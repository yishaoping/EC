set_param general.maxThreads 1
create_project -in_memory -part xcu280-fsvh2892-2L-e
set_property design_mode GateLvl [current_fileset]
read_verilog fixture.v
link_design -top exception_contract_fixture -part xcu280-fsvh2892-2L-e
source /data1/gzh/EC/firesim/final-opt4-20261106/candidates/mcrams-preplace-exception-contract-r1-20261112/verify.tcl
create_clock -name clk_out1_design_1_clk_wiz_0_0 -period 19.998 [get_ports clk]
foreach name {buildtop_reference_clock tileClockGroup_tile_1} index {0 1} {
    create_generated_clock -name $name -source [get_ports clk] -divide_by 1 [get_pins b${index}/O]
}
write_checkpoint -force diagnostic-clocks-only.dcp
foreach name {buildtop_reference_clock tileClockGroup_tile_1} setup {1 2} hold {0 1} {
    set c [get_clocks $name]
    set_multicycle_path $setup -setup -from $c -to $c
    set_multicycle_path $hold -hold -from $c -to $c
}
write_checkpoint -force diagnostic-baseline.dcp
proc restore {} {close_design; open_checkpoint diagnostic-baseline.dcp}
proc checker {} {get_clocks tileClockGroup_tile_1}
proc check_case {name expect_pass} {
    set failed [catch {ec_target_contract::verify [file join cases-v3 $name]} message]
    puts "VALIDATION_CASE $name failed=$failed expected_pass=$expect_pass message=$message"
    if {$failed == $expect_pass} {error "validation expectation failed: $name"}
}
check_case original_1_0_2_1 1
set_multicycle_path 3 -setup -from [checker] -to [checker]
check_case weakened_checker_setup 0
restore
set_multicycle_path 0 -hold -from [checker] -to [checker]
check_case missing_checker_hold_compensation 0
restore
close_design
open_checkpoint diagnostic-clocks-only.dcp
set_multicycle_path 1 -setup -from [get_clocks buildtop_reference_clock] -to [get_clocks buildtop_reference_clock]
set_multicycle_path 0 -hold -from [get_clocks buildtop_reference_clock] -to [get_clocks buildtop_reference_clock]
set_multicycle_path 2 -setup -from [checker] -to [checker]
check_case absent_checker_hold 0
restore
set_false_path -from [checker] -to [checker]
check_case checker_false_path 0
restore
set_false_path -from [get_pins r3/C] -to [get_pins r2/D]
check_case partially_overridden_checker 0
restore
set_multicycle_path 3 -setup -from [get_pins r3/C] -to [get_pins r2/D]
check_case pin_specific_checker_multicycle 0
restore
create_generated_clock -name tileClockGroup_tile_1 -source [get_ports clk] -divide_by 2 [get_pins b1/O]
set_multicycle_path 2 -setup -from [checker] -to [checker]
set_multicycle_path 1 -hold -from [checker] -to [checker]
check_case doubled_physical_checker_clock 0
restore
check_case restored_1_0_2_1 1
puts "ALL_EXCEPTION_CONTRACT_VALIDATIONS_PASSED"
exit 0
