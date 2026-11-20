module Group8ReferenceGranule0(
  input  [7:0]  io_keys_0,
  input  [7:0]  io_keys_1,
  input  [7:0]  io_keys_2,
  input  [7:0]  io_keys_3,
  input  [7:0]  io_keys_4,
  input  [7:0]  io_keys_5,
  input  [7:0]  io_keys_6,
  input  [7:0]  io_keys_7,
  input  [3:0]  io_counts_0,
  input  [3:0]  io_counts_1,
  input  [3:0]  io_counts_2,
  input  [3:0]  io_counts_3,
  input  [3:0]  io_counts_4,
  input  [3:0]  io_counts_5,
  input  [3:0]  io_counts_6,
  input  [3:0]  io_counts_7,
  input  [7:0]  io_query,
  output [63:0] io_result
);
  wire  bounded = io_counts_0 <= 4'h8 & io_counts_1 <= 4'h8 & io_counts_2 <= 4'h8 & io_counts_3 <= 4'h8 & io_counts_4
     <= 4'h8 & io_counts_5 <= 4'h8 & io_counts_6 <= 4'h8 & io_counts_7 <= 4'h8; // @[EmitGroup8.scala 33:64]
  wire [63:0] _result_T_1 = {{60'd0}, io_counts_0}; // @[EmitGroup8.scala 35:21]
  wire [63:0] _result_T_2 = io_keys_0 == io_query ? _result_T_1 : 64'h0; // @[EmitGroup8.scala 34:44]
  wire [63:0] _result_T_4 = {{60'd0}, io_counts_1}; // @[EmitGroup8.scala 35:21]
  wire [63:0] _result_T_5 = io_keys_1 == io_query ? _result_T_4 : 64'h0; // @[EmitGroup8.scala 34:44]
  wire [63:0] _result_T_7 = {{60'd0}, io_counts_2}; // @[EmitGroup8.scala 35:21]
  wire [63:0] _result_T_8 = io_keys_2 == io_query ? _result_T_7 : 64'h0; // @[EmitGroup8.scala 34:44]
  wire [63:0] _result_T_10 = {{60'd0}, io_counts_3}; // @[EmitGroup8.scala 35:21]
  wire [63:0] _result_T_11 = io_keys_3 == io_query ? _result_T_10 : 64'h0; // @[EmitGroup8.scala 34:44]
  wire [63:0] _result_T_13 = {{60'd0}, io_counts_4}; // @[EmitGroup8.scala 35:21]
  wire [63:0] _result_T_14 = io_keys_4 == io_query ? _result_T_13 : 64'h0; // @[EmitGroup8.scala 34:44]
  wire [63:0] _result_T_16 = {{60'd0}, io_counts_5}; // @[EmitGroup8.scala 35:21]
  wire [63:0] _result_T_17 = io_keys_5 == io_query ? _result_T_16 : 64'h0; // @[EmitGroup8.scala 34:44]
  wire [63:0] _result_T_19 = {{60'd0}, io_counts_6}; // @[EmitGroup8.scala 35:21]
  wire [63:0] _result_T_20 = io_keys_6 == io_query ? _result_T_19 : 64'h0; // @[EmitGroup8.scala 34:44]
  wire [63:0] _result_T_22 = {{60'd0}, io_counts_7}; // @[EmitGroup8.scala 35:21]
  wire [63:0] _result_T_23 = io_keys_7 == io_query ? _result_T_22 : 64'h0; // @[EmitGroup8.scala 34:44]
  wire [63:0] _result_T_25 = _result_T_2 + _result_T_5; // @[EmitGroup8.scala 35:48]
  wire [63:0] _result_T_27 = _result_T_25 + _result_T_8; // @[EmitGroup8.scala 35:48]
  wire [63:0] _result_T_29 = _result_T_27 + _result_T_11; // @[EmitGroup8.scala 35:48]
  wire [63:0] _result_T_31 = _result_T_29 + _result_T_14; // @[EmitGroup8.scala 35:48]
  wire [63:0] _result_T_33 = _result_T_31 + _result_T_17; // @[EmitGroup8.scala 35:48]
  wire [63:0] _result_T_35 = _result_T_33 + _result_T_20; // @[EmitGroup8.scala 35:48]
  wire [63:0] result = _result_T_35 + _result_T_23; // @[EmitGroup8.scala 35:48]
  assign io_result = bounded ? result : 64'h0; // @[EmitGroup8.scala 36:19]
endmodule
