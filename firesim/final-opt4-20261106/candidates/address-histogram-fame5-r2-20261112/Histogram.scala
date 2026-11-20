package histogramfame

import chisel3._
import chisel3.util._
import chisel3.experimental.annotate
import midas.targetutils.EnableModelMultiThreadingAnnotation
import org.chipsalliance.cde.config.{Config, Parameters}

// The complete strict histogram has 16 ordinary plus 64 overflow sources.
// Counts are the actual touched-mask bounds, not architectural counters.
class Source extends Bundle {
  val key = UInt(8.W)
  val bytes = UInt(4.W)
  val words4 = UInt(2.W)
  val words8 = UInt(2.W)
  val lines = UInt(1.W)
  def counts: Seq[UInt] = Seq(bytes, words4, words8, lines)
}

class HistogramBucket extends Module {
  val io = IO(new Bundle {
    val sources = Input(Vec(80, new Source))
    val key = Input(UInt(8.W))
    val result = Output(UInt(256.W))
  })
  // lookup is a source-projected version of the installed grouped histogram:
  // compact4, scatter, and width-bounded reduction are unchanged.
  val result = sourceprojected.AddressBucketGrouped.lookup(
    io.sources.map(_.key), io.sources.map(_.counts), Seq(8, 3, 2, 1), io.key)
  io.result := Cat(result.reverse)
}

class Histogram(val slots: Int) extends RawModule {
  require(Set(2, 4, 256).contains(slots))
  val clock = midas.widgets.RationalClockBridge().io.clocks.head
  val reset = WireInit(false.B)
  val io = Wire(new Bundle {
    val sources = Input(Vec(80, new Source))
    val result = Output(Vec(slots, UInt(256.W)))
    val anchor = Output(UInt(32.W))
  })
  // Keep selected models direct children of the bridge harness. Installed
  // PromoteSubmodule cannot promote a nonlocal instance annotation.
  withClockAndReset(clock, reset) {
    for (i <- 0 until slots) {
      val bucket = Module(new HistogramBucket)
      annotate(EnableModelMultiThreadingAnnotation(bucket))
      bucket.io.sources := io.sources
      bucket.io.key := i.U(8.W)
      io.result(i) := bucket.io.result
    }
    io.anchor := io.result(0)(31, 0)
    midas.widgets.PeekPokeBridge(clock, reset, "io" -> io)
  }
}

class Smoke2(implicit p: Parameters) extends Histogram(2)
class Smoke4(implicit p: Parameters) extends Histogram(4)
class Full256(implicit p: Parameters) extends Histogram(256)

class PlainConfig extends Config(new Config((site, here, up) => {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => false
}) ++ new firesim.configs.DacXilinxAlveoConfig)
class ThreadedConfig extends Config(new Config((site, here, up) => {
  case midas.GenerateMultiCycleRamModels => true
  case midas.EnableModelMultiThreading => true
}) ++ new firesim.configs.DacXilinxAlveoConfig)
