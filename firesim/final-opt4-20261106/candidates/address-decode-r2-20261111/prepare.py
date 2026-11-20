#!/usr/bin/python3
"""Bind the R2 RTL commit, proof inputs, and broker request atomically."""
from pathlib import Path
import datetime
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
F = W/'Opt4-fit-address-decode-r2-20261111'
C = W/'candidates/address-decode-r2-20261111'
R1 = W/'candidates/address-decode-r1-20261111'
R1_TREE = W/'Opt4-fit-address-decode-r1-20261111'
COMMIT = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=F, text=True).strip()
PARENT = subprocess.check_output(['git', 'rev-parse', 'HEAD^'], cwd=F, text=True).strip()

def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()

def atomic_bytes(path, data):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    tmp = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with tmp.open('wb') as f:
        f.write(data)
        f.flush()
        os.fsync(f.fileno())
    os.replace(tmp, path)

def atomic_json(path, value):
    atomic_bytes(path, (json.dumps(value, indent=2, sort_keys=True) + '\n').encode())

def exact_copy(src, dst):
    data = Path(src).read_bytes()
    if Path(dst).exists():
        assert Path(dst).read_bytes() == data, f'input conflict: {dst}'
    else:
        atomic_bytes(dst, data)

sys.path.insert(0, str(W/'scripts'))
spec = importlib.util.spec_from_file_location('opt4_build_hw_inventory', W/'scripts/build_hw.py')
build_hw = importlib.util.module_from_spec(spec)
spec.loader.exec_module(build_hw)
inventory = build_hw.inventory(F/'chipyard')
source_id = hashlib.sha256(json.dumps(inventory, sort_keys=True).encode()).hexdigest()
patch = subprocess.check_output(['git', 'show', '--format=', '--binary', COMMIT], cwd=F)
binding = dict(
    schema='ec-opt4-address-decode-binding/1',
    hardware_commit=COMMIT,
    source_id=source_id,
    parent_commit=PARENT,
    frozen_commit='8491167d84b6d9521b151a743673c1516926a1f8',
    profile='Opt4-fit-address-decode-r2-candidate',
    production_selected=False,
    formal_admission=False,
    candidate_change='Use native dynamic Vec reads for per-entry bucket-tag checks; retain shared one-hot current/retiring reads.',
    patch_sha256=hashlib.sha256(patch).hexdigest())

atomic_json(F/'source-inventory.json', inventory)
atomic_bytes(F/'candidate.patch', patch)
atomic_json(F/'candidate-binding.json', binding)

for name in ['EmitDecode.scala', 'frozen-original.v', 'frozen-tb.v']:
    exact_copy(R1/name, C/name)
config = json.loads((R1/'config.json').read_text())
config['binding'] = binding
config['worktree'] = str(F)
atomic_json(C/'config.json', config)
atomic_json(C/'binding.json', binding)

design_rel = Path('chipyard/generators/boom/src/main/scala/lsu')
design_files = [F/design_rel/name for name in [
    'PackageAddressStats.scala', 'AddressBucketAccess.scala', 'AddressBucketReduction.scala']]
deps = [Path(p) for p in config['classpath'] + config['compiler'] + [config['plugin']]]
other_inputs = [
    F/'source-inventory.json', F/'candidate.patch', F/'candidate-binding.json',
    C/'controller.py', C/'prepare.py', C/'config.json', C/'binding.json',
    C/'EmitDecode.scala', C/'frozen-original.v', C/'frozen-tb.v',
    R1/'controller.py']
input_paths = sorted(set(design_files + deps + other_inputs), key=str)
input_hashes = {str(path): sha(path) for path in input_paths}
atomic_json(C/'input-hashes.json', input_hashes)

job_name = 'address-decode-r2-' + COMMIT[:8]
state = D/'Opt4-fit-address-decode-r2-state.json'
out = D/'build-logs/Opt4-fit-address-decode-r2-20261111'
request = dict(action='cpu_job', spec=dict(
    name=job_name,
    kind='module',
    cwd=str(F),
    argv=['/usr/bin/python3', str(C/'controller.py')],
    inputs={**input_hashes, str(C/'input-hashes.json'): sha(C/'input-hashes.json')},
    outputs=[str(out/'result.json'), str(out/'verified-local.json')],
    checkpoints=[str(state), str(out/'verified-local.json')]))
request_path = U/'requests'/(job_name + '.json')
if request_path.exists():
    assert json.loads(request_path.read_text()) == request, 'immutable request conflict; use a new version'
else:
    atomic_json(request_path, request)
print(json.dumps(dict(status='REQUEST_READY', job=job_name, hardware_commit=COMMIT,
                      source_id=source_id, request=str(request_path)), sort_keys=True))
