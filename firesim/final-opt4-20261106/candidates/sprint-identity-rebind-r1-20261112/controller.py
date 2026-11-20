#!/usr/bin/python3
"""Wait only for already-owned host generation, then prepare offline identity."""
import fcntl
import json
import os
import resource
import sys
import time
from identity import C,W,D,OUT,COMMIT,prepare
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import identity,now,read,save


def main():
    OUT.mkdir(exist_ok=True)
    lock=(OUT/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (OUT/'state.json').exists(),'Adopt existing identity preparer'
    os.sched_setaffinity(0,{200,201});resource.setrlimit(resource.RLIMIT_AS,(4*2**30,)*2)
    st=dict(schema='ec-sprint-offline-identity-owner/1',**identity(),started_utc=now(),
        hardware_commit=COMMIT,no_CAD=True,fpga_access=False,new_runtime_owner=False,
        certificate_created=False,existing_handoff_modified=False)
    while True:
        result=prepare();st.update(result,updated_utc=now());save(OUT/'state.json',st)
        if not result['status'].startswith('WAITING'):
            save(OUT/'result.json',st);return
        parent=read(D/'build-logs/Opt4-sprint-composed-validate-r1-20261112/state.json')
        if parent.get('status','').startswith(('FAILED','PREREQUISITE_FAILED','INSUFFICIENT_')):
            st.update(status='UPSTREAM_VALIDATION_ENDED_WITHOUT_NEW_HOST_NO_REBIND',upstream=parent.get('status'),updated_utc=now())
            save(OUT/'state.json',st);save(OUT/'result.json',st);return
        time.sleep(300)


if __name__=='__main__':main()
