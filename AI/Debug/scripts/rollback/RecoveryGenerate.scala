package palimpsesttest

import chisel3._
import chisel3.util._
import chisel3.stage.ChiselStage
import boom.exu._
import freechips.rocketchip.tilelink._
import freechips.rocketchip.r._
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.tile.{TileKey, TileVisibilityNodeKey}
import freechips.rocketchip.subsystem.{TilesLocated, InSubsystem}
import org.chipsalliance.cde.config.Parameters
import chisel3.experimental.DataMirror

/** P5-02..07/P5-09: actual controller, SCP RAM, EVT and L2 archive.
  * This fixture is a component join. It does not substitute for a real-cache
  * or full BOOM architectural restore test. All stimulus comes from C++.
  */
class RecoveryHarness extends Module {
  val io = IO(new Bundle {
    val allocate = Input(UInt(32.W))
    val safe = Input(UInt(32.W))
    val captureCP = Input(Bool())
    val cpSeq = Input(UInt(32.W))
    val cpPC = Input(UInt(40.W))
    val cpInt = Input(UInt(64.W))
    val cpFP = Input(UInt(64.W))
    val cpCSR = Input(UInt(64.W))
    val cpReady = Output(Bool())
    val cpOccupancy = Output(UInt(3.W))
    val fail = Input(UInt(32.W))
    val failReady = Output(Bool())
    val identityUnavailable = Input(Bool())
    val compact = Input(Bool()) // isolated EVT component test; no physical ACK claim
    val quiesced = Input(Bool())
    val restartReady = Input(Bool())
    val stop = Output(Bool())
    val restore = Output(Bool())
    val restart = Output(Bool())
    val fatal = Output(Bool())
    val target = Output(UInt(32.W))
    val pc = Output(UInt(40.W))
    val integer = Output(UInt(64.W))
    val floating = Output(UInt(64.W))
    val csr = Output(UInt(64.W))
    val epoch = Output(UInt(32.W))
    val generation = Output(UInt(32.W))
    val archive = Input(Bool())
    val escape = Input(Bool())
    val archiveReady = Output(Bool())
    val address = Input(UInt(64.W))
    val seq = Input(UInt(32.W))
    val serial = Input(UInt(32.W))
    val value = Input(UInt(64.W))
    val query = Input(Bool())
    val queryReady = Output(Bool())
    val responseReady = Input(Bool())
    val response = Output(Bool())
    val found = Output(Bool())
    val selected = Output(UInt(32.W))
    val data = Output(UInt(64.W))
    val publishReady = Input(Bool())
    val publish = Output(Bool())
    val publishSeq = Output(UInt(32.W))
    val publishAck = Input(Bool())
    val pressure = Output(Bool())
  })
  val evt = Module(new PalimpsestExecutionHistory(32, 1))
  evt.io.compact := io.compact
  val cp = Module(new PalimpsestContextMemory(64, 40, 64, 4))
  val ctrl = Module(new PalimpsestRollbackController)
  val history = Module(new PalimpsestVersionHistory(8, 4))
  history.io.captureEscape := io.escape
  evt.io.allocated.valid := io.allocate =/= 0.U
  evt.io.allocated.bits := io.allocate
  evt.io.query(0) := io.seq
  cp.io.capture.valid := io.captureCP
  cp.io.capture.bits := 0.U.asTypeOf(chiselTypeOf(cp.io.capture.bits))
  cp.io.capture.bits.seq := io.cpSeq
  cp.io.capture.bits.epoch := evt.io.epoch
  cp.io.capture.bits.pc := io.cpPC
  cp.io.capture.bits.integer := VecInit(Seq.fill(32)(io.cpInt))
  cp.io.capture.bits.integer(0) := 0.U
  cp.io.capture.bits.floating := VecInit(Seq.fill(32)(io.cpFP))
  cp.io.capture.bits.csr := io.cpCSR
  cp.io.safeWatermark := io.safe
  cp.io.discard.valid := ctrl.io.restart.fire
  cp.io.discard.bits := ctrl.io.target
  cp.io.read <> ctrl.io.checkpoint
  cp.io.response.ready := ctrl.io.restart.fire
  cp.io.abort := ctrl.io.abandonCheckpoint
  ctrl.io.error.valid := io.fail =/= 0.U
  ctrl.io.error.bits.seq := io.fail
  ctrl.io.error.bits.cancelled := false.B
  ctrl.io.checkpointReady := cp.io.response.valid
  ctrl.io.checkpointMissing := cp.io.missing
  ctrl.io.quiesced := io.quiesced
  evt.io.rollback <> ctrl.io.commitHistory
  ctrl.io.historyUnavailable := evt.io.full
  ctrl.io.identityUnavailable := io.identityUnavailable
  ctrl.io.restored := RegNext(ctrl.io.restore, false.B)
  ctrl.io.restart.ready := io.restartReady
  io.cpReady := cp.io.capture.ready
  io.cpOccupancy := cp.io.occupancy
  io.failReady := ctrl.io.error.ready
  io.stop := ctrl.io.stop
  io.restore := ctrl.io.restore
  io.restart := ctrl.io.restart.fire
  io.fatal := ctrl.io.fatal
  io.target := ctrl.io.target
  io.pc := cp.io.response.bits.pc
  io.integer := cp.io.response.bits.integer(1)
  io.floating := cp.io.response.bits.floating(0)
  io.csr := cp.io.response.bits.csr
  io.epoch := evt.io.epoch
  io.generation := evt.io.generation
  history.io.context := 0.U.asTypeOf(new PalimpsestHistoryQuery)
  history.io.context.occupied := evt.io.occupied
  history.io.context.lower := evt.io.lower
  history.io.context.upper := evt.io.upper
  history.io.capture.valid := io.archive
  history.io.capture.bits.address := io.address
  history.io.capture.bits.key.valid := true.B
  history.io.capture.bits.key.writer := 0.U
  history.io.capture.bits.key.contentSeq := io.seq
  history.io.capture.bits.key.generation := io.serial
  history.io.capture.bits.data := Fill(8, io.value)
  history.io.watermark := io.safe
  history.io.query.valid := io.query
  history.io.query.bits := history.io.context
  history.io.query.bits.address := io.address
  history.io.result.ready := io.responseReady
  io.archiveReady := history.io.capture.ready
  io.queryReady := history.io.query.ready
  io.response := history.io.result.valid
  io.found := history.io.result.bits.found
  io.selected := history.io.result.bits.line.key.contentSeq
  io.data := history.io.result.bits.line.data(63, 0)
  history.io.publish.ready := io.publishReady
  val ackKey = RegEnable(history.io.publish.bits.key, history.io.publish.fire)
  history.io.published.valid := io.publishAck
  history.io.published.bits := ackKey
  io.publish := history.io.publish.valid
  io.publishSeq := history.io.publish.bits.key.contentSeq
  io.pressure := history.io.pressure
  when (ctrl.io.restore) { assert(io.quiesced, "restore before drain") }
  when (ctrl.io.restart.fire) { assert(cp.io.response.bits.seq === ctrl.io.target) }
}

/** P5-01/P1-01: actual R_RSUSL, including SyncReadMem comparison pipeline. */
class F0Harness(faultSeq: BigInt = 0, extraFaultSeqs: Seq[BigInt] = Seq.empty) extends Module {
  val io = IO(new Bundle {
    val start = Input(Bool())
    val seq = Input(UInt(32.W))
    val clear = Input(Bool())
    val beat = Input(Bool())
    val index = Input(UInt(7.W))
    val mainInt = Input(UInt(64.W))
    val mainFP = Input(UInt(64.W))
    val checkerF0 = Input(UInt(64.W))
    val compare = Input(Bool())
    val ack = Input(Bool())
    val complete = Output(Bool())
    val done = Output(Bool())
    val error = Output(Bool())
  })
  val rsu = Module(new R_RSUSL(R_RSUSLParams(64, 32, faultSeq, extraFaultSeqs)))
  rsu.io.rf_wen := false.B; rsu.io.rf_waddr := 0.U; rsu.io.rf_wdata := 0.U
  rsu.io.checker_mode := true.B
  rsu.io.check_priv := 0.U; rsu.io.excpt := false.B; rsu.io.eret := false.B
  rsu.io.check_done := 0.U
  rsu.io.arfs_merge := Cat(io.mainFP, io.mainInt)
  rsu.io.arfs_index := io.index; rsu.io.arfs_if_ARFS := io.beat.asUInt
  rsu.io.arfs_if_CPS := 0.U; rsu.io.paste_arfs := 0.U; rsu.io.clear_ic_status := 0.U
  rsu.io.package_start := io.start; rsu.io.package_clear := io.clear
  rsu.io.package_seq := io.seq; rsu.io.arfs_seq := io.seq
  rsu.io.compare_start := io.compare; rsu.io.compare_abort := false.B
  rsu.io.compare_done_ack := io.ack
  rsu.io.core_arfs_in := VecInit(Seq.fill(32)(0.U(64.W)))
  rsu.io.core_arfs_in(0) := "hffffffffffffffff".U // x0 must normalize
  rsu.io.core_farfs_in := VecInit(Seq.fill(32)(0.U(64.W)))
  rsu.io.core_farfs_in(0) := io.checkerF0
  rsu.io.elu_cp_deq := 1.U; rsu.io.core_trace := 0.U
  rsu.io.record_context := 0.U; rsu.io.store_from_checker := 0.U; rsu.io.core_id := 1.U
  io.complete := rsu.io.ecp_complete
  io.done := rsu.io.compare_done
  io.error := rsu.io.compare_done_error
}

object EmitRecovery extends App {
  require(args.length == 1, "target directory required")
  (new ChiselStage).emitVerilog(new RecoveryHarness, Array("--target-dir", args(0)))
}
object EmitF0 extends App {
  require(args.length == 1, "target directory required")
  (new ChiselStage).emitVerilog(new F0Harness, Array("--target-dir", args(0)))
}
class FaultInjectionHarness extends F0Harness(8, Seq(BigInt(24)))
object EmitFaultInjection extends App {
  require(args.length == 1, "target directory required")
  (new ChiselStage).emitVerilog(new FaultInjectionHarness,
    Array("--target-dir", args(0)))
}

/** Negotiate the same Tile visibility parameter standalone BOOM modules
  * normally obtain from their Tile. The DUT's traffic remains host-driven.
  */
class RecoveryFixtureBus(coherent: Boolean, transferBytes: Int = 16)(implicit p: Parameters) extends LazyModule {
  val tile = p(TilesLocated(InSubsystem)).collectFirst {
    case t: boom.common.BoomTileAttachParams => t.tileParams
  }.get
  val client = TLClientNode(Seq(TLClientPortParameters(Seq(TLClientParameters(
    name = "fixture", sourceId = IdRange(0, 1),
    supportsProbe = if (coherent) TransferSizes(64, 64) else TransferSizes.none)))))
  val visibility = TLIdentityNode()
  val manager = TLManagerNode(Seq(TLManagerPortParameters(Seq(TLManagerParameters(
    address = Seq(AddressSet(BigInt("80000000", 16), BigInt("0fffffff", 16))),
    regionType = if (coherent) RegionType.CACHED else RegionType.UNCACHED,
    supportsAcquireB = if (coherent) TransferSizes(64, 64) else TransferSizes.none,
    supportsAcquireT = if (coherent) TransferSizes(64, 64) else TransferSizes.none,
    supportsGet = TransferSizes(1, transferBytes), supportsPutFull = TransferSizes(1, transferBytes),
    supportsPutPartial = TransferSizes(1, transferBytes), supportsArithmetic = TransferSizes(4, 8),
    supportsLogical = TransferSizes(4, 8))), beatBytes = 16,
    endSinkId = if (coherent) 1 else 0)))
  manager := visibility := client
  val tileParams = p.alterPartial {
    case TileKey => tile
    case TileVisibilityNodeKey => visibility
  }
  def tieOffFixtureBus(): Unit = {
    val out = client.out.head._1
    val in = manager.in.head._1
    out.a.valid := false.B; out.a.bits := DontCare; out.d.ready := true.B
    in.a.ready := false.B; in.d.valid := false.B; in.d.bits := DontCare
    out.c.valid := false.B; out.c.bits := DontCare; out.e.valid := false.B; out.e.bits := DontCare
    out.b.ready := true.B
    in.c.ready := false.B; in.e.ready := false.B; in.b.valid := false.B; in.b.bits := DontCare
  }
  lazy val module: LazyModuleImp = new LazyModuleImp(this) { tieOffFixtureBus() }
}

/** P5-01/P5-02/P5-05/P5-09: actual production SVB, including WB_WAIT.
  * Lower archive receipt is host-controlled; this is not a cache hierarchy.
  */
class SvbTestDut(implicit p: Parameters, edge: TLEdgeOut) extends Module {
  val io = IO(new Bundle {
    val capture = Input(Bool()); val ready = Output(Bool())
    val address = Input(UInt(40.W)); val seq = Input(UInt(32.W))
    val serial = Input(UInt(32.W)); val value = Input(UInt(64.W))
    val safe = Input(UInt(32.W)); val firstDead = Input(UInt(32.W))
    val invalidate = Input(Bool()); val query = Input(Bool())
    val queryReady = Output(Bool()); val responseReady = Input(Bool())
    val response = Output(Bool()); val found = Output(Bool())
    val selected = Output(UInt(32.W)); val selectedSerial = Output(UInt(32.W))
    val data = Output(UInt(64.W)); val archiveReady = Input(Bool())
    val archive = Output(Bool()); val archiveSeq = Output(UInt(32.W))
    val ack = Input(Bool()); val occupancy = Output(UInt(3.W))
    val releaseBlocked = Output(Bool())
  })
  val svb = Module(new boom.lsu.SpeculativeVersionBuffer(4))
  require(svb.encRowBits % 64 == 0)
  svb.io.capture.valid := io.capture
  svb.io.capture.bits := 0.U.asTypeOf(chiselTypeOf(svb.io.capture.bits))
  svb.io.capture.bits.line := io.address
  svb.io.capture.bits.key.valid := true.B
  svb.io.capture.bits.key.contentSeq := io.seq
  svb.io.capture.bits.key.generation := io.serial
  svb.io.capture.bits.data := VecInit(Seq.fill(svb.refillCycles)(Fill(svb.encRowBits / 64, io.value)))
  svb.io.safeWatermark := io.safe
  for (i <- 0 until 4) {
    svb.io.historyValid(i) := io.firstDead === 0.U || svb.io.entrySeq(i) < io.firstDead
  }
  svb.io.currentEpoch := 0.U
  svb.io.diagnosticDump := false.B; svb.io.diagnosticCycle := 0.U
  svb.io.resetStats := false.B; svb.io.countStats := true.B
  svb.io.flush := false.B
  svb.io.invalidate.valid := io.invalidate
  svb.io.invalidate.bits := io.firstDead - 1.U
  svb.io.query.valid := io.query; svb.io.query.bits := io.address
  svb.io.recovered.ready := io.responseReady
  svb.io.promote.ready := io.archiveReady
  val ackEntry = RegEnable(svb.io.promote.bits.entry, svb.io.promote.fire)
  val ackKey = RegEnable(svb.io.promote.bits.key, svb.io.promote.fire)
  svb.io.ack.valid := io.ack
  svb.io.ack.bits.entry := ackEntry; svb.io.ack.bits.key := ackKey
  svb.io.releaseLines := VecInit(Seq.fill(4)(io.address))
  io.ready := svb.io.capture.ready; io.queryReady := svb.io.query.ready
  io.response := svb.io.recovered.valid; io.found := svb.io.recoveredFound
  io.selected := svb.io.recovered.bits.key.contentSeq
  io.selectedSerial := svb.io.recovered.bits.key.generation
  io.data := svb.io.recovered.bits.data(0)(63, 0)
  io.archive := svb.io.promote.valid; io.archiveSeq := svb.io.promote.bits.key.contentSeq
  io.occupancy := svb.io.occupancy; io.releaseBlocked := svb.io.releaseBlocked(0)
}
object EmitSvb extends App {
  require(args.length == 1)
  implicit val p: Parameters = new chipyard.v1Config
  val bus = LazyModule(new RecoveryFixtureBus(true) {
    override lazy val module: LazyModuleImp = new LazyModuleImp(this) {
      override def desiredName = "SvbHarness"
      tieOffFixtureBus()
      val dut = Module(new SvbTestDut()(tileParams, client.edges.out.head))
      val io = IO(chiselTypeOf(dut.io))
      io <> dut.io
    }
  })
  (new ChiselStage).emitVerilog(bus.module, Array("--target-dir", args(0)))
}

/** P3-15/P4-06/P5-09: production transaction-label allocator at a small
  * cyclic boundary. Callers retire each owner before reusing its labels.
  */
class IdentityHarness extends Module {
  val io = IO(new Bundle {
    val consume = Input(UInt(2.W))
    val next = Output(UInt(4.W))
    val available = Output(Bool())
    val stop = Output(Bool())
    val fatal = Output(Bool())
    val restart = Output(Bool())
  })
  val tokens = Module(new PalimpsestIdentityAllocator(4, 3))
  val ctrl = Module(new PalimpsestRollbackController)
  tokens.io.consume := io.consume
  io.next := tokens.io.next; io.available := tokens.io.available
  ctrl.io.error.valid := false.B
  ctrl.io.error.bits := 0.U.asTypeOf(new PalimpsestError)
  ctrl.io.checkpoint.ready := true.B
  ctrl.io.checkpointReady := true.B
  ctrl.io.checkpointMissing := false.B
  ctrl.io.quiesced := true.B
  ctrl.io.commitHistory.ready := true.B
  ctrl.io.historyUnavailable := false.B
  ctrl.io.identityUnavailable := !tokens.io.available
  ctrl.io.restored := true.B; ctrl.io.restart.ready := true.B
  io.stop := ctrl.io.stop; io.fatal := ctrl.io.fatal
  io.restart := ctrl.io.restart.fire
}
object EmitIdentity extends App {
  require(args.length == 1)
  (new ChiselStage).emitVerilog(new IdentityHarness, Array("--target-dir", args(0)))
}

/** P2-06/P5-03: production sequential PRF import, including all x/f slots. */
class RestoreTestDut(implicit p: Parameters) extends Module {
  val io = IO(new Bundle {
    val restore = Input(Bool())
    val seed = Input(UInt(64.W))
    val address = Input(UInt(6.W))
    val done = Output(Bool())
    val data = Output(UInt(64.W))
    val fpData = Output(UInt(64.W))
  })
  val rf = Module(new RegisterFileSynthesizable(64, 1, 1, 64, Seq(false), true))
  val fp = Module(new RegisterFileSynthesizable(64, 1, 1, 65, Seq(false), true))
  rf.io.write_ports(0).valid := false.B
  rf.io.write_ports(0).bits := 0.U.asTypeOf(chiselTypeOf(rf.io.write_ports(0).bits))
  rf.io.read_ports(0).addr := io.address
  fp.io.write_ports(0).valid := false.B
  fp.io.write_ports(0).bits := 0.U.asTypeOf(chiselTypeOf(fp.io.write_ports(0).bits))
  fp.io.read_ports(0).addr := io.address
  rf.restore.get.valid := io.restore
  fp.restore.get.valid := io.restore
  for (i <- 0 until 32) {
    val ieee = io.seed ^ (i * 0x101L).U
    rf.restore.get.bits(i) := ieee
    fp.restore.get.bits(i) := hardfloat.recFNFromFN(11, 53, ieee)
  }
  io.done := rf.restoreDone.get && fp.restoreDone.get
  io.data := rf.io.read_ports(0).data
  io.fpData := hardfloat.fNFromRecFN(11, 53, fp.io.read_ports(0).data)
}
object EmitRestore extends App {
  require(args.length == 1)
  implicit val p: Parameters = new chipyard.v1Config
  val bus = LazyModule(new RecoveryFixtureBus(false) {
    override lazy val module: LazyModuleImp = new LazyModuleImp(this) {
      override def desiredName = "RestoreHarness"
      tieOffFixtureBus()
      val dut = Module(new RestoreTestDut()(tileParams))
      val io = IO(chiselTypeOf(dut.io))
      io <> dut.io
    }
  })
  (new ChiselStage).emitVerilog(bus.module, Array("--target-dir", args(0)))
}

/** P4-09/P5-10: production IOMSHR with real external A/D handshakes. */
class IoTestDut(implicit p: Parameters, edge: TLEdgeOut) extends Module {
  val io = IO(new Bundle {
    val request = Input(Bool()); val ready = Output(Bool())
    val seq = Input(UInt(32.W)); val safe = Input(UInt(32.W)); val dead = Input(UInt(32.W))
    val write = Input(Bool()); val amo = Input(Bool())
    val address = Input(UInt(40.W)); val operand = Input(UInt(64.W))
    val external = Output(Bool()); val externalReady = Input(Bool()); val ack = Input(Bool())
    val input = Input(UInt(64.W)); val response = Output(Bool()); val result = Output(UInt(64.W))
    val responseReady = Input(Bool()); val completed = Output(Bool()); val doneReady = Input(Bool())
    val busy = Output(Bool()); val effectPending = Output(Bool())
    val replayFault = Output(Bool()); val replayFaultSeq = Output(UInt(32.W))
  })
  val dut = Module(new boom.lsu.BoomIOMSHR(0))
  dut.io.watermark := io.safe
  dut.io.historyContext := 0.U.asTypeOf(new PalimpsestHistoryQuery)
  dut.io.historyContext.occupied(0) := io.dead =/= 0.U
  dut.io.historyContext.lower(0) := io.dead
  dut.io.historyContext.upper(0) := io.dead
  dut.io.req.valid := io.request
  dut.io.preview := io.request
  dut.io.req.bits := 0.U.asTypeOf(chiselTypeOf(dut.io.req.bits))
  dut.io.req.bits.packet_seq := io.seq
  dut.io.req.bits.addr := io.address
  dut.io.req.bits.data := io.operand
  dut.io.req.bits.uop.debug_pc := "h80000100".U
  dut.io.req.bits.uop.mem_size := 3.U
  dut.io.req.bits.uop.mem_cmd := Mux(io.amo, freechips.rocketchip.rocket.M_XA_ADD,
    Mux(io.write, freechips.rocketchip.rocket.M_XWR, freechips.rocketchip.rocket.M_XRD))
  dut.io.req.bits.uop.is_amo := io.amo
  dut.io.req.bits.uop.uses_stq := io.write || io.amo
  dut.io.req.bits.uop.uses_ldq := !io.write && !io.amo
  dut.io.mem_access.ready := io.externalReady
  dut.io.mem_ack.valid := io.ack
  dut.io.mem_ack.bits := 0.U.asTypeOf(chiselTypeOf(dut.io.mem_ack.bits))
  dut.io.mem_ack.bits.opcode := Mux(io.write && !io.amo, TLMessages.AccessAck, TLMessages.AccessAckData)
  dut.io.mem_ack.bits.data := Fill(edge.bundle.dataBits / 64, io.input)
  dut.io.resp.ready := io.responseReady
  dut.io.completion.ready := io.doneReady
  io.ready := dut.io.req.ready
  io.external := dut.io.mem_access.valid
  io.response := dut.io.resp.valid
  io.result := dut.io.resp.bits.data
  io.completed := dut.io.completion.valid
  io.busy := dut.io.busy
  io.effectPending := dut.io.effectPending
  io.replayFault := dut.io.replayFault.valid
  io.replayFaultSeq := dut.io.replayFault.bits
}
object EmitIo extends App {
  require(args.length == 1)
  implicit val p: Parameters = new chipyard.v1Config
  val bus = LazyModule(new RecoveryFixtureBus(false) {
    override lazy val module: LazyModuleImp = new LazyModuleImp(this) {
      override def desiredName = "IoHarness"
      tieOffFixtureBus()
      val dut = Module(new IoTestDut()(tileParams, client.edges.out.head))
      val io = IO(chiselTypeOf(dut.io))
      io <> dut.io
    }
  })
  (new ChiselStage).emitVerilog(bus.module, Array("--target-dir", args(0)))
}

/** P5-10: instantiate the very same controller wired into BoomCore. The
  * host supplies ROB/LSU/RSU/segment events, not a second boundary model.
  */
object EmitIoBoundary extends App {
  require(args.length == 1)
  (new ChiselStage).emitVerilog(new PalimpsestIoBoundary(8, 2) {
    override def desiredName = "IoBoundaryHarness"
  }, Array("--target-dir", args(0)))
}

/** P4-10: exercise the production three-lane ROB and its recovery stop. */
object EmitPreciseException extends App {
  require(args.length == 1)
  implicit val p: Parameters = new chipyard.v1Config
  val bus = LazyModule(new RecoveryFixtureBus(true) {
    override lazy val module: LazyModuleImp = new LazyModuleImp(this) {
      override def desiredName = "PreciseExceptionHarness"
      tieOffFixtureBus()
      val io = IO(new Bundle {
        val dispatch = Input(Bool())
        val completeOlder = Input(Bool())
        val stop = Input(Bool())
        val resetBackend = Input(Bool())
        val ready = Output(Bool())
        val retired = Output(UInt(3.W))
        val trap = Output(Bool())
        val cause = Output(UInt(64.W))
        val pcOffset = Output(UInt(6.W))
        val empty = Output(Bool())
        val trackerTrap = Input(Bool())
        val trackerReturn = Input(Bool())
        val trackerRetire = Input(Bool())
        val saveTrapSeq = Input(UInt(32.W))
        val restoreTrapSeq = Input(UInt(32.W))
        val trapRestoreReady = Output(Bool())
        val handler = Output(Bool())
        val syscall = Output(Bool())
      })
      val rob = withReset(reset.asBool || io.resetBackend) {
        Module(new Rob(1, 1)(tileParams))
      }
      val r = rob.io
      require(r.enq_valids.length == 3)
      r.enq_valids := VecInit(Seq(io.dispatch, false.B, io.dispatch))
      r.enq_uops := 0.U.asTypeOf(chiselTypeOf(r.enq_uops))
      r.enq_uops(0).rob_idx := r.rob_tail_idx
      r.enq_uops(2).rob_idx := r.rob_tail_idx + 2.U
      r.enq_uops(2).exception := true.B
      r.enq_uops(2).exc_cause := 2.U
      r.enq_uops(2).pc_lob := 8.U
      r.enq_partial_stall := false.B
      r.xcpt_fetch_pc := "h80000000".U
      r.brupdate.b1 := 0.U.asTypeOf(chiselTypeOf(r.brupdate.b1))
      r.brupdate.b2.elements.filterNot(_._1 == "target_offset").foreach { case (_, field) =>
        field := 0.U.asTypeOf(chiselTypeOf(field))
      }
      r.brupdate.b2.target_offset := 0.S(21.W)
      r.wb_resps := 0.U.asTypeOf(chiselTypeOf(r.wb_resps))
      r.wb_resps(0).valid := io.completeOlder
      r.wb_resps(0).bits.uop.rob_idx := r.rob_head_idx
      r.lsu_clr_bsy := 0.U.asTypeOf(chiselTypeOf(r.lsu_clr_bsy))
      r.lsu_clr_unsafe := 0.U.asTypeOf(chiselTypeOf(r.lsu_clr_unsafe))
      r.debug_wb_valids := 0.U.asTypeOf(chiselTypeOf(r.debug_wb_valids))
      r.debug_wb_wdata := 0.U.asTypeOf(chiselTypeOf(r.debug_wb_wdata))
      r.debug_rs1_data := 0.U.asTypeOf(chiselTypeOf(r.debug_rs1_data))
      r.debug_rs2_data := 0.U.asTypeOf(chiselTypeOf(r.debug_rs2_data))
      r.debug_st := 0.U.asTypeOf(chiselTypeOf(r.debug_st))
      r.fflags := 0.U.asTypeOf(chiselTypeOf(r.fflags))
      r.lxcpt := 0.U.asTypeOf(chiselTypeOf(r.lxcpt))
      r.palimpsestSingleStep := false.B
      r.palimpsestRecoveryStop := io.stop
      r.csr_stall := false.B
      r.debug_tsc := 0.U
      r.gh_stall := io.stop
      r.gh_effective_jalr_target := 0.U
      r.gh_effective_rob_idx := 0.U
      r.gh_effective_valid := 0.U
      r.arch_redirect_valid := false.B
      r.arch_redirect_pc := 0.U
      io.ready := r.ready
      io.retired := r.commit.arch_valids.asUInt
      io.trap := r.com_xcpt.valid
      io.cause := r.com_xcpt.bits.cause
      io.pcOffset := r.com_xcpt.bits.pc_lob
      io.empty := r.empty
      val trap = Module(new PalimpsestTrapTracker)
      val contexts = Module(new PalimpsestContextMemory(64, 40, 64, 4))
      contexts.io.capture.valid := io.saveTrapSeq =/= 0.U
      contexts.io.capture.bits := 0.U.asTypeOf(chiselTypeOf(contexts.io.capture.bits))
      contexts.io.capture.bits.seq := io.saveTrapSeq
      contexts.io.capture.bits.trap := trap.io.snapshot
      when (contexts.io.capture.valid) { assert(contexts.io.capture.ready) }
      contexts.io.read.valid := io.restoreTrapSeq =/= 0.U
      contexts.io.read.bits := io.restoreTrapSeq
      contexts.io.safeWatermark := 0.U
      contexts.io.abort := false.B
      contexts.io.discard := 0.U.asTypeOf(chiselTypeOf(contexts.io.discard))
      contexts.io.response.ready := io.stop
      trap.io.restore.valid := contexts.io.response.fire
      trap.io.restore.bits := contexts.io.response.bits.trap
      trap.io.stop := io.stop
      trap.io.trap := io.trackerTrap
      trap.io.exception := io.trackerTrap
      trap.io.returns := io.trackerReturn
      trap.io.countedRetire := io.trackerRetire
      io.trapRestoreReady := contexts.io.response.valid
      io.handler := trap.io.snapshot.inHandler
      io.syscall := trap.io.syscall
    }
  })
  (new ChiselStage).emitVerilog(bus.module, Array("--target-dir", args(0)))
}

/** Real LSU at the execution/rollback boundary. Cache responses and PTW are
  * host endpoints; incoming execution requests are the production Valid IO.
  */
object EmitLsuRecovery extends App {
  require(args.length == 1)
  implicit val p: Parameters = new chipyard.v1Config
  val bus = LazyModule(new RecoveryFixtureBus(true, 64) {
    override lazy val module: LazyModuleImp = new LazyModuleImp(this) {
      override def desiredName = "LsuRecoveryHarness"
      tieOffFixtureBus()
      val io = IO(new Bundle {
        val dispatch = Input(Bool())
        val execute = Input(Bool())
        val kind = Input(UInt(3.W)) // load, combined store, address, data, SFENCE
        val stop = Input(Bool())
        val resetBackend = Input(Bool())
        val request = Output(Bool())
        val walk = Output(Bool())
        val busyClear = Output(Bool())
        val drained = Output(Bool())
      })
      val lsu = Module(new boom.lsu.LSU()(tileParams, client.edges.out.head))
      for (i <- 0 until 9) {
        val probe = WireDefault(0.U(64.W))
        chisel3.util.experimental.BoringUtils.addSink(probe, s"stage1_lsu_${tile.hartId}_$i")
        dontTouch(probe)
      }
      for (i <- 0 until 64) {
        val probe = WireDefault(0.U(256.W))
        chisel3.util.experimental.BoringUtils.addSink(probe, s"stage1_stq_${tile.hartId}_$i")
        dontTouch(probe)
      }
      def clearInputs(port: Data): Unit = port match {
        case record: Record => record.elements.values.foreach(clearInputs)
        case vec: Vec[_] => vec.getElements.foreach(clearInputs)
        case signed: SInt if DataMirror.directionOf(port) == ActualDirection.Input => signed := 0.S(21.W)
        case _ if DataMirror.directionOf(port) == ActualDirection.Input => port := 0.U.asTypeOf(chiselTypeOf(port))
        case _ =>
      }
      clearInputs(lsu.io)
      lsu.io.rollbackStop := io.stop
      lsu.io.rollbackTarget := 8.U
      lsu.io.rollbackReset := io.resetBackend
      lsu.io.core.ioPermit := !io.stop
      lsu.io.dmem.ordered := true.B
      lsu.io.dmem.req.ready := true.B
      lsu.io.ptw.ptbr.mode := 0.U
      lsu.io.ptw.status.prv := 3.U
      lsu.io.ptw.status.dprv := 3.U
      lsu.io.ptw.req.ready := true.B
      val uop = WireInit(0.U.asTypeOf(chiselTypeOf(lsu.io.core.dis_uops(0).bits)))
      uop.debug_pc := "h80001000".U
      uop.uses_ldq := io.kind === 0.U
      uop.uses_stq := io.kind >= 1.U && io.kind <= 3.U
      uop.ctrl.is_load := io.kind === 0.U
      uop.ctrl.is_sta := io.kind === 1.U || io.kind === 2.U
      uop.ctrl.is_std := io.kind === 1.U || io.kind === 3.U
      uop.mem_size := 3.U
      uop.mem_cmd := Mux(io.kind === 0.U, 0.U, 1.U)
      lsu.io.core.dis_uops(0).valid := io.dispatch
      lsu.io.core.dis_uops(0).bits := uop
      lsu.io.core.exe(0).req.valid := io.execute
      lsu.io.core.exe(0).req.bits.uop := uop
      lsu.io.core.exe(0).req.bits.addr := "h80002000".U
      lsu.io.core.exe(0).req.bits.data := "h1234".U
      lsu.io.core.exe(0).req.bits.sfence.valid := io.execute && io.kind === 4.U
      io.request := lsu.io.dmem.req.valid && lsu.io.dmem.req.bits.map(_.valid).reduce(_ || _)
      io.walk := lsu.io.ptw.req.valid
      io.busyClear := lsu.io.core.clr_bsy.map(_.valid).reduce(_ || _)
      io.drained := lsu.io.rollbackDrained
    }
  })
  (new ChiselStage).emitVerilog(bus.module, Array("--target-dir", args(0)))
}
