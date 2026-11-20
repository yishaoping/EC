#!/usr/bin/python3
"""Seal round 39 without modifying campaign, source, live jobs, or prior evidence."""
from pathlib import Path
import datetime
import hashlib
import json
import os
import re

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
O = D / 'build-logs/Opt4-round39-two-route-evidence-v1-20261111'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'

def read(path):
    return json.loads(Path(path).read_text())

def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()

def live(j):
    if not all(k in j for k in ['pid', 'start_ticks', 'host_boot_id']):
        return False
    if j['host_boot_id'] != Path('/proc/sys/kernel/random/boot_id').read_text().strip():
        return False
    try:
        fields = Path(f"/proc/{j['pid']}/stat").read_text().rsplit(')', 1)[1].split()
        return fields[19] == j['start_ticks'] and fields[0] != 'Z'
    except FileNotFoundError:
        return False

def save(name, value):
    with (O / name).open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())

def main():
    policy = read(U / 'campaign-policy.json')
    assert policy['functional_baseline_commit'] == BASE
    assert policy['area_equivalence_only'] and not policy['functional_extensions_allowed']
    assert policy['native_paused'] and not policy['fpga_access']
    assert policy['board_allowlist'] == ['0000:21:00.0']
    O.mkdir(exist_ok=False)
    now = datetime.datetime.now(datetime.timezone.utc)
    save('policy-observed.json', dict(utc=now.isoformat(), scope=policy['scope_reminder'],
         capacity=policy['latest_postopt_capacity'], campaign_policy_sha256=sha(U / 'campaign-policy.json')))
    jobs = {}
    for version in ['v1', 'v2', 'v3', 'v4', 'v5']:
        q = D / f'Opt4-mt-clock-repair-round39-{version}-state.json'
        state = read(q)
        name = f'mt-clock-repair-r39-{version}-8491167d'
        receipt = read(U / 'request-results' / (name + '.json'))
        result = D / f'build-logs/Opt4-mt-clock-repair-round39-{version}-20261111/result.json'
        failure = result.with_name('failure.json')
        jobs[version] = dict(state=state, controller_live=live(state), broker=receipt,
                             state_path=str(q), controller_inputs_changed=False)
        if state.get('child'):
            jobs[version]['child_live'] = live(state['child'])
        if result.exists():
            jobs[version]['result'] = read(result)
            jobs[version]['result_sha256'] = sha(result)
        if failure.exists():
            jobs[version]['failure'] = read(failure)
    assert jobs['v1']['state']['status'] == 'FAILED_WITH_EVIDENCE'
    assert jobs['v2']['broker']['status'] in ['STARTED', 'ADOPTED']
    assert jobs['v5']['broker']['status'] in ['STARTED', 'ADOPTED']
    repair = jobs['v5'].get('result')
    if not repair:
        assert jobs['v5']['controller_live'] or 'failure' in jobs['v5']
    save('clock-repair-and-recovery.json', jobs)
    check = D / 'build-logs/Opt4-mt-clock-repair-round39-v2-20261111/original-pass-check.log'
    text = check.read_text()
    assert 'ORIGINAL_INFER_MODEL_PORTS_PASS changed_clock_annotations=12 channels=1747 model_port_annotations=3183 circuit_object_identical=true restored_clock_mutation_rejected=true' in text
    missing = re.findall(r'\[module FireSim\] Reference (\w+) is not declared\.', text)
    assert len(missing) == len(set(missing)) == 6
    assert 'ORIGINAL_FAME_TRANSFORM_AND_RESOLVE_PASS' not in text
    proof_dir = D / 'build-logs/Opt4-mt-clock-repair-round39-v2-20261111'
    assert (proof_dir / 'original-infer-rejection.txt').exists()
    assert (proof_dir / 'mutant-infer-rejection.txt').exists()
    save('infer-pass-and-fame-residual.json', dict(
        original_infer_pass=True, changed_clock_annotations=12, preserved_channels=1747,
        inferred_model_port_annotations=3183, exact_circuit_object_preserved=True,
        original_and_restored_clock_mutation_rejected=True,
        log=str(check), log_sha256=sha(check), missing_references=missing,
        full_fame_validation_passed=False, host_output_admitted=False,
        causal_chain=dict(
            symptom='FAME validation rejects six undeclared Clock references (proven)',
            immediate='The original FAME module transformer removes input Clock ports that are not its clock-channel inputs; their original internal connects remain (source-supported)',
            upstream='Post-channel input roots differ; the separate pre-excision proof below establishes their original two master-clock roots',
            downstream='Full MT+MCRams compiler continuation remains blocked; existing MCRams parity and route B CAD continue independently'),
        constraints=['Never tie clocks based only on equal rational frequency or name',
                     'Do not delete retained target connections or observations to pass validation',
                     'Keep the exact pre-excision feedback-clock proof bound to any further isolated compiler repair',
                     'No target RTL or live input changes, no core-sharing or area claim']))
    residual_path = D / 'build-logs/Opt4-mt-clock-residual-round39-v1-20261111/result.json'
    residual = read(residual_path)
    assert len(residual['clock_roots']) == 6
    assert all(v['status'] == 'EXACT_UNCONDITIONAL_WIRE_ROOT' for v in residual['clock_roots'].values())
    roots = {r:v['root']['input'] for r,v in residual['clock_roots'].items()}
    assert all(v['root']['module'] == 'FAMETop' for v in residual['clock_roots'].values())
    assert list(roots.values()).count('clockBridge_clocks_0') == 2
    assert list(roots.values()).count('clockBridge_clocks_1') == 4
    scala = (W / 'candidates/mt-clock-repair-round39-v5-20261111/Check.scala').read_text()
    encoded = dict(re.findall(r'"(lazyModule_\w+)" -> "(clockBridge_clocks_[01])"', scala))
    assert encoded == roots, 'Generated gated-alias mapping must match all six independent roots exactly'
    bad_roots = dict(roots); bad_roots[next(iter(bad_roots))] = 'host_clock'
    swapped = {k:('clockBridge_clocks_1' if v == 'clockBridge_clocks_0' else 'clockBridge_clocks_0') for k,v in roots.items()}
    assert bad_roots != roots and swapped != roots
    save('pre-excision-clock-proof-and-v5-binding.json', dict(
        path=str(residual_path), sha256=sha(residual_path), exact_roots=roots,
        gated_alias_mapping_matches_all_roots=True, ungated_host_clock_and_swapped_domains_rejected=True,
        runtime_equivalence_passed=False, no_sharing_or_area_claim=True))
    delta = D / 'build-logs/Opt4-mt-clock-repair-round39-v2-20261111/wire-proof-and-delta.json'
    if delta.exists():
        j = read(delta)
        assert len(j['delta']) == 12 and len(j['proof']['conflicts']) == 24
        assert j['preserved_all_payloads_and_other_metadata'] and not j['target_circuit_changed']
        save('clock-repair-scope.json', dict(path=str(delta), sha256=sha(delta),
             changes=12, conflicts=24, channel_count=1747,
             target_circuit_changed=False, original_libraries_changed=False,
             special_rocket_variants_equivalent=False, mt_sharing_gain_measured=False))
    route_a = {}
    for key in ['original_svb_component_fpga_preparation', 'original_svb_component_21_follower']:
        q = Path(policy['parallel_evidence_routes']['route_a'][key]); state = read(q)
        route_a[key] = dict(path=str(q), state=state, live=live(state))
    for key, q in {
        'original_svb_component_cad': D / 'cycleprecise-frozen-svb-fpga-r2-20261111/cad-state.json',
        'mcrams_parity': D / 'Opt4-route-a-full-mcrams-parity-round38-v1-state.json',
    }.items():
        state = read(q)
        route_a[key] = dict(path=str(q), state=state, live=live(state))
        if state.get('child'):
            route_a[key]['child_live'] = live(state['child'])
        elif state.get('child_pid'):
            route_a[key]['child_live'] = live(dict(pid=state['child_pid'],
                start_ticks=state['child_start_ticks'], host_boot_id=state['host_boot_id']))
    save('route-a-adoption.json', route_a)
    component_log = D / 'cycleprecise-frozen-svb-fpga-r2-20261111/cad-logs/implementation-attempt-1.log'
    with component_log.open() as f:
        f.seek(max(0, component_log.stat().st_size - 2400)); tail = f.read()
    save('component-routing-observation.json', dict(
        path=str(component_log), bytes=component_log.stat().st_size,
        mtime_ns=component_log.stat().st_mtime_ns, tail=tail,
        stage='Live routing; intermediate congestion and timing are not a final result',
        certified_bitstream=route_a['original_svb_component_cad']['state']['certified_bitstream']))
    snap = read(U / 'snapshot.json')
    names = ['Opt4-fit-update-share-svb-cad-state.json',
             'Opt4-fit-dcache-full-pair-r2-state.json',
             'Opt4-fit-dcache-fieldbank-full-map-r4-state.json',
             'Opt4-fit-dcache-field-read-full-map-r2-state.json',
             'Opt4-fit-address-update-sequence-r1-state.json',
             'Opt4-fit-address-group8-cec-r1-state.json',
             'Opt4-fit-field-address-cycle-consumer-r3-state.json',
             'Opt4-fit-owner-update-sequence-system-r3-state.json']
    save('route-b-adoption.json', dict(snapshot_utc=snap['utc'],
         states={n:snap['states'][n] for n in names if n in snap['states']},
         new_whole_synthesis=False, inputs_changed=False, signals_sent=False))
    previous = D / 'build-logs/Opt4-full-gg-package-analysis-round37-v1-20261111/result.json'
    local = read(previous)
    assert local['status'] == 'PASS_APPLICATION_AND_131_LOCAL_CHECKER_RESULTS'
    save('adopted-canneal-evidence.json', dict(path=str(previous), sha256=sha(previous),
         output_correctness=local['output_correctness'], roi=local['roi'], runtime=local['runtime'],
         local_checker_count=local['local_checker']['full_pass'],
         boom_result_acceptance=local['boom_result_acceptance'],
         drain=local['result_path_full_drain'], fpga_sample=False, rerun=False))
    sprint = read(D / 'opt4-sprint-24h-20261111/latest.json')
    hours = (datetime.datetime.fromisoformat(sprint['deadline_utc']) - now).total_seconds() / 3600
    save('resource-and-deadline.json', dict(utc=now.isoformat(),
         sprint_checkpoint_utc=sprint['utc'], deadline_utc=sprint['deadline_utc'], remaining_hours=hours,
         resources={k:snap[k] for k in ['available_memory_gib','free_disk_gib','loadavg']},
         risk='HIGH: latest full Opt4 postopt exceeds U280 by 1,543,702 LUT. Equivalent full-module and whole resources pending.',
         component_scope='Capacity fit is component-only; target clock coverage/timing/DRC and certificate still required.',
         whole_opt4_fpga_success=False, worker_fpga_io=False))
    status = repair['status'] if repair else jobs['v5']['state']['status']
    if repair:
        assert repair['restored_host_clock_aliases'] == 6
        assert repair['check']['returncode'] == 0 and repair['compile']['returncode'] == 0
        assert not repair['whole_fit'] and not repair['formal_fpga_sample']
    report = f'''Round 39 advanced the isolated recovery of the frozen MTModels+MCRams host compiler boundary. Latest status: {status}.

The saved wire audit proves all 24 overlapping channel pairs use identical payloads and aliases of one clock. The isolated repair preserves all 1,747 channels and all source/sink/payload/non-clock annotations; it canonicalizes 12 clock metadata references, three per checker tile. It uses the unmodified compiler JARs and target circuit. The checker requires original InferModelPorts rejection on original metadata, acceptance of corrected metadata, rejection after restoring a conflicting clock, then original FAMETransform and ResolveAndCheck validation. Full host continuation, target runtime parity and measured sharing gains remain separate obligations.

Version v1 stopped at my incorrect eight-reference inventory guard before invoking Scala. Its failure, controller, request and raw evidence are preserved. Version v2 corrects that inventory to twelve and uses independent outputs. No frozen source, live job inputs or compiler libraries were edited. Five exact tile classes are singletons, so no core sharing or area gain is inferred from this clock repair.

Actual version v2 outcome: original InferModelPorts PASS with 3,183 model-port annotations, exact same circuit object, original-metadata rejection and restored-clock-mutation rejection. Subsequent FAME validation FAILED with six undeclared FireSim Clock references. The overall v2 job correctly remains FAILED_WITH_EVIDENCE. A separate brokered diagnostic traced the original pre-excision wires: the four checker feedback clocks connect unconditionally to clockBridge_clocks_1; the two BOOM feedback clocks connect unconditionally to clockBridge_clocks_0. This was not inferred from frequency. Version v3 prepared six host-only internal aliases but stopped at a type guard because my standalone checker omitted the original DefineAbstractClockGate pass; no repaired output was validated. Version v4 restored the original pass ordering but its alias declarations followed their original uses, which HighForm rejected. Version v5 moves only those six declarations before the original body, preserving every existing connection and adding the six proven aliases to corresponding FAME gated-clock outputs. Every failure is retained. The sealed binding independently compares all six generated aliases to the root proof and rejects swapped domains or an ungated host_clock mapping. Latest actual v5 status: {status}. Full host output/runtime parity and MT sharing remain unvalidated.

Adopted the existing full frozen MCRams same-ELF Canneal comparison, original SVB component implementation and 21-only follower. Their exact state and PID/start/boot checks are saved. Reused round 37's Canneal evidence: correct output, 536,456 software ROI cycles, 392,248 instructions, 1,759,002 fastest target cycles, 131 local checker PASS records. These are CPU measurements; BOOM acceptance/release/full drain and strict checkerDone-minusBOOMDone remain unobserved. The 136-package direct RTL run is separate evidence with its own memory environment. No valid formal Opt4 FPGA sample is claimed.

Preserved live e0 whole synthesis, full DCache candidate/reference maps, CEC and existing composition consumers. 9ae is completed NOT FIT: 2,847,382 LUT, 90,740 CARRY8, 195 DSP; LUT excess 1,543,702. No third whole build or duplicated live task was launched. Actual e211 complete-address map remains 761,398 LUT and module-only. No additive savings or whole FIT are inferred.

The sprint deadline is {sprint['deadline_utc']}, approximately {hours:.2f} hours remaining at seal. Full Opt4 deadline risk is HIGH; component capacity FIT still needs routed timing/DRC/target-clock coverage and independent certification. Component routing is active with congestion and negative intermediate timing observed; these are not final implementation results. Native stays paused and this worker performed no FPGA I/O. Next: adopt the versioned check's exact successful outputs or preserve its failure and repair independently; continue from a verified host checkpoint, while the existing full MCRams and significant area jobs proceed.
'''
    with (O / 'REPORT.md').open('x') as f:
        f.write(report)
    changed = [str(Path(__file__).resolve())]
    for version in ['v1','v2','v3','v4','v5']:
        for root in [W / f'candidates/mt-clock-repair-round39-{version}-20261111',
                     D / f'build-logs/Opt4-mt-clock-repair-round39-{version}-20261111']:
            changed += [str(p) for p in root.rglob('*') if p.is_file()]
        changed += [str(U / f'requests/mt-clock-repair-r39-{version}-8491167d.json'),
                    str(D / f'Opt4-mt-clock-repair-round39-{version}-state.json')]
    changed += [str(p) for p in O.iterdir() if p.is_file()]
    for root in [W / 'candidates/mt-clock-residual-round39-v1-20261111',
                 D / 'build-logs/Opt4-mt-clock-residual-round39-v1-20261111']:
        changed += [str(p) for p in root.rglob('*') if p.is_file()]
    changed += [str(U / 'requests/mt-clock-residual-r39-v1-8491167d.json'),
                str(D / 'Opt4-mt-clock-residual-round39-v1-state.json')]
    save('changed-files.json', sorted(set(changed)))
    print(json.dumps(dict(report=str(O / 'REPORT.md'), repair_status=status, remaining_hours=hours,
                          full_opt4_fit=False, new_fpga_sample=False)))

if __name__ == '__main__':
    main()
