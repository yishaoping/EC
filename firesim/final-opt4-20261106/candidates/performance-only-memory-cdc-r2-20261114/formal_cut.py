#!/usr/bin/env python3
"""All-state one-step equivalence; no clock/reset ordering assumptions."""
import copy
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess

O=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/performance-only-memory-cdc-r2-20261114/formal-r2')

def normalized(name):
    return re.sub(r'^source\.mem\[(\d+)\]$',r'source.mem_\1',name)

def states(module):
    result=[]
    for cellname,c in module['cells'].items():
        if c['type'] not in ['$dff','$adff']:continue
        q=c['connections']['Q']
        aliases=[(normalized(n),v) for n,v in module['netnames'].items() if v['bits']==q and not n.startswith('$')]
        assert aliases,(cellname,'state has no public RTL name')
        init={v['attributes']['init'] for _,v in aliases if 'init' in v.get('attributes',{})}
        assert len(init)<=1
        result.append(dict(cellname=cellname,cell=c,aliases={n for n,_ in aliases},init=next(iter(init),None)))
    assert len(result)==315,('unexpected state count',len(result))
    assert not any(c['type'] in ['$dlatch','$aldff','$sdff','$dffe','$adffe'] for c in module['cells'].values())
    return result

def cut(module,matched,names):
    result=copy.deepcopy(module)
    for state,name in zip(matched,names):
        c=state['cell'];del result['cells'][state['cellname']]
        for pin,bits in c['connections'].items():
            port=('state__' if pin=='Q' else pin+'__')+name
            assert port not in result['ports']
            result['ports'][port]=dict(direction='input' if pin=='Q' else 'output',bits=bits)
            result['netnames'][port]=dict(hide_name=0,bits=bits,attributes={})
    return result

def main():
    os.sched_setaffinity(0,{247})
    O.mkdir(exist_ok=False)
    source=O.parent/'formal-r1/flattened.json';raw=json.loads(source.read_text())
    gold,gate=(raw['modules'][n] for n in ['AsyncQueue','LocalMemAsyncQueue'])
    gs,ts=states(gold),states(gate)
    remaining=list(ts);order=[];names=[];mapping=[]
    for g in gs:
        possible=[(t,g['aliases']&t['aliases']) for t in remaining if g['aliases']&t['aliases']]
        assert len(possible)==1,(g['aliases'],'ambiguous state correspondence')
        t,common=possible[0];remaining.remove(t)
        assert g['cell']['type']==t['cell']['type']
        # Yosys memory_map emits a 32-bit CLK_POLARITY=1; proc uses 1-bit 1.
        # Check parameter values, with WIDTH checked separately, not serialization.
        def parameters(c):
            return {k:int(v,2) if isinstance(v,str) and re.fullmatch('[01]+',v) else v
                    for k,v in c['parameters'].items()}
        assert parameters(g['cell'])==parameters(t['cell']),common
        assert g['init']==t['init'],('initial state mismatch',common)
        assert set(g['cell']['connections'])==set(t['cell']['connections'])
        for pin in g['cell']['connections']:
            assert len(g['cell']['connections'][pin])==len(t['cell']['connections'][pin])
        name=sorted(common,key=lambda n:(len(n),n))[0]
        order.append(t);names.append(name)
        mapping.append(dict(state=name,width=len(g['cell']['connections']['Q']),type=g['cell']['type'],
            parameters=g['cell']['parameters'],initial=g['init']))
    assert not remaining
    result=dict(creator='All-state corresponding-register invariant check',modules={
        'FlatCut':cut(gold,gs,names),'MemoryCut':cut(gate,order,names)})
    (O/'cut.json').write_text(json.dumps(result)+'\n')
    (O/'state-mapping.json').write_text(json.dumps(mapping,indent=2)+'\n')
    script='''read_json cut.json
miter -equiv -flatten FlatCut MemoryCut cut_equiv
hierarchy -top cut_equiv
opt -full
sat -verify -prove trigger 0 -set-def-inputs
'''
    (O/'prove-cut.ys').write_text(script)
    with (O/'cut-service.log').open('wb') as f:
        p=subprocess.run(['/usr/local/bin/yosys','-Q','-T','-l','cut-proof.log','-s','prove-cut.ys'],
            cwd=O,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,timeout=1800)
    assert p.returncode==0,'SAT proof failed; keep the counterexample/log'
    assert 'SAT proof finished - no model found: SUCCESS!' in (O/'cut-proof.log').read_text()
    (O/'result.json').write_text(json.dumps(dict(status='PASS_ALL_STATE_REGISTER_TRANSITION_AND_OUTPUT_EQUIVALENCE',
        state_words=len(mapping),state_bits=sum(x['width'] for x in mapping),
        method='Flatten actual emitted complete modules; expand memory; biject every state word by stable RTL name; compare state types, parameters and initial values; replace corresponding Q by shared arbitrary inputs; prove all D, clock, asynchronous reset and public outputs combinationally equal.',
        arbitrary_independent_clock_and_reset_inputs=True,full_system_equivalence=False,
        source_json_sha256=hashlib.sha256(source.read_bytes()).hexdigest()),indent=2)+'\n')

if __name__=='__main__':main()
