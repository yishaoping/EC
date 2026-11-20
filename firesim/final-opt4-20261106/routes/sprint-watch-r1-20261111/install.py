#!/usr/bin/python3
import datetime as dt, json, os, pathlib, subprocess
P=pathlib.Path;C=P(__file__).resolve().parent
W=P('/data1/gzh/EC/firesim/final-opt4-20261106');D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
assert os.geteuid()==0
L=D/'opt4-sprint-24h-20261111';L.mkdir(exist_ok=True);os.chown(L,1008,1008)
p=L/'policy.json'
if not p.exists():
    t=dt.datetime.now(dt.timezone.utc)
    p.write_text(json.dumps(dict(started_utc=t.isoformat(),deadline_utc=(t+dt.timedelta(hours=24)).isoformat(),functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',interval_seconds=600,native_paused=True,board_allowlist=['0000:21:00.0'],fpga_access=False),indent=2)+'\n');os.chown(p,1008,1008)
unit='ec-opt4-sprint-watch-r1.service'
s=f'''[Unit]
Description=Opt4 24 hour measured-capacity checkpoint (read-only)
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
User=guozh
Group=guozh
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {C}/watch.py
Nice=19
CPUQuota=20%
MemoryMax=256M
Restart=on-failure
RestartSec=30
StandardOutput=append:{L}/service.log
StandardError=append:{L}/service.log
[Install]
WantedBy=multi-user.target
'''
p=P('/etc/systemd/system')/unit
if p.exists():assert p.read_text()==s
else:p.write_text(s)
subprocess.run(['systemctl','daemon-reload'],check=True);subprocess.run(['systemctl','enable','--now',unit],check=True)
