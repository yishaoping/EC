package opt4packedarea
import chisel3._
import chisel3.util._
class Bucket(reference: Boolean) extends RawModule {
  override def desiredName = "FPGATop"
  val io = IO(new Bundle {
    val keys = Input(Vec(80, UInt(8.W)))
    val counts = Input(Vec(80, Vec(4, UInt(4.W))))
    val result = Output(Vec(4, UInt(64.W)))
  })
  val bounds = Seq(8,3,2,1)
  val all = if (reference) boom.lsu.AddressBucketGroupedReference.histogram(
    io.keys.toSeq, io.counts.map(_.toSeq), bounds, 256)
  else boom.lsu.AddressBucketGrouped.histogram(
    io.keys.toSeq, io.counts.map(_.toSeq), bounds, 256)
  io.result := all(0)
}
object Emit extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new Bucket(args(0) == "reference"),
    Array("--target-dir", args(1)))
}
