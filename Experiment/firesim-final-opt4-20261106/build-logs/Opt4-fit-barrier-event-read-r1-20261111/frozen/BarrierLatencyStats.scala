package freechips.rocketchip.guardiancouncil

import chisel3._
import chisel3.util._

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
class GHBarrierLatencyStats(val window: Int) extends Module {
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
    val resolved = Output(UInt(64.W))
    val pending = Output(UInt(64.W))
    val dropped = Output(UInt(64.W))
    val requestCycleSum = Output(UInt(64.W))
    val safeCycleSum = Output(UInt(64.W))
    val statsValid = Output(UInt(64.W))
  })

  val buckets = RegInit(0.U.asTypeOf(new GHBarrierLatencyBucket(window)))
  val seen = RegInit(0.U(64.W))
  val resolved = RegInit(0.U(64.W))
  val pending = RegInit(0.U(64.W))
  val dropped = RegInit(0.U(64.W))
  val requestCycleSum = RegInit(0.U(64.W))
  val safeCycleSum = RegInit(0.U(64.W))
  val statsValid = RegInit(true.B)

  val bucketResolve = Wire(Vec(window, Bool()))
  for (i <- 0 until window) {
    bucketResolve(i) := buckets.valid(i) &&
      buckets.seq(i) <= io.safeWatermark
  }

  // 64 bits per bucket plus eight bits for a 256-entry reduction. The extra
  // bit also accommodates one same-cycle event below.
  val resolvedBucketsWide = (0 until window).map(i =>
    Mux(bucketResolve(i), buckets.count(i), 0.U(64.W)).pad(73)).reduce(_ + _)
  val requestBucketsWide = (0 until window).map(i =>
    Mux(bucketResolve(i), buckets.requestCycleSum(i), 0.U(64.W)).pad(73)).reduce(_ + _)
  val safeBucketsWide = (0 until window).map(i =>
    Mux(bucketResolve(i),
      (io.currentCycle * buckets.count(i)).pad(137), 0.U(137.W))).reduce(_ + _)

  // The producer classifies against its pre-edge watermark. If the same edge
  // advances the exported watermark past the event package, settle it at zero
  // cycles without consuming a bucket slot.
  val eventImmediate = io.event.valid && io.event.bits <= io.safeWatermark
  val eventNeedsBucket = io.event.valid && !eventImmediate
  val eventIndex = io.event.bits(indexBits - 1, 0)
  val eventBucketAvailable = !buckets.valid(eventIndex) ||
    bucketResolve(eventIndex) || buckets.seq(eventIndex) === io.event.bits
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

  val bucketCountOverflow = eventAccepted && buckets.valid(eventIndex) &&
    !bucketResolve(eventIndex) && buckets.count(eventIndex) === ~0.U(64.W)
  val bucketCycleOverflow = eventAccepted && buckets.valid(eventIndex) &&
    !bucketResolve(eventIndex) &&
    buckets.requestCycleSum(eventIndex) > (~0.U(64.W) - io.currentCycle)
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
    for (i <- 0 until window) {
      buckets.valid(i) := false.B
      buckets.seq(i) := 0.U
      buckets.count(i) := 0.U
      buckets.requestCycleSum(i) := 0.U
    }
  }.otherwise {
    for (i <- 0 until window) {
      when (bucketResolve(i)) {
        buckets.valid(i) := false.B
        buckets.count(i) := 0.U
        buckets.requestCycleSum(i) := 0.U
      }
    }

    when (eventAccepted) {
      when (!buckets.valid(eventIndex) || bucketResolve(eventIndex)) {
        buckets.valid(eventIndex) := true.B
        buckets.seq(eventIndex) := io.event.bits
        buckets.count(eventIndex) := 1.U
        buckets.requestCycleSum(eventIndex) := io.currentCycle
      }.otherwise {
        buckets.count(eventIndex) := buckets.count(eventIndex) + 1.U
        buckets.requestCycleSum(eventIndex) :=
          buckets.requestCycleSum(eventIndex) + io.currentCycle
      }
    }

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
}
