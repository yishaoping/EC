from pathlib import Path
import ast,hashlib,importlib.util,json,os,subprocess
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');U=D/'unattended-opt4';C=W/'candidates/owner-update-sequence-system-r1-20261111';F=W/'Opt4-fit-owner-update-sequence-r1-20261111';P=W/'Opt4-fit-dcache-owner-memory-r1-20261111';E=W/'Opt4-fit-address-update-sequence-r1-20261111';OWNER='2210930f510eccf5518c444dadca4a51bcf6f851';SEQ='e21194b24e3f9bf94c57dff009ed0c3d7d7eab7e';BASE='e0c3737f989c563f99a00f3fd26c1cbd27421775';REL='chipyard/generators/boom/src/main/scala/lsu/'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def read(p):return json.loads(Path(p).read_text())
def save(p,j):
 p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);t=p.with_name(p.name+'.tmp-combo');t.write_text(json.dumps(j,indent=2,sort_keys=True)+'\n');os.replace(t,p)
p=U/'foreground-area-owner.json';j=read(p);j['reserved_next_combination_paths']=[str(C),str(F)];j['next_combination_scope']='Only exact disjoint owner221+address e211 source composition. Prepare immutable version now; no admission/elaboration until real fullDCache pair and e211 actual map prove significant gain. Preserve live9ae/e0.';save(p,j)
assert not C.exists() and not F.exists();C.mkdir()
subprocess.run(['git','worktree','add','-b','opt4/owner-update-sequence-r1-20261111',str(F),OWNER],cwd=P,check=True,stdout=subprocess.DEVNULL)
for name in ['PackageAddressStats.scala','AddressBucketSequenceMemory.scala']:
 data=subprocess.check_output(['git','show',SEQ+':'+REL+name],cwd=E);assert data==(E/REL/name).read_bytes();(F/REL/name).write_bytes(data)
line=read(F/'lineage.json');line.update(branch='opt4/owner-update-sequence-r1-20261111',purpose='Independent exact owner221 and address e211 composition; same frozen functional/cycle semantics; awaiting combined proof/typecheck and actual module area gates.',source_tree=str(F/'chipyard'),component_commits=[OWNER,SEQ],functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8');save(F/'lineage.json',line)
subprocess.run(['git','diff','--check'],cwd=F,check=True);subprocess.run(['git','add',REL+'PackageAddressStats.scala',REL+'AddressBucketSequenceMemory.scala','lineage.json'],cwd=F,check=True);subprocess.run(['git','-c','user.name=EC experiment','-c','user.email=ec-experiment@localhost','commit','-m','Prepare exact owner storage and address sequence composition, unadmitted'],cwd=F,check=True,stdout=subprocess.DEVNULL)
commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip();s=importlib.util.spec_from_file_location('combination_inventory',W/'scripts/build_hw.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m);inventory=m.inventory(F/'chipyard');sid=hashlib.sha256(json.dumps(inventory,sort_keys=True).encode()).hexdigest()
cfg=read(W/'candidates/dcache-owner-system-r4-20261111/config.json');binding=cfg['binding'];binding.update(schema='ec-opt4-owner-sequence-composition/1',hardware_commit=commit,source_id=sid,parent_commit=OWNER,common_equivalent_parent=BASE,component_commits=[OWNER,SEQ],profile='Opt4-fit-C4-SVB32-owner-update-sequence-r1',production_selected=False);binding['changed_files'].append(REL+'AddressBucketSequenceMemory.scala');cfg.update(binding=binding,worktree=str(F));save(C/'config.json',cfg);(F/'bindings').mkdir();save(F/'bindings'/f'{commit}.json',binding);L=D/'build-logs/Opt4-fit-owner-update-sequence-system-r1-20261111';L.mkdir();save(L/'source-inventory.json',inventory);(L/'candidate.patch').write_bytes(subprocess.check_output(['git','diff','--binary',BASE,commit],cwd=F))
old=W/'candidates/dcache-owner-system-r4-20261111';controller=(old/'controller.py').read_text().replace('dcache-owner-system-r4-20261111','owner-update-sequence-system-r1-20261111').replace('dcache-owner-system-r4-state.json','owner-update-sequence-system-r1-state.json').replace('dcache-owner-rtl-state.json','owner-update-sequence-rtl-state.json')
a=controller.index(' while True:\n  mapped=');b=controller.index(" st=dict(schema='ec-opt4-best-module-system-preparation",a)
controller=controller[:a]+""" while True:
  mapped=read(D/'Opt4-fit-dcache-full-pair-r1-state.json');address=read(D/'Opt4-fit-address-update-sequence-r1-state.json')
  ownerproof=read(D/'Opt4-fit-dcache-owner-memory-validation-r3-state.json')
  deps=[mapped,address,ownerproof]
  if any(x.get('status') in ['FAILED_WITH_EVIDENCE','DEPENDENCY_FAILED_WITH_EVIDENCE'] for x in deps):
   waiting.update(status='DEPENDENCY_FAILED_WITH_EVIDENCE',dependencies=[x.get('status') for x in deps],updated_utc=now());save(S,waiting);save(L/'result.json',waiting);return
  if mapped.get('status')=='COMPLETE_REAL_FULL_DCACHE_OBSERVED_PAIR_NOT_WHOLE_DUT_FIT' and address.get('status')=='VERIFIED_AND_MAPPED_MODULE_ONLY' and ownerproof.get('status','').startswith('PASS_'):break
  waiting.update(status='WAITING_REAL_FULL_DCACHE_AND_ADDRESS_AREA_GATES',dependencies=[x.get('status') for x in deps],updated_utc=now());save(S,waiting);time.sleep(300)
 if mapped['lut_saved']<75000 or address['full_module_map']['resources']['CLB LUTs']>=872880:
  waiting.update(status='NOT_SELECTED_NO_SIGNIFICANT_COMBINED_MODULE_GAIN',dcache_observed_full_module_saving=mapped['lut_saved'],address_luts=address['full_module_map']['resources']['CLB LUTs'],updated_utc=now());save(S,waiting);save(L/'result.json',waiting);return
"""+controller[b:]
controller=controller.replace("'boom.lsu.AddressBucketUpdate$']","'boom.lsu.AddressBucketUpdate$','boom.lsu.AddressBucketSequenceMemory','boom.lsu.AddressBucketSequenceReplica']")
ast.parse(controller);(C/'controller.py').write_text(controller)
verify='''from pathlib import Path
import hashlib,json,subprocess
C=Path(__file__).resolve().parent;W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');L=D/'build-logs/Opt4-fit-owner-update-sequence-system-r1-20261111'
sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
cfg=json.loads((C/'config.json').read_text());b=cfg['binding'];F=Path(cfg['worktree']);owner,sequence=b['component_commits'];base=b['common_equivalent_parent'];rel='chipyard/generators/boom/src/main/scala/lsu/'
assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==b['hardware_commit']
get=lambda co,p:subprocess.check_output(['git','show',co+':'+p],cwd=F)
assert (F/rel/'dcache.scala').read_bytes()==get(owner,rel+'dcache.scala')
for n in ['PackageAddressStats.scala','AddressBucketSequenceMemory.scala']:assert (F/rel/n).read_bytes()==get(sequence,rel+n)
allowed={rel+'dcache.scala',rel+'PackageAddressStats.scala',rel+'AddressBucketSequenceMemory.scala','lineage.json'}
assert set(subprocess.check_output(['git','diff','--name-only',base,b['hardware_commit']],cwd=F,text=True).splitlines())==allowed
for p in b['changed_files']:
 if p not in allowed:assert (F/p).read_bytes()==get(base,p)
ownerproof=D/'build-logs/Opt4-fit-dcache-owner-system-r4-20261111/combined-equivalence.json';o=json.loads(ownerproof.read_text());assert o['hardware_commit']==owner and o['exact_source_reversal']
aseq=D/'Opt4-fit-address-update-sequence-r1-state.json';a=json.loads(aseq.read_text());assert a['hardware_commit']==sequence and a['status']=='VERIFIED_AND_MAPPED_MODULE_ONLY' and a['exact_parent_reversal'] and a['full_module_regression'].startswith('PASS_6144')
mp=a['full_module_map'];assert sha(mp['report'])==mp['report_sha256'] and mp['resources']['CLB LUTs']<872880
op=D/'Opt4-fit-dcache-full-pair-r1-state.json';p=json.loads(op.read_text());assert p['hardware_commit']==owner and p['status']=='COMPLETE_REAL_FULL_DCACHE_OBSERVED_PAIR_NOT_WHOLE_DUT_FIT' and p['lut_saved']>=75000
for row in p['maps'].values():assert sha(row['report'])==row['report_sha256']
r=dict(schema='ec-opt4-compositional-owner-address/1',status='PASS_EXACT_DISJOINT_SOURCE_COMPOSITION_COMPONENT_PROOFS_AND_ACTUAL_AREA_PENDING_TYPECHECK_GG',hardware_commit=b['hardware_commit'],source_id=b['source_id'],frozen_commit=b['frozen_commit'],component_commits=[owner,sequence],owner_proof_sha256=sha(ownerproof),address_proof_state_sha256=sha(aseq),full_dcache_area_state_sha256=sha(op),architectural_recovery_added=False,source_files_exact_components=True,all_other_bytes_common_parent=True,full_dut_formal=False,fpga_access=False,proof_limits='Source-bound compositional induction and unchanged module interfaces; address6144cycle52outputs+reset. Not monolithic fullDCache or fullDUT SAT. No arithmetic addition of local area gains used to claim wholeFIT.')
(L/'combined-equivalence.json').write_text(json.dumps(r,indent=2,sort_keys=True)+'\\n')
'''
ast.parse(verify);(C/'verify_combination.py').write_text(verify)
h=read(old/'input-hashes.json');h={p:v for p,v in h.items() if not p.startswith(str(old)) and not p.startswith(str(P))};h.update({str(F/p):sha(F/p) for p in b['changed_files']}) if False else None
# Bind shared compiler dependencies plus every new candidate source and controller.
h=read(old/'input-hashes.json');h={p:v for p,v in h.items() if not p.startswith(str(old)) and not p.startswith(str(P))};h.update({str(F/p):sha(F/p) for p in binding['changed_files']});h.update({str(C/n):sha(C/n) for n in ['config.json','controller.py','verify_combination.py']});save(C/'input-hashes.json',h)
spec=dict(name='owner-update-sequence-system-r1-'+commit[:8],kind='rtl',cwd=str(F/'chipyard'),argv=['/usr/bin/python3',str(C/'controller.py')],inputs={**h,str(C/'input-hashes.json'):sha(C/'input-hashes.json')},checkpoints=[str(D/'Opt4-fit-owner-update-sequence-system-r1-state.json'),str(D/'Opt4-fit-owner-update-sequence-rtl-state.json')],outputs=[str(L/'result.json')]);save(U/'requests'/(spec['name']+'.json'),dict(action='cpu_job',spec=spec));save(C/'binding.json',binding)
p=U/'campaign-policy.json';j=read(p);j['conditional_next_combination']=dict(commit=commit,source_id=sid,components=[OWNER,SEQ],state=str(D/'Opt4-fit-owner-update-sequence-system-r1-state.json'),request=str(U/'requests'/(spec['name']+'.json')),scope='Actual independent source combination prepared. NOT admitted: waits actual fullDCache and e211 area gates then verifies exact disjointsource composition/compile/GG/ABI. No thirdwholewhile9ae/e0live. After acceptedGG/ABI prepare separate CAD/runtime bound to this commit, never edit e0.')
save(p,j);print(json.dumps(dict(hardware_commit=commit,source_id=sid,status='PREPARED_NOT_ADMITTED_AREA_DEPENDENCIES_RUNNING',request=spec['name'])))
