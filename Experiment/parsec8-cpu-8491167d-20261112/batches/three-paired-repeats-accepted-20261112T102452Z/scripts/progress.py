"""Observe only this experiment's runs; partial counters are diagnostics."""
from common import *
import re
os.nice(19-os.getpriority(os.PRIO_PROCESS,0));os.sched_setaffinity(0,{200})
records=[]
for item,mode,repeat in [(x,mode,repeat) for x in read(ROOT/'queue.json')['items'] for mode in ['native','ec'] for repeat in range(1,4)]:
  m=read(ROOT/item['manifest'])
  r,p=selected_result(m,mode,repeat)
  paths=run_paths(m,mode,repeat)
  active=[]
  for out in paths:
   if not (out/'state.json').exists():continue
   s=read(out/'state.json');c=s.get('child')
   if s.get('status')!='RUNNING' or not c or ident(c['pid'])!=c:continue
   cmd=Path(f"/proc/{c['pid']}/cmdline").read_text()
   if str(out) not in cmd:continue
   status=Path(f"/proc/{c['pid']}/status").read_text()
   rss=re.search(r'^VmRSS:\s*(\d+)',status,re.M)
   cycles=None;source=None;filename=out/('host-summary.log' if mode=='ec' else 'roi-raw.jsonl')
   if filename.exists():
    with filename.open('rb') as f:
     f.seek(max(0,filename.stat().st_size-131072));tail=f.read().decode(errors='replace')
    if mode=='native':
     counters=re.findall(r'"source_boom_tick":(\d+)',tail)
     if counters:cycles=int(counters[-1]);source='diagnostic native BOOM tick snapshot'
    else:
     counters=re.findall(r'\bcycle=([0-9a-f]+)',tail)
     if counters:cycles=int(counters[-1],16);source='last printed BOOM CSR diagnostic event'
   fastest=None;heartbeat=out/'heartbeat.csv'
   if heartbeat.exists():
    with heartbeat.open('rb') as f:
     f.seek(max(0,heartbeat.stat().st_size-4096));lastbeats=f.read().decode(errors='replace').splitlines()
    beats=[line.split(',')[0].strip() for line in lastbeats if line.split(',')[0].strip().isdigit()]
    if beats:fastest=int(beats[-1])
   active.append(dict(identity=c,run_dir=str(out),resident_kib=int(rss[1]) if rss else None,cpu_affinity=sorted(os.sched_getaffinity(c['pid'])),nice=os.getpriority(os.PRIO_PROCESS,c['pid']),host_seconds=s.get('host_seconds'),pressure_paused=s.get('paused_for_pressure',False),pressure_paused_seconds=s.get('pressure_paused_seconds',0),partial_cycle=cycles,partial_cycle_source=source,last_heartbeat_fastest_target_cycle=fastest,heartbeat_is_roi_measurement=False,partial_is_performance_result=False,raw_bytes=s.get('raw_bytes')))
  records.append(dict(benchmark=m['benchmark'],profile=m['profile'],mode=mode,repeat=repeat,status='RUNNING' if active else (r or {}).get('status','PENDING'),roi_cycles=(r or {}).get('roi_cycles'),roi_instructions=(r or {}).get('roi_instructions'),active=active,result=str(p) if r else None))
j=dict(created_utc=now(),functional_baseline=BASE,running_simulator_count=sum(len(r['active']) for r in records),resident_kib=sum(a['resident_kib'] or 0 for r in records for a in r['active']),records=records,notes=['Partial diagnostic cycles demonstrate progress only; no ratio or ROI estimate is inferred','Only this independent directory and recorded process identities are inspected'])
save(ROOT/'audit/progress.json',j)
with (ROOT/'audit/progress-history.jsonl').open('a') as f:f.write(json.dumps(j,separators=(',',':'))+'\n')
print(json.dumps({'time':j['created_utc'],'active':[dict(benchmark=r['benchmark'],mode=r['mode'],**a) for r in records for a in r['active']]},indent=2))
