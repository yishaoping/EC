/*
 * Copyright 2019 SiFive, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You should have received a copy of LICENSE.Apache2 along with
 * this software. If not, you may obtain a copy at
 *
 *    https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package sifive.blocks.inclusivecache

import Chisel._
import chisel3.util.experimental.BoringUtils

import freechips.rocketchip.config._
import freechips.rocketchip.diplomacy._


import freechips.rocketchip.regmapper._
import freechips.rocketchip.tilelink._
import freechips.rocketchip.guardiancouncil.{GH_GlobalParams, GHBarrierLatencyStats}
import freechips.rocketchip.subsystem.BankedL2Key
import freechips.rocketchip.util._

class InclusiveCache(
  val cache: CacheParameters,
  val micro: InclusiveCacheMicroParameters,
  control: Option[InclusiveCacheControlParameters] = None
  )(implicit p: Parameters)
    extends LazyModule
{
  val access = TransferSizes(1, cache.blockBytes)
  val xfer = TransferSizes(cache.blockBytes, cache.blockBytes)
  val atom = TransferSizes(1, cache.beatBytes)

  var resourcesOpt: Option[ResourceBindings] = None

  val device: SimpleDevice = new SimpleDevice("cache-controller", Seq("sifive,inclusivecache0", "cache")) {
    def ofInt(x: Int) = Seq(ResourceInt(BigInt(x)))

    override def describe(resources: ResourceBindings): Description = {
      resourcesOpt = Some(resources)

      val Description(name, mapping) = super.describe(resources)
      // Find the outer caches
      val outer = node.edges.out
        .flatMap(_.manager.managers)
        .filter(_.supportsAcquireB)
        .flatMap(_.resources.headOption)
        .map(_.owner.label)
        .distinct
      val nextlevel: Option[(String, Seq[ResourceValue])] =
        if (outer.isEmpty) {
          None
        } else {
          Some("next-level-cache" -> outer.map(l => ResourceReference(l)).toList)
        }

      val extra = Map(
        "cache-level"            -> ofInt(2),
        "cache-unified"          -> Nil,
        "cache-size"             -> ofInt(cache.sizeBytes * node.edges.in.size),
        "cache-sets"             -> ofInt(cache.sets * node.edges.in.size),
        "cache-block-size"       -> ofInt(cache.blockBytes),
        "sifive,mshr-count"      -> ofInt(InclusiveCacheParameters.all_mshrs(cache, micro)))
      Description(name, mapping ++ extra ++ nextlevel)
    }
  }

  val node: TLAdapterNode = TLAdapterNode(
    clientFn  = { _ => TLClientPortParameters(Seq(TLClientParameters(
      name          = s"L${cache.level} InclusiveCache",
      sourceId      = IdRange(0, InclusiveCacheParameters.out_mshrs(cache, micro) + 1),
      supportsProbe = xfer)), echoFields = Seq(CachePreserveTxnField()))
    },
    managerFn = { m => TLManagerPortParameters(
      managers = m.managers.map { m => m.copy(
        regionType         = if (m.regionType >= RegionType.UNCACHED) RegionType.CACHED else m.regionType,
        resources          = Resource(device, "caches") +: m.resources,
        supportsAcquireB   = xfer,
        supportsAcquireT   = if (m.supportsAcquireT) xfer else TransferSizes.none,
        supportsArithmetic = if (m.supportsAcquireT) atom else TransferSizes.none,
        supportsLogical    = if (m.supportsAcquireT) atom else TransferSizes.none,
        supportsGet        = access,
        supportsPutFull    = if (m.supportsAcquireT) access else TransferSizes.none,
        supportsPutPartial = if (m.supportsAcquireT) access else TransferSizes.none,
        supportsHint       = access,
        alwaysGrantsT      = false,
        fifoId             = None)
      },
      beatBytes  = cache.beatBytes,
      endSinkId  = InclusiveCacheParameters.all_mshrs(cache, micro),
      minLatency = 2,
      requestKeys = Seq(CacheImage),
      responseFields = Seq(CacheImageField(), CacheRecoverySafeField()))
    })

  val ctlnode = control.map { c => TLRegisterNode(
    address     = Seq(AddressSet(c.address, 0xfff)),
    device      = device,
    concurrency = 1, // Only one flush at a time (else need to track who answers)
    beatBytes   = c.beatBytes)}

  lazy val module = new Impl
  class Impl extends LazyModuleImp(this) {

    // If you have a control port, you must have at least one cache port
    require (!ctlnode.isDefined || !node.edges.in.isEmpty)

    // Extract the client IdRanges; must be the same on all ports!
    val clientIds = node.edges.in.headOption.map(_.client.clients.map(_.sourceId).sortBy(_.start))
    node.edges.in.foreach { e => require(e.client.clients.map(_.sourceId).sortBy(_.start) == clientIds.get) }

    // Use the natural ordering of clients (just like in Directory)
    node.edges.in.headOption.foreach { n =>
      println(s"L${cache.level} InclusiveCache Client Map:")
      n.client.clients.zipWithIndex.foreach { case (c,i) =>
        println(s"\t${i} <= ${c.name}")
      }
      println("")
    }

    // Flush directive
    val flushInValid   = RegInit(Bool(false))
    val flushInReady   = Wire(init = Bool(false))
    val flushInAddress = Reg(UInt(width = 64))
    val flushNoMatch   = Wire(init = Bool(true))
    val flushOutValid  = RegInit(Bool(false))
    val flushOutReady  = Wire(init = Bool(false))

    when (flushOutReady) { flushOutValid := Bool(false) }
    when (flushInReady)  { flushInValid  := Bool(false) }

    when (flushNoMatch && flushInValid) {
      flushInReady := Bool(true)
      flushOutValid := Bool(true)
    }

    val flush32 = RegField.w(32, RegWriteFn((ivalid, oready, data) => {
      when (oready) { flushOutReady := Bool(true) }
      when (ivalid) { flushInValid := Bool(true) }
      when (ivalid && !flushInValid) { flushInAddress := data << 4 }
      (!flushInValid, flushOutValid)
    }), RegFieldDesc("Flush32", "Flush the physical address equal to the 32-bit written data << 4 from the cache"))

    val flush64 = RegField.w(64, RegWriteFn((ivalid, oready, data) => {
      when (oready) { flushOutReady := Bool(true) }
      when (ivalid) { flushInValid := Bool(true) }
      when (ivalid && !flushInValid) { flushInAddress := data }
      (!flushInValid, flushOutValid)
    }), RegFieldDesc("Flush64", "Flush the phsyical address equal to the 64-bit written data from the cache"))

    // Information about the cache configuration
    val banksR  = RegField.r(8, UInt(node.edges.in.size),               RegFieldDesc("Banks",
      "Number of banks in the cache", reset=Some(node.edges.in.size)))
    val waysR   = RegField.r(8, UInt(cache.ways),                       RegFieldDesc("Ways",
      "Number of ways per bank", reset=Some(cache.ways)))
    val lgSetsR = RegField.r(8, UInt(log2Ceil(cache.sets)),             RegFieldDesc("lgSets",
      "Base-2 logarithm of the sets per bank", reset=Some(log2Ceil(cache.sets))))
    val lgBlockBytesR = RegField.r(8, UInt(log2Ceil(cache.blockBytes)), RegFieldDesc("lgBlockBytes",
      "Base-2 logarithm of the bytes per cache block", reset=Some(log2Ceil(cache.blockBytes))))

    val regmap = ctlnode.map { c =>
      c.regmap(
        0x000 -> RegFieldGroup("Config", Some("Information about the Cache Configuration"), Seq(banksR, waysR, lgSetsR, lgBlockBytesR)),
        0x200 -> (if (control.get.beatBytes >= 8) Seq(flush64) else Seq()),
        0x240 -> Seq(flush32)
      )
    }

    // Create the L2 Banks
    val mods = (node.in zip node.out).zipWithIndex map {
      case (((in, edgeIn), (out, edgeOut)), bank) =>
      edgeOut.manager.managers.foreach { m =>
        require (m.supportsAcquireB.contains(xfer),
          s"All managers behind the L2 must support acquireB($xfer) " +
          s"but ${m.name} only supports (${m.supportsAcquireB})!")
        if (m.supportsAcquireT) require (m.supportsAcquireT.contains(xfer),
          s"Any probing managers behind the L2 must support acquireT($xfer) " +
          s"but ${m.name} only supports (${m.supportsAcquireT})!")
      }

      val params = InclusiveCacheParameters(cache, micro, control.isDefined, edgeIn, edgeOut)
      val scheduler = Module(new Scheduler(params))
      // Rare U-D07 service uses a held four-phase control transaction. No
      // ordinary rollback invokes this physical enumeration.
      val maintenanceRaw = chisel3.WireDefault(false.B)
      BoringUtils.addSink(maintenanceRaw, "PALIMPSEST_EVT_MAINTENANCE_REQUEST")
      scheduler.io.maintenance := AsyncResetSynchronizerShiftReg(maintenanceRaw, sync = 8)
      BoringUtils.addSource(scheduler.io.maintenanceAck, s"PALIMPSEST_EVT_MAINTENANCE_ACK_$bank")
      // P4-08: the single-bank v1Config is the implemented recovery topology.
      // Historical data never uses ReleaseData while a newer L1 owner lives.
      require(node.in.size == 1, "PALIMPSEST archive mailbox requires the single-bank configuration")
      val archiveReqRaw = chisel3.WireDefault(false.B)
      val archiveLineRaw = chisel3.WireDefault(0.U.asTypeOf(new PalimpsestHistoryLine))
      BoringUtils.addSink(archiveReqRaw, "PALIMPSEST_ARCHIVE_REQUEST")
      BoringUtils.addSink(archiveLineRaw, "PALIMPSEST_ARCHIVE_PAYLOAD")
      val archiveReqSync = AsyncResetSynchronizerShiftReg(archiveReqRaw, sync = 8)
      val archiveLineSync = AsyncResetSynchronizerShiftReg(archiveLineRaw.asUInt, sync = 3)
        .asTypeOf(new PalimpsestHistoryLine)
      val archiveAck = RegInit(false.B)
      val archiveKey = Reg(new CacheImageKey)
      scheduler.io.historyArchive.valid := archiveReqSync && !archiveAck
      scheduler.io.historyArchive.bits := archiveLineSync
      when (scheduler.io.historyArchive.fire()) { archiveAck := true.B; archiveKey := archiveLineSync.key }
      when (!archiveReqSync) { archiveAck := false.B }
      BoringUtils.addSource(archiveAck, "PALIMPSEST_ARCHIVE_ACK")
      BoringUtils.addSource(archiveKey, "PALIMPSEST_ARCHIVE_KEY")
      require(bank < 256, "Stage3 bank provenance width exceeded")
      scheduler.io.bank := UInt(bank, width = 8)
      BoringUtils.addSource(scheduler.io.identityUnavailable, s"PALIMPSEST_L2_IDENTITY_UNAVAILABLE_$bank")
      // P3-08/P4-05: bundled-data four-phase recovery mailbox. The source
      // holds payload from request assertion until every bank ACK returns low.
      // Request qualifies five destination cycles after the synchronized bus;
      // result payload remains stable through the complete ACK phase.
      // Install-only requests are acknowledged once the bank and Scheduler
      // have loaded the context. Only line queries wait for a scan result.
      val historyRequestRaw = chisel3.WireDefault(false.B)
      val historyPayloadRaw = chisel3.WireDefault(0.U.asTypeOf(new PalimpsestHistoryQuery))
      BoringUtils.addSink(historyRequestRaw, "PALIMPSEST_HISTORY_REQUEST")
      BoringUtils.addSink(historyPayloadRaw, "PALIMPSEST_HISTORY_PAYLOAD")
      val historyPayloadSync = AsyncResetSynchronizerShiftReg(historyPayloadRaw.asUInt, sync = 3)
        .asTypeOf(new PalimpsestHistoryQuery)
      val historyRequestSync = AsyncResetSynchronizerShiftReg(historyRequestRaw, sync = 8)
      val bankHistoryContext = RegInit(0.U.asTypeOf(new PalimpsestHistoryQuery))
      val historyQuerySent = RegInit(false.B)
      val historyAck = RegInit(false.B)
      val historyResult = Reg(new PalimpsestHistoryResult)
      scheduler.io.historyQuery.valid := historyRequestSync && !historyQuerySent
      scheduler.io.historyQuery.bits := historyPayloadSync
      scheduler.io.historyResult.ready := historyQuerySent && !historyAck
      when (scheduler.io.historyQuery.fire()) {
        bankHistoryContext := historyPayloadSync
        historyQuerySent := true.B
        when (historyPayloadSync.installOnly) {
          historyResult := 0.U.asTypeOf(new PalimpsestHistoryResult)
          historyAck := true.B
        }
      }
      when (scheduler.io.historyResult.fire()) {
        historyResult := scheduler.io.historyResult.bits
        historyAck := true.B
      }
      when (!historyRequestSync) { historyQuerySent := false.B; historyAck := false.B }
      BoringUtils.addSource(historyAck, s"PALIMPSEST_HISTORY_ACK_$bank")
      BoringUtils.addSource(historyResult, s"PALIMPSEST_HISTORY_RESULT_$bank")

      scheduler.io.in <> in
      out <> scheduler.io.out

      val flushSelect = edgeIn.manager.managers.flatMap(_.address).map(_.contains(flushInAddress)).reduce(_||_)
      when (flushSelect) { flushNoMatch := Bool(false) }

      when (flushSelect && scheduler.io.req.ready)  { flushInReady := Bool(true) }
      when (scheduler.io.resp.valid) { flushOutValid := Bool(true) }
      assert (!scheduler.io.resp.valid || flushSelect)

      scheduler.io.req.valid := flushInValid && flushSelect
      scheduler.io.req.bits.address := flushInAddress
      scheduler.io.resp.ready := !flushOutValid

      // Fix-up the missing addresses. We do this here so that the Scheduler can be
      // deduplicated by Firrtl to make hierarchical place-and-route easier.

      out.a.bits.address := params.restoreAddress(scheduler.io.out.a.bits.address)
      in .b.bits.address := params.restoreAddress(scheduler.io.in .b.bits.address)
      out.c.bits.address := params.restoreAddress(scheduler.io.out.c.bits.address)

      // Count only L2 victims whose directory provenance says that the line
      // was used by a DCache. ICache-only clean evictions are intentionally
      // excluded. SourceC accepts each line exactly once and never cancels it.
      val l2StatsReset = chisel3.WireDefault(false.B)
      BoringUtils.addSink(l2StatsReset, GH_GlobalParams.GH_L2_STATS_RESET_BORE)
      val l2StatsEnable = chisel3.WireDefault(false.B)
      BoringUtils.addSink(l2StatsEnable, GH_GlobalParams.GH_L2_STATS_ENABLE_BORE)
      val l2Counting = l2StatsEnable && !l2StatsReset
      val writeback = scheduler.io.dcacheWriteback
      val dirty = scheduler.io.dcacheWritebackDirty
      val cleanCount = RegInit(UInt(0, width = 64))
      val dirtyCount = RegInit(UInt(0, width = 64))
      when (l2Counting && writeback && !dirty) { cleanCount := cleanCount + UInt(1) }
      when (l2Counting && writeback && dirty)  { dirtyCount := dirtyCount + UInt(1) }

      // L2->DRAM dirty writeback classification.  The packet bitmap itself is
      // owned by BOOM; L2 only keeps independent per-package buckets because a
      // package can evict more than one line.
      val l2StatsWindow = 256
      val l2StatsIndexBits = log2Ceil(l2StatsWindow)
      val l2Cycle = RegInit(UInt(0, width = 64))
      val l2Bucket = RegInit(0.U.asTypeOf(new L2DirtyWritebackBucket(l2StatsWindow)))
      val l2BucketResolve = Wire(Vec(l2StatsWindow, Bool()))
      // WireDefault gives BoringUtils' sink a legal default flow; a plain
      // Wire with an init assignment is diagnosed as a conflicting source.
      val safeWatermarkGrayIn = chisel3.WireDefault(0.U(
        GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
      BoringUtils.addSink(safeWatermarkGrayIn,
        GH_GlobalParams.GH_L1_L2_SAFE_WATERMARK_GRAY_BORE)
      val safeWatermarkGraySync = AsyncResetSynchronizerShiftReg(
        safeWatermarkGrayIn, sync = 3, name = Some("l2_safe_watermark_sync"))
      def l2GrayToBinary(gray: UInt): UInt = {
        // Building the result as a Vec avoids the legacy Chisel flow checker
        // treating per-bit assignments to a returned UInt wire as sinks.
        Vec((0 until gray.getWidth).map { i =>
          gray(gray.getWidth - 1, i).xorR
        }).asUInt
      }
      val l2SafeWatermark = l2GrayToBinary(safeWatermarkGraySync)
      scheduler.io.safeWatermark := l2SafeWatermark
      val realBarrierEnabled = p(GH_GlobalParams.GH_REAL_BARRIER_ENABLED)
      val barrierRequest = chisel3.WireDefault(false.B)
      val barrierRequestSeq = chisel3.WireDefault(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
      val barrierCloseAck = chisel3.WireDefault(false.B)
      val barrierCloseAckSeq = chisel3.WireDefault(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
      BoringUtils.addSink(barrierCloseAck,
        s"${GH_GlobalParams.GH_L2_BARRIER_CLOSE_ACK_BORE}_$bank")
      BoringUtils.addSink(barrierCloseAckSeq,
        s"${GH_GlobalParams.GH_L2_BARRIER_CLOSE_ACK_SEQ_BORE}_$bank")
      val barrierCloseAckSync = AsyncResetSynchronizerShiftReg(
        barrierCloseAck, sync = 3, name = Some(s"l2_barrier_close_ack_${bank}_sync"))
      val barrierCloseAckSeqSync = AsyncResetSynchronizerShiftReg(
        barrierCloseAckSeq, sync = 3, name = Some(s"l2_barrier_close_ack_seq_${bank}_sync"))
      val barrierFailure = chisel3.WireDefault(false.B)
      val barrierFailureSeq = chisel3.WireDefault(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
      BoringUtils.addSink(barrierFailure,
        GH_GlobalParams.GH_L2_BARRIER_FAILURE_BORE)
      BoringUtils.addSink(barrierFailureSeq,
        GH_GlobalParams.GH_L2_BARRIER_FAILURE_SEQ_BORE)
      val barrierFailureSync = AsyncResetSynchronizerShiftReg(
        barrierFailure, sync = 3, name = Some(s"l2_barrier_failure_${bank}_sync"))
      val barrierFailureSeqSync = AsyncResetSynchronizerShiftReg(
        barrierFailureSeq, sync = 3, name = Some(s"l2_barrier_failure_seq_${bank}_sync"))
      val barrierActive = RegInit(false.B)
      val barrierSeq = RegInit(0.U(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
      val barrierTimeout = RegInit(0.U(16.W))
      val seqWatermarkRequest = chisel3.WireDefault(false.B)
      if (p(PalimpsestSeqRebaseThreshold) > 0) {
        val rawRequest = chisel3.WireDefault(false.B)
        val ack = RegInit(false.B)
        BoringUtils.addSink(rawRequest, "PALIMPSEST_SEQ_WATERMARK_REQUEST")
        BoringUtils.addSource(ack, s"PALIMPSEST_SEQ_WATERMARK_ACK_$bank")
        seqWatermarkRequest := AsyncResetSynchronizerShiftReg(rawRequest, sync = 8)
        // A Gray jump to zero is allowed only with every publishing owner
        // already stopped. Accept it after the new registered value has
        // passed the synchronizer and is stable in this bank.
        val watermarkZero = l2SafeWatermark === 0.U
        val watermarkStable = watermarkZero && RegNext(watermarkZero, false.B)
        when (!seqWatermarkRequest) { ack := false.B }
          .elsewhen (scheduler.io.maintenanceAck && watermarkStable &&
              !barrierActive && !barrierCloseAckSync && !barrierFailureSync) {
            ack := true.B
            barrierSeq := 0.U
          }
      }
      // Scheduler admits each outer write against its immutable image and
      // publication order. This sequenced barrier asks Main to close a package
      // to make validation progress while those independent owners drain.
      val localValidationBlock = scheduler.io.validationBlock
      val stage3BarrierSeq = Mux(localValidationBlock, scheduler.io.validationSeq, scheduler.io.clientValidationSeq)
      // A cold pressure scan may not have selected its Seq yet. Never latch
      // a close transaction for Seq0 (or an already covered predecessor):
      // neither needs another Checker close to free safe history entries.
      val barrierCandidateUnsafe = (localValidationBlock || scheduler.io.clientValidationBlock) &&
        stage3BarrierSeq =/= 0.U && stage3BarrierSeq > l2SafeWatermark &&
        bankHistoryContext.survives(stage3BarrierSeq)
      val barrierFromPeer = RegInit(false.B)
      val barrierCloseAccepted = barrierCloseAckSync &&
        barrierCloseAckSeqSync === barrierSeq
      val barrierTimedOut = barrierActive && barrierTimeout === 0xffff.U
      val barrierFailed = barrierActive && barrierFailureSync &&
        barrierFailureSeqSync =/= 0.U && barrierFailureSeqSync <= barrierSeq
      // P4-01: a Checker failure starts recovery; only a local timeout is
      // a barrier protocol error. Tombstoned work releases its close waiter.
      val barrierErrorDetected = barrierTimedOut && bankHistoryContext.survives(barrierSeq)
      val barrierReleased = barrierActive &&
        (barrierSeq <= l2SafeWatermark || !bankHistoryContext.survives(barrierSeq))
      // OPTIMIZATION_1_TRACE_BEGIN: these are observation-only per-bank
      // watermark and validation-barrier stages.  They let the one planned
      // run distinguish result/CDC/prefix delay from L2 barrier delay.
      val slowdown_opt1_l2_safe_gray_in = chisel3.WireInit(safeWatermarkGrayIn)
      chisel3.dontTouch(slowdown_opt1_l2_safe_gray_in)
      val slowdown_opt1_l2_safe_gray_sync = chisel3.WireInit(safeWatermarkGraySync)
      chisel3.dontTouch(slowdown_opt1_l2_safe_gray_sync)
      val slowdown_opt1_l2_safe_watermark = chisel3.WireInit(l2SafeWatermark)
      chisel3.dontTouch(slowdown_opt1_l2_safe_watermark)
      val slowdown_opt1_l2_validation_block = chisel3.WireInit(scheduler.io.validationBlock)
      chisel3.dontTouch(slowdown_opt1_l2_validation_block)
      val slowdown_opt1_l2_client_validation_block = chisel3.WireInit(scheduler.io.clientValidationBlock)
      chisel3.dontTouch(slowdown_opt1_l2_client_validation_block)
      val slowdown_opt1_l2_outer_candidate_unsafe = chisel3.WireInit(localValidationBlock)
      chisel3.dontTouch(slowdown_opt1_l2_outer_candidate_unsafe)
      val slowdown_opt1_l2_barrier_candidate_unsafe = chisel3.WireInit(barrierCandidateUnsafe)
      chisel3.dontTouch(slowdown_opt1_l2_barrier_candidate_unsafe)
      val slowdown_opt1_l2_barrier_active = chisel3.WireInit(barrierActive)
      chisel3.dontTouch(slowdown_opt1_l2_barrier_active)
      val slowdown_opt1_l2_barrier_seq = chisel3.WireInit(barrierSeq)
      chisel3.dontTouch(slowdown_opt1_l2_barrier_seq)
      val slowdown_opt1_l2_barrier_close_accepted = chisel3.WireInit(barrierCloseAccepted)
      chisel3.dontTouch(slowdown_opt1_l2_barrier_close_accepted)
      val slowdown_opt1_l2_barrier_released = chisel3.WireInit(barrierReleased)
      chisel3.dontTouch(slowdown_opt1_l2_barrier_released)
      val slowdown_opt1_l2_bank = chisel3.WireInit(UInt(bank, width = 8))
      chisel3.dontTouch(slowdown_opt1_l2_bank)
      val slowdown_opt1_l2_clock = chisel3.WireInit(clock.asBool)
      chisel3.dontTouch(slowdown_opt1_l2_clock)
      val slowdown_opt1_l2_validation_seq = chisel3.WireInit(scheduler.io.validationSeq)
      chisel3.dontTouch(slowdown_opt1_l2_validation_seq)
      val slowdown_opt1_l2_client_validation_seq = chisel3.WireInit(scheduler.io.clientValidationSeq)
      chisel3.dontTouch(slowdown_opt1_l2_client_validation_seq)
      val slowdown_opt1_l2_barrier_close_ack = chisel3.WireInit(barrierCloseAckSync)
      chisel3.dontTouch(slowdown_opt1_l2_barrier_close_ack)
      val slowdown_opt1_l2_barrier_close_ack_seq = chisel3.WireInit(barrierCloseAckSeqSync)
      chisel3.dontTouch(slowdown_opt1_l2_barrier_close_ack_seq)
      // OPTIMIZATION_1_TRACE_END
      if (realBarrierEnabled) {
        barrierRequest := barrierActive && !barrierReleased
      } else {
        barrierRequest := false.B
      }
      barrierRequestSeq := barrierSeq
      BoringUtils.addSource(barrierRequest,
        s"${GH_GlobalParams.GH_L2_BARRIER_REQUEST_BORE}_$bank")
      BoringUtils.addSource(barrierRequestSeq,
        s"${GH_GlobalParams.GH_L2_BARRIER_REQUEST_SEQ_BORE}_$bank")
      val barrierError = chisel3.WireDefault(false.B)
      if (realBarrierEnabled) {
        barrierError := barrierErrorDetected
      }
      BoringUtils.addSource(barrierError,
        s"${GH_GlobalParams.GH_L2_BARRIER_ERROR_BORE}_$bank")
      if (realBarrierEnabled) {
        when (!barrierActive && !seqWatermarkRequest && barrierCandidateUnsafe) {
          barrierActive := true.B
          barrierFromPeer := !localValidationBlock
          barrierSeq := stage3BarrierSeq
          barrierTimeout := 0.U
          when (!localValidationBlock) {
            printf("STAGE3_TX L2_CLIENT_CLOSE bank=%x cycle=%x seq=%x watermark=%x waiting=%x\n",
              bank.U, l2Cycle, stage3BarrierSeq, l2SafeWatermark, scheduler.io.clientWaiting)
          }
        }.elsewhen (barrierActive) {
          when (barrierTimeout =/= 0xffff.U) {
            barrierTimeout := barrierTimeout + 1.U
          }
          when (barrierReleased) {
            barrierActive := false.B
            barrierTimeout := 0.U
            when (barrierFromPeer) {
              printf("STAGE3_TX L2_CLIENT_VALIDATED bank=%x cycle=%x seq=%x watermark=%x\n",
                bank.U, l2Cycle, barrierSeq, l2SafeWatermark)
            }
          }
        }
      }
      val l2DramBarrierStats = Module(new GHBarrierLatencyStats(l2StatsWindow))
      val l2BarrierMonitorEvent = chisel3.WireDefault(false.B)
      if (realBarrierEnabled) {
        l2BarrierMonitorEvent := !barrierActive && barrierCandidateUnsafe
      } else {
        l2BarrierMonitorEvent := scheduler.io.dcacheWritebackRequest &&
          scheduler.io.dcacheWritebackRequestDirty &&
          scheduler.io.dcacheWritebackRequestPacketTracked &&
          scheduler.io.dcacheWritebackRequestPacketSeq =/= 0.U &&
          scheduler.io.dcacheWritebackRequestPacketSeq > l2SafeWatermark
      }
      l2DramBarrierStats.io.resetStats := l2StatsReset
      l2DramBarrierStats.io.event.valid := l2Counting && l2BarrierMonitorEvent
      l2DramBarrierStats.io.event.bits :=
        Mux(realBarrierEnabled.B,
          stage3BarrierSeq,
          scheduler.io.dcacheWritebackRequestPacketSeq)
      l2DramBarrierStats.io.safeWatermark := l2SafeWatermark
      l2DramBarrierStats.io.currentCycle := l2Cycle
      // Package FAIL/CANCEL is checked in the BOOM-domain report. The L2
      // monitor only owns local slot/counter validity.
      l2DramBarrierStats.io.fatalProtocolError := barrierErrorDetected
      val l2Required = l2Counting && writeback && dirty &&
        scheduler.io.dcacheWritebackPacketTracked &&
        scheduler.io.dcacheWritebackPacketSeq =/= 0.U
      val l2Verified = l2Required &&
        scheduler.io.dcacheWritebackPacketSeq <= l2SafeWatermark
      val l2Unverified = l2Required && !l2Verified
      // A dirty L2 writeback without packet attribution is a valid
      // non-verification class, matching the L1->L2 accounting semantics.
      val l2Nonverify = l2Counting && writeback && dirty && !l2Required
      val l2BucketIdx = scheduler.io.dcacheWritebackPacketSeq(l2StatsIndexBits - 1, 0)
      val l2BucketAvailable = !l2Bucket.valid(l2BucketIdx) ||
        l2BucketResolve(l2BucketIdx) ||
        l2Bucket.seq(l2BucketIdx) === scheduler.io.dcacheWritebackPacketSeq
      val l2BucketAccepted = l2Unverified && l2BucketAvailable
      val l2BucketDropped = l2Unverified && !l2BucketAvailable
      for (i <- 0 until l2StatsWindow) {
        l2BucketResolve(i) := l2Bucket.valid(i) &&
          l2Bucket.seq(i) <= l2SafeWatermark
      }

      val l2RequiredCount = RegInit(UInt(0, width = 64))
      val l2VerifiedCount = RegInit(UInt(0, width = 64))
      val l2UnverifiedCount = RegInit(UInt(0, width = 64))
      val l2ResolvedCount = RegInit(UInt(0, width = 64))
      val l2PendingCount = RegInit(UInt(0, width = 64))
      val l2NonverifyCount = RegInit(UInt(0, width = 64))
      // `other` is reserved for statistics failures such as bucket collisions.
      val l2OtherCount = RegInit(UInt(0, width = 64))
      val l2WritebackCycleSum = RegInit(UInt(0, width = 64))
      val l2VerifyCycleSum = RegInit(UInt(0, width = 64))
      val l2StatsValid = RegInit(true.B)
      // Use widened reductions: up to 256 buckets may resolve together, and
      // each bucket may contain more than one line from the same package.
      val l2ResolvedThisCycleWide = (0 until l2StatsWindow).map(i =>
        Mux(l2BucketResolve(i), l2Bucket.count(i), 0.U(64.W)).pad(73)).reduce(_ + _)
      val l2WritebackCycleThisCycleWide = (0 until l2StatsWindow).map(i =>
        Mux(l2BucketResolve(i), l2Bucket.writebackCycleSum(i), 0.U(64.W)).pad(73)).reduce(_ + _)
      val l2VerifyCycleThisCycleWide = (0 until l2StatsWindow).map(i =>
        Mux(l2BucketResolve(i), (l2Cycle * l2Bucket.count(i)).pad(137),
          0.U(137.W))).reduce(_ + _)
      val l2ResolvedThisCycle = l2ResolvedThisCycleWide(63, 0)
      val l2WritebackCycleThisCycle = l2WritebackCycleThisCycleWide(63, 0)
      val l2VerifyCycleThisCycle = l2VerifyCycleThisCycleWide(63, 0)
      val l2PendingBeforeAdd = Cat(0.U(1.W), l2PendingCount) +
        l2BucketAccepted.asUInt
      val l2PendingUnderflow = l2ResolvedThisCycleWide >
        l2PendingBeforeAdd.pad(73)
      val l2PendingNextWide = l2PendingBeforeAdd.pad(73) -
        l2ResolvedThisCycleWide
      val l2CounterArithmeticOverflow =
        l2ResolvedThisCycleWide(72, 64).orR ||
        l2WritebackCycleThisCycleWide(72, 64).orR ||
        l2VerifyCycleThisCycleWide(136, 64).orR ||
        l2PendingNextWide(72, 64).orR
      for (i <- 0 until l2StatsWindow) {
        when (l2BucketResolve(i)) {
          l2Bucket.valid(i) := false.B
          l2Bucket.count(i) := 0.U
          l2Bucket.writebackCycleSum(i) := 0.U
        }
      }
      when (l2Counting && l2BucketAccepted) {
        when (!l2Bucket.valid(l2BucketIdx) || l2BucketResolve(l2BucketIdx)) {
          l2Bucket.valid(l2BucketIdx) := true.B
          l2Bucket.seq(l2BucketIdx) := scheduler.io.dcacheWritebackPacketSeq
          l2Bucket.count(l2BucketIdx) := 1.U
          l2Bucket.writebackCycleSum(l2BucketIdx) := l2Cycle
        }.otherwise {
          l2Bucket.count(l2BucketIdx) := l2Bucket.count(l2BucketIdx) + 1.U
          l2Bucket.writebackCycleSum(l2BucketIdx) :=
            l2Bucket.writebackCycleSum(l2BucketIdx) + l2Cycle
        }
      }
      when (l2StatsReset) {
        l2Cycle := 0.U
      }.otherwise {
        // Keep the L2 time base running after STOP so delayed verification
        // completions receive their actual L2-cycle timestamp.
        l2Cycle := l2Cycle + 1.U
      }
      when (l2Counting && l2Required) { l2RequiredCount := l2RequiredCount + 1.U }
      when (l2Counting && l2Verified) { l2VerifiedCount := l2VerifiedCount + 1.U }
      when (l2Counting && l2Unverified) { l2UnverifiedCount := l2UnverifiedCount + 1.U }
      when (l2Counting && l2Nonverify) {
        l2NonverifyCount := l2NonverifyCount + 1.U
      }
      when (l2Counting && l2BucketDropped) {
        l2OtherCount := l2OtherCount + 1.U
      }
      when (l2Counting && l2BucketDropped) { l2StatsValid := false.B }
      when (l2ResolvedThisCycle =/= 0.U) {
        l2ResolvedCount := l2ResolvedCount + l2ResolvedThisCycle
        l2WritebackCycleSum := l2WritebackCycleSum + l2WritebackCycleThisCycle
        l2VerifyCycleSum := l2VerifyCycleSum + l2VerifyCycleThisCycle
      }
      when (l2ResolvedThisCycle =/= 0.U || l2BucketAccepted) {
        // Clamp an invalid subtraction to zero so a diagnostic condition does
        // not leave a permanently huge pending count that blocks report_end.
        l2PendingCount := Mux(l2PendingUnderflow, 0.U,
          l2PendingNextWide(63, 0))
      }
      when (l2CounterArithmeticOverflow || l2PendingUnderflow) {
        l2StatsValid := false.B
      }
      when (l2StatsReset) {
        cleanCount := 0.U
        dirtyCount := 0.U
        l2RequiredCount := 0.U
        l2VerifiedCount := 0.U
        l2UnverifiedCount := 0.U
        l2ResolvedCount := 0.U
        l2PendingCount := 0.U
        l2NonverifyCount := 0.U
        l2OtherCount := 0.U
        l2WritebackCycleSum := 0.U
        l2VerifyCycleSum := 0.U
        l2StatsValid := true.B
        for (i <- 0 until l2StatsWindow) {
          l2Bucket.valid(i) := false.B
          l2Bucket.seq(i) := 0.U
          l2Bucket.count(i) := 0.U
          l2Bucket.writebackCycleSum(i) := 0.U
        }
      }

      val cleanGray = Wire(UInt(width = 64))
      val dirtyGray = Wire(UInt(width = 64))
      cleanGray := cleanCount ^ (cleanCount >> 1)
      dirtyGray := dirtyCount ^ (dirtyCount >> 1)
      BoringUtils.addSource(cleanGray, s"${GH_GlobalParams.GH_L2_WB_CLEAN_GRAY_BORE}_$bank")
      BoringUtils.addSource(dirtyGray, s"${GH_GlobalParams.GH_L2_WB_DIRTY_GRAY_BORE}_$bank")
      val l2Stats = Seq(l2RequiredCount, l2VerifiedCount, l2UnverifiedCount,
        l2ResolvedCount, l2PendingCount, l2NonverifyCount, l2OtherCount,
        l2WritebackCycleSum, l2VerifyCycleSum,
        Cat(0.U(63.W), l2StatsValid))
      l2Stats.zipWithIndex.foreach { case (value, index) =>
        val gray = value ^ (value >> 1)
        BoringUtils.addSource(gray,
          s"${GH_GlobalParams.GH_L2_DRAM_STATS_BORE}_${index}_$bank")
      }
      val l2BarrierStats = Seq(
        l2DramBarrierStats.io.seen,
        l2DramBarrierStats.io.resolved,
        l2DramBarrierStats.io.pending,
        l2DramBarrierStats.io.dropped,
        l2DramBarrierStats.io.requestCycleSum,
        l2DramBarrierStats.io.safeCycleSum,
        l2DramBarrierStats.io.statsValid)
      l2BarrierStats.zipWithIndex.foreach { case (value, index) =>
        val gray = value ^ (value >> 1)
        BoringUtils.addSource(gray,
          s"${GH_GlobalParams.GH_L2_DRAM_BARRIER_STATS_BORE}_${index}_$bank")
      }

      scheduler
    }

    def json = s"""{"banks":[${mods.map(_.json).mkString(",")}]}"""
  }
}
