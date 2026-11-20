#!/usr/bin/python3
"""Read-only R6 shell and R3 checker adoption; no job or device control."""
import datetime as dt
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys

D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
A = Path(__file__).resolve().parent
R = D/'build-logs/Opt4-performance-only-support-r6-20261113'
K = D/'build-logs/Opt4-performance-only-checker-whole-r3-20261113'
P = D/'build-logs/Opt4-performance-only-checker-whole-r1-20261113'
Q = D/'build-logs/Opt4-performance-only-checker-whole-r2-20261113'
HW = '6fada307bb77be90b39720d3f95404fece0e431b'
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def save(p, value):
    with Path(p).open('x') as f:
        json.dump(value, f, indent=2)
        f.write('\n')


def proc(pid):
    p = Path('/proc')/str(pid)
    try:
        s = (p/'stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, state=s[0], start_ticks=s[19],
                    cpu_ticks=int(s[11])+int(s[12]), nice=int(s[16]),
                    host_boot_id=BOOT, cgroup=(p/'cgroup').read_text(),
                    cmdline=(p/'cmdline').read_text().replace('\0', ' ')[:1200],
                    children=[int(x) for x in (p/f'task/{pid}/children').read_text().split()])
    except (FileNotFoundError, ProcessLookupError):
        return dict(pid=pid, exited=True)


def tree(pid):
    result, pending = [], [pid]
    while pending:
        row = proc(pending.pop())
        result.append(row)
        pending.extend(row.get('children', []))
    return result


def log(p, size=6500):
    if not p.exists():
        return None
    s = p.stat()
    with p.open('rb') as f:
        f.seek(max(0, s.st_size-size))
        tail = f.read().decode(errors='replace').splitlines()[-18:]
    return dict(path=str(p), bytes=s.st_size, mtime_ns=s.st_mtime_ns, tail=tail)


def main():
    phase = sys.argv[1]
    assert phase in ['start', 'end']
    utc = dt.datetime.now(dt.timezone.utc).isoformat()
    owner, cad, checker = read(R/'state.json'), read(R/'cad-state.json'), read(K/'state.json')
    assert owner['hardware_commit'] == cad['hardware_commit'] == checker['hardware_commit'] == HW
    ctree = tree(owner['pid'])
    assert ctree[0]['start_ticks'] == owner['start_ticks'] and BOOT == owner['host_boot_id']
    assert 'ec-performance-only-support-r6-20261113.service' in ctree[0]['cgroup']
    ko = read(D/'performance-only-20261113/checker-whole-owner-r3.json')
    env = dict(os.environ, XDG_RUNTIME_DIR='/run/user/1008',
               DBUS_SESSION_BUS_ADDRESS='unix:path=/run/user/1008/bus')
    units = ['ec-performance-only-support-r6-20261113.service', ko['service'],
             'ec-performance-only-shell-observer-r1-20261113.service']
    services = subprocess.check_output(['systemctl', '--user', 'show', *units,
        '--property=Id,ActiveState,SubState,MainPID,ControlGroup,MemoryMax,Nice,Result'], env=env, text=True)
    kpid = int(subprocess.check_output(['systemctl', '--user', 'show', ko['service'],
        '--property=MainPID', '--value'], env=env, text=True))
    ktree = tree(kpid) if kpid else []
    prior_path = A/'owner-start.json' if phase == 'end' else A.parent/'round197/owner-end.json'
    prior = read(prior_path)
    cap = R/'capacity.complete'
    impl = R/'implementation-attempt-1.log'
    link_marker = '\nEC_FIT_LINK_ZERO_FUNCTIONAL_BLACKBOX\n' in impl.read_text()
    result = read(K/'result.json') if (K/'result.json').exists() else None
    row = dict(schema='ec-performance-only-round198-owner-observation/1', utc=utc,
        hardware_commit=HW, source_id=cad['source_id'], controller=ctree[0],
        process_tree=ctree, services=services, status=cad['status'],
        stage=cad['current_stage'], stage_wall_seconds=cad.get('stage_wall_seconds'),
        log=log(impl), executed_zero_functional_blackbox_link=link_marker,
        implementation_tcl_sha256=sha(R/'implementation-bound.tcl'),
        prior_observation=str(prior_path), prior_observation_sha256=sha(prior_path),
        observation_seconds=(dt.datetime.fromisoformat(utc)-dt.datetime.fromisoformat(prior['utc'])).total_seconds(),
        capacity_complete_exists=cap.exists(), capacity=cap.read_text().strip() if cap.exists() else None,
        postopt_utilization_exists=(R/'top-postopt-utilization.rpt').exists(),
        checker_owner=ko, checker_state=checker, checker_result=result,
        checker_process_tree=ktree, checker_log=log(K/'integrated-workload.log'),
        checker_heartbeat=log(K/'run/heartbeat.csv', 1000),
        checker_external_events=log(K/'run/external-events.jsonl', 5000),
        no_restart_or_duplicate=True, no_FPGA_IO=True)
    save(A/f'owner-{phase}.json', row)


if __name__ == '__main__':
    main()
