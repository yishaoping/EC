#!/usr/bin/python3
"""Publish source-bound round207 evidence without controlling any jobs."""
import datetime as dt
import fcntl
import hashlib
import json
import os
from pathlib import Path

D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
A = Path(__file__).resolve().parent
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
        json.dump(row, f, indent=2);f.write('\n')


def replace(p, row, before):
    assert p.read_bytes() == before, ('concurrent update', str(p))
    temp = p.with_name(p.name+'.round207.tmp')
    create(temp, row)
    os.replace(temp, p)


e = read(A/'evidence-readiness.json')
start, end = read(A/'owner-start.json'), read(A/'owner-end.json')
physical = read(A/'followthrough-audit.json')
assert e['authenticated_files'] == 922 and e['protected_checker_artifacts'] == 644
assert start['observation_seconds'] >= 600
assert start['controller']['pid'] == end['controller']['pid'] == 355419
assert start['controller']['start_ticks'] == end['controller']['start_ticks'] == '35248517'
assert end['status'] == 'RUNNING_IMPLEMENTATION'
assert physical['current_phase'] == 'Phase 7 Critical Cell Optimization' and not physical['current_log_errors']
assert all(not (S/name).exists() for name in [
    'implementation-result.json', 'timing_bitstream-result.json', 'postopt-result.json'])
for ledger in ['full_EC_ledger', 'prototype_ledger']:
    assert sha(e[ledger]['path']) == e[ledger]['sha256']
cpu = sum(x['cpu_seconds'] for row in [start, end] for x in row['process_cpu_deltas'])
growth = start['log_growth_bytes']+end['log_growth_bytes']
observed = start['observation_seconds']+end['observation_seconds']
assert growth > 0 and cpu > 0
utc = dt.datetime.now(dt.timezone.utc).isoformat()
wns = physical['intermediate_estimated_WNS_ns']
summary = (
    'EC Performance-Only 6fada307: same R6 completed rewiring (63 nets optimized,29 instances created) '
    'and advanced to critical-cell optimization (30 candidates). '
    f'{observed:.0f}s since prior durable observation, +{growth} log bytes, +{cpu:.1f} process CPU-seconds. '
    'Authenticated 922 pinned artifacts including 644 protected checker artifacts; existing actual '
    'whole-checker PASS131/131/131 and complete-shell postopt capacity FIT1023687/1303680LUT remain valid. '
    f'Intermediate estimated WNS={wns:.3f}ns; final timing, bitstream, certification and card21 runtime pending.')
old_owner = read(P/'ACTIVE_OWNER.json')
next_action = old_owner['next_action']
scope = (
    e['profile']+'\n\n'+summary+'\n\n'
    'The existing R6 controller PID355419/start35248517 and Vivado PID461680/start35811903 '
    'remain in their original service cgroup on bootd6c6e410-10ad-4326-86ba-79b657eabd96. '
    'Emitted checksums prove rewiring completed:63 nets optimized and29 instances created. '
    'The same job identified30 critical-cell candidates and is performing critical-cell optimization; '
    'no ERROR line appears in the preserved implementation log. '
    'The postopt capacity receipt is1023687LUT/279993headroom. The earlier placed checkpoint '
    'is1015701LUT/287979headroom and has not been presented as final physical utilization. '
    f'Intermediate WNS={wns:.3f}ns,TNS={physical["intermediate_estimated_TNS_ns"]:.3f}ns and the '
    'earlier congestion warning leave timing closure unproven. Final route/setup/hold/pulse/skew, '
    'clock and unconstrained-path coverage,DRC,bitstream remain pending.\n\n'
    'Existing actual complete MCRams-host Canneal project400 evidence remains authenticated: '
    '1759001targetedges,131allocations,131real full_compare results,131BOOMacceptances, '
    'all4checkers33/33/33/32,pending0,edgeerrors0,checksumPASS,applicationexit0. '
    'No simulation, checker analysis, observer link, model/RTL generation or driver build was repeated. '
    'This establishes finite host-model correctness; FPGA validation,simmedium,Slowdown and universal '
    'equivalence remain outside its scope.\n\n'
    'The prepared final-checkpoint postflight and exact physical/ABI/software certificate binder '
    'correctly wait for actual physical outputs and exact R6 cgroup release. The existing runtime '
    'owner remains waiting without children and retains its lock. No new service, waiter, cut, '
    'CAD strategy, constraint change, restart, CPU/SVB session control or FPGA IO occurred. '
    'All authenticated evidence and CAD inputs were preserved. Full EC/PALIMPSEST and prototype '
    'ledgers remain separate and unchanged. '
    'After all exact gates pass, require safe existing-owner handoff and21locks, then real card21 '
    'boot,checker,LSL/SVB preservation,cache isolation and drain before eight first simmedium samples. '
    'Unsupported diagnostic counters cannot establish drain.\n\nNext: '+next_action+'\n')
with (A/'EXACT_SCOPE.md').open('x') as f:
    f.write(scope)
receipt = read(D/'area-sprint-20261112/round-00206.json')
receipt.update(round=207, utc=utc, summary=summary, next_action=next_action,
    outcome='WAITING_ACTIVE_JOB', retry_after_seconds=600,
    intermediate_estimated_WNS_ns=wns,
    intermediate_estimated_TNS_ns=physical['intermediate_estimated_TNS_ns'],
    actual_placed_checkpoint=physical['adopted_placed_checkpoint'],
    actual_physical_progress=ref(A/'followthrough-audit.json'),
    real_progress=dict(stage='phys_opt_design_critical_cell_optimization', current_phase=physical['current_phase'],
        completed_physical_optimization_phases=physical['completed_physical_optimization_phases'],
        authenticated_artifacts=922, protected_checker_artifacts=644,
        whole_CAD_observation_seconds=observed, CAD_log_growth_bytes=growth, process_CPU_seconds=cpu),
    evidence=[ref(A/n) for n in ['observe.py','capture_followthrough.py','owner-start.json','owner-end.json','evidence-readiness.json',
        'followthrough-audit.json','EXACT_SCOPE.md','publish.py']],
    physical_readiness=e['physical_readiness'],
    fullshell_ledger=e['full_EC_ledger'], prototype_ledger=e['prototype_ledger'])
receipt_path = D/'area-sprint-20261112/round-00207.json'
create(receipt_path, receipt)
latest = dict(round=207, utc=utc, summary=summary, next_action=next_action,
    outcome='WAITING_ACTIVE_JOB', receipt=str(receipt_path), receipt_sha256=sha(receipt_path))
with (P/'ACTIVE_OWNER.json.lock').open('a') as lock:
    fcntl.flock(lock, fcntl.LOCK_EX)
    path=P/'ACTIVE_OWNER.json';before=path.read_bytes();owner=json.loads(before)
    assert owner['latest_round']['round'] == 206 and owner['hardware_commit'] == receipt['hardware_commit']
    (A/'ACTIVE_OWNER.before.json').write_bytes(before)
    owner.update(utc=utc, current_stage='phys_opt_design_critical_cell_optimization', placement_phase=physical['current_phase'],
        intermediate_estimated_WNS_ns=wns, intermediate_estimated_TNS_ns=physical['intermediate_estimated_TNS_ns'],
        latest_round=latest, controller_identity=end['controller'],
        owner_observation=str(A/'owner-end.json'), owner_observation_sha256=sha(A/'owner-end.json'),
        latest_evidence_readiness=ref(A/'evidence-readiness.json'),
        actual_physical_progress=ref(A/'followthrough-audit.json'))
    replace(path, owner, before)
with (D/'unattended-opt4/campaign-policy.lock').open('a') as lock:
    fcntl.flock(lock, fcntl.LOCK_EX)
    path=D/'unattended-opt4/campaign-policy.json';before=path.read_bytes();policy=json.loads(before)
    (A/'campaign-policy.before.json').write_bytes(before)
    policy['performance_only_priority_20261113'].update(active_owner=owner, latest_exact_scope=ref(A/'EXACT_SCOPE.md'))
    policy['round207_performance_only_physical_optimization_progress_20261113']=latest
    replace(path, policy, before)
path=D/'area-sprint-20261112/latest-round.json';before=path.read_bytes()
assert json.loads(before)['round']==206
(A/'latest-round.before.json').write_bytes(before);replace(path, latest, before)
with (P/'CONTINUATION.md').open('a') as f:
    f.write('\nRound207: '+summary+' Receipt '+str(receipt_path)+'. '+next_action+'\n')
path=P/'LATEST.md';(A/'LATEST.md.before').write_bytes(path.read_bytes())
path.write_text(e['profile']+'\n\n'+summary+'\n\n'+next_action+'\n\nEvidence: '+str(A/'EXACT_SCOPE.md')+'\n')
create(A/'publication.json', dict(schema='ec-performance-only-round207-publication/1', utc=utc,
    round_receipt=ref(receipt_path), ACTIVE_OWNER_sha256=sha(P/'ACTIVE_OWNER.json'),
    campaign_policy_sha256=sha(D/'unattended-opt4/campaign-policy.json'),
    full_EC_ledger_unchanged=True, prototype_ledger_unchanged=True,
    no_FPGA_IO=True, no_service_restart=True, publisher_source=ref(__file__)))
print(json.dumps(latest))
