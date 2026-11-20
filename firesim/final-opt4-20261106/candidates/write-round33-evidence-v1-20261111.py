#!/usr/bin/python3
"""Seal round 33 evidence and a passive next-stage contract; no jobs or device I/O."""
from pathlib import Path
import datetime
import hashlib
import json

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
OUT = D / 'build-logs/Opt4-unattended-round33-evidence-v1-20261111'
PRE = D / 'build-logs/Opt4-fit-field-read-address-compose-round33-v2-20261111'
AUDIT = D / 'build-logs/Opt4-route-a-svb-observation-audit-round33-v2-20261111'
JOB = U / 'jobs/field-read-address-precheck-r33-v2-da8b51a6/state.json'
BASELINE = '8491167d84b6d9521b151a743673c1516926a1f8'


def read(path):
    return json.loads(Path(path).read_text())


def sha(path):
    digest = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(2**20), b''):
            digest.update(block)
    return digest.hexdigest()


def write(path, value):
    with Path(path).open('x') as stream:
        json.dump(value, stream, indent=2, sort_keys=True)
        stream.write('\n')


def main():
    policy = read(U / 'campaign-policy.json')
    assert policy['area_equivalence_only'] and not policy['functional_extensions_allowed']
    assert policy['functional_baseline_commit'] == BASELINE
    assert policy['native_paused'] and not policy['fpga_access']
    assert not OUT.exists()
    broker = read(JOB)
    result_path = PRE / 'result.json'
    result = read(result_path)
    assert broker['status'] == 'COMPLETE' and broker['returncode'] == 0
    assert not broker['missing_outputs']
    assert broker['outputs'][str(result_path)] == sha(result_path)
    assert result['hardware_commit'] == 'da8b51a691cc104a5b32e13d2532ed9c836eb639'
    assert result['source_id'] == '4be542018125c2ba698f210e2bc769a789ba77a4e55432466552f14fceb11a9a'
    assert result['exact_component_source'] and result['frozen_parameters_match']
    assert result['normalized_component_address_rtl_equal']
    assert result['address_rtl_sha256'] == result['component_address_rtl_sha256']
    assert result['actual_component_area_pending'] and not result['area_admitted']
    assert result['final_generated_composed_dcache_equivalence_pending']
    for stage in result['stages'].values():
        assert stage['returncode'] == 0 and sha(stage['log']) == stage['log_sha256']
    audit = read(AUDIT / 'observation-inventory.json')
    assert audit['outputs'] == 127 and audit['output_bits'] == 5902
    assert audit['all_original_output_connections_verified']
    assert audit['all_original_output_peek_widths_channels_verified']
    assert not audit['all_output_cycle_comparison_verified']
    canneal_dir = D / 'cycleprecise-frozen-canneal-20261111'
    canneal = read(canneal_dir / 'result.json')
    assert canneal['status'] == 'PASS' and not canneal['errors']
    assert canneal['functional_baseline'] == BASELINE
    assert sha(canneal['analysis']) == canneal['analysis_sha256']
    analysis = read(canneal['analysis'])
    assert analysis['software_correct'] and not analysis['errors']
    assert analysis['packages']['generated'] == analysis['packages']['accepted_results'] == 136
    assert analysis['protocol']['status'] == 'PASS' and analysis['integrity']['status'] == 'PASS'
    full_dir = D / 'cycleprecise-frozen-full-metasim-r1-20261111'
    full_receipt = read(full_dir / 'receipts/compile.json')
    assert full_receipt['returncode'] == 2
    assert sha(full_receipt['log']) == full_receipt['log_sha256']
    compile_text = Path(full_receipt['log']).read_text()
    assert 'undefined reference to' in compile_text
    assert 'dwarf_siblingof' in compile_text and 'elf_version' in compile_text
    snapshot = read(U / 'snapshot.json')
    sprint = read(D / 'opt4-sprint-24h-20261111/latest.json')
    # Reuse the continuous monitor's exact sampled identities. No /proc traversal.
    adopted_names = [
        'Opt4-fit-bucket-tag-cad-state.json', 'Opt4-fit-update-share-svb-cad-state.json',
        'Opt4-fit-address-update-sequence-r1-state.json',
        'Opt4-fit-dcache-field-read-full-map-r2-state.json',
        'Opt4-fit-dcache-fieldbank-full-map-r4-state.json',
        'Opt4-fit-dcache-full-pair-r2-state.json']
    adopted = {}
    for name in adopted_names:
        row = snapshot['states'].get(name, {})
        adopted[name] = {key: row[key] for key in [
            'status', 'hardware_commit', 'source_id', 'pid', 'start_ticks', 'host_boot_id',
            'identity_live', 'controller', 'child', 'updated_utc', 'stage_log'] if key in row}
    dut_report = D / 'build-logs/Opt4-fit-bucket-tag-cad-9ae9a7fc/dut-utilization.rpt'
    prior_report = D / 'build-logs/Opt4-fit-cad-8da24a26/top-postopt-utilization.rpt'
    capacities = [row for row in sprint['reports'] if row['path'] in [str(dut_report), str(prior_report)]]
    assert len(capacities) == 2
    dut = next(row for row in capacities if row['path'] == str(dut_report))
    assert dut['resources']['CLB LUTs'] == 2767600
    assert dut['lut_gap_over_u280'] == 1463920
    created = datetime.datetime.now(datetime.timezone.utc).isoformat()
    evidence = dict(
        schema='ec-opt4-unattended-round33-evidence/1', created_utc=created,
        functional_baseline=BASELINE, fpga_access=False, native_paused=True,
        no_third_whole_launched=True, no_existing_job_or_rtl_modified=True,
        composition=dict(hardware_commit=result['hardware_commit'], source_id=result['source_id'],
                         result=str(result_path), result_sha256=sha(result_path),
                         status=result['status'], broker_status=broker['status'],
                         source_typecheck=True, frozen_parameters_match=True,
                         emitted_address_rtl_byte_hash_equal=True,
                         address_rtl_sha256=result['address_rtl_sha256'],
                         inherited_generated_identity_observations=2529,
                         inherited_frozen_dcache_cycles=8192,
                         inherited_frozen_dcache_observations=2534,
                         inherited_frozen_address_cycles=6144,
                         area_admitted=False, combined_generated_dcache_pending=True),
        route_a=dict(
            svb_observation_audit=str(AUDIT / 'observation-inventory.json'),
            output_count=127, output_bits=5902, test_body_mentions=14,
            all_output_cycle_comparison=False,
            canneal=dict(result=str(canneal_dir / 'result.json'), kind=canneal['kind'],
                         roi_cycles=canneal['roi_cycles'], roi_instructions=canneal['roi_instructions'],
                         total_harness_cycles=canneal['total_harness_cycles'],
                         host_wall_seconds=canneal['host_wall_seconds'], output=canneal['output'],
                         packages=136, accepted_pass_results=136,
                         svb_completions=analysis['protocol']['svb_completions'],
                         outstanding_at_end=analysis['protocol']['outstanding_at_end'],
                         roi_drain_tail_cycles=analysis['packages']['ROI_work_drain_tail_cycles'],
                         formal_fpga_sample=False, architectural_restart_established=False),
            full_host_metasim=dict(status='FAILED_WITH_EVIDENCE', returncode=2,
                                   receipt=str(full_dir / 'receipts/compile.json'),
                                   failure_stage='host driver link',
                                   observed_unresolved_symbol_families=['dwarf_*', 'elf_*', 'gelf_*'],
                                   interpretation='Build/link failure; no target functional conclusion.',
                                   foreground_recovery_owned=True)),
        resource_sample={key: value for key, value in snapshot.items() if key != 'states'},
        adopted_live_jobs_sample=adopted,
        capacity=capacities,
        sprint=dict(sample_utc=sprint['utc'], deadline_utc=sprint['deadline_utc'],
                    deadline_reached=sprint['deadline_reached'],
                    risk='HIGH: actual9ae DUT alone exceeds U280 LUT capacity by1463920. No9ae top post-opt FIT receipt or final e0/fullDCache/e211 resource receipt yet. Memory/time multiplexing boundary gains do not certify fullOpt4.',
                    no_deadline_success_claim=True),
        success_gate='A valid source/ABI/timing/DRC/capacity/bitstream-certified original-scheme formal Opt4 sample on21 through existing runtime services. None produced this round.')
    contract = dict(
        schema='ec-opt4-passive-next-stage-contract/1', created_utc=created,
        passive_only=True, no_job_submitted_by_this_contract=True, fpga_access=False,
        hardware_commit=result['hardware_commit'], source_id=result['source_id'],
        worktree=str(W / 'Opt4-fit-field-read-address-compose-round32-v1-20261111'),
        precheck_result=str(result_path), precheck_sha256=sha(result_path),
        exact_components=['3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c',
                          'e21194b24e3f9bf94c57dff009ed0c3d7d7eab7e'],
        actual_area_producers=[str(D / name) for name in adopted_names[2:]],
        required_gates=[
            'Adopt existing8d composition consumer; never duplicate its active GoldenGate/CAD.',
            'Authenticate final complete actual e211 address and3656 DCache reports against common references; exclude invalid or no-gain maps. Do not add isolated boundary savings.',
            'After material measured gains, use this passed exact-source compile and prepare one combined elaboration/GoldenGate version with original parameters and class origins.',
            'Verify complete actual combined DCache identity or frozen full-module cycle equivalence, preserving all original observations/assertions, plus exact composed address RTL.',
            'Audit all7 genuine generated ABI files; reuse driver only on byte equality, otherwise source-bound driver rebuild.',
            'No third whole while9ae/e0 remain live. Actual top post-opt capacity gate precedes placement. FIT advances immediately to timing/DRC/bitstream certification and existing21-only runtime services.',
            'For RouteA, foreground recovers metasim transport/link stages. After SVB metasim passes, compare every127 original output at required target cycles before standalone shell admission. Retain all raw failed receipts.'],
        poll_seconds=600, production_admitted=False)
    paths = [Path(__file__), JOB, result_path, AUDIT / 'observation-inventory.json',
             canneal_dir / 'result.json', Path(canneal['analysis']),
             full_dir / 'receipts/compile.json', dut_report, prior_report,
             U / 'request-results/field-read-address-precheck-r33-v1-da8b51a6.json',
             U / 'request-results/field-read-address-precheck-r33-v2-da8b51a6.json']
    bindings = {str(path): sha(path) for path in paths}
    policy = read(U / 'campaign-policy.json')
    assert policy['area_equivalence_only'] and not policy['fpga_access']
    OUT.mkdir()
    write(OUT / 'evidence.json', evidence)
    write(OUT / 'next-stage-contract.json', contract)
    write(OUT / 'bindings.json', bindings)
    write(OUT / 'policy-at-seal.json', policy)
    report = f'''Round33 completed the exact da8b51a6 composition precheck: combined changed-source typecheck, frozen parameter identity and emitted address RTL identity all passed. The broker authenticates returncode0 and the immutable result hash. The earlier missing-field verifier failure and broker input-root rejection remain preserved. The new controller verifies both local copies and original assertion provenance, without fabricating a missing receipt member or changing any target checks.

This precheck is not area admission. Actual e211/3656 complete-module maps, final combined generated DCache verification, real seven-file ABI audit and whole post-opt capacity/timing/DRC certification remain required. Both original whole jobs and existing module maps are adopted; no third whole was submitted.

RouteA has an independent validated frozen-target Canneal RTL result:485329 ROI cycles,392248 ROI instructions,136 accepted PASS package results,695 SVB completions and zero final outstanding protocol operations. Its checksum is verified. The262-cycle ROI work drain tail uses the existing same-domain analyzer. This is target RTL evidence, not FPGA/Linux formal performance or architectural restart evidence.

The static original-SVB wrapper audit verifies127 outputs/5902bits and matching channels. The directed body mentions14 outputs; a full cycle comparison is still pending. The r1 GoldenGate SVB run failed its occupancy/retention harness condition; the cause is unproven. Full frozen host metasim separately failed host linking on unresolved DWARF/ELF symbols (returncode2), with no target correctness conclusion. Foreground owns both recovery paths.

The measured9ae DUT uses2767600 LUT/89672 CARRY8/192 DSP, a1463920-LUT excess over U280 before full top capacity certification. The previous complete top post-opt report remains3215683 LUT. No9ae top FIT report or actual e0/fullDCache/e211 completed resource report is available in the adopted monitor sample. Deadline risk remains high. The24h deadline is{sprint['deadline_utc']}; sampled deadline_reached={sprint['deadline_reached']}.

Next: collect existing actual maps at600-second cadence, select only materially larger verified combinations, then run one combined generated verification/ABI path without duplicating the8d consumer or live wholes. Continue RouteA independently. Native remains paused; only existing certified21-only services can perform deployment. No formal FPGA sample was produced.
'''
    with (OUT / 'REPORT.md').open('x') as stream:
        stream.write(report)
    created_roots = [
        W / 'candidates/field-read-address-compose-round33-v1-20261111',
        W / 'candidates/field-read-address-compose-round33-v2-20261111',
        W / 'candidates/route-a-svb-observation-audit-round33-v1-20261111',
        W / 'candidates/route-a-svb-observation-audit-round33-v2-20261111',
        D / 'build-logs/Opt4-route-a-svb-observation-audit-round33-v1-20261111', AUDIT, OUT]
    files = {str(path) for root in created_roots for path in root.rglob('*') if path.is_file()}
    files.update(map(str, [W / 'candidates/prepare-field-read-address-round33-v2-20261111.py',
                          Path(__file__),
                          U / 'requests/field-read-address-precheck-r33-v1-da8b51a6.json',
                          U / 'requests/field-read-address-precheck-r33-v2-da8b51a6.json']))
    files.add(str(OUT / 'changed-files.json'))
    write(OUT / 'changed-files.json', dict(scope='Worker-created files only; broker/controller generated outputs are separately evidence.', files=sorted(files)))
    round_result = dict(
        outcome='PROGRESS',
        summary='da8b51a6 exact-source composition/typecheck/frozen-parameter/address-RTL precheck PASS. Preserved live CAD; no FIT or formal FPGA sample. RouteA output audit and Canneal evidence sealed.',
        changed_files=[str(W / 'candidates/prepare-field-read-address-round33-v2-20261111.py'),
                       str(W / 'candidates/field-read-address-compose-round33-v2-20261111/controller.py'),
                       str(W / 'candidates/route-a-svb-observation-audit-round33-v2-20261111/run.py'),
                       str(Path(__file__)), str(OUT / 'changed-files.json'),
                       str(OUT / 'evidence.json'), str(OUT / 'next-stage-contract.json'),
                       str(OUT / 'REPORT.md')],
        evidence=[str(result_path), str(AUDIT / 'observation-inventory.json'),
                  str(canneal_dir / 'result.json'), str(OUT / 'bindings.json')],
        launched_jobs=['field-read-address-precheck-r33-v2-da8b51a6: broker STARTED; COMPLETE returncode0'],
        next_action='At600-second cadence adopt9ae/e0/e211/3656/d9/fullpair reports. Require material actual full-module gains and combined generated equivalence/7ABI before any next whole; preserve8d consumer. Foreground continues RouteA transport/link recovery. FIT immediately certified21-only runtime.',
        retry_after_seconds=600)
    schema = read(U / 'round-schema.json')
    assert set(round_result) == set(schema['required'])
    assert round_result['outcome'] in schema['properties']['outcome']['enum']
    assert 30 <= round_result['retry_after_seconds'] <= 1800
    write(OUT / 'round-result.json', round_result)
    write(U / 'rounds/round-00033/area-progress-v1.json', round_result)
    print(json.dumps(dict(report=str(OUT / 'REPORT.md'), result=str(OUT / 'round-result.json'),
                          worker_changed_file_count=len(files), precheck_complete=True)))


if __name__ == '__main__':
    main()
