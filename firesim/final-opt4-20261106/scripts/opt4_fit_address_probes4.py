#!/usr/bin/env python3
"""Independent, bounded address arithmetic probes. No DUT or FPGA changes."""
import datetime as dt
import fcntl
import json
import math
import os
from pathlib import Path
import subprocess
import time

from board_batch import W, D, save, sha
from job_service import proc, boot
from opt4_fit_address_round3 import emit_tree, emit_increment
from summarize_opt4_fit import resources

O = D/'build-logs/Opt4-fit-address-probes4-20261110'
S = D/'Opt4-fit-address-probes4-state.json'
PARENT = 'aca893e0aa3f7e23e16067ab40713afea41558e8'
now = lambda: dt.datetime.now(dt.timezone.utc).isoformat()


def heap_tree(path, n):
    """Exact bit heap; six input bits become a 3-bit population count.

    No registers or cycle boundary changes. Inputs use the already proved
    [8,3,2,1] bounds. Final truncation is safe under those explicit bounds.
    """
    lines = [f'module Heap(input [{n*17-1}:0] terms,output [255:0] result);']
    offset = 0
    for g, (source_width, bound) in enumerate(zip([7,5,4,1], [8,3,2,1])):
        width = math.ceil(math.log2(n*bound+1))
        cols = [[] for _ in range(width+8)]
        for _ in range(n):
            for j in range(math.ceil(math.log2(bound+1))):
                cols[j].append(f'terms[{offset+j}]')
            offset += source_width
        serial = 0
        for col in range(width):
            while len(cols[col]) > 2:
                group = cols[col][:6]
                del cols[col][:len(group)]
                bits = math.ceil(math.log2(len(group)+1))
                name = f'g{g}_c{col}_p{serial}'
                serial += 1
                expr = ' + '.join("{"+str(bits-1)+"'b0,"+b+"}" for b in group)
                lines.append(f'wire [{bits-1}:0] {name} = {expr};')
                for j in range(bits):
                    cols[col+j].append(f'{name}[{j}]')
        rows = []
        for lane in range(2):
            value = ','.join(cols[j][lane] if len(cols[j]) > lane else "1'b0"
                             for j in range(width-1,-1,-1))
            name = f'g{g}_row{lane}'
            lines.append(f'wire [{width-1}:0] {name} = {{{value}}};')
            rows.append(name)
        lines.append(f'wire [{width-1}:0] g{g}_sum = {rows[0]} + {rows[1]};')
        lines.append(f'assign result[{g*64+63}:{g*64}] = g{g}_sum;')
    lines.append('endmodule')
    path.write_text('\n'.join(lines)+'\n')


def main():
    lock = (D/'.opt4-fit-address-probes4.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    O.mkdir(exist_ok=True)
    st = dict(schema='ec-opt4-fit-address-probes4/1', status='STARTING',
              pid=os.getpid(), start_ticks=proc(os.getpid())['start_ticks'],
              host_boot_id=boot(), started_utc=now(), parent_commit=PARENT,
              fpga_access=False, production_source_changed=False,
              full_dut_synthesis=False, formal_admission=False, stages={}, maps={}, proofs={})
    save(S,st)

    def run(label, argv, cwd, outputs, timeout=1200):
        receipt=cwd/(label+'-result.json')
        if receipt.exists():
            old=json.loads(receipt.read_text())
            assert old['returncode']==0
            assert all(sha(p)==h for p,h in old['inputs'].items())
            assert all(sha(p)==h for p,h in old['outputs'].items())
            st['stages'][label]=old;save(S,st);return
        inputs={str(p):sha(p) for p in cwd.glob('*.v')}
        inputs.update({str(p):sha(p) for p in cwd.glob('*.tcl')})
        attempt=len(list(cwd.glob(label+'-attempt-*.log')))+1
        log=cwd/(label+f'-attempt-{attempt}.log')
        start=time.monotonic()
        with log.open('ab',buffering=0) as f:
            child=subprocess.Popen(['nice','-n','18',*map(str,argv)],cwd=cwd,
                stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,
                start_new_session=True,env={**os.environ,'LD_LIBRARY_PATH':''})
            st.update(status='RUNNING_'+label.upper(),active_step=label,
                child_pid=child.pid,child_start_ticks=proc(child.pid)['start_ticks'])
            save(S,st)
            while child.poll() is None:
                try:child.wait(timeout=30)
                except subprocess.TimeoutExpired:pass
                if child.poll() is None and time.monotonic()-start>timeout:
                    # Only this probe's own process group, never any CAD/DUT job.
                    os.killpg(child.pid,15)
                    try:child.wait(timeout=20)
                    except subprocess.TimeoutExpired:os.killpg(child.pid,9);child.wait()
                    raise RuntimeError(label+' probe timeout')
                st.update(updated_utc=now(),elapsed_seconds=time.monotonic()-start)
                save(S,st);os.fsync(f.fileno())
        st.pop('child_pid',None);st.pop('child_start_ticks',None)
        assert child.returncode==0,(label,child.returncode,str(log))
        item=dict(returncode=0,inputs=inputs,outputs={str(p):sha(p) for p in outputs},
                  log=str(log),ended_utc=now(),wall_seconds=time.monotonic()-start)
        save(receipt,item);st['stages'][label]=item;save(S,st)

    # Bounded, universal combinational equivalence before either map.
    for n in [8,80]:
        sub=O/('heap'+str(n));sub.mkdir(exist_ok=True)
        ref=sub/'reference.v';cand=sub/'heap.v';proof=sub/'proof.v'
        emit_tree(ref,'Reference',n,True);heap_tree(cand,n)
        offset=0;bounds=[]
        for w,b in zip([7,5,4,1],[8,3,2,1]):
            for _ in range(n):
                bounds.append(f'(terms[{offset+w-1}:{offset}] <= {w}\'d{b})');offset+=w
        proof.write_text(f'module proof(input [{n*17-1}:0] terms,output ok);'
            'wire [255:0] a,b;Reference r(terms,a);Heap h(terms,b);'
            'assign ok= !('+' && '.join(bounds)+') || a==b;endmodule\n')
        script=f'read_verilog {ref} {cand} {proof}; prep -top proof -flatten; sat -verify -prove ok 1 -timeout 240'
        old_failure=sorted(sub.glob('proof'+str(n)+'-attempt-*.log'))
        timed_out=old_failure and 'proof did time out' in old_failure[-1].read_text(errors='replace')
        if timed_out:
            st['proofs']['heap'+str(n)]=dict(status='UNPROVEN_TIMEOUT_NOT_ADMITTED',log=str(old_failure[-1]))
        else:
            try:
                run('proof'+str(n),['/usr/local/bin/yosys','-Q','-T','-p',script],sub,[ref,cand,proof],300)
                st['proofs']['heap'+str(n)]=dict(status='PASS_BOUNDED_UNIVERSAL',input_bits=n*17)
            except (RuntimeError,AssertionError) as exc:
                st['proofs']['heap'+str(n)]=dict(status='UNPROVEN_NOT_ADMITTED',error=repr(exc))
        save(S,st)
    probes=[]
    for kind in ['dsp-wire','dsp-module','wide']:
        sub=O/kind;sub.mkdir(exist_ok=True);rtl=sub/'increment.v'
        emit_increment(rtl,'Increment','wide')
        content=rtl.read_text()
        if kind=='dsp-module':content=content.replace('module Increment','(* use_dsp = "yes" *) module Increment')
        if kind=='dsp-wire':
            import re
            content=re.sub(r'assign result\[(\d+):(\d+)\]=([^;]+);',
                lambda m:'(* use_dsp = "yes" *) wire [64:0] sum'+m[2]+'='+m[3]+';\nassign result['+m[1]+':'+m[2]+']=sum'+m[2]+';',content)
        rtl.write_text(content)
        # Mapping attributes do not change RTL arithmetic, but bind and prove
        # the emitted one-lane expression instead of assuming this fact.
        ref=sub/'reference.v';emit_increment(ref,'Reference','wide',1)
        one=sub/'one.v';emit_increment(one,'Candidate','wide',1)
        one.write_text(one.read_text().replace('module Candidate','(* use_dsp = "yes" *) module Candidate'))
        proof=sub/'proof.v';proof.write_text('module proof(input [63:0] a,input [9:0] d,output ok);wire [64:0] x,y;Reference r(a,d,x);Candidate c(a,d,y);assign ok=x==y;endmodule\n')
        script=f'read_verilog {ref} {one} {proof}; prep -top proof -flatten; sat -verify -prove ok 1 -timeout 120'
        run('arithmetic-proof',['/usr/local/bin/yosys','-Q','-T','-p',script],sub,[ref,one,proof],180)
        st['proofs'][kind]=dict(status='PASS_UNIVERSAL_74_INPUT_BITS',mapping_validation='RTL arithmetic only; mapped simulation still required')
        save(S,st)
        probes.append((kind,sub,rtl,'Increment'))
    if st['proofs']['heap80']['status']=='PASS_BOUNDED_UNIVERSAL':
        probes.append(('heap80',O/'heap80',O/'heap80/heap.v','Heap'))
    for label,sub,rtl,top in probes:
        tcl=sub/'map.tcl';report=sub/'utilization.rpt';dcp=sub/'module.dcp'
        tcl.write_text('set_param general.maxThreads 4\n'+f'read_verilog {{{rtl}}}\n'
            +f'synth_design -top {top} -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized\n'
            +f'report_utilization -file {{{report}}}\nwrite_checkpoint -force {{{dcp}}}\n'
            +f'write_verilog -force -mode funcsim {{{sub/"mapped.v"}}}\n'
            +'puts "EC_ADDRESS_PROBE4_MAP_COMPLETE"\nexit 0\n')
        run(label,['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal',
                   '-log',sub/'vivado.log','-source',tcl],sub,[report,dcp,sub/'mapped.v'])
        st['maps'][label]=dict(resources=resources(report),report=str(report),
            report_sha256=sha(report),rtl_sha256=sha(rtl),scope='micro probe only; not whole module or DUT')
        save(S,st)
    st.update(status='PROBES_MAPPED_NOT_INSTALLED',ended_utc=now())
    save(S,st);save(O/'result.json',st)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        if S.exists():
            st=json.loads(S.read_text());st.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now());save(S,st)
        raise
