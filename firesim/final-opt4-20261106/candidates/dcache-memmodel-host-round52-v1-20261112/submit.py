#!/usr/bin/python3
"""Publish at most one four-memory host generation after exact P0 receipts.

--check has no side effects. --submit is still deferred until both existing
producers have passed and exited. It never starts a workload or FPGA flow.
"""
import argparse
import fcntl
import hashlib
import json
import os
from pathlib import Path
import shutil

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
NAME = 'dcache-memmodel-host-r52-v1-3656aec4'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
OUT = D/'build-logs/Opt4-dcache-memmodel-host-round52-v1-20261112'
STATE = D/'Opt4-dcache-memmodel-host-round52-v1-state.json'


def read(path):
    return json.loads(Path(path).read_text())


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for b in iter(lambda: f.read(2**20), b''):
            h.update(b)
    return h.hexdigest()


def write_new(path, value):
    with Path(path).open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())


def prerequisites(plan):
    paths = plan['required_completed_receipts']
    missing = [q for q in paths if not Path(q).is_file()]
    if missing:
        return dict(status='DEFERRED_EXISTING_P0_RECEIPTS', missing=missing)
    gg, pair = map(read, paths)
    assert gg['status'] == 'PASS_COMPLETE_REAL_APPLICATION_GG_STREAM_REPLAY'
    assert gg['passed'] and gg['real_application_payload_mutation_rejected']
    summary = gg['positive']['summary']
    assert gg['positive']['returncode'] == 0
    assert summary['records'] == summary['target_cycles'] == gg['complete_trace_records']
    assert summary['mismatches'] == 0 and summary['input_cache_enabled'] == 0
    assert gg['negative']['mutation_applied'] and gg['negative']['mutation_payload_rejected']
    assert gg['negative']['returncode'] != 0
    assert pair['status'] == 'PASS_SAME_3656_TARGET_CANNEAL_CAPTURED_CYCLES_OUTPUT_EVENTS_NOT_FULL_EQUIVALENCE'
    assert pair['functional_baseline'] == BASE and pair['derived_hardware'] == plan['hardware_commit']
    assert pair['captured_finite_parity_passed']
    assert pair['exact_target_rows'] and pair['exact_target_print_streams']
    assert not gg['fpga_access'] and not pair['fpga_access']
    # Final results are not sufficient while their controllers are still live.
    snapshot = read(U/'snapshot.json')
    for name in ['Opt4-original-svb-gg-stream-replay-r3-state.json',
                 'Opt4-mcrams-owner-pair-runtime-r1-state.json']:
        row = snapshot['states'].get(name)
        if row is None or row.get('identity_live'):
            return dict(status='DEFERRED_PRODUCER_EXIT_SNAPSHOT', producer=name)
    return dict(status='READY_EXACT_P0_CPU_PREREQUISITES',
                receipt_sha256={q: sha(q) for q in paths})


def cpus_from_snapshot():
    # Consult known bound identities only. Never scan /proc or migrate jobs.
    states = read(U/'snapshot.json')['states']
    busy = set()
    boot = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
    for row in states.values():
        if not row.get('identity_live'):
            continue
        rows = [row, row.get('controller', {}), row.get('child', {}),
                row.get('stage_process', {}), *row.get('worker_processes', [])]
        for process in rows:
            pid = process.get('pid')
            if not pid or process.get('host_boot_id') != boot:
                continue
            try:
                stat = Path(f'/proc/{pid}/stat').read_text().rsplit(')', 1)[1].split()
                if stat[19] != str(process.get('start_ticks')) or stat[0] in ['Z', 'X']:
                    continue
                affinity = os.sched_getaffinity(pid)
                # Broad idle controllers do not reserve the entire host.
                if len(affinity) <= 8:
                    busy |= affinity
            except (FileNotFoundError, ProcessLookupError):
                pass
    allowed = set(os.sched_getaffinity(0)) - busy
    # Reserve 254/255 for the existing SVB physical recovery, even while idle.
    for a in [250, 248, 246, 244, 242, 240]:
        if {a, a+1} <= allowed:
            return [a, a+1]
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--submit', action='store_true')
    ap.add_argument('--check', action='store_true')
    args = ap.parse_args()
    assert args.submit != args.check
    p = read(U/'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access'] and not p['functional_extensions_allowed']
    plan = read(C/'plan.json')
    # Any existing four-memory transform owns the singleton. A failed/partial
    # producer must receive a versioned recovery, never a duplicate request.
    existing = sorted((U/'requests').glob('dcache-memmodel-host-*.json'))
    if existing:
        print(json.dumps(dict(status='ADOPT_EXISTING_FOUR_MEMORY_REQUEST', requests=list(map(str, existing)))))
        return
    assert not OUT.exists() and not STATE.exists(), 'Adopt/recover existing stage'
    gate = prerequisites(plan)
    if gate['status'] != 'READY_EXACT_P0_CPU_PREREQUISITES':
        print(json.dumps(gate))
        return
    mem = int(next(s.split()[1] for s in Path('/proc/meminfo').read_text().splitlines()
                   if s.startswith('MemAvailable:')))/2**20
    disk, load = shutil.disk_usage(W).free/2**30, os.getloadavg()[0]
    cpus = cpus_from_snapshot()
    if mem < 128 or disk < 100 or load >= 96 or cpus is None:
        print(json.dumps(dict(status='DEFERRED_UNCHANGED_RESOURCES_OR_CPU_CONFLICT',
                             memory_gib=mem, disk_gib=disk, load=load, cpus=cpus)))
        return
    if args.check:
        print(json.dumps(dict(**gate, cpus=cpus, request_submitted=False)))
        return
    lock = (C/'submit.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not list((U/'requests').glob('dcache-memmodel-host-*.json'))
    assert all(sha(q) == h for q, h in plan['inputs'].items())
    assert all(sha(q) == h for q, h in plan['external_tool_inputs'].items())
    # Hash final immutable prerequisites once at admission. The controller
    # requires these exact bytes again; it cannot accept a later edited PASS.
    bound = C/'prerequisite-bindings.json'
    if bound.exists():
        assert read(bound) == gate
    else:
        write_new(bound, gate)
    inputs = {**plan['inputs'], **{str(q): sha(q) for q in
        [C/'controller.py', C/'submit.py', C/'plan.json', C/'README.md', bound]}}
    assert all(Path(q).resolve().is_relative_to(W) for q in inputs)
    request = dict(action='cpu_job', spec=dict(name=NAME, kind='rtl', cwd=str(C),
        argv=['/usr/bin/python3', str(C/'controller.py'), '--run', '--cpus', ','.join(map(str, cpus))],
        inputs=inputs, outputs=[str(OUT/'result.json'), str(OUT/'complete.json')],
        checkpoints=[str(STATE)]))
    local = C/'request.json'
    if local.exists():
        assert read(local) == request
    else:
        write_new(local, request)
    temp = U/'requests'/('.'+NAME+'.tmp-'+str(os.getpid()))
    write_new(temp, request)
    os.link(temp, U/'requests'/(NAME+'.json'))
    temp.unlink()
    print(json.dumps(dict(status='REQUEST_PUBLISHED_NOT_YET_STARTED', name=NAME, cpus=cpus)))


if __name__ == '__main__':
    main()
