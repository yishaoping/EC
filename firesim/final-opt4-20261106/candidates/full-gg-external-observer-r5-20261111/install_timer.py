#!/usr/bin/python3
"""Install only an independent finite-check system timer; no device operations."""
from pathlib import Path
import os
import subprocess
C=Path(__file__).resolve().parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
UNIT='ec-opt4-external-svb-r5-dispatch'
service=f'''[Unit]
Description=Submit external SVB full observer once after existing Canneal completion
After=local-fs.target
RequiresMountsFor={C} {D}
[Service]
Type=oneshot
User=guozh
Group=guozh
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {C}/dispatch.py
TimeoutStartSec=120
CPUQuota=100%
MemoryMax=1G
Nice=15
StandardOutput=append:{D}/external-svb-r5-dispatch.log
StandardError=append:{D}/external-svb-r5-dispatch.log
'''
timer='''[Unit]
Description=Check external SVB full observer prerequisites every five minutes
[Timer]
OnBootSec=60s
OnUnitInactiveSec=300s
Persistent=true
AccuracySec=20s
Unit=ec-opt4-external-svb-r5-dispatch.service
[Install]
WantedBy=timers.target
'''
assert os.geteuid()==0,'root required only for dedicated system timer installation'
for suffix,text in [('service',service),('timer',timer)]:
 p=Path('/etc/systemd/system')/(UNIT+'.'+suffix)
 if p.exists():assert p.read_text()==text,'Existing independent unit changed; preserve and create another version'
 else:p.write_text(text)
subprocess.run(['systemctl','daemon-reload'],check=True)
subprocess.run(['systemctl','enable','--now',UNIT+'.timer'],check=True)
subprocess.run(['systemctl','start',UNIT+'.service'],check=True)
print(UNIT+'.timer')
