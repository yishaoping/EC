// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_ReferenceBank.h"
#include "Vtb__Syms.h"

VL_INLINE_OPT void Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__98(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__98\n"); );
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
    // Body
    vlSelfRef.__PVT___T_381 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_5) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_5)));
    __Vtemp_2[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_5_0);
    __Vtemp_2[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_5_0 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2493;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__loadFirstNextWide_20[0U] = __Vtemp_4[0U];
    vlSelfRef.__PVT__loadFirstNextWide_20[1U] = __Vtemp_4[1U];
    vlSelfRef.__PVT__loadFirstNextWide_20[2U] = (1U 
                                                 & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_5_1);
    __Vtemp_6[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_5_1 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2532;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__loadFirstNextWide_21[0U] = __Vtemp_8[0U];
    vlSelfRef.__PVT__loadFirstNextWide_21[1U] = __Vtemp_8[1U];
    vlSelfRef.__PVT__loadFirstNextWide_21[2U] = (1U 
                                                 & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_5_2);
    __Vtemp_10[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_5_2 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2573;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__loadFirstNextWide_22[0U] = __Vtemp_12[0U];
    vlSelfRef.__PVT__loadFirstNextWide_22[1U] = __Vtemp_12[1U];
    vlSelfRef.__PVT__loadFirstNextWide_22[2U] = (1U 
                                                 & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_5_3);
    __Vtemp_14[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_5_3 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2614;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__loadFirstNextWide_23[0U] = __Vtemp_16[0U];
    vlSelfRef.__PVT__loadFirstNextWide_23[1U] = __Vtemp_16[1U];
    vlSelfRef.__PVT__loadFirstNextWide_23[2U] = (1U 
                                                 & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_5_0);
    __Vtemp_18[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_5_0 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2493;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__storeFirstNextWide_20[0U] = __Vtemp_20[0U];
    vlSelfRef.__PVT__storeFirstNextWide_20[1U] = __Vtemp_20[1U];
    vlSelfRef.__PVT__storeFirstNextWide_20[2U] = (1U 
                                                  & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_5_1);
    __Vtemp_22[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_5_1 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2532;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__storeFirstNextWide_21[0U] = __Vtemp_24[0U];
    vlSelfRef.__PVT__storeFirstNextWide_21[1U] = __Vtemp_24[1U];
    vlSelfRef.__PVT__storeFirstNextWide_21[2U] = (1U 
                                                  & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_5_2);
    __Vtemp_26[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_5_2 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2573;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__storeFirstNextWide_22[0U] = __Vtemp_28[0U];
    vlSelfRef.__PVT__storeFirstNextWide_22[1U] = __Vtemp_28[1U];
    vlSelfRef.__PVT__storeFirstNextWide_22[2U] = (1U 
                                                  & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_5_3);
    __Vtemp_30[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_5_3 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2614;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__storeFirstNextWide_23[0U] = __Vtemp_32[0U];
    vlSelfRef.__PVT__storeFirstNextWide_23[1U] = __Vtemp_32[1U];
    vlSelfRef.__PVT__storeFirstNextWide_23[2U] = (1U 
                                                  & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_5_0);
    __Vtemp_34[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_5_0 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25494;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__strictWriteReadNextWide_20[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_20[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_20[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_5_1);
    __Vtemp_38[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_5_1 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25910;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__strictWriteReadNextWide_21[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_21[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_21[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_5_2);
    __Vtemp_42[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_5_2 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_26346;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__strictWriteReadNextWide_22[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_22[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_22[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_5_3);
    __Vtemp_46[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_5_3 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_26782;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__strictWriteReadNextWide_23[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_23[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_23[2U] 
        = (1U & __Vtemp_48[2U]);
    vlSelfRef.__PVT__allocate_5 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_5)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_5));
    vlSelfRef.__PVT___GEN_505 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_5)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_5));
    vlSelfRef.__PVT___T_235 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_3) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_3)));
    __Vtemp_50[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_3_0);
    __Vtemp_50[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_3_0 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1621;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__loadFirstNextWide_12[0U] = __Vtemp_52[0U];
    vlSelfRef.__PVT__loadFirstNextWide_12[1U] = __Vtemp_52[1U];
    vlSelfRef.__PVT__loadFirstNextWide_12[2U] = (1U 
                                                 & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_3_1);
    __Vtemp_54[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_3_1 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1660;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__loadFirstNextWide_13[0U] = __Vtemp_56[0U];
    vlSelfRef.__PVT__loadFirstNextWide_13[1U] = __Vtemp_56[1U];
    vlSelfRef.__PVT__loadFirstNextWide_13[2U] = (1U 
                                                 & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_3_2);
    __Vtemp_58[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_3_2 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1701;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__loadFirstNextWide_14[0U] = __Vtemp_60[0U];
    vlSelfRef.__PVT__loadFirstNextWide_14[1U] = __Vtemp_60[1U];
    vlSelfRef.__PVT__loadFirstNextWide_14[2U] = (1U 
                                                 & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_3_3);
    __Vtemp_62[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_3_3 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1742;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__loadFirstNextWide_15[0U] = __Vtemp_64[0U];
    vlSelfRef.__PVT__loadFirstNextWide_15[1U] = __Vtemp_64[1U];
    vlSelfRef.__PVT__loadFirstNextWide_15[2U] = (1U 
                                                 & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_3_0);
    __Vtemp_66[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_3_0 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1621;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__storeFirstNextWide_12[0U] = __Vtemp_68[0U];
    vlSelfRef.__PVT__storeFirstNextWide_12[1U] = __Vtemp_68[1U];
    vlSelfRef.__PVT__storeFirstNextWide_12[2U] = (1U 
                                                  & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_3_1);
    __Vtemp_70[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_3_1 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1660;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__storeFirstNextWide_13[0U] = __Vtemp_72[0U];
    vlSelfRef.__PVT__storeFirstNextWide_13[1U] = __Vtemp_72[1U];
    vlSelfRef.__PVT__storeFirstNextWide_13[2U] = (1U 
                                                  & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_3_2);
    __Vtemp_74[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_3_2 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1701;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__storeFirstNextWide_14[0U] = __Vtemp_76[0U];
    vlSelfRef.__PVT__storeFirstNextWide_14[1U] = __Vtemp_76[1U];
    vlSelfRef.__PVT__storeFirstNextWide_14[2U] = (1U 
                                                  & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_3_3);
    __Vtemp_78[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_3_3 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1742;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__storeFirstNextWide_15[0U] = __Vtemp_80[0U];
    vlSelfRef.__PVT__storeFirstNextWide_15[1U] = __Vtemp_80[1U];
    vlSelfRef.__PVT__storeFirstNextWide_15[2U] = (1U 
                                                  & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_3_0);
    __Vtemp_82[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_3_0 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16566;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.__PVT__strictWriteReadNextWide_12[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_12[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_12[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_3_1);
    __Vtemp_86[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_3_1 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16982;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.__PVT__strictWriteReadNextWide_13[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_13[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_13[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_3_2);
    __Vtemp_90[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_3_2 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_17418;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.__PVT__strictWriteReadNextWide_14[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_14[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_14[2U] 
        = (1U & __Vtemp_92[2U]);
    __Vtemp_94[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_3_3);
    __Vtemp_94[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_3_3 
                              >> 0x20U));
    __Vtemp_94[2U] = 0U;
    __Vtemp_95[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_17854;
    __Vtemp_95[1U] = 0U;
    __Vtemp_95[2U] = 0U;
    VL_ADD_W(3, __Vtemp_96, __Vtemp_94, __Vtemp_95);
    vlSelfRef.__PVT__strictWriteReadNextWide_15[0U] 
        = __Vtemp_96[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_15[1U] 
        = __Vtemp_96[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_15[2U] 
        = (1U & __Vtemp_96[2U]);
    vlSelfRef.__PVT__allocate_3 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_3)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_3));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__99(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__99\n"); );
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
    // Body
    vlSelfRef.__PVT___GEN_335 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_3)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_3));
    vlSelfRef.__PVT___T_16 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                              & ((IData)(vlSelfRef.__PVT__isRetiring) 
                                 & (IData)(vlSelfRef.bucketValid_0)));
    __Vtemp_2[0U] = (IData)(vlSelfRef.bucketLoadFirst_0_0);
    __Vtemp_2[1U] = (IData)((vlSelfRef.bucketLoadFirst_0_0 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_313;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__loadFirstNextWide[0U] = __Vtemp_4[0U];
    vlSelfRef.__PVT__loadFirstNextWide[1U] = __Vtemp_4[1U];
    vlSelfRef.__PVT__loadFirstNextWide[2U] = (1U & 
                                              __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.bucketLoadFirst_0_1);
    __Vtemp_6[1U] = (IData)((vlSelfRef.bucketLoadFirst_0_1 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_352;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__loadFirstNextWide_1[0U] = __Vtemp_8[0U];
    vlSelfRef.__PVT__loadFirstNextWide_1[1U] = __Vtemp_8[1U];
    vlSelfRef.__PVT__loadFirstNextWide_1[2U] = (1U 
                                                & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.bucketLoadFirst_0_2);
    __Vtemp_10[1U] = (IData)((vlSelfRef.bucketLoadFirst_0_2 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_393;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__loadFirstNextWide_2[0U] = __Vtemp_12[0U];
    vlSelfRef.__PVT__loadFirstNextWide_2[1U] = __Vtemp_12[1U];
    vlSelfRef.__PVT__loadFirstNextWide_2[2U] = (1U 
                                                & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.bucketLoadFirst_0_3);
    __Vtemp_14[1U] = (IData)((vlSelfRef.bucketLoadFirst_0_3 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_434;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__loadFirstNextWide_3[0U] = __Vtemp_16[0U];
    vlSelfRef.__PVT__loadFirstNextWide_3[1U] = __Vtemp_16[1U];
    vlSelfRef.__PVT__loadFirstNextWide_3[2U] = (1U 
                                                & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.bucketStoreFirst_0_0);
    __Vtemp_18[1U] = (IData)((vlSelfRef.bucketStoreFirst_0_0 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_313;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__storeFirstNextWide[0U] = __Vtemp_20[0U];
    vlSelfRef.__PVT__storeFirstNextWide[1U] = __Vtemp_20[1U];
    vlSelfRef.__PVT__storeFirstNextWide[2U] = (1U & 
                                               __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.bucketStoreFirst_0_1);
    __Vtemp_22[1U] = (IData)((vlSelfRef.bucketStoreFirst_0_1 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_352;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__storeFirstNextWide_1[0U] = __Vtemp_24[0U];
    vlSelfRef.__PVT__storeFirstNextWide_1[1U] = __Vtemp_24[1U];
    vlSelfRef.__PVT__storeFirstNextWide_1[2U] = (1U 
                                                 & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.bucketStoreFirst_0_2);
    __Vtemp_26[1U] = (IData)((vlSelfRef.bucketStoreFirst_0_2 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_393;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__storeFirstNextWide_2[0U] = __Vtemp_28[0U];
    vlSelfRef.__PVT__storeFirstNextWide_2[1U] = __Vtemp_28[1U];
    vlSelfRef.__PVT__storeFirstNextWide_2[2U] = (1U 
                                                 & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.bucketStoreFirst_0_3);
    __Vtemp_30[1U] = (IData)((vlSelfRef.bucketStoreFirst_0_3 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_434;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__storeFirstNextWide_3[0U] = __Vtemp_32[0U];
    vlSelfRef.__PVT__storeFirstNextWide_3[1U] = __Vtemp_32[1U];
    vlSelfRef.__PVT__storeFirstNextWide_3[2U] = (1U 
                                                 & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_0_0);
    __Vtemp_34[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_0_0 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3174;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__strictWriteReadNextWide[0U] = 
        __Vtemp_36[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide[1U] = 
        __Vtemp_36[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide[2U] = 
        (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_0_1);
    __Vtemp_38[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_0_1 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3590;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__strictWriteReadNextWide_1[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_1[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_1[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_0_2);
    __Vtemp_42[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_0_2 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_4026;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__strictWriteReadNextWide_2[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_2[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_2[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_0_3);
    __Vtemp_46[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_0_3 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_4462;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__strictWriteReadNextWide_3[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_3[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_3[2U] 
        = (1U & __Vtemp_48[2U]);
    vlSelfRef.__PVT__allocate = ((~ (IData)(vlSelfRef.bucketValid_0)) 
                                 & (IData)(vlSelfRef.__PVT__isCurrent));
    vlSelfRef.__PVT___GEN_80 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                 & (IData)(vlSelfRef.__PVT__isCurrent)) 
                                | (IData)(vlSelfRef.bucketValid_0));
    vlSelfRef.__PVT___T_1038 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                                & ((IData)(vlSelfRef.__PVT__isRetiring_14) 
                                   & (IData)(vlSelfRef.__PVT__bucketValid_14)));
    __Vtemp_50[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_14_0);
    __Vtemp_50[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_14_0 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_6417;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__loadFirstNextWide_56[0U] = __Vtemp_52[0U];
    vlSelfRef.__PVT__loadFirstNextWide_56[1U] = __Vtemp_52[1U];
    vlSelfRef.__PVT__loadFirstNextWide_56[2U] = (1U 
                                                 & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_14_1);
    __Vtemp_54[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_14_1 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_6456;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__loadFirstNextWide_57[0U] = __Vtemp_56[0U];
    vlSelfRef.__PVT__loadFirstNextWide_57[1U] = __Vtemp_56[1U];
    vlSelfRef.__PVT__loadFirstNextWide_57[2U] = (1U 
                                                 & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_14_2);
    __Vtemp_58[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_14_2 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_6497;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__loadFirstNextWide_58[0U] = __Vtemp_60[0U];
    vlSelfRef.__PVT__loadFirstNextWide_58[1U] = __Vtemp_60[1U];
    vlSelfRef.__PVT__loadFirstNextWide_58[2U] = (1U 
                                                 & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_14_3);
    __Vtemp_62[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_14_3 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_6538;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__loadFirstNextWide_59[0U] = __Vtemp_64[0U];
    vlSelfRef.__PVT__loadFirstNextWide_59[1U] = __Vtemp_64[1U];
    vlSelfRef.__PVT__loadFirstNextWide_59[2U] = (1U 
                                                 & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_14_0);
    __Vtemp_66[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_14_0 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_6417;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__storeFirstNextWide_56[0U] = __Vtemp_68[0U];
    vlSelfRef.__PVT__storeFirstNextWide_56[1U] = __Vtemp_68[1U];
    vlSelfRef.__PVT__storeFirstNextWide_56[2U] = (1U 
                                                  & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_14_1);
    __Vtemp_70[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_14_1 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_6456;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__storeFirstNextWide_57[0U] = __Vtemp_72[0U];
    vlSelfRef.__PVT__storeFirstNextWide_57[1U] = __Vtemp_72[1U];
    vlSelfRef.__PVT__storeFirstNextWide_57[2U] = (1U 
                                                  & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_14_2);
    __Vtemp_74[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_14_2 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_6497;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__storeFirstNextWide_58[0U] = __Vtemp_76[0U];
    vlSelfRef.__PVT__storeFirstNextWide_58[1U] = __Vtemp_76[1U];
    vlSelfRef.__PVT__storeFirstNextWide_58[2U] = (1U 
                                                  & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_14_3);
    __Vtemp_78[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_14_3 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_6538;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__storeFirstNextWide_59[0U] = __Vtemp_80[0U];
    vlSelfRef.__PVT__storeFirstNextWide_59[1U] = __Vtemp_80[1U];
    vlSelfRef.__PVT__storeFirstNextWide_59[2U] = (1U 
                                                  & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_14_0);
    __Vtemp_82[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_14_0 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65670;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.__PVT__strictWriteReadNextWide_56[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_56[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_56[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_14_1);
    __Vtemp_86[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_14_1 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66086;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.__PVT__strictWriteReadNextWide_57[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_57[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_57[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_14_2);
    __Vtemp_90[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_14_2 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66522;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.__PVT__strictWriteReadNextWide_58[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_58[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_58[2U] 
        = (1U & __Vtemp_92[2U]);
    __Vtemp_94[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_14_3);
    __Vtemp_94[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_14_3 
                              >> 0x20U));
    __Vtemp_94[2U] = 0U;
    __Vtemp_95[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66958;
    __Vtemp_95[1U] = 0U;
    __Vtemp_95[2U] = 0U;
    VL_ADD_W(3, __Vtemp_96, __Vtemp_94, __Vtemp_95);
    vlSelfRef.__PVT__strictWriteReadNextWide_59[0U] 
        = __Vtemp_96[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_59[1U] 
        = __Vtemp_96[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_59[2U] 
        = (1U & __Vtemp_96[2U]);
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__100(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__100\n"); );
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
    // Body
    vlSelfRef.__PVT__allocate_14 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_14)) 
                                    & (IData)(vlSelfRef.__PVT__isCurrent_14));
    vlSelfRef.__PVT___GEN_1270 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_14)) 
                                  | (IData)(vlSelfRef.__PVT__bucketValid_14));
    vlSelfRef.__PVT___T_965 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_13) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_13)));
    __Vtemp_2[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_13_0);
    __Vtemp_2[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_13_0 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_5981;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__loadFirstNextWide_52[0U] = __Vtemp_4[0U];
    vlSelfRef.__PVT__loadFirstNextWide_52[1U] = __Vtemp_4[1U];
    vlSelfRef.__PVT__loadFirstNextWide_52[2U] = (1U 
                                                 & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_13_1);
    __Vtemp_6[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_13_1 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_6020;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__loadFirstNextWide_53[0U] = __Vtemp_8[0U];
    vlSelfRef.__PVT__loadFirstNextWide_53[1U] = __Vtemp_8[1U];
    vlSelfRef.__PVT__loadFirstNextWide_53[2U] = (1U 
                                                 & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_13_2);
    __Vtemp_10[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_13_2 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_6061;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__loadFirstNextWide_54[0U] = __Vtemp_12[0U];
    vlSelfRef.__PVT__loadFirstNextWide_54[1U] = __Vtemp_12[1U];
    vlSelfRef.__PVT__loadFirstNextWide_54[2U] = (1U 
                                                 & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_13_3);
    __Vtemp_14[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_13_3 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_6102;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__loadFirstNextWide_55[0U] = __Vtemp_16[0U];
    vlSelfRef.__PVT__loadFirstNextWide_55[1U] = __Vtemp_16[1U];
    vlSelfRef.__PVT__loadFirstNextWide_55[2U] = (1U 
                                                 & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_13_0);
    __Vtemp_18[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_13_0 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_5981;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__storeFirstNextWide_52[0U] = __Vtemp_20[0U];
    vlSelfRef.__PVT__storeFirstNextWide_52[1U] = __Vtemp_20[1U];
    vlSelfRef.__PVT__storeFirstNextWide_52[2U] = (1U 
                                                  & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_13_1);
    __Vtemp_22[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_13_1 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_6020;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__storeFirstNextWide_53[0U] = __Vtemp_24[0U];
    vlSelfRef.__PVT__storeFirstNextWide_53[1U] = __Vtemp_24[1U];
    vlSelfRef.__PVT__storeFirstNextWide_53[2U] = (1U 
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
    __Vtemp_30[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_13_3);
    __Vtemp_30[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_13_3 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_6102;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__storeFirstNextWide_55[0U] = __Vtemp_32[0U];
    vlSelfRef.__PVT__storeFirstNextWide_55[1U] = __Vtemp_32[1U];
    vlSelfRef.__PVT__storeFirstNextWide_55[2U] = (1U 
                                                  & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_13_0);
    __Vtemp_34[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_13_0 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61206;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__strictWriteReadNextWide_52[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_52[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_52[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_13_1);
    __Vtemp_38[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_13_1 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61622;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__strictWriteReadNextWide_53[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_53[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_53[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_13_2);
    __Vtemp_42[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_13_2 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_62058;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__strictWriteReadNextWide_54[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_54[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_54[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_13_3);
    __Vtemp_46[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_13_3 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_62494;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__strictWriteReadNextWide_55[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_55[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_55[2U] 
        = (1U & __Vtemp_48[2U]);
    vlSelfRef.__PVT__allocate_13 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_13)) 
                                    & (IData)(vlSelfRef.__PVT__isCurrent_13));
    vlSelfRef.__PVT___GEN_1185 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_13)) 
                                  | (IData)(vlSelfRef.__PVT__bucketValid_13));
    vlSelfRef.__PVT___T_162 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_2) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_2)));
    __Vtemp_50[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_2_0);
    __Vtemp_50[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_2_0 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1185;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__loadFirstNextWide_8[0U] = __Vtemp_52[0U];
    vlSelfRef.__PVT__loadFirstNextWide_8[1U] = __Vtemp_52[1U];
    vlSelfRef.__PVT__loadFirstNextWide_8[2U] = (1U 
                                                & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_2_1);
    __Vtemp_54[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_2_1 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1224;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__loadFirstNextWide_9[0U] = __Vtemp_56[0U];
    vlSelfRef.__PVT__loadFirstNextWide_9[1U] = __Vtemp_56[1U];
    vlSelfRef.__PVT__loadFirstNextWide_9[2U] = (1U 
                                                & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_2_2);
    __Vtemp_58[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_2_2 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1265;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__loadFirstNextWide_10[0U] = __Vtemp_60[0U];
    vlSelfRef.__PVT__loadFirstNextWide_10[1U] = __Vtemp_60[1U];
    vlSelfRef.__PVT__loadFirstNextWide_10[2U] = (1U 
                                                 & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_2_3);
    __Vtemp_62[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_2_3 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1306;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__loadFirstNextWide_11[0U] = __Vtemp_64[0U];
    vlSelfRef.__PVT__loadFirstNextWide_11[1U] = __Vtemp_64[1U];
    vlSelfRef.__PVT__loadFirstNextWide_11[2U] = (1U 
                                                 & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_2_0);
    __Vtemp_66[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_2_0 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1185;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__storeFirstNextWide_8[0U] = __Vtemp_68[0U];
    vlSelfRef.__PVT__storeFirstNextWide_8[1U] = __Vtemp_68[1U];
    vlSelfRef.__PVT__storeFirstNextWide_8[2U] = (1U 
                                                 & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_2_1);
    __Vtemp_70[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_2_1 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1224;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__storeFirstNextWide_9[0U] = __Vtemp_72[0U];
    vlSelfRef.__PVT__storeFirstNextWide_9[1U] = __Vtemp_72[1U];
    vlSelfRef.__PVT__storeFirstNextWide_9[2U] = (1U 
                                                 & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_2_2);
    __Vtemp_74[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_2_2 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1265;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__storeFirstNextWide_10[0U] = __Vtemp_76[0U];
    vlSelfRef.__PVT__storeFirstNextWide_10[1U] = __Vtemp_76[1U];
    vlSelfRef.__PVT__storeFirstNextWide_10[2U] = (1U 
                                                  & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_2_3);
    __Vtemp_78[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_2_3 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1306;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__storeFirstNextWide_11[0U] = __Vtemp_80[0U];
    vlSelfRef.__PVT__storeFirstNextWide_11[1U] = __Vtemp_80[1U];
    vlSelfRef.__PVT__storeFirstNextWide_11[2U] = (1U 
                                                  & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_2_0);
    __Vtemp_82[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_2_0 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12102;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.__PVT__strictWriteReadNextWide_8[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_8[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_8[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_2_1);
    __Vtemp_86[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_2_1 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12518;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.__PVT__strictWriteReadNextWide_9[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_9[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_9[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_2_2);
    __Vtemp_90[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_2_2 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12954;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.__PVT__strictWriteReadNextWide_10[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_10[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_10[2U] 
        = (1U & __Vtemp_92[2U]);
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__101(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__101\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_2_3);
    __Vtemp_2[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_2_3 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_13390;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__strictWriteReadNextWide_11[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_11[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_11[2U] 
        = (1U & __Vtemp_4[2U]);
    vlSelfRef.__PVT__allocate_2 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_2)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_2));
    vlSelfRef.__PVT___GEN_250 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_2)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_2));
    vlSelfRef.__PVT___T_454 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_6) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_6)));
    __Vtemp_6[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_6_0);
    __Vtemp_6[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_6_0 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2929;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__loadFirstNextWide_24[0U] = __Vtemp_8[0U];
    vlSelfRef.__PVT__loadFirstNextWide_24[1U] = __Vtemp_8[1U];
    vlSelfRef.__PVT__loadFirstNextWide_24[2U] = (1U 
                                                 & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_6_1);
    __Vtemp_10[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_6_1 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2968;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__loadFirstNextWide_25[0U] = __Vtemp_12[0U];
    vlSelfRef.__PVT__loadFirstNextWide_25[1U] = __Vtemp_12[1U];
    vlSelfRef.__PVT__loadFirstNextWide_25[2U] = (1U 
                                                 & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_6_2);
    __Vtemp_14[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_6_2 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3009;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__loadFirstNextWide_26[0U] = __Vtemp_16[0U];
    vlSelfRef.__PVT__loadFirstNextWide_26[1U] = __Vtemp_16[1U];
    vlSelfRef.__PVT__loadFirstNextWide_26[2U] = (1U 
                                                 & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_6_3);
    __Vtemp_18[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_6_3 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3050;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__loadFirstNextWide_27[0U] = __Vtemp_20[0U];
    vlSelfRef.__PVT__loadFirstNextWide_27[1U] = __Vtemp_20[1U];
    vlSelfRef.__PVT__loadFirstNextWide_27[2U] = (1U 
                                                 & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_6_0);
    __Vtemp_22[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_6_0 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2929;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__storeFirstNextWide_24[0U] = __Vtemp_24[0U];
    vlSelfRef.__PVT__storeFirstNextWide_24[1U] = __Vtemp_24[1U];
    vlSelfRef.__PVT__storeFirstNextWide_24[2U] = (1U 
                                                  & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_6_1);
    __Vtemp_26[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_6_1 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2968;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__storeFirstNextWide_25[0U] = __Vtemp_28[0U];
    vlSelfRef.__PVT__storeFirstNextWide_25[1U] = __Vtemp_28[1U];
    vlSelfRef.__PVT__storeFirstNextWide_25[2U] = (1U 
                                                  & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_6_2);
    __Vtemp_30[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_6_2 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3009;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__storeFirstNextWide_26[0U] = __Vtemp_32[0U];
    vlSelfRef.__PVT__storeFirstNextWide_26[1U] = __Vtemp_32[1U];
    vlSelfRef.__PVT__storeFirstNextWide_26[2U] = (1U 
                                                  & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_6_3);
    __Vtemp_34[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_6_3 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3050;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__storeFirstNextWide_27[0U] = __Vtemp_36[0U];
    vlSelfRef.__PVT__storeFirstNextWide_27[1U] = __Vtemp_36[1U];
    vlSelfRef.__PVT__storeFirstNextWide_27[2U] = (1U 
                                                  & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_6_0);
    __Vtemp_38[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_6_0 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29958;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__strictWriteReadNextWide_24[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_24[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_24[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_6_1);
    __Vtemp_42[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_6_1 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_30374;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__strictWriteReadNextWide_25[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_25[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_25[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_6_2);
    __Vtemp_46[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_6_2 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_30810;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__strictWriteReadNextWide_26[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_26[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_26[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_6_3);
    __Vtemp_50[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_6_3 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_31246;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__strictWriteReadNextWide_27[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_27[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_27[2U] 
        = (1U & __Vtemp_52[2U]);
    vlSelfRef.__PVT__allocate_6 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_6)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_6));
    vlSelfRef.__PVT___GEN_590 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_6)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_6));
    vlSelfRef.__PVT___T_600 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_8) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_8)));
    __Vtemp_54[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_8_0);
    __Vtemp_54[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_8_0 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3801;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__loadFirstNextWide_32[0U] = __Vtemp_56[0U];
    vlSelfRef.__PVT__loadFirstNextWide_32[1U] = __Vtemp_56[1U];
    vlSelfRef.__PVT__loadFirstNextWide_32[2U] = (1U 
                                                 & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_8_1);
    __Vtemp_58[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_8_1 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3840;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__loadFirstNextWide_33[0U] = __Vtemp_60[0U];
    vlSelfRef.__PVT__loadFirstNextWide_33[1U] = __Vtemp_60[1U];
    vlSelfRef.__PVT__loadFirstNextWide_33[2U] = (1U 
                                                 & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_8_2);
    __Vtemp_62[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_8_2 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3881;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__loadFirstNextWide_34[0U] = __Vtemp_64[0U];
    vlSelfRef.__PVT__loadFirstNextWide_34[1U] = __Vtemp_64[1U];
    vlSelfRef.__PVT__loadFirstNextWide_34[2U] = (1U 
                                                 & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_8_3);
    __Vtemp_66[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_8_3 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3922;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__loadFirstNextWide_35[0U] = __Vtemp_68[0U];
    vlSelfRef.__PVT__loadFirstNextWide_35[1U] = __Vtemp_68[1U];
    vlSelfRef.__PVT__loadFirstNextWide_35[2U] = (1U 
                                                 & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_8_0);
    __Vtemp_70[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_8_0 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3801;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__storeFirstNextWide_32[0U] = __Vtemp_72[0U];
    vlSelfRef.__PVT__storeFirstNextWide_32[1U] = __Vtemp_72[1U];
    vlSelfRef.__PVT__storeFirstNextWide_32[2U] = (1U 
                                                  & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_8_1);
    __Vtemp_74[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_8_1 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3840;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__storeFirstNextWide_33[0U] = __Vtemp_76[0U];
    vlSelfRef.__PVT__storeFirstNextWide_33[1U] = __Vtemp_76[1U];
    vlSelfRef.__PVT__storeFirstNextWide_33[2U] = (1U 
                                                  & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_8_2);
    __Vtemp_78[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_8_2 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3881;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__storeFirstNextWide_34[0U] = __Vtemp_80[0U];
    vlSelfRef.__PVT__storeFirstNextWide_34[1U] = __Vtemp_80[1U];
    vlSelfRef.__PVT__storeFirstNextWide_34[2U] = (1U 
                                                  & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_8_3);
    __Vtemp_82[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_8_3 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3922;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.__PVT__storeFirstNextWide_35[0U] = __Vtemp_84[0U];
    vlSelfRef.__PVT__storeFirstNextWide_35[1U] = __Vtemp_84[1U];
    vlSelfRef.__PVT__storeFirstNextWide_35[2U] = (1U 
                                                  & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_8_0);
    __Vtemp_86[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_8_0 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38886;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.__PVT__strictWriteReadNextWide_32[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_32[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_32[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_8_1);
    __Vtemp_90[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_8_1 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_39302;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.__PVT__strictWriteReadNextWide_33[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_33[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_33[2U] 
        = (1U & __Vtemp_92[2U]);
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__102(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__102\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_8_2);
    __Vtemp_2[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_8_2 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_39738;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__strictWriteReadNextWide_34[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_34[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_34[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_8_3);
    __Vtemp_6[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_8_3 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_40174;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__strictWriteReadNextWide_35[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_35[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_35[2U] 
        = (1U & __Vtemp_8[2U]);
    vlSelfRef.__PVT__allocate_8 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_8)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_8));
    vlSelfRef.__PVT___GEN_760 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_8)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_8));
    vlSelfRef.__PVT___T_89 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                              & ((IData)(vlSelfRef.__PVT__isRetiring_1) 
                                 & (IData)(vlSelfRef.__PVT__bucketValid_1)));
    __Vtemp_10[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_1_0);
    __Vtemp_10[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_1_0 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_749;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__loadFirstNextWide_4[0U] = __Vtemp_12[0U];
    vlSelfRef.__PVT__loadFirstNextWide_4[1U] = __Vtemp_12[1U];
    vlSelfRef.__PVT__loadFirstNextWide_4[2U] = (1U 
                                                & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_1_1);
    __Vtemp_14[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_1_1 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_788;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__loadFirstNextWide_5[0U] = __Vtemp_16[0U];
    vlSelfRef.__PVT__loadFirstNextWide_5[1U] = __Vtemp_16[1U];
    vlSelfRef.__PVT__loadFirstNextWide_5[2U] = (1U 
                                                & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_1_2);
    __Vtemp_18[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_1_2 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_829;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__loadFirstNextWide_6[0U] = __Vtemp_20[0U];
    vlSelfRef.__PVT__loadFirstNextWide_6[1U] = __Vtemp_20[1U];
    vlSelfRef.__PVT__loadFirstNextWide_6[2U] = (1U 
                                                & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_1_3);
    __Vtemp_22[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_1_3 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_870;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__loadFirstNextWide_7[0U] = __Vtemp_24[0U];
    vlSelfRef.__PVT__loadFirstNextWide_7[1U] = __Vtemp_24[1U];
    vlSelfRef.__PVT__loadFirstNextWide_7[2U] = (1U 
                                                & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_1_0);
    __Vtemp_26[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_1_0 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_749;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__storeFirstNextWide_4[0U] = __Vtemp_28[0U];
    vlSelfRef.__PVT__storeFirstNextWide_4[1U] = __Vtemp_28[1U];
    vlSelfRef.__PVT__storeFirstNextWide_4[2U] = (1U 
                                                 & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_1_1);
    __Vtemp_30[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_1_1 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_788;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__storeFirstNextWide_5[0U] = __Vtemp_32[0U];
    vlSelfRef.__PVT__storeFirstNextWide_5[1U] = __Vtemp_32[1U];
    vlSelfRef.__PVT__storeFirstNextWide_5[2U] = (1U 
                                                 & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_1_2);
    __Vtemp_34[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_1_2 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_829;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__storeFirstNextWide_6[0U] = __Vtemp_36[0U];
    vlSelfRef.__PVT__storeFirstNextWide_6[1U] = __Vtemp_36[1U];
    vlSelfRef.__PVT__storeFirstNextWide_6[2U] = (1U 
                                                 & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_1_3);
    __Vtemp_38[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_1_3 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_870;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__storeFirstNextWide_7[0U] = __Vtemp_40[0U];
    vlSelfRef.__PVT__storeFirstNextWide_7[1U] = __Vtemp_40[1U];
    vlSelfRef.__PVT__storeFirstNextWide_7[2U] = (1U 
                                                 & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_1_0);
    __Vtemp_42[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_1_0 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7638;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__strictWriteReadNextWide_4[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_4[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_4[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_1_1);
    __Vtemp_46[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_1_1 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8054;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__strictWriteReadNextWide_5[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_5[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_5[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_1_2);
    __Vtemp_50[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_1_2 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8490;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__strictWriteReadNextWide_6[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_6[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_6[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_1_3);
    __Vtemp_54[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_1_3 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8926;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__strictWriteReadNextWide_7[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_7[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_7[2U] 
        = (1U & __Vtemp_56[2U]);
    vlSelfRef.__PVT__allocate_1 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_1)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_1));
    vlSelfRef.__PVT___GEN_165 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_1)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_1));
    vlSelfRef.__PVT___T_746 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_10) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_10)));
    __Vtemp_58[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_10_0);
    __Vtemp_58[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_10_0 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_4673;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__loadFirstNextWide_40[0U] = __Vtemp_60[0U];
    vlSelfRef.__PVT__loadFirstNextWide_40[1U] = __Vtemp_60[1U];
    vlSelfRef.__PVT__loadFirstNextWide_40[2U] = (1U 
                                                 & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_10_1);
    __Vtemp_62[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_10_1 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_4712;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__loadFirstNextWide_41[0U] = __Vtemp_64[0U];
    vlSelfRef.__PVT__loadFirstNextWide_41[1U] = __Vtemp_64[1U];
    vlSelfRef.__PVT__loadFirstNextWide_41[2U] = (1U 
                                                 & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_10_2);
    __Vtemp_66[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_10_2 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_4753;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__loadFirstNextWide_42[0U] = __Vtemp_68[0U];
    vlSelfRef.__PVT__loadFirstNextWide_42[1U] = __Vtemp_68[1U];
    vlSelfRef.__PVT__loadFirstNextWide_42[2U] = (1U 
                                                 & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_10_3);
    __Vtemp_70[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_10_3 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_4794;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__loadFirstNextWide_43[0U] = __Vtemp_72[0U];
    vlSelfRef.__PVT__loadFirstNextWide_43[1U] = __Vtemp_72[1U];
    vlSelfRef.__PVT__loadFirstNextWide_43[2U] = (1U 
                                                 & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_10_0);
    __Vtemp_74[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_10_0 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_4673;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__storeFirstNextWide_40[0U] = __Vtemp_76[0U];
    vlSelfRef.__PVT__storeFirstNextWide_40[1U] = __Vtemp_76[1U];
    vlSelfRef.__PVT__storeFirstNextWide_40[2U] = (1U 
                                                  & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_10_1);
    __Vtemp_78[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_10_1 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_4712;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__storeFirstNextWide_41[0U] = __Vtemp_80[0U];
    vlSelfRef.__PVT__storeFirstNextWide_41[1U] = __Vtemp_80[1U];
    vlSelfRef.__PVT__storeFirstNextWide_41[2U] = (1U 
                                                  & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_10_2);
    __Vtemp_82[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_10_2 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_4753;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.__PVT__storeFirstNextWide_42[0U] = __Vtemp_84[0U];
    vlSelfRef.__PVT__storeFirstNextWide_42[1U] = __Vtemp_84[1U];
    vlSelfRef.__PVT__storeFirstNextWide_42[2U] = (1U 
                                                  & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_10_3);
    __Vtemp_86[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_10_3 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_4794;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.__PVT__storeFirstNextWide_43[0U] = __Vtemp_88[0U];
    vlSelfRef.__PVT__storeFirstNextWide_43[1U] = __Vtemp_88[1U];
    vlSelfRef.__PVT__storeFirstNextWide_43[2U] = (1U 
                                                  & __Vtemp_88[2U]);
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
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__103(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__103\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_10_1);
    __Vtemp_2[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_10_1 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_48230;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__strictWriteReadNextWide_41[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_41[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_41[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_10_2);
    __Vtemp_6[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_10_2 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_48666;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__strictWriteReadNextWide_42[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_42[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_42[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_10_3);
    __Vtemp_10[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_10_3 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_49102;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__strictWriteReadNextWide_43[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_43[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_43[2U] 
        = (1U & __Vtemp_12[2U]);
    vlSelfRef.__PVT__allocate_10 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_10)) 
                                    & (IData)(vlSelfRef.__PVT__isCurrent_10));
    vlSelfRef.__PVT___GEN_930 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_10)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_10));
    vlSelfRef.__PVT___T_892 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_12) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_12)));
    __Vtemp_14[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_12_0);
    __Vtemp_14[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_12_0 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_5545;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__loadFirstNextWide_48[0U] = __Vtemp_16[0U];
    vlSelfRef.__PVT__loadFirstNextWide_48[1U] = __Vtemp_16[1U];
    vlSelfRef.__PVT__loadFirstNextWide_48[2U] = (1U 
                                                 & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_12_1);
    __Vtemp_18[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_12_1 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_5584;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__loadFirstNextWide_49[0U] = __Vtemp_20[0U];
    vlSelfRef.__PVT__loadFirstNextWide_49[1U] = __Vtemp_20[1U];
    vlSelfRef.__PVT__loadFirstNextWide_49[2U] = (1U 
                                                 & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_12_2);
    __Vtemp_22[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_12_2 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_5625;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__loadFirstNextWide_50[0U] = __Vtemp_24[0U];
    vlSelfRef.__PVT__loadFirstNextWide_50[1U] = __Vtemp_24[1U];
    vlSelfRef.__PVT__loadFirstNextWide_50[2U] = (1U 
                                                 & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_12_3);
    __Vtemp_26[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_12_3 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_5666;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__loadFirstNextWide_51[0U] = __Vtemp_28[0U];
    vlSelfRef.__PVT__loadFirstNextWide_51[1U] = __Vtemp_28[1U];
    vlSelfRef.__PVT__loadFirstNextWide_51[2U] = (1U 
                                                 & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_12_0);
    __Vtemp_30[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_12_0 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_5545;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__storeFirstNextWide_48[0U] = __Vtemp_32[0U];
    vlSelfRef.__PVT__storeFirstNextWide_48[1U] = __Vtemp_32[1U];
    vlSelfRef.__PVT__storeFirstNextWide_48[2U] = (1U 
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
    __Vtemp_38[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_12_2);
    __Vtemp_38[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_12_2 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_5625;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__storeFirstNextWide_50[0U] = __Vtemp_40[0U];
    vlSelfRef.__PVT__storeFirstNextWide_50[1U] = __Vtemp_40[1U];
    vlSelfRef.__PVT__storeFirstNextWide_50[2U] = (1U 
                                                  & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_12_3);
    __Vtemp_42[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_12_3 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_5666;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__storeFirstNextWide_51[0U] = __Vtemp_44[0U];
    vlSelfRef.__PVT__storeFirstNextWide_51[1U] = __Vtemp_44[1U];
    vlSelfRef.__PVT__storeFirstNextWide_51[2U] = (1U 
                                                  & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_12_0);
    __Vtemp_46[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_12_0 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56742;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__strictWriteReadNextWide_48[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_48[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_48[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_12_1);
    __Vtemp_50[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_12_1 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_57158;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__strictWriteReadNextWide_49[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_49[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_49[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_12_2);
    __Vtemp_54[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_12_2 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_57594;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__strictWriteReadNextWide_50[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_50[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_50[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_12_3);
    __Vtemp_58[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_12_3 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_58030;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__strictWriteReadNextWide_51[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_51[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_51[2U] 
        = (1U & __Vtemp_60[2U]);
    vlSelfRef.__PVT__allocate_12 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_12)) 
                                    & (IData)(vlSelfRef.__PVT__isCurrent_12));
    vlSelfRef.__PVT___GEN_1100 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_12)) 
                                  | (IData)(vlSelfRef.__PVT__bucketValid_12));
    vlSelfRef.io_currentCollision = (((IData)(vlSelfRef.__PVT__isCurrent) 
                                      & ((IData)(vlSelfRef.bucketValid_0) 
                                         & ((vlSelfRef.bucketSeq_0 
                                             >> 8U) 
                                            != (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                >> 8U)))) 
                                     | (((IData)(vlSelfRef.__PVT__isCurrent_1) 
                                         & ((IData)(vlSelfRef.__PVT__bucketValid_1) 
                                            & ((vlSelfRef.__PVT__bucketSeq_1 
                                                >> 8U) 
                                               != (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                   >> 8U)))) 
                                        | (((IData)(vlSelfRef.__PVT__isCurrent_2) 
                                            & ((IData)(vlSelfRef.__PVT__bucketValid_2) 
                                               & ((vlSelfRef.__PVT__bucketSeq_2 
                                                   >> 8U) 
                                                  != 
                                                  (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                   >> 8U)))) 
                                           | (((IData)(vlSelfRef.__PVT__isCurrent_3) 
                                               & ((IData)(vlSelfRef.__PVT__bucketValid_3) 
                                                  & ((vlSelfRef.__PVT__bucketSeq_3 
                                                      >> 8U) 
                                                     != 
                                                     (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                      >> 8U)))) 
                                              | (((IData)(vlSelfRef.__PVT__isCurrent_4) 
                                                  & ((IData)(vlSelfRef.__PVT__bucketValid_4) 
                                                     & ((vlSelfRef.__PVT__bucketSeq_4 
                                                         >> 8U) 
                                                        != 
                                                        (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                         >> 8U)))) 
                                                 | (((IData)(vlSelfRef.__PVT__isCurrent_5) 
                                                     & ((IData)(vlSelfRef.__PVT__bucketValid_5) 
                                                        & ((vlSelfRef.__PVT__bucketSeq_5 
                                                            >> 8U) 
                                                           != 
                                                           (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                            >> 8U)))) 
                                                    | (((IData)(vlSelfRef.__PVT__isCurrent_6) 
                                                        & ((IData)(vlSelfRef.__PVT__bucketValid_6) 
                                                           & ((vlSelfRef.__PVT__bucketSeq_6 
                                                               >> 8U) 
                                                              != 
                                                              (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                               >> 8U)))) 
                                                       | (((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                                           & ((IData)(vlSelfRef.__PVT__bucketValid_7) 
                                                              & ((vlSelfRef.__PVT__bucketSeq_7 
                                                                  >> 8U) 
                                                                 != 
                                                                 (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                                  >> 8U)))) 
                                                          | (((IData)(vlSelfRef.__PVT__isCurrent_8) 
                                                              & ((IData)(vlSelfRef.__PVT__bucketValid_8) 
                                                                 & ((vlSelfRef.__PVT__bucketSeq_8 
                                                                     >> 8U) 
                                                                    != 
                                                                    (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                                     >> 8U)))) 
                                                             | (((IData)(vlSelfRef.__PVT__isCurrent_9) 
                                                                 & ((IData)(vlSelfRef.__PVT__bucketValid_9) 
                                                                    & ((vlSelfRef.__PVT__bucketSeq_9 
                                                                        >> 8U) 
                                                                       != 
                                                                       (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                                        >> 8U)))) 
                                                                | (((IData)(vlSelfRef.__PVT__isCurrent_10) 
                                                                    & ((IData)(vlSelfRef.__PVT__bucketValid_10) 
                                                                       & ((vlSelfRef.__PVT__bucketSeq_10 
                                                                           >> 8U) 
                                                                          != 
                                                                          (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                                           >> 8U)))) 
                                                                   | (((IData)(vlSelfRef.__PVT__isCurrent_11) 
                                                                       & ((IData)(vlSelfRef.__PVT__bucketValid_11) 
                                                                          & ((vlSelfRef.__PVT__bucketSeq_11 
                                                                              >> 8U) 
                                                                             != 
                                                                             (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                                              >> 8U)))) 
                                                                      | (((IData)(vlSelfRef.__PVT__isCurrent_12) 
                                                                          & ((IData)(vlSelfRef.__PVT__bucketValid_12) 
                                                                             & ((vlSelfRef.__PVT__bucketSeq_12 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                         | (((IData)(vlSelfRef.__PVT__isCurrent_13) 
                                                                             & ((IData)(vlSelfRef.__PVT__bucketValid_13) 
                                                                                & ((vlSelfRef.__PVT__bucketSeq_13 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                            | (((IData)(vlSelfRef.__PVT__isCurrent_14) 
                                                                                & ((IData)(vlSelfRef.__PVT__bucketValid_14) 
                                                                                & ((vlSelfRef.__PVT__bucketSeq_14 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                               | ((IData)(vlSelfRef.__PVT__isCurrent_15) 
                                                                                & ((IData)(vlSelfRef.bucketValid_15) 
                                                                                & ((vlSelfRef.bucketSeq_15 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                                                >> 8U)))))))))))))))))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__105(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___nba_comb__TOP__tb__DOT__dut__DOT__reference_0__105\n"); );
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
    // Body
    __Vtemp_5[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                              ? vlSelfRef.buckets_requestCycleSum_0
                              : 0ULL));
    __Vtemp_5[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.buckets_requestCycleSum_0
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
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_7
                               : 0ULL));
    __Vtemp_28[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_7
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
                               ? vlSelfRef.buckets_requestCycleSum_15
                               : 0ULL));
    __Vtemp_64[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.buckets_requestCycleSum_15
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
    vlSelfRef.io_barrierResolvedRequest[0U] = __Vtemp_74[0U];
    vlSelfRef.io_barrierResolvedRequest[1U] = __Vtemp_74[1U];
    vlSelfRef.io_barrierResolvedRequest[2U] = (0xfU 
                                               & __Vtemp_74[2U]);
    vlSelfRef.__PVT___GEN_4371 = ((~ (IData)(vlSelfRef.__PVT__resolving_13)) 
                                  & (IData)(vlSelfRef.__PVT__buckets_valid_13));
    vlSelfRef.__PVT___canAccept_T_40 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_13)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_13)));
    vlSelfRef.io_retiringCollision = (((IData)(vlSelfRef.__PVT___io_retiringValid_T) 
                                       & ((vlSelfRef.bucketSeq_0 
                                           >> 8U) != 
                                          (vlSymsp->TOP.tb__DOT__io_retiringSeq 
                                           >> 8U))) 
                                      | (((IData)(vlSelfRef.__PVT___io_retiringValid_T_1) 
                                          & ((vlSelfRef.__PVT__bucketSeq_1 
                                              >> 8U) 
                                             != (vlSymsp->TOP.tb__DOT__io_retiringSeq 
                                                 >> 8U))) 
                                         | (((IData)(vlSelfRef.__PVT___io_retiringValid_T_2) 
                                             & ((vlSelfRef.__PVT__bucketSeq_2 
                                                 >> 8U) 
                                                != 
                                                (vlSymsp->TOP.tb__DOT__io_retiringSeq 
                                                 >> 8U))) 
                                            | (((IData)(vlSelfRef.__PVT___io_retiringValid_T_3) 
                                                & ((vlSelfRef.__PVT__bucketSeq_3 
                                                    >> 8U) 
                                                   != 
                                                   (vlSymsp->TOP.tb__DOT__io_retiringSeq 
                                                    >> 8U))) 
                                               | (((IData)(vlSelfRef.__PVT___io_retiringValid_T_4) 
                                                   & ((vlSelfRef.__PVT__bucketSeq_4 
                                                       >> 8U) 
                                                      != 
                                                      (vlSymsp->TOP.tb__DOT__io_retiringSeq 
                                                       >> 8U))) 
                                                  | (((IData)(vlSelfRef.__PVT___io_retiringValid_T_5) 
                                                      & ((vlSelfRef.__PVT__bucketSeq_5 
                                                          >> 8U) 
                                                         != 
                                                         (vlSymsp->TOP.tb__DOT__io_retiringSeq 
                                                          >> 8U))) 
                                                     | (((IData)(vlSelfRef.__PVT___io_retiringValid_T_6) 
                                                         & ((vlSelfRef.__PVT__bucketSeq_6 
                                                             >> 8U) 
                                                            != 
                                                            (vlSymsp->TOP.tb__DOT__io_retiringSeq 
                                                             >> 8U))) 
                                                        | (((IData)(vlSelfRef.__PVT___io_retiringValid_T_7) 
                                                            & ((vlSelfRef.__PVT__bucketSeq_7 
                                                                >> 8U) 
                                                               != 
                                                               (vlSymsp->TOP.tb__DOT__io_retiringSeq 
                                                                >> 8U))) 
                                                           | (((IData)(vlSelfRef.__PVT___io_retiringValid_T_8) 
                                                               & ((vlSelfRef.__PVT__bucketSeq_8 
                                                                   >> 8U) 
                                                                  != 
                                                                  (vlSymsp->TOP.tb__DOT__io_retiringSeq 
                                                                   >> 8U))) 
                                                              | (((IData)(vlSelfRef.__PVT___io_retiringValid_T_9) 
                                                                  & ((vlSelfRef.__PVT__bucketSeq_9 
                                                                      >> 8U) 
                                                                     != 
                                                                     (vlSymsp->TOP.tb__DOT__io_retiringSeq 
                                                                      >> 8U))) 
                                                                 | (((IData)(vlSelfRef.__PVT___io_retiringValid_T_10) 
                                                                     & ((vlSelfRef.__PVT__bucketSeq_10 
                                                                         >> 8U) 
                                                                        != 
                                                                        (vlSymsp->TOP.tb__DOT__io_retiringSeq 
                                                                         >> 8U))) 
                                                                    | (((IData)(vlSelfRef.__PVT___io_retiringValid_T_11) 
                                                                        & ((vlSelfRef.__PVT__bucketSeq_11 
                                                                            >> 8U) 
                                                                           != 
                                                                           (vlSymsp->TOP.tb__DOT__io_retiringSeq 
                                                                            >> 8U))) 
                                                                       | (((IData)(vlSelfRef.__PVT___io_retiringValid_T_12) 
                                                                           & ((vlSelfRef.__PVT__bucketSeq_12 
                                                                               >> 8U) 
                                                                              != 
                                                                              (vlSymsp->TOP.tb__DOT__io_retiringSeq 
                                                                               >> 8U))) 
                                                                          | (((IData)(vlSelfRef.__PVT___io_retiringValid_T_13) 
                                                                              & ((vlSelfRef.__PVT__bucketSeq_13 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSymsp->TOP.tb__DOT__io_retiringSeq 
                                                                                >> 8U))) 
                                                                             | (((IData)(vlSelfRef.__PVT___io_retiringValid_T_14) 
                                                                                & ((vlSelfRef.__PVT__bucketSeq_14 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSymsp->TOP.tb__DOT__io_retiringSeq 
                                                                                >> 8U))) 
                                                                                | ((IData)(vlSelfRef.__PVT___io_retiringValid_T_15) 
                                                                                & ((vlSelfRef.bucketSeq_15 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSymsp->TOP.tb__DOT__io_retiringSeq 
                                                                                >> 8U))))))))))))))))));
}
