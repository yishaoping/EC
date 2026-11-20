#!/usr/bin/env python3
"""Boundary handoff for the existing campaign; never replace a live sample.

The old controllers retain their active batches. Future tasks are explicitly
delegated in the plan. This service runs individual samples, first visiting all
available programs at repetition 1, then repetition 2, then repetition 3.
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

from board_batch import W, D, save, sha
from job_service import proc

BDF = '0000:21:00.0'
COMMIT = '8491167d84b6d9521b151a743673c1516926a1f8'
SOURCE = 'c9f51d3a94aac7783c750682162cd25e9d1460b04974bde9b7541f1d9f4120e7'
OUTPUT = D / 'coverage-first-state.json'
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
TERMINAL_FIRST = {'C4_INITIAL_BATCH_COMPLETE', 'C4_INITIAL_BATCH_FINISHED_WITH_FAILURES',
                  'STOPPED_ON_CONCRETE_FAILURE', 'INTERRUPTED'}
_hash_cache = {}


def now():
    return dt.datetime.now(dt.timezone.utc).isoformat()


def read(path, default=None):
    return json.loads(Path(path).read_text()) if Path(path).exists() else default


def digest(path):
    path = Path(path)
    st = path.stat()
    key = (str(path), st.st_ino, st.st_size, st.st_mtime_ns)
    if key not in _hash_cache:
        _hash_cache[key] = sha(path)
    return _hash_cache[key]


def live(state):
    """Unknown identities are busy; unreadable processes never authorize work."""
    if state.get('host_boot_id') not in [None, BOOT]:
        return False
    for pkey, tkey in [('pid', 'start_ticks'), ('child_pid', 'child_start_ticks')]:
        pid = state.get(pkey)
        if not pid:
            continue
        try:
            p = proc(pid)
        except PermissionError:
            return True
        if p and p['process_state'] not in ['Z', 'X']:
            if state.get(tkey) is None or str(state[tkey]) == p['start_ticks']:
                return True
    return False


def sample_busy():
    active = read(D / 'active-0000_21_00.0.json', {})
    if live(active):
        return True
    # A stale RUNNING record with a live owning runner must also be adopted.
    if active.get('status') in ['RUNNING', 'STARTING'] and active.get('host_boot_id') == BOOT:
        state = read(Path(active['run_dir']) / 'state.json', {})
        if live(state):
            return True
    return False


def catalog():
    plan = read(D / 'suite-execution-plan.json')
    rows = []
    for task in plan['programs']:
        name, profile = task['program'], task['software_profile_prefix']
        for cfg in ['Native', 'C4']:
            paths = dict(apps=W/f'software/{profile}-apps-build.json',
                         rootfs=W/f'software/{profile}-rootfs-build.json',
                         firmware=W/f'software/{cfg}/{profile}-firmware-build.json',
                         driver=W/f'runtime/{cfg}-efficiency-driver.json')
            if cfg in task.get('driver_receipts', {}):
                paths['driver'] = Path(task['driver_receipts'][cfg])
            row = dict(program=name, configuration=cfg, profile=profile,
                       receipts={k: str(p) for k, p in paths.items()})
            missing = [str(p) for p in paths.values() if not p.exists()]
            if missing:
                row.update(status='BLOCKED_SOFTWARE', missing=missing)
                rows.append(row)
                continue
            apps, rootfs, fw, driver = (read(paths[k]) for k in ['apps', 'rootfs', 'firmware', 'driver'])
            if cfg == 'C4' and apps.get('c4_incompatible_reason'):
                row.update(status='BLOCKED_ROI_PROTOCOL', reason=apps['c4_incompatible_reason'])
                rows.append(row)
                continue
            dtpath = next(Path(p) for p in fw['input_files'] if p.endswith('.json') and 'fdt' in Path(p).name)
            fdt = read(dtpath)
            if fdt['sha256'] != fw['content_checks']['fdt']['sha256']:
                fdt = read(Path(fw['content_checks']['fdt']['path']).parent/'manifest.json')
            bound = dict(configuration=cfg, board_bdf=BDF, program=name,
                         hardware_source_id=driver['hardware_source_id'],
                         apps_manifest_sha256=digest(paths['apps']),
                         rootfs_sha256=rootfs['sha256'], elf_sha256=apps['binaries'][name]['sha256'],
                         firmware_receipt_sha256=digest(paths['firmware']),
                         driver_receipt_sha256=digest(paths['driver']),
                         driver_sha256=driver['outputs'][str(Path(driver['output_dir'])/'FireSim-xilinx_alveo_u280')],
                         linux_bootargs=fdt['bootargs'], linux_memory_cap_bytes=fdt['linux_mem_cap'])
            if cfg == 'C4':
                assert bound['hardware_source_id'] == SOURCE
                bound['hardware_commit'] = COMMIT
            row.update(status='READY', bound=bound,
                       signature=hashlib.sha256(json.dumps(bound, sort_keys=True).encode()).hexdigest(),
                       inputs=[c['input'] for c in apps['cases'] if c['program'] == name],
                       formal_eligible=apps.get('formal_eligible', True))
            row['accepted_driver_bindings'] = []
            for altpath in task.get('reusable_driver_receipts', {}).get(cfg, []):
                alt = read(altpath)
                exe = Path(alt['output_dir'])/'FireSim-xilinx_alveo_u280'
                assert alt['returncode'] == 0 and alt['hardware_rtl_unchanged']
                assert alt['hardware_source_id'] == driver['hardware_source_id']
                assert digest(exe) == alt['outputs'][str(exe)]
                assert digest(alt['patch']) == alt['patch_sha256']
                row['accepted_driver_bindings'].append(dict(
                    driver_receipt_sha256=digest(altpath), driver_sha256=digest(exe)))
            rows.append(row)
    return rows


def results():
    found = []
    for path in sorted((D/'runs').glob('*/result.json')):
        r = read(path)
        c = read(path.parent/'complete.json', {})
        if (r.get('valid') and c.get('result_sha256') == digest(path)
                and c.get('identity_sha256') == r.get('identity_sha256')):
            found.append((path, r))
    return found


def matches(row, valid, size, repetition=1):
    driver_keys = {'driver_receipt_sha256', 'driver_sha256'}
    # Preserve exact valid historical e2 samples; never change their identity.
    # New execution and hardware smoke are strictly pinned to 21.
    board_pairs={('0000:21:00.0','21770433G02LA'),('0000:e2:00.0','21770433G001A')}
    accepted = row.get('accepted_driver_bindings', []) + [
        {k: row['bound'][k] for k in driver_keys if k in row['bound']}]
    return [(p, r) for p, r in valid if r.get('formal') == (size == 'simmedium')
            and r['identity'].get('input') == size
            and (size != 'simmedium' or r['identity'].get('repetition') == repetition)
            and all(r['identity'].get(k) == v for k, v in row['bound'].items() if k not in driver_keys | {'board_bdf'})
            and (r['identity'].get('board_bdf'),r['identity'].get('board_serial')) in board_pairs
            and any(all(r['identity'].get(k) == v for k,v in d.items()) for d in accepted)]


def smoke_valid(row, valid):
    keys = ['configuration', 'board_bdf', 'hardware_source_id', 'driver_sha256',
            'linux_bootargs', 'linux_memory_cap_bytes']
    return any(r['identity'].get('program') == 'smoke' and not r.get('formal')
               and all(r['identity'].get(k) == row['bound'][k] for k in keys)
               for _, r in valid)


def old_boundary(cfg):
    if sample_busy():
        return False, 'WAITING_ACTIVE_SAMPLE'
    q = read(D/f'suite-{cfg.lower()}-queue-state.json', {})
    if q.get('host_boot_id') != BOOT:
        return False, 'WAITING_CURRENT_BOOT_LEGACY_RECONCILIATION'
    if q.get('host_boot_id') == BOOT and q.get('status') not in [
            'WAITING_REMAINING_SOFTWARE', 'YIELDING_TO_READY_C4_BITSTREAM',
            'WAITING_MATCHING_DEPLOYMENT', 'STOPPED_ON_CONCRETE_FAILURE', 'INTERRUPTED',
            'WAITING_EXISTING_PRIORITY_QUEUE']:
        return False, 'WAITING_LEGACY_QUEUE_BOUNDARY'
    if q.get('child_pid') and live(dict(host_boot_id=q.get('host_boot_id'),
                                      child_pid=q['child_pid'], child_start_ticks=q.get('child_start_ticks'))):
        return False, 'WAITING_LEGACY_CHILD'
    cad = read(D/'C4-runtime-cad-state.json', {})
    first = read(D/'fpga-continuation-state.json', {})
    if cfg == 'C4':
        if first.get('host_boot_id') != BOOT:
            return False, 'WAITING_CURRENT_BOOT_C4_INITIAL_VALIDATOR'
        gate = read(D/'c4-canneal-continuation-state.json', {})
        if gate.get('status') != 'DELEGATED_TO_COVERAGE_FIRST_SERVICE':
            return False, 'WAITING_EXCLUSIVE_FUTURE_TASK_OWNERSHIP'
        if first.get('status') not in TERMINAL_FIRST:
            return False, 'WAITING_C4_FIRST_DEPLOYMENT_AND_GATES'
        if cad.get('status') != 'BUILT_NOT_RUN' or not cad.get('certified_bitstream'):
            return False, 'WAITING_EXACT_C4_BITSTREAM'
    elif cad.get('status') == 'BUILT_NOT_RUN':
        if first.get('status') not in TERMINAL_FIRST:
            return False, 'YIELDING_TO_C4_FIRST_DEPLOYMENT'
        # The old repair waiters explicitly refuse to start once CAD is ready.
        # Require their child identities to be gone before taking their backlog.
        for n in ['idle-repairs-state.json', 'fluidanimate-stable-native-state.json']:
            s = read(D/n, {})
            if s.get('status') == 'RUNNING' or (s.get('child_pid') and live(dict(
                    host_boot_id=s.get('host_boot_id'), child_pid=s['child_pid'],
                    child_start_ticks=s.get('child_start_ticks')))):
                return False, 'WAITING_LEGACY_REPAIR_BATCH'
    else:
        repair = read(D/'idle-repairs-state.json', {})
        fluid = read(D/'fluidanimate-stable-native-state.json', {})
        if repair.get('status') not in ['TARGETED_REPAIRS_FINISHED_REVIEW_EVIDENCE', 'FAILED_WITH_EVIDENCE']:
            return False, 'WAITING_EXISTING_DEDUP_REPAIR'
        if fluid.get('status') not in ['COMPLETE', 'FAILED_WITH_EVIDENCE']:
            return False, 'WAITING_EXISTING_FLUIDANIMATE_REPAIR'
    return True, 'SAFE_TASK_BOUNDARY'


def next_jobs(rows, valid, failures, cfg, repetition):
    jobs = []
    for row in rows:
        if row['configuration'] != cfg or row['status'] != 'READY':
            continue
        if not row['formal_eligible'] or matches(row, valid, 'simmedium', repetition):
            continue
        if repetition > 1 and not matches(row, valid, 'simmedium', 1):
            continue
        for size in ['test', 'simsmall', 'simmedium']:
            if size not in row['inputs']:
                continue
            rep = repetition if size == 'simmedium' else 1
            if matches(row, valid, size, rep):
                continue
            key = row['signature'] + ':' + size + ':' + str(rep)
            if key in failures:
                break
            if repetition > 1 and row['signature'] + ':simmedium:1' in failures:
                break
            jobs.append((row, size, rep, key))
            break
    return jobs


def choose_job(rows, valid, failures, boundaries):
    # Once C4 gates are ready, all runnable C4 work outranks Native network
    # work. Within a configuration, cover r1 before filling r2 and r3.
    for cfg in ['C4', 'Native']:
        if not boundaries[cfg][0]:
            continue
        for rep in [1, 2, 3]:
            for job in next_jobs(rows, valid, failures, cfg, rep):
                if smoke_valid(job[0], valid):
                    return job
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--inspect', action='store_true')
    args = ap.parse_args()
    if args.inspect:
        rows, valid = catalog(), results()
        priorities={t['program']:t.get('coverage_priority',100) for t in read(D/'suite-execution-plan.json')['programs']}
        rows.sort(key=lambda r: priorities[r['program']])
        print(json.dumps([dict(program=r['program'], configuration=r['configuration'],
            status=r['status'], formal=[n for n in [1,2,3] if r['status']=='READY'
            and matches(r,valid,'simmedium',n)]) for r in rows], indent=2))
        return
    assert os.geteuid() == 0
    lock = (D/'locks/coverage-first.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    previous = read(OUTPUT, {})
    # job_service identity gate must adopt any surviving child before here.
    assert not live(previous), 'adopt existing coordinator/child; never duplicate'
    state = dict(schema='ec-coverage-first/1', pid=os.getpid(), start_ticks=proc(os.getpid())['start_ticks'],
                 host_boot_id=BOOT, started_utc=now(), status='STARTING',
                 failures=previous.get('failures', {}), commands=previous.get('commands', []),
                 scheduling='ready C4 before Native; within each configuration cover r1 before r2/r3; failures remain explicit',
                 no_hardware_build=True, no_live_sample_changes=True)
    save(OUTPUT, state)

    def command(label, argv):
        logs = D/'coverage-first-logs';logs.mkdir(exist_ok=True)
        path = logs/(dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')+'-'+label+'.log')
        state.update(status='RUNNING', stage=label, log=str(path), argv=list(map(str,argv)))
        with path.open('ab',buffering=0) as log:
            child = subprocess.Popen(list(map(str,argv)),cwd=W,stdin=subprocess.DEVNULL,
                                     stdout=log,stderr=subprocess.STDOUT,start_new_session=True)
            state.update(child_pid=child.pid,child_start_ticks=proc(child.pid)['start_ticks'])
            save(OUTPUT,state)
            while child.poll() is None:
                try:child.wait(timeout=30)
                except subprocess.TimeoutExpired:pass
                state.update(updated_utc=now());save(OUTPUT,state);os.fsync(log.fileno())
        state.pop('child_pid',None);state.pop('child_start_ticks',None)
        record=dict(stage=label,returncode=child.returncode,log=str(path),ended_utc=now())
        state['commands'].append(record);save(OUTPUT,state)
        return record

    while True:
        assert Path('/proc/sys/kernel/random/boot_id').read_text().strip() == BOOT
        rows, valid = catalog(), results()
        state.update(updated_utc=now(), catalog=rows, plan_sha256=digest(D/'suite-execution-plan.json'))
        boundaries={c:old_boundary(c) for c in ['Native','C4']}
        state['boundaries']={c:dict(ready=b[0],reason=b[1]) for c,b in boundaries.items()}
        deployment=read(D/'latest-deployment.json',{})
        card=next((c for c in deployment.get('completed_cards',[]) if c['bdf']==BDF),{})
        current=card.get('configuration') if deployment.get('host_boot_id')==BOOT else None
        choice=choose_job(rows, valid, state['failures'], boundaries)
        if choice is None:
            state.update(status='WAITING_DEPENDENCY_OR_COMPLETE',stage=None)
            state['all_formal_complete']=all(r['status']=='READY' and all(
                matches(r,valid,'simmedium',n) for n in [1,2,3]) for r in rows)
            save(OUTPUT,state)
            if state['all_formal_complete']:return
            time.sleep(300);continue
        row,size,rep,key=choice;cfg=row['configuration']
        state['next_sample']=dict(configuration=cfg,program=row['program'],input=size,repetition=rep)
        if not smoke_valid(row,valid):
            state.update(status='BLOCKED_MATCHING_SMOKE',stage=cfg)
            save(OUTPUT,state)
            # Existing initial validators provide smoke; do not invent a pass.
            time.sleep(300);continue
        if current != cfg:
            rec=command(cfg+'-reuse-bitstream-deploy',['python3',W/'scripts/board_batch.py',
                '--deploy-only','--single-'+('c4' if cfg=='C4' else 'native')+'-bdf',BDF])
            if rec['returncode']:
                state.update(status='BLOCKED_DEPLOYMENT',deployment_error=rec)
                save(OUTPUT,state);time.sleep(300)
            continue
        # C4 failures can consume a deployment. Recover on the SAME certified
        # image before the next program, under board_batch's exclusive lock.
        consumed=read(D/'consumed-0000_21_00.0.json',{})
        generation=deployment.get('started_utc','')+'|'+BDF+'|'+card.get('bitstream_sha256','')
        reset_probe = False
        if cfg=='C4' and consumed.get('deployment_generation')==generation:
            prior=read(Path(consumed['run_dir'])/'result.json',{})
            driver=read(Path(row['receipts']['driver']))
            reset=prior.get('target_reset_validation') or consumed.get('target_reset_validation',{})
            if not prior.get('valid'):
                rec=command('C4-recover-consumed-deployment',['python3',W/'scripts/board_batch.py',
                    '--deploy-only','--single-c4-bdf',BDF])
                if rec['returncode']:
                    state.update(status='BLOCKED_DEPLOYMENT',deployment_error=rec);save(OUTPUT,state);time.sleep(300)
                continue
            reset_probe = not driver.get('supports_target_restart') and reset.get('status')!='VALIDATED'
        argv=['python3',W/'scripts/run_isolated_sample.py',cfg,row['program'],size,'--bdf',BDF,
              '--repetition',str(rep),'--timeout',str(14400 if size=='simmedium' else 7200)]
        for k,p in row['receipts'].items():argv+=['--'+k+'-receipt',p]
        if size=='simmedium':argv+=['--formal']
        if reset_probe:argv+=['--target-reset-probe']
        state['active_key']=key;save(OUTPUT,state)
        rec=command(cfg+'-'+row['program']+'-'+size+'-r'+str(rep),argv)
        # A zero process exit alone never commits success.
        after=results();committed=matches(row,after,size,rep)
        if rec['returncode'] or not committed:
            active=read(D/'active-0000_21_00.0.json',{})
            state['failures'][key]=dict(**rec,program=row['program'],configuration=cfg,
                input=size,repetition=rep,profile=row['profile'],run_dir=active.get('run_dir'),
                reason='nonzero runner exit or missing exact atomic completion')
        state.pop('active_key',None);save(OUTPUT,state)
        for script in ['summarize_results.py','publish_live.py']:
            command(script[:-3],['python3',W/'scripts'/script])


if __name__ == '__main__':
    main()
