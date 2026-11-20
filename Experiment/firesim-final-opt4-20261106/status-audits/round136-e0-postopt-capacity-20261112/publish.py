#!/usr/bin/env python3
"""Pin an exited CAD result and correct only its durable capacity/status fields."""
import datetime
import fcntl
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import shutil
import subprocess

B = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = Path(__file__).resolve().parent
R = B / 'build-logs/Opt4-fit-update-share-svb-cad-e0c3737f'
POLICY = B / 'unattended-opt4/campaign-policy.json'
UNIT = 'ec-opt4-auto-e0-safe-overlap-cad-r4-e0c3737f.service'
COMMIT = 'e0c3737f989c563f99a00f3fd26c1cbd27421775'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for chunk in iter(lambda: f.read(2**20), b''):
            h.update(chunk)
    return h.hexdigest()


def write(p, obj):
    p = Path(p)
    data = json.dumps(obj, indent=2, sort_keys=True) + '\n'
    tmp = p.with_name(p.name + '.tmp-' + str(os.getpid()))
    with tmp.open('w') as f:
        f.write(data)
        f.flush()
        os.fsync(f.fileno())
    os.replace(tmp, p)


def pin(src, name):
    src = Path(src)
    stat = src.stat()
    dst = O / name
    assert not dst.exists(), dst
    shutil.copyfile(src, dst)
    digest = sha(dst)
    after = src.stat()
    assert (stat.st_size, stat.st_mtime_ns) == (after.st_size, after.st_mtime_ns), src
    assert digest == sha(src), src
    return {'source': str(src), 'copy': str(dst), 'sha256': digest,
            'bytes': stat.st_size, 'source_mtime_ns': stat.st_mtime_ns}


def main():
    assert not (O / 'receipt.json').exists(), 'Immutable round already published'
    utc = datetime.datetime.now(datetime.timezone.utc).isoformat()
    state_pin = pin(B / 'Opt4-fit-update-share-svb-cad-state.json', 'e0-final-state.json')
    state = json.loads((O / 'e0-final-state.json').read_text())
    assert state['status'] == 'NOT_FIT_POSTOPT'
    assert state['hardware_commit'] == COMMIT and state['frozen_parent_commit'] == BASE
    assert state['stages']['implementation']['returncode'] == 1
    assert not state['certified_bitstream'] and not state['fpga_access']
    assert not Path('/proc/' + str(state['pid'])).exists(), 'Historical controller PID reused or live'

    result = subprocess.run(
        ['systemctl', 'show', UNIT, '-p', 'Id', '-p', 'ActiveState', '-p', 'SubState',
         '-p', 'MainPID', '-p', 'ControlGroup'], capture_output=True, text=True, check=True)
    unit = dict(line.split('=', 1) for line in result.stdout.splitlines())
    assert unit['Id'] == UNIT and unit['ActiveState'] == 'inactive'
    assert unit['MainPID'] == '0' and unit['ControlGroup'] == ''
    cgroups = []
    for root in ['/sys/fs/cgroup/systemd', '/sys/fs/cgroup/memory',
                 '/sys/fs/cgroup/cpu,cpuacct', '/sys/fs/cgroup']:
        path = Path(root) / 'system.slice' / UNIT
        members = {str(f): f.read_text().split() for f in path.rglob('cgroup.procs')} if path.exists() else {}
        assert not any(members.values()), members
        cgroups.append({'path': str(path), 'exists': path.exists(), 'recursive_members': members})
    service = {'unit': unit, 'recursive_cgroups': cgroups, 'observed_utc': utc,
               'historical_controller': {'pid': state['pid'], 'start_ticks': state['start_ticks'],
                                         'host_boot_id': state['host_boot_id'], 'pid_absent': True}}
    write(O / 'e0-service-exit.json', service)

    files = {'state': state_pin}
    for n in ['top-postopt-utilization.rpt', 'top-postopt-hierarchical.rpt', 'top-postopt-drc.rpt',
              'capacity.complete', 'implementation-bound.tcl', 'implementation-attempt-1.tcl',
              'implementation-attempt-1.log', 'selection.json']:
        files[n] = pin(R / n, n)
    assert (O / 'capacity.complete').read_text().strip() == 'NOT_FIT_POSTOPT {CLB LUTs}'
    assert sha(O / 'implementation-attempt-1.tcl') == state['stages']['implementation']['tcl_sha256']
    log = (O / 'implementation-attempt-1.log').read_text()
    assert 'NOT FIT; saved optimized checkpoint, no place/route: {CLB LUTs}' in log
    impl = Path(state['output_dir']) / 'vivado_proj/firesim.runs/impl_1'
    absent = ['.place_design.begin.rst', '.route_design.begin.rst',
              'design_1_wrapper_placed.dcp', 'design_1_wrapper_routed.dcp', 'design_1_wrapper.bit']
    assert all(not (impl / n).exists() for n in absent), 'Unexpected downstream implementation artifact'
    dcp = impl / 'design_1_wrapper_opt.dcp'
    dcp_stat = dcp.stat()
    dcp_hash = sha(dcp)
    assert (dcp_stat.st_size, dcp_stat.st_mtime_ns) == (dcp.stat().st_size, dcp.stat().st_mtime_ns)

    parser_src = Path('/data1/gzh/EC/firesim/final-opt4-20261106/candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py')
    files['resource_parser.py'] = pin(parser_src, 'resource_parser.py')
    spec = importlib.util.spec_from_file_location('saved_resource_parser', O / 'resource_parser.py')
    parser = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(parser)
    text = (O / 'top-postopt-utilization.rpt').read_text()
    assert re.search(r'^\| Design\s+: design_1_wrapper\s*$', text, re.M)
    assert re.search(r'^\| Device\s+: xcu280fsvh2892-2L\s*$', text, re.M)
    assert re.search(r'^\| Design State\s+: Optimized\s*$', text, re.M)
    resources = {}
    for label, section in parser.SECTIONS.items():
        rows = parser.table(parser.section(text, section), 'Site Type')
        matches = [row for row in rows if row['Site Type'].rstrip('*') == label]
        assert len(matches) == 1, (label, matches)
        row = matches[0]
        used, available = parser.number(row['Used']), parser.number(row['Available'])
        assert available == parser.CAPACITY[label]
        assert used == state['top_postopt_resources'][label]['used']
        resources[label] = {'used': used, 'available': available, 'percent': used / available * 100}
    checks = parser.crosschecks(text, resources)
    hier_text = (O / 'top-postopt-hierarchical.rpt').read_text()
    rows = parser.table(parser.section(hier_text, '1. Utilization by Hierarchy'), 'Instance')
    tops = [r for r in rows if r['Instance'] == 'design_1_wrapper' and r['Module'] == '(top)']
    assert len(tops) == 1
    top = tops[0]
    mapped = {'CLB LUTs': parser.number(top['Total LUTs']), 'CLB Registers': parser.number(top['FFs']),
              'Block RAM Tile': parser.number(top['RAMB36']) + parser.number(top['RAMB18']) / 2,
              'DSPs': parser.number(top['DSP Blocks']), 'URAM': parser.number(top['URAM'])}
    assert all(v == resources[k]['used'] for k, v in mapped.items())
    checks['hierarchy_totals_agree'] = mapped
    checks['state_totals_agree'] = True
    checks['capacity_gate_marker_agrees'] = True
    checks['placement_route_bitstream_artifacts_absent'] = absent

    with (O / 'publication.lock').open('w') as lock:
        fcntl.flock(lock, fcntl.LOCK_EX)
        policy_bytes = POLICY.read_bytes()
        before = json.loads(policy_bytes)
        assert before['functional_baseline_commit'] == BASE
        prior = before['latest_postopt_capacity']
        assert prior['commit'] == '9ae9a7fcf231a75259e23973b12a93896a443cbb'
        receipt = {
            'schema': 'ec-opt4-round136-completed-postopt-capacity/1', 'round': 136,
            'utc': utc, 'status': 'COMPLETED_E0_NOT_FIT_POSTOPT_PUBLISHED',
            'commit': COMMIT, 'source_id': state['source_id'], 'functional_baseline': BASE,
            'scope': 'Complete e0 design_1_wrapper after opt_design, including U280 shell',
            'resources': resources, 'lut_excess': int(resources['CLB LUTs']['used'] - resources['CLB LUTs']['available']),
            'measured_LUT_difference_from_9ae': int(resources['CLB LUTs']['used'] - prior['resources']['CLB LUTs']['used']),
            'comparison_limit': 'Different bound commits; measured resource difference does not establish causality or correctness admission',
            'physical_FIT': False, 'timing_certified': False, 'FPGA_samples': 0,
            'placement_skipped_by_capacity_gate': True, 'checks': checks, 'files': files,
            'saved_optimized_checkpoint': {'path': str(dcp), 'bytes': dcp_stat.st_size,
                                           'mtime_ns': dcp_stat.st_mtime_ns, 'sha256': dcp_hash},
            'e0_exit_evidence': str(O / 'e0-service-exit.json'),
            'original_MCrams_postopt': 'PENDING_IN_ROUND136_INITIAL_OBSERVATION_NOT_THIS_E0_RESULT',
            'existing_r6_H': {'pid': 3159232, 'start_ticks': '28601732',
                              'exact_cgroup': '/system.slice/ec-opt4-svb-host40-shell-physical-r6.service',
                              'status': 'RUNNING_IN_ROUND136_INITIAL_IDENTITY_CHECK_INTERMEDIATE_TIMING_ONLY'},
            'existing_metrics_request': 'STARTED_SINGLETON_WAITING_R5_RECEIPTS_NOT_QUEUED',
            'existing_shell_observer': 'R4B_WAITING_ACTUAL_R3_CLOCK_FAILURE_NO_CAD',
            'launched_jobs': [], 'new_requests': [], 'FPGA_operations': [],
            'CPU_comparison_controls': [], 'bound_source_changes': [], 'process_signals': [],
            'normal_CAD_recheck_seconds': 300, 'whole_CAD_recheck_seconds': 600,
            'next_automatic_action': 'Preserve r6 H->I->J and all certification/21-only directed/samebit replay gates. Original complete MCrams capacity continues to authoritative postopt; its r3 continuation requires actual FIT plus finite parity. Preserve r4b conditional observer, metrics singleton and all memory guards.',
        }
        write(O / 'campaign-policy.before.json', before)
        # Keep the previous capacity record and stale live-entry content reviewable.
        after = json.loads(policy_bytes)
        after['latest_completed_e0_postopt'] = {
            'commit': COMMIT, 'source_id': state['source_id'], 'status': 'NOT_FIT_POSTOPT',
            'resources': resources, 'lut_excess': receipt['lut_excess'],
            'placement_skipped_by_capacity_gate': True, 'certified_bitstream': False,
            'receipt': str(O / 'receipt.json'), 'observed_utc': utc}
        after['live_e0_whole_cad'].update({
            'status': 'COMPLETED_NOT_FIT_POSTOPT_SERVICE_INACTIVE', 'identity_live': False,
            'scope': 'Completed e0 complete-shell postopt; 2789012 LUTs, not FIT; checkpoint and reports retained. No restart or duplicate whole CAD.',
            'completion_receipt': str(O / 'receipt.json')})
        after['latest_postopt_capacity'] = {
            'commit': COMMIT, 'source_id': state['source_id'], 'functional_baseline': BASE,
            'status': 'NOT_FIT_POSTOPT', 'resources': resources, 'lut_excess': receipt['lut_excess'],
            'placement_skipped_by_capacity_gate': True, 'receipt': str(O / 'receipt.json'),
            'reports': {v['source']: v['sha256'] for k, v in files.items()
                        if k in ['top-postopt-utilization.rpt', 'top-postopt-hierarchical.rpt', 'capacity.complete']},
            'preceding_result': prior,
            'not_original_MCrams_result': True}
        after['latest_worker_round136_e0_postopt'] = {
            'status': receipt['status'], 'receipt': str(O / 'receipt.json'), 'utc': utc,
            'no_bound_source_changes': True, 'no_new_jobs': True}
        after['foreground_request_for_next_worker'] = (
            'Round136 pinned completed e0 fullshell postopt: 2789012LUT/1792097FF/81248CARRY8/1028.5BRAM/195DSP; '
            'zero blackboxes, NOTFIT excess1485332, service inactive/MainPID0/exact cgroups absent. '
            'Optimized DCP and reports retained; no place/route/bitstream; do not restart e0. '
            'This is distinct from original owner-MCrams capacity PID2379656/start25825451, which was still '
            'RUNNING_FULL_HOST_OPT_DESIGN with no postopt report at the round136 initial check; preserve it. '
            'Its known OOC synth2421933LUT is not shell FIT. Existing r6 H PID3159232/start28601732 was identity-matched '
            'in exact physical-r6 cgroup; preserve H->I->J and all original physical/certification/21-only directed '
            'and samebit application gates. R5 E/F terminal failure retained. Preserve r3 continuation and r4b '
            'conditional IPcollateral observer; shell-only/static inventory does not prove applied fullshell '
            'clock exceptions. Original metrics request STARTED PID2813002/start27638842, waiting exact r5 '
            'receipts; no duplicate, source edit or memory-guard bypass. No CPUcomparison controls or FPGA '
            'operations. NormalCAD checks>=300s, whole>=600s. Evidence: ' + str(O / 'receipt.json'))
        # Detect another writer rather than overwrite new foreground changes.
        assert POLICY.read_bytes() == policy_bytes, 'Concurrent policy writer; retry publication from new bytes'
        write(O / 'campaign-policy.after.json', after)
        write(POLICY, after)
        receipt['campaign_policy_before_sha256'] = hashlib.sha256(policy_bytes).hexdigest()
        receipt['campaign_policy_after_sha256'] = sha(POLICY)
        receipt['FPGA_SESSION_POLICY_sha256'] = sha(B / 'FPGA_SESSION_POLICY.json')
        write(O / 'receipt.json', receipt)

    report = (
        'Round136 pinned the completed e0 fullshell optimized result: 2,789,012 LUTs (213.93%), '
        '1,792,097 FFs, 81,248 CARRY8s, 1,028.5 BRAM tiles and 195 DSPs. The LUT excess is '
        '1,485,332. This is NOT FIT; the existing capacity gate stopped before placement. '
        'The final report, hierarchy and state agree; the primitive CARRY8 total agrees and no blackboxes remain.\n\n'
        'The e0 service is inactive with MainPID 0 and absent exact cgroups. The optimized checkpoint is '
        'retained and hashed in receipt.json. Its input commit is e0c3737f, distinct from the still pending '
        'original owner-MCrams postopt result. The measured LUT difference from completed 9ae is -58,370; '
        'this comparison supplies no correctness or timing admission.\n\n'
        'R6 H and both followers, original MCrams capacity, r3 continuation, r4b observer and the original '
        'metrics singleton were preserved. No jobs, requests, process signals, bound-source changes, '
        'CPU comparison controls or FPGA operations were issued. Next: existing H->I->J and strict '
        'certification/21-only replay; original MCrams authoritative postopt, then existing FIT/parity gates.\n')
    (O / 'REPORT.md').write_text(report)
    manifest = {str(p): sha(p) for p in O.iterdir()
                if p.is_file() and p.name not in ['artifact-sha256.json', 'publication.lock']}
    write(O / 'artifact-sha256.json', manifest)
    print(json.dumps({'receipt': str(O / 'receipt.json'), 'receipt_sha256': sha(O / 'receipt.json'),
                      'resources': resources, 'checks': checks, 'DCP_sha256': dcp_hash,
                      'policy_updated_fields': ['latest_completed_e0_postopt', 'live_e0_whole_cad',
                                                'latest_postopt_capacity', 'latest_worker_round136_e0_postopt',
                                                'foreground_request_for_next_worker']}))


if __name__ == '__main__':
    main()
