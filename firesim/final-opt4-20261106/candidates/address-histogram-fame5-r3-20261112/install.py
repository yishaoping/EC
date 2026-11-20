#!/usr/bin/python3
import importlib.util
import os
from pathlib import Path
import subprocess

C=Path(__file__).resolve().parent
spec=importlib.util.spec_from_file_location('histogram_fame5',C/'controller.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
cfg,pins=m.prepare()
assert all(m.sha(p)==h for p,h in pins['files'].items())
unit='ec-opt4-address-histogram-fame5-r3-20261112.service'
path=Path('/home/guozh/.config/systemd/user')/unit
m.exact(path,f'''[Unit]
Description=Actual 80-source 256-slot address histogram FAME5 token and paired host area
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
''')
assert not (m.O/'state.json').exists(), 'Adopt existing attempt; never restart'
env={**os.environ,'XDG_RUNTIME_DIR':'/run/user/1008','DBUS_SESSION_BUS_ADDRESS':'unix:path=/run/user/1008/bus'}
subprocess.run(['systemctl','--user','daemon-reload'],env=env,check=True)
subprocess.run(['systemctl','--user','enable','--now',unit],env=env,check=True)
m.save(C/'installation.json',dict(unit=unit,utc=m.now(),inputs_sha256=m.sha(C/'inputs.json'),
    fpga_access=False,full_system_build=False,production_admission=False))
print('STARTED_SOURCE_BOUND_FAME5_SMOKES_THEN_FULL256_PAIRED_HOST_AREA')
