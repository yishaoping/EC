#!/usr/bin/python3
"""EC-only, official simmedium, one attempt each. No FPGA or Native operations."""
from pathlib import Path
import argparse,csv,datetime,fcntl,gzip,hashlib,json,os,re,resource,selectors,signal,subprocess,sys,time,traceback,shutil
ROOT=Path(__file__).resolve().parent
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
OTHER=ROOT.parent/'parsec8-cpu-8491167d-20261112'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
MODEL=W/'candidates/full-gg-external-observer-r2-20261111/VFrozenOpt4Observed'
MODEL_SHA='cc2993bd8c6f56893afd9e73cc358684c07c481a52ef8eb50dc7a136134b2867'
BENCH=['blackscholes','fluidanimate','bodytrack','freqmine','swaptions','ferret','dedup','streamcluster']
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def read(p):return json.loads(Path(p).read_text())
def save(p,x):
 p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);tmp=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with tmp.open('w') as f:json.dump(x,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 tmp.replace(p)
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for b in iter(lambda:f.read(2**20),b''):h.update(b)
 return h.hexdigest()
def ident(pid):
 try:return dict(pid=pid,start_ticks=Path(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split()[19],boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def prepare():
 assert not (ROOT/'inputs.json').exists(),'adopt existing inputs, never overwrite'
 assert sha(MODEL)==MODEL_SHA
 binding=D/'cycleprecise-frozen-full-metasim-r1-20261111/binding.json';b=read(binding)
 assert b['functional_baseline']==BASE
 mem=read(W/'runtime/fased-common/manifest.json')
 header=Path(b['command'][b['command'].index('GEN_FILE_BASENAME=FireSim-generated')-1].split('=',1)[1])/'FireSim-generated.const.h'
 nprints=header.read_text().count('new synthesized_prints_t(');assert nprints==2
 plan=read(D/'suite-execution-plan.json');profiles={r['program']:r['software_profile_prefix'] for r in plan['programs']}
 historical=list(csv.DictReader((ROOT.parent/'parsec8-performance-audit-r2-20261112/historical-native-fpga.csv').open()))
 files={str(p):sha(p) for p in [Path(__file__),MODEL,binding,header,W/'runtime/fased-common/manifest.json']}
 contracts=[]
 for bench in BENCH:
  try:
   profile=profiles[bench];ap=W/f'software/{profile}-apps-build.json';rp=W/f'software/{profile}-rootfs-build.json';fp=W/f'software/C4/{profile}-firmware-build.json'
   a,r,f=map(read,[ap,rp,fp]);case=next(c for c in a['cases'] if c['program']==bench and c['input']=='simmedium')
   assert case['threads']==1 and a.get('formal_eligible',True) and not f.get('diagnostic_only')
   assert r['apps_manifest_sha256']==sha(ap) and sha(r['path'])==r['sha256']
   app=a['binaries'][bench];assert sha(app['path'])==app['sha256']
   elf=Path(f['output_dir'])/'platform/generic/firmware/fw_payload.elf';assert sha(elf)==f['outputs'][str(elf)]
   kp=next(Path(p) for p in f['input_files'] if p.endswith('.json') and 'kernel' in Path(p).name)
   kernel=read(kp);assert kernel['input_files'].get(r['path'])==r['sha256']
   fdpath=Path(f['content_checks']['fdt']['path']);assert sha(fdpath)==f['content_checks']['fdt']['sha256']
   fd=read(fdpath.parent/'manifest.json');assert fd['sha256']==sha(fdpath) and fd['linux_mem_cap']==2**31
   assert fd['target_boom_hz']==200000000 and fd['target_checker_hz']==100000000
   old=[h for h in historical if h['benchmark']==bench];assert len(old)==3
   native=[]
   for h in old:
    p=Path(h['result']);assert sha(p)==h['result_sha256'];n=read(p);ni=n['identity'];assert n['valid'] and ni['input']=='simmedium'
    checks={'elf':ni['elf_sha256']==app['sha256'],'rootfs':ni['rootfs_sha256']==r['sha256'],'case':ni['case']==case,'threads':ni['threads']==1,'frequency':ni['target_boom_hz']==fd['target_boom_hz'],'memory_model':ni['memory_model']=={k:mem[k] for k in ['model','settings']},'linux_memory':ni['linux_memory_cap_bytes']==fd['linux_mem_cap'],'bootargs':ni['linux_bootargs']==fd['bootargs']}
    native.append(dict(result=str(p),result_sha256=sha(p),repeat=ni['repetition'],roi_cycles=n['roi_cycles'],method='ARCHIVED_NATIVE_FPGA',contract_checks=checks,software_contract_matches=all(checks.values())))
   assert all(x['software_contract_matches'] for x in native),('historical contract mismatch',bench,native)
   for p in [ap,rp,fp,kp,elf,fdpath,Path(r['path']),Path(app['path'])]:files[str(p)]=sha(p)
   ct=dict(benchmark=bench,profile=profile,input='simmedium',repeat=1,mode='ec',case=case,app_sha256=app['sha256'],rootfs_sha256=r['sha256'],firmware=str(elf),firmware_sha256=sha(elf),fdt=fd,apps_receipt=str(ap),rootfs_receipt=str(rp),firmware_receipt=str(fp),native_archives=native,preflight='PASS_SOFTWARE_INPUT_MEMORY_FREQUENCY_CONTRACT',method='CPU_GOLDENGATE_FULL_EC_LINUX_SIMMEDIUM',roi_counter='same hardware marker-to-marker target ticks; no wall-clock proxy',cross_backend_slowdown_admission='PENDING_FULL_TARGET_CONFIGURATION_AND_RUNTIME_COUNTER_CHECKS')
  except Exception as e:ct=dict(benchmark=bench,input='simmedium',repeat=1,mode='ec',preflight='FAILED',error=repr(e))
  contracts.append(ct);save(ROOT/'contracts'/f'{bench}.json',ct)
 inputs=dict(functional_baseline=BASE,model=str(MODEL),model_sha256=MODEL_SHA,print_bridges=nprints,memory=mem,benchmarks=BENCH,contracts=contracts,files=files,native_launch_allowed=False,input_sizes=['simmedium'],repetitions=1,fpga_access=False,boot_timeout_seconds=21600,run_timeout_seconds=86400,stalled_progress_timeout_seconds=1800,log_budget_compressed_bytes=24*2**30,minimum_disk_free_bytes=30*2**30,simulators_total=2,cpu_slots=[201,200],created_utc=now())
 save(ROOT/'inputs.json',inputs);publish();print([(c['benchmark'],c['preflight'],c.get('error')) for c in contracts],flush=True)
def publish():
 if not (ROOT/'inputs.json').exists():return
 x=read(ROOT/'inputs.json');rows=[]
 for ct in x['contracts']:
  d=ROOT/'runs'/ct['benchmark'];s=read(d/'state.json') if (d/'state.json').exists() else {};r=read(d/'result.json') if (d/'result.json').exists() else {}
  rows.append(dict(benchmark=ct['benchmark'],input='simmedium',ec_repetitions=1,native_archived_valid_n=len(ct.get('native_archives',[])),native_relaunched=False,preflight=ct['preflight'],ec_status=r.get('status',s.get('status','QUEUED')),ec_roi_target_cycles=r.get('roi_cycles'),slowdown=None,slowdown_status='PENDING_VALID_FULL_SIMMEDIUM_EC_AND_COMPARABILITY',method='CPU_GOLDENGATE_EC',run_directory=str(d)))
 with (ROOT/'coverage.csv').open('w') as f:w=csv.DictWriter(f,fieldnames=list(rows[0]));w.writeheader();w.writerows(rows)
 save(ROOT/'coverage.json',dict(updated_utc=now(),rows=rows,valid_formal_ec=sum(bool(r['ec_roi_target_cycles']) for r in rows),scoped_data_excluded=True))
def run_one(bench,cpu):
 inputs=read(ROOT/'inputs.json');ct=next(c for c in inputs['contracts'] if c['benchmark']==bench)
 out=ROOT/'runs'/bench;out.mkdir(parents=True,exist_ok=True)
 lock=(out/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 assert not (out/'binding.json').exists(),'one attempt only; never duplicate an interrupted run'
 if ct['preflight']!='PASS_SOFTWARE_INPUT_MEMORY_FREQUENCY_CONTRACT':
  save(out/'result.json',dict(status='SKIPPED_PREFLIGHT_FAILED',error=ct.get('error'),valid=False));return
 held=[]
 for name in [f'cpu{cpu}-simulator.lock',('ec' if cpu==201 else 'ec-aux')+'-simulator.lock']:
  f=(OTHER/name).open('a');fcntl.flock(f,fcntl.LOCK_EX|fcntl.LOCK_NB);held.append(f)
 os.sched_setaffinity(0,{cpu});os.nice(19-os.getpriority(os.PRIO_PROCESS,0));resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
 for p in [str(MODEL),ct['firmware'],str(Path(__file__))]:assert sha(p)==inputs['files'][p]
 uartin=out/'uart.in';uartin.write_bytes(b'');rid=f'ec-{bench}-simmedium-r1-20261112'
 args=[str(MODEL),'+permissive','+max-cycles=1000000000000','+fesvr-step-size=1000',*inputs['memory']['plusargs'],'+heartbeat-polling-interval=1000','+uart-in0='+str(uartin),'+uart-out0='+str(out/'uart.log'),'+print-file='+str(out/'rtl-events-'),'+permissive-off','+prog0='+ct['firmware']]
 save(out/'binding.json',dict(contract=ct,args=args,model_sha256=sha(MODEL),runner_sha256=sha(__file__),inputs_sha256=sha(ROOT/'inputs.json'),functional_baseline=BASE,mode='ec',input='simmedium',repeat=1,cpu_affinity=[cpu],fpga_access=False,started_utc=now()))
 sel=selectors.DefaultSelector();streams={};keep=[]
 # Lossless compression of the original FIFO byte streams; no discarded prints.
 for n in [f'rtl-events-{i}' for i in range(inputs['print_bridges'])]:
  path=out/n;os.mkfifo(path);fd=os.open(path,os.O_RDWR|os.O_NONBLOCK);keep.append(fd)
  backing=(out/(n+'.gz')).open('xb');z=gzip.GzipFile(fileobj=backing,mode='wb',compresslevel=1,mtime=0)
  streams[fd]=dict(name=n,backing=backing,z=z,hash=hashlib.sha256(),bytes=0);sel.register(fd,selectors.EVENT_READ)
 env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'1','EC_EXTERNAL_OBSERVER_FILE':str(out/'external-events.jsonl')}
 child=subprocess.Popen(['/usr/bin/stdbuf','-oL','-eL',*args],cwd=out,stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,env=env,start_new_session=True)
 fd=child.stdout.fileno();os.set_blocking(fd,False);backing=(out/'host-complete.log.gz').open('xb');streams[fd]=dict(name='host-complete.log',backing=backing,z=gzip.GzipFile(fileobj=backing,mode='wb',compresslevel=1,mtime=0),hash=hashlib.sha256(),bytes=0);sel.register(fd,selectors.EVENT_READ)
 start=time.monotonic();last=0;sent=False;shutdown=False;done_at=None;cause=None;idle_at=start;progress=None;exit_at=None;buf=b'';faults=[]
 compact=(out/'host-summary.log').open('w');identity=ident(child.pid)
 def state():
  u=(out/'uart.log').read_text(errors='replace') if (out/'uart.log').exists() else ''
  hb=out/'heartbeat.csv';lastrow=hb.read_text().splitlines()[-1] if hb.exists() else None
  return dict(status='RUNNING_SIMMEDIUM_EC' if sent else 'BOOTING_FULL_EC_LINUX_FOR_SIMMEDIUM',child=identity,controller=ident(os.getpid()),benchmark=bench,input='simmedium',repeat=1,mode='ec',cpu=cpu,guest_command_sent=sent,guest_command_ended=shutdown,uart_bytes=len(u.encode()),heartbeat_last_row=lastrow,host_seconds=time.monotonic()-start,raw_bytes=sum(s['bytes'] for s in streams.values()),updated_utc=now(),stop_cause=cause)
 save(out/'state.json',state())
 try:
  while True:
   had=False
   for key,_ in sel.select(timeout=1):
    try:data=os.read(key.fd,262144)
    except BlockingIOError:continue
    if not data:
     if key.fd==child.stdout.fileno():sel.unregister(key.fd)
     continue
    had=True;s=streams[key.fd];s['hash'].update(data);s['bytes']+=len(data);s['z'].write(data)
    if s['name']=='host-complete.log':
     buf+=data;lines=buf.split(b'\n');buf=lines.pop()
     for line in lines:
      text=line.decode(errors='replace').rstrip('\r')
      if not re.match(r'^C[1-4]:',text):compact.write(text+'\n')
      if re.search(r'Assertion failed|%Error|Simulator deadlock detected|\*\*\* FAILED',text):faults.append(text[:1000]);cause=cause or 'MODEL_FAILURE'
   stamp=time.monotonic()
   if stamp-last>=10:
    st=state();u=(out/'uart.log').read_bytes() if (out/'uart.log').exists() else b''
    mark=(st['heartbeat_last_row'],st['raw_bytes'],st['uart_bytes'])
    if mark!=progress:progress=mark;idle_at=stamp
    if not sent and b'EC_GUEST_READY' in u:
     with uartin.open('ab',buffering=0) as f:f.write(f'/opt/ec-fpga/run-one {bench} simmedium 1 {rid}; echo EC_COMMAND_EXIT=$?\n'.encode());os.fsync(f.fileno())
     sent=True
    if sent and not shutdown and re.search(rb'EC_COMMAND_EXIT=\d+\r?\n',u):
     with uartin.open('ab',buffering=0) as f:f.write(b'/bin/busybox sync; /bin/poweroff -f\n');os.fsync(f.fileno())
     shutdown=True;done_at=stamp
    if any(v in u for v in [b'Kernel panic',b'EC_OPT4_INVALID',b'EC_SAMPLE_FAILED',b'EC_SAMPLE_INVALID']):cause=cause or 'GUEST_FAILURE'
    if not sent and stamp-start>inputs['boot_timeout_seconds']:cause=cause or 'BOOT_HOST_TIMEOUT'
    if stamp-start>inputs['run_timeout_seconds']:cause=cause or 'RUN_HOST_TIMEOUT'
    if stamp-idle_at>inputs['stalled_progress_timeout_seconds']:cause=cause or 'NO_OBSERVED_PROGRESS_TIMEOUT'
    if shutdown and done_at and stamp-done_at>30:cause=cause or ('CONTROLLED_AFTER_POWERDOWN' if b'Power down' in u else 'GUEST_SHUTDOWN_TIMEOUT')
    size=sum(p.stat().st_size for p in out.iterdir() if p.is_file())
    if size>inputs['log_budget_compressed_bytes'] or shutil.disk_usage(out).free<inputs['minimum_disk_free_bytes']:cause=cause or 'DISK_BUDGET'
    for s in streams.values():s['z'].flush();s['backing'].flush()
    compact.flush();save(out/'state.json',state());last=stamp
   if cause and child.poll() is None:
    assert ident(child.pid)==identity
    os.killpg(child.pid,signal.SIGTERM)
    try:child.wait(timeout=15)
    except subprocess.TimeoutExpired:
     assert ident(child.pid)==identity;os.killpg(child.pid,signal.SIGKILL);child.wait()
   if child.poll() is not None:
    exit_at=exit_at or stamp
    if not had and stamp-exit_at>=2:break
 finally:
  if child.poll() is None:
   assert ident(child.pid)==identity;os.killpg(child.pid,signal.SIGTERM);child.wait(timeout=15)
  integrity={}
  for fd,s in streams.items():
   s['z'].close();s['backing'].flush();os.fsync(s['backing'].fileno());s['backing'].close();integrity[s['name']]=dict(raw_bytes=s['bytes'],raw_sha256=s['hash'].hexdigest(),gzip_sha256=sha(out/(s['name']+'.gz')))
  for fd in keep:os.close(fd)
  sel.close();compact.close()
  ep=out/'external-events.jsonl'
  if ep.exists():
   rawhash=sha(ep);rawbytes=ep.stat().st_size
   with ep.open('rb') as src,gzip.open(str(ep)+'.gz','xb',compresslevel=1) as dst:shutil.copyfileobj(src,dst)
   integrity['external-events.jsonl']=dict(raw_bytes=rawbytes,raw_sha256=rawhash,gzip_sha256=sha(str(ep)+'.gz'))
  save(out/'stream-integrity.json',integrity)
 u=(out/'uart.log').read_text(errors='replace').replace('\r','') if (out/'uart.log').exists() else ''
 snapshots=[dict(re.findall(r'(\w+)=([0-9a-fA-F]+)',s)) for s in re.findall(r'EC_OPT4_SNAPSHOT ([^\n]*)',u)]
 cycles=drain=None;counts={}
 if len(snapshots)==2:
  try:
   counts={k:int(snapshots[-1][k]) for k in ['epoch','begin','end','drain','generated','completed','outstanding','faults','passed','failed','cancelled','dropped']}
   if counts['end']>counts['begin'] and counts['drain']>=counts['end']:cycles=counts['end']-counts['begin'];drain=counts['drain']-counts['end']
  except (ValueError,KeyError):pass
 software=(u.count('EC_SAMPLE_GUEST_DONE run_id='+rid+' ')==1 and re.search(r'^EC_COMMAND_EXIT=0$',u,re.M) is not None)
 # Positive EC accounting and strict external/print audit are required before publication.
 candidate=software and cycles is not None and counts.get('generated',0)>0 and counts['generated']==counts['completed']==counts['passed'] and not any(counts[k] for k in ['outstanding','faults','failed','cancelled','dropped']) and not faults
 status='COMPLETED_AWAITING_STRICT_AUDIT' if candidate else 'FAILED_OR_INCOMPLETE_SKIP_NEXT'
 result=dict(status=status,valid=False,publication_candidate=candidate,benchmark=bench,input='simmedium',repeat=1,mode='ec',method=ct['method'],roi_cycles=cycles if candidate else None,observed_roi_cycles=cycles,drain_cycles=drain,counts=counts,software_output_valid=software,returncode=child.returncode,stop_cause=cause,faults=faults,host_wall_seconds=time.monotonic()-start,functional_baseline=BASE,fpga_access=False,binding_sha256=sha(out/'binding.json'),stream_integrity_sha256=sha(out/'stream-integrity.json'),completed_utc=now(),slowdown=None)
 save(out/'result.json',result);save(out/'state.json',dict(status=status,result=str(out/'result.json'),updated_utc=now()))
def campaign():
 instance=(ROOT/'campaign.lock').open('a');fcntl.flock(instance,fcntl.LOCK_EX|fcntl.LOCK_NB)
 inputs=read(ROOT/'inputs.json');assert not inputs['native_launch_allowed'] and inputs['input_sizes']==['simmedium'] and inputs['repetitions']==1
 for p,h in inputs['files'].items():assert sha(p)==h,('changed pinned file',p)
 active={};pending=list(BENCH)
 while pending or active:
  for cpu in inputs['cpu_slots']:
   if cpu in active:continue
   while pending:
    b=pending.pop(0);out=ROOT/'runs'/b
    if (out/'result.json').exists():continue
    if (out/'binding.json').exists():
     save(ROOT/f'{b}-adoption-block.json',dict(status='UNFINISHED_EXISTING_ATTEMPT_NO_RELAUNCH',updated_utc=now()));continue
    # Locks are acquired by the worker; an occupied shared CPU is never displaced.
    fs=[];available=True
    for name in [f'cpu{cpu}-simulator.lock',('ec' if cpu==201 else 'ec-aux')+'-simulator.lock']:
     f=(OTHER/name).open('a');fs.append(f)
     try:fcntl.flock(f,fcntl.LOCK_EX|fcntl.LOCK_NB)
     except BlockingIOError:available=False;break
    for f in fs:f.close()
    if not available:pending.insert(0,b);break
    log=(ROOT/f'{b}-controller.log').open('ab',buffering=0)
    p=subprocess.Popen([sys.executable,str(Path(__file__)),'run',b,str(cpu)],stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,start_new_session=True)
    active[cpu]=(p,b,log);break
  for cpu,(p,b,log) in list(active.items()):
   if p.poll() is not None:
    log.close();out=ROOT/'runs'/b;out.mkdir(parents=True,exist_ok=True)
    if not (out/'result.json').exists():save(out/'result.json',dict(status='WRAPPER_FAILED_SKIP_NEXT',valid=False,returncode=p.returncode,log=str(ROOT/f'{b}-controller.log'),completed_utc=now()))
    del active[cpu]
  publish();save(ROOT/'campaign-state.json',dict(status='RUNNING_EC_SIMMEDIUM_ONLY' if pending or active else 'FIRST_ROUND_FINISHED',controller=ident(os.getpid()),active={str(c):dict(benchmark=b,worker=ident(p.pid)) for c,(p,b,l) in active.items()},pending=pending,native_launch_allowed=False,input='simmedium',repetitions=1,updated_utc=now()))
  if pending or active:time.sleep(10)
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('action',choices=['prepare','campaign','run','publish']);p.add_argument('benchmark',nargs='?',choices=BENCH);p.add_argument('cpu',nargs='?',type=int,choices=[200,201]);a=p.parse_args()
 if a.action=='run':run_one(a.benchmark,a.cpu)
 else:{'prepare':prepare,'campaign':campaign,'publish':publish}[a.action]()
