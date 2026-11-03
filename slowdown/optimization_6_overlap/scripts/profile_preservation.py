#!/usr/bin/env python3
"""Observed SC8 handoff phases, with explicit optional-capture boundaries."""
import argparse
from collections import defaultdict
import importlib.util
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
spec = importlib.util.spec_from_file_location('stable', ROOT / 'slowdown/optimization_4_svb/analysis/analyze_svb.py')
stable = importlib.util.module_from_spec(spec); spec.loader.exec_module(stable)
BITS = dict(safe=1, wb_fire=12, wb_done=13, clear_fire=17)


def profile(run):
    roi = json.loads((run / 'roi.json').read_text())
    rows = [r for r in stable.parse_events(run / 'safe_chain_events.tsv')
            if r['kind'] == 8 and r['hart'] == 0 and
            roi['start_cycle'] <= r['cycle'] < roi['stop_cycle']]
    groups = defaultdict(list)
    for row in rows:
        groups[row['nums'][0]].append(row)
    episodes = []
    for entry, samples in groups.items():
        samples.sort(key=lambda r: r['time'])
        active = [r for r in samples if r['nums'][9] & 1]
        if not active:
            continue
        # Entry assertion is a logged transition; an already-active descriptor
        # at ROI entry is censored. An optional record loss can also censor it.
        first = active[0]
        episode = dict(entry=entry, first_observed_cycle=first['cycle'],
                       last_observed_cycle=active[-1]['cycle'])
        for name, bit in BITS.items():
            candidates = [r['cycle'] for r in active if r['nums'][9] & (1 << bit)]
            episode[name] = min(candidates) if candidates else None
        episodes.append(episode)
    report = {}
    for name, begin, end in [('observed_entry_to_safe', 'first_observed_cycle', 'safe'),
            ('safe_to_wb', 'safe', 'wb_fire'), ('wb_to_receipt', 'wb_fire', 'wb_done'),
            ('receipt_to_invalidating_clear', 'wb_done', 'clear_fire')]:
        durations = [r[end] - r[begin] for r in episodes
                     if r[begin] is not None and r[end] is not None]
        if any(d < 0 for d in durations):
            raise ValueError('observed phase order violated')
        report[name] = dict(captured_intervals=len(durations), cycles=sum(durations),
                            maximum=max(durations, default=None))
    return dict(run=str(run.resolve()), observed_episodes=len(episodes), phases=report,
                first_saved_cycle=rows[0]['cycle'] if rows else None,
                last_saved_cycle=rows[-1]['cycle'] if rows else None,
                trailing_roi_gap=roi['stop_cycle'] - rows[-1]['cycle'] if rows else None,
                scope='optional SC8 observed intervals; entry can be censored; missing endpoints excluded; overlapping local exposure, not causal BOOM savings')


if __name__ == '__main__':
    ap = argparse.ArgumentParser(); ap.add_argument('run', type=Path)
    ap.add_argument('--output', type=Path); args = ap.parse_args()
    result = json.dumps(profile(args.run), indent=2, sort_keys=True) + '\n'
    if args.output:
        args.output.write_text(result)
    print(result)
