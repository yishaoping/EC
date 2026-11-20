#!/usr/bin/env python3
"""One authorized failed-workload repair, after the existing Native jobs exit.

No deployment, reset, driver operation, or second full-suite queue. Original
failed task remains evidence; the current full-suite process is not restarted.
"""
import argparse
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import subprocess
import time
from board_batch import W,D,save,sha
from job_service import proc

PROFILE='fluidanimate-stable-formal'
OUTPUT=D/'fluidanimate-stable-native-state.json'
BOOT=Path('/proc/sys/kernel/random/boot_id').read_text().strip()


def read(p):return json.loads(p.read_text()) if p.exists() else {}


def bindings():
    return dict(apps=W/f'software/{PROFILE}-apps-build.json',rootfs=W/f'software/{PROFILE}-rootfs-build.json',
        firmware=W/f'software/Native/{PROFILE}-firmware-build.json',driver=W/'runtime/Native-efficiency-driver.json')


def boundary():
    adoption=read(D/'software/fluidanimate-stable-formal-adoption.json')
    if adoption.get('status')!='BOUND_FOR_BOTH_CONFIGURATIONS':return 'WAITING_AUTHORIZED_PROFILE_READY',None
    task=next(t for t in read(D/'suite-execution-plan.json')['programs'] if t['program']=='fluidanimate')
    assert task['software_profile_prefix']==PROFILE and task.get('native_owner')=='ec-parsec-fluidanimate-stable-native.service'
    q=read(D/'suite-native-queue-state.json');active=read(D/'active-0000_21_00.0.json')
    if q.get('host_boot_id')!=BOOT or q.get('status')!='WAITING_REMAINING_SOFTWARE':return 'WAITING_EXISTING_NATIVE_QUEUE_IDLE',None
    if active.get('status') in ['RUNNING','STARTING']:return 'WAITING_ACTIVE_SAMPLE',None
    repair=read(D/'idle-repairs-state.json')
    if repair.get('status') not in ['TARGETED_REPAIRS_FINISHED_REVIEW_EVIDENCE','FAILED_WITH_EVIDENCE']:return 'WAITING_EXISTING_IDLE_REPAIRS',None
    cad=read(D/'C4-runtime-cad-state.json')
    if cad.get('status')=='BUILT_NOT_RUN':return 'YIELDING_TO_READY_C4_BITSTREAM',None
    deploy=read(D/'latest-deployment.json')
    if deploy.get('host_boot_id')!=BOOT or not any(c.get('bdf')=='0000:21:00.0' and c.get('configuration')=='Native' for c in deploy.get('completed_cards',[])):
        return 'WAITING_EXISTING_NATIVE_DEPLOYMENT_NO_GLOBAL_OPERATIONS',None
    return 'SAFE_NATIVE_BOUNDARY',dict(queue_pid=q.get('pid'),queue_start_ticks=q.get('start_ticks'),last_run=active.get('run_dir'),
        idle_repairs_status=repair.get('status'),adoption_sha256=sha(D/'software/fluidanimate-stable-formal-adoption.json'),
        deployment_sha256=sha(D/'latest-deployment.json'))


def exact_results(size,formal,bound):
    found=[]
    for p in (D/'runs').glob(f'native-fluidanimate-{size}-r*/result.json'):
        r=read(p);c=read(p.parent/'complete.json')
        if (r.get('valid') and r.get('formal')==formal and c.get('result_sha256')==sha(p)
            and c.get('identity_sha256')==r.get('identity_sha256') and all(r['identity'].get(k)==v for k,v in bound.items())):
            found.append((p,r))
    return found


def main():
    a=argparse.ArgumentParser();a.add_argument('--check-only',action='store_true');args=a.parse_args()
    if args.check_only:
        status,detail=boundary();print(json.dumps(dict(status=status,boundary=detail,fpga_operations=False)));return
    assert os.geteuid()==0
    lock=(D/'locks/fluidanimate-stable-native.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    prior=read(OUTPUT)
    if prior.get('status')=='COMPLETE':
        bound=prior['bound'];have=exact_results('simmedium',True,bound)
        if {r['identity']['repetition'] for _,r in have}>={1,2,3}:return
    if prior:
        history=D/'plan-history'/('fluidanimate-stable-native-before-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')+'.json');save(history,prior)
    state=dict(schema='ec-authorized-fluidanimate-native-repair/1',status='WAITING_AUTHORIZED_PROFILE_READY',
        host_boot_id=BOOT,pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],
        started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),no_deployment=True,no_live_job_input_changes=True,
        profile=PROFILE,original_failure_state=str(D/'suite-native-queue-state.json'),completed_commands=[])
    save(OUTPUT,state)
    maintenance=None;existing_repair=None
    while maintenance is None:
        reason,detail=boundary();state.update(status=reason,updated_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(OUTPUT,state)
        if detail:
            # The earlier repair must have released its lock, not merely written
            # a terminal state just before its process exits.
            try:
                existing_repair=(D/'locks/idle-repairs.lock').open('a');fcntl.flock(existing_repair,fcntl.LOCK_EX|fcntl.LOCK_NB)
                candidate=(D/'locks/maintenance-0000_21_00.0.lock').open('a');fcntl.flock(candidate,fcntl.LOCK_SH|fcntl.LOCK_NB)
            except BlockingIOError:
                if existing_repair:existing_repair.close();existing_repair=None
                if 'candidate' in locals():candidate.close()
            else:
                if boundary()[1]:maintenance=candidate;state['idle_boundary']=detail;break
                candidate.close();existing_repair.close();existing_repair=None
        time.sleep(300)
    def call(label,argv):
        stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
        log=D/'idle-repair-logs'/('fluidanimate-stable-'+label+'-'+stamp+'.log');log.parent.mkdir(exist_ok=True)
        state.update(status='RUNNING',stage=label,command=list(map(str,argv)),persistent_log=str(log));save(OUTPUT,state)
        with log.open('ab',buffering=0) as f:
            child=subprocess.Popen(list(map(str,argv)),cwd=W,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
            state.update(child_pid=child.pid,child_start_ticks=proc(child.pid)['start_ticks']);save(OUTPUT,state)
            while child.poll() is None:
                try:child.wait(timeout=30)
                except subprocess.TimeoutExpired:pass
                state.update(updated_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(OUTPUT,state);os.fsync(f.fileno())
            os.fsync(f.fileno())
        state.pop('child_pid',None);state.pop('child_start_ticks',None)
        state['completed_commands'].append(dict(stage=label,returncode=child.returncode,log=str(log)));save(OUTPUT,state)
        if child.returncode:raise RuntimeError(f'{label} returned {child.returncode}; retained evidence: {log}')
    try:
        paths=bindings();apps=read(paths['apps']);rootfs=read(paths['rootfs']);driver=read(paths['driver'])
        assert apps['formal_eligible'] and apps['software_profile']=='fluidanimate-stable-index-pairing-authorized-repair'
        bound=dict(configuration='Native',program='fluidanimate',board_bdf='0000:21:00.0',hardware_source_id=driver['hardware_source_id'],
            apps_manifest_sha256=sha(paths['apps']),elf_sha256=apps['binaries']['fluidanimate']['sha256'],rootfs_sha256=rootfs['sha256'],
            firmware_receipt_sha256=sha(paths['firmware']),driver_receipt_sha256=sha(paths['driver']))
        state.update(bound=bound,receipts={k:str(v) for k,v in paths.items()});save(OUTPUT,state)
        common=['--bdf','0000:21:00.0']
        for key,p in paths.items():common+=['--'+key+'-receipt',str(p)]
        for size in ['test','simsmall']:
            if not exact_results(size,False,bound):
                call(size,['python3',W/'scripts/run_isolated_sample.py','Native','fluidanimate',size,'--timeout','7200',*common])
        if len({r['identity']['repetition'] for _,r in exact_results('simmedium',True,bound)})<3:
            call('formal3',['python3',W/'scripts/run_repetitions.py','Native','--program','fluidanimate','--input','simmedium','--repetitions','3','--timeout','14400',*common])
        formal=exact_results('simmedium',True,bound);assert {r['identity']['repetition'] for _,r in formal}>={1,2,3}
        state.update(status='COMPLETE',formal_results=[str(p) for p,_ in formal],completed_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(OUTPUT,state)
        # Publishers have their own lock and cannot affect the live queue.
        subprocess.run(['python3',W/'scripts/summarize_results.py'],cwd=W,check=True)
        subprocess.run(['python3',W/'scripts/publish_live.py'],cwd=W,check=True)
    except Exception as exc:
        state.update(status='FAILED_WITH_EVIDENCE',error=repr(exc));save(OUTPUT,state);raise
    finally:
        maintenance.close();existing_repair.close()


if __name__=='__main__':main()
