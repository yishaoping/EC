set_param general.maxThreads 1
open_checkpoint {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/vivado_proj/firesim.runs/synth_1/design_1_wrapper.dcp}
set c [get_cells -hier -quiet -filter {REF_NAME == design_1_clk_wiz_0_0}]
if {[llength $c] != 1} {error "missing exact clock shell cell"}
read_checkpoint -cell $c {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/reused-checkpoints/design_1_clk_wiz_0_0.dcp}
report_clocks
puts "CLOCK_HOST_NAMED_COUNT=[llength [get_clocks -quiet host_clock]]"
set pins [get_pins -hier -quiet -filter {NAME =~ */clk_wiz_0/inst/clkout1_buf/O}]
puts "CLOCK_SHELL_OUTPUT_PINS=$pins"
puts "CLOCK_SHELL_OUTPUT_CLOCKS=[get_clocks -quiet -of_objects $pins]"
puts "SHELL_CLOCK_INVENTORY_COMPLETE_NO_SYNTH_OPT_OR_DEVICE"
exit 0
