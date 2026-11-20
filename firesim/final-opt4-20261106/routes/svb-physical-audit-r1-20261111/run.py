#!/usr/bin/python3
"""Read a sealed component checkpoint in a separate Vivado process.

No target changes, writeback to the producer, FPGA I/O or route interruption.
"""
import importlib.util
import os
from pathlib import Path

HERE = Path(__file__).resolve().parent
W = HERE.parent.parent
spec = importlib.util.spec_from_file_location(
    "route_common", W / "routes/cycleprecise-r2-20261111/run.py")
m = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m)
m.L = m.D / "cycleprecise-svb-physical-audit-r1-20261111"
m.S = m.L / "state.json"


def main():
    m.L.mkdir(exist_ok=True)
    lock = (m.L / "instance.lock").open("a")
    m.fcntl.flock(lock, m.fcntl.LOCK_EX | m.fcntl.LOCK_NB)
    plan = m.read(HERE / "inputs.json")
    assert plan["functional_baseline"] == m.BASE
    for p, expected in plan["files"].items():
        assert m.sha(p) == expected, ("input changed", p)
    m.ST.update(schema="ec-original-svb-physical-audit/1",
                **m.ident(os.getpid()), started_utc=m.now(),
                functional_baseline=m.BASE, fpga_access=False,
                target_changed=False, checkpoint=plan["checkpoint"])
    tcl = m.L / "audit.tcl"
    text = '''set_param general.maxThreads 2
open_checkpoint {CHECKPOINT}
puts "EC_AUDIT_DESIGN [current_design]"
report_clocks -file {OUT/physical-clocks.rpt}
check_timing -verbose -file {OUT/check-timing.rpt}
report_timing_summary -report_unconstrained -max_paths 10 -file {OUT/timing-summary.rpt}
report_timing -max_paths 30 -input_pins -nets -file {OUT/timing-paths.rpt}
report_high_fanout_nets -max_nets 40 -timing -file {OUT/high-fanout.rpt}
report_utilization -slr -file {OUT/slr-utilization.rpt}
report_design_analysis -congestion -file {OUT/congestion.rpt}
set fp [open {OUT/clock-targets.tsv} w]
foreach pin [get_pins -hier -quiet -filter {NAME =~ *RationalClockBridge_clocks_0_buffer/O}] {
  set clocks [get_clocks -of_objects $pin]
  puts $fp "$pin\t$clocks"
  foreach c $clocks {
    puts $fp "period=[get_property PERIOD $c]\tregisters=[llength [all_registers -clock $c]]"
  }
}
close $fp
set fp [open {OUT/pblocks.tsv} w]
foreach p [get_pblocks -quiet] {
  puts $fp "$p\t[get_property GRID_RANGES $p]\tcells=[llength [get_cells -quiet -of_objects $p]]"
}
close $fp
puts "EC_SVB_PHYSICAL_AUDIT_COMPLETE"
exit 0
'''.replace("CHECKPOINT", plan["checkpoint"]).replace("OUT", str(m.L))
    if tcl.exists():
        assert tcl.read_text() == text
    else:
        tcl.write_text(text)
    outputs = [m.L / p for p in ["physical-clocks.rpt", "check-timing.rpt",
               "timing-summary.rpt", "timing-paths.rpt", "high-fanout.rpt",
               "slr-utilization.rpt", "congestion.rpt", "clock-targets.tsv",
               "pblocks.tsv"]]
    receipt = m.stage("checkpoint-audit", ["/tools/Xilinx/Vivado/2021.1/bin/vivado",
        "-mode", "batch", "-nojournal", "-log", str(m.L / "vivado.log"),
        "-source", str(tcl)], m.L, outputs, timeout=3600,
        env={**os.environ, "LD_LIBRARY_PATH": ""})
    assert "EC_SVB_PHYSICAL_AUDIT_COMPLETE" in (m.L / "checkpoint-audit.log").read_text()
    result = dict(schema="ec-original-svb-physical-audit/1",
        status="CHECKPOINT_AUDIT_COMPLETE_NOT_ROUTE_OR_TIMING_PASS",
        functional_baseline=m.BASE, target_changed=False, fpga_access=False,
        checkpoint=plan["checkpoint"], checkpoint_sha256=plan["files"][plan["checkpoint"]],
        outputs=receipt["outputs"], completed_utc=m.now(),
        scope="Separate saved post-place checkpoint only; live route continues unchanged")
    m.save(m.L / "result.json", result)
    m.save(m.L / "complete.json", {"result_sha256": m.sha(m.L / "result.json")})
    m.update(status=result["status"], child={})


if __name__ == "__main__":
    try:
        main()
    except Exception as error:
        m.update(status="FAILED_WITH_EVIDENCE", error=repr(error))
        raise
