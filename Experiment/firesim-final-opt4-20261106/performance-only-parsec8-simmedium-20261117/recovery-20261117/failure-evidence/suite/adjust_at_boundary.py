#!/usr/bin/env python3
"""Pause only this suite orchestrator at a deployment boundary; preserve children."""
from pathlib import Path
import json
import os
import select
import signal
import subprocess
import time
import ctypes

ROOT=Path(__file__).resolve().parent
PID=1505274
assert os.geteuid()==0
cmd=(Path('/proc')/str(PID)/'cmdline').read_bytes().replace(b'\0',b' ')
assert str(ROOT/'run.py').encode() in cmd and b'--run' in cmd
fd=os.pidfd_open(PID)
lib=ctypes.CDLL(None,use_errno=True)
watch=lib.inotify_init1(os.O_NONBLOCK|os.O_CLOEXEC)
assert watch>=0 and lib.inotify_add_watch(watch,os.fsencode(ROOT),0x80|0x8)>=0
print(json.dumps({'status':'WAITING_ONE_SAFE_DEPLOYMENT_BOUNDARY','periodic_patrol':False}),flush=True)
while True:
    state=json.loads((ROOT/'state.json').read_text())
    assert state['pid']==PID
    if state.get('phase')=='CARD21_DEPLOYMENT':
        os.kill(PID,signal.SIGSTOP)
        time.sleep(.05)
        children=[int(p) for p in (Path('/proc')/str(PID)/'task'/str(PID)/'children').read_text().split()]
        commands=[]
        for child in children:
            try:commands.append((Path('/proc')/str(child)/'cmdline').read_bytes().replace(b'\0',b' '))
            except FileNotFoundError:pass
        if all(not c or b'after-physical.py' in c for c in commands):break
        os.kill(PID,signal.SIGCONT)
    ready,_,_=select.select([watch,fd],[],[],1200)
    assert ready,'Finite boundary wait expired without interrupting FPGA'
    assert fd not in ready,'Controller ended naturally; no restart performed'
    try:os.read(watch,65536)
    except BlockingIOError:pass
os.close(watch)
children_fds=[]
for child in children:
    try:children_fds.append(os.pidfd_open(child))
    except ProcessLookupError:pass
print(json.dumps({'status':'ORCHESTRATOR_PAUSED_AT_DEPLOYMENT_BOUNDARY','orchestrator':PID,
                  'deployment_children_left_running':children}),flush=True)
for childfd in children_fds:
    poll=select.poll();poll.register(childfd,select.POLLIN)
    assert poll.poll(2400000),'Deployment did not finish; no FPGA process was interrupted'
    os.close(childfd)
os.kill(PID,signal.SIGTERM)
os.kill(PID,signal.SIGCONT)
poll=select.poll();poll.register(fd,select.POLLIN);assert poll.poll(10000)
os.close(fd)
record=dict(status='HOST_TIMEOUT_ADJUSTMENT_SAFE_BOUNDARY',old_controller=PID,
            deployment_children_completed=children,FPGA_driver_interrupted=False,
            reason='600s boot guard too short for measured 659k target cycles/s at 10 MHz host',
            prior_attempts_preserved=True)
(ROOT/'boundary-adjustment.json').write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps(record),flush=True)
# Preserve only attempts that expired before the application command was sent.
archive=ROOT/'boot-limit600-attempts';archive.mkdir(exist_ok=True)
for directory in (ROOT/'runs').iterdir():
    result=directory/'result.json';s=directory/'state.json'
    if result.exists() and s.exists():
        r=json.loads(result.read_text());rs=json.loads(s.read_text())
        if r.get('timedout') and not rs.get('guest_ready'):
            directory.rename(archive/directory.name)
subprocess.run(['/usr/bin/python3','-I',str(ROOT/'run.py'),'--start'],check=True)
