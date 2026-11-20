#!/usr/bin/python3
"""Independent physical retry of a sealed, unchanged original SVB host design.

Never changes producer outputs, constraints, running CAD or FPGA devices.
Only placement/fanout/routing directives differ. Results are not full Opt4.
"""
import importlib.util
import os
from pathlib import Path
import resource
import time

HERE = Path(__file__).resolve().parent
W = HERE.parent.parent
spec = importlib.util.spec_from_file_location(
    "route_common", W / "routes/cycleprecise-r2-20261111/run.py")
m = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m)
m.L = m.D / "cycleprecise-svb-spread-implementation-r1-20261111"
m.S = m.L / "state.json"


def main():
    m.L.mkdir(exist_ok=True)
    lock = (m.L / "instance.lock").open("a")
    m.fcntl.flock(lock, m.fcntl.LOCK_EX | m.fcntl.LOCK_NB)
    plan = m.read(HERE / "inputs.json")
    assert plan["functional_baseline"] == m.BASE
    assert not plan["target_changed"] and not plan["fpga_access"]
    for p, expected in plan["files"].items():
        assert m.sha(p) == expected, ("input changed", p)
    cpus = sorted(os.sched_getaffinity(0))[-2:]
    os.sched_setaffinity(0, cpus)
    resource.setrlimit(resource.RLIMIT_AS, (64 * 2**30, 64 * 2**30))
    m.ST.update(schema="ec-original-svb-independent-physical-implementation/1",
                **m.ident(os.getpid()), started_utc=m.now(),
                functional_baseline=m.BASE, source_id=plan["source_id"],
                fpga_access=False, target_changed=False, complete_opt4=False,
                cpus=cpus, memory_limit_gib=64,
                producer_state=plan["producer_state"],
                checkpoint_sha256=plan["files"][plan["checkpoint"]])
    # The original route continues. This process has its own working directory,
    # two CPU affinity, bounded memory, checkpoints and logs; no DUT synthesis.
    tcl = m.L / "implement.tcl"
    code = r'''set_param general.maxThreads 2
puts "EC_SVB_SPREAD_PLACE_DIRECTIVE_HELP"
place_design -help
open_checkpoint {CHECKPOINT}
if {[get_property PART [current_design]] ne "xcu280-fsvh2892-2L-e"} {error "wrong device"}
set unresolved {}
foreach c [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}] {
  if {$c eq "dbg_hub" && [get_property REF_NAME $c] eq "dbg_hub_CV" && [get_property IS_DEBUG_CORE $c]} {continue}
  lappend unresolved $c
}
if {[llength $unresolved]} {error "unresolved functional IP: $unresolved"}
implement_debug_core
if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "unresolved debug core"}
place_design -directive AltSpreadLogic_high
write_checkpoint -force {OUT/spread-placed.dcp}
report_design_analysis -congestion -file {OUT/congestion-placed.rpt}
report_timing_summary -report_unconstrained -file {OUT/timing-placed.rpt}
puts "EC_SVB_SPREAD_PLACED_CHECKPOINT_COMPLETE"
phys_opt_design -directive AggressiveFanoutOpt
write_checkpoint -force {OUT/spread-physopt.dcp}
report_high_fanout_nets -max_nets 40 -timing -file {OUT/high-fanout.rpt}
report_design_analysis -congestion -file {OUT/congestion-physopt.rpt}
puts "EC_SVB_SPREAD_PHYSOPT_CHECKPOINT_COMPLETE"
route_design -directive Explore
write_checkpoint -force {OUT/spread-routed.dcp}
report_route_status -file {OUT/route-status.rpt}
report_timing_summary -report_unconstrained -file {OUT/timing-routed.rpt}
report_utilization -file {OUT/utilization-routed.rpt}
report_drc -file {OUT/drc-routed.rpt}
report_clocks -file {OUT/physical-clocks.rpt}
check_timing -verbose -file {OUT/check-timing.rpt}
set pins [get_pins -hier -filter {NAME =~ *RationalClockBridge_clocks_0_buffer/O}]
if {[llength $pins] != 1} {error "target buffer absent/ambiguous"}
set clks [get_clocks -of_objects $pins]
if {[llength $clks] != 1} {error "target timing clock absent/ambiguous"}
set period [get_property PERIOD $clks]
set regs [all_registers -clock $clks]
if {$period <= 0 || $period > 20.01 || [llength $regs] < 1000} {error "target clock relaxed or absent"}
set setup [get_timing_paths -delay_type max -max_paths 1]
set hold [get_timing_paths -delay_type min -max_paths 1]
if {![llength $setup] || ![llength $hold]} {error "missing timing paths"}
set wns [get_property SLACK $setup]; set whs [get_property SLACK $hold]
puts "EC_SVB_SPREAD_TIMING period=$period registers=[llength $regs] WNS=$wns WHS=$whs"
if {$wns < 0 || $whs < 0} {error "setup/hold timing gate failed; preserve routed DCP"}
write_bitstream -force {OUT/original-svb-spread.bit}
puts "EC_SVB_SPREAD_BITSTREAM_COMPLETE"
exit 0
'''.replace("CHECKPOINT", plan["checkpoint"]).replace("OUT", str(m.L))
    if tcl.exists():
        assert tcl.read_text() == code
    else:
        tcl.write_text(code)
    outputs = [m.L / n for n in ["spread-placed.dcp", "spread-physopt.dcp",
        "spread-routed.dcp", "route-status.rpt", "timing-routed.rpt",
        "utilization-routed.rpt", "drc-routed.rpt", "physical-clocks.rpt",
        "check-timing.rpt", "original-svb-spread.bit"]]
    receipt = m.stage("physical-implementation", [
        "/tools/Xilinx/Vivado/2021.1/bin/vivado", "-mode", "batch", "-nojournal",
        "-log", str(m.L / "vivado.log"), "-source", str(tcl)], m.L,
        outputs=outputs, timeout=24*3600,
        env={**os.environ, "LD_LIBRARY_PATH": "", "OMP_NUM_THREADS": "2"})
    text = (m.L / "physical-implementation.log").read_text(errors="replace")
    assert "EC_SVB_SPREAD_BITSTREAM_COMPLETE" in text
    assert "EC_SVB_SPREAD_TIMING" in text
    result = dict(schema="ec-original-svb-independent-physical-implementation/1",
        status="BITSTREAM_WRITTEN_PENDING_INDEPENDENT_CERTIFICATION",
        functional_baseline=m.BASE, source_id=plan["source_id"],
        target_changed=False, fpga_access=False, complete_opt4=False,
        formal_parsec_admission=False, checkpoint_sha256=m.ST["checkpoint_sha256"],
        producer_state=plan["producer_state"], physical_directives=[
            "place_design AltSpreadLogic_high", "phys_opt_design AggressiveFanoutOpt",
            "route_design Explore"], outputs=receipt["outputs"],
        bitstream=str(m.L / "original-svb-spread.bit"), completed_utc=m.now(),
        deployment_rule="Do not race existing component onboard service. Reuse certified winner at safe 21-only boundary; no e2/global operations.")
    m.save(m.L / "result.json", result)
    m.save(m.L / "complete.json", {"result_sha256": m.sha(m.L / "result.json")})
    m.update(status=result["status"], child={})


if __name__ == "__main__":
    try:
        main()
    except Exception as error:
        m.update(status="FAILED_WITH_EVIDENCE", error=repr(error), child={})
        m.save(m.L / "failure.json", m.ST)
        raise
