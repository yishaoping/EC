"""Pin completed results only; never launch CAD, control services, or access a card."""
import hashlib
import json
import re
from datetime import datetime, timezone
from pathlib import Path

B = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path('/data1/gzh/EC/firesim/final-opt4-20261106/candidates/svb-routed-conditional-r7-20261112')
A = Path(__file__).resolve().parent
K = B / 'cycleprecise-svb-host40-shell-recovery-r7-20261112/K-postroute-aggressive-explore'
MC = B / 'build-logs/Opt4-mcrams-full-host-capacity-r1-20261112'


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(4 * 1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def read(path):
    return json.loads(Path(path).read_text())


def save(name, data):
    path = A / name
    with path.open('x') as stream:
        json.dump(data, stream, indent=2, sort_keys=True)
        stream.write('\n')
    return str(path)


policy = read(B / 'FPGA_SESSION_POLICY.json')
assert policy['board_allowlist'] == ['0000:21:00.0']
assert policy['functional_baseline_commit'] == '8491167d84b6d9521b151a743673c1516926a1f8'
assert policy['native_fpga_paused'] and policy['preserve_all_correctness_and_physical_certification_gates']
assert not policy['functional_extensions_allowed']

result = read(K / 'result.json')
choice = read(K.parent / 'chosen-result.json')
assert choice['result'] == str(K / 'result.json')
assert choice['result_sha256'] == sha(K / 'result.json')
assert read(K / 'complete.json')['result_sha256'] == sha(K / 'result.json')
assert result['status'] == 'HOST40_BITSTREAM_PENDING_INDEPENDENT_CERTIFICATION'
assert result['returncode'] == 0 and not result['target_rtl_changed']
assert not result['complete_opt4'] and not result['fpga_access']
assert result['functional_baseline'] == policy['functional_baseline_commit']
assert result['input_manifest_sha256'] == sha(C / 'inputs.json')
assert result['sealed_inputs_sha256'] == sha(K / 'sealed-inputs.json')
assert result['timing'] == dict(wns=0.0, tns=0.0, setup_failing=0, whs=0.001, ths=0.0, hold_failing=0)

# Only this newly completed result's output set is rehashed. Unchanged source
# and prior source proofs remain bound through the original sealed manifests.
outputs = []
for path, expected in sorted(result['outputs'].items()):
    p = Path(path)
    before = p.stat()
    actual = sha(p)
    after = p.stat()
    assert (before.st_size, before.st_mtime_ns) == (after.st_size, after.st_mtime_ns), path
    assert actual == expected, path
    outputs.append(dict(path=path, bytes=after.st_size, sha256=actual))
assert result['bitstream_sha256'] == sha(result['bitstream'])
assert Path(result['bitstream']).stat().st_size == 42842607

timing_text = (K / 'final-timing.rpt').read_text()
assert 'All user specified timing constraints are met.' in timing_text
summary = timing_text.split('| Design Timing Summary', 1)[1]
row = re.search(r'^\s+(0\.000)\s+(0\.000)\s+0\s+365194\s+(0\.001)\s+(0\.000)\s+0\s+364234\s+(0\.000)\s+(0\.000)\s+0\s+154109\s*$', summary, re.M)
assert row, 'final all-clock timing row changed'
route = (K / 'route-final.rpt').read_text()
assert re.search(r'# of routable nets\.+\s*:\s*255876\s*:', route)
assert re.search(r'# of fully routed nets\.+\s*:\s*255876\s*:', route)
assert re.search(r'# of nets with routing errors\.+\s*:\s*0\s*:', route)
drc = (K / 'drc-final.rpt').read_text().split('2. REPORT DETAILS', 2)[1]
assert 'Violations found: 49' in drc
assert not re.search(r'\|\s*(?:Error|Critical Warning)\s*\|', drc)
warnings = re.findall(r'^\|\s*([\w-]+)\s*\|\s*Warning\s*\|.*?\|\s*(\d+)\s*\|', drc, re.M)
assert sum(int(count) for _, count in warnings) == 49
checks = (K / 'check-timing.rpt').read_text()
assert 'checking no_clock (0)' in checks and 'checking unconstrained_internal_endpoints (0)' in checks
save('K-result.json', result)
save('K-output-verification.json', dict(status='PASS_NEW_COMPLETED_OUTPUT_HASH_BINDINGS', outputs=outputs,
    result_sha256=sha(K / 'result.json'), chosen_result_sha256=sha(K.parent / 'chosen-result.json'),
    complete_sha256=sha(K / 'complete.json'), drc_warnings=dict(warnings),
    routable_nets=255876, fully_routed_nets=255876, routing_errors=0,
    independent_certificate_status='PENDING_AT_LIVE_OBSERVATION', fpga_measurement_claim=False))

mc_audit_path = B / 'status-audits/svb-r6-continuation-20261112/mcrams-postopt-resource-audit.json'
mc_audit = read(mc_audit_path)
for path, expected in mc_audit['evidence'].items():
    assert sha(path) == expected, path
text = (MC / 'postopt-utilization.rpt').read_text()
resources = {}
for label in ['CLB LUTs', 'CLB Registers', 'CARRY8', 'Block RAM Tile', 'URAM', 'DSPs']:
    match = re.search(r'^\|\s*' + re.escape(label) + r'\*?\s*\|\s*([\d.]+)\s*\|', text, re.M)
    assert match, label
    resources[label] = float(match.group(1))
assert resources == {'CLB LUTs': 2420482.0, 'CLB Registers': 1696013.0,
    'CARRY8': 80990.0, 'Block RAM Tile': 898.5, 'URAM': 0.0, 'DSPs': 192.0}
assert int(mc_audit['hierarchy_top']['Total LUTs']) == int(resources['CLB LUTs'])
assert mc_audit['crosschecks']['blackboxes'] == 0
save('MCrams-postopt-verification.json', dict(status='NOT_FIT_POSTOPT', full_generated_host=True,
    u280_shell_included=False, resources=resources, lut_capacity=1303680, lut_excess=1116802,
    full_physical_fit=False, postopt_checkpoint_not_hashed_while_original_write_active=True,
    source_audit=str(mc_audit_path), source_audit_sha256=sha(mc_audit_path), report_hashes=mc_audit['evidence'],
    no_new_physical_admission=True))

# These identities were directly observed earlier in this round, not inferred
# from historical state snapshots. Do not poll CAD again inside the interval.
save('live-adoption.json', dict(observation_window_utc=['2026-11-12T10:17:07Z', '2026-11-12T10:19:48Z'],
    host_boot_id='d6c6e410-10ad-4326-86ba-79b657eabd96',
    source='/proc/PID/stat, /proc/PID/cgroup, exact systemd cgroup.procs, systemctl show',
    running=[
        dict(kind='independent_r7_certificate_audit', pid=3277916, start_ticks='29017649',
             controller_pid=3192416, controller_start_ticks='28717374',
             cgroup='/system.slice/ec-opt4-svb-host40-shell-follow-r7.service', exact_cgroup_verified=True),
        dict(kind='original_MCrams_postopt_checkpoint_write', pid=2379656, start_ticks='25825451',
             cgroup='/system.slice/ec-opt4-auto-mcrams-full-host-capacity-r1-3656aec4.service', exact_cgroup_verified=True),
        dict(kind='existing_field_address_DUT_synthesis', pid=3138447, start_ticks='28529274',
             cgroup='/system.slice/ec-opt4-auto-field-address-cycle-cad-r3-8d50489a.service', exact_cgroup_verified=True),
        dict(kind='readonly_r2_metrics_consumer', pid=3209953, start_ticks='28802096',
             cgroup='/user.slice/user-1008.slice/user@1008.service/ec-opt4-svb-application-metrics-r2-20261112.service',
             exact_cgroup_verified=True, device_operations=[])],
    waiting=[dict(kind='r7_same_bit_application_follower', pid=3192469, start_ticks='28717452',
        cgroup='/system.slice/ec-opt4-svb-host40-shell-application-follow-r7.service',
        exact_cgroup_verified=True, prerequisite='independent certificate and valid directed replay'),
        dict(kind='21-only_directed_replay', prerequisite='independent physical certificate and both board locks')],
    completed=['r5 physical and certification follower exited naturally; PID2692703 absent',
        'r7 physical exited naturally after complete bitstream', 'r8 physical exited after r7 winner without CAD'],
    no_process_signals=True, no_service_mutations=True, no_new_job_requests=True, fpga_operations=[]))

receipt = dict(schema='ec-round139-r7-bitstream-certification-adoption/1', created_utc=datetime.now(timezone.utc).isoformat(),
    action='Pin completed K output bindings and adopt the existing independent certificate chain',
    functional_baseline=policy['functional_baseline_commit'], board_allowlist=policy['board_allowlist'],
    board_serial='21770433G02LA', component_is_not_complete_EC=True,
    independent_certificate_pending_at_observation=True, new_fpga_samples=0,
    automatic_next_action='Existing r7 certificate -> both board locks -> 21-only directed replay -> same-bit application replay -> existing readonly r2 metrics',
    MCrams='NOT_FIT_POSTOPT_2420482_LUT_EXCESS_1116802; preserve original checkpoint write and allow existing consumer to ingest final result',
    source_manifests={str(C / name): sha(C / name) for name in ['inputs.json', 'runtime-inputs.json', 'physical-clock-contract.json']},
    evidence={str(p): sha(p) for p in sorted(A.glob('*.json'))},
    implementation_or_timing_gates_changed=False, new_CAD=False, new_job_requests=[], device_operations=[])
save('receipt.json', receipt)
print(json.dumps(dict(receipt=str(A/'receipt.json'), receipt_sha256=sha(A/'receipt.json'),
    K_output_count=len(outputs), K_bitstream_sha256=result['bitstream_sha256'],
    MCrams_status='NOT_FIT_POSTOPT', MCrams_luts=2420482, independent_audit='EXISTING_LIVE_PID3277916', new_jobs=[]), sort_keys=True))
