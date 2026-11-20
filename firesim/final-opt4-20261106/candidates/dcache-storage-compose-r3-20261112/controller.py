#!/usr/bin/python3
"""Continue authenticated r2 RTL/closure; fix only the C++ test input binding."""
from pathlib import Path
import fcntl
import importlib.util
import json
import os
import re
import resource
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
R = W/'candidates/dcache-storage-compose-r2-20261112'
OLD = D/'build-logs/Opt4-dcache-storage-compose-r2-20261112'
O = D/'build-logs/Opt4-dcache-storage-compose-r3-20261112'
spec = importlib.util.spec_from_file_location('immutable_r2_controller', R/'controller.py')
m = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m)
m.O = O
from opt4_unattended_common import identity, now, read, save, sha


def main():
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Adopt existing attempt'
    os.sched_setaffinity(0,{216,217})
    resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    old = read(OLD/'state.json')
    assert old['status'] == 'FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED'
    assert "clear-inputs.h" in old['error']
    contract = read(OLD/'source-contract.json')
    assert all(sha(p)==h for p,h in contract['files'].items())
    receipt = read(OLD/'prepare-full-dcache-cycle-receipt.json')
    assert receipt['returncode'] == 0 and not receipt['missing_outputs']
    assert all(sha(p)==h for p,h in receipt['outputs'].items())
    cfg = read(R/'config.json')
    rtl = OLD/'goldengate/FireSim-generated.sv'
    rr = read(OLD/'rtl-receipt.json')
    assert rr['source_id'] == old['source_variant']
    assert rr['outputs'][str(rtl)] == sha(rtl)
    m.ST.update(schema='ec-dcache-storage-composition-continuation/1',**identity(),
        started_utc=now(),functional_baseline=m.BASE,parent_commit=m.PARENT,
        source_variant=old['source_variant'],source_variant_is_private=True,
        source_contract=str(OLD/'source-contract.json'),cpus=[216,217],
        fpga_access=False,whole_synthesis=False,production_admission=False,
        scope=old['scope'],no_RTL_regeneration=True)
    m.update('VERIFYING_AUTHENTICATED_R2_CLOSURE_AND_CORRECTED_STIMULUS')
    prepared = O/'cycle-prepared'
    prepared.mkdir()
    source = OLD/'cycle-prepared'
    reused = {}
    for name in ['frozen.sv','candidate.sv','pair.sv','mismatch-names.h','preparation.json']:
        p = source/name
        os.link(p,prepared/name)
        reused[str(p)] = sha(p)
    stimulus = W/'candidates/dcache-frozen-cycle-domain-r5-20261111'
    for name in ['clear-inputs.h','stimulus.cpp']:
        m.exact(prepared/name,(stimulus/name).read_text())
    # The earlier successful harness uses Verilator's double-underscore name
    # encoding. Confirm the fixed header initializes exactly the same ports.
    original_clear = (source/'clear-inputs.h').read_text()
    corrected_clear = (prepared/'clear-inputs.h').read_text()
    original_names = set(re.findall(r'd\.([A-Za-z0-9_]+)',original_clear))
    corrected_names = set(re.findall(r'd\.([A-Za-z0-9_]+)',corrected_clear))
    assert {n.replace('___05F','__') for n in corrected_names} == original_names
    save(O/'recovery.json',dict(prior_failure=str(OLD/'failure.json'),
        source_variant=old['source_variant'],same_hardware=True,reused=reused,
        reused_RTL_sha256=sha(rtl),source_unchanged=True,no_elaboration=True,
        corrected_input_ports=len(corrected_names),
        stimulus_sha256=sha(prepared/'stimulus.cpp'),header_sha256=sha(prepared/'clear-inputs.h')))
    exe = O/'obj/VDCacheCyclePair'
    m.stage('compile-full-dcache-cycle',['/usr/local/bin/verilator','--cc','--exe','--build','-j','2',
        '--compiler','clang','--top-module','DCacheCyclePair','--Mdir',O/'obj',
        '--output-split','10000','--output-split-cfuncs','200','-Wno-fatal',
        '--x-initial','0','--x-assign','0','-DRANDOMIZE_REG_INIT','-DRANDOMIZE_MEM_INIT',"-DRANDOM=32'h0",
        '-DSTOP_COND=1','-DPRINTF_COND=1','-CFLAGS','-O0 -fbracket-depth=4096 -I'+str(prepared),
        '-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',prepared/'frozen.sv',prepared/'candidate.sv',
        prepared/'pair.sv',prepared/'stimulus.cpp'],[exe])
    log = m.stage('full-dcache-cycle',[exe])
    assert 'COMPLETE_FROZEN_DCACHE_CYCLE_PASS cycles=8192' in log.read_text()
    m.update('FULL_DCACHE_FINITE_CYCLES_PASS_PREPARING_AREA',
        complete_dcache_cycles_verified=True,full_formal=False,comparison=str(log))
    observed,reference = m.area_prepare(rtl,OLD/'elaborate/firesim.firesim.FireSim.anno.json')
    assert sha(reference['report']) == reference['report_sha256']
    out = O/'area';out.mkdir()
    tcl,util,hier,dcp = [out/n for n in ['map.tcl','utilization.rpt','hierarchical.rpt','module.dcp']]
    m.exact(tcl,'set_param general.maxThreads 2\n'+f'read_verilog -sv {{{observed}}}\n'+
        f'synth_design -mode out_of_context -top {m.TOP} -part xcu280-fsvh2892-2L-e\n'+
        'if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}\n'+
        f'report_utilization -file {{{util}}}\nreport_utilization -hierarchical -hierarchical_depth 25 -file {{{hier}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
    m.stage('map-complete-dcache',['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal',
        '-log',out/'vivado.log','-source',tcl],[util,hier,dcp],cwd=out,mapping=True)
    sp = importlib.util.spec_from_file_location('resource_parser',W/'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py')
    parser = importlib.util.module_from_spec(sp);sp.loader.exec_module(parser)
    totals = parser.parse_total(util.read_text());parser.crosschecks(util.read_text(),totals)
    resources = {k:v['used'] for k,v in totals.items()}
    saved = reference['resources']['CLB LUTs']-resources['CLB LUTs']
    m.update('COMPLETE_FULL_DCACHE_CYCLE_AND_PAIRED_MODULE_AREA_NOT_WHOLE_FIT',
        candidate_resources=resources,reference_resources=reference['resources'],
        module_lut_saved=saved,ended_utc=now(),full_host_saving_unknown=True,whole_fit=False,
        next='Material AddressStats result plus complete-module host/token/ABI validation before one completehost postopt. Never add local module deltas to a different host baseline.')
    save(O/'result.json',m.ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED',error=repr(exc),ended_utc=now())
            save(O/'failure.json',m.ST)
        raise
