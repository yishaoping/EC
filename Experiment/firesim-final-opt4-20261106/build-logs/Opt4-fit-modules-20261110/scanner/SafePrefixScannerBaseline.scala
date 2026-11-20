package boom.lsu

import chisel3._
import chisel3.util._

/** Exact combinational cyclic prefix over fixed physical packet slots.
  * An offset in 1..window maps to one slot, and each slot has exactly one
  * such offset. Compare full sequence once per slot, then choose the first
  * failing distance. No state, events, PASS conditions or capacities change.
  */
class SafePrefixScannerBaseline(val window: Int = 256, val seqBits: Int = 32) extends Module {
  require(isPow2(window) && window > 1 && seqBits > log2Ceil(window))
  private val indexBits = log2Ceil(window)
  val io = IO(new Bundle {
    val watermark = Input(UInt(seqBits.W))
    val allocated = Input(Vec(window, Bool()))
    val completed = Input(Vec(window, Bool()))
    val passed = Input(Vec(window, Bool()))
    val seq = Input(Vec(window, UInt(seqBits.W)))
    val advance = Output(UInt((indexBits + 1).W))
  })
  var contiguous = true.B
  var safeAdvance = 0.U((indexBits + 1).W)
  for (offset <- 1 to window) {
    val seq = io.watermark + offset.U
    val idx = seq(indexBits - 1, 0)
    val slotPass = io.allocated(idx) && io.seq(idx) === seq &&
      io.completed(idx) && io.passed(idx)
    contiguous = contiguous && slotPass
    safeAdvance = Mux(contiguous, offset.U, safeAdvance)
  }
  io.advance := safeAdvance
}
