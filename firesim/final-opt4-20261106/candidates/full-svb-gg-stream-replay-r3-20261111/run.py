#!/usr/bin/python3
"""Force all PeekPoke source tokens. Reuse r2 compiled ABI, no model rebuild."""
from pathlib import Path
import datetime,fcntl,hashlib,json,math,os,re,resource,subprocess,sys,time,traceback
C=Path(__file__).resolve().parent;C2=C.with_name('full-svb-gg-stream-replay-r2-20261111')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');U=D/'unattended-opt4'
O=D/'cycleprecise-original-svb-gg-stream-replay-r3-20261111';OLD=D/'cycleprecise-original-svb-gg-stream-replay-r2-20261111'
OBS=D/'cycleprecise-frozen-full-gg-external-observer-r5-20261111';STANDALONE=D/'cycleprecise-original-svb-binary-replay-r1-20261111'
STATE=D/'Opt4-original-svb-gg-stream-replay-r3-state.json'
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
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def ident(pid):
 return dict(pid=pid,start_ticks=Path('/proc',str(pid),'stat').read_text().rsplit(')',1)[1].split()[19],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
def state(status,**v):save(STATE,dict(status=status,fpga_access=False,updated_utc=now(),**ident(os.getpid()),**v))
def check():
 p=read(C/'plan.json');policy=read(U/'campaign-policy.json')
 assert policy['functional_baseline_commit']==p['functional_baseline'] and policy['area_equivalence_only'] and policy['native_paused'] and not policy['fpga_access']
 assert policy['board_allowlist']==p['board_allowlist']==['0000:21:00.0']
 for f,h in p['inputs'].items():assert sha(f)==h,('CHANGED_R3_INPUT',f)
 oldplan=read(C2/'plan.json')
 for f,h in oldplan['inputs'].items():assert sha(f)==h,('CHANGED_ORIGINAL_ADAPTER_MODEL_INPUT',f)
 build=read(OLD/'build-receipt.json')
 for f,h in build['binaries'].items():assert sha(f)==h,('CHANGED_PREVIOUSLY_COMPILED_DRIVER',f)
 assert sha(C2/'plan.json')==build['plan_sha256']
 os.sched_setaffinity(0,sorted(os.sched_getaffinity(0))[:2]);resource.setrlimit(resource.RLIMIT_AS,(24*2**30,)*2)
 return p,build

def replay(trace,label,timeout,negative=False):
 argv=[str(C2/'VSVBStreamingReplay'),'+svb-force-all-inputs','+svb-trace='+str(trace),'+svb-state='+str(O/(label+'-progress.json'))]
 if negative:argv+=['+svb-mutate-data']
 path=O/(label+'.log');started=time.monotonic()
 with path.open('xb') as log:
  proc=subprocess.Popen(argv,cwd=O,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT)
  state('RUNNING_'+label,child=ident(proc.pid),argv=argv,timeout_seconds=timeout)
  try:rc=proc.wait(timeout=timeout)
  except subprocess.TimeoutExpired:proc.kill();proc.wait();raise
 text=path.read_text();m=re.search(r'SVB_GG_STREAM_SUMMARY (.*)',text)
 summary={k:(float(v) if '.' in v else int(v)) for k,v in (x.split('=',1) for x in m[1].split())} if m else None
 result=dict(returncode=rc,host_wall_seconds=time.monotonic()-started,log=str(path),log_sha256=sha(path),argv=argv,summary=summary,
  mutation_applied='MUTATED_EXPECTED_APPLICATION_OR_DIRECTED_PAYLOAD' in text,mutation_payload_rejected='SVB_GG_STREAM_MISMATCH' in text and 'port=io_promote_bits_data_0' in text,
  pass_test='[SVBProbe]PASS Test' in text,timeout_seconds=timeout)
 if summary:
  result['replayed_target_cycles_per_host_second']=summary['target_cycles']/result['host_wall_seconds']
  result['throughput_scope']='Host-controlled exact MMIO trace replay, not autonomous SVB throughput or targetarchitecture slowdown'
 fmr=re.search(r'^FMR:\s*([\d.]+)',text,re.M)
 if fmr:result['FMR']=float(fmr[1]);result['FMR_scope']='GoldenGate host cycles / fastest target cycles as reported by runtime; MMIO test harness included'
 return result

def prepare():
 assert not O.exists(),'ADOPT_EXISTING_R3_NO_DUPLICATE'
 O.mkdir();lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 p,build=check();old=read(OLD/'result.json');startup=old['force_all']
 assert startup['returncode']==0 and startup['summary']['records']==10000 and startup['summary']['mismatches']==0
 assert startup['summary']['input_cache_enabled']==0
 assert startup['summary']['capture_accepted']==startup['summary']['promote_accepted']==startup['summary']['acked']==0
 assert sha(startup['log'])==startup['log_sha256']
 assert '+svb-force-all-inputs' in startup['argv']
 # Reuse the genuine completed positive instead of repeating another10k test.
 positive=replay(C2/'directed-original-svb.bin','directed-positive',300)
 negative=replay(C2/'directed-original-svb.bin','directed-payload-negative',300,True)
 passed=positive['returncode']==0 and positive['pass_test'] and positive['summary']['records']==372 and positive['summary']['mismatches']==0 and positive['summary']['promote_accepted']>0 and negative['returncode']!=0 and negative['mutation_applied'] and negative['mutation_payload_rejected']
 result=dict(status='PASS_FORCE_ALL_STREAM_STARTUP_AND_DIRECTED_POSITIVE_PAYLOAD_NEGATIVE' if passed else 'FAILED_WITH_EVIDENCE',passed=passed,reused_real_startup_positive=startup,directed=positive,negative=negative,model_rebuilt=False,fpga_access=False,plan_sha256=sha(C/'plan.json'),previous_build_receipt=str(OLD/'build-receipt.json'),previous_build_receipt_sha256=sha(OLD/'build-receipt.json'),completed_utc=now(),scope='CPU sameGoldenGateadapter only;10kstartup realbutzeroSVBevents;372directed synthetic separate.62 emittedports definedmasks, not127debug observations. Originalr2 cachecandidate rejected and not enabled.')
 save(O/'result.json',result);state(result['status'],result=str(O/'result.json'),child={});assert passed,'DIRECTED_RECOVERY_FAILED'

def full():
 p,build=check();assert read(O/'result.json')['passed'];assert not (O/'full-result.json').exists(),'ADOPT_FULL_RESULT'
 lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 observed=read(OBS/'full-result.json');original=read(STANDALONE/'full-result.json')
 assert observed['valid_finite_observation'] and observed['full_original_generated_svb_ports_saved'] and original['passed']
 # Independent strict join does not mutate the live observer or its receipts.
 import importlib.util
 s=importlib.util.spec_from_file_location('strict_join',C.with_name('full-gg-acceptance-strict-r1-20261111')/'analyze.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
 strict=m.analyze(OBS/'canneal-observer-on');assert strict['passed'];save(O/'strict-checker-join.json',strict)
 trace=OBS/'canneal-observer-on/external-events.jsonl.svb-full.bin';expected=observed['binary_integrity']
 assert expected['counts']['capture_accepted']>0 and expected['counts']['promote_accepted']>0
 records=(trace.stat().st_size-16)//404;assert (trace.stat().st_size-16)%404==0 and records==expected['records']
 prep=read(O/'result.json');measured=max(prep['reused_real_startup_positive']['host_wall_seconds']/10000,prep['directed']['host_wall_seconds']/prep['directed']['summary']['records'])
 budget=math.ceil(3*measured*records+600);assert budget<=24*3600,'MEASURED_FULL_REPLAY_BUDGET_EXCEEDS24H_NO_ADMISSION'
 save(O/'measured-full-budget.json',dict(records=records,worst_measured_host_seconds_per_record=measured,safety_factor=3,additive_seconds=600,per_run_timeout_seconds=budget,record_snapshot_period=4096,scope='Measured CPU GG MMIO replay budget; not predicted architectureperformance',own_output_limit_bytes=4*2**30))
 positive=replay(trace,'application-positive',budget)
 summary=positive['summary'];passed=positive['returncode']==0 and positive['pass_test'] and summary is not None and summary['records']==summary['target_cycles']==records and summary['mismatches']==0 and summary['input_cache_enabled']==0
 if passed:
  for got,expected_name in [('capture_accepted','capture_accepted'),('promote_accepted','promote_accepted'),('acked','ack_accepted')]:assert summary[got]==expected['counts'][expected_name],('EVENT_COUNT_MISMATCH',got)
 negative=replay(trace,'application-payload-negative',budget,True) if passed else dict(returncode=None,mutation_applied=False,mutation_payload_rejected=False,status='NOT_RUN_AFTER_FAILED_POSITIVE')
 passed=passed and negative['returncode']!=0 and negative['mutation_applied'] and negative['mutation_payload_rejected']
 result=dict(status='PASS_COMPLETE_REAL_APPLICATION_GG_STREAM_REPLAY' if passed else 'FAILED_APPLICATION_REPLAY',passed=passed,positive=positive,negative=negative,real_application_payload_mutation_rejected=negative['mutation_payload_rejected'],trace=str(trace),trace_sha256=sha(trace),observer_result_sha256=sha(OBS/'full-result.json'),standalone_result_sha256=sha(STANDALONE/'full-result.json'),strict_checker_join_sha256=sha(O/'strict-checker-join.json'),build_receipt_sha256=sha(OLD/'build-receipt.json'),fpga_access=False,completed_utc=now(),complete_trace_records=records,scope='CPU GG adapter exactfullrealapplication binary; every targetedge,62 originalemittedports withdefinedmasks. Not FPGAmeasurement/fullOpt4formalequivalence/rollback.')
 save(O/'full-result.json',result)
 if passed:
  admission=dict(status='READY_FOR_CONTROLLED_21_ONLY_BOARD_ADMISSION_NOT_EXECUTED',functional_baseline=p['functional_baseline'],profile=p['profile'],source_id=p['source_id'],board_allowlist=p['board_allowlist'],driver=str(C2/'SVBStreamingReplay-xilinx_alveo_u280'),driver_sha256=sha(C2/'SVBStreamingReplay-xilinx_alveo_u280'),driver_args=['+svb-force-all-inputs'],required_driver_args=['+svb-force-all-inputs','+domain=0000','+bus=21','+device=00','+function=0','+bar=0','+svb-trace='+str(trace)],host_rtl_sha256=p['host_rtl_sha256'],control_header_sha256=p['control_header_sha256'],trace=str(trace),trace_sha256=result['trace_sha256'],trace_records=records,expected_summary=summary,cpu_proof=str(O/'full-result.json'),cpu_proof_sha256=sha(O/'full-result.json'),required_before_run=['Same exact certified originalSVBbitstream/headerABI','Existing21only deployment and device/run locks','Oldsynthetic task completed; no active21task','Independentmutableoutputdirectory; preserve all372cycle proof'],pass_markers=['exit0','[SVBProbe]PASS Test','SVB_GG_STREAM_SUMMARY mismatches=0 records=target_cycles=trace_records input_cache_enabled=0 and expected eventcounts'],fpga_access=False,complete_opt4=False,throughput_scope='Host MMIO trace replay targetcycles/hostsecond, not autonomous SVB throughput; targeteventlatencies come from identical replayed targetedge trace')
  save(O/'board-admission-ready.json',admission)
 state(result['status'],result=str(O/'full-result.json'),child={});assert passed,'APPLICATION_REPLAY_FAILED'
if __name__=='__main__':
 try:{'--prepare':prepare,'--full':full}[sys.argv[1]]()
 except BaseException as e:
  if O.exists():save(O/('failure-'+str(os.getpid())+'.json'),dict(error=repr(e),traceback=traceback.format_exc(),utc=now()))
  state('FAILED_WITH_EVIDENCE',error=repr(e));raise
