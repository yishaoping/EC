#!/usr/bin/env python3
"""Require identical generated machine description and clock summaries."""
import argparse, hashlib, json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
OUT = ROOT / 'slowdown/blackscholes_validation'
FROZEN = ROOT / 'slowdown/optimization_6_overlap/build/overlap_retained_copy_20261103_040650_0a6ef6bc/generated'

def main():
    p = argparse.ArgumentParser()
    p.add_argument('build', type=Path, nargs='?', default=OUT / 'build/matched_check')
    p.add_argument('--reference', type=Path, default=FROZEN)
    args = p.parse_args()
    files = {}
    for suffix in ['json', 'buildTopClockGenerator.freq-summary',
                   'harnessDividerOnlyClockGenerator.freq-summary']:
        name = 'chipyard.TestHarness.v1Config.' + suffix
        paths = [args.reference / name, args.build / 'generated' / name]
        hashes = [hashlib.sha256(path.read_bytes()).hexdigest() for path in paths]
        files[name] = dict(reference_sha256=hashes[0], candidate_sha256=hashes[1], identical=hashes[0] == hashes[1])
    report = dict(status='PASS' if all(x['identical'] for x in files.values()) else 'FAIL',
                  scope='Exact generated machine JSON and both frequency summaries; source config-only patch records ROB/PRF/LQ/SQ/MSHR/way/latency settings; checker fetch bandwidth is a design difference',
                  files=files)
    target = args.build / 'configuration_check.json'
    if target.exists():
        assert json.loads(target.read_text())['status'] == report['status'] == 'PASS'
    else:
        target.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report, indent=2))
    return report['status'] != 'PASS'

if __name__ == '__main__': raise SystemExit(main())
