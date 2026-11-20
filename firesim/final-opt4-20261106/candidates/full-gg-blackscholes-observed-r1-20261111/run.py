#!/usr/bin/python3
"""Full frozen Blackscholes GG runtime, complete gzip logs, strict event join."""
from pathlib import Path
import collections,datetime,fcntl,gzip,hashlib,importlib.util,json,os,re,resource,selectors,shutil,signal,subprocess,sys,time,traceback
C=Path(__file__).resolve().parent;W=C.parents[1]
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');U=D/'unattended-opt4'
O=D/'cycleprecise-frozen-full-gg-blackscholes-observed-r1-20261111'
STATE=D/'Opt4-full-gg-blackscholes-observed-r1-state.json'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
def read(p):return json.loads(Path(p).read_text())
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for b in iter(lambda:f.read(4*2**20),b''):h.update(b)
 return h.hexdigest()
def save(p,v):
 tmp=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with tmp.open('x') as f:json.dump(v,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(tmp,p)
 fd=os.open(p.parent,os.O_RDONLY|os.O_DIRECTORY);os.fsync(fd);os.close(fd)
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def ident(pid):
 return dict(pid=pid,start_ticks=Path('/proc',str(pid),'stat').read_text().rsplit(')',1)[1].split()[19],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
def state(status,**v):save(STATE,dict(status=status,**ident(os.getpid()),fpga_access=False,updated_utc=now(),**v))
def main():
 assert not O.exists(),'ADOPT_EXISTING_ATTEMPT_NO_DUPLICATE_OR_OVERWRITE'
 O.mkdir();lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 plan=read(C/'plan.json');policy=read(U/'campaign-policy.json')
 assert policy['functional_baseline_commit']==plan['functional_baseline']==BASE and policy['area_equivalence_only'] and policy['native_paused'] and not policy['fpga_access']
 assert policy['board_allowlist']==['0000:21:00.0']
 for p,h in plan['external_inputs'].items():assert sha(p)==h,('CHANGED_ORIGINAL_INPUT',p)
 assert sha(plan['elf'])==plan['elf_sha256'] and sha(plan['binary'])==plan['binary_sha256']
 os.sched_setaffinity(0,sorted(os.sched_getaffinity(0))[:2]);resource.setrlimit(resource.RLIMIT_AS,(24*2**30,)*2)
 assert shutil.disk_usage(O).free>=12*2**30
 assert not any('blackscholes' in json.dumps(read(p)).lower() for p in (U/'jobs').glob('*/spec.json') if read(p).get('name')!='full-gg-blackscholes-observed-r1-8491167d'),'OTHER_EXISTING_BLACKSCHOLES_JOB_ADOPT_REQUIRED'
 args=list(plan['base_args']);i=args.index('+permissive-off');args.insert(i,'+print-file='+str(O/'rtl-prints-'));args+=['+prog0='+plan['elf']]
 env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'1','EC_EXTERNAL_OBSERVER_FILE':str(O/'external-events.jsonl')}
 save(O/'binding.json',dict(functional_baseline=BASE,source_id=plan['source_id'],plan_sha256=sha(C/'plan.json'),binary=plan['binary'],binary_sha256=plan['binary_sha256'],elf=plan['elf'],elf_sha256=plan['elf_sha256'],args=args,observer_enabled=True,fpga_access=False,model_or_rtl_changed=False,scope=plan['scope']))
 rawhash=hashlib.sha256();rawbytes=0;tail=b'';buffer=b'';faults=[];app=[];last_flush=time.monotonic();started=time.monotonic();cause=None;fmr=None;target=None
 compact=(O/'host-summary.log').open('xb',buffering=0)
 backing=(O/'host-complete.log.gz').open('xb',buffering=0)
 compressed=gzip.GzipFile(filename='',mode='wb',compresslevel=1,fileobj=backing,mtime=0)
 proc=subprocess.Popen(['/usr/bin/stdbuf','-oL','-eL',*args],cwd=O,stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,env=env,start_new_session=True)
 assert proc.stdout is not None
 select=selectors.DefaultSelector();select.register(proc.stdout,selectors.EVENT_READ)
 child=ident(proc.pid);state('RUNNING_FULL_BLACKSCHOLES_GG_METASIM',child=child,run_directory=str(O),host_timeout_seconds=plan['host_timeout_seconds'],target_cycle_limit=plan['target_cycle_limit'])
 try:
  while select.get_map():
   for key,mask in select.select(timeout=1):
    data=os.read(key.fileobj.fileno(),256*1024)
    if not data:select.unregister(key.fileobj);continue
    rawhash.update(data);rawbytes+=len(data);compressed.write(data);tail=(tail+data)[-16384:];buffer+=data
    lines=buffer.split(b'\n');buffer=lines.pop()
    for line in lines:
     line+=b'\n';text=line.decode(errors='replace').rstrip('\r\n')
     # Omit only from compact secondary log; every byte remains in complete gzip.
     if not re.match(rb'^C[1-4]:',line):compact.write(line)
     if any(k in text for k in ['[ROI]','[OUTPUT]','[APP]','[COMPUTATION]','[END]']):app.append(text)
     if re.search(r'Assertion failed|%Error|status=FAIL|Simulator deadlock detected|\*\*\* FAILED',text):faults.append(text[:4096])
     m=re.search(r'Target Cycles Emulated:\s*(\d+)',text)
     if m:target=int(m[1])
     m=re.match(r'FMR:\s*([0-9.]+)',text)
     if m:fmr=float(m[1])
   if time.monotonic()-last_flush>=30:
    compressed.flush();os.fsync(backing.fileno());os.fsync(compact.fileno())
    hb=O/'heartbeat.csv';heartbeat=hb.read_text().splitlines()[-1] if hb.exists() else None
    owned=sum(p.stat().st_size for p in O.iterdir() if p.is_file())
    state('RUNNING_FULL_BLACKSCHOLES_GG_METASIM',child=child,host_wall_seconds=time.monotonic()-started,heartbeat_last_row=heartbeat,raw_stdout_bytes=rawbytes,compressed_stdout_bytes=backing.tell(),owned_output_bytes=owned)
    last_flush=time.monotonic()
    if owned>plan['owned_output_limit_bytes']:cause='OWNED_OUTPUT_LIMIT'
    if time.monotonic()-started>plan['host_timeout_seconds']:cause='HOST_TIMEOUT'
    if cause and proc.poll() is None:
     os.killpg(proc.pid,signal.SIGTERM)
     try:proc.wait(timeout=15)
     except subprocess.TimeoutExpired:os.killpg(proc.pid,signal.SIGKILL);proc.wait()
  rc=proc.wait()
 finally:
  if buffer:compact.write(buffer)
  compressed.close();os.fsync(backing.fileno());backing.close();os.fsync(compact.fileno());compact.close();select.close()
 elapsed=time.monotonic()-started
 save(O/'stdout-integrity.json',dict(raw_sha256=rawhash.hexdigest(),raw_bytes=rawbytes,gzip_sha256=sha(O/'host-complete.log.gz'),gzip_bytes=(O/'host-complete.log.gz').stat().st_size,complete_stream_eof=True,compression='gzip level1 lossless complete stdout+stderr, no line removed',fpga_access=False))
 # Runtime result first: incomplete application/protocol is never marked passed.
 roi=next((re.search(r'hart=0 start=(\d+) stop=(\d+) cycles=(\d+)',s) for s in app if s.startswith('[ROI]')),None)
 ap=next((re.search(r'protected=(\d+) start=(\d+) end=(\d+) cycles=(\d+) instret=(\d+) session_stop=(\d+)',s) for s in app if s.startswith('[APP]')),None)
 outputs=[s.split('[OUTPUT] ',1)[1] for s in app if '[OUTPUT] ' in s]
 software=rc==0 and cause is None and not faults and roi is not None and ap is not None and outputs==plan['expected_output'] and '[COMPUTATION] status=PASS scope=official_serial_kernel' in app and '[END] hart=0 status=PASS' in app
 strict=None;acceptance_error=None
 if software:
  try:
   spec=importlib.util.spec_from_file_location('strict_checker_join',C.with_name('full-gg-acceptance-strict-r1-20261111')/'analyze.py');mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
   strict=mod.analyze(O);save(O/'strict-acceptance.json',strict)
  except BaseException as error:acceptance_error=repr(error)
 valid=software and strict is not None and strict['passed']
 results=dict(schema='ec-full-frozen-gg-blackscholes-result/1',status='PASS_COMPLETE_APPLICATION_AND_STRICT_CHECKER_DRAIN' if valid else 'FAILED_OR_PROTOCOL_UNPROVEN_WITH_EVIDENCE',valid=valid,fpga_access=False,formal_fpga_sample=False,functional_baseline=BASE,source_id=plan['source_id'],benchmark=plan['benchmark'],input=plan['input'],elf_sha256=plan['elf_sha256'],binary_sha256=plan['binary_sha256'],returncode=rc,stop_cause=cause,host_wall_seconds=elapsed,total_fastest_target_cycles=target,host_simulator_FMR=fmr,simulation_target_cycles_per_host_second=target/elapsed if target else None,application_rows=app,output=outputs,software_correct=software,faults=faults,strict_acceptance=strict,strict_acceptance_error=acceptance_error,plan_sha256=sha(C/'plan.json'),binding_sha256=sha(O/'binding.json'),stdout_integrity_sha256=sha(O/'stdout-integrity.json'),scope=plan['scope'],completed_utc=now(),limitations=['Finite simulation result, not FPGA measurement or universal RTL equivalence','Allocation-to-result acceptance not strict checkerDone minus BOOMexecutionDone','No fullSVBbinarycapture here; no architecturalrollback/restartclaim','FASED30/max4 vs plain+dramsim differs; no cycleequivalenceclaim'])
 if roi and ap:
  rs,re_,cy=map(int,roi.groups());prot,aps,ape,apc,inst,session=map(int,ap.groups());assert re_-rs==cy and (aps,ape,apc)==(rs,re_,cy) and prot==1
  results.update(roi_start_csr=rs,roi_end_csr=re_,roi_cycles=cy,roi_instructions=inst,software_session_stop=session,plain_target_reference=plan['plain_target_reference'])
 if valid:
  events=[json.loads(l) for l in (O/'external-events.jsonl').read_text().splitlines()];accepted=[e for e in events if e['kind']=='BOOM_RESULT_ACCEPTED'];last=max(accepted,key=lambda e:e['boom_csr_cycle'])
  results.update(last_boom_accepted_result=last,checker_result_acceptance_tail_after_roi_csr_cycles=max(0,last['boom_csr_cycle']-results['roi_end_csr']),pending_at_roi_stop=sum(e['boom_csr_cycle']>=results['roi_end_csr'] for e in accepted),pending_at_observation_end=0)
 save(O/'result.json',results)
 if valid:save(O/'complete.json',dict(result_sha256=sha(O/'result.json'),binding_sha256=sha(O/'binding.json'),stdout_integrity_sha256=sha(O/'stdout-integrity.json'),strict_acceptance_sha256=sha(O/'strict-acceptance.json'),plan_sha256=sha(C/'plan.json'),elf_sha256=plan['elf_sha256'],fpga_access=False))
 state(results['status'],child={},result=str(O/'result.json'),host_wall_seconds=elapsed)
 assert valid,'BLACKSCHOLES_APPLICATION_OR_STRICT_PROTOCOL_FAILED'
if __name__=='__main__':
 try:main()
 except BaseException as error:
  if O.exists():save(O/('failure-'+str(os.getpid())+'.json'),dict(error=repr(error),traceback=traceback.format_exc(),utc=now(),fpga_access=False))
  state('FAILED_WITH_EVIDENCE',error=repr(error));raise
