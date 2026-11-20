#!/usr/bin/python3
"""Install one versioned priority follower; installation performs no FPGA I/O."""
import os
from pathlib import Path
import subprocess
import sys

C = Path(__file__).resolve().parent
sys.path.insert(0, str(C))
from follower import D, OUT, verify

UNIT = 'ec-opt4-fpga-priority-handoff-r1.service'


def main():
    verify()
    if '--validate-only' in sys.argv:
        print('PASS_PINNED_PRIORITY_HANDOFF_INPUTS_NO_SERVICE_OR_FPGA_ACTIONS')
        return
    assert os.geteuid() == 0, 'installation requires the existing system-service administrator'
    OUT.mkdir(exist_ok=True)
    text = f'''[Unit]
Description=Exact idle MCRams runtime handoff and eight-program FPGA priority
After=local-fs.target
RequiresMountsFor={C} {D}
StartLimitIntervalSec=0
[Service]
Type=simple
User=root
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {C / 'follower.py'}
Restart=on-failure
RestartSec=300
KillMode=process
StandardOutput=append:{OUT / 'service.log'}
StandardError=append:{OUT / 'service.log'}
[Install]
WantedBy=multi-user.target
'''
    path = Path('/etc/systemd/system') / UNIT
    if path.exists():
        assert path.read_text() == text, 'different immutable service requires a new version'
    else:
        path.write_text(text)
    subprocess.run(['systemctl', '--no-ask-password', 'daemon-reload'], check=True)
    subprocess.run(['systemctl', '--no-ask-password', 'enable', '--now', UNIT], check=True)
    print(UNIT)


if __name__ == '__main__':
    main()
