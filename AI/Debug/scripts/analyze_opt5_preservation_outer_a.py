#!/usr/bin/env python3
"""Offline preservation/outer-A attribution. No RTL generation or simulation.

Audits the completed-B evidence, separates lock scopes, computes only defensible
phase/structural bounds, and keeps absent transaction/critical histories null.
"""
import argparse
from bisect import bisect_right
from collections import Counter
import importlib.util
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[3]
SCRIPTS=ROOT/'AI/Debug/scripts'
PREVIOUS=ROOT/'AI/TMP/opt5_cache_transfer_attribution_20261101_113310'


def module(name,path):
    spec=importlib.util.spec_from_file_location(name,path)
    obj=importlib.util.module_from_spec(spec); spec.loader.exec_module(obj)
    return obj


transfer=module('preservation_prior_transfer',SCRIPTS/'analyze_opt5_cache_transfer.py')
require,read,sha=transfer.require,transfer.read,transfer.sha
iv=transfer.iv


def intrinsic_gap_bound(memory_write_starts,beats=8,internal_gap=3,carry_in=1):
    """Bound intrinsic nonvalid gap slots ONLY, using actual packet-count ceiling.

    The larger traffic window contains the ROI. Its memory writes aggregate
    preservation A + SourceC data C. Thus preservation first-A count <= writes.
    A singleton engine permits at most one already-started packet carry-in.
    This does NOT bound bank/ready stalls, drain/waitACK, or new-trace feedback.
    """
    require(memory_write_starts>=0 and beats>=1 and internal_gap>=0 and carry_in in (0,1), 'invalid bound inputs')
    n=memory_write_starts+carry_in
    return dict(packet_count_ceiling=n,reported_memory_writes=memory_write_starts,
        possible_pre_window_packet=carry_in,beats=beats,intrinsic_slots_between_beats=internal_gap,
        slots_per_packet=(beats-1)*internal_gap,cycle_upper_bound=n*(beats-1)*internal_gap,
        scope='delete only mandatory delay1/delay2/read gap slots while packet arb held; NOT whole lock/preservation UB',
        excludes=['bank-read waiting','downstream ready-low','pre-capture drain','waitAck','dependency timing feedback'])


def packet_contract(bank_ready,outer_ready,ack_cycle=None,cycles=100):
    """Small CPU contract witness, not hardware/runtime evidence.

    Starts with capture at edge0. Observe pre-edge state and separate beatsLeft
    from target-set reservation. Normal SourceA head is continuously pending.
    Used to refute a necessary waitAck->packet-lock dependency.
    """
    state='read'; beat=0; remaining=0; rows=[]
    for cycle in range(1,cycles+1):
        a_valid=state=='send'; lock=remaining>0
        own_a_ready=bool(outer_ready(cycle))
        pres_fire=a_valid and own_a_ready
        normal_fire=own_a_ready and not lock and not a_valid
        rows.append(dict(cycle=cycle,state=state,beat=beat,packet_lock=lock,
            target_set_lock=state!='idle',pres_fire=pres_fire,normal_fire=normal_fire,
            intrinsic_locked_gap=lock and state in ('read','delay1','delay2')))
        if pres_fire:
            remaining=7 if not lock else remaining-1
        if state=='read' and bank_ready(cycle): state='delay1'
        elif state=='delay1': state='delay2'
        elif state=='delay2': state='send'
        elif pres_fire:
            if beat==7: state='waitAck'
            else: beat+=1; state='read'
        if ack_cycle==cycle:
            require(state=='waitAck','ACK before final A beat')
            state='idle'
    return rows


def max_presented_heads_without_dequeue(heads,locked_cycles):
    """Held FIFO head cannot name multiple unique requests during no-dequeue lock."""
    observed={heads[i] for i in locked_cycles if heads[i] is not None}
    require(len(observed)<=1,'FIFO head changed while dequeue forbidden')
    return len(observed)


def analyze_episodes(transactions,roi,prefix,rows):
    cohort=[t for t in transactions if roi[0]<=t['first_c'] and t['ack']<roi[1]]
    summary={name:transfer.exact_distribution([t[b]-t[a] for t in cohort])
        for name,(a,b) in transfer.PHASES.items()}
    intervals=[[t['last_c'],t['first_bank']] for t in cohort]
    duration=iv.duration(intervals)
    require(duration==sum(t['first_bank']-t['last_c'] for t in cohort),'overlapping source6 pre-bank phases')
    control=iv.spans(rows,7,prefix[0],prefix[1])
    scheduler=iv.merge([[x['start'],x['end']] for x in control if transfer.gap.scheduler_unavailable(x['d'])])
    overlap=iv.duration(iv.intersect(iv.intersect(intervals,[prefix]),scheduler))
    wm=[r for r in rows if r['kind']==1]; times=[r['cycle'] for r in wm]
    def incoming_watermark(t):
        if t['ack']>=prefix[1]: return None
        index=bisect_right(times,t['last_c'])-1
        return wm[index]['d'][1] if index>=0 else None
    top=[]
    for t in sorted(cohort,key=lambda t:t['first_bank']-t['last_c'],reverse=True)[:20]:
        top.append(dict(start_cycle=t['last_c'],end_cycle=t['first_bank'],duration=t['first_bank']-t['last_c'],
            episode_kind='OBSERVED_RELEASE_PRE_BANK_PROXY_NOT_PRESERVATION_EPISODE',
            release_first_c=t['first_c'],release_ack=t['ack'],release_owner=t['owner'],
            release_source=t['source'],release_image_seq=t['package_seq'],release_generation=t['generation'],
            line_address=t['line_address'],l2_bank=0,l2_set=(t['line_address']>>6)&1023,
            c_transaction_type='ReleaseData',first_bank_write_cycle=t['first_bank'],
            preservation_seq=None,preservation_source=None,preservation_resident_image=None,
            drain_ready_cycle=None,arbiter_selected_cycle=None,bank_grant_cycle=None,
            outer_a_lock_duration=None,blocked_a_requests=None,blocked_unique_misses=None,
            retries_generated=None,rob_head_overlap=None,eventual_critical_load=None,
            incoming_safe_watermark_at_last_c=incoming_watermark(t),raw_rows=t['raw_rows']))
    categories=Counter(); waits=Counter()
    for t in cohort:
        w=incoming_watermark(t)
        if w is None: continue
        label='incoming_seq_at_or_below_watermark' if t['package_seq']<=w else 'incoming_seq_above_watermark'
        categories[label]+=1; waits[label]+=t['first_bank']-t['last_c']
    return dict(roi_cohort_count=len(cohort),prebank_union=duration,prebank_sum=summary['last_C_to_first_bank']['sum'],
        phase_distributions=summary,prebank_histogram=dict(sorted(Counter(t['first_bank']-t['last_c'] for t in cohort).items())),
        owners={owner:transfer.exact_distribution([t['first_bank']-t['last_c'] for t in cohort if t['owner']==owner]) for owner in ('normal','SVB')},
        top20_release_proxies=top,preservation_episodes=None,outer_a_lock_episodes=None,
        actual_preservation_top20=None,actual_outer_lock_top20=None,
        prebank_prefix_scheduler_overlap=overlap,
        tail_phase_observation=dict(threshold_cycles=55,
            count=sum(t['first_bank']-t['last_c']>=55 for t in cohort),modulus=40,
            first_bank_remainder_histogram=dict(Counter(t['first_bank']%40 for t in cohort if t['first_bank']-t['last_c']>=55)),
            scope='timing pattern only; selected tail threshold, no checkpoint/DRAM or critical causal identification'),
        incoming_watermark_prefix=dict(counts=dict(categories),prebank_durations=dict(waits),
            scope='incoming release image only, NOT overwritten L2 resident image or requester identity'))


SOURCE_RANGES={
 'sifive-cache/design/craft/inclusivecache/src/L2Preservation.scala':[(1,160)],
 'sifive-cache/design/craft/inclusivecache/src/Scheduler.scala':[(110,143),(145,220),(240,275),(312,338),(385,419),(515,551),(722,759),(770,822)],
 'sifive-cache/design/craft/inclusivecache/src/MSHR.scala':[(230,310),(450,490),(798,854)],
 'sifive-cache/design/craft/inclusivecache/src/SourceA.scala':[(30,62)],
 'sifive-cache/design/craft/inclusivecache/src/SinkC.scala':[(78,185)],
 'sifive-cache/design/craft/inclusivecache/src/SourceC.scala':[(79,158)],
 'sifive-cache/design/craft/inclusivecache/src/SourceD.scala':[(86,144),(220,249),(293,353)],
 'sifive-cache/design/craft/inclusivecache/src/BankedStore.scala':[(88,174)],
 'sifive-cache/design/craft/inclusivecache/src/Directory.scala':[(60,123)],
 'sifive-cache/design/craft/inclusivecache/src/Parameters.scala':[(65,94),(150,166)],
 'rocket-chip/src/main/scala/tilelink/Arbiter.scala':[(14,29),(82,130)],
 'rocket-chip/src/main/scala/tilelink/CacheCork.scala':[(53,126),(170,189)],
 'rocket-chip/src/main/scala/tilelink/CacheImage.scala':[(25,63)],
 'rocket-chip/src/main/resources/csrc/cache_opportunity.cc':[(374,382)],
}


def source_audit(generated):
    evidence={}
    for short,ranges in SOURCE_RANGES.items():
        p=ROOT/'chipyard/generators'/short; lines=p.read_text().splitlines()
        evidence[str(p)]=dict(sha256=sha(p),excerpts=[dict(start=a,end=min(b,len(lines)),
            lines=[f'{i}: {lines[i-1]}' for i in range(a,min(b,len(lines))+1)]) for a,b in ranges])
    needles={
        'Scheduler.sv':['beatsLeft <=','idle = beatsLeft','io_a_ready                        (io_out_a_ready',
            'drainForCheckpoint =','assign slowdown_scheduler_stage3_allowed_0 =',
            '.io_bs_adr_ready                   (~_preservation_io_lock_valid',
            '.io_bs_adr_ready                    (_preservation_io_lock_valid',
            '.io_sourceC_adr_valid','clientA_ready ='],
        'L2Preservation.sv':['capture =','_io_a_valid_output =','matches_0 =','assign io_lock_valid =','state <= 3\'h5','state <= {&beat','state == 3\'h2'],
        'SourceA.sv':['Queue_34 io_a_q (','.io_deq_ready','.io_deq_valid','.io_enq_bits_opcode'],
        'Queue_34.sv':['reg  deq_ptr_value;','wire do_deq =','assign io_deq_valid =','assign io_enq_ready =','deq_ptr_value <='],
        'MSHR.sv':['assign io_schedule_bits_a_valid','s_acquire','w_releaseack'],
    }
    texts={}
    for name,ns in needles.items():
        p=generated/'gen-collateral'/name; texts[name]=p.read_text()
        evidence[str(p)]=dict(sha256=sha(p),excerpts=[dict(line=i,text=s) for i,s in enumerate(texts[name].splitlines(),1) if any(n in s for n in ns)])
    l2=(ROOT/'chipyard/generators/sifive-cache/design/craft/inclusivecache/src/L2Preservation.scala').read_text()
    sched=(ROOT/'chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala').read_text()
    sourcea=(ROOT/'chipyard/generators/sifive-cache/design/craft/inclusivecache/src/SourceA.scala').read_text()
    mshr=(ROOT/'chipyard/generators/sifive-cache/design/craft/inclusivecache/src/MSHR.scala').read_text()
    checks=dict(target_lock_until_terminal_ack='io.lock.valid := active || capture' in l2 and 'val active = state =/= idle' in l2,
        final_A_enters_waitAck='when (finalBeat) { state := waitAck }' in l2,
        generated_normal_A_ready_uses_packet_idle_not_target_lock='io_out_a_ready & (idle ? ~_preservation_io_a_valid : state_1)' in texts['Scheduler.sv'],
        generated_packet_beats_count_down_on_A_fire='beatsLeft <= beatsLeft - {2\'h0, io_out_a_ready & slowdown_outer_a_valid};' in texts['Scheduler.sv'],
        generated_target_set_lock_independent='assign io_lock_valid = (|state) | capture;' in texts['L2Preservation.sv'],
        global_SourceC_schedule_block='(!m.io.schedule.bits.c.valid || (!preservation.io.lock.valid && !drainForCheckpoint))' in sched,
        global_SourceC_port_block='sourceC.io.bs_adr.ready := !preservation.io.lock.valid && bankedStore.io.sourceC_adr.ready' in sched,
        generated_SourceC_port_block='(~_preservation_io_lock_valid & _bankedStore_io_sourceC_adr_ready)' in texts['Scheduler.sv'],
        SourceA_only_Acquire='Mux(io.req.bits.block, TLMessages.AcquireBlock, TLMessages.AcquirePerm)' in sourcea,
        Acquire_requires_own_victim_receipt='io.schedule.bits.a.valid := !s_acquire && s_release && w_releaseack && s_pprobe' in mshr,
        normal_source_below_checkpoint_source='assert(sourceA.io.req.bits.source < UInt(InclusiveCacheParameters.out_mshrs(params.cache, params.micro))' in sched,
        generated_SourceA_FIFO2='Queue_34 io_a_q (' in texts['SourceA.sv'] and 'reg  deq_ptr_value;' in texts['Queue_34.sv'],
        generated_FIFO_no_dequeue_without_ready='wire do_deq = io_deq_ready & ~empty;' in texts['Queue_34.sv'])
    require(all(checks.values()),'static/source-generated dependency audit failed: '+str([k for k,v in checks.items() if not v]))
    return evidence,checks


def unknown_bounds(roi,head_miss,head_pending):
    require(0<=head_miss<=head_pending<=roi,'invalid nested head exposure')
    return dict(PRESERVATION_PENDING_UB=dict(value=None,trivial_range=[0,roi]),
        OUTER_A_BLOCKING_UB=dict(value=None,trivial_range=[0,roi]),
        OUTER_A_CRITICAL_UB=dict(value=None,head_miss_intersection_range=[0,head_miss],all_direct_head_pending_range=[0,head_pending]),
        PRESERVATION_CRITICAL_UB=dict(value=None,head_miss_intersection_range=[0,head_miss],all_direct_head_pending_range=[0,head_pending]),
        INDEPENDENT_CACHE_TRANSFER_UB=dict(value=None,deduplicated_direct_head_miss_union_range=[0,head_miss],
            deduplicated_all_direct_head_pending_union_range=[0,head_pending],
            whole_dependency_and_checker_chain='UNKNOWN; no global 80832 or67366 cap'),
        rule='nested overlaps union, never sum; raw overlap alone not removable critical causality')


def analyze(previous):
    # Verify the complete prior report and code, excluding mutable durable docs.
    transfer.gap.audit_hashes({str(previous/p):h for p,h in read(previous/'output_hashes.json').items()})
    prior_prov=read(previous/'provenance.json')
    transfer.gap.audit_hashes({p:h for p,h in prior_prov['input_sha256'].items() if '/AI/TMP/' in p or p.endswith('.py')})
    transfer.gap.audit_hashes(prior_prov['source_generated_sha256'])
    current,transactions=transfer.analyze(transfer.PREVIOUS)
    require(json.loads(json.dumps(current['release']))==read(previous/'numeric_audit.json')['release'],
            'raw reconstruction changed from prior report')
    run=Path(current['inputs']['B_run']); rows,cutoff,capture,offset=iv.read_events(run)
    require(offset==103,'unexpected clock domain')
    ep=analyze_episodes(transactions,current['software_roi'],current['optional_complete_prefix'],rows)
    generated=run.parent.parent/'build'/run.name/'generated'
    sources,checks=source_audit(generated)
    raw_text='\n'.join((run/n).read_text() for n in ['stdout.log','stderr.log','safe_chain_events.tsv'])
    names=['L2_PRESERVE_PENDING','L2_PRESERVE_REQ','L2_PRESERVE_ACK','STAGE3_DRAIN']
    records={n:raw_text.count(n) for n in names}
    require(not any(records.values()),'new preservation events available; missing-evidence report must be revisited')
    gapbound=intrinsic_gap_bound(current['l2']['dram_facing_writes'])
    bounds=unknown_bounds(1648923,current['counts'][transfer.gap.HEAD],current['counts']['rob_head_load_pending_cycles'])
    decision=dict(CURRENT_B_ROI=1648923,TARGET_ROI_EXCLUSIVE=1502513,REQUIRED_SAVING=146411,
        PRESERVATION_PENDING_CYCLES=None,OUTER_A_LOCK_CYCLES=None,OUTER_A_LOCK_EPISODES=None,
        OUTER_A_LOCK_MAX_DURATION=None,OUTER_A_LOCK_P90=None,OUTER_A_LOCK_P99=None,
        OUTER_A_LOCK_WITH_PENDING_REQ=None,OUTER_A_LOCK_ROB_CRITICAL_OVERLAP=None,
        PRESERVATION_ROB_CRITICAL_OVERLAP=None,REQUEST_AMPLIFICATION=None,RETRY_AMPLIFICATION=None,
        INDEPENDENT_CRITICAL_UPPER_BOUND=None,CONSERVATIVE_RECOVERABLE=0,EXPECTED_GAIN=None,
        AMPLIFICATION_PROVEN='NOT_PROVEN',MAIN_MECHANISM='NONE_JUSTIFIED',OPT5_STATUS='NONE_JUSTIFIED',
        SUB1P5_FEASIBILITY='NOT_SUPPORTED',NEXT_ACTION='MOVE_TO_NEXT_OFFLINE_BOTTLENECK',
        NEXT_OFFLINE_MECHANISM='RELEASE_ACQUIRE_HOL_FROM_GLOBAL_SOURCEC_RESERVATION_DURING_CHECKPOINT_WAITACK',
        CHECKER_FRONTEND_PRIORITY='LAST_RESORT',
        REJECTED_SUBHYPOTHESIS='OUTER_A_PACKET_LOCK_SPANS_PRECAPTURE_DRAIN_AND_TERMINAL_ACK',
        INTRINSIC_LOCK_GAP_ONLY_UB=gapbound['cycle_upper_bound'],
        HARDWARE_RUNS_PREPARED=0,HARDWARE_PHASES_EXECUTED=[])
    return dict(previous_report=str(previous),inputs=current['inputs'],decision=decision,episodes=ep,
        software_roi=current['software_roi'],traffic_window=current['traffic_window'],optional_complete_prefix=current['optional_complete_prefix'],
        optional_unknown_suffix_cycles=current['optional_unknown_suffix_cycles'],counts=current['counts'],l2=current['l2'],
        intrinsic_gap_bound=gapbound,upper_bounds=bounds,static_dependency_checks=checks,source_evidence=sources,
        evidence_availability=dict(preservation_named_records=records,
            ringbuffer_dumped=capture['diagnostic_ringbuffer']['dumped'],ringbuffer_file=capture['diagnostic_ringbuffer']['file'],
            discarded_diagnostic_lines=capture['counts']['discarded_diagnostic_lines'],
            schema38='ReleaseData actual bank writes only; not checkpoint bank reads or outer A timestamps',
            stored_observer_kinds=sorted({r['kind'] for r in rows}),
            runtime_preservation_counter_export=False,preservation_or_outer_A_events_reconstructable=False),
        request_amplification_bounds=dict(observed_value=None,presented_to_outer_arb_unique_heads_per_single_lock=[0,1],
            pending_SourceA_FIFO_capacity=2,normal_outer_source_count=2,
            all_inner_requests_or_queued_demand=None,
            retry_factor=None,retry_factor_reason='no associated retry events or blocked-request denominator; may be empty'),
        proposed_T1_T5={name:dict(total_cycles=None,episode_count=None,average=None,median=None,p90=None,p99=None,max=None,top_episodes=None)
            for name in ['last_C_to_preservation_entry','entry_to_eligible','eligible_to_selected','selected_to_bank_grant','bank_grant_to_new_first_write']},
        original_hash_counts=current['revalidated_hash_counts'])


def write_json(path,value):
    path.write_text(json.dumps(value,indent=2,sort_keys=True,ensure_ascii=False)+'\n')


def main():
    p=argparse.ArgumentParser(description=__doc__); p.add_argument('--previous',type=Path,default=PREVIOUS);p.add_argument('--out',type=Path,required=True)
    a=p.parse_args(); require(not a.out.exists(),'output must be a new directory')
    m=analyze(a.previous);a.out.mkdir(parents=True,exist_ok=False)
    render=module('preservation_reports',SCRIPTS/'opt5_preservation_outer_a_reports.py')
    render.write_reports(a.out,m)
    write_json(a.out/'numeric_audit.json',{k:v for k,v in m.items() if k!='source_evidence'})
    write_json(a.out/'source_evidence.json',m['source_evidence'])
    write_json(a.out/'final_decision.json',m['decision'])
    write_json(a.out/'top20_release_proxies.json',m['episodes']['top20_release_proxies'])
    witness=packet_contract(lambda _:True,lambda _:True,ack_cycle=70,cycles=75)
    write_json(a.out/'synthetic_contract_witness.json',dict(kind='CPU_ABSTRACT_CONTRACT_NOT_RUNTIME',trace=witness))
    inputs=[a.previous/n for n in ['output_hashes.json','provenance.json','numeric_audit.json']]
    inputs += [SCRIPTS/n for n in ['analyze_opt5_preservation_outer_a.py','opt5_preservation_outer_a_reports.py','test_opt5_preservation_outer_a.py']]
    inputs += [Path(m['inputs']['B_run'])/n for n in ['capture_summary.json','safe_chain_events.tsv','cache_opportunity.jsonl']]
    write_json(a.out/'provenance.json',dict(input_sha256={str(x):sha(x) for x in inputs},
        source_generated_sha256={p:v['sha256'] for p,v in m['source_evidence'].items()},
        original_hash_counts=m['original_hash_counts'],hardware_phases_executed=[],hardware_sources_modified=0))
    write_json(a.out/'validation_result.json',dict(status='PENDING_CPU_TESTS',required_artifacts=render.REQUIRED,
        hardware_generation='NOT_EXECUTED',verilator_build='NOT_EXECUTED',simulation='NOT_EXECUTED'))
    print(json.dumps(dict(report=str(a.out),decision=m['decision']),ensure_ascii=False))


if __name__=='__main__': main()
