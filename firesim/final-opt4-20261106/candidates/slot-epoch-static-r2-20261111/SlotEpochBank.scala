package boom.lsu

import chisel3._
import chisel3.util._

// Register representation only. All three write sites remain independent.
// Later ports win only at the same word; synchronous reset wins over all ports.
class SlotEpochBank(val sets: Int, val ways: Int) {
  require(isPow2(sets) && isPow2(ways) && sets > 1)
  private val setBits = log2Ceil(sets)
  private val wayBits = log2Ceil(ways)
  private val entries = sets * ways
  private val words = RegInit(VecInit(Seq.fill(entries)(0.U(16.W))))
  private val enable = WireDefault(VecInit(Seq.fill(3)(false.B)))
  private val address = WireDefault(VecInit(Seq.fill(3)(0.U(log2Ceil(entries).W))))
  private val data = WireDefault(VecInit(Seq.fill(3)(0.U(16.W))))
  private def index(set: UInt, way: UInt): UInt = {
    val s = set.pad(setBits)(setBits - 1, 0)
    if (ways == 1) s else Cat(s, way.pad(wayBits)(wayBits - 1, 0))
  }
  for (i <- 0 until entries; p <- 0 until 3) {
    when (enable(p) && address(p) === i.U) { words(i) := data(p) }
  }
  def read(set: UInt, way: UInt): UInt = {
    val a = index(set, way)
    Mux1H((0 until entries).map(i => (a === i.U) -> words(i)))
  }
  def readSet(set: UInt): Vec[UInt] =
    VecInit((0 until ways).map(w => read(set, w.U)))
  def write(port: Int, set: UInt, way: UInt, value: UInt): Unit = {
    require(port >= 0 && port < 3)
    enable(port) := true.B
    address(port) := index(set, way)
    data(port) := value
  }
  def snapshot: Vec[UInt] = words
}
