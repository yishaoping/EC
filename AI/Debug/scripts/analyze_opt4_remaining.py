#!/usr/bin/env python3
"""Read-only Opt4 fixed-trace opportunity analysis; never launches hardware.

Missing/sampled states remain unknown. Activity/exposure/critical path are not
interchangeable, and no additive decomposition of the baseline delta is made.
"""
import argparse
from collections import Counter, defaultdict
import hashlib
import importlib.util
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
DEFAULT_RUN = ROOT/'slowdown/optimization_4_svb/runs/optimization_4_svb_20261030_072604_18475a92'
MAX_OPTIONAL_RECORD = 448  # 6 uint64 decimal labels, 16 hex64 words, separators


def optional(kind, hart):
    return kind == 1 or (4 <= kind <= 15 and kind != 10) or (kind == 16 and hart != 0)


def merge(intervals):
    out = []
    for a, b in sorted((a, b) for a, b in intervals if a < b):
        if out and a <= out[-1][1]:
            out[-1][1] = max(b, out[-1][1])
        else:
            out.append([a, b])
    return out


def duration(intervals):
    return sum(b-a for a, b in merge(intervals))


def intersect(left, right):
    a, b = merge(left), merge(right)
    out, i, j = [], 0, 0
    while i < len(a) and j < len(b):
        lo, hi = max(a[i][0], b[j][0]), min(a[i][1], b[j][1])
        if lo < hi:
            out.append([lo, hi])
        if a[i][1] <= b[j][1]:
            i += 1
        else:
            j += 1
    return out


def distribution(values):
    values = sorted(values)
    if not values:
        return {'n': 0}
    return dict(n=len(values), min=values[0], mean=sum(values)/len(values),
                p50=values[(len(values)-1)//2], p95=values[(len(values)-1)*95//100], max=values[-1])


def read_events(run):
    capture = json.loads((run/'capture_summary.json').read_text())
    budget = capture['event_budgets']['diagnostic']
    rows, used, guaranteed_time, previous_time = [], 0, None, -1
    for lineno, raw in enumerate((run/'safe_chain_events.tsv').open(), 1):
        p = raw.rstrip('\n').split('\t')
        if p[0] != 'SC1':
            continue
        if len(p) != 23:
            raise ValueError(f'malformed event {lineno}')
        time, cycle, local, episode, kind, hart = map(int, p[1:7])
        if time < previous_time:
            raise ValueError('nonmonotone transport timestamps; prefix proof unavailable')
        previous_time = time
        if optional(kind, hart):
            if len(raw.encode()) > MAX_OPTIONAL_RECORD:
                raise ValueError('record exceeds proven schema length bound')
            # Before this byte threshold a missing record cannot have exhausted
            # the host diagnostic reservation. Exclude the boundary edge itself.
            if used <= budget-MAX_OPTIONAL_RECORD:
                guaranteed_time = time
            used += len(raw.encode())
        rows.append(dict(time=time, cycle=cycle, local=local, episode=episode,
                         kind=kind, hart=hart, d=[int(v, 16) for v in p[7:]], line=lineno))
    if len({r['episode'] for r in rows}) != 1:
        raise ValueError('cross-reset association forbidden')
    anchors = {r['time']-r['cycle'] for r in rows if r['hart']==0 and r['kind'] in (2,8,10,19,25,31)}
    if len(anchors) != 1:
        raise ValueError('main timestamp/cycle offset is not unique')
    offset = anchors.pop()
    cutoff = guaranteed_time-offset
    if not capture['optional_records_omitted']:
        cutoff = max(r['cycle'] for r in rows)
    return rows, cutoff, capture, offset


def spans(rows, kind, start, stop):
    seq = sorted((r for r in rows if r['kind']==kind and r['hart']==0), key=lambda r:r['cycle'])
    if not seq or seq[0]['cycle'] > start:
        raise ValueError('missing initial state')
    out = []
    for i, r in enumerate(seq):
        a = max(start,r['cycle'])
        b = min(stop,seq[i+1]['cycle'] if i+1<len(seq) else stop)
        if a < b:
            out.append(dict(start=a,end=b,d=r['d'],source_line=r['line']))
    return out


def analyze(run):
    run = run.resolve()
    spec = importlib.util.spec_from_file_location('opt4_svb_remaining', ROOT/'slowdown/optimization_4_svb/analysis/analyze_svb.py')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    summary = module.run_summary(run)
    integrity = module.integrity_ledger.build(module.parse_events(run/'safe_chain_events.tsv'))
    if integrity['status'] != 'PASS':
        raise ValueError('closed lifecycle ledger required')
    roi = json.loads((run/'roi.json').read_text())
    start, stop = roi['start_cycle'], roi['stop_cycle']
    rows, cutoff, capture, offset = read_events(run)
    cutoff = min(cutoff,stop)
    boundaries = [r for r in rows if r['kind']==10 and r['d'][1]]
    tstart = boundaries[0]['cycle']
    tstop = next(r['cycle'] for r in rows if r['kind']==30)
    pending = spans(rows,8,start,cutoff)
    control = spans(rows,7,start,cutoff)
    pstats, cstats = Counter(), Counter()
    psets, csets, episodes = defaultdict(list), defaultdict(list), defaultdict(list)
    for s in pending:
        a,b,d = s['start'],s['end'],s['d']
        if not d[9]&1:
            continue
        for name,condition in [('pending',True),('unsafe',not d[9]&2),('safe',bool(d[9]&2))] + [
                (name,bool(d[9]&(1<<bit))) for bit,name in ((3,'issued'),(4,'meta_clear'),(5,'mshr'),(6,'slot'),
                    (7,'drain'),(8,'completion'),(9,'probe'),(23,'exception'),(24,'kill'))]:
            if condition:
                pstats[name] += b-a
                psets[name].append([a,b])
        episodes[d[0]].append(s)
    for s in control:
        a,b,d = s['start'],s['end'],s['d'];f=d[2];fsm=d[3]>>3
        fields = [(f'fsm_{fsm}',True),('scheduler_unavailable',fsm==2 and not f&(1<<6)),
                  ('snapshot_wait',fsm==4),('transfer',fsm==5),
                  ('snapshot_rob_nonempty',fsm in (3,4) and not f&(1<<10)),
                  ('snapshot_rob_empty',fsm in (3,4) and bool(f&(1<<10))),
                  ('barrier_close',bool(f&(1<<12))),('rsu_busy',bool(f&(1<<4)))]
        for name,condition in fields:
            if condition:
                cstats[name] += b-a;csets[name].append([a,b])
    # Capture/terminal events update registers after the sampled edge. Rebuild
    # pre-edge occupancy using next-cycle boundaries, then check every bin.
    actions = defaultdict(int)
    for x in integrity['lifecycles']:
        actions[x['capture_cycle']+1] += 1
        actions[x['free_cycle']+1] -= 1
    hist = [0]*17;occ=0;last=tstart;full=[];active_sets={}
    for c in sorted(set(actions)|{tstart,tstop}):
        if c > tstart and last < tstop:
            lo,hi=max(last,tstart),min(c,tstop)
            if lo<hi:
                hist[occ] += hi-lo
                if occ==16:full.append([lo,hi])
        occ += actions[c];last=c
    l1 = next(x for x in summary['cache_opportunity']['models'] if x['level']==1)
    if hist != l1['shadow_8_capacity']['occupancy_histogram']:
        raise ValueError('lifecycle reconstruction disagrees with full histogram')
    full_episodes=[]
    for entry,es in episodes.items():
        interval=[min(s['start'] for s in es),max(s['end'] for s in es)]
        if intersect([interval],full):
            full_episodes.append(dict(entry=entry,start=interval[0],end=interval[1],cycles=interval[1]-interval[0],
                target=es[0]['d'][1],line=hex(es[0]['d'][13]),
                unsafe_cycles=sum(s['end']-s['start'] for s in es if not s['d'][9]&2)))
    # Conservative local ceiling includes every legacy episode overlapping full,
    # not just its unsafe subinterval; do not claim global timing feedback proof.
    svb32_ceiling=sum(e['cycles'] for e in full_episodes)
    if summary['svb']['full_fallback']!=1 or len(full_episodes)!=1:
        svb32_ceiling=None
    waits=[];promotion=[];safe_exposure=[];promlat=[];captlat=[]
    for x in integrity['lifecycles']:
        safe=x.get('safe_cycle');prom=x.get('promotion_cycle');free=x['free_cycle']+1
        if safe is not None:
            a,b=max(start,safe),min(stop,free)
            safe_exposure.append([a,b])
            waits.append([a,min(b,prom if prom is not None else free)])
        if prom is not None:
            promotion.append([max(start,prom),min(stop,free)])
            promlat.append(x['completion_cycle']-prom)
            captlat.append(prom-x['capture_cycle'])
    cache=[]
    for level in summary['cache_opportunity']['models']:
        st=level['models'][0]['stats'];busy=sum(level['mshr_occupancy_histogram'][1:]);weighted=sum(i*n for i,n in enumerate(level['mshr_occupancy_histogram']))
        cache.append(dict(level=level['level'],actual=level['actual'],s0_pass=level['geometry_decision_eligible'],
            mshr_busy_cycles=busy,mshr_entry_cycles=weighted,mshr_full_cycles=level['mshr_full_cycles'],
            entry_cycles_per_miss_ratio=(weighted/level['actual']['miss'] if level['level']==1 else None),
            models=[dict(name=m['name'],sets=m['sets'],ways=m['ways'],capacity_bytes=m['capacity_bytes'],
                **m['stats'],miss_reduction=(st['miss']-m['stats']['miss'] if level['geometry_decision_eligible'] else None),
                miss_reduction_percent=(100*(st['miss']-m['stats']['miss'])/st['miss'] if level['geometry_decision_eligible'] else None),
                raw_replacement_delta=(st['replacement']-m['stats']['replacement'] if level['geometry_decision_eligible'] else None),
                equal_service_proxy_cycles=((st['miss']-m['stats']['miss'])*weighted/level['actual']['miss'] if level['level']==1 and level['geometry_decision_eligible'] else None)) for m in level['models']]))
    full_safe=[]
    for a,b in full:
        owners=[x for x in integrity['lifecycles'] if x['capture_cycle']<a and x['free_cycle']>=a]
        full_safe.append(dict(start=a,end=b,owners=len(owners),
            safe_before_full=sum(x.get('safe_cycle') is not None and x['safe_cycle']<a for x in owners),
            first_safe_cycle=min((x['safe_cycle'] for x in owners if x.get('safe_cycle') is not None),default=None)))
    stats=dict(run=str(run),baseline_roi=1001675,opt3_roi=2928347,opt4_roi=stop-start,remaining_cycles=stop-start-1001675,
        performance_valid=summary['performance_valid'],correctness=summary['correctness'],
        interval_policy='half-open pre-edge main cycles; raw simulator time = CSR cycle + '+str(offset),
        traffic_window=[tstart,tstop],software_roi=[start,stop],optional_complete_prefix=[start,cutoff],
        optional_unknown_suffix_cycles=stop-cutoff,optional_records_omitted=capture['optional_records_omitted'],
        pressure=summary['traffic_pressure_counters'],svb=summary['svb'],source_stats=summary['source_stats'],
        legacy_pending_prefix=dict(pstats),control_prefix=dict(cstats),
        overlaps_prefix={name:duration(intersect(psets['pending'],cs)) for name,cs in csets.items()},
        svb_full_intervals=full,svb_full_owner_safety=full_safe,full_overlapping_legacy_episodes=full_episodes,
        svb32_fixed_trace_local_ceiling_cycles=svb32_ceiling,
        promotion=dict(safe_wait_union_cycles=duration(waits),inflight_union_cycles=duration(promotion),
            safe_to_terminal_union_cycles=duration(safe_exposure),latency=distribution(promlat),
            capture_to_issue_latency=distribution(captlat),
            safety_exposure_overlapping_legacy_prefix_cycles=duration(intersect(safe_exposure,psets['pending']))),
        cache=cache,rob_critical_path='UNOBSERVED',exact_lsu_stalls='UNOBSERVED',
        original_waitsafe_raw_cycles='UNOBSERVED; bypass count is not raw condition cycles',
        counterfactual_policy='no additive delta allocation; proxy is not a bound, observed activity is not avoidable loss',
        next_optimization='NONE_JUSTIFIED',decision='NEXT_OPTIMIZATION_NOT_YET_JUSTIFIED')
    return stats,summary,dict(pending=pending,control=control)


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--run',type=Path,default=DEFAULT_RUN)
    p.add_argument('--out',type=Path,required=True)
    a=p.parse_args();a.out.mkdir(parents=True,exist_ok=True)
    metrics,summary,spans_out=analyze(a.run)
    for name,data in [('metrics.json',metrics),('corrected_summary.json',summary),('reconstructed_intervals.json',spans_out)]:
        path=a.out/name
        if path.exists():raise ValueError('refusing to overwrite '+str(path))
        path.write_text(json.dumps(data,indent=2,sort_keys=True)+'\n')
    print(json.dumps({k:metrics[k] for k in ('decision','remaining_cycles','svb32_fixed_trace_local_ceiling_cycles','promotion','control_prefix','legacy_pending_prefix')},indent=2))

if __name__=='__main__':main()
