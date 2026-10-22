package sifive.blocks.inclusivecache

import Chisel._
import freechips.rocketchip.tilelink._

/** reason: 1 = same-line Release, 2 = same-line ProbeAck, 3 = trusted A write.
  * Set victims use the MSHR Release/ReleaseAck protocol, never this Put engine.
  */
class L2PreservationCandidate(params: InclusiveCacheParameters) extends InclusiveCacheBundle(params) {
  val set = UInt(width = params.setBits)
  val way = UInt(width = params.wayBits)
  val tag = UInt(width = params.tagBits)
  val image = new CacheImageKey
  val dirty = Bool()
  val outerPreserved = Bool()
  val reason = UInt(width = 2)
}

object L2Preservation {
  def blocked(image: CacheImageKey, dirty: Bool, preserved: Bool, watermark: UInt): Bool =
    !CacheImage.safe(image, watermark) || (dirty && !preserved)
}

/** Single non-destructive outer checkpoint engine. No candidate is accepted
  * until older bank writers/readers drain. Scheduler reserves the captured set
  * through ACK; the data array, directory and MSHR snapshots remain unchanged.
  * A Put does not drop the L2's T permission at the terminal CacheCork.
  */
class L2Preservation(params: InclusiveCacheParameters) extends Module {
  val io = new Bundle {
    val candidate = Valid(new L2PreservationCandidate(params)).flip
    val drained = Bool().flip
    val watermark = UInt(width = 32).flip
    val bank = UInt(width = 8).flip
    val lock = Valid(new L2PreservationCandidate(params))
    val completed = Valid(new L2PreservationCandidate(params))
    val a = Decoupled(new TLBundleA(params.outer.bundle))
    val d = Decoupled(new TLBundleD(params.outer.bundle)).flip
    val bs_adr = Decoupled(new BankedStoreOuterAddress(params))
    val bs_dat = new BankedStoreOuterDecoded(params).flip
    val counters = Vec(6, UInt(width = 64)) // req, ack, pending cycles, validation, stale, duplicate
    val txn = UInt(width = 64)
    // Observations only; no debug signal participates in admission/completion.
    val debugState = UInt(width = 3)
    val debugIssued = Bool()
    val debugAckSeen = Bool()
  }
  require(params.lastLevel, "checkpoint Put requires a terminal outer memory")
  require(params.outer.bundle.echoFields.exists(_.key == CachePreserveTxn),
    "Stage3 requires end-to-end completion echo")
  val idle :: read :: delay1 :: delay2 :: send :: waitAck :: failed :: Nil = chisel3.util.Enum(7)
  val state = RegInit(idle)
  val snapshot = Reg(new L2PreservationCandidate(params))
  val serial = RegInit(UInt(0, width = 64))
  val lastAck = RegInit(UInt(0, width = 64))
  val beat = RegInit(UInt(0, width = math.max(1, params.outerBeatBits)))
  val data = Reg(UInt(width = params.outer.bundle.dataBits))
  val issued = RegInit(Bool(false))
  io.debugState := state
  io.debugIssued := issued
  io.debugAckSeen := io.d.fire()
  val counts = RegInit(Vec(Seq.fill(6)(UInt(0, width = 64))))
  io.counters := counts
  val safe = CacheImage.safe(io.candidate.bits.image, io.watermark)
  val need = io.candidate.valid && safe && io.candidate.bits.dirty && !io.candidate.bits.outerPreserved
  val capture = state === idle && need && io.drained
  io.txn := Mux(capture, serial + UInt(1), serial)
  val active = state =/= idle
  io.lock.valid := active || capture
  io.lock.bits := Mux(active, snapshot, io.candidate.bits)
  val validationBlock = io.candidate.valid && !safe
  val wasBlocked = RegNext(validationBlock, Bool(false))
  when (validationBlock && !wasBlocked) {
    counts(3) := counts(3) + UInt(1)
    printf("STAGE3_TX L2_VALIDATION_BLOCK bank=%x set=%x way=%x tag=%x gen=%x seq=%x writer=%x reason=%x\n",
      io.bank, io.candidate.bits.set, io.candidate.bits.way, io.candidate.bits.tag,
      io.candidate.bits.image.generation, io.candidate.bits.image.contentSeq,
      io.candidate.bits.image.writer, io.candidate.bits.reason)
  }
  when (active) { counts(2) := counts(2) + UInt(1) }
  when (capture) {
    assert(!serial.andR, "L2 preservation serial exhausted")
    serial := serial + UInt(1)
    snapshot := io.candidate.bits
    beat := UInt(0)
    issued := Bool(false)
    state := read
    printf("STAGE3_TX L2_PRESERVE_PENDING bank=%x txn=%x set=%x way=%x tag=%x valid=%x writer=%x gen=%x seq=%x reason=%x\n",
      io.bank, serial + UInt(1), io.candidate.bits.set, io.candidate.bits.way, io.candidate.bits.tag,
      io.candidate.bits.image.valid, io.candidate.bits.image.writer,
      io.candidate.bits.image.generation, io.candidate.bits.image.contentSeq, io.candidate.bits.reason)
  }
  io.bs_adr.valid := state === read
  io.bs_adr.bits := 0.U.asTypeOf(new BankedStoreOuterAddress(params))
  io.bs_adr.bits.set := snapshot.set
  io.bs_adr.bits.way := snapshot.way
  io.bs_adr.bits.beat := beat
  io.bs_adr.bits.mask := ~UInt(0, width = params.outerMaskBits)
  when (io.bs_adr.fire()) { state := delay1 }
  when (state === delay1) { state := delay2 }
  when (state === delay2) { data := io.bs_dat.data; state := send }
  val finalBeat = beat === UInt(params.cache.blockBytes / params.outer.manager.beatBytes - 1)
  io.a.valid := state === send
  io.a.bits := 0.U.asTypeOf(new TLBundleA(params.outer.bundle))
  io.a.bits.opcode := TLMessages.PutFullData
  io.a.bits.size := UInt(params.offsetBits)
  io.a.bits.source := UInt(InclusiveCacheParameters.out_mshrs(params.cache, params.micro))
  io.a.bits.address := params.expandAddress(snapshot.tag, snapshot.set, UInt(0))
  io.a.bits.mask := ~UInt(0, width = params.outer.manager.beatBytes)
  io.a.bits.data := data
  io.a.bits.echo(CachePreserveTxn) := serial
  when (io.a.fire()) {
    assert(CacheImage.safe(snapshot.image, io.watermark), "L2_SPEC_OUTER_WRITE_ERROR checkpoint")
    when (beat === UInt(0)) {
      assert(!issued, "L2_DUP_PRESERVE_ERROR")
      issued := Bool(true)
      counts(0) := counts(0) + UInt(1)
      printf("STAGE3_TX L2_PRESERVE_REQ bank=%x txn=%x set=%x way=%x tag=%x valid=%x writer=%x gen=%x seq=%x reason=%x\n",
        io.bank, serial, snapshot.set, snapshot.way, snapshot.tag, snapshot.image.valid,
        snapshot.image.writer, snapshot.image.generation, snapshot.image.contentSeq, snapshot.reason)
    }
    when (finalBeat) { state := waitAck }
      .otherwise { beat := beat + UInt(1); state := read }
  }
  // A response must correspond to the entire accepted line, not an enqueue or
  // a prefix of a multibeat Put. A zero-latency final-beat response is legal.
  val sent = state === waitAck || (io.a.fire() && finalBeat)
  val matches = active && sent && io.d.bits.opcode === TLMessages.AccessAck &&
    io.d.bits.source === UInt(InclusiveCacheParameters.out_mshrs(params.cache, params.micro)) &&
    io.d.bits.size === UInt(params.offsetBits) && io.d.bits.echo(CachePreserveTxn) === serial
  val complete = io.d.fire() && matches && !io.d.bits.denied && !io.d.bits.corrupt
  io.d.ready := Bool(true)
  io.completed.valid := complete
  io.completed.bits := snapshot
  when (io.d.fire()) {
    when (matches) {
      assert(!io.d.bits.denied && !io.d.bits.corrupt, "L2 preservation outer failure")
      when (complete) {
        state := idle
        lastAck := serial
        counts(1) := counts(1) + UInt(1)
        printf("STAGE3_TX L2_PRESERVE_ACK bank=%x txn=%x set=%x way=%x tag=%x valid=%x writer=%x gen=%x seq=%x reason=%x\n",
          io.bank, serial, snapshot.set, snapshot.way, snapshot.tag, snapshot.image.valid,
          snapshot.image.writer, snapshot.image.generation, snapshot.image.contentSeq, snapshot.reason)
      }.otherwise { state := failed }
    }.otherwise {
      counts(4) := counts(4) + UInt(1)
      when (lastAck =/= UInt(0) && io.d.bits.echo(CachePreserveTxn) === lastAck) {
        counts(5) := counts(5) + UInt(1)
      }
      printf("STAGE3_TX L2_STALE_ACK_ERROR bank=%x txn=%x current=%x ignored=1\n",
        io.bank, io.d.bits.echo(CachePreserveTxn), serial)
    }
  }
  val priorActive = RegNext(active, Bool(false))
  val priorComplete = RegNext(complete, Bool(false))
  when (priorActive && !active) { assert(priorComplete, "L2 pending released without matching completion") }
  val priorSnapshot = RegNext(snapshot.asUInt)
  when (active && priorActive) { assert(snapshot.asUInt === priorSnapshot, "L2 pending provenance changed") }
}
