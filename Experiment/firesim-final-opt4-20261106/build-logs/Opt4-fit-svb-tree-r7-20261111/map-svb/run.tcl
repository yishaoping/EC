set_param general.maxThreads 8
read_verilog {/data1/gzh/EC/firesim/final-opt4-20261106/Opt4-fit-svb-tree-r1-20261111/chipyard/generators/rocket-chip/src/main/resources/vsrc/SafeChainEventLogger.v}
read_verilog {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r7-20261111/svb/SVBModuleHarness.v}
synth_design -top SVBModuleHarness -part xcu280-fsvh2892-2L-e -mode out_of_context
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r7-20261111/map-svb/utilization.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r7-20261111/map-svb/module.dcp}
exit 0
