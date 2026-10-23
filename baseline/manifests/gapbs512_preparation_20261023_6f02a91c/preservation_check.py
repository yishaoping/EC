"""Record project identities without refreshing any Git index."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys

ROOT = Path('/data1/gzh/EC')
OUT = Path(__file__).resolve().parent


def sha(path):
    h = hashlib.sha256()
    with path.open('rb') as stream:
        for block in iter(lambda: stream.read(1048576), b''):
            h.update(block)
    return h.hexdigest()


def git(directory, *args):
    return subprocess.check_output(
        ['git', '--no-optional-locks', '-c', 'core.fsmonitor=false', '-C', str(directory), *args],
        env={**os.environ, 'GIT_OPTIONAL_LOCKS': '0'})


def snapshot():
    paths = git(ROOT, 'ls-files', '-z', 'chipyard').decode().split('\0')
    identities = {}
    for name in filter(None, paths):
        p = ROOT / name
        if p.is_symlink():
            identities[name] = {'symlink': os.readlink(p)}
        elif p.is_file():
            identities[name] = {'sha256': sha(p)}
        elif p.is_dir():
            identities[name] = {'directory': True}
        else:
            identities[name] = {'missing': True}
    previous = json.loads((ROOT / 'baseline/manifests/common_benchmark_20261023_fa82d07b/preservation.before.json').read_text())
    protected = {n: sha(ROOT / n) for n in previous['files']
                 if n not in ('baseline/launch_baseline.py', 'baseline/start_baseline_experiment.sh')}
    current = ROOT / 'chipyard/sims/verilator/output/chipyard.TestHarness.v1Config'
    for name in ('test.log', 'test.vcd', 'test.out', 'test.loadmem_hex'):
        p = current / name
        protected[str(p.relative_to(ROOT))] = sha(p)
    return {'root_head': git(ROOT, 'rev-parse', 'HEAD').decode().strip(),
            'root_status': git(ROOT, 'status', '--porcelain=v1', '--untracked-files=normal').decode(),
            'root_index': sha(ROOT / '.git/index'),
            'source_head': git(ROOT / 'baseline/source', 'rev-parse', 'HEAD').decode().strip(),
            'source_status': git(ROOT / 'baseline/source', 'status', '--porcelain=v1').decode(),
            'source_index': sha(ROOT / 'baseline/source/.git/index'),
            'chipyard_tracked_count': len(identities),
            'chipyard_tracked_digest': hashlib.sha256(json.dumps(identities, sort_keys=True).encode()).hexdigest(),
            'protected_files': protected}


if __name__ == '__main__':
    phase = sys.argv[1]
    assert phase in ('before', 'after')
    result = snapshot()
    if phase == 'after':
        before = json.loads((OUT / 'preservation.before.json').read_text())
        if result != before:
            raise SystemExit('Preservation mismatch; inspect before and current identities')
        result['preservation'] = 'PASS'
    with (OUT / ('preservation.' + phase + '.json')).open('x') as stream:
        json.dump(result, stream, indent=2, ensure_ascii=False)
        stream.write('\n')
    print(phase + ': identities recorded; tracked Current files=' + str(result['chipyard_tracked_count']))
