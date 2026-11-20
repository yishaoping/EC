"""Read-only attribution bounds from accepted first-round raw logs; no reruns."""
import sys
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parents[2]/'scripts'))
from common import *
import csv,gzip,re,collections
os.nice(19-os.getpriority(os.PRIO_PROCESS,0));os.sched_setaffinity(0,{200})
dest=Path(__file__).resolve().parent;s=read(ROOT/'paper/summary.json');rows=[];evidence=[]
labels=('PRESERVATION_WAIT ','PRESERVATION_BLOCKED ','WB_BLOCK ','FASTLINE_BLOCK_OTHER_LINE ','PROBE_BLOCKED ','LONG_STALL ')
for r in s['per_benchmark']:
 p=Path(r['ec_evidence']).parent;result=read(p/'result.json');begin,end=result['roi_start_csr'],result['roi_end_csr']
 counts=collections.Counter();examples={};reason_counts=collections.Counter()
 with gzip.open(p/'host-complete.log.gz','rt',errors='replace') as f:
  for line in f:
   if not line.startswith(labels):continue
   m=re.search(r'\bcycle=([0-9a-f]+)\b',line)
   if not m or not begin<=int(m[1],16)<end:continue
   kind=line.split()[0];counts[kind]+=1
   reason=re.search(r'\b(?:waiting_reason|reason)=(\S+)',line)
   if reason:reason_counts[kind+':'+reason[1]]+=1
   if kind not in examples:examples[kind]=line.strip()
 native,ec,inst=r['native_cycles'],r['ec_cycles'],r['instructions_native']
 svb=read(p/'svb-metrics.json');promote=(svb['roi_capture_stats'].get('promotion_to_ack') or {}).get('mean');life=r['svb_roi_mean_capture_to_ack']
 row=dict(benchmark=r['benchmark'],profile=r['profile'],native_cycles=native,ec_cycles=ec,extra_roi_cycles=ec-native,roi_instructions=inst,native_cpi=native/inst,ec_cpi=ec/inst,slowdown=ec/native,extra_cycles_per_instruction=(ec-native)/inst,roi_svb_capture_events=r['svb_roi_capture_count'],roi_svb_capture_events_per_1000_instructions=r['svb_roi_capture_count']/inst*1000,mean_completed_svb_capture_to_ack_cycles=life,mean_completed_svb_promotion_to_ack_cycles=promote,mean_completed_svb_capture_to_promotion_cycles=life-promote if life is not None and promote is not None else None,checker_acceptance_tail_excluded_from_primary_ratio=r['checker_acceptance_tail_boom_cycles'],checker_local_mean_checker_cycles=r['checker_local_mean_cycles'],checker_hz=100000000,boom_hz=200000000,**{k.lower()+'_roi_onset_events':counts[k] for k in [x.strip() for x in labels]})
 rows.append(row);evidence.append(dict(benchmark=r['benchmark'],run_dir=str(p),result_sha256=sha(p/'result.json'),raw_integrity=read(p/'stdout-integrity.json'),roi_begin=begin,roi_end=end,onset_reason_counts=dict(reason_counts),raw_examples=examples))
 print(r['benchmark'],'CPI',round(native/inst,3),'->',round(ec/inst,3),'ROI events',dict(counts),flush=True)
with (dest/'cpi-and-observed-waits.csv').open('w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=list(rows[0]));w.writeheader();w.writerows(rows)
save(dest/'evidence.json',dict(created_utc=now(),functional_baseline=BASE,summary_sha256=sha(ROOT/'paper/summary.json'),script_sha256=sha(__file__),rows=rows,evidence=evidence,causal_levels={'direct_symptom':'PROVEN: same retired-instruction counts require more target cycles; CPI increases','immediate_blocking':'PROVEN_FOR_LOGGED_EVENTS: retained-version preservation/writeback blocking onsets occur withinROI where counted; these are event counts, not blocking durations or BOOM retirement-stall cycles','upstream_trigger':'PARTIALLY_SUPPORTED: frozen EC executes checker/package/version-preservation machinery and shares cache/coherence resources; exact per-mechanism causal share is UNPROVEN without matched ablations or retirement-correlated counters','amplifier':'UNQUANTIFIED: short/reduced/changed/component scopes, lower Native CPI, distinct linked addresses/cache state can amplify ratio; no full-workload calibration'},limits=['No simulator or hardware launched; all evidence read from accepted frozen-run logs','Do not sum overlapping checker intervals or SVB lifetimes as slowdown overhead','Blocking onsets are not block cycles; lack ofLONG_STALL does not imply no short stalls','Shared objects and matching dynamic instruction count do not remove linked-layout/cache-state confounding','These declared reduced/component profiles do not establish complete PARSEC application slowdown']))
