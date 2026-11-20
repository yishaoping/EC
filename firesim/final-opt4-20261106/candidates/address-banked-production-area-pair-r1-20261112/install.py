#!/usr/bin/python3
"""Install a separate waiting continuation without modifying the live validator."""
import importlib.util
import os
from pathlib import Path
import subprocess

C = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('production_area_pair', C/'controller.py')
m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
unit = 'ec-opt4-address-banked-production-area-pair-r1-20261112.service'
m.O.mkdir(exist_ok=True)
assert not (m.O/'state.json').exists(), 'Adopt the existing area continuation'
path = Path('/home/guozh/.config/systemd/user')/unit
m.m.exact(path, f'''[Unit]
Description=Validated complete production AddressStats serial plain/threaded host area pair
After=default.target
[Service]
Type=simple
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {C}/controller.py
Nice=10
Restart=no
KillMode=control-group
LimitCORE=0
TasksMax=1024
MemoryMax=64G
AllowedCPUs=212 213
StandardOutput=append:{m.O}/service.log
StandardError=append:{m.O}/service.log
[Install]
WantedBy=default.target
''')
env = {**os.environ, 'XDG_RUNTIME_DIR':'/run/user/1008',
       'DBUS_SESSION_BUS_ADDRESS':'unix:path=/run/user/1008/bus'}
subprocess.run(['systemctl', '--user', 'daemon-reload'], env=env, check=True)
subprocess.run(['systemctl', '--user', 'enable', '--now', unit], env=env, check=True)
m.save(C/'installation.json', dict(unit=unit, utc=m.now(), queued_continuation=True,
    validation_owner=str(m.P), cpus=[212,213], memory_limit_gib=64,
    r4_screen_positive_required=False, full_system_fit=False, fpga_access=False))
print('QUEUED_COMPLETE_PRODUCTION_HOST_AREA_PAIR_AFTER_VALIDATION_AND_EXACT_CGROUP_RELEASE')
