set_param general.maxThreads 8
set out [lindex $argv 0]
set checkpoint [lindex $argv 1]
file mkdir $out
proc attempt {name code} {
    global out
    puts "EC_AUDIT_BEGIN $name"
    set start [clock seconds]
    if {[catch {uplevel 1 $code} message options]} {
        set f [open "$out/$name.error.txt" w]
        puts $f $message
        if {[dict exists $options -errorinfo]} {puts $f [dict get $options -errorinfo]}
        close $f
        puts "EC_AUDIT_REPORT_ERROR $name $message"
    } else {
        puts "EC_AUDIT_REPORT_DONE $name seconds=[expr {[clock seconds]-$start}]"
    }
}
foreach command {report_design_analysis report_utilization report_high_fanout_nets report_qor_suggestions place_design phys_opt_design route_design get_tiles get_sites get_slrs report_route_status report_timing write_xdc} {
    attempt "help-$command" {redirect -file "$out/help-$command.txt" [list help $command]}
}
open_checkpoint $checkpoint
attempt route-status {report_route_status -file "$out/route-status.rpt"}
attempt utilization {report_utilization -file "$out/utilization.rpt"}
attempt per-slr {report_utilization -slr -file "$out/per-slr.rpt"}
attempt congestion {report_design_analysis -congestion -file "$out/congestion.rpt"}
attempt complexity {report_design_analysis -complexity -file "$out/complexity.rpt"}
attempt fanout {report_high_fanout_nets -timing -load_types -max_nets 100 -file "$out/high-fanout.rpt"}
attempt timing {report_timing -max_paths 30 -nworst 3 -input_pins -nets -transition_time -capacitance -file "$out/critical-paths.rpt"}
attempt clocks {report_clocks -file "$out/clocks.rpt"}
attempt clock-interaction {report_clock_interaction -file "$out/clock-interaction.rpt"}
attempt exceptions {report_exceptions -summary -file "$out/exceptions.rpt"}
attempt constraints {write_xdc -force "$out/effective.xdc"}
attempt qos {report_qor_suggestions -file "$out/qor-suggestions.rpt"}
attempt properties {
    set f [open "$out/physical-constraints.txt" w]
    foreach pb [get_pblocks -quiet] {
        puts $f "PBLOCK $pb"
        puts $f [report_property -return_string $pb]
        puts $f "CELLS [get_cells -quiet -of_objects $pb]"
    }
    foreach slr [get_slrs] {puts $f "SLR $slr [get_property SLR_INDEX $slr]"}
    foreach pattern {*clockBridge*buffer* *firesim_wrapper_0 *tile_reset_domain* *ghm_u_data_cdc*} {
        foreach c [get_cells -hier -quiet -filter "NAME =~ $pattern && IS_PRIMITIVE == 0"] {
            puts $f "HIER $c"
        }
    }
    foreach c [get_cells -hier -quiet -filter {IS_LOC_FIXED == 1 || IS_BEL_FIXED == 1}] {
        puts $f "FIXED $c [get_property LOC $c] [get_property BEL $c]"
    }
    close $f
}
puts "EC_AUDIT_COMPLETE"
exit 0
