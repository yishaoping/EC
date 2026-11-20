#!/usr/bin/env python3
"""Replace only this task's parent controller after its active child exits.

The child process group and FPGA sample are untouched. pidfds wait for the
known child exit; no device operations, polling process scans, or sample restart.
"""
import datetime as dt
import json
import os
from pathlib import Path
import select
import signal
import subprocess
from board_batch import W,D,save


def main():
    assert os.geteuid()==0
    path=D/'suite-native-queue-state.json';state=json.loads(path.read_text())
    pid=state['pid'];child=state['child_pid'];proc=Path('/proc')/str(pid)
    assert state['status']=='RUNNING' and state['stage']=='swaptions-formal3'
    assert (proc/'stat').read_text().split()[21]==state['start_ticks']
    assert 'suite_queue.py' in (proc/'cmdline').read_bytes().decode()
    assert 'run_repetitions.py' in (Path('/proc')/str(child)/'cmdline').read_bytes().decode()
    pidfd=os.pidfd_open(pid);childfd=os.pidfd_open(child)
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    receipt=D/('suite-native-rollover-'+stamp+'.json')
    record=dict(status='WAITING_CURRENT_CHILD_EXIT',pid=os.getpid(),old_controller_pid=pid,active_child_pid=child,active_child_untouched=True,archive=str(D/('suite-native-before-rollover-'+stamp+'.json')))
    Path(record['archive']).write_bytes(path.read_bytes())
    # Pause the scheduler only. Its already launched repetition child has its
    # own process/session and maintenance/card locks and keeps running.
    signal.pidfd_send_signal(pidfd,signal.SIGSTOP)
    save(receipt,record)
    poll=select.poll();poll.register(childfd,select.POLLIN)
    while not poll.poll(300000):
        record['heartbeat_utc']=dt.datetime.now(dt.timezone.utc).isoformat();save(receipt,record)
    signal.pidfd_send_signal(pidfd,signal.SIGTERM)
    signal.pidfd_send_signal(pidfd,signal.SIGCONT)
    ended=select.poll();ended.register(pidfd,select.POLLIN)
    assert ended.poll(10000),'old parent did not exit; do not start another'
    log=D/'suite-native-queue-refreshed-launch.log'
    with log.open('ab',buffering=0) as stream:
        new=subprocess.Popen(['python3',str(W/'scripts/suite_queue.py'),'Native'],cwd=W,stdin=subprocess.DEVNULL,stdout=stream,stderr=subprocess.STDOUT,start_new_session=True)
    record.update(status='REPLACED_AFTER_CHILD_EXIT',new_controller_pid=new.pid,log=str(log),ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(receipt,record)
    print(json.dumps(record),flush=True)


if __name__=='__main__':main()
