module AsyncMemChiselRTL(
  input         clock,
  input         reset,
  input         channels_read_cmds_0_en,
  input  [8:0]  channels_read_cmds_0_addr,
  input         channels_read_cmds_1_en,
  input  [8:0]  channels_read_cmds_1_addr,
  input         channels_read_cmds_2_en,
  input  [8:0]  channels_read_cmds_2_addr,
  input         channels_read_cmds_3_en,
  input  [8:0]  channels_read_cmds_3_addr,
  input         channels_read_cmds_4_en,
  input  [8:0]  channels_read_cmds_4_addr,
  input         channels_read_cmds_5_en,
  input  [8:0]  channels_read_cmds_5_addr,
  input         channels_read_cmds_6_en,
  input  [8:0]  channels_read_cmds_6_addr,
  input         channels_read_cmds_7_en,
  input  [8:0]  channels_read_cmds_7_addr,
  input         channels_read_cmds_8_en,
  input  [8:0]  channels_read_cmds_8_addr,
  input         channels_read_cmds_9_en,
  input  [8:0]  channels_read_cmds_9_addr,
  input         channels_read_cmds_10_en,
  input  [8:0]  channels_read_cmds_10_addr,
  input         channels_read_cmds_11_en,
  input  [8:0]  channels_read_cmds_11_addr,
  input         channels_read_cmds_12_en,
  input  [8:0]  channels_read_cmds_12_addr,
  input         channels_read_cmds_13_en,
  input  [8:0]  channels_read_cmds_13_addr,
  input         channels_read_cmds_14_en,
  input  [8:0]  channels_read_cmds_14_addr,
  input         channels_read_cmds_15_en,
  input  [8:0]  channels_read_cmds_15_addr,
  input         channels_read_cmds_16_en,
  input  [8:0]  channels_read_cmds_16_addr,
  input         channels_read_cmds_17_en,
  input  [8:0]  channels_read_cmds_17_addr,
  input         channels_read_cmds_18_en,
  input  [8:0]  channels_read_cmds_18_addr,
  input         channels_read_cmds_19_en,
  input  [8:0]  channels_read_cmds_19_addr,
  input         channels_read_cmds_20_en,
  input  [8:0]  channels_read_cmds_20_addr,
  input         channels_read_cmds_21_en,
  input  [8:0]  channels_read_cmds_21_addr,
  input         channels_read_cmds_22_en,
  input  [8:0]  channels_read_cmds_22_addr,
  input         channels_read_cmds_23_en,
  input  [8:0]  channels_read_cmds_23_addr,
  input         channels_read_cmds_24_en,
  input  [8:0]  channels_read_cmds_24_addr,
  input         channels_read_cmds_25_en,
  input  [8:0]  channels_read_cmds_25_addr,
  input         channels_read_cmds_26_en,
  input  [8:0]  channels_read_cmds_26_addr,
  input         channels_read_cmds_27_en,
  input  [8:0]  channels_read_cmds_27_addr,
  input         channels_read_cmds_28_en,
  input  [8:0]  channels_read_cmds_28_addr,
  input         channels_read_cmds_29_en,
  input  [8:0]  channels_read_cmds_29_addr,
  input         channels_read_cmds_30_en,
  input  [8:0]  channels_read_cmds_30_addr,
  input         channels_read_cmds_31_en,
  input  [8:0]  channels_read_cmds_31_addr,
  input         channels_read_cmds_32_en,
  input  [8:0]  channels_read_cmds_32_addr,
  input         channels_read_cmds_33_en,
  input  [8:0]  channels_read_cmds_33_addr,
  input         channels_read_cmds_34_en,
  input  [8:0]  channels_read_cmds_34_addr,
  output [80:0] channels_read_resps_0,
  output [80:0] channels_read_resps_1,
  output [80:0] channels_read_resps_2,
  output [80:0] channels_read_resps_3,
  output [80:0] channels_read_resps_4,
  output [80:0] channels_read_resps_5,
  output [80:0] channels_read_resps_6,
  output [80:0] channels_read_resps_7,
  output [80:0] channels_read_resps_8,
  output [80:0] channels_read_resps_9,
  output [80:0] channels_read_resps_10,
  output [80:0] channels_read_resps_11,
  output [80:0] channels_read_resps_12,
  output [80:0] channels_read_resps_13,
  output [80:0] channels_read_resps_14,
  output [80:0] channels_read_resps_15,
  output [80:0] channels_read_resps_16,
  output [80:0] channels_read_resps_17,
  output [80:0] channels_read_resps_18,
  output [80:0] channels_read_resps_19,
  output [80:0] channels_read_resps_20,
  output [80:0] channels_read_resps_21,
  output [80:0] channels_read_resps_22,
  output [80:0] channels_read_resps_23,
  output [80:0] channels_read_resps_24,
  output [80:0] channels_read_resps_25,
  output [80:0] channels_read_resps_26,
  output [80:0] channels_read_resps_27,
  output [80:0] channels_read_resps_28,
  output [80:0] channels_read_resps_29,
  output [80:0] channels_read_resps_30,
  output [80:0] channels_read_resps_31,
  output [80:0] channels_read_resps_32,
  output [80:0] channels_read_resps_33,
  output [80:0] channels_read_resps_34,
  input         channels_write_cmds_0_en,
  input         channels_write_cmds_0_mask,
  input  [8:0]  channels_write_cmds_0_addr,
  input  [80:0] channels_write_cmds_0_data
);
`ifdef RANDOMIZE_MEM_INIT
  reg [95:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
  reg [80:0] data [0:511]; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_0_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_0_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_0_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_1_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_1_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_1_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_2_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_2_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_2_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_3_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_3_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_3_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_4_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_4_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_4_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_5_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_5_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_5_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_6_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_6_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_6_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_7_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_7_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_7_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_8_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_8_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_8_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_9_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_9_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_9_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_10_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_10_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_10_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_11_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_11_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_11_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_12_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_12_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_12_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_13_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_13_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_13_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_14_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_14_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_14_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_15_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_15_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_15_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_16_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_16_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_16_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_17_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_17_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_17_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_18_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_18_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_18_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_19_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_19_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_19_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_20_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_20_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_20_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_21_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_21_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_21_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_22_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_22_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_22_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_23_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_23_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_23_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_24_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_24_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_24_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_25_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_25_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_25_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_26_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_26_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_26_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_27_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_27_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_27_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_28_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_28_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_28_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_29_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_29_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_29_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_30_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_30_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_30_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_31_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_31_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_31_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_32_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_32_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_32_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_33_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_33_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_33_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire  data_channels_read_resps_34_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_channels_read_resps_34_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_channels_read_resps_34_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire [80:0] data_MPORT_data; // @[AsyncMemModel.scala 16:17]
  wire [8:0] data_MPORT_addr; // @[AsyncMemModel.scala 16:17]
  wire  data_MPORT_mask; // @[AsyncMemModel.scala 16:17]
  wire  data_MPORT_en; // @[AsyncMemModel.scala 16:17]
  wire  _T = channels_write_cmds_0_en & channels_write_cmds_0_mask; // @[RegfileModel.scala 25:19]
  wire  _T_2 = ~reset; // @[AsyncMemModel.scala 29:31]
  assign data_channels_read_resps_0_MPORT_en = 1'h1;
  assign data_channels_read_resps_0_MPORT_addr = channels_read_cmds_0_addr;
  assign data_channels_read_resps_0_MPORT_data = data[data_channels_read_resps_0_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_1_MPORT_en = 1'h1;
  assign data_channels_read_resps_1_MPORT_addr = channels_read_cmds_1_addr;
  assign data_channels_read_resps_1_MPORT_data = data[data_channels_read_resps_1_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_2_MPORT_en = 1'h1;
  assign data_channels_read_resps_2_MPORT_addr = channels_read_cmds_2_addr;
  assign data_channels_read_resps_2_MPORT_data = data[data_channels_read_resps_2_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_3_MPORT_en = 1'h1;
  assign data_channels_read_resps_3_MPORT_addr = channels_read_cmds_3_addr;
  assign data_channels_read_resps_3_MPORT_data = data[data_channels_read_resps_3_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_4_MPORT_en = 1'h1;
  assign data_channels_read_resps_4_MPORT_addr = channels_read_cmds_4_addr;
  assign data_channels_read_resps_4_MPORT_data = data[data_channels_read_resps_4_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_5_MPORT_en = 1'h1;
  assign data_channels_read_resps_5_MPORT_addr = channels_read_cmds_5_addr;
  assign data_channels_read_resps_5_MPORT_data = data[data_channels_read_resps_5_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_6_MPORT_en = 1'h1;
  assign data_channels_read_resps_6_MPORT_addr = channels_read_cmds_6_addr;
  assign data_channels_read_resps_6_MPORT_data = data[data_channels_read_resps_6_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_7_MPORT_en = 1'h1;
  assign data_channels_read_resps_7_MPORT_addr = channels_read_cmds_7_addr;
  assign data_channels_read_resps_7_MPORT_data = data[data_channels_read_resps_7_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_8_MPORT_en = 1'h1;
  assign data_channels_read_resps_8_MPORT_addr = channels_read_cmds_8_addr;
  assign data_channels_read_resps_8_MPORT_data = data[data_channels_read_resps_8_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_9_MPORT_en = 1'h1;
  assign data_channels_read_resps_9_MPORT_addr = channels_read_cmds_9_addr;
  assign data_channels_read_resps_9_MPORT_data = data[data_channels_read_resps_9_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_10_MPORT_en = 1'h1;
  assign data_channels_read_resps_10_MPORT_addr = channels_read_cmds_10_addr;
  assign data_channels_read_resps_10_MPORT_data = data[data_channels_read_resps_10_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_11_MPORT_en = 1'h1;
  assign data_channels_read_resps_11_MPORT_addr = channels_read_cmds_11_addr;
  assign data_channels_read_resps_11_MPORT_data = data[data_channels_read_resps_11_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_12_MPORT_en = 1'h1;
  assign data_channels_read_resps_12_MPORT_addr = channels_read_cmds_12_addr;
  assign data_channels_read_resps_12_MPORT_data = data[data_channels_read_resps_12_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_13_MPORT_en = 1'h1;
  assign data_channels_read_resps_13_MPORT_addr = channels_read_cmds_13_addr;
  assign data_channels_read_resps_13_MPORT_data = data[data_channels_read_resps_13_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_14_MPORT_en = 1'h1;
  assign data_channels_read_resps_14_MPORT_addr = channels_read_cmds_14_addr;
  assign data_channels_read_resps_14_MPORT_data = data[data_channels_read_resps_14_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_15_MPORT_en = 1'h1;
  assign data_channels_read_resps_15_MPORT_addr = channels_read_cmds_15_addr;
  assign data_channels_read_resps_15_MPORT_data = data[data_channels_read_resps_15_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_16_MPORT_en = 1'h1;
  assign data_channels_read_resps_16_MPORT_addr = channels_read_cmds_16_addr;
  assign data_channels_read_resps_16_MPORT_data = data[data_channels_read_resps_16_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_17_MPORT_en = 1'h1;
  assign data_channels_read_resps_17_MPORT_addr = channels_read_cmds_17_addr;
  assign data_channels_read_resps_17_MPORT_data = data[data_channels_read_resps_17_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_18_MPORT_en = 1'h1;
  assign data_channels_read_resps_18_MPORT_addr = channels_read_cmds_18_addr;
  assign data_channels_read_resps_18_MPORT_data = data[data_channels_read_resps_18_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_19_MPORT_en = 1'h1;
  assign data_channels_read_resps_19_MPORT_addr = channels_read_cmds_19_addr;
  assign data_channels_read_resps_19_MPORT_data = data[data_channels_read_resps_19_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_20_MPORT_en = 1'h1;
  assign data_channels_read_resps_20_MPORT_addr = channels_read_cmds_20_addr;
  assign data_channels_read_resps_20_MPORT_data = data[data_channels_read_resps_20_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_21_MPORT_en = 1'h1;
  assign data_channels_read_resps_21_MPORT_addr = channels_read_cmds_21_addr;
  assign data_channels_read_resps_21_MPORT_data = data[data_channels_read_resps_21_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_22_MPORT_en = 1'h1;
  assign data_channels_read_resps_22_MPORT_addr = channels_read_cmds_22_addr;
  assign data_channels_read_resps_22_MPORT_data = data[data_channels_read_resps_22_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_23_MPORT_en = 1'h1;
  assign data_channels_read_resps_23_MPORT_addr = channels_read_cmds_23_addr;
  assign data_channels_read_resps_23_MPORT_data = data[data_channels_read_resps_23_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_24_MPORT_en = 1'h1;
  assign data_channels_read_resps_24_MPORT_addr = channels_read_cmds_24_addr;
  assign data_channels_read_resps_24_MPORT_data = data[data_channels_read_resps_24_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_25_MPORT_en = 1'h1;
  assign data_channels_read_resps_25_MPORT_addr = channels_read_cmds_25_addr;
  assign data_channels_read_resps_25_MPORT_data = data[data_channels_read_resps_25_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_26_MPORT_en = 1'h1;
  assign data_channels_read_resps_26_MPORT_addr = channels_read_cmds_26_addr;
  assign data_channels_read_resps_26_MPORT_data = data[data_channels_read_resps_26_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_27_MPORT_en = 1'h1;
  assign data_channels_read_resps_27_MPORT_addr = channels_read_cmds_27_addr;
  assign data_channels_read_resps_27_MPORT_data = data[data_channels_read_resps_27_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_28_MPORT_en = 1'h1;
  assign data_channels_read_resps_28_MPORT_addr = channels_read_cmds_28_addr;
  assign data_channels_read_resps_28_MPORT_data = data[data_channels_read_resps_28_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_29_MPORT_en = 1'h1;
  assign data_channels_read_resps_29_MPORT_addr = channels_read_cmds_29_addr;
  assign data_channels_read_resps_29_MPORT_data = data[data_channels_read_resps_29_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_30_MPORT_en = 1'h1;
  assign data_channels_read_resps_30_MPORT_addr = channels_read_cmds_30_addr;
  assign data_channels_read_resps_30_MPORT_data = data[data_channels_read_resps_30_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_31_MPORT_en = 1'h1;
  assign data_channels_read_resps_31_MPORT_addr = channels_read_cmds_31_addr;
  assign data_channels_read_resps_31_MPORT_data = data[data_channels_read_resps_31_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_32_MPORT_en = 1'h1;
  assign data_channels_read_resps_32_MPORT_addr = channels_read_cmds_32_addr;
  assign data_channels_read_resps_32_MPORT_data = data[data_channels_read_resps_32_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_33_MPORT_en = 1'h1;
  assign data_channels_read_resps_33_MPORT_addr = channels_read_cmds_33_addr;
  assign data_channels_read_resps_33_MPORT_data = data[data_channels_read_resps_33_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_channels_read_resps_34_MPORT_en = 1'h1;
  assign data_channels_read_resps_34_MPORT_addr = channels_read_cmds_34_addr;
  assign data_channels_read_resps_34_MPORT_data = data[data_channels_read_resps_34_MPORT_addr]; // @[AsyncMemModel.scala 16:17]
  assign data_MPORT_data = channels_write_cmds_0_data;
  assign data_MPORT_addr = channels_write_cmds_0_addr;
  assign data_MPORT_mask = 1'h1;
  assign data_MPORT_en = _T & _T_2;
  assign channels_read_resps_0 = data_channels_read_resps_0_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_1 = data_channels_read_resps_1_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_2 = data_channels_read_resps_2_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_3 = data_channels_read_resps_3_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_4 = data_channels_read_resps_4_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_5 = data_channels_read_resps_5_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_6 = data_channels_read_resps_6_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_7 = data_channels_read_resps_7_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_8 = data_channels_read_resps_8_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_9 = data_channels_read_resps_9_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_10 = data_channels_read_resps_10_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_11 = data_channels_read_resps_11_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_12 = data_channels_read_resps_12_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_13 = data_channels_read_resps_13_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_14 = data_channels_read_resps_14_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_15 = data_channels_read_resps_15_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_16 = data_channels_read_resps_16_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_17 = data_channels_read_resps_17_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_18 = data_channels_read_resps_18_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_19 = data_channels_read_resps_19_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_20 = data_channels_read_resps_20_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_21 = data_channels_read_resps_21_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_22 = data_channels_read_resps_22_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_23 = data_channels_read_resps_23_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_24 = data_channels_read_resps_24_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_25 = data_channels_read_resps_25_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_26 = data_channels_read_resps_26_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_27 = data_channels_read_resps_27_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_28 = data_channels_read_resps_28_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_29 = data_channels_read_resps_29_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_30 = data_channels_read_resps_30_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_31 = data_channels_read_resps_31_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_32 = data_channels_read_resps_32_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_33 = data_channels_read_resps_33_MPORT_data; // @[AsyncMemModel.scala 19:28]
  assign channels_read_resps_34 = data_channels_read_resps_34_MPORT_data; // @[AsyncMemModel.scala 19:28]
  always @(posedge clock) begin
    if (data_MPORT_en & data_MPORT_mask) begin
      data[data_MPORT_addr] <= data_MPORT_data; // @[AsyncMemModel.scala 16:17]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_MEM_INIT
  _RAND_0 = {3{`RANDOM}};
  for (initvar = 0; initvar < 512; initvar = initvar+1)
    data[initvar] = _RAND_0[80:0];
`endif // RANDOMIZE_MEM_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
