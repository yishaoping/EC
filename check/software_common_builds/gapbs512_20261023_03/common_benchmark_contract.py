"""Shared, standard-library-only descriptor and log contract; no top-level work."""
import re

ROI_LINE = re.compile(r'^\[ROI\] hart=(\d+) start=(\d+) stop=(\d+) cycles=(\d+)\s*$')
RESULT_LINE = re.compile(
    r'^\[RUN\] benchmark=gapbs_bfs nodes=(\d+) source=(\d+) reached=(\d+) '
    r'edges=(\d+) verified=(\d+) parent_checksum=(\d+)\s*$')
FAILURE_PATTERNS = [r'\[ERROR\]', r'\bstatus=FAIL\b', r'\*\*\* FAILED \*\*\*',
                    r'Assertion.*failed', r'%Error', r'\[VERIFY_DIAG\].*=FAIL']
PASS_PATTERNS = [r'^\[INIT\] checker_mask=0xf status=ready$',
                 r'^\[COMPUTATION\] status=PASS scope=amo_w_and_bfs_result$',
                 r'^\[END\] hart=0 status=PASS$',
                 r'^\[COMPLETION\] checker_software_ready=4 cache_drain=UNRESOLVED$']


def validate_roi_descriptor(d):
    roi = d.get('roi')
    if not isinstance(roi, dict):
        raise ValueError('schema 2 requires an explicit ROI contract')
    expected = {'schema': 1, 'hart': 0, 'counter': 'cycle',
                'start_symbol': 'common_roi_start', 'stop_symbol': 'common_roi_stop',
                'definition': 'stop_cycle - start_cycle',
                'scope': 'amo_w_plus_bfs512_plus_stop_and_session_completion'}
    for key, value in expected.items():
        if roi.get(key) != value:
            raise ValueError('Unsupported/missing ROI field: ' + key)
    for key in ('start_pc', 'stop_pc'):
        if not isinstance(roi.get(key), str) or not re.fullmatch(r'0x[0-9a-f]+', roi[key]):
            raise ValueError('Missing final ELF ROI PC: ' + key)
    if int(roi['stop_pc'], 16) <= int(roi['start_pc'], 16):
        raise ValueError('Invalid ROI PC order')
    if d.get('required_pass_patterns') != PASS_PATTERNS:
        raise ValueError('Common benchmark requires the shared pass contract')
    if d.get('failure_patterns') != FAILURE_PATTERNS:
        raise ValueError('Common benchmark requires the shared failure contract')
    if not isinstance(d.get('software_build_manifest'), str) or not re.fullmatch(
            r'[0-9a-f]{64}', d.get('software_build_manifest_sha256', '')):
        raise ValueError('Common benchmark requires a software build manifest identity')


def parse_common_log(lines):
    rois, results, failures = [], [], []
    expressions = [re.compile(p) for p in FAILURE_PATTERNS]
    for number, line in enumerate(lines, 1):
        match = ROI_LINE.fullmatch(line)
        if line.startswith('[ROI]') and not match:
            raise ValueError('Malformed ROI record')
        if match:
            rois.append(dict(zip(('hart', 'start', 'stop', 'cycles'), map(int, match.groups()))))
        match = RESULT_LINE.fullmatch(line)
        if line.startswith('[RUN] benchmark=gapbs_bfs') and not match:
            raise ValueError('Malformed computation record')
        if match:
            results.append(dict(zip(('nodes', 'source', 'reached', 'edges', 'verified',
                                     'parent_checksum'), map(int, match.groups()))))
        if any(p.search(line) for p in expressions):
            failures.append(number)
    if failures or len(rois) != 1 or len(results) != 1:
        raise ValueError('Ambiguous/missing ROI or computation record, or failure marker: ' +
                         str({'roi_count': len(rois), 'result_count': len(results), 'failure_lines': failures[:20]}))
    roi, result = rois[0], results[0]
    if (roi['hart'] != 0 or not 0 <= roi['start'] < roi['stop'] < 2**64 or
            roi['cycles'] != roi['stop'] - roi['start']):
        raise ValueError('Invalid hart/cycle samples/arithmetic; no wrap compensation')
    if any(result[k] != v for k, v in
           {'nodes': 512, 'source': 0, 'reached': 512, 'edges': 8192, 'verified': 1}.items()):
        raise ValueError('Workload result self-check failed')
    return {'ROI_cycles': roi['cycles'], 'samples': roi, 'workload_result': result,
            'measurement': 'SOFTWARE_ROI',
            'correctness_scope': 'AMO_W_AND_BFS_SELF_CHECKS_ONLY',
            'cache_package_drain': 'UNRESOLVED'}
