#!/usr/bin/env python3
"""Read-only source/elaborated inventory and preservation verification."""
from pathlib import Path
import json,hashlib,subprocess,collections,re,shutil,datetime
ROOT=Path(__file__).resolve().parents[1]; EC=ROOT.parents[1]
GEN=EC/'check/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config'
SRC=EC/'check/source/chipyard'
manifest=json.loads((ROOT/'baseline/manifest.json').read_text())
changes=[]
for relative,item in manifest['files'].items():
 p=EC/relative
 if not p.is_file() or hashlib.sha256(p.read_bytes()).hexdigest()!=item['sha256']:changes.append(relative)
if changes:raise RuntimeError('Baseline changed: '+repr(changes))
# Walk elaboration hierarchy: count INSTANCES, not merely module definitions.
hierarchy=json.loads((GEN/'top_module_hierarchy.json').read_text())
counts=collections.Counter(); nodes=[]
def walk(node,parent=''):
 path=parent+'.'+node['instance_name'] if parent else node['instance_name']
 counts[node['module_name']]+=1;nodes.append((node['module_name'],path))
 for child in node.get('instances',[]):walk(child,path)
walk(hierarchy)
mems=json.loads((GEN/'gen-collateral/metadata/seq_mems.json').read_text())
rows=[]
for m in mems:
 rows.append({'module':m['module_name'],'depth':m['depth'],'width':m['width'],'instances':len(m['hierarchy']),'bits':m['depth']*m['width']*len(m['hierarchy']),'paths':m['hierarchy'],'status':'ELABORATED_SRAM_INTERFACE_NOT_PHYSICAL_MACRO'})
# Generated helper RAMs are distinct from compiler-separated seq_mems.
helper=[]
for name,path in nodes:
 p=GEN/f'gen-collateral/{name}.sv'
 if not p.is_file():continue
 txt=p.read_text()
 for a,ident,b in re.findall(r'\breg\s*\[\s*(\d+)\s*:\s*0\s*\]\s+(\w+)\s*\[\s*0\s*:\s*(\d+)\s*\]',txt):
  helper.append({'path':path+'.'+ident,'module':name,'width':int(a)+1,'depth':int(b)+1,'bits':(int(a)+1)*(int(b)+1),'evidence':str(p)+':'+str(txt[:txt.index(ident)].count('\n')+1)})
# Direct expected configuration checks against elaborated DTS.
dts=(GEN/'chipyard.TestHarness.v1Config.dts').read_text()
assert dts.count('compatible = "sifive,rocket0", "riscv";')==4
assert 'cache-size = <524288>' in dts and 'sifive,mshr-count = <7>' in dts
assert 'i-cache-size = <32768>' in dts and 'd-cache-size = <4096>' in dts
out={'time_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'baseline_unchanged':True,'hashed_files_checked':len(manifest['files']),'root_head':manifest['root_head'],'chipyard_head':manifest['chipyard_head'],'generated_directory':str(GEN),'module_instance_counts':dict(counts),'sram_interfaces':rows,'sram_interface_bits':sum(m['bits'] for m in rows),'generated_inline_arrays':helper,'inline_array_bits':sum(m['bits'] for m in helper)}
(ROOT/'results/baseline_inventory.json').write_text(json.dumps(out,indent=2)+'\n')
# Tools: version strings only, no CAD invocation or license checkout.
tools={}
for executable,version_args in [('yosys',['-V']),('iverilog',['-V']),('verilator',['--version']),('dc_shell',[]),('lc_shell',[]),('vivado',[])]:
 path=shutil.which(executable);v=None
 if path and version_args:
  r=subprocess.run([path]+version_args,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
  v=r.stdout.splitlines()[0]
 tools[executable]={'path':path,'version':v}
tools['known_db_files']=[str(p) for p in Path('/opt/dc/smic').glob('*.db')]
tools['library_limit']='SMIC DB files present; no accessible dc_shell/lc_shell in PATH, no mapped SRAM library in this flow. Yosys cannot read Synopsys .db. No TSMC cell/macro mapping performed.'
(ROOT/'evidence/tools.json').write_text(json.dumps(tools,indent=2)+'\n')
# Record all original artifacts consumed by audit, including generated modules.
used={}
for p in list(GEN.glob('*.json'))+list(GEN.glob('*.dts'))+list(GEN.glob('*.conf'))+list((GEN/'gen-collateral').glob('*.sv')):
 used[str(p.relative_to(EC))]=hashlib.sha256(p.read_bytes()).hexdigest()
(ROOT/'baseline/generated-sha256.json').write_text(json.dumps(used,indent=2)+'\n')
print('Baseline preserved:',len(manifest['files']),'files; generated instances',sum(counts.values()),'; explicit SRAM interface bits',out['sram_interface_bits'],'; inline bits',out['inline_array_bits'])
print('LSL instances:',[(n,p) for n,p in nodes if n=='R_LSL'])
print('LSL RAMs:',[m for m in helper if '.lsl.' in m['path']][:3])
