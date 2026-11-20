#!/usr/bin/env python3
"""Adopt the installed R5 chain; never launch, signal, or edit bound inputs."""
from pathlib import Path
import datetime
import hashlib
import json
import os
import subprocess

D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
C = W / 'candidates/svb-host40-shell-recovery-r5-20261112'
A = Path(__file__).resolve().parent
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()


def read(path):
    return json.loads(Path(path).read_text())


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for chunk in iter(lambda: f.read(8 * 1024 * 1024), b''):
            h.update(chunk)
    return h.hexdigest()


def save(path, data):
    Path(path).write_text(json.dumps(data, indent=2, sort_keys=True) + '\n')


def identity(pid):
    p = Path('/proc') / str(pid)
    fields = (p / 'stat').read_text().rsplit(')', 1)[1].split()
    return dict(pid=pid, start_ticks=fields[19], host_boot_id=BOOT,
                process_state=fields[0], cpu_ticks=int(fields[11]) + int(fields[12]),
                argv=(p / 'cmdline').read_bytes().replace(b'\0', b' ').decode().strip(),
                cgroups=(p / 'cgroup').read_text().splitlines())


def unit(name):
    props = dict(line.split('=', 1) for line in subprocess.check_output([
        'systemctl', 'show', name, '-p', 'MainPID', '-p', 'ActiveState',
        '-p', 'ControlGroup', '-p', 'MemoryMax', '-p', 'CPUQuotaPerSecUSec',
        '-p', 'AllowedCPUs'], text=True).splitlines())
    cg = Path('/sys/fs/cgroup/systemd/system.slice') / name
    pids = sorted({int(x) for f in cg.rglob('cgroup.procs') for x in f.read_text().split()})
    return dict(unit=name, properties=props, processes=[identity(p) for p in pids])


def main():
    assert not (A / 'complete.json').exists(), 'preserve completed adoption receipt'
    utc = datetime.datetime.now(datetime.timezone.utc).isoformat()
    policy_path = D / 'unattended-opt4/campaign-policy.json'
    before = policy_path.read_bytes()
    policy = json.loads(before)
    assert policy['functional_baseline_commit'] == '8491167d84b6d9521b151a743673c1516926a1f8'
    assert policy['board_allowlist'] == ['0000:21:00.0'] and policy['native_paused']
    assert policy['area_equivalence_only'] and not policy['functional_extensions_allowed']

    prep = read(D / 'status-audits/fpga-r5-continuation-20261112/preparation.json')
    for path, expected in prep['source_sha256'].items():
        assert sha(path) == expected, ('R5 bound source changed', path)
    installation = read(C / 'installation.json')
    for name, expected in installation['units'].items():
        assert sha(Path('/etc/systemd/system') / name) == expected
    for name in ['inputs.json', 'runtime-inputs.json', 'application-inputs.json']:
        assert str(policy_path) not in read(C / name)['files']

    r4c = W / 'candidates/svb-host40-shell-recovery-r4-20261112'
    marker = 'clock_contract\nsnapshot final\n'
    assert (C / 'recover.tcl.in').read_text().split(marker, 1)[1] == (r4c / 'recover.tcl.in').read_text().split(marker, 1)[1]
    assert sha(C / 'certificate.py') == sha(r4c / 'certificate.py')

    r5_units = []
    for role, rel in [
        ('physical', 'cycleprecise-svb-host40-shell-recovery-r5-20261112/state.json'),
        ('follow', 'cycleprecise-original-svb-host40-shell-onboard-r5-20261112/state.json'),
        ('application-follow', 'cycleprecise-original-svb-host40-shell-application-onboard-r5-20261112/state.json')]:
        state = read(D / rel)
        row = unit('ec-opt4-svb-host40-shell-' + role + '-r5.service')
        actual = identity(state['pid'])
        assert row['properties']['ActiveState'] == 'active'
        assert row['properties']['MainPID'] == str(state['pid'])
        assert actual['start_ticks'] == str(state['start_ticks']) and actual['host_boot_id'] == state['host_boot_id']
        assert '1:name=systemd:' + row['properties']['ControlGroup'] in actual['cgroups']
        assert actual['pid'] in [p['pid'] for p in row['processes']]
        row.update(state_path=str(D / rel), state=state, identity_verified=True)
        r5_units.append(row)
    physical = r5_units[0]
    assert physical['properties']['MemoryMax'] == str(64 * 2**30)
    assert physical['properties']['AllowedCPUs'] == '224-225'
    assert physical['properties']['CPUQuotaPerSecUSec'] == '2s'
    vivados = [p for p in physical['processes'] if p['argv'].startswith('/tools/Xilinx/Vivado/2021.1/bin/unwrapped/lnx64.o/vivado ')]
    assert len(vivados) == 1
    assert os.sched_getaffinity(vivados[0]['pid']) == {224, 225}
    lock = D / 'cycleprecise-svb-host40-shell-recovery-r4-20261112/extra-component-slot.lock'
    lock_stat = lock.stat()
    lock_key = f'{os.major(lock_stat.st_dev):02x}:{os.minor(lock_stat.st_dev):02x}:{lock_stat.st_ino}'
    held = [line for line in Path('/proc/locks').read_text().splitlines()
            if f' WRITE {physical["state"]["pid"]} {lock_key} ' in line]
    assert len(held) == 1
    predecessor = unit('ec-opt4-svb-host40-shell-physical-r4.service')
    assert predecessor['properties']['MainPID'] == '0' and not predecessor['processes']
    assert predecessor['properties']['ActiveState'] in ['inactive', 'failed']

    preserved = []
    for name, rel in [
        ('ec-opt4-auto-svb-physical-resource-recovery-r51-v1.service', 'Opt4-svb-physical-resource-recovery-round51-v1-state.json'),
        ('ec-opt4-auto-svb-physical-resume-r3-v1-8491167d.service', 'Opt4-svb-physical-resume-r3-state.json'),
        ('ec-opt4-auto-mcrams-full-host-capacity-r1-3656aec4.service', 'Opt4-mcrams-full-host-capacity-r1-state.json'),
        ('ec-opt4-auto-owner-mc-runtime-r2-3656aec4.service', 'Opt4-mcrams-owner-mc-runtime-r2-state.json'),
        ('ec-opt4-auto-mcrams-host-continuation-r2-3656aec4.service', 'Opt4-mcrams-full-host-continuation-r2-state.json'),
        ('ec-opt4-fpga-priority-handoff-r1.service', 'fpga-priority-handoff-r1-20261112/state.json')]:
        state = read(D / rel)
        row = unit(name)
        actual = identity(state['pid'])
        assert row['properties']['ActiveState'] == 'active'
        assert actual['pid'] in [p['pid'] for p in row['processes']]
        assert actual['start_ticks'] == str(state['start_ticks']) and actual['host_boot_id'] == state['host_boot_id']
        assert '1:name=systemd:' + row['properties']['ControlGroup'] in actual['cgroups']
        row.update(identity_verified=True, status=state['status'], state_path=str(D / rel))
        preserved.append(row)

    selected = read(D / 'cycleprecise-svb-host40-shell-recovery-r5-20261112/selected-checkpoint.json')
    chosen_result = Path(selected['chosen'][3])
    result = read(chosen_result)
    chosen_dcp = Path(selected['chosen'][2])
    assert sha(chosen_dcp) == result['outputs'][str(chosen_dcp)]
    sealed = read(D / 'cycleprecise-svb-host40-shell-recovery-r5-20261112/E-preroute-shell-replication/sealed-inputs.json')
    assert sealed['source_checkpoint'] == str(chosen_dcp)
    assert sha(sealed['sealed_checkpoint']) == sealed['sealed_checkpoint_sha256'] == result['outputs'][str(chosen_dcp)]
    assert sealed['source_checkpoint_sha256'] == result['outputs'][str(chosen_dcp)]
    receipt = dict(schema='ec-fpga-round123-r5-adoption/1', utc=utc,
        status='ADOPTED_EXISTING_R5_NO_REINSTALL', r5_units=r5_units,
        predecessor=predecessor, shared_slot_lock=str(lock), lock_proof=held,
        bound_source_sha256=prep['source_sha256'], preserved_units=preserved,
        selected_checkpoint=selected, selected_result_sha256=sha(chosen_result),
        sealed_checkpoint_sha256=sealed['sealed_checkpoint_sha256'],
        unchanged_tcl_final_gate=True, unchanged_independent_certificate=True,
        actual_tool_support='PENDING_CAD_OBSERVATION_AT_NORMAL_INTERVAL',
        automatic_next='E actual exit -> F private unroute/fanout_opt/placement_opt/routing_opt; success -> independent certification -> card21 directed -> samebit real-application replay; R5 exhausted -> preserve and independently version minimal recovery via authorized administrator',
        new_jobs=[], process_signals=[], fpga_operations=[], cpu_comparison_operations=[],
        no_whole_cad_started=True, component_is_not_complete_ec=True)
    save(A / 'adoption.json', receipt)
    (A / 'campaign-policy.before.json').write_bytes(before)
    previous = policy['foreground_svb_resource_readmission_reserved']
    policy['foreground_svb_resource_readmission_reserved'] = dict(
        directory=str(C), state=physical['state_path'], units=list(installation['units']),
        installation_sha256=sha(C / 'installation.json'), utc=utc,
        status='R5_ADOPTED_EXISTING_ACTIVE_E_NO_REINSTALL',
        resource_readmission=previous['resource_readmission'], shared_slot_lock=str(lock),
        physical_or_target_gates_changed=False, live_cad_signalled=False,
        adoption_receipt=str(A / 'adoption.json'), adoption_receipt_sha256=sha(A / 'adoption.json'),
        predecessor_r4_receipt=str(A / 'campaign-policy.before.json'))
    policy['latest_svb_r5_adoption'] = dict(utc=utc, receipt=str(A / 'adoption.json'), sha256=sha(A / 'adoption.json'))
    policy['foreground_request_for_next_worker'] = (
        'Adopt installed ACTIVE R5 E/F and its existing three services; DO NOT duplicate, reinstall or edit bound source. '
        'R4 B/C/D failures immutable and exact physical cgroup empty. R5 uses same r4 shared slot lock, CPUs224225/64GiB. '
        'E actual exit -> automatic F. Preserve all certification/clock/timing/DRC/route/pulse/skew/21only/realapplication gates. '
        'If exhausted, preserve evidence then independently version minimal recovery through existing authorized administrator; no new whole CAD. '
        'Keep r51/r3, complete MCRams capacity, owner-MC parity, continuation and priority handoff alive. '
        'Separate CPU comparison/paper session remains independently owned. See ' + str(A / 'adoption.json'))
    assert policy_path.read_bytes() == before, 'concurrent policy update; merge independently'
    temp = policy_path.with_name('.campaign-policy.round123.tmp')
    save(temp, policy)
    os.chmod(temp, policy_path.stat().st_mode & 0o777)
    os.replace(temp, policy_path)
    changed_keys = [k for k in policy if policy.get(k) != json.loads(before).get(k)]
    assert set(changed_keys) == {'foreground_svb_resource_readmission_reserved', 'foreground_request_for_next_worker', 'latest_svb_r5_adoption'}
    save(A / 'complete.json', dict(status='COMPLETE_ADOPTION_ONLY', utc=utc,
        adoption_sha256=sha(A / 'adoption.json'), campaign_before_sha256=hashlib.sha256(before).hexdigest(),
        campaign_after_sha256=sha(policy_path), changed_policy_keys=changed_keys,
        script_sha256=sha(__file__)))
    print(json.dumps(dict(status=receipt['status'], physical_pid=physical['state']['pid'],
        vivado_pid=vivados[0]['pid'], selected_result_sha256=receipt['selected_result_sha256'],
        adoption_sha256=sha(A / 'adoption.json'), complete_sha256=sha(A / 'complete.json'),
        changed_policy_keys=changed_keys)))


if __name__ == '__main__':
    main()
