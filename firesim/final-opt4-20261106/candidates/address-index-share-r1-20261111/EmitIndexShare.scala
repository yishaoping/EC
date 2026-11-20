package opt4index

import chisel3._
import chisel3.util._

class IndexMatchProof extends RawModule {
  val io = IO(new Bundle {
    val sequence = Input(UInt(32.W))
    val bucket = Input(UInt(8.W))
    val direct = Output(Bool())
    val shared = Output(Bool())
    val equivalent = Output(Bool())
    val mutantEquivalent = Output(Bool())
  })
  val table = VecInit((0 until 256).map { i =>
    io.sequence(7, 0) === i.U(8.W)
  })
  io.direct := io.sequence(7, 0) === io.bucket
  io.shared := table(io.bucket)
  io.equivalent := io.direct === io.shared
  io.mutantEquivalent := io.direct === table(io.bucket ^ 1.U(8.W))
}

class IndexMatchBoundary extends RawModule {
  val io = IO(new Bundle {
    val sequences = Input(Vec(88, UInt(32.W)))
    val bucket = Input(UInt(8.W))
    val direct = Output(Vec(88, Bool()))
    val shared = Output(Vec(88, Bool()))
    val equivalent = Output(Bool())
  })
  for (w <- 0 until 88) {
    val table = VecInit((0 until 256).map { i =>
      io.sequences(w)(7, 0) === i.U(8.W)
    })
    io.direct(w) := io.sequences(w)(7, 0) === io.bucket
    io.shared(w) := table(io.bucket)
  }
  io.equivalent := (0 until 88).map(w => io.direct(w) === io.shared(w)).reduce(_ && _)
}

object EmitIndexShare extends App {
  val stage = new chisel3.stage.ChiselStage
  args(0) match {
    case "proof" => stage.emitVerilog(new IndexMatchProof, Array("--target-dir", args(1)))
    case "boundary" => stage.emitVerilog(new IndexMatchBoundary, Array("--target-dir", args(1)))
    case "address" => stage.emitVerilog(new boom.lsu.PackageAddressStats(3, 40, 64, 256),
      Array("--target-dir", args(1)))
  }
}
