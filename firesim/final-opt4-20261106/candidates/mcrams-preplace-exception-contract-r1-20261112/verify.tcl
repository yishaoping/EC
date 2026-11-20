# Read-only assertion of the generated target exception contract in an open design.
# Never source this as an XDC: it defines a verifier and changes no constraints.
namespace eval ec_target_contract {
    variable native clk_out1_design_1_clk_wiz_0_0
    variable clocks {buildtop_reference_clock tileClockGroup_tile_1}
    variable touched 0
}

proc ec_target_contract::ignore {args} {return {}}

proc ec_target_contract::inspect_query {command args} {
    variable clocks
    variable touched
    # These aliases expose read-only object queries, never constraint commands.
    set objects [uplevel #0 [list $command {*}$args]]
    if {![llength $objects]} {return $objects}
    set domains {}
    if {$command eq "get_clocks"} {
        foreach c $objects {lappend domains [get_property NAME $c]}
    } else {
        if {$command ne "get_cells"} {
            foreach c [get_clocks -quiet -of_objects $objects] {lappend domains [get_property NAME $c]}
        }
        if {$command eq "get_pins" || $command eq "get_cells"} {
            if {$command eq "get_pins"} {set cells [get_cells -quiet -of_objects $objects]} else {set cells $objects}
            set cp [get_pins -quiet -of_objects $cells -filter {IS_CLOCK == 1}]
            if {[llength $cp]} {
                foreach c [get_clocks -quiet -of_objects $cp] {lappend domains [get_property NAME $c]}
            }
        }
    }
    foreach c $domains {if {$c in $clocks} {set touched 1}}
    # Native Vivado collections must not cross an interpreter boundary mixed
    # with Tcl option strings. Return ordinary object names for nested queries.
    set names {}
    foreach object $objects {lappend names [get_property NAME $object]}
    return $names
}

proc ec_target_contract::touches_target {command} {
    variable touched
    set touched 0
    set parser [interp create -safe]
    foreach query {get_clocks get_cells get_pins get_ports get_nets} {
        interp alias $parser $query {} ec_target_contract::inspect_query $query
    }
    foreach constraint {current_design set_false_path set_multicycle_path set_max_delay set_min_delay set_bus_skew} {
        interp alias $parser $constraint {} ec_target_contract::ignore
    }
    # An unsupported export/scope fails closed instead of hiding an exception.
    set code [catch {interp eval $parser $command} message options]
    interp delete $parser
    if {$code} {return -options $options $message}
    return $touched
}

proc ec_target_contract::check_export {text} {
    variable clocks
    set pending {}
    set found [dict create]
    foreach line [split $text \n] {
        if {$pending eq {} && [regexp {^\s*(#|$)} $line]} {continue}
        append pending $line \n
        if {![info complete $pending]} {continue}
        set command [string trim [regsub -all {\\\n\s*} $pending { }]]
        set pending {}
        # Only inspect target exceptions; all original shell exceptions stay.
        if {![regexp {buildtop_reference_clock|tileClockGroup_tile_1|/sim/target/} $command]} {
            if {[touches_target $command]} {error "noncanonical exception touches a target clock domain: $command"}
            continue
        }
        set pattern {^set_multicycle_path ([0-9]+) -(setup|hold)\s+-from \[get_clocks \{?(buildtop_reference_clock|tileClockGroup_tile_1)\}?\]\s+-to \[get_clocks \{?(buildtop_reference_clock|tileClockGroup_tile_1)\}?\]$}
        if {![regexp $pattern $command -> cycles type from to] || $from ne $to} {
            error "unexpected valid target exception: $command"
        }
        set key [list $from $type]
        if {[dict exists $found $key]} {error "duplicate target exception: $key"}
        dict set found $key $cycles
    }
    if {[string trim $pending] ne {}} {error "incomplete exception export"}
    foreach name $clocks setup {1 2} hold {0 1} {
        foreach type {setup hold} expected [list $setup $hold] {
            set key [list $name $type]
            if {![dict exists $found $key] || [dict get $found $key] != $expected} {
                error "missing or changed valid target exception: $name $type expected=$expected"
            }
        }
    }
    return $found
}

proc ec_target_contract::check_coverage {text name setup hold} {
    set found [dict create]
    foreach line [split $text \n] {
        if {![regexp {^\s*[0-9]+\s+Multicycle Path\s+} $line]} {continue}
        set fields [regexp -all -inline {\S+} $line]
        if {[llength $fields] != 12 || [lrange $fields 5 8] ne {1 clocks 1 clocks}
            || ![string is integer -strict [lindex $fields 9]] || [lindex $fields 9] < 1
            || [lindex $fields 10] ne "100.00" || [lindex $fields 11] ne "100.00"} {
            error "target exception lacks complete nonempty coverage: $name $line"
        }
        if {[lindex $fields 3] eq "cycles=$setup" && [lindex $fields 4] eq "-"} {
            set type setup
        } elseif {[lindex $fields 3] eq "-" && [lindex $fields 4] eq "cycles=$hold"} {
            set type hold
        } else {error "unexpected target coverage row: $name $line"}
        if {[dict exists $found $type]} {error "duplicate target coverage: $name $type"}
        dict set found $type [lindex $fields 9]
    }
    if {[dict size $found] != 2} {error "missing target exception coverage: $name"}
    return $found
}

proc ec_target_contract::verify {output} {
    variable native
    variable clocks
    if {[file exists $output]} {error "preserve existing verification output: $output"}
    file mkdir $output
    # Vivado 2021.1 requires -file here and forbids -from/-to with this export.
    set valid [file join $output valid-exceptions.xdc]
    report_exceptions -write_valid_exceptions -file $valid
    set fp [open $valid r]; set text [read $fp]; close $fp
    set exported [check_export $text]
    set host [get_clocks -quiet $native]
    if {[llength $host] != 1} {error "missing unique native physical clock"}
    set period [get_property PERIOD $host]
    set result [dict create native_clock $native native_period_ns $period valid_exceptions $exported]
    foreach name $clocks setup {1 2} hold {0 1} {
        set c [get_clocks -quiet $name]
        if {[llength $c] != 1 || [get_property MASTER_CLOCK $c] ne $native
            || abs([get_property PERIOD $c]-$period)>0.001
            || [llength [all_registers -clock $c]] < 1} {
            error "target physical clock contract failed: $name"
        }
        set coverage [report_exceptions -from $c -to $c -coverage -no_header -return_string]
        set fp [open [file join $output ${name}-coverage.rpt] w]; puts $fp $coverage; close $fp
        dict set result $name coverage [check_coverage $coverage $name $setup $hold]
        set ignored [get_timing_paths -from $c -to $c -user_ignored -max_paths 1]
        if {[llength $ignored]} {error "target timing paths are suppressed: $name"}
        foreach type {max min} {
            set path [get_timing_paths -from $c -to $c -delay_type $type -max_paths 1]
            if {[llength $path] != 1} {error "missing timed target path: $name $type"}
            set requirement [get_property REQUIREMENT $path]
            set exception [get_property EXCEPTION $path]
            set expected [expr {$type eq "max" ? $setup*$period : 0.0}]
            if {abs($requirement-$expected)>0.001} {
                error "effective target requirement changed: $name $type $requirement expected=$expected"
            }
            if {$type eq "max"} {
                set pattern "^MultiCycle Path +Setup -end +$setup *$"
            } else {
                set pattern "^MultiCycle Path +Setup -end +$setup +Hold +-start +$hold *$"
            }
            if {![regexp $pattern $exception]} {error "effective target exception changed: $name $type $exception"}
            dict set result $name $type [dict create requirement_ns $requirement exception $exception \
                startpoint [get_property STARTPOINT_PIN $path] endpoint [get_property ENDPOINT_PIN $path]]
        }
    }
    set fp [open [file join $output result.tcldict] w]; puts $fp $result; close $fp
    puts "TARGET_EXCEPTION_CONTRACT_PASS $result"
    return $result
}
