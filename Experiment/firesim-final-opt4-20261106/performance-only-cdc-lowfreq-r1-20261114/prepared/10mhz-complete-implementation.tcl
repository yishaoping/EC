
set_param general.maxThreads 8
set out {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/performance-only-cdc-lowfreq-r1-20261114/prepared/10}
proc stage {name script} {
    global out
    set f [open "$out/current-stage.txt" w]; puts $f $name; close $f
    puts "EC_PHYSICAL_STAGE $name"
    uplevel 1 $script
}
stage open {open_checkpoint {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/performance-only-memory-cdc-r2-20261114/complete-shell-r3/shell-postopt.dcp}}
if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "unresolved functional cells"}
write_xdc -force "$out/input-effective.xdc"
set ec_frequency 10
stage clock_contract {source {/data1/gzh/EC/firesim/final-opt4-20261106/candidates/performance-only-cdc-lowfreq-r1-20261114/host-clock.tcl}}
write_xdc -force "$out/repaired-effective.xdc"
puts "EC_INPUT_IS_FRESH_MEM_POSTOPT_NO_UNROUTE"
puts "EC_INPUT_IS_FRESH_MEM_POSTOPT_NO_UNPLACE"
# The original has CLB site occupancy 99.82/99.93/100% despite only 78% LUTs.
# MUXF remapping is an equivalent primitive transform; preserve its checkpoint.
puts "EC_MEM_NO_GLOBAL_MUXF_REMAP"
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
stage spread {place_design -directive SSI_SpreadSLLs}
write_checkpoint -force "$out/placed.dcp"
report_utilization -slr -file "$out/per-slr-placed.rpt"
report_timing_summary -file "$out/timing-placed.rpt"
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

set candidates [get_nets -hier -quiet -filter {NAME =~ *packet_alloc_valid* || NAME =~ *ghm_u_data_cdc*source_valid*}]
set ranked {}
foreach n $candidates {
    set loads [get_pins -leaf -quiet -of_objects $n -filter {DIRECTION == IN}]
    if {[llength $loads] < 1024} {continue}
    set drivers [get_cells -quiet -of_objects [get_pins -leaf -quiet -of_objects $n -filter {DIRECTION == OUT}]]
    if {[llength $drivers] != 1} {continue}
    set driver [lindex $drivers 0]
    if {[regexp {^(BUFG|BUFH|MMCME|PLLE)} [get_property REF_NAME $driver]]} {continue}
    if {[string tolower [get_property -quiet ASYNC_REG $driver]] in {true 1}} {continue}
    lappend ranked [list [llength $loads] $n]
}
set ranked [lrange [lsort -integer -decreasing -index 0 $ranked] 0 15]
set f [open "$out/targeted-fanout-inputs.txt" w]
set hot_nets {}
foreach pair $ranked {
    set n [lindex $pair 1]
    puts $f "loads=[lindex $pair 0] net=$n"
    lappend hot_nets $n
}
close $f
if {[llength $hot_nets]} {
    if {[catch {stage targeted_fanout {phys_opt_design -force_replication_on_nets $hot_nets}} message options]} {
        set f [open "$out/targeted-fanout-command-error.txt" w];puts $f $message;close $f
        puts "EC_TARGETED_REPLICATION_DECLINED $message"
    }
}
stage fanout {phys_opt_design -fanout_opt -slr_crossing_opt}
report_high_fanout_nets -slr -max_nets 40 -file "$out/fanout-after-physopt.rpt"
report_design_analysis -congestion -file "$out/congestion-after-physopt.rpt"

write_checkpoint -force "$out/physopt.dcp"
if {[catch {stage routing {route_design -directive AlternateCLBRouting}} message options]} {
    set f [open "$out/routing-command-error.txt" w];puts $f $message;close $f
    puts "EC_ROUTE_COMMAND_ERROR_EVIDENCE_RETAINED $message"
}
write_checkpoint -force "$out/routed.dcp"
report_route_status -file "$out/route-status.rpt"
report_utilization -file "$out/utilization.rpt"
report_utilization -slr -file "$out/per-slr-routed.rpt"
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
    if {[catch {stage reroute {route_design -directive MoreGlobalIterations}} message options]} {
    set f [open "$out/reroute-command-error.txt" w];puts $f $message;close $f
    puts "EC_ROUTE_COMMAND_ERROR_EVIDENCE_RETAINED $message"
}
    write_checkpoint -force "$out/routed-final.dcp"
    report_route_status -file "$out/route-status.rpt"
    report_timing_summary -report_unconstrained -file "$out/timing.rpt"
    report_drc -file "$out/drc.rpt"
    report_methodology -file "$out/methodology.rpt"
    report_bus_skew -file "$out/bus-skew.rpt"
}

report_utilization -file "$out/utilization.rpt"
report_utilization -slr -file "$out/per-slr-routed.rpt"
report_utilization -slr -file "$out/per-slr-final.rpt"
report_high_fanout_nets -slr -max_nets 40 -file "$out/fanout-final.rpt"
report_timing -delay_type max -max_paths 20 -file "$out/setup-critical-paths.rpt"
report_timing -delay_type min -max_paths 20 -file "$out/hold-critical-paths.rpt"
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
