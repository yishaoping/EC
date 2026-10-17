#!/usr/bin/env python3
"""Bind build input snapshot, generated collateral and executable; never build."""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import sys


def sha256(path):
    digest = hashlib.sha256()
    with open(path, 'rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            digest.update(block)
    return digest.hexdigest()


def source_files(root):
    paths = subprocess.check_output(['git', '-C', str(root), 'ls-files', '-co', '--exclude-standard'], text=True).splitlines()
    suffixes = {'.scala', '.sbt', '.sc', '.v', '.sv', '.vh', '.cc', '.cpp', '.c', '.h', '.mk', '.json', '.conf', '.img'}
    return sorted(set(p for p in paths if
                      (p.startswith(('generators/', 'tools/', 'project/', 'sims/')) and
                       (Path(p).suffix in suffixes or Path(p).name == 'Makefile')) or
                      p in {'build.sbt', 'common.mk', 'variables.mk', 'build.sc'}))


def source_record(root):
    return {p: sha256(root / p) for p in source_files(root) if (root / p).is_file()}


def fail(reason):
    print('PROVENANCE=FAIL\nPROVENANCE_FAIL=' + reason)
    return 1


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', required=True)
    parser.add_argument('--sim')
    parser.add_argument('--generated')
    parser.add_argument('--manifest', required=True)
    parser.add_argument('--capture-source', action='store_true')
    parser.add_argument('--source-snapshot')
    parser.add_argument('--write', action='store_true')
    args = parser.parse_args()
    root, path = Path(args.root).resolve(), Path(args.manifest).resolve()
    source_hashes = source_record(root)
    if not source_hashes:
        return fail('empty_source_inventory')
    if args.capture_source:
        path.write_text(json.dumps(source_hashes, indent=2, sort_keys=True)+'\n')
        print('PROVENANCE_SOURCE_SNAPSHOT=' + str(path))
        return 0
    if not args.sim or not args.generated:
        return fail('simulator_and_generated_required')
    sim, generated = Path(args.sim).resolve(), Path(args.generated).resolve()
    if not sim.is_file() or not generated.is_dir():
        return fail('simulator_or_generated_model_missing')
    # Every generated C++ unit and RTL file is covered, not only VTestHarness.cpp.
    extensions = {'.h', '.cpp', '.cc', '.c', '.sv', '.v', '.vh', '.mk', '.f', '.json', '.fir'}
    generated_files = {str(p.relative_to(generated.parent)): sha256(p)
                       for p in sorted(generated.parent.rglob('*'))
                       if p.is_file() and p.suffix in extensions}
    if not (generated / 'VTestHarness.h').is_file() or not generated_files:
        return fail('generated_model_files_missing')
    strings = subprocess.check_output(['strings', str(sim)], text=True, errors='replace')
    markers = ('STAGE1_TX', 'STAGE1_SIM_EXIT', 'EXIT_DRAIN', 'CLEAR_CHECK')
    for marker in markers:
        if marker not in strings:
            return fail('simulator_missing_' + marker)
    record = dict(schema=2, source_files=source_hashes, generated_files=generated_files,
                  simulator_sha256=sha256(sim), simulator=str(sim), generated=str(generated),
                  trace_markers=list(markers))
    if args.write:
        if path.exists():
            return fail('manifest_already_exists')
        if not args.source_snapshot or json.loads(Path(args.source_snapshot).read_text()) != source_hashes:
            return fail('source_changed_during_build_or_snapshot_missing')
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps(record, indent=2, sort_keys=True)+'\n')
    else:
        if not path.is_file():
            return fail('manifest_missing_build_wrapper_must_write_it')
        saved = json.loads(path.read_text())
        if saved != record:
            return fail('manifest_source_model_or_simulator_mismatch')
    print('PROVENANCE=PASS\nPROVENANCE_MANIFEST=' + str(path))
    print('PROVENANCE_SOURCE_FILES=%d' % len(source_hashes))
    print('PROVENANCE_SIM_SHA256=' + record['simulator_sha256'])
    return 0


if __name__ == '__main__':
    sys.exit(main())
