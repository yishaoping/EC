// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__122(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__122\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_17_0);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_17_0 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_79062;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_68[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_68[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_68[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_17_1);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_17_1 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_79478;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_69[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_69[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_69[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_17_2);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_17_2 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_79914;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_70[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_70[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_70[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_17_3);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_17_3 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_80350;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_71[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_71[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_71[2U] 
        = (1U & __Vtemp_16[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_17 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_17));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_1525 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_17)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_1476 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_20) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)));
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_20_0);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_20_0 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_9033;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_80[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_80[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_80[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_20_1);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_20_1 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_9072;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_81[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_81[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_81[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_20_2);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_20_2 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_9113;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_82[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_82[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_82[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_20_3);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_20_3 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_9154;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_83[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_83[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_83[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_20_0);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_20_0 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9033;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_80[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_80[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_80[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_20_1);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_20_1 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9072;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_81[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_81[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_81[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_20_2);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_20_2 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9113;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_82[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_82[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_82[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_20_3);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_20_3 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9154;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_83[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_83[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_83[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_20_0);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_20_0 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_92454;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_80[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_80[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_80[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_20_1);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_20_1 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_92870;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_81[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_81[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_81[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_20_2);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_20_2 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_93306;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_82[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_82[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_82[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_20_3);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_20_3 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_93742;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_83[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_83[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_83[2U] 
        = (1U & __Vtemp_64[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_20 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_20));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_1780 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_20)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_1768 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_24) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)));
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_24_0);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_24_0 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_10777;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_96[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_96[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_96[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_24_1);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_24_1 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_10816;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_97[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_97[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_97[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_24_2);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_24_2 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_10857;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_98[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_98[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_98[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_24_3);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_24_3 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_10898;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_99[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_99[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_99[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_24_0);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_24_0 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10777;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_96[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_96[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_96[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_24_1);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_24_1 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10816;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_97[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_97[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_97[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_24_2);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_24_2 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10857;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_98[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_98[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_98[2U] 
        = (1U & __Vtemp_92[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__123(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__123\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_24_3);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_24_3 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10898;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_99[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_99[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_99[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_24_0);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_24_0 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_110310;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_96[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_96[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_96[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_24_1);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_24_1 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_110726;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_97[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_97[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_97[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_24_2);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_24_2 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_111162;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_98[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_98[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_98[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_24_3);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_24_3 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_111598;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_99[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_99[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_99[2U] 
        = (1U & __Vtemp_20[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_24 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_24));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_2120 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_24)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_2060 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_28) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)));
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_28_0);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_28_0 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_12521;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_112[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_112[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_112[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_28_1);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_28_1 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_12560;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_113[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_113[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_113[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_28_2);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_28_2 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_12601;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_114[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_114[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_114[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_28_3);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_28_3 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_12642;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_115[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_115[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_115[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_28_0);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_28_0 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12521;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_112[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_112[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_112[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_28_1);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_28_1 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12560;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_113[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_113[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_113[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_28_2);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_28_2 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12601;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_114[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_114[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_114[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_28_3);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_28_3 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12642;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_115[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_115[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_115[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_28_0);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_28_0 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_128166;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_112[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_112[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_112[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_28_1);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_28_1 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_128582;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_113[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_113[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_113[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_28_2);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_28_2 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_129018;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_114[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_114[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_114[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_28_3);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_28_3 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_129454;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_115[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_115[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_115[2U] 
        = (1U & __Vtemp_68[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_28 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_28));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_2460 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_28)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_1695 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_23) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)));
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_23_0);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_23_0 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_10341;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_92[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_92[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_92[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_23_1);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_23_1 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_10380;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_93[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_93[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_93[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_23_2);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_23_2 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_10421;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_94[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_94[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_94[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_23_3);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_23_3 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_10462;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_95[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_95[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_95[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_23_0);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_23_0 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10341;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_92[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_92[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_92[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_23_1);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_23_1 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10380;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_93[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_93[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_93[2U] 
        = (1U & __Vtemp_92[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__124(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__124\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_23_2);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_23_2 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10421;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_94[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_94[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_94[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_23_3);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_23_3 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10462;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_95[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_95[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_95[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_23_0);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_23_0 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_105846;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_92[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_92[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_92[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_23_1);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_23_1 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_106262;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_93[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_93[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_93[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_23_2);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_23_2 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_106698;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_94[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_94[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_94[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_23_3);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_23_3 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_107134;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_95[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_95[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_95[2U] 
        = (1U & __Vtemp_24[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_23 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_23));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_2035 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_23)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_1841 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_25) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)));
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_25_0);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_25_0 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_11213;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_100[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_100[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_100[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_25_1);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_25_1 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_11252;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_101[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_101[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_101[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_25_2);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_25_2 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_11293;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_102[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_102[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_102[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_25_3);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_25_3 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_11334;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_103[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_103[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_103[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_25_0);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_25_0 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_11213;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_100[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_100[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_100[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_25_1);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_25_1 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_11252;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_101[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_101[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_101[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_25_2);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_25_2 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_11293;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_102[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_102[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_102[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_25_3);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_25_3 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_11334;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_103[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_103[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_103[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_25_0);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_25_0 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_114774;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_100[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_100[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_100[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_25_1);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_25_1 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_115190;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_101[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_101[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_101[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_25_2);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_25_2 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_115626;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_102[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_102[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_102[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_25_3);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_25_3 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_116062;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_103[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_103[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_103[2U] 
        = (1U & __Vtemp_72[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_25 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_25));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_2205 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_25)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_1987 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_27) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)));
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_27_0);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_27_0 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_12085;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_108[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_108[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_108[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_27_1);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_27_1 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_12124;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_109[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_109[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_109[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_27_2);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_27_2 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_12165;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_110[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_110[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_110[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_27_3);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_27_3 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_12206;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_111[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_111[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_111[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_27_0);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_27_0 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12085;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_108[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_108[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_108[2U] 
        = (1U & __Vtemp_92[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__125(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__125\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_27_1);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_27_1 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12124;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_109[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_109[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_109[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_27_2);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_27_2 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12165;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_110[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_110[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_110[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_27_3);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_27_3 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12206;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_111[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_111[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_111[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_27_0);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_27_0 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_123702;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_108[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_108[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_108[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_27_1);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_27_1 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_124118;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_109[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_109[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_109[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_27_2);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_27_2 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_124554;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_110[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_110[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_110[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_27_3);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_27_3 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_124990;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_111[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_111[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_111[2U] 
        = (1U & __Vtemp_28[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_27 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_27));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_2375 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_27)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_2133 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_29) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)));
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_29_0);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_29_0 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_12957;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_116[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_116[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_116[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_29_1);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_29_1 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_12996;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_117[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_117[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_117[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_29_2);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_29_2 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_13037;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_118[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_118[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_118[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_29_3);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_29_3 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_13078;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_119[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_119[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_119[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_29_0);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_29_0 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12957;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_116[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_116[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_116[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_29_1);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_29_1 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_12996;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_117[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_117[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_117[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_29_2);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_29_2 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13037;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_118[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_118[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_118[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_29_3);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_29_3 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13078;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_119[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_119[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_119[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_29_0);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_29_0 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_132630;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_116[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_116[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_116[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_29_1);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_29_1 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_133046;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_117[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_117[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_117[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_29_2);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_29_2 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_133482;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_118[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_118[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_118[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_29_3);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_29_3 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_133918;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_119[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_119[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_119[2U] 
        = (1U & __Vtemp_76[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_29 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_29));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_2545 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_29)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_2279 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_31) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)));
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_31_0);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_31_0 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_13829;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_124[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_124[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_124[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_31_1);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_31_1 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_13868;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_125[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_125[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_125[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_31_2);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_31_2 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_13909;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_126[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_126[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_126[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_31_3);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_31_3 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_13950;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_127[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_127[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_127[2U] 
        = (1U & __Vtemp_92[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__126(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__126\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_31_0);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_31_0 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13829;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_124[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_124[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_124[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_31_1);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_31_1 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13868;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_125[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_125[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_125[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_31_2);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_31_2 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13909;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_126[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_126[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_126[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_31_3);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_31_3 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_13950;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_127[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_127[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_127[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_31_0);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_31_0 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_141558;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_124[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_124[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_124[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_31_1);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_31_1 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_141974;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_125[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_125[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_125[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_31_2);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_31_2 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_142410;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_126[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_126[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_126[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_31_3);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_31_3 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_142846;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_127[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_127[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_127[2U] 
        = (1U & __Vtemp_32[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_31 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_31));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_2715 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_31)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_89 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_1) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)));
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_1_0);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_1_0 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_749;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_4[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_4[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_4[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_1_1);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_1_1 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_788;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_5[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_5[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_5[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_1_2);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_1_2 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_829;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_6[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_6[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_6[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_1_3);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_1_3 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_870;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_7[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_7[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_7[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_1_0);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_1_0 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_749;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_4[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_4[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_4[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_1_1);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_1_1 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_788;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_5[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_5[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_5[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_1_2);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_1_2 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_829;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_6[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_6[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_6[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_1_3);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_1_3 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_870;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_7[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_7[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_7[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_1_0);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_1_0 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_7638;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_4[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_4[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_4[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_1_1);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_1_1 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_8054;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_5[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_5[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_5[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_1_2);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_1_2 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_8490;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_6[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_6[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_6[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_1_3);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_1_3 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_8926;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_7[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_7[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_7[2U] 
        = (1U & __Vtemp_80[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_1 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_1));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_165 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_1)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_235 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_3) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)));
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_3_0);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_3_0 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_1621;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_12[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_12[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_12[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_3_1);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_3_1 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_1660;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_13[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_13[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_13[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_3_2);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_3_2 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_1701;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_14[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_14[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_14[2U] 
        = (1U & __Vtemp_92[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__127(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__127\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_3_3);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_3_3 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_1742;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_15[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_15[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_15[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_3_0);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_3_0 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_1621;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_12[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_12[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_12[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_3_1);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_3_1 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_1660;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_13[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_13[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_13[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_3_2);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_3_2 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_1701;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_14[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_14[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_14[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_3_3);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_3_3 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_1742;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_15[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_15[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_15[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_3_0);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_3_0 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_16566;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_12[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_12[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_12[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_3_1);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_3_1 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_16982;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_13[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_13[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_13[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_3_2);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_3_2 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_17418;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_14[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_14[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_14[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_3_3);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_3_3 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_17854;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_15[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_15[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_15[2U] 
        = (1U & __Vtemp_36[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_3 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_3));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_335 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_3)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_1111 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_15) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)));
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_15_0);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_15_0 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_6853;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_60[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_60[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_60[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_15_1);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_15_1 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_6892;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_61[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_61[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_61[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_15_2);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_15_2 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_6933;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_62[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_62[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_62[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_15_3);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_15_3 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_6974;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_63[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_63[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_63[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_15_0);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_15_0 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6853;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_60[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_60[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_60[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_15_1);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_15_1 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6892;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_61[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_61[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_61[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_15_2);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_15_2 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6933;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_62[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_62[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_62[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_15_3);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_15_3 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_6974;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_63[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_63[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_63[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_15_0);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_15_0 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_70134;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_60[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_60[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_60[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_15_1);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_15_1 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_70550;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_61[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_61[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_61[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_15_2);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_15_2 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_70986;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_62[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_62[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_62[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_15_3);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_15_3 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_71422;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_63[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_63[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_63[2U] 
        = (1U & __Vtemp_84[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_15 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_15));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_1355 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_15)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_1914 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_26) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)));
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_26_0);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_26_0 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_11649;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_104[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_104[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_104[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_26_1);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_26_1 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_11688;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_105[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_105[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_105[2U] 
        = (1U & __Vtemp_92[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__128(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__128\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_26_2);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_26_2 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_11729;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_106[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_106[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_106[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_26_3);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_26_3 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_11770;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_107[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_107[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_107[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_26_0);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_26_0 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_11649;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_104[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_104[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_104[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_26_1);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_26_1 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_11688;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_105[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_105[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_105[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_26_2);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_26_2 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_11729;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_106[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_106[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_106[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_26_3);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_26_3 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_11770;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_107[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_107[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_107[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_26_0);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_26_0 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_119238;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_104[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_104[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_104[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_26_1);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_26_1 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_119654;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_105[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_105[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_105[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_26_2);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_26_2 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_120090;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_106[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_106[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_106[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_26_3);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_26_3 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_120526;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_107[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_107[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_107[2U] 
        = (1U & __Vtemp_40[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_26 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_26));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_2290 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_26)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_16 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)));
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_0_0);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_0_0 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_313;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_0_1);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_0_1 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_352;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_1[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_1[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_1[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_0_2);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_0_2 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_393;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_2[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_2[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_2[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_0_3);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_0_3 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_434;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_3[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_3[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_3[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_0_0);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_0_0 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_313;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_0_1);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_0_1 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_352;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_1[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_1[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_1[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_0_2);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_0_2 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_393;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_2[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_2[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_2[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_0_3);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_0_3 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_434;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_3[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_3[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_3[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_0_0);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_0_0 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_3174;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_0_1);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_0_1 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_3590;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_1[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_1[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_1[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_0_2);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_0_2 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_4026;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_2[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_2[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_2[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_0_3);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_0_3 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_4462;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_3[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_3[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_3[2U] 
        = (1U & __Vtemp_88[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_80 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0_io_currentCollision 
        = (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent) 
            & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0) 
               & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_0 
                   >> 8U) != (vlSelfRef.tb__DOT__io_processSeq 
                              >> 8U)))) | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_1) 
                                            & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1) 
                                               & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_1 
                                                   >> 8U) 
                                                  != 
                                                  (vlSelfRef.tb__DOT__io_processSeq 
                                                   >> 8U)))) 
                                           | ((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_2) 
                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2) 
                                                   & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_2 
                                                       >> 8U) 
                                                      != 
                                                      (vlSelfRef.tb__DOT__io_processSeq 
                                                       >> 8U)))) 
                                               | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_3) 
                                                   & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3) 
                                                      & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_3 
                                                          >> 8U) 
                                                         != 
                                                         (vlSelfRef.tb__DOT__io_processSeq 
                                                          >> 8U)))) 
                                                  | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_4) 
                                                      & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4) 
                                                         & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_4 
                                                             >> 8U) 
                                                            != 
                                                            (vlSelfRef.tb__DOT__io_processSeq 
                                                             >> 8U)))) 
                                                     | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_5) 
                                                         & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5) 
                                                            & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_5 
                                                                >> 8U) 
                                                               != 
                                                               (vlSelfRef.tb__DOT__io_processSeq 
                                                                >> 8U)))) 
                                                        | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_6) 
                                                            & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6) 
                                                               & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_6 
                                                                   >> 8U) 
                                                                  != 
                                                                  (vlSelfRef.tb__DOT__io_processSeq 
                                                                   >> 8U)))) 
                                                           | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_7) 
                                                               & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7) 
                                                                  & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_7 
                                                                      >> 8U) 
                                                                     != 
                                                                     (vlSelfRef.tb__DOT__io_processSeq 
                                                                      >> 8U)))) 
                                                              | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_8) 
                                                                  & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8) 
                                                                     & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_8 
                                                                         >> 8U) 
                                                                        != 
                                                                        (vlSelfRef.tb__DOT__io_processSeq 
                                                                         >> 8U)))) 
                                                                 | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_9) 
                                                                     & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9) 
                                                                        & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_9 
                                                                            >> 8U) 
                                                                           != 
                                                                           (vlSelfRef.tb__DOT__io_processSeq 
                                                                            >> 8U)))) 
                                                                    | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_10) 
                                                                        & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10) 
                                                                           & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_10 
                                                                               >> 8U) 
                                                                              != 
                                                                              (vlSelfRef.tb__DOT__io_processSeq 
                                                                               >> 8U)))) 
                                                                       | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_11) 
                                                                           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11) 
                                                                              & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_11 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                          | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_12) 
                                                                              & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_12 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                             | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_13) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_13 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                                | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_14) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_14 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                                | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_15) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_15 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                                | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_16) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_16 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                                | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_17) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_17 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                                | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_18) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_18 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                                | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_19) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_19 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                                | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_20) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_20 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                                | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_21) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_21 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                                | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_22) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_22 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                                | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_23) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_23 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                                | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_24) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_24 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                                | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_25) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_25 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                                | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_26) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_26 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                                | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_27) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_27 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                                | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_28) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_28 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                                | (((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_29) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_29 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))) 
                                                                                | ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_30) 
                                                                                & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30) 
                                                                                & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_30 
                                                                                >> 8U) 
                                                                                != 
                                                                                (vlSelfRef.tb__DOT__io_processSeq 
                                                                                >> 8U)))))))))))))))))))))))))))))))) 
                                              | ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_31) 
                                                 & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31) 
                                                    & ((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_31 
                                                        >> 8U) 
                                                       != 
                                                       (vlSelfRef.tb__DOT__io_processSeq 
                                                        >> 8U)))))));
}
