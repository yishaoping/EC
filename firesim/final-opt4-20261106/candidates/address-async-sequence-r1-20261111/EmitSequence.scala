package opt4sequence

import chisel3._
import chisel3.util._
import boom.lsu.{AddressBucketSequenceMemory,PackageAddressStats}

/** One-word induction cut. Invalid payload is deliberately unconstrained.
  * The enclosing source proves retirement cannot overlap processValid.
  * This cut preserves the inherited valid-slot low-sequence-bit invariant.
  */
class SequenceProof extends RawModule {
  val io=IO(new Bundle {
    val valid=Input(Bool()); val current=Input(Bool())
    val processValid=Input(Bool()); val eventEnable=Input(Bool())
    val retireReq=Input(Bool()); val resetStats=Input(Bool()); val globalReset=Input(Bool())
    val oldWord=Input(UInt(32.W)); val newWord=Input(UInt(32.W)); val sequence=Input(UInt(32.W))
    val equivalent=Output(Bool()); val nextEquivalent=Output(Bool())
    val mutationEquivalent=Output(Bool())
  })
  val invariant = !io.valid || io.oldWord === io.newWord
  val event = io.processValid && io.eventEnable && io.current
  val retire = !io.processValid && io.retireReq && io.valid
  val nextValid = !io.resetStats && !io.globalReset && ((io.valid && !retire) || event)
  val oldNext = Mux(io.resetStats,0.U(32.W),Mux(event,io.sequence,io.oldWord))
  val newNext = Mux(event && !io.resetStats,io.sequence,io.newWord)
  val oldMatch = io.oldWord(31,8) === io.sequence(31,8)
  val newMatch = AddressBucketSequenceMemory.matches(io.newWord,io.sequence,8)
  io.equivalent := !invariant || (!io.valid || oldMatch === newMatch)
  io.nextEquivalent := !invariant || (!nextValid || oldNext === newNext)
  val mutantNext = Mux(event && !io.resetStats,io.sequence ^ "h80000000".U,io.newWord)
  io.mutationEquivalent := !invariant || (!nextValid || oldNext === mutantNext)
}

object EmitSequence extends App {
  val s=new chisel3.stage.ChiselStage
  args(0) match {
    case "proof" => s.emitVerilog(new SequenceProof,Array("--target-dir",args(1)))
    case "memory" => s.emitVerilog(new AddressBucketSequenceMemory(256,90),Array("--target-dir",args(1)))
    case "address" => s.emitVerilog(new PackageAddressStats(3,40,64,256),Array("--target-dir",args(1)))
  }
}
