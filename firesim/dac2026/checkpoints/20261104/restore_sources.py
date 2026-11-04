#!/usr/bin/env python3
"""Verify checkpoint identities or restore source inputs into a new directory."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess

HERE = Path(__file__).resolve().parent


def identity(rows):
    items = {n: {k: v[k] for k in ('mode', 'blob')} for n, v in rows.items()}
    return hashlib.sha256(json.dumps(items, sort_keys=True, separators=(',', ':')).encode()).hexdigest()


def safe_path(name):
    p = Path(name)
    if p.is_absolute() or '..' in p.parts:
        raise ValueError('Unsafe source path: ' + name)
    return p


def assemble(manifest, repo_map):
    roots = manifest['roots']
    skip = set(manifest['skip_directories'])
    suffixes = set(manifest['artifact_suffixes'])

    def selected(name):
        p = safe_path(name)
        return (any(name == r or name.startswith(r + '/') for r in roots)
                and not set(p.parts) & skip and p.suffix not in suffixes and p.name != '.git')

    rows = {}
    for spec in sorted(manifest['base_repositories'], key=lambda item: len(item['prefix'])):
        repo = repo_map.get(spec['repository'], spec['repository'])
        if spec['prefix']:
            rows = {name: item for name, item in rows.items()
                    if not name.startswith(spec['prefix'])}
        args = ['git', '-C', repo, 'ls-tree', '-r', '-z', spec['commit']]
        strip = spec.get('strip_prefix', '')
        if strip:
            args += ['--', strip]
        for entry in subprocess.check_output(args).split(b'\0'):
            if not entry:
                continue
            meta, raw = entry.split(b'\t', 1)
            mode, kind, blob = meta.decode().split()
            name = os.fsdecode(raw)
            if kind != 'blob' or not name.startswith(strip):
                continue
            name = spec['prefix'] + name[len(strip):]
            if selected(name):
                rows[name] = dict(mode=mode, blob=blob, repository=repo)
    for name in manifest['absent_from_source']:
        rows.pop(name, None)
    for item in manifest['overlay_files']:
        name = item['path']
        p = HERE / 'overlays' / manifest['label'] / safe_path(item.get('stored_path', name))
        data = p.read_bytes()
        assert hashlib.sha256(data).hexdigest() == item['sha256'], str(p)
        actual = hashlib.sha1(b'blob ' + str(len(data)).encode() + b'\0' + data).hexdigest()
        assert actual == item['blob'], str(p)
        rows[name] = {**item, 'overlay': p}
    assert len(rows) == manifest['source_files'], manifest['label']
    assert identity(rows) == manifest['source_identity'], manifest['label']
    return rows


def verify_current(manifest, rows):
    root = Path(manifest['source_root'])
    # File-set equality is checked as well as file bytes, including new inputs.
    actual = {}
    skip = set(manifest['skip_directories'])
    for sub in manifest['roots']:
        p = root / sub
        paths = []
        if p.is_symlink() or p.is_file():
            paths.append(p)
        elif p.is_dir():
            for current, dirs, files in os.walk(p):
                paths += [Path(current) / d for d in dirs if (Path(current) / d).is_symlink()]
                dirs[:] = [d for d in dirs if d not in skip and not (Path(current) / d).is_symlink()]
                paths += [Path(current) / f for f in files]
        for path in paths:
            name = str(path.relative_to(root))
            if set(Path(name).parts) & skip or path.suffix in manifest['artifact_suffixes'] or path.name == '.git':
                continue
            link = path.is_symlink()
            data = os.readlink(path).encode() if link else path.read_bytes()
            actual[name] = dict(mode='120000' if link else '100755' if path.stat().st_mode & 0o111 else '100644',
                                blob=hashlib.sha1(b'blob ' + str(len(data)).encode() + b'\0' + data).hexdigest())
    assert identity(actual) == manifest['source_identity'], 'Current source changed: ' + str(root)


def restore(rows, destination):
    destination.mkdir(parents=True, exist_ok=False)
    processes = {}
    links = []
    try:
        for name, item in sorted(rows.items()):
            path = destination / safe_path(name)
            path.parent.mkdir(parents=True, exist_ok=True)
            if 'overlay' in item:
                data = item['overlay'].read_bytes()
            else:
                repo = item['repository']
                if repo not in processes:
                    processes[repo] = subprocess.Popen(['git', '-C', repo, 'cat-file', '--batch'],
                        stdin=subprocess.PIPE, stdout=subprocess.PIPE)
                proc = processes[repo]
                proc.stdin.write((item['blob'] + '\n').encode())
                proc.stdin.flush()
                header = proc.stdout.readline().decode().split()
                assert len(header) == 3 and header[1] == 'blob', header
                data = proc.stdout.read(int(header[2]))
                assert proc.stdout.read(1) == b'\n'
            assert hashlib.sha1(b'blob ' + str(len(data)).encode() + b'\0' + data).hexdigest() == item['blob'], name
            if item['mode'] == '120000':
                links.append((path, os.fsdecode(data)))
            else:
                path.write_bytes(data)
                path.chmod(0o755 if item['mode'] == '100755' else 0o644)
        for path, target in links:
            path.symlink_to(target)
    finally:
        for proc in processes.values():
            proc.stdin.close()
            assert proc.wait() == 0


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--verify-current', action='store_true', help='also read the preserved local source trees')
    parser.add_argument('--restore', metavar='LABEL', help='restore one source tree; no build products or environment')
    parser.add_argument('--destination', type=Path, help='must be a new directory')
    parser.add_argument('--repo-map', action='append', default=[], metavar='OLD=NEW', help='relocate a Git dependency')
    args = parser.parse_args()
    repo_map = dict(entry.split('=', 1) for entry in args.repo_map)
    if bool(args.restore) != bool(args.destination):
        parser.error('--restore and --destination must be supplied together')
    count = 0
    found = False
    for path in sorted((HERE / 'manifests').glob('*.json')):
        manifest = json.loads(path.read_text())
        if args.restore and manifest['label'] != args.restore:
            continue
        found = True
        rows = assemble(manifest, repo_map)
        if args.verify_current:
            verify_current(manifest, rows)
        if args.restore:
            restore(rows, args.destination)
            verify_current({**manifest, 'source_root': str(args.destination)}, rows)
        count += len(rows)
        print(manifest['label'], 'PASS', len(rows), flush=True)
    if not found:
        parser.error('unknown source label')
    print(json.dumps(dict(status='PASS', source_inputs=count, simulations_launched=0)))


if __name__ == '__main__':
    main()
