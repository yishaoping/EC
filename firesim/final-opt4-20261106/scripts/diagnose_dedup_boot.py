#!/usr/bin/env python3
"""Validate the failed image off board; QEMU boot is diagnostic, never FPGA proof."""
import datetime as dt
import argparse
import gzip
import hashlib
import json
import os
from pathlib import Path
import selectors
import signal
import subprocess
import time
from board_batch import W,D,save,sha

def main():
    parser=argparse.ArgumentParser();parser.add_argument('--profile',default='dedup-staged');parser.add_argument('--bios-kind',choices=['default','firmware-jump'],default='default');a=parser.parse_args()
    assert a.profile.replace('-','').isalnum()
    prefix='dedup' if a.profile=='dedup-staged' else a.profile
    checkpoint=D/f'software/{prefix}-boot-diagnostic.json'
    if checkpoint.exists() and json.loads(checkpoint.read_text()).get('status')=='COMPLETE':return
    fwpath=W/f'software/Native/{a.profile}-firmware-build.json'
    if not fwpath.exists():
        deadline=time.monotonic()+1800
        while not fwpath.exists() and time.monotonic()<deadline:time.sleep(5)
    fw=json.loads(fwpath.read_text())
    kp=next(Path(p) for p in fw['input_files'] if 'kernel' in p and p.endswith('.json'))
    k=json.loads(kp.read_text());out=Path(k['output_dir'])
    root=json.loads((W/f'software/{a.profile}-rootfs-build.json').read_text())
    raw=Path(root['path']).read_bytes();blob=(out/'usr/initramfs_inc_data').read_bytes()
    uncompressed=gzip.decompress(blob) if blob[:2]==b'\x1f\x8b' else blob
    assert uncompressed==raw, 'kernel initramfs differs from bound rootfs'
    pos=0;entries=[]
    while True:
        assert raw[pos:pos+6]==b'070701',(pos,raw[pos:pos+16])
        fields=[int(raw[pos+6+i*8:pos+14+i*8],16) for i in range(13)]
        size,namesize=fields[6],fields[11];start=pos+110
        name=raw[start:start+namesize-1].decode();assert raw[start+namesize-1]==0
        start=(start+namesize+3)&~3;end=start+size
        assert end<=len(raw)
        entries.append(dict(name=name,bytes=size))
        pos=(end+3)&~3
        if name=='TRAILER!!!':break
    assert not raw[pos:].strip(b'\0')
    image=out/'arch/riscv/boot/Image';assert sha(image)==fw['content_checks']['kernel']['sha256']
    qemu=Path('/data1/gzh/EC/chipyard/.conda-env/bin/qemu-system-riscv64')
    logs=D/'software'/(prefix+'-boot-diagnostic-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ'));logs.mkdir()
    bios='default' if a.bios_kind=='default' else str(Path(fw['output_dir'])/'platform/generic/firmware/fw_jump.bin')
    argv=[str(qemu),'-machine','virt','-cpu','rv64','-m','2G','-smp','1','-nographic','-no-reboot','-bios',bios,'-kernel',str(image),'-append','console=ttyS0 earlycon=sbi rdinit=/init panic=-1 mem=2G']
    state=dict(status='RUNNING',pid=os.getpid(),host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
               log=str(logs/'console.log'),argv=argv,kernel_sha256=sha(image),rootfs_sha256=sha(root['path']),
               firmware_receipt_sha256=sha(fwpath),kernel_archive_exact_match=True,cpio_entries=entries,
               diagnostic_only=True,fpga_operations=False,measurement_validity=False,
               bios_sha256=sha(bios) if bios!='default' else None,
               firmware_runtime_layout=fw.get('content_checks',{}).get('runtime_memory_layout'))
    save(checkpoint,state)
    c=subprocess.Popen(argv,stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,start_new_session=True,
                       env={**os.environ,'LD_LIBRARY_PATH':''})
    state.update(child_pid=c.pid,child_start_ticks=Path(f'/proc/{c.pid}/stat').read_text().split()[21]);save(checkpoint,state)
    sel=selectors.DefaultSelector();sel.register(c.stdout,selectors.EVENT_READ)
    start=time.monotonic();data=bytearray();sent=False;timedout=False
    with (logs/'console.log').open('wb',buffering=0) as log:
        while c.poll() is None:
            for key,_ in sel.select(timeout=1):
                chunk=os.read(key.fileobj.fileno(),65536)
                if chunk:log.write(chunk);os.fsync(log.fileno());data.extend(chunk)
            if b'EC_GUEST_READY' in data and not sent:
                c.stdin.write(b'/bin/busybox sha256sum /opt/ec-fpga/BUILD.json; cd /opt/ec-fpga; /bin/busybox sha256sum -c SHA256SUMS > /tmp/integrity.log; echo EC_QEMU_INTEGRITY_RC=$?; /bin/busybox cat /tmp/integrity.log; echo EC_QEMU_BOOT_DIAGNOSTIC_DONE; /bin/poweroff -f\n');c.stdin.flush();sent=True
            if time.monotonic()-start>180 or b'Kernel panic' in data:
                timedout=time.monotonic()-start>180;os.killpg(c.pid,signal.SIGTERM)
                try:c.wait(timeout=15)
                except subprocess.TimeoutExpired:os.killpg(c.pid,signal.SIGKILL);c.wait()
                break
        rest=c.stdout.read();log.write(rest);data.extend(rest);os.fsync(log.fileno())
    text=data.decode(errors='replace')
    state.update(status='COMPLETE',qemu_returncode=c.wait(),qemu_guest_ready=sent,
                 qemu_integrity_passed='EC_QEMU_INTEGRITY_RC=0' in text,
                 qemu_guest_done='\nEC_QEMU_BOOT_DIAGNOSTIC_DONE' in text,
                 kernel_panic='Kernel panic' in text,timedout=timedout,
                 conclusion='Archive and software boot diagnostics only; original FPGA boot failure remains unvalidated',
                 ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    save(checkpoint,state);save(logs/'result.json',state)
    print(json.dumps({k:state[k] for k in ['status','kernel_archive_exact_match','qemu_guest_ready','qemu_integrity_passed','kernel_panic','timedout']}),flush=True)

if __name__=='__main__':main()
