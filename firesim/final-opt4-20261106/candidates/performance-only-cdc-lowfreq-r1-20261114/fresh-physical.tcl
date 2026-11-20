# Full shell post-opt input only. No synthesis, failed route or old placement.
set_param general.maxThreads 8
set out {@OUT@}
proc stage {name script} {
    global out
    set f [open "$out/current-stage.txt" w]; puts $f $name; close $f
    puts "EC_PHYSICAL_STAGE $name"
    uplevel 1 $script
}
stage open {open_checkpoint {@CHECKPOINT@}}
if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {
    error "unresolved functional cells"
}
set ec_frequency 10
set ec_resume_checkpoint {}
stage clock_contract {source {@CLOCK@}}
puts "EC_FRESH_CDC_MEM_POSTOPT_NO_PRIOR_PLACE_OR_ROUTE"
stage spread {place_design -directive SSI_SpreadLogic_high}
write_checkpoint -force "$out/placed.dcp"
report_utilization -slr -file "$out/per-slr-placed.rpt"
report_design_analysis -congestion -file "$out/congestion-placed.rpt"
report_timing -delay_type max -max_paths 5 -path_type full_clock_expanded -file "$out/setup-placed.rpt"

# Replicate only measured allocation/CDC control drivers, never clocks or
# synchronizer cells. Do not run a global high-fanout report before routing.
set candidates [get_nets -hier -quiet -filter {NAME =~ *packet_alloc_valid* || NAME =~ *ghm_u_data_cdc*source_valid*}]
set ranked {}
foreach n $candidates {
    set loads [get_pins -leaf -quiet -of_objects $n -filter {DIRECTION == IN}]
    if {[llength $loads] < 1024} {continue}
    set drivers [get_cells -quiet -of_objects [get_pins -leaf -quiet -of_objects $n -filter {DIRECTION == OUT}]]
    if {[llength $drivers] != 1} {continue}
    set driver [lindex $drivers 0]
    if {[regexp {^(BUFG|BUFH|MMCME|PLLE)} [get_property REF_NAME $driver]]} {continue}
    if {[string tolower [get_property -quiet ASYNC_REG $driver]] in {true 1}} {continue}
    lappend ranked [list [llength $loads] $n]
}
set ranked [lrange [lsort -integer -decreasing -index 0 $ranked] 0 15]
set f [open "$out/targeted-fanout-inputs.txt" w]
set hot_nets {}
foreach pair $ranked {
    puts $f "loads=[lindex $pair 0] net=[lindex $pair 1]"
    lappend hot_nets [lindex $pair 1]
}
close $f
if {[llength $hot_nets]} {
    if {[catch {stage targeted_fanout {phys_opt_design -force_replication_on_nets $hot_nets}} message]} {
        set f [open "$out/targeted-fanout-command-error.txt" w]; puts $f $message; close $f
        puts "EC_TARGETED_REPLICATION_DECLINED $message"
    }
}
stage physical_repair {phys_opt_design -fanout_opt -placement_opt -slr_crossing_opt}
write_checkpoint -force "$out/physopt.dcp"
report_utilization -slr -file "$out/per-slr-physopt.rpt"
source {@ROUTING@}
error "strict routing flow returned without final bitstream gate"
