#!/usr/bin/env python3
"""Sequential system builds with explicit receipt dependencies, no FPGA access."""
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import subprocess
import sys

W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
def save(path,obj):
    tmp=path.with_suffix('.tmp')
    with tmp.open('w') as f:
        json.dump(obj,f,indent=2);f.write('\n');f.flush();os.fsync(f.fileno())
    tmp.replace(path)
def main():
    lock=(D/'.system-supervisor.lock').open('a')
    fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    state=dict(schema='ec-system-supervisor/1',status='RUNNING',pid=os.getpid(),start_ticks=Path('/proc/self/stat').read_text().split()[21],phases=[],no_fpga_access=True)
    path=D/'system-supervisor-state.json'
    for config,phase in [('C4','kernel'),('Native','kernel'),('C4','firmware'),('Native','firmware')]:
        argv=[sys.executable,str(W/'scripts/build_system.py'),config,phase]
        if phase=='firmware':argv+=['--kernel-result',str(W/'software'/config/'kernel-build.json'),'--fdt-result',str(W/'software'/config/'fdt-build.json')]
        entry=dict(configuration=config,phase=phase,started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),argv=argv,status='RUNNING')
        state['phases'].append(entry);save(path,state)
        with (D/(config+'-'+phase+'-system-supervisor.log')).open('ab',buffering=0) as f:
            child=subprocess.Popen(argv,stdout=f,stderr=subprocess.STDOUT)
            entry['pid']=child.pid;save(path,state)
            rc=child.wait()
        entry.update(status='BUILT_NOT_RUN' if rc==0 else 'FAILED',returncode=rc,ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
        if rc:
            state['status']='FAILED';save(path,state);return rc
        receipt=W/'software'/config/(phase+'-build.json');entry['receipt']=str(receipt);save(path,state)
    state['status']='BUILT_NOT_RUN';save(path,state);return 0
if __name__=='__main__':raise SystemExit(main())
