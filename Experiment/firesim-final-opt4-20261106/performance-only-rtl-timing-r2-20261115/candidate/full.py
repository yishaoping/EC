#!/usr/bin/env python3
"""Bound full-system GG build; optionally queue serial post-opt behind CAD leases.

No physical implementation is launched here. Never modifies another build.
"""
import datetime as dt
import fcntl
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import time
import types

C=Path(__file__).resolve().parent
T=C.parent.parent
W=T.parent
R=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
BASE=Path('/var/tmp/guozh-ec-rtl-structure-r1-20261114/full-r3')
MEM=R/'performance-only-memory-cdc-r2-20261114/complete-shell-r3'
O=Path(sys.argv[1]).resolve()
PROFILE=sys.argv[2]
QUEUE='--queue-postopt' in sys.argv
REL='chipyard/generators/rocket-chip/src/main/scala/'
S=dict(profile='EC Performance-Only',variant=PROFILE,fpga_access=False,full_physical_implementation=False)

def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def read(p):return json.loads(Path(p).read_text())
def save(p,v):
    tmp=Path(str(p)+'.tmp');tmp.write_text(json.dumps(v,indent=2)+'\n');os.replace(tmp,p)
def status(n,**kw):
    S.update(status=n,utc=dt.datetime.now(dt.timezone.utc).isoformat(),**kw);save(O/'state.json',S)
def load(name,p):
    s=importlib.util.spec_from_file_location(name,p);m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m
def run(name,args,outputs=(),cwd=None,timeout=10800):
    env={k:v for k,v in os.environ.items() if k not in ['PYTHONHOME','PYTHONPATH','LD_LIBRARY_PATH','LD_PRELOAD','JAVA_TOOL_OPTIONS']}
    env.update(OMP_NUM_THREADS='2',TMPDIR=str(O))
    status('RUNNING_'+name)
    with (O/(name+'.log')).open('xb') as f:
        p=subprocess.run(list(map(str,args)),cwd=cwd or T/'chipyard',env=env,
            stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,timeout=timeout)
    receipt=dict(argv=list(map(str,args)),returncode=p.returncode,
        outputs={str(p):sha(p) for p in outputs if Path(p).exists()})
    save(O/(name+'-receipt.json'),receipt)
    assert p.returncode==0 and len(receipt['outputs'])==len(outputs),(name,p.returncode)
    return (O/(name+'.log')).read_text(errors='replace')
def no_vivado():
    for p in Path('/proc').iterdir():
        if not p.name.isdigit():continue
        try:
            if (p/'comm').read_text().strip()=='vivado':return False
        except OSError:pass
    return True
def resources(p):
    keys=['CLB LUTs','CLB Registers','LUT as Memory','F7 Muxes','F8 Muxes','F9 Muxes','Block RAM Tile','DSPs','URAM','CARRY8']
    result={}
    for l in Path(p).read_text().splitlines():
        x=[v.strip().rstrip('*') for v in l.split('|')]
        if len(x)>6 and x[1] in keys:result.setdefault(x[1],float(x[2].replace(',','')))
    assert all(k in result for k in keys)
    return result

def main():
    os.sched_setaffinity(0,{248,249});os.nice(19)
    dependency=[v.split('=',1)[1] for v in sys.argv if v.startswith('--after-goldengate=')]
    if dependency:
        assert len(dependency)==1
        deadline=time.monotonic()+10800
        while True:
            prior=Path(dependency[0])
            state=read(prior/'state.json') if (prior/'state.json').exists() else {}
            if (prior/'rtl-state.json').exists():
                assert read(prior/'rtl-state.json')['status']=='GOLDENGATE_COMPLETE_NOT_SYNTHESIZED'
                break
            assert state.get('status')!='FAILED_WITH_EVIDENCE',state
            if time.monotonic()>deadline:raise RuntimeError('preceding Golden Gate build did not complete')
            time.sleep(30)
    if '--postopt-only' in sys.argv:
        assert QUEUE and O.is_dir()
        binding=read(O/'source-binding.json')
        rtl=read(O/'rtl-state.json')
        assert binding['commit']==rtl['hardware_commit']
        assert binding['source_id']==rtl['source_id']
        assert rtl['status']=='GOLDENGATE_COMPLETE_NOT_SYNTHESIZED'
        assert read(O/'target-graph-audit.json')['status']=='PASS_EXACT_TARGET_GRAPH_OUTSIDE_PROVEN_QUEUES'
        assert read(O/'instance-compatibility.json')['status']=='PASS_FULL_TARGET_INSTANCES_AND_CLASS_ORIGINS'
        for p,h in rtl['outputs'].items():assert sha(p)==h
        for rel,h in binding['overlay'].items():assert sha(T/rel)==h
        for rel,h in binding['structural_base']['changed'].items():assert sha(T/rel)==h
        S.update(hardware_commit=binding['commit'],source_id=binding['source_id'])
        return postopt(binding['commit'],binding['overlay'],binding['source_id'])
    O.mkdir(parents=True,exist_ok=False)
    assert PROFILE in ['bjl','bjl-result-cdc']
    committed=subprocess.check_output(['git','rev-parse','HEAD'],cwd=T,text=True).strip()
    selected=[REL+'guardiancouncil/GH_FIFO.scala', REL+'diplomacy/DeviceTree.scala']
    if PROFILE=='bjl-result-cdc':selected += [REL+'guardiancouncil/GHM.scala']
    binding=read(BASE/'source-binding.json')
    for rel,h in binding['changed'].items():assert sha(T/rel)==h,(rel,'structural base mismatch')
    changes={rel:sha(T/rel) for rel in selected}
    for rel in selected:
        assert subprocess.check_output(['git','show',committed+':'+rel],cwd=T)==(T/rel).read_bytes(),rel
    bjl=read(T/'candidates/rtl-timing-r1/results.json')
    assert bjl['formal']['status']=='PASS_INDUCTIVE_RESET_MASK_REFINEMENT'
    assert bjl['host']['status']=='PASS_ACTUAL_GOLDENGATE_MCRAM_TOKENS'
    dtb=read(C/'results.json')['dtb']
    assert dtb['status']=='PASS_DTB_FILE_OUTPUT_EXACT_BYTES'
    assert sha(T/(REL+'diplomacy/DeviceTree.scala'))==dtb['source_sha256']
    if PROFILE=='bjl-result-cdc':
        result=read(C/'results.json')['result_cdc']
        assert result['target']['status']=='PASS_RESULT_CDC_CYCLES_AND_ALL_STATE_EQUIVALENCE'
        assert result['host']['status']=='PASS_RESULT_CDC_ACTUAL_REVERSE_CLOCK_HOST_TOKENS'
        assert result['area']['status']=='PASS_PAIRED_RESULT_CDC_REAL_MODULE_AREA'
        for path,h in result['target']['source_sha256'].items():assert sha(path)==h
        assert sha(T/(REL+'guardiancouncil/GHM.scala'))==result['ghm_source_sha256']
    source_id=hashlib.sha256(json.dumps(dict(structure=binding['changed'],overlay=changes),sort_keys=True).encode()).hexdigest()
    S.update(hardware_commit=committed,source_id=source_id)
    save(O/'source-binding.json',dict(commit=committed,source_id=source_id,overlay=changes,structural_base=binding))
    cfg=read(W/'candidates/common-composed-source-r2-20261113/config.json')
    classes=O/'classes';classes.mkdir()
    cp=':'.join([str(BASE/'classes'),str(MEM/'classes'),str(R/'build-logs/Opt4-performance-only-fpga-r1-20261113/classes'),cfg['firechip'],*cfg['classpath']])
    java=[cfg['java'],'-Xmx48G','-Xss32M','-XX:ActiveProcessorCount=2','-Dec.dac.firesim=true']
    run('CHISEL_COMPILE',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,
        '-Xplugin:'+cfg['plugin'],'-d',classes,*[T/x for x in selected]],
        [classes/'freechips/rocketchip/guardiancouncil/GH_FIFO_SC.class'])
    java+=['-cp',str(classes)+':'+cp]
    run('PARAMETERS',java+['firesim.firesim.DacParameterAudit','firesim.firesim.DacOpt4C4',O/'parameters.json'],[O/'parameters.json'])
    assert read(O/'parameters.json')==read(cfg['frozen_parameters'])
    elab=O/'elaborate';elab.mkdir()
    fir=elab/'firesim.firesim.FireSim.fir';anno=elab/'firesim.firesim.FireSim.anno.json'
    log=run('ELABORATE',java[:1]+['-verbose:class']+java[1:]+['chipyard.Generator','--target-dir',elab,
        '--name','firesim.firesim.FireSim','--top-module','firesim.firesim.FireSim','--legacy-configs','firesim.firesim:DacOpt4C4'],[fir,anno])
    expected={'freechips.rocketchip.guardiancouncil.GH_FIFO_SC':classes,
        'freechips.rocketchip.guardiancouncil.GHM':classes if PROFILE=='bjl-result-cdc' else MEM/'classes',
        'freechips.rocketchip.diplomacy.DTB$':classes,
        'freechips.rocketchip.util.LocalMemAsyncQueue':MEM/'classes',
        'boom.lsu.SpeculativeVersionBuffer':BASE/'classes', 'boom.lsu.BoomNonBlockingDCache':BASE/'classes'}
    for cls,origin in expected.items():assert any(cls in l and str(origin) in l for l in log.splitlines()),cls
    target=fir.read_text()
    bjl_instances=re.findall(r'(?m)^\s*inst (u_channel_bj_\d+) of (GH_FIFO_SC(?:_\d+)?)\b',target)
    assert len(bjl_instances)==8,bjl_instances
    blocks=re.split(r'(?m)^  module ',target)
    bjl_blocks=[x for x in blocks if re.match(r'GH_FIFO_SC(?:_\d+)?\s*:',x)]
    assert len(bjl_blocks)==8,len(bjl_blocks)
    for block in bjl_blocks:
        assert re.search(r'(?:c?mem) mem\s*:',block),'BJL payload not a memory'
        assert not re.search(r'reg mem\s*:',block),'BJL RegVec fallback'
    data=re.findall(r'(?m)^\s*inst u_data_cdc_\d+ of LocalMemAsyncQueue(?:_\d+)?\b',target)
    assert len(data)==4
    if PROFILE=='bjl-result-cdc':
        results=re.findall(r'(?m)^\s*inst u_result_cdc_\d+ of LocalMemAsyncQueue(?:_\d+)?\b',target)
        assert len(results)==4
    # All eight proven queue definitions and the full target port graph are
    # bound before FAME extraction. Full-system runtime proof is not inferred.
    save(O/'instance-compatibility.json',dict(status='PASS_FULL_TARGET_INSTANCES_AND_CLASS_ORIGINS',
        bjl_instances=bjl_instances,bjl_memory_modules=len(bjl_blocks),data_cdc_memories=len(data),
        origins={k:str(v) for k,v in expected.items()},parameters_exact=True,full_system_runtime_equivalence=False))
    audit=load('timing_r2_target_audit',C/'target_audit.py')
    audit.audit(BASE/'elaborate/firesim.firesim.FireSim.fir',fir,PROFILE=='bjl-result-cdc',O/'target-graph-audit.json')
    host=O/'host';host.mkdir()
    log=run('GOLDENGATE',java+['midas.stage.GoldenGateMain','-i',fir,'-td',host,'-faf',anno,
        '-ggcp','ecperformanceonly','-ggcs','HostConfig','--output-filename-base','FireSim-generated'],
        [host/'FireSim-generated.sv',host/'FireSim-generated.synthesis.xdc'],cwd=O)
    assert 'Skipping Combinational Loop Detection' not in log
    ram=re.search(r'RAM Models To Extract: (\d+)',log)
    # This log counts annotated SRAM models elsewhere in the system. These
    # asynchronous queue memories are not themselves annotated/extracted;
    # neither this count nor enabling MCRAM proves queue time multiplexing.
    assert ram,'missing Golden Gate SRAM-model count'
    suffix=b'';listing=host/'firrtl_black_box_resource_files.f'
    for line in listing.read_text().splitlines() if listing.exists() else []:
        if line.strip():
            p=Path(line.strip());p=p if p.is_absolute() else host/p;suffix+=p.read_bytes()+b'\n'
    generated=host/'FireSim-generated.sv'
    if suffix:generated.write_bytes(generated.read_bytes()+suffix)
    def ports(text):
        m=re.search(r'^module FPGATop\s*\((.*?)\);',text,re.M|re.S);assert m
        return re.sub(r'\s+',' ',m[1]).strip()
    assert ports(generated.read_text())==ports((BASE/'host/FireSim-generated.sv').read_text())
    names=['FireSim-generated.sv','FireSim-generated.defines.vh','FireSim-generated.synthesis.xdc','FireSim-generated.implementation.xdc']
    save(O/'rtl-state.json',dict(status='GOLDENGATE_COMPLETE_NOT_SYNTHESIZED',hardware_commit=committed,source_id=source_id,
        goldengate_dir=str(host),configuration_matches_frozen_parameters=True,modified_class_origins_verified=True,
        ram_models=int(ram[1]),outputs={str(host/n):sha(host/n) for n in names}))
    for rel,h in changes.items():assert sha(T/rel)==h,'source changed during build'
    status('FULL_GOLDENGATE_COMPLETE_POSTOPT_NOT_RUN',ram_models=int(ram[1]))
    if not QUEUE:return
    postopt(committed,changes,source_id)

def postopt(committed,changes,source_id):
    deadline=time.monotonic()+72*3600
    with (R/'.performance-only-physical.lock').open('a') as lock:
        status('WAITING_EXISTING_CAD_PHYSICAL_LEASE')
        while True:
            try:fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB);break
            except BlockingIOError:
                if time.monotonic()>deadline:raise RuntimeError('existing CAD lease still occupied after 72h')
                time.sleep(30)
        while not no_vivado():
            status('WAITING_EXISTING_VIVADO_NO_NEW_CAD')
            if time.monotonic()>deadline:raise RuntimeError('existing CAD did not exit')
            time.sleep(30)
        sys.path.insert(0,str(W/'scripts'))
        cad=load('timing_r2_postopt',T/'candidates/rtl-structure-r1/cad_postopt.py')
        def guarded(*a,**kw):
            assert no_vivado(),'refuse simultaneous full Vivado'
            for rel,h in changes.items():assert sha(T/rel)==h
            return subprocess.Popen(*a,**kw)
        cad.subprocess=types.SimpleNamespace(**{**vars(subprocess),'Popen':guarded})
        project=O/'project';(project/'bindings').mkdir(parents=True)
        save(project/'bindings'/(committed+'.json'),dict(source_id=source_id,
            frozen_commit='8491167d84b6d9521b151a743673c1516926a1f8',hardware_commit=committed))
        cad.COMMIT,cad.F=committed,project
        cad.O,cad.L,cad.S,cad.R=project/'builds'/('cad-'+committed[:8]),O,O/'cad-state.json',O/'rtl-state.json'
        status('RUNNING_SERIAL_DUT_AND_COMPLETE_SHELL_POSTOPT')
        while True:
            try:cad.main();break
            except BlockingIOError:
                if time.monotonic()>deadline:raise
                time.sleep(30)
        new=resources(O/'top-postopt-utilization.rpt')
        old=resources(BASE.parent/'cad-r1/top-postopt-utilization.rpt')
        save(O/'full-shell-comparison.json',dict(status='REAL_COMPLETE_SHELL_POSTOPT_MEASURED',
            baseline=old,candidate=new,savings={k:old[k]-new[k] for k in old},
            place_route_timing_passed=False,baseline_report=str(BASE.parent/'cad-r1/top-postopt-utilization.rpt')))
        status('COMPLETE_SHELL_POSTOPT_READY_FOR_SEPARATE_FRESH_IMPLEMENTATION',resources=new)

if __name__=='__main__':
    try:main()
    except Exception as e:
        if O.is_dir():status('FAILED_WITH_EVIDENCE',error=repr(e))
        raise
