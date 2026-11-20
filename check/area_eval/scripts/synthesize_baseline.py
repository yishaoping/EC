#!/usr/bin/env python3
"""Synthesize bounded, existing PEEK components, preserving their real RAMs.

This is a component reference, NOT full BOOM/system area or a PAL/PEEK delta.
"""
from pathlib import Path
import json,subprocess
ROOT=Path(__file__).resolve().parents[1]
GEN=ROOT.parents[1]/'check/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config'
COLL=GEN/'gen-collateral'; OUT=ROOT/'results/baseline_synthesis'; OUT.mkdir(exist_ok=True)
hierarchy=json.loads((GEN/'top_module_hierarchy.json').read_text())
def find(n,target):
 if n['module_name']==target:return n
 for c in n.get('instances',[]):
  found=find(c,target)
  if found:return found
 return None
def modules(n):return {n['module_name']}.union(*(modules(c) for c in n.get('instances',[])))
summary={}
for top in ['R_RSU','R_LSL']:
 names=modules(find(hierarchy,top));d=OUT/top;d.mkdir(exist_ok=True)
 files=' '.join(str(COLL/(n+'.sv')) for n in sorted(names))
 script=f'read_verilog -sv -DSYNTHESIS {files}; hierarchy -check -top {top}; proc; opt; flatten; memory_dff; memory_collect; opt; check; write_json {d}/generic.json; stat'
 (d/'run.ys').write_text(script+'\n')
 with (d/'run.log').open('w') as log:
  subprocess.run(['yosys','-T','-s',str(d/'run.ys')],stdout=log,stderr=subprocess.STDOUT,check=True,timeout=60)
 design=json.loads((d/'generic.json').read_text())['modules'][top]
 mem=[];counts={}
 for cellname,c in design['cells'].items():
  counts[c['type']]=counts.get(c['type'],0)+1
  if c['type']=='$mem_v2':
   n=lambda k:int(c['parameters'][k],2)
   mem.append({'name':cellname,'bits':n('WIDTH')*n('SIZE'),'width':n('WIDTH'),'depth':n('SIZE'),'read_ports':n('RD_PORTS'),'write_ports':n('WR_PORTS')})
 sequential_bits=0
 for c in design['cells'].values():
  if c['type'] in ['$dff','$sdff','$adff','$dffe','$sdffe','$adffe']:
   sequential_bits+=int(c['parameters']['WIDTH'],2)
 result={'top':top,'source_files':sorted(names),'memory_bits':sum(m['bits'] for m in mem),'memories':mem,'sequential_bits_excluding_memories':sequential_bits,'generic_cell_counts':counts,'physical_area_mm2':None,'scope':'Existing component only; Yosys generic optimization; no technology timing or memory macro map'}
 summary[top]=result;(d/'result.json').write_text(json.dumps(result,indent=2)+'\n')
 print(top,'memory bits',result['memory_bits'],'register bits',sequential_bits,flush=True)
(OUT/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
