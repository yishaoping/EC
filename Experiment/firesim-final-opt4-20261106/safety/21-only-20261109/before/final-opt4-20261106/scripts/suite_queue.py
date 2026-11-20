#!/usr/bin/env python3
"""Extend the existing campaign without duplicating its priority controllers.

    No bitstream build. Deployment is reused; after a failed C4 guest only, the
    existing certified bitstream can be redeployed during unified idle maintenance.
    Each ready
program runs independently, failed programs remain recorded and do not block
the rest. Entire program batches retain the shared maintenance lock.
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

BDF='0000:21:00.0'


def read(p,default=None):return json.loads(p.read_text()) if p.exists() else default


def main():
    p=argparse.ArgumentParser();p.add_argument('configuration',choices=['Native','C4']);a=p.parse_args()
    assert os.geteuid()==0
    cfg=a.configuration
    lock=(D/f'locks/suite-{cfg.lower()}-queue.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    output=D/f'suite-{cfg.lower()}-queue-state.json'
    boot=Path('/proc/sys/kernel/random/boot_id').read_text().strip()
    old=read(output,{})
    if old:save(D/('queue-history-'+cfg+'-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')+'.json'),old)
    state=dict(schema='ec-full-suite-queue/1',configuration=cfg,pid=os.getpid(),start_ticks=Path('/proc/self/stat').read_text().split()[21],host_boot_id=boot,
        started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),status='WAITING_FOR_SOFTWARE',tasks={},bitstream_build_operations=False,
        recovery_deployment_policy='Only exact certified C4 image after concrete failed guest; board_batch obtains global exclusive maintenance and rechecks conflicts')
    save(output,state)
    def run(label,argv):
        log=D/'suite-queue-logs'/(cfg+'-'+label+'-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')+'.log')
        log.parent.mkdir(exist_ok=True)
        state.update(status='RUNNING',stage=label,log=str(log),argv=list(map(str,argv)))
        with log.open('wb',buffering=0) as f:
            child=subprocess.Popen(list(map(str,argv)),cwd=W,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
            state['child_pid']=child.pid;save(output,state);rc=child.wait()
        state.pop('child_pid',None);state.setdefault('completed_commands',[]).append(dict(stage=label,returncode=rc,log=str(log)))
        save(output,state)
        return rc
    def existing(program,inp,formal,receipts):
        apps=read(receipts['apps']);rootfs=read(receipts['rootfs'])
        found=[]
        for path in (D/'runs').glob(cfg.lower()+'-'+program+'-'+inp+'-r*/result.json'):
            r=read(path);i=r['identity'];c=read(path.parent/'complete.json',{})
            if not(r.get('valid') and r.get('formal')==formal and c.get('result_sha256')==sha(path) and c.get('identity_sha256')==r['identity_sha256']):continue
            if not(i['apps_manifest_sha256']==sha(receipts['apps']) and i['rootfs_sha256']==rootfs['sha256'] and i['elf_sha256']==apps['binaries'][program]['sha256'] and i['firmware_receipt_sha256']==sha(receipts['firmware']) and i['driver_receipt_sha256']==sha(receipts['driver'])):continue
            found.append(r)
        return found
    try:
        while True:
            assert Path('/proc/sys/kernel/random/boot_id').read_text().strip()==boot
            plan=read(D/'suite-execution-plan.json');state['plan_sha256']=sha(D/'suite-execution-plan.json')
            did_work=False
            if cfg=='C4':
                parents=[read(D/n,{}) for n in ['fpga-continuation-state.json','c4-canneal-continuation-state.json','c4-streamcluster-continuation-state.json']]
                terminals={'C4_INITIAL_BATCH_COMPLETE','C4_INITIAL_BATCH_FINISHED_WITH_FAILURES','COMPLETE','COMPLETE_FUNCTIONAL_ONLY','STOPPED_ON_CONCRETE_FAILURE','INTERRUPTED','SUPERSEDED_BY_FULL_SUITE_QUEUE'}
                if not all(s.get('status') in terminals for s in parents):
                    state.update(status='WAITING_EXISTING_PRIORITY_QUEUE',heartbeat_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(output,state);time.sleep(300);continue
                deployment=read(D/'latest-deployment.json',{})
                consumed=read(D/'consumed-0000_e2_00.0.json',{})
                generation=deployment.get('started_utc','')+'|'+BDF+'|'+deployment.get('bitstream_sha256','')
                if consumed.get('deployment_generation')==generation:
                    previous=read(Path(consumed['run_dir'])/'result.json',{})
                    if not previous.get('valid'):
                        # No shared maintenance lock is held here. The deployment
                        # tool independently requires all cards idle and rechecks
                        # concrete device users before each global operation.
                        rc=run('recover-after-invalid-guest',['python3',W/'scripts/board_batch.py','--deploy-only','--single-c4-bdf',BDF])
                        if rc:raise RuntimeError('certified C4 recovery deployment failed; inspect saved command log')
            for task in plan['programs']:
                name=task['program']
                # A profile may become ready while another program runs for
                # hours. Resolve the latest bound profile at each boundary.
                current_plan=read(D/'suite-execution-plan.json')
                task=next(t for t in current_plan['programs'] if t['program']==name)
                if cfg in task.get('managed_by_existing_queue',[]):
                    state['tasks'][name]=dict(status='OWNED_BY_EXISTING_PRIORITY_QUEUE');continue
                profile=task['software_profile_prefix']
                receipts=dict(apps=W/f'software/{profile}-apps-build.json',rootfs=W/f'software/{profile}-rootfs-build.json',
                    firmware=W/f'software/{cfg}/{profile}-firmware-build.json',driver=W/f'runtime/{cfg}-efficiency-driver.json')
                if not all(p.exists() for p in receipts.values()):
                    state['tasks'][name]=dict(status='WAITING_SOFTWARE',missing=[str(p) for p in receipts.values() if not p.exists()]);continue
                apps=read(receipts['apps']);formal_eligible=apps.get('formal_eligible',True)
                if cfg=='C4' and apps.get('c4_incompatible_reason'):
                    state['tasks'][name]=dict(status='BLOCKED_ROI_SYSCALL',reason=apps['c4_incompatible_reason']);continue
                formal=existing(name,'simmedium',True,receipts)
                if len({r['identity']['repetition'] for r in formal})>=3:
                    state['tasks'][name]=dict(status='COMPLETE',reused=True);continue
                if state['tasks'].get(name,{}).get('status') in ['FAILED','FUNCTIONAL_ONLY']:continue
                cad=read(D/'C4-runtime-cad-state.json',{})
                if cfg=='Native' and cad.get('status')=='BUILT_NOT_RUN':
                    state.update(status='YIELDING_TO_READY_C4_BITSTREAM');save(output,state);return
                maintenance=(D/'locks/dual-maintenance.lock').open('a')
                try:fcntl.flock(maintenance,fcntl.LOCK_SH|fcntl.LOCK_NB)
                except BlockingIOError:
                    maintenance.close();state['tasks'][name]=dict(status='WAITING_MAINTENANCE');continue
                try:
                    deploy=read(D/'latest-deployment.json',{})
                    card=next((x for x in deploy.get('completed_cards',[]) if x['bdf']==BDF),{})
                    if deploy.get('host_boot_id')!=boot or card.get('configuration')!=cfg:
                        state.update(status='WAITING_MATCHING_DEPLOYMENT');save(output,state)
                        if cfg=='Native':return
                        continue
                    did_work=True
                    common=['--bdf',BDF]
                    for key,path in receipts.items():common+=['--'+key+'-receipt',str(path)]
                    state['tasks'][name]=dict(status='RUNNING',receipts={k:str(v) for k,v in receipts.items()});save(output,state)
                    ok=True
                    sizes=['test','simsmall'] if any(c['input']=='test' and c['program']==name for c in apps['cases']) else ['simsmall']
                    for size in sizes:
                        if existing(name,size,False,receipts):continue
                        rc=run(name+'-'+size,['python3',W/'scripts/run_isolated_sample.py',cfg,name,size,'--timeout','7200',*common])
                        if rc!=0:ok=False;break
                    if ok and formal_eligible:
                        rc=run(name+'-formal3',['python3',W/'scripts/run_repetitions.py',cfg,'--program',name,'--input','simmedium','--repetitions','3','--timeout','14400',*common])
                        ok=rc==0
                    state['tasks'][name].update(status=('COMPLETE' if formal_eligible else 'FUNCTIONAL_ONLY') if ok else 'FAILED',ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
                    save(output,state)
                    run(name+'-summary',['python3',W/'scripts/summarize_results.py'])
                    run(name+'-publish',['python3',W/'scripts/publish_live.py'])
                finally:maintenance.close()
            state.update(status='WAITING_REMAINING_SOFTWARE',heartbeat_utc=dt.datetime.now(dt.timezone.utc).isoformat())
            save(output,state)
            if not did_work:time.sleep(300)
    except Exception as exc:
        state.update(status='STOPPED_ON_CONCRETE_FAILURE',error=repr(exc));raise
    finally:save(output,state)


if __name__=='__main__':main()
