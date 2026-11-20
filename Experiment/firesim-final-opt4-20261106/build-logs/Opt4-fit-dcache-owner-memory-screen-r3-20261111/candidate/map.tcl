set_param general.maxThreads 2
read_verilog {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-owner-memory-screen-r2-20261111/candidate/AsyncCandidate.v}
synth_design -mode out_of_context -top AsyncCandidate -part xcu280-fsvh2892-2L-e
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-owner-memory-screen-r3-20261111/candidate/utilization.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-owner-memory-screen-r3-20261111/candidate/module.dcp}
exit 0
