# User-invoked ASIC-only synthesis. Never uses FireSim-transformed RTL.
set out $env(DAC_AREA_OUT)
set_app_var target_library [split $env(DAC_TARGET_LIBS) "\n"]
set_app_var link_library [concat "*" $target_library [split $env(DAC_LINK_LIBS) "\n"]]
set_host_options -max_cores $env(DAC_MAX_CORES)
define_design_lib WORK -path "$out/WORK"
analyze -format sverilog [split $env(DAC_RTL_FILES) "\n"]
elaborate $env(DAC_TOP)
current_design $env(DAC_TOP)
if {![link]} { error "Unresolved target RTL/library references" }
if {![check_design]} { error "check_design failed" }
if {[sizeof_collection [get_cells -hierarchical -filter "is_black_box == true"]] > 0} {
    error "Unresolved black boxes: area is not comparable"
}
foreach line [split $env(DAC_CLOCKS) "\n"] {
    lassign $line port period
    if {[sizeof_collection [get_ports $port]] != 1} { error "Missing clock port $port" }
    create_clock -name $port -period $period [get_ports $port]
}
# Explicit asynchronous relationships, generated clocks and false paths must be
# supplied in a reviewed target-specific SDC before acceptance of timing results.
set_clock_uncertainty $env(DAC_CLOCK_UNCERTAINTY) [all_clocks]
set nonclock_inputs [remove_from_collection [all_inputs] [get_attribute [all_clocks] sources]]
set_input_delay $env(DAC_IO_DELAY) -clock [index_collection [all_clocks] 0] $nonclock_inputs
set_output_delay $env(DAC_IO_DELAY) -clock [index_collection [all_clocks] 0] [all_outputs]
source $env(DAC_SDC)
redirect -file "$out/check_timing.rpt" {check_timing}
compile_ultra -no_autoungroup
redirect -file "$out/check.rpt" {check_design}
redirect -file "$out/area.rpt" {report_area}
redirect -file "$out/hierarchy.rpt" {report_area -hierarchy}
redirect -file "$out/references.rpt" {report_reference -hierarchy}
redirect -file "$out/timing.rpt" {report_timing -max_paths 50 -path_type full}
redirect -file "$out/constraints.rpt" {report_constraint -all_violators}
redirect -file "$out/clocks.rpt" {report_clock}
write -format ddc -hierarchy -output "$out/target.ddc"
write_sdc "$out/target.sdc"
set f [open "$out/SUCCESS" w]; puts $f "mapped ASIC synthesis completed; inspect unconstrained paths and memory policy"; close $f
exit
