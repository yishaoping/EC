package opt4group

import chisel3._
import chisel3.util._
import boom.lsu.AddressBucketGrouped

class Group8CecIO(granule: Int) extends Bundle {
  val keys = Input(Vec(8, UInt(8.W)))
  val counts = Input(Vec(8, UInt(log2Ceil(Seq(8, 3, 2, 1)(granule) + 1).W)))
  val query = Input(UInt(8.W))
  val result = Output(UInt(64.W))
}

class Group8CandidateGranule(granule: Int) extends RawModule {
  val limits = Seq(8, 3, 2, 1)
  val io = IO(new Group8CecIO(granule))
  val bounded = io.counts.map(_ <= limits(granule).U).reduce(_ && _)
  val counts = io.counts.map(count => limits.indices.map(g =>
    if (g == granule) count else 0.U(4.W)))
  val group = AddressBucketGrouped.compact8(io.keys.toSeq, counts, limits)
  val result = AddressBucketGrouped.scatter(group, io.query, granule, limits(granule)).pad(64)
  io.result := Mux(bounded, result, 0.U(64.W))
}

class Group8CandidateGranule0 extends Group8CandidateGranule(0)
class Group8CandidateGranule1 extends Group8CandidateGranule(1)
class Group8CandidateGranule2 extends Group8CandidateGranule(2)
class Group8CandidateGranule3 extends Group8CandidateGranule(3)

class Group8ReferenceGranule(granule: Int) extends RawModule {
  val limits = Seq(8, 3, 2, 1)
  val io = IO(new Group8CecIO(granule))
  val bounded = io.counts.map(_ <= limits(granule).U).reduce(_ && _)
  val result = io.keys.indices.map(i => Mux(io.keys(i) === io.query,
    io.counts(i).pad(64), 0.U(64.W))).reduce(_ + _)
  io.result := Mux(bounded, result, 0.U(64.W))
}

class Group8ReferenceGranule0 extends Group8ReferenceGranule(0)
class Group8ReferenceGranule1 extends Group8ReferenceGranule(1)
class Group8ReferenceGranule2 extends Group8ReferenceGranule(2)
class Group8ReferenceGranule3 extends Group8ReferenceGranule(3)

class Group8EqProof(granule: Int) extends RawModule {
  val limits = Seq(8, 3, 2, 1)
  val io = IO(new Bundle {
    val keys = Input(Vec(8, UInt(8.W)))
    val counts = Input(Vec(8, UInt(4.W)))
    val query = Input(UInt(8.W))
    val equivalent = Output(Bool())
  })
  val bounded = io.counts.zipWithIndex.map { case (count, i) =>
    count <= limits(granule).U
  }.reduce(_ && _)
  val counts = io.counts.map(count => limits.indices.map(g =>
    if (g == granule) count else 0.U(4.W)))
  val group = AddressBucketGrouped.compact8(io.keys.toSeq, counts, limits)
  val ref = io.keys.indices.map(i => Mux(io.keys(i) === io.query,
    io.counts(i).pad(64), 0.U(64.W))).reduce(_ + _)
  io.equivalent := !bounded ||
    (AddressBucketGrouped.scatter(group, io.query, granule, limits(granule)) === ref)
}

class Group8EqProof0 extends Group8EqProof(0)
class Group8EqProof1 extends Group8EqProof(1)
class Group8EqProof2 extends Group8EqProof(2)
class Group8EqProof3 extends Group8EqProof(3)

class Group8TopologyProof extends RawModule {
  val limits = Seq(8, 3, 2, 1)
  val io = IO(new Bundle {
    val keys = Input(Vec(8, UInt(8.W)))
    val query = Input(UInt(8.W))
    val topology = Output(Bool())
  })
  val counts = io.keys.map(_ => limits.map(_ => 0.U(4.W)))
  val group = AddressBucketGrouped.compact8(io.keys.toSeq, counts, limits)
  val selected = group.map(e => e.last && e.key === io.query)
  io.topology := group.sliding(2).map(p => p(0).key <= p(1).key).reduce(_ && _) &&
    PopCount(selected) <= 1.U
}

class Group8BoundsProof(granule: Int) extends RawModule {
  val limits = Seq(8, 3, 2, 1)
  val io = IO(new Bundle {
    val keys = Input(Vec(8, UInt(8.W)))
    val counts = Input(Vec(8, UInt(4.W)))
    val inBounds = Output(Bool())
  })
  val bounded = io.counts.map(_ <= limits(granule).U).reduce(_ && _)
  val counts = io.counts.map(count => limits.indices.map(g =>
    if (g == granule) count else 0.U(4.W)))
  val group = AddressBucketGrouped.compact8(io.keys.toSeq, counts, limits)
  io.inBounds := !bounded || group.map(_.counts(granule) <= (8 * limits(granule)).U)
    .reduce(_ && _)
}

class Group8BoundsProof0 extends Group8BoundsProof(0)
class Group8BoundsProof1 extends Group8BoundsProof(1)
class Group8BoundsProof2 extends Group8BoundsProof(2)
class Group8BoundsProof3 extends Group8BoundsProof(3)

class Group8MutationProof0 extends RawModule {
  val limits = Seq(8, 3, 2, 1)
  val io = IO(new Bundle {
    val keys = Input(Vec(8, UInt(8.W)))
    val counts = Input(Vec(8, UInt(4.W)))
    val query = Input(UInt(8.W))
    val mutantEquivalent = Output(Bool())
  })
  val bounded = io.counts.map(_ <= limits(0).U).reduce(_ && _)
  val counts = io.counts.map(count => limits.indices.map(g =>
    if (g == 0) count else 0.U(4.W)))
  val group = AddressBucketGrouped.compact8(io.keys.toSeq, counts, limits)
  val mutant = group.updated(0, group(0).copy(last = false.B))
  val ref = io.keys.indices.map(i => Mux(io.keys(i) === io.query,
    io.counts(i).pad(64), 0.U(64.W))).reduce(_ + _)
  io.mutantEquivalent := !bounded ||
    (AddressBucketGrouped.scatter(mutant, io.query, 0, limits(0)) === ref)
}

class HistogramProbe(reference: Boolean = false) extends RawModule {
  val io = IO(new Bundle {
    val keys = Input(Vec(80, UInt(8.W)))
    val counts = Input(Vec(80, Vec(4, UInt(4.W))))
    val query = Input(UInt(8.W))
    val accumulator = Input(Vec(4, UInt(64.W)))
    val reset = Input(Bool())
    val buckets = Output(Vec(256, Vec(4, UInt(64.W))))
    val next = Output(Vec(4, UInt(65.W)) )
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
  else AddressBucketGrouped.histogram(io.keys.toSeq, io.counts.map(_.toSeq), limits, 256)
  io.buckets := histogram
  for (g <- limits.indices) io.next(g) := Mux(io.reset, 0.U(65.W),
    io.accumulator(g) +& histogram(io.query)(g))
}

object EmitGroup8 extends App {
  val stage = new chisel3.stage.ChiselStage
  args(0) match {
    case "candidate0" => stage.emitVerilog(new Group8CandidateGranule0, Array("--target-dir", args(1)))
    case "candidate1" => stage.emitVerilog(new Group8CandidateGranule1, Array("--target-dir", args(1)))
    case "candidate2" => stage.emitVerilog(new Group8CandidateGranule2, Array("--target-dir", args(1)))
    case "candidate3" => stage.emitVerilog(new Group8CandidateGranule3, Array("--target-dir", args(1)))
    case "reference0" => stage.emitVerilog(new Group8ReferenceGranule0, Array("--target-dir", args(1)))
    case "reference1" => stage.emitVerilog(new Group8ReferenceGranule1, Array("--target-dir", args(1)))
    case "reference2" => stage.emitVerilog(new Group8ReferenceGranule2, Array("--target-dir", args(1)))
    case "reference3" => stage.emitVerilog(new Group8ReferenceGranule3, Array("--target-dir", args(1)))
    case "eq0" => stage.emitVerilog(new Group8EqProof0, Array("--target-dir", args(1)))
    case "eq1" => stage.emitVerilog(new Group8EqProof1, Array("--target-dir", args(1)))
    case "eq2" => stage.emitVerilog(new Group8EqProof2, Array("--target-dir", args(1)))
    case "eq3" => stage.emitVerilog(new Group8EqProof3, Array("--target-dir", args(1)))
    case "topology" => stage.emitVerilog(new Group8TopologyProof, Array("--target-dir", args(1)))
    case "bounds0" => stage.emitVerilog(new Group8BoundsProof0, Array("--target-dir", args(1)))
    case "bounds1" => stage.emitVerilog(new Group8BoundsProof1, Array("--target-dir", args(1)))
    case "bounds2" => stage.emitVerilog(new Group8BoundsProof2, Array("--target-dir", args(1)))
    case "bounds3" => stage.emitVerilog(new Group8BoundsProof3, Array("--target-dir", args(1)))
    case "mutation" => stage.emitVerilog(new Group8MutationProof0, Array("--target-dir", args(1)))
    case "histogram" => stage.emitVerilog(new HistogramProbe, Array("--target-dir", args(1)))
    case "address" => stage.emitVerilog(new boom.lsu.PackageAddressStats(3, 40, 64, 256),
      Array("--target-dir", args(1)))
  }
}
