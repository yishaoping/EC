#!/usr/bin/python3
"""Validate complete production tokens at the observed precise pre-step horizon."""
from pathlib import Path
import fcntl
import hashlib
import importlib.util
import json
import os
import resource
import shutil
import subprocess
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-address-banked-production-host-r5-20261113'
R4 = D/'build-logs/Opt4-address-banked-production-host-r4-20261113'
R2 = D/'build-logs/Opt4-address-banked-production-host-r2-20261113'
R1 = D/'build-logs/Opt4-address-banked-production-host-r1-20261112'
DIAG = D/'build-logs/Opt4-address-production-token-boundary-diagnostic-r2-20261113'
TREE = W/'Opt4-area-address-production-host-r5-20261113'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, now, read, save, sha
spec = importlib.util.spec_from_file_location('original_production_validator',
    W/'candidates/address-banked-production-host-r4-20261113/controller.py')
old = importlib.util.module_from_spec(spec); spec.loader.exec_module(old)
old.C, old.O, old.m.C, old.m.O = C, O, C, O
m = old.m


def compiled_threaded(host, trace):
    original = R4/'Threaded/VCompleteAddressStats.csrc'
    obj = host/'VCompleteAddressStats.csrc'
    shutil.copytree(original, obj, copy_function=shutil.copy2)
    source_make = original/'Vemul.mk'; derived_make = obj/'Vemul.mk'
    text = source_make.read_text()
    old_driver = W/'candidates/address-banked-production-host-r4-20261113/TestComplete.cc'
    old_exe = R4/'Threaded/VCompleteAddressStats'; exe = host/'VCompleteAddressStats'
    assert text.count(str(old_driver)) == 1
    text = text.replace(str(old_driver), str(C/'TestComplete.cc'))
    text = text.replace('default: '+str(old_exe), 'default: '+str(exe))
    text = text.replace('\n'+str(old_exe)+':', '\n'+str(exe)+':')
    derived_make.write_text(text)
    for name in ['TestComplete.o', 'TestComplete.d']: (obj/name).unlink()
    clang = '/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'
    env = {**os.environ, 'CCACHE_DISABLE': '1', 'LD_LIBRARY_PATH': '',
        'PATH': str(Path(clang).parent)+':/usr/local/bin:/usr/bin:/bin'}
    argv = ['/usr/bin/make', '-C', obj, '-f', 'Vemul.mk', '-j2', 'CXX='+clang, 'LINK='+clang, 'OBJCACHE=']
    reused = {}
    for name in ['verilated.o', 'verilated_dpi.o', 'verilated_vpi.o', 'verilated_timing.o', 'verilated_threads.o']:
        assert sha(obj/name) == sha(original/name); reused[name] = sha(obj/name)
        argv += ['-o', name]
    dry = subprocess.check_output([str(arg) for arg in argv]+['-n'], env=env, text=True)
    (O/'compile-dry-run.txt').write_text(dry)
    assert dry.count(' -c ') == 1 and str(C/'TestComplete.cc') in dry
    save(O/'reused-threaded-model.json', dict(original_model_make_sha256=sha(source_make),
        derived_model_make_sha256=sha(derived_make), reused_runtime_objects=reused,
        hardware_model_archive_sha256=sha(original/'Vemul__ALL.a'), RTL_regenerated=False))
    m.stage('compile-driver-only-Threaded', argv, [exe], env=env, timeout=600)
    assert sha(obj/'Vemul__ALL.a') == sha(original/'Vemul__ALL.a')
    args = [exe, '+trace='+str(trace), '+seed=8491167', '+max-cycles=10000000']
    m.stage('token-oracle-Threaded', args, marker='COMPLETE_ADDRESS_HOST_TOKEN_PASS', env=env, timeout=3600)
    m.stage('token-negative-Threaded', args+['+negative'], negative=True,
        marker='COMPLETE_ADDRESS_HOST_MISMATCH cycle=100 port=io_statsValid', env=env, timeout=600)
    line = next(line for line in (O/'token-oracle-Threaded.log').read_text().splitlines()
        if line.startswith('COMPLETE_ADDRESS_HOST_TOKEN_PASS '))
    result = json.loads(line.split(' ', 1)[1])
    assert result['target_tokens'] == 3003 and result['checked_outputs'] == 3000*52
    return result


def main():
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Adopt the exact validator owner'
    units = ['ec-opt4-address-banked-production-host-r4-20261113.service',
        'ec-opt4-address-banked-production-area-pair-r3-20261113.service',
        'ec-opt4-address-production-token-boundary-diagnostic-r2-20261113.service']
    assert not any(old.members(unit) for unit in units)
    binding = read(C/'source-binding.json')
    assert all(sha(path) == h for path, h in binding['files'].items())
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=TREE, text=True).strip() == binding['experiment_commit']
    for rel, h in binding['committed_files'].items():
        assert hashlib.sha256(subprocess.check_output(['git', 'show', binding['experiment_commit']+':'+rel], cwd=TREE)).hexdigest() == h
    diagnostic = read(DIAG/'result.json')
    assert diagnostic['status'] == 'COMPLETE_BOUNDED_TOKEN_BOUNDARY_DIAGNOSTICS_NO_VALIDATION_CLAIM'
    for mode in range(4):
        receipt = read(DIAG/('boundary-mode-'+str(mode)+'-receipt.json'))
        assert receipt['accepted'] and sha(receipt['log']) == receipt['log_sha256']
    rows = [line for line in (DIAG/'boundary-mode-3.log').read_text().splitlines()
        if line.startswith('BOUNDARY_ROW')]
    assert len(rows) == 32
    assert all('precise=1' in line and 'match_current=52' in line for line in rows[3:])
    # A reversible source check limits the change to the position of step(1).
    driver = (C/'TestComplete.cc').read_text()
    original_driver = (W/'candidates/address-banked-production-host-r4-20261113/TestComplete.cc').read_text()
    reversed_driver = driver.replace('        ++checked;\n      }\n      step(1);\n    }',
        '        ++checked;\n      }\n    }').replace('      (void)peek_poke.peek(output_ports[0], true);',
        '      step(1);\n      (void)peek_poke.peek(output_ports[0], true);')
    assert reversed_driver == original_driver
    os.sched_setaffinity(0, {212, 213}); resource.setrlimit(resource.RLIMIT_AS, (64*2**30,)*2)
    m.ST.update(schema='ec-production-host-precise-horizon-recovery/1', **identity(), started_utc=now(),
        functional_baseline=binding['functional_baseline'], hardware_commit=binding['hardware_commit'],
        experiment_commit=binding['experiment_commit'], source_binding_sha256=sha(C/'source-binding.json'),
        cpus=[212, 213], memory_limit_gib=64, fpga_access=False, no_CAD=True, full_system_fit=False,
        hardware_changed=False, reused_exact_target_and_threaded_host=True,
        finite_target_parity_reused=True, host_area_gain_unknown=True,
        scope='Full production3003-token52-output/negative host validation at precise input-poked pre-step horizon; no area or FIT claim')
    m.update('ADMITTING_PRECISE_INPUT_POKED_HORIZON_VALIDATION')
    save(O/'predecessor-release.json', dict(utc=now(), units=units, members=[],
        diagnostic_result_sha256=sha(DIAG/'result.json'), failure_sha256=sha(R4/'failure.json')))
    save(O/'admission.json', m.admission())
    pins = dict(binding['files'])
    pins[str(C/'source-binding.json')] = sha(C/'source-binding.json')
    save(O/'inputs.json', dict(files=pins))
    for name in ['full-target-parity', 'full-target-negative']:
        receipt = read(R1/(name+'-receipt.json'))
        assert receipt['accepted'] and sha(receipt['log']) == receipt['log_sha256']
    cfg = read(W/'candidates/dcache-field-read-system-r1-20261111/config.json')
    receipt = read(R2/'goldengate-Threaded-receipt.json')
    assert receipt['accepted'] and all(sha(path) == h for path, h in receipt['outputs'].items())
    argv = receipt['argv']; cp = argv[argv.index('-cp')+1]
    target = R2/'Host-target'; annotation = target/'CompleteAddressStats.anno.json'
    assert len([a for a in read(annotation) if a.get('class', '').endswith('FirrtlEnableModelMultiThreadingAnnotation')]) == 16
    trace = R1/'positive-reference-public-tokens.txt'
    assert len(trace.read_text().splitlines()) == 3003
    old.link_inputs(R2/'Threaded', O/'Threaded')
    (O/'trace-ports.h').symlink_to(R2/'trace-ports.h')
    tokens = {'Threaded': compiled_threaded(O/'Threaded', trace)}
    save(O/'token-progress.json', tokens)
    plain = O/'Plain'
    m.stage('goldengate-Plain', [cfg['java'], '-Xmx48G', '-Xss32M', '-XX:ActiveProcessorCount=2',
        '-cp', cp, 'midas.stage.GoldenGateMain', '-i', target/'CompleteAddressStats.fir', '-td', plain,
        '-faf', annotation, '-ggcp', 'opt4bankedproduction', '-ggcs', 'PlainConfig', '--output-filename-base', 'FireSim-generated'],
        [plain/'FireSim-generated.sv', plain/'FireSim-generated.synthesis.xdc'])
    assert 'Skipping Combinational Loop Detection' not in (O/'goldengate-Plain.log').read_text()
    old.link_inputs(plain, O/'Plain-linked')
    tokens['Plain'] = old.simulate(O/'Plain-linked', 'Plain', trace)
    assert tokens['Plain']['digest'] == tokens['Threaded']['digest']
    assert all(sha(path) == h for path, h in pins.items())
    m.update('PASS_PRODUCTION_HOST_PRECISE_3003_TOKEN_ORACLE_AND_PLAIN_THREADED_PARITY_NO_AREA',
        tokens=tokens, target_tokens=3003, public_outputs=52, finite_target_parity_reused=True,
        target_cycles=6144, monitor_outputs=5684, geometry=dict(banks=16, lanes=16, slots=256),
        full_formal=False, ended_utc=now(),
        next='Exact area successor must bind these new precise-horizon tokens and wait for this entire cgroup to release; no area or FIT claim')
    save(O/'result.json', m.ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED', error=repr(exc), ended_utc=now())
            save(O/'failure.json', m.ST)
        raise
