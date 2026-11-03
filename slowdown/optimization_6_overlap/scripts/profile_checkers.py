#!/usr/bin/env python3
"""Aggregate only fully captured per-package checker counter intervals."""
import argparse
from collections import defaultdict
import importlib.util
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
spec = importlib.util.spec_from_file_location('stable_svb', ROOT / 'slowdown/optimization_4_svb/analysis/analyze_svb.py')
stable = importlib.util.module_from_spec(spec)
spec.loader.exec_module(stable)
CATEGORIES = ['issue_available', 'instruction_starvation', 'lsl_wait', 'dcache_blocked',
              'dependency', 'replay', 'setup_redirect_or_management', 'unused', 'other']


def profile(run):
    roi = json.loads((run / 'roi.json').read_text())
    records = stable.parse_events(run / 'safe_chain_events.tsv')
    groups = defaultdict(list)
    lifecycle = defaultdict(list)
    for r in records:
        if r['kind'] == 11 and 1 <= r['hart'] <= 4 and r['nums'][0]:
            # ECP epoch can advance during one package. Sequence is the owner;
            # epoch is a sampled progress attribute, not part of its identity.
            groups[(r['hart'], r['nums'][0])].append(r)
        if r['kind'] == 12 and 1 <= r['hart'] <= 4 and r['nums'][0]:
            lifecycle[(r['hart'], r['nums'][0])].append(r)
    accepted, omitted = [], defaultdict(int)
    for (hart, seq), rows in groups.items():
        rows.sort(key=lambda r: r['time'])
        zero = [r for r in rows if r['nums'][3] == 0 and r['nums'][2] & 128]
        terminals = [r for r in rows if r['nums'][2] & 2]
        if not zero or not terminals:
            omitted['missing_start_or_result'] += 1
            continue
        first, last = zero[0], terminals[-1]
        if not (roi['start_cycle'] <= first['cycle'] <= last['cycle'] < roi['stop_cycle']):
            omitted['crosses_roi_boundary'] += 1
            continue
        n = last['nums']
        if n[3] != sum(n[4:13]) or any(v < 0 for v in n[3:]):
            raise ValueError(f'invalid counter partition: hart={hart} seq={seq}')
        if any(first['nums'][3:]):
            raise ValueError(f'nonzero initial counters: hart={hart} seq={seq}')
        for before, after in zip(rows, rows[1:]):
            if any(a < b for b, a in zip(before['nums'][3:], after['nums'][3:])):
                raise ValueError(f'counters decreased inside owner: hart={hart} seq={seq}')
        accepted.append(dict(hart=hart, seq=seq,
            observed_epochs=sorted({r['nums'][1] for r in rows}),
            start_cycle=first['cycle'], result_cycle=last['cycle'], local_exec_cycles=n[3],
            counters=dict(zip(CATEGORIES, n[4:13])), checked_instructions=n[13],
            checked_loads=n[14], checked_stores=n[15]))
        life = [r for r in lifecycle[(hart, seq)] if r['nums'][2] & 2 and
                r['cycle'] == last['cycle']]
        if len(life) == 1:
            q = life[0]
            a, start, seal, done = q['nums'][3:7]
            # These four fields are checker CSR time. The event's cycle is
            # BOOM time and must not be mixed into their local differences.
            if a <= start <= done and seal >= a and seal:
                accepted[-1]['lifecycle_local_cycles'] = dict(
                    admission_to_start=start-a, admission_to_producer_seal=seal-a,
                    admission_to_exec_done=done-a,
                    result_queue_backpressure=q['nums'][13],
                    raw_ibuf_empty=q['nums'][11], raw_lsl_wait=q['nums'][12])
    reports = []
    for hart in range(1, 5):
        rows = [r for r in accepted if r['hart'] == hart]
        instructions = sum(r['checked_instructions'] for r in rows)
        counts = {name: sum(r['counters'][name] for r in rows) for name in CATEGORIES}
        life = [r['lifecycle_local_cycles'] for r in rows if 'lifecycle_local_cycles' in r]
        reports.append(dict(hart=hart, fully_captured_packages=len(rows),
            checked_instructions=instructions, counters=counts,
            local_cycles_per_checked_instruction={k: v / instructions if instructions else None for k, v in counts.items()},
            lifecycle_captured_packages=len(life),
            lifecycle_local_cycles={k: sum(r[k] for r in life) for k in life[0]} if life else {}))
    return dict(scope='checker-local priority partition for complete captured packages inside ROI; optional loss excludes packages, not zero-filled; not causal BOOM savings',
                run=str(run.resolve()), excluded=dict(omitted), harts=reports,
                packages=accepted)


if __name__ == '__main__':
    ap = argparse.ArgumentParser()
    ap.add_argument('run', type=Path)
    ap.add_argument('--output', type=Path)
    args = ap.parse_args()
    result = json.dumps(profile(args.run), indent=2, sort_keys=True) + '\n'
    if args.output:
        args.output.write_text(result)
        compact = json.loads(result)
        compact.pop('packages')
        print(json.dumps(compact, indent=2, sort_keys=True))
    else:
        print(result)
