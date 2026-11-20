set_param labtools.enable_cs_server false
open_hw_manager
connect_hw_server -url localhost:3121 -allow_non_jtag
refresh_hw_server
puts "EC_JTAG_TARGETS [get_hw_targets -quiet]"
puts "EC_JTAG_SERVERS [get_hw_servers -quiet]"
exit
