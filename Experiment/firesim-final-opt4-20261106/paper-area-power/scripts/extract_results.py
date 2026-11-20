#!/usr/bin/env python3
"""Extract archived Vivado reports; all numeric output carries stage/source."""
from pathlib import Path
from collections import defaultdict
import csv
import json
import re

ROOT = Path(__file__).resolve().parents[1]
RESULTS = ROOT / 'results'
RESULTS.mkdir(exist_ok=True)
LATEX = ROOT / 'latex'
LATEX.mkdir(exist_ok=True)
KEYS = ['LUT', 'logic_LUT', 'LUTRAM', 'SRL', 'register', 'RAMB36', 'RAMB18', 'URAM', 'DSP']
TOP = 'design_1_wrapper'
WRAPPER = TOP + '/design_1_i/firesim_wrapper_0'
TARGET = WRAPPER + '/inst/firesim_top/top/sim/target'
GROUPS = {
    'boom': 'BOOM + L1 / local controls (excl. SVB, GH_BUF)',
    'l2': 'Shared L2 cache and coherence wrapper',
    'svb': 'Speculative Version Buffer (SVB)',
    'lsl': 'Four checker Load-Store Logs (LSL)',
    'checker': 'Four checker domains (excl. LSL)',
    'communication': 'EC communication (system GHM CDC + GH_BUF)',
    'target_other': 'Other target interconnect / peripherals',
    'firesim_host': 'FireSim host / bridges / FAME harness',
    'shell': 'U280 shell / DDR4 / PCIe / debug',
}

def write_csv(name, rows):
    if not rows:
        return
    p = RESULTS / name
    with p.open('w', newline='') as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0]))
        w.writeheader()
        w.writerows(rows)

def header(text, key):
    m = re.search(r'^\|\s*' + re.escape(key) + r'\s*:\s*(.*?)\s*$', text, re.M)
    return m[1] if m else None

def utilization(p):
    text = p.read_text()
    rows = {}
    for n, line in enumerate(text.splitlines(), 1):
        a = [s.strip() for s in line.split('|')[1:-1]]
        if len(a) != 6:
            continue
        label = a[0].rstrip('*').strip()
        if label in rows or not re.fullmatch(r'\d+(?:\.\d+)?', a[1]) or not re.fullmatch(r'\d+(?:\.\d+)?', a[4]):
            continue
        used, available = float(a[1]), float(a[4])
        rows[label] = {'used': used, 'available': available, 'percent': 100 * used / available, 'source_line': n}
    return {'state': header(text, 'Design State'), 'tool': header(text, 'Tool Version'), 'date': header(text, 'Date'), 'device': header(text, 'Device'), 'rows': rows}

def hierarchy(p):
    nodes, stack = [], []
    self_rows = []
    for n, line in enumerate(p.read_text().splitlines(), 1):
        a = [s.strip() for s in line.split('|')[1:-1]]
        if len(a) != 11 or not a[2].isdigit():
            continue
        raw = line.split('|')[1]
        depth = (len(raw) - len(raw.lstrip()) - 1) // 2
        if a[0].startswith('('):
            self_rows.append((n, depth, a))
            continue
        while stack and nodes[stack[-1]]['depth'] >= depth:
            stack.pop()
        parent = stack[-1] if stack else None
        path = (nodes[parent]['path'] + '/' if parent is not None else '') + a[0]
        node = {'path': path, 'module': a[1], 'depth': depth, 'parent': parent, 'children': [], 'source_line': n, 'inclusive': dict(zip(KEYS, map(int, a[2:])))}
        if parent is not None:
            nodes[parent]['children'].append(len(nodes))
        nodes.append(node)
        stack.append(len(nodes) - 1)
    for node in nodes:
        node['exclusive'] = {k: node['inclusive'][k] - sum(nodes[i]['inclusive'][k] for i in node['children']) for k in KEYS}
        # Vivado may pack logic from sibling instances into shared LUTs. A
        # parent's total can therefore be smaller than the sum of its children.
        # Retain this signed accounting residual rather than clamping it, which
        # would silently overcount. It cancels within the selected coarse group.
    assert nodes[0]['path'] == TOP
    assert all(sum(n['exclusive'][k] for n in nodes) == nodes[0]['inclusive'][k] for k in KEYS)
    return nodes

def group(path):
    if not (path == TARGET or path.startswith(TARGET + '/')):
        return 'firesim_host' if path == WRAPPER or path.startswith(WRAPPER + '/') else 'shell'
    if '/dcache/svb' in path:
        return 'svb'
    if re.search(r'/tile_prci_domain_[1-4]/.*?/core/lsl(?:/|$)', path):
        return 'lsl'
    if '/system_/ghm_' in path or '/tile_reset_domain__boom_tile_/gh_buf' in path:
        return 'communication'
    if re.search(r'/tile_prci_domain_[1-4](?:/|$)', path):
        return 'checker'
    if '/tile_prci_domain_/' in path or path.endswith('/tile_prci_domain_'):
        return 'boom'
    # These register-file RAM models were hoisted by FAME, but are main-core storage.
    if '/FireSim_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_' in path:
        return 'boom'
    if '/subsystem_l2_wrapper' in path:
        return 'l2'
    return 'target_other'

def breakdown(p, stage):
    nodes = hierarchy(p)
    sums = {g: {k: 0 for k in KEYS} for g in GROUPS}
    detail = []
    for n in nodes:
        g = group(n['path'])
        for k in KEYS:
            sums[g][k] += n['exclusive'][k]
        detail.append({'stage': stage, 'path': n['path'], 'module': n['module'], 'group': g, **{'inclusive_' + k: n['inclusive'][k] for k in KEYS}, **{'exclusive_' + k: n['exclusive'][k] for k in KEYS}, 'negative_LUT_sharing_residual': any(v < 0 for v in n['exclusive'].values()), 'source': str(p.relative_to(ROOT)), 'source_line': n['source_line']})
    assert all(sum(v[k] for v in sums.values()) == nodes[0]['inclusive'][k] for k in KEYS)
    assert all(v >= 0 for values in sums.values() for v in values.values())
    write_csv('hierarchy_exclusive_' + stage + '.csv', detail)
    rows = []
    for g, label in GROUPS.items():
        v = sums[g]
        rows.append({'stage': stage, 'group': g, 'component': label, **v, 'BRAM36_equivalent': v['RAMB36'] + v['RAMB18'] / 2, 'LUT_percent_of_total': v['LUT'] * 100 / nodes[0]['inclusive']['LUT'], 'LUT_percent_of_U280': v['LUT'] * 100 / 1303680, 'CARRY8': 'NOT_REPORTED_BY_HIERARCHY', 'source': str(p.relative_to(ROOT)), 'method': 'inclusive minus immediate children; assign each exclusive row once'})
    write_csv('area_breakdown_' + stage + '.csv', rows)
    key_rows = []
    for n in nodes:
        if (n['path'] in (TOP, WRAPPER, TARGET) or n['module'].endswith(('_BoomTile', '_BoomCore', '_BoomNonBlockingDCache', '_SpeculativeVersionBuffer', '_InclusiveCache', '_R_RSU')) or re.search(r'_(RocketTile|R_LSL)(?:_\d+)?$', n['module']) or (n['depth'] == 11 and '/system_/ghm_' in n['path'])):
            key_rows.append({'stage': stage, 'path': n['path'], 'module': n['module'], **n['inclusive'], 'BRAM36_equivalent': n['inclusive']['RAMB36'] + n['inclusive']['RAMB18'] / 2, 'source': str(p.relative_to(ROOT)), 'source_line': n['source_line'], 'additive': 'NO; nested inclusive rows'})
    write_csv('key_hierarchy_inclusive_' + stage + '.csv', key_rows)
    return rows, nodes

def power(p, stage, valid):
    text = p.read_text()
    summary = {}
    metrics = {'Total On-Chip Power (W)': 'total_W', 'FPGA Power (W)': 'fpga_W', 'HBM Power (W)': 'hbm_W', 'Dynamic (W)': 'dynamic_W', 'Device Static (W)': 'static_W', 'Confidence Level': 'confidence', 'Simulation Activity File': 'activity_file', 'Design Nets Matched': 'matched_nets', 'Junction Temperature (C)': 'junction_C'}
    components, hierarchy_rows, clocks = [], [], []
    power_stack = []
    section = ''
    for n, line in enumerate(text.splitlines(), 1):
        if line.startswith(('1. Summary', '2. Settings', '3. Detailed Reports')):
            section = ''
        elif line.startswith('1.1 On-Chip'):
            section = 'components'
        elif line.startswith('1.2 '):
            section = ''
        elif line.startswith('2.2 '):
            section = 'clocks'
        elif line.startswith('3.1 '):
            section = 'hierarchy'
        a = [x.strip() for x in line.split('|')[1:-1]]
        if len(a) == 2 and a[0] in metrics and metrics[a[0]] not in summary:
            summary[metrics[a[0]]] = {'value': a[1], 'source_line': n}
        base = {'stage': stage, 'validity': valid, 'source': str(p.relative_to(ROOT)), 'source_line': n}
        if section == 'components' and len(a) == 5 and re.fullmatch(r'<?[\d.]+', a[1]):
            components.append({**base, 'component': a[0], 'power_W_as_reported': a[1], 'used_as_reported': a[2], 'additive': 'NO; includes nested resource subtotals and Total'})
        if section == 'hierarchy' and len(a) >= 2 and re.fullmatch(r'<?[\d.]+', a[1]):
            raw = line.split('|')[1]
            depth = (len(raw) - len(raw.lstrip()) - 1) // 2
            while power_stack and power_stack[-1][0] >= depth:
                power_stack.pop()
            path = '/'.join([x[1] for x in power_stack] + [a[0]])
            power_stack.append((depth, a[0]))
            hierarchy_rows.append({**base, 'depth': depth, 'path': path, 'name': a[0], 'dynamic_W_as_reported': a[1], 'additive': 'NO; inclusive hierarchy; root equals Dynamic, excludes Device Static'})
        if section == 'clocks' and len(a) == 3 and re.fullmatch(r'[\d.]+', a[2]):
            clocks.append({**base, 'clock': a[0], 'domain': a[1], 'period_ns_as_reported': a[2]})
    write_csv('power_components_' + stage + '.csv', components)
    write_csv('power_hierarchy_' + stage + '.csv', hierarchy_rows)
    write_csv('power_clocks_' + stage + '.csv', clocks)
    return {'stage': stage, 'validity': valid, 'reported_design_state': header(text, 'Design State'), 'tool': header(text, 'Tool Version'), 'process': header(text, 'Process'), 'characterization': header(text, 'Characterization'), 'source': str(p.relative_to(ROOT)), **summary}

def main():
    report_sources = {
        'dut_synthesis': ROOT / 'raw/r6/dut-utilization.rpt',
        'full_shell_postopt': ROOT / 'raw/r6/top-postopt-utilization.rpt',
        'full_shell_placed': ROOT / 'raw/r6/impl_1/design_1_wrapper_utilization_placed.rpt',
        'native_B_placed_context': ROOT / 'raw/native-B/impl_1/design_1_wrapper_utilization_placed.rpt',
    }
    util = {stage: utilization(p) for stage, p in report_sources.items()}
    resource_names = ['CLB LUTs', 'LUT as Logic', 'LUT as Memory', 'CLB Registers', 'Register as Flip Flop', 'Register as AND/OR', 'CARRY8', 'F7 Muxes', 'F8 Muxes', 'Block RAM Tile', 'RAMB36/FIFO', 'RAMB18', 'URAM', 'DSPs']
    summary_rows = []
    for stage, u in util.items():
        for key in resource_names:
            if key in u['rows']:
                summary_rows.append({'stage': stage, 'reported_design_state': u['state'], 'resource': key, **u['rows'][key], 'source': str(report_sources[stage].relative_to(ROOT)), 'hardware_commit': '6fada307' if not stage.startswith('native') else 'separate Native B build', 'boundary': 'DUT only' if stage == 'dut_synthesis' else 'whole design incl. FireSim and shell'})
    write_csv('resource_summary.csv', summary_rows)
    post, nodes = breakdown(ROOT / 'raw/r6/top-postopt-hierarchical.rpt', 'postopt')
    placed_path = ROOT / 'generated/placed/hierarchical.rpt'
    placed = None
    if placed_path.exists():
        placed, _ = breakdown(placed_path, 'placed')
    powers = [power(ROOT / 'raw/r6/impl_1/design_1_wrapper_power_routed.rpt', 'failed_route', 'diagnostic_only_illegal_routing')]
    if (ROOT / 'generated/placed/power_vectorless.rpt').exists():
        powers.append(power(ROOT / 'generated/placed/power_vectorless.rpt', 'placed_vectorless', 'pre_route_estimate_no_workload_activity'))
    write_csv('power_summary.csv', [{'stage': p['stage'], 'validity': p['validity'], 'reported_design_state': p['reported_design_state'], **{k: p[k]['value'] for k in ['total_W','dynamic_W','static_W','confidence','activity_file','matched_nets']}, 'source': p['source']} for p in powers])
    # Compatibility checks do not infer paired source/measurement equivalence.
    native = json.loads((ROOT / 'raw/native-B/parameters.json').read_text())
    ec = json.loads((ROOT / 'raw/profile/parameters.json').read_text())
    def normalize(x):
        if isinstance(x, dict):
            return {k: normalize(v) for k,v in x.items()}
        if isinstance(x, list):
            return [normalize(v) for v in x]
        if isinstance(x, str):
            return re.sub(r'\$\d+', '$N', x)
        return x
    comp = {'main_core_and_L1_parameters_equal': normalize(native['tiles'][0]) == normalize(ec['tiles'][0]), 'inclusive_cache_parameters_equal': native['inclusive_cache'] == ec['inclusive_cache'], 'external_memory_parameters_equal': native['external_memory'] == ec['external_memory'], 'memory_model_parameters_equal': native['memory_model'] == ec['memory_model'], 'native_harts': [t['hartId'] for t in native['tiles']], 'EC_harts': [t['hartId'] for t in ec['tiles']], 'strict_incremental_overhead_supported': False, 'reason': 'different source builds/dates, extra checker domains and tracing/communication, no matched PEEK or ParaMedic build; placement-to-placement totals are context only; power stages/activity not matched'}
    (RESULTS / 'baseline_compatibility.json').write_text(json.dumps(comp, indent=2) + '\n')
    comparison = []
    for key in ['CLB LUTs','CLB Registers','Block RAM Tile','URAM','DSPs','CARRY8']:
        for stage in ['full_shell_placed', 'native_B_placed_context']:
            v = util[stage]['rows'][key]
            comparison.append({'design': stage, 'resource': key, 'used': v['used'], 'percent_U280': v['percent'], 'stage': util[stage]['state'], 'comparison_status': 'CONTEXT_ONLY_NO_INCREMENTAL_CLAIM', 'source': str(report_sources[stage].relative_to(ROOT)), 'source_line': v['source_line']})
    for design in ['PEEK', 'ParaMedic']:
        comparison.append({'design': design, 'resource': 'all', 'used': '', 'percent_U280': '', 'stage': 'UNVERIFIED', 'comparison_status': 'NO_MATCHED_REAL_REPORT_FOUND_IN_SEARCHED_PATHS', 'source': 'evidence/baseline_report_search.json', 'source_line': ''})
    write_csv('baseline_comparison.csv', comparison)
    extraction = {'utilization': util, 'area_breakdown_postopt': post, 'area_breakdown_placed': placed, 'powers': powers, 'hierarchical_register_note': 'Vivado FFs column equals CLB Registers incl. one AND/OR primitive; use utilization report for strict Flip Flop count', 'CARRY8_note': 'not available per module in original hierarchy; no cross-stage allocation imputed'}
    (RESULTS / 'extracted.json').write_text(json.dumps(extraction, indent=2) + '\n')
    make_latex(post, util, powers)
    print(json.dumps({'postopt_total': {k:sum(r[k] for r in post) for k in KEYS}, 'power_stages': [p['stage'] for p in powers], 'baseline_compatibility': comp}, indent=2))

def make_latex(rows, util, powers):
    labels = {'boom':'BOOM/L1 and local control', 'l2':'Shared L2 and coherence', 'svb':'SVB', 'lsl':'LSLs (four)', 'checker':'Checker domains, excluding LSLs', 'communication':'GHM CDC and GH\_BUF', 'target_other':'Other target logic', 'firesim_host':'FireSim host and harness', 'shell':'FPGA shell and interfaces'}
    lines = [r'% Requires graphicx (available in the ACM/DAC template).', r'\begin{table}[t]', r'\centering', r'\caption{FPGA resource usage of the EC Performance-Only prototype (\texttt{6fada307}) after full-shell logic optimization in Vivado 2021.1. Counts describe mapped resources before placement/routing; they are not the incremental area of full PALIMPSEST.}', r'\label{tab:ec-fpga-resources}', r'\scriptsize', r'\setlength{\tabcolsep}{3pt}', r'\resizebox{\columnwidth}{!}{%', r'\begin{tabular}{lrrrr}', r'\hline', r'Component & LUTs & Registers & BRAM36-eq. & DSPs \\', r'\hline']
    for row in rows:
        lines.append(f"{labels[row['group']]} & {row['LUT']:,} & {row['register']:,} & {row['BRAM36_equivalent']:g} & {row['DSP']} " + r'\\')
    total = {k:sum(r[k] for r in rows) for k in KEYS}
    lines += [r'\hline', f"Total & {total['LUT']:,} & {total['register']:,} & {total['RAMB36']+total['RAMB18']/2:g} & {total['DSP']} " + r'\\', r'U280 utilization & 78.52\% & 39.09\% & 33.66\% & 1.27\% \\', r'\hline', r'\end{tabular}%', r'}', r'\vspace{2pt}', r'\parbox{\columnwidth}{\scriptsize Disjoint resource partition: child resources are excluded from parent groups; LUT-sharing residuals are retained. Registers include one AND/OR primitive (1,019,172 flip-flops). BRAM36-eq. is $658+41/2$; URAM usage is zero; CARRY8 usage is 15,706 (9.64\%). FAME-hoisted BOOM register-file RAM models are assigned to BOOM. Routing failed, so no final post-route area, timing-closed frequency, or measured board power is reported.}', r'\end{table}']
    (LATEX / 'hardware_overhead_table.tex').write_text('\n'.join(lines) + '\n')
    text = r'''\paragraph{Hardware resource usage.}
We characterize the EC Performance-Only prototype (revision
\texttt{6fada307}) using Vivado 2021.1 reports for an Alveo U280.
After full-shell logic optimization, the design uses 1,023,687 LUTs
(78.52\%), 1,019,173 registers (39.09\%), 678.5 BRAM36-equivalent
tiles (33.66\%), 115 DSPs (1.27\%), and no URAM.
These counts include the transformed target, FireSim host infrastructure,
and FPGA shell. We partition the hierarchy into disjoint groups to avoid
counting child modules twice. In particular, the SVB accounts for 64,699 LUTs,
while the four LSLs use 15,172 LUTs and 16 BRAM36 blocks.
This prototype retains data preservation, cache isolation, checker execution
logic, normal commit, and backpressure, while removing address/bucket and
barrier-latency diagnostic instrumentation. The source profile explicitly
retains recovery logic; these results do not establish a complete,
recovery-validated PALIMPSEST implementation.
The subsequent routing attempt failed, preventing timing closure and
deployment. Therefore, Table~\ref{tab:ec-fpga-resources} reports
pre-route mapped resource usage rather than a successfully implemented
FPGA footprint. We do not claim an incremental percentage over PEEK or
ParaMedic without matched builds and accounting boundaries.
'''
    placed = next((p for p in powers if p['stage'] == 'placed_vectorless'), None)
    if placed:
        text += ('\n' + r'% Optional supplemental estimate; not a measured-power result.' + '\n' + r'\paragraph{Power estimate.}' + '\n' + f"A separate report-only analysis of the archived, fully placed checkpoint\nproduces a vectorless estimate of {placed['total_W']['value']}~W total on-chip power\n({placed['dynamic_W']['value']}~W dynamic and {placed['static_W']['value']}~W device static)\n" + r'at the constrained approximately 50~MHz host clock. No workload SAIF/VCD' + '\n' + r'activity is available, and routing parasitics are estimated. The tool reports' + '\n' + f"{placed['confidence']['value'].lower()} confidence; propagated reset activity further limits the estimate.\n" + r'We therefore do not use it to claim workload power, board power,' + '\n' + r'energy savings, or a full-PALIMPSEST power overhead.' + '\n')
    text += ('\n' + r'% Audit-only diagnostic (excluded from quantitative power claims): the' + '\n' + r'% failed-route report lists 15.350 W total, 11.890 W dynamic and 3.460 W' + '\n' + r'% static, with Low confidence, no simulation activity, and excessive reset' + '\n' + r'% activity warnings. It was computed on an illegally routed design.' + '\n')
    (LATEX / 'hardware_overhead_analysis.tex').write_text(text)

if __name__ == '__main__':
    main()
