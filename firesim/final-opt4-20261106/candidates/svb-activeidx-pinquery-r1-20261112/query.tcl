# Physical-only query of the two original sequential activeIdx Q drivers.
# Exact NAME equality deliberately avoids glob interpretation of [0]/[1].
proc original_activeidx_nets {out} {
  set cells [get_cells -hier -quiet -filter {NAME == design_1_i/firesim_wrapper_0/inst/firesim_top/top/model/sim/target/SVBProbe_/dut/activeIdx_reg[0] || NAME == design_1_i/firesim_wrapper_0/inst/firesim_top/top/model/sim/target/SVBProbe_/dut/activeIdx_reg[1]}]
  if {[llength $cells] != 2} {error "expected exactly two original activeIdx FD cells; got [llength $cells]"}
  set result {}
  set fp [open $out w]
  puts $fp "cell\tref\tq_pin\tnet\tfanout"
  foreach c [lsort $cells] {
    set ref [get_property REF_NAME $c]
    if {$ref ni {FDRE FDSE}} {error "activeIdx has unexpected sequential primitive $ref"}
    set q [get_pins -quiet -of_objects $c -filter {REF_PIN_NAME == Q}]
    if {[llength $q] != 1} {error "activeIdx Q pin ambiguous"}
    set net [get_nets -quiet -of_objects $q]
    if {[llength $net] != 1} {error "activeIdx Q net ambiguous"}
    set drivers [get_pins -leaf -of_objects $net -filter {DIRECTION == OUT}]
    set loads [get_pins -leaf -of_objects $net -filter {DIRECTION == IN}]
    if {[llength $drivers] != 1 || [lindex $drivers 0] ne [lindex $q 0]} {error "activeIdx net driver mismatch"}
    if {[llength $loads] < 1000} {error "activeIdx Q net unexpected fanout [llength $loads]"}
    puts $fp "$c\t$ref\t$q\t$net\t[llength $loads]"
    puts "EC_ACTIVEIDX_PINQUERY cell=$c ref=$ref net=$net fanout=[llength $loads]"
    lappend result [lindex $net 0]
  }
  close $fp
  if {[llength [lsort -unique $result]] != 2} {error "activeIdx Q nets were not distinct"}
  return $result
}
