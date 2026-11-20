#!/usr/bin/env python3
"""After the first valid C4 batch, reuse its deployment for matched Canneal."""
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import subprocess
import time

from board_batch import W, D, save, sha


def main():
    assert os.geteuid() == 0
    lock = (D/'locks/c4-canneal-continuation.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    output = D/'c4-canneal-continuation-state.json'
    boot = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
    receipts = dict(driver=W/'runtime/C4-efficiency-driver.json',
                    firmware=W/'software/C4/canneal-formal-firmware-build.json',
                    apps=W/'software/canneal-formal-apps-build.json',
                    rootfs=W/'software/canneal-formal-rootfs-build.json')
    hashes = {k: sha(p) for k, p in receipts.items()}
    state = dict(schema='ec-c4-canneal-continuation/1', pid=os.getpid(), host_boot_id=boot,
                 started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
                 receipts={k: str(p) for k,p in receipts.items()}, receipt_hashes=hashes,
                 status='WAITING_FOR_VALID_C4_BLACKSCHOLES_BATCH',
                 no_bitstream_build_or_deployment_operations=True)
    save(output,state)
    try:
        while True:
            assert Path('/proc/sys/kernel/random/boot_id').read_text().strip() == boot
            parent = json.loads((D/'fpga-continuation-state.json').read_text())
            if parent.get('status') == 'C4_INITIAL_BATCH_COMPLETE':
                break
            if parent.get('status') in ['STOPPED_ON_CONCRETE_FAILURE','INTERRUPTED','C4_INITIAL_BATCH_FINISHED_WITH_FAILURES']:
                raise RuntimeError('C4 first batch did not meet functional/performance gates: '+parent['status'])
            state['heartbeat_utc']=dt.datetime.now(dt.timezone.utc).isoformat()
            save(output,state)
            time.sleep(300)
        assert all(sha(p)==hashes[k] for k,p in receipts.items())
        # Prevent any global maintenance while this software-only batch runs.
        maintenance=(D/'locks/maintenance-0000_21_00.0.lock').open('a')
        fcntl.flock(maintenance,fcntl.LOCK_SH|fcntl.LOCK_NB)
        def run(label,argv):
            log=D/(label+'-launch.log')
            state.update(status='RUNNING',stage=label,log=str(log))
            save(output,state)
            with log.open('ab',buffering=0) as stream:
                child=subprocess.Popen(argv,cwd=W,stdin=subprocess.DEVNULL,
                    stdout=stream,stderr=subprocess.STDOUT,start_new_session=True)
                state['child_pid']=child.pid
                save(output,state)
                rc=child.wait()
            state.setdefault('completed',[]).append(dict(stage=label,returncode=rc,log=str(log)))
            save(output,state)
            assert rc==0,(label,rc,str(log))
        common=['--bdf','0000:21:00.0']
        for k,p in receipts.items():common+=['--'+k+'-receipt',str(p)]
        run('c4-canneal-profile-simsmall',['python3',str(W/'scripts/run_isolated_sample.py'),
             'C4','canneal','simsmall','--timeout','3600',*common])
        run('c4-canneal-formal-repetitions',['python3',str(W/'scripts/run_repetitions.py'),
             'C4','--program','canneal','--input','simmedium','--repetitions','3','--timeout','3600',*common])
        state.update(status='COMPLETE',ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    except Exception as exc:
        state.update(status='STOPPED_ON_CONCRETE_FAILURE',error=repr(exc),ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
        raise
    finally:
        save(output,state)


if __name__=='__main__':main()
