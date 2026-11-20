#!/usr/bin/python3
"""Finite broker analysis; adopt immutable evidence and keep live jobs intact."""
import datetime
import fcntl
import json
import os
from pathlib import Path
import resource
import subprocess

C = Path(__file__).resolve().parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
STATE = D/'Opt4-owner-channel-composition-round50-v2-state.json'
O = D/'build-logs/Opt4-owner-channel-composition-round50-v2-20261111'


def atomic_state(value):
    value = {**value, 'updated_utc': datetime.datetime.now(datetime.timezone.utc).isoformat()}
    temp = STATE.with_name(STATE.name+'.tmp-'+str(os.getpid()))
    with temp.open('x') as stream:
        stream.write(json.dumps(value, sort_keys=True, indent=2)+'\n')
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(temp, STATE)


def main():
    policy = json.loads((D/'unattended-opt4/campaign-policy.json').read_text())
    assert policy['functional_baseline_commit'] == '8491167d84b6d9521b151a743673c1516926a1f8'
    assert policy['area_equivalence_only'] and not policy['fpga_access'] and policy['native_paused']
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    if (O/'complete.json').exists():
        subprocess.run(['/usr/bin/python3', str(C/'audit.py'), '--run'], check=True)
        return
    assert not (O/'analysis.log').exists(), 'preserve partial stage; use versioned recovery'
    allowed = set(os.sched_getaffinity(0)) & set(range(240, 250))
    assert allowed, 'no independent analysis CPU'
    os.sched_setaffinity(0, {max(allowed)})
    resource.setrlimit(resource.RLIMIT_AS, (2*2**30, 2*2**30))
    stat = Path('/proc/self/stat').read_text().rsplit(')', 1)[1].split()
    state = dict(status='RUNNING_READ_ONLY_OWNER_CHANNEL_AUDIT', pid=os.getpid(),
                 start_ticks=stat[19], host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
                 fpga_access=False, cpus=sorted(os.sched_getaffinity(0)))
    (O/'started.json').write_text(json.dumps(state, sort_keys=True, indent=2)+'\n')
    atomic_state(state)
    with (O/'analysis.log').open('x') as log:
        r = subprocess.run(['/usr/bin/python3', str(C/'audit.py'), '--run'], cwd=C,
                           stdout=log, stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL, timeout=300)
    if r.returncode:
        atomic_state({**state, 'status':'FAILED_WITH_EVIDENCE', 'returncode':r.returncode})
        raise AssertionError(('analysis failed; original logs preserved', r.returncode))
    atomic_state({**state, 'status':'PASS_EXACT_OWNER_CHANNEL_WIRING_NOT_FULL_EQUIVALENCE', 'result':str(O/'result.json'), 'complete':str(O/'complete.json')})


if __name__ == '__main__':
    main()
