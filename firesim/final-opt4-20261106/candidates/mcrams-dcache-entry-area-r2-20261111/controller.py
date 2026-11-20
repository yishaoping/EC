#!/usr/bin/python3
"""Same-settings actual entry host RTL OOC area. Never a full-DUT/FIT claim."""
from pathlib import Path
import argparse, fcntl, hashlib, importlib.util, json, os, re, resource, shutil
C=Path(__file__).resolve().parent
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
P=D/'build-logs/Opt4-mcrams-dcache-entry-r5-20261111'
L=D/'build-logs/Opt4-mcrams-dcache-entry-area-r2-20261111'
S=D/'Opt4-mcrams-dcache-entry-area-r2-state.json'
sp=importlib.util.spec_from_file_location('entry',W/'candidates/mcrams-dcache-entry-r5-20261111/controller.py')
m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
m.L=L;m.S=S
PART='xcu280-fsvh2892-2L-e'

def area(p):
 text=p.read_text();out={}
 for n in ['CLB LUTs','CLB Registers','CARRY8','DSPs','Block RAM Tile','URAM']:
  row=re.search(r'^\| '+re.escape(n)+r'\s*\|\s*([\d,.]+)\s*\|',text,re.M)
  if n=='CARRY8':
   if not row:row=re.search(r'^\|\s+CARRY8\s*\|\s*([\d,.]+)\s*\|',text,re.M)
  assert row,(n,str(p));out[n]=float(row[1].replace(',',''))
 return out

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--run',action='store_true');a=ap.parse_args();assert a.run
 L.mkdir(parents=True,exist_ok=True);lock=(L/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 cpus=[250,251];assert set(cpus)<=os.sched_getaffinity(0);os.sched_setaffinity(0,cpus)
 resource.setrlimit(resource.RLIMIT_AS,(64*2**30,64*2**30))
 plan=m.read(C/'plan.json');assert all(m.sha(p)==h for p,h in plan['inputs'].items())
 proof=m.read(P/'result.json');assert proof['status']=='PASS_REAL_DCACHE_MEMORY_INTERFACE_SAME_TARGET_GG_PLAIN_AND_MCRAMS_NOT_FULL_DCACHE'
 assert proof['production_admission'] is False and proof['full_dut_equivalence'] is False
 assert proof['results']['PlainConfig']['metrics']['event_digest']==proof['results']['MCConfig']['metrics']['event_digest']
 m.ST.update(schema='ec-real-dcache-entry-host-area/1',**m.identity(),started_utc=m.now(),functional_baseline=m.BASE,
   derived_hardware=m.HW,cpus=cpus,memory_limit_bytes=64*2**30,fpga_access=False,production_admission=False,whole_fit=False,
   scope='Complete isolated ownerImageMemory host entry including 35 reads,written-mask/reset,35 captures and PeekPoke. Not complete DCache.',proof_sha256=m.sha(P/'result.json'))
 m.update(status='RUNNING')
 models={};ports=[]
 for config in ['MCConfig','PlainConfig']:
  original=P/config/'FireSim-generated.sv'
  assert m.sha(original)==proof['results'][config]['host_rtl_sha256']
  text=original.read_text()
  header=re.search(r'^module FPGATop\(.*?^\);',text,re.M|re.S)[0];ports.append(header)
  if config=='MCConfig':
   assert re.search(r'^module RamModel\(',text,re.M) and re.search(r'\bRamModel model\s*\(',text)
   assert re.search(r'\bownerImageMemory Entry_dut_ownerImageMemory_\s*\(',text)
  out=L/config;out.mkdir(exist_ok=True);sv=out/'host.sv'
  if not sv.exists():shutil.copy2(original,sv)
  assert m.sha(sv)==m.sha(original)
  report=out/'utilization.rpt';hier=out/'hierarchical.rpt';checkpoint=out/'module.dcp'
  tcl=out/'map.tcl'
  body='set_param general.maxThreads 2\nread_verilog -sv {'+str(sv)+'}\n'
  body+='synth_design -mode out_of_context -top FPGATop -part '+PART+'\n'
  body+='set boxes [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]\nif {[llength $boxes]} {error "unresolved storage-entry dependencies: $boxes"}\n'
  body+='report_utilization -file {'+str(report)+'}\nreport_utilization -hierarchical -file {'+str(hier)+'}\n'
  body+='write_checkpoint -force {'+str(checkpoint)+'}\nputs "EC_ENTRY_AREA_ZERO_BLACKBOX_PASS"\nexit 0\n'
  if tcl.exists():assert tcl.read_text()==body
  else:tcl.write_text(body)
  r=m.stage('area-'+config,['nice','-n','15','/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(out/'vivado.log'),'-source',str(tcl)],cwd=out,outputs=[report,hier,checkpoint],timeout=10800)
  assert 'EC_ENTRY_AREA_ZERO_BLACKBOX_PASS' in (L/('area-'+config+'.log')).read_text()
  models[config]=dict(resources=area(report),report=str(report),report_sha256=m.sha(report),host_rtl_sha256=m.sha(original),
    checkpoint_sha256=m.sha(checkpoint),host_wall_seconds=r['host_wall_seconds'])
  m.ST['results']=models;m.update()
 assert ports[0]==ports[1],'host top interfaces differ'
 before=models['PlainConfig']['resources'];after=models['MCConfig']['resources']
 savings={n:before[n]-after[n] for n in before}
 m.update(status='MEASURED_REAL_ENTRY_HOST_AREA_NOT_FULL_DCACHE_OR_OPT4_FIT',completed_utc=m.now(),
   lut_saved=savings['CLB LUTs'],resource_savings=savings,
   next='Recheck defined target-cycle semantics for actual full DCache, including all generation/debug ports; apply exact MCRams annotations independently, verify whole target parity and measure before full CAD. No production admission from entry proof.')
 m.save(L/'result.json',m.ST)
if __name__=='__main__':
 try:main()
 except Exception as e:
  if L.exists():m.update(status='FAILED_WITH_EVIDENCE',error=repr(e));m.save(L/'failure.json',m.ST)
  raise
