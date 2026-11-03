#!/usr/bin/env python3
"""Validate overlap diagnostics without promoting exposure counts to savings."""
import argparse
import importlib.util
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
spec = importlib.util.spec_from_file_location(
    'stable_svb_analysis', ROOT / 'slowdown/optimization_4_svb/analysis/analyze_svb.py')
stable = importlib.util.module_from_spec(spec)
spec.loader.exec_module(stable)


def sourcec(records, capture, expected_cycles=None):
    rows = [r for r in records if r['kind'] == 48 and r['hart'] == 0]
    errors = []
    if len(rows) != 1:
        return dict(status='FAIL', errors=['one SC48 STOP record required'])
    n = rows[0]['nums']
    if n[0] != 1 or n[1] == 0 or any(n[10:]):
        errors.append('invalid SC48 schema/window/padding')
    if expected_cycles is not None and n[1] != expected_cycles:
        errors.append('SC48 window differs from same-enable L2 tick count')
    if any(x > n[1] for x in n[2:10]):
        errors.append('SC48 subcount exceeds sampled window')
    if n[2] + n[6] != n[8] or n[3] + n[7] != n[9]:
        errors.append('SC48 checkpoint phase conservation failed')
    if not (n[4] <= n[7] <= n[6] and n[3] <= n[2]):
        errors.append('SC48 release/phase subset failed')
    if n[5] < n[3] + n[7] - n[4]:
        errors.append('SC48 pending/no-accept conservation failed')
    observer = capture.get('observers', {}).get('48:0', {})
    producer = capture.get('producers', {}).get('48:0', {})
    if (observer.get('events_seen') != 1 or observer.get('footers_seen') != 1 or
            observer.get('footer_emitted_count') != 1 or observer.get('omitted') or
            producer.get('produced') != 1 or producer.get('emitted') != 1 or
            producer.get('omitted') != 0):
        errors.append('SC48 mandatory producer/capture conservation failed')
    names = ['schema', 'sample_cycles', 'reserved_cycles', 'reserved_pending_cycles',
             'accepted_releases_in_wait_ack', 'pending_no_accept_cycles',
             'wait_ack_cycles', 'wait_ack_pending_cycles', 'target_lock_cycles',
             'target_lock_pending_cycles']
    return dict(status='FAIL' if errors else 'PASS', errors=errors,
                counters=dict(zip(names, n)), cycle=rows[0]['cycle'],
                interpretation='overlapping activity counts on the new schedule; not causal ROI savings')


def frontend(records, roi):
    reports = []
    for hart in range(1, 5):
        by_kind = {}
        for kind in (13, 16):
            rows = sorted((r for r in records if r['kind'] == kind and r['hart'] == hart
                           and roi['start_cycle'] <= r['cycle'] < roi['stop_cycle']),
                          key=lambda r: r['time'])
            if len(rows) < 2:
                by_kind[str(kind)] = dict(status='INSUFFICIENT_SNAPSHOTS')
                continue
            first, last = rows[0], rows[-1]
            delta = [b-a for a, b in zip(first['nums'], last['nums'])]
            if kind == 13:
                names = ['live_cycles', 'empty_cycles', 'fetching_cycles', 'retired_classify_cycles',
                         'wait_bjl_cycles', 'ready_cycles', 'fq_deliveries', 'handoff_launches',
                         'icache_requests', 'held_ready_cycles', 'fault_deliveries',
                         'icache_acquires', 'tlb_miss_cycles', 'redirect_cycles']
                counts = dict(zip(names, delta[1:15]))
            else:
                names = ['classifications', 'no_cfi_or_fault', 'prefix', 'special', 'needs_bjl',
                         'bjl_reservations', 'bjl_not_ready_cycles', 'bjl_mismatch_cycles',
                         'held_ready_cycles']
                counts = dict(zip(names, delta[1:10]))
                # Baseline reserved d11-d15 as zero. Their deltas stay zero.
                counts.update(zip(['direct_deliveries', 'direct_bjl_reservations',
                                   'direct_successor_launches', 'direct_fq_blocked_cycles'], delta[11:15]))
            by_kind[str(kind)] = dict(status='EXACT_BETWEEN_SAVED_SNAPSHOTS',
                start_cycle=first['cycle'], stop_cycle=last['cycle'],
                leading_roi_gap=first['cycle']-roi['start_cycle'],
                trailing_roi_gap=roi['stop_cycle']-last['cycle'], counters=counts)
        reports.append(dict(hart=hart, snapshots=by_kind))
    return dict(scope='checker-local cumulative deltas; do not sum as BOOM savings', harts=reports)


def terminal_snapshots(records, capture, expected_cycles, required=False):
    """Check mandatory final records independently of optional prefix samples."""
    observed = any(r['kind'] in (49, 50) for r in records)
    if not required and not observed:
        return dict(status='NOT_IN_THIS_REVISION')
    errors, reports = [], {}
    names = {
        49: ['schema', 'sample_cycles', 'live_cycles', 'empty_cycles',
             'fetching_cycles', 'retired_classify_cycles', 'wait_bjl_cycles',
             'ready_cycles', 'fq_deliveries', 'handoff_launches', 'icache_requests',
             'held_ready_cycles', 'fault_deliveries', 'icache_acquires',
             'tlb_miss_cycles', 'redirect_cycles'],
        50: ['schema', 'sample_cycles', 'effects', 'effect_edge_terminal_enqueues',
             'effect_edge_terminal_deliveries', 'empty_queue_bypasses',
             'terminal_enqueues', 'terminal_deliveries', 'applied_s3_blocked_cycles',
             'queued_cycles', 'terminal_blocked_cycles', 'lsu_candidate_older_inflight_cycles',
             'lsu_accepted_terminal_forward_cycles', 'lsu_forwarded_store_admissions',
             'lsu_store_admissions', 'padding']}
    for kind, harts in ((49, range(1, 5)), (50, [0])):
        for hart in harts:
            identity = f'{kind}:{hart}'
            rows = [r for r in records if r['kind'] == kind and r['hart'] == hart]
            if len(rows) != 1:
                errors.append(identity + ' requires one final snapshot')
                continue
            n = rows[0]['nums']
            observer = capture.get('observers', {}).get(identity, {})
            producer = capture.get('producers', {}).get(identity, {})
            if (observer.get('events_seen') != 1 or observer.get('footers_seen') != 1 or
                    observer.get('footer_emitted_count') != 1 or observer.get('omitted') or
                    producer.get('produced') != 1 or producer.get('emitted') != 1 or
                    producer.get('omitted') != 0):
                errors.append(identity + ' producer/capture conservation failed')
            if n[0] != 1 or n[1] <= 0 or any(v > n[1] for v in n[2:]):
                errors.append(identity + ' invalid schema/window/subset')
            if kind == 49:
                if n[2] != sum(n[3:8]) or n[5] != 0:
                    errors.append(identity + ' frontend state partition failed')
                if n[9] > n[8] or n[9] > n[10] or n[11] > n[7] or n[12] > n[8]:
                    errors.append(identity + ' frontend event subsets failed')
            else:
                if expected_cycles is None or n[1] != expected_cycles:
                    errors.append(identity + ' differs from same-enable L2 window')
                if n[15] != 0 or not (n[4] <= n[3] <= n[2] and
                        n[4] <= n[5] <= min(n[6], n[7]) and
                        n[13] <= n[12] and n[13] <= n[14] and n[13] <= n[11]):
                    errors.append(identity + ' terminal/forwarding subsets failed')
            reports[identity] = dict(cycle=rows[0]['cycle'],
                                     counters=dict(zip(names[kind], n)))
    return dict(status='FAIL' if errors else 'PASS', errors=errors, snapshots=reports,
                scope='hardware traffic-enable window, local clock counts; overlapping activity, not causal savings')


def retained_copy(records, capture, expected_cycles, required=False):
    rows = [r for r in records if r['kind'] == 51 and r['hart'] == 0]
    if not required and not rows:
        return dict(status='NOT_IN_THIS_REVISION')
    errors = []
    if len(rows) != 1:
        return dict(status='FAIL', errors=['one SC51 STOP record required'])
    n = rows[0]['nums']
    observer = capture.get('observers', {}).get('51:0', {})
    producer = capture.get('producers', {}).get('51:0', {})
    if (observer.get('events_seen') != 1 or observer.get('footers_seen') != 1 or
            observer.get('footer_emitted_count') != 1 or observer.get('omitted') or
            producer.get('produced') != 1 or producer.get('emitted') != 1 or
            producer.get('omitted') != 0):
        errors.append('SC51 producer/capture conservation failed')
    if n[0] != 1 or n[1] <= 0 or any(n[9:]) or any(v > n[1] for v in n[2:9]):
        errors.append('SC51 invalid schema/window/padding')
    if expected_cycles is None or n[1] != expected_cycles:
        errors.append('SC51 differs from same-enable L2 window')
    # Requests and receipts can straddle the measurement boundary. Only
    # same-edge subsets are equalities; do not force issued == done in ROI.
    if n[3] > n[2] or n[5] + max(n[6], n[7]) > n[4]:
        errors.append('SC51 retention/receipt subsets failed')
    names = ['schema', 'sample_cycles', 'wb_requests', 'retaining_wb_requests',
             'wb_receipts', 'retained_receipts', 'retaining_receipts_owner_changed',
             'retaining_receipts_probe_revoked', 'invalidating_clears']
    return dict(status='FAIL' if errors else 'PASS', errors=errors,
                counters=dict(zip(names, n)), cycle=rows[0]['cycle'],
                scope='traffic-enable activity, not causal savings')


def analyze(run):
    records = stable.parse_events(run / 'safe_chain_events.tsv')
    summary = json.loads((run / 'summary.json').read_text())
    roi = json.loads((run / 'roi.json').read_text())
    capture = json.loads((run / 'capture_summary.json').read_text())
    windows = {m['cycles'] for m in summary.get('cache_opportunity', {}).get('models', [])
               if m.get('level') == 2 and 'cycles' in m}
    sc = sourcec(records, capture, next(iter(windows)) if len(windows) == 1 else None)
    if len(windows) != 1:
        sc['errors'].append('missing/ambiguous same-enable L2 tick window')
        sc['status'] = 'FAIL'
    patch = (run / 'source.patch').read_text() if (run / 'source.patch').exists() else ''
    final = terminal_snapshots(records, capture,
        next(iter(windows)) if len(windows) == 1 else None,
        required='OVERLAP_OBSERVATION_ONLY' in patch)
    retained = retained_copy(records, capture,
        next(iter(windows)) if len(windows) == 1 else None,
        required='RETAINED_COPY_OBSERVATION_ONLY' in patch)
    valid = (bool(summary.get('performance_valid')) and sc['status'] == 'PASS' and
             final['status'] in ('PASS', 'NOT_IN_THIS_REVISION') and
             retained['status'] in ('PASS', 'NOT_IN_THIS_REVISION'))
    cycles = summary.get('opt4_roi_cycles')
    return dict(run=str(run.resolve()), status='PASS' if valid else 'FAIL',
        performance_valid=valid, roi_cycles=cycles,
        slowdown=cycles / 1001675 if valid else None,
        improvement_vs_frozen_opt4_cycles=1707863-cycles if valid else None,
        sourcec=sc, frontend=frontend(records, roi), terminal_snapshots=final,
        retained_copy=retained,
        correctness=summary.get('correctness'), integrity=summary.get('integrity'),
        protocol=summary.get('protocol'), data_ordering=summary.get('data_ordering'))


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('run', type=Path)
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    report = analyze(args.run)
    result = json.dumps(report, indent=2, sort_keys=True) + '\n'
    if args.output:
        args.output.write_text(result)
    print(result)
    raise SystemExit(0 if report['performance_valid'] else 1)
