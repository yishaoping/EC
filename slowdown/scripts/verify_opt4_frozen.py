#!/usr/bin/env python3
"""Read-only frozen Opt4 audit. Never elaborates, builds or runs hardware."""
import argparse
import hashlib
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'check'))
from recorded_paths import current_path
ARCHIVE = ROOT / 'slowdown/analysis_archive'


def read(path):
    return json.loads(Path(path).read_text())


def digest(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for data in iter(lambda: stream.read(1024 * 1024), b''):
            h.update(data)
    return h.hexdigest()


def audit():
    manifest = read(ROOT / 'slowdown/opt4/frozen_manifest.json')
    failures = []
    checked = 0

    def check(condition, label):
        nonlocal checked
        checked += 1
        if not condition:
            failures.append(label)

    check(not subprocess.check_output(['git', 'diff', manifest['opt4_source_commit'],
                                       '--name-only', '--', 'chipyard'], cwd=ROOT),
          'tracked hardware differs from frozen Opt4 commit')
    check(not subprocess.check_output(['git', 'ls-files', '--others', '--exclude-standard',
                                       '--', 'chipyard'], cwd=ROOT), 'untracked hardware source')
    check(not subprocess.check_output(['git', 'diff', manifest['opt4_source_commit'],
                                       manifest['freeze_commit'], '--name-only', '--', 'chipyard'], cwd=ROOT),
          'freeze commit changed measured hardware')
    for path, expected in manifest['frozen_source_sha256'].items():
        check((ROOT / path).is_file() and digest(ROOT / path) == expected, path)
    check(hashlib.sha256(json.dumps(manifest['frozen_source_sha256'], sort_keys=True).encode()).hexdigest()
          == manifest['source_fingerprint'], 'canonical source fingerprint')
    for key in ['elf', 'loadmem']:
        p = Path(manifest['software'][key])
        check(p.is_file() and digest(p) == manifest['software'][key + '_sha256'], 'pinned ' + key)
    for name, item in manifest['reference_files'].items():
        p = ROOT / 'slowdown/opt4/reference' / name
        check(p.is_file() and digest(p) == item['sha256'], 'versioned reference ' + name)
        original = ROOT / item['source']
        check(original.is_file() and digest(original) == item['sha256'], 'original reference ' + name)
    for path, expected in manifest['raw_evidence_sha256'].items():
        check((ROOT / path).is_file() and digest(ROOT / path) == expected, 'raw evidence ' + path)
    patch = ROOT / manifest['versioned_guard_patch']
    check(digest(patch) == manifest['measured_patch_sha256'], 'guard patch hash')
    rc = subprocess.run(['git', 'apply', '--reverse', '--check', str(patch)], cwd=ROOT,
                        capture_output=True).returncode
    check(rc == 0, 'guard patch reverse check')
    summary = read(ROOT / 'slowdown/opt4/reference/corrected_summary.json')
    check(summary['correctness']['status'] == 'PASS' and summary['performance_valid'] and
          summary['opt4_roi_cycles'] == manifest['opt4_roi_cycles'] == 1707863,
          'corrected functional/ROI record')
    check(summary['integrity']['status'] == summary['protocol']['status'] ==
          summary['data_ordering']['status'] == summary['capture_evidence']['status'] == 'PASS',
          'independent correctness gates')
    check(summary['cache_opportunity']['shadow_validation_by_level'] == {'1:0': 'PASS', '2:0': 'FAIL'},
          'failed original L2 S0 remains explicit')
    archives = read(ARCHIVE / 'archive_inventory.json')
    for item in archives['files']:
        source, dest = ROOT / item['source'], ROOT / item['archived']
        check(source.is_file() and digest(source) == item['sha256'], 'original report ' + item['source'])
        check(dest.is_file() and digest(dest) == item['archived_sha256'], 'archive ' + item['archived'])
    replay = read(ARCHIVE / 'cleanup_evidence/patch_replay_validation.json')
    check(replay['status'] == 'PASS' and replay['files_reconstructed'] == 16 and
          replay['file_modes_preserved'], 'experimental patch replay')
    for name, expected in replay['sha256'].items():
        check(digest(ARCHIVE / 'experimental_patches' / name) == expected, 'experimental patch ' + name)
    snapshot = read(ARCHIVE / 'cleanup_evidence/pre_cleanup_inventory.json')
    for path, item in snapshot['files'].items():
        if Path(path).suffix == '.pyc':
            continue  # Explicitly inventoried reproducible bytecode deletion.
        saved = ARCHIVE / 'cleanup_evidence/pre_cleanup_files' / path
        check(saved.is_file() and digest(saved) == item['sha256'], 'pre-cleanup source snapshot ' + path)
    relocations = read(ARCHIVE / 'cleanup_evidence/log_relocation.json')['moved']
    moved = {x['source']: x for x in relocations}
    for item in read(ARCHIVE / 'cleanup_evidence/dramsim_log_inventory_before.json'):
        path = current_path(ROOT / moved.get(item['path'], {}).get('destination', item['path']))
        check(path.is_file() and digest(path) == item['sha256'], 'DRAM log ' + str(path))
    check(not (ROOT / 'dramsim.log').exists(), 'root dramsim.log absent')
    check(not (ROOT / 'baseline').exists() and not (ROOT / 'baseline').is_symlink(),
          'retired directory and compatibility symlink absent')
    relocation = read(ROOT / 'slowdown/manifests/workspace_relocation_20261102.json')
    for item in relocation['numbered_dramsim_logs']:
        target = ROOT / item['destination']
        check(target.is_file() and digest(target) == item['sha256'],
              'relocated numbered DRAM log ' + item['source'])
        check(not (ROOT / item['source']).exists(), 'retired root log ' + item['source'])
    for item in read(ARCHIVE / 'cleanup_evidence/deleted_files.json')['files']:
        check(not (ROOT / item['path']).exists(), 'deleted bytecode ' + item['path'])
    return dict(status='FAIL' if failures else 'PASS', checks=checked, failures=failures,
                stable_source_commit=manifest['opt4_source_commit'],
                source_fingerprint=manifest['source_fingerprint'],
                hardware_generation='NOT_EXECUTED', verilator_build='NOT_EXECUTED',
                simulation='NOT_EXECUTED')


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.parse_args()
    result = audit()
    print(json.dumps(result, indent=2, sort_keys=True))
    return 0 if result['status'] == 'PASS' else 1


if __name__ == '__main__':
    raise SystemExit(main())
