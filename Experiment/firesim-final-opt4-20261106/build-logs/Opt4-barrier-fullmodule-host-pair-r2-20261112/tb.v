module tb;
integer cycle;
reg [63:0] rng = 64'h4d595df4d0f33173;
reg  clock;
reg  reset;
reg  io_resetStats;
reg  io_event_valid;
reg [31:0] io_event_bits;
reg [31:0] io_safeWatermark;
reg [63:0] io_currentCycle;
reg  io_fatalProtocolError;
wire [63:0] r_io_seen;
wire [63:0] c_io_seen;
wire [160:0] r_io_debugView_0;
wire [160:0] c_io_debugView_0;
wire [160:0] r_io_debugView_1;
wire [160:0] c_io_debugView_1;
wire [160:0] r_io_debugView_2;
wire [160:0] c_io_debugView_2;
wire [160:0] r_io_debugView_3;
wire [160:0] c_io_debugView_3;
wire [160:0] r_io_debugView_4;
wire [160:0] c_io_debugView_4;
wire [160:0] r_io_debugView_5;
wire [160:0] c_io_debugView_5;
wire [160:0] r_io_debugView_6;
wire [160:0] c_io_debugView_6;
wire [160:0] r_io_debugView_7;
wire [160:0] c_io_debugView_7;
wire [160:0] r_io_debugView_8;
wire [160:0] c_io_debugView_8;
wire [160:0] r_io_debugView_9;
wire [160:0] c_io_debugView_9;
wire [160:0] r_io_debugView_10;
wire [160:0] c_io_debugView_10;
wire [160:0] r_io_debugView_11;
wire [160:0] c_io_debugView_11;
wire [160:0] r_io_debugView_12;
wire [160:0] c_io_debugView_12;
wire [160:0] r_io_debugView_13;
wire [160:0] c_io_debugView_13;
wire [160:0] r_io_debugView_14;
wire [160:0] c_io_debugView_14;
wire [160:0] r_io_debugView_15;
wire [160:0] c_io_debugView_15;
wire [160:0] r_io_debugView_16;
wire [160:0] c_io_debugView_16;
wire [160:0] r_io_debugView_17;
wire [160:0] c_io_debugView_17;
wire [160:0] r_io_debugView_18;
wire [160:0] c_io_debugView_18;
wire [160:0] r_io_debugView_19;
wire [160:0] c_io_debugView_19;
wire [160:0] r_io_debugView_20;
wire [160:0] c_io_debugView_20;
wire [160:0] r_io_debugView_21;
wire [160:0] c_io_debugView_21;
wire [160:0] r_io_debugView_22;
wire [160:0] c_io_debugView_22;
wire [160:0] r_io_debugView_23;
wire [160:0] c_io_debugView_23;
wire [160:0] r_io_debugView_24;
wire [160:0] c_io_debugView_24;
wire [160:0] r_io_debugView_25;
wire [160:0] c_io_debugView_25;
wire [160:0] r_io_debugView_26;
wire [160:0] c_io_debugView_26;
wire [160:0] r_io_debugView_27;
wire [160:0] c_io_debugView_27;
wire [160:0] r_io_debugView_28;
wire [160:0] c_io_debugView_28;
wire [160:0] r_io_debugView_29;
wire [160:0] c_io_debugView_29;
wire [160:0] r_io_debugView_30;
wire [160:0] c_io_debugView_30;
wire [160:0] r_io_debugView_31;
wire [160:0] c_io_debugView_31;
wire [160:0] r_io_debugView_32;
wire [160:0] c_io_debugView_32;
wire [160:0] r_io_debugView_33;
wire [160:0] c_io_debugView_33;
wire [160:0] r_io_debugView_34;
wire [160:0] c_io_debugView_34;
wire [160:0] r_io_debugView_35;
wire [160:0] c_io_debugView_35;
wire [160:0] r_io_debugView_36;
wire [160:0] c_io_debugView_36;
wire [160:0] r_io_debugView_37;
wire [160:0] c_io_debugView_37;
wire [160:0] r_io_debugView_38;
wire [160:0] c_io_debugView_38;
wire [160:0] r_io_debugView_39;
wire [160:0] c_io_debugView_39;
wire [160:0] r_io_debugView_40;
wire [160:0] c_io_debugView_40;
wire [160:0] r_io_debugView_41;
wire [160:0] c_io_debugView_41;
wire [160:0] r_io_debugView_42;
wire [160:0] c_io_debugView_42;
wire [160:0] r_io_debugView_43;
wire [160:0] c_io_debugView_43;
wire [160:0] r_io_debugView_44;
wire [160:0] c_io_debugView_44;
wire [160:0] r_io_debugView_45;
wire [160:0] c_io_debugView_45;
wire [160:0] r_io_debugView_46;
wire [160:0] c_io_debugView_46;
wire [160:0] r_io_debugView_47;
wire [160:0] c_io_debugView_47;
wire [160:0] r_io_debugView_48;
wire [160:0] c_io_debugView_48;
wire [160:0] r_io_debugView_49;
wire [160:0] c_io_debugView_49;
wire [160:0] r_io_debugView_50;
wire [160:0] c_io_debugView_50;
wire [160:0] r_io_debugView_51;
wire [160:0] c_io_debugView_51;
wire [160:0] r_io_debugView_52;
wire [160:0] c_io_debugView_52;
wire [160:0] r_io_debugView_53;
wire [160:0] c_io_debugView_53;
wire [160:0] r_io_debugView_54;
wire [160:0] c_io_debugView_54;
wire [160:0] r_io_debugView_55;
wire [160:0] c_io_debugView_55;
wire [160:0] r_io_debugView_56;
wire [160:0] c_io_debugView_56;
wire [160:0] r_io_debugView_57;
wire [160:0] c_io_debugView_57;
wire [160:0] r_io_debugView_58;
wire [160:0] c_io_debugView_58;
wire [160:0] r_io_debugView_59;
wire [160:0] c_io_debugView_59;
wire [160:0] r_io_debugView_60;
wire [160:0] c_io_debugView_60;
wire [160:0] r_io_debugView_61;
wire [160:0] c_io_debugView_61;
wire [160:0] r_io_debugView_62;
wire [160:0] c_io_debugView_62;
wire [160:0] r_io_debugView_63;
wire [160:0] c_io_debugView_63;
wire [160:0] r_io_debugView_64;
wire [160:0] c_io_debugView_64;
wire [160:0] r_io_debugView_65;
wire [160:0] c_io_debugView_65;
wire [160:0] r_io_debugView_66;
wire [160:0] c_io_debugView_66;
wire [160:0] r_io_debugView_67;
wire [160:0] c_io_debugView_67;
wire [160:0] r_io_debugView_68;
wire [160:0] c_io_debugView_68;
wire [160:0] r_io_debugView_69;
wire [160:0] c_io_debugView_69;
wire [160:0] r_io_debugView_70;
wire [160:0] c_io_debugView_70;
wire [160:0] r_io_debugView_71;
wire [160:0] c_io_debugView_71;
wire [160:0] r_io_debugView_72;
wire [160:0] c_io_debugView_72;
wire [160:0] r_io_debugView_73;
wire [160:0] c_io_debugView_73;
wire [160:0] r_io_debugView_74;
wire [160:0] c_io_debugView_74;
wire [160:0] r_io_debugView_75;
wire [160:0] c_io_debugView_75;
wire [160:0] r_io_debugView_76;
wire [160:0] c_io_debugView_76;
wire [160:0] r_io_debugView_77;
wire [160:0] c_io_debugView_77;
wire [160:0] r_io_debugView_78;
wire [160:0] c_io_debugView_78;
wire [160:0] r_io_debugView_79;
wire [160:0] c_io_debugView_79;
wire [160:0] r_io_debugView_80;
wire [160:0] c_io_debugView_80;
wire [160:0] r_io_debugView_81;
wire [160:0] c_io_debugView_81;
wire [160:0] r_io_debugView_82;
wire [160:0] c_io_debugView_82;
wire [160:0] r_io_debugView_83;
wire [160:0] c_io_debugView_83;
wire [160:0] r_io_debugView_84;
wire [160:0] c_io_debugView_84;
wire [160:0] r_io_debugView_85;
wire [160:0] c_io_debugView_85;
wire [160:0] r_io_debugView_86;
wire [160:0] c_io_debugView_86;
wire [160:0] r_io_debugView_87;
wire [160:0] c_io_debugView_87;
wire [160:0] r_io_debugView_88;
wire [160:0] c_io_debugView_88;
wire [160:0] r_io_debugView_89;
wire [160:0] c_io_debugView_89;
wire [160:0] r_io_debugView_90;
wire [160:0] c_io_debugView_90;
wire [160:0] r_io_debugView_91;
wire [160:0] c_io_debugView_91;
wire [160:0] r_io_debugView_92;
wire [160:0] c_io_debugView_92;
wire [160:0] r_io_debugView_93;
wire [160:0] c_io_debugView_93;
wire [160:0] r_io_debugView_94;
wire [160:0] c_io_debugView_94;
wire [160:0] r_io_debugView_95;
wire [160:0] c_io_debugView_95;
wire [160:0] r_io_debugView_96;
wire [160:0] c_io_debugView_96;
wire [160:0] r_io_debugView_97;
wire [160:0] c_io_debugView_97;
wire [160:0] r_io_debugView_98;
wire [160:0] c_io_debugView_98;
wire [160:0] r_io_debugView_99;
wire [160:0] c_io_debugView_99;
wire [160:0] r_io_debugView_100;
wire [160:0] c_io_debugView_100;
wire [160:0] r_io_debugView_101;
wire [160:0] c_io_debugView_101;
wire [160:0] r_io_debugView_102;
wire [160:0] c_io_debugView_102;
wire [160:0] r_io_debugView_103;
wire [160:0] c_io_debugView_103;
wire [160:0] r_io_debugView_104;
wire [160:0] c_io_debugView_104;
wire [160:0] r_io_debugView_105;
wire [160:0] c_io_debugView_105;
wire [160:0] r_io_debugView_106;
wire [160:0] c_io_debugView_106;
wire [160:0] r_io_debugView_107;
wire [160:0] c_io_debugView_107;
wire [160:0] r_io_debugView_108;
wire [160:0] c_io_debugView_108;
wire [160:0] r_io_debugView_109;
wire [160:0] c_io_debugView_109;
wire [160:0] r_io_debugView_110;
wire [160:0] c_io_debugView_110;
wire [160:0] r_io_debugView_111;
wire [160:0] c_io_debugView_111;
wire [160:0] r_io_debugView_112;
wire [160:0] c_io_debugView_112;
wire [160:0] r_io_debugView_113;
wire [160:0] c_io_debugView_113;
wire [160:0] r_io_debugView_114;
wire [160:0] c_io_debugView_114;
wire [160:0] r_io_debugView_115;
wire [160:0] c_io_debugView_115;
wire [160:0] r_io_debugView_116;
wire [160:0] c_io_debugView_116;
wire [160:0] r_io_debugView_117;
wire [160:0] c_io_debugView_117;
wire [160:0] r_io_debugView_118;
wire [160:0] c_io_debugView_118;
wire [160:0] r_io_debugView_119;
wire [160:0] c_io_debugView_119;
wire [160:0] r_io_debugView_120;
wire [160:0] c_io_debugView_120;
wire [160:0] r_io_debugView_121;
wire [160:0] c_io_debugView_121;
wire [160:0] r_io_debugView_122;
wire [160:0] c_io_debugView_122;
wire [160:0] r_io_debugView_123;
wire [160:0] c_io_debugView_123;
wire [160:0] r_io_debugView_124;
wire [160:0] c_io_debugView_124;
wire [160:0] r_io_debugView_125;
wire [160:0] c_io_debugView_125;
wire [160:0] r_io_debugView_126;
wire [160:0] c_io_debugView_126;
wire [160:0] r_io_debugView_127;
wire [160:0] c_io_debugView_127;
wire [160:0] r_io_debugView_128;
wire [160:0] c_io_debugView_128;
wire [160:0] r_io_debugView_129;
wire [160:0] c_io_debugView_129;
wire [160:0] r_io_debugView_130;
wire [160:0] c_io_debugView_130;
wire [160:0] r_io_debugView_131;
wire [160:0] c_io_debugView_131;
wire [160:0] r_io_debugView_132;
wire [160:0] c_io_debugView_132;
wire [160:0] r_io_debugView_133;
wire [160:0] c_io_debugView_133;
wire [160:0] r_io_debugView_134;
wire [160:0] c_io_debugView_134;
wire [160:0] r_io_debugView_135;
wire [160:0] c_io_debugView_135;
wire [160:0] r_io_debugView_136;
wire [160:0] c_io_debugView_136;
wire [160:0] r_io_debugView_137;
wire [160:0] c_io_debugView_137;
wire [160:0] r_io_debugView_138;
wire [160:0] c_io_debugView_138;
wire [160:0] r_io_debugView_139;
wire [160:0] c_io_debugView_139;
wire [160:0] r_io_debugView_140;
wire [160:0] c_io_debugView_140;
wire [160:0] r_io_debugView_141;
wire [160:0] c_io_debugView_141;
wire [160:0] r_io_debugView_142;
wire [160:0] c_io_debugView_142;
wire [160:0] r_io_debugView_143;
wire [160:0] c_io_debugView_143;
wire [160:0] r_io_debugView_144;
wire [160:0] c_io_debugView_144;
wire [160:0] r_io_debugView_145;
wire [160:0] c_io_debugView_145;
wire [160:0] r_io_debugView_146;
wire [160:0] c_io_debugView_146;
wire [160:0] r_io_debugView_147;
wire [160:0] c_io_debugView_147;
wire [160:0] r_io_debugView_148;
wire [160:0] c_io_debugView_148;
wire [160:0] r_io_debugView_149;
wire [160:0] c_io_debugView_149;
wire [160:0] r_io_debugView_150;
wire [160:0] c_io_debugView_150;
wire [160:0] r_io_debugView_151;
wire [160:0] c_io_debugView_151;
wire [160:0] r_io_debugView_152;
wire [160:0] c_io_debugView_152;
wire [160:0] r_io_debugView_153;
wire [160:0] c_io_debugView_153;
wire [160:0] r_io_debugView_154;
wire [160:0] c_io_debugView_154;
wire [160:0] r_io_debugView_155;
wire [160:0] c_io_debugView_155;
wire [160:0] r_io_debugView_156;
wire [160:0] c_io_debugView_156;
wire [160:0] r_io_debugView_157;
wire [160:0] c_io_debugView_157;
wire [160:0] r_io_debugView_158;
wire [160:0] c_io_debugView_158;
wire [160:0] r_io_debugView_159;
wire [160:0] c_io_debugView_159;
wire [160:0] r_io_debugView_160;
wire [160:0] c_io_debugView_160;
wire [160:0] r_io_debugView_161;
wire [160:0] c_io_debugView_161;
wire [160:0] r_io_debugView_162;
wire [160:0] c_io_debugView_162;
wire [160:0] r_io_debugView_163;
wire [160:0] c_io_debugView_163;
wire [160:0] r_io_debugView_164;
wire [160:0] c_io_debugView_164;
wire [160:0] r_io_debugView_165;
wire [160:0] c_io_debugView_165;
wire [160:0] r_io_debugView_166;
wire [160:0] c_io_debugView_166;
wire [160:0] r_io_debugView_167;
wire [160:0] c_io_debugView_167;
wire [160:0] r_io_debugView_168;
wire [160:0] c_io_debugView_168;
wire [160:0] r_io_debugView_169;
wire [160:0] c_io_debugView_169;
wire [160:0] r_io_debugView_170;
wire [160:0] c_io_debugView_170;
wire [160:0] r_io_debugView_171;
wire [160:0] c_io_debugView_171;
wire [160:0] r_io_debugView_172;
wire [160:0] c_io_debugView_172;
wire [160:0] r_io_debugView_173;
wire [160:0] c_io_debugView_173;
wire [160:0] r_io_debugView_174;
wire [160:0] c_io_debugView_174;
wire [160:0] r_io_debugView_175;
wire [160:0] c_io_debugView_175;
wire [160:0] r_io_debugView_176;
wire [160:0] c_io_debugView_176;
wire [160:0] r_io_debugView_177;
wire [160:0] c_io_debugView_177;
wire [160:0] r_io_debugView_178;
wire [160:0] c_io_debugView_178;
wire [160:0] r_io_debugView_179;
wire [160:0] c_io_debugView_179;
wire [160:0] r_io_debugView_180;
wire [160:0] c_io_debugView_180;
wire [160:0] r_io_debugView_181;
wire [160:0] c_io_debugView_181;
wire [160:0] r_io_debugView_182;
wire [160:0] c_io_debugView_182;
wire [160:0] r_io_debugView_183;
wire [160:0] c_io_debugView_183;
wire [160:0] r_io_debugView_184;
wire [160:0] c_io_debugView_184;
wire [160:0] r_io_debugView_185;
wire [160:0] c_io_debugView_185;
wire [160:0] r_io_debugView_186;
wire [160:0] c_io_debugView_186;
wire [160:0] r_io_debugView_187;
wire [160:0] c_io_debugView_187;
wire [160:0] r_io_debugView_188;
wire [160:0] c_io_debugView_188;
wire [160:0] r_io_debugView_189;
wire [160:0] c_io_debugView_189;
wire [160:0] r_io_debugView_190;
wire [160:0] c_io_debugView_190;
wire [160:0] r_io_debugView_191;
wire [160:0] c_io_debugView_191;
wire [160:0] r_io_debugView_192;
wire [160:0] c_io_debugView_192;
wire [160:0] r_io_debugView_193;
wire [160:0] c_io_debugView_193;
wire [160:0] r_io_debugView_194;
wire [160:0] c_io_debugView_194;
wire [160:0] r_io_debugView_195;
wire [160:0] c_io_debugView_195;
wire [160:0] r_io_debugView_196;
wire [160:0] c_io_debugView_196;
wire [160:0] r_io_debugView_197;
wire [160:0] c_io_debugView_197;
wire [160:0] r_io_debugView_198;
wire [160:0] c_io_debugView_198;
wire [160:0] r_io_debugView_199;
wire [160:0] c_io_debugView_199;
wire [160:0] r_io_debugView_200;
wire [160:0] c_io_debugView_200;
wire [160:0] r_io_debugView_201;
wire [160:0] c_io_debugView_201;
wire [160:0] r_io_debugView_202;
wire [160:0] c_io_debugView_202;
wire [160:0] r_io_debugView_203;
wire [160:0] c_io_debugView_203;
wire [160:0] r_io_debugView_204;
wire [160:0] c_io_debugView_204;
wire [160:0] r_io_debugView_205;
wire [160:0] c_io_debugView_205;
wire [160:0] r_io_debugView_206;
wire [160:0] c_io_debugView_206;
wire [160:0] r_io_debugView_207;
wire [160:0] c_io_debugView_207;
wire [160:0] r_io_debugView_208;
wire [160:0] c_io_debugView_208;
wire [160:0] r_io_debugView_209;
wire [160:0] c_io_debugView_209;
wire [160:0] r_io_debugView_210;
wire [160:0] c_io_debugView_210;
wire [160:0] r_io_debugView_211;
wire [160:0] c_io_debugView_211;
wire [160:0] r_io_debugView_212;
wire [160:0] c_io_debugView_212;
wire [160:0] r_io_debugView_213;
wire [160:0] c_io_debugView_213;
wire [160:0] r_io_debugView_214;
wire [160:0] c_io_debugView_214;
wire [160:0] r_io_debugView_215;
wire [160:0] c_io_debugView_215;
wire [160:0] r_io_debugView_216;
wire [160:0] c_io_debugView_216;
wire [160:0] r_io_debugView_217;
wire [160:0] c_io_debugView_217;
wire [160:0] r_io_debugView_218;
wire [160:0] c_io_debugView_218;
wire [160:0] r_io_debugView_219;
wire [160:0] c_io_debugView_219;
wire [160:0] r_io_debugView_220;
wire [160:0] c_io_debugView_220;
wire [160:0] r_io_debugView_221;
wire [160:0] c_io_debugView_221;
wire [160:0] r_io_debugView_222;
wire [160:0] c_io_debugView_222;
wire [160:0] r_io_debugView_223;
wire [160:0] c_io_debugView_223;
wire [160:0] r_io_debugView_224;
wire [160:0] c_io_debugView_224;
wire [160:0] r_io_debugView_225;
wire [160:0] c_io_debugView_225;
wire [160:0] r_io_debugView_226;
wire [160:0] c_io_debugView_226;
wire [160:0] r_io_debugView_227;
wire [160:0] c_io_debugView_227;
wire [160:0] r_io_debugView_228;
wire [160:0] c_io_debugView_228;
wire [160:0] r_io_debugView_229;
wire [160:0] c_io_debugView_229;
wire [160:0] r_io_debugView_230;
wire [160:0] c_io_debugView_230;
wire [160:0] r_io_debugView_231;
wire [160:0] c_io_debugView_231;
wire [160:0] r_io_debugView_232;
wire [160:0] c_io_debugView_232;
wire [160:0] r_io_debugView_233;
wire [160:0] c_io_debugView_233;
wire [160:0] r_io_debugView_234;
wire [160:0] c_io_debugView_234;
wire [160:0] r_io_debugView_235;
wire [160:0] c_io_debugView_235;
wire [160:0] r_io_debugView_236;
wire [160:0] c_io_debugView_236;
wire [160:0] r_io_debugView_237;
wire [160:0] c_io_debugView_237;
wire [160:0] r_io_debugView_238;
wire [160:0] c_io_debugView_238;
wire [160:0] r_io_debugView_239;
wire [160:0] c_io_debugView_239;
wire [160:0] r_io_debugView_240;
wire [160:0] c_io_debugView_240;
wire [160:0] r_io_debugView_241;
wire [160:0] c_io_debugView_241;
wire [160:0] r_io_debugView_242;
wire [160:0] c_io_debugView_242;
wire [160:0] r_io_debugView_243;
wire [160:0] c_io_debugView_243;
wire [160:0] r_io_debugView_244;
wire [160:0] c_io_debugView_244;
wire [160:0] r_io_debugView_245;
wire [160:0] c_io_debugView_245;
wire [160:0] r_io_debugView_246;
wire [160:0] c_io_debugView_246;
wire [160:0] r_io_debugView_247;
wire [160:0] c_io_debugView_247;
wire [160:0] r_io_debugView_248;
wire [160:0] c_io_debugView_248;
wire [160:0] r_io_debugView_249;
wire [160:0] c_io_debugView_249;
wire [160:0] r_io_debugView_250;
wire [160:0] c_io_debugView_250;
wire [160:0] r_io_debugView_251;
wire [160:0] c_io_debugView_251;
wire [160:0] r_io_debugView_252;
wire [160:0] c_io_debugView_252;
wire [160:0] r_io_debugView_253;
wire [160:0] c_io_debugView_253;
wire [160:0] r_io_debugView_254;
wire [160:0] c_io_debugView_254;
wire [160:0] r_io_debugView_255;
wire [160:0] c_io_debugView_255;
wire [63:0] r_io_resolved;
wire [63:0] c_io_resolved;
wire [63:0] r_io_pending;
wire [63:0] c_io_pending;
wire [63:0] r_io_dropped;
wire [63:0] c_io_dropped;
wire [63:0] r_io_requestCycleSum;
wire [63:0] c_io_requestCycleSum;
wire [63:0] r_io_safeCycleSum;
wire [63:0] c_io_safeCycleSum;
wire [63:0] r_io_statsValid;
wire [63:0] c_io_statsValid;
BarrierReference dutReference(.clock(clock),.reset(reset),.io_resetStats(io_resetStats),.io_event_valid(io_event_valid),.io_event_bits(io_event_bits),.io_safeWatermark(io_safeWatermark),.io_currentCycle(io_currentCycle),.io_fatalProtocolError(io_fatalProtocolError),.io_seen(r_io_seen),.io_debugView_0(r_io_debugView_0),.io_debugView_1(r_io_debugView_1),.io_debugView_2(r_io_debugView_2),.io_debugView_3(r_io_debugView_3),.io_debugView_4(r_io_debugView_4),.io_debugView_5(r_io_debugView_5),.io_debugView_6(r_io_debugView_6),.io_debugView_7(r_io_debugView_7),.io_debugView_8(r_io_debugView_8),.io_debugView_9(r_io_debugView_9),.io_debugView_10(r_io_debugView_10),.io_debugView_11(r_io_debugView_11),.io_debugView_12(r_io_debugView_12),.io_debugView_13(r_io_debugView_13),.io_debugView_14(r_io_debugView_14),.io_debugView_15(r_io_debugView_15),.io_debugView_16(r_io_debugView_16),.io_debugView_17(r_io_debugView_17),.io_debugView_18(r_io_debugView_18),.io_debugView_19(r_io_debugView_19),.io_debugView_20(r_io_debugView_20),.io_debugView_21(r_io_debugView_21),.io_debugView_22(r_io_debugView_22),.io_debugView_23(r_io_debugView_23),.io_debugView_24(r_io_debugView_24),.io_debugView_25(r_io_debugView_25),.io_debugView_26(r_io_debugView_26),.io_debugView_27(r_io_debugView_27),.io_debugView_28(r_io_debugView_28),.io_debugView_29(r_io_debugView_29),.io_debugView_30(r_io_debugView_30),.io_debugView_31(r_io_debugView_31),.io_debugView_32(r_io_debugView_32),.io_debugView_33(r_io_debugView_33),.io_debugView_34(r_io_debugView_34),.io_debugView_35(r_io_debugView_35),.io_debugView_36(r_io_debugView_36),.io_debugView_37(r_io_debugView_37),.io_debugView_38(r_io_debugView_38),.io_debugView_39(r_io_debugView_39),.io_debugView_40(r_io_debugView_40),.io_debugView_41(r_io_debugView_41),.io_debugView_42(r_io_debugView_42),.io_debugView_43(r_io_debugView_43),.io_debugView_44(r_io_debugView_44),.io_debugView_45(r_io_debugView_45),.io_debugView_46(r_io_debugView_46),.io_debugView_47(r_io_debugView_47),.io_debugView_48(r_io_debugView_48),.io_debugView_49(r_io_debugView_49),.io_debugView_50(r_io_debugView_50),.io_debugView_51(r_io_debugView_51),.io_debugView_52(r_io_debugView_52),.io_debugView_53(r_io_debugView_53),.io_debugView_54(r_io_debugView_54),.io_debugView_55(r_io_debugView_55),.io_debugView_56(r_io_debugView_56),.io_debugView_57(r_io_debugView_57),.io_debugView_58(r_io_debugView_58),.io_debugView_59(r_io_debugView_59),.io_debugView_60(r_io_debugView_60),.io_debugView_61(r_io_debugView_61),.io_debugView_62(r_io_debugView_62),.io_debugView_63(r_io_debugView_63),.io_debugView_64(r_io_debugView_64),.io_debugView_65(r_io_debugView_65),.io_debugView_66(r_io_debugView_66),.io_debugView_67(r_io_debugView_67),.io_debugView_68(r_io_debugView_68),.io_debugView_69(r_io_debugView_69),.io_debugView_70(r_io_debugView_70),.io_debugView_71(r_io_debugView_71),.io_debugView_72(r_io_debugView_72),.io_debugView_73(r_io_debugView_73),.io_debugView_74(r_io_debugView_74),.io_debugView_75(r_io_debugView_75),.io_debugView_76(r_io_debugView_76),.io_debugView_77(r_io_debugView_77),.io_debugView_78(r_io_debugView_78),.io_debugView_79(r_io_debugView_79),.io_debugView_80(r_io_debugView_80),.io_debugView_81(r_io_debugView_81),.io_debugView_82(r_io_debugView_82),.io_debugView_83(r_io_debugView_83),.io_debugView_84(r_io_debugView_84),.io_debugView_85(r_io_debugView_85),.io_debugView_86(r_io_debugView_86),.io_debugView_87(r_io_debugView_87),.io_debugView_88(r_io_debugView_88),.io_debugView_89(r_io_debugView_89),.io_debugView_90(r_io_debugView_90),.io_debugView_91(r_io_debugView_91),.io_debugView_92(r_io_debugView_92),.io_debugView_93(r_io_debugView_93),.io_debugView_94(r_io_debugView_94),.io_debugView_95(r_io_debugView_95),.io_debugView_96(r_io_debugView_96),.io_debugView_97(r_io_debugView_97),.io_debugView_98(r_io_debugView_98),.io_debugView_99(r_io_debugView_99),.io_debugView_100(r_io_debugView_100),.io_debugView_101(r_io_debugView_101),.io_debugView_102(r_io_debugView_102),.io_debugView_103(r_io_debugView_103),.io_debugView_104(r_io_debugView_104),.io_debugView_105(r_io_debugView_105),.io_debugView_106(r_io_debugView_106),.io_debugView_107(r_io_debugView_107),.io_debugView_108(r_io_debugView_108),.io_debugView_109(r_io_debugView_109),.io_debugView_110(r_io_debugView_110),.io_debugView_111(r_io_debugView_111),.io_debugView_112(r_io_debugView_112),.io_debugView_113(r_io_debugView_113),.io_debugView_114(r_io_debugView_114),.io_debugView_115(r_io_debugView_115),.io_debugView_116(r_io_debugView_116),.io_debugView_117(r_io_debugView_117),.io_debugView_118(r_io_debugView_118),.io_debugView_119(r_io_debugView_119),.io_debugView_120(r_io_debugView_120),.io_debugView_121(r_io_debugView_121),.io_debugView_122(r_io_debugView_122),.io_debugView_123(r_io_debugView_123),.io_debugView_124(r_io_debugView_124),.io_debugView_125(r_io_debugView_125),.io_debugView_126(r_io_debugView_126),.io_debugView_127(r_io_debugView_127),.io_debugView_128(r_io_debugView_128),.io_debugView_129(r_io_debugView_129),.io_debugView_130(r_io_debugView_130),.io_debugView_131(r_io_debugView_131),.io_debugView_132(r_io_debugView_132),.io_debugView_133(r_io_debugView_133),.io_debugView_134(r_io_debugView_134),.io_debugView_135(r_io_debugView_135),.io_debugView_136(r_io_debugView_136),.io_debugView_137(r_io_debugView_137),.io_debugView_138(r_io_debugView_138),.io_debugView_139(r_io_debugView_139),.io_debugView_140(r_io_debugView_140),.io_debugView_141(r_io_debugView_141),.io_debugView_142(r_io_debugView_142),.io_debugView_143(r_io_debugView_143),.io_debugView_144(r_io_debugView_144),.io_debugView_145(r_io_debugView_145),.io_debugView_146(r_io_debugView_146),.io_debugView_147(r_io_debugView_147),.io_debugView_148(r_io_debugView_148),.io_debugView_149(r_io_debugView_149),.io_debugView_150(r_io_debugView_150),.io_debugView_151(r_io_debugView_151),.io_debugView_152(r_io_debugView_152),.io_debugView_153(r_io_debugView_153),.io_debugView_154(r_io_debugView_154),.io_debugView_155(r_io_debugView_155),.io_debugView_156(r_io_debugView_156),.io_debugView_157(r_io_debugView_157),.io_debugView_158(r_io_debugView_158),.io_debugView_159(r_io_debugView_159),.io_debugView_160(r_io_debugView_160),.io_debugView_161(r_io_debugView_161),.io_debugView_162(r_io_debugView_162),.io_debugView_163(r_io_debugView_163),.io_debugView_164(r_io_debugView_164),.io_debugView_165(r_io_debugView_165),.io_debugView_166(r_io_debugView_166),.io_debugView_167(r_io_debugView_167),.io_debugView_168(r_io_debugView_168),.io_debugView_169(r_io_debugView_169),.io_debugView_170(r_io_debugView_170),.io_debugView_171(r_io_debugView_171),.io_debugView_172(r_io_debugView_172),.io_debugView_173(r_io_debugView_173),.io_debugView_174(r_io_debugView_174),.io_debugView_175(r_io_debugView_175),.io_debugView_176(r_io_debugView_176),.io_debugView_177(r_io_debugView_177),.io_debugView_178(r_io_debugView_178),.io_debugView_179(r_io_debugView_179),.io_debugView_180(r_io_debugView_180),.io_debugView_181(r_io_debugView_181),.io_debugView_182(r_io_debugView_182),.io_debugView_183(r_io_debugView_183),.io_debugView_184(r_io_debugView_184),.io_debugView_185(r_io_debugView_185),.io_debugView_186(r_io_debugView_186),.io_debugView_187(r_io_debugView_187),.io_debugView_188(r_io_debugView_188),.io_debugView_189(r_io_debugView_189),.io_debugView_190(r_io_debugView_190),.io_debugView_191(r_io_debugView_191),.io_debugView_192(r_io_debugView_192),.io_debugView_193(r_io_debugView_193),.io_debugView_194(r_io_debugView_194),.io_debugView_195(r_io_debugView_195),.io_debugView_196(r_io_debugView_196),.io_debugView_197(r_io_debugView_197),.io_debugView_198(r_io_debugView_198),.io_debugView_199(r_io_debugView_199),.io_debugView_200(r_io_debugView_200),.io_debugView_201(r_io_debugView_201),.io_debugView_202(r_io_debugView_202),.io_debugView_203(r_io_debugView_203),.io_debugView_204(r_io_debugView_204),.io_debugView_205(r_io_debugView_205),.io_debugView_206(r_io_debugView_206),.io_debugView_207(r_io_debugView_207),.io_debugView_208(r_io_debugView_208),.io_debugView_209(r_io_debugView_209),.io_debugView_210(r_io_debugView_210),.io_debugView_211(r_io_debugView_211),.io_debugView_212(r_io_debugView_212),.io_debugView_213(r_io_debugView_213),.io_debugView_214(r_io_debugView_214),.io_debugView_215(r_io_debugView_215),.io_debugView_216(r_io_debugView_216),.io_debugView_217(r_io_debugView_217),.io_debugView_218(r_io_debugView_218),.io_debugView_219(r_io_debugView_219),.io_debugView_220(r_io_debugView_220),.io_debugView_221(r_io_debugView_221),.io_debugView_222(r_io_debugView_222),.io_debugView_223(r_io_debugView_223),.io_debugView_224(r_io_debugView_224),.io_debugView_225(r_io_debugView_225),.io_debugView_226(r_io_debugView_226),.io_debugView_227(r_io_debugView_227),.io_debugView_228(r_io_debugView_228),.io_debugView_229(r_io_debugView_229),.io_debugView_230(r_io_debugView_230),.io_debugView_231(r_io_debugView_231),.io_debugView_232(r_io_debugView_232),.io_debugView_233(r_io_debugView_233),.io_debugView_234(r_io_debugView_234),.io_debugView_235(r_io_debugView_235),.io_debugView_236(r_io_debugView_236),.io_debugView_237(r_io_debugView_237),.io_debugView_238(r_io_debugView_238),.io_debugView_239(r_io_debugView_239),.io_debugView_240(r_io_debugView_240),.io_debugView_241(r_io_debugView_241),.io_debugView_242(r_io_debugView_242),.io_debugView_243(r_io_debugView_243),.io_debugView_244(r_io_debugView_244),.io_debugView_245(r_io_debugView_245),.io_debugView_246(r_io_debugView_246),.io_debugView_247(r_io_debugView_247),.io_debugView_248(r_io_debugView_248),.io_debugView_249(r_io_debugView_249),.io_debugView_250(r_io_debugView_250),.io_debugView_251(r_io_debugView_251),.io_debugView_252(r_io_debugView_252),.io_debugView_253(r_io_debugView_253),.io_debugView_254(r_io_debugView_254),.io_debugView_255(r_io_debugView_255),.io_resolved(r_io_resolved),.io_pending(r_io_pending),.io_dropped(r_io_dropped),.io_requestCycleSum(r_io_requestCycleSum),.io_safeCycleSum(r_io_safeCycleSum),.io_statsValid(r_io_statsValid));
BarrierCandidate dutCandidate(.clock(clock),.reset(reset),.io_resetStats(io_resetStats),.io_event_valid(io_event_valid),.io_event_bits(io_event_bits),.io_safeWatermark(io_safeWatermark),.io_currentCycle(io_currentCycle),.io_fatalProtocolError(io_fatalProtocolError),.io_seen(c_io_seen),.io_debugView_0(c_io_debugView_0),.io_debugView_1(c_io_debugView_1),.io_debugView_2(c_io_debugView_2),.io_debugView_3(c_io_debugView_3),.io_debugView_4(c_io_debugView_4),.io_debugView_5(c_io_debugView_5),.io_debugView_6(c_io_debugView_6),.io_debugView_7(c_io_debugView_7),.io_debugView_8(c_io_debugView_8),.io_debugView_9(c_io_debugView_9),.io_debugView_10(c_io_debugView_10),.io_debugView_11(c_io_debugView_11),.io_debugView_12(c_io_debugView_12),.io_debugView_13(c_io_debugView_13),.io_debugView_14(c_io_debugView_14),.io_debugView_15(c_io_debugView_15),.io_debugView_16(c_io_debugView_16),.io_debugView_17(c_io_debugView_17),.io_debugView_18(c_io_debugView_18),.io_debugView_19(c_io_debugView_19),.io_debugView_20(c_io_debugView_20),.io_debugView_21(c_io_debugView_21),.io_debugView_22(c_io_debugView_22),.io_debugView_23(c_io_debugView_23),.io_debugView_24(c_io_debugView_24),.io_debugView_25(c_io_debugView_25),.io_debugView_26(c_io_debugView_26),.io_debugView_27(c_io_debugView_27),.io_debugView_28(c_io_debugView_28),.io_debugView_29(c_io_debugView_29),.io_debugView_30(c_io_debugView_30),.io_debugView_31(c_io_debugView_31),.io_debugView_32(c_io_debugView_32),.io_debugView_33(c_io_debugView_33),.io_debugView_34(c_io_debugView_34),.io_debugView_35(c_io_debugView_35),.io_debugView_36(c_io_debugView_36),.io_debugView_37(c_io_debugView_37),.io_debugView_38(c_io_debugView_38),.io_debugView_39(c_io_debugView_39),.io_debugView_40(c_io_debugView_40),.io_debugView_41(c_io_debugView_41),.io_debugView_42(c_io_debugView_42),.io_debugView_43(c_io_debugView_43),.io_debugView_44(c_io_debugView_44),.io_debugView_45(c_io_debugView_45),.io_debugView_46(c_io_debugView_46),.io_debugView_47(c_io_debugView_47),.io_debugView_48(c_io_debugView_48),.io_debugView_49(c_io_debugView_49),.io_debugView_50(c_io_debugView_50),.io_debugView_51(c_io_debugView_51),.io_debugView_52(c_io_debugView_52),.io_debugView_53(c_io_debugView_53),.io_debugView_54(c_io_debugView_54),.io_debugView_55(c_io_debugView_55),.io_debugView_56(c_io_debugView_56),.io_debugView_57(c_io_debugView_57),.io_debugView_58(c_io_debugView_58),.io_debugView_59(c_io_debugView_59),.io_debugView_60(c_io_debugView_60),.io_debugView_61(c_io_debugView_61),.io_debugView_62(c_io_debugView_62),.io_debugView_63(c_io_debugView_63),.io_debugView_64(c_io_debugView_64),.io_debugView_65(c_io_debugView_65),.io_debugView_66(c_io_debugView_66),.io_debugView_67(c_io_debugView_67),.io_debugView_68(c_io_debugView_68),.io_debugView_69(c_io_debugView_69),.io_debugView_70(c_io_debugView_70),.io_debugView_71(c_io_debugView_71),.io_debugView_72(c_io_debugView_72),.io_debugView_73(c_io_debugView_73),.io_debugView_74(c_io_debugView_74),.io_debugView_75(c_io_debugView_75),.io_debugView_76(c_io_debugView_76),.io_debugView_77(c_io_debugView_77),.io_debugView_78(c_io_debugView_78),.io_debugView_79(c_io_debugView_79),.io_debugView_80(c_io_debugView_80),.io_debugView_81(c_io_debugView_81),.io_debugView_82(c_io_debugView_82),.io_debugView_83(c_io_debugView_83),.io_debugView_84(c_io_debugView_84),.io_debugView_85(c_io_debugView_85),.io_debugView_86(c_io_debugView_86),.io_debugView_87(c_io_debugView_87),.io_debugView_88(c_io_debugView_88),.io_debugView_89(c_io_debugView_89),.io_debugView_90(c_io_debugView_90),.io_debugView_91(c_io_debugView_91),.io_debugView_92(c_io_debugView_92),.io_debugView_93(c_io_debugView_93),.io_debugView_94(c_io_debugView_94),.io_debugView_95(c_io_debugView_95),.io_debugView_96(c_io_debugView_96),.io_debugView_97(c_io_debugView_97),.io_debugView_98(c_io_debugView_98),.io_debugView_99(c_io_debugView_99),.io_debugView_100(c_io_debugView_100),.io_debugView_101(c_io_debugView_101),.io_debugView_102(c_io_debugView_102),.io_debugView_103(c_io_debugView_103),.io_debugView_104(c_io_debugView_104),.io_debugView_105(c_io_debugView_105),.io_debugView_106(c_io_debugView_106),.io_debugView_107(c_io_debugView_107),.io_debugView_108(c_io_debugView_108),.io_debugView_109(c_io_debugView_109),.io_debugView_110(c_io_debugView_110),.io_debugView_111(c_io_debugView_111),.io_debugView_112(c_io_debugView_112),.io_debugView_113(c_io_debugView_113),.io_debugView_114(c_io_debugView_114),.io_debugView_115(c_io_debugView_115),.io_debugView_116(c_io_debugView_116),.io_debugView_117(c_io_debugView_117),.io_debugView_118(c_io_debugView_118),.io_debugView_119(c_io_debugView_119),.io_debugView_120(c_io_debugView_120),.io_debugView_121(c_io_debugView_121),.io_debugView_122(c_io_debugView_122),.io_debugView_123(c_io_debugView_123),.io_debugView_124(c_io_debugView_124),.io_debugView_125(c_io_debugView_125),.io_debugView_126(c_io_debugView_126),.io_debugView_127(c_io_debugView_127),.io_debugView_128(c_io_debugView_128),.io_debugView_129(c_io_debugView_129),.io_debugView_130(c_io_debugView_130),.io_debugView_131(c_io_debugView_131),.io_debugView_132(c_io_debugView_132),.io_debugView_133(c_io_debugView_133),.io_debugView_134(c_io_debugView_134),.io_debugView_135(c_io_debugView_135),.io_debugView_136(c_io_debugView_136),.io_debugView_137(c_io_debugView_137),.io_debugView_138(c_io_debugView_138),.io_debugView_139(c_io_debugView_139),.io_debugView_140(c_io_debugView_140),.io_debugView_141(c_io_debugView_141),.io_debugView_142(c_io_debugView_142),.io_debugView_143(c_io_debugView_143),.io_debugView_144(c_io_debugView_144),.io_debugView_145(c_io_debugView_145),.io_debugView_146(c_io_debugView_146),.io_debugView_147(c_io_debugView_147),.io_debugView_148(c_io_debugView_148),.io_debugView_149(c_io_debugView_149),.io_debugView_150(c_io_debugView_150),.io_debugView_151(c_io_debugView_151),.io_debugView_152(c_io_debugView_152),.io_debugView_153(c_io_debugView_153),.io_debugView_154(c_io_debugView_154),.io_debugView_155(c_io_debugView_155),.io_debugView_156(c_io_debugView_156),.io_debugView_157(c_io_debugView_157),.io_debugView_158(c_io_debugView_158),.io_debugView_159(c_io_debugView_159),.io_debugView_160(c_io_debugView_160),.io_debugView_161(c_io_debugView_161),.io_debugView_162(c_io_debugView_162),.io_debugView_163(c_io_debugView_163),.io_debugView_164(c_io_debugView_164),.io_debugView_165(c_io_debugView_165),.io_debugView_166(c_io_debugView_166),.io_debugView_167(c_io_debugView_167),.io_debugView_168(c_io_debugView_168),.io_debugView_169(c_io_debugView_169),.io_debugView_170(c_io_debugView_170),.io_debugView_171(c_io_debugView_171),.io_debugView_172(c_io_debugView_172),.io_debugView_173(c_io_debugView_173),.io_debugView_174(c_io_debugView_174),.io_debugView_175(c_io_debugView_175),.io_debugView_176(c_io_debugView_176),.io_debugView_177(c_io_debugView_177),.io_debugView_178(c_io_debugView_178),.io_debugView_179(c_io_debugView_179),.io_debugView_180(c_io_debugView_180),.io_debugView_181(c_io_debugView_181),.io_debugView_182(c_io_debugView_182),.io_debugView_183(c_io_debugView_183),.io_debugView_184(c_io_debugView_184),.io_debugView_185(c_io_debugView_185),.io_debugView_186(c_io_debugView_186),.io_debugView_187(c_io_debugView_187),.io_debugView_188(c_io_debugView_188),.io_debugView_189(c_io_debugView_189),.io_debugView_190(c_io_debugView_190),.io_debugView_191(c_io_debugView_191),.io_debugView_192(c_io_debugView_192),.io_debugView_193(c_io_debugView_193),.io_debugView_194(c_io_debugView_194),.io_debugView_195(c_io_debugView_195),.io_debugView_196(c_io_debugView_196),.io_debugView_197(c_io_debugView_197),.io_debugView_198(c_io_debugView_198),.io_debugView_199(c_io_debugView_199),.io_debugView_200(c_io_debugView_200),.io_debugView_201(c_io_debugView_201),.io_debugView_202(c_io_debugView_202),.io_debugView_203(c_io_debugView_203),.io_debugView_204(c_io_debugView_204),.io_debugView_205(c_io_debugView_205),.io_debugView_206(c_io_debugView_206),.io_debugView_207(c_io_debugView_207),.io_debugView_208(c_io_debugView_208),.io_debugView_209(c_io_debugView_209),.io_debugView_210(c_io_debugView_210),.io_debugView_211(c_io_debugView_211),.io_debugView_212(c_io_debugView_212),.io_debugView_213(c_io_debugView_213),.io_debugView_214(c_io_debugView_214),.io_debugView_215(c_io_debugView_215),.io_debugView_216(c_io_debugView_216),.io_debugView_217(c_io_debugView_217),.io_debugView_218(c_io_debugView_218),.io_debugView_219(c_io_debugView_219),.io_debugView_220(c_io_debugView_220),.io_debugView_221(c_io_debugView_221),.io_debugView_222(c_io_debugView_222),.io_debugView_223(c_io_debugView_223),.io_debugView_224(c_io_debugView_224),.io_debugView_225(c_io_debugView_225),.io_debugView_226(c_io_debugView_226),.io_debugView_227(c_io_debugView_227),.io_debugView_228(c_io_debugView_228),.io_debugView_229(c_io_debugView_229),.io_debugView_230(c_io_debugView_230),.io_debugView_231(c_io_debugView_231),.io_debugView_232(c_io_debugView_232),.io_debugView_233(c_io_debugView_233),.io_debugView_234(c_io_debugView_234),.io_debugView_235(c_io_debugView_235),.io_debugView_236(c_io_debugView_236),.io_debugView_237(c_io_debugView_237),.io_debugView_238(c_io_debugView_238),.io_debugView_239(c_io_debugView_239),.io_debugView_240(c_io_debugView_240),.io_debugView_241(c_io_debugView_241),.io_debugView_242(c_io_debugView_242),.io_debugView_243(c_io_debugView_243),.io_debugView_244(c_io_debugView_244),.io_debugView_245(c_io_debugView_245),.io_debugView_246(c_io_debugView_246),.io_debugView_247(c_io_debugView_247),.io_debugView_248(c_io_debugView_248),.io_debugView_249(c_io_debugView_249),.io_debugView_250(c_io_debugView_250),.io_debugView_251(c_io_debugView_251),.io_debugView_252(c_io_debugView_252),.io_debugView_253(c_io_debugView_253),.io_debugView_254(c_io_debugView_254),.io_debugView_255(c_io_debugView_255),.io_resolved(c_io_resolved),.io_pending(c_io_pending),.io_dropped(c_io_dropped),.io_requestCycleSum(c_io_requestCycleSum),.io_safeCycleSum(c_io_safeCycleSum),.io_statsValid(c_io_statsValid));
task check;
begin
if (r_io_seen !== c_io_seen) begin $display("BARRIER_MISMATCH port=io_seen cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_0 !== c_io_debugView_0) begin $display("BARRIER_MISMATCH port=io_debugView_0 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_1 !== c_io_debugView_1) begin $display("BARRIER_MISMATCH port=io_debugView_1 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_2 !== c_io_debugView_2) begin $display("BARRIER_MISMATCH port=io_debugView_2 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_3 !== c_io_debugView_3) begin $display("BARRIER_MISMATCH port=io_debugView_3 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_4 !== c_io_debugView_4) begin $display("BARRIER_MISMATCH port=io_debugView_4 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_5 !== c_io_debugView_5) begin $display("BARRIER_MISMATCH port=io_debugView_5 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_6 !== c_io_debugView_6) begin $display("BARRIER_MISMATCH port=io_debugView_6 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_7 !== c_io_debugView_7) begin $display("BARRIER_MISMATCH port=io_debugView_7 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_8 !== c_io_debugView_8) begin $display("BARRIER_MISMATCH port=io_debugView_8 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_9 !== c_io_debugView_9) begin $display("BARRIER_MISMATCH port=io_debugView_9 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_10 !== c_io_debugView_10) begin $display("BARRIER_MISMATCH port=io_debugView_10 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_11 !== c_io_debugView_11) begin $display("BARRIER_MISMATCH port=io_debugView_11 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_12 !== c_io_debugView_12) begin $display("BARRIER_MISMATCH port=io_debugView_12 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_13 !== c_io_debugView_13) begin $display("BARRIER_MISMATCH port=io_debugView_13 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_14 !== c_io_debugView_14) begin $display("BARRIER_MISMATCH port=io_debugView_14 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_15 !== c_io_debugView_15) begin $display("BARRIER_MISMATCH port=io_debugView_15 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_16 !== c_io_debugView_16) begin $display("BARRIER_MISMATCH port=io_debugView_16 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_17 !== c_io_debugView_17) begin $display("BARRIER_MISMATCH port=io_debugView_17 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_18 !== c_io_debugView_18) begin $display("BARRIER_MISMATCH port=io_debugView_18 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_19 !== c_io_debugView_19) begin $display("BARRIER_MISMATCH port=io_debugView_19 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_20 !== c_io_debugView_20) begin $display("BARRIER_MISMATCH port=io_debugView_20 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_21 !== c_io_debugView_21) begin $display("BARRIER_MISMATCH port=io_debugView_21 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_22 !== c_io_debugView_22) begin $display("BARRIER_MISMATCH port=io_debugView_22 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_23 !== c_io_debugView_23) begin $display("BARRIER_MISMATCH port=io_debugView_23 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_24 !== c_io_debugView_24) begin $display("BARRIER_MISMATCH port=io_debugView_24 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_25 !== c_io_debugView_25) begin $display("BARRIER_MISMATCH port=io_debugView_25 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_26 !== c_io_debugView_26) begin $display("BARRIER_MISMATCH port=io_debugView_26 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_27 !== c_io_debugView_27) begin $display("BARRIER_MISMATCH port=io_debugView_27 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_28 !== c_io_debugView_28) begin $display("BARRIER_MISMATCH port=io_debugView_28 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_29 !== c_io_debugView_29) begin $display("BARRIER_MISMATCH port=io_debugView_29 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_30 !== c_io_debugView_30) begin $display("BARRIER_MISMATCH port=io_debugView_30 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_31 !== c_io_debugView_31) begin $display("BARRIER_MISMATCH port=io_debugView_31 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_32 !== c_io_debugView_32) begin $display("BARRIER_MISMATCH port=io_debugView_32 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_33 !== c_io_debugView_33) begin $display("BARRIER_MISMATCH port=io_debugView_33 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_34 !== c_io_debugView_34) begin $display("BARRIER_MISMATCH port=io_debugView_34 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_35 !== c_io_debugView_35) begin $display("BARRIER_MISMATCH port=io_debugView_35 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_36 !== c_io_debugView_36) begin $display("BARRIER_MISMATCH port=io_debugView_36 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_37 !== c_io_debugView_37) begin $display("BARRIER_MISMATCH port=io_debugView_37 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_38 !== c_io_debugView_38) begin $display("BARRIER_MISMATCH port=io_debugView_38 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_39 !== c_io_debugView_39) begin $display("BARRIER_MISMATCH port=io_debugView_39 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_40 !== c_io_debugView_40) begin $display("BARRIER_MISMATCH port=io_debugView_40 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_41 !== c_io_debugView_41) begin $display("BARRIER_MISMATCH port=io_debugView_41 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_42 !== c_io_debugView_42) begin $display("BARRIER_MISMATCH port=io_debugView_42 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_43 !== c_io_debugView_43) begin $display("BARRIER_MISMATCH port=io_debugView_43 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_44 !== c_io_debugView_44) begin $display("BARRIER_MISMATCH port=io_debugView_44 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_45 !== c_io_debugView_45) begin $display("BARRIER_MISMATCH port=io_debugView_45 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_46 !== c_io_debugView_46) begin $display("BARRIER_MISMATCH port=io_debugView_46 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_47 !== c_io_debugView_47) begin $display("BARRIER_MISMATCH port=io_debugView_47 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_48 !== c_io_debugView_48) begin $display("BARRIER_MISMATCH port=io_debugView_48 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_49 !== c_io_debugView_49) begin $display("BARRIER_MISMATCH port=io_debugView_49 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_50 !== c_io_debugView_50) begin $display("BARRIER_MISMATCH port=io_debugView_50 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_51 !== c_io_debugView_51) begin $display("BARRIER_MISMATCH port=io_debugView_51 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_52 !== c_io_debugView_52) begin $display("BARRIER_MISMATCH port=io_debugView_52 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_53 !== c_io_debugView_53) begin $display("BARRIER_MISMATCH port=io_debugView_53 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_54 !== c_io_debugView_54) begin $display("BARRIER_MISMATCH port=io_debugView_54 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_55 !== c_io_debugView_55) begin $display("BARRIER_MISMATCH port=io_debugView_55 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_56 !== c_io_debugView_56) begin $display("BARRIER_MISMATCH port=io_debugView_56 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_57 !== c_io_debugView_57) begin $display("BARRIER_MISMATCH port=io_debugView_57 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_58 !== c_io_debugView_58) begin $display("BARRIER_MISMATCH port=io_debugView_58 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_59 !== c_io_debugView_59) begin $display("BARRIER_MISMATCH port=io_debugView_59 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_60 !== c_io_debugView_60) begin $display("BARRIER_MISMATCH port=io_debugView_60 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_61 !== c_io_debugView_61) begin $display("BARRIER_MISMATCH port=io_debugView_61 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_62 !== c_io_debugView_62) begin $display("BARRIER_MISMATCH port=io_debugView_62 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_63 !== c_io_debugView_63) begin $display("BARRIER_MISMATCH port=io_debugView_63 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_64 !== c_io_debugView_64) begin $display("BARRIER_MISMATCH port=io_debugView_64 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_65 !== c_io_debugView_65) begin $display("BARRIER_MISMATCH port=io_debugView_65 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_66 !== c_io_debugView_66) begin $display("BARRIER_MISMATCH port=io_debugView_66 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_67 !== c_io_debugView_67) begin $display("BARRIER_MISMATCH port=io_debugView_67 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_68 !== c_io_debugView_68) begin $display("BARRIER_MISMATCH port=io_debugView_68 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_69 !== c_io_debugView_69) begin $display("BARRIER_MISMATCH port=io_debugView_69 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_70 !== c_io_debugView_70) begin $display("BARRIER_MISMATCH port=io_debugView_70 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_71 !== c_io_debugView_71) begin $display("BARRIER_MISMATCH port=io_debugView_71 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_72 !== c_io_debugView_72) begin $display("BARRIER_MISMATCH port=io_debugView_72 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_73 !== c_io_debugView_73) begin $display("BARRIER_MISMATCH port=io_debugView_73 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_74 !== c_io_debugView_74) begin $display("BARRIER_MISMATCH port=io_debugView_74 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_75 !== c_io_debugView_75) begin $display("BARRIER_MISMATCH port=io_debugView_75 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_76 !== c_io_debugView_76) begin $display("BARRIER_MISMATCH port=io_debugView_76 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_77 !== c_io_debugView_77) begin $display("BARRIER_MISMATCH port=io_debugView_77 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_78 !== c_io_debugView_78) begin $display("BARRIER_MISMATCH port=io_debugView_78 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_79 !== c_io_debugView_79) begin $display("BARRIER_MISMATCH port=io_debugView_79 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_80 !== c_io_debugView_80) begin $display("BARRIER_MISMATCH port=io_debugView_80 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_81 !== c_io_debugView_81) begin $display("BARRIER_MISMATCH port=io_debugView_81 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_82 !== c_io_debugView_82) begin $display("BARRIER_MISMATCH port=io_debugView_82 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_83 !== c_io_debugView_83) begin $display("BARRIER_MISMATCH port=io_debugView_83 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_84 !== c_io_debugView_84) begin $display("BARRIER_MISMATCH port=io_debugView_84 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_85 !== c_io_debugView_85) begin $display("BARRIER_MISMATCH port=io_debugView_85 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_86 !== c_io_debugView_86) begin $display("BARRIER_MISMATCH port=io_debugView_86 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_87 !== c_io_debugView_87) begin $display("BARRIER_MISMATCH port=io_debugView_87 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_88 !== c_io_debugView_88) begin $display("BARRIER_MISMATCH port=io_debugView_88 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_89 !== c_io_debugView_89) begin $display("BARRIER_MISMATCH port=io_debugView_89 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_90 !== c_io_debugView_90) begin $display("BARRIER_MISMATCH port=io_debugView_90 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_91 !== c_io_debugView_91) begin $display("BARRIER_MISMATCH port=io_debugView_91 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_92 !== c_io_debugView_92) begin $display("BARRIER_MISMATCH port=io_debugView_92 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_93 !== c_io_debugView_93) begin $display("BARRIER_MISMATCH port=io_debugView_93 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_94 !== c_io_debugView_94) begin $display("BARRIER_MISMATCH port=io_debugView_94 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_95 !== c_io_debugView_95) begin $display("BARRIER_MISMATCH port=io_debugView_95 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_96 !== c_io_debugView_96) begin $display("BARRIER_MISMATCH port=io_debugView_96 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_97 !== c_io_debugView_97) begin $display("BARRIER_MISMATCH port=io_debugView_97 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_98 !== c_io_debugView_98) begin $display("BARRIER_MISMATCH port=io_debugView_98 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_99 !== c_io_debugView_99) begin $display("BARRIER_MISMATCH port=io_debugView_99 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_100 !== c_io_debugView_100) begin $display("BARRIER_MISMATCH port=io_debugView_100 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_101 !== c_io_debugView_101) begin $display("BARRIER_MISMATCH port=io_debugView_101 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_102 !== c_io_debugView_102) begin $display("BARRIER_MISMATCH port=io_debugView_102 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_103 !== c_io_debugView_103) begin $display("BARRIER_MISMATCH port=io_debugView_103 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_104 !== c_io_debugView_104) begin $display("BARRIER_MISMATCH port=io_debugView_104 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_105 !== c_io_debugView_105) begin $display("BARRIER_MISMATCH port=io_debugView_105 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_106 !== c_io_debugView_106) begin $display("BARRIER_MISMATCH port=io_debugView_106 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_107 !== c_io_debugView_107) begin $display("BARRIER_MISMATCH port=io_debugView_107 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_108 !== c_io_debugView_108) begin $display("BARRIER_MISMATCH port=io_debugView_108 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_109 !== c_io_debugView_109) begin $display("BARRIER_MISMATCH port=io_debugView_109 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_110 !== c_io_debugView_110) begin $display("BARRIER_MISMATCH port=io_debugView_110 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_111 !== c_io_debugView_111) begin $display("BARRIER_MISMATCH port=io_debugView_111 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_112 !== c_io_debugView_112) begin $display("BARRIER_MISMATCH port=io_debugView_112 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_113 !== c_io_debugView_113) begin $display("BARRIER_MISMATCH port=io_debugView_113 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_114 !== c_io_debugView_114) begin $display("BARRIER_MISMATCH port=io_debugView_114 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_115 !== c_io_debugView_115) begin $display("BARRIER_MISMATCH port=io_debugView_115 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_116 !== c_io_debugView_116) begin $display("BARRIER_MISMATCH port=io_debugView_116 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_117 !== c_io_debugView_117) begin $display("BARRIER_MISMATCH port=io_debugView_117 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_118 !== c_io_debugView_118) begin $display("BARRIER_MISMATCH port=io_debugView_118 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_119 !== c_io_debugView_119) begin $display("BARRIER_MISMATCH port=io_debugView_119 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_120 !== c_io_debugView_120) begin $display("BARRIER_MISMATCH port=io_debugView_120 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_121 !== c_io_debugView_121) begin $display("BARRIER_MISMATCH port=io_debugView_121 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_122 !== c_io_debugView_122) begin $display("BARRIER_MISMATCH port=io_debugView_122 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_123 !== c_io_debugView_123) begin $display("BARRIER_MISMATCH port=io_debugView_123 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_124 !== c_io_debugView_124) begin $display("BARRIER_MISMATCH port=io_debugView_124 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_125 !== c_io_debugView_125) begin $display("BARRIER_MISMATCH port=io_debugView_125 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_126 !== c_io_debugView_126) begin $display("BARRIER_MISMATCH port=io_debugView_126 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_127 !== c_io_debugView_127) begin $display("BARRIER_MISMATCH port=io_debugView_127 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_128 !== c_io_debugView_128) begin $display("BARRIER_MISMATCH port=io_debugView_128 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_129 !== c_io_debugView_129) begin $display("BARRIER_MISMATCH port=io_debugView_129 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_130 !== c_io_debugView_130) begin $display("BARRIER_MISMATCH port=io_debugView_130 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_131 !== c_io_debugView_131) begin $display("BARRIER_MISMATCH port=io_debugView_131 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_132 !== c_io_debugView_132) begin $display("BARRIER_MISMATCH port=io_debugView_132 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_133 !== c_io_debugView_133) begin $display("BARRIER_MISMATCH port=io_debugView_133 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_134 !== c_io_debugView_134) begin $display("BARRIER_MISMATCH port=io_debugView_134 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_135 !== c_io_debugView_135) begin $display("BARRIER_MISMATCH port=io_debugView_135 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_136 !== c_io_debugView_136) begin $display("BARRIER_MISMATCH port=io_debugView_136 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_137 !== c_io_debugView_137) begin $display("BARRIER_MISMATCH port=io_debugView_137 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_138 !== c_io_debugView_138) begin $display("BARRIER_MISMATCH port=io_debugView_138 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_139 !== c_io_debugView_139) begin $display("BARRIER_MISMATCH port=io_debugView_139 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_140 !== c_io_debugView_140) begin $display("BARRIER_MISMATCH port=io_debugView_140 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_141 !== c_io_debugView_141) begin $display("BARRIER_MISMATCH port=io_debugView_141 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_142 !== c_io_debugView_142) begin $display("BARRIER_MISMATCH port=io_debugView_142 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_143 !== c_io_debugView_143) begin $display("BARRIER_MISMATCH port=io_debugView_143 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_144 !== c_io_debugView_144) begin $display("BARRIER_MISMATCH port=io_debugView_144 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_145 !== c_io_debugView_145) begin $display("BARRIER_MISMATCH port=io_debugView_145 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_146 !== c_io_debugView_146) begin $display("BARRIER_MISMATCH port=io_debugView_146 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_147 !== c_io_debugView_147) begin $display("BARRIER_MISMATCH port=io_debugView_147 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_148 !== c_io_debugView_148) begin $display("BARRIER_MISMATCH port=io_debugView_148 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_149 !== c_io_debugView_149) begin $display("BARRIER_MISMATCH port=io_debugView_149 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_150 !== c_io_debugView_150) begin $display("BARRIER_MISMATCH port=io_debugView_150 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_151 !== c_io_debugView_151) begin $display("BARRIER_MISMATCH port=io_debugView_151 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_152 !== c_io_debugView_152) begin $display("BARRIER_MISMATCH port=io_debugView_152 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_153 !== c_io_debugView_153) begin $display("BARRIER_MISMATCH port=io_debugView_153 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_154 !== c_io_debugView_154) begin $display("BARRIER_MISMATCH port=io_debugView_154 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_155 !== c_io_debugView_155) begin $display("BARRIER_MISMATCH port=io_debugView_155 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_156 !== c_io_debugView_156) begin $display("BARRIER_MISMATCH port=io_debugView_156 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_157 !== c_io_debugView_157) begin $display("BARRIER_MISMATCH port=io_debugView_157 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_158 !== c_io_debugView_158) begin $display("BARRIER_MISMATCH port=io_debugView_158 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_159 !== c_io_debugView_159) begin $display("BARRIER_MISMATCH port=io_debugView_159 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_160 !== c_io_debugView_160) begin $display("BARRIER_MISMATCH port=io_debugView_160 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_161 !== c_io_debugView_161) begin $display("BARRIER_MISMATCH port=io_debugView_161 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_162 !== c_io_debugView_162) begin $display("BARRIER_MISMATCH port=io_debugView_162 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_163 !== c_io_debugView_163) begin $display("BARRIER_MISMATCH port=io_debugView_163 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_164 !== c_io_debugView_164) begin $display("BARRIER_MISMATCH port=io_debugView_164 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_165 !== c_io_debugView_165) begin $display("BARRIER_MISMATCH port=io_debugView_165 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_166 !== c_io_debugView_166) begin $display("BARRIER_MISMATCH port=io_debugView_166 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_167 !== c_io_debugView_167) begin $display("BARRIER_MISMATCH port=io_debugView_167 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_168 !== c_io_debugView_168) begin $display("BARRIER_MISMATCH port=io_debugView_168 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_169 !== c_io_debugView_169) begin $display("BARRIER_MISMATCH port=io_debugView_169 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_170 !== c_io_debugView_170) begin $display("BARRIER_MISMATCH port=io_debugView_170 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_171 !== c_io_debugView_171) begin $display("BARRIER_MISMATCH port=io_debugView_171 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_172 !== c_io_debugView_172) begin $display("BARRIER_MISMATCH port=io_debugView_172 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_173 !== c_io_debugView_173) begin $display("BARRIER_MISMATCH port=io_debugView_173 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_174 !== c_io_debugView_174) begin $display("BARRIER_MISMATCH port=io_debugView_174 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_175 !== c_io_debugView_175) begin $display("BARRIER_MISMATCH port=io_debugView_175 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_176 !== c_io_debugView_176) begin $display("BARRIER_MISMATCH port=io_debugView_176 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_177 !== c_io_debugView_177) begin $display("BARRIER_MISMATCH port=io_debugView_177 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_178 !== c_io_debugView_178) begin $display("BARRIER_MISMATCH port=io_debugView_178 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_179 !== c_io_debugView_179) begin $display("BARRIER_MISMATCH port=io_debugView_179 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_180 !== c_io_debugView_180) begin $display("BARRIER_MISMATCH port=io_debugView_180 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_181 !== c_io_debugView_181) begin $display("BARRIER_MISMATCH port=io_debugView_181 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_182 !== c_io_debugView_182) begin $display("BARRIER_MISMATCH port=io_debugView_182 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_183 !== c_io_debugView_183) begin $display("BARRIER_MISMATCH port=io_debugView_183 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_184 !== c_io_debugView_184) begin $display("BARRIER_MISMATCH port=io_debugView_184 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_185 !== c_io_debugView_185) begin $display("BARRIER_MISMATCH port=io_debugView_185 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_186 !== c_io_debugView_186) begin $display("BARRIER_MISMATCH port=io_debugView_186 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_187 !== c_io_debugView_187) begin $display("BARRIER_MISMATCH port=io_debugView_187 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_188 !== c_io_debugView_188) begin $display("BARRIER_MISMATCH port=io_debugView_188 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_189 !== c_io_debugView_189) begin $display("BARRIER_MISMATCH port=io_debugView_189 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_190 !== c_io_debugView_190) begin $display("BARRIER_MISMATCH port=io_debugView_190 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_191 !== c_io_debugView_191) begin $display("BARRIER_MISMATCH port=io_debugView_191 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_192 !== c_io_debugView_192) begin $display("BARRIER_MISMATCH port=io_debugView_192 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_193 !== c_io_debugView_193) begin $display("BARRIER_MISMATCH port=io_debugView_193 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_194 !== c_io_debugView_194) begin $display("BARRIER_MISMATCH port=io_debugView_194 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_195 !== c_io_debugView_195) begin $display("BARRIER_MISMATCH port=io_debugView_195 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_196 !== c_io_debugView_196) begin $display("BARRIER_MISMATCH port=io_debugView_196 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_197 !== c_io_debugView_197) begin $display("BARRIER_MISMATCH port=io_debugView_197 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_198 !== c_io_debugView_198) begin $display("BARRIER_MISMATCH port=io_debugView_198 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_199 !== c_io_debugView_199) begin $display("BARRIER_MISMATCH port=io_debugView_199 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_200 !== c_io_debugView_200) begin $display("BARRIER_MISMATCH port=io_debugView_200 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_201 !== c_io_debugView_201) begin $display("BARRIER_MISMATCH port=io_debugView_201 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_202 !== c_io_debugView_202) begin $display("BARRIER_MISMATCH port=io_debugView_202 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_203 !== c_io_debugView_203) begin $display("BARRIER_MISMATCH port=io_debugView_203 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_204 !== c_io_debugView_204) begin $display("BARRIER_MISMATCH port=io_debugView_204 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_205 !== c_io_debugView_205) begin $display("BARRIER_MISMATCH port=io_debugView_205 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_206 !== c_io_debugView_206) begin $display("BARRIER_MISMATCH port=io_debugView_206 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_207 !== c_io_debugView_207) begin $display("BARRIER_MISMATCH port=io_debugView_207 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_208 !== c_io_debugView_208) begin $display("BARRIER_MISMATCH port=io_debugView_208 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_209 !== c_io_debugView_209) begin $display("BARRIER_MISMATCH port=io_debugView_209 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_210 !== c_io_debugView_210) begin $display("BARRIER_MISMATCH port=io_debugView_210 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_211 !== c_io_debugView_211) begin $display("BARRIER_MISMATCH port=io_debugView_211 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_212 !== c_io_debugView_212) begin $display("BARRIER_MISMATCH port=io_debugView_212 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_213 !== c_io_debugView_213) begin $display("BARRIER_MISMATCH port=io_debugView_213 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_214 !== c_io_debugView_214) begin $display("BARRIER_MISMATCH port=io_debugView_214 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_215 !== c_io_debugView_215) begin $display("BARRIER_MISMATCH port=io_debugView_215 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_216 !== c_io_debugView_216) begin $display("BARRIER_MISMATCH port=io_debugView_216 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_217 !== c_io_debugView_217) begin $display("BARRIER_MISMATCH port=io_debugView_217 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_218 !== c_io_debugView_218) begin $display("BARRIER_MISMATCH port=io_debugView_218 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_219 !== c_io_debugView_219) begin $display("BARRIER_MISMATCH port=io_debugView_219 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_220 !== c_io_debugView_220) begin $display("BARRIER_MISMATCH port=io_debugView_220 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_221 !== c_io_debugView_221) begin $display("BARRIER_MISMATCH port=io_debugView_221 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_222 !== c_io_debugView_222) begin $display("BARRIER_MISMATCH port=io_debugView_222 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_223 !== c_io_debugView_223) begin $display("BARRIER_MISMATCH port=io_debugView_223 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_224 !== c_io_debugView_224) begin $display("BARRIER_MISMATCH port=io_debugView_224 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_225 !== c_io_debugView_225) begin $display("BARRIER_MISMATCH port=io_debugView_225 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_226 !== c_io_debugView_226) begin $display("BARRIER_MISMATCH port=io_debugView_226 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_227 !== c_io_debugView_227) begin $display("BARRIER_MISMATCH port=io_debugView_227 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_228 !== c_io_debugView_228) begin $display("BARRIER_MISMATCH port=io_debugView_228 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_229 !== c_io_debugView_229) begin $display("BARRIER_MISMATCH port=io_debugView_229 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_230 !== c_io_debugView_230) begin $display("BARRIER_MISMATCH port=io_debugView_230 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_231 !== c_io_debugView_231) begin $display("BARRIER_MISMATCH port=io_debugView_231 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_232 !== c_io_debugView_232) begin $display("BARRIER_MISMATCH port=io_debugView_232 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_233 !== c_io_debugView_233) begin $display("BARRIER_MISMATCH port=io_debugView_233 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_234 !== c_io_debugView_234) begin $display("BARRIER_MISMATCH port=io_debugView_234 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_235 !== c_io_debugView_235) begin $display("BARRIER_MISMATCH port=io_debugView_235 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_236 !== c_io_debugView_236) begin $display("BARRIER_MISMATCH port=io_debugView_236 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_237 !== c_io_debugView_237) begin $display("BARRIER_MISMATCH port=io_debugView_237 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_238 !== c_io_debugView_238) begin $display("BARRIER_MISMATCH port=io_debugView_238 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_239 !== c_io_debugView_239) begin $display("BARRIER_MISMATCH port=io_debugView_239 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_240 !== c_io_debugView_240) begin $display("BARRIER_MISMATCH port=io_debugView_240 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_241 !== c_io_debugView_241) begin $display("BARRIER_MISMATCH port=io_debugView_241 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_242 !== c_io_debugView_242) begin $display("BARRIER_MISMATCH port=io_debugView_242 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_243 !== c_io_debugView_243) begin $display("BARRIER_MISMATCH port=io_debugView_243 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_244 !== c_io_debugView_244) begin $display("BARRIER_MISMATCH port=io_debugView_244 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_245 !== c_io_debugView_245) begin $display("BARRIER_MISMATCH port=io_debugView_245 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_246 !== c_io_debugView_246) begin $display("BARRIER_MISMATCH port=io_debugView_246 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_247 !== c_io_debugView_247) begin $display("BARRIER_MISMATCH port=io_debugView_247 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_248 !== c_io_debugView_248) begin $display("BARRIER_MISMATCH port=io_debugView_248 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_249 !== c_io_debugView_249) begin $display("BARRIER_MISMATCH port=io_debugView_249 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_250 !== c_io_debugView_250) begin $display("BARRIER_MISMATCH port=io_debugView_250 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_251 !== c_io_debugView_251) begin $display("BARRIER_MISMATCH port=io_debugView_251 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_252 !== c_io_debugView_252) begin $display("BARRIER_MISMATCH port=io_debugView_252 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_253 !== c_io_debugView_253) begin $display("BARRIER_MISMATCH port=io_debugView_253 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_254 !== c_io_debugView_254) begin $display("BARRIER_MISMATCH port=io_debugView_254 cycle=%0d",cycle); $fatal(1); end
if (r_io_debugView_255 !== c_io_debugView_255) begin $display("BARRIER_MISMATCH port=io_debugView_255 cycle=%0d",cycle); $fatal(1); end
if (r_io_resolved !== c_io_resolved) begin $display("BARRIER_MISMATCH port=io_resolved cycle=%0d",cycle); $fatal(1); end
if (r_io_pending !== c_io_pending) begin $display("BARRIER_MISMATCH port=io_pending cycle=%0d",cycle); $fatal(1); end
if (r_io_dropped !== c_io_dropped) begin $display("BARRIER_MISMATCH port=io_dropped cycle=%0d",cycle); $fatal(1); end
if (r_io_requestCycleSum !== c_io_requestCycleSum) begin $display("BARRIER_MISMATCH port=io_requestCycleSum cycle=%0d",cycle); $fatal(1); end
if (r_io_safeCycleSum !== c_io_safeCycleSum) begin $display("BARRIER_MISMATCH port=io_safeCycleSum cycle=%0d",cycle); $fatal(1); end
if (r_io_statsValid !== c_io_statsValid) begin $display("BARRIER_MISMATCH port=io_statsValid cycle=%0d",cycle); $fatal(1); end
end
endtask
initial begin
clock = '0;
reset = '0;
io_resetStats = '0;
io_event_valid = '0;
io_event_bits = '0;
io_safeWatermark = '0;
io_currentCycle = '0;
io_fatalProtocolError = '0;
reset=1;
#1; clock=1; #1; clock=0; #1;
for(cycle=0;cycle<8192;cycle=cycle+1) begin
rng=rng^(rng<<13); rng=rng^(rng>>7); rng=rng^(rng<<17);
reset=(cycle==3072 || cycle==6144);
io_resetStats=(cycle==2048 || cycle==4096 || cycle==7168);
io_event_valid=(rng[3:0]!=0);
io_event_bits={20'd0,rng[11:0]};
io_safeWatermark={20'd0,rng[23:12]};
io_currentCycle=(cycle<4096)?(64'd100000+cycle):rng;
io_fatalProtocolError=(cycle==6000);
if(cycle<512) begin io_safeWatermark=0; io_event_bits=1+(cycle%255); io_currentCycle=cycle; end
if(cycle>=512 && cycle<768) begin io_safeWatermark=cycle-511; io_event_bits=cycle-255; end
#1; check; clock=1; #1; clock=0; #1;
if ($test$plusargs("EC_MUTATE") && cycle==1000) begin
force dutCandidate.seen = 64'hdeadbeef12345678; #1; end
check;
end
$display("BARRIER_COMPLETE_MODULE_PARITY_PASS cycles=8192 outputs=263"); $finish;
end
endmodule
