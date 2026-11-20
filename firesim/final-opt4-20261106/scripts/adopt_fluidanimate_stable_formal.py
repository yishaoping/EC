#!/usr/bin/env python3
"""Apply the explicit software-fix authorization to a new, immutable profile."""
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import shutil
import subprocess
from board_batch import W,D,save,sha

PROFILE='fluidanimate-stable-formal'
OUTPUT=D/'software/fluidanimate-stable-formal-adoption.json'


def read(p):return json.loads(p.read_text()) if p.exists() else {}


def main():
    assert os.geteuid()==0
    lock=(D/'locks/fluidanimate-stable-formal-adoption.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    old=read(OUTPUT)
    if old.get('status')=='BOUND_FOR_BOTH_CONFIGURATIONS':return
    candidate=W/'software/fluidanimate-stable-candidate-apps-build.json'
    apps=read(candidate);parent=read(W/'software/fluidanimate-apps-build.json')
    proof=read(D/'software/fluidanimate-stable-order-candidate.json')
    prep=read(D/'software/fluidanimate-stable-candidate-preparation.json')
    assert prep['status']=='READY_UNBOUND_PENDING_DECISION'
    assert sha(candidate)==prep['apps_receipt_sha256']
    assert proof['cross_environment_output_exact'] and proof['user_in_radius_omissions']==proof['linux_in_radius_omissions']==0
    source=Path(apps['output_dir'])/'src/fluidanimate'
    original=Path(parent['output_dir'])/'src/fluidanimate'
    condition='if(&neigh->p[iparNeigh % PARTICLES_PER_CELL] < &cell->p[ipar % PARTICLES_PER_CELL])'
    fixed='if(cindexNeigh < cindex || (cindexNeigh == cindex && iparNeigh < ipar))'
    before=(original/'serial.cpp').read_text();assert before.count(condition)==2
    assert (source/'serial.cpp').read_text()==before.replace(condition,fixed)
    for name,digest in apps['sources'].items():
        assert sha(source/name)==digest
        if name!='serial.cpp':assert sha(original/name)==digest
    for c in apps['cases']:
        p=next(p for p in parent['cases'] if p['input']==c['input'])
        assert c['argv']==p['argv'] and c['input_files']==p['input_files'] and c['threads']==p['threads']==1 and c['warmups']==p['warmups']==0
        assert not c['diagnostic_roi_syscalls']
        for rel,digest in c['input_files'].items():assert sha(Path(apps['output_dir'])/'inputs/fluidanimate'/c['input']/rel)==digest
        assert sha(Path(apps['host_log_dir'])/('reference-'+c['input'])/'out.fluid')==c['reference_outputs']['out.fluid']
    elf=Path(apps['binaries']['fluidanimate']['path']);assert sha(elf)==prep['candidate_elf_sha256']==apps['binaries']['fluidanimate']['sha256']
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    evidence=D/'software'/('fluidanimate-stable-formal-adoption-'+stamp);evidence.mkdir()
    authorization=dict(source='explicit user reply in this conversation',received_date='2026-11-07',
        answer='允许修复 profile，两组重新验证和采样（推荐）',
        scope='Two stable pair-order predicates; clearly labelled repaired software; identical Native/frozen Opt4 ELF/input/original ROI; preserve original failures')
    save(evidence/'authorization.json',authorization)
    state=dict(schema='ec-authorized-software-profile-adoption/1',status='PREPARING',profile=PROFILE,
        user_authorization=authorization,evidence_dir=str(evidence),candidate_receipt=str(candidate),candidate_receipt_sha256=sha(candidate),
        candidate_elf=str(elf),candidate_elf_sha256=sha(elf),minimal_patch=proof['candidate_patch'],minimal_patch_sha256=sha(proof['candidate_patch']),
        original_receipts_preserved=True,original_failures_preserved=True,bitstream_rebuild=False,active_processes_modified=False,
        started_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    save(OUTPUT,state)
    formal=dict(apps)
    formal.update(software_profile='fluidanimate-stable-index-pairing-authorized-repair',formal_eligible=True,
        awaiting_explicit_software_semantics_decision=False,status='PREPARED_FPGA_NOT_RUN',fpga_validation='NOT_RUN',
        software_semantics_label='Authorized repair of original address-dependent omitted particle interactions; separate from original profile',
        user_authorization_receipt=str(evidence/'authorization.json'),user_authorization_sha256=sha(evidence/'authorization.json'),
        candidate_receipt=str(candidate),candidate_receipt_sha256=sha(candidate),
        formal_input_policy='Official simmedium, 1 thread, 5 frames, full original AdvanceFrame ROI; authorized stable index pair ordering; exact complete output hash; both configurations use identical ELF/input/rootfs')
    formal['cases']=[dict(c,software_reference='STABLE_PAIR_ORDER_RISCV_REFERENCE',software_semantics_label=formal['software_semantics_label']) for c in apps['cases']]
    receipt=W/f'software/{PROFILE}-apps-build.json'
    if receipt.exists():
        # Recover a prepared prior adoption without changing the embedded receipt.
        prior=read(receipt);assert prior['candidate_receipt_sha256']==sha(candidate) and prior['formal_eligible']
        formal=prior
    else:save(receipt,formal)
    log=evidence/'software-build.log'
    with log.open('wb',buffering=0) as f:
        subprocess.run(['python3',W/'scripts/prepare_profile_system.py',PROFILE],cwd=W,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,check=True)
        os.fsync(f.fileno())
    bindings={}
    for suffix in ['apps','rootfs']:
        p=W/f'software/{PROFILE}-{suffix}-build.json';bindings[str(p)]=sha(p)
    for cfg in ['Native','C4']:
        for suffix in ['kernel','firmware']:
            p=W/f'software/{cfg}/{PROFILE}-{suffix}-build.json';j=read(p);assert j['returncode']==0
            bindings[str(p)]=sha(p)
    # This changes only the future, failed Fluidanimate task. The live queue and
    # all live sample arguments, receipts and filesystem inputs are left alone.
    planpath=D/'suite-execution-plan.json'
    planlock=(D/'locks/future-suite-plan.lock').open('a');fcntl.flock(planlock,fcntl.LOCK_EX)
    plan=read(planpath);active=read(D/'active-0000_e2_00.0.json');q=read(D/'suite-native-queue-state.json')
    assert active.get('program')!='fluidanimate' or active.get('status') not in ['RUNNING','STARTING']
    assert q.get('tasks',{}).get('fluidanimate',{}).get('status') in ['FAILED','COMPLETE','FUNCTIONAL_ONLY',None]
    task=next(t for t in plan['programs'] if t['program']=='fluidanimate')
    assert task['software_profile_prefix'] in ['fluidanimate',PROFILE]
    history=D/'plan-history';history.mkdir(exist_ok=True)
    archived=history/('before-fluidanimate-stable-formal-'+stamp+'.json');save(archived,plan)
    oldhash=sha(planpath)
    task.update(software_profile_prefix=PROFILE,
        managed_by_existing_queue=sorted(set(task.get('managed_by_existing_queue',[])+['Native'])),
        native_owner='ec-parsec-fluidanimate-stable-native.service',user_authorization_receipt=str(evidence/'authorization.json'),
        software_semantics_label=formal['software_semantics_label'])
    save(planpath,plan)
    state.update(status='BOUND_FOR_BOTH_CONFIGURATIONS',apps_receipt=str(receipt),apps_receipt_sha256=sha(receipt),
        bindings=bindings,plan_before=str(archived),plan_old_sha256=oldhash,plan_new_sha256=sha(planpath),
        native_owner=task['native_owner'],c4_owner='ec-parsec-c4-suite.service',
        observed_unchanged_active_run=active.get('run_dir'),completed_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
        runtime_validation='NOT_RUN',native_retry_policy='Wait existing native queue and idle-repairs; reuse deployment; functional gates then missing formal repeats only')
    save(OUTPUT,state);save(evidence/'receipt.json',state)
    print(json.dumps(state),flush=True)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        state=read(OUTPUT);state.update(status='FAILED_WITH_EVIDENCE',error=repr(exc));save(OUTPUT,state);raise
