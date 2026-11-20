# Candidate helper for the existing host-clock.tcl normalizer. Not sourced into
# active CAD. Replays precisely the previously resolved clock sets; no new
# exceptions, no relaxation of DDR/PCIe/target periods or setup/hold requirements.
# Replace only ec_record_groups's "queries/concat" emission with this function.
proc ec_exact_clock_query {names} {
    if {![llength $names]} {error "empty clock set must not produce a new exception"}
    set clauses {}
    foreach name $names {
        if {[regexp {["\\\n\r]} $name]} {error "unsupported clock name quoting"}
        lappend clauses [format {NAME == "%s"} $name]
    }
    return "\[get_clocks -quiet -filter [list [join $clauses { || }]]\]"
}
proc ec_exact_clock_groups {groups} {
    if {[llength $groups] != 2} {error "expected the two original resolved clock sets"}
    foreach names $groups {
        if {![llength $names]} {return "# Original empty scoped group; preserve no exception."}
    }
    set command {set_clock_groups -asynchronous}
    foreach names $groups {append command " -group [ec_exact_clock_query $names]"}
    return $command
}

set ec_resume_checkpoint {}
proc ec_record_groups {args} {
    global ec_groups
    set groups {}
    for {set i 0} {$i < [llength $args]} {incr i} {
        set a [lindex $args $i]
        if {$a eq "-group"} {incr i; lappend groups [lsort [lindex $args $i]]} elseif {$a ne "-asynchronous"} {error "unexpected scoped group option $a"}
    }
    if {[llength $groups] != 2} {error "expected two original clock groups"}
    lappend ec_groups $groups
    if {![llength [lindex $groups 0]] || ![llength [lindex $groups 1]]} {
        return "# Original empty scoped clock-group query; no exception applied."
    }
    return [ec_exact_clock_groups $groups]
}

set mmcm [get_cells -hier -quiet -filter {NAME =~ */clk_wiz_0/inst/mmcme4_adv_inst && REF_NAME == MMCME4_ADV}]
if {[llength $mmcm] != 1} {error "one exact host MMCM required"}
if {[get_property CLKFBOUT_MULT_F $mmcm] != 4 || [get_property DIVCLK_DIVIDE $mmcm] != 1} {
    error "unrecognized MMCM VCO configuration"
}
if {$ec_frequency ni {15 10}} {error "unapproved host frequency"}
set divide [expr {$ec_frequency == 15 ? 80.0 : 120.0}]
set_property CLKOUT0_DIVIDE_F $divide $mmcm
report_property -all $mmcm -file "$out/host-mmcm.txt"

# Remove the identified invalid clk_wiz OOC primary-clock override. Lift only
# the existing scoped asynchronous clock groups to the root with exactly the
# clock sets resolved by their original queries. All other XDC is unchanged.
write_xdc -force "$out/clock-input.xdc"
set f [open "$out/clock-input.xdc" r]; set original [read $f]; close $f
set normalized {}; set removed 0; set lifted 0; set ec_groups {}
set in_wizard 0; set in_pcie 0
foreach line [split $original \n] {
    set trim [string trim $line]
    if {[string match "current_instance*" $trim]} {
        set in_wizard [expr {$trim eq "current_instance design_1_i/clk_wiz_0/inst"}]
        set in_pcie [expr {$trim eq "current_instance design_1_i/xdma_0/inst/pcie4c_ip_i/inst"}]
    }
    if {$in_wizard && ([string match "create_clock *" $trim] || [string match "set_input_jitter *" $trim])} {
        incr removed
        lappend normalized "# Removed invalid OOC-only clock override: $trim"
        continue
    }
    if {$in_pcie && [string match "set_clock_groups *" $trim]} {
        current_instance design_1_i/xdma_0/inst/pcie4c_ip_i/inst
        set replacement [eval [string map {set_clock_groups ec_record_groups} $trim]]
        current_instance -quiet
        lappend normalized {current_instance -quiet} $replacement $line
        # Keep an auditable copy as a comment, not a duplicate scoped constraint.
        set normalized [lreplace $normalized end end "# Original scoped command: $line"]
        lappend normalized {current_instance design_1_i/xdma_0/inst/pcie4c_ip_i/inst}
        incr lifted
        continue
    }
    lappend normalized $line
}
current_instance -quiet
set existing_targets [get_clocks -quiet {buildtop_reference_clock tileClockGroup_tile_1}]
set validated_reuse [expr {$removed == 0 && $lifted == 0 && [llength $existing_targets] == 2 && ![llength [get_clocks -quiet design_1_i/clk_wiz_0/inst/clk_in1]]}]
if {$validated_reuse} {error "this candidate admits only a fresh raw post-opt checkpoint, not a previous recovered clock replay"}
if {$removed != 2 || $lifted != 8} {error "unknown original scoped clock recipe removed=$removed lifted=$lifted"}
set f [open "$out/normalized-clock-groups.txt" w];puts $f $ec_groups;close $f
set f [open "$out/clock-normalized.xdc" w];puts $f [join $normalized \n];close $f
if {!$validated_reuse} {
    reset_timing -invalid
    read_xdc "$out/clock-normalized.xdc"
    set input_clock [get_clocks -quiet sysclk0_clk_p]
    if {[llength $input_clock] != 1 || [get_property IS_GENERATED $input_clock]} {error "DDR reference must have one real primary clock"}
    # Keep the removed OOC jitter allowance as a conservative requirement on
    # the real upstream primary instead of inventing an internal primary.
    set_input_jitter $input_clock 0.033
} else {
    puts "EC_REUSE_VALIDATED_TOP_LEVEL_CLOCK_CONSTRAINTS"
}
current_instance -quiet
update_timing
foreach groups $ec_groups {
    foreach names $groups {
        foreach name $names {
            set clocks [get_clocks -quiet -filter [format {NAME == "%s"} $name]]
            if {[llength $clocks] != 1 || [get_property NAME $clocks] ne $name} {error "clock-group replay lost or renamed original clock $name"}
        }
    }
}

set record [open "$out/clock-contract.txt" w]
foreach index {0 1} name {buildtop_reference_clock tileClockGroup_tile_1} cycles {1 2} {
    set source [get_pins -hier -quiet -filter "NAME =~ */clockBridge_clocks_${index}_buffer/I"]
    set sink [get_pins -hier -quiet -filter "NAME =~ */clockBridge_clocks_${index}_buffer/O"]
    if {[llength $source] != 1 || [llength $sink] != 1} {error "clock bridge $index is not unique"}
    set master [get_clocks -quiet -of_objects $source]
    if {[llength $master] != 1} {error "host master is not unique"}
    set period [get_property PERIOD $master]
    if {abs($period - 1000.0/$ec_frequency) > 0.1} {error "real MMCM clock period $period disagrees with requested $ec_frequency MHz"}
    if {[llength [get_clocks -quiet $name]]} {
        if {!$validated_reuse || [lsearch -exact [get_clocks -of_objects $sink] $name] < 0} {error "unexpected existing target generated clock"}
        if {abs([get_property PERIOD [get_clocks $name]]-$period)>0.001} {error "reused generated clock did not follow physical MMCM change"}
    } else {
        create_generated_clock -name $name -source $source -divide_by 1 $sink
    }
    set_multicycle_path $cycles -setup -from [get_clocks $name] -to [get_clocks $name]
    set_multicycle_path [expr {$cycles-1}] -hold -from [get_clocks $name] -to [get_clocks $name]
    puts $record "$name master=$master nominal_MHz=$ec_frequency actual_period_ns=$period actual_MHz=[expr {1000.0/$period}] mmcm_divide=$divide setup=$cycles hold=[expr {$cycles-1}]"
}
close $record
report_clocks -file "$out/repaired-clocks.rpt"
report_clock_interaction -file "$out/repaired-clock-interaction.rpt"
write_xdc -force "$out/repaired-effective.xdc"
report_methodology -checks {TIMING-4 TIMING-27 TIMING-54} -file "$out/clock-methodology.rpt"
set f [open "$out/clock-methodology.rpt" r]; set clock_report [read $f]; close $f
if {[regexp {\|\s*(Error|Critical Warning)\s*\|} $clock_report]} {error "clock/scope methodology remains unresolved; refuse physical implementation"}

# The raw post-opt source must resolve the same vendor-owned PCIe groups.
set ec_constraint_directory [file dirname [info script]]
set f [open [file join $ec_constraint_directory clock-groups-original.tcldata] r]
set ec_original_groups [read $f];close $f
source [file join $ec_constraint_directory clock-exception-check.tcl]
if {[ec_expected_clock_group_pairs $ec_groups] ne [ec_expected_clock_group_pairs $ec_original_groups]} {
    error "fresh checkpoint clock memberships differ from the recorded original shell"
}
foreach pair $ec_groups {
    foreach names $pair {
        foreach name $names {
            if {$name in {mmcm_clkout0 buildtop_reference_clock tileClockGroup_tile_1 sysclk0_clk_p}} {
                error "DDR/host timing must not be cut by the PCIe clock-group replay"
            }
        }
    }
}
report_exceptions -file "$out/replayed-exceptions.rpt"
set f [open "$out/replayed-exceptions.rpt" r];set ec_exception_text [read $f];close $f
set ec_verified_pairs [ec_verify_clock_group_report $ec_exception_text $ec_groups]
set ec_ddr [get_clocks -quiet -filter {NAME == "mmcm_clkout0"}]
if {[llength $ec_ddr] != 1 || abs([get_property PERIOD $ec_ddr]-3.332)>0.001 ||
    ![get_property IS_GENERATED $ec_ddr] || [get_property MASTER_CLOCK $ec_ddr] ne "sysclk0_clk_p"} {
    error "original independent DDR clock contract changed"
}
set f [open "$out/clock-replay-admission.complete" w]
puts $f "PASS_EXACT_ORIGINAL_PCIE_CLOCK_GROUP_PAIRS=$ec_verified_pairs DDR_3.332_NS_UNCHANGED HOST_RELATED_NO_NEW_FALSE_PATH"
close $f
