module QueryContract(
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
  input  [31:0] io_seq_0,
  input  [31:0] io_seq_1,
  input  [31:0] io_seq_2,
  input  [31:0] io_seq_3,
  input  [31:0] io_seq_4,
  input  [31:0] io_seq_5,
  input  [31:0] io_seq_6,
  input  [31:0] io_seq_7,
  input  [7:0]  io_base,
  input  [31:0] io_query,
  output        io_same
);
  wire [8:0] _expected_T_1 = {{1'd0}, io_base}; // @[Geometry.scala 66:65]
  wire  _expected_T_5 = io_query[7:0] == _expected_T_1[7:0] & io_valid_0; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_12 = io_base + 8'h1; // @[Geometry.scala 66:65]
  wire  _expected_T_15 = io_query[7:0] == _expected_T_12 & io_valid_1; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_22 = io_base + 8'h2; // @[Geometry.scala 66:65]
  wire  _expected_T_25 = io_query[7:0] == _expected_T_22 & io_valid_2; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_32 = io_base + 8'h3; // @[Geometry.scala 66:65]
  wire  _expected_T_35 = io_query[7:0] == _expected_T_32 & io_valid_3; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_42 = io_base + 8'h4; // @[Geometry.scala 66:65]
  wire  _expected_T_45 = io_query[7:0] == _expected_T_42 & io_valid_4; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_52 = io_base + 8'h5; // @[Geometry.scala 66:65]
  wire  _expected_T_55 = io_query[7:0] == _expected_T_52 & io_valid_5; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_62 = io_base + 8'h6; // @[Geometry.scala 66:65]
  wire  _expected_T_65 = io_query[7:0] == _expected_T_62 & io_valid_6; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_72 = io_base + 8'h7; // @[Geometry.scala 66:65]
  wire  _expected_T_75 = io_query[7:0] == _expected_T_72 & io_valid_7; // @[Geometry.scala 66:76]
  wire  expected = _expected_T_5 & io_seq_0[31:8] == io_query[31:8] | _expected_T_15 & io_seq_1[31:8] == io_query[31:8]
     | _expected_T_25 & io_seq_2[31:8] == io_query[31:8] | _expected_T_35 & io_seq_3[31:8] == io_query[31:8] |
    _expected_T_45 & io_seq_4[31:8] == io_query[31:8] | _expected_T_55 & io_seq_5[31:8] == io_query[31:8] |
    _expected_T_65 & io_seq_6[31:8] == io_query[31:8] | _expected_T_75 & io_seq_7[31:8] == io_query[31:8]; // @[Geometry.scala 67:63]
  wire [7:0] io_same_offset = io_query[7:0] - io_base; // @[BankTagRead.scala 16:31]
  wire [2:0] io_same_lane = io_same_offset[2:0]; // @[BankTagRead.scala 17:22]
  wire  _GEN_1 = 3'h1 == io_same_lane ? io_valid_1 : io_valid_0; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_2 = 3'h2 == io_same_lane ? io_valid_2 : _GEN_1; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_3 = 3'h3 == io_same_lane ? io_valid_3 : _GEN_2; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_4 = 3'h4 == io_same_lane ? io_valid_4 : _GEN_3; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_5 = 3'h5 == io_same_lane ? io_valid_5 : _GEN_4; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_6 = 3'h6 == io_same_lane ? io_valid_6 : _GEN_5; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_7 = 3'h7 == io_same_lane ? io_valid_7 : _GEN_6; // @[BankTagRead.scala 20:{33,33}]
  wire [31:0] _GEN_9 = 3'h1 == io_same_lane ? io_seq_1 : io_seq_0; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_10 = 3'h2 == io_same_lane ? io_seq_2 : _GEN_9; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_11 = 3'h3 == io_same_lane ? io_seq_3 : _GEN_10; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_12 = 3'h4 == io_same_lane ? io_seq_4 : _GEN_11; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_13 = 3'h5 == io_same_lane ? io_seq_5 : _GEN_12; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_14 = 3'h6 == io_same_lane ? io_seq_6 : _GEN_13; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_15 = 3'h7 == io_same_lane ? io_seq_7 : _GEN_14; // @[BankTagRead.scala 20:{64,64}]
  wire  _io_same_T_6 = io_same_offset[7:3] == 5'h0 & _GEN_7 & _GEN_15[31:8] == io_query[31:8]; // @[BankTagRead.scala 20:50]
  assign io_same = expected == _io_same_T_6; // @[Geometry.scala 68:23]
endmodule
