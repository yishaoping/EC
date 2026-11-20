package opt4dcacheresult

import chisel3._
import chisel3.util._
import boom.lsu.AppliedEffectResultMemory

class ReferenceResultMemory(sets: Int, ways: Int, bits: Int) extends Module {
  val io = IO(new Bundle {
    val readSet = Input(Vec(2, UInt(log2Ceil(sets).W)))
    val readWay = Input(Vec(2, UInt(log2Ceil(ways).W)))
    val readData = Output(Vec(2, UInt(bits.W)))
    val writeEnable = Input(Bool())
    val writeSet = Input(UInt(log2Ceil(sets).W))
    val writeWay = Input(UInt(log2Ceil(ways).W))
    val writeData = Input(UInt(bits.W))
  })
  // Exact declaration/access pattern from the parent DCache.
  val appliedEffectResult = Reg(Vec(sets, Vec(ways, UInt(bits.W))))
  for (r <- 0 until 2) io.readData(r) := appliedEffectResult(io.readSet(r))(io.readWay(r))
  when (io.writeEnable) { appliedEffectResult(io.writeSet)(io.writeWay) := io.writeData }
}

/** Arbitrary-state, arbitrary-address one-word induction plus flattening.
  * Full payload equality is an invariant, without reset assumptions or validity
  * masking. The negative mutation flips a retained payload bit.
  */
class ResultWordProof(sets: Int, ways: Int) extends RawModule {
  val io=IO(new Bundle {
    val set=Input(UInt(log2Ceil(sets).W)); val way=Input(UInt(log2Ceil(ways).W))
    val writeSet=Input(UInt(log2Ceil(sets).W)); val writeWay=Input(UInt(log2Ceil(ways).W))
    val oldWord=Input(UInt(64.W)); val newWord=Input(UInt(64.W)); val data=Input(UInt(64.W))
    val enable=Input(Bool()); val reset=Input(Bool())
    val indexEquivalent=Output(Bool()); val nextEquivalent=Output(Bool()); val mutantEquivalent=Output(Bool())
  })
  val refHit=io.set===io.writeSet && io.way===io.writeWay
  val newHit=AppliedEffectResultMemory.index(io.set,io.way)===AppliedEffectResultMemory.index(io.writeSet,io.writeWay)
  io.indexEquivalent := refHit===newHit
  val oldNext=Mux(io.enable && refHit,io.data,io.oldWord)
  val newNext=Mux(io.enable && newHit,io.data,io.newWord)
  io.nextEquivalent := io.oldWord=/=io.newWord || oldNext===newNext
  val mutant=Mux(io.enable && newHit,io.data ^ "h8000000000000000".U,io.newWord)
  io.mutantEquivalent := io.oldWord=/=io.newWord || oldNext===mutant
}

class ResultMemoryPair(sets: Int,ways: Int) extends Module {
  val io=IO(new Bundle {
    val readSet=Input(Vec(2,UInt(log2Ceil(sets).W)))
    val readWay=Input(Vec(2,UInt(log2Ceil(ways).W)))
    val writeEnable=Input(Bool()); val writeSet=Input(UInt(log2Ceil(sets).W))
    val writeWay=Input(UInt(log2Ceil(ways).W));val writeData=Input(UInt(64.W))
    val reference=Output(Vec(2,UInt(64.W)));val candidate=Output(Vec(2,UInt(64.W)))
  })
  val reference=Module(new ReferenceResultMemory(sets,ways,64))
  val candidate=Module(new AppliedEffectResultMemory(sets,ways,64))
  reference.io.readSet:=io.readSet;reference.io.readWay:=io.readWay
  reference.io.writeEnable:=io.writeEnable;reference.io.writeSet:=io.writeSet
  reference.io.writeWay:=io.writeWay;reference.io.writeData:=io.writeData
  candidate.io.readSet:=io.readSet;candidate.io.readWay:=io.readWay
  candidate.io.writeEnable:=io.writeEnable;candidate.io.writeSet:=io.writeSet
  candidate.io.writeWay:=io.writeWay;candidate.io.writeData:=io.writeData
  io.reference:=reference.io.readData;io.candidate:=candidate.io.readData
}

object Emit extends App {
  import freechips.rocketchip.subsystem._
  val base=new firesim.firesim.DacOpt4C4().toInstance
  val tile=base(TilesLocated(InSubsystem)).map(_.tileParams).find(_.hartId==0).get
  val d=tile.dcache.get
  // Bound to actual target parameters, not an assumed power-of-two cut.
  require(d.nSets==64 && d.nWays==8)
  println(s"ACTUAL_RESULT_MEMORY sets=${d.nSets} ways=${d.nWays} bits=64")
  val s=new chisel3.stage.ChiselStage
  args(0) match {
    case "proof" => s.emitVerilog(new ResultWordProof(d.nSets,d.nWays),Array("--target-dir",args(1)))
    case "reference" => s.emitVerilog(new ReferenceResultMemory(d.nSets,d.nWays,64),Array("--target-dir",args(1)))
    case "candidate" => s.emitVerilog(new AppliedEffectResultMemory(d.nSets,d.nWays,64),Array("--target-dir",args(1)))
    case "pair" => s.emitVerilog(new ResultMemoryPair(d.nSets,d.nWays),Array("--target-dir",args(1)))
  }
}
