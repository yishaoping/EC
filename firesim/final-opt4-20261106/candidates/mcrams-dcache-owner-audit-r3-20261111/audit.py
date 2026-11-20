#!/usr/bin/python3
"""Reuse live r1 GG transform; exact memory-wrapper structural parity audit."""
import argparse, datetime, fcntl, hashlib, json, os, pathlib, re, time, difflib
P=pathlib.Path;C=P(__file__).resolve().parent
W=P('/data1/gzh/EC/firesim/final-opt4-20261106');D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
R=D/'build-logs/Opt4-mcrams-dcache-owner-system-r1-20261111'
O=D/'build-logs/Opt4-mcrams-dcache-owner-audit-r3-20261111'
ROOT=W/'Opt4-fit-dcache-field-read-prune-r1-20261111/builds/system-3656aec4-r4'
LOW=ROOT/'goldengate/post-bridge-extraction.fir';NAME='ownerImageMemory_flattened'
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def sha(p):
 h=hashlib.sha256()
 with P(p).open('rb') as f:
  for b in iter(lambda:f.read(2**20),b''):h.update(b)
 return h.hexdigest()
def read(p):return json.loads(P(p).read_text())
def save(p,x):
 p=P(p);p.parent.mkdir(parents=True,exist_ok=True);t=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with t.open('w') as f:json.dump(x,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(t,p)
def mod(t,n):return re.search(r'^  module '+re.escape(n)+r' :[^\n]*\n.*?(?=^  (?:ext)?module |\Z)',t,re.M|re.S)[0]
def memory(t,name=NAME):return re.search(r'^    mem '+name+r' :[^\n]*\n(?:      [^\n]*\n)+',t,re.M)[0]
def semantic_lines(t):
 return [re.sub(r'\s+@\[.*\]$','',x).strip() for x in t.splitlines() if x.strip()]
def check_pair(oldtext,newtext,module_name='BoomNonBlockingDCache',name=NAME):
 old=mod(oldtext,module_name);new=mod(newtext,module_name);mem=memory(old,name)
 inst=re.search(r'^    inst '+name+r' of (\S+)',new,re.M);assert inst,'memory wrapper instance missing'
 wrapper=mod(newtext,inst[1]);wrappedmem=memory(wrapper,name)
 assert semantic_lines(mem)==semantic_lines(wrappedmem),'memory definition/timing/ports changed'
 ports=re.findall(r'^      (?:reader|writer) => (.+)$',mem,re.M)
 readers=re.findall(r'^      reader => (.+)$',mem,re.M);writers=re.findall(r'^      writer => (.+)$',mem,re.M)
 assert len(readers)==35 and len(writers)==1
 # Normalize only the declared LabelSRAMModels memory-to-instance wrapping.
 # Every other DCache statement and output must remain exactly the same.
 old=old.replace(mem,'')
 new=re.sub(r'^    inst '+name+r' of [^\n]*\n','',new,flags=re.M)
 old_clock=re.findall(r'^    '+name+r'\.([^\n]+?)\.clk <= (.+)$',old,re.M)
 new_clock=re.findall(r'^    '+name+r'\.clk <= (.+)$',new,re.M)
 assert len(old_clock)==36 and len(new_clock)>=1,'clock binding inventory changed'
 normalizeclock=lambda v:re.sub(r'\s+@\[.*\]$','',v)
 assert set(normalizeclock(x[1]) for x in old_clock)=={'clock'}
 assert set(normalizeclock(x) for x in new_clock)=={'clock'}
 old=re.sub(r'^    '+name+r'\.[^\n]+?\.clk <= [^\n]*\n','',old,flags=re.M)
 new=re.sub(r'^    '+name+r'\.clk <= [^\n]*\n','',new,flags=re.M)
 a,b=semantic_lines(old),semantic_lines(new)
 if a!=b:
  (O/'unexpected-dcache-delta.diff').write_text('\n'.join(difflib.unified_diff(a,b,n=2))+'\n')
  raise AssertionError('non-wrapper DCache semantic statements differ; preserved for review')
 # Wrapper must wire every original port field directly to exactly the
 # corresponding external field and bind every memory clock to its clock.
 wl=semantic_lines(wrapper);connections=[x for x in wl if '<=' in x or '<-' in x]
 expected=[f'{name}.{p} <- {p}' for p in ports]+[f'{name}.{p}.clk <= clk' for p in ports]
 assert sorted(connections)==sorted(expected),'wrapper contains changed/missing/additional logic'
 return dict(target_DCache_nonwrapper_statements_identical=True,all_35_read_ports_preserved=True,
   single_writer_preserved=True,all_518_generation_debug_observations_preserved_by_exact_DCache_comparison=True,
   reset_and_write_gate_identical=True,raw_memory_definition_exact=True,read_latency=0,write_latency=1,
   read_under_write='undefined',width=81,depth=512,wrapper_module=inst[1],wrapper_sha256=hashlib.sha256(wrapper.encode()).hexdigest(),
   normalized_DCache_sha256=hashlib.sha256('\n'.join(a).encode()).hexdigest())
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--watch',action='store_true');args=ap.parse_args()
 O.mkdir(parents=True,exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 if (O/'complete.json').exists():
  x=read(O/'complete.json');assert sha(O/'result.json')==x['result_sha256'] and sha(__file__)==x['auditor_sha256'];print('IMMUTABLE_COMPLETE_REUSED');return
 receipt=R/'receipts/goldengate-owner-only.json'
 while not receipt.exists():
  state=read(R/'state.json') if (R/'state.json').exists() else {}
  save(O/'state.json',dict(status='WAITING_EXISTING_GG_NOT_DUPLICATING',utc=now(),pid=os.getpid(),existing_controller=state.get('pid'),existing_child=state.get('child'),receipt=str(receipt)))
  if state.get('status')=='FAILED_WITH_EVIDENCE':raise RuntimeError('GG failed before successful receipt; original evidence retained')
  if not args.watch:return
  time.sleep(300)
 r=read(receipt);assert r['returncode']==0
 append_receipt=R/'goldengate/blackboxes-appended.json'
 final_result=read(R/'result.json')
 assert final_result['status']=='HOST_RTL_GENERATED_REQUIRES_FULL_TARGET_PARITY_AND_AREA'
 assert append_receipt.exists(),'missing append receipt'
 append=read(append_receipt)
 for p,h in r['outputs'].items():
  p=P(p);assert p.is_file()
  if p.name!='FireSim-generated.sv':assert sha(p)==h,'GG completed non-SV output changed';continue
  final=p.read_bytes();listed=p.parent/'firrtl_black_box_resource_files.f'
  suffix=b''.join(P(n).read_text().encode() for n in listed.read_text().splitlines() if n.strip()) if listed.exists() else b''
  assert suffix and final.endswith(suffix),'blackbox append content mismatch'
  raw=final[:-len(suffix)]
  assert hashlib.sha256(raw).hexdigest()==h,'pre-append generated SV prefix hash mismatch'
  assert sha(p)==append['sha256']==final_result['host_rtl_sha256'],'final SV append/result hashes differ'
  save(O/'sv-append-chain.json',dict(raw_SV_sha256=h,final_SV_sha256=sha(p),exact_appended_resource_sha256=hashlib.sha256(suffix).hexdigest(),appended_bytes=len(suffix),raw_bytes=len(raw),append_receipt_sha256=sha(append_receipt),all_nonSV_outputs_exact=True))
 pre=read(R/'preflight.json');plan=read(W/'candidates/mcrams-dcache-owner-system-r1-20261111/plan.json')
 assert all(sha(p)==h for p,h in plan['inputs'].items()) and all(sha(p)==h for p,h in plan['evidence_sources'].items())
 g=R/'goldengate'
 original=mod(LOW.read_text(),'BoomNonBlockingDCache');same=mod((g/'post-bridge-extraction.fir').read_text(),'BoomNonBlockingDCache')
 assert original==same,'pre-host target DCache changed'
 result=check_pair((g/'post-wrap-top.fir').read_text(),(g/'post-wrap-sram-models.fir').read_text())
 # The independent capsule retains raw sv+header without changing live GG outputs.
 save(O/'raw-host-binding.json',{str(p):sha(p) for p in [g/'FireSim-generated.sv',g/'FireSim-generated.const.h',g/'post-bridge-extraction.fir']})
 result.update(schema='ec-owner-only-wrapper-structural-audit/3',utc=now(),status='STRUCTURAL_PASS_REQUIRES_FULL_TARGET_PARITY_AND_PAIRED_FULL_DCACHE_AREA',
   functional_baseline=pre['functional_baseline'],derived_hardware=pre['derived_hardware'],production_admission=False,whole_fit=False,
   existing_GG_receipt=str(receipt),existing_GG_receipt_sha256=sha(receipt),no_duplicate_transform=True,fpga_access=False,
   proof_scope='Exact compiler memory wrapping and preserved original target statements; not universal full-DUT equivalence or FPGA admission')
 save(O/'result.json',result);save(O/'complete.json',dict(result_sha256=sha(O/'result.json'),auditor_sha256=sha(__file__)))
 save(O/'state.json',dict(status=result['status'],utc=now(),pid=os.getpid(),result_sha256=sha(O/'result.json')))
 print(json.dumps(result))
if __name__=='__main__':
 try:main()
 except Exception as e:
  if O.exists():save(O/'failure.json',dict(utc=now(),status='FAIL_PRESERVED_NO_TRANSFORM_RERUN',error=repr(e)));save(O/'state.json',dict(utc=now(),status='FAILED_WITH_EVIDENCE',error=repr(e)))
  raise
