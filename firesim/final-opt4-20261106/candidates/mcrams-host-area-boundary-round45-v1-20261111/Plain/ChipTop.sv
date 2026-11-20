module ChipTop(
  output        serial_tl_clock,
  output        serial_tl_bits_in_ready,
  input         serial_tl_bits_in_valid,
  input  [3:0]  serial_tl_bits_in_bits,
  input         serial_tl_bits_out_ready,
  output        serial_tl_bits_out_valid,
  output [3:0]  serial_tl_bits_out_bits,
  input         custom_boot,
  input         async_reset,
  input         clocks_clocks_0,
  input         clocks_clocks_1,
  input         clocks_clocks_2,
  input         clocks_clocks_3,
  input         clocks_clocks_4,
  input         clocks_clocks_5,
  input         clocks_clocks_6,
  input         clocks_clocks_7,
  input         clocks_clocks_8,
  input         clocks_clocks_9,
  input         clocks_clocks_10,
  input         clocks_clocks_11,
  output        axi4_mem_0_clock,
  output        axi4_mem_0_reset,
  input         axi4_mem_0_bits_aw_ready,
  output        axi4_mem_0_bits_aw_valid,
  output [3:0]  axi4_mem_0_bits_aw_bits_id,
  output [34:0] axi4_mem_0_bits_aw_bits_addr,
  output [7:0]  axi4_mem_0_bits_aw_bits_len,
  output [2:0]  axi4_mem_0_bits_aw_bits_size,
  output [1:0]  axi4_mem_0_bits_aw_bits_burst,
  output        axi4_mem_0_bits_aw_bits_lock,
  output [3:0]  axi4_mem_0_bits_aw_bits_cache,
  output [2:0]  axi4_mem_0_bits_aw_bits_prot,
  output [3:0]  axi4_mem_0_bits_aw_bits_qos,
  input         axi4_mem_0_bits_w_ready,
  output        axi4_mem_0_bits_w_valid,
  output [63:0] axi4_mem_0_bits_w_bits_data,
  output [7:0]  axi4_mem_0_bits_w_bits_strb,
  output        axi4_mem_0_bits_w_bits_last,
  output        axi4_mem_0_bits_b_ready,
  input         axi4_mem_0_bits_b_valid,
  input  [3:0]  axi4_mem_0_bits_b_bits_id,
  input  [1:0]  axi4_mem_0_bits_b_bits_resp,
  input         axi4_mem_0_bits_ar_ready,
  output        axi4_mem_0_bits_ar_valid,
  output [3:0]  axi4_mem_0_bits_ar_bits_id,
  output [34:0] axi4_mem_0_bits_ar_bits_addr,
  output [7:0]  axi4_mem_0_bits_ar_bits_len,
  output [2:0]  axi4_mem_0_bits_ar_bits_size,
  output [1:0]  axi4_mem_0_bits_ar_bits_burst,
  output        axi4_mem_0_bits_ar_bits_lock,
  output [3:0]  axi4_mem_0_bits_ar_bits_cache,
  output [2:0]  axi4_mem_0_bits_ar_bits_prot,
  output [3:0]  axi4_mem_0_bits_ar_bits_qos,
  output        axi4_mem_0_bits_r_ready,
  input         axi4_mem_0_bits_r_valid,
  input  [3:0]  axi4_mem_0_bits_r_bits_id,
  input  [63:0] axi4_mem_0_bits_r_bits_data,
  input  [1:0]  axi4_mem_0_bits_r_bits_resp,
  input         axi4_mem_0_bits_r_bits_last,
  output        blockdev_clock,
  input         blockdev_bits_req_ready,
  output        blockdev_bits_req_valid,
  output        blockdev_bits_req_bits_write,
  output [31:0] blockdev_bits_req_bits_offset,
  output [31:0] blockdev_bits_req_bits_len,
  output        blockdev_bits_req_bits_tag,
  input         blockdev_bits_data_ready,
  output        blockdev_bits_data_valid,
  output [63:0] blockdev_bits_data_bits_data,
  output        blockdev_bits_data_bits_tag,
  output        blockdev_bits_resp_ready,
  input         blockdev_bits_resp_valid,
  input  [63:0] blockdev_bits_resp_bits_data,
  input         blockdev_bits_resp_bits_tag,
  input  [31:0] blockdev_bits_info_nsectors,
  input  [31:0] blockdev_bits_info_max_req_len,
  output        uart_0_txd,
  input         uart_0_rxd,
  output        trace_traces_4_clock,
  output        trace_traces_4_reset,
  output        trace_traces_4_insns_0_valid,
  output [39:0] trace_traces_4_insns_0_iaddr,
  output [31:0] trace_traces_4_insns_0_insn,
  output [2:0]  trace_traces_4_insns_0_priv,
  output        trace_traces_4_insns_0_exception,
  output        trace_traces_4_insns_0_interrupt,
  output [63:0] trace_traces_4_insns_0_cause,
  output [39:0] trace_traces_4_insns_0_tval,
  output        trace_traces_3_clock,
  output        trace_traces_3_reset,
  output        trace_traces_3_insns_0_valid,
  output [39:0] trace_traces_3_insns_0_iaddr,
  output [31:0] trace_traces_3_insns_0_insn,
  output [2:0]  trace_traces_3_insns_0_priv,
  output        trace_traces_3_insns_0_exception,
  output        trace_traces_3_insns_0_interrupt,
  output [63:0] trace_traces_3_insns_0_cause,
  output [39:0] trace_traces_3_insns_0_tval,
  output        trace_traces_2_clock,
  output        trace_traces_2_reset,
  output        trace_traces_2_insns_0_valid,
  output [39:0] trace_traces_2_insns_0_iaddr,
  output [31:0] trace_traces_2_insns_0_insn,
  output [2:0]  trace_traces_2_insns_0_priv,
  output        trace_traces_2_insns_0_exception,
  output        trace_traces_2_insns_0_interrupt,
  output [63:0] trace_traces_2_insns_0_cause,
  output [39:0] trace_traces_2_insns_0_tval,
  output        trace_traces_1_clock,
  output        trace_traces_1_reset,
  output        trace_traces_1_insns_0_valid,
  output [39:0] trace_traces_1_insns_0_iaddr,
  output [31:0] trace_traces_1_insns_0_insn,
  output [2:0]  trace_traces_1_insns_0_priv,
  output        trace_traces_1_insns_0_exception,
  output        trace_traces_1_insns_0_interrupt,
  output [63:0] trace_traces_1_insns_0_cause,
  output [39:0] trace_traces_1_insns_0_tval,
  output        trace_traces_0_clock,
  output        trace_traces_0_reset,
  output        trace_traces_0_insns_0_valid,
  output [39:0] trace_traces_0_insns_0_iaddr,
  output [31:0] trace_traces_0_insns_0_insn,
  output [63:0] trace_traces_0_insns_0_wdata,
  output [2:0]  trace_traces_0_insns_0_priv,
  output        trace_traces_0_insns_0_exception,
  output        trace_traces_0_insns_0_interrupt,
  output [63:0] trace_traces_0_insns_0_cause,
  output [39:0] trace_traces_0_insns_0_tval,
  output        trace_traces_0_insns_1_valid,
  output [39:0] trace_traces_0_insns_1_iaddr,
  output [31:0] trace_traces_0_insns_1_insn,
  output [63:0] trace_traces_0_insns_1_wdata,
  output [2:0]  trace_traces_0_insns_1_priv,
  output        trace_traces_0_insns_1_exception,
  output        trace_traces_0_insns_1_interrupt,
  output [63:0] trace_traces_0_insns_1_cause,
  output [39:0] trace_traces_0_insns_1_tval,
  output        trace_traces_0_insns_2_valid,
  output [39:0] trace_traces_0_insns_2_iaddr,
  output [31:0] trace_traces_0_insns_2_insn,
  output [63:0] trace_traces_0_insns_2_wdata,
  output [2:0]  trace_traces_0_insns_2_priv,
  output        trace_traces_0_insns_2_exception,
  output        trace_traces_0_insns_2_interrupt,
  output [63:0] trace_traces_0_insns_2_cause,
  output [39:0] trace_traces_0_insns_2_tval,
  output        synthesizedPrintf_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable,
  output [63:0] synthesizedPrintf_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0,
  output [63:0] synthesizedPrintf_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1,
  output [63:0] synthesizedPrintf_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2,
  output [63:0] synthesizedPrintf_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3,
  output [63:0] synthesizedPrintf_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4,
  output        synthesizedPrintf_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11,
  output [63:0] synthesizedPrintf_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12,
  output        synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable,
  output [2:0]  synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0,
  output [31:0] synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1,
  output [63:0] synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2,
  output [1:0]  synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3,
  output        synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable,
  output [2:0]  synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0,
  output [31:0] synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1,
  output [1:0]  synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2,
  output        synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3,
  output        synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4,
  output        synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable,
  output [2:0]  synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0,
  output [31:0] synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1,
  output [63:0] synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2,
  output [1:0]  synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3,
  output        synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable,
  output [2:0]  synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0,
  output [31:0] synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1,
  output [1:0]  synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2,
  output        synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3,
  output        synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4,
  output        synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable,
  output [2:0]  synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0,
  output [31:0] synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1,
  output [63:0] synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2,
  output [1:0]  synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3,
  output        synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable,
  output [2:0]  synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0,
  output [31:0] synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1,
  output [1:0]  synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2,
  output        synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3,
  output        synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4,
  output        synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable,
  output [2:0]  synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0,
  output [31:0] synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1,
  output [63:0] synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2,
  output [1:0]  synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3,
  output        synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable,
  output [2:0]  synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0,
  output [31:0] synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1,
  output [1:0]  synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2,
  output        synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3,
  output        synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4
);
  wire  system_clock; // @[ChipTop.scala 28:35]
  wire  system_reset; // @[ChipTop.scala 28:35]
  wire  system_auto_implicitClockGrouper_out_clock; // @[ChipTop.scala 28:35]
  wire  system_auto_implicitClockGrouper_out_reset; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_implicit_clock_clock; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_implicit_clock_reset; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_cbus_0_clock; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_cbus_0_reset; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_mbus_0_clock; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_mbus_0_reset; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_fbus_0_clock; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_fbus_0_reset; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_pbus_0_clock; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_pbus_0_reset; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_4_clock; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_4_reset; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_3_clock; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_3_reset; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_2_clock; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_2_reset; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_1_clock; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_1_reset; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_sbus_1_clock; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_sbus_1_reset; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_sbus_0_clock; // @[ChipTop.scala 28:35]
  wire  system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_sbus_0_reset; // @[ChipTop.scala 28:35]
  wire  system_auto_subsystem_mbus_fixedClockNode_out_clock; // @[ChipTop.scala 28:35]
  wire  system_auto_subsystem_mbus_fixedClockNode_out_reset; // @[ChipTop.scala 28:35]
  wire  system_mem_axi4_0_aw_ready; // @[ChipTop.scala 28:35]
  wire  system_mem_axi4_0_aw_valid; // @[ChipTop.scala 28:35]
  wire [3:0] system_mem_axi4_0_aw_bits_id; // @[ChipTop.scala 28:35]
  wire [34:0] system_mem_axi4_0_aw_bits_addr; // @[ChipTop.scala 28:35]
  wire [7:0] system_mem_axi4_0_aw_bits_len; // @[ChipTop.scala 28:35]
  wire [2:0] system_mem_axi4_0_aw_bits_size; // @[ChipTop.scala 28:35]
  wire [1:0] system_mem_axi4_0_aw_bits_burst; // @[ChipTop.scala 28:35]
  wire  system_mem_axi4_0_aw_bits_lock; // @[ChipTop.scala 28:35]
  wire [3:0] system_mem_axi4_0_aw_bits_cache; // @[ChipTop.scala 28:35]
  wire [2:0] system_mem_axi4_0_aw_bits_prot; // @[ChipTop.scala 28:35]
  wire [3:0] system_mem_axi4_0_aw_bits_qos; // @[ChipTop.scala 28:35]
  wire  system_mem_axi4_0_w_ready; // @[ChipTop.scala 28:35]
  wire  system_mem_axi4_0_w_valid; // @[ChipTop.scala 28:35]
  wire [63:0] system_mem_axi4_0_w_bits_data; // @[ChipTop.scala 28:35]
  wire [7:0] system_mem_axi4_0_w_bits_strb; // @[ChipTop.scala 28:35]
  wire  system_mem_axi4_0_w_bits_last; // @[ChipTop.scala 28:35]
  wire  system_mem_axi4_0_b_ready; // @[ChipTop.scala 28:35]
  wire  system_mem_axi4_0_b_valid; // @[ChipTop.scala 28:35]
  wire [3:0] system_mem_axi4_0_b_bits_id; // @[ChipTop.scala 28:35]
  wire [1:0] system_mem_axi4_0_b_bits_resp; // @[ChipTop.scala 28:35]
  wire  system_mem_axi4_0_ar_ready; // @[ChipTop.scala 28:35]
  wire  system_mem_axi4_0_ar_valid; // @[ChipTop.scala 28:35]
  wire [3:0] system_mem_axi4_0_ar_bits_id; // @[ChipTop.scala 28:35]
  wire [34:0] system_mem_axi4_0_ar_bits_addr; // @[ChipTop.scala 28:35]
  wire [7:0] system_mem_axi4_0_ar_bits_len; // @[ChipTop.scala 28:35]
  wire [2:0] system_mem_axi4_0_ar_bits_size; // @[ChipTop.scala 28:35]
  wire [1:0] system_mem_axi4_0_ar_bits_burst; // @[ChipTop.scala 28:35]
  wire  system_mem_axi4_0_ar_bits_lock; // @[ChipTop.scala 28:35]
  wire [3:0] system_mem_axi4_0_ar_bits_cache; // @[ChipTop.scala 28:35]
  wire [2:0] system_mem_axi4_0_ar_bits_prot; // @[ChipTop.scala 28:35]
  wire [3:0] system_mem_axi4_0_ar_bits_qos; // @[ChipTop.scala 28:35]
  wire  system_mem_axi4_0_r_ready; // @[ChipTop.scala 28:35]
  wire  system_mem_axi4_0_r_valid; // @[ChipTop.scala 28:35]
  wire [3:0] system_mem_axi4_0_r_bits_id; // @[ChipTop.scala 28:35]
  wire [63:0] system_mem_axi4_0_r_bits_data; // @[ChipTop.scala 28:35]
  wire [1:0] system_mem_axi4_0_r_bits_resp; // @[ChipTop.scala 28:35]
  wire  system_mem_axi4_0_r_bits_last; // @[ChipTop.scala 28:35]
  wire  system_custom_boot; // @[ChipTop.scala 28:35]
  wire  system_bdev_clock; // @[ChipTop.scala 28:35]
  wire  system_bdev_bits_req_ready; // @[ChipTop.scala 28:35]
  wire  system_bdev_bits_req_valid; // @[ChipTop.scala 28:35]
  wire  system_bdev_bits_req_bits_write; // @[ChipTop.scala 28:35]
  wire [31:0] system_bdev_bits_req_bits_offset; // @[ChipTop.scala 28:35]
  wire [31:0] system_bdev_bits_req_bits_len; // @[ChipTop.scala 28:35]
  wire  system_bdev_bits_data_ready; // @[ChipTop.scala 28:35]
  wire  system_bdev_bits_data_valid; // @[ChipTop.scala 28:35]
  wire [63:0] system_bdev_bits_data_bits_data; // @[ChipTop.scala 28:35]
  wire  system_bdev_bits_resp_ready; // @[ChipTop.scala 28:35]
  wire  system_bdev_bits_resp_valid; // @[ChipTop.scala 28:35]
  wire [63:0] system_bdev_bits_resp_bits_data; // @[ChipTop.scala 28:35]
  wire  system_bdev_bits_resp_bits_tag; // @[ChipTop.scala 28:35]
  wire [31:0] system_bdev_bits_info_nsectors; // @[ChipTop.scala 28:35]
  wire [31:0] system_bdev_bits_info_max_req_len; // @[ChipTop.scala 28:35]
  wire  system_serial_tl_clock; // @[ChipTop.scala 28:35]
  wire  system_serial_tl_bits_in_ready; // @[ChipTop.scala 28:35]
  wire  system_serial_tl_bits_in_valid; // @[ChipTop.scala 28:35]
  wire [3:0] system_serial_tl_bits_in_bits; // @[ChipTop.scala 28:35]
  wire  system_serial_tl_bits_out_ready; // @[ChipTop.scala 28:35]
  wire  system_serial_tl_bits_out_valid; // @[ChipTop.scala 28:35]
  wire [3:0] system_serial_tl_bits_out_bits; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_4_clock; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_4_reset; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_4_insns_0_valid; // @[ChipTop.scala 28:35]
  wire [39:0] system_traceIO_traces_4_insns_0_iaddr; // @[ChipTop.scala 28:35]
  wire [31:0] system_traceIO_traces_4_insns_0_insn; // @[ChipTop.scala 28:35]
  wire [2:0] system_traceIO_traces_4_insns_0_priv; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_4_insns_0_exception; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_4_insns_0_interrupt; // @[ChipTop.scala 28:35]
  wire [63:0] system_traceIO_traces_4_insns_0_cause; // @[ChipTop.scala 28:35]
  wire [39:0] system_traceIO_traces_4_insns_0_tval; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_3_clock; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_3_reset; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_3_insns_0_valid; // @[ChipTop.scala 28:35]
  wire [39:0] system_traceIO_traces_3_insns_0_iaddr; // @[ChipTop.scala 28:35]
  wire [31:0] system_traceIO_traces_3_insns_0_insn; // @[ChipTop.scala 28:35]
  wire [2:0] system_traceIO_traces_3_insns_0_priv; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_3_insns_0_exception; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_3_insns_0_interrupt; // @[ChipTop.scala 28:35]
  wire [63:0] system_traceIO_traces_3_insns_0_cause; // @[ChipTop.scala 28:35]
  wire [39:0] system_traceIO_traces_3_insns_0_tval; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_2_clock; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_2_reset; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_2_insns_0_valid; // @[ChipTop.scala 28:35]
  wire [39:0] system_traceIO_traces_2_insns_0_iaddr; // @[ChipTop.scala 28:35]
  wire [31:0] system_traceIO_traces_2_insns_0_insn; // @[ChipTop.scala 28:35]
  wire [2:0] system_traceIO_traces_2_insns_0_priv; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_2_insns_0_exception; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_2_insns_0_interrupt; // @[ChipTop.scala 28:35]
  wire [63:0] system_traceIO_traces_2_insns_0_cause; // @[ChipTop.scala 28:35]
  wire [39:0] system_traceIO_traces_2_insns_0_tval; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_1_clock; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_1_reset; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_1_insns_0_valid; // @[ChipTop.scala 28:35]
  wire [39:0] system_traceIO_traces_1_insns_0_iaddr; // @[ChipTop.scala 28:35]
  wire [31:0] system_traceIO_traces_1_insns_0_insn; // @[ChipTop.scala 28:35]
  wire [2:0] system_traceIO_traces_1_insns_0_priv; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_1_insns_0_exception; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_1_insns_0_interrupt; // @[ChipTop.scala 28:35]
  wire [63:0] system_traceIO_traces_1_insns_0_cause; // @[ChipTop.scala 28:35]
  wire [39:0] system_traceIO_traces_1_insns_0_tval; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_0_clock; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_0_reset; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_0_insns_0_valid; // @[ChipTop.scala 28:35]
  wire [39:0] system_traceIO_traces_0_insns_0_iaddr; // @[ChipTop.scala 28:35]
  wire [31:0] system_traceIO_traces_0_insns_0_insn; // @[ChipTop.scala 28:35]
  wire [63:0] system_traceIO_traces_0_insns_0_wdata; // @[ChipTop.scala 28:35]
  wire [2:0] system_traceIO_traces_0_insns_0_priv; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_0_insns_0_exception; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_0_insns_0_interrupt; // @[ChipTop.scala 28:35]
  wire [63:0] system_traceIO_traces_0_insns_0_cause; // @[ChipTop.scala 28:35]
  wire [39:0] system_traceIO_traces_0_insns_0_tval; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_0_insns_1_valid; // @[ChipTop.scala 28:35]
  wire [39:0] system_traceIO_traces_0_insns_1_iaddr; // @[ChipTop.scala 28:35]
  wire [31:0] system_traceIO_traces_0_insns_1_insn; // @[ChipTop.scala 28:35]
  wire [63:0] system_traceIO_traces_0_insns_1_wdata; // @[ChipTop.scala 28:35]
  wire [2:0] system_traceIO_traces_0_insns_1_priv; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_0_insns_1_exception; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_0_insns_1_interrupt; // @[ChipTop.scala 28:35]
  wire [63:0] system_traceIO_traces_0_insns_1_cause; // @[ChipTop.scala 28:35]
  wire [39:0] system_traceIO_traces_0_insns_1_tval; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_0_insns_2_valid; // @[ChipTop.scala 28:35]
  wire [39:0] system_traceIO_traces_0_insns_2_iaddr; // @[ChipTop.scala 28:35]
  wire [31:0] system_traceIO_traces_0_insns_2_insn; // @[ChipTop.scala 28:35]
  wire [63:0] system_traceIO_traces_0_insns_2_wdata; // @[ChipTop.scala 28:35]
  wire [2:0] system_traceIO_traces_0_insns_2_priv; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_0_insns_2_exception; // @[ChipTop.scala 28:35]
  wire  system_traceIO_traces_0_insns_2_interrupt; // @[ChipTop.scala 28:35]
  wire [63:0] system_traceIO_traces_0_insns_2_cause; // @[ChipTop.scala 28:35]
  wire [39:0] system_traceIO_traces_0_insns_2_tval; // @[ChipTop.scala 28:35]
  wire  system_uart_0_txd; // @[ChipTop.scala 28:35]
  wire  system_uart_0_rxd; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable; // @[ChipTop.scala 28:35]
  wire [63:0] system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0; // @[ChipTop.scala 28:35]
  wire [63:0] system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1; // @[ChipTop.scala 28:35]
  wire [63:0] system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2; // @[ChipTop.scala 28:35]
  wire [63:0] system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3; // @[ChipTop.scala 28:35]
  wire [63:0] system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11; // @[ChipTop.scala 28:35]
  wire [63:0] system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable; // @[ChipTop.scala 28:35]
  wire [2:0] system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0; // @[ChipTop.scala 28:35]
  wire [31:0] system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1; // @[ChipTop.scala 28:35]
  wire [63:0] system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2; // @[ChipTop.scala 28:35]
  wire [1:0] system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable; // @[ChipTop.scala 28:35]
  wire [2:0] system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0; // @[ChipTop.scala 28:35]
  wire [31:0] system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1; // @[ChipTop.scala 28:35]
  wire [1:0] system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable; // @[ChipTop.scala 28:35]
  wire [2:0] system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0; // @[ChipTop.scala 28:35]
  wire [31:0] system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1; // @[ChipTop.scala 28:35]
  wire [63:0] system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2; // @[ChipTop.scala 28:35]
  wire [1:0] system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable; // @[ChipTop.scala 28:35]
  wire [2:0] system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0; // @[ChipTop.scala 28:35]
  wire [31:0] system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1; // @[ChipTop.scala 28:35]
  wire [1:0] system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable; // @[ChipTop.scala 28:35]
  wire [2:0] system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0; // @[ChipTop.scala 28:35]
  wire [31:0] system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1; // @[ChipTop.scala 28:35]
  wire [63:0] system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2; // @[ChipTop.scala 28:35]
  wire [1:0] system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable; // @[ChipTop.scala 28:35]
  wire [2:0] system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0; // @[ChipTop.scala 28:35]
  wire [31:0] system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1; // @[ChipTop.scala 28:35]
  wire [1:0] system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable; // @[ChipTop.scala 28:35]
  wire [2:0] system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0; // @[ChipTop.scala 28:35]
  wire [31:0] system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1; // @[ChipTop.scala 28:35]
  wire [63:0] system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2; // @[ChipTop.scala 28:35]
  wire [1:0] system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable; // @[ChipTop.scala 28:35]
  wire [2:0] system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0; // @[ChipTop.scala 28:35]
  wire [31:0] system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1; // @[ChipTop.scala 28:35]
  wire [1:0] system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3; // @[ChipTop.scala 28:35]
  wire  system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4; // @[ChipTop.scala 28:35]
  wire  iocell_serial_tl_bits_out_bits_io_in_0_ready; // @[BridgeBinders.scala 64:24]
  wire  iocell_serial_tl_bits_out_bits_io_out_ready; // @[BridgeBinders.scala 64:24]
  wire  iocell_serial_tl_bits_out_bits_1_io_in_0_ready; // @[BridgeBinders.scala 64:24]
  wire  iocell_serial_tl_bits_out_bits_1_io_out_ready; // @[BridgeBinders.scala 64:24]
  wire  iocell_serial_tl_bits_out_bits_2_io_in_0_ready; // @[BridgeBinders.scala 64:24]
  wire  iocell_serial_tl_bits_out_bits_2_io_out_ready; // @[BridgeBinders.scala 64:24]
  wire  iocell_serial_tl_bits_out_bits_3_io_in_0_ready; // @[BridgeBinders.scala 64:24]
  wire  iocell_serial_tl_bits_out_bits_3_io_out_ready; // @[BridgeBinders.scala 64:24]
  wire  iocell_serial_tl_bits_out_valid_io_in_0_ready; // @[BridgeBinders.scala 64:24]
  wire  iocell_serial_tl_bits_out_valid_io_out_ready; // @[BridgeBinders.scala 64:24]
  wire  iocell_serial_tl_bits_out_ready_io_in; // @[BridgeBinders.scala 63:24]
  wire  iocell_serial_tl_bits_out_ready_io_out; // @[BridgeBinders.scala 63:24]
  wire  iocell_serial_tl_bits_in_bits_io_in; // @[BridgeBinders.scala 63:24]
  wire  iocell_serial_tl_bits_in_bits_io_out; // @[BridgeBinders.scala 63:24]
  wire  iocell_serial_tl_bits_in_bits_1_io_in; // @[BridgeBinders.scala 63:24]
  wire  iocell_serial_tl_bits_in_bits_1_io_out; // @[BridgeBinders.scala 63:24]
  wire  iocell_serial_tl_bits_in_bits_2_io_in; // @[BridgeBinders.scala 63:24]
  wire  iocell_serial_tl_bits_in_bits_2_io_out; // @[BridgeBinders.scala 63:24]
  wire  iocell_serial_tl_bits_in_bits_3_io_in; // @[BridgeBinders.scala 63:24]
  wire  iocell_serial_tl_bits_in_bits_3_io_out; // @[BridgeBinders.scala 63:24]
  wire  iocell_serial_tl_bits_in_valid_io_in; // @[BridgeBinders.scala 63:24]
  wire  iocell_serial_tl_bits_in_valid_io_out; // @[BridgeBinders.scala 63:24]
  wire  iocell_serial_tl_bits_in_ready_io_in_0_ready; // @[BridgeBinders.scala 64:24]
  wire  iocell_serial_tl_bits_in_ready_io_out_ready; // @[BridgeBinders.scala 64:24]
  wire  iocell_serial_tl_clock_io_in_0_ready; // @[BridgeBinders.scala 64:24]
  wire  iocell_serial_tl_clock_io_out_ready; // @[BridgeBinders.scala 64:24]
  wire  iocell_custom_boot_io_in; // @[BridgeBinders.scala 63:24]
  wire  iocell_custom_boot_io_out; // @[BridgeBinders.scala 63:24]
  wire  iocell_uart_0_rxd_io_in; // @[BridgeBinders.scala 63:24]
  wire  iocell_uart_0_rxd_io_out; // @[BridgeBinders.scala 63:24]
  wire  iocell_uart_0_txd_io_in_0_ready; // @[BridgeBinders.scala 64:24]
  wire  iocell_uart_0_txd_io_out_ready; // @[BridgeBinders.scala 64:24]
  wire [1:0] serial_tl_bits_out_bits_lo = {iocell_serial_tl_bits_out_bits_1_io_in_0_ready,
    iocell_serial_tl_bits_out_bits_io_in_0_ready}; // @[Cat.scala 33:92]
  wire [1:0] serial_tl_bits_out_bits_hi = {iocell_serial_tl_bits_out_bits_3_io_in_0_ready,
    iocell_serial_tl_bits_out_bits_2_io_in_0_ready}; // @[Cat.scala 33:92]
  wire [1:0] system_serial_tl_bits_in_bits_lo = {iocell_serial_tl_bits_in_bits_1_io_out,
    iocell_serial_tl_bits_in_bits_io_out}; // @[Cat.scala 33:92]
  wire [1:0] system_serial_tl_bits_in_bits_hi = {iocell_serial_tl_bits_in_bits_3_io_out,
    iocell_serial_tl_bits_in_bits_2_io_out}; // @[Cat.scala 33:92]
  DigitalTop system ( // @[ChipTop.scala 28:35]
    .clock(system_clock),
    .reset(system_reset),
    .auto_implicitClockGrouper_out_clock(system_auto_implicitClockGrouper_out_clock),
    .auto_implicitClockGrouper_out_reset(system_auto_implicitClockGrouper_out_reset),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_implicit_clock_clock(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_implicit_clock_clock),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_implicit_clock_reset(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_implicit_clock_reset),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_cbus_0_clock(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_cbus_0_clock),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_cbus_0_reset(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_cbus_0_reset),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_mbus_0_clock(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_mbus_0_clock),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_mbus_0_reset(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_mbus_0_reset),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_fbus_0_clock(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_fbus_0_clock),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_fbus_0_reset(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_fbus_0_reset),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_pbus_0_clock(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_pbus_0_clock),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_pbus_0_reset(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_pbus_0_reset),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_4_clock(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_4_clock),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_4_reset(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_4_reset),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_3_clock(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_3_clock),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_3_reset(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_3_reset),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_2_clock(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_2_clock),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_2_reset(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_2_reset),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_1_clock(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_1_clock),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_1_reset(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_1_reset),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_sbus_1_clock(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_sbus_1_clock),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_sbus_1_reset(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_sbus_1_reset),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_sbus_0_clock(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_sbus_0_clock),
    .auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_sbus_0_reset(
      system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_sbus_0_reset),
    .auto_subsystem_mbus_fixedClockNode_out_clock(system_auto_subsystem_mbus_fixedClockNode_out_clock),
    .auto_subsystem_mbus_fixedClockNode_out_reset(system_auto_subsystem_mbus_fixedClockNode_out_reset),
    .mem_axi4_0_aw_ready(system_mem_axi4_0_aw_ready),
    .mem_axi4_0_aw_valid(system_mem_axi4_0_aw_valid),
    .mem_axi4_0_aw_bits_id(system_mem_axi4_0_aw_bits_id),
    .mem_axi4_0_aw_bits_addr(system_mem_axi4_0_aw_bits_addr),
    .mem_axi4_0_aw_bits_len(system_mem_axi4_0_aw_bits_len),
    .mem_axi4_0_aw_bits_size(system_mem_axi4_0_aw_bits_size),
    .mem_axi4_0_aw_bits_burst(system_mem_axi4_0_aw_bits_burst),
    .mem_axi4_0_aw_bits_lock(system_mem_axi4_0_aw_bits_lock),
    .mem_axi4_0_aw_bits_cache(system_mem_axi4_0_aw_bits_cache),
    .mem_axi4_0_aw_bits_prot(system_mem_axi4_0_aw_bits_prot),
    .mem_axi4_0_aw_bits_qos(system_mem_axi4_0_aw_bits_qos),
    .mem_axi4_0_w_ready(system_mem_axi4_0_w_ready),
    .mem_axi4_0_w_valid(system_mem_axi4_0_w_valid),
    .mem_axi4_0_w_bits_data(system_mem_axi4_0_w_bits_data),
    .mem_axi4_0_w_bits_strb(system_mem_axi4_0_w_bits_strb),
    .mem_axi4_0_w_bits_last(system_mem_axi4_0_w_bits_last),
    .mem_axi4_0_b_ready(system_mem_axi4_0_b_ready),
    .mem_axi4_0_b_valid(system_mem_axi4_0_b_valid),
    .mem_axi4_0_b_bits_id(system_mem_axi4_0_b_bits_id),
    .mem_axi4_0_b_bits_resp(system_mem_axi4_0_b_bits_resp),
    .mem_axi4_0_ar_ready(system_mem_axi4_0_ar_ready),
    .mem_axi4_0_ar_valid(system_mem_axi4_0_ar_valid),
    .mem_axi4_0_ar_bits_id(system_mem_axi4_0_ar_bits_id),
    .mem_axi4_0_ar_bits_addr(system_mem_axi4_0_ar_bits_addr),
    .mem_axi4_0_ar_bits_len(system_mem_axi4_0_ar_bits_len),
    .mem_axi4_0_ar_bits_size(system_mem_axi4_0_ar_bits_size),
    .mem_axi4_0_ar_bits_burst(system_mem_axi4_0_ar_bits_burst),
    .mem_axi4_0_ar_bits_lock(system_mem_axi4_0_ar_bits_lock),
    .mem_axi4_0_ar_bits_cache(system_mem_axi4_0_ar_bits_cache),
    .mem_axi4_0_ar_bits_prot(system_mem_axi4_0_ar_bits_prot),
    .mem_axi4_0_ar_bits_qos(system_mem_axi4_0_ar_bits_qos),
    .mem_axi4_0_r_ready(system_mem_axi4_0_r_ready),
    .mem_axi4_0_r_valid(system_mem_axi4_0_r_valid),
    .mem_axi4_0_r_bits_id(system_mem_axi4_0_r_bits_id),
    .mem_axi4_0_r_bits_data(system_mem_axi4_0_r_bits_data),
    .mem_axi4_0_r_bits_resp(system_mem_axi4_0_r_bits_resp),
    .mem_axi4_0_r_bits_last(system_mem_axi4_0_r_bits_last),
    .custom_boot(system_custom_boot),
    .bdev_clock(system_bdev_clock),
    .bdev_bits_req_ready(system_bdev_bits_req_ready),
    .bdev_bits_req_valid(system_bdev_bits_req_valid),
    .bdev_bits_req_bits_write(system_bdev_bits_req_bits_write),
    .bdev_bits_req_bits_offset(system_bdev_bits_req_bits_offset),
    .bdev_bits_req_bits_len(system_bdev_bits_req_bits_len),
    .bdev_bits_data_ready(system_bdev_bits_data_ready),
    .bdev_bits_data_valid(system_bdev_bits_data_valid),
    .bdev_bits_data_bits_data(system_bdev_bits_data_bits_data),
    .bdev_bits_resp_ready(system_bdev_bits_resp_ready),
    .bdev_bits_resp_valid(system_bdev_bits_resp_valid),
    .bdev_bits_resp_bits_data(system_bdev_bits_resp_bits_data),
    .bdev_bits_resp_bits_tag(system_bdev_bits_resp_bits_tag),
    .bdev_bits_info_nsectors(system_bdev_bits_info_nsectors),
    .bdev_bits_info_max_req_len(system_bdev_bits_info_max_req_len),
    .serial_tl_clock(system_serial_tl_clock),
    .serial_tl_bits_in_ready(system_serial_tl_bits_in_ready),
    .serial_tl_bits_in_valid(system_serial_tl_bits_in_valid),
    .serial_tl_bits_in_bits(system_serial_tl_bits_in_bits),
    .serial_tl_bits_out_ready(system_serial_tl_bits_out_ready),
    .serial_tl_bits_out_valid(system_serial_tl_bits_out_valid),
    .serial_tl_bits_out_bits(system_serial_tl_bits_out_bits),
    .traceIO_traces_4_clock(system_traceIO_traces_4_clock),
    .traceIO_traces_4_reset(system_traceIO_traces_4_reset),
    .traceIO_traces_4_insns_0_valid(system_traceIO_traces_4_insns_0_valid),
    .traceIO_traces_4_insns_0_iaddr(system_traceIO_traces_4_insns_0_iaddr),
    .traceIO_traces_4_insns_0_insn(system_traceIO_traces_4_insns_0_insn),
    .traceIO_traces_4_insns_0_priv(system_traceIO_traces_4_insns_0_priv),
    .traceIO_traces_4_insns_0_exception(system_traceIO_traces_4_insns_0_exception),
    .traceIO_traces_4_insns_0_interrupt(system_traceIO_traces_4_insns_0_interrupt),
    .traceIO_traces_4_insns_0_cause(system_traceIO_traces_4_insns_0_cause),
    .traceIO_traces_4_insns_0_tval(system_traceIO_traces_4_insns_0_tval),
    .traceIO_traces_3_clock(system_traceIO_traces_3_clock),
    .traceIO_traces_3_reset(system_traceIO_traces_3_reset),
    .traceIO_traces_3_insns_0_valid(system_traceIO_traces_3_insns_0_valid),
    .traceIO_traces_3_insns_0_iaddr(system_traceIO_traces_3_insns_0_iaddr),
    .traceIO_traces_3_insns_0_insn(system_traceIO_traces_3_insns_0_insn),
    .traceIO_traces_3_insns_0_priv(system_traceIO_traces_3_insns_0_priv),
    .traceIO_traces_3_insns_0_exception(system_traceIO_traces_3_insns_0_exception),
    .traceIO_traces_3_insns_0_interrupt(system_traceIO_traces_3_insns_0_interrupt),
    .traceIO_traces_3_insns_0_cause(system_traceIO_traces_3_insns_0_cause),
    .traceIO_traces_3_insns_0_tval(system_traceIO_traces_3_insns_0_tval),
    .traceIO_traces_2_clock(system_traceIO_traces_2_clock),
    .traceIO_traces_2_reset(system_traceIO_traces_2_reset),
    .traceIO_traces_2_insns_0_valid(system_traceIO_traces_2_insns_0_valid),
    .traceIO_traces_2_insns_0_iaddr(system_traceIO_traces_2_insns_0_iaddr),
    .traceIO_traces_2_insns_0_insn(system_traceIO_traces_2_insns_0_insn),
    .traceIO_traces_2_insns_0_priv(system_traceIO_traces_2_insns_0_priv),
    .traceIO_traces_2_insns_0_exception(system_traceIO_traces_2_insns_0_exception),
    .traceIO_traces_2_insns_0_interrupt(system_traceIO_traces_2_insns_0_interrupt),
    .traceIO_traces_2_insns_0_cause(system_traceIO_traces_2_insns_0_cause),
    .traceIO_traces_2_insns_0_tval(system_traceIO_traces_2_insns_0_tval),
    .traceIO_traces_1_clock(system_traceIO_traces_1_clock),
    .traceIO_traces_1_reset(system_traceIO_traces_1_reset),
    .traceIO_traces_1_insns_0_valid(system_traceIO_traces_1_insns_0_valid),
    .traceIO_traces_1_insns_0_iaddr(system_traceIO_traces_1_insns_0_iaddr),
    .traceIO_traces_1_insns_0_insn(system_traceIO_traces_1_insns_0_insn),
    .traceIO_traces_1_insns_0_priv(system_traceIO_traces_1_insns_0_priv),
    .traceIO_traces_1_insns_0_exception(system_traceIO_traces_1_insns_0_exception),
    .traceIO_traces_1_insns_0_interrupt(system_traceIO_traces_1_insns_0_interrupt),
    .traceIO_traces_1_insns_0_cause(system_traceIO_traces_1_insns_0_cause),
    .traceIO_traces_1_insns_0_tval(system_traceIO_traces_1_insns_0_tval),
    .traceIO_traces_0_clock(system_traceIO_traces_0_clock),
    .traceIO_traces_0_reset(system_traceIO_traces_0_reset),
    .traceIO_traces_0_insns_0_valid(system_traceIO_traces_0_insns_0_valid),
    .traceIO_traces_0_insns_0_iaddr(system_traceIO_traces_0_insns_0_iaddr),
    .traceIO_traces_0_insns_0_insn(system_traceIO_traces_0_insns_0_insn),
    .traceIO_traces_0_insns_0_wdata(system_traceIO_traces_0_insns_0_wdata),
    .traceIO_traces_0_insns_0_priv(system_traceIO_traces_0_insns_0_priv),
    .traceIO_traces_0_insns_0_exception(system_traceIO_traces_0_insns_0_exception),
    .traceIO_traces_0_insns_0_interrupt(system_traceIO_traces_0_insns_0_interrupt),
    .traceIO_traces_0_insns_0_cause(system_traceIO_traces_0_insns_0_cause),
    .traceIO_traces_0_insns_0_tval(system_traceIO_traces_0_insns_0_tval),
    .traceIO_traces_0_insns_1_valid(system_traceIO_traces_0_insns_1_valid),
    .traceIO_traces_0_insns_1_iaddr(system_traceIO_traces_0_insns_1_iaddr),
    .traceIO_traces_0_insns_1_insn(system_traceIO_traces_0_insns_1_insn),
    .traceIO_traces_0_insns_1_wdata(system_traceIO_traces_0_insns_1_wdata),
    .traceIO_traces_0_insns_1_priv(system_traceIO_traces_0_insns_1_priv),
    .traceIO_traces_0_insns_1_exception(system_traceIO_traces_0_insns_1_exception),
    .traceIO_traces_0_insns_1_interrupt(system_traceIO_traces_0_insns_1_interrupt),
    .traceIO_traces_0_insns_1_cause(system_traceIO_traces_0_insns_1_cause),
    .traceIO_traces_0_insns_1_tval(system_traceIO_traces_0_insns_1_tval),
    .traceIO_traces_0_insns_2_valid(system_traceIO_traces_0_insns_2_valid),
    .traceIO_traces_0_insns_2_iaddr(system_traceIO_traces_0_insns_2_iaddr),
    .traceIO_traces_0_insns_2_insn(system_traceIO_traces_0_insns_2_insn),
    .traceIO_traces_0_insns_2_wdata(system_traceIO_traces_0_insns_2_wdata),
    .traceIO_traces_0_insns_2_priv(system_traceIO_traces_0_insns_2_priv),
    .traceIO_traces_0_insns_2_exception(system_traceIO_traces_0_insns_2_exception),
    .traceIO_traces_0_insns_2_interrupt(system_traceIO_traces_0_insns_2_interrupt),
    .traceIO_traces_0_insns_2_cause(system_traceIO_traces_0_insns_2_cause),
    .traceIO_traces_0_insns_2_tval(system_traceIO_traces_0_insns_2_tval),
    .uart_0_txd(system_uart_0_txd),
    .uart_0_rxd(system_uart_0_rxd),
    .synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable(
      system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable),
    .synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0(
      system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0),
    .synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1(
      system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1),
    .synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2(
      system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2),
    .synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3(
      system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3),
    .synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4(
      system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4),
    .synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11(
      system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11),
    .synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12(
      system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12),
    .synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable(
      system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable),
    .synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0(
      system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0),
    .synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1(
      system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1),
    .synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2(
      system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2),
    .synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3(
      system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3),
    .synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable(
      system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable),
    .synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0(
      system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0),
    .synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1(
      system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1),
    .synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2(
      system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2),
    .synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3(
      system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3),
    .synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4(
      system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4),
    .synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable(
      system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable),
    .synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0(
      system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0),
    .synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1(
      system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1),
    .synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2(
      system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2),
    .synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3(
      system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3),
    .synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable(
      system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable),
    .synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0(
      system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0),
    .synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1(
      system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1),
    .synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2(
      system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2),
    .synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3(
      system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3),
    .synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4(
      system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4),
    .synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable(
      system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable),
    .synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0(
      system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0),
    .synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1(
      system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1),
    .synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2(
      system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2),
    .synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3(
      system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3),
    .synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable(
      system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable),
    .synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0(
      system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0),
    .synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1(
      system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1),
    .synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2(
      system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2),
    .synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3(
      system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3),
    .synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4(
      system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4),
    .synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable(
      system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable),
    .synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0(
      system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0),
    .synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1(
      system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1),
    .synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2(
      system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2),
    .synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3(
      system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3),
    .synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable(
      system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable),
    .synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0(
      system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0),
    .synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1(
      system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1),
    .synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2(
      system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2),
    .synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3(
      system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3),
    .synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4(
      system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4)
  );
  Arbiter_10 iocell_serial_tl_bits_out_bits ( // @[BridgeBinders.scala 64:24]
    .io_in_0_ready(iocell_serial_tl_bits_out_bits_io_in_0_ready),
    .io_out_ready(iocell_serial_tl_bits_out_bits_io_out_ready)
  );
  Arbiter_10 iocell_serial_tl_bits_out_bits_1 ( // @[BridgeBinders.scala 64:24]
    .io_in_0_ready(iocell_serial_tl_bits_out_bits_1_io_in_0_ready),
    .io_out_ready(iocell_serial_tl_bits_out_bits_1_io_out_ready)
  );
  Arbiter_10 iocell_serial_tl_bits_out_bits_2 ( // @[BridgeBinders.scala 64:24]
    .io_in_0_ready(iocell_serial_tl_bits_out_bits_2_io_in_0_ready),
    .io_out_ready(iocell_serial_tl_bits_out_bits_2_io_out_ready)
  );
  Arbiter_10 iocell_serial_tl_bits_out_bits_3 ( // @[BridgeBinders.scala 64:24]
    .io_in_0_ready(iocell_serial_tl_bits_out_bits_3_io_in_0_ready),
    .io_out_ready(iocell_serial_tl_bits_out_bits_3_io_out_ready)
  );
  Arbiter_10 iocell_serial_tl_bits_out_valid ( // @[BridgeBinders.scala 64:24]
    .io_in_0_ready(iocell_serial_tl_bits_out_valid_io_in_0_ready),
    .io_out_ready(iocell_serial_tl_bits_out_valid_io_out_ready)
  );
  GH_Bridge iocell_serial_tl_bits_out_ready ( // @[BridgeBinders.scala 63:24]
    .io_in(iocell_serial_tl_bits_out_ready_io_in),
    .io_out(iocell_serial_tl_bits_out_ready_io_out)
  );
  GH_Bridge iocell_serial_tl_bits_in_bits ( // @[BridgeBinders.scala 63:24]
    .io_in(iocell_serial_tl_bits_in_bits_io_in),
    .io_out(iocell_serial_tl_bits_in_bits_io_out)
  );
  GH_Bridge iocell_serial_tl_bits_in_bits_1 ( // @[BridgeBinders.scala 63:24]
    .io_in(iocell_serial_tl_bits_in_bits_1_io_in),
    .io_out(iocell_serial_tl_bits_in_bits_1_io_out)
  );
  GH_Bridge iocell_serial_tl_bits_in_bits_2 ( // @[BridgeBinders.scala 63:24]
    .io_in(iocell_serial_tl_bits_in_bits_2_io_in),
    .io_out(iocell_serial_tl_bits_in_bits_2_io_out)
  );
  GH_Bridge iocell_serial_tl_bits_in_bits_3 ( // @[BridgeBinders.scala 63:24]
    .io_in(iocell_serial_tl_bits_in_bits_3_io_in),
    .io_out(iocell_serial_tl_bits_in_bits_3_io_out)
  );
  GH_Bridge iocell_serial_tl_bits_in_valid ( // @[BridgeBinders.scala 63:24]
    .io_in(iocell_serial_tl_bits_in_valid_io_in),
    .io_out(iocell_serial_tl_bits_in_valid_io_out)
  );
  Arbiter_10 iocell_serial_tl_bits_in_ready ( // @[BridgeBinders.scala 64:24]
    .io_in_0_ready(iocell_serial_tl_bits_in_ready_io_in_0_ready),
    .io_out_ready(iocell_serial_tl_bits_in_ready_io_out_ready)
  );
  Arbiter_10 iocell_serial_tl_clock ( // @[BridgeBinders.scala 64:24]
    .io_in_0_ready(iocell_serial_tl_clock_io_in_0_ready),
    .io_out_ready(iocell_serial_tl_clock_io_out_ready)
  );
  GH_Bridge iocell_custom_boot ( // @[BridgeBinders.scala 63:24]
    .io_in(iocell_custom_boot_io_in),
    .io_out(iocell_custom_boot_io_out)
  );
  GH_Bridge iocell_uart_0_rxd ( // @[BridgeBinders.scala 63:24]
    .io_in(iocell_uart_0_rxd_io_in),
    .io_out(iocell_uart_0_rxd_io_out)
  );
  Arbiter_10 iocell_uart_0_txd ( // @[BridgeBinders.scala 64:24]
    .io_in_0_ready(iocell_uart_0_txd_io_in_0_ready),
    .io_out_ready(iocell_uart_0_txd_io_out_ready)
  );
  assign serial_tl_clock = iocell_serial_tl_clock_io_in_0_ready; // @[IOCell.scala 179:61]
  assign serial_tl_bits_in_ready = iocell_serial_tl_bits_in_ready_io_in_0_ready; // @[IOCell.scala 239:25]
  assign serial_tl_bits_out_valid = iocell_serial_tl_bits_out_valid_io_in_0_ready; // @[IOCell.scala 239:25]
  assign serial_tl_bits_out_bits = {serial_tl_bits_out_bits_hi,serial_tl_bits_out_bits_lo}; // @[Cat.scala 33:92]
  assign axi4_mem_0_clock = system_auto_subsystem_mbus_fixedClockNode_out_clock; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign axi4_mem_0_reset = system_auto_subsystem_mbus_fixedClockNode_out_reset; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign axi4_mem_0_bits_aw_valid = system_mem_axi4_0_aw_valid; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_aw_bits_id = system_mem_axi4_0_aw_bits_id; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_aw_bits_addr = system_mem_axi4_0_aw_bits_addr; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_aw_bits_len = system_mem_axi4_0_aw_bits_len; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_aw_bits_size = system_mem_axi4_0_aw_bits_size; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_aw_bits_burst = system_mem_axi4_0_aw_bits_burst; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_aw_bits_lock = system_mem_axi4_0_aw_bits_lock; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_aw_bits_cache = system_mem_axi4_0_aw_bits_cache; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_aw_bits_prot = system_mem_axi4_0_aw_bits_prot; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_aw_bits_qos = system_mem_axi4_0_aw_bits_qos; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_w_valid = system_mem_axi4_0_w_valid; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_w_bits_data = system_mem_axi4_0_w_bits_data; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_w_bits_strb = system_mem_axi4_0_w_bits_strb; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_w_bits_last = system_mem_axi4_0_w_bits_last; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_b_ready = system_mem_axi4_0_b_ready; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_ar_valid = system_mem_axi4_0_ar_valid; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_ar_bits_id = system_mem_axi4_0_ar_bits_id; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_ar_bits_addr = system_mem_axi4_0_ar_bits_addr; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_ar_bits_len = system_mem_axi4_0_ar_bits_len; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_ar_bits_size = system_mem_axi4_0_ar_bits_size; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_ar_bits_burst = system_mem_axi4_0_ar_bits_burst; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_ar_bits_lock = system_mem_axi4_0_ar_bits_lock; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_ar_bits_cache = system_mem_axi4_0_ar_bits_cache; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_ar_bits_prot = system_mem_axi4_0_ar_bits_prot; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_ar_bits_qos = system_mem_axi4_0_ar_bits_qos; // @[IOBinders.scala 317:16]
  assign axi4_mem_0_bits_r_ready = system_mem_axi4_0_r_ready; // @[IOBinders.scala 317:16]
  assign blockdev_clock = system_bdev_clock; // @[IOBinders.scala 370:9]
  assign blockdev_bits_req_valid = system_bdev_bits_req_valid; // @[IOBinders.scala 370:9]
  assign blockdev_bits_req_bits_write = system_bdev_bits_req_bits_write; // @[IOBinders.scala 370:9]
  assign blockdev_bits_req_bits_offset = system_bdev_bits_req_bits_offset; // @[IOBinders.scala 370:9]
  assign blockdev_bits_req_bits_len = system_bdev_bits_req_bits_len; // @[IOBinders.scala 370:9]
  assign blockdev_bits_req_bits_tag = 1'h0; // @[IOBinders.scala 370:9]
  assign blockdev_bits_data_valid = system_bdev_bits_data_valid; // @[IOBinders.scala 370:9]
  assign blockdev_bits_data_bits_data = system_bdev_bits_data_bits_data; // @[IOBinders.scala 370:9]
  assign blockdev_bits_data_bits_tag = 1'h0; // @[IOBinders.scala 370:9]
  assign blockdev_bits_resp_ready = system_bdev_bits_resp_ready; // @[IOBinders.scala 370:9]
  assign uart_0_txd = iocell_uart_0_txd_io_in_0_ready; // @[IOCell.scala 239:25]
  assign trace_traces_4_clock = system_traceIO_traces_4_clock; // @[IOBinders.scala 400:13]
  assign trace_traces_4_reset = system_traceIO_traces_4_reset; // @[IOBinders.scala 400:13]
  assign trace_traces_4_insns_0_valid = system_traceIO_traces_4_insns_0_valid; // @[IOBinders.scala 400:13]
  assign trace_traces_4_insns_0_iaddr = system_traceIO_traces_4_insns_0_iaddr; // @[IOBinders.scala 400:13]
  assign trace_traces_4_insns_0_insn = system_traceIO_traces_4_insns_0_insn; // @[IOBinders.scala 400:13]
  assign trace_traces_4_insns_0_priv = system_traceIO_traces_4_insns_0_priv; // @[IOBinders.scala 400:13]
  assign trace_traces_4_insns_0_exception = system_traceIO_traces_4_insns_0_exception; // @[IOBinders.scala 400:13]
  assign trace_traces_4_insns_0_interrupt = system_traceIO_traces_4_insns_0_interrupt; // @[IOBinders.scala 400:13]
  assign trace_traces_4_insns_0_cause = system_traceIO_traces_4_insns_0_cause; // @[IOBinders.scala 400:13]
  assign trace_traces_4_insns_0_tval = system_traceIO_traces_4_insns_0_tval; // @[IOBinders.scala 400:13]
  assign trace_traces_3_clock = system_traceIO_traces_3_clock; // @[IOBinders.scala 400:13]
  assign trace_traces_3_reset = system_traceIO_traces_3_reset; // @[IOBinders.scala 400:13]
  assign trace_traces_3_insns_0_valid = system_traceIO_traces_3_insns_0_valid; // @[IOBinders.scala 400:13]
  assign trace_traces_3_insns_0_iaddr = system_traceIO_traces_3_insns_0_iaddr; // @[IOBinders.scala 400:13]
  assign trace_traces_3_insns_0_insn = system_traceIO_traces_3_insns_0_insn; // @[IOBinders.scala 400:13]
  assign trace_traces_3_insns_0_priv = system_traceIO_traces_3_insns_0_priv; // @[IOBinders.scala 400:13]
  assign trace_traces_3_insns_0_exception = system_traceIO_traces_3_insns_0_exception; // @[IOBinders.scala 400:13]
  assign trace_traces_3_insns_0_interrupt = system_traceIO_traces_3_insns_0_interrupt; // @[IOBinders.scala 400:13]
  assign trace_traces_3_insns_0_cause = system_traceIO_traces_3_insns_0_cause; // @[IOBinders.scala 400:13]
  assign trace_traces_3_insns_0_tval = system_traceIO_traces_3_insns_0_tval; // @[IOBinders.scala 400:13]
  assign trace_traces_2_clock = system_traceIO_traces_2_clock; // @[IOBinders.scala 400:13]
  assign trace_traces_2_reset = system_traceIO_traces_2_reset; // @[IOBinders.scala 400:13]
  assign trace_traces_2_insns_0_valid = system_traceIO_traces_2_insns_0_valid; // @[IOBinders.scala 400:13]
  assign trace_traces_2_insns_0_iaddr = system_traceIO_traces_2_insns_0_iaddr; // @[IOBinders.scala 400:13]
  assign trace_traces_2_insns_0_insn = system_traceIO_traces_2_insns_0_insn; // @[IOBinders.scala 400:13]
  assign trace_traces_2_insns_0_priv = system_traceIO_traces_2_insns_0_priv; // @[IOBinders.scala 400:13]
  assign trace_traces_2_insns_0_exception = system_traceIO_traces_2_insns_0_exception; // @[IOBinders.scala 400:13]
  assign trace_traces_2_insns_0_interrupt = system_traceIO_traces_2_insns_0_interrupt; // @[IOBinders.scala 400:13]
  assign trace_traces_2_insns_0_cause = system_traceIO_traces_2_insns_0_cause; // @[IOBinders.scala 400:13]
  assign trace_traces_2_insns_0_tval = system_traceIO_traces_2_insns_0_tval; // @[IOBinders.scala 400:13]
  assign trace_traces_1_clock = system_traceIO_traces_1_clock; // @[IOBinders.scala 400:13]
  assign trace_traces_1_reset = system_traceIO_traces_1_reset; // @[IOBinders.scala 400:13]
  assign trace_traces_1_insns_0_valid = system_traceIO_traces_1_insns_0_valid; // @[IOBinders.scala 400:13]
  assign trace_traces_1_insns_0_iaddr = system_traceIO_traces_1_insns_0_iaddr; // @[IOBinders.scala 400:13]
  assign trace_traces_1_insns_0_insn = system_traceIO_traces_1_insns_0_insn; // @[IOBinders.scala 400:13]
  assign trace_traces_1_insns_0_priv = system_traceIO_traces_1_insns_0_priv; // @[IOBinders.scala 400:13]
  assign trace_traces_1_insns_0_exception = system_traceIO_traces_1_insns_0_exception; // @[IOBinders.scala 400:13]
  assign trace_traces_1_insns_0_interrupt = system_traceIO_traces_1_insns_0_interrupt; // @[IOBinders.scala 400:13]
  assign trace_traces_1_insns_0_cause = system_traceIO_traces_1_insns_0_cause; // @[IOBinders.scala 400:13]
  assign trace_traces_1_insns_0_tval = system_traceIO_traces_1_insns_0_tval; // @[IOBinders.scala 400:13]
  assign trace_traces_0_clock = system_traceIO_traces_0_clock; // @[IOBinders.scala 400:13]
  assign trace_traces_0_reset = system_traceIO_traces_0_reset; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_0_valid = system_traceIO_traces_0_insns_0_valid; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_0_iaddr = system_traceIO_traces_0_insns_0_iaddr; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_0_insn = system_traceIO_traces_0_insns_0_insn; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_0_wdata = system_traceIO_traces_0_insns_0_wdata; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_0_priv = system_traceIO_traces_0_insns_0_priv; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_0_exception = system_traceIO_traces_0_insns_0_exception; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_0_interrupt = system_traceIO_traces_0_insns_0_interrupt; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_0_cause = system_traceIO_traces_0_insns_0_cause; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_0_tval = system_traceIO_traces_0_insns_0_tval; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_1_valid = system_traceIO_traces_0_insns_1_valid; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_1_iaddr = system_traceIO_traces_0_insns_1_iaddr; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_1_insn = system_traceIO_traces_0_insns_1_insn; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_1_wdata = system_traceIO_traces_0_insns_1_wdata; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_1_priv = system_traceIO_traces_0_insns_1_priv; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_1_exception = system_traceIO_traces_0_insns_1_exception; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_1_interrupt = system_traceIO_traces_0_insns_1_interrupt; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_1_cause = system_traceIO_traces_0_insns_1_cause; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_1_tval = system_traceIO_traces_0_insns_1_tval; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_2_valid = system_traceIO_traces_0_insns_2_valid; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_2_iaddr = system_traceIO_traces_0_insns_2_iaddr; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_2_insn = system_traceIO_traces_0_insns_2_insn; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_2_wdata = system_traceIO_traces_0_insns_2_wdata; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_2_priv = system_traceIO_traces_0_insns_2_priv; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_2_exception = system_traceIO_traces_0_insns_2_exception; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_2_interrupt = system_traceIO_traces_0_insns_2_interrupt; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_2_cause = system_traceIO_traces_0_insns_2_cause; // @[IOBinders.scala 400:13]
  assign trace_traces_0_insns_2_tval = system_traceIO_traces_0_insns_2_tval; // @[IOBinders.scala 400:13]
  assign synthesizedPrintf_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable =
    system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_enable;
  assign synthesizedPrintf_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0 =
    system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0;
  assign synthesizedPrintf_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1 =
    system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1;
  assign synthesizedPrintf_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2 =
    system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2;
  assign synthesizedPrintf_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3 =
    system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3;
  assign synthesizedPrintf_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4 =
    system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4;
  assign synthesizedPrintf_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11 =
    system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11;
  assign synthesizedPrintf_system_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12 =
    system_synthesizedPrintf_tile_prci_domain_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12;
  assign synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable =
    system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_enable;
  assign synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0 =
    system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_0;
  assign synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1 =
    system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_1;
  assign synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2 =
    system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_2;
  assign synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3 =
    system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_wire_args_3;
  assign synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable =
    system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_enable;
  assign synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0 =
    system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_0;
  assign synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1 =
    system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_1;
  assign synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2 =
    system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_2;
  assign synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3 =
    system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_3;
  assign synthesizedPrintf_system_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4 =
    system_synthesizedPrintf_tile_prci_domain_1_tile_reset_domain_tile_core_printf_1_wire_args_4;
  assign synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable =
    system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_enable;
  assign synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0 =
    system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_0;
  assign synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1 =
    system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_1;
  assign synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2 =
    system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_2;
  assign synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3 =
    system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_wire_args_3;
  assign synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable =
    system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_enable;
  assign synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0 =
    system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_0;
  assign synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1 =
    system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_1;
  assign synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2 =
    system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_2;
  assign synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3 =
    system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_3;
  assign synthesizedPrintf_system_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4 =
    system_synthesizedPrintf_tile_prci_domain_2_tile_reset_domain_tile_core_printf_1_wire_args_4;
  assign synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable =
    system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_enable;
  assign synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0 =
    system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_0;
  assign synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1 =
    system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_1;
  assign synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2 =
    system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_2;
  assign synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3 =
    system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_wire_args_3;
  assign synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable =
    system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_enable;
  assign synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0 =
    system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_0;
  assign synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1 =
    system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_1;
  assign synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2 =
    system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_2;
  assign synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3 =
    system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_3;
  assign synthesizedPrintf_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4 =
    system_synthesizedPrintf_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire_args_4;
  assign synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable =
    system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_enable;
  assign synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0 =
    system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_0;
  assign synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1 =
    system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_1;
  assign synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2 =
    system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_2;
  assign synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3 =
    system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_wire_args_3;
  assign synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable =
    system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_enable;
  assign synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0 =
    system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_0;
  assign synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1 =
    system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_1;
  assign synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2 =
    system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_2;
  assign synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3 =
    system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_3;
  assign synthesizedPrintf_system_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4 =
    system_synthesizedPrintf_tile_prci_domain_4_tile_reset_domain_tile_core_printf_1_wire_args_4;
  assign system_clock = system_auto_implicitClockGrouper_out_clock; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign system_reset = system_auto_implicitClockGrouper_out_reset; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_implicit_clock_clock = clocks_clocks_11; // @[Nodes.scala 1212:84 FireSim.scala 201:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_implicit_clock_reset = async_reset; // @[Nodes.scala 1212:84 FireSim.scala 202:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_cbus_0_clock = clocks_clocks_9
    ; // @[Nodes.scala 1212:84 FireSim.scala 201:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_cbus_0_reset = async_reset; // @[Nodes.scala 1212:84 FireSim.scala 202:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_mbus_0_clock = clocks_clocks_8
    ; // @[Nodes.scala 1212:84 FireSim.scala 201:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_mbus_0_reset = async_reset; // @[Nodes.scala 1212:84 FireSim.scala 202:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_fbus_0_clock = clocks_clocks_7
    ; // @[Nodes.scala 1212:84 FireSim.scala 201:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_fbus_0_reset = async_reset; // @[Nodes.scala 1212:84 FireSim.scala 202:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_pbus_0_clock = clocks_clocks_6
    ; // @[Nodes.scala 1212:84 FireSim.scala 201:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_pbus_0_reset = async_reset; // @[Nodes.scala 1212:84 FireSim.scala 202:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_4_clock =
    clocks_clocks_5; // @[Nodes.scala 1212:84 FireSim.scala 201:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_4_reset =
    async_reset; // @[Nodes.scala 1212:84 FireSim.scala 202:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_3_clock =
    clocks_clocks_4; // @[Nodes.scala 1212:84 FireSim.scala 201:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_3_reset =
    async_reset; // @[Nodes.scala 1212:84 FireSim.scala 202:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_2_clock =
    clocks_clocks_3; // @[Nodes.scala 1212:84 FireSim.scala 201:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_2_reset =
    async_reset; // @[Nodes.scala 1212:84 FireSim.scala 202:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_1_clock =
    clocks_clocks_2; // @[Nodes.scala 1212:84 FireSim.scala 201:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_tileClockGroup_tile_1_reset =
    async_reset; // @[Nodes.scala 1212:84 FireSim.scala 202:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_sbus_1_clock = clocks_clocks_1
    ; // @[Nodes.scala 1212:84 FireSim.scala 201:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_sbus_1_reset = async_reset; // @[Nodes.scala 1212:84 FireSim.scala 202:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_sbus_0_clock = clocks_clocks_0
    ; // @[Nodes.scala 1212:84 FireSim.scala 201:27]
  assign system_auto_prci_ctrl_domain_tileResetSetter_clock_in_member_allClocks_subsystem_sbus_0_reset = async_reset; // @[Nodes.scala 1212:84 FireSim.scala 202:27]
  assign system_mem_axi4_0_aw_ready = axi4_mem_0_bits_aw_ready; // @[IOBinders.scala 317:16]
  assign system_mem_axi4_0_w_ready = axi4_mem_0_bits_w_ready; // @[IOBinders.scala 317:16]
  assign system_mem_axi4_0_b_valid = axi4_mem_0_bits_b_valid; // @[IOBinders.scala 317:16]
  assign system_mem_axi4_0_b_bits_id = axi4_mem_0_bits_b_bits_id; // @[IOBinders.scala 317:16]
  assign system_mem_axi4_0_b_bits_resp = axi4_mem_0_bits_b_bits_resp; // @[IOBinders.scala 317:16]
  assign system_mem_axi4_0_ar_ready = axi4_mem_0_bits_ar_ready; // @[IOBinders.scala 317:16]
  assign system_mem_axi4_0_r_valid = axi4_mem_0_bits_r_valid; // @[IOBinders.scala 317:16]
  assign system_mem_axi4_0_r_bits_id = axi4_mem_0_bits_r_bits_id; // @[IOBinders.scala 317:16]
  assign system_mem_axi4_0_r_bits_data = axi4_mem_0_bits_r_bits_data; // @[IOBinders.scala 317:16]
  assign system_mem_axi4_0_r_bits_resp = axi4_mem_0_bits_r_bits_resp; // @[IOBinders.scala 317:16]
  assign system_mem_axi4_0_r_bits_last = axi4_mem_0_bits_r_bits_last; // @[IOBinders.scala 317:16]
  assign system_custom_boot = iocell_custom_boot_io_out; // @[IOCell.scala 224:26]
  assign system_bdev_bits_req_ready = blockdev_bits_req_ready; // @[IOBinders.scala 370:9]
  assign system_bdev_bits_data_ready = blockdev_bits_data_ready; // @[IOBinders.scala 370:9]
  assign system_bdev_bits_resp_valid = blockdev_bits_resp_valid; // @[IOBinders.scala 370:9]
  assign system_bdev_bits_resp_bits_data = blockdev_bits_resp_bits_data; // @[IOBinders.scala 370:9]
  assign system_bdev_bits_resp_bits_tag = blockdev_bits_resp_bits_tag; // @[IOBinders.scala 370:9]
  assign system_bdev_bits_info_nsectors = blockdev_bits_info_nsectors; // @[IOBinders.scala 370:9]
  assign system_bdev_bits_info_max_req_len = blockdev_bits_info_max_req_len; // @[IOBinders.scala 370:9]
  assign system_serial_tl_bits_in_valid = iocell_serial_tl_bits_in_valid_io_out; // @[IOCell.scala 224:26]
  assign system_serial_tl_bits_in_bits = {system_serial_tl_bits_in_bits_hi,system_serial_tl_bits_in_bits_lo}; // @[Cat.scala 33:92]
  assign system_serial_tl_bits_out_ready = iocell_serial_tl_bits_out_ready_io_out; // @[IOCell.scala 224:26]
  assign system_uart_0_rxd = iocell_uart_0_rxd_io_out; // @[IOCell.scala 224:26]
  assign iocell_serial_tl_bits_out_bits_io_out_ready = system_serial_tl_bits_out_bits[0]; // @[IOCell.scala 228:40]
  assign iocell_serial_tl_bits_out_bits_1_io_out_ready = system_serial_tl_bits_out_bits[1]; // @[IOCell.scala 228:40]
  assign iocell_serial_tl_bits_out_bits_2_io_out_ready = system_serial_tl_bits_out_bits[2]; // @[IOCell.scala 228:40]
  assign iocell_serial_tl_bits_out_bits_3_io_out_ready = system_serial_tl_bits_out_bits[3]; // @[IOCell.scala 228:40]
  assign iocell_serial_tl_bits_out_valid_io_out_ready = system_serial_tl_bits_out_valid; // @[IOCell.scala 228:40]
  assign iocell_serial_tl_bits_out_ready_io_in = serial_tl_bits_out_ready; // @[IOCell.scala 213:39]
  assign iocell_serial_tl_bits_in_bits_io_in = serial_tl_bits_in_bits[0]; // @[IOCell.scala 213:39]
  assign iocell_serial_tl_bits_in_bits_1_io_in = serial_tl_bits_in_bits[1]; // @[IOCell.scala 213:39]
  assign iocell_serial_tl_bits_in_bits_2_io_in = serial_tl_bits_in_bits[2]; // @[IOCell.scala 213:39]
  assign iocell_serial_tl_bits_in_bits_3_io_in = serial_tl_bits_in_bits[3]; // @[IOCell.scala 213:39]
  assign iocell_serial_tl_bits_in_valid_io_in = serial_tl_bits_in_valid; // @[IOCell.scala 213:39]
  assign iocell_serial_tl_bits_in_ready_io_out_ready = system_serial_tl_bits_in_ready; // @[IOCell.scala 228:40]
  assign iocell_serial_tl_clock_io_out_ready = system_serial_tl_clock; // @[IOCell.scala 179:44]
  assign iocell_custom_boot_io_in = custom_boot; // @[IOCell.scala 213:39]
  assign iocell_uart_0_rxd_io_in = uart_0_rxd; // @[IOCell.scala 213:39]
  assign iocell_uart_0_txd_io_out_ready = system_uart_0_txd; // @[IOCell.scala 228:40]
endmodule