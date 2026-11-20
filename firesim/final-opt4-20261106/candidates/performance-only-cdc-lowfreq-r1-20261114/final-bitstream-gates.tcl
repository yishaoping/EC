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
