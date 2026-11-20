#!/usr/bin/python3
"""Seal this worker's terminal receipts and scope-limited two-route findings."""
from pathlib import Path
import datetime
import hashlib
import json
import os
import re
import shutil

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
O = D / 'build-logs/Opt4-unattended-round34-evidence-v1-20261111'


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def save(p, j):
    with Path(p).open('x') as f:
        json.dump(j, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())


def live(identity, boot):
    if not identity or identity.get('host_boot_id') != boot:
        return False
    try:
        stat = Path('/proc') / str(identity['pid']) / 'stat'
        a = stat.read_text().rsplit(')', 1)[1].split()
        return a[19] == str(identity['start_ticks']) and a[0] not in ['X', 'Z']
    except (FileNotFoundError, KeyError):
        return False


def main():
    policy = read(U / 'campaign-policy.json')
    assert policy['area_equivalence_only'] and not policy['functional_extensions_allowed']
    assert policy['native_paused'] and not policy['fpga_access']
    assert not O.exists()
    O.mkdir()
    snapshot = read(U / 'snapshot.json')
    boot = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
    assert snapshot['host_boot_id'] == boot
    known = [
        'Opt4-fit-update-share-svb-cad-state.json',
        'Opt4-fit-address-update-sequence-r1-state.json',
        'Opt4-fit-dcache-field-read-full-map-r2-state.json',
        'Opt4-fit-dcache-fieldbank-full-map-r4-state.json',
        'Opt4-fit-dcache-full-pair-r2-state.json',
        'Opt4-fit-field-address-cycle-consumer-r3-state.json',
    ]
    adopted = {}
    for name in known:
        row = snapshot['states'].get(name, {})
        ids = [row.get('controller', {}), row.get('stage_process', {}),
               row.get('child', {}), *row.get('worker_processes', [])]
        unique = {}
        for identity in ids:
            if identity.get('pid'):
                unique[str(identity['pid'])] = dict(identity,
                    identity_live_at_seal=live(identity, boot))
        adopted[name] = dict(status=row.get('status'),
            snapshot_utc=snapshot['utc'], source_id=row.get('source_id'),
            hardware_commit=row.get('hardware_commit'), identities=unique,
            action='ADOPT_ONLY_NO_RESTART_NO_DUPLICATE')
    save(O / 'adopted-jobs.json', adopted)

    jobs = {}
    for name in ['postopt-rank-round34-v1-9ae9a7fc',
                 'postopt-rank-round34-v3-9ae9a7fc',
                 'field-read-address-rtl-prep-r34-v2-da8b51a6']:
        request = read(U / 'request-results' / (name + '.json'))
        job = read(U / 'jobs' / name / 'state.json')
        assert request['status'] == 'STARTED'
        assert job['status'] == 'COMPLETE' and job['returncode'] == 0
        assert not job['missing_outputs']
        assert all(sha(p) == digest for p, digest in job['outputs'].items())
        jobs[name] = dict(request=request, pid=job['pid'], start_ticks=job['start_ticks'],
            host_boot_id=job['host_boot_id'], returncode=0, status='COMPLETE', outputs=job['outputs'])
    failures = {}
    for name in ['postopt-rank-round34-v2-9ae9a7fc',
                 'field-read-address-rtl-prep-r34-v1-da8b51a6']:
        path = U / 'request-results' / (name + '.json')
        row = read(path)
        assert row['status'] == 'REJECTED_WITH_EVIDENCE'
        failures[name] = dict(path=str(path), sha256=sha(path), receipt=row,
            recovery='New request/version with authenticated evidence copies under W; original rejection unchanged.')
    save(O / 'launched-and-rejected-jobs.json', dict(completed=jobs, preserved_rejections=failures))

    rank_path = D / 'build-logs/Opt4-postopt-rank-round34-v3-20261111/result.json'
    rank = read(rank_path)
    prep_path = D / 'build-logs/Opt4-field-read-address-rtl-prep-round34-v2-20261111/result.json'
    prep = read(prep_path)
    assert rank['capacity_lut_excess'] == 1543702
    assert prep['class_count'] == 55 and prep['changed_source_count'] == 10
    assert rank['hypothetical_address_deletion_bound']['residual_excess_even_if_address_were_free'] == 651306

    route = D / 'cycleprecise-frozen-svb-trace-r4-20261111'
    binding = read(route / 'binding.json')
    result = read(route / 'result.json')
    assert result['negative_rejected'] and result['output_ports'] == 127
    assert sha(route / 'target-cycles.txt') == binding['trace_sha256']
    assert binding['trace_kind'] == 'SYNTHETIC_DIRECTED_ORIGINAL_COMPONENT_TRACE_NOT_APPLICATION'
    ports = binding['input_ports'] + binding['output_ports']
    assert len(binding['input_ports']) == 33 and len(binding['output_ports']) == 127
    lines = (route / 'target-cycles.txt').read_text().splitlines()
    for index, line in enumerate(lines):
        a = line.split()
        assert int(a[0]) == index and len(a) == 1 + len(ports)
        for value, (port, width) in zip(a[1:], ports):
            assert 0 <= int(value, 16) < 2**width, (index, port)
    assert len(lines) == result['target_cycles'] == 372
    compared = len(lines) - binding['compare_from_cycle']
    assert compared * 127 == result['compared_output_values'] == 42291
    assert sum(width for _, width in binding['output_ports']) == 5902
    harness = (route / 'TraceTest.cc').read_text()
    assert 'if(rows>=39)' in harness and 'step(1);' in harness
    assert 'PASS_SVB_TRACE target_cycles=372 compared_fields=42291 compare_from=39' in (route / 'compare.log').read_text()
    assert 'TARGET_HOST_MISMATCH cycle=40 port=io_capture_ready' in (route / 'negative.log').read_text()
    route_a = dict(schema='ec-opt4-independent-route-a-evidence-audit/1',
        status='PASS_RAW_SYNTHETIC_TRACE_BINDING_WIDTHS_COVERAGE_AND_RECEIPTS_NOT_A_NEW_SIMULATION',
        raw_trace_sha256=binding['trace_sha256'], rows=372, input_ports=33,
        output_ports=127, output_bits_per_cycle=5902, compared_cycles=compared,
        compared_output_values=42291, compare_from_cycle=39,
        initial_cycles_excluded_from_full_output_comparison=39,
        initial_output_values_not_compared=39 * 127,
        independent_host_value_comparison=False,
        scope='Independently authenticated all raw reference columns and recorded comparison receipts. Host values were checked by the existing foreground metasim service; no new simulator was run here.',
        remaining='Before claiming every required cycle, account for defined reset/warmup outputs in cycles0-38. No full application-payload real-trace replay is established.',
        trace_kind=binding['trace_kind'], complete_opt4=False, fpga_sample=False)
    full = D / 'cycleprecise-frozen-full-metasim-follow-r3-20261111'
    full_result = read(full / 'result.json')
    full_binding = read(full / 'binding.json')
    assert full_result['target_cycles'] == 10001 and not full_result['checker_pass']
    route_a['full_host_boot_probe'] = dict(
        target_cycles=10001, host_wall_seconds=full_result['host_wall_seconds'],
        returncode=full_result['returncode'], cycle_limit_stop=True,
        request_limits=[a for a in full_binding['args'] if re.match(r'\+mm_(read|write)MaxReqs_', a)],
        original_timing_parameter_admission_established=False,
        scope='Boot progress only. Runtime request limits are4; unchanged formal experiment parameters/output/checker/ROI admission is not established by this probe.')
    save(O / 'route-a-evidence-audit.json', route_a)
    sprint = read(D / 'opt4-sprint-24h-20261111/policy.json')
    now = datetime.datetime.now(datetime.timezone.utc)
    deadline = datetime.datetime.fromisoformat(sprint['deadline_utc'])
    risk = dict(deadline_utc=sprint['deadline_utc'], assessed_utc=now.isoformat(),
        remaining_seconds=int((deadline-now).total_seconds()),
        hardware_finding='HIGH_RISK_NOT_FIT_ACTUAL_9AE_POSTOPT',
        measured_luts=2847382, available_luts=1303680, excess_luts=1543702,
        available_memory_gib=snapshot['available_memory_gib'],
        disk_gib=snapshot['free_disk_gib'], loadavg=snapshot['loadavg'],
        resource_snapshot_utc=snapshot['utc'],
        constraints=['e0 has no completed resource report in this receipt; preserve effective synthesis.',
            'Local RAM time-multiplexing gains are not whole Opt4 gains. Ten coreRF annotations exist; major address/DCache arrays remain unannotated.',
            'Component synthetic host evidence and boot progress do not satisfy a real formal Opt4 FPGA sample.',
            'No architectural extensions, no Native resumption, no third whole, no worker FPGA access.'])
    save(O / 'sprint-risk.json', risk)
    bound = [rank_path, prep_path, Path(prep['build_plan']),
             route / 'binding.json', route / 'result.json', route / 'target-cycles.txt',
             route / 'TraceTest.cc', route / 'compare.log', route / 'negative.log',
             full / 'binding.json', full / 'result.json']
    save(O / 'bindings.json', {str(p): sha(p) for p in bound})
    (O / 'REPORT.md').write_text(
        '9ae is NOT FIT: actual top post-opt 2,847,382 LUT / 90,740 CARRY8 / 195 DSP; '
        'U280 LUT limit 1,303,680, excess 1,543,702. Its capacity-stop checkpoint is preserved.\n\n'
        'Completed hierarchy accounting preserves raw inclusive measurements and identifies42 shared-attribution overlaps. '
        'Reconciled allocations sum to2,847,382 LUT and are labeled accounting only. Address statistics measure892,396 inclusive LUT; '
        'even an impossible free-address bound leaves651,306 LUT excess. Preserve every instrumentation behavior. '
        'MSHR/probe instance labels may include hoisted DCache arrays; use source-bound memory evidence.\n\n'
        'da8 preparation authenticated and staged55 existing classes and10 changed-source files. Parameters, elaboration, GoldenGate '
        'commands and all7 ABI roles are prepared without recompiling or starting generation. Actual3656/e211 gains, candidate selection, '
        'complete combined generated equivalence, real ABI checks and physical certification remain required. Existing8d consumer is untouched.\n\n'
        'Route A independently audited the synthetic SVB raw trace:372 rows,33 inputs,127 outputs/5902 bits. '
        'Existing metasim compared42,291 outputs over333 cycles beginning at39 and rejected a mutation. '
        'The first39 cycles are excluded from the full comparison; defined reset/warmup outputs still need explicit coverage. '
        'This is synthetic component evidence, not application payload replay or an FPGA sample.\n\n'
        'The full frozen host boot probe advanced10,001 target cycles in26.065s and stopped at its limit. '
        'It used read/write request limits4, and establishes no unchanged formal experiment timing, ROI/output/checker pass. '
        'No new simulation or FPGA I/O was run by this worker. Deadline hardware risk remains high.\n\n'
        'Two broker input-root rejections were preserved. New versioned requests with W-bound snapshots completed successfully. '
        'e0, e211,3656,d9,fullpair and the unique8d consumer were adopted by PID/start/boot identity; no restart, duplicate whole or live-input edits.\n\n'
        'Next: collect existing module maps at600-second cadence, rank actual complete measured gains, and select one fully verified successor. '
        'Use the staged da8 plan only if it wins selection. Foreground Route A continues component CAD/certification and real payload capture. '
        'Any certified FIT immediately advances through the existing21-only runtime service; no functional recovery gate is added.\n')
    candidates = [
        'postopt-rank-round34-v1-20261111', 'postopt-rank-round34-v2-20261111',
        'postopt-rank-round34-v3-20261111',
        'field-read-address-rtl-prep-round34-v1-20261111',
        'field-read-address-rtl-prep-round34-v2-20261111']
    changed = [str(Path(__file__).resolve())]
    for name in candidates:
        changed += [str(p) for p in (W / 'candidates' / name).rglob('*') if p.is_file()]
    for pattern in ['Opt4-postopt-rank-round34-v*', 'Opt4-field-read-address-rtl-prep-round34-v*']:
        for p in (D / 'build-logs').glob(pattern):
            changed += [str(f) for f in p.rglob('*') if f.is_file()]
    changed += [str(p) for p in O.iterdir() if p.is_file()]
    changed += [str(p) for p in U.joinpath('requests').glob('*r34*da8b51a6.json')]
    changed += [str(p) for p in U.joinpath('requests').glob('postopt-rank-round34-*.json')]
    save(O / 'changed-files.json', sorted(set(changed)))
    progress = dict(outcome='PROGRESS', summary='Completed source-bound da8 RTL preparation and actual9ae capacity/hierarchy audit; no FIT or formal FPGA sample.',
        changed_files=[str(W / 'candidates/postopt-rank-round34-v3-20261111/controller.py'),
            str(W / 'candidates/field-read-address-rtl-prep-round34-v2-20261111/prepare.py'), str(O / 'REPORT.md')],
        evidence=[str(rank_path), str(prep_path), str(O / 'route-a-evidence-audit.json'), str(O / 'sprint-risk.json')],
        launched_jobs=[name + ': STARTED, COMPLETE returncode0' for name in jobs],
        next_action='Adopt existing maps after600seconds; select material measured equivalent gains, require composed generated verification and7ABI, and preserve e0/8d. Foreground RouteA continues independently; FIT immediately certified21-only runtime.',
        retry_after_seconds=600)
    save(U / 'rounds/round-00034/area-progress-v1.json', progress)
    print(json.dumps(progress, indent=2))


if __name__ == '__main__':
    main()
