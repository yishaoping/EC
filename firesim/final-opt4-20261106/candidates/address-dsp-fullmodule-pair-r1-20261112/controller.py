#!/usr/bin/python3
"""Source-bound full generated address leaf: attributes-only DSP mapping pair."""
import fcntl
import importlib.util
import json
import os
from pathlib import Path
import re
import resource
import shutil
import subprocess
import sys
import time

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-address-dsp-fullmodule-pair-r1-20261112'
SOURCE=D/'build-logs/Opt4-mcrams-dcache-owner-system-r1-20261111/goldengate/FireSim-generated.sv'
SUPPORT=D/'status-audits/full-ec-structural-priority-20261112/dsp-inference-support'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import identity, now, read, save, sha

ST={}
ATTRIBUTE='(* use_dsp = "yes" *) '


def exact(path,text):
    if path.exists():
        assert path.read_text()==text, ('Immutable input changed',str(path))
    else:
        path.write_text(text)


def update(status,**kw):
    ST.update(status=status,updated_utc=now(),**kw)
    save(O/'state.json',ST)


def prepare():
    O.mkdir(exist_ok=True)
    source_hash=sha(SOURCE)
    assert source_hash=='9d5380252ec779da8844b1ff632af84330fd2d0dff63912dd4c08180ae2ff3e1'
    original=SOURCE.read_text()
    match=re.search(r'^module PackageAddressStats\(',original,re.M)
    assert match
    end=original.index('\nendmodule',match.start())+len('\nendmodule')
    leaf=original[match.start():end]+'\n'
    assert not re.search(r'^  \w+ \w+ \(',leaf,re.M), 'Unexpected child modules: leaf must be complete'
    reference=leaf.replace('module PackageAddressStats(', 'module FPGATop(',1)
    pattern=r'^(  )(wire \[64:0\] (?:loadFirstNextWide|storeFirstNextWide|strictWriteReadNextWide)_(\d+)_(\d+) = [^;]+;[^\n]*)$'
    matches=list(re.finditer(pattern,reference,re.M))
    assert len(matches)==3072,len(matches)
    for name in ['loadFirstNextWide','storeFirstNextWide','strictWriteReadNextWide']:
        indices={(int(a),int(b)) for a,b in re.findall(r'wire \[64:0\] '+name+r'_(\d+)_(\d+) =',reference)}
        assert indices=={(i,g) for i in range(256) for g in range(4)}
    candidate=re.sub(pattern,lambda m:m[1]+ATTRIBUTE+m[2],reference,flags=re.M)
    assert candidate.count(ATTRIBUTE)==3072
    assert candidate.replace(ATTRIBUTE,'')==reference, 'RTL changed beyond synthesis attributes'
    exact(C/'Reference.sv',reference);exact(C/'Candidate.sv',candidate)
    mapped=(SUPPORT/'mapped.v').read_text()
    assert len(re.findall(r'\bDSP48E2\s*#',mapped))==2
    for reg in ['AREG','BREG','CREG','MREG','PREG']:
        assert re.findall(r'\.'+reg+r'\((\d+)\)',mapped)==['0','0'], reg
    assert not re.search(r'\bFD(?:RE|SE|CE|PE)\s',mapped), 'Support map added registers'
    paths=[C/'controller.py',C/'install.py',C/'Reference.sv',C/'Candidate.sv',SOURCE,
        SUPPORT/'add65.v',SUPPORT/'map.tcl',SUPPORT/'mapped.v',SUPPORT/'utilization.rpt',
        SUPPORT/'vivado-attempt2.log',W/'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py']
    pins=dict(schema='ec-address-full-generated-leaf-dsp-pair/1',
        functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
        derived_target='3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c',
        files={str(p):sha(p) for p in paths}, complete_actual_generated_leaf=True,
        leaf='PackageAddressStats', leaf_bytes=len(leaf), changed_adders=3072,
        unchanged_rtl_after_attribute_removal=True, target_registers_added=0,
        target_cycle_semantic_changes=0, target_source_modified=False,
        scope='Complete generated address module extracted from actual owner-MCRams host, renamed FPGATop for strict area parsing. Two identical OOC maps differing only3072 USE_DSP synthesis attributes. No host/shell FIT claim.',
        cpus=[220,221],memory_limit_gib=64,fpga_access=False,production_admission=False,
        ordering='Candidate first, Reference second; no saving asserted from incomplete pair')
    exact(C/'inputs.json',json.dumps(pins,indent=2,sort_keys=True)+'\n')
    return pins


def admission():
    while True:
        mem=int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))
        load=float(Path('/proc/loadavg').read_text().split()[0]);disk=shutil.disk_usage(W).free
        workers=[];overlap=[]
        for proc in Path('/proc').iterdir():
            if not proc.name.isdigit():continue
            try:
                args=(proc/'cmdline').read_bytes().split(b'\0');affinity=os.sched_getaffinity(int(proc.name))
                if args and args[0].endswith(b'/unwrapped/lnx64.o/vivado') and any(b'/data1/gzh/EC/' in a for a in args):workers.append(int(proc.name))
                if proc.stat().st_uid==os.getuid() and int(proc.name)!=os.getpid() and len(affinity)<=8 and affinity&{220,221}:overlap.append(int(proc.name))
            except OSError:pass
        if mem>=256*2**20 and load<64 and disk>=60*2**30 and len(workers)<8 and not overlap:
            return dict(utc=now(),memory_kib=mem,load1=load,disk_bytes=disk,existing_vivado=workers,cpu_overlap=overlap)
        update('WAITING_PRIVATE_FULL_MODULE_RESOURCES_NO_SIGNALS',memory_kib=mem,load1=load,
            disk_bytes=disk,existing_vivado=workers,cpu_overlap=overlap)
        time.sleep(30)


def stage(label,out,tcl,outputs):
    log=out/'vivado.log'
    assert not log.exists(), 'Preserve attempt, diagnose/version recovery'
    argv=['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(log),'-source',str(tcl)]
    started=time.monotonic()
    with (O/('map-'+label+'.log')).open('xb',buffering=0) as f:
        child=subprocess.Popen(argv,cwd=out,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,
            env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'2'})
        update('RUNNING_MAP_'+label.upper(),child=identity(child.pid),active_stage=label)
        while child.poll() is None:
            try:child.wait(timeout=30)
            except subprocess.TimeoutExpired:pass
            update('RUNNING_MAP_'+label.upper(),child=identity(child.pid),stage_seconds=time.monotonic()-started)
    receipt=dict(argv=argv,returncode=child.returncode,seconds=time.monotonic()-started,
        log_sha256=sha(log),outputs={str(p):sha(p) for p in outputs if p.is_file()},
        missing_outputs=[str(p) for p in outputs if not p.is_file()])
    save(O/('map-'+label+'-receipt.json'),receipt)
    update('COMPLETED_MAP_'+label.upper(),child={})
    assert child.returncode==0 and not receipt['missing_outputs'], (label,child.returncode,receipt['missing_outputs'])


def main():
    pins=prepare()
    if '--prepare-only' in sys.argv:
        print('PREPARED_ACTUAL_FULL_ADDRESS_DSP_ATTRIBUTES_ONLY_PAIR');return
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(),'Adopt original attempt, no restart'
    assert all(sha(p)==h for p,h in pins['files'].items())
    os.sched_setaffinity(0,{220,221});resource.setrlimit(resource.RLIMIT_AS,(64*2**30,64*2**30))
    ST.update(schema='ec-address-full-generated-leaf-dsp-pair/1',**identity(),
        started_utc=now(),inputs_sha256=sha(C/'inputs.json'),
        functional_baseline=pins['functional_baseline'],scope=pins['scope'],cpus=[220,221],
        target_cycle_changes=0,fpga_access=False,production_admission=False,whole_fit=False)
    spec=importlib.util.spec_from_file_location('full_address_dsp_parser',W/'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py')
    parser=importlib.util.module_from_spec(spec);spec.loader.exec_module(parser)
    results={}
    for label in ['Candidate','Reference']:
        update('ADMITTING_MAP_'+label.upper());save(O/(label+'-admission.json'),admission())
        out=O/label;out.mkdir();rtl=C/(label+'.sv')
        util=out/'utilization.rpt';hier=out/'hierarchical.rpt';dcp=out/'module.dcp';tcl=out/'map.tcl'
        exact(tcl,'set_param general.maxThreads 2\n'+f'read_verilog -sv {{{rtl}}}\n'+
            'synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e\n'+
            'if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}\n'+
            f'report_utilization -file {{{util}}}\nreport_utilization -hierarchical -file {{{hier}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
        stage(label,out,tcl,[util,hier,dcp])
        totals=parser.parse_total(util.read_text());parser.parse_hier(hier.read_text(),totals);parser.crosschecks(util.read_text(),totals)
        results[label]=dict(resources={k:v['used'] for k,v in totals.items()},
            outputs={str(p):sha(p) for p in [util,hier,dcp,tcl,rtl]})
        save(O/'paired-progress.json',results)
    savings={k:results['Reference']['resources'][k]-results['Candidate']['resources'][k] for k in results['Reference']['resources']}
    projected_dsp=192+results['Candidate']['resources']['DSPs']
    update('COMPLETE_ACTUAL_FULL_ADDRESS_DSP_AREA_PAIR_NOT_WHOLE_FIT',child={},completed_utc=now(),
        results=results,savings=savings,whole_dsp_allocation_check=projected_dsp,
        dsp_allocation_within_device=projected_dsp<=9024,
        next='Assess real fullmodule LUT reduction, DSP count, FF/memory and timing. Useful gain requires source-bound host composition plus fresh complete-host/shell capacity and physical certification; no speculative FIT claim.')
    save(O/'result.json',ST)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        if ST:
            update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED',error=repr(exc),ended_utc=now())
            save(O/'failure.json',ST)
        raise
