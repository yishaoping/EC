#!/usr/bin/python3
"""Read-only post-FPGA evidence consumer. No simulator, CAD, or device access.

The reported event intervals originate in the original complete target trace.
They acquire the separate label "exact replay validated" only after the existing
application follower has actually replayed that same complete trace on card21.
"""
from pathlib import Path
import argparse
import copy
import datetime
import hashlib
import json
import math
import os

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
OBS = D/'cycleprecise-frozen-full-gg-external-observer-r5-20261111/full-result.json'
CPU = D/'cycleprecise-original-svb-gg-stream-replay-r3-20261111'
O = D/'cycleprecise-svb-postfpga-metrics-round45-v1-20261111'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
SID = 'b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f'
ROOTS = [D/'cycleprecise-original-svb-application-onboard-r1-20261111',
         D/'cycleprecise-original-svb-application-onboard-recovered-r1-20261111']
KEYS = ['records', 'first_source_tick', 'last_source_tick', 'target_cycles',
        'reset_edges', 'defined_output_fields', 'defined_output_word_checks',
        'mismatches', 'capture_accepted', 'promote_accepted', 'acked',
        'mutation_applied', 'input_cache_enabled', 'input_word_writes']


def read(path):
    return json.loads(Path(path).read_text())


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for chunk in iter(lambda: stream.read(2**20), b''):
            h.update(chunk)
    return h.hexdigest()


def write_once(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    temp = path.with_name(path.name + '.preparing-' + str(os.getpid()))
    with temp.open('x') as stream:
        json.dump(value, stream, indent=2, sort_keys=True)
        stream.write('\n')
        stream.flush()
        os.fsync(stream.fileno())
    try:
        os.link(temp, path)
    finally:
        temp.unlink()


def policy():
    p = read(D/'unattended-opt4/campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert not p['functional_extensions_allowed'] and not p['fpga_access']
    assert p['native_paused'] and p['board_allowlist'] == ['0000:21:00.0']


def validate_histograms(lifetimes):
    assert lifetimes['all_observed_ownership_ended']
    assert lifetimes['final_preedge_occupancy'] == 0
    for name, metric in lifetimes['metrics'].items():
        hist = {int(value): count for value, count in metric['histogram'].items()}
        assert hist and min(hist) >= 0 and all(count > 0 for count in hist.values())
        assert sum(hist.values()) == metric['n'], ('histogram count', name)
        assert sum(value * count for value, count in hist.items()) == metric['total']
        assert math.isclose(metric['mean'], metric['total']/metric['n'], rel_tol=1e-12)
        assert metric['maximum'] == max(hist)
        for key, percentile in [('median', 0.5), ('p95', 0.95), ('p99', 0.99)]:
            rank, seen = math.ceil(percentile * metric['n']), 0
            for value in sorted(hist):
                seen += hist[value]
                if seen >= rank:
                    assert metric[key] == value, ('nearest rank percentile', name, key)
                    break


def validate_hardware(result, cert, admission, proof, observed, started, budget):
    assert result['status'] == 'VALID_ORIGINAL_SVB_REAL_APPLICATION_FPGA_TRACE'
    assert result['returncode'] == 0 and not result['full_opt4']
    assert result['functional_baseline'] == cert['functional_baseline'] == BASE
    assert result['source_id'] == cert['source_id'] == admission['source_id'] == SID
    assert result['board_bdf'] == cert['board_bdf'] == '0000:21:00.0'
    assert result['board_serial'] == cert['board_serial'] == '21770433G02LA'
    assert cert['status'] == 'CERTIFIED_ORIGINAL_SVB_COMPONENT_NOT_FULL_OPT4'
    assert cert['profile'] == 'OriginalSVB32-component-trace' and not cert['complete_opt4']
    assert proof['passed'] and proof['real_application_payload_mutation_rejected']
    assert result['trace_sha256'] == admission['trace_sha256'] == proof['trace_sha256']
    assert result['trace_sha256'] == observed['binary_integrity']['sha256']
    assert result['bitstream_sha256'] == cert['bitstream_sha256'] == started['bitstream_sha256']
    assert result['driver_sha256'] == admission['driver_sha256']
    assert started['reuse_existing_certified_bitstream'] and not started['deployment_operations']
    assert not result['deployment_operations']
    assert started['timeout_seconds'] == budget['per_run_timeout_seconds']
    assert 0 < budget['per_run_timeout_seconds'] <= 24*3600
    required = ['+svb-force-all-inputs', '+domain=0000', '+bus=21', '+device=00',
                '+function=0', '+bar=0', '+svb-trace=' + admission['trace']]
    assert admission['required_driver_args'] == required
    expected = proof['positive']['summary']
    assert all(result['summary'][key] == expected[key] for key in KEYS)
    assert result['summary']['records'] == result['summary']['target_cycles'] == observed['binary_integrity']['records']
    assert result['summary']['mismatches'] == result['summary']['mutation_applied'] == 0
    assert result['summary']['input_cache_enabled'] == 0
    for output, count in [('capture_accepted', 'capture_accepted'),
                          ('promote_accepted', 'promote_accepted'), ('acked', 'ack_accepted')]:
        assert result['summary'][output] == observed['binary_integrity']['counts'][count] > 0


def prepare():
    policy()
    observed = read(OBS)
    assert observed['valid_finite_observation'] and observed['full_original_generated_svb_ports_saved']
    validate_histograms(observed['svb_lifetimes_summary'])
    # Actual CPU-only evidence cannot satisfy the hardware gate.
    try:
        validate_hardware(observed, {}, {}, {}, observed, {}, {})
    except (AssertionError, KeyError):
        pass
    else:
        raise AssertionError('CPU observation was accepted as FPGA evidence')
    bad = copy.deepcopy(observed['svb_lifetimes_summary'])
    metric = next(iter(bad['metrics'].values()))
    first = next(iter(metric['histogram']))
    metric['histogram'][first] += 1
    try:
        validate_histograms(bad)
    except AssertionError:
        pass
    else:
        raise AssertionError('corrupted histogram was accepted')
    write_once(C/'plan.json', dict(schema='ec-post-fpga-trace-metrics-plan/1',
        functional_baseline=BASE, observer=str(OBS), observer_sha256=sha(OBS),
        analyzer_sha256=sha(__file__), exact_trace_sha256=observed['binary_integrity']['sha256'],
        records=observed['binary_integrity']['records'],
        preflight='PASS_HISTOGRAM_ARITHMETIC_CPU_NOT_HARDWARE_AND_MUTATION_REJECTION',
        required_hardware_roots=[str(path) for path in ROOTS],
        fpga_access=False, hardware_replay_passed=False, job_submitted=False,
        scope='Prepared read-only evidence consumer; no hardware result or new event measurement.'))
    print('PREPARED_WAITING_ACTUAL_APPLICATION_FPGA_PASS_NO_JOB_SUBMITTED')


def run():
    policy()
    plan = read(C/'plan.json')
    assert sha(OBS) == plan['observer_sha256'] and sha(__file__) == plan['analyzer_sha256']
    if (O/'complete.json').exists():
        assert sha(O/'result.json') == read(O/'complete.json')['result_sha256']
        print('IMMUTABLE_COMPLETE_REVALIDATED')
        return
    candidates = [root for root in ROOTS if (root/'complete.json').exists()]
    assert candidates, 'WAITING_ACTUAL_APPLICATION_FPGA_PASS_NO_RESULT_CREATED'
    assert len(candidates) == 1, 'ambiguous application follower completion'
    root = candidates[0]
    paths = [root/name for name in ['result.json', 'complete.json', 'certified-component.json',
                                   'application-admission.json', 'run-started.json']]
    result, marker, cert, admission, started = [read(path) for path in paths]
    assert sha(paths[0]) == marker['result_sha256']
    assert sha(paths[2]) == result['certificate_sha256']
    assert sha(paths[3]) == result['application_admission_sha256']
    assert sha(CPU/'full-result.json') == admission['cpu_proof_sha256'] == started['cpu_proof_sha256']
    proof, observed = read(CPU/'full-result.json'), read(OBS)
    budget = read(CPU/'measured-full-budget.json')
    validate_hardware(result, cert, admission, proof, observed, started, budget)
    assert sha(admission['trace']) == result['trace_sha256']
    assert sha(result['raw_log']) == result['raw_log_sha256']
    validate_histograms(observed['svb_lifetimes_summary'])
    seconds = result['host_wall_seconds']
    assert seconds > 0
    output = dict(schema='ec-post-fpga-exact-replay-validated-svb-events/1',
        status='PASS_REAL_COMPONENT_FPGA_REPLAY_BOUND_ORIGINAL_TRACE_EVENT_METRICS',
        functional_baseline=BASE, source_id=SID, hardware_replay_passed=True,
        analysis_device_access=False, full_opt4=False, formal_parsec_sample=False,
        event_metric_origin='Original frozen full-target CPU GoldenGate trace; exact same complete payload replay validated on FPGA component.',
        event_metrics=observed['svb_lifetimes_summary'],
        hardware_host_replay=dict(host_wall_seconds=seconds,
            target_records_per_host_second=result['summary']['records']/seconds,
            scope='Host MMIO replay throughput, not autonomous FPGA throughput or Native slowdown.'),
        bitstream_sha256=result['bitstream_sha256'], trace_sha256=result['trace_sha256'],
        strict_checker_latency_measured=False, architectural_restart_tested=False,
        evidence={str(path): sha(path) for path in paths + [OBS, CPU/'full-result.json', C/'plan.json']},
        completed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
    write_once(O/'result.json', output)
    write_once(O/'complete.json', dict(result_sha256=sha(O/'result.json')))
    print(output['status'])


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--prepare', action='store_true')
    parser.add_argument('--run', action='store_true')
    args = parser.parse_args()
    assert args.prepare != args.run
    prepare() if args.prepare else run()
