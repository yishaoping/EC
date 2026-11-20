#!/usr/bin/python3
"""Strict exact-cgroup recovery guard; no UNKNOWN-to-empty inference."""
import importlib.util
import os
from pathlib import Path
import subprocess
import sys

C=Path(__file__).resolve().parent
W=C.parent.parent
R1=C.with_name('svb-postroute-recovery-r1-20261111')
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import read,save,sha,now,identity


def verify():
    pins=read(C/'inputs.json')
    for p,h in pins['files'].items():assert sha(p)==h,('strict recovery source changed',p)
    return pins


def strict_empty(unit):
    # Existing physical jobs were launched as these exact system units.
    assert unit in ['ec-opt4-original-svb-spread-impl-r1.service',
                    'ec-opt4-frozen-svb-fpga-r2.service']
    raw=subprocess.run(['systemctl','show',unit,'-p','MainPID','-p','ControlGroup','-p','ActiveState'],
                       capture_output=True,text=True,check=True).stdout
    values=dict(x.split('=',1) for x in raw.splitlines() if '=' in x)
    if values.get('MainPID')!='0' or values.get('ActiveState') not in ['failed','inactive']:
        return False
    expected='/system.slice/'+unit
    group=values.get('ControlGroup','')
    if group and group!=expected:
        return False
    # Never rely on TasksCurrent (which can be UNKNOWN after a wrapper exit).
    # Explicitly inspect the known exact systemd cgroup even when its reported
    # ControlGroup field is empty. Absence is accepted only after the inactive
    # unit/MainPID0 checks above; a missing hierarchy/procs file is not empty.
    hierarchy=Path('/sys/fs/cgroup/systemd')
    if not hierarchy.is_dir():return False
    target=hierarchy/expected.lstrip('/')
    if not target.exists():return True
    if not (target/'cgroup.procs').is_file():return False
    for p in target.rglob('cgroup.procs'):
        if p.read_text().strip():return False
    return True


def module():
    spec=importlib.util.spec_from_file_location('strict_recovery_r1',R1/'run.py')
    m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
    m.unit_empty=strict_empty
    return m
