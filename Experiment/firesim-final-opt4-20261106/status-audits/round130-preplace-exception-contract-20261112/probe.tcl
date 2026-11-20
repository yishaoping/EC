set_param general.maxThreads 1
create_project -in_memory -part xcu280-fsvh2892-2L-e
set_property design_mode GateLvl [current_fileset]
read_verilog fixture.v
link_design -top exception_contract_fixture -part xcu280-fsvh2892-2L-e
# Test-only period copied from the saved shell inventory, never a production XDC.
create_clock -name clk_out1_design_1_clk_wiz_0_0 -period 19.998 [get_ports clk]
foreach name {buildtop_reference_clock tileClockGroup_tile_1} index {0 1} setup {1 2} hold {0 1} {
  create_generated_clock -name $name -source [get_ports clk] -divide_by 1 [get_pins b${index}/O]
  set c [get_clocks $name]
  set_multicycle_path $setup -setup -from $c -to $c
  set_multicycle_path $hold -hold -from $c -to $c
}
report_exceptions -write_valid_exceptions -file valid-exceptions.xdc
set fp [open valid-exceptions.xdc r]; puts [read $fp]; close $fp
foreach name {buildtop_reference_clock tileClockGroup_tile_1} {
  set c [get_clocks $name]
  puts "VALID $name"
  puts "COVERAGE $name"
  puts [report_exceptions -from $c -to $c -coverage -no_header -return_string]
  foreach type {max min} {
    set p [get_timing_paths -from $c -to $c -delay_type $type -max_paths 1]
    puts "PATH $name $type: [llength $p]"
    report_property $p
  }
}
exit 0
