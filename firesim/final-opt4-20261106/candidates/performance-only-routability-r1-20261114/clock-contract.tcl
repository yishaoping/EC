# Restore the exact generated Golden Gate 1/0 and 2/1 constraints at linked-shell paths.
# This changes neither the MMCM/BUFG configuration nor the target clock enable RTL.
if {[file exists {/data1/gzh/EC/firesim/final-opt4-20261106/candidates/performance-only-routability-r1-20261114/priority-handoff.json}] && [file tail $out] in {muxf-remap-sll-r2 cdc-svb-only-remap}} {
    set f [open "$out/deferred-to-mem-lowfreq.txt" w]
    puts $f "User priority: preserve existing placement; defer this unstarted legacy placement to the serialized equivalent Mem + 15/10MHz implementation."
    close $f
    puts "EC_UNSTARTED_LEGACY_PLACEMENT_DEFERRED_TO_MEM_LOW_FREQUENCY"
    exit 75
}
set clock_record [open "$out/clock-contract.txt" w]
foreach index {0 1} name {buildtop_reference_clock tileClockGroup_tile_1} cycles {1 2} {
    set source [get_pins -hier -quiet -filter "NAME =~ */clockBridge_clocks_${index}_buffer/I"]
    set sink [get_pins -hier -quiet -filter "NAME =~ */clockBridge_clocks_${index}_buffer/O"]
    if {[llength $source] != 1 || [llength $sink] != 1} {error "clock bridge $index must match exactly once"}
    set master [get_clocks -quiet -of_objects $source]
    if {[llength $master] != 1} {error "clock bridge $index does not have one real master clock"}
    set period [get_property PERIOD $master]
    if {$period < 19.99 || $period > 20.01} {error "unexpected host period $period; no automatic clock-frequency change"}
    if {[llength [get_clocks -quiet $name]]} {error "clock $name already exists; inspect rather than redefine"}
    create_generated_clock -name $name -source $source -divide_by 1 $sink
    set clock [get_clocks $name]
    set_multicycle_path $cycles -setup -from $clock -to $clock
    set_multicycle_path [expr {$cycles - 1}] -hold -from $clock -to $clock
    puts $clock_record "$name master=$master period=$period source=$source sink=$sink setup=$cycles hold=[expr {$cycles - 1}]"
}
close $clock_record
report_clocks -file "$out/repaired-clocks.rpt"
report_clock_interaction -file "$out/repaired-clock-interaction.rpt"
