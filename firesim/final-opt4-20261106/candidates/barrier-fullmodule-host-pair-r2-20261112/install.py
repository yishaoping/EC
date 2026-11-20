#!/usr/bin/python3
"""Install a single user-owned CPU-only continuation."""
import importlib.util
import subprocess
from pathlib import Path

C=Path(__file__).resolve().parent
spec=importlib.util.spec_from_file_location('barrier_fullpair',C/'controller.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
cfg,pins=m.prepare()
assert all(m.sha(p)==h for p,h in pins['files'].items())
unit='ec-opt4-barrier-fullmodule-host-pair-r2-20261112.service'
path=Path('/home/guozh/.config/systemd/user')/unit
text=f'''[Unit]
Description=Complete actual barrier finite parity then paired GoldenGate host area
After=default.target
[Service]
Type=simple
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {C}/controller.py
Nice=10
Restart=no
KillMode=process
LimitCORE=0
TasksMax=1024
StandardOutput=append:{m.O}/service.log
StandardError=append:{m.O}/service.log
[Install]
WantedBy=default.target
'''
assert not (m.O/'state.json').exists(), 'Adopt existing attempt; no restart'
m.exact(path,text)
subprocess.run(['systemctl','--user','daemon-reload'],check=True)
subprocess.run(['systemctl','--user','enable','--now',unit],check=True)
m.save(C/'installation.json',dict(unit=unit,utc=m.now(),inputs_sha256=m.sha(C/'inputs.json'),
    fpga_access=False,full_system_build=False,production_admission=False))
print('STARTED_COMPLETE_BARRIER_PARITY_THEN_SEQUENTIAL_HOST_AREA')
