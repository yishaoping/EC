open_checkpoint {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/routed.dcp}

set hp [get_pins -hier -quiet -filter {NAME =~ */clk_wiz_0/inst/clkout1_buf/O}]
if {[llength $hp]!=1} {error "physical host BUFG output not unique"}
set physical [get_clocks -quiet -of_objects $hp]
set native [get_clocks -quiet clk_out1_design_1_clk_wiz_0_0]
if {[llength $physical]!=1 || [llength $native]!=1 || $physical ne $native} {
 error "actual physical clock differs from pinned shell evidence: physical=$physical native=$native"
}

foreach name {buildtop_reference_clock tileClockGroup_tile_1} {
 set c [get_clocks -quiet $name]
 if {[llength $c]!=1 || [get_property MASTER_CLOCK $c] ne "clk_out1_design_1_clk_wiz_0_0"} {
  error "generated target clock has wrong physical master: $name"
 }
}

set host [get_clocks -quiet clk_out1_design_1_clk_wiz_0_0]
if {[llength $host] != 1} {error "missing exact host clock"}
set host_period [get_property PERIOD $host]
foreach name {buildtop_reference_clock tileClockGroup_tile_1} scale {1 1} {
 set c [get_clocks -quiet $name]
 if {[llength $c] != 1} {error "missing exact target clock $name"}
 set period [get_property PERIOD $c]
 if {abs($period-$host_period*$scale)>0.001} {error "target clock ratio changed: $name $period $host_period $scale"}
 if {[llength [all_registers -clock $c]] < 1} {error "target clock has no registers: $name"}
}
report_route_status -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/final-route-status.rpt}
report_clocks -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/final-clocks.rpt}
check_timing -verbose -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/final-check-timing.rpt}
set badroutes [get_nets -hier -quiet -filter {ROUTE_STATUS == UNROUTED || ROUTE_STATUS == PARTIAL || ROUTE_STATUS == CONFLICTS}]
if {[llength $badroutes]} {error "unrouted/partial/conflicting nets"}
set fp [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/final-check-timing.rpt} r];set checks [read $fp];close $fp
if {![regexp {checking no_clock \(0\)} $checks] || ![regexp {checking unconstrained_internal_endpoints \(0\)} $checks]} {error "clock coverage failed"}
set pulse [report_pulse_width -return_string -all_violators]
set fp [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/final-pulse.rpt} w];puts $fp $pulse;close $fp
if {[regexp -nocase {VIOLATED} $pulse] || [regexp {(^|[[:space:]])-[0-9]+\.[0-9]+([[:space:]]|$)} $pulse]} {error "pulse width failed"}
set skew [report_bus_skew -return_string -no_detailed_paths -warn_on_violation]
set fp [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/final-bus-skew.rpt} w];puts $fp $skew;close $fp
if {[regexp -nocase {VIOLATED} $skew]} {error "bus skew failed"}
report_timing_summary -report_unconstrained -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/timing-summary.rpt}
report_drc -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/final-drc.rpt}
set setup [get_timing_paths -delay_type max -max_paths 1]
set hold [get_timing_paths -delay_type min -max_paths 1]
if {![llength $setup] || ![llength $hold]} {error "missing timing paths"}
set wns [get_property SLACK $setup];set whs [get_property SLACK $hold]
if {$wns<0 || $whs<0} {error "setup/hold not closed: $wns $whs"}
set bad [get_drc_violations -quiet -filter {SEVERITY == Error}]
if {[llength $bad]} {error "DRC errors: $bad"}
puts "MCRAMS_PHYSICAL_TIMING WNS=$wns WHS=$whs"
source {/data1/gzh/EC/firesim/final-opt4-20261106/candidates/mcrams-preplace-exception-contract-r1-20261112/verify.tcl}
ec_target_contract::verify {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/final-target-exception-contract}
write_bitstream -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/firesim.bit}
exit 0