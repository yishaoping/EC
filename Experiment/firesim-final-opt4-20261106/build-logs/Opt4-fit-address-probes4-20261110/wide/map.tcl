set_param general.maxThreads 4
read_verilog {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-probes4-20261110/wide/increment.v}
synth_design -top Increment -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-probes4-20261110/wide/utilization.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-probes4-20261110/wide/module.dcp}
write_verilog -force -mode funcsim {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-probes4-20261110/wide/mapped.v}
puts "EC_ADDRESS_PROBE4_MAP_COMPLETE"
exit 0
