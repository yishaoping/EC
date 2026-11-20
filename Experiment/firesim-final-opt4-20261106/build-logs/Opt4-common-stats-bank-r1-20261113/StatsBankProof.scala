package ecstatscommon

import chisel3._
import chisel3.util._
import chisel3.experimental.annotate
import midas.targetutils.EnableModelMultiThreadingAnnotation
import freechips.rocketchip.guardiancouncil.{GH_GlobalParams, GHBarrierLatencyBucket}

class Counts extends Bundle {
  val bytes = UInt(4.W)
  val words4 = UInt(2.W)
  val words8 = UInt(2.W)
  val lines = UInt(1.W)
  def values: Seq[UInt] = Seq(bytes, words4, words8, lines)
}
class Source extends Bundle {
  val key = UInt(8.W)
  val counts = new Counts
}

// A complete bucket-state boundary: histogram -> exact wide sums -> writes.
// All target registers below replace existing bucket registers one for one.
// Global errors, event queues and table qualification remain outside this
// projection, exactly as processCommit / safeError are already qualified.
class StatsBankProof extends Module {
  private val indexBits = 8
  val lanes = 16
  val io = IO(new Bundle {
    val observeAddress = Output(Vec(16, UInt(1313.W)))
    val observeBarrier = Output(Vec(16, UInt(161.W)))

    val barrierBase = Input(UInt(8.W))
    val barrierResetStats = Input(Bool())
    val barrierEvent = Input(Valid(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)))
    val barrierSafeWatermark = Input(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
    val barrierCurrentCycle = Input(UInt(64.W))
    val barrierResolvedCount = Output(UInt(68.W))
    val barrierResolvedRequest = Output(UInt(68.W))
    val barrierEventAvailable = Output(Bool())
    val barrierCountOverflow = Output(Bool())
    val barrierCycleOverflow = Output(Bool())

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
    val queryMatch = Output(Vec(88, Bool()))
    val currentCollision = Output(Bool())
    val retiringValid = Output(Bool())
    val retiringCollision = Output(Bool())
    val retiringWords = Output(Vec(5, Vec(4, UInt(64.W))))
    val overflow = Output(Bool())

  })
  dontTouch(io)
  val bucketValid = RegInit(VecInit(Seq.fill(16)(false.B)))
  val bucketSeq = Reg(Vec(16, UInt(32.W)))
  val bucketStore = Reg(Vec(16, Vec(4, UInt(64.W))))
  val bucketLoadFirst = Reg(Vec(16, Vec(4, UInt(64.W))))
  val bucketStoreFirst = Reg(Vec(16, Vec(4, UInt(64.W))))
  val bucketStrictWriteRead = Reg(Vec(16, Vec(4, UInt(64.W))))
  val bucketFirstStore = Reg(Vec(16, Vec(4, UInt(64.W))))
  val laneOverflows = Wire(Vec(16, Bool()))
  for (i <- 0 until 16) {
    val key = (io.base + i.U)(7, 0)
    def delta(sources: Seq[Source]): Vec[UInt] =
      ecstatscommon.AddressBucketGrouped.lookup(sources.map(_.key),
        sources.map(_.counts.values), Seq(8, 3, 2, 1), key)
    val bucketLoadFirstDelta = delta(io.loadSources.toSeq)
    val bucketStoreFirstDelta = delta(io.storeSources.toSeq)
    val bucketStrictWriteReadDelta = delta(io.strictSources.toSeq)
    val isCurrent = io.processSeq(7, 0) === key
    val isRetiring = io.retiringSeq(7, 0) === key
    val allocate = isCurrent && !bucketValid(i)
    val overflows = collection.mutable.ArrayBuffer[Bool]()
    for (g <- 0 until 4) {
      val loadFirstNextWide = bucketLoadFirst(i)(g) +& bucketLoadFirstDelta(g)
      val storeFirstNextWide = bucketStoreFirst(i)(g) +& bucketStoreFirstDelta(g)
      val strictWriteReadNextWide = bucketStrictWriteRead(i)(g) +& bucketStrictWriteReadDelta(g)
      val currentStoreNextWide = Mux(bucketValid(i), bucketStore(i)(g),
        0.U(64.W)) +& io.newStore.values(g).pad(64)
      val currentFirstStoreNextWide = Mux(bucketValid(i), bucketFirstStore(i)(g),
        0.U(64.W)) +& io.newFirstStore.values(g).pad(64)
      overflows ++= Seq(loadFirstNextWide(64), storeFirstNextWide(64),
        strictWriteReadNextWide(64), isCurrent && currentStoreNextWide(64),
        isCurrent && currentFirstStoreNextWide(64))
      when (io.processCommit) {
        when (isCurrent) {
          bucketStore(i)(g) := currentStoreNextWide(63, 0)
          bucketFirstStore(i)(g) := currentFirstStoreNextWide(63, 0)
        }
        when (ecstatscommon.AddressBucketUpdate.enabled(isCurrent, bucketLoadFirstDelta(g))) {
          bucketLoadFirst(i)(g) := Mux(allocate, bucketLoadFirstDelta(g), loadFirstNextWide(63, 0))
        }
        when (ecstatscommon.AddressBucketUpdate.enabled(isCurrent, bucketStoreFirstDelta(g))) {
          bucketStoreFirst(i)(g) := Mux(allocate, bucketStoreFirstDelta(g), storeFirstNextWide(63, 0))
        }
        when (ecstatscommon.AddressBucketUpdate.enabled(isCurrent, bucketStrictWriteReadDelta(g))) {
          bucketStrictWriteRead(i)(g) := Mux(allocate, bucketStrictWriteReadDelta(g), strictWriteReadNextWide(63, 0))
        }
      }
      // Source assignment priority is process < retirement < resetStats.
      when (io.safeAdvance && !io.safeError && isRetiring && bucketValid(i)) {
        bucketStore(i)(g) := 0.U
        bucketFirstStore(i)(g) := 0.U
        bucketLoadFirst(i)(g) := 0.U
        bucketStoreFirst(i)(g) := 0.U
        bucketStrictWriteRead(i)(g) := 0.U
      }
      when (io.resetStats) {
        bucketStore(i)(g) := 0.U
        bucketFirstStore(i)(g) := 0.U
        bucketLoadFirst(i)(g) := 0.U
        bucketStoreFirst(i)(g) := 0.U
        bucketStrictWriteRead(i)(g) := 0.U
      }
    }
    when (io.processCommit && isCurrent) {
      bucketValid(i) := true.B
      bucketSeq(i) := io.processSeq
    }
    when (io.safeAdvance && !io.safeError && isRetiring && bucketValid(i)) {
      bucketValid(i) := false.B
    }
    when (io.resetStats) {
      bucketValid(i) := false.B
      bucketSeq(i) := 0.U
    }
    laneOverflows(i) := overflows.reduce(_ || _)

  }
  val keys = (0 until 16).map(i => (io.base + i.U)(7, 0))
  for (q <- 0 until 88) {
    io.queryMatch(q) := (0 until 16).map(i =>
      io.querySeq(q)(7, 0) === keys(i) && bucketValid(i) &&
      bucketSeq(i)(31, 8) === io.querySeq(q)(31, 8)).reduce(_ || _)
  }
  io.currentCollision := (0 until 16).map(i =>
    io.processSeq(7, 0) === keys(i) && bucketValid(i) &&
    bucketSeq(i)(31, 8) =/= io.processSeq(31, 8)).reduce(_ || _)
  val retireSelect = keys.map(_ === io.retiringSeq(7, 0))
  io.retiringValid := (0 until 16).map(i => retireSelect(i) && bucketValid(i)).reduce(_ || _)
  io.retiringCollision := (0 until 16).map(i => retireSelect(i) && bucketValid(i) &&
    bucketSeq(i)(31, 8) =/= io.retiringSeq(31, 8)).reduce(_ || _)
  val metrics = Seq(bucketStore, bucketFirstStore, bucketLoadFirst,
    bucketStoreFirst, bucketStrictWriteRead)
  for (m <- 0 until 5; g <- 0 until 4) {
    io.retiringWords(m)(g) := Mux1H(retireSelect, (0 until 16).map(i => metrics(m)(i)(g)))
  }
  io.overflow := laneOverflows.asUInt.orR
  val buckets = RegInit(0.U.asTypeOf(new GHBarrierLatencyBucket(lanes)))
  val resolving = Wire(Vec(lanes, Bool()))
  val available = Wire(Vec(lanes, Bool()))
  val countOverflow = Wire(Vec(lanes, Bool()))
  val cycleOverflow = Wire(Vec(lanes, Bool()))
  val eventNeedsBucket = io.barrierEvent.valid && io.barrierEvent.bits > io.barrierSafeWatermark
  for (i <- 0 until lanes) {
    val key = (io.barrierBase + i.U)(indexBits - 1, 0)
    val selected = io.barrierEvent.bits(indexBits - 1, 0) === key
    resolving(i) := buckets.valid(i) && buckets.seq(i) <= io.barrierSafeWatermark
    val canAccept = !buckets.valid(i) || resolving(i) || buckets.seq(i) === io.barrierEvent.bits
    val accepted = eventNeedsBucket && selected && canAccept
    available(i) := selected && canAccept
    countOverflow(i) := accepted && buckets.valid(i) && !resolving(i) &&
      buckets.count(i) === ~0.U(64.W)
    cycleOverflow(i) := accepted && buckets.valid(i) && !resolving(i) &&
      buckets.requestCycleSum(i) > (~0.U(64.W) - io.barrierCurrentCycle)

    when (io.barrierResetStats) {
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
          buckets.seq(i) := io.barrierEvent.bits
          buckets.count(i) := 1.U
          buckets.requestCycleSum(i) := io.barrierCurrentCycle
        }.otherwise {
          buckets.count(i) := buckets.count(i) + 1.U
          buckets.requestCycleSum(i) := buckets.requestCycleSum(i) + io.barrierCurrentCycle
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
  io.barrierResolvedCount := exactSum((0 until lanes).map(i =>
    Mux(resolving(i), buckets.count(i), 0.U(64.W))))
  io.barrierResolvedRequest := exactSum((0 until lanes).map(i =>
    Mux(resolving(i), buckets.requestCycleSum(i), 0.U(64.W))))
  io.barrierEventAvailable := available.asUInt.orR
  io.barrierCountOverflow := countOverflow.asUInt.orR
  io.barrierCycleOverflow := cycleOverflow.asUInt.orR
  for (i <- 0 until 16) io.observeAddress(i) := Cat(bucketValid(i), bucketSeq(i),
    bucketStore(i).asUInt, bucketFirstStore(i).asUInt, bucketLoadFirst(i).asUInt,
    bucketStoreFirst(i).asUInt, bucketStrictWriteRead(i).asUInt)

  for (i <- 0 until 16) io.observeBarrier(i) := Cat(buckets.valid(i), buckets.seq(i),
    buckets.count(i), buckets.requestCycleSum(i))

}
