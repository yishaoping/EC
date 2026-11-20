set_param general.maxThreads 2
read_verilog -sv {/data1/gzh/EC/firesim/final-opt4-20261106/candidates/mcrams-owner-generated-area-r1-20261111/actual-owner-host-closure.sv}
synth_design -mode out_of_context -top ownerImageMemory_flattened -part xcu280-fsvh2892-2L-e
set bb [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]
if {[llength $bb]} {error "Unresolved RAM host dependencies: $bb"}
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-owner-generated-area-r1-20261111/utilization.rpt}
report_utilization -hierarchical -hierarchical_depth 12 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-owner-generated-area-r1-20261111/hierarchical.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-owner-generated-area-r1-20261111/module.dcp}
puts "OWNER_ACTUAL_HOST_AREA_ZERO_BLACKBOX_PASS"
exit 0
