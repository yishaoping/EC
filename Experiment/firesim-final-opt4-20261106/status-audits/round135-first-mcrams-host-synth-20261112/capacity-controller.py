#!/usr/bin/python3
"""One independent full-generated-host OOC synth/post-opt capacity evaluation.
Explicitly a large full-host job, second to retained e0. No shell/P&R/FPGA.
No target parity or production admission can be inferred from this area job.
"""
import argparse,datetime,fcntl,hashlib,importlib.util,json,os,pathlib,resource,shutil,subprocess,time
P=pathlib.Path;C=P(__file__).resolve().parent
W=P('/data1/gzh/EC/firesim/final-opt4-20261106');D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-mcrams-full-host-capacity-r1-20261112';S=D/'Opt4-mcrams-full-host-capacity-r1-state.json';ST={}
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
  a=P(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split();return dict(pid=pid,start_ticks=a[19],host_boot_id=P('/proc/sys/kernel/random/boot_id').read_text().strip())
 except FileNotFoundError:return {}
def update(**kw):ST.update(kw,updated_utc=now());save(S,ST)
def main():
 ap=argparse.ArgumentParser();ap.add_argument('--run',action='store_true');ap.parse_args();plan=read(C/'plan.json')
 O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 assert not S.exists() and not (O/'run.log').exists(),'preserve existing full-host task; no duplicate'
 assert all(sha(p)==h for p,h in plan['inputs'].items()),'input version changed'
 allowed=set(os.sched_getaffinity(0));cpus=set(range(240,248));assert cpus<=allowed;os.sched_setaffinity(0,cpus);resource.setrlimit(resource.RLIMIT_AS,(128*2**30,128*2**30))
 ST.update(schema='ec-mcrams-full-host-capacity/1',**ident(),started_utc=now(),functional_baseline=plan['functional_baseline'],derived_hardware=plan['derived_hardware'],host_rtl_sha256=plan['host_rtl_sha256'],
  area_scope='Complete generated FPGATop host simulator with owner-only MCRams; U280 shell not included, no parity/FPGA claim',full_generated_host=True,full_physical_system=False,fpga_access=False,production_admission=False,whole_dut_target_parity=False,cpus=sorted(cpus),threads=8,memory_limit_gib=128)
 while True:
  mem=int(next(l.split()[1] for l in P('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))
  if mem>=256*2**20 and shutil.disk_usage(O).free>=140*2**30:break
  update(status='WAITING_SECOND_LARGE_HOST_CAPACITY_RESOURCE_GATE',mem_kib=mem,free_disk_bytes=shutil.disk_usage(O).free);time.sleep(300)
 # A separate lock explicitly serializes this MCRams full-host line. Never
 # locks or mutates the retained e0 CAD or P0 SVB physical tasks.
 hostlock=(D/'.mcrams-full-host-capacity.lock').open('a');fcntl.flock(hostlock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 log=O/'run.log';start=time.monotonic()
 with log.open('xb',buffering=0) as f:
  p=subprocess.Popen(['nice','-n','10','/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(O/'vivado.log'),'-source',str(C/'capacity.tcl')],cwd=O,
    env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'8','TMPDIR':str(O)},stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT)
  update(status='RUNNING_FULL_HOST_SYNTHESIS',child=ident(p.pid),log=str(log))
  while p.poll() is None:
   try:p.wait(timeout=60)
   except subprocess.TimeoutExpired:pass
   phase=(O/'phase.txt').read_text().strip() if (O/'phase.txt').exists() else 'synth_design'
   update(status='RUNNING_FULL_HOST_'+phase.upper(),host_wall_seconds=time.monotonic()-start);os.fsync(f.fileno())
 assert p.returncode==0,('CAD failed; preserve checkpoint and raw evidence',p.returncode)
 sp=importlib.util.spec_from_file_location('parser',C/'resource_parser.py');m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
 counts={}
 for label in ['synth','postopt']:
  u=O/(label+'-utilization.rpt');h=O/(label+'-hierarchical.rpt');tot=m.parse_total(u.read_text());detail=m.parse_hier(h.read_text(),tot);check=m.crosschecks(u.read_text(),tot)
  counts[label]=dict(resources={k:v['used'] for k,v in tot.items()},capacities={k:v['available'] for k,v in tot.items()},blackboxes=check['blackboxes'],evidence={str(p):sha(p) for p in [u,h]},hierarchy=detail['top'])
 post=counts['postopt'];gap={k:max(0,v-post['capacities'][k]) for k,v in post['resources'].items()};notfit=any(gap.values())
 update(status='NOT_FIT_FULL_GENERATED_HOST_NO_PLACE_RUN' if notfit else 'FIT_FULL_HOST_OOC_REQUIRES_SHELL_AND_PARITY_BEFORE_PHYSICAL_ADMISSION',child={},reports=counts,resource_excess=gap,
  full_host_fit=not notfit,full_physical_system_fit=False,completed_utc=now(),host_wall_seconds=time.monotonic()-start,
  no_place_or_route_run=True,checkpoint=str(O/'postopt.dcp'),checkpoint_sha256=sha(O/'postopt.dcp'),next='Use actual ranked full-host hierarchy to select next equivalent memory/storage transformation; physical system needs shell capacity/timing/DRC and target-cycle parity.')
 save(O/'result.json',ST)
if __name__=='__main__':
 try:main()
 except Exception as e:
  if ST:update(status='FAILED_WITH_EVIDENCE',error=repr(e),ended_utc=now());save(O/'failure.json',ST)
  raise
