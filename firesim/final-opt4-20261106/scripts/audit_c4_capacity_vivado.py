#!/usr/bin/env python3
"""Independent capacity audit of immutable DUT DCP, no synthesis or FPGA."""
from pathlib import Path
import datetime as dt
import fcntl
import json
import os
import shutil
import subprocess
import time
from board_batch import W,D,save,sha
from job_service import proc

STATE=D/'C4-capacity-vivado-state.json'
OUT=D/'build-logs/C4-capacity-20261110'
def now():return dt.datetime.now(dt.timezone.utc).isoformat()
def main():
 lock=(D/'.c4-capacity-vivado.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 s=json.loads((D/'C4-dcp-cad-state.json').read_text())
 d=next(d for d in s['reused_checkpoints'] if Path(d['snapshot']).stem=='design_1_firesim_wrapper_0_0')
 dcp=Path(d['stable_snapshot']);assert sha(dcp)==d['sha256']
 OUT.mkdir(exist_ok=True)
 assert shutil.disk_usage(OUT).free>80*2**30
 mem={l.split(':')[0]:int(l.split()[1]) for l in Path('/proc/meminfo').read_text().splitlines()}
 assert mem['MemAvailable']>128*2**20
 tcl=OUT/'capacity.tcl'
 tcl.write_text(f'''set_param general.maxThreads 8
puts "EC_CAPACITY_DEVICE_BEGIN"
report_property [get_parts xcu280-fsvh2892-2L-e]
puts "EC_CAPACITY_DEVICE_END"
open_checkpoint {{{dcp}}}
puts "EC_CAPACITY_DUT_OPEN"
report_utilization -file {{{OUT/'vivado-preopt.rpt'}}}
report_utilization -hierarchical -hierarchical_depth 10 -file {{{OUT/'vivado-hierarchical-preopt.rpt'}}}
puts "EC_CAPACITY_PREOPT_REPORTS_COMPLETE"
opt_design -directive Explore
puts "EC_CAPACITY_OPT_COMPLETE"
report_utilization -file {{{OUT/'vivado-postopt.rpt'}}}
report_utilization -hierarchical -hierarchical_depth 10 -file {{{OUT/'vivado-hierarchical-postopt.rpt'}}}
report_drc -file {{{OUT/'vivado-postopt-drc.rpt'}}}
puts "EC_CAPACITY_POSTOPT_REPORTS_COMPLETE"
write_checkpoint -force {{{OUT/'DUT-optimized-capacity.dcp'}}}
close_design
exit 0
''')
 argv=['nice','-n','10','/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(OUT/'capacity.vivado.log'),'-source',str(tcl)]
 st=dict(schema='ec-c4-capacity-vivado/1',status='STARTING',pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],
   host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),started_utc=now(),
   input_dcp=str(dcp),input_dcp_sha256=d['sha256'],hardware_commit=s['hardware_commit'],source_id=s['source_id'],
   work_dir=str(OUT),argv=argv,fpga_access=False,rtl_modified=False,dut_synthesis=False,
   certification='DIAGNOSTIC_ONLY_NOT_ADMITTED_TO_EXPERIMENT')
 save(STATE,st)
 with (OUT/'capacity.log').open('ab',buffering=0) as log:
  p=subprocess.Popen(argv,cwd=OUT,env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'8'},stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,start_new_session=True)
  st.update(status='RUNNING',child_pid=p.pid,child_start_ticks=proc(p.pid)['start_ticks']);save(STATE,st)
  while p.poll() is None:
   try:p.wait(timeout=30)
   except subprocess.TimeoutExpired:pass
   st.update(updated_utc=now(),free_gib=shutil.disk_usage(OUT).free/2**30);save(STATE,st);os.fsync(log.fileno())
  st.update(status='COMPLETE' if p.returncode==0 else 'FAILED_WITH_EVIDENCE',returncode=p.returncode,ended_utc=now())
  save(STATE,st)
 assert p.returncode==0
if __name__=='__main__':main()
