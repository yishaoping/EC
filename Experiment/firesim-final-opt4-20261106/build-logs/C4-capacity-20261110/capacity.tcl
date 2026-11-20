set_param general.maxThreads 8
puts "EC_CAPACITY_DEVICE_BEGIN"
report_property [get_parts xcu280-fsvh2892-2L-e]
puts "EC_CAPACITY_DEVICE_END"
open_checkpoint {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/reused-checkpoints/design_1_firesim_wrapper_0_0.dcp}
puts "EC_CAPACITY_DUT_OPEN"
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-20261110/vivado-preopt.rpt}
report_utilization -hierarchical -hierarchical_depth 10 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-20261110/vivado-hierarchical-preopt.rpt}
puts "EC_CAPACITY_PREOPT_REPORTS_COMPLETE"
opt_design -directive Explore
puts "EC_CAPACITY_OPT_COMPLETE"
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-20261110/vivado-postopt.rpt}
report_utilization -hierarchical -hierarchical_depth 10 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-20261110/vivado-hierarchical-postopt.rpt}
report_drc -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-20261110/vivado-postopt-drc.rpt}
puts "EC_CAPACITY_POSTOPT_REPORTS_COMPLETE"
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-20261110/DUT-optimized-capacity.dcp}
close_design
exit 0
