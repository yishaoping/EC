#!/usr/bin/python3
"""Install one offline successor; never replace an existing owner."""
from pathlib import Path
import importlib.util
import os
import subprocess
C = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('common_host_abi', C/'controller.py')
m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
binding = m.verify_binding()
unit = 'ec-opt4-common-host-abi-r1-20261113.service'
assert not m.members(unit), 'adopt existing live owner'
m.O.mkdir(exist_ok=True)
assert not (m.O/'state.json').exists(), 'preserve existing result'
env = {**os.environ, 'XDG_RUNTIME_DIR':'/run/user/1008',
    'DBUS_SESSION_BUS_ADDRESS':'unix:path=/run/user/1008/bus'}
result = subprocess.run(['systemd-run', '--user', '--unit='+unit, '--property=Nice=15',
    '--property=Restart=no', '--property=KillMode=control-group', '--property=MemoryMax=2G',
    '--property=LimitCORE=0', '--property=TasksMax=64', '--property=WorkingDirectory='+str(C),
    '--property=StandardOutput=append:'+str(m.O/'service.log'),
    '--property=StandardError=append:'+str(m.O/'service.log'), '/usr/bin/python3', str(C/'controller.py')],
    env=env, capture_output=True, text=True, check=True)
m.exact_json(C/'installation.json', dict(utc=m.now(), unit=unit,
    hardware_commit=m.HW, experiment_commit=binding['experiment_commit'],
    source_binding_sha256=m.sha(C/'source-binding.json'), no_CAD=True, no_FPGA_IO=True,
    no_waiting_CPU_pins=True, no_new_intelligent_supervisor=True, launch_stderr=result.stderr))
print(result.stderr.strip())
