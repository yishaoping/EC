#!/usr/bin/env python3
"""Reuse the diagnostic Linux kernel for network candidates, without FPGA access."""
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import re
import shutil
import signal
import subprocess
import sys
import tarfile
import time
from board_batch import W,D,save,sha
from job_service import proc
from network_binding import candidate
sys.path.insert(0,'/data1/gzh/EC/firesim/dac2026/scripts')
from prepare_boot_prerequisite import cpio_newc

R=D/'software/netstreamcluster-linux-validation.json'
P=Path('/data1/gzh/EC/Software/PARSEC')

def main():
    lock=(D/'software/netstreamcluster-linux-validation.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    bound,build=candidate(W/'software/network-candidate-build.json')
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    if R.exists():
        st=json.loads(R.read_text());assert st['candidate_receipt_sha256']==bound
        if st['status']=='COMPLETE_REVIEW_EVIDENCE':return
    else:
        st=dict(schema='ec-network-linux-validation/1',status='PREPARING',candidate_receipt_sha256=bound,
            output_dir=str(D/'software'/('netstreamcluster-linux-'+stamp)),work_dir=str(W/'software'/('netstreamcluster-linux-'+stamp)),
            started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),cases=[],formal_eligible=False,fpga_execution=False,
            hardware_modified=False,scheduler_modified=False)
    st.update(pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    out=Path(st['output_dir']);out.mkdir(exist_ok=True)
    work=Path(st['work_dir']);work.mkdir(exist_ok=True)
    # This earlier diagnostic kernel supports QEMU 16550 and SysV IPC; its
    # embedded initramfs is overlaid by a new external initrd. No kernel rebuild.
    prior=json.loads((D/'software/fluidanimate-stable-order-candidate.json').read_text())
    argv=prior['argv'];kernel=Path(argv[argv.index('-kernel')+1]);qemu=Path(argv[0])
    busybox=Path('/data1/gzh/EC/firesim/dac2026/images/software-v3/B-boot-20261102T083720.765499Z/rootfs/bin/busybox')
    st['reused_kernel']=dict(path=str(kernel),sha256=sha(kernel),configuration_sha256=sha(kernel.parents[3]/'.config'))
    st['qemu']=dict(path=str(qemu),sha256=sha(qemu));st['busybox_sha256']=sha(busybox);save(R,st)
    follow=json.loads((D/'software/network-followup-state.json').read_text())
    first=json.loads((D/'software/network-offline-validation.json').read_text())
    for size in ['simsmall','simmedium']:
        for name in ['netstreamcluster']:
            label=name+'-'+size;logdir=out/label
            if (logdir/'result.json').exists():continue
            if logdir.exists():logdir.rename(logdir.with_name(label+'-interrupted-'+stamp))
            logdir.mkdir()
            reference=Path(follow['output_dir'])/(label+'-riscv64')/'result.json'
            if not reference.exists():reference=Path(first['output_dir'])/(label+'-riscv64')/'result.json'
            case=json.loads(reference.read_text());assert case['status']!='FAILED_WITH_EVIDENCE'
            tree=work/label/'tree'
            if tree.parent.exists():tree.parent.rename(tree.parent.with_name(label+'-interrupted-'+stamp))
            for n in ['bin','dev','proc','sys','tmp','run','work','opt']: (tree/n).mkdir(parents=True,exist_ok=True)
            shutil.copy2(busybox,tree/'bin/busybox');(tree/'bin/sh').symlink_to('busybox')
            for part,b in build['programs'][name]['binaries'].items():
                assert sha(b['path'])==b['sha256']
                shutil.copy2(b['path'],tree/'opt'/('client' if part.startswith('client/') else 'server'))
            if case['input_archive']:
                archive=Path(case['input_archive']['path']);assert sha(archive)==case['input_archive']['sha256']
                with tarfile.open(archive) as tar:
                    assert all(not Path(m.name).is_absolute() and '..' not in Path(m.name).parts and not m.issym() and not m.islnk() for m in tar.getmembers())
                    tar.extractall(tree/'work')
            import shlex
            server=' '.join(shlex.quote(x) for x in ['/opt/server',*case['server_argv'][1:]])
            client=' '.join(shlex.quote(x) for x in ['/opt/client',*case['client_argv'][1:]])
            output='out.ddp' if name=='netdedup' else 'output.txt'
            decode="/opt/server -u -o decoded.dat > /run/decode.log 2>&1\necho EC_NETWORK_LINUX_DECODE_EXIT=$?\n/bin/busybox sha256sum decoded.dat "+('test.dat' if size=='test' else 'media.dat') if name=='netdedup' else ''
            init='''#!/bin/sh
export PATH=/bin UPTCPIP_RX_THREADS=1 OMP_NUM_THREADS=1 PARSEC_NUM_THREADS=1
/bin/busybox mount -t proc proc /proc
/bin/busybox mount -t sysfs sysfs /sys
/bin/busybox mount -t devtmpfs devtmpfs /dev
exec </dev/console >/dev/console 2>&1
echo EC_NETWORK_LINUX_START=LABEL
cd /work
CLIENT > /run/client.log 2>&1 &
client_pid=$!
SERVER > /run/server.log 2>&1 &
server_pid=$!
wait "$server_pid"; server_rc=$?
wait "$client_pid"; client_rc=$?
echo EC_NETWORK_LINUX_PEERS server=$server_rc client=$client_rc
echo EC_NETWORK_LINUX_SERVER_LOG_BEGIN
/bin/busybox cat /run/server.log
echo EC_NETWORK_LINUX_SERVER_LOG_END
echo EC_NETWORK_LINUX_CLIENT_LOG_BEGIN
/bin/busybox cat /run/client.log
echo EC_NETWORK_LINUX_CLIENT_LOG_END
/bin/busybox sha256sum OUTPUT
DECODE
echo EC_NETWORK_LINUX_DONE=LABEL
/bin/busybox poweroff -f
'''.replace('LABEL',label).replace('CLIENT',client,1).replace('SERVER',server,1).replace('OUTPUT',output).replace('DECODE',decode,1)
            # Marker words in the template are not shell-interpolated on host.
            (tree/'init').write_text(init);(tree/'init').chmod(0o755)
            cpio=tree.parent/'initramfs.cpio';cpio_newc(tree,cpio)
            command=[str(qemu),'-machine','virt','-cpu','rv64','-m','2G','-smp','1','-nographic','-no-reboot','-bios','default',
                '-kernel',str(kernel),'-initrd',str(cpio),'-append','console=ttyS0 earlycon=sbi rdinit=/init panic=-1 mem=2G']
            result=dict(program=name,input=size,status='RUNNING',argv=command,rootfs=dict(path=str(cpio),sha256=sha(cpio)),
                candidate_receipt_sha256=bound,reference=str(reference),formal_eligible=False,fpga_execution=False,
                timeout_seconds=300 if size=='test' else 1800)
            save(logdir/'state.json',result)
            started=time.monotonic()
            with (logdir/'console.log').open('wb',buffering=0) as log:
                child=subprocess.Popen(['nice','-n','15',*command],stdout=log,stderr=subprocess.STDOUT,stdin=subprocess.DEVNULL,start_new_session=True)
                st.update(status='RUNNING',active_case=label,child_pid=child.pid,child_start_ticks=proc(child.pid)['start_ticks']);save(R,st)
                result.update(pid=child.pid,start_ticks=st['child_start_ticks'],host_boot_id=st['host_boot_id']);save(logdir/'state.json',result)
                try:rc=child.wait(timeout=result['timeout_seconds'])
                except subprocess.TimeoutExpired:
                    os.killpg(child.pid,signal.SIGTERM);child.wait(timeout=15);rc=124
                os.fsync(log.fileno())
            text=(logdir/'console.log').read_text(errors='replace')
            hashes=re.findall(r'(?m)^([0-9a-f]{64})  '+re.escape(output)+r'\s*$',text)
            peers='EC_NETWORK_LINUX_PEERS server=0 client=0' in text
            roi=text.count('EC_NETWORK_DIAGNOSTIC_ROI_BEGIN')==text.count('EC_NETWORK_DIAGNOSTIC_ROI_END')==1
            exact=hashes==[case['output']['sha256']]
            valid=rc==0 and peers and roi and exact and ('EC_NETWORK_LINUX_DONE='+label) in text
            if name=='netdedup':
                valid=valid and 'EC_NETWORK_LINUX_DECODE_EXIT=0' in text and bool(re.search(r'(?m)^'+case['correctness']['input_sha256']+r'  decoded.dat\s*$',text))
            result.update(status='LINUX_PROTOCOL_AND_EXACT_OUTPUT_PASSED' if valid else 'FAILED_WITH_EVIDENCE',returncode=rc,
                both_peers_exit_zero=peers,original_roi_markers_complete=roi,exact_qemu_user_output=exact,
                observed_output_hashes=hashes,wall_seconds=time.monotonic()-started,ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
            save(logdir/'state.json',result);save(logdir/'result.json',result)
            st['cases'].append(dict(program=name,input=size,status=result['status'],result=str(logdir/'result.json')))
            st.pop('child_pid',None);st.pop('child_start_ticks',None);save(R,st)
    st.update(status='COMPLETE_REVIEW_EVIDENCE',ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(R,st)

if __name__=='__main__':main()
