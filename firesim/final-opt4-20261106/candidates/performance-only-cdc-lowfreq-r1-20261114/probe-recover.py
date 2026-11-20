#!/usr/bin/env python3
import json,os,subprocess,time
from pathlib import Path
O=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/performance-only-cdc-lowfreq-r1-20261114')
C=Path('/data1/gzh/EC/firesim/final-opt4-20261106/candidates/performance-only-cdc-lowfreq-r1-20261114')
os.sched_setaffinity(0,{248,249})
u='ec-performance-only-lowfreq-clock-probe-r1-20261114.service'
while subprocess.check_output(['systemctl','--user','show',u,'-p','ActiveState','--value'],text=True).strip() in ['active','activating']:
 time.sleep(15)
# Initial attempt lost literal-bracket clock names during pattern lookup.
# Reject its receipt even if the final methodology report has zero clock rules.
old=O/'clock-probe';archived=O/'clock-probe-rejected-r1'
assert not archived.exists()
old.rename(archived);old.mkdir()
(archived/'REJECTED.json').write_text(json.dumps(dict(status='REJECTED_CLOCK_GROUP_QUERY_PATTERN',reason='Original clock names containing [3] were treated as patterns. Replaced by exact NAME equality filters and verified every original clock object after replay.'),indent=2)+'\n')
with (old/'service.log').open('wb') as log:
 p=subprocess.run(['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(old/'vivado.log'),'-source',str(C/'clock-probe-r2.tcl')],cwd=old,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT)
assert p.returncode==0 and (old/'complete').is_file(),'Corrected clock proof failed; preserve logs, no implementation admission'
(O/'clock-probe-r2-result.json').write_text(json.dumps(dict(status='PASS_REAL_HOST_CLOCK_AND_EXACT_CLOCK_GROUP_REPLAY',proof_dir=str(old),prior_rejected=str(archived)),indent=2)+'\n')
