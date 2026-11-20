#!/usr/bin/python3
"""Read sealed paired hierarchy and failed physical reports; launch no CAD/FPGA.

Re-running verifies the original complete receipt without rewriting evidence.
"""
import csv
import hashlib
import io
import json
import os
from pathlib import Path
import re
from collections import defaultdict
from datetime import datetime, timezone

D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
OUT = D / 'build-logs/Opt4-fpga-critical-diagnosis-round119-v2-20261112'
AREA = D / 'build-logs/Opt4-mcrams-address-bucket-area-r2-20261112'
A = D / 'cycleprecise-svb-host40-shell-recovery-r2-20261112/A-shell-routing-placement'
B = D / 'cycleprecise-svb-host40-shell-recovery-r4-20261112/B-shell-FD-replicate'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
METRICS = ['LUT', 'logic_LUT', 'LUTRAM', 'SRL', 'FF', 'RAMB36', 'RAMB18', 'URAM', 'DSP']


def read(path):
    return json.loads(path.read_text())


def sha(path):
    h = hashlib.sha256()
    with path.open('rb') as f:
        for block in iter(lambda: f.read(1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def atomic(path, value):
    assert not path.exists(), ('immutable output exists', str(path))
    temp = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with temp.open('x') as f:
        f.write(value)
        f.flush()
        os.fsync(f.fileno())
    os.replace(temp, path)


def json_output(name, value):
    atomic(OUT / name, json.dumps(value, indent=2, sort_keys=True) + '\n')


def hierarchy(path):
    """Keep indentation; subtract immediate children, never add inclusive rows."""
    rows, self_rows, stack = {}, {}, []
    for number, line in enumerate(path.read_text().splitlines(), 1):
        fields = line.split('|')[1:-1]
        if len(fields) != 11 or not fields[2].strip().isdigit():
            continue
        raw, module = fields[:2]
        indent = len(raw) - len(raw.lstrip()) - 1
        assert indent >= 0 and indent % 2 == 0, (path, number)
        depth, name = indent // 2, raw.strip()
        values = dict(zip(METRICS, (int(x.strip()) for x in fields[2:])))
        if name.startswith('('):
            assert depth == len(stack) and name == '(' + stack[-1] + ')'
            parent = '/'.join(stack)
            assert parent not in self_rows
            self_rows[parent] = values
            continue
        stack = stack[:depth]
        assert len(stack) == depth, (path, number, 'missing parent')
        full_path = '/'.join(stack + [name])
        assert full_path not in rows, ('duplicate hierarchy path', full_path)
        rows[full_path] = dict(path=full_path, module=module.strip(), depth=depth,
                               report_line=number, inclusive=values)
        stack.append(name)
    assert list(rows)[0] == 'FPGATop'
    children = defaultdict(list)
    for name, row in rows.items():
        if row['depth']:
            children[name.rsplit('/', 1)[0]].append(row)
    for name, row in rows.items():
        exclusive = {k: row['inclusive'][k] - sum(c['inclusive'][k] for c in children[name])
                     for k in METRICS}
        assert all(v >= 0 for v in exclusive.values()), (name, exclusive)
        if name in self_rows:
            assert exclusive == self_rows[name], ('self-row mismatch', name)
        row['exclusive'] = exclusive
    for k in METRICS:
        assert sum(r['exclusive'][k] for r in rows.values()) == rows['FPGATop']['inclusive'][k]
    return rows


def category(path):
    if path.startswith('FPGATop/PeekPokeBridgeModule_0'):
        return 'PeekPoke bridge'
    if path.startswith('FPGATop/sim/PipeChannel'):
        return 'memory transport channels' if 'MemHarness_dut_bank_' in path else 'PeekPoke transport channels'
    if path.startswith('FPGATop/sim/target/') and '/MemHarness_dut_bank_' in path:
        return 'RAM model and wrapper'
    if path.startswith('FPGATop/sim/target'):
        return 'target adapter or register bank'
    return 'other host logic'


def partition(rows):
    result = defaultdict(lambda: dict.fromkeys(METRICS, 0))
    for row in rows.values():
        for k in METRICS:
            result[category(row['path'])][k] += row['exclusive'][k]
    return dict(result)


def timing(path):
    lines = path.read_text().splitlines()
    summary = None
    domains, paths, mode = [], [], None
    host_clock = None
    for i, line in enumerate(lines):
        if 'WNS(ns)' in line and summary is None:
            vals = lines[i + 2].split()
            if len(vals) == 12:
                summary = dict(wns_ns=float(vals[0]), tns_ns=float(vals[1]),
                               setup_violators=int(vals[2]), whs_ns=float(vals[4]),
                               hold_violators=int(vals[6]), pulse_violators=int(vals[10]))
        if line.startswith('| ') and not line.startswith('| -----'):
            mode = None
        if '| Intra Clock Table' in line:
            mode = 'intra'
        elif '| Inter Clock Table' in line:
            mode = 'inter'
        elif '| Other Path Groups Table' in line:
            mode = None
        fields = line.split()
        offset = 1 if mode == 'intra' else 2
        expected = [13] if mode == 'intra' else [6, 10]
        if mode and len(fields) in expected:
            try:
                vals = [float(x) for x in fields[offset:]]
            except ValueError:
                continue
            if mode == 'intra' and fields[0] == 'clk_out1_design_1_clk_wiz_0_0':
                host_clock = dict(clock=fields[0], wns_ns=vals[0], tns_ns=vals[1],
                                  failing_endpoints=int(vals[2]), whs_ns=vals[4])
            if vals[0] < 0:
                domains.append(dict(kind=mode, source_clock=fields[0],
                                    destination_clock=fields[offset - 1], wns_ns=vals[0],
                                    tns_ns=vals[1], failing_endpoints=int(vals[2])))
        if line.startswith('Slack (VIOLATED)'):
            entry = dict(slack_ns=float(re.search(r':\s*([-\d.]+)ns', line).group(1)),
                         report_line=i + 1)
            for text in lines[i + 1:i + 25]:
                for label in ['Source', 'Destination', 'Path Group', 'Path Type', 'Data Path Delay', 'Logic Levels']:
                    if text.strip().startswith(label + ':'):
                        entry[label] = text.strip().split(':', 1)[1].strip()
            paths.append(entry)
    assert summary == dict(wns_ns=-0.416, tns_ns=-386.608, setup_violators=2687,
                           whs_ns=0.001, hold_violators=0, pulse_violators=0), summary
    assert host_clock and host_clock['wns_ns'] == 2.987 and host_clock['failing_endpoints'] == 0
    expected = {
        ('intra', 'GTYE4_CHANNEL_TXOUTCLK[3]_3', 'GTYE4_CHANNEL_TXOUTCLK[3]_3'): (175, -14.743),
        ('intra', 'xdma_0_axi_aclk', 'xdma_0_axi_aclk'): (696, -149.142),
        ('intra', 'mmcm_clkout0', 'mmcm_clkout0'): (1762, -217.203),
        ('inter', 'xdma_0_axi_aclk', 'GTYE4_CHANNEL_TXOUTCLK[3]_3'): (51, -3.690),
        ('inter', 'GTYE4_CHANNEL_TXOUTCLK[3]_3', 'xdma_0_axi_aclk'): (19, -2.763),
    }
    observed = {(r['kind'], r['source_clock'], r['destination_clock']):
                (r['failing_endpoints'], r['tns_ns']) for r in domains}
    assert observed == expected, observed
    count = sum(d['failing_endpoints'] for d in domains)
    total_tns = round(sum(d['tns_ns'] for d in domains), 3)
    assert count == 2703 and total_tns == -387.541
    return dict(summary=summary, failing_clock_groups_not_disjoint=domains,
                host_clock_group=host_clock,
                clock_group_additivity=dict(failing_group_memberships=count,
                    design_unique_endpoints=summary['setup_violators'],
                    excess_group_memberships=count - summary['setup_violators'],
                    sum_group_TNS_ns=total_tns, design_TNS_ns=summary['tns_ns'],
                    excess_negative_group_TNS_ns=round(summary['tns_ns']-total_tns, 3),
                    explanation='A destination endpoint can fail paths in more than one clock-pair group. These group counts/TNS do not form a nonoverlapping design partition; the design summary remains authoritative.'),
                reported_failing_paths=paths, not_exhaustive_path_listing=True)


def main():
    policy = read(D / 'unattended-opt4/campaign-policy.json')
    session = read(D / 'FPGA_SESSION_POLICY.json')
    assert policy['functional_baseline_commit'] == session['functional_baseline_commit'] == BASE
    assert session['board_allowlist'] == ['0000:21:00.0'] and session['area_equivalence_only']
    if (OUT / 'complete.json').exists():
        complete = read(OUT / 'complete.json')
        for path, digest in {**complete['inputs'], **complete['outputs']}.items():
            assert sha(Path(path)) == digest, ('completed diagnosis changed', path)
        print('ADOPTED_IMMUTABLE_COMPLETE_DIAGNOSIS')
        return
    OUT.mkdir(parents=True, exist_ok=True)
    inputs = {}

    def bound(path, expected=None):
        digest = sha(path)
        assert expected is None or digest == expected, ('sealed input hash mismatch', str(path))
        inputs[str(path)] = digest
        return digest

    bound(Path(__file__))
    bound(W / 'candidates/fpga-critical-diagnosis-round119-v1-20261112/analyze.py')
    bound(D / 'build-logs/Opt4-fpga-critical-diagnosis-round119-v1-20261112/failed-attempt.json')
    area = read(AREA / 'result.json')
    bound(AREA / 'result.json', '8b210902fff2ed28e2da5d58ba355a081b9c536fda178ac52f1e46627221dabc')
    bound(AREA / 'area-decision.json')
    rows, parts = {}, {}
    for model in ['Reg', 'MemMC']:
        receipt = area['models'][model]
        bound(Path(receipt['report']), receipt['report_sha256'])
        h = Path(receipt['hierarchical_report'])
        bound(h, receipt['hierarchical_sha256'])
        rows[model] = hierarchy(h)
        parts[model] = partition(rows[model])
        top = rows[model]['FPGATop']['inclusive']
        assert top['LUT'] == receipt['resources']['CLB LUTs']
        assert top['FF'] == receipt['resources']['CLB Registers']
        assert top['RAMB36'] + top['RAMB18'] / 2 == receipt['resources']['Block RAM Tile']
    delta = []
    for name in sorted(set(parts['Reg']) | set(parts['MemMC'])):
        before = parts['Reg'].get(name, dict.fromkeys(METRICS, 0))
        after = parts['MemMC'].get(name, dict.fromkeys(METRICS, 0))
        delta.append(dict(category=name, Reg=before, MemMC=after,
                          delta={k: after[k] - before[k] for k in METRICS}))
    assert sum(r['delta']['LUT'] for r in delta) == 60726
    assert sum(r['delta']['FF'] for r in delta) == 39227
    assert parts['MemMC']['RAM model and wrapper']['LUT'] == 46784
    assert parts['MemMC']['RAM model and wrapper']['FF'] == 17284
    assert parts['MemMC']['RAM model and wrapper']['RAMB36'] == 1

    channel_groups = defaultdict(lambda: dict(count=0, LUT=0, FF=0))
    for row in rows['MemMC'].values():
        name = row['path'].split('/')[-1]
        if row['depth'] != 2 or not name.startswith('PipeChannel') or 'MemHarness_dut_bank_' not in name:
            continue
        key = 'response_data' if name.startswith('PipeChannel_MemHarness_dut_bank_') else (
            ('read_' if 'io_' in name else 'write_') + name.rsplit('_', 1)[-1])
        group = channel_groups[key]
        group['count'] += 1
        for k in ['LUT', 'FF']:
            group[k] += row['inclusive'][k]
    assert sum(x['count'] for x in channel_groups.values()) == 1796
    assert sum(x['LUT'] for x in channel_groups.values()) == 16642
    assert sum(x['FF'] for x in channel_groups.values()) == 36872

    sv = D / 'build-logs/Opt4-mcrams-address-bucket-r5-20261112/MemMC/FireSim-generated.sv'
    # Reuse the producer's complete host identity; hash only the narrowly inspected module.
    text = sv.read_text()
    match = re.search(r'^module RamModel\(.*?^endmodule', text, re.M | re.S)
    assert match
    module = match.group()
    counts = {}
    for label, pattern, expected in [
        ('read_ports', r'input\s+channels_read_cmds_(\d+)_valid', 258),
        ('write_ports', r'input\s+channels_write_cmds_(\d+)_valid', 256),
        ('response_snapshots_64bit', r'^\s*reg\s+\[63:0\]\s+read_resp_data_(\d+)\s*;', 258),
        ('read_states_2bit', r'^\s*reg\s+\[1:0\]\s+read_state_(\d+)\s*;', 258),
        ('write_complete_bits', r'^\s*reg\s+write_complete_(\d+)\s*;', 256),
    ]:
        ids = set(map(int, re.findall(pattern, module, re.M)))
        assert ids == set(range(expected)), (label, len(ids))
        counts[label] = len(ids)
    source_root = W / 'C4/chipyard/sims/firesim/sim/midas/src/main/scala/midas'
    for p in [W / 'candidates/mcrams-address-bucket-r5-20261112/Bucket.scala',
              source_root / 'models/sram/AsyncMemModel.scala', source_root / 'core/Channel.scala']:
        bound(p)
    generated = dict(path=str(sv), producer_host_sha256=area['models']['MemMC']['host_rtl_sha256'],
                     inspected_module='RamModel', inspected_module_sha256=hashlib.sha256(module.encode()).hexdigest(),
                     module_start_line=text[:match.start()].count('\n') + 1,
                     counts=counts, source_declared_response_payload_bits=258 * 64,
                     warning='Source register declarations are not a bit-for-bit mapped cell attribution.')

    bound(A / 'result.json')
    a_result = read(A / 'result.json')
    bound(A / 'final-timing.rpt', a_result['outputs'][str(A / 'final-timing.rpt')])
    physical = timing(A / 'final-timing.rpt')
    bound(B / 'result.json')
    b_result = read(B / 'result.json')
    bound(B / 'recovery.log', b_result['outputs'][str(B / 'recovery.log')])
    log = (B / 'recovery.log').read_text()
    message = 'Option -force_replication_on_nets is specified but not supported yet for post-route physical synthesis.'
    assert message in log and 'EC_HOST40_NEGATIVE_SHELL_Q_DIAGNOSTIC nets=9' in log
    physical['B_failure'] = dict(status='TOOL_MODE_ERROR_NOT_MEASURED_REPLICATION_FAILURE',
                                 selected_exact_FD_Q_nets=9, error=message,
                                 next_verification='Check supported pre-route physical mode from a separately sealed placed checkpoint or an explicitly unrouted copy; preserve active C/D and all clocks/gates. Do not retry this command on a fully routed design.')
    physical['causality'] = dict(symptom='Proven setup failure, WNS -0.416ns.',
        immediate_block='Proven PCIe and DDR shell setup violations; final all-clock gate rejected bitgen.',
        upstream_trigger='Sampled shell paths are route dominated; physical origin beyond these paths is unproven.',
        amplifier='Multiple independent shell domains remain failing; host frequency change alone does not close them.')

    result = dict(schema='ec-fpga-critical-path-diagnosis/1', functional_baseline=BASE,
                  status='PASS_RECONCILED_SAVED_HIERARCHY_AND_PHYSICAL_FAILURE_DIAGNOSIS',
                  fpga_access=False, CAD_started=False, simulator_started=False,
                  hardware_inputs_modified=False, whole_FIT=False, FPGA_samples=0,
                  paired_area=dict(Reg_LUT=57148, MemMC_LUT=117874, LUT_regression=60726,
                      FF_regression=39227, nonoverlapping_partition=delta,
                      memory_transport=channel_groups, generated_model=generated,
                      interpretation='Serialized RAM with per-reader snapshots and per-port token transport costs more than this register bank. Wide observation and parallel updates remain mandatory.',
                      next='Keep this layout rejected. Use actual complete owner-host hierarchy when its existing synthesis completes; do not repeat this losing full-address synthesis.'),
                  SVB_A_and_B=physical, inputs=inputs)
    json_output('result.json', result)
    stream = io.StringIO()
    writer = csv.writer(stream)
    writer.writerow(['category', 'Reg_LUT', 'MemMC_LUT', 'delta_LUT', 'Reg_FF', 'MemMC_FF', 'delta_FF'])
    for r in delta:
        writer.writerow([r['category'], r['Reg']['LUT'], r['MemMC']['LUT'], r['delta']['LUT'],
                         r['Reg']['FF'], r['MemMC']['FF'], r['delta']['FF']])
    atomic(OUT / 'paired-area-partition.csv', stream.getvalue())
    json_output('hierarchy-exclusive-rows.json', rows)
    report = '''Saved reports account for the entire address-bank regression: +60,726 LUT and +39,227 FF. The nonoverlapping partition is in paired-area-partition.csv. All hierarchy totals, immediate-child subtraction, explicit self rows, and LUT/FF/BRAM totals reconcile against both sealed utilization reports.

The MemMC model contains 258 readers, 256 writers, 258 separate 64-bit response snapshots, and 1,796 memory token channels. The mapped RAM model/wrapper is 46,784 LUT, including one RAMB36. The channels add 16,642 LUT/36,872 FF. Common bridge overhead does not explain the regression. This is an isolated state-interface harness, not full address arithmetic, complete DCache, whole capacity or FPGA data. No target observations or parallel updates may be removed to make this result smaller.

SVB A failed all-clock setup (WNS -0.416ns, TNS -386.608ns, 2,687 endpoints), with nonnegative hold. The DDR intra-clock group reports 1,762 endpoints/TNS -217.203ns; PCIe intra groups report 696 and 175, and cross-clock groups report 51 and 19. These are overlapping memberships: their sum is 2,703, exceeding the authoritative unique endpoint count by 16. Group TNS sums to -387.541ns, not design TNS -386.608ns. No exact endpoint partition is claimed. The host40 domain itself has +2.987ns setup slack. Sampled shell paths are route dominated; the precise physical origin beyond the saved paths is unproven.

Foreground r4 B selected nine exact FD Q nets, including DDR, but Vivado 2021.1 rejected forced replication in post-route mode before measuring its efficacy. This is a tool-mode failure, not evidence that physical replication loses. Preserve B. A future repair must first establish supported pre-route mode on a separate saved checkpoint/copy, with unchanged target, clocks and complete certification gates. Do not patch or retry active r4 C/D inputs.

The v1 analyzer's invalid clock-group additivity assertion failed before any completed diagnosis; its code and failed-attempt receipt are preserved and bound. V2 verifies the distinct design and clock-group counts independently. No CAD, simulation, service installation, root operation or FPGA I/O was performed by this analysis. Adopt installed priority handoff and active foreground r4 physical/certificate/application services. The existing complete-host MCRams producer and parity prerequisites retain their own controllers and admission gates.
'''
    atomic(OUT / 'REPORT.md', report)
    outputs = {str(p): sha(p) for p in OUT.iterdir() if p.is_file()}
    json_output('complete.json', dict(status=result['status'], completed_utc=datetime.now(timezone.utc).isoformat(),
                                      inputs=inputs, outputs=outputs))
    print(json.dumps(dict(status=result['status'], LUT_regression=60726, FF_regression=39227,
                          memory_channels=1796, DDR_setup_violators=1762,
                          B_failure=physical['B_failure']['status'], output=str(OUT))))


if __name__ == '__main__':
    main()
