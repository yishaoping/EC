#!/usr/bin/env python3
"""Accept newly completed receipts without CAD, device I/O, or CPU replay."""
import collections
import csv
import datetime
import hashlib
import io
import json
import math
import os
from pathlib import Path
import re
import statistics

B = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path('/data1/gzh/EC/firesim/final-opt4-20261106/candidates')
OUT = Path(__file__).resolve().parent
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
SID = 'b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f'
artifacts = {}


def sha(path):
    path = Path(path)
    h = hashlib.sha256()
    with path.open('rb') as f:
        for block in iter(lambda: f.read(1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def pin(path, expected=None):
    path = Path(path)
    got = sha(path)
    if expected is not None:
        assert got == expected, ('artifact digest', str(path), got, expected)
    artifacts[str(path)] = got
    return got


def read(path):
    pin(path)
    return json.loads(Path(path).read_text())


def save_new(name, data):
    with (OUT / name).open('x') as f:
        f.write(json.dumps(data, indent=2, sort_keys=True) + '\n')


def complete(run):
    result = read(run / 'result.json')
    pin(run / 'result.json', read(run / 'complete.json')['result_sha256'])
    return result


assert not (OUT / 'receipt.json').exists(), 'acceptance already immutable'
directed_dir = B / 'cycleprecise-original-svb-host40-shell-onboard-r7-20261112'
application_dir = B / 'cycleprecise-original-svb-host40-shell-application-onboard-r7-20261112'
metrics_dir = B / 'svb-application-fpga-metrics-r2-20261112'
directed, app, metrics = map(complete, (directed_dir, application_dir, metrics_dir))
cert_path = directed_dir / 'certified-component.json'
cert = read(cert_path)
for result in (directed, app):
    pin(cert_path, result['certificate_sha256'])
pin(application_dir / 'certified-component.json', app['certificate_sha256'])
assert cert['status'] == 'CERTIFIED_ORIGINAL_SVB_COMPONENT_HOST40_NOT_FULL_OPT4'
for result in (cert, directed, app, metrics):
    assert result['functional_baseline'] == BASE and result['source_id'] == SID
    assert result['board_bdf'] == '0000:21:00.0'
    assert result['board_serial'] == '21770433G02LA'
assert directed['status'] == 'VALID_COMPONENT_FPGA_TRACE'
assert app['status'] == 'VALID_ORIGINAL_SVB_REAL_APPLICATION_FPGA_TRACE'
assert not app['full_opt4'] and not metrics['full_ec'] and not cert['complete_opt4']
assert not app['target_cycle_definition_changed'] and not cert['target_rtl_changed']
assert not app['strict_checker_latency_measured'] and not app['architectural_restart_tested']
assert not app['deployment_operations'] and not metrics['device_operations']
assert metrics['strict_checker_latency'] is metrics['rollback_latency'] is None
assert metrics['autonomous_peak_throughput'] is None
bit_sha = pin(cert['bitstream'], cert['bitstream_sha256'])
assert bit_sha == app['bitstream_sha256'] == metrics['bitstream_sha256']
cad = read(cert['cad_result'])
pin(cert['cad_result'], cert['cad_result_sha256'])
assert cad['timing'] == dict(hold_failing=0, setup_failing=0, ths=0.0,
                            tns=0.0, whs=0.001, wns=0.0)
for path, digest in cad['outputs'].items():
    if Path(path).name in ('final-timing.rpt', 'route-final.rpt', 'drc-final.rpt'):
        pin(path, digest)
audit = read(directed_dir / 'clock-audit.complete.json')
pin(directed_dir / 'clock-audit.complete.json', cert['clock_audit_sha256'])
pin(directed_dir / 'clock-audit.log', audit['log_sha256'])
assert 'EC_SVB_HOST40_INDEPENDENT_AUDIT_PASS' in (directed_dir / 'clock-audit.log').read_text()
assert audit['routed_sha256'] == cad['outputs'][audit['routed_checkpoint']]
for file, key in [('pulse-width.rpt', 'pulse_width_sha256'), ('bus-skew.rpt', 'bus_skew_sha256')]:
    pin(directed_dir / file, audit[key])
deployment = read(directed_dir / 'deployment.json')
assert deployment['bdfs'] == ['0000:21:00.0']
assert deployment['serials'] == ['21770433G02LA'] and not deployment['global_operations']
assert deployment['bitstream_sha256'] == bit_sha
for result in (directed, app):
    pin(result['raw_log'], result['raw_log_sha256'])
    assert result['returncode'] == 0
assert directed['target_cycles_replayed'] == 372 and directed['compared_output_values'] == 42291
raw_text = Path(app['raw_log']).read_text()
assert '[SVBProbe]PASS Test' in raw_text
assert not any(s in raw_text for s in ('SVB_GG_STREAM_MISMATCH', '*** FAILED', 'Assertion failed'))
summaries = re.findall(r'^SVB_GG_STREAM_SUMMARY (.*)$', raw_text, re.M)
assert len(summaries) == 1
raw_summary = {k: float(v) if '.' in v or 'e' in v.lower() else int(v)
               for k, v in (word.split('=', 1) for word in summaries[0].split())}
assert raw_summary == app['summary']
for key, value in app['expected_cpu_summary'].items():
    if key != 'host_wall_seconds':
        assert app['summary'][key] == value, key
summary = app['summary']
assert summary['records'] == summary['target_cycles'] == 1759001
assert summary['mismatches'] == summary['input_cache_enabled'] == summary['mutation_applied'] == 0
assert summary['capture_accepted'] == summary['promote_accepted'] == summary['acked'] == 659
pin(application_dir / 'application-admission.json', app['application_admission_sha256'])
assert metrics['replay_result'] == str(application_dir / 'result.json')
pin(metrics['replay_result'], metrics['replay_result_sha256'])
pin(C / 'svb-application-fpga-metrics-r2-20261112/inputs.json', metrics['reference_manifest_sha256'])
pin(metrics_dir / 'matched-lifetimes.csv', metrics['matched_lifetimes_sha256'])
rows = list(csv.DictReader(io.StringIO((metrics_dir / 'matched-lifetimes.csv').read_text())))
assert len(rows) == 659
for row in rows:
    cap, prom, ack = (int(row[k + '_target_cycle']) for k in ('capture', 'promotion', 'ack'))
    assert cap <= prom < ack
    assert int(row['capture_to_ack']) == ack - cap
    assert int(row['capture_to_promotion']) == prom - cap
    assert int(row['promotion_to_ack']) == ack - prom
distributions = {}
for key, dist in metrics['latency_distributions_target_cycles'].items():
    values = sorted(int(row[key]) for row in rows)
    assert dist['n'] == len(values) and dist['total'] == sum(values)
    assert dist['histogram'] == dict(collections.Counter(map(str, values)))
    assert dist['maximum'] == max(values) and dist['median'] == statistics.median(values)
    assert math.isclose(dist['mean'], statistics.mean(values))
    for percentile in (95, 99):
        assert dist['p' + str(percentile)] == values[math.ceil(percentile / 100 * len(values)) - 1]
    distributions[key] = {k: v for k, v in dist.items() if k != 'histogram'}
assert math.isclose(metrics['driver_replay_target_cycles_per_host_second'],
                    summary['target_cycles'] / summary['host_wall_seconds'])
capacity_path = B / 'build-logs/Opt4-mcrams-full-host-capacity-r1-20261112/result.json'
capacity = read(capacity_path)
assert capacity['status'] == 'NOT_FIT_FULL_GENERATED_HOST_NO_PLACE_RUN'
assert capacity['no_place_or_route_run'] and not capacity['full_host_fit']
postopt = capacity['reports']['postopt']
assert postopt['blackboxes'] == 0 and postopt['resources']['CLB LUTs'] == 2420482
assert capacity['resource_excess']['CLB LUTs'] == 1116802
for path, digest in postopt['evidence'].items():
    pin(path, digest)
request = B / 'unattended-opt4/requests/svb-application-fpga-metrics-r1-8491167d.json'
pin(request)  # Retain the already admitted original r1 waiter and its exact request.
receipt = dict(schema='ec-round140-completed-svb-application-acceptance/1',
    utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
    status='PASS_BOUND_REAL_FPGA_COMPONENT_APPLICATION_AND_METRICS',
    functional_baseline=BASE, source_id=SID, board_bdf='0000:21:00.0',
    board_serial='21770433G02LA', bitstream_sha256=bit_sha,
    application_summary=summary, latency_distributions_target_cycles=distributions,
    directed_result=str(directed_dir / 'result.json'), application_result=str(application_dir / 'result.json'),
    metrics_result=str(metrics_dir / 'result.json'), artifacts_sha256=artifacts,
    mcrams=dict(status=capacity['status'], resources=postopt['resources'],
        lut_excess=1116802, shell_excluded=True, no_place_or_route_run=True,
        checkpoint_sha256_from_completed_producer=capacity['checkpoint_sha256'],
        large_checkpoint_rehashed_by_this_audit=False),
    no_cad_launch=True, no_device_io=True, no_process_signals=True,
    no_cpu_comparison_control=True, original_r1_request_unchanged=True,
    full_ec=False, strict_checker_latency=None, rollback_latency=None,
    boundary='659 captured application lifetimes validated by defined component outputs; replay host rate includes MMIO. No full EC or autonomous throughput claim.')
save_new('receipt.json', receipt)
policy_path = B / 'unattended-opt4/campaign-policy.json'
before = policy_path.read_bytes()
policy = json.loads(before)
with (OUT / 'campaign-policy.before.json').open('xb') as f:
    f.write(before)
app_entry = dict(result=str(application_dir / 'result.json'),
    result_sha256=artifacts[str(application_dir / 'result.json')], status=app['status'],
    bitstream_sha256=bit_sha, target_cycles=1759001, defined_output_word_checks=19698670,
    complete_ack_lifetimes=659, mismatches=0, full_ec=False,
    metrics_result=str(metrics_dir / 'result.json'),
    metrics_result_sha256=artifacts[str(metrics_dir / 'result.json')],
    acceptance_receipt=str(OUT / 'receipt.json'), acceptance_receipt_sha256=sha(OUT / 'receipt.json'))
policy['first_certified_svb_card21_application_measurement'] = app_entry
chain = policy['original_svb_application_chain']
chain.update(fpga_measurements_yet=True, latest_completed_result=app_entry['result'],
             latest_completed_result_sha256=app_entry['result_sha256'],
             measurement_scope='Real FPGA SVB component application trace only; no full EC, architectural restart or strict checker latency')
synth = policy.get('latest_mcrams_complete_host_synth', {})
synth.update(postopt_final_result_pending=False, postopt_result=str(capacity_path),
             postopt_result_sha256=artifacts[str(capacity_path)])
after = (json.dumps(policy, indent=2, sort_keys=True) + '\n').encode()
temporary = policy_path.with_name('.campaign-policy.round140.tmp')
with temporary.open('xb') as f:
    f.write(after)
    f.flush()
    os.fsync(f.fileno())
if policy_path.read_bytes() != before:
    temporary.unlink()
    raise RuntimeError('Concurrent policy update preserved; acceptance remains saved, retry policy merge separately')
os.chmod(temporary, policy_path.stat().st_mode & 0o777)
os.replace(temporary, policy_path)
save_new('policy-update.json', dict(before_sha256=hashlib.sha256(before).hexdigest(),
    after_sha256=sha(policy_path), receipt_sha256=sha(OUT / 'receipt.json'),
    changed_keys=['first_certified_svb_card21_application_measurement',
                  'original_svb_application_chain.fpga_measurements_yet',
                  'original_svb_application_chain.latest_completed_result',
                  'original_svb_application_chain.latest_completed_result_sha256',
                  'original_svb_application_chain.measurement_scope',
                  'latest_mcrams_complete_host_synth.postopt_final_result_pending',
                  'latest_mcrams_complete_host_synth.postopt_result',
                  'latest_mcrams_complete_host_synth.postopt_result_sha256'],
    no_live_bound_input_change=True))
print(json.dumps(dict(status=receipt['status'], receipt_sha256=sha(OUT / 'receipt.json'),
                     artifact_count=len(artifacts), target_cycles=1759001, matched_lifetimes=len(rows),
                     policy_sha256=sha(policy_path))))
