set_param general.maxThreads 2
open_checkpoint {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/vivado_proj/firesim.gen/sources_1/bd/design_1/ip/design_1_firesim_wrapper_0_0/design_1_firesim_wrapper_0_0.dcp}
if {[get_property PART [current_design]] ne "xcu280-fsvh2892-2L-e"} { error "DCP part mismatch" }
set bb [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]
puts "EC_DCP_READ_OK part=[get_property PART [current_design]] ports=[llength [get_ports]] unresolved=[llength $bb]"
if {[llength $bb] != 0} { error "DUT DCP contains unresolved cells" }
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-dcp-20261110T071734Z/dut-utilization.rpt}
close_design
exit 0
