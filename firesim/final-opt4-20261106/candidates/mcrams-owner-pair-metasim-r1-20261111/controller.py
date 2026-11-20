#!/usr/bin/python3
"""Serial two-model CPU compilation and same-target finite Canneal parity.
No GoldenGate regeneration, Vivado, FPGA, or changes to previous models.
"""
import argparse, datetime, fcntl, hashlib, json, os, pathlib, re, resource, shutil, signal, subprocess, time
P=pathlib.Path;C=P(__file__).resolve().parent
W=P('/data1/gzh/EC/firesim/final-opt4-20261106');D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'cycleprecise-owner-pair-metasim-r1-20261111';S=D/'Opt4-mcrams-owner-pair-metasim-r1-state.json'
BASE='8491167d84b6d9521b151a743673c1516926a1f8';HW='3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
ST={}
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
def ident(pid=None):
 pid=pid or os.getpid()
 try:
  s=P(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=s[19],host_boot_id=P('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def update(**kw):ST.update(kw,updated_utc=now());save(S,ST)
def verify(plan):
 for p,h in {**plan['original_inputs'],**plan['staged_inputs']}.items():assert sha(p)==h,('input version changed',p)
def guard():
 while True:
  mem=int(next(l.split()[1] for l in P('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))
  if mem>=96*2**20 and shutil.disk_usage(O).free>=100*2**30:return
  update(status='WAITING_CPU_MEMORY_DISK_GUARDS',available_memory_kib=mem,free_disk_bytes=shutil.disk_usage(O).free);time.sleep(300)
def stage(n,argv,cwd,env,outputs=(),timeout=None,budget=None):
 receipt=O/'receipts'/(n+'.json');log=O/(n+'.log')
 if receipt.exists():
  r=read(receipt)
  if r['returncode']==0 and r['stop_cause'] is None and all(P(p).is_file() and sha(p)==h for p,h in r['outputs'].items()):return r
  return r # Failed sample evidence remains; other model proceeds.
 assert not log.exists(),'partial stage preserved; independent reviewed recovery required'
 start=time.monotonic();update(status='RUNNING_'+n.upper().replace('-','_'),stage=n)
 with log.open('xb',buffering=0) as f:
  p=subprocess.Popen(argv,cwd=cwd,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
  update(child=ident(p.pid),log=str(log));cause=None
  while p.poll() is None:
   try:p.wait(timeout=30)
   except subprocess.TimeoutExpired:pass
   elapsed=time.monotonic()-start
   if timeout and elapsed>timeout:cause='HOST_TIMEOUT'
   if budget and sum(q.stat().st_size for q in P(cwd).glob('*') if q.is_file())>budget:cause='OWNED_LOG_BUDGET'
   if cause and p.poll() is None:
    # Only the freshly created private CPU process group owned by this stage.
    os.killpg(p.pid,signal.SIGTERM)
    try:p.wait(timeout=20)
    except subprocess.TimeoutExpired:os.killpg(p.pid,signal.SIGKILL);p.wait()
   os.fsync(f.fileno());update(host_wall_seconds=elapsed,stop_cause=cause)
  rc=p.returncode
 r=dict(stage=n,returncode=rc,stop_cause=cause,host_wall_seconds=time.monotonic()-start,ended_utc=now(),
   log=str(log),log_sha256=sha(log),outputs={str(p):sha(p) for p in outputs if P(p).is_file()},argv=argv)
 save(receipt,r);update(child={},last_receipt=str(receipt));return r
def parse_run(label,receipt,expected):
 run=O/label/'run';rows=[];metrics=[];fault=[]
 for line in P(receipt['log']).read_text(errors='replace').splitlines():
  if any(x in line for x in ['[ROI]','[OUTPUT]','[APP]','[COMPUTATION]','[END]']):rows.append(line.rstrip())
  if any(x in line for x in ['Target Cycles Emulated:','FMR:','Wallclock Time Elapsed:','Effective Target Frequency:']):metrics.append(line.rstrip())
  if re.search(r'Assertion failed|%Error|\*\*\* FAILED|status=FAIL|Simulator deadlock detected',line):fault.append(line.rstrip())
 correct=(receipt['returncode']==0 and receipt['stop_cause'] is None and not fault and any(expected in r for r in rows)
   and '[COMPUTATION] status=PASS scope=official_serial_kernel' in rows and '[END] hart=0 status=PASS' in rows)
 return dict(output_correctness=correct,target_rows=rows,host_metrics=metrics,faults=fault,
   host_wall_seconds=receipt['host_wall_seconds'],returncode=receipt['returncode'],stop_cause=receipt['stop_cause'],
   captured_print_streams={p.name:sha(p) for p in sorted(run.glob('rtl-prints-*')) if p.is_file()},
   binary_sha256=sha(O/label/'host'/('VOwnerPair'+label)))
def run():
 plan=read(C/'plan.json');O.mkdir(parents=True,exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 assert not S.exists(),'existing controller/state must be adopted, not restarted'
 assert {250,251}<=set(os.sched_getaffinity(0));os.sched_setaffinity(0,{250,251});resource.setrlimit(resource.RLIMIT_AS,(64*2**30,64*2**30))
 ST.update(schema='ec-owner-only-same-target-finite-parity/1',**ident(),started_utc=now(),functional_baseline=BASE,
  derived_hardware=HW,fpga_access=False,production_admission=False,whole_fit=False,cpus=[250,251],results={})
 update(status='VERIFYING_INPUTS');verify(plan)
 for label in ['Plain','MCRams']:
  guard();info=plan['models'][label];sub=O/label;host=sub/'host';run_dir=sub/'run';run_dir.mkdir(exist_ok=True)
  env={**os.environ,**info['environment']};binary=P(info['binary'])
  compile_r=stage('compile-'+label,info['command'],C,env,[binary])
  if compile_r['returncode']!=0 or not binary.exists():
   ST['results'][label]=dict(status='COMPILE_FAILED_PRESERVED',receipt=str(O/'receipts'/('compile-'+label+'.json')));update();continue
  args=[str(binary)]+['+print-file='+str(run_dir/'rtl-prints-') if a.startswith('+print-file=') else a for a in plan['reference_args'][1:]]
  # Inputs, target timing model, ROI and software are identical across hosts.
  assert args[1:]==['+print-file='+str(run_dir/'rtl-prints-') if a.startswith('+print-file=') else a for a in plan['reference_args'][1:]]
  rr=stage('run-'+label,args,run_dir,env,timeout=plan['host_timeout_seconds'],budget=plan['owned_log_budget_bytes'])
  metric=parse_run(label,rr,plan['application_expected_output']);ST['results'][label]=metric;save(sub/'run-result.json',metric);update()
 a=ST['results'].get('Plain',{});b=ST['results'].get('MCRams',{});streams=a.get('captured_print_streams',{})
 rows=a.get('target_rows')==b.get('target_rows') and bool(a.get('target_rows'))
 prints=streams==b.get('captured_print_streams') and len(streams)>=2
 passed=a.get('output_correctness') and b.get('output_correctness') and rows and prints
 status='PASS_SAME_3656_TARGET_CANNEAL_CAPTURED_CYCLES_OUTPUT_EVENTS_NOT_FULL_EQUIVALENCE' if passed else 'FAILED_OR_INCOMPLETE_SAME_TARGET_PARITY_PRESERVED'
 update(status=status,completed_utc=now(),exact_target_rows=rows,exact_target_print_streams=prints,
   captured_finite_parity_passed=bool(passed),limitations=['Finite captured observations only; not universal full-state equivalence',
   'BOOM acceptance/full-drain and strict checker latency require additional real completion observation',
   'Derived3656 implementation remains distinct from frozen RTL; no FPGA/whole FIT or formal PARSEC sample claim'])
 save(O/'result.json',ST)
def prepare():
 assert not (C/'plan.json').exists() and not O.exists()
 old=D/'cycleprecise-frozen-full-metasim-r1-20261111';pb=read(old/'binding.json')
 reference=D/'cycleprecise-frozen-full-metasim-sample-r1-20261111/binding.json';rb=read(reference)
 srcroot=W/'Opt4-fit-dcache-field-read-prune-r1-20261111/builds/system-3656aec4-r4'
 mc=D/'build-logs/Opt4-mcrams-dcache-owner-system-r1-20261111';audit=D/'build-logs/Opt4-mcrams-dcache-owner-audit-r3-20261111'
 assert read(audit/'result.json')['target_DCache_nonwrapper_statements_identical']
 sourceplan=read(W/'candidates/mcrams-dcache-owner-system-r1-20261111/plan.json')
 assert all(sha(p)==h for p,h in sourceplan['inputs'].items())
 originals={str(p):sha(p) for p in [reference,old/'binding.json',audit/'result.json',audit/'complete.json',mc/'result.json',mc/'preflight.json',mc/'post-transform-audit.json']}
 originals.update(sourceplan['inputs']);staged={};models={};O.mkdir()
 common_headers=O/'external-headers';common_headers.mkdir()
 for p in (old/'external-headers').iterdir():shutil.copy2(p,common_headers/p.name);originals[str(p)]=sha(p);staged[str(common_headers/p.name)]=sha(p)
 libs=O/'external-libs';libs.mkdir()
 for p in (old/'external-libs').iterdir():
  dest=libs/p.name;dest.symlink_to(p.resolve());originals[str(p.resolve())]=sha(p.resolve())
 for label,src in [('Plain',srcroot/'goldengate'),('MCRams',mc/'goldengate')]:
  sub=O/label;host=sub/'host';host.mkdir(parents=True)
  for name in ['FireSim-generated.sv','FireSim-generated.const.h','FireSim-generated.const.vh','FireSim-generated.defines.vh']:
   p=src/name;originals[str(p)]=sha(p);shutil.copy2(p,host/name);staged[str(host/name)]=sha(p)
  # Some pre-existing GG output already has blackboxes appended. Append only
  # missing definitions to this private plain copy, binding the final bytes.
  sv=host/'FireSim-generated.sv';text=sv.read_text()
  if label=='Plain':
   files=src/'firrtl_black_box_resource_files.f'
   for name in files.read_text().splitlines() if files.exists() else []:
    p=P(name);extra=p.read_text();modules=re.findall(r'(?m)^module\s+(\w+)',extra)
    if modules and all(re.search(r'(?m)^module\s+'+m+r'\b',text) for m in modules):continue
    assert modules and not any(re.search(r'(?m)^module\s+'+m+r'\b',text) for m in modules),'partial duplicate blackbox closure'
    text+='\n'+extra;originals[str(p)]=sha(p)
   sv.write_text(text);staged[str(sv)]=sha(sv)
  p=srcroot/'elaborate/firesim.firesim.FireSim.dromajo_params.h';shutil.copy2(p,host/'dromajo_params.h');originals[str(p)]=sha(p);staged[str(host/'dromajo_params.h')]=sha(p)
  cmd=[a.replace('DRIVER_NAME=FrozenOpt4','DRIVER_NAME=OwnerPair'+label).replace(str(old/'host'),str(host)) for a in pb['command']]
  driver=next(a[len('DRIVER='):] for a in cmd if a.startswith('DRIVER='));static=[p for p in driver.split() if p.endswith('.a')]
  for p in driver.split():originals[p]=sha(p)
  env={k:v.replace(str(old),str(O)) for k,v in pb['environment'].items()}
  env['LDFLAGS']+=' '+' '.join(static)+' -lstdc++ -lpthread -lgmp -l:libdwarf.so -l:libelf.so -lz'
  env.update(MAKEFLAGS='-j2',OMP_NUM_THREADS='2',CCACHE_DISABLE='1',LD_LIBRARY_PATH='')
  models[label]=dict(command=cmd,environment=env,binary=str(host/('VOwnerPair'+label)),host_rtl_sha256=sha(sv),generated_ABI_sha256=sha(host/'FireSim-generated.const.h'))
 fs=W/'C4/chipyard/sims/firesim/sim'
 for root in [fs/'midas/src/main/cc',fs/'firesim-lib/src/main/cc',fs/'src/main/cc/firesim',fs/'midas/src/main/verilog',W/'C4/chipyard/generators/testchipip/src/main/resources/testchipip/csrc']:
  for p in root.rglob('*'):
   if p.is_file() and (p.suffix in ['.h','.hpp','.cc','.v','.sv'] or p.name=='Makefile' or p.name.startswith('Makefrag')):originals[str(p)]=sha(p)
 elf=P(next(a[len('+prog0='):] for a in rb['args'] if a.startswith('+prog0=')));assert sha(elf)==rb['elf_sha256'];originals[str(elf)]=sha(elf)
 plan=dict(schema='ec-owner-only-serial-full-target-pair-plan/1',functional_baseline=BASE,derived_hardware=HW,
  original_inputs=originals,staged_inputs=staged,models=models,reference_args=rb['args'],elf_sha256=rb['elf_sha256'],
  application_expected_output=rb['application_expected_output'],target_cycle_limit=rb['target_cycle_limit'],host_timeout_seconds=rb['host_timeout_seconds'],
  owned_log_budget_bytes=rb['owned_log_budget_bytes'],max_parallel_full_compiles=1,compile_jobs=2,cpu_affinity=[250,251],minimum_memory_gib=96,address_space_limit_gib=64,
  source_id_is_derived=True,source_fir_sha256=sourceplan['inputs'][str(srcroot/'elaborate/firesim.firesim.FireSim.fir')],
  fpga_access=False,production_admission=False,whole_fit=False,created_utc=now())
 save(C/'plan.json',plan);save(O/'build-plan.json',plan)
 inputs={str(C/'controller.py'):sha(C/'controller.py'),str(C/'plan.json'):sha(C/'plan.json')}
 # Broker inputs must be under W. Runtime controller validates original D
 # evidence and private copied RTL without duplicating hundreds of MiB in W.
 for p,h in originals.items():
  if P(p).resolve().is_relative_to(W):inputs[p]=h
 name='owner-pair-metasim-r1-3656aec4';request=dict(action='cpu_job',spec=dict(name=name,kind='module',cwd=str(C),argv=['/usr/bin/python3',str(C/'controller.py'),'--run'],inputs=inputs,outputs=[str(O/'result.json')],checkpoints=[str(S)]))
 save(C/'request.json',request);target=D/'unattended-opt4/requests'/(name+'.json');assert not target.exists();save(target,request)
 print(json.dumps(dict(submitted=str(target),models=models,fpga_access=False)))
if __name__=='__main__':
 ap=argparse.ArgumentParser();ap.add_argument('--prepare',action='store_true');ap.add_argument('--run',action='store_true');a=ap.parse_args()
 try:prepare() if a.prepare else run()
 except Exception as e:
  if ST:update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(O/'failure.json',ST)
  raise
