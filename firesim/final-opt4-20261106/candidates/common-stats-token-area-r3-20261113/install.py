#!/usr/bin/python3
"""Install a single deterministic successor with no waiting-time CPU pins."""
from pathlib import Path
import importlib.util
import os
import subprocess

C = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('mixed_token_area_continuation', C/'controller.py')
m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
binding = m.verify_binding()
unit = 'ec-opt4-common-stats-token-area-r3-20261113.service'
assert not m.generation.members(unit), 'Adopt existing continuation'
m.O.mkdir(exist_ok=True)
assert not any((m.O/name).exists() for name in ['queue.json', 'state.json', 'preflight-failure.json'])
env = {**os.environ, 'XDG_RUNTIME_DIR': '/run/user/1008',
       'DBUS_SESSION_BUS_ADDRESS': 'unix:path=/run/user/1008/bus'}
argv = ['systemd-run', '--user', '--unit='+unit, '--property=Nice=10',
    '--property=Restart=no', '--property=KillMode=control-group',
    '--property=MemoryMax=64G', '--property=LimitCORE=0', '--property=TasksMax=1024',
    '--property=WorkingDirectory='+str(C),
    '--property=StandardOutput=append:'+str(m.O/'service.log'),
    '--property=StandardError=append:'+str(m.O/'service.log'),
    '/usr/bin/python3', str(C/'controller.py')]
result = subprocess.run(argv, env=env, capture_output=True, text=True, check=True)
m.save(C/'installation.json', dict(utc=m.now(), unit=unit,
    experiment_commit=binding['experiment_commit'], source_binding_sha256=m.sha(C/'source-binding.json'),
    prerequisite=str(m.P), no_waiting_CPU_affinity=True, cpus_after_exact_release=[206, 207],
    resource_guard_unchanged=True, no_FPGA_IO=True, new_intelligent_supervisor=False,
    launch_stderr=result.stderr))
print(result.stderr.strip())
