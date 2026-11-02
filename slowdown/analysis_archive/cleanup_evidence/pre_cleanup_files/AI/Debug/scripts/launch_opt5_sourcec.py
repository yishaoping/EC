#!/usr/bin/env python3
"""Single user-run SourceC experiment. --static-check never starts hardware."""
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
L2 = 'chipyard/generators/sifive-cache/design/craft/inclusivecache/src/'
CHANGED = {L2 + 'Scheduler.scala', L2 + 'L2Preservation.scala'}
COUNTERS = ['sourcec_reserved_cycles', 'sourcec_reserved_with_pending_release',
            'release_bypass_count', 'release_still_blocked_count', 'waitAck_cycles',
            'waitAck_with_pending_release', 'target_set_locked_cycles',
            'old_reserved_with_pending_release']


def read(path):
    return json.loads(Path(path).read_text())


def write(path, value):
    Path(path).write_text(json.dumps(value, indent=2, sort_keys=True) + '\n')


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
    require(arm == 'B' and contract['run_target'] == 'OPT5_SOURCEC_B_ONLY_64K_2WAY' and
            contract['number_of_full_runs_requested'] == 1 and
            contract['automatic_retry'] is False, 'only one Opt5 SourceC B run is authorized')


def capture_overlay_text():
    original = CAPTURE.read_text()
    require(original.count('len(self.observers) >= 128') == 1 and
            original.count('len(self.producers) >= 128') == 1, 'unexpected capture implementation')
    return original.replace('len(self.observers) >= 128', 'len(self.observers) >= 256').replace(
        'len(self.producers) >= 128', 'len(self.producers) >= 256')


def preflight(report):
    report = report.resolve()
    require(report.is_relative_to(ROOT / 'AI/TMP'), 'report must stay in AI/TMP')
    cp = report / 'sourcec_contract.json'
    contract = read(cp)
    validate_target(contract, 'B')
    seal = read(report / 'sealed/source_seal.json')
    require(seal['one_shot_contract'] == dict(path=str(cp.relative_to(ROOT)), sha256=digest(cp)),
            'experiment contract is not sealed')
    for rel, expected in contract['evidence_sha256'].items():
        require(digest(ROOT / rel) == expected, 'reference/validation evidence changed: ' + rel)
    old = read(contract['completed_B_seal'])
    before = read(report / 'evidence/pre_edit_inputs.json')['sha256']
    actual_changes = {p for p, h in seal['hardware_sha256'].items() if before.get(p) != h}
    require(actual_changes == CHANGED and
            set(seal['hardware_sha256']) == set(old['hardware_sha256']) | CHANGED,
            'hardware changes extend beyond the two reviewed L2 files')
    require(seal['software'] == old['software'] and seal['roi'] == old['roi'] and
            seal['common_l1'] == old['common_l1'] and seal['arms'] == old['arms'],
            'software/ROI/config differs from current B')
    require(read(report / 'evidence/scala_typer_result.json')['exit_code'] == 0 and
            read(report / 'evidence/cpu_test_result.json')['status'] == 'PASS',
            'type/offline checks have not passed')
    baseline = read(contract['validated_B_result'])
    require(baseline['valid'] and all(baseline['gates'].values()) and
            baseline['roi_cycles'] == contract['current_B_roi'] == 1648923 and
            baseline['source']['hardware_sha256'] == old['hardware_sha256'] and
            baseline['source']['tool_sha256'] == old['tool_sha256'],
            'completed B reference is invalid')
    overlay = ROOT / contract['capture_overlay']
    require(overlay.read_text() == capture_overlay_text(), 'capture overlay exceeds two identity caps')
    capture = module('compact_capture', overlay)
    sys.modules['compact_capture'] = capture
    launch = module('opt5_sourcec_existing_launcher', LAUNCHER)
    original_identity = launch.causal_identity

    def b_only_identity():
        require(launch.CAUSAL_CONTEXT == (report / 'sealed', 'B'), 'SourceC wrapper rejects arm A')
        validate_target(contract, launch.CAUSAL_CONTEXT[1])
        identity = original_identity()  # Existing source/patch/software guard stays intact.
        identity.update(optimization='Opt5-SourceC-waitAck-bypass',
                        validation_purpose='OPT5_SOURCEC_SINGLE_INTERVENTION_VS_COMPLETED_B',
                        sourcec_contract_sha256=digest(cp),
                        comparison_baseline_roi=1648923,
                        host_capture_overlay_sha256=digest(overlay))
        return identity

    launch.causal_identity = b_only_identity
    launch.CAUSAL_CONTEXT = (report / 'sealed', 'B')
    launch.ACTIVE_CONFIG = 'L1Causal64Config'
    identity = launch.causal_identity()
    return contract, launch, identity


def diagnostics(rows, event_path, capture):
    selected = [r for r in rows if r['kind'] == 48]
    reference = [r for r in rows if r['kind'] == 40 and r['hart'] == 0]
    errors = []
    if len(selected) != 1 or selected[0]['hart'] != 0 or len(reference) != 1:
        return dict(status='FAIL', errors=['expected one SC48 and one reference SC40 STOP'])
    words = selected[0]['n']
    sample = words[1]
    c = dict(zip(COUNTERS, words[2:10]))
    if words[0] != 1 or sample != reference[0]['n'][1] or not sample or any(words[10:]):
        errors.append('schema/window/padding mismatch')
    if any(v < 0 or v > sample for v in c.values()):
        errors.append('counter exceeds measurement window')
    if c['sourcec_reserved_cycles'] + c['waitAck_cycles'] != c['target_set_locked_cycles']:
        errors.append('reservation phase partition failed')
    if c['sourcec_reserved_with_pending_release'] + c['waitAck_with_pending_release'] != c['old_reserved_with_pending_release']:
        errors.append('pending phase partition failed')
    if not (c['release_bypass_count'] <= c['waitAck_with_pending_release'] <= c['waitAck_cycles'] and
            c['sourcec_reserved_with_pending_release'] <= c['sourcec_reserved_cycles'] and
            c['sourcec_reserved_with_pending_release'] <= c['release_still_blocked_count'] and
            c['old_reserved_with_pending_release'] <= c['target_set_locked_cycles']):
        errors.append('counter subset failed')
    footers = [p for line in Path(event_path).read_text().splitlines()
               if len(p := line.split('\t')) == 8 and p[0] == 'SC_END' and p[5:7] == ['48', '0']]
    producer = capture.get('producers', {}).get('48:0', {})
    observer = capture.get('observers', {}).get('48:0', {})
    if not (len(footers) == 1 and footers[0][7] == '1' and
            producer.get('produced') == producer.get('emitted') == 1 and
            producer.get('omitted') == 0 and observer.get('events_seen') == 1 and
            observer.get('footers_seen') == 1 and observer.get('omitted') == 0):
        errors.append('SC48 producer/footer/capture conservation failed')
    return dict(status='FAIL' if errors else 'PASS', errors=errors, sample_cycles=sample,
                counts=c, window='existing hardware traffic START-to-STOP, wider than software ROI',
                pending_policy='raw voluntary MSHR C opportunity; other blockers may overlap',
                still_blocked_unit='cycles with any raw pending victim and no accepted victim request')


def verdict(roi, valid):
    if not valid:
        return dict(performance_valid=False, OPT5_SUCCESS_SUB1P5='UNVALIDATED',
                    decision='INVALID_RUN_STOP_NO_RETRY', additional_sourcec_runs=0)
    gain = 1648923 - roi
    decision = ('SUB1P5_SUCCESS' if roi < 1502513 else 'STRONG_OPT5' if gain >= 100000
                else 'MODERATE_KEEP_FOR_COMBINATION' if gain >= 50000 else 'STOP_SOURCEC_DIRECTION')
    return dict(performance_valid=True, current_B_roi=1648923, opt5_roi=roi, saving_cycles=gain,
                OPT5_SUCCESS_SUB1P5='YES' if roi < 1502513 else 'NO', decision=decision,
                additional_sourcec_runs=0)


def analyze_only(report, contract):
    pair = module('sourcec_pair', SCRIPTS / 'analyze_l1_causal_pair.py')
    events = module('sourcec_events', SCRIPTS / 'inspect_checker_seq67_evidence.py')
    revision = report / 'sealed'
    result = pair.arm(revision, 'B')
    manifest = read(result['manifest'])
    baseline = read(contract['completed_B_manifest'])
    seal = read(revision / 'source_seal.json')
    run = Path(result['run'])
    build = revision / 'arms/B/build' / run.name
    bbuild = Path(contract['completed_B_build'])
    argv, bargv = manifest.get('simulation_argv', []), baseline['simulation_argv']
    gates = dict(result['gates'])
    gates.update(
        source_sealed=result['source']['hardware_sha256'] == seal['hardware_sha256'] and
            result['source']['tool_sha256'] == seal['tool_sha256'] and
            result['source']['paired_source_fingerprint'] == seal['paired_source_fingerprint'],
        same_software=manifest['software'] == baseline['software'],
        same_execution_arguments=bool(argv) and argv[1:] == bargv[1:],
        expected_executable=bool(argv) and Path(argv[0]).name == Path(bargv[0]).name == 'simulator-chipyard-L1Causal64Config',
        identical_generated_configuration=read(next((build / 'generated').glob('*Config.json'))) ==
            read(next((bbuild / 'generated').glob('*Config.json'))))
    for suffix in ['l2.json', 'buildTopClockGenerator.freq-summary', 'harnessDividerOnlyClockGenerator.freq-summary']:
        gates['identical_' + suffix] = digest(next((build / 'generated').glob('*Config.' + suffix))) == digest(
            next((bbuild / 'generated').glob('*Config.' + suffix)))
    native = 'chipyard/generators/rocket-chip/src/main/resources/csrc/cache_opportunity.cc'
    for name, directory in [('Opt5', build), ('B', bbuild)]:
        copies = list((directory / 'generated').rglob('cache_opportunity.cc'))
        gates[name + '_native_copies'] = bool(copies) and all(digest(p) == seal['hardware_sha256'][native] for p in copies)
    rows = list(events.records(run / 'safe_chain_events.tsv'))
    allocations = [r['n'][0] for r in rows if r['kind'] == 2]
    accepted = [r['n'][0] & 0xffffffff for r in rows if r['kind'] == 3 and r['n'][1] & 2]
    handoffs = [r for r in rows if r['kind'] == 47]
    gates['all_packages_closed'] = bool(allocations) and sorted(allocations) == sorted(accepted) == sorted(
        r['n'][0] for r in handoffs) and len(set(allocations)) == len(allocations)
    gates['clean_handoffs_no_cancel'] = bool(handoffs) and all(
        r['n'][15] & 1 and not r['n'][15] & 14 and r['n'][15] >> 11 == 0 and
        r['n'][7] == r['n'][8] == 0 and r['n'][14] >> 5 < 127 for r in handoffs)
    diag = diagnostics(rows, run / 'safe_chain_events.tsv', read(run / 'capture_summary.json'))
    gates['sourcec_diagnostics'] = diag['status'] == 'PASS'
    valid = all(gates.values())
    outcome = dict(status='PASS' if valid else 'FAIL', gates=gates,
                   diagnostics=diag, performance=verdict(result['roi_cycles'], valid),
                   reference='CURRENT_COMPLETED_B; historical A/new-B strict pairing remains pending',
                   host_capture_change='identity dictionaries128->256 only; same budgets and validation gates',
                   run=str(run), manifest=result['manifest'])
    write(report / 'evidence/runtime_opt5.json', result)
    validation = read(report / 'validation_result.json')
    validation['runtime'] = outcome
    write(report / 'validation_result.json', validation)
    return outcome


def claim_once(report):
    require(not list((report / 'sealed/arms/B/runs').glob('*/run_manifest.json')),
            'experiment already has a run; only --analyze-only is allowed')
    with (report / 'SOURCEC_LAUNCH_CLAIM.json').open('x') as stream:
        json.dump(dict(target='OPT5_SOURCEC_B_ONLY_64K_2WAY', automatic_retry=False), stream)


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
        print(json.dumps(dict(status='PASS', hardware_generation='NOT_EXECUTED',
                              verilator_build='NOT_EXECUTED', simulation='NOT_EXECUTED',
                              fingerprint=identity['paired_source_fingerprint'])))
        return 0
    if not args.analyze_only:
        claim_once(report)
        sys.argv = [str(LAUNCHER), '--l1-causal-arm', 'B', '--experiment-dir',
                    str(report / 'sealed'), '--jobs', str(args.jobs)]
        rc = launch.main()
        write(report / 'evidence/user_launcher_exit.json', dict(exit_code=rc))
        if rc:
            validation = read(report / 'validation_result.json')
            validation['runtime'] = dict(status='FAIL', launcher_exit_code=rc,
                                         performance=verdict(None, False),
                                         reason='inspect the fresh run manifest; no automatic retry')
            write(report / 'validation_result.json', validation)
            return rc
    outcome = analyze_only(report, contract)
    print(json.dumps(outcome, indent=2))
    return 0 if outcome['status'] == 'PASS' else 3


if __name__ == '__main__':
    raise SystemExit(main())
