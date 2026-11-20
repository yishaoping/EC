#include "VTagCompressProbe.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
static uint64_t rng=0x9e3779b97f4a7c15ULL;
static uint64_t random64(){rng^=rng<<13;rng^=rng>>7;rng^=rng<<17;return rng;}
static void fail(unsigned t,unsigned q){std::fprintf(stderr,"TAG_COMPRESS_FAIL vector=%u query=%u\n",t,q);std::exit(1);}
int main(int argc,char**argv){
Verilated::commandArgs(argc,argv);VTagCompressProbe dut;
uint8_t* valid[256]={&dut.io_valid_0,&dut.io_valid_1,&dut.io_valid_2,&dut.io_valid_3,&dut.io_valid_4,&dut.io_valid_5,&dut.io_valid_6,&dut.io_valid_7,&dut.io_valid_8,&dut.io_valid_9,&dut.io_valid_10,&dut.io_valid_11,&dut.io_valid_12,&dut.io_valid_13,&dut.io_valid_14,&dut.io_valid_15,&dut.io_valid_16,&dut.io_valid_17,&dut.io_valid_18,&dut.io_valid_19,&dut.io_valid_20,&dut.io_valid_21,&dut.io_valid_22,&dut.io_valid_23,&dut.io_valid_24,&dut.io_valid_25,&dut.io_valid_26,&dut.io_valid_27,&dut.io_valid_28,&dut.io_valid_29,&dut.io_valid_30,&dut.io_valid_31,&dut.io_valid_32,&dut.io_valid_33,&dut.io_valid_34,&dut.io_valid_35,&dut.io_valid_36,&dut.io_valid_37,&dut.io_valid_38,&dut.io_valid_39,&dut.io_valid_40,&dut.io_valid_41,&dut.io_valid_42,&dut.io_valid_43,&dut.io_valid_44,&dut.io_valid_45,&dut.io_valid_46,&dut.io_valid_47,&dut.io_valid_48,&dut.io_valid_49,&dut.io_valid_50,&dut.io_valid_51,&dut.io_valid_52,&dut.io_valid_53,&dut.io_valid_54,&dut.io_valid_55,&dut.io_valid_56,&dut.io_valid_57,&dut.io_valid_58,&dut.io_valid_59,&dut.io_valid_60,&dut.io_valid_61,&dut.io_valid_62,&dut.io_valid_63,&dut.io_valid_64,&dut.io_valid_65,&dut.io_valid_66,&dut.io_valid_67,&dut.io_valid_68,&dut.io_valid_69,&dut.io_valid_70,&dut.io_valid_71,&dut.io_valid_72,&dut.io_valid_73,&dut.io_valid_74,&dut.io_valid_75,&dut.io_valid_76,&dut.io_valid_77,&dut.io_valid_78,&dut.io_valid_79,&dut.io_valid_80,&dut.io_valid_81,&dut.io_valid_82,&dut.io_valid_83,&dut.io_valid_84,&dut.io_valid_85,&dut.io_valid_86,&dut.io_valid_87,&dut.io_valid_88,&dut.io_valid_89,&dut.io_valid_90,&dut.io_valid_91,&dut.io_valid_92,&dut.io_valid_93,&dut.io_valid_94,&dut.io_valid_95,&dut.io_valid_96,&dut.io_valid_97,&dut.io_valid_98,&dut.io_valid_99,&dut.io_valid_100,&dut.io_valid_101,&dut.io_valid_102,&dut.io_valid_103,&dut.io_valid_104,&dut.io_valid_105,&dut.io_valid_106,&dut.io_valid_107,&dut.io_valid_108,&dut.io_valid_109,&dut.io_valid_110,&dut.io_valid_111,&dut.io_valid_112,&dut.io_valid_113,&dut.io_valid_114,&dut.io_valid_115,&dut.io_valid_116,&dut.io_valid_117,&dut.io_valid_118,&dut.io_valid_119,&dut.io_valid_120,&dut.io_valid_121,&dut.io_valid_122,&dut.io_valid_123,&dut.io_valid_124,&dut.io_valid_125,&dut.io_valid_126,&dut.io_valid_127,&dut.io_valid_128,&dut.io_valid_129,&dut.io_valid_130,&dut.io_valid_131,&dut.io_valid_132,&dut.io_valid_133,&dut.io_valid_134,&dut.io_valid_135,&dut.io_valid_136,&dut.io_valid_137,&dut.io_valid_138,&dut.io_valid_139,&dut.io_valid_140,&dut.io_valid_141,&dut.io_valid_142,&dut.io_valid_143,&dut.io_valid_144,&dut.io_valid_145,&dut.io_valid_146,&dut.io_valid_147,&dut.io_valid_148,&dut.io_valid_149,&dut.io_valid_150,&dut.io_valid_151,&dut.io_valid_152,&dut.io_valid_153,&dut.io_valid_154,&dut.io_valid_155,&dut.io_valid_156,&dut.io_valid_157,&dut.io_valid_158,&dut.io_valid_159,&dut.io_valid_160,&dut.io_valid_161,&dut.io_valid_162,&dut.io_valid_163,&dut.io_valid_164,&dut.io_valid_165,&dut.io_valid_166,&dut.io_valid_167,&dut.io_valid_168,&dut.io_valid_169,&dut.io_valid_170,&dut.io_valid_171,&dut.io_valid_172,&dut.io_valid_173,&dut.io_valid_174,&dut.io_valid_175,&dut.io_valid_176,&dut.io_valid_177,&dut.io_valid_178,&dut.io_valid_179,&dut.io_valid_180,&dut.io_valid_181,&dut.io_valid_182,&dut.io_valid_183,&dut.io_valid_184,&dut.io_valid_185,&dut.io_valid_186,&dut.io_valid_187,&dut.io_valid_188,&dut.io_valid_189,&dut.io_valid_190,&dut.io_valid_191,&dut.io_valid_192,&dut.io_valid_193,&dut.io_valid_194,&dut.io_valid_195,&dut.io_valid_196,&dut.io_valid_197,&dut.io_valid_198,&dut.io_valid_199,&dut.io_valid_200,&dut.io_valid_201,&dut.io_valid_202,&dut.io_valid_203,&dut.io_valid_204,&dut.io_valid_205,&dut.io_valid_206,&dut.io_valid_207,&dut.io_valid_208,&dut.io_valid_209,&dut.io_valid_210,&dut.io_valid_211,&dut.io_valid_212,&dut.io_valid_213,&dut.io_valid_214,&dut.io_valid_215,&dut.io_valid_216,&dut.io_valid_217,&dut.io_valid_218,&dut.io_valid_219,&dut.io_valid_220,&dut.io_valid_221,&dut.io_valid_222,&dut.io_valid_223,&dut.io_valid_224,&dut.io_valid_225,&dut.io_valid_226,&dut.io_valid_227,&dut.io_valid_228,&dut.io_valid_229,&dut.io_valid_230,&dut.io_valid_231,&dut.io_valid_232,&dut.io_valid_233,&dut.io_valid_234,&dut.io_valid_235,&dut.io_valid_236,&dut.io_valid_237,&dut.io_valid_238,&dut.io_valid_239,&dut.io_valid_240,&dut.io_valid_241,&dut.io_valid_242,&dut.io_valid_243,&dut.io_valid_244,&dut.io_valid_245,&dut.io_valid_246,&dut.io_valid_247,&dut.io_valid_248,&dut.io_valid_249,&dut.io_valid_250,&dut.io_valid_251,&dut.io_valid_252,&dut.io_valid_253,&dut.io_valid_254,&dut.io_valid_255};
uint32_t* full[256]={&dut.io_fullSeq_0,&dut.io_fullSeq_1,&dut.io_fullSeq_2,&dut.io_fullSeq_3,&dut.io_fullSeq_4,&dut.io_fullSeq_5,&dut.io_fullSeq_6,&dut.io_fullSeq_7,&dut.io_fullSeq_8,&dut.io_fullSeq_9,&dut.io_fullSeq_10,&dut.io_fullSeq_11,&dut.io_fullSeq_12,&dut.io_fullSeq_13,&dut.io_fullSeq_14,&dut.io_fullSeq_15,&dut.io_fullSeq_16,&dut.io_fullSeq_17,&dut.io_fullSeq_18,&dut.io_fullSeq_19,&dut.io_fullSeq_20,&dut.io_fullSeq_21,&dut.io_fullSeq_22,&dut.io_fullSeq_23,&dut.io_fullSeq_24,&dut.io_fullSeq_25,&dut.io_fullSeq_26,&dut.io_fullSeq_27,&dut.io_fullSeq_28,&dut.io_fullSeq_29,&dut.io_fullSeq_30,&dut.io_fullSeq_31,&dut.io_fullSeq_32,&dut.io_fullSeq_33,&dut.io_fullSeq_34,&dut.io_fullSeq_35,&dut.io_fullSeq_36,&dut.io_fullSeq_37,&dut.io_fullSeq_38,&dut.io_fullSeq_39,&dut.io_fullSeq_40,&dut.io_fullSeq_41,&dut.io_fullSeq_42,&dut.io_fullSeq_43,&dut.io_fullSeq_44,&dut.io_fullSeq_45,&dut.io_fullSeq_46,&dut.io_fullSeq_47,&dut.io_fullSeq_48,&dut.io_fullSeq_49,&dut.io_fullSeq_50,&dut.io_fullSeq_51,&dut.io_fullSeq_52,&dut.io_fullSeq_53,&dut.io_fullSeq_54,&dut.io_fullSeq_55,&dut.io_fullSeq_56,&dut.io_fullSeq_57,&dut.io_fullSeq_58,&dut.io_fullSeq_59,&dut.io_fullSeq_60,&dut.io_fullSeq_61,&dut.io_fullSeq_62,&dut.io_fullSeq_63,&dut.io_fullSeq_64,&dut.io_fullSeq_65,&dut.io_fullSeq_66,&dut.io_fullSeq_67,&dut.io_fullSeq_68,&dut.io_fullSeq_69,&dut.io_fullSeq_70,&dut.io_fullSeq_71,&dut.io_fullSeq_72,&dut.io_fullSeq_73,&dut.io_fullSeq_74,&dut.io_fullSeq_75,&dut.io_fullSeq_76,&dut.io_fullSeq_77,&dut.io_fullSeq_78,&dut.io_fullSeq_79,&dut.io_fullSeq_80,&dut.io_fullSeq_81,&dut.io_fullSeq_82,&dut.io_fullSeq_83,&dut.io_fullSeq_84,&dut.io_fullSeq_85,&dut.io_fullSeq_86,&dut.io_fullSeq_87,&dut.io_fullSeq_88,&dut.io_fullSeq_89,&dut.io_fullSeq_90,&dut.io_fullSeq_91,&dut.io_fullSeq_92,&dut.io_fullSeq_93,&dut.io_fullSeq_94,&dut.io_fullSeq_95,&dut.io_fullSeq_96,&dut.io_fullSeq_97,&dut.io_fullSeq_98,&dut.io_fullSeq_99,&dut.io_fullSeq_100,&dut.io_fullSeq_101,&dut.io_fullSeq_102,&dut.io_fullSeq_103,&dut.io_fullSeq_104,&dut.io_fullSeq_105,&dut.io_fullSeq_106,&dut.io_fullSeq_107,&dut.io_fullSeq_108,&dut.io_fullSeq_109,&dut.io_fullSeq_110,&dut.io_fullSeq_111,&dut.io_fullSeq_112,&dut.io_fullSeq_113,&dut.io_fullSeq_114,&dut.io_fullSeq_115,&dut.io_fullSeq_116,&dut.io_fullSeq_117,&dut.io_fullSeq_118,&dut.io_fullSeq_119,&dut.io_fullSeq_120,&dut.io_fullSeq_121,&dut.io_fullSeq_122,&dut.io_fullSeq_123,&dut.io_fullSeq_124,&dut.io_fullSeq_125,&dut.io_fullSeq_126,&dut.io_fullSeq_127,&dut.io_fullSeq_128,&dut.io_fullSeq_129,&dut.io_fullSeq_130,&dut.io_fullSeq_131,&dut.io_fullSeq_132,&dut.io_fullSeq_133,&dut.io_fullSeq_134,&dut.io_fullSeq_135,&dut.io_fullSeq_136,&dut.io_fullSeq_137,&dut.io_fullSeq_138,&dut.io_fullSeq_139,&dut.io_fullSeq_140,&dut.io_fullSeq_141,&dut.io_fullSeq_142,&dut.io_fullSeq_143,&dut.io_fullSeq_144,&dut.io_fullSeq_145,&dut.io_fullSeq_146,&dut.io_fullSeq_147,&dut.io_fullSeq_148,&dut.io_fullSeq_149,&dut.io_fullSeq_150,&dut.io_fullSeq_151,&dut.io_fullSeq_152,&dut.io_fullSeq_153,&dut.io_fullSeq_154,&dut.io_fullSeq_155,&dut.io_fullSeq_156,&dut.io_fullSeq_157,&dut.io_fullSeq_158,&dut.io_fullSeq_159,&dut.io_fullSeq_160,&dut.io_fullSeq_161,&dut.io_fullSeq_162,&dut.io_fullSeq_163,&dut.io_fullSeq_164,&dut.io_fullSeq_165,&dut.io_fullSeq_166,&dut.io_fullSeq_167,&dut.io_fullSeq_168,&dut.io_fullSeq_169,&dut.io_fullSeq_170,&dut.io_fullSeq_171,&dut.io_fullSeq_172,&dut.io_fullSeq_173,&dut.io_fullSeq_174,&dut.io_fullSeq_175,&dut.io_fullSeq_176,&dut.io_fullSeq_177,&dut.io_fullSeq_178,&dut.io_fullSeq_179,&dut.io_fullSeq_180,&dut.io_fullSeq_181,&dut.io_fullSeq_182,&dut.io_fullSeq_183,&dut.io_fullSeq_184,&dut.io_fullSeq_185,&dut.io_fullSeq_186,&dut.io_fullSeq_187,&dut.io_fullSeq_188,&dut.io_fullSeq_189,&dut.io_fullSeq_190,&dut.io_fullSeq_191,&dut.io_fullSeq_192,&dut.io_fullSeq_193,&dut.io_fullSeq_194,&dut.io_fullSeq_195,&dut.io_fullSeq_196,&dut.io_fullSeq_197,&dut.io_fullSeq_198,&dut.io_fullSeq_199,&dut.io_fullSeq_200,&dut.io_fullSeq_201,&dut.io_fullSeq_202,&dut.io_fullSeq_203,&dut.io_fullSeq_204,&dut.io_fullSeq_205,&dut.io_fullSeq_206,&dut.io_fullSeq_207,&dut.io_fullSeq_208,&dut.io_fullSeq_209,&dut.io_fullSeq_210,&dut.io_fullSeq_211,&dut.io_fullSeq_212,&dut.io_fullSeq_213,&dut.io_fullSeq_214,&dut.io_fullSeq_215,&dut.io_fullSeq_216,&dut.io_fullSeq_217,&dut.io_fullSeq_218,&dut.io_fullSeq_219,&dut.io_fullSeq_220,&dut.io_fullSeq_221,&dut.io_fullSeq_222,&dut.io_fullSeq_223,&dut.io_fullSeq_224,&dut.io_fullSeq_225,&dut.io_fullSeq_226,&dut.io_fullSeq_227,&dut.io_fullSeq_228,&dut.io_fullSeq_229,&dut.io_fullSeq_230,&dut.io_fullSeq_231,&dut.io_fullSeq_232,&dut.io_fullSeq_233,&dut.io_fullSeq_234,&dut.io_fullSeq_235,&dut.io_fullSeq_236,&dut.io_fullSeq_237,&dut.io_fullSeq_238,&dut.io_fullSeq_239,&dut.io_fullSeq_240,&dut.io_fullSeq_241,&dut.io_fullSeq_242,&dut.io_fullSeq_243,&dut.io_fullSeq_244,&dut.io_fullSeq_245,&dut.io_fullSeq_246,&dut.io_fullSeq_247,&dut.io_fullSeq_248,&dut.io_fullSeq_249,&dut.io_fullSeq_250,&dut.io_fullSeq_251,&dut.io_fullSeq_252,&dut.io_fullSeq_253,&dut.io_fullSeq_254,&dut.io_fullSeq_255};
uint32_t* query[96]={&dut.io_querySeq_0,&dut.io_querySeq_1,&dut.io_querySeq_2,&dut.io_querySeq_3,&dut.io_querySeq_4,&dut.io_querySeq_5,&dut.io_querySeq_6,&dut.io_querySeq_7,&dut.io_querySeq_8,&dut.io_querySeq_9,&dut.io_querySeq_10,&dut.io_querySeq_11,&dut.io_querySeq_12,&dut.io_querySeq_13,&dut.io_querySeq_14,&dut.io_querySeq_15,&dut.io_querySeq_16,&dut.io_querySeq_17,&dut.io_querySeq_18,&dut.io_querySeq_19,&dut.io_querySeq_20,&dut.io_querySeq_21,&dut.io_querySeq_22,&dut.io_querySeq_23,&dut.io_querySeq_24,&dut.io_querySeq_25,&dut.io_querySeq_26,&dut.io_querySeq_27,&dut.io_querySeq_28,&dut.io_querySeq_29,&dut.io_querySeq_30,&dut.io_querySeq_31,&dut.io_querySeq_32,&dut.io_querySeq_33,&dut.io_querySeq_34,&dut.io_querySeq_35,&dut.io_querySeq_36,&dut.io_querySeq_37,&dut.io_querySeq_38,&dut.io_querySeq_39,&dut.io_querySeq_40,&dut.io_querySeq_41,&dut.io_querySeq_42,&dut.io_querySeq_43,&dut.io_querySeq_44,&dut.io_querySeq_45,&dut.io_querySeq_46,&dut.io_querySeq_47,&dut.io_querySeq_48,&dut.io_querySeq_49,&dut.io_querySeq_50,&dut.io_querySeq_51,&dut.io_querySeq_52,&dut.io_querySeq_53,&dut.io_querySeq_54,&dut.io_querySeq_55,&dut.io_querySeq_56,&dut.io_querySeq_57,&dut.io_querySeq_58,&dut.io_querySeq_59,&dut.io_querySeq_60,&dut.io_querySeq_61,&dut.io_querySeq_62,&dut.io_querySeq_63,&dut.io_querySeq_64,&dut.io_querySeq_65,&dut.io_querySeq_66,&dut.io_querySeq_67,&dut.io_querySeq_68,&dut.io_querySeq_69,&dut.io_querySeq_70,&dut.io_querySeq_71,&dut.io_querySeq_72,&dut.io_querySeq_73,&dut.io_querySeq_74,&dut.io_querySeq_75,&dut.io_querySeq_76,&dut.io_querySeq_77,&dut.io_querySeq_78,&dut.io_querySeq_79,&dut.io_querySeq_80,&dut.io_querySeq_81,&dut.io_querySeq_82,&dut.io_querySeq_83,&dut.io_querySeq_84,&dut.io_querySeq_85,&dut.io_querySeq_86,&dut.io_querySeq_87,&dut.io_querySeq_88,&dut.io_querySeq_89,&dut.io_querySeq_90,&dut.io_querySeq_91,&dut.io_querySeq_92,&dut.io_querySeq_93,&dut.io_querySeq_94,&dut.io_querySeq_95};
uint8_t* old_match[96]={&dut.io_oldMatch_0,&dut.io_oldMatch_1,&dut.io_oldMatch_2,&dut.io_oldMatch_3,&dut.io_oldMatch_4,&dut.io_oldMatch_5,&dut.io_oldMatch_6,&dut.io_oldMatch_7,&dut.io_oldMatch_8,&dut.io_oldMatch_9,&dut.io_oldMatch_10,&dut.io_oldMatch_11,&dut.io_oldMatch_12,&dut.io_oldMatch_13,&dut.io_oldMatch_14,&dut.io_oldMatch_15,&dut.io_oldMatch_16,&dut.io_oldMatch_17,&dut.io_oldMatch_18,&dut.io_oldMatch_19,&dut.io_oldMatch_20,&dut.io_oldMatch_21,&dut.io_oldMatch_22,&dut.io_oldMatch_23,&dut.io_oldMatch_24,&dut.io_oldMatch_25,&dut.io_oldMatch_26,&dut.io_oldMatch_27,&dut.io_oldMatch_28,&dut.io_oldMatch_29,&dut.io_oldMatch_30,&dut.io_oldMatch_31,&dut.io_oldMatch_32,&dut.io_oldMatch_33,&dut.io_oldMatch_34,&dut.io_oldMatch_35,&dut.io_oldMatch_36,&dut.io_oldMatch_37,&dut.io_oldMatch_38,&dut.io_oldMatch_39,&dut.io_oldMatch_40,&dut.io_oldMatch_41,&dut.io_oldMatch_42,&dut.io_oldMatch_43,&dut.io_oldMatch_44,&dut.io_oldMatch_45,&dut.io_oldMatch_46,&dut.io_oldMatch_47,&dut.io_oldMatch_48,&dut.io_oldMatch_49,&dut.io_oldMatch_50,&dut.io_oldMatch_51,&dut.io_oldMatch_52,&dut.io_oldMatch_53,&dut.io_oldMatch_54,&dut.io_oldMatch_55,&dut.io_oldMatch_56,&dut.io_oldMatch_57,&dut.io_oldMatch_58,&dut.io_oldMatch_59,&dut.io_oldMatch_60,&dut.io_oldMatch_61,&dut.io_oldMatch_62,&dut.io_oldMatch_63,&dut.io_oldMatch_64,&dut.io_oldMatch_65,&dut.io_oldMatch_66,&dut.io_oldMatch_67,&dut.io_oldMatch_68,&dut.io_oldMatch_69,&dut.io_oldMatch_70,&dut.io_oldMatch_71,&dut.io_oldMatch_72,&dut.io_oldMatch_73,&dut.io_oldMatch_74,&dut.io_oldMatch_75,&dut.io_oldMatch_76,&dut.io_oldMatch_77,&dut.io_oldMatch_78,&dut.io_oldMatch_79,&dut.io_oldMatch_80,&dut.io_oldMatch_81,&dut.io_oldMatch_82,&dut.io_oldMatch_83,&dut.io_oldMatch_84,&dut.io_oldMatch_85,&dut.io_oldMatch_86,&dut.io_oldMatch_87,&dut.io_oldMatch_88,&dut.io_oldMatch_89,&dut.io_oldMatch_90,&dut.io_oldMatch_91,&dut.io_oldMatch_92,&dut.io_oldMatch_93,&dut.io_oldMatch_94,&dut.io_oldMatch_95};
uint8_t* new_match[96]={&dut.io_newMatch_0,&dut.io_newMatch_1,&dut.io_newMatch_2,&dut.io_newMatch_3,&dut.io_newMatch_4,&dut.io_newMatch_5,&dut.io_newMatch_6,&dut.io_newMatch_7,&dut.io_newMatch_8,&dut.io_newMatch_9,&dut.io_newMatch_10,&dut.io_newMatch_11,&dut.io_newMatch_12,&dut.io_newMatch_13,&dut.io_newMatch_14,&dut.io_newMatch_15,&dut.io_newMatch_16,&dut.io_newMatch_17,&dut.io_newMatch_18,&dut.io_newMatch_19,&dut.io_newMatch_20,&dut.io_newMatch_21,&dut.io_newMatch_22,&dut.io_newMatch_23,&dut.io_newMatch_24,&dut.io_newMatch_25,&dut.io_newMatch_26,&dut.io_newMatch_27,&dut.io_newMatch_28,&dut.io_newMatch_29,&dut.io_newMatch_30,&dut.io_newMatch_31,&dut.io_newMatch_32,&dut.io_newMatch_33,&dut.io_newMatch_34,&dut.io_newMatch_35,&dut.io_newMatch_36,&dut.io_newMatch_37,&dut.io_newMatch_38,&dut.io_newMatch_39,&dut.io_newMatch_40,&dut.io_newMatch_41,&dut.io_newMatch_42,&dut.io_newMatch_43,&dut.io_newMatch_44,&dut.io_newMatch_45,&dut.io_newMatch_46,&dut.io_newMatch_47,&dut.io_newMatch_48,&dut.io_newMatch_49,&dut.io_newMatch_50,&dut.io_newMatch_51,&dut.io_newMatch_52,&dut.io_newMatch_53,&dut.io_newMatch_54,&dut.io_newMatch_55,&dut.io_newMatch_56,&dut.io_newMatch_57,&dut.io_newMatch_58,&dut.io_newMatch_59,&dut.io_newMatch_60,&dut.io_newMatch_61,&dut.io_newMatch_62,&dut.io_newMatch_63,&dut.io_newMatch_64,&dut.io_newMatch_65,&dut.io_newMatch_66,&dut.io_newMatch_67,&dut.io_newMatch_68,&dut.io_newMatch_69,&dut.io_newMatch_70,&dut.io_newMatch_71,&dut.io_newMatch_72,&dut.io_newMatch_73,&dut.io_newMatch_74,&dut.io_newMatch_75,&dut.io_newMatch_76,&dut.io_newMatch_77,&dut.io_newMatch_78,&dut.io_newMatch_79,&dut.io_newMatch_80,&dut.io_newMatch_81,&dut.io_newMatch_82,&dut.io_newMatch_83,&dut.io_newMatch_84,&dut.io_newMatch_85,&dut.io_newMatch_86,&dut.io_newMatch_87,&dut.io_newMatch_88,&dut.io_newMatch_89,&dut.io_newMatch_90,&dut.io_newMatch_91,&dut.io_newMatch_92,&dut.io_newMatch_93,&dut.io_newMatch_94,&dut.io_newMatch_95};
uint8_t valid_value[256];uint32_t full_seq[256],query_seq[96];
for(unsigned t=0;t<8192;t++){
 for(unsigned i=0;i<256;i++){
  valid_value[i]=((t+i*7)%5)!=0;
  uint32_t high;
  switch((t+i)%8){case 0:high=0;break;case 1:high=1;break;
   case 2:high=0xffffff;break;case 3:high=0x7fffff;break;
   case 4:high=0x800000;break;default:high=(uint32_t)random64()&0xffffff;break;}
  full_seq[i]=valid_value[i]?((high<<8)|i):(uint32_t)random64();
 }
 for(unsigned q=0;q<96;q++){
  unsigned idx=(q*37+t*13)&255u;uint32_t high;
  switch(q%6){case 0:high=full_seq[idx]>>8;break;case 1:high=0;break;
   case 2:high=0xffffff;break;case 3:high=(full_seq[idx]>>8)^1u;break;
   default:high=(uint32_t)random64()&0xffffff;break;}
  query_seq[q]=(high<<8)|idx;
 }
*valid[0]=valid_value[0];*full[0]=full_seq[0];
*valid[1]=valid_value[1];*full[1]=full_seq[1];
*valid[2]=valid_value[2];*full[2]=full_seq[2];
*valid[3]=valid_value[3];*full[3]=full_seq[3];
*valid[4]=valid_value[4];*full[4]=full_seq[4];
*valid[5]=valid_value[5];*full[5]=full_seq[5];
*valid[6]=valid_value[6];*full[6]=full_seq[6];
*valid[7]=valid_value[7];*full[7]=full_seq[7];
*valid[8]=valid_value[8];*full[8]=full_seq[8];
*valid[9]=valid_value[9];*full[9]=full_seq[9];
*valid[10]=valid_value[10];*full[10]=full_seq[10];
*valid[11]=valid_value[11];*full[11]=full_seq[11];
*valid[12]=valid_value[12];*full[12]=full_seq[12];
*valid[13]=valid_value[13];*full[13]=full_seq[13];
*valid[14]=valid_value[14];*full[14]=full_seq[14];
*valid[15]=valid_value[15];*full[15]=full_seq[15];
*valid[16]=valid_value[16];*full[16]=full_seq[16];
*valid[17]=valid_value[17];*full[17]=full_seq[17];
*valid[18]=valid_value[18];*full[18]=full_seq[18];
*valid[19]=valid_value[19];*full[19]=full_seq[19];
*valid[20]=valid_value[20];*full[20]=full_seq[20];
*valid[21]=valid_value[21];*full[21]=full_seq[21];
*valid[22]=valid_value[22];*full[22]=full_seq[22];
*valid[23]=valid_value[23];*full[23]=full_seq[23];
*valid[24]=valid_value[24];*full[24]=full_seq[24];
*valid[25]=valid_value[25];*full[25]=full_seq[25];
*valid[26]=valid_value[26];*full[26]=full_seq[26];
*valid[27]=valid_value[27];*full[27]=full_seq[27];
*valid[28]=valid_value[28];*full[28]=full_seq[28];
*valid[29]=valid_value[29];*full[29]=full_seq[29];
*valid[30]=valid_value[30];*full[30]=full_seq[30];
*valid[31]=valid_value[31];*full[31]=full_seq[31];
*valid[32]=valid_value[32];*full[32]=full_seq[32];
*valid[33]=valid_value[33];*full[33]=full_seq[33];
*valid[34]=valid_value[34];*full[34]=full_seq[34];
*valid[35]=valid_value[35];*full[35]=full_seq[35];
*valid[36]=valid_value[36];*full[36]=full_seq[36];
*valid[37]=valid_value[37];*full[37]=full_seq[37];
*valid[38]=valid_value[38];*full[38]=full_seq[38];
*valid[39]=valid_value[39];*full[39]=full_seq[39];
*valid[40]=valid_value[40];*full[40]=full_seq[40];
*valid[41]=valid_value[41];*full[41]=full_seq[41];
*valid[42]=valid_value[42];*full[42]=full_seq[42];
*valid[43]=valid_value[43];*full[43]=full_seq[43];
*valid[44]=valid_value[44];*full[44]=full_seq[44];
*valid[45]=valid_value[45];*full[45]=full_seq[45];
*valid[46]=valid_value[46];*full[46]=full_seq[46];
*valid[47]=valid_value[47];*full[47]=full_seq[47];
*valid[48]=valid_value[48];*full[48]=full_seq[48];
*valid[49]=valid_value[49];*full[49]=full_seq[49];
*valid[50]=valid_value[50];*full[50]=full_seq[50];
*valid[51]=valid_value[51];*full[51]=full_seq[51];
*valid[52]=valid_value[52];*full[52]=full_seq[52];
*valid[53]=valid_value[53];*full[53]=full_seq[53];
*valid[54]=valid_value[54];*full[54]=full_seq[54];
*valid[55]=valid_value[55];*full[55]=full_seq[55];
*valid[56]=valid_value[56];*full[56]=full_seq[56];
*valid[57]=valid_value[57];*full[57]=full_seq[57];
*valid[58]=valid_value[58];*full[58]=full_seq[58];
*valid[59]=valid_value[59];*full[59]=full_seq[59];
*valid[60]=valid_value[60];*full[60]=full_seq[60];
*valid[61]=valid_value[61];*full[61]=full_seq[61];
*valid[62]=valid_value[62];*full[62]=full_seq[62];
*valid[63]=valid_value[63];*full[63]=full_seq[63];
*valid[64]=valid_value[64];*full[64]=full_seq[64];
*valid[65]=valid_value[65];*full[65]=full_seq[65];
*valid[66]=valid_value[66];*full[66]=full_seq[66];
*valid[67]=valid_value[67];*full[67]=full_seq[67];
*valid[68]=valid_value[68];*full[68]=full_seq[68];
*valid[69]=valid_value[69];*full[69]=full_seq[69];
*valid[70]=valid_value[70];*full[70]=full_seq[70];
*valid[71]=valid_value[71];*full[71]=full_seq[71];
*valid[72]=valid_value[72];*full[72]=full_seq[72];
*valid[73]=valid_value[73];*full[73]=full_seq[73];
*valid[74]=valid_value[74];*full[74]=full_seq[74];
*valid[75]=valid_value[75];*full[75]=full_seq[75];
*valid[76]=valid_value[76];*full[76]=full_seq[76];
*valid[77]=valid_value[77];*full[77]=full_seq[77];
*valid[78]=valid_value[78];*full[78]=full_seq[78];
*valid[79]=valid_value[79];*full[79]=full_seq[79];
*valid[80]=valid_value[80];*full[80]=full_seq[80];
*valid[81]=valid_value[81];*full[81]=full_seq[81];
*valid[82]=valid_value[82];*full[82]=full_seq[82];
*valid[83]=valid_value[83];*full[83]=full_seq[83];
*valid[84]=valid_value[84];*full[84]=full_seq[84];
*valid[85]=valid_value[85];*full[85]=full_seq[85];
*valid[86]=valid_value[86];*full[86]=full_seq[86];
*valid[87]=valid_value[87];*full[87]=full_seq[87];
*valid[88]=valid_value[88];*full[88]=full_seq[88];
*valid[89]=valid_value[89];*full[89]=full_seq[89];
*valid[90]=valid_value[90];*full[90]=full_seq[90];
*valid[91]=valid_value[91];*full[91]=full_seq[91];
*valid[92]=valid_value[92];*full[92]=full_seq[92];
*valid[93]=valid_value[93];*full[93]=full_seq[93];
*valid[94]=valid_value[94];*full[94]=full_seq[94];
*valid[95]=valid_value[95];*full[95]=full_seq[95];
*valid[96]=valid_value[96];*full[96]=full_seq[96];
*valid[97]=valid_value[97];*full[97]=full_seq[97];
*valid[98]=valid_value[98];*full[98]=full_seq[98];
*valid[99]=valid_value[99];*full[99]=full_seq[99];
*valid[100]=valid_value[100];*full[100]=full_seq[100];
*valid[101]=valid_value[101];*full[101]=full_seq[101];
*valid[102]=valid_value[102];*full[102]=full_seq[102];
*valid[103]=valid_value[103];*full[103]=full_seq[103];
*valid[104]=valid_value[104];*full[104]=full_seq[104];
*valid[105]=valid_value[105];*full[105]=full_seq[105];
*valid[106]=valid_value[106];*full[106]=full_seq[106];
*valid[107]=valid_value[107];*full[107]=full_seq[107];
*valid[108]=valid_value[108];*full[108]=full_seq[108];
*valid[109]=valid_value[109];*full[109]=full_seq[109];
*valid[110]=valid_value[110];*full[110]=full_seq[110];
*valid[111]=valid_value[111];*full[111]=full_seq[111];
*valid[112]=valid_value[112];*full[112]=full_seq[112];
*valid[113]=valid_value[113];*full[113]=full_seq[113];
*valid[114]=valid_value[114];*full[114]=full_seq[114];
*valid[115]=valid_value[115];*full[115]=full_seq[115];
*valid[116]=valid_value[116];*full[116]=full_seq[116];
*valid[117]=valid_value[117];*full[117]=full_seq[117];
*valid[118]=valid_value[118];*full[118]=full_seq[118];
*valid[119]=valid_value[119];*full[119]=full_seq[119];
*valid[120]=valid_value[120];*full[120]=full_seq[120];
*valid[121]=valid_value[121];*full[121]=full_seq[121];
*valid[122]=valid_value[122];*full[122]=full_seq[122];
*valid[123]=valid_value[123];*full[123]=full_seq[123];
*valid[124]=valid_value[124];*full[124]=full_seq[124];
*valid[125]=valid_value[125];*full[125]=full_seq[125];
*valid[126]=valid_value[126];*full[126]=full_seq[126];
*valid[127]=valid_value[127];*full[127]=full_seq[127];
*valid[128]=valid_value[128];*full[128]=full_seq[128];
*valid[129]=valid_value[129];*full[129]=full_seq[129];
*valid[130]=valid_value[130];*full[130]=full_seq[130];
*valid[131]=valid_value[131];*full[131]=full_seq[131];
*valid[132]=valid_value[132];*full[132]=full_seq[132];
*valid[133]=valid_value[133];*full[133]=full_seq[133];
*valid[134]=valid_value[134];*full[134]=full_seq[134];
*valid[135]=valid_value[135];*full[135]=full_seq[135];
*valid[136]=valid_value[136];*full[136]=full_seq[136];
*valid[137]=valid_value[137];*full[137]=full_seq[137];
*valid[138]=valid_value[138];*full[138]=full_seq[138];
*valid[139]=valid_value[139];*full[139]=full_seq[139];
*valid[140]=valid_value[140];*full[140]=full_seq[140];
*valid[141]=valid_value[141];*full[141]=full_seq[141];
*valid[142]=valid_value[142];*full[142]=full_seq[142];
*valid[143]=valid_value[143];*full[143]=full_seq[143];
*valid[144]=valid_value[144];*full[144]=full_seq[144];
*valid[145]=valid_value[145];*full[145]=full_seq[145];
*valid[146]=valid_value[146];*full[146]=full_seq[146];
*valid[147]=valid_value[147];*full[147]=full_seq[147];
*valid[148]=valid_value[148];*full[148]=full_seq[148];
*valid[149]=valid_value[149];*full[149]=full_seq[149];
*valid[150]=valid_value[150];*full[150]=full_seq[150];
*valid[151]=valid_value[151];*full[151]=full_seq[151];
*valid[152]=valid_value[152];*full[152]=full_seq[152];
*valid[153]=valid_value[153];*full[153]=full_seq[153];
*valid[154]=valid_value[154];*full[154]=full_seq[154];
*valid[155]=valid_value[155];*full[155]=full_seq[155];
*valid[156]=valid_value[156];*full[156]=full_seq[156];
*valid[157]=valid_value[157];*full[157]=full_seq[157];
*valid[158]=valid_value[158];*full[158]=full_seq[158];
*valid[159]=valid_value[159];*full[159]=full_seq[159];
*valid[160]=valid_value[160];*full[160]=full_seq[160];
*valid[161]=valid_value[161];*full[161]=full_seq[161];
*valid[162]=valid_value[162];*full[162]=full_seq[162];
*valid[163]=valid_value[163];*full[163]=full_seq[163];
*valid[164]=valid_value[164];*full[164]=full_seq[164];
*valid[165]=valid_value[165];*full[165]=full_seq[165];
*valid[166]=valid_value[166];*full[166]=full_seq[166];
*valid[167]=valid_value[167];*full[167]=full_seq[167];
*valid[168]=valid_value[168];*full[168]=full_seq[168];
*valid[169]=valid_value[169];*full[169]=full_seq[169];
*valid[170]=valid_value[170];*full[170]=full_seq[170];
*valid[171]=valid_value[171];*full[171]=full_seq[171];
*valid[172]=valid_value[172];*full[172]=full_seq[172];
*valid[173]=valid_value[173];*full[173]=full_seq[173];
*valid[174]=valid_value[174];*full[174]=full_seq[174];
*valid[175]=valid_value[175];*full[175]=full_seq[175];
*valid[176]=valid_value[176];*full[176]=full_seq[176];
*valid[177]=valid_value[177];*full[177]=full_seq[177];
*valid[178]=valid_value[178];*full[178]=full_seq[178];
*valid[179]=valid_value[179];*full[179]=full_seq[179];
*valid[180]=valid_value[180];*full[180]=full_seq[180];
*valid[181]=valid_value[181];*full[181]=full_seq[181];
*valid[182]=valid_value[182];*full[182]=full_seq[182];
*valid[183]=valid_value[183];*full[183]=full_seq[183];
*valid[184]=valid_value[184];*full[184]=full_seq[184];
*valid[185]=valid_value[185];*full[185]=full_seq[185];
*valid[186]=valid_value[186];*full[186]=full_seq[186];
*valid[187]=valid_value[187];*full[187]=full_seq[187];
*valid[188]=valid_value[188];*full[188]=full_seq[188];
*valid[189]=valid_value[189];*full[189]=full_seq[189];
*valid[190]=valid_value[190];*full[190]=full_seq[190];
*valid[191]=valid_value[191];*full[191]=full_seq[191];
*valid[192]=valid_value[192];*full[192]=full_seq[192];
*valid[193]=valid_value[193];*full[193]=full_seq[193];
*valid[194]=valid_value[194];*full[194]=full_seq[194];
*valid[195]=valid_value[195];*full[195]=full_seq[195];
*valid[196]=valid_value[196];*full[196]=full_seq[196];
*valid[197]=valid_value[197];*full[197]=full_seq[197];
*valid[198]=valid_value[198];*full[198]=full_seq[198];
*valid[199]=valid_value[199];*full[199]=full_seq[199];
*valid[200]=valid_value[200];*full[200]=full_seq[200];
*valid[201]=valid_value[201];*full[201]=full_seq[201];
*valid[202]=valid_value[202];*full[202]=full_seq[202];
*valid[203]=valid_value[203];*full[203]=full_seq[203];
*valid[204]=valid_value[204];*full[204]=full_seq[204];
*valid[205]=valid_value[205];*full[205]=full_seq[205];
*valid[206]=valid_value[206];*full[206]=full_seq[206];
*valid[207]=valid_value[207];*full[207]=full_seq[207];
*valid[208]=valid_value[208];*full[208]=full_seq[208];
*valid[209]=valid_value[209];*full[209]=full_seq[209];
*valid[210]=valid_value[210];*full[210]=full_seq[210];
*valid[211]=valid_value[211];*full[211]=full_seq[211];
*valid[212]=valid_value[212];*full[212]=full_seq[212];
*valid[213]=valid_value[213];*full[213]=full_seq[213];
*valid[214]=valid_value[214];*full[214]=full_seq[214];
*valid[215]=valid_value[215];*full[215]=full_seq[215];
*valid[216]=valid_value[216];*full[216]=full_seq[216];
*valid[217]=valid_value[217];*full[217]=full_seq[217];
*valid[218]=valid_value[218];*full[218]=full_seq[218];
*valid[219]=valid_value[219];*full[219]=full_seq[219];
*valid[220]=valid_value[220];*full[220]=full_seq[220];
*valid[221]=valid_value[221];*full[221]=full_seq[221];
*valid[222]=valid_value[222];*full[222]=full_seq[222];
*valid[223]=valid_value[223];*full[223]=full_seq[223];
*valid[224]=valid_value[224];*full[224]=full_seq[224];
*valid[225]=valid_value[225];*full[225]=full_seq[225];
*valid[226]=valid_value[226];*full[226]=full_seq[226];
*valid[227]=valid_value[227];*full[227]=full_seq[227];
*valid[228]=valid_value[228];*full[228]=full_seq[228];
*valid[229]=valid_value[229];*full[229]=full_seq[229];
*valid[230]=valid_value[230];*full[230]=full_seq[230];
*valid[231]=valid_value[231];*full[231]=full_seq[231];
*valid[232]=valid_value[232];*full[232]=full_seq[232];
*valid[233]=valid_value[233];*full[233]=full_seq[233];
*valid[234]=valid_value[234];*full[234]=full_seq[234];
*valid[235]=valid_value[235];*full[235]=full_seq[235];
*valid[236]=valid_value[236];*full[236]=full_seq[236];
*valid[237]=valid_value[237];*full[237]=full_seq[237];
*valid[238]=valid_value[238];*full[238]=full_seq[238];
*valid[239]=valid_value[239];*full[239]=full_seq[239];
*valid[240]=valid_value[240];*full[240]=full_seq[240];
*valid[241]=valid_value[241];*full[241]=full_seq[241];
*valid[242]=valid_value[242];*full[242]=full_seq[242];
*valid[243]=valid_value[243];*full[243]=full_seq[243];
*valid[244]=valid_value[244];*full[244]=full_seq[244];
*valid[245]=valid_value[245];*full[245]=full_seq[245];
*valid[246]=valid_value[246];*full[246]=full_seq[246];
*valid[247]=valid_value[247];*full[247]=full_seq[247];
*valid[248]=valid_value[248];*full[248]=full_seq[248];
*valid[249]=valid_value[249];*full[249]=full_seq[249];
*valid[250]=valid_value[250];*full[250]=full_seq[250];
*valid[251]=valid_value[251];*full[251]=full_seq[251];
*valid[252]=valid_value[252];*full[252]=full_seq[252];
*valid[253]=valid_value[253];*full[253]=full_seq[253];
*valid[254]=valid_value[254];*full[254]=full_seq[254];
*valid[255]=valid_value[255];*full[255]=full_seq[255];
*query[0]=query_seq[0];
*query[1]=query_seq[1];
*query[2]=query_seq[2];
*query[3]=query_seq[3];
*query[4]=query_seq[4];
*query[5]=query_seq[5];
*query[6]=query_seq[6];
*query[7]=query_seq[7];
*query[8]=query_seq[8];
*query[9]=query_seq[9];
*query[10]=query_seq[10];
*query[11]=query_seq[11];
*query[12]=query_seq[12];
*query[13]=query_seq[13];
*query[14]=query_seq[14];
*query[15]=query_seq[15];
*query[16]=query_seq[16];
*query[17]=query_seq[17];
*query[18]=query_seq[18];
*query[19]=query_seq[19];
*query[20]=query_seq[20];
*query[21]=query_seq[21];
*query[22]=query_seq[22];
*query[23]=query_seq[23];
*query[24]=query_seq[24];
*query[25]=query_seq[25];
*query[26]=query_seq[26];
*query[27]=query_seq[27];
*query[28]=query_seq[28];
*query[29]=query_seq[29];
*query[30]=query_seq[30];
*query[31]=query_seq[31];
*query[32]=query_seq[32];
*query[33]=query_seq[33];
*query[34]=query_seq[34];
*query[35]=query_seq[35];
*query[36]=query_seq[36];
*query[37]=query_seq[37];
*query[38]=query_seq[38];
*query[39]=query_seq[39];
*query[40]=query_seq[40];
*query[41]=query_seq[41];
*query[42]=query_seq[42];
*query[43]=query_seq[43];
*query[44]=query_seq[44];
*query[45]=query_seq[45];
*query[46]=query_seq[46];
*query[47]=query_seq[47];
*query[48]=query_seq[48];
*query[49]=query_seq[49];
*query[50]=query_seq[50];
*query[51]=query_seq[51];
*query[52]=query_seq[52];
*query[53]=query_seq[53];
*query[54]=query_seq[54];
*query[55]=query_seq[55];
*query[56]=query_seq[56];
*query[57]=query_seq[57];
*query[58]=query_seq[58];
*query[59]=query_seq[59];
*query[60]=query_seq[60];
*query[61]=query_seq[61];
*query[62]=query_seq[62];
*query[63]=query_seq[63];
*query[64]=query_seq[64];
*query[65]=query_seq[65];
*query[66]=query_seq[66];
*query[67]=query_seq[67];
*query[68]=query_seq[68];
*query[69]=query_seq[69];
*query[70]=query_seq[70];
*query[71]=query_seq[71];
*query[72]=query_seq[72];
*query[73]=query_seq[73];
*query[74]=query_seq[74];
*query[75]=query_seq[75];
*query[76]=query_seq[76];
*query[77]=query_seq[77];
*query[78]=query_seq[78];
*query[79]=query_seq[79];
*query[80]=query_seq[80];
*query[81]=query_seq[81];
*query[82]=query_seq[82];
*query[83]=query_seq[83];
*query[84]=query_seq[84];
*query[85]=query_seq[85];
*query[86]=query_seq[86];
*query[87]=query_seq[87];
*query[88]=query_seq[88];
*query[89]=query_seq[89];
*query[90]=query_seq[90];
*query[91]=query_seq[91];
*query[92]=query_seq[92];
*query[93]=query_seq[93];
*query[94]=query_seq[94];
*query[95]=query_seq[95];
 dut.eval();if(!dut.io_invariant)fail(t,96);
{unsigned idx=query_seq[0]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[0];
if(*old_match[0]!=expected || *new_match[0]!=expected)fail(t,0);}
{unsigned idx=query_seq[1]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[1];
if(*old_match[1]!=expected || *new_match[1]!=expected)fail(t,1);}
{unsigned idx=query_seq[2]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[2];
if(*old_match[2]!=expected || *new_match[2]!=expected)fail(t,2);}
{unsigned idx=query_seq[3]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[3];
if(*old_match[3]!=expected || *new_match[3]!=expected)fail(t,3);}
{unsigned idx=query_seq[4]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[4];
if(*old_match[4]!=expected || *new_match[4]!=expected)fail(t,4);}
{unsigned idx=query_seq[5]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[5];
if(*old_match[5]!=expected || *new_match[5]!=expected)fail(t,5);}
{unsigned idx=query_seq[6]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[6];
if(*old_match[6]!=expected || *new_match[6]!=expected)fail(t,6);}
{unsigned idx=query_seq[7]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[7];
if(*old_match[7]!=expected || *new_match[7]!=expected)fail(t,7);}
{unsigned idx=query_seq[8]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[8];
if(*old_match[8]!=expected || *new_match[8]!=expected)fail(t,8);}
{unsigned idx=query_seq[9]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[9];
if(*old_match[9]!=expected || *new_match[9]!=expected)fail(t,9);}
{unsigned idx=query_seq[10]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[10];
if(*old_match[10]!=expected || *new_match[10]!=expected)fail(t,10);}
{unsigned idx=query_seq[11]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[11];
if(*old_match[11]!=expected || *new_match[11]!=expected)fail(t,11);}
{unsigned idx=query_seq[12]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[12];
if(*old_match[12]!=expected || *new_match[12]!=expected)fail(t,12);}
{unsigned idx=query_seq[13]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[13];
if(*old_match[13]!=expected || *new_match[13]!=expected)fail(t,13);}
{unsigned idx=query_seq[14]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[14];
if(*old_match[14]!=expected || *new_match[14]!=expected)fail(t,14);}
{unsigned idx=query_seq[15]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[15];
if(*old_match[15]!=expected || *new_match[15]!=expected)fail(t,15);}
{unsigned idx=query_seq[16]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[16];
if(*old_match[16]!=expected || *new_match[16]!=expected)fail(t,16);}
{unsigned idx=query_seq[17]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[17];
if(*old_match[17]!=expected || *new_match[17]!=expected)fail(t,17);}
{unsigned idx=query_seq[18]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[18];
if(*old_match[18]!=expected || *new_match[18]!=expected)fail(t,18);}
{unsigned idx=query_seq[19]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[19];
if(*old_match[19]!=expected || *new_match[19]!=expected)fail(t,19);}
{unsigned idx=query_seq[20]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[20];
if(*old_match[20]!=expected || *new_match[20]!=expected)fail(t,20);}
{unsigned idx=query_seq[21]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[21];
if(*old_match[21]!=expected || *new_match[21]!=expected)fail(t,21);}
{unsigned idx=query_seq[22]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[22];
if(*old_match[22]!=expected || *new_match[22]!=expected)fail(t,22);}
{unsigned idx=query_seq[23]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[23];
if(*old_match[23]!=expected || *new_match[23]!=expected)fail(t,23);}
{unsigned idx=query_seq[24]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[24];
if(*old_match[24]!=expected || *new_match[24]!=expected)fail(t,24);}
{unsigned idx=query_seq[25]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[25];
if(*old_match[25]!=expected || *new_match[25]!=expected)fail(t,25);}
{unsigned idx=query_seq[26]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[26];
if(*old_match[26]!=expected || *new_match[26]!=expected)fail(t,26);}
{unsigned idx=query_seq[27]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[27];
if(*old_match[27]!=expected || *new_match[27]!=expected)fail(t,27);}
{unsigned idx=query_seq[28]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[28];
if(*old_match[28]!=expected || *new_match[28]!=expected)fail(t,28);}
{unsigned idx=query_seq[29]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[29];
if(*old_match[29]!=expected || *new_match[29]!=expected)fail(t,29);}
{unsigned idx=query_seq[30]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[30];
if(*old_match[30]!=expected || *new_match[30]!=expected)fail(t,30);}
{unsigned idx=query_seq[31]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[31];
if(*old_match[31]!=expected || *new_match[31]!=expected)fail(t,31);}
{unsigned idx=query_seq[32]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[32];
if(*old_match[32]!=expected || *new_match[32]!=expected)fail(t,32);}
{unsigned idx=query_seq[33]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[33];
if(*old_match[33]!=expected || *new_match[33]!=expected)fail(t,33);}
{unsigned idx=query_seq[34]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[34];
if(*old_match[34]!=expected || *new_match[34]!=expected)fail(t,34);}
{unsigned idx=query_seq[35]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[35];
if(*old_match[35]!=expected || *new_match[35]!=expected)fail(t,35);}
{unsigned idx=query_seq[36]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[36];
if(*old_match[36]!=expected || *new_match[36]!=expected)fail(t,36);}
{unsigned idx=query_seq[37]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[37];
if(*old_match[37]!=expected || *new_match[37]!=expected)fail(t,37);}
{unsigned idx=query_seq[38]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[38];
if(*old_match[38]!=expected || *new_match[38]!=expected)fail(t,38);}
{unsigned idx=query_seq[39]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[39];
if(*old_match[39]!=expected || *new_match[39]!=expected)fail(t,39);}
{unsigned idx=query_seq[40]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[40];
if(*old_match[40]!=expected || *new_match[40]!=expected)fail(t,40);}
{unsigned idx=query_seq[41]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[41];
if(*old_match[41]!=expected || *new_match[41]!=expected)fail(t,41);}
{unsigned idx=query_seq[42]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[42];
if(*old_match[42]!=expected || *new_match[42]!=expected)fail(t,42);}
{unsigned idx=query_seq[43]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[43];
if(*old_match[43]!=expected || *new_match[43]!=expected)fail(t,43);}
{unsigned idx=query_seq[44]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[44];
if(*old_match[44]!=expected || *new_match[44]!=expected)fail(t,44);}
{unsigned idx=query_seq[45]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[45];
if(*old_match[45]!=expected || *new_match[45]!=expected)fail(t,45);}
{unsigned idx=query_seq[46]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[46];
if(*old_match[46]!=expected || *new_match[46]!=expected)fail(t,46);}
{unsigned idx=query_seq[47]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[47];
if(*old_match[47]!=expected || *new_match[47]!=expected)fail(t,47);}
{unsigned idx=query_seq[48]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[48];
if(*old_match[48]!=expected || *new_match[48]!=expected)fail(t,48);}
{unsigned idx=query_seq[49]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[49];
if(*old_match[49]!=expected || *new_match[49]!=expected)fail(t,49);}
{unsigned idx=query_seq[50]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[50];
if(*old_match[50]!=expected || *new_match[50]!=expected)fail(t,50);}
{unsigned idx=query_seq[51]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[51];
if(*old_match[51]!=expected || *new_match[51]!=expected)fail(t,51);}
{unsigned idx=query_seq[52]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[52];
if(*old_match[52]!=expected || *new_match[52]!=expected)fail(t,52);}
{unsigned idx=query_seq[53]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[53];
if(*old_match[53]!=expected || *new_match[53]!=expected)fail(t,53);}
{unsigned idx=query_seq[54]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[54];
if(*old_match[54]!=expected || *new_match[54]!=expected)fail(t,54);}
{unsigned idx=query_seq[55]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[55];
if(*old_match[55]!=expected || *new_match[55]!=expected)fail(t,55);}
{unsigned idx=query_seq[56]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[56];
if(*old_match[56]!=expected || *new_match[56]!=expected)fail(t,56);}
{unsigned idx=query_seq[57]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[57];
if(*old_match[57]!=expected || *new_match[57]!=expected)fail(t,57);}
{unsigned idx=query_seq[58]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[58];
if(*old_match[58]!=expected || *new_match[58]!=expected)fail(t,58);}
{unsigned idx=query_seq[59]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[59];
if(*old_match[59]!=expected || *new_match[59]!=expected)fail(t,59);}
{unsigned idx=query_seq[60]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[60];
if(*old_match[60]!=expected || *new_match[60]!=expected)fail(t,60);}
{unsigned idx=query_seq[61]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[61];
if(*old_match[61]!=expected || *new_match[61]!=expected)fail(t,61);}
{unsigned idx=query_seq[62]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[62];
if(*old_match[62]!=expected || *new_match[62]!=expected)fail(t,62);}
{unsigned idx=query_seq[63]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[63];
if(*old_match[63]!=expected || *new_match[63]!=expected)fail(t,63);}
{unsigned idx=query_seq[64]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[64];
if(*old_match[64]!=expected || *new_match[64]!=expected)fail(t,64);}
{unsigned idx=query_seq[65]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[65];
if(*old_match[65]!=expected || *new_match[65]!=expected)fail(t,65);}
{unsigned idx=query_seq[66]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[66];
if(*old_match[66]!=expected || *new_match[66]!=expected)fail(t,66);}
{unsigned idx=query_seq[67]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[67];
if(*old_match[67]!=expected || *new_match[67]!=expected)fail(t,67);}
{unsigned idx=query_seq[68]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[68];
if(*old_match[68]!=expected || *new_match[68]!=expected)fail(t,68);}
{unsigned idx=query_seq[69]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[69];
if(*old_match[69]!=expected || *new_match[69]!=expected)fail(t,69);}
{unsigned idx=query_seq[70]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[70];
if(*old_match[70]!=expected || *new_match[70]!=expected)fail(t,70);}
{unsigned idx=query_seq[71]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[71];
if(*old_match[71]!=expected || *new_match[71]!=expected)fail(t,71);}
{unsigned idx=query_seq[72]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[72];
if(*old_match[72]!=expected || *new_match[72]!=expected)fail(t,72);}
{unsigned idx=query_seq[73]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[73];
if(*old_match[73]!=expected || *new_match[73]!=expected)fail(t,73);}
{unsigned idx=query_seq[74]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[74];
if(*old_match[74]!=expected || *new_match[74]!=expected)fail(t,74);}
{unsigned idx=query_seq[75]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[75];
if(*old_match[75]!=expected || *new_match[75]!=expected)fail(t,75);}
{unsigned idx=query_seq[76]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[76];
if(*old_match[76]!=expected || *new_match[76]!=expected)fail(t,76);}
{unsigned idx=query_seq[77]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[77];
if(*old_match[77]!=expected || *new_match[77]!=expected)fail(t,77);}
{unsigned idx=query_seq[78]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[78];
if(*old_match[78]!=expected || *new_match[78]!=expected)fail(t,78);}
{unsigned idx=query_seq[79]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[79];
if(*old_match[79]!=expected || *new_match[79]!=expected)fail(t,79);}
{unsigned idx=query_seq[80]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[80];
if(*old_match[80]!=expected || *new_match[80]!=expected)fail(t,80);}
{unsigned idx=query_seq[81]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[81];
if(*old_match[81]!=expected || *new_match[81]!=expected)fail(t,81);}
{unsigned idx=query_seq[82]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[82];
if(*old_match[82]!=expected || *new_match[82]!=expected)fail(t,82);}
{unsigned idx=query_seq[83]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[83];
if(*old_match[83]!=expected || *new_match[83]!=expected)fail(t,83);}
{unsigned idx=query_seq[84]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[84];
if(*old_match[84]!=expected || *new_match[84]!=expected)fail(t,84);}
{unsigned idx=query_seq[85]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[85];
if(*old_match[85]!=expected || *new_match[85]!=expected)fail(t,85);}
{unsigned idx=query_seq[86]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[86];
if(*old_match[86]!=expected || *new_match[86]!=expected)fail(t,86);}
{unsigned idx=query_seq[87]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[87];
if(*old_match[87]!=expected || *new_match[87]!=expected)fail(t,87);}
{unsigned idx=query_seq[88]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[88];
if(*old_match[88]!=expected || *new_match[88]!=expected)fail(t,88);}
{unsigned idx=query_seq[89]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[89];
if(*old_match[89]!=expected || *new_match[89]!=expected)fail(t,89);}
{unsigned idx=query_seq[90]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[90];
if(*old_match[90]!=expected || *new_match[90]!=expected)fail(t,90);}
{unsigned idx=query_seq[91]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[91];
if(*old_match[91]!=expected || *new_match[91]!=expected)fail(t,91);}
{unsigned idx=query_seq[92]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[92];
if(*old_match[92]!=expected || *new_match[92]!=expected)fail(t,92);}
{unsigned idx=query_seq[93]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[93];
if(*old_match[93]!=expected || *new_match[93]!=expected)fail(t,93);}
{unsigned idx=query_seq[94]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[94];
if(*old_match[94]!=expected || *new_match[94]!=expected)fail(t,94);}
{unsigned idx=query_seq[95]&255u;
bool expected=valid_value[idx] && full_seq[idx]==query_seq[95];
if(*old_match[95]!=expected || *new_match[95]!=expected)fail(t,95);}
}
dut.final();std::puts("TAG_COMPRESS_ACTUAL_SIZE_PASS vectors=8192 slots=256 query_ports=96 seq_bits=32");return 0;}
