package boom.lsu

import chisel3._
import chisel3.util._

/** Counter state remains 64 bits; allocation and delta hits share the update. */
object AddressBucketUpdate {
  def enabled(current: Bool, delta: UInt): Bool = current || delta.orR
}
