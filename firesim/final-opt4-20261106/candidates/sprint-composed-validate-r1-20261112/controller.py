#!/usr/bin/python3
"""Conditional, deterministic complete-source validation and generated-host CAD.

This is a generated host measurement. It cannot certify shell FIT or deploy.
It waits for material measured module gain rather than burning whole CAD now.
"""
from pathlib import Path
import fcntl
import importlib.util
import json
import os
import re
import resource
import subprocess
import sys
import time

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-sprint-composed-validate-r1-20261112'
S=W/'candidates/address-banked-storage-compose-r1-20261112'
COMPILED=D/'build-logs/Opt4-address-banked-storage-compose-r1-20261112'
HOST=D/'build-logs/Opt4-address-banked-production-host-r1-20261112'
AREA=D/'build-logs/Opt4-address-banked-production-area-pair-r1-20261112'
DCACHE=D/'build-logs/Opt4-dcache-storage-compose-r3-20261112'
BRANCH=W/'Opt4-area-sprint-20261112'
spec=importlib.util.spec_from_file_location('immutable_stages',W/'candidates/dcache-storage-compose-r2-20261112/controller.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
m.O=O
from opt4_unattended_common import identity,live,now,read,save,sha


def idle_cpus():
    rows=[]
    for p in Path('/proc').iterdir():
        if not p.name.isdigit() or int(p.name)==os.getpid():continue
        try:
            affinity=os.sched_getaffinity(int(p.name))
            if p.stat().st_uid==os.getuid() and len(affinity)<=8 and affinity&{218,219}:
                r=identity(int(p.name))
                if live(r):rows.append(r)
        except (OSError,ProcessLookupError):pass
    return rows


def prerequisites():
    while True:
        host,area,dcache=[read(p/'result.json') for p in [HOST,AREA,DCACHE]]
        states=[read(p/'state.json') for p in [HOST,AREA,DCACHE]]
        if any(x.get('status','').startswith(('FAILED','REJECTED')) for x in states):
            m.update('PREREQUISITE_FAILED_CONTINUE_OTHER_CANDIDATES',
                prerequisite_statuses=[x.get('status') for x in states],ended_utc=now())
            save(O/'result.json',m.ST)
            return None
        if host and area and dcache:
            assert host['functional_baseline']==m.BASE
            assert host['finite_parity'] and host['target_cycles']==6144 and host['monitor_outputs']==5684
            assert host['tokens']['Plain']['digest']==host['tokens']['Threaded']['digest']
            assert host['host_tokens']==3003 and host['production_public_outputs']==52
            assert dcache['complete_dcache_cycles_verified']
            if area['lut_saved']<300000 or dcache['module_lut_saved']<0:
                m.update('INSUFFICIENT_MEASURED_COMBINATION_FOR_WHOLE_CAD_NEXT_STRUCTURE_REQUIRED',
                    address_module_lut_saved=area['lut_saved'],dcache_module_lut_saved=dcache['module_lut_saved'],
                    no_whole_CAD_started=True,ended_utc=now())
                save(O/'result.json',m.ST)
                return None
            assert area['public_outputs']==52 and area['proof_ports_absent']
            assert area['production_admission'] is False
            if not idle_cpus():
                return dict(host_result_sha256=sha(HOST/'result.json'),area_result_sha256=sha(AREA/'result.json'),
                    dcache_result_sha256=sha(DCACHE/'result.json'),
                    same_scope_address_gain=area['lut_saved'],same_scope_dcache_gain=dcache['module_lut_saved'],
                    module_deltas_not_added_to_whole_host_estimate=True)
        m.update('QUEUED_FOR_MATERIAL_VALIDATED_MODULE_COMBINATION',
            prerequisite_statuses=[x.get('status') for x in states],
            minimum_address_same_scope_gain=300000,cpus_busy=idle_cpus())
        time.sleep(30)


def cycle_prepare(variant,rtl):
    original=W/'candidates/dcache-frozen-cycle-r3-20261111'
    generator=O/'cycle-generator';generator.mkdir()
    script=(original/'prepare.py').read_text()
    script=script.replace("COMMIT = 'd9d732622601ed792a2647546006b5aae986ab8e'",'COMMIT = '+repr(m.ST['hardware_commit']))
    script=script.replace("SID = '1639f464d8675806abb5d7dd04adc5dfd1fcf0e351e016ef6a20adcbea1b6e4e'",'SID = '+repr(variant))
    m.exact(generator/'prepare.py',script)
    evidence=generator/'evidence';evidence.mkdir()
    for name in ['frozen-goldengate.json','frozen-annotations.json','frozen-parameters.json']:
        m.exact(evidence/name,(original/'evidence'/name).read_text())
    m.exact(evidence/'candidate-rtl.json',json.dumps(dict(hardware_commit=m.ST['hardware_commit'],source_id=variant,
        configuration_matches_frozen_parameters=True,goldengate_dir=str(rtl.parent),outputs={str(rtl):sha(rtl)}),indent=2)+'\n')
    m.exact(evidence/'candidate-annotations.json',(O/'elaborate/firesim.firesim.FireSim.anno.json').read_text())
    m.exact(generator/'input-hashes.json',json.dumps({str(p):sha(p) for p in evidence.iterdir()},indent=2)+'\n')
    prepared=O/'cycle-prepared'
    m.stage('prepare-full-dcache-cycle',['/usr/bin/python3',generator/'prepare.py',prepared],
        [prepared/'preparation.json',prepared/'frozen.sv',prepared/'candidate.sv',prepared/'pair.sv'])
    # Preserve the generated header and use the existing successful stimulus's
    # exact Verilator identifier encoding in this new validation directory.
    (prepared/'clear-inputs.h').rename(prepared/'clear-inputs-raw.h')
    stim=W/'candidates/dcache-frozen-cycle-domain-r5-20261111'
    for name in ['clear-inputs.h','stimulus.cpp']:
        m.exact(prepared/name,(stim/name).read_text())
    return prepared


def main():
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(),'Adopt existing attempt'
    os.sched_setaffinity(0,{218,219});resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=BRANCH,text=True).strip()
    assert commit.startswith('fd5de2b')
    m.ST.update(schema='ec-sprint-gated-composed-validation/1',**identity(),started_utc=now(),
        hardware_commit=commit,functional_baseline=m.BASE,cpus=[218,219],
        fpga_access=False,full_system_fit=False,shell_excluded=True,production_admission=False,
        scope='Exact committed source composition full frozen DCache finite cycles, actual threaded completehost postopt. Shell integration/certification remains mandatory.')
    m.update('QUEUED_VALIDATED_MATERIAL_AREA_GATE')
    gate=prerequisites()
    if gate is None:return
    save(O/'whole-admission.json',gate)
    cfg=read(S/'config.json');binding=read(S/'source-binding.json');compiled=read(COMPILED/'result.json')
    assert compiled['status']=='PASS_PRIVATE_COMPOSED_SOURCE_COMPILE_AND_FROZEN_PARAMETERS_NO_ELABORATION_OR_AREA'
    for group in [binding['files'],binding['dependencies'],compiled['compiled_classes']]:
        assert all(sha(p)==h for p,h in group.items()),'Compiled composition changed'
    for p,h in binding['files'].items():
        rel=Path(p).relative_to(S/'sources')
        assert sha(BRANCH/rel)==h,('Committed source bytes mismatch',str(rel))
        blob=subprocess.check_output(['git','show',commit+':'+str(rel)],cwd=BRANCH)
        import hashlib
        assert hashlib.sha256(blob).hexdigest()==h
    variant=binding['source_variant']
    m.update('USING_AUTHENTICATED_COMPILED_COMPOSITION',source_variant=variant)
    classes=COMPILED/'source-classes'
    configclasses=O/'config-classes';configclasses.mkdir()
    m.stage('compile-threaded-config',[cfg['java'],'-Xmx4G','-Xss16M','-cp',':'.join(cfg['compiler']),
        'scala.tools.nsc.Main','-classpath',':'.join(cfg['classpath']),'-d',configclasses,C/'ThreadedConfig.scala'],
        [configclasses/'ecsprint/ThreadedAlveoConfig.class'])
    cp=str(configclasses)+':'+str(classes)+':'+cfg['firechip']+':'+':'.join(cfg['classpath'])
    java=[cfg['java'],'-Xmx32G','-Xss64M','-XX:ActiveProcessorCount=2','-Dec.dac.firesim=true','-cp',cp]
    params=O/'parameters.json'
    m.stage('frozen-parameters',java+['firesim.firesim.DacParameterAudit','firesim.firesim.DacOpt4C4',params],[params])
    assert read(params)==read(cfg['frozen_parameters'])
    elab=O/'elaborate';elab.mkdir()
    fir=elab/'firesim.firesim.FireSim.fir';anno=elab/'firesim.firesim.FireSim.anno.json'
    log=m.stage('elaborate',java[:1]+['-verbose:class']+java[1:]+['chipyard.Generator',
        '--target-dir',elab,'--name','firesim.firesim.FireSim','--top-module','firesim.firesim.FireSim',
        '--legacy-configs','firesim.firesim:DacOpt4C4'],[fir,anno])
    for cls in ['boom.lsu.BoomNonBlockingDCache','boom.lsu.PackageAddressStats','opt4bankedproduction.BucketBank']:
        assert any(cls in l and str(classes) in l for l in log.read_text(errors='replace').splitlines())
    plain=O/'plain-target';plain.mkdir();rtl=plain/'FireSim-generated.sv'
    m.stage('goldengate-target',java+['midas.stage.GoldenGateMain','-i',fir,'-td',plain,'-faf',anno,
        '-ggcp','firesim.configs','-ggcs','DacXilinxAlveoConfig','--output-filename-base','FireSim-generated','--no-dedup'],[rtl])
    listing=plain/'firrtl_black_box_resource_files.f'
    with rtl.open('ab') as f:
        for p in listing.read_text().splitlines() if listing.exists() else []:
            if p.strip():f.write(Path(p).read_bytes());f.write(b'\n')
    prepared=cycle_prepare(variant,rtl)
    exe=O/'obj/VDCacheCyclePair'
    m.stage('compile-full-dcache-cycle',['/usr/local/bin/verilator','--cc','--exe','--build','-j','2',
        '--compiler','clang','--top-module','DCacheCyclePair','--Mdir',O/'obj','--output-split','10000',
        '--output-split-cfuncs','200','-Wno-fatal','--x-initial','0','--x-assign','0',
        '-DRANDOMIZE_REG_INIT','-DRANDOMIZE_MEM_INIT',"-DRANDOM=32'h0",'-DSTOP_COND=1','-DPRINTF_COND=1',
        '-CFLAGS','-O0 -fbracket-depth=4096 -I'+str(prepared),'-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',
        prepared/'frozen.sv',prepared/'candidate.sv',prepared/'pair.sv',prepared/'stimulus.cpp'],[exe])
    log=m.stage('full-dcache-cycle',[exe])
    assert 'COMPLETE_FROZEN_DCACHE_CYCLE_PASS cycles=8192' in log.read_text()
    m.update('PASS_COMPLETE_COMPOSED_DCACHE_FINITE_CYCLES_GENERATING_HOST',
        complete_dcache_cycles_verified=True,full_formal=False)
    host=O/'host';host.mkdir()
    # Dedup is required here so sixteen identical annotated banks share one
    # selected model type; target RTL comparison above retains old naming.
    m.stage('goldengate-threaded-host',java+['midas.stage.GoldenGateMain','-i',fir,'-td',host,'-faf',anno,
        '-ggcp','ecsprint','-ggcs','ThreadedAlveoConfig','--output-filename-base','FireSim-generated'],
        [host/'FireSim-generated.sv',host/'FireSim-generated.synthesis.xdc'])
    post=(host/'post-gen-sram-models.fir').read_text()
    assert 'module BucketBank_threaded :' in post
    save(O/'host-binding.json',dict(hardware_commit=commit,source_variant=variant,
        compiled_source_binding_sha256=sha(S/'source-binding.json'),
        host_RTL_sha256=sha(host/'FireSim-generated.sv'),
        component_complete_host_validation=gate['host_result_sha256'],
        complete_composed_cycles=True,host_system_token_equivalence_not_formally_proved=True))
    util,hier,dcp=[host/n for n in ['postopt-utilization.rpt','postopt-hierarchical.rpt','postopt.dcp']]
    tcl=host/'postopt.tcl'
    m.exact(tcl,'set_param general.maxThreads 2\n'+''.join(f'read_verilog -sv {{{p}}}\n' for p in sorted(host.glob('*.v'))+[host/'FireSim-generated.sv'])+
        f'read_xdc {{{host/"FireSim-generated.synthesis.xdc"}}}\n'+
        'synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e\n'+
        'if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}\nopt_design\n'+
        f'report_utilization -file {{{util}}}\nreport_utilization -hierarchical -hierarchical_depth 30 -file {{{hier}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
    m.stage('complete-host-postopt',['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal',
        '-log',host/'vivado.log','-source',tcl],[util,hier,dcp],cwd=host,mapping=True)
    sp=importlib.util.spec_from_file_location('parser',W/'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py')
    parser=importlib.util.module_from_spec(sp);sp.loader.exec_module(parser)
    total=parser.parse_total(util.read_text());parser.crosschecks(util.read_text(),total)
    resources={k:v['used'] for k,v in total.items()}
    gap=resources['CLB LUTs']-1303680
    m.update('COMPLETE_GENERATED_HOST_POSTOPT_SHELL_LINK_REQUIRED' if gap<=0 else
        'NOT_FIT_GENERATED_HOST_CONTINUE_STRUCTURAL_OPTIMIZATION',resources=resources,
        host_lut_gap=gap,shell_excluded=True,full_system_fit=False,ended_utc=now(),
        next='If host below capacity, new exact-source shell linking/postopt, complete ABI/host validation and physical certification before card21. If NOTFIT, use real hierarchy for next high-yield implementation. Old3656runtime identity is not valid for this commit.')
    save(O/'result.json',m.ST)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED',error=repr(exc),ended_utc=now())
            save(O/'failure.json',m.ST)
        raise
