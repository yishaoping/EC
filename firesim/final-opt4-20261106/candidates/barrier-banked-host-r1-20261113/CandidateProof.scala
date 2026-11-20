package freechips.rocketchip.guardiancouncil

import chisel3._
import chisel3.util._
import chisel3.experimental.annotate
import midas.targetutils.EnableModelMultiThreadingAnnotation

/** Per-package storage for a non-stalling barrier-latency measurement.
  *
  * Events are grouped by the package whose verification makes them safe.
  * Only timestamps for resolved events are exported; pending events retain
  * their request timestamps in the bucket until the safe watermark reaches
  * their full package sequence.
  */
class GHBarrierLatencyBucket(val window: Int) extends Bundle {
  require(window > 0)
  val valid = Vec(window, Bool())
  val seq = Vec(window, UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val count = Vec(window, UInt(64.W))
  val requestCycleSum = Vec(window, UInt(64.W))
}

/** Count events and their theoretical wait for a monotonically advancing
  * contiguous-safe package watermark. This module never backpressures the
  * producer: a slot collision drops only the measurement, increments
  * `dropped`, and permanently clears `statsValid` until reset.
  */
class GHBarrierLatencyStats(val window: Int, val bankLanes: Int = 16) extends Module {
  require(isPow2(window))
  require(window <= (BigInt(1) << GH_GlobalParams.GH_PACKET_SEQ_BITS))

  private val indexBits = log2Ceil(window)

  val io = IO(new Bundle {
    val resetStats = Input(Bool())
    val event = Input(Valid(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)))
    val safeWatermark = Input(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
    val currentCycle = Input(UInt(64.W))
    val fatalProtocolError = Input(Bool())

    val seen = Output(UInt(64.W))
    val debugView = Output(Vec(window, UInt(161.W)))
    val resolved = Output(UInt(64.W))
    val pending = Output(UInt(64.W))
    val dropped = Output(UInt(64.W))
    val requestCycleSum = Output(UInt(64.W))
    val safeCycleSum = Output(UInt(64.W))
    val statsValid = Output(UInt(64.W))
  })

  require(isPow2(bankLanes) && bankLanes <= window)
  val bucketBanks = Seq.tabulate(window / bankLanes) { b =>
    val bank = Module(new GHBarrierBucketBank(window, bankLanes))
    bank.io.base := (b * bankLanes).U
    bank.io.resetStats := io.resetStats
    bank.io.event := io.event
    bank.io.safeWatermark := io.safeWatermark
    bank.io.currentCycle := io.currentCycle
    annotate(EnableModelMultiThreadingAnnotation(bank))
    bank
  }
  val seen = RegInit(0.U(64.W))
  val resolved = RegInit(0.U(64.W))
  val pending = RegInit(0.U(64.W))
  val dropped = RegInit(0.U(64.W))
  val requestCycleSum = RegInit(0.U(64.W))
  val safeCycleSum = RegInit(0.U(64.W))
  val statsValid = RegInit(true.B)

  // An exact width-growing balanced tree: 256 unsigned 64-bit terms need
  // at most 72 bits. Preserve the 73-bit ABI and same-cycle-event headroom,
  // while avoiding a serial chain of 255 already-widened 73-bit additions.
  private def exactBucketSum(terms: Seq[UInt]): UInt = {
    require(terms.nonEmpty && window <= 256)
    def tree(xs: Seq[UInt]): UInt = {
      if (xs.size == 1) xs.head
      else tree(xs.grouped(2).map {
        case Seq(a, b) => a +& b
        case Seq(a) => a
      }.toSeq)
    }
    tree(terms).pad(73)
  }
  val resolvedBucketsWide = exactBucketSum(bucketBanks.map(_.io.resolvedCount))
  val requestBucketsWide = exactBucketSum(bucketBanks.map(_.io.resolvedRequest))
  // Candidate only: exact distributive factoring, no state/timing/overflow changes.
  // window<=256 implies resolvedBucketsWide fits 73 bits; 64*73 fits 137 bits.
  val safeBucketsWide = io.currentCycle * resolvedBucketsWide

  // The producer classifies against its pre-edge watermark. If the same edge
  // advances the exported watermark past the event package, settle it at zero
  // cycles without consuming a bucket slot.
  val eventImmediate = io.event.valid && io.event.bits <= io.safeWatermark
  val eventNeedsBucket = io.event.valid && !eventImmediate
  val eventIndex = io.event.bits(indexBits - 1, 0)
  val eventBucketAvailable = bucketBanks.map(_.io.eventAvailable).reduce(_ || _)
  val eventAccepted = eventNeedsBucket && eventBucketAvailable
  val eventDropped = eventNeedsBucket && !eventBucketAvailable

  val resolvedThisCycleWide = resolvedBucketsWide +
    Mux(eventImmediate, 1.U(73.W), 0.U(73.W))
  val requestThisCycleWide = requestBucketsWide +
    Mux(eventImmediate, io.currentCycle, 0.U(64.W)).pad(73)
  val safeThisCycleWide = safeBucketsWide +
    Mux(eventImmediate, io.currentCycle, 0.U(64.W)).pad(137)

  val pendingBeforeResolve = pending.pad(73) + eventAccepted.asUInt
  val pendingUnderflow = resolvedBucketsWide > pendingBeforeResolve
  val pendingNextWide = pendingBeforeResolve - resolvedBucketsWide

  val bucketCountOverflow = bucketBanks.map(_.io.countOverflow).reduce(_ || _)
  val bucketCycleOverflow = bucketBanks.map(_.io.cycleOverflow).reduce(_ || _)
  val reductionOverflow = resolvedThisCycleWide(72, 64).orR ||
    requestThisCycleWide(72, 64).orR || safeThisCycleWide(136, 64).orR ||
    pendingNextWide(72, 64).orR
  val counterOverflow =
    (io.event.valid && seen === ~0.U(64.W)) ||
    (eventDropped && dropped === ~0.U(64.W)) ||
    (resolvedThisCycleWide.orR &&
      resolved > (~0.U(64.W) - resolvedThisCycleWide(63, 0))) ||
    (requestThisCycleWide.orR &&
      requestCycleSum > (~0.U(64.W) - requestThisCycleWide(63, 0))) ||
    (safeThisCycleWide.orR &&
      safeCycleSum > (~0.U(64.W) - safeThisCycleWide(63, 0)))
  val arithmeticError = bucketCountOverflow || bucketCycleOverflow ||
    reductionOverflow || counterOverflow || pendingUnderflow

  when (io.resetStats) {
    seen := 0.U
    resolved := 0.U
    pending := 0.U
    dropped := 0.U
    requestCycleSum := 0.U
    safeCycleSum := 0.U
    statsValid := true.B
  }.otherwise {
    when (io.event.valid) { seen := seen + 1.U }
    when (eventDropped) { dropped := dropped + 1.U }
    when (resolvedThisCycleWide.orR) {
      resolved := resolved + resolvedThisCycleWide(63, 0)
      requestCycleSum := requestCycleSum + requestThisCycleWide(63, 0)
      safeCycleSum := safeCycleSum + safeThisCycleWide(63, 0)
    }
    when (eventAccepted || resolvedBucketsWide.orR) {
      pending := Mux(pendingUnderflow, 0.U, pendingNextWide(63, 0))
    }
    when (eventDropped || arithmeticError || io.fatalProtocolError) {
      statsValid := false.B
    }
  }

  io.seen := seen
  io.resolved := resolved
  io.pending := pending
  io.dropped := dropped
  io.requestCycleSum := requestCycleSum
  io.safeCycleSum := safeCycleSum
  io.statsValid := Cat(0.U(63.W), statsValid)
  for (i <- 0 until window) io.debugView(i) := bucketBanks(i / bankLanes).io.observe(i % bankLanes)

}
