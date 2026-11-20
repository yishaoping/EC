#!/usr/bin/python3
"""Select only the exact observed, proved source composition; no FPGA access."""
from pathlib import Path
import hashlib,json,subprocess
C=Path(__file__).resolve().parent;W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');L=D/'build-logs/Opt4-fit-dcache-owner-system-r4-20261111'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
cfg=json.loads((C/'config.json').read_text());b=cfg['binding'];F=Path(cfg['worktree']);M=W/'candidates/dcache-owner-memory-r1-20261111'
assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==b['hardware_commit']
assert set(subprocess.check_output(['git','diff','--name-only',b['parent_commit'],b['hardware_commit']],cwd=F,text=True).splitlines())=={'chipyard/generators/boom/src/main/scala/lsu/dcache.scala','lineage.json'}
src=F/'chipyard/generators/boom/src/main/scala/lsu/dcache.scala';back=src.read_text()
for new,old,n in reversed(json.loads((M/'reverse-substitutions.json').read_text())):
 assert new and back.count(new)>=n;back=back.replace(new,old,n)
assert back.encode()==subprocess.check_output(['git','show',b['parent_commit']+':chipyard/generators/boom/src/main/scala/lsu/dcache.scala'],cwd=F)
parent=D/'build-logs/Opt4-fit-update-share-svb-r2-20261111/composed-equivalence.json';p=json.loads(parent.read_text());assert p['hardware_commit']==b['parent_commit'] and not p['architectural_recovery_added']
for rel in b['changed_files']:
 if not rel.endswith('/dcache.scala'):assert (F/rel).read_bytes()==subprocess.check_output(['git','show',b['parent_commit']+':'+rel],cwd=F)
receipts={}
for name in ['Opt4-fit-dcache-owner-observed-map-r1-state.json','Opt4-fit-dcache-owner-memory-validation-r3-state.json','Opt4-fit-dcache-owner-arbiter-proof-r3-state.json']:
 path=D/name;j=json.loads(path.read_text());assert j['hardware_commit']==b['hardware_commit'];assert j['status'].startswith(('PASS_','COMPLETE_'))
 if name=='Opt4-fit-dcache-owner-observed-map-r1-state.json':
  contract_path=D/'build-logs/Opt4-fit-dcache-owner-observed-map-r1-20261111/source-contract.json';contract=json.loads(contract_path.read_text())
  validation=json.loads((D/'Opt4-fit-dcache-owner-memory-validation-r3-state.json').read_text())
  mapcfg_path=W/'candidates/dcache-owner-observed-map-r1-20261111/config.json';mapcfg=json.loads(mapcfg_path.read_text())
  assert mapcfg['binding']['hardware_commit']==b['hardware_commit'] and mapcfg['binding']['source_id']==b['source_id']
  assert contract['hardware_commit']==b['hardware_commit'] and contract['source_sha256']==j['source_validation_receipt']==validation['source_sha256']==sha(src)
  assert validation['source_id']==b['source_id']
  binding_receipt=dict(schema='ec-opt4-existing-map-source-binding/1',hardware_commit=b['hardware_commit'],source_id=b['source_id'],original_receipt=str(path),original_sha256=sha(path),contract_sha256=sha(contract_path),map_config_sha256=sha(mapcfg_path),source_sha256=sha(src),correction='Original complete map omitted source_id. Bound through immutable map config and exact source_validation_receipt; original unchanged.',complete_dcache_area=False)
  (L/'observed-map-source-binding.json').write_text(json.dumps(binding_receipt,indent=2,sort_keys=True)+'\n')
 else:assert j['source_id']==b['source_id']
 receipts[name]={'path':str(path),'sha256':sha(path),'status':j['status']}
m=json.loads((D/'Opt4-fit-dcache-owner-observed-map-r1-state.json').read_text());assert m['complete_generation_observation'] and m['input_field_aliases_match_source'] and m['lut_saved']>=75000
for row in m['maps'].values():assert sha(row['report'])==row['report_sha256'] and row['resources']['CLB LUTs']>0
result=dict(schema='ec-opt4-owner-system-composition/1',status='PASS_SOURCE_BOUND_OWNER_AND_E0_COMPOSITION_OBSERVED_AREA_NOT_FULL_DUT_FORMAL',hardware_commit=b['hardware_commit'],source_id=b['source_id'],frozen_commit=b['frozen_commit'],parent_commit=b['parent_commit'],parent_composition=str(parent),parent_composition_sha256=sha(parent),exact_source_reversal=True,all_other_modified_modules_byte_equal_parent=True,receipts=receipts,observed_storage_lut_saved=m['lut_saved'],scope='Source-bound146bit512word state representation induction and actual priorityArbiter2 exclusion. Same reset, invalid/debug reads, original256x2 configuration and all inherited frozen equivalent modules. Complete observed storage map is not completeDCache/whole DUT area. Actual GoldenGate origins/config/ABI and whole CAD are still required.',whole_dut_formal=False,fpga_access=False,architectural_recovery_added=False)
(L/'combined-equivalence.json').write_text(json.dumps(result,indent=2,sort_keys=True)+'\n')
