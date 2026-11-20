#!/usr/bin/python3
"""Install only the bounded private source compilation job."""
import os
from pathlib import Path
import subprocess
from prepare import exact

C = Path(__file__).resolve().parent
O = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-banked-storage-compose-r1-20261112')
UNIT = 'ec-opt4-address-banked-storage-compose-r1-20261112.service'
O.mkdir(exist_ok=True)
assert not (O/'state.json').exists(), 'Adopt existing source compilation'
unit = Path('/home/guozh/.config/systemd/user')/UNIT
exact(unit, f'''[Unit]
Description=Private production bank plus DCache storage source compile only
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
AllowedCPUs=218 219
StandardOutput=append:{O}/service.log
StandardError=append:{O}/service.log
[Install]
WantedBy=default.target
''')
env = {**os.environ, 'XDG_RUNTIME_DIR':'/run/user/1008',
       'DBUS_SESSION_BUS_ADDRESS':'unix:path=/run/user/1008/bus'}
subprocess.run(['systemctl','--user','daemon-reload'], env=env, check=True)
subprocess.run(['systemctl','--user','enable','--now',UNIT], env=env, check=True)
print('STARTED_PRIVATE_COMPOSED_SOURCE_COMPILE_ONLY_NO_ELABORATION_CAD_OR_FPGA')
