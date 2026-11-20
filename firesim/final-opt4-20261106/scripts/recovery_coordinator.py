#!/usr/bin/env python3
"""Order future boot recovery; never restart, stop, or migrate an active service."""
import json
from pathlib import Path
import subprocess
import time
from board_batch import D,save

BOOT=Path('/proc/sys/kernel/random/boot_id').read_text().strip()
def read(name):
    p=D/name
    return json.loads(p.read_text()) if p.exists() else {}
def active(name):return subprocess.run(['systemctl','is-active','--quiet','ec-parsec-'+name+'.service']).returncode==0
def start(name):
    if active(name):return 'ADOPT_EXISTING_ACTIVE_SERVICE'
    subprocess.run(['systemctl','start','ec-parsec-'+name+'.service'],check=True)
    return 'START_AFTER_IDENTITY_GATE'
def wait_current(path,seconds=180):
    deadline=time.monotonic()+seconds
    while time.monotonic()<deadline:
        state=read(path)
        if state.get('host_boot_id')==BOOT and state.get('status') not in ['INTERRUPTED','FAILED','STARTUP']:
            return state
        time.sleep(2)
    return read(path)
def main():
    state=dict(host_boot_id=BOOT,status='STARTING',actions={})
    state['actions']['cad']=start('cad');save(D/'jobs/recovery-coordinator/checkpoint.json',state)
    cad=wait_current('C4-runtime-cad-state.json');state['cad_status']=cad.get('status')
    # Native can still make progress if a concrete CAD failure needs review.
    state['actions']['native']=start('native')
    if cad.get('host_boot_id')==BOOT and cad.get('status') in ['RUNNING','STARTING','BUILT_NOT_RUN']:
        state['actions']['c4-first']=start('c4-first')
        first=wait_current('fpga-continuation-state.json');state['c4_first_status']=first.get('status')
        if first.get('host_boot_id')==BOOT:state['actions']['c4-suite']=start('c4-suite')
    for name in ['publisher','cad-monitor']:state['actions'][name]=start(name)
    state['status']='SERVICES_ADOPTED_OR_STARTED';save(D/'jobs/recovery-coordinator/checkpoint.json',state)
    print(json.dumps(state),flush=True)
if __name__=='__main__':main()
