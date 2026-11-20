#!/usr/bin/python3
"""Small read-only audit of completed r3 events; never run another workload.

Pair identities across checker/BOOM domains, but subtract cycles only between
allocation and acceptance in the same BOOM observer/timebase.
"""
import copy
import csv
import datetime
import hashlib
import json
import math
from collections import Counter
from pathlib import Path

W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
R=D/'cycleprecise-frozen-full-gg-external-observer-r3-20261111'
A=D/'build-logs/Opt4-full-gg-package-analysis-round37-v1-20261111'
O=D/'build-logs/Opt4-boom-accepted-evidence-round43-v1-20261111'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
def read(p):return json.loads(p.read_text())
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def save(p,j):
    with p.open('x') as f:json.dump(j,f,indent=2,sort_keys=True);f.write('\n')

def validate(rows,local):
    assert rows[0]['kind']=='HEADER' and rows[-1]['kind']=='END'
    assert [r['record'] for r in rows[1:]]==list(range(1,len(rows)))
    allocations={};accepted={};previous=0;offsets=set()
    for r in rows[1:-1]:
        seq=r['package_seq'];assert seq>0
        tick=r['fastest_target_cycle'];assert tick>=previous;previous=tick
        offsets.add(tick-r['boom_csr_cycle'])
        if r['kind']=='BOOM_ALLOC':
            assert seq not in allocations and seq not in accepted
            if allocations:assert seq==max(allocations)+1
            allocations[seq]=r
        else:
            assert r['kind']=='BOOM_RESULT_ACCEPTED'
            assert seq in allocations and seq not in accepted
            assert r['status']==0 and 1<=r['checker']<=4
            assert (r['raw_payload']&0xffffffff)==seq
            assert ((r['raw_payload']>>32)&3)==r['status'] and (r['raw_payload']>>34)>0
            assert r['fastest_target_cycle']>=allocations[seq]['fastest_target_cycle']
            accepted[seq]=r
    assert offsets=={1969}, 'timebase mapping changed; review before measuring intervals'
    assert set(allocations)==set(accepted)==set(range(1,132))
    checker={}
    for e in local:
        if e['event']=='LOCAL_RESULT_QUEUE_ENQUEUE':
            assert e['seq'] not in checker
            assert e['status']==0 and e['full_compare']==1 and e['cancelled']==0
            checker[e['seq']]=e
    assert set(checker)==set(accepted)
    for seq,e in checker.items():assert e['hart']==accepted[seq]['checker']
    end=rows[-1]
    assert (end['allocations'],end['accepted'],end['passed'],end['failed'],end['cancelled'],end['sample_errors'])==(131,131,131,0,0,0)
    pairs=[]
    for seq in sorted(allocations):
        a,b=allocations[seq],accepted[seq]
        delta=b['boom_csr_cycle']-a['boom_csr_cycle']
        assert delta==b['fastest_target_cycle']-a['fastest_target_cycle']
        pairs.append(dict(seq=seq,checker=b['checker'],status=b['status'],
            allocated_fastest_target_cycle=a['fastest_target_cycle'],accepted_fastest_target_cycle=b['fastest_target_cycle'],
            allocated_BOOM_csr_cycle=a['boom_csr_cycle'],accepted_BOOM_csr_cycle=b['boom_csr_cycle'],
            allocation_to_BOOM_acceptance_cycles=delta))
    return pairs

def main():
    policy=read(D/'unattended-opt4/campaign-policy.json')
    assert policy['functional_baseline_commit']==BASE and policy['native_paused'] and not policy['fpga_access']
    assert not O.exists(),'immutable audit exists; adopt it'
    rr,ar=read(R/'result.json'),read(A/'result.json')
    assert rr['valid_finite_observation'] and rr['status']=='PASS_SAME_ELF_CAPTURED_PARITY_AND_FINITE_BOOM_ACCEPTANCE'
    assert rr['functional_baseline']==ar['functional_baseline']==BASE
    assert rr['elf_sha256']==ar['input_elf_sha256']
    assert rr['original_prints_and_application_and_target_count_match']
    original=Path(ar['original_result']);ref=read(original)
    assert sha(original)==ar['original_result_sha256']
    for name in ['rtl-prints-0','rtl-prints-1']:
        expected=ref['files'][str(original.parent/name)]
        assert rr['full']['print_streams'][name]==expected
    events=R/'canneal-observer-on/external-events.jsonl'
    local=A/'checker-local-events.json'
    assert sha(events)==rr['full']['files'][str(events)]
    assert sha(local)==ar['files'][str(local)]
    rows=[json.loads(x) for x in events.read_text().splitlines()]
    checker=read(local);pairs=validate(rows,checker)
    # Required identity/status rejection checks, independently of the producer.
    negatives={};idx=next(i for i,r in enumerate(rows) if r['kind']=='BOOM_RESULT_ACCEPTED')
    for name in ['checker','status','payload-seq','duplicate','missing']:
        changed=copy.deepcopy(rows)
        if name=='checker':changed[idx]['checker']=4
        elif name=='status':changed[idx]['status']=1
        elif name=='payload-seq':changed[idx]['raw_payload']^=1
        elif name=='duplicate':changed.insert(idx+1,copy.deepcopy(changed[idx]))
        else:changed.pop(idx)
        for record,event in enumerate(changed[1:],1):event['record']=record
        try:validate(changed,checker)
        except AssertionError:negatives[name]='REJECTED'
        else:raise AssertionError('mutation accepted: '+name)
    values=sorted(p['allocation_to_BOOM_acceptance_cycles'] for p in pairs)
    stats=dict(n=len(values),mean_numerator=sum(values),mean_denominator=len(values),
        mean=sum(values)/len(values),median=values[len(values)//2],
        p95=values[math.ceil(.95*len(values))-1],p99=values[math.ceil(.99*len(values))-1],
        min=min(values),max=max(values),histogram=dict(sorted(Counter(values).items())))
    O.mkdir()
    with (O/'per-package.csv').open('x') as f:
        writer=csv.DictWriter(f,fieldnames=list(pairs[0]));writer.writeheader();writer.writerows(pairs)
    result=dict(schema='ec-finite-boom-allocation-result-identity-audit/1',
        status='PASS_131_UNIQUE_ALLOCATIONS_AND_MATCHING_CHECKER_BOOM_ACCEPTED_RESULTS',
        functional_baseline=BASE,source_id=rr['source_id'],completed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
        allocations=131,accepted=131,full_compare_pass=131,failed=0,cancelled=0,unmatched_allocations=0,
        checker_harts=dict(sorted(Counter(p['checker'] for p in pairs).items())),
        timebase='BOOM csr cycles; fastest_target_cycle=BOOM csr+1969 for every observed allocation/result',
        allocation_to_BOOM_result_acceptance_cycles=stats,
        per_package_table_sha256=sha(O/'per-package.csv'),negative_tests=negatives,
        input_sha256={str(p):sha(p) for p in [Path(__file__),R/'result.json',A/'result.json',original,events,local,
            W/'candidates/full-gg-external-observer-r3-20261111/observer_main.cpp']},
        fpga_access=False,formal_fpga_sample=False,full_Opt4_fit=False,full_SVB_drain_proved=False,
        limitations=['Finite CPU Canneal project400 workload; not FPGA/PARSEC r1.',
            'Allocation-to-result-acceptance includes input delivery and checker time; it is not checkerDone minus BOOMDone.',
            'Checker harts matched by sequence/status only; checker and BOOM cycle values were never subtracted.',
            'All observed allocations returned; no inference that every SVB or memory queue is empty.'])
    save(O/'result.json',result);save(O/'complete.json',dict(result_sha256=sha(O/'result.json')))
    print(json.dumps({k:v for k,v in result.items() if k not in ['input_sha256','allocation_to_BOOM_result_acceptance_cycles']}))
    print(json.dumps({k:v for k,v in stats.items() if k!='histogram'}))

if __name__=='__main__':main()
