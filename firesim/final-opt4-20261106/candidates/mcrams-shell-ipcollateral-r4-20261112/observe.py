#!/usr/bin/python3
"""Observe existing r3; submit one unprivileged repair only after actual failure."""
import fcntl
import json
import time
import prepare as p


def main():
    p.verify()
    m = p.module('r2_repair_observer_io', p.R2 / 'physical.py')
    out = p.D / 'mcrams-shell-ipcollateral-r4-observer-20261112'
    out.mkdir(exist_ok=True)
    lock = (out / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    state = dict(schema='ec-mcrams-conditional-IPcollateral-recovery/4',
        **m.ident(), started_utc=m.now(), no_DUT_resynthesis=True,
        fpga_access=False, active_r3_source_unchanged=True)
    while True:
        path = p.D / 'Opt4-mcrams-shell-physical-r2-state.json'
        previous = p.read(path) if path.exists() else {}
        state.update(status='WAITING_ACTUAL_R3_CLOCK_FAILURE_NO_CAD', updated_utc=m.now(),
            predecessor_status=previous.get('status'))
        if previous.get('status') == 'FAILED_WITH_EVIDENCE':
            # A controller's terminal state can precede the enclosing job's
            # exit. Wait for identities and the exact cgroup to release.
            if m.live(previous) or m.live(previous.get('child', {})):
                m.save(out / 'state.json', state)
                time.sleep(300)
                continue
            try:
                p.admit_failed_r3_identity_only()
            except BlockingIOError:
                m.save(out / 'state.json', state)
                time.sleep(300)
                continue
            except AssertionError as exc:
                state.update(status='PREDECESSOR_FAILURE_RETAINED_REQUIRES_INDEPENDENT_REVIEW',
                    reason=repr(exc), no_repair_submitted=True)
                m.save(out / 'state.json', state)
                return
            p.verify()
            name = 'mcrams-shell-ipcollateral-r4-3656aec4'
            pins = p.read(p.C / 'inputs.json')
            inputs = dict(pins['files'])
            inputs[str(p.C / 'inputs.json')] = p.sha(p.C / 'inputs.json')
            req = dict(action='cpu_job', spec=dict(name=name, kind='module', cwd=str(p.C),
                argv=['/usr/bin/python3', str(p.C / 'physical.py')], inputs=inputs,
                outputs=[str(p.OUTPUT / 'result.json')],
                checkpoints=[str(p.D / 'Opt4-mcrams-shell-ipcollateral-r4-state.json')]))
            q = p.D / 'unattended-opt4/requests' / (name + '.json')
            if q.exists():
                assert p.read(q) == req, 'immutable repair request changed'
            else:
                m.save(q, req)
            state.update(status='SUBMITTED_VERSIONED_CHECKPOINT_ONLY_REPAIR_AFTER_ACTUAL_R3_FAILURE',
                request=str(q), request_sha256=p.sha(q))
            m.save(out / 'state.json', state)
            return
        if previous.get('status') in ['NOT_FIT_COMPLETE_TOP_NO_PLACE',
                'PHYSICAL_BITSTREAM_TIMING_DRC_PASSED_REQUIRES_COMPOSITE_HOST_RUNTIME_CERTIFICATION']:
            state.update(status='R3_TERMINAL_RESULT_RETAINED_NO_REPAIR_NEEDED')
            m.save(out / 'state.json', state)
            return
        m.save(out / 'state.json', state)
        time.sleep(300)


if __name__ == '__main__':
    main()
