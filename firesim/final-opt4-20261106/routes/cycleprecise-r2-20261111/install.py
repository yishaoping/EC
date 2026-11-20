#!/usr/bin/python3
"""Install this bounded independent CPU route; never signal existing jobs/devices."""
import os, pathlib, json, subprocess, hashlib
P=pathlib.Path
W=P('/data1/gzh/EC/firesim/final-opt4-20261106')
D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C=P(__file__).resolve().parent
assert os.geteuid()==0
p=json.loads((D/'unattended-opt4/campaign-policy.json').read_text())
assert p['native_paused'] and p['area_equivalence_only'] and not p['functional_extensions_allowed']
assert p['functional_baseline_commit']=='8491167d84b6d9521b151a743673c1516926a1f8'
mem=int(next(l.split()[1] for l in P('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))
assert mem>256*2**20 and os.getloadavg()[0]<96
L=D/'cycleprecise-route-a-r2-20261111';L.mkdir(exist_ok=True);os.chown(L,1008,1008)
unit='ec-opt4-cycleprecise-route-a-r2.service'
text=f'''[Unit]
Description=Bounded Opt4 Golden Gate cycle precise prototypes (no FPGA access)
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User=guozh
Group=guozh
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {C}/run.py
Environment=PATH=/usr/bin:/bin
Nice=15
CPUQuota=400%
MemoryMax=64G
TasksMax=512
Restart=no
StandardOutput=append:{L}/service.log
StandardError=append:{L}/service.log
[Install]
WantedBy=multi-user.target
'''
dest=P('/etc/systemd/system')/unit
if dest.exists():assert dest.read_text()==text
else:dest.write_text(text)
subprocess.run(['systemctl','daemon-reload'],check=True)
subprocess.run(['systemctl','enable','--now',unit],check=True)
subprocess.run(['systemctl','show',unit,'-p','ActiveState','-p','MainPID','-p','MemoryMax','-p','CPUQuotaPerSecUSec'],check=True)
