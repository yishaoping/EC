#!/usr/bin/env python3
"""Advance the receipt-linked C4 build, persisting child identity and stage exits.

No FPGA access or deployment. Each stage is a separate process group, and only
the process group created by this supervisor can be stopped on timeout/signal.
"""
import argparse
import datetime as dt
import fcntl
import hashlib
import json
import os
from pathlib import Path
import signal
import subprocess
import sys
import time

WORK = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
DATA = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
PHASES = ['compile', 'parameters', 'elaborate', 'goldengate', 'driver']


def atomic(path, d):
    tmp = path.with_suffix('.tmp')
    with tmp.open('w') as f:
        json.dump(d, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    tmp.replace(path)


def main():
    p = argparse.ArgumentParser()
    p.add_argument('--from-phase', choices=PHASES, default='parameters')
    p.add_argument('--through', choices=PHASES, default='driver')
    a = p.parse_args()
    lock = (DATA/'.c4-build-supervisor.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    state_path = DATA/'C4-build-state.json'
    state = dict(schema='ec-firesim-build-state/1', pid=os.getpid(),
                 start_ticks=Path('/proc/self/stat').read_text().split()[21],
                 run_id=DATA.name, status='RUNNING', phases=[], no_fpga_access=True,
                 script_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest())
    child = None
    interrupted = False

    def stop(sig, frame):
        nonlocal interrupted
        interrupted = True
        if child is not None and child.poll() is None:
            os.killpg(child.pid, signal.SIGTERM)

    signal.signal(signal.SIGTERM, stop)
    signal.signal(signal.SIGINT, stop)
    for phase in PHASES[PHASES.index(a.from_phase):PHASES.index(a.through)+1]:
        argv = [sys.executable, str(WORK/'scripts/build_hw.py'), 'C4', phase]
        if phase in ['goldengate', 'driver']:
            previous_phase = 'elaborate' if phase=='goldengate' else 'goldengate'
            previous = next((s for s in reversed(state['phases']) if s['phase']==previous_phase), None)
            if previous is None or previous['status']!='PASSED':
                raise RuntimeError('missing successful prior phase in this supervised build')
            argv += ['--input-result', previous['result_path']]
        before = set((DATA/'build-logs').glob('C4-'+phase+'-*'))
        stream = (DATA/('C4-'+phase+'-supervisor.log')).open('ab', buffering=0)
        started = time.monotonic()
        child = subprocess.Popen(argv, stdout=stream, stderr=subprocess.STDOUT, start_new_session=True)
        stage = dict(phase=phase, argv=argv, pid=child.pid, pgid=child.pid,
                     start_ticks=Path(f'/proc/{child.pid}/stat').read_text().split()[21],
                     status='RUNNING', log=str(DATA/('C4-'+phase+'-supervisor.log')),
                     started_utc=dt.datetime.now(dt.timezone.utc).isoformat())
        state['phases'].append(stage)
        atomic(state_path, state)
        print(json.dumps(stage), flush=True)
        timeout = 7200 if phase=='goldengate' else 5400
        try:
            rc = child.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            os.killpg(child.pid, signal.SIGTERM)
            try:
                child.wait(timeout=30)
            except subprocess.TimeoutExpired:
                os.killpg(child.pid, signal.SIGKILL)
                child.wait()
            rc = 124
        stream.close()
        stage.update(returncode=rc, wall_seconds=time.monotonic()-started,
                     ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
        found = set((DATA/'build-logs').glob('C4-'+phase+'-*'))-before
        receipts = [x/'result.json' for x in found if (x/'result.json').exists()]
        valid = rc==0 and len(receipts)==1
        if valid:
            result = json.loads(receipts[0].read_text())
            valid = result['returncode']==0 and result['phase']==phase
            stage['result_path'] = str(receipts[0])
            stage['result_sha256'] = hashlib.sha256(receipts[0].read_bytes()).hexdigest()
        stage['status'] = 'PASSED' if valid else 'INTERRUPTED' if interrupted else 'TIMEOUT' if rc==124 else 'FAILED'
        if not valid:
            state['status'] = stage['status']
            atomic(state_path,state)
            print(json.dumps(stage),flush=True)
            return rc or 1
        atomic(state_path,state)
        print(json.dumps(stage),flush=True)
        if interrupted:
            state['status']='INTERRUPTED'
            atomic(state_path,state)
            return 130
    state['status']='PASSED'
    atomic(state_path,state)
    return 0


if __name__=='__main__':
    raise SystemExit(main())
