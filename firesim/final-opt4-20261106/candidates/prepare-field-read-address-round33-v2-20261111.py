#!/usr/bin/python3
"""Recover a rejected precheck using broker-local immutable evidence copies."""
from pathlib import Path
import ast
import datetime
import hashlib
import json
import os
import shutil
import sys

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
OLD = W / 'candidates/field-read-address-compose-round33-v1-20261111'
NEW = W / 'candidates/field-read-address-compose-round33-v2-20261111'
NAME = 'field-read-address-precheck-r33-v2-da8b51a6'


def read(path):
    return json.loads(Path(path).read_text())


def sha(path):
    digest = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(2**20), b''):
            digest.update(block)
    return digest.hexdigest()


def write(path, value):
    with Path(path).open('x') as stream:
        json.dump(value, stream, indent=2, sort_keys=True)
        stream.write('\n')
        stream.flush()
        os.fsync(stream.fileno())


def main():
    policy = read(U / 'campaign-policy.json')
    assert policy['area_equivalence_only'] and not policy['functional_extensions_allowed']
    assert not policy['fpga_access'] and policy['native_paused']
    assert policy['functional_baseline_commit'] == '8491167d84b6d9521b151a743673c1516926a1f8'
    rejection_path = U / 'request-results/field-read-address-precheck-r33-v1-da8b51a6.json'
    rejection = read(rejection_path)
    assert rejection['status'] == 'REJECTED_WITH_EVIDENCE'
    assert 'input root/file' in rejection['error']
    assert not (U / 'jobs/field-read-address-precheck-r33-v1-da8b51a6/state.json').exists()
    assert not (D / 'Opt4-fit-field-read-address-compose-round33-v1-state.json').exists()
    assert not NEW.exists()
    shutil.copytree(OLD, NEW)
    # All edits below apply exclusively to the new, never submitted version.
    for name in ['request.json', 'input-hashes.json', 'scope-guard-preflight.json']:
        (NEW / name).unlink()
    text = (NEW / 'controller.py').read_text().replace('round33-v1', 'round33-v2')
    needle = "        assert sha(provenance[key]['path']) == provenance[key]['sha256']"
    assert text.count(needle) == 1
    text = text.replace(needle, needle + "\n        assert sha(provenance[key]['copy']) == provenance[key]['sha256']")
    ast.parse(text)
    (NEW / 'controller.py').write_text(text)
    provenance = read(OLD / 'cycle-assertion-provenance.json')
    raw_inputs = set()
    for role in ['command', 'emitted_procedural_fatal']:
        row = provenance[role]
        original = Path(row['path'])
        assert sha(original) == row['sha256']
        local = NEW / 'evidence' / original.name
        shutil.copyfile(original, local)
        assert sha(local) == row['sha256']
        row['copy'] = str(local)
        raw_inputs.add(str(original))
    (NEW / 'cycle-assertion-provenance.json').write_text(json.dumps(provenance, indent=2, sort_keys=True) + '\n')
    evidence = read(OLD / 'evidence-bindings.json')
    for row in evidence.values():
        row['copy'] = row['copy'].replace(str(OLD), str(NEW))
    (NEW / 'evidence-bindings.json').write_text(json.dumps(evidence, indent=2, sort_keys=True) + '\n')
    shutil.copyfile(rejection_path, NEW / 'evidence/round33-v1-broker-rejection.json')
    shutil.copyfile(OLD / 'recovery.json', NEW / 'evidence/round33-v1-recovery.json')
    recovery = read(OLD / 'recovery.json')
    recovery.update(
        previous_request=str(U / 'requests/field-read-address-precheck-r33-v1-da8b51a6.json'),
        previous_error=rejection['error'], previous_status=rejection['status'],
        previous_job_started=False,
        reason='Broker executable/source inputs must be under W. Bind byte-identical local evidence copies and authenticate both copies and original D artifacts at runtime. No RTL, checks, resource guards or admission gates changed.',
        created_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
    (NEW / 'recovery.json').write_text(json.dumps(recovery, indent=2, sort_keys=True) + '\n')
    inputs = {}
    for path in read(OLD / 'input-hashes.json'):
        if path not in raw_inputs:
            local = Path(path.replace(str(OLD), str(NEW)))
            assert local.is_relative_to(W) and local.is_file()
            inputs[str(local)] = sha(local)
    for role in ['command', 'emitted_procedural_fatal']:
        local = provenance[role]['copy']
        inputs[local] = sha(local)
    for name in ['evidence/round33-v1-broker-rejection.json', 'evidence/round33-v1-recovery.json']:
        inputs[str(NEW / name)] = sha(NEW / name)
    inputs[str(Path(__file__).resolve())] = sha(Path(__file__))
    write(NEW / 'input-hashes.json', inputs)
    spec = read(OLD / 'request.json')['spec']
    spec.update(name=NAME, cwd=str(NEW), argv=['/usr/bin/python3', str(NEW / 'controller.py')],
                inputs={**inputs, str(NEW / 'input-hashes.json'): sha(NEW / 'input-hashes.json')},
                outputs=[str(D / 'build-logs/Opt4-fit-field-read-address-compose-round33-v2-20261111/result.json')],
                checkpoints=[str(D / 'Opt4-fit-field-read-address-compose-round33-v2-state.json')])
    sys.path.insert(0, str(W / 'scripts'))
    from opt4_unattended_common import bound_inputs
    from opt4_frozen_scope import enforce
    bound_inputs(spec)
    write(NEW / 'scope-guard-preflight.json', enforce(spec))
    write(NEW / 'request.json', dict(action='cpu_job', spec=spec))
    # Re-read the policy immediately before the sole broker mutation.
    policy = read(U / 'campaign-policy.json')
    assert policy['area_equivalence_only'] and not policy['fpga_access']
    final = U / 'requests' / (NAME + '.json')
    assert not final.exists() and not (U / 'request-results' / final.name).exists()
    temporary = final.with_name('.' + final.name + '.tmp-' + str(os.getpid()))
    shutil.copyfile(NEW / 'request.json', temporary)
    with temporary.open('rb') as stream:
        os.fsync(stream.fileno())
    os.replace(temporary, final)
    directory_fd = os.open(final.parent, os.O_RDONLY | os.O_DIRECTORY)
    os.fsync(directory_fd)
    os.close(directory_fd)
    print(json.dumps(dict(request=str(final), name=NAME, kind=spec['kind'],
                          input_count=len(spec['inputs']), submitted_not_started=True)))


if __name__ == '__main__':
    main()
