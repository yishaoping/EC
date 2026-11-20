#!/usr/bin/python3
"""Fresh exact sealed target-level RTL replay; never an FPGA or Linux PARSEC result."""
import copy, datetime as dt, fcntl, hashlib, importlib.util, json, os, pathlib, re, shutil, sys, threading, time
P=pathlib.Path
D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
DOC=P('/data1/gzh/EC/slowdown/final_opt4_freeze_20261106')
ROOT=P('/data1/gzh/EC/slowdown/streamcluster_aggressive/variants/preservation_svb32_permission')
L=D/'cycleprecise-frozen-canneal-20261111'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
def sha(p):
 h=hashlib.sha256()
 with P(p).open('rb') as f:
  for b in iter(lambda:f.read(2**20),b''):h.update(b)
 return h.hexdigest()
def now():return dt.datetime.now(dt.timezone.utc).isoformat()
def save(p,d):
 p=P(p);q=p.with_name(p.name+'.tmp-'+str(threading.get_ident()))
 with q.open('w') as f:json.dump(d,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def main():
 L.mkdir(exist_ok=True);lock=(L/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 assert not (L/'run_manifest.json').exists(),'adopt existing completed or partial evidence; never repeat'
 source=next(x for x in json.loads((DOC/'data/FINAL_RUNS.json').read_text()) if x['workload']=='canneal_project400' and x['mode']=='correction')
 prior=P(source['manifest']['absolute_path']);assert sha(prior)==source['manifest']['sha256']
 old=json.loads(prior.read_text());assert old['canonical_hardware_commit']==BASE
 assert old['elf_sha256']==source['elf_sha256'] and old['simulator_sha256']==source['simulator_sha256']
 argv=old['command'];assert sha(argv[0])==old['simulator_sha256']
 recipe=json.loads((DOC/'data/BUILD_RECIPE.json').read_text());assert recipe['source']['git_head']==BASE and recipe['source']['n_svb_entries']==32
 verified={}
 for group in ['hardware_sha256','restored_resource_sha256']:
  for n,h in recipe['source'].get(group,{}).items():
   p=ROOT/n;assert sha(p)==h,(str(p),'source drift');verified[str(p)]=h
 for n in ['test.riscv','test.loadmem_hex']:
  shutil.copy2(prior.parent/n,L/n)
 assert sha(L/'test.riscv')==old['elf_sha256']
 argv=[('+loadmem='+str(L/'test.loadmem_hex')) if a.startswith('+loadmem=') else (str(L/'test.riscv') if a==old['command'][-1] else a) for a in argv]
 for n in ['roi_cycles','roi_instret','roi_start','roi_end','total_harness_cycles','exit_status','output','capture','software_correct','end_utc']:old.pop(n,None)
 old.update(run_id=L.name,command=argv,start_utc=now(),state='STARTED',validation='RUNNING_NOT_VALIDATED',
  evidence_origin='NEW_TARGET_LEVEL_VERILATOR_REPLAY_NOT_FPGA',original_run=str(prior.parent))
 save(L/'run_manifest.json',old)
 save(L/'binding.json',dict(functional_baseline=BASE,simulator=str(argv[0]),simulator_sha256=old['simulator_sha256'],
   elf_sha256=old['elf_sha256'],loadmem_sha256=sha(L/'test.loadmem_hex'),verified_source_files=verified,
   input='project400 bare-metal; not formal Linux simmedium',configuration='sealed v1Config C4 SVB32 report-permission repair',
   native_comparison_available=False,strict_checker_latency_not_inferred=True,architectural_rollback_not_validated=True))
 script=ROOT/'slowdown/parsec_evaluation_20261103/scripts';sys.path.insert(0,str(script));import run_pilot
 start=time.monotonic();stop=threading.Event()
 def heartbeat():
  while not stop.is_set():
   fields=P('/proc/self/stat').read_text().rsplit(')',1)[1].split()
   save(L/'state.json',dict(status='RUNNING_TARGET_RTL',pid=os.getpid(),start_ticks=fields[19],
    host_boot_id=P('/proc/sys/kernel/random/boot_id').read_text().strip(),
    children=P(f'/proc/self/task/{os.getpid()}/children').read_text().split(),elapsed_host_seconds=time.monotonic()-start,updated_utc=now()))
   stop.wait(300)
 thread=threading.Thread(target=heartbeat,daemon=True);thread.start()
 os.chdir(L)
 rc,capture=run_pilot.compact_capture.capture(argv,L);stop.set();thread.join()
 old.update(state='COMPLETED',exit_status=rc,capture=capture,host_wall_seconds=time.monotonic()-start,end_utc=now())
 logs='\n'.join((L/n).read_text(errors='replace') for n in ['stdout.log','stderr.log'])
 app=re.findall(r'\[APP\] protected=(\d+) start=(\d+) end=(\d+) cycles=(\d+) instret=(\d+) session_stop=(\d+)',logs)
 if len(app)==1:
  flag,start,end,cycles,inst,stop=map(int,app[0]);assert end-start==cycles
  old.update(modeflag=flag,roi_cycles=cycles,roi_instret=inst,roi_start=start,roi_end=end,software_session_stop=stop,ipc=inst/cycles)
  save(L/'roi.json',dict(start_cycle=start,stop_cycle=end,safe_chain_roi_cycles=cycles,scope=old['software']['roi_scope']))
 old['output']=re.findall(r'\[OUTPUT\] (.*)',logs);total=re.findall(r'\*\*\* PASSED \*\*\* Completed after (\d+) cycles',logs)
 if len(total)==1:old['total_harness_cycles']=int(total[0])
 old['software_correct']=rc==0 and len(app)==1 and old.get('modeflag')==1 and len(total)==1 and old['output']==source['authoritative_final_gate']['output'] and '[COMPUTATION] status=PASS' in logs and '[END] hart=0 status=PASS' in logs and not re.search(r'\bAssertion\b|%Error|\*\*\* FAILED|status=FAIL',logs,re.I)
 old['validation']='SOFTWARE_PASS_PROTOCOL_PENDING' if old['software_correct'] else 'FAILED';save(L/'run_manifest.json',old)
 import analyze_pilot
 report=analyze_pilot.analyze(L)
 result=dict(status=report['status'],kind='TARGET_LEVEL_RTL_NOT_FPGA_NOT_LINUX_FORMAL',functional_baseline=BASE,
   roi_cycles=old.get('roi_cycles'),roi_instructions=old.get('roi_instret'),host_wall_seconds=old['host_wall_seconds'],
   total_harness_cycles=old.get('total_harness_cycles'),output=old['output'],analysis=str(L/'analysis.json'),
   analysis_sha256=sha(L/'analysis.json'),errors=report['errors'],architectural_rollback='NOT_ESTABLISHED',strict_latency='NOT_INFERRED')
 save(L/'result.json',result)
 if report['status']=='PASS':save(L/'complete.json',dict(result_sha256=sha(L/'result.json'),binding_sha256=sha(L/'binding.json'),run_manifest_sha256=sha(L/'run_manifest.json')))
 save(L/'state.json',dict(status='COMPLETE_VALIDATED' if report['status']=='PASS' else 'FAILED_WITH_EVIDENCE',updated_utc=now(),result=str(L/'result.json')))
 if report['status']!='PASS':raise RuntimeError(report['errors'])
if __name__=='__main__':main()
