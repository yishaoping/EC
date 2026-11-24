package palimpsesttest

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils
import chisel3.stage.ChiselStage
import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.tile.{TileKey, TileVisibilityNodeKey}
import freechips.rocketchip.subsystem.{TilesLocated, InSubsystem}
import freechips.rocketchip.tilelink._
import freechips.rocketchip.rocket.constants.MemoryOpConstants
import freechips.rocketchip.guardiancouncil.GH_GlobalParams
import boom.common.BoomTileAttachParams
import boom.lsu.BoomNonBlockingDCache
import boom.exu._
import sifive.blocks.inclusivecache._

/** P5-05/06/08: real L1 + InclusiveCache (including production CDC
  * mailboxes/history/preservation) + CacheCork. Only terminal memory and
  * architectural requests are supplied by the host. No fake archive ACK.
  * This is a memory-hierarchy test, not a BOOM architectural execution test.
  */
object EmitHierarchy extends App {
  implicit val p: Parameters = (new chipyard.v1Config).alterPartial {
    case PalimpsestSeqRebaseThreshold => BigInt(0)
  }
  val tile = p(TilesLocated(InSubsystem)).collectFirst {
    case t: BoomTileAttachParams => t.tileParams
  }.get
  class Harness extends LazyModule {
    val visibility = TLIdentityNode()
    val cacheParams = p.alterPartial {
      case TileKey => tile
      case TileVisibilityNodeKey => visibility
    }
    val l1 = LazyModule(new BoomNonBlockingDCache(tile.hartId)(cacheParams))
    val l2 = LazyModule(new InclusiveCache(CacheParameters(2, 4, 64, 64, 16, false),
      InclusiveCacheMicroParameters(8, memCycles = 8,
        innerBuf = InclusiveCachePortParameters.fullC)))
    val cork = LazyModule(new TLCacheCork)
    val host = TLClientNode(Seq(TLClientPortParameters(Seq(TLClientParameters(
      name = "trusted-host", sourceId = IdRange(0, 1))))))
    val clients = LazyModule(new TLXbar)
    val grantGate = TLAdapterNode(clientFn = { x => x }, managerFn = { x => x })
    val memory = TLManagerNode(Seq(TLManagerPortParameters(Seq(TLManagerParameters(
      address = Seq(AddressSet(BigInt("80000000", 16), BigInt("0fffffff", 16))),
      regionType = RegionType.UNCACHED,
      supportsGet = TransferSizes(1, 64), supportsPutFull = TransferSizes(1, 64),
      supportsPutPartial = TransferSizes(1, 64))), beatBytes = 16)))
    memory := cork.node := l2.node := clients.node
    clients.node := visibility := grantGate := l1.node
    clients.node := host
    lazy val module = new LazyModuleImp(this) with MemoryOpConstants {
      override def desiredName = "HierarchyHarness"
      val io = IO(new Bundle {
        val req = Input(Bool()); val ready = Output(Bool())
        val address = Input(UInt(40.W)); val data = Input(UInt(64.W))
        val command = Input(UInt(5.W)); val seq = Input(UInt(32.W)); val token = Input(UInt(64.W))
        val size = Input(UInt(2.W)); val doneData = Output(UInt(64.W))
        val doneReady = Input(Bool()); val done = Output(Bool())
        val doneToken = Output(UInt(64.W)); val doneStatus = Output(UInt(3.W))
        val response = Output(Bool()); val responseData = Output(UInt(64.W)); val nack = Output(Bool())
        val allocate = Input(UInt(32.W)); val pass = Input(UInt(32.W)); val fail = Input(UInt(32.W))
        val safe = Output(UInt(32.W)); val ordered = Output(Bool())
        val stop = Output(Bool()); val fatal = Output(Bool()); val epoch = Output(UInt(32.W))
        val restartReady = Input(Bool()); val restart = Output(Bool()); val restoredSeq = Output(UInt(32.W))
        val archiveReceipts = Output(UInt(32.W)); val selectedSeq = Output(UInt(32.W))
        val selectedData = Output(UInt(64.W)); val lookupFound = Output(Bool())
        val maintenanceRequest = Output(Bool()); val maintenanceAck = Output(Bool())
        val checkerClocks = Input(UInt(4.W))
        val historyRequest = Output(Bool()); val checkerHistoryAcks = Output(UInt(4.W))
        val checkerDead8 = Output(UInt(4.W))
        val hostReq = Input(Bool()); val hostWrite = Input(Bool())
        val hostAddress = Input(UInt(40.W)); val hostData = Input(UInt(64.W))
        val hostReady = Output(Bool()); val hostDone = Output(Bool())
        val hostResult = Output(UInt(64.W))
        val holdInnerGrant = Input(Bool()); val innerGrantPending = Output(Bool())
        val mv = Output(Bool()); val mr = Input(Bool()); val ma = Output(UInt(40.W)); val mo = Output(UInt(3.W))
        val ms = Output(UInt(8.W)); val mt = Output(UInt(64.W)); val ml = Output(UInt(64.W)); val mh = Output(UInt(64.W))
        val rv = Input(Bool()); val rr = Output(Bool()); val ro = Input(UInt(3.W)); val rs = Input(UInt(8.W))
        val rt = Input(UInt(64.W)); val rl = Input(UInt(64.W)); val rh = Input(UInt(64.W))
      })
      val dut = l1.module
      val (gateIn, _) = grantGate.in.head
      val (gateOut, _) = grantGate.out.head
      gateOut <> gateIn
      gateIn.d.valid := gateOut.d.valid && !io.holdInnerGrant
      gateOut.d.ready := gateIn.d.ready && !io.holdInnerGrant
      io.innerGrantPending := gateOut.d.valid
      // A separate lineage-unaware TL client exercises coherent host/HTIF
      // reads and writes while the production L1 cold lookup owns a result.
      val (h, he) = host.out.head
      h.a.valid := io.hostReq
      h.a.bits := Mux(io.hostWrite,
        CacheImage.base(he.Put(0.U, io.hostAddress, 3.U, Fill(he.bundle.dataBits / 64, io.hostData))._2),
        CacheImage.base(he.Get(0.U, io.hostAddress, 3.U)._2))
      io.hostReady := h.a.ready
      h.d.ready := true.B
      io.hostDone := h.d.fire
      io.hostResult := (h.d.bits.data >> (io.hostAddress(log2Ceil(he.manager.beatBytes)-1, 3) << 6))(63, 0)
      when (h.d.fire) { assert(!h.d.bits.denied && !h.d.bits.corrupt, "trusted host response failed") }
      h.b.ready := true.B
      h.c.valid := false.B; h.c.bits := 0.U.asTypeOf(h.c.bits)
      h.e.valid := false.B; h.e.bits := 0.U.asTypeOf(h.e.bits)
      dut.io.allCheckersDrained := true.B // host fixture has no Checker/CDC sources
      dut.io.rollbackRebase := false.B
      // The actual Rocket context receiver, with independently driven slow
      // clocks. Package execution/results remain host stimulus in this fixture.
      val historyRequest = WireDefault(false.B)
      val historyPayload = WireDefault(0.U.asTypeOf(new PalimpsestHistoryQuery))
      BoringUtils.addSink(historyRequest, "PALIMPSEST_HISTORY_REQUEST")
      BoringUtils.addSink(historyPayload, "PALIMPSEST_HISTORY_PAYLOAD")
      val checkerReceivers = (0 until 4).map { i =>
        val receiver = withClockAndReset(io.checkerClocks(i).asClock, reset.asAsyncReset) {
          Module(new PalimpsestHistoryReceiver)
        }
        receiver.io.request := historyRequest
        receiver.io.payload := historyPayload
        // Name the particular instance's ACK in the parent. Attaching the
        // source to a deduplicated receiver port is ambiguous with four sinks.
        val ack = WireInit(receiver.io.ack)
        BoringUtils.addSource(ack,
          s"PALIMPSEST_CHECKER_HISTORY_ACK_${i + GH_GlobalParams.GH_NUM_BIG_CORES}")
        receiver
      }
      io.historyRequest := historyRequest
      io.checkerHistoryAcks := VecInit(checkerReceivers.map(_.io.ack)).asUInt
      io.checkerDead8 := VecInit(checkerReceivers.map(r => !r.io.context.survives(8.U))).asUInt
      val maintenanceRequest = WireDefault(false.B)
      val maintenanceAck = WireDefault(false.B)
      BoringUtils.addSink(maintenanceRequest, "PALIMPSEST_EVT_MAINTENANCE_REQUEST")
      BoringUtils.addSink(maintenanceAck, "PALIMPSEST_EVT_MAINTENANCE_ACK_0")
      io.maintenanceRequest := maintenanceRequest
      io.maintenanceAck := maintenanceAck
      val ctrl = Module(new PalimpsestRollbackController)
      val cp = Module(new PalimpsestContextMemory(64, 40, 64))
      cp.io.capture.valid := io.allocate =/= 0.U
      cp.io.capture.bits := 0.U.asTypeOf(chiselTypeOf(cp.io.capture.bits))
      cp.io.capture.bits.seq := io.allocate
      cp.io.capture.bits.epoch := dut.io.rollbackEpoch
      cp.io.capture.bits.pc := 0x80000000L.U + (io.allocate << 2)
      when (cp.io.capture.valid) { assert(cp.io.capture.ready, "hierarchy stimulus exhausted SCP RAM") }
      cp.io.read <> ctrl.io.checkpoint
      cp.io.response.ready := ctrl.io.restart.fire
      cp.io.safeWatermark := dut.io.rollbackSafe
      cp.io.discard.valid := ctrl.io.restart.fire; cp.io.discard.bits := ctrl.io.target
      cp.io.abort := ctrl.io.abandonCheckpoint
      ctrl.io.error <> dut.io.rollbackError
      ctrl.io.checkpointReady := cp.io.response.valid; ctrl.io.checkpointMissing := cp.io.missing
      ctrl.io.quiesced := dut.io.rollbackQuiesced
      ctrl.io.commitHistory <> dut.io.rollbackHistory
      ctrl.io.historyUnavailable := dut.io.rollbackHistoryUnavailable
      ctrl.io.identityUnavailable := dut.io.rollbackIdentityUnavailable
      ctrl.io.restored := RegNext(ctrl.io.restore, false.B)
      ctrl.io.restart.ready := io.restartReady && dut.io.rollbackMemoryReady
      dut.io.rollbackStop := ctrl.io.stop; dut.io.rollbackTarget := ctrl.io.target
      dut.io.rollbackReset := ctrl.io.restore && !RegNext(ctrl.io.restore, false.B)
      io.stop := ctrl.io.stop; io.fatal := ctrl.io.fatal; io.restart := ctrl.io.restart.fire
      io.restoredSeq := cp.io.response.bits.seq; io.epoch := dut.io.rollbackEpoch
      io.safe := dut.io.rollbackSafe; io.ordered := dut.io.lsu.ordered
      dut.io.traffic_check_state := false.B
      dut.io.traffic_reset := false.B; dut.io.traffic_start := false.B; dut.io.traffic_stop := false.B
      val cycle = RegInit(0.U(64.W)); cycle := cycle + 1.U; dut.io.csr_cycle := cycle
      dut.io.packet_alloc_valid := io.allocate =/= 0.U; dut.io.packet_alloc_seq := io.allocate
      dut.io.packet_seq_baseline := io.seq
      dut.io.checker_results := 0.U.asTypeOf(chiselTypeOf(dut.io.checker_results))
      dut.io.checker_results(0) := Cat(io.pass =/= 0.U || io.fail =/= 0.U,
        Mux(io.fail =/= 0.U, GH_GlobalParams.GH_CHECKER_STATUS_FAIL.U(2.W),
          GH_GlobalParams.GH_CHECKER_STATUS_PASS.U(2.W)), Mux(io.fail =/= 0.U, io.fail, io.pass))
      dut.io.lsu.req.valid := io.req; io.ready := dut.io.lsu.req.ready
      dut.io.lsu.req.bits := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.req.bits))
      val r = dut.io.lsu.req.bits(0)
      r.valid := true.B; r.bits.addr := io.address; r.bits.data := io.data
      r.bits.uop.mem_cmd := io.command; r.bits.uop.mem_size := io.size; r.bits.uop.mem_signed := true.B
      r.bits.uop.uses_stq := isWrite(io.command); r.bits.uop.uses_ldq := !isWrite(io.command)
      r.bits.uop.is_amo := isAMO(io.command)
      r.bits.packet_seq := io.seq
      r.bits.request_token_valid := true.B; r.bits.request_token := io.token
      r.bits.effect_token_valid := isWrite(io.command); r.bits.effect_token := io.token
      r.bits.write_domain_valid := isWrite(io.command); r.bits.write_domain_seq := io.seq
      dut.io.lsu.s1_kill := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.s1_kill))
      dut.io.lsu.brupdate.b1 := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.brupdate.b1))
      dut.io.lsu.brupdate.b2.elements.filterNot(_._1 == "target_offset").foreach { case (_, d) =>
        d := 0.U.asTypeOf(chiselTypeOf(d))
      }
      dut.io.lsu.brupdate.b2.target_offset := 0.S(21.W)
      dut.io.lsu.exception := false.B; dut.io.lsu.rob_pnr_idx := 0.U; dut.io.lsu.rob_head_idx := 0.U
      dut.io.lsu.force_order := false.B
      dut.io.lsu.release.ready := true.B; dut.io.lsu.store_done.ready := io.doneReady
      dut.io.lsu.traffic_lr_complete := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.traffic_lr_complete))
      dut.io.lsu.traffic_sc_success_complete := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.traffic_sc_success_complete))
      dut.io.lsu.traffic_sc_fail_complete := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.traffic_sc_fail_complete))
      dut.io.lsu.traffic_amo_cache_complete := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.traffic_amo_cache_complete))
      dut.io.lsu.traffic_amo_uncache_complete := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.traffic_amo_uncache_complete))
      dut.io.lsu.traffic_arch_counter := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.traffic_arch_counter))
      dut.io.lsu.address_stats_event := 0.U.asTypeOf(chiselTypeOf(dut.io.lsu.address_stats_event))
      io.done := dut.io.lsu.store_done.fire; io.doneToken := dut.io.lsu.store_done.bits.req.request_token
      io.doneStatus := dut.io.lsu.store_done.bits.status
      io.doneData := dut.io.lsu.store_done.bits.data
      io.nack := dut.io.lsu.nack(0).valid
      io.response := dut.io.lsu.resp(0).valid; io.responseData := dut.io.lsu.resp(0).bits.data

      // Core-owned control inputs remain explicit host responsibilities. A
      // close ACK is never synthesized merely because a request is visible.
      val closeAck = WireDefault(false.B); val closeSeq = WireDefault(0.U(32.W))
      BoringUtils.addSource(closeAck, s"${GH_GlobalParams.GH_L2_BARRIER_CLOSE_ACK_BORE}_0")
      BoringUtils.addSource(closeSeq, s"${GH_GlobalParams.GH_L2_BARRIER_CLOSE_ACK_SEQ_BORE}_0")
      val watchdog = WireDefault(false.B)
      BoringUtils.addSource(watchdog, "EC_PIPELINE_WATCHDOG_SNAPSHOT")
      def observe(name: String, bits: Int): Unit = {
        val value = WireDefault(0.U(bits.W)); BoringUtils.addSink(value, name); dontTouch(value)
      }
      for (i <- 0 until 28) { observe(s"stage1_cache_${tile.hartId}_$i", 64) }
      observe(s"${GH_GlobalParams.GH_L2_BARRIER_REQUEST_BORE}_0", 1)
      observe(s"${GH_GlobalParams.GH_L2_BARRIER_REQUEST_SEQ_BORE}_0", 32)
      observe(s"${GH_GlobalParams.GH_L2_BARRIER_ERROR_BORE}_0", 1)
      observe(s"${GH_GlobalParams.GH_L2_WB_CLEAN_GRAY_BORE}_0", 64)
      observe(s"${GH_GlobalParams.GH_L2_WB_DIRTY_GRAY_BORE}_0", 64)
      for (i <- 0 until 10) { observe(s"${GH_GlobalParams.GH_L2_DRAM_STATS_BORE}_${i}_0", 64) }
      for (i <- 0 until 7) { observe(s"${GH_GlobalParams.GH_L2_DRAM_BARRIER_STATS_BORE}_${i}_0", 64) }
      val archiveAck = WireDefault(false.B)
      BoringUtils.addSink(archiveAck, "PALIMPSEST_ARCHIVE_ACK")
      val receipts = RegInit(0.U(32.W))
      when (archiveAck && !RegNext(archiveAck, false.B)) { receipts := receipts + 1.U }
      io.archiveReceipts := receipts
      val lookup = WireDefault(0.U.asTypeOf(new PalimpsestHistoryResult))
      BoringUtils.addSink(lookup, "PALIMPSEST_HISTORY_RESULT_0")
      io.selectedSeq := lookup.line.key.contentSeq; io.selectedData := lookup.line.data(63, 0)
      io.lookupFound := lookup.found

      val m = memory.in.head._1
      require(m.params.dataBits == 128 && m.params.addressBits <= 40 && m.params.sourceBits <= 8)
      io.mv := m.a.valid; m.a.ready := io.mr; io.ma := m.a.bits.address; io.mo := m.a.bits.opcode
      io.ms := m.a.bits.source; io.mt := m.a.bits.echo(CachePreserveTxn)
      io.ml := m.a.bits.data(63, 0); io.mh := m.a.bits.data(127, 64)
      m.d.valid := io.rv; m.d.bits := 0.U.asTypeOf(chiselTypeOf(m.d.bits)); io.rr := m.d.ready
      m.d.bits.opcode := io.ro; m.d.bits.source := io.rs; m.d.bits.size := 6.U
      m.d.bits.echo(CachePreserveTxn) := io.rt; m.d.bits.data := Cat(io.rh, io.rl)
      m.b.valid := false.B; m.b.bits := 0.U.asTypeOf(chiselTypeOf(m.b.bits))
      m.c.ready := true.B; m.e.ready := true.B
    }
  }
  require(args.length == 1)
  (new ChiselStage).emitVerilog(LazyModule(new Harness).module, Array("--target-dir", args(0)))
}
