#!/usr/bin/env python3
"""Retire only the verified idle certification waiter; never signal CAD."""
import datetime as dt
import hashlib
import json
import os
from pathlib import Path
import select
import shutil
import signal

O=Path('/var/tmp/guozh-ec-checker-fault-20261117/physical-r1')
C=Path('/data1/gzh/EC/firesim/final-opt4-20261106/Opt4-checker-fault-repair-20261117/candidates/checker-instruction-fault-20261117')
pid=1992511
p=Path('/proc',str(pid))
assert os.geteuid()==0
fd=os.pidfd_open(pid)
assert p.joinpath('stat').read_text().rsplit(') ',1)[1].split()[19]=='70091918'
assert p.joinpath('cmdline').read_bytes().split(b'\0')[1:]==[
    b'-I',str(C/'complete.py').encode(),b'--wait-pid',b'1953532',b'--start-ticks',b'69978335',b'']
assert json.loads((O/'completion-state.json').read_text())['status']=='WAITING_OWNED_BUILD_EXIT_SINGLE_EVENT_NO_PATROL'
assert not (O/'physical-complete.json').exists()
assert json.loads((O/'state.json').read_text())['pid']==1953532
assert Path('/proc/1953532/stat').read_text().rsplit(') ',1)[1].split()[19]=='69978335'
archive=O/'completion-rebind-20261117-strict-sample-gate'
archive.mkdir()
files=['completion.log','completion-launcher.json','completion-state.json','completion-control-binding.json']
for name in files:
    shutil.copy2(O/name,archive/name)
os.kill(pid,signal.SIGTERM)
poll=select.poll();poll.register(fd,select.POLLIN)
assert poll.poll(10000),'idle waiter did not exit; do not create a duplicate'
os.close(fd)
(O/'completion.log').unlink()  # archived above; new launcher uses exclusive create
row=dict(status='IDLE_COMPLETION_WAITER_STOPPED_FOR_POLICY_REBIND',pid=pid,
    utc=dt.datetime.now(dt.timezone.utc).isoformat(),cad_signalled=False,
    fpga_access=False,archived={name:hashlib.sha256((archive/name).read_bytes()).hexdigest() for name in files})
(archive/'transition.json').write_text(json.dumps(row,indent=2)+'\n')
(O/'completion-state.json').write_text(json.dumps(row,indent=2)+'\n')
print(json.dumps(row))
