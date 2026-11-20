set_param general.maxThreads 2
open_checkpoint {/var/tmp/guozh-ec-rtl-timing-r1-20261115/module-vivado/GH_FIFO_SC_Reference/routed.dcp}
set sources [all_registers -output_pins]
set sinks [all_registers -data_pins]
report_timing -from $sources -to $sinks -delay_type max -max_paths 20 -input_pins -nets -file {/var/tmp/guozh-ec-rtl-timing-r1-20261115/module-paths/GH_FIFO_SC_Reference-reg2reg-setup.rpt}
report_timing -from $sources -to $sinks -delay_type min -max_paths 20 -input_pins -nets -file {/var/tmp/guozh-ec-rtl-timing-r1-20261115/module-paths/GH_FIFO_SC_Reference-reg2reg-hold.rpt}
set f [open {/var/tmp/guozh-ec-rtl-timing-r1-20261115/module-paths/ddr-site-geometry.txt} w]
foreach name {SLICE_X121Y66 SLICE_X122Y76 SLICE_X118Y74 SLICE_X119Y72 SLICE_X123Y67} {
    set site [get_sites -quiet $name]
    if {[llength $site] != 1} {error "historical DDR data-path site absent"}
    puts $f "$name SLR=[get_slrs -quiet -of_objects $site] CLOCK_REGION=[get_clock_regions -quiet -of_objects $site]"
}
close $f
close_design
open_checkpoint {/var/tmp/guozh-ec-rtl-timing-r1-20261115/module-vivado/GH_FIFO_SC/routed.dcp}
set sources [all_registers -output_pins]
set sinks [all_registers -data_pins]
report_timing -from $sources -to $sinks -delay_type max -max_paths 20 -input_pins -nets -file {/var/tmp/guozh-ec-rtl-timing-r1-20261115/module-paths/GH_FIFO_SC-reg2reg-setup.rpt}
report_timing -from $sources -to $sinks -delay_type min -max_paths 20 -input_pins -nets -file {/var/tmp/guozh-ec-rtl-timing-r1-20261115/module-paths/GH_FIFO_SC-reg2reg-hold.rpt}
close_design
puts EC_MODULE_INTERNAL_PATH_EXTRACTION_COMPLETE
exit 0
