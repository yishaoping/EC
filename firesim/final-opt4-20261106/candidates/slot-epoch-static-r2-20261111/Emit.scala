package opt4epochstatic
import chisel3._
import chisel3.util._
import boom.lsu.SlotEpochBank

class EpochPorts extends Bundle {
  val enable = Input(UInt(3.W))
  val index = Input(Vec(3, UInt(9.W)))
  val refill = Input(UInt(16.W))
  val readIndex = Input(Vec(12, UInt(9.W)))
  val readData = Output(Vec(12, UInt(16.W)))
  val snapshot = Output(Vec(512, UInt(16.W)))
}
class EpochReference extends Module {
  val io = IO(new EpochPorts)
  val words = RegInit(VecInit(Seq.fill(256)(VecInit(Seq.fill(2)(0.U(16.W))))))
  def read(a: UInt): UInt = words(a(8, 1))(a(0))
  // Exact source ordering: probe increment, clear increment, refill assignment.
  when(io.enable(0)) { words(io.index(0)(8,1))(io.index(0)(0)) := read(io.index(0)) + 1.U }
  when(io.enable(1)) { words(io.index(1)(8,1))(io.index(1)(0)) := read(io.index(1)) + 1.U }
  when(io.enable(2)) { words(io.index(2)(8,1))(io.index(2)(0)) := io.refill }
  for(r <- 0 until 12) io.readData(r) := read(io.readIndex(r))
  io.snapshot := VecInit((0 until 256).flatMap(s => (0 until 2).map(w => words(s)(w))))
}
class EpochCandidate extends Module {
  val io = IO(new EpochPorts)
  val bank = new SlotEpochBank(256, 2)
  for(p <- 0 until 3) {
    val a = io.index(p)
    when(io.enable(p)) {
      bank.write(p, a(8,1), a(0),
        if(p == 2) io.refill else bank.read(a(8,1), a(0)) + 1.U)
    }
  }
  for(r <- 0 until 12) {
    val a = io.readIndex(r)
    io.readData(r) := bank.read(a(8,1), a(0))
  }
  io.snapshot := bank.snapshot
}
class EpochPair extends Module {
  val io = IO(new Bundle {
    val enable = Input(UInt(3.W))
    val index = Input(Vec(3, UInt(9.W)))
    val refill = Input(UInt(16.W))
    val readIndex = Input(Vec(12, UInt(9.W)))
    val equal = Output(Bool())
    val checksum = Output(UInt(16.W))
  })
  val a=Module(new EpochReference);val b=Module(new EpochCandidate)
  for(m <- Seq(a.io,b.io)) {
    m.enable:=io.enable;m.index:=io.index;m.refill:=io.refill;m.readIndex:=io.readIndex
  }
  io.equal := a.io.snapshot.asUInt === b.io.snapshot.asUInt &&
    a.io.readData.asUInt === b.io.readData.asUInt
  io.checksum := b.io.snapshot.reduce(_ ^ _) ^ b.io.readData.reduce(_ ^ _)
}
// Exact 512-entry transition cut. Hold/data/priority/read decode have no
// dependence on payload bit number, so this equality lifts to all sixteen bits.
// Increment values are arbitrary data at this cut, computed from the same old
// 16-bit word in the source. The full-width boundary checks overflow directly.
class EpochTransition extends RawModule {
  val io=IO(new Bundle {
    val old=Input(UInt(512.W));val enable=Input(UInt(3.W))
    val index=Input(Vec(3,UInt(9.W)));val data=Input(UInt(3.W))
    val synchronousReset=Input(Bool());val readIndex=Input(UInt(9.W))
    val equivalent=Output(Bool());val mutationEquivalent=Output(Bool())
  })
  val ref=WireDefault(VecInit(io.old.asBools))
  val cand=WireDefault(VecInit(io.old.asBools))
  for(p <- 0 until 3) { when(io.enable(p)) { ref(io.index(p)):=io.data(p) } }
  for(i <- 0 until 512; p <- 0 until 3) {
    when(io.enable(p) && io.index(p)===i.U) { cand(i):=io.data(p) }
  }
  when(io.synchronousReset) { ref:=0.U.asTypeOf(ref);cand:=0.U.asTypeOf(cand) }
  val selected=Mux1H((0 until 512).map(i => (io.readIndex===i.U) -> cand(i)))
  io.equivalent:=ref.asUInt===cand.asUInt && ref(io.readIndex)===selected
  // A genuine priority mutation on the 0/2 collision must be rejected.
  val mutant=WireDefault(cand)
  when(!io.synchronousReset && io.enable(0) && io.enable(2) && io.index(0)===io.index(2)) {
    mutant(io.index(0)):=io.data(0)
  }
  io.mutationEquivalent:=ref.asUInt===mutant.asUInt
}
object Emit extends App {
  val stage=new chisel3.stage.ChiselStage
  args(0) match {
    case "proof" => stage.emitVerilog(new EpochTransition,Array("--target-dir",args(1)))
    case "pair" => stage.emitVerilog(new EpochPair,Array("--target-dir",args(1)))
    case "reference" => stage.emitVerilog(new EpochReference,Array("--target-dir",args(1)))
    case "candidate" => stage.emitVerilog(new EpochCandidate,Array("--target-dir",args(1)))
  }
}
