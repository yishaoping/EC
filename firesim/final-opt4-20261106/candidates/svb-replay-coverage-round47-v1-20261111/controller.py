#!/usr/bin/python3
"""Broker-only finite analysis; preserve receipts and select an idle CPU."""
from pathlib import Path
import datetime
import fcntl
import hashlib
import json
import os
import resource
import subprocess
import time
import traceback

C = Path(__file__).resolve().parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-svb-replay-coverage-round47-v1-20261111'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def save_state(value):
    temp = O/('state.json.preparing-' + str(os.getpid()))
    with temp.open('x') as stream:
        json.dump(value, stream, indent=2, sort_keys=True)
        stream.write('\n')
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(temp, O/'state.json')


def cpu_times():
    result = {}
    for line in Path('/proc/stat').read_text().splitlines():
        fields = line.split()
        if fields and fields[0][3:].isdigit():
            # Exclude guest times, already included in user/nice counters.
            values = [int(value) for value in fields[1:9]]
            result[int(fields[0][3:])] = (sum(values), values[3]+values[4])
    return result


def main():
    p = json.loads((D/'unattended-opt4/campaign-policy.json').read_text())
    assert p['functional_baseline_commit'] == '8491167d84b6d9521b151a743673c1516926a1f8'
    assert p['area_equivalence_only'] and p['native_paused'] and not p['fpga_access']
    assert not p['functional_extensions_allowed'] and p['board_allowlist'] == ['0000:21:00.0']
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    if (O/'complete.json').exists():
        assert json.loads((O/'complete.json').read_text())['result_sha256'] == sha(O/'result.json')
        print('ADOPT_IMMUTABLE_COMPLETE_ORACLE')
        return
    assert not (O/'state.json').exists(), 'preserve partial or failed analysis; use versioned recovery'
    assert not (O/'result.json').exists() and not (O/'analysis.log').exists()
    before = cpu_times()
    time.sleep(0.25)
    after = cpu_times()
    # Keep new work away from the two active CPU0-1 workloads and direct
    # component physical jobs on250-255. No existing process is moved.
    allowed = set(os.sched_getaffinity(0))
    candidates = [cpu for cpu in range(240, 250) if cpu in allowed]
    assert candidates, 'no allowed CPU in independent analysis range'
    idle = {cpu: (after[cpu][1]-before[cpu][1])/max(1, after[cpu][0]-before[cpu][0]) for cpu in candidates}
    selected = max(candidates, key=lambda cpu: (idle[cpu], -cpu))
    os.sched_setaffinity(0, {selected})
    resource.setrlimit(resource.RLIMIT_AS, (2*2**30, 2*2**30))
    state = dict(schema='ec-finite-coverage-oracle-controller/1',
                 status='RUNNING_COMPLETE_BINARY_COUNT_ANALYSIS', pid=os.getpid(),
                 start_ticks=Path('/proc/self/stat').read_text().rsplit(')', 1)[1].split()[19],
                 host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
                 cpu=selected, cpu_idle_fractions=idle, fpga_access=False,
                 no_simulation_or_cad=True,
                 updated_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
    save_state(state)
    try:
        with (O/'analysis.log').open('x') as log:
            result = subprocess.run(['/usr/bin/python3', str(C/'audit.py'), '--run'],
                                    cwd=C, stdin=subprocess.DEVNULL,
                                    stdout=log, stderr=subprocess.STDOUT, timeout=300)
        assert result.returncode == 0, ('oracle failed', result.returncode)
        assert sha(O/'result.json') == json.loads((O/'complete.json').read_text())['result_sha256']
        state.update(status='PASS_COMPLETE_BINARY_COUNT_ORACLE_NOT_REPLAY_OR_FPGA',
                     result_sha256=sha(O/'result.json'))
    except BaseException as error:
        state.update(status='FAILED_WITH_EVIDENCE', error=repr(error), traceback=traceback.format_exc())
        raise
    finally:
        state['updated_utc'] = datetime.datetime.now(datetime.timezone.utc).isoformat()
        save_state(state)


if __name__ == '__main__':
    main()
