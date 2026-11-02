#!/usr/bin/env python3
"""User-only, single A' refresh; static/offline modes never launch hardware.

The existing source/patch/software guard is called intact. A separate seal binds
the same hardware as completed B plus a reviewed host-only capture overlay.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[3]
SCRIPTS = Path(__file__).resolve().parent
LAUNCHER = ROOT / 'slowdown/optimization_4_svb/scripts/launch_optimization_4_svb.py'
CAPTURE = ROOT / 'slowdown/optimization_4_svb/scripts/compact_capture.py'


def read(path):
    return json.loads(Path(path).read_text())


def digest(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    result = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(result)
    return result


def require(condition, message):
    if not condition:
        raise ValueError(message)


def validate_target(contract, arm):
    require(arm == 'A' and contract['run_target'] == 'A_PRIME_ONLY_32K_2WAY' and
            contract['number_of_full_runs_requested'] == 1 and
            contract['automatic_retry'] is False, 'only one A-prime baseline is authorized')


def preflight(report):
    report = report.resolve()
    require(report.is_relative_to(ROOT / 'AI/TMP'), 'report must stay in AI/TMP')
    contract_path = report / 'A_REFRESH_CONTRACT.json'
    contract = read(contract_path)
    validate_target(contract, 'A')
    decision = read(contract['postanalysis_decision'])
    require(decision['STRICT_BASELINE_GATE'] == 'STRICT_BASELINE_REFRESH_JUSTIFIED' and
            all(decision[k] == 'PASS' for k in ['CHECKER', 'OBSERVER', 'INTEGRITY']) and
            decision['B_ROI_COMPLETE'] == 'YES', 'completed B does not justify A-prime')
    revision = report / 'sealed'
    seal = read(revision / 'source_seal.json')
    require(seal['baseline_refresh_contract'] == dict(
        path=str(contract_path.relative_to(ROOT)), sha256=digest(contract_path)),
        'A-prime contract is not sealed')
    bseal = read(contract['completed_B_seal'])
    require(seal['hardware_sha256'] == bseal['hardware_sha256'] and
            seal['software'] == bseal['software'], 'A-prime must use completed B hardware/software')
    require(not seal.get('one_shot_contract'), 'cannot reuse or alter a B-only seal')
    for path, expected in contract['evidence_sha256'].items():
        require(digest(ROOT / path) == expected, 'reference evidence changed: ' + path)
    overlay = ROOT / contract['capture_overlay']
    text = CAPTURE.read_text()
    require(text.count('len(self.observers) >= 128') == 1 and
            text.count('len(self.producers) >= 128') == 1, 'unexpected capture source')
    expected = text.replace('len(self.observers) >= 128', 'len(self.observers) >= 256').replace(
        'len(self.producers) >= 128', 'len(self.producers) >= 256')
    require(overlay.read_text() == expected, 'host overlay has changes beyond two identity caps')
    capture = module('compact_capture', overlay)
    # The existing launcher imports this exact sealed module in both identity
    # and execution. All reservations/classification/limits stay byte-identical.
    sys.modules['compact_capture'] = capture
    launch = module('seq67_A_refresh_existing_launcher', LAUNCHER)
    original_identity = launch.causal_identity

    def a_only_identity():
        require(launch.CAUSAL_CONTEXT == (revision, 'A'), 'A-prime wrapper rejects arm B')
        validate_target(contract, launch.CAUSAL_CONTEXT[1])
        return original_identity()

    launch.causal_identity = a_only_identity
    launch.CAUSAL_CONTEXT = (revision, 'A')
    launch.ACTIVE_CONFIG = 'L1Causal32Config'
    identity = launch.causal_identity()
    require(identity['hardware_sha256'] == bseal['hardware_sha256'], 'runtime hardware changed')
    return contract, launch, identity


def analyze_only(report, contract):
    pair = module('seq67_A_refresh_pair', SCRIPTS / 'analyze_l1_causal_pair.py')
    revision = report / 'sealed'
    a = pair.arm(revision, 'A')
    b = read(contract['validated_B_result'])
    am, bm = read(a['manifest']), read(contract['completed_B_manifest'])
    aargv, bargv = am.get('simulation_argv', []), bm['simulation_argv']
    bbuild = Path(contract['completed_B_build'])
    abuild = revision / 'arms/A/build' / Path(a['run']).name
    generated = module('seq67_A_generated', SCRIPTS / 'collect_l1_causal_provenance.py')
    differences = generated.differences(
        read(next((abuild / 'generated').glob('*Config.json'))),
        read(next((bbuild / 'generated').glob('*Config.json'))))
    paired = dict(
        identical_hardware=a['source']['hardware_sha256'] == bm['source']['hardware_sha256'],
        identical_software=am['software'] == bm['software'],
        identical_execution_arguments=bool(aargv) and aargv[1:] == bargv[1:],
        expected_executables=bool(aargv) and Path(aargv[0]).name == 'simulator-chipyard-L1Causal32Config'
            and Path(bargv[0]).name == 'simulator-chipyard-L1Causal64Config',
        geometry_only=differences == [('/cpus/cpu@0/d-cache-sets/0', 256, 512),
                                      ('/cpus/cpu@0/d-cache-size/0', 32768, 65536)],
        A_source_sealed=a['source']['hardware_sha256'] == read(revision / 'source_seal.json')['hardware_sha256']
            and a['source']['tool_sha256'] == read(revision / 'source_seal.json')['tool_sha256'])
    for suffix in ['l2.json', 'buildTopClockGenerator.freq-summary',
                   'harnessDividerOnlyClockGenerator.freq-summary']:
        paired['identical_' + suffix] = digest(next((abuild / 'generated').glob('*Config.' + suffix))) == digest(
            next((bbuild / 'generated').glob('*Config.' + suffix)))
    native = 'chipyard/generators/rocket-chip/src/main/resources/csrc/cache_opportunity.cc'
    for name, build in [('A', abuild), ('B', bbuild)]:
        copies = list((build / 'generated').rglob('cache_opportunity.cc'))
        paired[name + '_native_copies'] = bool(copies) and all(
            digest(p) == bm['source']['hardware_sha256'][native] for p in copies)
    # Same mandatory seq67 instrumentation/guards; A need not assign sequence67
    # to hart3 or exercise exactly B's trap. Validate the whole recorded ledger.
    evidence = module('seq67_A_events', SCRIPTS / 'inspect_checker_seq67_evidence.py')
    rows = list(evidence.records(Path(a['run']) / 'safe_chain_events.tsv'))
    allocations = [r['n'][0] for r in rows if r['kind'] == 2]
    accepted = [r['n'][0] & 0xffffffff for r in rows if r['kind'] == 3 and r['n'][1] & 2]
    handoffs = [r for r in rows if r['kind'] == 47]
    paired['A_all_packages_closed'] = bool(allocations) and sorted(allocations) == sorted(accepted) == sorted(
        r['n'][0] for r in handoffs) and len(set(allocations)) == len(allocations)
    paired['A_clean_handoffs_and_no_cancel'] = bool(handoffs) and all(
        r['n'][15] & 1 and not r['n'][15] & 14 and r['n'][15] >> 11 == 0 and
        r['n'][7] == r['n'][8] == 0 and r['n'][14] >> 5 < 127 for r in handoffs)
    valid = a['valid'] and b['valid'] and all(paired.values())
    comparison = None
    if valid:
        comparison = dict(label='STRICT_A_PRIME_VS_EXISTING_B_WITH_AUDITED_HOST_ACCOUNTING_EXCEPTION',
            roi_A_prime=a['roi_cycles'], roi_B=b['roi_cycles'],
            delta_B_minus_A_prime=b['roi_cycles'] - a['roi_cycles'],
            percent=100 * (b['roi_cycles'] - a['roi_cycles']) / a['roi_cycles'],
            misses_A_prime=a['actual_l1']['miss'], misses_B=b['actual_l1']['miss'],
            causal_delta_B_minus_A_prime={k:b['causal']['counts'][k] - v for k,v in a['causal']['counts'].items()})
    result = dict(status='PASS' if valid else 'FAIL', A_gates=a['gates'], pairing_gates=paired,
                  comparison=comparison, additional_runs_scheduled=0,
                  host_exception='Only the two host identity accounting caps change128->256. Hardware/logging/budgets/analysis gates are identical; B has complete recovered mandatory conservation.')
    (report / 'A_prime_result.json').write_text(json.dumps(result, indent=2, sort_keys=True) + '\n')
    (report / 'runtime_A_prime.json').write_text(json.dumps(a, indent=2, sort_keys=True) + '\n')
    return result


def claim_once(report):
    require(not list((report / 'sealed/arms/A/runs').glob('*/run_manifest.json')),
            'A-prime already has a run; use --analyze-only')
    with (report / 'A_PRIME_LAUNCH_CLAIM.json').open('x') as stream:
        json.dump(dict(target='A_PRIME_ONLY_32K_2WAY', automatic_retry=False), stream)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--report', required=True, type=Path)
    ap.add_argument('--jobs', type=int, default=4)
    modes = ap.add_mutually_exclusive_group()
    modes.add_argument('--static-check', action='store_true')
    modes.add_argument('--analyze-only', action='store_true')
    args = ap.parse_args()
    require(args.jobs >= 1, 'jobs must be positive')
    report = args.report.resolve()
    contract, launch, identity = preflight(report)
    if args.static_check:
        print(json.dumps(dict(status='PASS', target=contract['run_target'],
                              hardware_generation='NOT_EXECUTED', verilator_build='NOT_EXECUTED',
                              simulation='NOT_EXECUTED', hardware_files=len(identity['hardware_sha256']))))
        return 0
    if not args.analyze_only:
        claim_once(report)
        sys.argv = [str(LAUNCHER), '--l1-causal-arm', 'A', '--experiment-dir',
                    str(report / 'sealed'), '--jobs', str(args.jobs)]
        rc = launch.main()
        (report / 'user_launcher_exit.json').write_text(json.dumps(dict(exit_code=rc)) + '\n')
        if rc:
            return rc
    result = analyze_only(report, contract)
    print(json.dumps(result, indent=2))
    return 0 if result['status'] == 'PASS' else 3


if __name__ == '__main__':
    raise SystemExit(main())
