package opt4async

import chisel3._
import chisel3.util._
import boom.lsu.AddressCurrentBucketMemory

/** Inductive payload relation: valid words agree, invalid words are arbitrary.
  * ResetStats clears the reference payload. A global reset clears validity
  * alone. Retirement cannot coincide with processValid, including an error.
  */
class AsyncProof extends RawModule {
  val io = IO(new Bundle {
    val valid=Input(Bool()); val current=Input(Bool())
    val processValid=Input(Bool()); val eventEnable=Input(Bool())
    val retireReq=Input(Bool()); val resetStats=Input(Bool()); val globalReset=Input(Bool())
    val oldWord=Input(UInt(64.W)); val newWord=Input(UInt(64.W)); val delta=Input(UInt(64.W))
    val equivalent=Output(Bool()); val overflowEquivalent=Output(Bool())
    val nextEquivalent=Output(Bool()); val mutationEquivalent=Output(Bool())
  })
  val invariant = !io.valid || io.oldWord === io.newWord
  val oldSum = Mux(io.valid,io.oldWord,0.U(64.W)) +& io.delta
  val newSum = AddressCurrentBucketMemory.sum(io.valid,io.newWord,io.delta)
  val event = io.processValid && io.eventEnable
  val retire = !io.processValid && io.retireReq && io.valid
  val nextValid = !io.resetStats && !io.globalReset &&
    ((io.valid && !retire) || event && io.current)
  val oldNext = Mux(io.resetStats,0.U(64.W),
    Mux(retire,0.U(64.W),Mux(event && io.current,oldSum(63,0),io.oldWord)))
  val newNext = Mux(event && io.current && !io.resetStats,newSum(63,0),io.newWord)
  val observableEqual = !io.valid || io.oldWord === io.newWord
  val nextEqual = !nextValid || oldNext === newNext
  val overflowEqual = oldSum(64) === newSum(64)
  val mutantSum = io.newWord +& io.delta
  val mutantNext = Mux(event && io.current && !io.resetStats,mutantSum(63,0),io.newWord)
  io.overflowEquivalent := !invariant || overflowEqual
  io.nextEquivalent := !invariant || nextEqual
  io.equivalent := !invariant || (observableEqual && nextEqual && overflowEqual)
  io.mutationEquivalent := !invariant || (!nextValid || oldNext === mutantNext)
}

/** Actual 256x512 memory, arbitrary payload injection and 64-bit carry cuts. */
class AsyncMemoryProbe extends Module {
  val io=IO(new Bundle {
    val currentIndex=Input(UInt(8.W)); val retiringIndex=Input(UInt(8.W))
    val writeEnable=Input(Bool()); val writeData=Input(Vec(2,Vec(4,UInt(64.W))))
    val currentValid=Input(Bool()); val retiringValid=Input(Bool())
    val delta=Input(Vec(2,Vec(4,UInt(64.W))))
    val current=Output(Vec(2,Vec(4,UInt(64.W))))
    val retiring=Output(Vec(2,Vec(4,UInt(64.W))))
    val next=Output(Vec(2,Vec(4,UInt(64.W))))
    val overflow=Output(Vec(2,Vec(4,Bool())))
  })
  val m=Module(new AddressCurrentBucketMemory(256))
  m.io.currentIndex:=io.currentIndex; m.io.retiringIndex:=io.retiringIndex
  m.io.writeEnable:=io.writeEnable; m.io.writeData:=io.writeData
  for(c<-0 until 2;g<-0 until 4) {
    val sum=AddressCurrentBucketMemory.sum(io.currentValid,m.io.current(c)(g),io.delta(c)(g))
    io.current(c)(g):=m.io.current(c)(g)
    io.retiring(c)(g):=AddressCurrentBucketMemory.base(io.retiringValid,m.io.retiring(c)(g))
    io.next(c)(g):=sum(63,0); io.overflow(c)(g):=sum(64)
  }
}

object EmitAsync extends App {
  val s=new chisel3.stage.ChiselStage
  args(0) match {
    case "proof" => s.emitVerilog(new AsyncProof,Array("--target-dir",args(1)))
    case "memory" => s.emitVerilog(new AddressCurrentBucketMemory(256),Array("--target-dir",args(1)))
    case "boundary" => s.emitVerilog(new AsyncMemoryProbe,Array("--target-dir",args(1)))
    case "address" => s.emitVerilog(new boom.lsu.PackageAddressStats(3,40,64,256),Array("--target-dir",args(1)))
  }
}
