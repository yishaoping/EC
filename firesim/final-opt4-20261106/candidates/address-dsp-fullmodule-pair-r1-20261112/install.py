#!/usr/bin/python3
import importlib.util
from pathlib import Path
import subprocess

C=Path(__file__).resolve().parent
spec=importlib.util.spec_from_file_location('actual_address_dsp_pair',C/'controller.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
pins=m.prepare()
assert all(m.sha(p)==h for p,h in pins['files'].items())
unit='ec-opt4-address-dsp-fullmodule-pair-r1-20261112.service'
path=Path('/home/guozh/.config/systemd/user')/unit
assert not (m.O/'state.json').exists(), 'Adopt existing job, no restart'
text=f'''[Unit]
Description=Actual full generated address3072wideadders DSP attributes only paired map
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
m.exact(path,text)
subprocess.run(['systemctl','--user','daemon-reload'],check=True)
subprocess.run(['systemctl','--user','enable','--now',unit],check=True)
m.save(C/'installation.json',dict(unit=unit,utc=m.now(),inputs_sha256=m.sha(C/'inputs.json'),
    fpga_access=False,whole_system_build=False,production_admission=False))
print('STARTED_ACTUAL_COMPLETE_ADDRESS_DSP_PAIR_NO_TARGET_LOGIC_OR_CYCLE_CHANGE')
