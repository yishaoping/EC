#!/usr/bin/python3
"""Bind proof inputs and optionally submit the index-share module job."""
from pathlib import Path
import hashlib
import json
import os
import shutil
import subprocess
import sys

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
F = W/'Opt4-fit-address-index-share-r1-20261111'
C = W/'candidates/address-index-share-r1-20261111'
TEMPLATE = W/'candidates/address-tag-read-r1-20261111'
REFERENCE = D/'build-logs/Opt4-fit-address-sort-11edd719-20261110/compare'
EVIDENCE = D/'build-logs/Opt4-fit-address-index-share-r1-20261111'
JOB = 'address-index-share-r1-470f1291'


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def atomic(path, data):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    tmp = path.with_name(path.name+'.tmp-'+str(os.getpid()))
    with tmp.open('wb') as f:
        f.write(data)
        f.flush()
        os.fsync(f.fileno())
    os.replace(tmp, path)


def atomic_json(path, value):
    atomic(path, (json.dumps(value, indent=2, sort_keys=True)+'\n').encode())


def exact_copy(src, dst):
    data = Path(src).read_bytes()
    if Path(dst).exists():
        assert Path(dst).read_bytes() == data, f'immutable file mismatch: {dst}'
    else:
        atomic(dst, data)


def main():
    binding_path = EVIDENCE/'candidate-binding.json'
    binding = json.loads(binding_path.read_text())
    commit = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=F, text=True).strip()
    assert commit == binding['hardware_commit'] == '470f1291d01608e80be6cd8d42b29fc5fc28d395'
    exact_copy(REFERENCE/'original.v', C/'frozen-original.v')
    exact_copy(REFERENCE/'tb.v', C/'frozen-tb.v')
    config = json.loads((TEMPLATE/'config.json').read_text())
    config['binding'] = binding
    config['worktree'] = str(F)
    atomic_json(C/'config.json', config)

    source = F/'chipyard/generators/boom/src/main/scala/lsu/PackageAddressStats.scala'
    deps = [Path(path) for path in config['classpath']+config['compiler']+[config['plugin']]]
    sources = [source, C/'controller.py', C/'prepare.py', C/'EmitIndexShare.scala',
        C/'config.json', C/'frozen-original.v', C/'frozen-tb.v', binding_path,
        EVIDENCE/'source-inventory.json', EVIDENCE/'candidate.patch',
        EVIDENCE/'source-input-hashes.json', W/'scripts/build_hw.py']
    hashes = {str(path): sha(path) for path in sorted(set(sources+deps), key=str)}
    atomic_json(C/'input-hashes.json', hashes)

    request_path = U/'requests'/(JOB+'.json')
    state = D/'Opt4-fit-address-index-share-r1-state.json'
    result = EVIDENCE/'result.json'
    verified = EVIDENCE/'verified-local.json'
    request = dict(action='cpu_job', spec=dict(
        name=JOB, kind='module', cwd=str(F/'chipyard'),
        argv=['/usr/bin/python3', str(C/'controller.py')],
        inputs={**hashes, str(C/'input-hashes.json'): sha(C/'input-hashes.json')},
        outputs=[str(result), str(verified)],
        checkpoints=[str(state), str(verified)]))
    preflight = dict(schema='ec-opt4-address-index-share-preflight/1',
        status='BOUND_AWAITING_CPU_SLOT', hardware_commit=commit,
        source_id=binding['source_id'], parent_commit=binding['parent_commit'],
        frozen_commit=binding['frozen_commit'], patch_sha256=binding['patch_sha256'],
        candidate_change=binding['candidate_change'], input_hashes_sha256=sha(C/'input-hashes.json'),
        frozen_reference_sha256=sha(C/'frozen-original.v'), frozen_testbench_sha256=sha(C/'frozen-tb.v'),
        request=str(request_path), request_submitted=False,
        limits=['No full-DUT synthesis/formal admission or FPGA access.',
                'The module OOC map does not establish whole-system FIT.'])
    atomic_json(EVIDENCE/'candidate-preflight.json', preflight)
    if '--submit' not in sys.argv:
        print(json.dumps(dict(status=preflight['status'], name=JOB, commit=commit,
                              source_id=binding['source_id'], request=str(request_path)), sort_keys=True))
        return
    available = int(next(line.split()[1] for line in Path('/proc/meminfo').read_text().splitlines()
                         if line.startswith('MemAvailable:')))
    assert available >= config['minimum_memory_gib']*2**20
    assert shutil.disk_usage(W).free >= config['minimum_disk_gib']*2**30
    if request_path.exists():
        assert json.loads(request_path.read_text()) == request, 'immutable request conflict; use a new version'
    else:
        atomic_json(request_path, request)
    preflight.update(status='REQUEST_READY', request_submitted=True)
    atomic_json(EVIDENCE/'candidate-preflight.json', preflight)
    print(json.dumps(dict(status='REQUEST_READY', name=JOB, commit=commit,
                          source_id=binding['source_id'], request=str(request_path)), sort_keys=True))


if __name__ == '__main__':
    main()
