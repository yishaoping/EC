#!/usr/bin/python3
"""Bind the group8 RTL, evidence, toolchain and broker request immutably."""
from pathlib import Path
import ast
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
C = W/'candidates/address-group8-r1-20261111'
F = W/'Opt4-fit-address-group8-r1-20261111'
T = W/'candidates/address-group4-r1-20261111'
O = D/'build-logs/Opt4-fit-address-group8-r1-20261111'
REL = 'chipyard/generators/boom/src/main/scala/lsu/'
PARENT = '981b890d870130f99ec24a0c5e37acb39362318a'
FROZEN = '8491167d84b6d9521b151a743673c1516926a1f8'

def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(1 << 20), b''):
            h.update(block)
    return h.hexdigest()

def write(path, data):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists():
        assert path.read_bytes() == data, 'immutable conflict: ' + str(path)
        return
    tmp = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with tmp.open('xb') as f:
        f.write(data); f.flush(); os.fsync(f.fileno())
    os.replace(tmp, path)

def save(path, value):
    write(path, (json.dumps(value, indent=2, sort_keys=True) + '\n').encode())

def git(*args):
    return subprocess.check_output(['git', *args], cwd=F, text=True).strip()

def main():
    assert git('rev-parse', 'HEAD^') == PARENT
    commit = git('rev-parse', 'HEAD')
    assert git('rev-parse', FROZEN) == FROZEN
    assert not git('status', '--porcelain', '--', 'chipyard').startswith('??')
    subprocess.run(['git', 'diff', '--check'], cwd=F, check=True)
    ast.parse((C/'controller.py').read_text())
    ast.parse(Path(__file__).read_text())
    for name in ['PackageAddressStats.scala', 'AddressBucketGrouped.scala']:
        path = F/REL/name
        assert path.read_bytes() == subprocess.check_output(['git', 'show', commit+':'+REL+name], cwd=F)

    spec = importlib.util.spec_from_file_location('group8_build_hw', W/'scripts/build_hw.py')
    build_hw = importlib.util.module_from_spec(spec); spec.loader.exec_module(build_hw)
    inventory = build_hw.inventory(F/'chipyard')
    source_id = hashlib.sha256(json.dumps(inventory, sort_keys=True).encode()).hexdigest()
    patch = subprocess.check_output(['git', 'show', '--format=', '--binary', commit], cwd=F)
    binding = dict(schema='ec-opt4-address-group8-binding/1', hardware_commit=commit,
        source_id=source_id, parent_commit=PARENT, frozen_commit=FROZEN,
        profile='Opt4-fit-address-group8-r1-candidate',
        candidate_change='For complete groups of eight source keys, compact equal keys with a 24-comparator bitonic network and bounded segmented sums before last-key scatter; retain group4 for other valid input counts. Architectural state, counters, event/reset/overflow/drain logic remain outside the histogram.',
        patch_sha256=hashlib.sha256(patch).hexdigest(), formal_admission=False,
        production_selected=False)
    save(F/'source-inventory.json', inventory)
    write(F/'candidate.patch', patch)
    save(F/'candidate-binding.json', binding)
    save(F/'bindings'/(commit+'.json'), binding)
    save(C/'binding.json', binding)

    cfg = json.loads((T/'config.json').read_text())
    cfg.update(binding=binding, worktree=str(F), minimum_memory_gib=48,
        minimum_disk_gib=40, max_threads=8,
        parent_local_receipt=str(D/'build-logs/Opt4-fit-address-round3-20261110/local-validation-receipt.json'))
    save(C/'config.json', cfg)
    for name in ['frozen-original.v', 'frozen-tb.v']:
        write(C/name, (T/name).read_bytes())

    parent_receipt = json.loads(Path(cfg['parent_local_receipt']).read_text())
    paths = [F/REL/name for name in ['PackageAddressStats.scala', 'AddressBucketGrouped.scala']]
    paths += [C/name for name in ['controller.py', 'prepare_group8.py', 'EmitGroup8.scala',
        'binding.json', 'config.json', 'frozen-original.v', 'frozen-tb.v']]
    paths += [F/'source-inventory.json', F/'candidate.patch', F/'candidate-binding.json',
        F/'bindings'/(commit+'.json'), F/'lineage.json', W/'scripts/build_hw.py',
        Path(cfg['parent_local_receipt']),
        Path(parent_receipt['tests']['touch_bounds']['log'])]
    paths += [Path(path) for path in cfg['classpath'] + cfg['compiler'] + [cfg['plugin']]]
    hashes = {str(path): sha(path) for path in sorted(set(paths), key=str)}
    save(C/'input-hashes.json', hashes)

    descriptor = dict(schema='ec-opt4-runtime-candidate/1', commit=commit, source_id=source_id,
        profile='Opt4-fit-C4-SVB32-group8-20261111',
        state_prefix='Opt4-fit-group8', worktree=str(F),
        cad_state=str(D/'Opt4-fit-group8-cad-state.json'),
        rtl_state=str(D/'Opt4-fit-group8-rtl-state.json'),
        board_bdf='0000:21:00.0', board_serial='21770433G02LA')
    desc = W/'runtime-candidates'/(commit[:8]+'.json')
    save(desc, descriptor)

    name = 'address-group8-r1-' + commit[:8]
    request_path = U/'requests'/(name+'.json')
    request = dict(action='cpu_job', spec=dict(name=name, kind='module', cwd=str(F),
        argv=['/usr/bin/python3', str(C/'controller.py')],
        inputs={**{p:h for p,h in hashes.items() if Path(p).resolve().is_relative_to(W)},
            str(C/'input-hashes.json'): sha(C/'input-hashes.json')},
        outputs=[str(O/'result.json'), str(O/'verified-local.json')],
        checkpoints=[str(D/'Opt4-fit-address-group8-r1-state.json'), str(O/'verified-local.json')]))
    manifest = dict(schema='ec-opt4-address-group8-preflight/1',
        status='BOUND_NO_VERIFICATION_YET', hardware_commit=commit, source_id=source_id,
        input_manifest_sha256=sha(C/'input-hashes.json'), outside_histogram_byte_equal=True,
        request=str(request_path), available_memory_gib=int(next(line.split()[1]
            for line in Path('/proc/meminfo').read_text().splitlines()
            if line.startswith('MemAvailable:')))/2**20,
        free_disk_gib=shutil.disk_usage(W).free/2**30, max_threads=8,
        minimum_memory_gib=48, minimum_disk_gib=40, fpga_access=False,
        formal_admission=False, full_dut_synthesis=False, production_selected=False,
        proof_limits=['No group8 local SAT, actual-size regression, complete-module comparison, or map result yet.',
            'The prior group4 source-count bounds apply only to the inherited input-side constraints; group8 compaction and scatter still require this candidate\'s checks.'])
    save(O/'candidate-preflight.json', manifest)

    if '--submit' in sys.argv:
        mem = int(next(line.split()[1] for line in Path('/proc/meminfo').read_text().splitlines()
                       if line.startswith('MemAvailable:')))
        assert mem >= 48*2**20 and shutil.disk_usage(W).free >= 40*2**30
        assert not request_path.exists(), 'immutable request name already exists'
        save(request_path, request)
    print(json.dumps(manifest, sort_keys=True))

if __name__ == '__main__':
    main()
