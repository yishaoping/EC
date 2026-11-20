#!/usr/bin/env python3
"""Reuse existing kernel/ROI objects; bind one application profile in both payloads."""
import argparse
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import subprocess
from board_batch import W,D,save,sha


def main():
    p=argparse.ArgumentParser();p.add_argument('profile');a=p.parse_args()
    profile=a.profile
    assert profile.replace('-','').isalnum()
    # Serialize these short incremental builds; build_system itself uses a
    # nonblocking lock, so independent application preparation must queue here.
    preparation=(W/'software/.profile-system-preparation.lock').open('a')
    fcntl.flock(preparation,fcntl.LOCK_EX)
    root=Path('/var/tmp/guozh-firesim-final-opt4-20261107-cad/system-builds')
    apps=W/f'software/{profile}-apps-build.json'
    assert apps.exists()
    state=dict(status='RUNNING',pid=os.getpid(),profile=profile,started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),commands=[])
    output=D/f'software/{profile}-system-preparation.json'
    save(output,state)
    def run(argv,label):
        argv=list(map(str,argv));log=D/f'software/{profile}-{label}-build.log'
        state.update(stage=label,log=str(log));state['commands'].append(argv);save(output,state)
        with log.open('ab',buffering=0) as f:
            child=subprocess.Popen(argv,cwd=W,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
            state['child_pid']=child.pid;save(output,state)
            rc=child.wait()
        assert rc==0,(label,rc,str(log))
    try:
        rootfs=W/f'software/{profile}-rootfs-build.json'
        if not rootfs.exists():run(['python3',W/'scripts/prepare_rootfs.py','--apps-receipt',apps,'--output-receipt',rootfs],'rootfs')
        fs=json.loads(rootfs.read_text());assert fs['apps_manifest_sha256']==sha(apps) and sha(fs['path'])==fs['sha256']
        # Validate generated guest shell before embedding it in either payload.
        shell=Path(fs['path']).parent/'tree/opt/ec-fpga/run-one'
        subprocess.run(['/bin/sh','-n',str(shell)],check=True)
        reuse=[]
        for cfg in ['Native','C4']:
            parent=W/f'software/{cfg}/canneal-formal-kernel-build.json'
            kernel=W/f'software/{cfg}/{profile}-kernel-build.json'
            if not kernel.exists():run(['python3',W/'scripts/build_earlyconsole.py',cfg,'--parent-receipt',parent,'--rootfs-receipt',rootfs,'--output-receipt',kernel,'--build-root',root],cfg+'-kernel')
            old=json.loads(parent.read_text());new=json.loads(kernel.read_text())
            oldout=Path(old['output_dir']);newout=Path(new['output_dir'])
            assert sha(oldout/'drivers/misc/ec_dac_roi.o')==sha(newout/'drivers/misc/ec_dac_roi.o')
            def config(path):return [l for l in path.read_text().splitlines() if not l.startswith('CONFIG_INITRAMFS_SOURCE=')]
            assert config(oldout/'.config')==config(newout/'.config'), 'unexpected kernel configuration change'
            reuse.append(dict(configuration=cfg,parent_receipt=str(parent),kernel_receipt=str(kernel),roi_driver_object_sha256=sha(newout/'drivers/misc/ec_dac_roi.o'),config_equal_except_initramfs=True))
            fw=W/f'software/{cfg}/{profile}-firmware-build.json'
            if not fw.exists():run(['python3',W/'scripts/build_system.py',cfg,'firmware','--kernel-result',kernel,'--fdt-result',W/f'software/{cfg}/fdt-mem2g-build.json','--output-receipt',fw,'--build-root',root,'--jobs','8'],cfg+'-firmware')
            firmware=json.loads(fw.read_text());assert firmware['returncode']==0
            assert sha(Path(firmware['output_dir'])/'platform/generic/firmware/fw_payload.elf')==firmware['outputs'][str(Path(firmware['output_dir'])/'platform/generic/firmware/fw_payload.elf')]
        state.update(status='READY_FOR_FPGA_NOT_RUN',reuse=reuse,apps_receipt=str(apps),rootfs_receipt=str(rootfs),ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    except Exception as exc:
        state.update(status='FAILED',error=repr(exc));raise
    finally:save(output,state)
    print(json.dumps(state),flush=True)


if __name__=='__main__':main()
