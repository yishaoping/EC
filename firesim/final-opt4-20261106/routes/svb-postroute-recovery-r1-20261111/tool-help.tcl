set_param general.maxThreads 2
puts "EC_PHYOPT_HELP_BEGIN"
phys_opt_design -help
puts "EC_PHYOPT_HELP_END"
puts "EC_ROUTE_HELP_BEGIN"
route_design -help
puts "EC_ROUTE_HELP_END"
exit 0
