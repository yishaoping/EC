set_param general.maxThreads 2
read_verilog -sv {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-address-bucket-r5-20261112/Reg/FireSim-generated.sv}
synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e
if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "unresolved address bank model"}
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-address-bucket-area-r2-20261112/Reg/utilization.rpt}
report_utilization -hierarchical -hierarchical_depth 15 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-address-bucket-area-r2-20261112/Reg/hierarchical.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-address-bucket-area-r2-20261112/Reg/mapped.dcp}
puts "ACTUAL_ADDRESS_BANK_AREA_ZERO_BLACKBOX"
exit 0
