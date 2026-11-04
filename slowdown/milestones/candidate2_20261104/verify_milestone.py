#!/usr/bin/env python3
"""Verify exact Candidate 2 bytes and saved evidence without building or running."""
import hashlib
import json
from pathlib import Path
import subprocess

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]


def digest(path):
    h = hashlib.sha256()
    with path.open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def verify():
    identity = json.loads((HERE / 'SOURCE_IDENTITY.json').read_text())
    source = identity['source']
    files = {**source['hardware_sha256'], **source['restored_resource_sha256']}
    for rel, expected in files.items():
        assert digest(ROOT / rel) == expected, rel
        blob = subprocess.check_output(['git', 'show', 'HEAD:' + rel], cwd=ROOT)
        assert hashlib.sha256(blob).hexdigest() == expected, 'commit: ' + rel
    canonical = identity['canonical_evaluated_hardware_commit']
    changed = subprocess.check_output(
        ['git', 'diff', '--name-only', canonical, 'HEAD', '--', 'chipyard'],
        cwd=ROOT, text=True).splitlines()
    assert set(changed) == set(source['restored_resource_sha256']), changed
    evidence = json.loads((HERE / 'EVIDENCE_INDEX.json').read_text())
    for item in evidence['archived_metadata']:
        assert digest(HERE / item['path']) == item['sha256'], item['path']
    local_present = 0
    for run in evidence['runs'].values():
        for item in run['original_artifacts']:
            original = Path(item['path'])
            if original.exists():
                assert digest(original) == item['sha256'], str(original)
                local_present += 1
    print(json.dumps({'status': 'PASS', 'hardware_and_resource_files': len(files),
        'only_chipyard_delta_from_evaluated_commit': 'six restored exact source resources',
        'archived_metadata_verified': len(evidence['archived_metadata']),
        'original_artifacts_verified_if_present': local_present,
        'recovery_restoration': 'UNPROVEN', 'simulations_launched': 0}, indent=2))


if __name__ == '__main__':
    verify()
