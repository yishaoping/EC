#!/usr/bin/env python3
import subprocess,json,os,datetime
from pathlib import Path
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
assert os.geteuid()==0
log=D/'owned-hw-server-3122.log'
with log.open('xb',buffering=0) as f:
    p=subprocess.Popen(['/tools/Xilinx/Vivado/2021.1/bin/hw_server','-s','tcp:127.0.0.1:3122'],stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
r=dict(pid=p.pid,pgid=p.pid,start_ticks=Path(f'/proc/{p.pid}/stat').read_text().split()[21],port=3122,url='localhost:3122',log=str(log),started_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),owned_by_this_campaign=True,other_servers_stopped=False)
(D/'owned-hw-server-3122.json').write_text(json.dumps(r,indent=2)+'\n')
print(json.dumps(r))
