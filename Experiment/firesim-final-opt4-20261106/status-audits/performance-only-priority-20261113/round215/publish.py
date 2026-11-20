#!/usr/bin/python3
"""Publish exact round215 evidence; no CAD, service or device control."""
import datetime as dt
import fcntl
import hashlib
import json
import os
from pathlib import Path

A = Path(__file__).resolve().parent
D = A.parents[2]
P = D/'performance-only-20261113'
S = D/'build-logs/Opt4-performance-only-support-r6-20261113'

def read(p):
    return json.loads(Path(p).read_text())

def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()

def ref(p):
    return dict(path=str(p), sha256=sha(p))

def create(p, data):
    with Path(p).open('x') as f:
        json.dump(data, f, indent=2)
        f.write('\n')

def replace(p, data, before):
    assert p.read_bytes() == before, ('concurrent update', str(p))
    temp = p.with_name(p.name+'.round215.tmp')
    create(temp, data)
    os.replace(temp, p)

e = read(A/'evidence-readiness.json')
start, end = read(A/'owner-start.json'), read(A/'owner-end.json')
physical = read(A/'followthrough-audit.json')
assert e['authenticated_files'] == 922 and e['protected_checker_artifacts'] == 644
assert start['observation_seconds'] >= 600
assert start['controller']['pid'] == end['controller']['pid'] == 355419
assert start['controller']['start_ticks'] == end['controller']['start_ticks'] == '35248517'
assert end['status'] == read(S/'cad-state.json')['status'] == 'RUNNING_IMPLEMENTATION'
assert physical['current_phase'] == 'Phase 18 Critical Cell Optimization' and not physical['current_log_errors']
assert physical['third_rewire_progress']['optimized_nets_or_cells'] == 38
assert physical['third_rewire_progress']['created_cells'] == 19
assert physical['third_rewire_progress']['completion_checksum'] == '12e316824'
assert physical['third_critical_cell_progress']['processed_unique_nets'] == 7
assert physical['third_critical_cell_progress']['replication_outcome_lines'] == 6
assert physical['third_critical_cell_progress']['nonreplication_outcome_lines'] == 1
assert not physical['third_critical_cell_progress']['phase_completed']
assert all(not (S/name).exists() for name in [
    'implementation-result.json', 'timing_bitstream-result.json', 'postopt-result.json'])
for ledger in ['full_EC_ledger', 'prototype_ledger']:
    assert sha(e[ledger]['path']) == e[ledger]['sha256']
assert all(sha(p) == h for p, h in physical['artifacts'].items())
cpu = sum(x['cpu_seconds'] for row in [start, end] for x in row['process_cpu_deltas'])
growth = start['log_growth_bytes']+end['log_growth_bytes']
observed = start['observation_seconds']+end['observation_seconds']
assert growth > 0 and cpu > 0
utc = dt.datetime.now(dt.timezone.utc).isoformat()
wns, tns = physical['intermediate_estimated_WNS_ns'], physical['intermediate_estimated_TNS_ns']
stage = 'phys_opt_design_third_critical_cell_optimization'
summary = (
    'EC Performance-Only 6fada307: same R6 completed the third rewire pass '
    '(38 nets optimized, 19 cells created) and advanced to Phase 18 Critical '
    'Cell Optimization. The saved log contains 7/30 third-pass candidate outcomes '
    '(6 replicated, 1 declined). '
    f'{observed:.0f}s since prior durable observation, +{growth} log bytes, '
    f'+{cpu:.1f} process CPU-seconds. Authenticated 922 pinned artifacts including '
    '644 protected checker artifacts. Actual whole-checker PASS131/131/131 and '
    'complete-shell postopt capacity FIT1023687/1303680LUT remain valid. '
    f'Intermediate estimated WNS={wns:.3f}ns; final timing, bitstream, certification '
    'and card21 runtime pending.')
old_owner = read(P/'ACTIVE_OWNER.json')
assert old_owner['latest_round']['round'] == 214
next_action = old_owner['next_action']
scope = (
    e['profile']+'\n\n'+summary+'\n\n'
    'Existing R6 PID355419/start35248517 and Vivado PID461680/start35811903 retain '
    'the original service cgroup and boot d6c6e410-10ad-4326-86ba-79b657eabd96. '
    'The preserved native implementation log authenticates Phase17 Rewire completion '
    'with checksum12e316824 (38 nets optimized, 19 cells created). Phase18 is '
    'in progress with 7/30 distinct candidate outcomes (6 replicated, 1 declined) '
    'in the snapshot; '
    'no ERROR line appears in the captured log. No CAD restart or duplicate occurred.\n\n'
    'Postopt capacity remains 1,023,687 LUT/279,993 headroom; the earlier placed '
    'checkpoint remains 1,015,701 LUT/287,979 headroom. Final utilization is pending. '
    f'Intermediate WNS={wns:.3f}ns and TNS={tns:.3f}ns leave timing closure open. '
    'Route, final setup/hold/pulse/skew/clock and unconstrained-path coverage, DRC, '
    'bitstream and exact physical/ABI/software certification remain pending.\n\n'
    'Existing complete MCRams-host Canneal project400 evidence is authenticated: '
    '1,759,001 target edges, 131 allocations, 131 real full_compare results, '
    '131 BOOM acceptances, checker counts33/33/33/32, pending0, edge errors0, '
    'checksum/application PASS and exit0. This is finite actual host-model '
    'correctness. FPGA, simmedium, Slowdown and universal equivalence require '
    'their own evidence. No simulation, checker analysis, model/RTL generation, '
    'observer linking or driver compilation was repeated.\n\n'
    'The prepared postflight and exact certificate binder are authenticated and '
    'wait for actual physical completion and exact R6 cgroup release. The existing '
    'runtime owner remains waiting without children and holds its original lock. '
    'No device IO, service/waiter creation, source/hardware/constraint edits, '
    'CPU/SVB session control or ledger changes occurred. Full EC/PALIMPSEST and '
    'Performance-Only evidence remain separate. Card21-only identity/locks and '
    'new-image physical/ABI/software certification precede device operations; '
    'real boot/checker/LSL-SVB/isolation/drain checks precede eight first samples. '
    'Unsupported diagnostic counters cannot establish drain.\n\n'
    'Audit scripts are new round-specific evidence copies; live controllers and '
    'pinned inputs were untouched.\n\nNext: '
    +next_action+'\n')
with (A/'EXACT_SCOPE.md').open('x') as f:
    f.write(scope)
receipt = read(D/'area-sprint-20261112/round-00214.json')
receipt.update(round=215, utc=utc, summary=summary, next_action=next_action,
    outcome='WAITING_ACTIVE_JOB', retry_after_seconds=600,
    intermediate_estimated_WNS_ns=wns, intermediate_estimated_TNS_ns=tns,
    actual_physical_progress=ref(A/'followthrough-audit.json'),
    real_progress=dict(stage=stage, current_phase=physical['current_phase'],
        completed_physical_optimization_phases=physical['completed_physical_optimization_phases'],
        third_rewire_progress=physical['third_rewire_progress'],
        third_critical_cell_progress=physical['third_critical_cell_progress'],
        phase_count_scope=physical['phase_count_scope'],
        authenticated_artifacts=922, protected_checker_artifacts=644,
        whole_CAD_observation_seconds=observed, CAD_log_growth_bytes=growth,
        process_CPU_seconds=cpu),
    evidence=[ref(A/n) for n in ['observe.py','capture_followthrough.py','owner-start.json','owner-end.json',
        'evidence-readiness.json','followthrough-audit.json','EXACT_SCOPE.md','publish.py']],
    physical_readiness=e['physical_readiness'], fullshell_ledger=e['full_EC_ledger'],
    prototype_ledger=e['prototype_ledger'], launched_jobs=[],
    no_new_service_or_waiter=True, no_FPGA_IO=True)
receipt_path = D/'area-sprint-20261112/round-00215.json'
create(receipt_path, receipt)
latest = dict(round=215, utc=utc, summary=summary, next_action=next_action,
    outcome='WAITING_ACTIVE_JOB', receipt=str(receipt_path), receipt_sha256=sha(receipt_path))
with (P/'ACTIVE_OWNER.json.lock').open('a') as lock:
    fcntl.flock(lock, fcntl.LOCK_EX)
    path=P/'ACTIVE_OWNER.json'; before=path.read_bytes(); owner=json.loads(before)
    assert owner['latest_round']['round'] == 214 and owner['hardware_commit'] == receipt['hardware_commit']
    (A/'ACTIVE_OWNER.before.json').write_bytes(before)
    owner.update(utc=utc, current_stage=stage, placement_phase=physical['current_phase'],
        third_rewire_progress=physical['third_rewire_progress'],
        third_critical_cell_progress=physical['third_critical_cell_progress'],
        intermediate_estimated_WNS_ns=wns, intermediate_estimated_TNS_ns=tns,
        latest_round=latest, controller_identity=end['controller'],
        owner_observation=str(A/'owner-end.json'), owner_observation_sha256=sha(A/'owner-end.json'),
        latest_evidence_readiness=ref(A/'evidence-readiness.json'),
        actual_physical_progress=ref(A/'followthrough-audit.json'))
    replace(path, owner, before)
with (D/'unattended-opt4/campaign-policy.lock').open('a') as lock:
    fcntl.flock(lock, fcntl.LOCK_EX)
    path=D/'unattended-opt4/campaign-policy.json'; before=path.read_bytes(); policy=json.loads(before)
    (A/'campaign-policy.before.json').write_bytes(before)
    policy['performance_only_priority_20261113'].update(active_owner=owner, latest_exact_scope=ref(A/'EXACT_SCOPE.md'))
    policy['round215_performance_only_physical_optimization_progress_20261113']=latest
    replace(path, policy, before)
path=D/'area-sprint-20261112/latest-round.json'; before=path.read_bytes()
assert json.loads(before)['round'] == 214
(A/'latest-round.before.json').write_bytes(before); replace(path, latest, before)
with (P/'CONTINUATION.md').open('a') as f:
    f.write('\nRound215: '+summary+' Receipt '+str(receipt_path)+'. '+next_action+'\n')
path=P/'LATEST.md'; (A/'LATEST.md.before').write_bytes(path.read_bytes())
path.write_text(e['profile']+'\n\n'+summary+'\n\n'+next_action+'\n\nEvidence: '+str(A/'EXACT_SCOPE.md')+'\n')
path=P/'LATEST.json'; before=path.read_bytes(); prototype=json.loads(before)
assert prototype['hardware_commit'] == receipt['hardware_commit']
(A/'LATEST.json.before').write_bytes(before)
prototype.update(updated_utc=utc, capacity_FIT=True, actual_postopt_LUT=1023687,
    LUT_headroom=279993, actual_checker_execution_tested=True,
    actual_integrated_checker_execution_passed=True,
    actual_complete_shell_postopt=e['exact_capacity_receipt'],
    actual_complete_checker_link_validation=e['exact_checker_receipt'],
    actual_checker_counts=e['actual_checker_counts'],
    stage='CAPACITY_FIT_PHYSICAL_IMPLEMENTATION_RUNNING', cad_stage=stage,
    placement_phase=physical['current_phase'], bitstream=None,
    physical_timing_passed=False, runtime_certified=False,
    intermediate_estimated_WNS_ns=wns, intermediate_estimated_TNS_ns=tns,
    exact_scope_report=str(A/'EXACT_SCOPE.md'), latest_round=latest,
    whole_CAD_observation_seconds=observed,
    actual_physical_progress=ref(A/'followthrough-audit.json'), no_FPGA_IO=True)
replace(path, prototype, before)
create(A/'publication.json', dict(schema='ec-performance-only-round215-publication/1', utc=utc,
    round_receipt=ref(receipt_path), ACTIVE_OWNER_sha256=sha(P/'ACTIVE_OWNER.json'),
    prototype_LATEST_sha256=sha(P/'LATEST.json'),
    campaign_policy_sha256=sha(D/'unattended-opt4/campaign-policy.json'),
    full_EC_ledger_unchanged=True, prototype_ledger_unchanged=True,
    no_FPGA_IO=True, no_service_restart=True, publisher_source=ref(__file__)))
print(json.dumps(latest))
