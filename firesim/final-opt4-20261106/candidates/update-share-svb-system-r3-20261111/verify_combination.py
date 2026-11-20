from pathlib import Path
import json,hashlib,subprocess,sys
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C=Path(__file__).resolve().parent
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import sha,save
cfg=json.loads((C/'config.json').read_text());b=cfg['binding'];F=Path(cfg['worktree']);p=Path(cfg['composed_proof']);r=json.loads(p.read_text())
assert r['hardware_commit']==b['hardware_commit'] and r['source_id']==b['source_id']
assert r['status']=='PASS_COMPOSED_SOURCE_BOUND_MODULE_EQUIVALENCE_TYPECHECKED_NOT_FULL_DUT_FORMAL_OR_CAD'
for row in r['emitted_component_rtl'].values():
 assert row['source_location_normalized_rtl_byte_equal']
 assert sha(row['rtl'])==row['sha256'] and sha(row['reference'])==row['reference_sha256']
assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==b['hardware_commit']
for rel in b['changed_files']:
 assert (F/rel).read_bytes()==subprocess.check_output(['git','show',b['hardware_commit']+':'+rel],cwd=F)
assert r['architectural_recovery_added'] is False
r['reused_receipt']=str(p);r['reused_receipt_sha256']=sha(p)
save(D/'build-logs/Opt4-fit-update-share-svb-system-r3-20261111/combined-equivalence.json',r)
print('PASS_REUSED_SOURCE_BOUND_COMPOSED_RTL_AND_COMPONENT_PROOFS')
