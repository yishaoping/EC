package boom.lsu

import chisel3._
import chisel3.util._

/** Full sequence payload, one writer and combinational reads at every caller.
  * Bucket validity stays in the parent. No access adds a clock cycle.
  */
class AddressBucketSequenceMemory(slots: Int, readers: Int, sequenceBits: Int = 32) extends Module {
  require(slots > 1 && isPow2(slots) && readers > 0 && sequenceBits > log2Ceil(slots))
  val io = IO(new Bundle {
    val readIndex = Input(Vec(readers, UInt(log2Ceil(slots).W)))
    val readData = Output(Vec(readers, UInt(sequenceBits.W)))
    val writeEnable = Input(Bool())
    val writeIndex = Input(UInt(log2Ceil(slots).W))
    val writeData = Input(UInt(sequenceBits.W))
  })
  val payload = Mem(slots, UInt(sequenceBits.W))
  for (r <- 0 until readers) { io.readData(r) := payload.read(io.readIndex(r)) }
  when (io.writeEnable) { payload.write(io.writeIndex, io.writeData) }
}

object AddressBucketSequenceMemory {
  def matches(stored: UInt, sequence: UInt, indexBits: Int): Bool =
    stored(stored.getWidth - 1, indexBits) === sequence(sequence.getWidth - 1, indexBits)
}
