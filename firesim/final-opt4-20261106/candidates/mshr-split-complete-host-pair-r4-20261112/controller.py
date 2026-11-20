#!/usr/bin/python3
"""Serial same-harness complete MSHR host maps; never whole EC CAD."""
from pathlib import Path
import fcntl
import importlib.util
import json
import os
import re
import resource
import subprocess
import sys

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-mshr-split-complete-host-pair-r4-20261112'
P1=D/'build-logs/Opt4-mshr-queue-split-memory-r1-20261112'
P4=D/'build-logs/Opt4-mshr-queue-split-memory-r4-20261112'
SOURCE=W/'Opt4-area-sprint-20261112/chipyard/generators/boom/src/main/scala/lsu/mshrs.scala'
spec=importlib.util.spec_from_file_location('stages',W/'candidates/dcache-storage-compose-r2-20261112/controller.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m);m.O=O
from opt4_unattended_common import identity,now,read,save,sha


def main():
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(),'Adopt existing area owner'
    os.sched_setaffinity(0,{204,205});resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    finite=read(P4/'result.json')
    assert finite['finite_cycles']==65536 and finite['all_outputs_including_invalid_payload_compared']
    binding=read(W/'candidates/mshr-queue-split-memory-r1-20261112/source-binding.json')
    assert all(sha(p)==h for p,h in binding['files'].items())
    assert sha(SOURCE)==binding['parent_mshrs_sha256']
    compiled=read(P1/'compile-source-receipt.json')
    assert compiled['returncode']==0 and all(sha(p)==h for p,h in compiled['outputs'].items())
    cfg=read(W/'candidates/address-banked-storage-compose-r1-20261112/config.json')
    m.ST.update(schema='ec-complete-mshr-split-host-pair/1',**identity(),started_utc=now(),
        hardware_parent=binding['hardware_parent'],functional_baseline=binding['functional_baseline'],
        cpus=[204,205],memory_limit_gib=64,fpga_access=False,production_admission=False,
        no_whole_EC_CAD=True,shell_excluded=True,full_system_fit=False,
        queue_finite_result_sha256=sha(P4/'result.json'),complete_MSHR_cycle_equivalence=False,
        scope='Actual six-MSHR file with complete original public IO in identical PeekPoke/MC harness. Queue finite parity only. Pair area is neither whole-host saving nor FIT.')
    m.update('PREPARING_COMPLETE_MSHR_SAME_HARNESS_PAIR')
    java=[cfg['java'],'-Xmx24G','-Xss32M','-XX:ActiveProcessorCount=2','-Dec.dac.firesim=true']
    PREVIOUS=D/'build-logs/Opt4-mshr-split-complete-host-pair-r1-20261112'
    rr=read(PREVIOUS/'compile-reference-receipt.json')
    assert rr['returncode']==0 and all(sha(p)==h for p,h in rr['outputs'].items())
    refclasses=PREVIOUS/'reference-classes'
    save(O/'recovery.json',dict(reason='Isolated PeekPoke cannot infer unused brupdate.b2.target_offset width. New common wrapper sizes it32bits and preserves every boundary leaf. Actual MSHR source and queue compiled classes reused unchanged.',
        parent_failure_sha256=sha(PREVIOUS/'failure.json'),reference_compile_sha256=sha(PREVIOUS/'compile-reference-receipt.json')))
    wrapperclasses=O/'wrapper-classes';wrapperclasses.mkdir()
    compiler=java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main',
        '-classpath',':'.join(cfg['classpath']),'-Xplugin:'+cfg['plugin']]
    m.stage('compile-harness',compiler+['-d',wrapperclasses,C/'Emit.scala'],[wrapperclasses/'mshrsplitarea/Emit.class'])
    results={};interfaces=[]
    parserpath=W/'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py'
    spec=importlib.util.spec_from_file_location('parser',parserpath)
    parser=importlib.util.module_from_spec(spec);spec.loader.exec_module(parser)
    for label,classes in [('Reference',refclasses),('Candidate',P1/'classes')]:
        cp=str(wrapperclasses)+':'+str(classes)+':'+':'.join(cfg['classpath'])
        target=O/(label+'-target');target.mkdir()
        log=m.stage('emit-'+label,java[:1]+['-verbose:class']+java[1:]+['-cp',cp,'mshrsplitarea.Emit',target],
            [target/'MSHR.fir',target/'MSHR.anno.json'])
        assert any('boom.lsu.BoomMSHRFile' in l and str(classes) in l for l in log.read_text().splitlines())
        fir=(target/'MSHR.fir').read_text()
        # Compare every original boundary port and width, before host transforms.
        block=re.split(r'\n  (?:ext)?module ',fir.split('module ActualMSHRModule :',1)[1])[0]
        interface=[l.strip() for l in block.splitlines() if re.match(r'^    (input|output) ',l)]
        assert interface
        interfaces.append(interface)
        if len(interfaces)==2:assert interfaces[0]==interfaces[1],'Complete MSHR target IO changed'
        host=O/(label+'-host');host.mkdir()
        m.stage('goldengate-'+label,java+['-cp',cp,'midas.stage.GoldenGateMain','-i',target/'MSHR.fir',
            '-td',host,'-faf',target/'MSHR.anno.json','-ggcp','mshrsplitarea','-ggcs','MCConfig',
            '--output-filename-base','FireSim-generated'],[host/'FireSim-generated.sv',host/'FireSim-generated.synthesis.xdc'])
        util,hier,dcp=[host/n for n in ['utilization.rpt','hierarchical.rpt','module.dcp']]
        tcl=host/'map.tcl'
        m.exact(tcl,'set_param general.maxThreads 2\n'+
            ''.join(f'read_verilog -sv {{{p}}}\n' for p in sorted(host.glob('*.v'))+[host/'FireSim-generated.sv'])+
            f'read_xdc {{{host/"FireSim-generated.synthesis.xdc"}}}\n'+
            'synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e\n'+
            'if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}\n'+
            f'report_utilization -file {{{util}}}\nreport_utilization -hierarchical -file {{{hier}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
        m.stage('map-'+label,['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal',
            '-log',host/'vivado.log','-source',tcl],[util,hier,dcp],cwd=host,mapping=True)
        total=parser.parse_total(util.read_text());parser.crosschecks(util.read_text(),total)
        results[label]=dict(resources={k:v['used'] for k,v in total.items()},
            outputs={str(p):sha(p) for p in [util,hier,dcp,host/'FireSim-generated.sv',tcl]})
        save(O/'progress.json',results)
    saving=results['Reference']['resources']['CLB LUTs']-results['Candidate']['resources']['CLB LUTs']
    m.update('COMPLETE_SAME_HARNESS_MSHR_HOST_PAIR_NOT_FULL_EC',results=results,
        same_scope_LUT_saved=saving,production_admission=False,ended_utc=now(),
        next='Reject regressions or immaterial gain; substantial saving still needs complete DCache observation cycles and source-bound composition. No automatic whole CAD from this pair.')
    save(O/'result.json',m.ST)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED',error=repr(exc),ended_utc=now())
            save(O/'failure.json',m.ST)
        raise
