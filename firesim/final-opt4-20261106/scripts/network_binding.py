"""Pin network validation to an immutable, fully verified build receipt.

Process metadata and later readelf commands are execution history, not a new
software version. All other fields must match before an old receipt is reused.
"""
import hashlib
import json
from pathlib import Path

VOLATILE = {'pid', 'start_ticks', 'host_boot_id', 'started_utc', 'updated_utc',
            'active_log', 'commands'}


def digest(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def verify_files(build):
    assert build['status'] == 'CANDIDATE_ELFS_BUILT', 'candidate build not complete'
    files = dict(build.get('reused_dependencies', {}))
    for group in build.get('checkpoints', {}).values():
        files.update(group)
    for program in build['programs'].values():
        assert program['status'] == 'ELF_COMPILED_DIAGNOSTIC_NOT_FORMAL'
        files.update({b['path']: b['sha256'] for b in program['binaries'].values()})
    if build.get('patch'):
        files[build['patch']] = build['patch_sha256']
    for path, expected in files.items():
        assert Path(path).is_file() and digest(path) == expected, 'changed candidate artifact: ' + path


def candidate(path):
    """Return receipt SHA and content, using earliest identical build snapshot.

    No existing receipt, checkpoint or result is rewritten. Real software or
    configuration changes retain a distinct identity and fail old resume gates.
    """
    path = Path(path)
    current = json.loads(path.read_text())
    verify_files(current)
    semantic = {k: v for k, v in current.items() if k not in VOLATILE}
    snapshots = sorted(Path(current['log_dir']).glob('build-result-*.json'))
    for snapshot in snapshots:
        prior = json.loads(snapshot.read_text())
        if {k: v for k, v in prior.items() if k not in VOLATILE} != semantic:
            continue
        verify_files(prior)
        # Excluded command history is allowed only as an unchanged prefix and
        # successful readelf/objdump or byte-identical diagnostic hook rebuilds.
        commands = current.get('commands', [])
        previous = prior.get('commands', [])
        assert commands[:len(previous)] == previous, 'build command history diverged'
        for command in commands[len(previous):]:
            label = command.get('label', '')
            assert command.get('returncode') == 0 and (
                label.endswith('-object-architecture') or label == 'diagnostic-hooks'
            ), 'unreviewed later build command'
        if any(c.get('label') == 'diagnostic-hooks' for c in commands[len(previous):]):
            pin_path = path.parent/'network-artifact-pin.json'
            pin = json.loads(pin_path.read_text())
            assert pin['canonical_receipt_sha256'] == digest(snapshot)
            for artifact, expected in pin['extra_artifacts'].items():
                assert digest(artifact) == expected, 'rebuilt diagnostic hooks changed'
        return digest(snapshot), prior
    return digest(path), current
