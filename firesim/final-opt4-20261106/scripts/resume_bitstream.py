#!/usr/bin/env python3
"""Resume the exact interrupted final C4 project using completed IP checkpoints."""
import datetime as dt
import fcntl
import hashlib
import json
import os
from pathlib import Path
import shutil
import signal
import subprocess
import sys
import time

from board_batch import W, D, save, sha
sys.path.insert(0, '/data1/gzh/EC/firesim/dac2026/scripts')
from build_minimal import inventory


def main():
    lock = (D/'.final-runtime-cad.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    path = D/'C4-runtime-cad-state.json'
    state = json.loads(path.read_text())
    boot = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
    assert state['status'] == 'INTERRUPTED', state['status']
    assert state['source_id'] == 'c9f51d3a94aac7783c750682162cd25e9d1460b04974bde9b7541f1d9f4120e7'
    assert state['hardware_commit'] == '8491167d84b6d9521b151a743673c1516926a1f8'
    cy = Path(state['source_tree'])
    inv = inventory(cy)
    assert hashlib.sha256(json.dumps(inv, sort_keys=True).encode()).hexdigest() == state['source_id']
    for p, h in {**state['inputs'], **state['effective_cad_inputs']}.items():
        assert sha(p) == h, p
    out = Path(state['output_dir'])
    assert (out/'vivado_proj/firesim.xpr').is_file()
    disk = shutil.disk_usage(out)
    assert disk.free >= 80*2**30 and shutil.disk_usage(D).free >= 20*2**30
    memory = {l.split(':')[0]: int(l.split()[1]) for l in Path('/proc/meminfo').read_text().splitlines()}
    assert memory['MemAvailable'] >= 32*2**20
    # A complete run marker plus its DCP is reusable; the interrupted DUT run
    # has no checkpoint and must repeat synthesis, while sibling IPs are kept.
    checkpoints = {}
    for marker in sorted((out/'vivado_proj/firesim.runs').glob('*/.vivado.end.rst')):
        for dcp in marker.parent.glob('*.dcp'):
            checkpoints[str(dcp)] = sha(dcp)
    assert checkpoints, 'no complete checkpoints available for reuse'
    stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    logs = D/'build-logs'/('C4-resume-'+stamp)
    logs.mkdir()
    save(logs/'interrupted-state.json', state)
    shutil.copy2(out/'vivado_proj/firesim.xpr', logs/'interrupted-project.xpr')
    for run in sorted((out/'vivado_proj/firesim.runs').iterdir()):
        if not run.is_dir() or (run/'.vivado.end.rst').exists():
            continue
        for p in run.iterdir():
            if p.is_file() and (p.suffix in ['.log', '.tcl', '.rst'] or p.name == 'runme.sh'):
                saved = logs/'interrupted-runs'/run.name/p.name
                saved.parent.mkdir(parents=True, exist_ok=True)
                shutil.copy2(p, saved)
    tcl = W/'scripts/resume_cad.tcl'
    shutil.copy2(tcl, logs/'resume_cad.tcl')
    checks = dict(completed_checkpoint_count=len(checkpoints), completed_checkpoints=checkpoints,
                  source_id=state['source_id'], effective_inputs_unchanged=True,
                  no_new_elaboration=True, no_new_goldengate=True, no_new_driver=True,
                  reuse_original_project=True, missing_DUT_checkpoint_requires_synthesis=True)
    save(logs/'reuse.json', checks)
    history = state.setdefault('resume_history', [])
    history.append(dict(prior_log_dir=state['log_dir'], prior_pid=state.get('pid'),
                        prior_child_pid=state.get('child_pid'), resumed_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
                        current_host_boot_id=boot, reused_checkpoint_count=len(checkpoints), log_dir=str(logs)))
    # The saved project and completed runs belong to guozh. Run the CAD tool
    # under that identity; keep the root supervisor for durable job bookkeeping.
    argv = ['runuser', '-u', 'guozh', '--', 'nice', '-n', '15', '/tools/Xilinx/Vivado/2021.1/bin/vivado', '-mode', 'batch',
            '-nojournal', '-log', str(logs/'vivado.log'), '-source', str(logs/'resume_cad.tcl'),
            '-tclargs', str(out), 'resume']
    state.update(status='STARTING', pid=os.getpid(), host_boot_id=boot,
                 start_ticks=Path('/proc/self/stat').read_text().split()[21],
                 argv=argv, log_dir=str(logs), returncode=None, certified_bitstream=False,
                 resumed_from_project=True, reused_checkpoint_count=len(checkpoints),
                 script_sha256=sha(__file__))
    state.pop('ended_utc', None)
    state.pop('error', None)
    save(path, state)
    child = None
    stopped = None

    def stop(sig, frame):
        nonlocal stopped
        stopped = 'INTERRUPTED'
        if child and child.poll() is None:
            os.killpg(child.pid, signal.SIGTERM)
    signal.signal(signal.SIGINT, stop)
    signal.signal(signal.SIGTERM, stop)
    start = time.monotonic()
    prior_elapsed = state.get('elapsed_seconds', 0)
    env = {**os.environ, 'OMP_NUM_THREADS': '2', 'MAKEFLAGS': '-j1', 'TMPDIR': str(out/'tmp')}
    with (logs/'build.log').open('wb', buffering=0) as stream:
        child = subprocess.Popen(argv, cwd=out, env=env, stdin=subprocess.DEVNULL,
                                 stdout=stream, stderr=subprocess.STDOUT, start_new_session=True)
        state.update(status='RUNNING', child_pid=child.pid, child_pgid=child.pid,
                     child_start_ticks=Path(f'/proc/{child.pid}/stat').read_text().split()[21])
        save(path, state)
        print(json.dumps(dict(pid=child.pid, log_dir=str(logs), reused_checkpoints=len(checkpoints))), flush=True)
        while child.poll() is None:
            try:
                child.wait(timeout=30)
            except subprocess.TimeoutExpired:
                pass
            free = shutil.disk_usage(out).free
            state.update(elapsed_seconds=prior_elapsed + time.monotonic()-start,
                         resume_elapsed_seconds=time.monotonic()-start, disk_free_gib=free/2**30,
                         updated_utc=dt.datetime.now(dt.timezone.utc).isoformat())
            save(path, state)
            if child.poll() is None and (free < 60*2**30 or disk.free-free > 120*2**30 or time.monotonic()-start > 24*3600):
                stopped = 'RESOURCE_LIMIT_OR_TIMEOUT'
                os.killpg(child.pid, signal.SIGTERM)
                try:
                    child.wait(timeout=30)
                except subprocess.TimeoutExpired:
                    os.killpg(child.pid, signal.SIGKILL)
                    child.wait()
    rc = child.returncode
    bit = out/'vivado_proj/firesim.bit'
    if rc == 0:
        if not bit.is_file() or not bit.stat().st_size:
            rc = 1
        elif inventory(cy) != inv:
            rc, stopped = 1, 'SOURCE_CHANGED'
        elif any(sha(p) != h for p, h in {**state['inputs'], **state['effective_cad_inputs'], **checkpoints}.items()):
            rc, stopped = 1, 'CAD_INPUT_CHANGED'
    state.update(returncode=rc, status=stopped or ('BUILT_NOT_RUN' if rc == 0 else 'FAILED'),
                 certified_bitstream=rc == 0 and stopped is None,
                 ended_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
                 outputs={str(bit): sha(bit)} if bit.exists() else {})
    if state['certified_bitstream']:
        destination = W/'images'/('C4-resumed-'+stamp)
        destination.mkdir()
        shutil.copy2(bit, destination/'firesim.bit')
        assert sha(destination/'firesim.bit') == state['outputs'][str(bit)]
        state.update(durable_bitstream=str(destination/'firesim.bit'),
                     durable_bitstream_sha256=sha(destination/'firesim.bit'))
        save(destination/'result.json', state)
        save(W/'bitstream-runtime-build.json', state)
    save(logs/'result.json', state)
    save(path, state)
    print(json.dumps(dict(status=state['status'], returncode=rc)), flush=True)
    return rc or (1 if stopped else 0)


if __name__ == '__main__':
    raise SystemExit(main())
