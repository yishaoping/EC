module ComparatorProof(
  input  [15:0] io_keys,
  input  [17:0] io_terms,
  output        io_ok
);
  wire [7:0] keys_0 = io_keys[7:0]; // @[EmitSort.scala 29:25]
  wire [7:0] keys_1 = io_keys[15:8]; // @[EmitSort.scala 29:38]
  wire [8:0] terms_0_0 = io_terms[8:0]; // @[EmitSort.scala 30:31]
  wire [8:0] terms_1_0 = io_terms[17:9]; // @[EmitSort.scala 30:50]
  wire [8:0] _T_1 = {1'h0,keys_0}; // @[Cat.scala 33:92]
  wire [8:0] _T_4 = {1'h0,keys_1}; // @[Cat.scala 33:92]
  wire  swap = _T_1 > _T_4; // @[AddressBucketReduction.scala 37:48]
  wire [8:0] _T_6 = swap ? _T_4 : _T_1; // @[AddressBucketReduction.scala 38:26]
  wire [8:0] _T_7 = swap ? terms_1_0 : terms_0_0; // @[AddressBucketReduction.scala 39:52]
  wire [8:0] _T_8 = swap ? _T_1 : _T_4; // @[AddressBucketReduction.scala 40:26]
  wire [8:0] _T_9 = swap ? terms_0_0 : terms_1_0; // @[AddressBucketReduction.scala 41:52]
  wire [17:0] before_0 = {1'h0,keys_0,terms_0_0}; // @[Cat.scala 33:92]
  wire [17:0] before_1 = {1'h0,keys_1,terms_1_0}; // @[Cat.scala 33:92]
  wire [17:0] after_0 = {_T_6,_T_7}; // @[Cat.scala 33:92]
  wire [17:0] after_1 = {_T_8,_T_9}; // @[Cat.scala 33:92]
  wire  _io_ok_T_6 = after_0 == before_1 & after_1 == before_0; // @[EmitSort.scala 36:30]
  wire  _io_ok_T_7 = after_0 == before_0 & after_1 == before_1 | _io_ok_T_6; // @[EmitSort.scala 35:57]
  assign io_ok = _T_6 <= _T_8 & _io_ok_T_7; // @[EmitSort.scala 34:33]
endmodule
