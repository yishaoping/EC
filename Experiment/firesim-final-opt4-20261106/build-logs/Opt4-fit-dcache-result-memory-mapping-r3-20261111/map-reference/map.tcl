set_param general.maxThreads 4
read_verilog {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-result-memory-mapping-r3-20261111/reference/ReferenceResultMemory.v}
synth_design -top ReferenceResultMemory -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-result-memory-mapping-r3-20261111/map-reference/utilization.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-result-memory-mapping-r3-20261111/map-reference/module.dcp}
exit 0
