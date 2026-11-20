#!/usr/bin/python3
"""Synthetic admission-gate checks; no simulation, request or device operation."""
import copy
import importlib.util
import json
from pathlib import Path

C = Path(__file__).resolve().parent
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
COMMIT = '3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'


def module(name, filename):
    spec = importlib.util.spec_from_file_location(name, C/filename)
    value = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(value)
    return value


def put(path, value):
    with path.open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')


def main():
    submit = module('prepared_submission', 'submit.py')
    policy = submit.read(submit.U/'campaign-policy.json')
    assert policy['functional_baseline_commit'] == BASE
    assert policy['area_equivalence_only'] and not policy['fpga_access']
    assert policy['native_paused'] and not policy['functional_extensions_allowed']
    root = C/'synthetic-gate-fixtures'
    root.mkdir()
    gg = dict(status='PASS_COMPLETE_REAL_APPLICATION_GG_STREAM_REPLAY', passed=True,
        real_application_payload_mutation_rejected=True, fpga_access=False,
        positive=dict(returncode=0, summary=dict(records=1759001,
            target_cycles=1759001, mismatches=0, input_cache_enabled=0)),
        negative=dict(returncode=1, mutation_applied=True, mutation_payload_rejected=True),
        complete_trace_records=1759001)
    pair = dict(status='PASS_SAME_3656_TARGET_CANNEAL_CAPTURED_CYCLES_OUTPUT_EVENTS_NOT_FULL_EQUIVALENCE',
        functional_baseline=BASE, derived_hardware=COMMIT, captured_finite_parity_passed=True,
        exact_target_rows=True, exact_target_print_streams=True, fpga_access=False)
    names = ['Opt4-original-svb-gg-stream-replay-r3-state.json',
             'Opt4-mcrams-owner-pair-runtime-r1-state.json']
    snapshot = dict(states={name: dict(identity_live=False) for name in names})
    original_read = submit.read
    submit.read = lambda p: snapshot if Path(p) == submit.U/'snapshot.json' else original_read(p)
    cases = []
    for name in ['valid_schema', 'stale_pair_status', 'failed_gg', 'input_cache',
                 'missing_edge', 'payload_negative_absent', 'different_source',
                 'different_baseline', 'mismatch', 'incomplete_parity', 'live_producer']:
        a, b = copy.deepcopy(gg), copy.deepcopy(pair)
        if name == 'stale_pair_status':
            b['status'] = 'PASS_SAME_3656_CANNEAL_CAPTURED_TARGET_CYCLES_OUTPUT_EVENTS_NOT_FULL_EQUIVALENCE'
        elif name == 'failed_gg':
            a['passed'] = False
        elif name == 'input_cache':
            a['positive']['summary']['input_cache_enabled'] = 1
        elif name == 'missing_edge':
            a['positive']['summary']['records'] -= 1
        elif name == 'payload_negative_absent':
            a['negative']['mutation_payload_rejected'] = False
        elif name == 'different_source':
            b['derived_hardware'] = '8491167d84b6d9521b151a743673c1516926a1f8'
        elif name == 'different_baseline':
            b['functional_baseline'] = 'a4477d7241d80826f5d47a679fa05a2571d413c7'
        elif name == 'mismatch':
            a['positive']['summary']['mismatches'] = 1
        elif name == 'incomplete_parity':
            b['captured_finite_parity_passed'] = False
        elif name == 'live_producer':
            snapshot['states'][names[0]]['identity_live'] = True
        sub = root/name
        sub.mkdir()
        for filename, value in [('gg.json', a), ('pair.json', b)]:
            put(sub/filename, value)
        plan = dict(hardware_commit=COMMIT, required_completed_receipts=[str(sub/'gg.json'), str(sub/'pair.json')])
        try:
            result = submit.prerequisites(plan)
        except AssertionError:
            if name in ['valid_schema', 'live_producer']:
                raise
            cases.append(dict(name=name, status='REJECTED_SYNTHETIC_MUTATION'))
        else:
            assert name in ['valid_schema', 'live_producer'], ('negative accepted', name)
            expected = 'READY_EXACT_P0_CPU_PREREQUISITES' if name == 'valid_schema' else 'DEFERRED_PRODUCER_EXIT_SNAPSHOT'
            assert result['status'] == expected
            cases.append(dict(name=name, status=result['status']))
    submit.read = original_read
    real = submit.prerequisites(original_read(C/'plan.json'))
    assert real['status'] == 'DEFERRED_EXISTING_P0_RECEIPTS'
    # Admission hashes are rechecked by the actual prepared controller. Change
    # an otherwise valid immutable receipt and verify that its bound hash fails.
    controller = module('prepared_controller', 'controller.py')
    controller.C = root/'valid_schema'
    plan = dict(hardware_commit=COMMIT, required_completed_receipts=[
        str(controller.C/'gg.json'), str(controller.C/'pair.json')])
    put(controller.C/'prerequisite-bindings.json', dict(receipt_sha256={
        p: controller.sha(p) for p in plan['required_completed_receipts']}))
    assert controller.prerequisites(plan)
    controller.sha = lambda _: '0'*64
    try:
        controller.prerequisites(plan)
        raise RuntimeError('Changed receipt hash was accepted')
    except AssertionError:
        cases.append(dict(name='changed_receipt_hash', status='REJECTED_SYNTHETIC_MUTATION'))
    result = dict(status='PASS_SYNTHETIC_ADMISSION_GATE_PREFLIGHT', cases=cases,
        real_gate=real, request_submitted=False, target_modified=False, fpga_access=False,
        scope='Admission software tests only; synthetic fixtures are not EC execution evidence')
    put(C/'gate-preflight.json', result)
    print(json.dumps(dict(status=result['status'], cases=len(cases), real_gate=real['status'])))


if __name__ == '__main__':
    main()
