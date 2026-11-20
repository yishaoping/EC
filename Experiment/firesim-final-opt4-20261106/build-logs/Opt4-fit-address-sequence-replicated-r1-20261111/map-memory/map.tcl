set_param general.maxThreads 4
read_verilog {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-sequence-replicated-r1-20261111/memory/AddressBucketSequenceMemory.v}
synth_design -top AddressBucketSequenceMemory -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-sequence-replicated-r1-20261111/map-memory/utilization.rpt}
report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-sequence-replicated-r1-20261111/map-memory/hierarchical.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-sequence-replicated-r1-20261111/map-memory/module.dcp}
exit 0
