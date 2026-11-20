package geometryreference

import chisel3._
import chisel3.util._

/** Read a complete stored tag before comparing its upper bits.
  * Every lane retains its full valid and 32-bit sequence state. Subtraction
  * also handles unaligned bases and wraparound, without a target register.
  */
object BankTagRead {
  def matches(valid: Seq[Bool], seq: Seq[UInt], base: UInt, query: UInt): Bool = {
    require(valid.size == 16 && seq.size == 16)
    require(base.getWidth == 8 && query.getWidth == 32)
    val offset = (query(7, 0) - base)(7, 0)
    val lane = offset(3, 0)
    val selectedValid = VecInit(valid)(lane)
    val selectedSeq = VecInit(seq)(lane)
    offset(7, 4) === 0.U && selectedValid && selectedSeq(31, 8) === query(31, 8)
  }
}
