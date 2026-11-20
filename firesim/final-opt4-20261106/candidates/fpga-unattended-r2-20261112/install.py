#!/usr/bin/python3
"""Install a conditional, safe-boundary versioned supervisor replacement."""
import os
from pathlib import Path
import subprocess
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
OUT = D / 'fpga-unattended-r2-20261112'
UNIT = 'ec-opt4-unattended-r2.service'
sys.path.insert(0, str(C))
from takeover import load


def main():
    load()
    assert os.geteuid() == 0
    OUT.mkdir(exist_ok=True)
    text = f'''[Unit]
Description=Bounded FPGA unattended supervisor after natural old round exit
After=local-fs.target network-online.target
Wants=network-online.target
RequiresMountsFor={W} {D}
StartLimitIntervalSec=0
[Service]
Type=simple
User=root
WorkingDirectory={W}
ExecStart=/usr/bin/python3 {C / 'takeover.py'}
Restart=on-failure
RestartSec=30
KillMode=process
StandardOutput=append:{OUT / 'service.log'}
StandardError=append:{OUT / 'service.log'}
UMask=0022
[Install]
WantedBy=multi-user.target
'''
    path = Path('/etc/systemd/system') / UNIT
    if path.exists():
        assert path.read_text() == text
    else:
        path.write_text(text)
    subprocess.run(['systemctl', '--no-ask-password', 'daemon-reload'], check=True)
    subprocess.run(['systemctl', '--no-ask-password', 'enable', '--now', UNIT], check=True)
    print(UNIT)


if __name__ == '__main__':
    main()
