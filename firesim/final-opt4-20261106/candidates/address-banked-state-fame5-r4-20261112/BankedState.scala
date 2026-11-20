package bankedstate

import chisel3._
import chisel3.util._
import chisel3.experimental.annotate
import midas.targetutils.EnableModelMultiThreadingAnnotation
import org.chipsalliance.cde.config.{Config, Parameters}

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
class BucketBank extends Module {
  val io = IO(new Bundle {
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
    // Exact finite verification observations. Both area sides use this same
    // harness; their absolute area is not complete-module or full-host area.
    val observe = Output(Vec(16, UInt(1314.W)))
  })
  val bucketValid = RegInit(VecInit(Seq.fill(16)(false.B)))
  val bucketSeq = Reg(Vec(16, UInt(32.W)))
  val bucketStore = Reg(Vec(16, Vec(4, UInt(64.W))))
  val bucketLoadFirst = Reg(Vec(16, Vec(4, UInt(64.W))))
  val bucketStoreFirst = Reg(Vec(16, Vec(4, UInt(64.W))))
  val bucketStrictWriteRead = Reg(Vec(16, Vec(4, UInt(64.W))))
  val bucketFirstStore = Reg(Vec(16, Vec(4, UInt(64.W))))
  for (i <- 0 until 16) {
    val key = (io.base + i.U)(7, 0)
    def delta(sources: Seq[Source]): Vec[UInt] =
      sourceprojected.AddressBucketGrouped.lookup(sources.map(_.key),
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
        when (boom.lsu.AddressBucketUpdate.enabled(isCurrent, bucketLoadFirstDelta(g))) {
          bucketLoadFirst(i)(g) := Mux(allocate, bucketLoadFirstDelta(g), loadFirstNextWide(63, 0))
        }
        when (boom.lsu.AddressBucketUpdate.enabled(isCurrent, bucketStoreFirstDelta(g))) {
          bucketStoreFirst(i)(g) := Mux(allocate, bucketStoreFirstDelta(g), storeFirstNextWide(63, 0))
        }
        when (boom.lsu.AddressBucketUpdate.enabled(isCurrent, bucketStrictWriteReadDelta(g))) {
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
    // Low field first: 5 metrics x 4 granules, sequence, valid, carry OR.
    val values = bucketStore(i).toSeq ++ bucketFirstStore(i).toSeq ++
      bucketLoadFirst(i).toSeq ++ bucketStoreFirst(i).toSeq ++ bucketStrictWriteRead(i).toSeq
    io.observe(i) := Cat(overflows.reduce(_ || _), bucketValid(i), bucketSeq(i), Cat(values.reverse))
  }
}

class BankedState(val banks: Int) extends RawModule {
  require(Set(2, 4, 16).contains(banks))
  val clock = midas.widgets.RationalClockBridge().io.clocks.head
  val reset = WireInit(false.B)
  val io = Wire(new Bundle {
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
    val observe = Output(Vec(banks * 16, UInt(1314.W)))
    val anchor = Output(UInt(32.W))
  })
  withClockAndReset(clock, reset) {
    for (b <- 0 until banks) {
      val bank = Module(new BucketBank)
      annotate(EnableModelMultiThreadingAnnotation(bank))
      bank.io.base := (b * 16).U
      bank.io.loadSources := io.loadSources
      bank.io.storeSources := io.storeSources
      bank.io.strictSources := io.strictSources
      bank.io.newStore := io.newStore
      bank.io.newFirstStore := io.newFirstStore
      bank.io.processSeq := io.processSeq
      bank.io.retiringSeq := io.retiringSeq
      bank.io.processCommit := io.processCommit
      bank.io.safeAdvance := io.safeAdvance
      bank.io.safeError := io.safeError
      bank.io.resetStats := io.resetStats
      for (i <- 0 until 16) io.observe(b * 16 + i) := bank.io.observe(i)
    }
    io.anchor := io.observe(0)(31, 0)
    midas.widgets.PeekPokeBridge(clock, reset, "io" -> io)
  }
}
class Smoke2(implicit p: Parameters) extends BankedState(2)
class Smoke4(implicit p: Parameters) extends BankedState(4)
class Full16(implicit p: Parameters) extends BankedState(16)
class PlainConfig extends Config(new Config((site, here, up) => {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => false
}) ++ new firesim.configs.DacXilinxAlveoConfig)
class ThreadedConfig extends Config(new Config((site, here, up) => {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => true
}) ++ new firesim.configs.DacXilinxAlveoConfig)
