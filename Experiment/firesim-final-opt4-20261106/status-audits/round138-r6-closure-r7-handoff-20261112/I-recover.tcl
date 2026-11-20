set_param general.maxThreads 2
open_checkpoint {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/sealed-source.dcp}
if {[get_property PART [current_design]] ne "xcu280-fsvh2892-2L-e"} {error "wrong device"}
if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "unresolved IP"}

proc clock_contract {} {
  set mmcm [get_cells -hier -filter {NAME == design_1_i/clk_wiz_0/inst/mmcme4_adv_inst}]
  if {[llength $mmcm]!=1 || [get_property REF_NAME $mmcm] ne "MMCME4_ADV" || [get_property CLKOUT0_DIVIDE_F $mmcm]!=30.0 || [get_property CLKFBOUT_MULT_F $mmcm]!=4.0 || [get_property DIVCLK_DIVIDE $mmcm]!=1} {error "host40 MMCM changed"}
  set expected [dict create {dbg_hub/inst/BSCANID.u_xsdbm_id/SWITCH_N_EXT_BSCAN.bscan_inst/SERIES7_BSCAN.bscan_inst/INTERNAL_TCK} 50.0 {design_1_i/clk_wiz_0/inst/clk_in1} 3.333 {design_1_i/xdma_0/inst/pcie4c_ip_i/inst/design_1_xdma_0_0_pcie4c_ip_gt_top_i/diablo_gt.diablo_gt_phy_wrapper/gt_wizard.gtwizard_top_i/design_1_xdma_0_0_pcie4c_ip_gt_i/inst/gen_gtwizard_gtye4_top.design_1_xdma_0_0_pcie4c_ip_gt_gtwizard_gtye4_inst/gen_gtwizard_gtye4.gen_cpll_cal_gtye4.gen_cpll_cal_inst[0].gen_inst_cpll_cal.gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_inst/gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_tx_i/bufg_gt_txoutclkmon_inst/O} 8.0 {design_1_i/xdma_0/inst/pcie4c_ip_i/inst/design_1_xdma_0_0_pcie4c_ip_gt_top_i/diablo_gt.diablo_gt_phy_wrapper/gt_wizard.gtwizard_top_i/design_1_xdma_0_0_pcie4c_ip_gt_i/inst/gen_gtwizard_gtye4_top.design_1_xdma_0_0_pcie4c_ip_gt_gtwizard_gtye4_inst/gen_gtwizard_gtye4.gen_cpll_cal_gtye4.gen_cpll_cal_inst[10].gen_inst_cpll_cal.gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_inst/gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_tx_i/bufg_gt_txoutclkmon_inst/O} 8.0 {design_1_i/xdma_0/inst/pcie4c_ip_i/inst/design_1_xdma_0_0_pcie4c_ip_gt_top_i/diablo_gt.diablo_gt_phy_wrapper/gt_wizard.gtwizard_top_i/design_1_xdma_0_0_pcie4c_ip_gt_i/inst/gen_gtwizard_gtye4_top.design_1_xdma_0_0_pcie4c_ip_gt_gtwizard_gtye4_inst/gen_gtwizard_gtye4.gen_cpll_cal_gtye4.gen_cpll_cal_inst[11].gen_inst_cpll_cal.gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_inst/gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_tx_i/bufg_gt_txoutclkmon_inst/O} 8.0 {design_1_i/xdma_0/inst/pcie4c_ip_i/inst/design_1_xdma_0_0_pcie4c_ip_gt_top_i/diablo_gt.diablo_gt_phy_wrapper/gt_wizard.gtwizard_top_i/design_1_xdma_0_0_pcie4c_ip_gt_i/inst/gen_gtwizard_gtye4_top.design_1_xdma_0_0_pcie4c_ip_gt_gtwizard_gtye4_inst/gen_gtwizard_gtye4.gen_cpll_cal_gtye4.gen_cpll_cal_inst[12].gen_inst_cpll_cal.gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_inst/gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_tx_i/bufg_gt_txoutclkmon_inst/O} 8.0 {design_1_i/xdma_0/inst/pcie4c_ip_i/inst/design_1_xdma_0_0_pcie4c_ip_gt_top_i/diablo_gt.diablo_gt_phy_wrapper/gt_wizard.gtwizard_top_i/design_1_xdma_0_0_pcie4c_ip_gt_i/inst/gen_gtwizard_gtye4_top.design_1_xdma_0_0_pcie4c_ip_gt_gtwizard_gtye4_inst/gen_gtwizard_gtye4.gen_cpll_cal_gtye4.gen_cpll_cal_inst[13].gen_inst_cpll_cal.gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_inst/gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_tx_i/bufg_gt_txoutclkmon_inst/O} 8.0 {design_1_i/xdma_0/inst/pcie4c_ip_i/inst/design_1_xdma_0_0_pcie4c_ip_gt_top_i/diablo_gt.diablo_gt_phy_wrapper/gt_wizard.gtwizard_top_i/design_1_xdma_0_0_pcie4c_ip_gt_i/inst/gen_gtwizard_gtye4_top.design_1_xdma_0_0_pcie4c_ip_gt_gtwizard_gtye4_inst/gen_gtwizard_gtye4.gen_cpll_cal_gtye4.gen_cpll_cal_inst[14].gen_inst_cpll_cal.gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_inst/gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_tx_i/bufg_gt_txoutclkmon_inst/O} 8.0 {design_1_i/xdma_0/inst/pcie4c_ip_i/inst/design_1_xdma_0_0_pcie4c_ip_gt_top_i/diablo_gt.diablo_gt_phy_wrapper/gt_wizard.gtwizard_top_i/design_1_xdma_0_0_pcie4c_ip_gt_i/inst/gen_gtwizard_gtye4_top.design_1_xdma_0_0_pcie4c_ip_gt_gtwizard_gtye4_inst/gen_gtwizard_gtye4.gen_cpll_cal_gtye4.gen_cpll_cal_inst[15].gen_inst_cpll_cal.gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_inst/gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_tx_i/bufg_gt_txoutclkmon_inst/O} 8.0 {design_1_i/xdma_0/inst/pcie4c_ip_i/inst/design_1_xdma_0_0_pcie4c_ip_gt_top_i/diablo_gt.diablo_gt_phy_wrapper/gt_wizard.gtwizard_top_i/design_1_xdma_0_0_pcie4c_ip_gt_i/inst/gen_gtwizard_gtye4_top.design_1_xdma_0_0_pcie4c_ip_gt_gtwizard_gtye4_inst/gen_gtwizard_gtye4.gen_cpll_cal_gtye4.gen_cpll_cal_inst[1].gen_inst_cpll_cal.gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_inst/gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_tx_i/bufg_gt_txoutclkmon_inst/O} 8.0 {design_1_i/xdma_0/inst/pcie4c_ip_i/inst/design_1_xdma_0_0_pcie4c_ip_gt_top_i/diablo_gt.diablo_gt_phy_wrapper/gt_wizard.gtwizard_top_i/design_1_xdma_0_0_pcie4c_ip_gt_i/inst/gen_gtwizard_gtye4_top.design_1_xdma_0_0_pcie4c_ip_gt_gtwizard_gtye4_inst/gen_gtwizard_gtye4.gen_cpll_cal_gtye4.gen_cpll_cal_inst[2].gen_inst_cpll_cal.gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_inst/gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_tx_i/bufg_gt_txoutclkmon_inst/O} 8.0 {design_1_i/xdma_0/inst/pcie4c_ip_i/inst/design_1_xdma_0_0_pcie4c_ip_gt_top_i/diablo_gt.diablo_gt_phy_wrapper/gt_wizard.gtwizard_top_i/design_1_xdma_0_0_pcie4c_ip_gt_i/inst/gen_gtwizard_gtye4_top.design_1_xdma_0_0_pcie4c_ip_gt_gtwizard_gtye4_inst/gen_gtwizard_gtye4.gen_cpll_cal_gtye4.gen_cpll_cal_inst[3].gen_inst_cpll_cal.gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_inst/gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_tx_i/bufg_gt_txoutclkmon_inst/O} 8.0 {design_1_i/xdma_0/inst/pcie4c_ip_i/inst/design_1_xdma_0_0_pcie4c_ip_gt_top_i/diablo_gt.diablo_gt_phy_wrapper/gt_wizard.gtwizard_top_i/design_1_xdma_0_0_pcie4c_ip_gt_i/inst/gen_gtwizard_gtye4_top.design_1_xdma_0_0_pcie4c_ip_gt_gtwizard_gtye4_inst/gen_gtwizard_gtye4.gen_cpll_cal_gtye4.gen_cpll_cal_inst[4].gen_inst_cpll_cal.gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_inst/gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_tx_i/bufg_gt_txoutclkmon_inst/O} 8.0 {design_1_i/xdma_0/inst/pcie4c_ip_i/inst/design_1_xdma_0_0_pcie4c_ip_gt_top_i/diablo_gt.diablo_gt_phy_wrapper/gt_wizard.gtwizard_top_i/design_1_xdma_0_0_pcie4c_ip_gt_i/inst/gen_gtwizard_gtye4_top.design_1_xdma_0_0_pcie4c_ip_gt_gtwizard_gtye4_inst/gen_gtwizard_gtye4.gen_cpll_cal_gtye4.gen_cpll_cal_inst[5].gen_inst_cpll_cal.gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_inst/gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_tx_i/bufg_gt_txoutclkmon_inst/O} 8.0 {design_1_i/xdma_0/inst/pcie4c_ip_i/inst/design_1_xdma_0_0_pcie4c_ip_gt_top_i/diablo_gt.diablo_gt_phy_wrapper/gt_wizard.gtwizard_top_i/design_1_xdma_0_0_pcie4c_ip_gt_i/inst/gen_gtwizard_gtye4_top.design_1_xdma_0_0_pcie4c_ip_gt_gtwizard_gtye4_inst/gen_gtwizard_gtye4.gen_cpll_cal_gtye4.gen_cpll_cal_inst[6].gen_inst_cpll_cal.gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_inst/gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_tx_i/bufg_gt_txoutclkmon_inst/O} 8.0 {design_1_i/xdma_0/inst/pcie4c_ip_i/inst/design_1_xdma_0_0_pcie4c_ip_gt_top_i/diablo_gt.diablo_gt_phy_wrapper/gt_wizard.gtwizard_top_i/design_1_xdma_0_0_pcie4c_ip_gt_i/inst/gen_gtwizard_gtye4_top.design_1_xdma_0_0_pcie4c_ip_gt_gtwizard_gtye4_inst/gen_gtwizard_gtye4.gen_cpll_cal_gtye4.gen_cpll_cal_inst[7].gen_inst_cpll_cal.gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_inst/gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_tx_i/bufg_gt_txoutclkmon_inst/O} 8.0 {design_1_i/xdma_0/inst/pcie4c_ip_i/inst/design_1_xdma_0_0_pcie4c_ip_gt_top_i/diablo_gt.diablo_gt_phy_wrapper/gt_wizard.gtwizard_top_i/design_1_xdma_0_0_pcie4c_ip_gt_i/inst/gen_gtwizard_gtye4_top.design_1_xdma_0_0_pcie4c_ip_gt_gtwizard_gtye4_inst/gen_gtwizard_gtye4.gen_cpll_cal_gtye4.gen_cpll_cal_inst[8].gen_inst_cpll_cal.gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_inst/gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_tx_i/bufg_gt_txoutclkmon_inst/O} 8.0 {design_1_i/xdma_0/inst/pcie4c_ip_i/inst/design_1_xdma_0_0_pcie4c_ip_gt_top_i/diablo_gt.diablo_gt_phy_wrapper/gt_wizard.gtwizard_top_i/design_1_xdma_0_0_pcie4c_ip_gt_i/inst/gen_gtwizard_gtye4_top.design_1_xdma_0_0_pcie4c_ip_gt_gtwizard_gtye4_inst/gen_gtwizard_gtye4.gen_cpll_cal_gtye4.gen_cpll_cal_inst[9].gen_inst_cpll_cal.gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_inst/gtwizard_ultrascale_v1_7_10_gtye4_cpll_cal_tx_i/bufg_gt_txoutclkmon_inst/O} 8.0 {design_1_i/xdma_0/inst/pcie4c_ip_i/inst/design_1_xdma_0_0_pcie4c_ip_gt_top_i/diablo_gt.diablo_gt_phy_wrapper/phy_clk_i/bufg_gt_intclk/O} 1000.0 {pcie_refclk_clk_p} 10.0 {sysclk0_clk_p} 9.996 {GTYE4_CHANNEL_QPLL0CLK[0]} 0.2 {GTYE4_CHANNEL_QPLL0CLK[0]_1} 0.2 {GTYE4_CHANNEL_QPLL0CLK[0]_2} 0.2 {GTYE4_CHANNEL_QPLL0CLK[0]_3} 0.2 {GTYE4_CHANNEL_QPLL0REFCLK[0]} 10.0 {GTYE4_CHANNEL_QPLL0REFCLK[0]_1} 10.0 {GTYE4_CHANNEL_QPLL0REFCLK[0]_2} 10.0 {GTYE4_CHANNEL_QPLL0REFCLK[0]_3} 10.0 {GTYE4_CHANNEL_QPLL1CLK[0]} 0.2 {GTYE4_CHANNEL_QPLL1CLK[0]_1} 0.2 {GTYE4_CHANNEL_QPLL1CLK[0]_2} 0.2 {GTYE4_CHANNEL_QPLL1CLK[0]_3} 0.2 {GTYE4_CHANNEL_QPLL1REFCLK[0]} 10.0 {GTYE4_CHANNEL_QPLL1REFCLK[0]_1} 10.0 {GTYE4_CHANNEL_QPLL1REFCLK[0]_2} 10.0 {GTYE4_CHANNEL_QPLL1REFCLK[0]_3} 10.0 {GTYE4_CHANNEL_TXOUTCLK[0]} 2.0 {GTYE4_CHANNEL_TXOUTCLK[0]_1} 2.0 {GTYE4_CHANNEL_TXOUTCLK[0]_2} 2.0 {GTYE4_CHANNEL_TXOUTCLK[0]_3} 2.0 {GTYE4_CHANNEL_TXOUTCLK[1]} 2.0 {GTYE4_CHANNEL_TXOUTCLK[1]_1} 2.0 {GTYE4_CHANNEL_TXOUTCLK[1]_2} 2.0 {GTYE4_CHANNEL_TXOUTCLK[1]_3} 2.0 {GTYE4_CHANNEL_TXOUTCLK[2]} 2.0 {GTYE4_CHANNEL_TXOUTCLK[2]_1} 2.0 {GTYE4_CHANNEL_TXOUTCLK[2]_2} 2.0 {GTYE4_CHANNEL_TXOUTCLK[2]_3} 2.0 {GTYE4_CHANNEL_TXOUTCLK[3]} 2.0 {GTYE4_CHANNEL_TXOUTCLK[3]_1} 2.0 {GTYE4_CHANNEL_TXOUTCLK[3]_2} 2.0 {GTYE4_CHANNEL_TXOUTCLK[3]_3} 2.0 {clk_out1_design_1_clk_wiz_0_0} 24.997 {design_1_xdma_0_0_pcie4c_ip_gt_top_i_n_116} 8.0 {mmcm_clkout0} 3.332 {mmcm_clkout5} 13.328 {mmcm_clkout6} 6.664 {pipe_clk} 4.0 {pll_clk[0]} 0.417 {pll_clk[0]_DIV} 3.332 {pll_clk[1]} 0.417 {pll_clk[1]_DIV} 3.332 {pll_clk[2]} 0.417 {pll_clk[2]_DIV} 3.332 {xdma_0_axi_aclk} 4.0]
  if {[llength [get_clocks]]!=[dict size $expected]} {error "clock set changed"}
  foreach clk [get_clocks] {
    set name [get_property NAME $clk]
    if {![dict exists $expected $name] || abs([get_property PERIOD $clk]-[dict get $expected $name])>0.002} {error "clock period changed: $name"}
  }
  set pins [get_pins -hier -filter {NAME =~ *RationalClockBridge_clocks_0_buffer/O}]
  if {[llength $pins]!=1} {error "target clock buffer absent/ambiguous"}
  set clk [get_clocks -of_objects $pins]
  if {[llength $clk]!=1 || abs([get_property PERIOD $clk]-24.9975)>0.002 || [llength [all_registers -clock $clk]]<1000} {error "host40 target coverage invalid"}
}
proc slacks {} {
  set setup [get_timing_paths -delay_type max -max_paths 1]
  set hold [get_timing_paths -delay_type min -max_paths 1]
  if {![llength $setup] || ![llength $hold]} {error "missing timing paths"}
  return [list [get_property SLACK $setup] [get_property SLACK $hold]]
}
proc snapshot {tag} {
  write_checkpoint -force "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/$tag.dcp"
  report_timing_summary -report_unconstrained -file "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/$tag-timing.rpt"
  set s [slacks]
  puts "EC_HOST40_SHELL_SNAPSHOT tag=$tag WNS=[lindex $s 0] WHS=[lindex $s 1]"
}
clock_contract
# Keep the fully routed E checkpoint intact. Record actual failing paths.
report_timing -delay_type max -slack_lesser_than 0 -max_paths 128 -nworst 1 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/negative-setup-before.rpt}
report_timing -delay_type min -max_paths 32 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/hold-before.rpt}
report_route_status -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/route-before.rpt}
puts "EC_R6_ROUTED_INPUT_VERIFIED slacks=[slacks]"
proc repair_critical_data_nets {} {
  set nets {}
  foreach path [get_timing_paths -delay_type max -slack_lesser_than 0 -max_paths 128 -nworst 1] {
    foreach point [get_property POINTS $path] {
      set pin [get_property PIN $point]
      if {![llength $pin] || [get_property DIRECTION $pin] ne "OUT"} {continue}
      set cell [get_cells -quiet -of_objects $pin]
      if {[llength $cell]!=1} {continue}
      set ref [get_property REF_NAME $cell]
      set name [get_property NAME $cell]
      if {![string match design_1_i/xdma_0/* $name]} {continue}
      if {![regexp {^(LUT[1-6]|MUXF[789]|CARRY8|FDRE|FDCE|FDSE|FDPE)$} $ref]} {continue}
      if {[string tolower [get_property ASYNC_REG $cell]] in {1 true yes} || [string tolower [get_property DONT_TOUCH $cell]] in {1 true yes}} {continue}
      set net [get_nets -quiet -of_objects $pin]
      if {[llength $net]!=1 || [llength [get_clocks -quiet -of_objects $net]]} {continue}
      if {[lsearch -exact $nets [lindex $net 0]]<0} {lappend nets [lindex $net 0]}
    }
  }
  if {![llength $nets] || [llength $nets]>256} {error "critical data reroute selection out of bounds"}
  set f [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/selected-critical-data-nets.txt} w];puts $f [join $nets \n];close $f
  puts "EC_R6_SELECTED_CRITICAL_DATA_NETS count=[llength $nets]"
  route_design -unroute -nets $nets
  route_design -nets $nets -delay
}

phys_opt_design -clock_opt
snapshot physical
set s [slacks]
set bad [get_nets -hier -quiet -filter {ROUTE_STATUS == UNROUTED || ROUTE_STATUS == PARTIAL || ROUTE_STATUS == CONFLICTS}]
if {[lindex $s 0]<0 || [lindex $s 1]<0 || [llength $bad]} {
  route_design -directive Explore -tns_cleanup
}
snapshot routed
set s [slacks]
if {[lindex $s 0]>=0 && [lindex $s 1]<0} {
  phys_opt_design -hold_fix
  snapshot hold-fixed
  route_design -directive Explore -tns_cleanup
  snapshot routed-hold-fixed
}
clock_contract
snapshot final
report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/utilization-final.rpt}
report_clocks -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/physical-clocks.rpt}
check_timing -verbose -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/check-timing.rpt}
report_route_status -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/route-final.rpt}
report_drc -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/drc-final.rpt}
report_timing -delay_type max -slack_lesser_than 0 -max_paths 128 -nworst 1 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/negative-setup-final.rpt}
set s [slacks]
if {[lindex $s 0]<0 || [lindex $s 1]<0} {error "setup/hold gate failed; candidate retained for next strategy"}
if {[llength [get_nets -hier -quiet -filter {ROUTE_STATUS == UNROUTED || ROUTE_STATUS == PARTIAL || ROUTE_STATUS == CONFLICTS}]]} {error "route coverage failed"}
if {[llength [get_drc_violations -quiet -filter {SEVERITY == Error}]]} {error "DRC errors"}
set f [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/check-timing.rpt} r];set checks [read $f];close $f
if {![regexp {checking no_clock \(0\)} $checks] || ![regexp {checking unconstrained_internal_endpoints \(0\)} $checks]} {error "clock coverage failed"}
set pulse [report_pulse_width -return_string -all_violators]
set f [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/pulse-width.rpt} w];puts $f $pulse;close $f
if {[regexp -nocase {VIOLATED} $pulse] || [regexp {(^|[[:space:]])-[0-9]+\.[0-9]+([[:space:]]|$)} $pulse]} {error "pulse width failed"}
set skew [report_bus_skew -return_string -no_detailed_paths -warn_on_violation]
set f [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/bus-skew.rpt} w];puts $f $skew;close $f
if {[regexp -nocase {VIOLATED} $skew]} {error "bus skew failed"}
report_cdc -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/cdc-final.rpt}
write_bitstream -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/original-svb-host40.bit}
puts "EC_SVB_HOST40_BITSTREAM_COMPLETE WNS=[lindex $s 0] WHS=[lindex $s 1]"
exit 0
