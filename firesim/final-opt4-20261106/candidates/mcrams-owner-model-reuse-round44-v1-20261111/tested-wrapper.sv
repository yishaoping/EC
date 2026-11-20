module ownerImageMemory(
  input         hostClock,
  input         hostReset,
  output        before_MPORT_24_en_sink_ready,
  input         before_MPORT_24_en_sink_valid,
  output        before_MPORT_17_en_sink_ready,
  input         before_MPORT_17_en_sink_valid,
  output        before_MPORT_23_en_sink_ready,
  input         before_MPORT_23_en_sink_valid,
  output        before_MPORT_24_addr_sink_ready,
  input         before_MPORT_24_addr_sink_valid,
  input  [8:0]  before_MPORT_24_addr_sink_bits,
  output        before_MPORT_14_addr_sink_ready,
  input         before_MPORT_14_addr_sink_valid,
  input  [8:0]  before_MPORT_14_addr_sink_bits,
  output        before_MPORT_addr_sink_ready,
  input         before_MPORT_addr_sink_valid,
  input  [8:0]  before_MPORT_addr_sink_bits,
  output        before_MPORT_29_en_sink_ready,
  input         before_MPORT_29_en_sink_valid,
  output        before_MPORT_33_en_sink_ready,
  input         before_MPORT_33_en_sink_valid,
  output        before_MPORT_12_addr_sink_ready,
  input         before_MPORT_12_addr_sink_valid,
  input  [8:0]  before_MPORT_12_addr_sink_bits,
  output        before_MPORT_20_en_sink_ready,
  input         before_MPORT_20_en_sink_valid,
  output        before_MPORT_23_addr_sink_ready,
  input         before_MPORT_23_addr_sink_valid,
  input  [8:0]  before_MPORT_23_addr_sink_bits,
  output        before_MPORT_6_addr_sink_ready,
  input         before_MPORT_6_addr_sink_valid,
  input  [8:0]  before_MPORT_6_addr_sink_bits,
  output        before_MPORT_2_addr_sink_ready,
  input         before_MPORT_2_addr_sink_valid,
  input  [8:0]  before_MPORT_2_addr_sink_bits,
  output        before_MPORT_27_addr_sink_ready,
  input         before_MPORT_27_addr_sink_valid,
  input  [8:0]  before_MPORT_27_addr_sink_bits,
  output        before_MPORT_1_en_sink_ready,
  input         before_MPORT_1_en_sink_valid,
  output        before_MPORT_17_addr_sink_ready,
  input         before_MPORT_17_addr_sink_valid,
  input  [8:0]  before_MPORT_17_addr_sink_bits,
  output        before_MPORT_19_addr_sink_ready,
  input         before_MPORT_19_addr_sink_valid,
  input  [8:0]  before_MPORT_19_addr_sink_bits,
  output        before_MPORT_10_en_sink_ready,
  input         before_MPORT_10_en_sink_valid,
  output        before_MPORT_3_addr_sink_ready,
  input         before_MPORT_3_addr_sink_valid,
  input  [8:0]  before_MPORT_3_addr_sink_bits,
  output        before_MPORT_9_en_sink_ready,
  input         before_MPORT_9_en_sink_valid,
  output        before_MPORT_25_addr_sink_ready,
  input         before_MPORT_25_addr_sink_valid,
  input  [8:0]  before_MPORT_25_addr_sink_bits,
  output        before_MPORT_13_en_sink_ready,
  input         before_MPORT_13_en_sink_valid,
  output        before_MPORT_31_addr_sink_ready,
  input         before_MPORT_31_addr_sink_valid,
  input  [8:0]  before_MPORT_31_addr_sink_bits,
  output        before_MPORT_18_addr_sink_ready,
  input         before_MPORT_18_addr_sink_valid,
  input  [8:0]  before_MPORT_18_addr_sink_bits,
  output        before_MPORT_33_addr_sink_ready,
  input         before_MPORT_33_addr_sink_valid,
  input  [8:0]  before_MPORT_33_addr_sink_bits,
  output        before_MPORT_26_addr_sink_ready,
  input         before_MPORT_26_addr_sink_valid,
  input  [8:0]  before_MPORT_26_addr_sink_bits,
  output        before_MPORT_10_addr_sink_ready,
  input         before_MPORT_10_addr_sink_valid,
  input  [8:0]  before_MPORT_10_addr_sink_bits,
  output        before_MPORT_3_en_sink_ready,
  input         before_MPORT_3_en_sink_valid,
  output        before_MPORT_30_en_sink_ready,
  input         before_MPORT_30_en_sink_valid,
  output        before_MPORT_28_addr_sink_ready,
  input         before_MPORT_28_addr_sink_valid,
  input  [8:0]  before_MPORT_28_addr_sink_bits,
  output        before_MPORT_2_en_sink_ready,
  input         before_MPORT_2_en_sink_valid,
  output        before_MPORT_12_en_sink_ready,
  input         before_MPORT_12_en_sink_valid,
  output        before_MPORT_30_addr_sink_ready,
  input         before_MPORT_30_addr_sink_valid,
  input  [8:0]  before_MPORT_30_addr_sink_bits,
  output        MPORT_data_sink_ready,
  input         MPORT_data_sink_valid,
  input  [80:0] MPORT_data_sink_bits,
  output        before_MPORT_13_addr_sink_ready,
  input         before_MPORT_13_addr_sink_valid,
  input  [8:0]  before_MPORT_13_addr_sink_bits,
  output        before_MPORT_20_addr_sink_ready,
  input         before_MPORT_20_addr_sink_valid,
  input  [8:0]  before_MPORT_20_addr_sink_bits,
  output        before_MPORT_1_addr_sink_ready,
  input         before_MPORT_1_addr_sink_valid,
  input  [8:0]  before_MPORT_1_addr_sink_bits,
  output        before_MPORT_25_en_sink_ready,
  input         before_MPORT_25_en_sink_valid,
  output        before_MPORT_5_en_sink_ready,
  input         before_MPORT_5_en_sink_valid,
  output        before_MPORT_31_en_sink_ready,
  input         before_MPORT_31_en_sink_valid,
  output        MPORT_addr_sink_ready,
  input         MPORT_addr_sink_valid,
  input  [8:0]  MPORT_addr_sink_bits,
  output        before_MPORT_22_addr_sink_ready,
  input         before_MPORT_22_addr_sink_valid,
  input  [8:0]  before_MPORT_22_addr_sink_bits,
  output        before_MPORT_16_addr_sink_ready,
  input         before_MPORT_16_addr_sink_valid,
  input  [8:0]  before_MPORT_16_addr_sink_bits,
  output        before_MPORT_34_en_sink_ready,
  input         before_MPORT_34_en_sink_valid,
  output        before_MPORT_16_en_sink_ready,
  input         before_MPORT_16_en_sink_valid,
  output        before_MPORT_5_addr_sink_ready,
  input         before_MPORT_5_addr_sink_valid,
  input  [8:0]  before_MPORT_5_addr_sink_bits,
  output        before_MPORT_9_addr_sink_ready,
  input         before_MPORT_9_addr_sink_valid,
  input  [8:0]  before_MPORT_9_addr_sink_bits,
  output        before_MPORT_7_en_sink_ready,
  input         before_MPORT_7_en_sink_valid,
  output        before_MPORT_15_addr_sink_ready,
  input         before_MPORT_15_addr_sink_valid,
  input  [8:0]  before_MPORT_15_addr_sink_bits,
  output        MPORT_en_sink_ready,
  input         MPORT_en_sink_valid,
  input         MPORT_en_sink_bits,
  output        before_MPORT_21_en_sink_ready,
  input         before_MPORT_21_en_sink_valid,
  output        before_MPORT_28_en_sink_ready,
  input         before_MPORT_28_en_sink_valid,
  output        before_MPORT_15_en_sink_ready,
  input         before_MPORT_15_en_sink_valid,
  output        before_MPORT_8_addr_sink_ready,
  input         before_MPORT_8_addr_sink_valid,
  input  [8:0]  before_MPORT_8_addr_sink_bits,
  output        before_MPORT_19_en_sink_ready,
  input         before_MPORT_19_en_sink_valid,
  output        before_MPORT_34_addr_sink_ready,
  input         before_MPORT_34_addr_sink_valid,
  input  [8:0]  before_MPORT_34_addr_sink_bits,
  output        before_MPORT_11_addr_sink_ready,
  input         before_MPORT_11_addr_sink_valid,
  input  [8:0]  before_MPORT_11_addr_sink_bits,
  output        before_MPORT_8_en_sink_ready,
  input         before_MPORT_8_en_sink_valid,
  output        before_MPORT_32_addr_sink_ready,
  input         before_MPORT_32_addr_sink_valid,
  input  [8:0]  before_MPORT_32_addr_sink_bits,
  output        before_MPORT_4_en_sink_ready,
  input         before_MPORT_4_en_sink_valid,
  output        before_MPORT_7_addr_sink_ready,
  input         before_MPORT_7_addr_sink_valid,
  input  [8:0]  before_MPORT_7_addr_sink_bits,
  output        before_MPORT_29_addr_sink_ready,
  input         before_MPORT_29_addr_sink_valid,
  input  [8:0]  before_MPORT_29_addr_sink_bits,
  output        before_MPORT_en_sink_ready,
  input         before_MPORT_en_sink_valid,
  output        before_MPORT_32_en_sink_ready,
  input         before_MPORT_32_en_sink_valid,
  output        before_MPORT_26_en_sink_ready,
  input         before_MPORT_26_en_sink_valid,
  output        before_MPORT_22_en_sink_ready,
  input         before_MPORT_22_en_sink_valid,
  output        MPORT_mask_sink_ready,
  input         MPORT_mask_sink_valid,
  input         MPORT_mask_sink_bits,
  output        before_MPORT_27_en_sink_ready,
  input         before_MPORT_27_en_sink_valid,
  output        before_MPORT_21_addr_sink_ready,
  input         before_MPORT_21_addr_sink_valid,
  input  [8:0]  before_MPORT_21_addr_sink_bits,
  output        before_MPORT_4_addr_sink_ready,
  input         before_MPORT_4_addr_sink_valid,
  input  [8:0]  before_MPORT_4_addr_sink_bits,
  output        before_MPORT_14_en_sink_ready,
  input         before_MPORT_14_en_sink_valid,
  output        before_MPORT_11_en_sink_ready,
  input         before_MPORT_11_en_sink_valid,
  output        before_MPORT_18_en_sink_ready,
  input         before_MPORT_18_en_sink_valid,
  output        before_MPORT_6_en_sink_ready,
  input         before_MPORT_6_en_sink_valid,
  input         before_MPORT_21_data_source_ready,
  output        before_MPORT_21_data_source_valid,
  output [80:0] before_MPORT_21_data_source_bits,
  input         before_MPORT_22_data_source_ready,
  output        before_MPORT_22_data_source_valid,
  output [80:0] before_MPORT_22_data_source_bits,
  input         before_MPORT_8_data_source_ready,
  output        before_MPORT_8_data_source_valid,
  output [80:0] before_MPORT_8_data_source_bits,
  input         before_MPORT_29_data_source_ready,
  output        before_MPORT_29_data_source_valid,
  output [80:0] before_MPORT_29_data_source_bits,
  input         before_MPORT_6_data_source_ready,
  output        before_MPORT_6_data_source_valid,
  output [80:0] before_MPORT_6_data_source_bits,
  input         before_MPORT_20_data_source_ready,
  output        before_MPORT_20_data_source_valid,
  output [80:0] before_MPORT_20_data_source_bits,
  input         before_MPORT_15_data_source_ready,
  output        before_MPORT_15_data_source_valid,
  output [80:0] before_MPORT_15_data_source_bits,
  input         before_MPORT_3_data_source_ready,
  output        before_MPORT_3_data_source_valid,
  output [80:0] before_MPORT_3_data_source_bits,
  input         before_MPORT_7_data_source_ready,
  output        before_MPORT_7_data_source_valid,
  output [80:0] before_MPORT_7_data_source_bits,
  input         before_MPORT_31_data_source_ready,
  output        before_MPORT_31_data_source_valid,
  output [80:0] before_MPORT_31_data_source_bits,
  input         before_MPORT_32_data_source_ready,
  output        before_MPORT_32_data_source_valid,
  output [80:0] before_MPORT_32_data_source_bits,
  input         before_MPORT_19_data_source_ready,
  output        before_MPORT_19_data_source_valid,
  output [80:0] before_MPORT_19_data_source_bits,
  input         before_MPORT_17_data_source_ready,
  output        before_MPORT_17_data_source_valid,
  output [80:0] before_MPORT_17_data_source_bits,
  input         before_MPORT_33_data_source_ready,
  output        before_MPORT_33_data_source_valid,
  output [80:0] before_MPORT_33_data_source_bits,
  input         before_MPORT_23_data_source_ready,
  output        before_MPORT_23_data_source_valid,
  output [80:0] before_MPORT_23_data_source_bits,
  input         before_MPORT_25_data_source_ready,
  output        before_MPORT_25_data_source_valid,
  output [80:0] before_MPORT_25_data_source_bits,
  input         before_MPORT_12_data_source_ready,
  output        before_MPORT_12_data_source_valid,
  output [80:0] before_MPORT_12_data_source_bits,
  input         before_MPORT_4_data_source_ready,
  output        before_MPORT_4_data_source_valid,
  output [80:0] before_MPORT_4_data_source_bits,
  input         before_MPORT_5_data_source_ready,
  output        before_MPORT_5_data_source_valid,
  output [80:0] before_MPORT_5_data_source_bits,
  input         before_MPORT_14_data_source_ready,
  output        before_MPORT_14_data_source_valid,
  output [80:0] before_MPORT_14_data_source_bits,
  input         before_MPORT_data_source_ready,
  output        before_MPORT_data_source_valid,
  output [80:0] before_MPORT_data_source_bits,
  input         before_MPORT_13_data_source_ready,
  output        before_MPORT_13_data_source_valid,
  output [80:0] before_MPORT_13_data_source_bits,
  input         before_MPORT_26_data_source_ready,
  output        before_MPORT_26_data_source_valid,
  output [80:0] before_MPORT_26_data_source_bits,
  input         before_MPORT_10_data_source_ready,
  output        before_MPORT_10_data_source_valid,
  output [80:0] before_MPORT_10_data_source_bits,
  input         before_MPORT_2_data_source_ready,
  output        before_MPORT_2_data_source_valid,
  output [80:0] before_MPORT_2_data_source_bits,
  input         before_MPORT_1_data_source_ready,
  output        before_MPORT_1_data_source_valid,
  output [80:0] before_MPORT_1_data_source_bits,
  input         before_MPORT_18_data_source_ready,
  output        before_MPORT_18_data_source_valid,
  output [80:0] before_MPORT_18_data_source_bits,
  input         before_MPORT_11_data_source_ready,
  output        before_MPORT_11_data_source_valid,
  output [80:0] before_MPORT_11_data_source_bits,
  input         before_MPORT_16_data_source_ready,
  output        before_MPORT_16_data_source_valid,
  output [80:0] before_MPORT_16_data_source_bits,
  input         before_MPORT_9_data_source_ready,
  output        before_MPORT_9_data_source_valid,
  output [80:0] before_MPORT_9_data_source_bits,
  input         before_MPORT_34_data_source_ready,
  output        before_MPORT_34_data_source_valid,
  output [80:0] before_MPORT_34_data_source_bits,
  input         before_MPORT_24_data_source_ready,
  output        before_MPORT_24_data_source_valid,
  output [80:0] before_MPORT_24_data_source_bits,
  input         before_MPORT_27_data_source_ready,
  output        before_MPORT_27_data_source_valid,
  output [80:0] before_MPORT_27_data_source_bits,
  input         before_MPORT_30_data_source_ready,
  output        before_MPORT_30_data_source_valid,
  output [80:0] before_MPORT_30_data_source_bits,
  input         before_MPORT_28_data_source_ready,
  output        before_MPORT_28_data_source_valid,
  output [80:0] before_MPORT_28_data_source_bits
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
  assign before_MPORT_24_en_sink_ready = model_channels_read_cmds_16_ready & before_MPORT_24_addr_sink_valid;
  assign before_MPORT_17_en_sink_ready = model_channels_read_cmds_10_ready & before_MPORT_17_addr_sink_valid;
  assign before_MPORT_23_en_sink_ready = model_channels_read_cmds_32_ready & before_MPORT_23_addr_sink_valid;
  assign before_MPORT_24_addr_sink_ready = model_channels_read_cmds_16_ready & before_MPORT_24_en_sink_valid;
  assign before_MPORT_14_addr_sink_ready = model_channels_read_cmds_30_ready & before_MPORT_14_en_sink_valid;
  assign before_MPORT_addr_sink_ready = model_channels_read_cmds_19_ready & before_MPORT_en_sink_valid;
  assign before_MPORT_29_en_sink_ready = model_channels_read_cmds_7_ready & before_MPORT_29_addr_sink_valid;
  assign before_MPORT_33_en_sink_ready = model_channels_read_cmds_8_ready & before_MPORT_33_addr_sink_valid;
  assign before_MPORT_12_addr_sink_ready = model_channels_read_cmds_9_ready & before_MPORT_12_en_sink_valid;
  assign before_MPORT_20_en_sink_ready = model_channels_read_cmds_0_ready & before_MPORT_20_addr_sink_valid;
  assign before_MPORT_23_addr_sink_ready = model_channels_read_cmds_32_ready & before_MPORT_23_en_sink_valid;
  assign before_MPORT_6_addr_sink_ready = model_channels_read_cmds_3_ready & before_MPORT_6_en_sink_valid;
  assign before_MPORT_2_addr_sink_ready = model_channels_read_cmds_20_ready & before_MPORT_2_en_sink_valid;
  assign before_MPORT_27_addr_sink_ready = model_channels_read_cmds_14_ready & before_MPORT_27_en_sink_valid;
  assign before_MPORT_1_en_sink_ready = model_channels_read_cmds_24_ready & before_MPORT_1_addr_sink_valid;
  assign before_MPORT_17_addr_sink_ready = model_channels_read_cmds_10_ready & before_MPORT_17_en_sink_valid;
  assign before_MPORT_19_addr_sink_ready = model_channels_read_cmds_1_ready & before_MPORT_19_en_sink_valid;
  assign before_MPORT_10_en_sink_ready = model_channels_read_cmds_27_ready & before_MPORT_10_addr_sink_valid;
  assign before_MPORT_3_addr_sink_ready = model_channels_read_cmds_33_ready & before_MPORT_3_en_sink_valid;
  assign before_MPORT_9_en_sink_ready = model_channels_read_cmds_28_ready & before_MPORT_9_addr_sink_valid;
  assign before_MPORT_25_addr_sink_ready = model_channels_read_cmds_15_ready & before_MPORT_25_en_sink_valid;
  assign before_MPORT_13_en_sink_ready = model_channels_read_cmds_11_ready & before_MPORT_13_addr_sink_valid;
  assign before_MPORT_31_addr_sink_ready = model_channels_read_cmds_29_ready & before_MPORT_31_en_sink_valid;
  assign before_MPORT_18_addr_sink_ready = model_channels_read_cmds_26_ready & before_MPORT_18_en_sink_valid;
  assign before_MPORT_33_addr_sink_ready = model_channels_read_cmds_8_ready & before_MPORT_33_en_sink_valid;
  assign before_MPORT_26_addr_sink_ready = model_channels_read_cmds_34_ready & before_MPORT_26_en_sink_valid;
  assign before_MPORT_10_addr_sink_ready = model_channels_read_cmds_27_ready & before_MPORT_10_en_sink_valid;
  assign before_MPORT_3_en_sink_ready = model_channels_read_cmds_33_ready & before_MPORT_3_addr_sink_valid;
  assign before_MPORT_30_en_sink_ready = model_channels_read_cmds_23_ready & before_MPORT_30_addr_sink_valid;
  assign before_MPORT_28_addr_sink_ready = model_channels_read_cmds_17_ready & before_MPORT_28_en_sink_valid;
  assign before_MPORT_2_en_sink_ready = model_channels_read_cmds_20_ready & before_MPORT_2_addr_sink_valid;
  assign before_MPORT_12_en_sink_ready = model_channels_read_cmds_9_ready & before_MPORT_12_addr_sink_valid;
  assign before_MPORT_30_addr_sink_ready = model_channels_read_cmds_23_ready & before_MPORT_30_en_sink_valid;
  assign MPORT_data_sink_ready = model_channels_write_cmds_0_ready & MPORT_mask_sink_valid & MPORT_addr_sink_valid &
    MPORT_en_sink_valid;
  assign before_MPORT_13_addr_sink_ready = model_channels_read_cmds_11_ready & before_MPORT_13_en_sink_valid;
  assign before_MPORT_20_addr_sink_ready = model_channels_read_cmds_0_ready & before_MPORT_20_en_sink_valid;
  assign before_MPORT_1_addr_sink_ready = model_channels_read_cmds_24_ready & before_MPORT_1_en_sink_valid;
  assign before_MPORT_25_en_sink_ready = model_channels_read_cmds_15_ready & before_MPORT_25_addr_sink_valid;
  assign before_MPORT_5_en_sink_ready = model_channels_read_cmds_18_ready & before_MPORT_5_addr_sink_valid;
  assign before_MPORT_31_en_sink_ready = model_channels_read_cmds_29_ready & before_MPORT_31_addr_sink_valid;
  assign MPORT_addr_sink_ready = model_channels_write_cmds_0_ready & MPORT_data_sink_valid & MPORT_mask_sink_valid &
    MPORT_en_sink_valid;
  assign before_MPORT_22_addr_sink_ready = model_channels_read_cmds_4_ready & before_MPORT_22_en_sink_valid;
  assign before_MPORT_16_addr_sink_ready = model_channels_read_cmds_21_ready & before_MPORT_16_en_sink_valid;
  assign before_MPORT_34_en_sink_ready = model_channels_read_cmds_6_ready & before_MPORT_34_addr_sink_valid;
  assign before_MPORT_16_en_sink_ready = model_channels_read_cmds_21_ready & before_MPORT_16_addr_sink_valid;
  assign before_MPORT_5_addr_sink_ready = model_channels_read_cmds_18_ready & before_MPORT_5_en_sink_valid;
  assign before_MPORT_9_addr_sink_ready = model_channels_read_cmds_28_ready & before_MPORT_9_en_sink_valid;
  assign before_MPORT_7_en_sink_ready = model_channels_read_cmds_22_ready & before_MPORT_7_addr_sink_valid;
  assign before_MPORT_15_addr_sink_ready = model_channels_read_cmds_5_ready & before_MPORT_15_en_sink_valid;
  assign MPORT_en_sink_ready = model_channels_write_cmds_0_ready & MPORT_data_sink_valid & MPORT_mask_sink_valid &
    MPORT_addr_sink_valid;
  assign before_MPORT_21_en_sink_ready = model_channels_read_cmds_12_ready & before_MPORT_21_addr_sink_valid;
  assign before_MPORT_28_en_sink_ready = model_channels_read_cmds_17_ready & before_MPORT_28_addr_sink_valid;
  assign before_MPORT_15_en_sink_ready = model_channels_read_cmds_5_ready & before_MPORT_15_addr_sink_valid;
  assign before_MPORT_8_addr_sink_ready = model_channels_read_cmds_2_ready & before_MPORT_8_en_sink_valid;
  assign before_MPORT_19_en_sink_ready = model_channels_read_cmds_1_ready & before_MPORT_19_addr_sink_valid;
  assign before_MPORT_34_addr_sink_ready = model_channels_read_cmds_6_ready & before_MPORT_34_en_sink_valid;
  assign before_MPORT_11_addr_sink_ready = model_channels_read_cmds_31_ready & before_MPORT_11_en_sink_valid;
  assign before_MPORT_8_en_sink_ready = model_channels_read_cmds_2_ready & before_MPORT_8_addr_sink_valid;
  assign before_MPORT_32_addr_sink_ready = model_channels_read_cmds_13_ready & before_MPORT_32_en_sink_valid;
  assign before_MPORT_4_en_sink_ready = model_channels_read_cmds_25_ready & before_MPORT_4_addr_sink_valid;
  assign before_MPORT_7_addr_sink_ready = model_channels_read_cmds_22_ready & before_MPORT_7_en_sink_valid;
  assign before_MPORT_29_addr_sink_ready = model_channels_read_cmds_7_ready & before_MPORT_29_en_sink_valid;
  assign before_MPORT_en_sink_ready = model_channels_read_cmds_19_ready & before_MPORT_addr_sink_valid;
  assign before_MPORT_32_en_sink_ready = model_channels_read_cmds_13_ready & before_MPORT_32_addr_sink_valid;
  assign before_MPORT_26_en_sink_ready = model_channels_read_cmds_34_ready & before_MPORT_26_addr_sink_valid;
  assign before_MPORT_22_en_sink_ready = model_channels_read_cmds_4_ready & before_MPORT_22_addr_sink_valid;
  assign MPORT_mask_sink_ready = model_channels_write_cmds_0_ready & MPORT_data_sink_valid & MPORT_addr_sink_valid &
    MPORT_en_sink_valid;
  assign before_MPORT_27_en_sink_ready = model_channels_read_cmds_14_ready & before_MPORT_27_addr_sink_valid;
  assign before_MPORT_21_addr_sink_ready = model_channels_read_cmds_12_ready & before_MPORT_21_en_sink_valid;
  assign before_MPORT_4_addr_sink_ready = model_channels_read_cmds_25_ready & before_MPORT_4_en_sink_valid;
  assign before_MPORT_14_en_sink_ready = model_channels_read_cmds_30_ready & before_MPORT_14_addr_sink_valid;
  assign before_MPORT_11_en_sink_ready = model_channels_read_cmds_31_ready & before_MPORT_11_addr_sink_valid;
  assign before_MPORT_18_en_sink_ready = model_channels_read_cmds_26_ready & before_MPORT_18_addr_sink_valid;
  assign before_MPORT_6_en_sink_ready = model_channels_read_cmds_3_ready & before_MPORT_6_addr_sink_valid;
  assign before_MPORT_21_data_source_valid = model_channels_read_resps_12_valid;
  assign before_MPORT_21_data_source_bits = model_channels_read_resps_12_bits;
  assign before_MPORT_22_data_source_valid = model_channels_read_resps_4_valid;
  assign before_MPORT_22_data_source_bits = model_channels_read_resps_4_bits;
  assign before_MPORT_8_data_source_valid = model_channels_read_resps_2_valid;
  assign before_MPORT_8_data_source_bits = model_channels_read_resps_2_bits;
  assign before_MPORT_29_data_source_valid = model_channels_read_resps_7_valid;
  assign before_MPORT_29_data_source_bits = model_channels_read_resps_7_bits;
  assign before_MPORT_6_data_source_valid = model_channels_read_resps_3_valid;
  assign before_MPORT_6_data_source_bits = model_channels_read_resps_3_bits;
  assign before_MPORT_20_data_source_valid = model_channels_read_resps_0_valid;
  assign before_MPORT_20_data_source_bits = model_channels_read_resps_0_bits;
  assign before_MPORT_15_data_source_valid = model_channels_read_resps_5_valid;
  assign before_MPORT_15_data_source_bits = model_channels_read_resps_5_bits;
  assign before_MPORT_3_data_source_valid = model_channels_read_resps_33_valid;
  assign before_MPORT_3_data_source_bits = model_channels_read_resps_33_bits;
  assign before_MPORT_7_data_source_valid = model_channels_read_resps_22_valid;
  assign before_MPORT_7_data_source_bits = model_channels_read_resps_22_bits;
  assign before_MPORT_31_data_source_valid = model_channels_read_resps_29_valid;
  assign before_MPORT_31_data_source_bits = model_channels_read_resps_29_bits;
  assign before_MPORT_32_data_source_valid = model_channels_read_resps_13_valid;
  assign before_MPORT_32_data_source_bits = model_channels_read_resps_13_bits;
  assign before_MPORT_19_data_source_valid = model_channels_read_resps_1_valid;
  assign before_MPORT_19_data_source_bits = model_channels_read_resps_1_bits;
  assign before_MPORT_17_data_source_valid = model_channels_read_resps_10_valid;
  assign before_MPORT_17_data_source_bits = model_channels_read_resps_10_bits;
  assign before_MPORT_33_data_source_valid = model_channels_read_resps_8_valid;
  assign before_MPORT_33_data_source_bits = model_channels_read_resps_8_bits;
  assign before_MPORT_23_data_source_valid = model_channels_read_resps_32_valid;
  assign before_MPORT_23_data_source_bits = model_channels_read_resps_32_bits;
  assign before_MPORT_25_data_source_valid = model_channels_read_resps_15_valid;
  assign before_MPORT_25_data_source_bits = model_channels_read_resps_15_bits;
  assign before_MPORT_12_data_source_valid = model_channels_read_resps_9_valid;
  assign before_MPORT_12_data_source_bits = model_channels_read_resps_9_bits;
  assign before_MPORT_4_data_source_valid = model_channels_read_resps_25_valid;
  assign before_MPORT_4_data_source_bits = model_channels_read_resps_25_bits;
  assign before_MPORT_5_data_source_valid = model_channels_read_resps_18_valid;
  assign before_MPORT_5_data_source_bits = model_channels_read_resps_18_bits;
  assign before_MPORT_14_data_source_valid = model_channels_read_resps_30_valid;
  assign before_MPORT_14_data_source_bits = model_channels_read_resps_30_bits;
  assign before_MPORT_data_source_valid = model_channels_read_resps_19_valid;
  assign before_MPORT_data_source_bits = model_channels_read_resps_19_bits;
  assign before_MPORT_13_data_source_valid = model_channels_read_resps_11_valid;
  assign before_MPORT_13_data_source_bits = model_channels_read_resps_11_bits;
  assign before_MPORT_26_data_source_valid = model_channels_read_resps_34_valid;
  assign before_MPORT_26_data_source_bits = model_channels_read_resps_34_bits;
  assign before_MPORT_10_data_source_valid = model_channels_read_resps_27_valid;
  assign before_MPORT_10_data_source_bits = model_channels_read_resps_27_bits;
  assign before_MPORT_2_data_source_valid = model_channels_read_resps_20_valid;
  assign before_MPORT_2_data_source_bits = model_channels_read_resps_20_bits;
  assign before_MPORT_1_data_source_valid = model_channels_read_resps_24_valid;
  assign before_MPORT_1_data_source_bits = model_channels_read_resps_24_bits;
  assign before_MPORT_18_data_source_valid = model_channels_read_resps_26_valid;
  assign before_MPORT_18_data_source_bits = model_channels_read_resps_26_bits;
  assign before_MPORT_11_data_source_valid = model_channels_read_resps_31_valid;
  assign before_MPORT_11_data_source_bits = model_channels_read_resps_31_bits;
  assign before_MPORT_16_data_source_valid = model_channels_read_resps_21_valid;
  assign before_MPORT_16_data_source_bits = model_channels_read_resps_21_bits;
  assign before_MPORT_9_data_source_valid = model_channels_read_resps_28_valid;
  assign before_MPORT_9_data_source_bits = model_channels_read_resps_28_bits;
  assign before_MPORT_34_data_source_valid = model_channels_read_resps_6_valid;
  assign before_MPORT_34_data_source_bits = model_channels_read_resps_6_bits;
  assign before_MPORT_24_data_source_valid = model_channels_read_resps_16_valid;
  assign before_MPORT_24_data_source_bits = model_channels_read_resps_16_bits;
  assign before_MPORT_27_data_source_valid = model_channels_read_resps_14_valid;
  assign before_MPORT_27_data_source_bits = model_channels_read_resps_14_bits;
  assign before_MPORT_30_data_source_valid = model_channels_read_resps_23_valid;
  assign before_MPORT_30_data_source_bits = model_channels_read_resps_23_bits;
  assign before_MPORT_28_data_source_valid = model_channels_read_resps_17_valid;
  assign before_MPORT_28_data_source_bits = model_channels_read_resps_17_bits;
  assign model_clock = hostClock;
  assign model_reset = hostReset;
  assign model_channels_read_cmds_0_valid = before_MPORT_20_addr_sink_valid & before_MPORT_20_en_sink_valid;
  assign model_channels_read_cmds_0_bits_addr = before_MPORT_20_addr_sink_bits;
  assign model_channels_read_cmds_1_valid = before_MPORT_19_addr_sink_valid & before_MPORT_19_en_sink_valid;
  assign model_channels_read_cmds_1_bits_addr = before_MPORT_19_addr_sink_bits;
  assign model_channels_read_cmds_2_valid = before_MPORT_8_addr_sink_valid & before_MPORT_8_en_sink_valid;
  assign model_channels_read_cmds_2_bits_addr = before_MPORT_8_addr_sink_bits;
  assign model_channels_read_cmds_3_valid = before_MPORT_6_addr_sink_valid & before_MPORT_6_en_sink_valid;
  assign model_channels_read_cmds_3_bits_addr = before_MPORT_6_addr_sink_bits;
  assign model_channels_read_cmds_4_valid = before_MPORT_22_addr_sink_valid & before_MPORT_22_en_sink_valid;
  assign model_channels_read_cmds_4_bits_addr = before_MPORT_22_addr_sink_bits;
  assign model_channels_read_cmds_5_valid = before_MPORT_15_addr_sink_valid & before_MPORT_15_en_sink_valid;
  assign model_channels_read_cmds_5_bits_addr = before_MPORT_15_addr_sink_bits;
  assign model_channels_read_cmds_6_valid = before_MPORT_34_addr_sink_valid & before_MPORT_34_en_sink_valid;
  assign model_channels_read_cmds_6_bits_addr = before_MPORT_34_addr_sink_bits;
  assign model_channels_read_cmds_7_valid = before_MPORT_29_addr_sink_valid & before_MPORT_29_en_sink_valid;
  assign model_channels_read_cmds_7_bits_addr = before_MPORT_29_addr_sink_bits;
  assign model_channels_read_cmds_8_valid = before_MPORT_33_addr_sink_valid & before_MPORT_33_en_sink_valid;
  assign model_channels_read_cmds_8_bits_addr = before_MPORT_33_addr_sink_bits;
  assign model_channels_read_cmds_9_valid = before_MPORT_12_addr_sink_valid & before_MPORT_12_en_sink_valid;
  assign model_channels_read_cmds_9_bits_addr = before_MPORT_12_addr_sink_bits;
  assign model_channels_read_cmds_10_valid = before_MPORT_17_addr_sink_valid & before_MPORT_17_en_sink_valid;
  assign model_channels_read_cmds_10_bits_addr = before_MPORT_17_addr_sink_bits;
  assign model_channels_read_cmds_11_valid = before_MPORT_13_addr_sink_valid & before_MPORT_13_en_sink_valid;
  assign model_channels_read_cmds_11_bits_addr = before_MPORT_13_addr_sink_bits;
  assign model_channels_read_cmds_12_valid = before_MPORT_21_addr_sink_valid & before_MPORT_21_en_sink_valid;
  assign model_channels_read_cmds_12_bits_addr = before_MPORT_21_addr_sink_bits;
  assign model_channels_read_cmds_13_valid = before_MPORT_32_addr_sink_valid & before_MPORT_32_en_sink_valid;
  assign model_channels_read_cmds_13_bits_addr = before_MPORT_32_addr_sink_bits;
  assign model_channels_read_cmds_14_valid = before_MPORT_27_addr_sink_valid & before_MPORT_27_en_sink_valid;
  assign model_channels_read_cmds_14_bits_addr = before_MPORT_27_addr_sink_bits;
  assign model_channels_read_cmds_15_valid = before_MPORT_25_addr_sink_valid & before_MPORT_25_en_sink_valid;
  assign model_channels_read_cmds_15_bits_addr = before_MPORT_25_addr_sink_bits;
  assign model_channels_read_cmds_16_valid = before_MPORT_24_addr_sink_valid & before_MPORT_24_en_sink_valid;
  assign model_channels_read_cmds_16_bits_addr = before_MPORT_24_addr_sink_bits;
  assign model_channels_read_cmds_17_valid = before_MPORT_28_addr_sink_valid & before_MPORT_28_en_sink_valid;
  assign model_channels_read_cmds_17_bits_addr = before_MPORT_28_addr_sink_bits;
  assign model_channels_read_cmds_18_valid = before_MPORT_5_addr_sink_valid & before_MPORT_5_en_sink_valid;
  assign model_channels_read_cmds_18_bits_addr = before_MPORT_5_addr_sink_bits;
  assign model_channels_read_cmds_19_valid = before_MPORT_addr_sink_valid & before_MPORT_en_sink_valid;
  assign model_channels_read_cmds_19_bits_addr = before_MPORT_addr_sink_bits;
  assign model_channels_read_cmds_20_valid = before_MPORT_2_addr_sink_valid & before_MPORT_2_en_sink_valid;
  assign model_channels_read_cmds_20_bits_addr = before_MPORT_2_addr_sink_bits;
  assign model_channels_read_cmds_21_valid = before_MPORT_16_addr_sink_valid & before_MPORT_16_en_sink_valid;
  assign model_channels_read_cmds_21_bits_addr = before_MPORT_16_addr_sink_bits;
  assign model_channels_read_cmds_22_valid = before_MPORT_7_addr_sink_valid & before_MPORT_7_en_sink_valid;
  assign model_channels_read_cmds_22_bits_addr = before_MPORT_7_addr_sink_bits;
  assign model_channels_read_cmds_23_valid = before_MPORT_30_addr_sink_valid & before_MPORT_30_en_sink_valid;
  assign model_channels_read_cmds_23_bits_addr = before_MPORT_30_addr_sink_bits;
  assign model_channels_read_cmds_24_valid = before_MPORT_1_addr_sink_valid & before_MPORT_1_en_sink_valid;
  assign model_channels_read_cmds_24_bits_addr = before_MPORT_1_addr_sink_bits;
  assign model_channels_read_cmds_25_valid = before_MPORT_4_addr_sink_valid & before_MPORT_4_en_sink_valid;
  assign model_channels_read_cmds_25_bits_addr = before_MPORT_4_addr_sink_bits;
  assign model_channels_read_cmds_26_valid = before_MPORT_18_addr_sink_valid & before_MPORT_18_en_sink_valid;
  assign model_channels_read_cmds_26_bits_addr = before_MPORT_18_addr_sink_bits;
  assign model_channels_read_cmds_27_valid = before_MPORT_10_addr_sink_valid & before_MPORT_10_en_sink_valid;
  assign model_channels_read_cmds_27_bits_addr = before_MPORT_10_addr_sink_bits;
  assign model_channels_read_cmds_28_valid = before_MPORT_9_addr_sink_valid & before_MPORT_9_en_sink_valid;
  assign model_channels_read_cmds_28_bits_addr = before_MPORT_9_addr_sink_bits;
  assign model_channels_read_cmds_29_valid = before_MPORT_31_addr_sink_valid & before_MPORT_31_en_sink_valid;
  assign model_channels_read_cmds_29_bits_addr = before_MPORT_31_addr_sink_bits;
  assign model_channels_read_cmds_30_valid = before_MPORT_14_addr_sink_valid & before_MPORT_14_en_sink_valid;
  assign model_channels_read_cmds_30_bits_addr = before_MPORT_14_addr_sink_bits;
  assign model_channels_read_cmds_31_valid = before_MPORT_11_addr_sink_valid & before_MPORT_11_en_sink_valid;
  assign model_channels_read_cmds_31_bits_addr = before_MPORT_11_addr_sink_bits;
  assign model_channels_read_cmds_32_valid = before_MPORT_23_addr_sink_valid & before_MPORT_23_en_sink_valid;
  assign model_channels_read_cmds_32_bits_addr = before_MPORT_23_addr_sink_bits;
  assign model_channels_read_cmds_33_valid = before_MPORT_3_addr_sink_valid & before_MPORT_3_en_sink_valid;
  assign model_channels_read_cmds_33_bits_addr = before_MPORT_3_addr_sink_bits;
  assign model_channels_read_cmds_34_valid = before_MPORT_26_addr_sink_valid & before_MPORT_26_en_sink_valid;
  assign model_channels_read_cmds_34_bits_addr = before_MPORT_26_addr_sink_bits;
  assign model_channels_read_resps_0_ready = before_MPORT_20_data_source_ready;
  assign model_channels_read_resps_1_ready = before_MPORT_19_data_source_ready;
  assign model_channels_read_resps_2_ready = before_MPORT_8_data_source_ready;
  assign model_channels_read_resps_3_ready = before_MPORT_6_data_source_ready;
  assign model_channels_read_resps_4_ready = before_MPORT_22_data_source_ready;
  assign model_channels_read_resps_5_ready = before_MPORT_15_data_source_ready;
  assign model_channels_read_resps_6_ready = before_MPORT_34_data_source_ready;
  assign model_channels_read_resps_7_ready = before_MPORT_29_data_source_ready;
  assign model_channels_read_resps_8_ready = before_MPORT_33_data_source_ready;
  assign model_channels_read_resps_9_ready = before_MPORT_12_data_source_ready;
  assign model_channels_read_resps_10_ready = before_MPORT_17_data_source_ready;
  assign model_channels_read_resps_11_ready = before_MPORT_13_data_source_ready;
  assign model_channels_read_resps_12_ready = before_MPORT_21_data_source_ready;
  assign model_channels_read_resps_13_ready = before_MPORT_32_data_source_ready;
  assign model_channels_read_resps_14_ready = before_MPORT_27_data_source_ready;
  assign model_channels_read_resps_15_ready = before_MPORT_25_data_source_ready;
  assign model_channels_read_resps_16_ready = before_MPORT_24_data_source_ready;
  assign model_channels_read_resps_17_ready = before_MPORT_28_data_source_ready;
  assign model_channels_read_resps_18_ready = before_MPORT_5_data_source_ready;
  assign model_channels_read_resps_19_ready = before_MPORT_data_source_ready;
  assign model_channels_read_resps_20_ready = before_MPORT_2_data_source_ready;
  assign model_channels_read_resps_21_ready = before_MPORT_16_data_source_ready;
  assign model_channels_read_resps_22_ready = before_MPORT_7_data_source_ready;
  assign model_channels_read_resps_23_ready = before_MPORT_30_data_source_ready;
  assign model_channels_read_resps_24_ready = before_MPORT_1_data_source_ready;
  assign model_channels_read_resps_25_ready = before_MPORT_4_data_source_ready;
  assign model_channels_read_resps_26_ready = before_MPORT_18_data_source_ready;
  assign model_channels_read_resps_27_ready = before_MPORT_10_data_source_ready;
  assign model_channels_read_resps_28_ready = before_MPORT_9_data_source_ready;
  assign model_channels_read_resps_29_ready = before_MPORT_31_data_source_ready;
  assign model_channels_read_resps_30_ready = before_MPORT_14_data_source_ready;
  assign model_channels_read_resps_31_ready = before_MPORT_11_data_source_ready;
  assign model_channels_read_resps_32_ready = before_MPORT_23_data_source_ready;
  assign model_channels_read_resps_33_ready = before_MPORT_3_data_source_ready;
  assign model_channels_read_resps_34_ready = before_MPORT_26_data_source_ready;
  assign model_channels_write_cmds_0_valid = MPORT_data_sink_valid & MPORT_mask_sink_valid & MPORT_addr_sink_valid &
    MPORT_en_sink_valid;
  assign model_channels_write_cmds_0_bits_en = MPORT_en_sink_bits;
  assign model_channels_write_cmds_0_bits_mask = MPORT_mask_sink_bits;
  assign model_channels_write_cmds_0_bits_addr = MPORT_addr_sink_bits;
  assign model_channels_write_cmds_0_bits_data = MPORT_data_sink_bits;
endmodule