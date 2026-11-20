package boom.lsu

import chisel3._
import chisel3.util._

/** Balanced exact argmax of valid (package, generation, slot) tuples. */
object NewestSafeEntry {
  def apply(valid: Seq[Bool], seq: Seq[UInt], generation: Seq[UInt]): (Bool, UInt) = {
    require(valid.nonEmpty && valid.size == seq.size && valid.size == generation.size)
    val bits = log2Ceil(valid.size) max 1
    val leaves = valid.indices.map(i =>
      (valid(i), Cat(seq(i), generation(i), i.U(bits.W)), i.U(bits.W)))
    def maximum(items: Seq[(Bool, UInt, UInt)]): (Bool, UInt, UInt) = {
      if (items.size == 1) items.head
      else {
        val (a, b) = items.splitAt(items.size / 2)
        val left = maximum(a); val right = maximum(b)
        val useRight = right._1 && (!left._1 || right._2 > left._2)
        (left._1 || right._1, Mux(useRight, right._2, left._2),
          Mux(useRight, right._3, left._3))
      }
    }
    val winner = maximum(leaves)
    (winner._1, Mux(winner._1, winner._3, 0.U(bits.W)))
  }
}
