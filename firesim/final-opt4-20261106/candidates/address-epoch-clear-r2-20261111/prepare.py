#!/usr/bin/python3
"""Bind the epoch-clear candidate and atomically submit its isolated CPU job."""
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
C = W/'candidates/address-epoch-clear-r2-20261111'
F = W/'Opt4-fit-address-epoch-clear-r2-20261111'
BASE = W/'candidates/address-tag-read-r1-20261111'
FROZEN = '8491167d84b6d9521b151a743673c1516926a1f8'
PARENT = '8da24a269b98a0d6a8f57b030353a310812c4344'
REL = 'chipyard/generators/boom/src/main/scala/lsu/'
O = D/'build-logs/Opt4-fit-address-epoch-clear-r2-20261111'

def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda: f.read(1 << 20), b''):
            h.update(b)
    return h.hexdigest()

def write(p, data):
    p = Path(p); p.parent.mkdir(parents=True, exist_ok=True)
    if p.exists():
        assert p.read_bytes() == data, 'immutable conflict: '+str(p)
        return
    q = p.with_name(p.name+'.tmp-'+str(os.getpid()))
    with q.open('wb') as f:
        f.write(data); f.flush(); os.fsync(f.fileno())
    os.replace(q, p)

def save(p, value):
    write(p, (json.dumps(value, indent=2, sort_keys=True)+'\n').encode())

def main():
    head = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=F, text=True).strip()
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD^'], cwd=F, text=True).strip() == PARENT
    assert subprocess.check_output(['git', 'rev-parse', FROZEN], cwd=F, text=True).strip() == FROZEN
    assert subprocess.check_output(['git', 'diff', '--check'], cwd=F).strip() == b''
    src = F/REL/'PackageAddressStats.scala'
    assert src.read_bytes() == subprocess.check_output(['git', 'show', head+':'+REL+'PackageAddressStats.scala'], cwd=F)
    spec = importlib.util.spec_from_file_location('epoch_build_hw', W/'scripts/build_hw.py')
    build_hw = importlib.util.module_from_spec(spec); spec.loader.exec_module(build_hw)
    inventory = build_hw.inventory(F/'chipyard')
    source_id = hashlib.sha256(json.dumps(inventory, sort_keys=True).encode()).hexdigest()
    patch = subprocess.check_output(['git', 'show', '--format=', '--binary', head], cwd=F)
    binding = dict(schema='ec-opt4-address-epoch-clear-binding/1', hardware_commit=head,
        parent_commit=PARENT, frozen_commit=FROZEN, source_id=source_id,
        profile='Opt4-fit-C4-SVB32-address-epoch-clear-r2-20261111',
        candidate_change='Remove reset and retirement writes to 256x5x4 64-bit bucket payloads and packet tags. Validity remains resettable; every payload read/carry is masked by validity, and allocation initializes from the bounded event delta. No state width, counter, cycle, output, or checker change.',
        patch_sha256=hashlib.sha256(patch).hexdigest(), formal_admission=False, production_selected=False)
    save(F/'source-inventory.json', inventory)
    write(F/'candidate.patch', patch)
    save(F/'candidate-binding.json', binding)
    save(F/'bindings'/(head+'.json'), binding)
    tag = json.loads((BASE/'config.json').read_text())
    cfg = dict(tag)
    cfg.update(binding=binding, worktree=str(F), packet_window=256, counter_width=64,
        frozen_original=str(BASE/'frozen-original.v'), frozen_tb=str(BASE/'frozen-tb.v'),
        minimum_memory_gib=48, minimum_disk_gib=40, max_threads=8)
    save(C/'config.json', cfg)
    paths = [C/'controller.py', C/'prepare.py', C/'EmitEpoch.scala', C/'config.json',
        F/'source-inventory.json', F/'candidate.patch', F/'candidate-binding.json', F/'bindings'/(head+'.json'),
        src, Path(cfg['frozen_original']), Path(cfg['frozen_tb']), W/'scripts/build_hw.py',
        Path(cfg['java']), Path('/usr/local/bin/yosys'), Path('/usr/local/bin/verilator'),
        Path('/tools/Xilinx/Vivado/2021.1/bin/vivado')]
    paths += [Path(p) for p in cfg['classpath']+cfg['compiler']+[cfg['plugin']]]
    assert all(p.is_file() for p in paths), 'missing immutable input'
    hashes = {str(p): sha(p) for p in sorted(set(paths), key=str)}
    save(C/'input-hashes.json', hashes)
    name = 'address-epoch-clear-r2-'+head[:8]
    desc = W/'runtime-candidates'/(head[:8]+'.json')
    descriptor = dict(schema='ec-opt4-runtime-candidate/1', commit=head, source_id=source_id,
        profile=binding['profile'], state_prefix='Opt4-fit-address-epoch-clear-r2', worktree=str(F),
        cad_state=str(D/'Opt4-fit-address-epoch-clear-r2-cad-state.json'),
        rtl_state=str(D/'Opt4-fit-address-epoch-clear-r2-rtl-state.json'),
        board_bdf='0000:21:00.0', board_serial='21770433G02LA')
    save(desc, descriptor)
    all_inputs = {**hashes, str(C/'input-hashes.json'): sha(C/'input-hashes.json')}
    request = dict(action='cpu_job', spec=dict(name=name, kind='module', cwd=str(F),
        argv=['/usr/bin/python3', str(C/'controller.py')], inputs=all_inputs,
        outputs=[str(O/'result.json'), str(O/'verified-local.json')],
        checkpoints=[str(D/'Opt4-fit-address-epoch-clear-r2-state.json'), str(O/'verified-local.json')]))
    preflight = dict(schema='ec-opt4-address-epoch-clear-preflight/1', status='BOUND_NOT_VERIFIED',
        hardware_commit=head, source_id=source_id, input_count=len(all_inputs),
        input_manifest_sha256=sha(C/'input-hashes.json'), request=str(U/'requests'/(name+'.json')),
        available_memory_gib=int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines()
            if x.startswith('MemAvailable:')))/2**20, free_disk_gib=shutil.disk_usage(W).free/2**30,
        max_threads=8, minimum_memory_gib=48, minimum_disk_gib=40, fpga_access=False,
        formal_admission=False, full_dut_synthesis=False, production_selected=False,
        proof_scope='One-slot 64-bit carry/reset/retirement invariant; full 256-slot module cycle regression; OOC module map only.')
    save(O/'candidate-preflight.json', preflight)
    if '--submit' in sys.argv:
        save(U/'requests'/(name+'.json'), request)
        save(U/'requests'/(head[:8]+'-prepare-runtime.json'), dict(action='prepare_runtime', descriptor=str(desc)))
    print(json.dumps(preflight, sort_keys=True))

if __name__ == '__main__':
    main()
