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
  input         io_valid_8,
  input         io_valid_9,
  input         io_valid_10,
  input         io_valid_11,
  input         io_valid_12,
  input         io_valid_13,
  input         io_valid_14,
  input         io_valid_15,
  input         io_valid_16,
  input         io_valid_17,
  input         io_valid_18,
  input         io_valid_19,
  input         io_valid_20,
  input         io_valid_21,
  input         io_valid_22,
  input         io_valid_23,
  input         io_valid_24,
  input         io_valid_25,
  input         io_valid_26,
  input         io_valid_27,
  input         io_valid_28,
  input         io_valid_29,
  input         io_valid_30,
  input         io_valid_31,
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
  input  [31:0] io_seq_16,
  input  [31:0] io_seq_17,
  input  [31:0] io_seq_18,
  input  [31:0] io_seq_19,
  input  [31:0] io_seq_20,
  input  [31:0] io_seq_21,
  input  [31:0] io_seq_22,
  input  [31:0] io_seq_23,
  input  [31:0] io_seq_24,
  input  [31:0] io_seq_25,
  input  [31:0] io_seq_26,
  input  [31:0] io_seq_27,
  input  [31:0] io_seq_28,
  input  [31:0] io_seq_29,
  input  [31:0] io_seq_30,
  input  [31:0] io_seq_31,
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
  wire [7:0] _expected_T_82 = io_base + 8'h8; // @[Geometry.scala 66:65]
  wire  _expected_T_85 = io_query[7:0] == _expected_T_82 & io_valid_8; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_92 = io_base + 8'h9; // @[Geometry.scala 66:65]
  wire  _expected_T_95 = io_query[7:0] == _expected_T_92 & io_valid_9; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_102 = io_base + 8'ha; // @[Geometry.scala 66:65]
  wire  _expected_T_105 = io_query[7:0] == _expected_T_102 & io_valid_10; // @[Geometry.scala 66:76]
  wire  _expected_T_109 = _expected_T_105 & io_seq_10[31:8] == io_query[31:8]; // @[Geometry.scala 67:17]
  wire [7:0] _expected_T_112 = io_base + 8'hb; // @[Geometry.scala 66:65]
  wire  _expected_T_115 = io_query[7:0] == _expected_T_112 & io_valid_11; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_122 = io_base + 8'hc; // @[Geometry.scala 66:65]
  wire  _expected_T_125 = io_query[7:0] == _expected_T_122 & io_valid_12; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_132 = io_base + 8'hd; // @[Geometry.scala 66:65]
  wire  _expected_T_135 = io_query[7:0] == _expected_T_132 & io_valid_13; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_142 = io_base + 8'he; // @[Geometry.scala 66:65]
  wire  _expected_T_145 = io_query[7:0] == _expected_T_142 & io_valid_14; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_152 = io_base + 8'hf; // @[Geometry.scala 66:65]
  wire  _expected_T_155 = io_query[7:0] == _expected_T_152 & io_valid_15; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_162 = io_base + 8'h10; // @[Geometry.scala 66:65]
  wire  _expected_T_165 = io_query[7:0] == _expected_T_162 & io_valid_16; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_172 = io_base + 8'h11; // @[Geometry.scala 66:65]
  wire  _expected_T_175 = io_query[7:0] == _expected_T_172 & io_valid_17; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_182 = io_base + 8'h12; // @[Geometry.scala 66:65]
  wire  _expected_T_185 = io_query[7:0] == _expected_T_182 & io_valid_18; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_192 = io_base + 8'h13; // @[Geometry.scala 66:65]
  wire  _expected_T_195 = io_query[7:0] == _expected_T_192 & io_valid_19; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_202 = io_base + 8'h14; // @[Geometry.scala 66:65]
  wire  _expected_T_205 = io_query[7:0] == _expected_T_202 & io_valid_20; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_212 = io_base + 8'h15; // @[Geometry.scala 66:65]
  wire  _expected_T_215 = io_query[7:0] == _expected_T_212 & io_valid_21; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_222 = io_base + 8'h16; // @[Geometry.scala 66:65]
  wire  _expected_T_225 = io_query[7:0] == _expected_T_222 & io_valid_22; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_232 = io_base + 8'h17; // @[Geometry.scala 66:65]
  wire  _expected_T_235 = io_query[7:0] == _expected_T_232 & io_valid_23; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_242 = io_base + 8'h18; // @[Geometry.scala 66:65]
  wire  _expected_T_245 = io_query[7:0] == _expected_T_242 & io_valid_24; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_252 = io_base + 8'h19; // @[Geometry.scala 66:65]
  wire  _expected_T_255 = io_query[7:0] == _expected_T_252 & io_valid_25; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_262 = io_base + 8'h1a; // @[Geometry.scala 66:65]
  wire  _expected_T_265 = io_query[7:0] == _expected_T_262 & io_valid_26; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_272 = io_base + 8'h1b; // @[Geometry.scala 66:65]
  wire  _expected_T_275 = io_query[7:0] == _expected_T_272 & io_valid_27; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_282 = io_base + 8'h1c; // @[Geometry.scala 66:65]
  wire  _expected_T_285 = io_query[7:0] == _expected_T_282 & io_valid_28; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_292 = io_base + 8'h1d; // @[Geometry.scala 66:65]
  wire  _expected_T_295 = io_query[7:0] == _expected_T_292 & io_valid_29; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_302 = io_base + 8'h1e; // @[Geometry.scala 66:65]
  wire  _expected_T_305 = io_query[7:0] == _expected_T_302 & io_valid_30; // @[Geometry.scala 66:76]
  wire [7:0] _expected_T_312 = io_base + 8'h1f; // @[Geometry.scala 66:65]
  wire  _expected_T_315 = io_query[7:0] == _expected_T_312 & io_valid_31; // @[Geometry.scala 66:76]
  wire  _expected_T_329 = _expected_T_5 & io_seq_0[31:8] == io_query[31:8] | _expected_T_15 & io_seq_1[31:8] == io_query
    [31:8] | _expected_T_25 & io_seq_2[31:8] == io_query[31:8] | _expected_T_35 & io_seq_3[31:8] == io_query[31:8] |
    _expected_T_45 & io_seq_4[31:8] == io_query[31:8] | _expected_T_55 & io_seq_5[31:8] == io_query[31:8] |
    _expected_T_65 & io_seq_6[31:8] == io_query[31:8] | _expected_T_75 & io_seq_7[31:8] == io_query[31:8] |
    _expected_T_85 & io_seq_8[31:8] == io_query[31:8] | _expected_T_95 & io_seq_9[31:8] == io_query[31:8] |
    _expected_T_109; // @[Geometry.scala 67:63]
  wire  _expected_T_339 = _expected_T_329 | _expected_T_115 & io_seq_11[31:8] == io_query[31:8] | _expected_T_125 &
    io_seq_12[31:8] == io_query[31:8] | _expected_T_135 & io_seq_13[31:8] == io_query[31:8] | _expected_T_145 &
    io_seq_14[31:8] == io_query[31:8] | _expected_T_155 & io_seq_15[31:8] == io_query[31:8] | _expected_T_165 &
    io_seq_16[31:8] == io_query[31:8] | _expected_T_175 & io_seq_17[31:8] == io_query[31:8] | _expected_T_185 &
    io_seq_18[31:8] == io_query[31:8] | _expected_T_195 & io_seq_19[31:8] == io_query[31:8] | _expected_T_205 &
    io_seq_20[31:8] == io_query[31:8]; // @[Geometry.scala 67:63]
  wire  _expected_T_349 = _expected_T_339 | _expected_T_215 & io_seq_21[31:8] == io_query[31:8] | _expected_T_225 &
    io_seq_22[31:8] == io_query[31:8] | _expected_T_235 & io_seq_23[31:8] == io_query[31:8] | _expected_T_245 &
    io_seq_24[31:8] == io_query[31:8] | _expected_T_255 & io_seq_25[31:8] == io_query[31:8] | _expected_T_265 &
    io_seq_26[31:8] == io_query[31:8] | _expected_T_275 & io_seq_27[31:8] == io_query[31:8] | _expected_T_285 &
    io_seq_28[31:8] == io_query[31:8] | _expected_T_295 & io_seq_29[31:8] == io_query[31:8] | _expected_T_305 &
    io_seq_30[31:8] == io_query[31:8]; // @[Geometry.scala 67:63]
  wire  expected = _expected_T_349 | _expected_T_315 & io_seq_31[31:8] == io_query[31:8]; // @[Geometry.scala 67:63]
  wire [7:0] io_same_offset = io_query[7:0] - io_base; // @[BankTagRead.scala 16:31]
  wire [4:0] io_same_lane = io_same_offset[4:0]; // @[BankTagRead.scala 17:22]
  wire  _GEN_1 = 5'h1 == io_same_lane ? io_valid_1 : io_valid_0; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_2 = 5'h2 == io_same_lane ? io_valid_2 : _GEN_1; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_3 = 5'h3 == io_same_lane ? io_valid_3 : _GEN_2; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_4 = 5'h4 == io_same_lane ? io_valid_4 : _GEN_3; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_5 = 5'h5 == io_same_lane ? io_valid_5 : _GEN_4; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_6 = 5'h6 == io_same_lane ? io_valid_6 : _GEN_5; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_7 = 5'h7 == io_same_lane ? io_valid_7 : _GEN_6; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_8 = 5'h8 == io_same_lane ? io_valid_8 : _GEN_7; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_9 = 5'h9 == io_same_lane ? io_valid_9 : _GEN_8; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_10 = 5'ha == io_same_lane ? io_valid_10 : _GEN_9; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_11 = 5'hb == io_same_lane ? io_valid_11 : _GEN_10; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_12 = 5'hc == io_same_lane ? io_valid_12 : _GEN_11; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_13 = 5'hd == io_same_lane ? io_valid_13 : _GEN_12; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_14 = 5'he == io_same_lane ? io_valid_14 : _GEN_13; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_15 = 5'hf == io_same_lane ? io_valid_15 : _GEN_14; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_16 = 5'h10 == io_same_lane ? io_valid_16 : _GEN_15; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_17 = 5'h11 == io_same_lane ? io_valid_17 : _GEN_16; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_18 = 5'h12 == io_same_lane ? io_valid_18 : _GEN_17; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_19 = 5'h13 == io_same_lane ? io_valid_19 : _GEN_18; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_20 = 5'h14 == io_same_lane ? io_valid_20 : _GEN_19; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_21 = 5'h15 == io_same_lane ? io_valid_21 : _GEN_20; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_22 = 5'h16 == io_same_lane ? io_valid_22 : _GEN_21; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_23 = 5'h17 == io_same_lane ? io_valid_23 : _GEN_22; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_24 = 5'h18 == io_same_lane ? io_valid_24 : _GEN_23; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_25 = 5'h19 == io_same_lane ? io_valid_25 : _GEN_24; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_26 = 5'h1a == io_same_lane ? io_valid_26 : _GEN_25; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_27 = 5'h1b == io_same_lane ? io_valid_27 : _GEN_26; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_28 = 5'h1c == io_same_lane ? io_valid_28 : _GEN_27; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_29 = 5'h1d == io_same_lane ? io_valid_29 : _GEN_28; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_30 = 5'h1e == io_same_lane ? io_valid_30 : _GEN_29; // @[BankTagRead.scala 20:{33,33}]
  wire  _GEN_31 = 5'h1f == io_same_lane ? io_valid_31 : _GEN_30; // @[BankTagRead.scala 20:{33,33}]
  wire [31:0] _GEN_33 = 5'h1 == io_same_lane ? io_seq_1 : io_seq_0; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_34 = 5'h2 == io_same_lane ? io_seq_2 : _GEN_33; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_35 = 5'h3 == io_same_lane ? io_seq_3 : _GEN_34; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_36 = 5'h4 == io_same_lane ? io_seq_4 : _GEN_35; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_37 = 5'h5 == io_same_lane ? io_seq_5 : _GEN_36; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_38 = 5'h6 == io_same_lane ? io_seq_6 : _GEN_37; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_39 = 5'h7 == io_same_lane ? io_seq_7 : _GEN_38; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_40 = 5'h8 == io_same_lane ? io_seq_8 : _GEN_39; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_41 = 5'h9 == io_same_lane ? io_seq_9 : _GEN_40; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_42 = 5'ha == io_same_lane ? io_seq_10 : _GEN_41; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_43 = 5'hb == io_same_lane ? io_seq_11 : _GEN_42; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_44 = 5'hc == io_same_lane ? io_seq_12 : _GEN_43; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_45 = 5'hd == io_same_lane ? io_seq_13 : _GEN_44; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_46 = 5'he == io_same_lane ? io_seq_14 : _GEN_45; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_47 = 5'hf == io_same_lane ? io_seq_15 : _GEN_46; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_48 = 5'h10 == io_same_lane ? io_seq_16 : _GEN_47; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_49 = 5'h11 == io_same_lane ? io_seq_17 : _GEN_48; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_50 = 5'h12 == io_same_lane ? io_seq_18 : _GEN_49; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_51 = 5'h13 == io_same_lane ? io_seq_19 : _GEN_50; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_52 = 5'h14 == io_same_lane ? io_seq_20 : _GEN_51; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_53 = 5'h15 == io_same_lane ? io_seq_21 : _GEN_52; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_54 = 5'h16 == io_same_lane ? io_seq_22 : _GEN_53; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_55 = 5'h17 == io_same_lane ? io_seq_23 : _GEN_54; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_56 = 5'h18 == io_same_lane ? io_seq_24 : _GEN_55; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_57 = 5'h19 == io_same_lane ? io_seq_25 : _GEN_56; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_58 = 5'h1a == io_same_lane ? io_seq_26 : _GEN_57; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_59 = 5'h1b == io_same_lane ? io_seq_27 : _GEN_58; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_60 = 5'h1c == io_same_lane ? io_seq_28 : _GEN_59; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_61 = 5'h1d == io_same_lane ? io_seq_29 : _GEN_60; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_62 = 5'h1e == io_same_lane ? io_seq_30 : _GEN_61; // @[BankTagRead.scala 20:{64,64}]
  wire [31:0] _GEN_63 = 5'h1f == io_same_lane ? io_seq_31 : _GEN_62; // @[BankTagRead.scala 20:{64,64}]
  wire  _io_same_T_6 = io_same_offset[7:5] == 3'h0 & _GEN_31 & _GEN_63[31:8] == io_query[31:8]; // @[BankTagRead.scala 20:50]
  assign io_same = expected == _io_same_T_6; // @[Geometry.scala 68:23]
endmodule
