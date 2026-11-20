set_param general.maxThreads 2
read_verilog {/data1/gzh/EC/firesim/final-opt4-20261106/candidates/address-dsp-counter-bank-r1-20261111/counter_bank.v}
synth_design -mode out_of_context -top CounterBankCandidate -part xcu280-fsvh2892-2L-e
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-dsp-counter-bank-r1-20261111/candidate/utilization.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-dsp-counter-bank-r1-20261111/candidate/module.dcp}
write_verilog -force -mode funcsim {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-dsp-counter-bank-r1-20261111/candidate/mapped.v}
exit 0
