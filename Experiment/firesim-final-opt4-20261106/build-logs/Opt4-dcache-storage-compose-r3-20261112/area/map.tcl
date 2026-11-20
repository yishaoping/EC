set_param general.maxThreads 2
read_verilog -sv {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-dcache-storage-compose-r3-20261112/full-dcache-observed.sv}
synth_design -mode out_of_context -top BoomNonBlockingDCache -part xcu280-fsvh2892-2L-e
if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-dcache-storage-compose-r3-20261112/area/utilization.rpt}
report_utilization -hierarchical -hierarchical_depth 25 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-dcache-storage-compose-r3-20261112/area/hierarchical.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-dcache-storage-compose-r3-20261112/area/module.dcp}
exit 0
