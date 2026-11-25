#!/usr/bin/env python3
"""P5-12: read-only source manifest, including new untracked hardware files."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys

REPO = Path(__file__).resolve().parents[4]


def capture():
    paths = subprocess.check_output([
        'git', 'ls-files', '-z', '--cached', '--others', '--exclude-standard',
        '--', 'chipyard', 'AI/Debug/scripts/rollback', 'AI/Debug/scripts/stage2',
        'AI/Debug/scripts/stage3', 'AI/Debug/scripts/baseline_publication',
        'AI/Debug/scripts/finite_identity', 'AI/Debug/scripts/sv39',
        'AI/Debug/scripts/synthesis', 'AI/Debug/scripts/csr_shadow',
        'AI/Debug/scripts/fullcore_concurrency',
        'Software/EC-Test', 'Software/GAPBS', 'Software/Test',
    ], cwd=REPO).split(b'\0')
    suffixes = {'.scala', '.sbt', '.v', '.sv', '.h', '.c', '.cpp', '.cc', '.sh', '.py', '.mk', '.xdc', '.tcl'}
    sources = {}
    for raw in sorted(set(paths)):
        if not raw:
            continue
        rel = raw.decode()
        path = REPO / rel
        if path.is_file() and (path.suffix in suffixes or path.name in {'Makefile', 'build.properties'}):
            sources[rel] = hashlib.sha256(path.read_bytes()).hexdigest()
    return {
        'head': subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=REPO, text=True).strip(),
        'sources': sources,
    }


if __name__ == '__main__':
    if len(sys.argv) != 2:
        raise SystemExit('Usage: source_manifest.py NEW_OUTPUT.json')
    with Path(sys.argv[1]).open('x') as stream:
        json.dump(capture(), stream, indent=2, sort_keys=True)
        stream.write('\n')
