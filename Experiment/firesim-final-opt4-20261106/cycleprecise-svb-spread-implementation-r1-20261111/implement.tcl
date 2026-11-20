set_param general.maxThreads 2
puts "EC_SVB_SPREAD_PLACE_DIRECTIVE_HELP"
place_design -help
open_checkpoint {/data1/gzh/EC/firesim/final-opt4-20261106/routes/svb-spread-implementation-r1-20261111/snapshot-opt.dcp}
if {[get_property PART [current_design]] ne "xcu280-fsvh2892-2L-e"} {error "wrong device"}
set unresolved {}
foreach c [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}] {
  if {$c eq "dbg_hub" && [get_property REF_NAME $c] eq "dbg_hub_CV" && [get_property IS_DEBUG_CORE $c]} {continue}
  lappend unresolved $c
}
if {[llength $unresolved]} {error "unresolved functional IP: $unresolved"}
implement_debug_core
if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "unresolved debug core"}
place_design -directive AltSpreadLogic_high
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-spread-implementation-r1-20261111/spread-placed.dcp}
report_design_analysis -congestion -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-spread-implementation-r1-20261111/congestion-placed.rpt}
report_timing_summary -report_unconstrained -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-spread-implementation-r1-20261111/timing-placed.rpt}
puts "EC_SVB_SPREAD_PLACED_/data1/gzh/EC/firesim/final-opt4-20261106/routes/svb-spread-implementation-r1-20261111/snapshot-opt.dcp_COMPLETE"
phys_opt_design -directive AggressiveFanoutOpt
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-spread-implementation-r1-20261111/spread-physopt.dcp}
report_high_fanout_nets -max_nets 40 -timing -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-spread-implementation-r1-20261111/high-fanout.rpt}
report_design_analysis -congestion -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-spread-implementation-r1-20261111/congestion-physopt.rpt}
puts "EC_SVB_SPREAD_PHYSOPT_/data1/gzh/EC/firesim/final-opt4-20261106/routes/svb-spread-implementation-r1-20261111/snapshot-opt.dcp_COMPLETE"
route_design -directive Explore
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-spread-implementation-r1-20261111/spread-routed.dcp}
report_route_status -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-spread-implementation-r1-20261111/route-status.rpt}
report_timing_summary -report_unconstrained -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-spread-implementation-r1-20261111/timing-routed.rpt}
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-spread-implementation-r1-20261111/utilization-routed.rpt}
report_drc -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-spread-implementation-r1-20261111/drc-routed.rpt}
report_clocks -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-spread-implementation-r1-20261111/physical-clocks.rpt}
check_timing -verbose -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-spread-implementation-r1-20261111/check-timing.rpt}
set pins [get_pins -hier -filter {NAME =~ *RationalClockBridge_clocks_0_buffer/O}]
if {[llength $pins] != 1} {error "target buffer absent/ambiguous"}
set clks [get_clocks -of_objects $pins]
if {[llength $clks] != 1} {error "target timing clock absent/ambiguous"}
set period [get_property PERIOD $clks]
set regs [all_registers -clock $clks]
if {$period <= 0 || $period > 20.01 || [llength $regs] < 1000} {error "target clock relaxed or absent"}
set setup [get_timing_paths -delay_type max -max_paths 1]
set hold [get_timing_paths -delay_type min -max_paths 1]
if {![llength $setup] || ![llength $hold]} {error "missing timing paths"}
set wns [get_property SLACK $setup]; set whs [get_property SLACK $hold]
puts "EC_SVB_SPREAD_TIMING period=$period registers=[llength $regs] WNS=$wns WHS=$whs"
if {$wns < 0 || $whs < 0} {error "setup/hold timing gate failed; preserve routed DCP"}
write_bitstream -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-spread-implementation-r1-20261111/original-svb-spread.bit}
puts "EC_SVB_SPREAD_BITSTREAM_COMPLETE"
exit 0
