package palimpsesttest

import chisel3._
import chisel3.stage.ChiselStage
import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.rocket._
import freechips.rocketchip.rocket.constants.MemoryOpConstants
import freechips.rocketchip.subsystem.{InSubsystem, TilesLocated}
import freechips.rocketchip.tile.{TileKey, TileVisibilityNodeKey}
import freechips.rocketchip.tilelink._
import boom.common.BoomTileAttachParams
import boom.lsu.NBDTLB

abstract class TranslationRecoveryPort(implicit p: Parameters) extends LazyModule {
  val config = new chipyard.v1Config
  val tile = config(TilesLocated(InSubsystem)).collectFirst {
    case t: BoomTileAttachParams => t.tileParams
  }.get
  val client = TLClientNode(Seq(TLClientPortParameters(Seq(
    TLClientParameters(name = "translation-test", sourceId = IdRange(0, 1))))))
  val visibility = TLIdentityNode()
  val memory = TLManagerNode(Seq(TLManagerPortParameters(Seq(TLManagerParameters(
    address = Seq(AddressSet(BigInt("80000000", 16), BigInt("fffffff", 16))),
    regionType = RegionType.UNCACHED, executable = true, supportsGet = TransferSizes(1, 64))), beatBytes = 16)))
  memory := visibility := client
  abstract class FixtureModule extends LazyModuleImp(this) with MemoryOpConstants {
    val tileParameters = config.alterPartial {
      case TileKey => tile
      case TileVisibilityNodeKey => visibility
    }
    val (bus, edge) = client.out.head
    // Only address attributes are used. The host models the PTW response.
    bus.a.valid := false.B
    bus.a.bits := 0.U.asTypeOf(chiselTypeOf(bus.a.bits))
    bus.d.ready := true.B
    val (mem, _) = memory.in.head
    mem.a.ready := false.B
    mem.d.valid := false.B
    mem.d.bits := 0.U.asTypeOf(chiselTypeOf(mem.d.bits))
  }
}

class TranslationRecoveryFixture(implicit p: Parameters) extends TranslationRecoveryPort {
  lazy val module = new FixtureModule {
    override def desiredName = "TranslationRecoveryHarness"
    val io = IO(new Bundle {
      val instruction = Input(Bool())
      val lookup = Input(Bool())
      val fence = Input(Bool())
      val walkReady = Input(Bool())
      val reply = Input(Bool())
      val homogeneous = Input(Bool())
      val vaddr = Input(UInt(40.W))
      val ppn = Input(UInt(44.W))
      val level = Input(UInt(2.W))
      val miss = Output(Bool())
      val idle = Output(Bool())
      val walk = Output(Bool())
      val resultAddr = Output(UInt(56.W))
    })
    val tlb = Module(new NBDTLB(false, 3, TLBConfig(1, 8))(edge, tileParameters))
    tlb.io.req.foreach { req =>
      req.valid := false.B
      req.bits := 0.U.asTypeOf(chiselTypeOf(req.bits))
    }
    val first = tlb.io.req.head
    first.valid := io.lookup && !io.instruction
    first.bits.vaddr := io.vaddr
    first.bits.cmd := M_XRD
    first.bits.size := 3.U
    tlb.io.kill := false.B
    tlb.io.sfence.valid := io.fence
    tlb.io.sfence.bits := 0.U.asTypeOf(chiselTypeOf(tlb.io.sfence.bits))
    // BOOM Frontend instantiates the shared Rocket TLB in instruction mode.
    val itlb = Module(new TLB(true, 3, TLBConfig(1, 8))(edge, tileParameters))
    itlb.io.req.valid := io.lookup && io.instruction
    itlb.io.req.bits := 0.U.asTypeOf(chiselTypeOf(itlb.io.req.bits))
    itlb.io.req.bits.vaddr := io.vaddr
    itlb.io.req.bits.cmd := M_XRD
    itlb.io.req.bits.prv := PRV.S.U
    itlb.io.req.bits.size := 3.U
    itlb.io.kill := false.B
    itlb.io.sfence.valid := io.fence
    itlb.io.sfence.bits := 0.U.asTypeOf(chiselTypeOf(itlb.io.sfence.bits))

    for ((ptw, selected) <- Seq((tlb.io.ptw, !io.instruction), (itlb.io.ptw, io.instruction))) {
      ptw.req.ready := io.walkReady && selected
      ptw.resp.valid := io.reply && selected
      ptw.resp.bits := 0.U.asTypeOf(chiselTypeOf(ptw.resp.bits))
      ptw.resp.bits.level := io.level
      ptw.resp.bits.homogeneous := io.homogeneous
      ptw.resp.bits.pte.ppn := io.ppn
      ptw.resp.bits.pte.v := true.B
      ptw.resp.bits.pte.r := true.B
      ptw.resp.bits.pte.x := true.B
      ptw.resp.bits.pte.a := true.B
      ptw.ptbr := 0.U.asTypeOf(chiselTypeOf(ptw.ptbr))
      ptw.ptbr.mode := 8.U
      ptw.hgatp := 0.U.asTypeOf(chiselTypeOf(ptw.hgatp))
      ptw.vsatp := 0.U.asTypeOf(chiselTypeOf(ptw.vsatp))
      ptw.status := 0.U.asTypeOf(chiselTypeOf(ptw.status))
      ptw.status.dprv := PRV.S.U
      ptw.hstatus := 0.U.asTypeOf(chiselTypeOf(ptw.hstatus))
      ptw.gstatus := 0.U.asTypeOf(chiselTypeOf(ptw.gstatus))
      ptw.pmp := 0.U.asTypeOf(chiselTypeOf(ptw.pmp))
      ptw.customCSRs := 0.U.asTypeOf(chiselTypeOf(ptw.customCSRs))
    }
    val instructionWalk = itlb.io.ptw.req.valid && itlb.io.ptw.req.bits.valid
    val dataWalk = tlb.io.ptw.req.valid && tlb.io.ptw.req.bits.valid
    io.miss := Mux(io.instruction, itlb.io.resp.miss, tlb.io.resp.head.miss)
    io.idle := Mux(io.instruction, itlb.io.req.ready, tlb.io.miss_rdy)
    io.walk := Mux(io.instruction, instructionWalk, dataWalk)
    io.resultAddr := Mux(io.instruction, itlb.io.resp.paddr, tlb.io.resp.head.paddr)
  }
}

object EmitTranslationRecovery extends App {
  require(args.length == 1)
  implicit val p: Parameters = new chipyard.v1Config
  (new ChiselStage).emitVerilog(LazyModule(new TranslationRecoveryFixture).module, Array("--target-dir", args(0)))
}


class PtwRecoveryFixture(implicit p: Parameters) extends TranslationRecoveryPort {
  lazy val module = new FixtureModule {
    override def desiredName = "PtwRecoveryHarness"
    val io = IO(new Bundle {
      val walk = Input(Bool())
      val ready = Output(Bool())
      val vpn = Input(UInt(27.W))
      val root = Input(UInt(44.W))
      val fence = Input(Bool())
      val memValid = Output(Bool())
      val memAddr = Output(UInt(56.W))
      val memReady = Input(Bool())
      val memKill = Output(Bool())
      val memResponse = Input(Bool())
      val memData = Input(UInt(64.W))
      val done = Output(Bool())
      val exception = Output(Bool())
      val ppn = Output(UInt(44.W))
    })
    val ptw = Module(new PTW(1)(edge, tileParameters))
    val requestor = ptw.io.requestor.head
    requestor.req.valid := io.walk
    requestor.req.bits.valid := true.B
    requestor.req.bits.bits.addr := io.vpn
    requestor.req.bits.bits.need_gpa := false.B
    requestor.req.bits.bits.vstage1 := false.B
    requestor.req.bits.bits.stage2 := false.B
    io.ready := requestor.req.ready
    io.done := requestor.resp.valid
    io.exception := requestor.resp.bits.ae_ptw || requestor.resp.bits.ae_final ||
      requestor.resp.bits.pf || requestor.resp.bits.gf
    io.ppn := requestor.resp.bits.pte.ppn
    val dpath = ptw.io.dpath
    dpath.ptbr := 0.U.asTypeOf(chiselTypeOf(dpath.ptbr))
    dpath.ptbr.mode := 8.U
    dpath.ptbr.ppn := io.root
    dpath.hgatp := 0.U.asTypeOf(chiselTypeOf(dpath.hgatp))
    dpath.vsatp := 0.U.asTypeOf(chiselTypeOf(dpath.vsatp))
    dpath.status := 0.U.asTypeOf(chiselTypeOf(dpath.status))
    dpath.status.dprv := PRV.S.U
    dpath.hstatus := 0.U.asTypeOf(chiselTypeOf(dpath.hstatus))
    dpath.gstatus := 0.U.asTypeOf(chiselTypeOf(dpath.gstatus))
    dpath.pmp := 0.U.asTypeOf(chiselTypeOf(dpath.pmp))
    dpath.customCSRs := 0.U.asTypeOf(chiselTypeOf(dpath.customCSRs))
    dpath.sfence.valid := io.fence
    dpath.sfence.bits := 0.U.asTypeOf(chiselTypeOf(dpath.sfence.bits))

    val memPort = ptw.io.mem
    io.memValid := memPort.req.valid
    io.memAddr := memPort.req.bits.addr
    io.memKill := memPort.s1_kill
    memPort.req.ready := io.memReady
    memPort.resp.valid := io.memResponse
    memPort.resp.bits := 0.U.asTypeOf(chiselTypeOf(memPort.resp.bits))
    memPort.resp.bits.data := io.memData
    memPort.s2_nack := false.B
    memPort.s2_nack_cause_raw := false.B
    memPort.s2_xcpt := 0.U.asTypeOf(chiselTypeOf(memPort.s2_xcpt))
    memPort.s2_paddr := 0.U
    memPort.s2_uncached := false.B
    memPort.s2_gpa := 0.U
    memPort.s2_gpa_is_pte := false.B
    memPort.ordered := true.B
    memPort.clock_enabled := true.B
    memPort.perf := 0.U.asTypeOf(chiselTypeOf(memPort.perf))
    memPort.replay_next := false.B
    memPort.uncached_resp.foreach { response =>
      response.valid := false.B
      response.bits := 0.U.asTypeOf(chiselTypeOf(response.bits))
    }
  }
}

object EmitPtwRecovery extends App {
  require(args.length == 1)
  implicit val p: Parameters = new chipyard.v1Config
  (new ChiselStage).emitVerilog(LazyModule(new PtwRecoveryFixture).module, Array("--target-dir", args(0)))
}
