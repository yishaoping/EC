#!/usr/bin/env python3
"""Bounded deterministic physical recovery, never invokes a model or a device."""
import datetime as dt
import fcntl
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import time

C = Path(__file__).resolve().parent
INPUT = json.loads((C / 'inputs.json').read_text())
O = Path(INPUT['output_dir'])
VIVADO = '/tools/Xilinx/Vivado/2021.1/bin/vivado'
AUDIT_UNIT = 'ec-performance-only-routability-audit-r1-20261114.service'
PROFILE = 'EC Performance-Only: data preservation + cache isolation'


def now():
    return dt.datetime.now(dt.timezone.utc).isoformat()


def save(path, value):
    path = Path(path)
    tmp = path.with_suffix(path.suffix + '.tmp')
    tmp.write_text(json.dumps(value, indent=2, sort_keys=True) + '\n')
    os.replace(tmp, path)


def digest(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(8 * 1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def route_metrics(path):
    text = Path(path).read_text()
    def number(label):
        m = re.search(label + r'\.+\s*:\s*(\d+)', text, re.I)
        return int(m[1]) if m else None
    total = number(r'# of routable nets')
    full = number(r'# of fully routed nets')
    errors = number(r'# of nets with routing errors')
    unrouted = number(r'# of unrouted nets')
    partial = number(r'# of partially routed nets')
    conflict = number(r'# of nets with resource conflicts')
    legal = (total is not None and full == total and errors in (None, 0)
             and unrouted in (None, 0) and partial in (None, 0)
             and conflict in (None, 0))
    return dict(routable=total, fully_routed=full, errors=errors,
                unrouted=unrouted, partial=partial, conflicts=conflict,
                legal=legal, fraction=full / total if total and full is not None else None)


def timing_metrics(path):
    lines = Path(path).read_text().splitlines()
    for i, line in enumerate(lines):
        if 'WNS(ns)' in line and 'TNS(ns)' in line:
            for row in lines[i+1:i+5]:
                cols = row.split()
                try:
                    if len(cols) >= 8:
                        return dict(wns=float(cols[0]), tns=float(cols[1]),
                                    setup_endpoints=int(cols[2]), whs=float(cols[4]),
                                    ths=float(cols[5]), hold_endpoints=int(cols[6]))
                except ValueError:
                    pass
    raise ValueError('timing summary has no numeric setup/hold row')


def utilization(path):
    result = {}
    for line in Path(path).read_text().splitlines():
        cols = [v.strip().rstrip('*') for v in line.split('|')]
        if len(cols) >= 7 and cols[1] in ['CLB LUTs', 'CLB Registers', 'CARRY8', 'Block RAM Tile', 'DSPs', 'URAM'] and cols[1] not in result:
            try:
                result[cols[1]] = dict(used=float(cols[2].replace(',', '')),
                                      available=float(cols[5].replace(',', '')))
            except ValueError:
                pass
    return result


ST = dict(schema='ec-performance-only-routability-campaign/1', profile=PROFILE,
          hardware_commit=INPUT['hardware_commit'], functional_baseline=INPUT['frozen_parent'],
          pid=os.getpid(), started_utc=now(), status='STARTING', candidates=[],
          fpga_access=False, model_requests=False, baseline_preserved=True)


def update(status, **kw):
    ST.update(status=status, updated_utc=now(), **kw)
    save(O / 'state.json', ST)


def run(name, code, hours=12):
    d = O / 'candidates' / name
    d.mkdir(exist_ok=False)
    script = d / 'run.tcl'
    script.write_text(code.replace('@OUT@', str(d)))
    update('RUNNING_' + name.upper(), current_candidate=name,
           tcl_sha256=digest(script), child_pid=None)
    argv = [VIVADO, '-mode', 'batch', '-nojournal', '-log', str(d/'vivado.log'),
            '-source', str(script)]
    with (d / 'stdout.log').open('wb') as stream:
        p = subprocess.Popen(argv, cwd=d, env={**os.environ, 'LD_LIBRARY_PATH': '',
                             'OMP_NUM_THREADS': '8', 'TMPDIR': str(O/'tmp')},
                             stdin=subprocess.DEVNULL, stdout=stream, stderr=subprocess.STDOUT)
        update(ST['status'], child_pid=p.pid, child_started_utc=now())
        start = time.monotonic()
        while p.poll() is None:
            try:
                p.wait(timeout=30)
            except subprocess.TimeoutExpired:
                pass
            log = d/'vivado.log'
            tail = log.read_text(errors='replace').splitlines()[-200:] if log.exists() else []
            phase = next((l for l in reversed(tail) if l.startswith('Phase ')), None)
            update(ST['status'], phase=phase, elapsed_seconds=time.monotonic()-start,
                   disk_free_gib=shutil.disk_usage(O).free/2**30)
            # Guards apply only to the new, owned candidate. Existing CAD is never signalled.
            if p.poll() is None and (shutil.disk_usage(O).free < 35*2**30 or time.monotonic()-start > hours*3600):
                p.terminate()
                try:
                    p.wait(timeout=60)
                except subprocess.TimeoutExpired:
                    p.kill(); p.wait()
                save(d/'guard.json', dict(utc=now(), reason='disk or bounded candidate runtime'))
    row = dict(candidate=name, returncode=p.returncode, ended_utc=now(),
               tcl_sha256=digest(script), log=str(d/'vivado.log'))
    if (d/'route-status.rpt').exists():
        row['routing'] = route_metrics(d/'route-status.rpt')
    if (d/'timing.rpt').exists():
        row['timing'] = timing_metrics(d/'timing.rpt')
    if (d/'utilization.rpt').exists():
        row['resources'] = utilization(d/'utilization.rpt')
    if (d/'remapped-utilization.rpt').exists():
        row['remapped_resources'] = utilization(d/'remapped-utilization.rpt')
    if (d/'placement-congestion-level.txt').exists():
        row['placed_congestion_level'] = int((d/'placement-congestion-level.txt').read_text())
    row['bitstream_generated'] = (d/'firesim.bit').is_file()
    save(d/'result.json', row)
    ST['candidates'].append(row)
    update('CANDIDATE_RECORDED', child_pid=None)
    return row


def physical_code(checkpoint, directive):
    return r'''
set_param general.maxThreads 8
set out {@OUT@}
proc stage {name script} {
    global out
    set f [open "$out/current-stage.txt" w]; puts $f $name; close $f
    puts "EC_PHYSICAL_STAGE $name"
    uplevel 1 $script
}
stage open {open_checkpoint {@CHECKPOINT@}}
if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "unresolved functional cells"}
write_xdc -force "$out/input-effective.xdc"
stage clock_contract {source {@CLOCK_CONTRACT@}}
write_xdc -force "$out/repaired-effective.xdc"
stage unroute {route_design -unroute}
stage unplace {place_design -unplace}
# The original has CLB site occupancy 99.82/99.93/100% despite only 78% LUTs.
# MUXF remapping is an equivalent primitive transform; preserve its checkpoint.
stage muxf_remap {opt_design -muxf_remap}
write_checkpoint -force "$out/muxf-remapped.dcp"
report_utilization -file "$out/remapped-utilization.rpt"
set f [open "$out/remapped-utilization.rpt" r]; set capacity [read $f]; close $f
set used -1; set available -1
foreach line [split $capacity \n] {
    set fields [split $line |]
    if {[llength $fields] > 6 && [string trimright [string trim [lindex $fields 1]] *] eq "CLB LUTs"} {
        set used [string trim [lindex $fields 2]]; set available [string trim [lindex $fields 5]]; break
    }
}
if {$used < 0 || $available < 0 || $used > $available} {error "MUXF remap exceeds LUT capacity or capacity unavailable"}
stage spread {place_design -directive @DIRECTIVE@}
write_checkpoint -force "$out/placed.dcp"
report_utilization -slr -file "$out/per-slr-placed.rpt"
report_design_analysis -congestion -file "$out/congestion-placed.rpt"
report_high_fanout_nets -timing -slr -max_nets 40 -file "$out/fanout-placed.rpt"
set f [open "$out/congestion-placed.rpt" r]; set placed_congestion [read $f]; close $f
set level 0
foreach line [split $placed_congestion \n] {
    if {[regexp {\|\s*(Global|Long|Short)\s*\|\s*([0-9]+)\s*\|} $line unused type value] && $value > $level} {set level $value}
}
set f [open "$out/placement-congestion-level.txt" w];puts $f $level;close $f
# No long routing retry when the new placement has reproduced the failed Level-8 density.
if {$level >= 8} {puts "EC_PHYSICAL_PLACEMENT_STILL_LEVEL8_SKIP_EXPENSIVE_ROUTING"; exit 3}
# Fanout optimization only: avoid repeating the lengthy timing-driven Explore pass.
stage fanout {phys_opt_design -fanout_opt}
write_checkpoint -force "$out/physopt.dcp"
stage routing {route_design -directive AlternateCLBRouting}
write_checkpoint -force "$out/routed.dcp"
report_route_status -file "$out/route-status.rpt"
report_utilization -file "$out/utilization.rpt"
report_timing_summary -report_unconstrained -file "$out/timing.rpt"
report_drc -file "$out/drc.rpt"
report_methodology -file "$out/methodology.rpt"
report_design_analysis -congestion -file "$out/congestion-routed.rpt"
report_bus_skew -file "$out/bus-skew.rpt"
# Never infer legal routing from route_design return code or checkpoint existence.
set f [open "$out/route-status.rpt" r]; set text [read $f]; close $f
set a -1; set b -2
regexp {# of routable nets\.+\s*:\s*(\d+)} $text unused a
regexp {# of fully routed nets\.+\s*:\s*(\d+)} $text unused b
if {$a < 1 || $a != $b} {puts "EC_PHYSICAL_NOT_LEGALLY_ROUTED"; exit 2}
set setup [get_timing_paths -delay_type max -max_paths 1]
set hold [get_timing_paths -delay_type min -max_paths 1]
if {![llength $setup] || ![llength $hold]} {error "missing constrained timing paths"}
if {[get_property SLACK $setup] < 0 || [get_property SLACK $hold] < 0} {
    stage postroute_opt {phys_opt_design -directive AggressiveExplore}
    stage reroute {route_design -directive MoreGlobalIterations}
    write_checkpoint -force "$out/routed-final.dcp"
    report_route_status -file "$out/route-status.rpt"
    report_timing_summary -report_unconstrained -file "$out/timing.rpt"
    report_drc -file "$out/drc.rpt"
    report_methodology -file "$out/methodology.rpt"
    report_bus_skew -file "$out/bus-skew.rpt"
}
puts "EC_PHYSICAL_REPORTS_COMPLETE"
# Strict admission before bit generation, even if a tool command returned success.
report_route_status -file "$out/route-status.rpt"
set f [open "$out/route-status.rpt" r]; set route_text [read $f]; close $f
set total -1; set complete -2
regexp {# of routable nets\.+\s*:\s*(\d+)} $route_text unused total
regexp {# of fully routed nets\.+\s*:\s*(\d+)} $route_text unused complete
if {$total < 1 || $total != $complete} {error "final routing is not legal"}
foreach label {{nets with routing errors} {unrouted nets} {partially routed nets} {nets with resource conflicts}} {
    set count 0
    regexp "# of $label\\.+\\s*:\\s*(\\d+)" $route_text unused count
    if {$count != 0} {error "nonzero $label: $count"}
}
set setup [get_timing_paths -delay_type max -max_paths 1]
set hold [get_timing_paths -delay_type min -max_paths 1]
if {[get_property SLACK $setup] < 0 || [get_property SLACK $hold] < 0} {error "final setup/hold gate failed"}
set f [open "$out/timing.rpt" r]; set timing_text [read $f]; close $f
if {[string first "Timing constraints are not met" $timing_text] >= 0} {error "summary timing gate failed"}
set bad_pulse -1
foreach line [split $timing_text \n] {
    if {[regexp {^\s*([-0-9.]+)\s+([-0-9.]+)\s+\d+\s+\d+\s+([-0-9.]+)\s+([-0-9.]+)\s+\d+\s+\d+\s+([-0-9.]+)\s+([-0-9.]+)\s+} $line unused sw st hw ht pw pt]} {
        set bad_pulse [expr {$pw < 0 || $pt < 0}]; break
    }
}
if {$bad_pulse != 0} {error "pulse-width gate failed or report missing"}
foreach report {drc.rpt methodology.rpt} {
    set f [open "$out/$report" r]; set text [read $f]; close $f
    if {[regexp {\|\s*(Error|Critical Warning)\s*\|} $text]} {error "unresolved critical DRC/methodology in $report"}
}
set f [open "$out/bus-skew.rpt" r]; set skew [read $f]; close $f
if {[regexp -nocase {VIOLATED|constraints are not met} $skew]} {error "bus-skew constraints not met"}
report_clocks -file "$out/final-clocks.rpt"
report_clock_interaction -file "$out/final-clock-interaction.rpt"
check_timing -override_defaults {no_clock unconstrained_internal_endpoints generated_clocks loops} -file "$out/check-timing.rpt"
set f [open "$out/check-timing.rpt" r]; set coverage [read $f]; close $f
if {[regexp {checking [a-z_]+ \([1-9][0-9]*\)} $coverage]} {error "clock coverage, generated clock or loop gate failed"}
write_checkpoint -force "$out/certification-input.dcp"
stage bitstream {write_bitstream -force "$out/firesim.bit"}
puts "EC_PHYSICAL_BITSTREAM_GENERATED_NOT_RUNTIME_CERTIFIED"
exit 0
'''.replace('@CHECKPOINT@', checkpoint).replace('@DIRECTIVE@', directive).replace('@CLOCK_CONTRACT@', str(C/'clock-contract.tcl'))


def main():
    with (O/'campaign.lock').open('a') as lock:
        fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
        os.sched_setaffinity(0, set(range(240, 248)))
        update('WAITING_EXISTING_CHECKPOINT_AUDIT')
        audit = O/'audit'
        required = ['congestion.rpt', 'per-slr.rpt', 'route-status.rpt', 'high-fanout.rpt']
        while True:
            log = audit/'audit.vivado.log'
            core_ready = (all((audit/n).is_file() and (audit/n).stat().st_size for n in required)
                          and log.is_file() and 'EC_AUDIT_REPORT_DONE fanout ' in log.read_text(errors='replace'))
            if core_ready:
                break
            # The measured CLB/MUXF packing result already justifies the first transform.
            # Keep the detailed congestion/QoR query running independently.
            if ((O/'first-physical-decision.json').is_file()
                and all((audit/n).is_file() and (audit/n).stat().st_size for n in ['per-slr.rpt','route-status.rpt'])):
                break
            status = subprocess.check_output(['systemctl', '--user', 'show', AUDIT_UNIT,
                                             '-p', 'ActiveState', '--value'], text=True).strip()
            if status not in ['active', 'activating']:
                break
            update('WAITING_EXISTING_CHECKPOINT_AUDIT')
            time.sleep(30)
        minimum = ['per-slr.rpt','route-status.rpt'] if (O/'first-physical-decision.json').is_file() else required
        missing = [n for n in minimum if not (audit/n).is_file() or not (audit/n).stat().st_size]
        if missing:
            update('AUDIT_INCOMPLETE_NEEDS_REPAIR', missing_reports=missing)
            return
        observed = route_metrics(audit/'route-status.rpt')
        save(O/'baseline-routing.json', observed)
        cp = INPUT['checkpoints']['design_1_wrapper_placed.dcp']
        assert digest(cp['path']) == cp['sha256']
        # First reduce local density; if it is insufficient, change SLR partitioning.
        choices = [('muxf-remap-spread-r1', 'AltSpreadLogic_high'),
                   ('muxf-remap-sll-r2', 'SSI_SpreadSLLs')]
        for name, directive in choices:
            decision = dict(utc=now(), candidate=name, placement=directive,
                            route='AlternateCLBRouting', source_checkpoint=cp,
                            netlist_transform='opt_design -muxf_remap, equivalent MUXF to LUT decomposition',
                            reason='All three SLRs have 99.82/99.93/100% CLB site occupancy; SLR2 has 65300 F7 and 25770 F8 muxes; trade spare LUT capacity for packing and routing freedom',
                            constraints='repair only the exact original Golden Gate generated clocks and 1/0,2/1 multicycle constraints at real linked-shell paths; no frequency or RTL change')
            save(O/(name+'-decision.json'), decision)
            result = run(name, physical_code(cp['path'], directive))
            routing = result.get('routing', {})
            if routing.get('legal') and result['bitstream_generated']:
                update('BITSTREAM_GENERATED_RUNTIME_CERTIFICATION_PENDING', best_candidate=name,
                       next_action='Bind exact physical receipt and unchanged 6fada307 host ABI; certify using only existing card21 ownership procedure before FPGA execution')
                return
        legal = [r for r in ST['candidates'] if r.get('routing', {}).get('legal')]
        update('LEGAL_ROUTING_TIMING_OR_CONSTRAINT_RECOVERY_REQUIRED' if legal else 'PHYSICAL_SCREEN_COMPLETE_RTL_RESTRUCTURING_REQUIRED',
               next_action='Use measured region and crossing reports to bank/relocate data CDC access; retain checker, storage, release and backpressure')


if __name__ == '__main__':
    try:
        main()
    except Exception as e:
        update('FAILED_WITH_EVIDENCE', error=repr(e), ended_utc=now())
        raise
