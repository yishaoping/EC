module Contract(
  input         clock,
  input         reset,
  input         io_valid_0,
  input         io_valid_1,
  input         io_valid_2,
  input         io_valid_3,
  input         io_valid_4,
  input         io_valid_5,
  input         io_valid_6,
  input         io_valid_7,
  input         io_valid_8,
  input         io_valid_9,
  input         io_valid_10,
  input         io_valid_11,
  input         io_valid_12,
  input         io_valid_13,
  input         io_valid_14,
  input         io_valid_15,
  input  [31:0] io_seq_0,
  input  [31:0] io_seq_1,
  input  [31:0] io_seq_2,
  input  [31:0] io_seq_3,
  input  [31:0] io_seq_4,
  input  [31:0] io_seq_5,
  input  [31:0] io_seq_6,
  input  [31:0] io_seq_7,
  input  [31:0] io_seq_8,
  input  [31:0] io_seq_9,
  input  [31:0] io_seq_10,
  input  [31:0] io_seq_11,
  input  [31:0] io_seq_12,
  input  [31:0] io_seq_13,
  input  [31:0] io_seq_14,
  input  [31:0] io_seq_15,
  input  [7:0]  io_base,
  input  [31:0] io_query,
  output        io_same
);
  wire [8:0] _io_same_T_1 = {{1'd0}, io_base}; // @[Query.scala 11:49]
  wire  _io_same_T_5 = io_query[7:0] == _io_same_T_1[7:0] & io_valid_0; // @[Query.scala 11:62]
  wire [7:0] _io_same_T_12 = io_base + 8'h1; // @[Query.scala 11:49]
  wire  _io_same_T_15 = io_query[7:0] == _io_same_T_12 & io_valid_1; // @[Query.scala 11:62]
  wire [7:0] _io_same_T_22 = io_base + 8'h2; // @[Query.scala 11:49]
  wire  _io_same_T_25 = io_query[7:0] == _io_same_T_22 & io_valid_2; // @[Query.scala 11:62]
  wire [7:0] _io_same_T_32 = io_base + 8'h3; // @[Query.scala 11:49]
  wire  _io_same_T_35 = io_query[7:0] == _io_same_T_32 & io_valid_3; // @[Query.scala 11:62]
  wire [7:0] _io_same_T_42 = io_base + 8'h4; // @[Query.scala 11:49]
  wire  _io_same_T_45 = io_query[7:0] == _io_same_T_42 & io_valid_4; // @[Query.scala 11:62]
  wire [7:0] _io_same_T_52 = io_base + 8'h5; // @[Query.scala 11:49]
  wire  _io_same_T_55 = io_query[7:0] == _io_same_T_52 & io_valid_5; // @[Query.scala 11:62]
  wire [7:0] _io_same_T_62 = io_base + 8'h6; // @[Query.scala 11:49]
  wire  _io_same_T_65 = io_query[7:0] == _io_same_T_62 & io_valid_6; // @[Query.scala 11:62]
  wire [7:0] _io_same_T_72 = io_base + 8'h7; // @[Query.scala 11:49]
  wire  _io_same_T_75 = io_query[7:0] == _io_same_T_72 & io_valid_7; // @[Query.scala 11:62]
  wire [7:0] _io_same_T_82 = io_base + 8'h8; // @[Query.scala 11:49]
  wire  _io_same_T_85 = io_query[7:0] == _io_same_T_82 & io_valid_8; // @[Query.scala 11:62]
  wire [7:0] _io_same_T_92 = io_base + 8'h9; // @[Query.scala 11:49]
  wire  _io_same_T_95 = io_query[7:0] == _io_same_T_92 & io_valid_9; // @[Query.scala 11:62]
  wire [7:0] _io_same_T_102 = io_base + 8'ha; // @[Query.scala 11:49]
  wire  _io_same_T_105 = io_query[7:0] == _io_same_T_102 & io_valid_10; // @[Query.scala 11:62]
  wire  _io_same_T_109 = _io_same_T_105 & io_seq_10[31:8] == io_query[31:8]; // @[Query.scala 12:16]
  wire [7:0] _io_same_T_112 = io_base + 8'hb; // @[Query.scala 11:49]
  wire  _io_same_T_115 = io_query[7:0] == _io_same_T_112 & io_valid_11; // @[Query.scala 11:62]
  wire [7:0] _io_same_T_122 = io_base + 8'hc; // @[Query.scala 11:49]
  wire  _io_same_T_125 = io_query[7:0] == _io_same_T_122 & io_valid_12; // @[Query.scala 11:62]
  wire [7:0] _io_same_T_132 = io_base + 8'hd; // @[Query.scala 11:49]
  wire  _io_same_T_135 = io_query[7:0] == _io_same_T_132 & io_valid_13; // @[Query.scala 11:62]
  wire [7:0] _io_same_T_142 = io_base + 8'he; // @[Query.scala 11:49]
  wire  _io_same_T_145 = io_query[7:0] == _io_same_T_142 & io_valid_14; // @[Query.scala 11:62]
  wire [7:0] _io_same_T_152 = io_base + 8'hf; // @[Query.scala 11:49]
  wire  _io_same_T_155 = io_query[7:0] == _io_same_T_152 & io_valid_15; // @[Query.scala 11:62]
  wire  _io_same_T_169 = _io_same_T_5 & io_seq_0[31:8] == io_query[31:8] | _io_same_T_15 & io_seq_1[31:8] == io_query[31
    :8] | _io_same_T_25 & io_seq_2[31:8] == io_query[31:8] | _io_same_T_35 & io_seq_3[31:8] == io_query[31:8] |
    _io_same_T_45 & io_seq_4[31:8] == io_query[31:8] | _io_same_T_55 & io_seq_5[31:8] == io_query[31:8] | _io_same_T_65
     & io_seq_6[31:8] == io_query[31:8] | _io_same_T_75 & io_seq_7[31:8] == io_query[31:8] | _io_same_T_85 & io_seq_8[31
    :8] == io_query[31:8] | _io_same_T_95 & io_seq_9[31:8] == io_query[31:8] | _io_same_T_109; // @[Query.scala 12:60]
  wire  _io_same_T_174 = _io_same_T_169 | _io_same_T_115 & io_seq_11[31:8] == io_query[31:8] | _io_same_T_125 &
    io_seq_12[31:8] == io_query[31:8] | _io_same_T_135 & io_seq_13[31:8] == io_query[31:8] | _io_same_T_145 & io_seq_14[
    31:8] == io_query[31:8] | _io_same_T_155 & io_seq_15[31:8] == io_query[31:8]; // @[Query.scala 12:60]
  wire [7:0] io_same_offset = io_query[7:0] - io_base; // @[BankTagRead.scala 14:31]
  wire [3:0] io_same_lane = io_same_offset[3:0]; // @[BankTagRead.scala 15:22]
  wire  _GEN_1 = 4'h1 == io_same_lane ? io_valid_1 : io_valid_0; // @[BankTagRead.scala 18:{26,26}]
  wire  _GEN_2 = 4'h2 == io_same_lane ? io_valid_2 : _GEN_1; // @[BankTagRead.scala 18:{26,26}]
  wire  _GEN_3 = 4'h3 == io_same_lane ? io_valid_3 : _GEN_2; // @[BankTagRead.scala 18:{26,26}]
  wire  _GEN_4 = 4'h4 == io_same_lane ? io_valid_4 : _GEN_3; // @[BankTagRead.scala 18:{26,26}]
  wire  _GEN_5 = 4'h5 == io_same_lane ? io_valid_5 : _GEN_4; // @[BankTagRead.scala 18:{26,26}]
  wire  _GEN_6 = 4'h6 == io_same_lane ? io_valid_6 : _GEN_5; // @[BankTagRead.scala 18:{26,26}]
  wire  _GEN_7 = 4'h7 == io_same_lane ? io_valid_7 : _GEN_6; // @[BankTagRead.scala 18:{26,26}]
  wire  _GEN_8 = 4'h8 == io_same_lane ? io_valid_8 : _GEN_7; // @[BankTagRead.scala 18:{26,26}]
  wire  _GEN_9 = 4'h9 == io_same_lane ? io_valid_9 : _GEN_8; // @[BankTagRead.scala 18:{26,26}]
  wire  _GEN_10 = 4'ha == io_same_lane ? io_valid_10 : _GEN_9; // @[BankTagRead.scala 18:{26,26}]
  wire  _GEN_11 = 4'hb == io_same_lane ? io_valid_11 : _GEN_10; // @[BankTagRead.scala 18:{26,26}]
  wire  _GEN_12 = 4'hc == io_same_lane ? io_valid_12 : _GEN_11; // @[BankTagRead.scala 18:{26,26}]
  wire  _GEN_13 = 4'hd == io_same_lane ? io_valid_13 : _GEN_12; // @[BankTagRead.scala 18:{26,26}]
  wire  _GEN_14 = 4'he == io_same_lane ? io_valid_14 : _GEN_13; // @[BankTagRead.scala 18:{26,26}]
  wire  _GEN_15 = 4'hf == io_same_lane ? io_valid_15 : _GEN_14; // @[BankTagRead.scala 18:{26,26}]
  wire [31:0] _GEN_17 = 4'h1 == io_same_lane ? io_seq_1 : io_seq_0; // @[BankTagRead.scala 18:{57,57}]
  wire [31:0] _GEN_18 = 4'h2 == io_same_lane ? io_seq_2 : _GEN_17; // @[BankTagRead.scala 18:{57,57}]
  wire [31:0] _GEN_19 = 4'h3 == io_same_lane ? io_seq_3 : _GEN_18; // @[BankTagRead.scala 18:{57,57}]
  wire [31:0] _GEN_20 = 4'h4 == io_same_lane ? io_seq_4 : _GEN_19; // @[BankTagRead.scala 18:{57,57}]
  wire [31:0] _GEN_21 = 4'h5 == io_same_lane ? io_seq_5 : _GEN_20; // @[BankTagRead.scala 18:{57,57}]
  wire [31:0] _GEN_22 = 4'h6 == io_same_lane ? io_seq_6 : _GEN_21; // @[BankTagRead.scala 18:{57,57}]
  wire [31:0] _GEN_23 = 4'h7 == io_same_lane ? io_seq_7 : _GEN_22; // @[BankTagRead.scala 18:{57,57}]
  wire [31:0] _GEN_24 = 4'h8 == io_same_lane ? io_seq_8 : _GEN_23; // @[BankTagRead.scala 18:{57,57}]
  wire [31:0] _GEN_25 = 4'h9 == io_same_lane ? io_seq_9 : _GEN_24; // @[BankTagRead.scala 18:{57,57}]
  wire [31:0] _GEN_26 = 4'ha == io_same_lane ? io_seq_10 : _GEN_25; // @[BankTagRead.scala 18:{57,57}]
  wire [31:0] _GEN_27 = 4'hb == io_same_lane ? io_seq_11 : _GEN_26; // @[BankTagRead.scala 18:{57,57}]
  wire [31:0] _GEN_28 = 4'hc == io_same_lane ? io_seq_12 : _GEN_27; // @[BankTagRead.scala 18:{57,57}]
  wire [31:0] _GEN_29 = 4'hd == io_same_lane ? io_seq_13 : _GEN_28; // @[BankTagRead.scala 18:{57,57}]
  wire [31:0] _GEN_30 = 4'he == io_same_lane ? io_seq_14 : _GEN_29; // @[BankTagRead.scala 18:{57,57}]
  wire [31:0] _GEN_31 = 4'hf == io_same_lane ? io_seq_15 : _GEN_30; // @[BankTagRead.scala 18:{57,57}]
  wire  _io_same_T_181 = io_same_offset[7:4] == 4'h0 & _GEN_15 & _GEN_31[31:8] == io_query[31:8]; // @[BankTagRead.scala 18:43]
  assign io_same = _io_same_T_174 == _io_same_T_181; // @[Query.scala 24:77]
endmodule
