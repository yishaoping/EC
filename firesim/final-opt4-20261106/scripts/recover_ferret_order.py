#!/usr/bin/env python3
"""Diagnose exact serial Ferret output in Linux before a versioned order repair."""
import base64
import copy
import datetime as dt
import difflib
import fcntl
import json
import os
from pathlib import Path
import re
import shlex
import shutil
import signal
import subprocess
import sys
import time
from board_batch import W, D, save, sha
from job_service import proc
sys.path.insert(0, '/data1/gzh/EC/firesim/dac2026/scripts')
from prepare_boot_prerequisite import cpio_newc

R = D/'software/ferret-order-recovery.json'
PROFILE = 'ferret-stable-order'


def main():
    lock=(D/'software/ferret-order-recovery.lock').open('a')
    fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    st=json.loads(R.read_text()) if R.exists() else dict(status='PREPARING',commands=[],cases={})
    if st['status']=='BOUND_FOR_EXISTING_QUEUE': return
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    logs=Path(st.setdefault('log_dir',str(D/'software'/('ferret-order-recovery-'+stamp))))
    out=Path(st.setdefault('output_dir',str(W/'software'/('ferret-stable-order-'+stamp))))
    logs.mkdir(exist_ok=True);out.mkdir(exist_ok=True)
    st.update(pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
        hardware_modified=False,driver_modified=False,scheduler_modified=False,fpga_validation='NOT_RUN')
    save(R,st)
    oldpath=W/'software/ferret-apps-build.json'; old=json.loads(oldpath.read_text()); oldout=Path(old['output_dir'])
    prior=json.loads((D/'software/fluidanimate-stable-order-candidate.json').read_text())['argv']
    kernel=Path(prior[prior.index('-kernel')+1]); qemu=Path(prior[0])
    busybox=Path('/data1/gzh/EC/firesim/dac2026/images/software-v3/B-boot-20261102T083720.765499Z/rootfs/bin/busybox')
    st['bindings']=dict(parent_receipt=str(oldpath),parent_receipt_sha256=sha(oldpath),diagnostic_elf_sha256=sha(oldout/'ferret-diagnostic'),
        kernel=dict(path=str(kernel),sha256=sha(kernel)),qemu=dict(path=str(qemu),sha256=sha(qemu)))
    save(R,st)

    def run(label,argv,cwd=None,timeout=1800,expected=(0,)):
        log=logs/(label+'.log'); started=time.monotonic()
        with log.open('ab',buffering=0) as stream:
            child=subprocess.Popen(['nice','-n','15',*map(str,argv)],cwd=cwd,stdin=subprocess.DEVNULL,stdout=stream,stderr=subprocess.STDOUT,start_new_session=True,
                env={**os.environ,'PATH':'/usr/bin:/bin','LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'1'})
            st.update(status='RUNNING',stage=label,child_pid=child.pid,child_start_ticks=proc(child.pid)['start_ticks']);save(R,st)
            try:rc=child.wait(timeout=timeout)
            except subprocess.TimeoutExpired:
                os.killpg(child.pid,signal.SIGTERM);child.wait(timeout=15);rc=124
            os.fsync(stream.fileno())
        st.pop('child_pid',None);st.pop('child_start_ticks',None)
        st['commands'].append(dict(label=label,argv=list(map(str,argv)),cwd=str(cwd) if cwd else None,returncode=rc,wall_seconds=time.monotonic()-started,log=str(log)));save(R,st)
        assert rc in expected,(label,rc,str(log))
        return log

    def linux(label,binary,case):
        result=logs/(label+'.json')
        if result.exists():
            r=json.loads(result.read_text());assert r['passed'];return Path(r['output'])
        tree=out/label/'tree'
        if tree.exists():shutil.rmtree(tree)
        for name in ['bin','dev','proc','sys','tmp','run','work','opt']:(tree/name).mkdir(parents=True,exist_ok=True)
        shutil.copy2(busybox,tree/'bin/busybox');(tree/'bin/sh').symlink_to('busybox')
        shutil.copy2(binary,tree/'opt/ferret')
        shutil.copytree(oldout/'inputs/ferret'/case['input'],tree/'work',dirs_exist_ok=True)
        argv=' '.join(shlex.quote(x) for x in ['/opt/ferret',*case['argv']])
        init='''#!/bin/sh
export PATH=/bin OMP_NUM_THREADS=1
/bin/busybox mount -t proc proc /proc
/bin/busybox mount -t sysfs sysfs /sys
/bin/busybox mount -t devtmpfs devtmpfs /dev
exec </dev/console >/dev/console 2>&1
cd /work
COMMAND
rc=$?
echo EC_FERRET_APP_EXIT=$rc
/bin/busybox sha256sum output.txt
echo EC_FERRET_OUTPUT_BEGIN
/bin/busybox uuencode -m output.txt output.txt
echo EC_FERRET_OUTPUT_END
echo EC_FERRET_DIAGNOSTIC_DONE
/bin/busybox poweroff -f
'''.replace('COMMAND',argv,1)
        (tree/'init').write_text(init);(tree/'init').chmod(0o755)
        image=tree.parent/'initramfs.cpio';cpio_newc(tree,image)
        command=[qemu,'-machine','virt','-cpu','rv64','-m','2G','-smp','1','-nographic','-no-reboot','-bios','default',
            '-kernel',kernel,'-initrd',image,'-append','console=ttyS0 earlycon=sbi rdinit=/init panic=-1 mem=2G']
        log=run(label,command)
        text=log.read_text(errors='replace')
        assert 'EC_FERRET_APP_EXIT=0' in text and 'EC_FERRET_DIAGNOSTIC_DONE' in text and 'Kernel panic' not in text
        body=text.split('EC_FERRET_OUTPUT_BEGIN\n',1)[1].split('EC_FERRET_OUTPUT_END',1)[0]
        body=body.replace('\r','').split('begin-base64 644 output.txt\n',1)[1].split('====',1)[0]
        captured=logs/(label+'-output.txt');captured.write_bytes(base64.b64decode(body))
        assert re.search(r'(?m)^'+sha(captured)+r'  output.txt\s*$',text),'guest/host transfer hash'
        save(result,dict(passed=True,diagnostic_only=True,fpga_execution=False,output=str(captured),output_sha256=sha(captured),
            elf_sha256=sha(binary),input_files=case['input_files'],argv=case['argv'],rootfs_sha256=sha(image),log=str(log)))
        return captured

    try:
        small=next(c for c in old['cases'] if c['input']=='simsmall')
        observed=linux('original-linux-simsmall',oldout/'ferret-diagnostic',small)
        ref=Path(next(iter(small['reference_outputs'])))
        actual=observed.read_text().splitlines(); expected=ref.read_text().splitlines()
        keys=lambda rows:[s.split('\t')[0] for s in rows]
        evidence=dict(exact_bytes=observed.read_bytes()==ref.read_bytes(),same_complete_query_rows=sorted(actual)==sorted(expected),
            query_count=len(actual),query_keys_unique=len(set(keys(actual)))==len(actual),actual_order=keys(actual),reference_order=keys(expected),
            observed_output=str(observed),reference_output=str(ref))
        st['original_linux_comparison']=evidence;save(R,st)
        assert not evidence['exact_bytes'] and evidence['same_complete_query_rows'] and evidence['query_keys_unique'], 'not proven to be a pure directory-order mismatch; retain evidence, do not alter gate'
        source=(oldout/'stage.cc').read_text()
        fixed=source.replace('#include <cstdio>','#include <cstdio>\n#include <algorithm>')
        anchor='  directories[p].next=0;'
        assert fixed.count(anchor)==1
        fixed=fixed.replace(anchor,'  std::sort(directories[p].entries.begin(), directories[p].entries.end(), [](const struct dirent &a, const struct dirent &b) { return strcmp(a.d_name, b.d_name) < 0; });\n'+anchor)
        (out/'stage.cc').write_text(fixed)
        patch=logs/'stable-directory-order.patch';patch.write_text(''.join(difflib.unified_diff(source.splitlines(True),fixed.splitlines(True),fromfile=str(oldout/'stage.cc'),tofile=str(out/'stage.cc'))))
        for name in ['ferret.c','image.c','image.o','ferret.o','ferret-diagnostic.o','diagnostic-hooks.o']:shutil.copy2(oldout/name,out/name)
        if not (out/'inputs').exists():shutil.copytree(oldout/'inputs',out/'inputs')
        # Reuse exactly the parent's compiler flags, computation objects and static libraries.
        commands=[x['argv'] for x in old['commands'] if x['argv'] and str(x['argv'][0]).endswith('riscv64-unknown-linux-gnu-g++')]
        for argv in commands:
            if '-c' in argv and str(oldout/'stage.cc') not in argv:continue
            argv=[str(out/Path(a).name) if a.startswith(str(oldout)+'/') else a for a in argv]
            target=Path(argv[argv.index('-o')+1]); label='build-'+target.name
            if not target.exists():run(label,argv)
        receipt=copy.deepcopy(old)
        receipt.update(output_dir=str(out),host_log_dir=str(logs),software_profile='ferret-serial-staged-stable-directory-order/1',
            status='PREPARED_FPGA_NOT_RUN',commands=[],cases=[],pid=os.getpid(),parent_receipt=str(oldpath),parent_receipt_sha256=sha(oldpath),
            integration_patch=str(patch),integration_patch_sha256=sha(patch),algorithm_sources_modified=False,
            version_delta='Only sort preloaded directory entries outside the original ROI; every original scan/JPEG/features/query/ranking/output operation remains in ROI.',
            diagnostic_capture_files=['output.txt'],fpga_validation='NOT_RUN')
        for c in old['cases']:
            c=copy.deepcopy(c);size=c['input'];label='fixed-user-'+size;work=logs/label
            if not work.exists():shutil.copytree(oldout/'inputs/ferret'/size,work)
            trace=run(label,['/usr/bin/qemu-riscv64','-strace',out/'ferret-diagnostic',*c['argv']],cwd=work)
            output=work/'output.txt';reference=Path(next(iter(c['reference_outputs'])))
            assert sorted(output.read_text().splitlines())==sorted(reference.read_text().splitlines()),'original per-query results differ'
            assert keys(output.read_text().splitlines())==sorted(keys(output.read_text().splitlines()))
            rows=trace.read_text().splitlines();begin=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_BEGIN'));end=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_END'))
            calls=[l for l in rows[begin+1:end] if re.match(r'^\d+ [a-zA-Z_]\w*\(',l)];assert not calls, calls
            captured=linux('fixed-linux-'+size,out/'ferret-diagnostic',c)
            assert output.read_bytes()==captured.read_bytes(),'fixed user/Linux byte mismatch'
            c.update(validation=dict(kind='files_sha256',files={'output.txt':sha(output)}),reference_outputs={str(output):sha(output)},
                diagnostic_trace=str(trace),diagnostic_roi_syscalls=calls,original_reference=str(reference),original_query_rows_exact=True,
                linux_output=str(captured),linux_output_sha256=sha(captured),fpga_validation='NOT_RUN')
            receipt['cases'].append(c);st['cases'][size]=c;save(R,st)
        receipt['binaries']['ferret'].update(path=str(out/'ferret'),sha256=sha(out/'ferret'))
        target=W/f'software/{PROFILE}-apps-build.json'
        if target.exists():assert json.loads(target.read_text())['binaries']==receipt['binaries']
        else:save(target,receipt)
        save(out/'manifest.json',receipt)
        root=W/'software';rootfs=root/f'{PROFILE}-rootfs-build.json'
        if not rootfs.exists():
            run('rootfs',[sys.executable,W/'scripts/prepare_rootfs.py','--apps-receipt',target,'--output-receipt',rootfs])
        fs=json.loads(rootfs.read_text());assert fs['apps_manifest_sha256']==sha(target) and sha(fs['path'])==fs['sha256']
        reuse=[]
        for cfg in ['Native','C4']:
            parent=root/cfg/'canneal-formal-kernel-build.json';kernel_receipt=root/cfg/f'{PROFILE}-kernel-build.json'
            if not kernel_receipt.exists():
                run(cfg+'-profile-kernel',[sys.executable,W/'scripts/build_earlyconsole.py',cfg,'--parent-receipt',parent,
                    '--rootfs-receipt',rootfs,'--output-receipt',kernel_receipt,
                    '--build-root','/var/tmp/guozh-firesim-final-opt4-20261107-cad/system-builds'],timeout=3600)
            before=Path(json.loads(parent.read_text())['output_dir']);after=Path(json.loads(kernel_receipt.read_text())['output_dir'])
            config=lambda p:[l for l in (p/'.config').read_text().splitlines() if not l.startswith('CONFIG_INITRAMFS_SOURCE=')]
            assert config(before)==config(after)
            assert sha(before/'drivers/misc/ec_dac_roi.o')==sha(after/'drivers/misc/ec_dac_roi.o')
            reuse.append(dict(configuration=cfg,config_equal_except_initramfs=True,roi_driver_object_unchanged=True,
                parent_receipt=str(parent),kernel_receipt=str(kernel_receipt),roi_driver_object_sha256=sha(after/'drivers/misc/ec_dac_roi.o')))
        st['kernel_reuse']=reuse;save(R,st)
        run('safe-fdt',[sys.executable,W/'scripts/prepare_safe_fdt_profile.py',PROFILE],timeout=1800)
        gate=(D/'locks/future-software-plan-update.lock').open('a');fcntl.flock(gate,fcntl.LOCK_EX)
        planpath=D/'suite-execution-plan.json';plan=json.loads(planpath.read_text())
        active=json.loads((D/'active-0000_21_00.0.json').read_text())
        assert not(active.get('program')=='ferret' and active.get('status') in ['RUNNING','STARTING'])
        row=next(r for r in plan['programs'] if r['program']=='ferret');assert row['software_profile_prefix'] in ['ferret-safe-fdt',PROFILE+'-safe-fdt']
        archive=D/'plan-history'/('before-ferret-stable-order-'+stamp+'.json');save(archive,plan)
        row['software_profile_prefix']=PROFILE+'-safe-fdt';save(planpath,plan)
        if st.get('error'):st.setdefault('resolved_attempt_errors',[]).append(st.pop('error'))
        st.update(status='BOUND_FOR_EXISTING_QUEUE',apps_receipt=str(target),apps_receipt_sha256=sha(target),
            elf_sha256=sha(out/'ferret'),patch=str(patch),patch_sha256=sha(patch),plan_archive=str(archive),
            plan_sha256=sha(planpath),ended_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
            next_action='Original coverage-first, 21-only: test -> simsmall -> formal r1/r2/r3, strict exact output and ROI gates; existing C4 priority unchanged')
        save(R,st)
    except Exception as exc:
        st.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(R,st);raise


if __name__=='__main__':main()
