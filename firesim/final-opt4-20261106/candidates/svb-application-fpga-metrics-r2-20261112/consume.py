#!/usr/bin/python3
"""Publish application event metrics only after exact card21 component replay.

Read-only with respect to CAD, device, driver, replay and CPU experiment state.
The prior independently audited lifetimes belong to the captured target trace;
successful hardware replay validates that trace on the component, not whole EC.
"""
import argparse
import csv
import fcntl
import hashlib
import json
import math
from pathlib import Path
import re
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
sys.path.insert(0, str(W / 'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha

BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
SID = 'b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f'
AUDIT = D / 'overnight-ec-evidence-audit-r4-20261112'
CPU = D / 'cycleprecise-original-svb-gg-stream-replay-r3-20261111'
RUNS = tuple(D / ('cycleprecise-original-svb-host40-shell-application-onboard-'+r+'-20261112') for r in ('r6', 'r7'))
RUN = RUNS[0]
OUT = D / 'svb-application-fpga-metrics-r2-20261112'
COUNT_KEYS = ('records', 'first_source_tick', 'last_source_tick', 'target_cycles',
              'reset_edges', 'defined_output_fields', 'defined_output_word_checks',
              'input_word_writes', 'input_cache_enabled', 'mismatches',
              'capture_accepted', 'promote_accepted', 'acked', 'mutation_applied')


def summary_gate(got, expected):
    assert all(got.get(k) == expected[k] for k in COUNT_KEYS), 'full replay count mismatch'
    assert got['input_cache_enabled'] == got['mismatches'] == got['mutation_applied'] == 0
    assert got['records'] == got['target_cycles'] > 0
    assert got['last_source_tick'] - got['first_source_tick'] + 1 == got['records']


def reference():
    pins = read(C / 'inputs.json')
    for path, digest in pins['files'].items():
        assert sha(path) == digest, ('metrics reference changed', path)
    admission = read(CPU / 'board-admission-ready.json')
    assert admission['functional_baseline'] == BASE and admission['source_id'] == SID
    assert admission['board_allowlist'] == ['0000:21:00.0'] and not admission['complete_opt4']
    assert sha(admission['cpu_proof']) == admission['cpu_proof_sha256']
    proof = read(admission['cpu_proof'])
    assert proof['passed'] and proof['real_application_payload_mutation_rejected']
    assert not proof['fpga_access'] and proof['positive']['returncode'] == 0
    assert proof['negative']['returncode'] != 0
    assert sha(admission['trace']) == admission['trace_sha256'] == proof['trace_sha256']
    assert sha(admission['driver']) == admission['driver_sha256']
    expected = admission['expected_summary']
    summary_gate(proof['positive']['summary'], expected)
    binary = read(AUDIT / 'binary-integrity-recomputed.json')
    lifetimes = read(AUDIT / 'svb-lifetimes-recomputed.json')
    rates = read(AUDIT / 'svb-observed-rates.json')
    assert binary['sha256'] == admission['trace_sha256']
    assert binary['records'] == expected['records']
    assert binary['counts']['reset_cycles'] == expected['reset_edges']
    assert lifetimes['status'] == 'PASS_MATCHED_COMPLETE_LIFETIME_SAMPLES_WITH_EXPLICIT_CENSORING'
    rows = lifetimes['sample_lifetimes']
    assert len(rows) == lifetimes['captures'] == lifetimes['complete_ack_lifetimes']
    assert len(rows) == expected['capture_accepted'] == expected['promote_accepted'] == expected['acked']
    assert not lifetimes['censored'] and lifetimes['censored_lifetimes'] == 0
    assert lifetimes['all_observed_ownership_ended'] and lifetimes['final_preedge_occupancy'] == 0
    for row in rows:
        cap, prom, ack = (row[k + '_target_cycle'] for k in ('capture', 'promotion', 'ack'))
        assert cap <= prom < ack
        assert row['capture_to_promotion'] == prom - cap
        assert row['promotion_to_ack'] == ack - prom
        assert row['capture_to_ack'] == ack - cap
    for key, distribution in lifetimes['metrics'].items():
        values = sorted(row[key] for row in rows)
        assert distribution['n'] == len(values) and distribution['total'] == sum(values)
        assert distribution['p95'] == values[math.ceil(.95 * len(values)) - 1]
        assert distribution['p99'] == values[math.ceil(.99 * len(values)) - 1]
        assert sum(distribution['histogram'].values()) == len(values)
    assert rates['completed_transactions'] == len(rows)
    assert rates['nonreset_observation_cycles'] == expected['records'] - expected['reset_edges']
    assert rates['first_capture_tick'] == min(row['capture_target_cycle'] for row in rows)
    assert rates['last_ack_tick'] == max(row['ack_target_cycle'] for row in rows)
    return admission, lifetimes, rates


def hardware(admission, run=RUN):
    result = read(run / 'result.json')
    assert result['status'] == 'VALID_ORIGINAL_SVB_REAL_APPLICATION_FPGA_TRACE'
    assert read(run / 'complete.json')['result_sha256'] == sha(run / 'result.json')
    assert result['functional_baseline'] == BASE and result['source_id'] == SID
    assert result['board_bdf'] == '0000:21:00.0' and result['board_serial'] == '21770433G02LA'
    assert result['returncode'] == 0 and not result['full_opt4']
    assert not result['strict_checker_latency_measured'] and not result['architectural_restart_tested']
    assert not result['deployment_operations']
    assert result['profile'] == 'OriginalSVB32-component-trace-host40'
    assert abs(result['physical_host_clock_period_ns'] - 24.9975) < .0001
    assert result['target_cycle_definition_changed'] is False
    for field in ('trace_sha256', 'driver_sha256'):
        assert result[field] == admission[field]
    assert result['application_admission_sha256'] == sha(run / 'application-admission.json')
    assert read(run / 'application-admission.json') == admission
    assert result['certificate_sha256'] == sha(run / 'certified-component.json')
    cert = read(run / 'certified-component.json')
    assert cert['status'] == 'CERTIFIED_ORIGINAL_SVB_COMPONENT_HOST40_NOT_FULL_OPT4'
    assert cert['functional_baseline'] == BASE and cert['source_id'] == SID and not cert['complete_opt4']
    assert cert['board_bdf'] == result['board_bdf'] and cert['board_serial'] == result['board_serial']
    assert sha(cert['bitstream']) == cert['bitstream_sha256'] == result['bitstream_sha256']
    assert sha(result['raw_log']) == result['raw_log_sha256']
    text = Path(result['raw_log']).read_text(errors='replace')
    assert '[SVBProbe]PASS Test' in text
    assert not any(s in text for s in ('SVB_GG_STREAM_MISMATCH', 'unstable value', '*** FAILED', 'Assertion failed'))
    lines = re.findall(r'^SVB_GG_STREAM_SUMMARY (.*)$', text, re.M)
    assert len(lines) == 1
    raw = {k: float(v) if '.' in v or 'e' in v.lower() else int(v)
           for k, v in (word.split('=', 1) for word in lines[0].split())}
    summary_gate(raw, admission['expected_summary'])
    summary_gate(result['summary'], admission['expected_summary'])
    assert raw == result['summary']
    assert raw['host_wall_seconds'] > 0 and result['host_wall_seconds'] > 0
    return result


def publish(admission, lifetimes, rates, result):
    assert not (OUT / 'complete.json').exists(), 'completed metrics immutable'
    rows = []
    for row in lifetimes['sample_lifetimes']:
        payload = json.dumps(row['identity'], separators=(',', ':')).encode()
        rows.append({**{k: v for k, v in row.items() if k != 'identity'},
                     'identity_sha256': hashlib.sha256(payload).hexdigest()})
    with (OUT / 'matched-lifetimes.csv').open('x') as stream:
        writer = csv.DictWriter(stream, fieldnames=list(rows[0]))
        writer.writeheader()
        writer.writerows(rows)
    save(OUT / 'result.json', dict(schema='ec-original-SVB-application-hardware-replay-metrics/1',
        kind='FPGA_COMPONENT_REPLAY_OF_CPU_CAPTURED_APPLICATION_TRACE_NOT_FULL_EC',
        functional_baseline=BASE, source_id=SID, board_bdf=result['board_bdf'],
        board_serial=result['board_serial'], completed_utc=now(),
        trace_sha256=admission['trace_sha256'], bitstream_sha256=result['bitstream_sha256'],
        replay_result=str(RUN / 'result.json'), replay_result_sha256=sha(RUN / 'result.json'),
        reference_manifest_sha256=sha(C / 'inputs.json'),
        matched_lifetimes_sha256=sha(OUT / 'matched-lifetimes.csv'),
        latency_distributions_target_cycles=lifetimes['metrics'],
        workload_observed_rates={k: v for k, v in rates.items() if k not in ('data_kind', 'scope', 'fpga_access')},
        driver_replay_target_cycles_per_host_second=result['summary']['target_cycles'] / result['summary']['host_wall_seconds'],
        inclusive_replay_target_cycles_per_host_second=result['summary']['target_cycles'] / result['host_wall_seconds'],
        strict_checker_latency=None, rollback_latency=None, autonomous_peak_throughput=None,
        full_ec=False, formal_parsec_sample=False, device_operations=[],
        scope='Target-edge capture/promote/ACK intervals from the exact captured application traffic whose defined component outputs all passed hardware replay. Host replay rates include MMIO overhead. ACK is SVB ownership/writeback completion.'))
    save(OUT / 'complete.json', dict(result_sha256=sha(OUT / 'result.json')))


def main():
    global RUN
    ap = argparse.ArgumentParser()
    ap.add_argument('--offline', action='store_true')
    args = ap.parse_args()
    admission, lifetimes, rates = reference()
    if args.offline:
        print(json.dumps(dict(status='REFERENCE_AND_LIFETIME_BINDINGS_PASS_NO_HARDWARE_ATTRIBUTION',
            matched_lifetimes=len(lifetimes['sample_lifetimes']), hardware_ready=any((r / 'complete.json').exists() for r in RUNS))))
        return
    OUT.mkdir(exist_ok=True)
    lock = (OUT / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    if (OUT / 'complete.json').exists():
        assert read(OUT / 'complete.json')['result_sha256'] == sha(OUT / 'result.json')
        return
    previous = read(OUT / 'state.json')
    assert not live(previous), 'adopt live metrics consumer'
    state = dict(schema='ec-SVB-readonly-metrics-consumer/1', **identity(),
                 fpga_access=False, device_operations=[], started_utc=now())
    while not any((r / 'complete.json').exists() for r in RUNS):
        state.update(status='WAITING_EXACT_CERTIFIED_APPLICATION_FPGA_REPLAY_NO_DEVICE_IO',
                     updated_utc=now(), replay_status={str(r): read(r / 'state.json').get('status') for r in RUNS})
        save(OUT / 'state.json', state)
        time.sleep(30)
    RUN = next(r for r in RUNS if (r / 'complete.json').exists())
    # Recheck immutable inputs after the wait before hardware attribution.
    admission, lifetimes, rates = reference()
    result = hardware(admission, RUN)
    publish(admission, lifetimes, rates, result)
    state.update(status='COMPLETE_BOUND_FPGA_COMPONENT_REPLAY_METRICS', ended_utc=now())
    save(OUT / 'state.json', state)


if __name__ == '__main__':
    main()
