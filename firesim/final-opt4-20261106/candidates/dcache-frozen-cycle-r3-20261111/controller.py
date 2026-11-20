#!/usr/bin/python3
"""Brokered complete frozen-DCache cycle regression; no whole CAD or FPGA I/O."""
from pathlib import Path
import datetime
import fcntl
import json
import os
import shutil
import subprocess
import time
from prepare import COMMIT, SID, FROZEN, D, C, sha, read, policy, generate

O = D / 'build-logs/Opt4-fit-dcache-frozen-cycle-r3-20261111'
S = D / 'Opt4-fit-dcache-frozen-cycle-r3-state.json'


def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def ident(pid):
    try:
        fields = Path(f'/proc/{pid}/stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, start_ticks=fields[19], process_state=fields[0],
                    host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError:
        return {}


def save(path, value):
    path = Path(path)
    temporary = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with temporary.open('w') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())
    os.replace(temporary, path)


def main():
    policy()
    O.mkdir(exist_ok=True)
    lock = (O / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not S.exists(), 'preserve partial stages; use a new reviewed recovery'
    state = dict(schema='ec-opt4-complete-frozen-dcache-cycle/1', **ident(os.getpid()),
                 hardware_commit=COMMIT, source_id=SID, functional_baseline_commit=FROZEN,
                 status='PREPARING', started_utc=now(), stages={}, fpga_access=False,
                 complete_dcache_cycles_verified=False, full_dut_formal=False, whole_admission=False)

    def update(**kw):
        state.update(kw); state['updated_utc'] = now(); save(S, state)

    update()
    while not (C / 'prepared/preparation.json').is_file():
        policy()
        preparation_state = D / 'Opt4-fit-dcache-frozen-cycle-prep-r3-state.json'
        prior = read(preparation_state) if preparation_state.is_file() else {}
        assert prior.get('status') != 'FAILED_WITH_EVIDENCE', 'preserve preparation failure'
        update(status='WAITING_AUTHENTICATED_COMPLETE_MODULE_PREPARATION')
        time.sleep(300)
    prep = read(C / 'prepared/preparation.json')
    assert prep['hardware_commit'] == COMMIT and prep['source_id'] == SID
    assert all(sha(p) == h for p, h in read(C / 'input-hashes.json').items())
    for label, row in prep['authenticated_rtl'].items():
        assert sha(row['closure']) == row['closure_sha256']
    assert sha(C / 'prepared/pair.sv') == prep['pair_sha256']
    update(preparation=prep, status='WAITING_MODULE_MEMORY_DISK_GATE')
    while True:
        policy()
        available = int(next(line.split()[1] for line in Path('/proc/meminfo').read_text().splitlines()
                             if line.startswith('MemAvailable:')))
        if available >= 48 * 2**20 and shutil.disk_usage(C).free >= 40 * 2**30:
            break
        time.sleep(300)
    env = {**os.environ, 'LD_LIBRARY_PATH': '', 'CCACHE_DISABLE': '1',
           'OMP_NUM_THREADS': '2', 'MAKEFLAGS': '-j2', 'TMPDIR': str(O)}

    def run(name, argv):
        policy()
        log = O / (name + '-attempt-1.log')
        with log.open('xb', buffering=0) as f:
            child = subprocess.Popen(argv, cwd=O, env=env, stdin=subprocess.DEVNULL,
                                     stdout=f, stderr=subprocess.STDOUT)
            update(status='RUNNING_' + name.upper(), child=ident(child.pid), stage_log=str(log))
            while child.poll() is None:
                try:
                    child.wait(timeout=30)
                except subprocess.TimeoutExpired:
                    pass
                os.fsync(f.fileno()); update()
        row = dict(argv=argv, returncode=child.returncode, log=str(log), log_sha256=sha(log), ended_utc=now())
        state['stages'][name] = row; update(child={})
        assert child.returncode == 0, (name, child.returncode, str(log))
        return log

    prepared = C / 'prepared'
    exe = O / 'obj/VDCacheCyclePair'
    run('compile', ['nice', '-n', '15', '/usr/local/bin/verilator', '--cc', '--exe', '--build',
        '-j', '2', '--top-module', 'DCacheCyclePair', '--Mdir', str(O / 'obj'),
        '--output-split', '10000', '--output-split-cfuncs', '200', '-Wno-fatal',
        '--x-initial', '0', '--x-assign', '0', '-DRANDOMIZE_REG_INIT', '-DRANDOMIZE_MEM_INIT',
        "-DRANDOM=32'h0", '-DSTOP_COND=1', '-DPRINTF_COND=1',
        '-CFLAGS', '-O0 -I' + str(prepared), '-MAKEFLAGS', 'OPT_FAST=-O0 OPT_SLOW=-O0',
        str(prepared / 'frozen.sv'), str(prepared / 'candidate.sv'), str(prepared / 'pair.sv'),
        str(C / 'stimulus.cpp')])
    assert exe.is_file()
    log = run('comparison', ['nice', '-n', '15', str(exe)])
    assert 'COMPLETE_FROZEN_DCACHE_CYCLE_PASS cycles=8192' in log.read_text()
    update(status='PASS_COMPLETE_FROZEN_DCACHE_8192_CYCLE_OBSERVATION_REGRESSION_NOT_FULL_FORMAL_NOT_WHOLE_ADMITTED',
           complete_dcache_cycles_verified=True, ended_utc=now(), executable_sha256=sha(exe))
    save(O / 'result.json', state)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if S.exists():
            state = read(S)
            if state.get('pid') == os.getpid():
                state.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=now())
                save(S, state)
        raise
