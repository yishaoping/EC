package opt4read
import chisel3._
import chisel3.util._
import boom.lsu.OneHotBucketRead
class ReadProbe extends RawModule {
 val io=IO(new Bundle {
  val words=Input(Vec(256,UInt(64.W)));val index=Input(UInt(8.W))
  val selected=Output(UInt(64.W));val equivalent=Output(Bool());val mutationEquivalent=Output(Bool())
 })
 val selected=OneHotBucketRead(io.words.toSeq,UIntToOH(io.index,256))
 io.selected:=selected
 io.equivalent:=selected===io.words(io.index)
 io.mutationEquivalent:=(selected^1.U)===io.words(io.index)
}
object EmitRead extends App {
 val s=new chisel3.stage.ChiselStage
 args(0) match {
  case "proof"|"boundary"=>s.emitVerilog(new ReadProbe,Array("--target-dir",args(1)))
  case "address"=>s.emitVerilog(new boom.lsu.PackageAddressStats(3,40,64,256),Array("--target-dir",args(1)))
 }
}
