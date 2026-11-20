set_param general.maxThreads 2
read_verilog {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-packed-full-module-r1-20261112/Candidate-Module/FPGATop.v}
synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e
if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-packed-full-module-r1-20261112/Candidate-area/utilization.rpt}
report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-packed-full-module-r1-20261112/Candidate-area/hierarchical.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-packed-full-module-r1-20261112/Candidate-area/module.dcp}
exit 0
