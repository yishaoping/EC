module CompressorContracts(
  input        clock,
  input        reset,
  input  [9:0] io_a_0,
  input  [9:0] io_a_1,
  input  [9:0] io_a_2,
  input  [9:0] io_b_0,
  input  [9:0] io_b_1,
  input  [9:0] io_b_2,
  input  [9:0] io_c_0,
  input  [9:0] io_c_1,
  input  [9:0] io_c_2,
  output       io_same
);
  wire [6:0] io_same_a = io_a_0[6:0]; // @[Delta.scala 40:20]
  wire [6:0] io_same_b = io_b_0[6:0]; // @[Delta.scala 41:20]
  wire [6:0] io_same_c = io_c_0[6:0]; // @[Delta.scala 42:20]
  wire [6:0] _io_same_sum_T = io_same_a ^ io_same_b; // @[WeightedCarrySave.scala 12:17]
  wire [6:0] io_same_s = _io_same_sum_T ^ io_same_c; // @[WeightedCarrySave.scala 12:21]
  wire [6:0] _io_same_carry_T = io_same_a & io_same_b; // @[WeightedCarrySave.scala 13:22]
  wire [6:0] _io_same_carry_T_1 = io_same_a & io_same_c; // @[WeightedCarrySave.scala 13:32]
  wire [6:0] _io_same_carry_T_2 = _io_same_carry_T | _io_same_carry_T_1; // @[WeightedCarrySave.scala 13:27]
  wire [6:0] _io_same_carry_T_3 = io_same_b & io_same_c; // @[WeightedCarrySave.scala 13:42]
  wire [6:0] _io_same_carry_T_4 = _io_same_carry_T_2 | _io_same_carry_T_3; // @[WeightedCarrySave.scala 13:37]
  wire [7:0] _io_same_carry_T_5 = {_io_same_carry_T_4, 1'h0}; // @[WeightedCarrySave.scala 13:48]
  wire [6:0] io_same_carry = _io_same_carry_T_5[6:0]; // @[WeightedCarrySave.scala 13:53]
  wire [6:0] _io_same_T_1 = io_same_s + io_same_carry; // @[Delta.scala 44:8]
  wire [6:0] _io_same_T_3 = io_same_a + io_same_b; // @[Delta.scala 44:24]
  wire [6:0] _io_same_T_5 = _io_same_T_3 + io_same_c; // @[Delta.scala 44:28]
  wire  _io_same_T_6 = _io_same_T_1 == _io_same_T_5; // @[Delta.scala 44:17]
  wire [7:0] io_same_a_1 = io_a_1[7:0]; // @[Delta.scala 40:20]
  wire [7:0] io_same_b_1 = io_b_1[7:0]; // @[Delta.scala 41:20]
  wire [7:0] io_same_c_1 = io_c_1[7:0]; // @[Delta.scala 42:20]
  wire [7:0] _io_same_sum_T_1 = io_same_a_1 ^ io_same_b_1; // @[WeightedCarrySave.scala 12:17]
  wire [7:0] io_same_s_1 = _io_same_sum_T_1 ^ io_same_c_1; // @[WeightedCarrySave.scala 12:21]
  wire [7:0] _io_same_carry_T_6 = io_same_a_1 & io_same_b_1; // @[WeightedCarrySave.scala 13:22]
  wire [7:0] _io_same_carry_T_7 = io_same_a_1 & io_same_c_1; // @[WeightedCarrySave.scala 13:32]
  wire [7:0] _io_same_carry_T_8 = _io_same_carry_T_6 | _io_same_carry_T_7; // @[WeightedCarrySave.scala 13:27]
  wire [7:0] _io_same_carry_T_9 = io_same_b_1 & io_same_c_1; // @[WeightedCarrySave.scala 13:42]
  wire [7:0] _io_same_carry_T_10 = _io_same_carry_T_8 | _io_same_carry_T_9; // @[WeightedCarrySave.scala 13:37]
  wire [8:0] _io_same_carry_T_11 = {_io_same_carry_T_10, 1'h0}; // @[WeightedCarrySave.scala 13:48]
  wire [7:0] io_same_carry_1 = _io_same_carry_T_11[7:0]; // @[WeightedCarrySave.scala 13:53]
  wire [7:0] _io_same_T_8 = io_same_s_1 + io_same_carry_1; // @[Delta.scala 44:8]
  wire [7:0] _io_same_T_10 = io_same_a_1 + io_same_b_1; // @[Delta.scala 44:24]
  wire [7:0] _io_same_T_12 = _io_same_T_10 + io_same_c_1; // @[Delta.scala 44:28]
  wire  _io_same_T_13 = _io_same_T_8 == _io_same_T_12; // @[Delta.scala 44:17]
  wire [9:0] _io_same_sum_T_2 = io_a_2 ^ io_b_2; // @[WeightedCarrySave.scala 12:17]
  wire [9:0] io_same_s_2 = _io_same_sum_T_2 ^ io_c_2; // @[WeightedCarrySave.scala 12:21]
  wire [9:0] _io_same_carry_T_12 = io_a_2 & io_b_2; // @[WeightedCarrySave.scala 13:22]
  wire [9:0] _io_same_carry_T_13 = io_a_2 & io_c_2; // @[WeightedCarrySave.scala 13:32]
  wire [9:0] _io_same_carry_T_14 = _io_same_carry_T_12 | _io_same_carry_T_13; // @[WeightedCarrySave.scala 13:27]
  wire [9:0] _io_same_carry_T_15 = io_b_2 & io_c_2; // @[WeightedCarrySave.scala 13:42]
  wire [9:0] _io_same_carry_T_16 = _io_same_carry_T_14 | _io_same_carry_T_15; // @[WeightedCarrySave.scala 13:37]
  wire [10:0] _io_same_carry_T_17 = {_io_same_carry_T_16, 1'h0}; // @[WeightedCarrySave.scala 13:48]
  wire [9:0] io_same_carry_2 = _io_same_carry_T_17[9:0]; // @[WeightedCarrySave.scala 13:53]
  wire [9:0] _io_same_T_15 = io_same_s_2 + io_same_carry_2; // @[Delta.scala 44:8]
  wire [9:0] _io_same_T_17 = io_a_2 + io_b_2; // @[Delta.scala 44:24]
  wire [9:0] _io_same_T_19 = _io_same_T_17 + io_c_2; // @[Delta.scala 44:28]
  wire  _io_same_T_20 = _io_same_T_15 == _io_same_T_19; // @[Delta.scala 44:17]
  assign io_same = _io_same_T_6 & _io_same_T_13 & _io_same_T_20; // @[Delta.scala 45:14]
endmodule
