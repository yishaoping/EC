set_param general.maxThreads 2
read_verilog tiny.v
synth_design -top Tiny -part xcu280-fsvh2892-2L-e -mode out_of_context
create_clock -name pcie_refclk_clk_p -period 10 [get_ports ca]
create_clock -name {GTYE4_CHANNEL_TXOUTCLK[3]_3} -period 2 [get_ports cb]
set from [get_clocks -filter {NAME == "pcie_refclk_clk_p"}]
set to [get_clocks -filter {NAME == "GTYE4_CHANNEL_TXOUTCLK[3]_3"}]
set pre [llength [get_timing_paths -from $from -to $to -max_paths 1]]
if {$pre != 1} {error "negative control lacks a timed CDC path"}
write_checkpoint -force original.dcp
read_xdc old.xdc
set old_count [llength [get_timing_paths -from $from -to $to -max_paths 1]]
write_xdc -force old-effective.xdc
report_exceptions -file old-exceptions.rpt
close_design
open_checkpoint original.dcp
source {/data1/gzh/EC/firesim/final-opt4-20261106/Opt4-performance-only-rtl-timing-r1-20261115/candidates/rtl-timing-r1/clock-group-replay-no-concat.tcl}
set cmd [ec_exact_clock_groups {{pcie_refclk_clk_p} {{GTYE4_CHANNEL_TXOUTCLK[3]_3}}}]
set f [open new.xdc w];puts $f $cmd;close $f
read_xdc new.xdc
set from [get_clocks -filter {NAME == "pcie_refclk_clk_p"}]
set to [get_clocks -filter {NAME == "GTYE4_CHANNEL_TXOUTCLK[3]_3"}]
set new_count [llength [get_timing_paths -from $from -to $to -max_paths 1]]
if {[get_property PERIOD $from] != 10 || [get_property PERIOD $to] != 2} {error "clock periods changed"}
write_xdc -force new-effective.xdc
report_exceptions -file new-exceptions.rpt
set f [open old-exceptions.rpt r];set old_exceptions [read $f];close $f
set f [open new-exceptions.rpt r];set new_exceptions [read $f];close $f
if {[string first {No valid timing exceptions found} $old_exceptions] < 0} {error "old concat negative control unexpectedly applied"}
if {[regexp -all {clock_group\s+clock_group} $new_exceptions] != 2} {error "new exact clock groups not present in exception database"}
set f [open result.txt w]
puts $f "CONSTRAINT_READ_XDC_SYNTAX_PASS old_concat_valid_exceptions=0 new_exact_filter_clock_group_directions=2 clock_periods_unchanged=true"
puts $f "Explicit-from/to path query counts (not a false-path admission test): before=$pre old=$old_count new=$new_count"
close $f
puts EC_CONSTRAINT_TINY_EXPERIMENT_COMPLETE
exit 0
