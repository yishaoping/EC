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
  val firstFailureDistances = (0 until window).map { i =>
    val nextWindow = i.U <= low
    val expectedHigh = high + nextWindow.asUInt
    val expectedSeq = Cat(expectedHigh, i.U(indexBits.W))
    val distanceLow = i.U(indexBits.W) - low
    val distance = Mux(distanceLow === 0.U,
      window.U((indexBits + 1).W), Cat(0.U(1.W), distanceLow))
    val pass = io.allocated(i) && io.seq(i) === expectedSeq &&
      io.completed(i) && io.passed(i)
    Mux(pass, (window + 1).U((indexBits + 1).W), distance)
  }
  def minimum(xs: Seq[UInt]): UInt = {
    if (xs.size == 1) xs.head
    else minimum(xs.grouped(2).map {
      case Seq(a,b) => Mux(a < b, a, b)
      case Seq(a) => a
    }.toSeq)
  }
  io.advance := minimum(firstFailureDistances) - 1.U
}
