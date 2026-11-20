#!/usr/bin/env python3
"""Rebuild firmware alone with a DTB address clear of large embedded initramfs."""
import argparse
import json
from pathlib import Path
import shutil
import subprocess
from board_batch import W,D,save,sha

def main():
    parser=argparse.ArgumentParser();parser.add_argument('parent');a=parser.parse_args()
    assert a.parent.replace('-','').isalnum();profile=a.parent+'-safe-fdt'
    state=dict(status='RUNNING',parent=a.parent,profile=profile,runtime_fdt_address=hex(0xbfe00000),
               kernel_rebuild=False,bitstream_rebuild=False,application_changes=False,configurations={})
    receipt=D/f'software/{profile}-system-preparation.json';save(receipt,state)
    try:
        for suffix in ['apps','rootfs']:
            parent=W/f'software/{a.parent}-{suffix}-build.json';target=W/f'software/{profile}-{suffix}-build.json'
            if not target.exists():shutil.copy2(parent,target)
            assert sha(parent)==sha(target)
        for cfg in ['Native','C4']:
            parent=W/f'software/{cfg}/{a.parent}-kernel-build.json';kernel=W/f'software/{cfg}/{profile}-kernel-build.json'
            if not kernel.exists():shutil.copy2(parent,kernel)
            assert sha(parent)==sha(kernel)
            fw=W/f'software/{cfg}/{profile}-firmware-build.json'
            if not fw.exists():
                log=D/f'software/{profile}-{cfg}-firmware.log'
                with log.open('ab',buffering=0) as f:
                    subprocess.run(['python3',W/'scripts/build_system.py',cfg,'firmware','--kernel-result',kernel,
                                    '--fdt-result',W/f'software/{cfg}/fdt-mem2g-build.json','--output-receipt',fw,
                                    '--build-root','/var/tmp/guozh-firesim-final-opt4-20261107-cad/system-builds',
                                    '--jobs','4','--fdt-load-address','0xbfe00000'],stdout=f,stderr=subprocess.STDOUT,check=True)
            firmware=json.loads(fw.read_text());assert firmware['returncode']==0
            assert firmware['content_checks']['runtime_memory_layout']['fdt_copy_start']==0xbfe00000
            state['configurations'][cfg]=dict(kernel_receipt=str(kernel),kernel_receipt_sha256=sha(kernel),firmware_receipt=str(fw),firmware_receipt_sha256=sha(fw))
            save(receipt,state)
        state['status']='READY_FOR_FPGA_NOT_RUN'
    except Exception as exc:state.update(status='FAILED_WITH_EVIDENCE',error=repr(exc));raise
    finally:save(receipt,state)

if __name__=='__main__':main()
