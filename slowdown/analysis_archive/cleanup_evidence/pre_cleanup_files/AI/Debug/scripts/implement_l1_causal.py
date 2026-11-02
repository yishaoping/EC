#!/usr/bin/env python3
"""One-time anchored instrumentation edit for L1-Causal-1; no hardware launch."""
from pathlib import Path

ROOT=Path('/data1/gzh/EC')
def insert(rel, anchor, block, after=False):
    p=ROOT/rel;s=p.read_text();assert s.count(anchor)==1,(rel,anchor)
    s=s.replace(anchor,anchor+block if after else block+anchor,1);p.write_text(s)

insert('chipyard/generators/chipyard/src/main/scala/config/RocketConfigs.scala',
 '//===== EC Config: End   =====//', '''
// L1_CAUSAL_GEOMETRY_BEGIN: the two arms differ only in BOOM DCache nSets.
class WithL1CausalSets(sets: Int) extends Config((site, here, up) => {
  case freechips.rocketchip.subsystem.TilesLocated(freechips.rocketchip.subsystem.InSubsystem) =>
    up(freechips.rocketchip.subsystem.TilesLocated(freechips.rocketchip.subsystem.InSubsystem), site).map {
      case b: boom.common.BoomTileAttachParams => b.copy(tileParams = b.tileParams.copy(
        dcache = b.tileParams.dcache.map(_.copy(nSets = sets))))
      case other => other
    }
})
class L1Causal32Config extends Config(new WithL1CausalSets(256) ++ new v1Config)
class L1Causal64Config extends Config(new WithL1CausalSets(512) ++ new v1Config)
// L1_CAUSAL_GEOMETRY_END
''',after=True)

rob='chipyard/generators/boom/src/main/scala/exu/rob.scala'
insert(rob,'  val rob_head_uses_ldq   = Wire(Vec(coreWidth, Bool()))',
 '''
  // L1_CAUSAL_OBSERVATION_BEGIN
  val causalHeadBusy = Wire(Vec(coreWidth, Bool()))
  // L1_CAUSAL_OBSERVATION_END
''',after=True)
insert(rob,'    val slowdown_head_busy = chisel3.WireInit(rob_bsy(rob_head))',
 '''
    // L1_CAUSAL_OBSERVATION_BEGIN
    causalHeadBusy(w) := rob_bsy(rob_head)
    // L1_CAUSAL_OBSERVATION_END
''',after=True)
insert(rob,'  io.com_load_is_at_rob_head := RegNext(','''
  // L1_CAUSAL_OBSERVATION_BEGIN
  val causalHeadBank = PriorityEncoder(rob_head_vals.asUInt)
  val causalHeadUop = io.commit.uops(causalHeadBank)
  val causalHeadLoadBusy = rob_head_vals.asUInt.orR &&
    rob_head_uses_ldq(causalHeadBank) && causalHeadBusy(causalHeadBank) &&
    rob_state =/= s_rollback && !io.commit.valids.asUInt.orR && !io.flush.valid && !io.com_xcpt.valid
  chisel3.util.experimental.BoringUtils.addSource(
    Cat(causalHeadLoadBusy, causalHeadUop.rob_idx, causalHeadUop.ldq_idx),
    "ec_l1_causal_rob_head_v1")
  // L1_CAUSAL_OBSERVATION_END
''')

insert('chipyard/generators/boom/src/main/scala/lsu/lsu.scala',
 '  // REMAINING_SLOWDOWN_OBSERVATION_BEGIN', '''
  // L1_CAUSAL_OBSERVATION_BEGIN
  require(numLdqEntries <= 64 && numStqEntries <= 64)
  val causalRobHead = WireInit(0.U((1 + robAddrSz + ldqAddrSz).W))
  BoringUtils.addSink(causalRobHead, "ec_l1_causal_rob_head_v1")
  val causalHeadIdx = causalRobHead(ldqAddrSz - 1, 0)
  val causalHeadRobIdx = causalRobHead(ldqAddrSz + robAddrSz - 1, ldqAddrSz)
  val causalHeadEntry = ldq(causalHeadIdx)
  val causalHeadWaiting = causalRobHead(ldqAddrSz + robAddrSz) && causalHeadEntry.valid &&
    causalHeadEntry.bits.uop.rob_idx === causalHeadRobIdx && !causalHeadEntry.bits.succeeded
  val causalHeadTokenForObserver = WireInit(causalHeadEntry.bits.functional_token)
  BoringUtils.addSource(causalHeadWaiting, "ec_l1_causal_head_wait_v1")
  BoringUtils.addSource(causalHeadTokenForObserver, "ec_l1_causal_head_token_v1")
  BoringUtils.addSource(causalHeadIdx, "ec_l1_causal_head_ldq_v1")
  BoringUtils.addSource(VecInit(ldq.map(_.valid)).asUInt, "ec_l1_causal_ldq_live_v1")
  // L1_CAUSAL_OBSERVATION_END
''')

insert('chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala',
 '  // REMAINING_SLOWDOWN_OBSERVATION_BEGIN', '''
  // L1_CAUSAL_OBSERVATION_BEGIN
  chisel3.util.experimental.BoringUtils.addSource(fsm_state === fsm_sch && !scheduler_available,
    "ec_l1_causal_scheduler_wait_v1")
  // L1_CAUSAL_OBSERVATION_END
''')

insert('chipyard/generators/boom/src/main/scala/exu/core.scala',
 '  // REMAINING_SLOWDOWN_OBSERVATION_BEGIN', '''
  // L1_CAUSAL_OBSERVATION_BEGIN
  // PCs and ELF hash are pinned by the paired launcher/workload contract.
  val causalRoiStart = rob.io.wb_resps.map(r => r.valid && r.bits.uop.debug_pc === "h80000340".U)
  val causalRoiStop = rob.io.wb_resps.map(r => r.valid && r.bits.uop.debug_pc === "h8000039c".U)
  val causalRoiRead = Mux1H(causalRoiStart.zip(causalRoiStop).map { case (a,b) => a || b },
    rob.io.wb_resps.map(_.bits.data(63,0)))
  BoringUtils.addSource(Cat(causalRoiStart.reduce(_ || _), causalRoiStop.reduce(_ || _), causalRoiRead),
    "ec_l1_causal_roi_marker_v1")
  // L1_CAUSAL_OBSERVATION_END
''')

insert('chipyard/generators/boom/src/main/scala/lsu/dcache.scala',
 '  // CACHE_OPPORTUNITY_OBSERVATION_ONLY. Values flow only into an input-only', '''
  // L1_CAUSAL_OBSERVATION_BEGIN
  val causalHeadWait = WireInit(false.B)
  val causalHeadToken = WireInit(0.U(64.W))
  val causalHeadLdq = WireInit(0.U(ldqAddrSz.W))
  val causalLdqLive = WireInit(0.U(numLdqEntries.W))
  val causalSchedulerWait = WireInit(false.B)
  val causalRoiMarker = WireInit(0.U(66.W))
  BoringUtils.addSink(causalHeadWait, "ec_l1_causal_head_wait_v1")
  BoringUtils.addSink(causalHeadToken, "ec_l1_causal_head_token_v1")
  BoringUtils.addSink(causalHeadLdq, "ec_l1_causal_head_ldq_v1")
  BoringUtils.addSink(causalLdqLive, "ec_l1_causal_ldq_live_v1")
  BoringUtils.addSink(causalSchedulerWait, "ec_l1_causal_scheduler_wait_v1")
  BoringUtils.addSink(causalRoiMarker, "ec_l1_causal_roi_marker_v1")
  val causalEvents = (0 until memWidth).flatMap { w =>
    val r = s2_req(w)
    val accepted = mshrs.io.req(w).bits
    val live = s2_valid(w) && s2_type === t_lsu && r.traffic_cacheable &&
      !IsKilledByBranch(io.lsu.brupdate, r.uop) && !(io.lsu.exception && r.uop.uses_ldq)
    val missFlags = VecInit(Seq(r.uop.uses_ldq, r.uop.uses_stq,
      !s2_tag_match(w), s2_tag_match(w) && !s2_hit(w),
      s2_nack_miss(w), s2_nack_victim(w), s2_nack_data(w), s2_nack_wb(w),
      s2_nack_hit(w), s2_send_nack(w))).asUInt
    val admissionFlags = VecInit(Seq(accepted.uop.uses_ldq, accepted.uop.uses_stq,
      accepted.admission === CacheAdmission.primary,
      accepted.admission === CacheAdmission.secondary,
      accepted.admission === CacheAdmission.upgrade)).asUInt
    Seq(
      CacheOpportunityObservation.event(io.lsu.req.fire && io.lsu.req.bits(w).valid &&
        io.lsu.req.bits(w).bits.uop.uses_ldq, 22,
        tag = io.lsu.req.bits(w).bits.request_token, set = io.lsu.req.bits(w).bits.uop.ldq_idx),
      CacheOpportunityObservation.event(live && !s2_hit(w), 14, missFlags,
        r.addr, r.request_token, r.uop.rob_idx,
        Mux(r.uop.uses_ldq, r.uop.ldq_idx, r.uop.stq_idx)),
      CacheOpportunityObservation.event(mshrs.io.req(w).fire && accepted.traffic_cacheable, 15,
        admissionFlags, accepted.addr, accepted.request_token, accepted.transaction_token,
        Mux(accepted.uop.uses_ldq, accepted.uop.ldq_idx, accepted.uop.stq_idx), accepted.replay_mshr_id),
      CacheOpportunityObservation.event(io.lsu.nack(w).valid && io.lsu.nack(w).bits.uop.uses_ldq, 21,
        missFlags, tag = io.lsu.nack(w).bits.request_token, set = io.lsu.nack(w).bits.uop.ldq_idx))
  } ++ Seq(
    CacheOpportunityObservation.event(dataWriteArb.io.in(1).fire && refillLastBeat && refillOwnerMatch,
      16, tag = mshrs.io.refill.bits.transaction_token, way = mshrs.io.refill.bits.mshr_id),
    // Head sample precedes response removal: the return cycle still cannot commit this busy load.
    CacheOpportunityObservation.event(true.B, 18,
      VecInit(Seq(causalHeadWait, causalSchedulerWait, remainingRobState(5))).asUInt,
      tag = causalHeadToken, value = causalLdqLive, set = causalHeadLdq),
    CacheOpportunityObservation.event(mshrs.io.replay.fire && mshrs.io.replay.bits.uop.uses_ldq,
      20, tag = mshrs.io.replay.bits.request_token, set = mshrs.io.replay.bits.uop.ldq_idx)) ++
    (0 until memWidth).map { w =>
      CacheOpportunityObservation.event(io.lsu.resp(w).valid && io.lsu.resp(w).bits.uop.uses_ldq,
        17, tag = io.lsu.resp(w).bits.request_token, set = io.lsu.resp(w).bits.uop.ldq_idx)
    } ++ Seq(CacheOpportunityObservation.event(causalRoiMarker(65,64).orR, 23,
      causalRoiMarker(65,64), tag = causalRoiMarker(63,0)))
  // L1_CAUSAL_OBSERVATION_END
''')
p=ROOT/'chipyard/generators/boom/src/main/scala/lsu/dcache.scala'
s=p.read_text();old='=== cfg.nMSHRs.U, cacheObservationEvents)';assert s.count(old)==1
s=s.replace(old,'=== cfg.nMSHRs.U, cacheObservationEvents ++ causalEvents)');p.write_text(s)
print('Anchored geometry and read-only Scala instrumentation applied')
