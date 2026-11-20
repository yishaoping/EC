#!/usr/bin/python3
"""Independent integration; never changes the installed r3/r4b workflow."""
import fcntl
import json
import subprocess
from pathlib import Path
import importlib.util

C = Path(__file__).resolve().parent
R4B = C.parent / 'mcrams-shell-ipcollateral-r4b-20261112'
CONTRACT = C.parent / 'mcrams-preplace-exception-contract-r1-20261112'


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    result = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(result)
    return result


previous = module('pinned_r4b_preparation', R4B / 'prepare.py')
sha, read = previous.sha, previous.read
W, D, R2, AUDIT = previous.W, previous.D, previous.R2, previous.AUDIT
PREVIOUS = previous.PREVIOUS
OUTPUT = D / 'build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112'
STATE = D / 'Opt4-mcrams-preplace-contract-runner-r1-state.json'
OBSERVER_STATE = D / 'mcrams-shell-ipcollateral-r4b-observer-20261112/state.json'
OBSERVER_UNIT = 'ec-opt4-auto-mcrams-ipcollateral-recovery-observer-r4b-3656aec4.service'
CGROUP_ROOTS = ('/sys/fs/cgroup/systemd', '/sys/fs/cgroup')
NATIVE_CLOCK, NATIVE_GATE, MASTER_GATE = previous.NATIVE_CLOCK, previous.NATIVE_GATE, previous.MASTER_GATE


def verify():
    pins = read(C / 'inputs.json')
    for path, digest in pins['files'].items():
        assert sha(path) == digest, ('independent runner input changed', path)
    return previous.verify()


def require_observer_released():
    """No signal/stop/submit: an active installed observer always blocks us."""
    original = module('runner_identity', R2 / 'physical.py')
    state = read(OBSERVER_STATE)
    expected = read(C / 'inputs.json')['installed_observer_identity']
    assert all(str(state.get(k)) == str(expected[k]) for k in
               ['pid', 'start_ticks', 'host_boot_id']), 'observer identity changed; preserve and review'
    if original.live(state):
        raise BlockingIOError('installed r4b observer remains active')
    props = dict(line.split('=', 1) for line in subprocess.check_output(
        ['systemctl', 'show', OBSERVER_UNIT, '-p', 'MainPID', '-p', 'ActiveState', '-p', 'ControlGroup'],
        text=True).splitlines())
    if props['MainPID'] != '0' or props['ActiveState'] not in ['inactive', 'failed']:
        raise BlockingIOError('installed r4b observer service has not exited')
    assert props['ControlGroup'] in ['', '/system.slice/' + OBSERVER_UNIT]
    for root in CGROUP_ROOTS:
        cg = Path(root) / 'system.slice' / OBSERVER_UNIT
        if cg.exists() and any(p.read_text().split() for p in cg.rglob('cgroup.procs')):
            raise BlockingIOError('installed r4b observer exact cgroup has not released')
    request = D / 'unattended-opt4/requests/mcrams-shell-ipcollateral-r4b-3656aec4.json'
    assert not request.exists() and not previous.OUTPUT.exists(), 'existing r4b repair owns this continuation'
    assert state.get('status') != 'SUBMITTED_VERSIONED_CHECKPOINT_ONLY_REPAIR_AFTER_ACTUAL_R3_FAILURE'
    return state, props


def render(wrapper, output):
    renderer = module('pinned_contract_renderer', CONTRACT / 'render.py')
    return renderer.render(wrapper, output)


def add_final_contract(body, output):
    needle = f'write_bitstream -force {{{output}/firesim.bit}}'
    assert body.count(needle) == 1
    addition = (f'source {{{CONTRACT / "verify.tcl"}}}\n'
                f'ec_target_contract::verify {{{output}/final-target-exception-contract}}\n')
    result = body.replace(needle, addition + needle)
    assert result.replace(addition, '') == body
    return result


def require_saved_contract(engine):
    artifact = engine.O / 'target-exception-contract/result.tcldict'
    receipt = read(engine.O / 'top_opt-receipt.json')
    assert receipt['returncode'] == 0
    assert str(artifact) in receipt['outputs'], 'top-opt receipt lacks verified contract'
    assert artifact.is_file() and sha(artifact) == receipt['outputs'][str(artifact)], 'verified contract changed'
    return artifact


def admit_failed_r3_identity_only():
    require_observer_released()
    return previous.admit_failed_r3_identity_only()


def admit_failed_r3():
    observer, props = require_observer_released()
    # Retain the observer's own singleton lock throughout the successor run.
    # This also excludes a service restart between identity checks and CAD.
    observer_lock = (OBSERVER_STATE.parent / 'instance.lock').open('a')
    fcntl.flock(observer_lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    require_observer_released()
    state, previous_props = previous.admit_failed_r3_identity_only()
    admission = read(D / 'build-logs/Opt4-mcrams-full-host-continuation-r2-20261112/capacity-parity-admission.json')
    for key in ['capacity_result', 'target_parity_result']:
        assert sha(admission[key]) == admission[key + '_sha256']
    assert read(admission['capacity_result'])['full_host_fit']
    assert read(admission['target_parity_result'])['captured_finite_parity_passed']
    receipt = read(PREVIOUS / 'wrapper_only-receipt.json')
    assert receipt['returncode'] == 0
    assert all(sha(path) == digest for path, digest in receipt['outputs'].items())
    wrapper = PREVIOUS / 'wrapper-host-linked.dcp'
    assert str(wrapper) in receipt['outputs']
    assert not OUTPUT.exists() and not STATE.exists(), 'independent evidence already exists'
    OUTPUT.mkdir()
    evidence = dict(previous_state=state, previous_service=previous_props,
                    installed_observer=observer, observer_service=props,
                    inputs_sha256=sha(C / 'inputs.json'), no_DUT_resynthesis=True,
                    fpga_access=False, wrapper=str(wrapper), wrapper_sha256=sha(wrapper),
                    wrapper_receipt_sha256=sha(PREVIOUS / 'wrapper_only-receipt.json'),
                    previous_failure_sha256=sha(PREVIOUS / 'failure.json'))
    (OUTPUT / 'repair-admission.json').write_text(json.dumps(evidence, indent=2) + '\n')
    (OUTPUT / 'physical-source-bound.implementation.xdc').write_text(previous.source_bound_xdc())
    (OUTPUT / 'top_opt_repair.tcl').write_text(render(wrapper, OUTPUT))
    return observer_lock


if __name__ == '__main__':
    verify()
    # Preparation alone is read-only; deliberately no request or CAD launcher.
    print(json.dumps(dict(status='INDEPENDENT_RUNNER_PREPARED_NOT_INSTALLED',
                         fpga_access=False, installed_observer_preserved=True)))
