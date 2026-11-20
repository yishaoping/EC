set_param general.maxThreads 8
open_checkpoint {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/vivado_proj/firesim.runs/synth_1/design_1_wrapper.dcp}
set target [get_cells -hier -quiet -filter {REF_NAME == design_1_axi_clock_converter_0_0}]
if {[llength $target] != 1} {error "shell cell match design_1_axi_clock_converter_0_0: $target"}
read_checkpoint -cell $target {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/reused-checkpoints/design_1_axi_clock_converter_0_0.dcp}
set target [get_cells -hier -quiet -filter {REF_NAME == design_1_axi_tieoff_master_0_0}]
if {[llength $target] != 1} {error "shell cell match design_1_axi_tieoff_master_0_0: $target"}
read_checkpoint -cell $target {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/reused-checkpoints/design_1_axi_tieoff_master_0_0.dcp}
set target [get_cells -hier -quiet -filter {REF_NAME == design_1_axi_dwidth_converter_0_0}]
if {[llength $target] != 1} {error "shell cell match design_1_axi_dwidth_converter_0_0: $target"}
read_checkpoint -cell $target {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/reused-checkpoints/design_1_axi_dwidth_converter_0_0.dcp}
set target [get_cells -hier -quiet -filter {REF_NAME == design_1_ddr4_0_0}]
if {[llength $target] != 1} {error "shell cell match design_1_ddr4_0_0: $target"}
read_checkpoint -cell $target {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/reused-checkpoints/design_1_ddr4_0_0.dcp}
set target [get_cells -hier -quiet -filter {REF_NAME == design_1_clk_wiz_0_0}]
if {[llength $target] != 1} {error "shell cell match design_1_clk_wiz_0_0: $target"}
read_checkpoint -cell $target {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/reused-checkpoints/design_1_clk_wiz_0_0.dcp}
set target [get_cells -hier -quiet -filter {REF_NAME == design_1_proc_sys_reset_1_0}]
if {[llength $target] != 1} {error "shell cell match design_1_proc_sys_reset_1_0: $target"}
read_checkpoint -cell $target {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/reused-checkpoints/design_1_proc_sys_reset_1_0.dcp}
set target [get_cells -hier -quiet -filter {REF_NAME == design_1_util_ds_buf_0}]
if {[llength $target] != 1} {error "shell cell match design_1_util_ds_buf_0: $target"}
read_checkpoint -cell $target {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/reused-checkpoints/design_1_util_ds_buf_0.dcp}
set target [get_cells -hier -quiet -filter {REF_NAME == design_1_resetn_inv_0_0}]
if {[llength $target] != 1} {error "shell cell match design_1_resetn_inv_0_0: $target"}
read_checkpoint -cell $target {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/reused-checkpoints/design_1_resetn_inv_0_0.dcp}
set target [get_cells -hier -quiet -filter {REF_NAME == design_1_axi_clock_converter_1_0}]
if {[llength $target] != 1} {error "shell cell match design_1_axi_clock_converter_1_0: $target"}
read_checkpoint -cell $target {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/reused-checkpoints/design_1_axi_clock_converter_1_0.dcp}
set target [get_cells -hier -quiet -filter {REF_NAME == design_1_proc_sys_reset_0_0}]
if {[llength $target] != 1} {error "shell cell match design_1_proc_sys_reset_0_0: $target"}
read_checkpoint -cell $target {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/reused-checkpoints/design_1_proc_sys_reset_0_0.dcp}
set target [get_cells -hier -quiet -filter {REF_NAME == design_1_xdma_0_0}]
if {[llength $target] != 1} {error "shell cell match design_1_xdma_0_0: $target"}
read_checkpoint -cell $target {/data1/gzh/EC/firesim/final-opt4-20261106/dcp-work/C4-dcp-20261110T071734Z/reused-checkpoints/design_1_xdma_0_0.dcp}
set f [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-20261110/shell-link-diagnostic/black-boxes.txt} w]
foreach c [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}] {
puts $f "CELL=$c REF_NAME=[get_property REF_NAME $c] IS_PRIMITIVE=[get_property IS_PRIMITIVE $c]"
report_property -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-20261110/shell-link-diagnostic/black-box-properties.rpt} -append $c
}
close $f
write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/C4-capacity-20261110/shell-link-diagnostic/shell-linked.dcp}
puts "EC_SHELL_LINK_DIAGNOSTIC_COMPLETE_NOT_FORMAL_BUILD"
exit 0
