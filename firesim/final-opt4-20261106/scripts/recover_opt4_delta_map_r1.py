#!/usr/bin/python3
"""Bounded module-map recovery for the Vivado cross-boundary allocation failure."""
from pathlib import Path
import datetime as dt
import fcntl
import hashlib
import json
import os
import shutil
import subprocess
import sys
import time

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
C = W / 'candidates/address-delta-r3-20261111'
F = W / 'Opt4-fit-address-delta-r3-20261111/chipyard'
BASE = D / 'build-logs/Opt4-fit-address-delta-r3-56711a00-20261111'
O = BASE / 'map-recovery-r1'
INPUTS = BASE / 'map-recovery-r1-input-hashes.json'
STATE = D / 'Opt4-fit-address-delta-map-recovery-r1-state.json'
JOB = U / 'jobs/address-delta-map-recovery-r1-e5f32750'


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def read(path):
    return json.loads(Path(path).read_text())


def save(path, value):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    temp = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with temp.open('w') as stream:
        json.dump(value, stream, indent=2, sort_keys=True)
        stream.write('\n')
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(temp, path)


def identity(pid):
    try:
        fields = (Path('/proc') / str(pid) / 'stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=int(pid), start_ticks=fields[19],
                    host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
                    process_state=fields[0])
    except (FileNotFoundError, ProcessLookupError, PermissionError):
        return {}


def is_same_live_process(record):
    current = identity(record.get('pid', 0))
    return bool(current and current.get('start_ticks') == str(record.get('start_ticks'))
                and current.get('host_boot_id') == record.get('host_boot_id')
                and current.get('process_state') not in ('Z', 'X'))


def preflight():
    expected = read(INPUTS)
    for path, digest in expected.items():
        assert sha(path) == digest, f'input changed: {path}'

    binding = read(C / 'candidate-binding.json')
    inventory = read(C / 'source-inventory.json')
    proof = read(BASE / 'verified-local.json')
    commit = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=F, text=True).strip()
    assert commit == binding['hardware_commit']
    assert hashlib.sha256(json.dumps(inventory, sort_keys=True).encode()).hexdigest() == binding['source_id']
    for rel in ('chipyard/generators/boom/src/main/scala/lsu/PackageAddressStats.scala',
                'chipyard/generators/boom/src/main/scala/lsu/AddressBucketAccess.scala',
                'chipyard/generators/boom/src/main/scala/lsu/AddressBucketReduction.scala'):
        assert (F / rel).read_bytes() == subprocess.check_output(
            ['git', 'show', binding['hardware_commit'] + ':' + rel], cwd=F)
    assert binding['hardware_commit'] == '56711a0057bb2822f5bf00754a2b3e13cde11e8f'
    assert binding['source_id'] == proof['source_id'] == 'e5f327505b504fa55c75b29500a915d2f32db6e28766f9444c62e3989a384ada'
    assert proof['full_dut_formal'] is False
    assert proof['actual_size_boundary'] == 'PASS_4096_VECTORS_ALL_256_SLOTS_64BIT_OVERFLOW_RESET'
    assert proof['full_module_regression'] == 'PASS_6144_CYCLES_52_OUTPUTS_NOT_FORMAL'
    assert sha(BASE / 'address/PackageAddressStats.v') == proof['rtl_sha256']

    failed = read(BASE / 'map-full-module/map-full-module-result.json')
    failed_state = read(JOB / 'state.json')
    failure_log = Path(failed['log']).read_text(errors='replace')
    assert failed['hardware_commit'] == binding['hardware_commit']
    assert failed['source_id'] == binding['source_id']
    assert failed['returncode'] == 7 and not failed['accepted_result']
    assert failed['missing_outputs'] and not failed['outputs']
    assert 'tcmalloc: large alloc' in failure_log
    assert 'out of memory allocating 184467440736077' in failure_log
    assert failed_state['status'] == 'FAILED_WITH_EVIDENCE'
    for record in (failed_state, failed, failed_state.get('child') or {}):
        assert not is_same_live_process(record), 'old controller/child is still live; adopt it'

    mem_kib = int(next(line.split()[1] for line in Path('/proc/meminfo').read_text().splitlines()
                       if line.startswith('MemAvailable:')))
    free_bytes = shutil.disk_usage(W).free
    assert mem_kib >= 48 * 1024 * 1024, 'module memory gate below 48 GiB'
    assert free_bytes >= 40 * 1024**3, 'module disk gate below 40 GiB'
    return binding, proof, failed


def parse_utilization(path):
    resources = {}
    for line in Path(path).read_text().splitlines():
        fields = [part.strip() for part in line.split('|')]
        if len(fields) > 2 and fields[1] in (
                'CLB LUTs*', 'CLB Registers', 'CARRY8', 'Block RAM Tile', 'DSPs'):
            resources[fields[1].rstrip('*')] = float(fields[2].replace(',', ''))
    required = {'CLB LUTs', 'CLB Registers', 'CARRY8', 'Block RAM Tile', 'DSPs'}
    assert required <= resources.keys(), f'incomplete utilization report: {resources}'
    return resources


def main():
    binding, proof, failed = preflight()
    if '--preflight-only' in sys.argv:
        print('PREFLIGHT_PASS no CAD launched; prior map dead and no checkpoint to resume')
        return

    O.mkdir(parents=True, exist_ok=True)
    lock = (O / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    state = dict(schema='ec-opt4-map-recovery/1', status='PREPARING',
                 hardware_commit=binding['hardware_commit'], source_id=binding['source_id'],
                 failed_attempt=str(failed['log']), prior_failure='VIVADO_INTERNAL_OVERSIZED_ALLOCATION',
                 recovery_recipe='AreaOptimized_high with flatten_hierarchy=none',
                 proof_scope=proof['local_formal'], full_module_regression=proof['full_module_regression'],
                 full_dut_synthesis=False, fpga_access=False, started_utc=dt.datetime.now(dt.timezone.utc).isoformat())
    save(STATE, state)

    rtl = BASE / 'address/PackageAddressStats.v'
    report = O / 'utilization.rpt'
    hierarchy = O / 'hierarchical.rpt'
    checkpoint = O / 'module.dcp'
    tcl = O / 'map.tcl'
    tcl_text = (
        'set_param general.maxThreads 4\n'
        f'read_verilog {{{rtl}}}\n'
        'synth_design -top PackageAddressStats -part xcu280-fsvh2892-2L-e '
        '-mode out_of_context -flatten_hierarchy none -directive AreaOptimized_high\n'
        f'report_utilization -file {{{report}}}\n'
        f'report_utilization -hierarchical -file {{{hierarchy}}}\n'
        f'write_checkpoint -force {{{checkpoint}}}\n'
        'exit 0\n')
    if tcl.exists():
        assert tcl.read_text() == tcl_text, 'recovery Tcl changed; use a new version'
    else:
        tcl.write_text(tcl_text)

    while True:
        mem_kib = int(next(line.split()[1] for line in Path('/proc/meminfo').read_text().splitlines()
                           if line.startswith('MemAvailable:')))
        if mem_kib >= 48 * 1024 * 1024 and shutil.disk_usage(W).free >= 40 * 1024**3:
            break
        state.update(status='WAITING_RESOURCE_GATE', updated_utc=dt.datetime.now(dt.timezone.utc).isoformat())
        save(STATE, state)
        time.sleep(30)

    log = O / 'vivado.log'
    attempt = O / 'map-attempt-1.log'
    assert not attempt.exists(), 'incomplete recovery attempt exists; preserve and audit it'
    argv = ['nice', '-n', '10', '/tools/Xilinx/Vivado/2021.1/bin/vivado',
            '-mode', 'batch', '-nojournal', '-log', str(log), '-source', str(tcl)]
    env = {**os.environ, 'LD_LIBRARY_PATH': '', 'OMP_NUM_THREADS': '4'}
    with attempt.open('xb', buffering=0) as stream:
        proc = subprocess.Popen(argv, cwd=O, env=env, stdin=subprocess.DEVNULL,
                                stdout=stream, stderr=subprocess.STDOUT)
        child = identity(proc.pid)
        state.update(status='RUNNING_ALTERNATE_OOC_MAP', child=child, argv=argv,
                     pid=os.getpid(), started_child_utc=dt.datetime.now(dt.timezone.utc).isoformat())
        save(STATE, state)
        while proc.poll() is None:
            try:
                proc.wait(timeout=30)
            except subprocess.TimeoutExpired:
                pass
            state['updated_utc'] = dt.datetime.now(dt.timezone.utc).isoformat()
            save(STATE, state)
            os.fsync(stream.fileno())

    receipt = dict(schema='ec-opt4-map-recovery-result/1', hardware_commit=binding['hardware_commit'],
                   source_id=binding['source_id'], rtl_sha256=sha(rtl), tcl_sha256=sha(tcl),
                   returncode=proc.returncode, log=str(attempt), vivado_log=str(log),
                   report=str(report), checkpoint=str(checkpoint), scope='OOC module map only; not whole-DUT FIT',
                   full_dut_synthesis=False, fpga_access=False)
    assert proc.returncode == 0, f'Vivado recovery failed; preserve output at {attempt}'
    assert report.is_file() and checkpoint.is_file() and hierarchy.is_file()
    receipt['resources'] = parse_utilization(report)
    receipt['report_sha256'] = sha(report)
    receipt['hierarchical_report_sha256'] = sha(hierarchy)
    receipt['checkpoint_sha256'] = sha(checkpoint)
    save(O / 'result.json', receipt)
    state.update(status='RECOVERED_MODULE_MAP_ONLY', full_module_map=receipt,
                 ended_utc=dt.datetime.now(dt.timezone.utc).isoformat(), child={})
    save(STATE, state)


if __name__ == '__main__':
    try:
        main()
    except Exception as error:
        old = {}
        try:
            old = read(STATE)
        except (FileNotFoundError, json.JSONDecodeError):
            pass
        if old:
            old.update(status='FAILED_WITH_EVIDENCE', error=repr(error),
                       ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
            save(STATE, old)
        raise
