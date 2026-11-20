#!/usr/bin/python3
"""Seal read-only adoption, failed-transform diagnosis and new preparation."""
from pathlib import Path
import datetime
import hashlib
import json

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
O = D / 'build-logs/Opt4-round36-two-route-preparation-v1-20261111'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda: f.read(2**20), b''):
            h.update(b)
    return h.hexdigest()


def save(name, value):
    with (O / name).open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True); f.write('\n')


def main():
    p = read(U / 'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE
    assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
    assert p['native_paused'] and not p['fpga_access']
    assert p['latest_postopt_capacity']['status'] == 'NOT_FIT_POSTOPT'
    assert not O.exists(), 'Immutable round evidence; use another version.'
    O.mkdir()
    snapshot = read(U / 'snapshot.json')
    names = ['Opt4-fit-update-share-svb-cad-state.json',
             'Opt4-fit-address-update-sequence-r1-state.json',
             'Opt4-fit-dcache-full-pair-r2-state.json',
             'Opt4-fit-dcache-fieldbank-full-map-r4-state.json',
             'Opt4-fit-dcache-field-read-full-map-r2-state.json',
             'Opt4-fit-address-group8-cec-r1-state.json',
             'Opt4-fit-field-address-cycle-consumer-r3-state.json']
    adopted = {n: snapshot['states'][n] for n in names}
    save('adopted-snapshot.json', dict(utc=snapshot['utc'],
                                    resources={k: v for k, v in snapshot.items() if k != 'states'},
                                    states=adopted, read_only=True, processes_signalled=False))
    mc = D / 'cycleprecise-frozen-mt-mcrams-r1-20261111'
    failed = read(mc / 'state.json'); text = (mc / 'goldengate.log').read_text()
    assert failed['status'] == 'FAILED_WITH_EVIDENCE'
    assert 'Channel definition has partially overlapping ports with existing channel definition' in text
    fame = W / 'C4/chipyard/sims/firesim/sim/midas/src/main/scala/midas/passes/fame'
    sources = [fame / n for n in ['FAMEUtils.scala', 'LabelMultiThreadedInstances.scala',
                                'MultiThreadFAME5Models.scala']]
    binding = read(mc / 'binding.json')
    diagnosis = dict(schema='ec-opt4-frozen-mt-mcrams-failure-diagnosis/1',
                     functional_baseline=BASE, failure_state=failed,
                     preserved_evidence={str(f): sha(f) for f in [mc / 'state.json',
                                          mc / 'goldengate.log', mc / 'binding.json', *sources]},
                     direct_symptom=dict(confidence='proven',
                         finding='InferModelPorts aborts in FAMEChannelAnalysis.ModulePortDeduper.'),
                     immediate_condition=dict(confidence='proven',
                         finding='A channel shares previously visited leaf ports without an identical (clock, ordered port list) channel definition. FAMEUtils rejects partial overlap.'),
                     upstream_trigger=dict(confidence='unproven',
                         finding='The exception does not identify the offending model/channel/ports. Raw per-channel definitions are needed before attributing it to a particular tile or memory.'),
                     downstream_effect=dict(confidence='proven',
                         finding='No completed MTModels+MCRams host RTL or full-system equivalence/area/FIT result from this attempt.'),
                     source_invariants=['LabelMultiThreadedInstances promotes the existing selected instances to FAME models when enabled.',
                                        'MultiThreadFAME5Models groups by exact OfModule and filters to repeated instances; at most one model class is supported.',
                                        'Five annotated tile instances include four specialized RocketTile module names and a BOOM tile. Their annotations do not establish shareable model identity.'],
                     original_memmodel_annotations=len(binding['memory_annotations']),
                     original_multithread_annotations=binding['multithread_annotations'],
                     target_fir_sha256=binding['target_fir_sha256'],
                     target_annotations_sha256=binding['target_annotations_sha256'],
                     target_or_compiler_changes=False, retry_started=False,
                     next='Preserve failure. Advance already completed MCRams-only host model through brokered compile, then same-target cycle/observation parity. Do not remove overlapping channels or merge specialized tiles without proof.')
    save('mt-mcrams-failure-diagnosis.json', diagnosis)
    v2 = W / 'candidates/full-mcrams-metasim-round36-v2-20261111'
    ready = D / 'cycleprecise-frozen-full-mcrams-metasim-round36-v2-20261111'
    req = U / 'requests/full-mcrams-metasim-r36-v2-8491167d.json'
    rr = U / 'request-results/full-mcrams-metasim-r36-v2-8491167d.json'
    rejection = U / 'request-results/full-mcrams-metasim-r36-v1-8491167d.json'
    preflight = read(ready / 'preflight.json')
    assert preflight['broker_inputs_validated'] == len(read(req)['spec']['inputs'])
    assert preflight['returncode'] == 0 and not preflight['compile_started']
    receipt = read(rr)
    save('compile-request-admission.json', dict(request=str(req), request_sha256=sha(req),
         broker_receipt=receipt, prior_rejection=read(rejection),
         prior_rejection_preserved=True, new_version=str(v2),
         preflight=preflight, kind='module', auxiliary_slot_not_used=True,
         started_or_adopted=receipt['status'].startswith(('STARTED', 'ADOPTED'))))
    sprint = read(D / 'opt4-sprint-24h-20261111/latest.json')
    deadline = datetime.datetime.fromisoformat(sprint['deadline_utc'])
    now = datetime.datetime.now(datetime.timezone.utc)
    remaining = (deadline - now).total_seconds()
    save('capacity-and-sprint.json', dict(functional_baseline=BASE,
         capacity=p['latest_postopt_capacity'], sprint_utc=sprint['utc'],
         deadline_utc=sprint['deadline_utc'], remaining_hours=remaining / 3600,
         sprint_resources=sprint['resources'],
         implementation_risk='HIGH: last completed whole design is 1,543,702 LUT over capacity; no verified aggregate successor whole report. Local RAM savings cannot be subtracted from this gap.',
         timing_risk='Original shell generated-XDC warnings require real target-domain clock and register coverage in any future certification. Preserve live CAD inputs.',
         full_opt4_fpga_success=False, component_capacity_is_separate=True))
    report = f'''Round 36 advanced the completed frozen MCRams-only host model toward full-system parity.

The isolated capsule stages its authenticated 183,665,269-byte host RTL, its own generated headers, and existing frozen driver sources. The compile plan uses two make jobs, a 64 GiB address-space limit, and 96 GiB available-memory/100 GiB disk guards. The recipe includes the prior plain-model static-library link repair. No RTL was regenerated or edited. All 158 broker inputs passed both frozen-scope and broker-root/hash validation; the print-only recipe passed. The ordinary module request is **{receipt['status']}**, so it is queued and no compile PID is claimed. Its successful build will still require full target-cycle/output/observation parity; it establishes no FIT or FPGA result.

Version 1 was rejected before execution because some manifest entries were outside W. Its controller, staged outputs, request and rejection remain intact. Version 2 binds immutable evidence copies in W and verifies original/staged paths again before compilation. Broker guards and services were not edited.

The exact frozen MTModels+MCRams transform failed in FAME channel analysis. The direct failure is partially overlapping channel ports, not an area or timing result. The emitting channel/model is not identified by that log, so its upstream cause remains unproven. Ten memory-model annotations and five tile annotations do exist. Exact module identity and channel semantics still gate sharing. No retry or annotation deletion was attempted.

Route B remains adopted: e0 whole synthesis; e211 address map; 221, d9 and 3656 full-DCache maps; group8 proof; and the existing unique 8d consumer. Their PID/start/boot identities and worker activity are preserved in adopted-snapshot.json. Completed 9ae post-opt is 2,847,382 LUT / 90,740 CARRY8 / 195 DSP, with LUT excess 1,543,702 and placement skipped by capacity guard. No third full Opt4 whole job was created. No measured whole saving is inferred from candidates whose maps remain live.

The original full-target Canneal CPU metasim and component CAD/21 follower remain owned by existing services. The earlier 136-package Canneal RTL result, 42,291 original SVB GG output comparisons, RAM library maps and component capacity are distinct evidence scopes. No complete application payload replay, strict checkerDone-minus-BOOMDone metric, full MCRams parity, complete Opt4 FIT, or new FPGA sample is claimed here. Native remains paused and the worker performed no FPGA I/O.

The sprint deadline is {sprint['deadline_utc']}; {remaining / 3600:.2f} hours remained at sealing. Whole-implementation risk remains high because the actual LUT gap is large. Next: let the broker start this one compile when an ordinary slot becomes free; adopt completion receipts from current maps and use the existing composed consumer only after significant measured gain and full verification. Certified full Opt4 FIT takes priority over further optimization.
'''
    (O / 'REPORT.md').write_text(report)
    files = []
    roots = [W / 'candidates/full-mcrams-metasim-round36-v1-20261111', v2,
             D / 'cycleprecise-frozen-full-mcrams-metasim-round36-v1-20261111', ready, O]
    for root in roots:
        files.extend(str(f) for f in root.rglob('*') if f.is_file())
    files.extend([str(Path(__file__).resolve()), str(req),
                  str(U / 'requests/full-mcrams-metasim-r36-v1-8491167d.json')])
    save('changed-files.json', sorted(files))
    save('result.json', dict(status='PASS_ISOLATED_SOURCE_BOUND_MCRAMS_COMPILE_PREPARATION_AND_ADOPTION',
         functional_baseline=BASE, request_status=receipt['status'], new_running_jobs=[],
         expensive_compile_started=False, source_rtl_changed=False, fpga_access=False,
         full_mcrams_parity=False, whole_opt4_fit=False,
         files={str(f): sha(f) for f in O.iterdir() if f.is_file()},
         ended_utc=now.isoformat()))
    print(json.dumps(dict(report=str(O / 'REPORT.md'), request_status=receipt['status'],
                         remaining_hours=round(remaining / 3600, 2), changed_files=len(files))))


if __name__ == '__main__':
    main()
