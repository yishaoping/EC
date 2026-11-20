#!/usr/bin/env python3
"""Snapshot exact existing r7 identities and publish a narrow durable handoff."""
import datetime
import hashlib
import json
import os
from pathlib import Path
import subprocess

B = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
A = Path(__file__).resolve().parent
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def read(p):
    return json.loads(Path(p).read_text())


def save(name, data):
    with (A/name).open('x') as f:
        json.dump(data, f, indent=2, sort_keys=True)
        f.write('\n')


def identity(pid, expected=None, cgroup=None):
    p = Path('/proc')/str(pid)
    try:
        fields = (p/'stat').read_text().rsplit(')', 1)[1].split()
        groups = sorted(set(x.split(':', 2)[2] for x in (p/'cgroup').read_text().splitlines()))
        argv = [x.decode() for x in (p/'cmdline').read_bytes().split(b'\0') if x]
    except FileNotFoundError:
        return dict(pid=pid, live=False, expected=expected)
    if expected:
        assert str(expected['start_ticks']) == fields[19]
        assert expected['host_boot_id'] == BOOT
    if cgroup:
        assert cgroup in groups
    return dict(pid=pid, live=True, host_boot_id=BOOT, start_ticks=fields[19], process_state=fields[0],
        cpu_ticks=int(fields[11])+int(fields[12]), argv=argv, exact_cgroups=groups,
        expected_identity_match=bool(expected), expected_cgroup=cgroup)


assert not (A/'receipt.json').exists(), 'immutable round already published'
now = datetime.datetime.now(datetime.timezone.utc).isoformat()
services = []
for rev in [5, 6, 7]:
    for kind, rel in [
        ('physical', f'cycleprecise-svb-host40-shell-recovery-r{rev}-20261112/state.json'),
        ('follow', f'cycleprecise-original-svb-host40-shell-onboard-r{rev}-20261112/state.json'),
        ('application-follow', f'cycleprecise-original-svb-host40-shell-application-onboard-r{rev}-20261112/state.json'),
    ]:
        unit = f'ec-opt4-svb-host40-shell-{kind}-r{rev}.service'
        p = B/rel
        raw = p.read_bytes()
        state = json.loads(raw)
        assert state['host_boot_id'] == BOOT
        props = dict(x.split('=', 1) for x in subprocess.check_output([
            'systemctl', 'show', unit, '--property=MainPID,ControlGroup,ActiveState,SubState,MemoryMax,CPUAffinity'], text=True).splitlines())
        group = '/system.slice/'+unit
        cg = Path('/sys/fs/cgroup/systemd')/group.lstrip('/')
        tasks = {int(x) for f in cg.rglob('cgroup.procs') for x in f.read_text().split()} if cg.exists() else set()
        controller = identity(state['pid'], state, group)
        members = [identity(pid, cgroup=group) for pid in sorted(tasks)]
        assert all(x['live'] for x in members)
        if controller['live']:
            assert props['MainPID'] == str(state['pid']) and props['ControlGroup'] == group
            assert props['ActiveState'] == 'active'
        if rev in [5, 6] and kind == 'physical':
            assert state['status'] == 'BOUNDED_SHELL_STRATEGIES_FAILED_WITH_ALL_CHECKPOINTS_RETAINED'
            assert not controller['live'] and not tasks and props['MainPID'] == '0'
        if rev == 7:
            assert controller['live'], unit
            if kind == 'physical':
                assert props['MemoryMax'] == str(64*2**30)
                assert state['mode'].startswith('K-'), 'phase changed: capture a new independently named audit'
                assert set(os.sched_getaffinity(state['pid'])) == {224, 225}
                child = identity(state['child']['pid'], state['child'], group)
                assert child['live']
                vivados = [x for x in members if x['argv'] and x['argv'][0].endswith('/unwrapped/lnx64.o/vivado')]
                assert len(vivados) == 1 and '/K-postroute-aggressive-explore/' in ' '.join(vivados[0]['argv'])
                current = dict(state=state, controller=controller, child=child, actual_vivado=vivados[0], properties=props,
                    cgroup_tasks=sorted(tasks), intermediate_is_final=False)
        (A/(unit+'.state.json')).write_bytes(raw)
        services.append(dict(unit=unit, state_path=str(p), state_sha256=hashlib.sha256(raw).hexdigest(),
            status=state['status'], controller=controller, properties=props, tasks=sorted(tasks), members=members))
save('service-identities.json', dict(utc=now, host_boot_id=BOOT, services=services))
r7root = B/'cycleprecise-svb-host40-shell-recovery-r7-20261112'
handoff = read(r7root/'r6-failure-handoff.json')
assert handoff['predecessor_state']['status'] == 'BOUNDED_SHELL_STRATEGIES_FAILED_WITH_ALL_CHECKPOINTS_RETAINED'
assert handoff['cgroup_tasks'] == [] and not handoff['processes_signalled']
assert handoff['properties']['MainPID'] == '0'
selected = read(r7root/'selected-checkpoint.json')
assert selected['timing']['wns'] == -0.017 and selected['timing']['whs'] == 0.001
completed = read(A/'completed-results.json')
assert selected['sha256'] == completed['completed']['I']['files']['final.dcp']['sha256']
for name in ['r6-failure-handoff.json', 'selected-checkpoint.json']:
    (A/('r7-'+name)).write_bytes((r7root/name).read_bytes())
save('r7-live-adoption.json', dict(utc=now, status='EXISTING_R7_K_ADOPTED_NO_REINSTALL_OR_NEW_REQUEST',
    current=current, predecessor_cgroup_empty=True, selected_checkpoint=selected,
    same_component_lock=str(B/'cycleprecise-svb-host40-shell-recovery-r4-20261112/extra-component-slot.lock'),
    conditional_strategies=['L-postroute-alternate-replication', 'M-postroute-critical-SRL-output-reroute'],
    conditional_M_API_hazard=str(A/'api-repair-plan.json'), independently_installed_followers_verified=True))

metrics = []
for version, expected in [(1, '/system.slice/ec-opt4-auto-svb-application-fpga-metrics-r1-8491167d.service'),
                          (2, '/user.slice/user-1008.slice/user@1008.service/ec-opt4-svb-application-metrics-r2-20261112.service')]:
    p = B/f'svb-application-fpga-metrics-r{version}-20261112/state.json'
    state = read(p)
    row = identity(state['pid'], state, expected)
    assert row['live'] and state['device_operations'] == [] and not state['fpga_access']
    metrics.append(dict(version=version, state_path=str(p), status=state['status'], identity=row,
        running=True, queued=False, device_operations=[]))
save('metrics-identities.json', dict(utc=now, consumers=metrics, new_requests=[]))
observer = dict(pid=2797798, start_ticks='27514959', host_boot_id=BOOT)
unit = 'ec-opt4-auto-mcrams-ipcollateral-recovery-observer-r4b-3656aec4.service'
row = identity(observer['pid'], observer, '/system.slice/'+unit)
assert row['live']
save('shell-observer-identity.json', dict(utc=now, existing_observer=row, new_observer=False))

next_action = ('Preserve existing r7 K then conditional L with all timing/route/DRC/clock/pulse/skew and independent '
    'certification gates, followed by existing locked 21-only directed and same-bit application replay. '
    'M has the proven J POINTS API hazard: preserve bound r7; if reached/fails, preserve evidence and use an '
    'independently versioned minimal API repair only after actual Vivado property validation and exact predecessor '
    'exit/empty-cgroup/same-slot gates. Keep original MCrams capacity/r3 continuation/r4b observer and both metrics singletons. '
    'No new whole CAD, duplicate request, CPU-comparison control or FPGA sample.')
receipt = dict(schema='ec-opt4-round138-r6-closure-r7-handoff/1', round=138, utc=now,
    status='I_FINAL_SETUP_FAILURE_J_API_FAILURE_PRESERVED_EXISTING_R7_K_ADOPTED',
    functional_baseline=completed['functional_baseline'], source_id=completed['source_id'],
    completed_results=str(A/'completed-results.json'), completed_results_sha256=sha(A/'completed-results.json'),
    I_final_timing=completed['completed']['I']['result']['timing'],
    I_final_checkpoint=completed['completed']['I']['files']['final.dcp'],
    J_failure=completed['completed']['J']['failure'], J_final_timing=None,
    r7_actual_vivado=current['actual_vivado'], r7_mode=current['state']['mode'],
    r7_current_status=current['state']['status'], r7_intermediate_is_final=False,
    running_metrics_versions=[1, 2], queued_metrics_requests=0, existing_r4b_observer=row,
    original_MCrams='Original controller PID2379596/start25825420 and child PID2379621/start25825441 matched at initial round read; postopt pending; not polled again inside600s',
    API_repair_status='PREPARED_UNAPPLIED_NOT_TOOL_VALIDATED_NOT_ADMITTED', API_repair=str(A/'api-repair-plan.json'),
    launched_jobs=[], new_requests=[], retired_processes=[], process_signals=[], live_bound_edits=[],
    FPGA_operations=[], CPU_comparison_controls=[], certified_bitstream=False, FPGA_samples=0,
    next_automatic_action=next_action, normal_CAD_recheck_seconds=300, whole_CAD_recheck_seconds=600)
save('receipt.json', receipt)

policy = B/'unattended-opt4/campaign-policy.json'
before = policy.read_bytes()
p = json.loads(before)
(A/'campaign-policy.before.json').write_bytes(before)
p['latest_p0_result_update'] = dict(result=str(A/'receipt.json'), result_sha256=sha(A/'receipt.json'),
    I_final_timing=receipt['I_final_timing'], J_failure='UNSUPPORTED_POINTS_PROPERTY_BEFORE_UNROUTE',
    existing_r7_mode=receipt['r7_mode'], actual_r7_vivado=receipt['r7_actual_vivado'], next_automatic_action=next_action)
p['latest_worker_execution_report'] = str(A/'receipt.json')
p['foreground_request_for_next_worker'] = (
    'Round138: r6 exhausted and exact physical cgroup empty. I FINAL FAILED WNS-0.017/WHS+0.001, '
    'TNS-0.387/42setup, routed255876/255876/errors0,49DRCwarnings/noError,no_clock0/unconstrained0. '
    'I finalDCP ed6266703cf077adc0e642cc8431e974486610e82dc9b4dfcd5f4a8bee521133. '
    'J FAILED before unroute: Vivado2021.1 timing_path POINTS property unsupported; no finaltiming. '
    f"Existing r7 K actuallyRUNNING PID{current['actual_vivado']['pid']}/start{current['actual_vivado']['start_ticks']}, "
    'boot/exact physical-r7 cgroup verified, private input exactly I finalDCP; do not duplicate/edit. '
    'K/L do not invoke broken selector; M contains same POINTS call. Separate unapplied two-token '
    'TIMING_POINTS repair preview retained, NOT toolvalidated/admitted; if needed independentlyversion '
    'after actual propertyvalidation and exact predecessor exit/emptycgroup/sameslot. '
    'Both r7 certificate/21-only directed and samebit application followers active. '
    'Metrics r1/r2 RUNNING waiting receipts, not queued; preserve singletons. '
    'OriginalMCrams postoptpending and r3/r4b preserved; no newwhole/CPUcomparison/deviceoperations. '
    'NormalCAD>=300s/whole>=600s. Evidence: '+str(A/'receipt.json'))
assert policy.read_bytes() == before, 'policy changed concurrently; immutable receipt remains valid'
temp = policy.with_name('campaign-policy.round138.tmp')
temp.write_text(json.dumps(p, indent=2, sort_keys=True)+'\n')
os.replace(temp, policy)
(A/'campaign-policy.after.json').write_bytes(policy.read_bytes())
save('publication.json', dict(receipt_sha256=sha(A/'receipt.json'), policy_before_sha256=hashlib.sha256(before).hexdigest(),
    policy_after_sha256=sha(policy), changed_policy_keys=['latest_p0_result_update', 'latest_worker_execution_report', 'foreground_request_for_next_worker']))
print(json.dumps(dict(receipt=str(A/'receipt.json'), sha256=sha(A/'receipt.json'),
    I_final_timing=receipt['I_final_timing'], J_failure='POINTS_UNSUPPORTED', r7_mode=receipt['r7_mode'],
    r7_vivado=current['actual_vivado'], launched_jobs=[])))
