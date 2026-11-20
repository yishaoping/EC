#!/usr/bin/python3
"""Atomically submit r2 with broker inputs rooted under W."""
from pathlib import Path
import hashlib
import json
import os
import subprocess

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
C = W/'candidates/update-share-svb-compose-r3-20261111'
F = W/'Opt4-fit-update-share-svb-r2-20261111'
O = D/'build-logs/Opt4-fit-update-share-svb-r2-20261111'
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
    binding = json.loads((C/'binding.json').read_text())
    commit = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=F, text=True).strip()
    assert commit == binding['hardware_commit']

    external = [
        D/'Opt4-fit-address-update-share-r2-state.json',
        D/'build-logs/Opt4-fit-address-update-share-r2-20261111/verified-local.json',
        D/'build-logs/Opt4-fit-address-update-share-r2-20261111/map-full-module/utilization.rpt',
        D/'build-logs/Opt4-fit-address-update-share-r2-20261111/compare/compare-attempt-1.log',
        D/'build-logs/Opt4-fit-svb-system-r2-20261111/combined-equivalence.json',
        D/'Opt4-fit-svb-system-r2-state.json',
    ]
    manifest = dict(schema='ec-opt4-composed-area-evidence/1', hardware_commit=commit,
                    address_commit=binding['address_commit'], svb_commit=binding['svb_commit'],
                    external_evidence=[dict(path=str(p), sha256=sha(p)) for p in external])
    manifest_path = C/'evidence-bindings-r2.json'
    atomic(manifest_path, (json.dumps(manifest, indent=2, sort_keys=True)+'\n').encode())

    inputs = [
        C/'controller.py', C/'entry.py', C/'submit.py', C/'binding.json', manifest_path,
        W/'scripts/build_hw.py', W/'candidates/address-update-share-r2-20261111/EmitUpdate.scala', W/'candidates/svb-system-r2-20261111/Emit.scala', W/'candidates/svb-system-r2-20261111/config.json',
        W/'candidates/svb-system-r2-20261111/binding.json',
        W/'candidates/address-update-share-r2-20261111/binding.json',
        F/(REL+'PackageAddressStats.scala'), F/(REL+'AddressBucketUpdate.scala'), F/(REL+'NewestSafeEntry.scala'),
        F/(REL+'speculative-version-buffer.scala'), F/'lineage.json',
        W/'Opt4-fit-svb-tree-r1-20261111/builds/system-f2d2ca3e-r2/svb-comparison/comparison/result.json',
        W/'Opt4-fit-svb-tree-r1-20261111/builds/system-f2d2ca3e-r2/svb-comparison/reference/SVBModuleHarness.v',
        W/'Opt4-fit-svb-tree-r1-20261111/builds/system-f2d2ca3e-r2/svb-comparison/candidate/SVBModuleHarness.v',
    ]
    cfg=json.loads((W/'candidates/svb-system-r2-20261111/config.json').read_text())
    inputs += [Path(p) for p in set(cfg['classpath']+cfg['compiler']+[cfg['plugin']]) if Path(p).is_file() and Path(p).is_relative_to(W)]
    input_hashes = {str(p):sha(p) for p in inputs}
    name = 'opt4-compose-update-share-svb-r3-'+commit[:8]
    request = dict(action='cpu_job', spec=dict(
        name=name, kind='module', cwd=str(F/'chipyard'),
        argv=['/usr/bin/python3', str(C/'entry.py')], inputs=input_hashes,
        outputs=[str(O/'composed-equivalence.json')],
        checkpoints=[str(D/'Opt4-fit-update-share-svb-r2-state.json'),
                     str(O/'compile-composed/compile-attempt-1.log')]))
    request_path = U/'requests'/(name+'.json')
    atomic(request_path, (json.dumps(request, indent=2, sort_keys=True)+'\n').encode())
    print(json.dumps(dict(name=name, hardware_commit=commit, input_count=len(input_hashes),
                          request=str(request_path), evidence_manifest=str(manifest_path),
                          output=str(O/'composed-equivalence.json'),
                          scope='composed module evidence and Scala typecheck; no whole-DUT CAD'),
                     sort_keys=True))

if __name__ == '__main__':
    main()
