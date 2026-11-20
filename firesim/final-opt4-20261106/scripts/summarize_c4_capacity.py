#!/usr/bin/env python3
"""Summarize existing capacity evidence. Never control CAD or FPGA tasks."""
from pathlib import Path
import datetime
import json
import os

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D / 'build-logs/C4-capacity-20261110'


def read(path):
    return json.loads(path.read_text()) if path.exists() else {}


def utilization(path):
    rows = {}
    if path.exists():
        for line in path.read_text().splitlines():
            fields = [v.strip().replace(',', '') for v in line.split('|')]
            if len(fields) < 7:
                continue
            name = fields[1].rstrip('*')
            if name not in ['CLB LUTs', 'CLB Registers', 'CARRY8', 'DSPs', 'Block RAM Tile', 'URAM']:
                continue
            try:
                used, available = float(fields[2]), float(fields[5])
                rows[name] = dict(used=used, available=available,
                                  percent=100 * used / available)
            except (ValueError, ZeroDivisionError):
                continue
    return rows


def save(path, value):
    temp = path.with_name(path.name + '.summary.tmp')
    with temp.open('w') as stream:
        stream.write(value if isinstance(value, str) else json.dumps(value, indent=2) + '\n')
        stream.flush()
        os.fsync(stream.fileno())
    temp.replace(path)


def main():
    census = read(O / 'edif-capacity-census.json')
    candidate = read(W / 'candidates/capacity-exact-factor-20261110/candidate.json')
    physical_hierarchy = read(O / 'hierarchical-preopt-partition.json')
    original_report = D / 'build-logs/C4-dcp-20261110T071734Z/dut-utilization.rpt'
    reports = {
        'mapped_dut': original_report,
        'reopened_dut_preopt': O / 'vivado-preopt.rpt',
        'optimized_dut': O / 'vivado-postopt.rpt',
        'optimized_complete_top': O / 'top-postopt/utilization.rpt',
    }
    resources = {k: utilization(v) for k, v in reports.items()}
    cad = read(D / 'C4-dcp-cad-state.json')
    audit = read(D / 'C4-capacity-vivado-state.json')
    log = O / 'capacity.log'
    stages = [line for line in log.read_text(errors='replace').splitlines()
              if line.startswith('Phase ') or 'EC_CAPACITY_' in line] if log.exists() else []
    top = resources['optimized_complete_top']
    # A flat pre-opt count does not prove the complete top's post-opt size.
    top_state = read(D / 'C4-capacity-top-postopt-state.json')
    finished = top_state.get('status') in ['NOT_FIT_POSTOPT', 'CAPACITY_FITS_POSTOPT_TIMING_PENDING']
    verdict = ('NOT_FIT_POSTOPT' if any(v['used'] > v['available'] for v in top.values())
               else 'CAPACITY_FITS_POSTOPT_TIMING_PENDING') if top and finished else 'TOP_POSTOPT_PENDING'
    largest = [dict(module=h['module'], instances=h['instances'],
                    direct=h['direct'],
                    total_direct_lut_primitives=h['total_direct_lut_primitives'])
               for h in census.get('hierarchy', [])[:12]]
    summary = dict(
        schema='ec-c4-capacity-summary/1',
        observed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
        frozen_commit=census.get('hardware_commit'), source_id=census.get('source_id'),
        input_dcp=census.get('input_dcp'), input_dcp_sha256=census.get('input_dcp_sha256'),
        part='xcu280-fsvh2892-2L-e',
        device=dict(luts=1303680, ff=2607360, slices_carry8=162960, dsp48e2=9024,
                    bram_tiles=2016, uram=960, slrs=3),
        current_mapped_verdict='NOT_FIT', complete_top_verdict=verdict,
        optimized_dut_verdict=('NOT_FIT' if any(v['used'] > v['available'] for v in resources['optimized_dut'].values()) else 'CAPACITY_WITHIN_DEVICE') if resources['optimized_dut'] else 'PENDING',
        resources=resources, reports={k:str(v) for k,v in reports.items()},
        independent_dut_audit_status=audit.get('status'),
        independent_dut_audit_latest_stage=stages[-1] if stages else None,
        dcp_build_status=cad.get('status'),
        dcp_current_stage=cad.get('current_stage'),
        double_count_check=census.get('duplicate_definition_check'),
        largest_direct_modules=largest,
        preopt_physical_hierarchy=physical_hierarchy,
        primitive_count_caveat='Raw LUT1..6 instance counts are not packed physical CLB LUT counts. Direct module rows are disjoint; do not add inclusive ancestors. Synthesis may move cones across hierarchy.',
        candidate=candidate,
        no_automatic_candidate_admission=True, fpga_access=False, cad_signals=False,
        next_decision='Use complete top post-opt report before capacity-based pause/termination. Candidate cannot replace frozen formal hardware without explicit approval and full validation.',
    )
    save(O / 'capacity-summary.json', summary)
    lut = resources['mapped_dut'].get('CLB LUTs', {})
    lines = [
        '# Frozen C4 U280 capacity evidence', '',
        f"Observed UTC: {summary['observed_utc']}", '',
        f"Frozen commit: `{summary['frozen_commit']}`; DCP SHA256 `{summary['input_dcp_sha256']}`.", '',
        f"**Current mapped DUT: NOT FIT.** CLB LUTs {lut.get('used')} / {lut.get('available')} ({lut.get('percent',0):.5f}%). This is a real flat physical utilization report; independent recursive EDIF instance census passed duplicate-definition checks.", '',
        f"**Complete top after optimization: {verdict}.** DUT-only optimization cannot establish what top integration removes. Capacity fit would still require routing, setup/hold, DRC, bitstream certification, and FPGA validation.", '',
        f"Independent DUT audit: {audit.get('status')}; latest marker: {summary['independent_dut_audit_latest_stage']}. DCP build: {cad.get('status')} / {cad.get('current_stage')}.", '',
        f"DUT after opt_design: **{summary['optimized_dut_verdict']}**. This scope is distinct from complete-top integration. The independent Opt4-fit branch is `/data1/gzh/EC/firesim/final-opt4-20261106/Opt4-fit-20261110`, with module preparation/mapping/verification states under the Experiment root. It preserves frozen RTL and records a new hardware identity; no full DUT rebuild or admission occurs before capacity verification.", '',
        '| Scope | LUTs | CARRY8 | DSP |', '|---|---:|---:|---:|',
    ]
    for scope, rows in resources.items():
        values = [f"{rows[n]['used']:,.0f}/{rows[n]['available']:,.0f}" if n in rows else 'Not produced' for n in ['CLB LUTs','CARRY8','DSPs']]
        lines.append('| ' + scope + ' | ' + ' | '.join(values) + ' |')
    lines += ['', 'Physical LUT hierarchy before optimization (reported subtree rows; do not add ancestors):', '',
              '| Scope | Physical LUTs | FF | DSP |', '|---|---:|---:|---:|']
    for row in physical_hierarchy.get('rows', [])[:7]:
        lines.append(f"| {row['name']} ({row['module']}) | {row['luts']:,} | {row['ff']:,} | {row['dsp']:,} |")
    lines += ['', 'These report rows total 361 LUTs above the flat count; cross-hierarchy LUT combining means the authoritative device count is the flat report. Four Rocket checker tile subtrees total only 304,654 LUTs; reducing checker count alone cannot resolve the present excess. Top-direct combinational cells include logic moved across hierarchy and cannot be assigned to a source function from their module name.']
    lines += ['', 'Largest direct module populations (raw primitive counts, **not physical packed LUTs**):', '',
              '| Module | LUT primitives | LUT6 | CARRY8 | DSP | FF |', '|---|---:|---:|---:|---:|---:|']
    for h in largest:
        a = h['direct']; mult=h['instances']
        vals=[a.get(k,0)*mult for k in ['lut_primitives','lut6','carry8','dsp48e2','registers']]
        lines.append('| '+h['module']+' | '+' | '.join(f'{v:,}' for v in vals)+' |')
    lines += [
        '', 'Source findings and independent candidate:', '',
        '- Three GHBarrierLatencyStats instances and the L2 writeback reduction instantiate 1,024 per-bucket 64x64 multiplies. They calculate the same current-cycle factor repeatedly.',
        '- Independent candidate factors sum(cycle * count) into cycle * sum(count), retaining the 137-bit result, reset, state, overflow consumers and all events. Four 64x73 multiplies replace 1,024 operators. This is a candidate only, outside live/frozen sources.',
        '- Arithmetic distributivity and exact unsigned bounds checked; 2,120 boundary/random arithmetic vectors passed. Generated-leaf sequential comparison passed 2,048 cycles. These are not full-design equivalence proof.',
        '- Real candidate-leaf mapping: 83,179 physical LUTs; 41,601 FF; 2,955 CARRY8; 16 DSP, versus 2,048 DSP in the original instance. Original raw LUTs cannot be directly compared to candidate physical LUTs. Full design capacity/timing remains unverified.',
        '- PackageAddressStats alone contains 1,664,889 raw LUT primitives and 390,791 FF. Its packet bucket updates/deltas and associative tracking require further exact restructuring; the set tables already use SyncReadMem. Reducing queue/window/table sizes or disabling observation is not an approved equivalent solution.',
        '- dcache STOP snapshot waits for addressStats.idle and barrier pending==0. Deleting statistics changes the measurement/drain contract; it is not a safe shortcut.',
        '- Prefer no-RTL netlist optimization first. If it remains over capacity, the prepared arithmetic candidate is the smallest tested source-level option, but may be insufficient. It requires an explicitly approved derived profile and full validation before formal use.',
        '- A failed early DCP gate was diagnosed separately: Vivado creates dbg_hub_CV as an IS_DEBUG_CORE placeholder, implemented by the original place-stage implement_debug_core command. The confirmed-dead failed DCP controller was resumed with a precise placeholder rule and a later all-zero black-box gate. Failed logs are preserved. No live original CAD or Native was interrupted.',
        '- Full-top opt_design now writes utilization/DRC and keeps its checkpoint before placement. An actual excess blocks place/route automatically, without admitting any bitstream or changing frozen RTL.',
        '', 'Evidence:', '',
    ]
    for name,path in reports.items():
        lines.append(f'- {name}: [{path.name}]({path}) ({"present" if path.exists() else "not produced"}).')
    for path in [O/'edif-capacity-census.json', O/'edif-name-attribution.json', W/'candidates/capacity-exact-factor-20261110/candidate.json']:
        lines.append(f'- [{path.name}]({path}).')
    save(O / 'CAPACITY_REPORT.md', '\n'.join(lines)+'\n')
    print(json.dumps(dict(verdict=verdict, mapped=resources['mapped_dut'], report=str(O/'CAPACITY_REPORT.md'))))


if __name__ == '__main__':
    main()
