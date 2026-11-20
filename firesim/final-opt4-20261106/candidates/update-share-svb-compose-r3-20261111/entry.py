#!/usr/bin/python3
"""Verify D-root evidence hashes, then run the immutable r1 composition checker."""
from pathlib import Path
import hashlib
import json
import runpy

C = Path('/data1/gzh/EC/firesim/final-opt4-20261106/candidates/update-share-svb-compose-r3-20261111')
MANIFEST = C/'evidence-bindings-r2.json'

def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()

manifest = json.loads(MANIFEST.read_text())
assert manifest['schema'] == 'ec-opt4-composed-area-evidence/1'
for row in manifest['external_evidence']:
    assert sha(row['path']) == row['sha256'], row['path']
runpy.run_path(str(C/'controller.py'), run_name='__main__')
