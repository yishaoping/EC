
set_param general.maxThreads 2
open_checkpoint {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-svb-fpga-r2-20261111/project/cad/vivado_proj/firesim.runs/impl_1/design_1_wrapper_routed.dcp}
if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "unresolved cells"}
set setup [get_timing_paths -delay_type max -max_paths 1]
set hold [get_timing_paths -delay_type min -max_paths 1]
if {![llength $setup] || ![llength $hold]} {error "missing timing paths"}
set wns [get_property SLACK $setup];set whs [get_property SLACK $hold]
report_timing_summary -report_unconstrained -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-svb-fpga-r2-20261111/cad-logs/timing-summary.rpt}
report_drc -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-svb-fpga-r2-20261111/cad-logs/final-drc.rpt}
puts "EC_FIT_TIMING WNS=$wns WHS=$whs"
if {$wns < 0 || $whs < 0} {error "setup/hold timing gate failed"}
write_bitstream -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-frozen-svb-fpga-r2-20261111/project/cad/vivado_proj/firesim.bit}
puts "EC_FIT_BITSTREAM_COMPLETE"
exit 0
