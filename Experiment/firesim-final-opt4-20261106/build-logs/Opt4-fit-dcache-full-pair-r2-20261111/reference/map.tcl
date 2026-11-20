set_param general.maxThreads 2
set_param synth.elaboration.rodinMoreOptions {rt::set_parameter dissolveMemorySizeLimit 74752}
read_verilog -sv {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-full-pair-r2-20261111/reference/full-dcache-observed.sv}
synth_design -mode out_of_context -top BoomNonBlockingDCache -part xcu280-fsvh2892-2L-e
set bb [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]
if {[llength $bb]} {error "unresolved DCache dependencies: $bb"}
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-full-pair-r2-20261111/reference/utilization.rpt}
report_utilization -hierarchical -hierarchical_depth 25 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-full-pair-r2-20261111/reference/hierarchical.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-full-pair-r2-20261111/reference/module.dcp}
exit 0
