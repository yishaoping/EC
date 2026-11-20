#!/usr/bin/env python3
"""Reproducible generic synthesis; RAM cells retained as explicit blackboxes.

No technology mapping to a 28 nm library. Gate-equivalent weights are a
transparent analytical model, NOT measured cell area. RAM ports/decoders are
inside the abstract macro; arrays never get silently counted as zero-area.
"""
from pathlib import Path
import subprocess,json,hashlib,time,argparse
ROOT=Path(__file__).resolve().parents[1]
parser=argparse.ArgumentParser(); parser.add_argument('--force',action='store_true'); args=parser.parse_args()
OUT=ROOT/'results/synthesis'; OUT.mkdir(exist_ok=True)
rtl=ROOT/'rtl/palimpsest.sv'
shapes={
 'l1_metadata':('pal_metadata_ram',{'SETS':64,'WAYS':8}),
 'l2_metadata':('pal_metadata_ram',{'SETS':1024,'WAYS':8}),
 'evt':('pal_evt',{'QUERIES':8}),
 'selector_l1':('pal_version_select',{'WAYS':8}),
 'selector_l2':('pal_version_select',{'WAYS':8}),
 'preserve':('pal_preserve',{}),
 'visibility':('pal_visibility',{}),
 'store_policy':('pal_store_policy',{'WAYS':8}),
 'reclaim':('pal_lsl_reclaim',{'SLOTS':8}),
 'sw':('pal_safe_watermark',{}),
 'rollback':('pal_rollback',{}),
 'context':('pal_context_store',{'SLOTS':8,'WORDS':80}),
}
# Yosys internal fine cells. INV=0.5 GE, NAND/NOR/AND/OR=1 GE,
# XOR/XNOR=2 GE, MUX=3 GE, DFF=6 GE. This is a chosen NAND2 model.
def weight(kind):
 if kind.startswith(('$_DFF','$_SDFF','$_ADFF','$_DFFE','$_SDFFE','$_ALDFF')):
  # Registers, clock enables, synchronous resets are mapped before counting.
  return 6.0,'sequential'
 if kind=='$_NOT_':return .5,'combinational'
 if kind in ('$_AND_','$_OR_','$_NAND_','$_NOR_'):return 1.0,'combinational'
 if kind in ('$_XOR_','$_XNOR_'):return 2.0,'combinational'
 if kind in ('$_MUX_','$_NMUX_'):return 3.0,'combinational'
 if kind in ('$_ANDNOT_','$_ORNOT_'):return 1.5,'combinational'
 if kind in ('$_AOI3_','$_OAI3_'):return 1.5,'combinational'
 if kind in ('$_AOI4_','$_OAI4_'):return 2.0,'combinational'
 raise ValueError('Unmodelled generic cell '+kind)
summary={}
for name,(top,params) in shapes.items():
 d=OUT/name; d.mkdir(exist_ok=True)
 fingerprint=hashlib.sha256(rtl.read_bytes()+Path(__file__).read_bytes()+json.dumps(params,sort_keys=True).encode()).hexdigest()
 resultpath=d/'result.json'
 if resultpath.exists() and not args.force:
  cached=json.loads(resultpath.read_text())
  if cached.get('fingerprint')==fingerprint:
   summary[name]=cached; print(name,'cached',flush=True); continue
 change=' '.join(f'-set {k} {v}' for k,v in params.items())
 # Small multiported/resettable tables are registers, not fictitious SRAMs.
 smallmap='memory_map;' if name in ('evt','reclaim') else (
   'memory_map pal_context_store/seq pal_context_store/epoch;' if name=='context' else '')
 first=f'read_verilog -sv {rtl}; chparam {change} {top}; hierarchy -check -top {top}; proc; opt; memory_dff; memory_collect; {smallmap} opt; check; write_json {d}/memory.json; stat'
 (d/'collect.ys').write_text(first+'\n')
 start=time.time()
 with (d/'collect.log').open('w') as log:
  subprocess.run(['yosys','-T','-s',str(d/'collect.ys')],stdout=log,stderr=subprocess.STDOUT,check=True,timeout=60)
 design=json.loads((d/'memory.json').read_text())
 memories=[]
 for mod in list(design['modules'].values()):
  for cellname,cell in mod.get('cells',{}).items():
   if cell['type']!='$mem_v2':continue
   param=cell['parameters']; num=lambda k:int(param[k],2)
   memories.append({'cell':cellname,'width':num('WIDTH'),'depth':num('SIZE'),'bits':num('WIDTH')*num('SIZE'),'read_ports':num('RD_PORTS'),'write_ports':num('WR_PORTS')})
   memtype='AREA_RAM_'+str(len(memories)); ports={}; names={}; bit=2
   for pname,conn in cell['connections'].items():
    bits=list(range(bit,bit+len(conn)));bit+=len(conn)
    ports[pname]={'direction':cell['port_directions'][pname],'bits':bits}
    names[pname]={'hide_name':0,'bits':bits,'attributes':{}}
   design['modules'][memtype]={'attributes':{'blackbox':'1'},'ports':ports,'netnames':names,'cells':{}}
   cell['type']=memtype;cell['parameters']={}
 (d/'abstract.json').write_text(json.dumps(design))
 second=f'read_json {d}/abstract.json; hierarchy -check -top {top}; flatten; opt; techmap; opt; dffunmap; abc -g simple; clean; check; write_json {d}/gates.json; stat'
 (d/'gates.ys').write_text(second+'\n')
 with (d/'gates.log').open('w') as log:
  subprocess.run(['yosys','-T','-s',str(d/'gates.ys')],stdout=log,stderr=subprocess.STDOUT,check=True,timeout=60)
 mapped=json.loads((d/'gates.json').read_text())['modules'][top]
 counts={};ge={'sequential':0.,'combinational':0.};dff=0
 for cell in mapped['cells'].values():
  kind=cell['type']; counts[kind]=counts.get(kind,0)+1
  if kind.startswith('AREA_RAM_'):continue
  w,group=weight(kind); ge[group]+=w
  if group=='sequential':dff+=1
 result={'fingerprint':fingerprint,'top':top,'parameters':params,'seconds':round(time.time()-start,3),'cell_counts':counts,'dff_bits':dff,'ge':ge,'total_ge_excluding_ram':sum(ge.values()),'memories':memories,'memory_bits':sum(m['bits'] for m in memories),'evidence_level':'GENERIC_SYNTHESIS_PLUS_ASSUMED_GE_WEIGHTS','critical_path_ns':None,'area_mm2':None}
 resultpath.write_text(json.dumps(result,indent=2)+'\n');summary[name]=result
 print(name,'RAM',result['memory_bits'],'DFF',dff,'GE',result['total_ge_excluding_ram'],flush=True)
(OUT/'summary.json').write_text(json.dumps(summary,indent=2)+'\n')
