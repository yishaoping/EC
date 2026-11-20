set_param general.maxThreads 4
read_verilog {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-index-share-r1-bind2-20261111/address/PackageAddressStats.v}
synth_design -top PackageAddressStats -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-index-share-r1-bind2-20261111/map-full-module/utilization.rpt}
report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-index-share-r1-bind2-20261111/map-full-module/hierarchical.rpt}
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-index-share-r1-bind2-20261111/map-full-module/module.dcp}
exit 0
