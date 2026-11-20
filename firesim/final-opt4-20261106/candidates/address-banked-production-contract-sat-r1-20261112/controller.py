#!/usr/bin/python3
"""Prove the actual generated bank's combinational production interface.

All storage bits are cut into arbitrary inputs. This is a local contract
proof, not whole-target or GoldenGate sequential equivalence.
"""
from pathlib import Path
import fcntl
import json
import os
import re
import resource
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-address-banked-production-contract-sat-r1-20261112'
SOURCE = D/'build-logs/Opt4-address-banked-production-host-r1-20261112/Proof-target/ProductionProofCandidate.v'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import identity, now, save, sha
ST = {}


def stage(name,script):
    path = O/(name+'.ys')
    assert not path.exists()
    path.write_text(script)
    log = O/(name+'.log')
    start=time.monotonic()
    with log.open('xb',buffering=0) as out:
        child=subprocess.Popen(['/usr/local/bin/yosys','-Q','-T','-s',str(path)],
            cwd=O,stdin=subprocess.DEVNULL,stdout=out,stderr=subprocess.STDOUT)
        while child.poll() is None:
            ST.update(status='RUNNING_'+name.upper(),active_stage=name,child=identity(child.pid),
                updated_utc=now(),stage_seconds=time.monotonic()-start)
            save(O/'state.json',ST)
            try:child.wait(timeout=30)
            except subprocess.TimeoutExpired:pass
    save(O/(name+'-receipt.json'),dict(returncode=child.returncode,seconds=time.monotonic()-start,
        script_sha256=sha(path),log_sha256=sha(log)))
    assert child.returncode==0,(name,child.returncode)
    return log


def main():
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(),'Adopt existing proof'
    os.sched_setaffinity(0,{224,225});resource.setrlimit(resource.RLIMIT_AS,(32*2**30,)*2)
    ST.update(schema='ec-actual-bank-production-contract-sat/1',**identity(),started_utc=now(),
        cpus=[224,225],functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
        source=str(SOURCE),source_sha256=sha(SOURCE),fpga_access=False,full_system_fit=False,
        scope='Arbitrary bucket state, complete88query sequence-match, current/retiring collision and all20retiring64bitwords. Aligned16lanebase. Local combinational proof only.')
    save(O/'state.json',ST)
    actual=(O/'actual-bank.sv').read_text()
    assert actual==SOURCE.read_text().split('\nendmodule',1)[0]+'\nendmodule\n'
    cut=O/'cut-bank.json'
    assert cut.is_file(), 'Authenticated preparation required'
    bank=json.loads(cut.read_text())['modules']['BucketBank']
    expected={}
    inputs=[]
    for name,v in bank['ports'].items():
        if v['direction']=='input' and (name.startswith('bucket') or name in
                ['io_base','io_processSeq','io_retiringSeq'] or name.startswith('io_querySeq_')):
            bits=len(v['bits']);inputs.append((name,bits))
    assert len([n for n,w in inputs if n.startswith('bucket')])==352
    assert len([n for n,w in inputs if n.startswith('io_querySeq')])==88
    outputs=[n for n,v in bank['ports'].items() if v['direction']=='output' and
        (n.startswith('io_queryMatch_') or n in ['io_currentCollision','io_retiringValid','io_retiringCollision']
         or n.startswith('io_retiringWords_'))]
    assert len(outputs)==111
    lines=['module Contract(\n'+',\n'.join('input '+(f'[{w-1}:0] ' if w>1 else '')+n for n,w in inputs)+',\noutput ok\n);']
    for n in outputs:
        w=len(bank['ports'][n]['bits']);lines.append('wire '+(f'[{w-1}:0] ' if w>1 else '')+n+';')
    conns=[]
    input_names={n for n,w in inputs}
    for n,v in bank['ports'].items():
        if v['direction']=='input':
            value=n if n in input_names else f"{len(v['bits'])}'b0"
            conns.append('.'+n+'('+value+')')
        elif n in outputs:conns.append('.'+n+'('+n+')')
    lines+=['BucketBank dut('+','.join(conns)+');']
    checks=[]
    def mux(names,index):
        # A structurally different dynamic selector, compared with actual
        # generated onehot bank selection for arbitrary valid/invalid payload.
        w=1 if names[0].startswith('bucketValid') else 32 if names[0].startswith('bucketSeq') else 64
        vname='view_'+str(len(expected));expected[vname]=True
        lines.append(f'wire [{len(names)*w-1}:0] {vname} = '+'{'+','.join(reversed(names))+'};')
        return f'(({vname} >> ({index} * {w})) & {w}\'h'+('f'*((w+3)//4) if w>1 else '1')+')'
    valid=lambda idx:mux(['bucketValid_'+str(i) for i in range(16)],idx)
    seq=lambda idx:mux(['bucketSeq_'+str(i) for i in range(16)],idx)
    for q in range(88):
        name=f'io_querySeq_{q}'
        wanted=f'({name}[7:4]==io_base[7:4] && {valid(name+"[3:0]")} && ({seq(name+"[3:0]")} >> 8)=={name}[31:8])'
        checks.append(f'(io_queryMatch_{q} == {wanted})')
    for label,name in [('current','io_processSeq'),('retiring','io_retiringSeq')]:
        v=valid(name+'[3:0]');s=seq(name+'[3:0]')
        checks.append(f'(io_{label}Collision == ({name}[7:4]==io_base[7:4] && {v} && ({s} >> 8)!={name}[31:8]))')
    checks.append(f'(io_retiringValid == (io_retiringSeq[7:4]==io_base[7:4] && {valid("io_retiringSeq[3:0]")}))')
    metrics=['bucketStore','bucketFirstStore','bucketLoadFirst','bucketStoreFirst','bucketStrictWriteRead']
    for m,metric in enumerate(metrics):
        for g in range(4):
            value=mux([f'{metric}_{i}_{g}' for i in range(16)],'io_retiringSeq[3:0]')
            checks.append(f"(io_retiringWords_{m}_{g} == (io_retiringSeq[7:4]==io_base[7:4] ? {value} : 64'b0))")
    lines.append("assign ok = (io_base[3:0]!=4'b0) || ("+' && '.join(checks)+');\nendmodule\n')
    wrapper=O/'contract.sv';wrapper.write_text('\n'.join(lines))
    prefix=f'read_json {cut}\nread_verilog -sv {wrapper}\nhierarchy -top Contract\nflatten\nopt -full\ncheck -assert\nsat -verify -timeout 300 -prove ok 1 -show-inputs -show-outputs\n'
    log=stage('prove-production-contract',prefix)
    assert 'SAT proof finished - no model found: SUCCESS!' in log.read_text()
    mutated=O/'contract-negative.sv'
    # A real changed query output is rejected by the same proof, ensuring
    # that the selected-output miter is connected and non-vacuous.
    negative=wrapper.read_text().replace('io_queryMatch_0 ==','~io_queryMatch_0 ==',1)
    assert negative!=wrapper.read_text();mutated.write_text(negative)
    negative_script=prefix.replace(str(wrapper),str(mutated)).replace('sat -verify -timeout 300 -prove ok 1','sat -timeout 60 -prove ok 1')
    neg=stage('negative-query-mutation',negative_script)
    assert 'SAT proof finished - model found: FAIL!' in neg.read_text()
    ST.update(status='PASS_ACTUAL_GENERATED_BANK_ARBITRARY_STATE_PRODUCTION_CONTRACT',
        output_checks=len(checks),query_outputs=88,retirement_words=20,arbitrary_state=True,
        invalid_payload_preserved=True,negative_detected=True,full_formal_equivalence=False,
        whole_target_equivalence=False,host_transform_equivalence=False,
        generated_bank_sha256=sha(O/'actual-bank.sv'),cut_bank_sha256=sha(cut),
        contract_sha256=sha(wrapper),ended_utc=now(),child={})
    save(O/'state.json',ST);save(O/'result.json',ST)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        if ST:
            ST.update(status='FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED',error=repr(exc),ended_utc=now())
            save(O/'state.json',ST);save(O/'failure.json',ST)
        raise
