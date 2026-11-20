# Read an archived, legally placed checkpoint. Reporting only: no optimization,
# placement, routing, netlist edits, activity override, or checkpoint write.
set root [file normalize [file join [file dirname [info script]] ..]]
set out [file join $root generated placed]
file mkdir $out
set_param general.maxThreads 2
open_checkpoint [file join $root checkpoints design_1_wrapper_placed.dcp]
set f [open [file join $out context.txt] w]
puts $f "Tool: [version -short]"
puts $f "Part: [get_property PART [current_design]]"
puts $f "Checkpoint stage: R6 placed, before physical optimization and routing"
puts $f "Activity: checkpoint defaults, no SAIF/VCD imported by this script"
foreach p [list_property [current_design]] {
    if {[regexp -nocase {power|toggle|probability|state|route|place} $p]} {
        puts $f "$p: [get_property $p [current_design]]"
    }
}
close $f
report_clocks -file [file join $out clocks.rpt]
report_utilization -file [file join $out utilization.rpt]
report_utilization -hierarchical -hierarchical_depth 30 -file [file join $out hierarchical.rpt]
report_power -hier all -file [file join $out power_vectorless.rpt]
if {[catch {report_switching_activity -file [file join $out switching_activity.rpt]} e]} {
    set f [open [file join $out switching_activity_error.txt] w]; puts $f $e; close $f
}
report_power -advisory -file [file join $out power_advisory.rpt]
set f [open [file join $out reporting.complete] w]; puts $f "REPORTING_ONLY_COMPLETE"; close $f
close_design
exit
