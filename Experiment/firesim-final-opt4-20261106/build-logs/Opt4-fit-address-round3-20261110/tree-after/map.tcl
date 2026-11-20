set_param general.maxThreads 8
read_verilog {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-round3-20261110/tree-after/tree.v}
synth_design -top After80 -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-round3-20261110/tree-after/utilization.rpt}
report_utilization -hierarchical -hierarchical_depth 20 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-round3-20261110/tree-after/hierarchical.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-round3-20261110/tree-after/module.dcp}
puts "EC_ADDRESS_ROUND3_MAP_COMPLETE tree-after"
exit 0
