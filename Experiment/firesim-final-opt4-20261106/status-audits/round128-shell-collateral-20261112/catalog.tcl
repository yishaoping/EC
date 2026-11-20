set_param general.maxThreads 1
create_project -in_memory -part xcu280-fsvh2892-2L-e
set_property design_mode GateLvl [current_fileset]
set_property ip_output_repo {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/vivado_proj/firesim.cache/ip} [current_project]
set_property ip_cache_permissions read [current_project]
set_property XPM_LIBRARIES {XPM_CDC XPM_FIFO XPM_MEMORY} [current_project]
add_files -quiet {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/vivado_proj/firesim.runs/synth_1/design_1_wrapper.dcp}
set_param project.isImplRun true
add_files {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/vivado_proj/firesim.srcs/sources_1/bd/design_1/design_1.bd}
set_param project.isImplRun false
report_compile_order -constraints -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/round128-shell-collateral-20261112/constraint-order.rpt}
set fp [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/round128-shell-collateral-20261112/file-inventory.tsv} w]
foreach f [lsort [get_files -all -quiet]] {
 puts $fp "FILE	$f"
 foreach prop {FILE_TYPE USED_IN_IMPLEMENTATION USED_IN_SYNTHESIS PROCESSING_ORDER SCOPED_TO_REF SCOPED_TO_CELLS PARENT_COMPOSITE_FILE} {
  if {[lsearch -exact [list_property $f] $prop]>=0} {puts $fp "$prop	[get_property $prop $f]"}
 }
}
close $fp
puts "COLLATERAL_CATALOG_COMPLETE_NO_LINK_SYNTH_OPT_ROUTE_DEVICE"
exit 0
