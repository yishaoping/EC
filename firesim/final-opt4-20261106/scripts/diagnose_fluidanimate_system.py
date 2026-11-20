#!/usr/bin/env python3
"""Run the original reference in a private Linux guest; no FPGA or validity bypass."""
import datetime as dt
import base64
import hashlib
import json
import os
from pathlib import Path
import re
import selectors
import shutil
import signal
import subprocess
import sys
import time
from board_batch import W,D,save,sha
sys.path.insert(0,'/data1/gzh/EC/firesim/dac2026/scripts')
from prepare_boot_prerequisite import cpio_newc


def recover_existing():
    output=D/'software/fluidanimate-linux-reference-diagnostic.json'
    state=json.loads(output.read_text())
    assert state.get('status')=='FAILED_WITH_EVIDENCE',state.get('status')
    log=Path(state['log_dir'])/'console.log'
    text=log.read_bytes().decode(errors='strict').replace('\r','')
    begin='EC_DIAGNOSTIC_FILE_BEGIN run_id=fluidanimate-linux-reference file=out.fluid bytes='
    end='EC_DIAGNOSTIC_FILE_END run_id=fluidanimate-linux-reference file=out.fluid'
    starts=[i for i,line in enumerate(text.splitlines()) if line.startswith(begin)]
    ends=[i for i,line in enumerate(text.splitlines()) if line==end]
    assert len(starts)==len(ends)==1 and starts[0]<ends[0]
    lines=text.splitlines();header=lines[starts[0]]
    match=re.fullmatch(re.escape(begin)+r'(\d+) encoding=base64',header)
    assert match and state.get('qemu_returncode')==0
    assert 'EC_LINUX_REFERENCE_EXIT=0' in text and 'EC_LINUX_REFERENCE_DONE' in lines
    declared=int(match.group(1));payload=[];ignored=[]
    for line in lines[starts[0]+1:ends[0]]:
        if re.fullmatch(r'[A-Za-z0-9+/=]+',line) and len(line)<=60 and len(line)%4==0:
            payload.append(line)
        elif re.fullmatch(r'\[\s*\d+(?:\.\d+)?\] [^\r\n]*',line):
            ignored.append(line)
        else:
            raise ValueError('unexpected line in diagnostic transfer: '+repr(line[:120]))
    encoded=''.join(payload)
    assert len(encoded)==4*((declared+2)//3), (len(encoded),declared)
    recovered=base64.b64decode(encoded,validate=True)
    assert len(recovered)==declared
    guest_hash=next(line.split()[0] for line in lines if re.fullmatch(r'[0-9a-f]{64}  out\.fluid',line))
    digest=hashlib.sha256(recovered).hexdigest();assert digest==guest_hash,(digest,guest_hash)
    apps=json.loads((W/'software/fluidanimate-apps-build.json').read_text())
    case=next(c for c in apps['cases'] if c['input']=='simsmall')
    target=Path(state['log_dir'])/'out.fluid';tmp=target.with_name(target.name+'.recover.tmp')
    with tmp.open('wb') as f:f.write(recovered);f.flush();os.fsync(f.fileno())
    tmp.replace(target)
    prior=dict(status=state.get('status'),error=state.get('error'),qemu_returncode=state.get('qemu_returncode'))
    archive=D/'software'/('fluidanimate-linux-reference-before-recovery-'+sha(output)+'.json')
    if not archive.exists():save(archive,state)
    state.update(status='COMPLETE_RECOVERED_FROM_EVIDENCE',output_file=str(target),output_sha256=digest,
        guest_reported_sha256=guest_hash,declared_bytes=declared,ignored_printk_lines=ignored,
        user_reference_sha256=case['reference_outputs']['out.fluid'],
        system_vs_user_exact=digest==case['reference_outputs']['out.fluid'],
        parser_recovered_without_rerun=True,prior_parser_failure=prior,prior_state_archive=str(archive),fpga_validity=False,
        recovered_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    save(output,state)
    receipt=D/'software/fluidanimate-linux-reference-recovery.json'
    save(receipt,dict(schema='ec-fluidanimate-linux-reference-recovery/1',status=state['status'],
        diagnostic_only=True,formal_eligible=False,run_log=str(log),run_log_sha256=sha(log),
        output_file=str(target),output_bytes=len(recovered),output_sha256=digest,
        guest_reported_sha256=guest_hash,user_reference_sha256=case['reference_outputs']['out.fluid'],
        exact_user_reference_match=state['system_vs_user_exact'],ignored_printk_lines=ignored,
        previous_failure=prior,reexecuted_qemu=False))
    print(json.dumps(state),flush=True)


def main():
    if sys.argv[1:]==['--recover-existing']:
        recover_existing();return
    output=D/'software/fluidanimate-linux-reference-diagnostic.json'
    old=json.loads(output.read_text()) if output.exists() else {}
    if old.get('status')=='COMPLETE':return
    apps=json.loads((W/'software/fluidanimate-apps-build.json').read_text())
    original=json.loads((W/'software/fluidanimate-rootfs-build.json').read_text())
    reference=Path(apps['output_dir'])/'fluidanimate-reference';assert reference.exists()
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    work=W/'software'/('fluidanimate-linux-diagnostic-'+stamp);work.mkdir()
    logs=D/'software'/work.name;logs.mkdir()
    tree=work/'tree';shutil.copytree(Path(original['path']).parent/'tree',tree,symlinks=True)
    shutil.copy2(reference,tree/'opt/ec-fpga/fluidanimate-reference')
    (tree/'init').write_text('''#!/bin/sh
export PATH=/bin:/sbin
mount -t devtmpfs devtmpfs /dev
mount -t proc proc /proc
mount -t sysfs sysfs /sys
exec </dev/console >/dev/console 2>&1
cd /opt/ec-fpga/inputs/fluidanimate/simsmall
echo EC_LINUX_REFERENCE_INPUT
/bin/busybox sha256sum in_35K.fluid /opt/ec-fpga/fluidanimate-reference
/opt/ec-fpga/fluidanimate-reference 1 5 in_35K.fluid out.fluid
rc=$?
echo EC_LINUX_REFERENCE_EXIT=$rc
/bin/busybox sha256sum out.fluid
size=$(/bin/busybox wc -c < out.fluid)
echo "EC_DIAGNOSTIC_FILE_BEGIN run_id=fluidanimate-linux-reference file=out.fluid bytes=$size encoding=base64"
/bin/busybox uuencode -m out.fluid ec-diagnostic | /bin/busybox sed '1d;$d'
echo EC_DIAGNOSTIC_FILE_END run_id=fluidanimate-linux-reference file=out.fluid
echo EC_LINUX_REFERENCE_DONE
/bin/busybox poweroff -f
''');(tree/'init').chmod(0o755)
    cpio_newc(tree,work/'initramfs.cpio')
    root_receipt=work/'rootfs-build.json';save(root_receipt,dict(path=str(work/'initramfs.cpio'),sha256=sha(work/'initramfs.cpio'),
        apps_manifest_sha256=sha(W/'software/fluidanimate-apps-build.json'),diagnostic_only=True))
    kernel_receipt=work/'kernel-build.json';log=logs/'kernel-build.log'
    state=dict(status='BUILDING_PRIVATE_DIAGNOSTIC_KERNEL',diagnostic_only=True,fpga_operations=False,
        rootfs_receipt=str(root_receipt),reference_elf=str(reference),reference_elf_sha256=sha(reference),
        original_apps_receipt_sha256=sha(W/'software/fluidanimate-apps-build.json'),log_dir=str(logs),
        no_algorithm_changes=True,no_active_inputs_modified=True)
    save(output,state)
    with log.open('wb',buffering=0) as f:
        subprocess.run(['python3',W/'scripts/build_earlyconsole.py','Native','--parent-receipt',W/'software/Native/fluidanimate-kernel-build.json',
            '--rootfs-receipt',root_receipt,'--output-receipt',kernel_receipt,'--build-root','/var/tmp/guozh-firesim-final-opt4-20261107-cad/system-builds'],
            stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,check=True)
    kernel=json.loads(kernel_receipt.read_text());image=Path(kernel['output_dir'])/'arch/riscv/boot/Image'
    assert 0x80200000+image.stat().st_size<0x82200000, 'QEMU default DTB placement must not overlap this diagnostic kernel'
    qemu='/data1/gzh/EC/chipyard/.conda-env/bin/qemu-system-riscv64'
    argv=[qemu,'-machine','virt','-cpu','rv64','-m','2G','-smp','1','-nographic','-no-reboot','-bios','default',
          '-kernel',str(image),'-append','console=ttyS0 earlycon=sbi rdinit=/init panic=-1 mem=2G']
    state.update(status='RUNNING_PRIVATE_QEMU_LINUX',argv=argv,kernel_sha256=sha(image));save(output,state)
    child=subprocess.Popen(argv,stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,start_new_session=True,
                           env={**os.environ,'LD_LIBRARY_PATH':''})
    state.update(child_pid=child.pid,child_start_ticks=Path(f'/proc/{child.pid}/stat').read_text().split()[21]);save(output,state)
    sel=selectors.DefaultSelector();sel.register(child.stdout,selectors.EVENT_READ);begin=time.monotonic();data=bytearray()
    with (logs/'console.log').open('wb',buffering=0) as f:
        while child.poll() is None:
            for key,_ in sel.select(timeout=1):
                chunk=os.read(key.fileobj.fileno(),65536)
                if chunk:f.write(chunk);data.extend(chunk)
            if time.monotonic()-begin>600 or b'Kernel panic' in data:
                os.killpg(child.pid,signal.SIGTERM)
                try:child.wait(timeout=15)
                except subprocess.TimeoutExpired:os.killpg(child.pid,signal.SIGKILL);child.wait()
                break
        rest=child.stdout.read();f.write(rest);data.extend(rest);os.fsync(f.fileno())
    import base64,re
    text=data.decode(errors='replace').replace('\r','');state.update(qemu_returncode=child.wait(),console_log=str(logs/'console.log'))
    begin='EC_DIAGNOSTIC_FILE_BEGIN run_id=fluidanimate-linux-reference file=out.fluid bytes='
    match=re.search(re.escape(begin)+r'(\d+) encoding=base64\n(.*?)^EC_DIAGNOSTIC_FILE_END run_id=fluidanimate-linux-reference file=out.fluid$',text,re.M|re.S)
    if not (match and 'EC_LINUX_REFERENCE_EXIT=0' in text and '\nEC_LINUX_REFERENCE_DONE' in text):
        state.update(status='FAILED_WITH_EVIDENCE',error='complete reference output missing');save(output,state)
        raise RuntimeError('complete reference output missing')
    # Linux console messages may be interleaved with a long UART transfer;
    # accept only complete uuencode payload lines and reject malformed data.
    encoded=''.join(line for line in match[2].splitlines() if re.fullmatch(r'[A-Za-z0-9+/=]+',line))
    recovered=base64.b64decode(encoded,validate=True);assert len(recovered)==int(match[1])
    out=logs/'out.fluid';out.write_bytes(recovered)
    case=next(c for c in apps['cases'] if c['input']=='simsmall')
    state.update(status='COMPLETE',output_file=str(out),output_sha256=sha(out),user_reference_sha256=case['reference_outputs']['out.fluid'],
                 system_vs_user_exact=sha(out)==case['reference_outputs']['out.fluid'],fpga_validity=False,
                 ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    save(output,state);print(json.dumps(state),flush=True)


if __name__=='__main__':main()
