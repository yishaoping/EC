// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__499(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__499\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_10;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_14;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_19;
    VlWide<3>/*95:0*/ __Vtemp_20;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_24;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_30;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_36;
    VlWide<3>/*95:0*/ __Vtemp_38;
    VlWide<3>/*95:0*/ __Vtemp_39;
    VlWide<3>/*95:0*/ __Vtemp_40;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_44;
    VlWide<3>/*95:0*/ __Vtemp_46;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_50;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_52;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_55;
    VlWide<3>/*95:0*/ __Vtemp_56;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_60;
    VlWide<3>/*95:0*/ __Vtemp_62;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_66;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_68;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_72;
    VlWide<3>/*95:0*/ __Vtemp_74;
    VlWide<3>/*95:0*/ __Vtemp_75;
    VlWide<3>/*95:0*/ __Vtemp_76;
    VlWide<3>/*95:0*/ __Vtemp_78;
    VlWide<3>/*95:0*/ __Vtemp_79;
    VlWide<3>/*95:0*/ __Vtemp_80;
    VlWide<3>/*95:0*/ __Vtemp_82;
    VlWide<3>/*95:0*/ __Vtemp_83;
    VlWide<3>/*95:0*/ __Vtemp_84;
    VlWide<3>/*95:0*/ __Vtemp_86;
    VlWide<3>/*95:0*/ __Vtemp_87;
    VlWide<3>/*95:0*/ __Vtemp_88;
    VlWide<3>/*95:0*/ __Vtemp_90;
    VlWide<3>/*95:0*/ __Vtemp_91;
    VlWide<3>/*95:0*/ __Vtemp_92;
    VlWide<3>/*95:0*/ __Vtemp_94;
    VlWide<3>/*95:0*/ __Vtemp_95;
    VlWide<3>/*95:0*/ __Vtemp_96;
    VlWide<3>/*95:0*/ __Vtemp_98;
    VlWide<3>/*95:0*/ __Vtemp_99;
    VlWide<3>/*95:0*/ __Vtemp_100;
    VlWide<3>/*95:0*/ __Vtemp_102;
    VlWide<3>/*95:0*/ __Vtemp_103;
    VlWide<3>/*95:0*/ __Vtemp_104;
    VlWide<3>/*95:0*/ __Vtemp_106;
    VlWide<3>/*95:0*/ __Vtemp_107;
    VlWide<3>/*95:0*/ __Vtemp_108;
    VlWide<3>/*95:0*/ __Vtemp_110;
    VlWide<3>/*95:0*/ __Vtemp_111;
    VlWide<3>/*95:0*/ __Vtemp_112;
    VlWide<3>/*95:0*/ __Vtemp_114;
    VlWide<3>/*95:0*/ __Vtemp_115;
    VlWide<3>/*95:0*/ __Vtemp_116;
    // Body
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_23_3);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_23_3 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_10462;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_95[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_95[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_95[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_24_3);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_24_3 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_10898;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_99[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_99[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_99[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_25_3);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_25_3 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_11334;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_103[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_103[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_103[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_26_3);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_26_3 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_11770;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_107[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_107[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_107[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_27_3);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_27_3 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_12206;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_111[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_111[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_111[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_28_3);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_28_3 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_12642;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_115[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_115[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_115[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_29_3);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_29_3 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_13078;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_119[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_119[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_119[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_30_3);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_30_3 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_13514;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_123[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_123[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_123[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_31_3);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_31_3 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_13950;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_127[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_127[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_127[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_0_1);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_0_1 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_352;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_1[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_1[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_1[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_1_1);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_1_1 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_788;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_5[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_5[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_5[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_2_1);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_2_1 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_1224;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_9[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_9[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_9[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_3_1);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_3_1 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_1660;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_13[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_13[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_13[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_4_1);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_4_1 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_2096;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_17[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_17[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_17[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_5_1);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_5_1 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_2532;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_21[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_21[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_21[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_6_1);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_6_1 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_2968;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_25[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_25[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_25[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_7_1);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_7_1 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_3404;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_29[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_29[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_29[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_8_1);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_8_1 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_3840;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_33[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_33[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_33[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_9_1);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_9_1 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_4276;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_37[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_37[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_37[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_10_1);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_10_1 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_4712;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_41[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_41[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_41[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_11_1);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_11_1 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_5148;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_45[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_45[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_45[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_12_1);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_12_1 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_5584;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_49[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_49[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_49[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_13_1);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_13_1 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_6020;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_53[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_53[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_53[2U] 
        = (1U & __Vtemp_92[2U]);
    __Vtemp_94[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_14_1);
    __Vtemp_94[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_14_1 
                              >> 0x20U));
    __Vtemp_94[2U] = 0U;
    __Vtemp_95[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_6456;
    __Vtemp_95[1U] = 0U;
    __Vtemp_95[2U] = 0U;
    VL_ADD_W(3, __Vtemp_96, __Vtemp_94, __Vtemp_95);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_57[0U] 
        = __Vtemp_96[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_57[1U] 
        = __Vtemp_96[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_57[2U] 
        = (1U & __Vtemp_96[2U]);
    __Vtemp_98[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_15_1);
    __Vtemp_98[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_15_1 
                              >> 0x20U));
    __Vtemp_98[2U] = 0U;
    __Vtemp_99[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_6892;
    __Vtemp_99[1U] = 0U;
    __Vtemp_99[2U] = 0U;
    VL_ADD_W(3, __Vtemp_100, __Vtemp_98, __Vtemp_99);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_61[0U] 
        = __Vtemp_100[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_61[1U] 
        = __Vtemp_100[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_61[2U] 
        = (1U & __Vtemp_100[2U]);
    __Vtemp_102[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_16_1);
    __Vtemp_102[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_16_1 
                               >> 0x20U));
    __Vtemp_102[2U] = 0U;
    __Vtemp_103[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_7328;
    __Vtemp_103[1U] = 0U;
    __Vtemp_103[2U] = 0U;
    VL_ADD_W(3, __Vtemp_104, __Vtemp_102, __Vtemp_103);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_65[0U] 
        = __Vtemp_104[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_65[1U] 
        = __Vtemp_104[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_65[2U] 
        = (1U & __Vtemp_104[2U]);
    __Vtemp_106[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_17_1);
    __Vtemp_106[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_17_1 
                               >> 0x20U));
    __Vtemp_106[2U] = 0U;
    __Vtemp_107[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_7764;
    __Vtemp_107[1U] = 0U;
    __Vtemp_107[2U] = 0U;
    VL_ADD_W(3, __Vtemp_108, __Vtemp_106, __Vtemp_107);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_69[0U] 
        = __Vtemp_108[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_69[1U] 
        = __Vtemp_108[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_69[2U] 
        = (1U & __Vtemp_108[2U]);
    __Vtemp_110[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_18_1);
    __Vtemp_110[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_18_1 
                               >> 0x20U));
    __Vtemp_110[2U] = 0U;
    __Vtemp_111[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_8200;
    __Vtemp_111[1U] = 0U;
    __Vtemp_111[2U] = 0U;
    VL_ADD_W(3, __Vtemp_112, __Vtemp_110, __Vtemp_111);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_73[0U] 
        = __Vtemp_112[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_73[1U] 
        = __Vtemp_112[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_73[2U] 
        = (1U & __Vtemp_112[2U]);
    __Vtemp_114[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_19_1);
    __Vtemp_114[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_19_1 
                               >> 0x20U));
    __Vtemp_114[2U] = 0U;
    __Vtemp_115[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_8636;
    __Vtemp_115[1U] = 0U;
    __Vtemp_115[2U] = 0U;
    VL_ADD_W(3, __Vtemp_116, __Vtemp_114, __Vtemp_115);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_77[0U] 
        = __Vtemp_116[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_77[1U] 
        = __Vtemp_116[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_77[2U] 
        = (1U & __Vtemp_116[2U]);
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__500(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__500\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_10;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_14;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_19;
    VlWide<3>/*95:0*/ __Vtemp_20;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_24;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_30;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_36;
    VlWide<3>/*95:0*/ __Vtemp_38;
    VlWide<3>/*95:0*/ __Vtemp_39;
    VlWide<3>/*95:0*/ __Vtemp_40;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_44;
    VlWide<3>/*95:0*/ __Vtemp_46;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_50;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_52;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_55;
    VlWide<3>/*95:0*/ __Vtemp_56;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_60;
    VlWide<3>/*95:0*/ __Vtemp_62;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_66;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_68;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_72;
    VlWide<3>/*95:0*/ __Vtemp_74;
    VlWide<3>/*95:0*/ __Vtemp_75;
    VlWide<3>/*95:0*/ __Vtemp_76;
    VlWide<3>/*95:0*/ __Vtemp_78;
    VlWide<3>/*95:0*/ __Vtemp_79;
    VlWide<3>/*95:0*/ __Vtemp_80;
    VlWide<3>/*95:0*/ __Vtemp_82;
    VlWide<3>/*95:0*/ __Vtemp_83;
    VlWide<3>/*95:0*/ __Vtemp_84;
    VlWide<3>/*95:0*/ __Vtemp_86;
    VlWide<3>/*95:0*/ __Vtemp_87;
    VlWide<3>/*95:0*/ __Vtemp_88;
    VlWide<3>/*95:0*/ __Vtemp_90;
    VlWide<3>/*95:0*/ __Vtemp_91;
    VlWide<3>/*95:0*/ __Vtemp_92;
    VlWide<3>/*95:0*/ __Vtemp_94;
    VlWide<3>/*95:0*/ __Vtemp_95;
    VlWide<3>/*95:0*/ __Vtemp_96;
    VlWide<3>/*95:0*/ __Vtemp_98;
    VlWide<3>/*95:0*/ __Vtemp_99;
    VlWide<3>/*95:0*/ __Vtemp_100;
    VlWide<3>/*95:0*/ __Vtemp_102;
    VlWide<3>/*95:0*/ __Vtemp_103;
    VlWide<3>/*95:0*/ __Vtemp_104;
    VlWide<3>/*95:0*/ __Vtemp_106;
    VlWide<3>/*95:0*/ __Vtemp_107;
    VlWide<3>/*95:0*/ __Vtemp_108;
    VlWide<3>/*95:0*/ __Vtemp_110;
    VlWide<3>/*95:0*/ __Vtemp_111;
    VlWide<3>/*95:0*/ __Vtemp_112;
    VlWide<3>/*95:0*/ __Vtemp_114;
    VlWide<3>/*95:0*/ __Vtemp_115;
    VlWide<3>/*95:0*/ __Vtemp_116;
    // Body
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_20_1);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_20_1 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_9072;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_81[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_81[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_81[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_21_1);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_21_1 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_9508;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_85[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_85[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_85[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_22_1);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_22_1 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_9944;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_89[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_89[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_89[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_23_1);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_23_1 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_10380;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_93[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_93[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_93[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_24_1);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_24_1 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_10816;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_97[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_97[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_97[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_25_1);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_25_1 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_11252;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_101[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_101[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_101[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_26_1);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_26_1 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_11688;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_105[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_105[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_105[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_27_1);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_27_1 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_12124;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_109[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_109[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_109[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_28_1);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_28_1 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_12560;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_113[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_113[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_113[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_29_1);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_29_1 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_12996;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_117[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_117[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_117[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_30_1);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_30_1 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_13432;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_121[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_121[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_121[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_31_1);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_31_1 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_13868;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_125[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_125[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_125[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_0_0);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_0_0 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_313;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_1_0);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_1_0 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_749;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_4[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_4[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_4[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_2_0);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_2_0 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_1185;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_8[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_8[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_8[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_3_0);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_3_0 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_1621;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_12[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_12[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_12[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_4_0);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_4_0 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2057;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_16[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_16[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_16[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_5_0);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_5_0 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2493;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_20[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_20[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_20[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_6_0);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_6_0 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2929;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_24[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_24[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_24[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_7_0);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_7_0 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3365;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_28[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_28[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_28[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_8_0);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_8_0 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3801;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_32[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_32[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_32[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_9_0);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_9_0 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_4237;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_36[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_36[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_36[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_10_0);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_10_0 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_4673;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_40[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_40[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_40[2U] 
        = (1U & __Vtemp_92[2U]);
    __Vtemp_94[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_11_0);
    __Vtemp_94[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_11_0 
                              >> 0x20U));
    __Vtemp_94[2U] = 0U;
    __Vtemp_95[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5109;
    __Vtemp_95[1U] = 0U;
    __Vtemp_95[2U] = 0U;
    VL_ADD_W(3, __Vtemp_96, __Vtemp_94, __Vtemp_95);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_44[0U] 
        = __Vtemp_96[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_44[1U] 
        = __Vtemp_96[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_44[2U] 
        = (1U & __Vtemp_96[2U]);
    __Vtemp_98[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_12_0);
    __Vtemp_98[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_12_0 
                              >> 0x20U));
    __Vtemp_98[2U] = 0U;
    __Vtemp_99[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5545;
    __Vtemp_99[1U] = 0U;
    __Vtemp_99[2U] = 0U;
    VL_ADD_W(3, __Vtemp_100, __Vtemp_98, __Vtemp_99);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_48[0U] 
        = __Vtemp_100[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_48[1U] 
        = __Vtemp_100[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_48[2U] 
        = (1U & __Vtemp_100[2U]);
    __Vtemp_102[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_13_0);
    __Vtemp_102[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_13_0 
                               >> 0x20U));
    __Vtemp_102[2U] = 0U;
    __Vtemp_103[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5981;
    __Vtemp_103[1U] = 0U;
    __Vtemp_103[2U] = 0U;
    VL_ADD_W(3, __Vtemp_104, __Vtemp_102, __Vtemp_103);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_52[0U] 
        = __Vtemp_104[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_52[1U] 
        = __Vtemp_104[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_52[2U] 
        = (1U & __Vtemp_104[2U]);
    __Vtemp_106[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_14_0);
    __Vtemp_106[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_14_0 
                               >> 0x20U));
    __Vtemp_106[2U] = 0U;
    __Vtemp_107[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6417;
    __Vtemp_107[1U] = 0U;
    __Vtemp_107[2U] = 0U;
    VL_ADD_W(3, __Vtemp_108, __Vtemp_106, __Vtemp_107);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_56[0U] 
        = __Vtemp_108[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_56[1U] 
        = __Vtemp_108[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_56[2U] 
        = (1U & __Vtemp_108[2U]);
    __Vtemp_110[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_15_0);
    __Vtemp_110[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_15_0 
                               >> 0x20U));
    __Vtemp_110[2U] = 0U;
    __Vtemp_111[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6853;
    __Vtemp_111[1U] = 0U;
    __Vtemp_111[2U] = 0U;
    VL_ADD_W(3, __Vtemp_112, __Vtemp_110, __Vtemp_111);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_60[0U] 
        = __Vtemp_112[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_60[1U] 
        = __Vtemp_112[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_60[2U] 
        = (1U & __Vtemp_112[2U]);
    __Vtemp_114[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_16_0);
    __Vtemp_114[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_16_0 
                               >> 0x20U));
    __Vtemp_114[2U] = 0U;
    __Vtemp_115[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_7289;
    __Vtemp_115[1U] = 0U;
    __Vtemp_115[2U] = 0U;
    VL_ADD_W(3, __Vtemp_116, __Vtemp_114, __Vtemp_115);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_64[0U] 
        = __Vtemp_116[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_64[1U] 
        = __Vtemp_116[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_64[2U] 
        = (1U & __Vtemp_116[2U]);
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__501(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__501\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_10;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_14;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_19;
    VlWide<3>/*95:0*/ __Vtemp_20;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_24;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_30;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_36;
    VlWide<3>/*95:0*/ __Vtemp_38;
    VlWide<3>/*95:0*/ __Vtemp_39;
    VlWide<3>/*95:0*/ __Vtemp_40;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_44;
    VlWide<3>/*95:0*/ __Vtemp_46;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_50;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_52;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_55;
    VlWide<3>/*95:0*/ __Vtemp_56;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_60;
    VlWide<3>/*95:0*/ __Vtemp_62;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_66;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_68;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_72;
    VlWide<3>/*95:0*/ __Vtemp_74;
    VlWide<3>/*95:0*/ __Vtemp_75;
    VlWide<3>/*95:0*/ __Vtemp_76;
    VlWide<3>/*95:0*/ __Vtemp_78;
    VlWide<3>/*95:0*/ __Vtemp_79;
    VlWide<3>/*95:0*/ __Vtemp_80;
    VlWide<3>/*95:0*/ __Vtemp_82;
    VlWide<3>/*95:0*/ __Vtemp_83;
    VlWide<3>/*95:0*/ __Vtemp_84;
    VlWide<3>/*95:0*/ __Vtemp_86;
    VlWide<3>/*95:0*/ __Vtemp_87;
    VlWide<3>/*95:0*/ __Vtemp_88;
    VlWide<3>/*95:0*/ __Vtemp_90;
    VlWide<3>/*95:0*/ __Vtemp_91;
    VlWide<3>/*95:0*/ __Vtemp_92;
    VlWide<3>/*95:0*/ __Vtemp_94;
    VlWide<3>/*95:0*/ __Vtemp_95;
    VlWide<3>/*95:0*/ __Vtemp_96;
    VlWide<3>/*95:0*/ __Vtemp_98;
    VlWide<3>/*95:0*/ __Vtemp_99;
    VlWide<3>/*95:0*/ __Vtemp_100;
    VlWide<3>/*95:0*/ __Vtemp_102;
    VlWide<3>/*95:0*/ __Vtemp_103;
    VlWide<3>/*95:0*/ __Vtemp_104;
    VlWide<3>/*95:0*/ __Vtemp_106;
    VlWide<3>/*95:0*/ __Vtemp_107;
    VlWide<3>/*95:0*/ __Vtemp_108;
    VlWide<3>/*95:0*/ __Vtemp_110;
    VlWide<3>/*95:0*/ __Vtemp_111;
    VlWide<3>/*95:0*/ __Vtemp_112;
    VlWide<3>/*95:0*/ __Vtemp_114;
    VlWide<3>/*95:0*/ __Vtemp_115;
    VlWide<3>/*95:0*/ __Vtemp_116;
    // Body
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_17_0);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_17_0 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_7725;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_68[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_68[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_68[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_18_0);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_18_0 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_8161;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_72[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_72[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_72[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_19_0);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_19_0 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_8597;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_76[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_76[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_76[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_20_0);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_20_0 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9033;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_80[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_80[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_80[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_21_0);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_21_0 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9469;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_84[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_84[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_84[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_22_0);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_22_0 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9905;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_88[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_88[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_88[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_23_0);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_23_0 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10341;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_92[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_92[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_92[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_24_0);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_24_0 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10777;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_96[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_96[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_96[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_25_0);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_25_0 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_11213;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_100[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_100[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_100[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_26_0);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_26_0 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_11649;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_104[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_104[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_104[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_27_0);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_27_0 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12085;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_108[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_108[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_108[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_28_0);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_28_0 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12521;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_112[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_112[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_112[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_29_0);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_29_0 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12957;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_116[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_116[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_116[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_30_0);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_30_0 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13393;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_120[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_120[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_120[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_31_0);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_31_0 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13829;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_124[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_124[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_124[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_0_2);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_0_2 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_393;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_2[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_2[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_2[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_1_2);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_1_2 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_829;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_6[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_6[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_6[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_2_2);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_2_2 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_1265;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_10[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_10[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_10[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_3_2);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_3_2 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_1701;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_14[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_14[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_14[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_4_2);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_4_2 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2137;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_18[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_18[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_18[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_5_2);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_5_2 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2573;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_22[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_22[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_22[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_6_2);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_6_2 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3009;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_26[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_26[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_26[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_7_2);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_7_2 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3445;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_30[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_30[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_30[2U] 
        = (1U & __Vtemp_92[2U]);
    __Vtemp_94[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_8_2);
    __Vtemp_94[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_8_2 
                              >> 0x20U));
    __Vtemp_94[2U] = 0U;
    __Vtemp_95[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3881;
    __Vtemp_95[1U] = 0U;
    __Vtemp_95[2U] = 0U;
    VL_ADD_W(3, __Vtemp_96, __Vtemp_94, __Vtemp_95);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_34[0U] 
        = __Vtemp_96[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_34[1U] 
        = __Vtemp_96[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_34[2U] 
        = (1U & __Vtemp_96[2U]);
    __Vtemp_98[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_9_2);
    __Vtemp_98[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_9_2 
                              >> 0x20U));
    __Vtemp_98[2U] = 0U;
    __Vtemp_99[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_4317;
    __Vtemp_99[1U] = 0U;
    __Vtemp_99[2U] = 0U;
    VL_ADD_W(3, __Vtemp_100, __Vtemp_98, __Vtemp_99);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_38[0U] 
        = __Vtemp_100[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_38[1U] 
        = __Vtemp_100[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_38[2U] 
        = (1U & __Vtemp_100[2U]);
    __Vtemp_102[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_10_2);
    __Vtemp_102[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_10_2 
                               >> 0x20U));
    __Vtemp_102[2U] = 0U;
    __Vtemp_103[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_4753;
    __Vtemp_103[1U] = 0U;
    __Vtemp_103[2U] = 0U;
    VL_ADD_W(3, __Vtemp_104, __Vtemp_102, __Vtemp_103);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_42[0U] 
        = __Vtemp_104[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_42[1U] 
        = __Vtemp_104[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_42[2U] 
        = (1U & __Vtemp_104[2U]);
    __Vtemp_106[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_11_2);
    __Vtemp_106[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_11_2 
                               >> 0x20U));
    __Vtemp_106[2U] = 0U;
    __Vtemp_107[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5189;
    __Vtemp_107[1U] = 0U;
    __Vtemp_107[2U] = 0U;
    VL_ADD_W(3, __Vtemp_108, __Vtemp_106, __Vtemp_107);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_46[0U] 
        = __Vtemp_108[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_46[1U] 
        = __Vtemp_108[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_46[2U] 
        = (1U & __Vtemp_108[2U]);
    __Vtemp_110[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_12_2);
    __Vtemp_110[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_12_2 
                               >> 0x20U));
    __Vtemp_110[2U] = 0U;
    __Vtemp_111[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5625;
    __Vtemp_111[1U] = 0U;
    __Vtemp_111[2U] = 0U;
    VL_ADD_W(3, __Vtemp_112, __Vtemp_110, __Vtemp_111);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_50[0U] 
        = __Vtemp_112[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_50[1U] 
        = __Vtemp_112[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_50[2U] 
        = (1U & __Vtemp_112[2U]);
    __Vtemp_114[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_13_2);
    __Vtemp_114[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_13_2 
                               >> 0x20U));
    __Vtemp_114[2U] = 0U;
    __Vtemp_115[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6061;
    __Vtemp_115[1U] = 0U;
    __Vtemp_115[2U] = 0U;
    VL_ADD_W(3, __Vtemp_116, __Vtemp_114, __Vtemp_115);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_54[0U] 
        = __Vtemp_116[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_54[1U] 
        = __Vtemp_116[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_54[2U] 
        = (1U & __Vtemp_116[2U]);
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__502(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__502\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_10;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_14;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_19;
    VlWide<3>/*95:0*/ __Vtemp_20;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_24;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_30;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_36;
    VlWide<3>/*95:0*/ __Vtemp_38;
    VlWide<3>/*95:0*/ __Vtemp_39;
    VlWide<3>/*95:0*/ __Vtemp_40;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_44;
    VlWide<3>/*95:0*/ __Vtemp_46;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_50;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_52;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_55;
    VlWide<3>/*95:0*/ __Vtemp_56;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_60;
    VlWide<3>/*95:0*/ __Vtemp_62;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_66;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_68;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_72;
    VlWide<3>/*95:0*/ __Vtemp_74;
    VlWide<3>/*95:0*/ __Vtemp_75;
    VlWide<3>/*95:0*/ __Vtemp_76;
    VlWide<3>/*95:0*/ __Vtemp_78;
    VlWide<3>/*95:0*/ __Vtemp_79;
    VlWide<3>/*95:0*/ __Vtemp_80;
    VlWide<3>/*95:0*/ __Vtemp_82;
    VlWide<3>/*95:0*/ __Vtemp_83;
    VlWide<3>/*95:0*/ __Vtemp_84;
    VlWide<3>/*95:0*/ __Vtemp_86;
    VlWide<3>/*95:0*/ __Vtemp_87;
    VlWide<3>/*95:0*/ __Vtemp_88;
    VlWide<3>/*95:0*/ __Vtemp_90;
    VlWide<3>/*95:0*/ __Vtemp_91;
    VlWide<3>/*95:0*/ __Vtemp_92;
    VlWide<3>/*95:0*/ __Vtemp_94;
    VlWide<3>/*95:0*/ __Vtemp_95;
    VlWide<3>/*95:0*/ __Vtemp_96;
    VlWide<3>/*95:0*/ __Vtemp_98;
    VlWide<3>/*95:0*/ __Vtemp_99;
    VlWide<3>/*95:0*/ __Vtemp_100;
    VlWide<3>/*95:0*/ __Vtemp_102;
    VlWide<3>/*95:0*/ __Vtemp_103;
    VlWide<3>/*95:0*/ __Vtemp_104;
    VlWide<3>/*95:0*/ __Vtemp_106;
    VlWide<3>/*95:0*/ __Vtemp_107;
    VlWide<3>/*95:0*/ __Vtemp_108;
    VlWide<3>/*95:0*/ __Vtemp_110;
    VlWide<3>/*95:0*/ __Vtemp_111;
    VlWide<3>/*95:0*/ __Vtemp_112;
    VlWide<3>/*95:0*/ __Vtemp_114;
    VlWide<3>/*95:0*/ __Vtemp_115;
    VlWide<3>/*95:0*/ __Vtemp_116;
    // Body
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_14_2);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_14_2 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6497;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_58[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_58[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_58[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_15_2);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_15_2 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6933;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_62[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_62[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_62[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_16_2);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_16_2 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_7369;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_66[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_66[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_66[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_17_2);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_17_2 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_7805;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_70[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_70[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_70[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_18_2);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_18_2 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_8241;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_74[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_74[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_74[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_19_2);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_19_2 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_8677;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_78[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_78[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_78[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_20_2);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_20_2 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9113;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_82[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_82[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_82[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_21_2);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_21_2 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9549;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_86[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_86[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_86[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_22_2);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_22_2 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9985;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_90[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_90[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_90[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_23_2);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_23_2 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10421;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_94[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_94[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_94[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_24_2);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_24_2 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10857;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_98[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_98[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_98[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_25_2);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_25_2 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_11293;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_102[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_102[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_102[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_26_2);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_26_2 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_11729;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_106[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_106[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_106[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_27_2);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_27_2 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12165;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_110[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_110[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_110[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_28_2);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_28_2 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12601;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_114[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_114[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_114[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_29_2);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_29_2 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13037;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_118[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_118[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_118[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_30_2);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_30_2 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13473;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_122[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_122[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_122[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_31_2);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_31_2 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13909;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_126[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_126[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_126[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_0_3);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_0_3 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_434;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_3[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_3[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_3[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_1_3);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_1_3 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_870;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_7[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_7[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_7[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_2_3);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_2_3 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_1306;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_11[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_11[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_11[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_3_3);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_3_3 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_1742;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_15[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_15[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_15[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_4_3);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_4_3 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2178;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_19[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_19[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_19[2U] 
        = (1U & __Vtemp_92[2U]);
    __Vtemp_94[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_5_3);
    __Vtemp_94[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_5_3 
                              >> 0x20U));
    __Vtemp_94[2U] = 0U;
    __Vtemp_95[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2614;
    __Vtemp_95[1U] = 0U;
    __Vtemp_95[2U] = 0U;
    VL_ADD_W(3, __Vtemp_96, __Vtemp_94, __Vtemp_95);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_23[0U] 
        = __Vtemp_96[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_23[1U] 
        = __Vtemp_96[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_23[2U] 
        = (1U & __Vtemp_96[2U]);
    __Vtemp_98[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_6_3);
    __Vtemp_98[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_6_3 
                              >> 0x20U));
    __Vtemp_98[2U] = 0U;
    __Vtemp_99[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3050;
    __Vtemp_99[1U] = 0U;
    __Vtemp_99[2U] = 0U;
    VL_ADD_W(3, __Vtemp_100, __Vtemp_98, __Vtemp_99);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_27[0U] 
        = __Vtemp_100[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_27[1U] 
        = __Vtemp_100[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_27[2U] 
        = (1U & __Vtemp_100[2U]);
    __Vtemp_102[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_7_3);
    __Vtemp_102[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_7_3 
                               >> 0x20U));
    __Vtemp_102[2U] = 0U;
    __Vtemp_103[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3486;
    __Vtemp_103[1U] = 0U;
    __Vtemp_103[2U] = 0U;
    VL_ADD_W(3, __Vtemp_104, __Vtemp_102, __Vtemp_103);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_31[0U] 
        = __Vtemp_104[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_31[1U] 
        = __Vtemp_104[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_31[2U] 
        = (1U & __Vtemp_104[2U]);
    __Vtemp_106[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_8_3);
    __Vtemp_106[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_8_3 
                               >> 0x20U));
    __Vtemp_106[2U] = 0U;
    __Vtemp_107[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3922;
    __Vtemp_107[1U] = 0U;
    __Vtemp_107[2U] = 0U;
    VL_ADD_W(3, __Vtemp_108, __Vtemp_106, __Vtemp_107);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_35[0U] 
        = __Vtemp_108[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_35[1U] 
        = __Vtemp_108[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_35[2U] 
        = (1U & __Vtemp_108[2U]);
    __Vtemp_110[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_9_3);
    __Vtemp_110[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_9_3 
                               >> 0x20U));
    __Vtemp_110[2U] = 0U;
    __Vtemp_111[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_4358;
    __Vtemp_111[1U] = 0U;
    __Vtemp_111[2U] = 0U;
    VL_ADD_W(3, __Vtemp_112, __Vtemp_110, __Vtemp_111);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_39[0U] 
        = __Vtemp_112[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_39[1U] 
        = __Vtemp_112[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_39[2U] 
        = (1U & __Vtemp_112[2U]);
    __Vtemp_114[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_10_3);
    __Vtemp_114[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_10_3 
                               >> 0x20U));
    __Vtemp_114[2U] = 0U;
    __Vtemp_115[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_4794;
    __Vtemp_115[1U] = 0U;
    __Vtemp_115[2U] = 0U;
    VL_ADD_W(3, __Vtemp_116, __Vtemp_114, __Vtemp_115);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_43[0U] 
        = __Vtemp_116[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_43[1U] 
        = __Vtemp_116[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_43[2U] 
        = (1U & __Vtemp_116[2U]);
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__503(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__503\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_10;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_14;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_19;
    VlWide<3>/*95:0*/ __Vtemp_20;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_24;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_30;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_36;
    VlWide<3>/*95:0*/ __Vtemp_38;
    VlWide<3>/*95:0*/ __Vtemp_39;
    VlWide<3>/*95:0*/ __Vtemp_40;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_44;
    VlWide<3>/*95:0*/ __Vtemp_46;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_50;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_52;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_55;
    VlWide<3>/*95:0*/ __Vtemp_56;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_60;
    VlWide<3>/*95:0*/ __Vtemp_62;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_66;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_68;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_72;
    VlWide<3>/*95:0*/ __Vtemp_74;
    VlWide<3>/*95:0*/ __Vtemp_75;
    VlWide<3>/*95:0*/ __Vtemp_76;
    VlWide<3>/*95:0*/ __Vtemp_78;
    VlWide<3>/*95:0*/ __Vtemp_79;
    VlWide<3>/*95:0*/ __Vtemp_80;
    VlWide<3>/*95:0*/ __Vtemp_82;
    VlWide<3>/*95:0*/ __Vtemp_83;
    VlWide<3>/*95:0*/ __Vtemp_84;
    VlWide<3>/*95:0*/ __Vtemp_86;
    VlWide<3>/*95:0*/ __Vtemp_87;
    VlWide<3>/*95:0*/ __Vtemp_88;
    VlWide<3>/*95:0*/ __Vtemp_90;
    VlWide<3>/*95:0*/ __Vtemp_91;
    VlWide<3>/*95:0*/ __Vtemp_92;
    VlWide<3>/*95:0*/ __Vtemp_94;
    VlWide<3>/*95:0*/ __Vtemp_95;
    VlWide<3>/*95:0*/ __Vtemp_96;
    VlWide<3>/*95:0*/ __Vtemp_98;
    VlWide<3>/*95:0*/ __Vtemp_99;
    VlWide<3>/*95:0*/ __Vtemp_100;
    VlWide<3>/*95:0*/ __Vtemp_102;
    VlWide<3>/*95:0*/ __Vtemp_103;
    VlWide<3>/*95:0*/ __Vtemp_104;
    VlWide<3>/*95:0*/ __Vtemp_106;
    VlWide<3>/*95:0*/ __Vtemp_107;
    VlWide<3>/*95:0*/ __Vtemp_108;
    VlWide<3>/*95:0*/ __Vtemp_110;
    VlWide<3>/*95:0*/ __Vtemp_111;
    VlWide<3>/*95:0*/ __Vtemp_112;
    VlWide<3>/*95:0*/ __Vtemp_114;
    VlWide<3>/*95:0*/ __Vtemp_115;
    VlWide<3>/*95:0*/ __Vtemp_116;
    // Body
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_11_3);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_11_3 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5230;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_47[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_47[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_47[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_12_3);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_12_3 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5666;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_51[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_51[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_51[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_13_3);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_13_3 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6102;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_55[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_55[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_55[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_14_3);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_14_3 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6538;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_59[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_59[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_59[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_15_3);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_15_3 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6974;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_63[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_63[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_63[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_16_3);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_16_3 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_7410;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_67[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_67[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_67[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_17_3);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_17_3 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_7846;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_71[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_71[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_71[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_18_3);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_18_3 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_8282;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_75[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_75[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_75[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_19_3);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_19_3 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_8718;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_79[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_79[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_79[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_20_3);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_20_3 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9154;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_83[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_83[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_83[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_21_3);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_21_3 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9590;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_87[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_87[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_87[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_22_3);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_22_3 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10026;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_91[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_91[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_91[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_23_3);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_23_3 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10462;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_95[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_95[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_95[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_24_3);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_24_3 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10898;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_99[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_99[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_99[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_25_3);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_25_3 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_11334;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_103[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_103[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_103[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_26_3);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_26_3 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_11770;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_107[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_107[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_107[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_27_3);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_27_3 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12206;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_111[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_111[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_111[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_28_3);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_28_3 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12642;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_115[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_115[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_115[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_29_3);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_29_3 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13078;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_119[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_119[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_119[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_30_3);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_30_3 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13514;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_123[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_123[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_123[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_31_3);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_31_3 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13950;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_127[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_127[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_127[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_0_1);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_0_1 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_352;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_1[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_1[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_1[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_1_1);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_1_1 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_788;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_5[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_5[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_5[2U] 
        = (1U & __Vtemp_92[2U]);
    __Vtemp_94[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_2_1);
    __Vtemp_94[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_2_1 
                              >> 0x20U));
    __Vtemp_94[2U] = 0U;
    __Vtemp_95[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_1224;
    __Vtemp_95[1U] = 0U;
    __Vtemp_95[2U] = 0U;
    VL_ADD_W(3, __Vtemp_96, __Vtemp_94, __Vtemp_95);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_9[0U] 
        = __Vtemp_96[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_9[1U] 
        = __Vtemp_96[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_9[2U] 
        = (1U & __Vtemp_96[2U]);
    __Vtemp_98[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_3_1);
    __Vtemp_98[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_3_1 
                              >> 0x20U));
    __Vtemp_98[2U] = 0U;
    __Vtemp_99[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_1660;
    __Vtemp_99[1U] = 0U;
    __Vtemp_99[2U] = 0U;
    VL_ADD_W(3, __Vtemp_100, __Vtemp_98, __Vtemp_99);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_13[0U] 
        = __Vtemp_100[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_13[1U] 
        = __Vtemp_100[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_13[2U] 
        = (1U & __Vtemp_100[2U]);
    __Vtemp_102[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_4_1);
    __Vtemp_102[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_4_1 
                               >> 0x20U));
    __Vtemp_102[2U] = 0U;
    __Vtemp_103[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2096;
    __Vtemp_103[1U] = 0U;
    __Vtemp_103[2U] = 0U;
    VL_ADD_W(3, __Vtemp_104, __Vtemp_102, __Vtemp_103);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_17[0U] 
        = __Vtemp_104[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_17[1U] 
        = __Vtemp_104[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_17[2U] 
        = (1U & __Vtemp_104[2U]);
    __Vtemp_106[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_5_1);
    __Vtemp_106[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_5_1 
                               >> 0x20U));
    __Vtemp_106[2U] = 0U;
    __Vtemp_107[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2532;
    __Vtemp_107[1U] = 0U;
    __Vtemp_107[2U] = 0U;
    VL_ADD_W(3, __Vtemp_108, __Vtemp_106, __Vtemp_107);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_21[0U] 
        = __Vtemp_108[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_21[1U] 
        = __Vtemp_108[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_21[2U] 
        = (1U & __Vtemp_108[2U]);
    __Vtemp_110[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_6_1);
    __Vtemp_110[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_6_1 
                               >> 0x20U));
    __Vtemp_110[2U] = 0U;
    __Vtemp_111[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2968;
    __Vtemp_111[1U] = 0U;
    __Vtemp_111[2U] = 0U;
    VL_ADD_W(3, __Vtemp_112, __Vtemp_110, __Vtemp_111);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_25[0U] 
        = __Vtemp_112[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_25[1U] 
        = __Vtemp_112[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_25[2U] 
        = (1U & __Vtemp_112[2U]);
    __Vtemp_114[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_7_1);
    __Vtemp_114[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_7_1 
                               >> 0x20U));
    __Vtemp_114[2U] = 0U;
    __Vtemp_115[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3404;
    __Vtemp_115[1U] = 0U;
    __Vtemp_115[2U] = 0U;
    VL_ADD_W(3, __Vtemp_116, __Vtemp_114, __Vtemp_115);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_29[0U] 
        = __Vtemp_116[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_29[1U] 
        = __Vtemp_116[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_29[2U] 
        = (1U & __Vtemp_116[2U]);
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__504(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__504\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_10;
    VlWide<3>/*95:0*/ __Vtemp_11;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_14;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_19;
    VlWide<3>/*95:0*/ __Vtemp_20;
    VlWide<3>/*95:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<3>/*95:0*/ __Vtemp_24;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<3>/*95:0*/ __Vtemp_27;
    VlWide<3>/*95:0*/ __Vtemp_28;
    VlWide<3>/*95:0*/ __Vtemp_30;
    VlWide<3>/*95:0*/ __Vtemp_31;
    VlWide<3>/*95:0*/ __Vtemp_32;
    VlWide<3>/*95:0*/ __Vtemp_34;
    VlWide<3>/*95:0*/ __Vtemp_35;
    VlWide<3>/*95:0*/ __Vtemp_36;
    VlWide<3>/*95:0*/ __Vtemp_38;
    VlWide<3>/*95:0*/ __Vtemp_39;
    VlWide<3>/*95:0*/ __Vtemp_40;
    VlWide<3>/*95:0*/ __Vtemp_42;
    VlWide<3>/*95:0*/ __Vtemp_43;
    VlWide<3>/*95:0*/ __Vtemp_44;
    VlWide<3>/*95:0*/ __Vtemp_46;
    VlWide<3>/*95:0*/ __Vtemp_47;
    VlWide<3>/*95:0*/ __Vtemp_48;
    VlWide<3>/*95:0*/ __Vtemp_50;
    VlWide<3>/*95:0*/ __Vtemp_51;
    VlWide<3>/*95:0*/ __Vtemp_52;
    VlWide<3>/*95:0*/ __Vtemp_54;
    VlWide<3>/*95:0*/ __Vtemp_55;
    VlWide<3>/*95:0*/ __Vtemp_56;
    VlWide<3>/*95:0*/ __Vtemp_58;
    VlWide<3>/*95:0*/ __Vtemp_59;
    VlWide<3>/*95:0*/ __Vtemp_60;
    VlWide<3>/*95:0*/ __Vtemp_62;
    VlWide<3>/*95:0*/ __Vtemp_63;
    VlWide<3>/*95:0*/ __Vtemp_64;
    VlWide<3>/*95:0*/ __Vtemp_66;
    VlWide<3>/*95:0*/ __Vtemp_67;
    VlWide<3>/*95:0*/ __Vtemp_68;
    VlWide<3>/*95:0*/ __Vtemp_70;
    VlWide<3>/*95:0*/ __Vtemp_71;
    VlWide<3>/*95:0*/ __Vtemp_72;
    VlWide<3>/*95:0*/ __Vtemp_74;
    VlWide<3>/*95:0*/ __Vtemp_75;
    VlWide<3>/*95:0*/ __Vtemp_76;
    VlWide<3>/*95:0*/ __Vtemp_78;
    VlWide<3>/*95:0*/ __Vtemp_79;
    VlWide<3>/*95:0*/ __Vtemp_80;
    VlWide<3>/*95:0*/ __Vtemp_82;
    VlWide<3>/*95:0*/ __Vtemp_83;
    VlWide<3>/*95:0*/ __Vtemp_84;
    VlWide<3>/*95:0*/ __Vtemp_86;
    VlWide<3>/*95:0*/ __Vtemp_87;
    VlWide<3>/*95:0*/ __Vtemp_88;
    VlWide<3>/*95:0*/ __Vtemp_90;
    VlWide<3>/*95:0*/ __Vtemp_91;
    VlWide<3>/*95:0*/ __Vtemp_92;
    VlWide<3>/*95:0*/ __Vtemp_94;
    VlWide<3>/*95:0*/ __Vtemp_95;
    VlWide<3>/*95:0*/ __Vtemp_96;
    VlWide<3>/*95:0*/ __Vtemp_98;
    VlWide<3>/*95:0*/ __Vtemp_99;
    VlWide<3>/*95:0*/ __Vtemp_100;
    VlWide<3>/*95:0*/ __Vtemp_102;
    VlWide<3>/*95:0*/ __Vtemp_103;
    VlWide<3>/*95:0*/ __Vtemp_104;
    VlWide<3>/*95:0*/ __Vtemp_106;
    VlWide<3>/*95:0*/ __Vtemp_107;
    VlWide<3>/*95:0*/ __Vtemp_108;
    VlWide<3>/*95:0*/ __Vtemp_110;
    VlWide<3>/*95:0*/ __Vtemp_111;
    VlWide<3>/*95:0*/ __Vtemp_112;
    VlWide<3>/*95:0*/ __Vtemp_114;
    VlWide<3>/*95:0*/ __Vtemp_115;
    VlWide<3>/*95:0*/ __Vtemp_116;
    // Body
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_8_1);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_8_1 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3840;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_33[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_33[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_33[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_9_1);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_9_1 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_4276;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_37[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_37[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_37[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_10_1);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_10_1 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_4712;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_41[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_41[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_41[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_11_1);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_11_1 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5148;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_45[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_45[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_45[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_12_1);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_12_1 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5584;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_49[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_49[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_49[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_13_1);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_13_1 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6020;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_53[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_53[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_53[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_14_1);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_14_1 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6456;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_57[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_57[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_57[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_15_1);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_15_1 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6892;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_61[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_61[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_61[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_16_1);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_16_1 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_7328;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_65[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_65[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_65[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_17_1);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_17_1 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_7764;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_69[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_69[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_69[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_18_1);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_18_1 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_8200;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_73[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_73[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_73[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_19_1);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_19_1 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_8636;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_77[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_77[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_77[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_20_1);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_20_1 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9072;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_81[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_81[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_81[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_21_1);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_21_1 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9508;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_85[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_85[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_85[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_22_1);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_22_1 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9944;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_89[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_89[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_89[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_23_1);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_23_1 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10380;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_93[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_93[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_93[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_24_1);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_24_1 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10816;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_97[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_97[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_97[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_25_1);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_25_1 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_11252;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_101[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_101[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_101[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_26_1);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_26_1 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_11688;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_105[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_105[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_105[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_27_1);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_27_1 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12124;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_109[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_109[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_109[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_28_1);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_28_1 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12560;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_113[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_113[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_113[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_29_1);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_29_1 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12996;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_117[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_117[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_117[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_30_1);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_30_1 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13432;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_121[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_121[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_121[2U] 
        = (1U & __Vtemp_92[2U]);
    __Vtemp_94[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_31_1);
    __Vtemp_94[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_31_1 
                              >> 0x20U));
    __Vtemp_94[2U] = 0U;
    __Vtemp_95[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13868;
    __Vtemp_95[1U] = 0U;
    __Vtemp_95[2U] = 0U;
    VL_ADD_W(3, __Vtemp_96, __Vtemp_94, __Vtemp_95);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_125[0U] 
        = __Vtemp_96[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_125[1U] 
        = __Vtemp_96[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_125[2U] 
        = (1U & __Vtemp_96[2U]);
    __Vtemp_98[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_0_0);
    __Vtemp_98[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_0_0 
                              >> 0x20U));
    __Vtemp_98[2U] = 0U;
    __Vtemp_99[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_3174;
    __Vtemp_99[1U] = 0U;
    __Vtemp_99[2U] = 0U;
    VL_ADD_W(3, __Vtemp_100, __Vtemp_98, __Vtemp_99);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide[0U] 
        = __Vtemp_100[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide[1U] 
        = __Vtemp_100[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide[2U] 
        = (1U & __Vtemp_100[2U]);
    __Vtemp_102[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_1_0);
    __Vtemp_102[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_1_0 
                               >> 0x20U));
    __Vtemp_102[2U] = 0U;
    __Vtemp_103[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_7638;
    __Vtemp_103[1U] = 0U;
    __Vtemp_103[2U] = 0U;
    VL_ADD_W(3, __Vtemp_104, __Vtemp_102, __Vtemp_103);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_4[0U] 
        = __Vtemp_104[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_4[1U] 
        = __Vtemp_104[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_4[2U] 
        = (1U & __Vtemp_104[2U]);
    __Vtemp_106[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_2_0);
    __Vtemp_106[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_2_0 
                               >> 0x20U));
    __Vtemp_106[2U] = 0U;
    __Vtemp_107[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_12102;
    __Vtemp_107[1U] = 0U;
    __Vtemp_107[2U] = 0U;
    VL_ADD_W(3, __Vtemp_108, __Vtemp_106, __Vtemp_107);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_8[0U] 
        = __Vtemp_108[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_8[1U] 
        = __Vtemp_108[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_8[2U] 
        = (1U & __Vtemp_108[2U]);
    __Vtemp_110[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_3_0);
    __Vtemp_110[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_3_0 
                               >> 0x20U));
    __Vtemp_110[2U] = 0U;
    __Vtemp_111[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_16566;
    __Vtemp_111[1U] = 0U;
    __Vtemp_111[2U] = 0U;
    VL_ADD_W(3, __Vtemp_112, __Vtemp_110, __Vtemp_111);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_12[0U] 
        = __Vtemp_112[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_12[1U] 
        = __Vtemp_112[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_12[2U] 
        = (1U & __Vtemp_112[2U]);
    __Vtemp_114[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_4_0);
    __Vtemp_114[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_4_0 
                               >> 0x20U));
    __Vtemp_114[2U] = 0U;
    __Vtemp_115[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_21030;
    __Vtemp_115[1U] = 0U;
    __Vtemp_115[2U] = 0U;
    VL_ADD_W(3, __Vtemp_116, __Vtemp_114, __Vtemp_115);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_16[0U] 
        = __Vtemp_116[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_16[1U] 
        = __Vtemp_116[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_16[2U] 
        = (1U & __Vtemp_116[2U]);
}
