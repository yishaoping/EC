#!/usr/bin/python3
"""Bounded boundary diagnosis reusing the exact completed R4 Verilator model."""
from pathlib import Path
import fcntl
import hashlib
import importlib.util
import os
import resource
import shutil
import subprocess
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-address-production-token-boundary-diagnostic-r2-20261113'
P = D/'build-logs/Opt4-address-banked-production-host-r4-20261113'
AREA = W/'candidates/address-banked-production-area-pair-r3-20261113/controller.py'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, now, read, save, sha
spec = importlib.util.spec_from_file_location('released_area_gate', AREA)
a = importlib.util.module_from_spec(spec); spec.loader.exec_module(a)
m = a.p.m
m.C, m.O, m.CPUS = C, O, {212, 213}


def main():
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Adopt the diagnostic owner'
    units = ['ec-opt4-address-production-token-boundary-diagnostic-r1-20261113.service',
             'ec-opt4-address-banked-production-host-r4-20261113.service',
             'ec-opt4-address-banked-production-area-pair-r3-20261113.service']
    assert not any(a.members(unit) for unit in units)
    binding = read(C/'source-binding.json')
    assert all(sha(path) == h for path, h in binding['files'].items())
    assert read(P/'failure.json')['active_stage'] == 'token-oracle-Threaded'
    assert '[CompleteHost]FAIL Test at cycle 1' in (P/'token-oracle-Threaded.log').read_text()
    header = (P/'Threaded/FireSim-generated.const.h').read_text()
    assert '.DONE = 16,' in header and '.PRECISE_PEEKABLE = 528,' in header
    os.sched_setaffinity(0, {212, 213}); resource.setrlimit(resource.RLIMIT_AS, (64*2**30,)*2)
    m.ST.update(schema='ec-production-token-boundary-diagnostic/1', **identity(), started_utc=now(),
        functional_baseline=binding['functional_baseline'], hardware_commit=binding['hardware_commit'],
        experiment_commit=binding['experiment_commit'], source_binding_sha256=sha(C/'source-binding.json'),
        fpga_access=False, no_CAD=True, full_system_fit=False, validation_claim=False,
        scope='32-token observation diagnostics of exact production threaded model; no equivalence, area or FIT claim')
    m.update('ADMITTING_EXACT_MODEL_REUSED_BOUNDARY_DIAGNOSTIC')
    save(O/'predecessor-release.json', dict(utc=now(), units=units, members=[],
        failure_sha256=sha(P/'failure.json')))
    save(O/'admission.json', m.admission())
    host = P/'Threaded'; original = host/'VCompleteAddressStats.csrc'; obj = O/'obj'
    shutil.copytree(original, obj, copy_function=shutil.copy2)
    source_make = original/'Vemul.mk'; derived_make = obj/'Vemul.mk'
    text = source_make.read_text()
    old_driver = W/'candidates/address-banked-production-host-r4-20261113/TestComplete.cc'
    old_exe = host/'VCompleteAddressStats'; exe = O/'VBoundary'
    assert text.count(str(old_driver)) == 1 and text.count(str(old_exe)+':') == 1
    text = text.replace(str(old_driver), str(C/'TestComplete.cc'))
    # Do not replace old_exe inside generated-header paths.
    text = text.replace('default: '+str(old_exe), 'default: '+str(exe))
    text = text.replace('\n'+str(old_exe)+':', '\n'+str(exe)+':')
    derived_make.write_text(text)
    for name in ['TestComplete.o', 'TestComplete.d']:
        (obj/name).unlink()
    clang = '/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'
    env = {**os.environ, 'CCACHE_DISABLE': '1', 'LD_LIBRARY_PATH': '',
           'PATH': str(Path(clang).parent)+':/usr/local/bin:/usr/bin:/bin'}
    argv = ['/usr/bin/make', '-C', obj, '-f', 'Vemul.mk', '-j2', 'CXX='+clang, 'LINK='+clang, 'OBJCACHE=']
    runtime_objects = ['verilated.o', 'verilated_dpi.o', 'verilated_vpi.o',
                       'verilated_timing.o', 'verilated_threads.o']
    for name in runtime_objects:
        assert sha(obj/name) == sha(original/name)
        argv += ['-o', name]
    dry = subprocess.check_output([str(arg) for arg in argv]+['-n'], env=env, text=True)
    save(O/'reuse-model-audit.json', dict(original_model_make_sha256=sha(source_make),
        derived_model_make_sha256=sha(derived_make), copied_files=sum(p.is_file() for p in obj.iterdir()),
        hardware_RTL_sha256=sha(host/'FireSim-generated.sv'),
        reused_runtime_objects={name: sha(obj/name) for name in runtime_objects},
        driver_only_recompile=True, original_model_archive_sha256=sha(original/'Vemul__ALL.a')))
    (O/'compile-dry-run.txt').write_text(dry)
    assert dry.count(' -c ') == 1 and str(C/'TestComplete.cc') in dry
    m.stage('compile-driver-only', argv, [exe], env=env, timeout=600)
    assert sha(obj/'Vemul__ALL.a') == sha(original/'Vemul__ALL.a')
    trace = D/'build-logs/Opt4-address-banked-production-host-r1-20261112/positive-reference-public-tokens.txt'
    for mode in range(4):
        m.stage('boundary-mode-'+str(mode), [exe, '+trace='+str(trace), '+boundary-mode='+str(mode),
            '+seed=8491167', '+max-cycles=10000000'], marker='BOUNDARY_DIAGNOSTIC_COMPLETE mode='+str(mode),
            env=env, timeout=300)
    assert all(sha(path) == h for path, h in binding['files'].items())
    m.update('COMPLETE_BOUNDED_TOKEN_BOUNDARY_DIAGNOSTICS_NO_VALIDATION_CLAIM', ended_utc=now(),
        modes=4, tokens_per_mode=32, public_outputs=52, hardware_model_reused=True)
    save(O/'result.json', m.ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED', error=repr(exc), ended_utc=now())
            save(O/'failure.json', m.ST)
        raise
