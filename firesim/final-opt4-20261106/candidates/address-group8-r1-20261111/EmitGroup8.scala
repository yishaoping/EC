package opt4group

import chisel3._
import chisel3.util._
import boom.lsu.AddressBucketGrouped

class Group8Proof extends RawModule {
  val io = IO(new Bundle {
    val keys = Input(Vec(8, UInt(8.W)))
    val counts = Input(Vec(8, Vec(4, UInt(4.W))))
    val query = Input(UInt(8.W))
    val equivalent = Output(Bool())
    val topology = Output(Bool())
    val bounds = Output(Bool())
    val mutantEquivalent = Output(Bool())
  })
  val limits = Seq(8, 3, 2, 1)
  val bounded = (0 until 8).flatMap(i => limits.indices.map(g =>
    io.counts(i)(g) <= limits(g).U)).reduce(_ && _)
  val group = AddressBucketGrouped.compact8(io.keys.toSeq,
    io.counts.map(_.toSeq), limits)
  val selected = group.map(e => e.last && e.key === io.query)
  val equivalent = limits.indices.map { g =>
    val ref = (0 until 8).map(i => Mux(io.keys(i) === io.query,
      io.counts(i)(g).pad(64), 0.U(64.W))).reduce(_ + _)
    AddressBucketGrouped.scatter(group, io.query, g, limits(g)) === ref
  }.reduce(_ && _)
  val mutant = group.updated(0, group(0).copy(last = false.B))
  val mutantRef = (0 until 8).map(i => Mux(io.keys(i) === io.query,
    io.counts(i)(0).pad(64), 0.U(64.W))).reduce(_ + _)
  io.equivalent := !bounded || equivalent
  io.topology := group.sliding(2).map(p => p(0).key <= p(1).key).reduce(_ && _) &&
    PopCount(selected) <= 1.U
  io.bounds := !bounded || group.flatMap(e => limits.indices.map(g =>
    e.counts(g) <= (8 * limits(g)).U)).reduce(_ && _)
  io.mutantEquivalent := !bounded ||
    AddressBucketGrouped.scatter(mutant, io.query, 0, limits(0)) === mutantRef
}

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
  val limits = Seq(8, 3, 2, 1)
  val histogram = if (reference) VecInit((0 until 256).map(i =>
    VecInit(limits.indices.map { g =>
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
        io.counts(j)(g)(log2Ceil(limits(g) + 1) - 1, 0),
        0.U(log2Ceil(limits(g) + 1).W)), limits(g)))).pad(64)
    })))
  else AddressBucketGrouped.histogram(io.keys.toSeq,
    io.counts.map(_.toSeq), limits, 256)
  io.buckets := histogram
  for (g <- limits.indices) io.next(g) := Mux(io.reset, 0.U(65.W),
    io.accumulator(g) +& histogram(io.query)(g))
}

object EmitGroup8 extends App {
  val stage = new chisel3.stage.ChiselStage
  args(0) match {
    case "proof8" => stage.emitVerilog(new Group8Proof, Array("--target-dir", args(1)))
    case "histogram" => stage.emitVerilog(new HistogramProbe, Array("--target-dir", args(1)))
    case "reference" => stage.emitVerilog(new HistogramProbe(true), Array("--target-dir", args(1)))
    case "address" => stage.emitVerilog(new boom.lsu.PackageAddressStats(3, 40, 64, 256),
      Array("--target-dir", args(1)))
  }
}
