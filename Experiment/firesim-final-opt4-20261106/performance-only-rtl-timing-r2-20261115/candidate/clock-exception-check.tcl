# Inspect actual report_exceptions output, not an explicit get_timing_paths
# query (which can still return diagnostic paths across clock groups).
proc ec_report_clock_group_pairs {text} {
    set pairs {}
    foreach line [split $text \n] {
        if {![regexp {clock_group[[:space:]]+clock_group} $line]} {continue}
        set matches [regexp -all -inline {\[get_clocks[[:space:]]+\{([^\}]*)\}\]} $line]
        if {[llength $matches] != 4} {error "unrecognized clock-group exception row: $line"}
        lappend pairs [list [lsort [string trim [lindex $matches 1]]] [lsort [string trim [lindex $matches 3]]]]
    }
    return [lsort -unique $pairs]
}

proc ec_expected_clock_group_pairs {groups} {
    set pairs {}
    foreach pair $groups {
        if {[llength $pair] != 2} {error "unknown clock-group arity"}
        lassign $pair a b
        if {![llength $a] || ![llength $b]} {continue}
        set a [lsort $a];set b [lsort $b]
        foreach clock $a {
            if {[lsearch -exact $b $clock] >= 0} {error "overlapping asynchronous groups"}
        }
        lappend pairs [list $a $b] [list $b $a]
    }
    return [lsort -unique $pairs]
}

proc ec_verify_clock_group_report {text groups} {
    set observed [ec_report_clock_group_pairs $text]
    set expected [ec_expected_clock_group_pairs $groups]
    if {$observed ne $expected} {error "actual clock-group exception memberships differ: expected=$expected observed=$observed"}
    return [llength $observed]
}
