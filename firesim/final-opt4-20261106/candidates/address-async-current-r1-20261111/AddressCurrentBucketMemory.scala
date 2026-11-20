package boom.lsu

import chisel3._
import chisel3.util._

/** Full-width payload with two asynchronous reads and one synchronous writer.
  * Validity stays in PackageAddressStats. No read or write adds a cycle.
  */
class AddressCurrentBucketMemory(slots: Int) extends Module {
  require(slots > 1 && isPow2(slots))
  val io = IO(new Bundle {
    val currentIndex = Input(UInt(log2Ceil(slots).W))
    val retiringIndex = Input(UInt(log2Ceil(slots).W))
    val writeEnable = Input(Bool())
    val writeData = Input(Vec(2, Vec(4, UInt(64.W))))
    val current = Output(Vec(2, Vec(4, UInt(64.W))))
    val retiring = Output(Vec(2, Vec(4, UInt(64.W))))
  })
  val payload = Mem(slots, Vec(2, Vec(4, UInt(64.W))))
  io.current := payload.read(io.currentIndex)
  io.retiring := payload.read(io.retiringIndex)
  when (io.writeEnable) { payload.write(io.currentIndex, io.writeData) }
}

object AddressCurrentBucketMemory {
  def base(valid: Bool, value: UInt): UInt = Mux(valid, value, 0.U(64.W))
  def sum(valid: Bool, value: UInt, delta: UInt): UInt =
    base(valid, value) +& delta.pad(64)
}
