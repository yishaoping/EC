#!/usr/bin/python3
from pathlib import Path
import os,subprocess
C=Path(__file__).resolve().parent;D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
UNIT='ec-opt4-svb-gg-stream-replay-r2-dispatch'
service=f'''[Unit]
Description=Submit SVB unchanged-GG streaming replay after complete application trace proof
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
StandardOutput=append:{D}/svb-gg-stream-replay-r2-dispatch.log
StandardError=append:{D}/svb-gg-stream-replay-r2-dispatch.log
'''
timer='''[Unit]
Description=Check complete original SVB application streaming replay prerequisites
[Timer]
OnBootSec=60s
OnUnitInactiveSec=300s
Persistent=true
AccuracySec=20s
Unit=ec-opt4-svb-gg-stream-replay-r2-dispatch.service
[Install]
WantedBy=timers.target
'''
assert os.geteuid()==0
for suffix,text in [('service',service),('timer',timer)]:
 p=Path('/etc/systemd/system')/(UNIT+'.'+suffix)
 if p.exists():assert p.read_text()==text
 else:p.write_text(text)
subprocess.run(['systemctl','daemon-reload'],check=True)
subprocess.run(['systemctl','enable','--now',UNIT+'.timer'],check=True)
subprocess.run(['systemctl','start',UNIT+'.service'],check=True)
print(UNIT+'.timer')
