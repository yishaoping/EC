"""Offline Opt3 checker counters and fused-classification evidence; never executes hardware tools.

SC1 timestamps are pre-edge samples. Counts partition local edges AFTER
admission and BEFORE the first exec_done sample. Raw predicates overlap.
ECP/ARF epoch, cache image generation and slot epoch are separate namespaces.
"""
import argparse
import json
import math
import statistics
from collections import Counter, defaultdict
from pathlib import Path
import sys

# Keep the standalone analyzer usable with Python's isolated (-I) mode too.
sys.path.insert(0, str(Path(__file__).resolve().parent))

from compact_causality import align_clocks, bit, read_events
from optimization2_comparison import extend_analysis as extend_safe_chain
from compact_causality import EXPECTED

OPT2 = 4707273
OPT2B = 3760243
ORIGINAL = 4734881
BASELINE = 1001675
CATEGORIES = ('EXEC_ACTIVE', 'WAIT_INSTRUCTION', 'WAIT_LSL', 'WAIT_MEMORY',
              'WAIT_DEPENDENCY', 'WAIT_REPLAY', 'WAIT_CONTROL',
              'WAIT_RESULT_RESOURCE', 'OTHER')
FRONTEND = ('live', 'empty', 'fetching', 'classify', 'wait_bjl', 'ready',
            'emitted', 'handoff', 'requests', 'fq_backpressure', 'fault_emits',
            'icache_acquires', 'tlb_miss', 'redirects')


def distribution(values):
    values = sorted(values)
    if not values:
        return dict(n=0, mean=None, median=None, p95=None, p99=None, max=None)
    return dict(n=len(values), mean=statistics.mean(values),
                median=statistics.median(values), min=values[0], max=values[-1],
                p95=values[math.ceil(.95*len(values))-1],
                p99=values[math.ceil(.99*len(values))-1])


def counter_partition(row):
    d = row['d']
    if sum(d[4:13]) != d[3]:
        raise ValueError('kind11 category conservation failed')
    if d[11]:
        raise ValueError('result-resource wait must be outside execution partition')
    if d[14] > d[13] or d[15] > d[13]:
        raise ValueError('retired memory counts exceed retired instructions')
    return dict(zip(CATEGORIES, d[4:13]))


def decode_checker(rows, roi):
    """Return fully observed packages, censored packages and hard errors.

    A terminal counter pair must join the SAME kind6 edge and owned ECP
    sequence. Initial ROI-active packages remain censored, never fabricated.
    """
    errors, censored, result = [], [], []
    admissions, executions, control = {}, defaultdict(list), {}
    streams = defaultdict(lambda: defaultdict(list))
    owners = defaultdict(set)
    for r in rows:
        h, d = r['hart'], r['d']
        if r['kind'] == 6:
            control[h, r['time'], r['local']] = r
            if bit(d[2], 20) and d[14]:
                key = h, d[14]
                if key in admissions:
                    errors.append('repeated package admission '+str(key))
                admissions[key] = r
            if d[0] and bit(d[2], 8):
                executions[h, d[0]].append(r)
        if r['kind'] in (11, 12) and d[0]:
            streams[h, d[0]][r['kind']].append(r)
            owners[d[0]].add(h)
            if r['kind'] == 11:
                try:
                    counter_partition(r)
                except ValueError as exc:
                    errors.append(str(exc)+' '+str((h, d[0], r['local'])))
    for s, hs in owners.items():
        if len(hs) != 1:
            errors.append('sequence assigned to multiple checker harts '+str(s))
    for (h, s), ks in sorted(streams.items()):
        a = admissions.get((h, s))
        finals = [r for r in ks[11] if bit(r['d'][2], 1)]
        if len(finals) > 1:
            errors.append('duplicate result counter terminal '+str((h, s)))
            continue
        if not finals:
            censored.append(dict(checker=h, seq=s, reason='no result terminal in capture'))
            continue
        end = finals[0]
        d = end['d']
        status = (d[2] >> 3) & 3
        if status or bit(d[2], 2):
            errors.append('FAIL/CANCELLED checker result '+str((h, s, status)))
            continue
        peers = [r for r in ks[12] if r['time'] == end['time'] and r['local'] == end['local']]
        c = control.get((h, end['time'], end['local']))
        if len(peers) != 1 or c is None:
            errors.append('missing exact kind11/kind12/kind6 terminal join '+str((h, s)))
            continue
        p = peers[0]['d']
        cd = c['d']
        if (p[:3] != d[:3] or cd[0] != s or not bit(cd[2], 16) or
                cd[9] != s or cd[1] != d[1] or (cd[7] & 0xffffffff) != s or
                ((cd[7] >> 32) & 3) != status):
            errors.append('terminal sequence/ECP epoch/status association mismatch '+str((h, s)))
            continue
        if not a or a['effective_cycle'] < roi['start_cycle']:
            censored.append(dict(checker=h, seq=s, reason='admission before capture/ROI'))
            continue
        if end['effective_cycle'] >= roi['stop_cycle']:
            censored.append(dict(checker=h, seq=s, reason='result after ROI'))
            continue
        done_candidates = [r for r in executions[h, s] if r['time'] <= end['time']]
        if not done_candidates or not bit(d[2], 0) or not p[6]:
            errors.append('PASS terminal lacks exec_done boundary '+str((h, s)))
            continue
        done = min(done_candidates, key=lambda r: r['time'])
        if p[3] != a['local'] or p[6] != done['local'] or d[3] != p[6]-p[3]-1:
            errors.append('admission/exec_done local-cycle conservation failed '+str((h, s)))
            continue
        if not p[4] or p[4] < p[3] or p[4] > p[6]:
            errors.append('invalid accepted-start local timestamp '+str((h, s)))
            continue
        try:
            counts = counter_partition(end)
        except ValueError:
            continue
        boundary = [r for r in ks[11] if r['time'] >= a['time'] and
                    r['time'] <= done['time'] and bit(r['d'][2], 5)]
        sealed_counts = None
        if boundary:
            seal_row = min(boundary, key=lambda r: r['time'])
            if p[5] != seal_row['local']:
                errors.append('seal timestamp/counter boundary mismatch '+str((h, s)))
            else:
                delta = [x-y for x, y in zip(d[4:13], seal_row['d'][4:13])]
                if min(delta) < 0 or sum(delta) != d[3]-seal_row['d'][3]:
                    errors.append('seal-to-done counter conservation failed '+str((h, s)))
                else:
                    sealed_counts = dict(zip(CATEGORIES, delta))
        e = dict(seq=s, checker=h, ecp_epoch=d[1], status='PASS',
                 admit_main=a['effective_cycle'], done_main=done['effective_cycle'],
                 result_main=end['effective_cycle'], admit_local=p[3], start_local=p[4],
                 seal_local=p[5], done_local=p[6], execution_cycles_local=d[3],
                 categories_local=counts, sealed_to_done_categories_local=sealed_counts,
                 retired=d[13], retired_reads=d[14], retired_writes=d[15],
                 retired_memory_ops=p[15], lsl_load_dequeues=p[7], lsl_store_dequeues=p[8],
                 csr_handshakes=p[9], rocc_handshakes=p[10],
                 raw_ibuf_empty=p[11], raw_lsl_wait=p[12],
                 result_resource_wait_local=p[13], checked_instructions=p[14],
                 admit_to_start_local=p[4]-p[3], start_to_done_local=p[6]-p[4],
                 admit_to_done_main=done['effective_cycle']-a['effective_cycle'],
                 done_to_result_main=end['effective_cycle']-done['effective_cycle'])
        if e['retired_memory_ops'] > e['retired']:
            errors.append('memory retirement conservation failed '+str((h, s)))
        e['cycles_per_retired_instruction_local'] = d[3]/d[13] if d[13] else None
        e['cycles_per_memory_op_local'] = d[3]/p[15] if p[15] else None
        result.append(e)
    # Every completely observed kind6 PASS must have new counter terminals.
    for key, a in admissions.items():
        if roi['start_cycle'] <= a['effective_cycle'] < roi['stop_cycle']:
            terminal = [r for r in control.values() if (r['hart'], r['d'][0]) == key
                        and bit(r['d'][2], 16) and r['effective_cycle'] < roi['stop_cycle']]
            if terminal and not any(bit(r['d'][2], 1) for r in streams[key][11]):
                errors.append('completed package missing Opt2b terminal '+str(key))
    return result, censored, errors


def summarize_packages(packages):
    fields = ('admit_to_start_local', 'start_to_done_local', 'admit_to_done_main',
              'done_to_result_main', 'execution_cycles_local', 'retired',
              'retired_memory_ops', 'lsl_load_dequeues', 'lsl_store_dequeues',
              'cycles_per_retired_instruction_local', 'cycles_per_memory_op_local')
    counts = {c: sum(p['categories_local'][c] for p in packages) for c in CATEGORIES}
    sealed = [p for p in packages if p['sealed_to_done_categories_local'] is not None]
    seal_counts = {c: sum(p['sealed_to_done_categories_local'][c] for p in sealed) for c in CATEGORIES}
    total = sum(counts.values())
    return dict(packages=len(packages), execution_cycles_local=total, categories_local=counts,
                dominant_category=max(counts, key=counts.get) if total else None,
                sealed_to_done=dict(packages=len(sealed), categories_local=seal_counts),
                distributions={f: distribution([p[f] for p in packages if p[f] is not None]) for f in fields},
                raw_overlap=dict(ibuf_empty=sum(p['raw_ibuf_empty'] for p in packages),
                                 lsl_wait=sum(p['raw_lsl_wait'] for p in packages)),
                retired=sum(p['retired'] for p in packages),
                retired_memory_ops=sum(p['retired_memory_ops'] for p in packages),
                result_resource_wait_local=sum(p['result_resource_wait_local'] for p in packages))


def frontend_counts(rows):
    result = {}
    for h in range(1, 5):
        rs = sorted((r for r in rows if r['kind'] == 13 and r['hart'] == h), key=lambda r: r['time'])
        if len(rs) < 2:
            raise ValueError('insufficient frontend cumulative snapshots '+str(h))
        first, last = rs[0], rs[-1]
        ds = [b-a for a, b in zip(first['d'][1:15], last['d'][1:15])]
        if min(ds) < 0:
            raise ValueError('frontend cumulative counters moved backwards')
        counters = dict(zip(FRONTEND, ds))
        if counters['handoff'] > min(counters['emitted'], counters['requests']):
            raise ValueError('handoff counter exceeds accepted responses/requests')
        result[h] = dict(counters=counters, start_main=first['effective_cycle'],
                         stop_main=last['effective_cycle'],
                         interval='snapshot-to-snapshot; final unsampled tail is censored',
                         saved_issue_opportunity_local_cycles=counters['handoff'],
                         roi_gain=None)
    return result


def version_events(rows):
    writes = [r for r in rows if r['kind'] == 14 and r['d'][0]]
    blocks = [r for r in rows if r['kind'] == 15 and r['d'][0]]
    identities = {(r['d'][1], r['d'][2], r['d'][8], r['d'][9]) for r in blocks}
    eligible = [r for r in blocks if r['d'][6] and r['d'][3] > r['d'][7]
                and r['d'][1] > r['d'][3] > 0]
    unsafe_writes = [r for r in writes if r['d'][6] and r['d'][3] > r['d'][7]
                     and r['d'][1] != r['d'][3]]
    return dict(semantic_write_events=len(writes), first_block_events=len(blocks),
                distinct_block_identities=len(identities),
                unsafe_older_to_younger_block_observations=len(eligible),
                observed_unsafe_cross_package_overwrites=len(unsafe_writes),
                capacity_coverage={str(n): None for n in (2, 4, 8, 16)},
                depth_coverage={str(n): None for n in (1, 2, 3, 4)},
                reason='serialized baseline does not expose never-issued younger stores; no counterfactual depth claim',
                svb='NOT_IMPLEMENTED', fallback='existing WaitSafe retained',
                allocations=None, promotions=None, occupancy=None, recovery_hit=None)


def classify_opt3(rows):
    rows = [r for r in rows if r["kind"] == 16]
    if len({r["hart"] for r in rows}) != 4:
        raise ValueError("kind16 fused-classification observer missing checker hart")
    totals = [0] * 9
    per_hart = {}
    for hart in range(1, 5):
        rs = sorted((r for r in rows if r["hart"] == hart), key=lambda r: r["time"])
        if len(rs) < 2:
            raise ValueError("insufficient kind16 snapshots for hart " + str(hart))
        for row in rs:
            if row['d'][1] != sum(row['d'][2:6]):
                raise ValueError('kind16 classification modes do not partition accepted responses')
        for before, after in zip(rs, rs[1:]):
            if any(a > b for a, b in zip(before['d'][1:10], after['d'][1:10])):
                raise ValueError('kind16 cumulative counter moved backwards within capture')
        delta = [b - a for a, b in zip(rs[0]["d"][1:10], rs[-1]["d"][1:10])]
        if min(delta) < 0:
            raise ValueError("kind16 cumulative counter moved backwards")
        for i, value in enumerate(delta): totals[i] += value
        per_hart[hart] = dict(zip(("classified", "no_cfi_or_fault", "prefix", "special",
                                   "wait_bjl", "bjl_reserve", "bjl_empty",
                                   "bjl_head_mismatch", "ready_held"), delta))
    keys = ("classified", "no_cfi_or_fault", "prefix", "special", "wait_bjl",
            "bjl_reserve", "bjl_empty", "bjl_head_mismatch", "ready_held")
    return dict(total=dict(zip(keys, totals)), per_hart=per_hart,
                classified=totals[0], schema="kind16 cumulative; snapshots are sparse")


def performance_metrics(actual):
    if actual <= 0:
        raise ValueError('ROI duration must be positive')
    return dict(baseline_roi=BASELINE, original_current_roi=ORIGINAL,
                opt2_roi=OPT2, opt2b_roi=OPT2B, opt3_roi=actual,
                incremental_reference='OPT2B', incremental_gain_cycles=OPT2B-actual,
                incremental_gain_percent=100*(OPT2B-actual)/OPT2B,
                gain_vs_opt2_cycles=OPT2-actual,
                gain_vs_opt2_percent=100*(OPT2-actual)/OPT2,
                total_gain_vs_original_cycles=ORIGINAL-actual,
                total_gain_vs_original_percent=100*(ORIGINAL-actual)/ORIGINAL,
                speedup_vs_opt2b=OPT2B/actual, speedup_vs_opt2=OPT2/actual,
                slowdown_vs_baseline=actual/BASELINE,
                gap_to_baseline_cycles=actual-BASELINE)

def _extend_analysis(events, roi, out):
    out = Path(out)
    legacy = json.loads((out/'summary.json').read_text())
    rows, footers, errors = read_events(Path(events))
    fit = align_clocks(rows, errors)
    opt3 = classify_opt3(rows)
    if legacy['coverage'] != 'COMPLETE' or errors:
        raise ValueError('Opt3 requires complete 71-observer coverage: '+str(errors))
    packages, censored, join_errors = decode_checker(rows, roi)
    errors.extend(join_errors)
    if not packages:
        errors.append('no fully observed checker package')
    front = frontend_counts(rows)
    if any(front[h]['counters']['classify'] for h in front):
        errors.append('retired CLASSIFY state counter is nonzero')
    versions = version_events(rows)
    if versions['observed_unsafe_cross_package_overwrites']:
        errors.append('unsafe cross-package L1 semantic overwrite observed')
    # Retain the tested safe-chain phase definitions while naming the Opt2b
    # reference separately below; the historical gain field is not Opt3 gain.
    chain = extend_safe_chain(events, roi, out)
    if any(chain['correctness'].get(k, 0) for k in ('failed', 'cancelled', 'allocation_collisions', 'stale_level_observations')):
        errors.append('safe-chain correctness counters nonzero')
    actual = roi['stop_cycle']-roi['start_cycle']
    ranked = sorted(packages, key=lambda p: p['start_to_done_local'], reverse=True)
    weights = Counter()
    with (out/'waitsafe_intervals.jsonl').open() as stream:
        for line in stream:
            r = json.loads(line)
            if r['unsafe']:
                weights[r['target']] += r['cycles']
    def tails(ps):
        return dict(packages=[p['seq'] for p in ps],
                    target_unsafe_pending_cycles=sum(weights[p['seq']] for p in ps))
    threshold = distribution([p['start_to_done_local'] for p in packages])['p95']
    summary = dict(schema=1, functional_change='CHECKER_FUSED_RESPONSE_CLASSIFICATION',
        opt3_classification=opt3,
        retained=['OPT1', 'OPT2_ROUND_ROBIN', 'OPT2B_HANDOFF'], clock_alignment=fit,
        performance=performance_metrics(actual),
        checker=dict(all=summarize_packages(packages),
                     per_checker={h: summarize_packages([p for p in packages if p['checker'] == h]) for h in range(1, 5)},
                     censored=censored,
                     long_tail=dict(top10=tails(ranked[:10]),
                                    top1percent=tails(ranked[:math.ceil(.01*len(ranked))]),
                                    p95_and_above=tails([p for p in ranked if p['start_to_done_local'] >= threshold]))),
        frontend=front, svb=versions,
        OPPORTUNITY_UPPER_BOUND={str(d): chain['strict_unsafe_waitsafe_cycles'] for d in (2, 3, 4)},
        pending=dict(total_cycles=chain['pending_cycles'],
                     strict_unsafe_cycles=chain['strict_unsafe_waitsafe_cycles'],
                     categories=chain['categories'], production_seal_phases=chain['production_seal_phases']),
        correctness=dict(status='FAIL' if errors else 'OBSERVED_CHECKS_PASS',
                         errors=errors, coverage=legacy['coverage'], observers=len(footers),
                         package_association='FAIL' if join_errors else 'PASS',
                         counters=chain['correctness'], workload_comparison=roi.get('comparison'),
                         RUN_PROVENANCE='UNRESOLVED', full_package_cache_dram_drain='UNRESOLVED',
                         recovery_fail_probe_dynamic='NOT_EXERCISED_BY_PASS_WORKLOAD'),
        validation_status='FAIL' if errors or roi.get('comparison') != 'SAME_SOFTWARE_ROI_COMPARABLE' else 'OBSERVED_CHECKS_PASS',
        limitations=['Exclusive stall categories are priority attribution, not independent causal lost cycles.',
                     'Per-checker local counts overlap in wall time; do not add them to main ROI loss.',
                     'Post-seal counts are measured at the checker-visible producer-seal boundary.',
                     'Frontend cumulative snapshots censor unsampled prefix/tail; no exact per-package ownership claim.',
                     'SVB recovery/ownership invariant not closed; no SVB implemented.',
                     'Existing full drain and RUN_PROVENANCE limitations remain.'])
    with (out/'opt3_summary.json').open('x') as stream:
        json.dump(summary, stream, indent=2); stream.write('\n')
    with (out/'checker_packages.json').open('x') as stream:
        json.dump(packages, stream, indent=2); stream.write('\n')
    return summary


def load_reference():
    ref = Path(__file__).with_name('reference_opt2b.json')
    if not ref.is_file():
        raise RuntimeError('pinned Opt2b reference missing')
    result = json.loads(ref.read_text())
    if result['roi'] != OPT2B or result['handoff'] != 630212:
        raise ValueError('Opt2b reference does not match the reviewed experiment')
    return result


def extend_analysis(events, roi, out):
    """Always leave a machine-readable failure summary on schema/coverage errors."""
    try:
        return _extend_analysis(events, roi, out)
    except (ValueError, KeyError, OSError) as exc:
        target = Path(out)/'opt3_summary.json'
        result = dict(schema=1, validation_status='FAIL',
                      functional_change='CHECKER_FUSED_RESPONSE_CLASSIFICATION',
                      correctness=dict(status='FAIL', errors=[str(exc)]),
                      performance=None, reason='incomplete or inconsistent evidence; no performance claim')
        if target.exists():
            raise  # Never overwrite prior evidence, including partial output.
        with target.open('x') as stream:
            json.dump(result, stream, indent=2); stream.write('\n')
        return result


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('events', type=Path)
    p.add_argument('roi', type=Path)
    p.add_argument('output', type=Path, help='fresh directory, never overwritten')
    args = p.parse_args()
    from compact_causality import analyze_events
    roi = json.loads(args.roi.read_text())
    analyze_events(args.events, roi, args.output)
    result = extend_analysis(args.events, roi, args.output)
    print(json.dumps(dict(summary=str(args.output/'opt3_summary.json'), status=result['validation_status'])))
    return 0 if result['validation_status'] == 'OBSERVED_CHECKS_PASS' else 3


if __name__ == '__main__':
    raise SystemExit(main())
