#!/usr/bin/env python3
"""Transparent area SENSITIVITY model, never a mapped 28 nm area report."""
from pathlib import Path
import json,csv,math
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
ROOT=Path(__file__).resolve().parents[1]
cfg=json.loads((ROOT/'config/scenarios.json').read_text())
syn=json.loads((ROOT/'results/synthesis/summary.json').read_text())
b=cfg['baseline'];f=cfg['field_scenarios']['typical'];field=sum(f[k] for k in ['seq_w','epoch_w','gen_w','owner_w'])+2
assert field==30
# Multiplicities explicitly describe the PROPOSED integration, not the current
# instantiated design. Eight reclaim descriptors per checker (32 total).
groups=[
 ('L1 Version Metadata',[('l1_metadata',1),('selector_l1',1),('store_policy',1)],0,'30 bits/line; one lookup/store lane; existing tag/valid/permission reused'),
 ('L2 Version Metadata',[('l2_metadata',1),('selector_l2',1),('store_policy',1)],0,'30 bits/line; one lookup/store lane; no data-array duplication'),
 ('Version Preservation',[('preserve',2)],0,'One source reservation per level; existing cache data stays locked'),
 ('Visibility Barrier',[('visibility',2)],0,'One external coherence/DRAM check per level; producer SW input shared'),
 ('Early LSL Reclamation',[('reclaim',b['checkers'])],0,'8 descriptors/checker; NO added LSL payload; block allocator still missing'),
 ('EVT',[('evt',1)],0,'16 epochs; 8 combinational queries; register implementation'),
 ('Rollback Controller',[('rollback',1)],0,'Flush/history/restore/restart held handshakes; no cache scan'),
 ('Checkpoint / Context Storage',[('context',1)],0,'8 x 80 x 64-bit retained contexts; baseline snapshot not credited as multi-slot memory'),
 ('Verification Bitmap / SW',[('sw',1)],0,'New relative to this check baseline; if a different PEEK already has this, subtract this row once'),
 ('Additional Buffers / Interfaces',[],f['buffer_lines']*b['line_bytes']*8,'2 optional line staging buffers, not instantiated; 5/15/30% interface logic allowance separately'),
]
rows=[]
for name,terms,bufferbits,notes in groups:
 mem=sum(syn[n]['memory_bits']*k for n,k in terms)+bufferbits
 dff=sum(syn[n]['dff_bits']*k for n,k in terms)
 comb=sum(syn[n]['ge']['combinational']*k for n,k in terms)
 seq=sum(syn[n]['ge']['sequential']*k for n,k in terms)
 row={'component':name,'added_memory_bits':mem,'dff_bits':dff,'added_storage_bits':mem+dff,'combinational_ge':comb,'sequential_ge':seq,'generic_ge_excluding_ram':comb+seq,'notes':notes,'evidence_level':'GENERIC_SYNTHESIS_COUNTS_WITH_SCENARIO_MULTIPLICITIES' if terms else 'ESTIMATED_NOT_IMPLEMENTED','evidence':'; '.join(f'results/synthesis/{n}/result.json x{k}' for n,k in terms)}
 for label,physical in cfg['physical_envelopes'].items():
  storage=mem*physical['sram_um2_per_bit']*physical['packing_factor']/1e6
  combination=comb*physical['nand2_um2']/1e6
  sequential=seq*physical['nand2_um2']/1e6
  row[f'{label}_storage_mm2']=storage;row[f'{label}_combinational_mm2']=combination;row[f'{label}_sequential_mm2']=sequential
  row[f'{label}_buffer_interface_mm2']=0.
  row[f'{label}_total_mm2']=storage+combination+sequential
 rows.append(row)
# Unintegrated adapters/muxes/tag sidebands/coherence changes are not synthesized.
# This is explicitly a sensitivity allowance, not completeness certification.
for label,physical in cfg['physical_envelopes'].items():
 logic=sum(r['generic_ge_excluding_ram'] for r in rows)*physical['nand2_um2']/1e6
 allowance=logic*physical['interface_margin']
 rows[-1][f'{label}_buffer_interface_mm2']=allowance
 rows[-1][f'{label}_total_mm2']+=allowance
reference_boom=cfg['paper_reference']['protected_boom_mm2'];reference_peek=reference_boom+4*.27
for row in rows:row['typical_pct_of_paper_reference_peek']=row['typical_total_mm2']/reference_peek*100

def writecsv(path,rows):
 with (ROOT/path).open('w',newline='') as fp:
  writer=csv.DictWriter(fp,fieldnames=list(rows[0]));writer.writeheader();writer.writerows(rows)
writecsv('results/module_area.csv',rows)
totals={label:sum(r[f'{label}_total_mm2'] for r in rows) for label in cfg['physical_envelopes']}
base_l2_data_bits=b['l2_bytes']*8
# Use observed baseline L2 directory width: 1024 x168. Data array is unchanged.
base_l2_bits=base_l2_data_bits+1024*168
normalization=[]
for label,p in cfg['physical_envelopes'].items():
 l2_macro_proxy=base_l2_bits*p['sram_um2_per_bit']*p['packing_factor']/1e6
 delta=totals[label]
 normalization.append({'case':label,'incremental_mm2_ASSUMPTION':delta,'pct_of_paper_boom_REFERENCE_ONLY':100*delta/reference_boom,'pct_of_paper_peek_REFERENCE_ONLY':100*delta/reference_peek,'peek_plus_increment_REFERENCE_ONLY_mm2':reference_peek+delta,'l2_data_directory_macro_proxy_mm2':l2_macro_proxy,'delta_pct_of_proxy_L2':100*delta/l2_macro_proxy,'l2_metadata_pct_of_proxy_L2':100*rows[1][f'{label}_total_mm2']/l2_macro_proxy,'delta_pct_of_paper_peek_plus_proxy_L2':100*delta/(reference_peek+l2_macro_proxy),'unprotected_architecture_area_mm2':None,'actual_check_peek_area_mm2':None,'actual_check_palimpsest_area_mm2':None,'physical_timing_ns':None})
writecsv('results/normalization.csv',normalization)
# Three architectures, preserving unknowns instead of relabeling MEEK or PEEK
# BOOM as an unprotected core. Reference-only totals are separate columns.
comparison=[{'architecture':'Unprotected baseline','actual_area_mm2':None,'reference_area_mm2':None,'incremental_model_mm2':None,'status':'UNVERIFIED: no matched unprotected synthesis; MEEK 3.89 is protected'},
 {'architecture':'PEEK','actual_area_mm2':None,'reference_area_mm2':reference_peek,'incremental_model_mm2':0,'status':'PAPER_REFERENCE_ONLY: TSMC28, different 4-wide/ROB128; macro boundary unclear'},
 {'architecture':'PALIMPSEST','actual_area_mm2':None,'reference_area_mm2':reference_peek+totals['typical'],'incremental_model_mm2':totals['typical'],'status':'ILLUSTRATIVE_REFERENCE_PLUS_MODEL: not matched platform or whole-chip synthesis'}]
writecsv('results/system_comparison.csv',comparison)
# Symbolic formulas give the total overhead honestly even when U/P are unknown.
summary={'area_status':'NO_MAPPED_28NM_AREA; engineering sensitivity, not confidence intervals','typical_fields':f,'metadata_bits_per_line':field,'incremental_mm2_sensitivity':totals,'total_memory_bits':sum(r['added_memory_bits'] for r in rows),'total_dff_bits':sum(r['dff_bits'] for r in rows),'total_generic_ge_excluding_ram':sum(r['generic_ge_excluding_ram'] for r in rows),'paper_reference_peek_mm2':reference_peek,'matched_delta_percentage':None,'unprotected_total_overhead_percentage':None,'formulas':{'A':'100*D/P, P=matched PEEK area, D=integrated PAL-PEEK delta','B':'100*(P+D-U)/U, U=matched unprotected area','with_L2':'100*D/(P+L), only if L2 excluded from P; add common peripheral area X to both denominators if desired'},'ff_implementation':{'extra_ram_bits_if_all_RAM_is_DFF':sum(r['added_memory_bits'] for r in rows),'additional_DFF_GE_only_lower_bound':sum(r['added_memory_bits'] for r in rows)*6,'note':'Excludes memory port mux/decoder/enable overhead; not a real SRAM implementation and not an upper bound'},'top3_typical':[(r['component'],r['typical_total_mm2']) for r in sorted(rows,key=lambda r:r['typical_total_mm2'],reverse=True)[:3]],'limitations':['One lookup/store lane per cache only; BOOM banking/load-port replication is unresolved','Sidecar SRAM packing/ports not mapped; density scenarios are assumed','EVT finite capacity, reclamation/rebase missing','LSL allocator/CDC/TileLink integration and multi-address WB concurrency missing','Architectural checkpoint payload is provisional (13 shadow CSRs plus full register slots), not full ISA recovery certification','No system synthesis, timing, power or SRAM macro result','PEEK Table3 macro/cache inclusion boundary not established; never add L2 twice']}
(ROOT/'results/area_summary.json').write_text(json.dumps(summary,indent=2)+'\n')
# Structural field sensitivity is independent of density and generic counts.
fieldrows=[]
for label,s in cfg['field_scenarios'].items():
 width=sum(s[k] for k in ['seq_w','epoch_w','gen_w','owner_w'])+2
 fieldrows.append({'field_scenario':label,'bits_per_line':width,'L1_metadata_bits':b['l1d_bytes']//64*width,'L2_metadata_bits':b['l2_bytes']//64*width,'EVT_interval_valid_bits':(1<<s['epoch_w'])*(2*s['seq_w']+1),'context_payload_bits':s['context_slots']*cfg['context_words']*64,'memory_macro_area_mm2':None,'note':'Structural sensitivity only; generic gate counts synthesized only for typical fields'})
writecsv('results/field_sensitivity.csv',fieldrows)
trend=[]
for kib in [128,256,512,1024,2048]:
 for label,p in cfg['physical_envelopes'].items():
  bits=kib*1024//64*field
  trend.append({'L2_KiB':kib,'physical_assumption':label,'metadata_bits':bits,'metadata_SRAM_estimate_mm2':bits*p['sram_um2_per_bit']*p['packing_factor']/1e6})
writecsv('results/cache_capacity_sensitivity.csv',trend)
# Publication export: all plots label modeled versus observed quantities.
plt.rcParams.update({'font.size':8,'font.family':'DejaVu Sans','pdf.fonttype':42,'ps.fonttype':42})
fig,ax=plt.subplots(figsize=(7.2,3.6));names=[r['component'].replace(' / ','/').replace('Version ','V. ') for r in rows];y=list(range(len(rows)))
ax.barh(y,[r['typical_storage_mm2'] for r in rows],label='SRAM density assumption',color='#4c78a8')
left=[r['typical_storage_mm2'] for r in rows]
for key,label,color in [('combinational','Generic gates × assumed GE area','#f58518'),('sequential','DFF counts × assumed GE area','#54a24b'),('buffer_interface','Unintegrated interface allowance','#b279a2')]:
 vals=[r[f'typical_{key}_mm2'] for r in rows];ax.barh(y,vals,left=left,label=label,color=color);left=[a+b for a,b in zip(left,vals)]
ax.set_yticks(y,names);ax.invert_yaxis();ax.set_xlim(0,max(left)*1.1);ax.set_xlabel('Area model (mm²); NOT mapped 28 nm synthesis');ax.legend(fontsize=6,loc='lower right');fig.tight_layout()
for ext in ['pdf','svg','png']:fig.savefig(ROOT/f'figures/incremental_modules.{ext}',dpi=220)
plt.close(fig)
fig,ax=plt.subplots(figsize=(5,3));ax.bar([1,2],[reference_peek,reference_peek],color='#4c78a8',label='PEEK paper core sum (different config)')
ax.bar(2,totals['typical'],bottom=reference_peek,color='#f58518',hatch='//',label='Independent incremental model')
ax.errorbar(2,reference_peek+totals['typical'],yerr=[[totals['typical']-totals['low']],[totals['high']-totals['typical']]],fmt='none',color='black',capsize=3)
ax.text(0,.1,'Unknown\nU',ha='center');ax.set_xticks([0,1,2],['Unprotected','PEEK paper','Reference + model']);ax.set_xlim(-.5,2.7);ax.set_ylabel('Reference-only area (mm²)');ax.set_title('Not a matched whole-system area comparison',fontsize=9);ax.legend(fontsize=6);fig.tight_layout()
for ext in ['pdf','svg','png']:fig.savefig(ROOT/f'figures/system_reference_only.{ext}',dpi=220)
plt.close(fig)
fig,ax=plt.subplots(figsize=(4.6,2.8))
for label in ['low','typical','high']:
 a=[r for r in trend if r['physical_assumption']==label];ax.plot([r['L2_KiB'] for r in a],[r['metadata_SRAM_estimate_mm2'] for r in a],marker='o',label=label)
ax.set_xlabel('L2 capacity (KiB), 64 B lines');ax.set_ylabel('Metadata SRAM model (mm²)');ax.set_title('30 bits/line; assumed density/packing, no macro mapping',fontsize=8);ax.legend();fig.tight_layout()
for ext in ['pdf','svg','png']:fig.savefig(ROOT/f'figures/cache_metadata_sensitivity.{ext}',dpi=220)
plt.close(fig)
# Exact output for report generator/terminal.
print(json.dumps(summary,indent=2))
