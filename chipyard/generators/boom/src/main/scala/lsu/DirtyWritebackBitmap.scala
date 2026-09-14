package boom.lsu

import chisel3._
import freechips.rocketchip.guardiancouncil.GH_GlobalParams

/**
  * Per-package verification state used by the L1->L2 dirty-writeback
  * statistics.  The sequence vector disambiguates slot reuse when sequence
  * numbers wrap around the finite measurement window.
  */
class DirtyWritebackBitmap(val window: Int) extends Bundle {
  require(window > 0)
  val allocated = Vec(window, Bool())
  val completed = Vec(window, Bool())
  val passed = Vec(window, Bool())
  val seq = Vec(window, UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
}
