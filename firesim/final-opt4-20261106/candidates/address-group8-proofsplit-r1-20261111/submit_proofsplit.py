#!/usr/bin/python3
"""Re-audit active Opt4 work and submit the isolated proof-split recovery."""
from pathlib import Path
import datetime as dt
import hashlib
import json
import os
import shutil

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
C = W/'candidates/address-group8-proofsplit-r1-20261111'
TAG = W/'candidates/address-group4-r1-20261111'
F = W/'Opt4-fit-address-group8-r1-20261111'
O = D/'build-logs/Opt4-fit-address-group8-proofsplit-r1-20261111'
NAME = 'address-group8-proofsplit-r1-32837b0b'
REQUEST = U/'requests'/(NAME+'.json')
RESULT = U/'request-results'/(NAME+'.json')
REPORT = U/'rounds/round-00011/group8-proofsplit-request-preflight.json'

def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(1 << 20), b''):
            h.update(block)
    return h.hexdigest()

def read(path):
    return json.loads(Path(path).read_text()) if Path(path).is_file() else {}

def identity(pid):
    try:
        tail = (Path('/proc')/str(pid)/'stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=int(pid), start_ticks=tail[19], process_state=tail[0],
                    host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except (FileNotFoundError, IndexError, ValueError):
        return {}

def recorded_processes(value):
    if isinstance(value, dict):
        if all(key in value for key in ('pid', 'start_ticks', 'host_boot_id')):
            yield value
        for child in value.values():
            yield from recorded_processes(child)
    elif isinstance(value, list):
        for child in value:
            yield from recorded_processes(child)

def live_records(state):
    records = list(recorded_processes(state))
    if isinstance(state, dict):
        boot = state.get('host_boot_id')
        for pid_key, tick_key in (('pid', 'start_ticks'), ('child_pid', 'child_start_ticks'),
                                  ('controller_pid', 'controller_start_ticks')):
            if state.get(pid_key) and state.get(tick_key) and boot:
                records.append(dict(pid=state[pid_key], start_ticks=state[tick_key], host_boot_id=boot))
    live = []
    seen = set()
    for record in records:
        pid = int(record['pid'])
        if pid in seen:
            continue
        seen.add(pid)
        actual = identity(pid)
        if actual and all(str(actual.get(key)) == str(record.get(key))
            for key in ('start_ticks', 'host_boot_id')) and actual['process_state'] not in ('Z', 'X'):
            live.append(actual)
    return live

def save_new(path, value):
    path = Path(path); path.parent.mkdir(parents=True, exist_ok=True)
    data = (json.dumps(value, indent=2, sort_keys=True) + '\n').encode()
    if path.exists():
        assert path.read_bytes() == data, 'immutable conflict: ' + str(path)
        return
    tmp = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with tmp.open('xb') as stream:
        stream.write(data); stream.flush(); os.fsync(stream.fileno())
    os.replace(tmp, path)

def main():
    assert not REQUEST.exists() and not RESULT.exists() and not REPORT.exists()
    cfg = read(C/'config.json'); binding = cfg['binding']; manifest_path = C/'input-hashes.json'
    hashes = read(manifest_path)
    assert binding['hardware_commit'] == '32837b0b1987091eb86e4157ec0c6360f5bde58b'
    assert hashes
    inputs = {path: digest for path, digest in hashes.items()
              if Path(path).resolve().is_relative_to(W)}
    inputs[str(manifest_path)] = sha(manifest_path)
    inputs[str(TAG/'controller.py')] = sha(TAG/'controller.py')
    inputs[str(Path(__file__).resolve())] = sha(__file__)
    assert all(Path(path).resolve().is_relative_to(W) for path in inputs)

    mem_kib = int(next(line.split()[1] for line in Path('/proc/meminfo').read_text().splitlines()
                       if line.startswith('MemAvailable:')))
    disk = shutil.disk_usage(W).free
    assert mem_kib >= 48 * 2**20, 'module memory gate requires 48 GiB'
    assert disk >= 40 * 2**30, 'module disk gate requires 40 GiB'

    jobs = []
    for state_path in sorted((U/'jobs').glob('*/state.json')):
        state = read(state_path); processes = live_records(state)
        if processes:
            jobs.append(dict(name=state_path.parent.name, status=state.get('status'),
                             live_processes=processes))
    assert len(jobs) < 4, 'four new CPU jobs are already live'

    cad_path = D/'Opt4-fit-cad-state.json'; cad = read(cad_path); cad_live = live_records(cad)
    cad_evidence = dict(path=str(cad_path), status=cad.get('status'),
        current_stage=cad.get('current_stage'), live_processes=cad_live)
    if cad.get('status', '').startswith('RUNNING_'):
        controller = live_records(dict(pid=cad.get('pid'), start_ticks=cad.get('start_ticks'),
            host_boot_id=cad.get('host_boot_id')))
        child = live_records(dict(pid=cad.get('child_pid'), start_ticks=cad.get('child_start_ticks'),
            host_boot_id=cad.get('host_boot_id')))
        assert controller and child, 'running CAD controller/child identity mismatch'
        cad_evidence.update(controller_live=controller, child_live=child)

    report = dict(schema='ec-opt4-group8-proofsplit-request-preflight/1',
        created_utc=dt.datetime.now(dt.timezone.utc).isoformat(), status='REQUEST_READY_NOT_STARTED',
        hardware_commit=binding['hardware_commit'], source_id=binding['source_id'],
        input_manifest_sha256=sha(manifest_path), active_cpu_jobs=jobs, whole_cad=cad_evidence,
        available_memory_gib=mem_kib/2**20, free_disk_gib=disk/2**30,
        thresholds=dict(module_memory_gib=48, module_disk_gib=40, max_new_cpu_jobs=4, candidate_threads=8),
        fpga_access=False, full_dut_synthesis=False, formal_admission=False,
        does_not_reuse_failed_state=True)
    save_new(REPORT, report)
    request = dict(action='cpu_job', spec=dict(name=NAME, kind='module', cwd=str(F),
        argv=['/usr/bin/python3', str(C/'controller.py')], inputs=inputs,
        outputs=[str(O/'result.json'), str(O/'verified-local.json')],
        checkpoints=[str(D/'Opt4-fit-address-group8-proofsplit-r1-state.json'), str(O/'verified-local.json')]))
    save_new(REQUEST, request)
    print(json.dumps(dict(status='REQUESTED_NOT_STARTED', request=str(REQUEST),
        request_sha256=sha(REQUEST), report=str(REPORT), live_jobs=len(jobs),
        memory_gib=report['available_memory_gib'], disk_gib=report['free_disk_gib']), sort_keys=True))

if __name__ == '__main__':
    main()
