#!/usr/bin/python3
"""Adopt existing exact evidence and observe R6; no job/device control."""
import datetime as dt
import fcntl
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import sys

D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
A = Path(__file__).resolve().parent
P = D/'performance-only-20261113'
S = D/'build-logs/Opt4-performance-only-support-r6-20261113'
R = W/'runtime/Opt4-performance-only-6fada307-bound-r1'
HW = '6fada307bb77be90b39720d3f95404fece0e431b'
SID = '461e1b98833d1a78a8bd27c0eed2d3353c648dfbf29ae5588db31bbce0f77369'
UNIT = 'ec-performance-only-support-r6-20261113.service'
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def save(p, row):
    with Path(p).open('x') as f:
        json.dump(row, f, indent=2)
        f.write('\n')


def ref(p):
    return dict(path=str(p), sha256=sha(p))


def proc(pid):
    p = Path('/proc')/str(pid)
    try:
        s = (p/'stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, state=s[0], start_ticks=s[19],
                    cpu_ticks=int(s[11])+int(s[12]), nice=int(s[16]),
                    host_boot_id=BOOT, cgroup=(p/'cgroup').read_text(),
                    cmdline=(p/'cmdline').read_text().replace('\0', ' ')[:1400],
                    children=[int(x) for x in (p/f'task/{pid}/children').read_text().split()])
    except (FileNotFoundError, ProcessLookupError):
        return dict(pid=pid, exited=True)


def tree(pid):
    rows, pending = [], [pid]
    while pending:
        row = proc(pending.pop())
        rows.append(row)
        pending.extend(row.get('children', []))
    return rows


def observe(phase):
    state, cad = read(S/'state.json'), read(S/'cad-state.json')
    assert state['hardware_commit'] == cad['hardware_commit'] == HW
    assert cad['source_id'] == SID
    rows = tree(state['pid'])
    assert rows[0]['start_ticks'] == state['start_ticks'] and BOOT == state['host_boot_id']
    assert UNIT in rows[0]['cgroup']
    log = S/'implementation-attempt-1.log'
    stat = log.stat()
    with log.open('rb') as f:
        f.seek(max(0, stat.st_size-4500))
        tail = f.read().decode(errors='replace').splitlines()[-22:]
    env = dict(os.environ, XDG_RUNTIME_DIR='/run/user/1008',
               DBUS_SESSION_BUS_ADDRESS='unix:path=/run/user/1008/bus')
    services = subprocess.check_output(['systemctl', '--user', 'show', UNIT,
        '--property=Id,ActiveState,SubState,MainPID,ControlGroup,MemoryMax,Nice,Result'], env=env, text=True)
    previous = A/'owner-start.json' if phase == 'end' else A.parent/'round214/owner-end.json'
    prior = read(previous)
    utc = dt.datetime.now(dt.timezone.utc).isoformat()
    by_identity = {(r['pid'], r.get('start_ticks')): r for r in prior['process_tree']}
    deltas = [dict(pid=r['pid'], start_ticks=r['start_ticks'],
        cpu_seconds=(r['cpu_ticks']-by_identity[(r['pid'], r['start_ticks'])]['cpu_ticks'])/os.sysconf('SC_CLK_TCK'))
        for r in rows if (r['pid'], r.get('start_ticks')) in by_identity]
    row = dict(schema='ec-performance-only-round214-owner-observation/1', utc=utc,
        hardware_commit=HW, source_id=SID, controller=rows[0], process_tree=rows,
        services=services, status=cad['status'], stage=cad['current_stage'],
        stage_wall_seconds=cad.get('stage_wall_seconds'),
        placement_phase=next((line.strip() for line in reversed(tail) if line.startswith('Phase ')), None),
        log=dict(path=str(log), bytes=stat.st_size, mtime_ns=stat.st_mtime_ns, tail=tail),
        prior_observation=ref(previous),
        observation_seconds=(dt.datetime.fromisoformat(utc)-dt.datetime.fromisoformat(prior['utc'])).total_seconds(),
        log_growth_bytes=stat.st_size-prior['log']['bytes'], process_cpu_deltas=deltas,
        capacity=(S/'capacity.complete').read_text().strip(),
        bitstream_stage_receipt_exists=(S/'timing_bitstream-result.json').exists(),
        outer_result_exists=(S/'postopt-result.json').exists(),
        no_restart_or_duplicate=True, no_FPGA_IO=True)
    save(A/f'owner-{phase}.json', row)
    print(json.dumps({k:row[k] for k in ['utc','status','stage','observation_seconds','log_growth_bytes','process_cpu_deltas']}))


def authenticate():
    pins = {}
    capacity = read(P/'complete-shell-postopt-r1.json')
    checker_path = P/'checker-whole-link-validation-r1.json'
    checker = read(checker_path)
    assert capacity['hardware_commit'] == checker['hardware_commit'] == HW
    assert capacity['source_id'] == SID and capacity['source_binding_verified']
    assert capacity['capacity_FIT'] and capacity['functional_blackboxes'] == 0
    assert capacity['resources']['CLB LUTs'] == dict(available=1303680.0, used=1023687.0)
    assert capacity['LUT_headroom'] == 279993
    assert checker['status'] == 'PASS_REAL_COMPLETE_HOST_CHECKER_LINK'
    assert checker['real_integrated_checker_execution_passed'] and not checker['actual_checker_results_injected']
    assert checker['source_rtl_and_compiled_model_unchanged'] and checker['expected_application_checksum_passed']
    assert checker['allocations'] == checker['real_full_compare_results'] == checker['BOOM_accepted'] == 131
    assert checker['pending'] == checker['sample_errors'] == 0
    assert checker['per_checker'] == {'1':33, '2':33, '3':33, '4':32}
    assert not checker['FPGA_IO'] and not checker['formal_PARSEC_sample'] and not checker['full_PALIMPSEST']
    assert sha(checker['analysis']) == checker['analysis_sha256']
    analysis = read(checker['analysis'])
    assert analysis['workload_returncode'] == 0
    assert analysis['status'] == checker['status'] and analysis['hardware_commit'] == HW
    pins.update(capacity['artifacts'])
    pins.update(checker['preserved_artifacts'])
    pins.update(analysis['artifacts'])
    pins[analysis['simulation_log']] = analysis['simulation_log_sha256']
    bundle = read(R/'bundle.json')
    assert bundle['hardware_commit'] == HW and bundle['source_id'] == SID
    pins.update(bundle['scripts']);pins.update(bundle['immutable_inputs'])
    source = Path(bundle['source_binding'])
    assert sha(source) == '1b339db692dc0376bb6798a93b479f452485507b825e7102496e7b7db74bf54e'
    binding = read(source);pins.update(binding['files'])
    cad = read(S/'cad-state.json')
    pins.update(cad['inputs']['generated'])
    for item in cad['inputs']['shell_checkpoints']:
        pins[item['path']] = item['sha256']
    assert len(cad['inputs']['shell_checkpoints']) == 11
    link = read(D/'build-logs/Opt4-performance-only-checker-whole-r3-20261113/link-recovery-binding.json')
    protected = link['protected_predecessor_artifacts']
    pins.update(protected)
    for path, digest in pins.items():
        assert sha(path) == digest, path
    admission = P/'physical-runtime-admission-r1.json'
    cert = R/'certified-build.json'
    assert not admission.exists() and not cert.exists(), 'adopt actual new output before pending audit'
    gates = read(P/'ACTIVE_OWNER.json')
    ready = {}
    for name, key in [('postflight','final_checkpoint_checks'),('certificate','exact_certificate_binding')]:
        item = gates[key]
        assert sha(item['source_binding']['path']) == item['source_binding']['sha256']
        own = read(item['source_binding']['path'])
        assert all(sha(p) == h for p,h in own['files'].items())
        completed = subprocess.run(['python3', item['entry']], text=True, capture_output=True, check=True)
        output = json.loads(completed.stdout)
        assert output['FPGA_IO'] is False
        ready[name] = output
    runtime_state = read(D/'Opt4-fit-runtime-state.json')
    owner = proc(runtime_state['pid'])
    assert owner['start_ticks'] == runtime_state['start_ticks'] and BOOT == runtime_state['host_boot_id']
    assert runtime_state['status'] == 'WAITING_FOR_DERIVED_BITSTREAM' and not owner['children']
    assert 'ec-parsec-opt4-fit-runtime.service' in owner['cgroup']
    lock = D/'locks/opt4-fit-runtime.lock'
    inode = lock.stat().st_ino
    entries = [line for line in Path('/proc/locks').read_text().splitlines()
               if f':{inode} ' in line]
    assert any(f'WRITE {owner["pid"]} ' in line for line in entries)
    row = dict(schema='ec-performance-only-round214-evidence-readiness/1',
        utc=dt.datetime.now(dt.timezone.utc).isoformat(), hardware_commit=HW, source_id=SID,
        profile=capacity['profile'], full_PALIMPSEST=False, capacity_FIT=True,
        actual_complete_shell_LUT=1023687, LUT_headroom=279993,
        exact_capacity_receipt=ref(P/'complete-shell-postopt-r1.json'),
        exact_checker_receipt=ref(checker_path), strict_analysis=ref(checker['analysis']),
        actual_checker_counts={k:checker[k] for k in ['actual_target_edges','allocations','real_full_compare_results','BOOM_accepted','per_checker','pending','sample_errors']},
        authenticated_files=len(pins), protected_checker_artifacts=len(protected),
        authenticated_pins=pins, physical_readiness=ready,
        runtime_owner=owner, runtime_lock=str(lock), runtime_lock_entries=entries,
        existing_runtime_lock_held=True, existing_runtime_safe_boundary=True,
        physical_timing_passed=False, certified_bitstream=False, runtime_certified=False,
        integrated_FPGA_validation_still_required=True,
        no_simulation_or_checker_analysis_repeated=True, no_driver_rebuild=True,
        no_new_service_or_waiter=True, no_healthy_restart=True, no_FPGA_IO=True,
        full_EC_ledger=ref(D/'area-sprint-20261112/fullshell-adoptions.json'),
        prototype_ledger=ref(P/'fullshell-adoptions.json'),
        executed_observer=ref(__file__))
    save(A/'evidence-readiness.json', row)
    print(json.dumps({k:v for k,v in row.items() if k not in ['authenticated_pins','runtime_owner','runtime_lock_entries']}))


if __name__ == '__main__':
    if sys.argv[1] == 'authenticate':
        authenticate()
    else:
        assert sys.argv[1] in ['start','end']
        observe(sys.argv[1])
