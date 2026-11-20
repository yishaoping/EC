#!/usr/bin/env python3
"""Recompute resource budgets independently. All mm² are analytical scenarios."""
from pathlib import Path
from decimal import Decimal as D
import csv, json

ROOT = Path(__file__).resolve().parents[1]
AREA = ROOT.parents[1]
cfg = json.loads((AREA/'config/scenarios.json').read_text())
old = json.loads((AREA/'results/synthesis/summary.json').read_text())
new = json.loads((ROOT/'results/synthesis/summary.json').read_text())

def dump(name, obj):
    (ROOT/name).write_text(json.dumps(obj, indent=2, ensure_ascii=False)+'\n')

def csvout(name, rows):
    with (ROOT/name).open('w', newline='') as fp:
        w = csv.DictWriter(fp, fieldnames=list(rows[0])); w.writeheader(); w.writerows(rows)

physical = cfg['physical_envelopes']
def area(bits, ge, label, margin=False):
    p = {k:D(str(v)) for k,v in physical[label].items()}
    return (D(bits)*p['sram_um2_per_bit']*p['packing_factor'] +
            D(str(ge))*p['nand2_um2']*(1+p['interface_margin'] if margin else 1))/D(1000000)

old_mult = {'l1_metadata':1,'l2_metadata':1,'selector_l1':1,'selector_l2':1,
            'store_policy':2,'preserve':2,'visibility':2,'reclaim':4,
            'evt':1,'sw':1,'rollback':1,'context':1}
mem = sum(old[k]['memory_bits']*n for k,n in old_mult.items()) + 1024
dff = sum(old[k]['dff_bits']*n for k,n in old_mult.items())
ge = sum(D(str(old[k]['total_ge_excluding_ram']))*n for k,n in old_mult.items())
assert (mem, dff, ge) == (303104,2236,D('50620.5'))
old_area = {p:float(area(mem, ge, p, True)) for p in physical}
prior = json.loads((AREA/'results/area_summary.json').read_text())
for p in physical:
    assert abs(old_area[p]-prior['incremental_mm2_sensitivity'][p]) < 1e-12
dump('results/legacy_arithmetic_audit.json', {
    'memory_bits':mem,'dff_bits':dff,'ge_excluding_ram':float(ge),
    'area_mm2_model':old_area,'reproduced_previous_totals':True,
    'formula':'(RAM_bits*density*packing + GE*NAND2_area*(1+margin))/1e6',
    'not_measured_28nm_area':True})

metadata=[]
for name, l2, l1ways, l2ways, seq in [
    ('legacy_512KiB_seq16',524288,8,8,16),
    ('frozen_1MiB_seq16_hypothesis',1048576,2,16,16),
    ('frozen_1MiB_seq32_reduced_identity_hypothesis',1048576,2,16,32)]:
    width=seq+4+8+2
    a,b=32768//64*width,l2//64*width
    metadata.append({'scenario':name,'L1D_bytes':32768,'L1D_sets':32768//64//l1ways,
                     'L1D_ways':l1ways,'L2_bytes':l2,'L2_sets':l2//64//l2ways,
                     'L2_ways':l2ways,'line_bytes':64,'Seq':seq,'Epoch':4,'CurGen':8,
                     'Cur_and_preserved':2,'bits_per_line':width,'L1D_metadata_bits':a,
                     'L2_metadata_bits':b,'metadata_bits_total':a+b,
                     'implementation_status':'DESIGN_HYPOTHESIS_OVER_OBSERVED_GEOMETRY'})
assert metadata[0]['metadata_bits_total']==261120
assert metadata[1]['metadata_bits_total']==506880
assert metadata[2]['metadata_bits_total']==777216
csvout('results/cache_metadata.csv',metadata)

groups=[
 ('L1D metadata and selection',[('l1_metadata',1),('selector_l1',1),('store_l1',1)]),
 ('L2 metadata and selection',[('l2_metadata',1),('selector_l2',1),('store_l2',1)]),
 ('Preservation controllers',[('preserve',2)]),
 ('Visibility checks',[('visibility',2)]),
 ('LSL release descriptors (conditional)',[('reclaim',4)]),
 ('EVT 16 entries / 16 queries',[('evt',1)]),
 ('Rollback controller',[('rollback',1)]),
 ('Context 8 x 80 x 64 (conditional)',[('context',1)]),
 ('SW bitmap 16 (conditional new instance)',[('sw',1)]),
]
modules=[]; totals=[]; cases={}
for seq in (16,32):
    syn=new[f'seq{seq}']; rows=[]
    for component, terms in groups:
        bits=sum(syn[k]['memory_bits']*n for k,n in terms)
        dff=sum(syn[k]['dff_bits']*n for k,n in terms)
        ge=sum(syn[k]['total_ge_excluding_ram']*n for k,n in terms)
        row={'sequence_bits':seq,'component':component,'RAM_bits':bits,'DFF_bits':dff,
             'GE_excluding_RAM':ge,
             'evidence':'; '.join(f'results/synthesis/seq{seq}/{k}/result.json x{n}' for k,n in terms)}
        for p in physical: row[p+'_mm2_model']=float(area(bits,ge,p))
        rows.append(row)
    modules+=rows
    bits=sum(r['RAM_bits'] for r in rows); ge=sum(r['GE_excluding_RAM'] for r in rows)
    dff=sum(r['DFF_bits'] for r in rows)
    vals={p:float(area(bits,ge,p)) for p in physical}
    planning={p:float(area(bits+1024,ge,p,True)) for p in physical}
    strip_ge=ge-syn['sw']['total_ge_excluding_ram']-4*syn['reclaim']['total_ge_excluding_ram']
    strip={p:float(area(bits,strip_ge,p)) for p in physical}
    ff_only={p:float(D(bits)*6*D(str(physical[p]['nand2_um2']))/1000000) for p in physical}
    cases[f'seq{seq}']={'RAM_bits':bits,'DFF_bits':dff,'GE_excluding_RAM':ge,
                       'primitive_subtotal_mm2_model':vals,
                       'old_style_with_2_optional_SRAM_buffers_and_margin_mm2_model':planning,
                       'without_additional_SW_and_LSL_descriptors_mm2_model':strip,
                       'additional_FF_cell_area_if_RAM_all_DFF_no_decoders_mm2_model':ff_only}
    for label in physical:
        totals.append({'scenario':f'1MiB_seq{seq}_reduced_identity', 'physical_assumption':label,
                       'RAM_bits':bits,'DFF_bits':dff,'GE_excluding_RAM':ge,
                       'primitive_subtotal_mm2_model':vals[label],
                       'old_style_planning_mm2_model':planning[label],
                       'without_extra_SW_reclaim_mm2_model':strip[label],
                       'integrated_PAL_minus_PEEK_mm2':None,
                       'meaning':'Conditional primitive budget, not full-system delta or a bound'})
assert cases['seq32']['RAM_bits']==818176
assert cases['seq32']['DFF_bits']==3452
assert cases['seq32']['GE_excluding_RAM']==113338.5
csvout('results/module_area.csv',modules)
csvout('results/area_scenarios.csv',totals)
dump('results/area_summary.json',{'status':'NO_TECHNOLOGY_MAPPING_NO_INTEGRATED_SOC',
     'physical_assumptions':physical,'cases':cases,
     'actual_PEEK_area_mm2':None,'actual_PALIMPSEST_area_mm2':None,
     'actual_matched_delta_mm2':None,'actual_matched_delta_percentage':None,
     'delta_formula':'A_primitive + A_missing_integration + A_macro_implementation_correction - A_reused_or_replaced',
     'unprotected_formula':'U=C; P=C+H_PEEK; PAL=C+H_PEEK+delta',
     'limitations':['SRAM density and GE weights assumed, no PDK',
       '46-bit metadata is a reduced-identity design choice; frozen CacheImageKey is 81 bits',
       '16-query EVT requires serialized access between clients; arbitration unimplemented',
       '8 contexts, 8 descriptors/checker, Epoch4/CurGen8 lack proven workload/admission bounds',
       'No finite upper bound on missing integration or macro-port overhead established']})

# Identical geometry and explicit area boundary for the three requested profiles.
base=Path('/data1/gzh/EC')
param_path=base/'firesim/final-opt4-20261106/builds/C4-parameters-20261106T100204.040607Z/parameters.json'
params=json.loads(param_path.read_text())
boom=params['tiles'][0]
geometry={
 'main_cores':1,'main_core':'BOOM OoO','decode_width':boom['core']['decodeWidth'],
 'ROB':boom['core']['numRobEntries'],
 'IQ_total':sum(q['numEntries'] for q in boom['core']['issueParams']),
 'LDQ':boom['core']['numLdqEntries'],'STQ':boom['core']['numStqEntries'],
 'main_L1I':{'bytes':32768,'ways':8,'sets':64},
 'main_L1D':{'bytes':32768,'ways':2,'sets':256,'MSHRs':6},
 'checker_cores':4,'checker_core':'Rocket in-order',
 'checker_L1I':{'bytes_each':4096,'ways':2,'sets':32},
 'checker_L1D':{'bytes_each':4096,'ways':2,'sets':32},
 'L2':{'bytes':1048576,'ways':16,'sets':1024,'MSHRs':4},'line_bytes':64,
 'target_clock_MHz':{'BOOM':200,'Rocket':100,'achieved_STA_MHz':None},
 'memory_address_space_bytes':params['external_memory']['master']['size'],
 'simulation_memory':'FASED read/write latency 30, max outstanding 4/4; not DDR3-1066',
 'evidence':str(param_path.relative_to(base))}
boundary={'include':['all 5 cores and native register files','all L1/L2 data and tag arrays',
 'SRAM macros, wrappers, decoders, repair/ECC if enabled','clock-crossing and on-chip interconnect',
 'same on-chip memory interface/controller if present','protection logic and storage when enabled'],
 'exclude':['external DRAM chips','FireSim/Goldengate host logic','measurement-only observers, traces and counters'],
 'stage':'report both mapped standard-cell + SRAM macro area separately; no floorplan whitespace in synthesis total',
 'SRAM_macro_selection':None,'on_chip_DDR3_controller_implementation':None,
 'common_data_array_bits':(32768*2+4*4096*2+1048576)*8}
profiles=[]
for name, enabled, formula in [('Unprotected baseline',[],'C'),
 ('PEEK',['PEEK snapshot/transport/LSL/checker validation'],'C+H_PEEK'),
 ('PALIMPSEST',['PEEK snapshot/transport/LSL/checker validation','PAL recovery mechanisms'],'C+H_PEEK+delta')]:
    profiles.append({'name':name,'status':'DECLARATIVE_NOT_ELABORATED_NOT_SYNTHESIZED',
                     'geometry':geometry,'area_boundary':boundary,'enabled':enabled,
                     'LSL_payload_bits_per_checker':0 if not enabled else 2*255*130,
                     'area_formula':formula,'area_mm2':None,
                     'note':'Unprotected retains 4 native Rockets; protection-specific LSL/checkpoint removed. PEEK is a clean port, not frozen EC relabeled.'})
dump('config/matched_profiles.json',profiles)
csvout('results/three_baselines.csv',[{'configuration':p['name'],'area_formula':p['area_formula'],
 'mapped_cell_mm2':None,'SRAM_macro_mm2':None,'total_mm2':None,'status':p['status']} for p in profiles])

# Current EC source has more fields than the reduced metadata hypothesis.
inventory=[{'object':'Frozen L2 source additions over ordinary directory',
 'formula':'dcache1 + packetSeq32 + packetTracked1 + CacheImageKey81 + outerPreserved1',
 'bits_per_line':116,'lines':16384,'declared_bits':116*16384,
 'status':'SOURCE_STRUCTURAL_COUNT_INCLUDES_MEASUREMENT_FIELDS_NOT_MAPPED_AREA'},
 {'object':'Frozen L2 functional image key and receipt only',
 'formula':'CacheImageKey(valid1 + writer16 + generation32 + contentSeq32) + outerPreserved1',
 'bits_per_line':82,'lines':16384,'declared_bits':82*16384,
 'status':'SUBSET_OF_PREVIOUS_ROW_DO_NOT_SUM'},
 {'object':'Illustrative new version fields retaining whole frozen image key',
 'formula':'CacheImageKey81 + RecoveryEpoch4 + CurrentGeneration8 + Current1 + preserved1',
 'bits_per_line':95,'lines':16896,'declared_bits':95*16896,
 'status':'DESIGN_SENSITIVITY_NOT_IMPLEMENTED_NOT_INCREMENTAL_TO_FROZEN'}]
csvout('results/frozen_identity_inventory.csv',inventory)
print(json.dumps({'legacy':old_area,'revised':cases,'common_data_bits':boundary['common_data_array_bits']},indent=2))
