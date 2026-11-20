set_param general.maxThreads 2
open_checkpoint {/UNEXECUTED/sealed.dcp}
if {[get_property PART [current_design]] ne "xcu280-fsvh2892-2L-e"} {error "wrong device"}
if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "unresolved IP"}

proc target_clock {} {
  set pins [get_pins -hier -filter {NAME =~ *RationalClockBridge_clocks_0_buffer/O}]
  if {[llength $pins] != 1} {error "target buffer absent/ambiguous"}
  set clocks [get_clocks -of_objects $pins]
  if {[llength $clocks] != 1} {error "target clock absent/ambiguous"}
  set period [get_property PERIOD $clocks]
  set registers [llength [all_registers -clock $clocks]]
  if {abs($period - 19.998) > 0.001 || $registers < 1000} {error "clock constraint changed"}
  puts "EC_SVB_RECOVERY_CLOCK period=$period registers=$registers"
  return $period
}

proc slacks {} {
  set setup [get_timing_paths -delay_type max -max_paths 1]
  set hold [get_timing_paths -delay_type min -max_paths 1]
  if {![llength $setup] || ![llength $hold]} {error "missing timing paths"}
  return [list [get_property SLACK $setup] [get_property SLACK $hold]]
}

proc saved_reports {tag} {
  write_checkpoint -force "/UNEXECUTED/output/$tag.dcp"
  report_route_status -file "/UNEXECUTED/output/$tag-route.rpt"
  report_timing_summary -report_unconstrained -file "/UNEXECUTED/output/$tag-timing.rpt"
  report_timing -delay_type min -max_paths 20 -nets -file "/UNEXECUTED/output/$tag-hold.rpt"
  report_timing -delay_type max -max_paths 20 -nets -file "/UNEXECUTED/output/$tag-setup.rpt"
  report_high_fanout_nets -max_nets 40 -timing -file "/UNEXECUTED/output/$tag-fanout.rpt"
  report_drc -file "/UNEXECUTED/output/$tag-drc.rpt"
  set values [slacks]
  puts "EC_SVB_RECOVERY_CHECKPOINT tag=$tag WNS=[lindex $values 0] WHS=[lindex $values 1]"
}

# Only inserted for an exited failed producer's sealed physopt checkpoint.
# This is physical driver replication, not a change to target RTL/state/cycles.
target_clock
set active_nets [get_nets -hier -quiet -filter {NAME =~ *SVBProbe_/dut/activeIdx_reg*}]
if {[llength $active_nets] != 2} {error "expected the exact two activeIdx nets"}
set fp [open {/UNEXECUTED/output/forced-replication-before.tsv} w]
foreach n $active_nets {
  set drivers [get_pins -leaf -of_objects $n -filter {DIRECTION == OUT}]
  set loads [get_pins -leaf -of_objects $n -filter {DIRECTION == IN}]
  if {[llength $drivers] != 1 || [llength $loads] < 1000} {error "unexpected activeIdx driver/fanout"}
  set cells [get_cells -of_objects $drivers]
  if {[llength $cells] != 1 || ![string match FD* [get_property REF_NAME $cells]]} {error "not an original sequential activeIdx driver"}
  puts $fp "$n\t[get_property REF_NAME $cells]\t[llength $loads]"
}
close $fp
report_high_fanout_nets -max_nets 40 -timing -file {/UNEXECUTED/output/fanout-before-forced-replication.rpt}
# Tool help confirms this forces replication even when timing slack is positive.
# Do not use retime, insert_negative_edge_ffs, or target clock changes.
phys_opt_design -force_replication_on_nets $active_nets
write_checkpoint -force {/UNEXECUTED/output/forced-replicated.dcp}
report_high_fanout_nets -max_nets 100 -timing -file {/UNEXECUTED/output/fanout-after-forced-replication.rpt}
report_design_analysis -congestion -file {/UNEXECUTED/output/congestion-after-forced-replication.rpt}
report_utilization -file {/UNEXECUTED/output/utilization-after-forced-replication.rpt}
puts "EC_SVB_ACTIVEIDX_FORCED_REPLICATION_COMPLETE nets=[llength $active_nets]"
route_design -directive Explore -tns_cleanup
saved_reports forced-replication-routed

target_clock
saved_reports initial
set values [slacks]
if {[lindex $values 0] < 0 || [lindex $values 1] < 0} {
  # Vivado 2021.1 help confirms this directive covers setup and aggressive
  # hold repair; it does not request retiming or negative-edge FF insertion.
  phys_opt_design -directive ExploreWithAggressiveHoldFix
  saved_reports physical-1
  # Retain legal unchanged routing while routing the physical ECOs.
  route_design -preserve -directive Explore -tns_cleanup
  saved_reports routed-1
}
set values [slacks]
if {[lindex $values 0] < 0 || [lindex $values 1] < 0} {
  # One bounded second attempt. No repeated unbounded routing or resynthesis.
  phys_opt_design -directive AggressiveExplore
  set values [slacks]
  if {[lindex $values 1] < 0} {phys_opt_design -aggressive_hold_fix}
  saved_reports physical-2
  route_design -directive Explore -tns_cleanup
  saved_reports routed-2
}
target_clock
saved_reports final
report_utilization -file {/UNEXECUTED/output/utilization-final.rpt}
report_clocks -file {/UNEXECUTED/output/physical-clocks.rpt}
check_timing -verbose -file {/UNEXECUTED/output/check-timing.rpt}
set values [slacks]
if {[lindex $values 0] < 0 || [lindex $values 1] < 0} {error "setup/hold gate failed; all checkpoints preserved"}
set badroutes [get_nets -hier -quiet -filter {ROUTE_STATUS == UNROUTED || ROUTE_STATUS == PARTIAL || ROUTE_STATUS == CONFLICTS}]
if {[llength $badroutes]} {error "unrouted/partial/conflicting nets"}
set errors [get_drc_violations -quiet -filter {SEVERITY == Error}]
if {[llength $errors]} {error "DRC errors $errors"}
set fp [open {/UNEXECUTED/output/check-timing.rpt} r]
set checks [read $fp]
close $fp
if {![regexp {checking no_clock \(0\)} $checks] || ![regexp {checking unconstrained_internal_endpoints \(0\)} $checks]} {error "clock coverage gate failed"}
set pulse [report_pulse_width -return_string -all_violators]
set fp [open {/UNEXECUTED/output/pulse-width-violators.rpt} w]
puts $fp $pulse
close $fp
if {[regexp -nocase {VIOLATED} $pulse] || [regexp {(^|[[:space:]])-[0-9]+\.[0-9]+([[:space:]]|$)} $pulse]} {error "pulse width timing gate failed"}
write_bitstream -force {/UNEXECUTED/output/original-svb-recovered.bit}
puts "EC_SVB_RECOVERY_BITSTREAM_COMPLETE WNS=[lindex $values 0] WHS=[lindex $values 1]"
exit 0
