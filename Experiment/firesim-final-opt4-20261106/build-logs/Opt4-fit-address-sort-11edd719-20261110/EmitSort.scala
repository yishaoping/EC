package opt4fit
import chisel3._
import chisel3.util._
class Scatter(n: Int, buckets: Int, reference: Boolean) extends RawModule {
  val io = IO(new Bundle {
    val keys = Input(UInt((n*log2Ceil(buckets)).W))
    val terms = Input(UInt((n*9).W))
    val result = Output(UInt((buckets*256).W))
  })
  val kb = log2Ceil(buckets)
  val keys = (0 until n).map(i => io.keys((i+1)*kb-1,i*kb))
  val widths = Seq(4,2,2,1)
  val offsets = Seq(0,4,6,8)
  val values = (0 until n).map(i => widths.indices.map(g =>
    io.terms(i*9+offsets(g)+widths(g)-1,i*9+offsets(g))))
  val out = if (!reference) boom.lsu.AddressBucketReduction(keys,values,Seq(8,3,2,1),buckets)
    else (0 until buckets).map(b => widths.indices.map(g =>
      keys.indices.map(i => Mux(keys(i) === b.U,values(i)(g).pad(64),0.U(64.W))).reduce(_ + _)))
  io.result := VecInit(out.map(x => VecInit(x))).asUInt
}
class SortZeroOne extends RawModule {
  val io = IO(new Bundle { val keys = Input(UInt(128.W)); val ok = Output(Bool()) })
  val keys = (0 until 128).map(i => io.keys(i).asUInt)
  val sorted = boom.lsu.AddressBucketReduction.sortRows(keys,keys.map(_ => Seq(0.U(1.W))),Seq(1),1)
  io.ok := (0 until 127).map(i => sorted(i)._1 <= sorted(i+1)._1).reduce(_ && _)
}
class ComparatorProof extends RawModule {
  val io = IO(new Bundle { val keys = Input(UInt(16.W)); val terms = Input(UInt(18.W)); val ok = Output(Bool()) })
  val keys = Seq(io.keys(7,0),io.keys(15,8))
  val terms = Seq(Seq(io.terms(8,0)),Seq(io.terms(17,9)))
  val s = boom.lsu.AddressBucketReduction.sortRows(keys,terms,Seq(9),8)
  val before = keys.zip(terms).map { case (k,v) => Cat(0.U(1.W),k,v.head) }
  val after = s.map { case (k,v) => Cat(k,v.head) }
  io.ok := (s(0)._1 <= s(1)._1) &&
    ((after(0) === before(0) && after(1) === before(1)) ||
     (after(0) === before(1) && after(1) === before(0)))
}
object EmitSort extends App {
  val stage = new chisel3.stage.ChiselStage
  args(0) match {
    case "address" => stage.emitVerilog(new boom.lsu.PackageAddressStats(3,40,64,256),Array("--target-dir",args(1)))
    case "zero-one" => stage.emitVerilog(new SortZeroOne,Array("--target-dir",args(1)))
    case "comparator" => stage.emitVerilog(new ComparatorProof,Array("--target-dir",args(1)))
    case mode => stage.emitVerilog(new Scatter(args(2).toInt,args(3).toInt,mode == "reference"),Array("--target-dir",args(1)))
  }
}
