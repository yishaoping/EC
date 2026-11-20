set_param general.maxThreads 2
set out {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/performance-only-cdc-lowfreq-r1-20261114/clock-ooc}
file mkdir $out
open_checkpoint {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/reused-checkpoints/design_1_clk_wiz_0_0.dcp}
set mmcm [get_cells -hier -filter {REF_NAME == MMCME4_ADV}]
if {[llength $mmcm]!=1} {error "expected one host MMCM"}
set before [get_property CLKOUT0_DIVIDE_F $mmcm]
if {$before!=24 || [get_property CLKFBOUT_MULT_F $mmcm]!=4 || [get_property DIVCLK_DIVIDE $mmcm]!=1} {error "unknown clock configuration"}
report_property -all $mmcm -file "$out/mmcm-before.txt"
create_clock -name host_input_300MHz -period 3.333 [get_ports clk_in1]
report_clocks -file "$out/clocks-50.rpt"
foreach freq {15 10} divide {80.0 120.0} {
  set_property CLKOUT0_DIVIDE_F $divide $mmcm
  update_timing
  set pin [get_pins -of_objects $mmcm -filter {REF_PIN_NAME == CLKOUT0}]
  set clk [get_clocks -of_objects $pin]
  if {[llength $clk]!=1} {error "no unique derived host clock"}
  set period [get_property PERIOD $clk]
  if {abs($period-(1000.0/$freq))>0.05} {error "MMCM change not reflected in generated clock $period"}
  puts "EC_REAL_CLOCK_TEST frequency_nominal=$freq divide=[get_property CLKOUT0_DIVIDE_F $mmcm] generated_period_ns=$period generated_MHz=[expr {1000.0/$period}]"
  report_clocks -file "$out/clocks-$freq.rpt"
  report_drc -file "$out/drc-$freq.rpt"
  write_checkpoint -force "$out/clock-$freq.dcp"
  write_verilog -force "$out/clock-$freq.v"
  write_xdc -force "$out/clock-$freq.xdc"
}
set f [open "$out/complete" w];puts $f PASS_MMCM_PROPERTY_AND_DERIVED_CLOCK;close $f
exit 0
