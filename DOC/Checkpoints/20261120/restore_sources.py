#!/usr/bin/env python3
"""Restore one archived copied source set into an empty directory."""

import argparse
from collections import Counter
import gzip
import hashlib
import json
import os
from pathlib import Path
import subprocess


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--list', action='store_true')
    parser.add_argument('--source-prefix')
    parser.add_argument('--destination', type=Path)
    args = parser.parse_args()
    archive = Path(__file__).resolve().parent
    repository = archive.parents[2]
    with gzip.open(archive / 'copied-source-manifest.json.gz', 'rt') as handle:
        manifest = json.load(handle)
    groups = Counter()
    for entry in manifest['entries']:
        parts = Path(entry['source']).parts
        prefix = '/'.join(parts[:5] if parts[2] == 'software' else parts[:4])
        groups[prefix] += 1
    if args.list:
        for prefix, count in sorted(groups.items()):
            print(f'{prefix}: {count}')
        return
    if not args.source_prefix or args.destination is None:
        parser.error('--source-prefix and --destination are required')
    prefix = args.source_prefix.rstrip('/')
    if prefix not in groups:
        parser.error('Choose a source set printed by --list')
    destination = args.destination.resolve()
    if destination.exists() and (not destination.is_dir() or any(destination.iterdir())):
        parser.error('Destination must be empty')
    destination.mkdir(parents=True, exist_ok=True)
    process = subprocess.Popen(['git', '-C', str(repository), 'cat-file', '--batch'],
                               stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    restored = 0
    try:
        for entry in manifest['entries']:
            if not entry['source'].startswith(prefix + '/'):
                continue
            relative = Path(entry['source']).relative_to(prefix)
            target = destination / relative
            if entry['unchanged']:
                query = f"{manifest['base_commit']}:{entry['baseline']}"
                process.stdin.write((query + '\n').encode())
                process.stdin.flush()
                header = process.stdout.readline().decode().split()
                if len(header) != 3 or header[1] != 'blob':
                    raise RuntimeError(f'Missing base object: {query}')
                raw = process.stdout.read(int(header[2]))
                if process.stdout.read(1) != b'\n':
                    raise RuntimeError('Invalid Git batch response')
            else:
                source = archive / entry['overlay']
                raw = os.readlink(source).encode() if source.is_symlink() else source.read_bytes()
            if hashlib.sha256(raw).hexdigest() != entry['sha256']:
                raise RuntimeError(f"Hash mismatch: {entry['source']}")
            # Reject an archived symlink used as a later parent directory.
            if not target.parent.resolve().is_relative_to(destination):
                raise RuntimeError('Source path escapes destination')
            target.parent.mkdir(parents=True, exist_ok=True)
            if entry['mode'] == '120000':
                target.symlink_to(os.fsdecode(raw))
            else:
                target.write_bytes(raw)
                target.chmod(0o755 if entry['mode'] == '100755' else 0o644)
            restored += 1
    finally:
        process.stdin.close()
        process.wait()
    print(f'Restored and verified {restored} files in {destination}')


if __name__ == '__main__':
    main()
