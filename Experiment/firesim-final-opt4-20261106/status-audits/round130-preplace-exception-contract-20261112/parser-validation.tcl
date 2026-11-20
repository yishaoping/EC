source /data1/gzh/EC/firesim/final-opt4-20261106/candidates/mcrams-preplace-exception-contract-r1-20261112/verify.tcl
set fp [open valid-exceptions.xdc r]; set original [read $fp]; close $fp
proc check {name text expect_pass} {
    set failed [catch {ec_target_contract::check_export $text} message]
    puts "EXPORT_CASE $name failed=$failed expected_pass=$expect_pass message=$message"
    if {$failed == $expect_pass} {error "export assertion failed: $name"}
}
check original_valid_export $original 1
check changed_setup [string map {{set_multicycle_path 2 -setup} {set_multicycle_path 3 -setup}} $original] 0
check changed_hold [string map {{set_multicycle_path 1 -hold} {set_multicycle_path 0 -hold}} $original] 0
check removed_hold [regsub {set_multicycle_path 1 -hold[^#]+} $original {}] 0
check doubled_setup_duplicate "$original\nset_multicycle_path 2 -setup -from \[get_clocks {tileClockGroup_tile_1}\] -to \[get_clocks {tileClockGroup_tile_1}\]\n" 0
puts ALL_VALID_EXPORT_MUTATIONS_PASSED
