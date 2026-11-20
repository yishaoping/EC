set_param general.maxThreads 8
read_verilog {/data1/gzh/EC/firesim/final-opt4-20261106/candidates/capacity-exact-factor-20261110/GHBarrierLatencyStats-factor.v}
synth_design -top GHBarrierLatencyStats -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-factor-leaf-20261110/factor-leaf-utilization.rpt}
report_timing_summary -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-factor-leaf-20261110/factor-leaf-timing.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-factor-leaf-20261110/factor-leaf.dcp}
puts "EC_CANDIDATE_LEAF_MAPPING_COMPLETE_NOT_FULL_DUT"
exit 0
