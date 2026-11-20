package opt4retirestatic
import chisel3._
import chisel3.util._

// Exact original nested dynamic Vec clear versus constant-slot decode.
// The incoming words can be the result of any preceding update, including
// simultaneous process writes. This proves last-connect priority too.
class RetireClearProof extends RawModule {
  val io=IO(new Bundle {
    val words=Input(Vec(256,Vec(4,UInt(1.W))))
    val valid=Input(UInt(256.W));val index=Input(UInt(8.W))
    val enable=Input(Bool());val resetStats=Input(Bool())
    val equivalent=Output(Bool());val mutationEquivalent=Output(Bool())
  })
  val reference=WireDefault(io.words)
  val candidate=WireDefault(io.words)
  val referenceValid=WireDefault(VecInit(io.valid.asBools))
  val candidateValid=WireDefault(VecInit(io.valid.asBools))
  when(io.enable && io.valid(io.index)) {
    referenceValid(io.index):=false.B
    for(g<-0 until 4) reference(io.index)(g):=0.U
  }
  for(i<-0 until 256) {
    when(io.enable && io.index===i.U && io.valid(i)) {
      candidateValid(i):=false.B
      for(g<-0 until 4) candidate(i)(g):=0.U
    }
  }
  when(io.resetStats) {
    reference:=0.U.asTypeOf(reference)
    candidate:=0.U.asTypeOf(candidate)
  }
  io.equivalent:=reference.asUInt===candidate.asUInt && referenceValid.asUInt===candidateValid.asUInt
  io.mutationEquivalent:=reference.asUInt===(candidate.asUInt ^ 1.U)
}
object Emit extends App {
  val stage=new chisel3.stage.ChiselStage
  args(0) match {
    case "proof"=>stage.emitVerilog(new RetireClearProof,Array("--target-dir",args(1)))
    case "address"=>stage.emitVerilog(new boom.lsu.PackageAddressStats(3,40,64,256),Array("--target-dir",args(1)))
  }
}
