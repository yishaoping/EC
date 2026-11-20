#!/usr/bin/env python3
"""Publish only new, offline-validated network software to the existing queue.

No scheduler/driver/hardware changes. Old profiles, failures and samples remain.
"""
import copy
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
import time
from board_batch import W,D,save,sha
from job_service import proc
from prepare_network_native import run_logged
sys.path.insert(0,'/data1/gzh/EC/firesim/dac2026/scripts')
from prepare_boot_prerequisite import cpio_newc

R=D/'software/network-native-wait-profile.json'


def read(p):
    return json.loads(Path(p).read_text())


def main():
    lock=(D/'software/network-native-wait-profile.lock').open('a')
    fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    st=read(R) if R.exists() else {}
    if st.get('status')=='NETSTREAMCLUSTER_BOUND_NETFERRET_READY_UNBOUND':return
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    st.update(pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],
        host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
        status='WAITING_OFFLINE_CASES',hardware_modified=False,scheduler_modified=False)
    save(R,st)
    while True:
        q=read(D/'software/network-native-wait-diagnosis.json')
        if q['status']=='COMPLETE_OFFLINE_REVIEW_REQUIRED':break
        time.sleep(60)
    required=['netstreamcluster-'+s+'-joined-icount'+('5' if s=='test' else 'None') for s in ['test','simsmall','simmedium']]
    required+=['netferret-'+s+'-baseline-icountNone' for s in ['simsmall','simmedium']]
    assert all(q['cases'][n]['status']=='OFFLINE_PASSED' and all(q['cases'][n]['gates'].values()) for n in required)
    parent=W/'software/netferret-apps-build.json';base=read(parent)
    out=Path(st.setdefault('output_dir',str(W/'software'/('network-native-wait-profile-'+stamp))))
    logs=Path(st.setdefault('log_dir',str(D/'software'/out.name)))
    out.mkdir(exist_ok=True);logs.mkdir(exist_ok=True)
    apps=copy.deepcopy(base)
    apps.update(output_dir=str(out),software_profile='network-full-original-roi-wait-evidence/2',
        parent_receipt=str(parent),parent_receipt_sha256=sha(parent),
        repair_evidence=dict(path=str(D/'software/network-native-wait-diagnosis.json'),
                            sha256=sha(D/'software/network-native-wait-diagnosis.json')),
        version_delta='Netferret ELF unchanged; Netstreamcluster joins original receive workers before stack queue leaves scope; unchanged outer ROI hook sites and complete computation; failure-only logs/task capture',
        fpga_validation='NOT_RUN',status='OFFLINE_VALIDATED_FPGA_PENDING')
    names=['netferret','netstreamcluster']
    apps['binaries']={n:b for n,b in base['binaries'].items() if n in names+[n+'client' for n in names]}
    apps['binaries']['netstreamcluster']={k:v for k,v in q['builds']['real-hooks'].items() if k in ['path','sha256']}
    apps['cases']=[c for c in apps['cases'] if c['program'] in names]
    for c in apps['cases']:
        c['fpga_validation']='NOT_RUN'
        if c['program']=='netstreamcluster':
            c['software_repair']='Receive lifetime join, same computation/input/original ROI sites; full ACK/close work retained'
            c['software_patch']=q['candidate_patch']
        src=Path(base['output_dir'])/'inputs'/c['program']/c['input']
        dst=out/'inputs'/c['program']/c['input']
        if not dst.exists():shutil.copytree(src,dst)
        assert {str(p.relative_to(dst)):sha(p) for p in dst.rglob('*') if p.is_file()}==c['input_files']
    ap=out/'apps-build.json'
    if ap.exists():assert read(ap)==apps
    else:save(ap,apps)
    fs_path=out/'rootfs-build.json'
    if not fs_path.exists():run_logged([sys.executable,W/'scripts/prepare_rootfs.py','--apps-receipt',ap,'--output-receipt',fs_path],logs/'rootfs.log')
    fs=read(fs_path)
    if 'network_launcher_sha256' not in fs:
        tree=Path(fs['path']).parent/'tree';dst=tree/'opt/ec-fpga'
        shell=dst/'run-one';text=shell.read_text();anchor='  /opt/ec-fpga/$program $argv >console.pipe 2>&1'
        assert text.count(anchor)==1
        shell.write_text(text.replace(anchor,'  /opt/ec-fpga/run-network "$program" "$input" >console.pipe 2>&1'))
        wrapper=Path(q['failure_capture']['path']);assert sha(wrapper)==q['failure_capture']['sha256']
        shutil.copy2(wrapper,dst/'run-network')
        for c in apps['cases']:(dst/'cases'/c['program']/c['input']/'client-argv').write_text(' '.join(c['client_argv'])+'\n')
        for p in [shell,dst/'run-network']:subprocess.run(['/bin/sh','-n',str(p)],check=True)
        (dst/'SHA256SUMS').write_text(''.join(sha(p)+'  '+str(p.relative_to(dst))+'\n' for p in sorted(dst.rglob('*')) if p.is_file() and p.name!='SHA256SUMS'))
        image=tree.parent/'initramfs-network.cpio';cpio_newc(tree,image)
        fs.update(path=str(image),sha256=sha(image),bytes=image.stat().st_size,shared_by=['Native'],
            files={str(p.relative_to(tree)):sha(p) for p in tree.rglob('*') if p.is_file()},
            network_launcher_sha256=sha(dst/'run-network'))
        save(fs_path,fs);save(image.parent/'manifest.json',fs)
    assert sha(fs['path'])==fs['sha256'] and fs['apps_manifest_sha256']==sha(ap)
    st.update(status='BUILDING_NATIVE_PAYLOAD',apps_receipt=str(ap),rootfs_receipt=str(fs_path));save(R,st)
    prep=(W/'software/.profile-system-preparation.lock').open('a');fcntl.flock(prep,fcntl.LOCK_EX)
    kr=out/'Native-kernel-build.json';fw=out/'Native-firmware-build.json'
    previous=read(D/'software/network-native-preparation.json')
    parent_kr=Path(previous['native_build']['kernel_receipt'])
    if not kr.exists():run_logged([sys.executable,W/'scripts/build_earlyconsole.py','Native','--parent-receipt',parent_kr,
        '--rootfs-receipt',fs_path,'--output-receipt',kr,'--build-root','/var/tmp/guozh-firesim-final-opt4-20261107-cad/system-builds'],logs/'Native-kernel.log')
    before=Path(read(parent_kr)['output_dir']);after=Path(read(kr)['output_dir'])
    strip=lambda p:[l for l in (p/'.config').read_text().splitlines() if not l.startswith('CONFIG_INITRAMFS_SOURCE=')]
    assert strip(before)==strip(after) and sha(before/'drivers/misc/ec_dac_roi.o')==sha(after/'drivers/misc/ec_dac_roi.o')
    if not fw.exists():run_logged([sys.executable,W/'scripts/build_system.py','Native','firmware','--kernel-result',kr,
        '--fdt-result',W/'software/Native/fdt-mem2g-build.json','--output-receipt',fw,'--build-root',
        '/var/tmp/guozh-firesim-final-opt4-20261107-cad/system-builds','--jobs','2','--fdt-load-address','0xbfe00000'],logs/'Native-firmware.log')
    assert read(fw)['returncode']==0
    prefixes={'netstreamcluster':'netstreamcluster-receivers-joined-v2','netferret':'netferret-failure-evidence-v2'}
    for name,prefix in prefixes.items():
        for src,dst in [(ap,W/f'software/{prefix}-apps-build.json'),(fs_path,W/f'software/{prefix}-rootfs-build.json'),
                        (fw,W/f'software/Native/{prefix}-firmware-build.json')]:
            if dst.exists():assert dst.read_bytes()==src.read_bytes()
            else:save(dst,read(src))
    gate=(D/'locks/future-software-plan-update.lock').open('a');fcntl.flock(gate,fcntl.LOCK_EX)
    # Do not replace the inputs of an active sample. The only change here is
    # one not-yet-started plan entry; existing coverage-first remains sole owner.
    active=read(D/'active-0000_21_00.0.json')
    assert not(active.get('program')=='netstreamcluster' and active.get('status') in ['RUNNING','STARTING'])
    planpath=D/'suite-execution-plan.json';plan=read(planpath)
    row=next(r for r in plan['programs'] if r['program']=='netstreamcluster')
    assert row['software_profile_prefix'] in ['netstreamcluster',prefixes['netstreamcluster']]
    old=sha(planpath);archive=D/'plan-history'/('before-netstreamcluster-receive-join-'+stamp+'.json');save(archive,plan)
    row['software_profile_prefix']=prefixes['netstreamcluster'];save(planpath,plan)
    st.update(status='NETSTREAMCLUSTER_BOUND_NETFERRET_READY_UNBOUND',firmware_receipt=str(fw),
        old_plan_sha256=old,new_plan_sha256=sha(planpath),plan_archive=str(archive),
        kernel_config_unchanged_except_initramfs=True,roi_driver_object_unchanged=True,
        hardware_build=False,fpga_started_by_this_service=False,
        netferret_note='Improved failure-evidence profile prepared but not bound; keep new Netstreamcluster FPGA test first, then inspect Netferret exact-ELF stall',
        next_action='Existing coverage-first starts Netstreamcluster test, then small/formal only if valid; C4 still outranks Native at every safe boundary',
        ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(R,st)


if __name__=='__main__':main()
