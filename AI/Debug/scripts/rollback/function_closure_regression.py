#!/usr/bin/env python3
"""Build fixed production sources and validate the complete C/E control chain.

All workload inputs are explicit existing ELFs with adjacent loadmem .hex files.
Any build, run, physical-load oracle or strict scoreboard failure exits nonzero.
The old Sv39 reproducer must use --sv39-load-pc 0x8000045c.
"""
import argparse
import concurrent.futures
import hashlib
import json
import os
from pathlib import Path
import re
import resource
import subprocess
import sys

import fullcore_scoreboard
import source_manifest
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'sv39'))
from scoreboard import scan as scan_sv39

ROOT = Path(__file__).resolve().parents[4]
SCRIPTS = Path(__file__).resolve().parent
CONFIGS = {'normal': 'v1Config', 'fault': 'PalimpsestFault8Config',
           'seq': 'PalimpsestSeqRebaseTestConfig', 'iofault': 'PalimpsestFault18TestConfig'}


def digest(path):
    h = hashlib.sha256()
    with path.open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def no_core():
    resource.setrlimit(resource.RLIMIT_CORE, (0, 0))


def command(args, dest, stem, env=None):
    (dest / (stem + '.command.json')).write_text(json.dumps(args, indent=2) + '\n')
    with (dest / (stem + '.log')).open('x') as log:
        ret = subprocess.run(args, cwd=dest, env=env, stdout=log,
                             stderr=subprocess.STDOUT, preexec_fn=no_core).returncode
    (dest / (stem + '.exit')).write_text(str(ret) + '\n')
    if ret:
        raise RuntimeError(f'{stem} exit {ret}: {dest}')


def sv39_loads(path, pc):
    return scan_sv39(path, pc)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True)
    for name in ['trap-io', 'sv39', 'output', 'amo']:
        parser.add_argument('--' + name, type=Path, required=True)
    parser.add_argument('--sv39-load-pc', type=lambda s: int(s, 0), default=0x8000045c)
    parser.add_argument('--sbt', type=Path, required=True)
    parser.add_argument('--jobs', type=int, default=6)
    parser.add_argument('--max-cycles', type=int, default=3000000)
    args = parser.parse_args()
    out = args.out.resolve()
    assert out.is_relative_to(ROOT / 'AI/TMP') and not out.exists()
    workloads = {p: getattr(args, p.replace('-', '_')).resolve()
                 for p in ['trap-io', 'sv39', 'output', 'amo']}
    for binary in workloads.values():
        assert binary.is_file() and binary.with_suffix('.hex').is_file(), binary
    out.mkdir()
    before = source_manifest.capture()
    (out / 'sources.before.json').write_text(json.dumps(before, indent=2, sort_keys=True) + '\n')
    results = {}

    def run(kind):
        config = CONFIGS[kind]
        model = out / kind
        env = dict(os.environ, PALIMPSEST_FULL_OUT=str(model), PALIMPSEST_CONFIG=config,
                   PALIMPSEST_SBT=str(args.sbt.resolve()), PALIMPSEST_BUILD_JOBS=str(args.jobs))
        env.pop('PALIMPSEST_BINARY', None)
        env.pop('PALIMPSEST_IO_NORMAL_LOG', None)
        command(['bash', str(SCRIPTS / 'user_fullcore.sh')], out, kind + '.build', env)
        sim = model / ('simulator-chipyard-' + config)
        observer = None
        if kind in {'normal', 'iofault'}:
            model_dir = model / 'generated-src' / ('chipyard.TestHarness.' + config) / ('chipyard.TestHarness.' + config)
            command([sys.executable, str(SCRIPTS / 'build_io_observer.py'), '--model-dir',
                     str(model_dir), '--out', str(model / 'io-observer')], model, 'observer')
            observer = model / 'io-observer/simulator'
        profiles = {'normal': list(workloads), 'fault': ['trap-io', 'sv39'],
                    'seq': ['trap-io'], 'iofault': ['output', 'amo']}[kind]
        runs = {}
        for profile in profiles:
            dest = model / profile
            dest.mkdir()
            binary = workloads[profile]
            image = binary.with_suffix('.hex')
            selected = observer if profile in {'output', 'amo'} else sim
            run_env = dict(os.environ, PALIMPSEST_IO_EFFECT_LOG=str(dest / 'effects.log'))
            inputs = [selected, binary, image, model / 'sources.before.json',
                      SCRIPTS / 'fullcore_scoreboard.py', Path(__file__).resolve()]
            (dest / 'inputs.json').write_text(json.dumps({str(p): digest(p) for p in inputs}, indent=2) + '\n')
            command([str(selected), '--verbose', '+permissive', f'+max-cycles={args.max_cycles}',
                     '+loadmem=' + str(image), '+loadmem_addr=80000000', '+permissive-off', str(binary)],
                    dest, 'run', run_env)
            if kind != 'iofault':
                score = ['--rebase' if kind == 'seq' else '--single', str(dest / 'run.log')]
                if profile != 'sv39':
                    score += ['--require-trap-io']
                command([sys.executable, str(SCRIPTS / 'fullcore_scoreboard.py')] + score, dest, 'scoreboard')
            if profile == 'sv39':
                records = sv39_loads(dest / 'run.log', args.sv39_load_pc)
                (dest / 'physical_loads.json').write_text(json.dumps(records, indent=2) + '\n')
            runs[profile] = 'PASS'
        return runs

    # Scala generation is serialized by the supplied sbt wrapper; independent
    # model builds and executions can proceed in parallel.
    with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
        jobs = {pool.submit(run, kind): kind for kind in CONFIGS}
        for job in concurrent.futures.as_completed(jobs):
            kind = jobs[job]
            try:
                results[kind] = {'status': 'PASS', 'runs': job.result()}
            except Exception as error:
                results[kind] = {'status': 'FAIL', 'error': repr(error)}
            (out / 'progress.json').write_text(json.dumps(results, indent=2) + '\n')
    for profile in ['trap-io', 'sv39', 'output', 'amo']:
        kind = 'fault' if profile in {'trap-io', 'sv39'} else 'iofault'
        try:
            normal = out / 'normal' / profile / 'run.log'
            fault = out / kind / profile / 'run.log'
            assert all((p.parent / 'run.exit').read_text().strip() == '0' for p in [normal, fault])
            if kind == 'fault':
                if profile == 'sv39':
                    score = [sys.executable, str(SCRIPTS.parent / 'sv39/scoreboard.py'),
                             '--normal', str(normal), '--fault', str(fault),
                             '--report', str(out / 'sv39.report.json')]
                else:
                    score = [sys.executable, str(SCRIPTS / 'fullcore_scoreboard.py'),
                             '--normal', str(normal), '--fault', str(fault), '--require-trap-io']
            else:
                score = [sys.executable, str(SCRIPTS / 'io_effect_scoreboard.py'),
                         '--normal', str(normal), '--fault', str(fault), '--failed-seq', '18',
                         '--effects', str(fault.parent / 'effects.log'), '--require-' + profile,
                         '--report', str(out / (profile + '.report.json'))]
            command(score, out, profile + '.pair')
            results[profile + '.pair'] = {'status': 'PASS'}
        except Exception as error:
            results[profile + '.pair'] = {'status': 'FAIL', 'error': repr(error)}
    after = source_manifest.capture()
    (out / 'sources.after.json').write_text(json.dumps(after, indent=2, sort_keys=True) + '\n')
    results['fixed_sources'] = {'status': 'PASS' if before == after else 'FAIL'}
    (out / 'summary.json').write_text(json.dumps(results, indent=2) + '\n')
    passed = all(item['status'] == 'PASS' for item in results.values())
    print('PALIMPSEST_FUNCTION_CLOSURE=' + ('PASS' if passed else 'FAIL'))
    return 0 if passed else 1


if __name__ == '__main__':
    raise SystemExit(main())
