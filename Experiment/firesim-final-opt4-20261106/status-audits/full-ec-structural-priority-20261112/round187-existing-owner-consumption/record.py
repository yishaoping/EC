#!/usr/bin/env python3
"""Record existing owners and completed receipts; never launch or alter a job."""
from pathlib import Path
import datetime
import hashlib
import json
import os
import subprocess

D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
O = Path(__file__).resolve().parent
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
PREV = D/'status-audits/full-ec-structural-priority-20261112/round186-existing-owner-consumption'


def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def read(path):
    p = Path(path)
    return json.loads(p.read_text()) if p.exists() else {}


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for chunk in iter(lambda: f.read(4*2**20), b''):
            h.update(chunk)
    return h.hexdigest()


def save(path, value):
    path = Path(path)
    tmp = path.with_name(path.name+'.round187.tmp')
    tmp.write_text(json.dumps(value, indent=2, sort_keys=True)+'\n')
    os.replace(tmp, path)


def identity(pid):
    p = Path('/proc')/str(pid)
    try:
        text = (p/'stat').read_text()
        fields = text[text.rfind(')')+2:].split()
        return dict(pid=int(pid), start_ticks=fields[19], host_boot_id=BOOT,
                    cpu_ticks=int(fields[11])+int(fields[12]), process_state=fields[0],
                    rss_bytes=int(fields[21])*os.sysconf('SC_PAGE_SIZE'))
    except (FileNotFoundError, ProcessLookupError):
        return {}


def members(unit):
    group = '/user.slice/user-1008.slice/user@1008.service/'+unit
    path = Path('/sys/fs/cgroup/systemd'+group)/'cgroup.procs'
    rows = [identity(pid) for pid in path.read_text().split()] if path.exists() else []
    return [row for row in rows if row and row['process_state'] != 'Z']


def ref(path):
    return dict(path=str(path), sha256=sha(path))


def main():
    assert not (O/'owner-observation.json').exists(), 'Keep the original observation immutable'
    previous = read(PREV/'owner-observation.json')
    names = ['address-banked-production-area-pair-r5', 'common-stats-host-r6',
             'common-caller-geometry-closure-r1', 'common-stats-token-area-r3',
             'common-mixed-geometry-r1', 'common-composed-validate-r2',
             'common-composed-shell-cad-r1', 'common-composed-shell-cad-r2',
             'common-composed-shell-cad-r3', 'address-checkpoint-timing-r2']
    owners, progress, bindings = {}, {}, {}
    old_bindings = previous['source_bindings']
    for name in names:
        out = D/'build-logs'/('Opt4-'+name+'-20261113')
        statepath = out/('state.json' if (out/'state.json').exists() else 'queue.json')
        raw = statepath.read_bytes()
        state = json.loads(raw)
        unit = 'ec-opt4-'+name+'-20261113.service'
        rows = members(unit)
        live = identity(state.get('pid', -1))
        same = bool(live and state.get('host_boot_id') == BOOT
                    and state.get('start_ticks') == live['start_ticks']
                    and live['pid'] in {r['pid'] for r in rows})
        if not state['status'].startswith('FAILED'):
            assert same, (name, 'Owner identity changed; inspect before action')
        snapshot = O/(name+'-state.json')
        snapshot.write_bytes(raw)
        owners[name] = dict(state=str(statepath), state_sha256=hashlib.sha256(raw).hexdigest(),
            state_snapshot=str(snapshot), status=state['status'], updated_utc=state.get('updated_utc'),
            active_stage=state.get('active_stage'), controller=live, identity_matches=same,
            cgroup_members=rows, completed_result=(out/'result.json').exists())
        if name in previous.get('compute_progress_since_round185', {}):
            old = previous['compute_progress_since_round185'][name]
            match = next((r for r in rows if r['pid'] == old['compute_identity']['pid']
                         and r['start_ticks'] == old['compute_identity']['start_ticks']), None)
            assert match and match['host_boot_id'] == old['compute_identity']['host_boot_id']
            progress[name] = dict(compute_identity=match, previous_observation_utc=old['observed_utc'],
                observed_utc=now(), cpu_seconds_advanced=(match['cpu_ticks']-old['compute_identity']['cpu_ticks'])/os.sysconf('SC_CLK_TCK'),
                completed_result=(out/'result.json').exists(), is_feasibility_evidence=False)
        candidate = W/'candidates'/(name+'-20261113')
        bindingpath = candidate/'source-binding.json'
        binding = read(bindingpath)
        if name in old_bindings:
            assert sha(bindingpath) == old_bindings[name]['source_binding_sha256']
        controller = candidate/'controller.py'
        assert sha(controller) == binding['files'][str(controller)]
        bindings[name] = dict(source_binding=str(bindingpath), source_binding_sha256=sha(bindingpath),
            controller_sha256=sha(controller), experiment_commit=binding.get('experiment_commit'),
            hardware_commit=binding.get('hardware_commit'),
            unchanged_binding_from_round186=name in old_bindings,
            full_file_inventory_not_rehashed=True)
    save(O/'owner-observation.json', dict(schema='ec-existing-owner-bounded-observation/1', utc=now(),
        owners=owners, compute_progress_since_round186=progress, source_bindings=bindings,
        previous_observation=ref(PREV/'owner-observation.json'), no_job_actions=True))

    actual = {}
    for name, date in [('address-dsp-fullmodule-pair-r1','20261112'),
                       ('address-packed-full-module-r1','20261112'),
                       ('dcache-storage-compose-report-r4','20261113'),
                       ('address-banked-production-host-r6','20261113')]:
        path = D/'build-logs'/('Opt4-'+name+'-'+date)/'result.json'
        result = read(path)
        assert result['functional_baseline'] == BASE
        actual[name] = dict(result=ref(path), status=result['status'], scope=result['scope'],
            hardware_commit=result.get('hardware_commit'), source_variant=result.get('source_variant'))
        for key in ['savings','module_lut_saved','complete_module_lut_saving','target_cycles','observations','tokens']:
            if key in result:
                actual[name][key] = result[key]
    plain = D/'build-logs/Opt4-address-banked-production-area-pair-r5-20261113'
    row = read(plain/'map-Plain-receipt.json')
    assert row['accepted'] and row['returncode'] == 0 and not row['missing_outputs']
    verified = {}
    for path, digest in row['outputs'].items():
        if path.endswith('.rpt'):
            assert sha(path) == digest
            verified[path] = digest
    measured = read(plain/'paired-progress.json')
    actual['production_area_R5'] = dict(plain_receipt=ref(plain/'map-Plain-receipt.json'),
        paired_progress=ref(plain/'paired-progress.json'), verified_report_hashes=verified,
        Plain_resources=measured['area']['Plain']['resources'],
        Threaded_result_exists=(plain/'map-Threaded-receipt.json').exists(),
        pair_result_exists=(plain/'result.json').exists(), same_scope_gain=None,
        is_complete_EC=False, shell_included=False)
    adopted = read(D/'area-sprint-20261112/fullshell-adoptions.json')['results'][-1]
    assert adopted['scope'] == 'complete_u280_shell_postopt'
    for key in ['result','utilization','source_binding']:
        assert sha(adopted[key]) == adopted[key+'_sha256']
    fullshell = read(adopted['result'])
    assert fullshell['functional_baseline'] == BASE and fullshell['shell_included'] and fullshell['blackboxes'] == 0
    assert fullshell['hardware_commit'] == adopted['hardware_commit']
    actual['authoritative_complete_shell'] = dict(adoption=adopted,
        LUT=fullshell['resources']['CLB LUTs'], capacity=1303680,
        gap=fullshell['resources']['CLB LUTs']-1303680, full_system_fit=False)
    save(O/'actual-result-consumption.json', dict(schema='ec-existing-completed-result-consumption/1', utc=now(),
        actual=actual, no_additive_whole_saving=True, no_new_result_claim=True))

    prior = D/'unattended-opt4/jobs/field-address-cycle-cad-r3-8d50489a/state.json'
    gates = dict(schema='ec-current-structural-gate-review/1', utc=now(),
        functional_baseline=BASE, new_candidate_or_restart_allowed=False,
        unowned_implementable_prerequisite_found=False,
        AddressStats='Only R5 Threaded actual paired result remains; do not substitute other module references.',
        mixed='Existing commonR6 generation -> token-areaR3 exact73output3003token positive/negative -> actual paired area.',
        composition='Pinned validateR2 requires actual mixed gain>=300000, nonnegative completed DCache gain, fullcaller8/16/32 and exact predecessor cgroup release.',
        shell='OriginalR1 expected KeyError(returncode), no host-binding/cad-state and complete cgroup release precede existingR3 handoff; no additional mapper.',
        timing='R2 opens existing checkpoints at10ns; compare within its DSP and production matched pairs only. No resynthesis.',
        future_compiler='8359b23 future immutable compiler invocations only; currentR6 and pinnedR2 unchanged.',
        future_physical_reader='Bind ACTIVE shellR3 exact outputs after actual physical result; five oldR1 reader references already recorded in round184.',
        original8d50489a_root_service=dict(state=ref(prior), status=read(prior)['status'],
            ended_utc=read(prior).get('ended_utc'), terminal_from_previous_day=True,
            restarted=False, reports_preserved=True),
        no_FPGA_IO=True, no_CPU_session_control=True, no_SVB_control=True,
        no_hardware_source_change=True, no_new_software_certification_work=True,
        no_new_service=True, no_subagents=True)
    save(O/'gate-review.json', gates)
    print(json.dumps(dict(evidence_dir=str(O), progress=progress,
        current_status={name:row['status'] for name,row in owners.items()},
        Plain_LUT=actual['production_area_R5']['Plain_resources']['CLB LUTs'],
        fullshell=actual['authoritative_complete_shell']), indent=2))


if __name__ == '__main__':
    main()
