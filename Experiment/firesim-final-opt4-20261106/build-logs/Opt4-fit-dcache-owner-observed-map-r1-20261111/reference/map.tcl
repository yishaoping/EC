set_param general.maxThreads 2
read_verilog {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-owner-observed-map-r1-20261111/reference/RegisterReference.v}
synth_design -mode out_of_context -top RegisterReference -part xcu280-fsvh2892-2L-e
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-owner-observed-map-r1-20261111/reference/utilization.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-owner-observed-map-r1-20261111/reference/module.dcp}
exit 0
