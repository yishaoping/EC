source {/data1/gzh/EC/firesim/final-opt4-20261106/Opt4-performance-only-rtl-timing-r1-20261115/candidates/rtl-timing-r1/clock-group-replay-no-concat.tcl}
set f [open {/var/tmp/guozh-ec-rtl-structure-r1-20261114/cad-r1/followthrough-r2/physical/candidates/structure-10mhz-ssi_spreadslls-r2/normalized-clock-groups.txt} r]; set groups [read $f]; close $f
set observed {}
proc get_clocks {args} {
    if {[lrange $args 0 1] ne {-quiet -filter}} {error "unknown query"}
    set filter [lindex $args 2]
    set names {}
    foreach {unused name} [regexp -all -inline {NAME == "([^"]+)"} $filter] {lappend names $name}
    if {![llength $names]} {error "empty mocked lookup"}
    return $names
}
proc set_clock_groups {args} {
    global observed
    if {[lindex $args 0] ne "-asynchronous"} {error "changed group kind"}
    set sets {}
    for {set i 1} {$i < [llength $args]} {incr i 2} {
        if {[lindex $args $i] ne "-group"} {error "unexpected group syntax"}
        lappend sets [lsort [lindex $args [expr {$i+1}]]]
    }
    lappend observed $sets
}
if {[llength $groups] != 8} {error "expected eight original group pairs"}
foreach pair $groups {
    set command [ec_exact_clock_groups $pair]
    if {[string first concat $command] >= 0} {error "unsupported command remains"}
    eval $command
}
set expected {}
foreach pair $groups {
    set sets {}; foreach names $pair {lappend sets [lsort $names]};lappend expected $sets
}
if {$observed ne $expected} {error "clock-set membership changed"}
set command [ec_exact_clock_groups {{{literal[3]} clkB} {clkC}}]
eval $command
if {[lindex $observed end] ne {{clkB {literal[3]}} clkC}} {error "literal bracket/union check failed"}
if {[string index [ec_exact_clock_groups {{} {clkB}}] 0] ne "#"} {error "empty group changed"}
puts CLOCK_GROUP_REPLAY_OFFLINE_PASS_original_pairs_8_literal_brackets_union_and_empty
