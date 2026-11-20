module QualifiedDeltaProof(
  input  [63:0]  io_packetSeq,
  input  [63:0]  io_bucketSeq_0,
  input  [63:0]  io_bucketSeq_1,
  input  [63:0]  io_bucketSeq_2,
  input  [63:0]  io_bucketSeq_3,
  input  [63:0]  io_bucketSeq_4,
  input  [63:0]  io_bucketSeq_5,
  input  [63:0]  io_bucketSeq_6,
  input  [63:0]  io_bucketSeq_7,
  input  [63:0]  io_bucketSeq_8,
  input  [63:0]  io_bucketSeq_9,
  input  [63:0]  io_bucketSeq_10,
  input  [63:0]  io_bucketSeq_11,
  input  [63:0]  io_bucketSeq_12,
  input  [63:0]  io_bucketSeq_13,
  input  [63:0]  io_bucketSeq_14,
  input  [63:0]  io_bucketSeq_15,
  input  [63:0]  io_bucketSeq_16,
  input  [63:0]  io_bucketSeq_17,
  input  [63:0]  io_bucketSeq_18,
  input  [63:0]  io_bucketSeq_19,
  input  [63:0]  io_bucketSeq_20,
  input  [63:0]  io_bucketSeq_21,
  input  [63:0]  io_bucketSeq_22,
  input  [63:0]  io_bucketSeq_23,
  input  [63:0]  io_bucketSeq_24,
  input  [63:0]  io_bucketSeq_25,
  input  [63:0]  io_bucketSeq_26,
  input  [63:0]  io_bucketSeq_27,
  input  [63:0]  io_bucketSeq_28,
  input  [63:0]  io_bucketSeq_29,
  input  [63:0]  io_bucketSeq_30,
  input  [63:0]  io_bucketSeq_31,
  input  [63:0]  io_bucketSeq_32,
  input  [63:0]  io_bucketSeq_33,
  input  [63:0]  io_bucketSeq_34,
  input  [63:0]  io_bucketSeq_35,
  input  [63:0]  io_bucketSeq_36,
  input  [63:0]  io_bucketSeq_37,
  input  [63:0]  io_bucketSeq_38,
  input  [63:0]  io_bucketSeq_39,
  input  [63:0]  io_bucketSeq_40,
  input  [63:0]  io_bucketSeq_41,
  input  [63:0]  io_bucketSeq_42,
  input  [63:0]  io_bucketSeq_43,
  input  [63:0]  io_bucketSeq_44,
  input  [63:0]  io_bucketSeq_45,
  input  [63:0]  io_bucketSeq_46,
  input  [63:0]  io_bucketSeq_47,
  input  [63:0]  io_bucketSeq_48,
  input  [63:0]  io_bucketSeq_49,
  input  [63:0]  io_bucketSeq_50,
  input  [63:0]  io_bucketSeq_51,
  input  [63:0]  io_bucketSeq_52,
  input  [63:0]  io_bucketSeq_53,
  input  [63:0]  io_bucketSeq_54,
  input  [63:0]  io_bucketSeq_55,
  input  [63:0]  io_bucketSeq_56,
  input  [63:0]  io_bucketSeq_57,
  input  [63:0]  io_bucketSeq_58,
  input  [63:0]  io_bucketSeq_59,
  input  [63:0]  io_bucketSeq_60,
  input  [63:0]  io_bucketSeq_61,
  input  [63:0]  io_bucketSeq_62,
  input  [63:0]  io_bucketSeq_63,
  input  [63:0]  io_bucketSeq_64,
  input  [63:0]  io_bucketSeq_65,
  input  [63:0]  io_bucketSeq_66,
  input  [63:0]  io_bucketSeq_67,
  input  [63:0]  io_bucketSeq_68,
  input  [63:0]  io_bucketSeq_69,
  input  [63:0]  io_bucketSeq_70,
  input  [63:0]  io_bucketSeq_71,
  input  [63:0]  io_bucketSeq_72,
  input  [63:0]  io_bucketSeq_73,
  input  [63:0]  io_bucketSeq_74,
  input  [63:0]  io_bucketSeq_75,
  input  [63:0]  io_bucketSeq_76,
  input  [63:0]  io_bucketSeq_77,
  input  [63:0]  io_bucketSeq_78,
  input  [63:0]  io_bucketSeq_79,
  input  [63:0]  io_bucketSeq_80,
  input  [63:0]  io_bucketSeq_81,
  input  [63:0]  io_bucketSeq_82,
  input  [63:0]  io_bucketSeq_83,
  input  [63:0]  io_bucketSeq_84,
  input  [63:0]  io_bucketSeq_85,
  input  [63:0]  io_bucketSeq_86,
  input  [63:0]  io_bucketSeq_87,
  input  [63:0]  io_bucketSeq_88,
  input  [63:0]  io_bucketSeq_89,
  input  [63:0]  io_bucketSeq_90,
  input  [63:0]  io_bucketSeq_91,
  input  [63:0]  io_bucketSeq_92,
  input  [63:0]  io_bucketSeq_93,
  input  [63:0]  io_bucketSeq_94,
  input  [63:0]  io_bucketSeq_95,
  input  [63:0]  io_bucketSeq_96,
  input  [63:0]  io_bucketSeq_97,
  input  [63:0]  io_bucketSeq_98,
  input  [63:0]  io_bucketSeq_99,
  input  [63:0]  io_bucketSeq_100,
  input  [63:0]  io_bucketSeq_101,
  input  [63:0]  io_bucketSeq_102,
  input  [63:0]  io_bucketSeq_103,
  input  [63:0]  io_bucketSeq_104,
  input  [63:0]  io_bucketSeq_105,
  input  [63:0]  io_bucketSeq_106,
  input  [63:0]  io_bucketSeq_107,
  input  [63:0]  io_bucketSeq_108,
  input  [63:0]  io_bucketSeq_109,
  input  [63:0]  io_bucketSeq_110,
  input  [63:0]  io_bucketSeq_111,
  input  [63:0]  io_bucketSeq_112,
  input  [63:0]  io_bucketSeq_113,
  input  [63:0]  io_bucketSeq_114,
  input  [63:0]  io_bucketSeq_115,
  input  [63:0]  io_bucketSeq_116,
  input  [63:0]  io_bucketSeq_117,
  input  [63:0]  io_bucketSeq_118,
  input  [63:0]  io_bucketSeq_119,
  input  [63:0]  io_bucketSeq_120,
  input  [63:0]  io_bucketSeq_121,
  input  [63:0]  io_bucketSeq_122,
  input  [63:0]  io_bucketSeq_123,
  input  [63:0]  io_bucketSeq_124,
  input  [63:0]  io_bucketSeq_125,
  input  [63:0]  io_bucketSeq_126,
  input  [63:0]  io_bucketSeq_127,
  input  [63:0]  io_bucketSeq_128,
  input  [63:0]  io_bucketSeq_129,
  input  [63:0]  io_bucketSeq_130,
  input  [63:0]  io_bucketSeq_131,
  input  [63:0]  io_bucketSeq_132,
  input  [63:0]  io_bucketSeq_133,
  input  [63:0]  io_bucketSeq_134,
  input  [63:0]  io_bucketSeq_135,
  input  [63:0]  io_bucketSeq_136,
  input  [63:0]  io_bucketSeq_137,
  input  [63:0]  io_bucketSeq_138,
  input  [63:0]  io_bucketSeq_139,
  input  [63:0]  io_bucketSeq_140,
  input  [63:0]  io_bucketSeq_141,
  input  [63:0]  io_bucketSeq_142,
  input  [63:0]  io_bucketSeq_143,
  input  [63:0]  io_bucketSeq_144,
  input  [63:0]  io_bucketSeq_145,
  input  [63:0]  io_bucketSeq_146,
  input  [63:0]  io_bucketSeq_147,
  input  [63:0]  io_bucketSeq_148,
  input  [63:0]  io_bucketSeq_149,
  input  [63:0]  io_bucketSeq_150,
  input  [63:0]  io_bucketSeq_151,
  input  [63:0]  io_bucketSeq_152,
  input  [63:0]  io_bucketSeq_153,
  input  [63:0]  io_bucketSeq_154,
  input  [63:0]  io_bucketSeq_155,
  input  [63:0]  io_bucketSeq_156,
  input  [63:0]  io_bucketSeq_157,
  input  [63:0]  io_bucketSeq_158,
  input  [63:0]  io_bucketSeq_159,
  input  [63:0]  io_bucketSeq_160,
  input  [63:0]  io_bucketSeq_161,
  input  [63:0]  io_bucketSeq_162,
  input  [63:0]  io_bucketSeq_163,
  input  [63:0]  io_bucketSeq_164,
  input  [63:0]  io_bucketSeq_165,
  input  [63:0]  io_bucketSeq_166,
  input  [63:0]  io_bucketSeq_167,
  input  [63:0]  io_bucketSeq_168,
  input  [63:0]  io_bucketSeq_169,
  input  [63:0]  io_bucketSeq_170,
  input  [63:0]  io_bucketSeq_171,
  input  [63:0]  io_bucketSeq_172,
  input  [63:0]  io_bucketSeq_173,
  input  [63:0]  io_bucketSeq_174,
  input  [63:0]  io_bucketSeq_175,
  input  [63:0]  io_bucketSeq_176,
  input  [63:0]  io_bucketSeq_177,
  input  [63:0]  io_bucketSeq_178,
  input  [63:0]  io_bucketSeq_179,
  input  [63:0]  io_bucketSeq_180,
  input  [63:0]  io_bucketSeq_181,
  input  [63:0]  io_bucketSeq_182,
  input  [63:0]  io_bucketSeq_183,
  input  [63:0]  io_bucketSeq_184,
  input  [63:0]  io_bucketSeq_185,
  input  [63:0]  io_bucketSeq_186,
  input  [63:0]  io_bucketSeq_187,
  input  [63:0]  io_bucketSeq_188,
  input  [63:0]  io_bucketSeq_189,
  input  [63:0]  io_bucketSeq_190,
  input  [63:0]  io_bucketSeq_191,
  input  [63:0]  io_bucketSeq_192,
  input  [63:0]  io_bucketSeq_193,
  input  [63:0]  io_bucketSeq_194,
  input  [63:0]  io_bucketSeq_195,
  input  [63:0]  io_bucketSeq_196,
  input  [63:0]  io_bucketSeq_197,
  input  [63:0]  io_bucketSeq_198,
  input  [63:0]  io_bucketSeq_199,
  input  [63:0]  io_bucketSeq_200,
  input  [63:0]  io_bucketSeq_201,
  input  [63:0]  io_bucketSeq_202,
  input  [63:0]  io_bucketSeq_203,
  input  [63:0]  io_bucketSeq_204,
  input  [63:0]  io_bucketSeq_205,
  input  [63:0]  io_bucketSeq_206,
  input  [63:0]  io_bucketSeq_207,
  input  [63:0]  io_bucketSeq_208,
  input  [63:0]  io_bucketSeq_209,
  input  [63:0]  io_bucketSeq_210,
  input  [63:0]  io_bucketSeq_211,
  input  [63:0]  io_bucketSeq_212,
  input  [63:0]  io_bucketSeq_213,
  input  [63:0]  io_bucketSeq_214,
  input  [63:0]  io_bucketSeq_215,
  input  [63:0]  io_bucketSeq_216,
  input  [63:0]  io_bucketSeq_217,
  input  [63:0]  io_bucketSeq_218,
  input  [63:0]  io_bucketSeq_219,
  input  [63:0]  io_bucketSeq_220,
  input  [63:0]  io_bucketSeq_221,
  input  [63:0]  io_bucketSeq_222,
  input  [63:0]  io_bucketSeq_223,
  input  [63:0]  io_bucketSeq_224,
  input  [63:0]  io_bucketSeq_225,
  input  [63:0]  io_bucketSeq_226,
  input  [63:0]  io_bucketSeq_227,
  input  [63:0]  io_bucketSeq_228,
  input  [63:0]  io_bucketSeq_229,
  input  [63:0]  io_bucketSeq_230,
  input  [63:0]  io_bucketSeq_231,
  input  [63:0]  io_bucketSeq_232,
  input  [63:0]  io_bucketSeq_233,
  input  [63:0]  io_bucketSeq_234,
  input  [63:0]  io_bucketSeq_235,
  input  [63:0]  io_bucketSeq_236,
  input  [63:0]  io_bucketSeq_237,
  input  [63:0]  io_bucketSeq_238,
  input  [63:0]  io_bucketSeq_239,
  input  [63:0]  io_bucketSeq_240,
  input  [63:0]  io_bucketSeq_241,
  input  [63:0]  io_bucketSeq_242,
  input  [63:0]  io_bucketSeq_243,
  input  [63:0]  io_bucketSeq_244,
  input  [63:0]  io_bucketSeq_245,
  input  [63:0]  io_bucketSeq_246,
  input  [63:0]  io_bucketSeq_247,
  input  [63:0]  io_bucketSeq_248,
  input  [63:0]  io_bucketSeq_249,
  input  [63:0]  io_bucketSeq_250,
  input  [63:0]  io_bucketSeq_251,
  input  [63:0]  io_bucketSeq_252,
  input  [63:0]  io_bucketSeq_253,
  input  [63:0]  io_bucketSeq_254,
  input  [63:0]  io_bucketSeq_255,
  input  [255:0] io_bucketValid,
  input          io_hit,
  input  [63:0]  io_count,
  output         io_legalDeltaImpliesValid
);
  wire [7:0] idx = io_packetSeq[7:0]; // @[EmitDecode.scala 80:25]
  wire [255:0] _matches_T = io_bucketValid >> idx; // @[EmitDecode.scala 81:31]
  wire [63:0] _GEN_1 = 8'h1 == idx ? io_bucketSeq_1 : io_bucketSeq_0; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_2 = 8'h2 == idx ? io_bucketSeq_2 : _GEN_1; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_3 = 8'h3 == idx ? io_bucketSeq_3 : _GEN_2; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_4 = 8'h4 == idx ? io_bucketSeq_4 : _GEN_3; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_5 = 8'h5 == idx ? io_bucketSeq_5 : _GEN_4; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_6 = 8'h6 == idx ? io_bucketSeq_6 : _GEN_5; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_7 = 8'h7 == idx ? io_bucketSeq_7 : _GEN_6; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_8 = 8'h8 == idx ? io_bucketSeq_8 : _GEN_7; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_9 = 8'h9 == idx ? io_bucketSeq_9 : _GEN_8; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_10 = 8'ha == idx ? io_bucketSeq_10 : _GEN_9; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_11 = 8'hb == idx ? io_bucketSeq_11 : _GEN_10; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_12 = 8'hc == idx ? io_bucketSeq_12 : _GEN_11; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_13 = 8'hd == idx ? io_bucketSeq_13 : _GEN_12; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_14 = 8'he == idx ? io_bucketSeq_14 : _GEN_13; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_15 = 8'hf == idx ? io_bucketSeq_15 : _GEN_14; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_16 = 8'h10 == idx ? io_bucketSeq_16 : _GEN_15; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_17 = 8'h11 == idx ? io_bucketSeq_17 : _GEN_16; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_18 = 8'h12 == idx ? io_bucketSeq_18 : _GEN_17; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_19 = 8'h13 == idx ? io_bucketSeq_19 : _GEN_18; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_20 = 8'h14 == idx ? io_bucketSeq_20 : _GEN_19; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_21 = 8'h15 == idx ? io_bucketSeq_21 : _GEN_20; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_22 = 8'h16 == idx ? io_bucketSeq_22 : _GEN_21; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_23 = 8'h17 == idx ? io_bucketSeq_23 : _GEN_22; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_24 = 8'h18 == idx ? io_bucketSeq_24 : _GEN_23; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_25 = 8'h19 == idx ? io_bucketSeq_25 : _GEN_24; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_26 = 8'h1a == idx ? io_bucketSeq_26 : _GEN_25; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_27 = 8'h1b == idx ? io_bucketSeq_27 : _GEN_26; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_28 = 8'h1c == idx ? io_bucketSeq_28 : _GEN_27; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_29 = 8'h1d == idx ? io_bucketSeq_29 : _GEN_28; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_30 = 8'h1e == idx ? io_bucketSeq_30 : _GEN_29; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_31 = 8'h1f == idx ? io_bucketSeq_31 : _GEN_30; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_32 = 8'h20 == idx ? io_bucketSeq_32 : _GEN_31; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_33 = 8'h21 == idx ? io_bucketSeq_33 : _GEN_32; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_34 = 8'h22 == idx ? io_bucketSeq_34 : _GEN_33; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_35 = 8'h23 == idx ? io_bucketSeq_35 : _GEN_34; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_36 = 8'h24 == idx ? io_bucketSeq_36 : _GEN_35; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_37 = 8'h25 == idx ? io_bucketSeq_37 : _GEN_36; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_38 = 8'h26 == idx ? io_bucketSeq_38 : _GEN_37; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_39 = 8'h27 == idx ? io_bucketSeq_39 : _GEN_38; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_40 = 8'h28 == idx ? io_bucketSeq_40 : _GEN_39; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_41 = 8'h29 == idx ? io_bucketSeq_41 : _GEN_40; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_42 = 8'h2a == idx ? io_bucketSeq_42 : _GEN_41; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_43 = 8'h2b == idx ? io_bucketSeq_43 : _GEN_42; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_44 = 8'h2c == idx ? io_bucketSeq_44 : _GEN_43; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_45 = 8'h2d == idx ? io_bucketSeq_45 : _GEN_44; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_46 = 8'h2e == idx ? io_bucketSeq_46 : _GEN_45; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_47 = 8'h2f == idx ? io_bucketSeq_47 : _GEN_46; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_48 = 8'h30 == idx ? io_bucketSeq_48 : _GEN_47; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_49 = 8'h31 == idx ? io_bucketSeq_49 : _GEN_48; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_50 = 8'h32 == idx ? io_bucketSeq_50 : _GEN_49; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_51 = 8'h33 == idx ? io_bucketSeq_51 : _GEN_50; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_52 = 8'h34 == idx ? io_bucketSeq_52 : _GEN_51; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_53 = 8'h35 == idx ? io_bucketSeq_53 : _GEN_52; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_54 = 8'h36 == idx ? io_bucketSeq_54 : _GEN_53; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_55 = 8'h37 == idx ? io_bucketSeq_55 : _GEN_54; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_56 = 8'h38 == idx ? io_bucketSeq_56 : _GEN_55; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_57 = 8'h39 == idx ? io_bucketSeq_57 : _GEN_56; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_58 = 8'h3a == idx ? io_bucketSeq_58 : _GEN_57; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_59 = 8'h3b == idx ? io_bucketSeq_59 : _GEN_58; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_60 = 8'h3c == idx ? io_bucketSeq_60 : _GEN_59; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_61 = 8'h3d == idx ? io_bucketSeq_61 : _GEN_60; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_62 = 8'h3e == idx ? io_bucketSeq_62 : _GEN_61; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_63 = 8'h3f == idx ? io_bucketSeq_63 : _GEN_62; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_64 = 8'h40 == idx ? io_bucketSeq_64 : _GEN_63; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_65 = 8'h41 == idx ? io_bucketSeq_65 : _GEN_64; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_66 = 8'h42 == idx ? io_bucketSeq_66 : _GEN_65; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_67 = 8'h43 == idx ? io_bucketSeq_67 : _GEN_66; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_68 = 8'h44 == idx ? io_bucketSeq_68 : _GEN_67; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_69 = 8'h45 == idx ? io_bucketSeq_69 : _GEN_68; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_70 = 8'h46 == idx ? io_bucketSeq_70 : _GEN_69; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_71 = 8'h47 == idx ? io_bucketSeq_71 : _GEN_70; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_72 = 8'h48 == idx ? io_bucketSeq_72 : _GEN_71; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_73 = 8'h49 == idx ? io_bucketSeq_73 : _GEN_72; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_74 = 8'h4a == idx ? io_bucketSeq_74 : _GEN_73; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_75 = 8'h4b == idx ? io_bucketSeq_75 : _GEN_74; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_76 = 8'h4c == idx ? io_bucketSeq_76 : _GEN_75; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_77 = 8'h4d == idx ? io_bucketSeq_77 : _GEN_76; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_78 = 8'h4e == idx ? io_bucketSeq_78 : _GEN_77; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_79 = 8'h4f == idx ? io_bucketSeq_79 : _GEN_78; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_80 = 8'h50 == idx ? io_bucketSeq_80 : _GEN_79; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_81 = 8'h51 == idx ? io_bucketSeq_81 : _GEN_80; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_82 = 8'h52 == idx ? io_bucketSeq_82 : _GEN_81; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_83 = 8'h53 == idx ? io_bucketSeq_83 : _GEN_82; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_84 = 8'h54 == idx ? io_bucketSeq_84 : _GEN_83; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_85 = 8'h55 == idx ? io_bucketSeq_85 : _GEN_84; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_86 = 8'h56 == idx ? io_bucketSeq_86 : _GEN_85; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_87 = 8'h57 == idx ? io_bucketSeq_87 : _GEN_86; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_88 = 8'h58 == idx ? io_bucketSeq_88 : _GEN_87; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_89 = 8'h59 == idx ? io_bucketSeq_89 : _GEN_88; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_90 = 8'h5a == idx ? io_bucketSeq_90 : _GEN_89; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_91 = 8'h5b == idx ? io_bucketSeq_91 : _GEN_90; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_92 = 8'h5c == idx ? io_bucketSeq_92 : _GEN_91; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_93 = 8'h5d == idx ? io_bucketSeq_93 : _GEN_92; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_94 = 8'h5e == idx ? io_bucketSeq_94 : _GEN_93; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_95 = 8'h5f == idx ? io_bucketSeq_95 : _GEN_94; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_96 = 8'h60 == idx ? io_bucketSeq_96 : _GEN_95; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_97 = 8'h61 == idx ? io_bucketSeq_97 : _GEN_96; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_98 = 8'h62 == idx ? io_bucketSeq_98 : _GEN_97; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_99 = 8'h63 == idx ? io_bucketSeq_99 : _GEN_98; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_100 = 8'h64 == idx ? io_bucketSeq_100 : _GEN_99; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_101 = 8'h65 == idx ? io_bucketSeq_101 : _GEN_100; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_102 = 8'h66 == idx ? io_bucketSeq_102 : _GEN_101; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_103 = 8'h67 == idx ? io_bucketSeq_103 : _GEN_102; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_104 = 8'h68 == idx ? io_bucketSeq_104 : _GEN_103; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_105 = 8'h69 == idx ? io_bucketSeq_105 : _GEN_104; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_106 = 8'h6a == idx ? io_bucketSeq_106 : _GEN_105; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_107 = 8'h6b == idx ? io_bucketSeq_107 : _GEN_106; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_108 = 8'h6c == idx ? io_bucketSeq_108 : _GEN_107; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_109 = 8'h6d == idx ? io_bucketSeq_109 : _GEN_108; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_110 = 8'h6e == idx ? io_bucketSeq_110 : _GEN_109; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_111 = 8'h6f == idx ? io_bucketSeq_111 : _GEN_110; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_112 = 8'h70 == idx ? io_bucketSeq_112 : _GEN_111; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_113 = 8'h71 == idx ? io_bucketSeq_113 : _GEN_112; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_114 = 8'h72 == idx ? io_bucketSeq_114 : _GEN_113; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_115 = 8'h73 == idx ? io_bucketSeq_115 : _GEN_114; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_116 = 8'h74 == idx ? io_bucketSeq_116 : _GEN_115; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_117 = 8'h75 == idx ? io_bucketSeq_117 : _GEN_116; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_118 = 8'h76 == idx ? io_bucketSeq_118 : _GEN_117; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_119 = 8'h77 == idx ? io_bucketSeq_119 : _GEN_118; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_120 = 8'h78 == idx ? io_bucketSeq_120 : _GEN_119; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_121 = 8'h79 == idx ? io_bucketSeq_121 : _GEN_120; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_122 = 8'h7a == idx ? io_bucketSeq_122 : _GEN_121; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_123 = 8'h7b == idx ? io_bucketSeq_123 : _GEN_122; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_124 = 8'h7c == idx ? io_bucketSeq_124 : _GEN_123; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_125 = 8'h7d == idx ? io_bucketSeq_125 : _GEN_124; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_126 = 8'h7e == idx ? io_bucketSeq_126 : _GEN_125; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_127 = 8'h7f == idx ? io_bucketSeq_127 : _GEN_126; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_128 = 8'h80 == idx ? io_bucketSeq_128 : _GEN_127; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_129 = 8'h81 == idx ? io_bucketSeq_129 : _GEN_128; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_130 = 8'h82 == idx ? io_bucketSeq_130 : _GEN_129; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_131 = 8'h83 == idx ? io_bucketSeq_131 : _GEN_130; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_132 = 8'h84 == idx ? io_bucketSeq_132 : _GEN_131; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_133 = 8'h85 == idx ? io_bucketSeq_133 : _GEN_132; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_134 = 8'h86 == idx ? io_bucketSeq_134 : _GEN_133; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_135 = 8'h87 == idx ? io_bucketSeq_135 : _GEN_134; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_136 = 8'h88 == idx ? io_bucketSeq_136 : _GEN_135; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_137 = 8'h89 == idx ? io_bucketSeq_137 : _GEN_136; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_138 = 8'h8a == idx ? io_bucketSeq_138 : _GEN_137; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_139 = 8'h8b == idx ? io_bucketSeq_139 : _GEN_138; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_140 = 8'h8c == idx ? io_bucketSeq_140 : _GEN_139; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_141 = 8'h8d == idx ? io_bucketSeq_141 : _GEN_140; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_142 = 8'h8e == idx ? io_bucketSeq_142 : _GEN_141; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_143 = 8'h8f == idx ? io_bucketSeq_143 : _GEN_142; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_144 = 8'h90 == idx ? io_bucketSeq_144 : _GEN_143; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_145 = 8'h91 == idx ? io_bucketSeq_145 : _GEN_144; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_146 = 8'h92 == idx ? io_bucketSeq_146 : _GEN_145; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_147 = 8'h93 == idx ? io_bucketSeq_147 : _GEN_146; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_148 = 8'h94 == idx ? io_bucketSeq_148 : _GEN_147; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_149 = 8'h95 == idx ? io_bucketSeq_149 : _GEN_148; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_150 = 8'h96 == idx ? io_bucketSeq_150 : _GEN_149; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_151 = 8'h97 == idx ? io_bucketSeq_151 : _GEN_150; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_152 = 8'h98 == idx ? io_bucketSeq_152 : _GEN_151; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_153 = 8'h99 == idx ? io_bucketSeq_153 : _GEN_152; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_154 = 8'h9a == idx ? io_bucketSeq_154 : _GEN_153; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_155 = 8'h9b == idx ? io_bucketSeq_155 : _GEN_154; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_156 = 8'h9c == idx ? io_bucketSeq_156 : _GEN_155; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_157 = 8'h9d == idx ? io_bucketSeq_157 : _GEN_156; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_158 = 8'h9e == idx ? io_bucketSeq_158 : _GEN_157; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_159 = 8'h9f == idx ? io_bucketSeq_159 : _GEN_158; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_160 = 8'ha0 == idx ? io_bucketSeq_160 : _GEN_159; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_161 = 8'ha1 == idx ? io_bucketSeq_161 : _GEN_160; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_162 = 8'ha2 == idx ? io_bucketSeq_162 : _GEN_161; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_163 = 8'ha3 == idx ? io_bucketSeq_163 : _GEN_162; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_164 = 8'ha4 == idx ? io_bucketSeq_164 : _GEN_163; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_165 = 8'ha5 == idx ? io_bucketSeq_165 : _GEN_164; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_166 = 8'ha6 == idx ? io_bucketSeq_166 : _GEN_165; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_167 = 8'ha7 == idx ? io_bucketSeq_167 : _GEN_166; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_168 = 8'ha8 == idx ? io_bucketSeq_168 : _GEN_167; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_169 = 8'ha9 == idx ? io_bucketSeq_169 : _GEN_168; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_170 = 8'haa == idx ? io_bucketSeq_170 : _GEN_169; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_171 = 8'hab == idx ? io_bucketSeq_171 : _GEN_170; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_172 = 8'hac == idx ? io_bucketSeq_172 : _GEN_171; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_173 = 8'had == idx ? io_bucketSeq_173 : _GEN_172; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_174 = 8'hae == idx ? io_bucketSeq_174 : _GEN_173; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_175 = 8'haf == idx ? io_bucketSeq_175 : _GEN_174; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_176 = 8'hb0 == idx ? io_bucketSeq_176 : _GEN_175; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_177 = 8'hb1 == idx ? io_bucketSeq_177 : _GEN_176; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_178 = 8'hb2 == idx ? io_bucketSeq_178 : _GEN_177; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_179 = 8'hb3 == idx ? io_bucketSeq_179 : _GEN_178; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_180 = 8'hb4 == idx ? io_bucketSeq_180 : _GEN_179; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_181 = 8'hb5 == idx ? io_bucketSeq_181 : _GEN_180; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_182 = 8'hb6 == idx ? io_bucketSeq_182 : _GEN_181; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_183 = 8'hb7 == idx ? io_bucketSeq_183 : _GEN_182; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_184 = 8'hb8 == idx ? io_bucketSeq_184 : _GEN_183; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_185 = 8'hb9 == idx ? io_bucketSeq_185 : _GEN_184; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_186 = 8'hba == idx ? io_bucketSeq_186 : _GEN_185; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_187 = 8'hbb == idx ? io_bucketSeq_187 : _GEN_186; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_188 = 8'hbc == idx ? io_bucketSeq_188 : _GEN_187; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_189 = 8'hbd == idx ? io_bucketSeq_189 : _GEN_188; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_190 = 8'hbe == idx ? io_bucketSeq_190 : _GEN_189; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_191 = 8'hbf == idx ? io_bucketSeq_191 : _GEN_190; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_192 = 8'hc0 == idx ? io_bucketSeq_192 : _GEN_191; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_193 = 8'hc1 == idx ? io_bucketSeq_193 : _GEN_192; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_194 = 8'hc2 == idx ? io_bucketSeq_194 : _GEN_193; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_195 = 8'hc3 == idx ? io_bucketSeq_195 : _GEN_194; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_196 = 8'hc4 == idx ? io_bucketSeq_196 : _GEN_195; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_197 = 8'hc5 == idx ? io_bucketSeq_197 : _GEN_196; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_198 = 8'hc6 == idx ? io_bucketSeq_198 : _GEN_197; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_199 = 8'hc7 == idx ? io_bucketSeq_199 : _GEN_198; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_200 = 8'hc8 == idx ? io_bucketSeq_200 : _GEN_199; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_201 = 8'hc9 == idx ? io_bucketSeq_201 : _GEN_200; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_202 = 8'hca == idx ? io_bucketSeq_202 : _GEN_201; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_203 = 8'hcb == idx ? io_bucketSeq_203 : _GEN_202; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_204 = 8'hcc == idx ? io_bucketSeq_204 : _GEN_203; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_205 = 8'hcd == idx ? io_bucketSeq_205 : _GEN_204; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_206 = 8'hce == idx ? io_bucketSeq_206 : _GEN_205; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_207 = 8'hcf == idx ? io_bucketSeq_207 : _GEN_206; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_208 = 8'hd0 == idx ? io_bucketSeq_208 : _GEN_207; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_209 = 8'hd1 == idx ? io_bucketSeq_209 : _GEN_208; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_210 = 8'hd2 == idx ? io_bucketSeq_210 : _GEN_209; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_211 = 8'hd3 == idx ? io_bucketSeq_211 : _GEN_210; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_212 = 8'hd4 == idx ? io_bucketSeq_212 : _GEN_211; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_213 = 8'hd5 == idx ? io_bucketSeq_213 : _GEN_212; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_214 = 8'hd6 == idx ? io_bucketSeq_214 : _GEN_213; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_215 = 8'hd7 == idx ? io_bucketSeq_215 : _GEN_214; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_216 = 8'hd8 == idx ? io_bucketSeq_216 : _GEN_215; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_217 = 8'hd9 == idx ? io_bucketSeq_217 : _GEN_216; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_218 = 8'hda == idx ? io_bucketSeq_218 : _GEN_217; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_219 = 8'hdb == idx ? io_bucketSeq_219 : _GEN_218; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_220 = 8'hdc == idx ? io_bucketSeq_220 : _GEN_219; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_221 = 8'hdd == idx ? io_bucketSeq_221 : _GEN_220; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_222 = 8'hde == idx ? io_bucketSeq_222 : _GEN_221; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_223 = 8'hdf == idx ? io_bucketSeq_223 : _GEN_222; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_224 = 8'he0 == idx ? io_bucketSeq_224 : _GEN_223; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_225 = 8'he1 == idx ? io_bucketSeq_225 : _GEN_224; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_226 = 8'he2 == idx ? io_bucketSeq_226 : _GEN_225; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_227 = 8'he3 == idx ? io_bucketSeq_227 : _GEN_226; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_228 = 8'he4 == idx ? io_bucketSeq_228 : _GEN_227; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_229 = 8'he5 == idx ? io_bucketSeq_229 : _GEN_228; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_230 = 8'he6 == idx ? io_bucketSeq_230 : _GEN_229; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_231 = 8'he7 == idx ? io_bucketSeq_231 : _GEN_230; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_232 = 8'he8 == idx ? io_bucketSeq_232 : _GEN_231; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_233 = 8'he9 == idx ? io_bucketSeq_233 : _GEN_232; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_234 = 8'hea == idx ? io_bucketSeq_234 : _GEN_233; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_235 = 8'heb == idx ? io_bucketSeq_235 : _GEN_234; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_236 = 8'hec == idx ? io_bucketSeq_236 : _GEN_235; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_237 = 8'hed == idx ? io_bucketSeq_237 : _GEN_236; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_238 = 8'hee == idx ? io_bucketSeq_238 : _GEN_237; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_239 = 8'hef == idx ? io_bucketSeq_239 : _GEN_238; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_240 = 8'hf0 == idx ? io_bucketSeq_240 : _GEN_239; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_241 = 8'hf1 == idx ? io_bucketSeq_241 : _GEN_240; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_242 = 8'hf2 == idx ? io_bucketSeq_242 : _GEN_241; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_243 = 8'hf3 == idx ? io_bucketSeq_243 : _GEN_242; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_244 = 8'hf4 == idx ? io_bucketSeq_244 : _GEN_243; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_245 = 8'hf5 == idx ? io_bucketSeq_245 : _GEN_244; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_246 = 8'hf6 == idx ? io_bucketSeq_246 : _GEN_245; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_247 = 8'hf7 == idx ? io_bucketSeq_247 : _GEN_246; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_248 = 8'hf8 == idx ? io_bucketSeq_248 : _GEN_247; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_249 = 8'hf9 == idx ? io_bucketSeq_249 : _GEN_248; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_250 = 8'hfa == idx ? io_bucketSeq_250 : _GEN_249; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_251 = 8'hfb == idx ? io_bucketSeq_251 : _GEN_250; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_252 = 8'hfc == idx ? io_bucketSeq_252 : _GEN_251; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_253 = 8'hfd == idx ? io_bucketSeq_253 : _GEN_252; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_254 = 8'hfe == idx ? io_bucketSeq_254 : _GEN_253; // @[EmitDecode.scala 81:{58,58}]
  wire [63:0] _GEN_255 = 8'hff == idx ? io_bucketSeq_255 : _GEN_254; // @[EmitDecode.scala 81:{58,58}]
  wire  matches_ = _matches_T[0] & _GEN_255 == io_packetSeq; // @[EmitDecode.scala 81:37]
  wire [63:0] delta = io_hit ? io_count : 64'h0; // @[EmitDecode.scala 82:18]
  wire  commit = ~(io_hit & ~matches_); // @[EmitDecode.scala 83:16]
  assign io_legalDeltaImpliesValid = ~(commit & |delta) | _matches_T[0]; // @[EmitDecode.scala 84:55]
endmodule
