// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_GHBarrierBucketBank.h"

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_21;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_25;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_29;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_41;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_45;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_49;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_52;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_57;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_61;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_65;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_68;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_73;
    VlWide<3>/*95:0*/ __Vtemp_74;
    VlWide<3>/*95:0*/ __Vtemp_79;
    VlWide<3>/*95:0*/ __Vtemp_80;
    VlWide<3>/*95:0*/ __Vtemp_81;
    VlWide<3>/*95:0*/ __Vtemp_83;
    VlWide<3>/*95:0*/ __Vtemp_85;
    VlWide<3>/*95:0*/ __Vtemp_86;
    VlWide<3>/*95:0*/ __Vtemp_87;
    VlWide<3>/*95:0*/ __Vtemp_89;
    VlWide<3>/*95:0*/ __Vtemp_90;
    VlWide<3>/*95:0*/ __Vtemp_92;
    VlWide<3>/*95:0*/ __Vtemp_95;
    VlWide<3>/*95:0*/ __Vtemp_96;
    VlWide<3>/*95:0*/ __Vtemp_97;
    VlWide<3>/*95:0*/ __Vtemp_99;
    VlWide<3>/*95:0*/ __Vtemp_101;
    VlWide<3>/*95:0*/ __Vtemp_102;
    VlWide<3>/*95:0*/ __Vtemp_103;
    VlWide<3>/*95:0*/ __Vtemp_105;
    VlWide<3>/*95:0*/ __Vtemp_106;
    VlWide<3>/*95:0*/ __Vtemp_108;
    VlWide<3>/*95:0*/ __Vtemp_109;
    VlWide<3>/*95:0*/ __Vtemp_111;
    VlWide<3>/*95:0*/ __Vtemp_115;
    VlWide<3>/*95:0*/ __Vtemp_116;
    VlWide<3>/*95:0*/ __Vtemp_117;
    VlWide<3>/*95:0*/ __Vtemp_119;
    VlWide<3>/*95:0*/ __Vtemp_121;
    VlWide<3>/*95:0*/ __Vtemp_122;
    VlWide<3>/*95:0*/ __Vtemp_123;
    VlWide<3>/*95:0*/ __Vtemp_125;
    VlWide<3>/*95:0*/ __Vtemp_126;
    VlWide<3>/*95:0*/ __Vtemp_128;
    VlWide<3>/*95:0*/ __Vtemp_131;
    VlWide<3>/*95:0*/ __Vtemp_132;
    VlWide<3>/*95:0*/ __Vtemp_133;
    VlWide<3>/*95:0*/ __Vtemp_135;
    VlWide<3>/*95:0*/ __Vtemp_137;
    VlWide<3>/*95:0*/ __Vtemp_138;
    VlWide<3>/*95:0*/ __Vtemp_139;
    VlWide<3>/*95:0*/ __Vtemp_141;
    VlWide<3>/*95:0*/ __Vtemp_142;
    VlWide<3>/*95:0*/ __Vtemp_144;
    VlWide<3>/*95:0*/ __Vtemp_145;
    VlWide<3>/*95:0*/ __Vtemp_147;
    VlWide<3>/*95:0*/ __Vtemp_148;
    // Body
    vlSelfRef.__PVT___GEN_150 = ((~ (IData)(vlSelfRef.__PVT__resolving_10)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_10));
    vlSelfRef.__PVT___canAccept_T_31 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_10)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_10)));
    vlSelfRef.__PVT___GEN_165 = ((~ (IData)(vlSelfRef.__PVT__resolving_11)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_11));
    vlSelfRef.__PVT___canAccept_T_34 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_11)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_11)));
    vlSelfRef.__PVT___GEN_180 = ((~ (IData)(vlSelfRef.__PVT__resolving_12)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_12));
    vlSelfRef.__PVT___canAccept_T_37 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_12)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_12)));
    vlSelfRef.__PVT___GEN_195 = ((~ (IData)(vlSelfRef.__PVT__resolving_13)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_13));
    vlSelfRef.__PVT___canAccept_T_40 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_13)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_13)));
    vlSelfRef.__PVT___GEN_210 = ((~ (IData)(vlSelfRef.__PVT__resolving_14)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_14));
    vlSelfRef.__PVT___canAccept_T_43 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_14)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_14)));
    __Vtemp_5[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                              ? vlSelfRef.__PVT__buckets_requestCycleSum_0
                              : 0ULL));
    __Vtemp_5[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_0
                               : 0ULL) >> 0x20U));
    __Vtemp_5[2U] = 0U;
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_1)
                              ? vlSelfRef.__PVT__buckets_requestCycleSum_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_1)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    VL_ADD_W(3, __Vtemp_7, __Vtemp_5, __Vtemp_6);
    __Vtemp_9[0U] = __Vtemp_7[0U];
    __Vtemp_9[1U] = __Vtemp_7[1U];
    __Vtemp_9[2U] = (1U & __Vtemp_7[2U]);
    __Vtemp_11[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_2)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_2
                               : 0ULL));
    __Vtemp_11[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_2)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_2
                                : 0ULL) >> 0x20U));
    __Vtemp_11[2U] = 0U;
    __Vtemp_12[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_3)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_3
                               : 0ULL));
    __Vtemp_12[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_3)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_3
                                : 0ULL) >> 0x20U));
    __Vtemp_12[2U] = 0U;
    VL_ADD_W(3, __Vtemp_13, __Vtemp_11, __Vtemp_12);
    __Vtemp_15[0U] = __Vtemp_13[0U];
    __Vtemp_15[1U] = __Vtemp_13[1U];
    __Vtemp_15[2U] = (1U & __Vtemp_13[2U]);
    VL_ADD_W(3, __Vtemp_16, __Vtemp_9, __Vtemp_15);
    __Vtemp_18[0U] = __Vtemp_16[0U];
    __Vtemp_18[1U] = __Vtemp_16[1U];
    __Vtemp_18[2U] = (3U & __Vtemp_16[2U]);
    __Vtemp_21[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_4)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_4
                               : 0ULL));
    __Vtemp_21[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_4)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_4
                                : 0ULL) >> 0x20U));
    __Vtemp_21[2U] = 0U;
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_5)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_5
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_5)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_5
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    VL_ADD_W(3, __Vtemp_23, __Vtemp_21, __Vtemp_22);
    __Vtemp_25[0U] = __Vtemp_23[0U];
    __Vtemp_25[1U] = __Vtemp_23[1U];
    __Vtemp_25[2U] = (1U & __Vtemp_23[2U]);
    __Vtemp_27[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_6)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_6
                               : 0ULL));
    __Vtemp_27[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_6)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_6
                                : 0ULL) >> 0x20U));
    __Vtemp_27[2U] = 0U;
    __Vtemp_28[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_7)
                               ? vlSelfRef.buckets_requestCycleSum_7
                               : 0ULL));
    __Vtemp_28[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_requestCycleSum_7
                                : 0ULL) >> 0x20U));
    __Vtemp_28[2U] = 0U;
    VL_ADD_W(3, __Vtemp_29, __Vtemp_27, __Vtemp_28);
    __Vtemp_31[0U] = __Vtemp_29[0U];
    __Vtemp_31[1U] = __Vtemp_29[1U];
    __Vtemp_31[2U] = (1U & __Vtemp_29[2U]);
    VL_ADD_W(3, __Vtemp_32, __Vtemp_25, __Vtemp_31);
    __Vtemp_34[0U] = __Vtemp_32[0U];
    __Vtemp_34[1U] = __Vtemp_32[1U];
    __Vtemp_34[2U] = (3U & __Vtemp_32[2U]);
    VL_ADD_W(3, __Vtemp_35, __Vtemp_18, __Vtemp_34);
    __Vtemp_37[0U] = __Vtemp_35[0U];
    __Vtemp_37[1U] = __Vtemp_35[1U];
    __Vtemp_37[2U] = (7U & __Vtemp_35[2U]);
    __Vtemp_41[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_8)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_8
                               : 0ULL));
    __Vtemp_41[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_8)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_8
                                : 0ULL) >> 0x20U));
    __Vtemp_41[2U] = 0U;
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_9)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_9
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_9)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_9
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    VL_ADD_W(3, __Vtemp_43, __Vtemp_41, __Vtemp_42);
    __Vtemp_45[0U] = __Vtemp_43[0U];
    __Vtemp_45[1U] = __Vtemp_43[1U];
    __Vtemp_45[2U] = (1U & __Vtemp_43[2U]);
    __Vtemp_47[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_10)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_10
                               : 0ULL));
    __Vtemp_47[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_10)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_10
                                : 0ULL) >> 0x20U));
    __Vtemp_47[2U] = 0U;
    __Vtemp_48[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_11)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_11
                               : 0ULL));
    __Vtemp_48[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_11)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_11
                                : 0ULL) >> 0x20U));
    __Vtemp_48[2U] = 0U;
    VL_ADD_W(3, __Vtemp_49, __Vtemp_47, __Vtemp_48);
    __Vtemp_51[0U] = __Vtemp_49[0U];
    __Vtemp_51[1U] = __Vtemp_49[1U];
    __Vtemp_51[2U] = (1U & __Vtemp_49[2U]);
    VL_ADD_W(3, __Vtemp_52, __Vtemp_45, __Vtemp_51);
    __Vtemp_54[0U] = __Vtemp_52[0U];
    __Vtemp_54[1U] = __Vtemp_52[1U];
    __Vtemp_54[2U] = (3U & __Vtemp_52[2U]);
    __Vtemp_57[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_12)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_12
                               : 0ULL));
    __Vtemp_57[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_12)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_12
                                : 0ULL) >> 0x20U));
    __Vtemp_57[2U] = 0U;
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_13)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_13
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_13)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_13
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    VL_ADD_W(3, __Vtemp_59, __Vtemp_57, __Vtemp_58);
    __Vtemp_61[0U] = __Vtemp_59[0U];
    __Vtemp_61[1U] = __Vtemp_59[1U];
    __Vtemp_61[2U] = (1U & __Vtemp_59[2U]);
    __Vtemp_63[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_14)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_14
                               : 0ULL));
    __Vtemp_63[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_14)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_14
                                : 0ULL) >> 0x20U));
    __Vtemp_63[2U] = 0U;
    __Vtemp_64[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_15)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_15
                               : 0ULL));
    __Vtemp_64[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_15
                                : 0ULL) >> 0x20U));
    __Vtemp_64[2U] = 0U;
    VL_ADD_W(3, __Vtemp_65, __Vtemp_63, __Vtemp_64);
    __Vtemp_67[0U] = __Vtemp_65[0U];
    __Vtemp_67[1U] = __Vtemp_65[1U];
    __Vtemp_67[2U] = (1U & __Vtemp_65[2U]);
    VL_ADD_W(3, __Vtemp_68, __Vtemp_61, __Vtemp_67);
    __Vtemp_70[0U] = __Vtemp_68[0U];
    __Vtemp_70[1U] = __Vtemp_68[1U];
    __Vtemp_70[2U] = (3U & __Vtemp_68[2U]);
    VL_ADD_W(3, __Vtemp_71, __Vtemp_54, __Vtemp_70);
    __Vtemp_73[0U] = __Vtemp_71[0U];
    __Vtemp_73[1U] = __Vtemp_71[1U];
    __Vtemp_73[2U] = (7U & __Vtemp_71[2U]);
    VL_ADD_W(3, __Vtemp_74, __Vtemp_37, __Vtemp_73);
    vlSelfRef.io_resolvedRequest[0U] = __Vtemp_74[0U];
    vlSelfRef.io_resolvedRequest[1U] = __Vtemp_74[1U];
    vlSelfRef.io_resolvedRequest[2U] = (0xfU & __Vtemp_74[2U]);
    vlSelfRef.__PVT___GEN_225 = ((~ (IData)(vlSelfRef.__PVT__resolving_15)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_15));
    __Vtemp_79[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_count_0
                               : 0ULL));
    __Vtemp_79[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                                ? vlSelfRef.__PVT__buckets_count_0
                                : 0ULL) >> 0x20U));
    __Vtemp_79[2U] = 0U;
    __Vtemp_80[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_1)
                               ? vlSelfRef.__PVT__buckets_count_1
                               : 0ULL));
    __Vtemp_80[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_1)
                                ? vlSelfRef.__PVT__buckets_count_1
                                : 0ULL) >> 0x20U));
    __Vtemp_80[2U] = 0U;
    VL_ADD_W(3, __Vtemp_81, __Vtemp_79, __Vtemp_80);
    __Vtemp_83[0U] = __Vtemp_81[0U];
    __Vtemp_83[1U] = __Vtemp_81[1U];
    __Vtemp_83[2U] = (1U & __Vtemp_81[2U]);
    __Vtemp_85[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_2)
                               ? vlSelfRef.__PVT__buckets_count_2
                               : 0ULL));
    __Vtemp_85[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_2)
                                ? vlSelfRef.__PVT__buckets_count_2
                                : 0ULL) >> 0x20U));
    __Vtemp_85[2U] = 0U;
    __Vtemp_86[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_3)
                               ? vlSelfRef.__PVT__buckets_count_3
                               : 0ULL));
    __Vtemp_86[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_3)
                                ? vlSelfRef.__PVT__buckets_count_3
                                : 0ULL) >> 0x20U));
    __Vtemp_86[2U] = 0U;
    VL_ADD_W(3, __Vtemp_87, __Vtemp_85, __Vtemp_86);
    __Vtemp_89[0U] = __Vtemp_87[0U];
    __Vtemp_89[1U] = __Vtemp_87[1U];
    __Vtemp_89[2U] = (1U & __Vtemp_87[2U]);
    VL_ADD_W(3, __Vtemp_90, __Vtemp_83, __Vtemp_89);
    __Vtemp_92[0U] = __Vtemp_90[0U];
    __Vtemp_92[1U] = __Vtemp_90[1U];
    __Vtemp_92[2U] = (3U & __Vtemp_90[2U]);
    __Vtemp_95[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_4)
                               ? vlSelfRef.__PVT__buckets_count_4
                               : 0ULL));
    __Vtemp_95[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_4)
                                ? vlSelfRef.__PVT__buckets_count_4
                                : 0ULL) >> 0x20U));
    __Vtemp_95[2U] = 0U;
    __Vtemp_96[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_5)
                               ? vlSelfRef.__PVT__buckets_count_5
                               : 0ULL));
    __Vtemp_96[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_5)
                                ? vlSelfRef.__PVT__buckets_count_5
                                : 0ULL) >> 0x20U));
    __Vtemp_96[2U] = 0U;
    VL_ADD_W(3, __Vtemp_97, __Vtemp_95, __Vtemp_96);
    __Vtemp_99[0U] = __Vtemp_97[0U];
    __Vtemp_99[1U] = __Vtemp_97[1U];
    __Vtemp_99[2U] = (1U & __Vtemp_97[2U]);
    __Vtemp_101[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_6)
                                ? vlSelfRef.__PVT__buckets_count_6
                                : 0ULL));
    __Vtemp_101[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_6)
                                 ? vlSelfRef.__PVT__buckets_count_6
                                 : 0ULL) >> 0x20U));
    __Vtemp_101[2U] = 0U;
    __Vtemp_102[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_count_7
                                : 0ULL));
    __Vtemp_102[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                 ? vlSelfRef.buckets_count_7
                                 : 0ULL) >> 0x20U));
    __Vtemp_102[2U] = 0U;
    VL_ADD_W(3, __Vtemp_103, __Vtemp_101, __Vtemp_102);
    __Vtemp_105[0U] = __Vtemp_103[0U];
    __Vtemp_105[1U] = __Vtemp_103[1U];
    __Vtemp_105[2U] = (1U & __Vtemp_103[2U]);
    VL_ADD_W(3, __Vtemp_106, __Vtemp_99, __Vtemp_105);
    __Vtemp_108[0U] = __Vtemp_106[0U];
    __Vtemp_108[1U] = __Vtemp_106[1U];
    __Vtemp_108[2U] = (3U & __Vtemp_106[2U]);
    VL_ADD_W(3, __Vtemp_109, __Vtemp_92, __Vtemp_108);
    __Vtemp_111[0U] = __Vtemp_109[0U];
    __Vtemp_111[1U] = __Vtemp_109[1U];
    __Vtemp_111[2U] = (7U & __Vtemp_109[2U]);
    __Vtemp_115[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_8)
                                ? vlSelfRef.__PVT__buckets_count_8
                                : 0ULL));
    __Vtemp_115[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_8)
                                 ? vlSelfRef.__PVT__buckets_count_8
                                 : 0ULL) >> 0x20U));
    __Vtemp_115[2U] = 0U;
    __Vtemp_116[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_9)
                                ? vlSelfRef.__PVT__buckets_count_9
                                : 0ULL));
    __Vtemp_116[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_9)
                                 ? vlSelfRef.__PVT__buckets_count_9
                                 : 0ULL) >> 0x20U));
    __Vtemp_116[2U] = 0U;
    VL_ADD_W(3, __Vtemp_117, __Vtemp_115, __Vtemp_116);
    __Vtemp_119[0U] = __Vtemp_117[0U];
    __Vtemp_119[1U] = __Vtemp_117[1U];
    __Vtemp_119[2U] = (1U & __Vtemp_117[2U]);
    __Vtemp_121[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_10)
                                ? vlSelfRef.__PVT__buckets_count_10
                                : 0ULL));
    __Vtemp_121[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_10)
                                 ? vlSelfRef.__PVT__buckets_count_10
                                 : 0ULL) >> 0x20U));
    __Vtemp_121[2U] = 0U;
    __Vtemp_122[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_11)
                                ? vlSelfRef.__PVT__buckets_count_11
                                : 0ULL));
    __Vtemp_122[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_11)
                                 ? vlSelfRef.__PVT__buckets_count_11
                                 : 0ULL) >> 0x20U));
    __Vtemp_122[2U] = 0U;
    VL_ADD_W(3, __Vtemp_123, __Vtemp_121, __Vtemp_122);
    __Vtemp_125[0U] = __Vtemp_123[0U];
    __Vtemp_125[1U] = __Vtemp_123[1U];
    __Vtemp_125[2U] = (1U & __Vtemp_123[2U]);
    VL_ADD_W(3, __Vtemp_126, __Vtemp_119, __Vtemp_125);
    __Vtemp_128[0U] = __Vtemp_126[0U];
    __Vtemp_128[1U] = __Vtemp_126[1U];
    __Vtemp_128[2U] = (3U & __Vtemp_126[2U]);
    __Vtemp_131[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_12)
                                ? vlSelfRef.__PVT__buckets_count_12
                                : 0ULL));
    __Vtemp_131[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_12)
                                 ? vlSelfRef.__PVT__buckets_count_12
                                 : 0ULL) >> 0x20U));
    __Vtemp_131[2U] = 0U;
    __Vtemp_132[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_13)
                                ? vlSelfRef.__PVT__buckets_count_13
                                : 0ULL));
    __Vtemp_132[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_13)
                                 ? vlSelfRef.__PVT__buckets_count_13
                                 : 0ULL) >> 0x20U));
    __Vtemp_132[2U] = 0U;
    VL_ADD_W(3, __Vtemp_133, __Vtemp_131, __Vtemp_132);
    __Vtemp_135[0U] = __Vtemp_133[0U];
    __Vtemp_135[1U] = __Vtemp_133[1U];
    __Vtemp_135[2U] = (1U & __Vtemp_133[2U]);
    __Vtemp_137[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_14)
                                ? vlSelfRef.__PVT__buckets_count_14
                                : 0ULL));
    __Vtemp_137[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_14)
                                 ? vlSelfRef.__PVT__buckets_count_14
                                 : 0ULL) >> 0x20U));
    __Vtemp_137[2U] = 0U;
    __Vtemp_138[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_count_15
                                : 0ULL));
    __Vtemp_138[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                 ? vlSelfRef.__PVT__buckets_count_15
                                 : 0ULL) >> 0x20U));
    __Vtemp_138[2U] = 0U;
    VL_ADD_W(3, __Vtemp_139, __Vtemp_137, __Vtemp_138);
    __Vtemp_141[0U] = __Vtemp_139[0U];
    __Vtemp_141[1U] = __Vtemp_139[1U];
    __Vtemp_141[2U] = (1U & __Vtemp_139[2U]);
    VL_ADD_W(3, __Vtemp_142, __Vtemp_135, __Vtemp_141);
    __Vtemp_144[0U] = __Vtemp_142[0U];
    __Vtemp_144[1U] = __Vtemp_142[1U];
    __Vtemp_144[2U] = (3U & __Vtemp_142[2U]);
    VL_ADD_W(3, __Vtemp_145, __Vtemp_128, __Vtemp_144);
    __Vtemp_147[0U] = __Vtemp_145[0U];
    __Vtemp_147[1U] = __Vtemp_145[1U];
    __Vtemp_147[2U] = (7U & __Vtemp_145[2U]);
    VL_ADD_W(3, __Vtemp_148, __Vtemp_111, __Vtemp_147);
    vlSelfRef.io_resolvedCount[0U] = __Vtemp_148[0U];
    vlSelfRef.io_resolvedCount[1U] = __Vtemp_148[1U];
    vlSelfRef.io_resolvedCount[2U] = (0xfU & __Vtemp_148[2U]);
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_21;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_25;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_29;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_37;
    VlWide<3>/*95:0*/ __Vtemp_41;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_45;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_49;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_52;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_57;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_61;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_65;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_68;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_73;
    VlWide<3>/*95:0*/ __Vtemp_74;
    VlWide<3>/*95:0*/ __Vtemp_79;
    VlWide<3>/*95:0*/ __Vtemp_80;
    VlWide<3>/*95:0*/ __Vtemp_81;
    VlWide<3>/*95:0*/ __Vtemp_83;
    VlWide<3>/*95:0*/ __Vtemp_85;
    VlWide<3>/*95:0*/ __Vtemp_86;
    VlWide<3>/*95:0*/ __Vtemp_87;
    VlWide<3>/*95:0*/ __Vtemp_89;
    VlWide<3>/*95:0*/ __Vtemp_90;
    VlWide<3>/*95:0*/ __Vtemp_92;
    VlWide<3>/*95:0*/ __Vtemp_95;
    VlWide<3>/*95:0*/ __Vtemp_96;
    VlWide<3>/*95:0*/ __Vtemp_97;
    VlWide<3>/*95:0*/ __Vtemp_99;
    VlWide<3>/*95:0*/ __Vtemp_101;
    VlWide<3>/*95:0*/ __Vtemp_102;
    VlWide<3>/*95:0*/ __Vtemp_103;
    VlWide<3>/*95:0*/ __Vtemp_105;
    VlWide<3>/*95:0*/ __Vtemp_106;
    VlWide<3>/*95:0*/ __Vtemp_108;
    VlWide<3>/*95:0*/ __Vtemp_109;
    VlWide<3>/*95:0*/ __Vtemp_111;
    VlWide<3>/*95:0*/ __Vtemp_115;
    VlWide<3>/*95:0*/ __Vtemp_116;
    VlWide<3>/*95:0*/ __Vtemp_117;
    VlWide<3>/*95:0*/ __Vtemp_119;
    VlWide<3>/*95:0*/ __Vtemp_121;
    VlWide<3>/*95:0*/ __Vtemp_122;
    VlWide<3>/*95:0*/ __Vtemp_123;
    VlWide<3>/*95:0*/ __Vtemp_125;
    VlWide<3>/*95:0*/ __Vtemp_126;
    VlWide<3>/*95:0*/ __Vtemp_128;
    VlWide<3>/*95:0*/ __Vtemp_131;
    VlWide<3>/*95:0*/ __Vtemp_132;
    VlWide<3>/*95:0*/ __Vtemp_133;
    VlWide<3>/*95:0*/ __Vtemp_135;
    VlWide<3>/*95:0*/ __Vtemp_137;
    VlWide<3>/*95:0*/ __Vtemp_138;
    VlWide<3>/*95:0*/ __Vtemp_139;
    VlWide<3>/*95:0*/ __Vtemp_141;
    VlWide<3>/*95:0*/ __Vtemp_142;
    VlWide<3>/*95:0*/ __Vtemp_144;
    VlWide<3>/*95:0*/ __Vtemp_145;
    VlWide<3>/*95:0*/ __Vtemp_147;
    VlWide<3>/*95:0*/ __Vtemp_148;
    // Body
    vlSelfRef.__PVT___canAccept_T_31 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_10)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_10)));
    vlSelfRef.__PVT___GEN_165 = ((~ (IData)(vlSelfRef.__PVT__resolving_11)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_11));
    vlSelfRef.__PVT___canAccept_T_34 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_11)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_11)));
    vlSelfRef.__PVT___GEN_180 = ((~ (IData)(vlSelfRef.__PVT__resolving_12)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_12));
    vlSelfRef.__PVT___canAccept_T_37 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_12)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_12)));
    vlSelfRef.__PVT___GEN_195 = ((~ (IData)(vlSelfRef.__PVT__resolving_13)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_13));
    vlSelfRef.__PVT___canAccept_T_40 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_13)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_13)));
    vlSelfRef.__PVT___GEN_210 = ((~ (IData)(vlSelfRef.__PVT__resolving_14)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_14));
    vlSelfRef.__PVT___canAccept_T_43 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_14)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_14)));
    __Vtemp_5[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                              ? vlSelfRef.__PVT__buckets_requestCycleSum_0
                              : 0ULL));
    __Vtemp_5[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_0
                               : 0ULL) >> 0x20U));
    __Vtemp_5[2U] = 0U;
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_1)
                              ? vlSelfRef.__PVT__buckets_requestCycleSum_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_1)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    VL_ADD_W(3, __Vtemp_7, __Vtemp_5, __Vtemp_6);
    __Vtemp_9[0U] = __Vtemp_7[0U];
    __Vtemp_9[1U] = __Vtemp_7[1U];
    __Vtemp_9[2U] = (1U & __Vtemp_7[2U]);
    __Vtemp_11[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_2)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_2
                               : 0ULL));
    __Vtemp_11[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_2)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_2
                                : 0ULL) >> 0x20U));
    __Vtemp_11[2U] = 0U;
    __Vtemp_12[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_3)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_3
                               : 0ULL));
    __Vtemp_12[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_3)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_3
                                : 0ULL) >> 0x20U));
    __Vtemp_12[2U] = 0U;
    VL_ADD_W(3, __Vtemp_13, __Vtemp_11, __Vtemp_12);
    __Vtemp_15[0U] = __Vtemp_13[0U];
    __Vtemp_15[1U] = __Vtemp_13[1U];
    __Vtemp_15[2U] = (1U & __Vtemp_13[2U]);
    VL_ADD_W(3, __Vtemp_16, __Vtemp_9, __Vtemp_15);
    __Vtemp_18[0U] = __Vtemp_16[0U];
    __Vtemp_18[1U] = __Vtemp_16[1U];
    __Vtemp_18[2U] = (3U & __Vtemp_16[2U]);
    __Vtemp_21[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_4)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_4
                               : 0ULL));
    __Vtemp_21[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_4)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_4
                                : 0ULL) >> 0x20U));
    __Vtemp_21[2U] = 0U;
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_5)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_5
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_5)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_5
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    VL_ADD_W(3, __Vtemp_23, __Vtemp_21, __Vtemp_22);
    __Vtemp_25[0U] = __Vtemp_23[0U];
    __Vtemp_25[1U] = __Vtemp_23[1U];
    __Vtemp_25[2U] = (1U & __Vtemp_23[2U]);
    __Vtemp_27[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_6)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_6
                               : 0ULL));
    __Vtemp_27[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_6)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_6
                                : 0ULL) >> 0x20U));
    __Vtemp_27[2U] = 0U;
    __Vtemp_28[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_7)
                               ? vlSelfRef.buckets_requestCycleSum_7
                               : 0ULL));
    __Vtemp_28[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_requestCycleSum_7
                                : 0ULL) >> 0x20U));
    __Vtemp_28[2U] = 0U;
    VL_ADD_W(3, __Vtemp_29, __Vtemp_27, __Vtemp_28);
    __Vtemp_31[0U] = __Vtemp_29[0U];
    __Vtemp_31[1U] = __Vtemp_29[1U];
    __Vtemp_31[2U] = (1U & __Vtemp_29[2U]);
    VL_ADD_W(3, __Vtemp_32, __Vtemp_25, __Vtemp_31);
    __Vtemp_34[0U] = __Vtemp_32[0U];
    __Vtemp_34[1U] = __Vtemp_32[1U];
    __Vtemp_34[2U] = (3U & __Vtemp_32[2U]);
    VL_ADD_W(3, __Vtemp_35, __Vtemp_18, __Vtemp_34);
    __Vtemp_37[0U] = __Vtemp_35[0U];
    __Vtemp_37[1U] = __Vtemp_35[1U];
    __Vtemp_37[2U] = (7U & __Vtemp_35[2U]);
    __Vtemp_41[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_8)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_8
                               : 0ULL));
    __Vtemp_41[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_8)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_8
                                : 0ULL) >> 0x20U));
    __Vtemp_41[2U] = 0U;
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_9)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_9
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_9)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_9
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    VL_ADD_W(3, __Vtemp_43, __Vtemp_41, __Vtemp_42);
    __Vtemp_45[0U] = __Vtemp_43[0U];
    __Vtemp_45[1U] = __Vtemp_43[1U];
    __Vtemp_45[2U] = (1U & __Vtemp_43[2U]);
    __Vtemp_47[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_10)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_10
                               : 0ULL));
    __Vtemp_47[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_10)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_10
                                : 0ULL) >> 0x20U));
    __Vtemp_47[2U] = 0U;
    __Vtemp_48[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_11)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_11
                               : 0ULL));
    __Vtemp_48[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_11)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_11
                                : 0ULL) >> 0x20U));
    __Vtemp_48[2U] = 0U;
    VL_ADD_W(3, __Vtemp_49, __Vtemp_47, __Vtemp_48);
    __Vtemp_51[0U] = __Vtemp_49[0U];
    __Vtemp_51[1U] = __Vtemp_49[1U];
    __Vtemp_51[2U] = (1U & __Vtemp_49[2U]);
    VL_ADD_W(3, __Vtemp_52, __Vtemp_45, __Vtemp_51);
    __Vtemp_54[0U] = __Vtemp_52[0U];
    __Vtemp_54[1U] = __Vtemp_52[1U];
    __Vtemp_54[2U] = (3U & __Vtemp_52[2U]);
    __Vtemp_57[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_12)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_12
                               : 0ULL));
    __Vtemp_57[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_12)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_12
                                : 0ULL) >> 0x20U));
    __Vtemp_57[2U] = 0U;
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_13)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_13
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_13)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_13
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    VL_ADD_W(3, __Vtemp_59, __Vtemp_57, __Vtemp_58);
    __Vtemp_61[0U] = __Vtemp_59[0U];
    __Vtemp_61[1U] = __Vtemp_59[1U];
    __Vtemp_61[2U] = (1U & __Vtemp_59[2U]);
    __Vtemp_63[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_14)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_14
                               : 0ULL));
    __Vtemp_63[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_14)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_14
                                : 0ULL) >> 0x20U));
    __Vtemp_63[2U] = 0U;
    __Vtemp_64[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_15)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_15
                               : 0ULL));
    __Vtemp_64[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_15
                                : 0ULL) >> 0x20U));
    __Vtemp_64[2U] = 0U;
    VL_ADD_W(3, __Vtemp_65, __Vtemp_63, __Vtemp_64);
    __Vtemp_67[0U] = __Vtemp_65[0U];
    __Vtemp_67[1U] = __Vtemp_65[1U];
    __Vtemp_67[2U] = (1U & __Vtemp_65[2U]);
    VL_ADD_W(3, __Vtemp_68, __Vtemp_61, __Vtemp_67);
    __Vtemp_70[0U] = __Vtemp_68[0U];
    __Vtemp_70[1U] = __Vtemp_68[1U];
    __Vtemp_70[2U] = (3U & __Vtemp_68[2U]);
    VL_ADD_W(3, __Vtemp_71, __Vtemp_54, __Vtemp_70);
    __Vtemp_73[0U] = __Vtemp_71[0U];
    __Vtemp_73[1U] = __Vtemp_71[1U];
    __Vtemp_73[2U] = (7U & __Vtemp_71[2U]);
    VL_ADD_W(3, __Vtemp_74, __Vtemp_37, __Vtemp_73);
    vlSelfRef.io_resolvedRequest[0U] = __Vtemp_74[0U];
    vlSelfRef.io_resolvedRequest[1U] = __Vtemp_74[1U];
    vlSelfRef.io_resolvedRequest[2U] = (0xfU & __Vtemp_74[2U]);
    vlSelfRef.__PVT___GEN_225 = ((~ (IData)(vlSelfRef.__PVT__resolving_15)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_15));
    __Vtemp_79[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_count_0
                               : 0ULL));
    __Vtemp_79[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                                ? vlSelfRef.__PVT__buckets_count_0
                                : 0ULL) >> 0x20U));
    __Vtemp_79[2U] = 0U;
    __Vtemp_80[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_1)
                               ? vlSelfRef.__PVT__buckets_count_1
                               : 0ULL));
    __Vtemp_80[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_1)
                                ? vlSelfRef.__PVT__buckets_count_1
                                : 0ULL) >> 0x20U));
    __Vtemp_80[2U] = 0U;
    VL_ADD_W(3, __Vtemp_81, __Vtemp_79, __Vtemp_80);
    __Vtemp_83[0U] = __Vtemp_81[0U];
    __Vtemp_83[1U] = __Vtemp_81[1U];
    __Vtemp_83[2U] = (1U & __Vtemp_81[2U]);
    __Vtemp_85[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_2)
                               ? vlSelfRef.__PVT__buckets_count_2
                               : 0ULL));
    __Vtemp_85[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_2)
                                ? vlSelfRef.__PVT__buckets_count_2
                                : 0ULL) >> 0x20U));
    __Vtemp_85[2U] = 0U;
    __Vtemp_86[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_3)
                               ? vlSelfRef.__PVT__buckets_count_3
                               : 0ULL));
    __Vtemp_86[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_3)
                                ? vlSelfRef.__PVT__buckets_count_3
                                : 0ULL) >> 0x20U));
    __Vtemp_86[2U] = 0U;
    VL_ADD_W(3, __Vtemp_87, __Vtemp_85, __Vtemp_86);
    __Vtemp_89[0U] = __Vtemp_87[0U];
    __Vtemp_89[1U] = __Vtemp_87[1U];
    __Vtemp_89[2U] = (1U & __Vtemp_87[2U]);
    VL_ADD_W(3, __Vtemp_90, __Vtemp_83, __Vtemp_89);
    __Vtemp_92[0U] = __Vtemp_90[0U];
    __Vtemp_92[1U] = __Vtemp_90[1U];
    __Vtemp_92[2U] = (3U & __Vtemp_90[2U]);
    __Vtemp_95[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_4)
                               ? vlSelfRef.__PVT__buckets_count_4
                               : 0ULL));
    __Vtemp_95[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_4)
                                ? vlSelfRef.__PVT__buckets_count_4
                                : 0ULL) >> 0x20U));
    __Vtemp_95[2U] = 0U;
    __Vtemp_96[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_5)
                               ? vlSelfRef.__PVT__buckets_count_5
                               : 0ULL));
    __Vtemp_96[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_5)
                                ? vlSelfRef.__PVT__buckets_count_5
                                : 0ULL) >> 0x20U));
    __Vtemp_96[2U] = 0U;
    VL_ADD_W(3, __Vtemp_97, __Vtemp_95, __Vtemp_96);
    __Vtemp_99[0U] = __Vtemp_97[0U];
    __Vtemp_99[1U] = __Vtemp_97[1U];
    __Vtemp_99[2U] = (1U & __Vtemp_97[2U]);
    __Vtemp_101[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_6)
                                ? vlSelfRef.__PVT__buckets_count_6
                                : 0ULL));
    __Vtemp_101[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_6)
                                 ? vlSelfRef.__PVT__buckets_count_6
                                 : 0ULL) >> 0x20U));
    __Vtemp_101[2U] = 0U;
    __Vtemp_102[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_count_7
                                : 0ULL));
    __Vtemp_102[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                 ? vlSelfRef.buckets_count_7
                                 : 0ULL) >> 0x20U));
    __Vtemp_102[2U] = 0U;
    VL_ADD_W(3, __Vtemp_103, __Vtemp_101, __Vtemp_102);
    __Vtemp_105[0U] = __Vtemp_103[0U];
    __Vtemp_105[1U] = __Vtemp_103[1U];
    __Vtemp_105[2U] = (1U & __Vtemp_103[2U]);
    VL_ADD_W(3, __Vtemp_106, __Vtemp_99, __Vtemp_105);
    __Vtemp_108[0U] = __Vtemp_106[0U];
    __Vtemp_108[1U] = __Vtemp_106[1U];
    __Vtemp_108[2U] = (3U & __Vtemp_106[2U]);
    VL_ADD_W(3, __Vtemp_109, __Vtemp_92, __Vtemp_108);
    __Vtemp_111[0U] = __Vtemp_109[0U];
    __Vtemp_111[1U] = __Vtemp_109[1U];
    __Vtemp_111[2U] = (7U & __Vtemp_109[2U]);
    __Vtemp_115[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_8)
                                ? vlSelfRef.__PVT__buckets_count_8
                                : 0ULL));
    __Vtemp_115[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_8)
                                 ? vlSelfRef.__PVT__buckets_count_8
                                 : 0ULL) >> 0x20U));
    __Vtemp_115[2U] = 0U;
    __Vtemp_116[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_9)
                                ? vlSelfRef.__PVT__buckets_count_9
                                : 0ULL));
    __Vtemp_116[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_9)
                                 ? vlSelfRef.__PVT__buckets_count_9
                                 : 0ULL) >> 0x20U));
    __Vtemp_116[2U] = 0U;
    VL_ADD_W(3, __Vtemp_117, __Vtemp_115, __Vtemp_116);
    __Vtemp_119[0U] = __Vtemp_117[0U];
    __Vtemp_119[1U] = __Vtemp_117[1U];
    __Vtemp_119[2U] = (1U & __Vtemp_117[2U]);
    __Vtemp_121[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_10)
                                ? vlSelfRef.__PVT__buckets_count_10
                                : 0ULL));
    __Vtemp_121[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_10)
                                 ? vlSelfRef.__PVT__buckets_count_10
                                 : 0ULL) >> 0x20U));
    __Vtemp_121[2U] = 0U;
    __Vtemp_122[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_11)
                                ? vlSelfRef.__PVT__buckets_count_11
                                : 0ULL));
    __Vtemp_122[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_11)
                                 ? vlSelfRef.__PVT__buckets_count_11
                                 : 0ULL) >> 0x20U));
    __Vtemp_122[2U] = 0U;
    VL_ADD_W(3, __Vtemp_123, __Vtemp_121, __Vtemp_122);
    __Vtemp_125[0U] = __Vtemp_123[0U];
    __Vtemp_125[1U] = __Vtemp_123[1U];
    __Vtemp_125[2U] = (1U & __Vtemp_123[2U]);
    VL_ADD_W(3, __Vtemp_126, __Vtemp_119, __Vtemp_125);
    __Vtemp_128[0U] = __Vtemp_126[0U];
    __Vtemp_128[1U] = __Vtemp_126[1U];
    __Vtemp_128[2U] = (3U & __Vtemp_126[2U]);
    __Vtemp_131[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_12)
                                ? vlSelfRef.__PVT__buckets_count_12
                                : 0ULL));
    __Vtemp_131[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_12)
                                 ? vlSelfRef.__PVT__buckets_count_12
                                 : 0ULL) >> 0x20U));
    __Vtemp_131[2U] = 0U;
    __Vtemp_132[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_13)
                                ? vlSelfRef.__PVT__buckets_count_13
                                : 0ULL));
    __Vtemp_132[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_13)
                                 ? vlSelfRef.__PVT__buckets_count_13
                                 : 0ULL) >> 0x20U));
    __Vtemp_132[2U] = 0U;
    VL_ADD_W(3, __Vtemp_133, __Vtemp_131, __Vtemp_132);
    __Vtemp_135[0U] = __Vtemp_133[0U];
    __Vtemp_135[1U] = __Vtemp_133[1U];
    __Vtemp_135[2U] = (1U & __Vtemp_133[2U]);
    __Vtemp_137[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_14)
                                ? vlSelfRef.__PVT__buckets_count_14
                                : 0ULL));
    __Vtemp_137[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_14)
                                 ? vlSelfRef.__PVT__buckets_count_14
                                 : 0ULL) >> 0x20U));
    __Vtemp_137[2U] = 0U;
    __Vtemp_138[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_count_15
                                : 0ULL));
    __Vtemp_138[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                 ? vlSelfRef.__PVT__buckets_count_15
                                 : 0ULL) >> 0x20U));
    __Vtemp_138[2U] = 0U;
    VL_ADD_W(3, __Vtemp_139, __Vtemp_137, __Vtemp_138);
    __Vtemp_141[0U] = __Vtemp_139[0U];
    __Vtemp_141[1U] = __Vtemp_139[1U];
    __Vtemp_141[2U] = (1U & __Vtemp_139[2U]);
    VL_ADD_W(3, __Vtemp_142, __Vtemp_135, __Vtemp_141);
    __Vtemp_144[0U] = __Vtemp_142[0U];
    __Vtemp_144[1U] = __Vtemp_142[1U];
    __Vtemp_144[2U] = (3U & __Vtemp_142[2U]);
    VL_ADD_W(3, __Vtemp_145, __Vtemp_128, __Vtemp_144);
    __Vtemp_147[0U] = __Vtemp_145[0U];
    __Vtemp_147[1U] = __Vtemp_145[1U];
    __Vtemp_147[2U] = (7U & __Vtemp_145[2U]);
    VL_ADD_W(3, __Vtemp_148, __Vtemp_111, __Vtemp_147);
    vlSelfRef.io_resolvedCount[0U] = __Vtemp_148[0U];
    vlSelfRef.io_resolvedCount[1U] = __Vtemp_148[1U];
    vlSelfRef.io_resolvedCount[2U] = (0xfU & __Vtemp_148[2U]);
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___ctor_var_reset_0(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___ctor_var_reset_0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clock = 0;
    vlSelf->reset = 0;
    VL_ZERO_RESET_W(161, vlSelf->io_observe_0);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_1);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_2);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_3);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_4);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_5);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_6);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_7);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_8);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_9);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_10);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_11);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_12);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_13);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_14);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_15);
    vlSelf->io_base = 0;
    vlSelf->io_resetStats = 0;
    vlSelf->io_event_valid = 0;
    vlSelf->io_event_bits = 0;
    vlSelf->io_safeWatermark = 0;
    vlSelf->io_currentCycle = 0;
    VL_ZERO_RESET_W(68, vlSelf->io_resolvedCount);
    VL_ZERO_RESET_W(68, vlSelf->io_resolvedRequest);
    vlSelf->io_eventAvailable = 0;
    vlSelf->io_countOverflow = 0;
    vlSelf->io_cycleOverflow = 0;
    vlSelf->__PVT__buckets_valid_0 = 0;
    vlSelf->__PVT__buckets_valid_1 = 0;
    vlSelf->__PVT__buckets_valid_2 = 0;
    vlSelf->__PVT__buckets_valid_3 = 0;
    vlSelf->__PVT__buckets_valid_4 = 0;
    vlSelf->__PVT__buckets_valid_5 = 0;
    vlSelf->__PVT__buckets_valid_6 = 0;
    vlSelf->buckets_valid_7 = 0;
    vlSelf->__PVT__buckets_valid_8 = 0;
    vlSelf->__PVT__buckets_valid_9 = 0;
    vlSelf->__PVT__buckets_valid_10 = 0;
    vlSelf->__PVT__buckets_valid_11 = 0;
    vlSelf->__PVT__buckets_valid_12 = 0;
    vlSelf->__PVT__buckets_valid_13 = 0;
    vlSelf->__PVT__buckets_valid_14 = 0;
    vlSelf->__PVT__buckets_valid_15 = 0;
    vlSelf->__PVT__buckets_seq_0 = 0;
    vlSelf->__PVT__buckets_seq_1 = 0;
    vlSelf->__PVT__buckets_seq_2 = 0;
    vlSelf->__PVT__buckets_seq_3 = 0;
    vlSelf->__PVT__buckets_seq_4 = 0;
    vlSelf->__PVT__buckets_seq_5 = 0;
    vlSelf->__PVT__buckets_seq_6 = 0;
    vlSelf->buckets_seq_7 = 0;
    vlSelf->__PVT__buckets_seq_8 = 0;
    vlSelf->__PVT__buckets_seq_9 = 0;
    vlSelf->__PVT__buckets_seq_10 = 0;
    vlSelf->__PVT__buckets_seq_11 = 0;
    vlSelf->__PVT__buckets_seq_12 = 0;
    vlSelf->__PVT__buckets_seq_13 = 0;
    vlSelf->__PVT__buckets_seq_14 = 0;
    vlSelf->__PVT__buckets_seq_15 = 0;
    vlSelf->__PVT__buckets_count_0 = 0;
    vlSelf->__PVT__buckets_count_1 = 0;
    vlSelf->__PVT__buckets_count_2 = 0;
    vlSelf->__PVT__buckets_count_3 = 0;
    vlSelf->__PVT__buckets_count_4 = 0;
    vlSelf->__PVT__buckets_count_5 = 0;
    vlSelf->__PVT__buckets_count_6 = 0;
    vlSelf->buckets_count_7 = 0;
    vlSelf->__PVT__buckets_count_8 = 0;
    vlSelf->__PVT__buckets_count_9 = 0;
    vlSelf->__PVT__buckets_count_10 = 0;
    vlSelf->__PVT__buckets_count_11 = 0;
    vlSelf->__PVT__buckets_count_12 = 0;
    vlSelf->__PVT__buckets_count_13 = 0;
    vlSelf->__PVT__buckets_count_14 = 0;
    vlSelf->__PVT__buckets_count_15 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_0 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_1 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_2 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_3 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_4 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_5 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_6 = 0;
    vlSelf->buckets_requestCycleSum_7 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_8 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_9 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_10 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_11 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_12 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_13 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_14 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_15 = 0;
    vlSelf->__PVT__eventNeedsBucket = 0;
    vlSelf->__PVT__resolving_0 = 0;
    vlSelf->__PVT___canAccept_T_1 = 0;
    vlSelf->__PVT__accepted = 0;
    vlSelf->__PVT__available_0 = 0;
    vlSelf->__PVT___countOverflow_0_T_2 = 0;
    vlSelf->__PVT___GEN_0 = 0;
    vlSelf->__PVT___buckets_count_0_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_0_T_1 = 0;
    vlSelf->__PVT__resolving_1 = 0;
    vlSelf->__PVT___canAccept_T_4 = 0;
    vlSelf->__PVT__accepted_1 = 0;
    vlSelf->__PVT__available_1 = 0;
    vlSelf->__PVT___countOverflow_1_T_2 = 0;
    vlSelf->__PVT___GEN_15 = 0;
    vlSelf->__PVT___buckets_count_1_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_1_T_1 = 0;
    vlSelf->__PVT__resolving_2 = 0;
    vlSelf->__PVT___canAccept_T_7 = 0;
    vlSelf->__PVT__accepted_2 = 0;
    vlSelf->__PVT__available_2 = 0;
    vlSelf->__PVT___countOverflow_2_T_2 = 0;
    vlSelf->__PVT___GEN_30 = 0;
    vlSelf->__PVT___buckets_count_2_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_2_T_1 = 0;
    vlSelf->__PVT__resolving_3 = 0;
    vlSelf->__PVT___canAccept_T_10 = 0;
    vlSelf->__PVT__accepted_3 = 0;
    vlSelf->__PVT__available_3 = 0;
    vlSelf->__PVT___countOverflow_3_T_2 = 0;
    vlSelf->__PVT___GEN_45 = 0;
    vlSelf->__PVT___buckets_count_3_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_3_T_1 = 0;
    vlSelf->__PVT__resolving_4 = 0;
    vlSelf->__PVT___canAccept_T_13 = 0;
    vlSelf->__PVT__accepted_4 = 0;
    vlSelf->__PVT__available_4 = 0;
    vlSelf->__PVT___countOverflow_4_T_2 = 0;
    vlSelf->__PVT___GEN_60 = 0;
    vlSelf->__PVT___buckets_count_4_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_4_T_1 = 0;
    vlSelf->__PVT__resolving_5 = 0;
    vlSelf->__PVT___canAccept_T_16 = 0;
    vlSelf->__PVT__accepted_5 = 0;
    vlSelf->__PVT__available_5 = 0;
    vlSelf->__PVT___countOverflow_5_T_2 = 0;
    vlSelf->__PVT___GEN_75 = 0;
    vlSelf->__PVT___buckets_count_5_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_5_T_1 = 0;
    vlSelf->__PVT__resolving_6 = 0;
    vlSelf->__PVT___canAccept_T_19 = 0;
    vlSelf->__PVT__accepted_6 = 0;
    vlSelf->__PVT__available_6 = 0;
    vlSelf->__PVT___countOverflow_6_T_2 = 0;
    vlSelf->__PVT___GEN_90 = 0;
    vlSelf->__PVT___buckets_count_6_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_6_T_1 = 0;
    vlSelf->__PVT__resolving_7 = 0;
    vlSelf->__PVT___canAccept_T_22 = 0;
    vlSelf->__PVT__accepted_7 = 0;
    vlSelf->__PVT__available_7 = 0;
    vlSelf->__PVT___countOverflow_7_T_2 = 0;
    vlSelf->__PVT___GEN_105 = 0;
    vlSelf->__PVT___buckets_count_7_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_7_T_1 = 0;
    vlSelf->__PVT__resolving_8 = 0;
    vlSelf->__PVT___canAccept_T_25 = 0;
    vlSelf->__PVT__accepted_8 = 0;
    vlSelf->__PVT__available_8 = 0;
    vlSelf->__PVT___countOverflow_8_T_2 = 0;
    vlSelf->__PVT___GEN_120 = 0;
    vlSelf->__PVT___buckets_count_8_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_8_T_1 = 0;
    vlSelf->__PVT__resolving_9 = 0;
    vlSelf->__PVT___canAccept_T_28 = 0;
    vlSelf->__PVT__accepted_9 = 0;
    vlSelf->__PVT__available_9 = 0;
    vlSelf->__PVT___countOverflow_9_T_2 = 0;
    vlSelf->__PVT___GEN_135 = 0;
    vlSelf->__PVT___buckets_count_9_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_9_T_1 = 0;
    vlSelf->__PVT__resolving_10 = 0;
    vlSelf->__PVT___canAccept_T_31 = 0;
    vlSelf->__PVT__accepted_10 = 0;
    vlSelf->__PVT__available_10 = 0;
    vlSelf->__PVT___countOverflow_10_T_2 = 0;
    vlSelf->__PVT___GEN_150 = 0;
    vlSelf->__PVT___buckets_count_10_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_10_T_1 = 0;
    vlSelf->__PVT__resolving_11 = 0;
    vlSelf->__PVT___canAccept_T_34 = 0;
    vlSelf->__PVT__accepted_11 = 0;
    vlSelf->__PVT__available_11 = 0;
    vlSelf->__PVT___countOverflow_11_T_2 = 0;
    vlSelf->__PVT___GEN_165 = 0;
    vlSelf->__PVT___buckets_count_11_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_11_T_1 = 0;
    vlSelf->__PVT__resolving_12 = 0;
    vlSelf->__PVT___canAccept_T_37 = 0;
    vlSelf->__PVT__accepted_12 = 0;
    vlSelf->__PVT__available_12 = 0;
    vlSelf->__PVT___countOverflow_12_T_2 = 0;
    vlSelf->__PVT___GEN_180 = 0;
    vlSelf->__PVT___buckets_count_12_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_12_T_1 = 0;
    vlSelf->__PVT__resolving_13 = 0;
    vlSelf->__PVT___canAccept_T_40 = 0;
    vlSelf->__PVT__accepted_13 = 0;
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___ctor_var_reset_1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___ctor_var_reset_1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__available_13 = 0;
    vlSelf->__PVT___countOverflow_13_T_2 = 0;
    vlSelf->__PVT___GEN_195 = 0;
    vlSelf->__PVT___buckets_count_13_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_13_T_1 = 0;
    vlSelf->__PVT__resolving_14 = 0;
    vlSelf->__PVT___canAccept_T_43 = 0;
    vlSelf->__PVT__accepted_14 = 0;
    vlSelf->__PVT__available_14 = 0;
    vlSelf->__PVT___countOverflow_14_T_2 = 0;
    vlSelf->__PVT___GEN_210 = 0;
    vlSelf->__PVT___buckets_count_14_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_14_T_1 = 0;
    vlSelf->__PVT__resolving_15 = 0;
    vlSelf->__PVT___canAccept_T_46 = 0;
    vlSelf->__PVT__accepted_15 = 0;
    vlSelf->__PVT__available_15 = 0;
    vlSelf->__PVT___countOverflow_15_T_2 = 0;
    vlSelf->__PVT___GEN_225 = 0;
    vlSelf->__PVT___buckets_count_15_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_15_T_1 = 0;
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___ctor_var_reset(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_GHBarrierBucketBank___ctor_var_reset_0(vlSelf);
    Vtb_GHBarrierBucketBank___ctor_var_reset_1(vlSelf);
}
