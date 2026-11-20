"""Expose superseded real failures alongside accepted scoped measurements."""
from common import *
import csv

cases=[('fluidanimate','fluid-full-frame-failure-chain.json'),('ferret','ferret-full-emd-failure-chain.json'),('dedup','dedup-buffer128-failure-chain.json')]
rows=[]
for benchmark,name in cases:
 p=ROOT/'diagnostics'/name;j=read(p);events=j.get('nonpass_results',[])
 result=j.get('result',j.get('observed_result',{}));rdir=Path(result.get('run_dir') or j.get('run_dir'))
 binding=read(rdir/'binding.json');mf=read(binding['manifest'])
 q=next(x for x in read(ROOT/'queue.json')['items'] if x['benchmark']==benchmark)
 selected=read(ROOT/q['manifest'])
 rows.append(dict(benchmark=benchmark,failed_profile=mf['profile'],status='OBSERVED_NONPASS_EXCLUDED',first_cancelled_sequence=min(x['package_seq'] for x in events),first_cancelled_boom_csr_cycle=min(x['boom_csr_cycle'] for x in events),observed_nonpass_results=len(events),complete_performance_pair=False,slowdown=None,selected_profile=selected['profile'],selected_scope_is_hardware_fix=False,root_cause='UNPROVEN',strict_detection_latency_cycles=None,full_rollback_latency_cycles=None,diagnostic=str(p),diagnostic_sha256=sha(p),raw_log=str(rdir/'host-complete.log.gz'),raw_integrity=str(rdir/'stdout-integrity.json'),functional_baseline=BASE))
with (ROOT/'paper/superseded-failures.csv').open('w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=list(rows[0]));w.writeheader();w.writerows(rows)
print('Superseded real cancellation cases retained:',len(rows),flush=True)
