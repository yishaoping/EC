set_param general.maxThreads 8
read_verilog {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-modules-20261110/round2/scanner/SafePrefixScanner.v}
synth_design -top SafePrefixScanner -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-modules-20261110/round2/scanner/utilization.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-modules-20261110/round2/scanner/module.dcp}
puts "EC_OPT4_FIT_ROUND2_MAP_OK scanner"
exit 0
