#!/usr/bin/python3
"""Seal new completed simulator evidence and preserve existing route ownership."""
from pathlib import Path
import datetime
import hashlib
import json

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
O = D / 'build-logs/Opt4-round37-two-route-evidence-v1-20261111'
A = D / 'build-logs/Opt4-full-gg-package-analysis-round37-v1-20261111'
C = W / 'candidates/full-gg-package-analysis-round37-v1-20261111'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
NAME = 'full-gg-package-analysis-r37-v1-8491167d'


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def save(name, value):
    with (O / name).open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')


def identity_live(row):
    if not row.get('pid'):
        return False
    try:
        fields = (Path('/proc') / str(row['pid']) / 'stat').read_text().rsplit(')', 1)[1].split()
        return (fields[0] not in ['Z', 'X'] and fields[19] == str(row['start_ticks'])
                and Path('/proc/sys/kernel/random/boot_id').read_text().strip() == row['host_boot_id'])
    except (OSError, KeyError, IndexError):
        return False


def main():
    p = read(U / 'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert not p['functional_extensions_allowed'] and not p['fpga_access'] and p['native_paused']
    assert not O.exists(), 'immutable round evidence'
    r = read(A / 'result.json')
    request = U / 'requests' / (NAME + '.json')
    broker = read(U / 'request-results' / request.name)
    job = read(U / 'jobs' / NAME / 'state.json')
    assert broker['status'] == 'STARTED' and job['status'] == 'COMPLETE' and job['returncode'] == 0
    assert job['outputs'][str(A / 'result.json')] == sha(A / 'result.json')
    assert r['negative_cases_rejected'] == 9 and r['local_checker']['full_pass'] == 131
    assert not r['formal_fpga_sample'] and not r['full_opt4_fit']
    O.mkdir()
    save('completed-analysis-admission.json', dict(request=str(request), request_sha256=sha(request),
         broker=broker, job={k: job[k] for k in ['status', 'pid', 'start_ticks', 'host_boot_id',
                  'started_utc', 'ended_utc', 'returncode', 'outputs']},
         result=str(A / 'result.json'), result_sha256=sha(A / 'result.json')))
    snapshot = read(U / 'snapshot.json')
    names = ['Opt4-fit-update-share-svb-cad-state.json',
             'Opt4-fit-address-update-sequence-r1-state.json',
             'Opt4-fit-dcache-full-pair-r2-state.json',
             'Opt4-fit-dcache-fieldbank-full-map-r4-state.json',
             'Opt4-fit-dcache-field-read-full-map-r2-state.json',
             'Opt4-fit-address-group8-cec-r1-state.json',
             'Opt4-fit-field-address-cycle-consumer-r3-state.json',
             'Opt4-fit-owner-update-sequence-system-r3-state.json']
    save('route-b-adopted-snapshot.json', dict(utc=snapshot['utc'],
         states={n: snapshot['states'][n] for n in names}, read_only=True,
         signals_sent=False, duplicate_whole_synthesis_started=False))
    route_a = {}
    for name in ['original_svb_component_fpga_preparation', 'original_svb_component_21_follower',
                 'full_frozen_metasim_recovery', 'complete_frozen_host_workload']:
        q = Path(p['parallel_evidence_routes']['route_a'][name])
        st = read(q)
        route_a[name] = dict(path=str(q), state=st, identity_live_at_audit=identity_live(st))
    q = D / 'cycleprecise-frozen-svb-fpga-r2-20261111/cad-state.json'
    cad = read(q)
    route_a['component_cad'] = dict(path=str(q),
         state={k: v for k, v in cad.items() if k != 'stages'},
         identity_live_at_audit=identity_live(cad))
    save('route-a-adoption.json', route_a)
    mc_req = U / 'requests/full-mcrams-metasim-r36-v2-8491167d.json'
    mc_plan = D / 'cycleprecise-frozen-full-mcrams-metasim-round36-v2-20261111/build-plan.json'
    mc = read(mc_plan)
    reference = D / 'cycleprecise-frozen-full-metasim-sample-r1-20261111/binding.json'
    rb = read(reference)
    save('mcrams-trace-comparison-preparation.json', dict(
         status='REFERENCE_READY_WAITING_EXISTING_MCRAMS_COMPILE', functional_baseline=BASE,
         existing_compile_request=str(mc_req), existing_compile_request_sha256=sha(mc_req),
         existing_compile_broker_receipt=read(U / 'request-results' / mc_req.name),
         build_plan=str(mc_plan), build_plan_sha256=sha(mc_plan),
         mcrams_host_rtl_sha256=mc['host_rtl_sha256'], target_fir_sha256=mc['target_fir_sha256'],
         target_annotations_sha256=mc['target_annotations_sha256'],
         reference_binding=str(reference), reference_binding_sha256=sha(reference),
         software_elf_sha256=rb['elf_sha256'], software_profile=rb['software_profile'],
         exact_reference_runtime_args=rb['args'],
         observed_reference_files={str(x): sha(x) for x in [A / 'checker-local-events.json',
              A / 'checker-local-intervals.json', A / 'stdout-selected-rows.json', A / 'result.json']},
         required_comparisons=['Exact same ELF, input, target clock ratios and memory timing/request parameters.',
              'Every captured local checker BEGIN/result value and checker-domain target cycle.',
              'Exact main-hart ROI start/end/cycles/instructions and application output.',
              'Fail on missing/extra events, changed timebase, status/cancel/full-compare mismatch or any error.'],
         preparation_limits=['No MCRams run started and no second compiler requested.',
              'Captured finite trace parity does not prove all required original outputs/state or universal equivalence.',
              'Complete real payload trace, BOOM result acceptance and full drain remain unobserved.'],
         full_observation_parity_passed=False, full_opt4_fit=False, fpga_access=False))
    sprint = read(D / 'opt4-sprint-24h-20261111/latest.json')
    now = datetime.datetime.now(datetime.timezone.utc)
    remaining = (datetime.datetime.fromisoformat(sprint['deadline_utc']) - now).total_seconds()/3600
    save('capacity-and-sprint.json', dict(capacity=p['latest_postopt_capacity'],
         sprint_utc=sprint['utc'], deadline_utc=sprint['deadline_utc'], remaining_hours=remaining,
         sprint_resources=sprint['resources'],
         risk='HIGH: actual whole design remains 1,543,702 LUT over capacity. Existing e0/module maps pending; no whole gain inferred.',
         component_risk='Capacity passes, but routing/timing/DRC/actual target clock coverage and independent certification must pass before existing 21-only follower acts.',
         full_opt4_fpga_success=False))
    text = f'''Round 37 validated the completed original GoldenGate Canneal CPU run without rebuilding or rerunning it.

The original application output matches checksum40b2b50000000000/verified1/routing_cost4789. Main-hart ROI: **536,456 cycles /392,248 instructions**. The model executed **1,759,002 fastest-target cycles in3121.7s**, measured563.476cycles/s, reportedFMR3.19; one host thread,3112.634CPU seconds, Verilator-reported16,565MB allocation (not peakRSS). Controller total was3136.113s. This is project400 bare-metal CPU metasimulation, separate from Linux formal PARSEC and the earlier136-package RTL harness run.

The 1,370,938,733-byte stdout was streamed and SHA256-verified once by the brokered analysis. All **131 checker BEGINs match131 local result-queue enqueues**, with status0/full_compare1/cancelled0, no duplicate or unmatched events and contiguous observed sequence1..131. Hart counts33/33/33/32. Nine actual-trace corruption tests were rejected: dropped begin/result, duplicate begin/result, failed status, missing full comparison, cancellation, wrong timebase and unknown record. Extracted exact events, intervals, histogram and selected stdout rows are retained in {A}.

These prints observe checker new_package and package_result_queue.enq.fire. They do not observe BOOM result dequeue/release, allocation or complete path drain. BEGIN→localenqueue is measured in the printed checker domain (1/2 base frequency): mean5593.290, median5009, P958875, P999805, max10025cycles. This is not checkerDone-minus-BOOMDone latency, and no CSR/print epoch alignment was assumed. No full payload replay or architectural restart claim is made. The preserved source diff records existing FireSim printf/service-idle integration; this analysis added no target logic and does not establish universal source/cycle equivalence.

The analysis service **{broker['unit']} actually started and completed** (PID{job['pid']}, start_ticks{job['start_ticks']}, boot{job['host_boot_id']}). Original producer results/logs were not edited. A source-bound reference for the existing MCRams compile is now prepared, including exact ELF/runtime parameters and required finite-trace comparisons. That existing compile remains broker-owned; no duplicate build or MCRams simulation was launched. Even a future finite trace match would not establish all required original observations or full Opt4 FIT.

Route B remains adopted from the saved snapshot at {snapshot['utc']}: live e0 whole synthesis; e211 address; 221/d9/3656 fullDCache maps; existing group8 proof and unique composed consumers. Completed9ae post-opt remains **2,847,382LUT /90,740CARRY8 /195DSP**, LUT excess1,543,702, stopped before placement. Existing original-SVB component CAD/21 follower remain independent; component capacity200,342LUT is not completeOpt4 FIT. No third fullOpt4 whole was started, no live inputs changed, no Native resumed and no worker FPGA I/O occurred.

Sprint deadline: {sprint['deadline_utc']}; {remaining:.2f}hours remained at sealing. Whole implementation risk remains high. Next: adopt actual module-map completion through existing composition gates and let the queued MCRams compiler start when an ordinary slot frees. Preserve component implementation and the certified21-only follower; true completeOpt4 FIT takes priority over extra optimization. No new FPGA sample exists.
'''
    with (O / 'REPORT.md').open('x') as f:
        f.write(text)
    files = sorted(str(f) for root in [C, A, O] for f in root.rglob('*')
                   if f.is_file() and '__pycache__' not in str(f))
    files.extend([str(Path(__file__).resolve()), str(request)])
    save('changed-files.json', sorted(files))
    save('result.json', dict(status='PASS_NEW_FROZEN_GG_APPLICATION_AND_LOCAL_CHECKER_EVIDENCE',
         functional_baseline=BASE, analysis_result_sha256=sha(A / 'result.json'),
         files={str(x): sha(x) for x in O.iterdir() if x.is_file()},
         launched_jobs=[broker['unit']], full_opt4_fit=False, valid_formal_fpga_sample=False,
         native_paused=True, fpga_access=False, ended_utc=now.isoformat()))
    print(json.dumps(dict(report=str(O / 'REPORT.md'), remaining_hours=remaining,
                         status='PASS_NEW_FROZEN_GG_APPLICATION_AND_LOCAL_CHECKER_EVIDENCE')))


if __name__ == '__main__':
    main()
