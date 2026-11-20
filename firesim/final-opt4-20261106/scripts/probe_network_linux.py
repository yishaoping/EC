#!/usr/bin/env python3
"""Bounded UART-visible diagnosis of the first Linux-only network timeout."""
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import shutil
import signal
import subprocess
import sys
from board_batch import W,D,save,sha
from job_service import proc
sys.path.insert(0,'/data1/gzh/EC/firesim/dac2026/scripts')
from prepare_boot_prerequisite import cpio_newc

def main():
    lock=(D/'software/network-linux-probe.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    prior=json.loads((D/'software/network-linux-validation.json').read_text())
    failed=Path(prior['output_dir'])/'netdedup-test/result.json'
    assert json.loads(failed.read_text())['status']=='FAILED_WITH_EVIDENCE'
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=D/'software'/('network-linux-probe-'+stamp);out.mkdir()
    work=W/'software'/out.name;work.mkdir();tree=work/'tree'
    shutil.copytree(Path(prior['work_dir'])/'netdedup-test/tree',tree,symlinks=True)
    init='''#!/bin/sh
export PATH=/bin UPTCPIP_RX_THREADS=1
/bin/busybox mount -t proc proc /proc
/bin/busybox mount -t sysfs sysfs /sys
/bin/busybox mount -t devtmpfs devtmpfs /dev
/bin/busybox mount -t tmpfs tmpfs /tmp
exec </dev/console >/dev/console 2>&1
echo EC_NETWORK_PROBE_START
cd /work
/opt/client -i test.dat &
cp=$!
/opt/server -c -v -t 1 -o out.ddp &
sp=$!
/bin/busybox sleep 5
echo EC_NETWORK_PROBE_SHM
/bin/busybox cat /proc/sysvipc/shm
/bin/busybox ls -li /tmp
for p in /proc/[0-9]*; do
 echo EC_NETWORK_PROBE_TASK=$p
 /bin/busybox cat "$p/comm" "$p/wchan"
 for t in "$p"/task/*; do echo THREAD=$t; /bin/busybox cat "$t/wchan"; done
done
wait "$sp"; sr=$?
wait "$cp"; cr=$?
echo EC_NETWORK_PROBE_PEERS server=$sr client=$cr
/bin/busybox sha256sum out.ddp
echo EC_NETWORK_PROBE_DONE
/bin/busybox poweroff -f
'''
    (tree/'init').write_text(init);(tree/'init').chmod(0o755)
    image=work/'initramfs.cpio';cpio_newc(tree,image)
    argv=[prior['qemu']['path'],'-machine','virt','-cpu','rv64','-m','2G','-smp','1','-nographic','-no-reboot','-bios','default',
        '-kernel',prior['reused_kernel']['path'],'-initrd',str(image),'-append','console=ttyS0 earlycon=sbi rdinit=/init panic=-1 mem=2G']
    st=dict(schema='ec-network-linux-probe/1',status='RUNNING',output_dir=str(out),work_dir=str(work),argv=argv,
        rootfs_sha256=sha(image),source_failure=str(failed),candidate_receipt_sha256=prior['candidate_receipt_sha256'],
        pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
        diagnostic_only=True,formal_eligible=False,fpga_execution=False,timeout_seconds=60,
        differences='Mount private guest tmpfs /tmp and expose unmodified peer stdout directly to guest UART for diagnosis')
    R=D/'software/network-linux-probe.json';save(R,st)
    with (out/'console.log').open('wb',buffering=0) as log:
        child=subprocess.Popen(['nice','-n','15',*argv],stdout=log,stderr=subprocess.STDOUT,stdin=subprocess.DEVNULL,start_new_session=True)
        st.update(child_pid=child.pid,child_start_ticks=proc(child.pid)['start_ticks']);save(R,st)
        try:rc=child.wait(timeout=60)
        except subprocess.TimeoutExpired:os.killpg(child.pid,signal.SIGTERM);child.wait(timeout=15);rc=124
        os.fsync(log.fileno())
    st.update(status='COMPLETE_DIAGNOSTIC_ONLY',returncode=rc,ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(R,st)

if __name__=='__main__':main()
