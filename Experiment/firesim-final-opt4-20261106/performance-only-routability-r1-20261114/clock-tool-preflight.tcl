set_param general.maxThreads 2
foreach command {delete_clocks reset_clock_groups get_clock_groups reset_timing read_xdc report_exceptions} {
    puts "EC_CLOCK_TOOL_HELP $command"
    if {[catch {help $command} result]} {puts "EC_HELP_UNAVAILABLE $command $result"}
}
exit 0
