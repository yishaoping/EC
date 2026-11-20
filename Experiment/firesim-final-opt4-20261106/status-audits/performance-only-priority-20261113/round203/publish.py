#!/usr/bin/python3
"""Publish round203 evidence only; never alter a live job, lock, or device."""
from pathlib import Path
import datetime as dt
import fcntl
import hashlib
import json
import os

D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
A = Path(__file__).resolve().parent
P = D/'performance-only-20261113'
S = D/'build-logs/Opt4-performance-only-support-r6-20261113'
HW = '6fada307bb77be90b39720d3f95404fece0e431b'
SID = '461e1b98833d1a78a8bd27c0eed2d3353c648dfbf29ae5588db31bbce0f77369'
PROFILE = 'EC Performance-Only: data preservation + cache isolation'


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def ref(p):
    return dict(path=str(p), sha256=sha(p))


def create(p, row):
    with Path(p).open('x') as f:
        json.dump(row, f, indent=2)
        f.write('\n')


def replace(p, row, old):
    assert p.read_bytes() == old, ('concurrent update', str(p))
    temp = p.with_name(p.name+'.round203.tmp')
    with temp.open('x') as f:
        json.dump(row, f, indent=2)
        f.write('\n')
    os.replace(temp, p)


evidence = read(A/'evidence-readiness.json')
start, end = read(A/'owner-start.json'), read(A/'owner-end.json')
assert evidence['authenticated_files'] == 922 and evidence['protected_checker_artifacts'] == 644
assert start['observation_seconds'] >= 600
assert end['controller']['pid'] == start['controller']['pid'] == 355419
assert end['controller']['start_ticks'] == start['controller']['start_ticks'] == '35248517'
assert end['status'] == 'RUNNING_IMPLEMENTATION'
assert not end['bitstream_stage_receipt_exists'] and not end['outer_result_exists']
assert not (S/'timing_bitstream-result.json').exists() and not (S/'postopt-result.json').exists()
assert sha(D/'area-sprint-20261112/fullshell-adoptions.json') == evidence['full_EC_ledger']['sha256']
assert sha(P/'fullshell-adoptions.json') == evidence['prototype_ledger']['sha256']
utc = dt.datetime.now(dt.timezone.utc).isoformat()
cpu_start = sum(r['cpu_seconds'] for r in start['process_cpu_deltas'])
cpu_end = sum(r['cpu_seconds'] for r in end['process_cpu_deltas'])
cpu = cpu_start + cpu_end
growth = start['log_growth_bytes'] + end['log_growth_bytes']
observed = start['observation_seconds'] + end['observation_seconds']
summary = (f'EC Performance-Only6fada307: same R6 advanced to timing optimization within place_design ({end["placement_phase"]}); '
    f'{observed:.0f}s since prior durable observation, +{growth} log bytes, '
    f'+{cpu:.1f} process CPU-seconds. Authenticated922 pinned artifacts, including644 protected checker artifacts; '
    'actual whole-checker PASS131/131/131 and complete-shell capacity FIT1023687/1303680LUT remain valid. '
    'Physical timing/bitstream/certificate and card21 runtime remain pending.')
old_owner = read(P/'ACTIVE_OWNER.json')
next_action = old_owner['next_action']
scope = (PROFILE+'\n\n'+summary+'\n\n'
    'The capacity receipt binds the actual whole U280 shell, zero functional blackboxes, hardware6fada307, '
    'source461e1b98833d1a78a8bd27c0eed2d3353c648dfbf29ae5588db31bbce0f77369, '
    'and actual reports. Resources:1023687LUT,1019173FF,15706CARRY8,115DSP,678.5BRAM,0URAM. '
    'LUT headroom279993. Capacity FIT is established; physical timing closure is pending.\n\n'
    'Authenticated the existing whole-checker result and its unchanged raw log, preserved events, model/objects, '
    'source inputs, generated host RTL, shell IPs, staged driver/software and future physical/certificate entry points. '
    'No checker analysis, simulation, model build, driver build, synthesis or place/route was repeated. '
    'Actual Canneal project400 complete-host validation:1759001targetedges,131allocations,131real full_compare, '
    '131BOOMacceptances,per-checker33/33/33/32,pending0,sample_errors0,checksumPASS,applicationexit0. '
    'The preserved R3 postparser failure does not invalidate this same-run native-stdout analysis. '
    'No local checker latency is inferred. This finite CPU model validation is not FPGA execution, '
    'Linux simmedium, Slowdown data or universal equivalence.\n\n'
    'The same PID355419/start35248517/bootd6c6e410-10ad-4326-86ba-79b657eabd96 and Vivado descendant '
    'remain in the exact R6 service cgroup. R6 is still within place_design; its post-placement timing optimization phase does not establish final timing closure. The existing immutable implementation continues to phys_opt_design and route_design; the staged final-checkpoint checks cover setup/hold/pulse/skew/clock coverage/unconstrained endpoints/routes/DRC. Original placement inputs are untouched; no new cuts or duplicate CAD. '
    'Both staged report-only physical postflight and certificate binding explicitly refuse to proceed until their '
    'actual physical evidence prerequisites exist; no successor job/service/waiter was installed. '
    'The existing root runtime owner remains in WAITING_FOR_DERIVED_BITSTREAM with no child and holds '
    'opt4-fit-runtime.lock. This observation does not authorize bypassing any lock or constitute a handoff. '
    'Recheck exact physical/ABI/software certification, PID/cgroup and every card21 lock at the actual handoff.\n\n'
    'Integrated card21 checker/storage/isolation/drain evidence is still required before simmedium. '
    'The staged runtime intentionally waits for that evidence; generic boot/smoke or the CPU checker PASS alone '
    'cannot satisfy it. Omitted diagnostics remain unsupported and cannot serve as drain evidence. '
    'No FPGA IO or CPU/SVB session control occurred. Prototype capacity remains outside the full-EC/PALIMPSEST ledger.\n\n'
    'Next: '+next_action+'\n')
with (A/'EXACT_SCOPE.md').open('x') as f:
    f.write(scope)
evidence_refs = [ref(A/n) for n in ['observe.py','owner-start.json','owner-end.json','evidence-readiness.json','followthrough-audit.json','EXACT_SCOPE.md']]
receipt = dict(schema='ec-area-sprint-round-evidence/1', round=203, utc=utc,
    outcome='WAITING_ACTIVE_JOB', summary=summary, next_action=next_action, retry_after_seconds=600,
    hardware_commit=HW, source_id=SID, functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
    profile=PROFILE, full_PALIMPSEST=False, hardware_unchanged=True,
    experiment_commit='cef2d0bd09ec1480db0f29034c2b0a29a28b949f',
    checker_analysis_commit='02436d48a8dbc3a16f92c9f689f8fb391e89d5c5',
    source_binding=old_owner['source_binding'], source_binding_sha256=old_owner['source_binding_sha256'],
    prototype_FIT=True, capacity_FIT=True, prototype_area_LUT=1023687, LUT_headroom=279993,
    physical_timing_passed=False, bitstream_exists=False, runtime_certified=False,
    actual_integrated_checker_execution_passed=True, actual_checker_counts=evidence['actual_checker_counts'],
    checker_scope=read(P/'checker-whole-link-validation-r1.json')['scope'],
    real_progress=dict(stage='placer_timing_optimization', placement_phase=end['placement_phase'], authenticated_artifacts=922,
        protected_checker_artifacts=644, whole_CAD_observation_seconds=start['observation_seconds']+end['observation_seconds'],
        CAD_log_growth_bytes=growth,
        process_CPU_seconds=cpu),
    launched_jobs=[], adopted_not_launched_jobs=['ec-performance-only-support-r6-20261113.service'],
    evidence=evidence_refs, physical_readiness=evidence['physical_readiness'],
    existing_runtime_lock_preserved=True, handoff_performed=False,
    no_FPGA_IO=True, no_CPU_or_SVB_session_control=True, no_healthy_restart=True,
    no_new_cuts=True, no_new_service_or_waiter=True, no_new_intelligent_supervisor=True,
    no_subagents=True, no_driver_rebuild=True, no_simulation_or_checker_analysis_repeated=True,
    fullshell_ledger=evidence['full_EC_ledger'], prototype_ledger=evidence['prototype_ledger'],
    postflight_entry=old_owner['final_checkpoint_checks']['entry'],
    certificate_entry=old_owner['exact_certificate_binding']['entry'])
receipt_path = D/'area-sprint-20261112/round-00202.json'
create(receipt_path, receipt)
latest = dict(round=203, utc=utc, summary=summary, next_action=next_action,
    outcome='WAITING_ACTIVE_JOB', receipt=str(receipt_path), receipt_sha256=sha(receipt_path))
with (P/'ACTIVE_OWNER.json.lock').open('a') as lock:
    fcntl.flock(lock, fcntl.LOCK_EX)
    path = P/'ACTIVE_OWNER.json'; before = path.read_bytes(); owner = json.loads(before)
    assert owner['latest_round']['round'] == 202 and owner['hardware_commit'] == HW
    (A/'ACTIVE_OWNER.before.json').write_bytes(before)
    owner.update(utc=utc, current_stage='placer_timing_optimization', placement_phase=end['placement_phase'], latest_round=latest,
        controller_identity=end['controller'], owner_observation=str(A/'owner-end.json'),
        owner_observation_sha256=sha(A/'owner-end.json'),
        latest_evidence_readiness=ref(A/'evidence-readiness.json'))
    replace(path, owner, before)
with (D/'unattended-opt4/campaign-policy.lock').open('a') as lock:
    fcntl.flock(lock, fcntl.LOCK_EX)
    path = D/'unattended-opt4/campaign-policy.json'; before = path.read_bytes(); policy = json.loads(before)
    (A/'campaign-policy.before.json').write_bytes(before)
    pp = policy['performance_only_priority_20261113']
    pp.update(active_owner=owner, latest_exact_scope=ref(A/'EXACT_SCOPE.md'))
    policy['round203_performance_only_placer_timing_optimization_and_exact_readiness_20261113'] = latest
    replace(path, policy, before)
path = D/'area-sprint-20261112/latest-round.json'; before = path.read_bytes()
assert json.loads(before)['round'] == 202
(A/'latest-round.before.json').write_bytes(before); replace(path, latest, before)
with (P/'CONTINUATION.md').open('a') as f:
    f.write('\nRound203: '+summary+' Receipt '+str(receipt_path)+'. '+next_action+'\n')
path = P/'LATEST.md'; (A/'LATEST.md.before').write_bytes(path.read_bytes())
path.write_text(PROFILE+'\n\n'+summary+'\n\n'+next_action+'\n\nEvidence: '+str(A/'EXACT_SCOPE.md')+'\n')
create(A/'publication.json', dict(schema='ec-performance-only-round203-publication/1',
    utc=utc, round_receipt=ref(receipt_path), ACTIVE_OWNER_sha256=sha(P/'ACTIVE_OWNER.json'),
    campaign_policy_sha256=sha(D/'unattended-opt4/campaign-policy.json'),
    full_EC_ledger_unchanged=True, prototype_ledger_unchanged=True,
    no_FPGA_IO=True, no_service_restart=True, publisher_source=ref(__file__)))
print(json.dumps(latest))
