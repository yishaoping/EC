from common import *
import argparse,gzip,re,selectors,signal,subprocess,time,resource,fcntl
def run(manifest,mode,repeat=1,attempt=1,slot_name=None):
 slot_name=slot_name or mode
 cpus={'native':200,'native-aux':201,'native-extra1':202,'native-extra2':204,'ec':201,'ec-aux':200,'ec-extra1':202,'ec-extra2':204}
 assert slot_name in cpus and (slot_name.startswith('native')==(mode=='native'))
 cpu=cpus[slot_name]
 cpu_lock=(ROOT/f'cpu{cpu}-simulator.lock').open('a');fcntl.flock(cpu_lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 slot=(ROOT/(slot_name+'-simulator.lock')).open('a');fcntl.flock(slot,fcntl.LOCK_EX|fcntl.LOCK_NB)
 mf=read(manifest);out=ROOT/'runs'/f"{mf['benchmark']}-{mf['profile']}-{mode}-r{repeat}"
 policy_path=ROOT/'execution-policy.json';policy=read(policy_path) if policy_path.exists() else {}
 host_timeout=max(mf['timeout_seconds'],policy.get('host_timeout_floor_seconds',0))
 guard=policy.get('extra_slot_pressure_guard',{}) if slot_name in ['native-extra1','native-extra2','ec-extra1','ec-extra2'] else {}
 paused_at=None;paused_seconds=0;pressure_before=None;last_pressure=0
 def cpu_snapshot():
  return {s.split()[0]:list(map(int,s.split()[1:])) for s in Path('/proc/stat').read_text().splitlines() if s.startswith('cpu')}
 siblings=[int(s) for s in Path(f'/sys/devices/system/cpu/cpu{cpu}/topology/thread_siblings_list').read_text().strip().split(',') if int(s)!=cpu] if guard else []
 if attempt>1:out=out.with_name(out.name+f'-attempt{attempt}')
 if (out/'result.json').exists():return read(out/'result.json')
 out.mkdir(exist_ok=True)
 lock=(out/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 assert not (out/'binding.json').exists(),'Unfinished attempt must retain evidence and receive a new attempt directory'
 os.nice(19-os.getpriority(os.PRIO_PROCESS,0));os.sched_setaffinity(0,{cpu})
 resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
 binary=NATIVE if mode=='native' else PROTECTED;elf=mf['elf'][mode]
 assert sha(elf['path'])==elf['sha256']
 for n,h in mf.get('shared_kernel_objects',{}).items():assert sha(n)==h
 args=[str(binary),'+permissive','+max-cycles='+str(mf['max_target_cycles']),'+fesvr-step-size=1000',*MEM,'+heartbeat-polling-interval=1000','+print-file='+str(out/'rtl-prints-')]
 if mode=='native':args+=['+ec-dac-roi-log='+str(out/'roi-raw.jsonl'),'+ec-dac-snapshot-seconds=20']
 args+=['+permissive-off','+prog0='+elf['path']]
 # Additional FESVR program arguments are parsed after prog0.
 args+=mf.get('program_args',[])
 env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'1','EC_EXTERNAL_OBSERVER_FILE':str(out/'external-events.jsonl') if mode=='ec' else ''}
 save(out/'binding.json',dict(args=args,binary_sha256=sha(binary),elf=elf,manifest=str(manifest),manifest_sha256=sha(manifest),functional_baseline=BASE,memory=MEM,fpga_access=False,started_utc=now(),runner_sha256=sha(__file__),execution_policy=policy,execution_policy_sha256=sha(policy_path) if policy else None,effective_host_timeout_seconds=host_timeout,simulation_slot=slot_name,cpu_affinity=[cpu]))
 rawhash=hashlib.sha256();rawbytes=0;rows=[];faults=[];buf=b'';target=None;cause=None;start=time.monotonic();last=start
 with (out/'host-complete.log.gz').open('xb') as backing,(out/'host-summary.log').open('w') as compact:
  zipped=gzip.GzipFile(fileobj=backing,mode='wb',compresslevel=1,mtime=0)
  child=subprocess.Popen(['/usr/bin/stdbuf','-oL','-eL',*args],cwd=out,stdin=subprocess.DEVNULL,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,env=env,start_new_session=True)
  save(out/'state.json',dict(status='RUNNING',child=ident(child.pid),controller=ident(os.getpid()),argv=args))
  sel=selectors.DefaultSelector();sel.register(child.stdout,selectors.EVENT_READ)
  while sel.get_map():
   for key,_ in sel.select(timeout=1):
    data=os.read(key.fileobj.fileno(),262144)
    if not data:sel.unregister(key.fileobj);continue
    rawhash.update(data);rawbytes+=len(data);zipped.write(data);buf+=data
    lines=buf.split(b'\n');buf=lines.pop()
    for line in lines:
     text=line.decode(errors='replace').rstrip('\r')
     if not re.match(r'^C[1-4]:',text):compact.write(text+'\n')
     if any(k in text for k in ['[ROI]','[OUTPUT]','[APP]','[COMPUTATION]','[END]','[IRQ]']):rows.append(text)
     if re.search(r'Assertion failed|%Error|status=FAIL|Simulator deadlock detected|\*\*\* FAILED',text):faults.append(text[:1000])
     if mode=='ec' and re.search(r'EC_OPT4_PACKAGE_RESULT .*status=[12]\b',text):
      faults.append(text[:1000]);cause=cause or 'NONPASS_CHECKER_RESULT'
     m=re.search(r'Target Cycles Emulated:\s*(\d+)',text)
     if m:target=int(m[1])
   if time.monotonic()-last>=20:
    zipped.flush();compact.flush();backing.flush();os.fsync(backing.fileno())
    save(out/'state.json',dict(status='RUNNING',child=ident(child.pid),controller=ident(os.getpid()),host_seconds=time.monotonic()-start,raw_bytes=rawbytes,paused_for_pressure=paused_at is not None,pressure_paused_seconds=paused_seconds+(time.monotonic()-paused_at if paused_at else 0),updated_utc=now()))
    last=time.monotonic()
   if guard and time.monotonic()-last_pressure>=guard.get('poll_seconds',10) and child.poll() is None:
    current=cpu_snapshot();last_pressure=time.monotonic()
    if pressure_before is not None:
     def busy(name):
      delta=[b-a for a,b in zip(pressure_before[name],current[name])]
      return 1-(delta[3]+delta[4])/sum(delta) if sum(delta) else 0
     available_mem=int(re.search(r'^MemAvailable:\s*(\d+)',Path('/proc/meminfo').read_text(),re.M)[1])*1024
     global_busy=busy('cpu');sibling_busy=max([busy('cpu'+str(s)) for s in siblings] or [0])
     pressure=global_busy>guard.get('max_global_busy_fraction',.65) or sibling_busy>guard.get('max_sibling_busy_fraction',.2) or available_mem<guard.get('minimum_available_memory_bytes',64*2**30)
     if pressure!=(paused_at is not None):
      assert ident(child.pid).get('pid')==child.pid
      os.killpg(child.pid,signal.SIGSTOP if pressure else signal.SIGCONT)
      stamp=time.monotonic()
      if pressure:paused_at=stamp
      else:paused_seconds+=stamp-paused_at;paused_at=None
      with (out/'resource-pressure-events.jsonl').open('a') as pressure_log:pressure_log.write(json.dumps(dict(created_utc=now(),event='PAUSE_OWN_SIMULATOR' if pressure else 'RESUME_OWN_SIMULATOR',child=ident(child.pid),global_busy_fraction=global_busy,sibling_busy_fraction=sibling_busy,available_memory_bytes=available_mem))+'\n')
    pressure_before=current
   if cause is None or cause=='NONPASS_CHECKER_RESULT':
    active_seconds=time.monotonic()-start-paused_seconds-(time.monotonic()-paused_at if paused_at else 0)
    if active_seconds>host_timeout:cause='HOST_TIMEOUT'
    if rawbytes>policy.get('raw_log_limit_bytes',4*2**30):cause='RAW_LOG_LIMIT'
    try:
     resident_kib=int(re.search(r'^VmRSS:\s*(\d+)',Path(f'/proc/{child.pid}/status').read_text(),re.M)[1])
     if resident_kib*1024>policy.get('resident_limit_bytes',16*2**30):cause='RESIDENT_MEMORY_LIMIT'
    except (FileNotFoundError,TypeError):pass
    if cause and child.poll() is None:
     if paused_at is not None:os.killpg(child.pid,signal.SIGCONT);paused_seconds+=time.monotonic()-paused_at;paused_at=None
     os.killpg(child.pid,signal.SIGTERM)
     try:child.wait(timeout=15)
     except subprocess.TimeoutExpired:os.killpg(child.pid,signal.SIGKILL)
  rc=child.wait();zipped.close();compact.flush();os.fsync(backing.fileno())
 integrity=dict(raw_sha256=rawhash.hexdigest(),raw_bytes=rawbytes,gzip_sha256=sha(out/'host-complete.log.gz'),complete_stream_eof=True)
 save(out/'stdout-integrity.json',integrity)
 roi=next((re.search(r'start=(\d+) stop=(\d+) cycles=(\d+)',x) for x in rows if x.startswith('[ROI]')),None)
 ap=next((re.search(r'cycles=(\d+) instret=(\d+)',x) for x in rows if x.startswith('[APP]')),None)
 outputs=[x.split('[OUTPUT] ',1)[1] for x in rows if x.startswith('[OUTPUT] ')]
 irq=next((re.search(r'before=(\d+) after=(\d+) mie=(\d+)',x) for x in rows if x.startswith('[IRQ]')),None)
 irq_valid=(irq is not None and irq[1]==irq[2] and int(irq[3])&128==0) if mf.get('interrupt_policy') else None
 expected_ok=outputs==mf['expected_output']
 if mf.get('output_acceptance')=='verified_fields_checksum_may_differ_from_host':
  norm=lambda a:[re.sub(r'checksum=[0-9a-f]+','checksum=ARCH_FLOAT',x) for x in a]
  expected_ok=norm(outputs)==norm(mf['expected_output']) and all('verified=1' in x for x in outputs)
 correct=rc==0 and cause is None and not faults and roi is not None and ap is not None and expected_ok and '[END] hart=0 status=PASS' in rows
 if mf.get('interrupt_policy'):correct=correct and irq_valid
 strict=None;error=None;tail=None
 if correct and mode=='ec':
  try:
   strict=module(W/'candidates/full-gg-acceptance-strict-r1-20261111/analyze.py','strict_join').analyze(out)
   save(out/'strict-acceptance.json',strict)
   events=[json.loads(x) for x in (out/'external-events.jsonl').read_text().splitlines()]
   accepted=[x for x in events if x['kind']=='BOOM_RESULT_ACCEPTED']
   tail=max(0,max(x['boom_csr_cycle'] for x in accepted)-int(roi[2]))
  except Exception as e:error=repr(e)
 valid=correct and (mode=='native' or strict is not None and strict['passed'])
 result=dict(benchmark=mf['benchmark'],profile=mf['profile'],mode=mode,repeat=repeat,method=mf['method'],valid=valid,software_correct=correct,status='PASS' if valid else 'FAILED_OR_UNVALIDATED',returncode=rc,stop_cause=cause,faults=faults,output=outputs,application_rows=rows,strict_acceptance=strict,strict_acceptance_error=error,drain_cycles=tail,strict_detection_latency_cycles=None,full_rollback_latency_cycles=None,svb_events=None,total_fastest_target_cycles=target,host_seconds=time.monotonic()-start,completed_utc=now(),functional_baseline=BASE,manifest_sha256=sha(manifest),binding_sha256=sha(out/'binding.json'),raw_log_sha256=integrity['raw_sha256'],run_dir=str(out))
 result.update(interrupt_policy=mf.get('interrupt_policy'),interrupt_policy_verified=irq_valid)
 result.update(resource_pressure_paused_seconds=paused_seconds,active_host_seconds=time.monotonic()-start-paused_seconds,simulation_slot=slot_name)
 if roi and ap:
  begin,end,cycles=map(int,roi.groups());assert end-begin==cycles==int(ap[1])
  result.update(roi_cycles=cycles,roi_instructions=int(ap[2]),roi_start_csr=begin,roi_end_csr=end)
 save(out/'result.json',result)
 if valid:save(out/'complete.json',dict(result_sha256=sha(out/'result.json'),binding_sha256=sha(out/'binding.json'),stdout_integrity_sha256=sha(out/'stdout-integrity.json')))
 save(out/'state.json',dict(status=result['status'],result=str(out/'result.json'),controller=ident(os.getpid())))
 return result
if __name__=='__main__':
 ap=argparse.ArgumentParser();ap.add_argument('manifest');ap.add_argument('mode',choices=['native','ec']);ap.add_argument('--repeat',type=int,default=1);ap.add_argument('--attempt',type=int,default=1);ap.add_argument('--slot',choices=['native','native-aux','native-extra1','native-extra2','ec','ec-aux','ec-extra1','ec-extra2']);a=ap.parse_args()
 print(json.dumps(run(Path(a.manifest),a.mode,a.repeat,a.attempt,a.slot),indent=2))
