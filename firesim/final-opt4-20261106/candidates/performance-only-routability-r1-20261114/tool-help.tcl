foreach c {place_design phys_opt_design route_design report_design_analysis report_utilization report_high_fanout_nets report_qor_suggestions get_tiles get_sites get_slrs get_property reset_property write_xdc} {puts "EC_HELP_BEGIN $c"; puts [help $c]; puts "EC_HELP_END $c"}
exit 0
