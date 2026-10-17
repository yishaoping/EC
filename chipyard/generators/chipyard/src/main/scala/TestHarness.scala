package chipyard

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils
import freechips.rocketchip.subsystem.{TilesLocated, InSubsystem}
import boom.common.BoomTileAttachParams

import scala.collection.mutable.{ArrayBuffer, LinkedHashMap}
import freechips.rocketchip.diplomacy.{LazyModule}
import org.chipsalliance.cde.config.{Field, Parameters}
import freechips.rocketchip.util.{ResetCatchAndSync}
import freechips.rocketchip.prci.{ClockBundle, ClockBundleParameters, ClockSinkParameters, ClockParameters}

import chipyard.harness.{ApplyHarnessBinders, HarnessBinders}
import chipyard.iobinders.HasIOBinders
import chipyard.clocking.{SimplePllConfiguration, ClockDividerN}

// -------------------------------
// Chipyard Test Harness
// -------------------------------

case object BuildTop extends Field[Parameters => LazyModule]((p: Parameters) => new ChipTop()(p))
case object DefaultClockFrequencyKey extends Field[Double](100.0) // MHz
case object HarnessClockInstantiatorKey extends Field[() => HarnessClockInstantiator](() => new DividerOnlyHarnessClockInstantiator)

trait HasHarnessSignalReferences {
  implicit val p: Parameters
  val harnessClockInstantiator = p(HarnessClockInstantiatorKey)()
  // clock/reset of the chiptop reference clock (can be different than the implicit harness clock/reset)
  var refClockFreq: Double = p(DefaultClockFrequencyKey)
  def setRefClockFreq(freqMHz: Double) = { refClockFreq = freqMHz }
  def getRefClockFreq: Double = refClockFreq
  def buildtopClock: Clock
  def buildtopReset: Reset
  def success: Bool
}

class TestHarness(implicit val p: Parameters) extends Module with HasHarnessSignalReferences {
  val io = IO(new Bundle {
    val success = Output(Bool())
    // Observation-only, continuously evaluated RTL state. The emulator reads
    // these after its final eval, without clocking the machine again.
    val stage1_schema = Output(UInt(8.W))
    val stage1_cache = Output(Vec(28, UInt(64.W)))
    val stage1_lsu = Output(Vec(9, UInt(64.W)))
    val stage1_stq = Output(Vec(64, Vec(4, UInt(64.W))))
  })

  val buildtopClock = Wire(Clock())
  val buildtopReset = Wire(Reset())

  val lazyDut = LazyModule(p(BuildTop)(p)).suggestName("chiptop")
  val dut = Module(lazyDut.module)

  io.success := false.B

  // Match the concrete attachment before accessing its path-dependent
  // tileParams type; the probes only need the resulting plain hart IDs.
  val stage1BoomHartIds: Seq[Int] = p(TilesLocated(InSubsystem)).collect {
    case b: BoomTileAttachParams => b.tileParams.hartId
  }
  io.stage1_schema := 0.U
  io.stage1_cache := 0.U.asTypeOf(io.stage1_cache)
  io.stage1_lsu := 0.U.asTypeOf(io.stage1_lsu)
  io.stage1_stq := 0.U.asTypeOf(io.stage1_stq)
  if (stage1BoomHartIds.size == 1) {
    val hart = stage1BoomHartIds.head
    io.stage1_schema := 1.U
    for (i <- 0 until 28) {
      val value = WireInit(0.U(64.W))
      BoringUtils.addSink(value, s"stage1_cache_${hart}_$i")
      io.stage1_cache(i) := value
    }
    for (i <- 0 until 9) {
      val value = WireInit(0.U(64.W))
      BoringUtils.addSink(value, s"stage1_lsu_${hart}_$i")
      io.stage1_lsu(i) := value
    }
    for (i <- 0 until 64) {
      val value = WireInit(0.U(256.W))
      BoringUtils.addSink(value, s"stage1_stq_${hart}_$i")
      for (j <- 0 until 4) { io.stage1_stq(i)(j) := value(64*j+63, 64*j) }
    }
  }

  val success = io.success

  lazyDut match { case d: HasIOBinders =>
    ApplyHarnessBinders(this, d.lazySystem, d.portMap)
  }

  val refClkBundle = harnessClockInstantiator.requestClockBundle("buildtop_reference_clock", getRefClockFreq * (1000 * 1000))

  buildtopClock := refClkBundle.clock
  buildtopReset := WireInit(refClkBundle.reset)

  val implicitHarnessClockBundle = Wire(new ClockBundle(ClockBundleParameters()))
  implicitHarnessClockBundle.clock := clock
  implicitHarnessClockBundle.reset := reset
  harnessClockInstantiator.instantiateHarnessClocks(implicitHarnessClockBundle)
}
