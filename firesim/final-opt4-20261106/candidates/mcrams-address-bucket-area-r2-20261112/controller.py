#!/usr/bin/python3
"""Two-core actual one-bank area; immutable passed parity, no FPGA operation."""
import datetime, fcntl, hashlib, importlib.util, json, os, pathlib, resource, subprocess, time
P=pathlib.Path; C=P(__file__).resolve().parent
W=P('/data1/gzh/EC/firesim/final-opt4-20261106')
D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
REF=D/'build-logs/Opt4-mcrams-address-bucket-r5-20261112'
O=D/'build-logs/Opt4-mcrams-address-bucket-area-r2-20261112'
S=D/'Opt4-mcrams-address-bucket-area-r2-state.json'; ST={}
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def read(p):return json.loads(P(p).read_text()) if P(p).exists() else {}
def sha(p):
 h=hashlib.sha256()
 with P(p).open('rb') as f:
  for b in iter(lambda:f.read(2**20),b''):h.update(b)
 return h.hexdigest()
def save(p,j):
 p=P(p);p.parent.mkdir(parents=True,exist_ok=True);q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('w') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(q,p);fd=os.open(p.parent,os.O_RDONLY|os.O_DIRECTORY);os.fsync(fd);os.close(fd)
def ident(pid=None):
 pid=pid or os.getpid()
 try:
  a=P(f'/proc/{pid}/stat').read_text().rsplit(')',1)[1].split()
  return dict(pid=pid,start_ticks=a[19],host_boot_id=P('/proc/sys/kernel/random/boot_id').read_text().strip(),process_state=a[0],cpu_ticks=int(a[11])+int(a[12]),rss_bytes=int(a[21])*os.sysconf('SC_PAGE_SIZE'))
 except FileNotFoundError:return {}
def live(x):
 a=ident(x.get('pid')) if x.get('pid') else {}
 return bool(a and a['process_state'] not in ['X','Z'] and all(str(a[k])==str(x.get(k)) for k in ['pid','start_ticks','host_boot_id']))
def update(**kw):ST.update(kw,updated_utc=now());save(S,ST)
def parser():
 s=importlib.util.spec_from_file_location('area_parser',C/'resource_parser.py');m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
def model_receipt(label,sv,out,elapsed):
 m=parser();u=out/'utilization.rpt';h=out/'hierarchical.rpt'
 tot=m.parse_total(u.read_text());hier=m.parse_hier(h.read_text(),tot);checks=m.crosschecks(u.read_text(),tot)
 assert tot['CLB LUTs']['used']>0
 return dict(resources={k:v['used'] for k,v in tot.items()},capacities={k:v['available'] for k,v in tot.items()},host_rtl_sha256=sha(sv),report_sha256=sha(u),hierarchical_sha256=sha(h),checkpoint_sha256=sha(out/'mapped.dcp'),report=str(u),hierarchical_report=str(h),checkpoint=str(out/'mapped.dcp'),crosschecks=checks,hierarchy_top=hier['top'],stage_wall_seconds=elapsed,zero_blackboxes=True)
def main():
 O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 old=read(S);assert not live(old) and not live(old.get('child',{})),'adopt existing live area'
 plan=read(C/'plan.json')
 for p,h in {**plan['inputs'],**plan['evidence_inputs']}.items():assert sha(p)==h,p
 assert set([220,221])<=os.sched_getaffinity(0);os.sched_setaffinity(0,{220,221});resource.setrlimit(resource.RLIMIT_AS,(24*2**30,24*2**30))
 r1=read(D/'Opt4-mcrams-address-bucket-area-r1-state.json');assert not live(r1) and not live(r1.get('child',{})),'r1 already running; adopt it'
 global_lock=(D/'.address-bucket-mcrams-area.lock').open('a');fcntl.flock(global_lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 proof=read(REF/'result.json');assert proof['status']=='PASS_WORD_TRANSITION_LEMMA_AND_FINITE_FULL_WIDTH_ALL_WORD_TARGET_PARITY_AREA_PENDING'
 assert proof['results']['Reg']['metrics']['event_digest']==proof['results']['MemMC']['metrics']['event_digest']
 if old:save(O/('before-'+str(os.getpid())+'.json'),old)
 ST.update(schema='ec-two-core-address-bank-area/2',**ident(),started_utc=now(),functional_baseline=proof['functional_baseline'],fpga_access=False,full_address_module=False,whole_fit=False,no_large_CAD=True,cpus=[220,221],threads=2,memory_limit_gib=24,proof_sha256=sha(REF/'result.json'),models={},status='STARTED_PAIRED_ACTUAL_ADDRESS_BANK_AREA')
 update()
 for label in ['MemMC','Reg']:
  sv=REF/label/'FireSim-generated.sv';assert sha(sv)==proof['results'][label]['host_rtl_sha256'];out=O/label;out.mkdir(exist_ok=True);rp=out/'receipt.json'
  if rp.exists():
   rr=read(rp);actual=model_receipt(label,sv,out,rr['stage_wall_seconds']);assert all(rr[k]==v for k,v in actual.items()),'completed evidence changed';ST['models'][label]=rr;update();continue
  if (out/'mapped.dcp').exists() and (out/'utilization.rpt').exists() and (out/'hierarchical.rpt').exists():
   rr=model_receipt(label,sv,out,None);rr['recovered_completed_reports_no_resynthesis']=True
  else:
   assert not (out/'run.log').exists(),'partial area preserved; independent checkpoint recovery required'
   script=out/'map.tcl';script.write_text('set_param general.maxThreads 2\nread_verilog -sv {'+str(sv)+'}\nsynth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e\nif {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "unresolved address bank model"}\nreport_utilization -file {'+str(out/'utilization.rpt')+'}\nreport_utilization -hierarchical -hierarchical_depth 15 -file {'+str(out/'hierarchical.rpt')+'}\nwrite_checkpoint -force {'+str(out/'mapped.dcp')+'}\nputs "ACTUAL_ADDRESS_BANK_AREA_ZERO_BLACKBOX"\nexit 0\n')
   start=time.monotonic()
   with (out/'run.log').open('xb',buffering=0) as f:
    p=subprocess.Popen(['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-source',str(script)],cwd=out,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'2'},start_new_session=True)
    update(status='RUNNING_LOCAL_'+label,child=ident(p.pid),current_model=label,log=str(out/'run.log'))
    while p.poll() is None:
     try:p.wait(timeout=60)
     except subprocess.TimeoutExpired:pass
     update(host_wall_seconds=time.monotonic()-start);os.fsync(f.fileno())
    elapsed=time.monotonic()-start;save(out/'exit.json',dict(returncode=p.returncode,stage_wall_seconds=elapsed,ended_utc=now(),log_sha256=sha(out/'run.log')))
   update(child={});assert p.returncode==0,(label,p.returncode)
   rr=model_receipt(label,sv,out,elapsed)
  save(rp,rr);ST['models'][label]=rr;update()
 before=ST['models']['Reg']['resources'];after=ST['models']['MemMC']['resources']
 update(status='MEASURED_ACTUAL_REGVEC_VS_MCRAMS_ADDRESS_BANK_NO_FULL_MODULE_FIT_CLAIM',completed_utc=now(),resource_savings={k:before[k]-after[k] for k in before},area_scope='One original256x64 storage update interface, all258reads/256writes; not full arithmetic/AddressStats',child={})
 save(O/'result.json',ST)
if __name__=='__main__':
 try:main()
 except Exception as exc:
  if ST:update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now());save(O/'failure.json',ST)
  raise
