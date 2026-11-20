# Select original sequential Q drivers on actual negative shell setup paths.
# Never replicate the target, a clock, a CDC synchronizer or an async data net.
proc shell_fd_q_nets {report} {
  set nets {};set f [open $report w]
  puts $f "cell\tref\tnet\tfanout\tpath_slack"
  foreach path [get_timing_paths -delay_type max -max_paths 256 -nworst 1 -slack_lesser_than 0.0] {
    set start [get_property STARTPOINT_PIN $path]
    set cell [get_cells -quiet -of_objects [get_pins -quiet $start]]
    if {[llength $cell] != 1} {continue}
    set name [get_property NAME $cell]
    if {![string match design_1_i/xdma_0/* $name] && ![string match design_1_i/axi_clock_converter_0/* $name] && ![string match design_1_i/axi_clock_converter_1/* $name] && ![string match design_1_i/ddr4_0/* $name] && ![string match design_1_i/axi_dwidth_converter_0/* $name]} {continue}
    set ref [get_property REF_NAME $cell]
    if {$ref ni {FDRE FDSE FDCE FDPE}} {continue}
    if {[string tolower [get_property ASYNC_REG $cell]] in {1 true yes} || [string tolower [get_property DONT_TOUCH $cell]] in {1 true yes}} {continue}
    set q [get_pins -quiet -of_objects $cell -filter {REF_PIN_NAME == Q}]
    if {[llength $q] != 1} {continue}
    set net [get_nets -quiet -of_objects $q]
    if {[llength $net] != 1} {continue}
    set drivers [get_pins -leaf -of_objects $net -filter {DIRECTION == OUT}]
    set loads [get_pins -leaf -of_objects $net -filter {DIRECTION == IN}]
    if {[llength $drivers] != 1 || [lindex $drivers 0] ne [lindex $q 0] || [llength $loads]<128} {continue}
    if {[lsearch -exact $nets [lindex $net 0]]>=0} {continue}
    puts $f "$name\t$ref\t$net\t[llength $loads]\t[get_property SLACK $path]"
    puts "EC_HOST40_SHELL_Q_NET cell=$name ref=$ref net=$net fanout=[llength $loads]"
    lappend nets [lindex $net 0]
  }
  close $f
  return $nets
}
