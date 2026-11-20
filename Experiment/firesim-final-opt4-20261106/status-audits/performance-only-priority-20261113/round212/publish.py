#!/usr/bin/python3
"""Publish exact round212 evidence; do not control hardware, jobs or live inputs."""
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


def create(p, row):
    with Path(p).open('x') as f:
        json.dump(row, f, indent=2); f.write('\n')


def replace(p, row, before):
    assert p.read_bytes() == before, ('concurrent update', str(p))
    temp = p.with_name(p.name+'.round212.tmp')
    create(temp, row)
    os.replace(temp, p)


e = read(A/'evidence-readiness.json')
start, end = read(A/'owner-start.json'), read(A/'owner-end.json')
physical = read(A/'followthrough-audit.json')
assert e['authenticated_files'] == 922 and e['protected_checker_artifacts'] == 644
assert start['observation_seconds'] >= 600
assert start['controller']['pid'] == end['controller']['pid'] == 355419
assert start['controller']['start_ticks'] == end['controller']['start_ticks'] == '35248517'
assert end['status'] == read(S/'cad-state.json')['status'] == 'RUNNING_IMPLEMENTATION'
assert physical['current_phase'] == 'Phase 12 Critical Cell Optimization'
assert not physical['current_log_errors'] and physical['second_rewire_progress']['phase_completed']
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
wns = physical['intermediate_estimated_WNS_ns']
critical = physical['second_critical_cell_progress']
stage = 'phys_opt_design_second_critical_cell'
summary = (
    'EC Performance-Only 6fada307: same R6 completed the second rewire pass '
    '(20 nets optimized, 13 cells created) and advanced to Phase 12 Critical Cell Optimization. '
    f'The saved log contains {critical["processed_unique_nets"]}/30 second-pass candidate outcomes '
    f'({critical["replication_outcome_lines"]} replicated, {critical["nonreplication_outcome_lines"]} declined). '
    f'{observed:.0f}s since prior durable observation, +{growth} log bytes, +{cpu:.1f} process CPU-seconds. '
    'Authenticated 922 pinned artifacts including 644 protected checker artifacts. '
    'Actual whole-checker PASS131/131/131 and complete-shell postopt capacity '
    'FIT1023687/1303680LUT remain valid. '
    f'Intermediate estimated WNS={wns:.3f}ns; final timing, bitstream, certification and card21 runtime pending.')
old_owner = read(P/'ACTIVE_OWNER.json')
assert old_owner['latest_round']['round'] == 211
next_action = old_owner['next_action']
scope = (
    e['profile']+'\n\n'+summary+'\n\n'
    'The existing R6 controller PID355419/start35248517 and Vivado PID461680/start35811903 '
    'retain their original service cgroup and boot d6c6e410-10ad-4326-86ba-79b657eabd96. '
    'The emitted Phase11 checksum14eb45519 authenticates completion of the second rewiring '
    'pass; Phase12 remains incomplete in the preserved log. No ERROR line appears. '
    'Postopt capacity remains1,023,687LUT/279,993headroom; the earlier placed checkpoint '
    'remains1,015,701LUT/287,979headroom. Final physical utilization is pending. '
    f'Intermediate WNS={wns:.3f}ns, TNS={physical["intermediate_estimated_TNS_ns"]:.3f}ns and '
    'the earlier congestion warning leave timing closure unproven. Final route, setup/hold, '
    'pulse/skew, clock and unconstrained-path coverage, DRC and bitstream remain pending.\n\n'
    'The phase-count parser now bounds each phase at its next start. It records the first '
    'and second critical-cell passes separately, so later outcomes cannot inflate the first '
    'pass. This changes evidence bookkeeping only. The initial read-only round212 observer '
    'used a current-round predecessor path due to text replacement and stopped before '
    'writing an observation. The original script is preserved; observe-r2.py corrects that '
    'path to the exact round211 observation. No live controller, input, CAD or oracle changed.\n\n'
    'Existing actual complete MCRams-host Canneal project400 evidence remains authenticated: '
    '1,759,001 target edges; 131 allocations, 131 real full_compare results, 131 BOOM acceptances; '
    'four checkers33/33/33/32; pending0; edge errors0; checksum/application PASS and exit0. '
    'No simulation, checker analysis, observer link, model/RTL generation or driver build '
    'was repeated. This establishes finite host-model correctness. FPGA, Linux simmedium, '
    'Slowdown and universal equivalence claims require their own evidence.\n\n'
    'The prepared postflight and exact physical/ABI/software binder correctly wait for '
    'actual physical completion and exact R6 cgroup release. The existing runtime owner '
    'remains waiting without children and retains its lock. No new service, waiter, hardware '
    'cut, CAD strategy, constraint change, restart, CPU/SVB session control or FPGA IO occurred. '
    'Full EC/PALIMPSEST and prototype ledgers remain separate and unchanged. Exact physical '
    'certification and safe existing-owner/card21-lock handoff precede real card21 boot, '
    'checker, LSL/SVB preservation, cache isolation and drain, then eight first simmedium '
    'samples. Unsupported diagnostic counters cannot establish drain.\n\nNext: '+next_action+'\n')
with (A/'EXACT_SCOPE.md').open('x') as f:
    f.write(scope)
receipt = read(D/'area-sprint-20261112/round-00211.json')
receipt.update(round=212, utc=utc, summary=summary, next_action=next_action,
    outcome='WAITING_ACTIVE_JOB', retry_after_seconds=600,
    intermediate_estimated_WNS_ns=wns,
    intermediate_estimated_TNS_ns=physical['intermediate_estimated_TNS_ns'],
    actual_placed_checkpoint=physical['adopted_placed_checkpoint'],
    actual_physical_progress=ref(A/'followthrough-audit.json'),
    real_progress=dict(stage=stage, current_phase=physical['current_phase'],
        completed_physical_optimization_phases=physical['completed_physical_optimization_phases'],
        critical_cell_progress=physical['critical_cell_progress'],
        second_critical_cell_progress=critical,
        second_rewire_progress=physical['second_rewire_progress'],
        phase_count_scope=physical['phase_count_scope'],
        authenticated_artifacts=922, protected_checker_artifacts=644,
        whole_CAD_observation_seconds=observed, CAD_log_growth_bytes=growth, process_CPU_seconds=cpu),
    evidence=[ref(A/n) for n in ['observe.py','observe-r2.py','observer-recovery.json',
        'capture_followthrough.py','owner-start.json','owner-end.json','evidence-readiness.json',
        'followthrough-audit.json','EXACT_SCOPE.md','publish.py']],
    physical_readiness=e['physical_readiness'],
    fullshell_ledger=e['full_EC_ledger'], prototype_ledger=e['prototype_ledger'])
receipt_path = D/'area-sprint-20261112/round-00212.json'
create(receipt_path, receipt)
latest = dict(round=212, utc=utc, summary=summary, next_action=next_action,
    outcome='WAITING_ACTIVE_JOB', receipt=str(receipt_path), receipt_sha256=sha(receipt_path))
with (P/'ACTIVE_OWNER.json.lock').open('a') as lock:
    fcntl.flock(lock, fcntl.LOCK_EX)
    path=P/'ACTIVE_OWNER.json'; before=path.read_bytes(); owner=json.loads(before)
    assert owner['latest_round']['round'] == 211 and owner['hardware_commit'] == receipt['hardware_commit']
    (A/'ACTIVE_OWNER.before.json').write_bytes(before)
    owner.update(utc=utc, current_stage=stage, placement_phase=physical['current_phase'],
        critical_cell_progress=physical['critical_cell_progress'], second_critical_cell_progress=critical,
        second_rewire_progress=physical['second_rewire_progress'],
        intermediate_estimated_WNS_ns=wns, intermediate_estimated_TNS_ns=physical['intermediate_estimated_TNS_ns'],
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
    policy['round212_performance_only_physical_optimization_progress_20261113']=latest
    replace(path, policy, before)
path=D/'area-sprint-20261112/latest-round.json'; before=path.read_bytes()
assert json.loads(before)['round'] == 211
(A/'latest-round.before.json').write_bytes(before); replace(path, latest, before)
with (P/'CONTINUATION.md').open('a') as f:
    f.write('\nRound212: '+summary+' Receipt '+str(receipt_path)+'. '+next_action+'\n')
path=P/'LATEST.md'; (A/'LATEST.md.before').write_bytes(path.read_bytes())
path.write_text(e['profile']+'\n\n'+summary+'\n\n'+next_action+'\n\nEvidence: '+str(A/'EXACT_SCOPE.md')+'\n')
create(A/'publication.json', dict(schema='ec-performance-only-round212-publication/1', utc=utc,
    round_receipt=ref(receipt_path), ACTIVE_OWNER_sha256=sha(P/'ACTIVE_OWNER.json'),
    campaign_policy_sha256=sha(D/'unattended-opt4/campaign-policy.json'),
    full_EC_ledger_unchanged=True, prototype_ledger_unchanged=True,
    no_FPGA_IO=True, no_service_restart=True, publisher_source=ref(__file__)))
print(json.dumps(latest))
