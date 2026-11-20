set_param general.maxThreads 2
read_verilog {/var/tmp/guozh-ec-rtl-timing-r1-20261115/target/QueuePair.v}
synth_design -top GH_FIFO_SC -part xcu280-fsvh2892-2L-e -mode out_of_context -flatten_hierarchy rebuilt
create_clock -name queue -period 100.0 [get_ports clock]
set_input_delay -clock queue 0 [get_ports -filter {DIRECTION == IN && NAME != clock}]
set_output_delay -clock queue 0 [all_outputs]
opt_design
write_checkpoint -force postopt.dcp
report_utilization -file postopt-utilization.rpt
place_design
phys_opt_design -fanout_opt
route_design
write_checkpoint -force routed.dcp
report_utilization -file utilization.rpt
report_timing_summary -report_unconstrained -file timing.rpt
report_timing -delay_type max -max_paths 20 -input_pins -nets -file setup.rpt
report_timing -delay_type min -max_paths 20 -input_pins -nets -file hold.rpt
report_high_fanout_nets -max_nets 20 -file fanout.rpt
report_route_status -file route-status.rpt
report_drc -file drc.rpt
puts EC_BJL_PAIRED_MODULE_MEASUREMENT_COMPLETE
exit 0
