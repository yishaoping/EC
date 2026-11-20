#!/usr/bin/python3
"""Bind and atomically submit the composed area proof/typecheck job."""
from pathlib import Path
import hashlib
import json
import os
import subprocess

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
C = W/'candidates/update-share-svb-compose-r1'
F = W/'Opt4-fit-update-share-svb-r1-20261111'
O = D/'build-logs/Opt4-fit-update-share-svb-r1-20261111'
REL = 'chipyard/generators/boom/src/main/scala/lsu/'

def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()

def atomic(path, data):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists():
        assert path.read_bytes() == data, str(path)
        return
    tmp = path.with_name(path.name+'.tmp-'+str(os.getpid()))
    with tmp.open('xb') as f:
        f.write(data)
        f.flush()
        os.fsync(f.fileno())
    os.replace(tmp, path)

def main():
    policy = json.loads((U/'campaign-policy.json').read_text())
    assert policy['functional_baseline_commit'] == '8491167d84b6d9521b151a743673c1516926a1f8'
    assert policy['area_equivalence_only'] and policy['functional_extensions_allowed'] is False
    assert policy['fpga_access'] is False
    commit = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=F, text=True).strip()
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD^'], cwd=F, text=True).strip() == \
        'f2d2ca3ea0b12c918f2ccd2d1131be2709960470'
    address_binding = json.loads(
        (W/'candidates/address-update-share-r2-20261111/binding.json').read_text())
    binding = dict(
        schema='ec-opt4-composed-area-proof-binding/1', hardware_commit=commit,
        svb_commit='f2d2ca3ea0b12c918f2ccd2d1131be2709960470',
        svb_source_id='f678ac806ea4b0f801596b26ec8bf9ef914a3161b39f92564ac25452abd8eafc',
        address_commit='00847dc2b8f6be3f1e1ff0639c1104d33334ddc9',
        address_source_id=address_binding['source_id'],
        area_parent='9ae9a7fcf231a75259e23973b12a93896a443cbb',
        frozen_commit=policy['functional_baseline_commit'],
        worktree=str(F), profile='Opt4-fit-C4-SVB32-update-share-svb-compose-r1',
        fpga_access=False, full_dut_formal=False)
    atomic(C/'binding.json', (json.dumps(binding, indent=2, sort_keys=True)+'\n').encode())
    evidence = [
        C/'controller.py', C/'submit.py', C/'binding.json', W/'scripts/build_hw.py',
        W/'candidates/svb-system-r2-20261111/config.json',
        W/'candidates/svb-system-r2-20261111/binding.json',
        W/'candidates/address-update-share-r2-20261111/binding.json',
        U/'campaign-policy.json',
        F/(REL+'PackageAddressStats.scala'),
        F/(REL+'NewestSafeEntry.scala'),
        F/(REL+'speculative-version-buffer.scala'), F/'lineage.json',
        D/'Opt4-fit-address-update-share-r2-state.json',
        D/'build-logs/Opt4-fit-address-update-share-r2-20261111/verified-local.json',
        D/'build-logs/Opt4-fit-address-update-share-r2-20261111/map-full-module/utilization.rpt',
        D/'build-logs/Opt4-fit-address-update-share-r2-20261111/compare/compare-attempt-1.log',
        D/'build-logs/Opt4-fit-svb-system-r2-20261111/combined-equivalence.json',
        D/'Opt4-fit-svb-system-r2-state.json',
        W/'Opt4-fit-svb-tree-r1-20261111/builds/system-f2d2ca3e-r2/svb-comparison/comparison/result.json',
        W/'Opt4-fit-svb-tree-r1-20261111/builds/system-f2d2ca3e-r2/svb-comparison/reference/SVBModuleHarness.v',
        W/'Opt4-fit-svb-tree-r1-20261111/builds/system-f2d2ca3e-r2/svb-comparison/candidate/SVBModuleHarness.v',
    ]
    inputs = {str(p):sha(p) for p in evidence}
    name = 'opt4-compose-update-share-svb-r1-'+commit[:8]
    output = O/'composed-equivalence.json'
    state = D/'Opt4-fit-update-share-svb-r1-state.json'
    request = dict(action='cpu_job', spec=dict(
        name=name, kind='module', cwd=str(F/'chipyard'),
        argv=['/usr/bin/python3', str(C/'controller.py')], inputs=inputs,
        outputs=[str(output)], checkpoints=[str(state), str(O/'compile-composed/compile-attempt-1.log')]))
    atomic(U/'requests'/(name+'.json'), (json.dumps(request, indent=2, sort_keys=True)+'\n').encode())
    print(json.dumps(dict(name=name, hardware_commit=commit, source_id='computed-by-controller',
                          input_count=len(inputs), request=str(U/'requests'/(name+'.json')),
                          output=str(output), scope='source-bound component proof reuse plus composed Scala typecheck; no whole-DUT CAD'),
                     sort_keys=True))

if __name__ == '__main__':
    main()
