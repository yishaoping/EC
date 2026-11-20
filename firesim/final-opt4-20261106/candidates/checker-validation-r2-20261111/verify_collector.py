#!/usr/bin/python3
"""Offline synthetic fixtures for the pinned real sample validator. No FPGA data."""
from pathlib import Path
import copy,importlib.util,json,sys,hashlib
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import save,sha,now
runtime=W/'runtime/Opt4-fit-9ae9a7fc/scripts/run_isolated_sample.py'
# Importing the collector defines functions only. No main(), run() or devices.
spec=importlib.util.spec_from_file_location('derived_collector_test',runtime);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
O=D/'build-logs/Opt4-checker-collector-validation-r2-20261111';O.mkdir(exist_ok=True)
identity=dict(configuration='C4',run_id='SYNTHETIC_FIXTURE_NOT_EXPERIMENT',memory_model=dict(settings={'read_latency':20}))
start='EC_OPT4_SNAPSHOT epoch=1 begin=100 end=0 drain=0 generated=0 completed=0 outstanding=0 faults=0 passed=0 failed=0 cancelled=0 dropped=0\n'
end='EC_OPT4_SNAPSHOT epoch=1 begin=100 end=200 drain=240 generated=4 completed=4 outstanding=0 faults=0 passed=4 failed=0 cancelled=0 dropped=0\n'
uart='EC_OPT4_CONTEXT satp=8000000000080001 hardware_initialized=1\n'+''.join('EC_OPT4_INSTALLED hart=%d satp=8000000000080001\n'%h for h in range(1,5))+start+end+'EC_OPT4_CONTEXT_DRAINED firmware=f satp=8000000000080001 epoch=1 generated=4 completed=4 outstanding=0\nEC_SAMPLE_GUEST_DONE run_id=SYNTHETIC_FIXTURE_NOT_EXPERIMENT verified=1\nEC_COMMAND_EXIT=0\nPower down\n'
events=''.join('EC_OPT4_PACKAGE_BEGIN hart=%d seq=%08x satp=8000000000080001 prv=0\nEC_OPT4_PACKAGE_RESULT hart=%d seq=%08x status=0 full_compare=1 cancelled=0\n'%(h,h,h,h) for h in range(1,5))
host='EC_FASED_READBACK key=read_latency expected=20 actual=20\nEC_HOST_INTERVAL target_start=0 target_end=1000 target_delta=1000 host_delta=2000 wall_seconds=1.0 throughput_cycles_per_second=1000.0\n'
fixtures=[('baseline',uart,events,host,False,True),('real_compare_fail',uart,events.replace('status=0 full_compare=1','status=1 full_compare=1',1),host,False,False),('compare_disabled',uart,events.replace('full_compare=1','full_compare=0',1),host,False,False),('unfinished',uart,events.rsplit('EC_OPT4_PACKAGE_RESULT',1)[0],host,False,False),('wrong_sequence',uart,events.replace('hart=1 seq=00000001 status','hart=1 seq=0000ffff status'),host,False,False),('duplicate_result',uart,events+events.splitlines()[1]+'\n',host,False,False),('fault_counter',uart.replace('faults=0 passed=4','faults=1 passed=4'),events,host,False,False),('undrained',uart.replace('outstanding=0 faults=0 passed=4','outstanding=1 faults=0 passed=4'),events,host,False,False),('wrong_context',uart,events.replace('satp=8000000000080001','satp=8000000000080002',1),host,False,False),('timeout',uart,events,host,True,False),('missing_output',uart.replace('EC_SAMPLE_GUEST_DONE','INCOMPLETE'),events,host,False,False),('memory_mismatch',uart,events,host.replace('actual=20','actual=21'),False,False),('cancelled',uart,events.replace('cancelled=0','cancelled=1',1),host,False,False)]
rows=[]
for name,u,e,h,timed,expected in fixtures:
 p=O/name;p.mkdir(exist_ok=True);(p/'uart.log').write_text(u);(p/'rtl-events-fixture.log').write_text(e);(p/'host.log').write_text(h)
 r=m.verify(p,identity,0,False,timed);assert r['valid']==expected,(name,r)
 rows.append(dict(case=name,expected_valid=expected,observed_valid=r['valid'],issues=r['issues']))
r=dict(schema='ec-offline-collector-verification/1',status='PASS_13_SYNTHETIC_FIXTURES',utc=now(),hardware_commit='9ae9a7fcf231a75259e23973b12a93896a443cbb',source_id='3791dd0e8f7d9c380500cd37f11ece4c92e275bc399894780228fa61449df561',validator=str(runtime),validator_sha256=sha(runtime),cases=rows,fpga_execution=False,real_checker_execution=False,rollback_validated=False,limit='Collector rejection behavior only. Synthetic logs are never stored in runs/ or admitted as FPGA samples; no evidence of hardware fault injection or architectural restart.')
save(O/'result.json',r);print(json.dumps(dict(status=r['status'],cases=len(rows),evidence=str(O/'result.json'))))
