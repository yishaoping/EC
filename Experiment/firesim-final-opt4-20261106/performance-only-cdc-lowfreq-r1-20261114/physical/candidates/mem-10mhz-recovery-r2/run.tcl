set_param general.maxThreads 8
set out {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/performance-only-cdc-lowfreq-r1-20261114/physical/candidates/mem-10mhz-recovery-r2}
proc stage {name script} {
    global out
    set f [open "$out/current-stage.txt" w]; puts $f $name; close $f
    puts "EC_PHYSICAL_STAGE $name"
    uplevel 1 $script
}
set ec_frequency 10
set ec_resume_checkpoint [exec /usr/bin/env -u PYTHONHOME -u PYTHONPATH -u LD_LIBRARY_PATH -u LD_PRELOAD /usr/bin/python3 -I {/data1/gzh/EC/firesim/final-opt4-20261106/candidates/performance-only-cdc-lowfreq-r1-20261114/select_route_checkpoint.py} $out]
stage open {open_checkpoint $ec_resume_checkpoint}
if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "unresolved functional cells"}
stage clock_contract {source {/data1/gzh/EC/firesim/final-opt4-20261106/candidates/performance-only-cdc-lowfreq-r1-20261114/host-clock.tcl}}
error "strict routing flow returned without final bitstream gate"
