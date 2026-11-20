#!/usr/bin/python3
"""Retry broker admission after preserving all input hashes in a W manifest."""
from pathlib import Path
import hashlib
import json
import os

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
C = W/'candidates/address-epoch-clear-r2-20261111'
F = W/'Opt4-fit-address-epoch-clear-r2-20261111'
O = D/'build-logs/Opt4-fit-address-epoch-clear-r2-20261111'
COMMIT = '64421513f29420498e128b78d82121ab11f52286'

def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda: f.read(1 << 20), b''):
            h.update(b)
    return h.hexdigest()

def save(p, value):
    p = Path(p); p.parent.mkdir(parents=True, exist_ok=True)
    data = (json.dumps(value, indent=2, sort_keys=True)+'\n').encode()
    if p.exists():
        assert p.read_bytes() == data, 'immutable request conflict: '+str(p)
        return
    q = p.with_name(p.name+'.tmp-'+str(os.getpid()))
    with q.open('wb') as f:
        f.write(data); f.flush(); os.fsync(f.fileno())
    os.replace(q, p)

def main():
    cfg = json.loads((C/'config.json').read_text())
    assert cfg['binding']['hardware_commit'] == COMMIT
    assert Path(cfg['worktree']) == F
    manifest = C/'input-hashes.json'
    full = json.loads(manifest.read_text())
    # The controller verifies every path, including external tool binaries;
    # the broker accepts only W-contained paths in its own input list.
    inputs = {p: h for p, h in full.items() if Path(p).resolve().is_relative_to(W)}
    prep = C/'prepare-r2b.py'; inputs[str(prep)] = sha(prep)
    inputs[str(manifest)] = sha(manifest)
    entry = C/'controller.py'
    assert str(entry) in inputs and str(manifest) in inputs and len(inputs) >= 100
    name = 'address-epoch-clear-r2b-'+COMMIT[:8]
    request = dict(action='cpu_job', spec=dict(name=name, kind='module', cwd=str(F),
        argv=['/usr/bin/python3', str(entry)], inputs=inputs,
        outputs=[str(O/'result.json'), str(O/'verified-local.json')],
        checkpoints=[str(D/'Opt4-fit-address-epoch-clear-r2-state.json'), str(O/'verified-local.json')]))
    save(U/'requests'/(name+'.json'), request)
    print(json.dumps(dict(request=name, broker_inputs=len(inputs), full_input_hashes=len(full),
        excluded_from_broker_paths=sorted(set(full)-set(inputs)), entry_script_hash=sha(entry),
        input_manifest_sha256=sha(manifest), status='SUBMITTED_NO_TOOL_INPUTS_DROPPED_FROM_CONTROLLER_MANIFEST'), sort_keys=True))

if __name__ == '__main__':
    main()
