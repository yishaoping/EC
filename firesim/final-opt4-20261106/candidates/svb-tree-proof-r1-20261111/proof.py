#!/usr/bin/python3
"""Independent compositional certificate over actual emitted selection tree.
Full32 direct SAT continues separately; this job does not stop/admit it.
"""
from pathlib import Path
import re,json,subprocess,sys
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import save,sha,now
C=Path(__file__).resolve().parent;O=D/'build-logs/Opt4-fit-svb-tree-compositional-proof-r1-20261111';O.mkdir(exist_ok=True)
P=D/'build-logs/Opt4-fit-svb-tree-r5-20261111/candidate/CandidateSelection.v';s=P.read_text();clean=re.sub(r'//[^\n]*','',s);defs={m[1]:m[2].strip() for m in re.finditer(r'(?:wire(?:\s+\[[^]]+\])?\s+|assign\s+)(\w+)\s*=\s*(.*?);',clean,re.S)}
valid={f'io_valid_{i}':frozenset([i]) for i in range(32)}
def mask(expr):
 expr=expr.strip()
 if expr in valid:return valid[expr]
 if expr in defs:
  valid[expr]=mask(defs[expr]);return valid[expr]
 expr=re.sub(r'[()\s]','',expr);terms=expr.split('|');assert len(terms)>1,(expr,'not OR')
 return frozenset().union(*(mask(t) for t in terms))
keys={};indices={};rows=[]
for n,v in defs.items():
 m=re.fullmatch(r"\{io_seq_(\d+),io_generation_(\d+),5'h([0-9a-f]+)\}",v)
 if m:
  i,j,k=int(m[1]),int(m[2]),int(m[3],16);assert i==j==k;keys[n]=(frozenset([i]),"5'h"+format(i,'x'))
assert len(keys)==32
nodes=[(n,v) for n,v in defs.items() if n=='useRight' or re.fullmatch(r'useRight_\d+',n)]
assert len(nodes)==31
for select,expr in nodes:
 m=re.fullmatch(r'(\w+)\s*&\s*\(~(\w+)\s*\|\s*(\w+)\s*>\s*(\w+)\)',expr);assert m,(select,expr)
 rv,lv,rkey,lkey=m.groups();left,li=keys[lkey];right,ri=keys[rkey];assert not left&right and mask(lv)==left and mask(rv)==right
 idx=[n for n,v in defs.items() if re.sub(r'\s','',v)==f'{select}?{ri}:{li}'];assert len(idx)==1,(select,idx,li,ri)
 outs=[n for n,v in defs.items() if re.sub(r'\s','',v)==f'{select}?{rkey}:{lkey}'];assert len(outs)==(0 if select=='useRight_30' else 1)
 if outs:keys[outs[0]]=(left|right,idx[0])
 rows.append(dict(selector=select,left=sorted(left),right=sorted(right),selected_index=idx[0]))
 assert mask(defs['io_chosenValid'])==frozenset(range(32))
assert rows[-1]['left']+rows[-1]['right']==list(range(32))
assert re.sub(r'\s','',defs['io_chosenIdx'])==f"_T_154?{rows[-1]['selected_index']}:5'h0"
assert mask('_T_154')==frozenset(range(32))
# Universal unsigned merge lemma: winner belongs to a valid side, dominates
# both children, and retains the child's key and index. No input bounds.
verilog='''module MergeLemma(input av,bv, input[68:0] ak,bk,input[4:0] ai,bi,output ok,output mutant_ok);
wire choose_b=bv&(~av|bk>ak);wire v=av|bv;wire[68:0] k=choose_b?bk:ak;wire[4:0] i=choose_b?bi:ai;
assign ok= (v==(av|bv)) && (!v || ((choose_b?bv:av) && k==(choose_b?bk:ak) && i==(choose_b?bi:ai))) && (!av || k>=ak) && (!bv || k>=bk);
assign mutant_ok=(!v || k==(choose_b?ak:bk));
endmodule
'''
v=O/'merge.v';v.write_text(verilog)
for name,prop,negative in [('lemma','ok',False),('negative','mutant_ok',True)]:
 script=O/(name+'.ys');script.write_text('read_verilog '+str(v)+'\nprep -top MergeLemma -flatten\nsat -timeout 120 -verify -prove '+prop+' 1\n');log=O/(name+'.log')
 with log.open('w') as f:r=subprocess.run(['/usr/local/bin/yosys','-s',str(script)],stdout=f,stderr=subprocess.STDOUT,timeout=180)
 text=log.read_text();assert ('proof did fail' in text and r.returncode!=0) if negative else ('SUCCESS!' in text and r.returncode==0)
# Total-order uniqueness: slot index is part of key. Tree has each index once,
# so its maximum is exactly the reference noNewer pairwise argmax.
r=dict(schema='ec-svb-compositional-selection-proof/1',status='PASS_LOCAL_SAT_AND_ACTUAL_32_LEAF_31_MERGE_TOPOLOGY',utc=now(),hardware_commit='f2d2ca3ea0b12c918f2ccd2d1131be2709960470',source_id='f678ac806ea4b0f801596b26ec8bf9ef914a3161b39f92564ac25452abd8eafc',candidate_rtl=str(P),candidate_rtl_sha256=sha(P),merge_lemma_sha256=sha(v),lemmas=['merge selects a valid child exactly, or marks no valid child','unsigned 69-bit winner dominates both valid children for arbitrary values','31 actual RTL merges cover every one of 32 leaves exactly once without overlap','root valid equals any valid; invalid root index zero','keys concatenate exact 32-bit seq,32-bit generation,5-bit original slot; unique slot breaks ties','therefore root tuple is unique pairwise noNewer maximum'],nodes=rows,negative_mutation='REJECTED',whole_dut_formal=False,direct_32slot_sat='SEPARATE_RUNNING_NOT_CLAIMED_PASSED',fpga_execution=False)
save(O/'result.json',r);print(json.dumps(dict(status=r['status'],nodes=len(rows),path=str(O/'result.json'))))
