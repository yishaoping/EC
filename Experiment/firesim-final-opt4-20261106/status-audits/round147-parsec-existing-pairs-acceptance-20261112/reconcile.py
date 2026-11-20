#!/usr/bin/env python3
"""Accept unchanged CPU evidence independently of historical FPGA exceptions.

Reads completed publications and receipts only. Never starts experiments or
modifies the original publication, campaign, hardware, or controller inputs.
"""
import csv
import hashlib
import json
import math
import os
from pathlib import Path

OUT = Path(__file__).resolve().parent
SOURCE = Path('/data1/gzh/EC/Experiment/parsec8-performance-audit-20261112')
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
NAMES = ['blackscholes', 'fluidanimate', 'bodytrack', 'freqmine',
         'swaptions', 'ferret', 'dedup', 'streamcluster']
SOURCE_COMPLETE_SHA = '2f2ee470b7b2960664188210d9b257f1594b4a6bf9096932ee60ab2ba796c2cb'
HASH_CACHE = {}


def read(path):
    return json.loads(Path(path).read_text())


def rows(name):
    with (SOURCE / name).open() as stream:
        return list(csv.DictReader(stream))


def sha(path):
    path = Path(path)
    stat = path.stat()
    key = (str(path), stat.st_ino, stat.st_size, stat.st_mtime_ns, stat.st_ctime_ns)
    if key in HASH_CACHE:
        return HASH_CACHE[key]
    digest = hashlib.sha256()
    with path.open('rb') as stream:
        while block := stream.read(8 * 2**20):
            digest.update(block)
    HASH_CACHE[key] = digest.hexdigest()
    return HASH_CACHE[key]


def require(condition, reason):
    if not condition:
        raise ValueError(reason)


def current_cpu_record(record):
    path = Path(record['result'])
    run = read(path)
    binding = read(path.parent / 'binding.json')
    done = read(path.parent / 'complete.json')
    receipt = read(path.parent / 'stdout-integrity.json')
    require(record['passed'] and run['valid'] and run['returncode'] == 0,
            'CPU run not accepted')
    require(sha(path) == record['result_sha256'] == done['result_sha256'],
            'CPU result SHA mismatch')
    require(sha(path.parent / 'binding.json') == record['binding_sha256']
            == done['binding_sha256'], 'CPU binding SHA mismatch')
    require(sha(path.parent / 'stdout-integrity.json')
            == done['stdout_integrity_sha256'], 'CPU integrity receipt changed')
    require(receipt['complete_stream_eof'] and sha(record['compressed_raw_log'])
            == receipt['gzip_sha256'] == record['gzip_sha256'],
            'Compressed raw log changed since complete raw-stream audit')
    require(receipt['raw_sha256'] == record['raw_sha256'] == run['raw_log_sha256']
            and receipt['raw_bytes'] == record['raw_bytes'],
            'Previously decompressed stream binding mismatch')
    require(run['functional_baseline'] == binding['functional_baseline'] == BASE
            and not binding['fpga_access'], 'Wrong CPU provenance')
    require(run['roi_end_csr'] - run['roi_start_csr'] == run['roi_cycles']
            == record['roi_cycles'] > 0 and run['interrupt_policy_verified'],
            'ROI or interrupt policy invalid')
    require(sha(binding['args'][0]) == binding['binary_sha256']
            and sha(binding['elf']['path']) == binding['elf']['sha256']
            and sha(binding['manifest']) == binding['manifest_sha256']
            == record['manifest_sha256'], 'CPU model/software/manifest changed')
    for key in ['benchmark', 'mode', 'repeat', 'profile', 'roi_instructions']:
        require(run[key] == record[key], 'CPU record mismatch: ' + key)
    if run['mode'] == 'ec':
        strict = read(path.parent / 'strict-acceptance.json')
        require(strict['passed'] and strict['functional_baseline'] == BASE,
                'Strict checker receipt not accepted')
        require(strict['allocations'] == strict['local_begins']
                == strict['full_compare_local_results']
                == strict['boom_pass_accepted'] > 0, 'Checker lifecycle incomplete')
        require(all(strict[key] == 0 for key in
                    ['pending', 'fail', 'cancel', 'duplicate', 'sample_errors']),
                'Checker failure or undrained package')
        for evidence, digest in strict['evidence'].items():
            require(sha(evidence) == digest, 'Strict checker evidence changed')
    return run


def main():
    require(not (OUT / 'complete.json').exists(), 'Completed acceptance is immutable')
    os.sched_setaffinity(0, {200})
    os.nice(19 - os.getpriority(os.PRIO_PROCESS, 0))
    require(sha(SOURCE / 'complete.json') == SOURCE_COMPLETE_SHA,
            'Unexpected source publication receipt')
    complete = read(SOURCE / 'complete.json')
    for name, digest in complete['files_sha256'].items():
        require(sha(SOURCE / name) == digest, 'Publication file changed: ' + name)
    summary = read(SOURCE / 'summary.json')
    require(summary['functional_baseline'] == BASE and not summary['failures'],
            'Source CPU audit has failures')
    require(summary['raw_cpu_logs_verified'] == 48
            and summary['matched_repeat_pairs'] == 24
            and summary['first_round_pairs'] == 8
            and not summary['fpga_access'] and summary['new_simulations_started'] == 0,
            'Source coverage mismatch')
    require(sha(summary['snapshot_receipt']) == summary['snapshot_receipt_sha256'],
            'Original accepted snapshot receipt changed')
    records = read(SOURCE / 'cpu-raw-log-audit.json')
    require(len(records) == 48, 'Expected 48 complete audited CPU records')
    by_result = {}
    failures = []
    for record in records:
        try:
            require(record['result'] not in by_result, 'Duplicate CPU result')
            by_result[record['result']] = current_cpu_record(record)
        except Exception as error:
            failures.append({'result': record['result'], 'error': str(error)})
    accepted = []
    pairs = rows('paired-repeats.csv')
    require(len(pairs) == 24, 'Expected 24 declared pairs')
    for pair in pairs:
        try:
            native = by_result[pair['native_result']]
            ec = by_result[pair['ec_result']]
            require(native['mode'] == 'native' and ec['mode'] == 'ec', 'Wrong mode')
            require(native['benchmark'] == ec['benchmark'] == pair['benchmark']
                    and native['repeat'] == ec['repeat'] == int(pair['repeat'])
                    and native['profile'] == ec['profile'], 'Pair identity mismatch')
            require(native['output'] == ec['output']
                    and native['manifest_sha256'] == ec['manifest_sha256']
                    and native['roi_instructions'] == ec['roi_instructions']
                    == int(pair['roi_instructions_each']), 'Pair workload mismatch')
            require(native['roi_cycles'] == int(pair['native_roi_cycles'])
                    and ec['roi_cycles'] == int(pair['ec_roi_cycles'])
                    and math.isclose(float(pair['slowdown']),
                                     ec['roi_cycles'] / native['roi_cycles'],
                                     rel_tol=1e-14), 'Wrong CPU denominator or ratio')
            require(pair['method'] == 'CPU_GG_CYCLE_EXACT'
                    and pair['functional_baseline'] == BASE
                    and pair['full_application_claim'] == pair['full_simmedium']
                    == 'False', 'Unsupported scope')
            accepted.append(pair)
        except Exception as error:
            failures.append({'benchmark': pair['benchmark'],
                             'repeat': pair['repeat'], 'error': str(error)})
    require({(p['benchmark'], int(p['repeat'])) for p in accepted}
            == {(name, repeat) for name in NAMES for repeat in [1, 2, 3]}
            and len(accepted) == 24 and not failures,
            'Incomplete CPU acceptance: ' + json.dumps(failures))
    first = rows('first-round.csv')
    require([p['benchmark'] for p in first] == NAMES
            and first == [p for p in accepted if p['repeat'] == '1'],
            'First-round table differs from accepted pairs')
    historical = []
    for row in rows('historical-native-fpga.csv'):
        path = Path(row['result'])
        run = read(path)
        require(sha(path) == row['result_sha256']
                == read(path.parent / 'complete.json')['result_sha256'],
                'Historical result binding changed')
        issues = []
        for evidence, expected in run['evidence'].items():
            actual = sha(evidence)
            if actual != expected:
                issues.append({'path': evidence, 'expected_sha256': expected,
                               'actual_sha256': actual})
        require(row['saved_result_and_evidence_valid'] == str(not issues),
                'Historical evidence status changed')
        historical.append({'benchmark': row['benchmark'], 'repeat': int(row['repeat']),
                           'saved_evidence_valid': not issues, 'issues': issues,
                           'usable_as_cpu_denominator': False,
                           'historical_bdf_read_from_receipt': run['identity']['board_bdf']})
    require(len(historical) == 24, 'Historical coverage changed')
    require(sha(SOURCE / 'complete.json') == SOURCE_COMPLETE_SHA,
            'Source publication changed during verification')
    result = {
        'schema': 'ec-parsec-cpu-acceptance/1',
        'status': 'PASS_CPU_8_PROFILES_24_PAIRS_HISTORICAL_PARTIAL',
        'functional_baseline': BASE,
        'cpu_status': 'PASS_EXISTING_MATCHED_DECLARED_ROIS',
        'accepted_cpu_pairs': 24, 'cpu_raw_logs_bound': 48,
        'raw_stream_redecompression': False,
        'raw_stream_audit_reused': str(SOURCE / 'cpu-raw-log-audit.json'),
        'source_publication_complete_sha256': SOURCE_COMPLETE_SHA,
        'source_summary_status_preserved': summary['status'],
        'source_publication': str(SOURCE),
        'cpu_failures': failures, 'first_round': first,
        'historical_fpga_status': 'PARTIAL_SAVED_EVIDENCE_21_OF_24',
        'historical_fpga': historical,
        'historical_fpga_used_as_cpu_denominator': False,
        'full_application_slowdown': None, 'full_simmedium_slowdown': None,
        'full_ec_fpga_slowdown': None,
        'scope': 'Three captured phases; other inputs reduced or changed. No extrapolation.',
        'comparability_limits': 'Boot ELF/link addresses and initial cache layouts differ; '
                               'three deterministic repeats do not measure input variability.',
        'new_simulations_started': 0, 'fpga_access': False, 'cad_submissions': 0,
        'original_sources_modified': False,
    }
    (OUT / 'result.json').write_text(json.dumps(result, indent=2, sort_keys=True) + '\n')
    manifest = {p.name: sha(p) for p in OUT.iterdir()
                if p.is_file() and p.name in ['result.json', 'reconcile.py', 'README.md']}
    (OUT / 'complete.json').write_text(json.dumps({
        'status': result['status'], 'files_sha256': manifest,
        'source_complete_sha256': SOURCE_COMPLETE_SHA,
    }, indent=2, sort_keys=True) + '\n')
    print(json.dumps({key: result[key] for key in [
        'status', 'accepted_cpu_pairs', 'cpu_raw_logs_bound',
        'historical_fpga_status', 'new_simulations_started', 'fpga_access']}))


if __name__ == '__main__':
    main()
