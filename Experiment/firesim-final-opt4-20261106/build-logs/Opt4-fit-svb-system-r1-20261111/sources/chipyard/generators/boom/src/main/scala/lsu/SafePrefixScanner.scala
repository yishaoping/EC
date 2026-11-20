package boom.lsu

import chisel3._
import chisel3.util._

/** Exact combinational cyclic prefix over fixed physical packet slots.
  * An offset in 1..window maps to one slot, and each slot has exactly one
  * such offset. Compare full sequence once per slot, then choose the first
  * failing distance. No state, events, PASS conditions or capacities change.
  */
class SafePrefixScanner(val window: Int = 256, val seqBits: Int = 32) extends Module {
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
  val low = io.watermark(indexBits - 1, 0)
  val high = io.watermark(seqBits - 1, indexBits)
  val nextHigh = high + 1.U
  val failed = VecInit((0 until window).map { i =>
    val nextWindow = i.U <= low
    // Only two high halves can be expected in one cyclic window. Share the
    // incrementer rather than forming one high+predicate adder per slot.
    val expectedHigh = Mux(nextWindow, nextHigh, high)
    val expectedSeq = Cat(expectedHigh, i.U(indexBits.W))
    val pass = io.allocated(i) && io.seq(i) === expectedSeq &&
      io.completed(i) && io.passed(i)
    !pass
  })
  // Cyclic distance order is [low+1, window-1], then [0, low]. Two ordinary
  // priority encoders and one subtraction find exactly the same first fail
  // as a minimum over 256 independently subtracted distances.
  val afterLow = VecInit((0 until window).map(i => failed(i) && i.U > low))
  val firstSlot = Mux(afterLow.asUInt.orR,
    PriorityEncoder(afterLow.asUInt), PriorityEncoder(failed.asUInt))
  val distanceLow = firstSlot - low
  val distance = Mux(distanceLow === 0.U,
    window.U((indexBits + 1).W), Cat(0.U(1.W), distanceLow))
  io.advance := Mux(failed.asUInt.orR, distance - 1.U,
    window.U((indexBits + 1).W))
}
