set_param general.maxThreads 2
read_verilog {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/performance-only-local-cdc-r1-20261114/run-r2/target/QueuePair.v}
synth_design -top AsyncQueue -part xcu280-fsvh2892-2L-e -mode out_of_context -flatten_hierarchy rebuilt
create_clock -name enqueue -period 20.0 [get_ports io_enq_clock]
create_clock -name dequeue -period 40.0 [get_ports io_deq_clock]
opt_design
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/performance-only-local-cdc-r1-20261114/area-r1/Flat/utilization.rpt}
report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/performance-only-local-cdc-r1-20261114/area-r1/Flat/hierarchical.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/performance-only-local-cdc-r1-20261114/area-r1/Flat/postopt.dcp}
puts "EC_LOCAL_CDC_COMPLETE_MODULE_AREA_DONE"
exit 0
