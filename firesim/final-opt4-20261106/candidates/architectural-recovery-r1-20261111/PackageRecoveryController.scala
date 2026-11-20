package boom.recovery

import chisel3._
import chisel3.util._

/** Independent functional extension, NOT instantiated in the area mainline.
  * Tokens name immutable complete register/CSR and memory checkpoints. Their
  * producers/restore engines must be connected and verified before admission.
  */
class RecoveryCheckpoint extends Bundle {
  val sequence = UInt(32.W)
  val generation = UInt(32.W)
  val restartPc = UInt(64.W)
  val architecturalToken = UInt(64.W)
  val memoryToken = UInt(64.W)
}
class RecoveryFailure extends Bundle {
  val sequence = UInt(32.W)
  val generation = UInt(32.W)
  val allocated = Bool()
  val comparedMismatch = Bool()
}
class RecoveryCommand extends Bundle {
  val checkpoint = new RecoveryCheckpoint
  val failedSequence = UInt(32.W)
  val recoveryGeneration = UInt(32.W)
}
class RecoveryAcknowledgement extends Bundle {
  val command = new RecoveryCommand
  val retiredPc = UInt(64.W)
  val allCheckerTasksDrained = Bool()
}
class RecoveryEvent extends Bundle {
  val kind = UInt(4.W)
  val recordSequence = UInt(64.W)
  val targetCycle = UInt(64.W)
  val command = new RecoveryCommand
}

/** Ordered quiesce -> memory -> architecture -> checker init -> first retired
  * restart PC -> checker drain. No command acceptance is called completion.
  * Matching responses are required; a wrong or unsolicited response fails
  * closed, preserving the latched checkpoint/ownership tokens for diagnosis.
  * Complete architectural recovery is NOT established by this module alone.
  */
class PackageRecoveryController extends Module {
  val io = IO(new Bundle {
    val targetCycle = Input(UInt(64.W))
    // Producer must select the MOST RECENT CONTIGUOUS PASS, never max(PASS).
    val checkpoint = Input(Valid(new RecoveryCheckpoint))
    val failure = Flipped(Decoupled(new RecoveryFailure))
    // 0 quiesce, 1 memory restore, 2 register/PC/CSR restore, 3 checker init,
    // 4 redirect (response comes from actual restart-PC retirement), 5 drain.
    val request = Vec(6, Decoupled(new RecoveryCommand))
    val response = Flipped(Vec(6, Valid(new RecoveryAcknowledgement)))
    val active = Output(Bool())
    val freezeRetirement = Output(Bool())
    val freezeNewPackages = Output(Bool())
    val protocolError = Output(Bool())
    val phase = Output(UInt(3.W))
    val events = Output(Vec(8, Valid(new RecoveryEvent)))
  })
  val idle = 0.U(3.W)
  val failed = 7.U(3.W)
  val state = RegInit(idle)
  val sent = RegInit(false.B)
  val command = Reg(new RecoveryCommand)
  val badResponse = Wire(Bool())
  val eventSequence = RegInit(0.U(64.W))
  val eventFire = WireInit(VecInit(Seq.fill(8)(false.B)))
  val acceptedCommand = Wire(new RecoveryCommand)
  acceptedCommand.checkpoint := io.checkpoint.bits
  acceptedCommand.failedSequence := io.failure.bits.sequence
  acceptedCommand.recoveryGeneration := io.checkpoint.bits.generation + 1.U

  io.active := state =/= idle
  io.phase := state
  io.protocolError := state === failed
  io.failure.ready := state === idle
  // Only after redirect acceptance may the restored instruction retire.
  val replayExecuting = state === 6.U || (state === 5.U && sent)
  io.freezeRetirement := (io.active && !replayExecuting) || io.failure.valid || badResponse
  io.freezeNewPackages := io.freezeRetirement

  when (io.failure.fire) {
    val legal = io.checkpoint.valid && io.failure.bits.allocated &&
      io.failure.bits.comparedMismatch &&
      io.failure.bits.generation === io.checkpoint.bits.generation &&
      io.failure.bits.sequence > io.checkpoint.bits.sequence &&
      io.checkpoint.bits.generation =/= "hffffffff".U
    when (legal) {
      command := acceptedCommand
      state := 1.U
      sent := false.B
      eventFire(0) := true.B // actual qualified FAIL acceptance
      eventFire(1) := true.B // actual immutable checkpoint selection
    }.otherwise {
      state := failed
    }
  }

  for (p <- 0 until 6) {
    val current = state === (p + 1).U
    io.request(p).valid := current && !sent
    io.request(p).bits := command
    when (current && io.request(p).fire) { sent := true.B }
    when (io.response(p).valid) {
      val matched = current && (sent || io.request(p).fire) &&
        io.response(p).bits.command.asUInt === command.asUInt
      val completion = if (p == 4)
        io.response(p).bits.retiredPc === command.checkpoint.restartPc
      else if (p == 5) io.response(p).bits.allCheckerTasksDrained
      else true.B
      when (matched && completion) {
        eventFire(p + 2) := true.B
        state := (if (p == 5) idle else (p + 2).U)
        sent := false.B
      }.otherwise {
        state := failed
      }
    }
  }
  // Multiple/unsolicited responses cannot manufacture a completion witness.
  badResponse := (0 until 6).map { p =>
    io.response(p).valid && !(state === (p + 1).U &&
      (sent || io.request(p).fire) &&
      io.response(p).bits.command.asUInt === command.asUInt &&
      (if (p == 4) io.response(p).bits.retiredPc === command.checkpoint.restartPc
       else if (p == 5) io.response(p).bits.allCheckerTasksDrained else true.B))
  }.reduce(_ || _)
  when (badResponse || state === failed) {
    state := failed
    for (i <- 0 until 8) { eventFire(i) := false.B }
  }
  for (i <- 0 until 8) {
    io.events(i).valid := eventFire(i)
    io.events(i).bits.kind := i.U
    io.events(i).bits.targetCycle := io.targetCycle
    io.events(i).bits.command := Mux(io.failure.fire, acceptedCommand, command)
    io.events(i).bits.recordSequence := eventSequence +
      (if (i == 0) 0.U else PopCount(eventFire.take(i)))
  }
  when (eventFire.asUInt.orR) { eventSequence := eventSequence + PopCount(eventFire) }
}
