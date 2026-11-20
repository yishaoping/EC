package mshrsplitprobe

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.tile._
import freechips.rocketchip.subsystem._
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.tilelink._
import boom.common._
import boom.lsu.BoomDCacheReqInternal

class QueuePair(implicit p: Parameters) extends Module {
  val reference = Module(new mshrsplitreference.BranchKillableQueue(
    new BoomDCacheReqInternal, 16, u => u.uses_ldq, false, true))
  val candidate = Module(new mshrsplitcandidate.BranchKillableQueue(
    new BoomDCacheReqInternal, 16, u => u.uses_ldq, false, true))
  val io = IO(new Bundle {
    val enqValid = Input(Bool())
    val enqBits = Input(UInt(reference.io.enq.bits.getWidth.W))
    val deqReady = Input(Bool())
    val branch = Input(UInt(reference.io.brupdate.getWidth.W))
    val flush = Input(Bool())
    val holdHead = Input(Bool())
    val mismatch = Output(UInt(8.W))
    val referenceDeq = Output(UInt(reference.io.deq.bits.getWidth.W))
    val candidateDeq = Output(UInt(reference.io.deq.bits.getWidth.W))
    val events = Output(UInt(8.W))
  })
  reference.io.enq.valid := io.enqValid
  reference.io.enq.bits := io.enqBits.asTypeOf(reference.io.enq.bits)
  reference.io.deq.ready := io.deqReady
  reference.io.brupdate := io.branch.asTypeOf(reference.io.brupdate)
  reference.io.flush := io.flush
  reference.io.hold_head.get := io.holdHead
  candidate.io.enq.valid := io.enqValid
  candidate.io.enq.bits := io.enqBits.asTypeOf(candidate.io.enq.bits)
  candidate.io.deq.ready := io.deqReady
  candidate.io.brupdate := io.branch.asTypeOf(candidate.io.brupdate)
  candidate.io.flush := io.flush
  candidate.io.hold_head.get := io.holdHead
  io.mismatch := Cat(
    reference.io.enq.ready =/= candidate.io.enq.ready,
    reference.io.deq.valid =/= candidate.io.deq.valid,
    reference.io.deq.bits.asUInt =/= candidate.io.deq.bits.asUInt,
    reference.io.discarded.get.valid =/= candidate.io.discarded.get.valid,
    reference.io.discarded.get.bits.asUInt =/= candidate.io.discarded.get.bits.asUInt,
    reference.io.empty =/= candidate.io.empty,
    reference.io.count =/= candidate.io.count,
    reference.io.hold_head.get =/= candidate.io.hold_head.get)
  io.referenceDeq := reference.io.deq.bits.asUInt
  io.candidateDeq := candidate.io.deq.bits.asUInt
  io.events := Cat(reference.io.enq.fire, reference.io.deq.fire,
    reference.io.discarded.get.valid, reference.io.empty,
    !reference.io.enq.ready, io.holdHead, io.flush, io.branch.orR)
}

object Emit extends App {
  val base = new firesim.firesim.DacOpt4C4().toInstance
  val tile = base(TilesLocated(InSubsystem)).map(_.tileParams).find(_.hartId == 0).get
  implicit val p: Parameters = base.alterPartial { case TileKey => tile; case MaxHartIdBits => 3 }
  require(tile.dcache.get.nRPQ == 16)
  val client = TLMasterPortParameters.v1(Seq(TLMasterParameters.v1("mshr-queue-proof", supportsProbe=TransferSizes(64,64))))
  val manager = TLSlavePortParameters.v1(Seq(TLSlaveParameters.v1(address=Seq(AddressSet(0, (BigInt(1)<<35)-1)), regionType=RegionType.CACHED, supportsAcquireT=TransferSizes(64,64), supportsAcquireB=TransferSizes(64,64), supportsGet=TransferSizes(1,64), supportsPutFull=TransferSizes(1,64))), beatBytes=tile.dcache.get.rowBits / 8, endSinkId=1)
  val wrapper = LazyModule(new LazyModule()(p) {
    val clientNode = TLClientNode(Seq(client))
    val visibilityNode = TLEphemeralNode()
    val managerNode = TLManagerNode(Seq(manager))
    managerNode := visibilityNode := clientNode
    lazy val module = new LazyModuleImp(this) {
      override def desiredName = "MSHRQueueHarness"
      val tileP = p.alterPartial { case TileVisibilityNodeKey => visibilityNode }
      val dut = Module(new QueuePair()(tileP))
      val io = IO(chiselTypeOf(dut.io))
      io <> dut.io
    }
  })
  (new chisel3.stage.ChiselStage).emitVerilog(wrapper.module, Array("--target-dir",args(0)))
}
