set_param general.maxThreads 2
read_verilog {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-slot-epoch-static-r5-20261111/candidate/EpochCandidate.v}
synth_design -mode out_of_context -top EpochCandidate -part xcu280-fsvh2892-2L-e
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-slot-epoch-static-r8-20261111/candidate/utilization.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-slot-epoch-static-r8-20261111/candidate/module.dcp}
exit 0
