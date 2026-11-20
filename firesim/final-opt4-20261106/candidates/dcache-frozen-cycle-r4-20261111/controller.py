#!/usr/bin/python3
"""Resume exact generated model with corrected C++ port names and VlWide API.

No RTL regeneration or mutation; retain failed r3 and its generated sources.
"""
from pathlib import Path
import datetime
import fcntl
import hashlib
import json
import os
import shutil
import subprocess

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
O = D / 'build-logs/Opt4-fit-dcache-frozen-cycle-r4-20261111'
S = D / 'Opt4-fit-dcache-frozen-cycle-r4-state.json'
OLD = D / 'build-logs/Opt4-fit-dcache-frozen-cycle-r3-20261111/obj'
FROZEN = '8491167d84b6d9521b151a743673c1516926a1f8'
COMMIT = 'd9d732622601ed792a2647546006b5aae986ab8e'
SID = '1639f464d8675806abb5d7dd04adc5dfd1fcf0e351e016ef6a20adcbea1b6e4e'


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def ident(pid):
    try:
        s = Path(f'/proc/{pid}/stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, start_ticks=s[19], process_state=s[0],
                    host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError:
        return {}


def save(p, j):
    p = Path(p)
    tmp = p.with_name(p.name + '.tmp-' + str(os.getpid()))
    with tmp.open('w') as f:
        json.dump(j, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())
    os.replace(tmp, p)


def policy():
    p = read(D / 'unattended-opt4/campaign-policy.json')
    assert p['functional_baseline_commit'] == FROZEN
    assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
    assert p['native_paused'] and not p['fpga_access']


def main():
    policy()
    O.mkdir(exist_ok=True)
    lock = (O / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not S.exists(), 'preserve prior output; use versioned recovery'
    manifest = read(C / 'input-hashes.json')
    assert all(sha(p) == h for p, h in manifest.items())
    for filename in ['prior-domain.json', 'prior-broker.json']:
        prior = read(C / 'evidence' / filename)
        assert prior['status'] == 'FAILED_WITH_EVIDENCE'
        for old in [prior, prior.get('child', {})]:
            current = ident(old.get('pid', 0))
            assert not (current and current['start_ticks'] == str(old.get('start_ticks'))
                        and current['host_boot_id'] == old.get('host_boot_id')
                        and current['process_state'] not in ['Z', 'X'])
    prep = read(C / 'prepared/preparation.json')
    assert prep['hardware_commit'] == COMMIT and prep['source_id'] == SID
    assert prep['functional_baseline_commit'] == FROZEN
    assert prep['all_original_outputs'] and prep['all_original_donttouch_observations']
    assert prep['generation_taps'] == 512
    for row in prep['authenticated_rtl'].values():
        assert sha(row['path']) == row['sha256']
        assert sha(row['closure']) == row['closure_sha256']
    assert sha(W / 'candidates/dcache-frozen-cycle-r3-20261111/prepared/pair.sv') == prep['pair_sha256']
    state = dict(schema='ec-opt4-complete-frozen-dcache-cycle/1', **ident(os.getpid()),
                 hardware_commit=COMMIT, source_id=SID, functional_baseline_commit=FROZEN,
                 status='REUSING_AUTHENTICATED_GENERATED_CPP_MODEL', started_utc=now(),
                 stages={}, preparation=prep, fpga_access=False,
                 complete_dcache_cycles_verified=False, full_dut_formal=False,
                 whole_admission=False, rtl_regenerated=False, rtl_changed=False)

    def update(**kw):
        state.update(kw); state['updated_utc'] = now(); save(S, state)

    update()
    obj = O / 'obj'
    obj.mkdir()
    model = read(C / 'evidence/generated-model-hashes.json')
    copied = {}
    for name, digest in model.items():
        p = Path(name)
        assert p.parent == OLD and p.is_file() and sha(p) == digest
        dst = obj / p.name
        shutil.copy2(p, dst)
        assert sha(dst) == digest
        copied[p.name] = digest
    mk = obj / 'VDCacheCyclePair.mk'
    old_mk = mk.read_text()
    assert str(W / 'candidates/dcache-frozen-cycle-r3-20261111') in old_mk
    mk.write_text(old_mk.replace(str(W / 'candidates/dcache-frozen-cycle-r3-20261111'), str(C)))
    save(O / 'reused-model.json', dict(original_hashes=model, copied_model=copied,
                                     makefile_sha256=sha(mk), only_make_paths_changed=True,
                                     no_verilator_RTL_regeneration=True))
    env = {**os.environ, 'LD_LIBRARY_PATH': '', 'CCACHE_DISABLE': '1',
           'OMP_NUM_THREADS': '2', 'MAKEFLAGS': '-j2', 'TMPDIR': str(O)}

    def run(name, argv):
        policy()
        log = O / (name + '-attempt-1.log')
        with log.open('xb', buffering=0) as f:
            p = subprocess.Popen(argv, cwd=obj, env=env, stdin=subprocess.DEVNULL,
                                 stdout=f, stderr=subprocess.STDOUT)
            update(status='RUNNING_' + name.upper(), child=ident(p.pid), stage_log=str(log))
            while p.poll() is None:
                try:
                    p.wait(timeout=30)
                except subprocess.TimeoutExpired:
                    pass
                update(); os.fsync(f.fileno())
        state['stages'][name] = dict(argv=argv, returncode=p.returncode, log=str(log),
                                    log_sha256=sha(log), ended_utc=now())
        update(child={})
        assert p.returncode == 0, (name, p.returncode, str(log))
        return log

    run('compile', ['nice', '-n', '15', '/usr/bin/make', '-f', 'VDCacheCyclePair.mk', '-j2',
                    'OPT_FAST=-O0', 'OPT_SLOW=-O0'])
    exe = obj / 'VDCacheCyclePair'
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
