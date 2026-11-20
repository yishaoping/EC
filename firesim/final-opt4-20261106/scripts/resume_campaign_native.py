#!/usr/bin/env python3
"""After verified interruption, restore the certified Native card and resume only missing samples."""
import json
import subprocess
from pathlib import Path
from board_batch import W,D

def call(args):subprocess.run(list(map(str,args)),cwd=W,check=True)
def main():
    cad=json.loads((D/'C4-runtime-cad-state.json').read_text())
    if cad['status']=='BUILT_NOT_RUN':return
    boot=Path('/proc/sys/kernel/random/boot_id').read_text().strip()
    deployment=json.loads((D/'latest-deployment.json').read_text())
    cards=deployment.get('completed_cards',[])
    if deployment.get('host_boot_id')!=boot or not any(c.get('configuration')=='Native' and c['bdf']=='0000:21:00.0' for c in cards):
        call(['python3',W/'scripts/board_batch.py','--deploy-only','--single-native-bdf','0000:21:00.0'])
        call(['python3',W/'scripts/run_isolated_sample.py','Native','smoke','test','--bdf','0000:21:00.0','--driver-receipt',W/'runtime/Native-efficiency-driver.json','--firmware-receipt',W/'software/Native/reboot-firmware-build.json','--apps-receipt',W/'software/formal-apps-build.json','--rootfs-receipt',W/'software/formal-rootfs-build.json','--timeout','600'])
    call(['python3',W/'scripts/suite_queue.py','Native'])
if __name__=='__main__':main()
