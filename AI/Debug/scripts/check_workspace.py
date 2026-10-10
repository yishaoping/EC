#!/usr/bin/env python3
"""Check EC Debug structure, retained provenance, maintained links and AI-only paths.

This check never deletes or rewrites anything. Historical reports preserve their
original link text. Deleted raw archives are recorded in original_inventory.tsv;
only retained artifacts are expected to exist and match their recorded SHA256.
"""
import argparse
import csv
import hashlib
import re
from pathlib import Path


def sha(path):
    h = hashlib.sha256()
    with path.open('rb') as f:
        for b in iter(lambda: f.read(4 * 1024 * 1024), b''):
            h.update(b)
    return h.hexdigest()


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--repo', type=Path, default=Path(__file__).resolve().parents[3])
    ap.add_argument('--verify-retained-hashes', action='store_true')
    ap.add_argument('--verify-archive-hashes', action='store_true', help=argparse.SUPPRESS)
    args = ap.parse_args()
    repo = args.repo.resolve()
    ai = (repo / 'AI').resolve()
    debug = repo / 'AI/Debug'
    errors = []
    for required in ['README.md', 'state/current_debug_state.md', 'project', 'history', 'bugs', 'design', 'skills', 'scripts', 'prompts', 'checks', 'references']:
        if not (debug / required).exists(): errors.append('missing ' + required)
    for p in debug.rglob('*'):
        if p.is_file() and p.stat().st_size > 20 * 1024 * 1024:
            errors.append('large intermediate in long-term workspace: ' + str(p))
        if p.is_file() and (p.read_bytes()[:4] == b'\x7fELF' if p.stat().st_size < 1024 * 1024 else False):
            errors.append('ELF binary in long-term workspace: ' + str(p))
    inventory = debug / 'references/original_inventory.tsv'
    rows = list(csv.DictReader(inventory.open(), delimiter='\t'))
    for row in rows:
        dest = (repo / row['long_term_or_staging_path']).resolve()
        if not dest.is_relative_to(ai):
            errors.append('classified destination outside AI: ' + str(dest))
        if row['archive_status'] != 'deleted-by-user-request':
            errors.append('unknown archive status: ' + row['original_path'])
        if row['role'] == 'temporary-generated':
            if row['retention_status'] != 'deleted-by-user-request':
                errors.append('missing deletion status: ' + row['original_path'])
            continue
        if not dest.is_file():
            errors.append('missing long-term classified artifact: ' + str(dest))
        elif row['retention_status'] == 'retained-exact':
            if dest.stat().st_size != int(row['bytes']):
                errors.append('retained artifact size changed: ' + str(dest))
            elif (args.verify_retained_hashes or args.verify_archive_hashes) and sha(dest) != row['sha256']:
                errors.append('retained artifact hash mismatch: ' + str(dest))
        elif row['retention_status'] != 'retained-updated':
            errors.append('unknown retention status: ' + row['original_path'])
    for p in debug.rglob('*'):
        if p.is_symlink() and not p.resolve().is_relative_to(ai):
            errors.append('Debug symlink points outside AI: ' + str(p))
    for p in debug.rglob('*.md'):
        if 'history' in p.relative_to(debug).parts:
            continue
        for target in re.findall(r'\]\(([^)]+)\)', p.read_text()):
            if re.match(r'^[a-z]+://', target) or target.startswith('#'):
                continue
            target = target.split('#', 1)[0].strip('<>')
            if not target: continue
            link = (p.parent / target).resolve()
            if not link.exists(): errors.append(f'broken maintained link: {p}: {target}')
    tmp = repo / 'AI/TMP'
    tmp_count = sum(1 for _ in tmp.iterdir()) if tmp.is_dir() else 0
    print(f'Inventory: {len(rows)} original files; TMP top-level entries: {tmp_count}')
    if errors:
        print('\n'.join(errors))
        raise SystemExit(1)
    print('PASS: workspace, maintained links, retained provenance, size policy and AI-only destinations')


if __name__ == '__main__':
    main()
