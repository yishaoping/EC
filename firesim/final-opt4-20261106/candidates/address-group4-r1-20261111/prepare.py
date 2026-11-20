#!/usr/bin/python3
"""Freeze source/configuration, then submit one sequential broker CPU job."""
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
C = W/'candidates/address-group4-r1-20261111'
F = W/'Opt4-fit-address-group4-r1-20261111'
T = W/'candidates/address-tag-read-r1-20261111'
O = D/'build-logs/Opt4-fit-address-group4-r1-20261111'
REL = 'chipyard/generators/boom/src/main/scala/lsu/'
PARENT = 'aca893e0aa3f7e23e16067ab40713afea41558e8'
FROZEN = '8491167d84b6d9521b151a743673c1516926a1f8'

def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for block in iter(lambda:f.read(2**20), b''): h.update(block)
    return h.hexdigest()

def write(p, data):
    p = Path(p); p.parent.mkdir(parents=True, exist_ok=True)
    if p.exists(): assert p.read_bytes() == data, 'immutable conflict: '+str(p); return
    q = p.with_name(p.name+'.tmp-'+str(os.getpid()))
    with q.open('wb') as f: f.write(data); f.flush(); os.fsync(f.fileno())
    os.replace(q, p)

def save(p, value): write(p, (json.dumps(value, indent=2, sort_keys=True)+'\n').encode())

def main():
    assert subprocess.check_output(['git','rev-parse','HEAD^'], cwd=F, text=True).strip() == PARENT
    commit = subprocess.check_output(['git','rev-parse','HEAD'], cwd=F, text=True).strip()
    assert subprocess.check_output(['git','rev-parse', FROZEN], cwd=F, text=True).strip() == FROZEN
    ast.parse((C/'controller.py').read_text())
    subprocess.run(['git','diff','--check'], cwd=F, check=True)
    for n in ['PackageAddressStats.scala', 'AddressBucketGrouped.scala']:
        assert (F/REL/n).read_bytes() == subprocess.check_output(['git','show',commit+':'+REL+n], cwd=F)
    sys.path.insert(0, str(W/'scripts'))
    spec = importlib.util.spec_from_file_location('group4_build_hw', W/'scripts/build_hw.py')
    mod = importlib.util.module_from_spec(spec); spec.loader.exec_module(mod)
    inventory = mod.inventory(F/'chipyard')
    source_id = hashlib.sha256(json.dumps(inventory, sort_keys=True).encode()).hexdigest()
    patch = subprocess.check_output(['git','show','--format=','--binary',commit], cwd=F)
    binding = dict(schema='ec-opt4-address-group4-binding/1', hardware_commit=commit, source_id=source_id,
        parent_commit=PARENT, frozen_commit=FROZEN, profile='Opt4-fit-address-group4-r1-candidate',
        candidate_change='Compact four source keys with a five-comparator sorting network, bounded segmented sums, and last-key scatter; sum 20 local groups per strict bucket. State, counters, event/reset/overflow/drain logic outside the histogram unchanged.',
        patch_sha256=hashlib.sha256(patch).hexdigest(), formal_admission=False, production_selected=False)
    save(F/'source-inventory.json', inventory); write(F/'candidate.patch', patch)
    save(F/'candidate-binding.json', binding); save(F/'bindings'/(commit+'.json'), binding)
    save(C/'binding.json', binding)
    cfg = json.loads((T/'config.json').read_text())
    cfg.update(binding=binding, worktree=str(F),
        parent_local_receipt=str(D/'build-logs/Opt4-fit-address-round3-20261110/local-validation-receipt.json'))
    save(C/'config.json', cfg)
    for n in ['frozen-original.v', 'frozen-tb.v']: write(C/n, (T/n).read_bytes())
    receipt = json.loads(Path(cfg['parent_local_receipt']).read_text())
    paths = [F/REL/n for n in ['PackageAddressStats.scala','AddressBucketGrouped.scala']]
    paths += [C/n for n in ['controller.py','prepare.py','EmitGroup.scala','binding.json','config.json','frozen-original.v','frozen-tb.v']]
    paths += [F/'source-inventory.json', F/'candidate.patch', F/'candidate-binding.json', F/'bindings'/(commit+'.json'),
              W/'scripts/build_hw.py', Path(cfg['parent_local_receipt']), Path(receipt['tests']['touch_bounds']['log'])]
    paths += [Path(p) for p in cfg['classpath']+cfg['compiler']+[cfg['plugin']]]
    hashes = {str(p):sha(p) for p in sorted(set(paths), key=str)}
    save(C/'input-hashes.json', hashes)
    descriptor = dict(schema='ec-opt4-runtime-candidate/1', commit=commit, source_id=source_id,
        profile='Opt4-fit-C4-SVB32-group4-20261111', state_prefix='Opt4-fit-group4', worktree=str(F),
        cad_state=str(D/'Opt4-fit-group4-cad-state.json'), rtl_state=str(D/'Opt4-fit-group4-rtl-state.json'),
        board_bdf='0000:21:00.0', board_serial='21770433G02LA')
    desc = W/'runtime-candidates'/(commit[:8]+'.json'); save(desc, descriptor)
    name = 'address-group4-r1-'+commit[:8]
    request = dict(action='cpu_job', spec=dict(name=name, kind='module', cwd=str(F),
        argv=['/usr/bin/python3',str(C/'controller.py')], inputs={**hashes,str(C/'input-hashes.json'):sha(C/'input-hashes.json')},
        outputs=[str(O/'result.json'),str(O/'verified-local.json')],
        checkpoints=[str(D/'Opt4-fit-address-group4-r1-state.json'),str(O/'verified-local.json')]))
    preflight = dict(schema='ec-opt4-address-group4-preflight/1', status='BOUND_NO_VERIFICATION_YET',
        hardware_commit=commit, source_id=source_id, input_manifest_sha256=sha(C/'input-hashes.json'),
        outside_histogram_byte_equal=True, request=str(U/'requests'/(name+'.json')),
        available_memory_gib=int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines()
            if x.startswith('MemAvailable:')))/2**20, free_disk_gib=shutil.disk_usage(W).free/2**30,
        max_threads=8, minimum_memory_gib=48, minimum_disk_gib=40, fpga_access=False,
        formal_admission=False, full_dut_synthesis=False, production_selected=False,
        proof_limits=['No group4 local proof, actual-size regression, complete-module regression, or map result yet.',
            'The inherited source-mask bounds are proved; new grouping and scatter proof remains mandatory.'])
    save(O/'candidate-preflight.json', preflight)
    if '--submit' in sys.argv:
        save(U/'requests'/(name+'.json'), request)
        save(U/'requests'/(commit[:8]+'-prepare-runtime.json'), dict(action='prepare_runtime',descriptor=str(desc)))
    print(json.dumps(preflight, sort_keys=True))

if __name__ == '__main__': main()
