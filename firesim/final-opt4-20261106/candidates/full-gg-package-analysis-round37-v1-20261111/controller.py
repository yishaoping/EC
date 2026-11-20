#!/usr/bin/python3
"""Authenticate and analyze completed original GG evidence, without rerunning it.

The synthesized RESULT print observes local queue enqueue. It does not observe
BOOM dequeue, release, architectural execution completion, or full-system parity.
"""
from pathlib import Path
import collections
import datetime
import difflib
import fcntl
import hashlib
import json
import math
import os
import re
import resource
import shutil
import statistics
import sys

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
C = Path(__file__).resolve().parent
R = D / 'cycleprecise-frozen-full-metasim-sample-r1-20261111'
O = D / 'build-logs/Opt4-full-gg-package-analysis-round37-v1-20261111'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
NAME = 'full-gg-package-analysis-r37-v1-8491167d'
CORE = W / 'C4/chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala'
FROZEN_CORE = Path('/data1/gzh/EC-backups/opt4-final-performance-20261106/source/chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala')
HEADER = '# Clock Domain: tileClockGroup_tile_1, Relative Frequency: 1/2 of Base Clock'
BEGIN = re.compile(r'CYCLE:\s+(\d+) EC_OPT4_PACKAGE_BEGIN hart=(\d+) seq=([0-9a-f]+) satp=([0-9a-f]+) prv=(\d+)')
RESULT = re.compile(r'CYCLE:\s+(\d+) EC_OPT4_PACKAGE_RESULT hart=(\d+) seq=([0-9a-f]+) status=(\d+) full_compare=(\d+) cancelled=(\d+)')


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


def save(p, value):
    # Every artifact in this analysis version is write-once.
    with Path(p).open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')


def policy():
    p = read(U / 'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE
    assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
    assert p['native_paused'] and not p['fpga_access']
    assert p['board_allowlist'] == ['0000:21:00.0']
    return p


def parse_prints(text):
    lines = text.splitlines()
    assert lines and lines[0] == HEADER, 'unrecognized checker clock domain'
    begins, results, live, events = {}, {}, {}, []
    previous_cycle = -1
    last_sequence = collections.defaultdict(int)
    for line_number, line in enumerate(lines[1:], 2):
        if not line.strip():
            continue
        a, b = BEGIN.fullmatch(line), RESULT.fullmatch(line)
        assert a or b, ('unparsed print', line_number)
        fields = list((a or b).groups())
        cycle, hart, seq = int(fields[0]), int(fields[1]), int(fields[2], 16)
        assert 1 <= hart <= 4 and seq > 0, 'invalid package identity'
        assert cycle >= previous_cycle, 'nonmonotonic checker clock'
        previous_cycle = cycle
        key = (hart, seq)
        if a:
            assert key not in begins, 'duplicate begin'
            assert hart not in live, 'checker began another package before local result'
            assert seq > last_sequence[hart], 'nonmonotonic hart sequence'
            last_sequence[hart] = seq
            begins[key] = cycle
            live[hart] = seq
            event = dict(event='CHECKER_NEW_PACKAGE', cycle=cycle, hart=hart, seq=seq,
                         satp=int(fields[3], 16), prv=int(fields[4]))
        else:
            status, full, cancelled = map(int, fields[3:])
            assert key in begins and live.get(hart) == seq, 'result without owned begin'
            assert key not in results, 'duplicate result'
            assert status == 0 and full == 1 and cancelled == 0, 'local result not full PASS'
            assert cycle >= begins[key], 'result before begin'
            results[key] = cycle
            del live[hart]
            event = dict(event='LOCAL_RESULT_QUEUE_ENQUEUE', cycle=cycle, hart=hart,
                         seq=seq, status=status, full_compare=full, cancelled=cancelled)
        events.append(event)
    assert begins and not live and begins.keys() == results.keys(), 'unmatched local packages'
    seqs = sorted(seq for _, seq in begins)
    assert len(set(seqs)) == len(seqs), 'global sequence reused'
    assert seqs == list(range(1, len(seqs) + 1)), 'observed package sequence gap'
    return events, begins, results


def parser_negatives(text):
    lines = text.splitlines()
    ri = next(i for i, s in enumerate(lines) if 'PACKAGE_RESULT' in s)
    bi = next(i for i, s in enumerate(lines) if 'PACKAGE_BEGIN' in s)
    cases = {
        'missing_result': '\n'.join(lines[:ri] + lines[ri + 1:]),
        'missing_begin': '\n'.join(lines[:bi] + lines[bi + 1:]),
        'duplicate_begin': '\n'.join(lines[:bi] + [lines[bi]] + lines[bi:]),
        'duplicate_result': '\n'.join(lines[:ri] + [lines[ri]] + lines[ri:]),
        'failed_status': text.replace('status=0', 'status=1', 1),
        'missing_full_compare': text.replace('full_compare=1', 'full_compare=0', 1),
        'cancelled_result': text.replace('cancelled=0', 'cancelled=1', 1),
        'wrong_timebase': text.replace('1/2 of Base Clock', '1/1 of Base Clock', 1),
        'unknown_event': text + '\nCYCLE: 999999 EC_OPT4_PACKAGE_UNKNOWN\n',
    }
    outcomes = {}
    for name, mutant in cases.items():
        assert mutant != text
        try:
            parse_prints(mutant)
        except AssertionError as exc:
            outcomes[name] = dict(rejected=True, reason=str(exc))
        else:
            raise AssertionError(('parser accepted corrupted actual trace', name))
    return outcomes


def summarize(values):
    v = sorted(values)
    n = len(v)
    return dict(n=n, sum=sum(v), mean=statistics.mean(v), median=statistics.median(v),
                minimum=v[0], maximum=v[-1], p95=v[math.ceil(.95*n)-1],
                p99=v[math.ceil(.99*n)-1], histogram=dict(sorted(collections.Counter(v).items())),
                units='checker-domain target cycles', percentiles='nearest rank')


def prepare():
    policy()
    assert not (C / 'manifest.json').exists(), 'immutable prepared capsule'
    e = C / 'evidence'
    e.mkdir()
    originals = [R / 'binding.json', R / 'result.json', R / 'rtl-prints-0',
                 R / 'rtl-prints-1', CORE, FROZEN_CORE,
                 D / 'cycleprecise-frozen-full-metasim-r1-20261111/binding.json',
                 D / 'cycleprecise-frozen-full-metasim-follow-r3-20261111/binding.json']
    manifest = dict(functional_baseline=BASE, originals={}, copies={})
    inputs = {str(C / 'controller.py'): sha(C / 'controller.py')}
    for i, p in enumerate(originals):
        q = e / (str(i) + '-' + p.name)
        shutil.copy2(p, q)
        h = sha(q)
        manifest['originals'][str(p)] = h
        manifest['copies'][str(p)] = str(q)
        inputs[str(q)] = h
    r = read(R / 'result.json')
    assert r['status'] == 'APPLICATION_OUTPUT_MATCH_PROTOCOL_PENDING'
    manifest['raw_log'] = dict(path=str(R / 'host.log'), sha256=r['files'][str(R / 'host.log')])
    manifest['scope'] = 'analysis only; observe local enqueue, never infer BOOM acceptance'
    save(C / 'manifest.json', manifest)
    inputs[str(C / 'manifest.json')] = sha(C / 'manifest.json')
    req = dict(action='cpu_job', spec=dict(name=NAME, kind='analysis', cwd=str(C),
               argv=['/usr/bin/python3', str(C / 'controller.py'), '--analyze'],
               inputs=inputs, outputs=[str(O / 'result.json')],
               checkpoints=[str(O / 'state.json')]))
    save(C / 'request.json', req)
    print(json.dumps(dict(request=str(C / 'request.json'), inputs=len(inputs), runtime_started=False)))


def analyze():
    policy()
    assert not O.exists(), 'preserve partial/failed analysis; create another version'
    O.mkdir()
    lock = (O / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    resource.setrlimit(resource.RLIMIT_AS, (2 * 2**30, 2 * 2**30))
    manifest = read(C / 'manifest.json')
    for p, h in manifest['originals'].items():
        assert sha(p) == h == sha(manifest['copies'][p]), ('source changed', p)
    process = Path('/proc/self/stat').read_text().rsplit(')', 1)[1].split()
    save(O / 'state.json', dict(status='ANALYZING_COMPLETED_GG_PRINTS', pid=os.getpid(),
         start_ticks=process[19], host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
         functional_baseline=BASE, fpga_access=False, started_utc=now()))
    b, r = read(R / 'binding.json'), read(R / 'result.json')
    assert b['functional_baseline'] == r['functional_baseline'] == BASE
    assert r['returncode'] == 0 and r['output_correctness'] and not r['fault_marker']
    assert r['stop_cause'] is None and not r['checker_validation']
    parent = D / 'cycleprecise-frozen-full-metasim-follow-r3-20261111/binding.json'
    assert sha(parent) == b['probe_binding_sha256']
    pb = read(parent)
    assert b['binary_sha256'] == pb['binary_sha256'] and b['elf_sha256'] == pb['elf_sha256']
    assert sha(b['args'][0]) == b['binary_sha256']
    elf = next(x[len('+prog0='):] for x in b['args'] if x.startswith('+prog0='))
    assert sha(elf) == b['elf_sha256']
    core = CORE.read_text()
    for required in ['when (new_package)', 'val package_result_fire = package_result_queue.io.enq.fire',
                     'when (package_result_fire)', 'EC_OPT4_PACKAGE_BEGIN', 'EC_OPT4_PACKAGE_RESULT']:
        assert required in core, ('print semantics changed', required)
    diff = ''.join(difflib.unified_diff(FROZEN_CORE.read_text().splitlines(True),
                   core.splitlines(True), fromfile=str(FROZEN_CORE), tofile=str(CORE)))
    with (O / 'frozen-to-firesim-core-observation.diff').open('x') as f:
        f.write(diff)
    print_text = (R / 'rtl-prints-1').read_text()
    assert sha(R / 'rtl-prints-1') == r['files'][str(R / 'rtl-prints-1')]
    events, begins, results = parse_prints(print_text)
    negatives = parser_negatives(print_text)
    save(O / 'parser-negative-tests.json', negatives)
    save(O / 'checker-local-events.json', events)
    intervals = {f'{hart}:{seq}': results[(hart, seq)] - begin
                 for (hart, seq), begin in sorted(begins.items())}
    save(O / 'checker-local-intervals.json', dict(intervals=intervals,
         statistics=summarize(list(intervals.values())),
         event_definition='CHECKER_NEW_PACKAGE to LOCAL_RESULT_QUEUE_ENQUEUE',
         clock_domain=HEADER, conversion='one printed checker tick = two fastest/base target ticks; no CSR epoch alignment inferred'))
    # Stream and authenticate the large original stdout once, retaining selected
    # rows only. Neither artifacts nor original producer results are rewritten.
    markers = []
    h = hashlib.sha256()
    remainder = b''
    line_number = 0
    keys = [b'[APP]', b'[ROI]', b'[OUTPUT]', b'[COMPUTATION]', b'[END]',
            b'*** PASSED ***', b'Target Cycles Emulated:', b'FMR:',
            b'Wallclock Time Elapsed:', b'Host Frequency:', b'Effective Target Frequency:',
            b'- Verilator: cpu', b'Assertion failed', b'%Error', b'*** FAILED',
            b'status=FAIL', b'Simulator deadlock detected']
    stat_before = (R / 'host.log').stat()
    with (R / 'host.log').open('rb') as f:
        for block in iter(lambda: f.read(4 * 2**20), b''):
            h.update(block)
            lines = (remainder + block).split(b'\n')
            remainder = lines.pop()
            for line in lines:
                line_number += 1
                if any(k in line for k in keys):
                    markers.append(dict(line=line_number, text=line.decode(errors='replace')))
    if remainder:
        line_number += 1
        if any(k in remainder for k in keys):
            markers.append(dict(line=line_number, text=remainder.decode(errors='replace')))
    stat_after = (R / 'host.log').stat()
    assert (stat_before.st_size, stat_before.st_mtime_ns) == (stat_after.st_size, stat_after.st_mtime_ns)
    assert h.hexdigest() == manifest['raw_log']['sha256'], 'raw stdout changed'
    selected = '\n'.join(x['text'] for x in markers)
    faults = [x for x in markers if any(k in x['text'] for k in
              ['Assertion failed', '%Error', '*** FAILED', 'status=FAIL', 'Simulator deadlock detected'])]
    assert not faults, faults
    apps = re.findall(r'\[APP\] protected=(\d+) start=(\d+) end=(\d+) cycles=(\d+) instret=(\d+) session_stop=(\d+)', selected)
    assert len(apps) == 1 and [list(apps[0])] == r['roi_records']
    protected, begin, end, cycles, instret, session_stop = map(int, apps[0])
    assert protected == 1 and end - begin == cycles and session_stop >= end
    assert b['application_expected_output'] in selected
    assert '[COMPUTATION] status=PASS' in selected and '[END] hart=0 status=PASS' in selected
    emulated = int(re.search(r'Target Cycles Emulated:\s+(\d+)', selected).group(1))
    elapsed = float(re.search(r'Wallclock Time Elapsed:\s+([\d.]+) s', selected).group(1))
    fmr = float(re.search(r'FMR:\s+([\d.]+)', selected).group(1))
    cpustats = re.search(r'- Verilator: cpu ([\d.]+) s on (\d+) threads; allocated (\d+) MB', selected)
    save(O / 'stdout-selected-rows.json', dict(log=str(R / 'host.log'), sha256=h.hexdigest(),
         bytes=stat_before.st_size, total_lines=line_number, rows=markers))
    out = dict(schema='ec-original-full-gg-checker-evidence/1',
         status='PASS_APPLICATION_AND_131_LOCAL_CHECKER_RESULTS' if len(begins) == 131 else 'PASS_APPLICATION_AND_LOCAL_CHECKER_RESULTS',
         functional_baseline=BASE, source_id=read(D / 'cycleprecise-frozen-full-metasim-r1-20261111/binding.json')['source_id'],
         kind='FULL_ORIGINAL_GOLDENGATE_CPU_METASIM_NOT_FPGA',
         original_result=str(R / 'result.json'), original_result_sha256=sha(R / 'result.json'),
         binding_sha256=sha(R / 'binding.json'), input_elf_sha256=b['elf_sha256'],
         binary_sha256=b['binary_sha256'],
         software_profile=b['software_profile'], output_correctness=True,
         roi=dict(start=begin, end=end, cycles=cycles, instret=instret,
                  session_stop=session_stop, timebase='main hart software rdcycle; no checker print epoch alignment inferred'),
         local_checker=dict(begin_count=len(begins), result_enqueue_count=len(results),
              full_pass=len(results), failed=0, cancelled=0, unmatched_begins=0,
              duplicate_results=0, harts=dict(collections.Counter(h for h, _ in begins)),
              interval_statistics=summarize(list(intervals.values())), timebase=HEADER),
         boom_result_acceptance='UNOBSERVED: local enq print is not BOOM result dequeue/release',
         generated_package_count='UNOBSERVED: checker new_package does not observe BOOM allocation',
         result_path_full_drain='NOT_ESTABLISHED: matched local enqueue records alone do not prove end-to-end drain',
         strict_checker_done_minus_boom_done='UNAVAILABLE: no matched BOOM execution-complete event',
         complete_payload_trace=False, full_mcrams_parity=False,
         full_opt4_fit=False, formal_fpga_sample=False, fpga_access=False,
         runtime=dict(emulated_fastest_target_cycles=emulated, model_elapsed_seconds=elapsed,
              measured_target_cycles_per_second=emulated/elapsed, reported_fmr=fmr,
              controller_wall_seconds=r['host_wall_seconds'],
              cpu_seconds=float(cpustats[1]), host_threads=int(cpustats[2]),
              verilator_reported_allocated_mb=int(cpustats[3]), allocation_is_not_peak_rss=True),
         negative_cases_rejected=len(negatives),
         scope_limits=['Finite original-system CPU run; no universal formal equivalence.',
              'Separate from original 136-package RTL harness run: memory environment and event coverage differ.',
              'No Native slowdown, architectural restart, all-required-output parity, or FPGA certification.'],
         files={str(x): sha(x) for x in O.iterdir() if x.is_file()}, ended_utc=now())
    save(O / 'result.json', out)
    state = read(O / 'state.json')
    state.update(status=out['status'], result=str(O / 'result.json'),
                 result_sha256=sha(O / 'result.json'), ended_utc=now())
    temp = O / '.state-final.json'
    save(temp, state)
    os.replace(temp, O / 'state.json')
    print(json.dumps({k: out[k] for k in ['status', 'roi', 'local_checker', 'runtime', 'negative_cases_rejected']}))


if __name__ == '__main__':
    if sys.argv[1:] == ['--prepare']:
        prepare()
    elif sys.argv[1:] == ['--analyze']:
        try:
            analyze()
        except Exception as exc:
            if O.exists() and not (O / 'failure.json').exists():
                save(O / 'failure.json', dict(status='FAILED_WITH_EVIDENCE',
                     error=repr(exc), ended_utc=now(), fpga_access=False))
            raise
    else:
        raise SystemExit('Use --prepare or broker --analyze.')
