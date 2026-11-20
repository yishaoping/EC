// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_ReferenceBank.h"

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__320(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__320\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_7_2);
    __Vtemp_2[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_7_2 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3445;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__storeFirstNextWide_30[0U] = __Vtemp_4[0U];
    vlSelfRef.__PVT__storeFirstNextWide_30[1U] = __Vtemp_4[1U];
    vlSelfRef.__PVT__storeFirstNextWide_30[2U] = (1U 
                                                  & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_8_2);
    __Vtemp_6[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_8_2 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3881;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__storeFirstNextWide_34[0U] = __Vtemp_8[0U];
    vlSelfRef.__PVT__storeFirstNextWide_34[1U] = __Vtemp_8[1U];
    vlSelfRef.__PVT__storeFirstNextWide_34[2U] = (1U 
                                                  & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_9_2);
    __Vtemp_10[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_9_2 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_4317;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__storeFirstNextWide_38[0U] = __Vtemp_12[0U];
    vlSelfRef.__PVT__storeFirstNextWide_38[1U] = __Vtemp_12[1U];
    vlSelfRef.__PVT__storeFirstNextWide_38[2U] = (1U 
                                                  & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_10_2);
    __Vtemp_14[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_10_2 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_4753;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__storeFirstNextWide_42[0U] = __Vtemp_16[0U];
    vlSelfRef.__PVT__storeFirstNextWide_42[1U] = __Vtemp_16[1U];
    vlSelfRef.__PVT__storeFirstNextWide_42[2U] = (1U 
                                                  & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_11_2);
    __Vtemp_18[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_11_2 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_5189;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__storeFirstNextWide_46[0U] = __Vtemp_20[0U];
    vlSelfRef.__PVT__storeFirstNextWide_46[1U] = __Vtemp_20[1U];
    vlSelfRef.__PVT__storeFirstNextWide_46[2U] = (1U 
                                                  & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_12_2);
    __Vtemp_22[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_12_2 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_5625;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__storeFirstNextWide_50[0U] = __Vtemp_24[0U];
    vlSelfRef.__PVT__storeFirstNextWide_50[1U] = __Vtemp_24[1U];
    vlSelfRef.__PVT__storeFirstNextWide_50[2U] = (1U 
                                                  & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_13_2);
    __Vtemp_26[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_13_2 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_6061;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__storeFirstNextWide_54[0U] = __Vtemp_28[0U];
    vlSelfRef.__PVT__storeFirstNextWide_54[1U] = __Vtemp_28[1U];
    vlSelfRef.__PVT__storeFirstNextWide_54[2U] = (1U 
                                                  & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_14_2);
    __Vtemp_30[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_14_2 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_6497;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__storeFirstNextWide_58[0U] = __Vtemp_32[0U];
    vlSelfRef.__PVT__storeFirstNextWide_58[1U] = __Vtemp_32[1U];
    vlSelfRef.__PVT__storeFirstNextWide_58[2U] = (1U 
                                                  & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.bucketStoreFirst_15_2);
    __Vtemp_34[1U] = (IData)((vlSelfRef.bucketStoreFirst_15_2 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_6933;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__storeFirstNextWide_62[0U] = __Vtemp_36[0U];
    vlSelfRef.__PVT__storeFirstNextWide_62[1U] = __Vtemp_36[1U];
    vlSelfRef.__PVT__storeFirstNextWide_62[2U] = (1U 
                                                  & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.bucketStoreFirst_0_3);
    __Vtemp_38[1U] = (IData)((vlSelfRef.bucketStoreFirst_0_3 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_434;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__storeFirstNextWide_3[0U] = __Vtemp_40[0U];
    vlSelfRef.__PVT__storeFirstNextWide_3[1U] = __Vtemp_40[1U];
    vlSelfRef.__PVT__storeFirstNextWide_3[2U] = (1U 
                                                 & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_1_3);
    __Vtemp_42[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_1_3 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_870;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__storeFirstNextWide_7[0U] = __Vtemp_44[0U];
    vlSelfRef.__PVT__storeFirstNextWide_7[1U] = __Vtemp_44[1U];
    vlSelfRef.__PVT__storeFirstNextWide_7[2U] = (1U 
                                                 & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_2_3);
    __Vtemp_46[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_2_3 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1306;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__storeFirstNextWide_11[0U] = __Vtemp_48[0U];
    vlSelfRef.__PVT__storeFirstNextWide_11[1U] = __Vtemp_48[1U];
    vlSelfRef.__PVT__storeFirstNextWide_11[2U] = (1U 
                                                  & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_3_3);
    __Vtemp_50[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_3_3 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1742;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__storeFirstNextWide_15[0U] = __Vtemp_52[0U];
    vlSelfRef.__PVT__storeFirstNextWide_15[1U] = __Vtemp_52[1U];
    vlSelfRef.__PVT__storeFirstNextWide_15[2U] = (1U 
                                                  & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_4_3);
    __Vtemp_54[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_4_3 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2178;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__storeFirstNextWide_19[0U] = __Vtemp_56[0U];
    vlSelfRef.__PVT__storeFirstNextWide_19[1U] = __Vtemp_56[1U];
    vlSelfRef.__PVT__storeFirstNextWide_19[2U] = (1U 
                                                  & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_5_3);
    __Vtemp_58[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_5_3 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2614;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__storeFirstNextWide_23[0U] = __Vtemp_60[0U];
    vlSelfRef.__PVT__storeFirstNextWide_23[1U] = __Vtemp_60[1U];
    vlSelfRef.__PVT__storeFirstNextWide_23[2U] = (1U 
                                                  & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_6_3);
    __Vtemp_62[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_6_3 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3050;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__storeFirstNextWide_27[0U] = __Vtemp_64[0U];
    vlSelfRef.__PVT__storeFirstNextWide_27[1U] = __Vtemp_64[1U];
    vlSelfRef.__PVT__storeFirstNextWide_27[2U] = (1U 
                                                  & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_7_3);
    __Vtemp_66[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_7_3 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3486;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__storeFirstNextWide_31[0U] = __Vtemp_68[0U];
    vlSelfRef.__PVT__storeFirstNextWide_31[1U] = __Vtemp_68[1U];
    vlSelfRef.__PVT__storeFirstNextWide_31[2U] = (1U 
                                                  & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_8_3);
    __Vtemp_70[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_8_3 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3922;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__storeFirstNextWide_35[0U] = __Vtemp_72[0U];
    vlSelfRef.__PVT__storeFirstNextWide_35[1U] = __Vtemp_72[1U];
    vlSelfRef.__PVT__storeFirstNextWide_35[2U] = (1U 
                                                  & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_9_3);
    __Vtemp_74[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_9_3 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_4358;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__storeFirstNextWide_39[0U] = __Vtemp_76[0U];
    vlSelfRef.__PVT__storeFirstNextWide_39[1U] = __Vtemp_76[1U];
    vlSelfRef.__PVT__storeFirstNextWide_39[2U] = (1U 
                                                  & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_10_3);
    __Vtemp_78[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_10_3 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_4794;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__storeFirstNextWide_43[0U] = __Vtemp_80[0U];
    vlSelfRef.__PVT__storeFirstNextWide_43[1U] = __Vtemp_80[1U];
    vlSelfRef.__PVT__storeFirstNextWide_43[2U] = (1U 
                                                  & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_11_3);
    __Vtemp_82[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_11_3 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_5230;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.__PVT__storeFirstNextWide_47[0U] = __Vtemp_84[0U];
    vlSelfRef.__PVT__storeFirstNextWide_47[1U] = __Vtemp_84[1U];
    vlSelfRef.__PVT__storeFirstNextWide_47[2U] = (1U 
                                                  & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_12_3);
    __Vtemp_86[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_12_3 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_5666;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.__PVT__storeFirstNextWide_51[0U] = __Vtemp_88[0U];
    vlSelfRef.__PVT__storeFirstNextWide_51[1U] = __Vtemp_88[1U];
    vlSelfRef.__PVT__storeFirstNextWide_51[2U] = (1U 
                                                  & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_13_3);
    __Vtemp_90[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_13_3 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_6102;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.__PVT__storeFirstNextWide_55[0U] = __Vtemp_92[0U];
    vlSelfRef.__PVT__storeFirstNextWide_55[1U] = __Vtemp_92[1U];
    vlSelfRef.__PVT__storeFirstNextWide_55[2U] = (1U 
                                                  & __Vtemp_92[2U]);
    __Vtemp_94[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_14_3);
    __Vtemp_94[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_14_3 
                              >> 0x20U));
    __Vtemp_94[2U] = 0U;
    __Vtemp_95[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_6538;
    __Vtemp_95[1U] = 0U;
    __Vtemp_95[2U] = 0U;
    VL_ADD_W(3, __Vtemp_96, __Vtemp_94, __Vtemp_95);
    vlSelfRef.__PVT__storeFirstNextWide_59[0U] = __Vtemp_96[0U];
    vlSelfRef.__PVT__storeFirstNextWide_59[1U] = __Vtemp_96[1U];
    vlSelfRef.__PVT__storeFirstNextWide_59[2U] = (1U 
                                                  & __Vtemp_96[2U]);
    __Vtemp_98[0U] = (IData)(vlSelfRef.bucketStoreFirst_15_3);
    __Vtemp_98[1U] = (IData)((vlSelfRef.bucketStoreFirst_15_3 
                              >> 0x20U));
    __Vtemp_98[2U] = 0U;
    __Vtemp_99[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_6974;
    __Vtemp_99[1U] = 0U;
    __Vtemp_99[2U] = 0U;
    VL_ADD_W(3, __Vtemp_100, __Vtemp_98, __Vtemp_99);
    vlSelfRef.__PVT__storeFirstNextWide_63[0U] = __Vtemp_100[0U];
    vlSelfRef.__PVT__storeFirstNextWide_63[1U] = __Vtemp_100[1U];
    vlSelfRef.__PVT__storeFirstNextWide_63[2U] = (1U 
                                                  & __Vtemp_100[2U]);
    __Vtemp_102[0U] = (IData)(vlSelfRef.bucketStoreFirst_0_1);
    __Vtemp_102[1U] = (IData)((vlSelfRef.bucketStoreFirst_0_1 
                               >> 0x20U));
    __Vtemp_102[2U] = 0U;
    __Vtemp_103[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_352;
    __Vtemp_103[1U] = 0U;
    __Vtemp_103[2U] = 0U;
    VL_ADD_W(3, __Vtemp_104, __Vtemp_102, __Vtemp_103);
    vlSelfRef.__PVT__storeFirstNextWide_1[0U] = __Vtemp_104[0U];
    vlSelfRef.__PVT__storeFirstNextWide_1[1U] = __Vtemp_104[1U];
    vlSelfRef.__PVT__storeFirstNextWide_1[2U] = (1U 
                                                 & __Vtemp_104[2U]);
    __Vtemp_106[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_1_1);
    __Vtemp_106[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_1_1 
                               >> 0x20U));
    __Vtemp_106[2U] = 0U;
    __Vtemp_107[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_788;
    __Vtemp_107[1U] = 0U;
    __Vtemp_107[2U] = 0U;
    VL_ADD_W(3, __Vtemp_108, __Vtemp_106, __Vtemp_107);
    vlSelfRef.__PVT__storeFirstNextWide_5[0U] = __Vtemp_108[0U];
    vlSelfRef.__PVT__storeFirstNextWide_5[1U] = __Vtemp_108[1U];
    vlSelfRef.__PVT__storeFirstNextWide_5[2U] = (1U 
                                                 & __Vtemp_108[2U]);
    __Vtemp_110[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_2_1);
    __Vtemp_110[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_2_1 
                               >> 0x20U));
    __Vtemp_110[2U] = 0U;
    __Vtemp_111[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1224;
    __Vtemp_111[1U] = 0U;
    __Vtemp_111[2U] = 0U;
    VL_ADD_W(3, __Vtemp_112, __Vtemp_110, __Vtemp_111);
    vlSelfRef.__PVT__storeFirstNextWide_9[0U] = __Vtemp_112[0U];
    vlSelfRef.__PVT__storeFirstNextWide_9[1U] = __Vtemp_112[1U];
    vlSelfRef.__PVT__storeFirstNextWide_9[2U] = (1U 
                                                 & __Vtemp_112[2U]);
    __Vtemp_114[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_3_1);
    __Vtemp_114[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_3_1 
                               >> 0x20U));
    __Vtemp_114[2U] = 0U;
    __Vtemp_115[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1660;
    __Vtemp_115[1U] = 0U;
    __Vtemp_115[2U] = 0U;
    VL_ADD_W(3, __Vtemp_116, __Vtemp_114, __Vtemp_115);
    vlSelfRef.__PVT__storeFirstNextWide_13[0U] = __Vtemp_116[0U];
    vlSelfRef.__PVT__storeFirstNextWide_13[1U] = __Vtemp_116[1U];
    vlSelfRef.__PVT__storeFirstNextWide_13[2U] = (1U 
                                                  & __Vtemp_116[2U]);
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__321(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__321\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_4_1);
    __Vtemp_2[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_4_1 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2096;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__storeFirstNextWide_17[0U] = __Vtemp_4[0U];
    vlSelfRef.__PVT__storeFirstNextWide_17[1U] = __Vtemp_4[1U];
    vlSelfRef.__PVT__storeFirstNextWide_17[2U] = (1U 
                                                  & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_5_1);
    __Vtemp_6[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_5_1 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2532;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__storeFirstNextWide_21[0U] = __Vtemp_8[0U];
    vlSelfRef.__PVT__storeFirstNextWide_21[1U] = __Vtemp_8[1U];
    vlSelfRef.__PVT__storeFirstNextWide_21[2U] = (1U 
                                                  & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_6_1);
    __Vtemp_10[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_6_1 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2968;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__storeFirstNextWide_25[0U] = __Vtemp_12[0U];
    vlSelfRef.__PVT__storeFirstNextWide_25[1U] = __Vtemp_12[1U];
    vlSelfRef.__PVT__storeFirstNextWide_25[2U] = (1U 
                                                  & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_7_1);
    __Vtemp_14[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_7_1 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3404;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__storeFirstNextWide_29[0U] = __Vtemp_16[0U];
    vlSelfRef.__PVT__storeFirstNextWide_29[1U] = __Vtemp_16[1U];
    vlSelfRef.__PVT__storeFirstNextWide_29[2U] = (1U 
                                                  & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_8_1);
    __Vtemp_18[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_8_1 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3840;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__storeFirstNextWide_33[0U] = __Vtemp_20[0U];
    vlSelfRef.__PVT__storeFirstNextWide_33[1U] = __Vtemp_20[1U];
    vlSelfRef.__PVT__storeFirstNextWide_33[2U] = (1U 
                                                  & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_9_1);
    __Vtemp_22[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_9_1 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_4276;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__storeFirstNextWide_37[0U] = __Vtemp_24[0U];
    vlSelfRef.__PVT__storeFirstNextWide_37[1U] = __Vtemp_24[1U];
    vlSelfRef.__PVT__storeFirstNextWide_37[2U] = (1U 
                                                  & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_10_1);
    __Vtemp_26[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_10_1 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_4712;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__storeFirstNextWide_41[0U] = __Vtemp_28[0U];
    vlSelfRef.__PVT__storeFirstNextWide_41[1U] = __Vtemp_28[1U];
    vlSelfRef.__PVT__storeFirstNextWide_41[2U] = (1U 
                                                  & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_11_1);
    __Vtemp_30[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_11_1 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_5148;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__storeFirstNextWide_45[0U] = __Vtemp_32[0U];
    vlSelfRef.__PVT__storeFirstNextWide_45[1U] = __Vtemp_32[1U];
    vlSelfRef.__PVT__storeFirstNextWide_45[2U] = (1U 
                                                  & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_12_1);
    __Vtemp_34[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_12_1 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_5584;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__storeFirstNextWide_49[0U] = __Vtemp_36[0U];
    vlSelfRef.__PVT__storeFirstNextWide_49[1U] = __Vtemp_36[1U];
    vlSelfRef.__PVT__storeFirstNextWide_49[2U] = (1U 
                                                  & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_13_1);
    __Vtemp_38[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_13_1 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_6020;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__storeFirstNextWide_53[0U] = __Vtemp_40[0U];
    vlSelfRef.__PVT__storeFirstNextWide_53[1U] = __Vtemp_40[1U];
    vlSelfRef.__PVT__storeFirstNextWide_53[2U] = (1U 
                                                  & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_14_1);
    __Vtemp_42[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_14_1 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_6456;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__storeFirstNextWide_57[0U] = __Vtemp_44[0U];
    vlSelfRef.__PVT__storeFirstNextWide_57[1U] = __Vtemp_44[1U];
    vlSelfRef.__PVT__storeFirstNextWide_57[2U] = (1U 
                                                  & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.bucketStoreFirst_15_1);
    __Vtemp_46[1U] = (IData)((vlSelfRef.bucketStoreFirst_15_1 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_6892;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__storeFirstNextWide_61[0U] = __Vtemp_48[0U];
    vlSelfRef.__PVT__storeFirstNextWide_61[1U] = __Vtemp_48[1U];
    vlSelfRef.__PVT__storeFirstNextWide_61[2U] = (1U 
                                                  & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_0_0);
    __Vtemp_50[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_0_0 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3174;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__strictWriteReadNextWide[0U] = 
        __Vtemp_52[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide[1U] = 
        __Vtemp_52[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide[2U] = 
        (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_1_0);
    __Vtemp_54[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_1_0 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7638;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__strictWriteReadNextWide_4[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_4[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_4[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_2_0);
    __Vtemp_58[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_2_0 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12102;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__strictWriteReadNextWide_8[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_8[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_8[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_3_0);
    __Vtemp_62[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_3_0 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16566;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__strictWriteReadNextWide_12[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_12[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_12[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_4_0);
    __Vtemp_66[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_4_0 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21030;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__strictWriteReadNextWide_16[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_16[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_16[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_5_0);
    __Vtemp_70[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_5_0 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25494;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__strictWriteReadNextWide_20[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_20[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_20[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_6_0);
    __Vtemp_74[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_6_0 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29958;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__strictWriteReadNextWide_24[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_24[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_24[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_7_0);
    __Vtemp_78[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_7_0 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34422;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__strictWriteReadNextWide_28[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_28[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_28[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_8_0);
    __Vtemp_82[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_8_0 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38886;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.__PVT__strictWriteReadNextWide_32[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_32[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_32[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_9_0);
    __Vtemp_86[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_9_0 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43350;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.__PVT__strictWriteReadNextWide_36[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_36[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_36[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_10_0);
    __Vtemp_90[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_10_0 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47814;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.__PVT__strictWriteReadNextWide_40[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_40[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_40[2U] 
        = (1U & __Vtemp_92[2U]);
    __Vtemp_94[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_11_0);
    __Vtemp_94[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_11_0 
                              >> 0x20U));
    __Vtemp_94[2U] = 0U;
    __Vtemp_95[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52278;
    __Vtemp_95[1U] = 0U;
    __Vtemp_95[2U] = 0U;
    VL_ADD_W(3, __Vtemp_96, __Vtemp_94, __Vtemp_95);
    vlSelfRef.__PVT__strictWriteReadNextWide_44[0U] 
        = __Vtemp_96[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_44[1U] 
        = __Vtemp_96[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_44[2U] 
        = (1U & __Vtemp_96[2U]);
    __Vtemp_98[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_12_0);
    __Vtemp_98[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_12_0 
                              >> 0x20U));
    __Vtemp_98[2U] = 0U;
    __Vtemp_99[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56742;
    __Vtemp_99[1U] = 0U;
    __Vtemp_99[2U] = 0U;
    VL_ADD_W(3, __Vtemp_100, __Vtemp_98, __Vtemp_99);
    vlSelfRef.__PVT__strictWriteReadNextWide_48[0U] 
        = __Vtemp_100[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_48[1U] 
        = __Vtemp_100[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_48[2U] 
        = (1U & __Vtemp_100[2U]);
    __Vtemp_102[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_13_0);
    __Vtemp_102[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_13_0 
                               >> 0x20U));
    __Vtemp_102[2U] = 0U;
    __Vtemp_103[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61206;
    __Vtemp_103[1U] = 0U;
    __Vtemp_103[2U] = 0U;
    VL_ADD_W(3, __Vtemp_104, __Vtemp_102, __Vtemp_103);
    vlSelfRef.__PVT__strictWriteReadNextWide_52[0U] 
        = __Vtemp_104[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_52[1U] 
        = __Vtemp_104[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_52[2U] 
        = (1U & __Vtemp_104[2U]);
    __Vtemp_106[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_14_0);
    __Vtemp_106[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_14_0 
                               >> 0x20U));
    __Vtemp_106[2U] = 0U;
    __Vtemp_107[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65670;
    __Vtemp_107[1U] = 0U;
    __Vtemp_107[2U] = 0U;
    VL_ADD_W(3, __Vtemp_108, __Vtemp_106, __Vtemp_107);
    vlSelfRef.__PVT__strictWriteReadNextWide_56[0U] 
        = __Vtemp_108[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_56[1U] 
        = __Vtemp_108[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_56[2U] 
        = (1U & __Vtemp_108[2U]);
    __Vtemp_110[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_15_0);
    __Vtemp_110[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_15_0 
                               >> 0x20U));
    __Vtemp_110[2U] = 0U;
    __Vtemp_111[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_70134;
    __Vtemp_111[1U] = 0U;
    __Vtemp_111[2U] = 0U;
    VL_ADD_W(3, __Vtemp_112, __Vtemp_110, __Vtemp_111);
    vlSelfRef.__PVT__strictWriteReadNextWide_60[0U] 
        = __Vtemp_112[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_60[1U] 
        = __Vtemp_112[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_60[2U] 
        = (1U & __Vtemp_112[2U]);
    __Vtemp_114[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_0_2);
    __Vtemp_114[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_0_2 
                               >> 0x20U));
    __Vtemp_114[2U] = 0U;
    __Vtemp_115[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_4026;
    __Vtemp_115[1U] = 0U;
    __Vtemp_115[2U] = 0U;
    VL_ADD_W(3, __Vtemp_116, __Vtemp_114, __Vtemp_115);
    vlSelfRef.__PVT__strictWriteReadNextWide_2[0U] 
        = __Vtemp_116[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_2[1U] 
        = __Vtemp_116[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_2[2U] 
        = (1U & __Vtemp_116[2U]);
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__322(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__322\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_1_2);
    __Vtemp_2[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_1_2 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8490;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__strictWriteReadNextWide_6[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_6[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_6[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_2_2);
    __Vtemp_6[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_2_2 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12954;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__strictWriteReadNextWide_10[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_10[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_10[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_3_2);
    __Vtemp_10[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_3_2 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_17418;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__strictWriteReadNextWide_14[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_14[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_14[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_4_2);
    __Vtemp_14[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_4_2 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21882;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__strictWriteReadNextWide_18[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_18[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_18[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_5_2);
    __Vtemp_18[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_5_2 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_26346;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__strictWriteReadNextWide_22[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_22[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_22[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_6_2);
    __Vtemp_22[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_6_2 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_30810;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__strictWriteReadNextWide_26[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_26[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_26[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_7_2);
    __Vtemp_26[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_7_2 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_35274;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__strictWriteReadNextWide_30[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_30[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_30[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_8_2);
    __Vtemp_30[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_8_2 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_39738;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__strictWriteReadNextWide_34[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_34[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_34[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_9_2);
    __Vtemp_34[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_9_2 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_44202;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__strictWriteReadNextWide_38[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_38[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_38[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_10_2);
    __Vtemp_38[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_10_2 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_48666;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__strictWriteReadNextWide_42[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_42[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_42[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_11_2);
    __Vtemp_42[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_11_2 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_53130;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__strictWriteReadNextWide_46[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_46[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_46[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_12_2);
    __Vtemp_46[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_12_2 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_57594;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__strictWriteReadNextWide_50[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_50[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_50[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_13_2);
    __Vtemp_50[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_13_2 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_62058;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__strictWriteReadNextWide_54[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_54[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_54[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_14_2);
    __Vtemp_54[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_14_2 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66522;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__strictWriteReadNextWide_58[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_58[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_58[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_15_2);
    __Vtemp_58[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_15_2 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_70986;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__strictWriteReadNextWide_62[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_62[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_62[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_0_3);
    __Vtemp_62[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_0_3 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_4462;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__strictWriteReadNextWide_3[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_3[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_3[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_1_3);
    __Vtemp_66[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_1_3 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8926;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__strictWriteReadNextWide_7[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_7[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_7[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_2_3);
    __Vtemp_70[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_2_3 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_13390;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__strictWriteReadNextWide_11[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_11[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_11[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_3_3);
    __Vtemp_74[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_3_3 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_17854;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__strictWriteReadNextWide_15[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_15[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_15[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_4_3);
    __Vtemp_78[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_4_3 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_22318;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__strictWriteReadNextWide_19[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_19[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_19[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_5_3);
    __Vtemp_82[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_5_3 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_26782;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.__PVT__strictWriteReadNextWide_23[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_23[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_23[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_6_3);
    __Vtemp_86[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_6_3 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_31246;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.__PVT__strictWriteReadNextWide_27[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_27[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_27[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_7_3);
    __Vtemp_90[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_7_3 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_35710;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.__PVT__strictWriteReadNextWide_31[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_31[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_31[2U] 
        = (1U & __Vtemp_92[2U]);
    __Vtemp_94[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_8_3);
    __Vtemp_94[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_8_3 
                              >> 0x20U));
    __Vtemp_94[2U] = 0U;
    __Vtemp_95[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_40174;
    __Vtemp_95[1U] = 0U;
    __Vtemp_95[2U] = 0U;
    VL_ADD_W(3, __Vtemp_96, __Vtemp_94, __Vtemp_95);
    vlSelfRef.__PVT__strictWriteReadNextWide_35[0U] 
        = __Vtemp_96[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_35[1U] 
        = __Vtemp_96[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_35[2U] 
        = (1U & __Vtemp_96[2U]);
    __Vtemp_98[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_9_3);
    __Vtemp_98[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_9_3 
                              >> 0x20U));
    __Vtemp_98[2U] = 0U;
    __Vtemp_99[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_44638;
    __Vtemp_99[1U] = 0U;
    __Vtemp_99[2U] = 0U;
    VL_ADD_W(3, __Vtemp_100, __Vtemp_98, __Vtemp_99);
    vlSelfRef.__PVT__strictWriteReadNextWide_39[0U] 
        = __Vtemp_100[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_39[1U] 
        = __Vtemp_100[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_39[2U] 
        = (1U & __Vtemp_100[2U]);
    __Vtemp_102[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_10_3);
    __Vtemp_102[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_10_3 
                               >> 0x20U));
    __Vtemp_102[2U] = 0U;
    __Vtemp_103[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_49102;
    __Vtemp_103[1U] = 0U;
    __Vtemp_103[2U] = 0U;
    VL_ADD_W(3, __Vtemp_104, __Vtemp_102, __Vtemp_103);
    vlSelfRef.__PVT__strictWriteReadNextWide_43[0U] 
        = __Vtemp_104[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_43[1U] 
        = __Vtemp_104[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_43[2U] 
        = (1U & __Vtemp_104[2U]);
    __Vtemp_106[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_11_3);
    __Vtemp_106[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_11_3 
                               >> 0x20U));
    __Vtemp_106[2U] = 0U;
    __Vtemp_107[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_53566;
    __Vtemp_107[1U] = 0U;
    __Vtemp_107[2U] = 0U;
    VL_ADD_W(3, __Vtemp_108, __Vtemp_106, __Vtemp_107);
    vlSelfRef.__PVT__strictWriteReadNextWide_47[0U] 
        = __Vtemp_108[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_47[1U] 
        = __Vtemp_108[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_47[2U] 
        = (1U & __Vtemp_108[2U]);
    __Vtemp_110[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_12_3);
    __Vtemp_110[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_12_3 
                               >> 0x20U));
    __Vtemp_110[2U] = 0U;
    __Vtemp_111[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_58030;
    __Vtemp_111[1U] = 0U;
    __Vtemp_111[2U] = 0U;
    VL_ADD_W(3, __Vtemp_112, __Vtemp_110, __Vtemp_111);
    vlSelfRef.__PVT__strictWriteReadNextWide_51[0U] 
        = __Vtemp_112[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_51[1U] 
        = __Vtemp_112[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_51[2U] 
        = (1U & __Vtemp_112[2U]);
    __Vtemp_114[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_13_3);
    __Vtemp_114[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_13_3 
                               >> 0x20U));
    __Vtemp_114[2U] = 0U;
    __Vtemp_115[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_62494;
    __Vtemp_115[1U] = 0U;
    __Vtemp_115[2U] = 0U;
    VL_ADD_W(3, __Vtemp_116, __Vtemp_114, __Vtemp_115);
    vlSelfRef.__PVT__strictWriteReadNextWide_55[0U] 
        = __Vtemp_116[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_55[1U] 
        = __Vtemp_116[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_55[2U] 
        = (1U & __Vtemp_116[2U]);
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__323(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_0__323\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_14_3);
    __Vtemp_2[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_14_3 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66958;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__strictWriteReadNextWide_59[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_59[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_59[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_15_3);
    __Vtemp_6[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_15_3 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_71422;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__strictWriteReadNextWide_63[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_63[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_63[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_0_1);
    __Vtemp_10[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_0_1 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3590;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__strictWriteReadNextWide_1[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_1[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_1[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_1_1);
    __Vtemp_14[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_1_1 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8054;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__strictWriteReadNextWide_5[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_5[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_5[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_2_1);
    __Vtemp_18[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_2_1 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12518;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__strictWriteReadNextWide_9[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_9[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_9[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_3_1);
    __Vtemp_22[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_3_1 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16982;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__strictWriteReadNextWide_13[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_13[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_13[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_4_1);
    __Vtemp_26[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_4_1 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21446;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__strictWriteReadNextWide_17[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_17[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_17[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_5_1);
    __Vtemp_30[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_5_1 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25910;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__strictWriteReadNextWide_21[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_21[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_21[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_6_1);
    __Vtemp_34[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_6_1 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_30374;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__strictWriteReadNextWide_25[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_25[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_25[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_7_1);
    __Vtemp_38[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_7_1 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34838;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__strictWriteReadNextWide_29[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_29[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_29[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_8_1);
    __Vtemp_42[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_8_1 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_39302;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__strictWriteReadNextWide_33[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_33[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_33[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_9_1);
    __Vtemp_46[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_9_1 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43766;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__strictWriteReadNextWide_37[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_37[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_37[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_10_1);
    __Vtemp_50[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_10_1 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_48230;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__strictWriteReadNextWide_41[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_41[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_41[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_11_1);
    __Vtemp_54[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_11_1 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52694;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__strictWriteReadNextWide_45[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_45[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_45[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_12_1);
    __Vtemp_58[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_12_1 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_57158;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__strictWriteReadNextWide_49[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_49[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_49[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_13_1);
    __Vtemp_62[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_13_1 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61622;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__strictWriteReadNextWide_53[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_53[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_53[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_14_1);
    __Vtemp_66[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_14_1 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66086;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__strictWriteReadNextWide_57[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_57[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_57[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_15_1);
    __Vtemp_70[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_15_1 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_70550;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__strictWriteReadNextWide_61[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_61[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_61[2U] 
        = (1U & __Vtemp_72[2U]);
    vlSelfRef.io_overflow = (1U & ((vlSelfRef.__PVT__loadFirstNextWide_60[2U] 
                                    | (vlSelfRef.__PVT__storeFirstNextWide_60[2U] 
                                       | (vlSelfRef.__PVT__strictWriteReadNextWide_60[2U] 
                                          | (((IData)(vlSelfRef.__PVT__isCurrent_15) 
                                              & vlSelfRef.__PVT__currentStoreNextWide_60[2U]) 
                                             | (((IData)(vlSelfRef.__PVT__isCurrent_15) 
                                                 & vlSelfRef.__PVT__currentFirstStoreNextWide_60[2U]) 
                                                | (vlSelfRef.__PVT__loadFirstNextWide_61[2U] 
                                                   | (vlSelfRef.__PVT__storeFirstNextWide_61[2U] 
                                                      | (vlSelfRef.__PVT__strictWriteReadNextWide_61[2U] 
                                                         | (((IData)(vlSelfRef.__PVT__isCurrent_15) 
                                                             & vlSelfRef.__PVT__currentStoreNextWide_61[2U]) 
                                                            | (((IData)(vlSelfRef.__PVT__isCurrent_15) 
                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_61[2U]) 
                                                               | (vlSelfRef.__PVT__loadFirstNextWide_62[2U] 
                                                                  | (vlSelfRef.__PVT__storeFirstNextWide_62[2U] 
                                                                     | (vlSelfRef.__PVT__strictWriteReadNextWide_62[2U] 
                                                                        | (((IData)(vlSelfRef.__PVT__isCurrent_15) 
                                                                            & vlSelfRef.__PVT__currentStoreNextWide_62[2U]) 
                                                                           | (((IData)(vlSelfRef.__PVT__isCurrent_15) 
                                                                               & vlSelfRef.__PVT__currentFirstStoreNextWide_62[2U]) 
                                                                              | (vlSelfRef.__PVT__loadFirstNextWide_63[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_63[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_63[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_15) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_63[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_63[2U])))))))))))))))))))) 
                                   | ((vlSelfRef.__PVT__loadFirstNextWide_56[2U] 
                                       | (vlSelfRef.__PVT__storeFirstNextWide_56[2U] 
                                          | (vlSelfRef.__PVT__strictWriteReadNextWide_56[2U] 
                                             | (((IData)(vlSelfRef.__PVT__isCurrent_14) 
                                                 & vlSelfRef.__PVT__currentStoreNextWide_56[2U]) 
                                                | (((IData)(vlSelfRef.__PVT__isCurrent_14) 
                                                    & vlSelfRef.__PVT__currentFirstStoreNextWide_56[2U]) 
                                                   | (vlSelfRef.__PVT__loadFirstNextWide_57[2U] 
                                                      | (vlSelfRef.__PVT__storeFirstNextWide_57[2U] 
                                                         | (vlSelfRef.__PVT__strictWriteReadNextWide_57[2U] 
                                                            | (((IData)(vlSelfRef.__PVT__isCurrent_14) 
                                                                & vlSelfRef.__PVT__currentStoreNextWide_57[2U]) 
                                                               | (((IData)(vlSelfRef.__PVT__isCurrent_14) 
                                                                   & vlSelfRef.__PVT__currentFirstStoreNextWide_57[2U]) 
                                                                  | (vlSelfRef.__PVT__loadFirstNextWide_58[2U] 
                                                                     | (vlSelfRef.__PVT__storeFirstNextWide_58[2U] 
                                                                        | (vlSelfRef.__PVT__strictWriteReadNextWide_58[2U] 
                                                                           | (((IData)(vlSelfRef.__PVT__isCurrent_14) 
                                                                               & vlSelfRef.__PVT__currentStoreNextWide_58[2U]) 
                                                                              | (((IData)(vlSelfRef.__PVT__isCurrent_14) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_58[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_59[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_59[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_59[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_14) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_59[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_59[2U])))))))))))))))))))) 
                                      | ((vlSelfRef.__PVT__loadFirstNextWide_52[2U] 
                                          | (vlSelfRef.__PVT__storeFirstNextWide_52[2U] 
                                             | (vlSelfRef.__PVT__strictWriteReadNextWide_52[2U] 
                                                | (((IData)(vlSelfRef.__PVT__isCurrent_13) 
                                                    & vlSelfRef.__PVT__currentStoreNextWide_52[2U]) 
                                                   | (((IData)(vlSelfRef.__PVT__isCurrent_13) 
                                                       & vlSelfRef.__PVT__currentFirstStoreNextWide_52[2U]) 
                                                      | (vlSelfRef.__PVT__loadFirstNextWide_53[2U] 
                                                         | (vlSelfRef.__PVT__storeFirstNextWide_53[2U] 
                                                            | (vlSelfRef.__PVT__strictWriteReadNextWide_53[2U] 
                                                               | (((IData)(vlSelfRef.__PVT__isCurrent_13) 
                                                                   & vlSelfRef.__PVT__currentStoreNextWide_53[2U]) 
                                                                  | (((IData)(vlSelfRef.__PVT__isCurrent_13) 
                                                                      & vlSelfRef.__PVT__currentFirstStoreNextWide_53[2U]) 
                                                                     | (vlSelfRef.__PVT__loadFirstNextWide_54[2U] 
                                                                        | (vlSelfRef.__PVT__storeFirstNextWide_54[2U] 
                                                                           | (vlSelfRef.__PVT__strictWriteReadNextWide_54[2U] 
                                                                              | (((IData)(vlSelfRef.__PVT__isCurrent_13) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_54[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_13) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_54[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_55[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_55[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_55[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_13) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_55[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_55[2U])))))))))))))))))))) 
                                         | ((vlSelfRef.__PVT__loadFirstNextWide_48[2U] 
                                             | (vlSelfRef.__PVT__storeFirstNextWide_48[2U] 
                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_48[2U] 
                                                   | (((IData)(vlSelfRef.__PVT__isCurrent_12) 
                                                       & vlSelfRef.__PVT__currentStoreNextWide_48[2U]) 
                                                      | (((IData)(vlSelfRef.__PVT__isCurrent_12) 
                                                          & vlSelfRef.__PVT__currentFirstStoreNextWide_48[2U]) 
                                                         | (vlSelfRef.__PVT__loadFirstNextWide_49[2U] 
                                                            | (vlSelfRef.__PVT__storeFirstNextWide_49[2U] 
                                                               | (vlSelfRef.__PVT__strictWriteReadNextWide_49[2U] 
                                                                  | (((IData)(vlSelfRef.__PVT__isCurrent_12) 
                                                                      & vlSelfRef.__PVT__currentStoreNextWide_49[2U]) 
                                                                     | (((IData)(vlSelfRef.__PVT__isCurrent_12) 
                                                                         & vlSelfRef.__PVT__currentFirstStoreNextWide_49[2U]) 
                                                                        | (vlSelfRef.__PVT__loadFirstNextWide_50[2U] 
                                                                           | (vlSelfRef.__PVT__storeFirstNextWide_50[2U] 
                                                                              | (vlSelfRef.__PVT__strictWriteReadNextWide_50[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_12) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_50[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_12) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_50[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_51[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_51[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_51[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_12) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_51[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_51[2U])))))))))))))))))))) 
                                            | ((vlSelfRef.__PVT__loadFirstNextWide_44[2U] 
                                                | (vlSelfRef.__PVT__storeFirstNextWide_44[2U] 
                                                   | (vlSelfRef.__PVT__strictWriteReadNextWide_44[2U] 
                                                      | (((IData)(vlSelfRef.__PVT__isCurrent_11) 
                                                          & vlSelfRef.__PVT__currentStoreNextWide_44[2U]) 
                                                         | (((IData)(vlSelfRef.__PVT__isCurrent_11) 
                                                             & vlSelfRef.__PVT__currentFirstStoreNextWide_44[2U]) 
                                                            | (vlSelfRef.__PVT__loadFirstNextWide_45[2U] 
                                                               | (vlSelfRef.__PVT__storeFirstNextWide_45[2U] 
                                                                  | (vlSelfRef.__PVT__strictWriteReadNextWide_45[2U] 
                                                                     | (((IData)(vlSelfRef.__PVT__isCurrent_11) 
                                                                         & vlSelfRef.__PVT__currentStoreNextWide_45[2U]) 
                                                                        | (((IData)(vlSelfRef.__PVT__isCurrent_11) 
                                                                            & vlSelfRef.__PVT__currentFirstStoreNextWide_45[2U]) 
                                                                           | (vlSelfRef.__PVT__loadFirstNextWide_46[2U] 
                                                                              | (vlSelfRef.__PVT__storeFirstNextWide_46[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_46[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_11) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_46[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_11) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_46[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_47[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_47[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_47[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_11) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_47[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_47[2U])))))))))))))))))))) 
                                               | ((vlSelfRef.__PVT__loadFirstNextWide_40[2U] 
                                                   | (vlSelfRef.__PVT__storeFirstNextWide_40[2U] 
                                                      | (vlSelfRef.__PVT__strictWriteReadNextWide_40[2U] 
                                                         | (((IData)(vlSelfRef.__PVT__isCurrent_10) 
                                                             & vlSelfRef.__PVT__currentStoreNextWide_40[2U]) 
                                                            | (((IData)(vlSelfRef.__PVT__isCurrent_10) 
                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_40[2U]) 
                                                               | (vlSelfRef.__PVT__loadFirstNextWide_41[2U] 
                                                                  | (vlSelfRef.__PVT__storeFirstNextWide_41[2U] 
                                                                     | (vlSelfRef.__PVT__strictWriteReadNextWide_41[2U] 
                                                                        | (((IData)(vlSelfRef.__PVT__isCurrent_10) 
                                                                            & vlSelfRef.__PVT__currentStoreNextWide_41[2U]) 
                                                                           | (((IData)(vlSelfRef.__PVT__isCurrent_10) 
                                                                               & vlSelfRef.__PVT__currentFirstStoreNextWide_41[2U]) 
                                                                              | (vlSelfRef.__PVT__loadFirstNextWide_42[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_42[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_42[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_10) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_42[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_10) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_42[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_43[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_43[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_43[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_10) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_43[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_43[2U])))))))))))))))))))) 
                                                  | ((vlSelfRef.__PVT__loadFirstNextWide_36[2U] 
                                                      | (vlSelfRef.__PVT__storeFirstNextWide_36[2U] 
                                                         | (vlSelfRef.__PVT__strictWriteReadNextWide_36[2U] 
                                                            | (((IData)(vlSelfRef.__PVT__isCurrent_9) 
                                                                & vlSelfRef.__PVT__currentStoreNextWide_36[2U]) 
                                                               | (((IData)(vlSelfRef.__PVT__isCurrent_9) 
                                                                   & vlSelfRef.__PVT__currentFirstStoreNextWide_36[2U]) 
                                                                  | (vlSelfRef.__PVT__loadFirstNextWide_37[2U] 
                                                                     | (vlSelfRef.__PVT__storeFirstNextWide_37[2U] 
                                                                        | (vlSelfRef.__PVT__strictWriteReadNextWide_37[2U] 
                                                                           | (((IData)(vlSelfRef.__PVT__isCurrent_9) 
                                                                               & vlSelfRef.__PVT__currentStoreNextWide_37[2U]) 
                                                                              | (((IData)(vlSelfRef.__PVT__isCurrent_9) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_37[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_38[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_38[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_38[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_9) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_38[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_9) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_38[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_39[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_39[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_39[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_9) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_39[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_39[2U])))))))))))))))))))) 
                                                     | ((vlSelfRef.__PVT__loadFirstNextWide_32[2U] 
                                                         | (vlSelfRef.__PVT__storeFirstNextWide_32[2U] 
                                                            | (vlSelfRef.__PVT__strictWriteReadNextWide_32[2U] 
                                                               | (((IData)(vlSelfRef.__PVT__isCurrent_8) 
                                                                   & vlSelfRef.__PVT__currentStoreNextWide_32[2U]) 
                                                                  | (((IData)(vlSelfRef.__PVT__isCurrent_8) 
                                                                      & vlSelfRef.__PVT__currentFirstStoreNextWide_32[2U]) 
                                                                     | (vlSelfRef.__PVT__loadFirstNextWide_33[2U] 
                                                                        | (vlSelfRef.__PVT__storeFirstNextWide_33[2U] 
                                                                           | (vlSelfRef.__PVT__strictWriteReadNextWide_33[2U] 
                                                                              | (((IData)(vlSelfRef.__PVT__isCurrent_8) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_33[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_8) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_33[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_34[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_34[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_34[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_8) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_34[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_8) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_34[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_35[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_35[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_35[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_8) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_35[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_35[2U])))))))))))))))))))) 
                                                        | ((vlSelfRef.__PVT__loadFirstNextWide_28[2U] 
                                                            | (vlSelfRef.__PVT__storeFirstNextWide_28[2U] 
                                                               | (vlSelfRef.__PVT__strictWriteReadNextWide_28[2U] 
                                                                  | (((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                                                      & vlSelfRef.__PVT__currentStoreNextWide_28[2U]) 
                                                                     | (((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                                                         & vlSelfRef.__PVT__currentFirstStoreNextWide_28[2U]) 
                                                                        | (vlSelfRef.__PVT__loadFirstNextWide_29[2U] 
                                                                           | (vlSelfRef.__PVT__storeFirstNextWide_29[2U] 
                                                                              | (vlSelfRef.__PVT__strictWriteReadNextWide_29[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_29[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_29[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_30[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_30[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_30[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_30[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_30[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_31[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_31[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_31[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_31[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_31[2U])))))))))))))))))))) 
                                                           | ((vlSelfRef.__PVT__loadFirstNextWide_24[2U] 
                                                               | (vlSelfRef.__PVT__storeFirstNextWide_24[2U] 
                                                                  | (vlSelfRef.__PVT__strictWriteReadNextWide_24[2U] 
                                                                     | (((IData)(vlSelfRef.__PVT__isCurrent_6) 
                                                                         & vlSelfRef.__PVT__currentStoreNextWide_24[2U]) 
                                                                        | (((IData)(vlSelfRef.__PVT__isCurrent_6) 
                                                                            & vlSelfRef.__PVT__currentFirstStoreNextWide_24[2U]) 
                                                                           | (vlSelfRef.__PVT__loadFirstNextWide_25[2U] 
                                                                              | (vlSelfRef.__PVT__storeFirstNextWide_25[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_25[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_6) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_25[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_6) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_25[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_26[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_26[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_26[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_6) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_26[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_6) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_26[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_27[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_27[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_27[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_6) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_27[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_27[2U])))))))))))))))))))) 
                                                              | ((vlSelfRef.__PVT__loadFirstNextWide_20[2U] 
                                                                  | (vlSelfRef.__PVT__storeFirstNextWide_20[2U] 
                                                                     | (vlSelfRef.__PVT__strictWriteReadNextWide_20[2U] 
                                                                        | (((IData)(vlSelfRef.__PVT__isCurrent_5) 
                                                                            & vlSelfRef.__PVT__currentStoreNextWide_20[2U]) 
                                                                           | (((IData)(vlSelfRef.__PVT__isCurrent_5) 
                                                                               & vlSelfRef.__PVT__currentFirstStoreNextWide_20[2U]) 
                                                                              | (vlSelfRef.__PVT__loadFirstNextWide_21[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_21[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_21[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_5) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_21[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_5) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_21[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_22[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_22[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_22[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_5) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_22[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_5) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_22[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_23[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_23[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_23[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_5) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_23[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_23[2U])))))))))))))))))))) 
                                                                 | ((vlSelfRef.__PVT__loadFirstNextWide_16[2U] 
                                                                     | (vlSelfRef.__PVT__storeFirstNextWide_16[2U] 
                                                                        | (vlSelfRef.__PVT__strictWriteReadNextWide_16[2U] 
                                                                           | (((IData)(vlSelfRef.__PVT__isCurrent_4) 
                                                                               & vlSelfRef.__PVT__currentStoreNextWide_16[2U]) 
                                                                              | (((IData)(vlSelfRef.__PVT__isCurrent_4) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_16[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_17[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_17[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_17[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_4) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_17[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_4) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_17[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_18[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_18[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_18[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_4) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_18[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_4) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_18[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_19[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_19[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_19[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_4) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_19[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_19[2U])))))))))))))))))))) 
                                                                    | ((vlSelfRef.__PVT__loadFirstNextWide_12[2U] 
                                                                        | (vlSelfRef.__PVT__storeFirstNextWide_12[2U] 
                                                                           | (vlSelfRef.__PVT__strictWriteReadNextWide_12[2U] 
                                                                              | (((IData)(vlSelfRef.__PVT__isCurrent_3) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_12[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_3) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_12[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_13[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_13[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_13[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_3) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_13[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_3) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_13[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_14[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_14[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_14[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_3) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_14[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_3) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_14[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_15[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_15[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_15[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_3) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_15[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_15[2U])))))))))))))))))))) 
                                                                       | ((vlSelfRef.__PVT__loadFirstNextWide_8[2U] 
                                                                           | (vlSelfRef.__PVT__storeFirstNextWide_8[2U] 
                                                                              | (vlSelfRef.__PVT__strictWriteReadNextWide_8[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_2) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_8[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_2) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_8[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_9[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_9[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_9[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_2) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_9[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_2) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_9[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_10[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_10[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_10[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_2) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_10[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_2) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_10[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_11[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_11[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_11[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_2) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_11[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_11[2U])))))))))))))))))))) 
                                                                          | ((vlSelfRef.__PVT__loadFirstNextWide_4[2U] 
                                                                              | (vlSelfRef.__PVT__storeFirstNextWide_4[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_4[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_1) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_4[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_1) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_4[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_5[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_5[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_5[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_1) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_5[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_1) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_5[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_6[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_6[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_6[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_1) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_6[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_1) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_6[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_7[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_7[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_7[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent_1) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_7[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_7[2U])))))))))))))))))))) 
                                                                             | (vlSelfRef.__PVT__loadFirstNextWide[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_1[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_1[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_1[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_1[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_1[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_2[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_2[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_2[2U] 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent) 
                                                                                & vlSelfRef.__PVT__currentStoreNextWide_2[2U]) 
                                                                                | (((IData)(vlSelfRef.__PVT__isCurrent) 
                                                                                & vlSelfRef.__PVT__currentFirstStoreNextWide_2[2U]) 
                                                                                | (vlSelfRef.__PVT__loadFirstNextWide_3[2U] 
                                                                                | (vlSelfRef.__PVT__storeFirstNextWide_3[2U] 
                                                                                | (vlSelfRef.__PVT__strictWriteReadNextWide_3[2U] 
                                                                                | ((IData)(vlSelfRef.__PVT__isCurrent) 
                                                                                & (vlSelfRef.__PVT__currentStoreNextWide_3[2U] 
                                                                                | vlSelfRef.__PVT__currentFirstStoreNextWide_3[2U]))))))))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__20(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__20\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_18 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_432) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_442));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_17 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_427) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_437));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_23 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_569) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_579));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_22 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_564) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_574));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_28 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_706) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_716));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_27 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_701) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_711));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_33 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_843) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_853));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_32 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_838) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_848));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_38 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_980) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_990));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_37 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_975) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_985));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_43 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1117) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1127));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_42 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1112) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1122));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_48 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1254) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1264));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_47 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1249) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1259));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_53 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1391) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1401));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_52 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1386) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1396));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_58 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1528) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1538));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_57 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1523) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1533));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_63 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1665) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1675));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_62 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1660) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1670));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_68 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1802) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1812));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_67 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1797) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1807));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_73 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1939) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1949));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_72 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1934) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1944));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_78 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2076) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2086));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_77 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2071) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2081));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_83 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2213) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2223));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_82 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2208) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2218));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_88 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2350) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2360));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_87 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2345) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2355));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_93 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2487) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2497));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_92 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2482) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2492));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_98 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2624) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2634));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_97 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2619) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2629));
    if (vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_3) {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_115 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_32;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_120 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_33;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_126 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_34;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_132 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_35;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_47 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_22;
    } else {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_115 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_22;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_120 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_23;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_126 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_24;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_132 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_25;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_47 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_32;
    }
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__50(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__50\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_4) {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_98 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_43;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_103 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_44;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_108 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_45;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_68 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_47;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_74 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_48;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_80 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_49;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_86 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_50;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_61 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_41;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_56 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_46;
    } else {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_98 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_48;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_103 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_49;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_108 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_50;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_68 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_42;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_74 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_43;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_80 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_44;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_86 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_45;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_61 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_46;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_56 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_41;
    }
    if (vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_9) {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_229 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_179;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_235 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_180;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_240 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_181;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_245 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_182;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_205 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_184;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_211 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_185;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_217 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_186;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_223 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_187;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_198 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_178;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_193 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_183;
    } else {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_229 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_184;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_235 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_185;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_240 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_186;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_245 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_187;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_205 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_179;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_211 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_180;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_217 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_181;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_223 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_182;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_198 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_183;
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_193 
            = vlSelfRef.__PVT___bucketStoreFirstDelta_T_178;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_4) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_92 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_98 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_103 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_44;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_108 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_45;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_68 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_74 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_48;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_80 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_49;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_86 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_50;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_41;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_46;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_92 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_98 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_48;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_103 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_49;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_108 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_50;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_68 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_74 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_80 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_44;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_86 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_45;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_46;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_41;
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_229 
        = ((IData)(vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_9)
            ? (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_179)
            : (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_184));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__51(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__51\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_9) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_235 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_180;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_240 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_181;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_245 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_182;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_205 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_184;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_211 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_185;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_217 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_186;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_223 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_187;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_178;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_183;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_235 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_185;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_240 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_186;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_245 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_187;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_205 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_179;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_211 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_180;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_217 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_181;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_223 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_182;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_183;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_178;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_14) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_366 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_316;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_372 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_317;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_377 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_318;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_382 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_319;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_342 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_321;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_348 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_322;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_354 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_323;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_360 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_324;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_315;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_320;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_366 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_321;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_372 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_322;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_377 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_323;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_382 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_324;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_342 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_316;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_348 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_317;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_354 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_318;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_360 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_319;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_320;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_315;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_19) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_503 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_453;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_509 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_454;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_514 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_455;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_519 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_456;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_479 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_458;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_485 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_459;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_491 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_460;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_497 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_461;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_452;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_457;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_503 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_458;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_509 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_459;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_514 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_460;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_519 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_461;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_479 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_453;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_485 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_454;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_491 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_455;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_497 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_456;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_457;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_452;
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_640 
        = ((IData)(vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_24)
            ? (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_590)
            : (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_595));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__52(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__52\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_24) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_646 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_591;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_651 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_592;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_656 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_593;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_616 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_595;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_622 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_596;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_628 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_597;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_634 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_598;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_589;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_594;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_646 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_596;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_651 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_597;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_656 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_598;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_616 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_590;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_622 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_591;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_628 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_592;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_634 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_593;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_594;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_589;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_29) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_777 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_727;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_783 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_728;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_788 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_729;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_793 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_730;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_753 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_732;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_759 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_733;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_765 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_734;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_771 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_735;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_726;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_731;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_777 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_732;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_783 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_733;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_788 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_734;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_793 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_735;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_753 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_727;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_759 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_728;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_765 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_729;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_771 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_730;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_731;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_726;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_34) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_914 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_864;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_920 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_865;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_925 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_866;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_930 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_867;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_890 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_869;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_896 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_870;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_902 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_871;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_908 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_872;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_863;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_868;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_914 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_869;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_920 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_870;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_925 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_871;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_930 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_872;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_890 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_864;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_896 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_865;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_902 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_866;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_908 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_867;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_868;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_863;
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1051 
        = ((IData)(vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_39)
            ? (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1001)
            : (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1006));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__53(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__53\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_39) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1057 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1002;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1062 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1003;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1067 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1004;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1027 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1006;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1033 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1007;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1039 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1008;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1045 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1009;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1000;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1005;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1057 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1007;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1062 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1008;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1067 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1009;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1027 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1001;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1033 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1002;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1039 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1003;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1045 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1004;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1005;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1000;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_44) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1188 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1138;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1194 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1139;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1199 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1140;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1204 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1141;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1164 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1143;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1170 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1144;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1176 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1145;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1182 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1146;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1137;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1142;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1188 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1143;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1194 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1144;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1199 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1145;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1204 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1146;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1164 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1138;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1170 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1139;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1176 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1140;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1182 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1141;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1142;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1137;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_49) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1325 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1275;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1331 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1276;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1336 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1277;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1341 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1278;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1301 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1280;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1307 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1281;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1313 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1282;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1319 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1283;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1274;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1279;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1325 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1280;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1331 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1281;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1336 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1282;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1341 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1283;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1301 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1275;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1307 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1276;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1313 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1277;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1319 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1278;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1279;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1274;
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1462 
        = ((IData)(vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_54)
            ? (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1412)
            : (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1417));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__54(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__54\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_54) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1468 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1413;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1473 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1414;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1478 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1415;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1438 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1417;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1444 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1418;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1450 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1419;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1456 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1420;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1411;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1416;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1468 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1418;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1473 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1419;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1478 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1420;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1438 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1412;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1444 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1413;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1450 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1414;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1456 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1415;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1416;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1411;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_59) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1599 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1549;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1605 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1550;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1610 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1551;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1615 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1552;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1575 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1554;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1581 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1555;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1587 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1556;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1593 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1557;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1548;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1553;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1599 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1554;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1605 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1555;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1610 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1556;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1615 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1557;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1575 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1549;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1581 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1550;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1587 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1551;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1593 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1552;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1553;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1548;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_64) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1736 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1686;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1742 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1687;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1747 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1688;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1752 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1689;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1712 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1691;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1718 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1692;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1724 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1693;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1730 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1694;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1685;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1690;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1736 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1691;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1742 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1692;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1747 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1693;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1752 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1694;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1712 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1686;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1718 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1687;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1724 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1688;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1730 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1689;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1690;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1685;
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1873 
        = ((IData)(vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_69)
            ? (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1823)
            : (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1828));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__55(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__55\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_69) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1879 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1824;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1884 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1825;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1889 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1826;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1849 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1828;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1855 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1829;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1861 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1830;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1867 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1831;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1842 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1822;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1837 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1827;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1879 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1829;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1884 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1830;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1889 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1831;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1849 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1823;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1855 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1824;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1861 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1825;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1867 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1826;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1842 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1827;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1837 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1822;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_74) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2010 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1960;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2016 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1961;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2021 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1962;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2026 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1963;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1986 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1965;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1992 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1966;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1998 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1967;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2004 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1968;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1979 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1959;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1974 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1964;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2010 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1965;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2016 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1966;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2021 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1967;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2026 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1968;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1986 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1960;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1992 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1961;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1998 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1962;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2004 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1963;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1979 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1964;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1974 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1959;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_79) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2147 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2097;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2153 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2098;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2158 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2099;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2163 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2100;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2123 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2102;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2129 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2103;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2135 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2104;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2141 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2105;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2116 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2096;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2111 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2101;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2147 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2102;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2153 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2103;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2158 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2104;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2163 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2105;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2123 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2097;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2129 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2098;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2135 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2099;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2141 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2100;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2116 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2101;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2111 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2096;
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2284 
        = ((IData)(vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_84)
            ? (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2234)
            : (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2239));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__56(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_sequent__TOP__tb__DOT__dut__DOT__reference_0__56\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_84) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2290 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2235;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2295 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2236;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2300 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2237;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2260 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2239;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2266 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2240;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2272 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2241;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2278 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2242;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2253 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2233;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2248 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2238;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2290 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2240;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2295 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2241;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2300 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2242;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2260 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2234;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2266 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2235;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2272 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2236;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2278 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2237;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2253 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2238;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2248 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2233;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_89) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2421 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2371;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2427 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2372;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2432 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2373;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2437 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2374;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2397 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2376;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2403 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2377;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2409 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2378;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2415 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2379;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2390 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2370;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2375;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2421 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2376;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2427 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2377;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2432 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2378;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2437 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2379;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2397 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2371;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2403 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2372;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2409 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2373;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2415 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2374;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2390 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2375;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2370;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_94) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2558 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2508;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2564 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2509;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2569 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2510;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2574 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2511;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2534 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2513;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2540 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2514;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2546 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2515;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2552 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2516;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2507;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2512;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2558 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2513;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2564 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2514;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2569 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2515;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2574 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2516;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2534 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2508;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2540 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2509;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2546 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2510;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2552 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2511;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2512;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2507;
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2695 
        = ((IData)(vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_99)
            ? (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2645)
            : (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2650));
}
