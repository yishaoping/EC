#!/usr/bin/env python3
"""Serialize firmware-only repairs and real boot/integrity diagnostics."""
import json
import subprocess
import time
from board_batch import W,D,save

def main():
    path=D/'software/large-payloads-preparation.json'
    state=dict(status='RUNNING',profiles={});save(path,state)
    for parent in ['dedup-staged','facesim-staged-resident','ferret','raytrace-headless']:
        profile=parent+'-safe-fdt'
        if parent=='dedup-staged':
            receipt=D/f'software/{profile}-system-preparation.json';deadline=time.monotonic()+600
            while time.monotonic()<deadline:
                r=json.loads(receipt.read_text()) if receipt.exists() else {}
                if r.get('status') in ['READY_FOR_FPGA_NOT_RUN','FAILED_WITH_EVIDENCE']:break
                time.sleep(5)
            assert r.get('status')=='READY_FOR_FPGA_NOT_RUN',r
        else:subprocess.run(['python3',W/'scripts/prepare_safe_fdt_profile.py',parent],check=True)
        subprocess.run(['python3',W/'scripts/diagnose_dedup_boot.py','--profile',profile,'--bios-kind','firmware-jump'],check=True)
        result=D/f'software/{profile}-boot-diagnostic.json';r=json.loads(result.read_text())
        state['profiles'][profile]=dict(software_boot_integrity_passed=r.get('qemu_integrity_passed'),receipt=str(result),fpga_validation='NOT_RUN')
        save(path,state)
    state['status']='COMPLETE';save(path,state)

if __name__=='__main__':main()
