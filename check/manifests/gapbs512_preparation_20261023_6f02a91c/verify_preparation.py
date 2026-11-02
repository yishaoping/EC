"""Static/artifact checks only, plus an isolated log-capture fixture."""
import ast
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import subprocess
import sys

ROOT = Path('/data1/gzh/EC/baseline')
OUT = Path(__file__).resolve().parent
BUILD = ROOT / 'software_common_builds/gapbs512_20261023_03'


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    value = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(value)
    return value


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    launcher = module('baseline_launcher', ROOT / 'launch_baseline.py')
    compiler = module('baseline_compiler', ROOT / 'prepare_common_build.py')
    scripts = ['run_baseline_gapbs512.sh', 'start_baseline_experiment.sh', 'build_common_benchmark.sh']
    subprocess.run(['/bin/bash', '-n', *[str(ROOT / s) for s in scripts]], check=True)
    for filename in ('launch_baseline.py', 'prepare_common_build.py', 'common_benchmark_contract.py'):
        ast.parse((ROOT / filename).read_text(), filename=filename)
    entry = ROOT / scripts[0]
    assert entry.stat().st_mode & 0o100
    descriptor = json.loads((BUILD / 'workload.json').read_text())
    pin = re.search(r'^expected_descriptor=([0-9a-f]{64})$', entry.read_text(), re.M).group(1)
    assert pin == sha(BUILD / 'workload.json')
    selected, inputs = launcher.workload(str(BUILD / 'workload.json'))
    roi = compiler.finalize  # Reuse the ELF check without writing another loadmem.
    # finalize writes only a new loadmem. Supply an existing artifact guard to
    # verify static ELF/layout/disassembly checks run before its exclusive open.
    try:
        roi(BUILD, (BUILD / 'test.symbols').read_text(), (BUILD / 'test.dump').read_text())
    except FileExistsError as exc:
        assert Path(exc.filename) == BUILD / 'test.loadmem_hex'
    else:
        raise AssertionError('Existing loadmem overwrite guard did not fire')
    build = json.loads((BUILD / 'build.manifest.json').read_text())
    assert compiler.tree(BUILD / 'source') == build['source_hashes']
    assert compiler.tree(ROOT / 'software_common') == build['source_hashes']
    fixed = json.loads((ROOT / 'software/fixed_candidate/origin.stage1_workload.json').read_text())
    preserved = ['Benchmark/gapbs/gapbs_bfs.c', 'Benchmark/gapbs/gapbs_bfs.h',
                 'bench/stage1_amo.h', 'hw/interrupt.c', 'hw/interrupt.h']
    for name in preserved:
        assert sha(BUILD / 'source' / name) == fixed['sources']['Software/Test/' + name]
    historical = ROOT / 'source/chipyard'
    make = (historical / 'sims/verilator/Makefile').read_text()
    common = (historical / 'common.mk').read_text()
    driver = (historical / 'generators/chipyard/src/main/resources/csrc/emulator.cc').read_text()
    assert 'debug: $(sim_debug)' in make and 'verilog: $(sim_common_files)' in common
    assert 'VERILATOR_FST_MODE ?= 1' in make and '--trace-fst' in make
    assert 'sim = $(sim_dir)/$(sim_prefix)-$(MODEL_PACKAGE)-$(CONFIG)' in make
    assert "case 'v':" in driver and "case 's':" in driver
    assert 'tile->trace(tfp.get(), 99)' in driver
    assert '+max-cycles=' in driver and '+cycle-count' in driver
    # Exercise only invoke's stream capture with Python text, never build/run.
    fixture = OUT / 'capture_fixture'
    fixture.mkdir(exist_ok=False)
    (fixture / 'tmp').mkdir()
    env = json.loads((ROOT / 'manifests/environment.json').read_text())
    record = {'commands': [], 'purpose': 'SYNTHETIC_LOG_CAPTURE_ONLY_NO_WORKLOAD'}
    rc = launcher.invoke(
        ['/usr/bin/python3', '-I', '-B', '-c',
         'import sys; print("fixture stdout"); print("fixture stderr",file=sys.stderr)'],
        fixture, fixture / 'test.log', launcher.sandbox_environment(env, fixture / 'tmp'), record,
        fixture / 'stdout.log', fixture / 'stderr.log')
    assert rc == 0
    assert (fixture / 'stdout.log').read_text() == 'fixture stdout\n'
    assert (fixture / 'stderr.log').read_text() == 'fixture stderr\n'
    assert sorted((fixture / 'test.log').read_text().splitlines()) == ['fixture stderr', 'fixture stdout']
    result = {'status': 'PASS', 'bash_syntax': 'PASS', 'python_syntax': 'PASS',
              'entry_executable_and_descriptor_pin': 'PASS',
              'software_descriptor_and_input_hashes': 'PASS',
              'elf_roi_instruction_and_layout_checks': 'PASS',
              'existing_loadmem_overwrite_refused': 'PASS',
              'source_snapshot_matches_build': 'PASS',
              'original_bfs_amo_timer_source_identity': 'PASS',
              'historical_make_targets_and_driver_flags': 'PASS',
              'isolated_stdout_stderr_capture_fixture': 'PASS',
              'elf': selected['elf'], 'elf_sha256': selected['elf_sha256'],
              'loadmem': selected['loadmem'], 'loadmem_sha256': selected['loadmem_sha256'],
              'software_roi': selected['roi'],
              'hardware_generation': 'NOT_EXECUTED', 'verilator_build': 'NOT_EXECUTED',
              'simulation': 'NOT_EXECUTED', 'workload': 'NOT_EXECUTED',
              'one_key_entry_executed': False,
              'compiler': build['compiler_version'],
              'script_sha256': {n: sha(ROOT / n) for n in scripts + ['launch_baseline.py']}}
    with (OUT / 'static_checks.json').open('x') as stream:
        json.dump(result, stream, indent=2)
        stream.write('\n')
    print('PREPARATION_CHECKS=PASS; no hardware generation/build/simulation/workload')


if __name__ == '__main__':
    main()
