set_param general.maxThreads 2
read_verilog {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-installed-image-proof-r1-20261111/candidate/InstalledCandidate.v}
synth_design -mode out_of_context -top InstalledCandidate -part xcu280-fsvh2892-2L-e
set bb [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]
if {[llength $bb]} {error "unresolved storage blackbox"}
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-installed-image-map-r1-20261111/candidate/utilization.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-installed-image-map-r1-20261111/candidate/module.dcp}
exit 0
