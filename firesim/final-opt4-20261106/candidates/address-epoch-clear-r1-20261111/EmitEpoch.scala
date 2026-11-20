package opt4epoch

import chisel3._
import chisel3.util._

/** One symbolic slot proves the uniform 256-entry update equation. */
class EpochProof extends RawModule {
  val io = IO(new Bundle {
    val valid = Input(Bool())
    val processValid = Input(Bool())
    val eventEnable = Input(Bool())
    val current = Input(Bool())
    val retireReq = Input(Bool())
    val reset = Input(Bool())
    val oldCounters = Input(Vec(5, UInt(64.W)))
    val newCounters = Input(Vec(5, UInt(64.W)))
    val delta = Input(Vec(5, UInt(64.W)))
    val oldNext = Output(Vec(5, UInt(64.W)))
    val newNext = Output(Vec(5, UInt(64.W)))
    val nextValid = Output(Bool())
    val commit = Output(Bool())
    val oldOverflow = Output(Bool())
    val newOverflow = Output(Bool())
    val observableEqual = Output(Bool())
    val stepOk = Output(Bool())
    val unguardedInvalidOverflow = Output(Bool())
  })

  val oldBase = VecInit((0 until 5).map(i =>
    Mux(io.valid, io.oldCounters(i), 0.U(64.W))))
  val oldSums = VecInit((0 until 5).map(i =>
    oldBase(i) +& io.delta(i)))
  val newSums = VecInit((0 until 5).map(i =>
    io.newCounters(i) +& io.delta(i)))
  val anyDelta = io.delta.map(_.orR).reduce(_ || _)
  val qualified = io.current || !anyDelta || io.valid
  val oldOverflow = oldSums.map(_(64)).reduce(_ || _)
  val newOverflowRaw = newSums.map(_(64)).reduce(_ || _)
  val newOverflow = io.valid && newOverflowRaw
  val commit = io.processValid && io.eventEnable && qualified && !oldOverflow
  val retire = !io.processValid && io.retireReq && io.valid
  val nextValid = !io.reset && (io.valid && !retire || commit && io.current)

  io.oldNext := VecInit((0 until 5).map(i => Mux(io.reset, 0.U(64.W),
    Mux(commit, Mux(io.valid, oldSums(i)(63, 0), io.delta(i)),
      Mux(retire, 0.U(64.W), oldBase(i))))))
  io.newNext := VecInit((0 until 5).map(i => Mux(io.reset, 0.U(64.W),
    Mux(commit, Mux(io.valid, newSums(i)(63, 0), io.delta(i)),
      io.newCounters(i)))))
  io.nextValid := nextValid
  io.commit := commit
  io.oldOverflow := oldOverflow
  io.newOverflow := newOverflow
  io.observableEqual := VecInit((0 until 5).map(i =>
    Mux(io.valid, io.oldCounters(i), 0.U) ===
      Mux(io.valid, io.newCounters(i), 0.U))).asUInt.andR

  val stateInvariant = !io.valid || io.oldCounters.asUInt === io.newCounters.asUInt
  io.stepOk := !stateInvariant || (io.observableEqual &&
    oldOverflow === newOverflow &&
    (!nextValid || io.oldNext.asUInt === io.newNext.asUInt))
  io.unguardedInvalidOverflow := !io.valid && !io.current && anyDelta &&
    newOverflowRaw && !oldOverflow
}

object EmitEpoch extends App {
  val stage = new chisel3.stage.ChiselStage
  args(0) match {
    case "proof" => stage.emitVerilog(new EpochProof, Array("--target-dir", args(1)))
    case "address" => stage.emitVerilog(
      new boom.lsu.PackageAddressStats(3, 40, 64, 256),
      Array("--target-dir", args(1)))
  }
}
