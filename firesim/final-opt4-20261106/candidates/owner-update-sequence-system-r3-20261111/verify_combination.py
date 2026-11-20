from pathlib import Path
import hashlib,json,subprocess
C=Path(__file__).resolve().parent;W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');L=D/'build-logs/Opt4-fit-owner-update-sequence-system-r3-20261111'
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
aseq=D/'Opt4-fit-address-update-sequence-r1-state.json';a=json.loads(aseq.read_text());assert a['hardware_commit']==sequence and a['status']=='VERIFIED_AND_MAPPED_COMPLETE_ADDRESS_MODULE_NOT_WHOLE_DUT' and a['exact_parent_reversal'] and a['full_module_regression'].startswith('PASS_6144')
mp=a['full_module_map'];assert sha(mp['report'])==mp['report_sha256'] and mp['resources']['CLB LUTs']<872880
op=D/'Opt4-fit-dcache-full-pair-r2-state.json';p=json.loads(op.read_text());assert p['hardware_commit']==owner and p['status']=='COMPLETE_REAL_FULL_DCACHE_OBSERVED_PAIR_NOT_WHOLE_DUT_FIT' and p['lut_saved']>=75000
for row in p['maps'].values():assert sha(row['report'])==row['report_sha256']
r=dict(schema='ec-opt4-compositional-owner-address/1',status='PASS_EXACT_DISJOINT_SOURCE_COMPOSITION_COMPONENT_PROOFS_AND_ACTUAL_AREA_PENDING_TYPECHECK_GG',hardware_commit=b['hardware_commit'],source_id=b['source_id'],frozen_commit=b['frozen_commit'],component_commits=[owner,sequence],owner_proof_sha256=sha(ownerproof),address_proof_state_sha256=sha(aseq),full_dcache_area_state_sha256=sha(op),architectural_recovery_added=False,source_files_exact_components=True,all_other_bytes_common_parent=True,full_dut_formal=False,fpga_access=False,proof_limits='Source-bound compositional induction and unchanged module interfaces; address6144cycle52outputs+reset. Not monolithic fullDCache or fullDUT SAT. No arithmetic addition of local area gains used to claim wholeFIT.')
(L/'combined-equivalence.json').write_text(json.dumps(r,indent=2,sort_keys=True)+'\n')
