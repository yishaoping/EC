#!/usr/bin/env python3
"""Actual 34x256 queues, two-clock cycle comparison and all-state SAT."""
import copy
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import subprocess
import sys

C=Path(__file__).resolve().parent;T=C.parent.parent;W=T.parent
R=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=Path(sys.argv[1]).resolve()
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def run(name,args,cwd=None,timeout=900,negative=False):
    env={k:v for k,v in os.environ.items() if k not in ['PYTHONHOME','PYTHONPATH','LD_LIBRARY_PATH','LD_PRELOAD','JAVA_TOOL_OPTIONS']}
    with (O/(name+'.log')).open('xb') as f:
        p=subprocess.run(list(map(str,args)),cwd=cwd or O,env=env,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,timeout=timeout)
    text=(O/(name+'.log')).read_text(errors='replace')
    assert (p.returncode==0)!=negative,(name,p.returncode)
    return text
def load(name,path):
    s=importlib.util.spec_from_file_location(name,path);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
def main():
    os.sched_setaffinity(0,{250,251});os.nice(19);O.mkdir(parents=True,exist_ok=False)
    cfg=json.loads((W/'candidates/common-composed-source-r2-20261113/config.json').read_text())
    base=R/'build-logs/Opt4-performance-only-fpga-r1-20261113/classes'
    cp=':'.join([str(base),cfg['firechip'],*cfg['classpath']])
    classes=O/'classes';classes.mkdir();target=O/'target';target.mkdir()
    src=T/'chipyard/generators/rocket-chip/src/main/scala/util'
    java=[cfg['java'],'-Xmx8G','-Xss16M','-XX:ActiveProcessorCount=2']
    run('compile',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,
        '-Xplugin:'+cfg['plugin'],'-d',classes,src/'AsyncQueue.scala',src/'LocalMemAsyncQueue.scala',C/'ResultCDC.scala'])
    run('emit',java+['-cp',str(classes)+':'+cp,'resultcdcprobe.Emit',target])
    run('verilate',['/usr/local/bin/verilator','--cc','--exe','--build','-j','2','-Wno-fatal',
        '--top-module','QueuePair','--Mdir',O/'obj',target/'QueuePair.v',C/'result-compare.cpp'])
    cycle=run('cycles',[O/'obj/VQueuePair']);assert 'RESULT_CDC_ALL_OUTPUT_PASS' in cycle
    script='read_verilog -sv target/QueuePair.v\nhierarchy -top QueuePair\nproc\nflatten AsyncQueue LocalMemAsyncQueue\nmemory_map\nopt_clean\nwrite_json flattened.json\n'
    (O/'prepare.ys').write_text(script)
    run('prepare',['/usr/local/bin/yosys','-Q','-T','-s','prepare.ys'])
    raw=json.loads((O/'flattened.json').read_text())
    cutlib=load('result_state_cut',T/'candidates/performance-only-memory-cdc-r2-20261114/formal_cut.py')
    gold,gate=[raw['modules'][n] for n in ['AsyncQueue','LocalMemAsyncQueue']]
    gs,ts=cutlib.states(gold),cutlib.states(gate);remaining=list(ts);order=[];names=[];mapping=[]
    for g in gs:
        matches=[(t,g['aliases']&t['aliases']) for t in remaining if g['aliases']&t['aliases']]
        assert len(matches)==1,(g['aliases'],matches)
        t,common=matches[0];remaining.remove(t)
        assert g['cell']['type']==t['cell']['type'] and g['init']==t['init']
        def pars(c):return {k:int(v,2) if isinstance(v,str) and re.fullmatch('[01]+',v) else v for k,v in c['parameters'].items()}
        assert pars(g['cell'])==pars(t['cell'])
        assert set(g['cell']['connections'])==set(t['cell']['connections'])
        for pin in g['cell']['connections']:assert len(g['cell']['connections'][pin])==len(t['cell']['connections'][pin])
        name=sorted(common,key=lambda n:(len(n),n))[0];names.append(name);order.append(t)
        mapping.append(dict(name=name,width=len(g['cell']['connections']['Q']),init=g['init'],type=g['cell']['type']))
    assert not remaining and len(mapping)==315
    modules=dict(FlatCut=cutlib.cut(gold,gs,names),MemoryCut=cutlib.cut(gate,order,names))
    lane_source=T/'candidates/performance-only-memory-cdc-r2-20261114/formal_lanes.py'
    # Reuse the checked-in generic cone check at production width, with no
    # invocation of its historical job-control/admission code.
    namespace={'__name__':'result_lane_checker','__file__':str(lane_source)}
    exec(compile(lane_source.read_text().replace('305','34'),str(lane_source),'exec'),namespace)
    symmetry={n:namespace['verify_lanes'](m) for n,m in modules.items()}
    (O/'lane-symmetry.json').write_text(json.dumps(symmetry,indent=2)+'\n')
    (O/'state-mapping.json').write_text(json.dumps(mapping,indent=2)+'\n')
    for m in modules.values():
        for n,p in m['ports'].items():
            if len(p['bits'])==34:p['bits']=p['bits'][:1];m['netnames'][n]['bits']=p['bits']
    passing=copy.deepcopy(modules)
    negative=copy.deepcopy(modules)
    m=negative['MemoryCut'];bit=max(b for v in m['netnames'].values() for b in v['bits'] if isinstance(b,int))+1
    old=m['ports']['io_deq_valid']['bits'][0]
    m['cells']['negative_valid_flip']=dict(type='$not',parameters=dict(A_SIGNED='0',A_WIDTH=format(1,'032b'),Y_WIDTH=format(1,'032b')),
        attributes={},port_directions=dict(A='input',Y='output'),connections=dict(A=[old],Y=[bit]))
    m['ports']['io_deq_valid']['bits']=[bit]
    for label,mods in [('proof',passing),('negative',negative)]:
        (O/(label+'.json')).write_text(json.dumps(dict(modules=mods))+'\n')
        (O/(label+'.ys')).write_text('read_json '+label+'.json\nmiter -equiv -flatten FlatCut MemoryCut equiv\nhierarchy -top equiv\ntechmap\nopt -full\ncheck -assert\nsat -verify -prove trigger 0 -set-def-inputs\n')
        log=run(label,['/usr/local/bin/yosys','-Q','-T','-s',label+'.ys'],negative=label=='negative')
        assert ('no model found: SUCCESS!' if label=='proof' else 'proof did fail') in log
    result=dict(status='PASS_RESULT_CDC_CYCLES_AND_ALL_STATE_EQUIVALENCE',width=34,capacity=256,
        cycles=cycle.strip(),rtl_sha256=sha(target/'QueuePair.v'),state_words=len(mapping),
        state_bits=sum(v['width'] for v in mapping),
        source_sha256={str(src/n):sha(src/n) for n in ['AsyncQueue.scala','LocalMemAsyncQueue.scala']},
        state_cut_helper_sha256=sha(T/'candidates/performance-only-memory-cdc-r2-20261114/formal_cut.py'),
        lane_checker_sha256=sha(lane_source),negative_control='valid inversion is detected',
        independent_clock_and_reset_equations=True,full_system_equivalence=False,host_token_test_pending=True)
    (O/'result.json').write_text(json.dumps(result,indent=2)+'\n')
if __name__=='__main__':main()
