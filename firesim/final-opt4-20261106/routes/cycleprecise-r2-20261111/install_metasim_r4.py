#!/usr/bin/python3
import os, pathlib, subprocess, json, hashlib, sys
P=pathlib.Path;W=P('/data1/gzh/EC/firesim/final-opt4-20261106');D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');C=P(__file__).resolve().parent
assert os.geteuid()==0
mem=int(next(s.split()[1] for s in P('/proc/meminfo').read_text().splitlines() if s.startswith('MemAvailable:')))
assert mem>256*2**20 and os.getloadavg()[0]<96
unit='ec-opt4-cycleprecise-metasim-r4.service';L=D/'cycleprecise-metasim-r4-20261111';L.mkdir(exist_ok=True);os.chown(L,1008,1008)
s=f'''[Unit]
Description=Opt4 Golden Gate same-target multi-cycle metasim (no FPGA)
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
User=guozh
Group=guozh
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {C}/metasim_recovery_r4.py
Nice=15
CPUQuota=200%
MemoryMax=32G
TasksMax=512
Restart=no
StandardOutput=append:{L}/service.log
StandardError=append:{L}/service.log
[Install]
WantedBy=multi-user.target
'''
p=P('/etc/systemd/system')/unit
if p.exists():assert p.read_text()==s
else:p.write_text(s)
subprocess.run(['systemctl','daemon-reload'],check=True);subprocess.run(['systemctl','enable','--now',unit],check=True)

