#!/usr/bin/python3
"""Validate frozen real event traces and export only strictly supported intervals."""
import collections,hashlib,importlib.util,json,math,pathlib,statistics,sys
P=pathlib.Path;ROOT=P('/data1/gzh/EC/slowdown/streamcluster_aggressive/variants/preservation_svb32_permission')
DOC=P('/data1/gzh/EC/slowdown/final_opt4_freeze_20261106');D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
L=D/'paper-evidence-20261111/real-event-intervals';L.mkdir(exist_ok=True)
def sha(p):return hashlib.sha256(P(p).read_bytes()).hexdigest()
def module(name,p):
 s=importlib.util.spec_from_file_location(name,p);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
stable=module('real_event_svb',ROOT/'slowdown/optimization_4_svb/analysis/analyze_svb.py')
def stats(values):
 values=sorted(values)
 if not values:return {'n':0}
 counts=collections.Counter(values)
 return dict(n=len(values),sum=sum(values),mean=statistics.mean(values),median=statistics.median(values),
  maximum=max(values),p95=values[math.ceil(.95*len(values))-1],p99=values[math.ceil(.99*len(values))-1],
  histogram={str(k):v for k,v in sorted(counts.items())},histogram_resolution='exact integer cycles; no bucket approximation',percentiles='nearest rank')
reports=[]
for item in json.loads((DOC/'data/FINAL_RUNS.json').read_text()):
 if item['mode']!='correction' or item['workload']=='bfs':continue
 mp=P(item['manifest']['absolute_path']);assert sha(mp)==item['manifest']['sha256']
 run=mp.parent;ap=run/'analysis.json';accepted=item.get('authoritative_final_gate',{})
 assert sha(ap)==accepted['lifetime']['analysis_sha256']
 a=json.loads(ap.read_text());assert a['status']=='PASS' and not a['errors']
 records=stable.parse_events(run/'safe_chain_events.tsv')
 integrity=stable.integrity_ledger.build(records);assert integrity['status']=='PASS' and not integrity['errors']
 protocol=stable.protocol_ledger(records,run/'safe_chain_events.tsv',32);assert protocol['status']=='PASS' and protocol['outstanding_at_end']==0
 lifecycle=integrity['lifecycles'];complete=[r for r in lifecycle if r['terminal_reason']=='PROMOTED_COMPLETED']
 intervals={}
 for label,begin,end in [('svb_capture_to_terminal_completion','capture_cycle','completion_cycle'),('svb_safe_to_promotion','safe_cycle','promotion_cycle'),('svb_promotion_to_ack','promotion_cycle','ack_cycle'),('svb_ack_to_completion','ack_cycle','completion_cycle')]:
  values=[]
  for r in complete:
   assert r[begin] is not None and r[end] is not None and r[end]>=r[begin]
   values.append(r[end]-r[begin])
  intervals[label]=stats(values)
 # Same original sequence and checker hart, all on checker-local CSR time.
 # This deliberately never subtracts BOOM sampled cycles or PACKAGE_BEGIN.
 local={}
 for r in records:
  if r['kind']==12 and 1<=r['hart']<=4 and r['nums'][0] and r['nums'][2]&2:
   n=r['nums'];key=(r['hart'],n[0]);v=(n[3],n[4],n[5],n[6])
   assert key not in local or local[key]==v
   local[key]=v
 checker=[]
 for key,(admit,start,seal,done) in local.items():
  if admit<=start<=done and seal>=admit and seal:
   checker.append({'hart':key[0],'sequence':key[1],'admit_to_start':start-admit,'admit_to_exec_done':done-admit,'start_to_exec_done':done-start})
 out=dict(workload=item['workload'],hardware_commit=item['hardware_commit'],origin='EXISTING_VALIDATED_FULL_TARGET_RTL_TRACE_NOT_FPGA_NEW_EXECUTION',
   input= item['workload'].split('_',1)[-1],run=str(run),manifest_sha256=sha(mp),analysis_sha256=sha(ap),
   event_trace_sha256=sha(run/'safe_chain_events.tsv'),roi_cycles=item['roi_cycles'],roi_instructions=item['roi_instret'],
   timebase='SVB intervals BOOM diagnostic cycle sampled at original event; checker intervals original checker-local CSR cycles. These timebases are never subtracted from each other.',
   original_allocation_count=len(lifecycle),original_terminal_counts=integrity['terminal_counts'],completed_intervals=len(complete),
   memory_management_intervals=intervals,checker_local_intervals={k:stats([r[k] for r in checker]) for k in ['admit_to_start','admit_to_exec_done','start_to_exec_done']},
   checker_packages=len(checker),strict_checker_minus_boom_completion_latency='NOT_AVAILABLE: no proven same-package BOOM execution-complete event in this extraction. Producer seal/admission are not substituted.',
   rollback_restart='NOT_MEASURED: no architectural completion event or forced complete restore in this ordinary no-fault run.',
   full_memory_payload_trace='NOT_AVAILABLE: SC32/37/38 contain identity/coverage/hash; hashes do not reconstruct original data words. Do not claim full payload replay or counterfactual cycle-exact execution from these events.')
 (L/(item['workload']+'.json')).write_text(json.dumps(out,indent=2)+'\n');reports.append(out)
(L/'summary.json').write_text(json.dumps({'classification':'ORIGINAL_RTL_EVENT_INTERVAL_ANALYSIS','results':reports},indent=2)+'\n')
print(json.dumps([dict(workload=r['workload'],complete_svb=r['completed_intervals'],svb_capture_completion_mean=r['memory_management_intervals']['svb_capture_to_terminal_completion'].get('mean'),checker_packages=r['checker_packages'],strict_latency=r['strict_checker_minus_boom_completion_latency']) for r in reports],indent=2))
