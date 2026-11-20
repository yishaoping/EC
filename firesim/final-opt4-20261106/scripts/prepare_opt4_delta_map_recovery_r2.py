#!/usr/bin/python3
"""Prepare or submit the corrected isolated delta candidate map recovery."""
from pathlib import Path
import hashlib
import json
import os
import sys

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
C = W / 'candidates/address-delta-r3-20261111'
F = W / 'Opt4-fit-address-delta-r3-20261111/chipyard'
BASE = D / 'build-logs/Opt4-fit-address-delta-r3-56711a00-20261111'
JOB_NAME = 'address-delta-map-recovery-r2-e5f32750'
CONTROLLER = W / 'scripts/recover_opt4_delta_map_r2.py'
IMPLEMENTATION = W / 'scripts/recover_opt4_delta_map_r1.py'
PREPARED_INPUTS = BASE / 'map-recovery-r2-input-hashes.json'


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def atomic_json(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    temp = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with temp.open('w') as stream:
        json.dump(value, stream, indent=2, sort_keys=True)
        stream.write('\n')
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(temp, path)


def main():
    source_dir = F / 'chipyard/generators/boom/src/main/scala/lsu'
    prior_job = U / 'jobs/address-delta-r3-56711a00'
    failed_dir = BASE / 'map-full-module'
    paths = [
        CONTROLLER, IMPLEMENTATION,
        C / 'candidate-binding.json', C / 'candidate.patch', C / 'source-inventory.json',
        source_dir / 'PackageAddressStats.scala',
        source_dir / 'AddressBucketAccess.scala', source_dir / 'AddressBucketReduction.scala',
        BASE / 'verified-local.json', BASE / 'address/PackageAddressStats.v',
        failed_dir / 'map-full-module-result.json', failed_dir / 'map-full-module-attempt-1.log',
        prior_job / 'state.json', prior_job / 'console.log',
    ]
    for path in paths:
        assert path.is_file(), f'missing bound input: {path}'
    input_hashes = {str(path): sha(path) for path in sorted(set(paths), key=str)}
    atomic_json(PREPARED_INPUTS, input_hashes)
    if '--inputs-only' in sys.argv:
        print(json.dumps(dict(status='INPUTS_READY', count=len(input_hashes),
                              hashes=str(PREPARED_INPUTS)), sort_keys=True))
        return

    outputs = [str(BASE / 'map-recovery-r2/result.json'),
               str(BASE / 'map-recovery-r2/utilization.rpt'),
               str(BASE / 'map-recovery-r2/module.dcp')]
    checkpoints = [str(D / 'Opt4-fit-address-delta-map-recovery-r2-state.json'),
                   str(BASE / 'map-recovery-r2/result.json')]
    inputs = {**input_hashes, str(PREPARED_INPUTS): sha(PREPARED_INPUTS)}
    request = dict(action='cpu_job', spec=dict(
        name=JOB_NAME, kind='module', cwd=str(F),
        argv=['/usr/bin/python3', str(CONTROLLER)],
        inputs=inputs, outputs=outputs, checkpoints=checkpoints))
    path = U / 'requests' / (JOB_NAME + '.json')
    if path.exists():
        assert json.loads(path.read_text()) == request, 'immutable request conflict; use a new recovery version'
    else:
        atomic_json(path, request)
    print(json.dumps(dict(status='REQUEST_READY', name=JOB_NAME, request=str(path),
                          source_commit='56711a0057bb2822f5bf00754a2b3e13cde11e8f',
                          source_id='e5f327505b504fa55c75b29500a915d2f32db6e28766f9444c62e3989a384ada'),
                     sort_keys=True))


if __name__ == '__main__':
    main()
