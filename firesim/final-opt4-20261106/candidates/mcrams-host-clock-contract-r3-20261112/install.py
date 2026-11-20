#!/usr/bin/python3
"""Replace only the exact idle two-Python consumer, never a CAD producer."""
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
AUDIT = D/'status-audits/fpga-critical-unblock-20261112T0530Z'
OLD = 'ec-opt4-auto-mcrams-host-continuation-r2-3656aec4.service'
NEW = 'ec-opt4-mcrams-host-continuation-r3-clock-3656aec4.service'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, read, save, sha, now


def properties(unit):
    command = ['systemctl','show',unit]
    for key in ['MainPID','ActiveState','ControlGroup']:
        command += ['-p',key]
    return dict(l.split('=',1) for l in subprocess.check_output(command,text=True).splitlines() if '=' in l)


def rows(unit):
    props = properties(unit)
    cg = Path('/sys/fs/cgroup/systemd/system.slice')/unit
    result = []
    if cg.exists():
        for pid in sorted({int(x) for p in cg.rglob('cgroup.procs') for x in p.read_text().split()}):
            row = identity(pid)
            row['argv'] = [x.decode() for x in (Path('/proc')/str(pid)/'cmdline').read_bytes().split(b'\0') if x]
            result.append(row)
    return props,result


def main():
    assert os.geteuid()==0
    spec=importlib.util.spec_from_file_location('clock_contract_repair',C/'physical.py')
    helper=importlib.util.module_from_spec(spec);spec.loader.exec_module(helper);helper.verify()
    assert not (D/'Opt4-mcrams-shell-physical-r2-state.json').exists()
    assert not (D/'unattended-opt4/requests/mcrams-shell-physical-r2-3656aec4.json').exists()
    assert not (D/'unattended-opt4/requests/mcrams-shell-physical-r3-clock-3656aec4.json').exists()
    props,old=rows(OLD)
    state=read(D/'Opt4-mcrams-full-host-continuation-r2-state.json')
    expected={
        ('/usr/bin/python3',str(W/'scripts/opt4_unattended_cpu_job.py'),str(D/'unattended-opt4/jobs/mcrams-host-continuation-r2-3656aec4/spec.json')),
        ('/usr/bin/python3',str(C.parent/'mcrams-full-host-continuation-r2-20261112/continue.py')),
    }
    assert props['ActiveState']=='active' and {tuple(r['argv']) for r in old}==expected and len(old)==2
    assert live(state) and state['status'] in ['ADOPTING_EXISTING_CAPACITY_AND_PARITY_NO_DUPLICATES','HOST_OOC_FIT_REQUIRES_ACTUAL_TARGET_PARITY_BEFORE_SHELL']
    assert any(r['pid']==state['pid'] and r['start_ticks']==state['start_ticks'] for r in old)
    assert props['ControlGroup']=='/system.slice/'+OLD
    _,newrows=rows(NEW);assert not newrows
    # Record the exact producer identities; neither belongs to the consumer
    # cgroup. They must remain alive and unchanged across the handoff.
    producers={}
    for pid in [2379594,2379596,2379656,2378806,2378807,2692645,2692703]:
        row=identity(pid);assert live(row)
        assert pid not in {r['pid'] for r in old}
        producers[str(pid)]=row
    unit=f'''[Unit]
Description=Complete MCRams existing producer consumer with generated clock contract repair r3
After=local-fs.target
RequiresMountsFor={W} {D}
StartLimitIntervalSec=0
[Service]
Type=simple
User=guozh
Group=guozh
WorkingDirectory={C}
ExecStart=/usr/bin/python3 {C}/continue.py
Restart=on-failure
RestartSec=30
KillMode=control-group
Nice=10
TasksMax=64
MemoryMax=1G
StandardOutput=append:{AUDIT}/continuation-r3-service.log
StandardError=append:{AUDIT}/continuation-r3-service.log
[Install]
WantedBy=multi-user.target
'''
    path=Path('/etc/systemd/system')/NEW
    if path.exists():assert path.read_text()==unit
    else:path.write_text(unit)
    AUDIT.mkdir(exist_ok=True)
    save(AUDIT/'consumer-r2-before-handoff.json',dict(captured_utc=now(),state=state,properties=props,processes=old,producers=producers,physical_inputs_unchanged=True))
    # Re-read immediately. The only signalled tasks are the two exact idle
    # Python waiters above; there are no CAD, simulation or device children.
    props2,old2=rows(OLD)
    assert [(r['pid'],r['start_ticks'],r['argv']) for r in old2]==[(r['pid'],r['start_ticks'],r['argv']) for r in old]
    assert not (D/'unattended-opt4/requests/mcrams-shell-physical-r2-3656aec4.json').exists()
    subprocess.run(['systemctl','kill','--kill-who=all','--signal=TERM',OLD],check=True)
    subprocess.run(['systemctl','stop',OLD],check=True)
    subprocess.run(['systemctl','disable',OLD],check=True,capture_output=True)
    for _ in range(20):
        p,r=rows(OLD)
        if p['MainPID']=='0' and not r:break
        time.sleep(.25)
    assert p['MainPID']=='0' and not r
    subprocess.run(['systemctl','daemon-reload'],check=True)
    subprocess.run(['systemctl','enable','--now',NEW],check=True,capture_output=True)
    for _ in range(20):
        state=read(D/'Opt4-mcrams-full-host-continuation-r2-state.json')
        if state.get('continuation_revision')=='r3-generated-clock-contract' and live(state):break
        time.sleep(.25)
    assert state.get('continuation_revision')=='r3-generated-clock-contract' and live(state)
    for pid,oldrow in producers.items():
        newrow=identity(int(pid));assert live(newrow) and newrow['start_ticks']==oldrow['start_ticks']
    save(AUDIT/'consumer-r3-installed.json',dict(completed_utc=now(),old_service=OLD,new_service=NEW,
        old_consumer_only_tasks_retired=old,producers_preserved=producers,new_state=state,
        replacement_source_sha256=sha(C/'continue.py'),clock_repair_sha256=sha(C/'physical.py'),
        cad_signals=[],fpga_access=False,old_bound_sources_modified=False))
    print('MCRAMS_CLOCK_CONTRACT_R3_CONSUMER_RUNNING_PRODUCERS_UNCHANGED')


if __name__=='__main__':main()
