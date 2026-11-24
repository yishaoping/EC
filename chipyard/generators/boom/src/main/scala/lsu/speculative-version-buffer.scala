package boom.lsu

import chisel3._
import chisel3.util._

import org.chipsalliance.cde.config.{Field, Parameters}
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.rocket._
import freechips.rocketchip.tilelink._
import freechips.rocketchip.util.{CacheOpportunityObservation, SafeChainObservation}
import freechips.rocketchip.guardiancouncil.GH_GlobalParams
import boom.common._

/** Storage capacity only; cache geometry and version semantics are unchanged. */
case object SVBEntries extends Field[Int](16)

/** The complete image handed from the L1 line reader to the SVB. */
class SpeculativeVersionSnapshot(val rows: Int, val rowBits: Int)(implicit p: Parameters)
    extends BoomBundle()(p) {
  val line = UInt(coreMaxAddrBits.W)
  val key = new CacheImageKey
  val epoch = UInt(16.W)
  val param = UInt(TLPermissions.cWidth.W)
  val data = Vec(rows, UInt(rowBits.W))
}

/** A full immutable snapshot plus its SVB slot identity. */
class SpeculativeVersionPromotion(rows: Int, rowBits: Int, entryBits: Int)(implicit p: Parameters)
    extends SpeculativeVersionSnapshot(rows, rowBits)(p) {
  val entry = UInt(entryBits.W)
}

class SpeculativeVersionCompletion(entryBits: Int)(implicit p: Parameters) extends BoomBundle()(p) {
  val entry = UInt(entryBits.W)
  val key = new CacheImageKey
}

/**
  * A bounded, global associative buffer for the one case in which the old
  * L1 image is an unsafe predecessor of a younger same-line store.
  *
  * Entries participate in addressed recovery, independently of ordinary L1
  * hit selection. Surviving entries transfer in ascending Seq/serial order
  * through the archive mailbox. WB_WAIT owns its bytes until the exact
  * archive receipt; that receipt transfers storage, not coherence permission
  * and not DRAM safety. Safety is HistoryValid && Seq <= SW at publication.
  */
class SpeculativeVersionBuffer(val entries: Int)
    (implicit edge: TLEdgeOut, p: Parameters)
    extends L1HellaCacheModule()(p) {
  require(entries > 0 && (entries & (entries - 1)) == 0,
    "SVB entry count must be a power of two")

  val io = IO(new Bundle {
    val capture = Flipped(Decoupled(new SpeculativeVersionSnapshot(refillCycles, encRowBits)))
    val safeWatermark = Input(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
    // P3-06/P3-09: an addressed, held recovery response, independent of WB.
    val query = Flipped(Decoupled(UInt(coreMaxAddrBits.W)))
    val recovered = Decoupled(new SpeculativeVersionSnapshot(refillCycles, encRowBits))
    val recoveredFound = Output(Bool())
    val entrySeq = Output(Vec(entries, UInt(32.W)))
    val historyValid = Input(Vec(entries, Bool()))

    val currentEpoch = Input(UInt(16.W))
    val diagnosticDump = Input(Bool())
    val diagnosticCycle = Input(UInt(64.W))
    val resetStats = Input(Bool())
    val countStats = Input(Bool())
    val invalidate = Input(Valid(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)))
    val flush = Input(Bool())
    val promote = Decoupled(new SpeculativeVersionPromotion(refillCycles, encRowBits, log2Ceil(entries)))
    val selected = Output(Bool())
    val activeEntry = Output(UInt(log2Ceil(entries).W))
    val activeLine = Output(UInt(coreMaxAddrBits.W))
    val activeKey = Output(new CacheImageKey)
    val queued = Output(UInt(log2Ceil(entries + 1).W))
    val coalesced = Output(UInt(log2Ceil(entries + 1).W))
    val discarded = Output(UInt(log2Ceil(entries + 1).W))
    // A younger normal release/probe must not publish ahead of any retained
    // predecessor. Include WB_WAIT until its matching completion, not C.last.
    val releaseLines = Input(Vec(4, UInt(coreMaxAddrBits.W)))
    val releaseBlocked = Output(Vec(4, Bool()))
    val releaseBlockingEntry = Output(Vec(4, UInt(log2Ceil(entries).W)))
    val releaseBlockingLine = Output(Vec(4, UInt(coreMaxAddrBits.W)))
    val releaseBlockingSeq = Output(Vec(4, UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)))
    val releaseBlockingGeneration = Output(Vec(4, UInt(32.W)))
    val ack = Input(Valid(new SpeculativeVersionCompletion(log2Ceil(entries))))
    val occupancy = Output(UInt(log2Ceil(entries + 1).W))
    val maxOccupancy = Output(UInt(log2Ceil(entries + 1).W))
    val maxDepth = Output(UInt(log2Ceil(entries + 1).W))
    val depth = Output(UInt(log2Ceil(entries + 1).W))
    val occupancyHistogram = Output(Vec(entries + 1, UInt(64.W)))
    val depthHistogram = Output(Vec(entries + 1, UInt(64.W)))
    // Observation identity only; never participates in allocation or arbitration.
    val observationSerial = Output(UInt(64.W))
    val allocation = Output(Bool())
    val allocatedEntry = Output(UInt(log2Ceil(entries).W))
    val entryAccounting = Output(Vec(5, UInt(64.W)))
    val fullFallback = Output(Bool())
    val promotion = Output(Bool())
    val acked = Output(Bool())
    val recoveryFromSvb = Output(Bool())
  })

  private val stFree = 0.U(2.W)
  private val stSpec = 1.U(2.W)
  private val stWb = 2.U(2.W)

  val valid = RegInit(VecInit(Seq.fill(entries)(false.B)))
  val state = RegInit(VecInit(Seq.fill(entries)(stFree)))
  val line = Reg(Vec(entries, UInt(coreMaxAddrBits.W)))
  val key = Reg(Vec(entries, new CacheImageKey))
  val epoch = Reg(Vec(entries, UInt(16.W)))
  val param = Reg(Vec(entries, UInt(TLPermissions.cWidth.W)))
  val data = Reg(Vec(entries, Vec(refillCycles, UInt(encRowBits.W))))
  val active = RegInit(false.B)
  val activeIdx = Reg(UInt(log2Ceil(entries).W))
  val sent = RegInit(false.B)

  io.entrySeq := key.map(_.contentSeq)
  val recoveryPending = RegInit(false.B)
  val recoveryFound = RegInit(false.B)
  val recoveryPayload = Reg(new SpeculativeVersionSnapshot(refillCycles, encRowBits))
  val matches = VecInit((0 until entries).map(i => valid(i) && io.historyValid(i) &&
    line(i) === io.query.bits))
  val winners = VecInit((0 until entries).map(i => matches(i) &&
    (0 until entries).filter(_ != i).map(j => !matches(j) ||
      key(i).contentSeq > key(j).contentSeq ||
      (key(i).contentSeq === key(j).contentSeq &&
        (key(i).generation > key(j).generation ||
          (key(i).generation === key(j).generation && (i < j).B))))
      .foldLeft(true.B)(_ && _)))
  io.query.ready := !recoveryPending && !io.flush && !io.invalidate.valid
  io.recovered.valid := recoveryPending
  io.recovered.bits := recoveryPayload
  io.recoveredFound := recoveryFound
  when (io.query.fire) {
    val i = PriorityEncoder(winners.asUInt)
    recoveryPending := true.B
    recoveryFound := winners.asUInt.orR
    recoveryPayload.line := io.query.bits
    recoveryPayload.key := key(i)
    recoveryPayload.epoch := epoch(i)
    recoveryPayload.param := param(i)
    recoveryPayload.data := data(i)
    assert(PopCount(winners) <= 1.U, "ambiguous SVB recovery candidate")
  }
  when (io.recovered.fire) { recoveryPending := false.B }

  val freeVec = VecInit((0 until entries).map(i => !valid(i)))
  for (q <- 0 until 4) {
    val blockedByEntry = VecInit((0 until entries).map(i => valid(i) && line(i) === io.releaseLines(q)))
    io.releaseBlocked(q) := blockedByEntry.asUInt.orR
    io.releaseBlockingEntry(q) := PriorityEncoder(blockedByEntry.asUInt)
    io.releaseBlockingLine(q) := Mux(io.releaseBlocked(q), line(io.releaseBlockingEntry(q)), 0.U)
    io.releaseBlockingSeq(q) := Mux(io.releaseBlocked(q), key(io.releaseBlockingEntry(q)).contentSeq, 0.U)
    io.releaseBlockingGeneration(q) := Mux(io.releaseBlocked(q), key(io.releaseBlockingEntry(q)).generation, 0.U)
  }
  val freeAny = freeVec.asUInt.orR
  val allocOH = PriorityEncoderOH(freeVec.asUInt)
  io.capture.ready := freeAny && !io.flush
  // P1-09/U-D05: same-Seq intermediate values are not checkpoint
  // predecessors. Among safe values only the latest per address is needed
  // by any outstanding SCP (>SW). Never coalesce the accepted WB owner.
  val coalesce = VecInit((0 until entries).map(i => io.capture.fire &&
    valid(i) && state(i) === stSpec && io.historyValid(i) &&
    !(active && activeIdx === i.U) && line(i) === io.capture.bits.line &&
    (io.capture.bits.key.contentSeq > key(i).contentSeq ||
      (io.capture.bits.key.contentSeq === key(i).contentSeq && io.capture.bits.key.generation > key(i).generation)) &&
    (io.capture.bits.key.contentSeq === key(i).contentSeq ||
      (key(i).contentSeq <= io.safeWatermark && io.capture.bits.key.contentSeq <= io.safeWatermark))))

  val entrySafe = VecInit((0 until entries).map(i =>
    valid(i) && state(i) === stSpec && io.historyValid(i) &&
      (!key(i).valid || key(i).contentSeq === 0.U ||
       key(i).contentSeq <= io.safeWatermark)))

  val entryAge = RegInit(VecInit(Seq.fill(entries)(0.U(32.W))))
  val entryAgeReported = RegInit(VecInit(Seq.fill(entries)(false.B)))
  for (i <- 0 until entries) {
    when (!valid(i)) {
      entryAge(i) := 0.U
      entryAgeReported(i) := false.B
    }.otherwise {
      when (entryAge(i) =/= ~0.U(32.W)) { entryAge(i) := entryAge(i) + 1.U }
      when (entryAge(i) === 65535.U && !entryAgeReported(i)) {
        val waitingReason = Mux(state(i) === stWb,
          Mux(sent, 2.U, 1.U), Mux(entrySafe(i), 3.U, 4.U))
        printf("LONG_STALL object=SVB_ENTRY cycle=%x age=%x entry=%x line=%x state=%x safe=%x active=%x promotion_eligible=%x seq=%x generation=%x waiting_reason=%x watermark=%x\n",
          io.diagnosticCycle, entryAge(i), i.U, line(i), state(i), entrySafe(i),
          active && activeIdx === i.U, entrySafe(i) && !active,
          key(i).contentSeq, key(i).generation, waitingReason, io.safeWatermark)
        entryAgeReported(i) := true.B
      }
    }
  }

  for (i <- 0 until entries) {
    val wasSafe = RegNext(entrySafe(i), false.B)
    when (entrySafe(i) && !wasSafe) {
      printf("SVB_SAFE cycle=%x entry=%x line=%x seq=%x generation=%x epoch=%x watermark=%x\n",
        io.diagnosticCycle, i.U, line(i), key(i).contentSeq, key(i).generation,
        epoch(i), io.safeWatermark)
    }
  }

  when (io.diagnosticDump) {
    for (i <- 0 until entries) {
      when (valid(i)) {
        printf("SVB_HANG_ENTRY cycle=%x entry=%x state=%x active=%x line=%x seq=%x generation=%x writer=%x key_valid=%x epoch=%x\n",
          io.diagnosticCycle, i.U, state(i), active && activeIdx === i.U,
          line(i), key(i).contentSeq, key(i).generation, key(i).writer,
          key(i).valid, epoch(i))
      }
    }
  }

  // Compare every candidate; equal-package versions on the same line are
  // ordered by the immutable writer generation, never by reusable slot ID.
  // This also prevents selection of an entry coalesced in this same cycle.
  // P4-03/P4-13: transfer unsafe snapshots to the addressed L2 archive too.
  // The archive receipt transfers responsibility; it is not a DRAM-safe claim.
  val transferable = VecInit((0 until entries).map(i => valid(i) && state(i) === stSpec && io.historyValid(i) && !coalesce(i)))
  val chooseValid = WireDefault(false.B)
  val chooseIdx = WireDefault(0.U(log2Ceil(entries).W))
  for (i <- 0 until entries) {
    val noOlder = (0 until entries).filter(_ != i).map(j =>
      !(transferable(j) && (key(j).contentSeq < key(i).contentSeq ||
        (key(j).contentSeq === key(i).contentSeq &&
          (key(j).generation < key(i).generation ||
           (key(j).generation === key(i).generation && (j > i).B)))))).foldLeft(true.B)(_ && _)
    when (transferable(i) && noOlder) {
      chooseValid := true.B
      chooseIdx := i.U
    }
  }

  val occupancyValue = PopCount(valid)
  io.occupancy := occupancyValue
  val maxOccupancyReg = RegInit(0.U(log2Ceil(entries + 1).W))
  val maxDepthReg = RegInit(0.U(log2Ceil(entries + 1).W))
  when (io.resetStats) {
    maxOccupancyReg := 0.U
    maxDepthReg := 0.U
  }.elsewhen (io.countStats && occupancyValue > maxOccupancyReg) {
    maxOccupancyReg := occupancyValue
  }
  io.maxOccupancy := maxOccupancyReg

  val lineDepth = VecInit((0 until entries).map(i =>
    PopCount((0 until entries).map(j => valid(j) && line(j) === line(i)))))
  val depthValue = Mux(valid.asUInt.orR, lineDepth.reduce((a, b) => Mux(a > b, a, b)), 0.U)
  io.depth := depthValue
  when (!io.resetStats && io.countStats && depthValue > maxDepthReg) { maxDepthReg := depthValue }
  io.maxDepth := maxDepthReg

  val occupancyHistogramReg = RegInit(VecInit(Seq.fill(entries + 1)(0.U(64.W))))
  val depthHistogramReg = RegInit(VecInit(Seq.fill(entries + 1)(0.U(64.W))))
  when (io.resetStats) {
    for (i <- 0 to entries) {
      occupancyHistogramReg(i) := 0.U
      depthHistogramReg(i) := 0.U
    }
  }.elsewhen (io.countStats && occupancyHistogramReg(occupancyValue) =/= ~0.U(64.W)) {
    occupancyHistogramReg(occupancyValue) := occupancyHistogramReg(occupancyValue) + 1.U
  }
  when (!io.resetStats && io.countStats && depthHistogramReg(depthValue) =/= ~0.U(64.W)) {
    depthHistogramReg(depthValue) := depthHistogramReg(depthValue) + 1.U
  }
  io.occupancyHistogram := occupancyHistogramReg
  io.depthHistogram := depthHistogramReg

  // Once selected, hold both entry and payload through arbitration and ACK.
  // Flush/coalescing may only discard SPEC entries, never this WB_WAIT owner.
  io.selected := !active && chooseValid && !io.flush && !io.invalidate.valid
  io.activeEntry := Mux(io.selected, chooseIdx, activeIdx)
  io.activeLine := line(io.activeEntry)
  io.activeKey := key(io.activeEntry)
  io.queued := PopCount(transferable) + (active && !sent).asUInt
  io.promote.valid := active && !sent
  io.promote.bits.entry := activeIdx
  io.promote.bits.line := line(activeIdx)
  io.promote.bits.key := key(activeIdx)
  io.promote.bits.epoch := epoch(activeIdx)
  io.promote.bits.param := param(activeIdx)
  io.promote.bits.data := data(activeIdx)
  io.allocation := io.capture.fire
  io.allocatedEntry := PriorityEncoder(freeVec.asUInt)
  io.fullFallback := !io.capture.ready && io.capture.valid
  io.promotion := io.promote.fire
  io.acked := io.ack.valid && active && sent &&
    io.ack.bits.entry === activeIdx && io.ack.bits.key.asUInt === key(activeIdx).asUInt
  io.recoveryFromSvb := io.recovered.fire && io.recoveredFound
  when (io.ack.valid) {
    assert(io.acked, "SVB completion does not match the outstanding entry/key")
  }

  when (io.capture.fire) {
    for (i <- 0 until entries) {
      when (allocOH(i)) {
        valid(i) := true.B
        state(i) := stSpec
        line(i) := io.capture.bits.line
        key(i) := io.capture.bits.key
        epoch(i) := io.capture.bits.epoch
        param(i) := io.capture.bits.param
        data(i) := io.capture.bits.data
        printf("SVB_ENTRY_ALLOC cycle=%x entry=%x line=%x seq=%x generation=%x epoch=%x state=SPEC\n",
          io.diagnosticCycle, i.U, io.capture.bits.line, io.capture.bits.key.contentSeq,
          io.capture.bits.key.generation, io.capture.bits.epoch)
      }
    }
  }

  when (io.selected) {
    assert(valid(chooseIdx) && state(chooseIdx) === stSpec,
      "SVB scheduler reselected WB_WAIT or invalid entry")
    assert(io.historyValid(chooseIdx), "SVB selected discarded execution history")
    active := true.B
    activeIdx := chooseIdx
    sent := false.B
    state(chooseIdx) := stWb
    printf("SVB_PROMOTION_SELECT cycle=%x entry=%x line=%x seq=%x generation=%x state=WB_WAIT safe=%x\n",
      io.diagnosticCycle, chooseIdx, line(chooseIdx), key(chooseIdx).contentSeq,
      key(chooseIdx).generation, entrySafe(chooseIdx))
  }
  // A complete newer safe image supersedes an older safe image on the same
  // line.  WB entries are deliberately excluded: until their ACK they still
  // own a valid lower-level recovery copy.
  io.coalesced := PopCount(coalesce)
  io.discarded := PopCount((0 until entries).map(i => valid(i) && state(i) === stSpec &&
    !coalesce(i) && (io.flush || (io.invalidate.valid && key(i).valid &&
      key(i).contentSeq > io.invalidate.bits))))
  for (i <- 0 until entries) {
    when (coalesce(i)) {
      valid(i) := false.B
      state(i) := stFree
    }
  }
  when (io.promote.fire) {
    assert(active && !sent && valid(activeIdx) && state(activeIdx) === stWb,
      "SVB duplicate promotion or missing WB_WAIT owner")
    sent := true.B
  }

  when (io.acked) {
    printf("SVB_COMPLETION cycle=%x entry=%x line=%x seq=%x generation=%x state=FREE\n",
      io.diagnosticCycle, activeIdx, line(activeIdx), key(activeIdx).contentSeq,
      key(activeIdx).generation)
    valid(activeIdx) := false.B
    state(activeIdx) := stFree
    sent := false.B
    active := false.B
  }

  // P1-03/P1-04: invalidate.bits is the last surviving sequence, NEVER SW.
  // Surviving unsafe predecessors must remain queryable. An accepted WB
  // retains its original owner through ACK, independently of invalidation.
  when (io.invalidate.valid) {
    for (i <- 0 until entries) {
      when (valid(i) && state(i) === stSpec &&
        key(i).valid && key(i).contentSeq > io.invalidate.bits) {
        valid(i) := false.B
        state(i) := stFree
      }
    }
  }
  when (io.flush) {
    for (i <- 0 until entries) {
      when (state(i) === stSpec) {
        valid(i) := false.B
        state(i) := stFree
      }
    }
  }

  // Simulation evidence is keyed by allocation serial, never reusable slot/key.
  val observationSerialCounter = RegInit(0.U(64.W))
  val observationSerials = Reg(Vec(entries, UInt(64.W)))
  when (io.capture.fire) {
    observationSerialCounter := observationSerialCounter + 1.U
    observationSerials(io.allocatedEntry) := observationSerialCounter + 1.U
  }
  io.observationSerial := observationSerials(activeIdx)
  def integrityEvent(kind: Int, event: Bool, fields: Seq[UInt], lane: UInt = 0.U): Unit =
    SafeChainObservation.emit(kind, clock, reset.asBool, io.diagnosticCycle,
      io.diagnosticCycle, lane, true.B, event, fields, 0.U, true.B)
  val captureHash = CacheOpportunityObservation.lineHash(io.capture.bits.data.toSeq, encRowBits)
  integrityEvent(32, io.capture.fire, Seq(2.U, observationSerialCounter + 1.U,
    io.allocatedEntry, io.capture.bits.line, io.capture.bits.key.contentSeq,
    io.capture.bits.key.generation, io.capture.bits.key.writer, io.capture.bits.epoch,
    io.capture.bits.key.valid.asUInt, captureHash, (refillCycles * encRowBits / 64).U))
  val capturedPrevious = RegNext(io.capture.fire, false.B)
  val capturedIndex = RegEnable(io.allocatedEntry, io.capture.fire)
  integrityEvent(33, capturedPrevious, Seq(2.U, observationSerials(capturedIndex),
    capturedIndex, CacheOpportunityObservation.lineHash(data(capturedIndex).toSeq, encRowBits)))
  integrityEvent(34, io.promote.fire, Seq(2.U, observationSerials(activeIdx), activeIdx,
    CacheOpportunityObservation.lineHash(data(activeIdx).toSeq, encRowBits),
    CacheOpportunityObservation.lineHash(io.promote.bits.data.toSeq, encRowBits)))
  for (i <- 0 until entries) {
    val discard = valid(i) && state(i) === stSpec && !coalesce(i) &&
      (io.flush || (io.invalidate.valid && key(i).valid && key(i).contentSeq > io.invalidate.bits))
    val complete = io.acked && activeIdx === i.U
    val terminal = coalesce(i) || discard || complete
    val successor = PriorityEncoder(VecInit((0 until entries).map(j =>
      entrySafe(j) && line(j) === line(i) && key(j).writer === key(i).writer &&
      (key(j).contentSeq > key(i).contentSeq ||
       (key(j).contentSeq === key(i).contentSeq && key(j).generation > key(i).generation)))).asUInt)
    integrityEvent(35, terminal, Seq(2.U, observationSerials(i), i.U,
      Mux(complete, 1.U, Mux(coalesce(i), 2.U, Mux(io.flush, 3.U, 4.U))),
      Mux(coalesce(i), observationSerials(successor), 0.U)), i.U)
    val safePrevious = RegNext(entrySafe(i), false.B)
    val serialPrevious = RegNext(observationSerials(i))
    integrityEvent(36, entrySafe(i) && (!safePrevious || serialPrevious =/= observationSerials(i)),
      Seq(2.U, observationSerials(i), i.U, io.safeWatermark), i.U)
    val retainedImage = RegNext(valid(i) && !terminal, false.B)
    val previousImage = RegNext(Cat(line(i), key(i).asUInt, epoch(i), param(i), data(i).asUInt))
    when (retainedImage) {
      assert(valid(i) && Cat(line(i), key(i).asUInt, epoch(i), param(i), data(i).asUInt) === previousImage,
        "INTEGRITY-1: retained SVB snapshot changed before terminal event")
    }
  }
  // Atomic next-state accounting includes every terminal on the same edge.
  val observationDeleted = io.coalesced +& io.discarded +& io.acked.asUInt
  val observationNextOccupancy = occupancyValue +& io.capture.fire.asUInt - observationDeleted
  val observationExpectedOccupancy = RegNext(observationNextOccupancy)
  when (RegNext(!reset.asBool, false.B)) {
    assert(occupancyValue === observationExpectedOccupancy, "INTEGRITY-2: simultaneous occupancy accounting")
  }

  // Full-run conservation, independent of RESET/START/STOP measurement bits.
  // Capture and deletion are disjoint by slot; WB_WAIT is never discarded.
  val totalAllocated = RegInit(0.U(64.W))
  val totalCompleted = RegInit(0.U(64.W))
  val totalCoalesced = RegInit(0.U(64.W))
  val totalDiscarded = RegInit(0.U(64.W))
  when (io.capture.fire) { totalAllocated := totalAllocated + 1.U }
  when (io.acked) { totalCompleted := totalCompleted + 1.U }
  totalCoalesced := totalCoalesced + io.coalesced
  totalDiscarded := totalDiscarded + io.discarded
  io.entryAccounting := VecInit(Seq(totalAllocated, totalCompleted, totalCoalesced,
    totalDiscarded, occupancyValue.pad(64)))
  assert(totalAllocated === totalCompleted + totalCoalesced + totalDiscarded + occupancyValue,
    "SVB entry conservation failed")

  assert(PopCount((0 until entries).map(i => valid(i) && state(i) === stWb)) <= 1.U,
    "SVB has multiple outstanding promotions")
  when (active) {
    assert(valid(activeIdx) && state(activeIdx) === stWb, "SVB lost WB_WAIT owner before ACK")
  }
  for (i <- 0 until entries) {
    val retained = RegNext(valid(i) && state(i) === stWb &&
      !(io.acked && activeIdx === i.U), false.B)
    val heldImage = RegNext(Cat(line(i), key(i).asUInt, epoch(i), param(i), data(i).asUInt))
    when (retained) {
      assert(valid(i) && state(i) === stWb, "SVB freed WB_WAIT without matching ACK")
      assert(Cat(line(i), key(i).asUInt, epoch(i), param(i), data(i).asUInt) === heldImage,
        "SVB mutated WB_WAIT snapshot")
    }
  }
  assert(!(io.capture.fire && !freeAny), "SVB overwrite while all entries valid")
}
