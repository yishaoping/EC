#!/usr/bin/env python3
"""Finite build continuation, not a periodic agent or CAD-status patrol.

Prepare both complete Golden Gate targets on two CPUs. Then admit the combined
candidate first, and the BJL-only attribution build second, serially behind
both existing CAD leases. This script never places, routes or accesses FPGA.
"""
import datetime as dt
import json
import os
from pathlib import Path
import subprocess
import sys

C = Path(__file__).resolve().parent
O = Path(sys.argv[1]).resolve()


def save(value):
    value['utc'] = dt.datetime.now(dt.timezone.utc).isoformat()
    p = O/'queue-state.json'
    tmp = p.with_suffix('.tmp')
    tmp.write_text(json.dumps(value, indent=2)+'\n')
    os.replace(tmp, p)


def main():
    os.sched_setaffinity(0, {248, 249})
    os.nice(19)
    O.mkdir(parents=True, exist_ok=False)
    state = dict(profile='EC Performance-Only', fpga_access=False,
                 full_physical_implementation=False, stages=[])
    prepared = []
    for profile in ['bjl-result-cdc', 'bjl']:
        output = O/('full-'+profile)
        item = dict(stage='prepare', variant=profile, output=str(output), status='RUNNING')
        state['stages'].append(item)
        save(state)
        argv = [sys.executable, '-I', str(C/'full.py'), str(output), profile]
        with (O/(profile+'-prepare.log')).open('xb') as log:
            p = subprocess.run(argv, stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT)
        item.update(returncode=p.returncode, status='PREPARED' if p.returncode == 0 else 'FAILED_WITH_EVIDENCE')
        save(state)
        if p.returncode == 0:
            prepared.append((profile, output))
    for profile, output in prepared:
        item = dict(stage='serial-postopt', variant=profile, output=str(output),
                    status='WAITING_LEASES_THEN_POSTOPT')
        state['stages'].append(item)
        save(state)
        argv = [sys.executable, '-I', str(C/'full.py'), str(output), profile,
                '--queue-postopt', '--postopt-only']
        with (O/(profile+'-postopt.log')).open('xb') as log:
            p = subprocess.run(argv, stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT)
        item.update(returncode=p.returncode, status='POSTOPT_COMPLETE' if p.returncode == 0 else 'FAILED_WITH_EVIDENCE')
        save(state)
    state['status'] = ('COMPLETE_POSTOPT_NOT_PHYSICALLY_IMPLEMENTED'
        if len(state['stages']) == 4 and all(x['returncode'] == 0 for x in state['stages'])
        else 'FINISHED_WITH_FAILURE_EVIDENCE')
    save(state)


if __name__ == '__main__':
    main()
