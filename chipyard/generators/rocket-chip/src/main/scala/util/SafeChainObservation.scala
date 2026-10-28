package freechips.rocketchip.util

import chisel3._
import chisel3.experimental.IntParam
import chisel3.util._
import chisel3.util.experimental.BoringUtils

/** OBSERVATION_ONLY: input-only simulation sink. No functional consumers.
  * The shared BOOM cycle and ROI taps are deliberately NOT CDC protocol state.
  * They are used only to label simulation events; local cycles/$time are kept.
  */
class SafeChainEventLogger(kind: Int) extends BlackBox(Map("KIND" -> IntParam(kind)))
    with HasBlackBoxResource {
  val io = IO(new Bundle {
    val clock = Input(Clock())
    val reset = Input(Bool())
    val roi = Input(Bool())
    val sample = Input(Bool())
    val force_event = Input(Bool())
    val core_cycle = Input(UInt(64.W))
    val local_cycle = Input(UInt(64.W))
    val hart = Input(UInt(16.W))
    val change_key = Input(UInt(1024.W))
    val data = Input(UInt(1024.W))
  })
  addResource("/vsrc/SafeChainEventLogger.v")
}

object SafeChainObservation {
  val CycleTap = "ec_safe_chain_observation_cycle_v1"
  val RoiTap = "ec_safe_chain_observation_roi_v1"

  def context(): (UInt, Bool) = {
    val cycle = WireInit(0.U(64.W))
    val roi = WireInit(false.B)
    BoringUtils.addSink(cycle, CycleTap)
    BoringUtils.addSink(roi, RoiTap)
    (cycle, roi)
  }

  def emit(kind: Int, clk: Clock, rst: Bool, cycle: UInt, local: UInt,
           hart: UInt, roi: Bool, sample: Bool, fields: Seq[UInt],
           key: UInt, force: Bool = false.B): Unit = {
    require(fields.length <= 16)
    // getWidth throws for otherwise valid UInts declared without an explicit
    // width (for example a pipeline PC register).  Known widths are checked;
    // unknown widths are resolved by the fixed-width observation sinks below.
    fields.foreach(_.widthOption.foreach(width =>
      require(width <= 64, "SC1 fields must fit one hex64 word")))
    key.widthOption.foreach(width =>
      require(width <= 1024, "SC1 change key exceeds observation bus"))
    val logger = Module(new SafeChainEventLogger(kind))
    logger.suggestName(s"safe_chain_observer_$kind")
    logger.io.clock := clk
    logger.io.reset := rst
    logger.io.roi := roi
    logger.io.sample := sample
    logger.io.force_event := force
    logger.io.core_cycle := cycle
    logger.io.local_cycle := local
    logger.io.hart := hart
    logger.io.change_key := key
    // Chisel Bool is a UInt subtype, and asUInt preserves the Bool runtime
    // type. Use a fixed UInt sink so Bool, known-width UInt, and unknown-width
    // UInt fields all converge to the 16-word observation bus without calling
    // Bool.cloneTypeWidth or relying on an unknown intermediate Vec width.
    val words = Wire(Vec(16, UInt(64.W)))
    for (i <- 0 until 16) {
      words(i) := 0.U(64.W)
    }
    fields.zipWithIndex.foreach { case (field, i) =>
      val value = field match {
        case bit: Bool => Mux(bit, 1.U(1.W), 0.U(1.W))
        case other => other
      }
      words(i) := value
    }
    logger.io.data := words.asUInt
  }
}
