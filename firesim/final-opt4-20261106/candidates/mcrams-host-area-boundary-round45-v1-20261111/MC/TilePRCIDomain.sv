module TilePRCIDomain(
  output         auto_tile_reset_domain_boom_tile_broadcast_out_0_valid,
  output [39:0]  auto_tile_reset_domain_boom_tile_broadcast_out_0_iaddr,
  output [31:0]  auto_tile_reset_domain_boom_tile_broadcast_out_0_insn,
  output [2:0]   auto_tile_reset_domain_boom_tile_broadcast_out_0_priv,
  output         auto_tile_reset_domain_boom_tile_broadcast_out_0_exception,
  output         auto_tile_reset_domain_boom_tile_broadcast_out_0_interrupt,
  output [63:0]  auto_tile_reset_domain_boom_tile_broadcast_out_0_cause,
  output [39:0]  auto_tile_reset_domain_boom_tile_broadcast_out_0_tval,
  output [63:0]  auto_tile_reset_domain_boom_tile_broadcast_out_0_wdata,
  output         auto_tile_reset_domain_boom_tile_broadcast_out_1_valid,
  output [39:0]  auto_tile_reset_domain_boom_tile_broadcast_out_1_iaddr,
  output [31:0]  auto_tile_reset_domain_boom_tile_broadcast_out_1_insn,
  output [2:0]   auto_tile_reset_domain_boom_tile_broadcast_out_1_priv,
  output         auto_tile_reset_domain_boom_tile_broadcast_out_1_exception,
  output         auto_tile_reset_domain_boom_tile_broadcast_out_1_interrupt,
  output [63:0]  auto_tile_reset_domain_boom_tile_broadcast_out_1_cause,
  output [39:0]  auto_tile_reset_domain_boom_tile_broadcast_out_1_tval,
  output [63:0]  auto_tile_reset_domain_boom_tile_broadcast_out_1_wdata,
  output         auto_tile_reset_domain_boom_tile_broadcast_out_2_valid,
  output [39:0]  auto_tile_reset_domain_boom_tile_broadcast_out_2_iaddr,
  output [31:0]  auto_tile_reset_domain_boom_tile_broadcast_out_2_insn,
  output [2:0]   auto_tile_reset_domain_boom_tile_broadcast_out_2_priv,
  output         auto_tile_reset_domain_boom_tile_broadcast_out_2_exception,
  output         auto_tile_reset_domain_boom_tile_broadcast_out_2_interrupt,
  output [63:0]  auto_tile_reset_domain_boom_tile_broadcast_out_2_cause,
  output [39:0]  auto_tile_reset_domain_boom_tile_broadcast_out_2_tval,
  output [63:0]  auto_tile_reset_domain_boom_tile_broadcast_out_2_wdata,
  input  [139:0] auto_tile_reset_domain_boom_tile_checker_results_sk_in,
  output [159:0] auto_tile_reset_domain_boom_tile_checker_segment_id_sr_out,
  input  [19:0]  auto_tile_reset_domain_boom_tile_global_checker_big_owner_sk_in,
  output [19:0]  auto_tile_reset_domain_boom_tile_checker_big_owner_sr_out,
  input  [4:0]   auto_tile_reset_domain_boom_tile_global_ic_status_sk_in,
  output [4:0]   auto_tile_reset_domain_boom_tile_ic_status_sr_out,
  input  [63:0]  auto_tile_reset_domain_boom_tile_debug_gcounter_sk_in,
  input  [227:0] auto_tile_reset_domain_boom_tile_report_fi_detection_in_sk_in,
  input  [2:0]   auto_tile_reset_domain_boom_tile_bigcore_comp_in_sk_in,
  input  [3:0]   auto_tile_reset_domain_boom_tile_bigcore_hang_in_sk_in,
  output         auto_tile_reset_domain_boom_tile_reset_sr_out,
  output         auto_tile_reset_domain_boom_tile_clock_sr_out,
  output [164:0] auto_tile_reset_domain_boom_tile_producer_seal_sr_out,
  output [31:0]  auto_tile_reset_domain_boom_tile_ght_status_out_sr_out,
  output [31:0]  auto_tile_reset_domain_boom_tile_ght_packet_dest_sr_out,
  output [152:0] auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out,
  output [271:0] auto_tile_reset_domain_boom_tile_ght_packet_out_sr_out,
  input  [4:0]   auto_tile_reset_domain_boom_tile_icsl_na_sk_in,
  input  [4:0]   auto_tile_reset_domain_boom_tile_clear_ic_status_tomain_sk_in,
  output [79:0]  auto_tile_reset_domain_boom_tile_ic_counter_sr_out,
  input  [2:0]   auto_tile_reset_domain_boom_tile_hartid_in,
  input          auto_int_in_clock_xing_in_2_sync_0,
  input          auto_int_in_clock_xing_in_1_sync_0,
  input          auto_int_in_clock_xing_in_0_sync_0,
  input          auto_int_in_clock_xing_in_0_sync_1,
  input          auto_tl_master_clock_xing_out_a_ready,
  output         auto_tl_master_clock_xing_out_a_valid,
  output [2:0]   auto_tl_master_clock_xing_out_a_bits_opcode,
  output [2:0]   auto_tl_master_clock_xing_out_a_bits_param,
  output [3:0]   auto_tl_master_clock_xing_out_a_bits_size,
  output [3:0]   auto_tl_master_clock_xing_out_a_bits_source,
  output [34:0]  auto_tl_master_clock_xing_out_a_bits_address,
  output         auto_tl_master_clock_xing_out_a_bits_user_cache_image_valid,
  output [15:0]  auto_tl_master_clock_xing_out_a_bits_user_cache_image_writer,
  output [31:0]  auto_tl_master_clock_xing_out_a_bits_user_cache_image_generation,
  output [31:0]  auto_tl_master_clock_xing_out_a_bits_user_cache_image_contentSeq,
  output [7:0]   auto_tl_master_clock_xing_out_a_bits_mask,
  output [63:0]  auto_tl_master_clock_xing_out_a_bits_data,
  output         auto_tl_master_clock_xing_out_a_bits_corrupt,
  output         auto_tl_master_clock_xing_out_b_ready,
  input          auto_tl_master_clock_xing_out_b_valid,
  input  [1:0]   auto_tl_master_clock_xing_out_b_bits_param,
  input  [3:0]   auto_tl_master_clock_xing_out_b_bits_source,
  input  [34:0]  auto_tl_master_clock_xing_out_b_bits_address,
  input          auto_tl_master_clock_xing_out_c_ready,
  output         auto_tl_master_clock_xing_out_c_valid,
  output [2:0]   auto_tl_master_clock_xing_out_c_bits_opcode,
  output [2:0]   auto_tl_master_clock_xing_out_c_bits_param,
  output [3:0]   auto_tl_master_clock_xing_out_c_bits_size,
  output [3:0]   auto_tl_master_clock_xing_out_c_bits_source,
  output [34:0]  auto_tl_master_clock_xing_out_c_bits_address,
  output         auto_tl_master_clock_xing_out_c_bits_user_cache_image_valid,
  output [15:0]  auto_tl_master_clock_xing_out_c_bits_user_cache_image_writer,
  output [31:0]  auto_tl_master_clock_xing_out_c_bits_user_cache_image_generation,
  output [31:0]  auto_tl_master_clock_xing_out_c_bits_user_cache_image_contentSeq,
  output [63:0]  auto_tl_master_clock_xing_out_c_bits_data,
  output         auto_tl_master_clock_xing_out_c_bits_corrupt,
  output         auto_tl_master_clock_xing_out_d_ready,
  input          auto_tl_master_clock_xing_out_d_valid,
  input  [2:0]   auto_tl_master_clock_xing_out_d_bits_opcode,
  input  [1:0]   auto_tl_master_clock_xing_out_d_bits_param,
  input  [3:0]   auto_tl_master_clock_xing_out_d_bits_size,
  input  [3:0]   auto_tl_master_clock_xing_out_d_bits_source,
  input  [1:0]   auto_tl_master_clock_xing_out_d_bits_sink,
  input          auto_tl_master_clock_xing_out_d_bits_denied,
  input          auto_tl_master_clock_xing_out_d_bits_user_cache_image_valid,
  input  [15:0]  auto_tl_master_clock_xing_out_d_bits_user_cache_image_writer,
  input  [31:0]  auto_tl_master_clock_xing_out_d_bits_user_cache_image_generation,
  input  [31:0]  auto_tl_master_clock_xing_out_d_bits_user_cache_image_contentSeq,
  input  [63:0]  auto_tl_master_clock_xing_out_d_bits_data,
  input          auto_tl_master_clock_xing_out_d_bits_corrupt,
  input          auto_tl_master_clock_xing_out_e_ready,
  output         auto_tl_master_clock_xing_out_e_valid,
  output [1:0]   auto_tl_master_clock_xing_out_e_bits_sink,
  input          auto_tap_clock_in_clock,
  input          auto_tap_clock_in_reset,
  output         clock,
  output         reset,
  input  [63:0]  gray_6,
  input          io_enq_ready,
  input  [63:0]  gray_2,
  output         io_reply_valid,
  input  [63:0]  gray_13,
  output         barrierFailureSticky,
  input          barrierRequest,
  output         debug_traffic_counting,
  output [703:0] _T_213,
  input  [63:0]  gray_9,
  output         bankAck,
  input  [63:0]  gray_1,
  input          io_deq_valid,
  input  [63:0]  gray_5,
  output [31:0]  barrierFailureSeq,
  input  [63:0]  gray_10,
  output         io_traffic_reset,
  input  [63:0]  gray_14,
  input  [255:0] _T,
  input  [63:0]  dirtyGray,
  input  [63:0]  gray_8,
  output [31:0]  safeWatermarkGray,
  input  [63:0]  gray,
  output [31:0]  _T_248,
  input  [63:0]  gray_4,
  output         clock_0,
  input  [63:0]  gray_15,
  input  [63:0]  gray_11,
  input  [63:0]  cleanGray,
  output         _T_214,
  input  [63:0]  gray_7,
  input  [63:0]  gray_3,
  output         io_request_ready,
  input  [31:0]  barrierRequestSeq,
  input  [63:0]  gray_16,
  input  [63:0]  gray_12,
  output         synthesizedPrintf_tile_reset_domain_boom_tile_core_dac_printf_wire_enable,
  output [63:0]  synthesizedPrintf_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0,
  output [63:0]  synthesizedPrintf_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1,
  output [63:0]  synthesizedPrintf_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2,
  output [63:0]  synthesizedPrintf_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3,
  output [63:0]  synthesizedPrintf_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4,
  output         synthesizedPrintf_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11,
  output [63:0]  synthesizedPrintf_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12,
  output [6:0]   tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_0_MPORT_addr, // @[regfile.scala 117:20]
  input  [63:0]  tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_0_MPORT_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_1_MPORT_addr, // @[regfile.scala 117:20]
  input  [63:0]  tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_1_MPORT_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_2_MPORT_addr, // @[regfile.scala 117:20]
  input  [63:0]  tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_2_MPORT_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_3_MPORT_addr, // @[regfile.scala 117:20]
  input  [63:0]  tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_3_MPORT_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_4_MPORT_addr, // @[regfile.scala 117:20]
  input  [63:0]  tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_4_MPORT_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_5_MPORT_addr, // @[regfile.scala 117:20]
  input  [63:0]  tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_5_MPORT_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_6_MPORT_addr, // @[regfile.scala 117:20]
  input  [63:0]  tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_6_MPORT_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_7_MPORT_addr, // @[regfile.scala 117:20]
  input  [63:0]  tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_7_MPORT_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_8_MPORT_addr, // @[regfile.scala 117:20]
  input  [63:0]  tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_8_MPORT_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_9_MPORT_addr, // @[regfile.scala 117:20]
  input  [63:0]  tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_9_MPORT_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_10_MPORT_addr, // @[regfile.scala 117:20]
  input  [63:0]  tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_10_MPORT_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_addr, // @[regfile.scala 117:20]
  output         tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_en, // @[regfile.scala 117:20]
  output [63:0]  tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_1_addr, // @[regfile.scala 117:20]
  output         tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_1_en, // @[regfile.scala 117:20]
  output [63:0]  tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_1_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_2_addr, // @[regfile.scala 117:20]
  output         tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_2_en, // @[regfile.scala 117:20]
  output [63:0]  tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_2_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_3_addr, // @[regfile.scala 117:20]
  output         tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_3_en, // @[regfile.scala 117:20]
  output [63:0]  tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_3_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_read_data_0_MPORT_addr, // @[regfile.scala 117:20]
  input  [64:0]  tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_read_data_0_MPORT_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_read_data_1_MPORT_addr, // @[regfile.scala 117:20]
  input  [64:0]  tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_read_data_1_MPORT_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_read_data_2_MPORT_addr, // @[regfile.scala 117:20]
  input  [64:0]  tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_read_data_2_MPORT_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_MPORT_addr, // @[regfile.scala 117:20]
  output         tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_MPORT_en, // @[regfile.scala 117:20]
  output [64:0]  tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_MPORT_data, // @[regfile.scala 117:20]
  output [6:0]   tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_MPORT_1_addr, // @[regfile.scala 117:20]
  output         tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_MPORT_1_en, // @[regfile.scala 117:20]
  output [64:0]  tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_MPORT_1_data, // @[regfile.scala 117:20]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_installPreservationAllowed_MPORT_addr, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_installPreservationAllowed_MPORT_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_refillPreservationAllowed_MPORT_addr, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_refillPreservationAllowed_MPORT_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_wb_io_image_key_MPORT_addr, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_wb_io_image_key_MPORT_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageResidentMatch_MPORT_addr, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageResidentMatch_MPORT_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageWbPacketSeq_MPORT_addr, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageWbPacketSeq_MPORT_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_s2_overwrittenKey_MPORT_addr, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_s2_overwrittenKey_MPORT_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_svbCaptureResidentMatch_MPORT_addr, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_svbCaptureResidentMatch_MPORT_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_svbFastKey_MPORT_addr, // @[dcache.scala 727:29]
  output         tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_svbFastKey_MPORT_en, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_svbFastKey_MPORT_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_clearFreezeReadBypassWindow_MPORT_addr, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_clearFreezeReadBypassWindow_MPORT_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_addr, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_1_addr, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_1_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_2_addr, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_2_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageWbReq_valid_MPORT_addr, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageWbReq_valid_MPORT_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_addr, // @[dcache.scala 727:29]
  output         tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_en, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_addr, // @[dcache.scala 727:29]
  output         tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_en, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_4_addr, // @[dcache.scala 727:29]
  output         tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_4_en, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_4_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_5_addr, // @[dcache.scala 727:29]
  output         tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_5_en, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_5_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_6_addr, // @[dcache.scala 727:29]
  output         tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_6_en, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_6_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_7_addr, // @[dcache.scala 727:29]
  output         tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_7_en, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_7_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_8_addr, // @[dcache.scala 727:29]
  output         tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_8_en, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_8_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_9_addr, // @[dcache.scala 727:29]
  output         tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_9_en, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_9_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_10_addr, // @[dcache.scala 727:29]
  output         tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_10_en, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_10_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_s3_l1PreservationAllowed_MPORT_addr, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_s3_l1PreservationAllowed_MPORT_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_12_addr, // @[dcache.scala 727:29]
  output         tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_12_en, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_12_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_13_addr, // @[dcache.scala 727:29]
  output         tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_13_en, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_13_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_14_addr, // @[dcache.scala 727:29]
  output         tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_14_en, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_14_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_15_addr, // @[dcache.scala 727:29]
  output         tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_15_en, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_15_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_16_addr, // @[dcache.scala 727:29]
  output         tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_16_en, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_16_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_slowdown_opt1_pending_live_key_MPORT_addr
    , // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_slowdown_opt1_pending_live_key_MPORT_data
    , // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_slowdown_opt1_pending_safe_MPORT_addr, // @[dcache.scala 727:29]
  input  [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_slowdown_opt1_pending_safe_MPORT_data, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_preservationWaitWatermark_MPORT_addr, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_17_addr, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_18_addr, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_opt2bWriteKey_MPORT_addr, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_safeChainLiveKey_MPORT_addr, // @[dcache.scala 727:29]
  output [8:0]   tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_addr, // @[dcache.scala 727:29]
  output         tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_en, // @[dcache.scala 727:29]
  output [80:0]  tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_data // @[dcache.scala 727:29]
);
  wire  tile_reset_domain__boom_tile__clock; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__reset; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_broadcast_out_1_0_valid; // @[HasTiles.scala 324:53]
  wire [39:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_0_iaddr; // @[HasTiles.scala 324:53]
  wire [31:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_0_insn; // @[HasTiles.scala 324:53]
  wire [2:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_0_priv; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_broadcast_out_1_0_exception; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_broadcast_out_1_0_interrupt; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_0_cause; // @[HasTiles.scala 324:53]
  wire [39:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_0_tval; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_0_wdata; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_broadcast_out_1_1_valid; // @[HasTiles.scala 324:53]
  wire [39:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_1_iaddr; // @[HasTiles.scala 324:53]
  wire [31:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_1_insn; // @[HasTiles.scala 324:53]
  wire [2:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_1_priv; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_broadcast_out_1_1_exception; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_broadcast_out_1_1_interrupt; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_1_cause; // @[HasTiles.scala 324:53]
  wire [39:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_1_tval; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_1_wdata; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_broadcast_out_1_2_valid; // @[HasTiles.scala 324:53]
  wire [39:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_2_iaddr; // @[HasTiles.scala 324:53]
  wire [31:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_2_insn; // @[HasTiles.scala 324:53]
  wire [2:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_2_priv; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_broadcast_out_1_2_exception; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_broadcast_out_1_2_interrupt; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_2_cause; // @[HasTiles.scala 324:53]
  wire [39:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_2_tval; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__auto_broadcast_out_1_2_wdata; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_master_out_a_ready; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_master_out_a_valid; // @[HasTiles.scala 324:53]
  wire [2:0] tile_reset_domain__boom_tile__auto_master_out_a_bits_opcode; // @[HasTiles.scala 324:53]
  wire [2:0] tile_reset_domain__boom_tile__auto_master_out_a_bits_param; // @[HasTiles.scala 324:53]
  wire [3:0] tile_reset_domain__boom_tile__auto_master_out_a_bits_size; // @[HasTiles.scala 324:53]
  wire [3:0] tile_reset_domain__boom_tile__auto_master_out_a_bits_source; // @[HasTiles.scala 324:53]
  wire [34:0] tile_reset_domain__boom_tile__auto_master_out_a_bits_address; // @[HasTiles.scala 324:53]
  wire [7:0] tile_reset_domain__boom_tile__auto_master_out_a_bits_mask; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__auto_master_out_a_bits_data; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_master_out_b_ready; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_master_out_b_valid; // @[HasTiles.scala 324:53]
  wire [1:0] tile_reset_domain__boom_tile__auto_master_out_b_bits_param; // @[HasTiles.scala 324:53]
  wire [3:0] tile_reset_domain__boom_tile__auto_master_out_b_bits_size; // @[HasTiles.scala 324:53]
  wire [3:0] tile_reset_domain__boom_tile__auto_master_out_b_bits_source; // @[HasTiles.scala 324:53]
  wire [34:0] tile_reset_domain__boom_tile__auto_master_out_b_bits_address; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_master_out_c_ready; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_master_out_c_valid; // @[HasTiles.scala 324:53]
  wire [2:0] tile_reset_domain__boom_tile__auto_master_out_c_bits_opcode; // @[HasTiles.scala 324:53]
  wire [2:0] tile_reset_domain__boom_tile__auto_master_out_c_bits_param; // @[HasTiles.scala 324:53]
  wire [3:0] tile_reset_domain__boom_tile__auto_master_out_c_bits_size; // @[HasTiles.scala 324:53]
  wire [3:0] tile_reset_domain__boom_tile__auto_master_out_c_bits_source; // @[HasTiles.scala 324:53]
  wire [34:0] tile_reset_domain__boom_tile__auto_master_out_c_bits_address; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_master_out_c_bits_user_cache_image_valid; // @[HasTiles.scala 324:53]
  wire [15:0] tile_reset_domain__boom_tile__auto_master_out_c_bits_user_cache_image_writer; // @[HasTiles.scala 324:53]
  wire [31:0] tile_reset_domain__boom_tile__auto_master_out_c_bits_user_cache_image_generation; // @[HasTiles.scala 324:53]
  wire [31:0] tile_reset_domain__boom_tile__auto_master_out_c_bits_user_cache_image_contentSeq; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__auto_master_out_c_bits_data; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_master_out_d_ready; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_master_out_d_valid; // @[HasTiles.scala 324:53]
  wire [2:0] tile_reset_domain__boom_tile__auto_master_out_d_bits_opcode; // @[HasTiles.scala 324:53]
  wire [1:0] tile_reset_domain__boom_tile__auto_master_out_d_bits_param; // @[HasTiles.scala 324:53]
  wire [3:0] tile_reset_domain__boom_tile__auto_master_out_d_bits_size; // @[HasTiles.scala 324:53]
  wire [3:0] tile_reset_domain__boom_tile__auto_master_out_d_bits_source; // @[HasTiles.scala 324:53]
  wire [1:0] tile_reset_domain__boom_tile__auto_master_out_d_bits_sink; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_master_out_d_bits_denied; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_master_out_d_bits_user_cache_image_valid; // @[HasTiles.scala 324:53]
  wire [15:0] tile_reset_domain__boom_tile__auto_master_out_d_bits_user_cache_image_writer; // @[HasTiles.scala 324:53]
  wire [31:0] tile_reset_domain__boom_tile__auto_master_out_d_bits_user_cache_image_generation; // @[HasTiles.scala 324:53]
  wire [31:0] tile_reset_domain__boom_tile__auto_master_out_d_bits_user_cache_image_contentSeq; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__auto_master_out_d_bits_data; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_master_out_d_bits_corrupt; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_master_out_e_ready; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_master_out_e_valid; // @[HasTiles.scala 324:53]
  wire [1:0] tile_reset_domain__boom_tile__auto_master_out_e_bits_sink; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_int_local_in_3_0; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_int_local_in_2_0; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_int_local_in_1_0; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_int_local_in_1_1; // @[HasTiles.scala 324:53]
  wire [139:0] tile_reset_domain__boom_tile__auto_checker_results_sk_in; // @[HasTiles.scala 324:53]
  wire [159:0] tile_reset_domain__boom_tile__auto_checker_segment_id_sr_out; // @[HasTiles.scala 324:53]
  wire [19:0] tile_reset_domain__boom_tile__auto_global_checker_big_owner_sk_in; // @[HasTiles.scala 324:53]
  wire [19:0] tile_reset_domain__boom_tile__auto_checker_big_owner_sr_out; // @[HasTiles.scala 324:53]
  wire [4:0] tile_reset_domain__boom_tile__auto_global_ic_status_sk_in; // @[HasTiles.scala 324:53]
  wire [4:0] tile_reset_domain__boom_tile__auto_ic_status_sr_out; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__auto_debug_gcounter_sk_in; // @[HasTiles.scala 324:53]
  wire [227:0] tile_reset_domain__boom_tile__auto_report_fi_detection_in_sk_in; // @[HasTiles.scala 324:53]
  wire [2:0] tile_reset_domain__boom_tile__auto_bigcore_comp_in_sk_in; // @[HasTiles.scala 324:53]
  wire [3:0] tile_reset_domain__boom_tile__auto_bigcore_hang_in_sk_in; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_reset_sr_out; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__auto_clock_sr_out; // @[HasTiles.scala 324:53]
  wire [164:0] tile_reset_domain__boom_tile__auto_producer_seal_sr_out; // @[HasTiles.scala 324:53]
  wire [31:0] tile_reset_domain__boom_tile__auto_ght_status_out_sr_out; // @[HasTiles.scala 324:53]
  wire [31:0] tile_reset_domain__boom_tile__auto_ght_packet_dest_sr_out; // @[HasTiles.scala 324:53]
  wire [152:0] tile_reset_domain__boom_tile__auto_core_r_arfs_sr_out; // @[HasTiles.scala 324:53]
  wire [271:0] tile_reset_domain__boom_tile__auto_ght_packet_out_sr_out; // @[HasTiles.scala 324:53]
  wire [4:0] tile_reset_domain__boom_tile__auto_icsl_na_sk_in; // @[HasTiles.scala 324:53]
  wire [4:0] tile_reset_domain__boom_tile__auto_clear_ic_status_tomain_sk_in; // @[HasTiles.scala 324:53]
  wire [79:0] tile_reset_domain__boom_tile__auto_ic_counter_sr_out; // @[HasTiles.scala 324:53]
  wire [2:0] tile_reset_domain__boom_tile__auto_hartid_in; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_6_0; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__io_enq_ready; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_2_0; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__io_reply_valid; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_3_0; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__barrierFailureSticky; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__barrierRequest; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__debug_traffic_counting; // @[HasTiles.scala 324:53]
  wire [703:0] tile_reset_domain__boom_tile___T_213; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_9_0; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__bankAck; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_1_0; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__io_deq_valid; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_5_0; // @[HasTiles.scala 324:53]
  wire [31:0] tile_reset_domain__boom_tile__barrierFailureSeq; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_0_0; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__io_traffic_reset; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_4_0; // @[HasTiles.scala 324:53]
  wire [255:0] tile_reset_domain__boom_tile___T_0; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_wb_dirty_gray_0; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_8_0; // @[HasTiles.scala 324:53]
  wire [31:0] tile_reset_domain__boom_tile__safeWatermarkGray; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_0_0; // @[HasTiles.scala 324:53]
  wire [31:0] tile_reset_domain__boom_tile___T_248; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_4_0; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__clock_0; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_5_0; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_1_0; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_wb_clean_gray_0; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile___T_214; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_7_0; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_3_0; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__io_request_ready; // @[HasTiles.scala 324:53]
  wire [31:0] tile_reset_domain__boom_tile__barrierRequestSeq; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_6_0; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_2_0; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_enable; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_0; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_1; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_2; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_3; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_4; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_11; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_12; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_0_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_0_MPORT_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_1_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_1_MPORT_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_2_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_2_MPORT_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_3_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_3_MPORT_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_4_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_4_MPORT_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_5_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_5_MPORT_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_6_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_6_MPORT_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_7_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_7_MPORT_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_8_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_8_MPORT_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_9_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_9_MPORT_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_10_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_10_MPORT_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_en; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_1_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_1_en; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_1_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_2_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_2_en; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_2_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_3_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_3_en; // @[HasTiles.scala 324:53]
  wire [63:0] tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_3_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_0_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [64:0] tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_0_MPORT_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_1_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [64:0] tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_1_MPORT_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_2_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [64:0] tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_2_MPORT_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_en; // @[HasTiles.scala 324:53]
  wire [64:0] tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_data; // @[HasTiles.scala 324:53]
  wire [6:0] tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_1_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_1_en; // @[HasTiles.scala 324:53]
  wire [64:0] tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_1_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_installPreservationAllowed_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_installPreservationAllowed_MPORT_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_refillPreservationAllowed_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_refillPreservationAllowed_MPORT_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_wb_io_image_key_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_wb_io_image_key_MPORT_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageResidentMatch_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageResidentMatch_MPORT_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageWbPacketSeq_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageWbPacketSeq_MPORT_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_s2_overwrittenKey_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_s2_overwrittenKey_MPORT_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_svbCaptureResidentMatch_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_svbCaptureResidentMatch_MPORT_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_svbFastKey_MPORT_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_svbFastKey_MPORT_en; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_svbFastKey_MPORT_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_clearFreezeReadBypassWindow_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_clearFreezeReadBypassWindow_MPORT_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_1_addr; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_1_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_2_addr; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_2_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageWbReq_valid_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageWbReq_valid_MPORT_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_en; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_en; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_4_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_4_en; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_4_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_5_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_5_en; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_5_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_6_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_6_en; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_6_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_7_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_7_en; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_7_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_8_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_8_en; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_8_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_9_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_9_en; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_9_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_10_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_10_en; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_10_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_s3_l1PreservationAllowed_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_s3_l1PreservationAllowed_MPORT_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_12_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_12_en; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_12_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_13_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_13_en; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_13_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_14_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_14_en; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_14_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_15_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_15_en; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_15_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_16_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_16_en; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_16_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_slowdown_opt1_pending_live_key_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_slowdown_opt1_pending_live_key_MPORT_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_slowdown_opt1_pending_safe_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_slowdown_opt1_pending_safe_MPORT_data; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_preservationWaitWatermark_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_17_addr; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_18_addr; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_opt2bWriteKey_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_safeChainLiveKey_MPORT_addr; // @[HasTiles.scala 324:53]
  wire [8:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_addr; // @[HasTiles.scala 324:53]
  wire  tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_en; // @[HasTiles.scala 324:53]
  wire [80:0] tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_data; // @[HasTiles.scala 324:53]
  wire  buffer_1_clock; // @[Buffer.scala 69:28]
  wire  buffer_1_reset; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_in_a_ready; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_in_a_valid; // @[Buffer.scala 69:28]
  wire [2:0] buffer_1_auto_in_a_bits_opcode; // @[Buffer.scala 69:28]
  wire [2:0] buffer_1_auto_in_a_bits_param; // @[Buffer.scala 69:28]
  wire [3:0] buffer_1_auto_in_a_bits_size; // @[Buffer.scala 69:28]
  wire [3:0] buffer_1_auto_in_a_bits_source; // @[Buffer.scala 69:28]
  wire [34:0] buffer_1_auto_in_a_bits_address; // @[Buffer.scala 69:28]
  wire [7:0] buffer_1_auto_in_a_bits_mask; // @[Buffer.scala 69:28]
  wire [63:0] buffer_1_auto_in_a_bits_data; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_in_b_ready; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_in_b_valid; // @[Buffer.scala 69:28]
  wire [1:0] buffer_1_auto_in_b_bits_param; // @[Buffer.scala 69:28]
  wire [3:0] buffer_1_auto_in_b_bits_size; // @[Buffer.scala 69:28]
  wire [3:0] buffer_1_auto_in_b_bits_source; // @[Buffer.scala 69:28]
  wire [34:0] buffer_1_auto_in_b_bits_address; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_in_c_ready; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_in_c_valid; // @[Buffer.scala 69:28]
  wire [2:0] buffer_1_auto_in_c_bits_opcode; // @[Buffer.scala 69:28]
  wire [2:0] buffer_1_auto_in_c_bits_param; // @[Buffer.scala 69:28]
  wire [3:0] buffer_1_auto_in_c_bits_size; // @[Buffer.scala 69:28]
  wire [3:0] buffer_1_auto_in_c_bits_source; // @[Buffer.scala 69:28]
  wire [34:0] buffer_1_auto_in_c_bits_address; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_in_c_bits_user_cache_image_valid; // @[Buffer.scala 69:28]
  wire [15:0] buffer_1_auto_in_c_bits_user_cache_image_writer; // @[Buffer.scala 69:28]
  wire [31:0] buffer_1_auto_in_c_bits_user_cache_image_generation; // @[Buffer.scala 69:28]
  wire [31:0] buffer_1_auto_in_c_bits_user_cache_image_contentSeq; // @[Buffer.scala 69:28]
  wire [63:0] buffer_1_auto_in_c_bits_data; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_in_d_ready; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_in_d_valid; // @[Buffer.scala 69:28]
  wire [2:0] buffer_1_auto_in_d_bits_opcode; // @[Buffer.scala 69:28]
  wire [1:0] buffer_1_auto_in_d_bits_param; // @[Buffer.scala 69:28]
  wire [3:0] buffer_1_auto_in_d_bits_size; // @[Buffer.scala 69:28]
  wire [3:0] buffer_1_auto_in_d_bits_source; // @[Buffer.scala 69:28]
  wire [1:0] buffer_1_auto_in_d_bits_sink; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_in_d_bits_denied; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_in_d_bits_user_cache_image_valid; // @[Buffer.scala 69:28]
  wire [15:0] buffer_1_auto_in_d_bits_user_cache_image_writer; // @[Buffer.scala 69:28]
  wire [31:0] buffer_1_auto_in_d_bits_user_cache_image_generation; // @[Buffer.scala 69:28]
  wire [31:0] buffer_1_auto_in_d_bits_user_cache_image_contentSeq; // @[Buffer.scala 69:28]
  wire [63:0] buffer_1_auto_in_d_bits_data; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_in_d_bits_corrupt; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_in_e_ready; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_in_e_valid; // @[Buffer.scala 69:28]
  wire [1:0] buffer_1_auto_in_e_bits_sink; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_out_a_ready; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_out_a_valid; // @[Buffer.scala 69:28]
  wire [2:0] buffer_1_auto_out_a_bits_opcode; // @[Buffer.scala 69:28]
  wire [2:0] buffer_1_auto_out_a_bits_param; // @[Buffer.scala 69:28]
  wire [3:0] buffer_1_auto_out_a_bits_size; // @[Buffer.scala 69:28]
  wire [3:0] buffer_1_auto_out_a_bits_source; // @[Buffer.scala 69:28]
  wire [34:0] buffer_1_auto_out_a_bits_address; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_out_a_bits_user_cache_image_valid; // @[Buffer.scala 69:28]
  wire [15:0] buffer_1_auto_out_a_bits_user_cache_image_writer; // @[Buffer.scala 69:28]
  wire [31:0] buffer_1_auto_out_a_bits_user_cache_image_generation; // @[Buffer.scala 69:28]
  wire [31:0] buffer_1_auto_out_a_bits_user_cache_image_contentSeq; // @[Buffer.scala 69:28]
  wire [7:0] buffer_1_auto_out_a_bits_mask; // @[Buffer.scala 69:28]
  wire [63:0] buffer_1_auto_out_a_bits_data; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_out_a_bits_corrupt; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_out_b_ready; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_out_b_valid; // @[Buffer.scala 69:28]
  wire [1:0] buffer_1_auto_out_b_bits_param; // @[Buffer.scala 69:28]
  wire [3:0] buffer_1_auto_out_b_bits_source; // @[Buffer.scala 69:28]
  wire [34:0] buffer_1_auto_out_b_bits_address; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_out_c_ready; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_out_c_valid; // @[Buffer.scala 69:28]
  wire [2:0] buffer_1_auto_out_c_bits_opcode; // @[Buffer.scala 69:28]
  wire [2:0] buffer_1_auto_out_c_bits_param; // @[Buffer.scala 69:28]
  wire [3:0] buffer_1_auto_out_c_bits_size; // @[Buffer.scala 69:28]
  wire [3:0] buffer_1_auto_out_c_bits_source; // @[Buffer.scala 69:28]
  wire [34:0] buffer_1_auto_out_c_bits_address; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_out_c_bits_user_cache_image_valid; // @[Buffer.scala 69:28]
  wire [15:0] buffer_1_auto_out_c_bits_user_cache_image_writer; // @[Buffer.scala 69:28]
  wire [31:0] buffer_1_auto_out_c_bits_user_cache_image_generation; // @[Buffer.scala 69:28]
  wire [31:0] buffer_1_auto_out_c_bits_user_cache_image_contentSeq; // @[Buffer.scala 69:28]
  wire [63:0] buffer_1_auto_out_c_bits_data; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_out_c_bits_corrupt; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_out_d_ready; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_out_d_valid; // @[Buffer.scala 69:28]
  wire [2:0] buffer_1_auto_out_d_bits_opcode; // @[Buffer.scala 69:28]
  wire [1:0] buffer_1_auto_out_d_bits_param; // @[Buffer.scala 69:28]
  wire [3:0] buffer_1_auto_out_d_bits_size; // @[Buffer.scala 69:28]
  wire [3:0] buffer_1_auto_out_d_bits_source; // @[Buffer.scala 69:28]
  wire [1:0] buffer_1_auto_out_d_bits_sink; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_out_d_bits_denied; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_out_d_bits_user_cache_image_valid; // @[Buffer.scala 69:28]
  wire [15:0] buffer_1_auto_out_d_bits_user_cache_image_writer; // @[Buffer.scala 69:28]
  wire [31:0] buffer_1_auto_out_d_bits_user_cache_image_generation; // @[Buffer.scala 69:28]
  wire [31:0] buffer_1_auto_out_d_bits_user_cache_image_contentSeq; // @[Buffer.scala 69:28]
  wire [63:0] buffer_1_auto_out_d_bits_data; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_out_d_bits_corrupt; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_out_e_ready; // @[Buffer.scala 69:28]
  wire  buffer_1_auto_out_e_valid; // @[Buffer.scala 69:28]
  wire [1:0] buffer_1_auto_out_e_bits_sink; // @[Buffer.scala 69:28]
  wire  intsink_1_auto_in_sync_0; // @[Crossing.scala 99:29]
  wire  intsink_1_auto_in_sync_1; // @[Crossing.scala 99:29]
  wire  intsink_1_auto_out_0; // @[Crossing.scala 99:29]
  wire  intsink_1_auto_out_1; // @[Crossing.scala 99:29]
  wire  intsink_2_io_in; // @[Crossing.scala 99:29]
  wire  intsink_2_io_out; // @[Crossing.scala 99:29]
  wire  intsink_3_io_in; // @[Crossing.scala 99:29]
  wire  intsink_3_io_out; // @[Crossing.scala 99:29]
  BoomTile tile_reset_domain__boom_tile_ ( // @[HasTiles.scala 324:53]
    .clock(tile_reset_domain__boom_tile__clock),
    .reset(tile_reset_domain__boom_tile__reset),
    .auto_broadcast_out_1_0_valid(tile_reset_domain__boom_tile__auto_broadcast_out_1_0_valid),
    .auto_broadcast_out_1_0_iaddr(tile_reset_domain__boom_tile__auto_broadcast_out_1_0_iaddr),
    .auto_broadcast_out_1_0_insn(tile_reset_domain__boom_tile__auto_broadcast_out_1_0_insn),
    .auto_broadcast_out_1_0_priv(tile_reset_domain__boom_tile__auto_broadcast_out_1_0_priv),
    .auto_broadcast_out_1_0_exception(tile_reset_domain__boom_tile__auto_broadcast_out_1_0_exception),
    .auto_broadcast_out_1_0_interrupt(tile_reset_domain__boom_tile__auto_broadcast_out_1_0_interrupt),
    .auto_broadcast_out_1_0_cause(tile_reset_domain__boom_tile__auto_broadcast_out_1_0_cause),
    .auto_broadcast_out_1_0_tval(tile_reset_domain__boom_tile__auto_broadcast_out_1_0_tval),
    .auto_broadcast_out_1_0_wdata(tile_reset_domain__boom_tile__auto_broadcast_out_1_0_wdata),
    .auto_broadcast_out_1_1_valid(tile_reset_domain__boom_tile__auto_broadcast_out_1_1_valid),
    .auto_broadcast_out_1_1_iaddr(tile_reset_domain__boom_tile__auto_broadcast_out_1_1_iaddr),
    .auto_broadcast_out_1_1_insn(tile_reset_domain__boom_tile__auto_broadcast_out_1_1_insn),
    .auto_broadcast_out_1_1_priv(tile_reset_domain__boom_tile__auto_broadcast_out_1_1_priv),
    .auto_broadcast_out_1_1_exception(tile_reset_domain__boom_tile__auto_broadcast_out_1_1_exception),
    .auto_broadcast_out_1_1_interrupt(tile_reset_domain__boom_tile__auto_broadcast_out_1_1_interrupt),
    .auto_broadcast_out_1_1_cause(tile_reset_domain__boom_tile__auto_broadcast_out_1_1_cause),
    .auto_broadcast_out_1_1_tval(tile_reset_domain__boom_tile__auto_broadcast_out_1_1_tval),
    .auto_broadcast_out_1_1_wdata(tile_reset_domain__boom_tile__auto_broadcast_out_1_1_wdata),
    .auto_broadcast_out_1_2_valid(tile_reset_domain__boom_tile__auto_broadcast_out_1_2_valid),
    .auto_broadcast_out_1_2_iaddr(tile_reset_domain__boom_tile__auto_broadcast_out_1_2_iaddr),
    .auto_broadcast_out_1_2_insn(tile_reset_domain__boom_tile__auto_broadcast_out_1_2_insn),
    .auto_broadcast_out_1_2_priv(tile_reset_domain__boom_tile__auto_broadcast_out_1_2_priv),
    .auto_broadcast_out_1_2_exception(tile_reset_domain__boom_tile__auto_broadcast_out_1_2_exception),
    .auto_broadcast_out_1_2_interrupt(tile_reset_domain__boom_tile__auto_broadcast_out_1_2_interrupt),
    .auto_broadcast_out_1_2_cause(tile_reset_domain__boom_tile__auto_broadcast_out_1_2_cause),
    .auto_broadcast_out_1_2_tval(tile_reset_domain__boom_tile__auto_broadcast_out_1_2_tval),
    .auto_broadcast_out_1_2_wdata(tile_reset_domain__boom_tile__auto_broadcast_out_1_2_wdata),
    .auto_master_out_a_ready(tile_reset_domain__boom_tile__auto_master_out_a_ready),
    .auto_master_out_a_valid(tile_reset_domain__boom_tile__auto_master_out_a_valid),
    .auto_master_out_a_bits_opcode(tile_reset_domain__boom_tile__auto_master_out_a_bits_opcode),
    .auto_master_out_a_bits_param(tile_reset_domain__boom_tile__auto_master_out_a_bits_param),
    .auto_master_out_a_bits_size(tile_reset_domain__boom_tile__auto_master_out_a_bits_size),
    .auto_master_out_a_bits_source(tile_reset_domain__boom_tile__auto_master_out_a_bits_source),
    .auto_master_out_a_bits_address(tile_reset_domain__boom_tile__auto_master_out_a_bits_address),
    .auto_master_out_a_bits_mask(tile_reset_domain__boom_tile__auto_master_out_a_bits_mask),
    .auto_master_out_a_bits_data(tile_reset_domain__boom_tile__auto_master_out_a_bits_data),
    .auto_master_out_b_ready(tile_reset_domain__boom_tile__auto_master_out_b_ready),
    .auto_master_out_b_valid(tile_reset_domain__boom_tile__auto_master_out_b_valid),
    .auto_master_out_b_bits_param(tile_reset_domain__boom_tile__auto_master_out_b_bits_param),
    .auto_master_out_b_bits_size(tile_reset_domain__boom_tile__auto_master_out_b_bits_size),
    .auto_master_out_b_bits_source(tile_reset_domain__boom_tile__auto_master_out_b_bits_source),
    .auto_master_out_b_bits_address(tile_reset_domain__boom_tile__auto_master_out_b_bits_address),
    .auto_master_out_c_ready(tile_reset_domain__boom_tile__auto_master_out_c_ready),
    .auto_master_out_c_valid(tile_reset_domain__boom_tile__auto_master_out_c_valid),
    .auto_master_out_c_bits_opcode(tile_reset_domain__boom_tile__auto_master_out_c_bits_opcode),
    .auto_master_out_c_bits_param(tile_reset_domain__boom_tile__auto_master_out_c_bits_param),
    .auto_master_out_c_bits_size(tile_reset_domain__boom_tile__auto_master_out_c_bits_size),
    .auto_master_out_c_bits_source(tile_reset_domain__boom_tile__auto_master_out_c_bits_source),
    .auto_master_out_c_bits_address(tile_reset_domain__boom_tile__auto_master_out_c_bits_address),
    .auto_master_out_c_bits_user_cache_image_valid(
      tile_reset_domain__boom_tile__auto_master_out_c_bits_user_cache_image_valid),
    .auto_master_out_c_bits_user_cache_image_writer(
      tile_reset_domain__boom_tile__auto_master_out_c_bits_user_cache_image_writer),
    .auto_master_out_c_bits_user_cache_image_generation(
      tile_reset_domain__boom_tile__auto_master_out_c_bits_user_cache_image_generation),
    .auto_master_out_c_bits_user_cache_image_contentSeq(
      tile_reset_domain__boom_tile__auto_master_out_c_bits_user_cache_image_contentSeq),
    .auto_master_out_c_bits_data(tile_reset_domain__boom_tile__auto_master_out_c_bits_data),
    .auto_master_out_d_ready(tile_reset_domain__boom_tile__auto_master_out_d_ready),
    .auto_master_out_d_valid(tile_reset_domain__boom_tile__auto_master_out_d_valid),
    .auto_master_out_d_bits_opcode(tile_reset_domain__boom_tile__auto_master_out_d_bits_opcode),
    .auto_master_out_d_bits_param(tile_reset_domain__boom_tile__auto_master_out_d_bits_param),
    .auto_master_out_d_bits_size(tile_reset_domain__boom_tile__auto_master_out_d_bits_size),
    .auto_master_out_d_bits_source(tile_reset_domain__boom_tile__auto_master_out_d_bits_source),
    .auto_master_out_d_bits_sink(tile_reset_domain__boom_tile__auto_master_out_d_bits_sink),
    .auto_master_out_d_bits_denied(tile_reset_domain__boom_tile__auto_master_out_d_bits_denied),
    .auto_master_out_d_bits_user_cache_image_valid(
      tile_reset_domain__boom_tile__auto_master_out_d_bits_user_cache_image_valid),
    .auto_master_out_d_bits_user_cache_image_writer(
      tile_reset_domain__boom_tile__auto_master_out_d_bits_user_cache_image_writer),
    .auto_master_out_d_bits_user_cache_image_generation(
      tile_reset_domain__boom_tile__auto_master_out_d_bits_user_cache_image_generation),
    .auto_master_out_d_bits_user_cache_image_contentSeq(
      tile_reset_domain__boom_tile__auto_master_out_d_bits_user_cache_image_contentSeq),
    .auto_master_out_d_bits_data(tile_reset_domain__boom_tile__auto_master_out_d_bits_data),
    .auto_master_out_d_bits_corrupt(tile_reset_domain__boom_tile__auto_master_out_d_bits_corrupt),
    .auto_master_out_e_ready(tile_reset_domain__boom_tile__auto_master_out_e_ready),
    .auto_master_out_e_valid(tile_reset_domain__boom_tile__auto_master_out_e_valid),
    .auto_master_out_e_bits_sink(tile_reset_domain__boom_tile__auto_master_out_e_bits_sink),
    .auto_int_local_in_3_0(tile_reset_domain__boom_tile__auto_int_local_in_3_0),
    .auto_int_local_in_2_0(tile_reset_domain__boom_tile__auto_int_local_in_2_0),
    .auto_int_local_in_1_0(tile_reset_domain__boom_tile__auto_int_local_in_1_0),
    .auto_int_local_in_1_1(tile_reset_domain__boom_tile__auto_int_local_in_1_1),
    .auto_checker_results_sk_in(tile_reset_domain__boom_tile__auto_checker_results_sk_in),
    .auto_checker_segment_id_sr_out(tile_reset_domain__boom_tile__auto_checker_segment_id_sr_out),
    .auto_global_checker_big_owner_sk_in(tile_reset_domain__boom_tile__auto_global_checker_big_owner_sk_in),
    .auto_checker_big_owner_sr_out(tile_reset_domain__boom_tile__auto_checker_big_owner_sr_out),
    .auto_global_ic_status_sk_in(tile_reset_domain__boom_tile__auto_global_ic_status_sk_in),
    .auto_ic_status_sr_out(tile_reset_domain__boom_tile__auto_ic_status_sr_out),
    .auto_debug_gcounter_sk_in(tile_reset_domain__boom_tile__auto_debug_gcounter_sk_in),
    .auto_report_fi_detection_in_sk_in(tile_reset_domain__boom_tile__auto_report_fi_detection_in_sk_in),
    .auto_bigcore_comp_in_sk_in(tile_reset_domain__boom_tile__auto_bigcore_comp_in_sk_in),
    .auto_bigcore_hang_in_sk_in(tile_reset_domain__boom_tile__auto_bigcore_hang_in_sk_in),
    .auto_reset_sr_out(tile_reset_domain__boom_tile__auto_reset_sr_out),
    .auto_clock_sr_out(tile_reset_domain__boom_tile__auto_clock_sr_out),
    .auto_producer_seal_sr_out(tile_reset_domain__boom_tile__auto_producer_seal_sr_out),
    .auto_ght_status_out_sr_out(tile_reset_domain__boom_tile__auto_ght_status_out_sr_out),
    .auto_ght_packet_dest_sr_out(tile_reset_domain__boom_tile__auto_ght_packet_dest_sr_out),
    .auto_core_r_arfs_sr_out(tile_reset_domain__boom_tile__auto_core_r_arfs_sr_out),
    .auto_ght_packet_out_sr_out(tile_reset_domain__boom_tile__auto_ght_packet_out_sr_out),
    .auto_icsl_na_sk_in(tile_reset_domain__boom_tile__auto_icsl_na_sk_in),
    .auto_clear_ic_status_tomain_sk_in(tile_reset_domain__boom_tile__auto_clear_ic_status_tomain_sk_in),
    .auto_ic_counter_sr_out(tile_reset_domain__boom_tile__auto_ic_counter_sr_out),
    .auto_hartid_in(tile_reset_domain__boom_tile__auto_hartid_in),
    .gh_l2_dram_dirty_stats_6_0(tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_6_0),
    .io_enq_ready(tile_reset_domain__boom_tile__io_enq_ready),
    .gh_l2_dram_dirty_stats_2_0(tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_2_0),
    .io_reply_valid(tile_reset_domain__boom_tile__io_reply_valid),
    .gh_l2_dram_barrier_stats_3_0(tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_3_0),
    .barrierFailureSticky(tile_reset_domain__boom_tile__barrierFailureSticky),
    .barrierRequest(tile_reset_domain__boom_tile__barrierRequest),
    .debug_traffic_counting(tile_reset_domain__boom_tile__debug_traffic_counting),
    ._T_213(tile_reset_domain__boom_tile___T_213),
    .gh_l2_dram_dirty_stats_9_0(tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_9_0),
    .bankAck(tile_reset_domain__boom_tile__bankAck),
    .gh_l2_dram_dirty_stats_1_0(tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_1_0),
    .io_deq_valid(tile_reset_domain__boom_tile__io_deq_valid),
    .gh_l2_dram_dirty_stats_5_0(tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_5_0),
    .barrierFailureSeq(tile_reset_domain__boom_tile__barrierFailureSeq),
    .gh_l2_dram_barrier_stats_0_0(tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_0_0),
    .io_traffic_reset(tile_reset_domain__boom_tile__io_traffic_reset),
    .gh_l2_dram_barrier_stats_4_0(tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_4_0),
    ._T_0(tile_reset_domain__boom_tile___T_0),
    .gh_l2_dram_wb_dirty_gray_0(tile_reset_domain__boom_tile__gh_l2_dram_wb_dirty_gray_0),
    .gh_l2_dram_dirty_stats_8_0(tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_8_0),
    .safeWatermarkGray(tile_reset_domain__boom_tile__safeWatermarkGray),
    .gh_l2_dram_dirty_stats_0_0(tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_0_0),
    ._T_248(tile_reset_domain__boom_tile___T_248),
    .gh_l2_dram_dirty_stats_4_0(tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_4_0),
    .clock_0(tile_reset_domain__boom_tile__clock_0),
    .gh_l2_dram_barrier_stats_5_0(tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_5_0),
    .gh_l2_dram_barrier_stats_1_0(tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_1_0),
    .gh_l2_dram_wb_clean_gray_0(tile_reset_domain__boom_tile__gh_l2_dram_wb_clean_gray_0),
    ._T_214(tile_reset_domain__boom_tile___T_214),
    .gh_l2_dram_dirty_stats_7_0(tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_7_0),
    .gh_l2_dram_dirty_stats_3_0(tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_3_0),
    .io_request_ready(tile_reset_domain__boom_tile__io_request_ready),
    .barrierRequestSeq(tile_reset_domain__boom_tile__barrierRequestSeq),
    .gh_l2_dram_barrier_stats_6_0(tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_6_0),
    .gh_l2_dram_barrier_stats_2_0(tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_2_0),
    .synthesizedPrintf_core_dac_printf_wire_enable(
      tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_enable),
    .synthesizedPrintf_core_dac_printf_wire_args_0(
      tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_0),
    .synthesizedPrintf_core_dac_printf_wire_args_1(
      tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_1),
    .synthesizedPrintf_core_dac_printf_wire_args_2(
      tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_2),
    .synthesizedPrintf_core_dac_printf_wire_args_3(
      tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_3),
    .synthesizedPrintf_core_dac_printf_wire_args_4(
      tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_4),
    .synthesizedPrintf_core_dac_printf_wire_args_11(
      tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_11),
    .synthesizedPrintf_core_dac_printf_wire_args_12(
      tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_12),
    .core_iregfile_regfile_read_data_0_MPORT_addr(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_0_MPORT_addr),
    .core_iregfile_regfile_read_data_0_MPORT_data(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_0_MPORT_data),
    .core_iregfile_regfile_read_data_1_MPORT_addr(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_1_MPORT_addr),
    .core_iregfile_regfile_read_data_1_MPORT_data(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_1_MPORT_data),
    .core_iregfile_regfile_read_data_2_MPORT_addr(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_2_MPORT_addr),
    .core_iregfile_regfile_read_data_2_MPORT_data(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_2_MPORT_data),
    .core_iregfile_regfile_read_data_3_MPORT_addr(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_3_MPORT_addr),
    .core_iregfile_regfile_read_data_3_MPORT_data(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_3_MPORT_data),
    .core_iregfile_regfile_read_data_4_MPORT_addr(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_4_MPORT_addr),
    .core_iregfile_regfile_read_data_4_MPORT_data(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_4_MPORT_data),
    .core_iregfile_regfile_read_data_5_MPORT_addr(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_5_MPORT_addr),
    .core_iregfile_regfile_read_data_5_MPORT_data(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_5_MPORT_data),
    .core_iregfile_regfile_read_data_6_MPORT_addr(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_6_MPORT_addr),
    .core_iregfile_regfile_read_data_6_MPORT_data(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_6_MPORT_data),
    .core_iregfile_regfile_read_data_7_MPORT_addr(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_7_MPORT_addr),
    .core_iregfile_regfile_read_data_7_MPORT_data(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_7_MPORT_data),
    .core_iregfile_regfile_read_data_8_MPORT_addr(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_8_MPORT_addr),
    .core_iregfile_regfile_read_data_8_MPORT_data(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_8_MPORT_data),
    .core_iregfile_regfile_read_data_9_MPORT_addr(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_9_MPORT_addr),
    .core_iregfile_regfile_read_data_9_MPORT_data(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_9_MPORT_data),
    .core_iregfile_regfile_read_data_10_MPORT_addr(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_10_MPORT_addr),
    .core_iregfile_regfile_read_data_10_MPORT_data(
      tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_10_MPORT_data),
    .core_iregfile_regfile_MPORT_addr(tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_addr),
    .core_iregfile_regfile_MPORT_en(tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_en),
    .core_iregfile_regfile_MPORT_data(tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_data),
    .core_iregfile_regfile_MPORT_1_addr(tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_1_addr),
    .core_iregfile_regfile_MPORT_1_en(tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_1_en),
    .core_iregfile_regfile_MPORT_1_data(tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_1_data),
    .core_iregfile_regfile_MPORT_2_addr(tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_2_addr),
    .core_iregfile_regfile_MPORT_2_en(tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_2_en),
    .core_iregfile_regfile_MPORT_2_data(tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_2_data),
    .core_iregfile_regfile_MPORT_3_addr(tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_3_addr),
    .core_iregfile_regfile_MPORT_3_en(tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_3_en),
    .core_iregfile_regfile_MPORT_3_data(tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_3_data),
    .core_fp_pipeline_fregfile_regfile_read_data_0_MPORT_addr(
      tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_0_MPORT_addr),
    .core_fp_pipeline_fregfile_regfile_read_data_0_MPORT_data(
      tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_0_MPORT_data),
    .core_fp_pipeline_fregfile_regfile_read_data_1_MPORT_addr(
      tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_1_MPORT_addr),
    .core_fp_pipeline_fregfile_regfile_read_data_1_MPORT_data(
      tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_1_MPORT_data),
    .core_fp_pipeline_fregfile_regfile_read_data_2_MPORT_addr(
      tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_2_MPORT_addr),
    .core_fp_pipeline_fregfile_regfile_read_data_2_MPORT_data(
      tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_2_MPORT_data),
    .core_fp_pipeline_fregfile_regfile_MPORT_addr(
      tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_addr),
    .core_fp_pipeline_fregfile_regfile_MPORT_en(tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_en
      ),
    .core_fp_pipeline_fregfile_regfile_MPORT_data(
      tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_data),
    .core_fp_pipeline_fregfile_regfile_MPORT_1_addr(
      tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_1_addr),
    .core_fp_pipeline_fregfile_regfile_MPORT_1_en(
      tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_1_en),
    .core_fp_pipeline_fregfile_regfile_MPORT_1_data(
      tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_1_data),
    .dcache_ownerImageMemory_flattened_installPreservationAllowed_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_installPreservationAllowed_MPORT_addr),
    .dcache_ownerImageMemory_flattened_installPreservationAllowed_MPORT_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_installPreservationAllowed_MPORT_data),
    .dcache_ownerImageMemory_flattened_refillPreservationAllowed_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_refillPreservationAllowed_MPORT_addr),
    .dcache_ownerImageMemory_flattened_refillPreservationAllowed_MPORT_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_refillPreservationAllowed_MPORT_data),
    .dcache_ownerImageMemory_flattened_wb_io_image_key_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_wb_io_image_key_MPORT_addr),
    .dcache_ownerImageMemory_flattened_wb_io_image_key_MPORT_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_wb_io_image_key_MPORT_data),
    .dcache_ownerImageMemory_flattened_crossPackageResidentMatch_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageResidentMatch_MPORT_addr),
    .dcache_ownerImageMemory_flattened_crossPackageResidentMatch_MPORT_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageResidentMatch_MPORT_data),
    .dcache_ownerImageMemory_flattened_crossPackageWbPacketSeq_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageWbPacketSeq_MPORT_addr),
    .dcache_ownerImageMemory_flattened_crossPackageWbPacketSeq_MPORT_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageWbPacketSeq_MPORT_data),
    .dcache_ownerImageMemory_flattened_s2_overwrittenKey_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_s2_overwrittenKey_MPORT_addr),
    .dcache_ownerImageMemory_flattened_s2_overwrittenKey_MPORT_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_s2_overwrittenKey_MPORT_data),
    .dcache_ownerImageMemory_flattened_svbCaptureResidentMatch_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_svbCaptureResidentMatch_MPORT_addr),
    .dcache_ownerImageMemory_flattened_svbCaptureResidentMatch_MPORT_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_svbCaptureResidentMatch_MPORT_data),
    .dcache_ownerImageMemory_flattened_svbFastKey_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_svbFastKey_MPORT_addr),
    .dcache_ownerImageMemory_flattened_svbFastKey_MPORT_en(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_svbFastKey_MPORT_en),
    .dcache_ownerImageMemory_flattened_svbFastKey_MPORT_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_svbFastKey_MPORT_data),
    .dcache_ownerImageMemory_flattened_clearFreezeReadBypassWindow_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_clearFreezeReadBypassWindow_MPORT_addr),
    .dcache_ownerImageMemory_flattened_clearFreezeReadBypassWindow_MPORT_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_clearFreezeReadBypassWindow_MPORT_data),
    .dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_addr),
    .dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_data),
    .dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_1_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_1_addr),
    .dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_1_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_1_data),
    .dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_2_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_2_addr),
    .dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_2_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_2_data),
    .dcache_ownerImageMemory_flattened_crossPackageWbReq_valid_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageWbReq_valid_MPORT_addr),
    .dcache_ownerImageMemory_flattened_crossPackageWbReq_valid_MPORT_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageWbReq_valid_MPORT_data),
    .dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_addr),
    .dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_en(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_en),
    .dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_data),
    .dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_addr),
    .dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_en(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_en),
    .dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_data),
    .dcache_ownerImageMemory_flattened_MPORT_4_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_4_addr),
    .dcache_ownerImageMemory_flattened_MPORT_4_en(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_4_en),
    .dcache_ownerImageMemory_flattened_MPORT_4_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_4_data),
    .dcache_ownerImageMemory_flattened_MPORT_5_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_5_addr),
    .dcache_ownerImageMemory_flattened_MPORT_5_en(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_5_en),
    .dcache_ownerImageMemory_flattened_MPORT_5_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_5_data),
    .dcache_ownerImageMemory_flattened_MPORT_6_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_6_addr),
    .dcache_ownerImageMemory_flattened_MPORT_6_en(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_6_en),
    .dcache_ownerImageMemory_flattened_MPORT_6_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_6_data),
    .dcache_ownerImageMemory_flattened_MPORT_7_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_7_addr),
    .dcache_ownerImageMemory_flattened_MPORT_7_en(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_7_en),
    .dcache_ownerImageMemory_flattened_MPORT_7_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_7_data),
    .dcache_ownerImageMemory_flattened_MPORT_8_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_8_addr),
    .dcache_ownerImageMemory_flattened_MPORT_8_en(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_8_en),
    .dcache_ownerImageMemory_flattened_MPORT_8_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_8_data),
    .dcache_ownerImageMemory_flattened_MPORT_9_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_9_addr),
    .dcache_ownerImageMemory_flattened_MPORT_9_en(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_9_en),
    .dcache_ownerImageMemory_flattened_MPORT_9_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_9_data),
    .dcache_ownerImageMemory_flattened_MPORT_10_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_10_addr),
    .dcache_ownerImageMemory_flattened_MPORT_10_en(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_10_en),
    .dcache_ownerImageMemory_flattened_MPORT_10_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_10_data),
    .dcache_ownerImageMemory_flattened_s3_l1PreservationAllowed_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_s3_l1PreservationAllowed_MPORT_addr),
    .dcache_ownerImageMemory_flattened_s3_l1PreservationAllowed_MPORT_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_s3_l1PreservationAllowed_MPORT_data),
    .dcache_ownerImageMemory_flattened_MPORT_12_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_12_addr),
    .dcache_ownerImageMemory_flattened_MPORT_12_en(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_12_en),
    .dcache_ownerImageMemory_flattened_MPORT_12_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_12_data),
    .dcache_ownerImageMemory_flattened_MPORT_13_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_13_addr),
    .dcache_ownerImageMemory_flattened_MPORT_13_en(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_13_en),
    .dcache_ownerImageMemory_flattened_MPORT_13_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_13_data),
    .dcache_ownerImageMemory_flattened_MPORT_14_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_14_addr),
    .dcache_ownerImageMemory_flattened_MPORT_14_en(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_14_en),
    .dcache_ownerImageMemory_flattened_MPORT_14_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_14_data),
    .dcache_ownerImageMemory_flattened_MPORT_15_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_15_addr),
    .dcache_ownerImageMemory_flattened_MPORT_15_en(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_15_en),
    .dcache_ownerImageMemory_flattened_MPORT_15_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_15_data),
    .dcache_ownerImageMemory_flattened_MPORT_16_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_16_addr),
    .dcache_ownerImageMemory_flattened_MPORT_16_en(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_16_en),
    .dcache_ownerImageMemory_flattened_MPORT_16_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_16_data),
    .dcache_ownerImageMemory_flattened_slowdown_opt1_pending_live_key_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_slowdown_opt1_pending_live_key_MPORT_addr),
    .dcache_ownerImageMemory_flattened_slowdown_opt1_pending_live_key_MPORT_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_slowdown_opt1_pending_live_key_MPORT_data),
    .dcache_ownerImageMemory_flattened_slowdown_opt1_pending_safe_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_slowdown_opt1_pending_safe_MPORT_addr),
    .dcache_ownerImageMemory_flattened_slowdown_opt1_pending_safe_MPORT_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_slowdown_opt1_pending_safe_MPORT_data),
    .dcache_ownerImageMemory_flattened_preservationWaitWatermark_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_preservationWaitWatermark_MPORT_addr),
    .dcache_ownerImageMemory_flattened_MPORT_17_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_17_addr),
    .dcache_ownerImageMemory_flattened_MPORT_18_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_18_addr),
    .dcache_ownerImageMemory_flattened_opt2bWriteKey_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_opt2bWriteKey_MPORT_addr),
    .dcache_ownerImageMemory_flattened_safeChainLiveKey_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_safeChainLiveKey_MPORT_addr),
    .dcache_ownerImageMemory_flattened_MPORT_addr(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_addr),
    .dcache_ownerImageMemory_flattened_MPORT_en(tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_en
      ),
    .dcache_ownerImageMemory_flattened_MPORT_data(
      tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_data)
  );
  TLBuffer_20 buffer_1 ( // @[Buffer.scala 69:28]
    .clock(buffer_1_clock),
    .reset(buffer_1_reset),
    .auto_in_a_ready(buffer_1_auto_in_a_ready),
    .auto_in_a_valid(buffer_1_auto_in_a_valid),
    .auto_in_a_bits_opcode(buffer_1_auto_in_a_bits_opcode),
    .auto_in_a_bits_param(buffer_1_auto_in_a_bits_param),
    .auto_in_a_bits_size(buffer_1_auto_in_a_bits_size),
    .auto_in_a_bits_source(buffer_1_auto_in_a_bits_source),
    .auto_in_a_bits_address(buffer_1_auto_in_a_bits_address),
    .auto_in_a_bits_mask(buffer_1_auto_in_a_bits_mask),
    .auto_in_a_bits_data(buffer_1_auto_in_a_bits_data),
    .auto_in_b_ready(buffer_1_auto_in_b_ready),
    .auto_in_b_valid(buffer_1_auto_in_b_valid),
    .auto_in_b_bits_param(buffer_1_auto_in_b_bits_param),
    .auto_in_b_bits_size(buffer_1_auto_in_b_bits_size),
    .auto_in_b_bits_source(buffer_1_auto_in_b_bits_source),
    .auto_in_b_bits_address(buffer_1_auto_in_b_bits_address),
    .auto_in_c_ready(buffer_1_auto_in_c_ready),
    .auto_in_c_valid(buffer_1_auto_in_c_valid),
    .auto_in_c_bits_opcode(buffer_1_auto_in_c_bits_opcode),
    .auto_in_c_bits_param(buffer_1_auto_in_c_bits_param),
    .auto_in_c_bits_size(buffer_1_auto_in_c_bits_size),
    .auto_in_c_bits_source(buffer_1_auto_in_c_bits_source),
    .auto_in_c_bits_address(buffer_1_auto_in_c_bits_address),
    .auto_in_c_bits_user_cache_image_valid(buffer_1_auto_in_c_bits_user_cache_image_valid),
    .auto_in_c_bits_user_cache_image_writer(buffer_1_auto_in_c_bits_user_cache_image_writer),
    .auto_in_c_bits_user_cache_image_generation(buffer_1_auto_in_c_bits_user_cache_image_generation),
    .auto_in_c_bits_user_cache_image_contentSeq(buffer_1_auto_in_c_bits_user_cache_image_contentSeq),
    .auto_in_c_bits_data(buffer_1_auto_in_c_bits_data),
    .auto_in_d_ready(buffer_1_auto_in_d_ready),
    .auto_in_d_valid(buffer_1_auto_in_d_valid),
    .auto_in_d_bits_opcode(buffer_1_auto_in_d_bits_opcode),
    .auto_in_d_bits_param(buffer_1_auto_in_d_bits_param),
    .auto_in_d_bits_size(buffer_1_auto_in_d_bits_size),
    .auto_in_d_bits_source(buffer_1_auto_in_d_bits_source),
    .auto_in_d_bits_sink(buffer_1_auto_in_d_bits_sink),
    .auto_in_d_bits_denied(buffer_1_auto_in_d_bits_denied),
    .auto_in_d_bits_user_cache_image_valid(buffer_1_auto_in_d_bits_user_cache_image_valid),
    .auto_in_d_bits_user_cache_image_writer(buffer_1_auto_in_d_bits_user_cache_image_writer),
    .auto_in_d_bits_user_cache_image_generation(buffer_1_auto_in_d_bits_user_cache_image_generation),
    .auto_in_d_bits_user_cache_image_contentSeq(buffer_1_auto_in_d_bits_user_cache_image_contentSeq),
    .auto_in_d_bits_data(buffer_1_auto_in_d_bits_data),
    .auto_in_d_bits_corrupt(buffer_1_auto_in_d_bits_corrupt),
    .auto_in_e_ready(buffer_1_auto_in_e_ready),
    .auto_in_e_valid(buffer_1_auto_in_e_valid),
    .auto_in_e_bits_sink(buffer_1_auto_in_e_bits_sink),
    .auto_out_a_ready(buffer_1_auto_out_a_ready),
    .auto_out_a_valid(buffer_1_auto_out_a_valid),
    .auto_out_a_bits_opcode(buffer_1_auto_out_a_bits_opcode),
    .auto_out_a_bits_param(buffer_1_auto_out_a_bits_param),
    .auto_out_a_bits_size(buffer_1_auto_out_a_bits_size),
    .auto_out_a_bits_source(buffer_1_auto_out_a_bits_source),
    .auto_out_a_bits_address(buffer_1_auto_out_a_bits_address),
    .auto_out_a_bits_user_cache_image_valid(buffer_1_auto_out_a_bits_user_cache_image_valid),
    .auto_out_a_bits_user_cache_image_writer(buffer_1_auto_out_a_bits_user_cache_image_writer),
    .auto_out_a_bits_user_cache_image_generation(buffer_1_auto_out_a_bits_user_cache_image_generation),
    .auto_out_a_bits_user_cache_image_contentSeq(buffer_1_auto_out_a_bits_user_cache_image_contentSeq),
    .auto_out_a_bits_mask(buffer_1_auto_out_a_bits_mask),
    .auto_out_a_bits_data(buffer_1_auto_out_a_bits_data),
    .auto_out_a_bits_corrupt(buffer_1_auto_out_a_bits_corrupt),
    .auto_out_b_ready(buffer_1_auto_out_b_ready),
    .auto_out_b_valid(buffer_1_auto_out_b_valid),
    .auto_out_b_bits_param(buffer_1_auto_out_b_bits_param),
    .auto_out_b_bits_source(buffer_1_auto_out_b_bits_source),
    .auto_out_b_bits_address(buffer_1_auto_out_b_bits_address),
    .auto_out_c_ready(buffer_1_auto_out_c_ready),
    .auto_out_c_valid(buffer_1_auto_out_c_valid),
    .auto_out_c_bits_opcode(buffer_1_auto_out_c_bits_opcode),
    .auto_out_c_bits_param(buffer_1_auto_out_c_bits_param),
    .auto_out_c_bits_size(buffer_1_auto_out_c_bits_size),
    .auto_out_c_bits_source(buffer_1_auto_out_c_bits_source),
    .auto_out_c_bits_address(buffer_1_auto_out_c_bits_address),
    .auto_out_c_bits_user_cache_image_valid(buffer_1_auto_out_c_bits_user_cache_image_valid),
    .auto_out_c_bits_user_cache_image_writer(buffer_1_auto_out_c_bits_user_cache_image_writer),
    .auto_out_c_bits_user_cache_image_generation(buffer_1_auto_out_c_bits_user_cache_image_generation),
    .auto_out_c_bits_user_cache_image_contentSeq(buffer_1_auto_out_c_bits_user_cache_image_contentSeq),
    .auto_out_c_bits_data(buffer_1_auto_out_c_bits_data),
    .auto_out_c_bits_corrupt(buffer_1_auto_out_c_bits_corrupt),
    .auto_out_d_ready(buffer_1_auto_out_d_ready),
    .auto_out_d_valid(buffer_1_auto_out_d_valid),
    .auto_out_d_bits_opcode(buffer_1_auto_out_d_bits_opcode),
    .auto_out_d_bits_param(buffer_1_auto_out_d_bits_param),
    .auto_out_d_bits_size(buffer_1_auto_out_d_bits_size),
    .auto_out_d_bits_source(buffer_1_auto_out_d_bits_source),
    .auto_out_d_bits_sink(buffer_1_auto_out_d_bits_sink),
    .auto_out_d_bits_denied(buffer_1_auto_out_d_bits_denied),
    .auto_out_d_bits_user_cache_image_valid(buffer_1_auto_out_d_bits_user_cache_image_valid),
    .auto_out_d_bits_user_cache_image_writer(buffer_1_auto_out_d_bits_user_cache_image_writer),
    .auto_out_d_bits_user_cache_image_generation(buffer_1_auto_out_d_bits_user_cache_image_generation),
    .auto_out_d_bits_user_cache_image_contentSeq(buffer_1_auto_out_d_bits_user_cache_image_contentSeq),
    .auto_out_d_bits_data(buffer_1_auto_out_d_bits_data),
    .auto_out_d_bits_corrupt(buffer_1_auto_out_d_bits_corrupt),
    .auto_out_e_ready(buffer_1_auto_out_e_ready),
    .auto_out_e_valid(buffer_1_auto_out_e_valid),
    .auto_out_e_bits_sink(buffer_1_auto_out_e_bits_sink)
  );
  IntSyncSyncCrossingSink intsink_1 ( // @[Crossing.scala 99:29]
    .auto_in_sync_0(intsink_1_auto_in_sync_0),
    .auto_in_sync_1(intsink_1_auto_in_sync_1),
    .auto_out_0(intsink_1_auto_out_0),
    .auto_out_1(intsink_1_auto_out_1)
  );
  GH_Bridge intsink_2 ( // @[Crossing.scala 99:29]
    .io_in(intsink_2_io_in),
    .io_out(intsink_2_io_out)
  );
  GH_Bridge intsink_3 ( // @[Crossing.scala 99:29]
    .io_in(intsink_3_io_in),
    .io_out(intsink_3_io_out)
  );
  assign auto_tile_reset_domain_boom_tile_broadcast_out_0_valid =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_0_valid; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_0_iaddr =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_0_iaddr; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_0_insn =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_0_insn; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_0_priv =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_0_priv; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_0_exception =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_0_exception; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_0_interrupt =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_0_interrupt; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_0_cause =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_0_cause; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_0_tval =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_0_tval; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_0_wdata =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_0_wdata; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_1_valid =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_1_valid; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_1_iaddr =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_1_iaddr; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_1_insn =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_1_insn; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_1_priv =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_1_priv; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_1_exception =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_1_exception; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_1_interrupt =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_1_interrupt; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_1_cause =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_1_cause; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_1_tval =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_1_tval; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_1_wdata =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_1_wdata; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_2_valid =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_2_valid; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_2_iaddr =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_2_iaddr; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_2_insn =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_2_insn; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_2_priv =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_2_priv; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_2_exception =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_2_exception; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_2_interrupt =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_2_interrupt; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_2_cause =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_2_cause; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_2_tval =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_2_tval; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_broadcast_out_2_wdata =
    tile_reset_domain__boom_tile__auto_broadcast_out_1_2_wdata; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_checker_segment_id_sr_out =
    tile_reset_domain__boom_tile__auto_checker_segment_id_sr_out; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_checker_big_owner_sr_out =
    tile_reset_domain__boom_tile__auto_checker_big_owner_sr_out; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_ic_status_sr_out = tile_reset_domain__boom_tile__auto_ic_status_sr_out; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_reset_sr_out = tile_reset_domain__boom_tile__auto_reset_sr_out; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_clock_sr_out = tile_reset_domain__boom_tile__auto_clock_sr_out; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_producer_seal_sr_out = tile_reset_domain__boom_tile__auto_producer_seal_sr_out
    ; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_ght_status_out_sr_out =
    tile_reset_domain__boom_tile__auto_ght_status_out_sr_out; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_ght_packet_dest_sr_out =
    tile_reset_domain__boom_tile__auto_ght_packet_dest_sr_out; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out = tile_reset_domain__boom_tile__auto_core_r_arfs_sr_out; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_ght_packet_out_sr_out =
    tile_reset_domain__boom_tile__auto_ght_packet_out_sr_out; // @[LazyModule.scala 368:12]
  assign auto_tile_reset_domain_boom_tile_ic_counter_sr_out = tile_reset_domain__boom_tile__auto_ic_counter_sr_out; // @[LazyModule.scala 368:12]
  assign auto_tl_master_clock_xing_out_a_valid = buffer_1_auto_out_a_valid; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_a_bits_opcode = buffer_1_auto_out_a_bits_opcode; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_a_bits_param = buffer_1_auto_out_a_bits_param; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_a_bits_size = buffer_1_auto_out_a_bits_size; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_a_bits_source = buffer_1_auto_out_a_bits_source; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_a_bits_address = buffer_1_auto_out_a_bits_address; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_a_bits_user_cache_image_valid = buffer_1_auto_out_a_bits_user_cache_image_valid; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_a_bits_user_cache_image_writer = buffer_1_auto_out_a_bits_user_cache_image_writer
    ; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_a_bits_user_cache_image_generation =
    buffer_1_auto_out_a_bits_user_cache_image_generation; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_a_bits_user_cache_image_contentSeq =
    buffer_1_auto_out_a_bits_user_cache_image_contentSeq; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_a_bits_mask = buffer_1_auto_out_a_bits_mask; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_a_bits_data = buffer_1_auto_out_a_bits_data; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_a_bits_corrupt = buffer_1_auto_out_a_bits_corrupt; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_b_ready = buffer_1_auto_out_b_ready; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_c_valid = buffer_1_auto_out_c_valid; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_c_bits_opcode = buffer_1_auto_out_c_bits_opcode; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_c_bits_param = buffer_1_auto_out_c_bits_param; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_c_bits_size = buffer_1_auto_out_c_bits_size; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_c_bits_source = buffer_1_auto_out_c_bits_source; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_c_bits_address = buffer_1_auto_out_c_bits_address; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_c_bits_user_cache_image_valid = buffer_1_auto_out_c_bits_user_cache_image_valid; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_c_bits_user_cache_image_writer = buffer_1_auto_out_c_bits_user_cache_image_writer
    ; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_c_bits_user_cache_image_generation =
    buffer_1_auto_out_c_bits_user_cache_image_generation; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_c_bits_user_cache_image_contentSeq =
    buffer_1_auto_out_c_bits_user_cache_image_contentSeq; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_c_bits_data = buffer_1_auto_out_c_bits_data; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_c_bits_corrupt = buffer_1_auto_out_c_bits_corrupt; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_d_ready = buffer_1_auto_out_d_ready; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_e_valid = buffer_1_auto_out_e_valid; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign auto_tl_master_clock_xing_out_e_bits_sink = buffer_1_auto_out_e_bits_sink; // @[Nodes.scala 1215:84 LazyModule.scala 353:16]
  assign clock = auto_tap_clock_in_clock; // @[Nodes.scala 1215:84 LazyModule.scala 366:16]
  assign reset = auto_tap_clock_in_reset; // @[Nodes.scala 1215:84 LazyModule.scala 366:16]
  assign io_reply_valid = tile_reset_domain__boom_tile__io_reply_valid;
  assign barrierFailureSticky = tile_reset_domain__boom_tile__barrierFailureSticky;
  assign debug_traffic_counting = tile_reset_domain__boom_tile__debug_traffic_counting;
  assign _T_213 = tile_reset_domain__boom_tile___T_213;
  assign bankAck = tile_reset_domain__boom_tile__bankAck;
  assign barrierFailureSeq = tile_reset_domain__boom_tile__barrierFailureSeq;
  assign io_traffic_reset = tile_reset_domain__boom_tile__io_traffic_reset;
  assign safeWatermarkGray = tile_reset_domain__boom_tile__safeWatermarkGray;
  assign _T_248 = tile_reset_domain__boom_tile___T_248;
  assign clock_0 = tile_reset_domain__boom_tile__clock_0;
  assign _T_214 = tile_reset_domain__boom_tile___T_214;
  assign io_request_ready = tile_reset_domain__boom_tile__io_request_ready;
  assign synthesizedPrintf_tile_reset_domain_boom_tile_core_dac_printf_wire_enable =
    tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_enable;
  assign synthesizedPrintf_tile_reset_domain_boom_tile_core_dac_printf_wire_args_0 =
    tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_0;
  assign synthesizedPrintf_tile_reset_domain_boom_tile_core_dac_printf_wire_args_1 =
    tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_1;
  assign synthesizedPrintf_tile_reset_domain_boom_tile_core_dac_printf_wire_args_2 =
    tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_2;
  assign synthesizedPrintf_tile_reset_domain_boom_tile_core_dac_printf_wire_args_3 =
    tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_3;
  assign synthesizedPrintf_tile_reset_domain_boom_tile_core_dac_printf_wire_args_4 =
    tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_4;
  assign synthesizedPrintf_tile_reset_domain_boom_tile_core_dac_printf_wire_args_11 =
    tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_11;
  assign synthesizedPrintf_tile_reset_domain_boom_tile_core_dac_printf_wire_args_12 =
    tile_reset_domain__boom_tile__synthesizedPrintf_core_dac_printf_wire_args_12;
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_0_MPORT_addr =
    tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_0_MPORT_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_1_MPORT_addr =
    tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_1_MPORT_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_2_MPORT_addr =
    tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_2_MPORT_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_3_MPORT_addr =
    tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_3_MPORT_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_4_MPORT_addr =
    tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_4_MPORT_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_5_MPORT_addr =
    tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_5_MPORT_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_6_MPORT_addr =
    tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_6_MPORT_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_7_MPORT_addr =
    tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_7_MPORT_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_8_MPORT_addr =
    tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_8_MPORT_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_9_MPORT_addr =
    tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_9_MPORT_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_10_MPORT_addr =
    tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_10_MPORT_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_addr =
    tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_en =
    tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_en; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_data =
    tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_1_addr =
    tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_1_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_1_en =
    tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_1_en; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_1_data =
    tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_1_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_2_addr =
    tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_2_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_2_en =
    tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_2_en; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_2_data =
    tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_2_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_3_addr =
    tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_3_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_3_en =
    tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_3_en; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_iregfile_regfile_MPORT_3_data =
    tile_reset_domain__boom_tile__core_iregfile_regfile_MPORT_3_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_read_data_0_MPORT_addr =
    tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_0_MPORT_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_read_data_1_MPORT_addr =
    tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_1_MPORT_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_read_data_2_MPORT_addr =
    tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_2_MPORT_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_MPORT_addr =
    tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_MPORT_en =
    tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_en; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_MPORT_data =
    tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_MPORT_1_addr =
    tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_1_addr; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_MPORT_1_en =
    tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_1_en; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_MPORT_1_data =
    tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_MPORT_1_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_installPreservationAllowed_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_installPreservationAllowed_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_refillPreservationAllowed_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_refillPreservationAllowed_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_wb_io_image_key_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_wb_io_image_key_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageResidentMatch_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageResidentMatch_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageWbPacketSeq_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageWbPacketSeq_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_s2_overwrittenKey_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_s2_overwrittenKey_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_svbCaptureResidentMatch_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_svbCaptureResidentMatch_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_svbFastKey_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_svbFastKey_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_svbFastKey_MPORT_en =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_svbFastKey_MPORT_en; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_clearFreezeReadBypassWindow_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_clearFreezeReadBypassWindow_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_1_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_1_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_2_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_2_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageWbReq_valid_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageWbReq_valid_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_en =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_en; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_en =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_en; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_4_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_4_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_4_en =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_4_en; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_5_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_5_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_5_en =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_5_en; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_6_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_6_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_6_en =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_6_en; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_7_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_7_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_7_en =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_7_en; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_8_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_8_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_8_en =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_8_en; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_9_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_9_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_9_en =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_9_en; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_10_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_10_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_10_en =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_10_en; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_s3_l1PreservationAllowed_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_s3_l1PreservationAllowed_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_12_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_12_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_12_en =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_12_en; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_13_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_13_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_13_en =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_13_en; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_14_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_14_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_14_en =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_14_en; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_15_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_15_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_15_en =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_15_en; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_16_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_16_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_16_en =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_16_en; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_slowdown_opt1_pending_live_key_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_slowdown_opt1_pending_live_key_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_slowdown_opt1_pending_safe_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_slowdown_opt1_pending_safe_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_preservationWaitWatermark_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_preservationWaitWatermark_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_17_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_17_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_18_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_18_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_opt2bWriteKey_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_opt2bWriteKey_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_safeChainLiveKey_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_safeChainLiveKey_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_addr =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_addr; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_en =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_en; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_data =
    tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__clock = auto_tap_clock_in_clock; // @[Nodes.scala 1215:84 LazyModule.scala 366:16]
  assign tile_reset_domain__boom_tile__reset = auto_tap_clock_in_reset; // @[Nodes.scala 1215:84 LazyModule.scala 366:16]
  assign tile_reset_domain__boom_tile__auto_master_out_a_ready = buffer_1_auto_in_a_ready; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_b_valid = buffer_1_auto_in_b_valid; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_b_bits_param = buffer_1_auto_in_b_bits_param; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_b_bits_size = buffer_1_auto_in_b_bits_size; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_b_bits_source = buffer_1_auto_in_b_bits_source; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_b_bits_address = buffer_1_auto_in_b_bits_address; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_c_ready = buffer_1_auto_in_c_ready; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_d_valid = buffer_1_auto_in_d_valid; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_d_bits_opcode = buffer_1_auto_in_d_bits_opcode; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_d_bits_param = buffer_1_auto_in_d_bits_param; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_d_bits_size = buffer_1_auto_in_d_bits_size; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_d_bits_source = buffer_1_auto_in_d_bits_source; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_d_bits_sink = buffer_1_auto_in_d_bits_sink; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_d_bits_denied = buffer_1_auto_in_d_bits_denied; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_d_bits_user_cache_image_valid =
    buffer_1_auto_in_d_bits_user_cache_image_valid; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_d_bits_user_cache_image_writer =
    buffer_1_auto_in_d_bits_user_cache_image_writer; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_d_bits_user_cache_image_generation =
    buffer_1_auto_in_d_bits_user_cache_image_generation; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_d_bits_user_cache_image_contentSeq =
    buffer_1_auto_in_d_bits_user_cache_image_contentSeq; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_d_bits_data = buffer_1_auto_in_d_bits_data; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_d_bits_corrupt = buffer_1_auto_in_d_bits_corrupt; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_master_out_e_ready = buffer_1_auto_in_e_ready; // @[LazyModule.scala 368:12]
  assign tile_reset_domain__boom_tile__auto_int_local_in_3_0 = intsink_3_io_out; // @[LazyModule.scala 366:16]
  assign tile_reset_domain__boom_tile__auto_int_local_in_2_0 = intsink_2_io_out; // @[LazyModule.scala 366:16]
  assign tile_reset_domain__boom_tile__auto_int_local_in_1_0 = intsink_1_auto_out_0; // @[LazyModule.scala 366:16]
  assign tile_reset_domain__boom_tile__auto_int_local_in_1_1 = intsink_1_auto_out_1; // @[LazyModule.scala 366:16]
  assign tile_reset_domain__boom_tile__auto_checker_results_sk_in =
    auto_tile_reset_domain_boom_tile_checker_results_sk_in; // @[LazyModule.scala 366:16]
  assign tile_reset_domain__boom_tile__auto_global_checker_big_owner_sk_in =
    auto_tile_reset_domain_boom_tile_global_checker_big_owner_sk_in; // @[LazyModule.scala 366:16]
  assign tile_reset_domain__boom_tile__auto_global_ic_status_sk_in =
    auto_tile_reset_domain_boom_tile_global_ic_status_sk_in; // @[LazyModule.scala 366:16]
  assign tile_reset_domain__boom_tile__auto_debug_gcounter_sk_in = auto_tile_reset_domain_boom_tile_debug_gcounter_sk_in
    ; // @[LazyModule.scala 366:16]
  assign tile_reset_domain__boom_tile__auto_report_fi_detection_in_sk_in =
    auto_tile_reset_domain_boom_tile_report_fi_detection_in_sk_in; // @[LazyModule.scala 366:16]
  assign tile_reset_domain__boom_tile__auto_bigcore_comp_in_sk_in =
    auto_tile_reset_domain_boom_tile_bigcore_comp_in_sk_in; // @[LazyModule.scala 366:16]
  assign tile_reset_domain__boom_tile__auto_bigcore_hang_in_sk_in =
    auto_tile_reset_domain_boom_tile_bigcore_hang_in_sk_in; // @[LazyModule.scala 366:16]
  assign tile_reset_domain__boom_tile__auto_icsl_na_sk_in = auto_tile_reset_domain_boom_tile_icsl_na_sk_in; // @[LazyModule.scala 366:16]
  assign tile_reset_domain__boom_tile__auto_clear_ic_status_tomain_sk_in =
    auto_tile_reset_domain_boom_tile_clear_ic_status_tomain_sk_in; // @[LazyModule.scala 366:16]
  assign tile_reset_domain__boom_tile__auto_hartid_in = auto_tile_reset_domain_boom_tile_hartid_in; // @[LazyModule.scala 366:16]
  assign tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_6_0 = gray_6;
  assign tile_reset_domain__boom_tile__io_enq_ready = io_enq_ready;
  assign tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_2_0 = gray_2;
  assign tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_3_0 = gray_13;
  assign tile_reset_domain__boom_tile__barrierRequest = barrierRequest;
  assign tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_9_0 = gray_9;
  assign tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_1_0 = gray_1;
  assign tile_reset_domain__boom_tile__io_deq_valid = io_deq_valid;
  assign tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_5_0 = gray_5;
  assign tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_0_0 = gray_10;
  assign tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_4_0 = gray_14;
  assign tile_reset_domain__boom_tile___T_0 = _T;
  assign tile_reset_domain__boom_tile__gh_l2_dram_wb_dirty_gray_0 = dirtyGray;
  assign tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_8_0 = gray_8;
  assign tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_0_0 = gray;
  assign tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_4_0 = gray_4;
  assign tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_5_0 = gray_15;
  assign tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_1_0 = gray_11;
  assign tile_reset_domain__boom_tile__gh_l2_dram_wb_clean_gray_0 = cleanGray;
  assign tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_7_0 = gray_7;
  assign tile_reset_domain__boom_tile__gh_l2_dram_dirty_stats_3_0 = gray_3;
  assign tile_reset_domain__boom_tile__barrierRequestSeq = barrierRequestSeq;
  assign tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_6_0 = gray_16;
  assign tile_reset_domain__boom_tile__gh_l2_dram_barrier_stats_2_0 = gray_12;
  assign tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_0_MPORT_data =
    tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_0_MPORT_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_1_MPORT_data =
    tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_1_MPORT_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_2_MPORT_data =
    tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_2_MPORT_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_3_MPORT_data =
    tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_3_MPORT_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_4_MPORT_data =
    tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_4_MPORT_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_5_MPORT_data =
    tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_5_MPORT_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_6_MPORT_data =
    tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_6_MPORT_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_7_MPORT_data =
    tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_7_MPORT_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_8_MPORT_data =
    tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_8_MPORT_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_9_MPORT_data =
    tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_9_MPORT_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain__boom_tile__core_iregfile_regfile_read_data_10_MPORT_data =
    tile_reset_domain_boom_tile_core_iregfile_regfile_read_data_10_MPORT_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_0_MPORT_data =
    tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_read_data_0_MPORT_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_1_MPORT_data =
    tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_read_data_1_MPORT_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain__boom_tile__core_fp_pipeline_fregfile_regfile_read_data_2_MPORT_data =
    tile_reset_domain_boom_tile_core_fp_pipeline_fregfile_regfile_read_data_2_MPORT_data; // @[regfile.scala 117:{20,20}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_installPreservationAllowed_MPORT_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_installPreservationAllowed_MPORT_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_refillPreservationAllowed_MPORT_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_refillPreservationAllowed_MPORT_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_wb_io_image_key_MPORT_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_wb_io_image_key_MPORT_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageResidentMatch_MPORT_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageResidentMatch_MPORT_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageWbPacketSeq_MPORT_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageWbPacketSeq_MPORT_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_s2_overwrittenKey_MPORT_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_s2_overwrittenKey_MPORT_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_svbCaptureResidentMatch_MPORT_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_svbCaptureResidentMatch_MPORT_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_svbFastKey_MPORT_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_svbFastKey_MPORT_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_clearFreezeReadBypassWindow_MPORT_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_clearFreezeReadBypassWindow_MPORT_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_1_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_1_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_2_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageSvbRescue_MPORT_2_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackageWbReq_valid_MPORT_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackageWbReq_valid_MPORT_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackagePendingSeq_MPORT_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_crossPackagePendingKey_MPORT_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_4_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_4_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_5_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_5_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_6_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_6_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_7_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_7_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_8_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_8_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_9_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_9_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_10_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_10_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_s3_l1PreservationAllowed_MPORT_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_s3_l1PreservationAllowed_MPORT_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_12_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_12_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_13_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_13_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_14_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_14_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_15_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_15_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_MPORT_16_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_MPORT_16_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_slowdown_opt1_pending_live_key_MPORT_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_slowdown_opt1_pending_live_key_MPORT_data; // @[dcache.scala 727:{29,29}]
  assign tile_reset_domain__boom_tile__dcache_ownerImageMemory_flattened_slowdown_opt1_pending_safe_MPORT_data =
    tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_slowdown_opt1_pending_safe_MPORT_data; // @[dcache.scala 727:{29,29}]
  assign buffer_1_clock = auto_tap_clock_in_clock; // @[Nodes.scala 1215:84 LazyModule.scala 366:16]
  assign buffer_1_reset = auto_tap_clock_in_reset; // @[Nodes.scala 1215:84 LazyModule.scala 366:16]
  assign buffer_1_auto_in_a_valid = tile_reset_domain__boom_tile__auto_master_out_a_valid; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_a_bits_opcode = tile_reset_domain__boom_tile__auto_master_out_a_bits_opcode; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_a_bits_param = tile_reset_domain__boom_tile__auto_master_out_a_bits_param; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_a_bits_size = tile_reset_domain__boom_tile__auto_master_out_a_bits_size; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_a_bits_source = tile_reset_domain__boom_tile__auto_master_out_a_bits_source; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_a_bits_address = tile_reset_domain__boom_tile__auto_master_out_a_bits_address; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_a_bits_mask = tile_reset_domain__boom_tile__auto_master_out_a_bits_mask; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_a_bits_data = tile_reset_domain__boom_tile__auto_master_out_a_bits_data; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_b_ready = tile_reset_domain__boom_tile__auto_master_out_b_ready; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_c_valid = tile_reset_domain__boom_tile__auto_master_out_c_valid; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_c_bits_opcode = tile_reset_domain__boom_tile__auto_master_out_c_bits_opcode; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_c_bits_param = tile_reset_domain__boom_tile__auto_master_out_c_bits_param; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_c_bits_size = tile_reset_domain__boom_tile__auto_master_out_c_bits_size; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_c_bits_source = tile_reset_domain__boom_tile__auto_master_out_c_bits_source; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_c_bits_address = tile_reset_domain__boom_tile__auto_master_out_c_bits_address; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_c_bits_user_cache_image_valid =
    tile_reset_domain__boom_tile__auto_master_out_c_bits_user_cache_image_valid; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_c_bits_user_cache_image_writer =
    tile_reset_domain__boom_tile__auto_master_out_c_bits_user_cache_image_writer; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_c_bits_user_cache_image_generation =
    tile_reset_domain__boom_tile__auto_master_out_c_bits_user_cache_image_generation; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_c_bits_user_cache_image_contentSeq =
    tile_reset_domain__boom_tile__auto_master_out_c_bits_user_cache_image_contentSeq; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_c_bits_data = tile_reset_domain__boom_tile__auto_master_out_c_bits_data; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_d_ready = tile_reset_domain__boom_tile__auto_master_out_d_ready; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_e_valid = tile_reset_domain__boom_tile__auto_master_out_e_valid; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_in_e_bits_sink = tile_reset_domain__boom_tile__auto_master_out_e_bits_sink; // @[LazyModule.scala 355:16]
  assign buffer_1_auto_out_a_ready = auto_tl_master_clock_xing_out_a_ready; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_b_valid = auto_tl_master_clock_xing_out_b_valid; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_b_bits_param = auto_tl_master_clock_xing_out_b_bits_param; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_b_bits_source = auto_tl_master_clock_xing_out_b_bits_source; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_b_bits_address = auto_tl_master_clock_xing_out_b_bits_address; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_c_ready = auto_tl_master_clock_xing_out_c_ready; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_d_valid = auto_tl_master_clock_xing_out_d_valid; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_d_bits_opcode = auto_tl_master_clock_xing_out_d_bits_opcode; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_d_bits_param = auto_tl_master_clock_xing_out_d_bits_param; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_d_bits_size = auto_tl_master_clock_xing_out_d_bits_size; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_d_bits_source = auto_tl_master_clock_xing_out_d_bits_source; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_d_bits_sink = auto_tl_master_clock_xing_out_d_bits_sink; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_d_bits_denied = auto_tl_master_clock_xing_out_d_bits_denied; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_d_bits_user_cache_image_valid = auto_tl_master_clock_xing_out_d_bits_user_cache_image_valid; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_d_bits_user_cache_image_writer = auto_tl_master_clock_xing_out_d_bits_user_cache_image_writer
    ; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_d_bits_user_cache_image_generation =
    auto_tl_master_clock_xing_out_d_bits_user_cache_image_generation; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_d_bits_user_cache_image_contentSeq =
    auto_tl_master_clock_xing_out_d_bits_user_cache_image_contentSeq; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_d_bits_data = auto_tl_master_clock_xing_out_d_bits_data; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_d_bits_corrupt = auto_tl_master_clock_xing_out_d_bits_corrupt; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign buffer_1_auto_out_e_ready = auto_tl_master_clock_xing_out_e_ready; // @[Nodes.scala 1212:84 LazyModule.scala 368:12]
  assign intsink_1_auto_in_sync_0 = auto_int_in_clock_xing_in_0_sync_0; // @[Nodes.scala 1215:84 LazyModule.scala 366:16]
  assign intsink_1_auto_in_sync_1 = auto_int_in_clock_xing_in_0_sync_1; // @[Nodes.scala 1215:84 LazyModule.scala 366:16]
  assign intsink_2_io_in = auto_int_in_clock_xing_in_1_sync_0; // @[Nodes.scala 1215:84 LazyModule.scala 366:16]
  assign intsink_3_io_in = auto_int_in_clock_xing_in_2_sync_0; // @[Nodes.scala 1215:84 LazyModule.scala 366:16]
endmodule