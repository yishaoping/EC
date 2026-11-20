package boom.lsu

import chisel3._
import chisel3.util._

/** Unreset full-width duplicate-result payload. Both reads are asynchronous;
  * the single writer acts on exactly the original edge, including reset edges.
  * The original DCache validity/token arrays retain their original semantics.
  */
class AppliedEffectResultMemory(sets: Int, ways: Int, bits: Int) extends Module {
  require(sets > 1 && ways > 1 && isPow2(sets) && isPow2(ways))
  require(bits > 0)
  val io = IO(new Bundle {
    val readSet = Input(Vec(2, UInt(log2Ceil(sets).W)))
    val readWay = Input(Vec(2, UInt(log2Ceil(ways).W)))
    val readData = Output(Vec(2, UInt(bits.W)))
    val writeEnable = Input(Bool())
    val writeSet = Input(UInt(log2Ceil(sets).W))
    val writeWay = Input(UInt(log2Ceil(ways).W))
    val writeData = Input(UInt(bits.W))
  })
  val payload = Mem(sets * ways, UInt(bits.W))
  for (r <- 0 until 2) {
    io.readData(r) := payload.read(AppliedEffectResultMemory.index(io.readSet(r), io.readWay(r)))
  }
  when (io.writeEnable) {
    payload.write(AppliedEffectResultMemory.index(io.writeSet, io.writeWay), io.writeData)
  }
}

object AppliedEffectResultMemory {
  def index(set: UInt, way: UInt): UInt = Cat(set, way)
}
