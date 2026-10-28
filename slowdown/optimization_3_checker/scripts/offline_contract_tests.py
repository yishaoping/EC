#!/usr/bin/env python3
"""Pure source/observer contract checks; never builds or runs hardware."""
import json
from pathlib import Path

ROOT = Path('/data1/gzh/EC')
FRONTEND = ROOT / 'chipyard/generators/rocket-chip/src/main/scala/rocket/Frontend.scala'
LAUNCHER = ROOT / 'slowdown/optimization_3_checker/scripts/launch_optimization_3_checker.py'
PARSER = ROOT / 'slowdown/optimization_3_checker/analysis/compact_causality.py'
SUMMARY = ROOT / 'slowdown/optimization_3_checker/analysis/opt3_summary.py'


def main():
    source = FRONTEND.read_text()
    assert 'checker_classify ::' not in source
    assert 'val checker_classify_fire =' in source
    assert 'checker_state === checker_wait_bjl' in source
    assert 'BJL.io.bj_req_valid := checker_state === checker_wait_bjl' in source
    assert 'checker_tail_bits' in source and 'checker_partial_bits := checker_tail_bits' in source
    assert 'assert(!fq.io.enq.fire' in source
    assert 'assert(!BJL.io.bj_req_valid' in source
    assert 'SafeChainObservation.emit(16' in source
    parser = PARSER.read_text()
    assert 'EXPECTED |= {(16, h) for h in range(1, 5)}' in parser
    launcher = LAUNCHER.read_text()
    assert 'CHECKER_FUSED_RESPONSE_CLASSIFICATION' in launcher
    assert 'range(1, 17)' in launcher and 'kind in (3, 4, 5, 6, 11, 12, 13, 16)' in launcher
    assert 'NO_AUTOMATIC_RETRY' in launcher
    assert 'hardware_generation": "NOT_EXECUTED"' in launcher
    assert 'def short_temporary()' in launcher
    assert "for name in ('t', 'u', 'v', 'w', 'x', 'y', 'z')" in launcher
    assert 'def classify_opt3' in SUMMARY.read_text()
    preparation = json.loads((ROOT / 'slowdown/optimization_3_checker/manifests/preparation.json').read_text())
    assert preparation['status'] == 'REVIEWED_BEFORE_RUN'
    print('OPT3_OFFLINE_CONTRACT=PASS')


if __name__ == '__main__':
    main()
