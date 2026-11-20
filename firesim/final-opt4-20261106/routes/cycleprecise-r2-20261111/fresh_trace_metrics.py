#!/usr/bin/python3
"""Supported intervals from the newly completed, version-bound Canneal run."""
import collections, importlib.util, json, math, pathlib, statistics
P=pathlib.Path;C=P(__file__).resolve().parent
sp=importlib.util.spec_from_file_location('proto',C/'run.py');m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
R=m.D/'cycleprecise-frozen-canneal-20261111'
def stats(v):
 v=sorted(v);n=len(v)
 return dict(n=n,sum=sum(v),mean=statistics.mean(v),median=statistics.median(v),maximum=v[-1],p95=v[math.ceil(.95*n)-1],p99=v[math.ceil(.99*n)-1],
  histogram=dict(sorted(collections.Counter(v).items())),resolution='exact integer cycles',percentiles='nearest rank')
def main():
 c=m.read(R/'complete.json')
 for name,k in [('binding.json','binding_sha256'),('result.json','result_sha256'),('run_manifest.json','run_manifest_sha256')]:assert m.sha(R/name)==c[k]
 r=m.read(R/'result.json');a=m.read(R/'analysis.json')
 assert r['status']=='PASS' and not r['errors'] and r['analysis_sha256']==m.sha(R/'analysis.json')
 assert a['packages']['PASS']==136 and a['protocol']['outstanding_at_end']==0
 root=P('/data1/gzh/EC/slowdown/streamcluster_aggressive/variants/preservation_svb32_permission')
 p=root/'slowdown/optimization_4_svb/analysis/analyze_svb.py'
 s=importlib.util.spec_from_file_location('fresh_svb',p);v=importlib.util.module_from_spec(s);s.loader.exec_module(v)
 events=R/'safe_chain_events.tsv';records=v.parse_events(events)
 ledger=v.integrity_ledger.build(records);assert ledger['status']=='PASS' and not ledger['errors']
 complete=[x for x in ledger['lifecycles'] if x['terminal_reason']=='PROMOTED_COMPLETED']
 intervals={}
 for label,begin,end in [('capture_to_completion','capture_cycle','completion_cycle'),('safe_to_promotion','safe_cycle','promotion_cycle'),('promotion_to_ack','promotion_cycle','ack_cycle'),('ack_to_completion','ack_cycle','completion_cycle')]:
  assert all(x[begin] is not None and x[end] is not None and x[end]>=x[begin] for x in complete)
  intervals[label]=stats([x[end]-x[begin] for x in complete])
 out=dict(kind='NEW_COMPLETED_FULL_TARGET_RTL_REAL_EVENT_ANALYSIS_NOT_FPGA',functional_baseline=m.BASE,
  result_sha256=m.sha(R/'result.json'),analysis_sha256=m.sha(R/'analysis.json'),events_sha256=m.sha(events),
  parser_sha256=m.sha(p),svb_timebase='BOOM diagnostic cycles',svb_intervals=intervals,
  roi_cycles=r['roi_cycles'],roi_instructions=r['roi_instructions'],roi_work_drain_cycles=a['packages']['ROI_work_drain_tail_cycles'],
  roi_start_to_verified_cycles=a['packages']['ROI_work_start_to_verified_cycles'],package_results=a['packages'],
  checker_work=a['full_session_checker_work'],host_wall_seconds=r['host_wall_seconds'],
  harness_cycles_per_second=r['total_harness_cycles']/r['host_wall_seconds'],
  strict_checker_minus_boom_done_latency='UNAVAILABLE: no proven matched BOOM execution-complete event; do not substitute seal, admission or package begin',
  architectural_rollback_restart='NOT_MEASURED',full_payload_trace='NOT_AVAILABLE: event hashes cannot reconstruct data')
 f=R/'fresh-event-intervals.json'
 if f.exists():assert m.read(f)==out
 else:m.save(f,out)
 print(json.dumps({k:v for k,v in out.items() if k not in ['svb_intervals','package_results','checker_work']},indent=2))
if __name__=='__main__':main()
