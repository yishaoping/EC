#!/usr/bin/python3
"""Prepare the W-contained immutable inputs and optional bind2 broker request."""
from pathlib import Path
import hashlib
import importlib.util
import json
import os
import shutil
import subprocess
import sys

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
F = W/'Opt4-fit-address-index-share-r1-20261111'
C = W/'candidates/address-index-share-r1-bind2-20261111'
TEMPLATE = W/'candidates/address-tag-read-r1-20261111'
REFERENCE = D/'build-logs/Opt4-fit-address-sort-11edd719-20261110/compare'
EVIDENCE = D/'build-logs/Opt4-fit-address-index-share-r1-bind2-20261111'
JOB = 'address-index-share-r1-bind2-470f1291'
REL = 'chipyard/generators/boom/src/main/scala/lsu/PackageAddressStats.scala'


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
    binding = json.loads((F/'candidate-binding.json').read_text())
    commit = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=F, text=True).strip()
    parent = subprocess.check_output(['git', 'rev-parse', 'HEAD^'], cwd=F, text=True).strip()
    assert commit == binding['hardware_commit'] == '470f1291d01608e80be6cd8d42b29fc5fc28d395'
    assert parent == binding['parent_commit'] == '8da24a269b98a0d6a8f57b030353a310812c4344'
    assert sha(F/'candidate.patch') == binding['patch_sha256']

    spec = importlib.util.spec_from_file_location('index_share_build_hw', W/'scripts/build_hw.py')
    build_hw = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(build_hw)
    inventory = build_hw.inventory(F/'chipyard')
    source_id = hashlib.sha256(json.dumps(inventory, sort_keys=True).encode()).hexdigest()
    assert source_id == binding['source_id']
    assert json.loads((F/'source-inventory.json').read_text()) == inventory

    parent_source = subprocess.check_output(['git', 'show', parent+':'+REL], cwd=F)
    atomic(C/'parent-PackageAddressStats.scala', parent_source)
    exact_copy(REFERENCE/'original.v', C/'frozen-original.v')
    exact_copy(REFERENCE/'tb.v', C/'frozen-tb.v')
    config = json.loads((TEMPLATE/'config.json').read_text())
    config['binding'] = binding
    config['worktree'] = str(F)
    atomic_json(C/'config.json', config)

    source = F/REL
    deps = [Path(path) for path in config['classpath']+config['compiler']+[config['plugin']]]
    sources = [source, C/'controller.py', C/'prepare.py', C/'EmitIndexShare.scala', C/'config.json',
        C/'parent-PackageAddressStats.scala', C/'frozen-original.v', C/'frozen-tb.v',
        F/'source-inventory.json', F/'candidate.patch', F/'candidate-binding.json',
        W/'scripts/build_hw.py']
    input_paths = sorted(set(sources+deps), key=str)
    assert all(path.resolve().is_relative_to(W) and path.is_file() for path in input_paths)
    hashes = {str(path): sha(path) for path in input_paths}
    atomic_json(C/'input-hashes.json', hashes)
    atomic_json(EVIDENCE/'input-hashes.json', hashes)

    request_path = U/'requests'/(JOB+'.json')
    state = D/'Opt4-fit-address-index-share-r1-bind2-state.json'
    result = EVIDENCE/'result.json'
    verified = EVIDENCE/'verified-local.json'
    request = dict(action='cpu_job', spec=dict(
        name=JOB, kind='module', cwd=str(F/'chipyard'),
        argv=['/usr/bin/python3', str(C/'controller.py')],
        inputs={**hashes, str(C/'input-hashes.json'): sha(C/'input-hashes.json')},
        outputs=[str(result), str(verified)], checkpoints=[str(state), str(verified)]))
    preflight = dict(schema='ec-opt4-address-index-share-preflight/1', status='BOUND_AWAITING_CPU_SLOT',
        hardware_commit=commit, source_id=source_id, parent_commit=parent,
        frozen_commit=binding['frozen_commit'], patch_sha256=binding['patch_sha256'],
        candidate_change=binding['candidate_change'], input_hashes_sha256=sha(C/'input-hashes.json'),
        input_count=len(hashes), frozen_reference_sha256=sha(C/'frozen-original.v'),
        frozen_testbench_sha256=sha(C/'frozen-tb.v'), request=str(request_path), request_submitted=False,
        limits=['All request inputs resolve under W; outputs and evidence are under D.',
                'No full-DUT synthesis/formal admission or FPGA access.',
                'The module OOC map does not establish whole-system FIT.'])
    atomic_json(EVIDENCE/'candidate-preflight.json', preflight)
    if '--submit' not in sys.argv:
        print(json.dumps(dict(status=preflight['status'], name=JOB, commit=commit,
                              source_id=source_id, request=str(request_path), input_count=len(hashes)), sort_keys=True))
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
                          source_id=source_id, request=str(request_path), input_count=len(hashes)), sort_keys=True))


if __name__ == '__main__':
    main()
