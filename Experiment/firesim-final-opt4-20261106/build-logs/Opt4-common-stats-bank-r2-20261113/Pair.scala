package commonbanktest
import chisel3._
import chisel3.util._
import ecstatscommon.{Counts, Source}
import freechips.rocketchip.guardiancouncil.GH_GlobalParams
class Pair extends Module {
  val a = Module(new opt4bankedproduction.AddressReference)
  val b = Module(new freechips.rocketchip.guardiancouncil.BarrierReference(256,16))
  val c = Module(new ecstatscommon.StatsBankProof)
  val io = IO(new Bundle {
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
    val same = Output(Bool())
  })
  a.io.base := io.base
  c.io.base := io.base
  a.io.loadSources := io.loadSources
  c.io.loadSources := io.loadSources
  a.io.storeSources := io.storeSources
  c.io.storeSources := io.storeSources
  a.io.strictSources := io.strictSources
  c.io.strictSources := io.strictSources
  a.io.newStore := io.newStore
  c.io.newStore := io.newStore
  a.io.newFirstStore := io.newFirstStore
  c.io.newFirstStore := io.newFirstStore
  a.io.processSeq := io.processSeq
  c.io.processSeq := io.processSeq
  a.io.retiringSeq := io.retiringSeq
  c.io.retiringSeq := io.retiringSeq
  a.io.processCommit := io.processCommit
  c.io.processCommit := io.processCommit
  a.io.safeAdvance := io.safeAdvance
  c.io.safeAdvance := io.safeAdvance
  a.io.safeError := io.safeError
  c.io.safeError := io.safeError
  a.io.resetStats := io.resetStats
  c.io.resetStats := io.resetStats
  a.io.querySeq := io.querySeq
  c.io.querySeq := io.querySeq
  b.io.base := io.barrierBase
  c.io.barrierBase := io.barrierBase
  b.io.resetStats := io.barrierResetStats
  c.io.barrierResetStats := io.barrierResetStats
  b.io.event := io.barrierEvent
  c.io.barrierEvent := io.barrierEvent
  b.io.safeWatermark := io.barrierSafeWatermark
  c.io.barrierSafeWatermark := io.barrierSafeWatermark
  b.io.currentCycle := io.barrierCurrentCycle
  c.io.barrierCurrentCycle := io.barrierCurrentCycle
  io.same := (a.io.observeAddress.asUInt === c.io.observeAddress.asUInt) &&
    (a.io.queryMatch.asUInt === c.io.queryMatch.asUInt) &&
    (a.io.currentCollision.asUInt === c.io.currentCollision.asUInt) &&
    (a.io.retiringValid.asUInt === c.io.retiringValid.asUInt) &&
    (a.io.retiringCollision.asUInt === c.io.retiringCollision.asUInt) &&
    (a.io.retiringWords.asUInt === c.io.retiringWords.asUInt) &&
    (a.io.overflow.asUInt === c.io.overflow.asUInt) &&
    (b.io.observeBarrier.asUInt === c.io.observeBarrier.asUInt) &&
    (b.io.resolvedCount.asUInt === c.io.barrierResolvedCount.asUInt) &&
    (b.io.resolvedRequest.asUInt === c.io.barrierResolvedRequest.asUInt) &&
    (b.io.eventAvailable.asUInt === c.io.barrierEventAvailable.asUInt) &&
    (b.io.countOverflow.asUInt === c.io.barrierCountOverflow.asUInt) &&
    (b.io.cycleOverflow.asUInt === c.io.barrierCycleOverflow.asUInt)
}

object Emit extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new Pair,
    Array("--target-dir",args(0),"--output-file","Pair"))
}
