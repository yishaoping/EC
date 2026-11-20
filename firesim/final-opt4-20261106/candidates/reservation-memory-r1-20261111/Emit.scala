package opt4reservation
import chisel3._
import chisel3.util._
class Payload extends Bundle {
 val epoch=UInt(16.W);val transaction=UInt(32.W);val mshr=UInt(8.W)
 val newOwner=Bool();val tag=UInt(23.W)
}
class Ports extends Bundle {
 val write=Input(Bool());val index=Input(UInt(9.W));val data=Input(UInt(80.W))
 val readIndex=Input(Vec(5,UInt(9.W)));val result=Output(Vec(5,UInt(80.W)))
}
class ReservationReference extends Module {
  val io=IO(new Ports);val nSets=256;val nWays=2;val tagBits=23;val memWidth=1
  val reservedEpoch = Reg(Vec(nSets, Vec(nWays, UInt(16.W))))
  val reservedTransaction = Reg(Vec(nSets, Vec(nWays, UInt(32.W))))
  val reservedMshr = Reg(Vec(nSets, Vec(nWays, UInt(8.W))))
  val reservedNewOwner = Reg(Vec(nSets, Vec(nWays, Bool())))
  val reservedTag = Reg(Vec(nSets, Vec(nWays, UInt(tagBits.W))))
  val data=io.data.asTypeOf(new Payload)
  val set=io.index(8,1);val way=io.index(0)
  when(io.write) {
    reservedEpoch(set)(way) := data.epoch
    reservedTransaction(set)(way) := data.transaction
    reservedMshr(set)(way) := data.mshr
    reservedNewOwner(set)(way) := data.newOwner
    reservedTag(set)(way) := data.tag
  }
  for(i<-0 until 5) {
    val s=io.readIndex(i)(8,1);val v=io.readIndex(i)(0);val r=Wire(new Payload)
    r.epoch:=reservedEpoch(s)(v)
    r.transaction:=reservedTransaction(s)(v)
    r.mshr:=reservedMshr(s)(v)
    r.newOwner:=reservedNewOwner(s)(v)
    r.tag:=reservedTag(s)(v)
    io.result(i):=r.asUInt
  }
}
class ReservationCandidate extends Module {
  val io=IO(new Ports);val nSets=256;val nWays=2;val tagBits=23;val memWidth=1
  class ReservationStorage[T <: Data](gen: T) {
    private val payload = if (memWidth == 1) Some(Mem(nSets * nWays, gen)) else None
    private val registers = if (memWidth != 1) Some(Reg(Vec(nSets, Vec(nWays, gen)))) else None
    def apply(set: UInt)(way: UInt): T = {
      if (memWidth == 1) payload.get.read(Cat(set, way)) else registers.get(set)(way)
    }
    def write(set: UInt, way: UInt, data: T): Unit = {
      if (memWidth == 1) payload.get.write(Cat(set, way), data)
      else registers.get(set)(way) := data
    }
  }
  val reservedEpoch = new ReservationStorage(UInt(16.W))
  val reservedTransaction = new ReservationStorage(UInt(32.W))
  val reservedMshr = new ReservationStorage(UInt(8.W))
  val reservedNewOwner = new ReservationStorage(Bool())
  val reservedTag = new ReservationStorage(UInt(tagBits.W))
  val data=io.data.asTypeOf(new Payload)
  val set=io.index(8,1);val way=io.index(0)
  when(io.write) {
    reservedEpoch.write(set,way,data.epoch)
    reservedTransaction.write(set,way,data.transaction)
    reservedMshr.write(set,way,data.mshr)
    reservedNewOwner.write(set,way,data.newOwner)
    reservedTag.write(set,way,data.tag)
  }
  for(i<-0 until 5) {
    val s=io.readIndex(i)(8,1);val v=io.readIndex(i)(0);val r=Wire(new Payload)
    r.epoch:=reservedEpoch(s)(v)
    r.transaction:=reservedTransaction(s)(v)
    r.mshr:=reservedMshr(s)(v)
    r.newOwner:=reservedNewOwner(s)(v)
    r.tag:=reservedTag(s)(v)
    io.result(i):=r.asUInt
  }
}
class ReservationPair extends Module {
 val io=IO(new Bundle {
  val write=Input(Bool());val index=Input(UInt(9.W));val data=Input(UInt(80.W))
  val readIndex=Input(Vec(5,UInt(9.W)))
  val reference=Output(Vec(5,UInt(80.W)));val candidate=Output(Vec(5,UInt(80.W)))
 })
 val a=Module(new ReservationReference);val b=Module(new ReservationCandidate)
 for(x<-Seq(a.io,b.io)){x.write:=io.write;x.index:=io.index;x.data:=io.data;x.readIndex:=io.readIndex}
 io.reference:=a.io.result;io.candidate:=b.io.result
}
class ReservationTransition extends RawModule {
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
 import boom.common.BoomTileParams
 val base=new firesim.firesim.DacOpt4C4().toInstance
 val tile=base(TilesLocated(InSubsystem)).map(_.tileParams).find(_.hartId==0).get.asInstanceOf[BoomTileParams]
 require(tile.dcache.get.nSets==256 && tile.dcache.get.nWays==2)
 require(tile.core.issueParams.find(_.iqType==4).get.issueWidth==1)
 require((new Payload).getWidth==80)
 println("RESERVATION_ACTUAL_GEOMETRY sets=256 ways=2 bits=80 fields=16,32,8,1,23 writers=1 reset=uninitialized")
 val stage=new chisel3.stage.ChiselStage
 args(0) match {
  case "proof"=>stage.emitVerilog(new ReservationTransition,Array("--target-dir",args(1)))
  case "pair"=>stage.emitVerilog(new ReservationPair,Array("--target-dir",args(1)))
  case "reference"=>stage.emitVerilog(new ReservationReference,Array("--target-dir",args(1)))
  case "candidate"=>stage.emitVerilog(new ReservationCandidate,Array("--target-dir",args(1)))
 }
}
