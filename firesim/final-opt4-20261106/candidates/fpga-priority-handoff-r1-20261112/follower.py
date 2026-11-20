#!/usr/bin/python3
"""Versioned root handoff, never a substitute for physical certification."""
import fcntl
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
R = W / 'runtime/Opt4-fit-mcrams-owner-r1'
ORIGINAL = W / 'candidates/mcrams-full-host-continuation-r2-20261112'
OUT = D / 'fpga-priority-handoff-r1-20261112'
sys.path.insert(0, str(W / 'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha

ST = {}
READY = 'PHYSICAL_BITSTREAM_TIMING_DRC_PASSED_REQUIRES_COMPOSITE_HOST_RUNTIME_CERTIFICATION'


def update(status, **values):
    ST.update(status=status, updated_utc=now(), **values)
    save(OUT / 'state.json', ST)


def verify():
    pins = read(C / 'inputs.json')
    for path, digest in pins['files'].items():
        assert sha(path) == digest, ('changed pinned handoff input', path)
    p = read(D / 'FPGA_SESSION_POLICY.json')
    assert p['functional_baseline_commit'] == pins['functional_baseline_commit']
    assert p['board_allowlist'] == ['0000:21:00.0']
    assert p['priority_programs'] == pins['priority_programs']
    spec = importlib.util.spec_from_file_location('ec_original_mcrams_installer', ORIGINAL / 'install_runtime.py')
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    m.verify()
    return pins


def service(unit):
    fields = ['MainPID', 'ActiveState', 'ControlGroup', 'TasksCurrent']
    command = ['systemctl', 'show', unit]
    for name in fields:
        command += ['-p', name]
    props = dict(line.split('=', 1) for line in
        subprocess.check_output(command, text=True).splitlines() if '=' in line)
    path = Path('/sys/fs/cgroup/systemd/system.slice') / unit
    if not path.exists():
        assert (props['MainPID'] == '0' and props['ActiveState'] in ['inactive', 'failed']
            and props['ControlGroup'] == ''), 'unknown cgroup is not idle'
        return props, []
    assert (path / 'cgroup.procs').is_file(), 'unreadable cgroup is not idle'
    assert props['ControlGroup'] == '/system.slice/' + unit
    rows = []
    for pid in sorted({int(pid) for f in path.rglob('cgroup.procs') for pid in f.read_text().split()}):
        row = identity(pid)
        assert row and row['process_state'] not in ['Z', 'X']
        row['argv'] = [v.decode() for v in (Path('/proc') / str(pid) / 'cmdline').read_bytes().split(b'\0') if v]
        rows.append(row)
    return props, rows


def idle_runtime_rows(rows, old):
    if len(rows) != 2 or not live(old) or old.get('child_pid') or old.get('commands'):
        return False
    expected = [
        ['/usr/bin/python3', str(W / 'scripts/job_service.py'), 'run', 'opt4-fit-runtime'],
        ['python3', str(W / 'scripts/continue_opt4_fit.py')],
    ]
    return (old.get('status') == 'WAITING_FOR_DERIVED_BITSTREAM'
        and old.get('hardware_commit') == '8da24a269b98a0d6a8f57b030353a310812c4344'
        and sorted(r['argv'] for r in rows) == sorted(expected)
        and any(r['pid'] == old['pid'] and r['start_ticks'] == old['start_ticks'] for r in rows))


def stop_verified_idle(unit, expected_rows, reason):
    props, rows = service(unit)
    assert [(r['pid'], r['start_ticks'], r['argv']) for r in rows] == [
        (r['pid'], r['start_ticks'], r['argv']) for r in expected_rows], 'service changed during handoff'
    save(OUT / (unit + '-before.json'), dict(utc=now(), properties=props,
        rows=rows, reason=reason, fpga_io=False, cad_signalled=False))
    subprocess.run(['systemctl', '--no-ask-password', 'stop', unit], check=True)
    props, rows = service(unit)
    assert props['MainPID'] == '0' and not rows
    save(OUT / (unit + '-stopped.json'), dict(utc=now(), reason=reason,
        fpga_io=False, cad_signalled=False))


def adopt_original_waiter():
    unit = 'ec-opt4-mcrams-owner-runtime-follow-r1.service'
    props, rows = service(unit)
    if props['MainPID'] == '0' and not rows:
        return True
    expected = ['/usr/bin/python3', str(ORIGINAL / 'install_runtime.py'), '--follow']
    # The original follower has no sample/CAD children. Once it execs a real
    # runtime its argv changes and this handoff refuses to stop it.
    if len(rows) != 1 or rows[0]['argv'] != expected:
        return False
    from coverage_first import sample_busy
    if sample_busy() or live(read(D / 'Opt4-mcrams-owner-runtime-state.json')):
        return False
    stop_verified_idle(unit, rows, 'Replace exact single Python certification waiter with versioned priority follower')
    return True


def release_obsolete_runtime():
    unit = 'ec-parsec-opt4-fit-runtime.service'
    props, rows = service(unit)
    if props['MainPID'] == '0' and not rows:
        return True
    old = read(D / 'Opt4-fit-runtime-state.json')
    if read(D / 'Opt4-fit-cad-state.json').get('status') != 'NOT_FIT_POSTOPT':
        return False
    if not idle_runtime_rows(rows, old):
        return False
    from coverage_first import sample_busy
    if sample_busy():
        return False
    assert old.get('certified_bitstream') is False
    stop_verified_idle(unit, rows, 'Real certified composite candidate replaces exact obsolete NOT FIT idle runtime waiter')
    return True


def main():
    verify()
    assert os.geteuid() == 0, 'root service is required for exact system-unit handoff'
    OUT.mkdir(exist_ok=True)
    lock = (OUT / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    ST.update(schema='ec-fpga-priority-handoff/1', **identity(), started_utc=now(),
        board_bdf='0000:21:00.0', fpga_io=False, no_cad_launch=True)
    while not adopt_original_waiter():
        update('WAITING_EXACT_IDLE_ORIGINAL_FOLLOWER_NO_PREEMPTION')
        time.sleep(60)
    update('ADOPTED_ORIGINAL_IDLE_FOLLOWER_WAITING_REAL_PHYSICAL_CERTIFICATION')
    while True:
        verify()
        physical = read(D / 'Opt4-mcrams-shell-physical-r2-state.json')
        if physical.get('status') == READY:
            spec = importlib.util.spec_from_file_location('ec_original_composite_certifier', ORIGINAL / 'runtime_certify.py')
            certifier = importlib.util.module_from_spec(spec)
            spec.loader.exec_module(certifier)
            result = certifier.certify()
            assert result['certified_bitstream'] and result['status'] == 'CERTIFIED_DERIVED_ARTIFACT_NOT_RUNTIME_VALIDATED'
            if release_obsolete_runtime():
                update('CERTIFIED_ORIGINAL_ARTIFACT_ENTERING_PRIORITY_RUNTIME',
                    certificate_sha256=sha(R / 'certified-build.json'))
                os.execv('/usr/bin/python3', ['/usr/bin/python3', str(C / 'controller.py')])
            update('WAITING_EXACT_OBSOLETE_IDLE_RUNTIME_NO_PREEMPTION')
        else:
            update('WAITING_REAL_FULL_PHYSICAL_CERTIFICATION', physical_status=physical.get('status'))
        time.sleep(300)


if __name__ == '__main__':
    main()
