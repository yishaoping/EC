package mshrsplitarea

import chisel3._
import chisel3.experimental.DataMirror
import scala.collection.immutable.ListMap
import org.chipsalliance.cde.config.{Config,Parameters}
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.subsystem._
import freechips.rocketchip.tile._
import freechips.rocketchip.tilelink._

// The real core infers this unused BrResolutionInfo width from its producer.
// Give the isolated PeekPoke wrapper the same explicit width on both sides.
// Every boundary leaf is preserved; only this otherwise-unbounded type is sized.
class SizedBoundary(template:Record,path:String="") extends Record {
  def concrete(d:Data,name:String):Data=d match {
    case r:Record=>new SizedBoundary(r,name)
    case v:Vec[_]=>Vec(v.length,concrete(v.head,name+"[]"))
    case _=>
      val leaf=if(name=="brupdate.b2.target_offset") SInt(32.W) else chiselTypeOf(d)
      DataMirror.directionOf(d) match {
        case ActualDirection.Input=>Input(leaf)
        case ActualDirection.Output=>Output(leaf)
        case _=>leaf
      }
  }
  val elements=ListMap(template.elements.toSeq.map { case(name,d)=>
    name->concrete(d,if(path.isEmpty) name else path+"."+name) }:_*)
  override def cloneType:this.type=(new SizedBoundary(template,path)).asInstanceOf[this.type]
}

object ActualMSHR {
  def build(): Module = {
    val base=new firesim.firesim.DacOpt4C4().toInstance
    val tile=base(TilesLocated(InSubsystem)).map(_.tileParams).find(_.hartId==0).get
    require(tile.dcache.get.nMSHRs==6 && tile.dcache.get.nRPQ==16 && tile.dcache.get.nSDQ==17)
    implicit val p: Parameters=base.alterPartial { case TileKey=>tile; case MaxHartIdBits=>3 }
    val client=TLMasterPortParameters.v1(Seq(TLMasterParameters.v1("mshr-full-module",supportsProbe=TransferSizes(64,64))))
    val manager=TLSlavePortParameters.v1(Seq(TLSlaveParameters.v1(
      address=Seq(AddressSet(0,(BigInt(1)<<35)-1)),regionType=RegionType.CACHED,
      supportsAcquireT=TransferSizes(64,64),supportsAcquireB=TransferSizes(64,64),
      supportsGet=TransferSizes(1,64),supportsPutFull=TransferSizes(1,64))),
      beatBytes=tile.dcache.get.rowBits/8,endSinkId=1)
    val wrapper=LazyModule(new LazyModule()(p) {
      val clientNode=TLClientNode(Seq(client))
      val visibilityNode=TLEphemeralNode()
      val managerNode=TLManagerNode(Seq(manager))
      managerNode:=visibilityNode:=clientNode
      lazy val module=new LazyModuleImp(this) {
        override def desiredName="ActualMSHRModule"
        val tileP=p.alterPartial { case TileVisibilityNodeKey=>visibilityNode }
        val dut=Module(new boom.lsu.BoomMSHRFile()(clientNode.edges.out.head,tileP))
        val io=IO(new SizedBoundary(dut.io))
        def connectLeaves(original:Data,exposed:Data):Unit=original match {
          case r:Record=>r.elements.foreach { case(name,d)=>connectLeaves(d,exposed.asInstanceOf[Record].elements(name)) }
          case v:Vec[_]=>v.zip(exposed.asInstanceOf[Vec[Data]]).foreach { case(a,b)=>connectLeaves(a,b) }
          case _=>DataMirror.directionOf(original) match {
            case ActualDirection.Input=>original:=exposed
            case ActualDirection.Output=>exposed:=original
            case _=>throw new Exception("Unexpected undirected MSHR leaf")
          }
        }
        connectLeaves(dut.io,io)
      }
    })
    wrapper.module
  }
}

class Harness(implicit p:Parameters) extends firesim.midasexamples.PeekPokeMidasExampleHarness(
  ()=>ActualMSHR.build())

class MCConfig extends Config(new Config((site,here,up)=> {
  case midas.GenerateMultiCycleRamModels=>true
  case midas.EnableModelMultiThreading=>false
}) ++ new firesim.configs.DacXilinxAlveoConfig)

object Emit extends App {
  freechips.rocketchip.system.Generator.main(Array(
    "--target-dir",args(0),"--name","MSHR","--top-module","mshrsplitarea.Harness",
    "--configs","firesim.midasexamples.NoConfig"))
}
