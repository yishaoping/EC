#!/usr/bin/python3
"""External read-only observer: new main, exact old model archive, bounded probes.

No FPGA access. A successful startup comparison is not checker admission.
The subsequent same-ELF run must validate every observed BOOM acceptance.
"""
from pathlib import Path
import datetime
import fcntl
import hashlib
import json
import os
import re
import resource
import shlex
import shutil
import signal
import subprocess
import sys
import time
import traceback

W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C=Path(__file__).resolve().parent
U=D/'unattended-opt4'
B=D/'cycleprecise-frozen-full-metasim-r1-20261111'
OBJ=B/'host/VFrozenOpt4.csrc'
REF=D/'cycleprecise-frozen-full-metasim-sample-r1-20261111'
OUT=D/'cycleprecise-frozen-full-gg-external-observer-r4-20261111'
STATE=D/'Opt4-full-gg-external-observer-r4-state.json'
NAME='full-gg-external-observer-r4-8491167d'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
CLANG='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'
VINC=Path('/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/share/verilator/include')
ST={}

def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def read(p):return json.loads(Path(p).read_text())
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for b in iter(lambda:f.read(4*2**20),b''):h.update(b)
 return h.hexdigest()
def save(p,v):
 p=Path(p);p.parent.mkdir(exist_ok=True,parents=True);tmp=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with tmp.open('x') as f:json.dump(v,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(tmp,p)
 fd=os.open(p.parent,os.O_RDONLY|os.O_DIRECTORY);os.fsync(fd);os.close(fd)
def ident(pid):
 try:
  f=Path(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split()
  return dict(pid=pid,start_ticks=f[19],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def policy():
 p=read(U/'campaign-policy.json')
 assert p['functional_baseline_commit']==BASE and p['area_equivalence_only']
 assert not p['functional_extensions_allowed'] and p['native_paused'] and not p['fpga_access']
 assert p['board_allowlist']==['0000:21:00.0']
def update(**v):
 ST.update(v,updated_utc=now());save(STATE,ST)

def prepare():
 policy();assert not OUT.exists() and not STATE.exists() and not (C/'plan.json').exists()
 ref=read(REF/'binding.json');assert ref['functional_baseline']==BASE
 assert sha(B/'host/VFrozenOpt4')==ref['binary_sha256']
 assert sha(B/'host/FireSim-generated.sv')=='27362c56925b674288d37039c749ec9fbdd1a2e62141aac6d072022fd4d60885'
 prefix='emul__DOT__FPGATop__DOT__sim__DOT__target__DOT__FireSim___DOT__'
 system=prefix+'lazyModule__DOT__system__DOT__'
 boom=system+'tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__'
 src=(C/'observer_main.cpp.in').read_text().replace('@BOOM@',boom).replace('@SYS@',system).replace('@CLOCK@',prefix)
 (C/'observer_main.cpp').write_text(src)
 compile_args=[CLANG,'-std=c++20','-O1','-DVL_TIME_CONTEXT','-DVERILATOR','-I'+str(VINC),'-I'+str(VINC/'vltstd'),'-I'+str(OBJ),'-c',str(C/'observer_main.cpp'),'-o',str(C/'observer_main.o')]
 log=D/'cycleprecise-frozen-full-metasim-follow-r2-20261111/link-repair.log'
 old=shlex.split(next(l for l in log.read_text().splitlines() if l.startswith('clang++ ')))
 link=[CLANG]
 for a in old[1:]:
  if a.endswith('.o') or a.endswith('.a'):
   if not a.startswith('/'):a=str(OBJ/a)
  link.append(a)
 target=C/'VFrozenOpt4Observed'
 link[link.index('-o')+1]=str(target)
 link.insert(link.index(str(OBJ/'Vemul__ALL.a')),str(C/'observer_main.o'))
 external=[B/'host/VFrozenOpt4',B/'host/FireSim-generated.sv',log,REF/'binding.json',REF/'result.json',B/'binding.json']
 external += [Path(a) for a in link if a.startswith('/') and Path(a).suffix in ['.o','.a'] and Path(a)!=C/'observer_main.o']
 external += sorted(OBJ.glob('*.h'))
 external += [OBJ/'Vemul__main.cpp',OBJ/'Vemul___024root__0.cpp',OBJ/'Vemul___024root__31.cpp']
 elf=Path(next(a[len('+prog0='):] for a in ref['args'] if a.startswith('+prog0=')))
 external += [elf,REF/'rtl-prints-0',REF/'rtl-prints-1']
 assert sha(elf)==ref['elf_sha256']
 hashes={str(p):sha(p) for p in external}
 contract=dict(schema='ec-gg-external-sampling-contract/1',functional_baseline=BASE,
  generated_host_rtl=str(B/'host/FireSim-generated.sv'),
  clock='clockBridge_clocks_0_buffer_O',clock_source='BUFGCE(hostClock, clockBridge_clocks_0_enabled & targetCycleFinishing & ~hostReset)',
  generated_trigger='Vemul___024root__0.cpp eval_triggers_vec__act__0 bit 4 detects this actual output posedge',
  pre_values='Snapshot at the prior settled evaluation before an actual BUFGCE posedge; never sample only post-eval combinational ready/valid',
  finite_validation=['actual BOOM edge vs tCycleFastest increment on every edge','accepted vector population vs completed counter increment on every nonreset edge','per-status increments vs PASS/FAIL/CANCEL counters','accepted pre-cycle vs stored lastCheckerResultCycle','no completion changes without actual BOOM edge'],
  hardware_source=str(W/'C4/chipyard/generators/boom/src/main/scala/lsu/dcache.scala'),
  result_boundary='resultAccepted(i): valid, known status, matching allocated sequence, not completed/stale/duplicate; this is BOOM consumption, not checker local enqueue',
  csr_timestamp='DCache crossPackageBarrierStats.io_currentCycle aliases io.csr_cycle and is exactly RHS of lastCheckerResultCycle in generated C++',
  unobserved=['architectural restore/restart','complete SVB capture/promote/ACK payload','BOOM execution completion of the same checker package'],
  limitation='Runtime checks establish finite sampling consistency; not universal formal equivalence. Strict checkerDone-minusBOOMDone remains unavailable.',
  fpga_access=False)
 save(C/'sampling-contract.json',contract)
 plan=dict(schema='ec-gg-external-observer-plan/1',functional_baseline=BASE,source_id=read(B/'binding.json')['source_id'],
  external_inputs=hashes,compile_args=compile_args,link_args=link,binary=str(target),reference_args=ref['args'],
  probe_limit=10000,full_limit=5000000,host_timeout_seconds=10800,probe_timeout_seconds=240,
  owned_log_budget_bytes=4*2**30,address_space_limit_gib=24,cpu_affinity_limit=2,
  elf_sha256=ref['elf_sha256'],created_utc=now(),fpga_access=False)
 save(C/'plan.json',plan)
 bound={str(p):sha(p) for p in [C/'extend_observer.py',C/'controller.py',C/'observer_main.cpp.in',C/'observer_main.cpp',C/'sampling-contract.json',C/'plan.json']}
 req=dict(action='cpu_job',spec=dict(name=NAME,kind='analysis',cwd=str(C),argv=['/usr/bin/python3',str(C/'controller.py'),'--run'],inputs=bound,
  outputs=[str(OUT/'result.json')],checkpoints=[str(STATE)]))
 save(C/'request.json',req)
 print(json.dumps(dict(prepared=str(C/'plan.json'),request=str(C/'request.json'),external_files=len(hashes),runtime_started=False)))

def command(argv,log):
 with log.open('xb',buffering=0) as out:
  p=subprocess.Popen(argv,cwd=C,stdin=subprocess.DEVNULL,stdout=out,stderr=subprocess.STDOUT)
  update(child=ident(p.pid),command=argv)
  rc=p.wait()
 assert rc==0,('compile_or_link_failed',rc,str(log))

def run_model(name,binary,enabled,limit,plan):
 out=OUT/name
 result=out/'result.json'
 if result.exists():return read(result)
 assert not out.exists(),('preserve_incomplete_attempt_new_version_required',str(out))
 out.mkdir()
 args=[str(binary) if i==0 else '+max-cycles='+str(limit) if a.startswith('+max-cycles=') else '+print-file='+str(out/'rtl-prints-') if a.startswith('+print-file=') else a for i,a in enumerate(plan['reference_args'])]
 env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'1'}
 env.pop('EC_EXTERNAL_OBSERVER_FILE',None)
 if enabled:env['EC_EXTERNAL_OBSERVER_FILE']=str(out/'external-events.jsonl')
 save(out/'binding.json',dict(args=args,binary_sha256=sha(binary),elf_sha256=plan['elf_sha256'],plan_sha256=sha(C/'plan.json'),observer_enabled=enabled,functional_baseline=BASE,fpga_access=False))
 started=time.monotonic();cause=None
 with (out/'host.log').open('xb',buffering=0) as log:
  p=subprocess.Popen(['/usr/bin/stdbuf','-oL','-eL',*args],cwd=out,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,env=env,start_new_session=True)
  update(status='RUNNING_'+name.upper().replace('-','_'),child=ident(p.pid),run_directory=str(out))
  while True:
   try:rc=p.wait(timeout=30)
   except subprocess.TimeoutExpired:rc=None
   size=sum(q.stat().st_size for q in out.iterdir() if q.is_file())
   hb=out/'heartbeat.csv'
   heartbeat=hb.read_text().splitlines()[-1] if hb.exists() else None
   update(host_wall_seconds=time.monotonic()-started,owned_log_bytes=size,heartbeat_last_row=heartbeat,process_exited=rc is not None)
   os.fsync(log.fileno())
   if rc is not None:break
   if size>plan['owned_log_budget_bytes']:cause='LOG_BUDGET'
   if time.monotonic()-started>(plan['probe_timeout_seconds'] if limit==plan['probe_limit'] else plan['host_timeout_seconds']):cause='TIMEOUT'
   if cause:
    os.killpg(p.pid,signal.SIGTERM)
    try:rc=p.wait(timeout=15)
    except subprocess.TimeoutExpired:os.killpg(p.pid,signal.SIGKILL);rc=p.wait()
    break
 raw=(out/'host.log').read_text(errors='replace')
 m=re.findall(r'Target Cycles Emulated:\s*(\d+)',raw)
 target=int(m[-1]) if m else None
 prints={p.name:sha(p) for p in out.glob('rtl-prints-*')}
 obs=None;event_count=0
 if enabled:
  lines=(out/'external-events.jsonl').read_text().splitlines()
  event_count=len(lines)
  obs=json.loads(lines[-1]) if lines else None
  if not obs or obs.get('kind')!='END':cause=cause or 'INCOMPLETE_OBSERVER_TAIL'
 rows=[l.rstrip('\r') for l in raw.splitlines() if any(k in l for k in ('[ROI]','[OUTPUT]','[APP]','[COMPUTATION]','[END]'))]
 faults=[l for l in raw.splitlines() if re.search(r'Assertion failed|%Error|status=FAIL|Simulator deadlock detected',l)]
 value=dict(returncode=rc,stop_cause=cause,host_wall_seconds=time.monotonic()-started,target_cycles=target,print_streams=prints,observer_summary=obs,
  event_lines=event_count,application_rows=rows,faults=faults,completed_utc=now(),fpga_access=False,
  files={str(p):sha(p) for p in out.iterdir() if p.is_file() and p.name!='result.json'})
 save(result,value);return value

def run():
 policy()
 assert not OUT.exists() and not STATE.exists(),'adopt existing job; do not duplicate'
 OUT.mkdir();lock=(OUT/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 plan=read(C/'plan.json')
 ST.update(schema='ec-gg-external-observer-state/1',**ident(os.getpid()),functional_baseline=BASE,fpga_access=False,started_utc=now())
 update(status='VALIDATING_EXTERNAL_INPUTS')
 for p,h in plan['external_inputs'].items():assert sha(p)==h,('changed_original_input',p)
 os.sched_setaffinity(0,sorted(os.sched_getaffinity(0))[:plan['cpu_affinity_limit']])
 resource.setrlimit(resource.RLIMIT_AS,(plan['address_space_limit_gib']*2**30,)*2)
 assert int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))>=48*2**20
 assert shutil.disk_usage(OUT).free>=40*2**30
 update(status='COMPILING_REPLACEMENT_MAIN_ONLY')
 command(plan['compile_args'],OUT/'compile.log')
 update(status='RELINKING_EXISTING_MODEL_ARCHIVE_ONLY')
 command(plan['link_args'],OUT/'link.log')
 save(OUT/'build-receipt.json',dict(binary_sha256=sha(plan['binary']),original_model_archive_sha256=plan['external_inputs'][str(OBJ/'Vemul__ALL.a')],only_new_compilation=str(C/'observer_main.cpp'),target_rtl_modified=False,model_objects_rebuilt=False,plan_sha256=sha(C/'plan.json')))
 baseline=run_model('probe-original',B/'host/VFrozenOpt4',False,plan['probe_limit'],plan)
 off=run_model('probe-observer-off',plan['binary'],False,plan['probe_limit'],plan)
 on=run_model('probe-observer-on',plan['binary'],True,plan['probe_limit'],plan)
 samples=[baseline,off,on]
 passed=all(s['returncode']==1 and s['stop_cause'] is None and not s['faults'] and s['target_cycles']==10001 for s in samples)
 passed &= all('*** FAILED *** simulation timed out after 10001 cycles' in (OUT/name/'host.log').read_text() for name in ['probe-original','probe-observer-off','probe-observer-on'])
 passed &= baseline['print_streams']==off['print_streams']==on['print_streams'] and baseline['application_rows']==off['application_rows']==on['application_rows']
 passed &= bool(on['observer_summary'] and on['observer_summary']['sample_errors']==0 and on['observer_summary']['boom_edges']>0)
 probe=dict(status='PASS_FINITE_STARTUP_ON_OFF_PARITY' if passed else 'FAILED_WITH_EVIDENCE',passed=passed,original=baseline,observer_off=off,observer_on=on,
  scope='10000-cycle startup probe only; not application/checker acceptance proof',completed_utc=now(),fpga_access=False)
 save(OUT/'probe-result.json',probe)
 if passed:
  save(OUT/'result.json',dict(status='PREPARED_AND_PROBE_PASSED_FULL_CANNEAL_DEFERRED',probe_result_sha256=sha(OUT/'probe-result.json'),fpga_access=False,full_runtime_started=False,predecessor=str(D/'cycleprecise-frozen-full-gg-external-observer-r3-20261111/result.json'),rule='Only predecessor completed and finite BOOM acceptance valid; separate immutable --full request',completed_utc=now()))
  update(status='PREPARED_AND_PROBE_PASSED_FULL_CANNEAL_DEFERRED',child={},process_exited=True)
  return
 if not passed:
  save(OUT/'result.json',probe);update(status='PROBE_FAILED_WITH_EVIDENCE',child={},process_exited=True);return

def full_only():
 policy()
 assert (OUT/'probe-result.json').exists() and read(OUT/'probe-result.json')['passed']
 prior=D/'cycleprecise-frozen-full-gg-external-observer-r3-20261111/result.json'
 assert prior.exists(),'WAITING_PREDECESSOR_COMPLETION'
 assert read(prior).get('valid_finite_observation'),'PREDECESSOR_OBSERVER_NOT_VALIDATED'
 lock=(OUT/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 plan=read(C/'plan.json')
 for p,h in plan['external_inputs'].items():assert sha(p)==h,('changed_original_input',p)
 os.sched_setaffinity(0,sorted(os.sched_getaffinity(0))[:plan['cpu_affinity_limit']])
 resource.setrlimit(resource.RLIMIT_AS,(plan['address_space_limit_gib']*2**30,)*2)
 ST.update(schema='ec-gg-external-observer-state/1',**ident(os.getpid()),functional_baseline=BASE,fpga_access=False,started_utc=now())
 full=run_model('canneal-observer-on',plan['binary'],True,plan['full_limit'],plan)
 ref=read(REF/'result.json')
 expected_prints={p.name:sha(p) for p in REF.glob('rtl-prints-*')}
 ref_raw=(REF/'host.log').read_text(errors='replace')
 ref_rows=[l.rstrip('\r') for l in ref_raw.splitlines() if any(k in l for k in ('[ROI]','[OUTPUT]','[APP]','[COMPUTATION]','[END]'))]
 obs=full['observer_summary'] or {}
 exact=(full['print_streams']==expected_prints and full['application_rows']==ref_rows and full['target_cycles']==1759002)
 valid=full['returncode']==0 and full['stop_cause'] is None and not full['faults'] and exact and obs.get('sample_errors')==0 and obs.get('accepted',0)>0
 result=dict(status='PASS_SAME_ELF_CAPTURED_PARITY_AND_FINITE_BOOM_ACCEPTANCE' if valid else 'FULL_RUN_FAILED_OR_UNPROVEN_WITH_EVIDENCE',valid_finite_observation=valid,
  original_prints_and_application_and_target_count_match=exact,observer_summary=obs,full=full,probe_result_sha256=sha(OUT/'probe-result.json'),
  functional_baseline=BASE,elf_sha256=plan['elf_sha256'],source_id=plan['source_id'],plan_sha256=sha(C/'plan.json'),fpga_access=False,formal_fpga_sample=False,
  limitations=['Finite workload, not universal formal equivalence','No strict checkerDone minus same-package BOOMDone','No architectural restore/restart verification','No SVB full payload replay until separately captured'],completed_utc=now())
 save(OUT/'result.json',result);update(status=result['status'],child={},process_exited=True,result=str(OUT/'result.json'))

if __name__=='__main__':
 try:{'--prepare':prepare,'--run':run,'--full':full_only}[sys.argv[1]]()
 except BaseException as e:
  if OUT.exists():
   save(OUT/'failure.json',dict(error=repr(e),traceback=traceback.format_exc(),utc=now()))
   update(status='FAILED_WITH_EVIDENCE',error=repr(e))
  raise
