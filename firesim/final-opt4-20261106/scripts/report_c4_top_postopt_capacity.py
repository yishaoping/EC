#!/usr/bin/env python3
"""Report top optimized capacity before routing completion, never control CAD."""
from pathlib import Path
import datetime,json,os,subprocess,time,re
from board_batch import W,D,save,sha
from job_service import proc
O=D/'build-logs/C4-capacity-20261110/top-postopt';O.mkdir(exist_ok=True)
state=D/'C4-capacity-top-postopt-state.json'
st=dict(status='WAITING_TOP_OPT_CHECKPOINT',pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),fpga_access=False,cad_signals=False)
save(state,st)
while True:
 marker=O/'capacity.complete'
 if marker.exists() and 'EC_CAPACITY_TOP_REPORT_COMPLETE' in marker.read_text():
  st.update(status='NOT_FIT_POSTOPT' if 'NOT_FIT_POSTOPT' in marker.read_text() else 'CAPACITY_FITS_POSTOPT_TIMING_PENDING',report_scope='Complete top inline report after opt_design, before placement',report=str(O/'utilization.rpt'),capacity_does_not_prove_timing_or_routability=True,ended_utc=datetime.datetime.now(datetime.timezone.utc).isoformat());save(state,st);raise SystemExit(0)
 s=json.loads((D/'C4-dcp-cad-state.json').read_text());run=Path(s['output_dir'])/'vivado_proj/firesim.runs/impl_1';dcp=run/'design_1_wrapper_opt.dcp'
 # Only consume a finished optimization checkpoint; never a partially written zip.
 ready=dcp.is_file() and ((run/'.opt_design.end.rst').exists() or (run/'.place_design.begin.rst').exists())
 # This build emits its report in the live Vivado after optimization; avoid
 # reopening a multi-GB checkpoint while the inline report is being produced.
 inline='EC_CAPACITY_TOP_REPORT_COMPLETE' in (Path(s['log_dir'])/'implementation-bound.tcl').read_text()
 if ready and not inline:break
 if s['status']=='FAILED_WITH_EVIDENCE':
  st.update(status='CAD_FAILED_BEFORE_POSTOPT',error=s.get('error'));save(state,st);raise SystemExit(1)
 st.update(updated_utc=datetime.datetime.now(datetime.timezone.utc).isoformat());save(state,st);time.sleep(300)
before=dcp.stat();digest=sha(dcp);assert (dcp.stat().st_size,dcp.stat().st_mtime_ns)==(before.st_size,before.st_mtime_ns)
tcl=O/'report.tcl';tcl.write_text('set_param general.maxThreads 8\nopen_checkpoint {'+str(dcp)+'}\nreport_utilization -file {'+str(O/'utilization.rpt')+'}\nreport_utilization -hierarchical -hierarchical_depth 10 -file {'+str(O/'hierarchical.rpt')+'}\nreport_drc -file {'+str(O/'drc.rpt')+'}\nclose_design\nexit 0\n')
with (O/'report.log').open('ab',buffering=0) as log:
 p=subprocess.Popen(['nice','-n','10','/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(O/'vivado.log'),'-source',str(tcl)],cwd=O,env={**os.environ,'LD_LIBRARY_PATH':''},stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,start_new_session=True)
 st.update(status='READING_TOP_POSTOPT_CHECKPOINT',input_dcp=str(dcp),input_sha256=digest,child_pid=p.pid,child_start_ticks=proc(p.pid)['start_ticks']);save(state,st)
 while p.poll() is None:
  try:p.wait(timeout=30)
  except subprocess.TimeoutExpired:pass
  st.update(updated_utc=datetime.datetime.now(datetime.timezone.utc).isoformat());save(state,st)
 st.update(status='POSTOPT_REPORTED' if p.returncode==0 else 'FAILED_WITH_EVIDENCE',returncode=p.returncode);save(state,st)
assert p.returncode==0
text=(O/'utilization.rpt').read_text();rows={}
for line in text.splitlines():
 parts=[x.strip().replace(',','') for x in line.split('|')]
 if len(parts)>6 and parts[1] in ['CLB LUTs*','CLB LUTs','CLB Registers','CARRY8','DSPs','Block RAM Tile']:
  try:rows[parts[1]]=dict(used=float(parts[2]),available=float(parts[5]))
  except ValueError:pass
assert rows
excess={k:v for k,v in rows.items() if v['used']>v['available']}
st.update(status='NOT_FIT_POSTOPT' if excess else 'CAPACITY_FITS_POSTOPT_TIMING_PENDING',resources=rows,excess=excess,report_scope='Complete top after opt_design, before route completion',capacity_does_not_prove_timing_or_routability=True,ended_utc=datetime.datetime.now(datetime.timezone.utc).isoformat());save(state,st)
