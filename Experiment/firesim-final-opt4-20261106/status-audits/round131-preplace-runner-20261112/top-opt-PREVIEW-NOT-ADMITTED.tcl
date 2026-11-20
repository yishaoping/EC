set_param general.maxThreads 8
create_project -in_memory -part xcu280-fsvh2892-2L-e
set_property design_mode GateLvl [current_fileset]
set_property ip_output_repo {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/vivado_proj/firesim.cache/ip} [current_project]
set_property ip_cache_permissions read [current_project]
set_property XPM_LIBRARIES {XPM_CDC XPM_FIFO XPM_MEMORY} [current_project]
add_files -quiet {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/vivado_proj/firesim.runs/synth_1/design_1_wrapper.dcp}
set_param project.isImplRun true
add_files {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/vivado_proj/firesim.srcs/sources_1/bd/design_1/design_1.bd}
set_param project.isImplRun false
set old [get_files -all -quiet {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/vivado_proj/firesim.gen/sources_1/bd/design_1/ip/design_1_firesim_wrapper_0_0/design_1_firesim_wrapper_0_0.dcp}]
if {[llength $old]!=1} {error "old host checkpoint not uniquely identified"}
set_property USED_IN_IMPLEMENTATION false $old
if {[get_property USED_IN_IMPLEMENTATION $old]} {error "old DUT checkpoint still enabled"}
add_files -quiet {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/wrapper-host-linked.dcp}
set replacement [get_files -all -quiet {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/wrapper-host-linked.dcp}]
if {[llength $replacement]!=1} {error "replacement checkpoint missing"}
set_property SCOPED_TO_CELLS {design_1_i/firesim_wrapper_0} $replacement
report_compile_order -constraints -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/constraint-order.rpt}
set_param project.isImplRun true
link_design -top design_1_wrapper -part xcu280-fsvh2892-2L-e
set_param project.isImplRun false

set bad {}
set unresolved [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]
foreach c $unresolved {
 if {$c eq "dbg_hub" && [get_property REF_NAME $c] eq "dbg_hub_CV" && [get_property IS_DEBUG_CORE $c]} {continue}
 lappend bad $c
}
if {[llength $bad]} {error "unresolved functional blackboxes: $bad"}

write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/linked-with-ip-constraints.dcp}
report_clocks -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/linked-native-clocks.rpt}
# Bind to the observed native clock; never create or rename a physical clock.

set hp [get_pins -hier -quiet -filter {NAME =~ */clk_wiz_0/inst/clkout1_buf/O}]
if {[llength $hp]!=1} {error "physical host BUFG output not unique"}
set physical [get_clocks -quiet -of_objects $hp]
set native [get_clocks -quiet clk_out1_design_1_clk_wiz_0_0]
if {[llength $physical]!=1 || [llength $native]!=1 || $physical ne $native} {
 error "actual physical clock differs from pinned shell evidence: physical=$physical native=$native"
}

set shim [get_cells -hier -quiet -filter {REF_NAME == F1Shim}]
if {[llength $shim]!=1} {error "F1Shim constraint scope not unique"}
read_xdc -cells $shim {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/physical-source-bound.implementation.xdc}
read_xdc {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/design/bitstream_config.xdc}
opt_design -directive Explore
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/top-opt.dcp}
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/top-postopt-utilization.rpt}
report_utilization -hierarchical -hierarchical_depth 30 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/top-postopt-hierarchical.rpt}
report_clocks -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/top-preplace-clocks.rpt}
report_exceptions -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/top-preplace-exceptions.rpt}
write_xdc -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/top-preplace-effective.xdc}

set host [get_clocks -quiet clk_out1_design_1_clk_wiz_0_0]
if {[llength $host] != 1} {error "missing exact host clock"}
set host_period [get_property PERIOD $host]
foreach name {buildtop_reference_clock tileClockGroup_tile_1} {
  set c [get_clocks -quiet $name]
  if {[llength $c] != 1} {error "missing exact target clock $name"}
  if {abs([get_property PERIOD $c]-$host_period)>0.001} {
    error "clock differs from exact generated divide_by=1 contract: $name"
  }
  if {[llength [all_registers -clock $c]] < 1} {error "target clock has no registers: $name"}
}


foreach name {buildtop_reference_clock tileClockGroup_tile_1} {
 set c [get_clocks -quiet $name]
 if {[llength $c]!=1 || [get_property MASTER_CLOCK $c] ne "clk_out1_design_1_clk_wiz_0_0"} {
  error "generated target clock has wrong physical master: $name"
 }
}

source {/data1/gzh/EC/firesim/final-opt4-20261106/candidates/mcrams-preplace-exception-contract-r1-20261112/verify.tcl}
ec_target_contract::verify {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/target-exception-contract}
check_timing -verbose -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/top-preplace-check-timing.rpt}
set fp [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-preplace-contract-runner-r1-20261112/top-preplace-check-timing.rpt} r]
set checks [read $fp];close $fp
if {![regexp {checking no_clock \(0\)} $checks] || ![regexp {checking unconstrained_internal_endpoints \(0\)} $checks]} {
 error "preplace clock coverage failed"
}
puts "IP_COLLATERAL_RELINK_TOP_OPT_CONTRACT_PASSED_NO_PLACE"
exit 0
