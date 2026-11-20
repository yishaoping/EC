#!/usr/bin/python3
"""Read-only verification of a completed frozen GG sample and its raw stream."""
import collections
import fcntl
import gzip
import hashlib
import json
import os
from pathlib import Path
import re
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
O = D/'build-logs/Opt4-blackscholes-result-audit-round52-v2-20261112'
S = D/'Opt4-blackscholes-result-audit-round52-v2-state.json'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, now, read, save, sha


def join(events, prints):
    allocations, accepted, begins, results = {}, {}, {}, {}
    headers, endings = [], []
    for e in events:
        if e['kind'] == 'HEADER':
            assert e['functional_baseline'] == BASE
            headers.append(e)
            continue
        if e['kind'] == 'END':
            endings.append(e)
            continue
        assert e['kind'] in ['BOOM_ALLOC', 'BOOM_RESULT_ACCEPTED']
        seq = e['package_seq']
        target = allocations if e['kind'] == 'BOOM_ALLOC' else accepted
        assert seq not in target, ('duplicate', e['kind'], seq)
        target[seq] = e
    for line in prints.splitlines():
        if 'EC_OPT4_PACKAGE_BEGIN ' in line:
            m = re.search(r'CYCLE:\s*(\d+) EC_OPT4_PACKAGE_BEGIN hart=(\d+) seq=([0-9a-fA-F]+)', line)
            assert m
            cycle, hart, seq = int(m[1]), int(m[2]), int(m[3], 16)
            assert seq not in begins
            begins[seq] = dict(cycle=cycle, hart=hart)
        elif 'EC_OPT4_PACKAGE_RESULT ' in line:
            m = re.search(r'CYCLE:\s*(\d+) EC_OPT4_PACKAGE_RESULT hart=(\d+) seq=([0-9a-fA-F]+) status=(\d+) full_compare=(\d+) cancelled=(\d+)', line)
            assert m
            cycle, hart, seq, status, full, cancel = int(m[1]), int(m[2]), int(m[3], 16), int(m[4]), int(m[5]), int(m[6])
            assert seq not in results and status == 0 and full == 1 and cancel == 0
            results[seq] = dict(cycle=cycle, hart=hart)
    assert len(headers) == len(endings) == 1
    end = endings[0]
    assert end['sample_errors'] == end['failed'] == end['cancelled'] == 0
    assert end['allocations'] == len(allocations)
    assert end['accepted'] == end['passed'] == len(accepted)
    assert allocations and set(allocations) == set(accepted) == set(begins) == set(results)
    counts = collections.Counter()
    for seq, alloc in allocations.items():
        a, b, r = accepted[seq], begins[seq], results[seq]
        assert a['status'] == 0 and a['checker'] == b['hart'] == r['hart']
        assert b['hart'] in [1, 2, 3, 4]
        assert alloc['fastest_target_cycle'] <= a['fastest_target_cycle']
        assert b['cycle'] <= r['cycle']
        counts[str(b['hart'])] += 1
    return dict(packages=len(allocations), per_checker=dict(sorted(counts.items())),
                pending=0, last_boom_accepted=max(e['boom_csr_cycle'] for e in accepted.values()))


def main():
    p = read(U/'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access'] and not p['functional_extensions_allowed']
    plan = read(C/'plan.json')
    assert all(sha(q) == h for q, h in plan['inputs'].items())
    O.mkdir(parents=True, exist_ok=True)
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    if (O/'complete.json').exists():
        assert read(O/'complete.json')['result_sha256'] == sha(O/'result.json')
        return
    assert not S.exists(), 'Preserve partial audit; versioned recovery required'
    assert plan['cpu'] in os.sched_getaffinity(0)
    os.sched_setaffinity(0, {plan['cpu']})
    state = dict(schema='ec-frozen-blackscholes-result-audit/1', **identity(),
        fpga_access=False, functional_baseline=BASE)
    save(S, {**state, 'status': 'VERIFYING_COMPLETED_SAMPLE_RAW_STREAM_AND_PACKAGE_JOIN', 'updated_utc': now()})
    try:
        E = Path(plan['evidence'])
        r, done, binding = [read(E/n) for n in ['result.json', 'complete.json', 'binding.json']]
        original_plan, integrity = read(E/'producer-plan.json'), read(E/'stdout-integrity.json')
        assert sha(E/'result.json') == done['result_sha256']
        assert sha(E/'binding.json') == done['binding_sha256'] == r['binding_sha256']
        assert sha(E/'stdout-integrity.json') == done['stdout_integrity_sha256'] == r['stdout_integrity_sha256']
        assert sha(E/'producer-plan.json') == done['plan_sha256'] == r['plan_sha256']
        assert sha(E/'strict-acceptance.json') == done['strict_acceptance_sha256']
        assert r['status'] == 'PASS_COMPLETE_APPLICATION_AND_STRICT_CHECKER_DRAIN'
        assert r['valid'] and r['software_correct'] and r['returncode'] == 0
        assert not r['faults'] and r['stop_cause'] is None
        assert not r['fpga_access'] and not r['formal_fpga_sample']
        assert r['functional_baseline'] == original_plan['functional_baseline'] == binding['functional_baseline'] == BASE
        assert r['source_id'] == original_plan['source_id'] == binding['source_id']
        assert not binding['model_or_rtl_changed'] and not original_plan['target_or_host_rtl_modified']
        assert r['elf_sha256'] == done['elf_sha256'] == sha(original_plan['elf'])
        assert r['binary_sha256'] == sha(original_plan['binary'])
        assert r['roi_end_csr']-r['roi_start_csr'] == r['roi_cycles'] == 6166433
        assert r['roi_instructions'] == 3562647
        assert r['output'] == ['benchmark=blackscholes checksum=1187d037cad2df6f verified=1 options=64 runs=100']
        assert integrity['complete_stream_eof']
        assert sha(E/'host-complete.log.gz') == integrity['gzip_sha256']
        raw_hash, raw_bytes = hashlib.sha256(), 0
        with gzip.open(E/'host-complete.log.gz', 'rb') as f:
            for block in iter(lambda: f.read(2**20), b''):
                raw_hash.update(block)
                raw_bytes += len(block)
        assert raw_bytes == integrity['raw_bytes'] and raw_hash.hexdigest() == integrity['raw_sha256']
        events = [json.loads(line) for line in (E/'external-events.jsonl').read_text().splitlines()]
        prints = (E/'rtl-prints-1').read_text()
        paired = join(events, prints)
        assert paired['packages'] == 1122
        assert paired['per_checker'] == r['strict_acceptance']['per_checker']
        assert paired['last_boom_accepted']-r['roi_end_csr'] == r['checker_result_acceptance_tail_after_roi_csr_cycles'] == 9655
        rejected = []
        for kind in ['missing_acceptance', 'wrong_status', 'wrong_checker', 'duplicate_allocation']:
            mutation = [dict(e) for e in events]
            index = next(i for i, e in enumerate(mutation) if e['kind'] == 'BOOM_RESULT_ACCEPTED')
            if kind == 'missing_acceptance':
                mutation.pop(index)
            elif kind == 'wrong_status':
                mutation[index]['status'] = 1
            elif kind == 'wrong_checker':
                mutation[index]['checker'] = mutation[index]['checker'] % 4 + 1
            else:
                mutation.append(dict(next(e for e in mutation if e['kind'] == 'BOOM_ALLOC')))
            try:
                join(mutation, prints)
            except AssertionError:
                rejected.append(kind)
            else:
                raise AssertionError(('Join mutation accepted', kind))
        result = {**state, 'status': 'PASS_BOUND_FULL_BLACKSCHOLES_CPU_GG_RAW_STREAM_AND_1122_PACKAGE_JOIN',
            'completed_utc': now(), 'sample_result_sha256': done['result_sha256'],
            'source_id': r['source_id'], 'elf_sha256': r['elf_sha256'],
            'roi_cycles': r['roi_cycles'], 'roi_instructions': r['roi_instructions'],
            'raw_stdout_bytes': raw_bytes, 'raw_stdout_sha256': raw_hash.hexdigest(),
            'raw_gzip_bytes': integrity['gzip_bytes'], 'output': r['output'],
            'strict_join': paired, 'join_mutations_rejected': rejected,
            'checker_acceptance_tail_from_roi_boom_csr_cycles': 9655,
            'host_wall_seconds': r['host_wall_seconds'], 'host_simulator_FMR': r['host_simulator_FMR'],
            'simulation_target_cycles_per_host_second': r['simulation_target_cycles_per_host_second'],
            'full_equivalence': False, 'formal_fpga_sample': False,
            'limitations': r['limitations'], 'input_sha256': plan['inputs']}
        save(O/'result.json', result)
        save(O/'complete.json', dict(result_sha256=sha(O/'result.json'), completed_utc=now()))
        save(S, {**state, 'status': result['status'], 'updated_utc': now(), 'result_sha256': sha(O/'result.json')})
        print(result['status'])
    except Exception as exc:
        save(O/'failure.json', {**state, 'status': 'FAILED_WITH_EVIDENCE', 'error': repr(exc)})
        save(S, {**state, 'status': 'FAILED_WITH_EVIDENCE', 'error': repr(exc), 'updated_utc': now()})
        raise


if __name__ == '__main__':
    main()
