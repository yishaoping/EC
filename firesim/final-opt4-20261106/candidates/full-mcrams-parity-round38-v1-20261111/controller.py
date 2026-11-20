#!/usr/bin/python3
"""Run the completed, source-bound frozen MCRams model on the reference ELF.

Only CPU metasimulation. Compare finite captured observations, never promote
them to universal full-state equivalence, full Opt4 FIT, or an FPGA sample.
"""
from pathlib import Path
import datetime
import fcntl
import hashlib
import importlib.util
import json
import os
import re
import resource
import shutil
import signal
import subprocess
import sys
import time
import traceback

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
C = Path(__file__).resolve().parent
M = D / 'cycleprecise-frozen-full-mcrams-metasim-round36-v2-20261111'
R = D / 'cycleprecise-frozen-full-metasim-sample-r1-20261111'
A = D / 'build-logs/Opt4-full-gg-package-analysis-round37-v1-20261111'
PREP = D / 'build-logs/Opt4-round37-two-route-evidence-v1-20261111/mcrams-trace-comparison-preparation.json'
O = D / 'cycleprecise-frozen-full-mcrams-parity-round38-v1-20261111'
S = D / 'Opt4-route-a-full-mcrams-parity-round38-v1-state.json'
PARSER = W / 'candidates/full-gg-package-analysis-round37-v1-20261111/controller.py'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
NAME = 'full-mcrams-parity-r38-v1-8491167d'
ST = {}


def read(path):
    return json.loads(Path(path).read_text())


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(4 * 2**20), b''):
            h.update(block)
    return h.hexdigest()


def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def save(path, value):
    path = Path(path)
    tmp = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with tmp.open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())
    os.replace(tmp, path)


def policy():
    p = read(U / 'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE
    assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
    assert p['native_paused'] and not p['fpga_access']
    assert p['board_allowlist'] == ['0000:21:00.0']
    return p


def ident(pid):
    try:
        fields = Path(f'/proc/{pid}/stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, start_ticks=fields[19],
                    host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError:
        return {}


def update(**kwargs):
    ST.update(kwargs, updated_utc=now())
    save(S, ST)


def prepare():
    policy()
    assert not O.exists() and not S.exists() and not (C / 'plan.json').exists()
    assert not (U / 'requests' / (NAME + '.json')).exists()
    compiled, model_plan = read(M / 'result.json'), read(M / 'build-plan.json')
    reference, rb, prepared = read(R / 'result.json'), read(R / 'binding.json'), read(PREP)
    assert compiled['status'] == 'BUILT_FULL_FROZEN_MCRAMS_PARITY_AND_RUNTIME_PENDING'
    assert compiled['returncode'] == 0 and not compiled['runtime_started']
    assert compiled['functional_baseline'] == model_plan['functional_baseline'] == rb['functional_baseline'] == BASE
    assert sha(M / 'build-plan.json') == compiled['build_plan_sha256'] == prepared['build_plan_sha256']
    assert model_plan['platform_config'] == 'MCRams_DacXilinxAlveoConfig'
    assert model_plan['memory_annotations'] == 10 and model_plan['original_target_function_and_cycles_unmodified']
    assert model_plan['target_fir_sha256'] == prepared['target_fir_sha256']
    assert model_plan['target_annotations_sha256'] == prepared['target_annotations_sha256']
    assert compiled['host_rtl_sha256'] == prepared['mcrams_host_rtl_sha256']
    assert reference['returncode'] == 0 and reference['output_correctness'] and reference['stop_cause'] is None
    assert rb['args'] == prepared['exact_reference_runtime_args']
    assert sha(R / 'binding.json') == prepared['reference_binding_sha256']
    binary = Path(compiled['binary'])
    assert sha(binary) == compiled['binary_sha256']
    elf = Path(next(a[len('+prog0='):] for a in rb['args'] if a.startswith('+prog0=')))
    assert sha(elf) == rb['elf_sha256'] == prepared['software_elf_sha256']
    assert (rb['host_timeout_seconds'], rb['owned_log_budget_bytes'], rb['target_cycle_limit']) == (10800, 4 * 2**30, 5000000)
    args = [str(binary) if i == 0 else '+print-file=' + str(O / 'rtl-prints-')
            if a.startswith('+print-file=') else a for i, a in enumerate(rb['args'])]
    # The executable and private output prefix are the only substitutions.
    assert args[1:] == [('+print-file=' + str(O / 'rtl-prints-')) if a.startswith('+print-file=') else a for a in rb['args'][1:]]
    files = [C / 'controller.py', PARSER, PREP, M / 'result.json', M / 'build-plan.json',
             R / 'binding.json', R / 'result.json', R / 'rtl-prints-0', R / 'rtl-prints-1',
             A / 'result.json', A / 'checker-local-events.json', A / 'stdout-selected-rows.json', binary, elf]
    # Keep original generated ABI and source receipts bound; no copied plain ABI.
    files += sorted((M / 'host').glob('FireSim-generated.*h'))
    files += sorted((M / 'external-libs').iterdir())
    originals = {str(p): sha(p) for p in files}
    for name in ['rtl-prints-0', 'rtl-prints-1']:
        assert originals[str(R / name)] == reference['files'][str(R / name)]
    for name, digest in prepared['observed_reference_files'].items():
        if name in originals:
            assert originals[name] == digest
    plan = dict(schema='ec-opt4-full-mcrams-finite-parity-plan/1', functional_baseline=BASE,
                args=args, reference_args=rb['args'], original_inputs=originals,
                binary_sha256=compiled['binary_sha256'], elf_sha256=rb['elf_sha256'],
                source_id=model_plan['source_id'], host_rtl_sha256=compiled['host_rtl_sha256'],
                target_fir_sha256=model_plan['target_fir_sha256'],
                target_annotations_sha256=model_plan['target_annotations_sha256'],
                target_cycle_limit=rb['target_cycle_limit'], host_timeout_seconds=rb['host_timeout_seconds'],
                owned_log_budget_bytes=rb['owned_log_budget_bytes'],
                minimum_memory_gib=96, minimum_disk_gib=100, address_space_limit_gib=64,
                application_expected_output=rb['application_expected_output'],
                scope='CPU same-ELF finite captured-observation comparison only',
                full_observation_parity_passed=False, production_admission=False, whole_fit=False,
                fpga_access=False, created_utc=now())
    save(C / 'plan.json', plan)
    capsule = C / 'evidence'; capsule.mkdir()
    bound, copies = {}, {}
    for name, digest in originals.items():
        p = Path(name)
        if p.resolve().is_relative_to(W):
            bound[name] = digest
        else:
            q = capsule / (digest[:16] + '-' + p.name)
            if not q.exists():
                shutil.copy2(p, q)
            assert sha(q) == digest
            bound[str(q)] = digest
            copies[name] = str(q)
    save(C / 'evidence-copies.json', copies)
    for p in [C / 'plan.json', C / 'evidence-copies.json']:
        bound[str(p)] = sha(p)
    request = dict(action='cpu_job', spec=dict(name=NAME, kind='module', cwd=str(C),
                   argv=['/usr/bin/python3', str(C / 'controller.py'), '--run'], inputs=bound,
                   outputs=[str(O / 'result.json')], checkpoints=[str(S)]))
    save(C / 'request.json', request)
    print(json.dumps(dict(prepared=str(C / 'plan.json'), request=str(C / 'request.json'),
                          input_files=len(bound), runtime_started=False)))


def parse_stdout(log):
    records, faults = [], []
    h = hashlib.sha256()
    metrics = []
    target_keys = ('[ROI]', '[OUTPUT]', '[APP]', '[COMPUTATION]', '[END]')
    metric_keys = ('*** PASSED ***', 'Target Cycles Emulated:', 'FMR:', 'Wallclock Time Elapsed:',
                   'Host Frequency:', 'Effective Target Frequency:', '- Verilator: cpu')
    with log.open('rb') as f:
        for line in f:
            h.update(line)
            text = line.decode(errors='replace').rstrip('\r\n')
            if any(k in text for k in target_keys):
                records.append(text)
            if any(k in text for k in metric_keys):
                metrics.append(text)
            if re.search(r'Assertion failed|%Error|\*\*\* FAILED|status=FAIL|Simulator deadlock detected', text):
                faults.append(text)
    return dict(sha256=h.hexdigest(), target_rows=records, metrics=metrics, faults=faults)


def compare_outputs(plan, rc, cause, host_wall, peak_rss):
    policy()
    stdout = parse_stdout(O / 'host.log')
    save(O / 'stdout-selected-rows.json', stdout)
    reference_rows = [r['text'] for r in read(A / 'stdout-selected-rows.json')['rows']
                      if any(k in r['text'] for k in ('[ROI]', '[OUTPUT]', '[APP]', '[COMPUTATION]', '[END]'))]
    rows_match = stdout['target_rows'] == reference_rows
    ps = importlib.util.spec_from_file_location('original_gg_parser', PARSER)
    parser = importlib.util.module_from_spec(ps); ps.loader.exec_module(parser)
    stream_comparison = {}
    for name in ['rtl-prints-0', 'rtl-prints-1']:
        path = O / name
        actual = sha(path) if path.exists() else None
        expected = plan['original_inputs'][str(R / name)]
        stream_comparison[name] = dict(sha256=actual, expected_sha256=expected, exact_match=actual == expected)
    local_pass, events, parser_error = False, [], None
    try:
        events, begins, results = parser.parse_prints((O / 'rtl-prints-1').read_text())
        local_pass = events == read(A / 'checker-local-events.json')
    except Exception as error:
        parser_error = repr(error)
    save(O / 'checker-local-events.json', events)
    matches = (rc == 0 and cause is None and not stdout['faults'] and rows_match and local_pass
               and all(v['exact_match'] for v in stream_comparison.values()))
    correctness = (rc == 0 and cause is None and not stdout['faults']
                   and any(plan['application_expected_output'] in r for r in stdout['target_rows'])
                   and '[COMPUTATION] status=PASS scope=official_serial_kernel' in stdout['target_rows']
                   and '[END] hart=0 status=PASS' in stdout['target_rows'])
    negative_tests = {'different_clock_header': False, 'shifted_target_cycle': False,
                      'missing_target_row': False, 'changed_target_value': False}
    # Comparison gate mutation tests do not rerun or alter the simulator.
    if local_pass:
        changed = [dict(e) for e in events]; changed[0]['cycle'] += 1
        negative_tests['shifted_target_cycle'] = changed != read(A / 'checker-local-events.json')
        text = (O / 'rtl-prints-1').read_text()
        try:
            parser.parse_prints(text.replace('1/2 of Base Clock', '1/1 of Base Clock', 1))
        except AssertionError:
            negative_tests['different_clock_header'] = True
    if rows_match and reference_rows:
        negative_tests['missing_target_row'] = reference_rows[:-1] != reference_rows
        negative_tests['changed_target_value'] = [reference_rows[0] + ' MUTATED'] + reference_rows[1:] != reference_rows
    status = ('PASS_SAME_ELF_FINITE_CAPTURED_TARGET_CYCLE_OBSERVATIONS_NOT_FULL_EQUIVALENCE' if matches
              else 'MCRAMS_WORKLOAD_OR_CAPTURED_PARITY_FAILED_WITH_EVIDENCE')
    result = dict(schema='ec-opt4-full-mcrams-finite-parity-result/1', status=status, functional_baseline=BASE,
                  returncode=rc, stop_cause=cause, host_wall_seconds=host_wall,
                  child_peak_rss_kib=peak_rss, output_correctness=correctness,
                  captured_observation_parity_passed=matches, exact_roi_and_output_rows=rows_match,
                  exact_print_streams=stream_comparison, checker_local_event_count=len(events),
                  exact_checker_local_event_values_and_cycles=local_pass, parser_error=parser_error,
                  comparison_mutations_rejected=negative_tests, stdout=stdout,
                  plan_sha256=sha(C / 'plan.json'), source_id=plan['source_id'],
                  binary_sha256=plan['binary_sha256'], elf_sha256=plan['elf_sha256'],
                  target_fir_sha256=plan['target_fir_sha256'], target_annotations_sha256=plan['target_annotations_sha256'],
                  host_rtl_sha256=plan['host_rtl_sha256'], completed_utc=now(),
                  fpga_access=False, formal_fpga_sample=False, whole_fit=False,
                  full_observation_parity_passed=False, production_admission=False,
                  limitations=['Finite captured outputs do not cover all original outputs or state',
                               'BOOM result acceptance/release and complete drain are unobserved',
                               'No complete real application payload trace or strict checkerDone-minusBOOMDone',
                               'Host implementation debug stdout may repeat across host stalls; exact comparison uses captured target print streams and application records',
                               'No FPGA execution, physical implementation or whole-system area admission'])
    save(O / 'result.json', result)
    update(status=status, child={}, result=str(O / 'result.json'), process_exited=True)


def run():
    policy()
    assert not O.exists() and not S.exists(), 'Adopt existing run; never replay partial output'
    plan = read(C / 'plan.json')
    for p, digest in plan['original_inputs'].items():
        assert sha(p) == digest, ('changed_bound_input', p)
    O.mkdir()
    lock = (O / 'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    ST.update(schema='ec-opt4-full-mcrams-finite-parity-run/1', **ident(os.getpid()),
              functional_baseline=BASE, fpga_access=False, formal_fpga_sample=False, started_utc=now())
    update(status='WAITING_CPU_MEMORY_DISK_GUARDS')
    while True:
        policy()
        available = int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines()
                             if l.startswith('MemAvailable:')))
        if available >= plan['minimum_memory_gib'] * 2**20 and shutil.disk_usage(O).free >= plan['minimum_disk_gib'] * 2**30:
            break
        time.sleep(300)
    save(O / 'binding.json', plan)
    resource.setrlimit(resource.RLIMIT_AS, (plan['address_space_limit_gib'] * 2**30,) * 2)
    started = time.monotonic(); cause = None
    with (O / 'host.log').open('xb', buffering=0) as log:
        child = subprocess.Popen(['/usr/bin/stdbuf', '-oL', '-eL', *plan['args']], cwd=O,
                                 stdin=subprocess.DEVNULL, stdout=log, stderr=subprocess.STDOUT,
                                 start_new_session=True, env={**os.environ, 'LD_LIBRARY_PATH': '', 'OMP_NUM_THREADS': '2'})
        update(status='RUNNING_SAME_ELF_FULL_MCRAMS_CAPTURED_PARITY', child=ident(child.pid))
        while True:
            try:
                rc = child.wait(timeout=30)
            except subprocess.TimeoutExpired:
                rc = None
            policy()
            total = sum(p.stat().st_size for p in O.iterdir() if p.is_file())
            hb = O / 'heartbeat.csv'
            tail = hb.read_text().splitlines()[-1] if hb.exists() else None
            update(host_wall_seconds=time.monotonic() - started, owned_log_bytes=total,
                   heartbeat_last_row=tail, process_exited=rc is not None)
            os.fsync(log.fileno())
            if rc is not None:
                break
            if total > plan['owned_log_budget_bytes']:
                cause = 'OWNED_LOG_BUDGET_EXCEEDED'
            if time.monotonic() - started > plan['host_timeout_seconds']:
                cause = 'HOST_TIMEOUT'
            if cause:
                os.killpg(child.pid, signal.SIGTERM)
                try:
                    rc = child.wait(timeout=20)
                except subprocess.TimeoutExpired:
                    os.killpg(child.pid, signal.SIGKILL); rc = child.wait()
                break
    elapsed = time.monotonic() - started
    peak = resource.getrusage(resource.RUSAGE_CHILDREN).ru_maxrss
    update(status='ANALYZING_COMPLETED_MCRAMS_CAPTURED_OBSERVATIONS', child={}, process_exited=True,
           host_wall_seconds=elapsed, returncode=rc, stop_cause=cause, child_peak_rss_kib=peak)
    compare_outputs(plan, rc, cause, elapsed, peak)


if __name__ == '__main__':
    try:
        {'--prepare': prepare, '--run': run}[sys.argv[1]]()
    except BaseException as error:
        if O.exists():
            save(O / 'failure.json', dict(error=repr(error), traceback=traceback.format_exc(), utc=now()))
            update(status='FAILED_WITH_EVIDENCE', error=repr(error))
        raise
