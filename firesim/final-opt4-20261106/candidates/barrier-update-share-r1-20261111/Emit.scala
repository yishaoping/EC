package opt4barriershare

import chisel3._
import chisel3.util._
import freechips.rocketchip.guardiancouncil.{GHBarrierEventUpdate, GHBarrierLatencyStats}

/** Arbitrary 256-slot hold/clear/write transition; no reachability assumption.
  * One payload bit lifts to each bit because the write data is independent of
  * the slot decoder. Full 64-bit arithmetic is proved separately below.
  */
class SlotWriteProof extends RawModule {
  val io = IO(new Bundle {
    val words = Input(Vec(256, Bool()))
    val clear = Input(Vec(256, Bool()))
    val index = Input(UInt(8.W))
    val accepted = Input(Bool())
    val data = Input(Bool())
    val reset = Input(Bool())
    val equivalent = Output(Bool())
    val mutantEquivalent = Output(Bool())
  })
  val reference = WireInit(io.words)
  for (i <- 0 until 256) {
    when (io.clear(i)) { reference(i) := false.B }
  }
  when (io.accepted) { reference(io.index) := io.data }
  when (io.reset) { reference := 0.U.asTypeOf(reference) }
  val candidate = Wire(Vec(256, Bool()))
  val mutant = Wire(Vec(256, Bool()))
  for (i <- 0 until 256) {
    candidate(i) := Mux(io.reset, false.B,
      Mux(GHBarrierEventUpdate.selected(io.accepted, io.index, i), io.data,
        Mux(io.clear(i), false.B, io.words(i))))
    mutant(i) := Mux(io.reset, false.B,
      Mux(GHBarrierEventUpdate.selected(io.accepted, io.index, 255-i), io.data,
        Mux(io.clear(i), false.B, io.words(i))))
  }
  io.equivalent := candidate.asUInt === reference.asUInt
  io.mutantEquivalent := mutant.asUInt === reference.asUInt
}

class ArithmeticProof extends RawModule {
  val io = IO(new Bundle {
    val allocate = Input(Bool())
    val count = Input(UInt(64.W))
    val sum = Input(UInt(64.W))
    val cycle = Input(UInt(64.W))
    val equivalent = Output(Bool())
    val mutantEquivalent = Output(Bool())
  })
  val referenceCount = Wire(UInt(64.W))
  val referenceSum = Wire(UInt(64.W))
  when (io.allocate) {
    referenceCount := 1.U
    referenceSum := io.cycle
  }.otherwise {
    referenceCount := io.count + 1.U
    referenceSum := io.sum + io.cycle
  }
  val candidateCount = GHBarrierEventUpdate.count(io.allocate, io.count)
  val candidateSum = GHBarrierEventUpdate.cycleSum(io.allocate, io.sum, io.cycle)
  io.equivalent := candidateCount === referenceCount && candidateSum === referenceSum
  io.mutantEquivalent := candidateCount === referenceCount &&
    (candidateSum ^ 1.U) === referenceSum
}

object Emit extends App {
  val stage = new chisel3.stage.ChiselStage
  args(0) match {
    case "slots" => stage.emitVerilog(new SlotWriteProof, Array("--target-dir", args(1)))
    case "arithmetic" => stage.emitVerilog(new ArithmeticProof, Array("--target-dir", args(1)))
    case "module" => stage.emitVerilog(new GHBarrierLatencyStats(256), Array("--target-dir", args(1)))
  }
}
