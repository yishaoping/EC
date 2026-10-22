#!/usr/bin/env python3
"""Internal Stage 3 state machine. Public entry: stage3/stage3_run.sh (no modes).

Each invocation owns a fresh directory. Completed phase directories are never
modified; reuse is a checked reference to their sealed inputs and artifacts.
Importing this module performs no build, analysis, or simulation.
"""
import ast
from collections import Counter
import contextlib
import fcntl
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import signal
import subprocess
import sys
import tempfile
import traceback

import stage2_validation as common

REPO, SCRIPTS = common.REPO, common.SCRIPTS
RUNS = REPO / 'AI/TMP/stage3_runs'
PHASES = ('build', 'directed', 'system')
SCHEMA = 'stage3-auto-1'
TIMEOUTS = dict(build=12*3600, directed=15*60, system=24*3600)
CASES = (
    'same_line_safe_dirty_wait_ack', 'same_line_already_outer_preserved',
    'safe_dirty_set_victim_wait_ack', 'speculative_set_victim_blocks_outer',
    'validated_victim_preserve_ack_replace', 'outer_backpressure_exactly_once',
    'delayed_ack_freezes_predecessor', 'stale_ack_ignored', 'duplicate_ack_ignored',
    'repeated_speculative_same_line', 'same_set_different_line_replacement',
    'pending_same_line_request', 'pending_replacement_pressure',
    'validation_and_ack_same_cycle', 'validation_and_refill_replacement_same_cycle',
    'flush_clear_normal_writeback_barrier', 'safe_clean_victim_no_write',
    'full_provenance_collision', 'lineage_unaware_peer_waits_validation')
DIRECTED_CODE = ('protocol_report', 'case_report', 'directed', 'verify_directed')
SYSTEM_CODE = ('progress_report', 'system_reports', 'system_binding', 'system', 'verify_system')


def digest(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True, separators=(',', ':')).encode()).hexdigest()


def save_new(path, value):
    # No overwrites, including on failure or repeated invocations.
    with path.open('x') as stream:
        json.dump(value, stream, indent=2, sort_keys=True)
        stream.write('\n')


def audit(root, value):
    with (root/'reuse.audit.jsonl').open('a') as stream:
        stream.write(json.dumps(value, sort_keys=True)+'\n')


def script_hashes(names):
    return {name: common.sha(SCRIPTS/name) for name in names}


def code_identity():
    # Checker-only fixes can retain a model. Any unclassified state-machine,
    # import, constant or helper change conservatively invalidates BUILD too.
    groups = dict(core=[], directed=[], system=[])
    for node in ast.parse(Path(__file__).read_text()).body:
        name = getattr(node, 'name', '')
        case_constant = isinstance(node, ast.Assign) and any(
            isinstance(t, ast.Name) and t.id == 'CASES' for t in node.targets)
        group = 'directed' if name in DIRECTED_CODE or case_constant else 'system' if name in SYSTEM_CODE else 'core'
        groups[group].append(ast.dump(node, include_attributes=False))
    return {key: digest(value) for key, value in groups.items()}


def inputs():
    record = common.inputs()  # source/workload/tool hashes; no build or simulation
    record['schema'] = SCHEMA
    record['environment_hashes'].pop('STAGE3_ROOT', None)  # obsolete; never selects a run
    record['stage3_scripts'] = script_hashes([
        'stage3_validation.py', 'stage3/stage3_run.sh',
        'stage3/Stage3Generate.scala', 'stage3/stage3_test.cpp'])
    record['runner_code'] = code_identity()
    record['build'].update(module_top='Stage3Harness', module_wiring_audit=False)
    return record


def prepare_workload(root):
    """Refresh changed software at invocation time; never reuse its old ELF."""
    from stage1_workload import sources, verify
    for name in os.environ:
        if name.startswith('STAGE1_') and name not in ('STAGE1_WORKLOAD', 'STAGE1_WAVEFORM'):
            raise common.Stop('unsupported inherited override: ' + name, 2)
    manifest = Path(os.environ.get('STAGE1_WORKLOAD', REPO/'AI/TMP/stage1_workload.json')).resolve()
    previous = common.read(manifest) if manifest.is_file() else None
    if previous is not None and previous.get('sources') == sources():
        verify(manifest)  # Artifact corruption still fails; it is not a rebuild hint.
        return
    if previous is not None:
        save_new(root/'workload.before.json', previous)
    print('WORKLOAD=PREPARING_CHANGED_SOFTWARE', flush=True)
    env = dict(os.environ, STAGE1_WORKLOAD=str(manifest))
    common.command(root, 'workload.prepare.log',
                   ['bash', SCRIPTS/'stage1_prepare_workload.sh'], env=env)
    verify(manifest)


def verify_inputs(record):
    if inputs() != record:
        raise common.Stop('inputs changed during this invocation; rerun the same command')


def phase_contract(record, phase, dependencies):
    shared = dict(schema=SCHEMA, phase=phase, head=record['head'], source=record['source'],
                  tools=record['tools'], environment=record['environment_hashes'],
                  riscv=record['riscv'], java_dir=record['java_dir'],
                  core=record['runner_code']['core'], dependencies=dependencies,
                  entry=record['stage3_scripts']['stage3/stage3_run.sh'])
    if phase == 'build':
        shared.update(build=record['build'], scripts={k: record['scripts'][k] for k in (
            'AI/Debug/scripts/stage2_validation.py', 'AI/Debug/scripts/stage1_build_and_run.sh',
            'AI/Debug/scripts/stage1_provenance.py', 'AI/Debug/scripts/stage1_workload.py')},
            fixture={k: v for k, v in record['stage3_scripts'].items() if k.endswith(('.scala', '.cpp'))})
    else:
        shared.update(workload=record['workload'], workload_sha256=record['workload_sha256'],
                      workload_inputs=record['workload_inputs'], checker=record['runner_code'][phase],
                      cases=list(CASES) if phase == 'directed' else [], timeout=TIMEOUTS[phase])
        if phase == 'system':
            shared['scripts'] = {k: record['scripts'][k] for k in (
                'AI/Debug/scripts/stage1_run_trace.sh', 'AI/Debug/scripts/stage1_trace_scoreboard.py',
                'AI/Debug/scripts/stage2_trace_scoreboard.py')}
    return shared


def command_failure(path, reason, code=1, *, raw_code=None):
    # Only called for logs created by this attempt. Reused evidence stays read-only.
    first = None
    try:
        first = common.first_error(path)
        diagnostics = common.failure_diagnostics(path, raw_code)
    except Exception as error:
        # Failure to write a diagnostic must not replace the original tool status.
        diagnostics = dict(count=None, text='', json='', error=str(error))
        print('ERROR_REPORT_FAILURE='+str(error), flush=True)
    return common.Stop(reason+(': '+first if first else ''), code, log=path, first_error=first,
                       raw_code=raw_code, diagnostics=diagnostics)


def execute(root, log, argv, *, phase, cwd=REPO, env=None):
    path = root/log
    print('LOG='+str(path), flush=True)
    with (root/'commands.jsonl').open('a') as stream:
        stream.write(json.dumps(dict(log=log, argv=list(map(str, argv)), cwd=str(cwd)))+'\n')
    timed_out = False
    with path.open('x') as out:
        process = subprocess.Popen(list(map(str, argv)), cwd=cwd, env=env,
                                   stdin=subprocess.DEVNULL, stdout=out, stderr=subprocess.STDOUT,
                                   start_new_session=True)
        try:
            rc = process.wait(timeout=TIMEOUTS[phase])
        except BaseException as error:
            # An interrupted/timeout attempt never becomes reusable. Stop its
            # descendants before releasing the global build/run lock.
            with contextlib.suppress(ProcessLookupError):
                os.killpg(process.pid, signal.SIGTERM)
            try:
                process.wait(timeout=10)
            except subprocess.TimeoutExpired:
                with contextlib.suppress(ProcessLookupError):
                    os.killpg(process.pid, signal.SIGKILL)
                process.wait()
            if isinstance(error, subprocess.TimeoutExpired):
                timed_out = True
            else:
                raise
            rc = process.returncode
    with (root/'commands.jsonl').open('a') as stream:
        stream.write(json.dumps(dict(log=log, raw_exit_code=rc))+'\n')
    if timed_out:
        raise command_failure(path, 'wall timeout in '+phase+'; process group stopped',
                              124, raw_code=rc)
    if rc:
        raise command_failure(path, 'command failed', common.process_code(rc), raw_code=rc)


def manifest(root, paths):
    unique = sorted(set(paths))
    if not unique or any(not path.is_file() for path in unique):
        raise common.Stop('missing evidence/model artifact under '+str(root))
    return {str(path.relative_to(root)): common.sha(path) for path in unique}


def build_artifacts(root):
    paths = [p for folder in ('generated', 'obj') for p in (root/folder).rglob('*')
             if p.is_file() and p.suffix in ('.v', '.sv', '.fir', '.json', '.h', '.cpp', '.cc', '.mk', '.f')]
    paths += [root/name for name in (
        'generated/Stage3Harness.v', 'obj/VStage3Harness', 'rtl.f',
        'fixture/Stage3Generate.scala', 'fixture/stage3_test.cpp',
        'module.emit.log', 'module.lint.log', 'module.build.log', 'system.build.wrapper.log',
        'system.build/provenance.json', 'system.build/source.before.json')]
    return manifest(root, paths)


def verify_build(root, review):
    # Full system source/generated/binary attestation, with output ONLY in the
    # current invocation's review directory. Never append to an old run.
    p = common.system_paths(root)
    execute(review, 'provenance.verify.log', [sys.executable, '-B', SCRIPTS/'stage1_provenance.py',
        '--root', REPO/'chipyard', '--sim', p['sim'], '--generated', p['generated'],
        '--manifest', p['manifest']], phase='build')
    if not re.search(r'^PROVENANCE=PASS$', (review/'provenance.verify.log').read_text(), re.M):
        raise common.Stop('system model attestation missing PASS', log=review/'provenance.verify.log')
    return build_artifacts(root)


def build(root, record):
    fixture = root/'fixture'
    fixture.mkdir()
    for name in ('Stage3Generate.scala', 'stage3_test.cpp'):
        shutil.copyfile(SCRIPTS/'stage3'/name, fixture/name)
    generated = root/'generated'
    generated.mkdir()
    (root/'source.patch').write_bytes(subprocess.check_output(['git', 'diff', '--', 'chipyard/generators'], cwd=REPO))
    execute(root, 'module.emit.log', [record['tools']['sbt']['path'], '-java-home', record['java_dir'],
        *common.MODULE_JVM_ARGS,
        'set chipyard / Compile / unmanagedSources += file("'+str(fixture/'Stage3Generate.scala')+'")',
        'project chipyard', 'Compile / compile', 'runMain stage3.EmitModule '+str(generated)],
        phase='build', cwd=REPO/'chipyard', env=dict(os.environ, RISCV=record['riscv']))
    log = root/'module.emit.log'
    if common.error_entries(log) or not re.search(r'^STAGE3_EMIT=PASS top=Stage3Harness$', log.read_text(errors='replace'), re.M):
        raise command_failure(log, 'module generation incomplete', raw_code=0)
    rtl = sorted(generated.rglob('*.v'))+sorted(generated.rglob('*.sv'))
    if not rtl or not (generated/'Stage3Harness.v').is_file():
        raise command_failure(log, 'fresh Stage3Harness RTL missing', raw_code=0)
    (root/'rtl.f').write_text(''.join(str(p)+'\n' for p in rtl))
    args = ['--assert', '-Wno-fatal', '-Werror-UNOPTFLAT', '-Werror-PINMISSING', '--error-limit', '0',
            '--top-module', 'Stage3Harness', '-f', root/'rtl.f']
    execute(root, 'module.lint.log', [record['tools']['verilator']['path'], '--lint-only',
        '--Mdir', root/'lint', *args], phase='build', cwd=root)
    execute(root, 'module.build.log', [record['tools']['verilator']['path'], '--cc', '--exe', '--build',
        *args, '--Mdir', root/'obj', '-CFLAGS', '-std=c++17', fixture/'stage3_test.cpp'], phase='build', cwd=root)
    execute(root, 'system.build.wrapper.log', ['bash', SCRIPTS/'stage1_build_and_run.sh'], phase='build',
        env=dict(os.environ, STAGE1_BUILD_ONLY='1', STAGE1_SIM_ROOT=str(root/'system.build'),
                 STAGE1_WORKLOAD=record['workload']))


def protocol_report(lines, allow_ignored=False):
    errors, counts = [], Counter()
    pending, requested, victims, seen_victims = {}, set(), {}, set()
    correctness = Counter(speculative_outer_write=0, stale_ack_effect=0,
                          duplicate_preserve=0, premature_overwrite=0)
    names = ('set', 'way', 'tag', 'valid', 'writer', 'gen', 'seq', 'reason')
    for line in lines:
        for token, category in (('L2_SPEC_OUTER_WRITE_ERROR', 'speculative_outer_write'),
                                ('L2_DUP_PRESERVE_ERROR', 'duplicate_preserve'),
                                ('L2_PREMATURE_OVERWRITE_ERROR', 'premature_overwrite')):
            if token in line:
                correctness[category] += 1
                errors.append(token)
        if re.search(r'Assertion.*failed|Assertion Failure|%Error|\[END\] status=(?:FAIL|TIMEOUT)', line, re.I):
            errors.append('assertion_or_runtime_failure')
        m = re.search(r'STAGE3_TX (\w+) (.*)', line)
        if not m:
            if 'L2_STALE_ACK_ERROR' in line:
                errors.append('unclassified_stale_ack')
                correctness['stale_ack_effect'] += 1
            continue
        event = m[1]
        fields = {k: int(v, 16) for k, v in re.findall(r'(\w+)=([0-9a-fA-F]+)\b', m[2])}
        counts[event] += 1
        txn = (fields.get('bank'), fields.get('txn'))
        identity = tuple(fields.get(k) for k in names)
        if event in ('L2_PRESERVE_PENDING', 'L2_PRESERVE_REQ', 'L2_PRESERVE_ACK', 'L2_VICTIM_REQ', 'L2_VICTIM_ACK'):
            if any(k not in fields for k in ('bank', 'txn', *names)) or fields.get('txn') == 0:
                errors.append('incomplete_transaction_provenance')
        if event == 'L2_PRESERVE_PENDING':
            if txn in pending or txn in requested:
                errors.append('duplicate_pending')
                correctness['duplicate_preserve'] += 1
            pending[txn] = identity
        elif event == 'L2_PRESERVE_REQ':
            if pending.get(txn) != identity or txn in requested:
                errors.append('duplicate_or_wrong_request')
                correctness['duplicate_preserve'] += 1
            requested.add(txn)
        elif event == 'L2_PRESERVE_ACK':
            if pending.pop(txn, None) != identity or txn not in requested:
                errors.append('unmatched_checkpoint_ack')
                correctness['stale_ack_effect'] += 1
        elif event in ('L2_VICTIM_REQ', 'L2_VICTIM_ACK'):
            key = (*txn, fields.get('source'))
            if 'source' not in fields: errors.append('missing_victim_source')
            if event == 'L2_VICTIM_REQ':
                if key in seen_victims:
                    errors.append('duplicate_victim_request')
                    correctness['duplicate_preserve'] += 1
                seen_victims.add(key)
                victims[key] = identity
            elif victims.pop(key, None) != identity:
                errors.append('unmatched_victim_ack')
                correctness['stale_ack_effect'] += 1
        elif event == 'L2_STALE_ACK_ERROR':
            # Directed intentionally injects stale/duplicate/early ACKs. Their
            # ignored trace plus independent host checks is required coverage,
            # never an exemption for a state-changing or malformed stale ACK.
            if not (allow_ignored and fields.get('ignored') == 1 and
                    all(k in fields for k in ('bank', 'txn', 'current'))):
                correctness['stale_ack_effect'] += 1
                errors.append('stale_ack_not_proven_ignored')
        elif event.endswith('_ERROR'):
            errors.append(event)
    if pending or victims: errors.append('unclosed_preservation')
    return dict(status='FAIL' if errors else 'PASS', errors=errors, counts=dict(counts),
                correctness_errors=dict(correctness), checkpoint_transactions=len(requested),
                checkpoint_acks=counts['L2_PRESERVE_ACK'], victim_acks=counts['L2_VICTIM_ACK'])


def case_report(text, rc=0):
    cases = Counter(re.findall(r'^CASE (\w+) PASS$', text, re.M))
    protocol = protocol_report(text.splitlines(), allow_ignored=True)
    errors = list(protocol['errors'])
    missing = sorted(set(CASES)-cases.keys())
    if set(cases)-set(CASES) or any(v != 1 for v in cases.values()) or missing:
        errors.append(f'case_inventory_requires_exact_{len(CASES)}_of_{len(CASES)}')
    if re.search(r'^CASE .*\bFAIL\b|^STAGE3_DIRECTED=FAIL', text, re.M): errors.append('explicit_case_failure')
    count_lines = re.findall(r'^STAGE3_COUNTERS (.*)$', text, re.M)
    counts = {k: int(v) for k, v in re.findall(r'(\w+)=(\d+)', count_lines[0])} if len(count_lines) == 1 else {}
    if not counts: errors.append('missing_or_duplicate_counters')
    if counts.get('req') != protocol['checkpoint_transactions'] or counts.get('ack') != protocol['checkpoint_acks']:
        errors.append('counter_trace_mismatch')
    if counts.get('assertions') != 0 or counts.get('errors') != 0: errors.append('hardware_or_host_errors')
    if not counts.get('validation_ack_race') or not counts.get('validation_write_race'):
        errors.append('precise_validation_races_not_seen')
    if not protocol['checkpoint_transactions'] or not counts.get('stale') or not counts.get('duplicate'):
        errors.append('missing_preservation_or_adversarial_ack_coverage')
    if len(re.findall(r'^STAGE3_DIRECTED=PASS cycles=[1-9]\d*$', text, re.M)) != 1:
        errors.append('missing_unique_directed_completion')
    if re.findall(r'^\[END\] status=(\w+)\s*$', text, re.M) != ['PASS']:
        errors.append('missing_unique_end_pass')
    if rc: errors.append('simulator_nonzero_exit')
    return dict(status='FAIL' if errors else 'PASS', cases=dict(cases), missing=missing, errors=errors,
                simulator_exit_code=rc, counters=counts, protocol=protocol)


def directed(root, record, build_root):
    failure = None
    try:
        execute(root, 'module.trace.log', [build_root/'obj/VStage3Harness'], phase='directed', cwd=root)
    except common.Stop as error:
        failure = error
    report = case_report((root/'module.trace.log').read_text(errors='replace'),
                         failure.raw_code if failure else 0)
    save_new(root/'directed.coverage.json', report)
    if failure: raise failure
    if report['status'] != 'PASS':
        raise common.Stop(f'DIRECTED requires {len(CASES)}/{len(CASES)}, END PASS and zero correctness errors', log=root/'directed.coverage.json')


def verify_directed(root, build_root):
    commands = [json.loads(line) for line in (root/'commands.jsonl').read_text().splitlines()]
    if commands != [dict(log='module.trace.log', argv=[str(build_root/'obj/VStage3Harness')], cwd=str(root)),
                    dict(log='module.trace.log', raw_exit_code=0)]:
        raise common.Stop('directed trace executable/exit provenance differs')
    if case_report((root/'module.trace.log').read_text(errors='replace')) != common.read(root/'directed.coverage.json'):
        raise common.Stop('directed checker/evidence mismatch')
    if common.read(root/'directed.coverage.json')['status'] != 'PASS':
        raise common.Stop('directed correctness gate failed')
    return manifest(root, [root/'module.trace.log', root/'directed.coverage.json', root/'commands.jsonl'])


def progress_report(trace, stage1):
    errors, samples = [], []
    exit_line = stage1.get('sim_exit') or ''
    m = re.search(r'\bcycles=(\d+)\b', exit_line)
    if not m or not (0 < int(m[1]) < 500000000) or 'reason=serial_success ' not in exit_line:
        errors.append('no_bounded_successful_progress')
    if stage1.get('verified') != 1 or stage1.get('software_end') != 'PASS': errors.append('workload_not_verified')
    if stage1.get('gates', {}).get('exit_outstanding') != 'PASS' or stage1.get('exit_real_outstanding') != 0 or stage1.get('exit_blockers'):
        errors.append('exit_not_drained')
    if set(stage1.get('exit_drain', {})) != {'DCACHE', 'LSU'}: errors.append('missing_live_exit_drain')
    pattern = re.compile(r'\bdeadlock\b|\bwatchdog\b.*(?:fired|expired|timeout|fail)|'
                         r'(?:max.?cycles|timeout|timed out).*(?:exceed|reached|fail)|'
                         r'(?:status|reason)=(?:TIMEOUT|DEADLOCK|max_cycles|watchdog)', re.I)
    with trace.open(errors='replace') as stream:
        for lineno, line in enumerate(stream, 1):
            if pattern.search(line):
                if len(samples) < 20: samples.append(dict(line=lineno, text=line.strip()))
    if samples: errors.append('deadlock_or_timeout_diagnostic')
    return dict(status='FAIL' if errors else 'PASS', errors=errors, diagnostics=samples,
                cycles=int(m[1]) if m else None, cycle_limit=500000000, wall_timeout_seconds=TIMEOUTS['system'])


def system_reports(root):
    from stage1_trace_scoreboard import Scoreboard
    from stage2_trace_scoreboard import analyze
    run = root/'system.run'
    trace = run/'trace.log'
    board, trace_hash = Scoreboard(common.read(run/'workload.json')), hashlib.sha256()
    with trace.open('rb') as stream:
        for lineno, line in enumerate(stream, 1):
            trace_hash.update(line)
            board.consume(line, lineno)
    stage1 = board.finish()
    stage1['trace_sha256'] = trace_hash.hexdigest()
    with trace.open(errors='replace') as stream: stage2 = analyze(stream)
    with trace.open(errors='replace') as stream: stage3 = protocol_report(stream)
    if not stage3['counts'].get('L2_PRESERVE_REQ', 0) + stage3['counts'].get('L2_VICTIM_REQ', 0):
        stage3['errors'].append('no_stage3_system_observation')
        stage3['status'] = 'FAIL'
    progress = progress_report(trace, stage1)
    return {'stage1.recheck.json': stage1, 'stage2.scoreboard.json': stage2,
            'stage3.scoreboard.json': stage3, 'progress.json': progress}


def system_binding(root, record, build_root):
    run, p = root/'system.run', common.system_paths(build_root)
    if common.sha(run/'provenance.json') != common.sha(p['manifest']):
        raise common.Stop('system trace not bound to upstream model')
    if common.sha(run/'workload.json') != record['workload_sha256']:
        raise common.Stop('system trace workload differs')
    if common.sha(run/'stage1_trace_scoreboard.py') != record['scripts']['AI/Debug/scripts/stage1_trace_scoreboard.py']:
        raise common.Stop('system trace checker differs')
    saved = common.read(run/'run.json')
    if saved['input_sha256'] != {name: common.sha(run/name) for name in (
            'provenance.json', 'workload.json', 'stage1_trace_scoreboard.py')}:
        raise common.Stop('system run input snapshot changed')
    workload = common.read(run/'workload.json')
    argv = [str(p['sim'])]
    if record['environment'].get('STAGE1_WAVEFORM') in (None, '1'):
        argv += ['-v', str(run/'trace.fst')]
    argv += ['+verbose', '+permissive', '+dramsim',
             '+dramsim_ini_dir='+str(REPO/'chipyard/generators/testchipip/src/main/resources/dramsim2_ini'),
             '+max-cycles=500000000', '+loadmem='+workload['loadmem'], '+loadmem_addr=80000000',
             '+permissive-off', workload['benchmark']]
    if saved['argv'] != argv or saved['run_directory'] != str(run):
        raise common.Stop('system trace executable/arguments/directory differ')


def system(root, record, build_root):
    p = common.system_paths(build_root)
    failure = None
    try:
        execute(root, 'system.run.wrapper.log', ['bash', SCRIPTS/'stage1_run_trace.sh'], phase='system',
            env=dict(os.environ, STAGE1_SIM=str(p['sim']), STAGE1_GENERATED=str(p['generated']),
                     STAGE1_PROVENANCE=str(p['manifest']), STAGE1_RUN_ROOT=str(root/'system.run'),
                     STAGE1_WORKLOAD=record['workload']))
    except common.Stop as error:
        failure = error
    if (root/'system.run/trace.log').is_file():
        for name, report in system_reports(root).items(): save_new(root/'system.run'/name, report)
    if failure: raise failure
    system_binding(root, record, build_root)


def verify_system(root):
    run = root/'system.run'
    if (run/'simulator.status').read_text().strip() != 'SIMULATOR_EXIT_CODE=0':
        raise common.Stop('system simulator exit not zero')
    saved = common.read(run/'scoreboard.json')
    for name, report in system_reports(root).items():
        if digest(report) != digest(common.read(run/name)) or report['status'] != 'PASS':
            raise common.Stop('system regression/invariant/progress gate: '+name, log=run/name)
        if name == 'stage1.recheck.json' and digest(report) != digest(saved):
            raise common.Stop('Stage1 launcher and independent recheck disagree', log=run/'scoreboard.json')
    artifacts = manifest(root, [root/'system.run.wrapper.log', root/'commands.jsonl'] + [run/name for name in (
        'trace.log', 'run.json', 'simulator.status', 'provenance.json', 'workload.json',
        'stage1_trace_scoreboard.py', 'scoreboard.json', 'scoreboard.out',
        'stage1.recheck.json', 'stage2.scoreboard.json', 'stage3.scoreboard.json', 'progress.json')])
    if saved['trace_sha256'] != artifacts['system.run/trace.log']:
        raise common.Stop('system trace changed while checking it')
    return artifacts


def review_dir(root, label):
    path = Path(tempfile.mkdtemp(prefix=label+'_', dir=root/'reviews'))
    return path


def verify_result(path, record, phase, dependencies, root):
    result = common.read(path)
    phase_root = path.parent
    saved_inputs = common.read(phase_root.parent/'inputs.json')
    expected = phase_contract(record, phase, dependencies)
    if result.get('schema') != SCHEMA or result.get('phase') != phase or result.get('status') != 'PASS' or result.get('exit_code') != 0:
        raise common.Stop('phase not sealed PASS/exit0')
    if result.get('key') != digest(expected) or result.get('dependencies') != dependencies:
        raise common.Stop('phase key/upstream dependency changed')
    if digest(phase_contract(saved_inputs, phase, dependencies)) != result['key']:
        raise common.Stop('saved source/input provenance differs from phase key')
    if result['inputs_sha256'] != common.sha(phase_root.parent/'inputs.json'):
        raise common.Stop('saved inputs manifest changed')
    if common.read(phase_root/'plan.json') != expected or common.read(phase_root/'seal.json') != dict(result_sha256=common.sha(path)):
        raise common.Stop('phase plan/result seal changed')
    if set(result['upstream_paths']) != set(dependencies):
        raise common.Stop('upstream phase inventory differs')
    for name, upstream_path in result['upstream_paths'].items():
        upstream_path = Path(upstream_path)
        upstream = common.read(upstream_path)
        if (upstream.get('phase') != name or upstream.get('status') != 'PASS' or
                upstream.get('token') != dependencies[name] or
                common.read(upstream_path.parent/'seal.json') != dict(result_sha256=common.sha(upstream_path))):
            raise common.Stop('upstream phase seal/token changed')
    review = review_dir(root, 'verify_'+phase)
    build_root = Path(result['upstream_paths']['build']).parent if phase != 'build' else phase_root
    actual = verify_build(phase_root, review) if phase == 'build' else verify_directed(phase_root, build_root) if phase == 'directed' else verify_system(phase_root)
    if result['artifacts'] != actual or result['token'] != digest(dict(key=result['key'], artifacts=actual)):
        raise common.Stop('phase artifact/model identity changed')
    if phase == 'system':
        # The wrapper's attestation, workload, checker and argv must refer to
        # the same upstream model, not another run with a convenient PASS.
        system_binding(phase_root, record, build_root)
    audit(root, dict(phase=phase, candidate=str(path), reuse='VERIFIED', token=result['token']))
    return result


def find_reusable(root, record, phase, dependencies):
    key = digest(phase_contract(record, phase, dependencies))
    # Ordering is irrelevant to validity; no timestamp or latest/PASS shortcut.
    for path in sorted(RUNS.glob('run_*/'+phase+'/result.json')):
        if path.parent.parent == root: continue
        try:
            if common.read(path).get('key') != key: continue
            result = verify_result(path, record, phase, dependencies, root)
            return path, result
        except Exception as error:
            audit(root, dict(phase=phase, candidate=str(path), reuse='INVALID', reason=str(error)))
    return None


def run_phase(root, record, phase, upstream):
    dependencies = {name: result['token'] for name, (_, result) in upstream.items()}
    # Recheck the actual upstream evidence before executing OR skipping the
    # next phase; a previous in-memory PASS is not a provenance certificate.
    checked_dependencies = {}
    for name, (path, _) in upstream.items():
        verify_result(path, record, name, checked_dependencies, root)
        checked_dependencies[name] = dependencies[name]
    reused = find_reusable(root, record, phase, dependencies)
    verify_inputs(record)
    if reused:
        path, result = reused
        folder = root/phase
        folder.mkdir()
        save_new(folder/'reference.json', dict(schema=SCHEMA, status='REUSED', result=str(path),
                 result_sha256=common.sha(path), key=result['key'], token=result['token'], dependencies=dependencies))
        print(phase.upper()+'=REUSED evidence='+str(path.parent), flush=True)
        return path, result, 'REUSED'
    folder = root/phase
    folder.mkdir()
    contract = phase_contract(record, phase, dependencies)
    save_new(folder/'plan.json', contract)
    save_new(folder/'started.json', dict(status='RUNNING', key=digest(contract)))
    build_root = upstream['build'][0].parent if phase != 'build' else None
    if phase == 'build': build(folder, record)
    elif phase == 'directed': directed(folder, record, build_root)
    else: system(folder, record, build_root)
    verify_inputs(record)
    review = review_dir(root, 'complete_'+phase)
    if phase == 'build': artifacts = verify_build(folder, review)
    else:
        # A simulator/checker must not silently mutate its upstream model.
        checked = verify_build(build_root, review)
        if checked != upstream['build'][1]['artifacts']:
            raise common.Stop('upstream model changed during '+phase)
        if phase == 'system':
            directed_path, directed_result = upstream['directed']
            original_build = Path(directed_result['upstream_paths']['build']).parent
            if verify_directed(directed_path.parent, original_build) != directed_result['artifacts']:
                raise common.Stop('upstream DIRECTED evidence changed during SYSTEM')
        artifacts = verify_directed(folder, build_root) if phase == 'directed' else verify_system(folder)
    result = dict(schema=SCHEMA, phase=phase, status='PASS', exit_code=0, key=digest(contract),
                  inputs_sha256=common.sha(root/'inputs.json'), dependencies=dependencies,
                  upstream_paths={name: str(path) for name, (path, _) in upstream.items()}, artifacts=artifacts)
    result['token'] = digest(dict(key=result['key'], artifacts=artifacts))
    save_new(folder/'result.json', result)
    save_new(folder/'seal.json', dict(result_sha256=common.sha(folder/'result.json')))
    print(phase.upper()+'=PASS', flush=True)
    return folder/'result.json', result, 'PASS'


def summary(root, source, states, status, action, failure_log='', reason='', *, diagnostics=None, raw_code=None):
    diagnostics = diagnostics or {}
    values = dict(STAGE3_ROOT=str(root), SOURCE_PROVENANCE=source,
                  BUILD=states['build'], DIRECTED=states['directed'], SYSTEM=states['system'],
                  STAGE3_STATUS=status, STAGE3_CLOSURE='NO',  # closure still requires evidence review
                  NEXT_ACTION=action, FAILURE_LOG=str(failure_log), FAILURE_REASON=reason.replace('\n', ' '),
                  RAW_EXIT_CODE=raw_code if raw_code is not None else '',
                  FAILURE_DIAGNOSTIC_COUNT=diagnostics.get('count', ''),
                  FAILURE_ERRORS_TEXT=diagnostics.get('text', ''),
                  FAILURE_ERRORS_JSON=diagnostics.get('json', ''),
                  ONE_USER_COMMAND='YES', FAIL_FAST='YES', SAFE_RESUME='YES',
                  STALE_RESULT_REUSE='NO', MANUAL_STAGE_SELECTION='NO')
    save_new(root/'summary.json', values)
    text = ''.join(key+'='+str(value)+'\n' for key, value in values.items())
    with (root/'summary.out').open('x') as stream: stream.write(text)
    print(text, end='', flush=True)


def main():
    RUNS.mkdir(parents=True, exist_ok=True)
    root = Path(tempfile.mkdtemp(prefix='run_', dir=RUNS))
    (root/'reviews').mkdir()
    states = dict.fromkeys(PHASES, 'NOT_RUN')
    record, phase, source, failure_log, reason = None, 'build', 'FAIL', '', ''
    diagnostics, raw_code = None, None
    code, status, action = 1, 'BUILD_FAILED', 'FIX_FAILURE_AND_RERUN_SAME_COMMAND'
    with (root/'runner.log').open('x') as log, contextlib.redirect_stdout(common.Tee(sys.stdout, log)), contextlib.redirect_stderr(common.Tee(sys.stderr, log)):
        print('STAGE3_ROOT='+str(root), flush=True)
        try:
            if len(sys.argv) != 1:
                raise common.Stop('Stage3 accepts no arguments; use stage3/stage3_run.sh', 2)
            os.chdir(REPO)
            with (RUNS/'runner.lock').open('a') as lock:
                try:
                    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
                except BlockingIOError:
                    raise common.Stop('another Stage3 invocation is active; rerun after it ends', 2)
                prepare_workload(root)
                record = inputs()
                save_new(root/'inputs.json', record)
                source = 'PASS'
                upstream = {}
                for phase in PHASES:
                    verify_inputs(record)
                    path, result, states[phase] = run_phase(root, record, phase, upstream)
                    upstream[phase] = (path, result)
                    verify_inputs(record)
                code, status, action = 0, 'VALIDATION_PASS', 'REVIEW_VALIDATION_EVIDENCE'
        except BaseException as error:
            code = error.code if isinstance(error, common.Stop) else 130 if isinstance(error, KeyboardInterrupt) else 143 if isinstance(error, SystemExit) else 1
            states[phase] = 'FAIL'
            status = phase.upper()+'_FAILED'
            reason = str(error) or type(error).__name__
            failure_log = getattr(error, 'log', None) or root/'failure.log'
            diagnostics = getattr(error, 'diagnostics', None)
            raw_code = getattr(error, 'raw_code', None)
            with (root/'failure.log').open('x') as out:
                traceback.print_exc(file=out)
            save_new(root/'failure.json', dict(phase=phase, exit_code=code, raw_exit_code=raw_code,
                     reason=reason, log=str(failure_log), first_error=getattr(error, 'first_error', None),
                     diagnostics=diagnostics))
            if record is not None:
                try: verify_inputs(record)
                except BaseException: source, status = 'FAIL', 'INPUTS_CHANGED'
        summary(root, source, states, status, action, failure_log, reason,
                diagnostics=diagnostics, raw_code=raw_code)
    return code


if __name__ == '__main__':
    signal.signal(signal.SIGTERM, lambda *_: sys.exit(143))
    sys.exit(main())
