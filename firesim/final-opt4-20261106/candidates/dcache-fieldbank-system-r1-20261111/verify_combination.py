from pathlib import Path
import json,hashlib,subprocess
C=Path(__file__).resolve().parent;D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');L=D/'build-logs/Opt4-fit-dcache-fieldbank-system-r1-20261111'
read=lambda p:json.loads(Path(p).read_text());sha=lambda p:hashlib.sha256(Path(p).read_bytes()).hexdigest()
cfg=read(C/'config.json');b=cfg['binding'];source=D/'Opt4-fit-dcache-owner-fieldbanks-r1-state.json';parent=D/'build-logs/Opt4-fit-dcache-generated-owner-proof-r3-20261111/result.json';s=read(source);p=read(parent)
assert s['status']=='PASS_SOURCE_BOUND_FIELD_STORAGE_RELATION_TYPECHECK_FROZEN_PARAMETERS_NOT_GENERATED_OR_AREA_ADMITTED' and s['hardware_commit']==b['hardware_commit'] and s['source_id']==b['source_id'] and s['exact_parent_reversal']
assert p['status']=='PASS_ACTUAL_GENERATED_512WORD_TRANSITION_AND_TAPS_WITH_REAL_WRITE_MUTATION_NOT_FULL_DCACHE_FORMAL' and p['hardware_commit']==b['parent_commit'] and p['covered_count']==512 and p['actual_write_data_mutation_rejected']
assert b['frozen_commit']=='8491167d84b6d9521b151a743673c1516926a1f8'
for v in s['stages'].values():assert v['accepted'] and sha(v['log'])==v['sha256']
r=dict(schema='ec-fieldbank-composition/1',hardware_commit=b['hardware_commit'],source_id=b['source_id'],parent_commit=b['parent_commit'],frozen_commit=b['frozen_commit'],exact_source_reversal=True,field_widths=[81,32,32,1],source_proof_sha256=sha(source),parent_actual_generated_cut_proof_sha256=sha(parent),whole_dut_formal=False,area_admitted=False,fpga_access=False,proof_limits='Source-bound field decomposition composed with proven parent storage transition cut; new generatedRTL/fullmodulearea still required.')
(L/'combined-equivalence.json').write_text(json.dumps(r,indent=2,sort_keys=True)+'\n')
