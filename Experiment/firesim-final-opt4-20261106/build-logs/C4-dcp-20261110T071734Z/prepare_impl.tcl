set_param general.maxThreads 2
set_param board.repoPaths {/data1/gzh/EC/firesim/dac2026/deps/boards}
open_project {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/vivado_proj/firesim.xpr}
set impl [get_runs impl_1]
foreach step {OPT_DESIGN PLACE_DESIGN ROUTE_DESIGN PHYS_OPT_DESIGN POST_ROUTE_PHYS_OPT_DESIGN} {
  set_property STEPS.$step.ARGS.DIRECTIVE Explore $impl
}
set_property STEPS.PHYS_OPT_DESIGN.IS_ENABLED true $impl
launch_runs $impl -to_step route_design -scripts_only
close_project
exit 0
