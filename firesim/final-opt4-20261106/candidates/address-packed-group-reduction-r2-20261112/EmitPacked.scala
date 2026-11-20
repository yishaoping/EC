package opt4packed

import chisel3._
import chisel3.util._
import boom.lsu.AddressBucketGrouped

/** Full 80-source / 256-destination / four-granule combinational cut. */
class HistogramProbe(reference: Boolean = false) extends RawModule {
  val io = IO(new Bundle {
    val keys = Input(Vec(80, UInt(8.W)))
    val counts = Input(Vec(80, Vec(4, UInt(4.W))))
    val query = Input(UInt(8.W))
    val accumulator = Input(Vec(4, UInt(64.W)))
    val reset = Input(Bool())
    val buckets = Output(Vec(256, Vec(4, UInt(64.W))))
    val next = Output(Vec(4, UInt(65.W)))
  })
  val bounds = Seq(8, 3, 2, 1)
  val histogram = if (reference) VecInit((0 until 256).map(i =>
    VecInit(bounds.indices.map { g =>
      def tree(xs: Seq[(UInt, Int)]): UInt = {
        if (xs.size == 1) xs.head._1
        else tree(xs.grouped(2).map {
          case Seq((a, am), (b, bm)) =>
            val width = log2Ceil(am + bm + 1)
            (a.pad(width) + b.pad(width), am + bm)
          case Seq(a) => a
        }.toSeq)
      }
      tree((0 until 80).map(j => (Mux(io.keys(j) === i.U,
        io.counts(j)(g)(log2Ceil(bounds(g) + 1) - 1, 0),
        0.U(log2Ceil(bounds(g) + 1).W)), bounds(g)))).pad(64)
    })))
  else AddressBucketGrouped.histogram(io.keys.toSeq, io.counts.map(_.toSeq), bounds, 256)
  io.buckets := histogram
  for (g <- bounds.indices) io.next(g) := Mux(io.reset, 0.U(65.W),
    io.accumulator(g) +& histogram(io.query)(g))
}

object EmitPacked extends App {
  val stage = new chisel3.stage.ChiselStage
  args(0) match {
    case "histogram" => stage.emitVerilog(new HistogramProbe, Array("--target-dir", args(1)))
    case "reference" => stage.emitVerilog(new HistogramProbe(true), Array("--target-dir", args(1)))
  }
}
