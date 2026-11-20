"""Independent raw-stream verification for completed selected runs."""
from common import *
import gzip,csv,re,collections
os.nice(19-os.getpriority(os.PRIO_PROCESS,0));os.sched_setaffinity(0,{200})
rows=[]
for item in read(ROOT/'queue.json')['items']:
 mp=ROOT/item['manifest']
 if not mp.exists():continue
 mf=read(mp)
 for mode in ['native','ec']:
  for p in [p for repeat in range(1,4) for p in run_paths(mf,mode,repeat)]:
   if not (p/'complete.json').exists():continue
   r=read(p/'result.json');receipt=read(p/'stdout-integrity.json');completion=read(p/'complete.json');binding=read(p/'binding.json')
   strict_evidence=(r.get('strict_acceptance') or {}).get('evidence',{})
   current_strict_evidence={name:sha(name) if Path(name).is_file() else None for name in strict_evidence}
   fingerprint=dict(result=sha(p/'result.json'),integrity=sha(p/'stdout-integrity.json'),completion=sha(p/'complete.json'),binding=sha(p/'binding.json'),manifest=sha(mp),binary=sha(binding['args'][0]),elf=sha(binding['elf']['path']),gzip_sha256=sha(p/'host-complete.log.gz'),strict_evidence=current_strict_evidence,script=sha(__file__))
   cached=read(p/'raw-audit.json') if (p/'raw-audit.json').exists() else {}
   if cached.get('fingerprint')==fingerprint and cached.get('passed'):
    rows.append(cached);continue
   digest=hashlib.sha256();size=0;svb=collections.Counter();svb_examples=[];markers=[]
   with gzip.open(p/'host-complete.log.gz','rb') as f:
    for line in f:
     digest.update(line);size+=len(line)
     if line.startswith((b'[ROI]',b'[APP]',b'[IRQ]',b'[OUTPUT]',b'[END]')):markers.append(line.decode(errors='replace').strip())
     if b'SVB' in line:
      tag=line.decode(errors='replace').split()[0];svb[tag]+=1
      if len(svb_examples)<6:svb_examples.append(line.decode(errors='replace').strip())
   checks=dict(functional_baseline=r.get('functional_baseline')==binding.get('functional_baseline')==BASE,model_binary=sha(binding['args'][0])==binding['binary_sha256'],raw_sha256=digest.hexdigest()==receipt['raw_sha256']==r['raw_log_sha256'],raw_bytes=size==receipt['raw_bytes'],gzip_sha256=sha(p/'host-complete.log.gz')==receipt['gzip_sha256'],complete_result_hash=sha(p/'result.json')==completion['result_sha256'],complete_binding_hash=sha(p/'binding.json')==completion['binding_sha256'],bound_manifest=sha(mp)==binding['manifest_sha256']==r['manifest_sha256'],bound_elf=sha(binding['elf']['path'])==binding['elf']['sha256'])
   parsed={tag:[s for s in markers if s.startswith(tag)] for tag in ['[ROI]','[APP]','[IRQ]','[OUTPUT]','[END]']}
   checks['unique_roi_app_irq_markers']=all(len(parsed[tag])==1 for tag in ['[ROI]','[APP]','[IRQ]'])
   roi=re.search(r'start=(\d+) stop=(\d+) cycles=(\d+)',parsed['[ROI]'][0]) if len(parsed['[ROI]'])==1 else None
   app=re.search(r'start=(\d+) end=(\d+) cycles=(\d+) instret=(\d+)',parsed['[APP]'][0]) if len(parsed['[APP]'])==1 else None
   irq=re.search(r'before=(\d+) after=(\d+) mie=(\d+)',parsed['[IRQ]'][0]) if len(parsed['[IRQ]'])==1 else None
   checks['raw_roi_csr_and_cycles']=bool(roi and tuple(map(int,roi.groups()))==(r['roi_start_csr'],r['roi_end_csr'],r['roi_cycles']) and r['roi_end_csr']-r['roi_start_csr']==r['roi_cycles'])
   checks['raw_app_cycles_and_instructions']=bool(app and tuple(map(int,app.groups()))==(r['roi_start_csr'],r['roi_end_csr'],r['roi_cycles'],r['roi_instructions']))
   checks['raw_timer_policy']=bool(irq and irq[1]==irq[2] and int(irq[3])&128==0 and r.get('interrupt_policy_verified'))
   checks['raw_output_and_end']=([s[len('[OUTPUT] '):] for s in parsed['[OUTPUT]']]==r['output'] and parsed['[END]']==['[END] hart=0 status=PASS'])
   checks['strict_event_evidence_hashes']=mode=='native' or bool(strict_evidence and current_strict_evidence==strict_evidence and r['strict_acceptance']['passed'])
   checks['completion_integrity_receipt_hash']=sha(p/'stdout-integrity.json')==completion['stdout_integrity_sha256']
   rows.append(dict(benchmark=mf['benchmark'],mode=mode,passed=all(checks.values()),checks=checks,raw_bytes=size,result=str(p/'result.json'),result_sha256=sha(p/'result.json'),svb_printed_records=dict(svb),svb_examples=svb_examples,fingerprint=fingerprint,svb_lifecycle_evidence=str(p/'svb-metrics.json') if (p/'svb-metrics.json').exists() else None,svb_limitation='Raw audit counts labels only; per-key lifecycle analysis is separate'))
   save(p/'raw-audit.json',rows[-1])
   print(mf['benchmark'],mode,p.name,all(checks.values()),size,dict(svb),flush=True)
save(ROOT/'audit/completed-raw-audit.json',dict(created_utc=now(),all_verified=bool(rows) and all(x['passed'] for x in rows),runs=rows))
