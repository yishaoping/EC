set_param general.maxThreads 2
open_checkpoint {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-dsp-fullmodule-pair-r1-20261112/Reference/module.dcp}
if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "unresolved cells"}
if {[llength [get_ports clock]] != 1} {error "exact clock port required"}
if {[llength [get_clocks -quiet]]} {delete_clocks [get_clocks]}
create_clock -name EC_SCREEN_100MHZ -period 10.000 [get_ports clock]
set data_inputs [get_ports -quiet -filter {DIRECTION == IN && NAME != clock}]
if {[llength $data_inputs]} {set_input_delay 0.000 -clock EC_SCREEN_100MHZ $data_inputs}
set_output_delay 0.000 -clock EC_SCREEN_100MHZ [all_outputs]
report_timing_summary -delay_type min_max -report_unconstrained -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-checkpoint-timing-r2-20261113/DSP-Reference/timing-summary.rpt}
report_timing -delay_type max -path_type full_clock_expanded -max_paths 10 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-checkpoint-timing-r2-20261113/DSP-Reference/setup-paths.rpt}
report_timing -delay_type min -path_type full_clock_expanded -max_paths 10 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-checkpoint-timing-r2-20261113/DSP-Reference/hold-paths.rpt}
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-checkpoint-timing-r2-20261113/DSP-Reference/utilization.rpt}
set f [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-address-checkpoint-timing-r2-20261113/DSP-Reference/metrics.txt} w]
foreach delay {max min} {
  set p [get_timing_paths -delay_type $delay -max_paths 1]
  if {![llength $p]} {error "missing $delay timing paths"}
  puts $f "$delay.slack=[get_property SLACK $p]"
  puts $f "$delay.data_path_delay=[get_property DATAPATH_DELAY $p]"
  puts $f "$delay.startpoint=[get_property STARTPOINT_PIN $p]"
  puts $f "$delay.endpoint=[get_property ENDPOINT_PIN $p]"
}
close $f
puts "EC_REPORT_ONLY_CHECKPOINT_TIMING_COMPLETE"
exit 0
