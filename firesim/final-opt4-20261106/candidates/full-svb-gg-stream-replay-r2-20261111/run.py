#!/usr/bin/python3
from pathlib import Path
import fcntl,hashlib,json,os,resource,subprocess,sys,time,traceback,datetime,re
C=Path(__file__).resolve().parent;W=C.parents[1]
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'cycleprecise-original-svb-gg-stream-replay-r2-20261111'
OBS=D/'cycleprecise-frozen-full-gg-external-observer-r5-20261111'
STATE=D/'Opt4-original-svb-gg-stream-replay-r2-state.json'
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for b in iter(lambda:f.read(4*2**20),b''):h.update(b)
 return h.hexdigest()
def read(p):return json.loads(Path(p).read_text())
def save(p,v):
 tmp=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with tmp.open('x') as f:json.dump(v,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(tmp,p)
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def ident(pid):
 s=Path('/proc',str(pid),'stat').read_text().rsplit(')',1)[1].split()
 return dict(pid=pid,start_ticks=s[19],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
def state(status,**v):save(STATE,dict(status=status,**ident(os.getpid()),fpga_access=False,updated_utc=now(),**v))
def check():
 p=read(C/'plan.json');policy=read(D/'unattended-opt4/campaign-policy.json')
 assert policy['functional_baseline_commit']==p['functional_baseline'] and policy['area_equivalence_only'] and policy['native_paused']
 assert not policy['fpga_access'] and policy['board_allowlist']==p['board_allowlist']==['0000:21:00.0']
 for f,h in p['inputs'].items():assert sha(f)==h,('CHANGED_INPUT',f)
 os.sched_setaffinity(0,sorted(os.sched_getaffinity(0))[:2]);resource.setrlimit(resource.RLIMIT_AS,(24*2**30,)*2)
 return p

def command(argv,label,timeout=1800):
 path=O/(label+'.log');started=time.monotonic()
 with path.open('xb') as log:
  proc=subprocess.Popen(argv,cwd=O,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT)
  state('RUNNING_'+label,child=ident(proc.pid),argv=argv)
  try:rc=proc.wait(timeout=timeout)
  except subprocess.TimeoutExpired:proc.kill();proc.wait();raise
 return dict(argv=argv,returncode=rc,host_wall_seconds=time.monotonic()-started,log=str(path),log_sha256=sha(path))
def replay(trace,label,negative=False,force_all=False,timeout=3600):
 argv=[str(C/'VSVBStreamingReplay'),'+svb-trace='+str(trace),'+svb-state='+str(O/(label+'-progress.json'))]
 if negative:argv+=['+svb-mutate-data']
 if force_all:argv+=['+svb-force-all-inputs']
 result=command(argv,label,timeout)
 text=Path(result['log']).read_text();m=re.search(r'SVB_GG_STREAM_SUMMARY (.*)',text)
 result['summary']={k:(float(v) if '.' in v else int(v)) for k,v in (x.split('=',1) for x in m[1].split())} if m else None
 result['mutation_applied']='MUTATED_EXPECTED_APPLICATION_OR_DIRECTED_PAYLOAD' in text
 result['mutation_payload_rejected']='SVB_GG_STREAM_MISMATCH' in text and 'port=io_promote_bits_data_0' in text
 return result

def prepare():
 assert not O.exists(),'ADOPT_EXISTING_PREPARATION_NO_DUPLICATE'
 O.mkdir();lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 p=check()
 results={}
 for label,key in [('compile','compile'),('cpu-link','cpu_link'),('hardware-link','hardware_link')]:
  results[label]=command(p[key],label);assert results[label]['returncode']==0,(label,results[label])
 receipt=dict(builds=results,binaries={str(C/n):sha(C/n) for n in ['VSVBStreamingReplay','SVBStreamingReplay-xilinx_alveo_u280']},plan_sha256=sha(C/'plan.json'),model_objects_rebuilt=False,target_rtl_changed=False,fpga_access=False)
 save(O/'build-receipt.json',receipt)
 startup=OBS/'probe-observer-on/external-events.jsonl.svb-full.bin'
 assert read(OBS/'probe-result.json')['passed']
 probe=replay(startup,'startup-positive')
 force_all=replay(startup,'startup-force-all-positive',force_all=True)
 directed=replay(C/'directed-original-svb.bin','directed-positive')
 negative=replay(C/'directed-original-svb.bin','directed-payload-negative',True)
 keys=['records','first_source_tick','last_source_tick','target_cycles','reset_edges','defined_output_fields','defined_output_word_checks','mismatches','capture_accepted','promote_accepted','acked']
 cache_parity=probe['summary'] and force_all['summary'] and all(probe['summary'][k]==force_all['summary'][k] for k in keys)
 passed=cache_parity and probe['returncode']==0 and force_all['returncode']==0 and directed['returncode']==0 and negative['returncode']!=0 and negative['mutation_applied'] and negative['mutation_payload_rejected']
 result=dict(status='PASS_STARTUP_AND_DIRECTED_GG_STREAM_REPLAY' if passed else 'FAILED_WITH_EVIDENCE',passed=passed,probe=probe,force_all=force_all,cache_semantic_parity=cache_parity,directed=directed,negative=negative,plan_sha256=sha(C/'plan.json'),binding=receipt,scope='CPU GoldenGate adapter. Startup contains zero application SVB events. Directed test and mutation use original synthetic372cycle trace, not application data. Only62 original emittedports with defined masks, not all127componentobservations. No FPGA run.',fpga_access=False,completed_utc=now())
 save(O/'result.json',result);state(result['status'],result=str(O/'result.json'),child={})
 assert passed,'PREPARATION_FAILED'
def full():
 p=check();assert read(O/'result.json')['passed'];assert not (O/'full-result.json').exists(),'ADOPT_FULL_RESULT'
 lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 receipt=read(O/'build-receipt.json')
 assert sha(C/'plan.json')==receipt['plan_sha256']
 for f,h in receipt['binaries'].items():assert sha(f)==h
 observed=read(OBS/'full-result.json')
 assert observed['valid_finite_observation'] and observed['full_original_generated_svb_ports_saved']
 standalone=read(D/'cycleprecise-original-svb-binary-replay-r1-20261111/full-result.json');assert standalone['passed']
 trace=OBS/'canneal-observer-on/external-events.jsonl.svb-full.bin'
 expected=observed['binary_integrity']
 assert expected['counts']['capture_accepted']>0 and expected['counts']['promote_accepted']>0
 import math
 prep=read(O/'result.json')
 measured=max(prep[k]['host_wall_seconds']/prep[k]['summary']['records'] for k in ['probe','force_all','directed'])
 total=(trace.stat().st_size-16)//404
 budget=math.ceil(3*measured*total+600)
 assert budget<=24*3600,'MEASURED_FULL_REPLAY_BUDGET_EXCEEDS_24H_DO_NOT_LAUNCH'
 save(O/'measured-full-budget.json',dict(records=total,worst_measured_host_seconds_per_record=measured,safety_factor=3,additive_seconds=600,timeout_seconds=budget,scope='Finite upper budget from actual GG adapter startup and directed workloads; not predicted architecture performance'))
 positive=replay(trace,'application-positive',timeout=budget)
 negative=replay(trace,'application-payload-negative',True,timeout=budget)
 passed=positive['returncode']==0 and negative['returncode']!=0 and negative['mutation_applied'] and negative['mutation_payload_rejected']
 result=dict(status='PASS_COMPLETE_REAL_APPLICATION_GG_STREAM_REPLAY' if passed else 'FAILED_APPLICATION_REPLAY',passed=passed,positive=positive,negative=negative,real_application_payload_mutation_rejected=negative['mutation_payload_rejected'],trace=str(trace),trace_sha256=sha(trace),observer_result_sha256=sha(OBS/'full-result.json'),standalone_result_sha256=sha(D/'cycleprecise-original-svb-binary-replay-r1-20261111/full-result.json'),build_receipt_sha256=sha(O/'build-receipt.json'),fpga_access=False,completed_utc=now(),scope='CPU GG adapter, same existing ABI and model.62 original emittedports masked when undefined. Not FPGA measurement or wholeOpt4 equivalence.')
 save(O/'full-result.json',result)
 if passed:
  admission=dict(status='READY_FOR_CONTROLLED_21_ONLY_BOARD_ADMISSION_NOT_EXECUTED',functional_baseline=p['functional_baseline'],profile=p['profile'],source_id=p['source_id'],board_allowlist=p['board_allowlist'],driver=str(C/'SVBStreamingReplay-xilinx_alveo_u280'),driver_sha256=sha(C/'SVBStreamingReplay-xilinx_alveo_u280'),host_rtl_sha256=p['inputs'][str(D/'cycleprecise-frozen-svb-fpga-r2-20261111/goldengate/FireSim-generated.sv')],control_header_sha256=p['inputs'][str(D/'cycleprecise-frozen-svb-fpga-r2-20261111/goldengate/FireSim-generated.const.h')],trace=str(trace),trace_sha256=result['trace_sha256'],cpu_proof=str(O/'full-result.json'),cpu_proof_sha256=sha(O/'full-result.json'),required_before_run=['Exact certified bitstream using this adapter source and header ABI','Existing21only deployment and device/run locks','No active21task; safe boundary only','Per-run mutable output directory; no changes to existing372cycle proof or driver'],fpga_access=False,complete_opt4=False)
  save(O/'board-admission-ready.json',admission)
 state(result['status'],result=str(O/'full-result.json'),child={});assert passed,'APPLICATION_REPLAY_FAILED'
if __name__=='__main__':
 try:{'--prepare':prepare,'--full':full}[sys.argv[1]]()
 except BaseException as e:
  if O.exists():save(O/('failure-'+str(os.getpid())+'.json'),dict(error=repr(e),traceback=traceback.format_exc(),utc=now()))
  state('FAILED_WITH_EVIDENCE',error=repr(e));raise
