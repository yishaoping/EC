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
import freechips.rocketchip.diplomacy.AddressSet
import freechips.rocketchip.tilelink._
import freechips.rocketchip.util._
import freechips.rocketchip.guardiancouncil.GH_GlobalParams
import freechips.rocketchip.util.{CacheOpportunityObservation, SafeChainObservation}
import chisel3.util.experimental.BoringUtils

// Diagnostic outputs only. Host-idle and checkpoint capture are different
// drains: neither these observations nor host ledgers feed the protocol.
class Stage3DrainStatus(params: InclusiveCacheParameters) extends InclusiveCacheBundle(params)
{
  val state = UInt(width = 3)
  val candidate = Bool()
  val safe = Bool()
  val selected = UInt(width = params.mshrs + 1) // bit0 Probe, bit(i+1) MSHR i
  val quiescent = Bool()
  val drained = Bool()
  val requested = Bool()
  val sourceDIdle = Bool()
  val sourceDBusy = UInt(width = 4)
  val sourceCIdle = Bool()
  val sourceCBusy = UInt(width = 4)
  val sinkCBusy = Bool() // admitted bank-address queue, not blocked first C beat
  val mshrPending = UInt(width = params.mshrs)
  val mshrQuiescent = UInt(width = params.mshrs)
  val sourceDValid = Bool()
  val sourceDReady = Bool()
  val sourceCValid = Bool()
  val sourceCReady = Bool()
  val probeValid = Bool()
  val probeAllow = Bool()
  val requestValid = Bool()
  val requestReady = Bool()
  val issued = Bool()
  val ackSeen = Bool()
  val address = UInt(width = params.inner.bundle.addressBits)
}

class Scheduler(params: InclusiveCacheParameters, trace: Boolean = false) extends Module
{
  val io = new Bundle {
    val in = TLBundle(params.inner.bundle).flip
    val out = TLBundle(params.outer.bundle)
    // Way permissions
    val ways = Vec(params.allClients, UInt(width = params.cache.ways)).flip
    val divs = Vec(params.allClients, UInt(width = InclusiveCacheParameters.lfsrBits + 1)).flip
    // Control port
    val req = Decoupled(new SinkXRequest(params)).flip
    val resp = Decoupled(new SourceXRequest(params))
    // One-cycle, line-level pulses for DCache-originated L2 evictions.
    val dcacheWriteback = Bool()
    val dcacheWritebackDirty = Bool()
    val dcacheWritebackPacketSeq = UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)
    val dcacheWritebackPacketTracked = Bool()
    // Earlier line-level acceptance point used by the hypothetical L2-DRAM
    // barrier monitor. This remains independent of the outer C handshake.
    val dcacheWritebackRequest = Bool()
    val dcacheWritebackRequestDirty = Bool()
    val dcacheWritebackRequestPacketSeq = UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)
    val dcacheWritebackRequestPacketTracked = Bool()
    val safeWatermark = Input(UInt(32.W))
    val bank = Input(UInt(8.W))
    val historyArchive = Decoupled(new PalimpsestHistoryLine).flip // P4-08
    val historyQuery = Decoupled(new PalimpsestHistoryQuery).flip
    val historyResult = Decoupled(new PalimpsestHistoryResult)
    val maintenance = Input(Bool()) // held rare EVT-capacity service request
    val maintenanceAck = Bool()

    val clientValidationBlock = Bool()
    val clientValidationSeq = UInt(width = 32)
    val clientWaiting = UInt(width = params.inner.bundle.sourceBits + 1)
    val validationBlock = Bool()
    val validationSeq = UInt(width = 32)
    val preservationLock = Valid(new L2PreservationCandidate(params))
    val preservationTxn = UInt(width = 64)
    val preservationAck = Bool()
    val preservationCounters = Vec(6, UInt(width = 64))
    val active = Bool()
    val identityUnavailable = Bool()
    val bankWrite = Bool()
    val metaWrite = Bool()
    val baselineCommit = Bool() // addressed receipt write, allowed under its own lock
    val historyPressure = Bool()
    val historyEscapeAvailable = Bool()
    val drain = new Stage3DrainStatus(params)
    val flushStatus = new MSHRFlushStatus(params)
  }

  val sourceA = Module(new SourceA(params))
  val sourceB = Module(new SourceB(params))
  val sourceC = Module(new SourceC(params))
  val sourceD = Module(new SourceD(params))
  val sourceE = Module(new SourceE(params))
  val sourceX = Module(new SourceX(params))
  val preservation = Module(new L2Preservation(params))
  preservation.io.watermark := io.safeWatermark
  preservation.io.bank := io.bank
  // P3-07/P4-08: history is an addressed sidecar, not extra same-tag ways.
  val versionHistory = Module(new PalimpsestVersionHistory(
    params.p(PalimpsestHistoryEntries), params.p(PalimpsestEscapeEntries)))
  versionHistory.io.watermark := io.safeWatermark
  io.historyPressure := versionHistory.io.pressure
  io.historyEscapeAvailable := versionHistory.io.escapeAvailable
  val maintIdle :: maintDrain :: maintRead :: maintWait :: maintFlush :: maintResponse :: maintDone :: Nil = chisel3.util.Enum(7)
  val maintState = RegInit(maintIdle)
  val maintSet = RegInit(UInt(0, width = params.setBits))
  val maintWay = RegInit(UInt(0, width = params.wayBits))
  val maintFinished = RegInit(Bool(false))
  val maintAddress = Reg(UInt(width = params.inner.bundle.addressBits))
  val maintActive = io.maintenance || maintState =/= maintIdle
  val maintReadFire = Wire(init = Bool(false))
  val maintReadResponse = params.dirReg(RegNext(maintReadFire, Bool(false)))
  io.maintenanceAck := maintState === maintDone
  when (io.maintenance && maintState === maintIdle) {
    maintSet := UInt(0); maintWay := UInt(0); maintFinished := Bool(false)
    maintState := maintDrain
  }
  when (!io.maintenance && maintState === maintDone) { maintState := maintIdle }
  def advanceMaintenance(): Unit = {
    when (maintWay === UInt(params.cache.ways - 1)) {
      maintWay := UInt(0)
      when (maintSet === UInt(params.cache.sets - 1)) { maintFinished := Bool(true) }
        .otherwise { maintSet := maintSet + UInt(1) }
    }.otherwise { maintWay := maintWay + UInt(1) }
    maintState := maintDrain
  }
  val recoveryContext = RegInit(0.U.asTypeOf(new PalimpsestHistoryQuery))
  when (io.historyQuery.fire()) { recoveryContext := io.historyQuery.bits }
  versionHistory.io.context := recoveryContext
  def historySafe(key: CacheImageKey): Bool =
    recoveryContext.survives(key.contentSeq) && CacheImage.safe(key, io.safeWatermark)

  val trustedQuery = Wire(Decoupled(new PalimpsestHistoryQuery))
  val trustedResult = Wire(Valid(new PalimpsestHistoryResult))
  val trustedQueryInFlight = RegInit(Bool(false))
  io.historyResult.valid := versionHistory.io.result.valid && !trustedQueryInFlight
  io.historyResult.bits := versionHistory.io.result.bits
  trustedResult.valid := versionHistory.io.result.valid && trustedQueryInFlight
  trustedResult.bits := versionHistory.io.result.bits
  versionHistory.io.result.ready := trustedQueryInFlight || io.historyResult.ready
  when (trustedQuery.fire()) { trustedQueryInFlight := Bool(true) }
  when (trustedResult.valid) { trustedQueryInFlight := Bool(false) }
  preservation.io.historyPublish <> versionHistory.io.publish
  versionHistory.io.published := preservation.io.historyPublished
  val (publishTag, publishSet, _) = params.parseAddress(versionHistory.io.publish.bits.address)
  val publishKey = versionHistory.io.publish.bits.key
  def pendingSafeBaseline(tag: UInt, set: UInt): Bool =
    versionHistory.io.publish.valid && historySafe(publishKey) && publishTag === tag && publishSet === set
  val historyCaptureArb = Module(new chisel3.util.Arbiter(new PalimpsestHistoryLine, 3))
  val preserveCredit = preservation.io.lock.valid && !historySafe(preservation.io.lock.bits.image)
  historyCaptureArb.io.in(0) <> preservation.io.archive
  historyCaptureArb.io.in(1).valid := io.historyArchive.valid && !preserveCredit
  historyCaptureArb.io.in(1).bits := io.historyArchive.bits
  io.historyArchive.ready := historyCaptureArb.io.in(1).ready && !preserveCredit
  versionHistory.io.capture <> historyCaptureArb.io.out
  versionHistory.io.captureEscape := historyCaptureArb.io.chosen =/= UInt(1)

  preservation.io.historyContext := recoveryContext
  sourceC.io.historyContext := recoveryContext
  sourceC.io.watermark := io.safeWatermark


  // The dedicated source cannot alias an MSHR. TL arbitration holds a Put's
  // entire multibeat transfer, including gaps for bank reads/backpressure.
  TLArbiter.lowest(params.outer, io.out.a, preservation.io.a, sourceA.io.a)
  io.out.c <> sourceC.io.c
  io.out.e <> sourceE.io.e
  io.in.b <> sourceB.io.b
  io.in.d <> sourceD.io.d
  io.resp.valid := sourceX.io.x.valid && maintState =/= maintResponse
  io.resp.bits := sourceX.io.x.bits
  sourceX.io.x.ready := Mux(maintState === maintResponse, Bool(true), io.resp.ready)
  when (maintState === maintResponse && sourceX.io.x.fire()) { advanceMaintenance() }

  val sinkA = Module(new SinkA(params))
  val sinkC = Module(new SinkC(params))
  val sinkD = Module(new SinkD(params))
  val sinkE = Module(new SinkE(params))
  val sinkX = Module(new SinkX(params))

  // No new A owner enters while the rare physical sweep is in progress.
  // Already accepted SinkA/MSHR work, Probe/C responses and outer ACKs finish.
  sinkA.io.a.valid := io.in.a.valid && !maintActive
  sinkA.io.a.bits := io.in.a.bits
  io.in.a.ready := sinkA.io.a.ready && !maintActive
  // Keep the configured C queue in front of SinkC admission. A ProbeAckData
  // waiting there for its predecessor checkpoint owns no history staging yet.
  val bufferedC = if (params.firstLevel) io.in.c else params.micro.innerBuf.c(io.in.c)
  // Capture every admitted authored C image, including a migrating Current.
  // Hold the complete staging line until the history RAM accepts it.
  val historyCPending = RegInit(Bool(false))
  val historyCPartial = RegInit(Bool(false))
  val historyCChecked = RegInit(Bool(false))
  val historyCLine = Reg(new PalimpsestHistoryLine)
  sinkC.io.c.valid := bufferedC.valid && !historyCPending
  sinkC.io.c.bits := bufferedC.bits
  bufferedC.ready := sinkC.io.c.ready && !historyCPending
  val (_, historyCLast, _, historyCBeat) = params.inner.count(sinkC.io.c)
  val historyCKey = sinkC.io.c.bits.user.lift(CacheImage).getOrElse(0.U.asTypeOf(new CacheImageKey))
  when (sinkC.io.c.fire() && params.inner.hasData(sinkC.io.c.bits) && historyCKey.valid) {
    val (tag, set, _) = params.parseAddress(sinkC.io.c.bits.address)
    historyCLine.address := params.restoreAddress(params.expandAddress(tag, set, UInt(0)))
    historyCLine.key := historyCKey
    val rows = Wire(init = historyCLine.data.asTypeOf(Vec(
      params.cache.blockBytes / params.inner.manager.beatBytes, UInt(width = params.inner.bundle.dataBits))))
    rows(historyCBeat) := sinkC.io.c.bits.data
    historyCLine.data := rows.asUInt
    historyCPartial := !historyCLast
    // The held publish offer remains searchable and cannot take its set
    // lock while this same-line Probe is writing data. A covered older
    // response must still complete C, but must not re-enter history.
    val coveredProbe = sinkC.io.c.bits.opcode === TLMessages.ProbeAckData &&
      pendingSafeBaseline(tag, set) &&
      CacheImage.coveredTracked(historyCKey, publishKey)
    when (historyCLast && !coveredProbe) {
      historyCPending := Bool(true)
      historyCChecked := historyCKey.contentSeq === UInt(0)
    }
  }
  val (historyCTag, historyCSet, _) = params.parseAddress(historyCLine.address)
  val historyCCaptureAllowed = Wire(Bool())
  historyCaptureArb.io.in(2).valid := historyCPending && historyCChecked && !preserveCredit && historyCCaptureAllowed
  historyCaptureArb.io.in(2).bits := historyCLine
  when (historyCaptureArb.io.in(2).fire()) { historyCPending := Bool(false) }

  // Include the staged incoming C owner in the query barrier: an ACKed L1
  // snapshot must be searchable before the bank returns its query response.
  val historyQueryClear = !historyCPending && !historyCPartial && !bufferedC.valid && !io.in.c.valid
  val installOnly = io.historyQuery.bits.installOnly
  // An EVT installation has no line result. Its receipt must be independent
  // of old owners, which can still need the outer terminal beat to finish.
  versionHistory.io.query.valid := Mux(io.historyQuery.valid, !installOnly, trustedQuery.valid) &&
    historyQueryClear
  versionHistory.io.query.bits := Mux(io.historyQuery.valid, io.historyQuery.bits, trustedQuery.bits)
  io.historyQuery.ready := installOnly || (versionHistory.io.query.ready && historyQueryClear)
  trustedQuery.ready := versionHistory.io.query.ready && historyQueryClear && !io.historyQuery.valid
  sinkE.io.e <> io.in.e
  val checkpointResponse = io.out.d.bits.source ===
    UInt(InclusiveCacheParameters.out_mshrs(params.cache, params.micro))
  preservation.io.d.valid := io.out.d.valid && checkpointResponse
  preservation.io.d.bits := io.out.d.bits
  sinkD.io.d.valid := io.out.d.valid && !checkpointResponse
  sinkD.io.d.bits := io.out.d.bits
  io.out.d.ready := Mux(checkpointResponse, preservation.io.d.ready, sinkD.io.d.ready)
  sinkX.io.x.valid := Mux(maintActive, maintState === maintFlush, io.req.valid)
  sinkX.io.x.bits.address := Mux(maintActive, maintAddress, io.req.bits.address)
  io.req.ready := sinkX.io.x.ready && !maintActive
  when (maintState === maintFlush && sinkX.io.x.fire()) { maintState := maintResponse }

  io.out.b.ready := Bool(true) // disconnected

  val directory = Module(new Directory(params))
  // Reuse the addressed directory port before handing tracked C to History.
  // An exact outer receipt remains in the directory after History retires
  // the data entry, so a later older C cannot republish the retired version.
  val historyCCheckFire = Wire(init = Bool(false))
  val historyCCheckWaiting = RegInit(Bool(false))
  val historyCCheckResponse = params.dirReg(RegNext(historyCCheckFire, Bool(false)))
  when (historyCCheckFire) { historyCCheckWaiting := Bool(true) }
  when (historyCCheckResponse && directory.io.result.valid) {
    historyCCheckWaiting := Bool(false)
    val resident = directory.io.result.bits
    when (resident.hit && resident.outerPreserved && historySafe(resident.image) &&
      CacheImage.coveredTracked(historyCLine.key, resident.image)) {
      historyCPending := Bool(false)
    }.otherwise { historyCChecked := Bool(true) }
  }
  // P3-10/U-D06: after a history DRAM ACK, update the existing resident
  // receipt before releasing the address lock or accepting another archive.
  // This is one addressed directory read/write, never a cache-wide scan or
  // an unbounded published-address CAM.
  val baselineIdle :: baselineRead :: baselineWait :: baselineWrite :: baselineDone :: Nil = chisel3.util.Enum(5)
  val baselineState = RegInit(baselineIdle)
  val baselineResult = Reg(new DirectoryResult(params))
  val baselineActive = baselineState =/= baselineIdle || preservation.io.baseline.valid
  val baselineReadFire = Wire(init = Bool(false))
  val baselineReadResponse = params.dirReg(RegNext(baselineReadFire, Bool(false)))
  preservation.io.baseline.ready := baselineState === baselineDone
  when (preservation.io.baseline.valid && baselineState === baselineIdle) { baselineState := baselineRead }
  when (baselineReadFire) { baselineState := baselineWait }
  when (baselineState === baselineWait && directory.io.result.valid && baselineReadResponse) {
    baselineResult := directory.io.result.bits
    baselineState := Mux(directory.io.result.bits.hit, baselineWrite, baselineDone)
  }
  when (preservation.io.baseline.fire()) { baselineState := baselineIdle }
  val bankedStore = Module(new BankedStore(params))
  val requests = Module(new ListBuffer(ListBufferParameters(new QueuedRequest(params), 3*params.mshrs, params.secondary, false)))
  val mshrs = Seq.tabulate(params.mshrs) { i => Module(new MSHR(params, trace, i)) }
  val abc_mshrs = mshrs.init.init
  val bc_mshr = mshrs.init.last
  val c_mshr = mshrs.last
  // The caller has stopped Main and established SW=allocatedTail. The old
  // EVT remains installed for the ENTIRE sweep. Publish all surviving safe
  // history, drop dead data through normal permission-only releases, and
  // wait for every original terminal acknowledgement before certifying empty.
  val maintNoWaiters = Wire(init = Bool(false))
  val maintDrained = maintNoWaiters && !mshrs.map(_.io.status.valid).reduce(_||_) &&
    !requests.io.valid.orR && sourceD.io.idle && sourceC.io.idle && !sinkC.io.bankBusy &&
    !sinkA.io.req.valid && !sinkX.io.req.valid && !sourceX.io.x.valid &&
    historyQueryClear && !io.historyArchive.valid &&
    !preservation.io.lock.valid && !baselineActive && versionHistory.io.empty
  when (maintState === maintDrain && maintDrained) {
    maintState := Mux(maintFinished, maintDone, maintRead)
  }
  when (maintReadFire) { maintState := maintWait }
  when (maintState === maintWait && maintReadResponse && directory.io.result.valid) {
    when (directory.io.result.bits.hit) {
      maintAddress := params.expandAddress(directory.io.result.bits.tag, maintSet, UInt(0))
      maintState := maintFlush
    }.otherwise { advanceMaintenance() }
  }
  // Select one active control transaction for diagnostics; no protocol consumer.
  val flushStatusOH = PriorityEncoderOH(Vec(mshrs.map(_.io.flushStatus.active)).asUInt)
  io.flushStatus := Mux1H(flushStatusOH, mshrs.map(_.io.flushStatus))
  // One independent slot per real unaware source. A TL source cannot have
  // two live A requests. Slots hold no MSHR, set lock, bank or D pipeline.
  // The dummy slot makes the all-aware configuration legal without empty Vecs.
  // One metadata-only wait slot per actual TL source. Capacity parking also
  // applies to Main misses, so they cannot monopolize a Checker's set.
  val waitSources = params.inner.client.clients.flatMap(c => c.sourceId.start until c.sourceId.end).distinct
  require(waitSources.nonEmpty)
  val clientWaitValid = waitSources.map(_ => RegInit(Bool(false)))
  maintNoWaiters := !clientWaitValid.reduce(_||_)
  val clientWait = waitSources.map(_ => Reg(new ClientWaitRequest(params)))
  val clientWaitRunnable = Vec(clientWaitValid.zip(clientWait).map { case (v, q) =>
    v && (q.seq <= io.safeWatermark || !recoveryContext.survives(q.seq)) && !mshrs.map(m =>
      m.io.status.valid && m.io.status.bits.set === q.request.set).reduce(_||_)
  }).asUInt
  val clientReplayOH = PriorityEncoderOH(clientWaitRunnable)
  val clientReplay = Wire(Decoupled(new FullRequest(params)))
  clientReplay.valid := clientWaitRunnable.orR
  clientReplay.bits := Mux1H(clientReplayOH, clientWait.map(_.request))
  when (clientReplay.fire()) {
    clientWaitValid.zipWithIndex.foreach { case (v, i) => when (clientReplayOH(i)) { v := Bool(false) } }
    printf("STAGE3_TX L2_CLIENT_RETRY bank=%x source=%x set=%x tag=%x watermark=%x\n",
      io.bank, clientReplay.bits.source, clientReplay.bits.set, clientReplay.bits.tag, io.safeWatermark)
  }
  val waitingUnsafe = clientWaitValid.zip(clientWait).map { case (v, q) => v && q.seq > io.safeWatermark && recoveryContext.survives(q.seq) }
  io.clientValidationBlock := waitingUnsafe.reduce(_||_)
  io.clientValidationSeq := Mux1H(PriorityEncoderOH(Vec(waitingUnsafe).asUInt), clientWait.map(_.seq))
  io.clientWaiting := PopCount(Vec(clientWaitValid))
  val nestedwb = Wire(new NestedWriteback(params))
  io.preservationLock := preservation.io.lock
  io.preservationTxn := preservation.io.txn
  io.preservationAck := preservation.io.completed.valid
  io.preservationCounters := preservation.io.counters
  io.identityUnavailable := preservation.io.identityUnavailable || mshrs.map(_.io.identityUnavailable).reduce(_ || _)
  io.active := mshrs.map(_.io.status.valid).reduce(_||_) || !sourceD.io.idle ||
    !sourceC.io.idle || sinkC.io.bankBusy || clientWaitValid.reduce(_||_) || maintActive
  io.bankWrite := sourceD.io.bs_wadr.fire() || (sinkC.io.bs_adr.fire() && !sinkC.io.bs_adr.bits.noop)
  io.metaWrite := directory.io.write.fire()
  io.baselineCommit := directory.io.write.fire() && baselineState === baselineWrite

  mshrs.foreach { m =>
    m.io.preserved := preservation.io.completed; m.io.bank := io.bank
    m.io.watermark := io.safeWatermark; m.io.historyContext := recoveryContext
    m.io.pauseExecute := versionHistory.io.publishPending
    m.io.capacityBlocked := !versionHistory.io.escapeAvailable
  }
  mshrs.foreach { m =>
    m.io.baseline.valid := preservation.io.baseline.fire()
    m.io.baseline.bits := preservation.io.baseline.bits
    // Share the receipt comparison with the pre-admission drain check.
    when (versionHistory.io.publish.valid) {
      m.io.baseline.bits.set := publishSet
      m.io.baseline.bits.tag := publishTag
      m.io.baseline.bits.image := publishKey
    }
  }
  // Candidate selection observes production MSHR metadata and the actual
  // ProbeAck input, before any bank write. Identical keys are immutable copies.
  val candidates = mshrs.map { m =>
    val x = Wire(Valid(new L2PreservationCandidate(params)))
    val r = m.io.resident.bits
    val d = m.io.schedule.bits.d
    // Same-package writes inherit the safe predecessor obligation from Stage 2.
    val releaseSameUnsafePackage = CacheImage.samePackageSupersede(d.bits.image, r.image, io.safeWatermark)
    val releaseChange = d.bits.prio(2) && d.bits.opcode === TLMessages.ReleaseData &&
      !releaseSameUnsafePackage &&
      (!d.bits.image.valid || d.bits.image.asUInt =/= r.image.asUInt)
    val trustedChange = m.io.trustedWrite
    // P4-12/U-D09: an unsafe victim can move into the recovery domain's
    // reserved history space, then release permission without dirty bytes.
    // Waiting for SW here can block a Checker's instruction fetch miss.
    val unsafeEvict = m.io.schedule.bits.c.valid &&
      recoveryContext.survives(r.image.contentSeq) && !CacheImage.safe(r.image, io.safeWatermark)
    val destructive = m.io.resident.valid && ((r.hit && ((d.valid && releaseChange) || trustedChange)) || unsafeEvict)
    x.valid := destructive && L2Preservation.blocked(r.image, r.dirty, r.outerPreserved, io.safeWatermark)
    x.bits.set := m.io.status.bits.set; x.bits.way := r.way; x.bits.tag := r.tag
    x.bits.image := r.image; x.bits.dirty := r.dirty; x.bits.outerPreserved := r.outerPreserved
    x.bits.reason := Mux(trustedChange, UInt(3), UInt(1))
    x
  }
  val probeBC = bc_mshr.io.resident.valid && bc_mshr.io.status.bits.set === sinkC.io.probe.bits.set
  val probeABC = abc_mshrs.map(m => m.io.resident.valid && m.io.status.bits.set === sinkC.io.probe.bits.set)
  val probeResident = Mux(probeBC, bc_mshr.io.resident.bits, Mux1H(probeABC, abc_mshrs.map(_.io.resident.bits)))
  val probeFound = (probeBC || probeABC.reduce(_||_)) && probeResident.state =/= MetaData.INVALID &&
    probeResident.tag === sinkC.io.probe.bits.tag
  // Apply the same rule to first-beat ProbeAckData before SinkC admission.
  val probeSameUnsafePackage = CacheImage.samePackageSupersede(sinkC.io.probe.bits.image,
    probeResident.image, io.safeWatermark)
  val probeChange = sinkC.io.probe.valid && probeFound &&
    !probeSameUnsafePackage &&
    (!sinkC.io.probe.bits.image.valid || probeResident.image.asUInt =/= sinkC.io.probe.bits.image.asUInt)
  val historyCoversProbeResident = pendingSafeBaseline(sinkC.io.probe.bits.tag, sinkC.io.probe.bits.set) &&
    (CacheImage.earlier(probeResident.image, publishKey) || probeResident.image.asUInt === publishKey.asUInt)
  val probeNeedsGate = probeChange && !historyCoversProbeResident && L2Preservation.blocked(probeResident.image,
    probeResident.dirty, probeResident.outerPreserved, io.safeWatermark)
  // System builds need the incoming identity as well as the resident key:
  // validation-only logs cannot distinguish a true cross-package waiter from
  // a coherent peer that dropped its imported lineage. Log entry/change only.
  val probeGateIdentity = Cat(sinkC.io.probe.bits.source, sinkC.io.probe.bits.tag,
    sinkC.io.probe.bits.set, sinkC.io.probe.bits.image.asUInt, probeResident.image.asUInt)
  val priorProbeGate = RegNext(probeNeedsGate, Bool(false))
  val priorProbeIdentity = RegNext(probeGateIdentity)
  when (probeNeedsGate && (!priorProbeGate || priorProbeIdentity =/= probeGateIdentity)) {
    printf("STAGE3_TX L2_PROBE_BLOCK bank=%x source=%x set=%x way=%x tag=%x dirty=%x outer=%x old_valid=%x old_writer=%x old_gen=%x old_seq=%x new_valid=%x new_writer=%x new_gen=%x new_seq=%x watermark=%x same_package=%x newer=%x\n",
      io.bank, sinkC.io.probe.bits.source, sinkC.io.probe.bits.set, probeResident.way,
      probeResident.tag, probeResident.dirty, probeResident.outerPreserved,
      probeResident.image.valid, probeResident.image.writer, probeResident.image.generation,
      probeResident.image.contentSeq, sinkC.io.probe.bits.image.valid,
      sinkC.io.probe.bits.image.writer, sinkC.io.probe.bits.image.generation,
      sinkC.io.probe.bits.image.contentSeq, io.safeWatermark,
      CacheImage.sameSpeculativePackage(sinkC.io.probe.bits.image, probeResident.image),
      sinkC.io.probe.bits.image.generation > probeResident.image.generation)
  }
  val probeCandidate = Wire(Valid(new L2PreservationCandidate(params)))
  probeCandidate.valid := probeNeedsGate
  probeCandidate.bits.set := sinkC.io.probe.bits.set
  probeCandidate.bits.way := probeResident.way; probeCandidate.bits.tag := probeResident.tag
  probeCandidate.bits.image := probeResident.image; probeCandidate.bits.dirty := probeResident.dirty
  probeCandidate.bits.outerPreserved := probeResident.outerPreserved; probeCandidate.bits.reason := UInt(2)
  val selectableCandidates = mshrs.zip(candidates).zipWithIndex.map { case ((m, x), i) =>
    val preemptors = mshrs.zipWithIndex.filter { case (_, j) => j > i && j >= params.mshrs - 2 }
    val preempted = preemptors.map { case (n, _) =>
      n.io.status.valid && n.io.status.bits.set === m.io.status.bits.set
    }.foldLeft(Bool(false))(_||_)
    val eligible = Wire(init = x)
    eligible.valid := x.valid && !preempted
    eligible
  }
  val allCandidates = probeCandidate +: selectableCandidates
  val candidateQuiescent = Seq(Bool(true)) ++ mshrs.map(_.io.quiescent)
  val runnable = Vec(allCandidates.zip(candidateQuiescent).map { case (x, q) =>
    val safe = CacheImage.safe(x.bits.image, io.safeWatermark)
    // The sidecar scanner may not yet have raised publish.valid. A direct
    // safe resident Put must wait for already-owned safe history,
    // just like SourceC below; otherwise a newer Put can precede old history.
    // Unsafe preservation still consumes escape credit and can unblock C.
    x.valid && q && Mux(safe, !versionHistory.io.publishPending && !historyCPending && !historyCPartial,
      versionHistory.io.escapeAvailable)
  }).asUInt
  // Unsafe waiters do not monopolize the shared checkpoint engine. Stop new
  // bank pipeline work while draining, so capture cannot starve behind a
  // continuous stream of otherwise independent SourceD/SourceC operations.
  val candidateOH = Mux(runnable.orR, PriorityEncoderOH(runnable),
    PriorityEncoderOH(Vec(allCandidates.map(_.valid)).asUInt))
  val drainForCheckpoint = (runnable.orR || versionHistory.io.publishPending) && !preservation.io.lock.valid
  // No set lock is acquired until the complete-line storage credit exists.
  // The active lock then excludes competing archive ingress above.
  preservation.io.candidate.valid := runnable.orR
  preservation.io.candidate.bits := Mux1H(candidateOH, allCandidates.map(_.bits))
  preservation.io.drained := sourceD.io.idle && sourceC.io.idle && !sinkC.io.bankBusy &&
    (!preservation.io.candidate.valid || Mux1H(candidateOH, candidateQuiescent)) &&
    mshrs.map(m => !versionHistory.io.publish.valid ||
      m.io.status.bits.set =/= publishSet ||
      // Drain outer refill/writeback across the set and wait for only those
      // probes whose resident could change upon receipt.
      (m.io.baselineOuterReady && m.io.baselineProbeReady)).reduce(_ && _)
  io.drain.state := preservation.io.debugState
  io.drain.candidate := preservation.io.candidate.valid
  io.drain.safe := CacheImage.safe(preservation.io.candidate.bits.image, io.safeWatermark)
  io.drain.selected := candidateOH
  io.drain.quiescent := Mux1H(candidateOH, candidateQuiescent)
  io.drain.drained := preservation.io.drained
  io.drain.requested := drainForCheckpoint
  io.drain.sourceDIdle := sourceD.io.idle
  io.drain.sourceDBusy := sourceD.io.drainBusy
  io.drain.sourceCIdle := sourceC.io.idle
  io.drain.sourceCBusy := sourceC.io.drainBusy
  io.drain.sinkCBusy := sinkC.io.bankBusy
  io.drain.mshrPending := Cat(mshrs.map(_.io.status.valid).reverse)
  io.drain.mshrQuiescent := Cat(mshrs.map(_.io.quiescent).reverse)
  io.drain.sourceDValid := sourceD.io.req.valid
  io.drain.sourceDReady := sourceD.io.req.ready
  io.drain.sourceCValid := sourceC.io.req.valid
  io.drain.sourceCReady := sourceC.io.req.ready
  io.drain.probeValid := sinkC.io.probe.valid
  io.drain.probeAllow := sinkC.io.probeAllow
  io.drain.issued := preservation.io.debugIssued
  io.drain.ackSeen := preservation.io.debugAckSeen
  val drainImage = Mux(preservation.io.lock.valid, preservation.io.lock.bits, preservation.io.candidate.bits)
  io.drain.address := params.restoreAddress(params.expandAddress(drainImage.tag, drainImage.set, UInt(0)))
  if (trace) {
    val cycle = RegInit(UInt(0, width = 64))
    cycle := cycle + UInt(1)
    val waiting = preservation.io.candidate.valid || preservation.io.lock.valid
    val age = RegInit(UInt(0, width = 8))
    age := Mux(waiting, age + UInt(1), UInt(0))
    val prior = RegNext(io.drain.asUInt)
    when (waiting && (prior =/= io.drain.asUInt || age === UInt(0))) {
      printf("STAGE3_DRAIN cycle=%d bank=%x state=%x candidate=%x safe=%x selected=%x drained=%x requested=%x quiescent=%x sourceD_idle=%x sourceD_busy=%x sourceC_idle=%x sourceC_busy=%x sinkC_bank_pending=%x mshr_pending=%x mshr_quiescent=%x sourceD_valid=%x sourceD_ready=%x sourceC_valid=%x sourceC_ready=%x probe_valid=%x probe_allow=%x req_valid=%x req_ready=%x issued=%x ack_seen=%x matching_ack=%x pending=%x set=%x way=%x addr=%x txn=%x watermark=%x\n",
        cycle, io.bank, io.drain.state, io.drain.candidate, io.drain.safe, candidateOH,
        io.drain.drained, drainForCheckpoint, io.drain.quiescent, sourceD.io.idle, sourceD.io.drainBusy,
        sourceC.io.idle, sourceC.io.drainBusy, sinkC.io.bankBusy, io.drain.mshrPending,
        io.drain.mshrQuiescent, sourceD.io.req.valid, sourceD.io.req.ready, sourceC.io.req.valid,
        sourceC.io.req.ready, sinkC.io.probe.valid, sinkC.io.probeAllow,
        io.drain.requestValid, io.drain.requestReady, preservation.io.debugIssued, preservation.io.debugAckSeen,
        preservation.io.completed.valid, preservation.io.lock.valid, drainImage.set, drainImage.way,
        io.drain.address, preservation.io.txn, io.safeWatermark)
    }
  }
  def locked(set: UInt): Bool = preservation.io.lock.valid && preservation.io.lock.bits.set === set
  // A new receipt may finish after the directory check. Delay handoff during
  // its lock and use the receipt's actual key when it arrives.
  historyCCaptureAllowed := !locked(historyCSet)
  when (historyCPending && preservation.io.baseline.fire() &&
    historyCSet === preservation.io.baseline.bits.set && historyCTag === preservation.io.baseline.bits.tag &&
    CacheImage.coveredTracked(historyCLine.key, preservation.io.baseline.bits.image)) {
    historyCPending := Bool(false)
  }
  sinkC.io.probeAllow := !probeNeedsGate && !locked(sinkC.io.probe.bits.set)
  when (sinkC.io.probe.valid) {
    assert(probeFound, "Stage3 ProbeAckData has no resident owner")
  }
  val peerResponseBlocked = mshrs.map { m =>
    val d = m.io.schedule.bits.d
    m.io.schedule.valid && d.valid && d.bits.prio(0) && !d.bits.control && !d.bits.bad &&
      CacheImage.exposesResident(d.bits.opcode) &&
      !params.isImageAware(d.bits.source) &&
      (!historySafe(d.bits.image) ||
       (m.io.resident.bits.hit && !historySafe(m.io.resident.bits.image) &&
        (d.bits.opcode === TLMessages.ArithmeticData || d.bits.opcode === TLMessages.LogicalData)))
  }
  val parkReady = mshrs.map { m =>
    val p = m.io.schedule.bits.park
    !p.valid || ((!m.io.schedule.bits.dir.valid || !sinkC.io.bankBusy) && waitSources.zipWithIndex.map { case (source, i) =>
      Bool(source >= 0) && p.bits.request.source === UInt(source max 0) && !clientWaitValid(i)
    }.reduce(_||_))
  }
  // The shared indexed history reader checks the address of a trusted Put or
  // AMO after coherence has finished returning predecessors. No checker or
  // history publication owns this reservation while the request is parked.
  val trustedChecked = RegInit(Bool(false))
  val trustedMshr = Reg(UInt(width = log2Ceil(params.mshrs)))
  val trustedAddress = Reg(UInt(width = 64))
  val trustedSeq = Reg(UInt(width = 32))
  val trustedInvalidated = RegInit(Bool(false))
  val trustedCheckVec = Vec(mshrs.zip(candidates).map { case (m, x) =>
    m.io.trustedWrite && !x.valid && !locked(m.io.status.bits.set)
  }).asUInt
  val trustedCheckOH = PriorityEncoderOH(trustedCheckVec)
  // A query starts with both C ingress and queue empty. Watch every later
  // ingress beat, including any that queues behind a blocked head, so a
  // matching line invalidates the query before it can authorize a write.
  val ingressKey = io.in.c.bits.user.lift(CacheImage).getOrElse(0.U.asTypeOf(new CacheImageKey))
  val trustedIncoming = (io.in.c.valid && params.inner.hasData(io.in.c.bits) && ingressKey.valid &&
    params.restoreAddress(io.in.c.bits.address) === trustedAddress) ||
    ((historyCPending || historyCPartial) && historyCLine.address === trustedAddress) ||
    (io.historyArchive.valid && io.historyArchive.bits.address === trustedAddress) ||
    (preservation.io.archive.valid && preservation.io.archive.bits.address === trustedAddress)
  val trustedOrderBusy = versionHistory.io.publishPending || io.historyQuery.valid
  val historyKnownEmpty = versionHistory.io.empty && historyQueryClear &&
    !io.historyArchive.valid && !preservation.io.archive.valid
  trustedQuery.valid := trustedCheckVec.orR && !trustedChecked && !trustedQueryInFlight &&
    !trustedOrderBusy && !historyKnownEmpty && !io.historyArchive.valid && !preservation.io.archive.valid
  trustedQuery.bits := recoveryContext
  trustedQuery.bits.installOnly := Bool(false)
  trustedQuery.bits.address := Mux1H(trustedCheckOH, mshrs.map(_.io.trustedAddress))
  when (trustedQuery.fire()) {
    trustedMshr := OHToUInt(trustedCheckOH)
    trustedAddress := trustedQuery.bits.address
    trustedInvalidated := Bool(false)
  }
  when (trustedQueryInFlight && (trustedIncoming || trustedOrderBusy)) { trustedInvalidated := Bool(true) }
  when (trustedResult.valid) {
    trustedChecked := !trustedInvalidated && !trustedIncoming && !trustedOrderBusy
    trustedSeq := Mux(trustedResult.bits.found, trustedResult.bits.line.key.contentSeq, UInt(0))
  }
  val trustedMatches = mshrs.zipWithIndex.map { case (m, i) =>
    trustedMshr === UInt(i) && m.io.trustedWrite && m.io.trustedAddress === trustedAddress
  }
  when (trustedChecked && (trustedIncoming || trustedOrderBusy || !Vec(trustedMatches).asUInt.orR)) {
    trustedChecked := Bool(false)
  }
  val trustedApproved = trustedMatches.map(_ && trustedChecked && !trustedIncoming && !trustedOrderBusy)
  mshrs.zip(trustedApproved).foreach { case (m, approved) =>
    m.io.trustedWait.valid := approved && trustedSeq > io.safeWatermark
    m.io.trustedWait.bits := trustedSeq
    m.io.trustedAllow := historyKnownEmpty || (approved && trustedSeq === UInt(0))
    when (approved && m.io.schedule.fire() &&
      (m.io.schedule.bits.d.valid || m.io.schedule.bits.park.valid)) { trustedChecked := Bool(false) }
  }
  val stage3Allowed = mshrs.zip(candidates).map { case (m, x) =>
    val awaitingCReceiptCheck = historyCPending && !historyCChecked &&
      historyCSet === m.io.status.bits.set && historyCTag === m.io.resident.bits.tag
    val outerSafe = !m.io.schedule.bits.c.valid ||
      (!awaitingCReceiptCheck && (historySafe(m.io.resident.bits.image) || m.io.resident.bits.outerPreserved ||
        !recoveryContext.survives(m.io.resident.bits.image.contentSeq)) &&
        ((!m.io.resident.bits.dirty || m.io.resident.bits.outerPreserved) ||
          (!versionHistory.io.publishPending && !historyCPending && !historyCPartial)))
    !baselineActive && (!x.valid || m.io.schedule.bits.park.valid) && !locked(m.io.status.bits.set) && outerSafe &&
      (!m.io.schedule.bits.c.valid || (!preservation.io.lock.valid && !drainForCheckpoint)) &&
      // A safe history candidate must reach the coherent baseline before D
      // can expose an older resident. Keep this barrier while the shared
      // preservation engine owns a different set as well.
      (!m.io.schedule.bits.d.valid || (!drainForCheckpoint && !versionHistory.io.publishPending))
  }
  val unsafeVictims = mshrs.map(m => m.io.schedule.valid && m.io.schedule.bits.c.valid &&
    !historySafe(m.io.resident.bits.image))
  val unsafeSameLine = allCandidates.map(x => x.valid && !CacheImage.safe(x.bits.image, io.safeWatermark))
  val unsafeOH = PriorityEncoderOH(Vec(unsafeVictims ++ unsafeSameLine).asUInt)
  io.validationBlock := (unsafeVictims ++ unsafeSameLine).reduce(_||_) || versionHistory.io.pressure
  io.validationSeq := Mux(versionHistory.io.pressure, versionHistory.io.pressureSeq,
    Mux1H(unsafeOH, mshrs.map(_.io.resident.bits.image.contentSeq) ++
      allCandidates.map(_.bits.image.contentSeq)))
  val victimBlocked = RegNext(Vec(unsafeVictims).asUInt, UInt(0, width = params.mshrs))
  mshrs.zipWithIndex.foreach { case (m, i) =>
    when (unsafeVictims(i) && !victimBlocked(i)) {
      printf("STAGE3_TX L2_VALIDATION_BLOCK bank=%x set=%x way=%x tag=%x gen=%x seq=%x writer=%x reason=4\n",
        io.bank, m.io.status.bits.set, m.io.resident.bits.way, m.io.resident.bits.tag,
        m.io.resident.bits.image.generation, m.io.resident.bits.image.contentSeq, m.io.resident.bits.image.writer)
    }
  }

  // Deliver messages from Sinks to MSHRs
  mshrs.zipWithIndex.foreach { case (m, i) =>
    m.io.sinkc.valid := m.io.status.valid && sinkC.io.resp.valid && sinkC.io.resp.bits.set === m.io.status.bits.set
    m.io.sinkd.valid := sinkD.io.resp.valid && sinkD.io.resp.bits.source === UInt(i)
    m.io.sinke.valid := sinkE.io.resp.valid && sinkE.io.resp.bits.sink   === UInt(i)
    m.io.sinkc.bits := sinkC.io.resp.bits
    m.io.sinkd.bits := sinkD.io.resp.bits
    m.io.sinke.bits := sinkE.io.resp.bits
    m.io.nestedwb := nestedwb
    m.io.releaseSent.valid := sourceC.io.c.fire() && sourceC.io.c_last &&
      sourceC.io.c.bits.opcode(1) && sourceC.io.c.bits.source === UInt(i)
    m.io.releaseSent.bits := sourceC.io.c.bits.echo.lift(CachePreserveTxn).getOrElse(UInt(0, width = 64))
  }

  // If the pre-emption BC or C MSHR have a matching set, the normal MSHR must be blocked
  val mshr_stall_abc = abc_mshrs.map { m =>
    (bc_mshr.io.status.valid && m.io.status.bits.set === bc_mshr.io.status.bits.set) ||
    ( c_mshr.io.status.valid && m.io.status.bits.set ===  c_mshr.io.status.bits.set)
  }
  val mshr_stall_bc =
    c_mshr.io.status.valid && bc_mshr.io.status.bits.set === c_mshr.io.status.bits.set
  val mshr_stall_c = Bool(false)
  val mshr_stall = mshr_stall_abc :+ mshr_stall_bc :+ mshr_stall_c


  val stall_abc = (mshr_stall_abc zip abc_mshrs) map { case (s, m) => s && m.io.status.valid }
  if (!params.lastLevel || !params.firstLevel)
    params.ccover(stall_abc.reduce(_||_), "SCHEDULER_ABC_INTERLOCK", "ABC MSHR interlocked due to pre-emption")
  if (!params.lastLevel)
    params.ccover(mshr_stall_bc && bc_mshr.io.status.valid, "SCHEDULER_BC_INTERLOCK", "BC MSHR interlocked due to pre-emption")

  // Consider scheduling an MSHR only if all the resources it requires are available
  // stage3Allowed checks the actual victim's safety, pending publications
  // and set ownership. A producer close request caused by unrelated history
  // pressure must leave eligible C traffic running, including Checker victims.
  val mshr_request = Cat(mshrs.zip(mshr_stall).zip(stage3Allowed).zipWithIndex.map { case (((m, s), allowed), i) =>
    // A nested C can wait for History publication while that publication
    // drains the preempted plan's accepted outer Grant. Its terminal E has
    // no bank/directory effect and must be allowed to break this wait cycle.
    // The schedule remains all-or-none: never bypass with another operation.
    val q = m.io.schedule.bits
    val grantAckOnly = q.e.valid && !q.a.valid && !q.b.valid && !q.c.valid &&
      !q.d.valid && !q.x.valid && !q.dir.valid && !q.park.valid
    m.io.schedule.valid && (!s || grantAckOnly) && allowed && parkReady(i) && !peerResponseBlocked(i) &&
      (sourceA.io.req.ready || !m.io.schedule.bits.a.valid) &&
      (sourceB.io.req.ready || !m.io.schedule.bits.b.valid) &&
      (sourceC.io.req.ready || !m.io.schedule.bits.c.valid) &&
      (sourceD.io.req.ready || !m.io.schedule.bits.d.valid) &&
      (sourceE.io.req.ready || !m.io.schedule.bits.e.valid) &&
      (sourceX.io.req.ready || !m.io.schedule.bits.x.valid) &&
      (directory.io.write.ready || !m.io.schedule.bits.dir.valid)
  }.reverse)

  // Round-robin arbitration of MSHRs
  val robin_filter = RegInit(UInt(0, width = params.mshrs))
  def selectMshr(req: UInt): UInt = {
    val robinRequest = Cat(req, req & robin_filter)
    val selectOH2 = ~(leftOR(robinRequest) << 1) & robinRequest
    selectOH2(2 * params.mshrs - 1, params.mshrs) |
      selectOH2(params.mshrs - 1, 0)
  }
  val mshr_selectOH = selectMshr(mshr_request)
  val mshr_select = OHToUInt(mshr_selectOH)
  val schedule = Mux1H(mshr_selectOH, mshrs.map(_.io.schedule.bits))
  val scheduleTag = Mux1H(mshr_selectOH, mshrs.map(_.io.status.bits.tag))
  val scheduleSet = Mux1H(mshr_selectOH, mshrs.map(_.io.status.bits.set))

  // When an MSHR wins the schedule, it has lowest priority next time
  when (mshr_request.orR) { robin_filter := ~rightOR(mshr_selectOH) }

  // Fill in which MSHR sends the request
  schedule.a.bits.source := mshr_select
  schedule.c.bits.source := Mux(schedule.c.bits.opcode(1), mshr_select, UInt(0)) // only set for Release[Data] not ProbeAck[Data]
  schedule.d.bits.sink   := mshr_select

  sourceA.io.req := schedule.a
  sourceB.io.req := schedule.b
  sourceC.io.req := schedule.c
  // P4-05: release coherence permission for discarded bytes without writing
  // them to outer memory. The normal Release/ReleaseAck lifecycle remains.
  when (!recoveryContext.survives(schedule.c.bits.image.contentSeq)) {
    sourceC.io.req.bits.dirty := Bool(false)
    sourceC.io.req.bits.opcode := schedule.c.bits.opcode & UInt(6, width = 3)
  }
  when (schedule.park.valid) {
    val p = schedule.park.bits
    val matches = Vec(waitSources.map(source => Bool(source >= 0) && p.request.source === UInt(source max 0)))
    assert(PopCount(matches) === UInt(1), "client wait source not classified")
    clientWait.zip(clientWaitValid).zipWithIndex.foreach { case ((q, v), i) =>
      when (matches(i)) {
        assert(!v, "client source reused while parked")
        q := p
        v := Bool(true)
      }
    }
    printf("STAGE3_TX L2_CLIENT_WAIT bank=%x mshr=%x source=%x opcode=%x set=%x tag=%x seq=%x watermark=%x commit=%x\n",
      io.bank, mshr_select, p.request.source, p.request.opcode, p.request.set, p.request.tag,
      p.seq, io.safeWatermark, schedule.dir.valid)
  }
  sourceD.io.req := schedule.d
  // Classify the selected Acquire hint at the response selection boundary.
  // SourceD freezes this bit with the payload selection in its existing pipe.
  // publishPending below/at admission prevents certification before History
  // publication; one shared comparison replaces Main's later SW comparison.
  val recoverySeq = Mux1H(mshr_selectOH, mshrs.map(_.io.recoverySeq))
  sourceD.io.req.bits.recoverySafe := recoverySeq <= io.safeWatermark
  when (sourceD.io.req.fire() && sourceD.io.req.bits.prio(0) &&
        !sourceD.io.req.bits.control && !sourceD.io.req.bits.bad &&
        CacheImage.exposesResident(sourceD.io.req.bits.opcode)) {
    assert(params.isImageAware(sourceD.io.req.bits.source) ||
      (historySafe(sourceD.io.req.bits.image) &&
       (!(sourceD.io.req.bits.opcode === TLMessages.ArithmeticData ||
          sourceD.io.req.bits.opcode === TLMessages.LogicalData) ||
        !Mux1H(mshr_selectOH, mshrs.map(_.io.resident.bits.hit)) ||
        CacheImage.safe(Mux1H(mshr_selectOH, mshrs.map(_.io.resident.bits.image)), io.safeWatermark))),
      "L2_UNSAFE_CLIENT_TRANSFER")
  }
  when (sourceD.io.req.fire()) {
    val old = Mux1H(mshr_selectOH, mshrs.map(_.io.resident.bits))
    printf("STAGE3_TX L2_EXECUTE set=%x way=%x tag=%x old_valid=%x old_writer=%x old_gen=%x old_seq=%x dirty=%x outer=%x new_valid=%x new_writer=%x new_gen=%x new_seq=%x opcode=%x prio=%x\n",
      scheduleSet, sourceD.io.req.bits.way, scheduleTag, old.image.valid, old.image.writer,
      old.image.generation, old.image.contentSeq, old.dirty, old.outerPreserved,
      sourceD.io.req.bits.image.valid, sourceD.io.req.bits.image.writer,
      sourceD.io.req.bits.image.generation, sourceD.io.req.bits.image.contentSeq,
      sourceD.io.req.bits.opcode, sourceD.io.req.bits.prio.asUInt)
  }
  sourceE.io.req := schedule.e
  sourceX.io.req := schedule.x
  directory.io.write := schedule.dir
  when (baselineState === baselineWrite) {
    val old = baselineResult.image
    val newer = preservation.io.baseline.bits.image
    val obsolete = old.contentSeq < newer.contentSeq ||
      (old.contentSeq === newer.contentSeq && old.generation <= newer.generation)
    val strictlyOlder = old.contentSeq < newer.contentSeq ||
      (old.contentSeq === newer.contentSeq && old.generation < newer.generation)
    directory.io.write.valid := Bool(true)
    directory.io.write.bits.set := preservation.io.baseline.bits.set
    directory.io.write.bits.way := baselineResult.way
    for (name <- (new DirectoryEntry(params)).elements.keys) {
      directory.io.write.bits.data.elements(name) := baselineResult.elements(name)
    }
    directory.io.write.bits.data.outerPreserved := baselineResult.outerPreserved || obsolete
    directory.io.write.bits.data.baselineObsolete := baselineResult.baselineObsolete || strictlyOlder
    when (strictlyOlder) { directory.io.write.bits.data.image := newer }
    when (directory.io.write.fire()) { baselineState := baselineDone }
  }

  // Count a writeback at the first beat accepted by the outer C channel. This
  // matches the L1->L2 accounting point and includes any SourceC queue delay.
  io.dcacheWriteback := sourceC.io.c.fire() && sourceC.io.c_first &&
    sourceC.io.c_dcache
  io.dcacheWritebackDirty := io.dcacheWriteback && sourceC.io.c_dirty
  io.dcacheWritebackPacketSeq := sourceC.io.c_packetSeq
  io.dcacheWritebackPacketTracked := sourceC.io.c_packetTracked
  io.dcacheWritebackRequest := sourceC.io.req.fire() &&
    sourceC.io.req.bits.dcache
  io.dcacheWritebackRequestDirty := io.dcacheWritebackRequest &&
    sourceC.io.req.bits.dirty
  io.dcacheWritebackRequestPacketSeq := sourceC.io.req.bits.packetSeq
  io.dcacheWritebackRequestPacketTracked := sourceC.io.req.bits.packetTracked

  // Forward meta-data changes from nested transaction completion
  val select_c  = mshr_selectOH(params.mshrs-1)
  val select_bc = mshr_selectOH(params.mshrs-2)
  nestedwb.set   := Mux(select_c, c_mshr.io.status.bits.set, bc_mshr.io.status.bits.set)
  nestedwb.tag   := Mux(select_c, c_mshr.io.status.bits.tag, bc_mshr.io.status.bits.tag)
  nestedwb.b_toN       := select_bc && bc_mshr.io.schedule.bits.dir.valid && bc_mshr.io.schedule.bits.dir.bits.data.state === MetaData.INVALID
  nestedwb.b_toB       := select_bc && bc_mshr.io.schedule.bits.dir.valid && bc_mshr.io.schedule.bits.dir.bits.data.state === MetaData.BRANCH
  nestedwb.b_clr_dirty := select_bc && bc_mshr.io.schedule.bits.dir.valid
  nestedwb.c_set_dirty := select_c  &&  c_mshr.io.schedule.bits.dir.valid && c_mshr.io.schedule.bits.dir.bits.data.dirty
  nestedwb.c_set_dcache := select_c && c_mshr.io.schedule.bits.dir.valid && c_mshr.io.schedule.bits.dir.bits.data.dcache
  nestedwb.c_set_packet := select_c && c_mshr.io.schedule.bits.dir.valid &&
    c_mshr.io.schedule.bits.dir.bits.data.dirty
  nestedwb.packetSeq := c_mshr.io.schedule.bits.dir.bits.data.packetSeq
  nestedwb.packetTracked := c_mshr.io.schedule.bits.dir.bits.data.packetTracked
  nestedwb.image := c_mshr.io.schedule.bits.dir.bits.data.image
  nestedwb.outerPreserved := c_mshr.io.schedule.bits.dir.bits.data.outerPreserved
  nestedwb.baselineObsolete := c_mshr.io.schedule.bits.dir.bits.data.baselineObsolete

  // Pick highest priority request
  val preferClientReplay = RegInit(Bool(false))
  val useClientReplay = clientReplay.valid && (!sinkA.io.req.valid || preferClientReplay)
  val clientA = Wire(Decoupled(new FullRequest(params)))
  clientA.valid := sinkA.io.req.valid || clientReplay.valid
  clientA.bits := Mux(useClientReplay, clientReplay.bits, sinkA.io.req.bits)
  sinkA.io.req.ready := clientA.ready && !useClientReplay
  clientReplay.ready := clientA.ready && useClientReplay
  when (clientA.fire()) { preferClientReplay := !useClientReplay }
  val request = Wire(Decoupled(new FullRequest(params)))
  val requestEnabled = directory.io.ready && !baselineActive &&
    !locked(request.bits.set) && !io.identityUnavailable
  request.valid := requestEnabled &&
    (clientA.valid || sinkX.io.req.valid || sinkC.io.req.valid)
  request.bits := Mux(sinkC.io.req.valid, sinkC.io.req.bits,
                  Mux(sinkX.io.req.valid, sinkX.io.req.bits, clientA.bits))
  io.drain.requestValid := request.valid
  io.drain.requestReady := request.ready
  sinkC.io.req.ready := requestEnabled && request.ready
  sinkX.io.req.ready := requestEnabled && request.ready && !sinkC.io.req.valid
  clientA.ready := requestEnabled && request.ready && !sinkC.io.req.valid && !sinkX.io.req.valid

  // If no MSHR has been assigned to this set, we need to allocate one
  val setMatches = Cat(mshrs.map { m => m.io.status.valid && m.io.status.bits.set === request.bits.set }.reverse)
  val alloc = !setMatches.orR // NOTE: no matches also means no BC or C pre-emption on this set
  // If a same-set MSHR says that requests of this type must be blocked (for bounded time), do it
  val blockB = Mux1H(setMatches, mshrs.map(_.io.status.bits.blockB)) && request.bits.prio(1)
  val blockC = Mux1H(setMatches, mshrs.map(_.io.status.bits.blockC)) && request.bits.prio(2)
  // If a same-set MSHR says that requests of this type must be handled out-of-band, use special BC|C MSHR
  // ... these special MSHRs interlock the MSHR that said it should be pre-empted.
  val nestB  = Mux1H(setMatches, mshrs.map(_.io.status.bits.nestB))  && request.bits.prio(1)
  val nestC  = Mux1H(setMatches, mshrs.map(_.io.status.bits.nestC))  && request.bits.prio(2)
  // Prevent priority inversion; we may not queue to MSHRs beyond our level
  val prioFilter = Cat(request.bits.prio(2), !request.bits.prio(0), ~UInt(0, width = params.mshrs-2))
  val lowerMatches = setMatches & prioFilter
  // If we match an MSHR <= our priority that neither blocks nor nests us, queue to it.
  val queue = lowerMatches.orR && !nestB && !nestC && !blockB && !blockC

  if (!params.lastLevel) {
    params.ccover(request.valid && blockB, "SCHEDULER_BLOCKB", "Interlock B request while resolving set conflict")
    params.ccover(request.valid && nestB,  "SCHEDULER_NESTB", "Priority escalation from channel B")
  }
  if (!params.firstLevel) {
    params.ccover(request.valid && blockC, "SCHEDULER_BLOCKC", "Interlock C request while resolving set conflict")
    params.ccover(request.valid && nestC,  "SCHEDULER_NESTC", "Priority escalation from channel C")
  }
  params.ccover(request.valid && queue, "SCHEDULER_SECONDARY", "Enqueue secondary miss")

  // It might happen that lowerMatches has >1 bit if the two special MSHRs are in-use
  // We want to Q to the highest matching priority MSHR.
  val lowerMatches1 =
    Mux(lowerMatches(params.mshrs-1), UInt(1 << (params.mshrs-1)),
    Mux(lowerMatches(params.mshrs-2), UInt(1 << (params.mshrs-2)),
    lowerMatches))

  // If this goes to the scheduled MSHR, it may need to be bypassed
  // Alternatively, the MSHR may be refilled from a request queued in the ListBuffer
  val selected_requests = Cat(mshr_selectOH, mshr_selectOH, mshr_selectOH) & requests.io.valid
  val a_pop = selected_requests((0 + 1) * params.mshrs - 1, 0 * params.mshrs).orR
  val b_pop = selected_requests((1 + 1) * params.mshrs - 1, 1 * params.mshrs).orR
  val c_pop = selected_requests((2 + 1) * params.mshrs - 1, 2 * params.mshrs).orR
  val bypassMatches = (mshr_selectOH & lowerMatches1).orR &&
                      Mux(c_pop || request.bits.prio(2), !c_pop, Mux(b_pop || request.bits.prio(1), !b_pop, !a_pop))
  val may_pop = a_pop || b_pop || c_pop
  val bypass = request.valid && queue && bypassMatches
  val will_reload = schedule.reload && (may_pop || bypass) && !io.identityUnavailable
  val will_pop = schedule.reload && may_pop && !bypass && !io.identityUnavailable

  params.ccover(mshr_selectOH.orR && bypass, "SCHEDULER_BYPASS", "Bypass new request directly to conflicting MSHR")
  params.ccover(mshr_selectOH.orR && will_reload, "SCHEDULER_RELOAD", "Back-to-back service of two requests")
  params.ccover(mshr_selectOH.orR && will_pop, "SCHEDULER_POP", "Service of a secondary miss")

  // Repeat the above logic, but without the fan-in
  mshrs.zipWithIndex.foreach { case (m, i) =>
    val sel = mshr_selectOH(i)
    m.io.schedule.ready := sel
    val a_pop = requests.io.valid(params.mshrs * 0 + i)
    val b_pop = requests.io.valid(params.mshrs * 1 + i)
    val c_pop = requests.io.valid(params.mshrs * 2 + i)
    val bypassMatches = lowerMatches1(i) &&
                        Mux(c_pop || request.bits.prio(2), !c_pop, Mux(b_pop || request.bits.prio(1), !b_pop, !a_pop))
    val may_pop = a_pop || b_pop || c_pop
    val bypass = request.valid && queue && bypassMatches
    val will_reload = m.io.schedule.bits.reload && (may_pop || bypass) && !io.identityUnavailable
    m.io.allocate.bits := Mux(bypass, Wire(new QueuedRequest(params), init = request.bits), requests.io.data)
    m.io.allocate.bits.set := m.io.status.bits.set
    m.io.allocate.bits.repeat := m.io.allocate.bits.tag === m.io.status.bits.tag
    m.io.allocate.valid := sel && will_reload
  }

  // Determine which of the queued requests to pop (supposing will_pop)
  val prio_requests = ~(~requests.io.valid | (requests.io.valid >> params.mshrs) | (requests.io.valid >> 2*params.mshrs))
  val pop_index = OHToUInt(Cat(mshr_selectOH, mshr_selectOH, mshr_selectOH) & prio_requests)
  requests.io.pop.valid := will_pop
  requests.io.pop.bits  := pop_index

  // Reload from the Directory if the next MSHR operation changes tags
  val lb_tag_mismatch = scheduleTag =/= requests.io.data.tag
  val mshr_uses_directory_assuming_no_bypass = schedule.reload && may_pop && lb_tag_mismatch
  val mshr_uses_directory_for_lb = will_pop && lb_tag_mismatch
  val mshr_uses_directory = will_reload && scheduleTag =/= Mux(bypass, request.bits.tag, requests.io.data.tag)

  // Is there an MSHR free for this request?
  val mshr_validOH = Cat(mshrs.map(_.io.status.valid).reverse)
  val mshr_free = (~mshr_validOH & prioFilter).orR

  // Fanout the request to the appropriate handler (if any)
  val bypassQueue = schedule.reload && bypassMatches
  val request_alloc_cases =
     (alloc && !mshr_uses_directory_assuming_no_bypass && mshr_free) ||
     (nestB && !mshr_uses_directory_assuming_no_bypass && !bc_mshr.io.status.valid && !c_mshr.io.status.valid) ||
     (nestC && !mshr_uses_directory_assuming_no_bypass && !c_mshr.io.status.valid)
  request.ready := !io.identityUnavailable &&
    (request_alloc_cases || (queue && (bypassQueue || requests.io.push.ready)))
  val alloc_uses_directory = request.valid && request_alloc_cases

  // When a request goes through, it will need to hit the Directory
  directory.io.read.valid := mshr_uses_directory || alloc_uses_directory
  directory.io.read.bits.set := Mux(mshr_uses_directory_for_lb, scheduleSet,          request.bits.set)
  directory.io.read.bits.tag := Mux(mshr_uses_directory_for_lb, requests.io.data.tag, request.bits.tag)
  directory.io.read.bits.checkerFetch :=
    Mux(mshr_uses_directory_for_lb, requests.io.data.prio(0), request.bits.prio(0)) &&
    CacheImage.exposesResident(Mux(mshr_uses_directory_for_lb, requests.io.data.opcode, request.bits.opcode)) &&
    !params.isImageAware(Mux(mshr_uses_directory_for_lb, requests.io.data.source, request.bits.source))
  directory.io.read.bits.maintenance := Bool(false)
  directory.io.read.bits.maintenanceWay := UInt(0)
  when (baselineState === baselineRead && directory.io.ready &&
    !(mshr_uses_directory || alloc_uses_directory)) {
    directory.io.read.valid := Bool(true)
    directory.io.read.bits.set := preservation.io.baseline.bits.set
    directory.io.read.bits.tag := preservation.io.baseline.bits.tag
    directory.io.read.bits.checkerFetch := Bool(false)
    baselineReadFire := Bool(true)
  }
  when (maintState === maintRead && directory.io.ready && !baselineActive &&
    !(mshr_uses_directory || alloc_uses_directory)) {
    directory.io.read.valid := Bool(true)
    directory.io.read.bits.set := maintSet
    directory.io.read.bits.tag := UInt(0)
    directory.io.read.bits.checkerFetch := Bool(false)
    directory.io.read.bits.maintenance := Bool(true)
    directory.io.read.bits.maintenanceWay := maintWay
    maintReadFire := Bool(true)
  }
  when (historyCPending && !historyCChecked && !historyCCheckWaiting &&
    directory.io.ready && !baselineActive && !locked(historyCSet) &&
    maintState =/= maintRead && !(mshr_uses_directory || alloc_uses_directory)) {
    directory.io.read.valid := Bool(true)
    directory.io.read.bits.set := historyCSet
    directory.io.read.bits.tag := historyCTag
    directory.io.read.bits.checkerFetch := Bool(false)
    historyCCheckFire := Bool(true)
  }

  // Enqueue the request if not bypassed directly into an MSHR
  requests.io.push.valid := request.valid && queue && !bypassQueue
  requests.io.push.bits.data  := request.bits
  requests.io.push.bits.index := Mux1H(
    request.bits.prio, Seq(
      OHToUInt(lowerMatches1 << params.mshrs*0),
      OHToUInt(lowerMatches1 << params.mshrs*1),
      OHToUInt(lowerMatches1 << params.mshrs*2)))

  val mshr_insertOH = ~(leftOR(~mshr_validOH) << 1) & ~mshr_validOH & prioFilter
  (mshr_insertOH.asBools zip mshrs) map { case (s, m) =>
    when (request.valid && alloc && s && !mshr_uses_directory_assuming_no_bypass) {
      m.io.allocate.valid := Bool(true)
      m.io.allocate.bits := request.bits
      m.io.allocate.bits.repeat := Bool(false)
    }
  }

  when (request.valid && nestB && !bc_mshr.io.status.valid && !c_mshr.io.status.valid && !mshr_uses_directory_assuming_no_bypass) {
    bc_mshr.io.allocate.valid := Bool(true)
    bc_mshr.io.allocate.bits := request.bits
    bc_mshr.io.allocate.bits.repeat := Bool(false)
    assert (!request.bits.prio(0))
  }
  bc_mshr.io.allocate.bits.prio(0) := Bool(false)

  when (request.valid && nestC && !c_mshr.io.status.valid && !mshr_uses_directory_assuming_no_bypass) {
    c_mshr.io.allocate.valid := Bool(true)
    c_mshr.io.allocate.bits := request.bits
    c_mshr.io.allocate.bits.repeat := Bool(false)
    assert (!request.bits.prio(0))
    assert (!request.bits.prio(1))
  }
  c_mshr.io.allocate.bits.prio(0) := Bool(false)
  c_mshr.io.allocate.bits.prio(1) := Bool(false)

  // Fanout the result of the Directory lookup
  val dirTarget = Mux(alloc, mshr_insertOH, Mux(nestB, UInt(1 << (params.mshrs-2)), UInt(1 << (params.mshrs-1))))
  val directoryFanout = params.dirReg(RegNext(Mux(mshr_uses_directory, mshr_selectOH, Mux(alloc_uses_directory, dirTarget, UInt(0)))))
  mshrs.zipWithIndex.foreach { case (m, i) =>
    m.io.directory.valid := directoryFanout(i)
    m.io.directory.bits := directory.io.result.bits
  }

  // MSHR response meta-data fetch
  sinkC.io.way :=
    Mux(bc_mshr.io.status.valid && bc_mshr.io.status.bits.set === sinkC.io.set,
      bc_mshr.io.status.bits.way,
      Mux1H(abc_mshrs.map(m => m.io.status.valid && m.io.status.bits.set === sinkC.io.set),
            abc_mshrs.map(_.io.status.bits.way)))
  sinkD.io.way := Vec(mshrs.map(_.io.status.bits.way))(sinkD.io.source)
  sinkD.io.set := Vec(mshrs.map(_.io.status.bits.set))(sinkD.io.source)

  // CACHE_OPPORTUNITY_OBSERVATION_ONLY: actual accepted lookups/traffic and
  // input-only host shadow models. No ready/valid, replacement, or barrier
  // predicate depends on these observations.
  val observationReset = chisel3.WireInit(false.B)
  val observationEnable = chisel3.WireInit(false.B)
  BoringUtils.addSink(observationReset, GH_GlobalParams.GH_L2_STATS_RESET_BORE)
  BoringUtils.addSink(observationEnable, GH_GlobalParams.GH_L2_STATS_ENABLE_BORE)
  val observationContext = SafeChainObservation.context()
  val observationStop = RegNext(observationEnable, Bool(false)) && !observationEnable
  // FullRequest adds fields to QueuedRequest, so a direct aggregate Mux
  // fails Chisel's runtime type check. Project by field connection, exactly
  // as the functional MSHR allocation path does above; do not bit-cast.
  val observationIncoming = Wire(new QueuedRequest(params), init = request.bits)
  val observationLookup = params.dirReg(RegEnable(
    Mux(mshr_uses_directory_for_lb, requests.io.data, observationIncoming), directory.io.read.valid))
  val observationDemand = directory.io.result.valid && observationLookup.prio(0) &&
    !observationLookup.control && observationLookup.opcode =/= TLMessages.Hint
  val observationSet = params.dirReg(RegEnable(directory.io.read.bits.set, directory.io.read.valid))
  val observationAddress = params.expandAddress(observationLookup.tag, observationSet, UInt(0))
  val observationWrite = observationLookup.opcode === TLMessages.PutFullData ||
    observationLookup.opcode === TLMessages.PutPartialData ||
    observationLookup.opcode === TLMessages.ArithmeticData || observationLookup.opcode === TLMessages.LogicalData ||
    (observationLookup.opcode === TLMessages.AcquirePerm) ||
    (observationLookup.opcode === TLMessages.AcquireBlock && observationLookup.param =/= TLPermissions.NtoB)
  val (observationAFirst, _, _, _) = params.inner.count(io.in.a)
  val (observationCFirst, _, _, _) = params.inner.count(io.in.c)
  val (observationOuterAFirst, _, _, _) = params.outer.count(io.out.a)
  val (observationOuterCFirst, _, _, _) = params.outer.count(io.out.c)
  val observationMemRead = io.out.a.bits.opcode === TLMessages.Get ||
    io.out.a.bits.opcode === TLMessages.AcquireBlock
  val observationMemWrite = io.out.a.bits.opcode === TLMessages.PutFullData ||
    io.out.a.bits.opcode === TLMessages.PutPartialData
  val observationEvents = Seq(
    CacheOpportunityObservation.event(observationDemand, 1,
      Vec(Seq(!observationWrite, observationWrite, directory.io.result.bits.hit,
        !directory.io.result.bits.hit)).asUInt,
      observationAddress, set = observationSet, way = directory.io.result.bits.way,
      occupancy = directory.io.observationValidWays),
    CacheOpportunityObservation.event(sourceC.io.req.fire() && sourceC.io.req.bits.reason === UInt(1),
      2, sourceC.io.req.bits.dirty.asUInt,
      set = sourceC.io.req.bits.set, way = sourceC.io.req.bits.way),
    CacheOpportunityObservation.event(directory.io.write.fire(), 5,
      Vec(Seq(directory.io.write.bits.data.state =/= MetaData.INVALID,
        directory.io.write.bits.data.dirty)).asUInt,
      params.expandAddress(directory.io.write.bits.data.tag, directory.io.write.bits.set, UInt(0)),
      set = directory.io.write.bits.set, way = directory.io.write.bits.way),
    CacheOpportunityObservation.event(io.in.a.fire() && observationAFirst, 6, UInt(1)),
    CacheOpportunityObservation.event(io.in.c.fire() && observationCFirst, 6, UInt(2)),
    CacheOpportunityObservation.event(io.out.a.fire() && observationOuterAFirst &&
      (observationMemRead || observationMemWrite), 7,
      Vec(Seq(observationMemRead, observationMemWrite)).asUInt,
      value = UInt(1, width = 64) << io.out.a.bits.size),
    CacheOpportunityObservation.event(io.out.c.fire() && observationOuterCFirst &&
      io.out.c.bits.opcode === TLMessages.ReleaseData, 7, UInt(2), value = UInt(params.cache.blockBytes)),
    CacheOpportunityObservation.event(sourceC.io.req.fire(), 8),
    CacheOpportunityObservation.event(io.in.c.fire() && observationCFirst &&
      io.in.c.bits.opcode === TLMessages.ReleaseData, 12, address = io.in.c.bits.address))
  CacheOpportunityObservation.emit(2, params.cache.sets, params.cache.ways,
    params.cache.blockBytes, params.mshrs, clock, reset, observationReset,
    observationEnable, observationStop, io.bank, observationContext._1,
    PopCount(mshrs.map(_.io.status.valid)), mshrs.map(_.io.status.valid).reduce(_ && _), observationEvents)

  // Beat buffer connections between components
  sinkA.io.pb_pop <> sourceD.io.pb_pop
  sourceD.io.pb_beat := sinkA.io.pb_beat
  sinkC.io.rel_pop <> sourceD.io.rel_pop
  sourceD.io.rel_beat := sinkC.io.rel_beat

  // BankedStore ports
  bankedStore.io.sinkC_adr <> sinkC.io.bs_adr
  bankedStore.io.sinkC_dat := sinkC.io.bs_dat
  bankedStore.io.sinkD_adr <> sinkD.io.bs_adr
  bankedStore.io.sinkD_dat := sinkD.io.bs_dat
  bankedStore.io.sourceC_adr.valid := Mux(preservation.io.lock.valid, preservation.io.bs_adr.valid, sourceC.io.bs_adr.valid)
  bankedStore.io.sourceC_adr.bits := Mux(preservation.io.lock.valid, preservation.io.bs_adr.bits, sourceC.io.bs_adr.bits)
  preservation.io.bs_adr.ready := preservation.io.lock.valid && bankedStore.io.sourceC_adr.ready
  sourceC.io.bs_adr.ready := !preservation.io.lock.valid && bankedStore.io.sourceC_adr.ready
  bankedStore.io.sourceD_radr <> sourceD.io.bs_radr
  bankedStore.io.sourceD_wadr <> sourceD.io.bs_wadr
  bankedStore.io.sourceD_wdat := sourceD.io.bs_wdat
  sourceC.io.bs_dat := bankedStore.io.sourceC_dat
  preservation.io.bs_dat := bankedStore.io.sourceC_dat
  sourceD.io.bs_rdat := bankedStore.io.sourceD_rdat

  // SourceD data hazard interlock
  sourceD.io.evict_req := sourceC.io.evict_req
  sourceD.io.grant_req := sinkD  .io.grant_req
  sourceC.io.evict_safe := sourceD.io.evict_safe
  sinkD  .io.grant_safe := sourceD.io.grant_safe

  // The reservation covers physical effects, not just candidate selection.
  when (preservation.io.lock.valid) {
    assert(!(directory.io.write.fire() && locked(directory.io.write.bits.set) && baselineState =/= baselineWrite), "L2_PREMATURE_OVERWRITE_ERROR directory")
    assert(!(sourceD.io.bs_wadr.fire() && locked(sourceD.io.bs_wadr.bits.set)), "L2_PREMATURE_OVERWRITE_ERROR SourceD")
    assert(!(sinkC.io.bs_adr.fire() && !sinkC.io.bs_adr.bits.noop && locked(sinkC.io.bs_adr.bits.set)), "L2_PREMATURE_OVERWRITE_ERROR SinkC")
    assert(!(sinkD.io.bs_adr.fire() && !sinkD.io.bs_adr.bits.noop && locked(sinkD.io.bs_adr.bits.set)), "L2_PREMATURE_OVERWRITE_ERROR refill")
  }
  when (sourceC.io.req.fire()) {
    assert(sourceC.io.req.bits.source < UInt(InclusiveCacheParameters.out_mshrs(params.cache, params.micro)),
      "L2 MSHR release aliases checkpoint source")
    assert(!sourceC.io.req.bits.dirty || historySafe(sourceC.io.req.bits.image), "L2_SPEC_OUTER_WRITE_ERROR victim")
    printf("STAGE3_TX L2_VICTIM_REQ bank=%x txn=%x source=%x set=%x way=%x tag=%x valid=%x writer=%x gen=%x seq=%x dirty=%x reason=%x\n",
      io.bank, sourceC.io.req.bits.txn, sourceC.io.req.bits.source, sourceC.io.req.bits.set,
      sourceC.io.req.bits.way, sourceC.io.req.bits.tag, sourceC.io.req.bits.image.valid,
      sourceC.io.req.bits.image.writer, sourceC.io.req.bits.image.generation, sourceC.io.req.bits.image.contentSeq,
      sourceC.io.req.bits.dirty, sourceC.io.req.bits.reason)
  }
  when (sourceA.io.req.fire()) {
    assert(sourceA.io.req.bits.source < UInt(InclusiveCacheParameters.out_mshrs(params.cache, params.micro)),
      "L2 MSHR acquire aliases checkpoint source")
  }
  when (io.out.a.fire() && (io.out.a.bits.opcode === TLMessages.PutFullData ||
        io.out.a.bits.opcode === TLMessages.PutPartialData)) {
    assert(preservation.io.a.fire() && CacheImage.safe(preservation.io.lock.bits.image, io.safeWatermark),
      "L2_SPEC_OUTER_WRITE_ERROR A source")
  }

  // SLOWDOWN_TRACE_BEGIN: observation-only; no functional consumers.
  val slowdown_scheduler_request_valid = chisel3.WireInit(request.valid)
  chisel3.dontTouch(slowdown_scheduler_request_valid)
  val slowdown_scheduler_request_ready = chisel3.WireInit(request.ready)
  chisel3.dontTouch(slowdown_scheduler_request_ready)
  val slowdown_scheduler_request_set = chisel3.WireInit(request.bits.set)
  chisel3.dontTouch(slowdown_scheduler_request_set)
  val slowdown_scheduler_request_tag = chisel3.WireInit(request.bits.tag)
  chisel3.dontTouch(slowdown_scheduler_request_tag)
  val slowdown_scheduler_request_source = chisel3.WireInit(request.bits.source)
  chisel3.dontTouch(slowdown_scheduler_request_source)
  val slowdown_scheduler_candidates = chisel3.WireInit(mshr_request)
  chisel3.dontTouch(slowdown_scheduler_candidates)
  val slowdown_scheduler_selected = chisel3.WireInit(mshr_selectOH)
  chisel3.dontTouch(slowdown_scheduler_selected)
  val slowdown_scheduler_set = chisel3.WireInit(scheduleSet)
  chisel3.dontTouch(slowdown_scheduler_set)
  val slowdown_scheduler_tag = chisel3.WireInit(scheduleTag)
  chisel3.dontTouch(slowdown_scheduler_tag)
  val slowdown_scheduler_set_matches = chisel3.WireInit(setMatches)
  chisel3.dontTouch(slowdown_scheduler_set_matches)
  val slowdown_scheduler_allocate = chisel3.WireInit(alloc)
  chisel3.dontTouch(slowdown_scheduler_allocate)
  val slowdown_scheduler_block_b = chisel3.WireInit(blockB)
  chisel3.dontTouch(slowdown_scheduler_block_b)
  val slowdown_scheduler_block_c = chisel3.WireInit(blockC)
  chisel3.dontTouch(slowdown_scheduler_block_c)
  val slowdown_validation_block = chisel3.WireInit(io.validationBlock)
  chisel3.dontTouch(slowdown_validation_block)
  val slowdown_client_validation_block = chisel3.WireInit(io.clientValidationBlock)
  chisel3.dontTouch(slowdown_client_validation_block)
  val slowdown_preservation_lock = chisel3.WireInit(io.preservationLock.valid)
  chisel3.dontTouch(slowdown_preservation_lock)
  val slowdown_preservation_txn = chisel3.WireInit(io.preservationTxn)
  chisel3.dontTouch(slowdown_preservation_txn)
  val slowdown_preservation_ack = chisel3.WireInit(io.preservationAck)
  chisel3.dontTouch(slowdown_preservation_ack)
  val slowdown_outer_a_valid = chisel3.WireInit(io.out.a.valid)
  chisel3.dontTouch(slowdown_outer_a_valid)
  val slowdown_outer_a_ready = chisel3.WireInit(io.out.a.ready)
  chisel3.dontTouch(slowdown_outer_a_ready)
  val slowdown_outer_a_opcode = chisel3.WireInit(io.out.a.bits.opcode)
  chisel3.dontTouch(slowdown_outer_a_opcode)
  val slowdown_outer_a_source = chisel3.WireInit(io.out.a.bits.source)
  chisel3.dontTouch(slowdown_outer_a_source)
  val slowdown_outer_a_size = chisel3.WireInit(io.out.a.bits.size)
  chisel3.dontTouch(slowdown_outer_a_size)
  val slowdown_outer_a_address = chisel3.WireInit(io.out.a.bits.address)
  chisel3.dontTouch(slowdown_outer_a_address)
  val slowdown_outer_c_valid = chisel3.WireInit(io.out.c.valid)
  chisel3.dontTouch(slowdown_outer_c_valid)
  val slowdown_outer_c_ready = chisel3.WireInit(io.out.c.ready)
  chisel3.dontTouch(slowdown_outer_c_ready)
  val slowdown_outer_c_opcode = chisel3.WireInit(io.out.c.bits.opcode)
  chisel3.dontTouch(slowdown_outer_c_opcode)
  val slowdown_outer_c_source = chisel3.WireInit(io.out.c.bits.source)
  chisel3.dontTouch(slowdown_outer_c_source)
  val slowdown_outer_c_size = chisel3.WireInit(io.out.c.bits.size)
  chisel3.dontTouch(slowdown_outer_c_size)
  val slowdown_outer_c_address = chisel3.WireInit(io.out.c.bits.address)
  chisel3.dontTouch(slowdown_outer_c_address)
  val slowdown_outer_d_valid = chisel3.WireInit(io.out.d.valid)
  chisel3.dontTouch(slowdown_outer_d_valid)
  val slowdown_outer_d_ready = chisel3.WireInit(io.out.d.ready)
  chisel3.dontTouch(slowdown_outer_d_ready)
  val slowdown_outer_d_opcode = chisel3.WireInit(io.out.d.bits.opcode)
  chisel3.dontTouch(slowdown_outer_d_opcode)
  val slowdown_outer_d_source = chisel3.WireInit(io.out.d.bits.source)
  chisel3.dontTouch(slowdown_outer_d_source)
  val slowdown_outer_d_size = chisel3.WireInit(io.out.d.bits.size)
  chisel3.dontTouch(slowdown_outer_d_size)
  val slowdown_scheduler_interlock = chisel3.WireInit(chisel3.VecInit(mshr_stall))
  chisel3.dontTouch(slowdown_scheduler_interlock)
  val slowdown_scheduler_stage3_allowed = chisel3.WireInit(chisel3.VecInit(stage3Allowed))
  chisel3.dontTouch(slowdown_scheduler_stage3_allowed)
  val slowdown_scheduler_park_ready = chisel3.WireInit(chisel3.VecInit(parkReady))
  chisel3.dontTouch(slowdown_scheduler_park_ready)
  val slowdown_scheduler_peer_block = chisel3.WireInit(chisel3.VecInit(peerResponseBlocked))
  chisel3.dontTouch(slowdown_scheduler_peer_block)
  val slowdown_scheduler_source_a_ready = chisel3.WireInit(sourceA.io.req.ready)
  chisel3.dontTouch(slowdown_scheduler_source_a_ready)
  val slowdown_scheduler_source_b_ready = chisel3.WireInit(sourceB.io.req.ready)
  chisel3.dontTouch(slowdown_scheduler_source_b_ready)
  val slowdown_scheduler_source_c_ready = chisel3.WireInit(sourceC.io.req.ready)
  chisel3.dontTouch(slowdown_scheduler_source_c_ready)
  val slowdown_scheduler_source_d_ready = chisel3.WireInit(sourceD.io.req.ready)
  chisel3.dontTouch(slowdown_scheduler_source_d_ready)
  val slowdown_scheduler_source_e_ready = chisel3.WireInit(sourceE.io.req.ready)
  chisel3.dontTouch(slowdown_scheduler_source_e_ready)
  val slowdown_scheduler_source_x_ready = chisel3.WireInit(sourceX.io.req.ready)
  chisel3.dontTouch(slowdown_scheduler_source_x_ready)
  val slowdown_scheduler_directory_ready = chisel3.WireInit(directory.io.write.ready)
  chisel3.dontTouch(slowdown_scheduler_directory_ready)
  // SLOWDOWN_TRACE_END
  private def afmt(x: AddressSet) = s"""{"base":${x.base},"mask":${x.mask}}"""
  private def addresses = params.inner.manager.managers.flatMap(_.address).map(afmt _).mkString(",")
  private def setBits = params.addressMapping.drop(params.offsetBits).take(params.setBits).mkString(",")
  private def tagBits = params.addressMapping.drop(params.offsetBits + params.setBits).take(params.tagBits).mkString(",")
  private def simple = s""""reset":"${reset.pathName}","tagBits":[${tagBits}],"setBits":[${setBits}],"blockBytes":${params.cache.blockBytes},"ways":${params.cache.ways}"""
  def json: String = s"""{"addresses":[${addresses}],${simple},"directory":${directory.json},"subbanks":${bankedStore.json}}"""
}
