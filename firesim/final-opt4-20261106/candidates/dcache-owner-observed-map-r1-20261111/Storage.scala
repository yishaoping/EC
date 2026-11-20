package opt4ownerobserved
import chisel3._
import chisel3.util._

// Area screen only. All reads remain asynchronous, and reset remains a
// synchronous read-as-zero state transition, with reset dominating writes.
class OwnerPayload extends Bundle {
 val image=new freechips.rocketchip.tilelink.CacheImageKey
 val generation=UInt(32.W)
 val packetSeq=UInt(32.W)
 val tracked=Bool()
}
object CanonicalOwner {
 def apply(data:UInt):OwnerPayload={
  // Exact aliases in both source write sites. This allows synthesis to retain
  // true register/data equivalences; generic unrelated146-bit inputs do not.
  val v=Wire(new OwnerPayload)
  val key=data(145,65).asTypeOf(new freechips.rocketchip.tilelink.CacheImageKey)
  v.image:=key;v.generation:=key.generation;v.packetSeq:=key.contentSeq
  v.tracked:=key.valid && key.contentSeq=/=0.U
  v
 }
}
class StoragePorts(val bits:Int,val readers:Int) extends Bundle {
  val debugGeneration=Output(Vec(512,UInt(32.W)))
  val writeEnable=Input(Bool())
  val writeIndex=Input(UInt(9.W))
  val writeData=Input(UInt(bits.W))
  val readIndex=Input(Vec(readers,UInt(9.W)))
  val readData=Output(Vec(readers,UInt(bits.W)))
}
class RegisterReference(bits:Int,readers:Int) extends Module {
 val io=IO(new StoragePorts(bits,readers))
 // Preserve actual256sets x2ways nested source topology.
 val words=RegInit(VecInit(Seq.fill(256)(VecInit(Seq.fill(2)(0.U.asTypeOf(new OwnerPayload))))))
 when(io.writeEnable){words(io.writeIndex(8,1))(io.writeIndex(0)):=CanonicalOwner(io.writeData)}
 for(r<-0 until readers) io.readData(r):=words(io.readIndex(r)(8,1))(io.readIndex(r)(0)).asUInt
 for(i<-0 until 512)io.debugGeneration(i):=words(i/2)(i%2).generation
}
class AsyncCandidate(bits:Int,readers:Int) extends Module {
 val io=IO(new StoragePorts(bits,readers))
 val written=RegInit(VecInit(Seq.fill(512)(false.B)))
 val payload=Mem(512,new OwnerPayload)
 when(io.writeEnable && !reset.asBool){
  payload.write(io.writeIndex,CanonicalOwner(io.writeData))
  written(io.writeIndex):=true.B
 }
 for(r<-0 until readers) io.readData(r):=Mux(written(io.readIndex(r)),payload.read(io.readIndex(r)).asUInt,0.U(bits.W))
 for(i<-0 until 512)io.debugGeneration(i):=Mux(written(i),payload.read(i.U).generation,0.U(32.W))
}

// Inductive transition at exact512entry geometry, one data bit. Data-independent
// decode/hold/mask lifts bitwise to all146bits, including arbitrary payload.
class StorageInduction extends RawModule {
 val io=IO(new Bundle {
  val raw=Input(UInt(512.W));val written=Input(UInt(512.W))
  val data=Input(Bool());val writeEnable=Input(Bool());val reset=Input(Bool())
  val index=Input(UInt(9.W));val readIndex=Input(UInt(9.W))
  val equivalent=Output(Bool());val mutationEquivalent=Output(Bool())
 })
 val ref=WireDefault(VecInit((io.raw & io.written).asBools))
 val raw=WireDefault(VecInit(io.raw.asBools));val valid=WireDefault(VecInit(io.written.asBools))
 when(io.writeEnable){ref(io.index):=io.data}
 when(io.writeEnable && !io.reset){raw(io.index):=io.data;valid(io.index):=true.B}
 when(io.reset){ref:=0.U.asTypeOf(ref);valid:=0.U.asTypeOf(valid)}
 val candidate=raw.asUInt & valid.asUInt
 // Whole next-state relation and arbitrary asynchronous read both checked.
 io.equivalent:=ref.asUInt===candidate && ref(io.readIndex)===candidate(io.readIndex)
 io.mutationEquivalent:=ref.asUInt===(candidate ^ 1.U)
}
class StoragePair extends Module {
 val io=IO(new Bundle {
  val writeEnable=Input(Bool());val writeIndex=Input(UInt(9.W));val writeData=Input(UInt(146.W))
  val readIndex=Input(Vec(8,UInt(9.W)));val equal=Output(Bool());val checksum=Output(UInt(146.W))
 })
 val a=Module(new RegisterReference(146,8));val b=Module(new AsyncCandidate(146,8))
 for(m<-Seq(a.io,b.io)){m.writeEnable:=io.writeEnable;m.writeIndex:=io.writeIndex;m.writeData:=io.writeData;m.readIndex:=io.readIndex}
 io.equal:=a.io.readData.asUInt===b.io.readData.asUInt && a.io.debugGeneration.asUInt===b.io.debugGeneration.asUInt
 io.checksum:=a.io.readData.reduce(_ ^ _)
}
object Emit extends App {
 val s=new chisel3.stage.ChiselStage
 args(0) match {
  case "reference"=>s.emitVerilog(new RegisterReference(146,12),Array("--target-dir",args(1)))
  case "candidate"=>s.emitVerilog(new AsyncCandidate(146,12),Array("--target-dir",args(1)))
  case "pair"=>s.emitVerilog(new StoragePair,Array("--target-dir",args(1)))
  case "proof"=>s.emitVerilog(new StorageInduction,Array("--target-dir",args(1)))
 }
}
