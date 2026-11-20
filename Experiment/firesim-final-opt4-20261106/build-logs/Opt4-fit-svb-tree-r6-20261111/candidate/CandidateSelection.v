module CandidateSelection(
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
  input  [31:0] io_generation_0,
  input  [31:0] io_generation_1,
  input  [31:0] io_generation_2,
  input  [31:0] io_generation_3,
  input  [31:0] io_generation_4,
  input  [31:0] io_generation_5,
  input  [31:0] io_generation_6,
  input  [31:0] io_generation_7,
  input  [31:0] io_generation_8,
  input  [31:0] io_generation_9,
  input  [31:0] io_generation_10,
  input  [31:0] io_generation_11,
  input  [31:0] io_generation_12,
  input  [31:0] io_generation_13,
  input  [31:0] io_generation_14,
  input  [31:0] io_generation_15,
  input  [31:0] io_generation_16,
  input  [31:0] io_generation_17,
  input  [31:0] io_generation_18,
  input  [31:0] io_generation_19,
  input  [31:0] io_generation_20,
  input  [31:0] io_generation_21,
  input  [31:0] io_generation_22,
  input  [31:0] io_generation_23,
  input  [31:0] io_generation_24,
  input  [31:0] io_generation_25,
  input  [31:0] io_generation_26,
  input  [31:0] io_generation_27,
  input  [31:0] io_generation_28,
  input  [31:0] io_generation_29,
  input  [31:0] io_generation_30,
  input  [31:0] io_generation_31,
  output        io_chosenValid,
  output [4:0]  io_chosenIdx,
  output        io_equivalent,
  output        io_mutantEquivalent
);
  wire [68:0] _T_32 = {io_seq_0,io_generation_0,5'h0}; // @[Cat.scala 33:92]
  wire [68:0] _T_33 = {io_seq_1,io_generation_1,5'h1}; // @[Cat.scala 33:92]
  wire [68:0] _T_34 = {io_seq_2,io_generation_2,5'h2}; // @[Cat.scala 33:92]
  wire [68:0] _T_35 = {io_seq_3,io_generation_3,5'h3}; // @[Cat.scala 33:92]
  wire [68:0] _T_36 = {io_seq_4,io_generation_4,5'h4}; // @[Cat.scala 33:92]
  wire [68:0] _T_37 = {io_seq_5,io_generation_5,5'h5}; // @[Cat.scala 33:92]
  wire [68:0] _T_38 = {io_seq_6,io_generation_6,5'h6}; // @[Cat.scala 33:92]
  wire [68:0] _T_39 = {io_seq_7,io_generation_7,5'h7}; // @[Cat.scala 33:92]
  wire [68:0] _T_40 = {io_seq_8,io_generation_8,5'h8}; // @[Cat.scala 33:92]
  wire [68:0] _T_41 = {io_seq_9,io_generation_9,5'h9}; // @[Cat.scala 33:92]
  wire [68:0] _T_42 = {io_seq_10,io_generation_10,5'ha}; // @[Cat.scala 33:92]
  wire [68:0] _T_43 = {io_seq_11,io_generation_11,5'hb}; // @[Cat.scala 33:92]
  wire [68:0] _T_44 = {io_seq_12,io_generation_12,5'hc}; // @[Cat.scala 33:92]
  wire [68:0] _T_45 = {io_seq_13,io_generation_13,5'hd}; // @[Cat.scala 33:92]
  wire [68:0] _T_46 = {io_seq_14,io_generation_14,5'he}; // @[Cat.scala 33:92]
  wire [68:0] _T_47 = {io_seq_15,io_generation_15,5'hf}; // @[Cat.scala 33:92]
  wire [68:0] _T_48 = {io_seq_16,io_generation_16,5'h10}; // @[Cat.scala 33:92]
  wire [68:0] _T_49 = {io_seq_17,io_generation_17,5'h11}; // @[Cat.scala 33:92]
  wire [68:0] _T_50 = {io_seq_18,io_generation_18,5'h12}; // @[Cat.scala 33:92]
  wire [68:0] _T_51 = {io_seq_19,io_generation_19,5'h13}; // @[Cat.scala 33:92]
  wire [68:0] _T_52 = {io_seq_20,io_generation_20,5'h14}; // @[Cat.scala 33:92]
  wire [68:0] _T_53 = {io_seq_21,io_generation_21,5'h15}; // @[Cat.scala 33:92]
  wire [68:0] _T_54 = {io_seq_22,io_generation_22,5'h16}; // @[Cat.scala 33:92]
  wire [68:0] _T_55 = {io_seq_23,io_generation_23,5'h17}; // @[Cat.scala 33:92]
  wire [68:0] _T_56 = {io_seq_24,io_generation_24,5'h18}; // @[Cat.scala 33:92]
  wire [68:0] _T_57 = {io_seq_25,io_generation_25,5'h19}; // @[Cat.scala 33:92]
  wire [68:0] _T_58 = {io_seq_26,io_generation_26,5'h1a}; // @[Cat.scala 33:92]
  wire [68:0] _T_59 = {io_seq_27,io_generation_27,5'h1b}; // @[Cat.scala 33:92]
  wire [68:0] _T_60 = {io_seq_28,io_generation_28,5'h1c}; // @[Cat.scala 33:92]
  wire [68:0] _T_61 = {io_seq_29,io_generation_29,5'h1d}; // @[Cat.scala 33:92]
  wire [68:0] _T_62 = {io_seq_30,io_generation_30,5'h1e}; // @[Cat.scala 33:92]
  wire [68:0] _T_63 = {io_seq_31,io_generation_31,5'h1f}; // @[Cat.scala 33:92]
  wire  useRight = io_valid_1 & (~io_valid_0 | _T_33 > _T_32); // @[NewestSafeEntry.scala 18:33]
  wire  _T_64 = io_valid_0 | io_valid_1; // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_65 = useRight ? _T_33 : _T_32; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_66 = useRight ? 5'h1 : 5'h0; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_1 = io_valid_3 & (~io_valid_2 | _T_35 > _T_34); // @[NewestSafeEntry.scala 18:33]
  wire  _T_67 = io_valid_2 | io_valid_3; // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_68 = useRight_1 ? _T_35 : _T_34; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_69 = useRight_1 ? 5'h3 : 5'h2; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_2 = _T_67 & (~_T_64 | _T_68 > _T_65); // @[NewestSafeEntry.scala 18:33]
  wire  _T_70 = io_valid_0 | io_valid_1 | (io_valid_2 | io_valid_3); // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_71 = useRight_2 ? _T_68 : _T_65; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_72 = useRight_2 ? _T_69 : _T_66; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_3 = io_valid_5 & (~io_valid_4 | _T_37 > _T_36); // @[NewestSafeEntry.scala 18:33]
  wire  _T_73 = io_valid_4 | io_valid_5; // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_74 = useRight_3 ? _T_37 : _T_36; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_75 = useRight_3 ? 5'h5 : 5'h4; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_4 = io_valid_7 & (~io_valid_6 | _T_39 > _T_38); // @[NewestSafeEntry.scala 18:33]
  wire  _T_76 = io_valid_6 | io_valid_7; // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_77 = useRight_4 ? _T_39 : _T_38; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_78 = useRight_4 ? 5'h7 : 5'h6; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_5 = _T_76 & (~_T_73 | _T_77 > _T_74); // @[NewestSafeEntry.scala 18:33]
  wire  _T_79 = io_valid_4 | io_valid_5 | (io_valid_6 | io_valid_7); // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_80 = useRight_5 ? _T_77 : _T_74; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_81 = useRight_5 ? _T_78 : _T_75; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_6 = _T_79 & (~_T_70 | _T_80 > _T_71); // @[NewestSafeEntry.scala 18:33]
  wire  _T_82 = io_valid_0 | io_valid_1 | (io_valid_2 | io_valid_3) | (io_valid_4 | io_valid_5 | (io_valid_6 |
    io_valid_7)); // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_83 = useRight_6 ? _T_80 : _T_71; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_84 = useRight_6 ? _T_81 : _T_72; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_7 = io_valid_9 & (~io_valid_8 | _T_41 > _T_40); // @[NewestSafeEntry.scala 18:33]
  wire  _T_85 = io_valid_8 | io_valid_9; // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_86 = useRight_7 ? _T_41 : _T_40; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_87 = useRight_7 ? 5'h9 : 5'h8; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_8 = io_valid_11 & (~io_valid_10 | _T_43 > _T_42); // @[NewestSafeEntry.scala 18:33]
  wire  _T_88 = io_valid_10 | io_valid_11; // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_89 = useRight_8 ? _T_43 : _T_42; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_90 = useRight_8 ? 5'hb : 5'ha; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_9 = _T_88 & (~_T_85 | _T_89 > _T_86); // @[NewestSafeEntry.scala 18:33]
  wire  _T_91 = io_valid_8 | io_valid_9 | (io_valid_10 | io_valid_11); // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_92 = useRight_9 ? _T_89 : _T_86; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_93 = useRight_9 ? _T_90 : _T_87; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_10 = io_valid_13 & (~io_valid_12 | _T_45 > _T_44); // @[NewestSafeEntry.scala 18:33]
  wire  _T_94 = io_valid_12 | io_valid_13; // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_95 = useRight_10 ? _T_45 : _T_44; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_96 = useRight_10 ? 5'hd : 5'hc; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_11 = io_valid_15 & (~io_valid_14 | _T_47 > _T_46); // @[NewestSafeEntry.scala 18:33]
  wire  _T_97 = io_valid_14 | io_valid_15; // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_98 = useRight_11 ? _T_47 : _T_46; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_99 = useRight_11 ? 5'hf : 5'he; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_12 = _T_97 & (~_T_94 | _T_98 > _T_95); // @[NewestSafeEntry.scala 18:33]
  wire  _T_100 = io_valid_12 | io_valid_13 | (io_valid_14 | io_valid_15); // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_101 = useRight_12 ? _T_98 : _T_95; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_102 = useRight_12 ? _T_99 : _T_96; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_13 = _T_100 & (~_T_91 | _T_101 > _T_92); // @[NewestSafeEntry.scala 18:33]
  wire  _T_103 = io_valid_8 | io_valid_9 | (io_valid_10 | io_valid_11) | (io_valid_12 | io_valid_13 | (io_valid_14 |
    io_valid_15)); // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_104 = useRight_13 ? _T_101 : _T_92; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_105 = useRight_13 ? _T_102 : _T_93; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_14 = _T_103 & (~_T_82 | _T_104 > _T_83); // @[NewestSafeEntry.scala 18:33]
  wire  _T_106 = io_valid_0 | io_valid_1 | (io_valid_2 | io_valid_3) | (io_valid_4 | io_valid_5 | (io_valid_6 |
    io_valid_7)) | (io_valid_8 | io_valid_9 | (io_valid_10 | io_valid_11) | (io_valid_12 | io_valid_13 | (io_valid_14 |
    io_valid_15))); // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_107 = useRight_14 ? _T_104 : _T_83; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_108 = useRight_14 ? _T_105 : _T_84; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_15 = io_valid_17 & (~io_valid_16 | _T_49 > _T_48); // @[NewestSafeEntry.scala 18:33]
  wire  _T_109 = io_valid_16 | io_valid_17; // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_110 = useRight_15 ? _T_49 : _T_48; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_111 = useRight_15 ? 5'h11 : 5'h10; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_16 = io_valid_19 & (~io_valid_18 | _T_51 > _T_50); // @[NewestSafeEntry.scala 18:33]
  wire  _T_112 = io_valid_18 | io_valid_19; // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_113 = useRight_16 ? _T_51 : _T_50; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_114 = useRight_16 ? 5'h13 : 5'h12; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_17 = _T_112 & (~_T_109 | _T_113 > _T_110); // @[NewestSafeEntry.scala 18:33]
  wire  _T_115 = io_valid_16 | io_valid_17 | (io_valid_18 | io_valid_19); // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_116 = useRight_17 ? _T_113 : _T_110; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_117 = useRight_17 ? _T_114 : _T_111; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_18 = io_valid_21 & (~io_valid_20 | _T_53 > _T_52); // @[NewestSafeEntry.scala 18:33]
  wire  _T_118 = io_valid_20 | io_valid_21; // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_119 = useRight_18 ? _T_53 : _T_52; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_120 = useRight_18 ? 5'h15 : 5'h14; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_19 = io_valid_23 & (~io_valid_22 | _T_55 > _T_54); // @[NewestSafeEntry.scala 18:33]
  wire  _T_121 = io_valid_22 | io_valid_23; // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_122 = useRight_19 ? _T_55 : _T_54; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_123 = useRight_19 ? 5'h17 : 5'h16; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_20 = _T_121 & (~_T_118 | _T_122 > _T_119); // @[NewestSafeEntry.scala 18:33]
  wire  _T_124 = io_valid_20 | io_valid_21 | (io_valid_22 | io_valid_23); // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_125 = useRight_20 ? _T_122 : _T_119; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_126 = useRight_20 ? _T_123 : _T_120; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_21 = _T_124 & (~_T_115 | _T_125 > _T_116); // @[NewestSafeEntry.scala 18:33]
  wire  _T_127 = io_valid_16 | io_valid_17 | (io_valid_18 | io_valid_19) | (io_valid_20 | io_valid_21 | (io_valid_22 |
    io_valid_23)); // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_128 = useRight_21 ? _T_125 : _T_116; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_129 = useRight_21 ? _T_126 : _T_117; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_22 = io_valid_25 & (~io_valid_24 | _T_57 > _T_56); // @[NewestSafeEntry.scala 18:33]
  wire  _T_130 = io_valid_24 | io_valid_25; // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_131 = useRight_22 ? _T_57 : _T_56; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_132 = useRight_22 ? 5'h19 : 5'h18; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_23 = io_valid_27 & (~io_valid_26 | _T_59 > _T_58); // @[NewestSafeEntry.scala 18:33]
  wire  _T_133 = io_valid_26 | io_valid_27; // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_134 = useRight_23 ? _T_59 : _T_58; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_135 = useRight_23 ? 5'h1b : 5'h1a; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_24 = _T_133 & (~_T_130 | _T_134 > _T_131); // @[NewestSafeEntry.scala 18:33]
  wire  _T_136 = io_valid_24 | io_valid_25 | (io_valid_26 | io_valid_27); // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_137 = useRight_24 ? _T_134 : _T_131; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_138 = useRight_24 ? _T_135 : _T_132; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_25 = io_valid_29 & (~io_valid_28 | _T_61 > _T_60); // @[NewestSafeEntry.scala 18:33]
  wire  _T_139 = io_valid_28 | io_valid_29; // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_140 = useRight_25 ? _T_61 : _T_60; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_141 = useRight_25 ? 5'h1d : 5'h1c; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_26 = io_valid_31 & (~io_valid_30 | _T_63 > _T_62); // @[NewestSafeEntry.scala 18:33]
  wire  _T_142 = io_valid_30 | io_valid_31; // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_143 = useRight_26 ? _T_63 : _T_62; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_144 = useRight_26 ? 5'h1f : 5'h1e; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_27 = _T_142 & (~_T_139 | _T_143 > _T_140); // @[NewestSafeEntry.scala 18:33]
  wire  _T_145 = io_valid_28 | io_valid_29 | (io_valid_30 | io_valid_31); // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_146 = useRight_27 ? _T_143 : _T_140; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_147 = useRight_27 ? _T_144 : _T_141; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_28 = _T_145 & (~_T_136 | _T_146 > _T_137); // @[NewestSafeEntry.scala 18:33]
  wire  _T_148 = io_valid_24 | io_valid_25 | (io_valid_26 | io_valid_27) | (io_valid_28 | io_valid_29 | (io_valid_30 |
    io_valid_31)); // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_149 = useRight_28 ? _T_146 : _T_137; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_150 = useRight_28 ? _T_147 : _T_138; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_29 = _T_148 & (~_T_127 | _T_149 > _T_128); // @[NewestSafeEntry.scala 18:33]
  wire  _T_151 = io_valid_16 | io_valid_17 | (io_valid_18 | io_valid_19) | (io_valid_20 | io_valid_21 | (io_valid_22 |
    io_valid_23)) | (io_valid_24 | io_valid_25 | (io_valid_26 | io_valid_27) | (io_valid_28 | io_valid_29 | (io_valid_30
     | io_valid_31))); // @[NewestSafeEntry.scala 19:18]
  wire [68:0] _T_152 = useRight_29 ? _T_149 : _T_128; // @[NewestSafeEntry.scala 19:34]
  wire [4:0] _T_153 = useRight_29 ? _T_150 : _T_129; // @[NewestSafeEntry.scala 20:14]
  wire  useRight_30 = _T_151 & (~_T_106 | _T_152 > _T_107); // @[NewestSafeEntry.scala 18:33]
  wire  _T_154 = io_valid_0 | io_valid_1 | (io_valid_2 | io_valid_3) | (io_valid_4 | io_valid_5 | (io_valid_6 |
    io_valid_7)) | (io_valid_8 | io_valid_9 | (io_valid_10 | io_valid_11) | (io_valid_12 | io_valid_13 | (io_valid_14 |
    io_valid_15))) | _T_151; // @[NewestSafeEntry.scala 19:18]
  wire [4:0] _T_156 = useRight_30 ? _T_153 : _T_108; // @[NewestSafeEntry.scala 20:14]
  assign io_chosenValid = io_valid_0 | io_valid_1 | (io_valid_2 | io_valid_3) | (io_valid_4 | io_valid_5 | (io_valid_6
     | io_valid_7)) | (io_valid_8 | io_valid_9 | (io_valid_10 | io_valid_11) | (io_valid_12 | io_valid_13 | (io_valid_14
     | io_valid_15))) | _T_151; // @[NewestSafeEntry.scala 19:18]
  assign io_chosenIdx = _T_154 ? _T_156 : 5'h0; // @[NewestSafeEntry.scala 24:20]
  assign io_equivalent = 1'h1; // @[Emit.scala 38:17]
  assign io_mutantEquivalent = 1'h1; // @[Emit.scala 39:23]
endmodule
