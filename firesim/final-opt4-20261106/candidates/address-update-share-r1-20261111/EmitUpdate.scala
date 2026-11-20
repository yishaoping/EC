package opt4update
import chisel3._
import chisel3.util._
import boom.lsu.AddressBucketUpdate

/** Inductive one-counter cut; delta has the full architectural 64-bit range. */
class UpdateProof extends RawModule {
  val io = IO(new Bundle {
    val valid = Input(Bool()); val counter = Input(UInt(64.W)); val delta = Input(UInt(64.W))
    val current = Input(Bool()); val event = Input(Bool()); val retire = Input(Bool()); val reset = Input(Bool())
    val equivalent = Output(Bool()); val invariantStep = Output(Bool()); val currentSumEqual = Output(Bool())
    val mutationEquivalent = Output(Bool())
  })
  val invariant = io.valid || io.counter === 0.U
  val wide = io.counter +& io.delta
  val oldCurrentWide = Mux(io.valid, io.counter, 0.U(64.W)) +& io.delta
  val guard = io.valid || io.current || !io.delta.orR
  val commit = io.event && guard && !wide(64)
  val retiring = !io.event && io.retire
  val oldUpdated = Mux(io.current, oldCurrentWide(63,0),
    Mux(io.delta.orR, wide(63,0), io.counter))
  val newUpdated = Mux(AddressBucketUpdate.enabled(io.current, io.delta), wide(63,0), io.counter)
  val oldNext = Mux(io.reset || retiring, 0.U(64.W), Mux(commit, oldUpdated, io.counter))
  val newNext = Mux(io.reset || retiring, 0.U(64.W), Mux(commit, newUpdated, io.counter))
  val nextValid = !io.reset && !retiring && (io.valid || commit && io.current)
  val mutant = Mux(retiring, 0.U(64.W), Mux(commit, newUpdated, io.counter))
  io.equivalent := !invariant || oldNext === newNext
  io.invariantStep := !invariant || nextValid || newNext === 0.U
  io.currentSumEqual := !invariant || wide === oldCurrentWide
  io.mutationEquivalent := !invariant || oldNext === mutant
}

/** Every legal nonzero hit must target a valid slot; all 32 tag bits retained. */
class QualifiedProof extends RawModule {
  val io = IO(new Bundle {
    val seq = Input(UInt(32.W)); val tags = Input(Vec(256,UInt(32.W)))
    val valid = Input(UInt(256.W)); val hit = Input(Bool()); val count = Input(UInt(64.W))
    val legal = Output(Bool())
  })
  val idx=io.seq(7,0)
  val qualifiedError=io.hit && (!io.valid(idx) || io.tags(idx)(31,8) =/= io.seq(31,8))
  io.legal := !(!qualifiedError && io.hit && io.count.orR) || io.valid(idx)
}

/** Actual 256 slots, five counter categories and complete 64-bit overflow. */
class UpdateProbe extends RawModule {
  val io = IO(new Bundle {
    val words=Input(Vec(256,Vec(5,UInt(64.W)))); val delta=Input(Vec(256,Vec(5,UInt(64.W))))
    val valid=Input(UInt(256.W)); val current=Input(UInt(8.W)); val retiring=Input(UInt(8.W))
    val event=Input(Bool()); val retire=Input(Bool()); val reset=Input(Bool())
    val next=Output(Vec(256,Vec(5,UInt(64.W)))); val arithmeticError=Output(Bool())
  })
  val carries=collection.mutable.ArrayBuffer[Bool]()
  for(i<-0 until 256; g<-0 until 5) {
    val current=io.current===i.U
    val sum=io.words(i)(g)+&io.delta(i)(g)
    carries += (if(g<2) current && sum(64) else sum(64))
    val enabled=if(g<2) current else AddressBucketUpdate.enabled(current,io.delta(i)(g))
    val updated=Mux(io.event && enabled,sum(63,0),io.words(i)(g))
    io.next(i)(g):=Mux(io.reset || !io.event && io.retire && io.retiring===i.U,0.U(64.W),updated)
  }
  io.arithmeticError:=carries.reduce(_||_)
}
object EmitUpdate extends App {
 val s=new chisel3.stage.ChiselStage
 args(0) match {
  case "proof"=>s.emitVerilog(new UpdateProof,Array("--target-dir",args(1)))
  case "qualified"=>s.emitVerilog(new QualifiedProof,Array("--target-dir",args(1)))
  case "boundary"=>s.emitVerilog(new UpdateProbe,Array("--target-dir",args(1)))
  case "address"=>s.emitVerilog(new boom.lsu.PackageAddressStats(3,40,64,256),Array("--target-dir",args(1)))
 }
}
