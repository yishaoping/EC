#!/usr/bin/python3
"""Serial exact area successor; wait without occupying validator CPU pins."""
from pathlib import Path
import fcntl
import importlib.util
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D / 'build-logs/Opt4-address-banked-production-area-pair-r2-20261113'
sys.path.insert(0, str(W / 'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha
spec = importlib.util.spec_from_file_location('direct_host_area', W / 'candidates/address-banked-production-area-pair-r1-20261112/controller.py')
p = importlib.util.module_from_spec(spec)
spec.loader.exec_module(p)
p.P = D / 'build-logs/Opt4-address-banked-production-host-r2-20261113'
p.O, p.m.O = O, O
p.SOURCE = C
p.UNIT = 'ec-opt4-address-banked-production-host-r2-20261113.service'


def main():
    O.mkdir(exist_ok=True)
    lock = (O / 'waiter.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not (O / 'state.json').exists(), 'Adopt exact area owner'
    binding = read(C / 'source-binding.json')
    assert binding['files'][str(C / 'area.py')] == sha(C / 'area.py')
    while True:
        state, result = read(p.P / 'state.json'), read(p.P / 'result.json')
        if result.get('status') == p.PASS and not live(state) and not p.owner_members():
            break
        if state.get('status', '').startswith('FAILED'):
            save(O / 'state.json', dict(schema='ec-production-direct-host-area/1', **identity(),
                status='PREREQUISITE_FAILED_NO_AREA_STARTED', updated_utc=now(),
                predecessor=str(p.P / 'failure.json'), fpga_access=False, full_system_fit=False))
            return
        save(O / 'queue.json', dict(schema='ec-production-direct-host-area-queue/1', **identity(),
            status='WAITING_EXACT_NEW_VALIDATOR_AND_CGROUP_RELEASE', updated_utc=now(),
            prerequisite=str(p.P / 'state.json'), prerequisite_status=state.get('status'),
            own_CPU_affinity_unrestricted=True, no_CAD_started=True,
            source_binding_sha256=sha(C / 'source-binding.json')))
        time.sleep(30)
    p.main()


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if p.m.ST:
            p.m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED', error=repr(exc), ended_utc=now())
            p.save(O / 'failure.json', p.m.ST)
        raise
