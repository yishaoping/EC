module ownerImageMemory_flattened(
  input         hostClock,
  input         hostReset,
  output        MPORT_5_addr_sink_ready,
  input         MPORT_5_addr_sink_valid,
  input  [8:0]  MPORT_5_addr_sink_bits,
  output        crossPackagePendingKey_MPORT_addr_sink_ready,
  input         crossPackagePendingKey_MPORT_addr_sink_valid,
  input  [8:0]  crossPackagePendingKey_MPORT_addr_sink_bits,
  output        MPORT_14_addr_sink_ready,
  input         MPORT_14_addr_sink_valid,
  input  [8:0]  MPORT_14_addr_sink_bits,
  output        slowdown_opt1_pending_live_key_MPORT_addr_sink_ready,
  input         slowdown_opt1_pending_live_key_MPORT_addr_sink_valid,
  input  [8:0]  slowdown_opt1_pending_live_key_MPORT_addr_sink_bits,
  output        s3_l1PreservationAllowed_MPORT_addr_sink_ready,
  input         s3_l1PreservationAllowed_MPORT_addr_sink_valid,
  input  [8:0]  s3_l1PreservationAllowed_MPORT_addr_sink_bits,
  output        crossPackagePendingSeq_MPORT_en_sink_ready,
  input         crossPackagePendingSeq_MPORT_en_sink_valid,
  output        refillPreservationAllowed_MPORT_addr_sink_ready,
  input         refillPreservationAllowed_MPORT_addr_sink_valid,
  input  [8:0]  refillPreservationAllowed_MPORT_addr_sink_bits,
  output        crossPackageWbReq_valid_MPORT_en_sink_ready,
  input         crossPackageWbReq_valid_MPORT_en_sink_valid,
  output        MPORT_6_en_sink_ready,
  input         MPORT_6_en_sink_valid,
  output        crossPackageResidentMatch_MPORT_addr_sink_ready,
  input         crossPackageResidentMatch_MPORT_addr_sink_valid,
  input  [8:0]  crossPackageResidentMatch_MPORT_addr_sink_bits,
  output        crossPackageWbPacketSeq_MPORT_addr_sink_ready,
  input         crossPackageWbPacketSeq_MPORT_addr_sink_valid,
  input  [8:0]  crossPackageWbPacketSeq_MPORT_addr_sink_bits,
  output        crossPackageSvbRescue_MPORT_2_en_sink_ready,
  input         crossPackageSvbRescue_MPORT_2_en_sink_valid,
  output        MPORT_15_addr_sink_ready,
  input         MPORT_15_addr_sink_valid,
  input  [8:0]  MPORT_15_addr_sink_bits,
  output        MPORT_16_en_sink_ready,
  input         MPORT_16_en_sink_valid,
  output        MPORT_16_addr_sink_ready,
  input         MPORT_16_addr_sink_valid,
  input  [8:0]  MPORT_16_addr_sink_bits,
  output        MPORT_10_addr_sink_ready,
  input         MPORT_10_addr_sink_valid,
  input  [8:0]  MPORT_10_addr_sink_bits,
  output        crossPackageWbReq_valid_MPORT_addr_sink_ready,
  input         crossPackageWbReq_valid_MPORT_addr_sink_valid,
  input  [8:0]  crossPackageWbReq_valid_MPORT_addr_sink_bits,
  output        opt2bWriteKey_MPORT_en_sink_ready,
  input         opt2bWriteKey_MPORT_en_sink_valid,
  output        svbCaptureResidentMatch_MPORT_addr_sink_ready,
  input         svbCaptureResidentMatch_MPORT_addr_sink_valid,
  input  [8:0]  svbCaptureResidentMatch_MPORT_addr_sink_bits,
  output        s3_l1PreservationAllowed_MPORT_en_sink_ready,
  input         s3_l1PreservationAllowed_MPORT_en_sink_valid,
  output        MPORT_9_en_sink_ready,
  input         MPORT_9_en_sink_valid,
  output        MPORT_data_sink_ready,
  input         MPORT_data_sink_valid,
  input  [80:0] MPORT_data_sink_bits,
  output        crossPackageWbPacketSeq_MPORT_en_sink_ready,
  input         crossPackageWbPacketSeq_MPORT_en_sink_valid,
  output        MPORT_12_addr_sink_ready,
  input         MPORT_12_addr_sink_valid,
  input  [8:0]  MPORT_12_addr_sink_bits,
  output        preservationWaitWatermark_MPORT_en_sink_ready,
  input         preservationWaitWatermark_MPORT_en_sink_valid,
  output        safeChainLiveKey_MPORT_en_sink_ready,
  input         safeChainLiveKey_MPORT_en_sink_valid,
  output        MPORT_15_en_sink_ready,
  input         MPORT_15_en_sink_valid,
  output        clearFreezeReadBypassWindow_MPORT_addr_sink_ready,
  input         clearFreezeReadBypassWindow_MPORT_addr_sink_valid,
  input  [8:0]  clearFreezeReadBypassWindow_MPORT_addr_sink_bits,
  output        svbFastKey_MPORT_en_sink_ready,
  input         svbFastKey_MPORT_en_sink_valid,
  output        crossPackagePendingSeq_MPORT_addr_sink_ready,
  input         crossPackagePendingSeq_MPORT_addr_sink_valid,
  input  [8:0]  crossPackagePendingSeq_MPORT_addr_sink_bits,
  output        MPORT_4_en_sink_ready,
  input         MPORT_4_en_sink_valid,
  output        MPORT_17_en_sink_ready,
  input         MPORT_17_en_sink_valid,
  output        clearFreezeReadBypassWindow_MPORT_en_sink_ready,
  input         clearFreezeReadBypassWindow_MPORT_en_sink_valid,
  output        MPORT_addr_sink_ready,
  input         MPORT_addr_sink_valid,
  input  [8:0]  MPORT_addr_sink_bits,
  output        MPORT_10_en_sink_ready,
  input         MPORT_10_en_sink_valid,
  output        crossPackageSvbRescue_MPORT_2_addr_sink_ready,
  input         crossPackageSvbRescue_MPORT_2_addr_sink_valid,
  input  [8:0]  crossPackageSvbRescue_MPORT_2_addr_sink_bits,
  output        crossPackagePendingKey_MPORT_en_sink_ready,
  input         crossPackagePendingKey_MPORT_en_sink_valid,
  output        slowdown_opt1_pending_safe_MPORT_en_sink_ready,
  input         slowdown_opt1_pending_safe_MPORT_en_sink_valid,
  output        installPreservationAllowed_MPORT_en_sink_ready,
  input         installPreservationAllowed_MPORT_en_sink_valid,
  output        MPORT_7_addr_sink_ready,
  input         MPORT_7_addr_sink_valid,
  input  [8:0]  MPORT_7_addr_sink_bits,
  output        slowdown_opt1_pending_safe_MPORT_addr_sink_ready,
  input         slowdown_opt1_pending_safe_MPORT_addr_sink_valid,
  input  [8:0]  slowdown_opt1_pending_safe_MPORT_addr_sink_bits,
  output        MPORT_en_sink_ready,
  input         MPORT_en_sink_valid,
  input         MPORT_en_sink_bits,
  output        crossPackageSvbRescue_MPORT_1_en_sink_ready,
  input         crossPackageSvbRescue_MPORT_1_en_sink_valid,
  output        opt2bWriteKey_MPORT_addr_sink_ready,
  input         opt2bWriteKey_MPORT_addr_sink_valid,
  input  [8:0]  opt2bWriteKey_MPORT_addr_sink_bits,
  output        svbCaptureResidentMatch_MPORT_en_sink_ready,
  input         svbCaptureResidentMatch_MPORT_en_sink_valid,
  output        MPORT_7_en_sink_ready,
  input         MPORT_7_en_sink_valid,
  output        wb_io_image_key_MPORT_addr_sink_ready,
  input         wb_io_image_key_MPORT_addr_sink_valid,
  input  [8:0]  wb_io_image_key_MPORT_addr_sink_bits,
  output        svbFastKey_MPORT_addr_sink_ready,
  input         svbFastKey_MPORT_addr_sink_valid,
  input  [8:0]  svbFastKey_MPORT_addr_sink_bits,
  output        MPORT_14_en_sink_ready,
  input         MPORT_14_en_sink_valid,
  output        preservationWaitWatermark_MPORT_addr_sink_ready,
  input         preservationWaitWatermark_MPORT_addr_sink_valid,
  input  [8:0]  preservationWaitWatermark_MPORT_addr_sink_bits,
  output        MPORT_18_addr_sink_ready,
  input         MPORT_18_addr_sink_valid,
  input  [8:0]  MPORT_18_addr_sink_bits,
  output        MPORT_6_addr_sink_ready,
  input         MPORT_6_addr_sink_valid,
  input  [8:0]  MPORT_6_addr_sink_bits,
  output        slowdown_opt1_pending_live_key_MPORT_en_sink_ready,
  input         slowdown_opt1_pending_live_key_MPORT_en_sink_valid,
  output        MPORT_12_en_sink_ready,
  input         MPORT_12_en_sink_valid,
  output        crossPackageSvbRescue_MPORT_en_sink_ready,
  input         crossPackageSvbRescue_MPORT_en_sink_valid,
  output        MPORT_8_addr_sink_ready,
  input         MPORT_8_addr_sink_valid,
  input  [8:0]  MPORT_8_addr_sink_bits,
  output        MPORT_17_addr_sink_ready,
  input         MPORT_17_addr_sink_valid,
  input  [8:0]  MPORT_17_addr_sink_bits,
  output        wb_io_image_key_MPORT_en_sink_ready,
  input         wb_io_image_key_MPORT_en_sink_valid,
  output        MPORT_8_en_sink_ready,
  input         MPORT_8_en_sink_valid,
  output        crossPackageSvbRescue_MPORT_addr_sink_ready,
  input         crossPackageSvbRescue_MPORT_addr_sink_valid,
  input  [8:0]  crossPackageSvbRescue_MPORT_addr_sink_bits,
  output        installPreservationAllowed_MPORT_addr_sink_ready,
  input         installPreservationAllowed_MPORT_addr_sink_valid,
  input  [8:0]  installPreservationAllowed_MPORT_addr_sink_bits,
  output        refillPreservationAllowed_MPORT_en_sink_ready,
  input         refillPreservationAllowed_MPORT_en_sink_valid,
  output        crossPackageSvbRescue_MPORT_1_addr_sink_ready,
  input         crossPackageSvbRescue_MPORT_1_addr_sink_valid,
  input  [8:0]  crossPackageSvbRescue_MPORT_1_addr_sink_bits,
  output        s2_overwrittenKey_MPORT_en_sink_ready,
  input         s2_overwrittenKey_MPORT_en_sink_valid,
  output        crossPackageResidentMatch_MPORT_en_sink_ready,
  input         crossPackageResidentMatch_MPORT_en_sink_valid,
  output        MPORT_18_en_sink_ready,
  input         MPORT_18_en_sink_valid,
  output        MPORT_13_addr_sink_ready,
  input         MPORT_13_addr_sink_valid,
  input  [8:0]  MPORT_13_addr_sink_bits,
  output        safeChainLiveKey_MPORT_addr_sink_ready,
  input         safeChainLiveKey_MPORT_addr_sink_valid,
  input  [8:0]  safeChainLiveKey_MPORT_addr_sink_bits,
  output        MPORT_mask_sink_ready,
  input         MPORT_mask_sink_valid,
  input         MPORT_mask_sink_bits,
  output        s2_overwrittenKey_MPORT_addr_sink_ready,
  input         s2_overwrittenKey_MPORT_addr_sink_valid,
  input  [8:0]  s2_overwrittenKey_MPORT_addr_sink_bits,
  output        MPORT_9_addr_sink_ready,
  input         MPORT_9_addr_sink_valid,
  input  [8:0]  MPORT_9_addr_sink_bits,
  output        MPORT_13_en_sink_ready,
  input         MPORT_13_en_sink_valid,
  output        MPORT_5_en_sink_ready,
  input         MPORT_5_en_sink_valid,
  output        MPORT_4_addr_sink_ready,
  input         MPORT_4_addr_sink_valid,
  input  [8:0]  MPORT_4_addr_sink_bits,
  input         MPORT_10_data_source_ready,
  output        MPORT_10_data_source_valid,
  output [80:0] MPORT_10_data_source_bits,
  input         crossPackagePendingSeq_MPORT_data_source_ready,
  output        crossPackagePendingSeq_MPORT_data_source_valid,
  output [80:0] crossPackagePendingSeq_MPORT_data_source_bits,
  input         MPORT_4_data_source_ready,
  output        MPORT_4_data_source_valid,
  output [80:0] MPORT_4_data_source_bits,
  input         crossPackageWbPacketSeq_MPORT_data_source_ready,
  output        crossPackageWbPacketSeq_MPORT_data_source_valid,
  output [80:0] crossPackageWbPacketSeq_MPORT_data_source_bits,
  input         MPORT_14_data_source_ready,
  output        MPORT_14_data_source_valid,
  output [80:0] MPORT_14_data_source_bits,
  input         MPORT_6_data_source_ready,
  output        MPORT_6_data_source_valid,
  output [80:0] MPORT_6_data_source_bits,
  input         MPORT_18_data_source_ready,
  output        MPORT_18_data_source_valid,
  output [80:0] MPORT_18_data_source_bits,
  input         crossPackageSvbRescue_MPORT_data_source_ready,
  output        crossPackageSvbRescue_MPORT_data_source_valid,
  output [80:0] crossPackageSvbRescue_MPORT_data_source_bits,
  input         safeChainLiveKey_MPORT_data_source_ready,
  output        safeChainLiveKey_MPORT_data_source_valid,
  output [80:0] safeChainLiveKey_MPORT_data_source_bits,
  input         MPORT_17_data_source_ready,
  output        MPORT_17_data_source_valid,
  output [80:0] MPORT_17_data_source_bits,
  input         s3_l1PreservationAllowed_MPORT_data_source_ready,
  output        s3_l1PreservationAllowed_MPORT_data_source_valid,
  output [80:0] s3_l1PreservationAllowed_MPORT_data_source_bits,
  input         crossPackageWbReq_valid_MPORT_data_source_ready,
  output        crossPackageWbReq_valid_MPORT_data_source_valid,
  output [80:0] crossPackageWbReq_valid_MPORT_data_source_bits,
  input         svbFastKey_MPORT_data_source_ready,
  output        svbFastKey_MPORT_data_source_valid,
  output [80:0] svbFastKey_MPORT_data_source_bits,
  input         refillPreservationAllowed_MPORT_data_source_ready,
  output        refillPreservationAllowed_MPORT_data_source_valid,
  output [80:0] refillPreservationAllowed_MPORT_data_source_bits,
  input         s2_overwrittenKey_MPORT_data_source_ready,
  output        s2_overwrittenKey_MPORT_data_source_valid,
  output [80:0] s2_overwrittenKey_MPORT_data_source_bits,
  input         preservationWaitWatermark_MPORT_data_source_ready,
  output        preservationWaitWatermark_MPORT_data_source_valid,
  output [80:0] preservationWaitWatermark_MPORT_data_source_bits,
  input         MPORT_8_data_source_ready,
  output        MPORT_8_data_source_valid,
  output [80:0] MPORT_8_data_source_bits,
  input         crossPackageSvbRescue_MPORT_1_data_source_ready,
  output        crossPackageSvbRescue_MPORT_1_data_source_valid,
  output [80:0] crossPackageSvbRescue_MPORT_1_data_source_bits,
  input         MPORT_16_data_source_ready,
  output        MPORT_16_data_source_valid,
  output [80:0] MPORT_16_data_source_bits,
  input         slowdown_opt1_pending_live_key_MPORT_data_source_ready,
  output        slowdown_opt1_pending_live_key_MPORT_data_source_valid,
  output [80:0] slowdown_opt1_pending_live_key_MPORT_data_source_bits,
  input         MPORT_12_data_source_ready,
  output        MPORT_12_data_source_valid,
  output [80:0] MPORT_12_data_source_bits,
  input         MPORT_15_data_source_ready,
  output        MPORT_15_data_source_valid,
  output [80:0] MPORT_15_data_source_bits,
  input         opt2bWriteKey_MPORT_data_source_ready,
  output        opt2bWriteKey_MPORT_data_source_valid,
  output [80:0] opt2bWriteKey_MPORT_data_source_bits,
  input         MPORT_9_data_source_ready,
  output        MPORT_9_data_source_valid,
  output [80:0] MPORT_9_data_source_bits,
  input         crossPackageSvbRescue_MPORT_2_data_source_ready,
  output        crossPackageSvbRescue_MPORT_2_data_source_valid,
  output [80:0] crossPackageSvbRescue_MPORT_2_data_source_bits,
  input         MPORT_13_data_source_ready,
  output        MPORT_13_data_source_valid,
  output [80:0] MPORT_13_data_source_bits,
  input         slowdown_opt1_pending_safe_MPORT_data_source_ready,
  output        slowdown_opt1_pending_safe_MPORT_data_source_valid,
  output [80:0] slowdown_opt1_pending_safe_MPORT_data_source_bits,
  input         wb_io_image_key_MPORT_data_source_ready,
  output        wb_io_image_key_MPORT_data_source_valid,
  output [80:0] wb_io_image_key_MPORT_data_source_bits,
  input         MPORT_5_data_source_ready,
  output        MPORT_5_data_source_valid,
  output [80:0] MPORT_5_data_source_bits,
  input         clearFreezeReadBypassWindow_MPORT_data_source_ready,
  output        clearFreezeReadBypassWindow_MPORT_data_source_valid,
  output [80:0] clearFreezeReadBypassWindow_MPORT_data_source_bits,
  input         svbCaptureResidentMatch_MPORT_data_source_ready,
  output        svbCaptureResidentMatch_MPORT_data_source_valid,
  output [80:0] svbCaptureResidentMatch_MPORT_data_source_bits,
  input         crossPackageResidentMatch_MPORT_data_source_ready,
  output        crossPackageResidentMatch_MPORT_data_source_valid,
  output [80:0] crossPackageResidentMatch_MPORT_data_source_bits,
  input         installPreservationAllowed_MPORT_data_source_ready,
  output        installPreservationAllowed_MPORT_data_source_valid,
  output [80:0] installPreservationAllowed_MPORT_data_source_bits,
  input         MPORT_7_data_source_ready,
  output        MPORT_7_data_source_valid,
  output [80:0] MPORT_7_data_source_bits,
  input         crossPackagePendingKey_MPORT_data_source_ready,
  output        crossPackagePendingKey_MPORT_data_source_valid,
  output [80:0] crossPackagePendingKey_MPORT_data_source_bits
);
  wire  model_clock;
  wire  model_reset;
  wire  model_channels_read_cmds_0_ready;
  wire  model_channels_read_cmds_0_valid;
  wire [8:0] model_channels_read_cmds_0_bits_addr;
  wire  model_channels_read_cmds_1_ready;
  wire  model_channels_read_cmds_1_valid;
  wire [8:0] model_channels_read_cmds_1_bits_addr;
  wire  model_channels_read_cmds_2_ready;
  wire  model_channels_read_cmds_2_valid;
  wire [8:0] model_channels_read_cmds_2_bits_addr;
  wire  model_channels_read_cmds_3_ready;
  wire  model_channels_read_cmds_3_valid;
  wire [8:0] model_channels_read_cmds_3_bits_addr;
  wire  model_channels_read_cmds_4_ready;
  wire  model_channels_read_cmds_4_valid;
  wire [8:0] model_channels_read_cmds_4_bits_addr;
  wire  model_channels_read_cmds_5_ready;
  wire  model_channels_read_cmds_5_valid;
  wire [8:0] model_channels_read_cmds_5_bits_addr;
  wire  model_channels_read_cmds_6_ready;
  wire  model_channels_read_cmds_6_valid;
  wire [8:0] model_channels_read_cmds_6_bits_addr;
  wire  model_channels_read_cmds_7_ready;
  wire  model_channels_read_cmds_7_valid;
  wire [8:0] model_channels_read_cmds_7_bits_addr;
  wire  model_channels_read_cmds_8_ready;
  wire  model_channels_read_cmds_8_valid;
  wire [8:0] model_channels_read_cmds_8_bits_addr;
  wire  model_channels_read_cmds_9_ready;
  wire  model_channels_read_cmds_9_valid;
  wire [8:0] model_channels_read_cmds_9_bits_addr;
  wire  model_channels_read_cmds_10_ready;
  wire  model_channels_read_cmds_10_valid;
  wire [8:0] model_channels_read_cmds_10_bits_addr;
  wire  model_channels_read_cmds_11_ready;
  wire  model_channels_read_cmds_11_valid;
  wire [8:0] model_channels_read_cmds_11_bits_addr;
  wire  model_channels_read_cmds_12_ready;
  wire  model_channels_read_cmds_12_valid;
  wire [8:0] model_channels_read_cmds_12_bits_addr;
  wire  model_channels_read_cmds_13_ready;
  wire  model_channels_read_cmds_13_valid;
  wire [8:0] model_channels_read_cmds_13_bits_addr;
  wire  model_channels_read_cmds_14_ready;
  wire  model_channels_read_cmds_14_valid;
  wire [8:0] model_channels_read_cmds_14_bits_addr;
  wire  model_channels_read_cmds_15_ready;
  wire  model_channels_read_cmds_15_valid;
  wire [8:0] model_channels_read_cmds_15_bits_addr;
  wire  model_channels_read_cmds_16_ready;
  wire  model_channels_read_cmds_16_valid;
  wire [8:0] model_channels_read_cmds_16_bits_addr;
  wire  model_channels_read_cmds_17_ready;
  wire  model_channels_read_cmds_17_valid;
  wire [8:0] model_channels_read_cmds_17_bits_addr;
  wire  model_channels_read_cmds_18_ready;
  wire  model_channels_read_cmds_18_valid;
  wire [8:0] model_channels_read_cmds_18_bits_addr;
  wire  model_channels_read_cmds_19_ready;
  wire  model_channels_read_cmds_19_valid;
  wire [8:0] model_channels_read_cmds_19_bits_addr;
  wire  model_channels_read_cmds_20_ready;
  wire  model_channels_read_cmds_20_valid;
  wire [8:0] model_channels_read_cmds_20_bits_addr;
  wire  model_channels_read_cmds_21_ready;
  wire  model_channels_read_cmds_21_valid;
  wire [8:0] model_channels_read_cmds_21_bits_addr;
  wire  model_channels_read_cmds_22_ready;
  wire  model_channels_read_cmds_22_valid;
  wire [8:0] model_channels_read_cmds_22_bits_addr;
  wire  model_channels_read_cmds_23_ready;
  wire  model_channels_read_cmds_23_valid;
  wire [8:0] model_channels_read_cmds_23_bits_addr;
  wire  model_channels_read_cmds_24_ready;
  wire  model_channels_read_cmds_24_valid;
  wire [8:0] model_channels_read_cmds_24_bits_addr;
  wire  model_channels_read_cmds_25_ready;
  wire  model_channels_read_cmds_25_valid;
  wire [8:0] model_channels_read_cmds_25_bits_addr;
  wire  model_channels_read_cmds_26_ready;
  wire  model_channels_read_cmds_26_valid;
  wire [8:0] model_channels_read_cmds_26_bits_addr;
  wire  model_channels_read_cmds_27_ready;
  wire  model_channels_read_cmds_27_valid;
  wire [8:0] model_channels_read_cmds_27_bits_addr;
  wire  model_channels_read_cmds_28_ready;
  wire  model_channels_read_cmds_28_valid;
  wire [8:0] model_channels_read_cmds_28_bits_addr;
  wire  model_channels_read_cmds_29_ready;
  wire  model_channels_read_cmds_29_valid;
  wire [8:0] model_channels_read_cmds_29_bits_addr;
  wire  model_channels_read_cmds_30_ready;
  wire  model_channels_read_cmds_30_valid;
  wire [8:0] model_channels_read_cmds_30_bits_addr;
  wire  model_channels_read_cmds_31_ready;
  wire  model_channels_read_cmds_31_valid;
  wire [8:0] model_channels_read_cmds_31_bits_addr;
  wire  model_channels_read_cmds_32_ready;
  wire  model_channels_read_cmds_32_valid;
  wire [8:0] model_channels_read_cmds_32_bits_addr;
  wire  model_channels_read_cmds_33_ready;
  wire  model_channels_read_cmds_33_valid;
  wire [8:0] model_channels_read_cmds_33_bits_addr;
  wire  model_channels_read_cmds_34_ready;
  wire  model_channels_read_cmds_34_valid;
  wire [8:0] model_channels_read_cmds_34_bits_addr;
  wire  model_channels_read_resps_0_ready;
  wire  model_channels_read_resps_0_valid;
  wire [80:0] model_channels_read_resps_0_bits;
  wire  model_channels_read_resps_1_ready;
  wire  model_channels_read_resps_1_valid;
  wire [80:0] model_channels_read_resps_1_bits;
  wire  model_channels_read_resps_2_ready;
  wire  model_channels_read_resps_2_valid;
  wire [80:0] model_channels_read_resps_2_bits;
  wire  model_channels_read_resps_3_ready;
  wire  model_channels_read_resps_3_valid;
  wire [80:0] model_channels_read_resps_3_bits;
  wire  model_channels_read_resps_4_ready;
  wire  model_channels_read_resps_4_valid;
  wire [80:0] model_channels_read_resps_4_bits;
  wire  model_channels_read_resps_5_ready;
  wire  model_channels_read_resps_5_valid;
  wire [80:0] model_channels_read_resps_5_bits;
  wire  model_channels_read_resps_6_ready;
  wire  model_channels_read_resps_6_valid;
  wire [80:0] model_channels_read_resps_6_bits;
  wire  model_channels_read_resps_7_ready;
  wire  model_channels_read_resps_7_valid;
  wire [80:0] model_channels_read_resps_7_bits;
  wire  model_channels_read_resps_8_ready;
  wire  model_channels_read_resps_8_valid;
  wire [80:0] model_channels_read_resps_8_bits;
  wire  model_channels_read_resps_9_ready;
  wire  model_channels_read_resps_9_valid;
  wire [80:0] model_channels_read_resps_9_bits;
  wire  model_channels_read_resps_10_ready;
  wire  model_channels_read_resps_10_valid;
  wire [80:0] model_channels_read_resps_10_bits;
  wire  model_channels_read_resps_11_ready;
  wire  model_channels_read_resps_11_valid;
  wire [80:0] model_channels_read_resps_11_bits;
  wire  model_channels_read_resps_12_ready;
  wire  model_channels_read_resps_12_valid;
  wire [80:0] model_channels_read_resps_12_bits;
  wire  model_channels_read_resps_13_ready;
  wire  model_channels_read_resps_13_valid;
  wire [80:0] model_channels_read_resps_13_bits;
  wire  model_channels_read_resps_14_ready;
  wire  model_channels_read_resps_14_valid;
  wire [80:0] model_channels_read_resps_14_bits;
  wire  model_channels_read_resps_15_ready;
  wire  model_channels_read_resps_15_valid;
  wire [80:0] model_channels_read_resps_15_bits;
  wire  model_channels_read_resps_16_ready;
  wire  model_channels_read_resps_16_valid;
  wire [80:0] model_channels_read_resps_16_bits;
  wire  model_channels_read_resps_17_ready;
  wire  model_channels_read_resps_17_valid;
  wire [80:0] model_channels_read_resps_17_bits;
  wire  model_channels_read_resps_18_ready;
  wire  model_channels_read_resps_18_valid;
  wire [80:0] model_channels_read_resps_18_bits;
  wire  model_channels_read_resps_19_ready;
  wire  model_channels_read_resps_19_valid;
  wire [80:0] model_channels_read_resps_19_bits;
  wire  model_channels_read_resps_20_ready;
  wire  model_channels_read_resps_20_valid;
  wire [80:0] model_channels_read_resps_20_bits;
  wire  model_channels_read_resps_21_ready;
  wire  model_channels_read_resps_21_valid;
  wire [80:0] model_channels_read_resps_21_bits;
  wire  model_channels_read_resps_22_ready;
  wire  model_channels_read_resps_22_valid;
  wire [80:0] model_channels_read_resps_22_bits;
  wire  model_channels_read_resps_23_ready;
  wire  model_channels_read_resps_23_valid;
  wire [80:0] model_channels_read_resps_23_bits;
  wire  model_channels_read_resps_24_ready;
  wire  model_channels_read_resps_24_valid;
  wire [80:0] model_channels_read_resps_24_bits;
  wire  model_channels_read_resps_25_ready;
  wire  model_channels_read_resps_25_valid;
  wire [80:0] model_channels_read_resps_25_bits;
  wire  model_channels_read_resps_26_ready;
  wire  model_channels_read_resps_26_valid;
  wire [80:0] model_channels_read_resps_26_bits;
  wire  model_channels_read_resps_27_ready;
  wire  model_channels_read_resps_27_valid;
  wire [80:0] model_channels_read_resps_27_bits;
  wire  model_channels_read_resps_28_ready;
  wire  model_channels_read_resps_28_valid;
  wire [80:0] model_channels_read_resps_28_bits;
  wire  model_channels_read_resps_29_ready;
  wire  model_channels_read_resps_29_valid;
  wire [80:0] model_channels_read_resps_29_bits;
  wire  model_channels_read_resps_30_ready;
  wire  model_channels_read_resps_30_valid;
  wire [80:0] model_channels_read_resps_30_bits;
  wire  model_channels_read_resps_31_ready;
  wire  model_channels_read_resps_31_valid;
  wire [80:0] model_channels_read_resps_31_bits;
  wire  model_channels_read_resps_32_ready;
  wire  model_channels_read_resps_32_valid;
  wire [80:0] model_channels_read_resps_32_bits;
  wire  model_channels_read_resps_33_ready;
  wire  model_channels_read_resps_33_valid;
  wire [80:0] model_channels_read_resps_33_bits;
  wire  model_channels_read_resps_34_ready;
  wire  model_channels_read_resps_34_valid;
  wire [80:0] model_channels_read_resps_34_bits;
  wire  model_channels_write_cmds_0_ready;
  wire  model_channels_write_cmds_0_valid;
  wire  model_channels_write_cmds_0_bits_en;
  wire  model_channels_write_cmds_0_bits_mask;
  wire [8:0] model_channels_write_cmds_0_bits_addr;
  wire [80:0] model_channels_write_cmds_0_bits_data;
  RamModel model (
    .clock(model_clock),
    .reset(model_reset),
    .channels_read_cmds_0_ready(model_channels_read_cmds_0_ready),
    .channels_read_cmds_0_valid(model_channels_read_cmds_0_valid),
    .channels_read_cmds_0_bits_addr(model_channels_read_cmds_0_bits_addr),
    .channels_read_cmds_1_ready(model_channels_read_cmds_1_ready),
    .channels_read_cmds_1_valid(model_channels_read_cmds_1_valid),
    .channels_read_cmds_1_bits_addr(model_channels_read_cmds_1_bits_addr),
    .channels_read_cmds_2_ready(model_channels_read_cmds_2_ready),
    .channels_read_cmds_2_valid(model_channels_read_cmds_2_valid),
    .channels_read_cmds_2_bits_addr(model_channels_read_cmds_2_bits_addr),
    .channels_read_cmds_3_ready(model_channels_read_cmds_3_ready),
    .channels_read_cmds_3_valid(model_channels_read_cmds_3_valid),
    .channels_read_cmds_3_bits_addr(model_channels_read_cmds_3_bits_addr),
    .channels_read_cmds_4_ready(model_channels_read_cmds_4_ready),
    .channels_read_cmds_4_valid(model_channels_read_cmds_4_valid),
    .channels_read_cmds_4_bits_addr(model_channels_read_cmds_4_bits_addr),
    .channels_read_cmds_5_ready(model_channels_read_cmds_5_ready),
    .channels_read_cmds_5_valid(model_channels_read_cmds_5_valid),
    .channels_read_cmds_5_bits_addr(model_channels_read_cmds_5_bits_addr),
    .channels_read_cmds_6_ready(model_channels_read_cmds_6_ready),
    .channels_read_cmds_6_valid(model_channels_read_cmds_6_valid),
    .channels_read_cmds_6_bits_addr(model_channels_read_cmds_6_bits_addr),
    .channels_read_cmds_7_ready(model_channels_read_cmds_7_ready),
    .channels_read_cmds_7_valid(model_channels_read_cmds_7_valid),
    .channels_read_cmds_7_bits_addr(model_channels_read_cmds_7_bits_addr),
    .channels_read_cmds_8_ready(model_channels_read_cmds_8_ready),
    .channels_read_cmds_8_valid(model_channels_read_cmds_8_valid),
    .channels_read_cmds_8_bits_addr(model_channels_read_cmds_8_bits_addr),
    .channels_read_cmds_9_ready(model_channels_read_cmds_9_ready),
    .channels_read_cmds_9_valid(model_channels_read_cmds_9_valid),
    .channels_read_cmds_9_bits_addr(model_channels_read_cmds_9_bits_addr),
    .channels_read_cmds_10_ready(model_channels_read_cmds_10_ready),
    .channels_read_cmds_10_valid(model_channels_read_cmds_10_valid),
    .channels_read_cmds_10_bits_addr(model_channels_read_cmds_10_bits_addr),
    .channels_read_cmds_11_ready(model_channels_read_cmds_11_ready),
    .channels_read_cmds_11_valid(model_channels_read_cmds_11_valid),
    .channels_read_cmds_11_bits_addr(model_channels_read_cmds_11_bits_addr),
    .channels_read_cmds_12_ready(model_channels_read_cmds_12_ready),
    .channels_read_cmds_12_valid(model_channels_read_cmds_12_valid),
    .channels_read_cmds_12_bits_addr(model_channels_read_cmds_12_bits_addr),
    .channels_read_cmds_13_ready(model_channels_read_cmds_13_ready),
    .channels_read_cmds_13_valid(model_channels_read_cmds_13_valid),
    .channels_read_cmds_13_bits_addr(model_channels_read_cmds_13_bits_addr),
    .channels_read_cmds_14_ready(model_channels_read_cmds_14_ready),
    .channels_read_cmds_14_valid(model_channels_read_cmds_14_valid),
    .channels_read_cmds_14_bits_addr(model_channels_read_cmds_14_bits_addr),
    .channels_read_cmds_15_ready(model_channels_read_cmds_15_ready),
    .channels_read_cmds_15_valid(model_channels_read_cmds_15_valid),
    .channels_read_cmds_15_bits_addr(model_channels_read_cmds_15_bits_addr),
    .channels_read_cmds_16_ready(model_channels_read_cmds_16_ready),
    .channels_read_cmds_16_valid(model_channels_read_cmds_16_valid),
    .channels_read_cmds_16_bits_addr(model_channels_read_cmds_16_bits_addr),
    .channels_read_cmds_17_ready(model_channels_read_cmds_17_ready),
    .channels_read_cmds_17_valid(model_channels_read_cmds_17_valid),
    .channels_read_cmds_17_bits_addr(model_channels_read_cmds_17_bits_addr),
    .channels_read_cmds_18_ready(model_channels_read_cmds_18_ready),
    .channels_read_cmds_18_valid(model_channels_read_cmds_18_valid),
    .channels_read_cmds_18_bits_addr(model_channels_read_cmds_18_bits_addr),
    .channels_read_cmds_19_ready(model_channels_read_cmds_19_ready),
    .channels_read_cmds_19_valid(model_channels_read_cmds_19_valid),
    .channels_read_cmds_19_bits_addr(model_channels_read_cmds_19_bits_addr),
    .channels_read_cmds_20_ready(model_channels_read_cmds_20_ready),
    .channels_read_cmds_20_valid(model_channels_read_cmds_20_valid),
    .channels_read_cmds_20_bits_addr(model_channels_read_cmds_20_bits_addr),
    .channels_read_cmds_21_ready(model_channels_read_cmds_21_ready),
    .channels_read_cmds_21_valid(model_channels_read_cmds_21_valid),
    .channels_read_cmds_21_bits_addr(model_channels_read_cmds_21_bits_addr),
    .channels_read_cmds_22_ready(model_channels_read_cmds_22_ready),
    .channels_read_cmds_22_valid(model_channels_read_cmds_22_valid),
    .channels_read_cmds_22_bits_addr(model_channels_read_cmds_22_bits_addr),
    .channels_read_cmds_23_ready(model_channels_read_cmds_23_ready),
    .channels_read_cmds_23_valid(model_channels_read_cmds_23_valid),
    .channels_read_cmds_23_bits_addr(model_channels_read_cmds_23_bits_addr),
    .channels_read_cmds_24_ready(model_channels_read_cmds_24_ready),
    .channels_read_cmds_24_valid(model_channels_read_cmds_24_valid),
    .channels_read_cmds_24_bits_addr(model_channels_read_cmds_24_bits_addr),
    .channels_read_cmds_25_ready(model_channels_read_cmds_25_ready),
    .channels_read_cmds_25_valid(model_channels_read_cmds_25_valid),
    .channels_read_cmds_25_bits_addr(model_channels_read_cmds_25_bits_addr),
    .channels_read_cmds_26_ready(model_channels_read_cmds_26_ready),
    .channels_read_cmds_26_valid(model_channels_read_cmds_26_valid),
    .channels_read_cmds_26_bits_addr(model_channels_read_cmds_26_bits_addr),
    .channels_read_cmds_27_ready(model_channels_read_cmds_27_ready),
    .channels_read_cmds_27_valid(model_channels_read_cmds_27_valid),
    .channels_read_cmds_27_bits_addr(model_channels_read_cmds_27_bits_addr),
    .channels_read_cmds_28_ready(model_channels_read_cmds_28_ready),
    .channels_read_cmds_28_valid(model_channels_read_cmds_28_valid),
    .channels_read_cmds_28_bits_addr(model_channels_read_cmds_28_bits_addr),
    .channels_read_cmds_29_ready(model_channels_read_cmds_29_ready),
    .channels_read_cmds_29_valid(model_channels_read_cmds_29_valid),
    .channels_read_cmds_29_bits_addr(model_channels_read_cmds_29_bits_addr),
    .channels_read_cmds_30_ready(model_channels_read_cmds_30_ready),
    .channels_read_cmds_30_valid(model_channels_read_cmds_30_valid),
    .channels_read_cmds_30_bits_addr(model_channels_read_cmds_30_bits_addr),
    .channels_read_cmds_31_ready(model_channels_read_cmds_31_ready),
    .channels_read_cmds_31_valid(model_channels_read_cmds_31_valid),
    .channels_read_cmds_31_bits_addr(model_channels_read_cmds_31_bits_addr),
    .channels_read_cmds_32_ready(model_channels_read_cmds_32_ready),
    .channels_read_cmds_32_valid(model_channels_read_cmds_32_valid),
    .channels_read_cmds_32_bits_addr(model_channels_read_cmds_32_bits_addr),
    .channels_read_cmds_33_ready(model_channels_read_cmds_33_ready),
    .channels_read_cmds_33_valid(model_channels_read_cmds_33_valid),
    .channels_read_cmds_33_bits_addr(model_channels_read_cmds_33_bits_addr),
    .channels_read_cmds_34_ready(model_channels_read_cmds_34_ready),
    .channels_read_cmds_34_valid(model_channels_read_cmds_34_valid),
    .channels_read_cmds_34_bits_addr(model_channels_read_cmds_34_bits_addr),
    .channels_read_resps_0_ready(model_channels_read_resps_0_ready),
    .channels_read_resps_0_valid(model_channels_read_resps_0_valid),
    .channels_read_resps_0_bits(model_channels_read_resps_0_bits),
    .channels_read_resps_1_ready(model_channels_read_resps_1_ready),
    .channels_read_resps_1_valid(model_channels_read_resps_1_valid),
    .channels_read_resps_1_bits(model_channels_read_resps_1_bits),
    .channels_read_resps_2_ready(model_channels_read_resps_2_ready),
    .channels_read_resps_2_valid(model_channels_read_resps_2_valid),
    .channels_read_resps_2_bits(model_channels_read_resps_2_bits),
    .channels_read_resps_3_ready(model_channels_read_resps_3_ready),
    .channels_read_resps_3_valid(model_channels_read_resps_3_valid),
    .channels_read_resps_3_bits(model_channels_read_resps_3_bits),
    .channels_read_resps_4_ready(model_channels_read_resps_4_ready),
    .channels_read_resps_4_valid(model_channels_read_resps_4_valid),
    .channels_read_resps_4_bits(model_channels_read_resps_4_bits),
    .channels_read_resps_5_ready(model_channels_read_resps_5_ready),
    .channels_read_resps_5_valid(model_channels_read_resps_5_valid),
    .channels_read_resps_5_bits(model_channels_read_resps_5_bits),
    .channels_read_resps_6_ready(model_channels_read_resps_6_ready),
    .channels_read_resps_6_valid(model_channels_read_resps_6_valid),
    .channels_read_resps_6_bits(model_channels_read_resps_6_bits),
    .channels_read_resps_7_ready(model_channels_read_resps_7_ready),
    .channels_read_resps_7_valid(model_channels_read_resps_7_valid),
    .channels_read_resps_7_bits(model_channels_read_resps_7_bits),
    .channels_read_resps_8_ready(model_channels_read_resps_8_ready),
    .channels_read_resps_8_valid(model_channels_read_resps_8_valid),
    .channels_read_resps_8_bits(model_channels_read_resps_8_bits),
    .channels_read_resps_9_ready(model_channels_read_resps_9_ready),
    .channels_read_resps_9_valid(model_channels_read_resps_9_valid),
    .channels_read_resps_9_bits(model_channels_read_resps_9_bits),
    .channels_read_resps_10_ready(model_channels_read_resps_10_ready),
    .channels_read_resps_10_valid(model_channels_read_resps_10_valid),
    .channels_read_resps_10_bits(model_channels_read_resps_10_bits),
    .channels_read_resps_11_ready(model_channels_read_resps_11_ready),
    .channels_read_resps_11_valid(model_channels_read_resps_11_valid),
    .channels_read_resps_11_bits(model_channels_read_resps_11_bits),
    .channels_read_resps_12_ready(model_channels_read_resps_12_ready),
    .channels_read_resps_12_valid(model_channels_read_resps_12_valid),
    .channels_read_resps_12_bits(model_channels_read_resps_12_bits),
    .channels_read_resps_13_ready(model_channels_read_resps_13_ready),
    .channels_read_resps_13_valid(model_channels_read_resps_13_valid),
    .channels_read_resps_13_bits(model_channels_read_resps_13_bits),
    .channels_read_resps_14_ready(model_channels_read_resps_14_ready),
    .channels_read_resps_14_valid(model_channels_read_resps_14_valid),
    .channels_read_resps_14_bits(model_channels_read_resps_14_bits),
    .channels_read_resps_15_ready(model_channels_read_resps_15_ready),
    .channels_read_resps_15_valid(model_channels_read_resps_15_valid),
    .channels_read_resps_15_bits(model_channels_read_resps_15_bits),
    .channels_read_resps_16_ready(model_channels_read_resps_16_ready),
    .channels_read_resps_16_valid(model_channels_read_resps_16_valid),
    .channels_read_resps_16_bits(model_channels_read_resps_16_bits),
    .channels_read_resps_17_ready(model_channels_read_resps_17_ready),
    .channels_read_resps_17_valid(model_channels_read_resps_17_valid),
    .channels_read_resps_17_bits(model_channels_read_resps_17_bits),
    .channels_read_resps_18_ready(model_channels_read_resps_18_ready),
    .channels_read_resps_18_valid(model_channels_read_resps_18_valid),
    .channels_read_resps_18_bits(model_channels_read_resps_18_bits),
    .channels_read_resps_19_ready(model_channels_read_resps_19_ready),
    .channels_read_resps_19_valid(model_channels_read_resps_19_valid),
    .channels_read_resps_19_bits(model_channels_read_resps_19_bits),
    .channels_read_resps_20_ready(model_channels_read_resps_20_ready),
    .channels_read_resps_20_valid(model_channels_read_resps_20_valid),
    .channels_read_resps_20_bits(model_channels_read_resps_20_bits),
    .channels_read_resps_21_ready(model_channels_read_resps_21_ready),
    .channels_read_resps_21_valid(model_channels_read_resps_21_valid),
    .channels_read_resps_21_bits(model_channels_read_resps_21_bits),
    .channels_read_resps_22_ready(model_channels_read_resps_22_ready),
    .channels_read_resps_22_valid(model_channels_read_resps_22_valid),
    .channels_read_resps_22_bits(model_channels_read_resps_22_bits),
    .channels_read_resps_23_ready(model_channels_read_resps_23_ready),
    .channels_read_resps_23_valid(model_channels_read_resps_23_valid),
    .channels_read_resps_23_bits(model_channels_read_resps_23_bits),
    .channels_read_resps_24_ready(model_channels_read_resps_24_ready),
    .channels_read_resps_24_valid(model_channels_read_resps_24_valid),
    .channels_read_resps_24_bits(model_channels_read_resps_24_bits),
    .channels_read_resps_25_ready(model_channels_read_resps_25_ready),
    .channels_read_resps_25_valid(model_channels_read_resps_25_valid),
    .channels_read_resps_25_bits(model_channels_read_resps_25_bits),
    .channels_read_resps_26_ready(model_channels_read_resps_26_ready),
    .channels_read_resps_26_valid(model_channels_read_resps_26_valid),
    .channels_read_resps_26_bits(model_channels_read_resps_26_bits),
    .channels_read_resps_27_ready(model_channels_read_resps_27_ready),
    .channels_read_resps_27_valid(model_channels_read_resps_27_valid),
    .channels_read_resps_27_bits(model_channels_read_resps_27_bits),
    .channels_read_resps_28_ready(model_channels_read_resps_28_ready),
    .channels_read_resps_28_valid(model_channels_read_resps_28_valid),
    .channels_read_resps_28_bits(model_channels_read_resps_28_bits),
    .channels_read_resps_29_ready(model_channels_read_resps_29_ready),
    .channels_read_resps_29_valid(model_channels_read_resps_29_valid),
    .channels_read_resps_29_bits(model_channels_read_resps_29_bits),
    .channels_read_resps_30_ready(model_channels_read_resps_30_ready),
    .channels_read_resps_30_valid(model_channels_read_resps_30_valid),
    .channels_read_resps_30_bits(model_channels_read_resps_30_bits),
    .channels_read_resps_31_ready(model_channels_read_resps_31_ready),
    .channels_read_resps_31_valid(model_channels_read_resps_31_valid),
    .channels_read_resps_31_bits(model_channels_read_resps_31_bits),
    .channels_read_resps_32_ready(model_channels_read_resps_32_ready),
    .channels_read_resps_32_valid(model_channels_read_resps_32_valid),
    .channels_read_resps_32_bits(model_channels_read_resps_32_bits),
    .channels_read_resps_33_ready(model_channels_read_resps_33_ready),
    .channels_read_resps_33_valid(model_channels_read_resps_33_valid),
    .channels_read_resps_33_bits(model_channels_read_resps_33_bits),
    .channels_read_resps_34_ready(model_channels_read_resps_34_ready),
    .channels_read_resps_34_valid(model_channels_read_resps_34_valid),
    .channels_read_resps_34_bits(model_channels_read_resps_34_bits),
    .channels_write_cmds_0_ready(model_channels_write_cmds_0_ready),
    .channels_write_cmds_0_valid(model_channels_write_cmds_0_valid),
    .channels_write_cmds_0_bits_en(model_channels_write_cmds_0_bits_en),
    .channels_write_cmds_0_bits_mask(model_channels_write_cmds_0_bits_mask),
    .channels_write_cmds_0_bits_addr(model_channels_write_cmds_0_bits_addr),
    .channels_write_cmds_0_bits_data(model_channels_write_cmds_0_bits_data)
  );
  assign MPORT_5_addr_sink_ready = model_channels_read_cmds_9_ready & MPORT_5_en_sink_valid;
  assign crossPackagePendingKey_MPORT_addr_sink_ready = model_channels_read_cmds_13_ready &
    crossPackagePendingKey_MPORT_en_sink_valid;
  assign MPORT_14_addr_sink_ready = model_channels_read_cmds_17_ready & MPORT_14_en_sink_valid;
  assign slowdown_opt1_pending_live_key_MPORT_addr_sink_ready = model_channels_read_cmds_16_ready &
    slowdown_opt1_pending_live_key_MPORT_en_sink_valid;
  assign s3_l1PreservationAllowed_MPORT_addr_sink_ready = model_channels_read_cmds_12_ready &
    s3_l1PreservationAllowed_MPORT_en_sink_valid;
  assign crossPackagePendingSeq_MPORT_en_sink_ready = model_channels_read_cmds_24_ready &
    crossPackagePendingSeq_MPORT_addr_sink_valid;
  assign refillPreservationAllowed_MPORT_addr_sink_ready = model_channels_read_cmds_25_ready &
    refillPreservationAllowed_MPORT_en_sink_valid;
  assign crossPackageWbReq_valid_MPORT_en_sink_ready = model_channels_read_cmds_19_ready &
    crossPackageWbReq_valid_MPORT_addr_sink_valid;
  assign MPORT_6_en_sink_ready = model_channels_read_cmds_8_ready & MPORT_6_addr_sink_valid;
  assign crossPackageResidentMatch_MPORT_addr_sink_ready = model_channels_read_cmds_7_ready &
    crossPackageResidentMatch_MPORT_en_sink_valid;
  assign crossPackageWbPacketSeq_MPORT_addr_sink_ready = model_channels_read_cmds_1_ready &
    crossPackageWbPacketSeq_MPORT_en_sink_valid;
  assign crossPackageSvbRescue_MPORT_2_en_sink_ready = model_channels_read_cmds_18_ready &
    crossPackageSvbRescue_MPORT_2_addr_sink_valid;
  assign MPORT_15_addr_sink_ready = model_channels_read_cmds_31_ready & MPORT_15_en_sink_valid;
  assign MPORT_16_en_sink_ready = model_channels_read_cmds_30_ready & MPORT_16_addr_sink_valid;
  assign MPORT_16_addr_sink_ready = model_channels_read_cmds_30_ready & MPORT_16_en_sink_valid;
  assign MPORT_10_addr_sink_ready = model_channels_read_cmds_10_ready & MPORT_10_en_sink_valid;
  assign crossPackageWbReq_valid_MPORT_addr_sink_ready = model_channels_read_cmds_19_ready &
    crossPackageWbReq_valid_MPORT_en_sink_valid;
  assign opt2bWriteKey_MPORT_en_sink_ready = model_channels_read_cmds_6_ready & opt2bWriteKey_MPORT_addr_sink_valid;
  assign svbCaptureResidentMatch_MPORT_addr_sink_ready = model_channels_read_cmds_22_ready &
    svbCaptureResidentMatch_MPORT_en_sink_valid;
  assign s3_l1PreservationAllowed_MPORT_en_sink_ready = model_channels_read_cmds_12_ready &
    s3_l1PreservationAllowed_MPORT_addr_sink_valid;
  assign MPORT_9_en_sink_ready = model_channels_read_cmds_21_ready & MPORT_9_addr_sink_valid;
  assign MPORT_data_sink_ready = model_channels_write_cmds_0_ready & MPORT_mask_sink_valid & MPORT_addr_sink_valid &
    MPORT_en_sink_valid;
  assign crossPackageWbPacketSeq_MPORT_en_sink_ready = model_channels_read_cmds_1_ready &
    crossPackageWbPacketSeq_MPORT_addr_sink_valid;
  assign MPORT_12_addr_sink_ready = model_channels_read_cmds_32_ready & MPORT_12_en_sink_valid;
  assign preservationWaitWatermark_MPORT_en_sink_ready = model_channels_read_cmds_34_ready &
    preservationWaitWatermark_MPORT_addr_sink_valid;
  assign safeChainLiveKey_MPORT_en_sink_ready = model_channels_read_cmds_2_ready &
    safeChainLiveKey_MPORT_addr_sink_valid;
  assign MPORT_15_en_sink_ready = model_channels_read_cmds_31_ready & MPORT_15_addr_sink_valid;
  assign clearFreezeReadBypassWindow_MPORT_addr_sink_ready = model_channels_read_cmds_28_ready &
    clearFreezeReadBypassWindow_MPORT_en_sink_valid;
  assign svbFastKey_MPORT_en_sink_ready = model_channels_read_cmds_4_ready & svbFastKey_MPORT_addr_sink_valid;
  assign crossPackagePendingSeq_MPORT_addr_sink_ready = model_channels_read_cmds_24_ready &
    crossPackagePendingSeq_MPORT_en_sink_valid;
  assign MPORT_4_en_sink_ready = model_channels_read_cmds_23_ready & MPORT_4_addr_sink_valid;
  assign MPORT_17_en_sink_ready = model_channels_read_cmds_29_ready & MPORT_17_addr_sink_valid;
  assign clearFreezeReadBypassWindow_MPORT_en_sink_ready = model_channels_read_cmds_28_ready &
    clearFreezeReadBypassWindow_MPORT_addr_sink_valid;
  assign MPORT_addr_sink_ready = model_channels_write_cmds_0_ready & MPORT_data_sink_valid & MPORT_mask_sink_valid &
    MPORT_en_sink_valid;
  assign MPORT_10_en_sink_ready = model_channels_read_cmds_10_ready & MPORT_10_addr_sink_valid;
  assign crossPackageSvbRescue_MPORT_2_addr_sink_ready = model_channels_read_cmds_18_ready &
    crossPackageSvbRescue_MPORT_2_en_sink_valid;
  assign crossPackagePendingKey_MPORT_en_sink_ready = model_channels_read_cmds_13_ready &
    crossPackagePendingKey_MPORT_addr_sink_valid;
  assign slowdown_opt1_pending_safe_MPORT_en_sink_ready = model_channels_read_cmds_20_ready &
    slowdown_opt1_pending_safe_MPORT_addr_sink_valid;
  assign installPreservationAllowed_MPORT_en_sink_ready = model_channels_read_cmds_33_ready &
    installPreservationAllowed_MPORT_addr_sink_valid;
  assign MPORT_7_addr_sink_ready = model_channels_read_cmds_14_ready & MPORT_7_en_sink_valid;
  assign slowdown_opt1_pending_safe_MPORT_addr_sink_ready = model_channels_read_cmds_20_ready &
    slowdown_opt1_pending_safe_MPORT_en_sink_valid;
  assign MPORT_en_sink_ready = model_channels_write_cmds_0_ready & MPORT_data_sink_valid & MPORT_mask_sink_valid &
    MPORT_addr_sink_valid;
  assign crossPackageSvbRescue_MPORT_1_en_sink_ready = model_channels_read_cmds_3_ready &
    crossPackageSvbRescue_MPORT_1_addr_sink_valid;
  assign opt2bWriteKey_MPORT_addr_sink_ready = model_channels_read_cmds_6_ready & opt2bWriteKey_MPORT_en_sink_valid;
  assign svbCaptureResidentMatch_MPORT_en_sink_ready = model_channels_read_cmds_22_ready &
    svbCaptureResidentMatch_MPORT_addr_sink_valid;
  assign MPORT_7_en_sink_ready = model_channels_read_cmds_14_ready & MPORT_7_addr_sink_valid;
  assign wb_io_image_key_MPORT_addr_sink_ready = model_channels_read_cmds_26_ready & wb_io_image_key_MPORT_en_sink_valid
    ;
  assign svbFastKey_MPORT_addr_sink_ready = model_channels_read_cmds_4_ready & svbFastKey_MPORT_en_sink_valid;
  assign MPORT_14_en_sink_ready = model_channels_read_cmds_17_ready & MPORT_14_addr_sink_valid;
  assign preservationWaitWatermark_MPORT_addr_sink_ready = model_channels_read_cmds_34_ready &
    preservationWaitWatermark_MPORT_en_sink_valid;
  assign MPORT_18_addr_sink_ready = model_channels_read_cmds_0_ready & MPORT_18_en_sink_valid;
  assign MPORT_6_addr_sink_ready = model_channels_read_cmds_8_ready & MPORT_6_en_sink_valid;
  assign slowdown_opt1_pending_live_key_MPORT_en_sink_ready = model_channels_read_cmds_16_ready &
    slowdown_opt1_pending_live_key_MPORT_addr_sink_valid;
  assign MPORT_12_en_sink_ready = model_channels_read_cmds_32_ready & MPORT_12_addr_sink_valid;
  assign crossPackageSvbRescue_MPORT_en_sink_ready = model_channels_read_cmds_5_ready &
    crossPackageSvbRescue_MPORT_addr_sink_valid;
  assign MPORT_8_addr_sink_ready = model_channels_read_cmds_11_ready & MPORT_8_en_sink_valid;
  assign MPORT_17_addr_sink_ready = model_channels_read_cmds_29_ready & MPORT_17_en_sink_valid;
  assign wb_io_image_key_MPORT_en_sink_ready = model_channels_read_cmds_26_ready & wb_io_image_key_MPORT_addr_sink_valid
    ;
  assign MPORT_8_en_sink_ready = model_channels_read_cmds_11_ready & MPORT_8_addr_sink_valid;
  assign crossPackageSvbRescue_MPORT_addr_sink_ready = model_channels_read_cmds_5_ready &
    crossPackageSvbRescue_MPORT_en_sink_valid;
  assign installPreservationAllowed_MPORT_addr_sink_ready = model_channels_read_cmds_33_ready &
    installPreservationAllowed_MPORT_en_sink_valid;
  assign refillPreservationAllowed_MPORT_en_sink_ready = model_channels_read_cmds_25_ready &
    refillPreservationAllowed_MPORT_addr_sink_valid;
  assign crossPackageSvbRescue_MPORT_1_addr_sink_ready = model_channels_read_cmds_3_ready &
    crossPackageSvbRescue_MPORT_1_en_sink_valid;
  assign s2_overwrittenKey_MPORT_en_sink_ready = model_channels_read_cmds_27_ready &
    s2_overwrittenKey_MPORT_addr_sink_valid;
  assign crossPackageResidentMatch_MPORT_en_sink_ready = model_channels_read_cmds_7_ready &
    crossPackageResidentMatch_MPORT_addr_sink_valid;
  assign MPORT_18_en_sink_ready = model_channels_read_cmds_0_ready & MPORT_18_addr_sink_valid;
  assign MPORT_13_addr_sink_ready = model_channels_read_cmds_15_ready & MPORT_13_en_sink_valid;
  assign safeChainLiveKey_MPORT_addr_sink_ready = model_channels_read_cmds_2_ready &
    safeChainLiveKey_MPORT_en_sink_valid;
  assign MPORT_mask_sink_ready = model_channels_write_cmds_0_ready & MPORT_data_sink_valid & MPORT_addr_sink_valid &
    MPORT_en_sink_valid;
  assign s2_overwrittenKey_MPORT_addr_sink_ready = model_channels_read_cmds_27_ready &
    s2_overwrittenKey_MPORT_en_sink_valid;
  assign MPORT_9_addr_sink_ready = model_channels_read_cmds_21_ready & MPORT_9_en_sink_valid;
  assign MPORT_13_en_sink_ready = model_channels_read_cmds_15_ready & MPORT_13_addr_sink_valid;
  assign MPORT_5_en_sink_ready = model_channels_read_cmds_9_ready & MPORT_5_addr_sink_valid;
  assign MPORT_4_addr_sink_ready = model_channels_read_cmds_23_ready & MPORT_4_en_sink_valid;
  assign MPORT_10_data_source_valid = model_channels_read_resps_10_valid;
  assign MPORT_10_data_source_bits = model_channels_read_resps_10_bits;
  assign crossPackagePendingSeq_MPORT_data_source_valid = model_channels_read_resps_24_valid;
  assign crossPackagePendingSeq_MPORT_data_source_bits = model_channels_read_resps_24_bits;
  assign MPORT_4_data_source_valid = model_channels_read_resps_23_valid;
  assign MPORT_4_data_source_bits = model_channels_read_resps_23_bits;
  assign crossPackageWbPacketSeq_MPORT_data_source_valid = model_channels_read_resps_1_valid;
  assign crossPackageWbPacketSeq_MPORT_data_source_bits = model_channels_read_resps_1_bits;
  assign MPORT_14_data_source_valid = model_channels_read_resps_17_valid;
  assign MPORT_14_data_source_bits = model_channels_read_resps_17_bits;
  assign MPORT_6_data_source_valid = model_channels_read_resps_8_valid;
  assign MPORT_6_data_source_bits = model_channels_read_resps_8_bits;
  assign MPORT_18_data_source_valid = model_channels_read_resps_0_valid;
  assign MPORT_18_data_source_bits = model_channels_read_resps_0_bits;
  assign crossPackageSvbRescue_MPORT_data_source_valid = model_channels_read_resps_5_valid;
  assign crossPackageSvbRescue_MPORT_data_source_bits = model_channels_read_resps_5_bits;
  assign safeChainLiveKey_MPORT_data_source_valid = model_channels_read_resps_2_valid;
  assign safeChainLiveKey_MPORT_data_source_bits = model_channels_read_resps_2_bits;
  assign MPORT_17_data_source_valid = model_channels_read_resps_29_valid;
  assign MPORT_17_data_source_bits = model_channels_read_resps_29_bits;
  assign s3_l1PreservationAllowed_MPORT_data_source_valid = model_channels_read_resps_12_valid;
  assign s3_l1PreservationAllowed_MPORT_data_source_bits = model_channels_read_resps_12_bits;
  assign crossPackageWbReq_valid_MPORT_data_source_valid = model_channels_read_resps_19_valid;
  assign crossPackageWbReq_valid_MPORT_data_source_bits = model_channels_read_resps_19_bits;
  assign svbFastKey_MPORT_data_source_valid = model_channels_read_resps_4_valid;
  assign svbFastKey_MPORT_data_source_bits = model_channels_read_resps_4_bits;
  assign refillPreservationAllowed_MPORT_data_source_valid = model_channels_read_resps_25_valid;
  assign refillPreservationAllowed_MPORT_data_source_bits = model_channels_read_resps_25_bits;
  assign s2_overwrittenKey_MPORT_data_source_valid = model_channels_read_resps_27_valid;
  assign s2_overwrittenKey_MPORT_data_source_bits = model_channels_read_resps_27_bits;
  assign preservationWaitWatermark_MPORT_data_source_valid = model_channels_read_resps_34_valid;
  assign preservationWaitWatermark_MPORT_data_source_bits = model_channels_read_resps_34_bits;
  assign MPORT_8_data_source_valid = model_channels_read_resps_11_valid;
  assign MPORT_8_data_source_bits = model_channels_read_resps_11_bits;
  assign crossPackageSvbRescue_MPORT_1_data_source_valid = model_channels_read_resps_3_valid;
  assign crossPackageSvbRescue_MPORT_1_data_source_bits = model_channels_read_resps_3_bits;
  assign MPORT_16_data_source_valid = model_channels_read_resps_30_valid;
  assign MPORT_16_data_source_bits = model_channels_read_resps_30_bits;
  assign slowdown_opt1_pending_live_key_MPORT_data_source_valid = model_channels_read_resps_16_valid;
  assign slowdown_opt1_pending_live_key_MPORT_data_source_bits = model_channels_read_resps_16_bits;
  assign MPORT_12_data_source_valid = model_channels_read_resps_32_valid;
  assign MPORT_12_data_source_bits = model_channels_read_resps_32_bits;
  assign MPORT_15_data_source_valid = model_channels_read_resps_31_valid;
  assign MPORT_15_data_source_bits = model_channels_read_resps_31_bits;
  assign opt2bWriteKey_MPORT_data_source_valid = model_channels_read_resps_6_valid;
  assign opt2bWriteKey_MPORT_data_source_bits = model_channels_read_resps_6_bits;
  assign MPORT_9_data_source_valid = model_channels_read_resps_21_valid;
  assign MPORT_9_data_source_bits = model_channels_read_resps_21_bits;
  assign crossPackageSvbRescue_MPORT_2_data_source_valid = model_channels_read_resps_18_valid;
  assign crossPackageSvbRescue_MPORT_2_data_source_bits = model_channels_read_resps_18_bits;
  assign MPORT_13_data_source_valid = model_channels_read_resps_15_valid;
  assign MPORT_13_data_source_bits = model_channels_read_resps_15_bits;
  assign slowdown_opt1_pending_safe_MPORT_data_source_valid = model_channels_read_resps_20_valid;
  assign slowdown_opt1_pending_safe_MPORT_data_source_bits = model_channels_read_resps_20_bits;
  assign wb_io_image_key_MPORT_data_source_valid = model_channels_read_resps_26_valid;
  assign wb_io_image_key_MPORT_data_source_bits = model_channels_read_resps_26_bits;
  assign MPORT_5_data_source_valid = model_channels_read_resps_9_valid;
  assign MPORT_5_data_source_bits = model_channels_read_resps_9_bits;
  assign clearFreezeReadBypassWindow_MPORT_data_source_valid = model_channels_read_resps_28_valid;
  assign clearFreezeReadBypassWindow_MPORT_data_source_bits = model_channels_read_resps_28_bits;
  assign svbCaptureResidentMatch_MPORT_data_source_valid = model_channels_read_resps_22_valid;
  assign svbCaptureResidentMatch_MPORT_data_source_bits = model_channels_read_resps_22_bits;
  assign crossPackageResidentMatch_MPORT_data_source_valid = model_channels_read_resps_7_valid;
  assign crossPackageResidentMatch_MPORT_data_source_bits = model_channels_read_resps_7_bits;
  assign installPreservationAllowed_MPORT_data_source_valid = model_channels_read_resps_33_valid;
  assign installPreservationAllowed_MPORT_data_source_bits = model_channels_read_resps_33_bits;
  assign MPORT_7_data_source_valid = model_channels_read_resps_14_valid;
  assign MPORT_7_data_source_bits = model_channels_read_resps_14_bits;
  assign crossPackagePendingKey_MPORT_data_source_valid = model_channels_read_resps_13_valid;
  assign crossPackagePendingKey_MPORT_data_source_bits = model_channels_read_resps_13_bits;
  assign model_clock = hostClock;
  assign model_reset = hostReset;
  assign model_channels_read_cmds_0_valid = MPORT_18_addr_sink_valid & MPORT_18_en_sink_valid;
  assign model_channels_read_cmds_0_bits_addr = MPORT_18_addr_sink_bits;
  assign model_channels_read_cmds_1_valid = crossPackageWbPacketSeq_MPORT_addr_sink_valid &
    crossPackageWbPacketSeq_MPORT_en_sink_valid;
  assign model_channels_read_cmds_1_bits_addr = crossPackageWbPacketSeq_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_2_valid = safeChainLiveKey_MPORT_addr_sink_valid &
    safeChainLiveKey_MPORT_en_sink_valid;
  assign model_channels_read_cmds_2_bits_addr = safeChainLiveKey_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_3_valid = crossPackageSvbRescue_MPORT_1_addr_sink_valid &
    crossPackageSvbRescue_MPORT_1_en_sink_valid;
  assign model_channels_read_cmds_3_bits_addr = crossPackageSvbRescue_MPORT_1_addr_sink_bits;
  assign model_channels_read_cmds_4_valid = svbFastKey_MPORT_addr_sink_valid & svbFastKey_MPORT_en_sink_valid;
  assign model_channels_read_cmds_4_bits_addr = svbFastKey_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_5_valid = crossPackageSvbRescue_MPORT_addr_sink_valid &
    crossPackageSvbRescue_MPORT_en_sink_valid;
  assign model_channels_read_cmds_5_bits_addr = crossPackageSvbRescue_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_6_valid = opt2bWriteKey_MPORT_addr_sink_valid & opt2bWriteKey_MPORT_en_sink_valid;
  assign model_channels_read_cmds_6_bits_addr = opt2bWriteKey_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_7_valid = crossPackageResidentMatch_MPORT_addr_sink_valid &
    crossPackageResidentMatch_MPORT_en_sink_valid;
  assign model_channels_read_cmds_7_bits_addr = crossPackageResidentMatch_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_8_valid = MPORT_6_addr_sink_valid & MPORT_6_en_sink_valid;
  assign model_channels_read_cmds_8_bits_addr = MPORT_6_addr_sink_bits;
  assign model_channels_read_cmds_9_valid = MPORT_5_addr_sink_valid & MPORT_5_en_sink_valid;
  assign model_channels_read_cmds_9_bits_addr = MPORT_5_addr_sink_bits;
  assign model_channels_read_cmds_10_valid = MPORT_10_addr_sink_valid & MPORT_10_en_sink_valid;
  assign model_channels_read_cmds_10_bits_addr = MPORT_10_addr_sink_bits;
  assign model_channels_read_cmds_11_valid = MPORT_8_addr_sink_valid & MPORT_8_en_sink_valid;
  assign model_channels_read_cmds_11_bits_addr = MPORT_8_addr_sink_bits;
  assign model_channels_read_cmds_12_valid = s3_l1PreservationAllowed_MPORT_addr_sink_valid &
    s3_l1PreservationAllowed_MPORT_en_sink_valid;
  assign model_channels_read_cmds_12_bits_addr = s3_l1PreservationAllowed_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_13_valid = crossPackagePendingKey_MPORT_addr_sink_valid &
    crossPackagePendingKey_MPORT_en_sink_valid;
  assign model_channels_read_cmds_13_bits_addr = crossPackagePendingKey_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_14_valid = MPORT_7_addr_sink_valid & MPORT_7_en_sink_valid;
  assign model_channels_read_cmds_14_bits_addr = MPORT_7_addr_sink_bits;
  assign model_channels_read_cmds_15_valid = MPORT_13_addr_sink_valid & MPORT_13_en_sink_valid;
  assign model_channels_read_cmds_15_bits_addr = MPORT_13_addr_sink_bits;
  assign model_channels_read_cmds_16_valid = slowdown_opt1_pending_live_key_MPORT_addr_sink_valid &
    slowdown_opt1_pending_live_key_MPORT_en_sink_valid;
  assign model_channels_read_cmds_16_bits_addr = slowdown_opt1_pending_live_key_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_17_valid = MPORT_14_addr_sink_valid & MPORT_14_en_sink_valid;
  assign model_channels_read_cmds_17_bits_addr = MPORT_14_addr_sink_bits;
  assign model_channels_read_cmds_18_valid = crossPackageSvbRescue_MPORT_2_addr_sink_valid &
    crossPackageSvbRescue_MPORT_2_en_sink_valid;
  assign model_channels_read_cmds_18_bits_addr = crossPackageSvbRescue_MPORT_2_addr_sink_bits;
  assign model_channels_read_cmds_19_valid = crossPackageWbReq_valid_MPORT_addr_sink_valid &
    crossPackageWbReq_valid_MPORT_en_sink_valid;
  assign model_channels_read_cmds_19_bits_addr = crossPackageWbReq_valid_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_20_valid = slowdown_opt1_pending_safe_MPORT_addr_sink_valid &
    slowdown_opt1_pending_safe_MPORT_en_sink_valid;
  assign model_channels_read_cmds_20_bits_addr = slowdown_opt1_pending_safe_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_21_valid = MPORT_9_addr_sink_valid & MPORT_9_en_sink_valid;
  assign model_channels_read_cmds_21_bits_addr = MPORT_9_addr_sink_bits;
  assign model_channels_read_cmds_22_valid = svbCaptureResidentMatch_MPORT_addr_sink_valid &
    svbCaptureResidentMatch_MPORT_en_sink_valid;
  assign model_channels_read_cmds_22_bits_addr = svbCaptureResidentMatch_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_23_valid = MPORT_4_addr_sink_valid & MPORT_4_en_sink_valid;
  assign model_channels_read_cmds_23_bits_addr = MPORT_4_addr_sink_bits;
  assign model_channels_read_cmds_24_valid = crossPackagePendingSeq_MPORT_addr_sink_valid &
    crossPackagePendingSeq_MPORT_en_sink_valid;
  assign model_channels_read_cmds_24_bits_addr = crossPackagePendingSeq_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_25_valid = refillPreservationAllowed_MPORT_addr_sink_valid &
    refillPreservationAllowed_MPORT_en_sink_valid;
  assign model_channels_read_cmds_25_bits_addr = refillPreservationAllowed_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_26_valid = wb_io_image_key_MPORT_addr_sink_valid & wb_io_image_key_MPORT_en_sink_valid
    ;
  assign model_channels_read_cmds_26_bits_addr = wb_io_image_key_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_27_valid = s2_overwrittenKey_MPORT_addr_sink_valid &
    s2_overwrittenKey_MPORT_en_sink_valid;
  assign model_channels_read_cmds_27_bits_addr = s2_overwrittenKey_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_28_valid = clearFreezeReadBypassWindow_MPORT_addr_sink_valid &
    clearFreezeReadBypassWindow_MPORT_en_sink_valid;
  assign model_channels_read_cmds_28_bits_addr = clearFreezeReadBypassWindow_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_29_valid = MPORT_17_addr_sink_valid & MPORT_17_en_sink_valid;
  assign model_channels_read_cmds_29_bits_addr = MPORT_17_addr_sink_bits;
  assign model_channels_read_cmds_30_valid = MPORT_16_addr_sink_valid & MPORT_16_en_sink_valid;
  assign model_channels_read_cmds_30_bits_addr = MPORT_16_addr_sink_bits;
  assign model_channels_read_cmds_31_valid = MPORT_15_addr_sink_valid & MPORT_15_en_sink_valid;
  assign model_channels_read_cmds_31_bits_addr = MPORT_15_addr_sink_bits;
  assign model_channels_read_cmds_32_valid = MPORT_12_addr_sink_valid & MPORT_12_en_sink_valid;
  assign model_channels_read_cmds_32_bits_addr = MPORT_12_addr_sink_bits;
  assign model_channels_read_cmds_33_valid = installPreservationAllowed_MPORT_addr_sink_valid &
    installPreservationAllowed_MPORT_en_sink_valid;
  assign model_channels_read_cmds_33_bits_addr = installPreservationAllowed_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_34_valid = preservationWaitWatermark_MPORT_addr_sink_valid &
    preservationWaitWatermark_MPORT_en_sink_valid;
  assign model_channels_read_cmds_34_bits_addr = preservationWaitWatermark_MPORT_addr_sink_bits;
  assign model_channels_read_resps_0_ready = MPORT_18_data_source_ready;
  assign model_channels_read_resps_1_ready = crossPackageWbPacketSeq_MPORT_data_source_ready;
  assign model_channels_read_resps_2_ready = safeChainLiveKey_MPORT_data_source_ready;
  assign model_channels_read_resps_3_ready = crossPackageSvbRescue_MPORT_1_data_source_ready;
  assign model_channels_read_resps_4_ready = svbFastKey_MPORT_data_source_ready;
  assign model_channels_read_resps_5_ready = crossPackageSvbRescue_MPORT_data_source_ready;
  assign model_channels_read_resps_6_ready = opt2bWriteKey_MPORT_data_source_ready;
  assign model_channels_read_resps_7_ready = crossPackageResidentMatch_MPORT_data_source_ready;
  assign model_channels_read_resps_8_ready = MPORT_6_data_source_ready;
  assign model_channels_read_resps_9_ready = MPORT_5_data_source_ready;
  assign model_channels_read_resps_10_ready = MPORT_10_data_source_ready;
  assign model_channels_read_resps_11_ready = MPORT_8_data_source_ready;
  assign model_channels_read_resps_12_ready = s3_l1PreservationAllowed_MPORT_data_source_ready;
  assign model_channels_read_resps_13_ready = crossPackagePendingKey_MPORT_data_source_ready;
  assign model_channels_read_resps_14_ready = MPORT_7_data_source_ready;
  assign model_channels_read_resps_15_ready = MPORT_13_data_source_ready;
  assign model_channels_read_resps_16_ready = slowdown_opt1_pending_live_key_MPORT_data_source_ready;
  assign model_channels_read_resps_17_ready = MPORT_14_data_source_ready;
  assign model_channels_read_resps_18_ready = crossPackageSvbRescue_MPORT_2_data_source_ready;
  assign model_channels_read_resps_19_ready = crossPackageWbReq_valid_MPORT_data_source_ready;
  assign model_channels_read_resps_20_ready = slowdown_opt1_pending_safe_MPORT_data_source_ready;
  assign model_channels_read_resps_21_ready = MPORT_9_data_source_ready;
  assign model_channels_read_resps_22_ready = svbCaptureResidentMatch_MPORT_data_source_ready;
  assign model_channels_read_resps_23_ready = MPORT_4_data_source_ready;
  assign model_channels_read_resps_24_ready = crossPackagePendingSeq_MPORT_data_source_ready;
  assign model_channels_read_resps_25_ready = refillPreservationAllowed_MPORT_data_source_ready;
  assign model_channels_read_resps_26_ready = wb_io_image_key_MPORT_data_source_ready;
  assign model_channels_read_resps_27_ready = s2_overwrittenKey_MPORT_data_source_ready;
  assign model_channels_read_resps_28_ready = clearFreezeReadBypassWindow_MPORT_data_source_ready;
  assign model_channels_read_resps_29_ready = MPORT_17_data_source_ready;
  assign model_channels_read_resps_30_ready = MPORT_16_data_source_ready;
  assign model_channels_read_resps_31_ready = MPORT_15_data_source_ready;
  assign model_channels_read_resps_32_ready = MPORT_12_data_source_ready;
  assign model_channels_read_resps_33_ready = installPreservationAllowed_MPORT_data_source_ready;
  assign model_channels_read_resps_34_ready = preservationWaitWatermark_MPORT_data_source_ready;
  assign model_channels_write_cmds_0_valid = MPORT_data_sink_valid & MPORT_mask_sink_valid & MPORT_addr_sink_valid &
    MPORT_en_sink_valid;
  assign model_channels_write_cmds_0_bits_en = MPORT_en_sink_bits;
  assign model_channels_write_cmds_0_bits_mask = MPORT_mask_sink_bits;
  assign model_channels_write_cmds_0_bits_addr = MPORT_addr_sink_bits;
  assign model_channels_write_cmds_0_bits_data = MPORT_data_sink_bits;
endmodule