#!/usr/bin/env python3
"""Actual result CDC pair, small two-CPU OOC module synth only."""
import json
import os
from pathlib import Path
import subprocess
import sys
C=Path(__file__).resolve().parent;T=C.parent.parent;O=Path(sys.argv[1]).resolve();A=O/'module-area'
def resources(p):
 r={}
 for l in p.read_text().splitlines():
  x=[v.strip().rstrip('*') for v in l.split('|')]
  if len(x)>6 and x[1] in ['CLB LUTs','CLB Registers','LUT as Memory','F7 Muxes','F8 Muxes','F9 Muxes','Block RAM Tile','DSPs','URAM','CARRY8']:r.setdefault(x[1],float(x[2].replace(',','')))
 return r
def main():
 os.sched_setaffinity(0,{250,251});os.nice(19)
 assert json.loads((O/'result.json').read_text())['status']=='PASS_RESULT_CDC_CYCLES_AND_ALL_STATE_EQUIVALENCE'
 A.mkdir(exist_ok=False);rows={}
 for top in ['AsyncQueue','LocalMemAsyncQueue']:
  d=A/top;d.mkdir()
  (d/'run.tcl').write_text('''set_param general.maxThreads 2
read_verilog {%s}
synth_design -top %s -part xcu280-fsvh2892-2L-e -mode out_of_context -flatten_hierarchy rebuilt
create_clock -name checker -period 200 [get_ports io_enq_clock]
create_clock -name boom -period 100 [get_ports io_deq_clock]
opt_design
report_utilization -file utilization.rpt
report_high_fanout_nets -max_nets 25 -file fanout.rpt
write_checkpoint -force postopt.dcp
puts EC_RESULT_CDC_MODULE_AREA_COMPLETE
exit 0
'''%(O/'target/QueuePair.v',top))
  env={k:v for k,v in os.environ.items() if k not in ['PYTHONHOME','PYTHONPATH','LD_LIBRARY_PATH','LD_PRELOAD']}
  env['OMP_NUM_THREADS']='2'
  with (d/'stdout.log').open('xb') as f:p=subprocess.run(['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log','vivado.log','-source','run.tcl'],cwd=d,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,env=env,timeout=900)
  assert p.returncode==0
  assert 'EC_RESULT_CDC_MODULE_AREA_COMPLETE' in (d/'vivado.log').read_text()
  rows[top]=resources(d/'utilization.rpt')
  (A/'result.json').write_text(json.dumps(dict(status='PARTIAL_MODULE_AREA' if len(rows)<2 else 'PASS_PAIRED_RESULT_CDC_REAL_MODULE_AREA',width=34,capacity=256,rows=rows,full_shell=False,generated_host_area=False),indent=2)+'\n')
if __name__=='__main__':main()
