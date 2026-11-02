#!/usr/bin/env python3
"""Readable secondary review of a fully validated L1-Causal-1 pair."""
import argparse
import hashlib
import json
from pathlib import Path


def read(path):
    return json.loads(path.read_text())


def table(headers, rows):
    return '\n'.join(['|' + '|'.join(headers) + '|',
                      '|' + '|'.join(['---'] * len(headers)) + '|'] +
                     ['|' + '|'.join(str(x) for x in row) + '|' for row in rows])


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('root', type=Path)
    root = parser.parse_args().root.resolve()
    validation = read(root / 'validation_result.json')
    if validation['status'] != 'PASS':
        raise SystemExit('Refusing secondary interpretation before all pair gates PASS')
    arms = [read(root / name) for name in ['baseline_result.json', 'l1_64k_2way_result.json']]
    raw = [[json.loads(line) for line in (Path(a['run']) / 'cache_opportunity.jsonl').read_text().splitlines()]
           for a in arms]
    summaries = [read(Path(a['run']) / 'analysis/summary.json') for a in arms]
    comparison = read(root / 'comparison.json')
    sections = ['# L1-Causal-1 secondary mechanism review',
                'Only the validated r2 pair is used. Positive delta means A minus B. '
                'Exact software ROI and wider hardware traffic windows are kept separate.']

    occupancy = [a['causal']['mshr_occupancy_histogram'] for a in arms]
    roi = [a['roi_cycles'] for a in arms]
    sections += ['## Exact-ROI MSHR occupancy', table(
        ['Owners', 'A cycles', 'A % ROI', 'B cycles', 'B % ROI', 'A minus B cycles'],
        [(i, f'{occupancy[0][i]:,}', f'{100 * occupancy[0][i] / roi[0]:.4f}',
          f'{occupancy[1][i]:,}', f'{100 * occupancy[1][i] / roi[1]:.4f}',
          f'{occupancy[0][i] - occupancy[1][i]:+,}') for i in range(7)])]
    means = [sum(i * n for i, n in enumerate(h)) / nroi for h, nroi in zip(occupancy, roi)]
    sections += [f'Time-average live MSHR owners: A {means[0]:.6f}, B {means[1]:.6f}. '
                 'An owner may remain live after refill for draining or publication; occupancy is a resource exposure.']

    sections += ['## Completion-in-ROI latency cohorts', table(
        ['Stage', 'A samples', 'B samples', 'A mean cycles', 'B mean cycles'],
        [(x['metric'], x['A_samples'], x['B_samples'],
          'N/A' if x['A_mean'] is None else f"{x['A_mean']:.4f}",
          'N/A' if x['B_mean'] is None else f"{x['B_mean']:.4f}")
         for x in comparison['latency_comparison']])]
    for j, label in enumerate(['load detect to acceptance', 'MSHR allocation to final refill',
                               'load detect to DCache data response']):
        hist = [a['causal']['latency_histograms'][j] for a in arms]
        rows = []
        for i in range(32):
            if not (hist[0][i] or hist[1][i]):
                continue
            label_bin = '0' if i == 0 else (f'>={2**30}' if i == 31 else f'{2**(i-1)}..{2**i-1}')
            rows.append((label_bin, hist[0][i], hist[1][i]))
        sections += [label + ':', table(['Latency cycles (log bins)', 'A samples', 'B samples'], rows)]
    sections += ['Cohorts differ between stages and between arms. They may start before ROI; '
                 'unfinished or squashed requests are censored. Data response and refill are not retirement. '
                 'No latency mean is multiplied by avoided misses to estimate ROI benefit.']

    sections += ['## Wider traffic-window feedback']
    for level in [1, 2]:
        cache = [next(x for x in rows if x['level'] == level) for rows in raw]
        sections += [f'L{level} actual event counters:', table(
            ['Counter', 'A', 'B', 'A minus B'],
            [(key, cache[0]['actual'][key], cache[1]['actual'][key],
              cache[0]['actual'][key] - cache[1]['actual'][key])
             for key in cache[0]['actual'] if key in cache[1]['actual']])]
        sections += [f"L{level} S0 misses: {cache[0]['models'][0]['stats']['miss']} / "
                     f"{cache[1]['models'][0]['stats']['miss']} (A / B); these are model counts, not actual misses."]
    for group in ['svb', 'source_stats', 'traffic_pressure_counters']:
        values = [s[group] for s in summaries]
        sections += [group + ':', table(['Counter', 'A', 'B', 'A minus B'],
            [(key, values[0][key], values[1][key], values[0][key] - values[1][key])
             for key in values[0] if key in values[1] and key != 'pending_line'
             and type(values[0][key]) is int and type(values[1][key]) is int])]
    schema = read(Path(__file__).resolve().parents[1] / 'references/remaining_slowdown_observer_schema.json')
    for group, names in schema['groups'].items():
        counters = [s['remaining_observation']['groups'][group] for s in summaries]
        sections += [f'Bounded STOP {group} (hardware traffic window):',
                     table(['Predicate', 'A', 'B', 'A minus B'],
                           [(name, counters[0][i], counters[1][i], counters[0][i] - counters[1][i])
                            for i, name in enumerate(names) if i > 1])]
    sections += ['The traffic windows differ in length and are wider than software ROI. '
                 'Their activity counters can overlap and cannot be added to exact-ROI causal counters '
                 'or interpreted as independent recovered cycles. Geometry can change dirty eviction, '
                 'SVB/publication and checker scheduling feedback; this pair does not isolate each mediation path.',
                 f"Analysis source SHA256: `{hashlib.sha256(Path(__file__).read_bytes()).hexdigest()}`."]
    (root / 'mechanism_review.md').write_text('\n\n'.join(sections) + '\n')
    print(root / 'mechanism_review.md')


if __name__ == '__main__':
    main()
