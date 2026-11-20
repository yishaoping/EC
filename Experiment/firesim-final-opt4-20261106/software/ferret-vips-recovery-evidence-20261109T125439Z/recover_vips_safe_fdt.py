#!/usr/bin/env python3
"""Firmware-only Vips repair; bind future queue item after real boot integrity."""
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import subprocess
import sys
from board_batch import W, D, save, sha
from job_service import proc

R = D/'software/vips-safe-fdt-recovery.json'


def main():
    lock=(D/'software/vips-safe-fdt-recovery.lock').open('a')
    fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    st=json.loads(R.read_text()) if R.exists() else dict(status='PREPARING',commands=[])
    if st['status']=='BOUND_FOR_EXISTING_QUEUE':return
    st.update(pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    logs=Path(st.setdefault('log_dir',str(D/'software'/('vips-safe-fdt-recovery-'+stamp))))
    logs.mkdir(exist_ok=True);save(R,st)
    def run(label,argv):
        with (logs/(label+'.log')).open('ab',buffering=0) as stream:
            child=subprocess.Popen(list(map(str,argv)),stdout=stream,stderr=subprocess.STDOUT,stdin=subprocess.DEVNULL,start_new_session=True)
            st.update(status='RUNNING',stage=label,child_pid=child.pid,child_start_ticks=proc(child.pid)['start_ticks']);save(R,st)
            rc=child.wait(timeout=1800);os.fsync(stream.fileno())
        st.pop('child_pid',None);st.pop('child_start_ticks',None)
        st['commands'].append(dict(label=label,argv=list(map(str,argv)),returncode=rc,log=str(logs/(label+'.log'))));save(R,st)
        assert rc==0,(label,rc)
    old=json.loads((W/'software/Native/vips-firmware-build.json').read_text())
    n=old['content_checks']['kernel']['bytes']
    st['original_layout']=dict(kernel_start=hex(0x80200000),kernel_end=hex(0x80200000+n),default_fdt_copy=hex(0x82200000),overlap=0x80200000<=0x82200000<0x80200000+n,
        symptom='Vips old guest panics before EC_GUEST_READY; preserve original evidence',root_cause_boundary='Default OpenSBI FDT destination lies within embedded kernel image. FPGA proof of repair still required.')
    save(R,st)
    run('firmware-only',[sys.executable,W/'scripts/prepare_safe_fdt_profile.py','vips'])
    run('qemu-boot-integrity',[sys.executable,W/'scripts/diagnose_dedup_boot.py','--profile','vips-safe-fdt','--bios-kind','firmware-jump'])
    diagnostic=D/'software/vips-safe-fdt-boot-diagnostic.json';q=json.loads(diagnostic.read_text())
    assert q['qemu_integrity_passed'] and q['qemu_guest_done'] and not q['kernel_panic'] and not q['timedout']
    for cfg in ['Native','C4']:
        fw=json.loads((W/f'software/{cfg}/vips-safe-fdt-firmware-build.json').read_text())
        assert fw['returncode']==0 and fw['content_checks']['runtime_memory_layout']['no_overlap']
    gate=(D/'locks/future-software-plan-update.lock').open('a');fcntl.flock(gate,fcntl.LOCK_EX)
    planpath=D/'suite-execution-plan.json';plan=json.loads(planpath.read_text())
    active=json.loads((D/'active-0000_21_00.0.json').read_text())
    assert not(active.get('program')=='vips' and active.get('status') in ['RUNNING','STARTING'])
    row=next(r for r in plan['programs'] if r['program']=='vips')
    assert row['software_profile_prefix'] in ['vips','vips-safe-fdt']
    before=sha(planpath)
    archive=D/'plan-history'/('before-vips-safe-fdt-'+stamp+'.json');save(archive,plan)
    row['software_profile_prefix']='vips-safe-fdt'
    save(planpath,plan)
    st.update(status='BOUND_FOR_EXISTING_QUEUE',ended_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
        qemu_boot_diagnostic=dict(path=str(diagnostic),sha256=sha(diagnostic)),old_plan_sha256=before,new_plan_sha256=sha(planpath),
        plan_archive=str(archive),hardware_modified=False,driver_modified=False,scheduler_modified=False,
        app_elf_input_roi_unchanged=True,bitstream_rebuild=False,fpga_validation='NOT_RUN',
        next_action='Existing coverage-first sees distinct safe-FDT firmware signature; run test/small/formal via its normal 21-only locks. C4 keeps priority when ready.')
    save(R,st)


if __name__=='__main__':main()
