set_param general.maxThreads 2
read_verilog {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/full-ec-structural-priority-20261112/dsp-inference-support/add65.v}
synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/full-ec-structural-priority-20261112/dsp-inference-support/utilization.rpt}
write_verilog -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/full-ec-structural-priority-20261112/dsp-inference-support/mapped.v}
exit 0
