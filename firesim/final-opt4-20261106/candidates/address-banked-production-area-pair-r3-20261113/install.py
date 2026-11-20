#!/usr/bin/python3
"""Install only a new deterministic waiter; it inherits no live CPU pins."""
from pathlib import Path
import importlib.util
import os
import subprocess

C = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('r4_area_waiter', C/'controller.py')
m = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m)
m.verify_binding()
unit = 'ec-opt4-address-banked-production-area-pair-r3-20261113.service'
env = {**os.environ, 'XDG_RUNTIME_DIR': '/run/user/1008',
       'DBUS_SESSION_BUS_ADDRESS': 'unix:path=/run/user/1008/bus'}
m.O.mkdir(exist_ok=True)
assert not (m.O/'queue.json').exists() and not (m.O/'state.json').exists()
assert not m.members(unit)
args = ['systemd-run', '--user', '--unit='+unit, '--property=Nice=10',
    '--property=Restart=no', '--property=KillMode=control-group',
    '--property=MemoryMax=64G', '--property=LimitCORE=0', '--property=TasksMax=1024',
    '--property=WorkingDirectory='+str(C),
    '--property=StandardOutput=append:'+str(m.O/'service.log'),
    '--property=StandardError=append:'+str(m.O/'service.log'),
    '/usr/bin/python3', str(C/'controller.py')]
result = subprocess.run(args, env=env, capture_output=True, text=True, check=True)
m.save(C/'installation.json', dict(unit=unit, utc=m.now(),
    source_binding_sha256=m.sha(C/'source-binding.json'), prerequisite=str(m.P),
    serial_area_cpus_after_validator_release=[212, 213], memory_limit_gib=64,
    queued_only=True, no_FPGA_IO=True, new_intelligent_supervisor=False,
    launch_stderr=result.stderr))
print(result.stderr.strip())
