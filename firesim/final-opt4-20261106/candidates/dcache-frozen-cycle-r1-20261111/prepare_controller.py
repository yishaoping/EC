#!/usr/bin/python3
"""Light brokered RTL preparation only. The separate module job compiles/runs."""
import datetime
import fcntl
import json
import os
from pathlib import Path
from prepare import C, D, COMMIT, SID, policy, generate

S = D / 'Opt4-fit-dcache-frozen-cycle-prep-r1-state.json'


def save(j):
    p = S.with_name(S.name + '.tmp-' + str(os.getpid()))
    with p.open('w') as f:
        json.dump(j, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())
    os.replace(p, S)


def main():
    policy()
    lock = (C / 'prepare.instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not S.exists(), 'preserve partial preparation; use reviewed new version'
    stat = Path(f'/proc/{os.getpid()}/stat').read_text().rsplit(')', 1)[1].split()
    state = dict(schema='ec-opt4-complete-dcache-cycle-preparation-controller/1',
                 hardware_commit=COMMIT, source_id=SID, pid=os.getpid(), start_ticks=stat[19],
                 host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
                 status='PREPARING_COMPLETE_FROZEN_MODULE_CLOSURES', fpga_access=False,
                 started_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
    save(state)
    try:
        receipt = generate(C / 'prepared')
        state.update(status='COMPLETE_AUTHENTICATED_FROZEN_AND_CANDIDATE_MODULE_CLOSURES_NOT_YET_COMPILED',
                     compared_signals=receipt['compared_signals'], compared_bits=receipt['compared_bits'],
                     ended_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
        save(state)
    except Exception as exc:
        state.update(status='FAILED_WITH_EVIDENCE', error=repr(exc),
                     ended_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
        save(state)
        raise


if __name__ == '__main__':
    main()
