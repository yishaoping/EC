#!/usr/bin/python3
"""Prepare an independent, checkpoint-only repair after actual r3 failure.

This entry point only writes a reviewed Tcl input. It never executes CAD,
changes the r3 consumer, publishes certification, or touches a device.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import subprocess

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
AUDIT = D / 'status-audits/round128-shell-collateral-20261112'
R2 = C.parent / 'mcrams-full-host-continuation-r2-20261112'
R3 = C.parent / 'mcrams-host-clock-contract-r3-20261112'
SHELL = W / 'dcp-work/C4-dcp-20261110T071734Z'
OLD_DUT = SHELL / 'vivado_proj/firesim.gen/sources_1/bd/design_1/ip/design_1_firesim_wrapper_0_0/design_1_firesim_wrapper_0_0.dcp'
BD = SHELL / 'vivado_proj/firesim.srcs/sources_1/bd/design_1/design_1.bd'
PREVIOUS = D / 'build-logs/Opt4-mcrams-shell-physical-r2-20261112'
OUTPUT = D / 'build-logs/Opt4-mcrams-shell-ipcollateral-r4-20261112'
NATIVE_CLOCK = 'clk_out1_design_1_clk_wiz_0_0'

NATIVE_GATE = f'''
set hp [get_pins -hier -quiet -filter {{NAME =~ */clk_wiz_0/inst/clkout1_buf/O}}]
if {{[llength $hp]!=1}} {{error "physical host BUFG output not unique"}}
set physical [get_clocks -quiet -of_objects $hp]
set native [get_clocks -quiet {NATIVE_CLOCK}]
if {{[llength $physical]!=1 || [llength $native]!=1 || $physical ne $native}} {{
 error "actual physical clock differs from pinned shell evidence: physical=$physical native=$native"
}}
'''

MASTER_GATE = f'''
foreach name {{buildtop_reference_clock tileClockGroup_tile_1}} {{
 set c [get_clocks -quiet $name]
 if {{[llength $c]!=1 || [get_property MASTER_CLOCK $c] ne "{NATIVE_CLOCK}"}} {{
  error "generated target clock has wrong physical master: $name"
 }}
}}
'''


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for chunk in iter(lambda: f.read(2**20), b''):
            h.update(chunk)
    return h.hexdigest()


def read(path):
    return json.loads(Path(path).read_text())


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return m


def verify():
    pins = read(C / 'inputs.json')
    for path, digest in pins['files'].items():
        assert sha(path) == digest, ('repair input changed', path)
    manifest = read(AUDIT / 'collateral-manifest.json')
    for path, digest in manifest['files'].items():
        assert sha(path) == digest, ('generated collateral changed', path)
    assert len(manifest['implementation_order']) == 27
    assert all('_ooc.xdc' not in p for p in manifest['implementation_order'])
    module('r3_clock_contract', R3 / 'physical.py').verify()
    plan = read(R2 / 'physical-plan.json')
    for path, digest in plan['immutable_inputs'].items():
        assert sha(path) == digest, ('physical plan input changed', path)
    return plan, manifest


def render(wrapper, output):
    """Use the original BD loader; keep generated scope/order under Vivado."""
    plan = read(R2 / 'physical-plan.json')
    r2 = module('r2_physical_gate', R2 / 'physical.py')
    r3 = module('r3_physical_gate', R3 / 'physical.py')
    return f'''set_param general.maxThreads 8
create_project -in_memory -part xcu280-fsvh2892-2L-e
set_property design_mode GateLvl [current_fileset]
set_property ip_output_repo {{{SHELL}/vivado_proj/firesim.cache/ip}} [current_project]
set_property ip_cache_permissions read [current_project]
set_property XPM_LIBRARIES {{XPM_CDC XPM_FIFO XPM_MEMORY}} [current_project]
add_files -quiet {{{plan['shell_top_dcp']}}}
set_param project.isImplRun true
add_files {{{BD}}}
set_param project.isImplRun false
set old [get_files -all -quiet {{{OLD_DUT}}}]
if {{[llength $old]!=1}} {{error "old host checkpoint not uniquely identified"}}
set_property USED_IN_IMPLEMENTATION false $old
if {{[get_property USED_IN_IMPLEMENTATION $old]}} {{error "old DUT checkpoint still enabled"}}
add_files -quiet {{{wrapper}}}
set replacement [get_files -all -quiet {{{wrapper}}}]
if {{[llength $replacement]!=1}} {{error "replacement checkpoint missing"}}
set_property SCOPED_TO_CELLS {{design_1_i/firesim_wrapper_0}} $replacement
report_compile_order -constraints -file {{{output}/constraint-order.rpt}}
set_param project.isImplRun true
link_design -top design_1_wrapper -part xcu280-fsvh2892-2L-e
set_param project.isImplRun false
{r2.gate()}
write_checkpoint -force {{{output}/linked-with-ip-constraints.dcp}}
report_clocks -file {{{output}/linked-native-clocks.rpt}}
# Bind to the observed native clock; never create or rename a physical clock.
{NATIVE_GATE}
set shim [get_cells -hier -quiet -filter {{REF_NAME == F1Shim}}]
if {{[llength $shim]!=1}} {{error "F1Shim constraint scope not unique"}}
read_xdc -cells $shim {{{output}/physical-source-bound.implementation.xdc}}
read_xdc {{{plan['bitstream_xdc']}}}
opt_design -directive Explore
write_checkpoint -force {{{output}/top-opt.dcp}}
report_utilization -file {{{output}/top-postopt-utilization.rpt}}
report_utilization -hierarchical -hierarchical_depth 30 -file {{{output}/top-postopt-hierarchical.rpt}}
report_clocks -file {{{output}/top-preplace-clocks.rpt}}
report_exceptions -file {{{output}/top-preplace-exceptions.rpt}}
write_xdc -force {{{output}/top-preplace-effective.xdc}}
{r3.CLOCK_GATE.replace('get_clocks -quiet host_clock', 'get_clocks -quiet ' + NATIVE_CLOCK)}
{MASTER_GATE}
check_timing -verbose -file {{{output}/top-preplace-check-timing.rpt}}
set fp [open {{{output}/top-preplace-check-timing.rpt}} r]
set checks [read $fp];close $fp
if {{![regexp {{checking no_clock \(0\)}} $checks] || ![regexp {{checking unconstrained_internal_endpoints \(0\)}} $checks]}} {{
 error "preplace clock coverage failed"
}}
puts "IP_COLLATERAL_RELINK_TOP_OPT_CONTRACT_PASSED_NO_PLACE"
exit 0
'''


def source_bound_xdc():
    """Change only the source lookup in a separate integration artifact.

    All six generated commands, two divide-by-one clocks, destination pins,
    and setup/hold multicycles 1/0 and 2/1 retain their original semantics.
    The generator's file and all BD/IP collateral stay byte-for-byte intact.
    """
    plan = read(R2 / 'physical-plan.json')
    source = Path(plan['implementation_xdc']).read_text()
    needle = '[get_clocks host_clock]'
    assert source.count(needle) == 2
    bound = source.replace(needle, '[get_clocks ' + NATIVE_CLOCK + ']')
    assert bound.replace('[get_clocks ' + NATIVE_CLOCK + ']', needle) == source
    return bound


def admit_failed_r3_identity_only():
    """Require the actual predecessor to have exited its exact cgroup."""
    original = module('r2_identity', R2 / 'physical.py')
    state = read(D / 'Opt4-mcrams-shell-physical-r2-state.json')
    assert state['physical_controller_revision'] == 'r3-generated-clock-contract'
    assert state['status'] == 'FAILED_WITH_EVIDENCE' and state['stage'] == 'top_opt'
    assert not original.live(state) and not original.live(state.get('child', {}))
    unit = 'ec-opt4-auto-mcrams-shell-physical-r3-clock-3656aec4.service'
    props = dict(line.split('=', 1) for line in subprocess.check_output(
        ['systemctl', 'show', unit, '-p', 'MainPID', '-p', 'ControlGroup', '-p', 'ActiveState'], text=True).splitlines())
    if props['MainPID'] != '0' or props['ActiveState'] not in ['inactive', 'failed']:
        raise BlockingIOError('exact predecessor service has not exited')
    assert props['ControlGroup'] in ['', '/system.slice/' + unit]
    cg = Path('/sys/fs/cgroup/systemd/system.slice') / unit
    if cg.exists() and any(p.read_text().split() for p in cg.rglob('cgroup.procs')):
        raise BlockingIOError('exact predecessor cgroup has not released')
    failure = read(PREVIOUS / 'failure.json')
    assert failure == state
    assert 'missing exact host clock' in (PREVIOUS / 'top_opt.log').read_text()
    return state, props


def admit_failed_r3():
    """Only an actual failure and empty exact service cgroup admit preparation."""
    state, props = admit_failed_r3_identity_only()
    admission = read(D / 'build-logs/Opt4-mcrams-full-host-continuation-r2-20261112/capacity-parity-admission.json')
    for key in ['capacity_result', 'target_parity_result']:
        assert sha(admission[key]) == admission[key + '_sha256']
    assert read(admission['capacity_result'])['full_host_fit']
    assert read(admission['target_parity_result'])['captured_finite_parity_passed']
    receipt = read(PREVIOUS / 'wrapper_only-receipt.json')
    assert receipt['returncode'] == 0
    for path, digest in receipt['outputs'].items():
        assert sha(path) == digest
    wrapper = PREVIOUS / 'wrapper-host-linked.dcp'
    assert str(wrapper) in receipt['outputs']
    assert not OUTPUT.exists(), 'independent repair output already exists'
    OUTPUT.mkdir()
    evidence = dict(previous_state=state, previous_service=props,
                    previous_failure_sha256=sha(PREVIOUS / 'failure.json'),
                    wrapper_receipt_sha256=sha(PREVIOUS / 'wrapper_only-receipt.json'),
                    wrapper_sha256=sha(wrapper), wrapper=str(wrapper),
                    inputs_sha256=sha(C / 'inputs.json'),
                    no_DUT_resynthesis=True, fpga_access=False)
    (OUTPUT / 'repair-admission.json').write_text(json.dumps(evidence, indent=2) + '\n')
    (OUTPUT / 'physical-source-bound.implementation.xdc').write_text(source_bound_xdc())
    (OUTPUT / 'top_opt_repair.tcl').write_text(render(wrapper, OUTPUT))
    return OUTPUT / 'top_opt_repair.tcl'


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--prepare-after-r3-failure', action='store_true')
    args = parser.parse_args()
    _, manifest = verify()
    if args.prepare_after_r3_failure:
        print(admit_failed_r3())
    else:
        print(json.dumps(dict(status='PREPARED_NOT_ADMITTED_OR_EXECUTED',
            pinned_collateral_files=len(manifest['files']),
            implementation_constraints=len(manifest['implementation_order']),
            fpga_access=False, active_r3_unchanged=True)))


if __name__ == '__main__':
    main()
