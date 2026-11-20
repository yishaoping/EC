#!/usr/bin/python3
"""Retire only a new, idle, defective continuation; never signal any CAD job."""
from pathlib import Path
import fcntl
import os
import subprocess
import sys
import time

W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U=D/'unattended-opt4'
O=D/'status-audits/ec-real-data-20261112T012600Z/idle-continuation-handoff'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import identity,live,now,read,save,sha

assert os.geteuid()==0
unit='ec-opt4-auto-mcrams-host-continuation-r1-3656aec4.service'
expected={2395830:'25933352',2395831:'25933355'}
statepath=D/'Opt4-mcrams-full-host-continuation-r1-state.json'
jobpath=U/'jobs/mcrams-host-continuation-r1-3656aec4/state.json'
O.mkdir(exist_ok=True)
lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
assert not (O/'complete.json').exists(),'already handed off'
state=read(statepath);job=read(jobpath)
assert state['pid']==2395831 and state['start_ticks']=='25933355'
assert state['status']=='ADOPTING_EXISTING_CAPACITY_AND_PARITY_NO_DUPLICATES'
assert not state.get('child') and not state.get('fpga_access')
assert job['pid']==2395830 and job['child']['pid']==2395831
for pid,start in expected.items():
    actual=identity(pid)
    assert actual['start_ticks']==start and live(actual),('process identity changed',actual)
cg=Path('/sys/fs/cgroup/systemd/system.slice')/unit
assert cg.is_dir() and (cg/'cgroup.procs').is_file()
members=set()
for file in cg.rglob('cgroup.procs'):members.update(map(int,file.read_text().split()))
assert members==set(expected),('must have no CAD/model/extra child',members)
for name in ['mcrams-shell-physical-r1-3656aec4','mcrams-host-report-recovery-r1-3656aec4']:
    assert not (U/'requests'/(name+'.json')).exists(),('successor already submitted',name)
protected=[D/'Opt4-mcrams-full-host-capacity-r1-state.json',D/'Opt4-mcrams-owner-mc-runtime-r2-state.json',D/'Opt4-svb-physical-resume-r3-state.json',D/'Opt4-fit-update-share-svb-cad-state.json']
before={str(p):read(p) for p in protected}
assert all(live(x) for x in before.values()),'retain all active producer identities'
save(O/'before.json',dict(utc=now(),old_state=state,old_job=job,exact_cgroup_members=sorted(members),protected=before,
     reason='Idle new controller misclassifies future physical job and lacks complete physical gates; replace independently, no CAD/model/signals or live input modifications.'))
# Stop only the verified idle job controller. The systemd unit uses KillMode
# process, so terminate its one Python waiting child explicitly, then stop the
# idle wrapper. No CAD or model exists in this exact cgroup.
os.kill(2395831,15)
subprocess.run(['systemctl','stop',unit],check=True)
subprocess.run(['systemctl','disable',unit],check=True,capture_output=True)
for _ in range(30):
    if not any(live(dict(pid=pid,start_ticks=start,host_boot_id=state['host_boot_id'])) for pid,start in expected.items()):break
    time.sleep(0.1)
assert not any(live(dict(pid=pid,start_ticks=start,host_boot_id=state['host_boot_id'])) for pid,start in expected.items())
for file in cg.rglob('cgroup.procs') if cg.exists() else []:assert not file.read_text().strip()
after={str(p):read(p) for p in protected}
for p,old in before.items():
    current=after[p]
    assert current['pid']==old['pid'] and str(current['start_ticks'])==str(old['start_ticks']) and live(current)
state.update(status='RETIRED_IDLE_CONTROLLER_REPLACED_BY_STRICT_R2',retired_utc=now(),reason='No actual CAD/model ever launched by this continuation',child={})
save(statepath,state)
job.update(status='RETIRED_IDLE_CONTROLLER_REPLACED_BY_STRICT_R2',ended_utc=now(),child={})
save(jobpath,job)
save(O/'complete.json',dict(utc=now(),disabled_unit=unit,stopped_only_idle_pids=sorted(expected),
    protected_producer_identities_preserved=True,old_inputs_modified=False,fpga_access=False,
    before_sha256=sha(O/'before.json')))
print('PASS_ONLY_DEFECTIVE_IDLE_CONTROLLER_RETIRED_ALL_CAD_MODELS_PRESERVED')
