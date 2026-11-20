#!/usr/bin/python3
"""Private source composition, full DCache cycle comparison and module area.

Never starts whole synthesis, touches the FPGA or modifies a shared worktree.
The committed parent and the private source variant have separate identities.
"""
from pathlib import Path
import fcntl
import hashlib
import importlib.util
import json
import os
import re
import resource
import shutil
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D / 'build-logs/Opt4-dcache-storage-compose-r1-20261112'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
PARENT = '3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
TOP = 'BoomNonBlockingDCache'
sys.path.insert(0, str(W / 'scripts'))
from opt4_unattended_common import identity, now, read, save, sha

ST = {}


def update(status=None, **kw):
    if status:
        ST['status'] = status
    ST.update(updated_utc=now(), **kw)
    save(O / 'state.json', ST)


def exact(p, value):
    p = Path(p)
    p.parent.mkdir(parents=True, exist_ok=True)
    if p.exists():
        assert p.read_text() == value, ('immutable input differs', str(p))
    else:
        p.write_text(value)


def guard(mapping=False):
    while True:
        mem = int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines()
                       if l.startswith('MemAvailable:')))
        load = float(Path('/proc/loadavg').read_text().split()[0])
        disk = shutil.disk_usage(W).free
        workers = []
        for p in Path('/proc').iterdir():
            if not p.name.isdigit():
                continue
            try:
                args = (p / 'cmdline').read_bytes().split(b'\0')
                if args[0].endswith(b'/unwrapped/lnx64.o/vivado') and b'-notrace' not in args:
                    workers.append(int(p.name))
            except (OSError, IndexError):
                pass
        if mem >= 256 * 2**20 and load < 64 and disk >= 100 * 2**30 and (not mapping or len(workers) < 8):
            save(O / ('admission-' + str(time.time_ns()) + '.json'),
                 dict(utc=now(),available_kib=mem,load1=load,disk_bytes=disk,primary_vivado=workers))
            return
        update('WAITING_RESOURCE_GUARD',available_kib=mem,load1=load,disk_bytes=disk,primary_vivado=workers)
        time.sleep(30)


def stage(name, argv, outputs=(), cwd=None, mapping=False):
    guard(mapping)
    receipt = O / (name + '-receipt.json')
    old = read(receipt)
    if old:
        assert old['returncode'] == 0, ('preserve failed stage; version recovery', name)
        assert all(sha(p) == h for p, h in old['outputs'].items())
        return Path(old['log'])
    log = O / (name + '.log')
    assert not log.exists(), ('incomplete stage requires versioned recovery', name)
    started = time.monotonic()
    env = {**os.environ,'LD_LIBRARY_PATH':'','JAVA_TOOL_OPTIONS':'','CCACHE_DISABLE':'1',
           'OMP_NUM_THREADS':'2','MAKEFLAGS':'-j2','TMPDIR':str(O)}
    with log.open('xb', buffering=0) as f:
        child = subprocess.Popen(list(map(str,argv)),cwd=cwd or O,env=env,
                                 stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT)
        update('RUNNING_' + name.upper(),active_stage=name,child=identity(child.pid),stage_log=str(log))
        while child.poll() is None:
            try:
                child.wait(timeout=30)
            except subprocess.TimeoutExpired:
                pass
            update(stage_seconds=time.monotonic()-started)
    row = dict(argv=list(map(str,argv)),returncode=child.returncode,seconds=time.monotonic()-started,
               log=str(log),log_sha256=sha(log),outputs={str(p):sha(p) for p in outputs if p.is_file()},
               missing_outputs=[str(p) for p in outputs if not p.is_file()])
    save(receipt,row)
    update(child={})
    assert child.returncode == 0 and not row['missing_outputs'], (name,child.returncode,row['missing_outputs'])
    return log


def source_contract(cfg):
    root = Path(cfg['candidate_source_root'])
    rel = 'chipyard/generators/boom/src/main/scala/lsu/dcache.scala'
    s = (root / rel).read_text()
    for old, new in reversed(read(C / 'replacements.json')):
        assert s.count(new) == 1
        s = s.replace(new,old,1)
    assert s == (C / 'parent-dcache.scala').read_text()
    assert s == (Path(cfg['source_parent']) / rel).read_text()
    for rel in cfg['binding']['changed_files']:
        if rel.endswith(('/dcache.scala','/AppliedEffectResultMemory.scala')):
            continue
        assert (root / rel).read_bytes() == (Path(cfg['source_parent']) / rel).read_bytes()
    files = {str(p):sha(p) for p in sorted(root.rglob('*.scala'))}
    for p in [C/'config.json',C/'replacements.json',C/'parent-dcache.scala',C/'controller.py']:
        files[str(p)] = sha(p)
    variant = hashlib.sha256(json.dumps(files,sort_keys=True).encode()).hexdigest()
    save(O/'source-contract.json',dict(status='PASS_EXACT_PARENT_REVERSAL',parent_commit=PARENT,
         functional_baseline=BASE,source_variant=variant,files=files,substitutions=15,
         source_is_private_shadow=True,private_variant_is_not_a_committed_hardware_revision=True,
         shared_sources_modified=False,new_functions=False,target_cycle_changes=0))
    return variant


def cycle_prepare(variant,rtl_receipt):
    g = O/'cycle-generator'
    g.mkdir(exist_ok=True)
    original = W/'candidates/dcache-frozen-cycle-r3-20261111'
    text = (original/'prepare.py').read_text()
    text = text.replace("COMMIT = 'd9d732622601ed792a2647546006b5aae986ab8e'", "COMMIT = " + repr(PARENT))
    text = text.replace("SID = '1639f464d8675806abb5d7dd04adc5dfd1fcf0e351e016ef6a20adcbea1b6e4e'", "SID = " + repr(variant))
    exact(g/'prepare.py',text)
    evidence=g/'evidence';evidence.mkdir(exist_ok=True)
    for name in ['frozen-goldengate.json','frozen-annotations.json','frozen-parameters.json']:
        exact(evidence/name,(original/'evidence'/name).read_text())
    exact(evidence/'candidate-rtl.json',json.dumps(rtl_receipt,indent=2,sort_keys=True)+'\n')
    exact(evidence/'candidate-annotations.json',(O/'elaborate/firesim.firesim.FireSim.anno.json').read_text())
    exact(g/'input-hashes.json',json.dumps({str(p):sha(p) for p in sorted(evidence.iterdir())},indent=2,sort_keys=True)+'\n')
    prepared=O/'cycle-prepared'
    stage('prepare-full-dcache-cycle',['/usr/bin/python3',g/'prepare.py',prepared],
          [prepared/'preparation.json',prepared/'pair.sv',prepared/'candidate.sv',prepared/'frozen.sv'])
    # Corrected existing stimulus has already passed the complete frozen pair.
    stimulus=W/'candidates/dcache-frozen-cycle-domain-r5-20261111'
    exact(prepared/'clear-inputs.h',(stimulus/'clear-inputs.h').read_text())
    exact(prepared/'stimulus.cpp',(stimulus/'stimulus.cpp').read_text())
    return prepared


def area_prepare(rtl,anno):
    text=rtl.read_text()
    match=re.search(r'^module '+TOP+r'\((.*?)\);',text,re.M|re.S)
    assert match
    end=text.index('\nendmodule',match.end());body=text[match.end():end]
    signals=set(re.findall(r'\bwire\s+\[31:0\]\s+(debug_line_generation_\d+)\s*=',body))
    assert signals=={'debug_line_generation_'+str(i) for i in range(512)}
    names=[];kept=[]
    for a in read(anno):
        if a.get('class')=='firrtl.transforms.DontTouchAnnotation' and a.get('target','').startswith('~FireSim|'+TOP+'>'):
            names.append(re.sub(r'[^A-Za-z0-9_$]','_',a['target'].split('>',1)[1]).rstrip('_'))
    for name in sorted(set(names)):
        pat=r'(?m)^(\s*)(wire|reg)(\s+(?:\[[^\]\n]+\]\s+)?)('+re.escape(name)+r'(?:_\d+)*)(\s*(?:=|;))'
        def mark(m):
            kept.append(m[4]);return m[1]+'(* keep = "true" *) '+m[2]+m[3]+m[4]+m[5]
        body=re.sub(pat,mark,body)
    ref=read(D/'Opt4-fit-dcache-field-read-full-map-r2-state.json')
    assert sorted(set(kept))==ref['inputs']['candidate']['annotation_kept_signals']
    header=match[0][:-2]+',\n  output [16383:0] opt4_complete_generation_observation\n);'
    assign='\n  assign opt4_complete_generation_observation = {'+', '.join('debug_line_generation_'+str(i) for i in reversed(range(512)))+'};\n'
    out=O/'full-dcache-observed.sv'
    exact(out,text[:match.start()]+header+body+assign+text[end:])
    save(O/'area-harness.json',dict(original=str(rtl),original_sha256=sha(rtl),observed=str(out),
         observed_sha256=sha(out),all_original_ports=True,all_original_observations=True,
         generation_words=512,identical_harness_to_reference=True,reference=ref['maps']['candidate']))
    return out,ref['maps']['candidate']


def main():
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(),'adopt live/finished run, do not restart'
    os.sched_setaffinity(0,{216,217});resource.setrlimit(resource.RLIMIT_AS,(64*2**30,64*2**30))
    ST.update(schema='ec-dcache-storage-composition/1',**identity(),started_utc=now(),
              functional_baseline=BASE,parent_commit=PARENT,source_variant_is_private=True,
              cpus=[216,217],fpga_access=False,whole_synthesis=False,production_admission=False,
              scope='Full frozen DCache cycle/observation finite regression and complete DCache OOC area. No whole formal or host/shell FIT claim.')
    update('VERIFYING_EXACT_SOURCE_COMPOSITION')
    cfg=read(C/'config.json');variant=source_contract(cfg);update(source_variant=variant)
    sources=[Path(cfg['candidate_source_root'])/r for r in cfg['binding']['changed_files']]
    classes=O/'source-classes';classes.mkdir(exist_ok=True)
    stage('compile-source',[cfg['java'],'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=2','-cp',':'.join(cfg['compiler']),
          'scala.tools.nsc.Main','-classpath',':'.join(cfg['classpath']),'-Xplugin:'+cfg['plugin'],'-d',classes,*sources],
          [classes/'boom/lsu/BoomNonBlockingDCache.class',classes/'boom/lsu/AppliedEffectResultMemory.class'])
    cp=str(classes)+':'+cfg['firechip']+':'+':'.join(cfg['classpath'])
    java=[cfg['java'],'-Xmx32G','-Xss8M','-XX:ActiveProcessorCount=2','-Dec.dac.firesim=true','-cp',cp]
    pp=O/'parameters.json'
    stage('frozen-parameters',java+['firesim.firesim.DacParameterAudit','firesim.firesim.DacOpt4C4',pp],[pp])
    assert read(pp)==read(cfg['frozen_parameters']),'frozen core/checker/cache geometry changed'
    elab=O/'elaborate';elab.mkdir(exist_ok=True)
    fir=elab/'firesim.firesim.FireSim.fir';anno=elab/'firesim.firesim.FireSim.anno.json'
    log=stage('elaborate',java[:1]+['-verbose:class']+java[1:]+['chipyard.Generator','--target-dir',elab,
              '--name','firesim.firesim.FireSim','--top-module','firesim.firesim.FireSim',
              '--legacy-configs','firesim.firesim:DacOpt4C4'],[fir,anno])
    loaded=log.read_text(errors='replace')
    for name in ['boom.lsu.BoomNonBlockingDCache','boom.lsu.AppliedEffectResultMemory','boom.lsu.PackageAddressStats']:
        assert any(name in l and str(classes) in l for l in loaded.splitlines()),('wrong class origin',name)
    gg=O/'goldengate';gg.mkdir(exist_ok=True);rtl=gg/'FireSim-generated.sv'
    stage('goldengate-target',java+['midas.stage.GoldenGateMain','-i',fir,'-td',gg,'-faf',anno,
          '-ggcp','firesim.configs','-ggcs','DacXilinxAlveoConfig','--output-filename-base','FireSim-generated','--no-dedup'],[rtl])
    marker=O/'blackboxes-appended.json'
    if not marker.exists():
        listing=gg/'firrtl_black_box_resource_files.f';added={}
        with rtl.open('ab') as f:
            for line in listing.read_text().splitlines() if listing.exists() else []:
                if line.strip():
                    p=Path(line.strip());f.write(p.read_bytes());f.write(b'\n');added[str(p)]=sha(p)
        save(marker,dict(output_sha256=sha(rtl),appended=added))
    rr=dict(hardware_commit=PARENT,source_id=variant,source_variant_is_private=True,
            configuration_matches_frozen_parameters=True,goldengate_dir=str(gg),
            outputs={str(rtl):sha(rtl)})
    save(O/'rtl-receipt.json',rr)
    prepared=cycle_prepare(variant,rr)
    exe=O/'obj/VDCacheCyclePair'
    stage('compile-full-dcache-cycle',['/usr/local/bin/verilator','--cc','--exe','--build','-j','2',
          '--compiler','clang','--top-module','DCacheCyclePair','--Mdir',O/'obj',
          '--output-split','10000','--output-split-cfuncs','200','-Wno-fatal',
          '--x-initial','0','--x-assign','0','-DRANDOMIZE_REG_INIT','-DRANDOMIZE_MEM_INIT',"-DRANDOM=32'h0",
          '-DSTOP_COND=1','-DPRINTF_COND=1','-CFLAGS','-O0 -fbracket-depth=4096 -I'+str(prepared),
          '-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',prepared/'frozen.sv',prepared/'candidate.sv',
          prepared/'pair.sv',prepared/'stimulus.cpp'],[exe])
    log=stage('full-dcache-cycle',[exe])
    assert 'COMPLETE_FROZEN_DCACHE_CYCLE_PASS cycles=8192' in log.read_text()
    update('FULL_DCACHE_FINITE_CYCLES_PASS_PREPARING_AREA',complete_dcache_cycles_verified=True,
           full_formal=False,comparison=str(log))
    observed,reference=area_prepare(rtl,anno)
    assert sha(reference['report'])==reference['report_sha256']
    out=O/'area';out.mkdir(exist_ok=True);tcl=out/'map.tcl';util=out/'utilization.rpt';hier=out/'hierarchical.rpt';dcp=out/'module.dcp'
    exact(tcl,'set_param general.maxThreads 2\n'+f'read_verilog -sv {{{observed}}}\n'+
          f'synth_design -mode out_of_context -top {TOP} -part xcu280-fsvh2892-2L-e\n'+
          'if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}\n'+
          f'report_utilization -file {{{util}}}\nreport_utilization -hierarchical -hierarchical_depth 25 -file {{{hier}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
    stage('map-complete-dcache',['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal',
          '-log',out/'vivado.log','-source',tcl],[util,hier,dcp],cwd=out,mapping=True)
    spec=importlib.util.spec_from_file_location('resource_parser',W/'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py')
    parser=importlib.util.module_from_spec(spec);spec.loader.exec_module(parser)
    totals=parser.parse_total(util.read_text());parser.crosschecks(util.read_text(),totals)
    resources={k:v['used'] for k,v in totals.items()}
    saved=reference['resources']['CLB LUTs']-resources['CLB LUTs']
    update('COMPLETE_FULL_DCACHE_CYCLE_AND_PAIRED_MODULE_AREA_NOT_WHOLE_FIT',candidate_resources=resources,
           reference_resources=reference['resources'],module_lut_saved=saved,ended_utc=now(),
           next='Combine only with substantial proven AddressStats implementation. Generate exact MCRams host and complete host parity/ABI; one fresh whole postopt after measured gain justifies it.',
           full_host_saving_unknown=True,whole_fit=False)
    save(O/'result.json',ST)


if __name__=='__main__':
    try:
        main()
    except Exception as exc:
        if ST:
            update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED',error=repr(exc),ended_utc=now())
            save(O/'failure.json',ST)
        raise
