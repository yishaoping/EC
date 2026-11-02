#!/usr/bin/env python3
"""Launch exactly one corrected B through the existing sealed launcher.

--static-check performs only identity/evidence checks. The normal entry point is
for the user; the agent must not invoke it when hardware execution is forbidden.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]
SCRIPTS = Path(__file__).resolve().parent
LAUNCH = ROOT/'slowdown/optimization_4_svb/scripts/launch_optimization_4_svb.py'


def digest(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda: f.read(1024*1024), b''):
            h.update(b)
    return h.hexdigest()


def preflight(report):
    report = report.resolve()
    if not report.is_relative_to(ROOT/'AI/TMP'):
        raise ValueError('one-shot report must be in AI/TMP')
    contract = json.loads((report/'one_shot_contract.json').read_text())
    seal = json.loads((report/'sealed/source_seal.json').read_text())
    if contract['run_target'] != 'B_ONLY_64K_2WAY' or contract['number_of_full_runs_requested'] != 1:
        raise ValueError('not a B-only one-run contract')
    if json.loads((report/'scala_typer_result.json').read_text())['exit_code'] != 0:
        raise ValueError('Scala type check did not pass')
    if any(x['exit_code'] != 0 for x in json.loads((report/'offline_tests_result.json').read_text())):
        raise ValueError('offline tests did not pass')
    binding = seal['one_shot_contract']
    if (ROOT/binding['path']).resolve() != report/'one_shot_contract.json' or digest(ROOT/binding['path']) != binding['sha256']:
        raise ValueError('run contract is not sealed')
    for rel, expected in contract['evidence_sha256'].items():
        if digest(ROOT/rel) != expected:
            raise ValueError('immutable old evidence/proof changed: '+rel)
    spec = importlib.util.spec_from_file_location('seq67_launch', LAUNCH)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    mod.CAUSAL_CONTEXT = (report/'sealed', 'B')
    mod.ACTIVE_CONFIG = 'L1Causal64Config'
    sys.path.insert(0, str(LAUNCH.parent))
    mod.causal_identity()
    return contract


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--report', type=Path, required=True)
    ap.add_argument('--jobs', type=int, default=4)
    ap.add_argument('--static-check', action='store_true')
    ap.add_argument('--analyze-only', action='store_true', help='offline postprocessing only; never starts hardware')
    a = ap.parse_args()
    if a.jobs < 1 or a.static_check and a.analyze_only:
        ap.error('invalid jobs/mode')
    report = a.report.resolve()
    contract = preflight(report)
    if a.static_check:
        print(json.dumps(dict(status='PASS', target=contract['run_target'],
            hardware_generation='NOT_EXECUTED', verilator_build='NOT_EXECUTED', simulation='NOT_EXECUTED')))
        return 0
    if not a.analyze_only:
        # An exclusive persistent claim prevents an accidental second benchmark.
        # Failed build recovery is a separate manual action, never an auto retry.
        if list((report/'sealed/arms/B/runs').glob('*/run_manifest.json')):
            raise RuntimeError('B already has a run; use --analyze-only for offline analysis')
        with (report/'B_LAUNCH_CLAIM.json').open('x') as f:
            json.dump(dict(target='B_ONLY_64K_2WAY', policy='NO_AUTOMATIC_RETRY', jobs=a.jobs), f)
        argv = [sys.executable, '-I', '-B', str(LAUNCH), '--l1-causal-arm', 'B',
            '--experiment-dir', str(report/'sealed'), '--jobs', str(a.jobs)]
        (report/'user_launcher_argv.json').write_text(json.dumps(argv, indent=2)+'\n')
        rc = subprocess.run(argv, cwd=ROOT).returncode
        (report/'user_launcher_exit.json').write_text(json.dumps({'exit_code':rc})+'\n')
    result = subprocess.run([sys.executable, '-I', '-B', str(SCRIPTS/'analyze_checker_seq67_one_shot.py'),
        '--report', str(report)], cwd=ROOT)
    return result.returncode


if __name__ == '__main__':
    raise SystemExit(main())
