#!/usr/bin/env python3
"""Matched module-only Vivado maps; at most two jobs, no full DUT or FPGA."""
from pathlib import Path
import datetime,fcntl,json,os,subprocess,time
from board_batch import W,D,save,sha
from job_service import proc
O=D/'build-logs/Opt4-fit-modules-20261110'
STATE=D/'Opt4-fit-mapping-state.json'
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def parse(p):
 r={}
 for l in p.read_text().splitlines():
  f=[x.strip() for x in l.split('|')]
  if len(f)>6 and f[1] in ['CLB LUTs*','CLB Registers','CARRY8','DSPs','Block RAM Tile']:
   try:r[f[1].rstrip('*')]=float(f[2])
   except ValueError:pass
 return r
def main():
 lock=(D/'.opt4-fit-mapping.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 st=dict(status='WAITING_MODULE_RTL',pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),started_utc=now(),fpga_access=False,full_dut_synthesis=False,max_concurrent=2,modules={});save(STATE,st)
 jobs={};done=set()
 while len(done)<4:
  build=json.loads((D/'Opt4-fit-modules-state.json').read_text())
  for key in ['fit-barrier','baseline-barrier','fit-address','baseline-address']:
   if key in done or key in jobs or len(jobs)>=2:continue
   r=build['modules'].get(key,{})
   if r.get('status')!='ELABORATED_MODULE_ONLY':continue
   path=Path(r['rtl']);assert sha(path)==r['rtl_sha256'];out=path.parent/'vivado';out.mkdir(exist_ok=True)
   top='GHBarrierLatencyStats' if r['module']=='barrier' else 'PackageAddressStats'
   tcl=out/'map.tcl';tcl.write_text(f'''set_param general.maxThreads 8
read_verilog {{{path}}}
synth_design -top {top} -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized
report_utilization -file {{{out/'utilization.rpt'}}}
report_utilization -hierarchical -hierarchical_depth 20 -file {{{out/'hierarchical.rpt'}}}
write_checkpoint -force {{{out/'module.dcp'}}}
puts "EC_OPT4_FIT_MODULE_MAP_COMPLETE {key}"
exit 0
''')
   f=(out/'mapping.log').open('ab',buffering=0)
   argv=['nice','-n','15','/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(out/'vivado.log'),'-source',str(tcl)]
   p=subprocess.Popen(argv,cwd=out,env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'8'},stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
   st['modules'][key]=dict(status='MAPPING',pid=p.pid,start_ticks=proc(p.pid)['start_ticks'],rtl=str(path),rtl_sha256=r['rtl_sha256'],source_sha256=r['source_sha256'],fit_commit=r['fit_commit'],tcl_sha256=sha(tcl),out=str(out),started_utc=now(),timing_closed=False)
   jobs[key]=(p,f,out);save(STATE,st)
  for key,(p,f,out) in list(jobs.items()):
   if p.poll() is None:continue
   os.fsync(f.fileno());f.close();r=st['modules'][key];r.update(status='MAPPED_MODULE_ONLY' if p.returncode==0 else 'FAILED_WITH_EVIDENCE',returncode=p.returncode,ended_utc=now())
   if p.returncode==0:r.update(utilization=parse(out/'utilization.rpt'),report_sha256=sha(out/'utilization.rpt'))
   done.add(key);del jobs[key];save(out/'receipt.json',r);save(STATE,st)
  if build['status']=='FAILED_WITH_EVIDENCE' and not jobs:
   st.update(status='ELABORATION_FAILED_PARTIAL_MAPS_PRESERVED');save(STATE,st);return
  st.update(status='RUNNING_MODULE_MAPS' if jobs else 'WAITING_MODULE_RTL',updated_utc=now());save(STATE,st)
  if len(done)<4:time.sleep(30)
 st.update(status='MODULE_MAPS_COMPLETE' if all(x['returncode']==0 for x in st['modules'].values()) else 'PARTIAL_FAILURE_WITH_EVIDENCE',ended_utc=now());save(STATE,st)
if __name__=='__main__':main()
