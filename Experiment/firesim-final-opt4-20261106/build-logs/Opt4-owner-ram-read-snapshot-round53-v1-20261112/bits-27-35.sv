module RamModel(
  input         clock,
  input         reset,
  output        channels_read_cmds_0_ready,
  input         channels_read_cmds_0_valid,
  input  [8:0]  channels_read_cmds_0_bits_addr,
  output        channels_read_cmds_1_ready,
  input         channels_read_cmds_1_valid,
  input  [8:0]  channels_read_cmds_1_bits_addr,
  output        channels_read_cmds_2_ready,
  input         channels_read_cmds_2_valid,
  input  [8:0]  channels_read_cmds_2_bits_addr,
  output        channels_read_cmds_3_ready,
  input         channels_read_cmds_3_valid,
  input  [8:0]  channels_read_cmds_3_bits_addr,
  output        channels_read_cmds_4_ready,
  input         channels_read_cmds_4_valid,
  input  [8:0]  channels_read_cmds_4_bits_addr,
  output        channels_read_cmds_5_ready,
  input         channels_read_cmds_5_valid,
  input  [8:0]  channels_read_cmds_5_bits_addr,
  output        channels_read_cmds_6_ready,
  input         channels_read_cmds_6_valid,
  input  [8:0]  channels_read_cmds_6_bits_addr,
  output        channels_read_cmds_7_ready,
  input         channels_read_cmds_7_valid,
  input  [8:0]  channels_read_cmds_7_bits_addr,
  output        channels_read_cmds_8_ready,
  input         channels_read_cmds_8_valid,
  input  [8:0]  channels_read_cmds_8_bits_addr,
  output        channels_read_cmds_9_ready,
  input         channels_read_cmds_9_valid,
  input  [8:0]  channels_read_cmds_9_bits_addr,
  output        channels_read_cmds_10_ready,
  input         channels_read_cmds_10_valid,
  input  [8:0]  channels_read_cmds_10_bits_addr,
  output        channels_read_cmds_11_ready,
  input         channels_read_cmds_11_valid,
  input  [8:0]  channels_read_cmds_11_bits_addr,
  output        channels_read_cmds_12_ready,
  input         channels_read_cmds_12_valid,
  input  [8:0]  channels_read_cmds_12_bits_addr,
  output        channels_read_cmds_13_ready,
  input         channels_read_cmds_13_valid,
  input  [8:0]  channels_read_cmds_13_bits_addr,
  output        channels_read_cmds_14_ready,
  input         channels_read_cmds_14_valid,
  input  [8:0]  channels_read_cmds_14_bits_addr,
  output        channels_read_cmds_15_ready,
  input         channels_read_cmds_15_valid,
  input  [8:0]  channels_read_cmds_15_bits_addr,
  output        channels_read_cmds_16_ready,
  input         channels_read_cmds_16_valid,
  input  [8:0]  channels_read_cmds_16_bits_addr,
  output        channels_read_cmds_17_ready,
  input         channels_read_cmds_17_valid,
  input  [8:0]  channels_read_cmds_17_bits_addr,
  output        channels_read_cmds_18_ready,
  input         channels_read_cmds_18_valid,
  input  [8:0]  channels_read_cmds_18_bits_addr,
  output        channels_read_cmds_19_ready,
  input         channels_read_cmds_19_valid,
  input  [8:0]  channels_read_cmds_19_bits_addr,
  output        channels_read_cmds_20_ready,
  input         channels_read_cmds_20_valid,
  input  [8:0]  channels_read_cmds_20_bits_addr,
  output        channels_read_cmds_21_ready,
  input         channels_read_cmds_21_valid,
  input  [8:0]  channels_read_cmds_21_bits_addr,
  output        channels_read_cmds_22_ready,
  input         channels_read_cmds_22_valid,
  input  [8:0]  channels_read_cmds_22_bits_addr,
  output        channels_read_cmds_23_ready,
  input         channels_read_cmds_23_valid,
  input  [8:0]  channels_read_cmds_23_bits_addr,
  output        channels_read_cmds_24_ready,
  input         channels_read_cmds_24_valid,
  input  [8:0]  channels_read_cmds_24_bits_addr,
  output        channels_read_cmds_25_ready,
  input         channels_read_cmds_25_valid,
  input  [8:0]  channels_read_cmds_25_bits_addr,
  output        channels_read_cmds_26_ready,
  input         channels_read_cmds_26_valid,
  input  [8:0]  channels_read_cmds_26_bits_addr,
  output        channels_read_cmds_27_ready,
  input         channels_read_cmds_27_valid,
  input  [8:0]  channels_read_cmds_27_bits_addr,
  output        channels_read_cmds_28_ready,
  input         channels_read_cmds_28_valid,
  input  [8:0]  channels_read_cmds_28_bits_addr,
  output        channels_read_cmds_29_ready,
  input         channels_read_cmds_29_valid,
  input  [8:0]  channels_read_cmds_29_bits_addr,
  output        channels_read_cmds_30_ready,
  input         channels_read_cmds_30_valid,
  input  [8:0]  channels_read_cmds_30_bits_addr,
  output        channels_read_cmds_31_ready,
  input         channels_read_cmds_31_valid,
  input  [8:0]  channels_read_cmds_31_bits_addr,
  output        channels_read_cmds_32_ready,
  input         channels_read_cmds_32_valid,
  input  [8:0]  channels_read_cmds_32_bits_addr,
  output        channels_read_cmds_33_ready,
  input         channels_read_cmds_33_valid,
  input  [8:0]  channels_read_cmds_33_bits_addr,
  output        channels_read_cmds_34_ready,
  input         channels_read_cmds_34_valid,
  input  [8:0]  channels_read_cmds_34_bits_addr,
  input         channels_read_resps_0_ready,
  output        channels_read_resps_0_valid,
  output [80:0] channels_read_resps_0_bits,
  input         channels_read_resps_1_ready,
  output        channels_read_resps_1_valid,
  output [80:0] channels_read_resps_1_bits,
  input         channels_read_resps_2_ready,
  output        channels_read_resps_2_valid,
  output [80:0] channels_read_resps_2_bits,
  input         channels_read_resps_3_ready,
  output        channels_read_resps_3_valid,
  output [80:0] channels_read_resps_3_bits,
  input         channels_read_resps_4_ready,
  output        channels_read_resps_4_valid,
  output [80:0] channels_read_resps_4_bits,
  input         channels_read_resps_5_ready,
  output        channels_read_resps_5_valid,
  output [80:0] channels_read_resps_5_bits,
  input         channels_read_resps_6_ready,
  output        channels_read_resps_6_valid,
  output [80:0] channels_read_resps_6_bits,
  input         channels_read_resps_7_ready,
  output        channels_read_resps_7_valid,
  output [80:0] channels_read_resps_7_bits,
  input         channels_read_resps_8_ready,
  output        channels_read_resps_8_valid,
  output [80:0] channels_read_resps_8_bits,
  input         channels_read_resps_9_ready,
  output        channels_read_resps_9_valid,
  output [80:0] channels_read_resps_9_bits,
  input         channels_read_resps_10_ready,
  output        channels_read_resps_10_valid,
  output [80:0] channels_read_resps_10_bits,
  input         channels_read_resps_11_ready,
  output        channels_read_resps_11_valid,
  output [80:0] channels_read_resps_11_bits,
  input         channels_read_resps_12_ready,
  output        channels_read_resps_12_valid,
  output [80:0] channels_read_resps_12_bits,
  input         channels_read_resps_13_ready,
  output        channels_read_resps_13_valid,
  output [80:0] channels_read_resps_13_bits,
  input         channels_read_resps_14_ready,
  output        channels_read_resps_14_valid,
  output [80:0] channels_read_resps_14_bits,
  input         channels_read_resps_15_ready,
  output        channels_read_resps_15_valid,
  output [80:0] channels_read_resps_15_bits,
  input         channels_read_resps_16_ready,
  output        channels_read_resps_16_valid,
  output [80:0] channels_read_resps_16_bits,
  input         channels_read_resps_17_ready,
  output        channels_read_resps_17_valid,
  output [80:0] channels_read_resps_17_bits,
  input         channels_read_resps_18_ready,
  output        channels_read_resps_18_valid,
  output [80:0] channels_read_resps_18_bits,
  input         channels_read_resps_19_ready,
  output        channels_read_resps_19_valid,
  output [80:0] channels_read_resps_19_bits,
  input         channels_read_resps_20_ready,
  output        channels_read_resps_20_valid,
  output [80:0] channels_read_resps_20_bits,
  input         channels_read_resps_21_ready,
  output        channels_read_resps_21_valid,
  output [80:0] channels_read_resps_21_bits,
  input         channels_read_resps_22_ready,
  output        channels_read_resps_22_valid,
  output [80:0] channels_read_resps_22_bits,
  input         channels_read_resps_23_ready,
  output        channels_read_resps_23_valid,
  output [80:0] channels_read_resps_23_bits,
  input         channels_read_resps_24_ready,
  output        channels_read_resps_24_valid,
  output [80:0] channels_read_resps_24_bits,
  input         channels_read_resps_25_ready,
  output        channels_read_resps_25_valid,
  output [80:0] channels_read_resps_25_bits,
  input         channels_read_resps_26_ready,
  output        channels_read_resps_26_valid,
  output [80:0] channels_read_resps_26_bits,
  input         channels_read_resps_27_ready,
  output        channels_read_resps_27_valid,
  output [80:0] channels_read_resps_27_bits,
  input         channels_read_resps_28_ready,
  output        channels_read_resps_28_valid,
  output [80:0] channels_read_resps_28_bits,
  input         channels_read_resps_29_ready,
  output        channels_read_resps_29_valid,
  output [80:0] channels_read_resps_29_bits,
  input         channels_read_resps_30_ready,
  output        channels_read_resps_30_valid,
  output [80:0] channels_read_resps_30_bits,
  input         channels_read_resps_31_ready,
  output        channels_read_resps_31_valid,
  output [80:0] channels_read_resps_31_bits,
  input         channels_read_resps_32_ready,
  output        channels_read_resps_32_valid,
  output [80:0] channels_read_resps_32_bits,
  input         channels_read_resps_33_ready,
  output        channels_read_resps_33_valid,
  output [80:0] channels_read_resps_33_bits,
  input         channels_read_resps_34_ready,
  output        channels_read_resps_34_valid,
  output [80:0] channels_read_resps_34_bits,
  output        channels_write_cmds_0_ready,
  input         channels_write_cmds_0_valid,
  input         channels_write_cmds_0_bits_en,
  input         channels_write_cmds_0_bits_mask,
  input  [8:0]  channels_write_cmds_0_bits_addr,
  input  [80:0] channels_write_cmds_0_bits_data,
 input [8:0] proof_watch, output [8:0] proof_word,
 output proof_write_enable, output [8:0] proof_write_address,
 output [80:0] proof_write_data, output [8:0] proof_pipeline, output [8:0] proof_read_address
);
`ifdef RANDOMIZE_MEM_INIT
  reg [95:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [31:0] _RAND_19;
  reg [31:0] _RAND_20;
  reg [31:0] _RAND_21;
  reg [31:0] _RAND_22;
  reg [31:0] _RAND_23;
  reg [31:0] _RAND_24;
  reg [31:0] _RAND_25;
  reg [31:0] _RAND_26;
  reg [31:0] _RAND_27;
  reg [31:0] _RAND_28;
  reg [31:0] _RAND_29;
  reg [31:0] _RAND_30;
  reg [31:0] _RAND_31;
  reg [31:0] _RAND_32;
  reg [31:0] _RAND_33;
  reg [31:0] _RAND_34;
  reg [31:0] _RAND_35;
  reg [95:0] _RAND_36;
  reg [95:0] _RAND_37;
  reg [95:0] _RAND_38;
  reg [95:0] _RAND_39;
  reg [95:0] _RAND_40;
  reg [95:0] _RAND_41;
  reg [95:0] _RAND_42;
  reg [95:0] _RAND_43;
  reg [95:0] _RAND_44;
  reg [95:0] _RAND_45;
  reg [95:0] _RAND_46;
  reg [95:0] _RAND_47;
  reg [95:0] _RAND_48;
  reg [95:0] _RAND_49;
  reg [95:0] _RAND_50;
  reg [95:0] _RAND_51;
  reg [95:0] _RAND_52;
  reg [95:0] _RAND_53;
  reg [95:0] _RAND_54;
  reg [95:0] _RAND_55;
  reg [95:0] _RAND_56;
  reg [95:0] _RAND_57;
  reg [95:0] _RAND_58;
  reg [95:0] _RAND_59;
  reg [95:0] _RAND_60;
  reg [95:0] _RAND_61;
  reg [95:0] _RAND_62;
  reg [95:0] _RAND_63;
  reg [95:0] _RAND_64;
  reg [95:0] _RAND_65;
  reg [95:0] _RAND_66;
  reg [95:0] _RAND_67;
  reg [95:0] _RAND_68;
  reg [95:0] _RAND_69;
  reg [95:0] _RAND_70;
  reg [95:0] _RAND_71;
  reg [31:0] _RAND_72;
`endif // RANDOMIZE_REG_INIT
  reg [80:0] data [0:511]; // @[AsyncMemModel.scala 62:17]
  wire  data_read_data_async_en; // @[AsyncMemModel.scala 62:17 67:34]
  wire [8:0] data_read_data_async_addr; // @[AsyncMemModel.scala 62:17 121:{35,54}]
  wire [80:0] data_read_data_async_data; // @[AsyncMemModel.scala 62:17]
  wire [80:0] data_MPORT_data; // @[AsyncMemModel.scala 62:17 141:21 150:40 152:25]
  wire [8:0] data_MPORT_addr; // @[AsyncMemModel.scala 62:17 69:66]
  wire  data_MPORT_mask; // @[AsyncMemModel.scala 62:17 69:66]
  wire  data_MPORT_en; // @[AsyncMemModel.scala 62:17 69:48]
  reg [1:0] read_state_34; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_34 = read_state_34 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_34 = read_state_34 == 2'h0 & channels_read_cmds_34_valid; // @[AsyncMemModel.scala 77:96]
  reg [1:0] read_state_0; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T = read_state_0 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_0 = read_state_0 == 2'h0 & channels_read_cmds_0_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_1 = ~read_access_req_0; // @[AsyncMemModel.scala 80:96]
  reg [1:0] read_state_1; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_1 = read_state_1 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_1 = read_state_1 == 2'h0 & channels_read_cmds_1_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_2 = read_access_available_1 & ~read_access_req_1; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_2; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_2 = read_state_2 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_2 = read_state_2 == 2'h0 & channels_read_cmds_2_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_3 = read_access_available_2 & ~read_access_req_2; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_3; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_3 = read_state_3 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_3 = read_state_3 == 2'h0 & channels_read_cmds_3_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_4 = read_access_available_3 & ~read_access_req_3; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_4; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_4 = read_state_4 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_4 = read_state_4 == 2'h0 & channels_read_cmds_4_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_5 = read_access_available_4 & ~read_access_req_4; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_5; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_5 = read_state_5 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_5 = read_state_5 == 2'h0 & channels_read_cmds_5_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_6 = read_access_available_5 & ~read_access_req_5; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_6; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_6 = read_state_6 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_6 = read_state_6 == 2'h0 & channels_read_cmds_6_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_7 = read_access_available_6 & ~read_access_req_6; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_7; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_7 = read_state_7 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_7 = read_state_7 == 2'h0 & channels_read_cmds_7_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_8 = read_access_available_7 & ~read_access_req_7; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_8; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_8 = read_state_8 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_8 = read_state_8 == 2'h0 & channels_read_cmds_8_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_9 = read_access_available_8 & ~read_access_req_8; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_9; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_9 = read_state_9 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_9 = read_state_9 == 2'h0 & channels_read_cmds_9_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_10 = read_access_available_9 & ~read_access_req_9; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_10; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_10 = read_state_10 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_10 = read_state_10 == 2'h0 & channels_read_cmds_10_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_11 = read_access_available_10 & ~read_access_req_10; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_11; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_11 = read_state_11 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_11 = read_state_11 == 2'h0 & channels_read_cmds_11_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_12 = read_access_available_11 & ~read_access_req_11; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_12; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_12 = read_state_12 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_12 = read_state_12 == 2'h0 & channels_read_cmds_12_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_13 = read_access_available_12 & ~read_access_req_12; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_13; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_13 = read_state_13 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_13 = read_state_13 == 2'h0 & channels_read_cmds_13_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_14 = read_access_available_13 & ~read_access_req_13; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_14; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_14 = read_state_14 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_14 = read_state_14 == 2'h0 & channels_read_cmds_14_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_15 = read_access_available_14 & ~read_access_req_14; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_15; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_15 = read_state_15 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_15 = read_state_15 == 2'h0 & channels_read_cmds_15_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_16 = read_access_available_15 & ~read_access_req_15; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_16; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_16 = read_state_16 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_16 = read_state_16 == 2'h0 & channels_read_cmds_16_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_17 = read_access_available_16 & ~read_access_req_16; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_17; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_17 = read_state_17 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_17 = read_state_17 == 2'h0 & channels_read_cmds_17_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_18 = read_access_available_17 & ~read_access_req_17; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_18; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_18 = read_state_18 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_18 = read_state_18 == 2'h0 & channels_read_cmds_18_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_19 = read_access_available_18 & ~read_access_req_18; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_19; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_19 = read_state_19 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_19 = read_state_19 == 2'h0 & channels_read_cmds_19_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_20 = read_access_available_19 & ~read_access_req_19; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_20; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_20 = read_state_20 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_20 = read_state_20 == 2'h0 & channels_read_cmds_20_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_21 = read_access_available_20 & ~read_access_req_20; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_21; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_21 = read_state_21 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_21 = read_state_21 == 2'h0 & channels_read_cmds_21_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_22 = read_access_available_21 & ~read_access_req_21; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_22; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_22 = read_state_22 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_22 = read_state_22 == 2'h0 & channels_read_cmds_22_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_23 = read_access_available_22 & ~read_access_req_22; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_23; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_23 = read_state_23 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_23 = read_state_23 == 2'h0 & channels_read_cmds_23_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_24 = read_access_available_23 & ~read_access_req_23; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_24; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_24 = read_state_24 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_24 = read_state_24 == 2'h0 & channels_read_cmds_24_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_25 = read_access_available_24 & ~read_access_req_24; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_25; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_25 = read_state_25 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_25 = read_state_25 == 2'h0 & channels_read_cmds_25_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_26 = read_access_available_25 & ~read_access_req_25; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_26; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_26 = read_state_26 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_26 = read_state_26 == 2'h0 & channels_read_cmds_26_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_27 = read_access_available_26 & ~read_access_req_26; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_27; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_27 = read_state_27 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_27 = read_state_27 == 2'h0 & channels_read_cmds_27_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_28 = read_access_available_27 & ~read_access_req_27; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_28; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_28 = read_state_28 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_28 = read_state_28 == 2'h0 & channels_read_cmds_28_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_29 = read_access_available_28 & ~read_access_req_28; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_29; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_29 = read_state_29 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_29 = read_state_29 == 2'h0 & channels_read_cmds_29_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_30 = read_access_available_29 & ~read_access_req_29; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_30; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_30 = read_state_30 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_30 = read_state_30 == 2'h0 & channels_read_cmds_30_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_31 = read_access_available_30 & ~read_access_req_30; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_31; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_31 = read_state_31 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_31 = read_state_31 == 2'h0 & channels_read_cmds_31_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_32 = read_access_available_31 & ~read_access_req_31; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_32; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_32 = read_state_32 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_32 = read_state_32 == 2'h0 & channels_read_cmds_32_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_33 = read_access_available_32 & ~read_access_req_32; // @[AsyncMemModel.scala 80:93]
  reg [1:0] read_state_33; // @[AsyncMemModel.scala 75:23]
  wire  _read_access_req_T_33 = read_state_33 == 2'h0; // @[AsyncMemModel.scala 77:86]
  wire  read_access_req_33 = read_state_33 == 2'h0 & channels_read_cmds_33_valid; // @[AsyncMemModel.scala 77:96]
  wire  read_access_available_34 = read_access_available_33 & ~read_access_req_33; // @[AsyncMemModel.scala 80:93]
  wire  read_access_granted_34 = read_access_req_34 & read_access_available_34; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_33 = read_access_req_33 & read_access_available_33; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_32 = read_access_req_32 & read_access_available_32; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_31 = read_access_req_31 & read_access_available_31; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_30 = read_access_req_30 & read_access_available_30; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_29 = read_access_req_29 & read_access_available_29; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_28 = read_access_req_28 & read_access_available_28; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_27 = read_access_req_27 & read_access_available_27; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_26 = read_access_req_26 & read_access_available_26; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_25 = read_access_req_25 & read_access_available_25; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_24 = read_access_req_24 & read_access_available_24; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_23 = read_access_req_23 & read_access_available_23; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_22 = read_access_req_22 & read_access_available_22; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_21 = read_access_req_21 & read_access_available_21; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_20 = read_access_req_20 & read_access_available_20; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_19 = read_access_req_19 & read_access_available_19; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_18 = read_access_req_18 & read_access_available_18; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_17 = read_access_req_17 & read_access_available_17; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_16 = read_access_req_16 & read_access_available_16; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_15 = read_access_req_15 & read_access_available_15; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_14 = read_access_req_14 & read_access_available_14; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_13 = read_access_req_13 & read_access_available_13; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_12 = read_access_req_12 & read_access_available_12; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_11 = read_access_req_11 & read_access_available_11; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_10 = read_access_req_10 & read_access_available_10; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_9 = read_access_req_9 & read_access_available_9; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_8 = read_access_req_8 & read_access_available_8; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_7 = read_access_req_7 & read_access_available_7; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_6 = read_access_req_6 & read_access_available_6; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_5 = read_access_req_5 & read_access_available_5; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_4 = read_access_req_4 & read_access_available_4; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_3 = read_access_req_3 & read_access_available_3; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_2 = read_access_req_2 & read_access_available_2; // @[AsyncMemModel.scala 49:50]
  wire  read_access_granted_1 = read_access_req_1 & read_access_available_1; // @[AsyncMemModel.scala 49:50]
  wire [8:0] _GEN_17 = read_access_granted_1 ? channels_read_cmds_1_bits_addr : channels_read_cmds_0_bits_addr; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_25 = read_access_granted_2 ? channels_read_cmds_2_bits_addr : _GEN_17; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_33 = read_access_granted_3 ? channels_read_cmds_3_bits_addr : _GEN_25; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_41 = read_access_granted_4 ? channels_read_cmds_4_bits_addr : _GEN_33; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_49 = read_access_granted_5 ? channels_read_cmds_5_bits_addr : _GEN_41; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_57 = read_access_granted_6 ? channels_read_cmds_6_bits_addr : _GEN_49; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_65 = read_access_granted_7 ? channels_read_cmds_7_bits_addr : _GEN_57; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_73 = read_access_granted_8 ? channels_read_cmds_8_bits_addr : _GEN_65; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_81 = read_access_granted_9 ? channels_read_cmds_9_bits_addr : _GEN_73; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_89 = read_access_granted_10 ? channels_read_cmds_10_bits_addr : _GEN_81; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_97 = read_access_granted_11 ? channels_read_cmds_11_bits_addr : _GEN_89; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_105 = read_access_granted_12 ? channels_read_cmds_12_bits_addr : _GEN_97; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_113 = read_access_granted_13 ? channels_read_cmds_13_bits_addr : _GEN_105; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_121 = read_access_granted_14 ? channels_read_cmds_14_bits_addr : _GEN_113; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_129 = read_access_granted_15 ? channels_read_cmds_15_bits_addr : _GEN_121; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_137 = read_access_granted_16 ? channels_read_cmds_16_bits_addr : _GEN_129; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_145 = read_access_granted_17 ? channels_read_cmds_17_bits_addr : _GEN_137; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_153 = read_access_granted_18 ? channels_read_cmds_18_bits_addr : _GEN_145; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_161 = read_access_granted_19 ? channels_read_cmds_19_bits_addr : _GEN_153; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_169 = read_access_granted_20 ? channels_read_cmds_20_bits_addr : _GEN_161; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_177 = read_access_granted_21 ? channels_read_cmds_21_bits_addr : _GEN_169; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_185 = read_access_granted_22 ? channels_read_cmds_22_bits_addr : _GEN_177; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_193 = read_access_granted_23 ? channels_read_cmds_23_bits_addr : _GEN_185; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_201 = read_access_granted_24 ? channels_read_cmds_24_bits_addr : _GEN_193; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_209 = read_access_granted_25 ? channels_read_cmds_25_bits_addr : _GEN_201; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_217 = read_access_granted_26 ? channels_read_cmds_26_bits_addr : _GEN_209; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_225 = read_access_granted_27 ? channels_read_cmds_27_bits_addr : _GEN_217; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_233 = read_access_granted_28 ? channels_read_cmds_28_bits_addr : _GEN_225; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_241 = read_access_granted_29 ? channels_read_cmds_29_bits_addr : _GEN_233; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_249 = read_access_granted_30 ? channels_read_cmds_30_bits_addr : _GEN_241; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_257 = read_access_granted_31 ? channels_read_cmds_31_bits_addr : _GEN_249; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_265 = read_access_granted_32 ? channels_read_cmds_32_bits_addr : _GEN_257; // @[AsyncMemModel.scala 121:{35,54}]
  wire [8:0] _GEN_273 = read_access_granted_33 ? channels_read_cmds_33_bits_addr : _GEN_265; // @[AsyncMemModel.scala 121:{35,54}]
  reg [80:0] read_data; // @[AsyncMemModel.scala 68:26]
  wire  _T_293 = channels_write_cmds_0_ready & channels_write_cmds_0_valid; // @[Decoupled.scala 51:35]
  wire  _active_write_en_T = channels_write_cmds_0_bits_en & channels_write_cmds_0_bits_mask; // @[RegfileModel.scala 25:19]
  wire  active_write_en = _T_293 & _active_write_en_T; // @[AsyncMemModel.scala 142:19 150:40 153:23]
  reg [80:0] read_resp_data_0; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_1; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_2; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_3; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_4; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_5; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_6; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_7; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_8; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_9; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_10; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_11; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_12; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_13; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_14; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_15; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_16; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_17; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_18; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_19; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_20; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_21; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_22; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_23; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_24; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_25; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_26; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_27; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_28; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_29; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_30; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_31; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_32; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_33; // @[AsyncMemModel.scala 76:27]
  reg [80:0] read_resp_data_34; // @[AsyncMemModel.scala 76:27]
  wire  _reads_done_T_30 = read_state_15 != 2'h0; // @[AsyncMemModel.scala 84:92]
  wire  _reads_done_T_31 = read_state_0 != 2'h0 & read_state_1 != 2'h0 & read_state_2 != 2'h0 & read_state_3 != 2'h0 &
    read_state_4 != 2'h0 & read_state_5 != 2'h0 & read_state_6 != 2'h0 & read_state_7 != 2'h0 & read_state_8 != 2'h0 &
    read_state_9 != 2'h0 & read_state_10 != 2'h0 & read_state_11 != 2'h0 & read_state_12 != 2'h0 & read_state_13 != 2'h0
     & read_state_14 != 2'h0 & _reads_done_T_30; // @[AsyncMemModel.scala 84:87]
  wire  _reads_done_T_61 = _reads_done_T_31 & read_state_16 != 2'h0 & read_state_17 != 2'h0 & read_state_18 != 2'h0 &
    read_state_19 != 2'h0 & read_state_20 != 2'h0 & read_state_21 != 2'h0 & read_state_22 != 2'h0 & read_state_23 != 2'h0
     & read_state_24 != 2'h0 & read_state_25 != 2'h0 & read_state_26 != 2'h0 & read_state_27 != 2'h0 & read_state_28 != 2'h0
     & read_state_29 != 2'h0 & read_state_30 != 2'h0; // @[AsyncMemModel.scala 84:87]
  wire  reads_done = _reads_done_T_61 & read_state_31 != 2'h0 & read_state_32 != 2'h0 & read_state_33 != 2'h0 &
    read_state_34 != 2'h0; // @[AsyncMemModel.scala 84:87]
  wire  _outputs_responded_or_firing_T_1 = channels_read_resps_0_ready & channels_read_resps_0_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_5 = channels_read_resps_1_ready & channels_read_resps_1_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_9 = channels_read_resps_2_ready & channels_read_resps_2_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_13 = channels_read_resps_3_ready & channels_read_resps_3_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_17 = channels_read_resps_4_ready & channels_read_resps_4_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_21 = channels_read_resps_5_ready & channels_read_resps_5_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_25 = channels_read_resps_6_ready & channels_read_resps_6_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_29 = channels_read_resps_7_ready & channels_read_resps_7_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_33 = channels_read_resps_8_ready & channels_read_resps_8_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_37 = channels_read_resps_9_ready & channels_read_resps_9_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_41 = channels_read_resps_10_ready & channels_read_resps_10_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_42 = read_state_10 == 2'h3 | _outputs_responded_or_firing_T_41; // @[AsyncMemModel.scala 93:54]
  wire  _outputs_responded_or_firing_T_43 = (read_state_0 == 2'h3 | _outputs_responded_or_firing_T_1) & (read_state_1
     == 2'h3 | _outputs_responded_or_firing_T_5) & (read_state_2 == 2'h3 | _outputs_responded_or_firing_T_9) & (
    read_state_3 == 2'h3 | _outputs_responded_or_firing_T_13) & (read_state_4 == 2'h3 |
    _outputs_responded_or_firing_T_17) & (read_state_5 == 2'h3 | _outputs_responded_or_firing_T_21) & (read_state_6 == 2'h3
     | _outputs_responded_or_firing_T_25) & (read_state_7 == 2'h3 | _outputs_responded_or_firing_T_29) & (read_state_8
     == 2'h3 | _outputs_responded_or_firing_T_33) & (read_state_9 == 2'h3 | _outputs_responded_or_firing_T_37) &
    _outputs_responded_or_firing_T_42; // @[AsyncMemModel.scala 93:34]
  wire  _outputs_responded_or_firing_T_45 = channels_read_resps_11_ready & channels_read_resps_11_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_49 = channels_read_resps_12_ready & channels_read_resps_12_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_53 = channels_read_resps_13_ready & channels_read_resps_13_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_57 = channels_read_resps_14_ready & channels_read_resps_14_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_61 = channels_read_resps_15_ready & channels_read_resps_15_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_65 = channels_read_resps_16_ready & channels_read_resps_16_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_69 = channels_read_resps_17_ready & channels_read_resps_17_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_73 = channels_read_resps_18_ready & channels_read_resps_18_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_77 = channels_read_resps_19_ready & channels_read_resps_19_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_81 = channels_read_resps_20_ready & channels_read_resps_20_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_83 = _outputs_responded_or_firing_T_43 & (read_state_11 == 2'h3 |
    _outputs_responded_or_firing_T_45) & (read_state_12 == 2'h3 | _outputs_responded_or_firing_T_49) & (read_state_13
     == 2'h3 | _outputs_responded_or_firing_T_53) & (read_state_14 == 2'h3 | _outputs_responded_or_firing_T_57) & (
    read_state_15 == 2'h3 | _outputs_responded_or_firing_T_61) & (read_state_16 == 2'h3 |
    _outputs_responded_or_firing_T_65) & (read_state_17 == 2'h3 | _outputs_responded_or_firing_T_69) & (read_state_18
     == 2'h3 | _outputs_responded_or_firing_T_73) & (read_state_19 == 2'h3 | _outputs_responded_or_firing_T_77) & (
    read_state_20 == 2'h3 | _outputs_responded_or_firing_T_81); // @[AsyncMemModel.scala 93:34]
  wire  _outputs_responded_or_firing_T_85 = channels_read_resps_21_ready & channels_read_resps_21_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_89 = channels_read_resps_22_ready & channels_read_resps_22_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_93 = channels_read_resps_23_ready & channels_read_resps_23_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_97 = channels_read_resps_24_ready & channels_read_resps_24_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_101 = channels_read_resps_25_ready & channels_read_resps_25_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_105 = channels_read_resps_26_ready & channels_read_resps_26_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_109 = channels_read_resps_27_ready & channels_read_resps_27_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_113 = channels_read_resps_28_ready & channels_read_resps_28_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_117 = channels_read_resps_29_ready & channels_read_resps_29_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_121 = channels_read_resps_30_ready & channels_read_resps_30_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_123 = _outputs_responded_or_firing_T_83 & (read_state_21 == 2'h3 |
    _outputs_responded_or_firing_T_85) & (read_state_22 == 2'h3 | _outputs_responded_or_firing_T_89) & (read_state_23
     == 2'h3 | _outputs_responded_or_firing_T_93) & (read_state_24 == 2'h3 | _outputs_responded_or_firing_T_97) & (
    read_state_25 == 2'h3 | _outputs_responded_or_firing_T_101) & (read_state_26 == 2'h3 |
    _outputs_responded_or_firing_T_105) & (read_state_27 == 2'h3 | _outputs_responded_or_firing_T_109) & (read_state_28
     == 2'h3 | _outputs_responded_or_firing_T_113) & (read_state_29 == 2'h3 | _outputs_responded_or_firing_T_117) & (
    read_state_30 == 2'h3 | _outputs_responded_or_firing_T_121); // @[AsyncMemModel.scala 93:34]
  wire  _outputs_responded_or_firing_T_125 = channels_read_resps_31_ready & channels_read_resps_31_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_129 = channels_read_resps_32_ready & channels_read_resps_32_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_133 = channels_read_resps_33_ready & channels_read_resps_33_valid; // @[Decoupled.scala 51:35]
  wire  _outputs_responded_or_firing_T_137 = channels_read_resps_34_ready & channels_read_resps_34_valid; // @[Decoupled.scala 51:35]
  wire  outputs_responded_or_firing = _outputs_responded_or_firing_T_123 & (read_state_31 == 2'h3 |
    _outputs_responded_or_firing_T_125) & (read_state_32 == 2'h3 | _outputs_responded_or_firing_T_129) & (read_state_33
     == 2'h3 | _outputs_responded_or_firing_T_133) & (read_state_34 == 2'h3 | _outputs_responded_or_firing_T_137); // @[AsyncMemModel.scala 93:34]
  reg  write_complete_0; // @[AsyncMemModel.scala 97:27]
  wire  writes_done_or_finishing = write_complete_0 | _T_293; // @[AsyncMemModel.scala 104:53]
  wire  advance_cycle = outputs_responded_or_firing & writes_done_or_finishing; // @[AsyncMemModel.scala 107:51]
  wire  _T_8 = advance_cycle | reset; // @[AsyncMemModel.scala 111:23]
  wire  _channels_read_resps_0_bits_T = read_state_0 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_0_valid_T_1 = read_state_0 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_1_bits_T = read_state_1 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_1_valid_T_1 = read_state_1 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_2_bits_T = read_state_2 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_2_valid_T_1 = read_state_2 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_3_bits_T = read_state_3 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_3_valid_T_1 = read_state_3 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_4_bits_T = read_state_4 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_4_valid_T_1 = read_state_4 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_5_bits_T = read_state_5 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_5_valid_T_1 = read_state_5 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_6_bits_T = read_state_6 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_6_valid_T_1 = read_state_6 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_7_bits_T = read_state_7 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_7_valid_T_1 = read_state_7 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_8_bits_T = read_state_8 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_8_valid_T_1 = read_state_8 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_9_bits_T = read_state_9 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_9_valid_T_1 = read_state_9 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_10_bits_T = read_state_10 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_10_valid_T_1 = read_state_10 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_11_bits_T = read_state_11 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_11_valid_T_1 = read_state_11 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_12_bits_T = read_state_12 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_12_valid_T_1 = read_state_12 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_13_bits_T = read_state_13 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_13_valid_T_1 = read_state_13 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_14_bits_T = read_state_14 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_14_valid_T_1 = read_state_14 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_15_bits_T = read_state_15 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_15_valid_T_1 = read_state_15 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_16_bits_T = read_state_16 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_16_valid_T_1 = read_state_16 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_17_bits_T = read_state_17 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_17_valid_T_1 = read_state_17 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_18_bits_T = read_state_18 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_18_valid_T_1 = read_state_18 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_19_bits_T = read_state_19 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_19_valid_T_1 = read_state_19 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_20_bits_T = read_state_20 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_20_valid_T_1 = read_state_20 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_21_bits_T = read_state_21 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_21_valid_T_1 = read_state_21 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_22_bits_T = read_state_22 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_22_valid_T_1 = read_state_22 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_23_bits_T = read_state_23 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_23_valid_T_1 = read_state_23 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_24_bits_T = read_state_24 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_24_valid_T_1 = read_state_24 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_25_bits_T = read_state_25 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_25_valid_T_1 = read_state_25 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_26_bits_T = read_state_26 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_26_valid_T_1 = read_state_26 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_27_bits_T = read_state_27 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_27_valid_T_1 = read_state_27 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_28_bits_T = read_state_28 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_28_valid_T_1 = read_state_28 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_29_bits_T = read_state_29 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_29_valid_T_1 = read_state_29 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_30_bits_T = read_state_30 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_30_valid_T_1 = read_state_30 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_31_bits_T = read_state_31 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_31_valid_T_1 = read_state_31 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_32_bits_T = read_state_32 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_32_valid_T_1 = read_state_32 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_33_bits_T = read_state_33 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_33_valid_T_1 = read_state_33 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _channels_read_resps_34_bits_T = read_state_34 == 2'h1; // @[AsyncMemModel.scala 124:54]
  wire  _channels_read_resps_34_valid_T_1 = read_state_34 == 2'h2; // @[AsyncMemModel.scala 125:79]
  wire  _GEN_289 = _T_293 | write_complete_0; // @[AsyncMemModel.scala 147:47 148:25 97:27]
  assign data_read_data_async_en = 1'h1; // @[AsyncMemModel.scala 67:34]
  assign data_read_data_async_addr = read_access_granted_34 ? channels_read_cmds_34_bits_addr : _GEN_273; // @[AsyncMemModel.scala 121:{35,54}]
  assign data_read_data_async_data = data[data_read_data_async_addr]; // @[AsyncMemModel.scala 62:17]
  assign data_MPORT_data = channels_write_cmds_0_bits_data; // @[AsyncMemModel.scala 141:21 150:40 152:25]
  assign data_MPORT_addr = channels_write_cmds_0_bits_addr; // @[AsyncMemModel.scala 69:66]
  assign data_MPORT_mask = 1'h1; // @[AsyncMemModel.scala 69:66]
  assign data_MPORT_en = active_write_en & ~reset; // @[AsyncMemModel.scala 69:48]
  assign channels_read_cmds_0_ready = read_state_0 == 2'h0; // @[AsyncMemModel.scala 123:50]
  assign channels_read_cmds_1_ready = _read_access_req_T_1 & read_access_available_1; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_2_ready = _read_access_req_T_2 & read_access_available_2; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_3_ready = _read_access_req_T_3 & read_access_available_3; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_4_ready = _read_access_req_T_4 & read_access_available_4; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_5_ready = _read_access_req_T_5 & read_access_available_5; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_6_ready = _read_access_req_T_6 & read_access_available_6; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_7_ready = _read_access_req_T_7 & read_access_available_7; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_8_ready = _read_access_req_T_8 & read_access_available_8; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_9_ready = _read_access_req_T_9 & read_access_available_9; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_10_ready = _read_access_req_T_10 & read_access_available_10; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_11_ready = _read_access_req_T_11 & read_access_available_11; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_12_ready = _read_access_req_T_12 & read_access_available_12; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_13_ready = _read_access_req_T_13 & read_access_available_13; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_14_ready = _read_access_req_T_14 & read_access_available_14; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_15_ready = _read_access_req_T_15 & read_access_available_15; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_16_ready = _read_access_req_T_16 & read_access_available_16; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_17_ready = _read_access_req_T_17 & read_access_available_17; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_18_ready = _read_access_req_T_18 & read_access_available_18; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_19_ready = _read_access_req_T_19 & read_access_available_19; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_20_ready = _read_access_req_T_20 & read_access_available_20; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_21_ready = _read_access_req_T_21 & read_access_available_21; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_22_ready = _read_access_req_T_22 & read_access_available_22; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_23_ready = _read_access_req_T_23 & read_access_available_23; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_24_ready = _read_access_req_T_24 & read_access_available_24; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_25_ready = _read_access_req_T_25 & read_access_available_25; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_26_ready = _read_access_req_T_26 & read_access_available_26; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_27_ready = _read_access_req_T_27 & read_access_available_27; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_28_ready = _read_access_req_T_28 & read_access_available_28; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_29_ready = _read_access_req_T_29 & read_access_available_29; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_30_ready = _read_access_req_T_30 & read_access_available_30; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_31_ready = _read_access_req_T_31 & read_access_available_31; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_32_ready = _read_access_req_T_32 & read_access_available_32; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_33_ready = _read_access_req_T_33 & read_access_available_33; // @[AsyncMemModel.scala 123:60]
  assign channels_read_cmds_34_ready = _read_access_req_T_34 & read_access_available_34; // @[AsyncMemModel.scala 123:60]
  assign channels_read_resps_0_valid = _channels_read_resps_0_bits_T | read_state_0 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_0_bits = read_state_0 == 2'h1 ? read_data : read_resp_data_0; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_1_valid = _channels_read_resps_1_bits_T | read_state_1 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_1_bits = read_state_1 == 2'h1 ? read_data : read_resp_data_1; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_2_valid = _channels_read_resps_2_bits_T | read_state_2 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_2_bits = read_state_2 == 2'h1 ? read_data : read_resp_data_2; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_3_valid = _channels_read_resps_3_bits_T | read_state_3 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_3_bits = read_state_3 == 2'h1 ? read_data : read_resp_data_3; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_4_valid = _channels_read_resps_4_bits_T | read_state_4 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_4_bits = read_state_4 == 2'h1 ? read_data : read_resp_data_4; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_5_valid = _channels_read_resps_5_bits_T | read_state_5 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_5_bits = read_state_5 == 2'h1 ? read_data : read_resp_data_5; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_6_valid = _channels_read_resps_6_bits_T | read_state_6 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_6_bits = read_state_6 == 2'h1 ? read_data : read_resp_data_6; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_7_valid = _channels_read_resps_7_bits_T | read_state_7 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_7_bits = read_state_7 == 2'h1 ? read_data : read_resp_data_7; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_8_valid = _channels_read_resps_8_bits_T | read_state_8 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_8_bits = read_state_8 == 2'h1 ? read_data : read_resp_data_8; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_9_valid = _channels_read_resps_9_bits_T | read_state_9 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_9_bits = read_state_9 == 2'h1 ? read_data : read_resp_data_9; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_10_valid = _channels_read_resps_10_bits_T | read_state_10 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_10_bits = read_state_10 == 2'h1 ? read_data : read_resp_data_10; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_11_valid = _channels_read_resps_11_bits_T | read_state_11 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_11_bits = read_state_11 == 2'h1 ? read_data : read_resp_data_11; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_12_valid = _channels_read_resps_12_bits_T | read_state_12 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_12_bits = read_state_12 == 2'h1 ? read_data : read_resp_data_12; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_13_valid = _channels_read_resps_13_bits_T | read_state_13 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_13_bits = read_state_13 == 2'h1 ? read_data : read_resp_data_13; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_14_valid = _channels_read_resps_14_bits_T | read_state_14 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_14_bits = read_state_14 == 2'h1 ? read_data : read_resp_data_14; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_15_valid = _channels_read_resps_15_bits_T | read_state_15 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_15_bits = read_state_15 == 2'h1 ? read_data : read_resp_data_15; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_16_valid = _channels_read_resps_16_bits_T | read_state_16 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_16_bits = read_state_16 == 2'h1 ? read_data : read_resp_data_16; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_17_valid = _channels_read_resps_17_bits_T | read_state_17 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_17_bits = read_state_17 == 2'h1 ? read_data : read_resp_data_17; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_18_valid = _channels_read_resps_18_bits_T | read_state_18 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_18_bits = read_state_18 == 2'h1 ? read_data : read_resp_data_18; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_19_valid = _channels_read_resps_19_bits_T | read_state_19 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_19_bits = read_state_19 == 2'h1 ? read_data : read_resp_data_19; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_20_valid = _channels_read_resps_20_bits_T | read_state_20 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_20_bits = read_state_20 == 2'h1 ? read_data : read_resp_data_20; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_21_valid = _channels_read_resps_21_bits_T | read_state_21 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_21_bits = read_state_21 == 2'h1 ? read_data : read_resp_data_21; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_22_valid = _channels_read_resps_22_bits_T | read_state_22 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_22_bits = read_state_22 == 2'h1 ? read_data : read_resp_data_22; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_23_valid = _channels_read_resps_23_bits_T | read_state_23 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_23_bits = read_state_23 == 2'h1 ? read_data : read_resp_data_23; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_24_valid = _channels_read_resps_24_bits_T | read_state_24 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_24_bits = read_state_24 == 2'h1 ? read_data : read_resp_data_24; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_25_valid = _channels_read_resps_25_bits_T | read_state_25 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_25_bits = read_state_25 == 2'h1 ? read_data : read_resp_data_25; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_26_valid = _channels_read_resps_26_bits_T | read_state_26 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_26_bits = read_state_26 == 2'h1 ? read_data : read_resp_data_26; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_27_valid = _channels_read_resps_27_bits_T | read_state_27 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_27_bits = read_state_27 == 2'h1 ? read_data : read_resp_data_27; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_28_valid = _channels_read_resps_28_bits_T | read_state_28 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_28_bits = read_state_28 == 2'h1 ? read_data : read_resp_data_28; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_29_valid = _channels_read_resps_29_bits_T | read_state_29 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_29_bits = read_state_29 == 2'h1 ? read_data : read_resp_data_29; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_30_valid = _channels_read_resps_30_bits_T | read_state_30 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_30_bits = read_state_30 == 2'h1 ? read_data : read_resp_data_30; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_31_valid = _channels_read_resps_31_bits_T | read_state_31 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_31_bits = read_state_31 == 2'h1 ? read_data : read_resp_data_31; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_32_valid = _channels_read_resps_32_bits_T | read_state_32 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_32_bits = read_state_32 == 2'h1 ? read_data : read_resp_data_32; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_33_valid = _channels_read_resps_33_bits_T | read_state_33 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_33_bits = read_state_33 == 2'h1 ? read_data : read_resp_data_33; // @[AsyncMemModel.scala 124:39]
  assign channels_read_resps_34_valid = _channels_read_resps_34_bits_T | read_state_34 == 2'h2; // @[AsyncMemModel.scala 125:62]
  assign channels_read_resps_34_bits = read_state_34 == 2'h1 ? read_data : read_resp_data_34; // @[AsyncMemModel.scala 124:39]
  assign channels_write_cmds_0_ready = reads_done & ~write_complete_0; // @[AsyncMemModel.scala 144:58]
  always @(posedge clock) begin
    if (data_MPORT_en & data_MPORT_mask) begin
      data[data_MPORT_addr] <= data_MPORT_data; // @[AsyncMemModel.scala 62:17]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_34 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_34 & read_access_granted_34) begin // @[AsyncMemModel.scala 129:69]
      read_state_34 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_34_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_137) begin // @[AsyncMemModel.scala 132:27]
        read_state_34 <= 2'h3;
      end else begin
        read_state_34 <= 2'h2;
      end
    end else if (_channels_read_resps_34_valid_T_1 & _outputs_responded_or_firing_T_137) begin // @[AsyncMemModel.scala 134:78]
      read_state_34 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_0 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T & read_access_req_0) begin // @[AsyncMemModel.scala 129:69]
      read_state_0 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_0_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_1) begin // @[AsyncMemModel.scala 132:27]
        read_state_0 <= 2'h3;
      end else begin
        read_state_0 <= 2'h2;
      end
    end else if (_channels_read_resps_0_valid_T_1 & _outputs_responded_or_firing_T_1) begin // @[AsyncMemModel.scala 134:78]
      read_state_0 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_1 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_1 & read_access_granted_1) begin // @[AsyncMemModel.scala 129:69]
      read_state_1 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_1_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_5) begin // @[AsyncMemModel.scala 132:27]
        read_state_1 <= 2'h3;
      end else begin
        read_state_1 <= 2'h2;
      end
    end else if (_channels_read_resps_1_valid_T_1 & _outputs_responded_or_firing_T_5) begin // @[AsyncMemModel.scala 134:78]
      read_state_1 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_2 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_2 & read_access_granted_2) begin // @[AsyncMemModel.scala 129:69]
      read_state_2 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_2_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_9) begin // @[AsyncMemModel.scala 132:27]
        read_state_2 <= 2'h3;
      end else begin
        read_state_2 <= 2'h2;
      end
    end else if (_channels_read_resps_2_valid_T_1 & _outputs_responded_or_firing_T_9) begin // @[AsyncMemModel.scala 134:78]
      read_state_2 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_3 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_3 & read_access_granted_3) begin // @[AsyncMemModel.scala 129:69]
      read_state_3 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_3_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_13) begin // @[AsyncMemModel.scala 132:27]
        read_state_3 <= 2'h3;
      end else begin
        read_state_3 <= 2'h2;
      end
    end else if (_channels_read_resps_3_valid_T_1 & _outputs_responded_or_firing_T_13) begin // @[AsyncMemModel.scala 134:78]
      read_state_3 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_4 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_4 & read_access_granted_4) begin // @[AsyncMemModel.scala 129:69]
      read_state_4 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_4_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_17) begin // @[AsyncMemModel.scala 132:27]
        read_state_4 <= 2'h3;
      end else begin
        read_state_4 <= 2'h2;
      end
    end else if (_channels_read_resps_4_valid_T_1 & _outputs_responded_or_firing_T_17) begin // @[AsyncMemModel.scala 134:78]
      read_state_4 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_5 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_5 & read_access_granted_5) begin // @[AsyncMemModel.scala 129:69]
      read_state_5 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_5_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_21) begin // @[AsyncMemModel.scala 132:27]
        read_state_5 <= 2'h3;
      end else begin
        read_state_5 <= 2'h2;
      end
    end else if (_channels_read_resps_5_valid_T_1 & _outputs_responded_or_firing_T_21) begin // @[AsyncMemModel.scala 134:78]
      read_state_5 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_6 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_6 & read_access_granted_6) begin // @[AsyncMemModel.scala 129:69]
      read_state_6 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_6_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_25) begin // @[AsyncMemModel.scala 132:27]
        read_state_6 <= 2'h3;
      end else begin
        read_state_6 <= 2'h2;
      end
    end else if (_channels_read_resps_6_valid_T_1 & _outputs_responded_or_firing_T_25) begin // @[AsyncMemModel.scala 134:78]
      read_state_6 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_7 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_7 & read_access_granted_7) begin // @[AsyncMemModel.scala 129:69]
      read_state_7 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_7_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_29) begin // @[AsyncMemModel.scala 132:27]
        read_state_7 <= 2'h3;
      end else begin
        read_state_7 <= 2'h2;
      end
    end else if (_channels_read_resps_7_valid_T_1 & _outputs_responded_or_firing_T_29) begin // @[AsyncMemModel.scala 134:78]
      read_state_7 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_8 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_8 & read_access_granted_8) begin // @[AsyncMemModel.scala 129:69]
      read_state_8 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_8_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_33) begin // @[AsyncMemModel.scala 132:27]
        read_state_8 <= 2'h3;
      end else begin
        read_state_8 <= 2'h2;
      end
    end else if (_channels_read_resps_8_valid_T_1 & _outputs_responded_or_firing_T_33) begin // @[AsyncMemModel.scala 134:78]
      read_state_8 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_9 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_9 & read_access_granted_9) begin // @[AsyncMemModel.scala 129:69]
      read_state_9 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_9_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_37) begin // @[AsyncMemModel.scala 132:27]
        read_state_9 <= 2'h3;
      end else begin
        read_state_9 <= 2'h2;
      end
    end else if (_channels_read_resps_9_valid_T_1 & _outputs_responded_or_firing_T_37) begin // @[AsyncMemModel.scala 134:78]
      read_state_9 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_10 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_10 & read_access_granted_10) begin // @[AsyncMemModel.scala 129:69]
      read_state_10 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_10_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_41) begin // @[AsyncMemModel.scala 132:27]
        read_state_10 <= 2'h3;
      end else begin
        read_state_10 <= 2'h2;
      end
    end else if (_channels_read_resps_10_valid_T_1 & _outputs_responded_or_firing_T_41) begin // @[AsyncMemModel.scala 134:78]
      read_state_10 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_11 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_11 & read_access_granted_11) begin // @[AsyncMemModel.scala 129:69]
      read_state_11 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_11_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_45) begin // @[AsyncMemModel.scala 132:27]
        read_state_11 <= 2'h3;
      end else begin
        read_state_11 <= 2'h2;
      end
    end else if (_channels_read_resps_11_valid_T_1 & _outputs_responded_or_firing_T_45) begin // @[AsyncMemModel.scala 134:78]
      read_state_11 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_12 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_12 & read_access_granted_12) begin // @[AsyncMemModel.scala 129:69]
      read_state_12 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_12_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_49) begin // @[AsyncMemModel.scala 132:27]
        read_state_12 <= 2'h3;
      end else begin
        read_state_12 <= 2'h2;
      end
    end else if (_channels_read_resps_12_valid_T_1 & _outputs_responded_or_firing_T_49) begin // @[AsyncMemModel.scala 134:78]
      read_state_12 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_13 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_13 & read_access_granted_13) begin // @[AsyncMemModel.scala 129:69]
      read_state_13 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_13_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_53) begin // @[AsyncMemModel.scala 132:27]
        read_state_13 <= 2'h3;
      end else begin
        read_state_13 <= 2'h2;
      end
    end else if (_channels_read_resps_13_valid_T_1 & _outputs_responded_or_firing_T_53) begin // @[AsyncMemModel.scala 134:78]
      read_state_13 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_14 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_14 & read_access_granted_14) begin // @[AsyncMemModel.scala 129:69]
      read_state_14 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_14_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_57) begin // @[AsyncMemModel.scala 132:27]
        read_state_14 <= 2'h3;
      end else begin
        read_state_14 <= 2'h2;
      end
    end else if (_channels_read_resps_14_valid_T_1 & _outputs_responded_or_firing_T_57) begin // @[AsyncMemModel.scala 134:78]
      read_state_14 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_15 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_15 & read_access_granted_15) begin // @[AsyncMemModel.scala 129:69]
      read_state_15 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_15_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_61) begin // @[AsyncMemModel.scala 132:27]
        read_state_15 <= 2'h3;
      end else begin
        read_state_15 <= 2'h2;
      end
    end else if (_channels_read_resps_15_valid_T_1 & _outputs_responded_or_firing_T_61) begin // @[AsyncMemModel.scala 134:78]
      read_state_15 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_16 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_16 & read_access_granted_16) begin // @[AsyncMemModel.scala 129:69]
      read_state_16 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_16_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_65) begin // @[AsyncMemModel.scala 132:27]
        read_state_16 <= 2'h3;
      end else begin
        read_state_16 <= 2'h2;
      end
    end else if (_channels_read_resps_16_valid_T_1 & _outputs_responded_or_firing_T_65) begin // @[AsyncMemModel.scala 134:78]
      read_state_16 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_17 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_17 & read_access_granted_17) begin // @[AsyncMemModel.scala 129:69]
      read_state_17 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_17_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_69) begin // @[AsyncMemModel.scala 132:27]
        read_state_17 <= 2'h3;
      end else begin
        read_state_17 <= 2'h2;
      end
    end else if (_channels_read_resps_17_valid_T_1 & _outputs_responded_or_firing_T_69) begin // @[AsyncMemModel.scala 134:78]
      read_state_17 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_18 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_18 & read_access_granted_18) begin // @[AsyncMemModel.scala 129:69]
      read_state_18 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_18_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_73) begin // @[AsyncMemModel.scala 132:27]
        read_state_18 <= 2'h3;
      end else begin
        read_state_18 <= 2'h2;
      end
    end else if (_channels_read_resps_18_valid_T_1 & _outputs_responded_or_firing_T_73) begin // @[AsyncMemModel.scala 134:78]
      read_state_18 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_19 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_19 & read_access_granted_19) begin // @[AsyncMemModel.scala 129:69]
      read_state_19 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_19_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_77) begin // @[AsyncMemModel.scala 132:27]
        read_state_19 <= 2'h3;
      end else begin
        read_state_19 <= 2'h2;
      end
    end else if (_channels_read_resps_19_valid_T_1 & _outputs_responded_or_firing_T_77) begin // @[AsyncMemModel.scala 134:78]
      read_state_19 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_20 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_20 & read_access_granted_20) begin // @[AsyncMemModel.scala 129:69]
      read_state_20 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_20_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_81) begin // @[AsyncMemModel.scala 132:27]
        read_state_20 <= 2'h3;
      end else begin
        read_state_20 <= 2'h2;
      end
    end else if (_channels_read_resps_20_valid_T_1 & _outputs_responded_or_firing_T_81) begin // @[AsyncMemModel.scala 134:78]
      read_state_20 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_21 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_21 & read_access_granted_21) begin // @[AsyncMemModel.scala 129:69]
      read_state_21 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_21_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_85) begin // @[AsyncMemModel.scala 132:27]
        read_state_21 <= 2'h3;
      end else begin
        read_state_21 <= 2'h2;
      end
    end else if (_channels_read_resps_21_valid_T_1 & _outputs_responded_or_firing_T_85) begin // @[AsyncMemModel.scala 134:78]
      read_state_21 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_22 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_22 & read_access_granted_22) begin // @[AsyncMemModel.scala 129:69]
      read_state_22 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_22_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_89) begin // @[AsyncMemModel.scala 132:27]
        read_state_22 <= 2'h3;
      end else begin
        read_state_22 <= 2'h2;
      end
    end else if (_channels_read_resps_22_valid_T_1 & _outputs_responded_or_firing_T_89) begin // @[AsyncMemModel.scala 134:78]
      read_state_22 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_23 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_23 & read_access_granted_23) begin // @[AsyncMemModel.scala 129:69]
      read_state_23 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_23_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_93) begin // @[AsyncMemModel.scala 132:27]
        read_state_23 <= 2'h3;
      end else begin
        read_state_23 <= 2'h2;
      end
    end else if (_channels_read_resps_23_valid_T_1 & _outputs_responded_or_firing_T_93) begin // @[AsyncMemModel.scala 134:78]
      read_state_23 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_24 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_24 & read_access_granted_24) begin // @[AsyncMemModel.scala 129:69]
      read_state_24 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_24_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_97) begin // @[AsyncMemModel.scala 132:27]
        read_state_24 <= 2'h3;
      end else begin
        read_state_24 <= 2'h2;
      end
    end else if (_channels_read_resps_24_valid_T_1 & _outputs_responded_or_firing_T_97) begin // @[AsyncMemModel.scala 134:78]
      read_state_24 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_25 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_25 & read_access_granted_25) begin // @[AsyncMemModel.scala 129:69]
      read_state_25 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_25_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_101) begin // @[AsyncMemModel.scala 132:27]
        read_state_25 <= 2'h3;
      end else begin
        read_state_25 <= 2'h2;
      end
    end else if (_channels_read_resps_25_valid_T_1 & _outputs_responded_or_firing_T_101) begin // @[AsyncMemModel.scala 134:78]
      read_state_25 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_26 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_26 & read_access_granted_26) begin // @[AsyncMemModel.scala 129:69]
      read_state_26 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_26_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_105) begin // @[AsyncMemModel.scala 132:27]
        read_state_26 <= 2'h3;
      end else begin
        read_state_26 <= 2'h2;
      end
    end else if (_channels_read_resps_26_valid_T_1 & _outputs_responded_or_firing_T_105) begin // @[AsyncMemModel.scala 134:78]
      read_state_26 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_27 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_27 & read_access_granted_27) begin // @[AsyncMemModel.scala 129:69]
      read_state_27 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_27_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_109) begin // @[AsyncMemModel.scala 132:27]
        read_state_27 <= 2'h3;
      end else begin
        read_state_27 <= 2'h2;
      end
    end else if (_channels_read_resps_27_valid_T_1 & _outputs_responded_or_firing_T_109) begin // @[AsyncMemModel.scala 134:78]
      read_state_27 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_28 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_28 & read_access_granted_28) begin // @[AsyncMemModel.scala 129:69]
      read_state_28 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_28_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_113) begin // @[AsyncMemModel.scala 132:27]
        read_state_28 <= 2'h3;
      end else begin
        read_state_28 <= 2'h2;
      end
    end else if (_channels_read_resps_28_valid_T_1 & _outputs_responded_or_firing_T_113) begin // @[AsyncMemModel.scala 134:78]
      read_state_28 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_29 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_29 & read_access_granted_29) begin // @[AsyncMemModel.scala 129:69]
      read_state_29 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_29_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_117) begin // @[AsyncMemModel.scala 132:27]
        read_state_29 <= 2'h3;
      end else begin
        read_state_29 <= 2'h2;
      end
    end else if (_channels_read_resps_29_valid_T_1 & _outputs_responded_or_firing_T_117) begin // @[AsyncMemModel.scala 134:78]
      read_state_29 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_30 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_30 & read_access_granted_30) begin // @[AsyncMemModel.scala 129:69]
      read_state_30 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_30_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_121) begin // @[AsyncMemModel.scala 132:27]
        read_state_30 <= 2'h3;
      end else begin
        read_state_30 <= 2'h2;
      end
    end else if (_channels_read_resps_30_valid_T_1 & _outputs_responded_or_firing_T_121) begin // @[AsyncMemModel.scala 134:78]
      read_state_30 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_31 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_31 & read_access_granted_31) begin // @[AsyncMemModel.scala 129:69]
      read_state_31 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_31_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_125) begin // @[AsyncMemModel.scala 132:27]
        read_state_31 <= 2'h3;
      end else begin
        read_state_31 <= 2'h2;
      end
    end else if (_channels_read_resps_31_valid_T_1 & _outputs_responded_or_firing_T_125) begin // @[AsyncMemModel.scala 134:78]
      read_state_31 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_32 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_32 & read_access_granted_32) begin // @[AsyncMemModel.scala 129:69]
      read_state_32 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_32_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_129) begin // @[AsyncMemModel.scala 132:27]
        read_state_32 <= 2'h3;
      end else begin
        read_state_32 <= 2'h2;
      end
    end else if (_channels_read_resps_32_valid_T_1 & _outputs_responded_or_firing_T_129) begin // @[AsyncMemModel.scala 134:78]
      read_state_32 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    if (_T_8) begin // @[AsyncMemModel.scala 127:42]
      read_state_33 <= 2'h0; // @[AsyncMemModel.scala 128:21]
    end else if (_read_access_req_T_33 & read_access_granted_33) begin // @[AsyncMemModel.scala 129:69]
      read_state_33 <= 2'h1; // @[AsyncMemModel.scala 130:21]
    end else if (_channels_read_resps_33_bits_T) begin // @[AsyncMemModel.scala 131:44]
      if (_outputs_responded_or_firing_T_133) begin // @[AsyncMemModel.scala 132:27]
        read_state_33 <= 2'h3;
      end else begin
        read_state_33 <= 2'h2;
      end
    end else if (_channels_read_resps_33_valid_T_1 & _outputs_responded_or_firing_T_133) begin // @[AsyncMemModel.scala 134:78]
      read_state_33 <= 2'h3; // @[AsyncMemModel.scala 135:21]
    end
    read_data <= data_read_data_async_data; // @[AsyncMemModel.scala 68:26]
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T & read_access_req_0)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_0 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_0 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_1 & read_access_granted_1)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_1 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_1 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_2 & read_access_granted_2)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_2 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_2 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_3 & read_access_granted_3)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_3 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_3 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_4 & read_access_granted_4)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_4 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_4 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_5 & read_access_granted_5)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_5 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_5 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_6 & read_access_granted_6)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_6 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_6 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_7 & read_access_granted_7)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_7 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_7 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_8 & read_access_granted_8)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_8 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_8 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_9 & read_access_granted_9)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_9 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_9 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_10 & read_access_granted_10)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_10 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_10 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_11 & read_access_granted_11)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_11 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_11 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_12 & read_access_granted_12)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_12 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_12 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_13 & read_access_granted_13)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_13 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_13 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_14 & read_access_granted_14)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_14 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_14 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_15 & read_access_granted_15)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_15 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_15 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_16 & read_access_granted_16)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_16 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_16 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_17 & read_access_granted_17)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_17 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_17 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_18 & read_access_granted_18)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_18 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_18 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_19 & read_access_granted_19)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_19 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_19 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_20 & read_access_granted_20)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_20 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_20 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_21 & read_access_granted_21)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_21 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_21 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_22 & read_access_granted_22)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_22 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_22 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_23 & read_access_granted_23)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_23 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_23 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_24 & read_access_granted_24)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_24 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_24 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_25 & read_access_granted_25)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_25 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_25 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_26 & read_access_granted_26)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_26 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_26 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_27 & read_access_granted_27)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_27 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_27 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_28 & read_access_granted_28)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_28 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_28 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_29 & read_access_granted_29)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_29 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_29 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_30 & read_access_granted_30)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_30 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_30 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_31 & read_access_granted_31)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_31 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_31 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_32 & read_access_granted_32)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_32 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_32 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_33 & read_access_granted_33)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_33 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_33 <= read_data;
        end
      end
    end
    if (!(_T_8)) begin // @[AsyncMemModel.scala 127:42]
      if (!(_read_access_req_T_34 & read_access_granted_34)) begin // @[AsyncMemModel.scala 129:69]
        if (read_state_34 == 2'h1) begin // @[AsyncMemModel.scala 124:39]
          read_resp_data_34 <= read_data;
        end
      end
    end
    if (_T_8) begin // @[AsyncMemModel.scala 145:42]
      write_complete_0 <= 1'h0; // @[AsyncMemModel.scala 146:25]
    end else begin
      write_complete_0 <= _GEN_289;
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
`ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{`RANDOM}};
  read_state_34 = _RAND_1[1:0];
  _RAND_2 = {1{`RANDOM}};
  read_state_0 = _RAND_2[1:0];
  _RAND_3 = {1{`RANDOM}};
  read_state_1 = _RAND_3[1:0];
  _RAND_4 = {1{`RANDOM}};
  read_state_2 = _RAND_4[1:0];
  _RAND_5 = {1{`RANDOM}};
  read_state_3 = _RAND_5[1:0];
  _RAND_6 = {1{`RANDOM}};
  read_state_4 = _RAND_6[1:0];
  _RAND_7 = {1{`RANDOM}};
  read_state_5 = _RAND_7[1:0];
  _RAND_8 = {1{`RANDOM}};
  read_state_6 = _RAND_8[1:0];
  _RAND_9 = {1{`RANDOM}};
  read_state_7 = _RAND_9[1:0];
  _RAND_10 = {1{`RANDOM}};
  read_state_8 = _RAND_10[1:0];
  _RAND_11 = {1{`RANDOM}};
  read_state_9 = _RAND_11[1:0];
  _RAND_12 = {1{`RANDOM}};
  read_state_10 = _RAND_12[1:0];
  _RAND_13 = {1{`RANDOM}};
  read_state_11 = _RAND_13[1:0];
  _RAND_14 = {1{`RANDOM}};
  read_state_12 = _RAND_14[1:0];
  _RAND_15 = {1{`RANDOM}};
  read_state_13 = _RAND_15[1:0];
  _RAND_16 = {1{`RANDOM}};
  read_state_14 = _RAND_16[1:0];
  _RAND_17 = {1{`RANDOM}};
  read_state_15 = _RAND_17[1:0];
  _RAND_18 = {1{`RANDOM}};
  read_state_16 = _RAND_18[1:0];
  _RAND_19 = {1{`RANDOM}};
  read_state_17 = _RAND_19[1:0];
  _RAND_20 = {1{`RANDOM}};
  read_state_18 = _RAND_20[1:0];
  _RAND_21 = {1{`RANDOM}};
  read_state_19 = _RAND_21[1:0];
  _RAND_22 = {1{`RANDOM}};
  read_state_20 = _RAND_22[1:0];
  _RAND_23 = {1{`RANDOM}};
  read_state_21 = _RAND_23[1:0];
  _RAND_24 = {1{`RANDOM}};
  read_state_22 = _RAND_24[1:0];
  _RAND_25 = {1{`RANDOM}};
  read_state_23 = _RAND_25[1:0];
  _RAND_26 = {1{`RANDOM}};
  read_state_24 = _RAND_26[1:0];
  _RAND_27 = {1{`RANDOM}};
  read_state_25 = _RAND_27[1:0];
  _RAND_28 = {1{`RANDOM}};
  read_state_26 = _RAND_28[1:0];
  _RAND_29 = {1{`RANDOM}};
  read_state_27 = _RAND_29[1:0];
  _RAND_30 = {1{`RANDOM}};
  read_state_28 = _RAND_30[1:0];
  _RAND_31 = {1{`RANDOM}};
  read_state_29 = _RAND_31[1:0];
  _RAND_32 = {1{`RANDOM}};
  read_state_30 = _RAND_32[1:0];
  _RAND_33 = {1{`RANDOM}};
  read_state_31 = _RAND_33[1:0];
  _RAND_34 = {1{`RANDOM}};
  read_state_32 = _RAND_34[1:0];
  _RAND_35 = {1{`RANDOM}};
  read_state_33 = _RAND_35[1:0];
  _RAND_36 = {3{`RANDOM}};
  read_data = _RAND_36[80:0];
  _RAND_37 = {3{`RANDOM}};
  read_resp_data_0 = _RAND_37[80:0];
  _RAND_38 = {3{`RANDOM}};
  read_resp_data_1 = _RAND_38[80:0];
  _RAND_39 = {3{`RANDOM}};
  read_resp_data_2 = _RAND_39[80:0];
  _RAND_40 = {3{`RANDOM}};
  read_resp_data_3 = _RAND_40[80:0];
  _RAND_41 = {3{`RANDOM}};
  read_resp_data_4 = _RAND_41[80:0];
  _RAND_42 = {3{`RANDOM}};
  read_resp_data_5 = _RAND_42[80:0];
  _RAND_43 = {3{`RANDOM}};
  read_resp_data_6 = _RAND_43[80:0];
  _RAND_44 = {3{`RANDOM}};
  read_resp_data_7 = _RAND_44[80:0];
  _RAND_45 = {3{`RANDOM}};
  read_resp_data_8 = _RAND_45[80:0];
  _RAND_46 = {3{`RANDOM}};
  read_resp_data_9 = _RAND_46[80:0];
  _RAND_47 = {3{`RANDOM}};
  read_resp_data_10 = _RAND_47[80:0];
  _RAND_48 = {3{`RANDOM}};
  read_resp_data_11 = _RAND_48[80:0];
  _RAND_49 = {3{`RANDOM}};
  read_resp_data_12 = _RAND_49[80:0];
  _RAND_50 = {3{`RANDOM}};
  read_resp_data_13 = _RAND_50[80:0];
  _RAND_51 = {3{`RANDOM}};
  read_resp_data_14 = _RAND_51[80:0];
  _RAND_52 = {3{`RANDOM}};
  read_resp_data_15 = _RAND_52[80:0];
  _RAND_53 = {3{`RANDOM}};
  read_resp_data_16 = _RAND_53[80:0];
  _RAND_54 = {3{`RANDOM}};
  read_resp_data_17 = _RAND_54[80:0];
  _RAND_55 = {3{`RANDOM}};
  read_resp_data_18 = _RAND_55[80:0];
  _RAND_56 = {3{`RANDOM}};
  read_resp_data_19 = _RAND_56[80:0];
  _RAND_57 = {3{`RANDOM}};
  read_resp_data_20 = _RAND_57[80:0];
  _RAND_58 = {3{`RANDOM}};
  read_resp_data_21 = _RAND_58[80:0];
  _RAND_59 = {3{`RANDOM}};
  read_resp_data_22 = _RAND_59[80:0];
  _RAND_60 = {3{`RANDOM}};
  read_resp_data_23 = _RAND_60[80:0];
  _RAND_61 = {3{`RANDOM}};
  read_resp_data_24 = _RAND_61[80:0];
  _RAND_62 = {3{`RANDOM}};
  read_resp_data_25 = _RAND_62[80:0];
  _RAND_63 = {3{`RANDOM}};
  read_resp_data_26 = _RAND_63[80:0];
  _RAND_64 = {3{`RANDOM}};
  read_resp_data_27 = _RAND_64[80:0];
  _RAND_65 = {3{`RANDOM}};
  read_resp_data_28 = _RAND_65[80:0];
  _RAND_66 = {3{`RANDOM}};
  read_resp_data_29 = _RAND_66[80:0];
  _RAND_67 = {3{`RANDOM}};
  read_resp_data_30 = _RAND_67[80:0];
  _RAND_68 = {3{`RANDOM}};
  read_resp_data_31 = _RAND_68[80:0];
  _RAND_69 = {3{`RANDOM}};
  read_resp_data_32 = _RAND_69[80:0];
  _RAND_70 = {3{`RANDOM}};
  read_resp_data_33 = _RAND_70[80:0];
  _RAND_71 = {3{`RANDOM}};
  read_resp_data_34 = _RAND_71[80:0];
  _RAND_72 = {1{`RANDOM}};
  write_complete_0 = _RAND_72[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
 assign proof_word = data[proof_watch][35:27];
 assign proof_write_enable = data_MPORT_en & data_MPORT_mask;
 assign proof_write_address = data_MPORT_addr;
 assign proof_write_data = data_MPORT_data;
 assign proof_pipeline = read_data[35:27];
 assign proof_read_address = data_read_data_async_addr;
endmodule
module OwnerReadSnapshotRelation(input clock,
input reset,
input [34:0] command_valid,
input [314:0] command_address,
input [34:0] response_ready,
input write_valid,
input write_en,
input write_mask,
input [8:0] write_address,
input [80:0] write_payload,
input [8:0] watch,
output stable_address,
output word_relation,
output read_relation);

 wire [8:0] actual_word, actual_address, actual_pipeline, actual_read_address;
 wire [80:0] actual_data;
 wire actual_write;
 reg [8:0] previous_watch, expected_word, expected_pipeline;
 reg captured_watch;
 always @(posedge clock) begin
   previous_watch <= watch;
   captured_watch <= actual_read_address == watch;
   expected_pipeline <= expected_word;
   if (actual_write && actual_address == watch)
     expected_word <= actual_data[35:27];
 end
 assign stable_address = watch == previous_watch;
 assign word_relation = actual_word == expected_word;
 assign read_relation = !captured_watch || actual_pipeline == expected_pipeline;
 RamModel dut(.clock(clock),
.reset(reset),
.proof_watch(watch),
.proof_word(actual_word),
.proof_write_enable(actual_write),
.proof_write_address(actual_address),
.proof_write_data(actual_data),
.proof_pipeline(actual_pipeline),
.proof_read_address(actual_read_address),
.channels_write_cmds_0_ready(),
.channels_write_cmds_0_valid(write_valid),
.channels_write_cmds_0_bits_en(write_en),
.channels_write_cmds_0_bits_mask(write_mask),
.channels_write_cmds_0_bits_addr(write_address),
.channels_write_cmds_0_bits_data(write_payload),
.channels_read_cmds_0_ready(),
.channels_read_cmds_0_valid(command_valid[0]),
.channels_read_cmds_0_bits_addr(command_address[0 +: 9]),
.channels_read_resps_0_ready(response_ready[0]),
.channels_read_resps_0_valid(),
.channels_read_resps_0_bits(),
.channels_read_cmds_1_ready(),
.channels_read_cmds_1_valid(command_valid[1]),
.channels_read_cmds_1_bits_addr(command_address[9 +: 9]),
.channels_read_resps_1_ready(response_ready[1]),
.channels_read_resps_1_valid(),
.channels_read_resps_1_bits(),
.channels_read_cmds_2_ready(),
.channels_read_cmds_2_valid(command_valid[2]),
.channels_read_cmds_2_bits_addr(command_address[18 +: 9]),
.channels_read_resps_2_ready(response_ready[2]),
.channels_read_resps_2_valid(),
.channels_read_resps_2_bits(),
.channels_read_cmds_3_ready(),
.channels_read_cmds_3_valid(command_valid[3]),
.channels_read_cmds_3_bits_addr(command_address[27 +: 9]),
.channels_read_resps_3_ready(response_ready[3]),
.channels_read_resps_3_valid(),
.channels_read_resps_3_bits(),
.channels_read_cmds_4_ready(),
.channels_read_cmds_4_valid(command_valid[4]),
.channels_read_cmds_4_bits_addr(command_address[36 +: 9]),
.channels_read_resps_4_ready(response_ready[4]),
.channels_read_resps_4_valid(),
.channels_read_resps_4_bits(),
.channels_read_cmds_5_ready(),
.channels_read_cmds_5_valid(command_valid[5]),
.channels_read_cmds_5_bits_addr(command_address[45 +: 9]),
.channels_read_resps_5_ready(response_ready[5]),
.channels_read_resps_5_valid(),
.channels_read_resps_5_bits(),
.channels_read_cmds_6_ready(),
.channels_read_cmds_6_valid(command_valid[6]),
.channels_read_cmds_6_bits_addr(command_address[54 +: 9]),
.channels_read_resps_6_ready(response_ready[6]),
.channels_read_resps_6_valid(),
.channels_read_resps_6_bits(),
.channels_read_cmds_7_ready(),
.channels_read_cmds_7_valid(command_valid[7]),
.channels_read_cmds_7_bits_addr(command_address[63 +: 9]),
.channels_read_resps_7_ready(response_ready[7]),
.channels_read_resps_7_valid(),
.channels_read_resps_7_bits(),
.channels_read_cmds_8_ready(),
.channels_read_cmds_8_valid(command_valid[8]),
.channels_read_cmds_8_bits_addr(command_address[72 +: 9]),
.channels_read_resps_8_ready(response_ready[8]),
.channels_read_resps_8_valid(),
.channels_read_resps_8_bits(),
.channels_read_cmds_9_ready(),
.channels_read_cmds_9_valid(command_valid[9]),
.channels_read_cmds_9_bits_addr(command_address[81 +: 9]),
.channels_read_resps_9_ready(response_ready[9]),
.channels_read_resps_9_valid(),
.channels_read_resps_9_bits(),
.channels_read_cmds_10_ready(),
.channels_read_cmds_10_valid(command_valid[10]),
.channels_read_cmds_10_bits_addr(command_address[90 +: 9]),
.channels_read_resps_10_ready(response_ready[10]),
.channels_read_resps_10_valid(),
.channels_read_resps_10_bits(),
.channels_read_cmds_11_ready(),
.channels_read_cmds_11_valid(command_valid[11]),
.channels_read_cmds_11_bits_addr(command_address[99 +: 9]),
.channels_read_resps_11_ready(response_ready[11]),
.channels_read_resps_11_valid(),
.channels_read_resps_11_bits(),
.channels_read_cmds_12_ready(),
.channels_read_cmds_12_valid(command_valid[12]),
.channels_read_cmds_12_bits_addr(command_address[108 +: 9]),
.channels_read_resps_12_ready(response_ready[12]),
.channels_read_resps_12_valid(),
.channels_read_resps_12_bits(),
.channels_read_cmds_13_ready(),
.channels_read_cmds_13_valid(command_valid[13]),
.channels_read_cmds_13_bits_addr(command_address[117 +: 9]),
.channels_read_resps_13_ready(response_ready[13]),
.channels_read_resps_13_valid(),
.channels_read_resps_13_bits(),
.channels_read_cmds_14_ready(),
.channels_read_cmds_14_valid(command_valid[14]),
.channels_read_cmds_14_bits_addr(command_address[126 +: 9]),
.channels_read_resps_14_ready(response_ready[14]),
.channels_read_resps_14_valid(),
.channels_read_resps_14_bits(),
.channels_read_cmds_15_ready(),
.channels_read_cmds_15_valid(command_valid[15]),
.channels_read_cmds_15_bits_addr(command_address[135 +: 9]),
.channels_read_resps_15_ready(response_ready[15]),
.channels_read_resps_15_valid(),
.channels_read_resps_15_bits(),
.channels_read_cmds_16_ready(),
.channels_read_cmds_16_valid(command_valid[16]),
.channels_read_cmds_16_bits_addr(command_address[144 +: 9]),
.channels_read_resps_16_ready(response_ready[16]),
.channels_read_resps_16_valid(),
.channels_read_resps_16_bits(),
.channels_read_cmds_17_ready(),
.channels_read_cmds_17_valid(command_valid[17]),
.channels_read_cmds_17_bits_addr(command_address[153 +: 9]),
.channels_read_resps_17_ready(response_ready[17]),
.channels_read_resps_17_valid(),
.channels_read_resps_17_bits(),
.channels_read_cmds_18_ready(),
.channels_read_cmds_18_valid(command_valid[18]),
.channels_read_cmds_18_bits_addr(command_address[162 +: 9]),
.channels_read_resps_18_ready(response_ready[18]),
.channels_read_resps_18_valid(),
.channels_read_resps_18_bits(),
.channels_read_cmds_19_ready(),
.channels_read_cmds_19_valid(command_valid[19]),
.channels_read_cmds_19_bits_addr(command_address[171 +: 9]),
.channels_read_resps_19_ready(response_ready[19]),
.channels_read_resps_19_valid(),
.channels_read_resps_19_bits(),
.channels_read_cmds_20_ready(),
.channels_read_cmds_20_valid(command_valid[20]),
.channels_read_cmds_20_bits_addr(command_address[180 +: 9]),
.channels_read_resps_20_ready(response_ready[20]),
.channels_read_resps_20_valid(),
.channels_read_resps_20_bits(),
.channels_read_cmds_21_ready(),
.channels_read_cmds_21_valid(command_valid[21]),
.channels_read_cmds_21_bits_addr(command_address[189 +: 9]),
.channels_read_resps_21_ready(response_ready[21]),
.channels_read_resps_21_valid(),
.channels_read_resps_21_bits(),
.channels_read_cmds_22_ready(),
.channels_read_cmds_22_valid(command_valid[22]),
.channels_read_cmds_22_bits_addr(command_address[198 +: 9]),
.channels_read_resps_22_ready(response_ready[22]),
.channels_read_resps_22_valid(),
.channels_read_resps_22_bits(),
.channels_read_cmds_23_ready(),
.channels_read_cmds_23_valid(command_valid[23]),
.channels_read_cmds_23_bits_addr(command_address[207 +: 9]),
.channels_read_resps_23_ready(response_ready[23]),
.channels_read_resps_23_valid(),
.channels_read_resps_23_bits(),
.channels_read_cmds_24_ready(),
.channels_read_cmds_24_valid(command_valid[24]),
.channels_read_cmds_24_bits_addr(command_address[216 +: 9]),
.channels_read_resps_24_ready(response_ready[24]),
.channels_read_resps_24_valid(),
.channels_read_resps_24_bits(),
.channels_read_cmds_25_ready(),
.channels_read_cmds_25_valid(command_valid[25]),
.channels_read_cmds_25_bits_addr(command_address[225 +: 9]),
.channels_read_resps_25_ready(response_ready[25]),
.channels_read_resps_25_valid(),
.channels_read_resps_25_bits(),
.channels_read_cmds_26_ready(),
.channels_read_cmds_26_valid(command_valid[26]),
.channels_read_cmds_26_bits_addr(command_address[234 +: 9]),
.channels_read_resps_26_ready(response_ready[26]),
.channels_read_resps_26_valid(),
.channels_read_resps_26_bits(),
.channels_read_cmds_27_ready(),
.channels_read_cmds_27_valid(command_valid[27]),
.channels_read_cmds_27_bits_addr(command_address[243 +: 9]),
.channels_read_resps_27_ready(response_ready[27]),
.channels_read_resps_27_valid(),
.channels_read_resps_27_bits(),
.channels_read_cmds_28_ready(),
.channels_read_cmds_28_valid(command_valid[28]),
.channels_read_cmds_28_bits_addr(command_address[252 +: 9]),
.channels_read_resps_28_ready(response_ready[28]),
.channels_read_resps_28_valid(),
.channels_read_resps_28_bits(),
.channels_read_cmds_29_ready(),
.channels_read_cmds_29_valid(command_valid[29]),
.channels_read_cmds_29_bits_addr(command_address[261 +: 9]),
.channels_read_resps_29_ready(response_ready[29]),
.channels_read_resps_29_valid(),
.channels_read_resps_29_bits(),
.channels_read_cmds_30_ready(),
.channels_read_cmds_30_valid(command_valid[30]),
.channels_read_cmds_30_bits_addr(command_address[270 +: 9]),
.channels_read_resps_30_ready(response_ready[30]),
.channels_read_resps_30_valid(),
.channels_read_resps_30_bits(),
.channels_read_cmds_31_ready(),
.channels_read_cmds_31_valid(command_valid[31]),
.channels_read_cmds_31_bits_addr(command_address[279 +: 9]),
.channels_read_resps_31_ready(response_ready[31]),
.channels_read_resps_31_valid(),
.channels_read_resps_31_bits(),
.channels_read_cmds_32_ready(),
.channels_read_cmds_32_valid(command_valid[32]),
.channels_read_cmds_32_bits_addr(command_address[288 +: 9]),
.channels_read_resps_32_ready(response_ready[32]),
.channels_read_resps_32_valid(),
.channels_read_resps_32_bits(),
.channels_read_cmds_33_ready(),
.channels_read_cmds_33_valid(command_valid[33]),
.channels_read_cmds_33_bits_addr(command_address[297 +: 9]),
.channels_read_resps_33_ready(response_ready[33]),
.channels_read_resps_33_valid(),
.channels_read_resps_33_bits(),
.channels_read_cmds_34_ready(),
.channels_read_cmds_34_valid(command_valid[34]),
.channels_read_cmds_34_bits_addr(command_address[306 +: 9]),
.channels_read_resps_34_ready(response_ready[34]),
.channels_read_resps_34_valid(),
.channels_read_resps_34_bits());
endmodule
