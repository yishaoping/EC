#!/usr/bin/python3
"""Seal round-38 evidence without changing any existing route input or owner."""
from pathlib import Path
import collections
import datetime
import hashlib
import json
import re

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
O = D / 'build-logs/Opt4-round38-two-route-evidence-v1-20261111'
A = D / 'build-logs/Opt4-mt-channel-audit-round38-v1-20261111'
C = W / 'candidates/mt-channel-audit-round38-v1-20261111'
P = W / 'candidates/full-mcrams-parity-round38-v1-20261111'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'


def read(path):
    return json.loads(Path(path).read_text())


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def save(name, value):
    with (O / name).open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True); f.write('\n')


def live(row):
    try:
        fields = Path(f"/proc/{row['pid']}/stat").read_text().rsplit(')', 1)[1].split()
        return (fields[0] not in ['Z', 'X'] and fields[19] == str(row['start_ticks'])
                and Path('/proc/sys/kernel/random/boot_id').read_text().strip() == row['host_boot_id'])
    except (OSError, KeyError):
        return False


def main():
    policy = read(U / 'campaign-policy.json')
    assert policy['functional_baseline_commit'] == BASE and policy['area_equivalence_only']
    assert not policy['functional_extensions_allowed'] and not policy['fpga_access'] and policy['native_paused']
    assert not O.exists(), 'Preserve immutable round evidence'
    audit = read(A / 'result.json')
    assert audit['status'] == 'PASS_ALL_CONFLICT_CLOCKS_WIRE_IDENTICAL_NO_REPAIR_APPLIED'
    assert len(audit['conflicts']) == 24
    aj = read(U / 'jobs/mt-channel-audit-r38-v2-8491167d/state.json')
    assert aj['status'] == 'COMPLETE' and aj['returncode'] == 0
    assert aj['outputs'][str(A / 'result.json')] == sha(A / 'result.json')
    # Independently restrict every traversed clock reference to a Clock port;
    # this rules out accidentally interpreting a register assignment as a wire.
    needed = {step['module'] for proof in audit['clock_proofs'].values() for step in proof['chain']}
    wanted = needed | {'FAMETop'}
    inventory = {}
    current = None
    fir = D / 'cycleprecise-frozen-mt-mcrams-r1-20261111/goldengate/post-channel-excision.fir'
    with fir.open() as f:
        for line in f:
            if line.startswith(('  module ', '  extmodule ')):
                current = re.match(r'\s*(?:module|extmodule) (\w+)\s*:', line)[1]
                if current in wanted:
                    inventory[current] = dict(ports={}, instances={})
            if current not in wanted:
                continue
            p = re.match(r'\s*(input|output) (\w+) : (.*?)(?: @\[.*)?\s*$', line)
            i = re.match(r'\s*inst (\w+) of (\w+)', line)
            if p:
                inventory[current]['ports'][p[2]] = p[3]
            if i:
                inventory[current]['instances'][i[1]] = i[2]
    hops = 0
    for proof in audit['clock_proofs'].values():
        for step in proof['chain']:
            module, ref = step['module'], step['reference']
            if '.' in ref:
                inst, ref = ref.split('.')
                module = inventory[module]['instances'][inst]
            assert inventory[module]['ports'][ref] == 'Clock', ('non_clock_port_in_proof', step)
            hops += 1
    anno = D / 'cycleprecise-frozen-mt-mcrams-r1-20261111/goldengate/post-channel-excision.json'
    annotations = [a for a in read(anno) if a.get('class', '').endswith('FirrtlEnableModelMultiThreadingAnnotation')]
    types = sorted({a['target'].rsplit(':', 1)[1] for a in annotations})
    counts = collections.Counter(inventory['FAMETop']['instances'].values())
    mt = {name: counts[name] for name in types}
    assert len(annotations) == 5 and all(count == 1 for count in mt.values())
    O.mkdir()
    save('mt-clock-proof-and-continuation.json', dict(
        functional_baseline=BASE, audit=str(A / 'result.json'), audit_sha256=sha(A / 'result.json'),
        source_fir_sha256=audit['inputs'][str(fir)], annotation_sha256=audit['inputs'][str(anno)],
        conflicts=24, identical_payload_and_wire_clock_for_all=True,
        all_clock_cone_hops_are_clock_ports=True, verified_clock_port_hops=hops,
        canonical_input='FireSim.clockBridge_clocks_1', unsafe_cases_rejected=6,
        identical_duplicate_connect_case_passed=True, multithread_annotated_instances_by_exact_module_type=mt,
        actual_mt_stage_reached=False, compiler_repair_applied=False, target_changed=False,
        causal_chain=dict(symptom='InferModelPorts ModulePortDeduper rejects partially overlapping ports (proven)',
             immediate_condition='Same payload with different clock Port names in 24 channel pairs (proven)',
             upstream_trigger='Intermodel hartid and synthesizedPrintf channels select distinct aliases of the same clock wire (proven)',
             downstream='FAME transform and MT sharing cannot be reached in this failed run (proven)'),
        next_repair_constraints=[
            'Use isolated versioned host compiler/stage copies; never modify frozen or live inputs.',
            'Canonicalize only metadata clock references proven to have the same unconditional wire root; retain every channel, payload, observation and target clock schedule.',
            'Re-run actual InferModelPorts/FAME validation and mutation rejection on distinct roots before further host build.',
            'Current FAME5 code filters exact module classes with one instance. All five annotated classes are singletons, so fixing the overlap alone does not prove or imply sharing.',
            'Any sharing of specialized Rocket variants needs explicit source-bound state/output/cycle equivalence and preserved per-hart identity.'],
        scope='Saved compiler boundary; not universal target equivalence, measured area saving or FPGA admission'))
    parity_name = 'full-mcrams-parity-r38-v1-8491167d'
    parity_state = read(D / 'Opt4-route-a-full-mcrams-parity-round38-v1-state.json')
    receipt = read(U / 'request-results' / (parity_name + '.json'))
    assert receipt['status'] == 'STARTED'
    assert live(parity_state) and live(parity_state['child'])
    save('mcrams-parity-started.json', dict(
        request=str(U / 'requests' / (parity_name + '.json')), broker=receipt,
        controller=parity_state, controller_identity_verified=True, child_identity_verified=True,
        plan=str(P / 'plan.json'), plan_sha256=sha(P / 'plan.json'),
        comparison_pending=True, finite_captured_outputs_only=True, full_observation_parity_passed=False,
        additional_review_before_parity_use='Inspect final fastest-target cycle count and FMR/host-resource rows alongside exact print/ROI comparisons; no full-state admission.'))
    snapshot = read(U / 'snapshot.json')
    names = ['Opt4-fit-update-share-svb-cad-state.json', 'Opt4-fit-dcache-full-pair-r2-state.json',
             'Opt4-fit-dcache-fieldbank-full-map-r4-state.json', 'Opt4-fit-dcache-field-read-full-map-r2-state.json',
             'Opt4-fit-address-update-sequence-r1-state.json', 'Opt4-fit-address-group8-cec-r1-state.json',
             'Opt4-fit-field-address-cycle-consumer-r3-state.json', 'Opt4-fit-owner-update-sequence-system-r3-state.json']
    save('route-b-adopted-snapshot.json', dict(utc=snapshot['utc'],
         states={n: snapshot['states'][n] for n in names if n in snapshot['states']},
         target_inputs_changed=False, new_whole_build_started=False, signals_sent=False))
    route_a = {}
    for name in ['original_svb_component_fpga_preparation', 'original_svb_component_21_follower']:
        q = Path(policy['parallel_evidence_routes']['route_a'][name]); st = read(q)
        route_a[name] = dict(path=str(q), state=st, identity_live_at_audit=live(st))
    q = D / 'cycleprecise-frozen-svb-fpga-r2-20261111/cad-state.json'; st = read(q)
    route_a['component_cad'] = dict(path=str(q), state={k:v for k,v in st.items() if k != 'stages'}, identity_live_at_audit=live(st))
    save('route-a-adoption.json', route_a)
    sprint = read(D / 'opt4-sprint-24h-20261111/latest.json')
    utc = datetime.datetime.now(datetime.timezone.utc)
    hours = (datetime.datetime.fromisoformat(sprint['deadline_utc']) - utc).total_seconds() / 3600
    save('capacity-and-sprint.json', dict(capacity=policy['latest_postopt_capacity'],
        sprint_utc=sprint['utc'], deadline_utc=sprint['deadline_utc'], remaining_hours=hours,
        resource_snapshot={k:snapshot[k] for k in ['utc','available_memory_gib','free_disk_gib','loadavg']},
        full_opt4_risk='HIGH: whole postopt exceeds U280 by 1,543,702 LUT. Live e0 and module maps are pending; no whole saving inferred from e211 or RAM boundaries.',
        component_risk='Component capacity fits; routing/timing/DRC/physical target-clock coverage and independent 21-only certification remain required.',
        full_opt4_fpga_success=False, new_fpga_sample=False))
    report = f'''Round 38 completed a source-bound audit of the failed frozen MTModels+MCRams compiler boundary and started the already-built full frozen MCRams model on the exact reference Canneal ELF.

All 24 overlapping channel pairs have identical payloads and clock ports wired to FireSim.clockBridge_clocks_1. The saved result retains every connection and source line. This seal independently checked all {hops} traversed references are Clock ports, so no register assignment was treated as a same-cycle wire. Six unsafe cases were rejected; identical duplicate connects passed. No compiler, target, annotation or existing input was changed. The first broker request was rejected for input-root binding; its evidence is retained. The replacement request used authenticated copies under W and completed with exit 0.

The failure occurs in InferModelPorts, before FAME or MT sharing. The five annotated module types each have exactly one top instance: {json.dumps(mt,sort_keys=True)}. Current MultiThreadFAME5Models filters singleton types. Resolving the channel overlap alone therefore provides no measured sharing or area gain. The continuation receipt records a restricted host-metadata repair principle and the separate equivalence obligation for specialized Rocket variants.

The existing full MCRams compiler completed successfully, binary SHA256 1fd2d1a399f2b1e4f84a295e614a5fc295123ac1030d316347bd1b4470b6cd8c. The broker STARTED the finite parity job; both its controller and child PID/start/boot identities were verified. It reuses ELF d0d0e9ae99bd963aeed84a8b395e7096f54985d117d11542d553a38680b8397b, identical memory arguments, target limit 5,000,000, host timeout 10,800 seconds and 4 GiB owned-log budget. Only executable and private print prefix differ from the original run. It preserves raw logs, compares both captured target print streams and all captured checker events/ROI/output records exactly, and measures peak child RSS. Its observations remain incomplete: BOOM acceptance/release/full drain and a complete application payload trace are unavailable. Final fastest-target cycles require review with the parity result. CPU metasimulation is not a formal FPGA sample.

Adopted existing e0 whole synthesis, full DCache maps/CEC/composition consumers, component implementation and original 21-only follower without restarting or changing inputs. e211's measured 761,398-LUT complete-address result remains module-only; no whole gain is inferred. 9ae remains completed NOT FIT: 2,847,382 whole postopt LUT, excess 1,543,702. The 24-hour deadline is {sprint['deadline_utc']} ({hours:.2f} hours remaining at seal). Full Opt4 remains high risk. The component's capacity fit still requires physical implementation and certification. Native remains paused; this worker performed no FPGA I/O and produced no new FPGA sample.
'''
    with (O / 'REPORT.md').open('x') as f:
        f.write(report)
    changed = sorted(str(p) for root in [C, P, A, O] for p in root.rglob('*') if p.is_file())
    changed += [str(Path(__file__).resolve()), str(D / 'Opt4-mt-channel-audit-round38-v1-state.json')]
    changed += [str(U / 'requests' / (n + '.json')) for n in
                ['mt-channel-audit-r38-v1-8491167d', 'mt-channel-audit-r38-v2-8491167d', parity_name]]
    save('changed-files.json', sorted(set(changed)))
    print(json.dumps(dict(report=str(O / 'REPORT.md'), clock_conflicts=24,
                          clock_port_hops=hops, parity_started=True, remaining_hours=hours)))


if __name__ == '__main__':
    main()
