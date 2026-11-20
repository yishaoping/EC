package opt4epoch

import chisel3._
import chisel3.util._

/** One-slot inductive cut for reset/retire payload elision. */
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
    val delta = Input(Vec(5, UInt(13.W)))
    val stepOk = Output(Bool())
    val observableEqual = Output(Bool())
    val oldOverflow = Output(Bool())
    val newOverflow = Output(Bool())
    val commitEqual = Output(Bool())
    val nextObservableEqual = Output(Bool())
    val unguardedInvalidOverflow = Output(Bool())
  })

  val oldBase = VecInit((0 until 5).map(i =>
    Mux(io.valid, io.oldCounters(i), 0.U(64.W))))
  val newBase = VecInit((0 until 5).map(i =>
    Mux(io.valid, io.newCounters(i), 0.U(64.W))))
  val oldSums = VecInit((0 until 5).map(i => oldBase(i) +& io.delta(i).pad(64)))
  val newSums = VecInit((0 until 5).map(i => newBase(i) +& io.delta(i).pad(64)))
  val anyDelta = io.delta.map(_.orR).reduce(_ || _)
  val structuralOk = io.current || io.valid || !anyDelta
  val oldOverflow = oldSums.map(_(64)).reduce(_ || _)
  // With invalid payloads, the only addend is a bounded per-cycle histogram
  // delta (13 bits), so it cannot carry out of the architectural 64-bit sum.
  val newOverflow = io.valid && newSums.map(_(64)).reduce(_ || _)
  val commit = !io.reset && io.processValid && io.eventEnable && structuralOk && !oldOverflow
  val retire = !io.reset && !io.processValid && io.retireReq && io.valid
  val nextValid = !io.reset && (io.valid && !retire || commit && io.current)

  val oldNext = VecInit((0 until 5).map(i => Mux(io.reset, 0.U(64.W),
    Mux(commit && (io.current || anyDelta), oldSums(i)(63, 0),
      Mux(retire, 0.U(64.W), io.oldCounters(i))))))
  // A reset or retirement only invalidates the slot. Its payload can retain
  // stale bits because all consumers select zero while valid is false.
  val newNext = VecInit((0 until 5).map(i =>
    Mux(commit && (io.current || anyDelta), newSums(i)(63, 0), io.newCounters(i))))
  val invariant = !io.valid || io.oldCounters.asUInt === io.newCounters.asUInt
  val observableEqual = VecInit((0 until 5).map(i =>
    Mux(io.valid, io.oldCounters(i), 0.U) ===
      Mux(io.valid, io.newCounters(i), 0.U))).asUInt.andR
  val nextObservableEqual = !nextValid || oldNext.asUInt === newNext.asUInt

  io.observableEqual := observableEqual
  io.oldOverflow := oldOverflow
  io.newOverflow := newOverflow
  io.commitEqual := commit ===
    (!io.reset && io.processValid && io.eventEnable && structuralOk && !newOverflow)
  io.nextObservableEqual := nextObservableEqual
  io.stepOk := !invariant || (observableEqual && oldOverflow === newOverflow &&
    io.commitEqual && nextObservableEqual)
  io.unguardedInvalidOverflow := !io.valid && !io.current && anyDelta &&
    VecInit((0 until 5).map(i =>
      (io.newCounters(i) +& io.delta(i).pad(64))(64))).asUInt.orR
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
