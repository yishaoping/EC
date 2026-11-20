#!/usr/bin/env python3
"""Campaign-scoped systemd jobs: audit identities, adopt live jobs, resume only dead jobs."""
import argparse
import datetime as dt
import fcntl
import hashlib
import json
import os
from pathlib import Path
import select
import subprocess
import sys
import time
from board_batch import W,D,save,sha

J=D/'jobs';S=W/'scripts/job-specs'
def read(p):return json.loads(p.read_text()) if p.exists() else {}
def boot():return Path('/proc/sys/kernel/random/boot_id').read_text().strip()
def proc(pid):
    try:
        p=Path('/proc')/str(pid);s=(p/'stat').read_text();v=s[s.rindex(')')+2:].split()
        return dict(pid=int(pid),start_ticks=v[19],process_state=v[0],cmdline=(p/'cmdline').read_bytes().replace(b'\0',b' ').decode(errors='replace'))
    except (FileNotFoundError,ProcessLookupError):return None
def inspect(path):
    j=read(path);rows=[]
    for k,t in [('pid','start_ticks'),('child_pid','child_start_ticks')]:
        if not j.get(k):continue
        try:r=proc(j[k])
        except PermissionError:r=dict(pid=j[k],unreadable=True)
        match=bool(r and j.get('host_boot_id')==boot() and j.get(t) is not None
                   and str(j[t])==r.get('start_ticks') and r.get('process_state') not in ['Z','X'])
        uncertain=bool(r and j.get('host_boot_id') in [None,boot()]
                       and (r.get('unreadable') or j.get(t) is None))
        rows.append(dict(field=k,expected_start_ticks=j.get(t),observed=r,identity_live=match,
                         identity_uncertain=uncertain,old_boot=j.get('host_boot_id') not in [None,boot()]))
    return dict(path=str(path),status=j.get('status'),recorded_boot_id=j.get('host_boot_id'),processes=rows)
def audit(spec):
    paths=[Path(p) for p in spec.get('legacy_states',[])]+[J/spec['name']/'state.json']
    return dict(schema='ec-job-identity-audit/1',observed_utc=dt.datetime.now(dt.timezone.utc).isoformat(),current_boot_id=boot(),job=spec['name'],states=[inspect(p) for p in paths])
def interrupted():
    """Archive only stale states, never results/completion evidence or live inputs."""
    recovery_lock=(D/'locks/job-interruption-reconcile.lock').open('a');fcntl.flock(recovery_lock,fcntl.LOCK_EX)
    dest=D/'interruptions'/('host-reboot-'+boot());dest.mkdir(parents=True,exist_ok=True)
    paths=[D/n for n in ['C4-runtime-cad-state.json','fpga-continuation-state.json','suite-native-queue-state.json','suite-c4-queue-state.json','active-0000_e2_00.0.json']]
    paths+=list((D/'runs').glob('*/state.json'))+list((D/'sampling-batches').glob('*/state.json'))
    changed=[]
    for p in paths:
        j=read(p)
        if j.get('host_boot_id') in [None,boot()] or j.get('status') not in ['RUNNING','STARTING','WAITING_FOR_EXACT_C4_BITSTREAM','WAITING_EXISTING_PRIORITY_QUEUE']:continue
        assert not any(x['identity_live'] for x in inspect(p)['processes'])
        if (p.parent/'complete.json').exists() or (p.parent/'result.json').exists():continue
        target=dest/p.relative_to(D);target.parent.mkdir(parents=True,exist_ok=True)
        if not target.exists():target.write_bytes(p.read_bytes())
        j.update(status='INTERRUPTED',interruption_reason='confirmed host boot_id change; prior process identity no longer exists',interrupted_by_host_boot_id=boot(),interruption_observed_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(p,j);changed.append(str(p))
    receipt=read(dest/'receipt.json');receipt.update(host_boot_id=boot(),observed_utc=dt.datetime.now(dt.timezone.utc).isoformat(),changed_states=sorted(set(receipt.get('changed_states',[])+changed)),valid_samples_unchanged=True,fpga_or_process_actions=False);save(dest/'receipt.json',receipt)
def run(spec):
    out=J/spec['name'];out.mkdir(parents=True,exist_ok=True)
    lock=(out/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    snapshot=audit(spec);save(out/'startup-audit.json',snapshot)
    # A previous process outside systemd is monitored in place. It is never
    # stopped, migrated, or replaced by this service.
    live=[x['observed'] for s in snapshot['states'] for x in s['processes'] if x['identity_live']]
    uncertain=[x for s in snapshot['states'] for x in s['processes'] if x.get('identity_uncertain')]
    prior=read(out/'state.json')
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    if prior:save(out/('before-'+stamp+'.json'),prior)
    state=dict(schema='ec-service-job/1',job=spec['name'],pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=boot(),started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),service_unit='ec-parsec-'+spec['name']+'.service',status='ADOPTED_MONITOR' if live else 'STARTING',spec_sha256=sha(S/(spec['name']+'.json')),persistent_log=str(out/'console.log'),checkpoint_paths=spec.get('legacy_states',[]),no_instruction_checkpoint=True)
    save(out/'state.json',state)
    # An incomplete legacy identity is not proof of exit and cannot authorize
    # another task. A known live parent still permits monitoring in place.
    if uncertain and not live:
        state.update(status='IDENTITY_REQUIRES_REVIEW_NO_START',uncertain_processes=uncertain,
                     ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
        save(out/'state.json',state);return
    if live:
        fds=[]
        for r in live:
            try:fds.append(os.pidfd_open(r['pid']))
            except ProcessLookupError:pass
        while fds:
            done,_,_=select.select(fds,[],[],300)
            for fd in done:os.close(fd);fds.remove(fd)
            state.update(updated_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(out/'state.json',state)
        state.update(status='ADOPTED_PROCESSES_EXITED_REVIEW_CHECKPOINT',ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(out/'state.json',state)
        if not spec.get('resume_after_adopted_exit'):return
    interrupted()
    if spec.get('completion_state'):
        bound=read(Path(spec['completion_state']['path']))
        if bound.get('status') in spec['completion_state']['statuses']:
            state.update(status='COMPLETE_REUSED_CHECKPOINT',ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(out/'state.json',state);return
    # Bind scripts once per start, then let the job save its own checkpoints.
    state['command']=spec['argv'];state['input_sha256']={p:sha(p) for p in spec.get('inputs',[])}
    with (out/'console.log').open('ab',buffering=0) as log:
        log.write((json.dumps(dict(event='START',utc=state['started_utc'],boot_id=boot(),argv=spec['argv']))+'\n').encode());os.fsync(log.fileno())
        child=subprocess.Popen(spec['argv'],cwd=W,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,start_new_session=True)
        state.update(status='RUNNING',child_pid=child.pid,child_start_ticks=proc(child.pid)['start_ticks']);save(out/'state.json',state)
        while child.poll() is None:
            try:child.wait(timeout=30)
            except subprocess.TimeoutExpired:pass
            state.update(updated_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(out/'state.json',state);os.fsync(log.fileno())
        state.update(status='COMPLETE' if child.returncode==0 else 'FAILED_WITH_EVIDENCE',returncode=child.returncode,ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(out/'state.json',state)
    if child.returncode and spec.get('restart_supervisor_on_error'):
        raise RuntimeError(f"{spec['name']} exited {child.returncode}; retained checkpoint/log; systemd bounded restart")
    # Concrete application failure stays visible; no unbounded restart loop.
def main():
    a=argparse.ArgumentParser();a.add_argument('operation',choices=['audit','run','install']);a.add_argument('name',nargs='?');v=a.parse_args()
    specs=[read(p) for p in sorted(S.glob('*.json')) if not v.name or p.stem==v.name];assert specs
    if v.operation=='audit':print(json.dumps([audit(s) for s in specs],indent=2));return
    assert os.geteuid()==0
    if v.operation=='run':assert len(specs)==1;run(specs[0]);return
    J.mkdir(exist_ok=True)
    units=[]
    for s in specs:
        name=s['name'];assert name.replace('-','').isalnum()
        unit=f'ec-parsec-{name}.service';out=J/name;out.mkdir(exist_ok=True)
        text=f'''[Unit]
Description=EC PARSEC campaign {name}
After=local-fs.target network-online.target
RequiresMountsFor={W} {D} /var/tmp/guozh-firesim-final-opt4-20261107-cad
StartLimitIntervalSec=600
StartLimitBurst=3

[Service]
Type=simple
User=root
WorkingDirectory={W}
ExecStart=/usr/bin/python3 {W}/scripts/job_service.py run {name}
Restart=on-failure
RestartSec=30
KillMode=control-group
TimeoutStopSec=90
StandardOutput=append:{out}/service.log
StandardError=append:{out}/service.log
UMask=0022

[Install]
WantedBy=multi-user.target
'''
        target=Path('/etc/systemd/system')/unit
        if target.exists() and target.read_text()!=text:
            old=target.read_text();assert f'ExecStart=/usr/bin/python3 {W}/scripts/job_service.py run {name}\n' in old
            assert subprocess.run(['systemctl','is-active','--quiet',unit]).returncode!=0,'do not modify an active unit'
            (out/('unit-before-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')+'.service')).write_text(old)
            target.write_text(text)
        else:target.write_text(text)
        (out/'unit.service').write_text(text);units.append(unit)
    subprocess.run(['systemctl','daemon-reload'],check=True)
    subprocess.run(['systemctl','enable',*units],check=True)
    print(json.dumps(dict(installed=units,started=False)))
if __name__=='__main__':main()
