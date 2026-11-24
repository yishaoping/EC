#!/usr/bin/env python3
"""Build and run production full Cores for normal, two FAILs, and I/O+rebase.

Uses one unmodified compact-trap-io ELF for every configuration. Model/source
and workload hashes, raw exits and strict complete-program oracles are retained.
"""
import argparse
import concurrent.futures
import json
import os
from pathlib import Path
import resource
import subprocess
import sys

from build_io_observer import digest
import source_manifest

ROOT = Path(__file__).resolve().parents[4]
SCRIPTS = Path(__file__).resolve().parent
CONFIGS = {'normal': 'v1Config', 'two-faults': 'PalimpsestTwoFaultTestConfig',
           'io-rebase': 'PalimpsestFault40Seq41TestConfig'}


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


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--out', type=Path, required=True)
    p.add_argument('--binary', type=Path, required=True)
    p.add_argument('--sbt', type=Path, required=True)
    p.add_argument('--jobs', type=int, default=6)
    p.add_argument('--max-cycles', type=int, default=3000000)
    a = p.parse_args()
    out, binary = a.out.resolve(), a.binary.resolve()
    image = binary.with_suffix('.hex')
    assert out.is_relative_to(ROOT / 'AI/TMP') and not out.exists()
    assert binary.is_file() and image.is_file()
    out.mkdir()
    before = source_manifest.capture()
    (out / 'sources.before.json').write_text(json.dumps(before, indent=2, sort_keys=True) + '\n')
    results = {}

    def run(kind):
        config = CONFIGS[kind]
        model = out / kind
        env = dict(os.environ, PALIMPSEST_FULL_OUT=str(model), PALIMPSEST_CONFIG=config,
                   PALIMPSEST_SBT=str(a.sbt.resolve()), PALIMPSEST_BUILD_JOBS=str(a.jobs))
        env.pop('PALIMPSEST_BINARY', None)
        env.pop('PALIMPSEST_IO_NORMAL_LOG', None)
        command(['bash', str(SCRIPTS / 'user_fullcore.sh')], out, kind + '.build', env)
        sim = model / ('simulator-chipyard-' + config)
        if kind == 'io-rebase':
            name = 'chipyard.TestHarness.' + config
            command([sys.executable, '-B', str(SCRIPTS / 'build_io_observer.py'),
                     '--model-dir', str(model / 'generated-src' / name / name),
                     '--out', str(model / 'observer'), '--with-rebase'], model, 'observer')
            sim = model / 'observer/simulator'
        dest = model / 'program'
        dest.mkdir()
        inputs = [sim, binary, image, model / 'sources.before.json',
                  SCRIPTS / 'concurrency_scoreboard.py', SCRIPTS / 'fullcore_scoreboard.py',
                  SCRIPTS / 'io_effect_scoreboard.py',
                  SCRIPTS.parent / 'fullcore_concurrency/io_rebase_scoreboard.py',
                  Path(__file__).resolve()]
        hashes = {str(p): digest(p) for p in inputs}
        (dest / 'inputs.json').write_text(json.dumps(hashes, indent=2) + '\n')
        env = dict(os.environ, PALIMPSEST_IO_EFFECT_LOG=str(dest / 'effects.log'),
                   PALIMPSEST_OVERLAP_LOG=str(dest / 'overlap.log'))
        command([str(sim), '--verbose', '+permissive', f'+max-cycles={a.max_cycles}',
                 '+loadmem=' + str(image), '+loadmem_addr=80000000', '+permissive-off',
                 str(binary)], dest, 'run', env)
        command([sys.executable, '-B', str(SCRIPTS / 'fullcore_scoreboard.py'),
                 '--single', str(dest / 'run.log'), '--require-trap-io'], dest, 'oracle')
        assert all(digest(Path(p)) == h for p, h in hashes.items()), 'run inputs changed'
        return {'status': 'PASS', 'raw_exit': 0, 'architecture_oracle': 'PASS'}

    with concurrent.futures.ThreadPoolExecutor(max_workers=3) as pool:
        jobs = {pool.submit(run, k): k for k in CONFIGS}
        for job in concurrent.futures.as_completed(jobs):
            kind = jobs[job]
            try:
                results[kind] = job.result()
            except Exception as error:
                results[kind] = {'status': 'FAIL', 'error': repr(error)}
            (out / 'progress.json').write_text(json.dumps(results, indent=2) + '\n')
    for kind in ('two-faults', 'io-rebase'):
        dest = out / kind / 'program'
        try:
            assert all(results[k]['status'] == 'PASS' for k in ('normal', kind))
            scorer = (SCRIPTS.parent / 'fullcore_concurrency/io_rebase_scoreboard.py'
                      if kind == 'io-rebase' else SCRIPTS / 'concurrency_scoreboard.py')
            args = [sys.executable, '-B', str(scorer),
                    '--normal', str(out / 'normal/program/run.log'),
                    '--fault', str(dest / 'run.log'),
                    '--report', str(dest / 'result.json')]
            if kind == 'io-rebase':
                args += ['--effects', str(dest / 'effects.log'), '--overlap', str(dest / 'overlap.log')]
            else:
                args += ['--kind', kind]
            command(args, dest, 'scoreboard')
            results[kind + '.pair'] = {'status': 'PASS'}
        except Exception as error:
            results[kind + '.pair'] = {'status': 'FAIL', 'error': repr(error)}
    after = source_manifest.capture()
    (out / 'sources.after.json').write_text(json.dumps(after, indent=2, sort_keys=True) + '\n')
    results['fixed_sources'] = {'status': 'PASS' if before == after else 'FAIL'}
    (out / 'summary.json').write_text(json.dumps(results, indent=2) + '\n')
    passed = all(r['status'] == 'PASS' for r in results.values())
    print('PALIMPSEST_CONCURRENCY_REGRESSION=' + ('PASS' if passed else 'FAIL'))
    return 0 if passed else 1


if __name__ == '__main__':
    raise SystemExit(main())
