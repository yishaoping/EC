package palimpsesttest
import chisel3._
import chisel3.stage.ChiselStage
import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.rocket._
import freechips.rocketchip.subsystem.{InSubsystem,TilesLocated}
import freechips.rocketchip.tile.{TileKey,TileVisibilityNodeKey}
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.tilelink._
import freechips.rocketchip.subsystem.RocketTileAttachParams
class CSRShadowDut(implicit p: Parameters) extends Module {
 val io=IO(new Bundle {
  val mode=Input(UInt(2.W));val write=Input(Bool());val operation=Input(UInt(3.W));val address=Input(UInt(12.W));val data=Input(UInt(64.W))
  val beat=Input(Bool());val cps=Input(Bool());val index=Input(UInt(7.W));val pair=Input(UInt(128.W))
  val compare=Input(Bool());val clear=Input(Bool());val done=Output(Bool());val error=Output(Bool());val read=Output(UInt(64.W));val physicalMprv=Output(Bool())
 })
 val perf=new EventSets(Seq.fill(2)(new EventSet((mask: UInt, hits: UInt) => (mask & hits).orR, Seq("unused" -> (() => (false.B, false.B, 0.U(64.W)))))))
 val csr=Module(new CSRFile(perf))
 csr.io.ungated_clock:=clock;csr.io.hartid:=1.U
 csr.io.interrupts:=0.U.asTypeOf(chiselTypeOf(csr.io.interrupts))
 csr.io.palimpsestRestore.valid:=false.B;csr.io.palimpsestRestore.bits:=0.U
 csr.io.rw.addr:=io.address;csr.io.rw.cmd:=Mux(io.write,io.operation,CSR.R);csr.io.rw.wdata:=io.data
 csr.io.decode.foreach(_.inst:=0.U);csr.io.exception:=false.B;csr.io.retire:=0.U;csr.io.cause:=0.U
 csr.io.pc:=0.U;csr.io.tval:=0.U;csr.io.htval:=0.U;csr.io.gva:=false.B
 csr.io.fcsr_flags.valid:=false.B;csr.io.fcsr_flags.bits:=0.U;csr.io.set_fs_dirty.foreach(_:=false.B)
 csr.io.rocc_interrupt:=false.B;csr.io.counters.foreach(_.inc:=0.U);csr.io.inst.foreach(_:=0.U)
 csr.io.vector.foreach(v=>{v.set_vs_dirty:=false.B;v.set_vconfig.valid:=false.B;v.set_vconfig.bits:=0.U.asTypeOf(chiselTypeOf(v.set_vconfig.bits));v.set_vstart.valid:=false.B;v.set_vstart.bits:=0.U;v.set_vxsat:=false.B})
 csr.io.pfarf_valid:=0.U;csr.io.fcsr_in:=0.U;csr.io.core_trace:=0.U
 csr.io.checker_mode:=io.mode===1.U;csr.io.checker_priv_mode:=io.mode===2.U
 csr.io.arfs_is_CSR:=io.beat;csr.io.arfs_is_CPS:=io.cps;csr.io.csr_shadows:=io.pair;csr.io.shadow_idx:=io.index
 csr.io.check_priv:=0.U;csr.io.check_ret_priv:=0.U;csr.io.check_exception:=false.B
 csr.io.check_tvec:=0.U;csr.io.check_priv_ret:=false.B;csr.io.check_epc:=0.U;csr.io.check_boundary_pc:=0.U
 csr.io.ic_check_done:=io.compare;csr.io.clear_ic_status:=io.clear
 io.done:=csr.io.if_priv_checkcomp;io.error:=csr.io.shadow_check_error;io.read:=csr.io.rw.rdata;io.physicalMprv:=csr.io.status.mprv
}
class CSRShadowFixture(implicit p:Parameters) extends LazyModule {
 val tile=p(TilesLocated(InSubsystem)).collectFirst {case t:RocketTileAttachParams=>t.tileParams}.get
 val client=TLClientNode(Seq(TLClientPortParameters(Seq(TLClientParameters(name="csr-shadow",sourceId=IdRange(0,1))))))
 val visibility=TLIdentityNode()
 val memory=TLManagerNode(Seq(TLManagerPortParameters(Seq(TLManagerParameters(address=Seq(AddressSet(BigInt("80000000",16),BigInt("fffffff",16))),regionType=RegionType.UNCACHED,executable=true,supportsGet=TransferSizes(1,64))),beatBytes=16)))
 memory:=visibility:=client
 lazy val module=new LazyModuleImp(this){
  override def desiredName="CSRShadowHarness"
  val tileP=p.alterPartial{case TileKey=>tile;case TileVisibilityNodeKey=>visibility}
  val dut=Module(new CSRShadowDut()(tileP))
  val io=IO(chiselTypeOf(dut.io));io<>dut.io
  val out=client.out.head._1;out.a.valid:=false.B;out.a.bits:=0.U.asTypeOf(chiselTypeOf(out.a.bits));out.d.ready:=true.B
  val in=memory.in.head._1;in.a.ready:=false.B;in.d.valid:=false.B;in.d.bits:=0.U.asTypeOf(chiselTypeOf(in.d.bits))
 }
}
object EmitCSRShadow extends App {
 implicit val p:Parameters=new chipyard.v1Config
 val top=LazyModule(new CSRShadowFixture)
 (new ChiselStage).emitVerilog(top.module,Array("--target-dir",args(0)))
}
