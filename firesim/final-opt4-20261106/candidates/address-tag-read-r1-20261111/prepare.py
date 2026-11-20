#!/usr/bin/python3
"""Bind the tag-read candidate; submit only when a broker CPU slot is free."""
from pathlib import Path
import hashlib
import importlib.util
import json
import os
import subprocess
import sys

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
F = W/'Opt4-fit-address-tag-read-r1-20261111'
C = W/'candidates/address-tag-read-r1-20261111'
TEMPLATE = W/'candidates/address-decode-r1-20261111'
TEMPLATE_TREE = W/'Opt4-fit-address-decode-r1-20261111'
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
spec = importlib.util.spec_from_file_location('opt4_tag_read_build_hw', W/'scripts/build_hw.py')
build_hw = importlib.util.module_from_spec(spec)
spec.loader.exec_module(build_hw)
inventory = build_hw.inventory(F/'chipyard')
source_id = hashlib.sha256(json.dumps(inventory, sort_keys=True).encode()).hexdigest()
patch = subprocess.check_output(['git', 'show', '--format=', '--binary', COMMIT], cwd=F)
binding = dict(
    schema='ec-opt4-address-tag-read-binding/1',
    hardware_commit=COMMIT,
    source_id=source_id,
    parent_commit=PARENT,
    frozen_commit='8491167d84b6d9521b151a743673c1516926a1f8',
    profile='Opt4-fit-address-tag-read-r1-candidate',
    production_selected=False,
    formal_admission=False,
    candidate_change=(
        'Select {valid,sequence} as one packed dynamic bucket-tag read for '
        'current, retiring, and qualified-error checks; counter state, widths, '
        'writes, and cycle behavior are otherwise unchanged.'),
    patch_sha256=hashlib.sha256(patch).hexdigest())

atomic_json(F/'source-inventory.json', inventory)
atomic_bytes(F/'candidate.patch', patch)
atomic_json(F/'candidate-binding.json', binding)
for name in ['frozen-original.v', 'frozen-tb.v']:
    exact_copy(TEMPLATE/name, C/name)
exact_copy(TEMPLATE_TREE/'chipyard/generators/boom/src/main/scala/lsu/AddressBucketAccess.scala',
           C/'AddressBucketAccess.scala')
config = json.loads((C/'config.json').read_text())
config['binding'] = binding
config['worktree'] = str(F)
atomic_json(C/'config.json', config)
atomic_json(C/'binding.json', binding)

design = F/'chipyard/generators/boom/src/main/scala/lsu/PackageAddressStats.scala'
deps = [Path(p) for p in config['classpath'] + config['compiler'] + [config['plugin']]]
other_inputs = [
    F/'source-inventory.json', F/'candidate.patch', F/'candidate-binding.json',
    C/'controller.py', C/'prepare.py', C/'config.json', C/'binding.json',
    C/'EmitDecode.scala', C/'AddressBucketAccess.scala',
    C/'frozen-original.v', C/'frozen-tb.v', W/'scripts/build_hw.py']
input_paths = sorted(set([design] + deps + other_inputs), key=str)
input_hashes = {str(path): sha(path) for path in input_paths}
atomic_json(C/'input-hashes.json', input_hashes)

job_name = 'address-tag-read-r1-' + COMMIT[:8]
state = D/'Opt4-fit-address-tag-read-r1-state.json'
out = D/'build-logs/Opt4-fit-address-tag-read-r1-20261111'
request = dict(action='cpu_job', spec=dict(
    name=job_name,
    kind='module',
    cwd=str(F),
    argv=['/usr/bin/python3', str(C/'controller.py')],
    inputs={**input_hashes, str(C/'input-hashes.json'): sha(C/'input-hashes.json')},
    outputs=[str(out/'result.json'), str(out/'verified-local.json')],
    checkpoints=[str(state), str(out/'verified-local.json')]))
request_path = U/'requests'/(job_name + '.json')
preflight = dict(
    schema='ec-opt4-address-tag-read-preflight/1',
    status='BOUND_AWAITING_CPU_SLOT',
    hardware_commit=COMMIT,
    source_id=source_id,
    parent_commit=PARENT,
    frozen_commit=binding['frozen_commit'],
    candidate_change=binding['candidate_change'],
    patch_sha256=binding['patch_sha256'],
    input_hashes_sha256=sha(C/'input-hashes.json'),
    request=str(request_path),
    request_submitted=False,
    proof_limits=[
        'No local SAT, actual-size simulation, full-module comparison, or OOC map has run yet.',
        'This candidate is not admitted to full-DUT or formal builds.'])
atomic_json(out/'candidate-preflight.json', preflight)
if '--submit' in sys.argv:
    if request_path.exists():
        assert json.loads(request_path.read_text()) == request, 'immutable request conflict'
    else:
        atomic_json(request_path, request)
    status = 'REQUEST_READY'
    preflight['status'] = status
    preflight['request_submitted'] = True
    atomic_json(out/'candidate-preflight.json', preflight)
else:
    status = 'BOUND_AWAITING_CPU_SLOT'
print(json.dumps(dict(status=status, job=job_name, hardware_commit=COMMIT,
                      source_id=source_id, request=str(request_path)), sort_keys=True))
