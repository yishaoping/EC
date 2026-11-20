#!/usr/bin/python3
"""Install one private CPU-only service, preserving every existing task."""
import fcntl
import os
from pathlib import Path
import subprocess
import sys

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-address-packed-full-module-r1-20261112'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import read,save,sha,now,live


def main():
    pins=read(C/'inputs.json')
    assert pins and all(sha(p)==h for p,h in pins['files'].items())
    unit='ec-opt4-address-packed-full-module-r1-20261112.service'
    path=Path('/home/guozh/.config/systemd/user')/unit
    text=f'''[Unit]
Description=Private equivalent complete address module parity and sequential paired area
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
StandardOutput=append:{O}/service.log
StandardError=append:{O}/service.log
[Install]
WantedBy=default.target
'''
    with (O/'installer.lock').open('a') as lock:
        fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
        state=read(O/'state.json')
        active=subprocess.run(['systemctl','--user','is-active','--quiet',unit]).returncode==0
        if active or live(state) or live(state.get('child',{})):
            print('ADOPT_EXISTING_NO_RESTART');return
        assert not state,'Retain existing failed/complete state; no repeat without versioned diagnosis'
        path.parent.mkdir(parents=True,exist_ok=True)
        if path.exists():assert path.read_text()==text
        else:path.write_text(text)
        subprocess.run(['systemctl','--user','daemon-reload'],check=True)
        subprocess.run(['systemctl','--user','enable','--now',unit],check=True)
        save(C/'installation.json',dict(unit=unit,unit_file=str(path),unit_sha256=sha(path),
            inputs_sha256=sha(C/'inputs.json'),utc=now(),live_tasks_signalled=False,
            fpga_access=False,full_host_synthesis=False,production_admission=False))
        print('STARTED_PRIVATE_COMPLETE_MODULE_PARITY_THEN_SEQUENTIAL_AREA_NO_LIVE_RESTART')


if __name__=='__main__':main()
