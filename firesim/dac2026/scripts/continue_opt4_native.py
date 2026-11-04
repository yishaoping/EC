#!/usr/bin/env python3
"""Continue a prepared native test only after an existing smoke commits.

Uses filesystem notifications, never process-table polling. This entry only
invokes opt4_linux_run.py: it has no FPGA or hardware-deployment path.
"""
import argparse
import ctypes
import datetime as dt
import hashlib
import json
import os
from pathlib import Path
import select
import subprocess
import sys


ROOT = Path('/data1/gzh/EC')
RESULTS = ROOT / 'Experiment/dac2026/opt4-linux-v6/linux'
RUNNER = Path(__file__).with_name('opt4_linux_run.py').resolve()


def digest(path):
    value = hashlib.sha256()
    with Path(path).open('rb') as f:
        for chunk in iter(lambda: f.read(1 << 20), b''):
            value.update(chunk)
    return value.hexdigest()


def save(path, record):
    tmp = path.with_suffix('.tmp')
    with tmp.open('x') as f:
        json.dump(record, f, indent=2)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    os.replace(tmp, path)
    fd = os.open(path.parent, os.O_RDONLY | os.O_DIRECTORY)
    try:
        os.fsync(fd)
    finally:
        os.close(fd)


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--smoke-attempt', type=Path, required=True)
    p.add_argument('--test-attempt', type=Path, required=True)
    a = p.parse_args()
    smoke, test = a.smoke_attempt.resolve(), a.test_attempt.resolve()
    if (test/'CONTINUATION_DISABLED.json').exists():
        p.error('continuation explicitly disabled; old test must never start')
    if smoke.parent != RESULTS / 'partial' or test.parent != RESULTS / 'partial':
        p.error('both attempts must be in the native partial results directory')
    bm = json.loads((smoke / 'manifest.json').read_text())
    cm = json.loads((test / 'manifest.json').read_text())
    if bm['mode'] != 'smoke' or cm['mode'] != 'test':
        p.error('requires smoke followed by Blackscholes test')
    if bm.get('console') != 'htif' or cm.get('console') != 'htif':
        p.error('requires the native HTIF console entry')
    for name in ['native', 'apps', 'rootfs']:
        if bm['receipts'][name] != cm['receipts'][name]:
            p.error('smoke/test native, apps and rootfs must match: ' + name)
    if not (smoke / 'STARTED.json').exists():
        p.error('smoke is not started; this entry cannot start a second smoke')
    if (test / 'STARTED.json').exists():
        p.error('test has already started; refusing duplicate execution')
    if digest(RUNNER) != cm['runner_sha256']:
        p.error('test runner changed; prepare a new attempt')

    record = {
        'pid': os.getpid(), 'started_at': dt.datetime.now(dt.timezone.utc).isoformat(),
        'smoke_attempt': str(smoke), 'test_attempt': str(test),
        'smoke_manifest_sha256': digest(smoke / 'manifest.json'),
        'test_manifest_sha256': digest(test / 'manifest.json'),
        'runner_sha256': digest(RUNNER), 'script_sha256': digest(__file__),
        'status': 'WAITING_FOR_REAL_SMOKE_COMPLETION',
        'no_fpga_device_access': True, 'process_table_polling': False,
    }
    # Exclusive creation prevents two continuation workers for this test.
    with (test / 'continuation-owner.json').open('x') as f:
        json.dump(record, f, indent=2)
        f.flush()
        os.fsync(f.fileno())
    save(test / 'continuation-state.json', record)
    print('Waiting for real smoke verification: ' + str(smoke), flush=True)

    libc = ctypes.CDLL(None, use_errno=True)
    libc.inotify_init1.argtypes = [ctypes.c_int]
    libc.inotify_init1.restype = ctypes.c_int
    libc.inotify_add_watch.argtypes = [ctypes.c_int, ctypes.c_char_p, ctypes.c_uint32]
    libc.inotify_add_watch.restype = ctypes.c_int
    fd = libc.inotify_init1(os.O_CLOEXEC | os.O_NONBLOCK)
    if fd < 0:
        raise OSError(ctypes.get_errno(), 'inotify_init1')
    complete = RESULTS / 'complete'
    complete.mkdir(exist_ok=True)
    try:
        for directory in [smoke, test, complete]:
            # CLOSE_WRITE, MOVED_TO, CREATE, ATTRIB (including atomic hard link).
            if libc.inotify_add_watch(fd, os.fsencode(directory), 0x8 | 0x80 | 0x100 | 0x4) < 0:
                raise OSError(ctypes.get_errno(), 'inotify_add_watch')
        while True:
            if (test/'CONTINUATION_DISABLED.json').exists():
                record.update(status='DISABLED_TEST_NOT_STARTED')
                save(test/'continuation-state.json',record)
                return 1
            verification = smoke / 'verification.json'
            committed = complete / (smoke.name + '.json')
            if verification.exists():
                try:
                    verdict = json.loads(verification.read_text())
                except json.JSONDecodeError:
                    verdict = None  # Writer has not closed the file yet.
                if verdict is not None:
                    if verdict.get('valid') is not True or verdict.get('runtime_validation') != 'PASS':
                        record.update(status='SMOKE_INVALID_TEST_NOT_STARTED', smoke_verification=verdict)
                        save(test / 'continuation-state.json', record)
                        print(json.dumps(record, indent=2), flush=True)
                        return 1
                    if committed.exists():
                        commit = json.loads(committed.read_text())
                        if commit.get('identity') != bm['identity'] or verdict.get('identity') != bm['identity']:
                            raise ValueError('smoke completion identity mismatch')
                        if any(commit.get(k) != v for k, v in verdict.items()):
                            raise ValueError('smoke commit differs from verification')
                        break
            # Timeout permits interruption, without inspecting task state.
            while True:
                ready, _, _ = select.select([fd], [], [], 60)
                if ready:
                    while True:
                        try:
                            os.read(fd, 65536)
                        except BlockingIOError:
                            break
                    break
    finally:
        os.close(fd)
    if digest(smoke / 'manifest.json') != record['smoke_manifest_sha256'] or \
            digest(test / 'manifest.json') != record['test_manifest_sha256']:
        raise ValueError('bound attempt manifest changed')
    if (test / 'STARTED.json').exists():
        raise ValueError('test already started while waiting')
    if (test/'CONTINUATION_DISABLED.json').exists():
        raise ValueError('continuation disabled before test launch')
    command = [sys.executable, str(RUNNER), 'run', '--attempt', str(test)]
    record.update(status='RUNNING_BLACKSCHOLES_TEST', smoke_completion=str(committed),
                  smoke_completion_sha256=digest(committed), command=command,
                  test_started_at=dt.datetime.now(dt.timezone.utc).isoformat())
    save(test / 'continuation-state.json', record)
    print('Smoke valid; starting real native Blackscholes: ' + str(test), flush=True)
    with (test / 'continuation-run.log').open('xb', buffering=0) as log:
        rc = subprocess.run(command, cwd=ROOT, stdout=log, stderr=subprocess.STDOUT).returncode
        os.fsync(log.fileno())
    record.update(status='TEST_RUNNER_EXITED', returncode=rc,
                  ended_at=dt.datetime.now(dt.timezone.utc).isoformat())
    if (test / 'verification.json').exists():
        record['test_verification'] = json.loads((test / 'verification.json').read_text())
    save(test / 'continuation-state.json', record)
    print(json.dumps(record, indent=2), flush=True)
    return rc


if __name__ == '__main__':
    raise SystemExit(main())
