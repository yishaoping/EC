#!/usr/bin/python3
"""Start exactly one bounded compile; no model supervisor or FPGA access."""
from pathlib import Path
import importlib.util
import os
import subprocess

C = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('common_composed_compile', C/'controller.py')
m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
binding = m.verify_binding()
assert not m.cpu_owners(), 'Dedicated CPUs are owned'
m.O.mkdir(exist_ok=True)
assert not (m.O/'state.json').exists(), 'Adopt existing compile'
unit = 'ec-opt4-common-composed-source-r1-20261113.service'
env = {**os.environ, 'XDG_RUNTIME_DIR': '/run/user/1008',
    'DBUS_SESSION_BUS_ADDRESS': 'unix:path=/run/user/1008/bus'}
result = subprocess.run(['systemd-run', '--user', '--unit='+unit, '--property=Nice=10',
    '--property=Restart=no', '--property=KillMode=control-group', '--property=MemoryMax=64G',
    '--property=LimitCORE=0', '--property=TasksMax=1024', '--property=WorkingDirectory='+str(C),
    '--property=StandardOutput=append:'+str(m.O/'service.log'),
    '--property=StandardError=append:'+str(m.O/'service.log'),
    '/usr/bin/python3', str(C/'controller.py')], env=env, capture_output=True, text=True, check=True)
m.save(C/'installation.json', dict(utc=m.now(), unit=unit, hardware_commit=binding['hardware_commit'],
    source_binding_sha256=m.sha(C/'source-binding.json'), no_elaboration=True, no_CAD=True,
    no_FPGA_IO=True, no_new_intelligent_supervisor=True, cpus=[218, 219], launch_stderr=result.stderr))
print(result.stderr.strip())
