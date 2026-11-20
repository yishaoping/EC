#!/usr/bin/python3
"""Install a conditional reuse-only card21 application-trace runtime follower."""
import json
import os
from pathlib import Path
import subprocess
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
L = D/'cycleprecise-original-svb-application-onboard-recovered-r1-20261111'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import live, read, save, sha, now


def main():
    assert os.geteuid() == 0
    pins = read(C/'inputs.json')
    assert pins['board_allowlist'] == ['0000:21:00.0'] and pins['no_deployment_operations']
    for p,h in pins['files'].items():
        assert sha(p) == h
    assert not live(read(L/'state.json')), 'adopt existing follower'
    assert not (L/'run-started.json').exists(), 'adopt existing run evidence'
    subprocess.run(['/usr/bin/python3', str(C/'run.py'), '--offline'], check=True)
    L.mkdir(exist_ok=True)
    unit = 'ec-opt4-original-svb-application-onboard-recovered-r1.service'
    text = f'''[Unit]
Description=Reuse certified card21 SVB component for proven real application trace
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User=root
WorkingDirectory={W}
ExecStart=/usr/bin/python3 {C}/run.py
Environment=PYTHONPATH={W}/scripts
Nice=10
CPUQuota=200%
MemoryMax=24G
TasksMax=256
Restart=no
KillMode=process
StandardOutput=append:{L}/service.log
StandardError=append:{L}/service.log
[Install]
WantedBy=multi-user.target
'''
    path = Path('/etc/systemd/system')/unit
    if path.exists():
        assert path.read_text() == text
    else:
        path.write_text(text)
    save(L/'installation.json', dict(unit=unit, unit_sha256=sha(path), inputs_sha256=sha(C/'inputs.json'),
        installed_utc=now(), deployment_operations=[], fpga_access_at_install=False,
        rule='No deployment; wait bound CPU real trace proof, original SVB certificate and completed directed board run, matching current deployment and both card21 locks. Full Opt4 has priority.'))
    subprocess.run(['systemctl','daemon-reload'], check=True)
    subprocess.run(['systemctl','enable','--now',unit], check=True)
    subprocess.run(['systemctl','show',unit,'-p','MainPID','-p','ActiveState'], check=True)


if __name__ == '__main__':
    main()
