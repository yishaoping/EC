"""Preserve superseded and incomplete evidence independently of selected profiles."""
from common import *
import csv
selected={str(ROOT/x['manifest']) for x in read(ROOT/'queue.json')['items']}
rows=[]
for p in sorted((ROOT/'runs').glob('*/binding.json')):
 b=read(p);rp=p.parent/'result.json';r=read(rp) if rp.exists() else {}
 reason=p.parent/'external-stop-reason.json'
 if not reason.exists():reason=p.parent/'diagnostic-stop-reason.json'
 rows.append(dict(run=p.parent.name,benchmark=r.get('benchmark'),profile=r.get('profile'),mode=r.get('mode'),repeat=r.get('repeat'),selected_manifest=b['manifest'] in selected,status=r.get('status','RUNNING_OR_INTERRUPTED_WITHOUT_RESULT'),software_correct=r.get('software_correct'),valid=r.get('valid'),native_or_ec_roi_cycles=r.get('roi_cycles'),roi_instructions=r.get('roi_instructions'),stop_cause=r.get('stop_cause'),returncode=r.get('returncode'),functional_baseline=b['functional_baseline'],manifest=b['manifest'],bound_manifest_sha256=b['manifest_sha256'],binding=str(p),result=str(rp) if r else None,complete_receipt=str(p.parent/'complete.json') if (p.parent/'complete.json').exists() else None,external_stop_reason=str(reason) if reason.exists() else None,raw_integrity=str(p.parent/'stdout-integrity.json') if (p.parent/'stdout-integrity.json').exists() else None,pair_acceptance_reference=str(ROOT/'paper/parsec8-native-ec.csv')))
with (ROOT/'paper/all-run-evidence-ledger.csv').open('w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=list(rows[0]) if rows else ['run']);w.writeheader();w.writerows(rows)
comparisons=[]
for name,old,new in [('ferret','real-test-first-emd-warm-replay','real-test-first-emd-warm-replay-qword-setup')]:
 ps=[ROOT/'runs'/f'{name}-{v}-native-r1/result.json' for v in [old,new]]
 if not all(p.exists() for p in ps):continue
 a,b=map(read,ps)
 if a.get('valid') and b.get('valid'):
  comparisons.append(dict(benchmark=name,old_profile=old,new_profile=new,old_native_cycles=a['roi_cycles'],new_native_cycles=b['roi_cycles'],instructions_match=a['roi_instructions']==b['roi_instructions'],roi_instructions=b['roi_instructions'],relative_cycle_change=b['roi_cycles']/a['roi_cycles']-1,scope='NATIVE_ONLY_SETUP_AND_LINK_LAYOUT_VARIANT_NOT_EC_SLOWDOWN_OR_GENERAL_ERROR_BOUND',old_evidence=str(ps[0]),new_evidence=str(ps[1])))
with (ROOT/'paper/setup-variants-native-only.csv').open('w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=list(comparisons[0]) if comparisons else ['benchmark']);w.writeheader();w.writerows(comparisons)
