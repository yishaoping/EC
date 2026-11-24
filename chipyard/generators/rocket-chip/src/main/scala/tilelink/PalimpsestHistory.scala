package freechips.rocketchip.tilelink

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Field

// P4-12/U-D09: storage policy parameters, not additional cache arrays.
case object PalimpsestHistoryEntries extends Field[Int](64)
case object PalimpsestEscapeEntries extends Field[Int](4)
case object PalimpsestCheckerEscapeWay extends Field[Boolean](false)
/** Beginning of the reserved Seq32 interval used to take an empty SCP.
  * A small value is useful for directed rollover tests.
  */
case object PalimpsestSeqRebaseThreshold extends Field[BigInt](0)

/** P3-15/P4-06/D07: cyclic transaction labels, with a contiguous batch.
  * These labels are scoped by a live LSQ/MSHR owner, not persistent content.
  * A slot is reusable only after its exactly-once terminal response. Skip
  * the short tail so callers can add batch offsets without crossing zero.
  * Do not use this allocator for Seq or persistent version ordering.
  */
class PalimpsestIdentityAllocator(width: Int, maxBatch: Int, limit: BigInt = 0) extends Module {
  private val last = if (limit == 0) (BigInt(1) << width) - 1 else limit
  require(width > 1 && maxBatch > 0 && last > maxBatch && last < (BigInt(1) << width))
  val io = IO(new Bundle {
    val consume = Input(UInt(log2Ceil(maxBatch + 1).W))
    val next = Output(UInt(width.W))
    val available = Output(Bool())
  })
  val next = RegInit(1.U(width.W))
  val base = Mux(next <= (last - maxBatch).U(width.W), next, 1.U(width.W))
  val advanced = base +& io.consume
  io.next := base
  io.available := true.B
  when (io.consume =/= 0.U) {
    assert(io.consume <= maxBatch.U, "identity allocation exceeds reserved group")
    assert(advanced <= last.U, "identity allocator would wrap")
    when (io.consume <= maxBatch.U) { next := advanced }
  }
}

/** P3-07/P3-08: single-Main history payloads, independent of coherence ways.
  * Content keys are immutable. The mailbox carries both EVT installs and
  * addressed cold queries.
  */
class PalimpsestHistoryLine extends Bundle {
  val address = UInt(64.W)
  val key = new CacheImageKey
  val data = UInt(512.W)
}
class PalimpsestHistoryQuery extends Bundle {
  val installOnly = Bool()
  val address = UInt(64.W)
  val occupied = Vec(32, Bool())
  val lower = Vec(32, UInt(32.W))
  val upper = Vec(32, UInt(32.W))
  def survives(seq: UInt): Bool = seq === 0.U || !(0 until 32).map(i =>
    occupied(i) && seq >= lower(i) && seq <= upper(i)).reduce(_ || _)
}
class PalimpsestHistoryResult extends Bundle {
  val found = Bool()
  val line = new PalimpsestHistoryLine
}

/** P2-09/P4-05: Checker endpoint of the held four-phase context mailbox.
  * The source holds payload until every bank AND Checker acknowledges, and
  * does not issue another request until all acknowledgements have fallen.
  * Install once, before acknowledging, in the receiving Checker's clock.
  */
class PalimpsestHistoryReceiver extends Module {
  val io = IO(new Bundle {
    val request = Input(Bool())
    val payload = Input(new PalimpsestHistoryQuery)
    val ack = Output(Bool())
    val context = Output(new PalimpsestHistoryQuery)
  })
  val payload = freechips.rocketchip.util.AsyncResetSynchronizerShiftReg(io.payload.asUInt, sync = 3)
    .asTypeOf(new PalimpsestHistoryQuery)
  val request = freechips.rocketchip.util.AsyncResetSynchronizerShiftReg(io.request, sync = 8)
  val context = RegInit(0.U.asTypeOf(new PalimpsestHistoryQuery))
  val ack = RegInit(false.B)
  when (!request) { ack := false.B }
    .elsewhen (!ack) { context := payload; ack := true.B }
  io.context := context
  io.ack := ack
}

/** P1-03/P3-07/P4-12, U-D04/05/09: addressed history with a cold scanner.
  * Metadata has one indexed comparison per cycle. Full lines live in a
  * single-read/single-write Mem, rather than a 64-way flop/MUX/CAM network.
  * The ingress register is an owned full-line buffer: capture.fire transfers
  * responsibility there; queries wait until that owner has reached the RAM.
  * Reserved entries accept preservation traffic, not ordinary SVB migration.
  */
class PalimpsestVersionHistory(entries: Int = 64, escapeEntries: Int = 4) extends Module {
  require(entries > 1 && escapeEntries >= 0 && escapeEntries < entries)
  val io = IO(new Bundle {
    val capture = Flipped(Decoupled(new PalimpsestHistoryLine))
    val captureEscape = Input(Bool())
    val watermark = Input(UInt(32.W))
    val context = Input(new PalimpsestHistoryQuery)
    val query = Flipped(Decoupled(new PalimpsestHistoryQuery))
    val result = Decoupled(new PalimpsestHistoryResult)
    val publish = Decoupled(new PalimpsestHistoryLine)
    val published = Input(Valid(new CacheImageKey))
    val publishPending = Output(Bool())
    val pressure = Output(Bool())
    val escapeAvailable = Output(Bool())
    val pressureSeq = Output(UInt(32.W))
    val empty = Output(Bool()) // safe maintenance completion, not a reclaim request
  })
  private val indexBits = log2Ceil(entries)
  val valid = RegInit(VecInit(Seq.fill(entries)(false.B)))
  val address = Reg(Vec(entries, UInt(64.W)))
  val key = Reg(Vec(entries, new CacheImageKey))
  val data = Mem(entries, UInt(512.W))
  val idle :: captureScan :: captureCommit :: queryScan :: queryRead :: respond :: publishScan :: publishRead :: Nil = Enum(8)
  val state = RegInit(idle)
  val index = RegInit(0.U(indexBits.W))
  val capturePending = RegInit(false.B)
  val captureLine = Reg(new PalimpsestHistoryLine)
  val capturedObsolete = RegInit(false.B)
  val obsolete = RegInit(0.U(entries.W))
  val query = Reg(new PalimpsestHistoryQuery)
  val result = Reg(new PalimpsestHistoryResult)
  val found = RegInit(false.B)
  val best = Reg(new CacheImageKey)
  val bestIndex = Reg(UInt(indexBits.W))
  val wb = RegInit(false.B)
  val wbSent = RegInit(false.B)
  val wbIndex = Reg(UInt(indexBits.W))
  val wbLine = Reg(new PalimpsestHistoryLine)
  // Conservative cached OR. Set on capture/SW/context changes, clear only
  // after a complete publish scan finds no safe entry. No wide CAM needed.
  val maybeSafe = RegInit(false.B)
  val lastWatermark = RegNext(io.watermark, 0.U)
  val scanWatermark = Reg(UInt(32.W))
  val free = ~valid.asUInt
  val freeCount = PopCount(free)
  io.pressure := freeCount <= escapeEntries.U
  // The accepted ingress already owns one slot, even before its scan commits.
  // Do not advertise that same last credit to a cache preservation reader.
  io.escapeAvailable := free.orR && !(capturePending && freeCount <= 1.U)
  val oldest = RegInit(0.U(32.W))
  io.pressureSeq := oldest
  io.capture.ready := state === idle && !capturePending && !io.query.valid &&
    (freeCount > escapeEntries.U || (io.captureEscape && free.orR) ||
      !io.context.survives(io.capture.bits.key.contentSeq))
  io.query.ready := state === idle && !capturePending
  io.result.valid := state === respond
  io.result.bits := result
  io.publish.valid := wb && !wbSent
  io.publish.bits := wbLine
  // SW may change on the very cycle a safe resident release is selected.
  // Advertise that work immediately, before maybeSafe's registering edge,
  // so the resident cannot overtake an older newly-safe history image.
  io.publishPending := wb || maybeSafe || capturePending || io.watermark =/= lastWatermark
  io.empty := !valid.asUInt.orR && !capturePending && !wb && state === idle && !maybeSafe
  when (io.watermark =/= lastWatermark) { maybeSafe := true.B }
  when (io.capture.fire) {
    capturePending := true.B
    captureLine := io.capture.bits
    maybeSafe := true.B
  }
  when (state === idle) {
    index := 0.U
    found := false.B
    when (capturePending) {
      capturedObsolete := false.B
      obsolete := 0.U
      state := captureScan
    }.elsewhen (io.query.fire) {
      query := io.query.bits
      state := queryScan
    }.elsewhen (!io.capture.fire && !wb && maybeSafe) {
      oldest := 0.U
      scanWatermark := io.watermark
      state := publishScan
    }
  }
  val currentValid = valid(index) && io.context.survives(key(index).contentSeq)
  val currentOwned = wb && wbIndex === index
  def later(a: CacheImageKey, b: CacheImageKey): Bool =
    a.contentSeq > b.contentSeq || (a.contentSeq === b.contentSeq && a.generation > b.generation)
  def equivalentLifetime(a: CacheImageKey, b: CacheImageKey): Bool =
    a.contentSeq === b.contentSeq || (CacheImage.safe(a, io.watermark) && CacheImage.safe(b, io.watermark))
  val scanning = state === captureScan || state === queryScan || state === publishScan
  when (scanning) {
    // Passive dead-entry reclamation uses this already selected metadata.
    when (valid(index) && !currentValid && !currentOwned) { valid(index) := false.B }
    when (state === captureScan && currentValid && address(index) === captureLine.address) {
      when (key(index).asUInt === captureLine.key.asUInt ||
        (later(key(index), captureLine.key) && equivalentLifetime(key(index), captureLine.key))) {
        capturedObsolete := true.B
      }
      when (!currentOwned && later(captureLine.key, key(index)) && equivalentLifetime(captureLine.key, key(index))) {
        obsolete := obsolete | UIntToOH(index, entries)
      }
    }
    val queryMatch = valid(index) && address(index) === query.address && query.survives(key(index).contentSeq)
    // Use one safe prefix for the whole publication scan. A newer version
    // must not become eligible after the scan has passed its predecessor.
    // A changed watermark requests another scan or is picked up after WB ACK.
    val safe = currentValid && CacheImage.safe(key(index), scanWatermark)
    val select = Mux(state === queryScan,
      queryMatch && (!found || later(key(index), best)),
      safe && (!found || later(best, key(index))))
    when ((state === queryScan || state === publishScan) && select) {
      found := true.B
      best := key(index)
      bestIndex := index
    }
    when (state === publishScan && currentValid && key(index).contentSeq =/= 0.U &&
      (oldest === 0.U || key(index).contentSeq < oldest)) { oldest := key(index).contentSeq }
    when (index === (entries - 1).U) {
      when (state === captureScan) { state := captureCommit }
      when (state === queryScan) { state := queryRead }
      when (state === publishScan) {
        when (found || select) { state := publishRead }
          .otherwise { state := idle; maybeSafe := io.watermark =/= scanWatermark }
      }
    }.otherwise { index := index + 1.U }
  }
  when (state === captureCommit) {
    val drop = capturedObsolete || !io.context.survives(captureLine.key.contentSeq)
    val reclaim = obsolete & ~Mux(wb, UIntToOH(wbIndex, entries), 0.U(entries.W))
    val available = free | reclaim
    when (drop || available.orR) {
      when (!drop) {
        val slot = PriorityEncoder(available)
        for (i <- 0 until entries) { when (reclaim(i)) { valid(i) := false.B } }
        valid(slot) := true.B
        address(slot) := captureLine.address
        key(slot) := captureLine.key
        data.write(slot, captureLine.data)
      }
      capturePending := false.B
      state := idle
    }
  }
  // One shared RAM read port, used only after the indexed selection scan.
  val selectedData = data.read(bestIndex)
  when (state === queryRead) {
    result.found := found
    result.line.address := query.address
    result.line.key := best
    result.line.data := selectedData
    state := respond
  }
  when (io.result.fire) { state := idle }
  when (state === publishRead) {
    wb := true.B
    wbSent := false.B
    wbIndex := bestIndex
    wbLine.address := address(bestIndex)
    wbLine.key := best
    wbLine.data := selectedData
    state := idle
  }
  when (io.publish.fire) { wbSent := true.B }
  when (io.published.valid) {
    assert(wb && wbSent && io.published.bits.asUInt === wbLine.key.asUInt,
      "L2 history publish ACK identity mismatch")
    valid(wbIndex) := false.B
    wb := false.B
    wbSent := false.B
    maybeSafe := true.B
  }
}
