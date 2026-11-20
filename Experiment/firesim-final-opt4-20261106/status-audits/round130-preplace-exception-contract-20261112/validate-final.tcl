set_param general.maxThreads 1
open_checkpoint diagnostic-baseline.dcp
source /data1/gzh/EC/firesim/final-opt4-20261106/candidates/mcrams-preplace-exception-contract-r1-20261112/verify.tcl
proc restore {} {close_design; open_checkpoint diagnostic-baseline.dcp}
proc check_case {name expect_pass reason} {
    set failed [catch {ec_target_contract::verify [file join cases-final $name]} message options]
    puts "VALIDATION_CASE $name failed=$failed expected_pass=$expect_pass message=$message"
    if {$failed == $expect_pass || ($failed && ![string match $reason $message])} {
        if {$failed} {puts [dict get $options -errorinfo]}
        error "validation expectation failed: $name"
    }
}
check_case original_1_0_2_1 1 {}
set_multicycle_path 3 -setup -from [get_clocks tileClockGroup_tile_1] -to [get_clocks tileClockGroup_tile_1]
check_case conflicting_checker_setup 0 {duplicate target exception:*}
restore
set_multicycle_path 0 -hold -from [get_clocks tileClockGroup_tile_1] -to [get_clocks tileClockGroup_tile_1]
check_case conflicting_checker_hold 0 {duplicate target exception:*}
close_design
open_checkpoint diagnostic-clocks-only.dcp
set_multicycle_path 1 -setup -from [get_clocks buildtop_reference_clock] -to [get_clocks buildtop_reference_clock]
set_multicycle_path 0 -hold -from [get_clocks buildtop_reference_clock] -to [get_clocks buildtop_reference_clock]
set_multicycle_path 2 -setup -from [get_clocks tileClockGroup_tile_1] -to [get_clocks tileClockGroup_tile_1]
check_case absent_checker_hold 0 {missing or changed valid target exception:*}
restore
set_false_path -from [get_clocks tileClockGroup_tile_1] -to [get_clocks tileClockGroup_tile_1]
check_case checker_false_path 0 {unexpected valid target exception:*}
restore
set_false_path -from [get_pins r3/C] -to [get_pins r2/D]
check_case partially_overridden_checker 0 {noncanonical exception touches a target clock domain:*}
restore
set_multicycle_path 3 -setup -from [get_pins r3/C] -to [get_pins r2/D]
check_case pin_specific_checker_multicycle 0 {noncanonical exception touches a target clock domain:*}
restore
create_generated_clock -name tileClockGroup_tile_1 -source [get_ports clk] -divide_by 2 [get_pins b1/O]
check_case doubled_physical_checker_clock 0 {target physical clock contract failed:*}
restore
check_case restored_1_0_2_1 1 {}
puts ALL_EXCEPTION_CONTRACT_VALIDATIONS_PASSED
exit 0
