#!/usr/bin/python3
"""Partition actual RTL contracts; exact cone isomorphism covers replicas."""
from pathlib import Path
import functools
import hashlib
import importlib.util
import json
import os
import re
import resource
import fcntl

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
OLD=D/'build-logs/Opt4-address-banked-production-contract-sat-r1-20261112'
O=D/'build-logs/Opt4-address-banked-production-contract-sat-r2-20261112'
spec=importlib.util.spec_from_file_location('immutable_sat_stages',W/'candidates/address-banked-production-contract-sat-r1-20261112/controller.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);m.O=O
from opt4_unattended_common import identity,now,read,save,sha


def main():
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists()
    os.sched_setaffinity(0,{224,225});resource.setrlimit(resource.RLIMIT_AS,(32*2**30,)*2)
    failed=read(OLD/'failure.json')
    assert 'timeout' in (OLD/'prove-production-contract.log').read_text().lower()
    assert sha(m.SOURCE)==failed['source_sha256']
    actual=(OLD/'actual-bank.sv').read_text()
    assert actual==m.SOURCE.read_text().split('\nendmodule',1)[0]+'\nendmodule\n'
    cut=OLD/'cut-bank.json'
    bank=read(cut)['modules']['BucketBank']
    drivers={};ports={}
    for n,v in bank['ports'].items():
        if v['direction']=='input':
            for i,b in enumerate(v['bits']):ports[b]=(n,i)
    for n,c in bank['cells'].items():
        for port,d in c['port_directions'].items():
            if d=='output':
                for i,b in enumerate(c['connections'][port]):
                    if b not in ports:drivers[b]=(n,port,i)
    def cone(output,family):
        @functools.lru_cache(None)
        def h(b):
            if isinstance(b,str):return b
            if b in ports:
                n,i=ports[b]
                if family=='query':n=re.sub(r'^io_querySeq_\d+$','querySeq',n)
                else:n=re.sub(r'^bucket(?:Store|FirstStore|LoadFirst|StoreFirst|StrictWriteRead)_(\d+)_\d$',r'payload_\1',n)
                return hashlib.sha256(repr(('input',n,i)).encode()).hexdigest()
            n,p,i=drivers[b];c=bank['cells'][n]
            ins={p:[h(v) for v in c['connections'][p]] for p,d in c['port_directions'].items() if d=='input'}
            return hashlib.sha256(json.dumps([c['type'],c['parameters'],p,i,ins],sort_keys=True).encode()).hexdigest()
        return hashlib.sha256(json.dumps([h(b) for b in bank['ports'][output]['bits']]).encode()).hexdigest()
    query={str(q):cone('io_queryMatch_'+str(q),'query') for q in range(88)}
    payload={f'{k}_{g}':cone(f'io_retiringWords_{k}_{g}','payload') for k in range(5) for g in range(4)}
    assert len(set(query.values()))==len(set(payload.values()))==1
    save(O/'cone-isomorphism.json',dict(query_hashes=query,payload_hashes=payload,
        normalized_query_input_only=True,normalized_payload_family_and_granule_only=True,
        arbitrary_state_bits_not_constrained=True,cut_json_sha256=sha(cut)))
    source=(OLD/'contract.sv').read_text()
    body=source.rsplit('assign ok = ',1)[1].split(';',1)[0]
    prefix="(io_base[3:0]!=4'b0) || ("
    assert body.startswith(prefix) and body.endswith(')')
    expression=body[len(prefix):-1]
    checks=[];depth=0;start=0;i=0
    while i<len(expression):
        if expression[i]=='(':depth+=1
        elif expression[i]==')':depth-=1
        if depth==0 and expression[i:i+4]==' && ':
            checks.append(expression[start:i]);start=i+4;i+=3
        i+=1
    checks.append(expression[start:]);assert len(checks)==111
    selected={'query':checks[0],'current-collision':checks[88],
        'retiring-collision':checks[89],'retiring-valid':checks[90],'payload':checks[91]}
    m.ST.update(schema='ec-actual-production-contract-partitioned-sat/1',**identity(),started_utc=now(),
        functional_baseline=m.BASE if hasattr(m,'BASE') else '8491167d84b6d9521b151a743673c1516926a1f8',
        cpus=[224,225],fpga_access=False,full_system_fit=False,
        actual_RTL_sha256=sha(m.SOURCE),cut_json_sha256=sha(cut),
        scope='Exact generated bank query/collision/retirement arbitrary-state contracts via SAT plus structurally identical replicas; no target transition or host equivalence claim.')
    save(O/'state.json',m.ST)
    for name,check in selected.items():
        path=O/(name+'.sv')
        text=source.rsplit('assign ok = ',1)[0]+'assign ok = '+prefix+check+');\nendmodule\n'
        path.write_text(text)
        ys=f'read_json {cut}\nread_verilog -sv {path}\nhierarchy -top Contract\nflatten\nwreduce\nopt -full\ncheck -assert\nsat -verify -timeout 120 -prove ok 1\n'
        log=m.stage('prove-'+name,ys)
        assert 'SAT proof finished - no model found: SUCCESS!' in log.read_text()
        save(O/(name+'-pass.json'),dict(check=check,arbitrary_state=True,script_sha256=sha(O/('prove-'+name+'.ys')),log_sha256=sha(log)))
    negative=O/'query-negative.sv'
    negative.write_text((O/'query.sv').read_text().replace('io_queryMatch_0 ==','~io_queryMatch_0 ==',1))
    ys=f'read_json {cut}\nread_verilog -sv {negative}\nhierarchy -top Contract\nflatten\nwreduce\nopt -full\nsat -timeout 60 -prove ok 1\n'
    log=m.stage('negative-query-mutation',ys)
    assert 'SAT proof finished - model found: FAIL!' in log.read_text()
    m.ST.update(status='PASS_ACTUAL_BANK_ARBITRARY_STATE_CONTRACTS_WITH_EXACT_REPLICA_COVERAGE',
        query_outputs=88,payload_words=20,collision_and_valid_outputs=3,checks_covered=111,
        negative_detected=True,full_formal_equivalence=False,target_transition_equivalence=False,
        host_equivalence=False,ended_utc=now(),child={})
    save(O/'state.json',m.ST);save(O/'result.json',m.ST)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        if m.ST:
            m.ST.update(status='FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED',error=repr(exc),ended_utc=now())
            save(O/'state.json',m.ST);save(O/'failure.json',m.ST)
        raise
