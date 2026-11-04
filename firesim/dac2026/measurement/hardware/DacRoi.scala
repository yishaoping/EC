package freechips.rocketchip.util

import chisel3._
import chisel3.util._
import freechips.rocketchip.config.Field

case object DacRoiEnabled extends Field[Boolean](false)

class DacRoiRequest extends Bundle {
  val token = UInt(64.W)
  val epoch = UInt(64.W)
  val satp = UInt(64.W)
  val hart = UInt(64.W)
}
class DacRoiReply extends Bundle {
  val token = UInt(64.W)
  val error = UInt(64.W)
  val state = UInt(64.W)
  val epoch = UInt(64.W)
  val begin = UInt(64.W)
  val end = UInt(64.W)
  val drain = UInt(64.W)
  val outstanding = UInt(64.W)
  val generated = UInt(64.W)
  val completed = UInt(64.W)
  val faults = UInt(64.W)
}

/** B-only source-clock observer. Control ready NEVER feeds the BOOM pipeline.
  * Retired marker metadata is delayed one cycle by BOOM's debug instruction
  * memory. originalTick tags that retirement edge, not its delivery edge.
  * This measures ROI boundaries only; it provides NO execution timestamps.
  */
class DacRoiController(retireWidth: Int) extends Module {
  val io = IO(new Bundle {
    val request = Flipped(Decoupled(new DacRoiRequest))
    val reply = Decoupled(new DacRoiReply)
    val valid = Input(Vec(retireWidth, Bool()))
    val insn = Input(Vec(retireWidth, UInt(32.W)))
    val originalTick = Input(UInt(64.W))
    val satp = Input(UInt(64.W))
    val prv = Input(UInt(2.W))
    val hart = Input(UInt(64.W))
    val tick = Output(UInt(64.W))
  })
  val idle = 0.U(64.W); val armed = 1.U(64.W); val running = 2.U(64.W)
  val ended = 3.U(64.W); val drained = 4.U(64.W); val poison = 5.U(64.W)
  val tick = RegInit(0.U(64.W))
  val overflow = RegInit(false.B)
  tick := tick + 1.U
  when(tick.andR) { overflow := true.B }
  io.tick := tick

  val state = RegInit(idle)
  val epoch = RegInit(0.U(64.W))
  val expectedSatp = RegInit(0.U(64.W))
  val beginTick = RegInit(0.U(64.W))
  val endTick = RegInit(0.U(64.W))
  val faults = RegInit(0.U(64.W))
  val lastSerial = RegInit(0.U(56.W))
  val reply = RegInit(0.U.asTypeOf(new DacRoiReply))
  val replyValid = RegInit(false.B)
  io.reply.bits := reply
  io.reply.valid := replyValid
  io.request.ready := !replyValid || io.reply.ready
  when(io.reply.fire) { replyValid := false.B }

  val matches = io.satp === expectedSatp && io.prv === 0.U && io.hart === 0.U
  val starts = VecInit((0 until retireWidth).map(w => io.valid(w) && matches && io.insn(w) === "h6b100013".U))
  val ends = VecInit((0 until retireWidth).map(w => io.valid(w) && matches && io.insn(w) === "h6b200013".U))
  val active = state === armed || state === running || state === ended
  val start = starts.asUInt.orR; val end = ends.asUInt.orR
  when(active && (start || end)) {
    when(PopCount(starts) +& PopCount(ends) =/= 1.U) {
      state := poison; faults := faults | 4.U
    }.elsewhen(start && state === armed) {
      beginTick := io.originalTick; state := running
    }.elsewhen(end && state === running && io.originalTick > beginTick) {
      endTick := io.originalTick; state := ended
    }.otherwise {
      state := poison; faults := faults | 2.U
    }
  }

  when(io.request.fire) {
    val q = io.request.bits
    val op = q.token(7, 0)
    val serial = q.token(63, 8)
    val goodToken = serial > lastSerial
    val sameEpoch = q.epoch === epoch
    val okArm = op === 1.U && (state === idle || state === drained) &&
      q.epoch > epoch && q.satp(63, 60) =/= 0.U && q.hart === 0.U && !overflow && !tick.andR
    val okEnd = op === 2.U && sameEpoch && state === ended && faults === 0.U
    val okDrain = op === 3.U && sameEpoch && state === ended && faults === 0.U
    val okAbort = op === 4.U && q.epoch >= epoch
    val ok = goodToken && (okArm || okEnd || okDrain || okAbort)
    replyValid := true.B
    reply := 0.U.asTypeOf(new DacRoiReply)
    reply.token := q.token
    reply.error := Mux(ok, 0.U, 1.U)
    reply.state := state
    reply.epoch := epoch
    reply.begin := beginTick
    reply.end := endTick
    reply.drain := endTick // B has no checker, producer, transport or outstanding task.
    reply.faults := faults
    when(goodToken) { lastSerial := serial }
    when(ok && okArm) {
      epoch := q.epoch; expectedSatp := q.satp; state := armed
      beginTick := 0.U; endTick := 0.U; faults := 0.U
      reply.epoch := q.epoch; reply.state := armed
      reply.begin := 0.U; reply.end := 0.U; reply.drain := 0.U; reply.faults := 0.U
    }
    when(ok && okDrain) { state := drained; reply.state := drained }
    when(ok && okAbort) {
      state := idle; epoch := q.epoch; reply.state := idle; reply.epoch := q.epoch
    }
  }
  // A wrapped source time can never be repaired by starting a new epoch.
  when(overflow || tick.andR) { state := poison; faults := faults | 1.U }
}
