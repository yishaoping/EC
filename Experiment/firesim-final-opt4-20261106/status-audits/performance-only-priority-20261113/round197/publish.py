#!/usr/bin/python3
"""Publish source-bound observations without controlling any running owner."""
import datetime as dt
import hashlib
import json
import os
from pathlib import Path

D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
A = Path(__file__).resolve().parent
R = D/'build-logs/Opt4-performance-only-support-r6-20261113'
P = D/'performance-only-20261113'


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def write(p, value):
    with Path(p).open('x') as f:
        json.dump(value, f, indent=2)
        f.write('\n')


def replace(p, value, before):
    assert p.read_bytes() == before, ('concurrent report update', str(p))
    tmp = p.with_name(p.name+'.round197.tmp')
    tmp.write_text(json.dumps(value, indent=2)+'\n')
    os.replace(tmp, p)


def main():
    utc = dt.datetime.now(dt.timezone.utc).isoformat()
    start, end = read(A/'owner-start.json'), read(A/'owner-end.json')
    assert not end['capacity_complete_exists'], 'consume actual capacity before publishing this pending report'
    assert end['checker_result'] is None, 'consume actual checker result before publishing this pending report'
    assert not (R/'capacity.complete').exists(), 'new capacity requires adoption before publication'
    assert not (D/'build-logs/Opt4-performance-only-checker-whole-r3-20261113/result.json').exists(), 'new checker result requires adoption before publication'
    prior = read(start['prior_observation'])
    cad = read(R/'cad-state.json')
    prefix = (R/'implementation-attempt-1.log').read_bytes()
    assert b'\nEC_FIT_LINK_ZERO_FUNCTIONAL_BLACKBOX\n' in prefix
    assert b'opt_design completed successfully' in prefix
    (A/'implementation-prefix.log').write_bytes(prefix)
    checks = []
    for path, digest in cad['inputs']['generated'].items():
        actual = sha(path)
        assert actual == digest, path
        checks.append(dict(path=path, sha256=actual, PASS=True))
    write(A/'shell-link-authentication.json', dict(
        schema='ec-performance-only-executed-shell-link-authentication/1', utc=utc,
        hardware_commit=cad['hardware_commit'], source_id=cad['source_id'],
        generated_input_checks=checks, executed_zero_functional_blackbox_link=True,
        opt_design_completed=True, optimized_checkpoint_and_capacity_publication_pending=True,
        implementation_tcl_sha256=sha(R/'implementation-bound.tcl'),
        captured_log_prefix=str(A/'implementation-prefix.log'), captured_prefix_bytes=len(prefix),
        captured_prefix_sha256=sha(A/'implementation-prefix.log'),
        capacity_FIT=None, complete_shell_LUT=None, no_FPGA_IO=True))
    scope = """EC Performance-Only: data preservation + cache isolation; hardware 6fada307.

R6 remains the sole complete-shell CAD owner. The actual link completed with zero unresolved functional blackboxes, and opt_design completed successfully. The optimized checkpoint is being written; capacity.complete and a complete-shell utilization receipt do not exist in the ending observation. The 939,850 LUT / 927,968 FF / 545 BRAM / 112 DSP report is DUT synthesis only. No complete-shell FIT, physical completion, bitstream or runtime certification is established.

R3 is adopted as the existing real whole-host checker validation owner. R1 compiled the exact host successfully; R2 compiled the corrected read-only observer and failed its link-command parser. R3 successfully linked that observer before Vemul__ALL.a, whose default main remains archived. All 644 protected predecessor artifacts match their hashes. R2 observer source/object and oracle are byte unchanged. The host RTL matches the CAD input. No model rebuild or RTL change occurred.

The actual R3 workload is active. No result.json exists, so integrated checker acceptance remains pending. The strict oracle still requires allocation/local BEGIN/full_compare result/actual BOOM accepted sequence equality, all four checkers, no duplicate or missing sequence, no cancellation, no sampling errors, verified Canneal output and clean exit. Partial workload output, generated identity, and boundary-injected module tests do not establish this result. This finite Canneal project400 test is not PARSEC simmedium, FPGA execution, or universal equivalence.

No new job, supervisor, subagent, software build, validation run, CAD restart, hardware edit, FPGA IO, CPU-session control or SVB-session control was performed. The full-EC/PALIMPSEST shell ledger is unchanged. No new structural cut is authorized before this hardware's actual complete-shell postopt result.
"""
    (A/'EXACT_SCOPE.md').write_text(scope)
    summary = ('EC Performance-Only6fada307: actual complete-shell link has zero unresolved functional blackboxes; '
               'opt_design completed and R6 is writing its optimized checkpoint. Adopted existing checker R3 after '
               'successful observer link; verified644 protected artifacts unchanged and exact hostRTL matches CAD. '
               'No complete-shell LUT/FIT or integrated checker PASS yet.')
    next_action = ('Preserve sole R6 and existing checker R3; no duplicate validation, model rebuild, CAD restart, '
                   'or new cuts before actual complete-shell postopt. Consume R3 result with unchanged strict real4checker '
                   'allocation/localBEGIN/full_compare/BOOM-acceptance sequence join. At >=600s CAD cadence consume '
                   'capacity.complete with source-bound utilization/hierarchy. NOTFIT: use new hierarchy for one substantial '
                   'structural optimization preserving real storage/isolation/normal commit/checker/backpressure. FIT: '
                   'finish physical/all-STA/DRC, exact profile physical/ABI/software certificate and existing-lock safe21 '
                   'runtime handoff; require real checker/boot/storage/isolation/drain before eight first simmedium samples. '
                   'Unknown failures need immutable diagnosed recovery after exact predecessor cgroup release.')
    ledger = D/'area-sprint-20261112/fullshell-adoptions.json'
    evidence = [dict(path=str(A/name), sha256=sha(A/name)) for name in [
        'owner-start.json', 'owner-end.json', 'checker-r3-authentication.json',
        'checker-owner-adoption.json', 'shell-link-authentication.json', 'EXACT_SCOPE.md']]
    observation = start['observation_seconds']+end['observation_seconds']
    receipt_path = D/'area-sprint-20261112/round-00197.json'
    receipt = dict(schema='ec-area-sprint-round-evidence/1', round=197, utc=utc,
        outcome='WAITING_ACTIVE_JOB', summary=summary, next_action=next_action, retry_after_seconds=600,
        profile='EC Performance-Only: data preservation + cache isolation',
        hardware_commit=cad['hardware_commit'], source_id=cad['source_id'],
        functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
        experiment_commits=['cef2d0bd09ec1480db0f29034c2b0a29a28b949f',
                            '570803d340a33fd50639466982ed75dbe8fef32a'],
        hardware_unchanged=True, full_PALIMPSEST=False, prototype_FIT=None, prototype_area_LUT=None,
        runtime_certified=False, actual_checker_execution_tested=False, integrated_validation_started=True,
        launched_jobs=[], adopted_not_launched_jobs=[
            'ec-performance-only-support-r6-20261113.service',
            'ec-performance-only-checker-whole-r3-20261113.service'],
        real_progress=dict(stage='implementation', executed_zero_functional_blackbox_link=True,
            opt_design_completed=True, checkpoint_writing=True, whole_CAD_observation_seconds=observation,
            CAD_log_growth_bytes=end['log']['bytes']-prior['log']['bytes'],
            checker_log_growth_bytes=end['checker_log']['bytes']-start['checker_log']['bytes'],
            checker_status=end['checker_state']['status'], checker_result_published=False),
        evidence=evidence, no_CPU_or_SVB_session_control=True, no_FPGA_IO=True,
        no_driver_rebuild=True, no_healthy_restart=True, no_new_cuts_before_actual_complete_shell_postopt=True,
        no_new_intelligent_supervisor=True, no_subagents=True, no_validation_rerun=True,
        fullshell_ledger=dict(path=str(ledger), sha256=sha(ledger), prototype_not_added=True))
    write(receipt_path, receipt)
    latest = dict(round=197, utc=utc, summary=summary, next_action=next_action,
                  outcome='WAITING_ACTIVE_JOB', receipt=str(receipt_path), receipt_sha256=sha(receipt_path))
    owner_path = P/'ACTIVE_OWNER.json'
    owner_before = owner_path.read_bytes()
    (A/'ACTIVE_OWNER.before.json').write_bytes(owner_before)
    owner = json.loads(owner_before)
    adoption = dict(owner=end['checker_owner'], adoption=str(A/'checker-owner-adoption.json'),
                    adoption_sha256=sha(A/'checker-owner-adoption.json'),
                    current_status=end['checker_state']['status'], integrated_validation_started=True,
                    actual_integrated_checker_execution_passed=False)
    owner.update(utc=utc, latest_round=latest, next_action=next_action,
                 controller_identity=end['controller'], current_stage=end['stage'],
                 owner_observation=str(A/'owner-end.json'), owner_observation_sha256=sha(A/'owner-end.json'),
                 foreground_checker_whole_link_validation=adoption,
                 shell_link=dict(authentication=str(A/'shell-link-authentication.json'),
                                 authentication_sha256=sha(A/'shell-link-authentication.json'),
                                 zero_unresolved_functional_blackboxes=True, opt_design_completed=True,
                                 complete_shell_postopt_capacity_pending=True))
    replace(owner_path, owner, owner_before)
    policy_path = D/'unattended-opt4/campaign-policy.json'
    policy_before = policy_path.read_bytes()
    (A/'campaign-policy.before.json').write_bytes(policy_before)
    policy = json.loads(policy_before)
    pp = policy['performance_only_priority_20261113']
    pp.update(active_owner=owner, foreground_checker_whole_link_validation={
        **end['checker_owner'], 'status':end['checker_state']['status'],
        'adoption':str(A/'checker-owner-adoption.json'), 'adoption_sha256':sha(A/'checker-owner-adoption.json'),
        'real_integrated_checker_execution_passed':False})
    policy['round197_performance_only_shell_link_and_checker_r3_adoption_20261113'] = latest
    replace(policy_path, policy, policy_before)
    pointer = D/'area-sprint-20261112/latest-round.json'
    pointer_before = pointer.read_bytes()
    assert json.loads(pointer_before).get('round', 0) < 197
    (A/'latest-round.before.json').write_bytes(pointer_before)
    replace(pointer, latest, pointer_before)
    continuation = P/'CONTINUATION.md'
    with continuation.open('a') as f:
        f.write('\nRound197: '+summary+' Receipt '+str(receipt_path)+'. '+next_action+'\n')
    write(A/'publication.json', dict(schema='ec-performance-only-round197-publication/1', utc=utc,
        round_receipt=str(receipt_path), round_receipt_sha256=sha(receipt_path),
        ACTIVE_OWNER_sha256=sha(owner_path), campaign_policy_sha256=sha(policy_path),
        existing_collector_pointer_updated=True, existing_collector_code_unchanged=True,
        no_service_restart=True, no_FPGA_IO=True))
    print(json.dumps(latest))


if __name__ == '__main__':
    main()
