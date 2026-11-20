set_param general.maxThreads 1
proc OPTRACE {args} {}
  create_project -in_memory -part xcu280-fsvh2892-2L-e
  set_property board_part_repo_paths {/data1/gzh/EC/firesim/dac2026/deps/boards} [current_project]
  set_property board_part xilinx.com:au280:part0:1.1 [current_project]
  set_property design_mode GateLvl [current_fileset]
  set_param project.singleFileAddWarning.threshold 0
  set_property XPM_LIBRARIES {XPM_CDC XPM_FIFO XPM_MEMORY} [current_project]
  add_files -quiet /data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/vivado_proj/firesim.runs/synth_1/design_1_wrapper.dcp
  set_msg_config -source 4 -id {BD 41-1661} -limit 0
  set_param project.isImplRun true
  add_files /data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/vivado_proj/firesim.srcs/sources_1/bd/design_1/design_1.bd
  set_param project.isImplRun false
puts "===SHELL_FILES_BEGIN==="
foreach f [get_files -all] {puts "FILE=$f TYPE=[get_property FILE_TYPE $f] IMPL=[get_property USED_IN_IMPLEMENTATION $f]"}
puts "===CONSTRAINT_ORDER_BEGIN==="
foreach f [get_files -compile_order constraints -used_in implementation] {puts "XDC=$f REF=[get_property SCOPED_TO_REF $f] CELLS=[get_property SCOPED_TO_CELLS $f] ORDER=[get_property PROCESSING_ORDER $f]"}
puts "SHELL_PROJECT_ONLY_INVENTORY_COMPLETE_NO_LINK_SYNTH_OPT_ROUTE_DEVICE"
exit 0
