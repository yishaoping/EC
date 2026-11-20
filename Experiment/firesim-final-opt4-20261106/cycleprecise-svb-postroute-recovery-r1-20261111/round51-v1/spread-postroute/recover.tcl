set_param general.maxThreads 2
open_checkpoint {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/round51-v1/spread-postroute/sealed-routed.dcp}
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
  write_checkpoint -force "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/round51-v1/spread-postroute/$tag.dcp"
  report_route_status -file "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/round51-v1/spread-postroute/$tag-route.rpt"
  report_timing_summary -report_unconstrained -file "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/round51-v1/spread-postroute/$tag-timing.rpt"
  report_timing -delay_type min -max_paths 20 -nets -file "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/round51-v1/spread-postroute/$tag-hold.rpt"
  report_timing -delay_type max -max_paths 20 -nets -file "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/round51-v1/spread-postroute/$tag-setup.rpt"
  report_high_fanout_nets -max_nets 40 -timing -file "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/round51-v1/spread-postroute/$tag-fanout.rpt"
  report_drc -file "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/round51-v1/spread-postroute/$tag-drc.rpt"
  set values [slacks]
  puts "EC_SVB_RECOVERY_CHECKPOINT tag=$tag WNS=[lindex $values 0] WHS=[lindex $values 1]"
}

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
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/round51-v1/spread-postroute/utilization-final.rpt}
report_clocks -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/round51-v1/spread-postroute/physical-clocks.rpt}
check_timing -verbose -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/round51-v1/spread-postroute/check-timing.rpt}
set values [slacks]
if {[lindex $values 0] < 0 || [lindex $values 1] < 0} {error "setup/hold gate failed; all checkpoints preserved"}
set badroutes [get_nets -hier -quiet -filter {ROUTE_STATUS == UNROUTED || ROUTE_STATUS == PARTIAL || ROUTE_STATUS == CONFLICTS}]
if {[llength $badroutes]} {error "unrouted/partial/conflicting nets"}
set errors [get_drc_violations -quiet -filter {SEVERITY == Error}]
if {[llength $errors]} {error "DRC errors $errors"}
set fp [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/round51-v1/spread-postroute/check-timing.rpt} r]
set checks [read $fp]
close $fp
if {![regexp {checking no_clock \(0\)} $checks] || ![regexp {checking unconstrained_internal_endpoints \(0\)} $checks]} {error "clock coverage gate failed"}
set pulse [report_pulse_width -return_string -all_violators]
set fp [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/round51-v1/spread-postroute/pulse-width-violators.rpt} w]
puts $fp $pulse
close $fp
if {[regexp -nocase {VIOLATED} $pulse] || [regexp {(^|[[:space:]])-[0-9]+\.[0-9]+([[:space:]]|$)} $pulse]} {error "pulse width timing gate failed"}
write_bitstream -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/round51-v1/spread-postroute/original-svb-recovered.bit}
puts "EC_SVB_RECOVERY_BITSTREAM_COMPLETE WNS=[lindex $values 0] WHS=[lindex $values 1]"
exit 0
