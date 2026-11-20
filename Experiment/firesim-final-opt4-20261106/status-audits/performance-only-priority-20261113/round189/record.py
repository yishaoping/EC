#!/usr/bin/python3
"""One-shot evidence publication. Never starts, restarts, or modifies an owner."""
from pathlib import Path
import datetime as dt
import hashlib
import json
import os
import sys

D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
O = Path(__file__).resolve().parent
PREV = D/'status-audits/full-ec-structural-priority-20261112/round188-existing-owner-consumption/owner-observation.json'
HANDOFF = D/'performance-only-20261113/HANDOFF.json'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
PROFILE = 'EC Performance-Only: data preservation + cache isolation'
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, now, read, save, sha


def ref(path):
    return dict(path=str(path), sha256=sha(path))


def group_members(unit):
    group = '/user.slice/user-1008.slice/user@1008.service/'+unit
    path = Path('/sys/fs/cgroup/systemd'+group)/'cgroup.procs'
    rows = [identity(int(p)) for p in path.read_text().split()] if path.exists() else []
    return [r for r in rows if r and r['process_state'] not in ['Z', 'X']]


def main():
    assert dt.datetime.now(dt.timezone.utc) >= dt.datetime(2026, 11, 13, 2, 55, 5, tzinfo=dt.timezone.utc), 'Respect module observation interval'
    assert not (O/'owner-observation.json').exists(), 'Keep original observation immutable'
    assert not HANDOFF.exists(), 'Handoff is now available: inspect and adopt its exact owner before publishing'
    previous = read(PREV)
    owners, progress, bindings, attention = {}, {}, {}, []
    for name, old in previous['owners'].items():
        out = D/'build-logs'/('Opt4-'+name+'-20261113')
        statepath = out/('state.json' if (out/'state.json').exists() else 'queue.json')
        raw = statepath.read_bytes()
        state = json.loads(raw)
        snapshot = O/(name+'-state.json')
        snapshot.write_bytes(raw)
        rows = group_members('ec-opt4-'+name+'-20261113.service')
        controller = identity(state['pid']) if state.get('pid') else {}
        same = bool(controller and controller['start_ticks'] == state.get('start_ticks')
                    and state.get('host_boot_id') == BOOT
                    and controller['pid'] in {r['pid'] for r in rows})
        result_exists = (out/'result.json').exists()
        if not same and not state['status'].startswith('FAILED'):
            attention.append(dict(owner=name, reason='Controller ended or ownership changed; inspect exact receipt and cgroup before action'))
        if state['status'] != old['status'] or result_exists != old['completed_result']:
            attention.append(dict(owner=name, previous_status=old['status'], status=state['status'], result_exists=result_exists))
        owners[name] = dict(state=str(statepath), state_snapshot=str(snapshot),
            state_sha256=hashlib.sha256(raw).hexdigest(), status=state['status'],
            active_stage=state.get('active_stage'), updated_utc=state.get('updated_utc'),
            controller=controller, identity_matches=same, cgroup_members=rows,
            completed_result=result_exists)
        old_progress = previous.get('compute_progress_since_round187', {}).get(name)
        if old_progress:
            old_compute = old_progress['compute_identity']
            current = next((r for r in rows if r['pid'] == old_compute['pid']
                            and r['start_ticks'] == old_compute['start_ticks']), None)
            if current:
                progress[name] = dict(compute_identity=current,
                    previous_observation_utc=old_progress['observed_utc'], observed_utc=now(),
                    cpu_seconds_advanced=(current['cpu_ticks']-old_compute['cpu_ticks'])/os.sysconf('SC_CLK_TCK'),
                    is_feasibility_evidence=False)
        candidate = W/'candidates'/(name+'-20261113')
        bindingpath = candidate/'source-binding.json'
        binding = read(bindingpath)
        assert sha(bindingpath) == previous['source_bindings'][name]['source_binding_sha256']
        controllerpath = candidate/'controller.py'
        assert sha(controllerpath) == binding['files'][str(controllerpath)]
        bindings[name] = dict(source_binding=ref(bindingpath), controller=ref(controllerpath),
            unchanged_from_round188=True)
    observation = dict(schema='ec-preserved-owner-observation/1', utc=now(),
        previous_observation=ref(PREV), owners=owners, source_bindings=bindings,
        compute_progress_since_round188=progress, attention=attention,
        no_job_actions=True, no_hardware_source_change=True)
    save(O/'owner-observation.json', observation)
    if attention:
        print(json.dumps(dict(attention=attention, evidence=str(O/'owner-observation.json'))))
        return 2

    policy = D/'unattended-opt4/campaign-policy.json'
    raw = policy.read_bytes()
    priority = json.loads(raw)['performance_only_priority_20261113']
    assert priority['authorized'] and priority['foreground_preparation_owner']
    assert priority['profile'] == PROFILE and Path(priority['handoff']) == HANDOFF
    assert priority['board_allowlist'] == ['0000:21:00.0'] and priority['not_full_PALIMPSEST']
    (O/'campaign-policy.snapshot.json').write_bytes(raw)
    authority = dict(schema='ec-performance-only-priority-adoption/1', utc=now(),
        profile=PROFILE, full_PALIMPSEST=False, functional_baseline_preserved=BASE,
        policy_snapshot=ref(O/'campaign-policy.snapshot.json'), policy_priority=priority,
        handoff=str(HANDOFF), handoff_exists=False, deterministic_owner_adopted=False,
        preparation_owner='Existing foreground; do not duplicate branch/controller preparation',
        source_branch='ec-performance-only-fpga-r1-20261113',
        authorized_pruning=['EC fault rollback/replay/restore/injection only',
                            'Diagnostic-only AddressStats/bucketSequenceMemory/Barrier logic'],
        required=['Real LSL and SVB storage', 'Cache Versioning and isolation',
                  'Genuine checker completion', 'Safe normal commit and release',
                  'All functional stalls and backpressure', 'Ordinary cache miss replay and CPU recovery',
                  'Full cache geometry', 'Omitted diagnostic metrics explicitly unsupported/invalid'],
        new_image_gates=['New hardware identity', 'Actual complete-shell post-opt receipt',
                        'Physical timing/DRC/bitstream', 'Exact ABI/software certification',
                        'Existing card21 locks and serial binding'],
        no_new_service=True, no_new_supervisor_or_subagents=True, no_FPGA_IO=True)
    save(O/'priority-adoption.json', authority)

    area = D/'build-logs/Opt4-address-banked-production-area-pair-r5-20261113'
    paired = read(area/'paired-progress.json')
    plain = read(area/'map-Plain-receipt.json')
    assert plain['accepted'] and plain['returncode'] == 0 and not plain['missing_outputs']
    for p, digest in plain['outputs'].items():
        if p.endswith('.rpt'):
            assert sha(p) == digest
    adoption = read(D/'area-sprint-20261112/fullshell-adoptions.json')['results'][-1]
    assert adoption['scope'] == 'complete_u280_shell_postopt'
    for k in ['result', 'utilization', 'source_binding']:
        assert sha(adoption[k]) == adoption[k+'_sha256']
    shell = read(adoption['result'])
    assert shell['functional_baseline'] == BASE and shell['shell_included'] and shell['blackboxes'] == 0
    assert shell['hardware_commit'] == adoption['hardware_commit']
    lut = shell['resources']['CLB LUTs']
    measured = dict(schema='ec-separate-scope-measured-evidence/1', utc=now(),
        full_design_reference=dict(adoption=adoption, LUT=lut, capacity=1303680,
            gap=lut-1303680, full_system_fit=False, performance_only_result=False),
        production_area=dict(Plain_LUT=paired['area']['Plain']['resources']['CLB LUTs'],
            Plain_receipt=ref(area/'map-Plain-receipt.json'),
            Threaded_receipt_exists=(area/'map-Threaded-receipt.json').exists(),
            complete_pair_exists=(area/'result.json').exists(), gain_unknown=True),
        performance_only=dict(handoff_pending=True, complete_shell_result=None,
            fit_established=False, certified_bitstream=False), no_additive_whole_saving=True)
    save(O/'measured-evidence.json', measured)

    next_action = ('Prioritize foreground performance-only HANDOFF.json; when published, authenticate its immutable hardware/source/controller binding, PID/start_ticks/boot_id/cgroup and adopt its sole deterministic owner. '
        'Diagnose failures with versioned corrections only after exact predecessor cgroup release. Require actual complete-shell post-opt before any FIT claim; NOT FIT uses that hierarchy for substantial cuts, FIT continues physical/timing/DRC/bitstream/new identity and ABI/software certification before card21-only eight PARSEC simmedium first samples. '
        'Preserve production areaR5/commonR6/callerR1/token-areaR3/validateR2/ACTIVE shellR3; consume their actual completions after >=300s module or >=600s whole-CAD observation intervals. Compiler8359b23 is future-only; full-design physical readers bind R3 exact paths. No duplicate preparation, new supervisor/subagent, healthy restart, CPU/SVB control or FPGA IO.')
    summary = ('Priority adopted: '+PROFILE+'; foreground HANDOFF.json is pending, so no competing preparation or launch. '
        'Existing productionR5/commonR6/callerR1 identities and immutable bindings preserved; Threaded area and composed shell remain pending. '
        f'Latest completed FULL-DESIGN shell remains {lut} LUT, gap {lut-1303680}, NOT FIT; no performance-only shell/FIT/bitstream result.')
    receipt = D/'area-sprint-20261112/round-00189.json'
    report = dict(schema='ec-area-sprint-round-evidence/1', round=189, utc=now(),
        priority_profile=PROFILE, full_PALIMPSEST=False, functional_baseline_preserved=BASE,
        outcome='WAITING_ACTIVE_JOB', retry_after_seconds=300, summary=summary,
        next_action=next_action, launched_jobs=[], performance_only_handoff_pending=True,
        performance_only_FIT_established=False, certified_performance_only_bitstream=False,
        full_design_reference=measured['full_design_reference'],
        owner_statuses={name:row['status'] for name,row in owners.items()},
        compute_progress_since_round188=progress,
        evidence={p.stem:ref(p) for p in [O/'record.py', O/'owner-observation.json',
            O/'priority-adoption.json', O/'measured-evidence.json']},
        no_FPGA_IO=True, no_CPU_session_control=True, no_SVB_control=True,
        no_healthy_task_restart=True, no_hardware_source_change=True,
        no_new_intelligent_supervisor=True, no_new_subagents=True,
        no_duplicate_foreground_preparation=True)
    assert not receipt.exists()
    assert not HANDOFF.exists(), 'Handoff appeared: adopt before publishing'
    save(receipt, report)
    save(D/'area-sprint-20261112/latest-round.json', dict(round=189, utc=now(),
        receipt=str(receipt), receipt_sha256=sha(receipt), summary=summary, next_action=next_action))
    print(json.dumps(dict(receipt=ref(receipt), profile=PROFILE, handoff_pending=True,
        owner_statuses=report['owner_statuses'], compute_progress=progress,
        full_design_LUT=lut, no_performance_only_FIT=True), indent=2))
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
