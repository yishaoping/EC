package boom.lsu

import chisel3._
import freechips.rocketchip.guardiancouncil.GH_GlobalParams

/**
  * A bucket accumulates dirty writebacks belonging to one package until the
  * package reaches the contiguous safe watermark.  Buckets deliberately use
  * independent storage from the verification bitmap so multiple writebacks
  * for one package can be accounted for without changing package state.
  */
class DirtyWritebackBucket(val window: Int) extends Bundle {
  require(window > 0)
  val valid = Vec(window, Bool())
  val seq = Vec(window, UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val count = Vec(window, UInt(64.W))
  val writebackCycleSum = Vec(window, UInt(64.W))
}
