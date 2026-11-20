module FAMETop(
  input         hostClock,
  input         hostReset,
  output        FireSim_peekPokeBridge_reset_sink_ready,
  input         FireSim_peekPokeBridge_reset_sink_valid,
  output        FireSim_ep_tsi_out_ready_sink_ready,
  input         FireSim_ep_tsi_out_ready_sink_valid,
  input         FireSim_ep_tsi_out_ready_sink_bits,
  output        FireSim_ep_tsi_in_fwd_sink_ready,
  input         FireSim_ep_tsi_in_fwd_sink_valid,
  input  [31:0] FireSim_ep_tsi_in_fwd_sink_bits_bits,
  input         FireSim_ep_tsi_in_fwd_sink_bits_valid,
  output        FireSim_ep_1_axi4_ar_ready_sink_ready,
  input         FireSim_ep_1_axi4_ar_ready_sink_valid,
  input         FireSim_ep_1_axi4_ar_ready_sink_bits,
  output        FireSim_ep_1_axi4_w_ready_sink_ready,
  input         FireSim_ep_1_axi4_w_ready_sink_valid,
  input         FireSim_ep_1_axi4_w_ready_sink_bits,
  output        FireSim_ep_1_axi4_aw_ready_sink_ready,
  input         FireSim_ep_1_axi4_aw_ready_sink_valid,
  input         FireSim_ep_1_axi4_aw_ready_sink_bits,
  output        FireSim_ep_1_axi4_r_fwd_sink_ready,
  input         FireSim_ep_1_axi4_r_fwd_sink_valid,
  input  [3:0]  FireSim_ep_1_axi4_r_fwd_sink_bits_bits_id,
  input         FireSim_ep_1_axi4_r_fwd_sink_bits_bits_last,
  input  [63:0] FireSim_ep_1_axi4_r_fwd_sink_bits_bits_data,
  input         FireSim_ep_1_axi4_r_fwd_sink_bits_valid,
  output        FireSim_ep_1_axi4_b_fwd_sink_ready,
  input         FireSim_ep_1_axi4_b_fwd_sink_valid,
  input  [3:0]  FireSim_ep_1_axi4_b_fwd_sink_bits_bits_id,
  input         FireSim_ep_1_axi4_b_fwd_sink_bits_valid,
  output        FireSim_ep_2_uart_rxd_sink_ready,
  input         FireSim_ep_2_uart_rxd_sink_valid,
  input         FireSim_ep_2_uart_rxd_sink_bits,
  output        FireSim_ep_3_bdev_info_max_req_len_sink_ready,
  input         FireSim_ep_3_bdev_info_max_req_len_sink_valid,
  input  [31:0] FireSim_ep_3_bdev_info_max_req_len_sink_bits,
  output        FireSim_ep_3_bdev_info_nsectors_sink_ready,
  input         FireSim_ep_3_bdev_info_nsectors_sink_valid,
  input  [31:0] FireSim_ep_3_bdev_info_nsectors_sink_bits,
  output        FireSim_ep_3_bdev_data_ready_sink_ready,
  input         FireSim_ep_3_bdev_data_ready_sink_valid,
  input         FireSim_ep_3_bdev_data_ready_sink_bits,
  output        FireSim_ep_3_bdev_req_ready_sink_ready,
  input         FireSim_ep_3_bdev_req_ready_sink_valid,
  input         FireSim_ep_3_bdev_req_ready_sink_bits,
  output        FireSim_ep_3_bdev_resp_fwd_sink_ready,
  input         FireSim_ep_3_bdev_resp_fwd_sink_valid,
  input         FireSim_ep_3_bdev_resp_fwd_sink_bits_bits_tag,
  input  [63:0] FireSim_ep_3_bdev_resp_fwd_sink_bits_bits_data,
  input         FireSim_ep_3_bdev_resp_fwd_sink_bits_valid,
  output        FireSim_tracerv_triggerDebit_sink_ready,
  input         FireSim_tracerv_triggerDebit_sink_valid,
  output        FireSim_tracerv_triggerCredit_sink_ready,
  input         FireSim_tracerv_triggerCredit_sink_valid,
  output        FireSim_tracerv_1_triggerDebit_sink_ready,
  input         FireSim_tracerv_1_triggerDebit_sink_valid,
  output        FireSim_tracerv_1_triggerCredit_sink_ready,
  input         FireSim_tracerv_1_triggerCredit_sink_valid,
  output        FireSim_tracerv_2_triggerDebit_sink_ready,
  input         FireSim_tracerv_2_triggerDebit_sink_valid,
  output        FireSim_tracerv_2_triggerCredit_sink_ready,
  input         FireSim_tracerv_2_triggerCredit_sink_valid,
  output        FireSim_tracerv_3_triggerDebit_sink_ready,
  input         FireSim_tracerv_3_triggerDebit_sink_valid,
  output        FireSim_tracerv_3_triggerCredit_sink_ready,
  input         FireSim_tracerv_3_triggerCredit_sink_valid,
  output        FireSim_tracerv_4_triggerDebit_sink_ready,
  input         FireSim_tracerv_4_triggerDebit_sink_valid,
  output        FireSim_tracerv_4_triggerCredit_sink_ready,
  input         FireSim_tracerv_4_triggerCredit_sink_valid,
  output        FireSim_clockBridge_clocks_sink_ready,
  input         FireSim_clockBridge_clocks_sink_bits__0,
  input         FireSim_clockBridge_clocks_sink_bits__1,
  output        FireSim_resetBridge_reset_sink_ready,
  input         FireSim_resetBridge_reset_sink_valid,
  input         FireSim_resetBridge_reset_sink_bits,
  output        resetBridge_reset_2_sink_ready,
  input         resetBridge_reset_2_sink_valid,
  input         resetBridge_reset_2_sink_bits,
  output        resetBridge_reset_1_sink_ready,
  input         resetBridge_reset_1_sink_valid,
  input         resetBridge_reset_1_sink_bits,
  output        resetBridge_reset_sink_ready,
  input         resetBridge_reset_sink_valid,
  input         resetBridge_reset_sink_bits,
  input         FireSim_ep_tsi_out_fwd_source_ready,
  output        FireSim_ep_tsi_out_fwd_source_valid,
  output [31:0] FireSim_ep_tsi_out_fwd_source_bits_bits,
  output        FireSim_ep_tsi_out_fwd_source_bits_valid,
  input         FireSim_ep_tsi_in_ready_source_ready,
  output        FireSim_ep_tsi_in_ready_source_valid,
  output        FireSim_ep_tsi_in_ready_source_bits,
  input         FireSim_ep_1_reset_source_ready,
  output        FireSim_ep_1_reset_source_valid,
  output        FireSim_ep_1_reset_source_bits,
  input         FireSim_ep_1_axi4_ar_fwd_source_ready,
  output        FireSim_ep_1_axi4_ar_fwd_source_valid,
  output [3:0]  FireSim_ep_1_axi4_ar_fwd_source_bits_bits_id,
  output [3:0]  FireSim_ep_1_axi4_ar_fwd_source_bits_bits_qos,
  output [2:0]  FireSim_ep_1_axi4_ar_fwd_source_bits_bits_prot,
  output [3:0]  FireSim_ep_1_axi4_ar_fwd_source_bits_bits_cache,
  output        FireSim_ep_1_axi4_ar_fwd_source_bits_bits_lock,
  output [1:0]  FireSim_ep_1_axi4_ar_fwd_source_bits_bits_burst,
  output [2:0]  FireSim_ep_1_axi4_ar_fwd_source_bits_bits_size,
  output [7:0]  FireSim_ep_1_axi4_ar_fwd_source_bits_bits_len,
  output [34:0] FireSim_ep_1_axi4_ar_fwd_source_bits_bits_addr,
  output        FireSim_ep_1_axi4_ar_fwd_source_bits_valid,
  input         FireSim_ep_1_axi4_w_fwd_source_ready,
  output        FireSim_ep_1_axi4_w_fwd_source_valid,
  output [7:0]  FireSim_ep_1_axi4_w_fwd_source_bits_bits_strb,
  output        FireSim_ep_1_axi4_w_fwd_source_bits_bits_last,
  output [63:0] FireSim_ep_1_axi4_w_fwd_source_bits_bits_data,
  output        FireSim_ep_1_axi4_w_fwd_source_bits_valid,
  input         FireSim_ep_1_axi4_aw_fwd_source_ready,
  output        FireSim_ep_1_axi4_aw_fwd_source_valid,
  output [3:0]  FireSim_ep_1_axi4_aw_fwd_source_bits_bits_id,
  output [3:0]  FireSim_ep_1_axi4_aw_fwd_source_bits_bits_qos,
  output [2:0]  FireSim_ep_1_axi4_aw_fwd_source_bits_bits_prot,
  output [3:0]  FireSim_ep_1_axi4_aw_fwd_source_bits_bits_cache,
  output        FireSim_ep_1_axi4_aw_fwd_source_bits_bits_lock,
  output [1:0]  FireSim_ep_1_axi4_aw_fwd_source_bits_bits_burst,
  output [2:0]  FireSim_ep_1_axi4_aw_fwd_source_bits_bits_size,
  output [7:0]  FireSim_ep_1_axi4_aw_fwd_source_bits_bits_len,
  output [34:0] FireSim_ep_1_axi4_aw_fwd_source_bits_bits_addr,
  output        FireSim_ep_1_axi4_aw_fwd_source_bits_valid,
  input         FireSim_ep_1_axi4_r_ready_source_ready,
  output        FireSim_ep_1_axi4_r_ready_source_valid,
  output        FireSim_ep_1_axi4_r_ready_source_bits,
  input         FireSim_ep_1_axi4_b_ready_source_ready,
  output        FireSim_ep_1_axi4_b_ready_source_valid,
  output        FireSim_ep_1_axi4_b_ready_source_bits,
  input         FireSim_ep_2_uart_txd_source_ready,
  output        FireSim_ep_2_uart_txd_source_valid,
  output        FireSim_ep_2_uart_txd_source_bits,
  input         FireSim_ep_3_bdev_data_fwd_source_ready,
  output        FireSim_ep_3_bdev_data_fwd_source_valid,
  output        FireSim_ep_3_bdev_data_fwd_source_bits_bits_tag,
  output [63:0] FireSim_ep_3_bdev_data_fwd_source_bits_bits_data,
  output        FireSim_ep_3_bdev_data_fwd_source_bits_valid,
  input         FireSim_ep_3_bdev_req_fwd_source_ready,
  output        FireSim_ep_3_bdev_req_fwd_source_valid,
  output        FireSim_ep_3_bdev_req_fwd_source_bits_bits_tag,
  output [31:0] FireSim_ep_3_bdev_req_fwd_source_bits_bits_len,
  output [31:0] FireSim_ep_3_bdev_req_fwd_source_bits_bits_offset,
  output        FireSim_ep_3_bdev_req_fwd_source_bits_bits_write,
  output        FireSim_ep_3_bdev_req_fwd_source_bits_valid,
  input         FireSim_ep_3_bdev_resp_ready_source_ready,
  output        FireSim_ep_3_bdev_resp_ready_source_valid,
  output        FireSim_ep_3_bdev_resp_ready_source_bits,
  input         FireSim_tracerv_trace_insns_0_tval_source_ready,
  output        FireSim_tracerv_trace_insns_0_tval_source_valid,
  output [39:0] FireSim_tracerv_trace_insns_0_tval_source_bits,
  input         FireSim_tracerv_trace_insns_0_cause_source_ready,
  output        FireSim_tracerv_trace_insns_0_cause_source_valid,
  output [63:0] FireSim_tracerv_trace_insns_0_cause_source_bits,
  input         FireSim_tracerv_trace_insns_0_interrupt_source_ready,
  output        FireSim_tracerv_trace_insns_0_interrupt_source_valid,
  output        FireSim_tracerv_trace_insns_0_interrupt_source_bits,
  input         FireSim_tracerv_trace_insns_0_exception_source_ready,
  output        FireSim_tracerv_trace_insns_0_exception_source_valid,
  output        FireSim_tracerv_trace_insns_0_exception_source_bits,
  input         FireSim_tracerv_trace_insns_0_priv_source_ready,
  output        FireSim_tracerv_trace_insns_0_priv_source_valid,
  output [2:0]  FireSim_tracerv_trace_insns_0_priv_source_bits,
  input         FireSim_tracerv_trace_insns_0_wdata_source_ready,
  output        FireSim_tracerv_trace_insns_0_wdata_source_valid,
  output [63:0] FireSim_tracerv_trace_insns_0_wdata_source_bits,
  input         FireSim_tracerv_trace_insns_0_insn_source_ready,
  output        FireSim_tracerv_trace_insns_0_insn_source_valid,
  output [31:0] FireSim_tracerv_trace_insns_0_insn_source_bits,
  input         FireSim_tracerv_trace_insns_0_iaddr_source_ready,
  output        FireSim_tracerv_trace_insns_0_iaddr_source_valid,
  output [39:0] FireSim_tracerv_trace_insns_0_iaddr_source_bits,
  input         FireSim_tracerv_trace_insns_0_valid_source_ready,
  output        FireSim_tracerv_trace_insns_0_valid_source_valid,
  output        FireSim_tracerv_trace_insns_0_valid_source_bits,
  input         FireSim_tracerv_trace_insns_1_tval_source_ready,
  output        FireSim_tracerv_trace_insns_1_tval_source_valid,
  output [39:0] FireSim_tracerv_trace_insns_1_tval_source_bits,
  input         FireSim_tracerv_trace_insns_1_cause_source_ready,
  output        FireSim_tracerv_trace_insns_1_cause_source_valid,
  output [63:0] FireSim_tracerv_trace_insns_1_cause_source_bits,
  input         FireSim_tracerv_trace_insns_1_interrupt_source_ready,
  output        FireSim_tracerv_trace_insns_1_interrupt_source_valid,
  output        FireSim_tracerv_trace_insns_1_interrupt_source_bits,
  input         FireSim_tracerv_trace_insns_1_exception_source_ready,
  output        FireSim_tracerv_trace_insns_1_exception_source_valid,
  output        FireSim_tracerv_trace_insns_1_exception_source_bits,
  input         FireSim_tracerv_trace_insns_1_priv_source_ready,
  output        FireSim_tracerv_trace_insns_1_priv_source_valid,
  output [2:0]  FireSim_tracerv_trace_insns_1_priv_source_bits,
  input         FireSim_tracerv_trace_insns_1_wdata_source_ready,
  output        FireSim_tracerv_trace_insns_1_wdata_source_valid,
  output [63:0] FireSim_tracerv_trace_insns_1_wdata_source_bits,
  input         FireSim_tracerv_trace_insns_1_insn_source_ready,
  output        FireSim_tracerv_trace_insns_1_insn_source_valid,
  output [31:0] FireSim_tracerv_trace_insns_1_insn_source_bits,
  input         FireSim_tracerv_trace_insns_1_iaddr_source_ready,
  output        FireSim_tracerv_trace_insns_1_iaddr_source_valid,
  output [39:0] FireSim_tracerv_trace_insns_1_iaddr_source_bits,
  input         FireSim_tracerv_trace_insns_1_valid_source_ready,
  output        FireSim_tracerv_trace_insns_1_valid_source_valid,
  output        FireSim_tracerv_trace_insns_1_valid_source_bits,
  input         FireSim_tracerv_trace_insns_2_tval_source_ready,
  output        FireSim_tracerv_trace_insns_2_tval_source_valid,
  output [39:0] FireSim_tracerv_trace_insns_2_tval_source_bits,
  input         FireSim_tracerv_trace_insns_2_cause_source_ready,
  output        FireSim_tracerv_trace_insns_2_cause_source_valid,
  output [63:0] FireSim_tracerv_trace_insns_2_cause_source_bits,
  input         FireSim_tracerv_trace_insns_2_interrupt_source_ready,
  output        FireSim_tracerv_trace_insns_2_interrupt_source_valid,
  output        FireSim_tracerv_trace_insns_2_interrupt_source_bits,
  input         FireSim_tracerv_trace_insns_2_exception_source_ready,
  output        FireSim_tracerv_trace_insns_2_exception_source_valid,
  output        FireSim_tracerv_trace_insns_2_exception_source_bits,
  input         FireSim_tracerv_trace_insns_2_priv_source_ready,
  output        FireSim_tracerv_trace_insns_2_priv_source_valid,
  output [2:0]  FireSim_tracerv_trace_insns_2_priv_source_bits,
  input         FireSim_tracerv_trace_insns_2_wdata_source_ready,
  output        FireSim_tracerv_trace_insns_2_wdata_source_valid,
  output [63:0] FireSim_tracerv_trace_insns_2_wdata_source_bits,
  input         FireSim_tracerv_trace_insns_2_insn_source_ready,
  output        FireSim_tracerv_trace_insns_2_insn_source_valid,
  output [31:0] FireSim_tracerv_trace_insns_2_insn_source_bits,
  input         FireSim_tracerv_trace_insns_2_iaddr_source_ready,
  output        FireSim_tracerv_trace_insns_2_iaddr_source_valid,
  output [39:0] FireSim_tracerv_trace_insns_2_iaddr_source_bits,
  input         FireSim_tracerv_trace_insns_2_valid_source_ready,
  output        FireSim_tracerv_trace_insns_2_valid_source_valid,
  output        FireSim_tracerv_trace_insns_2_valid_source_bits,
  input         FireSim_tracerv_trace_reset_source_ready,
  output        FireSim_tracerv_trace_reset_source_valid,
  output        FireSim_tracerv_trace_reset_source_bits,
  input         FireSim_tracerv_1_trace_insns_0_tval_source_ready,
  output        FireSim_tracerv_1_trace_insns_0_tval_source_valid,
  output [39:0] FireSim_tracerv_1_trace_insns_0_tval_source_bits,
  input         FireSim_tracerv_1_trace_insns_0_cause_source_ready,
  output        FireSim_tracerv_1_trace_insns_0_cause_source_valid,
  output [63:0] FireSim_tracerv_1_trace_insns_0_cause_source_bits,
  input         FireSim_tracerv_1_trace_insns_0_interrupt_source_ready,
  output        FireSim_tracerv_1_trace_insns_0_interrupt_source_valid,
  output        FireSim_tracerv_1_trace_insns_0_interrupt_source_bits,
  input         FireSim_tracerv_1_trace_insns_0_exception_source_ready,
  output        FireSim_tracerv_1_trace_insns_0_exception_source_valid,
  output        FireSim_tracerv_1_trace_insns_0_exception_source_bits,
  input         FireSim_tracerv_1_trace_insns_0_priv_source_ready,
  output        FireSim_tracerv_1_trace_insns_0_priv_source_valid,
  output [2:0]  FireSim_tracerv_1_trace_insns_0_priv_source_bits,
  input         FireSim_tracerv_1_trace_insns_0_insn_source_ready,
  output        FireSim_tracerv_1_trace_insns_0_insn_source_valid,
  output [31:0] FireSim_tracerv_1_trace_insns_0_insn_source_bits,
  input         FireSim_tracerv_1_trace_insns_0_iaddr_source_ready,
  output        FireSim_tracerv_1_trace_insns_0_iaddr_source_valid,
  output [39:0] FireSim_tracerv_1_trace_insns_0_iaddr_source_bits,
  input         FireSim_tracerv_1_trace_insns_0_valid_source_ready,
  output        FireSim_tracerv_1_trace_insns_0_valid_source_valid,
  output        FireSim_tracerv_1_trace_insns_0_valid_source_bits,
  input         FireSim_tracerv_1_trace_reset_source_ready,
  output        FireSim_tracerv_1_trace_reset_source_valid,
  output        FireSim_tracerv_1_trace_reset_source_bits,
  input         FireSim_tracerv_2_trace_insns_0_tval_source_ready,
  output        FireSim_tracerv_2_trace_insns_0_tval_source_valid,
  output [39:0] FireSim_tracerv_2_trace_insns_0_tval_source_bits,
  input         FireSim_tracerv_2_trace_insns_0_cause_source_ready,
  output        FireSim_tracerv_2_trace_insns_0_cause_source_valid,
  output [63:0] FireSim_tracerv_2_trace_insns_0_cause_source_bits,
  input         FireSim_tracerv_2_trace_insns_0_interrupt_source_ready,
  output        FireSim_tracerv_2_trace_insns_0_interrupt_source_valid,
  output        FireSim_tracerv_2_trace_insns_0_interrupt_source_bits,
  input         FireSim_tracerv_2_trace_insns_0_exception_source_ready,
  output        FireSim_tracerv_2_trace_insns_0_exception_source_valid,
  output        FireSim_tracerv_2_trace_insns_0_exception_source_bits,
  input         FireSim_tracerv_2_trace_insns_0_priv_source_ready,
  output        FireSim_tracerv_2_trace_insns_0_priv_source_valid,
  output [2:0]  FireSim_tracerv_2_trace_insns_0_priv_source_bits,
  input         FireSim_tracerv_2_trace_insns_0_insn_source_ready,
  output        FireSim_tracerv_2_trace_insns_0_insn_source_valid,
  output [31:0] FireSim_tracerv_2_trace_insns_0_insn_source_bits,
  input         FireSim_tracerv_2_trace_insns_0_iaddr_source_ready,
  output        FireSim_tracerv_2_trace_insns_0_iaddr_source_valid,
  output [39:0] FireSim_tracerv_2_trace_insns_0_iaddr_source_bits,
  input         FireSim_tracerv_2_trace_insns_0_valid_source_ready,
  output        FireSim_tracerv_2_trace_insns_0_valid_source_valid,
  output        FireSim_tracerv_2_trace_insns_0_valid_source_bits,
  input         FireSim_tracerv_2_trace_reset_source_ready,
  output        FireSim_tracerv_2_trace_reset_source_valid,
  output        FireSim_tracerv_2_trace_reset_source_bits,
  input         FireSim_tracerv_3_trace_insns_0_tval_source_ready,
  output        FireSim_tracerv_3_trace_insns_0_tval_source_valid,
  output [39:0] FireSim_tracerv_3_trace_insns_0_tval_source_bits,
  input         FireSim_tracerv_3_trace_insns_0_cause_source_ready,
  output        FireSim_tracerv_3_trace_insns_0_cause_source_valid,
  output [63:0] FireSim_tracerv_3_trace_insns_0_cause_source_bits,
  input         FireSim_tracerv_3_trace_insns_0_interrupt_source_ready,
  output        FireSim_tracerv_3_trace_insns_0_interrupt_source_valid,
  output        FireSim_tracerv_3_trace_insns_0_interrupt_source_bits,
  input         FireSim_tracerv_3_trace_insns_0_exception_source_ready,
  output        FireSim_tracerv_3_trace_insns_0_exception_source_valid,
  output        FireSim_tracerv_3_trace_insns_0_exception_source_bits,
  input         FireSim_tracerv_3_trace_insns_0_priv_source_ready,
  output        FireSim_tracerv_3_trace_insns_0_priv_source_valid,
  output [2:0]  FireSim_tracerv_3_trace_insns_0_priv_source_bits,
  input         FireSim_tracerv_3_trace_insns_0_insn_source_ready,
  output        FireSim_tracerv_3_trace_insns_0_insn_source_valid,
  output [31:0] FireSim_tracerv_3_trace_insns_0_insn_source_bits,
  input         FireSim_tracerv_3_trace_insns_0_iaddr_source_ready,
  output        FireSim_tracerv_3_trace_insns_0_iaddr_source_valid,
  output [39:0] FireSim_tracerv_3_trace_insns_0_iaddr_source_bits,
  input         FireSim_tracerv_3_trace_insns_0_valid_source_ready,
  output        FireSim_tracerv_3_trace_insns_0_valid_source_valid,
  output        FireSim_tracerv_3_trace_insns_0_valid_source_bits,
  input         FireSim_tracerv_3_trace_reset_source_ready,
  output        FireSim_tracerv_3_trace_reset_source_valid,
  output        FireSim_tracerv_3_trace_reset_source_bits,
  input         FireSim_tracerv_4_trace_insns_0_tval_source_ready,
  output        FireSim_tracerv_4_trace_insns_0_tval_source_valid,
  output [39:0] FireSim_tracerv_4_trace_insns_0_tval_source_bits,
  input         FireSim_tracerv_4_trace_insns_0_cause_source_ready,
  output        FireSim_tracerv_4_trace_insns_0_cause_source_valid,
  output [63:0] FireSim_tracerv_4_trace_insns_0_cause_source_bits,
  input         FireSim_tracerv_4_trace_insns_0_interrupt_source_ready,
  output        FireSim_tracerv_4_trace_insns_0_interrupt_source_valid,
  output        FireSim_tracerv_4_trace_insns_0_interrupt_source_bits,
  input         FireSim_tracerv_4_trace_insns_0_exception_source_ready,
  output        FireSim_tracerv_4_trace_insns_0_exception_source_valid,
  output        FireSim_tracerv_4_trace_insns_0_exception_source_bits,
  input         FireSim_tracerv_4_trace_insns_0_priv_source_ready,
  output        FireSim_tracerv_4_trace_insns_0_priv_source_valid,
  output [2:0]  FireSim_tracerv_4_trace_insns_0_priv_source_bits,
  input         FireSim_tracerv_4_trace_insns_0_insn_source_ready,
  output        FireSim_tracerv_4_trace_insns_0_insn_source_valid,
  output [31:0] FireSim_tracerv_4_trace_insns_0_insn_source_bits,
  input         FireSim_tracerv_4_trace_insns_0_iaddr_source_ready,
  output        FireSim_tracerv_4_trace_insns_0_iaddr_source_valid,
  output [39:0] FireSim_tracerv_4_trace_insns_0_iaddr_source_bits,
  input         FireSim_tracerv_4_trace_insns_0_valid_source_ready,
  output        FireSim_tracerv_4_trace_insns_0_valid_source_valid,
  output        FireSim_tracerv_4_trace_insns_0_valid_source_bits,
  input         FireSim_tracerv_4_trace_reset_source_ready,
  output        FireSim_tracerv_4_trace_reset_source_valid,
  output        FireSim_tracerv_4_trace_reset_source_bits,
  input         FireSim_synthesizedPrintf_clockBridge_clocks_0_globalReset_source_ready,
  output        FireSim_synthesizedPrintf_clockBridge_clocks_0_globalReset_source_valid,
  output        FireSim_synthesizedPrintf_clockBridge_clocks_0_globalReset_source_bits,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_valid
    ,
  output [63:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_valid
    ,
  output [63:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_valid
    ,
  output [63:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_valid
    ,
  output [63:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_valid
    ,
  output [63:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_5_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_5_source_valid
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_6_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_6_source_valid
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_7_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_7_source_valid
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_8_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_8_source_valid
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_9_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_9_source_valid
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_10_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_10_source_valid
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_valid
    ,
  output [63:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_bits
    ,
  input         FireSim_synthesizedPrintf_clockBridge_clocks_1_globalReset_source_ready,
  output        FireSim_synthesizedPrintf_clockBridge_clocks_1_globalReset_source_valid,
  output        FireSim_synthesizedPrintf_clockBridge_clocks_1_globalReset_source_bits,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
    ,
  output [2:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
    ,
  output [31:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
    ,
  output [1:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
    ,
  output [2:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
    ,
  output [31:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
    ,
  output [63:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
    ,
  output [1:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
    ,
  output [2:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
    ,
  output [31:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
    ,
  output [63:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
    ,
  output [1:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
    ,
  output [2:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
    ,
  output [31:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
    ,
  output [63:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
    ,
  output [1:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
    ,
  output [2:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
    ,
  output [31:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
    ,
  output [63:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
    ,
  output [1:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
    ,
  output [2:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
    ,
  output [31:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
    ,
  output [1:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
    ,
  output [2:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
    ,
  output [31:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
    ,
  output [1:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
    ,
  output [2:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
    ,
  output [31:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
    ,
  output [1:0]
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
    ,
  input
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
    ,
  output
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
    ,
  input         ep_reset_source_ready,
  output        ep_reset_source_valid,
  output        ep_reset_source_bits,
  input         ep_2_reset_source_ready,
  output        ep_2_reset_source_valid,
  output        ep_2_reset_source_bits,
  input         ep_3_reset_source_ready,
  output        ep_3_reset_source_valid,
  output        ep_3_reset_source_bits
);
  wire  FireSim__hostClock;
  wire  FireSim__hostReset;
  wire  FireSim__clockBridge_clocks_sink_ready;
  wire  FireSim__clockBridge_clocks_sink_bits__0;
  wire  FireSim__clockBridge_clocks_sink_bits__1;
  wire  FireSim__ep_1_axi4_aw_ready_sink_ready;
  wire  FireSim__ep_1_axi4_aw_ready_sink_valid;
  wire  FireSim__ep_1_axi4_aw_ready_sink_bits;
  wire  FireSim__peekPokeBridge_reset_sink_ready;
  wire  FireSim__peekPokeBridge_reset_sink_valid;
  wire  FireSim__tracerv_3_triggerDebit_sink_ready;
  wire  FireSim__tracerv_3_triggerDebit_sink_valid;
  wire  FireSim__ep_3_bdev_info_nsectors_sink_ready;
  wire  FireSim__ep_3_bdev_info_nsectors_sink_valid;
  wire [31:0] FireSim__ep_3_bdev_info_nsectors_sink_bits;
  wire  FireSim__tracerv_triggerDebit_sink_ready;
  wire  FireSim__tracerv_triggerDebit_sink_valid;
  wire  FireSim__tracerv_2_triggerCredit_sink_ready;
  wire  FireSim__tracerv_2_triggerCredit_sink_valid;
  wire  FireSim__ep_3_bdev_info_max_req_len_sink_ready;
  wire  FireSim__ep_3_bdev_info_max_req_len_sink_valid;
  wire [31:0] FireSim__ep_3_bdev_info_max_req_len_sink_bits;
  wire  FireSim__ep_3_bdev_req_ready_sink_ready;
  wire  FireSim__ep_3_bdev_req_ready_sink_valid;
  wire  FireSim__ep_3_bdev_req_ready_sink_bits;
  wire  FireSim__tracerv_triggerCredit_sink_ready;
  wire  FireSim__tracerv_triggerCredit_sink_valid;
  wire  FireSim__ep_3_bdev_resp_fwd_sink_ready;
  wire  FireSim__ep_3_bdev_resp_fwd_sink_valid;
  wire  FireSim__ep_3_bdev_resp_fwd_sink_bits_bits_tag;
  wire [63:0] FireSim__ep_3_bdev_resp_fwd_sink_bits_bits_data;
  wire  FireSim__ep_3_bdev_resp_fwd_sink_bits_valid;
  wire  FireSim__ep_1_axi4_ar_ready_sink_ready;
  wire  FireSim__ep_1_axi4_ar_ready_sink_valid;
  wire  FireSim__ep_1_axi4_ar_ready_sink_bits;
  wire  FireSim__ep_tsi_out_ready_sink_ready;
  wire  FireSim__ep_tsi_out_ready_sink_valid;
  wire  FireSim__ep_tsi_out_ready_sink_bits;
  wire  FireSim__resetBridge_reset_sink_ready;
  wire  FireSim__resetBridge_reset_sink_valid;
  wire  FireSim__resetBridge_reset_sink_bits;
  wire  FireSim__tracerv_4_triggerDebit_sink_ready;
  wire  FireSim__tracerv_4_triggerDebit_sink_valid;
  wire  FireSim__ep_1_axi4_w_ready_sink_ready;
  wire  FireSim__ep_1_axi4_w_ready_sink_valid;
  wire  FireSim__ep_1_axi4_w_ready_sink_bits;
  wire  FireSim__tracerv_1_triggerCredit_sink_ready;
  wire  FireSim__tracerv_1_triggerCredit_sink_valid;
  wire  FireSim__ep_tsi_in_fwd_sink_ready;
  wire  FireSim__ep_tsi_in_fwd_sink_valid;
  wire [31:0] FireSim__ep_tsi_in_fwd_sink_bits_bits;
  wire  FireSim__ep_tsi_in_fwd_sink_bits_valid;
  wire  FireSim__ep_2_uart_rxd_sink_ready;
  wire  FireSim__ep_2_uart_rxd_sink_valid;
  wire  FireSim__ep_2_uart_rxd_sink_bits;
  wire  FireSim__tracerv_1_triggerDebit_sink_ready;
  wire  FireSim__tracerv_1_triggerDebit_sink_valid;
  wire  FireSim__tracerv_4_triggerCredit_sink_ready;
  wire  FireSim__tracerv_4_triggerCredit_sink_valid;
  wire  FireSim__tracerv_2_triggerDebit_sink_ready;
  wire  FireSim__tracerv_2_triggerDebit_sink_valid;
  wire  FireSim__ep_3_bdev_data_ready_sink_ready;
  wire  FireSim__ep_3_bdev_data_ready_sink_valid;
  wire  FireSim__ep_3_bdev_data_ready_sink_bits;
  wire  FireSim__tracerv_3_triggerCredit_sink_ready;
  wire  FireSim__tracerv_3_triggerCredit_sink_valid;
  wire  FireSim__ep_1_axi4_b_fwd_sink_ready;
  wire  FireSim__ep_1_axi4_b_fwd_sink_valid;
  wire [3:0] FireSim__ep_1_axi4_b_fwd_sink_bits_bits_id;
  wire  FireSim__ep_1_axi4_b_fwd_sink_bits_valid;
  wire  FireSim__ep_1_axi4_r_fwd_sink_ready;
  wire  FireSim__ep_1_axi4_r_fwd_sink_valid;
  wire [3:0] FireSim__ep_1_axi4_r_fwd_sink_bits_bits_id;
  wire  FireSim__ep_1_axi4_r_fwd_sink_bits_bits_last;
  wire [63:0] FireSim__ep_1_axi4_r_fwd_sink_bits_bits_data;
  wire  FireSim__ep_1_axi4_r_fwd_sink_bits_valid;
  wire  FireSim__ep_1_axi4_ar_fwd_source_ready;
  wire  FireSim__ep_1_axi4_ar_fwd_source_valid;
  wire [3:0] FireSim__ep_1_axi4_ar_fwd_source_bits_bits_id;
  wire [3:0] FireSim__ep_1_axi4_ar_fwd_source_bits_bits_qos;
  wire [2:0] FireSim__ep_1_axi4_ar_fwd_source_bits_bits_prot;
  wire [3:0] FireSim__ep_1_axi4_ar_fwd_source_bits_bits_cache;
  wire  FireSim__ep_1_axi4_ar_fwd_source_bits_bits_lock;
  wire [1:0] FireSim__ep_1_axi4_ar_fwd_source_bits_bits_burst;
  wire [2:0] FireSim__ep_1_axi4_ar_fwd_source_bits_bits_size;
  wire [7:0] FireSim__ep_1_axi4_ar_fwd_source_bits_bits_len;
  wire [34:0] FireSim__ep_1_axi4_ar_fwd_source_bits_bits_addr;
  wire  FireSim__ep_1_axi4_ar_fwd_source_bits_valid;
  wire  FireSim__ep_3_bdev_data_fwd_source_ready;
  wire  FireSim__ep_3_bdev_data_fwd_source_valid;
  wire  FireSim__ep_3_bdev_data_fwd_source_bits_bits_tag;
  wire [63:0] FireSim__ep_3_bdev_data_fwd_source_bits_bits_data;
  wire  FireSim__ep_3_bdev_data_fwd_source_bits_valid;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
    ;
  wire [31:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
    ;
  wire [31:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
    ;
  wire  FireSim__tracerv_1_trace_insns_0_interrupt_source_ready;
  wire  FireSim__tracerv_1_trace_insns_0_interrupt_source_valid;
  wire  FireSim__tracerv_1_trace_insns_0_interrupt_source_bits;
  wire  FireSim__tracerv_1_trace_insns_0_iaddr_source_ready;
  wire  FireSim__tracerv_1_trace_insns_0_iaddr_source_valid;
  wire [39:0] FireSim__tracerv_1_trace_insns_0_iaddr_source_bits;
  wire  FireSim__tracerv_trace_insns_2_priv_source_ready;
  wire  FireSim__tracerv_trace_insns_2_priv_source_valid;
  wire [2:0] FireSim__tracerv_trace_insns_2_priv_source_bits;
  wire  FireSim__tracerv_trace_insns_0_insn_source_ready;
  wire  FireSim__tracerv_trace_insns_0_insn_source_valid;
  wire [31:0] FireSim__tracerv_trace_insns_0_insn_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
    ;
  wire [2:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
    ;
  wire  FireSim__tracerv_2_trace_insns_0_cause_source_ready;
  wire  FireSim__tracerv_2_trace_insns_0_cause_source_valid;
  wire [63:0] FireSim__tracerv_2_trace_insns_0_cause_source_bits;
  wire  FireSim__tracerv_trace_insns_0_tval_source_ready;
  wire  FireSim__tracerv_trace_insns_0_tval_source_valid;
  wire [39:0] FireSim__tracerv_trace_insns_0_tval_source_bits;
  wire  FireSim__tracerv_trace_insns_1_insn_source_ready;
  wire  FireSim__tracerv_trace_insns_1_insn_source_valid;
  wire [31:0] FireSim__tracerv_trace_insns_1_insn_source_bits;
  wire  FireSim__tracerv_3_trace_insns_0_tval_source_ready;
  wire  FireSim__tracerv_3_trace_insns_0_tval_source_valid;
  wire [39:0] FireSim__tracerv_3_trace_insns_0_tval_source_bits;
  wire  FireSim__tracerv_trace_insns_2_interrupt_source_ready;
  wire  FireSim__tracerv_trace_insns_2_interrupt_source_valid;
  wire  FireSim__tracerv_trace_insns_2_interrupt_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
    ;
  wire [1:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
    ;
  wire  FireSim__ep_1_axi4_r_ready_source_ready;
  wire  FireSim__ep_1_axi4_r_ready_source_valid;
  wire  FireSim__ep_1_axi4_r_ready_source_bits;
  wire  FireSim__tracerv_trace_insns_2_wdata_source_ready;
  wire  FireSim__tracerv_trace_insns_2_wdata_source_valid;
  wire [63:0] FireSim__tracerv_trace_insns_2_wdata_source_bits;
  wire  FireSim__tracerv_4_trace_insns_0_cause_source_ready;
  wire  FireSim__tracerv_4_trace_insns_0_cause_source_valid;
  wire [63:0] FireSim__tracerv_4_trace_insns_0_cause_source_bits;
  wire  FireSim__tracerv_trace_insns_0_exception_source_ready;
  wire  FireSim__tracerv_trace_insns_0_exception_source_valid;
  wire  FireSim__tracerv_trace_insns_0_exception_source_bits;
  wire  FireSim__synthesizedPrintf_clockBridge_clocks_0_globalReset_source_ready;
  wire  FireSim__synthesizedPrintf_clockBridge_clocks_0_globalReset_source_valid;
  wire  FireSim__synthesizedPrintf_clockBridge_clocks_0_globalReset_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
    ;
  wire  FireSim__tracerv_3_trace_insns_0_iaddr_source_ready;
  wire  FireSim__tracerv_3_trace_insns_0_iaddr_source_valid;
  wire [39:0] FireSim__tracerv_3_trace_insns_0_iaddr_source_bits;
  wire  FireSim__tracerv_trace_insns_2_insn_source_ready;
  wire  FireSim__tracerv_trace_insns_2_insn_source_valid;
  wire [31:0] FireSim__tracerv_trace_insns_2_insn_source_bits;
  wire  FireSim__tracerv_trace_insns_1_iaddr_source_ready;
  wire  FireSim__tracerv_trace_insns_1_iaddr_source_valid;
  wire [39:0] FireSim__tracerv_trace_insns_1_iaddr_source_bits;
  wire  FireSim__tracerv_1_trace_insns_0_valid_source_ready;
  wire  FireSim__tracerv_1_trace_insns_0_valid_source_valid;
  wire  FireSim__tracerv_1_trace_insns_0_valid_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
    ;
  wire  FireSim__tracerv_4_trace_insns_0_exception_source_ready;
  wire  FireSim__tracerv_4_trace_insns_0_exception_source_valid;
  wire  FireSim__tracerv_4_trace_insns_0_exception_source_bits;
  wire  FireSim__tracerv_trace_insns_0_iaddr_source_ready;
  wire  FireSim__tracerv_trace_insns_0_iaddr_source_valid;
  wire [39:0] FireSim__tracerv_trace_insns_0_iaddr_source_bits;
  wire  FireSim__tracerv_3_trace_insns_0_valid_source_ready;
  wire  FireSim__tracerv_3_trace_insns_0_valid_source_valid;
  wire  FireSim__tracerv_3_trace_insns_0_valid_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
    ;
  wire [1:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
    ;
  wire [63:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
    ;
  wire [2:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_valid
    ;
  wire [63:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_8_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_8_source_valid
    ;
  wire  FireSim__tracerv_1_trace_insns_0_priv_source_ready;
  wire  FireSim__tracerv_1_trace_insns_0_priv_source_valid;
  wire [2:0] FireSim__tracerv_1_trace_insns_0_priv_source_bits;
  wire  FireSim__tracerv_trace_insns_2_exception_source_ready;
  wire  FireSim__tracerv_trace_insns_2_exception_source_valid;
  wire  FireSim__tracerv_trace_insns_2_exception_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
    ;
  wire [2:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
    ;
  wire  FireSim__tracerv_trace_insns_1_wdata_source_ready;
  wire  FireSim__tracerv_trace_insns_1_wdata_source_valid;
  wire [63:0] FireSim__tracerv_trace_insns_1_wdata_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
    ;
  wire [31:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
    ;
  wire  FireSim__tracerv_2_trace_insns_0_priv_source_ready;
  wire  FireSim__tracerv_2_trace_insns_0_priv_source_valid;
  wire [2:0] FireSim__tracerv_2_trace_insns_0_priv_source_bits;
  wire  FireSim__tracerv_3_trace_insns_0_insn_source_ready;
  wire  FireSim__tracerv_3_trace_insns_0_insn_source_valid;
  wire [31:0] FireSim__tracerv_3_trace_insns_0_insn_source_bits;
  wire  FireSim__ep_1_reset_source_ready;
  wire  FireSim__ep_1_reset_source_valid;
  wire  FireSim__ep_1_reset_source_bits;
  wire  FireSim__tracerv_2_trace_insns_0_tval_source_ready;
  wire  FireSim__tracerv_2_trace_insns_0_tval_source_valid;
  wire [39:0] FireSim__tracerv_2_trace_insns_0_tval_source_bits;
  wire  FireSim__tracerv_3_trace_insns_0_cause_source_ready;
  wire  FireSim__tracerv_3_trace_insns_0_cause_source_valid;
  wire [63:0] FireSim__tracerv_3_trace_insns_0_cause_source_bits;
  wire  FireSim__ep_3_bdev_resp_ready_source_ready;
  wire  FireSim__ep_3_bdev_resp_ready_source_valid;
  wire  FireSim__ep_3_bdev_resp_ready_source_bits;
  wire  FireSim__tracerv_1_trace_reset_source_ready;
  wire  FireSim__tracerv_1_trace_reset_source_valid;
  wire  FireSim__tracerv_1_trace_reset_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
    ;
  wire [1:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
    ;
  wire  FireSim__tracerv_trace_insns_1_interrupt_source_ready;
  wire  FireSim__tracerv_trace_insns_1_interrupt_source_valid;
  wire  FireSim__tracerv_trace_insns_1_interrupt_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
    ;
  wire [1:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
    ;
  wire  FireSim__tracerv_trace_insns_0_interrupt_source_ready;
  wire  FireSim__tracerv_trace_insns_0_interrupt_source_valid;
  wire  FireSim__tracerv_trace_insns_0_interrupt_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
    ;
  wire [1:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
    ;
  wire  FireSim__ep_tsi_in_ready_source_ready;
  wire  FireSim__ep_tsi_in_ready_source_valid;
  wire  FireSim__ep_tsi_in_ready_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
    ;
  wire [31:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
    ;
  wire  FireSim__tracerv_trace_insns_2_cause_source_ready;
  wire  FireSim__tracerv_trace_insns_2_cause_source_valid;
  wire [63:0] FireSim__tracerv_trace_insns_2_cause_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_bits
    ;
  wire  FireSim__tracerv_2_trace_insns_0_insn_source_ready;
  wire  FireSim__tracerv_2_trace_insns_0_insn_source_valid;
  wire [31:0] FireSim__tracerv_2_trace_insns_0_insn_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_valid
    ;
  wire [63:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_bits
    ;
  wire  FireSim__tracerv_1_trace_insns_0_exception_source_ready;
  wire  FireSim__tracerv_1_trace_insns_0_exception_source_valid;
  wire  FireSim__tracerv_1_trace_insns_0_exception_source_bits;
  wire  FireSim__tracerv_trace_insns_0_priv_source_ready;
  wire  FireSim__tracerv_trace_insns_0_priv_source_valid;
  wire [2:0] FireSim__tracerv_trace_insns_0_priv_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_7_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_7_source_valid
    ;
  wire  FireSim__tracerv_trace_reset_source_ready;
  wire  FireSim__tracerv_trace_reset_source_valid;
  wire  FireSim__tracerv_trace_reset_source_bits;
  wire  FireSim__tracerv_3_trace_insns_0_interrupt_source_ready;
  wire  FireSim__tracerv_3_trace_insns_0_interrupt_source_valid;
  wire  FireSim__tracerv_3_trace_insns_0_interrupt_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_10_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_10_source_valid
    ;
  wire  FireSim__tracerv_trace_insns_1_valid_source_ready;
  wire  FireSim__tracerv_trace_insns_1_valid_source_valid;
  wire  FireSim__tracerv_trace_insns_1_valid_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_bits
    ;
  wire  FireSim__tracerv_2_trace_reset_source_ready;
  wire  FireSim__tracerv_2_trace_reset_source_valid;
  wire  FireSim__tracerv_2_trace_reset_source_bits;
  wire  FireSim__tracerv_trace_insns_1_exception_source_ready;
  wire  FireSim__tracerv_trace_insns_1_exception_source_valid;
  wire  FireSim__tracerv_trace_insns_1_exception_source_bits;
  wire  FireSim__tracerv_4_trace_insns_0_tval_source_ready;
  wire  FireSim__tracerv_4_trace_insns_0_tval_source_valid;
  wire [39:0] FireSim__tracerv_4_trace_insns_0_tval_source_bits;
  wire  FireSim__tracerv_4_trace_insns_0_interrupt_source_ready;
  wire  FireSim__tracerv_4_trace_insns_0_interrupt_source_valid;
  wire  FireSim__tracerv_4_trace_insns_0_interrupt_source_bits;
  wire  FireSim__tracerv_2_trace_insns_0_iaddr_source_ready;
  wire  FireSim__tracerv_2_trace_insns_0_iaddr_source_valid;
  wire [39:0] FireSim__tracerv_2_trace_insns_0_iaddr_source_bits;
  wire  FireSim__tracerv_trace_insns_2_valid_source_ready;
  wire  FireSim__tracerv_trace_insns_2_valid_source_valid;
  wire  FireSim__tracerv_trace_insns_2_valid_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
    ;
  wire [2:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
    ;
  wire  FireSim__ep_1_axi4_w_fwd_source_ready;
  wire  FireSim__ep_1_axi4_w_fwd_source_valid;
  wire [7:0] FireSim__ep_1_axi4_w_fwd_source_bits_bits_strb;
  wire  FireSim__ep_1_axi4_w_fwd_source_bits_bits_last;
  wire [63:0] FireSim__ep_1_axi4_w_fwd_source_bits_bits_data;
  wire  FireSim__ep_1_axi4_w_fwd_source_bits_valid;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
    ;
  wire [2:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
    ;
  wire  FireSim__tracerv_2_trace_insns_0_interrupt_source_ready;
  wire  FireSim__tracerv_2_trace_insns_0_interrupt_source_valid;
  wire  FireSim__tracerv_2_trace_insns_0_interrupt_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
    ;
  wire  FireSim__tracerv_trace_insns_1_tval_source_ready;
  wire  FireSim__tracerv_trace_insns_1_tval_source_valid;
  wire [39:0] FireSim__tracerv_trace_insns_1_tval_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
    ;
  wire  FireSim__tracerv_1_trace_insns_0_insn_source_ready;
  wire  FireSim__tracerv_1_trace_insns_0_insn_source_valid;
  wire [31:0] FireSim__tracerv_1_trace_insns_0_insn_source_bits;
  wire  FireSim__tracerv_4_trace_insns_0_insn_source_ready;
  wire  FireSim__tracerv_4_trace_insns_0_insn_source_valid;
  wire [31:0] FireSim__tracerv_4_trace_insns_0_insn_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
    ;
  wire [31:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_6_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_6_source_valid
    ;
  wire  FireSim__ep_1_axi4_aw_fwd_source_ready;
  wire  FireSim__ep_1_axi4_aw_fwd_source_valid;
  wire [3:0] FireSim__ep_1_axi4_aw_fwd_source_bits_bits_id;
  wire [3:0] FireSim__ep_1_axi4_aw_fwd_source_bits_bits_qos;
  wire [2:0] FireSim__ep_1_axi4_aw_fwd_source_bits_bits_prot;
  wire [3:0] FireSim__ep_1_axi4_aw_fwd_source_bits_bits_cache;
  wire  FireSim__ep_1_axi4_aw_fwd_source_bits_bits_lock;
  wire [1:0] FireSim__ep_1_axi4_aw_fwd_source_bits_bits_burst;
  wire [2:0] FireSim__ep_1_axi4_aw_fwd_source_bits_bits_size;
  wire [7:0] FireSim__ep_1_axi4_aw_fwd_source_bits_bits_len;
  wire [34:0] FireSim__ep_1_axi4_aw_fwd_source_bits_bits_addr;
  wire  FireSim__ep_1_axi4_aw_fwd_source_bits_valid;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
    ;
  wire [63:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_valid
    ;
  wire [63:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_bits
    ;
  wire  FireSim__tracerv_4_trace_insns_0_valid_source_ready;
  wire  FireSim__tracerv_4_trace_insns_0_valid_source_valid;
  wire  FireSim__tracerv_4_trace_insns_0_valid_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
    ;
  wire [1:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
    ;
  wire [2:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
    ;
  wire  FireSim__tracerv_3_trace_insns_0_exception_source_ready;
  wire  FireSim__tracerv_3_trace_insns_0_exception_source_valid;
  wire  FireSim__tracerv_3_trace_insns_0_exception_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_5_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_5_source_valid
    ;
  wire  FireSim__tracerv_trace_insns_0_wdata_source_ready;
  wire  FireSim__tracerv_trace_insns_0_wdata_source_valid;
  wire [63:0] FireSim__tracerv_trace_insns_0_wdata_source_bits;
  wire  FireSim__tracerv_1_trace_insns_0_tval_source_ready;
  wire  FireSim__tracerv_1_trace_insns_0_tval_source_valid;
  wire [39:0] FireSim__tracerv_1_trace_insns_0_tval_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
    ;
  wire [1:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
    ;
  wire  FireSim__tracerv_trace_insns_1_priv_source_ready;
  wire  FireSim__tracerv_trace_insns_1_priv_source_valid;
  wire [2:0] FireSim__tracerv_trace_insns_1_priv_source_bits;
  wire  FireSim__tracerv_trace_insns_0_valid_source_ready;
  wire  FireSim__tracerv_trace_insns_0_valid_source_valid;
  wire  FireSim__tracerv_trace_insns_0_valid_source_bits;
  wire  FireSim__ep_2_uart_txd_source_ready;
  wire  FireSim__ep_2_uart_txd_source_valid;
  wire  FireSim__ep_2_uart_txd_source_bits;
  wire  FireSim__synthesizedPrintf_clockBridge_clocks_1_globalReset_source_ready;
  wire  FireSim__synthesizedPrintf_clockBridge_clocks_1_globalReset_source_valid;
  wire  FireSim__synthesizedPrintf_clockBridge_clocks_1_globalReset_source_bits;
  wire  FireSim__ep_tsi_out_fwd_source_ready;
  wire  FireSim__ep_tsi_out_fwd_source_valid;
  wire [31:0] FireSim__ep_tsi_out_fwd_source_bits_bits;
  wire  FireSim__ep_tsi_out_fwd_source_bits_valid;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_bits
    ;
  wire  FireSim__tracerv_4_trace_insns_0_priv_source_ready;
  wire  FireSim__tracerv_4_trace_insns_0_priv_source_valid;
  wire [2:0] FireSim__tracerv_4_trace_insns_0_priv_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
    ;
  wire [31:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
    ;
  wire  FireSim__tracerv_trace_insns_2_iaddr_source_ready;
  wire  FireSim__tracerv_trace_insns_2_iaddr_source_valid;
  wire [39:0] FireSim__tracerv_trace_insns_2_iaddr_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
    ;
  wire  FireSim__tracerv_1_trace_insns_0_cause_source_ready;
  wire  FireSim__tracerv_1_trace_insns_0_cause_source_valid;
  wire [63:0] FireSim__tracerv_1_trace_insns_0_cause_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
    ;
  wire [31:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
    ;
  wire  FireSim__tracerv_trace_insns_2_tval_source_ready;
  wire  FireSim__tracerv_trace_insns_2_tval_source_valid;
  wire [39:0] FireSim__tracerv_trace_insns_2_tval_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
    ;
  wire [63:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
    ;
  wire  FireSim__tracerv_4_trace_reset_source_ready;
  wire  FireSim__tracerv_4_trace_reset_source_valid;
  wire  FireSim__tracerv_4_trace_reset_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
    ;
  wire [2:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
    ;
  wire  FireSim__ep_3_bdev_req_fwd_source_ready;
  wire  FireSim__ep_3_bdev_req_fwd_source_valid;
  wire  FireSim__ep_3_bdev_req_fwd_source_bits_bits_tag;
  wire [31:0] FireSim__ep_3_bdev_req_fwd_source_bits_bits_len;
  wire [31:0] FireSim__ep_3_bdev_req_fwd_source_bits_bits_offset;
  wire  FireSim__ep_3_bdev_req_fwd_source_bits_bits_write;
  wire  FireSim__ep_3_bdev_req_fwd_source_bits_valid;
  wire  FireSim__tracerv_trace_insns_1_cause_source_ready;
  wire  FireSim__tracerv_trace_insns_1_cause_source_valid;
  wire [63:0] FireSim__tracerv_trace_insns_1_cause_source_bits;
  wire  FireSim__tracerv_2_trace_insns_0_valid_source_ready;
  wire  FireSim__tracerv_2_trace_insns_0_valid_source_valid;
  wire  FireSim__tracerv_2_trace_insns_0_valid_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
    ;
  wire [2:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_valid
    ;
  wire [63:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_9_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_9_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_valid
    ;
  wire [63:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_bits
    ;
  wire  FireSim__tracerv_3_trace_insns_0_priv_source_ready;
  wire  FireSim__tracerv_3_trace_insns_0_priv_source_valid;
  wire [2:0] FireSim__tracerv_3_trace_insns_0_priv_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
    ;
  wire [31:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
    ;
  wire  FireSim__tracerv_2_trace_insns_0_exception_source_ready;
  wire  FireSim__tracerv_2_trace_insns_0_exception_source_valid;
  wire  FireSim__tracerv_2_trace_insns_0_exception_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
    ;
  wire [63:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_valid
    ;
  wire [63:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
    ;
  wire  FireSim__tracerv_trace_insns_0_cause_source_ready;
  wire  FireSim__tracerv_trace_insns_0_cause_source_valid;
  wire [63:0] FireSim__tracerv_trace_insns_0_cause_source_bits;
  wire  FireSim__ep_1_axi4_b_ready_source_ready;
  wire  FireSim__ep_1_axi4_b_ready_source_valid;
  wire  FireSim__ep_1_axi4_b_ready_source_bits;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_valid
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_bits
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
    ;
  wire
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
    ;
  wire [1:0]
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
    ;
  wire  FireSim__tracerv_4_trace_insns_0_iaddr_source_ready;
  wire  FireSim__tracerv_4_trace_insns_0_iaddr_source_valid;
  wire [39:0] FireSim__tracerv_4_trace_insns_0_iaddr_source_bits;
  wire  FireSim__tracerv_3_trace_reset_source_ready;
  wire  FireSim__tracerv_3_trace_reset_source_valid;
  wire  FireSim__tracerv_3_trace_reset_source_bits;
  FireSim FireSim_ (
    .hostClock(FireSim__hostClock),
    .hostReset(FireSim__hostReset),
    .clockBridge_clocks_sink_ready(FireSim__clockBridge_clocks_sink_ready),
    .clockBridge_clocks_sink_bits__0(FireSim__clockBridge_clocks_sink_bits__0),
    .clockBridge_clocks_sink_bits__1(FireSim__clockBridge_clocks_sink_bits__1),
    .ep_1_axi4_aw_ready_sink_ready(FireSim__ep_1_axi4_aw_ready_sink_ready),
    .ep_1_axi4_aw_ready_sink_valid(FireSim__ep_1_axi4_aw_ready_sink_valid),
    .ep_1_axi4_aw_ready_sink_bits(FireSim__ep_1_axi4_aw_ready_sink_bits),
    .peekPokeBridge_reset_sink_ready(FireSim__peekPokeBridge_reset_sink_ready),
    .peekPokeBridge_reset_sink_valid(FireSim__peekPokeBridge_reset_sink_valid),
    .tracerv_3_triggerDebit_sink_ready(FireSim__tracerv_3_triggerDebit_sink_ready),
    .tracerv_3_triggerDebit_sink_valid(FireSim__tracerv_3_triggerDebit_sink_valid),
    .ep_3_bdev_info_nsectors_sink_ready(FireSim__ep_3_bdev_info_nsectors_sink_ready),
    .ep_3_bdev_info_nsectors_sink_valid(FireSim__ep_3_bdev_info_nsectors_sink_valid),
    .ep_3_bdev_info_nsectors_sink_bits(FireSim__ep_3_bdev_info_nsectors_sink_bits),
    .tracerv_triggerDebit_sink_ready(FireSim__tracerv_triggerDebit_sink_ready),
    .tracerv_triggerDebit_sink_valid(FireSim__tracerv_triggerDebit_sink_valid),
    .tracerv_2_triggerCredit_sink_ready(FireSim__tracerv_2_triggerCredit_sink_ready),
    .tracerv_2_triggerCredit_sink_valid(FireSim__tracerv_2_triggerCredit_sink_valid),
    .ep_3_bdev_info_max_req_len_sink_ready(FireSim__ep_3_bdev_info_max_req_len_sink_ready),
    .ep_3_bdev_info_max_req_len_sink_valid(FireSim__ep_3_bdev_info_max_req_len_sink_valid),
    .ep_3_bdev_info_max_req_len_sink_bits(FireSim__ep_3_bdev_info_max_req_len_sink_bits),
    .ep_3_bdev_req_ready_sink_ready(FireSim__ep_3_bdev_req_ready_sink_ready),
    .ep_3_bdev_req_ready_sink_valid(FireSim__ep_3_bdev_req_ready_sink_valid),
    .ep_3_bdev_req_ready_sink_bits(FireSim__ep_3_bdev_req_ready_sink_bits),
    .tracerv_triggerCredit_sink_ready(FireSim__tracerv_triggerCredit_sink_ready),
    .tracerv_triggerCredit_sink_valid(FireSim__tracerv_triggerCredit_sink_valid),
    .ep_3_bdev_resp_fwd_sink_ready(FireSim__ep_3_bdev_resp_fwd_sink_ready),
    .ep_3_bdev_resp_fwd_sink_valid(FireSim__ep_3_bdev_resp_fwd_sink_valid),
    .ep_3_bdev_resp_fwd_sink_bits_bits_tag(FireSim__ep_3_bdev_resp_fwd_sink_bits_bits_tag),
    .ep_3_bdev_resp_fwd_sink_bits_bits_data(FireSim__ep_3_bdev_resp_fwd_sink_bits_bits_data),
    .ep_3_bdev_resp_fwd_sink_bits_valid(FireSim__ep_3_bdev_resp_fwd_sink_bits_valid),
    .ep_1_axi4_ar_ready_sink_ready(FireSim__ep_1_axi4_ar_ready_sink_ready),
    .ep_1_axi4_ar_ready_sink_valid(FireSim__ep_1_axi4_ar_ready_sink_valid),
    .ep_1_axi4_ar_ready_sink_bits(FireSim__ep_1_axi4_ar_ready_sink_bits),
    .ep_tsi_out_ready_sink_ready(FireSim__ep_tsi_out_ready_sink_ready),
    .ep_tsi_out_ready_sink_valid(FireSim__ep_tsi_out_ready_sink_valid),
    .ep_tsi_out_ready_sink_bits(FireSim__ep_tsi_out_ready_sink_bits),
    .resetBridge_reset_sink_ready(FireSim__resetBridge_reset_sink_ready),
    .resetBridge_reset_sink_valid(FireSim__resetBridge_reset_sink_valid),
    .resetBridge_reset_sink_bits(FireSim__resetBridge_reset_sink_bits),
    .tracerv_4_triggerDebit_sink_ready(FireSim__tracerv_4_triggerDebit_sink_ready),
    .tracerv_4_triggerDebit_sink_valid(FireSim__tracerv_4_triggerDebit_sink_valid),
    .ep_1_axi4_w_ready_sink_ready(FireSim__ep_1_axi4_w_ready_sink_ready),
    .ep_1_axi4_w_ready_sink_valid(FireSim__ep_1_axi4_w_ready_sink_valid),
    .ep_1_axi4_w_ready_sink_bits(FireSim__ep_1_axi4_w_ready_sink_bits),
    .tracerv_1_triggerCredit_sink_ready(FireSim__tracerv_1_triggerCredit_sink_ready),
    .tracerv_1_triggerCredit_sink_valid(FireSim__tracerv_1_triggerCredit_sink_valid),
    .ep_tsi_in_fwd_sink_ready(FireSim__ep_tsi_in_fwd_sink_ready),
    .ep_tsi_in_fwd_sink_valid(FireSim__ep_tsi_in_fwd_sink_valid),
    .ep_tsi_in_fwd_sink_bits_bits(FireSim__ep_tsi_in_fwd_sink_bits_bits),
    .ep_tsi_in_fwd_sink_bits_valid(FireSim__ep_tsi_in_fwd_sink_bits_valid),
    .ep_2_uart_rxd_sink_ready(FireSim__ep_2_uart_rxd_sink_ready),
    .ep_2_uart_rxd_sink_valid(FireSim__ep_2_uart_rxd_sink_valid),
    .ep_2_uart_rxd_sink_bits(FireSim__ep_2_uart_rxd_sink_bits),
    .tracerv_1_triggerDebit_sink_ready(FireSim__tracerv_1_triggerDebit_sink_ready),
    .tracerv_1_triggerDebit_sink_valid(FireSim__tracerv_1_triggerDebit_sink_valid),
    .tracerv_4_triggerCredit_sink_ready(FireSim__tracerv_4_triggerCredit_sink_ready),
    .tracerv_4_triggerCredit_sink_valid(FireSim__tracerv_4_triggerCredit_sink_valid),
    .tracerv_2_triggerDebit_sink_ready(FireSim__tracerv_2_triggerDebit_sink_ready),
    .tracerv_2_triggerDebit_sink_valid(FireSim__tracerv_2_triggerDebit_sink_valid),
    .ep_3_bdev_data_ready_sink_ready(FireSim__ep_3_bdev_data_ready_sink_ready),
    .ep_3_bdev_data_ready_sink_valid(FireSim__ep_3_bdev_data_ready_sink_valid),
    .ep_3_bdev_data_ready_sink_bits(FireSim__ep_3_bdev_data_ready_sink_bits),
    .tracerv_3_triggerCredit_sink_ready(FireSim__tracerv_3_triggerCredit_sink_ready),
    .tracerv_3_triggerCredit_sink_valid(FireSim__tracerv_3_triggerCredit_sink_valid),
    .ep_1_axi4_b_fwd_sink_ready(FireSim__ep_1_axi4_b_fwd_sink_ready),
    .ep_1_axi4_b_fwd_sink_valid(FireSim__ep_1_axi4_b_fwd_sink_valid),
    .ep_1_axi4_b_fwd_sink_bits_bits_id(FireSim__ep_1_axi4_b_fwd_sink_bits_bits_id),
    .ep_1_axi4_b_fwd_sink_bits_valid(FireSim__ep_1_axi4_b_fwd_sink_bits_valid),
    .ep_1_axi4_r_fwd_sink_ready(FireSim__ep_1_axi4_r_fwd_sink_ready),
    .ep_1_axi4_r_fwd_sink_valid(FireSim__ep_1_axi4_r_fwd_sink_valid),
    .ep_1_axi4_r_fwd_sink_bits_bits_id(FireSim__ep_1_axi4_r_fwd_sink_bits_bits_id),
    .ep_1_axi4_r_fwd_sink_bits_bits_last(FireSim__ep_1_axi4_r_fwd_sink_bits_bits_last),
    .ep_1_axi4_r_fwd_sink_bits_bits_data(FireSim__ep_1_axi4_r_fwd_sink_bits_bits_data),
    .ep_1_axi4_r_fwd_sink_bits_valid(FireSim__ep_1_axi4_r_fwd_sink_bits_valid),
    .ep_1_axi4_ar_fwd_source_ready(FireSim__ep_1_axi4_ar_fwd_source_ready),
    .ep_1_axi4_ar_fwd_source_valid(FireSim__ep_1_axi4_ar_fwd_source_valid),
    .ep_1_axi4_ar_fwd_source_bits_bits_id(FireSim__ep_1_axi4_ar_fwd_source_bits_bits_id),
    .ep_1_axi4_ar_fwd_source_bits_bits_qos(FireSim__ep_1_axi4_ar_fwd_source_bits_bits_qos),
    .ep_1_axi4_ar_fwd_source_bits_bits_prot(FireSim__ep_1_axi4_ar_fwd_source_bits_bits_prot),
    .ep_1_axi4_ar_fwd_source_bits_bits_cache(FireSim__ep_1_axi4_ar_fwd_source_bits_bits_cache),
    .ep_1_axi4_ar_fwd_source_bits_bits_lock(FireSim__ep_1_axi4_ar_fwd_source_bits_bits_lock),
    .ep_1_axi4_ar_fwd_source_bits_bits_burst(FireSim__ep_1_axi4_ar_fwd_source_bits_bits_burst),
    .ep_1_axi4_ar_fwd_source_bits_bits_size(FireSim__ep_1_axi4_ar_fwd_source_bits_bits_size),
    .ep_1_axi4_ar_fwd_source_bits_bits_len(FireSim__ep_1_axi4_ar_fwd_source_bits_bits_len),
    .ep_1_axi4_ar_fwd_source_bits_bits_addr(FireSim__ep_1_axi4_ar_fwd_source_bits_bits_addr),
    .ep_1_axi4_ar_fwd_source_bits_valid(FireSim__ep_1_axi4_ar_fwd_source_bits_valid),
    .ep_3_bdev_data_fwd_source_ready(FireSim__ep_3_bdev_data_fwd_source_ready),
    .ep_3_bdev_data_fwd_source_valid(FireSim__ep_3_bdev_data_fwd_source_valid),
    .ep_3_bdev_data_fwd_source_bits_bits_tag(FireSim__ep_3_bdev_data_fwd_source_bits_bits_tag),
    .ep_3_bdev_data_fwd_source_bits_bits_data(FireSim__ep_3_bdev_data_fwd_source_bits_bits_data),
    .ep_3_bdev_data_fwd_source_bits_valid(FireSim__ep_3_bdev_data_fwd_source_bits_valid),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
      ),
    .tracerv_1_trace_insns_0_interrupt_source_ready(FireSim__tracerv_1_trace_insns_0_interrupt_source_ready),
    .tracerv_1_trace_insns_0_interrupt_source_valid(FireSim__tracerv_1_trace_insns_0_interrupt_source_valid),
    .tracerv_1_trace_insns_0_interrupt_source_bits(FireSim__tracerv_1_trace_insns_0_interrupt_source_bits),
    .tracerv_1_trace_insns_0_iaddr_source_ready(FireSim__tracerv_1_trace_insns_0_iaddr_source_ready),
    .tracerv_1_trace_insns_0_iaddr_source_valid(FireSim__tracerv_1_trace_insns_0_iaddr_source_valid),
    .tracerv_1_trace_insns_0_iaddr_source_bits(FireSim__tracerv_1_trace_insns_0_iaddr_source_bits),
    .tracerv_trace_insns_2_priv_source_ready(FireSim__tracerv_trace_insns_2_priv_source_ready),
    .tracerv_trace_insns_2_priv_source_valid(FireSim__tracerv_trace_insns_2_priv_source_valid),
    .tracerv_trace_insns_2_priv_source_bits(FireSim__tracerv_trace_insns_2_priv_source_bits),
    .tracerv_trace_insns_0_insn_source_ready(FireSim__tracerv_trace_insns_0_insn_source_ready),
    .tracerv_trace_insns_0_insn_source_valid(FireSim__tracerv_trace_insns_0_insn_source_valid),
    .tracerv_trace_insns_0_insn_source_bits(FireSim__tracerv_trace_insns_0_insn_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
      ),
    .tracerv_2_trace_insns_0_cause_source_ready(FireSim__tracerv_2_trace_insns_0_cause_source_ready),
    .tracerv_2_trace_insns_0_cause_source_valid(FireSim__tracerv_2_trace_insns_0_cause_source_valid),
    .tracerv_2_trace_insns_0_cause_source_bits(FireSim__tracerv_2_trace_insns_0_cause_source_bits),
    .tracerv_trace_insns_0_tval_source_ready(FireSim__tracerv_trace_insns_0_tval_source_ready),
    .tracerv_trace_insns_0_tval_source_valid(FireSim__tracerv_trace_insns_0_tval_source_valid),
    .tracerv_trace_insns_0_tval_source_bits(FireSim__tracerv_trace_insns_0_tval_source_bits),
    .tracerv_trace_insns_1_insn_source_ready(FireSim__tracerv_trace_insns_1_insn_source_ready),
    .tracerv_trace_insns_1_insn_source_valid(FireSim__tracerv_trace_insns_1_insn_source_valid),
    .tracerv_trace_insns_1_insn_source_bits(FireSim__tracerv_trace_insns_1_insn_source_bits),
    .tracerv_3_trace_insns_0_tval_source_ready(FireSim__tracerv_3_trace_insns_0_tval_source_ready),
    .tracerv_3_trace_insns_0_tval_source_valid(FireSim__tracerv_3_trace_insns_0_tval_source_valid),
    .tracerv_3_trace_insns_0_tval_source_bits(FireSim__tracerv_3_trace_insns_0_tval_source_bits),
    .tracerv_trace_insns_2_interrupt_source_ready(FireSim__tracerv_trace_insns_2_interrupt_source_ready),
    .tracerv_trace_insns_2_interrupt_source_valid(FireSim__tracerv_trace_insns_2_interrupt_source_valid),
    .tracerv_trace_insns_2_interrupt_source_bits(FireSim__tracerv_trace_insns_2_interrupt_source_bits),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
      ),
    .ep_1_axi4_r_ready_source_ready(FireSim__ep_1_axi4_r_ready_source_ready),
    .ep_1_axi4_r_ready_source_valid(FireSim__ep_1_axi4_r_ready_source_valid),
    .ep_1_axi4_r_ready_source_bits(FireSim__ep_1_axi4_r_ready_source_bits),
    .tracerv_trace_insns_2_wdata_source_ready(FireSim__tracerv_trace_insns_2_wdata_source_ready),
    .tracerv_trace_insns_2_wdata_source_valid(FireSim__tracerv_trace_insns_2_wdata_source_valid),
    .tracerv_trace_insns_2_wdata_source_bits(FireSim__tracerv_trace_insns_2_wdata_source_bits),
    .tracerv_4_trace_insns_0_cause_source_ready(FireSim__tracerv_4_trace_insns_0_cause_source_ready),
    .tracerv_4_trace_insns_0_cause_source_valid(FireSim__tracerv_4_trace_insns_0_cause_source_valid),
    .tracerv_4_trace_insns_0_cause_source_bits(FireSim__tracerv_4_trace_insns_0_cause_source_bits),
    .tracerv_trace_insns_0_exception_source_ready(FireSim__tracerv_trace_insns_0_exception_source_ready),
    .tracerv_trace_insns_0_exception_source_valid(FireSim__tracerv_trace_insns_0_exception_source_valid),
    .tracerv_trace_insns_0_exception_source_bits(FireSim__tracerv_trace_insns_0_exception_source_bits),
    .synthesizedPrintf_clockBridge_clocks_0_globalReset_source_ready(
      FireSim__synthesizedPrintf_clockBridge_clocks_0_globalReset_source_ready),
    .synthesizedPrintf_clockBridge_clocks_0_globalReset_source_valid(
      FireSim__synthesizedPrintf_clockBridge_clocks_0_globalReset_source_valid),
    .synthesizedPrintf_clockBridge_clocks_0_globalReset_source_bits(
      FireSim__synthesizedPrintf_clockBridge_clocks_0_globalReset_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
      ),
    .tracerv_3_trace_insns_0_iaddr_source_ready(FireSim__tracerv_3_trace_insns_0_iaddr_source_ready),
    .tracerv_3_trace_insns_0_iaddr_source_valid(FireSim__tracerv_3_trace_insns_0_iaddr_source_valid),
    .tracerv_3_trace_insns_0_iaddr_source_bits(FireSim__tracerv_3_trace_insns_0_iaddr_source_bits),
    .tracerv_trace_insns_2_insn_source_ready(FireSim__tracerv_trace_insns_2_insn_source_ready),
    .tracerv_trace_insns_2_insn_source_valid(FireSim__tracerv_trace_insns_2_insn_source_valid),
    .tracerv_trace_insns_2_insn_source_bits(FireSim__tracerv_trace_insns_2_insn_source_bits),
    .tracerv_trace_insns_1_iaddr_source_ready(FireSim__tracerv_trace_insns_1_iaddr_source_ready),
    .tracerv_trace_insns_1_iaddr_source_valid(FireSim__tracerv_trace_insns_1_iaddr_source_valid),
    .tracerv_trace_insns_1_iaddr_source_bits(FireSim__tracerv_trace_insns_1_iaddr_source_bits),
    .tracerv_1_trace_insns_0_valid_source_ready(FireSim__tracerv_1_trace_insns_0_valid_source_ready),
    .tracerv_1_trace_insns_0_valid_source_valid(FireSim__tracerv_1_trace_insns_0_valid_source_valid),
    .tracerv_1_trace_insns_0_valid_source_bits(FireSim__tracerv_1_trace_insns_0_valid_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
      ),
    .tracerv_4_trace_insns_0_exception_source_ready(FireSim__tracerv_4_trace_insns_0_exception_source_ready),
    .tracerv_4_trace_insns_0_exception_source_valid(FireSim__tracerv_4_trace_insns_0_exception_source_valid),
    .tracerv_4_trace_insns_0_exception_source_bits(FireSim__tracerv_4_trace_insns_0_exception_source_bits),
    .tracerv_trace_insns_0_iaddr_source_ready(FireSim__tracerv_trace_insns_0_iaddr_source_ready),
    .tracerv_trace_insns_0_iaddr_source_valid(FireSim__tracerv_trace_insns_0_iaddr_source_valid),
    .tracerv_trace_insns_0_iaddr_source_bits(FireSim__tracerv_trace_insns_0_iaddr_source_bits),
    .tracerv_3_trace_insns_0_valid_source_ready(FireSim__tracerv_3_trace_insns_0_valid_source_ready),
    .tracerv_3_trace_insns_0_valid_source_valid(FireSim__tracerv_3_trace_insns_0_valid_source_valid),
    .tracerv_3_trace_insns_0_valid_source_bits(FireSim__tracerv_3_trace_insns_0_valid_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_valid
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_bits
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_8_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_8_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_8_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_8_source_valid
      ),
    .tracerv_1_trace_insns_0_priv_source_ready(FireSim__tracerv_1_trace_insns_0_priv_source_ready),
    .tracerv_1_trace_insns_0_priv_source_valid(FireSim__tracerv_1_trace_insns_0_priv_source_valid),
    .tracerv_1_trace_insns_0_priv_source_bits(FireSim__tracerv_1_trace_insns_0_priv_source_bits),
    .tracerv_trace_insns_2_exception_source_ready(FireSim__tracerv_trace_insns_2_exception_source_ready),
    .tracerv_trace_insns_2_exception_source_valid(FireSim__tracerv_trace_insns_2_exception_source_valid),
    .tracerv_trace_insns_2_exception_source_bits(FireSim__tracerv_trace_insns_2_exception_source_bits),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
      ),
    .tracerv_trace_insns_1_wdata_source_ready(FireSim__tracerv_trace_insns_1_wdata_source_ready),
    .tracerv_trace_insns_1_wdata_source_valid(FireSim__tracerv_trace_insns_1_wdata_source_valid),
    .tracerv_trace_insns_1_wdata_source_bits(FireSim__tracerv_trace_insns_1_wdata_source_bits),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
      ),
    .tracerv_2_trace_insns_0_priv_source_ready(FireSim__tracerv_2_trace_insns_0_priv_source_ready),
    .tracerv_2_trace_insns_0_priv_source_valid(FireSim__tracerv_2_trace_insns_0_priv_source_valid),
    .tracerv_2_trace_insns_0_priv_source_bits(FireSim__tracerv_2_trace_insns_0_priv_source_bits),
    .tracerv_3_trace_insns_0_insn_source_ready(FireSim__tracerv_3_trace_insns_0_insn_source_ready),
    .tracerv_3_trace_insns_0_insn_source_valid(FireSim__tracerv_3_trace_insns_0_insn_source_valid),
    .tracerv_3_trace_insns_0_insn_source_bits(FireSim__tracerv_3_trace_insns_0_insn_source_bits),
    .ep_1_reset_source_ready(FireSim__ep_1_reset_source_ready),
    .ep_1_reset_source_valid(FireSim__ep_1_reset_source_valid),
    .ep_1_reset_source_bits(FireSim__ep_1_reset_source_bits),
    .tracerv_2_trace_insns_0_tval_source_ready(FireSim__tracerv_2_trace_insns_0_tval_source_ready),
    .tracerv_2_trace_insns_0_tval_source_valid(FireSim__tracerv_2_trace_insns_0_tval_source_valid),
    .tracerv_2_trace_insns_0_tval_source_bits(FireSim__tracerv_2_trace_insns_0_tval_source_bits),
    .tracerv_3_trace_insns_0_cause_source_ready(FireSim__tracerv_3_trace_insns_0_cause_source_ready),
    .tracerv_3_trace_insns_0_cause_source_valid(FireSim__tracerv_3_trace_insns_0_cause_source_valid),
    .tracerv_3_trace_insns_0_cause_source_bits(FireSim__tracerv_3_trace_insns_0_cause_source_bits),
    .ep_3_bdev_resp_ready_source_ready(FireSim__ep_3_bdev_resp_ready_source_ready),
    .ep_3_bdev_resp_ready_source_valid(FireSim__ep_3_bdev_resp_ready_source_valid),
    .ep_3_bdev_resp_ready_source_bits(FireSim__ep_3_bdev_resp_ready_source_bits),
    .tracerv_1_trace_reset_source_ready(FireSim__tracerv_1_trace_reset_source_ready),
    .tracerv_1_trace_reset_source_valid(FireSim__tracerv_1_trace_reset_source_valid),
    .tracerv_1_trace_reset_source_bits(FireSim__tracerv_1_trace_reset_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
      ),
    .tracerv_trace_insns_1_interrupt_source_ready(FireSim__tracerv_trace_insns_1_interrupt_source_ready),
    .tracerv_trace_insns_1_interrupt_source_valid(FireSim__tracerv_trace_insns_1_interrupt_source_valid),
    .tracerv_trace_insns_1_interrupt_source_bits(FireSim__tracerv_trace_insns_1_interrupt_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
      ),
    .tracerv_trace_insns_0_interrupt_source_ready(FireSim__tracerv_trace_insns_0_interrupt_source_ready),
    .tracerv_trace_insns_0_interrupt_source_valid(FireSim__tracerv_trace_insns_0_interrupt_source_valid),
    .tracerv_trace_insns_0_interrupt_source_bits(FireSim__tracerv_trace_insns_0_interrupt_source_bits),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
      ),
    .ep_tsi_in_ready_source_ready(FireSim__ep_tsi_in_ready_source_ready),
    .ep_tsi_in_ready_source_valid(FireSim__ep_tsi_in_ready_source_valid),
    .ep_tsi_in_ready_source_bits(FireSim__ep_tsi_in_ready_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
      ),
    .tracerv_trace_insns_2_cause_source_ready(FireSim__tracerv_trace_insns_2_cause_source_ready),
    .tracerv_trace_insns_2_cause_source_valid(FireSim__tracerv_trace_insns_2_cause_source_valid),
    .tracerv_trace_insns_2_cause_source_bits(FireSim__tracerv_trace_insns_2_cause_source_bits),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_bits
      ),
    .tracerv_2_trace_insns_0_insn_source_ready(FireSim__tracerv_2_trace_insns_0_insn_source_ready),
    .tracerv_2_trace_insns_0_insn_source_valid(FireSim__tracerv_2_trace_insns_0_insn_source_valid),
    .tracerv_2_trace_insns_0_insn_source_bits(FireSim__tracerv_2_trace_insns_0_insn_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_valid
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_bits
      ),
    .tracerv_1_trace_insns_0_exception_source_ready(FireSim__tracerv_1_trace_insns_0_exception_source_ready),
    .tracerv_1_trace_insns_0_exception_source_valid(FireSim__tracerv_1_trace_insns_0_exception_source_valid),
    .tracerv_1_trace_insns_0_exception_source_bits(FireSim__tracerv_1_trace_insns_0_exception_source_bits),
    .tracerv_trace_insns_0_priv_source_ready(FireSim__tracerv_trace_insns_0_priv_source_ready),
    .tracerv_trace_insns_0_priv_source_valid(FireSim__tracerv_trace_insns_0_priv_source_valid),
    .tracerv_trace_insns_0_priv_source_bits(FireSim__tracerv_trace_insns_0_priv_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_7_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_7_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_7_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_7_source_valid
      ),
    .tracerv_trace_reset_source_ready(FireSim__tracerv_trace_reset_source_ready),
    .tracerv_trace_reset_source_valid(FireSim__tracerv_trace_reset_source_valid),
    .tracerv_trace_reset_source_bits(FireSim__tracerv_trace_reset_source_bits),
    .tracerv_3_trace_insns_0_interrupt_source_ready(FireSim__tracerv_3_trace_insns_0_interrupt_source_ready),
    .tracerv_3_trace_insns_0_interrupt_source_valid(FireSim__tracerv_3_trace_insns_0_interrupt_source_valid),
    .tracerv_3_trace_insns_0_interrupt_source_bits(FireSim__tracerv_3_trace_insns_0_interrupt_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_10_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_10_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_10_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_10_source_valid
      ),
    .tracerv_trace_insns_1_valid_source_ready(FireSim__tracerv_trace_insns_1_valid_source_ready),
    .tracerv_trace_insns_1_valid_source_valid(FireSim__tracerv_trace_insns_1_valid_source_valid),
    .tracerv_trace_insns_1_valid_source_bits(FireSim__tracerv_trace_insns_1_valid_source_bits),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_bits
      ),
    .tracerv_2_trace_reset_source_ready(FireSim__tracerv_2_trace_reset_source_ready),
    .tracerv_2_trace_reset_source_valid(FireSim__tracerv_2_trace_reset_source_valid),
    .tracerv_2_trace_reset_source_bits(FireSim__tracerv_2_trace_reset_source_bits),
    .tracerv_trace_insns_1_exception_source_ready(FireSim__tracerv_trace_insns_1_exception_source_ready),
    .tracerv_trace_insns_1_exception_source_valid(FireSim__tracerv_trace_insns_1_exception_source_valid),
    .tracerv_trace_insns_1_exception_source_bits(FireSim__tracerv_trace_insns_1_exception_source_bits),
    .tracerv_4_trace_insns_0_tval_source_ready(FireSim__tracerv_4_trace_insns_0_tval_source_ready),
    .tracerv_4_trace_insns_0_tval_source_valid(FireSim__tracerv_4_trace_insns_0_tval_source_valid),
    .tracerv_4_trace_insns_0_tval_source_bits(FireSim__tracerv_4_trace_insns_0_tval_source_bits),
    .tracerv_4_trace_insns_0_interrupt_source_ready(FireSim__tracerv_4_trace_insns_0_interrupt_source_ready),
    .tracerv_4_trace_insns_0_interrupt_source_valid(FireSim__tracerv_4_trace_insns_0_interrupt_source_valid),
    .tracerv_4_trace_insns_0_interrupt_source_bits(FireSim__tracerv_4_trace_insns_0_interrupt_source_bits),
    .tracerv_2_trace_insns_0_iaddr_source_ready(FireSim__tracerv_2_trace_insns_0_iaddr_source_ready),
    .tracerv_2_trace_insns_0_iaddr_source_valid(FireSim__tracerv_2_trace_insns_0_iaddr_source_valid),
    .tracerv_2_trace_insns_0_iaddr_source_bits(FireSim__tracerv_2_trace_insns_0_iaddr_source_bits),
    .tracerv_trace_insns_2_valid_source_ready(FireSim__tracerv_trace_insns_2_valid_source_ready),
    .tracerv_trace_insns_2_valid_source_valid(FireSim__tracerv_trace_insns_2_valid_source_valid),
    .tracerv_trace_insns_2_valid_source_bits(FireSim__tracerv_trace_insns_2_valid_source_bits),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
      ),
    .ep_1_axi4_w_fwd_source_ready(FireSim__ep_1_axi4_w_fwd_source_ready),
    .ep_1_axi4_w_fwd_source_valid(FireSim__ep_1_axi4_w_fwd_source_valid),
    .ep_1_axi4_w_fwd_source_bits_bits_strb(FireSim__ep_1_axi4_w_fwd_source_bits_bits_strb),
    .ep_1_axi4_w_fwd_source_bits_bits_last(FireSim__ep_1_axi4_w_fwd_source_bits_bits_last),
    .ep_1_axi4_w_fwd_source_bits_bits_data(FireSim__ep_1_axi4_w_fwd_source_bits_bits_data),
    .ep_1_axi4_w_fwd_source_bits_valid(FireSim__ep_1_axi4_w_fwd_source_bits_valid),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
      ),
    .tracerv_2_trace_insns_0_interrupt_source_ready(FireSim__tracerv_2_trace_insns_0_interrupt_source_ready),
    .tracerv_2_trace_insns_0_interrupt_source_valid(FireSim__tracerv_2_trace_insns_0_interrupt_source_valid),
    .tracerv_2_trace_insns_0_interrupt_source_bits(FireSim__tracerv_2_trace_insns_0_interrupt_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_valid
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_bits
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
      ),
    .tracerv_trace_insns_1_tval_source_ready(FireSim__tracerv_trace_insns_1_tval_source_ready),
    .tracerv_trace_insns_1_tval_source_valid(FireSim__tracerv_trace_insns_1_tval_source_valid),
    .tracerv_trace_insns_1_tval_source_bits(FireSim__tracerv_trace_insns_1_tval_source_bits),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_bits
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
      ),
    .tracerv_1_trace_insns_0_insn_source_ready(FireSim__tracerv_1_trace_insns_0_insn_source_ready),
    .tracerv_1_trace_insns_0_insn_source_valid(FireSim__tracerv_1_trace_insns_0_insn_source_valid),
    .tracerv_1_trace_insns_0_insn_source_bits(FireSim__tracerv_1_trace_insns_0_insn_source_bits),
    .tracerv_4_trace_insns_0_insn_source_ready(FireSim__tracerv_4_trace_insns_0_insn_source_ready),
    .tracerv_4_trace_insns_0_insn_source_valid(FireSim__tracerv_4_trace_insns_0_insn_source_valid),
    .tracerv_4_trace_insns_0_insn_source_bits(FireSim__tracerv_4_trace_insns_0_insn_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_6_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_6_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_6_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_6_source_valid
      ),
    .ep_1_axi4_aw_fwd_source_ready(FireSim__ep_1_axi4_aw_fwd_source_ready),
    .ep_1_axi4_aw_fwd_source_valid(FireSim__ep_1_axi4_aw_fwd_source_valid),
    .ep_1_axi4_aw_fwd_source_bits_bits_id(FireSim__ep_1_axi4_aw_fwd_source_bits_bits_id),
    .ep_1_axi4_aw_fwd_source_bits_bits_qos(FireSim__ep_1_axi4_aw_fwd_source_bits_bits_qos),
    .ep_1_axi4_aw_fwd_source_bits_bits_prot(FireSim__ep_1_axi4_aw_fwd_source_bits_bits_prot),
    .ep_1_axi4_aw_fwd_source_bits_bits_cache(FireSim__ep_1_axi4_aw_fwd_source_bits_bits_cache),
    .ep_1_axi4_aw_fwd_source_bits_bits_lock(FireSim__ep_1_axi4_aw_fwd_source_bits_bits_lock),
    .ep_1_axi4_aw_fwd_source_bits_bits_burst(FireSim__ep_1_axi4_aw_fwd_source_bits_bits_burst),
    .ep_1_axi4_aw_fwd_source_bits_bits_size(FireSim__ep_1_axi4_aw_fwd_source_bits_bits_size),
    .ep_1_axi4_aw_fwd_source_bits_bits_len(FireSim__ep_1_axi4_aw_fwd_source_bits_bits_len),
    .ep_1_axi4_aw_fwd_source_bits_bits_addr(FireSim__ep_1_axi4_aw_fwd_source_bits_bits_addr),
    .ep_1_axi4_aw_fwd_source_bits_valid(FireSim__ep_1_axi4_aw_fwd_source_bits_valid),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_valid
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_bits
      ),
    .tracerv_4_trace_insns_0_valid_source_ready(FireSim__tracerv_4_trace_insns_0_valid_source_ready),
    .tracerv_4_trace_insns_0_valid_source_valid(FireSim__tracerv_4_trace_insns_0_valid_source_valid),
    .tracerv_4_trace_insns_0_valid_source_bits(FireSim__tracerv_4_trace_insns_0_valid_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
      ),
    .tracerv_3_trace_insns_0_exception_source_ready(FireSim__tracerv_3_trace_insns_0_exception_source_ready),
    .tracerv_3_trace_insns_0_exception_source_valid(FireSim__tracerv_3_trace_insns_0_exception_source_valid),
    .tracerv_3_trace_insns_0_exception_source_bits(FireSim__tracerv_3_trace_insns_0_exception_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_5_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_5_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_5_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_5_source_valid
      ),
    .tracerv_trace_insns_0_wdata_source_ready(FireSim__tracerv_trace_insns_0_wdata_source_ready),
    .tracerv_trace_insns_0_wdata_source_valid(FireSim__tracerv_trace_insns_0_wdata_source_valid),
    .tracerv_trace_insns_0_wdata_source_bits(FireSim__tracerv_trace_insns_0_wdata_source_bits),
    .tracerv_1_trace_insns_0_tval_source_ready(FireSim__tracerv_1_trace_insns_0_tval_source_ready),
    .tracerv_1_trace_insns_0_tval_source_valid(FireSim__tracerv_1_trace_insns_0_tval_source_valid),
    .tracerv_1_trace_insns_0_tval_source_bits(FireSim__tracerv_1_trace_insns_0_tval_source_bits),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
      ),
    .tracerv_trace_insns_1_priv_source_ready(FireSim__tracerv_trace_insns_1_priv_source_ready),
    .tracerv_trace_insns_1_priv_source_valid(FireSim__tracerv_trace_insns_1_priv_source_valid),
    .tracerv_trace_insns_1_priv_source_bits(FireSim__tracerv_trace_insns_1_priv_source_bits),
    .tracerv_trace_insns_0_valid_source_ready(FireSim__tracerv_trace_insns_0_valid_source_ready),
    .tracerv_trace_insns_0_valid_source_valid(FireSim__tracerv_trace_insns_0_valid_source_valid),
    .tracerv_trace_insns_0_valid_source_bits(FireSim__tracerv_trace_insns_0_valid_source_bits),
    .ep_2_uart_txd_source_ready(FireSim__ep_2_uart_txd_source_ready),
    .ep_2_uart_txd_source_valid(FireSim__ep_2_uart_txd_source_valid),
    .ep_2_uart_txd_source_bits(FireSim__ep_2_uart_txd_source_bits),
    .synthesizedPrintf_clockBridge_clocks_1_globalReset_source_ready(
      FireSim__synthesizedPrintf_clockBridge_clocks_1_globalReset_source_ready),
    .synthesizedPrintf_clockBridge_clocks_1_globalReset_source_valid(
      FireSim__synthesizedPrintf_clockBridge_clocks_1_globalReset_source_valid),
    .synthesizedPrintf_clockBridge_clocks_1_globalReset_source_bits(
      FireSim__synthesizedPrintf_clockBridge_clocks_1_globalReset_source_bits),
    .ep_tsi_out_fwd_source_ready(FireSim__ep_tsi_out_fwd_source_ready),
    .ep_tsi_out_fwd_source_valid(FireSim__ep_tsi_out_fwd_source_valid),
    .ep_tsi_out_fwd_source_bits_bits(FireSim__ep_tsi_out_fwd_source_bits_bits),
    .ep_tsi_out_fwd_source_bits_valid(FireSim__ep_tsi_out_fwd_source_bits_valid),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_valid
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_bits
      ),
    .tracerv_4_trace_insns_0_priv_source_ready(FireSim__tracerv_4_trace_insns_0_priv_source_ready),
    .tracerv_4_trace_insns_0_priv_source_valid(FireSim__tracerv_4_trace_insns_0_priv_source_valid),
    .tracerv_4_trace_insns_0_priv_source_bits(FireSim__tracerv_4_trace_insns_0_priv_source_bits),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
      ),
    .tracerv_trace_insns_2_iaddr_source_ready(FireSim__tracerv_trace_insns_2_iaddr_source_ready),
    .tracerv_trace_insns_2_iaddr_source_valid(FireSim__tracerv_trace_insns_2_iaddr_source_valid),
    .tracerv_trace_insns_2_iaddr_source_bits(FireSim__tracerv_trace_insns_2_iaddr_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
      ),
    .tracerv_1_trace_insns_0_cause_source_ready(FireSim__tracerv_1_trace_insns_0_cause_source_ready),
    .tracerv_1_trace_insns_0_cause_source_valid(FireSim__tracerv_1_trace_insns_0_cause_source_valid),
    .tracerv_1_trace_insns_0_cause_source_bits(FireSim__tracerv_1_trace_insns_0_cause_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
      ),
    .tracerv_trace_insns_2_tval_source_ready(FireSim__tracerv_trace_insns_2_tval_source_ready),
    .tracerv_trace_insns_2_tval_source_valid(FireSim__tracerv_trace_insns_2_tval_source_valid),
    .tracerv_trace_insns_2_tval_source_bits(FireSim__tracerv_trace_insns_2_tval_source_bits),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
      ),
    .tracerv_4_trace_reset_source_ready(FireSim__tracerv_4_trace_reset_source_ready),
    .tracerv_4_trace_reset_source_valid(FireSim__tracerv_4_trace_reset_source_valid),
    .tracerv_4_trace_reset_source_bits(FireSim__tracerv_4_trace_reset_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
      ),
    .ep_3_bdev_req_fwd_source_ready(FireSim__ep_3_bdev_req_fwd_source_ready),
    .ep_3_bdev_req_fwd_source_valid(FireSim__ep_3_bdev_req_fwd_source_valid),
    .ep_3_bdev_req_fwd_source_bits_bits_tag(FireSim__ep_3_bdev_req_fwd_source_bits_bits_tag),
    .ep_3_bdev_req_fwd_source_bits_bits_len(FireSim__ep_3_bdev_req_fwd_source_bits_bits_len),
    .ep_3_bdev_req_fwd_source_bits_bits_offset(FireSim__ep_3_bdev_req_fwd_source_bits_bits_offset),
    .ep_3_bdev_req_fwd_source_bits_bits_write(FireSim__ep_3_bdev_req_fwd_source_bits_bits_write),
    .ep_3_bdev_req_fwd_source_bits_valid(FireSim__ep_3_bdev_req_fwd_source_bits_valid),
    .tracerv_trace_insns_1_cause_source_ready(FireSim__tracerv_trace_insns_1_cause_source_ready),
    .tracerv_trace_insns_1_cause_source_valid(FireSim__tracerv_trace_insns_1_cause_source_valid),
    .tracerv_trace_insns_1_cause_source_bits(FireSim__tracerv_trace_insns_1_cause_source_bits),
    .tracerv_2_trace_insns_0_valid_source_ready(FireSim__tracerv_2_trace_insns_0_valid_source_ready),
    .tracerv_2_trace_insns_0_valid_source_valid(FireSim__tracerv_2_trace_insns_0_valid_source_valid),
    .tracerv_2_trace_insns_0_valid_source_bits(FireSim__tracerv_2_trace_insns_0_valid_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_valid
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_bits
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_9_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_9_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_9_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_9_source_valid
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_valid
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_bits
      ),
    .tracerv_3_trace_insns_0_priv_source_ready(FireSim__tracerv_3_trace_insns_0_priv_source_ready),
    .tracerv_3_trace_insns_0_priv_source_valid(FireSim__tracerv_3_trace_insns_0_priv_source_valid),
    .tracerv_3_trace_insns_0_priv_source_bits(FireSim__tracerv_3_trace_insns_0_priv_source_bits),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
      ),
    .tracerv_2_trace_insns_0_exception_source_ready(FireSim__tracerv_2_trace_insns_0_exception_source_ready),
    .tracerv_2_trace_insns_0_exception_source_valid(FireSim__tracerv_2_trace_insns_0_exception_source_valid),
    .tracerv_2_trace_insns_0_exception_source_bits(FireSim__tracerv_2_trace_insns_0_exception_source_bits),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_valid
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_bits
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
      ),
    .
      synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
      (
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
      ),
    .tracerv_trace_insns_0_cause_source_ready(FireSim__tracerv_trace_insns_0_cause_source_ready),
    .tracerv_trace_insns_0_cause_source_valid(FireSim__tracerv_trace_insns_0_cause_source_valid),
    .tracerv_trace_insns_0_cause_source_bits(FireSim__tracerv_trace_insns_0_cause_source_bits),
    .ep_1_axi4_b_ready_source_ready(FireSim__ep_1_axi4_b_ready_source_ready),
    .ep_1_axi4_b_ready_source_valid(FireSim__ep_1_axi4_b_ready_source_valid),
    .ep_1_axi4_b_ready_source_bits(FireSim__ep_1_axi4_b_ready_source_bits),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_bits
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_ready(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_valid(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
      ),
    .synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_bits(
      FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
      ),
    .tracerv_4_trace_insns_0_iaddr_source_ready(FireSim__tracerv_4_trace_insns_0_iaddr_source_ready),
    .tracerv_4_trace_insns_0_iaddr_source_valid(FireSim__tracerv_4_trace_insns_0_iaddr_source_valid),
    .tracerv_4_trace_insns_0_iaddr_source_bits(FireSim__tracerv_4_trace_insns_0_iaddr_source_bits),
    .tracerv_3_trace_reset_source_ready(FireSim__tracerv_3_trace_reset_source_ready),
    .tracerv_3_trace_reset_source_valid(FireSim__tracerv_3_trace_reset_source_valid),
    .tracerv_3_trace_reset_source_bits(FireSim__tracerv_3_trace_reset_source_bits)
  );
  assign FireSim_peekPokeBridge_reset_sink_ready = FireSim__peekPokeBridge_reset_sink_ready;
  assign FireSim_ep_tsi_out_ready_sink_ready = FireSim__ep_tsi_out_ready_sink_ready;
  assign FireSim_ep_tsi_in_fwd_sink_ready = FireSim__ep_tsi_in_fwd_sink_ready;
  assign FireSim_ep_1_axi4_ar_ready_sink_ready = FireSim__ep_1_axi4_ar_ready_sink_ready;
  assign FireSim_ep_1_axi4_w_ready_sink_ready = FireSim__ep_1_axi4_w_ready_sink_ready;
  assign FireSim_ep_1_axi4_aw_ready_sink_ready = FireSim__ep_1_axi4_aw_ready_sink_ready;
  assign FireSim_ep_1_axi4_r_fwd_sink_ready = FireSim__ep_1_axi4_r_fwd_sink_ready;
  assign FireSim_ep_1_axi4_b_fwd_sink_ready = FireSim__ep_1_axi4_b_fwd_sink_ready;
  assign FireSim_ep_2_uart_rxd_sink_ready = FireSim__ep_2_uart_rxd_sink_ready;
  assign FireSim_ep_3_bdev_info_max_req_len_sink_ready = FireSim__ep_3_bdev_info_max_req_len_sink_ready;
  assign FireSim_ep_3_bdev_info_nsectors_sink_ready = FireSim__ep_3_bdev_info_nsectors_sink_ready;
  assign FireSim_ep_3_bdev_data_ready_sink_ready = FireSim__ep_3_bdev_data_ready_sink_ready;
  assign FireSim_ep_3_bdev_req_ready_sink_ready = FireSim__ep_3_bdev_req_ready_sink_ready;
  assign FireSim_ep_3_bdev_resp_fwd_sink_ready = FireSim__ep_3_bdev_resp_fwd_sink_ready;
  assign FireSim_tracerv_triggerDebit_sink_ready = FireSim__tracerv_triggerDebit_sink_ready;
  assign FireSim_tracerv_triggerCredit_sink_ready = FireSim__tracerv_triggerCredit_sink_ready;
  assign FireSim_tracerv_1_triggerDebit_sink_ready = FireSim__tracerv_1_triggerDebit_sink_ready;
  assign FireSim_tracerv_1_triggerCredit_sink_ready = FireSim__tracerv_1_triggerCredit_sink_ready;
  assign FireSim_tracerv_2_triggerDebit_sink_ready = FireSim__tracerv_2_triggerDebit_sink_ready;
  assign FireSim_tracerv_2_triggerCredit_sink_ready = FireSim__tracerv_2_triggerCredit_sink_ready;
  assign FireSim_tracerv_3_triggerDebit_sink_ready = FireSim__tracerv_3_triggerDebit_sink_ready;
  assign FireSim_tracerv_3_triggerCredit_sink_ready = FireSim__tracerv_3_triggerCredit_sink_ready;
  assign FireSim_tracerv_4_triggerDebit_sink_ready = FireSim__tracerv_4_triggerDebit_sink_ready;
  assign FireSim_tracerv_4_triggerCredit_sink_ready = FireSim__tracerv_4_triggerCredit_sink_ready;
  assign FireSim_clockBridge_clocks_sink_ready = FireSim__clockBridge_clocks_sink_ready;
  assign FireSim_resetBridge_reset_sink_ready = FireSim__resetBridge_reset_sink_ready;
  assign resetBridge_reset_2_sink_ready = ep_reset_source_ready;
  assign resetBridge_reset_1_sink_ready = ep_2_reset_source_ready;
  assign resetBridge_reset_sink_ready = ep_3_reset_source_ready;
  assign FireSim_ep_tsi_out_fwd_source_valid = FireSim__ep_tsi_out_fwd_source_valid;
  assign FireSim_ep_tsi_out_fwd_source_bits_bits = FireSim__ep_tsi_out_fwd_source_bits_bits;
  assign FireSim_ep_tsi_out_fwd_source_bits_valid = FireSim__ep_tsi_out_fwd_source_bits_valid;
  assign FireSim_ep_tsi_in_ready_source_valid = FireSim__ep_tsi_in_ready_source_valid;
  assign FireSim_ep_tsi_in_ready_source_bits = FireSim__ep_tsi_in_ready_source_bits;
  assign FireSim_ep_1_reset_source_valid = FireSim__ep_1_reset_source_valid;
  assign FireSim_ep_1_reset_source_bits = FireSim__ep_1_reset_source_bits;
  assign FireSim_ep_1_axi4_ar_fwd_source_valid = FireSim__ep_1_axi4_ar_fwd_source_valid;
  assign FireSim_ep_1_axi4_ar_fwd_source_bits_bits_id = FireSim__ep_1_axi4_ar_fwd_source_bits_bits_id;
  assign FireSim_ep_1_axi4_ar_fwd_source_bits_bits_qos = FireSim__ep_1_axi4_ar_fwd_source_bits_bits_qos;
  assign FireSim_ep_1_axi4_ar_fwd_source_bits_bits_prot = FireSim__ep_1_axi4_ar_fwd_source_bits_bits_prot;
  assign FireSim_ep_1_axi4_ar_fwd_source_bits_bits_cache = FireSim__ep_1_axi4_ar_fwd_source_bits_bits_cache;
  assign FireSim_ep_1_axi4_ar_fwd_source_bits_bits_lock = FireSim__ep_1_axi4_ar_fwd_source_bits_bits_lock;
  assign FireSim_ep_1_axi4_ar_fwd_source_bits_bits_burst = FireSim__ep_1_axi4_ar_fwd_source_bits_bits_burst;
  assign FireSim_ep_1_axi4_ar_fwd_source_bits_bits_size = FireSim__ep_1_axi4_ar_fwd_source_bits_bits_size;
  assign FireSim_ep_1_axi4_ar_fwd_source_bits_bits_len = FireSim__ep_1_axi4_ar_fwd_source_bits_bits_len;
  assign FireSim_ep_1_axi4_ar_fwd_source_bits_bits_addr = FireSim__ep_1_axi4_ar_fwd_source_bits_bits_addr;
  assign FireSim_ep_1_axi4_ar_fwd_source_bits_valid = FireSim__ep_1_axi4_ar_fwd_source_bits_valid;
  assign FireSim_ep_1_axi4_w_fwd_source_valid = FireSim__ep_1_axi4_w_fwd_source_valid;
  assign FireSim_ep_1_axi4_w_fwd_source_bits_bits_strb = FireSim__ep_1_axi4_w_fwd_source_bits_bits_strb;
  assign FireSim_ep_1_axi4_w_fwd_source_bits_bits_last = FireSim__ep_1_axi4_w_fwd_source_bits_bits_last;
  assign FireSim_ep_1_axi4_w_fwd_source_bits_bits_data = FireSim__ep_1_axi4_w_fwd_source_bits_bits_data;
  assign FireSim_ep_1_axi4_w_fwd_source_bits_valid = FireSim__ep_1_axi4_w_fwd_source_bits_valid;
  assign FireSim_ep_1_axi4_aw_fwd_source_valid = FireSim__ep_1_axi4_aw_fwd_source_valid;
  assign FireSim_ep_1_axi4_aw_fwd_source_bits_bits_id = FireSim__ep_1_axi4_aw_fwd_source_bits_bits_id;
  assign FireSim_ep_1_axi4_aw_fwd_source_bits_bits_qos = FireSim__ep_1_axi4_aw_fwd_source_bits_bits_qos;
  assign FireSim_ep_1_axi4_aw_fwd_source_bits_bits_prot = FireSim__ep_1_axi4_aw_fwd_source_bits_bits_prot;
  assign FireSim_ep_1_axi4_aw_fwd_source_bits_bits_cache = FireSim__ep_1_axi4_aw_fwd_source_bits_bits_cache;
  assign FireSim_ep_1_axi4_aw_fwd_source_bits_bits_lock = FireSim__ep_1_axi4_aw_fwd_source_bits_bits_lock;
  assign FireSim_ep_1_axi4_aw_fwd_source_bits_bits_burst = FireSim__ep_1_axi4_aw_fwd_source_bits_bits_burst;
  assign FireSim_ep_1_axi4_aw_fwd_source_bits_bits_size = FireSim__ep_1_axi4_aw_fwd_source_bits_bits_size;
  assign FireSim_ep_1_axi4_aw_fwd_source_bits_bits_len = FireSim__ep_1_axi4_aw_fwd_source_bits_bits_len;
  assign FireSim_ep_1_axi4_aw_fwd_source_bits_bits_addr = FireSim__ep_1_axi4_aw_fwd_source_bits_bits_addr;
  assign FireSim_ep_1_axi4_aw_fwd_source_bits_valid = FireSim__ep_1_axi4_aw_fwd_source_bits_valid;
  assign FireSim_ep_1_axi4_r_ready_source_valid = FireSim__ep_1_axi4_r_ready_source_valid;
  assign FireSim_ep_1_axi4_r_ready_source_bits = FireSim__ep_1_axi4_r_ready_source_bits;
  assign FireSim_ep_1_axi4_b_ready_source_valid = FireSim__ep_1_axi4_b_ready_source_valid;
  assign FireSim_ep_1_axi4_b_ready_source_bits = FireSim__ep_1_axi4_b_ready_source_bits;
  assign FireSim_ep_2_uart_txd_source_valid = FireSim__ep_2_uart_txd_source_valid;
  assign FireSim_ep_2_uart_txd_source_bits = FireSim__ep_2_uart_txd_source_bits;
  assign FireSim_ep_3_bdev_data_fwd_source_valid = FireSim__ep_3_bdev_data_fwd_source_valid;
  assign FireSim_ep_3_bdev_data_fwd_source_bits_bits_tag = FireSim__ep_3_bdev_data_fwd_source_bits_bits_tag;
  assign FireSim_ep_3_bdev_data_fwd_source_bits_bits_data = FireSim__ep_3_bdev_data_fwd_source_bits_bits_data;
  assign FireSim_ep_3_bdev_data_fwd_source_bits_valid = FireSim__ep_3_bdev_data_fwd_source_bits_valid;
  assign FireSim_ep_3_bdev_req_fwd_source_valid = FireSim__ep_3_bdev_req_fwd_source_valid;
  assign FireSim_ep_3_bdev_req_fwd_source_bits_bits_tag = FireSim__ep_3_bdev_req_fwd_source_bits_bits_tag;
  assign FireSim_ep_3_bdev_req_fwd_source_bits_bits_len = FireSim__ep_3_bdev_req_fwd_source_bits_bits_len;
  assign FireSim_ep_3_bdev_req_fwd_source_bits_bits_offset = FireSim__ep_3_bdev_req_fwd_source_bits_bits_offset;
  assign FireSim_ep_3_bdev_req_fwd_source_bits_bits_write = FireSim__ep_3_bdev_req_fwd_source_bits_bits_write;
  assign FireSim_ep_3_bdev_req_fwd_source_bits_valid = FireSim__ep_3_bdev_req_fwd_source_bits_valid;
  assign FireSim_ep_3_bdev_resp_ready_source_valid = FireSim__ep_3_bdev_resp_ready_source_valid;
  assign FireSim_ep_3_bdev_resp_ready_source_bits = FireSim__ep_3_bdev_resp_ready_source_bits;
  assign FireSim_tracerv_trace_insns_0_tval_source_valid = FireSim__tracerv_trace_insns_0_tval_source_valid;
  assign FireSim_tracerv_trace_insns_0_tval_source_bits = FireSim__tracerv_trace_insns_0_tval_source_bits;
  assign FireSim_tracerv_trace_insns_0_cause_source_valid = FireSim__tracerv_trace_insns_0_cause_source_valid;
  assign FireSim_tracerv_trace_insns_0_cause_source_bits = FireSim__tracerv_trace_insns_0_cause_source_bits;
  assign FireSim_tracerv_trace_insns_0_interrupt_source_valid = FireSim__tracerv_trace_insns_0_interrupt_source_valid;
  assign FireSim_tracerv_trace_insns_0_interrupt_source_bits = FireSim__tracerv_trace_insns_0_interrupt_source_bits;
  assign FireSim_tracerv_trace_insns_0_exception_source_valid = FireSim__tracerv_trace_insns_0_exception_source_valid;
  assign FireSim_tracerv_trace_insns_0_exception_source_bits = FireSim__tracerv_trace_insns_0_exception_source_bits;
  assign FireSim_tracerv_trace_insns_0_priv_source_valid = FireSim__tracerv_trace_insns_0_priv_source_valid;
  assign FireSim_tracerv_trace_insns_0_priv_source_bits = FireSim__tracerv_trace_insns_0_priv_source_bits;
  assign FireSim_tracerv_trace_insns_0_wdata_source_valid = FireSim__tracerv_trace_insns_0_wdata_source_valid;
  assign FireSim_tracerv_trace_insns_0_wdata_source_bits = FireSim__tracerv_trace_insns_0_wdata_source_bits;
  assign FireSim_tracerv_trace_insns_0_insn_source_valid = FireSim__tracerv_trace_insns_0_insn_source_valid;
  assign FireSim_tracerv_trace_insns_0_insn_source_bits = FireSim__tracerv_trace_insns_0_insn_source_bits;
  assign FireSim_tracerv_trace_insns_0_iaddr_source_valid = FireSim__tracerv_trace_insns_0_iaddr_source_valid;
  assign FireSim_tracerv_trace_insns_0_iaddr_source_bits = FireSim__tracerv_trace_insns_0_iaddr_source_bits;
  assign FireSim_tracerv_trace_insns_0_valid_source_valid = FireSim__tracerv_trace_insns_0_valid_source_valid;
  assign FireSim_tracerv_trace_insns_0_valid_source_bits = FireSim__tracerv_trace_insns_0_valid_source_bits;
  assign FireSim_tracerv_trace_insns_1_tval_source_valid = FireSim__tracerv_trace_insns_1_tval_source_valid;
  assign FireSim_tracerv_trace_insns_1_tval_source_bits = FireSim__tracerv_trace_insns_1_tval_source_bits;
  assign FireSim_tracerv_trace_insns_1_cause_source_valid = FireSim__tracerv_trace_insns_1_cause_source_valid;
  assign FireSim_tracerv_trace_insns_1_cause_source_bits = FireSim__tracerv_trace_insns_1_cause_source_bits;
  assign FireSim_tracerv_trace_insns_1_interrupt_source_valid = FireSim__tracerv_trace_insns_1_interrupt_source_valid;
  assign FireSim_tracerv_trace_insns_1_interrupt_source_bits = FireSim__tracerv_trace_insns_1_interrupt_source_bits;
  assign FireSim_tracerv_trace_insns_1_exception_source_valid = FireSim__tracerv_trace_insns_1_exception_source_valid;
  assign FireSim_tracerv_trace_insns_1_exception_source_bits = FireSim__tracerv_trace_insns_1_exception_source_bits;
  assign FireSim_tracerv_trace_insns_1_priv_source_valid = FireSim__tracerv_trace_insns_1_priv_source_valid;
  assign FireSim_tracerv_trace_insns_1_priv_source_bits = FireSim__tracerv_trace_insns_1_priv_source_bits;
  assign FireSim_tracerv_trace_insns_1_wdata_source_valid = FireSim__tracerv_trace_insns_1_wdata_source_valid;
  assign FireSim_tracerv_trace_insns_1_wdata_source_bits = FireSim__tracerv_trace_insns_1_wdata_source_bits;
  assign FireSim_tracerv_trace_insns_1_insn_source_valid = FireSim__tracerv_trace_insns_1_insn_source_valid;
  assign FireSim_tracerv_trace_insns_1_insn_source_bits = FireSim__tracerv_trace_insns_1_insn_source_bits;
  assign FireSim_tracerv_trace_insns_1_iaddr_source_valid = FireSim__tracerv_trace_insns_1_iaddr_source_valid;
  assign FireSim_tracerv_trace_insns_1_iaddr_source_bits = FireSim__tracerv_trace_insns_1_iaddr_source_bits;
  assign FireSim_tracerv_trace_insns_1_valid_source_valid = FireSim__tracerv_trace_insns_1_valid_source_valid;
  assign FireSim_tracerv_trace_insns_1_valid_source_bits = FireSim__tracerv_trace_insns_1_valid_source_bits;
  assign FireSim_tracerv_trace_insns_2_tval_source_valid = FireSim__tracerv_trace_insns_2_tval_source_valid;
  assign FireSim_tracerv_trace_insns_2_tval_source_bits = FireSim__tracerv_trace_insns_2_tval_source_bits;
  assign FireSim_tracerv_trace_insns_2_cause_source_valid = FireSim__tracerv_trace_insns_2_cause_source_valid;
  assign FireSim_tracerv_trace_insns_2_cause_source_bits = FireSim__tracerv_trace_insns_2_cause_source_bits;
  assign FireSim_tracerv_trace_insns_2_interrupt_source_valid = FireSim__tracerv_trace_insns_2_interrupt_source_valid;
  assign FireSim_tracerv_trace_insns_2_interrupt_source_bits = FireSim__tracerv_trace_insns_2_interrupt_source_bits;
  assign FireSim_tracerv_trace_insns_2_exception_source_valid = FireSim__tracerv_trace_insns_2_exception_source_valid;
  assign FireSim_tracerv_trace_insns_2_exception_source_bits = FireSim__tracerv_trace_insns_2_exception_source_bits;
  assign FireSim_tracerv_trace_insns_2_priv_source_valid = FireSim__tracerv_trace_insns_2_priv_source_valid;
  assign FireSim_tracerv_trace_insns_2_priv_source_bits = FireSim__tracerv_trace_insns_2_priv_source_bits;
  assign FireSim_tracerv_trace_insns_2_wdata_source_valid = FireSim__tracerv_trace_insns_2_wdata_source_valid;
  assign FireSim_tracerv_trace_insns_2_wdata_source_bits = FireSim__tracerv_trace_insns_2_wdata_source_bits;
  assign FireSim_tracerv_trace_insns_2_insn_source_valid = FireSim__tracerv_trace_insns_2_insn_source_valid;
  assign FireSim_tracerv_trace_insns_2_insn_source_bits = FireSim__tracerv_trace_insns_2_insn_source_bits;
  assign FireSim_tracerv_trace_insns_2_iaddr_source_valid = FireSim__tracerv_trace_insns_2_iaddr_source_valid;
  assign FireSim_tracerv_trace_insns_2_iaddr_source_bits = FireSim__tracerv_trace_insns_2_iaddr_source_bits;
  assign FireSim_tracerv_trace_insns_2_valid_source_valid = FireSim__tracerv_trace_insns_2_valid_source_valid;
  assign FireSim_tracerv_trace_insns_2_valid_source_bits = FireSim__tracerv_trace_insns_2_valid_source_bits;
  assign FireSim_tracerv_trace_reset_source_valid = FireSim__tracerv_trace_reset_source_valid;
  assign FireSim_tracerv_trace_reset_source_bits = FireSim__tracerv_trace_reset_source_bits;
  assign FireSim_tracerv_1_trace_insns_0_tval_source_valid = FireSim__tracerv_1_trace_insns_0_tval_source_valid;
  assign FireSim_tracerv_1_trace_insns_0_tval_source_bits = FireSim__tracerv_1_trace_insns_0_tval_source_bits;
  assign FireSim_tracerv_1_trace_insns_0_cause_source_valid = FireSim__tracerv_1_trace_insns_0_cause_source_valid;
  assign FireSim_tracerv_1_trace_insns_0_cause_source_bits = FireSim__tracerv_1_trace_insns_0_cause_source_bits;
  assign FireSim_tracerv_1_trace_insns_0_interrupt_source_valid =
    FireSim__tracerv_1_trace_insns_0_interrupt_source_valid;
  assign FireSim_tracerv_1_trace_insns_0_interrupt_source_bits = FireSim__tracerv_1_trace_insns_0_interrupt_source_bits;
  assign FireSim_tracerv_1_trace_insns_0_exception_source_valid =
    FireSim__tracerv_1_trace_insns_0_exception_source_valid;
  assign FireSim_tracerv_1_trace_insns_0_exception_source_bits = FireSim__tracerv_1_trace_insns_0_exception_source_bits;
  assign FireSim_tracerv_1_trace_insns_0_priv_source_valid = FireSim__tracerv_1_trace_insns_0_priv_source_valid;
  assign FireSim_tracerv_1_trace_insns_0_priv_source_bits = FireSim__tracerv_1_trace_insns_0_priv_source_bits;
  assign FireSim_tracerv_1_trace_insns_0_insn_source_valid = FireSim__tracerv_1_trace_insns_0_insn_source_valid;
  assign FireSim_tracerv_1_trace_insns_0_insn_source_bits = FireSim__tracerv_1_trace_insns_0_insn_source_bits;
  assign FireSim_tracerv_1_trace_insns_0_iaddr_source_valid = FireSim__tracerv_1_trace_insns_0_iaddr_source_valid;
  assign FireSim_tracerv_1_trace_insns_0_iaddr_source_bits = FireSim__tracerv_1_trace_insns_0_iaddr_source_bits;
  assign FireSim_tracerv_1_trace_insns_0_valid_source_valid = FireSim__tracerv_1_trace_insns_0_valid_source_valid;
  assign FireSim_tracerv_1_trace_insns_0_valid_source_bits = FireSim__tracerv_1_trace_insns_0_valid_source_bits;
  assign FireSim_tracerv_1_trace_reset_source_valid = FireSim__tracerv_1_trace_reset_source_valid;
  assign FireSim_tracerv_1_trace_reset_source_bits = FireSim__tracerv_1_trace_reset_source_bits;
  assign FireSim_tracerv_2_trace_insns_0_tval_source_valid = FireSim__tracerv_2_trace_insns_0_tval_source_valid;
  assign FireSim_tracerv_2_trace_insns_0_tval_source_bits = FireSim__tracerv_2_trace_insns_0_tval_source_bits;
  assign FireSim_tracerv_2_trace_insns_0_cause_source_valid = FireSim__tracerv_2_trace_insns_0_cause_source_valid;
  assign FireSim_tracerv_2_trace_insns_0_cause_source_bits = FireSim__tracerv_2_trace_insns_0_cause_source_bits;
  assign FireSim_tracerv_2_trace_insns_0_interrupt_source_valid =
    FireSim__tracerv_2_trace_insns_0_interrupt_source_valid;
  assign FireSim_tracerv_2_trace_insns_0_interrupt_source_bits = FireSim__tracerv_2_trace_insns_0_interrupt_source_bits;
  assign FireSim_tracerv_2_trace_insns_0_exception_source_valid =
    FireSim__tracerv_2_trace_insns_0_exception_source_valid;
  assign FireSim_tracerv_2_trace_insns_0_exception_source_bits = FireSim__tracerv_2_trace_insns_0_exception_source_bits;
  assign FireSim_tracerv_2_trace_insns_0_priv_source_valid = FireSim__tracerv_2_trace_insns_0_priv_source_valid;
  assign FireSim_tracerv_2_trace_insns_0_priv_source_bits = FireSim__tracerv_2_trace_insns_0_priv_source_bits;
  assign FireSim_tracerv_2_trace_insns_0_insn_source_valid = FireSim__tracerv_2_trace_insns_0_insn_source_valid;
  assign FireSim_tracerv_2_trace_insns_0_insn_source_bits = FireSim__tracerv_2_trace_insns_0_insn_source_bits;
  assign FireSim_tracerv_2_trace_insns_0_iaddr_source_valid = FireSim__tracerv_2_trace_insns_0_iaddr_source_valid;
  assign FireSim_tracerv_2_trace_insns_0_iaddr_source_bits = FireSim__tracerv_2_trace_insns_0_iaddr_source_bits;
  assign FireSim_tracerv_2_trace_insns_0_valid_source_valid = FireSim__tracerv_2_trace_insns_0_valid_source_valid;
  assign FireSim_tracerv_2_trace_insns_0_valid_source_bits = FireSim__tracerv_2_trace_insns_0_valid_source_bits;
  assign FireSim_tracerv_2_trace_reset_source_valid = FireSim__tracerv_2_trace_reset_source_valid;
  assign FireSim_tracerv_2_trace_reset_source_bits = FireSim__tracerv_2_trace_reset_source_bits;
  assign FireSim_tracerv_3_trace_insns_0_tval_source_valid = FireSim__tracerv_3_trace_insns_0_tval_source_valid;
  assign FireSim_tracerv_3_trace_insns_0_tval_source_bits = FireSim__tracerv_3_trace_insns_0_tval_source_bits;
  assign FireSim_tracerv_3_trace_insns_0_cause_source_valid = FireSim__tracerv_3_trace_insns_0_cause_source_valid;
  assign FireSim_tracerv_3_trace_insns_0_cause_source_bits = FireSim__tracerv_3_trace_insns_0_cause_source_bits;
  assign FireSim_tracerv_3_trace_insns_0_interrupt_source_valid =
    FireSim__tracerv_3_trace_insns_0_interrupt_source_valid;
  assign FireSim_tracerv_3_trace_insns_0_interrupt_source_bits = FireSim__tracerv_3_trace_insns_0_interrupt_source_bits;
  assign FireSim_tracerv_3_trace_insns_0_exception_source_valid =
    FireSim__tracerv_3_trace_insns_0_exception_source_valid;
  assign FireSim_tracerv_3_trace_insns_0_exception_source_bits = FireSim__tracerv_3_trace_insns_0_exception_source_bits;
  assign FireSim_tracerv_3_trace_insns_0_priv_source_valid = FireSim__tracerv_3_trace_insns_0_priv_source_valid;
  assign FireSim_tracerv_3_trace_insns_0_priv_source_bits = FireSim__tracerv_3_trace_insns_0_priv_source_bits;
  assign FireSim_tracerv_3_trace_insns_0_insn_source_valid = FireSim__tracerv_3_trace_insns_0_insn_source_valid;
  assign FireSim_tracerv_3_trace_insns_0_insn_source_bits = FireSim__tracerv_3_trace_insns_0_insn_source_bits;
  assign FireSim_tracerv_3_trace_insns_0_iaddr_source_valid = FireSim__tracerv_3_trace_insns_0_iaddr_source_valid;
  assign FireSim_tracerv_3_trace_insns_0_iaddr_source_bits = FireSim__tracerv_3_trace_insns_0_iaddr_source_bits;
  assign FireSim_tracerv_3_trace_insns_0_valid_source_valid = FireSim__tracerv_3_trace_insns_0_valid_source_valid;
  assign FireSim_tracerv_3_trace_insns_0_valid_source_bits = FireSim__tracerv_3_trace_insns_0_valid_source_bits;
  assign FireSim_tracerv_3_trace_reset_source_valid = FireSim__tracerv_3_trace_reset_source_valid;
  assign FireSim_tracerv_3_trace_reset_source_bits = FireSim__tracerv_3_trace_reset_source_bits;
  assign FireSim_tracerv_4_trace_insns_0_tval_source_valid = FireSim__tracerv_4_trace_insns_0_tval_source_valid;
  assign FireSim_tracerv_4_trace_insns_0_tval_source_bits = FireSim__tracerv_4_trace_insns_0_tval_source_bits;
  assign FireSim_tracerv_4_trace_insns_0_cause_source_valid = FireSim__tracerv_4_trace_insns_0_cause_source_valid;
  assign FireSim_tracerv_4_trace_insns_0_cause_source_bits = FireSim__tracerv_4_trace_insns_0_cause_source_bits;
  assign FireSim_tracerv_4_trace_insns_0_interrupt_source_valid =
    FireSim__tracerv_4_trace_insns_0_interrupt_source_valid;
  assign FireSim_tracerv_4_trace_insns_0_interrupt_source_bits = FireSim__tracerv_4_trace_insns_0_interrupt_source_bits;
  assign FireSim_tracerv_4_trace_insns_0_exception_source_valid =
    FireSim__tracerv_4_trace_insns_0_exception_source_valid;
  assign FireSim_tracerv_4_trace_insns_0_exception_source_bits = FireSim__tracerv_4_trace_insns_0_exception_source_bits;
  assign FireSim_tracerv_4_trace_insns_0_priv_source_valid = FireSim__tracerv_4_trace_insns_0_priv_source_valid;
  assign FireSim_tracerv_4_trace_insns_0_priv_source_bits = FireSim__tracerv_4_trace_insns_0_priv_source_bits;
  assign FireSim_tracerv_4_trace_insns_0_insn_source_valid = FireSim__tracerv_4_trace_insns_0_insn_source_valid;
  assign FireSim_tracerv_4_trace_insns_0_insn_source_bits = FireSim__tracerv_4_trace_insns_0_insn_source_bits;
  assign FireSim_tracerv_4_trace_insns_0_iaddr_source_valid = FireSim__tracerv_4_trace_insns_0_iaddr_source_valid;
  assign FireSim_tracerv_4_trace_insns_0_iaddr_source_bits = FireSim__tracerv_4_trace_insns_0_iaddr_source_bits;
  assign FireSim_tracerv_4_trace_insns_0_valid_source_valid = FireSim__tracerv_4_trace_insns_0_valid_source_valid;
  assign FireSim_tracerv_4_trace_insns_0_valid_source_bits = FireSim__tracerv_4_trace_insns_0_valid_source_bits;
  assign FireSim_tracerv_4_trace_reset_source_valid = FireSim__tracerv_4_trace_reset_source_valid;
  assign FireSim_tracerv_4_trace_reset_source_bits = FireSim__tracerv_4_trace_reset_source_bits;
  assign FireSim_synthesizedPrintf_clockBridge_clocks_0_globalReset_source_valid =
    FireSim__synthesizedPrintf_clockBridge_clocks_0_globalReset_source_valid;
  assign FireSim_synthesizedPrintf_clockBridge_clocks_0_globalReset_source_bits =
    FireSim__synthesizedPrintf_clockBridge_clocks_0_globalReset_source_bits;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_5_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_5_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_6_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_6_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_7_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_7_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_8_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_8_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_9_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_9_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_10_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_10_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_bits
    ;
  assign FireSim_synthesizedPrintf_clockBridge_clocks_1_globalReset_source_valid =
    FireSim__synthesizedPrintf_clockBridge_clocks_1_globalReset_source_valid;
  assign FireSim_synthesizedPrintf_clockBridge_clocks_1_globalReset_source_bits =
    FireSim__synthesizedPrintf_clockBridge_clocks_1_globalReset_source_bits;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_bits
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_valid
    ;
  assign
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
     =
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_bits
    ;
  assign ep_reset_source_valid = resetBridge_reset_2_sink_valid;
  assign ep_reset_source_bits = resetBridge_reset_2_sink_bits;
  assign ep_2_reset_source_valid = resetBridge_reset_1_sink_valid;
  assign ep_2_reset_source_bits = resetBridge_reset_1_sink_bits;
  assign ep_3_reset_source_valid = resetBridge_reset_sink_valid;
  assign ep_3_reset_source_bits = resetBridge_reset_sink_bits;
  assign FireSim__hostClock = hostClock;
  assign FireSim__hostReset = hostReset;
  assign FireSim__clockBridge_clocks_sink_bits__0 = FireSim_clockBridge_clocks_sink_bits__0;
  assign FireSim__clockBridge_clocks_sink_bits__1 = FireSim_clockBridge_clocks_sink_bits__1;
  assign FireSim__ep_1_axi4_aw_ready_sink_valid = FireSim_ep_1_axi4_aw_ready_sink_valid;
  assign FireSim__ep_1_axi4_aw_ready_sink_bits = FireSim_ep_1_axi4_aw_ready_sink_bits;
  assign FireSim__peekPokeBridge_reset_sink_valid = FireSim_peekPokeBridge_reset_sink_valid;
  assign FireSim__tracerv_3_triggerDebit_sink_valid = FireSim_tracerv_3_triggerDebit_sink_valid;
  assign FireSim__ep_3_bdev_info_nsectors_sink_valid = FireSim_ep_3_bdev_info_nsectors_sink_valid;
  assign FireSim__ep_3_bdev_info_nsectors_sink_bits = FireSim_ep_3_bdev_info_nsectors_sink_bits;
  assign FireSim__tracerv_triggerDebit_sink_valid = FireSim_tracerv_triggerDebit_sink_valid;
  assign FireSim__tracerv_2_triggerCredit_sink_valid = FireSim_tracerv_2_triggerCredit_sink_valid;
  assign FireSim__ep_3_bdev_info_max_req_len_sink_valid = FireSim_ep_3_bdev_info_max_req_len_sink_valid;
  assign FireSim__ep_3_bdev_info_max_req_len_sink_bits = FireSim_ep_3_bdev_info_max_req_len_sink_bits;
  assign FireSim__ep_3_bdev_req_ready_sink_valid = FireSim_ep_3_bdev_req_ready_sink_valid;
  assign FireSim__ep_3_bdev_req_ready_sink_bits = FireSim_ep_3_bdev_req_ready_sink_bits;
  assign FireSim__tracerv_triggerCredit_sink_valid = FireSim_tracerv_triggerCredit_sink_valid;
  assign FireSim__ep_3_bdev_resp_fwd_sink_valid = FireSim_ep_3_bdev_resp_fwd_sink_valid;
  assign FireSim__ep_3_bdev_resp_fwd_sink_bits_bits_tag = FireSim_ep_3_bdev_resp_fwd_sink_bits_bits_tag;
  assign FireSim__ep_3_bdev_resp_fwd_sink_bits_bits_data = FireSim_ep_3_bdev_resp_fwd_sink_bits_bits_data;
  assign FireSim__ep_3_bdev_resp_fwd_sink_bits_valid = FireSim_ep_3_bdev_resp_fwd_sink_bits_valid;
  assign FireSim__ep_1_axi4_ar_ready_sink_valid = FireSim_ep_1_axi4_ar_ready_sink_valid;
  assign FireSim__ep_1_axi4_ar_ready_sink_bits = FireSim_ep_1_axi4_ar_ready_sink_bits;
  assign FireSim__ep_tsi_out_ready_sink_valid = FireSim_ep_tsi_out_ready_sink_valid;
  assign FireSim__ep_tsi_out_ready_sink_bits = FireSim_ep_tsi_out_ready_sink_bits;
  assign FireSim__resetBridge_reset_sink_valid = FireSim_resetBridge_reset_sink_valid;
  assign FireSim__resetBridge_reset_sink_bits = FireSim_resetBridge_reset_sink_bits;
  assign FireSim__tracerv_4_triggerDebit_sink_valid = FireSim_tracerv_4_triggerDebit_sink_valid;
  assign FireSim__ep_1_axi4_w_ready_sink_valid = FireSim_ep_1_axi4_w_ready_sink_valid;
  assign FireSim__ep_1_axi4_w_ready_sink_bits = FireSim_ep_1_axi4_w_ready_sink_bits;
  assign FireSim__tracerv_1_triggerCredit_sink_valid = FireSim_tracerv_1_triggerCredit_sink_valid;
  assign FireSim__ep_tsi_in_fwd_sink_valid = FireSim_ep_tsi_in_fwd_sink_valid;
  assign FireSim__ep_tsi_in_fwd_sink_bits_bits = FireSim_ep_tsi_in_fwd_sink_bits_bits;
  assign FireSim__ep_tsi_in_fwd_sink_bits_valid = FireSim_ep_tsi_in_fwd_sink_bits_valid;
  assign FireSim__ep_2_uart_rxd_sink_valid = FireSim_ep_2_uart_rxd_sink_valid;
  assign FireSim__ep_2_uart_rxd_sink_bits = FireSim_ep_2_uart_rxd_sink_bits;
  assign FireSim__tracerv_1_triggerDebit_sink_valid = FireSim_tracerv_1_triggerDebit_sink_valid;
  assign FireSim__tracerv_4_triggerCredit_sink_valid = FireSim_tracerv_4_triggerCredit_sink_valid;
  assign FireSim__tracerv_2_triggerDebit_sink_valid = FireSim_tracerv_2_triggerDebit_sink_valid;
  assign FireSim__ep_3_bdev_data_ready_sink_valid = FireSim_ep_3_bdev_data_ready_sink_valid;
  assign FireSim__ep_3_bdev_data_ready_sink_bits = FireSim_ep_3_bdev_data_ready_sink_bits;
  assign FireSim__tracerv_3_triggerCredit_sink_valid = FireSim_tracerv_3_triggerCredit_sink_valid;
  assign FireSim__ep_1_axi4_b_fwd_sink_valid = FireSim_ep_1_axi4_b_fwd_sink_valid;
  assign FireSim__ep_1_axi4_b_fwd_sink_bits_bits_id = FireSim_ep_1_axi4_b_fwd_sink_bits_bits_id;
  assign FireSim__ep_1_axi4_b_fwd_sink_bits_valid = FireSim_ep_1_axi4_b_fwd_sink_bits_valid;
  assign FireSim__ep_1_axi4_r_fwd_sink_valid = FireSim_ep_1_axi4_r_fwd_sink_valid;
  assign FireSim__ep_1_axi4_r_fwd_sink_bits_bits_id = FireSim_ep_1_axi4_r_fwd_sink_bits_bits_id;
  assign FireSim__ep_1_axi4_r_fwd_sink_bits_bits_last = FireSim_ep_1_axi4_r_fwd_sink_bits_bits_last;
  assign FireSim__ep_1_axi4_r_fwd_sink_bits_bits_data = FireSim_ep_1_axi4_r_fwd_sink_bits_bits_data;
  assign FireSim__ep_1_axi4_r_fwd_sink_bits_valid = FireSim_ep_1_axi4_r_fwd_sink_bits_valid;
  assign FireSim__ep_1_axi4_ar_fwd_source_ready = FireSim_ep_1_axi4_ar_fwd_source_ready;
  assign FireSim__ep_3_bdev_data_fwd_source_ready = FireSim_ep_3_bdev_data_fwd_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
    ;
  assign FireSim__tracerv_1_trace_insns_0_interrupt_source_ready =
    FireSim_tracerv_1_trace_insns_0_interrupt_source_ready;
  assign FireSim__tracerv_1_trace_insns_0_iaddr_source_ready = FireSim_tracerv_1_trace_insns_0_iaddr_source_ready;
  assign FireSim__tracerv_trace_insns_2_priv_source_ready = FireSim_tracerv_trace_insns_2_priv_source_ready;
  assign FireSim__tracerv_trace_insns_0_insn_source_ready = FireSim_tracerv_trace_insns_0_insn_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
    ;
  assign FireSim__tracerv_2_trace_insns_0_cause_source_ready = FireSim_tracerv_2_trace_insns_0_cause_source_ready;
  assign FireSim__tracerv_trace_insns_0_tval_source_ready = FireSim_tracerv_trace_insns_0_tval_source_ready;
  assign FireSim__tracerv_trace_insns_1_insn_source_ready = FireSim_tracerv_trace_insns_1_insn_source_ready;
  assign FireSim__tracerv_3_trace_insns_0_tval_source_ready = FireSim_tracerv_3_trace_insns_0_tval_source_ready;
  assign FireSim__tracerv_trace_insns_2_interrupt_source_ready = FireSim_tracerv_trace_insns_2_interrupt_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
    ;
  assign FireSim__ep_1_axi4_r_ready_source_ready = FireSim_ep_1_axi4_r_ready_source_ready;
  assign FireSim__tracerv_trace_insns_2_wdata_source_ready = FireSim_tracerv_trace_insns_2_wdata_source_ready;
  assign FireSim__tracerv_4_trace_insns_0_cause_source_ready = FireSim_tracerv_4_trace_insns_0_cause_source_ready;
  assign FireSim__tracerv_trace_insns_0_exception_source_ready = FireSim_tracerv_trace_insns_0_exception_source_ready;
  assign FireSim__synthesizedPrintf_clockBridge_clocks_0_globalReset_source_ready =
    FireSim_synthesizedPrintf_clockBridge_clocks_0_globalReset_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
    ;
  assign FireSim__tracerv_3_trace_insns_0_iaddr_source_ready = FireSim_tracerv_3_trace_insns_0_iaddr_source_ready;
  assign FireSim__tracerv_trace_insns_2_insn_source_ready = FireSim_tracerv_trace_insns_2_insn_source_ready;
  assign FireSim__tracerv_trace_insns_1_iaddr_source_ready = FireSim_tracerv_trace_insns_1_iaddr_source_ready;
  assign FireSim__tracerv_1_trace_insns_0_valid_source_ready = FireSim_tracerv_1_trace_insns_0_valid_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
    ;
  assign FireSim__tracerv_4_trace_insns_0_exception_source_ready =
    FireSim_tracerv_4_trace_insns_0_exception_source_ready;
  assign FireSim__tracerv_trace_insns_0_iaddr_source_ready = FireSim_tracerv_trace_insns_0_iaddr_source_ready;
  assign FireSim__tracerv_3_trace_insns_0_valid_source_ready = FireSim_tracerv_3_trace_insns_0_valid_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_8_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_8_source_ready
    ;
  assign FireSim__tracerv_1_trace_insns_0_priv_source_ready = FireSim_tracerv_1_trace_insns_0_priv_source_ready;
  assign FireSim__tracerv_trace_insns_2_exception_source_ready = FireSim_tracerv_trace_insns_2_exception_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
    ;
  assign FireSim__tracerv_trace_insns_1_wdata_source_ready = FireSim_tracerv_trace_insns_1_wdata_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
    ;
  assign FireSim__tracerv_2_trace_insns_0_priv_source_ready = FireSim_tracerv_2_trace_insns_0_priv_source_ready;
  assign FireSim__tracerv_3_trace_insns_0_insn_source_ready = FireSim_tracerv_3_trace_insns_0_insn_source_ready;
  assign FireSim__ep_1_reset_source_ready = FireSim_ep_1_reset_source_ready;
  assign FireSim__tracerv_2_trace_insns_0_tval_source_ready = FireSim_tracerv_2_trace_insns_0_tval_source_ready;
  assign FireSim__tracerv_3_trace_insns_0_cause_source_ready = FireSim_tracerv_3_trace_insns_0_cause_source_ready;
  assign FireSim__ep_3_bdev_resp_ready_source_ready = FireSim_ep_3_bdev_resp_ready_source_ready;
  assign FireSim__tracerv_1_trace_reset_source_ready = FireSim_tracerv_1_trace_reset_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
    ;
  assign FireSim__tracerv_trace_insns_1_interrupt_source_ready = FireSim_tracerv_trace_insns_1_interrupt_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
    ;
  assign FireSim__tracerv_trace_insns_0_interrupt_source_ready = FireSim_tracerv_trace_insns_0_interrupt_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
    ;
  assign FireSim__ep_tsi_in_ready_source_ready = FireSim_ep_tsi_in_ready_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
    ;
  assign FireSim__tracerv_trace_insns_2_cause_source_ready = FireSim_tracerv_trace_insns_2_cause_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable_source_ready
    ;
  assign FireSim__tracerv_2_trace_insns_0_insn_source_ready = FireSim_tracerv_2_trace_insns_0_insn_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2_source_ready
    ;
  assign FireSim__tracerv_1_trace_insns_0_exception_source_ready =
    FireSim_tracerv_1_trace_insns_0_exception_source_ready;
  assign FireSim__tracerv_trace_insns_0_priv_source_ready = FireSim_tracerv_trace_insns_0_priv_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_7_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_7_source_ready
    ;
  assign FireSim__tracerv_trace_reset_source_ready = FireSim_tracerv_trace_reset_source_ready;
  assign FireSim__tracerv_3_trace_insns_0_interrupt_source_ready =
    FireSim_tracerv_3_trace_insns_0_interrupt_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_10_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_10_source_ready
    ;
  assign FireSim__tracerv_trace_insns_1_valid_source_ready = FireSim_tracerv_trace_insns_1_valid_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable_source_ready
    ;
  assign FireSim__tracerv_2_trace_reset_source_ready = FireSim_tracerv_2_trace_reset_source_ready;
  assign FireSim__tracerv_trace_insns_1_exception_source_ready = FireSim_tracerv_trace_insns_1_exception_source_ready;
  assign FireSim__tracerv_4_trace_insns_0_tval_source_ready = FireSim_tracerv_4_trace_insns_0_tval_source_ready;
  assign FireSim__tracerv_4_trace_insns_0_interrupt_source_ready =
    FireSim_tracerv_4_trace_insns_0_interrupt_source_ready;
  assign FireSim__tracerv_2_trace_insns_0_iaddr_source_ready = FireSim_tracerv_2_trace_insns_0_iaddr_source_ready;
  assign FireSim__tracerv_trace_insns_2_valid_source_ready = FireSim_tracerv_trace_insns_2_valid_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0_source_ready
    ;
  assign FireSim__ep_1_axi4_w_fwd_source_ready = FireSim_ep_1_axi4_w_fwd_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
    ;
  assign FireSim__tracerv_2_trace_insns_0_interrupt_source_ready =
    FireSim_tracerv_2_trace_insns_0_interrupt_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
    ;
  assign FireSim__tracerv_trace_insns_1_tval_source_ready = FireSim_tracerv_trace_insns_1_tval_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3_source_ready
    ;
  assign FireSim__tracerv_1_trace_insns_0_insn_source_ready = FireSim_tracerv_1_trace_insns_0_insn_source_ready;
  assign FireSim__tracerv_4_trace_insns_0_insn_source_ready = FireSim_tracerv_4_trace_insns_0_insn_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_6_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_6_source_ready
    ;
  assign FireSim__ep_1_axi4_aw_fwd_source_ready = FireSim_ep_1_axi4_aw_fwd_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3_source_ready
    ;
  assign FireSim__tracerv_4_trace_insns_0_valid_source_ready = FireSim_tracerv_4_trace_insns_0_valid_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
    ;
  assign FireSim__tracerv_3_trace_insns_0_exception_source_ready =
    FireSim_tracerv_3_trace_insns_0_exception_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_5_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_5_source_ready
    ;
  assign FireSim__tracerv_trace_insns_0_wdata_source_ready = FireSim_tracerv_trace_insns_0_wdata_source_ready;
  assign FireSim__tracerv_1_trace_insns_0_tval_source_ready = FireSim_tracerv_1_trace_insns_0_tval_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
    ;
  assign FireSim__tracerv_trace_insns_1_priv_source_ready = FireSim_tracerv_trace_insns_1_priv_source_ready;
  assign FireSim__tracerv_trace_insns_0_valid_source_ready = FireSim_tracerv_trace_insns_0_valid_source_ready;
  assign FireSim__ep_2_uart_txd_source_ready = FireSim_ep_2_uart_txd_source_ready;
  assign FireSim__synthesizedPrintf_clockBridge_clocks_1_globalReset_source_ready =
    FireSim_synthesizedPrintf_clockBridge_clocks_1_globalReset_source_ready;
  assign FireSim__ep_tsi_out_fwd_source_ready = FireSim_ep_tsi_out_fwd_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11_source_ready
    ;
  assign FireSim__tracerv_4_trace_insns_0_priv_source_ready = FireSim_tracerv_4_trace_insns_0_priv_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
    ;
  assign FireSim__tracerv_trace_insns_2_iaddr_source_ready = FireSim_tracerv_trace_insns_2_iaddr_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable_source_ready
    ;
  assign FireSim__tracerv_1_trace_insns_0_cause_source_ready = FireSim_tracerv_1_trace_insns_0_cause_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
    ;
  assign FireSim__tracerv_trace_insns_2_tval_source_ready = FireSim_tracerv_trace_insns_2_tval_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
    ;
  assign FireSim__tracerv_4_trace_reset_source_ready = FireSim_tracerv_4_trace_reset_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
    ;
  assign FireSim__ep_3_bdev_req_fwd_source_ready = FireSim_ep_3_bdev_req_fwd_source_ready;
  assign FireSim__tracerv_trace_insns_1_cause_source_ready = FireSim_tracerv_trace_insns_1_cause_source_ready;
  assign FireSim__tracerv_2_trace_insns_0_valid_source_ready = FireSim_tracerv_2_trace_insns_0_valid_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_9_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_9_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12_source_ready
    ;
  assign FireSim__tracerv_3_trace_insns_0_priv_source_ready = FireSim_tracerv_3_trace_insns_0_priv_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
    ;
  assign FireSim__tracerv_2_trace_insns_0_exception_source_ready =
    FireSim_tracerv_2_trace_insns_0_exception_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4_source_ready
    ;
  assign FireSim__tracerv_trace_insns_0_cause_source_ready = FireSim_tracerv_trace_insns_0_cause_source_ready;
  assign FireSim__ep_1_axi4_b_ready_source_ready = FireSim_ep_1_axi4_b_ready_source_ready;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable_source_ready
    ;
  assign
    FireSim__synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
     =
    FireSim_synthesizedPrintf_lazyModule_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3_source_ready
    ;
  assign FireSim__tracerv_4_trace_insns_0_iaddr_source_ready = FireSim_tracerv_4_trace_insns_0_iaddr_source_ready;
  assign FireSim__tracerv_3_trace_reset_source_ready = FireSim_tracerv_3_trace_reset_source_ready;
endmodule