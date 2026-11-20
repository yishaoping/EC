#!/usr/bin/python3
"""Publish source-bound round evidence; no job, lock-owner, or device control."""
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


def replace(p, row, before):
    assert p.read_bytes() == before, ('concurrent update', str(p))
    temp = p.with_name(p.name+'.round204.tmp')
    with temp.open('x') as f:
        json.dump(row, f, indent=2)
        f.write('\n')
    os.replace(temp, p)


evidence = read(A/'evidence-readiness.json')
start, end = read(A/'owner-start.json'), read(A/'owner-end.json')
placed = read(A/'followthrough-audit.json')
assert evidence['authenticated_files'] == 922 and evidence['protected_checker_artifacts'] == 644
assert start['observation_seconds'] >= 600
assert end['controller']['pid'] == start['controller']['pid'] == 355419
assert end['controller']['start_ticks'] == start['controller']['start_ticks'] == '35248517'
assert end['status'] == 'RUNNING_IMPLEMENTATION'
assert placed['place_design_completed_successfully'] and placed['resources']['CLB LUTs'] == 1015701
assert placed['placement_errors'] == placed['placement_critical_warnings'] == 0
assert not (S/'timing_bitstream-result.json').exists() and not (S/'postopt-result.json').exists()
assert sha(D/'area-sprint-20261112/fullshell-adoptions.json') == evidence['full_EC_ledger']['sha256']
assert sha(P/'fullshell-adoptions.json') == evidence['prototype_ledger']['sha256']
utc = dt.datetime.now(dt.timezone.utc).isoformat()
cpu = sum(r['cpu_seconds'] for row in [start, end] for r in row['process_cpu_deltas'])
growth = start['log_growth_bytes'] + end['log_growth_bytes']
observed = start['observation_seconds'] + end['observation_seconds']
summary = (
    'EC Performance-Only6fada307: same R6 completed place_design with zero errors and saved its authenticated '
    'whole-shell placed checkpoint:1015701LUT,287979headroom. '
    f'{observed:.0f}s since prior durable observation,+{growth}log bytes,+{cpu:.1f}process CPU-seconds. '
    'Intermediate estimated WNS=-3.154ns and high-congestion warning; final physical closure pending. '
    'Authenticated922 pinned artifacts,including644 protected checker artifacts; actual whole-checker '
    'PASS131/131/131 and complete-shell postopt capacity FIT1023687/1303680LUT remain valid. '
    'No bitstream/certificate/card21 runtime result yet.')
old_owner = read(P/'ACTIVE_OWNER.json')
next_action = old_owner['next_action']
scope = (
    PROFILE+'\n\n'+summary+'\n\n'
    'The actual placed checkpoint is independently hash-bound with a captured Vivado implementation log '
    'and its utilization report. Whole-shell placed resources:1015701LUT,1019298FF,15706CARRY8,115DSP,678.5BRAM,0URAM. '
    'The original postopt capacity result remains1023687LUT/279993headroom. These are distinct implementation stages. '
    'The placement result is not final routed timing or runtime certification. The -3.154ns WNS is the placer\'s '
    'post-replication estimate. High congestion is a direct tool warning; route failure or final closure is unproven. '
    'The same immutable R6 implementation continues through phys_opt_design -directive Explore and route_design -directive Explore. '
    'No constraint change or new physical strategy was introduced.\n\n'
    'Authenticated existing Canneal project400 whole MCRams-host evidence:1759001targetedges,131allocations, '
    '131real full_compare,131BOOMacceptances,all4checkers33/33/33/32,pending0,edgeerrors0,checksumPASS,applicationexit0. '
    'No simulation, observer link, strict analysis, model/RTL generation, driver build or CAD was duplicated. '
    'The preserved original R3 transport-postparser failure remains evidence; its actual run was successful. '
    'This finite CPU model result is not FPGA validation,simmedium,Slowdown or universal equivalence.\n\n'
    'Same exact R6 PID355419/start35248517/bootd6c6e410-10ad-4326-86ba-79b657eabd96 remains active in its service cgroup. '
    'The prepared final-checkpoint report-only checks and exact certificate binder correctly remain gated on physical completion '
    'and exact cgroup release. Required checks:setup,hold,pulse,skew,clock coverage,IO/internal unconstrained endpoints,route coverage,DRC. '
    'The existing root runtime owner is waiting without children and retains opt4-fit-runtime.lock. No handoff or device operation occurred. '
    'Recheck all exact physical/ABI/software gates and all card21 locks at the actual safe-boundary handoff. '
    'Integrated FPGA checker,LSL/SVB preservation,cache isolation and safe drain remain required before eight first simmedium samples. '
    'Unsupported diagnostic pending counters cannot establish drain. Full-EC/PALIMPSEST and prototype ledgers are unchanged.\n\n'
    'Next: '+next_action+'\n')
with (A/'EXACT_SCOPE.md').open('x') as f:
    f.write(scope)
refs = [ref(A/n) for n in ['observe.py','owner-start.json','owner-end.json','evidence-readiness.json','followthrough-audit.json','EXACT_SCOPE.md']]
receipt = dict(schema='ec-area-sprint-round-evidence/1', round=204, utc=utc,
    outcome='WAITING_ACTIVE_JOB', summary=summary, next_action=next_action, retry_after_seconds=600,
    hardware_commit=HW, source_id=SID, functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
    profile=PROFILE, full_PALIMPSEST=False, hardware_unchanged=True,
    experiment_commit='cef2d0bd09ec1480db0f29034c2b0a29a28b949f',
    checker_analysis_commit='02436d48a8dbc3a16f92c9f689f8fb391e89d5c5',
    source_binding=old_owner['source_binding'], source_binding_sha256=old_owner['source_binding_sha256'],
    prototype_FIT=True, capacity_FIT=True, prototype_area_LUT=1023687, LUT_headroom=279993,
    actual_placed_checkpoint=ref(A/'followthrough-audit.json'), placed_resources=placed['resources'],
    placed_LUT_headroom=287979, intermediate_estimated_WNS_ns=-3.154, high_congestion_warning=True,
    physical_timing_passed=False, bitstream_exists=False, runtime_certified=False,
    actual_integrated_checker_execution_passed=True, actual_checker_counts=evidence['actual_checker_counts'],
    checker_scope=read(P/'checker-whole-link-validation-r1.json')['scope'],
    real_progress=dict(stage='placement_completed_placed_reports',
        authenticated_artifacts=922, protected_checker_artifacts=644,
        whole_CAD_observation_seconds=observed, CAD_log_growth_bytes=growth, process_CPU_seconds=cpu),
    launched_jobs=[], adopted_not_launched_jobs=['ec-performance-only-support-r6-20261113.service'],
    evidence=refs, physical_readiness=evidence['physical_readiness'],
    existing_runtime_lock_preserved=True, handoff_performed=False,
    no_FPGA_IO=True, no_CPU_or_SVB_session_control=True, no_healthy_restart=True,
    no_new_cuts=True, no_new_service_or_waiter=True, no_new_intelligent_supervisor=True,
    no_subagents=True, no_driver_rebuild=True, no_simulation_or_checker_analysis_repeated=True,
    fullshell_ledger=evidence['full_EC_ledger'], prototype_ledger=evidence['prototype_ledger'],
    postflight_entry=old_owner['final_checkpoint_checks']['entry'],
    certificate_entry=old_owner['exact_certificate_binding']['entry'])
receipt_path = D/'area-sprint-20261112/round-00204.json'
create(receipt_path, receipt)
latest = dict(round=204, utc=utc, summary=summary, next_action=next_action,
    outcome='WAITING_ACTIVE_JOB', receipt=str(receipt_path), receipt_sha256=sha(receipt_path))
with (P/'ACTIVE_OWNER.json.lock').open('a') as lock:
    fcntl.flock(lock, fcntl.LOCK_EX)
    path = P/'ACTIVE_OWNER.json'; before = path.read_bytes(); owner = json.loads(before)
    assert owner['latest_round']['round'] == 203 and owner['hardware_commit'] == HW
    (A/'ACTIVE_OWNER.before.json').write_bytes(before)
    owner.update(utc=utc, current_stage='placement_completed_placed_reports',
        placement_phase='place_design completed successfully; placed checkpoint saved', latest_round=latest,
        controller_identity=end['controller'], owner_observation=str(A/'owner-end.json'),
        owner_observation_sha256=sha(A/'owner-end.json'), latest_evidence_readiness=ref(A/'evidence-readiness.json'),
        actual_placed_checkpoint=ref(A/'followthrough-audit.json'), placed_resources=placed['resources'],
        placed_LUT_headroom=287979, intermediate_estimated_WNS_ns=-3.154, high_congestion_warning=True)
    replace(path, owner, before)
with (D/'unattended-opt4/campaign-policy.lock').open('a') as lock:
    fcntl.flock(lock, fcntl.LOCK_EX)
    path = D/'unattended-opt4/campaign-policy.json'; before = path.read_bytes(); policy = json.loads(before)
    (A/'campaign-policy.before.json').write_bytes(before)
    policy['performance_only_priority_20261113'].update(active_owner=owner, latest_exact_scope=ref(A/'EXACT_SCOPE.md'))
    policy['round204_performance_only_placement_completed_and_exact_readiness_20261113'] = latest
    replace(path, policy, before)
path = D/'area-sprint-20261112/latest-round.json'; before = path.read_bytes()
assert json.loads(before)['round'] == 203
(A/'latest-round.before.json').write_bytes(before); replace(path, latest, before)
with (P/'CONTINUATION.md').open('a') as f:
    f.write('\nRound204: '+summary+' Receipt '+str(receipt_path)+'. '+next_action+'\n')
path = P/'LATEST.md'; (A/'LATEST.md.before').write_bytes(path.read_bytes())
path.write_text(PROFILE+'\n\n'+summary+'\n\n'+next_action+'\n\nEvidence: '+str(A/'EXACT_SCOPE.md')+'\n')
create(A/'publication.json', dict(schema='ec-performance-only-round204-publication/1', utc=utc,
    round_receipt=ref(receipt_path), ACTIVE_OWNER_sha256=sha(P/'ACTIVE_OWNER.json'),
    campaign_policy_sha256=sha(D/'unattended-opt4/campaign-policy.json'),
    full_EC_ledger_unchanged=True, prototype_ledger_unchanged=True,
    no_FPGA_IO=True, no_service_restart=True, publisher_source=ref(__file__)))
print(json.dumps(latest))
