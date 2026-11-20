# Runs only in the already scheduled 10 MHz attempt, after real clock replay.
# The current 15 MHz process never sources this file.
proc ec_try_route {name directive} {
    global out
    if {[catch {stage $name [list route_design -directive $directive -tns_cleanup]} message]} {
        set f [open "$out/$name-command-error.txt" w]; puts $f $message; close $f
        puts "EC_ROUTE_COMMAND_ERROR_EVIDENCE_RETAINED $message"
    }
}
proc ec_route_legal {} {
    global out
    report_route_status -file "$out/route-status.rpt"
    set f [open "$out/route-status.rpt" r]; set text [read $f]; close $f
    set total -1; set complete -2
    regexp {# of routable nets\.+\s*:\s*(\d+)} $text unused total
    regexp {# of fully routed nets\.+\s*:\s*(\d+)} $text unused complete
    if {$total < 1 || $total != $complete} {return 0}
    foreach label {{nets with routing errors} {unrouted nets} {partially routed nets} {nets with resource conflicts}} {
        set count 0
        regexp "# of $label\\.+\\s*:\\s*(\\d+)" $text unused count
        if {$count != 0} {return 0}
    }
    return 1
}
proc ec_slacks {} {
    set setup [get_timing_paths -delay_type max -max_paths 1]
    set hold [get_timing_paths -delay_type min -max_paths 1]
    if {![llength $setup] || ![llength $hold]} {error "missing constrained setup/hold paths"}
    return [list [get_property SLACK $setup] [get_property SLACK $hold]]
}
puts "EC_10MHZ_RECOVERY_REUSES_MEASURED_PLACEMENT_AND_ROUTING"
if {[file tail $ec_resume_checkpoint] eq "placed.dcp"} {
    # The preceding physical optimization did not produce a usable checkpoint.
    stage local_physical_repair {phys_opt_design -fanout_opt -placement_opt -slr_crossing_opt}
}
ec_try_route routing MoreGlobalIterations
write_checkpoint -force "$out/routed.dcp"
set legal [ec_route_legal]
if {$legal} {
    set slack [ec_slacks]
    if {[lindex $slack 0] < 0 || [lindex $slack 1] < 0} {
        # Unlike AggressiveExplore, this documented directive explicitly
        # repairs hold by inserting data-path delay, retaining real constraints.
        stage postroute_hold_setup {phys_opt_design -directive ExploreWithHoldFix}
        ec_try_route reroute Explore
        write_checkpoint -force "$out/routed-final.dcp"
        set legal [ec_route_legal]
    }
    if {$legal} {
        set slack [ec_slacks]
        if {[lindex $slack 1] < 0} {
            stage postroute_remaining_hold {phys_opt_design -aggressive_hold_fix}
            ec_try_route hold_reroute Explore
            write_checkpoint -force "$out/routed-final.dcp"
        }
    }
}
# Necessary final evidence only; no high-fanout/QoR report before routing.
report_route_status -file "$out/route-status.rpt"
report_utilization -file "$out/utilization.rpt"
report_utilization -slr -file "$out/per-slr-final.rpt"
report_timing_summary -report_unconstrained -file "$out/timing.rpt"
report_drc -file "$out/drc.rpt"
report_methodology -file "$out/methodology.rpt"
report_bus_skew -file "$out/bus-skew.rpt"
# Byte-preserved gate block from the running attempt: legal route, setup/hold,
# pulse width, DRC/methodology, skew and clock coverage precede write_bitstream.
source {/data1/gzh/EC/firesim/final-opt4-20261106/candidates/performance-only-cdc-lowfreq-r1-20261114/final-bitstream-gates.tcl}
