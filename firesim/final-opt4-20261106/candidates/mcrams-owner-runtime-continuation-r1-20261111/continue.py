#!/usr/bin/python3
"""Idempotent nonresident runtime-only successor; never duplicates compilation."""
import argparse, datetime, fcntl, hashlib, importlib.util, json, os, pathlib, resource, shutil, time
P=pathlib.Path;C=P(__file__).resolve().parent
W=P('/data1/gzh/EC/firesim/final-opt4-20261106');D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U=D/'unattended-opt4';BUILD=D/'cycleprecise-owner-pair-compile-round43-v1-20261111'
O=D/'cycleprecise-owner-pair-runtime-r1-20261111';S=D/'Opt4-mcrams-owner-pair-runtime-r1-state.json'
HELPER=W/'candidates/mcrams-owner-pair-metasim-r1-20261111/controller.py'
BASE='8491167d84b6d9521b151a743673c1516926a1f8';HW='3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
NAME='owner-pair-runtime-r1-3656aec4'
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def read(p):return json.loads(P(p).read_text())
def sha(p):
 h=hashlib.sha256()
 with P(p).open('rb') as f:
  for b in iter(lambda:f.read(2**20),b''):h.update(b)
 return h.hexdigest()
def save(p,j):
 p=P(p);p.parent.mkdir(parents=True,exist_ok=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def ident(pid):
 try:
  f=P(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=f[19],host_boot_id=P('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def previous_live():
 p=D/'Opt4-route-a-full-mcrams-parity-round38-v1-state.json'
 if not p.exists():return False
 s=read(p)
 return any(i.get('pid') and ident(i['pid'])=={k:i[k] for k in ['pid','start_ticks','host_boot_id']} for i in [s,s.get('child',{})])
def report(status,**kw):save(C/'continuation-state.json',dict(status=status,checked_utc=now(),**kw));print(status)
def prepare():
 lock=(C/'prepare.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 request=U/'requests'/(NAME+'.json')
 if request.exists():
  assert read(request)==read(C/'request.json'),'existing request version changed'
  report('SUBMITTED_ADOPT_EXISTING_NO_DUPLICATE',request=str(request));return
 result=BUILD/'result.json'
 if not result.exists():report('WAITING_EXISTING_ROUND43_COMPILE',result=str(result));return
 done=read(result)
 if done.get('status')!='BUILT_BOTH_SAME_TARGET_HOST_MODELS_FULL_PARITY_AND_AREA_PENDING':
  report('BLOCKED_EXISTING_COMPILE_FAILED_REQUIRES_RECOVERY',result=str(result));return
 if previous_live():report('WAITING_EXISTING_FROZEN_MCRAMS_CANNEAL_NO_PARALLEL_SECOND');return
 assert not (C/'plan.json').exists() and not O.exists(),'partial preparation retained; reviewed recovery required'
 bp=read(BUILD/'build-plan.json');assert sha(BUILD/'build-plan.json')==done['build_plan_sha256']
 assert bp['functional_baseline']==BASE and bp['hardware_commit']==HW and bp['sequential_models']
 rbp=D/'cycleprecise-frozen-full-metasim-sample-r1-20261111/binding.json';rb=read(rbp)
 elf=P(next(x[len('+prog0='):] for x in rb['args'] if x.startswith('+prog0=')));assert sha(elf)==rb['elf_sha256']
 inputs={str(p):sha(p) for p in [C/'continue.py',HELPER,BUILD/'build-plan.json',result,rbp,elf]};models={}
 for mode in bp['modes']:
  label='MCRams' if mode['label']=='MC' else mode['label'];receipt=BUILD/mode['label']/'compile-receipt.json';r=read(receipt);b=P(mode['binary'])
  assert r['returncode']==0 and sha(b)==r['binary_sha256'] and r['build_plan_sha256']==sha(BUILD/'build-plan.json')
  header=P(mode['host_dir'])/'FireSim-generated.const.h';assert sha(header)==r['generated_const_h_sha256']
  inputs.update({str(p):sha(p) for p in [receipt,b,header]});models[label]=dict(binary=str(b),environment=mode['environment'],receipt=str(receipt))
 assert set(models)=={'Plain','MCRams'}
 O.mkdir();plan=dict(schema='ec-owner-runtime-after-unique-round43-compile/1',functional_baseline=BASE,derived_hardware=HW,
  inputs=inputs,models=models,reference_args=rb['args'],elf_sha256=rb['elf_sha256'],application_expected_output=rb['application_expected_output'],
  host_timeout_seconds=rb['host_timeout_seconds'],owned_log_budget_bytes=rb['owned_log_budget_bytes'],target_cycle_limit=rb['target_cycle_limit'],
  no_compile=True,fpga_access=False,production_admission=False,whole_fit=False,created_utc=now())
 save(C/'plan.json',plan);save(O/'plan.json',plan)
 # Runtime controller rechecks original binaries and receipts; broker binds
 # immutable W evidence capsule and entry script without huge model copies.
 req=dict(action='cpu_job',spec=dict(name=NAME,kind='module',cwd=str(C),argv=['/usr/bin/python3',str(C/'continue.py'),'--run'],
  inputs={str(p):sha(p) for p in [C/'continue.py',C/'plan.json',HELPER]},outputs=[str(O/'result.json')],checkpoints=[str(S)]))
 save(C/'request.json',req);save(request,req);report('SUBMITTED_RUNTIME_ONLY_NO_NEW_COMPILE',request=str(request))
def run():
 plan=read(C/'plan.json');lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 assert not S.exists(),'adopt existing runtime state; no duplicate'
 assert all(sha(p)==h for p,h in plan['inputs'].items());assert not previous_live(),'previous Canneal unexpectedly still alive'
 assert {250,251}<=set(os.sched_getaffinity(0));os.sched_setaffinity(0,{250,251});resource.setrlimit(resource.RLIMIT_AS,(64*2**30,64*2**30))
 sp=importlib.util.spec_from_file_location('pair_helpers',HELPER);m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m);m.O=O;m.S=S
 m.ST.update(schema='ec-owner-only-runtime-captured-target-parity/1',**ident(os.getpid()),functional_baseline=BASE,derived_hardware=HW,
  started_utc=now(),fpga_access=False,production_admission=False,whole_fit=False,no_compile=True,results={});m.update(status='STARTED_RUNTIME_ONLY')
 for label in ['Plain','MCRams']:
  m.guard();item=plan['models'][label];run_dir=O/label/'run';run_dir.mkdir(parents=True)
  args=[item['binary']]+['+print-file='+str(run_dir/'rtl-prints-') if a.startswith('+print-file=') else a for a in plan['reference_args'][1:]]
  rr=m.stage('run-'+label,args,run_dir,{**os.environ,**item['environment']},timeout=plan['host_timeout_seconds'],budget=plan['owned_log_budget_bytes'])
  # parse_run's generated binary location differs: construct the same parser
  # logic without copying/rebuilding the existing authenticated executable.
  symlink=O/label/'host'/('VOwnerPair'+label);symlink.parent.mkdir(exist_ok=True);symlink.symlink_to(item['binary'])
  metric=m.parse_run(label,rr,plan['application_expected_output']);m.ST['results'][label]=metric;save(O/label/'run-result.json',metric);m.update()
 a=m.ST['results']['Plain'];b=m.ST['results']['MCRams'];rows=bool(a['target_rows']) and a['target_rows']==b['target_rows'];streams=bool(a['captured_print_streams']) and len(a['captured_print_streams'])>=2 and a['captured_print_streams']==b['captured_print_streams']
 ok=a['output_correctness'] and b['output_correctness'] and rows and streams
 m.update(status='PASS_SAME_3656_CANNEAL_CAPTURED_TARGET_CYCLES_OUTPUT_EVENTS_NOT_FULL_EQUIVALENCE' if ok else 'FAILED_FINITE_CAPTURED_PARITY_PRESERVED',
  captured_finite_parity_passed=ok,exact_target_rows=rows,exact_print_streams=streams,completed_utc=now(),
  limitations=['Finite captured observations only; not universal formal equivalence','No FPGA, whole FIT, strict checkerDone-minusBOOMDone, or full BOOM drain claim'])
 save(O/'result.json',m.ST)
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--prepare-when-ready',action='store_true');p.add_argument('--run',action='store_true');a=p.parse_args()
 try:prepare() if a.prepare_when_ready else run()
 except Exception as e:
  report('FAILED_WITH_EVIDENCE',error=repr(e));raise
