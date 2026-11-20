set_param general.maxThreads 2
open_checkpoint original.dcp
puts "EC_CLOCKS=[get_clocks]"
puts "EC_FROM_FILTER=[get_clocks -filter {NAME == \"pcie_refclk_clk_p\"}]"
puts {literal query next}
puts [get_clocks -filter {NAME == "GTYE4_CHANNEL_TXOUTCLK[3]_3"}]
puts "EC_TO_PIN=[get_clocks -of_objects [get_ports cb]]"
read_xdc new.xdc
report_exceptions -file debug-read-exceptions.rpt
write_xdc -force debug-read.xdc
set_clock_groups -asynchronous -group [get_clocks -of_objects [get_ports ca]] -group [get_clocks -of_objects [get_ports cb]]
report_exceptions -file debug-direct-exceptions.rpt
write_xdc -force debug-direct.xdc
puts EC_CONSTRAINT_DEBUG_DONE
exit
