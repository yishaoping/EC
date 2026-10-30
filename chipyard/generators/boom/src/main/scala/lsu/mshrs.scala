//******************************************************************************
// Ported from Rocket-Chip
// See LICENSE.Berkeley and LICENSE.SiFive in Rocket-Chip for license details.
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

package boom.lsu

import chisel3._
import chisel3.util._

import org.chipsalliance.cde.config.Parameters
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.tilelink._
import freechips.rocketchip.tile._
import freechips.rocketchip.util._
import freechips.rocketchip.rocket._

import boom.common._
import boom.exu.BrUpdateInfo
import boom.util.{IsKilledByBranch, GetNewBrMask, BranchKillableQueue, IsOlder, UpdateBrMask, AgePriorityEncoder, WrapInc}

class BoomDCacheReqInternal(implicit p: Parameters) extends BoomDCacheReq()(p)
  with HasL1HellaCacheParameters
{
  // miss info
  val tag_match = Bool()
  val old_meta  = new L1Metadata
  val way_en    = UInt(nWays.W)

  // Used in the MSHRs
}


class BoomMSHR(implicit edge: TLEdgeOut, p: Parameters) extends BoomModule()(p)
  with HasL1HellaCacheParameters
{
  val io = IO(new Bundle {
    val id = Input(UInt())

    val req_pri_val = Input(Bool())
    val req_pri_rdy = Output(Bool())
    val req_sec_val = Input(Bool())
    val req_sec_rdy = Output(Bool())

    val clear_prefetch = Input(Bool())
    val brupdate       = Input(new BrUpdateInfo)
    val exception    = Input(Bool())
    val rob_pnr_idx  = Input(UInt(robAddrSz.W))
    val rob_head_idx = Input(UInt(robAddrSz.W))

    val req          = Input(new BoomDCacheReqInternal)
    val req_is_probe = Input(Bool())

    val idx = Output(Valid(UInt()))
    val way = Output(Valid(UInt()))
    val tag = Output(Valid(UInt()))
    val debug_state = Output(UInt(5.W))
    val debug_waiting_resource = Output(UInt(4.W))


    val mem_acquire = Decoupled(new TLBundleA(edge.bundle))

    val mem_grant   = Flipped(Decoupled(new TLBundleD(edge.bundle)))
    val mem_finish  = Decoupled(new TLBundleE(edge.bundle))

    val prober_state = Input(Valid(UInt(coreMaxAddrBits.W)))

    val refill      = Decoupled(new BoomCacheRefill)

    val meta_write  = Decoupled(new L1MetaWriteReq)
    val meta_read   = Decoupled(new L1MetaReadReq)
    val meta_resp   = Input(Valid(new L1Metadata))
    val wb_req      = Decoupled(new WritebackReq(edge.bundle))

    // To inform the prefetcher when we are commiting the fetch of this line
    val commit_val  = Output(Bool())
    val commit_addr = Output(UInt(coreMaxAddrBits.W))
    val commit_coh  = Output(new ClientMetadata)

    // Reading from the line buffer
    val lb_read       = Decoupled(new LineBufferReadReq)
    val lb_resp       = Input(UInt(encRowBits.W))
    val lb_write      = Decoupled(new LineBufferWriteReq)

    // Replays go through the cache pipeline again
    val replay      = Decoupled(new BoomDCacheReqInternal)
    // Legacy observation ports; tagged replay_result is the lifecycle authority.
    val replay_effect_done = Input(Bool())
    val replay_cancel = Input(Bool())
    val replay_result = Flipped(Decoupled(new BoomCacheCompletion))
    val replay_grant = Input(Valid(new BoomDCacheReq))
    val retired = Output(Valid(new BoomDCacheReqInternal))
    val install = Decoupled(new BoomCacheInstall)
    val install_fault = Input(Bool())
    val refill_fault = Input(Bool())
    val owner = Output(new BoomDCacheReqInternal)
    val next_transaction_token = Output(UInt(32.W))
    val write_domain_valid = Output(Bool())
    val write_domain_seq = Output(UInt(freechips.rocketchip.guardiancouncil.GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
    // Resp go straight out to the core
    val resp        = Decoupled(new BoomDCacheResp)

    // Writeback unit tells us when it is done processing our wb
    val wb_resp     = Input(Bool())

    val probe_rdy   = Output(Bool())
  })

  // TODO: Optimize this. We don't want to mess with cache during speculation
  // s_refill_req      : Make a request for a new cache line
  // s_refill_resp     : Store the refill response into our buffer
  // s_drain_rpq_loads : Drain out loads from the rpq
  //                   : If miss was misspeculated, go to s_invalid
  // s_wb_req          : Write back the evicted cache line
  // s_wb_resp         : Finish writing back the evicted cache line
  // s_meta_write_req  : Write the metadata for new cache lne
  // s_meta_write_resp :

  val s_invalid :: s_refill_req :: s_refill_resp :: s_drain_rpq_loads :: s_meta_read :: s_meta_resp_1 :: s_meta_resp_2 :: s_meta_clear :: s_wb_meta_read :: s_wb_req :: s_wb_resp :: s_commit_line :: s_drain_rpq :: s_meta_write_req :: s_mem_finish_1 :: s_mem_finish_2 :: s_prefetched :: s_prefetch :: Nil = Enum(18)
  val state = RegInit(s_invalid)
  io.debug_state := state
  val debugWaitingResource = WireDefault(0.U(4.W))
  when (state === s_refill_req)       { debugWaitingResource := 1.U }
  when (state === s_refill_resp)      { debugWaitingResource := 2.U }
  when (state === s_drain_rpq_loads)  { debugWaitingResource := 3.U }
  when (state === s_meta_read || state === s_wb_meta_read) { debugWaitingResource := 4.U }
  when (state === s_meta_resp_1 || state === s_meta_resp_2) { debugWaitingResource := 5.U }
  when (state === s_meta_clear || state === s_meta_write_req) { debugWaitingResource := 6.U }
  when (state === s_wb_req)           { debugWaitingResource := 7.U }
  when (state === s_wb_resp)          { debugWaitingResource := 8.U }
  when (state === s_commit_line)      { debugWaitingResource := 9.U }
  when (state === s_drain_rpq)        { debugWaitingResource := 10.U }
  when (state === s_mem_finish_1 || state === s_mem_finish_2) { debugWaitingResource := 11.U }
  when (state === s_prefetch || state === s_prefetched) { debugWaitingResource := 12.U }
  io.debug_waiting_resource := debugWaitingResource

  val req     = Reg(new BoomDCacheReqInternal)
  val transactionSerial = RegInit(0.U(32.W))
  val writeDomainValid = RegInit(false.B)
  val writeDomainSeq = Reg(UInt(freechips.rocketchip.guardiancouncil.GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
  val refillImage = Reg(new CacheImageKey)
  val grantFirst = RegInit(true.B)
  val installStarted = RegInit(false.B)
  val protocolFault = RegInit(false.B)
  // Holds one row only after the install owner has accepted the row read.
  // Ordinary RPQ loads use the same LineBuffer port but must not update it.
  val rowValid = RegInit(false.B)
  val rowData = Reg(UInt(encRowBits.W))
  io.owner := req
  io.next_transaction_token := transactionSerial + 1.U
  io.write_domain_valid := writeDomainValid
  io.write_domain_seq := writeDomainSeq
  io.install.valid := false.B
  io.install.bits.req := req
  io.install.bits.new_owner := !req.tag_match
  io.install.bits.image := refillImage
  io.retired.valid := false.B
  io.retired.bits := req
  val req_idx = req.addr(untagBits-1, blockOffBits)
  val req_tag = req.addr >> untagBits
  val req_block_addr = (req.addr >> blockOffBits) << blockOffBits
  val req_needs_wb = RegInit(false.B)

  val new_coh = RegInit(ClientMetadata.onReset)
  val (_, shrink_param, coh_on_clear) = req.old_meta.coh.onCacheControl(M_FLUSH)
  val grow_param = new_coh.onAccess(req.uop.mem_cmd)._2
  val coh_on_grant = new_coh.onGrant(req.uop.mem_cmd, io.mem_grant.bits.param)

  // We only accept secondary misses if the original request had sufficient permissions
  val (cmd_requires_second_acquire, is_hit_again, _, dirtier_coh, dirtier_cmd) =
    new_coh.onSecondaryAccess(req.uop.mem_cmd, io.req.uop.mem_cmd)

  val (_, _, refill_done, refill_address_inc) = edge.addr_inc(io.mem_grant)
  val cross_package_secondary_write = isWrite(io.req.uop.mem_cmd) && io.req.write_domain_valid &&
    writeDomainValid && io.req.write_domain_seq =/= writeDomainSeq
  // SLOWDOWN_TRACE_BEGIN: observation-only; no functional consumers.
  val slowdown_mshr_state = chisel3.WireInit(state)
  chisel3.dontTouch(slowdown_mshr_state)
  val slowdown_mshr_id = chisel3.WireInit(io.id)
  chisel3.dontTouch(slowdown_mshr_id)
  val slowdown_mshr_addr = chisel3.WireInit(req.addr)
  chisel3.dontTouch(slowdown_mshr_addr)
  val slowdown_mshr_set = chisel3.WireInit(req_idx)
  chisel3.dontTouch(slowdown_mshr_set)
  val slowdown_mshr_tag = chisel3.WireInit(req_tag)
  chisel3.dontTouch(slowdown_mshr_tag)
  val slowdown_mshr_rob_idx = chisel3.WireInit(req.uop.rob_idx)
  chisel3.dontTouch(slowdown_mshr_rob_idx)
  val slowdown_mshr_token = chisel3.WireInit(req.request_token)
  chisel3.dontTouch(slowdown_mshr_token)
  val slowdown_mshr_transaction = chisel3.WireInit(req.transaction_token)
  chisel3.dontTouch(slowdown_mshr_transaction)
  val slowdown_mshr_packet_seq = chisel3.WireInit(req.packet_seq)
  chisel3.dontTouch(slowdown_mshr_packet_seq)
  val slowdown_mshr_pri_valid = chisel3.WireInit(io.req_pri_val)
  chisel3.dontTouch(slowdown_mshr_pri_valid)
  val slowdown_mshr_pri_ready = chisel3.WireInit(io.req_pri_rdy)
  chisel3.dontTouch(slowdown_mshr_pri_ready)
  val slowdown_mshr_sec_valid = chisel3.WireInit(io.req_sec_val)
  chisel3.dontTouch(slowdown_mshr_sec_valid)
  val slowdown_mshr_sec_ready = chisel3.WireInit(io.req_sec_rdy)
  chisel3.dontTouch(slowdown_mshr_sec_ready)
  val slowdown_mshr_cross_package_secondary = chisel3.WireInit(cross_package_secondary_write)
  chisel3.dontTouch(slowdown_mshr_cross_package_secondary)
  val slowdown_mshr_replay_valid = chisel3.WireInit(io.replay.valid)
  chisel3.dontTouch(slowdown_mshr_replay_valid)
  val slowdown_mshr_replay_ready = chisel3.WireInit(io.replay.ready)
  chisel3.dontTouch(slowdown_mshr_replay_ready)
  val slowdown_mshr_retired = chisel3.WireInit(io.retired.valid)
  chisel3.dontTouch(slowdown_mshr_retired)
  val slowdown_mshr_grant_valid = chisel3.WireInit(io.mem_grant.valid)
  chisel3.dontTouch(slowdown_mshr_grant_valid)
  val slowdown_mshr_grant_ready = chisel3.WireInit(io.mem_grant.ready)
  chisel3.dontTouch(slowdown_mshr_grant_ready)
  val slowdown_mshr_wb_valid = chisel3.WireInit(io.wb_req.valid)
  chisel3.dontTouch(slowdown_mshr_wb_valid)
  val slowdown_mshr_wb_ready = chisel3.WireInit(io.wb_req.ready)
  chisel3.dontTouch(slowdown_mshr_wb_ready)
  // SLOWDOWN_TRACE_END
  // Both drain phases must finish a finite set of already-owned requests.
  // New secondaries retry instead of extending the active drain.
  val drainAdmissionClosed = state.isOneOf(s_drain_rpq, s_drain_rpq_loads)
  val sec_rdy = (!cmd_requires_second_acquire && !io.req_is_probe &&
                 !cross_package_secondary_write && !protocolFault &&
                 !drainAdmissionClosed &&
                 !state.isOneOf(s_invalid, s_meta_write_req, s_mem_finish_1, s_mem_finish_2))

  val rpq = Module(new BranchKillableQueue(new BoomDCacheReqInternal, cfg.nRPQ,
    u => u.uses_ldq, false, holdable = true))
  rpq.io.brupdate := io.brupdate
  rpq.io.flush  := io.exception
  assert(!(state === s_invalid && !rpq.io.empty))

  rpq.io.enq.valid := ((io.req_pri_val && io.req_pri_rdy) || (io.req_sec_val && io.req_sec_rdy)) && !isPrefetch(io.req.uop.mem_cmd)
  rpq.io.enq.bits  := io.req
  rpq.io.deq.ready := false.B
  when (drainAdmissionClosed) {
    assert(!(io.req_sec_val && io.req_sec_rdy), "secondary accepted during RPQ drain")
    // RPQ has only primary/secondary producers; replay RETRY holds its head.
    assert(!rpq.io.enq.fire, "RPQ enqueue during closed drain")
  }
  val replay_inflight = RegInit(false.B)
  val inflight = Reg(new BoomDCacheReqInternal)
  val inflightGrantValid = RegInit(false.B)
  when (io.replay_grant.valid) {
    assert(replay_inflight && io.replay_grant.bits.request_token === inflight.request_token &&
      io.replay_grant.bits.transaction_token === inflight.transaction_token,
      "write grant does not match issued RPQ owner")
    inflight.line_generation := io.replay_grant.bits.line_generation
    inflight.image_valid := io.replay_grant.bits.image_valid
    inflightGrantValid := true.B
  }
  val resultMatches = replay_inflight &&
    io.replay_result.bits.req.replay_mshr_id === io.id &&
    io.replay_result.bits.req.transaction_token === inflight.transaction_token &&
    io.replay_result.bits.req.request_token_valid === inflight.request_token_valid &&
    io.replay_result.bits.req.request_token === inflight.request_token &&
    io.replay_result.bits.req.slot_epoch === inflight.slot_epoch &&
    io.replay_result.bits.req.sdq_id === inflight.sdq_id &&
    io.replay_result.bits.req.owner_way === inflight.owner_way &&
    io.replay_result.bits.req.effect_token_valid === inflight.effect_token_valid &&
    io.replay_result.bits.req.effect_token === inflight.effect_token &&
    (!inflightGrantValid ||
      (io.replay_result.bits.req.line_generation === inflight.line_generation &&
       io.replay_result.bits.req.image_valid === inflight.image_valid))
  io.replay_result.ready := resultMatches
  when (io.replay_result.valid) {
    assert(resultMatches, "stale replay completion / MSHR allocation reuse")
  }
  val replayTerminal = io.replay_result.fire &&
    io.replay_result.bits.status =/= CacheTerminal.retry
  rpq.io.hold_head.get := replay_inflight && !replayTerminal
  when (io.replay_result.fire) { replay_inflight := false.B }
  when (replayTerminal) {
    io.retired.valid := true.B
    io.retired.bits := inflight
  }
  when (rpq.io.discarded.get.valid && !replay_inflight) {
    io.retired.valid := true.B // legitimate pre-issue CANCEL
    io.retired.bits := rpq.io.discarded.get.bits
  }
  when (io.install_fault || io.refill_fault) { protocolFault := true.B }
  assert(!io.install_fault, "refill destination owner mismatch")
  assert(!io.refill_fault, "active refill owner mismatch")


  val grantack = RegInit(0.U.asTypeOf(Valid(new TLBundleE(edge.bundle))))
  val refill_ctr  = Reg(UInt(log2Ceil(cacheDataBeats).W))
  val commit_line = Reg(Bool())
  val grant_had_data = Reg(Bool())
  io.install.bits.has_data := grant_had_data
  val finish_to_prefetch = Reg(Bool())

  // Block probes if a tag write we started is still in the pipeline
  val meta_hazard = RegInit(0.U(2.W))
  when (meta_hazard =/= 0.U) { meta_hazard := meta_hazard + 1.U }
  when (io.meta_write.fire) { meta_hazard := 1.U }
  // Before E, the old resident can still answer probes. After full Grant
  // capture, this MSHR retains the new permission/image until final publish.
  // A probe is parked in BoomProbeUnit while the bounded local drain runs.
  io.probe_rdy := meta_hazard === 0.U &&
    state.isOneOf(s_invalid, s_refill_req, s_refill_resp)
  io.idx.valid := state =/= s_invalid
  io.tag.valid := state =/= s_invalid
  io.way.valid := !state.isOneOf(s_invalid, s_prefetch)
  io.idx.bits := req_idx
  io.tag.bits := req_tag
  io.way.bits := req.way_en

  io.meta_write.valid    := false.B
  io.meta_write.bits     := 0.U.asTypeOf(new L1MetaWriteReq)
  io.req_pri_rdy         := false.B
  io.req_sec_rdy         := sec_rdy && rpq.io.enq.ready
  io.mem_acquire.valid   := false.B
  io.mem_acquire.bits    := 0.U.asTypeOf(new TLBundleA(edge.bundle))
  io.mem_grant.ready     := false.B
  io.refill.valid        := false.B
  io.refill.bits         := 0.U.asTypeOf(new BoomCacheRefill)
  io.replay.valid        := false.B
  io.replay.bits         := 0.U.asTypeOf(new BoomDCacheReqInternal)
  io.wb_req.valid        := false.B
  io.wb_req.bits         := 0.U.asTypeOf(new WritebackReq(edge.bundle))
  io.resp.valid          := false.B
  io.resp.bits := 0.U.asTypeOf(new BoomDCacheResp)
  io.commit_val          := false.B
  io.commit_addr         := req.addr
  io.commit_coh          := coh_on_grant
  io.meta_read.valid     := false.B
  io.meta_read.bits      := 0.U.asTypeOf(new L1MetaReadReq)
  // Full Grant capture owns the E responsibility independently of replay.
  io.mem_finish.valid    := grantack.valid
  io.mem_finish.bits     := grantack.bits
  when (io.mem_finish.fire) { grantack.valid := false.B }
  io.lb_write.valid      := false.B
  io.lb_write.bits       := 0.U.asTypeOf(new LineBufferWriteReq)
  io.lb_read.valid       := false.B
  io.lb_read.bits        := 0.U.asTypeOf(new LineBufferReadReq)

  // Keep the RPQ head and its SDQ payload live from issue through the actual
  // data-array effect.  A retry leaves the head in place and only clears the
  // in-flight marker.
  // The legacy bool ports are deliberately not lifecycle authorities.
  // Only a matching, acknowledged result can end an issued attempt.

  when (io.req_sec_val && io.req_sec_rdy) {
    assert(io.req.owner_context_valid && io.req.transaction_token === req.transaction_token &&
      io.req.slot_epoch === req.slot_epoch && io.req.owner_way === req.owner_way,
      "secondary did not inherit its MSHR owner")
    req.uop.mem_cmd := dirtier_cmd
    when (is_hit_again) {
      new_coh := dirtier_coh
    }
    when (isWrite(io.req.uop.mem_cmd) && io.req.write_domain_valid && !writeDomainValid) {
      writeDomainValid := true.B
      writeDomainSeq := io.req.write_domain_seq
    }
  }

  def handle_pri_req(old_state: UInt): UInt = {
    val new_state = WireInit(old_state)
    grantack.valid := false.B
    refill_ctr := 0.U
    assert(rpq.io.enq.ready)
    req := io.req
    assert(io.req.owner_context_valid && io.req.way_en.orR &&
      io.req.owner_way === io.req.way_en, "primary lacks destination owner context")
    assert(io.req.write_domain_valid === isWrite(io.req.uop.mem_cmd),
      "primary write domain must describe its own request")
    transactionSerial := io.req.transaction_token
    assert(io.req.transaction_token =/= 0.U, "MSHR transaction token exhausted")
    installStarted := false.B
    rowValid := false.B
    protocolFault := false.B
    grantFirst := true.B
    writeDomainValid := io.req.write_domain_valid
    writeDomainSeq := io.req.write_domain_seq
    val old_coh   = io.req.old_meta.coh
    req_needs_wb := old_coh.onCacheControl(M_FLUSH)._1 // does the line we are evicting need to be written back
    when (io.req.tag_match) {
      val (is_hit, _, coh_on_hit) = old_coh.onAccess(io.req.uop.mem_cmd)
      when (is_hit) { // set dirty bit
        assert(isWrite(io.req.uop.mem_cmd))
        new_coh     := coh_on_hit
        new_state   := s_drain_rpq
      } .otherwise { // upgrade permissions
        new_coh     := old_coh
        new_state   := s_refill_req
      }
    } .otherwise { // refill and writeback if necessary
      new_coh     := ClientMetadata.onReset
      new_state   := s_refill_req
    }
    new_state
  }

  when (state === s_invalid) {
    io.req_pri_rdy := true.B
    grant_had_data := false.B

    when (io.req_pri_val && io.req_pri_rdy) {
      state := handle_pri_req(state)
    }
  } .elsewhen (state === s_refill_req) {
    io.mem_acquire.valid := true.B
    // TODO: Use AcquirePerm if just doing permissions acquire
    io.mem_acquire.bits  := CacheImage.base(edge.AcquireBlock(
      fromSource      = io.id,
      toAddress       = Cat(req_tag, req_idx) << blockOffBits,
      lgSize          = lgCacheBlockBytes.U,
      growPermissions = grow_param)._2)
    when (io.mem_acquire.fire) {
      state := s_refill_resp
    }
  } .elsewhen (state === s_refill_resp) {
    when (edge.hasData(io.mem_grant.bits)) {
      io.mem_grant.ready      := io.lb_write.ready
      io.lb_write.valid       := io.mem_grant.valid
      io.lb_write.bits.id     := io.id
      io.lb_write.bits.offset := refill_address_inc >> rowOffBits
      io.lb_write.bits.data   := io.mem_grant.bits.data
    } .otherwise {
      io.mem_grant.ready      := true.B
    }

    when (io.mem_grant.fire) {
      val incomingImage = io.mem_grant.bits.user.lift(CacheImage).getOrElse(0.U.asTypeOf(new CacheImageKey))
      assert(incomingImage.valid || incomingImage.asUInt === 0.U, "malformed BASE image")
      assert(!incomingImage.valid || incomingImage.generation =/= 0.U, "authored image has no generation")
      when (grantFirst) { refillImage := incomingImage }
      .otherwise { assert(incomingImage.asUInt === refillImage.asUInt, "GrantData image changed between beats") }
      grantFirst := false.B
      grant_had_data := edge.hasData(io.mem_grant.bits)
      assert(!io.mem_grant.bits.denied && !io.mem_grant.bits.corrupt, "cannot certify a denied/corrupt refill")
    }
    when (refill_done) {
      grantack.valid := edge.isRequest(io.mem_grant.bits)
      grantack.bits := edge.GrantAck(io.mem_grant.bits)
      state := Mux(edge.hasData(io.mem_grant.bits), s_drain_rpq_loads, s_commit_line)
      assert(edge.hasData(io.mem_grant.bits) || req.tag_match,
        "new-line allocation requires complete GrantData")
      assert(edge.hasData(io.mem_grant.bits) || !req_needs_wb)
      commit_line := false.B
      new_coh := coh_on_grant

    }
  } .elsewhen (state === s_drain_rpq_loads) {
    val drain_load = (isRead(rpq.io.deq.bits.uop.mem_cmd) &&
                     !isWrite(rpq.io.deq.bits.uop.mem_cmd) &&
                     (rpq.io.deq.bits.uop.mem_cmd =/= M_XLR)) // LR should go through replay
    // drain all loads for now
    val rp_addr = Cat(req_tag, req_idx, rpq.io.deq.bits.addr(blockOffBits-1,0))
    val word_idx  = if (rowWords == 1) 0.U else rp_addr(log2Up(rowWords*coreDataBytes)-1, log2Up(wordBytes))
    val data      = io.lb_resp
    val data_word = data >> Cat(word_idx, 0.U(log2Up(coreDataBits).W))
    val loadgen = new LoadGen(rpq.io.deq.bits.uop.mem_size, rpq.io.deq.bits.uop.mem_signed,
      Cat(req_tag, req_idx, rpq.io.deq.bits.addr(blockOffBits-1,0)),
      data_word, false.B, wordBytes)


    rpq.io.deq.ready       := io.resp.ready && io.lb_read.ready && drain_load
    io.lb_read.valid       := rpq.io.deq.valid && drain_load
    io.lb_read.bits.id     := io.id
    io.lb_read.bits.offset := rpq.io.deq.bits.addr >> rowOffBits

    io.resp.valid     := rpq.io.deq.valid && io.lb_read.fire && drain_load
    io.resp.bits.uop  := rpq.io.deq.bits.uop
    io.resp.bits.data := loadgen.data
    io.resp.bits.is_hella := rpq.io.deq.bits.is_hella
    io.resp.bits.traffic_check := rpq.io.deq.bits.traffic_check
    io.resp.bits.traffic_seen  := rpq.io.deq.bits.traffic_seen
    io.resp.bits.traffic_cacheable := rpq.io.deq.bits.traffic_cacheable
    io.resp.bits.request_token_valid := rpq.io.deq.bits.request_token_valid
    io.resp.bits.request_token := rpq.io.deq.bits.request_token
    when (rpq.io.deq.fire) {
      io.retired.valid := true.B
      io.retired.bits := rpq.io.deq.bits
      commit_line   := true.B
    }
      .elsewhen (rpq.io.empty && !commit_line)
    {
      when (!rpq.io.enq.fire) {
        // Even a killed primary must retire its destination reservation.
        // Install the captured line before releasing this transaction.
        state := s_meta_read
        finish_to_prefetch := false.B
      }
    } .elsewhen (rpq.io.empty || (rpq.io.deq.valid && !drain_load)) {
      // io.commit_val is for the prefetcher. it tells the prefetcher that this line was correctly acquired
      // The prefetcher should consider fetching the next line
      io.commit_val := true.B
      state := s_meta_read
    }
  } .elsewhen (state === s_meta_read) {
    io.meta_read.valid := !io.prober_state.valid || !grantack.valid || (io.prober_state.bits(untagBits-1,blockOffBits) =/= req_idx)
    io.meta_read.bits.idx := req_idx
    io.meta_read.bits.tag := req_tag
    io.meta_read.bits.way_en := req.way_en
    when (io.meta_read.fire) {
      state := s_meta_resp_1
    }
  } .elsewhen (state === s_meta_resp_1) {
    state := s_meta_resp_2
  } .elsewhen (state === s_meta_resp_2) {
    val needs_wb = io.meta_resp.bits.coh.onCacheControl(M_FLUSH)._1
    state := Mux(!io.meta_resp.valid, s_meta_read, // Prober could have nack'd this read
             Mux(needs_wb, s_meta_clear, s_commit_line))
  } .elsewhen (state === s_meta_clear) {
    io.meta_write.valid         := true.B
    io.meta_write.bits.idx      := req_idx
    io.meta_write.bits.tag      := req_tag
    io.meta_write.bits.data.coh := coh_on_clear
    io.meta_write.bits.data.tag := req_tag
    io.meta_write.bits.way_en   := req.way_en

    when (io.meta_write.fire) {
      state      := s_wb_req
    }
  } .elsewhen (state === s_wb_req) {
    io.wb_req.valid          := true.B

    io.wb_req.bits.tag       := req.old_meta.tag
    io.wb_req.bits.idx       := req_idx
    io.wb_req.bits.param     := shrink_param
    io.wb_req.bits.way_en    := req.way_en
    io.wb_req.bits.source    := io.id
    io.wb_req.bits.voluntary := true.B
    when (io.wb_req.fire) {
      state := s_wb_resp
    }
  } .elsewhen (state === s_wb_resp) {
    when (io.wb_resp) {
      state := s_commit_line
    }
  } .elsewhen (state === s_commit_line) {
    io.install.valid := !installStarted && !protocolFault
    when (io.install.fire) {
      installStarted := true.B
      // Permission upgrades have no line-buffer payload. Their owner
      // reservation is still acknowledged, then replay/publish follows;
      // only a complete GrantData may enter the row-install loop below.
      when (!grant_had_data) { state := s_drain_rpq }
    }
    when (!grant_had_data) {
      io.lb_read.valid := false.B
      io.refill.valid := false.B
    }
    // Do not request the shared LineBuffer until the destination is active.
    // A held row avoids repeatedly winning its read arbiter under write stalls.
    io.lb_read.valid := grant_had_data && installStarted && !protocolFault && !rowValid
    io.lb_read.bits.id := io.id
    io.lb_read.bits.offset := refill_ctr
    val install_row_read_fire = io.lb_read.fire &&
      state === s_commit_line && installStarted && grant_had_data && !protocolFault
    when (install_row_read_fire) {
      rowData := io.lb_resp
      rowValid := true.B
    }
    io.refill.valid := grant_had_data && rowValid && !protocolFault
    io.refill.bits.addr := req_block_addr | (refill_ctr << rowOffBits)
    // The held primary descriptor supplies one physical line for every row.
    io.refill.bits.line_addr := req_block_addr
    io.refill.bits.way_en := req.way_en
    io.refill.bits.wmask := ~(0.U(rowWords.W))
    io.refill.bits.data := rowData
    io.refill.bits.slot_epoch := req.slot_epoch
    io.refill.bits.line_generation := req.line_generation
    io.refill.bits.transaction_token := req.transaction_token
    io.refill.bits.mshr_id := io.id
    io.refill.bits.owner_context_valid := req.owner_context_valid
    io.refill.bits.image := refillImage
    when (io.refill.fire) {
      rowValid := false.B
      refill_ctr := refill_ctr + 1.U
      when (refill_ctr === (cacheDataBeats - 1).U) { state := s_drain_rpq }
    }
  } .elsewhen (state === s_drain_rpq) {
    io.replay.valid := rpq.io.deq.valid && !replay_inflight
    io.replay.bits  := rpq.io.deq.bits
    io.replay.bits.way_en    := req.way_en
    io.replay.bits.addr := Cat(req_tag, req_idx, rpq.io.deq.bits.addr(blockOffBits-1,0))
    io.replay.bits.replay_mshr_id := io.id
    when (io.replay.fire) {
      replay_inflight := true.B
      inflight := io.replay.bits
      inflightGrantValid := false.B
    }
    rpq.io.deq.ready := replayTerminal
    when (replayTerminal && io.replay_result.bits.status === CacheTerminal.applied &&
        isWrite(inflight.uop.mem_cmd)) {
      // Set dirty bit
      val (is_hit, _, coh_on_hit) = new_coh.onAccess(rpq.io.deq.bits.uop.mem_cmd)
      assert(is_hit, "We still don't have permissions for this store")
      new_coh := coh_on_hit
    }
    when (rpq.io.empty && !rpq.io.enq.valid && !replay_inflight) {
      state := s_meta_write_req
    }
  } .elsewhen (state === s_meta_write_req) {
    io.meta_write.valid         := true.B
    io.meta_write.bits.idx      := req_idx
    io.meta_write.bits.tag      := req_tag
    io.meta_write.bits.data.coh := new_coh
    io.meta_write.bits.data.tag := req_tag
    io.meta_write.bits.way_en   := req.way_en
    when (io.meta_write.fire) {
      state := s_mem_finish_1
      finish_to_prefetch := false.B
    }
  } .elsewhen (state === s_mem_finish_1) {
    when (!grantack.valid) {
      grantack.valid := false.B
      state := s_mem_finish_2
    }
  } .elsewhen (state === s_mem_finish_2) {
    state := Mux(finish_to_prefetch, s_prefetch, s_invalid)
  } .elsewhen (state === s_prefetch) {
    io.req_pri_rdy := true.B
    when ((io.req_sec_val && !io.req_sec_rdy) || io.clear_prefetch) {
      state := s_invalid
    } .elsewhen (io.req_sec_val && io.req_sec_rdy) {
      val (is_hit, _, coh_on_hit) = new_coh.onAccess(io.req.uop.mem_cmd)
      when (is_hit) { // Proceed with refill
        new_coh := coh_on_hit
        state := s_meta_read
      } .otherwise { // Reacquire this line
        new_coh := ClientMetadata.onReset
        grantFirst := true.B
        state := s_refill_req
      }
    } .elsewhen (io.req_pri_val && io.req_pri_rdy) {
      grant_had_data := false.B
      state := handle_pri_req(state)
    }
  }
}

class BoomIOMSHR(id: Int)(implicit edge: TLEdgeOut, p: Parameters) extends BoomModule()(p)
  with HasL1HellaCacheParameters
{
  val io = IO(new Bundle {
    val req  = Flipped(Decoupled(new BoomDCacheReq))
    val resp = Decoupled(new BoomDCacheResp)
    val mem_access = Decoupled(new TLBundleA(edge.bundle))
    val completion = Decoupled(new BoomCacheCompletion)
    val mem_ack    = Flipped(Valid(new TLBundleD(edge.bundle)))
    val traffic_strict_store_complete = Output(Bool())
    val traffic_strict_store_complete_stq_idx = Output(UInt(stqAddrSz.W))
    val traffic_strict_store_complete_token = Output(UInt(64.W))

    // We don't need brupdate in here because uncacheable operations are guaranteed non-speculative
  })

  def beatOffset(addr: UInt) = addr.extract(beatOffBits-1, wordOffBits)

  def wordFromBeat(addr: UInt, dat: UInt) = {
    val shift = Cat(beatOffset(addr), 0.U((wordOffBits+log2Ceil(wordBytes)).W))
    (dat >> shift)(wordBits-1, 0)
  }

  val req = Reg(new BoomDCacheReq)
  val grant_word = Reg(UInt(wordBits.W))

  val s_idle :: s_mem_access :: s_mem_ack :: s_resp :: Nil = Enum(4)

  val state = RegInit(s_idle)
  io.req.ready := state === s_idle

  val loadgen = new LoadGen(req.uop.mem_size, req.uop.mem_signed, req.addr, grant_word, false.B, wordBytes)

  val a_source  = id.U
  val a_address = req.addr
  val a_size    = req.uop.mem_size
  val a_data    = Fill(beatWords, req.data)

  val get      = CacheImage.base(edge.Get(a_source, a_address, a_size)._2)
  val put      = CacheImage.base(edge.Put(a_source, a_address, a_size, a_data)._2)
  val atomics  = if (edge.manager.anySupportLogical) {
    MuxLookup(req.uop.mem_cmd, (0.U).asTypeOf(new TLBundleA(edge.bundle)), Array(
      M_XA_SWAP -> CacheImage.base(edge.Logical(a_source, a_address, a_size, a_data, TLAtomics.SWAP)._2),
      M_XA_XOR  -> CacheImage.base(edge.Logical(a_source, a_address, a_size, a_data, TLAtomics.XOR) ._2),
      M_XA_OR   -> CacheImage.base(edge.Logical(a_source, a_address, a_size, a_data, TLAtomics.OR)  ._2),
      M_XA_AND  -> CacheImage.base(edge.Logical(a_source, a_address, a_size, a_data, TLAtomics.AND) ._2),
      M_XA_ADD  -> CacheImage.base(edge.Arithmetic(a_source, a_address, a_size, a_data, TLAtomics.ADD)._2),
      M_XA_MIN  -> CacheImage.base(edge.Arithmetic(a_source, a_address, a_size, a_data, TLAtomics.MIN)._2),
      M_XA_MAX  -> CacheImage.base(edge.Arithmetic(a_source, a_address, a_size, a_data, TLAtomics.MAX)._2),
      M_XA_MINU -> CacheImage.base(edge.Arithmetic(a_source, a_address, a_size, a_data, TLAtomics.MINU)._2),
      M_XA_MAXU -> CacheImage.base(edge.Arithmetic(a_source, a_address, a_size, a_data, TLAtomics.MAXU)._2)))
  } else {
    // If no managers support atomics, assert fail if processor asks for them
    assert(state === s_idle || !isAMO(req.uop.mem_cmd))
    (0.U).asTypeOf(new TLBundleA(edge.bundle))
  }
  assert(state === s_idle || req.uop.mem_cmd =/= M_XSC)

  io.mem_access.valid := state === s_mem_access
  io.mem_access.bits  := Mux(isAMO(req.uop.mem_cmd), atomics, Mux(isRead(req.uop.mem_cmd), get, put))

  val send_resp = isRead(req.uop.mem_cmd) && !isWrite(req.uop.mem_cmd)
  val responseDone = RegInit(false.B)
  val completionDone = RegInit(false.B)

  io.resp.valid     := (state === s_resp) && send_resp && !responseDone
  io.resp.bits.uop  := req.uop
  io.resp.bits.data := loadgen.data
  io.resp.bits.is_hella := req.is_hella
  io.resp.bits.traffic_check := req.traffic_check
  io.resp.bits.traffic_seen  := req.traffic_seen
  io.resp.bits.traffic_cacheable := req.traffic_cacheable
  io.resp.bits.request_token_valid := req.request_token_valid
  io.resp.bits.request_token := req.request_token
  io.completion.valid := state === s_resp && isWrite(req.uop.mem_cmd) &&
    !completionDone && (!send_resp || responseDone)
  io.completion.bits.req := req
  io.completion.bits.status := CacheTerminal.applied
  io.completion.bits.data := loadgen.data
  when (io.resp.fire) { responseDone := true.B }
  when (io.completion.fire) { completionDone := true.B }

  // D response and the held terminal handshake complete an uncached write.
  io.traffic_strict_store_complete := io.completion.fire &&
    req.strict_store_token_valid && !req.traffic_cacheable && req.uop.uses_stq &&
    req.uop.mem_cmd === M_XWR
  io.traffic_strict_store_complete_stq_idx := req.uop.stq_idx
  io.traffic_strict_store_complete_token := req.strict_store_token

  when (io.req.fire) {
    req   := io.req.bits
    responseDone := false.B
    completionDone := false.B
    assert(!io.req.bits.owner_context_valid, "MMIO cannot own a cache slot")
    state := s_mem_access
  }
  when (io.mem_access.fire) {
    state := s_mem_ack
  }
  when (state === s_mem_ack && io.mem_ack.valid) {
    state := s_resp
    when (isRead(req.uop.mem_cmd)) {
      grant_word := wordFromBeat(req.addr, io.mem_ack.bits.data)
    }
  }
  when (state === s_resp) {
    when ((!send_resp || responseDone || io.resp.fire) &&
        (!isWrite(req.uop.mem_cmd) || completionDone || io.completion.fire)) {
      state := s_idle
    }
  }
}

class LineBufferReadReq(implicit p: Parameters) extends BoomBundle()(p)
  with HasL1HellaCacheParameters
{
  val id      = UInt(log2Ceil(nLBEntries).W)
  val offset  = UInt(log2Ceil(cacheDataBeats).W)
  def lb_addr = Cat(id, offset)
}

class LineBufferWriteReq(implicit p: Parameters) extends LineBufferReadReq()(p)
{
  val data   = UInt(encRowBits.W)
}

class LineBufferMetaWriteReq(implicit p: Parameters) extends BoomBundle()(p)
{
  val id   = UInt(log2Ceil(nLBEntries).W)
  val coh  = new ClientMetadata
  val addr = UInt(coreMaxAddrBits.W)
}

class LineBufferMeta(implicit p: Parameters) extends BoomBundle()(p)
  with HasL1HellaCacheParameters
{
  val coh  = new ClientMetadata
  val addr = UInt(coreMaxAddrBits.W)
}

class BoomMSHRFile(implicit edge: TLEdgeOut, p: Parameters) extends BoomModule()(p)
  with HasL1HellaCacheParameters
{
  val io = IO(new Bundle {
    val req  = Flipped(Vec(memWidth, Decoupled(new BoomDCacheReqInternal))) // Req from s2 of DCache pipe
    val lookup = Input(Vec(memWidth, new BoomDCacheReqInternal))
    val admission = Output(Vec(memWidth, new BoomCacheAdmission))
    val install = Decoupled(new BoomCacheInstall)
    val install_fault = Input(Vec(cfg.nMSHRs, Bool()))
    val refill_fault = Input(Vec(cfg.nMSHRs, Bool()))
    val replay_result = Flipped(Vec(cfg.nMSHRs, Decoupled(new BoomCacheCompletion)))
    val replay_grant = Input(Vec(cfg.nMSHRs, Valid(new BoomDCacheReq)))
    val mmio_completion = Decoupled(new BoomCacheCompletion)
    val req_is_probe = Input(Vec(memWidth, Bool()))
    val resp = Decoupled(new BoomDCacheResp)
    val secondary_miss = Output(Vec(memWidth, Bool()))
    val block_hit = Output(Vec(memWidth, Bool()))
    val owner_line_valid = Output(Vec(cfg.nMSHRs, Bool()))
    val owner_line_addr = Output(Vec(cfg.nMSHRs, UInt(coreMaxAddrBits.W)))
    val owner_line_way = Output(Vec(cfg.nMSHRs, UInt(nWays.W)))
    val debug_state = Output(Vec(cfg.nMSHRs, UInt(5.W)))
    val debug_waiting_resource = Output(Vec(cfg.nMSHRs, UInt(4.W)))

    val brupdate       = Input(new BrUpdateInfo)
    val exception    = Input(Bool())
    val rob_pnr_idx  = Input(UInt(robAddrSz.W))
    val rob_head_idx = Input(UInt(robAddrSz.W))

    val mem_acquire  = Decoupled(new TLBundleA(edge.bundle))
    val mem_grant    = Flipped(Decoupled(new TLBundleD(edge.bundle)))
    val mem_finish   = Decoupled(new TLBundleE(edge.bundle))

    val refill     = Decoupled(new BoomCacheRefill)
    val meta_write = Decoupled(new L1MetaWriteReq)
    val meta_read  = Decoupled(new L1MetaReadReq)
    val meta_resp  = Input(Valid(new L1Metadata))
    val replay     = Decoupled(new BoomDCacheReqInternal)
    val replay_effect_done = Input(Bool())
    val replay_done_id = Input(UInt(log2Ceil(cfg.nMSHRs max 2).W))
    val replay_cancel = Input(Bool())
    val replay_cancel_id = Input(UInt(log2Ceil(cfg.nMSHRs max 2).W))
    val replay_effect_done_vec = Input(Vec(cfg.nMSHRs, Bool()))
    val replay_cancel_vec = Input(Vec(cfg.nMSHRs, Bool()))
    val replay_done_sdq_id = Output(UInt(log2Ceil(cfg.nSDQ).W))
    val replay_done_is_write = Output(Bool())
    val replay_done_sdq_mask = Output(UInt(cfg.nSDQ.W))
    val prefetch   = Decoupled(new BoomDCacheReq)
    val wb_req     = Decoupled(new WritebackReq(edge.bundle))

    val prober_state = Input(Valid(UInt(coreMaxAddrBits.W)))

    val clear_all = Input(Bool()) // Clears all uncommitted MSHRs to prepare for fence

    val wb_resp   = Input(Bool())

    val fence_rdy = Output(Bool())
    // Observation only: parked s_prefetch owners are ready for a new primary
    // request and have no active transaction. Include busy uncached MSHRs.
    val active_transactions = Output(UInt(log2Ceil(cfg.nMSHRs + cfg.nMMIOs + 1).W))
    val probe_rdy = Output(Bool())
    val traffic_strict_store_complete = Output(Bool())
    val traffic_strict_store_complete_stq_idx = Output(UInt(stqAddrSz.W))
    val traffic_strict_store_complete_token = Output(UInt(64.W))
  })

  val req_idx = PriorityEncoder(VecInit(io.req.map(_.valid)).asUInt)
  val raw = io.lookup(req_idx)
  val req     = io.req(req_idx)
  val req_is_probe = io.req_is_probe(0)

  for (w <- 0 until memWidth)
    io.req(w).ready := false.B

  val prefetcher: DataPrefetcher = if (enablePrefetching) Module(new NLPrefetcher)
                                                     else Module(new NullPrefetcher)

  io.prefetch <> prefetcher.io.prefetch


  val cacheable = edge.manager.supportsAcquireBFast(raw.addr, lgCacheBlockBytes.U)

  // --------------------
  // The MSHR SDQ
  val sdq_val      = RegInit(0.U(cfg.nSDQ.W))
  val sdq_alloc_id = PriorityEncoder(~sdq_val(cfg.nSDQ-1,0))
  val sdq_rdy      = !sdq_val.andR
  val sdq_enq      = req.fire && cacheable && isWrite(req.bits.uop.mem_cmd)
  val sdq          = Mem(cfg.nSDQ, UInt(coreDataBits.W))
  val sdqOwner = Reg(Vec(cfg.nSDQ, new BoomDCacheReqInternal))

  when (sdq_enq) {
    sdq(sdq_alloc_id) := req.bits.data
    sdqOwner(sdq_alloc_id) := req.bits
  }

  // --------------------
  // The LineBuffer Data
  // Holds refilling lines, prefetched lines
  val lb = Mem(nLBEntries * cacheDataBeats, UInt(encRowBits.W))
  val lb_read_arb  = Module(new Arbiter(new LineBufferReadReq, cfg.nMSHRs))
  val lb_write_arb = Module(new Arbiter(new LineBufferWriteReq, cfg.nMSHRs))

  lb_read_arb.io.out.ready  := false.B
  lb_write_arb.io.out.ready := true.B

  val lb_read_data = WireInit(0.U(encRowBits.W))
  when (lb_write_arb.io.out.fire) {
    lb.write(lb_write_arb.io.out.bits.lb_addr, lb_write_arb.io.out.bits.data)
  } .otherwise {
    lb_read_arb.io.out.ready := true.B
    when (lb_read_arb.io.out.fire) {
      lb_read_data := lb.read(lb_read_arb.io.out.bits.lb_addr)
    }
  }
  def widthMap[T <: Data](f: Int => T) = VecInit((0 until memWidth).map(f))




  val idx_matches = Wire(Vec(memWidth, Vec(cfg.nMSHRs, Bool())))
  val tag_matches = Wire(Vec(memWidth, Vec(cfg.nMSHRs, Bool())))
  val way_matches = Wire(Vec(memWidth, Vec(cfg.nMSHRs, Bool())))

  val tag_match   = widthMap(w => Mux1H(idx_matches(w), tag_matches(w)))
  val idx_match   = widthMap(w => idx_matches(w).reduce(_||_))
  val way_match   = widthMap(w => Mux1H(idx_matches(w), way_matches(w)))

  val wb_tag_list = Wire(Vec(cfg.nMSHRs, UInt(tagBits.W)))

  val meta_write_arb = Module(new Arbiter(new L1MetaWriteReq           , cfg.nMSHRs))
  val meta_read_arb  = Module(new Arbiter(new L1MetaReadReq            , cfg.nMSHRs))
  val wb_req_arb     = Module(new Arbiter(new WritebackReq(edge.bundle), cfg.nMSHRs))
  val replay_arb     = Module(new Arbiter(new BoomDCacheReqInternal    , cfg.nMSHRs))
  val resp_arb       = Module(new Arbiter(new BoomDCacheResp           , cfg.nMSHRs + nIOMSHRs))
  val refill_arb     = Module(new Arbiter(new BoomCacheRefill          , cfg.nMSHRs))
  val installArb = Module(new Arbiter(new BoomCacheInstall, cfg.nMSHRs))
  val mmioCompletionArb = Module(new Arbiter(new BoomCacheCompletion, nIOMSHRs))
  io.install <> installArb.io.out
  io.mmio_completion <> mmioCompletionArb.io.out

  val commit_vals    = Wire(Vec(cfg.nMSHRs, Bool()))
  val commit_addrs   = Wire(Vec(cfg.nMSHRs, UInt(coreMaxAddrBits.W)))
  val commit_cohs    = Wire(Vec(cfg.nMSHRs, new ClientMetadata))

  var sec_rdy   = false.B

  io.fence_rdy := true.B
  io.probe_rdy := true.B
  io.mem_grant.ready := false.B
  io.replay_done_sdq_id := 0.U
  io.replay_done_is_write := false.B
  io.replay_done_sdq_mask := 0.U
  for (i <- 0 until cfg.nMSHRs) {
    io.owner_line_valid(i) := false.B
    io.owner_line_addr(i) := 0.U
    io.owner_line_way(i) := 0.U
  }
  for (w <- 0 until memWidth) {
    io.admission(w) := 0.U.asTypeOf(new BoomCacheAdmission)
    io.admission(w).kind := CacheAdmission.conflict
    io.admission(w).way := io.lookup(w).way_en
    io.admission(w).sdq_id := sdq_alloc_id
    io.admission(w).slot_epoch := io.lookup(w).slot_epoch
    io.admission(w).line_generation := io.lookup(w).line_generation
    io.admission(w).image_valid := io.lookup(w).image_valid
    io.admission(w).write_domain_valid := io.lookup(w).write_domain_valid
    io.admission(w).write_domain_seq := io.lookup(w).write_domain_seq
    when (!edge.manager.supportsAcquireBFast(io.lookup(w).addr, lgCacheBlockBytes.U)) {
      io.admission(w).kind := CacheAdmission.mmio
    }
  }

  val mshr_alloc_idx = Wire(UInt())
  val pri_rdy = WireInit(false.B)
  val pri_val = req.valid && sdq_rdy && cacheable && !idx_match(req_idx)
  val mshrs = (0 until cfg.nMSHRs) map { i =>
    val mshr = Module(new BoomMSHR)
    mshr.io.id := i.U(log2Ceil(cfg.nMSHRs).W)

    for (w <- 0 until memWidth) {
      idx_matches(w)(i) := mshr.io.idx.valid && mshr.io.idx.bits === io.lookup(w).addr(untagBits-1,blockOffBits)
      tag_matches(w)(i) := mshr.io.tag.valid && mshr.io.tag.bits === io.lookup(w).addr >> untagBits
      way_matches(w)(i) := mshr.io.way.valid && mshr.io.way.bits === io.lookup(w).way_en
    }
    wb_tag_list(i) := mshr.io.wb_req.bits.tag
    io.owner_line_valid(i) := mshr.io.idx.valid
    io.owner_line_addr(i) := Cat(mshr.io.tag.bits, mshr.io.idx.bits) << blockOffBits
    io.owner_line_way(i) := mshr.io.way.bits
    io.debug_state(i) := mshr.io.debug_state
    io.debug_waiting_resource(i) := mshr.io.debug_waiting_resource



    mshr.io.req_pri_val  := (i.U === mshr_alloc_idx) && pri_val
    when (i.U === mshr_alloc_idx) {
      pri_rdy := mshr.io.req_pri_rdy
    }

    mshr.io.req_sec_val  := req.valid && sdq_rdy && tag_match(req_idx) && idx_matches(req_idx)(i) && cacheable
    mshr.io.req          := req.bits
    installArb.io.in(i) <> mshr.io.install
    mshr.io.install_fault := io.install_fault(i)
    mshr.io.refill_fault := io.refill_fault(i)
    mshr.io.replay_result <> io.replay_result(i)
    mshr.io.replay_grant := io.replay_grant(i)
    when (!idx_match(req_idx) && i.U === mshr_alloc_idx && cacheable) {
      io.admission(req_idx).kind := Mux(raw.tag_match, CacheAdmission.upgrade, CacheAdmission.primary)
      io.admission(req_idx).mshr_id := i.U
      io.admission(req_idx).transaction_token := mshr.io.next_transaction_token
    }
    when (idx_matches(req_idx)(i) && tag_match(req_idx) && cacheable) {
      io.admission(req_idx).kind := CacheAdmission.secondary
      io.admission(req_idx).mshr_id := i.U
      io.admission(req_idx).transaction_token := mshr.io.owner.transaction_token
      io.admission(req_idx).way := mshr.io.owner.way_en
      io.admission(req_idx).slot_epoch := mshr.io.owner.slot_epoch
      io.admission(req_idx).line_generation := mshr.io.owner.line_generation
      io.admission(req_idx).image_valid := mshr.io.owner.image_valid
      io.admission(req_idx).write_domain_valid := mshr.io.write_domain_valid || raw.write_domain_valid
      io.admission(req_idx).write_domain_seq := Mux(mshr.io.write_domain_valid,
        mshr.io.write_domain_seq, raw.write_domain_seq)
    }
    mshr.io.replay_effect_done := io.replay_effect_done_vec(i)
    mshr.io.replay_cancel := io.replay_cancel_vec(i)
    mshr.io.req_is_probe := req_is_probe

    // Clear because of a FENCE, a request to the same idx as a prefetched line,
    // a probe to that prefetched line, all mshrs are in use
    mshr.io.clear_prefetch := ((io.clear_all && !req.valid)||
      (req.valid && idx_matches(req_idx)(i) && cacheable && !tag_match(req_idx)) ||
      (req_is_probe && idx_matches(req_idx)(i)))
    mshr.io.brupdate       := io.brupdate
    mshr.io.exception    := io.exception
    mshr.io.rob_pnr_idx  := io.rob_pnr_idx
    mshr.io.rob_head_idx := io.rob_head_idx

    mshr.io.prober_state := io.prober_state

    mshr.io.wb_resp      := io.wb_resp

    meta_write_arb.io.in(i) <> mshr.io.meta_write
    meta_read_arb.io.in(i)  <> mshr.io.meta_read
    mshr.io.meta_resp       := io.meta_resp
    wb_req_arb.io.in(i)     <> mshr.io.wb_req
    replay_arb.io.in(i)     <> mshr.io.replay
    refill_arb.io.in(i)     <> mshr.io.refill

    lb_read_arb.io.in(i)       <> mshr.io.lb_read
    mshr.io.lb_resp            := lb_read_data
    lb_write_arb.io.in(i)      <> mshr.io.lb_write

    commit_vals(i)  := mshr.io.commit_val
    commit_addrs(i) := mshr.io.commit_addr
    commit_cohs(i)  := mshr.io.commit_coh

    mshr.io.mem_grant.valid := false.B
    mshr.io.mem_grant.bits  := DontCare
    when (io.mem_grant.bits.source === i.U) {
      mshr.io.mem_grant <> io.mem_grant
    }

    sec_rdy   = sec_rdy || (mshr.io.req_sec_rdy && mshr.io.req_sec_val)
    resp_arb.io.in(i) <> mshr.io.resp

    when (!mshr.io.req_pri_rdy) {
      io.fence_rdy := false.B
    }
    for (w <- 0 until memWidth) {
      when (!mshr.io.probe_rdy && idx_matches(w)(i) && io.req_is_probe(w)) {
        io.probe_rdy := false.B
      }
    }

    mshr
  }

  // Free by the immutable issued descriptor, never by a mutable RPQ head.
  val retiredStores = mshrs.map(m => m.io.retired.valid && isWrite(m.io.retired.bits.uop.mem_cmd))
  val free_sdq_mask = (0 until cfg.nMSHRs).map { i =>
    val r = mshrs(i).io.retired.bits
    val owner = sdqOwner(r.sdq_id)
    val matches = sdq_val(r.sdq_id) && owner.request_token === r.request_token &&
      owner.request_token_valid && r.request_token_valid &&
      owner.transaction_token === r.transaction_token && owner.slot_epoch === r.slot_epoch &&
      owner.owner_way === r.owner_way && owner.replay_mshr_id === r.replay_mshr_id &&
      owner.effect_token_valid && r.effect_token_valid && owner.effect_token === r.effect_token
    when (retiredStores(i)) { assert(matches, "SDQ terminal owner mismatch") }
    UIntToOH(r.sdq_id, cfg.nSDQ) & Fill(cfg.nSDQ, retiredStores(i) && matches)
  }.reduce(_ | _)
  io.replay_done_sdq_mask := free_sdq_mask
  io.replay_done_is_write := retiredStores.reduce(_ || _)
  io.replay_done_sdq_id := Mux1H(PriorityEncoderOH(VecInit(retiredStores).asUInt).asBools,
    mshrs.map(_.io.retired.bits.sdq_id))
  val replay_terminal_vec = VecInit(mshrs.map(_.io.retired.valid))

  // Try to round-robin the MSHRs
  val mshr_head      = RegInit(0.U(log2Ceil(cfg.nMSHRs).W))
  mshr_alloc_idx    := RegNext(AgePriorityEncoder(mshrs.map(m=>m.io.req_pri_rdy), mshr_head))
  when (pri_rdy && pri_val) { mshr_head := WrapInc(mshr_head, cfg.nMSHRs) }



  io.meta_write <> meta_write_arb.io.out
  io.meta_read  <> meta_read_arb.io.out
  io.wb_req     <> wb_req_arb.io.out

  val mmio_alloc_arb = Module(new Arbiter(Bool(), nIOMSHRs))


  var mmio_rdy = false.B

  val mmios = (0 until nIOMSHRs) map { i =>
    val id = cfg.nMSHRs + 1 + i // +1 for wb unit
    val mshr = Module(new BoomIOMSHR(id))

    mmio_alloc_arb.io.in(i).valid := mshr.io.req.ready
    mmio_alloc_arb.io.in(i).bits  := DontCare
    mshr.io.req.valid := mmio_alloc_arb.io.in(i).ready
    BoomDCacheReq.copyBase(mshr.io.req.bits, req.bits)
    mshr.io.req.bits.owner_context_valid := false.B
    mshr.io.req.bits.owner_way := 0.U
    mmioCompletionArb.io.in(i) <> mshr.io.completion

    mmio_rdy = mmio_rdy || mshr.io.req.ready

    mshr.io.mem_ack.bits  := io.mem_grant.bits
    mshr.io.mem_ack.valid := io.mem_grant.valid && io.mem_grant.bits.source === id.U
    when (io.mem_grant.bits.source === id.U) {
      io.mem_grant.ready := true.B
    }

    resp_arb.io.in(cfg.nMSHRs + i) <> mshr.io.resp
    when (!mshr.io.req.ready) {
      io.fence_rdy := false.B
    }
    mshr
  }

  io.active_transactions := PopCount(VecInit(
    mshrs.map(m => !m.io.req_pri_rdy) ++ mmios.map(m => !m.io.req.ready)))

  val strictStoreComplete = mmios.map(_.io.traffic_strict_store_complete)
  io.traffic_strict_store_complete := strictStoreComplete.reduce(_||_)
  io.traffic_strict_store_complete_stq_idx :=
    Mux1H(strictStoreComplete, mmios.map(_.io.traffic_strict_store_complete_stq_idx))
  io.traffic_strict_store_complete_token :=
    Mux1H(strictStoreComplete, mmios.map(_.io.traffic_strict_store_complete_token))

  mmio_alloc_arb.io.out.ready := req.valid && !cacheable

  TLArbiter.lowestFromSeq(edge, io.mem_acquire, mshrs.map(_.io.mem_acquire) ++ mmios.map(_.io.mem_access))
  TLArbiter.lowestFromSeq(edge, io.mem_finish,  mshrs.map(_.io.mem_finish))

  val respq = Module(new BranchKillableQueue(new BoomDCacheResp, 4, u => u.uses_ldq, flow = false))
  respq.io.brupdate := io.brupdate
  respq.io.flush    := io.exception
  respq.io.enq      <> resp_arb.io.out
  io.resp           <> respq.io.deq

  for (w <- 0 until memWidth) {
    io.req(w).ready      := (w.U === req_idx) &&
      Mux(!cacheable, mmio_rdy, sdq_rdy && Mux(idx_match(w), tag_match(w) && sec_rdy, pri_rdy))
    io.secondary_miss(w) := idx_match(w) && way_match(w) && !tag_match(w)
    io.block_hit(w)      := idx_match(w) && tag_match(w)
  }
  io.refill         <> refill_arb.io.out

  val replay_terminal = replay_terminal_vec.reduce(_ || _)

  io.replay <> replay_arb.io.out
  io.replay.bits.data := sdq(replay_arb.io.out.bits.sdq_id)
  when (io.replay.valid && isWrite(io.replay.bits.uop.mem_cmd)) {
    val r = io.replay.bits
    val owner = sdqOwner(r.sdq_id)
    assert(sdq_val(r.sdq_id) && owner.request_token_valid && r.request_token_valid &&
      owner.request_token === r.request_token && owner.transaction_token === r.transaction_token &&
      owner.slot_epoch === r.slot_epoch && owner.replay_mshr_id === r.replay_mshr_id &&
      owner.effect_token === r.effect_token, "replay read from stale SDQ owner")
  }

  when (io.replay.valid || replay_terminal || sdq_enq) {
    sdq_val := sdq_val & ~free_sdq_mask |
      PriorityEncoderOH(~sdq_val(cfg.nSDQ-1,0)) & Fill(cfg.nSDQ, sdq_enq)
  }

  prefetcher.io.mshr_avail    := RegNext(pri_rdy)
  prefetcher.io.req_val       := RegNext(commit_vals.reduce(_||_))
  prefetcher.io.req_addr      := RegNext(Mux1H(commit_vals, commit_addrs))
  prefetcher.io.req_coh       := RegNext(Mux1H(commit_vals, commit_cohs))
  // SLOWDOWN_TRACE_BEGIN: observation-only; no functional consumers.
  val slowdown_mshr_file_req_valid = chisel3.WireInit(VecInit(io.req.map(_.valid)))
  chisel3.dontTouch(slowdown_mshr_file_req_valid)
  val slowdown_mshr_file_req_ready = chisel3.WireInit(VecInit(io.req.map(_.ready)))
  chisel3.dontTouch(slowdown_mshr_file_req_ready)
  val slowdown_mshr_sdq_ready = chisel3.WireInit(sdq_rdy)
  chisel3.dontTouch(slowdown_mshr_sdq_ready)
  val slowdown_mshr_file_active = chisel3.WireInit(io.active_transactions)
  chisel3.dontTouch(slowdown_mshr_file_active)
  // SLOWDOWN_TRACE_END

}
