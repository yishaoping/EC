#!/usr/bin/python3
"""Independent host-only continuation, manually broker-admitted after P0/pair PASS."""
import argparse
import datetime
import fcntl
import hashlib
import json
import os
from pathlib import Path
import resource
import shutil
import subprocess
import time

C = Path(__file__).resolve().parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
O = D/'build-logs/Opt4-dcache-memmodel-host-round52-v1-20261112'
S = D/'Opt4-dcache-memmodel-host-round52-v1-state.json'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def save(p, value):
    p = Path(p)
    p.parent.mkdir(parents=True, exist_ok=True)
    q = p.with_name('.' + p.name + '.tmp-' + str(os.getpid()))
    with q.open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    os.replace(q, p)


def identity(pid):
    stat = Path(f'/proc/{pid}/stat').read_text().rsplit(')', 1)[1].split()
    return dict(pid=pid, start_ticks=stat[19], host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())


def policy():
    p = read(U/'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access'] and not p['functional_extensions_allowed']


def prerequisites(plan):
    gg, pair = map(read, plan['required_completed_receipts'])
    assert gg['status'] == 'PASS_COMPLETE_REAL_APPLICATION_GG_STREAM_REPLAY'
    assert gg['passed'] and gg['real_application_payload_mutation_rejected']
    assert pair['status'] == 'PASS_SAME_3656_TARGET_CANNEAL_CAPTURED_CYCLES_OUTPUT_EVENTS_NOT_FULL_EQUIVALENCE'
    assert pair['functional_baseline'] == BASE
    assert pair['derived_hardware'] == plan['hardware_commit']
    bound = read(C/'prerequisite-bindings.json')
    hashes = {p: sha(p) for p in plan['required_completed_receipts']}
    assert bound['receipt_sha256'] == hashes, 'Prerequisite receipt changed after admission'
    return hashes


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--run', action='store_true', required=True)
    ap.add_argument('--cpus', required=True, help='Two nonconflicting CPU IDs selected at broker submission')
    args = ap.parse_args()
    policy()
    plan = read(C/'plan.json')
    if (O/'complete.json').exists():
        assert sha(O/'result.json') == read(O/'complete.json')['result_sha256']
        print('IMMUTABLE_COMPLETE_REVALIDATED')
        return
    required = prerequisites(plan)
    cpus = {int(c) for c in args.cpus.split(',')}
    assert len(cpus) == 2 and cpus <= set(os.sched_getaffinity(0))
    O.mkdir(parents=True, exist_ok=True)
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not S.exists() and not (O/'goldengate.log').exists(), 'Existing/partial stage preserved; use independent recovery'
    assert all(sha(p) == h for p, h in plan['inputs'].items())
    assert all(sha(p) == h for p, h in plan['external_tool_inputs'].items())
    os.sched_setaffinity(0, cpus)
    resource.setrlimit(resource.RLIMIT_AS, (64*2**30, 64*2**30))
    state = dict(schema='ec-four-owner-host-continuation-state/1', **identity(os.getpid()),
        functional_baseline=BASE, hardware_commit=plan['hardware_commit'], source_id=plan['source_id'],
        cpus=sorted(cpus), fpga_access=False, production_admission=False, whole_synthesis=False,
        started_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(), prerequisite_receipts=required)

    def update(**kw):
        state.update(kw, updated_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
        save(S, state)

    try:
        # Preserve the campaign resource floors. Never start Java under a weak margin.
        while True:
            policy()
            mem = int(next(line.split()[1] for line in Path('/proc/meminfo').read_text().splitlines() if line.startswith('MemAvailable:')))/2**20
            disk = shutil.disk_usage(O).free/2**30
            if mem >= 128 and disk >= 100 and os.getloadavg()[0] < 96:
                break
            update(status='WAITING_RESOURCE_GUARD', available_memory_gib=mem, free_disk_gib=disk)
            time.sleep(300)
        cfg = read(plan['config'])
        out = O/'goldengate'
        out.mkdir()
        argv = [cfg['java'], '-Xmx40G', '-Xss8M', '-XX:ActiveProcessorCount=2', '-Dec.dac.firesim=true',
            '-cp', ':'.join(cfg['classpath']), 'midas.stage.GoldenGateMain', '-i', plan['target_fir'],
            '-td', str(out), '-faf', str(C/'four-owner-memories.anno.json'), '-ggcp', 'firesim.configs',
            '-ggcs', 'MCRams_DacXilinxAlveoConfig', '--output-filename-base', 'FireSim-generated', '--no-dedup']
        log = O/'goldengate.log'
        started = time.monotonic()
        with log.open('xb', buffering=0) as f:
            child = subprocess.Popen(argv, cwd=C, stdin=subprocess.DEVNULL, stdout=f, stderr=subprocess.STDOUT,
                env={**os.environ, 'LD_LIBRARY_PATH': '', 'OMP_NUM_THREADS': '2'})
            update(status='RUNNING_FOUR_MEMORY_GOLDENGATE', child=identity(child.pid), argv=argv, stage_log=str(log))
            while child.poll() is None:
                try:
                    child.wait(timeout=30)
                except subprocess.TimeoutExpired:
                    pass
                update(host_wall_seconds=time.monotonic()-started)
                os.fsync(f.fileno())
        raw_sv = out/'FireSim-generated.sv'
        prehost = out/'post-bridge-extraction.fir'
        header = out/'FireSim-generated.const.h'
        receipt = dict(returncode=child.returncode, argv=argv, log_sha256=sha(log),
            outputs={str(p): sha(p) for p in [raw_sv, prehost, header] if p.exists()}, host_wall_seconds=time.monotonic()-started)
        save(O/'goldengate-receipt.json', receipt)
        update(child={})
        assert child.returncode == 0 and len(receipt['outputs']) == 3
        assert sha(prehost) == plan['complete_prehost_target_sha256'], 'Complete pre-host target changed'
        assert sha(plan['target_fir']) == plan['inputs'][plan['target_fir']]
        # Keep raw GoldenGate SV immutable. Assemble the blackbox suffix into a
        # separate file, recording prefix/suffix hashes for exact later audits.
        files = out/'firrtl_black_box_resource_files.f'
        paths = [Path(p.strip()) for p in files.read_text().splitlines() if p.strip()] if files.exists() else []
        paths = [p if p.is_absolute() else out/p for p in paths]
        assembled = out/'FireSim-with-blackboxes.sv'
        prefix = raw_sv.stat().st_size
        with assembled.open('xb') as f:
            with raw_sv.open('rb') as src:
                shutil.copyfileobj(src, f)
            for p in paths:
                with p.open('rb') as src:
                    shutil.copyfileobj(src, f)
            f.flush()
            os.fsync(f.fileno())
        save(O/'assembly.json', dict(raw_sv=str(raw_sv), raw_sha256=sha(raw_sv), raw_prefix_bytes=prefix,
            ordered_suffix=[dict(path=str(p), sha256=sha(p), bytes=p.stat().st_size) for p in paths],
            final_sv=str(assembled), final_sha256=sha(assembled)))
        update(status='HOST_GENERATED_FOUR_MEMORY_TARGET_UNCHANGED_PARITY_AND_AREA_REQUIRED',
            host_rtl=str(assembled), host_rtl_sha256=sha(assembled), target_function_changed=False,
            generation_read_ports=518, whole_fit=False, full_host_parity_passed=False)
        save(O/'result.json', state)
        save(O/'complete.json', dict(result_sha256=sha(O/'result.json')))
    except Exception as exc:
        update(status='FAILED_WITH_EVIDENCE', error=repr(exc))
        save(O/'failure.json', state)
        raise


if __name__ == '__main__':
    main()
