package commonqueryscreen

import chisel3._
import chisel3.util._
import ecstatscommon.BankTagRead

// Exact original common-bank query expression. State is cut to arbitrary
// inputs for this physical screen; all 256 production slots remain present.
object OriginalQuery {
  def apply(valid: Seq[Bool], seq: Seq[UInt], base: UInt, query: UInt): Bool = {
    (0 until 16).map(i => query(7, 0) === (base + i.U)(7, 0) &&
      valid(i) && seq(i)(31, 8) === query(31, 8)).reduce(_ || _)
  }
}

class Contract extends Module {
  val io = IO(new Bundle {
    val valid = Input(Vec(16, Bool()))
    val seq = Input(Vec(16, UInt(32.W)))
    val base = Input(UInt(8.W))
    val query = Input(UInt(32.W))
    val same = Output(Bool())
  })
  io.same := OriginalQuery(io.valid.toSeq, io.seq.toSeq, io.base, io.query) ===
    BankTagRead.matches(io.valid.toSeq, io.seq.toSeq, io.base, io.query)
}

class QueryPlane(candidate: Boolean) extends Module {
  override def desiredName = "FPGATop"
  val io = IO(new Bundle {
    val valid = Input(Vec(256, Bool()))
    val seq = Input(Vec(256, UInt(32.W)))
    val query = Input(Vec(88, UInt(32.W)))
    val matches = Output(Vec(88, Bool()))
  })
  for (q <- 0 until 88) {
    io.matches(q) := (0 until 16).map { b =>
      val valid = io.valid.toSeq.slice(16 * b, 16 * b + 16)
      val seq = io.seq.toSeq.slice(16 * b, 16 * b + 16)
      if (candidate) BankTagRead.matches(valid, seq, (16 * b).U(8.W), io.query(q))
      else OriginalQuery(valid, seq, (16 * b).U(8.W), io.query(q))
    }.reduce(_ || _)
  }
}

object Emit extends App {
  val module = args(0) match {
    case "Contract" => () => new Contract
    case "Reference" => () => new QueryPlane(false)
    case "Candidate" => () => new QueryPlane(true)
  }
  (new chisel3.stage.ChiselStage).emitVerilog(module(),
    Array("--target-dir", args(1), "--output-file", args(0)))
}
