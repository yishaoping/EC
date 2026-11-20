set_param general.maxThreads 2
open_checkpoint {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/sealed-physopt.dcp}
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
  write_checkpoint -force "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/$tag.dcp"
  report_route_status -file "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/$tag-route.rpt"
  report_timing_summary -report_unconstrained -file "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/$tag-timing.rpt"
  report_timing -delay_type min -max_paths 20 -nets -file "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/$tag-hold.rpt"
  report_timing -delay_type max -max_paths 20 -nets -file "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/$tag-setup.rpt"
  report_high_fanout_nets -max_nets 40 -timing -file "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/$tag-fanout.rpt"
  report_drc -file "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/$tag-drc.rpt"
  set values [slacks]
  puts "EC_SVB_RECOVERY_CHECKPOINT tag=$tag WNS=[lindex $values 0] WHS=[lindex $values 1]"
}

target_clock
# Physical-only query of the two original sequential activeIdx Q drivers.
# Exact NAME equality deliberately avoids glob interpretation of [0]/[1].
proc original_activeidx_nets {out} {
  set cells [get_cells -hier -quiet -filter {NAME == design_1_i/firesim_wrapper_0/inst/firesim_top/top/model/sim/target/SVBProbe_/dut/activeIdx_reg[0] || NAME == design_1_i/firesim_wrapper_0/inst/firesim_top/top/model/sim/target/SVBProbe_/dut/activeIdx_reg[1]}]
  if {[llength $cells] != 2} {error "expected exactly two original activeIdx FD cells; got [llength $cells]"}
  set result {}
  set fp [open $out w]
  puts $fp "cell\tref\tq_pin\tnet\tfanout"
  foreach c [lsort $cells] {
    set ref [get_property REF_NAME $c]
    if {$ref ni {FDRE FDSE}} {error "activeIdx has unexpected sequential primitive $ref"}
    set q [get_pins -quiet -of_objects $c -filter {REF_PIN_NAME == Q}]
    if {[llength $q] != 1} {error "activeIdx Q pin ambiguous"}
    set net [get_nets -quiet -of_objects $q]
    if {[llength $net] != 1} {error "activeIdx Q net ambiguous"}
    set drivers [get_pins -leaf -of_objects $net -filter {DIRECTION == OUT}]
    set loads [get_pins -leaf -of_objects $net -filter {DIRECTION == IN}]
    if {[llength $drivers] != 1 || [lindex $drivers 0] ne [lindex $q 0]} {error "activeIdx net driver mismatch"}
    if {[llength $loads] < 1000} {error "activeIdx Q net unexpected fanout [llength $loads]"}
    puts $fp "$c\t$ref\t$q\t$net\t[llength $loads]"
    puts "EC_ACTIVEIDX_PINQUERY cell=$c ref=$ref net=$net fanout=[llength $loads]"
    lappend result [lindex $net 0]
  }
  close $fp
  if {[llength [lsort -unique $result]] != 2} {error "activeIdx Q nets were not distinct"}
  return $result
}

set active_nets [original_activeidx_nets {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/forced-replication-before.tsv}]
report_high_fanout_nets -max_nets 40 -timing -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/fanout-before-forced-replication.rpt}
phys_opt_design -force_replication_on_nets $active_nets
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/forced-replicated.dcp}
report_high_fanout_nets -max_nets 100 -timing -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/fanout-after-forced-replication.rpt}
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/utilization-after-forced-replication.rpt}
puts "EC_SVB_EXACT_ACTIVEIDX_FORCED_REPLICATION_COMPLETE nets=[llength $active_nets]"
route_design -directive Explore -tns_cleanup
saved_reports forced-replication-routed

saved_reports initial
set values [slacks]
if {[lindex $values 0] < 0 || [lindex $values 1] < 0} {
  # Vivado 2021.1 help confirms this directive covers setup and aggressive
  # hold repair; it does not request retiming or negative-edge FF insertion.
  phys_opt_design -directive ExploreWithAggressiveHoldFix
  saved_reports physical-1
  # Retain legal unchanged routing while routing the physical ECOs.
  route_design -directive Explore -tns_cleanup
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
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/utilization-final.rpt}
report_clocks -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/physical-clocks.rpt}
check_timing -verbose -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/check-timing.rpt}
set values [slacks]
if {[lindex $values 0] < 0 || [lindex $values 1] < 0} {error "setup/hold gate failed; all checkpoints preserved"}
set badroutes [get_nets -hier -quiet -filter {ROUTE_STATUS == UNROUTED || ROUTE_STATUS == PARTIAL || ROUTE_STATUS == CONFLICTS}]
if {[llength $badroutes]} {error "unrouted/partial/conflicting nets"}
set errors [get_drc_violations -quiet -filter {SEVERITY == Error}]
if {[llength $errors]} {error "DRC errors $errors"}
set fp [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/check-timing.rpt} r]
set checks [read $fp]
close $fp
if {![regexp {checking no_clock \(0\)} $checks] || ![regexp {checking unconstrained_internal_endpoints \(0\)} $checks]} {error "clock coverage gate failed"}
set pulse [report_pulse_width -return_string -all_violators]
set fp [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/pulse-width-violators.rpt} w]
puts $fp $pulse
close $fp
if {[regexp -nocase {VIOLATED} $pulse] || [regexp {(^|[[:space:]])-[0-9]+\.[0-9]+([[:space:]]|$)} $pulse]} {error "pulse width timing gate failed"}
set bus_skew [report_bus_skew -return_string -no_detailed_paths -warn_on_violation]
set fp [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/bus-skew-final.rpt} w]; puts $fp $bus_skew; close $fp
if {[regexp -nocase {VIOLATED} $bus_skew]} {error "bus skew timing gate failed"}
write_bitstream -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/pinreplicate-r4-spread-physopt/original-svb-recovered.bit}
puts "EC_SVB_RECOVERY_BITSTREAM_COMPLETE WNS=[lindex $values 0] WHS=[lindex $values 1]"
exit 0
