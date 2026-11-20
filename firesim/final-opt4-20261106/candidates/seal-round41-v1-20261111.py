#!/usr/bin/python3
"""Seal round41 evidence by reading only recorded jobs and immutable receipts."""
from pathlib import Path
import datetime
import hashlib
import json
import os

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
O = D / 'build-logs/Opt4-round41-two-route-evidence-v1-20261111'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for data in iter(lambda: f.read(2**20), b''):
            h.update(data)
    return h.hexdigest()


def save(name, value):
    with (O / name).open('x') as f:
        json.dump(value, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())


def live(state):
    try:
        if state['host_boot_id'] != BOOT:
            return False
        fields = Path('/proc/' + str(state['pid']) + '/stat').read_text().rsplit(')', 1)[1].split()
        return fields[19] == str(state['start_ticks']) and fields[0] != 'Z'
    except (KeyError, FileNotFoundError):
        return False


def observed(p):
    p = Path(p)
    if not p.exists():
        return dict(path=str(p), exists=False)
    j = read(p)
    child = j.get('child', {})
    if j.get('child_pid'):
        child = dict(pid=j['child_pid'], start_ticks=j.get('child_start_ticks'), host_boot_id=j.get('host_boot_id'))
    return dict(path=str(p), value=j, controller_live=live(j), child_live=live(child))


def main():
    policy = read(U / 'campaign-policy.json')
    assert policy['functional_baseline_commit'] == BASE
    assert policy['area_equivalence_only'] and policy['native_paused']
    assert not policy['functional_extensions_allowed'] and not policy['fpga_access']
    assert policy['board_allowlist'] == ['0000:21:00.0']
    O.mkdir(exist_ok=False)
    now = datetime.datetime.now(datetime.timezone.utc)
    save('policy-observed.json', dict(observed_utc=now.isoformat(), sha256=sha(U / 'campaign-policy.json'),
         foreground_request=policy['foreground_request_for_next_worker'], latest_capacity=policy['latest_postopt_capacity']))
    preparation = {}
    for version in ('v1', 'v2', 'v3'):
        name = 'dcache-memmodel-prep-r41-' + version + '-3656aec4'
        broker = U / 'request-results' / (name + '.json')
        state = D / ('Opt4-dcache-memmodel-prep-round41-' + version + '-state.json')
        record = dict(broker=observed(broker), state=observed(state))
        logdir = D / ('build-logs/Opt4-dcache-memmodel-prep-round41-' + version + '-20261111')
        for filename in ('result.json', 'failure.json', 'memory-coverage.json'):
            p = logdir / filename
            if p.exists():
                record[filename] = dict(path=str(p), sha256=sha(p), value=read(p))
        preparation[version] = record
    save('annotation-preparation.json', preparation)
    host = dict(broker=observed(U / 'request-results/dcache-memmodel-host-r41-v1-3656aec4.json'),
                state=observed(D / 'Opt4-dcache-memmodel-host-round41-v1-state.json'))
    save('independent-host-generation.json', host)
    area_path = D / 'build-logs/Opt4-mcrams-dcache-entry-area-analysis-r1-20261111/result.json'
    area = read(area_path)
    assert area['status'] == 'CORRECTED_AREA_COMPLETE_NOT_FULL_DCACHE_OR_OPT4_FIT'
    resources = {label: {k: v['used'] for k, v in result['resources'].items()} for label, result in area['results'].items()}
    assert resources['PlainConfig']['CLB LUTs'] == 405706 and resources['MCConfig']['CLB LUTs'] == 24192
    save('actual-corrected-entry-area.json', dict(path=str(area_path), sha256=sha(area_path), resources=resources,
         saving_luts=381514, scope=area['scope'], whole_gain_claimed=False, original_parser_or_map_changed=False,
         original_failure_and_zero_lut_report_preserved=True))
    snapshot = read(U / 'snapshot.json')
    names = ['Opt4-fit-update-share-svb-cad-state.json', 'Opt4-fit-dcache-field-read-full-map-r2-state.json',
             'Opt4-fit-dcache-fieldbank-full-map-r4-state.json', 'Opt4-fit-dcache-full-pair-r2-state.json',
             'Opt4-fit-field-address-cycle-consumer-r3-state.json', 'Opt4-fit-owner-update-sequence-system-r3-state.json',
             'Opt4-fit-address-group8-cec-r1-state.json', 'Opt4-fit-address-update-sequence-r1-state.json']
    save('route-b-adoption.json', dict(snapshot_utc=snapshot['utc'], states={n: snapshot['states'][n] for n in names if n in snapshot['states']},
         whole_syntheses_launched=0, live_inputs_changed=False, signals_sent=False))
    route_a_paths = {
        'svb_component_original_cad': D / 'cycleprecise-frozen-svb-fpga-r2-20261111/cad-state.json',
        'svb_original_follower': D / 'cycleprecise-original-svb-onboard-r1-20261111/state.json',
        'svb_independent_spread': D / 'cycleprecise-svb-spread-implementation-r1-20261111/state.json',
        'svb_spread_follower': D / 'cycleprecise-original-svb-spread-onboard-r2-20261111/state.json',
        'full_canneal_observer_r3': D / 'Opt4-full-gg-external-observer-r3-state.json',
        'full_svb_payload_dispatch': D / 'Opt4-full-gg-external-observer-r5-dispatch-state.json',
        'full_svb_payload_r5': D / 'Opt4-full-gg-external-observer-r5-state.json',
        'full_mcrams_same_environment': D / 'Opt4-route-a-full-mcrams-parity-round38-v1-state.json',
        'original_svb_binary_replay': D / 'Opt4-original-svb-binary-replay-r1-state.json',
        'original_svb_replay_dispatch': D / 'Opt4-original-svb-binary-replay-r1-dispatch-state.json',
        'mt_host_continuation': D / 'Opt4-mt-host-continue-round40-v4-state.json'}
    save('route-a-adoption.json', {key: observed(p) for key, p in route_a_paths.items()})
    sprint = read(D / 'opt4-sprint-24h-20261111/policy.json')
    remaining = (datetime.datetime.fromisoformat(sprint['deadline_utc']) - now).total_seconds() / 3600
    save('resource-and-deadline.json', dict(utc=now.isoformat(), snapshot_utc=snapshot['utc'], remaining_hours=remaining,
         deadline_utc=sprint['deadline_utc'], resources={k: snapshot[k] for k in ('available_memory_gib', 'free_disk_gib', 'loadavg')},
         full_opt4_fit_risk='HIGH: measured whole top exceeds device by1543702LUT',
         component_risk='Routing, clock coverage, timing/DRC and source-bound21-only certification remain required.',
         worker_fpga_io=False, formal_opt4_fpga_sample_claimed=False))
    latest = preparation['v3']['state'].get('value', {}).get('status', 'NOT_STARTED')
    hstatus = host['state'].get('value', {}).get('status', 'NOT_STARTED')
    report = f'''Round41: exact-target DCache memory annotations and measured routeA area continuation.

Latest preparation: {latest}. Independent host generation: {hstatus}.
Version1 was rejected by the existing broker because experiment-directory receipts are outside its input root. Version2 staged immutable worktree receipt copies and started, then refused a Scala object-equality guard on separately deserialized annotations. Version3 uses canonical JSON value identity while preserving the target AST memory-resolution checks and four negative metadata cases. Original failures and all inputs are retained. No policy, broker guard, live source or live controller was edited.

The target FIRRTL remains the exact emitted3656aec4 bytes, derived from functional baseline8491167d. The controller stages four host annotations for image512x81/35R1W, generation512x32/518R1W, packet512x32/4R1W and tracked512x1/4R1W. Only a successful recorded resolver result establishes their AST resolution. Existing ten RF annotations and all bridge/observation/MT metadata remain intact. All512 generation observations, all518 generation readers, reset/written masking, target clocks and collision semantics are required downstream. Annotation preparation is neither complete DCache host/target equivalence nor area/FIT admission. The address module inventory has24 actual synchronous memories and37 register declarations; dominant RegVec state is not converted by annotation alone.

Corrected actual same-entry paired mapping completed: Plain405706LUT/65886FF/250CARRY8/0BRAM/0DSP; MCRams24192LUT/32721FF/250CARRY8/1.5BRAM/0DSP. Local difference381514LUT. Independent main-table/hierarchy/primitive checks reject the legacy erroneous0LUT parse. This is the reset-masked35read-entry host harness, not complete DCache or fullOpt4; the saving is never subtracted from whole capacity. Existing same-target finite entry proof retains178857defined values/2569cycles and both negative mutations.

The existing r5 application capture dispatcher and original-SVB replay timer were adopted. Startup10000cycle replay plus a directed data mutation passed in the existing replay service; this is not complete real-application payload replay. Existing r3Canneal, fullMCRams parity, originalSVB component implementation/spread and both21-only followers are preserved. The completed MT continuation emitted hostRTL from its verified checkpoint; ABI/blackbox validation and same-target runtime parity remain pending. No competing full application or component deployment was started.

RouteB remains active. Latest whole9ae postopt2847382LUT/90740CARRY8/195DSP is NOT FIT, gap1543702LUT. Livee0, three complete-DCache maps and source-bound consumers were adopted without modification or duplication. e211761398LUT is complete-address-module evidence only. No third whole synthesis or new target feature was introduced.

The host continuation submit.py is one-shot and dependency guarded. It publishes no request until the exact-target annotation preparation passes, then seals prerequisite copies underW and atomically submits one unique brokerRTL job. A DEFERRED request remains queued and is never described as running. Python syntax checks and the no-prerequisite exit path passed. No waiting CPU process or timer is added.

Sprint deadline{sprint['deadline_utc']}; {remaining:.2f}hours remain at seal. FullOpt4 FIT risk HIGH. Native stays paused; worker FPGA I/O is zero. No certified formalOpt4 FPGA sample is claimed. Next: adopt the queued preparation; after its actualPASS invokeW/candidates/dcache-memmodel-host-round41-v1-20261111/submit.py once. Preserve all original observation ports, validate same-target full-module cycles before real full-module area, and let existing component certification/runtime followers own21-only deployment.
'''
    (O / 'REPORT.md').write_text(report)
    changed = [str(Path(__file__).resolve())]
    for c in sorted((W / 'candidates').glob('dcache-memmodel-*-round41-v*-20261111')):
        changed.extend(str(p) for p in c.rglob('*') if p.is_file())
    changed.extend(str(p) for p in (U / 'requests').glob('dcache-memmodel-*-r41-*.json'))
    changed.extend(str(p) for p in O.iterdir() if p.is_file())
    save('changed-files.json', sorted(changed))
    print(json.dumps(dict(report=str(O / 'REPORT.md'), preparation=latest, host_generation=hstatus,
                         remaining_hours=remaining, changed_files_manifest=str(O / 'changed-files.json'))))


if __name__ == '__main__':
    main()
