"""Join logged SVB capture, promotion and matching completion events by real key."""
from common import *
import gzip,re,csv,statistics
os.nice(19-os.getpriority(os.PRIO_PROCESS,0));os.sched_setaffinity(0,{200})
source=D/'cycleprecise-frozen-full-metasim-r1-20261111/host/FireSim-generated.sv'
code=source.read_text()
assert 'SVB_ENTRY_ALLOC cycle=%x' in code and 'SVB_COMPLETION cycle=%x' in code
# Source definitions and generated target port tie establish all printed event cycles
# as the same BOOM CSR diagnostic cycle, separate from fastest host clocks.
rows=[]
targets=[]
for item in read(ROOT/'queue.json')['items']:
 mp=ROOT/item['manifest']
 if not mp.exists():continue
 mf=read(mp)
 for repeat in range(1,4):
  result,rp=selected_result(mf,'ec',repeat)
  targets.append((mf,result,rp))
for mf,result,rp in targets:
 if not result or not result.get('valid'):continue
 out=rp.parent
 if not (out/'complete.json').exists():continue
 fingerprint=dict(raw_integrity=sha(out/'stdout-integrity.json'),source=sha(source),script=sha(__file__))
 cache=read(out/'svb-metrics.json') if (out/'svb-metrics.json').exists() else {}
 if cache.get('fingerprint')==fingerprint:
  rows.append(cache['paper_row']);continue
 dest=out/'svb-lifetimes.csv';live={};events={};lifetimes=[];errors=[];superseded=0;roi_allocs=0;roi_superseded=0
 begin=result['roi_start_csr'];end=result['roi_end_csr']
 with gzip.open(out/'host-complete.log.gz','rt',errors='replace') as f:
  for line in f:
   if not line.startswith(('SVB_ENTRY_ALLOC ','SVB_PROMOTION_SELECT ','SVB_COMPLETION ','SVB_SAFE ','SVB_C_FIRE ')):continue
   name=line.split()[0];events[name]=events.get(name,0)+1
   kv=dict(re.findall(r'(\w+)=([0-9a-f]+)(?=\s|$)',line))
   if not all(k in kv for k in ['cycle','entry','line','seq','generation']):errors.append('MISSING_FIELDS:'+line.strip());continue
   v={k:int(kv[k],16) for k in kv};key=tuple(v[k] for k in ['entry','line','seq','generation'])
   if name=='SVB_ENTRY_ALLOC':
    if begin<=v['cycle']<end:roi_allocs+=1
    if v['entry'] in live:
     superseded+=1
     if begin<=live[v['entry']]['capture']<end:roi_superseded+=1
    live[v['entry']]=dict(key=key,capture=v['cycle'],select=None,first_c=None,last_c=None,completion=None)
   elif name in ['SVB_PROMOTION_SELECT','SVB_C_FIRE','SVB_COMPLETION']:
    rec=live.get(v['entry'])
    if rec is None or rec['key']!=key:errors.append('UNMATCHED_'+name+':'+str(key));continue
    if name=='SVB_PROMOTION_SELECT':
     if rec['select'] is not None:errors.append('DUPLICATE_SELECT')
     rec['select']=v['cycle']
    elif name=='SVB_C_FIRE':
     if v.get('first'):rec['first_c']=v['cycle']
     if v.get('last'):rec['last_c']=v['cycle']
    else:
     rec['completion']=v['cycle'];del live[v['entry']]
     if any(rec[k] is None for k in ['select','first_c','last_c']):errors.append('MISSING_ENDPOINT:'+str(key));continue
     if not rec['capture']<=rec['select']<=rec['first_c']<=rec['last_c']<=rec['completion']:errors.append('OUT_OF_ORDER:'+str(key));continue
     lifetimes.append(dict(benchmark=mf['benchmark'],entry=key[0],line=hex(key[1]),seq=key[2],generation=key[3],capture_in_roi=begin<=rec['capture']<end,**{k:rec[k] for k in ['capture','select','first_c','last_c','completion']},capture_to_ack=rec['completion']-rec['capture'],promotion_to_ack=rec['completion']-rec['select'],last_c_to_ack=rec['completion']-rec['last_c']))
 with dest.open('w',newline='') as f:
  cols=list(lifetimes[0]) if lifetimes else ['benchmark'];w=csv.DictWriter(f,fieldnames=cols);w.writeheader();w.writerows(lifetimes)
 roi_lifetimes=[x for x in lifetimes if x['capture_in_roi']]
 def stats(k,population=None):
  v=sorted(x[k] for x in (lifetimes if population is None else population))
  return dict(n=len(v),minimum=min(v),mean=statistics.mean(v),median=statistics.median(v),p95=v[max(0,(len(v)*95+99)//100-1)],maximum=max(v)) if v else None
 j=dict(benchmark=mf['benchmark'],timebase='BOOM CSR cycle supplied as io_diagnosticCycle; all endpoints from same generated target logs',method='Observed full-key capture/select/C-first/C-last/matching-ACK event join',event_counts=events,complete_matched_lifetimes=len(lifetimes),unmatched_current_entries=len(live),superseded_entry_reallocations=superseded,errors=errors,passed=not errors,stats={k:stats(k) for k in ['capture_to_ack','promotion_to_ack','last_c_to_ack']},source_generated_rtl=str(source),source_generated_rtl_sha256=sha(source),raw_log_sha256=read(out/'stdout-integrity.json')['raw_sha256'],lifetime_csv=str(dest),lifetime_csv_sha256=sha(dest),limitations=['Per-key matched completed lifetimes only, including pre/post ROI checker software traffic','Reallocated uncompleted entries may have been safely coalesced; absent coalescing event is not fabricated','No payload comparison inferred from these labels; not strict checker detection or rollback latency'])
 j.update(roi_start_csr=begin,roi_end_csr=end,roi_capture_count=roi_allocs,roi_complete_matched_lifetimes=len(roi_lifetimes),roi_superseded_entries=roi_superseded,roi_unmatched_current_entries=sum(begin<=v['capture']<end for v in live.values()),roi_capture_stats={k:stats(k,roi_lifetimes) for k in ['capture_to_ack','promotion_to_ack','last_c_to_ack']},roi_capture_matched_ack_tail=max(0,max(x['completion'] for x in roi_lifetimes)-end) if roi_lifetimes else None,roi_tail_limitation='Last matching ACK among captured-and-completed ROI keys only; missing/coalesced keys and payload validation preclude inferring architectural or full SVB drain')
 rows.append(dict(benchmark=mf['benchmark'],profile=mf['profile'],repeat=result['repeat'],complete_matched_lifetimes=len(lifetimes),pending_entries=len(live),superseded_entry_reallocations=superseded,errors=len(errors),mean_capture_to_ack=stats('capture_to_ack')['mean'] if lifetimes else None,mean_promotion_to_ack=stats('promotion_to_ack')['mean'] if lifetimes else None,roi_capture_count=roi_allocs,roi_complete_matched_lifetimes=len(roi_lifetimes),roi_superseded_entries=roi_superseded,roi_mean_capture_to_ack=stats('capture_to_ack',roi_lifetimes)['mean'] if roi_lifetimes else None,roi_matched_ack_tail=j['roi_capture_matched_ack_tail'],evidence=str(out/'svb-metrics.json')))
 j.update(fingerprint=fingerprint,paper_row=rows[-1]);save(out/'svb-metrics.json',j)
 print(mf['benchmark'],len(lifetimes),'errors',len(errors),'pending',len(live),'superseded',superseded,flush=True)
if rows:
 for filename,population in [('svb-metrics.csv',[r for r in rows if r['repeat']==1]),('svb-metrics-repeats.csv',rows)]:
  with (ROOT/'paper'/filename).open('w',newline='') as f:
   w=csv.DictWriter(f,fieldnames=list(rows[0]));w.writeheader();w.writerows(population)
