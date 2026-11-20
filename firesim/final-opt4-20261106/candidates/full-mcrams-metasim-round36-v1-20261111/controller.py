#!/usr/bin/python3
"""Prepare and broker one CPU compile of the completed frozen MCRams model.

This never invokes GoldenGate, Vivado, a runtime workload, or FPGA tools.
Original full-host compilation and its running Canneal workload are read-only.
Compile output is a prerequisite for subsequent cycle/observation parity work.
"""
from pathlib import Path
import datetime
import fcntl
import hashlib
import json
import os
import resource
import shutil
import subprocess
import sys
import time

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
U = D / 'unattended-opt4'
O = D / 'cycleprecise-frozen-full-mcrams-metasim-round36-v1-20261111'
S = D / 'Opt4-route-a-full-mcrams-metasim-round36-v1-state.json'
MC = D / 'cycleprecise-frozen-mcrams-20261111'
PLAIN = D / 'cycleprecise-frozen-full-metasim-r1-20261111'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
NAME = 'full-mcrams-metasim-r36-v1-8491167d'


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda: f.read(2**20), b''):
            h.update(b)
    return h.hexdigest()


def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def save(p, j):
    p = Path(p)
    q = p.with_name(p.name + '.tmp-' + str(os.getpid()))
    with q.open('x') as f:
        json.dump(j, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())
    os.replace(q, p)


def policy():
    p = read(U / 'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE
    assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
    assert p['native_paused'] and not p['fpga_access']
    assert p['board_allowlist'] == ['0000:21:00.0']
    return p


def ident(pid):
    try:
        st = Path(f'/proc/{pid}/stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, start_ticks=st[19],
                    host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError:
        return {}


def prepare():
    policy()
    assert not O.exists() and not S.exists(), 'Adopt existing preparation; never overwrite.'
    assert not (U / 'requests' / (NAME + '.json')).exists()
    r = read(MC / 'result.json')
    mb = read(MC / 'binding.json')
    pb = read(PLAIN / 'binding.json')
    assert r['status'] == 'HOST_TRANSFORM_COMPLETE_NOT_EQUIVALENCE_OR_FIT_ADMITTED'
    assert r['functional_baseline'] == mb['functional_baseline'] == pb['functional_baseline'] == BASE
    assert mb['platform_config'] == 'MCRams_DacXilinxAlveoConfig'
    assert not r['raw_target_fir_changed'] and not mb['new_target_features']
    assert len(mb['memory_annotations']) == 10 and len(mb['multithread_annotations']) == 5
    assert pb['target_platform_config'] == 'DacXilinxAlveoConfig'
    inputs = {str(C / 'controller.py'): sha(C / 'controller.py')}
    for p in [MC / 'result.json', MC / 'binding.json', MC / 'receipts/goldengate.json',
              PLAIN / 'binding.json']:
        inputs[str(p)] = sha(p)
    # Bind the unchanged target once. The two host models have the same
    # source FIRRTL/annotations, without adding or dropping observations.
    for key in ['target_fir', 'target_annotations']:
        p = Path(mb[key]); assert sha(p) == mb[key + '_sha256']
        inputs[str(p)] = mb[key + '_sha256']
    fg = D / 'build-logs/C4-goldengate-20261106T100436.256198Z/result.json'
    inputs[str(fg)] = sha(fg)
    frozen = read(fg)
    assert frozen['returncode'] == 0 and frozen['frozen_hardware_commit'] == BASE
    # The original GG receipt records its elaborate receipt, whose output
    # manifest authenticates the same target input used for MCRams.
    er = Path(frozen['input_result']); ej = read(er)
    assert sha(er) == frozen['input_result_sha256']
    for key in ['target_fir', 'target_annotations']:
        assert ej['outputs'][mb[key]] == mb[key + '_sha256']
    inputs[str(er)] = sha(er)
    src = MC / 'goldengate'
    sv = src / 'FireSim-generated.sv'
    assert sha(sv) == r['host_rtl_sha256']
    O.mkdir()
    out = O / 'host'; out.mkdir()
    staged = {}
    for n in ['FireSim-generated.sv', 'FireSim-generated.const.h',
              'FireSim-generated.const.vh', 'FireSim-generated.defines.vh']:
        p = src / n; h = sha(p); dst = out / n
        shutil.copy2(p, dst); assert sha(dst) == h
        inputs[str(p)] = h; staged[str(dst)] = h
    # These are private copies of headers already used by the repaired plain
    # model. Generated ABI headers come from MCRams itself, never substituted.
    inc = O / 'external-headers'; inc.mkdir()
    for p in sorted((PLAIN / 'external-headers').iterdir()):
        assert p.is_file()
        h = sha(p); shutil.copy2(p, inc / p.name)
        inputs[str(p)] = h; staged[str(inc / p.name)] = h
    if (PLAIN / 'host/dromajo_params.h').is_file():
        p = PLAIN / 'host/dromajo_params.h'
        shutil.copy2(p, out / p.name)
        inputs[str(p)] = sha(p); staged[str(out / p.name)] = sha(p)
    libs = O / 'external-libs'; libs.mkdir()
    for p in sorted((PLAIN / 'external-libs').iterdir()):
        assert p.is_file()
        target = p.resolve(); inputs[str(target)] = sha(target)
        (libs / p.name).symlink_to(target)
    command = [a.replace('DRIVER_NAME=FrozenOpt4', 'DRIVER_NAME=FrozenOpt4MCRams')
               .replace(str(PLAIN / 'host'), str(out)) for a in pb['command']]
    for tool in [pb['environment']['CXX'],
                 '/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/bin/verilator']:
        inputs[tool] = sha(tool)
    driverarg = next(a for a in command if a.startswith('DRIVER='))
    for p in driverarg[len('DRIVER='):].split():
        assert sha(p) == pb['input_sha256'][p]
        inputs[p] = pb['input_sha256'][p]
    fs = W / 'C4/chipyard/sims/firesim/sim'
    # Bind Makefile and the C++/Verilog include closure, rather than trusting
    # only .cc files. No dependency cache or live model inputs are modified.
    roots = [fs / 'midas/src/main/cc', fs / 'firesim-lib/src/main/cc',
             fs / 'src/main/cc/firesim', fs / 'midas/src/main/verilog',
             W / 'C4/chipyard/generators/testchipip/src/main/resources/testchipip/csrc']
    for root in roots:
        for p in root.rglob('*'):
            if p.is_file() and (p.suffix in ['.h', '.hpp', '.cc', '.v', '.sv'] or
                                p.name == 'Makefile' or p.name.startswith('Makefrag')):
                inputs[str(p)] = sha(p)
    env = {k: v.replace(str(PLAIN), str(O)) for k, v in pb['environment'].items()}
    static = [p for p in driverarg[len('DRIVER='):].split() if p.endswith('.a')]
    # Include the two static libraries explicitly in final link flags: the
    # prior plain build's diagnosed missing-library failure is not repeated.
    env['LDFLAGS'] += ' ' + ' '.join(static) + ' -lstdc++ -lpthread -lgmp -l:libdwarf.so -l:libelf.so -lz'
    env.update(MAKEFLAGS='-j2', OMP_NUM_THREADS='2', CCACHE_DISABLE='1', LD_LIBRARY_PATH='')
    plan = dict(schema='ec-opt4-full-mcrams-metasim-build-plan/1',
                functional_baseline=BASE, source_id=pb['source_id'],
                status='PREPARED_COMPILE_ONLY_PARITY_PENDING', command=command,
                environment=env, input_sha256=inputs, staged_sha256=staged,
                binary=str(out / 'VFrozenOpt4MCRams'), host_rtl_sha256=r['host_rtl_sha256'],
                target_fir_sha256=mb['target_fir_sha256'],
                target_annotations_sha256=mb['target_annotations_sha256'],
                platform_config=mb['platform_config'], memory_annotations=10,
                original_target_function_and_cycles_unmodified=True,
                generated_abi_reused_from_plain=False, compile_only=True,
                full_observation_parity_passed=False, production_admission=False,
                whole_fit=False, fpga_access=False, max_compile_jobs=2,
                address_space_limit_gib=64, minimum_memory_gib=96,
                minimum_disk_gib=100, created_utc=now())
    save(O / 'build-plan.json', plan)
    save(C / 'input-hashes.json', inputs)
    spec_inputs = {**inputs, **staged, str(O / 'build-plan.json'): sha(O / 'build-plan.json'),
                   str(C / 'input-hashes.json'): sha(C / 'input-hashes.json')}
    request = dict(action='cpu_job', spec=dict(name=NAME, kind='module', cwd=str(C),
                   argv=['/usr/bin/python3', str(C / 'controller.py'), '--compile'],
                   inputs=spec_inputs, outputs=[str(O / 'result.json')], checkpoints=[str(S)]))
    save(C / 'request.json', request)
    print(json.dumps(dict(prepared=str(O / 'build-plan.json'), request=str(C / 'request.json'),
                          input_files=len(inputs), staged_files=len(staged), compile_started=False)))


def compile_model():
    policy()
    lock = (O / 'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not S.exists(), 'Preserve prior/partial stages; use a versioned recovery.'
    plan = read(O / 'build-plan.json')
    for p, h in {**plan['input_sha256'], **plan['staged_sha256']}.items():
        assert sha(p) == h, ('changed bound input', p)
    state = dict(schema='ec-opt4-full-mcrams-metasim-compile/1', **ident(os.getpid()),
                 functional_baseline=BASE, host_rtl_sha256=plan['host_rtl_sha256'],
                 started_utc=now(), status='WAITING_CPU_MEMORY_DISK_GUARDS',
                 fpga_access=False, full_observation_parity_passed=False, whole_fit=False)

    def update(**kw):
        state.update(kw, updated_utc=now()); save(S, state)

    update()
    while True:
        policy()
        available = int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines()
                             if l.startswith('MemAvailable:')))
        if available >= 96 * 2**20 and shutil.disk_usage(O).free >= 100 * 2**30:
            break
        time.sleep(300)
    model = O / 'host/VFrozenOpt4MCRams.csrc'
    assert not model.exists(), 'The upstream make recipe deletes model_dir; never replay a partial stage.'
    resource.setrlimit(resource.RLIMIT_AS, (64 * 2**30, 64 * 2**30))
    started = time.monotonic(); log = O / 'compile-attempt-1.log'
    with log.open('xb', buffering=0) as f:
        child = subprocess.Popen(plan['command'], cwd=C,
                                 env={**os.environ, **plan['environment']}, stdin=subprocess.DEVNULL,
                                 stdout=f, stderr=subprocess.STDOUT)
        update(status='RUNNING_FULL_FROZEN_MCRAMS_HOST_COMPILE', child=ident(child.pid), log=str(log))
        while child.poll() is None:
            try:
                child.wait(timeout=30)
            except subprocess.TimeoutExpired:
                pass
            os.fsync(f.fileno()); update(host_wall_seconds=time.monotonic() - started)
    binary = Path(plan['binary'])
    result = dict(status='BUILT_FULL_FROZEN_MCRAMS_PARITY_AND_RUNTIME_PENDING'
                  if child.returncode == 0 and binary.is_file() else 'FAILED_WITH_EVIDENCE',
                  functional_baseline=BASE, host_rtl_sha256=plan['host_rtl_sha256'],
                  build_plan_sha256=sha(O / 'build-plan.json'), returncode=child.returncode,
                  log=str(log), log_sha256=sha(log), host_wall_seconds=time.monotonic() - started,
                  binary=str(binary), binary_sha256=sha(binary) if binary.is_file() else None,
                  full_observation_parity_passed=False, runtime_started=False,
                  production_admission=False, whole_fit=False, fpga_access=False,
                  next='Validate same-ELF/input and every required original output at target-cycle boundaries; compile is not parity, FIT or a valid FPGA sample.',
                  ended_utc=now())
    save(O / 'result.json', result); update(status=result['status'], child={}, result=str(O / 'result.json'))
    assert result['status'].startswith('BUILT_'), 'Preserve failure and use a reviewed new version.'


if __name__ == '__main__':
    if sys.argv[1:] == ['--prepare']:
        prepare()
    elif sys.argv[1:] == ['--compile']:
        try:
            compile_model()
        except Exception as exc:
            if S.exists():
                st = read(S)
                if st.get('pid') == os.getpid():
                    st.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), updated_utc=now())
                    save(S, st)
            raise
    else:
        raise SystemExit('Use --prepare or broker --compile.')
