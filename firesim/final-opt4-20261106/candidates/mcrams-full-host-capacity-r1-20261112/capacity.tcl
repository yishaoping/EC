set_param general.maxThreads 8
read_verilog -sv {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-dcache-owner-system-r1-20261111/goldengate/FireSim-generated.sv}
set f [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-full-host-capacity-r1-20261112/phase.txt} w]; puts $f synth_design; close $f
synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e
set bb [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]
if {[llength $bb]} {error "Unresolved complete host blackboxes: $bb"}
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-full-host-capacity-r1-20261112/synth-utilization.rpt}
report_utilization -hierarchical -hierarchical_depth 25 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-full-host-capacity-r1-20261112/synth-hierarchical.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-full-host-capacity-r1-20261112/synth.dcp}
set f [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-full-host-capacity-r1-20261112/phase.txt} w]; puts $f opt_design; close $f
opt_design
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-full-host-capacity-r1-20261112/postopt-utilization.rpt}
report_utilization -hierarchical -hierarchical_depth 25 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-full-host-capacity-r1-20261112/postopt-hierarchical.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-full-host-capacity-r1-20261112/postopt.dcp}
set f [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-full-host-capacity-r1-20261112/phase.txt} w]; puts $f complete; close $f
puts "FULL_HOST_POSTOPT_CAPACITY_REPORT_COMPLETE_NO_PLACEMENT"
exit 0
