#!/usr/bin/python3
"""Offline ownership and pipeline tests. No subprocess/CAD is launched."""
import ast
import hashlib
import importlib.util
import json
from pathlib import Path
import sys
import tempfile
import types
from unittest import mock

ROOT = Path('/data1/gzh/EC')
C = ROOT / 'firesim/final-opt4-20261106/candidates/mcrams-preplace-contract-runner-r1-20261112'
sys.path.insert(0, str(C))
import prepare as p
import physical


def save(path, value):
    Path(path).parent.mkdir(parents=True, exist_ok=True)
    Path(path).write_text(json.dumps(value, indent=2) + '\n')


def baseline_body(name, output):
    tree = ast.parse((p.R2 / 'physical.py').read_text())
    calls = [node for node in ast.walk(tree) if isinstance(node, ast.Call)
             and isinstance(node.func, ast.Name) and node.func.id == 'stage'
             and isinstance(node.args[0], ast.Constant) and node.args[0].value == name]
    assert len(calls) == 1
    return eval(compile(ast.Expression(calls[0].args[1]), '<pinned-stage>', 'eval'), {'O': output})


results = []


def pipeline(case):
    with tempfile.TemporaryDirectory(prefix='ec-r131-runner-') as directory:
        base = Path(directory)
        output, old = base / 'output', base / 'old'
        output.mkdir(); old.mkdir()
        canonical = base / 'Opt4-mcrams-shell-physical-r2-state.json'
        save(canonical, {'status': 'FAILED_WITH_EVIDENCE'})
        before = p.sha(canonical)
        old_artifacts = {}
        for stage, filename in [('stub', 'FPGATop_stub.v'), ('wrapper_only', 'wrapper-host-linked.dcp')]:
            artifact = old / filename
            artifact.write_text('exact successful predecessor ' + filename)
            old_artifacts[filename] = p.sha(artifact)
            save(old / (stage + '-receipt.json'), {'returncode': 0, 'outputs': {str(artifact): p.sha(artifact)}})
        engine = types.SimpleNamespace(ST={}, save=save, now=lambda: 'offline-test')
        calls = []

        def update(**values):
            engine.ST.update(values)

        def original_stage(name, body, outputs):
            calls.append((name, body, list(outputs)))
            for artifact in outputs:
                if case == 'missing_topopt_contract' and name == 'top_opt' and artifact.name == 'result.tcldict':
                    continue
                if case == 'missing_final_contract' and name == 'timing_drc_bitstream' and artifact.name == 'result.tcldict':
                    continue
                artifact.parent.mkdir(parents=True, exist_ok=True)
                artifact.write_text('offline-stage-output:' + name)
            receipt = {'returncode': 0, 'outputs': {str(a): p.sha(a) for a in outputs if a.is_file()}}
            save(output / (name + '-receipt.json'), receipt)
            assert all(a.is_file() for a in outputs), 'required stage output absent'
            if case == 'tampered_preplace_contract' and name == 'top_opt':
                (output / 'target-exception-contract/result.tcldict').write_text('tampered')

        def run_engine():
            engine.ST['status'] = 'RUNNING'
            engine.stage('stub', 'FORBIDDEN_SYNTHESIS', [output / 'FPGATop_stub.v'])
            engine.stage('wrapper_only', 'FORBIDDEN_SYNTHESIS', [output / 'wrapper-host-linked.dcp'])
            engine.stage('top_opt', 'replaced', [output / 'top-opt.dcp', output / 'top-postopt-utilization.rpt'])
            if case == 'not_fit':
                engine.ST['status'] = 'NOT_FIT_COMPLETE_TOP_NO_PLACE'
                return
            engine.stage('place', baseline_body('place', output), [output / 'placed.dcp'])
            engine.stage('route', baseline_body('route', output), [output / 'routed.dcp'])
            engine.stage('timing_drc_bitstream', baseline_body('timing_drc_bitstream', output),
                         [output / 'firesim.bit', output / 'timing-summary.rpt', output / 'final-drc.rpt'])
            engine.ST['status'] = 'PHYSICAL_BITSTREAM_TIMING_DRC_PASSED_REQUIRES_COMPOSITE_HOST_RUNTIME_CERTIFICATION'
            if case == 'canonical_changed':
                save(canonical, {'status': 'OTHER_OWNER_RESULT'})

        engine.stage, engine.update, engine.main = original_stage, update, run_engine
        actual_module = p.module

        def modules(name, path):
            return engine if name == 'original_r2_physical_runner' else actual_module(name, path)

        expected_error = case in ['missing_topopt_contract', 'tampered_preplace_contract',
                                  'missing_final_contract', 'canonical_changed']
        with mock.patch.multiple(p, D=base, PREVIOUS=old, OUTPUT=output, STATE=base / 'own-state.json'), \
             mock.patch.object(p, 'verify'), mock.patch.object(p, 'admit_failed_r3'), \
             mock.patch.object(p, 'admit_failed_r3_identity_only') as recheck, \
             mock.patch.object(p, 'module', side_effect=modules):
            error = None
            try:
                physical.main()
            except AssertionError as exc:
                error = str(exc)
            assert bool(error) == expected_error, (case, error)
            reasons = {'missing_topopt_contract': 'required stage output absent',
                       'tampered_preplace_contract': 'verified contract changed',
                       'missing_final_contract': 'required stage output absent',
                       'canonical_changed': 'canonical predecessor changed'}
            if expected_error:
                assert error == reasons[case], (case, error)
            stages = [name for name, _, _ in calls]
            assert 'stub' not in stages and 'wrapper_only' not in stages
            assert all(p.sha(output / filename) == digest for filename, digest in old_artifacts.items())
            if case in ['missing_topopt_contract', 'tampered_preplace_contract', 'not_fit']:
                assert 'place' not in stages
            if expected_error:
                assert (output / 'failure.json').is_file()
                assert recheck.call_count == 0
                if case == 'canonical_changed':
                    assert p.read(canonical)['status'] == 'OTHER_OWNER_RESULT'
                else:
                    assert p.sha(canonical) == before
            else:
                assert recheck.call_count == 1
                assert p.read(canonical)['status'] == engine.ST['status']
            for name, body, outputs in calls:
                if name in ['place', 'route']:
                    assert body == baseline_body(name, output)
                if name == 'top_opt':
                    assert body == p.render(output / 'wrapper-host-linked.dcp', output)
                    assert output / 'target-exception-contract/result.tcldict' in outputs
                    assert body.index('write_checkpoint -force') < body.index('ec_target_contract::verify')
                if name == 'timing_drc_bitstream':
                    baseline = baseline_body(name, output).replace('scale {1 2}', 'scale {1 1}').replace(
                        'get_clocks -quiet host_clock', 'get_clocks -quiet ' + p.NATIVE_CLOCK)
                    needle = 'set host [get_clocks -quiet ' + p.NATIVE_CLOCK + ']'
                    baseline = baseline.replace(needle, p.NATIVE_GATE + p.MASTER_GATE + '\n' + needle)
                    assert body == p.add_final_contract(baseline, output)
                    assert body.index('report_drc -file') < body.index('ec_target_contract::verify') < body.index('write_bitstream -force')
                    assert output / 'final-target-exception-contract/result.tcldict' in outputs
        results.append({'case': case, 'passed': True, 'stages_reaching_engine': stages, 'expected_error': error})


for case in ['success', 'not_fit', 'missing_topopt_contract', 'tampered_preplace_contract',
             'missing_final_contract', 'canonical_changed']:
    pipeline(case)

# Exercise the real current ownership refusal, without changing any process.
try:
    p.require_observer_released()
except BlockingIOError as exc:
    assert str(exc) == 'installed r4b observer remains active'
    results.append({'case': 'actual_installed_observer_refused', 'passed': True, 'reason': str(exc)})
else:
    raise AssertionError('expected existing observer to remain active')

with tempfile.TemporaryDirectory(prefix='ec-r131-ownership-') as directory:
    base = Path(directory)
    state = base / 'state.json'
    identity = p.read(C / 'inputs.json')['installed_observer_identity']
    save(state, dict(identity, status='WAITING_ACTUAL_R3_CLOCK_FAILURE_NO_CAD'))
    original = types.SimpleNamespace(live=lambda state: False)
    cgroup = base / 'cg/system.slice' / p.OBSERVER_UNIT
    cgroup.mkdir(parents=True)
    for case, props, members, reason in [
            ('released', {'MainPID': '0', 'ActiveState': 'inactive', 'ControlGroup': ''}, '', None),
            ('service_still_active', {'MainPID': '7', 'ActiveState': 'active', 'ControlGroup': '/system.slice/' + p.OBSERVER_UNIT}, '', 'installed r4b observer service has not exited'),
            ('wrong_service_cgroup', {'MainPID': '0', 'ActiveState': 'inactive', 'ControlGroup': '/system.slice/other.service'}, '', ''),
            ('orphan_in_exact_cgroup', {'MainPID': '0', 'ActiveState': 'failed', 'ControlGroup': '/system.slice/' + p.OBSERVER_UNIT}, '123\n', 'installed r4b observer exact cgroup has not released'),
            ('prior_repair_request', {'MainPID': '0', 'ActiveState': 'inactive', 'ControlGroup': ''}, '', 'existing r4b repair owns this continuation')]:
        (cgroup / 'cgroup.procs').write_text(members)
        if case == 'prior_repair_request':
            save(base / 'unattended-opt4/requests/mcrams-shell-ipcollateral-r4b-3656aec4.json', {'existing': True})
        with mock.patch.multiple(p, OBSERVER_STATE=state, D=base, CGROUP_ROOTS=(str(base / 'cg'),)), \
             mock.patch.object(p, 'module', return_value=original), \
             mock.patch.object(p.subprocess, 'check_output', return_value='\n'.join(k + '=' + v for k, v in props.items())), \
             mock.patch.object(p.previous, 'OUTPUT', base / 'r4b-output'):
            try:
                returned = p.require_observer_released()
            except (AssertionError, BlockingIOError) as exc:
                assert reason is not None and str(exc) == reason, (case, str(exc))
                results.append({'case': case, 'passed': True, 'reason': str(exc)})
            else:
                assert reason is None and returned[1] == props
                results.append({'case': case, 'passed': True, 'reason': 'released exact service and empty cgroup accepted'})

    observer_lock = (base / 'instance.lock').open('a')
    p.fcntl.flock(observer_lock, p.fcntl.LOCK_EX | p.fcntl.LOCK_NB)
    with mock.patch.object(p, 'OBSERVER_STATE', state), \
         mock.patch.object(p, 'require_observer_released', return_value=({}, {})):
        try:
            p.admit_failed_r3()
        except BlockingIOError:
            results.append({'case': 'singleton_lock_contention', 'passed': True,
                            'reason': 'same observer lock prevents successor admission'})
        else:
            raise AssertionError('contended observer lock was acquired')
    observer_lock.close()

output = Path(__file__).with_name('validation.json')
save(output, {'schema': 'ec-round131-offline-runner-validation/1', 'cases': results,
              'all_passed': True, 'actual_fullshell_CAD_executed': False,
              'processes_signalled': [], 'production_requests_created': []})
print(json.dumps({'all_passed': True, 'cases': len(results), 'validation': str(output)}))
