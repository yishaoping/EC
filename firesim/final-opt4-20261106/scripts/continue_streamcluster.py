#!/usr/bin/env python3
"""Validate staged I/O on C4 after the unchanged-hardware formal batches."""
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import subprocess
import time

from board_batch import W,D,save,sha


def main():
    assert os.geteuid()==0
    lock=(D/'locks/c4-streamcluster-continuation.lock').open('a')
    fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    boot=Path('/proc/sys/kernel/random/boot_id').read_text().strip()
    path=D/'c4-streamcluster-continuation-state.json'
    receipts=dict(driver=W/'runtime/C4-efficiency-driver.json',
        firmware=W/'software/C4/streamcluster-staged-firmware-build.json',
        apps=W/'software/streamcluster-staged-apps-build.json',
        rootfs=W/'software/streamcluster-staged-rootfs-build.json')
    hashes={k:sha(p) for k,p in receipts.items()}
    state=dict(schema='ec-c4-streamcluster-continuation/1',pid=os.getpid(),host_boot_id=boot,
        status='WAITING_FOR_C4_CANNEAL_BATCH',receipt_hashes=hashes,
        receipts={k:str(p) for k,p in receipts.items()},formal_eligible=False,
        no_bitstream_build_or_deployment_operations=True)
    save(path,state)
    try:
        while True:
            prior=json.loads((D/'c4-canneal-continuation-state.json').read_text())
            if prior['status']=='COMPLETE':break
            if prior['status'] in ['STOPPED_ON_CONCRETE_FAILURE','INTERRUPTED']:
                raise RuntimeError('preceding C4 validation failed: '+prior['status'])
            state['heartbeat_utc']=dt.datetime.now(dt.timezone.utc).isoformat();save(path,state)
            time.sleep(300)
        assert all(sha(p)==hashes[k] for k,p in receipts.items())
        maintenance=(D/'locks/maintenance-0000_21_00.0.lock').open('a')
        fcntl.flock(maintenance,fcntl.LOCK_SH|fcntl.LOCK_NB)
        for inp in ['test','simsmall']:
            argv=['python3',str(W/'scripts/run_isolated_sample.py'),'C4','streamcluster',inp,
                  '--bdf','0000:21:00.0','--timeout','3600']
            for k,p in receipts.items():argv+=['--'+k+'-receipt',str(p)]
            log=D/('c4-streamcluster-staged-'+inp+'-launch.log')
            state.update(status='RUNNING',input=inp,log=str(log));save(path,state)
            with log.open('ab',buffering=0) as stream:
                child=subprocess.Popen(argv,cwd=W,stdin=subprocess.DEVNULL,
                    stdout=stream,stderr=subprocess.STDOUT,start_new_session=True)
                state['child_pid']=child.pid;save(path,state);rc=child.wait()
            state.setdefault('completed',[]).append(dict(input=inp,returncode=rc,log=str(log)))
            save(path,state)
            assert rc==0,(inp,rc,str(log))
        state.update(status='COMPLETE_FUNCTIONAL_ONLY',ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    except Exception as exc:
        state.update(status='STOPPED_ON_CONCRETE_FAILURE',error=repr(exc),ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
        raise
    finally:save(path,state)


if __name__=='__main__':main()
