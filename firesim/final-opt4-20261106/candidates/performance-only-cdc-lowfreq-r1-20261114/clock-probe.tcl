set_param general.maxThreads 2
set out {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/performance-only-cdc-lowfreq-r1-20261114/clock-probe}
open_checkpoint {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-performance-only-support-r6-20261113/project/builds/cad-6fada307/vivado_proj/firesim.runs/impl_1/design_1_wrapper_opt.dcp}
set ec_frequency 15
source {/data1/gzh/EC/firesim/final-opt4-20261106/candidates/performance-only-cdc-lowfreq-r1-20261114/host-clock.tcl}
report_methodology -checks {TIMING-4 TIMING-27 TIMING-54} -file "$out/clock-methodology.rpt"
set f [open "$out/clock-methodology.rpt" r]; set report [read $f]; close $f
if {[regexp {\|\s*(Error|Critical Warning)\s*\|} $report]} {error "clock/scope methodology remains unresolved"}
set f [open "$out/complete" w];puts $f PASS_FULL_SHELL_CLOCK_AND_SCOPE_REPLAY;close $f
exit 0
