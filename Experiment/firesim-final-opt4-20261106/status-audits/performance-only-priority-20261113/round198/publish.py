#!/usr/bin/python3
"""Publish authenticated prototype capacity/checker results; never control owners."""
from pathlib import Path
import datetime as dt
import fcntl
import hashlib
import json
import os

D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
A=Path(__file__).resolve().parent
P=D/'performance-only-20261113'
S=D/'build-logs/Opt4-performance-only-support-r6-20261113'
HW='6fada307bb77be90b39720d3f95404fece0e431b'
SID='461e1b98833d1a78a8bd27c0eed2d3353c648dfbf29ae5588db31bbce0f77369'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
PROFILE='EC Performance-Only: data preservation + cache isolation'

def read(p):return json.loads(Path(p).read_text())
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for block in iter(lambda:f.read(2**20),b''):h.update(block)
 return h.hexdigest()
def write(p,row):
 with Path(p).open('x') as f:json.dump(row,f,indent=2);f.write('\n')
def replace(p,row,old):
 assert p.read_bytes()==old,('concurrent evidence update',str(p))
 tmp=p.with_name(p.name+'.round198.tmp');tmp.write_text(json.dumps(row,indent=2)+'\n');os.replace(tmp,p)
def ref(p):return dict(path=str(p),sha256=sha(p))

utc=dt.datetime.now(dt.timezone.utc).isoformat()
cap=read(A/'capacity-adoption.json');check=read(A/'checker-finished-analysis-adoption.json')
start=read(A/'owner-start.json');end=read(A/'owner-end.json')
assert cap['capacity_FIT'] and check['actual_integrated_checker_execution_passed']
assert cap['actual_LUT']==1023687 and cap['LUT_headroom']==279993
assert cap['hardware_commit']==check['hardware_commit']==HW
assert not (S/'timing_bitstream-result.json').exists(), 'consume new physical stage before pending publication'
assert sha(D/'area-sprint-20261112/fullshell-adoptions.json')=='4f2f686829b0b34546f0fbb37367f7a69c3b82f69e95e8bbce29465df4c9a2b3'
post=W/'Opt4-performance-only-physical-postflight-r1-20261113/candidates/performance-only-physical-postflight-r1-20261113/postflight.py'
cert=W/'Opt4-performance-only-certificate-analysis-bind-r1-20261113/candidates/performance-only-certificate-analysis-bind-r1-20261113/certify.py'
summary=('EC Performance-Only6fada307: adopted actual complete-shell postopt capacity FIT1023687/1303680LUT,279993headroom; '
 'same R6 implementation is in placement. Authenticated existing foreground whole-checker analysis PASS131allocations/131full_compare/131BOOMaccepted across4checkers,pending0. '
 'Staged final-checkpoint all-STA and exact certificate binders; physical closure/bitstream/runtime certification remain pending.')
next_action=('Preserve the same R6 through place/route/setup-hold/bitstream; no cuts, restart, duplicate CAD, checker run or driver rebuild. '
 'After actual physical output and exact R6 cgroup release, allocate two idle campaign CPUs and run '+str(post)+' --run --cpus CPU0 CPU1 for report-only all-STA/pulse/skew/clock/IO/internal-unconstrained/route/DRC checks under the existing CAD lease. '
 'Then run '+str(cert)+' --write to bind the existing foreground strict checker analysis and exact physical/ABI/software evidence. '
 'Only then hand off the existing runtime owner at a safe boundary without bypassing any21lock. Require integrated card21 boot/checker/LSL-SVB/isolation/drain before the requested eight first simmedium samples. '
 'Unknown failures require immutable diagnosed corrections after exact predecessor release; do not repeat completed validation.')
result=dict(schema='ec-performance-only-complete-shell-capacity-result/1',utc=utc,hardware_commit=HW,source_id=SID,
 functional_baseline=BASE,profile=PROFILE,full_PALIMPSEST=False,scope='complete_u280_shell_postopt',shell_included=True,blackboxes=0,
 status='CAPACITY_FITS_POSTOPT_TIMING_PENDING',capacity_FIT=True,physical_timing_passed=False,runtime_certified=False,
 resources=cap['resources'],LUT_headroom=279993,capacity_authentication=ref(A/'capacity-adoption.json'),
 utilization=str(S/'top-postopt-utilization.rpt'),utilization_sha256=sha(S/'top-postopt-utilization.rpt'),
 source_binding=cap['source_binding'],source_binding_sha256=cap['source_binding_sha256'],FPGA_IO=False)
write(A/'complete-shell-result.json',result)
ledger=P/'fullshell-adoptions.json'
assert not ledger.exists(),'adopt existing prototype ledger before adding'
write(ledger,dict(schema='ec-performance-only-fullshell-adoptions/1',profile=PROFILE,full_PALIMPSEST=False,
 results=[dict(scope='complete_u280_shell_postopt',result=str(A/'complete-shell-result.json'),result_sha256=sha(A/'complete-shell-result.json'),
 utilization=result['utilization'],utilization_sha256=result['utilization_sha256'],source_binding=result['source_binding'],
 source_binding_sha256=result['source_binding_sha256'],hardware_commit=HW,capacity_FIT=True,physical_timing_pending=True)]))
scope=('EC Performance-Only: data preservation + cache isolation. Hardware6fada307 remains unchanged. Not full PALIMPSEST.\n\n'
 'The actual complete U280 shell postopt uses1023687LUT/1303680,1019173FF,15706CARRY8,115DSP,678.5BRAM,0URAM. '
 'Capacity fits with279993LUT headroom. The executed shell link has zero functional blackboxes;168 source/input hashes were authenticated. '
 'The same R6 PID355419/start35248517/bootd6c6e410-10ad-4326-86ba-79b657eabd96 still owns placement. This establishes capacity only; final setup/hold/pulse/skew/clock/unconstrained/DRC closure and bitstream remain pending.\n\n'
 'The foreground completed the original R3 workload with returncode0, then its controller rejected missing checker records in ROI-only PrintBridge output. '
 'That original failure is preserved. Existing foreground analysis02436d48 joined native generated RocketCore $fwrite BEGIN/RESULT records from the SAME authenticated simulator log to actual BOOM-edge allocation/acceptance. '
 'Adopted strict finite complete-host checker PASS:131allocations,131full_compare results,131BOOM accepted;per-checker33/33/33/32;pending0;sample_errors0;expected Canneal checksum verified. '
 'All644 protected predecessor artifacts remain unchanged. Native local prints have no timestamps, so no local latency is claimed. This is actual complete CPU MCRams-host Canneal project400 finite correctness, not Linux simmedium, FPGA execution, Slowdown data or universal equivalence. No simulation or checker analysis was repeated here.\n\n'
 'New immutable support commitsdb4458c and9869d9c stage the report-only final-checkpoint checks and exact certificate binder.39 isolated STA/identity/checker-admission fixtures and8 certificate-schema rejection checks pass;these are tool validation only, not physical evidence. '
 'Readiness refuses actual STA/certification before physical completion and exact R6 cgroup release. No service or waiter was installed. '
 'The physical clock contract preserves both divide_by1 generated clocks and tile_1 multicycle2/1;no timing constraints are modified.\n\n'
 'The existing root runtime owner still holds opt4-fit-runtime.lock while waiting without a child. No lock, service or card21 operation occurred. '
 'Exact new physical/ABI/software certification and existing-owner safe handoff still precede FPGA IO;integrated FPGA checker/storage/isolation/drain still precede simmedium. '
 'No prototype result was added to the full-EC/PALIMPSEST ledger;the new capacity record is in this profile only.\n')
(A/'EXACT_SCOPE.md').write_text(scope)
entries=[ref(A/n) for n in ['owner-start.json','owner-end.json','capacity-adoption.json','complete-shell-result.json',
 'checker-finished-analysis-adoption.json','postflight-source-binding.json','postflight-fixtures.json','postflight-readiness.json',
 'certificate-analysis-source-binding.json','certificate-analysis-fixtures.json','certificate-analysis-readiness.json','runtime-lock-handoff-status.json','EXACT_SCOPE.md']]
receipt=dict(schema='ec-area-sprint-round-evidence/1',round=198,utc=utc,outcome='WAITING_ACTIVE_JOB',summary=summary,next_action=next_action,retry_after_seconds=600,
 hardware_commit=HW,source_id=SID,functional_baseline=BASE,profile=PROFILE,full_PALIMPSEST=False,hardware_unchanged=True,
 prototype_FIT=True,capacity_FIT=True,prototype_area_LUT=1023687,LUT_headroom=279993,physical_timing_passed=False,bitstream_exists=False,runtime_certified=False,
 actual_checker_execution_tested=True,actual_integrated_checker_execution_passed=True,checker_scope=check['scope'],
 actual_checker_counts=dict(allocations=131,real_full_compare_results=131,BOOM_accepted=131,per_checker=check['per_checker'],pending=0,sample_errors=0),
 experiment_commits=['cef2d0bd09ec1480db0f29034c2b0a29a28b949f','02436d48a8dbc3a16f92c9f689f8fb391e89d5c5','db4458c7082de9c6a3cdb5ac474118d5a3b7e730','9869d9c7b7da92552191b8ec493a5a0f93e565f4'],
 launched_jobs=[],adopted_not_launched_jobs=['ec-performance-only-support-r6-20261113.service'],
 real_progress=dict(stage='placement',source_input_hashes_authenticated=168,protected_checker_artifacts_authenticated=644,
 whole_CAD_observation_seconds=start['observation_seconds']+end['observation_seconds'],
 CAD_log_growth_bytes=end['log']['bytes']-start['log']['bytes'],strict_completed_checker_analysis_adopted=True,
 final_STA_fixture_checks=39,certificate_schema_negative_checks=8),evidence=entries,
 no_CPU_or_SVB_session_control=True,no_FPGA_IO=True,no_driver_rebuild=True,no_healthy_restart=True,no_new_cuts=True,
 no_new_intelligent_supervisor=True,no_subagents=True,no_simulation_or_checker_analysis_repeated=True,no_new_service_or_waiter=True,
 existing_runtime_lock_preserved=True,fullshell_ledger=dict(path=str(D/'area-sprint-20261112/fullshell-adoptions.json'),sha256=sha(D/'area-sprint-20261112/fullshell-adoptions.json'),prototype_not_added=True),
 prototype_ledger=ref(ledger),postflight_entry=str(post),certificate_entry=str(cert))
receipt_path=D/'area-sprint-20261112/round-00198.json';write(receipt_path,receipt)
latest=dict(round=198,utc=utc,summary=summary,next_action=next_action,outcome='WAITING_ACTIVE_JOB',receipt=str(receipt_path),receipt_sha256=sha(receipt_path))
with (P/'ACTIVE_OWNER.json.lock').open('a') as lock:
 fcntl.flock(lock,fcntl.LOCK_EX)
 path=P/'ACTIVE_OWNER.json';before=path.read_bytes();(A/'ACTIVE_OWNER.before.json').write_bytes(before);owner=json.loads(before)
 owner.update(utc=utc,status='CAPACITY_FIT_PHYSICAL_IMPLEMENTATION_RUNNING',FIT=True,capacity_FIT=True,actual_whole_shell_LUT=1023687,LUT_headroom=279993,
  physical_timing_passed=False,runtime_certified=False,actual_checker_execution_tested=True,actual_integrated_checker_execution_passed=True,
  actual_complete_shell_postopt=ref(A/'complete-shell-result.json'),actual_complete_checker_link_validation=ref(A/'checker-finished-analysis-adoption.json'),
  current_stage='placement',controller_identity=end['controller'],latest_round=latest,next_action=next_action,
  owner_observation=str(A/'owner-end.json'),owner_observation_sha256=sha(A/'owner-end.json'),
  preserve_same_healthy_implementation_through_route=True,no_new_cuts=True,
  final_checkpoint_checks=dict(entry=str(post),source_binding=ref(A/'postflight-source-binding.json'),readiness=ref(A/'postflight-readiness.json'),service_installed=False),
  exact_certificate_binding=dict(entry=str(cert),source_binding=ref(A/'certificate-analysis-source-binding.json'),readiness=ref(A/'certificate-analysis-readiness.json'),requires_actual_physical=True),
  foreground_checker_whole_link_validation=dict(current_status='PASS_REAL_COMPLETE_HOST_CHECKER_LINK',adoption=ref(A/'checker-finished-analysis-adoption.json'),actual_integrated_checker_execution_passed=True,original_R3_failure_preserved=True),
  shell_link=dict(zero_unresolved_functional_blackboxes=True,opt_design_completed=True,complete_shell_postopt_capacity_pending=False,capacity=ref(A/'capacity-adoption.json')))
 replace(path,owner,before)
with (D/'unattended-opt4/campaign-policy.lock').open('a') as lock:
 fcntl.flock(lock,fcntl.LOCK_EX)
 path=D/'unattended-opt4/campaign-policy.json';before=path.read_bytes();(A/'campaign-policy.before.json').write_bytes(before);policy=json.loads(before)
 pp=policy['performance_only_priority_20261113'];pp.update(active_owner=owner,latest_exact_scope=ref(A/'EXACT_SCOPE.md'),
  actual_complete_shell_postopt=dict(LUT=1023687,LUT_headroom=279993,capacity_FIT=True,resource_capacity=1303680,evidence=str(A/'complete-shell-result.json'),evidence_sha256=sha(A/'complete-shell-result.json')),
  preserve_same_healthy_implementation_through_route=True,no_new_cuts=True,final_checkpoint_checks=owner['final_checkpoint_checks'],exact_certificate_binding=owner['exact_certificate_binding'])
 policy['round198_performance_only_capacity_fit_and_completed_checker_adoption_20261113']=latest
 replace(path,policy,before)
path=D/'area-sprint-20261112/latest-round.json';before=path.read_bytes();assert json.loads(before)['round']<198;(A/'latest-round.before.json').write_bytes(before);replace(path,latest,before)
with (P/'CONTINUATION.md').open('a') as f:f.write('\nRound198: '+summary+' Receipt '+str(receipt_path)+'. '+next_action+'\n')
latest_md=P/'LATEST.md';(A/'LATEST.md.before').write_bytes(latest_md.read_bytes());latest_md.write_text(PROFILE+'\n\n'+summary+'\n\n'+next_action+'\n\nEvidence: '+str(A/'EXACT_SCOPE.md')+'\n')
write(A/'publication.json',dict(schema='ec-performance-only-round198-publication/1',utc=utc,round_receipt=ref(receipt_path),ACTIVE_OWNER_sha256=sha(P/'ACTIVE_OWNER.json'),campaign_policy_sha256=sha(D/'unattended-opt4/campaign-policy.json'),prototype_ledger=ref(ledger),full_PALIMPSEST_ledger_unchanged=True,no_FPGA_IO=True,no_service_restart=True))
print(json.dumps(latest))
