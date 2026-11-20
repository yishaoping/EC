#!/usr/bin/env python3
"""Measure both complete queues, independently; never claims shell or host FIT."""
import datetime as dt
import hashlib
import json
import os
from pathlib import Path
import subprocess
import time

C = Path(__file__).resolve().parent
O = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/performance-only-memory-cdc-r2-20261114')
A = O / 'area-r1'

def save(status, **kw):
    tmp = A/'state.tmp'
    tmp.write_text(json.dumps(dict(status=status, utc=dt.datetime.now(dt.timezone.utc).isoformat(),
        profile='Performance-Only equivalent GHM data-queue candidate',
        fpga_access=False, model_requests=False, shell_fit=False, generated_host_area=False, **kw), indent=2)+'\n')
    os.replace(tmp, A/'state.json')

def resources(p):
    result = {}
    for line in p.read_text().splitlines():
        c = [x.strip().rstrip('*') for x in line.split('|')]
        if len(c)>6 and c[1] in ['CLB LUTs','CLB Registers','F7 Muxes','F8 Muxes','F9 Muxes','CARRY8','Block RAM Tile','DSPs','URAM']:
            result.setdefault(c[1],float(c[2].replace(',','')))
    return result

def main():
    os.sched_setaffinity(0,{246,247})
    A.mkdir(exist_ok=False)
    save('WAITING_MEMORY_QUEUE_FINITE_CYCLE_EQUIVALENCE')
    start=time.monotonic()
    receipt=O/'run-r1/state.json'
    while True:
        if receipt.is_file():
            status=json.loads(receipt.read_text())['status']
            if status.startswith('PASS_ACTUAL_QUEUE'):break
            if status.startswith('FAILED'):raise RuntimeError('memory queue finite-cycle validation failed')
        if time.monotonic()-start>3600:raise RuntimeError('finite validation gate timed out')
        time.sleep(15)
    # This is exploratory area only; no system admission before formal/host gates.
    rtl=O/'run-r1/target/QueuePair.v'
    digest=hashlib.sha256(rtl.read_bytes()).hexdigest()
    # Same full 305-bit x 256-entry module, same tool, part, clock periods and options.
    rows={}
    for name,top in [('Flat','AsyncQueue'),('Local','LocalMemAsyncQueue')]:
        d=A/name;d.mkdir()
        tcl=d/'run.tcl'
        tcl.write_text(f'''set_param general.maxThreads 2
read_verilog {{{rtl}}}
synth_design -top {top} -part xcu280-fsvh2892-2L-e -mode out_of_context -flatten_hierarchy rebuilt
create_clock -name enqueue -period 20.0 [get_ports io_enq_clock]
create_clock -name dequeue -period 40.0 [get_ports io_deq_clock]
opt_design
report_utilization -file {{{d/'utilization.rpt'}}}
report_utilization -hierarchical -file {{{d/'hierarchical.rpt'}}}
write_checkpoint -force {{{d/'postopt.dcp'}}}
puts "EC_LOCAL_CDC_COMPLETE_MODULE_AREA_DONE"
exit 0
''')
        save('SYNTHESIZING_'+name.upper(),rtl_sha256=digest,complete_module_top=top,results=rows)
        with (d/'stdout.log').open('wb') as f:
            p=subprocess.run(['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(d/'vivado.log'),'-source',str(tcl)],
                cwd=d,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,
                env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'2'},timeout=7200)
        if p.returncode or not (d/'postopt.dcp').is_file():raise RuntimeError((name,'module area failed',p.returncode))
        rows[name]=resources(d/'utilization.rpt')
        assert hashlib.sha256(rtl.read_bytes()).hexdigest()==digest
    delta={k:rows['Flat'][k]-rows['Local'][k] for k in rows['Flat'] if k in rows['Local']}
    save('COMPLETE_QUEUE_PAIR_AREA_MEASURED_NOT_HOST_OR_SHELL',results=rows,savings_per_queue=delta,
        rtl_sha256=digest,capacity=256,payload_bits=305,
        next_action='Use actual paired result with host equivalence and whole-system constraints; never add this delta directly to shell LUT or claim routability.')

if __name__=='__main__':
    try:main()
    except Exception as e:
        if A.is_dir():save('FAILED_WITH_EVIDENCE',error=repr(e))
        raise
