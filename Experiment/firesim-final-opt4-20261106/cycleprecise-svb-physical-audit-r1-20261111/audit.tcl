set_param general.maxThreads 2
open_checkpoint {/data1/gzh/EC/firesim/final-opt4-20261106/routes/svb-physical-audit-r1-20261111/snapshot-physopt.dcp}
puts "EC_AUDIT_DESIGN [current_design]"
report_clocks -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-physical-audit-r1-20261111/physical-clocks.rpt}
check_timing -verbose -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-physical-audit-r1-20261111/check-timing.rpt}
report_timing_summary -report_unconstrained -max_paths 10 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-physical-audit-r1-20261111/timing-summary.rpt}
report_timing -max_paths 30 -input_pins -nets -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-physical-audit-r1-20261111/timing-paths.rpt}
report_high_fanout_nets -max_nets 40 -timing -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-physical-audit-r1-20261111/high-fanout.rpt}
report_utilization -slr -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-physical-audit-r1-20261111/slr-utilization.rpt}
report_design_analysis -congestion -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-physical-audit-r1-20261111/congestion.rpt}
set fp [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-physical-audit-r1-20261111/clock-targets.tsv} w]
foreach pin [get_pins -hier -quiet -filter {NAME =~ *RationalClockBridge_clocks_0_buffer/O}] {
  set clocks [get_clocks -of_objects $pin]
  puts $fp "$pin	$clocks"
  foreach c $clocks {
    puts $fp "period=[get_property PERIOD $c]	registers=[llength [all_registers -clock $c]]"
  }
}
close $fp
set fp [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-physical-audit-r1-20261111/pblocks.tsv} w]
foreach p [get_pblocks -quiet] {
  puts $fp "$p	[get_property GRID_RANGES $p]	cells=[llength [get_cells -quiet -of_objects $p]]"
}
close $fp
puts "EC_SVB_PHYSICAL_AUDIT_COMPLETE"
exit 0
