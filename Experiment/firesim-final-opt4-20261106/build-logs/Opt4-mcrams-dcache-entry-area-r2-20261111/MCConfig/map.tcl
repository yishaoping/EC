set_param general.maxThreads 2
read_verilog -sv {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-dcache-entry-area-r2-20261111/MCConfig/host.sv}
synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e
set boxes [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]
if {[llength $boxes]} {error "unresolved storage-entry dependencies: $boxes"}
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-dcache-entry-area-r2-20261111/MCConfig/utilization.rpt}
report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-dcache-entry-area-r2-20261111/MCConfig/hierarchical.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-dcache-entry-area-r2-20261111/MCConfig/module.dcp}
puts "EC_ENTRY_AREA_ZERO_BLACKBOX_PASS"
exit 0
