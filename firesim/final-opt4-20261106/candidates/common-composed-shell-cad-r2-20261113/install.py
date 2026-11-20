#!/usr/bin/python3
"""Install exactly one offline complete-shell CAD successor, no restart."""
from pathlib import Path
import importlib.util
import os
import subprocess

C = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('shell_installer', C/'controller.py')
m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
unit = 'ec-opt4-common-composed-shell-cad-r2-20261113.service'
env = {**os.environ, 'XDG_RUNTIME_DIR': '/run/user/1008',
    'DBUS_SESSION_BUS_ADDRESS': 'unix:path=/run/user/1008/bus'}
status = subprocess.run(['systemctl', '--user', 'show', unit, '-p', 'ActiveState', '--value'],
    env=env, capture_output=True, text=True)
assert status.stdout.strip() not in ['active', 'activating'], 'Adopt existing owner'
assert not (m.O/'state.json').exists(), 'Adopt immutable terminal or live owner'
binding = m.read(C/'source-binding.json')
assert all(m.sha(path) == digest for path, digest in binding['files'].items())
m.O.mkdir(exist_ok=True)
result = subprocess.run(['systemd-run', '--user', '--unit='+unit, '--property=Nice=10',
    '--property=Restart=no', '--property=KillMode=control-group', '--property=MemoryMax=128G',
    '--property=LimitCORE=0', '--property=TasksMax=1024', '--property=WorkingDirectory='+str(C),
    '--property=StandardOutput=append:'+str(m.O/'service.log'),
    '--property=StandardError=append:'+str(m.O/'service.log'),
    '/usr/bin/python3', str(C/'controller.py')], env=env, capture_output=True, text=True, check=True)
m.save(C/'installation.json', dict(utc=m.now(), unit=unit,
    hardware_commit=m.COMMIT, source_binding_sha256=m.sha(C/'source-binding.json'),
    no_waiting_CPU_pins=True, no_FPGA_IO=True, no_new_intelligent_supervisor=True,
    launch_stderr=result.stderr))
print(result.stderr.strip())
