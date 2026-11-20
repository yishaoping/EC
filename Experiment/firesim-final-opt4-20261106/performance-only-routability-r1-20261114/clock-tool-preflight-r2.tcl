set_param general.maxThreads 2
foreach command {remove_clocks reset_timing read_xdc report_exceptions} {
    puts "EC_CLOCK_TOOL_HELP $command"
    if {[catch {help $command} result]} {puts "EC_HELP_UNAVAILABLE $command $result"} else {puts $result}
}
exit 0
