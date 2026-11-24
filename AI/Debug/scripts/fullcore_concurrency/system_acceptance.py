#!/usr/bin/env python3
"""Score completed final Core runs; missing or failed acceptance exits nonzero.

This scores saved real simulations and corruption negatives. It never changes
69-task statuses and never treats source differences or physical signoff as
implicitly accepted. Build/run provenance must be reviewed separately.
"""
import argparse
import json
from pathlib import Path
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[3]
ROLLBACK = HERE.parent / 'rollback'
sys.path.insert(0, str(ROLLBACK))
from build_io_observer import digest


def main():
    p = argparse.ArgumentParser(description=__doc__)
    for name in ('core-runs', 'rebase-run', 'pressure-run', 'out'):
        p.add_argument('--' + name, type=Path, required=True)
    a = p.parse_args()
    cores, rebase, pressure, out = (getattr(a, n).resolve() for n in
        ('core_runs', 'rebase_run', 'pressure_run', 'out'))
    assert out.is_relative_to(ROOT / 'AI/TMP') and not out.exists()
    out.mkdir()
    results = {}
    scripts = [Path(__file__).resolve(), ROLLBACK/'fullcore_scoreboard.py',
        ROLLBACK/'io_effect_scoreboard.py', HERE/'interrupt_scoreboard.py',
        HERE/'interrupt_negative_test.py', HERE/'pressure_scoreboard.py',
        HERE/'pressure_negative_test.py', HERE/'io_rebase_scoreboard.py',
        HERE/'io_rebase_negative_test.py', HERE.parent/'sv39/scoreboard.py']
    hashes = {str(p): digest(p) for p in scripts}

    def call(name, args):
        dest = out / name
        dest.mkdir()
        command = [sys.executable, '-B', *map(str, args)]
        (dest/'command.json').write_text(json.dumps(command, indent=2) + '\n')
        with (dest/'run.log').open('x') as log:
            ret = subprocess.run(command, stdout=log, stderr=subprocess.STDOUT).returncode
        (dest/'run.exit').write_text(str(ret) + '\n')
        results[name] = {'status': 'PASS' if ret == 0 else 'FAIL', 'exit': ret,
                         'evidence': str(dest)}
        (out/'progress.json').write_text(json.dumps(results, indent=2) + '\n')

    profiles = {'normal': ['irq', 'trap', 'sv39', 'output', 'amo'],
                'fault8': ['trap', 'sv39'], 'fault18': ['irq', 'output', 'amo']}
    # Validate raw AND previously run architecture oracle before doing pairs.
    for config, workloads in profiles.items():
        for workload in workloads:
            d = cores/config/workload
            try:
                assert (d/'run.exit').read_text().strip() == '0'
                assert (d/'oracle.exit').read_text().strip() == '0'
                for name in ('run.log', 'inputs.json'):
                    assert (d/name).is_file()
                results[config+'.'+workload] = {'status': 'PASS', 'raw_exit': 0,
                    'architecture_oracle_exit': 0, 'evidence': str(d)}
            except (OSError, AssertionError) as error:
                results[config+'.'+workload] = {'status': 'INCOMPLETE_OR_FAILED',
                    'error': str(error), 'evidence': str(d)}
    if not all(r['status'] == 'PASS' for r in results.values()):
        (out/'result.json').write_text(json.dumps({'status': 'FAIL', 'results': results}, indent=2)+'\n')
        return 1
    normal, fault8, fault18 = cores/'normal', cores/'fault8', cores/'fault18'
    call('trap', [ROLLBACK/'fullcore_scoreboard.py', '--normal', normal/'trap/run.log',
                  '--fault', fault8/'trap/run.log', '--require-trap-io'])
    call('sv39', [HERE.parent/'sv39/scoreboard.py', '--normal', normal/'sv39/run.log',
                  '--fault', fault8/'sv39/run.log', '--report', out/'sv39/report.json'])
    for profile in ('output', 'amo'):
        call(profile, [ROLLBACK/'io_effect_scoreboard.py', '--normal', normal/profile/'run.log',
            '--fault', fault18/profile/'run.log', '--effects', fault18/profile/'effects.log',
            '--failed-seq', '18', '--require-'+profile, '--report', out/profile/'report.json'])
    irq_args = ['--normal', normal/'irq/run.log', '--fault', fault18/'irq/run.log',
                '--normal-effects', normal/'irq/effects.log', '--fault-effects', fault18/'irq/effects.log',
                '--normal-irq', normal/'irq/irq.log', '--fault-irq', fault18/'irq/irq.log']
    call('irq', [HERE/'interrupt_scoreboard.py', *irq_args, '--report', out/'irq/report.json'])
    call('irq_negative', [HERE/'interrupt_negative_test.py', *irq_args,
                         '--out', out/'irq_negative/cases'])
    rebase_args = ['--normal', normal/'trap/run.log', '--fault', rebase/'run.log',
                   '--effects', rebase/'effects.log', '--overlap', rebase/'overlap.log']
    call('io_rebase', [HERE/'io_rebase_scoreboard.py', *rebase_args,
                      '--report', out/'io_rebase/report.json'])
    call('io_rebase_negative', [HERE/'io_rebase_negative_test.py', *rebase_args,
                               '--out', out/'io_rebase_negative/cases'])
    pressure_args = ['--program', pressure/'run.log', '--pressure', pressure/'pressure.log',
                     '--run-exit', pressure/'run.exit']
    call('pressure', [HERE/'pressure_scoreboard.py', *pressure_args,
                      '--report', out/'pressure/report.json'])
    call('pressure_negative', [HERE/'pressure_negative_test.py', *pressure_args,
                               '--out', out/'pressure_negative/cases'])
    passed = all(r['status'] == 'PASS' for r in results.values())
    assert all(digest(Path(p)) == h for p, h in hashes.items()), 'scoring tools changed'
    result = {'status': 'PASS' if passed else 'FAIL', 'scope': 'complete Core oracles and negative tests',
        'results': results, 'tools': hashes,
        'separate_required_reviews': ['source/model relationship including pressure source delta',
            'original69 task acceptance', 'physical synthesis/timing/CDC status']}
    (out/'result.json').write_text(json.dumps(result, indent=2) + '\n')
    print('PALIMPSEST_SYSTEM_ACCEPTANCE=' + result['status'])
    return 0 if passed else 1


if __name__ == '__main__':
    raise SystemExit(main())
