#!/usr/bin/env python3
"""Publish measured synth evidence and a bounded continuation handoff."""
import datetime
import hashlib
import json
import jsonschema
import os
from pathlib import Path

D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = Path(__file__).resolve().parent
POLICY = D / 'unattended-opt4/campaign-policy.json'


def sha(data):
    return hashlib.sha256(data).hexdigest()


def save(path, value):
    with path.open('x') as stream:
        json.dump(value, stream, indent=2, sort_keys=True)
        stream.write('\n')


def main():
    now = datetime.datetime.now(datetime.timezone.utc).isoformat()
    observation = json.loads((O / 'observation.json').read_text())
    hierarchy = json.loads((O / 'hierarchy.json').read_text())
    request_path = D / 'unattended-opt4/requests/mcrams-full-host-capacity-r1-3656aec4.json'
    request_bytes = request_path.read_bytes()
    request = json.loads(request_bytes)
    with (O / 'capacity-request.json').open('xb') as stream:
        stream.write(request_bytes)
    source_evidence = {}
    for path, digest in request['spec']['inputs'].items():
        source = Path(path)
        data = source.read_bytes()
        assert sha(data) == digest, path
        # The parser already has an exact copy in this audit.
        dest = O / ('capacity-' + source.name)
        with dest.open('xb') as stream:
            stream.write(data)
        source_evidence[path] = dict(sha256=digest, copy=str(dest))
    plan = json.loads((O / 'capacity-plan.json').read_text())
    assert plan['functional_baseline'] == observation['functional_baseline']
    assert plan['derived_hardware'] == observation['derived_target_commit']
    before = POLICY.read_bytes()
    policy = json.loads(before)
    assert policy['functional_baseline_commit'] == observation['functional_baseline']
    with (O / 'campaign-policy.before.json').open('xb') as stream:
        stream.write(before)
    evidence = dict(
        stage='synth', scope=observation['scope'],
        functional_baseline=observation['functional_baseline'],
        derived_target_commit=observation['derived_target_commit'],
        host_rtl_sha256=plan['host_rtl_sha256'],
        resources=observation['complete_host_synth_resources'],
        LUT_excess=observation['synth_LUT_excess'],
        postopt_final_result_pending=True, physical_FIT=False,
        report_receipt=str(O / 'observation.json'),
        report_receipt_sha256=sha((O / 'observation.json').read_bytes()),
        hierarchy=str(O / 'hierarchy.json'),
        hierarchy_sha256=sha((O / 'hierarchy.json').read_bytes()),
        addressStats_synth_LUTs=hierarchy['address_stats']['LUTs'],
        owner_image_wrapper_synth_LUTs=hierarchy['owner_image_wrapper']['LUTs'],
        captured_utc=observation['observed_utc'])
    policy['latest_mcrams_complete_host_synth'] = evidence
    handoff = (
        'Round135 published first actual complete owner-MCRams FPGATop OOC synth: '
        '2421933LUT/1696044FF/80994CARRY8/898.5BRAM/192DSP, zero blackboxes, '
        'synth LUT excess1118253; postopt still pending in captured early receipt, shell excluded, no physical FIT. '
        'Measured addressStats881587LUT; hoisted ownerImageMemory_flattened2218LUT (RamModel2217). '
        'Preserve existing capacity PID2379656/start25825451 and continue to authoritative postopt; no restart or new whole CAD. '
        'During capture existing r6 G finished FAILED final WNS-0.023/WHS+0.001 with39setup/0hold failures, no bitstream. '
        'Existing controller automatically started H VivadoPID3159232/start28601732 in exact physical-r6 cgroup. '
        'Adopt same foreground candidates/svb-r5-routed-repair-r6-20261112 and unchanged three services; H->I->J then all physical/certification gates and21-only directed/samebit replay. '
        'No reinstall, duplicate or source/gate edit. Existing r3 MCrams continuation and r4b IPcollateral observer match identities; preserve them. '
        'Original read-only metrics request is already STARTED (since06:24Z), PID2813002/start27638842, waiting certified r5 application receipts; preserve singleton and its own output, no guard bypass/duplicate/CPUcomparison control. '
        'Owner parity is completed finite captured-event parity, not full-state or strict-latency equivalence. '
        'Normal CAD checks>=300s; whole>=600s. Evidence: ' + str(O / 'receipt.json'))
    policy['foreground_request_for_next_worker'] = handoff
    policy['latest_worker_round135_measured_synth'] = dict(
        receipt=str(O / 'receipt.json'), status='MEASURED_HOST_SYNTH_PUBLISHED_R6_H_ADOPTED_NO_NEW_JOBS',
        utc=now, no_bound_source_changes=True, no_new_jobs=True)
    # Fail before mutation if another owner changed policy during capture.
    assert POLICY.read_bytes() == before, 'campaign policy changed concurrently'
    after = (json.dumps(policy, indent=2, sort_keys=True) + '\n').encode()
    tmp = POLICY.with_name('campaign-policy.round135.tmp')
    with tmp.open('xb') as stream:
        stream.write(after)
        stream.flush()
        os.fsync(stream.fileno())
    os.replace(tmp, POLICY)
    with (O / 'campaign-policy.after.json').open('xb') as stream:
        stream.write(after)
    files = {str(p): sha(p.read_bytes()) for p in sorted(O.iterdir()) if p.is_file()}
    receipt = dict(schema='ec-opt4-round135-critical-action/1', round=135, utc=now,
        status='FIRST_COMPLETE_HOST_SYNTH_COUNTS_AND_HIERARCHY_PUBLISHED',
        files=files, original_capacity_request_sha256=sha(request_bytes),
        capacity_bound_control_files=source_evidence,
        host_rtl_pinned_by_original_plan=plan['host_rtl_sha256'],
        campaign_policy_before_sha256=sha(before), campaign_policy_after_sha256=sha(after),
        complete_host_synth_LUTs=2421933, synth_LUT_excess=1118253,
        authoritative_postopt_pending=True, physical_FIT=False,
        r6_G_final_timing=observation['r6_G_final_timing'],
        r6_H_live=observation['r6_H_live'], r6_certified=False,
        metrics_request_status='EXISTING_STARTED_NOT_QUEUED',
        launched_jobs=[], new_requests=[], existing_processes_signalled=[],
        root_operations=[], FPGA_operations=[], CPU_comparison_controls=[],
        bound_source_changes=[], normal_CAD_recheck_seconds=300, whole_CAD_recheck_seconds=600,
        next_automatic_action='Existing r6 H->I->J, strict certification and21-only directed/samebit application on pass. Existing MCrams capacity continues to postopt; existing r3 continuation requires actual FIT plus finite parity; existing r4b observer only follows actual shell-contract failure.')
    save(O / 'receipt.json', receipt)
    result = dict(outcome='PROGRESS',
        summary='Published measured complete MCrams host synth: 2,421,933 LUTs (185.78%); post-opt and shell FIT pending. R6 G failed setup; existing H is running. No new jobs.',
        changed_files=[str(POLICY), str(O / 'receipt.json'), str(O / 'hierarchy.json'), str(O / 'REPORT.md')],
        evidence=[
            str(O / 'receipt.json') + ' sha256=' + sha((O / 'receipt.json').read_bytes()),
            'Synth reports verified against original early receipt; zero blackboxes; hierarchy/resource/primitive totals agree.',
            'R6 G final WNS -0.023 ns/WHS +0.001 ns, 39 setup failures; no bitstream. H Vivado PID3159232/start28601732 verified in exact physical-r6 cgroup.',
            'RUNNING: existing MCrams capacity, r6 H, r3 continuation, r4b observer and one read-only metrics consumer. QUEUED: no new requests; metrics is STARTED and waiting receipts.'
        ], launched_jobs=[],
        next_action='Preserve existing r6 H->I->J and strict certification/21-only replay gates. Await authoritative MCrams post-opt; shell physical requires FIT plus parity. Keep all bound sources, singleton consumers and resource guards unchanged.',
        retry_after_seconds=600)
    schema = json.loads((D / 'unattended-opt4/round-schema.json').read_text())
    jsonschema.validate(result, schema)
    result_path = D / 'unattended-opt4/rounds/round135-result.json'
    save(result_path, result)
    save(O / 'validation.json', dict(round_schema='PASS', copied_file_hashes='PASS',
         original_capacity_control_pins='4/4 PASS',
         strict_total_hierarchy_primitive_parser='PASS',
         result=str(result_path), receipt_sha256=sha((O / 'receipt.json').read_bytes())))
    print(json.dumps(result))


if __name__ == '__main__':
    main()
