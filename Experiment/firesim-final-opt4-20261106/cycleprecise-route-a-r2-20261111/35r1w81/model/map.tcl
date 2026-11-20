set_param general.maxThreads 2
read_verilog {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-route-a-r2-20261111/35r1w81/model/AsyncMemChiselModel.v}
synth_design -mode out_of_context -top AsyncMemChiselModel -part xcu280-fsvh2892-2L-e
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-route-a-r2-20261111/35r1w81/model/utilization.rpt}
report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-route-a-r2-20261111/35r1w81/model/hierarchical.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-route-a-r2-20261111/35r1w81/model/module.dcp}
exit 0
