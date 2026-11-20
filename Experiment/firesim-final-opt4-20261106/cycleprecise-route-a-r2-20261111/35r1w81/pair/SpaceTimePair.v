module AsyncMemChiselModel(
  input         clock,
  input         reset,
  output        channels_reset_ready,
  input         channels_reset_valid,
  input         channels_reset_bits,
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
  input  [80:0] channels_write_cmds_0_bits_data
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
  reg [31:0] _RAND_36;
  reg [31:0] _RAND_37;
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
  reg [95:0] _RAND_72;
  reg [95:0] _RAND_73;
  reg [31:0] _RAND_74;
`endif // RANDOMIZE_REG_INIT
  reg [80:0] data [0:511]; // @[AsyncMemModel.scala 62:17]
  wire  data_read_data_async_en; // @[AsyncMemModel.scala 62:17]
  wire [8:0] data_read_data_async_addr; // @[AsyncMemModel.scala 62:17]
  wire [80:0] data_read_data_async_data; // @[AsyncMemModel.scala 62:17]
  wire [80:0] data_MPORT_data; // @[AsyncMemModel.scala 62:17]
  wire [8:0] data_MPORT_addr; // @[AsyncMemModel.scala 62:17]
  wire  data_MPORT_mask; // @[AsyncMemModel.scala 62:17]
  wire  data_MPORT_en; // @[AsyncMemModel.scala 62:17]
  reg  target_reset_fired; // @[AsyncMemModel.scala 56:31]
  wire  target_reset_available = target_reset_fired | channels_reset_valid; // @[AsyncMemModel.scala 57:51]
  reg  target_reset_reg; // @[AsyncMemModel.scala 58:29]
  wire  target_reset_value = target_reset_fired ? target_reset_reg : channels_reset_bits; // @[AsyncMemModel.scala 59:31]
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
  wire  _T_1 = active_write_en & ~target_reset_value; // @[AsyncMemModel.scala 69:25]
  wire  _T_3 = ~reset; // @[AsyncMemModel.scala 69:51]
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
  wire  write_prereqs_met_0 = reads_done & target_reset_available; // @[AsyncMemModel.scala 100:91]
  wire  writes_done_or_finishing = write_complete_0 | _T_293; // @[AsyncMemModel.scala 104:53]
  wire  advance_cycle = outputs_responded_or_firing & writes_done_or_finishing; // @[AsyncMemModel.scala 107:51]
  wire  _T_8 = advance_cycle | reset; // @[AsyncMemModel.scala 111:23]
  wire  _T_9 = channels_reset_ready & channels_reset_valid; // @[Decoupled.scala 51:35]
  wire  _GEN_5 = _T_9 | target_reset_fired; // @[AsyncMemModel.scala 113:37 114:24 56:31]
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
  assign data_read_data_async_en = 1'h1;
  assign data_read_data_async_addr = read_access_granted_34 ? channels_read_cmds_34_bits_addr : _GEN_273;
  assign data_read_data_async_data = data[data_read_data_async_addr]; // @[AsyncMemModel.scala 62:17]
  assign data_MPORT_data = channels_write_cmds_0_bits_data;
  assign data_MPORT_addr = channels_write_cmds_0_bits_addr;
  assign data_MPORT_mask = 1'h1;
  assign data_MPORT_en = _T_1 & _T_3;
  assign channels_reset_ready = ~target_reset_fired; // @[AsyncMemModel.scala 110:27]
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
  assign channels_write_cmds_0_ready = write_prereqs_met_0 & ~write_complete_0; // @[AsyncMemModel.scala 144:58]
  always @(posedge clock) begin
    if (data_MPORT_en & data_MPORT_mask) begin
      data[data_MPORT_addr] <= data_MPORT_data; // @[AsyncMemModel.scala 62:17]
    end
    if (advance_cycle | reset) begin // @[AsyncMemModel.scala 111:40]
      target_reset_fired <= 1'h0; // @[AsyncMemModel.scala 112:24]
    end else begin
      target_reset_fired <= _GEN_5;
    end
    if (!(advance_cycle | reset)) begin // @[AsyncMemModel.scala 111:40]
      if (_T_9) begin // @[AsyncMemModel.scala 113:37]
        target_reset_reg <= channels_reset_bits; // @[AsyncMemModel.scala 115:22]
      end
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
  target_reset_fired = _RAND_1[0:0];
  _RAND_2 = {1{`RANDOM}};
  target_reset_reg = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  read_state_34 = _RAND_3[1:0];
  _RAND_4 = {1{`RANDOM}};
  read_state_0 = _RAND_4[1:0];
  _RAND_5 = {1{`RANDOM}};
  read_state_1 = _RAND_5[1:0];
  _RAND_6 = {1{`RANDOM}};
  read_state_2 = _RAND_6[1:0];
  _RAND_7 = {1{`RANDOM}};
  read_state_3 = _RAND_7[1:0];
  _RAND_8 = {1{`RANDOM}};
  read_state_4 = _RAND_8[1:0];
  _RAND_9 = {1{`RANDOM}};
  read_state_5 = _RAND_9[1:0];
  _RAND_10 = {1{`RANDOM}};
  read_state_6 = _RAND_10[1:0];
  _RAND_11 = {1{`RANDOM}};
  read_state_7 = _RAND_11[1:0];
  _RAND_12 = {1{`RANDOM}};
  read_state_8 = _RAND_12[1:0];
  _RAND_13 = {1{`RANDOM}};
  read_state_9 = _RAND_13[1:0];
  _RAND_14 = {1{`RANDOM}};
  read_state_10 = _RAND_14[1:0];
  _RAND_15 = {1{`RANDOM}};
  read_state_11 = _RAND_15[1:0];
  _RAND_16 = {1{`RANDOM}};
  read_state_12 = _RAND_16[1:0];
  _RAND_17 = {1{`RANDOM}};
  read_state_13 = _RAND_17[1:0];
  _RAND_18 = {1{`RANDOM}};
  read_state_14 = _RAND_18[1:0];
  _RAND_19 = {1{`RANDOM}};
  read_state_15 = _RAND_19[1:0];
  _RAND_20 = {1{`RANDOM}};
  read_state_16 = _RAND_20[1:0];
  _RAND_21 = {1{`RANDOM}};
  read_state_17 = _RAND_21[1:0];
  _RAND_22 = {1{`RANDOM}};
  read_state_18 = _RAND_22[1:0];
  _RAND_23 = {1{`RANDOM}};
  read_state_19 = _RAND_23[1:0];
  _RAND_24 = {1{`RANDOM}};
  read_state_20 = _RAND_24[1:0];
  _RAND_25 = {1{`RANDOM}};
  read_state_21 = _RAND_25[1:0];
  _RAND_26 = {1{`RANDOM}};
  read_state_22 = _RAND_26[1:0];
  _RAND_27 = {1{`RANDOM}};
  read_state_23 = _RAND_27[1:0];
  _RAND_28 = {1{`RANDOM}};
  read_state_24 = _RAND_28[1:0];
  _RAND_29 = {1{`RANDOM}};
  read_state_25 = _RAND_29[1:0];
  _RAND_30 = {1{`RANDOM}};
  read_state_26 = _RAND_30[1:0];
  _RAND_31 = {1{`RANDOM}};
  read_state_27 = _RAND_31[1:0];
  _RAND_32 = {1{`RANDOM}};
  read_state_28 = _RAND_32[1:0];
  _RAND_33 = {1{`RANDOM}};
  read_state_29 = _RAND_33[1:0];
  _RAND_34 = {1{`RANDOM}};
  read_state_30 = _RAND_34[1:0];
  _RAND_35 = {1{`RANDOM}};
  read_state_31 = _RAND_35[1:0];
  _RAND_36 = {1{`RANDOM}};
  read_state_32 = _RAND_36[1:0];
  _RAND_37 = {1{`RANDOM}};
  read_state_33 = _RAND_37[1:0];
  _RAND_38 = {3{`RANDOM}};
  read_data = _RAND_38[80:0];
  _RAND_39 = {3{`RANDOM}};
  read_resp_data_0 = _RAND_39[80:0];
  _RAND_40 = {3{`RANDOM}};
  read_resp_data_1 = _RAND_40[80:0];
  _RAND_41 = {3{`RANDOM}};
  read_resp_data_2 = _RAND_41[80:0];
  _RAND_42 = {3{`RANDOM}};
  read_resp_data_3 = _RAND_42[80:0];
  _RAND_43 = {3{`RANDOM}};
  read_resp_data_4 = _RAND_43[80:0];
  _RAND_44 = {3{`RANDOM}};
  read_resp_data_5 = _RAND_44[80:0];
  _RAND_45 = {3{`RANDOM}};
  read_resp_data_6 = _RAND_45[80:0];
  _RAND_46 = {3{`RANDOM}};
  read_resp_data_7 = _RAND_46[80:0];
  _RAND_47 = {3{`RANDOM}};
  read_resp_data_8 = _RAND_47[80:0];
  _RAND_48 = {3{`RANDOM}};
  read_resp_data_9 = _RAND_48[80:0];
  _RAND_49 = {3{`RANDOM}};
  read_resp_data_10 = _RAND_49[80:0];
  _RAND_50 = {3{`RANDOM}};
  read_resp_data_11 = _RAND_50[80:0];
  _RAND_51 = {3{`RANDOM}};
  read_resp_data_12 = _RAND_51[80:0];
  _RAND_52 = {3{`RANDOM}};
  read_resp_data_13 = _RAND_52[80:0];
  _RAND_53 = {3{`RANDOM}};
  read_resp_data_14 = _RAND_53[80:0];
  _RAND_54 = {3{`RANDOM}};
  read_resp_data_15 = _RAND_54[80:0];
  _RAND_55 = {3{`RANDOM}};
  read_resp_data_16 = _RAND_55[80:0];
  _RAND_56 = {3{`RANDOM}};
  read_resp_data_17 = _RAND_56[80:0];
  _RAND_57 = {3{`RANDOM}};
  read_resp_data_18 = _RAND_57[80:0];
  _RAND_58 = {3{`RANDOM}};
  read_resp_data_19 = _RAND_58[80:0];
  _RAND_59 = {3{`RANDOM}};
  read_resp_data_20 = _RAND_59[80:0];
  _RAND_60 = {3{`RANDOM}};
  read_resp_data_21 = _RAND_60[80:0];
  _RAND_61 = {3{`RANDOM}};
  read_resp_data_22 = _RAND_61[80:0];
  _RAND_62 = {3{`RANDOM}};
  read_resp_data_23 = _RAND_62[80:0];
  _RAND_63 = {3{`RANDOM}};
  read_resp_data_24 = _RAND_63[80:0];
  _RAND_64 = {3{`RANDOM}};
  read_resp_data_25 = _RAND_64[80:0];
  _RAND_65 = {3{`RANDOM}};
  read_resp_data_26 = _RAND_65[80:0];
  _RAND_66 = {3{`RANDOM}};
  read_resp_data_27 = _RAND_66[80:0];
  _RAND_67 = {3{`RANDOM}};
  read_resp_data_28 = _RAND_67[80:0];
  _RAND_68 = {3{`RANDOM}};
  read_resp_data_29 = _RAND_68[80:0];
  _RAND_69 = {3{`RANDOM}};
  read_resp_data_30 = _RAND_69[80:0];
  _RAND_70 = {3{`RANDOM}};
  read_resp_data_31 = _RAND_70[80:0];
  _RAND_71 = {3{`RANDOM}};
  read_resp_data_32 = _RAND_71[80:0];
  _RAND_72 = {3{`RANDOM}};
  read_resp_data_33 = _RAND_72[80:0];
  _RAND_73 = {3{`RANDOM}};
  read_resp_data_34 = _RAND_73[80:0];
  _RAND_74 = {1{`RANDOM}};
  write_complete_0 = _RAND_74[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module AsyncMemChiselRTL(
  input         clock,
  input         reset,
  input  [8:0]  channels_read_cmds_0_addr,
  input  [8:0]  channels_read_cmds_1_addr,
  input  [8:0]  channels_read_cmds_2_addr,
  input  [8:0]  channels_read_cmds_3_addr,
  input  [8:0]  channels_read_cmds_4_addr,
  input  [8:0]  channels_read_cmds_5_addr,
  input  [8:0]  channels_read_cmds_6_addr,
  input  [8:0]  channels_read_cmds_7_addr,
  input  [8:0]  channels_read_cmds_8_addr,
  input  [8:0]  channels_read_cmds_9_addr,
  input  [8:0]  channels_read_cmds_10_addr,
  input  [8:0]  channels_read_cmds_11_addr,
  input  [8:0]  channels_read_cmds_12_addr,
  input  [8:0]  channels_read_cmds_13_addr,
  input  [8:0]  channels_read_cmds_14_addr,
  input  [8:0]  channels_read_cmds_15_addr,
  input  [8:0]  channels_read_cmds_16_addr,
  input  [8:0]  channels_read_cmds_17_addr,
  input  [8:0]  channels_read_cmds_18_addr,
  input  [8:0]  channels_read_cmds_19_addr,
  input  [8:0]  channels_read_cmds_20_addr,
  input  [8:0]  channels_read_cmds_21_addr,
  input  [8:0]  channels_read_cmds_22_addr,
  input  [8:0]  channels_read_cmds_23_addr,
  input  [8:0]  channels_read_cmds_24_addr,
  input  [8:0]  channels_read_cmds_25_addr,
  input  [8:0]  channels_read_cmds_26_addr,
  input  [8:0]  channels_read_cmds_27_addr,
  input  [8:0]  channels_read_cmds_28_addr,
  input  [8:0]  channels_read_cmds_29_addr,
  input  [8:0]  channels_read_cmds_30_addr,
  input  [8:0]  channels_read_cmds_31_addr,
  input  [8:0]  channels_read_cmds_32_addr,
  input  [8:0]  channels_read_cmds_33_addr,
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
module SpaceTimePair(
  input         clock,
  input         reset,
  input         io_targetClock,
  input         io_targetReset,
  output        io_model_reset_ready,
  input         io_model_reset_valid,
  input         io_model_reset_bits,
  output        io_model_read_cmds_0_ready,
  input         io_model_read_cmds_0_valid,
  input         io_model_read_cmds_0_bits_en,
  input  [8:0]  io_model_read_cmds_0_bits_addr,
  output        io_model_read_cmds_1_ready,
  input         io_model_read_cmds_1_valid,
  input         io_model_read_cmds_1_bits_en,
  input  [8:0]  io_model_read_cmds_1_bits_addr,
  output        io_model_read_cmds_2_ready,
  input         io_model_read_cmds_2_valid,
  input         io_model_read_cmds_2_bits_en,
  input  [8:0]  io_model_read_cmds_2_bits_addr,
  output        io_model_read_cmds_3_ready,
  input         io_model_read_cmds_3_valid,
  input         io_model_read_cmds_3_bits_en,
  input  [8:0]  io_model_read_cmds_3_bits_addr,
  output        io_model_read_cmds_4_ready,
  input         io_model_read_cmds_4_valid,
  input         io_model_read_cmds_4_bits_en,
  input  [8:0]  io_model_read_cmds_4_bits_addr,
  output        io_model_read_cmds_5_ready,
  input         io_model_read_cmds_5_valid,
  input         io_model_read_cmds_5_bits_en,
  input  [8:0]  io_model_read_cmds_5_bits_addr,
  output        io_model_read_cmds_6_ready,
  input         io_model_read_cmds_6_valid,
  input         io_model_read_cmds_6_bits_en,
  input  [8:0]  io_model_read_cmds_6_bits_addr,
  output        io_model_read_cmds_7_ready,
  input         io_model_read_cmds_7_valid,
  input         io_model_read_cmds_7_bits_en,
  input  [8:0]  io_model_read_cmds_7_bits_addr,
  output        io_model_read_cmds_8_ready,
  input         io_model_read_cmds_8_valid,
  input         io_model_read_cmds_8_bits_en,
  input  [8:0]  io_model_read_cmds_8_bits_addr,
  output        io_model_read_cmds_9_ready,
  input         io_model_read_cmds_9_valid,
  input         io_model_read_cmds_9_bits_en,
  input  [8:0]  io_model_read_cmds_9_bits_addr,
  output        io_model_read_cmds_10_ready,
  input         io_model_read_cmds_10_valid,
  input         io_model_read_cmds_10_bits_en,
  input  [8:0]  io_model_read_cmds_10_bits_addr,
  output        io_model_read_cmds_11_ready,
  input         io_model_read_cmds_11_valid,
  input         io_model_read_cmds_11_bits_en,
  input  [8:0]  io_model_read_cmds_11_bits_addr,
  output        io_model_read_cmds_12_ready,
  input         io_model_read_cmds_12_valid,
  input         io_model_read_cmds_12_bits_en,
  input  [8:0]  io_model_read_cmds_12_bits_addr,
  output        io_model_read_cmds_13_ready,
  input         io_model_read_cmds_13_valid,
  input         io_model_read_cmds_13_bits_en,
  input  [8:0]  io_model_read_cmds_13_bits_addr,
  output        io_model_read_cmds_14_ready,
  input         io_model_read_cmds_14_valid,
  input         io_model_read_cmds_14_bits_en,
  input  [8:0]  io_model_read_cmds_14_bits_addr,
  output        io_model_read_cmds_15_ready,
  input         io_model_read_cmds_15_valid,
  input         io_model_read_cmds_15_bits_en,
  input  [8:0]  io_model_read_cmds_15_bits_addr,
  output        io_model_read_cmds_16_ready,
  input         io_model_read_cmds_16_valid,
  input         io_model_read_cmds_16_bits_en,
  input  [8:0]  io_model_read_cmds_16_bits_addr,
  output        io_model_read_cmds_17_ready,
  input         io_model_read_cmds_17_valid,
  input         io_model_read_cmds_17_bits_en,
  input  [8:0]  io_model_read_cmds_17_bits_addr,
  output        io_model_read_cmds_18_ready,
  input         io_model_read_cmds_18_valid,
  input         io_model_read_cmds_18_bits_en,
  input  [8:0]  io_model_read_cmds_18_bits_addr,
  output        io_model_read_cmds_19_ready,
  input         io_model_read_cmds_19_valid,
  input         io_model_read_cmds_19_bits_en,
  input  [8:0]  io_model_read_cmds_19_bits_addr,
  output        io_model_read_cmds_20_ready,
  input         io_model_read_cmds_20_valid,
  input         io_model_read_cmds_20_bits_en,
  input  [8:0]  io_model_read_cmds_20_bits_addr,
  output        io_model_read_cmds_21_ready,
  input         io_model_read_cmds_21_valid,
  input         io_model_read_cmds_21_bits_en,
  input  [8:0]  io_model_read_cmds_21_bits_addr,
  output        io_model_read_cmds_22_ready,
  input         io_model_read_cmds_22_valid,
  input         io_model_read_cmds_22_bits_en,
  input  [8:0]  io_model_read_cmds_22_bits_addr,
  output        io_model_read_cmds_23_ready,
  input         io_model_read_cmds_23_valid,
  input         io_model_read_cmds_23_bits_en,
  input  [8:0]  io_model_read_cmds_23_bits_addr,
  output        io_model_read_cmds_24_ready,
  input         io_model_read_cmds_24_valid,
  input         io_model_read_cmds_24_bits_en,
  input  [8:0]  io_model_read_cmds_24_bits_addr,
  output        io_model_read_cmds_25_ready,
  input         io_model_read_cmds_25_valid,
  input         io_model_read_cmds_25_bits_en,
  input  [8:0]  io_model_read_cmds_25_bits_addr,
  output        io_model_read_cmds_26_ready,
  input         io_model_read_cmds_26_valid,
  input         io_model_read_cmds_26_bits_en,
  input  [8:0]  io_model_read_cmds_26_bits_addr,
  output        io_model_read_cmds_27_ready,
  input         io_model_read_cmds_27_valid,
  input         io_model_read_cmds_27_bits_en,
  input  [8:0]  io_model_read_cmds_27_bits_addr,
  output        io_model_read_cmds_28_ready,
  input         io_model_read_cmds_28_valid,
  input         io_model_read_cmds_28_bits_en,
  input  [8:0]  io_model_read_cmds_28_bits_addr,
  output        io_model_read_cmds_29_ready,
  input         io_model_read_cmds_29_valid,
  input         io_model_read_cmds_29_bits_en,
  input  [8:0]  io_model_read_cmds_29_bits_addr,
  output        io_model_read_cmds_30_ready,
  input         io_model_read_cmds_30_valid,
  input         io_model_read_cmds_30_bits_en,
  input  [8:0]  io_model_read_cmds_30_bits_addr,
  output        io_model_read_cmds_31_ready,
  input         io_model_read_cmds_31_valid,
  input         io_model_read_cmds_31_bits_en,
  input  [8:0]  io_model_read_cmds_31_bits_addr,
  output        io_model_read_cmds_32_ready,
  input         io_model_read_cmds_32_valid,
  input         io_model_read_cmds_32_bits_en,
  input  [8:0]  io_model_read_cmds_32_bits_addr,
  output        io_model_read_cmds_33_ready,
  input         io_model_read_cmds_33_valid,
  input         io_model_read_cmds_33_bits_en,
  input  [8:0]  io_model_read_cmds_33_bits_addr,
  output        io_model_read_cmds_34_ready,
  input         io_model_read_cmds_34_valid,
  input         io_model_read_cmds_34_bits_en,
  input  [8:0]  io_model_read_cmds_34_bits_addr,
  input         io_model_read_resps_0_ready,
  output        io_model_read_resps_0_valid,
  output [80:0] io_model_read_resps_0_bits,
  input         io_model_read_resps_1_ready,
  output        io_model_read_resps_1_valid,
  output [80:0] io_model_read_resps_1_bits,
  input         io_model_read_resps_2_ready,
  output        io_model_read_resps_2_valid,
  output [80:0] io_model_read_resps_2_bits,
  input         io_model_read_resps_3_ready,
  output        io_model_read_resps_3_valid,
  output [80:0] io_model_read_resps_3_bits,
  input         io_model_read_resps_4_ready,
  output        io_model_read_resps_4_valid,
  output [80:0] io_model_read_resps_4_bits,
  input         io_model_read_resps_5_ready,
  output        io_model_read_resps_5_valid,
  output [80:0] io_model_read_resps_5_bits,
  input         io_model_read_resps_6_ready,
  output        io_model_read_resps_6_valid,
  output [80:0] io_model_read_resps_6_bits,
  input         io_model_read_resps_7_ready,
  output        io_model_read_resps_7_valid,
  output [80:0] io_model_read_resps_7_bits,
  input         io_model_read_resps_8_ready,
  output        io_model_read_resps_8_valid,
  output [80:0] io_model_read_resps_8_bits,
  input         io_model_read_resps_9_ready,
  output        io_model_read_resps_9_valid,
  output [80:0] io_model_read_resps_9_bits,
  input         io_model_read_resps_10_ready,
  output        io_model_read_resps_10_valid,
  output [80:0] io_model_read_resps_10_bits,
  input         io_model_read_resps_11_ready,
  output        io_model_read_resps_11_valid,
  output [80:0] io_model_read_resps_11_bits,
  input         io_model_read_resps_12_ready,
  output        io_model_read_resps_12_valid,
  output [80:0] io_model_read_resps_12_bits,
  input         io_model_read_resps_13_ready,
  output        io_model_read_resps_13_valid,
  output [80:0] io_model_read_resps_13_bits,
  input         io_model_read_resps_14_ready,
  output        io_model_read_resps_14_valid,
  output [80:0] io_model_read_resps_14_bits,
  input         io_model_read_resps_15_ready,
  output        io_model_read_resps_15_valid,
  output [80:0] io_model_read_resps_15_bits,
  input         io_model_read_resps_16_ready,
  output        io_model_read_resps_16_valid,
  output [80:0] io_model_read_resps_16_bits,
  input         io_model_read_resps_17_ready,
  output        io_model_read_resps_17_valid,
  output [80:0] io_model_read_resps_17_bits,
  input         io_model_read_resps_18_ready,
  output        io_model_read_resps_18_valid,
  output [80:0] io_model_read_resps_18_bits,
  input         io_model_read_resps_19_ready,
  output        io_model_read_resps_19_valid,
  output [80:0] io_model_read_resps_19_bits,
  input         io_model_read_resps_20_ready,
  output        io_model_read_resps_20_valid,
  output [80:0] io_model_read_resps_20_bits,
  input         io_model_read_resps_21_ready,
  output        io_model_read_resps_21_valid,
  output [80:0] io_model_read_resps_21_bits,
  input         io_model_read_resps_22_ready,
  output        io_model_read_resps_22_valid,
  output [80:0] io_model_read_resps_22_bits,
  input         io_model_read_resps_23_ready,
  output        io_model_read_resps_23_valid,
  output [80:0] io_model_read_resps_23_bits,
  input         io_model_read_resps_24_ready,
  output        io_model_read_resps_24_valid,
  output [80:0] io_model_read_resps_24_bits,
  input         io_model_read_resps_25_ready,
  output        io_model_read_resps_25_valid,
  output [80:0] io_model_read_resps_25_bits,
  input         io_model_read_resps_26_ready,
  output        io_model_read_resps_26_valid,
  output [80:0] io_model_read_resps_26_bits,
  input         io_model_read_resps_27_ready,
  output        io_model_read_resps_27_valid,
  output [80:0] io_model_read_resps_27_bits,
  input         io_model_read_resps_28_ready,
  output        io_model_read_resps_28_valid,
  output [80:0] io_model_read_resps_28_bits,
  input         io_model_read_resps_29_ready,
  output        io_model_read_resps_29_valid,
  output [80:0] io_model_read_resps_29_bits,
  input         io_model_read_resps_30_ready,
  output        io_model_read_resps_30_valid,
  output [80:0] io_model_read_resps_30_bits,
  input         io_model_read_resps_31_ready,
  output        io_model_read_resps_31_valid,
  output [80:0] io_model_read_resps_31_bits,
  input         io_model_read_resps_32_ready,
  output        io_model_read_resps_32_valid,
  output [80:0] io_model_read_resps_32_bits,
  input         io_model_read_resps_33_ready,
  output        io_model_read_resps_33_valid,
  output [80:0] io_model_read_resps_33_bits,
  input         io_model_read_resps_34_ready,
  output        io_model_read_resps_34_valid,
  output [80:0] io_model_read_resps_34_bits,
  output        io_model_write_cmds_0_ready,
  input         io_model_write_cmds_0_valid,
  input         io_model_write_cmds_0_bits_en,
  input         io_model_write_cmds_0_bits_mask,
  input  [8:0]  io_model_write_cmds_0_bits_addr,
  input  [80:0] io_model_write_cmds_0_bits_data,
  input         io_reference_read_cmds_0_en,
  input  [8:0]  io_reference_read_cmds_0_addr,
  input         io_reference_read_cmds_1_en,
  input  [8:0]  io_reference_read_cmds_1_addr,
  input         io_reference_read_cmds_2_en,
  input  [8:0]  io_reference_read_cmds_2_addr,
  input         io_reference_read_cmds_3_en,
  input  [8:0]  io_reference_read_cmds_3_addr,
  input         io_reference_read_cmds_4_en,
  input  [8:0]  io_reference_read_cmds_4_addr,
  input         io_reference_read_cmds_5_en,
  input  [8:0]  io_reference_read_cmds_5_addr,
  input         io_reference_read_cmds_6_en,
  input  [8:0]  io_reference_read_cmds_6_addr,
  input         io_reference_read_cmds_7_en,
  input  [8:0]  io_reference_read_cmds_7_addr,
  input         io_reference_read_cmds_8_en,
  input  [8:0]  io_reference_read_cmds_8_addr,
  input         io_reference_read_cmds_9_en,
  input  [8:0]  io_reference_read_cmds_9_addr,
  input         io_reference_read_cmds_10_en,
  input  [8:0]  io_reference_read_cmds_10_addr,
  input         io_reference_read_cmds_11_en,
  input  [8:0]  io_reference_read_cmds_11_addr,
  input         io_reference_read_cmds_12_en,
  input  [8:0]  io_reference_read_cmds_12_addr,
  input         io_reference_read_cmds_13_en,
  input  [8:0]  io_reference_read_cmds_13_addr,
  input         io_reference_read_cmds_14_en,
  input  [8:0]  io_reference_read_cmds_14_addr,
  input         io_reference_read_cmds_15_en,
  input  [8:0]  io_reference_read_cmds_15_addr,
  input         io_reference_read_cmds_16_en,
  input  [8:0]  io_reference_read_cmds_16_addr,
  input         io_reference_read_cmds_17_en,
  input  [8:0]  io_reference_read_cmds_17_addr,
  input         io_reference_read_cmds_18_en,
  input  [8:0]  io_reference_read_cmds_18_addr,
  input         io_reference_read_cmds_19_en,
  input  [8:0]  io_reference_read_cmds_19_addr,
  input         io_reference_read_cmds_20_en,
  input  [8:0]  io_reference_read_cmds_20_addr,
  input         io_reference_read_cmds_21_en,
  input  [8:0]  io_reference_read_cmds_21_addr,
  input         io_reference_read_cmds_22_en,
  input  [8:0]  io_reference_read_cmds_22_addr,
  input         io_reference_read_cmds_23_en,
  input  [8:0]  io_reference_read_cmds_23_addr,
  input         io_reference_read_cmds_24_en,
  input  [8:0]  io_reference_read_cmds_24_addr,
  input         io_reference_read_cmds_25_en,
  input  [8:0]  io_reference_read_cmds_25_addr,
  input         io_reference_read_cmds_26_en,
  input  [8:0]  io_reference_read_cmds_26_addr,
  input         io_reference_read_cmds_27_en,
  input  [8:0]  io_reference_read_cmds_27_addr,
  input         io_reference_read_cmds_28_en,
  input  [8:0]  io_reference_read_cmds_28_addr,
  input         io_reference_read_cmds_29_en,
  input  [8:0]  io_reference_read_cmds_29_addr,
  input         io_reference_read_cmds_30_en,
  input  [8:0]  io_reference_read_cmds_30_addr,
  input         io_reference_read_cmds_31_en,
  input  [8:0]  io_reference_read_cmds_31_addr,
  input         io_reference_read_cmds_32_en,
  input  [8:0]  io_reference_read_cmds_32_addr,
  input         io_reference_read_cmds_33_en,
  input  [8:0]  io_reference_read_cmds_33_addr,
  input         io_reference_read_cmds_34_en,
  input  [8:0]  io_reference_read_cmds_34_addr,
  output [80:0] io_reference_read_resps_0,
  output [80:0] io_reference_read_resps_1,
  output [80:0] io_reference_read_resps_2,
  output [80:0] io_reference_read_resps_3,
  output [80:0] io_reference_read_resps_4,
  output [80:0] io_reference_read_resps_5,
  output [80:0] io_reference_read_resps_6,
  output [80:0] io_reference_read_resps_7,
  output [80:0] io_reference_read_resps_8,
  output [80:0] io_reference_read_resps_9,
  output [80:0] io_reference_read_resps_10,
  output [80:0] io_reference_read_resps_11,
  output [80:0] io_reference_read_resps_12,
  output [80:0] io_reference_read_resps_13,
  output [80:0] io_reference_read_resps_14,
  output [80:0] io_reference_read_resps_15,
  output [80:0] io_reference_read_resps_16,
  output [80:0] io_reference_read_resps_17,
  output [80:0] io_reference_read_resps_18,
  output [80:0] io_reference_read_resps_19,
  output [80:0] io_reference_read_resps_20,
  output [80:0] io_reference_read_resps_21,
  output [80:0] io_reference_read_resps_22,
  output [80:0] io_reference_read_resps_23,
  output [80:0] io_reference_read_resps_24,
  output [80:0] io_reference_read_resps_25,
  output [80:0] io_reference_read_resps_26,
  output [80:0] io_reference_read_resps_27,
  output [80:0] io_reference_read_resps_28,
  output [80:0] io_reference_read_resps_29,
  output [80:0] io_reference_read_resps_30,
  output [80:0] io_reference_read_resps_31,
  output [80:0] io_reference_read_resps_32,
  output [80:0] io_reference_read_resps_33,
  output [80:0] io_reference_read_resps_34,
  input         io_reference_write_cmds_0_en,
  input         io_reference_write_cmds_0_mask,
  input  [8:0]  io_reference_write_cmds_0_addr,
  input  [80:0] io_reference_write_cmds_0_data
);
  wire  host_clock; // @[Prototype.scala 17:20]
  wire  host_reset; // @[Prototype.scala 17:20]
  wire  host_channels_reset_ready; // @[Prototype.scala 17:20]
  wire  host_channels_reset_valid; // @[Prototype.scala 17:20]
  wire  host_channels_reset_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_0_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_0_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_0_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_1_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_1_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_1_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_2_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_2_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_2_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_3_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_3_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_3_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_4_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_4_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_4_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_5_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_5_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_5_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_6_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_6_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_6_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_7_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_7_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_7_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_8_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_8_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_8_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_9_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_9_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_9_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_10_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_10_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_10_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_11_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_11_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_11_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_12_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_12_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_12_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_13_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_13_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_13_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_14_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_14_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_14_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_15_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_15_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_15_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_16_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_16_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_16_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_17_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_17_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_17_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_18_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_18_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_18_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_19_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_19_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_19_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_20_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_20_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_20_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_21_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_21_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_21_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_22_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_22_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_22_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_23_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_23_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_23_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_24_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_24_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_24_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_25_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_25_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_25_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_26_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_26_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_26_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_27_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_27_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_27_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_28_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_28_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_28_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_29_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_29_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_29_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_30_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_30_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_30_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_31_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_31_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_31_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_32_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_32_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_32_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_33_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_33_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_33_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_34_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_cmds_34_valid; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_read_cmds_34_bits_addr; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_0_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_0_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_0_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_1_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_1_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_1_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_2_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_2_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_2_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_3_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_3_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_3_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_4_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_4_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_4_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_5_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_5_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_5_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_6_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_6_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_6_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_7_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_7_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_7_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_8_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_8_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_8_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_9_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_9_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_9_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_10_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_10_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_10_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_11_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_11_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_11_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_12_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_12_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_12_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_13_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_13_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_13_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_14_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_14_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_14_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_15_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_15_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_15_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_16_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_16_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_16_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_17_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_17_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_17_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_18_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_18_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_18_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_19_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_19_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_19_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_20_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_20_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_20_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_21_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_21_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_21_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_22_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_22_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_22_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_23_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_23_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_23_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_24_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_24_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_24_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_25_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_25_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_25_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_26_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_26_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_26_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_27_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_27_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_27_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_28_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_28_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_28_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_29_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_29_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_29_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_30_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_30_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_30_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_31_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_31_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_31_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_32_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_32_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_32_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_33_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_33_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_33_bits; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_34_ready; // @[Prototype.scala 17:20]
  wire  host_channels_read_resps_34_valid; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_read_resps_34_bits; // @[Prototype.scala 17:20]
  wire  host_channels_write_cmds_0_ready; // @[Prototype.scala 17:20]
  wire  host_channels_write_cmds_0_valid; // @[Prototype.scala 17:20]
  wire  host_channels_write_cmds_0_bits_en; // @[Prototype.scala 17:20]
  wire  host_channels_write_cmds_0_bits_mask; // @[Prototype.scala 17:20]
  wire [8:0] host_channels_write_cmds_0_bits_addr; // @[Prototype.scala 17:20]
  wire [80:0] host_channels_write_cmds_0_bits_data; // @[Prototype.scala 17:20]
  wire  target_clock; // @[Prototype.scala 19:11]
  wire  target_reset; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_0_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_1_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_2_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_3_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_4_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_5_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_6_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_7_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_8_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_9_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_10_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_11_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_12_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_13_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_14_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_15_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_16_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_17_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_18_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_19_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_20_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_21_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_22_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_23_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_24_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_25_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_26_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_27_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_28_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_29_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_30_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_31_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_32_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_33_addr; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_read_cmds_34_addr; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_0; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_1; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_2; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_3; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_4; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_5; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_6; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_7; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_8; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_9; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_10; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_11; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_12; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_13; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_14; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_15; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_16; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_17; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_18; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_19; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_20; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_21; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_22; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_23; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_24; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_25; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_26; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_27; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_28; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_29; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_30; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_31; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_32; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_33; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_read_resps_34; // @[Prototype.scala 19:11]
  wire  target_channels_write_cmds_0_en; // @[Prototype.scala 19:11]
  wire  target_channels_write_cmds_0_mask; // @[Prototype.scala 19:11]
  wire [8:0] target_channels_write_cmds_0_addr; // @[Prototype.scala 19:11]
  wire [80:0] target_channels_write_cmds_0_data; // @[Prototype.scala 19:11]
  AsyncMemChiselModel host ( // @[Prototype.scala 17:20]
    .clock(host_clock),
    .reset(host_reset),
    .channels_reset_ready(host_channels_reset_ready),
    .channels_reset_valid(host_channels_reset_valid),
    .channels_reset_bits(host_channels_reset_bits),
    .channels_read_cmds_0_ready(host_channels_read_cmds_0_ready),
    .channels_read_cmds_0_valid(host_channels_read_cmds_0_valid),
    .channels_read_cmds_0_bits_addr(host_channels_read_cmds_0_bits_addr),
    .channels_read_cmds_1_ready(host_channels_read_cmds_1_ready),
    .channels_read_cmds_1_valid(host_channels_read_cmds_1_valid),
    .channels_read_cmds_1_bits_addr(host_channels_read_cmds_1_bits_addr),
    .channels_read_cmds_2_ready(host_channels_read_cmds_2_ready),
    .channels_read_cmds_2_valid(host_channels_read_cmds_2_valid),
    .channels_read_cmds_2_bits_addr(host_channels_read_cmds_2_bits_addr),
    .channels_read_cmds_3_ready(host_channels_read_cmds_3_ready),
    .channels_read_cmds_3_valid(host_channels_read_cmds_3_valid),
    .channels_read_cmds_3_bits_addr(host_channels_read_cmds_3_bits_addr),
    .channels_read_cmds_4_ready(host_channels_read_cmds_4_ready),
    .channels_read_cmds_4_valid(host_channels_read_cmds_4_valid),
    .channels_read_cmds_4_bits_addr(host_channels_read_cmds_4_bits_addr),
    .channels_read_cmds_5_ready(host_channels_read_cmds_5_ready),
    .channels_read_cmds_5_valid(host_channels_read_cmds_5_valid),
    .channels_read_cmds_5_bits_addr(host_channels_read_cmds_5_bits_addr),
    .channels_read_cmds_6_ready(host_channels_read_cmds_6_ready),
    .channels_read_cmds_6_valid(host_channels_read_cmds_6_valid),
    .channels_read_cmds_6_bits_addr(host_channels_read_cmds_6_bits_addr),
    .channels_read_cmds_7_ready(host_channels_read_cmds_7_ready),
    .channels_read_cmds_7_valid(host_channels_read_cmds_7_valid),
    .channels_read_cmds_7_bits_addr(host_channels_read_cmds_7_bits_addr),
    .channels_read_cmds_8_ready(host_channels_read_cmds_8_ready),
    .channels_read_cmds_8_valid(host_channels_read_cmds_8_valid),
    .channels_read_cmds_8_bits_addr(host_channels_read_cmds_8_bits_addr),
    .channels_read_cmds_9_ready(host_channels_read_cmds_9_ready),
    .channels_read_cmds_9_valid(host_channels_read_cmds_9_valid),
    .channels_read_cmds_9_bits_addr(host_channels_read_cmds_9_bits_addr),
    .channels_read_cmds_10_ready(host_channels_read_cmds_10_ready),
    .channels_read_cmds_10_valid(host_channels_read_cmds_10_valid),
    .channels_read_cmds_10_bits_addr(host_channels_read_cmds_10_bits_addr),
    .channels_read_cmds_11_ready(host_channels_read_cmds_11_ready),
    .channels_read_cmds_11_valid(host_channels_read_cmds_11_valid),
    .channels_read_cmds_11_bits_addr(host_channels_read_cmds_11_bits_addr),
    .channels_read_cmds_12_ready(host_channels_read_cmds_12_ready),
    .channels_read_cmds_12_valid(host_channels_read_cmds_12_valid),
    .channels_read_cmds_12_bits_addr(host_channels_read_cmds_12_bits_addr),
    .channels_read_cmds_13_ready(host_channels_read_cmds_13_ready),
    .channels_read_cmds_13_valid(host_channels_read_cmds_13_valid),
    .channels_read_cmds_13_bits_addr(host_channels_read_cmds_13_bits_addr),
    .channels_read_cmds_14_ready(host_channels_read_cmds_14_ready),
    .channels_read_cmds_14_valid(host_channels_read_cmds_14_valid),
    .channels_read_cmds_14_bits_addr(host_channels_read_cmds_14_bits_addr),
    .channels_read_cmds_15_ready(host_channels_read_cmds_15_ready),
    .channels_read_cmds_15_valid(host_channels_read_cmds_15_valid),
    .channels_read_cmds_15_bits_addr(host_channels_read_cmds_15_bits_addr),
    .channels_read_cmds_16_ready(host_channels_read_cmds_16_ready),
    .channels_read_cmds_16_valid(host_channels_read_cmds_16_valid),
    .channels_read_cmds_16_bits_addr(host_channels_read_cmds_16_bits_addr),
    .channels_read_cmds_17_ready(host_channels_read_cmds_17_ready),
    .channels_read_cmds_17_valid(host_channels_read_cmds_17_valid),
    .channels_read_cmds_17_bits_addr(host_channels_read_cmds_17_bits_addr),
    .channels_read_cmds_18_ready(host_channels_read_cmds_18_ready),
    .channels_read_cmds_18_valid(host_channels_read_cmds_18_valid),
    .channels_read_cmds_18_bits_addr(host_channels_read_cmds_18_bits_addr),
    .channels_read_cmds_19_ready(host_channels_read_cmds_19_ready),
    .channels_read_cmds_19_valid(host_channels_read_cmds_19_valid),
    .channels_read_cmds_19_bits_addr(host_channels_read_cmds_19_bits_addr),
    .channels_read_cmds_20_ready(host_channels_read_cmds_20_ready),
    .channels_read_cmds_20_valid(host_channels_read_cmds_20_valid),
    .channels_read_cmds_20_bits_addr(host_channels_read_cmds_20_bits_addr),
    .channels_read_cmds_21_ready(host_channels_read_cmds_21_ready),
    .channels_read_cmds_21_valid(host_channels_read_cmds_21_valid),
    .channels_read_cmds_21_bits_addr(host_channels_read_cmds_21_bits_addr),
    .channels_read_cmds_22_ready(host_channels_read_cmds_22_ready),
    .channels_read_cmds_22_valid(host_channels_read_cmds_22_valid),
    .channels_read_cmds_22_bits_addr(host_channels_read_cmds_22_bits_addr),
    .channels_read_cmds_23_ready(host_channels_read_cmds_23_ready),
    .channels_read_cmds_23_valid(host_channels_read_cmds_23_valid),
    .channels_read_cmds_23_bits_addr(host_channels_read_cmds_23_bits_addr),
    .channels_read_cmds_24_ready(host_channels_read_cmds_24_ready),
    .channels_read_cmds_24_valid(host_channels_read_cmds_24_valid),
    .channels_read_cmds_24_bits_addr(host_channels_read_cmds_24_bits_addr),
    .channels_read_cmds_25_ready(host_channels_read_cmds_25_ready),
    .channels_read_cmds_25_valid(host_channels_read_cmds_25_valid),
    .channels_read_cmds_25_bits_addr(host_channels_read_cmds_25_bits_addr),
    .channels_read_cmds_26_ready(host_channels_read_cmds_26_ready),
    .channels_read_cmds_26_valid(host_channels_read_cmds_26_valid),
    .channels_read_cmds_26_bits_addr(host_channels_read_cmds_26_bits_addr),
    .channels_read_cmds_27_ready(host_channels_read_cmds_27_ready),
    .channels_read_cmds_27_valid(host_channels_read_cmds_27_valid),
    .channels_read_cmds_27_bits_addr(host_channels_read_cmds_27_bits_addr),
    .channels_read_cmds_28_ready(host_channels_read_cmds_28_ready),
    .channels_read_cmds_28_valid(host_channels_read_cmds_28_valid),
    .channels_read_cmds_28_bits_addr(host_channels_read_cmds_28_bits_addr),
    .channels_read_cmds_29_ready(host_channels_read_cmds_29_ready),
    .channels_read_cmds_29_valid(host_channels_read_cmds_29_valid),
    .channels_read_cmds_29_bits_addr(host_channels_read_cmds_29_bits_addr),
    .channels_read_cmds_30_ready(host_channels_read_cmds_30_ready),
    .channels_read_cmds_30_valid(host_channels_read_cmds_30_valid),
    .channels_read_cmds_30_bits_addr(host_channels_read_cmds_30_bits_addr),
    .channels_read_cmds_31_ready(host_channels_read_cmds_31_ready),
    .channels_read_cmds_31_valid(host_channels_read_cmds_31_valid),
    .channels_read_cmds_31_bits_addr(host_channels_read_cmds_31_bits_addr),
    .channels_read_cmds_32_ready(host_channels_read_cmds_32_ready),
    .channels_read_cmds_32_valid(host_channels_read_cmds_32_valid),
    .channels_read_cmds_32_bits_addr(host_channels_read_cmds_32_bits_addr),
    .channels_read_cmds_33_ready(host_channels_read_cmds_33_ready),
    .channels_read_cmds_33_valid(host_channels_read_cmds_33_valid),
    .channels_read_cmds_33_bits_addr(host_channels_read_cmds_33_bits_addr),
    .channels_read_cmds_34_ready(host_channels_read_cmds_34_ready),
    .channels_read_cmds_34_valid(host_channels_read_cmds_34_valid),
    .channels_read_cmds_34_bits_addr(host_channels_read_cmds_34_bits_addr),
    .channels_read_resps_0_ready(host_channels_read_resps_0_ready),
    .channels_read_resps_0_valid(host_channels_read_resps_0_valid),
    .channels_read_resps_0_bits(host_channels_read_resps_0_bits),
    .channels_read_resps_1_ready(host_channels_read_resps_1_ready),
    .channels_read_resps_1_valid(host_channels_read_resps_1_valid),
    .channels_read_resps_1_bits(host_channels_read_resps_1_bits),
    .channels_read_resps_2_ready(host_channels_read_resps_2_ready),
    .channels_read_resps_2_valid(host_channels_read_resps_2_valid),
    .channels_read_resps_2_bits(host_channels_read_resps_2_bits),
    .channels_read_resps_3_ready(host_channels_read_resps_3_ready),
    .channels_read_resps_3_valid(host_channels_read_resps_3_valid),
    .channels_read_resps_3_bits(host_channels_read_resps_3_bits),
    .channels_read_resps_4_ready(host_channels_read_resps_4_ready),
    .channels_read_resps_4_valid(host_channels_read_resps_4_valid),
    .channels_read_resps_4_bits(host_channels_read_resps_4_bits),
    .channels_read_resps_5_ready(host_channels_read_resps_5_ready),
    .channels_read_resps_5_valid(host_channels_read_resps_5_valid),
    .channels_read_resps_5_bits(host_channels_read_resps_5_bits),
    .channels_read_resps_6_ready(host_channels_read_resps_6_ready),
    .channels_read_resps_6_valid(host_channels_read_resps_6_valid),
    .channels_read_resps_6_bits(host_channels_read_resps_6_bits),
    .channels_read_resps_7_ready(host_channels_read_resps_7_ready),
    .channels_read_resps_7_valid(host_channels_read_resps_7_valid),
    .channels_read_resps_7_bits(host_channels_read_resps_7_bits),
    .channels_read_resps_8_ready(host_channels_read_resps_8_ready),
    .channels_read_resps_8_valid(host_channels_read_resps_8_valid),
    .channels_read_resps_8_bits(host_channels_read_resps_8_bits),
    .channels_read_resps_9_ready(host_channels_read_resps_9_ready),
    .channels_read_resps_9_valid(host_channels_read_resps_9_valid),
    .channels_read_resps_9_bits(host_channels_read_resps_9_bits),
    .channels_read_resps_10_ready(host_channels_read_resps_10_ready),
    .channels_read_resps_10_valid(host_channels_read_resps_10_valid),
    .channels_read_resps_10_bits(host_channels_read_resps_10_bits),
    .channels_read_resps_11_ready(host_channels_read_resps_11_ready),
    .channels_read_resps_11_valid(host_channels_read_resps_11_valid),
    .channels_read_resps_11_bits(host_channels_read_resps_11_bits),
    .channels_read_resps_12_ready(host_channels_read_resps_12_ready),
    .channels_read_resps_12_valid(host_channels_read_resps_12_valid),
    .channels_read_resps_12_bits(host_channels_read_resps_12_bits),
    .channels_read_resps_13_ready(host_channels_read_resps_13_ready),
    .channels_read_resps_13_valid(host_channels_read_resps_13_valid),
    .channels_read_resps_13_bits(host_channels_read_resps_13_bits),
    .channels_read_resps_14_ready(host_channels_read_resps_14_ready),
    .channels_read_resps_14_valid(host_channels_read_resps_14_valid),
    .channels_read_resps_14_bits(host_channels_read_resps_14_bits),
    .channels_read_resps_15_ready(host_channels_read_resps_15_ready),
    .channels_read_resps_15_valid(host_channels_read_resps_15_valid),
    .channels_read_resps_15_bits(host_channels_read_resps_15_bits),
    .channels_read_resps_16_ready(host_channels_read_resps_16_ready),
    .channels_read_resps_16_valid(host_channels_read_resps_16_valid),
    .channels_read_resps_16_bits(host_channels_read_resps_16_bits),
    .channels_read_resps_17_ready(host_channels_read_resps_17_ready),
    .channels_read_resps_17_valid(host_channels_read_resps_17_valid),
    .channels_read_resps_17_bits(host_channels_read_resps_17_bits),
    .channels_read_resps_18_ready(host_channels_read_resps_18_ready),
    .channels_read_resps_18_valid(host_channels_read_resps_18_valid),
    .channels_read_resps_18_bits(host_channels_read_resps_18_bits),
    .channels_read_resps_19_ready(host_channels_read_resps_19_ready),
    .channels_read_resps_19_valid(host_channels_read_resps_19_valid),
    .channels_read_resps_19_bits(host_channels_read_resps_19_bits),
    .channels_read_resps_20_ready(host_channels_read_resps_20_ready),
    .channels_read_resps_20_valid(host_channels_read_resps_20_valid),
    .channels_read_resps_20_bits(host_channels_read_resps_20_bits),
    .channels_read_resps_21_ready(host_channels_read_resps_21_ready),
    .channels_read_resps_21_valid(host_channels_read_resps_21_valid),
    .channels_read_resps_21_bits(host_channels_read_resps_21_bits),
    .channels_read_resps_22_ready(host_channels_read_resps_22_ready),
    .channels_read_resps_22_valid(host_channels_read_resps_22_valid),
    .channels_read_resps_22_bits(host_channels_read_resps_22_bits),
    .channels_read_resps_23_ready(host_channels_read_resps_23_ready),
    .channels_read_resps_23_valid(host_channels_read_resps_23_valid),
    .channels_read_resps_23_bits(host_channels_read_resps_23_bits),
    .channels_read_resps_24_ready(host_channels_read_resps_24_ready),
    .channels_read_resps_24_valid(host_channels_read_resps_24_valid),
    .channels_read_resps_24_bits(host_channels_read_resps_24_bits),
    .channels_read_resps_25_ready(host_channels_read_resps_25_ready),
    .channels_read_resps_25_valid(host_channels_read_resps_25_valid),
    .channels_read_resps_25_bits(host_channels_read_resps_25_bits),
    .channels_read_resps_26_ready(host_channels_read_resps_26_ready),
    .channels_read_resps_26_valid(host_channels_read_resps_26_valid),
    .channels_read_resps_26_bits(host_channels_read_resps_26_bits),
    .channels_read_resps_27_ready(host_channels_read_resps_27_ready),
    .channels_read_resps_27_valid(host_channels_read_resps_27_valid),
    .channels_read_resps_27_bits(host_channels_read_resps_27_bits),
    .channels_read_resps_28_ready(host_channels_read_resps_28_ready),
    .channels_read_resps_28_valid(host_channels_read_resps_28_valid),
    .channels_read_resps_28_bits(host_channels_read_resps_28_bits),
    .channels_read_resps_29_ready(host_channels_read_resps_29_ready),
    .channels_read_resps_29_valid(host_channels_read_resps_29_valid),
    .channels_read_resps_29_bits(host_channels_read_resps_29_bits),
    .channels_read_resps_30_ready(host_channels_read_resps_30_ready),
    .channels_read_resps_30_valid(host_channels_read_resps_30_valid),
    .channels_read_resps_30_bits(host_channels_read_resps_30_bits),
    .channels_read_resps_31_ready(host_channels_read_resps_31_ready),
    .channels_read_resps_31_valid(host_channels_read_resps_31_valid),
    .channels_read_resps_31_bits(host_channels_read_resps_31_bits),
    .channels_read_resps_32_ready(host_channels_read_resps_32_ready),
    .channels_read_resps_32_valid(host_channels_read_resps_32_valid),
    .channels_read_resps_32_bits(host_channels_read_resps_32_bits),
    .channels_read_resps_33_ready(host_channels_read_resps_33_ready),
    .channels_read_resps_33_valid(host_channels_read_resps_33_valid),
    .channels_read_resps_33_bits(host_channels_read_resps_33_bits),
    .channels_read_resps_34_ready(host_channels_read_resps_34_ready),
    .channels_read_resps_34_valid(host_channels_read_resps_34_valid),
    .channels_read_resps_34_bits(host_channels_read_resps_34_bits),
    .channels_write_cmds_0_ready(host_channels_write_cmds_0_ready),
    .channels_write_cmds_0_valid(host_channels_write_cmds_0_valid),
    .channels_write_cmds_0_bits_en(host_channels_write_cmds_0_bits_en),
    .channels_write_cmds_0_bits_mask(host_channels_write_cmds_0_bits_mask),
    .channels_write_cmds_0_bits_addr(host_channels_write_cmds_0_bits_addr),
    .channels_write_cmds_0_bits_data(host_channels_write_cmds_0_bits_data)
  );
  AsyncMemChiselRTL target ( // @[Prototype.scala 19:11]
    .clock(target_clock),
    .reset(target_reset),
    .channels_read_cmds_0_addr(target_channels_read_cmds_0_addr),
    .channels_read_cmds_1_addr(target_channels_read_cmds_1_addr),
    .channels_read_cmds_2_addr(target_channels_read_cmds_2_addr),
    .channels_read_cmds_3_addr(target_channels_read_cmds_3_addr),
    .channels_read_cmds_4_addr(target_channels_read_cmds_4_addr),
    .channels_read_cmds_5_addr(target_channels_read_cmds_5_addr),
    .channels_read_cmds_6_addr(target_channels_read_cmds_6_addr),
    .channels_read_cmds_7_addr(target_channels_read_cmds_7_addr),
    .channels_read_cmds_8_addr(target_channels_read_cmds_8_addr),
    .channels_read_cmds_9_addr(target_channels_read_cmds_9_addr),
    .channels_read_cmds_10_addr(target_channels_read_cmds_10_addr),
    .channels_read_cmds_11_addr(target_channels_read_cmds_11_addr),
    .channels_read_cmds_12_addr(target_channels_read_cmds_12_addr),
    .channels_read_cmds_13_addr(target_channels_read_cmds_13_addr),
    .channels_read_cmds_14_addr(target_channels_read_cmds_14_addr),
    .channels_read_cmds_15_addr(target_channels_read_cmds_15_addr),
    .channels_read_cmds_16_addr(target_channels_read_cmds_16_addr),
    .channels_read_cmds_17_addr(target_channels_read_cmds_17_addr),
    .channels_read_cmds_18_addr(target_channels_read_cmds_18_addr),
    .channels_read_cmds_19_addr(target_channels_read_cmds_19_addr),
    .channels_read_cmds_20_addr(target_channels_read_cmds_20_addr),
    .channels_read_cmds_21_addr(target_channels_read_cmds_21_addr),
    .channels_read_cmds_22_addr(target_channels_read_cmds_22_addr),
    .channels_read_cmds_23_addr(target_channels_read_cmds_23_addr),
    .channels_read_cmds_24_addr(target_channels_read_cmds_24_addr),
    .channels_read_cmds_25_addr(target_channels_read_cmds_25_addr),
    .channels_read_cmds_26_addr(target_channels_read_cmds_26_addr),
    .channels_read_cmds_27_addr(target_channels_read_cmds_27_addr),
    .channels_read_cmds_28_addr(target_channels_read_cmds_28_addr),
    .channels_read_cmds_29_addr(target_channels_read_cmds_29_addr),
    .channels_read_cmds_30_addr(target_channels_read_cmds_30_addr),
    .channels_read_cmds_31_addr(target_channels_read_cmds_31_addr),
    .channels_read_cmds_32_addr(target_channels_read_cmds_32_addr),
    .channels_read_cmds_33_addr(target_channels_read_cmds_33_addr),
    .channels_read_cmds_34_addr(target_channels_read_cmds_34_addr),
    .channels_read_resps_0(target_channels_read_resps_0),
    .channels_read_resps_1(target_channels_read_resps_1),
    .channels_read_resps_2(target_channels_read_resps_2),
    .channels_read_resps_3(target_channels_read_resps_3),
    .channels_read_resps_4(target_channels_read_resps_4),
    .channels_read_resps_5(target_channels_read_resps_5),
    .channels_read_resps_6(target_channels_read_resps_6),
    .channels_read_resps_7(target_channels_read_resps_7),
    .channels_read_resps_8(target_channels_read_resps_8),
    .channels_read_resps_9(target_channels_read_resps_9),
    .channels_read_resps_10(target_channels_read_resps_10),
    .channels_read_resps_11(target_channels_read_resps_11),
    .channels_read_resps_12(target_channels_read_resps_12),
    .channels_read_resps_13(target_channels_read_resps_13),
    .channels_read_resps_14(target_channels_read_resps_14),
    .channels_read_resps_15(target_channels_read_resps_15),
    .channels_read_resps_16(target_channels_read_resps_16),
    .channels_read_resps_17(target_channels_read_resps_17),
    .channels_read_resps_18(target_channels_read_resps_18),
    .channels_read_resps_19(target_channels_read_resps_19),
    .channels_read_resps_20(target_channels_read_resps_20),
    .channels_read_resps_21(target_channels_read_resps_21),
    .channels_read_resps_22(target_channels_read_resps_22),
    .channels_read_resps_23(target_channels_read_resps_23),
    .channels_read_resps_24(target_channels_read_resps_24),
    .channels_read_resps_25(target_channels_read_resps_25),
    .channels_read_resps_26(target_channels_read_resps_26),
    .channels_read_resps_27(target_channels_read_resps_27),
    .channels_read_resps_28(target_channels_read_resps_28),
    .channels_read_resps_29(target_channels_read_resps_29),
    .channels_read_resps_30(target_channels_read_resps_30),
    .channels_read_resps_31(target_channels_read_resps_31),
    .channels_read_resps_32(target_channels_read_resps_32),
    .channels_read_resps_33(target_channels_read_resps_33),
    .channels_read_resps_34(target_channels_read_resps_34),
    .channels_write_cmds_0_en(target_channels_write_cmds_0_en),
    .channels_write_cmds_0_mask(target_channels_write_cmds_0_mask),
    .channels_write_cmds_0_addr(target_channels_write_cmds_0_addr),
    .channels_write_cmds_0_data(target_channels_write_cmds_0_data)
  );
  assign io_model_reset_ready = host_channels_reset_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_0_ready = host_channels_read_cmds_0_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_1_ready = host_channels_read_cmds_1_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_2_ready = host_channels_read_cmds_2_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_3_ready = host_channels_read_cmds_3_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_4_ready = host_channels_read_cmds_4_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_5_ready = host_channels_read_cmds_5_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_6_ready = host_channels_read_cmds_6_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_7_ready = host_channels_read_cmds_7_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_8_ready = host_channels_read_cmds_8_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_9_ready = host_channels_read_cmds_9_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_10_ready = host_channels_read_cmds_10_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_11_ready = host_channels_read_cmds_11_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_12_ready = host_channels_read_cmds_12_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_13_ready = host_channels_read_cmds_13_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_14_ready = host_channels_read_cmds_14_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_15_ready = host_channels_read_cmds_15_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_16_ready = host_channels_read_cmds_16_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_17_ready = host_channels_read_cmds_17_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_18_ready = host_channels_read_cmds_18_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_19_ready = host_channels_read_cmds_19_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_20_ready = host_channels_read_cmds_20_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_21_ready = host_channels_read_cmds_21_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_22_ready = host_channels_read_cmds_22_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_23_ready = host_channels_read_cmds_23_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_24_ready = host_channels_read_cmds_24_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_25_ready = host_channels_read_cmds_25_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_26_ready = host_channels_read_cmds_26_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_27_ready = host_channels_read_cmds_27_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_28_ready = host_channels_read_cmds_28_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_29_ready = host_channels_read_cmds_29_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_30_ready = host_channels_read_cmds_30_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_31_ready = host_channels_read_cmds_31_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_32_ready = host_channels_read_cmds_32_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_33_ready = host_channels_read_cmds_33_ready; // @[Prototype.scala 21:17]
  assign io_model_read_cmds_34_ready = host_channels_read_cmds_34_ready; // @[Prototype.scala 21:17]
  assign io_model_read_resps_0_valid = host_channels_read_resps_0_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_0_bits = host_channels_read_resps_0_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_1_valid = host_channels_read_resps_1_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_1_bits = host_channels_read_resps_1_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_2_valid = host_channels_read_resps_2_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_2_bits = host_channels_read_resps_2_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_3_valid = host_channels_read_resps_3_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_3_bits = host_channels_read_resps_3_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_4_valid = host_channels_read_resps_4_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_4_bits = host_channels_read_resps_4_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_5_valid = host_channels_read_resps_5_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_5_bits = host_channels_read_resps_5_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_6_valid = host_channels_read_resps_6_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_6_bits = host_channels_read_resps_6_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_7_valid = host_channels_read_resps_7_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_7_bits = host_channels_read_resps_7_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_8_valid = host_channels_read_resps_8_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_8_bits = host_channels_read_resps_8_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_9_valid = host_channels_read_resps_9_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_9_bits = host_channels_read_resps_9_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_10_valid = host_channels_read_resps_10_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_10_bits = host_channels_read_resps_10_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_11_valid = host_channels_read_resps_11_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_11_bits = host_channels_read_resps_11_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_12_valid = host_channels_read_resps_12_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_12_bits = host_channels_read_resps_12_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_13_valid = host_channels_read_resps_13_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_13_bits = host_channels_read_resps_13_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_14_valid = host_channels_read_resps_14_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_14_bits = host_channels_read_resps_14_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_15_valid = host_channels_read_resps_15_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_15_bits = host_channels_read_resps_15_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_16_valid = host_channels_read_resps_16_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_16_bits = host_channels_read_resps_16_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_17_valid = host_channels_read_resps_17_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_17_bits = host_channels_read_resps_17_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_18_valid = host_channels_read_resps_18_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_18_bits = host_channels_read_resps_18_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_19_valid = host_channels_read_resps_19_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_19_bits = host_channels_read_resps_19_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_20_valid = host_channels_read_resps_20_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_20_bits = host_channels_read_resps_20_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_21_valid = host_channels_read_resps_21_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_21_bits = host_channels_read_resps_21_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_22_valid = host_channels_read_resps_22_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_22_bits = host_channels_read_resps_22_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_23_valid = host_channels_read_resps_23_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_23_bits = host_channels_read_resps_23_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_24_valid = host_channels_read_resps_24_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_24_bits = host_channels_read_resps_24_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_25_valid = host_channels_read_resps_25_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_25_bits = host_channels_read_resps_25_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_26_valid = host_channels_read_resps_26_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_26_bits = host_channels_read_resps_26_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_27_valid = host_channels_read_resps_27_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_27_bits = host_channels_read_resps_27_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_28_valid = host_channels_read_resps_28_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_28_bits = host_channels_read_resps_28_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_29_valid = host_channels_read_resps_29_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_29_bits = host_channels_read_resps_29_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_30_valid = host_channels_read_resps_30_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_30_bits = host_channels_read_resps_30_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_31_valid = host_channels_read_resps_31_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_31_bits = host_channels_read_resps_31_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_32_valid = host_channels_read_resps_32_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_32_bits = host_channels_read_resps_32_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_33_valid = host_channels_read_resps_33_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_33_bits = host_channels_read_resps_33_bits; // @[Prototype.scala 21:17]
  assign io_model_read_resps_34_valid = host_channels_read_resps_34_valid; // @[Prototype.scala 21:17]
  assign io_model_read_resps_34_bits = host_channels_read_resps_34_bits; // @[Prototype.scala 21:17]
  assign io_model_write_cmds_0_ready = host_channels_write_cmds_0_ready; // @[Prototype.scala 21:17]
  assign io_reference_read_resps_0 = target_channels_read_resps_0; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_1 = target_channels_read_resps_1; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_2 = target_channels_read_resps_2; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_3 = target_channels_read_resps_3; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_4 = target_channels_read_resps_4; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_5 = target_channels_read_resps_5; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_6 = target_channels_read_resps_6; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_7 = target_channels_read_resps_7; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_8 = target_channels_read_resps_8; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_9 = target_channels_read_resps_9; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_10 = target_channels_read_resps_10; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_11 = target_channels_read_resps_11; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_12 = target_channels_read_resps_12; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_13 = target_channels_read_resps_13; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_14 = target_channels_read_resps_14; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_15 = target_channels_read_resps_15; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_16 = target_channels_read_resps_16; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_17 = target_channels_read_resps_17; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_18 = target_channels_read_resps_18; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_19 = target_channels_read_resps_19; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_20 = target_channels_read_resps_20; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_21 = target_channels_read_resps_21; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_22 = target_channels_read_resps_22; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_23 = target_channels_read_resps_23; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_24 = target_channels_read_resps_24; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_25 = target_channels_read_resps_25; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_26 = target_channels_read_resps_26; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_27 = target_channels_read_resps_27; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_28 = target_channels_read_resps_28; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_29 = target_channels_read_resps_29; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_30 = target_channels_read_resps_30; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_31 = target_channels_read_resps_31; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_32 = target_channels_read_resps_32; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_33 = target_channels_read_resps_33; // @[Prototype.scala 22:19]
  assign io_reference_read_resps_34 = target_channels_read_resps_34; // @[Prototype.scala 22:19]
  assign host_clock = clock;
  assign host_reset = reset;
  assign host_channels_reset_valid = io_model_reset_valid; // @[Prototype.scala 21:17]
  assign host_channels_reset_bits = io_model_reset_bits; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_0_valid = io_model_read_cmds_0_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_0_bits_addr = io_model_read_cmds_0_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_1_valid = io_model_read_cmds_1_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_1_bits_addr = io_model_read_cmds_1_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_2_valid = io_model_read_cmds_2_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_2_bits_addr = io_model_read_cmds_2_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_3_valid = io_model_read_cmds_3_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_3_bits_addr = io_model_read_cmds_3_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_4_valid = io_model_read_cmds_4_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_4_bits_addr = io_model_read_cmds_4_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_5_valid = io_model_read_cmds_5_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_5_bits_addr = io_model_read_cmds_5_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_6_valid = io_model_read_cmds_6_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_6_bits_addr = io_model_read_cmds_6_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_7_valid = io_model_read_cmds_7_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_7_bits_addr = io_model_read_cmds_7_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_8_valid = io_model_read_cmds_8_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_8_bits_addr = io_model_read_cmds_8_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_9_valid = io_model_read_cmds_9_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_9_bits_addr = io_model_read_cmds_9_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_10_valid = io_model_read_cmds_10_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_10_bits_addr = io_model_read_cmds_10_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_11_valid = io_model_read_cmds_11_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_11_bits_addr = io_model_read_cmds_11_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_12_valid = io_model_read_cmds_12_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_12_bits_addr = io_model_read_cmds_12_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_13_valid = io_model_read_cmds_13_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_13_bits_addr = io_model_read_cmds_13_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_14_valid = io_model_read_cmds_14_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_14_bits_addr = io_model_read_cmds_14_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_15_valid = io_model_read_cmds_15_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_15_bits_addr = io_model_read_cmds_15_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_16_valid = io_model_read_cmds_16_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_16_bits_addr = io_model_read_cmds_16_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_17_valid = io_model_read_cmds_17_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_17_bits_addr = io_model_read_cmds_17_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_18_valid = io_model_read_cmds_18_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_18_bits_addr = io_model_read_cmds_18_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_19_valid = io_model_read_cmds_19_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_19_bits_addr = io_model_read_cmds_19_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_20_valid = io_model_read_cmds_20_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_20_bits_addr = io_model_read_cmds_20_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_21_valid = io_model_read_cmds_21_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_21_bits_addr = io_model_read_cmds_21_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_22_valid = io_model_read_cmds_22_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_22_bits_addr = io_model_read_cmds_22_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_23_valid = io_model_read_cmds_23_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_23_bits_addr = io_model_read_cmds_23_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_24_valid = io_model_read_cmds_24_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_24_bits_addr = io_model_read_cmds_24_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_25_valid = io_model_read_cmds_25_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_25_bits_addr = io_model_read_cmds_25_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_26_valid = io_model_read_cmds_26_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_26_bits_addr = io_model_read_cmds_26_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_27_valid = io_model_read_cmds_27_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_27_bits_addr = io_model_read_cmds_27_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_28_valid = io_model_read_cmds_28_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_28_bits_addr = io_model_read_cmds_28_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_29_valid = io_model_read_cmds_29_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_29_bits_addr = io_model_read_cmds_29_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_30_valid = io_model_read_cmds_30_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_30_bits_addr = io_model_read_cmds_30_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_31_valid = io_model_read_cmds_31_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_31_bits_addr = io_model_read_cmds_31_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_32_valid = io_model_read_cmds_32_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_32_bits_addr = io_model_read_cmds_32_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_33_valid = io_model_read_cmds_33_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_33_bits_addr = io_model_read_cmds_33_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_34_valid = io_model_read_cmds_34_valid; // @[Prototype.scala 21:17]
  assign host_channels_read_cmds_34_bits_addr = io_model_read_cmds_34_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_0_ready = io_model_read_resps_0_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_1_ready = io_model_read_resps_1_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_2_ready = io_model_read_resps_2_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_3_ready = io_model_read_resps_3_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_4_ready = io_model_read_resps_4_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_5_ready = io_model_read_resps_5_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_6_ready = io_model_read_resps_6_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_7_ready = io_model_read_resps_7_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_8_ready = io_model_read_resps_8_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_9_ready = io_model_read_resps_9_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_10_ready = io_model_read_resps_10_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_11_ready = io_model_read_resps_11_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_12_ready = io_model_read_resps_12_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_13_ready = io_model_read_resps_13_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_14_ready = io_model_read_resps_14_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_15_ready = io_model_read_resps_15_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_16_ready = io_model_read_resps_16_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_17_ready = io_model_read_resps_17_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_18_ready = io_model_read_resps_18_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_19_ready = io_model_read_resps_19_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_20_ready = io_model_read_resps_20_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_21_ready = io_model_read_resps_21_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_22_ready = io_model_read_resps_22_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_23_ready = io_model_read_resps_23_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_24_ready = io_model_read_resps_24_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_25_ready = io_model_read_resps_25_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_26_ready = io_model_read_resps_26_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_27_ready = io_model_read_resps_27_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_28_ready = io_model_read_resps_28_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_29_ready = io_model_read_resps_29_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_30_ready = io_model_read_resps_30_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_31_ready = io_model_read_resps_31_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_32_ready = io_model_read_resps_32_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_33_ready = io_model_read_resps_33_ready; // @[Prototype.scala 21:17]
  assign host_channels_read_resps_34_ready = io_model_read_resps_34_ready; // @[Prototype.scala 21:17]
  assign host_channels_write_cmds_0_valid = io_model_write_cmds_0_valid; // @[Prototype.scala 21:17]
  assign host_channels_write_cmds_0_bits_en = io_model_write_cmds_0_bits_en; // @[Prototype.scala 21:17]
  assign host_channels_write_cmds_0_bits_mask = io_model_write_cmds_0_bits_mask; // @[Prototype.scala 21:17]
  assign host_channels_write_cmds_0_bits_addr = io_model_write_cmds_0_bits_addr; // @[Prototype.scala 21:17]
  assign host_channels_write_cmds_0_bits_data = io_model_write_cmds_0_bits_data; // @[Prototype.scala 21:17]
  assign target_clock = io_targetClock;
  assign target_reset = io_targetReset;
  assign target_channels_read_cmds_0_addr = io_reference_read_cmds_0_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_1_addr = io_reference_read_cmds_1_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_2_addr = io_reference_read_cmds_2_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_3_addr = io_reference_read_cmds_3_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_4_addr = io_reference_read_cmds_4_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_5_addr = io_reference_read_cmds_5_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_6_addr = io_reference_read_cmds_6_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_7_addr = io_reference_read_cmds_7_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_8_addr = io_reference_read_cmds_8_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_9_addr = io_reference_read_cmds_9_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_10_addr = io_reference_read_cmds_10_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_11_addr = io_reference_read_cmds_11_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_12_addr = io_reference_read_cmds_12_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_13_addr = io_reference_read_cmds_13_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_14_addr = io_reference_read_cmds_14_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_15_addr = io_reference_read_cmds_15_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_16_addr = io_reference_read_cmds_16_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_17_addr = io_reference_read_cmds_17_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_18_addr = io_reference_read_cmds_18_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_19_addr = io_reference_read_cmds_19_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_20_addr = io_reference_read_cmds_20_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_21_addr = io_reference_read_cmds_21_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_22_addr = io_reference_read_cmds_22_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_23_addr = io_reference_read_cmds_23_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_24_addr = io_reference_read_cmds_24_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_25_addr = io_reference_read_cmds_25_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_26_addr = io_reference_read_cmds_26_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_27_addr = io_reference_read_cmds_27_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_28_addr = io_reference_read_cmds_28_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_29_addr = io_reference_read_cmds_29_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_30_addr = io_reference_read_cmds_30_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_31_addr = io_reference_read_cmds_31_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_32_addr = io_reference_read_cmds_32_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_33_addr = io_reference_read_cmds_33_addr; // @[Prototype.scala 22:19]
  assign target_channels_read_cmds_34_addr = io_reference_read_cmds_34_addr; // @[Prototype.scala 22:19]
  assign target_channels_write_cmds_0_en = io_reference_write_cmds_0_en; // @[Prototype.scala 22:19]
  assign target_channels_write_cmds_0_mask = io_reference_write_cmds_0_mask; // @[Prototype.scala 22:19]
  assign target_channels_write_cmds_0_addr = io_reference_write_cmds_0_addr; // @[Prototype.scala 22:19]
  assign target_channels_write_cmds_0_data = io_reference_write_cmds_0_data; // @[Prototype.scala 22:19]
endmodule
