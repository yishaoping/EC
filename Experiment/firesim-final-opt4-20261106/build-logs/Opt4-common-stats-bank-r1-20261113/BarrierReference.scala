package freechips.rocketchip.guardiancouncil

import chisel3._
import chisel3.util._

/** Complete barrier bucket state and read/compute/write cone. Each instance
  * handles all of its entries at the original target edge. FAME5 may share
  * identical instances in host time; no target-cycle scheduling is added.
  */
class BarrierReference(val window: Int, val lanes: Int) extends Module {
  require(isPow2(window) && isPow2(lanes) && lanes <= window && window <= 256)
  private val indexBits = log2Ceil(window)
  private val sumBits = 64 + log2Ceil(lanes)
  val io = IO(new Bundle {
    val observeBarrier = Output(Vec(16, UInt(161.W)))

    val base = Input(UInt(indexBits.W))
    val resetStats = Input(Bool())
    val event = Input(Valid(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)))
    val safeWatermark = Input(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
    val currentCycle = Input(UInt(64.W))
    val resolvedCount = Output(UInt(sumBits.W))
    val resolvedRequest = Output(UInt(sumBits.W))
    val eventAvailable = Output(Bool())
    val countOverflow = Output(Bool())
    val cycleOverflow = Output(Bool())
  })

  val buckets = RegInit(0.U.asTypeOf(new GHBarrierLatencyBucket(lanes)))
  val resolving = Wire(Vec(lanes, Bool()))
  val available = Wire(Vec(lanes, Bool()))
  val countOverflow = Wire(Vec(lanes, Bool()))
  val cycleOverflow = Wire(Vec(lanes, Bool()))
  val eventNeedsBucket = io.event.valid && io.event.bits > io.safeWatermark
  for (i <- 0 until lanes) {
    val key = (io.base + i.U)(indexBits - 1, 0)
    val selected = io.event.bits(indexBits - 1, 0) === key
    resolving(i) := buckets.valid(i) && buckets.seq(i) <= io.safeWatermark
    val canAccept = !buckets.valid(i) || resolving(i) || buckets.seq(i) === io.event.bits
    val accepted = eventNeedsBucket && selected && canAccept
    available(i) := selected && canAccept
    countOverflow(i) := accepted && buckets.valid(i) && !resolving(i) &&
      buckets.count(i) === ~0.U(64.W)
    cycleOverflow(i) := accepted && buckets.valid(i) && !resolving(i) &&
      buckets.requestCycleSum(i) > (~0.U(64.W) - io.currentCycle)

    when (io.resetStats) {
      buckets.valid(i) := false.B
      buckets.seq(i) := 0.U
      buckets.count(i) := 0.U
      buckets.requestCycleSum(i) := 0.U
    }.otherwise {
      when (resolving(i)) {
        buckets.valid(i) := false.B
        buckets.count(i) := 0.U
        buckets.requestCycleSum(i) := 0.U
      }
      // Reallocation wins over retirement on the same target edge.
      when (accepted) {
        when (!buckets.valid(i) || resolving(i)) {
          buckets.valid(i) := true.B
          buckets.seq(i) := io.event.bits
          buckets.count(i) := 1.U
          buckets.requestCycleSum(i) := io.currentCycle
        }.otherwise {
          buckets.count(i) := buckets.count(i) + 1.U
          buckets.requestCycleSum(i) := buckets.requestCycleSum(i) + io.currentCycle
        }
      }
    }
  }

  private def exactSum(xs: Seq[UInt]): UInt = {
    if (xs.size == 1) xs.head
    else exactSum(xs.grouped(2).map {
      case Seq(a, b) => a +& b
      case Seq(a) => a
    }.toSeq)
  }
  io.resolvedCount := exactSum((0 until lanes).map(i =>
    Mux(resolving(i), buckets.count(i), 0.U(64.W))))
  io.resolvedRequest := exactSum((0 until lanes).map(i =>
    Mux(resolving(i), buckets.requestCycleSum(i), 0.U(64.W))))
  io.eventAvailable := available.asUInt.orR
  io.countOverflow := countOverflow.asUInt.orR
  io.cycleOverflow := cycleOverflow.asUInt.orR
  for (i <- 0 until 16) io.observeBarrier(i) := Cat(buckets.valid(i), buckets.seq(i),
    buckets.count(i), buckets.requestCycleSum(i))

}
