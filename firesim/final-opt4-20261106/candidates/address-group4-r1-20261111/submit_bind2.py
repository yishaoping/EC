#!/usr/bin/python3
"""Recover rejected spec without changing controller, RTL, manifest or broker.

Direct broker inputs must be under W. Two D evidence files remain transitively
bound by the W manifest and are rehashed by the controller before any stage.
"""
from pathlib import Path
import hashlib
import json
import os

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
C = W/'candidates/address-group4-r1-20261111'

def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p, value):
    data = (json.dumps(value, indent=2, sort_keys=True)+'\n').encode()
    if p.exists(): assert p.read_bytes() == data; return
    q = p.with_name(p.name+'.tmp-'+str(os.getpid()))
    with q.open('wb') as f: f.write(data); f.flush(); os.fsync(f.fileno())
    os.replace(q, p)

def main():
    old = U/'requests/address-group4-r1-981b890d.json'
    receipt = U/'request-results'/old.name
    assert json.loads(receipt.read_text())['status'] == 'REJECTED_WITH_EVIDENCE'
    req = json.loads(old.read_text()); original = req['spec']['inputs']
    assert all(sha(p) == h for p, h in original.items())
    direct = {p:h for p,h in original.items() if Path(p).resolve().is_relative_to(W)}
    inherited = {p:h for p,h in original.items() if p not in direct}
    assert set(inherited) == {
        str(D/'build-logs/Opt4-fit-address-round3-20261110/local-validation-receipt.json'),
        str(D/'build-logs/Opt4-fit-address-round3-20261110/proofs/hit-bounds-attempt-1.log')}
    manifest = json.loads((C/'input-hashes.json').read_text())
    assert all(manifest[p] == h for p,h in inherited.items())
    assert direct[str(C/'input-hashes.json')] == sha(C/'input-hashes.json')
    assert 'assert all(sha(p) == h for p, h in inputs.items())' in (C/'controller.py').read_text()
    req['spec']['name'] = 'address-group4-r1-bind2-981b890d'
    req['spec']['inputs'] = {**direct, str(Path(__file__).resolve()):sha(__file__)}
    save(U/'requests/address-group4-r1-bind2-981b890d.json', req)
    result = dict(schema='ec-opt4-broker-spec-recovery/1', original_request=str(old),
        original_request_sha256=sha(old), original_receipt=str(receipt),
        reason='Broker requires all direct input paths under W; two inherited proof evidence paths were under D.',
        new_request=str(U/'requests/address-group4-r1-bind2-981b890d.json'),
        inherited_evidence_hashes=inherited,
        immutable_manifest=str(C/'input-hashes.json'), immutable_manifest_sha256=sha(C/'input-hashes.json'),
        validation='Controller verifies every original manifest input, including both D files, before any stage. No design/config/controller/evidence hashes changed.',
        controller_changed=False, broker_changed=False, fpga_access=False)
    save(D/'unattended-opt4/rounds/round-00007/broker-binding-recovery.json', result)
    print(json.dumps(result, indent=2))

if __name__ == '__main__': main()
