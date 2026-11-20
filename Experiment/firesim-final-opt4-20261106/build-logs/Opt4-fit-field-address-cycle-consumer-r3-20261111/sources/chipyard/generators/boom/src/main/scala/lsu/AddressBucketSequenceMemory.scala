package boom.lsu

import chisel3._
import chisel3.util._

/** Each physical copy has only two asynchronous readers and one writer.
  * All copies receive every write on the same edge. Parent validity hides
  * unwritten payload, and no reset initializes or clears memory contents.
  */
class AddressBucketSequenceReplica(slots: Int, sequenceBits: Int) extends Module {
  val io = IO(new Bundle {
    val readIndex = Input(Vec(2, UInt(log2Ceil(slots).W)))
    val readData = Output(Vec(2, UInt(sequenceBits.W)))
    val writeEnable = Input(Bool())
    val writeIndex = Input(UInt(log2Ceil(slots).W))
    val writeData = Input(UInt(sequenceBits.W))
  })
  val payload = Mem(slots, UInt(sequenceBits.W))
  for (r <- 0 until 2) { io.readData(r) := payload.read(io.readIndex(r)) }
  when (io.writeEnable) { payload.write(io.writeIndex, io.writeData) }
}

class AddressBucketSequenceMemory(slots: Int, readers: Int, sequenceBits: Int = 32) extends Module {
  require(slots > 1 && isPow2(slots) && readers > 0 && sequenceBits > log2Ceil(slots))
  val io = IO(new Bundle {
    val readIndex = Input(Vec(readers, UInt(log2Ceil(slots).W)))
    val readData = Output(Vec(readers, UInt(sequenceBits.W)))
    val writeEnable = Input(Bool())
    val writeIndex = Input(UInt(log2Ceil(slots).W))
    val writeData = Input(UInt(sequenceBits.W))
  })
  for (copy <- 0 until (readers + 1) / 2) {
    val replica = Module(new AddressBucketSequenceReplica(slots, sequenceBits))
    replica.io.writeEnable := io.writeEnable
    replica.io.writeIndex := io.writeIndex
    replica.io.writeData := io.writeData
    for (port <- 0 until 2) {
      val reader = copy * 2 + port
      if (reader < readers) {
        replica.io.readIndex(port) := io.readIndex(reader)
        io.readData(reader) := replica.io.readData(port)
      } else {
        replica.io.readIndex(port) := 0.U
      }
    }
  }
}

object AddressBucketSequenceMemory {
  def matches(stored: UInt, sequence: UInt, indexBits: Int): Bool =
    stored(stored.getWidth - 1, indexBits) === sequence(sequence.getWidth - 1, indexBits)
}
