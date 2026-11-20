// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__115(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__115\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_10_0);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_10_0 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_4673;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_40[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_40[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_40[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_10_1);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_10_1 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_4712;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_41[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_41[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_41[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_10_2);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_10_2 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_4753;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_42[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_42[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_42[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_10_3);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_10_3 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_4794;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_43[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_43[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_43[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_10_0);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_10_0 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_4673;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_40[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_40[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_40[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_10_1);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_10_1 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_4712;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_41[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_41[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_41[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_10_2);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_10_2 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_4753;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_42[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_42[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_42[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_10_3);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_10_3 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_4794;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_43[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_43[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_43[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_10_0);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_10_0 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_47814;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_40[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_40[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_40[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_10_1);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_10_1 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_48230;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_41[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_41[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_41[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_10_2);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_10_2 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_48666;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_42[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_42[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_42[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_10_3);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_10_3 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_49102;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_43[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_43[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_43[2U] 
        = (1U & __Vtemp_48[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_10 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_10));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_930 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_10)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_381 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_5) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)));
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_5_0);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_5_0 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_2493;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_20[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_20[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_20[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_5_1);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_5_1 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_2532;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_21[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_21[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_21[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_5_2);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_5_2 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_2573;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_22[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_22[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_22[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_5_3);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_5_3 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_2614;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_23[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_23[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_23[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_5_0);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_5_0 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2493;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_20[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_20[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_20[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_5_1);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_5_1 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2532;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_21[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_21[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_21[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_5_2);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_5_2 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2573;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_22[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_22[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_22[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_5_3);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_5_3 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2614;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_23[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_23[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_23[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_5_0);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_5_0 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_25494;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_20[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_20[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_20[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_5_1);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_5_1 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_25910;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_21[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_21[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_21[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_5_2);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_5_2 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_26346;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_22[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_22[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_22[2U] 
        = (1U & __Vtemp_92[2U]);
    __Vtemp_94[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_5_3);
    __Vtemp_94[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_5_3 
                              >> 0x20U));
    __Vtemp_94[2U] = 0U;
    __Vtemp_95[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_26782;
    __Vtemp_95[1U] = 0U;
    __Vtemp_95[2U] = 0U;
    VL_ADD_W(3, __Vtemp_96, __Vtemp_94, __Vtemp_95);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_23[0U] 
        = __Vtemp_96[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_23[1U] 
        = __Vtemp_96[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_23[2U] 
        = (1U & __Vtemp_96[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_5 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_5));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_505 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_5)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5));
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__116(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__116\n"); );
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
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_162 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_2) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)));
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_2_0);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_2_0 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_1185;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_8[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_8[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_8[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_2_1);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_2_1 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_1224;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_9[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_9[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_9[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_2_2);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_2_2 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_1265;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_10[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_10[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_10[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_2_3);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_2_3 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_1306;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_11[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_11[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_11[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_2_0);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_2_0 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_1185;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_8[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_8[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_8[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_2_1);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_2_1 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_1224;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_9[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_9[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_9[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_2_2);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_2_2 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_1265;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_10[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_10[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_10[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_2_3);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_2_3 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_1306;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_11[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_11[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_11[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_2_0);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_2_0 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_12102;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_8[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_8[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_8[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_2_1);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_2_1 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_12518;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_9[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_9[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_9[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_2_2);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_2_2 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_12954;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_10[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_10[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_10[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_2_3);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_2_3 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_13390;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_11[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_11[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_11[2U] 
        = (1U & __Vtemp_48[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_2 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_2));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_250 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_2)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_819 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_11) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)));
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_11_0);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_11_0 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_5109;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_44[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_44[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_44[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_11_1);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_11_1 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_5148;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_45[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_45[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_45[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_11_2);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_11_2 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_5189;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_46[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_46[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_46[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_11_3);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_11_3 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_5230;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_47[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_47[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_47[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_11_0);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_11_0 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5109;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_44[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_44[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_44[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_11_1);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_11_1 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5148;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_45[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_45[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_45[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_11_2);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_11_2 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5189;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_46[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_46[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_46[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_11_3);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_11_3 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5230;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_47[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_47[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_47[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_11_0);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_11_0 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_52278;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_44[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_44[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_44[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_11_1);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_11_1 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_52694;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_45[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_45[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_45[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_11_2);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_11_2 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_53130;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_46[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_46[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_46[2U] 
        = (1U & __Vtemp_92[2U]);
    __Vtemp_94[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_11_3);
    __Vtemp_94[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_11_3 
                              >> 0x20U));
    __Vtemp_94[2U] = 0U;
    __Vtemp_95[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_53566;
    __Vtemp_95[1U] = 0U;
    __Vtemp_95[2U] = 0U;
    VL_ADD_W(3, __Vtemp_96, __Vtemp_94, __Vtemp_95);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_47[0U] 
        = __Vtemp_96[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_47[1U] 
        = __Vtemp_96[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_47[2U] 
        = (1U & __Vtemp_96[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_11 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_11));
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__117(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__117\n"); );
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
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_1015 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_11)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_1549 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_21) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)));
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_21_0);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_21_0 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_9469;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_84[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_84[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_84[2U] 
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
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_21_2);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_21_2 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_9549;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_86[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_86[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_86[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_21_3);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_21_3 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_9590;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_87[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_87[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_87[2U] 
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
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_21_1);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_21_1 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9508;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_85[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_85[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_85[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_21_2);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_21_2 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9549;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_86[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_86[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_86[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_21_3);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_21_3 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9590;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_87[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_87[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_87[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_21_0);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_21_0 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_96918;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_84[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_84[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_84[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_21_1);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_21_1 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_97334;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_85[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_85[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_85[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_21_2);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_21_2 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_97770;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_86[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_86[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_86[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_21_3);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_21_3 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_98206;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_87[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_87[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_87[2U] 
        = (1U & __Vtemp_48[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_21 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_21));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_1865 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_21)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_527 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_7) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)));
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_7_0);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_7_0 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_3365;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_28[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_28[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_28[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_7_1);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_7_1 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_3404;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_29[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_29[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_29[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_7_2);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_7_2 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_3445;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_30[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_30[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_30[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_7_3);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_7_3 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_3486;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_31[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_31[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_31[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_7_0);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_7_0 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3365;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_28[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_28[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_28[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_7_1);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_7_1 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3404;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_29[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_29[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_29[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_7_2);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_7_2 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3445;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_30[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_30[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_30[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_7_3);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_7_3 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3486;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_31[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_31[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_31[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_7_0);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_7_0 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_34422;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_28[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_28[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_28[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_7_1);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_7_1 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_34838;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_29[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_29[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_29[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_7_2);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_7_2 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_35274;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_30[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_30[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_30[2U] 
        = (1U & __Vtemp_92[2U]);
    __Vtemp_94[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_7_3);
    __Vtemp_94[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_7_3 
                              >> 0x20U));
    __Vtemp_94[2U] = 0U;
    __Vtemp_95[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_35710;
    __Vtemp_95[1U] = 0U;
    __Vtemp_95[2U] = 0U;
    VL_ADD_W(3, __Vtemp_96, __Vtemp_94, __Vtemp_95);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_31[0U] 
        = __Vtemp_96[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_31[1U] 
        = __Vtemp_96[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_31[2U] 
        = (1U & __Vtemp_96[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__118(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__118\n"); );
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
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_7 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_7));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_675 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_7)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_673 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_9) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)));
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_9_0);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_9_0 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_4237;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_36[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_36[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_36[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_9_1);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_9_1 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_4276;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_37[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_37[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_37[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_9_2);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_9_2 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_4317;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_38[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_38[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_38[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_9_3);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_9_3 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_4358;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_39[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_39[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_39[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_9_0);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_9_0 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_4237;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_36[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_36[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_36[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_9_1);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_9_1 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_4276;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_37[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_37[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_37[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_9_2);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_9_2 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_4317;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_38[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_38[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_38[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_9_3);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_9_3 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_4358;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_39[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_39[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_39[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_9_0);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_9_0 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_43350;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_36[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_36[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_36[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_9_1);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_9_1 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_43766;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_37[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_37[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_37[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_9_2);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_9_2 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_44202;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_38[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_38[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_38[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_9_3);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_9_3 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_44638;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_39[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_39[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_39[2U] 
        = (1U & __Vtemp_48[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_9 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_9));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_845 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_9)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_892 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_12) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)));
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_12_0);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_12_0 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_5545;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_48[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_48[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_48[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_12_1);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_12_1 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_5584;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_49[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_49[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_49[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_12_2);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_12_2 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_5625;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_50[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_50[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_50[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_12_3);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_12_3 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_5666;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_51[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_51[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_51[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_12_0);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_12_0 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5545;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_48[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_48[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_48[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_12_1);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_12_1 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5584;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_49[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_49[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_49[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_12_2);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_12_2 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5625;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_50[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_50[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_50[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_12_3);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_12_3 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5666;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_51[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_51[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_51[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_12_0);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_12_0 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_56742;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_48[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_48[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_48[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_12_1);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_12_1 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_57158;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_49[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_49[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_49[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_12_2);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_12_2 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_57594;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_50[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_50[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_50[2U] 
        = (1U & __Vtemp_92[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__119(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__119\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_12_3);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_12_3 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_58030;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_51[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_51[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_51[2U] 
        = (1U & __Vtemp_4[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_12 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_12));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_1100 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_12)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_1038 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_14) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)));
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_14_0);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_14_0 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_6417;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_56[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_56[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_56[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_14_1);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_14_1 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_6456;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_57[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_57[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_57[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_14_2);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_14_2 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_6497;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_58[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_58[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_58[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_14_3);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_14_3 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_6538;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_59[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_59[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_59[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_14_0);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_14_0 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6417;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_56[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_56[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_56[2U] 
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
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_14_2);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_14_2 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6497;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_58[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_58[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_58[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_14_3);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_14_3 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6538;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_59[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_59[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_59[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_14_0);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_14_0 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_65670;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_56[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_56[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_56[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_14_1);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_14_1 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_66086;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_57[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_57[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_57[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_14_2);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_14_2 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_66522;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_58[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_58[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_58[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_14_3);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_14_3 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_66958;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_59[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_59[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_59[2U] 
        = (1U & __Vtemp_52[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_14 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_14));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_1270 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_14)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_1184 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_16) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)));
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_16_0);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_16_0 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_7289;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_64[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_64[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_64[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_16_1);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_16_1 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_7328;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_65[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_65[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_65[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_16_2);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_16_2 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_7369;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_66[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_66[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_66[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_16_3);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_16_3 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_7410;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_67[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_67[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_67[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_16_0);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_16_0 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_7289;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_64[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_64[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_64[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_16_1);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_16_1 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_7328;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_65[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_65[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_65[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_16_2);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_16_2 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_7369;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_66[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_66[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_66[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_16_3);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_16_3 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_7410;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_67[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_67[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_67[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_16_0);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_16_0 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_74598;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_64[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_64[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_64[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_16_1);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_16_1 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_75014;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_65[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_65[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_65[2U] 
        = (1U & __Vtemp_92[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__120(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__120\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_16_2);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_16_2 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_75450;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_66[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_66[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_66[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_16_3);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_16_3 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_75886;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_67[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_67[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_67[2U] 
        = (1U & __Vtemp_8[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_16 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_16));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_1440 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_16)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_1330 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_18) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)));
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_18_0);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_18_0 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_8161;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_72[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_72[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_72[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_18_1);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_18_1 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_8200;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_73[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_73[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_73[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_18_2);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_18_2 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_8241;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_74[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_74[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_74[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_18_3);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_18_3 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_8282;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_75[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_75[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_75[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_18_0);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_18_0 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_8161;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_72[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_72[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_72[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_18_1);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_18_1 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_8200;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_73[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_73[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_73[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_18_2);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_18_2 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_8241;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_74[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_74[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_74[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_18_3);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_18_3 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_8282;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_75[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_75[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_75[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_18_0);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_18_0 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_83526;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_72[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_72[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_72[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_18_1);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_18_1 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_83942;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_73[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_73[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_73[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_18_2);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_18_2 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_84378;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_74[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_74[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_74[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_18_3);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_18_3 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_84814;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_75[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_75[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_75[2U] 
        = (1U & __Vtemp_56[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_18 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_18));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_1610 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_18)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_2206 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_30) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)));
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_30_0);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_30_0 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_13393;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_120[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_120[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_120[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_30_1);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_30_1 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_13432;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_121[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_121[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_121[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_30_2);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_30_2 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_13473;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_122[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_122[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_122[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_30_3);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_30_3 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_13514;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_123[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_123[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_123[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_30_0);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_30_0 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13393;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_120[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_120[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_120[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_30_1);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_30_1 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13432;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_121[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_121[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_121[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_30_2);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_30_2 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13473;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_122[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_122[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_122[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_30_3);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_30_3 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13514;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_123[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_123[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_123[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_30_0);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_30_0 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_137094;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_120[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_120[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_120[2U] 
        = (1U & __Vtemp_92[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__121(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__121\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_30_1);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_30_1 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_137510;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_121[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_121[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_121[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_30_2);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_30_2 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_137946;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_122[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_122[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_122[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_30_3);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_30_3 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_138382;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_123[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_123[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_123[2U] 
        = (1U & __Vtemp_12[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_30 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_30));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_2630 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_30)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_965 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_13) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)));
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_13_0);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_13_0 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_5981;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_52[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_52[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_52[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_13_1);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_13_1 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_6020;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_53[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_53[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_53[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_13_2);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_13_2 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_6061;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_54[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_54[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_54[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_13_3);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_13_3 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_6102;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_55[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_55[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_55[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_13_0);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_13_0 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_5981;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_52[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_52[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_52[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_13_1);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_13_1 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6020;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_53[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_53[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_53[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_13_2);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_13_2 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6061;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_54[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_54[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_54[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_13_3);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_13_3 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6102;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_55[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_55[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_55[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_13_0);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_13_0 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_61206;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_52[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_52[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_52[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_13_1);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_13_1 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_61622;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_53[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_53[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_53[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_13_2);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_13_2 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_62058;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_54[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_54[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_54[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_13_3);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_13_3 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_62494;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_55[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_55[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_55[2U] 
        = (1U & __Vtemp_60[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_13 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_13));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_1185 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_13)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_1257 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_17) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)));
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_17_0);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_17_0 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_7725;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_68[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_68[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_68[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_17_1);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_17_1 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_7764;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_69[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_69[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_69[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_17_2);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_17_2 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_7805;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_70[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_70[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_70[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_17_3);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_17_3 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_7846;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_71[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_71[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_71[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_17_0);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_17_0 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_7725;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_68[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_68[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_68[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_17_1);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_17_1 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_7764;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_69[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_69[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_69[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_17_2);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_17_2 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_7805;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_70[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_70[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_70[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_17_3);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_17_3 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_7846;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_71[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_71[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_71[2U] 
        = (1U & __Vtemp_92[2U]);
}
