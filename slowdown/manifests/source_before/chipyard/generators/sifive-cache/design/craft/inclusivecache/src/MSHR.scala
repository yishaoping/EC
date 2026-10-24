/*
 * Copyright 2019 SiFive, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You should have received a copy of LICENSE.Apache2 along with
 * this software. If not, you may obtain a copy at
 *
 *    https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package sifive.blocks.inclusivecache

import Chisel._
import chisel3.internal.sourceinfo.SourceInfo
import freechips.rocketchip.tilelink._
import freechips.rocketchip.guardiancouncil.GH_GlobalParams
import TLPermissions._
import TLMessages._
import MetaData._
import chisel3.PrintableHelper

// Park only the original request and its validation obligation. No directory
// snapshot/way or ownership is retained across replay.
class ClientWaitRequest(params: InclusiveCacheParameters) extends InclusiveCacheBundle(params)
{
  val request = new FullRequest(params)
  val seq = UInt(width = 32)
}

class ScheduleRequest(params: InclusiveCacheParameters) extends InclusiveCacheBundle(params)
{
  val a = Valid(new SourceARequest(params))
  val b = Valid(new SourceBRequest(params))
  val c = Valid(new SourceCRequest(params))
  val d = Valid(new SourceDRequest(params))
  val e = Valid(new SourceERequest(params))
  val x = Valid(new SourceXRequest(params))
  val dir = Valid(new DirectoryWrite(params))
  val park = Valid(new ClientWaitRequest(params))
  val reload = Bool() // get next request via allocate (if any)
}

class MSHRStatus(params: InclusiveCacheParameters) extends InclusiveCacheBundle(params)
{
  val set = UInt(width = params.setBits)
  val tag = UInt(width = params.tagBits)
  val way = UInt(width = params.wayBits)
  val blockB = Bool()
  val nestB  = Bool()
  val blockC = Bool()
  val nestC  = Bool()
}

// Observation only: distinguish a missing inner response from validation or
// outer completion when a control flush cannot finish. Never feeds scheduling.
class MSHRFlushStatus(params: InclusiveCacheParameters) extends InclusiveCacheBundle(params)
{
  val active = Bool()
  val mshr = UInt(width = 32)
  val metaValid = Bool()
  val hit = Bool()
  val state = UInt(width = 4) // stable diagnostic code, independent of Scala object initialization
  val address = UInt(width = params.inner.bundle.addressBits)
  val set = UInt(width = params.setBits)
  val way = UInt(width = params.wayBits)
  val image = new CacheImageKey
  val dirty = Bool()
  val clients = UInt(width = params.clientBits)
  val outerPreserved = Bool()
  val probeScheduled = Bool()
  val probeAckFirst = Bool()
  val probeAckLast = Bool()
  val releaseIssued = Bool()
  val releaseSent = Bool()
  val releaseAck = Bool()
  val noWait = Bool()
  val commitValid = Bool()
  val commitReady = Bool() // actual final directory schedule handshake
}

class NestedWriteback(params: InclusiveCacheParameters) extends InclusiveCacheBundle(params)
{
  val set = UInt(width = params.setBits)
  val tag = UInt(width = params.tagBits)
  val b_toN       = Bool() // nested Probes may unhit us
  val b_toB       = Bool() // nested Probes may demote us
  val b_clr_dirty = Bool() // nested Probes clear dirty
  val c_set_dirty = Bool() // nested Releases MAY set dirty
  val c_set_dcache = Bool() // nested DCache releases mark data provenance
  val c_set_packet = Bool() // nested dirty writeback carries packet provenance
  val packetSeq = UInt(width = GH_GlobalParams.GH_PACKET_SEQ_BITS)
  val packetTracked = Bool()
  val image = new CacheImageKey
  val outerPreserved = Bool()
}

sealed trait CacheState
{
  val code = UInt(CacheState.index)
  CacheState.index = CacheState.index + 1
}

object CacheState
{
  var index = 0
}

case object S_INVALID  extends CacheState
case object S_BRANCH   extends CacheState
case object S_BRANCH_C extends CacheState
case object S_TIP      extends CacheState
case object S_TIP_C    extends CacheState
case object S_TIP_CD   extends CacheState
case object S_TIP_D    extends CacheState
case object S_TRUNK_C  extends CacheState
case object S_TRUNK_CD extends CacheState

class MSHR(params: InclusiveCacheParameters, trace: Boolean = false, id: Int = 0) extends Module
{
  val io = new Bundle {
    val allocate  = Valid(new AllocateRequest(params)).flip // refills MSHR for next cycle
    val directory = Valid(new DirectoryResult(params)).flip // triggers schedule setup
    val status    = Valid(new MSHRStatus(params))
    val schedule  = Decoupled(new ScheduleRequest(params))
    val sinkc     = Valid(new SinkCResponse(params)).flip
    val sinkd     = Valid(new SinkDResponse(params)).flip
    val sinke     = Valid(new SinkEResponse(params)).flip
    val nestedwb  = new NestedWriteback(params).flip
    val resident = Valid(new DirectoryResult(params))
    val preserved = Valid(new L2PreservationCandidate(params)).flip
    val releaseSent = Valid(UInt(width = 64)).flip
    val quiescent = Bool()
    val watermark = UInt(width = 32).flip
    val bank = UInt(width = 8).flip
    val flushStatus = new MSHRFlushStatus(params)
  }

  val request_valid = RegInit(Bool(false))
  val request = Reg(new FullRequest(params))
  val meta_valid = RegInit(Bool(false))
  val meta = Reg(new DirectoryResult(params))
  val planStarted = RegInit(Bool(false))
  io.resident.valid := request_valid && meta_valid
  io.resident.bits := meta
  val releaseGeneration = RegInit(UInt(0, width = 64))
  val releaseSent = RegInit(Bool(false))
  val releaseIssued = RegInit(Bool(false))
  val releaseSnapshot = Reg(new DirectoryResult(params))

  // Define which states are valid
  when (meta_valid) {
    when (meta.state === INVALID) {
      assert (!meta.clients.orR)
      assert (!meta.dirty)
      assert (!meta.dcache)
    }
    when (meta.state === BRANCH) {
      assert (!meta.dirty)
    }
    when (meta.state === TRUNK) {
      assert (meta.clients.orR)
      assert ((meta.clients & (meta.clients - UInt(1))) === UInt(0)) // at most one
    }
    when (meta.state === TIP) {
      // noop
    }
  }

  // Completed transitions (s_ = scheduled), (w_ = waiting)
  val s_rprobe         = RegInit(Bool(true)) // B
  val w_rprobeackfirst = RegInit(Bool(true))
  val w_rprobeacklast  = RegInit(Bool(true))
  val s_release        = RegInit(Bool(true)) // CW w_rprobeackfirst
  val w_releaseack     = RegInit(Bool(true))
  val s_pprobe         = RegInit(Bool(true)) // B
  val s_acquire        = RegInit(Bool(true)) // A  s_release, s_pprobe [1]
  val s_flush          = RegInit(Bool(true)) // X  w_releaseack
  val w_grantfirst     = RegInit(Bool(true))
  val w_grantlast      = RegInit(Bool(true))
  val w_grant          = RegInit(Bool(true)) // first | last depending on wormhole
  val w_pprobeackfirst = RegInit(Bool(true))
  val w_pprobeacklast  = RegInit(Bool(true))
  val w_pprobeack      = RegInit(Bool(true)) // first | last depending on wormhole
  val s_probeack       = RegInit(Bool(true)) // C  w_pprobeackfirst (mutually exclusive with next two s_*)
  val s_grantack       = RegInit(Bool(true)) // E  w_grantfirst ... CAN require both outE&inD to service outD
  val s_execute        = RegInit(Bool(true)) // D  w_pprobeack, w_grant
  val w_grantack       = RegInit(Bool(true))
  val s_writeback      = RegInit(Bool(true)) // W  w_*

  // [1]: We cannot issue outer Acquire while holding blockB (=> outA can stall)
  // However, inB and outC are higher priority than outB, so s_release and s_pprobe
  // may be safely issued while blockB. Thus we must NOT try to schedule the
  // potentially stuck s_acquire with either of them (scheduler is all or none).

  // Meta-data that we discover underway
  val sink = Reg(UInt(width = params.outer.bundle.sinkBits))
  val gotT = Reg(Bool())
  val bad_grant = Reg(Bool())
  val probes_done = Reg(UInt(width = params.clientBits))
  val probes_toN = Reg(UInt(width = params.clientBits))
  val probes_noT = Reg(Bool())

  // When a nested transaction completes, update our meta data
  when (meta_valid && meta.state =/= INVALID &&
        io.nestedwb.set === request.set && io.nestedwb.tag === meta.tag) {
    when (io.nestedwb.b_clr_dirty) { meta.dirty := Bool(false) }
    when (io.nestedwb.c_set_dirty) { meta.dirty := Bool(true) }
    when (io.nestedwb.c_set_dcache) { meta.dcache := Bool(true) }
    when (io.nestedwb.c_set_packet) {
      meta.packetSeq := io.nestedwb.packetSeq
      meta.packetTracked := io.nestedwb.packetTracked
      meta.image := io.nestedwb.image
      meta.outerPreserved := io.nestedwb.outerPreserved
    }
    when (io.nestedwb.b_toB) { meta.state := BRANCH }
    when (io.nestedwb.b_toN) { meta.hit := Bool(false) }
  }

  // Scheduler status
  io.status.valid := request_valid
  io.status.bits.set    := request.set
  io.status.bits.tag    := request.tag
  io.status.bits.way    := meta.way
  io.status.bits.blockB := !meta_valid || ((!w_releaseack || !w_rprobeacklast || !w_pprobeacklast) && !w_grantfirst)
  io.status.bits.nestB  := meta_valid && w_releaseack && w_rprobeacklast && w_pprobeacklast && !w_grantfirst
  // The above rules ensure we will block and not nest an outer probe while still doing our
  // own inner probes. Thus every probe wakes exactly one MSHR.
  io.status.bits.blockC := !meta_valid || (s_release && !w_releaseack)
  io.status.bits.nestC  := meta_valid && !(s_release && !w_releaseack) &&
    (!w_rprobeackfirst || !w_pprobeackfirst || !w_grantfirst)
  // The w_grantfirst in nestC is necessary to deal with:
  //   acquire waiting for grant, inner release gets queued, outer probe -> inner probe -> deadlock
  // ... this is possible because the release+probe can be for same set, but different tag

  // We can only demand: block, nest, or queue
  assert (!io.status.bits.nestB || !io.status.bits.blockB)
  assert (!io.status.bits.nestC || !io.status.bits.blockC)

  // Scheduler requests
  val no_wait = w_rprobeacklast && w_releaseack && w_grantlast && w_pprobeacklast && w_grantack
  io.quiescent := w_rprobeacklast && w_pprobeacklast && w_grantlast
  io.schedule.bits.a.valid := !s_acquire && s_release && w_releaseack && s_pprobe
  io.schedule.bits.b.valid := !s_rprobe || !s_pprobe
  io.schedule.bits.c.valid := (!s_release && w_rprobeacklast) || (!s_probeack && w_pprobeacklast)
  io.schedule.bits.d.valid := !s_execute && w_pprobeacklast && w_grant
  io.schedule.bits.e.valid := !s_grantack && w_grantfirst
  io.schedule.bits.x.valid := !s_flush && w_releaseack
  // Keep old tag/ownership recoverable until outer completion. In particular
  // neither an invalid tag nor an acquire/refill may overtake ReleaseAck.
  io.schedule.bits.dir.valid := !s_writeback && no_wait
  io.schedule.bits.reload := no_wait
  io.schedule.valid := io.schedule.bits.a.valid || io.schedule.bits.b.valid || io.schedule.bits.c.valid ||
                       io.schedule.bits.d.valid || io.schedule.bits.e.valid || io.schedule.bits.x.valid ||
                       io.schedule.bits.dir.valid

  val peerExposure = request.prio(0) && !request.control && !params.isImageAware(request.source) &&
    CacheImage.exposesResident(request.opcode)
  val peerUnsafe = request_valid && meta_valid && meta.hit && peerExposure &&
    !CacheImage.safe(meta.image, io.watermark)
  // Before any Probe/Acquire, park immediately. If the key first becomes unsafe
  // in ProbeAckData, finish those handshakes and outer GrantAck before parking.
  // Neither case has executed SourceD or granted the peer ownership.
  val parkEarly = peerUnsafe && !planStarted
  val parkLate = peerUnsafe && !s_execute && w_pprobeacklast && w_rprobeacklast &&
    w_grantlast && s_grantack && s_acquire && s_pprobe && s_rprobe && w_releaseack
  val parkPeer = parkEarly || parkLate
  val parkCommit = parkPeer && planStarted
  io.schedule.bits.park.valid := parkPeer
  io.schedule.bits.park.bits.request := request
  io.schedule.bits.park.bits.seq := meta.image.contentSeq
  // Suppress only the unsafe execution while outstanding probes/refill/outer E
  // drain. In particular E must not be coupled to a blocked D admission.
  when (peerUnsafe) {
    io.schedule.bits.d.valid := Bool(false)
    io.schedule.bits.dir.valid := Bool(false)
    io.schedule.bits.reload := Bool(false)
  }
  when (parkPeer) {
    io.schedule.bits.a.valid := Bool(false)
    io.schedule.bits.b.valid := Bool(false)
    io.schedule.bits.c.valid := Bool(false)
    io.schedule.bits.d.valid := Bool(false)
    io.schedule.bits.e.valid := Bool(false)
    io.schedule.bits.x.valid := Bool(false)
    io.schedule.bits.dir.valid := parkCommit
    io.schedule.bits.reload := Bool(true)
  }
  io.schedule.valid := io.schedule.bits.a.valid || io.schedule.bits.b.valid || io.schedule.bits.c.valid ||
    io.schedule.bits.d.valid || io.schedule.bits.e.valid || io.schedule.bits.x.valid ||
    io.schedule.bits.dir.valid || io.schedule.bits.park.valid

  // Schedule completions
  when (io.schedule.ready) {
    planStarted := Bool(true)
                                    s_rprobe     := Bool(true)
    when (w_rprobeacklast)        { s_release    := Bool(true) }
                                    s_pprobe     := Bool(true)
    when (s_release && w_releaseack && s_pprobe) { s_acquire := Bool(true) }
    when (w_releaseack)           { s_flush      := Bool(true) }
    when (w_pprobeacklast)        { s_probeack   := Bool(true) }
    when (w_grantfirst)           { s_grantack   := Bool(true) }
    when (io.schedule.bits.d.valid) { s_execute := Bool(true) }
    when (io.schedule.bits.dir.valid) { s_writeback := Bool(true) }
    // Await the next operation
    when ((no_wait && !peerUnsafe) || parkPeer) {
      request_valid := Bool(false)
      meta_valid := Bool(false)
    }
  }

  // A parked request has no remaining plan in this MSHR. Allocation/lookup
  // below has higher priority and initializes a queued successor normally.
  when (io.schedule.fire() && parkPeer) {
    s_rprobe := Bool(true); w_rprobeackfirst := Bool(true); w_rprobeacklast := Bool(true)
    s_release := Bool(true); w_releaseack := Bool(true)
    s_pprobe := Bool(true); w_pprobeackfirst := Bool(true); w_pprobeacklast := Bool(true)
    w_pprobeack := Bool(true)
    s_acquire := Bool(true); w_grantfirst := Bool(true); w_grantlast := Bool(true); w_grant := Bool(true)
    s_grantack := Bool(true); s_probeack := Bool(true); s_flush := Bool(true)
    s_execute := Bool(true); w_grantack := Bool(true); s_writeback := Bool(true)
  }

  // Resulting meta-data
  val final_meta_writeback = Wire(init = meta)

  val req_clientBit = params.clientBit(request.source)
  val req_needT = needT(request.opcode, request.param)
  val req_acquire = request.opcode === AcquireBlock || request.opcode === AcquirePerm
  val meta_no_clients = !meta.clients.orR
  val req_promoteT = req_acquire && Mux(meta.hit, meta_no_clients && meta.state === TIP, gotT)

  when (request.prio(2) && Bool(!params.firstLevel)) { // always a hit
    final_meta_writeback.dirty   := meta.dirty || request.opcode(0)
    final_meta_writeback.dcache  := meta.dcache || params.isDCacheSource(request.source)
    final_meta_writeback.state   := Mux(request.param =/= TtoT && meta.state === TRUNK, TIP, meta.state)
    final_meta_writeback.clients := meta.clients & ~Mux(isToN(request.param), req_clientBit, UInt(0))
    final_meta_writeback.hit     := Bool(true) // chained requests are hits
  } .elsewhen (request.control && Bool(params.control)) { // request.prio(0)
    when (meta.hit) {
      final_meta_writeback.dirty   := Bool(false)
      final_meta_writeback.dcache  := Bool(false)
      final_meta_writeback.packetSeq := UInt(0)
      final_meta_writeback.packetTracked := Bool(false)
      final_meta_writeback.image := 0.U.asTypeOf(new CacheImageKey)
      final_meta_writeback.outerPreserved := Bool(false)
      final_meta_writeback.state   := INVALID
      final_meta_writeback.clients := meta.clients & ~probes_toN
    }
    final_meta_writeback.hit := Bool(false)
  } .otherwise {
    final_meta_writeback.dirty := (meta.hit && meta.dirty) || !request.opcode(2)
    final_meta_writeback.dcache := (meta.hit && meta.dcache) || params.isDCacheSource(request.source)
    final_meta_writeback.state := Mux(req_needT,
                                    Mux(req_acquire, TRUNK, TIP),
                                    Mux(!meta.hit, Mux(gotT, Mux(req_acquire, TRUNK, TIP), BRANCH),
                                      MuxLookup(meta.state, UInt(0, width=2), Seq(
                                        INVALID -> BRANCH,
                                        BRANCH  -> BRANCH,
                                        TRUNK   -> TIP,
                                        TIP     -> Mux(meta_no_clients && req_acquire, TRUNK, TIP)))))
    final_meta_writeback.clients := Mux(meta.hit, meta.clients & ~probes_toN, UInt(0)) |
                                    Mux(req_acquire, req_clientBit, UInt(0))
    final_meta_writeback.tag := request.tag
    final_meta_writeback.hit := Bool(true)
    when (!meta.hit) {
      final_meta_writeback.packetSeq := UInt(0)
      final_meta_writeback.packetTracked := Bool(false)
      final_meta_writeback.image := 0.U.asTypeOf(new CacheImageKey)
      // New refill came from the coherent outer image. It is clean; no
      // authored inner version is inferred from permission-only transitions.
      final_meta_writeback.outerPreserved := Bool(true)
    }
  }

  when (bad_grant) {
    when (meta.hit) {
      // upgrade failed (B -> T)
      assert (!meta_valid || meta.state === BRANCH)
      final_meta_writeback.hit     := Bool(true)
      final_meta_writeback.dirty   := Bool(false)
      final_meta_writeback.dcache  := meta.dcache
      final_meta_writeback.packetSeq := meta.packetSeq
      final_meta_writeback.packetTracked := meta.packetTracked
      final_meta_writeback.image := meta.image
      final_meta_writeback.state   := BRANCH
      final_meta_writeback.clients := meta.clients & ~probes_toN
    } .otherwise {
      // failed N -> (T or B)
      final_meta_writeback.hit     := Bool(false)
      final_meta_writeback.dirty   := Bool(false)
      final_meta_writeback.dcache  := Bool(false)
      final_meta_writeback.packetSeq := UInt(0)
      final_meta_writeback.packetTracked := Bool(false)
      final_meta_writeback.image := 0.U.asTypeOf(new CacheImageKey)
      final_meta_writeback.outerPreserved := Bool(false)
      final_meta_writeback.state   := INVALID
      final_meta_writeback.clients := UInt(0)
    }
  }

  // A nested inner Release carries the line's BOOM packet provenance.  Keep
  // it with the resident directory line so a later L2 eviction can classify
  // the corresponding writeback.
  when (request.prio(2) && request.opcode === ReleaseData) {
    final_meta_writeback.packetSeq := request.packetSeq
    final_meta_writeback.packetTracked := request.packetTracked
    final_meta_writeback.image := request.image
    final_meta_writeback.outerPreserved := meta.outerPreserved &&
      request.image.valid && meta.image.asUInt === request.image.asUInt
  }

  // Denial retains the previous bytes/key (or the invalid BASE on a miss).
  // A failed trusted operation must not relabel an old speculative image.
  when (request.prio(0) && !request.opcode(2) && !bad_grant) {
    final_meta_writeback.image := 0.U.asTypeOf(new CacheImageKey)
    final_meta_writeback.packetSeq := 0.U
    final_meta_writeback.packetTracked := Bool(false)
    final_meta_writeback.outerPreserved := Bool(false)
  }

  when (parkPeer) {
    // Publish only effects of already completed probes; the waiting requester
    // has received no D beat and MUST NOT be added to the sharer/owner mask.
    final_meta_writeback := meta
    when (planStarted) {
      final_meta_writeback.clients := meta.clients & ~probes_toN
      when (meta.state === TRUNK && probes_noT) { final_meta_writeback.state := TIP }
    }
  }
  when (io.schedule.fire() && parkPeer) {
    assert(!s_execute && !releaseIssued, "peer park after response/victim release")
    assert(!io.schedule.bits.d.valid && !io.schedule.bits.a.valid && !io.schedule.bits.b.valid &&
      !io.schedule.bits.c.valid && !io.schedule.bits.e.valid, "peer park emitted protocol work")
    assert(final_meta_writeback.image.asUInt === meta.image.asUInt &&
      final_meta_writeback.outerPreserved === meta.outerPreserved &&
      final_meta_writeback.dirty === meta.dirty, "peer park changed protected bytes/receipt")
    assert((final_meta_writeback.clients & ~meta.clients) === UInt(0), "peer park granted ownership")
  }

  // Just because a client says BtoT, by the time we process the request he may be N.
  // Therefore, we must consult our own meta-data state to confirm he owns the line still.
  val honour_BtoT = meta.hit && (meta.clients & req_clientBit).orR

  // The client asking us to act is proof they don't have permissions.
  val excluded_client = Mux(meta.hit && request.prio(0) && skipProbeN(request.opcode, params.cache.hintsSkipProbe), req_clientBit, UInt(0))
  io.schedule.bits.a.bits.tag     := request.tag
  io.schedule.bits.a.bits.set     := request.set
  io.schedule.bits.a.bits.param   := Mux(req_needT, Mux(meta.hit, BtoT, NtoT), NtoB)
  io.schedule.bits.a.bits.block   := request.size =/= UInt(log2Ceil(params.cache.blockBytes)) ||
                                     !(request.opcode === PutFullData || request.opcode === AcquirePerm)
  io.schedule.bits.a.bits.source  := UInt(0)
  io.schedule.bits.b.bits.param   := Mux(!s_rprobe, toN, Mux(request.prio(1), request.param, Mux(req_needT, toN, toB)))
  io.schedule.bits.b.bits.tag     := Mux(!s_rprobe, meta.tag, request.tag)
  io.schedule.bits.b.bits.set     := request.set
  io.schedule.bits.b.bits.clients := meta.clients & ~excluded_client
  io.schedule.bits.c.bits.opcode  := Mux(meta.dirty && !meta.outerPreserved, ReleaseData, Release)
  io.schedule.bits.c.bits.param   := Mux(meta.state === BRANCH, BtoN, TtoN)
  io.schedule.bits.c.bits.source  := UInt(0)
  io.schedule.bits.c.bits.tag     := meta.tag
  io.schedule.bits.c.bits.set     := request.set
  io.schedule.bits.c.bits.way     := meta.way
  io.schedule.bits.c.bits.dirty   := meta.dirty && !meta.outerPreserved
  io.schedule.bits.c.bits.dcache  := meta.dcache
  io.schedule.bits.c.bits.packetSeq := meta.packetSeq
  io.schedule.bits.c.bits.packetTracked := meta.packetTracked
  io.schedule.bits.c.bits.image := meta.image
  io.schedule.bits.c.bits.txn := releaseGeneration
  io.schedule.bits.c.bits.reason := Mux(request.control, UInt(2), UInt(1))
  io.schedule.bits.d.bits         := request
  io.schedule.bits.d.bits.param   := Mux(!req_acquire, request.param,
                                       MuxLookup(request.param, Wire(request.param), Seq(
                                         NtoB -> Mux(req_promoteT, NtoT, NtoB),
                                         BtoT -> Mux(honour_BtoT,  BtoT, NtoT),
                                         NtoT -> NtoT)))
  io.schedule.bits.d.bits.sink    := UInt(0)
  io.schedule.bits.d.bits.way     := meta.way
  io.schedule.bits.d.bits.bad     := bad_grant
  // C replies echo the protected snapshot; A grants name the resident bytes.
  io.schedule.bits.d.bits.image := Mux(request.prio(2), request.image, final_meta_writeback.image)
  io.schedule.bits.e.bits.sink    := sink
  io.schedule.bits.x.bits.fail    := Bool(false)
  io.schedule.bits.dir.bits.set   := request.set
  io.schedule.bits.dir.bits.way   := meta.way
  io.schedule.bits.dir.bits.data := Wire(new DirectoryEntry(params), init = final_meta_writeback)

  // Coverage of state transitions
  def cacheState(entry: DirectoryEntry, hit: Bool) = {
    val out = Wire(UInt())
    val c = entry.clients.orR
    val d = entry.dirty
    switch (entry.state) {
      is (BRANCH)  { out := Mux(c, S_BRANCH_C.code, S_BRANCH.code) }
      is (TRUNK)   { out := Mux(d, S_TRUNK_CD.code, S_TRUNK_C.code) }
      is (TIP)     { out := Mux(c, Mux(d, S_TIP_CD.code, S_TIP_C.code), Mux(d, S_TIP_D.code, S_TIP.code)) }
      is (INVALID) { out := S_INVALID.code }
    }
    when (!hit) { out := S_INVALID.code }
    out
  }

  val p = !params.lastLevel  // can be probed
  val c = !params.firstLevel // can be acquired
  val m = params.inner.client.clients.exists(!_.supports.probe)   // can be written (or read)
  val r = params.outer.manager.managers.exists(!_.alwaysGrantsT) // read-only devices exist
  val f = params.control     // flush control register exists
  val cfg = (p, c, m, r, f)
  val b = r || p // can reach branch state (via probe downgrade or read-only device)

  // The cache must be used for something or we would not be here
  require(c || m)

  val evict = cacheState(meta, !meta.hit)
  val before = cacheState(meta, meta.hit)
  val after  = cacheState(final_meta_writeback, Bool(true))

  io.flushStatus.active := request_valid && request.control
  io.flushStatus.mshr := UInt(id)
  io.flushStatus.metaValid := meta_valid
  io.flushStatus.hit := meta.hit
  io.flushStatus.state := MuxLookup(before, UInt(15), Seq(
    S_INVALID.code -> UInt(0), S_BRANCH.code -> UInt(1), S_BRANCH_C.code -> UInt(2),
    S_TIP.code -> UInt(3), S_TIP_C.code -> UInt(4), S_TIP_CD.code -> UInt(5),
    S_TIP_D.code -> UInt(6), S_TRUNK_C.code -> UInt(7), S_TRUNK_CD.code -> UInt(8)))
  io.flushStatus.address := params.restoreAddress(params.expandAddress(request.tag, request.set, request.offset))
  io.flushStatus.set := request.set
  io.flushStatus.way := meta.way
  io.flushStatus.image := meta.image
  io.flushStatus.dirty := meta.dirty
  io.flushStatus.clients := meta.clients
  io.flushStatus.outerPreserved := meta.outerPreserved
  io.flushStatus.probeScheduled := s_rprobe
  io.flushStatus.probeAckFirst := w_rprobeackfirst
  io.flushStatus.probeAckLast := w_rprobeacklast
  io.flushStatus.releaseIssued := releaseIssued
  io.flushStatus.releaseSent := releaseSent
  io.flushStatus.releaseAck := w_releaseack
  io.flushStatus.noWait := no_wait
  io.flushStatus.commitValid := io.schedule.bits.dir.valid
  io.flushStatus.commitReady := io.schedule.bits.dir.valid && io.schedule.fire()

  // Event-only diagnostics for the directed fixture. Production callers keep
  // trace=false; no protocol input, state transition or scheduling gate changes.
  if (trace) {
    val cycle = RegInit(UInt(0, width = 64))
    cycle := cycle + UInt(1)
    if (id == 0) when (cycle === UInt(0)) {
      printf("STAGE3_MSHR event=STATE_CODES INVALID=%x BRANCH=%x BRANCH_C=%x TIP=%x TIP_C=%x TIP_CD=%x TIP_D=%x TRUNK_C=%x TRUNK_CD=%x\n",
        S_INVALID.code, S_BRANCH.code, S_BRANCH_C.code, S_TIP.code, S_TIP_C.code,
        S_TIP_CD.code, S_TIP_D.code, S_TRUNK_C.code, S_TRUNK_CD.code)
    }
    def log(event: String) {
      printf(s"STAGE3_MSHR event=$event cycle=%d bank=%x mshr=%d txn=%x before=%x after=%x control=%x opcode=%x source=%x addr=%x set=%x tag=%x way=%x hit=%x state=%x dirty=%x clients=%x victim_tag=%x image=%x gen=%x seq=%x outer=%x final_state=%x final_dirty=%x final_clients=%x release_issued=%x release_sent=%x release_ack=%x grant_last=%x no_wait=%x reload=%x\n",
        cycle, io.bank, UInt(id), releaseGeneration, before, after, request.control, request.opcode,
        request.source, params.restoreAddress(params.expandAddress(request.tag, request.set, request.offset)),
        request.set, request.tag, meta.way, meta.hit, meta.state, meta.dirty, meta.clients, meta.tag,
        meta.image.valid, meta.image.generation, meta.image.contentSeq, meta.outerPreserved,
        final_meta_writeback.state, final_meta_writeback.dirty, final_meta_writeback.clients,
        releaseIssued, releaseSent, w_releaseack, w_grantlast, no_wait, io.allocate.valid)
    }
    when (io.allocate.valid) {
      printf("STAGE3_MSHR event=ALLOC cycle=%d mshr=%d next_txn=%x repeat=%x control=%x opcode=%x source=%x set=%x tag=%x old_active=%x\n",
        cycle, UInt(id), releaseGeneration + UInt(1), io.allocate.bits.repeat,
        io.allocate.bits.control, io.allocate.bits.opcode, io.allocate.bits.source,
        io.allocate.bits.set, io.allocate.bits.tag, request_valid)
    }
    when (io.directory.valid) {
      printf("STAGE3_MSHR event=LOOKUP cycle=%d mshr=%d next_txn=%x hit=%x state=%x dirty=%x clients=%x victim_tag=%x way=%x\n",
        cycle, UInt(id), releaseGeneration + UInt(1), io.directory.bits.hit, io.directory.bits.state,
        io.directory.bits.dirty, io.directory.bits.clients, io.directory.bits.tag, io.directory.bits.way)
    }
    when (io.schedule.fire()) {
      when (io.schedule.bits.park.valid) { log("CLIENT_PARK") }
      when (io.schedule.bits.b.valid) { log("PROBE_SENT") }
      when (io.schedule.bits.dir.valid) { log("COMMIT") }
      when (io.schedule.bits.c.valid) { log("RELEASE") }
      when (io.schedule.bits.a.valid) { log("ACQUIRE") }
      when (no_wait) { log("FREE_OR_RELOAD") }
    }
    when (io.sinkd.valid && io.sinkd.bits.opcode === ReleaseAck) { log("RELEASE_ACK_INPUT") }
    when (io.releaseSent.valid) { log("RELEASE_SENT") }
    when (io.sinkc.valid) {
      log("PROBE_ACK_INPUT")
      printf("STAGE3_MSHR event=PROBE_ACK_DETAIL cycle=%d mshr=%d source=%x param=%x data=%x last=%x\n",
        cycle, UInt(id), io.sinkc.bits.source, io.sinkc.bits.param, io.sinkc.bits.data, io.sinkc.bits.last)
    }
    when (io.sinkd.valid && (io.sinkd.bits.opcode === Grant || io.sinkd.bits.opcode === GrantData)) {
      when (!w_grantfirst || io.sinkd.bits.last) {
        log("REFILL")
        printf("STAGE3_MSHR event=REFILL_INPUT cycle=%d mshr=%d txn=%x param=%x denied=%x last=%x\n",
          cycle, UInt(id), releaseGeneration, io.sinkd.bits.param, io.sinkd.bits.denied, io.sinkd.bits.last)
      }
    }
    when (io.preserved.valid && meta_valid && request.set === io.preserved.bits.set &&
          meta.way === io.preserved.bits.way && meta.tag === io.preserved.bits.tag &&
          meta.image.asUInt === io.preserved.bits.image.asUInt) { log("PRESERVED") }
  }

  def eviction(from: CacheState, cover: Boolean)(implicit sourceInfo: SourceInfo) {
    if (cover) {
      params.ccover(evict === from.code, s"MSHR_${from}_EVICT", s"State transition from ${from} to evicted ${cfg}")
    } else {
      assert(!(evict === from.code), cf"State transition from ${from} to evicted should be impossible ${cfg}")
    }
    if (cover && f) {
      params.ccover(before === from.code, s"MSHR_${from}_FLUSH", s"State transition from ${from} to flushed ${cfg}")
    } else {
      assert(!(before === from.code), cf"State transition from ${from} to flushed should be impossible ${cfg}")
    }
  }

  def transition(from: CacheState, to: CacheState, cover: Boolean)(implicit sourceInfo: SourceInfo) {
    if (cover) {
      params.ccover(before === from.code && after === to.code, s"MSHR_${from}_${to}", s"State transition from ${from} to ${to} ${cfg}")
    } else {
      assert(!(before === from.code && after === to.code), cf"State transition from ${from} to ${to} should be impossible ${cfg}")
    }
  }

  def flushCommit(from: CacheState, cover: Boolean)(implicit sourceInfo: SourceInfo) {
    if (cover && f) {
      params.ccover(before === from.code && after === S_INVALID.code,
        s"MSHR_${from}_FLUSH_COMMIT", s"Completed flush from ${from} ${cfg}")
    } else {
      assert(!(before === from.code), cf"Flush commit from ${from} should be impossible ${cfg}")
    }
  }

  when ((!s_release && w_rprobeackfirst) && io.schedule.ready) {
    eviction(S_BRANCH,    b)      // MMIO read to read-only device
    eviction(S_BRANCH_C,  b && c) // you need children to become C
    eviction(S_TIP,       true)   // MMIO read || clean release can lead to this state
    eviction(S_TIP_C,     c)      // needs two clients || client + mmio || downgrading client
    eviction(S_TIP_CD,    c)      // needs two clients || client + mmio || downgrading client
    eviction(S_TIP_D,     true)   // MMIO write || dirty release lead here
    eviction(S_TRUNK_C,   c)      // acquire for write
    eviction(S_TRUNK_CD,  c)      // dirty release then reacquire
  }

  // Flush used to invalidate at the eviction schedule, outside the ordinary
  // transition table. Stage3 defers that write until ReleaseAck. Classify the
  // delayed commit as the same control operation, with its own terminal proof.
  // Ordinary A/C transitions below retain every original capability condition.
  when ((!s_writeback && no_wait) && io.schedule.ready && request.control) {
    assert(Bool(f) && request.prio(0), "MSHR flush commit without control capability")
    assert(request_valid && meta_valid && meta.hit && meta.state =/= INVALID,
      "MSHR flush commit without a resident hit")
    assert(releaseIssued && releaseSent && w_releaseack,
      "MSHR flush commit before matching ReleaseAck")
    assert(!io.schedule.bits.a.valid && !io.schedule.bits.d.valid,
      "MSHR flush commit attempted Acquire or inner data response")
    assert(!final_meta_writeback.hit && final_meta_writeback.state === INVALID &&
      !final_meta_writeback.clients.orR && !final_meta_writeback.dirty && !final_meta_writeback.dcache,
      "MSHR flush commit retained permissions or dirty data")
    assert(final_meta_writeback.image.asUInt === UInt(0) && !final_meta_writeback.outerPreserved &&
      final_meta_writeback.packetSeq === UInt(0) && !final_meta_writeback.packetTracked,
      "MSHR flush commit retained old provenance")
    // Retain the eviction/flush capability assertions at the final commit too.
    flushCommit(S_INVALID, false)
    flushCommit(S_BRANCH, b)
    flushCommit(S_BRANCH_C, b && c)
    flushCommit(S_TIP, true)
    flushCommit(S_TIP_C, c)
    flushCommit(S_TIP_CD, c)
    flushCommit(S_TIP_D, true)
    flushCommit(S_TRUNK_C, c)
    flushCommit(S_TRUNK_CD, c)
  }

  when (io.schedule.bits.dir.valid && io.schedule.ready && !request.control) {
    transition(S_INVALID,  S_BRANCH,   b && m) // only MMIO can bring us to BRANCH state
    transition(S_INVALID,  S_BRANCH_C, b && c) // C state is only possible if there are inner caches
    transition(S_INVALID,  S_TIP,      m)      // MMIO read
    transition(S_INVALID,  S_TIP_C,    false)  // we would go S_TRUNK_C instead
    transition(S_INVALID,  S_TIP_CD,   false)  // acquire does not cause dirty immediately
    transition(S_INVALID,  S_TIP_D,    m)      // MMIO write
    transition(S_INVALID,  S_TRUNK_C,  c)      // acquire
    transition(S_INVALID,  S_TRUNK_CD, false)  // acquire does not cause dirty immediately

    transition(S_BRANCH,   S_INVALID,  b && p) // probe can do this (flushes run as evictions)
    transition(S_BRANCH,   S_BRANCH_C, b && c) // acquire
    transition(S_BRANCH,   S_TIP,      b && m) // prefetch write
    transition(S_BRANCH,   S_TIP_C,    false)  // we would go S_TRUNK_C instead
    transition(S_BRANCH,   S_TIP_CD,   false)  // acquire does not cause dirty immediately
    transition(S_BRANCH,   S_TIP_D,    b && m) // MMIO write
    transition(S_BRANCH,   S_TRUNK_C,  b && c) // acquire
    transition(S_BRANCH,   S_TRUNK_CD, false)  // acquire does not cause dirty immediately

    transition(S_BRANCH_C, S_INVALID,  b && c && p)
    transition(S_BRANCH_C, S_BRANCH,   b && c)      // clean release (optional)
    transition(S_BRANCH_C, S_TIP,      b && c && m) // prefetch write
    transition(S_BRANCH_C, S_TIP_C,    false)       // we would go S_TRUNK_C instead
    transition(S_BRANCH_C, S_TIP_D,    b && c && m) // MMIO write
    transition(S_BRANCH_C, S_TIP_CD,   false)       // going dirty means we must shoot down clients
    transition(S_BRANCH_C, S_TRUNK_C,  b && c)      // acquire
    transition(S_BRANCH_C, S_TRUNK_CD, false)       // acquire does not cause dirty immediately

    transition(S_TIP,      S_INVALID,  p)
    transition(S_TIP,      S_BRANCH,   p)      // losing TIP only possible via probe
    transition(S_TIP,      S_BRANCH_C, false)  // we would go S_TRUNK_C instead
    transition(S_TIP,      S_TIP_C,    false)  // we would go S_TRUNK_C instead
    transition(S_TIP,      S_TIP_D,    m)      // direct dirty only via MMIO write
    transition(S_TIP,      S_TIP_CD,   false)  // acquire does not make us dirty immediately
    transition(S_TIP,      S_TRUNK_C,  c)      // acquire
    transition(S_TIP,      S_TRUNK_CD, false)  // acquire does not make us dirty immediately

    transition(S_TIP_C,    S_INVALID,  c && p)
    transition(S_TIP_C,    S_BRANCH,   c && p) // losing TIP only possible via probe
    transition(S_TIP_C,    S_BRANCH_C, c && p) // losing TIP only possible via probe
    transition(S_TIP_C,    S_TIP,      c)      // probed while MMIO read || clean release (optional)
    transition(S_TIP_C,    S_TIP_D,    c && m) // direct dirty only via MMIO write
    transition(S_TIP_C,    S_TIP_CD,   false)  // going dirty means we must shoot down clients
    transition(S_TIP_C,    S_TRUNK_C,  c)      // acquire
    transition(S_TIP_C,    S_TRUNK_CD, false)  // acquire does not make us immediately dirty

    transition(S_TIP_D,    S_INVALID,  p)
    transition(S_TIP_D,    S_BRANCH,   p)      // losing D is only possible via probe
    transition(S_TIP_D,    S_BRANCH_C, p && c) // probed while acquire shared
    transition(S_TIP_D,    S_TIP,      p)      // probed while MMIO read || outer probe.toT (optional)
    transition(S_TIP_D,    S_TIP_C,    false)  // we would go S_TRUNK_C instead
    transition(S_TIP_D,    S_TIP_CD,   false)  // we would go S_TRUNK_CD instead
    transition(S_TIP_D,    S_TRUNK_C,  p && c) // probed while acquired
    transition(S_TIP_D,    S_TRUNK_CD, c)      // acquire

    transition(S_TIP_CD,   S_INVALID,  c && p)
    transition(S_TIP_CD,   S_BRANCH,   c && p) // losing D is only possible via probe
    transition(S_TIP_CD,   S_BRANCH_C, c && p) // losing D is only possible via probe
    transition(S_TIP_CD,   S_TIP,      c && p) // probed while MMIO read || outer probe.toT (optional)
    transition(S_TIP_CD,   S_TIP_C,    false)  // we would go S_TRUNK_C instead
    transition(S_TIP_CD,   S_TIP_D,    c)      // MMIO write || clean release (optional)
    transition(S_TIP_CD,   S_TRUNK_C,  c && p) // probed while acquire
    transition(S_TIP_CD,   S_TRUNK_CD, c)      // acquire

    transition(S_TRUNK_C,  S_INVALID,  c && p)
    transition(S_TRUNK_C,  S_BRANCH,   c && p) // losing TIP only possible via probe
    transition(S_TRUNK_C,  S_BRANCH_C, c && p) // losing TIP only possible via probe
    transition(S_TRUNK_C,  S_TIP,      c)      // MMIO read || clean release (optional)
    transition(S_TRUNK_C,  S_TIP_C,    c)      // bounce shared
    transition(S_TRUNK_C,  S_TIP_D,    c)      // dirty release
    transition(S_TRUNK_C,  S_TIP_CD,   c)      // dirty bounce shared
    transition(S_TRUNK_C,  S_TRUNK_CD, c)      // dirty bounce

    transition(S_TRUNK_CD, S_INVALID,  c && p)
    transition(S_TRUNK_CD, S_BRANCH,   c && p) // losing D only possible via probe
    transition(S_TRUNK_CD, S_BRANCH_C, c && p) // losing D only possible via probe
    transition(S_TRUNK_CD, S_TIP,      c && p) // probed while MMIO read || outer probe.toT (optional)
    transition(S_TRUNK_CD, S_TIP_C,    false)  // we would go S_TRUNK_C instead
    transition(S_TRUNK_CD, S_TIP_D,    c)      // dirty release
    transition(S_TRUNK_CD, S_TIP_CD,   c)      // bounce shared
    transition(S_TRUNK_CD, S_TRUNK_C,  c && p) // probed while acquire
  }

  // Handle response messages
  val probe_bit = params.clientBit(io.sinkc.bits.source)
  val last_probe = (probes_done | probe_bit) === (meta.clients & ~excluded_client)
  val probe_toN = isToN(io.sinkc.bits.param)
  if (!params.firstLevel) when (io.sinkc.valid) {
    params.ccover( probe_toN && io.schedule.bits.b.bits.param === toB, "MSHR_PROBE_FULL", "Client downgraded to N when asked only to do B")
    params.ccover(!probe_toN && io.schedule.bits.b.bits.param === toB, "MSHR_PROBE_HALF", "Client downgraded to B when asked only to do B")
    // Caution: the probe matches us only in set.
    // We would never allow an outer probe to nest until both w_[rp]probeack complete, so
    // it is safe to just unguardedly update the probe FSM.
    probes_done := probes_done | probe_bit
    probes_toN := probes_toN | Mux(probe_toN, probe_bit, UInt(0))
    probes_noT := probes_noT || io.sinkc.bits.param =/= TtoT
    w_rprobeackfirst := w_rprobeackfirst || last_probe
    w_rprobeacklast := w_rprobeacklast || (last_probe && io.sinkc.bits.last)
    w_pprobeackfirst := w_pprobeackfirst || last_probe
    w_pprobeacklast := w_pprobeacklast || (last_probe && io.sinkc.bits.last)
    // Allow wormhole routing from sinkC if the first request beat has offset 0
    val set_pprobeack = last_probe && (io.sinkc.bits.last || request.offset === UInt(0))
    w_pprobeack := w_pprobeack || set_pprobeack
    params.ccover(!set_pprobeack && w_rprobeackfirst, "MSHR_PROBE_SERIAL", "Sequential routing of probe response data")
    params.ccover( set_pprobeack && w_rprobeackfirst, "MSHR_PROBE_WORMHOLE", "Wormhole routing of probe response data")
    // However, meta-data updates need to be done more cautiously
    when (meta.state =/= INVALID && io.sinkc.bits.tag === meta.tag && io.sinkc.bits.data && io.sinkc.bits.last) {
      meta.dirty := Bool(true)
      meta.packetSeq := io.sinkc.bits.packetSeq
      meta.packetTracked := io.sinkc.bits.packetTracked
      meta.image := io.sinkc.bits.image
      meta.outerPreserved := meta.outerPreserved && io.sinkc.bits.image.valid &&
        meta.image.asUInt === io.sinkc.bits.image.asUInt
    }
  }
  when (io.sinkd.valid) {
    when (io.sinkd.bits.opcode === Grant || io.sinkd.bits.opcode === GrantData) {
      sink := io.sinkd.bits.sink
      w_grantfirst := Bool(true)
      w_grantlast := io.sinkd.bits.last
      // Record if we need to prevent taking ownership
      bad_grant := io.sinkd.bits.denied
      // Allow wormhole routing for requests whose first beat has offset 0
      w_grant := request.offset === UInt(0) || io.sinkd.bits.last
      params.ccover(io.sinkd.bits.opcode === GrantData && request.offset === UInt(0), "MSHR_GRANT_WORMHOLE", "Wormhole routing of grant response data")
      params.ccover(io.sinkd.bits.opcode === GrantData && request.offset =/= UInt(0), "MSHR_GRANT_SERIAL", "Sequential routing of grant response data")
      gotT := io.sinkd.bits.param === toT
    }
    .elsewhen (io.sinkd.bits.opcode === ReleaseAck) {
      val matching = request_valid && releaseIssued && !w_releaseack && s_release &&
        (releaseSent || (io.releaseSent.valid && io.releaseSent.bits === releaseGeneration)) &&
        io.sinkd.bits.txn === releaseGeneration
      when (matching) {
        assert(!io.sinkd.bits.denied, "L2 victim preservation outer failure")
        when (!io.sinkd.bits.denied) {
          w_releaseack := Bool(true)
          printf("STAGE3_TX L2_VICTIM_ACK bank=%x txn=%x source=%x set=%x way=%x tag=%x valid=%x writer=%x gen=%x seq=%x reason=%x\n",
            io.bank, releaseGeneration, io.sinkd.bits.source, request.set, meta.way, meta.tag, meta.image.valid,
            meta.image.writer, meta.image.generation, meta.image.contentSeq, Mux(request.control, UInt(2), UInt(1)))
        }
      }.otherwise {
        printf("STAGE3_TX L2_STALE_ACK_ERROR bank=%x txn=%x current=%x ignored=1 victim=1\n",
          io.bank, io.sinkd.bits.txn, releaseGeneration)
      }
    }
  }
  when (io.releaseSent.valid) {
    assert(releaseIssued && io.releaseSent.bits === releaseGeneration && !releaseSent,
      "L2_DUP_PRESERVE_ERROR victim")
    releaseSent := Bool(true)
  }
  when (io.schedule.fire()) {
    assert(!io.schedule.bits.a.valid || w_releaseack, "L2_PREMATURE_OVERWRITE_ERROR acquire")
    assert(!io.schedule.bits.dir.valid || w_releaseack, "L2_PREMATURE_OVERWRITE_ERROR victim tag")
    when (io.schedule.bits.c.valid) {
      assert(!releaseIssued, "L2_DUP_PRESERVE_ERROR victim request")
      releaseIssued := Bool(true)
      releaseSnapshot := meta
    }
  }
  when (releaseIssued && !w_releaseack) {
    assert(meta.asUInt === releaseSnapshot.asUInt, "L2 pending victim identity changed")
  }
  when (io.preserved.valid && meta_valid && request.set === io.preserved.bits.set &&
        meta.way === io.preserved.bits.way && meta.tag === io.preserved.bits.tag &&
        meta.image.asUInt === io.preserved.bits.image.asUInt) {
    // Scheduler freezes every mutating entry in this set on the ACK cycle.
    assert(!io.directory.valid && !(io.allocate.valid && io.allocate.bits.repeat) &&
      !(io.sinkc.valid && io.sinkc.bits.data) &&
      !(io.nestedwb.c_set_packet && io.nestedwb.set === request.set && io.nestedwb.tag === meta.tag),
      "L2 receipt raced a resident mutation")
    meta.outerPreserved := Bool(true)
  }
  when (io.sinke.valid) {
    w_grantack := Bool(true)
  }

  // Bootstrap new requests
  val allocate_as_full = Wire(new FullRequest(params), init = io.allocate.bits)
  val new_meta = Mux(io.allocate.valid && io.allocate.bits.repeat, final_meta_writeback, io.directory.bits)
  val new_request = Mux(io.allocate.valid, allocate_as_full, request)
  val new_needT = needT(new_request.opcode, new_request.param)
  val new_clientBit = params.clientBit(new_request.source)
  val new_skipProbe = Mux(skipProbeN(new_request.opcode, params.cache.hintsSkipProbe), new_clientBit, UInt(0))

  val prior = cacheState(final_meta_writeback, Bool(true))
  def bypass(from: CacheState, cover: Boolean)(implicit sourceInfo: SourceInfo) {
    if (cover) {
      params.ccover(prior === from.code, s"MSHR_${from}_BYPASS", s"State bypass transition from ${from} ${cfg}")
    } else {
      assert(!(prior === from.code), cf"State bypass from ${from} should be impossible ${cfg}")
    }
  }

  when (io.allocate.valid && io.allocate.bits.repeat) {
    bypass(S_INVALID,   f || p) // Can lose permissions (probe/flush)
    bypass(S_BRANCH,    b)      // MMIO read to read-only device
    bypass(S_BRANCH_C,  b && c) // you need children to become C
    bypass(S_TIP,       true)   // MMIO read || clean release can lead to this state
    bypass(S_TIP_C,     c)      // needs two clients || client + mmio || downgrading client
    bypass(S_TIP_CD,    c)      // needs two clients || client + mmio || downgrading client
    bypass(S_TIP_D,     true)   // MMIO write || dirty release lead here
    bypass(S_TRUNK_C,   c)      // acquire for write
    bypass(S_TRUNK_CD,  c)      // dirty release then reacquire
  }

  when (io.allocate.valid) {
    assert (!request_valid || (((no_wait && !peerUnsafe) || parkPeer) && io.schedule.fire()))
    request_valid := Bool(true)
    request := io.allocate.bits
  }

  // Create execution plan
  when (io.directory.valid || (io.allocate.valid && io.allocate.bits.repeat)) {
    assert(!releaseGeneration.andR, "L2 release serial exhausted")
    releaseGeneration := releaseGeneration + UInt(1)
    releaseSent := Bool(false)
    releaseIssued := Bool(false)
    meta_valid := Bool(true)
    planStarted := Bool(false)
    meta := new_meta
    probes_done := UInt(0)
    probes_toN := UInt(0)
    probes_noT := Bool(false)
    gotT := Bool(false)
    bad_grant := Bool(false)

    // These should already be either true or turning true
    // We clear them here explicitly to simplify the mux tree
    s_rprobe         := Bool(true)
    w_rprobeackfirst := Bool(true)
    w_rprobeacklast  := Bool(true)
    s_release        := Bool(true)
    w_releaseack     := Bool(true)
    s_pprobe         := Bool(true)
    s_acquire        := Bool(true)
    s_flush          := Bool(true)
    w_grantfirst     := Bool(true)
    w_grantlast      := Bool(true)
    w_grant          := Bool(true)
    w_pprobeackfirst := Bool(true)
    w_pprobeacklast  := Bool(true)
    w_pprobeack      := Bool(true)
    s_probeack       := Bool(true)
    s_grantack       := Bool(true)
    s_execute        := Bool(true)
    w_grantack       := Bool(true)
    s_writeback      := Bool(true)

    // For C channel requests (ie: Release[Data])
    when (new_request.prio(2) && Bool(!params.firstLevel)) {
      s_execute := Bool(false)
      // Every data release publishes its exact image, even if dirty/client
      // state is unchanged (for example a nested release after a probe).
      when (new_request.opcode(0)) {
        s_writeback := Bool(false)
      }
      // Does our state change?
      when (isToB(new_request.param) && new_meta.state === TRUNK) {
        s_writeback := Bool(false)
      }
      // Do our clients change?
      when (isToN(new_request.param) && (new_meta.clients & new_clientBit) =/= UInt(0)) {
        s_writeback := Bool(false)
      }
      assert (new_meta.hit)
    }
    // For X channel requests (ie: flush)
    .elsewhen (new_request.control && Bool(params.control)) { // new_request.prio(0)
      s_flush := Bool(false)
      // Do we need to actually do something?
      when (new_meta.hit) {
        s_writeback := Bool(false)
        s_release := Bool(false)
        w_releaseack := Bool(false)
        // Do we need to shoot-down inner caches?
        when (Bool(!params.firstLevel) && (new_meta.clients =/= UInt(0))) {
          s_rprobe := Bool(false)
          w_rprobeackfirst := Bool(false)
          w_rprobeacklast := Bool(false)
        }
      }
    }
    // For A channel requests
    .otherwise { // new_request.prio(0) && !new_request.control
      s_execute := Bool(false)
      // Do we need an eviction?
      when (!new_meta.hit && new_meta.state =/= INVALID) {
        s_release := Bool(false)
        w_releaseack := Bool(false)
        // Do we need to shoot-down inner caches?
        when (Bool(!params.firstLevel) & (new_meta.clients =/= UInt(0))) {
          s_rprobe := Bool(false)
          w_rprobeackfirst := Bool(false)
          w_rprobeacklast := Bool(false)
        }
      }
      // Do we need an acquire?
      when (!new_meta.hit || (new_meta.state === BRANCH && new_needT)) {
        s_acquire := Bool(false)
        w_grantfirst := Bool(false)
        w_grantlast := Bool(false)
        w_grant := Bool(false)
        s_grantack := Bool(false)
        s_writeback := Bool(false)
      }
      // Do we need a probe?
      when (Bool(!params.firstLevel) && (new_meta.hit &&
            (new_needT || new_meta.state === TRUNK) &&
            (new_meta.clients & ~new_skipProbe) =/= UInt(0))) {
        s_pprobe := Bool(false)
        w_pprobeackfirst := Bool(false)
        w_pprobeacklast := Bool(false)
        w_pprobeack := Bool(false)
        s_writeback := Bool(false)
      }
      // Do we need a grantack?
      when (new_request.opcode === AcquireBlock || new_request.opcode === AcquirePerm) {
        w_grantack := Bool(false)
        s_writeback := Bool(false)
      }
      // Every trusted byte update revokes the old exact-image receipt and
      // publishes BASE, even when the resident was already dirty. Dirty-state
      // equality alone does not imply that the content identity is unchanged.
      when (!new_request.opcode(2)) {
        s_writeback := Bool(false)
      }
    }
  }
}
