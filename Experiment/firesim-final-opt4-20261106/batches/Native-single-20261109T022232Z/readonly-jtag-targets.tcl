set_param labtools.enable_cs_server false
open_hw_manager
connect_hw_server -url localhost:3122 -allow_non_jtag
foreach target [get_hw_targets] { puts "EC_JTAG_TARGET $target" }
close_hw_manager
exit
