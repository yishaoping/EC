#!/usr/bin/python3
"""Full256 mixed8/32 caller host/token/area screens, immutable and deterministic."""
from pathlib import Path
import fcntl
import hashlib
import importlib.util
import os
import re
import resource
import subprocess
import sys
import time
from prepare import derive,T
C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-common-mixed-geometry-r1-20261113'
CPUS={218,219}
FULL_AFFINITY=set(os.sched_getaffinity(0))
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import identity,now,read,save,sha

def load(name,path):
    spec=importlib.util.spec_from_file_location(name,path)
    module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
    return module

m=load('mixed_geometry_original_guard',W/'candidates/address-histogram-fame5-r6-20261112/controller.py')
m.C,m.O,m.CPUS=C,O,CPUS
mapper=load('mixed_geometry_exact_mapper',W/'candidates/address-banked-production-area-pair-r1-20261112/controller.py')
mapper.C,mapper.m=C,m
oracle=load('mixed_geometry_same_oracle',C/'oracle.py')
oracle.m,oracle.save,oracle.sha=m,save,sha
runtime=load('mixed_geometry_same_runtime',C/'runtime.py')
runtime.m=m
G=D/'build-logs/Opt4-common-caller-geometry-closure-r1-20261113'
GEN=D/'build-logs/Opt4-common-stats-host-r6-20261113'
TOK=D/'build-logs/Opt4-common-stats-token-area-r3-20261113'
COMPILED=D/'build-logs/Opt4-common-composed-source-r2-20261113'
ACTIVE_ROOT=None
original_stage=m.stage

def geometry_stage(name,argv,outputs=(),**kwargs):
    actual=(ACTIVE_ROOT.name+'-'+name) if ACTIVE_ROOT else name
    original_stage(actual,argv,outputs,**kwargs)
    if ACTIVE_ROOT:
        for suffix in ['.log','-receipt.json']:
            link=ACTIVE_ROOT/(name+suffix)
            assert not link.exists() and not link.is_symlink()
            link.symlink_to(O/(actual+suffix))
    return O/(actual+'.log')

m.stage=geometry_stage


def members(unit):
    suffix='/'+unit
    result=[]
    for proc in Path('/proc').iterdir():
        if not proc.name.isdigit():continue
        try:
            paths=[line.split(':',2)[-1] for line in (proc/'cgroup').read_text().splitlines()]
            if any(path.endswith(suffix) or suffix+'/' in path for path in paths):
                row=identity(int(proc.name))
                if row and row['process_state'] not in ['Z','X']:result.append(row)
        except OSError:pass
    return result


def verify_binding():
    binding=read(C/'source-binding.json')
    assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=T,text=True).strip()==binding['experiment_commit']
    assert all(sha(path)==h for path,h in binding['files'].items()),'Pinned input changed'
    for relative,h in binding['committed_files'].items():
        assert sha(T/relative)==h
        assert hashlib.sha256(subprocess.check_output(['git','show',binding['experiment_commit']+':'+relative],cwd=T)).hexdigest()==h
    text,receipt=derive()
    assert text==(C/'Mixed.scala').read_text() and receipt==read(C/'derivation.json')
    for name in ['TestMixed.cc','oracle.py','runtime.py']:
        assert (C/name).read_bytes()==(W/'candidates/common-stats-token-area-r3-20261113'/name).read_bytes()
    prior=read(COMPILED/'result.json')
    assert prior['status']=='PASS_COMPLETE_COMMON_COMPOSITION_COMPILE_FROZEN_PARAMETERS_AND_LINKAGE_NO_RTL'
    assert prior['hardware_commit']==binding['compiled_source_commit']
    inventory=read(COMPILED/'compiled-classes.json')
    assert all(sha(path)==h for path,h in inventory['files'].items())
    return binding


def accepted(path):
    r=read(path)
    assert r['accepted'] and not r['missing_outputs'] and r['returncode']==0,path
    assert sha(r['log'])==r['log_sha256']
    assert all(sha(path)==h for path,h in r['outputs'].items())
    return r


def helper_gate():
    import builtins,symtable
    for name,module in [('oracle.py',oracle),('runtime.py',runtime)]:
        for function in symtable.symtable((C/name).read_text(),str(C/name),'exec').get_children():
            missing=[symbol.get_name() for symbol in function.get_symbols()
                if symbol.is_referenced() and symbol.is_global() and
                symbol.get_name() not in vars(module) and not hasattr(builtins,symbol.get_name())]
            assert not missing,(name,function.get_name(),missing)


def prerequisites():
    required=[(G,'ec-opt4-common-caller-geometry-closure-r1-20261113.service',
        'PASS_COMPLETE_ADDRESS_CALLER_8_16_32_FINITE_ALL_STATE_AND_ABI_NOT_HOST_AREA'),
        (GEN,'ec-opt4-common-stats-host-r6-20261113.service',
        'PASS_MIXED_HOST_BATCH_REMAP_AND_EXACT_HOST_GENERATION_TOKEN_VALIDATION_PENDING')]
    while True:
        observations={}
        ready=True
        for directory,unit,status in required:
            state,result=read(directory/'state.json'),read(directory/'result.json')
            owned=members(unit)
            if state.get('status','').startswith('FAILED'):
                raise RuntimeError(('Diagnose immutable prerequisite failure',str(directory/'failure.json')))
            observations[directory.name]=dict(status=state.get('status'),cgroup_members=owned)
            if result.get('status')!=status or owned:ready=False
        if ready:
            for lanes in ['8','16','32']:
                row=read(G/'result.json')['validated'][lanes]
                assert row['cycles']==6144 and row['outputs']==5684
                assert row['negative_invalid_payload_rejected'] and row['oracle_inverse_byte_equal']
            return {str(p/'result.json'):sha(p/'result.json') for p,_,_ in required}
        m.update('QUEUED_AFTER_EXACT_GEOMETRY_AND_MIXED_GENERATION_RELEASE',prerequisites=observations,
            no_waiting_CPU_pins=True,no_host_transform_started=True)
        time.sleep(30)


def target_reference(trace):
    while True:
        receipt=TOK/'target-token-oracle-receipt.json'
        if receipt.exists():
            accepted(receipt)
            reference=TOK/'target-public-tokens.txt'
            assert trace.read_bytes()==reference.read_bytes(),'Full3003-token public trace differs across geometry'
            return dict(reference_trace=str(reference),reference_trace_sha256=sha(reference),
                trace_sha256=sha(trace),all3003_rows_byte_equal=True,public_outputs=73,
                target_oracle_receipt_sha256=sha(receipt))
        state=read(TOK/'state.json')
        if state.get('status','').startswith(('FAILED','PREREQUISITE_FAILED')):
            raise RuntimeError(('Diagnose original16 mixed target failure',str(TOK)))
        m.update('WAITING_SOLE_16_LANE_ORACLE_WITHOUT_DUPLICATION')
        time.sleep(30)


def main():
    global ACTIVE_ROOT
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(),'Adopt existing exact screen owner'
    binding=verify_binding();helper_gate()
    m.ST.update(schema='ec-production256-mixed-host-geometry-screen/1',**identity(),started_utc=now(),
        experiment_commit=binding['experiment_commit'],hardware_commit=binding['experiment_commit'],
        compiled_source_commit=binding['compiled_source_commit'],
        functional_baseline=binding['functional_baseline'],source_binding_sha256=sha(C/'source-binding.json'),
        geometries=[8,32],production_slots_each=256,barrier_callers=3,public_outputs=73,
        cpus=sorted(CPUS),memory_limit_gib=64,fpga_access=False,whole_EC_CAD=False,
        production_admission=False,full_system_fit=False,
        scope='Complete mixed AddressStats and three barriers at full256 slots/role, actual8/32 lanes, same Plain/Threaded host tokens and serial OOC maps. No complete EC, fullshell FIT or physical certification claim.')
    m.update('ADMITTING_IMMUTABLE_GEOMETRY_HARNESS_COMPILE')
    cfg=read(W/'candidates/common-composed-source-r2-20261113/config.json')
    inventory=read(COMPILED/'compiled-classes.json')
    save(O/'compile-admission.json',m.admission())
    os.sched_setaffinity(0,CPUS);resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    classes=O/'classes';classes.mkdir()
    java=[cfg['java'],'-Xmx24G','-Xss32M','-XX:ActiveProcessorCount=2']
    m.stage('compile-full256-geometry-harness',java+['-cp',':'.join(cfg['compiler']),
        'scala.tools.nsc.Main','-classpath',inventory['classpath'],'-Xplugin:'+cfg['plugin'],
        '-d',classes,C/'Mixed.scala'],[classes/('commonstatshost/'+name+'.class')
        for name in ['MixedTarget','MixedHost8','MixedHost32','Emit','PlainConfig','ThreadedConfig']])
    save(O/'compiled-harness.json',dict(files={str(p):sha(p) for p in classes.rglob('*.class')},
        source_binding_sha256=sha(C/'source-binding.json'),
        reusable_complete_class_inventory_sha256=sha(COMPILED/'compiled-classes.json'),
        added_target_cycles=0,hardware_body_derivation_sha256=sha(C/'derivation.json')))
    os.sched_setaffinity(0,FULL_AFFINITY)
    gate=prerequisites();save(O/'prerequisite-release.json',dict(results=gate,exact_cgroups_released=True))
    verify_binding()
    save(O/'generation-admission.json',m.admission());os.sched_setaffinity(0,CPUS)
    # Compiler repairs precede all stock jars; newly compiled production classes
    # precede the obsolete7-argument caller classes from the old16-lane host.
    cp=':'.join(map(str,[classes,GEN/'mapper-classes',
        D/'build-logs/Opt4-common-stats-host-r5-20261113/checker-classes']))+':'+inventory['classpath']
    java=[cfg['java'],'-Xmx48G','-Xss32M','-XX:ActiveProcessorCount=2','-cp',cp]
    complete={}
    for lanes in [8,32]:
        root=O/f'lanes-{lanes}';root.mkdir();ACTIVE_ROOT=root
        target=root/'Host-target';target.mkdir()
        m.stage(f'elaborate-mixed-host-{lanes}',java+['freechips.rocketchip.system.Generator',
            '--target-dir',target,'--name','MixedStats','--top-module',f'commonstatshost.MixedHost{lanes}',
            '--configs','firesim.midasexamples.NoConfig'],[target/'MixedStats.fir',target/'MixedStats.anno.json'])
        selected=[a for a in read(target/'MixedStats.anno.json')
            if a.get('class','').endswith('FirrtlEnableModelMultiThreadingAnnotation')]
        count=1024//lanes
        assert len(selected)==count and count&(count-1)==0
        assert all(re.fullmatch(r'StatsBank(?:_\d+)?',a['target'].split(':')[-1]) for a in selected)
        assert 'DontCheckCombLoopsAnnotation' not in (target/'MixedStats.anno.json').read_text()
        targetrtl=root/'Target-oracle';targetrtl.mkdir()
        m.stage(f'elaborate-token-target-{lanes}',java+['commonstatshost.Emit',str(lanes),targetrtl],[targetrtl/'MixedTarget.v'])
        oracle.O=root
        trace=oracle.oracle(targetrtl/'MixedTarget.v')
        save(root/'target-geometry-equivalence.json',target_reference(trace))
        hosts={};audits={};tokens={}
        for name in ['Threaded','Plain']:
            host=root/name;host.mkdir();hosts[name]=host
            stage=f'goldengate-{name}-{lanes}'
            m.stage(stage,java+['midas.stage.GoldenGateMain','-i',target/'MixedStats.fir',
                '-td',host,'-faf',target/'MixedStats.anno.json','-ggcp','commonstatshost',
                '-ggcs',name+'Config','--output-filename-base','FireSim-generated'],
                [host/'FireSim-generated.sv',host/'FireSim-generated.synthesis.xdc'])
            log=(root/(stage+'.log')).read_text()
            assert 'Skipping Combinational Loop Detection' not in log
            assert 'EC_BATCH_ANNOTATION_REMAP input=' in log
            fame=(host/'post-fame-transform.fir').read_text()
            types=re.findall(r'(?m)^\s*inst \w+ of (StatsBank(?:_\d+)?)\b',fame)
            assert len(types)==count and len(set(types))==1
            fir=(host/'post-gen-sram-models.fir').read_text()
            assert ('module StatsBank_threaded :' in fir)==(name=='Threaded')
            assert not any(word in fir for word in ['io_observe','io_debugBuckets','io_debugValid','io_debugSeq'])
            audits[name]=dict(selected_instances=count,selected_types=list(set(types)),lanes=lanes,
                slots_each=256,address_banks=256//lanes,barrier_banks=768//lanes,
                proof_outputs=False,host_RTL_sha256=sha(host/'FireSim-generated.sv'))
        save(root/'host-topology.json',audits)
        # The exact same73-output observation horizon and negative oracle run
        # on both hosts before any map of this geometry is admitted.
        runtime.O=root
        for name in ['Threaded','Plain']:
            tokens[name]=runtime.simulate(hosts[name],f'{name}-{lanes}',trace)
            save(root/'token-progress.json',tokens)
        assert tokens['Threaded']['digest']==tokens['Plain']['digest']
        save(root/'host-validation.json',dict(tokens=tokens,outputs=73,target_tokens=3003,
            source_binding_sha256=sha(C/'source-binding.json'),full_formal=False))
        mapper.O=root/'area';mapper.O.mkdir();mapper.P=root
        measured={}
        for name in ['Plain','Threaded']:
            host,signature=mapper.prepare_host(name)
            measured[name]=mapper.map_or_reuse(host,f'{name}-{lanes}',signature)
            save(root/'paired-progress.json',measured)
        savings={k:measured['Plain']['resources'][k]-measured['Threaded']['resources'][k]
            for k in measured['Plain']['resources']}
        complete[str(lanes)]=dict(tokens=tokens,area=measured,savings=savings,
            topology=audits,target_trace_binding_sha256=sha(root/'target-geometry-equivalence.json'))
        save(O/'completed-geometries.json',complete)
        verify_binding()
    m.update('COMPLETE_PRODUCTION256_MIXED_8_32_HOST_TOKENS_AND_AREA_NOT_WHOLE_EC',
        completed=complete,ended_utc=now(),full_formal=False,
        next='Choose8/16/32 from actual compatible full-size resources and host cycles, then exact source/frozenDCache/completehost/ABI and complete shell CAD. No extrapolated savings or automatic whole build.')
    save(O/'result.json',m.ST)

if __name__=='__main__':
    try:main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED',error=repr(exc),ended_utc=now())
            save(O/'failure.json',m.ST)
        else:
            O.mkdir(exist_ok=True);save(O/'preflight-failure.json',dict(utc=now(),error=repr(exc)))
        raise
