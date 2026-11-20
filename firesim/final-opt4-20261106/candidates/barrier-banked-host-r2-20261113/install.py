#!/usr/bin/python3
"""Install one immutable CPU/CAD experiment, with no FPGA access."""
from pathlib import Path
import importlib.util
import os
import subprocess

C=Path(__file__).resolve().parent
spec=importlib.util.spec_from_file_location('barrier_banked_owner',C/'controller.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
binding=m.read(m.PC/'source-binding.json')
binding['recovery']=dict(predecessor=str(m.P),diagnosis='PromoteSubmodule requires local selected instances; flatten only the complete-host harness with source-identical target logic.',hardware_source_unchanged=True,host_source_sha256=m.sha(C/'Host.scala'))
binding['hardware_commit']=subprocess.check_output(['git','rev-parse','HEAD'],cwd=m.TREE,text=True).strip()
for path,h in binding['source_files'].items():
    rel=Path(path).relative_to(m.TREE)
    import hashlib
    blob=subprocess.check_output(['git','show',binding['hardware_commit']+':'+str(rel)],cwd=m.TREE)
    assert hashlib.sha256(blob).hexdigest()==h
m.m.exact(C/'source-binding.json',__import__('json').dumps(binding,indent=2,sort_keys=True)+'\n')
m.O.mkdir(exist_ok=True)
assert not (m.O/'state.json').exists(),'Adopt the existing owner; never restart'
unit='ec-opt4-barrier-banked-host-r2-20261113.service'
path=Path('/home/guozh/.config/systemd/user')/unit
text=f'''[Unit]
Description=Complete 256-entry barrier bank target host tokens and serial area screens
After=default.target
[Service]
Type=simple
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {C}/controller.py
Nice=10
Restart=no
KillMode=process
LimitCORE=0
MemoryMax=64G
CPUAffinity=206 207
TasksMax=1024
StandardOutput=append:{m.O}/service.log
StandardError=append:{m.O}/service.log
[Install]
WantedBy=default.target
'''
m.m.exact(path,text)
env={**os.environ,'XDG_RUNTIME_DIR':'/run/user/1008','DBUS_SESSION_BUS_ADDRESS':'unix:path=/run/user/1008/bus'}
subprocess.run(['systemctl','--user','daemon-reload'],env=env,check=True)
subprocess.run(['systemctl','--user','enable','--now',unit],env=env,check=True)
m.save(C/'installation.json',dict(unit=unit,utc=m.now(),hardware_commit=binding['hardware_commit'],
    source_binding_sha256=m.sha(C/'source-binding.json'),FPGA_IO=False,new_intelligent_supervisor=False))
print('STARTED_FULL256_BARRIER_BANK_TARGET_HOST_AREA_EXPERIMENT')
