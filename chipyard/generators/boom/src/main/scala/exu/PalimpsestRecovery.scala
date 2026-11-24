package boom.exu

import chisel3._
import chisel3.util._

/** P2-01: one Main's held, sequenced error. A cancellation is never a PASS. */
class PalimpsestError extends Bundle {
  val seq = UInt(32.W)
  val cancelled = Bool()
}

/** Main's exception bookkeeping used by R_IC and R_RSU. Trap mode can span
  * multiple packages, and the pending syscall indication can survive to a
  * snapshot in the handler. Both must follow the same SCP as the CSRs.
  */
class PalimpsestTrapContext extends Bundle {
  val inHandler = Bool()
  val exceptionPending = Bool()
  val exceptionRecent = Bool()
}

class PalimpsestTrapTracker extends Module {
  val io = IO(new Bundle {
    val trap = Input(Bool())
    val exception = Input(Bool())
    val returns = Input(Bool())
    val countedRetire = Input(Bool())
    val stop = Input(Bool())
    val restore = Flipped(Valid(new PalimpsestTrapContext))
    val snapshot = Output(new PalimpsestTrapContext)
    val syscall = Output(Bool())
  })
  val state = RegInit(0.U.asTypeOf(new PalimpsestTrapContext))
  when (io.restore.valid) {
    assert(io.stop, "trap context restore without retirement stop")
    state := io.restore.bits
  }.elsewhen (!io.stop) {
    when (io.trap) { state.inHandler := true.B }
      .elsewhen (io.returns) { state.inHandler := false.B }
    when (io.exception) {
      state.exceptionPending := true.B
      state.exceptionRecent := true.B
    }.elsewhen (io.countedRetire) {
      state.exceptionRecent := false.B
      when (!state.exceptionRecent) { state.exceptionPending := false.B }
    }
  }
  io.snapshot := state
  io.syscall := !io.stop && io.countedRetire && (state.exceptionPending || io.exception)
}

/** P4-09/10/11: the actual Core device-instruction boundary controller.
  * Prefix ECP excludes the held ROB head. A new SCP/segment and a validated
  * prefix precede the one permitted instruction; its effect segment must
  * validate before younger retirement. Inputs name actual owner conditions,
  * not elapsed cycles. Kept separate so directed tests use production logic.
  */
class PalimpsestIoBoundary(robBits: Int, commitWidth: Int) extends Module {
  require(robBits > 0 && commitWidth > 0)
  val io = IO(new Bundle {
    val protectedExecution = Input(Bool())
    val request = Input(Bool())
    val head = Input(UInt(robBits.W))
    val activeSeq = Input(UInt(32.W))
    val safe = Input(UInt(32.W))
    val boundaryReady = Input(Bool())
    val issueReady = Input(Bool())
    val postReady = Input(Bool())
    val producerIdle = Input(Bool())
    val packageOpen = Input(Bool())
    val retired = Input(Vec(commitWidth, Valid(UInt(robBits.W))))
    val flush = Input(Bool())
    val stop = Input(Bool())
    val effectPending = Input(Bool())
    val retirementHold = Output(Bool())
    val interruptHold = Output(Bool())
    val dispatchHold = Output(Bool())
    val snapshotBoundary = Output(Bool())
    val permit = Output(Bool())
    val singleStep = Output(Bool())
    val forceClose = Output(Bool())
    val closeSeq = Output(UInt(32.W))
    val idle = Output(Bool())
    val state = Output(UInt(3.W))
  })
  val idle :: closeBefore :: waitBefore :: issue :: closeAfter :: waitAfter :: Nil = Enum(6)
  val state = RegInit(idle)
  val prefix = Reg(UInt(32.W))
  val effectSeq = Reg(UInt(32.W))
  val head = Reg(UInt(robBits.W))
  // ROB flush is a synchronous cancellation input only. Feeding it back
  // through retirementHold would make a commit/flush/stall combinational loop.
  val starting = state === idle && io.protectedExecution && io.request && !io.stop
  val retired = io.retired.map(r => r.valid && r.bits === head).reduce(_ || _)
  io.retirementHold := starting || (state =/= idle && state =/= issue)
  io.dispatchHold := starting || state =/= idle
  io.interruptHold := starting || state =/= idle || io.effectPending
  io.snapshotBoundary := !io.stop &&
    (((state === closeBefore || state === waitBefore) && io.boundaryReady) ||
      ((state === closeAfter || state === waitAfter) && io.postReady))
  io.permit := !io.stop && (!io.protectedExecution || state === issue)
  io.singleStep := state === issue
  io.forceClose := !io.stop && (state === closeBefore || state === closeAfter)
  io.closeSeq := Mux(state === closeBefore, prefix, effectSeq)
  io.idle := state === idle
  io.state := state
  when (starting) { prefix := io.activeSeq; head := io.head; state := closeBefore }
  when (state === closeBefore && io.activeSeq > prefix) { state := waitBefore }
  when (state === waitBefore && io.safe >= prefix && io.issueReady && io.producerIdle && io.packageOpen) {
    effectSeq := io.activeSeq
    state := issue
  }
  when (state === issue && retired) { state := closeAfter }
  when (state === closeAfter && io.activeSeq > effectSeq) { state := waitAfter }
  when (state === waitAfter && io.safe >= effectSeq && io.producerIdle) { state := idle }
  // A trap may cancel the unexecuted head during prefix closure as well.
  // The external effect journal, if any, remains an independent owner.
  when (io.stop || io.flush) { state := idle }
  when (starting) { assert(io.activeSeq =/= 0.U, "protected I/O has no active segment") }
  when (io.protectedExecution && io.permit) {
    assert(io.safe >= prefix, "I/O issued before its committed prefix validated")
  }
}

/** P2-03: opaque CSR words are packed/unpacked only by CSRFile. */
class PalimpsestCheckpoint(val xlen: Int, val pcBits: Int, val csrBits: Int) extends Bundle {
  val seq = UInt(32.W)
  val epoch = UInt(32.W)
  val pc = UInt(pcBits.W)
  val integer = Vec(32, UInt(xlen.W))
  val floating = Vec(32, UInt(xlen.W))
  val csr = UInt(csrBits.W)
  val trap = new PalimpsestTrapContext
}

/** P2-03/P2-04: CP ownership is independent of Checker-slot ownership.
  * A PASS out of order cannot reclaim a checkpoint: only the contiguous safe
  * prefix can. The held read response pins its CP through restore completion.
  */
class PalimpsestContextMemory(xlen: Int, pcBits: Int, csrBits: Int, entries: Int = 16)
    extends Module {
  require(entries > 1)
  val io = IO(new Bundle {
    val capture = Flipped(Decoupled(new PalimpsestCheckpoint(xlen, pcBits, csrBits)))
    val safeWatermark = Input(UInt(32.W))
    val discard = Input(Valid(UInt(32.W))) // first discarded Seq, inclusive
    val read = Flipped(Decoupled(UInt(32.W)))
    val response = Decoupled(new PalimpsestCheckpoint(xlen, pcBits, csrBits))
    val missing = Output(Bool())
    val occupancy = Output(UInt(log2Ceil(entries + 1).W))
    val abort = Input(Bool())
  })
  val valid = RegInit(VecInit(Seq.fill(entries)(false.B)))
  val checkpoints = Mem(entries, new PalimpsestCheckpoint(xlen, pcBits, csrBits))
  val seq = Reg(Vec(entries, UInt(32.W)))
  val pinned = RegInit(false.B)
  val pin = Reg(UInt(log2Ceil(entries).W))
  val held = Reg(new PalimpsestCheckpoint(xlen, pcBits, csrBits))
  val free = VecInit(valid.map(!_))
  val hits = VecInit((0 until entries).map(i => valid(i) && seq(i) === io.read.bits))
  io.capture.ready := free.asUInt.orR && !io.discard.valid
  io.read.ready := !pinned && !io.discard.valid
  io.response.valid := pinned
  io.response.bits := held
  io.missing := io.read.valid && io.read.ready && !hits.asUInt.orR
  io.occupancy := PopCount(valid)
  when (io.capture.fire) {
    val i = PriorityEncoder(free.asUInt)
    assert(io.capture.bits.seq =/= 0.U, "CP cannot use reserved Seq0")
    assert(!(0 until entries).map(j => valid(j) && seq(j) === io.capture.bits.seq).reduce(_ || _),
      "duplicate persistent SCP")
    valid(i) := true.B
    seq(i) := io.capture.bits.seq
    checkpoints.write(i, io.capture.bits)
  }
  when (io.read.fire && hits.asUInt.orR) {
    assert(PopCount(hits) === 1.U, "ambiguous SCP lookup")
    val i = PriorityEncoder(hits.asUInt)
    pin := i
    held := checkpoints(i)
    pinned := true.B
  }
  when (io.response.fire || io.abort) { pinned := false.B }
  for (i <- 0 until entries) {
    when (valid(i) && !(pinned && pin === i.U && !io.response.fire && !io.abort) &&
      !(io.read.fire && hits(i)) &&
      (seq(i) <= io.safeWatermark || (io.discard.valid && seq(i) >= io.discard.bits))) {
      valid(i) := false.B
    }
  }
  when (pinned && !io.response.ready) {
    assert(valid(pin), "pinned SCP reclaimed before restore completion")
  }
}

/** P3-01/P3-02/P3-03/P3-15: an EVT represented by discarded Seq intervals.
  * Seq never aliases, so its interval identifies the execution Epoch without
  * changing the immutable CacheImage key or ACK identity. Retain tombstones:
  * an old cache/ACK may outlive a rollback. Exhaustion is explicit backpressure,
  * not wraparound. Adjacent/overlapping suffixes merge on repeated rollback.
  */
class PalimpsestExecutionHistory(entries: Int = 32, queryPorts: Int = 1,
                                allowSeqRebase: Boolean = false) extends Module {
  require(entries > 0 && queryPorts > 0)
  val io = IO(new Bundle {
    val allocated = Input(Valid(UInt(32.W)))
    val rollback = Flipped(Decoupled(UInt(32.W)))
    val query = Input(Vec(queryPorts, UInt(32.W)))
    val survives = Output(Vec(queryPorts, Bool()))
    val epoch = Output(UInt(32.W))
    val generation = Output(UInt(32.W))
    val allocatedTail = Output(UInt(32.W))
    val full = Output(Bool())
    val lower = Output(Vec(entries, UInt(32.W)))
    val upper = Output(Vec(entries, UInt(32.W)))
    val occupied = Output(Vec(entries, Bool()))
    val maintenanceRequired = Output(Bool())
    val compact = Input(Bool()) // all cache/history references reconciled by maintenance
    val rebase = if (allowSeqRebase) Some(Input(Bool())) else None
  })
  val tail = RegInit(0.U(32.W))
  val epoch = RegInit(0.U(32.W))
  val generation = RegInit(0.U(32.W))
  val valid = RegInit(VecInit(Seq.fill(entries)(false.B)))
  val lower = RegInit(VecInit(Seq.fill(entries)(0.U(32.W))))
  val upper = RegInit(VecInit(Seq.fill(entries)(0.U(32.W))))
  // Adjacent dead intervals contain no surviving Seq between them. Merge
  // them as well as overlap, using an extra bit so upper=MAX cannot wrap.
  // A real surviving gap is never merged, even if it is already below SW.
  val merge = VecInit((0 until entries).map(i => valid(i) &&
    Cat(0.U(1.W), io.rollback.bits) <= (upper(i) +& 1.U) && tail >= lower(i)))
  val free = VecInit(valid.map(!_))
  val candidate = Mux(merge.asUInt.orR, PriorityEncoder(merge.asUInt), PriorityEncoder(free.asUInt))
  val capacity = merge.asUInt.orR || free.asUInt.orR
  io.rollback.ready := capacity && !epoch.andR && !generation.andR && !io.allocated.valid &&
    io.rollback.bits =/= 0.U && io.rollback.bits <= tail
  io.full := !capacity || epoch.andR || generation.andR
  io.epoch := epoch
  io.generation := generation
  io.allocatedTail := tail
  io.occupied := valid
  // Reserve more labels than the maximum live SCP window, so earlier FAILs
  // can still merge/reselect while the service waits for a validated prefix.
  private val maintenanceEpoch = (BigInt(1) << 32) - entries - 2
  io.maintenanceRequired := valid.asUInt.andR || epoch >= maintenanceEpoch.U || generation >= maintenanceEpoch.U
  io.lower := lower
  io.upper := upper
  for (q <- 0 until queryPorts) {
    val s = io.query(q)
    io.survives(q) := s === 0.U || (s <= tail &&
      !(0 until entries).map(i => valid(i) && s >= lower(i) && s <= upper(i)).reduce(_ || _))
  }
  when (io.allocated.valid) {
    assert(io.allocated.bits > tail && io.allocated.bits =/= 0.U,
      "PALIMPSEST Seq reused or wrapped")
    tail := io.allocated.bits
  }
  when (io.rollback.fire) {
    var first = io.rollback.bits
    for (i <- 0 until entries) {
      first = Mux(merge(i) && lower(i) < first, lower(i), first)
      when (merge(i)) { valid(i) := false.B }
    }
    valid(candidate) := true.B
    lower(candidate) := first
    upper(candidate) := tail
    epoch := epoch + 1.U
    generation := generation + 1.U
  }
  when (io.compact) {
    assert(!io.allocated.valid && !io.rollback.fire, "EVT maintenance overlapped execution allocation")
    valid.foreach(_ := false.B)
    // No old Current or in-flight owner remains. Execution labels can cycle;
    // Seq remains monotonic and keeps its independent ordering semantics.
    epoch := 0.U
    generation := 0.U
  }
  io.rebase.foreach { rebase =>
    when (rebase) {
      assert(io.compact, "Seq rebase without physical maintenance certificate")
      tail := 0.U
    }
  }
}

/** P2-02/P2-11/P4-01: restart is an acknowledged transaction, never a timer.
  * The controller requires all three independent completion conditions. An
  * earlier error arriving during restoration aborts that attempt and reselects
  * its SCP before any restart. Side effects already accepted by TL are handled
  * by the quiesce/reconcile participant, not by dropping their valid signals.
  */
class PalimpsestRollbackController(allowSeqRebase: Boolean = false) extends Module {
  val io = IO(new Bundle {
    val error = Flipped(Decoupled(new PalimpsestError))
    val checkpoint = Decoupled(UInt(32.W))
    val checkpointReady = Input(Bool())
    val checkpointMissing = Input(Bool())
    val abandonCheckpoint = Output(Bool())
    val quiesced = Input(Bool())
    val commitHistory = Decoupled(UInt(32.W))
    val historyUnavailable = Input(Bool())
    val identityUnavailable = Input(Bool()) // P3-15/P4-06: permanent finite boundary
    val restore = Output(Bool())
    val restored = Input(Bool())
    val restart = Decoupled(UInt(32.W))
    val stop = Output(Bool())
    val quiesce = Output(Bool())
    val target = Output(UInt(32.W))
    val fatal = Output(Bool())
    val state = Output(UInt(3.W))
    val rebase = if (allowSeqRebase) Some(Flipped(Decoupled(UInt(32.W)))) else None
    val rebasing = if (allowSeqRebase) Some(Output(Bool())) else None
  })
  val idle :: lookup :: drain :: history :: restore :: resume :: failed :: Nil = Enum(7)
  val state = RegInit(idle)
  val target = RegInit(0.U(32.W))
  val rebasing = if (allowSeqRebase) RegInit(false.B) else false.B
  io.rebasing.foreach(_ := rebasing)
  val earlier = !io.identityUnavailable && io.error.valid && io.error.bits.seq =/= 0.U &&
    (state === idle || io.error.bits.seq < target)
  io.error.ready := state =/= failed && !io.identityUnavailable
  io.abandonCheckpoint := io.error.fire && earlier
  io.checkpoint.valid := state === lookup && !earlier && !io.identityUnavailable
  io.checkpoint.bits := target
  io.commitHistory.valid := state === history && io.checkpointReady && !earlier && !io.identityUnavailable
  io.commitHistory.bits := target
  io.restore := state === restore && !earlier && !io.identityUnavailable
  // Coherence can acquire a new owner after drain acknowledged quiescence.
  // Recheck the live participants at the actual restart handshake; the SCP
  // and stop remain held while that late owner finishes.
  io.restart.valid := state === resume && io.quiesced && io.checkpointReady &&
    !earlier && !io.identityUnavailable
  io.restart.bits := target
  io.stop := state =/= idle || io.error.valid || io.identityUnavailable
  io.quiesce := state =/= idle
  io.target := Mux(earlier, io.error.bits.seq, target)
  io.fatal := state === failed || io.identityUnavailable
  io.state := state
  switch (state) {
    is (lookup) { when (io.checkpoint.fire) { state := history } }
    is (drain) { when (io.quiesced && io.checkpointReady) { state := restore } }
    is (history) { when (io.commitHistory.fire) { state := drain } }
    is (restore) { when (io.restored && !earlier) { state := resume } }
    is (resume) { when (io.restart.fire) { state := idle; target := 0.U } }
  }
  when (io.error.fire && earlier) {
    target := io.error.bits.seq
    state := lookup
    if (allowSeqRebase) rebasing := false.B
  }
  io.rebase.foreach { request =>
    request.ready := state === idle && !io.error.valid && !io.identityUnavailable
    when (request.fire) {
      assert(request.bits =/= 0.U, "Seq rebase requires a Starting CP")
      target := request.bits
      rebasing := true.B
      state := lookup
    }
    when (io.restart.fire) { rebasing := false.B }
  }
  when (io.checkpointMissing) { state := failed }
  // P3-15: finite tombstone/Epoch exhaustion cannot be confused with an
  // ordinary temporary memory stall. Stop with the SCP still pinned.
  when (state === history && io.historyUnavailable && !earlier) { state := failed }
  when (io.identityUnavailable) { state := failed }
  when (io.error.fire) { assert(io.error.bits.seq =/= 0.U, "unsequenced rollback error") }
  when (io.restart.fire) {
    assert(io.quiesced && io.checkpointReady, "restart without reconciled transaction/SCP")
  }
}
