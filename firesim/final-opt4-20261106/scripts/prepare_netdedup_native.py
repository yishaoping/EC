#!/usr/bin/env python3
"""Separate post-ROI decoding from the measured Netdedup server, then bind it."""
import copy
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

from board_batch import W,D,save,sha
from job_service import proc
from prepare_network_native import WRAPPER,read,run_logged
sys.path.insert(0,'/data1/gzh/EC/firesim/dac2026/scripts')
from prepare_boot_prerequisite import cpio_newc

R=D/'software/netdedup-native-preparation.json'


def main():
    lock=(D/'software/netdedup-native-preparation.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    st=read(R) if R.exists() else {}
    if st.get('status')=='BOUND_TO_EXISTING_NATIVE_QUEUE':return
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=Path(st.setdefault('output_dir',str(W/'software'/('netdedup-native-'+stamp))))
    logs=Path(st.setdefault('log_dir',str(D/'software'/out.name)))
    out.mkdir(exist_ok=True);logs.mkdir(exist_ok=True)
    st.update(status='PREPARING',pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],
        host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),hardware_modified=False,scheduler_modified=False)
    save(R,st)
    try:
        prior=read(D/'software/network-native-preparation.json')
        parent=Path(prior['output_dir'])/'apps-build.json';base=read(parent)
        apps=copy.deepcopy(base)
        apps.update(output_dir=str(out),software_profile='netdedup-original-network-full-roi-native/2',
            parent_receipt=str(parent),parent_receipt_sha256=sha(parent),
            version_delta='Only independent post-ROI correctness decoder uses diagnostic hooks; measured server/client and original compression ROI unchanged')
        apps['binaries']={n:b for n,b in base['binaries'].items() if n in ['netdedup','netdedupclient']}
        probe=read(D/'software/network-complete-roi-probe.json')
        diag=read(probe['cases']['netdedup']['diagnostic_receipt']['path'])
        decoder=diag['programs']['netdedup']['binaries']['server/netdedup']
        assert sha(decoder['path'])==decoder['sha256']
        apps['binaries']['netdedupdecoder']=decoder
        apps['validation_decoder']=dict(**decoder,scope='Full compressed output decode after measured server exit and genuine ROI end; never a measured or checker workload substitute')
        apps['cases']=[c for c in base['cases'] if c['program']=='netdedup']
        for c in apps['cases']:
            source=Path(base['output_dir'])/'inputs/netdedup'/c['input'];dest=out/'inputs/netdedup'/c['input']
            if not dest.exists():shutil.copytree(source,dest)
            assert {str(p.relative_to(dest)):sha(p) for p in dest.rglob('*') if p.is_file()}==c['input_files']
        ap=out/'apps-build.json'
        if ap.exists():assert read(ap)==apps
        else:save(ap,apps)
        fs_path=out/'rootfs-build.json'
        if not fs_path.exists():
            run_logged([sys.executable,W/'scripts/prepare_rootfs.py','--apps-receipt',ap,'--output-receipt',fs_path],logs/'rootfs.log')
        fs=read(fs_path)
        if 'network_launcher_sha256' not in fs:
            tree=Path(fs['path']).parent/'tree';dst=tree/'opt/ec-fpga'
            shell=dst/'run-one';text=shell.read_text()
            anchor='  /opt/ec-fpga/$program $argv >console.pipe 2>&1'
            assert text.count(anchor)==1
            shell.write_text(text.replace(anchor,'  /opt/ec-fpga/run-network "$program" "$input" >console.pipe 2>&1'))
            wrapper=WRAPPER.replace('/opt/ec-fpga/netdedup -u -o decoded.dat','/opt/ec-fpga/netdedupdecoder -u -o decoded.dat')
            (dst/'run-network').write_text(wrapper);(dst/'run-network').chmod(0o755)
            for c in apps['cases']:(dst/'cases/netdedup'/c['input']/'client-argv').write_text(' '.join(c['client_argv'])+'\n')
            for p in [shell,dst/'run-network']:subprocess.run(['/bin/sh','-n',str(p)],check=True)
            (dst/'SHA256SUMS').write_text(''.join(sha(p)+'  '+str(p.relative_to(dst))+'\n' for p in sorted(dst.rglob('*')) if p.is_file() and p.name!='SHA256SUMS'))
            image=Path(fs['path']).parent/'initramfs-network.cpio';cpio_newc(tree,image)
            fs.update(path=str(image),sha256=sha(image),bytes=image.stat().st_size,shared_by=['Native'],
                files={str(p.relative_to(tree)):sha(p) for p in tree.rglob('*') if p.is_file()},
                network_launcher_sha256=sha(dst/'run-network'),validation_decoder=apps['validation_decoder'])
            save(fs_path,fs);save(image.parent/'manifest.json',fs)
        assert sha(fs['path'])==fs['sha256'] and fs['apps_manifest_sha256']==sha(ap)
        # Reuse the exact previously validated wrapper test, changing only the
        # independent decoder executable. A second diagnostic marker pair in
        # decode.log is outside the one measured server ROI and explicitly checked.
        check=logs/'wrapper-test.json'
        if not check.exists():
            tree=Path(fs['path']).parent/'tree';diag_tree=out/'diagnostic/tree'
            shutil.copytree(tree,diag_tree,symlinks=True)
            shutil.copy2(decoder['path'],diag_tree/'opt/ec-fpga/netdedup')
            (diag_tree/'init').write_text('''#!/bin/sh
export PATH=/bin:/sbin
mount -t devtmpfs devtmpfs /dev
mount -t proc proc /proc
mount -t sysfs sysfs /sys
exec </dev/console >/dev/console 2>&1
cd /tmp
/bin/busybox cp -R /opt/ec-fpga/inputs/netdedup/test/. .
/bin/sh /opt/ec-fpga/run-network netdedup test
echo EC_NETWORK_WRAPPER_EXIT=$?
/bin/busybox poweroff -f
''');(diag_tree/'init').chmod(0o755)
            image=diag_tree.parent/'initramfs.cpio';cpio_newc(diag_tree,image)
            argv=read(D/'software/fluidanimate-stable-order-candidate.json')['argv'];kernel=argv[argv.index('-kernel')+1]
            log=logs/'wrapper-test.log'
            run_logged([argv[0],'-machine','virt','-cpu','rv64','-m','2G','-smp','1','-nographic','-no-reboot','-bios','default',
                '-kernel',kernel,'-initrd',image,'-append','console=ttyS0 earlycon=sbi rdinit=/init panic=-1 mem=2G'],log,240)
            t=log.read_text(errors='replace').replace('\r','')
            server=t.split('EC_NETWORK_SERVER_LOG_BEGIN program=netdedup\n')[1].split('EC_NETWORK_SERVER_LOG_END program=netdedup')[0]
            gates=dict(server_full_original_roi=server.count('EC_NETWORK_DIAGNOSTIC_ROI_BEGIN')==server.count('EC_NETWORK_DIAGNOSTIC_ROI_END')==1,
                peers_zero='EC_NETWORK_PEERS_EXIT program=netdedup server=0 client=0' in t,
                complete_decode='decoded.dat: OK' in t,exact_compressed='out.ddp: OK' in t,
                wrapper_zero='EC_NETWORK_WRAPPER_EXIT=0' in t,no_panic='Kernel panic' not in t)
            save(check,dict(passed=all(gates.values()),gates=gates,diagnostic_only=True,fpga_execution=False,
                log=str(log),log_sha256=sha(log),measured_server_sha256=apps['binaries']['netdedup']['sha256'],
                validation_decoder_sha256=decoder['sha256'],launcher_sha256=fs['network_launcher_sha256']))
        assert read(check)['passed']
        st.update(status='BUILDING_NATIVE_PAYLOAD',offline_validation=str(check));save(R,st)
        prep=(W/'software/.profile-system-preparation.lock').open('a');fcntl.flock(prep,fcntl.LOCK_EX)
        kr=out/'Native-kernel-build.json';fw=out/'Native-firmware-build.json'
        parent_kr=Path(prior['native_build']['kernel_receipt'])
        if not kr.exists():run_logged([sys.executable,W/'scripts/build_earlyconsole.py','Native','--parent-receipt',parent_kr,
            '--rootfs-receipt',fs_path,'--output-receipt',kr,'--build-root','/var/tmp/guozh-firesim-final-opt4-20261107-cad/system-builds'],logs/'Native-kernel.log')
        before=Path(read(parent_kr)['output_dir']);after=Path(read(kr)['output_dir'])
        strip=lambda p:[l for l in (p/'.config').read_text().splitlines() if not l.startswith('CONFIG_INITRAMFS_SOURCE=')]
        assert strip(before)==strip(after) and sha(before/'drivers/misc/ec_dac_roi.o')==sha(after/'drivers/misc/ec_dac_roi.o')
        if not fw.exists():run_logged([sys.executable,W/'scripts/build_system.py','Native','firmware','--kernel-result',kr,
            '--fdt-result',W/'software/Native/fdt-mem2g-build.json','--output-receipt',fw,'--build-root',
            '/var/tmp/guozh-firesim-final-opt4-20261107-cad/system-builds','--jobs','4','--fdt-load-address','0xbfe00000'],logs/'Native-firmware.log')
        for src,dst in [(ap,W/'software/netdedup-apps-build.json'),(fs_path,W/'software/netdedup-rootfs-build.json'),
                        (fw,W/'software/Native/netdedup-firmware-build.json')]:
            if dst.exists():assert dst.read_bytes()==src.read_bytes(),'never replace a profile'
            else:save(dst,read(src))
        st.update(status='BOUND_TO_EXISTING_NATIVE_QUEUE',apps_receipt=str(ap),rootfs_receipt=str(fs_path),
            firmware_receipt=str(fw),offline_validation=str(check),measured_server_sha256=apps['binaries']['netdedup']['sha256'],
            decoder_sha256=decoder['sha256'],ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
        save(R,st)
    except Exception as e:
        st.update(status='FAILED_WITH_EVIDENCE',error=repr(e));save(R,st);raise


if __name__=='__main__':main()
