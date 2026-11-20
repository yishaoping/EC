set_param general.maxThreads 2
read_verilog -sv {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-svb-r3-20261111/SafeChainEventLogger.v}
read_verilog -sv {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-svb-r3-20261111/SpeculativeVersionBuffer.sv}
synth_design -mode out_of_context -top SpeculativeVersionBuffer -part xcu280-fsvh2892-2L-e
set bb [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]
if {[llength $bb]} {error "unresolved dependencies"}
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-svb-r3-20261111/utilization.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-svb-r3-20261111/module.dcp}
exit 0
