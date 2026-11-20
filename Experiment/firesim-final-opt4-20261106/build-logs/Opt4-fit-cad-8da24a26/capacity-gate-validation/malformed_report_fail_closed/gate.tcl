proc report_utilization {args} {}
proc report_drc {args} {}

  report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-cad-8da24a26/capacity-gate-validation/malformed_report_fail_closed/top-postopt-utilization.rpt}
  report_utilization -hierarchical -hierarchical_depth 30 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-cad-8da24a26/capacity-gate-validation/malformed_report_fail_closed/top-postopt-hierarchical.rpt}
  report_drc -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-cad-8da24a26/capacity-gate-validation/malformed_report_fail_closed/top-postopt-drc.rpt}
  set f [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-cad-8da24a26/capacity-gate-validation/malformed_report_fail_closed/top-postopt-utilization.rpt} r]
  set text [read $f]; close $f
  set exceeded {}; set seen {}
  foreach line [split $text \n] {
    set a [split $line |]
    if {[llength $a] < 7} {continue}
    set kind [string trimright [string trim [lindex $a 1]] *]
    if {$kind ni {"CLB LUTs" "CLB Registers" "CARRY8" "DSPs" "Block RAM Tile" "URAM"} || [dict exists $seen $kind]} {continue}
    set used [string map {, {}} [string trim [lindex $a 2]]]
    set avail [string map {, {}} [string trim [lindex $a 5]]]
    if {![string is double -strict $used] || ![string is double -strict $avail] || $avail <= 0} {continue}
    dict set seen $kind 1
    puts "EC_FIT_CAPACITY kind=$kind used=$used available=$avail"
    if {$used > $avail} {lappend exceeded $kind}
  }
  if {[dict size $seen] < 5} {error "capacity report parse incomplete"}
  set f [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-cad-8da24a26/capacity-gate-validation/malformed_report_fail_closed/capacity.complete} w]
  if {[llength $exceeded]} {puts $f "NOT_FIT_POSTOPT $exceeded";close $f;error "NOT FIT; saved optimized checkpoint, no place/route: $exceeded"}
  puts $f "CAPACITY_FITS_POSTOPT_TIMING_PENDING";close $f

puts "GATE_RETURNED_SUCCESS"
