package sifive.blocks.inclusivecache

import Chisel._
import freechips.rocketchip.guardiancouncil.GH_GlobalParams

/** Per-package L2->DRAM dirty-writeback accounting storage.
  *
  * The verification bitmap lives with BOOM's package tracker.  L2 keeps a
  * separate bucket because one checked package may evict several lines.
  */
class L2DirtyWritebackBucket(val entries: Int) extends Bundle {
  val valid = Vec(entries, Bool())
  val seq = Vec(entries, UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val count = Vec(entries, UInt(64.W))
  val writebackCycleSum = Vec(entries, UInt(64.W))
}
