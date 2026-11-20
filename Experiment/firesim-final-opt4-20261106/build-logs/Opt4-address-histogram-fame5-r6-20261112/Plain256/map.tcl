set_param general.maxThreads 2
read_verilog -sv {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-histogram-fame5-r6-20261112/Plain256/AbstractClockGate.v}
read_verilog -sv {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-histogram-fame5-r6-20261112/Plain256/FireSim-generated.sv}
read_xdc {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-histogram-fame5-r6-20261112/Plain256/FireSim-generated.synthesis.xdc}
synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e
if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-histogram-fame5-r6-20261112/Plain256/utilization.rpt}
report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-histogram-fame5-r6-20261112/Plain256/hierarchical.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-histogram-fame5-r6-20261112/Plain256/host.dcp}
exit 0
