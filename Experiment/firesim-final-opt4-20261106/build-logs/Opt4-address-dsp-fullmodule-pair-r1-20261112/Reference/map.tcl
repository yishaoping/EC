set_param general.maxThreads 2
read_verilog -sv {/data1/gzh/EC/firesim/final-opt4-20261106/candidates/address-dsp-fullmodule-pair-r1-20261112/Reference.sv}
synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e
if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-dsp-fullmodule-pair-r1-20261112/Reference/utilization.rpt}
report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-dsp-fullmodule-pair-r1-20261112/Reference/hierarchical.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-dsp-fullmodule-pair-r1-20261112/Reference/module.dcp}
exit 0
