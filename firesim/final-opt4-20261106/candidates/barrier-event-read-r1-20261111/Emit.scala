package opt4barrierevent

import chisel3._
import chisel3.util._
import freechips.rocketchip.guardiancouncil.{GHBarrierEventAccess, GHBarrierLatencyStats}

/** Actual 256-slot arbitrary 64-bit read cut; no valid-state assumption. */
class EventReadProof extends RawModule {
  val io = IO(new Bundle {
    val index = Input(UInt(8.W))
    val data = Input(Vec(256, UInt(64.W)))
    val equivalent = Output(Bool())
    val mutantEquivalent = Output(Bool())
  })
  val select = (0 until 256).map(i => io.index === i.U)
  val value = GHBarrierEventAccess.read(select, io.data.toSeq)
  io.equivalent := value === io.data(io.index)
  io.mutantEquivalent := GHBarrierEventAccess.read(select.reverse, io.data.toSeq) === io.data(io.index)
}

object Emit extends App {
  val stage = new chisel3.stage.ChiselStage
  args(0) match {
    case "proof" => stage.emitVerilog(new EventReadProof, Array("--target-dir", args(1)))
    case "module" => stage.emitVerilog(new GHBarrierLatencyStats(256), Array("--target-dir", args(1)))
  }
}
