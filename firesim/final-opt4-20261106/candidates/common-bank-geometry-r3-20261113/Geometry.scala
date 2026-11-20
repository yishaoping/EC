package geometrytest
import chisel3._
import chisel3.util._
import ecstatscommon._
import boom.lsu.PackageAddressStats
import freechips.rocketchip.guardiancouncil.{GHBarrierLatencyStats,GH_GlobalParams}
class Partition(val lanes: Int) extends Module {
  require(Set(8,16,32).contains(lanes))
  val reference=Seq.fill(2)(Module(new geometryreference.ReferenceBank))
  val candidate=Seq.fill(32/lanes)(Module(new GeometryBankProof(lanes)))
  val io=IO(new Bundle {
    val barrierBase = Input(UInt(8.W))
    val barrierResetStats = Input(Bool())
    val barrierEvent = Input(Valid(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)))
    val barrierSafeWatermark = Input(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
    val barrierCurrentCycle = Input(UInt(64.W))
    val base = Input(UInt(8.W))
    val loadSources = Input(Vec(8, new Source))
    val storeSources = Input(Vec(8, new Source))
    val strictSources = Input(Vec(80, new Source))
    val newStore = Input(new Counts)
    val newFirstStore = Input(new Counts)
    val processSeq = Input(UInt(32.W))
    val retiringSeq = Input(UInt(32.W))
    val processCommit = Input(Bool())
    val safeAdvance = Input(Bool())
    val safeError = Input(Bool())
    val resetStats = Input(Bool())
    val querySeq = Input(Vec(88, UInt(32.W)))
    val same=Output(Bool())
  })
  val inNames=Seq("barrierBase","barrierResetStats","barrierEvent","barrierSafeWatermark","barrierCurrentCycle","base","loadSources","storeSources","strictSources","newStore","newFirstStore","processSeq","retiringSeq","processCommit","safeAdvance","safeError","resetStats","querySeq")
  for((bank,i) <- reference.zipWithIndex; n <- inNames) {
    if(n=="base" || n=="barrierBase") bank.io.elements(n) := (io.elements(n).asUInt + (i*16).U)(7,0)
    else bank.io.elements(n) := io.elements(n)
  }
  for((bank,i) <- candidate.zipWithIndex; n <- inNames) {
    if(n=="base" || n=="barrierBase") bank.io.elements(n) := (io.elements(n).asUInt + (i*lanes).U)(7,0)
    else bank.io.elements(n) := io.elements(n)
  }
  val checks=collection.mutable.ArrayBuffer[Bool]()
  for(i <- 0 until 32) {
    checks += reference(i/16).io.observeAddress(i%16) === candidate(i/lanes).io.observeAddress(i%lanes)
    checks += reference(i/16).io.observeBarrier(i%16) === candidate(i/lanes).io.observeBarrier(i%lanes)
  }
  def bitOr(xs: Seq[UInt]): UInt = xs.reduce(_ | _)
  for(n <- Seq("queryMatch","currentCollision","retiringValid","retiringCollision","retiringWords","overflow",
               "barrierEventAvailable","barrierCountOverflow","barrierCycleOverflow")) {
    checks += bitOr(reference.map(_.io.elements(n).asUInt)) === bitOr(candidate.map(_.io.elements(n).asUInt))
  }
  for(n <- Seq("barrierResolvedCount","barrierResolvedRequest")) {
    val a=reference.map(_.io.elements(n).asUInt.pad(69)).reduce(_ + _)
    val b=candidate.map(_.io.elements(n).asUInt.pad(69)).reduce(_ + _)
    checks += a === b
  }
  io.same := checks.reduce(_ && _)
}
class QueryContract(val lanes: Int) extends Module {
  val io=IO(new Bundle {
    val valid=Input(Vec(lanes,Bool()))
    val seq=Input(Vec(lanes,UInt(32.W)))
    val base=Input(UInt(8.W))
    val query=Input(UInt(32.W))
    val same=Output(Bool())
  })
  val expected=(0 until lanes).map(i => io.query(7,0)===(io.base+i.U)(7,0) &&
    io.valid(i) && io.seq(i)(31,8)===io.query(31,8)).reduce(_ || _)
  io.same := expected === BankTagRead.matches(io.valid.toSeq,io.seq.toSeq,io.base,io.query)
}
class MixedGeometry(val lanes: Int) extends Module {
  val address=Module(new PackageAddressStats(3,40,64,256,bankLanes=lanes))
  val barriers=Seq.fill(3)(Module(new GHBarrierLatencyStats(256,lanes)))
  val io=IO(new Bundle {
    val address=chiselTypeOf(MixedGeometry.this.address.io)
    val barrier=Vec(3,chiselTypeOf(barriers.head.io))
  })
  address.io <> io.address
  for(i <- 0 until 3) barriers(i).io <> io.barrier(i)
}
object Emit extends App {
  val lanes=args(1).toInt
  val dut: () => RawModule = args(0) match {
    case "Partition" => () => new Partition(lanes)
    case "QueryContract" => () => new QueryContract(lanes)
    case "Bank" => () => new GeometryBankProof(lanes)
    case "Mixed" => () => new MixedGeometry(lanes)
  }
  (new chisel3.stage.ChiselStage).emitVerilog(dut(),Array("--target-dir",args(2),"--output-file",args(0)))
}
