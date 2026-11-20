package opt4installedimage
import chisel3._
import chisel3.util._
import freechips.rocketchip.tilelink.CacheImageKey

class Ports extends Bundle {
  val write = Input(Bool())
  val set = Input(UInt(8.W))
  val way = Input(UInt(1.W))
  val data = Input(new CacheImageKey)
  val readSet = Input(UInt(8.W))
  val readWay = Input(UInt(1.W))
  val result = Output(new CacheImageKey)
}
class InstalledReference extends Module {
  val io=IO(new Ports)
  val installedImage=Reg(Vec(256,Vec(2,new CacheImageKey)))
  when(io.write) { installedImage(io.set)(io.way):=io.data }
  io.result:=installedImage(io.readSet)(io.readWay)
}
class InstalledCandidate extends Module {
  val io=IO(new Ports)
  val installedImage=Mem(512,new CacheImageKey)
  when(io.write) { installedImage.write(Cat(io.set,io.way),io.data) }
  io.result:=installedImage.read(Cat(io.readSet,io.readWay))
}
class InstalledPair extends Module {
  val io=IO(new Bundle {
    val write=Input(Bool());val index=Input(UInt(9.W));val data=Input(UInt(81.W))
    val readIndex=Input(UInt(9.W))
    val reference=Output(UInt(81.W));val candidate=Output(UInt(81.W))
  })
  val a=Module(new InstalledReference);val b=Module(new InstalledCandidate)
  for(x<-Seq(a.io,b.io)) {
    x.write:=io.write;x.set:=io.index(8,1);x.way:=io.index(0)
    x.data:=io.data.asTypeOf(new CacheImageKey)
    x.readSet:=io.readIndex(8,1);x.readWay:=io.readIndex(0)
  }
  io.reference:=a.io.result.asUInt;io.candidate:=b.io.result.asUInt
}
// Explicit arbitrary-state cut: flattening is a bijection over all512 words.
// Each output bit uses the same independent hold/write and address expression.
// No reset operation exists in either actual payload implementation.
class InstalledTransition extends RawModule {
  val io=IO(new Bundle {
    val old=Input(UInt(512.W));val write=Input(Bool());val writeIndex=Input(UInt(9.W))
    val data=Input(Bool());val readIndex=Input(UInt(9.W))
    val reset=Input(Bool())
    val equivalent=Output(Bool());val mutationEquivalent=Output(Bool())
  })
  val nested=WireDefault(VecInit((0 until 256).map(s=>VecInit((0 until 2).map(w=>io.old(2*s+w))))))
  when(io.write) { nested(io.writeIndex(8,1))(io.writeIndex(0)):=io.data }
  val flat=WireDefault(VecInit(io.old.asBools))
  for(i<-0 until 512) { when(io.write && io.writeIndex===i.U) { flat(i):=io.data } }
  val ref=VecInit((0 until 256).flatMap(s=>(0 until 2).map(w=>nested(s)(w))))
  io.equivalent:=ref.asUInt===flat.asUInt && nested(io.readIndex(8,1))(io.readIndex(0))===flat(io.readIndex)
  // Real payload-write mutation, independent of reset and address assumptions.
  val mutant=WireDefault(flat)
  when(io.write) { mutant(io.writeIndex):= !io.data }
  io.mutationEquivalent:=ref.asUInt===mutant.asUInt
}
object Emit extends App {
  import freechips.rocketchip.subsystem._
  val base=new firesim.firesim.DacOpt4C4().toInstance
  val tile=base(TilesLocated(InSubsystem)).map(_.tileParams).find(_.hartId==0).get
  require(tile.dcache.get.nSets==256 && tile.dcache.get.nWays==2)
  val key=new CacheImageKey
  require(key.getWidth==81)
  println(s"INSTALLED_ACTUAL_GEOMETRY sets=256 ways=2 bits=${key.getWidth} reset=uninitialized class_origin=${classOf[CacheImageKey].getProtectionDomain.getCodeSource.getLocation}")
  val stage=new chisel3.stage.ChiselStage
  args(0) match {
    case "proof"=>stage.emitVerilog(new InstalledTransition,Array("--target-dir",args(1)))
    case "pair"=>stage.emitVerilog(new InstalledPair,Array("--target-dir",args(1)))
    case "reference"=>stage.emitVerilog(new InstalledReference,Array("--target-dir",args(1)))
    case "candidate"=>stage.emitVerilog(new InstalledCandidate,Array("--target-dir",args(1)))
  }
}
