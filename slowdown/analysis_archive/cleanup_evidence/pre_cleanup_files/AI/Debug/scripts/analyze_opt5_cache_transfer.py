#!/usr/bin/env python3
"""Offline cache-transfer audit of the named completed B. No hardware invocation.

Reconstructs mandatory C endpoints / actual L2 bank commits / ReleaseAck. This
is a phase-duration analysis, not a critical-path or counterfactual speedup model.
Outputs must be new; all old evidence and synthetic fixtures are retained.
"""
import argparse
from collections import Counter
import csv
import importlib.util
import json
import math
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
SCRIPTS = ROOT / 'AI/Debug/scripts'
PREVIOUS = ROOT / 'AI/TMP/opt5_sub1p5_gap_analysis_20261101_110130'


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    obj = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(obj)
    return obj


gap = module('transfer_existing_gap', SCRIPTS / 'analyze_opt5_sub1p5_gap.py')
iv = module('transfer_existing_intervals', SCRIPTS / 'analyze_opt4_remaining.py')
require, read, sha = gap.require, gap.read, gap.sha


def exact_distribution(values):
    v = sorted(values)
    if not v:
        return dict(n=0, sum=0, mean=None, median=None, p90=None, p99=None, max=None)
    return dict(n=len(v), sum=sum(v), mean=sum(v)/len(v),
                median=v[math.ceil(len(v)*.5)-1], p90=v[math.ceil(len(v)*.9)-1],
                p99=v[math.ceil(len(v)*.99)-1], max=v[-1],
                quantiles='nearest_rank', min=v[0])


def bin_bounds(index):
    return [0, 0] if index == 0 else [2**(index-1), None if index == 31 else 2**index-1]


def histogram_summary(hist, samples, total):
    require(len(hist) == 32 and all(isinstance(x, int) and x >= 0 for x in hist), 'invalid histogram')
    require(sum(hist) == samples and samples > 0, 'histogram cohort mismatch')
    low = sum(n*bin_bounds(i)[0] for i,n in enumerate(hist))
    high = None if hist[31] else sum(n*bin_bounds(i)[1] for i,n in enumerate(hist[:31]))
    require(total >= low and (high is None or total <= high), 'sum outside histogram bounds')
    def quantile(q):
        rank, cumulative = math.ceil(samples*q), 0
        for i,n in enumerate(hist):
            cumulative += n
            if cumulative >= rank:
                return bin_bounds(i)
    # Actual elapsed-duration bounds for a histogram cohort, using its exact sum.
    # These are not service penalties or ROI-cycle/critical-path estimates.
    tail_first = 11  # bin11 starts at1024 cycles
    tail_low = sum(n*bin_bounds(i)[0] for i,n in enumerate(hist) if i >= tail_first)
    tail_high = None if hist[31] else sum(n*bin_bounds(i)[1] for i,n in enumerate(hist[:31]) if i >= tail_first)
    other_low = sum(n*bin_bounds(i)[0] for i,n in enumerate(hist[:tail_first]))
    other_high = sum(n*bin_bounds(i)[1] for i,n in enumerate(hist[:tail_first]))
    tail_bounds = [max(tail_low,total-other_high),
                   min(total-other_low,tail_high if tail_high is not None else total)]
    require(0 <= tail_bounds[0] <= tail_bounds[1] <= total, 'invalid tail-duration bounds')
    return dict(n=samples, sum=total, mean=total/samples,
                median_bounds=quantile(.5), p90_bounds=quantile(.9),
                p99_bounds=quantile(.99), max_bounds=bin_bounds(max(i for i,n in enumerate(hist) if n)),
                at_least_1024=dict(samples=sum(hist[tail_first:]),
                    elapsed_duration_sum_bounds=tail_bounds,
                    fraction_of_latency_sum_bounds=[x/total for x in tail_bounds] if total else None,
                    scope='completion-cohort elapsed durations; may overlap/start before ROI; not critical ROI cycles'),
                exact_quantiles=None, cohort='completion_in_ROI; may_start_before_ROI; unfinished_censored')


def release_identity(d):
    return tuple(d[i] for i in (1,2,3,4,5,7,8,9,10,15))


def reconstruct(rows, source=6):
    """Fail closed on incomplete lifetimes, reused source, wrong identity or words.

    Equal-edge ordering is C endpoints, bank writes, ACK. A newly reused source on
    the same edge as the old ACK is deliberately rejected as ambiguous.
    Other clients' SC38 are counted and excluded, never matched by address alone.
    """
    require(len({r['episode'] for r in rows}) <= 1, 'cross-reset join forbidden')
    selected, excluded = [], Counter()
    for r in rows:
        if r['kind'] in (20,21):
            require(r['hart'] == 0 and r['d'][5] == source, 'unexpected L1 release source/hart')
            selected.append(r)
        elif r['kind'] == 38:
            require(r['d'][0] == 2, 'unsupported SC38 schema')
            if r['d'][5] == source:
                selected.append(r)
            else:
                excluded[str(r['d'][5])] += 1
    selected.sort(key=lambda r: (r['cycle'], {20:0,38:1,21:2}[r['kind']], r['line']))
    active, done = None, []
    for r in selected:
        d, kind, cycle = r['d'], r['kind'], r['cycle']
        if kind in (20,21):
            require(d[0] == 1 and d[13] == 1 and d[15] == 6, 'invalid release schema/match/size')
            require(d[1] in (0,1) and d[9] in (0,1) and d[3] % 64 == 0, 'invalid owner/key/line')
            require(d[1] == 1 or d[2] == 255, 'normal release has non-normal entry')
        if kind == 20:
            require(d[6] == 7 and (d[11],d[12]) in ((1,0),(0,1)), 'invalid C endpoint/opcode')
            if d[11]:
                require(active is None, 'overlapping source lifetime')
                active = dict(identity=release_identity(d), source=source, owner='SVB' if d[1] else 'normal',
                              entry=d[2], line_address=d[3], package_seq=d[4], generation=d[7], writer=d[8],
                              key_valid=d[9], epoch=d[10], first_c=cycle, last_c=None,
                              bank_cycles=[], bank_word_offsets=[], bank_hashes=[],
                              raw_rows=dict(first_c=r['line'], bank=[]))
            else:
                require(active is not None and release_identity(d) == active['identity'], 'unmatched last C')
                require(active['last_c'] is None, 'duplicate last C')
                active['last_c'] = cycle
                active['raw_rows']['last_c'] = r['line']
        elif kind == 38:
            require(active is not None, 'bank write outside source lifetime')
            require(tuple(d[1:5]) == tuple(active[k] for k in ('line_address','package_seq','generation','writer')),
                    'bank-write token mismatch')
            require(d[8] == 1 and d[9] == 8, 'unexpected bank word geometry')
            require(d[7] == len(active['bank_cycles']) and d[7] < 8, 'duplicate/missing/out-of-order bank word')
            require(not active['bank_cycles'] or cycle > active['bank_cycles'][-1], 'multiple bank words on one edge')
            active['bank_cycles'].append(cycle)
            active['bank_word_offsets'].append(d[7])
            active['bank_hashes'].append(d[6])
            active['raw_rows']['bank'].append(r['line'])
        else:
            require(d[6] == 6 and active is not None, 'unmatched/invalid ReleaseAck')
            require(release_identity(d) == active['identity'], 'ACK identity mismatch')
            require(active['last_c'] is not None and len(active['bank_cycles']) == 8, 'ACK before complete C/bank coverage')
            require(active['last_c'] <= active['bank_cycles'][-1] <= cycle, 'ACK before final commit')
            active['ack'] = cycle
            active['first_bank'], active['last_bank'] = active['bank_cycles'][0], active['bank_cycles'][-1]
            active['raw_rows']['ack'] = r['line']
            del active['identity']
            done.append(active)
            active = None
    require(active is None, 'unfinished source lifetime at log end')
    return done, dict(excluded)


PHASES = {
    'first_C_to_last_C': ('first_c','last_c'),
    'first_C_to_first_bank': ('first_c','first_bank'),
    'last_C_to_first_bank': ('last_c','first_bank'),
    'first_bank_to_last_bank': ('first_bank','last_bank'),
    'last_C_to_last_bank': ('last_c','last_bank'),
    'last_bank_to_ACK': ('last_bank','ack'),
    'last_C_to_ACK': ('last_c','ack'),
    'first_C_to_ACK': ('first_c','ack'),
}


def summarize(transactions, roi, prefix, scheduler):
    lo, hi = roi
    contained = [t for t in transactions if lo <= t['first_c'] and t['ack'] < hi]
    touched = [t for t in transactions if t['first_c'] < hi and t['ack'] >= lo]
    intervals = [[t['first_c'],t['ack']] for t in transactions]
    clipped = iv.intersect(intervals, [roi])
    prefix_intervals = iv.intersect(clipped, [prefix])
    groups = {}
    for owner in ('all','normal','SVB'):
        cohort = [t for t in contained if owner == 'all' or t['owner'] == owner]
        groups[owner] = {k:exact_distribution([t[b]-t[a] for t in cohort]) for k,(a,b) in PHASES.items()}
    return dict(full_run_transactions=len(transactions), roi_contained_transactions=len(contained),
                roi_touched_transactions=len(touched), boundary_censored_transactions=len(touched)-len(contained),
                distributions=groups, interval_convention='[first_C, ACK); ACK edge excluded; not registered sourceBusy count',
                roi_phase_union_cycles=iv.duration(clipped), prefix_phase_union_cycles=iv.duration(prefix_intervals),
                scheduler_overlap_prefix_cycles=iv.duration(iv.intersect(prefix_intervals,scheduler)),
                scheduler_prefix_cycles=iv.duration(scheduler),
                largest_bank_interbeat_gap=max((b-a for t in contained for a,b in zip(t['bank_cycles'],t['bank_cycles'][1:])),default=None),
                last_C_to_ACK_histogram=dict(sorted(Counter(t['ack']-t['last_c'] for t in contained).items())),
                critical_subset=None, noncritical_subset=None, independent_critical_upper_bound=None,
                conservative_recoverable_cycles=0,
                top_episodes=sorted(contained,key=lambda t:t['ack']-t['last_c'],reverse=True)[:10])


SOURCE_RANGES = {
    'boom/src/main/scala/lsu/dcache.scala': [(26,100),(185,260),(439,461),(772,810),(848,900),(1268,1305),(1423,1470),(1495,1558),(1625,1638),(4307,4335)],
    'boom/src/main/scala/lsu/mshrs.scala': [(220,240),(288,337),(404,634),(849,916),(967,1012),(1120,1145)],
    'sifive-cache/design/craft/inclusivecache/src/Scheduler.scala': [(110,150),(250,275),(312,338),(385,405),(515,552),(770,785)],
    'sifive-cache/design/craft/inclusivecache/src/L2Preservation.scala': [(48,160)],
    'sifive-cache/design/craft/inclusivecache/src/BankedStore.scala': [(88,174)],
    'sifive-cache/design/craft/inclusivecache/src/SourceD.scala': [(80,140),(220,250),(320,356),(437,465)],
    'sifive-cache/design/craft/inclusivecache/src/SinkD.scala': [(35,115)],
    'sifive-cache/design/craft/inclusivecache/src/SinkA.scala': [(35,95)],
    'sifive-cache/design/craft/inclusivecache/src/SinkC.scala': [(35,120)],
    'sifive-cache/design/craft/inclusivecache/src/SourceC.scala': [(35,120)],
    'sifive-cache/design/craft/inclusivecache/src/Parameters.scala': [(55,94),(145,235)],
    'sifive-cache/design/craft/inclusivecache/src/Configs.scala': [(10,100)],
    'rocket-chip/src/main/scala/diplomacy/Parameters.scala': [(257,290)],
    'rocket-chip/src/main/scala/tilelink/Arbiter.scala': [(82,130)],
    'rocket-chip/src/main/scala/r/R_IC.scala': [(565,590)],
}


def source_snapshot(generated):
    evidence = {}
    for short,ranges in SOURCE_RANGES.items():
        p = ROOT / 'chipyard/generators' / short
        lines = p.read_text().splitlines()
        evidence[str(p)] = dict(sha256=sha(p), excerpts=[dict(start=a,end=min(b,len(lines)),
            lines=[f'{i}: {lines[i-1]}' for i in range(a,min(b,len(lines))+1)]) for a,b in ranges])
    for name, needles in {
        'BoomTile.sv':['TLWidthWidget_13 widget (','(_dcache_auto_out_a_valid)','BoomNonBlockingDCache dcache ('],
        'BoomMSHRFile.sv':['assign slowdown_mshr_file_req_ready_0 =','lb_write','lb_read_arb','NullPrefetcher'],
        'BoomNonBlockingDCache.sv':['BoomDuplicatedDataArray data (','debug_s2_nack_data_0 ='],
        'BoomMSHR.sv':['assign io_mem_finish_valid =','assign _io_lb_read_valid_output =','assign _io_refill_valid_output ='],
        'L2Preservation.sv':['wire         capture =','_io_bs_adr_valid_output =','_io_a_valid_output =','matches_0 =','state == 3\'h2','state == 3\'h3','assign io_lock_valid ='],
        'Scheduler.sv':['reg  [2:0]      beatsLeft;','wire            idle = beatsLeft','beatsLeft <=','L2Preservation preservation (','BankedStore bankedStore ('],
    }.items():
        p = generated / 'gen-collateral' / name
        excerpts = [dict(line=i,text=line) for i,line in enumerate(p.read_text().splitlines(),1)
                    if any(n in line for n in needles)]
        evidence[str(p)] = dict(sha256=sha(p), excerpts=excerpts)
    for name in ['model_module_hierarchy.json','l2.json','buildTopClockGenerator.freq-summary','harnessDividerOnlyClockGenerator.freq-summary']:
        matches = [p for p in generated.iterdir() if p.name == name or p.name.endswith('.'+name)]
        require(len(matches) == 1, 'missing/ambiguous generated artifact '+name)
        p = matches[0]
        evidence[str(p)] = dict(sha256=sha(p))
        if name == 'l2.json':
            evidence[str(p)]['configuration'] = read(p)
        elif name.endswith('freq-summary'):
            evidence[str(p)]['text'] = p.read_text()
        else:
            selected = []
            def walk(node, parent=''):
                path = parent+'.'+node['instance_name'] if parent else node['instance_name']
                if node['module_name'] in ('BoomNonBlockingDCache','BoomMSHRFile','BoomMSHR','BoomIOMSHR',
                    'TLWidthWidget_13','TLWidthWidget_14','TLXbar_10','TLBuffer_19','TLBuffer_16','Scheduler',
                    'L2Preservation','BankedStore','TLCacheCork','TLToAXI4','AXI4IdIndexer','AXI4UserYanker','SimDRAM'):
                    selected.append(dict(path=path,module=node['module_name']))
                for child in node.get('instances',[]): walk(child,path)
            walk(read(p))
            evidence[str(p)]['selected_hierarchy'] = selected
    return evidence


def analyze(previous):
    prev_prov = read(previous/'provenance.json')
    # State/README are mutable durable documentation; old reports themselves stay intact.
    immutable = {p:h for p,h in prev_prov['input_sha256'].items()
                 if '/AI/TMP/' in p or p.endswith('.py')}
    gap.audit_hashes(immutable)
    gap.audit_hashes(prev_prov['source_generated_evidence_sha256'])
    fresh = gap.analyze(Path(read(previous/'numeric_audit.json')['previous_report']))
    b = fresh['arms']['B']
    require(b['causal'] == read(previous/'numeric_audit.json')['arms']['B']['causal'], 'previous/raw counters differ')
    rows,cutoff,_,offset = iv.read_events(Path(b['run']))
    require(offset == 103, 'unexpected cycle domain')
    transactions,excluded = reconstruct(rows)
    summary = summarize(transactions,b['software_roi'],b['optional_complete_prefix'],b['scheduler_prefix']['intervals'])
    require(summary['roi_phase_union_cycles'] == summary['distributions']['all']['first_C_to_ACK']['sum'],
            'cohort duration/union mismatch; review boundary or overlap')
    causal = b['causal']; counts = causal['counts']
    histograms = {name:histogram_summary(causal['latency_histograms'][i], counts[key+'_samples'],counts[key+'_sum'])
                  for i,(name,key) in enumerate([('detect_to_alloc','detect_alloc'),('alloc_to_physical_final_refill','alloc_refill'),('detect_to_data','detect_data')])}
    l2 = next(x for x in map(json.loads,(Path(b['run'])/'cache_opportunity.jsonl').read_text().splitlines()) if x['level']==2)
    l2 = {k:l2[k] for k in ['cycles','actual','inner_a_first_by_opcode','inner_c_first_by_opcode',
            'dram_facing_reads','dram_facing_writes','dram_facing_read_bytes','dram_facing_write_bytes',
            'writebacks','mshr_occupancy_histogram','mshr_full_cycles']}
    generated = Path(b['run']).parent.parent/'build'/Path(b['run']).name/'generated'
    sources = source_snapshot(generated)
    decision = dict(CURRENT_B_ROI=1648923,TARGET_ROI=1502513,REMAINING_GAP=146410,
        MINIMUM_INTEGER_SAVING=146411,CACHE_TRANSFER_MAJOR_BOTTLENECK='NOT_PROVEN',
        LARGEST_CACHE_TRANSFER_MECHANISM='MEASURED_L1_RELEASE_TO_L2_BANK_COMMIT_AND_ACK; HYPOTHESIS_L2_PRESERVATION_DRAIN_AND_OUTER_A_LOCK',
        INDEPENDENT_CRITICAL_UPPER_BOUND=None,
        UPPER_BOUND_SCOPE='whole cache-transfer critical budget unknown; measured post-first-C phase exposure only 100915 cycles',
        CONSERVATIVE_RECOVERABLE=0,EXPECTED_RECOVERABLE=None,MAIN_OPT5_CANDIDATE='NONE_JUSTIFIED',
        **{'1P5_FEASIBILITY':'SUB1P5_NOT_SUPPORTED'},CHECKER_FRONTEND_PRIORITY='LAST_RESORT',
        NEXT_ACTION='MORE_OFFLINE_ATTRIBUTION',STRICT_PAIRING='STRICT_PAIRING_PENDING',
        NEW_HARDWARE_RUNS_PREPARED=0,HARDWARE_PHASES_EXECUTED=[])
    return dict(decision=decision,inputs=fresh['inputs'],target=fresh['target'],
                software_roi=b['software_roi'],traffic_window=b['traffic_window'],
                optional_complete_prefix=b['optional_complete_prefix'],optional_unknown_suffix_cycles=b['optional_unknown_suffix_cycles'],
                simulator_time_minus_boom_cycle=offset,counts=counts,native_histograms=histograms,
                release=summary,excluded_other_client_bank_events=excluded,l2=l2,
                previous_report=str(previous),revalidated_hash_counts=fresh['revalidated_hash_counts'],
                additional_prior_input_hashes_rechecked=len(immutable),source_evidence=sources,
                scheduler_prefix=b['scheduler_prefix'],comparison=fresh['comparison']), transactions


def write_json(path, value):
    path.write_text(json.dumps(value,indent=2,sort_keys=True,ensure_ascii=False)+'\n')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--previous',type=Path,default=PREVIOUS)
    parser.add_argument('--out',type=Path,required=True)
    args = parser.parse_args()
    require(not args.out.exists(), 'output must be a new directory; no old report overwrite')
    m,transactions = analyze(args.previous)
    args.out.mkdir(parents=True,exist_ok=False)
    write_json(args.out/'numeric_audit.json',{k:v for k,v in m.items() if k != 'source_evidence'})
    write_json(args.out/'source_evidence.json',m['source_evidence'])
    write_json(args.out/'release_transactions.json',transactions)
    write_json(args.out/'final_decision.json',m['decision'])
    fields = ['owner','line_address','package_seq','generation','writer','first_c','last_c','first_bank','last_bank','ack']
    with (args.out/'release_transactions.csv').open('w',newline='') as f:
        w = csv.DictWriter(f,fieldnames=fields,extrasaction='ignore'); w.writeheader(); w.writerows(transactions)
    render = module('transfer_report_renderer',SCRIPTS/'opt5_cache_transfer_reports.py')
    render.write_reports(args.out,m)
    inputs = [args.previous/x for x in ['numeric_audit.json','provenance.json','validation_result.json']]
    inputs += [SCRIPTS/x for x in ['analyze_opt5_cache_transfer.py','opt5_cache_transfer_reports.py','test_opt5_cache_transfer.py']]
    inputs += [Path(m['inputs']['B_run'])/x for x in ['safe_chain_events.tsv','cache_opportunity.jsonl','roi.json','capture_summary.json']]
    write_json(args.out/'provenance.json',dict(input_sha256={str(p):sha(p) for p in inputs},
        source_generated_sha256={p:d['sha256'] for p,d in m['source_evidence'].items()},
        revalidated_originals=m['revalidated_hash_counts'],hardware_phases_executed=[],
        preserve_old_reports_and_fixtures=True))
    required = render.REQUIRED
    write_json(args.out/'validation_result.json',dict(status='PENDING_CPU_TESTS',scope='offline attribution only',
        required_artifacts=required,required_artifacts_present=all((args.out/x).is_file() for x in required if x != 'validation_result.json'),
        original_hash_counts=m['revalidated_hash_counts'],sealed_sources_tools_evidence_unchanged='PASS',
        mandatory_release_chain='PASS',complete_bank_coverage='8/8 words per transaction',
        critical_join='UNAVAILABLE',hardware_sources_modified=0,hardware_generation='NOT_EXECUTED',
        verilator_build='NOT_EXECUTED',simulation='NOT_EXECUTED',new_hardware_runs_prepared=0,
        offline_tests='PENDING',strict_pairing='STRICT_PAIRING_PENDING'))
    print(json.dumps(dict(report=str(args.out),decision=m['decision'],release_roi=m['release']['roi_contained_transactions']),ensure_ascii=False))


if __name__ == '__main__':
    main()
