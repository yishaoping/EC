package boom.lsu
import chisel3._
import chisel3.util._
import boom.common._
import boom.exu.BrUpdateInfo
import boom.util.{IsKilledByBranch, GetNewBrMask}
import org.chipsalliance.cde.config.Parameters
class BoomMSHRBranchKillableQueue[T <: boom.common.HasBoomUOP](gen: T, entries: Int, flush_fn: boom.common.MicroOp => Bool = u => true.B, flow: Boolean = true, holdable: Boolean = false)
  (implicit p: org.chipsalliance.cde.config.Parameters)
  extends boom.common.BoomModule()(p)
  with boom.common.HasBoomCoreParameters
{
  val io = IO(new Bundle {
    val enq     = Flipped(Decoupled(gen))
    val deq     = Decoupled(gen)

    val brupdate  = Input(new BrUpdateInfo())
    val flush   = Input(Bool())
    // Only the MSHR RPQ enables this port. Kills may invalidate the head,
    // but cannot recycle its RAM/identity while an issued replay owns it.
    val hold_head = if (holdable) Some(Input(Bool())) else None
    // A killed, not-yet-issued head still owns companion resources. Expose
    // its immutable payload at cancellation instead of silently skipping it.
    val discarded = if (holdable) Some(Output(Valid(gen))) else None

    val empty   = Output(Bool())
    val count   = Output(UInt(log2Ceil(entries).W))
  })

  val ram     = Mem(entries, gen)
  val valids  = RegInit(VecInit(Seq.fill(entries) {false.B}))
  val uops    = Mem(entries, new MicroOp)
  val brMasks = Reg(Vec(entries, UInt(maxBrCount.W)))

  val enq_ptr = Counter(entries)
  val deq_ptr = Counter(entries)
  val maybe_full = RegInit(false.B)

  val ptr_match = enq_ptr.value === deq_ptr.value
  io.empty := ptr_match && !maybe_full
  val full = ptr_match && maybe_full
  val do_enq = WireInit(io.enq.fire)
  val do_deq = WireInit((io.deq.ready || !valids(deq_ptr.value)) && !io.empty)
  if (holdable) { do_deq := (io.deq.ready || !valids(deq_ptr.value)) && !io.empty && !io.hold_head.get }

  for (i <- 0 until entries) {
    val mask = brMasks(i)
    val uop  = WireInit(uops(i))
    uop.br_mask := brMasks(i)
    valids(i)  := valids(i) && !IsKilledByBranch(io.brupdate, mask) && !(io.flush && flush_fn(uop))
    when (valids(i)) {
      brMasks(i) := GetNewBrMask(io.brupdate, mask)
    }
  }

  when (do_enq) {
    ram(enq_ptr.value)          := io.enq.bits
    valids(enq_ptr.value)       := true.B //!IsKilledByBranch(io.brupdate, io.enq.bits.uop)
    uops(enq_ptr.value)         := io.enq.bits.uop
    brMasks(enq_ptr.value) := GetNewBrMask(io.brupdate, io.enq.bits.uop)
    enq_ptr.inc()
  }

  when (do_deq) {
    valids(deq_ptr.value) := false.B
    deq_ptr.inc()
  }

  when (do_enq =/= do_deq) {
    maybe_full := do_enq
  }

  io.enq.ready := !full

  val out = Wire(gen)
  out             := ram(deq_ptr.value)
  out.uop         := uops(deq_ptr.value)
  out.uop.br_mask := brMasks(deq_ptr.value)
  io.deq.valid            := !io.empty && valids(deq_ptr.value) && !IsKilledByBranch(io.brupdate, out.uop) && !(io.flush && flush_fn(out.uop))
  io.deq.bits             := out
  io.deq.bits.uop.br_mask := GetNewBrMask(io.brupdate, out.uop)
  if (holdable) {
    io.discarded.get.valid := do_deq && !io.deq.fire
    io.discarded.get.bits := out
  }

  // For flow queue behavior.
  if (flow) {
    when (io.empty) {
      io.deq.valid := io.enq.valid //&& !IsKilledByBranch(io.brupdate, io.enq.bits.uop)
      io.deq.bits := io.enq.bits
      io.deq.bits.uop.br_mask := GetNewBrMask(io.brupdate, io.enq.bits.uop)

      do_deq := false.B
      when (io.deq.ready) { do_enq := false.B }
    }
  }
  private val ptr_diff = enq_ptr.value - deq_ptr.value
  if (isPow2(entries)) {
    io.count := Cat(maybe_full && ptr_match, ptr_diff)
  }
  else {
    io.count := Mux(ptr_match,
                    Mux(maybe_full,
                        entries.asUInt, 0.U),
                    Mux(deq_ptr.value > enq_ptr.value,
                        entries.asUInt + ptr_diff, ptr_diff))
  }
}
