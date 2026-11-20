#!/usr/bin/env python3
"""Observe the existing owner and recover only a proven clock-probe wait race.

Never signals an existing process, starts a second physical implementation,
invokes a model, or accesses a device. Other failures retain their evidence.
"""
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import subprocess
import time

C = Path(__file__).resolve().parent
O = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/performance-only-cdc-lowfreq-r1-20261114')
OWNER = 'ec-performance-only-cdc-lowfreq-r1-20261114.service'
PROBES = ['ec-performance-only-lowfreq-clock-probe-r1-20261114.service',
          'ec-performance-only-lowfreq-clock-probe-r2-20261114.service']


def read(p):
    return json.loads(Path(p).read_text()) if Path(p).exists() else {}


def active(unit):
    return subprocess.check_output(['systemctl', '--user', 'show', unit,
        '-p', 'ActiveState', '--value'], text=True).strip() in ['active', 'activating']


def save(status, **kw):
    row = dict(status=status, utc=dt.datetime.now(dt.timezone.utc).isoformat(),
               model_requests=False, fpga_access=False, **kw)
    p = O/'followthrough-state.json';tmp = p.with_suffix('.tmp')
    tmp.write_text(json.dumps(row, indent=2)+'\n');os.replace(tmp, p)


def main():
    with (O/'followthrough.lock').open('a') as lock:
        fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
        while active(OWNER):
            state = read(O/'state.json')
            save('OBSERVING_EXISTING_OWNER_NO_RESTART', owner_status=state.get('status'),
                 physical_state=read(O/'physical/state.json'))
            time.sleep(30)
        result = read(O/'result.json')
        if result:
            save('OWNER_COMPLETED_EVIDENCE_RETAINED', result=result)
            return
        state = read(O/'state.json')
        # This exact failure happens only before any new physical candidate.
        # The corrected probe uses a different service name than the original
        # in-memory owner knew. Recover its waiting stage, never a running CAD.
        if ('Clock/scope probe must pass before implementation' in state.get('error', '')
                and not (O/'physical').exists()):
            while any(active(u) for u in PROBES):
                save('WAITING_CORRECTED_CLOCK_PROBE_NO_CAD_RESTART')
                time.sleep(30)
            assert (O/'clock-probe/complete').read_text().strip() == 'PASS_FULL_SHELL_CLOCK_AND_SCOPE_REPLAY'
            p = O/'clock-wait-race-original-state.json'
            assert not p.exists(), 'one recovery only; do not repeat an unchanged failure'
            p.write_text(json.dumps(state, indent=2)+'\n')
            save('RECOVERING_COMPLETED_CLOCK_WAIT_STAGE_ONLY')
            with (O/'clock-wait-recovery.log').open('xb') as log:
                completed = subprocess.run(['/usr/bin/python3', str(C/'controller.py')],
                    cwd=O, stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT)
            save('CLOCK_WAIT_RECOVERY_RETURNED', returncode=completed.returncode,
                 owner_status=read(O/'state.json').get('status'), result=read(O/'result.json'))
            return
        save('OWNER_FAILURE_EVIDENCE_REQUIRES_DIAGNOSED_RECOVERY', owner_state=state)


if __name__ == '__main__':
    main()
