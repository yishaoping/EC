#!/usr/bin/python3
"""Install one deterministic distinct geometry screen; preserve original owners."""
from pathlib import Path
import importlib.util
import os
import subprocess
import sys
C=Path(__file__).resolve().parent
sys.path.insert(0,str(C))
spec=importlib.util.spec_from_file_location('distinct_geometry_owner',C/'controller.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
binding=m.verify_binding();m.helper_gate()
unit='ec-opt4-common-mixed-geometry-r1-20261113.service'
assert not m.members(unit),'Adopt existing exact screen'
m.O.mkdir(exist_ok=True)
assert not any((m.O/name).exists() for name in ['state.json','preflight-failure.json'])
env={**os.environ,'XDG_RUNTIME_DIR':'/run/user/1008','DBUS_SESSION_BUS_ADDRESS':'unix:path=/run/user/1008/bus'}
result=subprocess.run(['systemd-run','--user','--unit='+unit,'--property=Nice=10',
    '--property=Restart=no','--property=KillMode=control-group','--property=MemoryMax=64G',
    '--property=LimitCORE=0','--property=TasksMax=1024','--property=WorkingDirectory='+str(C),
    '--property=StandardOutput=append:'+str(m.O/'service.log'),
    '--property=StandardError=append:'+str(m.O/'service.log'),
    '/usr/bin/python3',str(C/'controller.py')],env=env,capture_output=True,text=True,check=True)
m.save(C/'installation.json',dict(utc=m.now(),unit=unit,experiment_commit=binding['experiment_commit'],
    source_binding_sha256=m.sha(C/'source-binding.json'),cpus_after_admission=sorted(m.CPUS),
    geometries=[8,32],slots_each=256,original16_owner_preserved=True,
    no_waiting_CPU_pins=True,resource_guard_unchanged=True,no_FPGA_IO=True,
    no_new_intelligent_supervisor=True,launch_stderr=result.stderr))
print(result.stderr.strip())
