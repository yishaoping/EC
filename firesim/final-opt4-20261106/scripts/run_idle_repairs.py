#!/usr/bin/env python3
"""Run only two explicit repairs after the existing Native queue becomes idle.

Never stop/restart the queue or change any active sample. No deployment or
bitstream build. An exact per-card lock in the existing runner is the final
authority; the whole repair batch holds shared global maintenance protection.
"""
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import subprocess
import time
from board_batch import W,D,save,sha


OUTPUT=D/'idle-repairs-state.json'
BOOT=Path('/proc/sys/kernel/random/boot_id').read_text().strip()


def read(p):return json.loads(p.read_text()) if p.exists() else {}


def receipts(profile):
    return dict(apps=W/f'software/{profile}-apps-build.json',rootfs=W/f'software/{profile}-rootfs-build.json',
                firmware=W/f'software/Native/{profile}-firmware-build.json',driver=W/'runtime/Native-efficiency-driver.json')


def valid_results(program,size,formal,bound):
    result=[]
    for p in (D/'runs').glob(f'native-{program}-{size}-r*/result.json'):
        r=read(p);c=read(p.parent/'complete.json');i=r.get('identity',{})
        if not (r.get('valid') and r.get('formal')==formal and c.get('result_sha256')==sha(p)
                and c.get('identity_sha256')==r.get('identity_sha256')):continue
        if all(i.get(k)==v for k,v in bound.items()):result.append((p,r))
    return result


def quiet_boundary():
    q=read(D/'suite-native-queue-state.json');active=read(D/'active-0000_21_00.0.json')
    if q.get('host_boot_id')!=BOOT or q.get('status')!='WAITING_REMAINING_SOFTWARE':return None
    if active.get('status') in ['RUNNING','STARTING']:return None
    child=q.get('child_pid')
    if child:
        try:
            fields=(Path('/proc')/str(child)/'stat').read_text()
            process_state=fields[fields.rindex(')')+2:].split()[0]
            cmd=(Path('/proc')/str(child)/'cmdline').read_bytes().replace(b'\0',b' ').decode(errors='replace')
            if process_state not in ['Z','X'] and 'run_repetitions.py' in cmd:return None
        except FileNotFoundError:pass
    plan=read(D/'suite-execution-plan.json')
    for task in plan['programs']:
        if 'Native' in task.get('managed_by_existing_queue',[]):continue
        ready=all(p.exists() for p in receipts(task['software_profile_prefix']).values())
        status=q.get('tasks',{}).get(task['program'],{}).get('status')
        if ready and status not in ['COMPLETE','FAILED','FUNCTIONAL_ONLY']:return None
    deployment=read(D/'latest-deployment.json')
    if deployment.get('host_boot_id')!=BOOT:return None
    if not any(c.get('bdf')=='0000:21:00.0' and c.get('configuration')=='Native' for c in deployment.get('completed_cards',[])):return None
    # Prefer the first final C4 run as soon as it becomes possible.
    if read(D/'C4-runtime-cad-state.json').get('status')=='BUILT_NOT_RUN':return None
    first=read(D/'fpga-continuation-state.json')
    if first.get('status') not in ['WAITING_FOR_EXACT_C4_BITSTREAM','WAITING_FOR_ACTIVE_FPGA_SAMPLES']:return None
    return dict(plan_sha256=sha(D/'suite-execution-plan.json'),queue_pid=q.get('pid'),
                queue_start_ticks=q.get('start_ticks'),last_active_run=active.get('run_dir'))


def main():
    assert os.geteuid()==0
    lock=(D/'locks/idle-repairs.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    prior=read(OUTPUT)
    state=dict(schema='ec-targeted-idle-repairs/1',status='WAITING_EXISTING_NATIVE_QUEUE_IDLE',
        host_boot_id=BOOT,pid=os.getpid(),start_ticks=Path('/proc/self/stat').read_text().split()[21],
        started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),tasks=prior.get('tasks',{}),
        no_deployment=True,no_active_inputs_modified=True,no_instruction_checkpoint=True)
    save(OUTPUT,state)
    maintenance=None
    while maintenance is None:
        boundary=quiet_boundary()
        if boundary:
            candidate=(D/'locks/maintenance-0000_21_00.0.lock').open('a')
            try:fcntl.flock(candidate,fcntl.LOCK_SH|fcntl.LOCK_NB)
            except BlockingIOError:candidate.close()
            else:
                if quiet_boundary():maintenance=candidate;state['idle_boundary']=boundary;break
                candidate.close()
        state.update(updated_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(OUTPUT,state)
        time.sleep(300)
    def call(stage,argv):
        log=D/'idle-repair-logs'/(stage+'-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')+'.log');log.parent.mkdir(exist_ok=True)
        state.update(status='RUNNING',stage=stage,argv=list(map(str,argv)),log=str(log));save(OUTPUT,state)
        with log.open('ab',buffering=0) as f:
            child=subprocess.Popen(list(map(str,argv)),cwd=W,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
            state.update(child_pid=child.pid,child_start_ticks=Path(f'/proc/{child.pid}/stat').read_text().split()[21]);save(OUTPUT,state)
            rc=child.wait();os.fsync(f.fileno())
        state.pop('child_pid',None);state.pop('child_start_ticks',None)
        state.setdefault('commands',[]).append(dict(stage=stage,returncode=rc,log=str(log)));save(OUTPUT,state)
        return rc
    try:
        # Same repaired receipts are already selected in the main execution plan.
        bound=receipts('dedup-staged-safe-fdt')
        ident=dict(firmware_receipt_sha256=sha(bound['firmware']),apps_manifest_sha256=sha(bound['apps']),
                   rootfs_sha256=read(bound['rootfs'])['sha256'],driver_receipt_sha256=sha(bound['driver']))
        common=['--bdf','0000:21:00.0']
        for k,p in bound.items():common+=['--'+k+'-receipt',str(p)]
        ok=True
        for size in ['test','simsmall']:
            if valid_results('dedup',size,False,ident):continue
            if call('dedup-'+size,['python3',W/'scripts/run_isolated_sample.py','Native','dedup',size,'--timeout','7200',*common]):ok=False;break
        if ok:
            have=valid_results('dedup','simmedium',True,ident)
            if len({r['identity']['repetition'] for _,r in have})<3:
                ok=call('dedup-formal3',['python3',W/'scripts/run_repetitions.py','Native','--program','dedup','--input','simmedium','--repetitions','3','--timeout','14400',*common])==0
        state['tasks']['dedup']=dict(status='COMPLETE' if ok else 'FAILED_WITH_EVIDENCE',receipts={k:str(p) for k,p in bound.items()});save(OUTPUT,state)
        if state['tasks'].get('fluidanimate-capture',{}).get('status')!='CAPTURE_ATTEMPTED_REVIEW_OUTPUT':
            bound=receipts('fluidanimate-diagnostic');common=['--bdf','0000:21:00.0']
            for k,p in bound.items():common+=['--'+k+'-receipt',str(p)]
            rc=call('fluidanimate-simsmall-capture',['python3',W/'scripts/run_isolated_sample.py','Native','fluidanimate','simsmall','--timeout','7200',*common])
            state['tasks']['fluidanimate-capture']=dict(status='CAPTURE_ATTEMPTED_REVIEW_OUTPUT',returncode=rc,formal_eligible=False,
                receipts={k:str(p) for k,p in bound.items()});save(OUTPUT,state)
        call('summarize',['python3',W/'scripts/summarize_results.py'])
        call('publish',['python3',W/'scripts/publish_live.py'])
        state.update(status='TARGETED_REPAIRS_FINISHED_REVIEW_EVIDENCE',ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    except Exception as exc:
        state.update(status='FAILED_WITH_EVIDENCE',error=repr(exc));raise
    finally:
        maintenance.close();save(OUTPUT,state)


if __name__=='__main__':main()
