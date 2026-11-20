#!/usr/bin/python3
"""Run immutable r1 recovery with stricter in-memory cgroup admission."""
import argparse
import fcntl
import json
import os
from pathlib import Path
from guard import C,R1,verify,module,save,sha,now,identity,read


def main():
    ap=argparse.ArgumentParser()
    ap.add_argument('--producer',choices=['original','spread'],required=True)
    ap.add_argument('--mode',choices=['postroute','replicate'],required=True)
    ap.add_argument('--run',action='store_true')
    args=ap.parse_args()
    pins=verify();m=module()
    row=m.eligibility(args.producer,args.mode)
    if not args.run:
        print(json.dumps(row,indent=2));return
    assert row['eligible'],row
    out=m.OUTPUT/(args.producer+'-'+args.mode)
    out.mkdir(exist_ok=True)
    lock=(out/'strict-r2-instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (out/'state.json').exists() and not (out/'strict-r2-admission.json').exists(),'preserve attempt evidence'
    save(out/'strict-r2-admission.json',dict(schema='ec-exact-cgroup-recovery-admission/2',
         utc=now(),**identity(),eligibility=row,inputs=str(C/'inputs.json'),inputs_sha256=sha(C/'inputs.json'),
         original_recovery_inputs_sha256=sha(R1/'inputs.json'),unknown_tasks_count_not_used=True,
         exact_systemd_cgroup='/system.slice/'+row['unit'],fpga_access=False))
    try:m.run(args.producer,args.mode)
    except Exception as e:
        prior=read(out/'state.json')
        if not prior or prior.get('pid')==os.getpid():
            prior.update(status='FAILED_WITH_EVIDENCE',error=repr(e),updated_utc=now(),**identity())
            save(out/'state.json',prior);save(out/'failure-r2.json',prior)
        raise


if __name__=='__main__':main()
