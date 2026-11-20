package deltacsa

import chisel3._
import chisel3.util._
import ecstatscommon.{Counts, Source, WeightedCarrySave}

// All sixteen banks / 256 destinations and all production source records.
// This cuts the combinational delta plane at its actual caller boundary.
// Target state, carry feedback and all host transforms are outside this screen.
class DeltaPlane(candidate: Boolean) extends Module {
  override def desiredName = "FPGATop"
  val io = IO(new Bundle {
    val load = Input(Vec(8, new Source))
    val store = Input(Vec(8, new Source))
    val strict = Input(Vec(80, new Source))
    val delta = Output(Vec(3, Vec(256, Vec(4, UInt(64.W)))))
  })
  val sources = Seq(io.load.toSeq, io.store.toSeq, io.strict.toSeq)
  for (p <- 0 until 3) {
    val keys = sources(p).map(_.key)
    val counts = sources(p).map(_.counts.values)
    io.delta(p) := (if (candidate)
      ecstatscommon.AddressBucketGrouped.histogram(keys, counts, Seq(8, 3, 2, 1), 256)
    else ReferenceGrouped.histogram(keys, counts, Seq(8, 3, 2, 1), 256))
  }
}

// These are the exact compressor used by the production helper at every
// reduction round. Full sum equivalence also requires the tree-width audit.
class CompressorContracts extends Module {
  val io = IO(new Bundle {
    val a = Input(Vec(3, UInt(10.W)))
    val b = Input(Vec(3, UInt(10.W)))
    val c = Input(Vec(3, UInt(10.W)))
    val same = Output(Bool())
  })
  val widths = Seq(7, 8, 10)
  io.same := widths.indices.map { i =>
    val w = widths(i)
    val a = io.a(i)(w - 1, 0)
    val b = io.b(i)(w - 1, 0)
    val c = io.c(i)(w - 1, 0)
    val (s, carry) = WeightedCarrySave.compress(a, b, c, w)
    (s + carry) === (a + b + c)
  }.reduce(_ && _)
}

class ReductionChecks extends Module {
  val io = IO(new Bundle {
    val terms = Input(Vec(20, UInt(10.W)))
    val same = Output(Bool())
  })
  io.same := Seq((6, 10), (4, 8), (4, 8), (3, 7)).map { case (leaf, width) =>
    val xs = io.terms.toSeq.map(_(leaf - 1, 0))
    val expected = xs.map(_.pad(width)).reduce(_ + _)
    WeightedCarrySave.sum(xs, width) === expected
  }.reduce(_ && _)
}

object Emit extends App {
  val module = args(0) match {
    case "Contract" => () => new CompressorContracts
    case "Reduction" => () => new ReductionChecks
    case "Reference" => () => new DeltaPlane(false)
    case "Candidate" => () => new DeltaPlane(true)
  }
  (new chisel3.stage.ChiselStage).emitVerilog(module(),
    Array("--target-dir", args(1), "--output-file", args(0)))
}
