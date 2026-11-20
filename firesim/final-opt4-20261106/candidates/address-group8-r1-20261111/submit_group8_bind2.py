#!/usr/bin/python3
"""Audit live Opt4 jobs and atomically submit the fully bound group8 map job."""
from pathlib import Path
import datetime as dt
import hashlib
import json
import os
import shutil
import subprocess

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
C = W/'candidates/address-group8-r1-20261111'
T = W/'candidates/address-group4-r1-20261111'
F = W/'Opt4-fit-address-group8-r1-20261111'
O = D/'build-logs/Opt4-fit-address-group8-r1-20261111'
NAME = 'address-group8-r1-bind2-32837b0b'
REQUEST = U/'requests'/(NAME+'.json')
RESULT = U/'request-results'/(NAME+'.json')
REPORT = U/'rounds/round-00011/group8-request-preflight.json'

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

def flat_processes(state):
    if not isinstance(state, dict):
        return
    boot = state.get('host_boot_id')
    if state.get('pid') and state.get('start_ticks') and boot:
        yield dict(pid=state['pid'], start_ticks=state['start_ticks'], host_boot_id=boot)
    if state.get('child_pid') and state.get('child_start_ticks') and boot:
        yield dict(pid=state['child_pid'], start_ticks=state['child_start_ticks'], host_boot_id=boot)
    if state.get('controller_pid') and state.get('controller_start_ticks') and boot:
        yield dict(pid=state['controller_pid'], start_ticks=state['controller_start_ticks'], host_boot_id=boot)

def live_records(state):
    live = []
    seen = set()
    for recorded in list(recorded_processes(state)) + list(flat_processes(state)):
        pid = int(recorded['pid'])
        if pid in seen:
            continue
        seen.add(pid)
        actual = identity(pid)
        same = bool(actual and all(str(actual.get(key)) == str(recorded.get(key))
            for key in ('start_ticks', 'host_boot_id')) and actual['process_state'] not in ('Z', 'X'))
        if same:
            live.append(actual)
    return live

def save_new(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    data = (json.dumps(value, indent=2, sort_keys=True) + '\n').encode()
    if path.exists():
        assert path.read_bytes() == data, 'immutable conflict: ' + str(path)
        return
    tmp = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with tmp.open('xb') as stream:
        stream.write(data); stream.flush(); os.fsync(stream.fileno())
    os.replace(tmp, path)

def main():
    assert not REQUEST.exists() and not RESULT.exists(), 'request name already used; choose a new version'
    assert not REPORT.exists(), 'preflight evidence already exists; preserve it and use a new version'
    config = read(C/'config.json')
    binding = config['binding']
    assert binding['hardware_commit'] == '32837b0b1987091eb86e4157ec0c6360f5bde58b'
    assert binding['frozen_commit'] == '8491167d84b6d9521b151a743673c1516926a1f8'
    manifest_path = C/'input-hashes.json'
    hashes = read(manifest_path)
    assert hashes and sha(manifest_path)
    for path, digest in hashes.items():
        if Path(path).resolve().is_relative_to(W):
            assert len(digest) == 64
    helper = T/'controller.py'
    helper_hash = sha(helper)
    script_hash = sha(__file__)
    inputs = {path: digest for path, digest in hashes.items()
              if Path(path).resolve().is_relative_to(W)}
    inputs[str(manifest_path)] = sha(manifest_path)
    inputs[str(helper)] = helper_hash
    inputs[str(Path(__file__).resolve())] = script_hash
    assert all(Path(path).resolve().is_relative_to(W) for path in inputs)

    mem_kib = int(next(line.split()[1] for line in Path('/proc/meminfo').read_text().splitlines()
                       if line.startswith('MemAvailable:')))
    disk = shutil.disk_usage(W).free
    assert mem_kib >= 48 * 2**20, 'module memory gate requires 48 GiB'
    assert disk >= 40 * 2**30, 'module disk gate requires 40 GiB'

    jobs = []
    for state_path in sorted((U/'jobs').glob('*/state.json')):
        state = read(state_path)
        processes = live_records(state)
        if processes:
            jobs.append(dict(name=state_path.parent.name, status=state.get('status'),
                             live_processes=processes))
    assert len(jobs) < 4, 'four new CPU jobs already live; do not submit another'

    cad_path = D/'Opt4-fit-cad-state.json'
    cad = read(cad_path)
    cad_live = live_records(cad)
    cad_evidence = dict(path=str(cad_path), status=cad.get('status'),
                        current_stage=cad.get('current_stage'), live_processes=cad_live)
    if cad.get('status', '').startswith('RUNNING_'):
        controller_record = cad.get('controller') or dict(pid=cad.get('pid'),
            start_ticks=cad.get('start_ticks'), host_boot_id=cad.get('host_boot_id'))
        child_record = cad.get('child') or dict(pid=cad.get('child_pid'),
            start_ticks=cad.get('child_start_ticks'), host_boot_id=cad.get('host_boot_id'))
        controller_live = live_records(controller_record)
        child_live = live_records(child_record)
        assert controller_live and child_live and cad_live, (
            'CAD state says running but controller/child identities are not both live')
        cad_evidence['controller_live'] = controller_live
        cad_evidence['child_live'] = child_live

    report = dict(schema='ec-opt4-group8-request-preflight/1',
        created_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
        status='REQUEST_READY_NOT_STARTED', hardware_commit=binding['hardware_commit'],
        source_id=binding['source_id'], input_manifest_sha256=sha(manifest_path),
        supplemental_test_helper=str(helper), supplemental_test_helper_sha256=helper_hash,
        submit_script=str(Path(__file__).resolve()), submit_script_sha256=script_hash,
        active_cpu_jobs=jobs, whole_cad=cad_evidence,
        available_memory_gib=mem_kib/2**20, free_disk_gib=disk/2**30,
        thresholds=dict(module_memory_gib=48, module_disk_gib=40,
                        max_new_cpu_jobs=4, candidate_threads=8),
        fpga_access=False, full_dut_synthesis=False, formal_admission=False)
    save_new(REPORT, report)

    request = dict(action='cpu_job', spec=dict(name=NAME, kind='module', cwd=str(F),
        argv=['/usr/bin/python3', str(C/'controller.py')], inputs=inputs,
        outputs=[str(O/'result.json'), str(O/'verified-local.json')],
        checkpoints=[str(D/'Opt4-fit-address-group8-r1-state.json'), str(O/'verified-local.json')]))
    save_new(REQUEST, request)
    print(json.dumps(dict(status='REQUESTED_NOT_STARTED', request=str(REQUEST),
        request_sha256=sha(REQUEST), preflight_report=str(REPORT), live_jobs=len(jobs),
        memory_gib=report['available_memory_gib'], disk_gib=report['free_disk_gib']), sort_keys=True))

if __name__ == '__main__':
    main()
