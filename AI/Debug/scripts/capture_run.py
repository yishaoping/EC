#!/usr/bin/env python3
"""Preserve an EC run identity and selected artifacts in a NEW AI/TMP run directory.

Default: copy small logs, hash/record every artifact; --copy copies all explicitly
supplied artifacts. Never overwrites an existing directory and never cleans TMP.
"""
import argparse
import hashlib
import json
import shutil
import subprocess
from datetime import datetime
from pathlib import Path
from zoneinfo import ZoneInfo


def digest(path):
    h = hashlib.sha256()
    with path.open('rb') as f:
        for block in iter(lambda: f.read(4 * 1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('run_id')
    ap.add_argument('--repo', type=Path, default=Path(__file__).resolve().parents[3])
    ap.add_argument('--artifact', action='append', type=Path, default=[])
    ap.add_argument('--copy', action='store_true', help='copy all supplied artifacts, including large waveforms')
    args = ap.parse_args()
    if not args.run_id or args.run_id in ('.', '..') or any(c not in 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_' for c in args.run_id):
        ap.error('run_id must contain only letters, digits, - or _')
    repo = args.repo.resolve()
    if not (repo / 'chipyard').is_dir():
        ap.error('repo must contain chipyard/')
    artifacts = [p.resolve() for p in args.artifact]
    missing = [str(p) for p in artifacts if not p.is_file()]
    if missing:
        ap.error('missing artifact(s): ' + ', '.join(missing))
    out = repo / 'AI/TMP' / args.run_id
    out.mkdir(parents=True, exist_ok=False)
    git = lambda *a: subprocess.check_output(['git', '-C', str(repo), *a])
    diff = git('diff', '--binary', 'HEAD', '--', 'chipyard', 'Software')
    (out / 'functional_worktree.diff').write_bytes(diff)
    manifest = {'captured': datetime.now(ZoneInfo('Asia/Shanghai')).isoformat(),
                'head': git('rev-parse', 'HEAD').decode().strip(),
                'status': git('status', '--short', '--branch').decode(),
                'functional_diff_sha256': hashlib.sha256(diff).hexdigest(),
                'interpretation': 'identity only; source/RTL/run equivalence must be checked',
                'artifacts': []}
    for i, p in enumerate(artifacts):
        st = p.stat()
        entry = {'path': str(p), 'bytes': st.st_size, 'sha256': digest(p),
                 'mtime': datetime.fromtimestamp(st.st_mtime, ZoneInfo('Asia/Shanghai')).isoformat()}
        if args.copy or (p.suffix in ('.log', '.md', '.json') and st.st_size <= 1024 * 1024):
            dest = out / f'{i:03d}-{p.name}'
            shutil.copy2(p, dest)
            if digest(dest) != entry['sha256']:
                raise RuntimeError('artifact changed during copy: ' + str(p))
            entry['copy'] = dest.name
        if p.stat().st_size != st.st_size or p.stat().st_mtime_ns != st.st_mtime_ns:
            raise RuntimeError('artifact changed during capture: ' + str(p))
        manifest['artifacts'].append(entry)
    (out / 'manifest.json').write_text(json.dumps(manifest, ensure_ascii=False, indent=2) + '\n')
    print(out / 'manifest.json')


if __name__ == '__main__':
    main()
