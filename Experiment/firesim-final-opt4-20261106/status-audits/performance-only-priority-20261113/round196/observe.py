#!/usr/bin/python3
"""One-shot read-only owner/result audit; never controls or launches work."""
import datetime as dt
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys

D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
A = Path(__file__).resolve().parent
R = D/'build-logs/Opt4-performance-only-support-r6-20261113'
K = D/'build-logs/Opt4-performance-only-checker-whole-r1-20261113'
HARDWARE = '6fada307bb77be90b39720d3f95404fece0e431b'
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def save(p, data):
    with Path(p).open('x') as f:
        json.dump(data, f, indent=2)
        f.write('\n')


def process(pid):
    p = Path('/proc')/str(pid)
    try:
        s = (p/'stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, state=s[0], start_ticks=s[19],
                    cpu_ticks=int(s[11])+int(s[12]), nice=int(s[16]),
                    host_boot_id=BOOT, cgroup=(p/'cgroup').read_text(),
                    cmdline=(p/'cmdline').read_text().replace('\0', ' ')[:1000],
                    children=[int(x) for x in
                              (p/f'task/{pid}/children').read_text().split()])
    except FileNotFoundError:
        return dict(pid=pid, exited=True)


def tree(pid):
    result, pending = [], [pid]
    while pending:
        row = process(pending.pop())
        result.append(row)
        pending.extend(row.get('children', []))
    return result


def log_info(p):
    if not p.exists():
        return None
    s = p.stat()
    with p.open('rb') as f:
        f.seek(max(0, s.st_size-7000))
        tail = f.read().decode(errors='replace').splitlines()[-16:]
    return dict(path=str(p), bytes=s.st_size, mtime_ns=s.st_mtime_ns, tail=tail)


def main():
    phase = sys.argv[1]
    assert phase in ['start', 'end']
    utc = dt.datetime.now(dt.timezone.utc).isoformat()
    cad, owner, checker = read(R/'cad-state.json'), read(R/'state.json'), read(K/'state.json')
    assert cad['hardware_commit'] == owner['hardware_commit'] == checker['hardware_commit'] == HARDWARE
    ctree = tree(owner['pid'])
    assert ctree[0]['start_ticks'] == owner['start_ticks']
    assert BOOT == owner['host_boot_id']
    assert 'ec-performance-only-support-r6-20261113.service' in ctree[0]['cgroup']
    checker_owner = read(D/'performance-only-20261113/checker-whole-owner-r1.json')
    env = dict(os.environ, XDG_RUNTIME_DIR='/run/user/1008',
               DBUS_SESSION_BUS_ADDRESS='unix:path=/run/user/1008/bus')
    units = ['ec-performance-only-support-r6-20261113.service',
             checker_owner['service'], 'ec-performance-only-shell-observer-r1-20261113.service']
    services = subprocess.check_output(['systemctl', '--user', 'show', *units,
        '--property=Id,ActiveState,SubState,MainPID,ControlGroup,MemoryMax,Nice'], env=env, text=True)
    checker_pid = int(subprocess.check_output(['systemctl', '--user', 'show',
        checker_owner['service'], '--property=MainPID', '--value'], env=env, text=True))
    ktree = tree(checker_pid) if checker_pid else []
    cap = R/'capacity.complete'
    prior_path = (A/'owner-start.json' if phase == 'end' else
                  A.parent/'round195/owner-end.json')
    prior = read(prior_path)
    row = dict(schema='ec-performance-only-round196-owner-observation/1', utc=utc,
        hardware_commit=HARDWARE, source_id=cad['source_id'], exact_service=units[0],
        controller=ctree[0], process_tree=ctree, services=services,
        status=cad['status'], stage=cad['current_stage'],
        stage_wall_seconds=cad.get('stage_wall_seconds'), dut_resources=cad.get('dut_resources'),
        log=log_info(R/(cad['current_stage']+'-attempt-1.log')),
        prior_observation=str(prior_path), prior_observation_sha256=sha(prior_path),
        observation_seconds=(dt.datetime.fromisoformat(utc)-dt.datetime.fromisoformat(prior['utc'])).total_seconds(),
        capacity_complete_exists=cap.exists(), capacity=cap.read_text().strip() if cap.exists() else None,
        postopt_utilization_exists=(R/'top-postopt-utilization.rpt').exists(),
        actual_whole_shell_LUT=None, FIT=None, runtime_certified=False,
        checker_owner=checker_owner, checker_state=checker, checker_process_tree=ktree,
        checker_log=log_info(K/'compile-complete-host.log'),
        no_restart_or_duplicate=True, FPGA_IO=False)
    save(A/f'owner-{phase}.json', row)
    if phase == 'start':
        receipt_path = R/'dut_synth-result.json'
        receipt = read(receipt_path)
        assert receipt['returncode'] == 0 and receipt['hardware_commit'] == HARDWARE
        assert receipt['source_id'] == cad['source_id']
        checks = []
        for path, digest in receipt['outputs'].items():
            actual = sha(path)
            assert actual == digest, path
            checks.append(dict(path=path, sha256=actual, PASS=True))
        manifest_path = D/'performance-only-20261113/normal-path-evidence-preserved-r1/manifest.json'
        manifest = read(manifest_path)
        for entry in manifest['files']:
            for kind in ['original', 'preserved_copy']:
                path = entry[kind]
                actual = sha(path)
                assert actual == entry['sha256'], path
                checks.append(dict(path=path, sha256=actual, PASS=True))
        controller = Path(checker_owner['path'])/'controller.py'
        assert sha(controller) == checker_owner['controller_sha256']
        binding = read(K/'input-binding.json')
        host_path = K/'host/FireSim-generated.sv'
        assert sha(host_path) == binding['source_host_RTL_sha256']
        assert binding['source_host_RTL_sha256'] == cad['inputs']['generated'][str(R/'project/builds/cad-6fada307/design/FireSim-generated.sv')]
        save(A/'new-evidence-authentication.json', dict(
            schema='ec-performance-only-round196-new-evidence-authentication/1', utc=utc,
            hardware_commit=HARDWARE, source_id=cad['source_id'], PASS=True,
            dut_receipt=str(receipt_path), dut_receipt_sha256=sha(receipt_path),
            dut_scope='DUT synthesis only; complete shell postopt capacity remains unproven',
            dut_resources=cad['dut_resources'], checks=checks,
            preserved_manifest=str(manifest_path), preserved_manifest_sha256=sha(manifest_path),
            preserved_original_and_copy_count=len(manifest['files']),
            checker_controller_sha256=sha(controller), checker_input_binding_sha256=sha(K/'input-binding.json'),
            checker_exact_host_RTL_matches_CAD=True, checker_host_RTL_sha256=sha(host_path),
            actual_integrated_checker_execution_passed=False,
            source_RTL_changed=False, simulation_or_CAD_launched=False, FPGA_IO=False))
    print(json.dumps(dict(phase=phase, status=row['status'], stage=row['stage'],
        observation_seconds=row['observation_seconds'], capacity=row['capacity'],
        checker_status=checker['status'], evidence=str(A/f'owner-{phase}.json'))))


if __name__ == '__main__':
    main()
