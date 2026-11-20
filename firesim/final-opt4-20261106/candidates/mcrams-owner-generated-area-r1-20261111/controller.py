#!/usr/bin/python3
"""OOC area of the exact actual whole-generated owner RAM host wrapper.
This module-only result cannot be called paired full-DCache/whole-system FIT.
"""
import argparse,datetime,fcntl,hashlib,importlib.util,json,os,pathlib,re,resource,shutil,subprocess,time
P=pathlib.Path;C=P(__file__).resolve().parent
W=P('/data1/gzh/EC/firesim/final-opt4-20261106');D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-mcrams-owner-generated-area-r1-20261111';S=D/'Opt4-mcrams-owner-generated-area-r1-state.json'
SRC=D/'build-logs/Opt4-mcrams-dcache-owner-system-r1-20261111/goldengate/FireSim-generated.sv'
TOP='ownerImageMemory_flattened';ST={}
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def read(p):return json.loads(P(p).read_text())
def sha(p):return hashlib.sha256(P(p).read_bytes()).hexdigest()
def save(p,j):
 p=P(p);p.parent.mkdir(parents=True,exist_ok=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def ident(pid=None):
 pid=pid or os.getpid()
 try:
  a=P(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=a[19],boot_id=P('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def update(**kw):ST.update(kw,updated_utc=now());save(S,ST)
def prepare():
 assert not (C/'plan.json').exists() and not O.exists();O.mkdir(parents=True)
 text=SRC.read_text();mods={m[1]:m[0] for m in re.finditer(r'^module (\w+)\b.*?^endmodule\b[^\n]*',text,re.M|re.S)}
 assert TOP in mods and len(mods)>100
 pat=re.compile(r'\b('+'|'.join(sorted((re.escape(n) for n in mods),key=len,reverse=True))+r')\s+(?:#\s*\([^;]*?\)\s*)?\w+\s*\(')
 todo=[TOP];seen=set()
 while todo:
  n=todo.pop()
  if n in seen:continue
  seen.add(n);todo.extend(m[1] for m in pat.finditer(mods[n]) if m[1] not in seen)
 assert 'RamModel' in seen and len(seen)<30,(len(seen),seen)
 rtl=C/'actual-owner-host-closure.sv';rtl.write_text('\n\n'.join(mods[n] for n in sorted(seen))+'\n')
 h=mods[TOP][:mods[TOP].index(');')+2];ports=re.findall(r'(?m)^\s*(input|output)\s+(?:\[([^\]]+)\]\s+)?(\w+)',h)
 assert len(ports)>100;save(C/'extraction.json',dict(scope='Exact whole-generated owner RAM host wrapper including all handshake ports and real model dependency closure; not entire DCache',source=str(SRC),source_sha256=sha(SRC),top=TOP,modules={n:hashlib.sha256(mods[n].encode()).hexdigest() for n in sorted(seen)},ports=ports,unmodified_module_bytes=True))
 # Reuse the tested total-section and hierarchy/primitive crosschecks with
 # the explicitly named module root, never matching SLR rows.
 parser=(W/'candidates/mcrams-dcache-entry-area-analysis-r2-20261111/analyze.py').read_text().split('\ndef analyze_config')[0]
 parser=parser.replace("FPGATop",TOP);(C/'resource_parser.py').write_text(parser)
 tcl=C/'map.tcl';tcl.write_text('set_param general.maxThreads 2\nread_verilog -sv {'+str(rtl)+'}\nsynth_design -mode out_of_context -top '+TOP+' -part xcu280-fsvh2892-2L-e\nset bb [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]\nif {[llength $bb]} {error "Unresolved RAM host dependencies: $bb"}\nreport_utilization -file {'+str(O/'utilization.rpt')+'}\nreport_utilization -hierarchical -hierarchical_depth 12 -file {'+str(O/'hierarchical.rpt')+'}\nwrite_checkpoint -force {'+str(O/'module.dcp')+'}\nputs "OWNER_ACTUAL_HOST_AREA_ZERO_BLACKBOX_PASS"\nexit 0\n')
 files=[C/'controller.py',C/'resource_parser.py',C/'extraction.json',rtl,tcl];sources=[SRC,D/'build-logs/Opt4-mcrams-dcache-owner-audit-r3-20261111/result.json',D/'build-logs/Opt4-mcrams-dcache-owner-audit-r3-20261111/complete.json']
 plan=dict(schema='ec-actual-owner-host-area-plan/1',functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',derived_hardware='3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c',inputs={str(p):sha(p) for p in files+sources},top=TOP,cpu_affinity=[250,251],threads=2,memory_limit_gib=64,minimum_memory_gib=128,no_whole_cad=True,fpga_access=False,whole_fit=False,production_admission=False)
 save(C/'plan.json',plan);name='owner-generated-area-r1-3656aec4';req=dict(action='cpu_job',spec=dict(name=name,kind='module',cwd=str(C),argv=['/usr/bin/python3',str(C/'controller.py'),'--run'],inputs={str(p):sha(p) for p in files+[C/'plan.json']},outputs=[str(O/'result.json')],checkpoints=[str(S)]));save(C/'request.json',req);dest=D/'unattended-opt4/requests'/(name+'.json');assert not dest.exists();save(dest,req);print(json.dumps(dict(submitted=str(dest),modules=sorted(seen),ports=len(ports),rtl_bytes=rtl.stat().st_size)))
def run():
 assert not S.exists(),'existing task/state cannot be duplicated';lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB);plan=read(C/'plan.json')
 assert all(sha(p)==h for p,h in plan['inputs'].items());assert {250,251}<=set(os.sched_getaffinity(0));os.sched_setaffinity(0,{250,251});resource.setrlimit(resource.RLIMIT_AS,(64*2**30,64*2**30))
 ST.update(schema='ec-actual-owner-host-area/1',**ident(),started_utc=now(),functional_baseline=plan['functional_baseline'],derived_hardware=plan['derived_hardware'],fpga_access=False,whole_fit=False,production_admission=False)
 while True:
  mem=int(next(l.split()[1] for l in P('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))
  if mem>=128*2**20 and shutil.disk_usage(O).free>=100*2**30:break
  update(status='WAITING_MODULE_RESOURCE_GUARD',mem_kib=mem);time.sleep(300)
 log=O/'map.log';assert not log.exists();start=time.monotonic()
 with log.open('xb',buffering=0) as f:
  p=subprocess.Popen(['nice','-n','15','/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(O/'vivado.log'),'-source',str(C/'map.tcl')],cwd=O,env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'2','TMPDIR':str(O)},stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT)
  update(status='RUNNING_EXACT_OWNER_HOST_MODULE_ONLY',child=ident(p.pid),log=str(log))
  while p.poll() is None:
   try:p.wait(timeout=30)
   except subprocess.TimeoutExpired:pass
   update(host_wall_seconds=time.monotonic()-start);os.fsync(f.fileno())
 assert p.returncode==0 and 'OWNER_ACTUAL_HOST_AREA_ZERO_BLACKBOX_PASS' in log.read_text()
 sp=importlib.util.spec_from_file_location('resource_parser',C/'resource_parser.py');m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
 text=(O/'utilization.rpt').read_text();hier=(O/'hierarchical.rpt').read_text();total=m.parse_total(text);detail=m.parse_hier(hier,total);extra=m.crosschecks(text,total)
 assert detail['ram_model_instances'] and extra['blackboxes']==0
 update(status='COMPLETE_ACTUAL_GENERATED_OWNER_HOST_AREA_NOT_FULL_DCACHE_OR_FIT',child={},resources={k:v['used'] for k,v in total.items()},host_wall_seconds=time.monotonic()-start,completed_utc=now(),area_scope=read(C/'extraction.json')['scope'],evidence={str(p):sha(p) for p in [O/'utilization.rpt',O/'hierarchical.rpt',O/'module.dcp',log,C/'extraction.json']})
 save(O/'result.json',ST)
if __name__=='__main__':
 ap=argparse.ArgumentParser();ap.add_argument('--prepare',action='store_true');ap.add_argument('--run',action='store_true');a=ap.parse_args()
 try:prepare() if a.prepare else run()
 except Exception as e:
  if ST:update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(O/'failure.json',ST)
  raise
