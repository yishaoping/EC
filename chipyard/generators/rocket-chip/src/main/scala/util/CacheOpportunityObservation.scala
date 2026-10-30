package freechips.rocketchip.util

import chisel3._
import chisel3.experimental.IntParam
import chisel3.util._

/** Simulation inputs only. No outputs, state, or ready/valid feedback. */
class CacheOpportunityEvent extends Bundle {
  val valid = Bool()
  val kind = UInt(8.W)
  val flags = UInt(32.W)
  val address = UInt(64.W)
  val tag = UInt(64.W)
  val value = UInt(64.W)
  val set = UInt(32.W)
  val way = UInt(32.W)
  val occupancy = UInt(32.W)
}

class CacheOpportunityObserver(level: Int, sets: Int, ways: Int, blockBytes: Int,
    mshrs: Int, ports: Int) extends BlackBox(Map(
      "LEVEL" -> IntParam(level), "SETS" -> IntParam(sets), "WAYS" -> IntParam(ways),
      "BLOCK_BYTES" -> IntParam(blockBytes), "MSHRS" -> IntParam(mshrs), "PORTS" -> IntParam(ports)))
    with HasBlackBoxResource {
  val io = IO(new Bundle {
    val clock = Input(Clock())
    val reset = Input(Bool())
    val clear = Input(Bool())
    val enable = Input(Bool())
    val stop = Input(Bool())
    val instance_id = Input(UInt(32.W))
    val cycle = Input(UInt(64.W))
    val mshr_occupancy = Input(UInt(32.W))
    val mshr_full = Input(Bool())
    val event_valid = Input(UInt(ports.W))
    val event_kind = Input(UInt((ports * 8).W))
    val event_flags = Input(UInt((ports * 32).W))
    val event_address = Input(UInt((ports * 64).W))
    val event_tag = Input(UInt((ports * 64).W))
    val event_value = Input(UInt((ports * 64).W))
    val event_set = Input(UInt((ports * 32).W))
    val event_way = Input(UInt((ports * 32).W))
    val event_occupancy = Input(UInt((ports * 32).W))
  })
  addResource("/vsrc/CacheOpportunityObserver.sv")
  addResource("/csrc/cache_opportunity.cc")
}

object CacheOpportunityObservation {
  def event(valid: Bool, kind: Int, flags: UInt = 0.U, address: UInt = 0.U,
      tag: UInt = 0.U, value: UInt = 0.U, set: UInt = 0.U,
      way: UInt = 0.U, occupancy: UInt = 0.U): CacheOpportunityEvent = {
    val e = Wire(new CacheOpportunityEvent)
    e.valid := valid; e.kind := kind.U; e.flags := flags; e.address := address
    e.tag := tag; e.value := value; e.set := set; e.way := way; e.occupancy := occupancy
    e
  }

  def emit(level: Int, sets: Int, ways: Int, blockBytes: Int, mshrs: Int,
      clk: Clock, rst: Bool, clear: Bool, enable: Bool, stop: Bool,
      id: UInt, cycle: UInt, occupied: UInt, full: Bool,
      events: Seq[CacheOpportunityEvent]): Unit = {
    require(events.nonEmpty)
    val o = Module(new CacheOpportunityObserver(level, sets, ways, blockBytes, mshrs, events.size))
    o.io.clock := clk; o.io.reset := rst; o.io.clear := clear; o.io.enable := enable
    o.io.stop := stop; o.io.instance_id := id; o.io.cycle := cycle
    o.io.mshr_occupancy := occupied; o.io.mshr_full := full
    o.io.event_valid := VecInit(events.map(_.valid)).asUInt
    o.io.event_kind := VecInit(events.map(_.kind)).asUInt
    o.io.event_flags := VecInit(events.map(_.flags)).asUInt
    o.io.event_address := VecInit(events.map(_.address)).asUInt
    o.io.event_tag := VecInit(events.map(_.tag)).asUInt
    o.io.event_value := VecInit(events.map(_.value)).asUInt
    o.io.event_set := VecInit(events.map(_.set)).asUInt
    o.io.event_way := VecInit(events.map(_.way)).asUInt
    o.io.event_occupancy := VecInit(events.map(_.occupancy)).asUInt
  }

  def rotate(x: UInt, shift: Int): UInt = {
    val v = Wire(UInt(64.W)); v := x
    val n = shift % 64
    if (n == 0) v else Cat(v(63 - n, 0), v(63, 64 - n))
  }

  /** XOR/rotation diagnostic hash; not a cryptographic data proof. */
  def rowHash(x: UInt, bits: Int): UInt =
    (0 until ((bits + 63) / 64)).map(i =>
      rotate(x(math.min(bits - 1, i * 64 + 63), i * 64), i * 7)).reduce(_ ^ _)

  def lineHash(rows: Seq[UInt], bits: Int): UInt =
    rows.zipWithIndex.map { case (r, i) =>
      rotate(rowHash(r, bits), i * ((bits + 63) / 64) * 7)
    }.reduce(_ ^ _)
}
