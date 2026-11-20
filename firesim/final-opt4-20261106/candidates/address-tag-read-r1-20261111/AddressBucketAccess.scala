package boom.lsu

import chisel3._
import chisel3.util._

/** Combinational access to an unchanged power-of-two bucket register bank.
  * Decode once per address, then share that decode across all payload bits.
  * No register, capacity, arithmetic width, or cycle boundary is changed.
  */
object AddressBucketAccess {
  def decode(index: UInt, entries: Int): Seq[Bool] = {
    require(isPow2(entries))
    require(index.getWidth == log2Ceil(entries))
    (0 until entries).map(i => index === i.U)
  }

  def select(selects: Seq[Bool], values: Seq[UInt]): UInt = {
    require(selects.nonEmpty && selects.size == values.size)
    Mux1H(selects.zip(values))
  }
}
