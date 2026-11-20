#!/usr/bin/python3
"""True single BOOM GG metasimulation preparation and bounded CPU-only build.

Native FPGA campaign stays paused. No target RTL changes, CAD, board access,
checker bypass or EC software modification. Native needs its own boot ABI;
the protected kernel sources/input and counter boundary sequence are retained.
"""
from pathlib import Path
import argparse,datetime,fcntl,hashlib,json,os,re,resource,shutil,subprocess,time,traceback
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U=D/'unattended-opt4';C=Path(__file__).resolve().parent
O=D/'cycleprecise-matched-single-boom-gg-r1-20261112'
S=D/'Opt4-matched-single-boom-gg-r1-state.json'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
SID='be443a3dc2992eb52be4d3da55d687e13e9a21a0dccc1d136a2f23c2c3f436e4'
TEMPLATE=D/'cycleprecise-frozen-full-metasim-r1-20261111'
NAME='matched-single-boom-gg-r1-8491167d'
ST={}
def read(p):return json.loads(Path(p).read_text())
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for block in iter(lambda:f.read(2**20),b''):h.update(block)
 return h.hexdigest()
def save(p,j):
 p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);t=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with t.open('x') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(t,p)
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def ident(pid):
 try:s=Path(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=s[19],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def update(status,**kw):ST.update(status=status,updated_utc=now(),**kw);save(S,ST)
def policy():
 p=read(U/'campaign-policy.json');assert p['functional_baseline_commit']==BASE and p['native_paused'] and not p['fpga_access']
 assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
 assert p['board_allowlist']==['0000:21:00.0']
def copy(p,q,hashes):
 p=Path(p);q=Path(q);q.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(p,q)
 hashes[str(p)]=sha(p);assert sha(q)==hashes[str(p)]
 return q
def command(argv,log,cwd,env=None,timeout=3600):
 start=time.monotonic();assert not log.exists()
 with log.open('xb',buffering=0) as f:
  p=subprocess.Popen(argv,cwd=cwd,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,env=env,start_new_session=True)
  update('RUNNING_OWNED_CPU_STAGE',child=ident(p.pid),argv=argv,log=str(log))
  try:rc=p.wait(timeout=timeout)
  except subprocess.TimeoutExpired:
   os.killpg(p.pid,15)
   try:rc=p.wait(timeout=20)
   except subprocess.TimeoutExpired:os.killpg(p.pid,9);rc=p.wait()
   rc='HOST_TIMEOUT'
  os.fsync(f.fileno())
 result=dict(argv=argv,returncode=rc,host_wall_seconds=time.monotonic()-start,log=str(log),log_sha256=sha(log))
 assert rc==0,('OWNED_CPU_STAGE_FAILED',result)
 return result

NATIVE_MAIN=r'''#include <stdint.h>
#include <stdio.h>
extern volatile uint64_t tohost,fromhost;
extern void workload_prepare(void),workload_run(void);
extern int workload_verify(void);
volatile uint64_t eval_protected __attribute__((section(".eval_mode")))=0;
void __attribute__((noreturn,noinline)) _exit(int code) {
 __asm__ volatile("csrci mstatus,8":::"memory"); fromhost=0;
 tohost=(((uint64_t)(unsigned int)code<<1)|1)&((1ULL<<48)-1);
 __asm__ volatile("fence rw,rw\n1: j 1b":::"memory");__builtin_unreachable();
}
int main(void) {
 uint64_t hart,start,end,is,ie;
 __asm__ volatile("csrr %0,mhartid":"=r"(hart));
 if(hart!=0)return 2;
 printf("[CONFIG] profile=clean-single-boom no_checker=1 threads=1 native_boot_adapter=1\n");
 workload_prepare();
 __asm__ volatile(".global common_roi_start\ncommon_roi_start:\nrdcycle %0\nrdinstret %1":"=r"(start),"=r"(is)::"memory");
 workload_run();
 __asm__ volatile(".global common_roi_stop\ncommon_roi_stop:\nrdinstret %1\nrdcycle %0":"=r"(end),"=r"(ie)::"memory");
 printf("[ROI] hart=0 start=%lu stop=%lu cycles=%lu\n",start,end,end-start);
 int ok=workload_verify();
 printf("[APP] protected=0 start=%lu end=%lu cycles=%lu instret=%lu session_stop=%lu\n",start,end,end-start,ie-is,end);
 printf("[COMPUTATION] status=%s scope=official_serial_kernel\n",ok?"PASS":"FAIL");
 printf("[END] hart=0 status=%s\n",ok?"PASS":"FAIL");return ok?0:1;
}
'''

def prepare():
 policy();assert not (C/'plan.json').exists() and not O.exists(),'ADOPT_EXISTING_VERSION'
 O.mkdir();inputs={str(C/'controller.py'):sha(C/'controller.py')}
 reuse=read(W/'native-reuse.json');assert reuse['source_id']==SID
 receipts={k:read(reuse[k]) for k in ['elaboration_receipt','goldengate_receipt','driver_receipt']}
 for k,j in receipts.items():
  assert j['returncode']==0 and j['source_id']==SID
  assert sha(reuse[k])==reuse[k+'_sha256'];inputs[reuse[k]]=sha(reuse[k])
 g=receipts['goldengate_receipt'];src=Path(g['output_dir']);host=C/'prepared-host';host.mkdir()
 for name in ['FireSim-generated.sv','FireSim-generated.const.h','FireSim-generated.const.vh','FireSim-generated.defines.vh']:
  assert sha(src/name)==g['outputs'][str(src/name)]
  copy(src/name,host/name,inputs)
 text=(host/'FireSim-generated.sv').read_text();appended=[]
 for line in (src/'firrtl_black_box_resource_files.f').read_text().splitlines():
  if not line.strip():continue
  p=Path(line.strip());s=p.read_text();names=re.findall(r'^\s*module\s+(\w+)',s,re.M)
  inputs[str(p)]=sha(p)
  if not all(re.search(r'\bmodule\s+'+n+r'\b',text) for n in names):text+='\n'+s;appended.append(str(p))
 if appended:(host/'FireSim-generated.sv').write_text(text)
 old=Path(receipts['driver_receipt']['output_dir'])
 if (old/'dromajo_params.h').exists():copy(old/'dromajo_params.h',host/'dromajo_params.h',inputs)
 for folder in ['external-headers','external-libs']:
  (C/folder).mkdir()
  for p in (TEMPLATE/folder).iterdir():
   if p.is_file():copy(p.resolve(),C/folder/p.name,inputs)
 for p in list((C/'external-libs').glob('*.so')):
  s=subprocess.check_output(['/usr/bin/readelf','-d',str(p)],text=True)
  match=re.search(r'\(SONAME\).*?\[(.*?)\]',s)
  if match and not (p.parent/match[1]).exists():(p.parent/match[1]).symlink_to(p.name)
 # Software: only the Native startup/EC ABI glue changes; frozen kernels and
 # embedded inputs are independently hashed and retained byte for byte.
 final=read('/data1/gzh/EC/slowdown/final_opt4_freeze_20261106/data/FINAL_RUNS.json')
 software=[]
 for workload in ['canneal_project400','blackscholes_project64']:
  entry=next(x for x in final if x['workload']==workload and x['mode']=='correction')
  manifest=Path(entry['manifest']['absolute_path']);assert sha(manifest)==entry['manifest']['sha256'];mf=read(manifest)
  sw=mf['software'];assert mf['canonical_hardware_commit']==BASE
  original=Path(sw['commands'][0][-1]).parent;source=original/'source'
  work=C/'software'/workload;work.mkdir(parents=True)
  target=work/'source';shutil.copytree(source,target,ignore=shutil.ignore_patterns('Benchmark','.git'))
  sourcechecks={}
  for name,h in sw['source_sha256'].items():
   p=source/name;q=target/name
   if not q.is_file():continue
   assert sha(p)==h and sha(q)==h,('FROZEN_SOFTWARE_SOURCE_CHANGED',str(p))
   inputs[str(p)]=h;sourcechecks[name]=h
  shutil.copy2(target/'test.c',work/'ec-original-test.c')
  (target/'test.c').write_text(NATIVE_MAIN)
  # GCC searches this link-script name in cwd as well as -L support.
  if (original/'htif.ld').exists():copy(original/'htif.ld',work/'htif.ld',inputs)
  commands=[]
  for oldcmd in sw['commands']:
   cmd=[str(a).replace(str(original),str(work)) for a in oldcmd]
   commands.append(cmd)
  elf=work/'protected.riscv'
  software.append(dict(workload=workload,commands=commands,cwd=str(work),elf=str(elf),
      expected_output=mf['output'],protected_reference_elf_sha256=mf['elf_sha256'],
      reference_manifest=str(manifest),reference_manifest_sha256=sha(manifest),
      kernel_and_input_source_sha256={k:v for k,v in sourcechecks.items() if k!='test.c'},
      original_main_sha256=sourcechecks['test.c'],native_main_sha256=sha(target/'test.c'),
      source_unchanged_except=['test.c'],roi_scope=sw['roi_scope'],threads=sw['threads'],
      original_software_scope={k:sw.get(k) for k in ['input_class','input_sha256','iterations','swaps_per_temperature','start_temperature','options','seed']},
      software_layout_identical=False,limitation='Native boot glue and link layout differ; original algorithm,embedded input,compilerflags,threads,and ROI counter order preserved. Not sameELF.'))
 # Reuse the original matching generic FireSim driver sources, compile them
 # against Native's own generated header and address map, never an EC ABI.
 pb=read(TEMPLATE/'binding.json');out=O/'host';out.mkdir()
 for p in host.iterdir():copy(p,out/p.name,inputs)
 commandline=[a.replace('DRIVER_NAME=FrozenOpt4','DRIVER_NAME=MatchingNative')
              .replace(str(TEMPLATE/'host'),str(out)).replace('-j2','-j8') for a in pb['command']]
 driverarg=next(a for a in commandline if a.startswith('DRIVER='));libs=[]
 for p in driverarg[len('DRIVER='):].split():
  inputs[p]=sha(p)
  if p.endswith('.a'):libs.append(p)
 env={k:v.replace(str(TEMPLATE),str(C)) for k,v in pb['environment'].items()}
 env['LDFLAGS']+=' '+' '.join(libs)+' -lstdc++ -lpthread -lgmp -l:libdwarf.so -l:libelf.so -lz'
 env.update(MAKEFLAGS='-j8',OMP_NUM_THREADS='1',CCACHE_DISABLE='1',LD_LIBRARY_PATH='')
 # Source/ABI audit is explicit and must never silently run EC startup on Native.
 config=W/'Native/chipyard/generators/chipyard/src/main/scala/config/DacBaselineConfig.scala'
 nativecore=W/'Native/chipyard/generators/boom/src/main/scala/common/config-mixins.scala'
 inputs[str(config)]=sha(config);inputs[str(nativecore)]=sha(nativecore)
 assert 'WithDacMatchedBoom(1' in config.read_text() and 'WithNGCCheckers' not in config.read_text()
 plan=dict(schema='ec-clean-single-boom-matching-gg/1',functional_baseline=BASE,native_source_id=SID,
   native_configuration='Clean DacBaseline WithDacMatchedBoom(1),noRocket/checker/EC',
   reuse_receipt=str(W/'native-reuse.json'),source_host_rtl=str(src/'FireSim-generated.sv'),
   source_host_rtl_sha256=sha(src/'FireSim-generated.sv'),host_rtl_sha256=sha(out/'FireSim-generated.sv'),
   only_blackbox_resource_appended=appended,command=commandline,environment=env,
   binary=str(out/'VMatchingNative'),software=software,original_inputs=inputs,
   common_target_boom_hz=200000000,memory_plusargs=['+mm_readLatency_0=30','+mm_readMaxReqs_0=4','+mm_relaxFunctionalModel_0=0','+mm_writeLatency_0=30','+mm_writeMaxReqs_0=4'],
   max_cpus=8,address_space_limit_gib=64,compile_timeout_seconds=10800,
   native_fpga_paused=True,fpga_access=False,rtl_modified=False,
   same_protected_elf_usable_on_native=False,abi_reason='Original test_setup unconditionally calls r_ini/GHT/RoCC before eval_protected branch;cleanNative has no customhardware.IndependentNativeboot adapter required; no silenttrapignore.',
   ready_for_performance_pair=False,stage='PREPARED_SOURCE_ABI_AUDIT_NOT_COMPILED',created_utc=now())
 save(C/'plan.json',plan)
 # All executable/source inputs must remain under the campaign root. Stage
 # external evidence and tools as immutable hash receipts; actual sources are
 # rechecked against original_inputs before a compiler is invoked.
 capsule=C/'evidence';capsule.mkdir();bound={}
 for q,h in inputs.items():
  p=Path(q)
  if p.resolve().is_relative_to(W):bound[str(p)]=h
  else:
   dest=capsule/(h[:16]+'-'+p.name)
   if not dest.exists():shutil.copy2(p,dest)
   assert sha(dest)==h;bound[str(dest)]=h
 for root in [C/'prepared-host',C/'software',C/'external-headers',C/'external-libs']:
  for p in root.rglob('*'):
   if p.is_file() and not p.is_symlink():bound[str(p)]=sha(p)
 bound[str(C/'controller.py')]=sha(C/'controller.py');bound[str(C/'plan.json')]=sha(C/'plan.json')
 req=dict(action='cpu_job',spec=dict(name=NAME,kind='analysis',cwd=str(C),argv=['/usr/bin/python3',str(C/'controller.py'),'--run'],
    inputs=bound,outputs=[str(O/'compile-result.json'),str(O/'software-build.json'),str(O/'boot-probe.json')],checkpoints=[str(S)]))
 save(C/'request.json',req)
 dest=U/'requests'/(NAME+'.json');assert not dest.exists();save(dest,req)
 print(json.dumps(dict(status='SOURCE_ABI_AUDIT_COMPLETE_CPU_COMPILE_SUBMITTED',request=str(dest),input_files=len(bound),host_rtl_mb=(out/'FireSim-generated.sv').stat().st_size/2**20,max_cpus=8,max_address_space_gib=64,fpga_access=False),indent=2))

def run():
 policy();p=read(C/'plan.json');O.mkdir(exist_ok=True)
 lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 ST.update(schema=p['schema'],**ident(os.getpid()),functional_baseline=BASE,native_source_id=SID,fpga_access=False,native_fpga_paused=True)
 os.nice(5);allowed=sorted(os.sched_getaffinity(0));os.sched_setaffinity(0,allowed[-8:])
 resource.setrlimit(resource.RLIMIT_AS,(64*2**30,64*2**30))
 assert shutil.disk_usage(O).free>12*2**30
 for q,h in p['original_inputs'].items():assert sha(q)==h,('SOURCE_CHANGED_BEFORE_COMPILE',q)
 built=[]
 for s in p['software']:
  stage=O/('software-'+s['workload']+'.log');assert not stage.exists()
  logs=[]
  for i,argv in enumerate(s['commands']):logs.append(command(argv,O/(s['workload']+'-compile-'+str(i)+'.log'),Path(s['cwd']),timeout=300))
  elf=Path(s['elf']);assert elf.exists()
  objdump='/data1/gzh/EC/chipyard/.conda-env/riscv-tools/bin/riscv64-unknown-elf-objdump'
  disasm=subprocess.check_output([objdump,'-d',str(elf)],text=True)
  # main must not call EC startup/IRQ/control helpers; all actual boot/runtime
  # acceptance remains a separate simulation gate, never an offline pass.
  main=re.search(r'<main>:\n(.*?)(?=\n\n)',disasm,re.S);assert main
  assert not any(x in main[1] for x in ['r_ini','ght_','ghe_','test_setup','csr_software_cfg','msip_cfg'])
  (O/(s['workload']+'-native-main-disassembly.txt')).write_text(main[0]+'\n')
  built.append(dict(workload=s['workload'],elf=str(elf),elf_sha256=sha(elf),reference_manifest_sha256=s['reference_manifest_sha256'],
       native_main_sha256=s['native_main_sha256'],unchanged_kernel_input_files=len(s['kernel_and_input_source_sha256']),commands=logs,
       runtime_validation=False,fpga_access=False))
 save(O/'software-build.json',dict(status='BUILT_INDEPENDENT_NATIVE_BOOT_IDENTICAL_KERNEL_AND_INPUT_SOURCE_NOT_RUNTIME_PASS',software=built,plan_sha256=sha(C/'plan.json'),fpga_access=False))
 env={**os.environ,**p['environment']}
 result=command(p['command'],O/'model-compile.log',O,env=env,timeout=p['compile_timeout_seconds'])
 binary=Path(p['binary']);assert binary.exists()
 save(O/'compile-result.json',dict(status='BUILT_TRUE_SINGLE_BOOM_GOLDENGATE_MODEL_RUNTIME_NOT_VALIDATED',binary=str(binary),binary_sha256=sha(binary),plan_sha256=sha(C/'plan.json'),compile=result,fpga_access=False))
 # One bounded real boot probe on the compatible Native adapter. A cycle-limit
 # exit is diagnostic progress and never counts as a valid performance sample.
 elf=built[0]['elf'];argv=[str(binary),'+permissive','+max-cycles=10000','+fesvr-step-size=1000',*p['memory_plusargs'],'+permissive-off','+prog0='+elf]
 start=time.monotonic();log=O/'native-boot-probe.log';assert not log.exists()
 with log.open('xb',buffering=0) as f:
  child=subprocess.Popen(argv,cwd=O,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,env={**env,'LD_LIBRARY_PATH':''},start_new_session=True)
  update('RUNNING_BOUNDED_NATIVE_BOOT_NOT_PERFORMANCE',child=ident(child.pid))
  try:rc=child.wait(timeout=1200)
  except subprocess.TimeoutExpired:
   os.killpg(child.pid,15);rc=child.wait(timeout=20)
  os.fsync(f.fileno())
 text=log.read_text(errors='replace');cycles=re.findall(r'Target Cycles Emulated:\s*(\d+)',text)
 good=bool(cycles) and int(cycles[-1])>=10000 and not re.search(r'Assertion failed|%Error|status=FAIL|Simulator deadlock detected',text)
 boot=dict(status='BOUNDED_NATIVE_TARGET_PROGRESS_NOT_BENCHMARK_PASS' if good else 'BOOT_FAILED_WITH_EVIDENCE',
    returncode=rc,target_cycles=int(cycles[-1]) if cycles else None,host_wall_seconds=time.monotonic()-start,argv=argv,
    log_sha256=sha(log),binary_sha256=sha(binary),elf_sha256=sha(elf),runtime_benchmark_passed=False,fpga_access=False)
 save(O/'boot-probe.json',boot);assert good,'BOUNDED_BOOT_FAILED'
 update(boot['status'],child={},binary_sha256=sha(binary),next='Separate immutable samekernel complete workload runtime request after bootreceipt/source/counterABI audit; no FPGA Native restart')

if __name__=='__main__':
 try:
  ap=argparse.ArgumentParser();ap.add_argument('--prepare',action='store_true');ap.add_argument('--run',action='store_true');a=ap.parse_args()
  if a.prepare:prepare()
  elif a.run:run()
  else:raise ValueError('explicit action required')
 except BaseException as e:
  O.mkdir(exist_ok=True);save(O/('failure-'+str(os.getpid())+'.json'),dict(error=repr(e),traceback=traceback.format_exc(),fpga_access=False))
  raise
