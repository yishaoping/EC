set_param general.maxThreads 2
open_checkpoint {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-spread-implementation-r1-20261111/spread-routed.dcp}
if {[get_property PART [current_design]] ne "xcu280-fsvh2892-2L-e"} {error "wrong device"}
if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "unresolved cells"}
set mmcm [get_cells -hier -filter {NAME == design_1_i/clk_wiz_0/inst/mmcme4_adv_inst}]
if {[llength $mmcm] != 1} {error "ambiguous physical clock generator"}
if {[get_property REF_NAME $mmcm] ne "MMCME4_ADV"} {error "wrong primitive"}
if {[get_property CLKOUT0_DIVIDE_F $mmcm] != 24.0 || [get_property CLKFBOUT_MULT_F $mmcm] != 4.0 || [get_property DIVCLK_DIVIDE $mmcm] != 1} {error "unexpected original clock configuration"}
set pins [get_pins -hier -filter {NAME =~ *RationalClockBridge_clocks_0_buffer/O}]
if {[llength $pins] != 1} {error "target buffer absent/ambiguous"}
set target [get_clocks -of_objects $pins]
if {[llength $target] != 1 || abs([get_property PERIOD $target] - 19.998) > 0.001} {error "original target clock changed"}
set target_name [get_property NAME $target]
set original_registers [lsort [get_property NAME [all_registers -clock $target]]]
set original_cells [llength [get_cells -hier]]
set original_nets [llength [get_nets -hier]]
set clock_periods [dict create]
foreach c [get_clocks] {dict set clock_periods [get_property NAME $c] [get_property PERIOD $c]}
report_clocks -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-hostclock-probe-r2-20261112/before-clocks.rpt}
set fp [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-hostclock-probe-r2-20261112/before-mmcm.rpt} w]
foreach property [lsort [list_property $mmcm]] {puts $fp "$property = [get_property $property $mmcm]"}
close $fp
report_timing_summary -report_unconstrained -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-hostclock-probe-r2-20261112/before-timing.rpt}
# Change the actual physical MMCM divider. Do not alter timing constraints,
# target RTL, bridge clock ratios, PCIe/MIG clocks, or start a router.
set_property CLKOUT0_DIVIDE_F 30.0 $mmcm
update_timing
set target [get_clocks -of_objects $pins]
set period [get_property PERIOD $target]
if {[llength $target] != 1 || abs($period - 24.9975) > 0.002} {error "actual clock did not follow MMCM divider"}
if {$original_registers ne [lsort [get_property NAME [all_registers -clock $target]]]} {error "target register clock membership changed"}
if {$original_cells != [llength [get_cells -hier]] || $original_nets != [llength [get_nets -hier]]} {error "netlist topology changed"}
foreach c [get_clocks] {
  set name [get_property NAME $c]
  if {![dict exists $clock_periods $name]} {error "unexpected new clock $name"}
  if {$name ne $target_name && abs([get_property PERIOD $c] - [dict get $clock_periods $name]) > 0.0001} {error "unrelated shell clock changed: $name"}
}
set fp [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-hostclock-probe-r2-20261112/after-mmcm.rpt} w]
foreach property [lsort [list_property $mmcm]] {puts $fp "$property = [get_property $property $mmcm]"}
close $fp
report_clocks -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-hostclock-probe-r2-20261112/after-clocks.rpt}
report_timing_summary -report_unconstrained -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-hostclock-probe-r2-20261112/after-timing.rpt}
report_timing -max_paths 20 -delay_type max -nets -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-hostclock-probe-r2-20261112/after-setup.rpt}
report_timing -max_paths 20 -delay_type min -nets -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-hostclock-probe-r2-20261112/after-hold.rpt}
report_route_status -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-hostclock-probe-r2-20261112/after-route.rpt}
report_drc -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-hostclock-probe-r2-20261112/after-drc.rpt}
check_timing -verbose -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-hostclock-probe-r2-20261112/after-check-timing.rpt}
set skew [report_bus_skew -return_string -no_detailed_paths -warn_on_violation]
set f [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-hostclock-probe-r2-20261112/after-bus-skew.rpt} w]; puts $f $skew; close $f
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-hostclock-probe-r2-20261112/host40-probe.dcp}
set setup [get_timing_paths -max_paths 1 -delay_type max]
set hold [get_timing_paths -max_paths 1 -delay_type min]
if {![llength $setup] || ![llength $hold]} {error "timing paths absent"}
puts "EC_SVB_ACTUAL_HOST_CLOCK_PROBE_COMPLETE divider=30 period=$period WNS=[get_property SLACK $setup] WHS=[get_property SLACK $hold] registers=[llength $original_registers]"
puts "NOT_A_CERTIFICATE_NO_BITSTREAM_NO_FPGA_IO"
exit 0
