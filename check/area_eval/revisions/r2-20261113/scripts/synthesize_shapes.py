#!/usr/bin/env python3
"""Bounded independent primitive synthesis, not a SoC or technology mapping.

Original RTL is read only. Results preserve the r1 generic flow for comparison.
Run two sequence widths on frozen-experiment cache geometry. No SRAM is mapped
to flip-flops except the explicitly small EVT/reclaim/context-identity tables.
"""
from pathlib import Path
import json, subprocess, hashlib, time

ROOT = Path(__file__).resolve().parents[1]
AREA = ROOT.parents[1]
RTL = AREA / 'rtl/palimpsest.sv'
OUT = ROOT / 'results/synthesis'

def weight(kind):
    if kind.startswith(('$_DFF', '$_SDFF', '$_ADFF', '$_DFFE', '$_ALDFF')):
        return 6., 'sequential'
    if kind == '$_NOT_': return .5, 'combinational'
    if kind in ('$_AND_', '$_OR_', '$_NAND_', '$_NOR_'): return 1., 'combinational'
    if kind in ('$_XOR_', '$_XNOR_'): return 2., 'combinational'
    if kind in ('$_MUX_', '$_NMUX_'): return 3., 'combinational'
    if kind in ('$_ANDNOT_', '$_ORNOT_', '$_AOI3_', '$_OAI3_'): return 1.5, 'combinational'
    if kind in ('$_AOI4_', '$_OAI4_'): return 2., 'combinational'
    raise ValueError(kind)

def run_yosys(d, name, script):
    path = d / (name + '.ys')
    path.write_text(script + '\n')
    with (d / (name + '.log')).open('w') as log:
        subprocess.run(['yosys', '-T', '-s', str(path)], stdout=log,
                       stderr=subprocess.STDOUT, check=True, timeout=60)

all_results = {}
for seq_w in (16, 32):
    shapes = {
        'l1_metadata': ('pal_metadata_ram', {'SETS':256, 'WAYS':2}),
        'l2_metadata': ('pal_metadata_ram', {'SETS':1024, 'WAYS':16}),
        'selector_l1': ('pal_version_select', {'WAYS':2}),
        'selector_l2': ('pal_version_select', {'WAYS':16}),
        'store_l1': ('pal_store_policy', {'WAYS':2}),
        'store_l2': ('pal_store_policy', {'WAYS':16}),
        'preserve': ('pal_preserve', {}),
        'visibility': ('pal_visibility', {}),
        'reclaim': ('pal_lsl_reclaim', {'SLOTS':8}),
        # One 16-way lookup at a time; other clients must be arbitrated.
        'evt': ('pal_evt', {'QUERIES':16}),
        'sw': ('pal_safe_watermark', {}),
        'rollback': ('pal_rollback', {}),
        'context': ('pal_context_store', {'SLOTS':8, 'WORDS':80}),
    }
    summary = {}
    for name, (top, params) in shapes.items():
        params = dict(params, SEQ_W=seq_w)
        d = OUT / ('seq' + str(seq_w)) / name
        d.mkdir(parents=True, exist_ok=True)
        fingerprint = hashlib.sha256(RTL.read_bytes() + Path(__file__).read_bytes()
                                    + json.dumps(params, sort_keys=True).encode()).hexdigest()
        result_path = d / 'result.json'
        if result_path.exists():
            result = json.loads(result_path.read_text())
            assert result['fingerprint'] == fingerprint, 'Use a new revision for changed inputs'
            summary[name] = result
            continue
        change = ' '.join(f'-set {k} {v}' for k, v in params.items())
        smallmap = ('memory_map;' if name in ('evt', 'reclaim') else
                    'memory_map pal_context_store/seq pal_context_store/epoch;' if name == 'context' else '')
        start = time.monotonic()
        run_yosys(d, 'collect', f'read_verilog -sv {RTL}; chparam {change} {top}; '
                  f'hierarchy -check -top {top}; proc; opt; memory_dff; memory_collect; '
                  f'{smallmap} opt; check; write_json {d}/memory.json; stat')
        design = json.loads((d / 'memory.json').read_text())
        memories = []
        for mod in list(design['modules'].values()):
            for cellname, cell in mod.get('cells', {}).items():
                if cell['type'] != '$mem_v2': continue
                p = cell['parameters']
                n = lambda k: int(p[k], 2)
                memories.append({'cell':cellname, 'width':n('WIDTH'), 'depth':n('SIZE'),
                                 'bits':n('WIDTH')*n('SIZE'), 'read_ports':n('RD_PORTS'),
                                 'write_ports':n('WR_PORTS')})
                memtype = 'AREA_RAM_' + str(len(memories))
                ports, names, bit = {}, {}, 2
                for pn, conn in cell['connections'].items():
                    bits = list(range(bit, bit + len(conn)))
                    bit += len(conn)
                    ports[pn] = {'direction':cell['port_directions'][pn], 'bits':bits}
                    names[pn] = {'hide_name':0, 'bits':bits, 'attributes':{}}
                design['modules'][memtype] = {'attributes':{'blackbox':'1'},
                                             'ports':ports, 'netnames':names, 'cells':{}}
                cell['type'], cell['parameters'] = memtype, {}
        (d / 'abstract.json').write_text(json.dumps(design))
        run_yosys(d, 'gates', f'read_json {d}/abstract.json; hierarchy -check -top {top}; '
                  f'flatten; opt; techmap; opt; dffunmap; abc -g simple; clean; check; '
                  f'write_json {d}/gates.json; stat')
        mapped = json.loads((d / 'gates.json').read_text())['modules'][top]
        counts, ge, dff = {}, {'sequential':0., 'combinational':0.}, 0
        for cell in mapped['cells'].values():
            kind = cell['type']
            counts[kind] = counts.get(kind, 0) + 1
            if kind.startswith('AREA_RAM_'): continue
            w, group = weight(kind)
            ge[group] += w
            dff += group == 'sequential'
        result = {'fingerprint':fingerprint, 'top':top, 'parameters':params,
                  'rtl_sha256':hashlib.sha256(RTL.read_bytes()).hexdigest(),
                  'seconds':round(time.monotonic()-start, 3), 'cell_counts':counts,
                  'dff_bits':dff, 'ge':ge, 'total_ge_excluding_ram':sum(ge.values()),
                  'memories':memories, 'memory_bits':sum(m['bits'] for m in memories),
                  'area_mm2':None, 'critical_path_ns':None,
                  'evidence_level':'GENERIC_SYNTHESIS_WITH_ASSUMED_GE_WEIGHTS_NO_PDK'}
        result_path.write_text(json.dumps(result, indent=2) + '\n')
        summary[name] = result
        print(seq_w, name, result['memory_bits'], dff, sum(ge.values()), flush=True)
    (OUT / ('seq' + str(seq_w)) / 'summary.json').write_text(json.dumps(summary, indent=2) + '\n')
    all_results['seq' + str(seq_w)] = summary
(OUT / 'summary.json').write_text(json.dumps(all_results, indent=2) + '\n')
