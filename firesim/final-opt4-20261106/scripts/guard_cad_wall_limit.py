#!/usr/bin/env python3
"""Keep the existing CAD child alive past the legacy wrapper's wall limit.

Only the Python bookkeeping wrapper is suspended near its obsolete 24h limit.
Vivado and its process group receive no signal. On CAD exit, the same wrapper
resumes to validate inputs, persist the bitstream and complete certification.
The resource guards remain enforced; no FPGA or project input is accessed.
"""
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import select
import shutil
import signal
import time

from board_batch import D, save

STATE = D / 'cad-wall-limit-guard-state.json'
CAD = D / 'C4-runtime-cad-state.json'


def now():
    return dt.datetime.now(dt.timezone.utc).isoformat()


def proc(pid):
    try:
        p = Path('/proc') / str(pid)
        fields = (p / 'stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, state=fields[0], ppid=int(fields[1]),
                    start_ticks=fields[19],
                    cmdline=(p / 'cmdline').read_bytes().replace(b'\0', b' ').decode())
    except (FileNotFoundError, ProcessLookupError):
        return None


def main():
    assert os.geteuid() == 0
    lock = (D / 'locks/cad-wall-limit-guard.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    boot = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
    cad = json.loads(CAD.read_text())
    assert cad['host_boot_id'] == boot and cad['status'] == 'RUNNING'
    assert cad['hardware_commit'] == '8491167d84b6d9521b151a743673c1516926a1f8'
    wrapper, child = proc(cad['pid']), proc(cad['child_pid'])
    assert wrapper and child
    assert wrapper['start_ticks'] == str(cad['start_ticks'])
    assert child['start_ticks'] == str(cad['child_start_ticks'])
    assert child['ppid'] == wrapper['pid']
    assert '/scripts/resume_bitstream.py' in wrapper['cmdline']
    assert '/Vivado/2021.1/bin/vivado' in child['cmdline']
    assert cad['output_dir'] in child['cmdline']
    # pidfds bind all signals and exit monitoring to these exact processes.
    wrapper_fd, child_fd = os.pidfd_open(wrapper['pid']), os.pidfd_open(child['pid'])
    prior = json.loads(STATE.read_text()) if STATE.exists() else {}
    same = (prior.get('host_boot_id') == boot and
            prior.get('wrapper', {}).get('start_ticks') == wrapper['start_ticks'])
    paused = bool(same and prior.get('wrapper_paused'))
    # Refuse to take ownership of a stop for which this guard has no receipt.
    assert wrapper['state'] != 'T' or paused
    state = dict(schema='ec-cad-wall-limit-guard/1', pid=os.getpid(),
                 start_ticks=proc(os.getpid())['start_ticks'], host_boot_id=boot,
                 started_utc=now(), wrapper=wrapper, cad_child=child,
                 wrapper_paused=paused, status='MONITORING_LEGACY_WRAPPER_LIMIT',
                 reason='24h total wall limit would kill active CAD after completed 22h synthesis; preserve the exact CAD process and final certification',
                 pause_at_resume_elapsed_seconds=23 * 3600,
                 no_vivado_signals=True, no_project_input_changes=True,
                 fpga_access=False, events=prior.get('events', []) if same else [])
    baseline_elapsed = cad['resume_elapsed_seconds']
    started = time.monotonic()
    save(STATE, state)
    while True:
        if select.select([child_fd], [], [], 0)[0]:
            if paused:
                signal.pidfd_send_signal(wrapper_fd, signal.SIGCONT)
                state['events'].append(dict(utc=now(), action='RESUME_SAME_WRAPPER_AFTER_CAD_EXIT'))
            state.update(status='CAD_EXITED_WRAPPER_FINALIZING', wrapper_paused=False,
                         ended_utc=now())
            save(STATE, state)
            print(json.dumps(state), flush=True)
            return
        elapsed = baseline_elapsed + time.monotonic() - started
        free = shutil.disk_usage(cad['output_dir']).free / 2 ** 30
        budget = cad['disk_budget']
        resource_limit = (free < budget['stop_free_below_gib'] or
                          budget['initial_free_gib'] - free > budget['max_growth_gib'])
        if resource_limit:
            if paused:
                signal.pidfd_send_signal(wrapper_fd, signal.SIGCONT)
            state.update(status='RESOURCE_GUARD_RETURNED_TO_ORIGINAL_WRAPPER',
                         wrapper_paused=False, disk_free_gib=free, ended_utc=now())
            save(STATE, state)
            raise RuntimeError('disk resource limit; original wrapper resumes its existing termination policy')
        if not paused and elapsed >= state['pause_at_resume_elapsed_seconds']:
            # Never signal the PGID, the service cgroup, or a Vivado process.
            signal.pidfd_send_signal(wrapper_fd, signal.SIGSTOP)
            paused = True
            state['events'].append(dict(utc=now(), action='PAUSE_ONLY_PYTHON_WRAPPER',
                                        pid=wrapper['pid'], resume_elapsed_seconds=elapsed))
            print(json.dumps(state['events'][-1]), flush=True)
        state.update(status='VIVADO_CONTINUES_WRAPPER_LIMIT_SUSPENDED' if paused else
                     'MONITORING_LEGACY_WRAPPER_LIMIT', wrapper_paused=paused,
                     updated_utc=now(), resume_elapsed_seconds=elapsed, disk_free_gib=free)
        save(STATE, state)
        # A durable service watches the existing child; SSH/VS Code are irrelevant.
        select.select([child_fd], [], [], 300)


if __name__ == '__main__':
    main()
