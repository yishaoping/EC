#!/usr/bin/python3
"""Read-only report recovery first; reuse completed DCP, never rerun DUT synth."""
import importlib.util,json,pathlib,sys,subprocess,os,fcntl,time,shutil
C=pathlib.Path(__file__).resolve().parent
spec=importlib.util.spec_from_file_location('continuation',C/'continue.py');m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
A=m.AREA;out=m.O/'recovered-capacity.json'
assert not m.live(m.read(m.D/'Opt4-mcrams-full-host-capacity-r1-state.json'))
assert not m.live(m.read(m.D/'Opt4-mcrams-full-host-capacity-r1-state.json').get('child',{}))
s=importlib.util.spec_from_file_location('reports',m.W/'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py');p=importlib.util.module_from_spec(s);s.loader.exec_module(p)
recovery=m.O/'postopt-report-recovery';recovery.mkdir(exist_ok=True)
if (A/'postopt.dcp').exists() or (A/'synth.dcp').exists():
 checkpoint=A/'postopt.dcp' if (A/'postopt.dcp').exists() else A/'synth.dcp'
 # Only if original reports are absent, reuse the last completed checkpoint
 # and run missing opt/report. This never repeats synth_design.
 if not all((A/n).exists() for n in ['postopt-utilization.rpt','postopt-hierarchical.rpt','postopt.dcp']):
  code='set_param general.maxThreads 8\nopen_checkpoint {'+str(checkpoint)+'}\n'
  if checkpoint.name=='synth.dcp':code+='opt_design\n'
  code+='report_utilization -file {'+str(recovery/'postopt-utilization.rpt')+'}\nreport_utilization -hierarchical -file {'+str(recovery/'postopt-hierarchical.rpt')+'}\nwrite_checkpoint -force {'+str(recovery/'postopt.dcp')+'}\nexit 0\n'
  lock=(m.D/'.mcrams-full-host-capacity.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
  while True:
   mem=int(next(x.split()[1] for x in pathlib.Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))
   if mem>=256*2**20 and shutil.disk_usage(recovery).free>=150*2**30:break
   time.sleep(300)
  script=recovery/'recover.tcl' ;assert not script.exists(),'partial recovery evidence retained'
  script.write_text(code)
  with (recovery/'run.log').open('xb',buffering=0) as f:subprocess.run(['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-source',str(script)],cwd=recovery,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,env={**os.environ,'LD_LIBRARY_PATH':''},check=True)
  A=recovery
if (A/'postopt-utilization.rpt').exists() and (A/'postopt.dcp').exists():
 totals=p.parse_total((A/'postopt-utilization.rpt').read_text());p.parse_hier((A/'postopt-hierarchical.rpt').read_text(),totals);p.crosschecks((A/'postopt-utilization.rpt').read_text(),totals)
 resources={k:v['used'] for k,v in totals.items()};capacities={k:v['available'] for k,v in totals.items()}
 r=dict(status='RECOVERED_ACTUAL_POSTOPT_REPORTS_NO_RESYNTHESIS',functional_baseline=m.BASE,derived_hardware=m.HW,host_rtl_sha256='9d5380252ec779da8844b1ff632af84330fd2d0dff63912dd4c08180ae2ff3e1',reports=dict(postopt=dict(resources=resources,capacities=capacities)),resource_excess={k:max(0,v-capacities[k]) for k,v in resources.items()},full_host_fit=all(v<=capacities[k] for k,v in resources.items()),checkpoint=str(A/'postopt.dcp'),checkpoint_sha256=m.sha(A/'postopt.dcp'),evidence_sha256={str(x):m.sha(x) for x in [A/'postopt-utilization.rpt',A/'postopt-hierarchical.rpt']},full_physical_fit=False,fpga_access=False)
elif (A/'synth.dcp').exists():
 r=dict(status='SYNTH_CHECKPOINT_PRESERVED_OPT_RECOVERY_REQUIRED',checkpoint=str(A/'synth.dcp'),fpga_access=False,automatic_resynthesis=False)
else:
 r=dict(status='NO_COMPLETED_CHECKPOINT_PRESERVED_REAL_TOOL_FAILURE_REQUIRES_AUTONOMOUS_DIAGNOSIS',failure=m.read(A/'failure.json'),log=str(A/'run.log'),fpga_access=False,automatic_resynthesis=False)
if out.exists():assert m.read(out)==r
else:m.save(out,r)
print(r['status'])
