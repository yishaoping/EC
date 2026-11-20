#!/usr/bin/env python3
"""Check emitted bit-heap by exact integer conservation, then matched OOC map.

The full SAT timeout remains evidence. This is a separate compositional proof
of the parsed concrete RTL grammar, not a full-DUT or sequential proof.
"""
import collections
import datetime as dt
import fcntl
import hashlib
import itertools
import json
import math
import os
from pathlib import Path
import re
import subprocess
import time

from board_batch import W,D,save,sha
from job_service import proc,boot
from summarize_opt4_fit import resources

BASE=D/'build-logs/Opt4-fit-address-probes4-20261110/heap80'
O=D/'build-logs/Opt4-fit-address-heap-proof-20261110'
S=D/'Opt4-fit-address-heap-proof-state.json'
now=lambda:dt.datetime.now(dt.timezone.utc).isoformat()


def verify_heap(text,n=80):
    """Induction: each exhaustively checked 3..6 bit compressor preserves
    the nonnegative weighted sum. Parse/consume actual wire references, not an
    independently regenerated intended network. A leaf bound prevents final
    carry truncation; every intermediate counter retains its original width.
    """
    lines=text.splitlines();assert lines[0]==f'module Heap(input [{n*17-1}:0] terms,output [255:0] result);'
    assert lines[-1]=='endmodule'
    proofs={}
    for count in range(3,7):
        width=math.ceil(math.log2(count+1))
        for bits in itertools.product([0,1],repeat=count):
            value=sum(bits);digits=[(value>>j)&1 for j in range(width)]
            assert sum(v*(1<<j) for j,v in enumerate(digits))==value
        proofs[str(count)]=dict(input_bits=count,cases=2**count,width=width,status='EXHAUSTIVE_UNIVERSAL')
    pos=1;offset=0;results=[]
    for g,(source_width,bound) in enumerate(zip([7,5,4,1],[8,3,2,1])):
        width=math.ceil(math.log2(n*bound+1));pending=collections.Counter();compressors=0
        for _ in range(n):
            for j in range(math.ceil(math.log2(bound+1))):pending[(f'terms[{offset+j}]',1<<j)]+=1
            # Under 0<=leaf<=bound, all omitted high leaf bits equal zero.
            assert bound < (1<<math.ceil(math.log2(bound+1)))
            offset+=source_width
        while pos<len(lines):
            m=re.fullmatch(r'wire \[(\d+):0\] (g'+str(g)+r'_c(\d+)_p\d+) = (.*);',lines[pos])
            if not m:break
            high,name,col,expr=m.groups();width_c=int(high)+1;weight=1<<int(col)
            terms=expr.split(' + ');assert len(terms) in range(3,7)
            assert width_c==math.ceil(math.log2(len(terms)+1))
            for term in terms:
                atom=re.fullmatch(r"\{"+str(width_c-1)+r"'b0,((?:terms|g\d+_c\d+_p\d+)\[\d+\])\}",term)
                assert atom,term
                key=(atom[1],weight);assert pending[key]>0,(name,key)
                pending[key]-=1
            for j in range(width_c):pending[(name+'['+str(j)+']',weight*(1<<j))]+=1
            compressors+=1;pos+=1
        for lane in range(2):
            prefix=f'wire [{width-1}:0] g{g}_row{lane} = {{'
            line=lines[pos];assert line.startswith(prefix) and line.endswith('};')
            atoms=line[len(prefix):-2].split(',');assert len(atoms)==width
            for j,atom in enumerate(reversed(atoms)):
                if atom=="1'b0":continue
                key=(atom,1<<j);assert pending[key]>0,(g,lane,key)
                pending[key]-=1
            pos+=1
        leftover=[k for k,v in pending.items() for _ in range(v)]
        assert all(weight>=(1<<width) for atom,weight in leftover)
        assert lines[pos]==f'wire [{width-1}:0] g{g}_sum = g{g}_row0 + g{g}_row1;';pos+=1
        assert lines[pos]==f'assign result[{g*64+63}:{g*64}] = g{g}_sum;';pos+=1
        # Sum <= n*bound < 2**width; all nonnegative leftover high bits
        # must be zero and the final width-sized addition cannot overflow.
        assert n*bound < 1<<width
        results.append(dict(granularity=g,leaf_count=n,leaf_bound=bound,final_width=width,
            maximum_integer_sum=n*bound,compressors=compressors,nonnegative_high_bits=len(leftover),
            status='PARSED_WEIGHTED_CONSERVATION_AND_BOUND_PROVED'))
    assert pos==len(lines)-1
    return dict(status='PASS_COMPOSITIONAL_PARSED_RTL_UNDER_EXPLICIT_LEAF_BOUNDS',
        compressor_lemmas=proofs,granularities=results,scope='Combinational arithmetic only, not full module or DUT')


def verify_reference(text,n=80):
    """Parse balanced reference; every node is exact under interval bounds."""
    assert text.splitlines()[0]==f'module Reference(input [{n*17-1}:0] terms, output [255:0] result);'
    values={};outputs={};leaf_ranges={};node_count=0
    offset=0
    for g,(w,b) in enumerate(zip([7,5,4,1],[8,3,2,1])):
        for i in range(n):
            leaf_ranges[f'g{g}_leaf{i}']=(offset,math.ceil(math.log2(b+1)),b)
            offset+=w
    for line in text.splitlines()[1:-1]:
        m=re.fullmatch(r'wire \[(\d+):0\] (\w+) = terms\[(\d+):(\d+)\];',line)
        if m:
            high,name,hi,lo=m.groups();off,w,bound=leaf_ranges[name]
            assert (int(high)+1,int(hi),int(lo))==(w,off+w-1,off)
            values[name]=(collections.Counter({name:1}),bound);continue
        m=re.fullmatch(r'wire \[(\d+):0\] (\w+) = (\w+) \+ (\w+);',line)
        if m:
            high,name,a,b=m.groups();assert a in values and b in values and name not in values
            coeff=values[a][0]+values[b][0];bound=values[a][1]+values[b][1]
            assert bound < 1<<(int(high)+1)
            values[name]=(coeff,bound);node_count+=1;continue
        m=re.fullmatch(r'assign result\[(\d+):(\d+)\]=(\w+);',line)
        assert m,line
        hi,lo,name=m.groups();g=int(lo)//64
        assert int(hi)==g*64+63 and int(lo)==g*64 and g not in outputs
        coeff,bound=values[name]
        assert coeff==collections.Counter({f'g{g}_leaf{i}':1 for i in range(n)})
        outputs[g]=bound
    assert set(outputs)==set(range(4)) and node_count==4*(n-1)
    return dict(status='PASS_PARSED_REFERENCE_EXACT_UNDER_LEAF_BOUNDS',node_count=node_count,output_bounds=outputs)


def main():
    lock=(D/'.opt4-fit-address-heap-proof.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    O.mkdir(exist_ok=True)
    st=dict(schema='ec-address-heap-compositional-proof/1',pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],
        host_boot_id=boot(),started_utc=now(),status='VERIFYING',fpga_access=False,production_source_changed=False)
    save(S,st)
    rtl=O/'heap.v';ref=O/'reference.v'
    for src,dst in [(BASE/'heap.v',rtl),(BASE/'reference.v',ref)]:
        if dst.exists():assert dst.read_bytes()==src.read_bytes()
        else:dst.write_bytes(src.read_bytes())
    proof=verify_heap(rtl.read_text());reference=verify_reference(ref.read_text())
    # Negative structural mutation must be rejected by independent parsing.
    bad=rtl.read_text().replace("terms[0]","terms[1]",1)
    try:verify_heap(bad)
    except AssertionError:pass
    else:raise AssertionError('malformed weighted network accepted')
    st.update(status='COMPOSITIONAL_PROOF_PASSED_MAPPING',proof=proof,reference=reference,
        rtl_sha256=sha(rtl),reference_sha256=sha(ref),negative_mutation_rejected=True,
        explicit_precondition='Each original full-width term <= [8,3,2,1], already universal SAT-proved from processTouch in round3',
        original_full_sat='TIMEOUT_RETAINED_NOT_RELABELED',formal_admission=False)
    save(O/'proof.json',st);save(S,st)
    tcl=O/'map.tcl';report=O/'utilization.rpt';dcp=O/'module.dcp'
    tcl.write_text('set_param general.maxThreads 4\n'+f'read_verilog {{{rtl}}}\n'
        +'synth_design -top Heap -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized\n'
        +f'report_utilization -file {{{report}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
    argv=['nice','-n','18','/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(O/'vivado.log'),'-source',str(tcl)]
    receipt=O/'mapping-result.json'
    if receipt.exists():
        old=json.loads(receipt.read_text());assert old['rtl_sha256']==sha(rtl) and old['tcl_sha256']==sha(tcl)
        assert old['report_sha256']==sha(report) and old['checkpoint_sha256']==sha(dcp)
    else:
        with (O/'console.log').open('ab',buffering=0) as log:
            p=subprocess.Popen(argv,cwd=O,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,
                start_new_session=True,env={**os.environ,'LD_LIBRARY_PATH':''})
            st.update(child_pid=p.pid,child_start_ticks=proc(p.pid)['start_ticks']);save(S,st)
            while p.poll() is None:
                try:p.wait(timeout=30)
                except subprocess.TimeoutExpired:pass
                st.update(updated_utc=now());save(S,st);os.fsync(log.fileno())
        assert p.returncode==0,(p.returncode,str(O/'console.log'))
        save(receipt,dict(returncode=0,rtl_sha256=sha(rtl),tcl_sha256=sha(tcl),report_sha256=sha(report),checkpoint_sha256=sha(dcp)))
    st.pop('child_pid',None);st.pop('child_start_ticks',None)
    st.update(status='COMPOSITIONALLY_PROVED_MICRO_MAP_COMPLETE_NOT_INSTALLED',resources=resources(report),ended_utc=now())
    save(S,st);save(O/'result.json',st)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        if S.exists():
            st=json.loads(S.read_text());st.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now());save(S,st)
        raise
