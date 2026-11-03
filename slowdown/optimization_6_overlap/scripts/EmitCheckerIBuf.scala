package opt4perf

import Chisel._
import chisel3.stage.ChiselStage
import freechips.rocketchip.util._
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.rocket.{BTBResp, FrontendResp, IBuf, ICacheParams, Instruction, RocketCoreParams}
import freechips.rocketchip.tile.{RocketTileParams, TileKey, TileVisibilityNodeKey}
import freechips.rocketchip.tilelink._

class CheckerIBufWrapper(words: Int, base: org.chipsalliance.cde.config.Parameters)
    extends Module {
  private val client = TLMasterPortParameters.v1(Seq(TLMasterParameters.v1(name = "checker_ibuf")))
  private val manager = TLSlavePortParameters.v1(Seq(TLSlaveParameters.v1(
    address = Seq(AddressSet(0, 0xffff)), supportsGet = TransferSizes(1, 8))), beatBytes = 8)
  private val edge = new TLEdgeOut(client, manager, base,
    chisel3.internal.sourceinfo.UnlocatableSourceInfo)
  private val visibility = new TLEphemeralNode()(ValName("tile_master")) {
    override lazy val edges: Edges[TLEdgeIn, TLEdgeOut] = Edges(Nil, Seq(edge))
  }
  private val tile = RocketTileParams(
    core = RocketCoreParams(fetchWords = words),
    icache = Some(ICacheParams(fetchBytes = 4 * words)))
  private implicit val tileParameters = base.alterMap(Map(
    TileKey -> tile,
    TileVisibilityNodeKey -> visibility))
  val io = IO(new Bundle {
    val imem = Flipped(Decoupled(new FrontendResp()(tileParameters)))
    val kill = Input(Bool())
    val pc = Output(UInt(40.W))
    val btb_resp = Output(new BTBResp()(tileParameters))
    val checker_mode = Input(Bool())
    val inst = Vec(1, Decoupled(new Instruction()(tileParameters)))
  })
  val ibuf = Module(new IBuf()(tileParameters))
  ibuf.io.imem.valid := io.imem.valid
  ibuf.io.imem.bits := io.imem.bits
  io.imem.ready := ibuf.io.imem.ready
  ibuf.io.kill := io.kill
  ibuf.io.checker_mode := io.checker_mode
  io.inst(0).valid := ibuf.io.inst(0).valid
  io.inst(0).bits := ibuf.io.inst(0).bits
  ibuf.io.inst(0).ready := io.inst(0).ready
  io.pc := ibuf.io.pc
  io.btb_resp := ibuf.io.btb_resp
}

/** Standalone emitted hardware for short instruction-buffer tests. */
object EmitCheckerIBuf extends App {
  require(args.length == 2, "usage: EmitCheckerIBuf FETCH_WORDS OUTPUT_DIRECTORY")
  val words = args(0).toInt
  val parameters = new chipyard.v1Config().toInstance
  (new ChiselStage).emitVerilog(new CheckerIBufWrapper(words, parameters),
    Array("--target-dir", args(1)))
}
