#!/usr/bin/env python3
"""User-only fresh build + exactly one final diagnostic FST run. No resume."""
import argparse
import datetime as dt
import hashlib
import json
import os
from pathlib import Path
import shutil
import sys
import time
import uuid

SCRIPTS = Path(__file__).resolve().parent
sys.path.insert(0, str(SCRIPTS))
import launch_optimization_4_svb as base
import waveform_prepare as wp
from waveform_capture import capture

ROOT, OUT, CHIPYARD = base.ROOT, base.OUT, base.CHIPYARD
WAVE = OUT/'waveform_debug'
START = 1500000


def identity():
    ident = base.identity()
    paths = [SCRIPTS/n for n in ('launch_waveform_debug.py', 'waveform_prepare.py',
             'waveform_capture.py', 'opt4_waveform_runtime.h', 'fst_waveform_index.c',
             'analyze_waveform.py')]
    paths += [OUT.parent/'run_optimization_4_svb_waveform_debug.sh',
              CHIPYARD/'sims/verilator/Makefile',
              CHIPYARD/'generators/chipyard/src/main/resources/csrc/emulator.cc',
              CHIPYARD/'generators/chipyard/src/main/resources/csrc/stage1_exit.h']
    ident['waveform_tool_sha256'] = {str(p.relative_to(ROOT)): base.sha(p) for p in paths}
    return ident


def make_args(build, jobs):
    argv = base.make_argv(build, jobs)
    argv = [x for x in argv if not str(x).startswith('EXTRA_SIM_CXXFLAGS=')]
    return argv + ['VERILATOR_FST_MODE=1',
                   'EXTRA_SIM_CXXFLAGS=-DSTAGE1_EXIT_PORTS -DSAFE_CHAIN_EVENTS -DVL_USER_FATAL',
                   'TRACING_OPTS=--trace-fst --trace-threads 1 --trace-depth 99 --trace-max-array 256 --trace-max-width 1048576 --trace-structs']


def simulation_args(simulator, run):
    return [str(simulator), '-s', '1', '+cycle-count', '-v', str(run/'hang.fst'),
            '--dump-start='+str(START), '+permissive',
            '+safe-chain-events', '+safe-chain-budgeted', '+cache-opportunity', '+dramsim',
            '+dramsim_ini_dir='+str(CHIPYARD/'generators/testchipip/src/main/resources/dramsim2_ini'),
            '+max-cycles=500000000', '+loadmem='+str(base.LOADMEM), '+loadmem_addr=80000000',
            '+permissive-off', str(base.ELF)]


def reject_second_run():
    guard = WAVE/'FINAL_DIAGNOSTIC_SIMULATION_STARTED.json'
    if guard.exists():
        raise RuntimeError('final diagnostic simulation already attempted; analyze existing FST: '+str(guard))
    # Fail closed even if only a per-run guard survived interruption.
    for previous in WAVE.glob('*/SIMULATION_STARTED.json'):
        raise RuntimeError('final diagnostic simulation already attempted: '+str(previous.parent))


def trace_artifact(run):
    path = run/'hang.fst'
    if not path.is_file():
        return dict(path=str(path), status='MISSING')
    print('PHASE_START=waveform_hash FST='+str(path), flush=True)
    h = hashlib.sha256(); last = time.monotonic(); hashed = 0
    with path.open('rb') as source:
        for chunk in iter(lambda: source.read(1024*1024), b''):
            h.update(chunk); hashed += len(chunk)
            if time.monotonic()-last >= 30:
                print('WAVEFORM_HASH_IN_PROGRESS bytes='+str(hashed), flush=True); last = time.monotonic()
    return dict(path=str(path), bytes=path.stat().st_size, sha256=h.hexdigest(), format='FST',
                status='SAVED' if path.stat().st_size else 'EMPTY', copies=1)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--static-check', action='store_true', help='identity only; no elaboration/build/simulation')
    parser.add_argument('--jobs', type=int, default=1)
    args = parser.parse_args()
    if args.jobs < 1: parser.error('--jobs must be positive')
    run = manifest = None
    phase = 'SOURCE_IDENTITY'
    try:
        print('PHASE_START=source_identity', flush=True)
        ident = identity()
        if args.static_check:
            print(json.dumps(dict(status='PASS', source=ident, format='FST', dump_start=START,
                                  hardware_generation='NOT_EXECUTED', verilator_build='NOT_EXECUTED',
                                  simulation='NOT_EXECUTED', no_resume=True), indent=2))
            return 0
        reject_second_run()
        stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%d_%H%M%S')
        run_id = 'optimization_4_svb_waveform_'+stamp+'_'+uuid.uuid4().hex[:8]
        run = WAVE/run_id
        build = OUT/'build'/run_id
        run.mkdir(parents=True, exist_ok=False); build.mkdir(parents=True, exist_ok=False)
        manifest = dict(schema=3, run_id=run_id, kind='ONE_TIME_ROOT_CAUSE_WAVEFORM', source=ident,
                        run_directory=str(run), build_directory=str(build), commands=[],
                        hardware_generation='NOT_STARTED', verilator_build='NOT_STARTED', simulation='NOT_STARTED',
                        result='IN_PROGRESS', phase=phase, no_resume=True,
                        capture_policy=dict(host_stream_limit='disabled for this waveform run',
                                            producer_sampling='unchanged budgeted observers',
                                            failure_ring_events=8192, failure_ring_bytes=1048576),
                        software=dict(elf=str(base.ELF), elf_sha256=base.ELF_SHA,
                                      loadmem=str(base.LOADMEM), loadmem_sha256=base.LOADMEM_SHA),
                        trace=dict(format='FST', path=str(run/'hang.fst'), windowed=True,
                                   simulator_start=START, simulator_end='termination',
                                   fst_start=START*2, fst_tick='2*simulator_time + clock_phase',
                                   prior_run_core_cycle='simulator_time - 103; recheck against captured csr_cycle',
                                   verbose=False, runtime_scope='high coverage control hierarchy, depth99'))
        base.record(run/'run_manifest.json', manifest)
        print('RUN_DIRECTORY='+str(run)+'\nBUILD_DIRECTORY='+str(build), flush=True)
        shutil.copytree(CHIPYARD/'tools/DRAMSim2', build/'dramsim', symlinks=True,
                        ignore=shutil.ignore_patterns('*.o', '*.a', '*.so', 'results', '.git'))
        base.prepare_sim_dir(build)
        make = make_args(build, args.jobs)

        def execute(name, argv, log):
            nonlocal phase
            phase = name; manifest['phase'] = name
            item = dict(phase=name, argv=list(map(str, argv)), log=str(log), status='RUNNING')
            manifest['commands'].append(item); base.record(run/'run_manifest.json', manifest)
            try: base.command(argv, ROOT, log)
            except BaseException:
                item['status'] = 'FAILED'; raise
            item['status'] = 'PASS'; base.record(run/'run_manifest.json', manifest)

        execute('RTL_GENERATION', make+['verilog'], build/'rtl_generation.log')
        manifest['hardware_generation'] = 'PASS'
        # Copy actual active Chipyard emulator/header prerequisites before the
        # build-local overlay; debug make then sees newer observation copies.
        generated = build/'generated'
        execute('SIM_SUPPORT_COPY', make+[generated/'sim_files.f'], build/'sim_support_copy.log')
        phase = 'OBSERVATION_OVERLAY'
        inventory = wp.prepare(generated, SCRIPTS/'opt4_waveform_runtime.h')
        base.record(run/'signal_manifest.json', inventory)
        execute('VERILATOR_FST_BUILD', make+['debug'], build/'verilator_fst_build.log')
        manifest['verilator_build'] = 'PASS'
        phase = 'COMPILED_TRACE_AUDIT'
        audit = wp.compiled_audit(build, inventory)
        base.record(run/'compiled_trace_audit.json', audit)
        if audit['status'] != 'PASS':
            raise RuntimeError('required trace declarations missing; simulation refused')
        for path, rec in inventory['files'].items():
            if base.sha(path) != rec['observed_sha256']:
                raise RuntimeError('build overwrote observation overlay: '+path)
        if base.sha(generated/'gen-collateral/emulator.cc') != inventory['emulator']['observed_sha256']:
            raise RuntimeError('build overwrote trace-safe emulator')
        simulator = build/'verilator/simulator-chipyard-v1Config-debug'
        if not simulator.is_file() or not os.access(simulator, os.X_OK):
            raise RuntimeError('FST debug simulator missing')
        manifest['simulator'] = dict(path=str(simulator), sha256=base.sha(simulator))
        # Prepare native reader before committing the only simulation attempt.
        gtkwave = CHIPYARD/'.conda-env/share/verilator/include/gtkwave'
        reader = build/'fst_waveform_index'
        execute('FST_READER_BUILD', ['cc', '-O2', '-DFST_CONFIG_INCLUDE="fst_config.h"',
                                    '-I'+str(gtkwave), '-I'+str(CHIPYARD/'.conda-env/include'),
                                    SCRIPTS/'fst_waveform_index.c', gtkwave/'fstapi.c',
                                    gtkwave/'fastlz.c', gtkwave/'lz4.c',
                                    '-L'+str(CHIPYARD/'.conda-env/lib'), '-lz', '-o', reader], build/'fst_reader_build.log')
        if identity() != ident:
            raise RuntimeError('source identity changed during fresh build; simulation refused')
        reject_second_run()
        argv = simulation_args(simulator, run)
        phase = 'SIMULATION'
        claim = dict(run_directory=str(run), policy='ONE_ATTEMPT_NO_AUTOMATIC_RETRY', source=ident)
        with (WAVE/'FINAL_DIAGNOSTIC_SIMULATION_STARTED.json').open('x') as f:
            json.dump(claim, f, indent=2); f.write('\n')
        with (run/'SIMULATION_STARTED.json').open('x') as f:
            json.dump(claim, f, indent=2); f.write('\n')
        manifest.update(phase=phase, simulation='STARTED', simulation_argv=argv)
        base.record(run/'run_manifest.json', manifest)
        print('PHASE_START=simulation; FST_WINDOW_START='+str(START), flush=True)
        rc, stats = capture(argv, run)
        manifest.update(simulation='COMPLETED', exit_status=rc, capture=stats, waveform=trace_artifact(run))
        base.record(run/'run_manifest.json', manifest)
        execute('INITIAL_HANG_ANALYSIS', [sys.executable, OUT/'analysis/analyze_hang.py', run], run/'hang_analysis.log')
        execute('PREFIX_PROTOCOL_ANALYSIS', [sys.executable, OUT/'analysis/analyze_svb.py', run,
                                            '--output', run/'protocol_summary.json'], run/'protocol_analysis.log')
        execute('FST_INITIAL_ANALYSIS', [sys.executable, SCRIPTS/'analyze_waveform.py', run,
                                        '--reader', reader], run/'waveform_analysis.log')
        summary = json.loads((run/'waveform_summary.json').read_text())
        manifest.update(phase='COMPLETE', result='DIAGNOSTIC_CAPTURE_COMPLETE' if summary['coverage']=='PASS'
                        else 'DIAGNOSTIC_CAPTURE_INCOMPLETE', benchmark_exit_status=rc,
                        runtime_rootcause='PENDING_OFFLINE_FST_CAUSAL_ANALYSIS')
        base.record(run/'run_manifest.json', manifest)
        print('RUN_MANIFEST='+str(run/'run_manifest.json')+'\nFST='+str(run/'hang.fst'), flush=True)
        # A successfully captured hang is still a failed hardware simulation.
        return 0 if rc == 0 and summary['coverage'] == 'PASS' else 3
    except BaseException as exc:
        if manifest is not None:
            manifest.update(result='INTERRUPTED' if isinstance(exc, KeyboardInterrupt) else 'FAILED',
                            phase=phase, error=str(exc) or type(exc).__name__)
            if phase == 'SIMULATION': manifest['simulation'] = 'ABORTED'
            if hasattr(exc, 'capture_stats'):
                manifest.update(capture=exc.capture_stats, exit_status=getattr(exc, 'simulator_return_code', None))
            manifest['waveform'] = trace_artifact(run)
            base.record(run/'run_manifest.json', manifest)
        print('OPT4_WAVEFORM_FAILED phase='+phase+' error='+(str(exc) or type(exc).__name__),
              file=sys.stderr, flush=True)
        return 1


if __name__ == '__main__':
    raise SystemExit(main())
