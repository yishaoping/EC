set_param general.maxThreads 2
read_verilog {/var/tmp/guozh-ec-rtl-timing-r2-20261115/result-cdc/target/QueuePair.v}
synth_design -top LocalMemAsyncQueue -part xcu280-fsvh2892-2L-e -mode out_of_context -flatten_hierarchy rebuilt
create_clock -name checker -period 200 [get_ports io_enq_clock]
create_clock -name boom -period 100 [get_ports io_deq_clock]
opt_design
report_utilization -file utilization.rpt
report_high_fanout_nets -max_nets 25 -file fanout.rpt
write_checkpoint -force postopt.dcp
puts EC_RESULT_CDC_MODULE_AREA_COMPLETE
exit 0
