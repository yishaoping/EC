set_param general.maxThreads 1
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
if {[llength $old]!=1} {error "exact old host DCP not identified"}
set_property USED_IN_IMPLEMENTATION false $old
puts "OLD_DUT_DCP_IMPLEMENTATION_DISABLED=[get_property USED_IN_IMPLEMENTATION $old]"
set_param project.isImplRun true
link_design -top design_1_wrapper -part xcu280-fsvh2892-2L-e
set_param project.isImplRun false
report_clocks -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/round128-shell-collateral-20261112/linked-shell-clocks.rpt}
report_compile_order -constraints -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/round128-shell-collateral-20261112/linked-constraint-order.rpt}
puts "NAMED_HOST_CLOCK_COUNT=[llength [get_clocks -quiet host_clock]]"
set cp [get_pins -hier -quiet -filter {NAME =~ */clk_wiz_0/inst/clkout1_buf/O}]
puts "PHYSICAL_HOST_CLOCK_PINS=$cp"
puts "PHYSICAL_HOST_CLOCKS=[get_clocks -quiet -of_objects $cp]"
puts "SHELL_ONLY_LINK_INVENTORY_COMPLETE_NO_DUT_SYNTH_OPT_ROUTE_DEVICE"
exit 0
