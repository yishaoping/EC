import sys
from pathlib import Path as _BundlePath
sys.path.insert(0, str(_BundlePath(__file__).resolve().parent))
sys.path.insert(1, '/data1/gzh/EC/firesim/final-opt4-20261106/scripts')
#!/usr/bin/env python3
"""Derived C4 certification -> 21-only safe boundary -> strict gates -> PARSEC.

Original Native coordinator stays alive; shared card/maintenance locks and a
certified priority marker reserve future launches only, never a live sample.
"""
import argparse
import datetime as dt
import fcntl
import hashlib
import json
import os
from pathlib import Path
import subprocess
import time

from board_batch import W,D,save,sha
from job_service import boot,proc
from opt4_fit_runtime_guard import (COMMIT,SOURCE,PROFILE,BDF,SERIAL,CERT,SUITE,
    PRIORITY,artifact,software_paths,complete,read)

STATE=D/'Opt4-fit-group4-runtime-state.json'
LOGS=D/'Opt4-fit-group4-runtime-logs'
now=lambda:dt.datetime.now(dt.timezone.utc).isoformat()


def row_key(row):
    return hashlib.sha256(json.dumps(dict(program=row['program'],receipts=row['receipt_sha256'],
        commit=COMMIT,source_id=SOURCE),sort_keys=True).encode()).hexdigest()


def task_key(row,size,rep,program=None):
    return row_key(row)+':'+(program or row['program'])+':'+size+':'+str(rep)


def committed(row,records,size,rep,program=None,bitsha=None):
    name=program or row['program']
    return [(p,r) for p,r in records if r.get('formal')==(size=='simmedium')
        and r['identity'].get('configuration')=='C4'
        and r['identity'].get('hardware_commit')==COMMIT
        and r['identity'].get('hardware_source_id')==SOURCE
        and r['identity'].get('hardware_profile')==PROFILE
        and r['identity'].get('board_bdf')==BDF and r['identity'].get('board_serial')==SERIAL
        and r['identity'].get('program')==name and r['identity'].get('input')==size
        and r['identity'].get('repetition')==rep
        and r['identity'].get('threads')==1 and r['identity'].get('warmups')==0
        and r['identity'].get('bitstream_sha256')==bitsha
        and r['identity'].get('rootfs_sha256')==row['rootfs_sha256']
        and (name=='smoke' or r['identity'].get('elf_sha256')==row['elf_sha256'])
        and all(r['identity'].get(k)==v for k,v in dict(
            apps_manifest_sha256=row['receipt_sha256']['apps'],
            firmware_receipt_sha256=row['receipt_sha256']['firmware'],
            driver_receipt_sha256=row['receipt_sha256']['driver']).items())]


def next_task(suite,records,failures,bitsha):
    # Hardware smoke is mandatory. Failed hardware smoke stops all work;
    # application failures below skip only that software profile/stage.
    first=suite['programs'][0]
    if not committed(first,records,'test',1,'smoke',bitsha):
        key=task_key(first,'test',1,'smoke')
        return None if key in failures else (first,'smoke','test',1,key)
    for rep in [1,2,3]:
        for row in suite['programs']:
            if committed(row,records,'simmedium',rep,bitsha=bitsha):continue
            for size in ['test','simsmall','simmedium']:
                if size not in row['input_sizes']:continue
                n=rep if size=='simmedium' else 1
                if committed(row,records,size,n,bitsha=bitsha):continue
                key=task_key(row,size,n)
                if key in failures:break
                if rep>1 and not committed(row,records,'simmedium',1,bitsha=bitsha):break
                return row,row['program'],size,n,key
    return None


def records():
    found=[]
    for p in sorted((D/'runs').glob('opt4-fit-981b890d-*/result.json')):
        r=complete(p)
        if r:found.append((p,r))
    return found


def sample_argv(row,program,size,rep,probe=False):
    args=['python3',str(Path(__file__).resolve().parent/'run_isolated_sample.py'),'C4',program,size,
        '--bdf',BDF,'--repetition',str(rep),'--timeout',str(14400 if size=='simmedium' else 7200),
        '--opt4-fit-receipt',str(CERT)]
    for k,p in row['receipts'].items():args+=['--'+k+'-receipt',p]
    if size=='simmedium':args+=['--formal']
    if probe:args+=['--target-reset-probe']
    return args


def deploy_argv():
    return ['python3',str(Path(__file__).resolve().parent/'board_batch.py'),'--deploy-only',
        '--single-c4-bdf',BDF,'--opt4-fit-receipt',str(CERT)]


def main():
    ap=argparse.ArgumentParser();ap.add_argument('--inspect',action='store_true');a=ap.parse_args()
    suite=read(SUITE)
    assert suite['hardware_commit']==COMMIT and suite['source_id']==SOURCE
    assert suite['program_count']==len(suite['programs'])==13
    if a.inspect:
        s=read(D/'Opt4-fit-group4-cad-state.json')
        print(json.dumps(dict(cad_status=s['status'],programs=[r['program'] for r in suite['programs']],
            deploy_argv=deploy_argv(),first_sample_argv=sample_argv(suite['programs'][0],'smoke','test',1),
            fpga_access=False)));return
    assert os.geteuid()==0
    lock=(D/'locks/opt4-fit-runtime.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    LOGS.mkdir(exist_ok=True)
    previous=read(STATE) if STATE.exists() else {}
    if previous:
        from coverage_first import live
        assert not live(previous),'adopt existing controller/child rather than duplicate'
        save(LOGS/('before-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')+'.json'),previous)
    st=dict(schema='ec-opt4-fit-runtime/1',pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],
        host_boot_id=boot(),started_utc=now(),status='WAITING_FOR_DERIVED_BITSTREAM',
        hardware_commit=COMMIT,source_id=SOURCE,hardware_profile=PROFILE,board_bdf=BDF,board_serial=SERIAL,
        software_suite_sha256=sha(SUITE),failures=previous.get('failures',{}),commands=previous.get('commands',[]),
        scheduling='Opt4-fit priority; formal r1 coverage before r2/r3; app failure skips; exact complete hashes reused',
        checkpoint_policy='complete samples and stage receipts; no instruction checkpoint',certified_bitstream=False)
    save(STATE,st)

    def update(**values):st.update(**values,updated_utc=now());save(STATE,st)
    def command(label,argv):
        log=LOGS/(dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')+'-'+label+'.log')
        update(status='RUNNING',stage=label,log=str(log),argv=list(map(str,argv)))
        with log.open('ab',buffering=0) as f:
            child=subprocess.Popen(list(map(str,argv)),cwd=W,stdin=subprocess.DEVNULL,
                stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
            update(child_pid=child.pid,child_start_ticks=proc(child.pid)['start_ticks'])
            while child.poll() is None:
                try:child.wait(timeout=30)
                except subprocess.TimeoutExpired:pass
                update();os.fsync(f.fileno())
        st.pop('child_pid',None);st.pop('child_start_ticks',None)
        item=dict(stage=label,returncode=child.returncode,log=str(log),ended_utc=now())
        st['commands'].append(item);update();return item

    # No FPGA maintenance locks, priority reservation or deployment before a
    # real CAD success. Preserve Native progress throughout the wait.
    from prepare_opt4_fit_runtime import certify
    while not CERT.exists():
        cad=read(D/'Opt4-fit-group4-cad-state.json')
        update(status='WAITING_FOR_DERIVED_BITSTREAM',cad_status=cad.get('status'),cad_stage=cad.get('current_stage'))
        if cad.get('status')=='BUILT_TIMING_DRC_PASSED_NOT_RUNTIME_VALIDATED':
            certify();break
        time.sleep(300)
    cert=artifact(CERT);bitsha=cert['durable_bitstream_sha256']
    assert sha(SUITE)==st['software_suite_sha256'],'immutable prepared suite changed'
    for row in suite['programs']:software_paths(row)
    priority=dict(schema='ec-derived-fpga-priority/1',status='REQUESTED_AT_SAFE_BOUNDARY',
        hardware_commit=COMMIT,source_id=SOURCE,board_bdf=BDF,board_serial=SERIAL,
        certificate_sha256=sha(CERT),software_suite_sha256=sha(SUITE),requested_utc=now())
    save(PRIORITY,priority);update(certified_bitstream=True,bitstream_sha256=bitsha)

    from coverage_first import sample_busy
    while True:
        current=records();task=next_task(suite,current,st['failures'],bitsha)
        matrix={r['program']:[rep for rep in [1,2,3] if committed(r,current,'simmedium',rep,bitsha=bitsha)] for r in suite['programs']}
        update(valid_formal_samples=sum(map(len,matrix.values())),matrix=matrix)
        if task is None:
            status='COMPLETE_39_FORMAL_SAMPLES' if all(len(v)==3 for v in matrix.values()) else 'RUNNABLE_BATCH_EXHAUSTED_FAILURES_RETAINED'
            priority.update(status='YIELDED_NO_RUNNABLE_DERIVED_TASKS',updated_utc=now());save(PRIORITY,priority)
            update(status=status,ended_utc=now());return
        row,program,size,rep,key=task
        update(next_sample=dict(program=program,input=size,repetition=rep),active_key=key)
        if sample_busy():
            update(status='WAITING_21_SAFE_TASK_BOUNDARY');time.sleep(60);continue
        # Maintenance/card locks in deployed tools close races after this
        # observation. A surviving unknown owner causes no operation.
        dep=read(D/'latest-deployment.json') if (D/'latest-deployment.json').exists() else {}
        card=next((c for c in dep.get('completed_cards',[]) if c['bdf']==BDF),{})
        matching=(dep.get('host_boot_id')==boot() and dep.get('status')=='DEPLOYED_NOT_RUN'
            and card.get('hardware_commit')==COMMIT and card.get('hardware_profile')==PROFILE
            and card.get('bitstream_sha256')==bitsha and card.get('derived_build_receipt_sha256')==sha(CERT))
        probe=False
        if matching:
            generation=dep['started_utc']+'|'+BDF+'|'+bitsha
            consumed=read(D/'consumed-0000_21_00.0.json') if (D/'consumed-0000_21_00.0.json').exists() else {}
            if consumed.get('deployment_generation')==generation:
                prior=complete(Path(consumed['run_dir'])/'result.json')
                if not prior or not prior.get('guest_power_down_observed'):matching=False
                else:
                    reset=prior.get('target_reset_validation') or consumed.get('target_reset_validation',{})
                    probe=not read(row['receipts']['driver']).get('supports_target_restart') and reset.get('status')!='VALIDATED'
        if not matching:
            rec=command('deploy-21-derived',deploy_argv())
            if rec['returncode']:
                update(status='BLOCKED_21_DEPLOYMENT',deployment_failure=rec)
                time.sleep(300)
            continue
        priority.update(status='ACTIVE',updated_utc=now());save(PRIORITY,priority)
        before=read(D/'active-0000_21_00.0.json') if (D/'active-0000_21_00.0.json').exists() else {}
        rec=command(program+'-'+size+'-r'+str(rep),sample_argv(row,program,size,rep,probe))
        after=read(D/'active-0000_21_00.0.json')
        good=committed(row,records(),size,rep,program,bitsha)
        if not good:
            # One guarded reset-probe failure may be host bridge reuse only.
            # Retain it, retry once on a fresh copy of the SAME certified image.
            reset_retry_key=key+':fresh-reset-retry'
            if probe and reset_retry_key not in st['failures']:
                st['failures'][reset_retry_key]=dict(**rec,reason='reset probe failed; retry same input once after fresh deployment')
                update();rec=command('fresh-reset-retry-deploy',deploy_argv())
                if rec['returncode']==0:
                    rec=command(program+'-'+size+'-fresh-retry',sample_argv(row,program,size,rep))
                    after=read(D/'active-0000_21_00.0.json');good=committed(row,records(),size,rep,program,bitsha)
            if not good:
                st['failures'][key]=dict(**rec,program=program,input=size,repetition=rep,
                    run_dir=after.get('run_dir') if after.get('run_id')!=before.get('run_id') else None,
                    reason='no exact valid atomic result; process exit alone is insufficient')
        st.pop('active_key',None);update()
        # Never let a reporting error destroy committed experiments.
        for script in ['summarize_results.py','publish_live.py']:
            command(script[:-3],['python3',str(W/'scripts'/script)])


if __name__=='__main__':
    try:main()
    except Exception as exc:
        if STATE.exists():
            s=read(STATE);s.update(status='FAILED_WITH_EVIDENCE_NO_ACTIVE_TASK_TERMINATED',error=repr(exc),ended_utc=now());save(STATE,s)
        raise
