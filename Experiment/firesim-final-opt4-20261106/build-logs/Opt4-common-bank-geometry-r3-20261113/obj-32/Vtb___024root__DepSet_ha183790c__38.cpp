// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__20(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__20\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_2
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_2
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_114[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_114[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_114[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_3
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_3
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_115[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_115[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_115[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_28_0
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_28_0
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_112[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_112[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_112[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_28_1
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_28_1
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_113[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_113[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_113[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_28_2
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_28_2
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_114[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_114[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_114[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_28_3
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_28_3
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_115[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_115[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_115[2U] 
        = (1U & __Vtemp_24[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_28 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_28) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28));
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_23_0
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_23_0
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_92[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_92[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_92[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_23_1
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_23_1
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_93[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_93[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_93[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_23_2
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_23_2
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_94[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_94[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_94[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_23_3
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_23_3
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_95[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_95[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_95[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_23_0
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_23_0
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_92[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_92[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_92[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_23_1
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_23_1
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_93[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_93[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_93[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_23_2
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_23_2
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_94[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_94[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_94[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_23_3
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_23_3
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_95[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_95[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_95[2U] 
        = (1U & __Vtemp_56[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_23 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_23) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23));
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_0
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_0
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_100[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_100[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_100[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_1
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_1
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_101[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_101[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_101[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_2
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_2
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_102[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_102[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_102[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_3
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_3
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_103[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_103[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_103[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_25_0
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_25_0
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_100[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_100[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_100[2U] 
        = (1U & __Vtemp_76[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__21(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__21\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_25_1
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_25_1
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_101[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_101[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_101[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_25_2
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_25_2
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_102[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_102[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_102[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_25_3
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_25_3
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_103[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_103[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_103[2U] 
        = (1U & __Vtemp_12[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_25 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_25) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25));
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_0
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_0
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_108[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_108[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_108[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_1
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_1
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_109[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_109[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_109[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_2
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_2
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_110[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_110[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_110[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_3
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_3
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_111[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_111[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_111[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_27_0
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_27_0
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_108[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_108[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_108[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_27_1
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_27_1
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_109[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_109[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_109[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_27_2
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_27_2
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_110[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_110[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_110[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_27_3
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_27_3
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_111[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_111[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_111[2U] 
        = (1U & __Vtemp_44[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_27 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_27) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27));
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_0
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_0
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_116[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_116[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_116[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_1
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_1
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_117[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_117[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_117[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_2
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_2
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_118[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_118[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_118[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_3
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_3
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_119[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_119[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_119[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_29_0
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_29_0
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_116[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_116[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_116[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_29_1
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_29_1
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_117[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_117[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_117[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_29_2
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_29_2
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_118[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_118[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_118[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_29_3
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_29_3
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_119[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_119[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_119[2U] 
        = (1U & __Vtemp_76[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__22(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__22\n"); );
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
    // Body
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_29 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_29) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29));
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_124[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_124[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_124[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_125[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_125[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_125[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_126[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_126[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_126[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_127[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_127[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_127[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_31_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_31_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_124[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_124[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_124[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_31_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_31_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_125[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_125[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_125[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_31_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_31_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_126[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_126[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_126[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_31_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_31_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_127[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_127[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_127[2U] 
        = (1U & __Vtemp_32[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_31 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_31) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31));
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_1_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_1_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_4[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_4[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_4[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_1_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_1_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_5[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_5[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_5[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_1_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_1_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_6[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_6[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_6[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_1_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_1_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_7[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_7[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_7[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_1_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_1_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_4[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_4[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_4[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_1_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_1_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_5[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_5[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_5[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_1_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_1_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_6[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_6[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_6[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_1_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_1_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_7[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_7[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_7[2U] 
        = (1U & __Vtemp_64[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_1 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_1) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1));
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_3_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_3_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_12[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_12[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_12[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_3_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_3_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_13[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_13[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_13[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_3_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_3_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_14[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_14[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_14[2U] 
        = (1U & __Vtemp_76[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__23(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__23\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_3_3
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_3_3
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_15[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_15[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_15[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_3_0
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_3_0
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_12[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_12[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_12[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_3_1
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_3_1
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_13[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_13[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_13[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_3_2
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_3_2
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_14[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_14[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_14[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_3_3
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_3_3
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_15[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_15[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_15[2U] 
        = (1U & __Vtemp_20[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_3 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_3) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3));
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_15_0
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_15_0
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_60[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_60[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_60[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_15_1
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_15_1
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_61[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_61[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_61[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_15_2
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_15_2
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_62[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_62[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_62[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_15_3
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_15_3
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_63[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_63[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_63[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_15_0
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_15_0
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_60[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_60[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_60[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_15_1
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_15_1
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_61[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_61[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_61[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_15_2
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_15_2
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_62[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_62[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_62[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_15_3
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_15_3
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_63[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_63[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_63[2U] 
        = (1U & __Vtemp_52[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_15 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_15) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15));
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_0
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_0
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_104[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_104[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_104[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_1
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_1
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_105[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_105[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_105[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_2
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_2
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_106[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_106[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_106[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_3
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_3
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_107[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_107[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_107[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_26_0
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_26_0
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_104[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_104[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_104[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_26_1
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_26_1
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_105[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_105[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_105[2U] 
        = (1U & __Vtemp_76[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__24(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__24\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_26_2
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_26_2
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_106[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_106[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_106[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_26_3
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_26_3
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_107[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_107[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_107[2U] 
        = (1U & __Vtemp_8[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_26 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_26) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0_io_queryMatch_87 
        = (IData)(((0U == (0xe0U & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset))) 
                   & (((0x1fU == (0x1fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                        ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                        : ((0x1eU == (0x1fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                            ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                            : ((0x1dU == (0x1fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                : ((0x1cU == (0x1fU 
                                              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                    ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                    : ((0x1bU == (0x1fU 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                        ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                        : ((0x1aU == 
                                            (0x1fU 
                                             & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                            ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                            : ((0x19U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                                                : (
                                                   (0x18U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                    ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                                                    : 
                                                   ((0x17U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                     ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                                                     : 
                                                    ((0x16U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                      ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                                                      : 
                                                     ((0x15U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                       ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                                                       : 
                                                      ((0x14U 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                        ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                                                        : 
                                                       ((0x13U 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                         ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                                                         : 
                                                        ((0x12U 
                                                          == 
                                                          (0x1fU 
                                                           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                          ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                                                          : 
                                                         ((0x11U 
                                                           == 
                                                           (0x1fU 
                                                            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                           ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                                                           : 
                                                          ((0x10U 
                                                            == 
                                                            (0x1fU 
                                                             & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                            ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                                                            : 
                                                           ((0xfU 
                                                             == 
                                                             (0x1fU 
                                                              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                             ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                                             : 
                                                            ((0xeU 
                                                              == 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                              ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                                                              : 
                                                             ((0xdU 
                                                               == 
                                                               (0x1fU 
                                                                & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                               ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                                                               : 
                                                              ((0xcU 
                                                                == 
                                                                (0x1fU 
                                                                 & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                                                                : 
                                                               ((0xbU 
                                                                 == 
                                                                 (0x1fU 
                                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                 ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                                                 : 
                                                                ((0xaU 
                                                                  == 
                                                                  (0x1fU 
                                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                  ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                                                  : 
                                                                 ((9U 
                                                                   == 
                                                                   (0x1fU 
                                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                   ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                                                                   : 
                                                                  ((8U 
                                                                    == 
                                                                    (0x1fU 
                                                                     & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                    ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                                                                    : 
                                                                   ((7U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                     ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                                                                     : 
                                                                    ((6U 
                                                                      == 
                                                                      (0x1fU 
                                                                       & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                      ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                                                      : 
                                                                     ((5U 
                                                                       == 
                                                                       (0x1fU 
                                                                        & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                       ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                                                       : 
                                                                      ((4U 
                                                                        == 
                                                                        (0x1fU 
                                                                         & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                        ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                                                                        : 
                                                                       ((3U 
                                                                         == 
                                                                         (0x1fU 
                                                                          & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                         ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                                                                         : 
                                                                        ((2U 
                                                                          == 
                                                                          (0x1fU 
                                                                           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                          ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                                                                          : 
                                                                         ((1U 
                                                                           == 
                                                                           (0x1fU 
                                                                            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                           ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                                                           : (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)))))))))))))))))))))))))))))))) 
                      & ((((0x1fU == (0x1fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                            ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_31
                            : ((0x1eU == (0x1fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_30
                                : ((0x1dU == (0x1fU 
                                              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                    ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_29
                                    : ((0x1cU == (0x1fU 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                        ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_28
                                        : ((0x1bU == 
                                            (0x1fU 
                                             & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                            ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_27
                                            : ((0x1aU 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_26
                                                : (
                                                   (0x19U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                    ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_25
                                                    : 
                                                   ((0x18U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                     ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_24
                                                     : 
                                                    ((0x17U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                      ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_23
                                                      : 
                                                     ((0x16U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                       ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_22
                                                       : 
                                                      ((0x15U 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                        ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_21
                                                        : 
                                                       ((0x14U 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                         ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_20
                                                         : 
                                                        ((0x13U 
                                                          == 
                                                          (0x1fU 
                                                           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                          ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_19
                                                          : 
                                                         ((0x12U 
                                                           == 
                                                           (0x1fU 
                                                            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                           ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_18
                                                           : 
                                                          ((0x11U 
                                                            == 
                                                            (0x1fU 
                                                             & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                            ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_17
                                                            : 
                                                           ((0x10U 
                                                             == 
                                                             (0x1fU 
                                                              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                             ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_16
                                                             : 
                                                            ((0xfU 
                                                              == 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_15
                                                              : 
                                                             ((0xeU 
                                                               == 
                                                               (0x1fU 
                                                                & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_14
                                                               : 
                                                              ((0xdU 
                                                                == 
                                                                (0x1fU 
                                                                 & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_13
                                                                : 
                                                               ((0xcU 
                                                                 == 
                                                                 (0x1fU 
                                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                 ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_12
                                                                 : 
                                                                ((0xbU 
                                                                  == 
                                                                  (0x1fU 
                                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                  ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_11
                                                                  : 
                                                                 ((0xaU 
                                                                   == 
                                                                   (0x1fU 
                                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                   ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_10
                                                                   : 
                                                                  ((9U 
                                                                    == 
                                                                    (0x1fU 
                                                                     & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                    ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_9
                                                                    : 
                                                                   ((8U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                     ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_8
                                                                     : 
                                                                    ((7U 
                                                                      == 
                                                                      (0x1fU 
                                                                       & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                      ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_7
                                                                      : 
                                                                     ((6U 
                                                                       == 
                                                                       (0x1fU 
                                                                        & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                       ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_6
                                                                       : 
                                                                      ((5U 
                                                                        == 
                                                                        (0x1fU 
                                                                         & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                        ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_5
                                                                        : 
                                                                       ((4U 
                                                                         == 
                                                                         (0x1fU 
                                                                          & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                         ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_4
                                                                         : 
                                                                        ((3U 
                                                                          == 
                                                                          (0x1fU 
                                                                           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                          ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_3
                                                                          : 
                                                                         ((2U 
                                                                           == 
                                                                           (0x1fU 
                                                                            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                           ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_2
                                                                           : 
                                                                          ((1U 
                                                                            == 
                                                                            (0x1fU 
                                                                             & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_87_offset)))
                                                                            ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_1
                                                                            : vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_0))))))))))))))))))))))))))))))) 
                          >> 8U) == (vlSelfRef.tb__DOT__io_querySeq_87 
                                     >> 8U)))));
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__111(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__111\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb__DOT__dut__DOT__candidate_0_io_queryMatch_0 
        = (IData)(((0U == (0xe0U & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset))) 
                   & (((0x1fU == (0x1fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                        ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                        : ((0x1eU == (0x1fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                            ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                            : ((0x1dU == (0x1fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                : ((0x1cU == (0x1fU 
                                              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                    ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                    : ((0x1bU == (0x1fU 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                        ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                        : ((0x1aU == 
                                            (0x1fU 
                                             & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                            ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                            : ((0x19U 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                                                : (
                                                   (0x18U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                    ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                                                    : 
                                                   ((0x17U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                     ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                                                     : 
                                                    ((0x16U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                      ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                                                      : 
                                                     ((0x15U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                       ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                                                       : 
                                                      ((0x14U 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                        ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                                                        : 
                                                       ((0x13U 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                         ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                                                         : 
                                                        ((0x12U 
                                                          == 
                                                          (0x1fU 
                                                           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                          ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                                                          : 
                                                         ((0x11U 
                                                           == 
                                                           (0x1fU 
                                                            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                           ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                                                           : 
                                                          ((0x10U 
                                                            == 
                                                            (0x1fU 
                                                             & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                            ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                                                            : 
                                                           ((0xfU 
                                                             == 
                                                             (0x1fU 
                                                              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                             ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                                             : 
                                                            ((0xeU 
                                                              == 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                              ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                                                              : 
                                                             ((0xdU 
                                                               == 
                                                               (0x1fU 
                                                                & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                               ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                                                               : 
                                                              ((0xcU 
                                                                == 
                                                                (0x1fU 
                                                                 & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                                                                : 
                                                               ((0xbU 
                                                                 == 
                                                                 (0x1fU 
                                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                 ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                                                 : 
                                                                ((0xaU 
                                                                  == 
                                                                  (0x1fU 
                                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                  ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                                                  : 
                                                                 ((9U 
                                                                   == 
                                                                   (0x1fU 
                                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                   ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                                                                   : 
                                                                  ((8U 
                                                                    == 
                                                                    (0x1fU 
                                                                     & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                    ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                                                                    : 
                                                                   ((7U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                     ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                                                                     : 
                                                                    ((6U 
                                                                      == 
                                                                      (0x1fU 
                                                                       & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                      ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                                                      : 
                                                                     ((5U 
                                                                       == 
                                                                       (0x1fU 
                                                                        & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                       ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                                                       : 
                                                                      ((4U 
                                                                        == 
                                                                        (0x1fU 
                                                                         & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                        ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                                                                        : 
                                                                       ((3U 
                                                                         == 
                                                                         (0x1fU 
                                                                          & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                         ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                                                                         : 
                                                                        ((2U 
                                                                          == 
                                                                          (0x1fU 
                                                                           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                          ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                                                                          : 
                                                                         ((1U 
                                                                           == 
                                                                           (0x1fU 
                                                                            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                           ? (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                                                           : (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)))))))))))))))))))))))))))))))) 
                      & ((((0x1fU == (0x1fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                            ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_31
                            : ((0x1eU == (0x1fU & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_30
                                : ((0x1dU == (0x1fU 
                                              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                    ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_29
                                    : ((0x1cU == (0x1fU 
                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                        ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_28
                                        : ((0x1bU == 
                                            (0x1fU 
                                             & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                            ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_27
                                            : ((0x1aU 
                                                == 
                                                (0x1fU 
                                                 & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_26
                                                : (
                                                   (0x19U 
                                                    == 
                                                    (0x1fU 
                                                     & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                    ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_25
                                                    : 
                                                   ((0x18U 
                                                     == 
                                                     (0x1fU 
                                                      & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                     ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_24
                                                     : 
                                                    ((0x17U 
                                                      == 
                                                      (0x1fU 
                                                       & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                      ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_23
                                                      : 
                                                     ((0x16U 
                                                       == 
                                                       (0x1fU 
                                                        & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                       ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_22
                                                       : 
                                                      ((0x15U 
                                                        == 
                                                        (0x1fU 
                                                         & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                        ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_21
                                                        : 
                                                       ((0x14U 
                                                         == 
                                                         (0x1fU 
                                                          & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                         ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_20
                                                         : 
                                                        ((0x13U 
                                                          == 
                                                          (0x1fU 
                                                           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                          ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_19
                                                          : 
                                                         ((0x12U 
                                                           == 
                                                           (0x1fU 
                                                            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                           ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_18
                                                           : 
                                                          ((0x11U 
                                                            == 
                                                            (0x1fU 
                                                             & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                            ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_17
                                                            : 
                                                           ((0x10U 
                                                             == 
                                                             (0x1fU 
                                                              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                             ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_16
                                                             : 
                                                            ((0xfU 
                                                              == 
                                                              (0x1fU 
                                                               & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_15
                                                              : 
                                                             ((0xeU 
                                                               == 
                                                               (0x1fU 
                                                                & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_14
                                                               : 
                                                              ((0xdU 
                                                                == 
                                                                (0x1fU 
                                                                 & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_13
                                                                : 
                                                               ((0xcU 
                                                                 == 
                                                                 (0x1fU 
                                                                  & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                 ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_12
                                                                 : 
                                                                ((0xbU 
                                                                  == 
                                                                  (0x1fU 
                                                                   & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                  ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_11
                                                                  : 
                                                                 ((0xaU 
                                                                   == 
                                                                   (0x1fU 
                                                                    & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                   ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_10
                                                                   : 
                                                                  ((9U 
                                                                    == 
                                                                    (0x1fU 
                                                                     & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                    ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_9
                                                                    : 
                                                                   ((8U 
                                                                     == 
                                                                     (0x1fU 
                                                                      & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                     ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_8
                                                                     : 
                                                                    ((7U 
                                                                      == 
                                                                      (0x1fU 
                                                                       & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                      ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_7
                                                                      : 
                                                                     ((6U 
                                                                       == 
                                                                       (0x1fU 
                                                                        & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                       ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_6
                                                                       : 
                                                                      ((5U 
                                                                        == 
                                                                        (0x1fU 
                                                                         & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                        ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_5
                                                                        : 
                                                                       ((4U 
                                                                         == 
                                                                         (0x1fU 
                                                                          & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                         ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_4
                                                                         : 
                                                                        ((3U 
                                                                          == 
                                                                          (0x1fU 
                                                                           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                          ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_3
                                                                          : 
                                                                         ((2U 
                                                                           == 
                                                                           (0x1fU 
                                                                            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                           ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_2
                                                                           : 
                                                                          ((1U 
                                                                            == 
                                                                            (0x1fU 
                                                                             & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__io_queryMatch_0_offset)))
                                                                            ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_1
                                                                            : vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketSeq_0))))))))))))))))))))))))))))))) 
                          >> 8U) == (vlSelfRef.tb__DOT__io_querySeq_0 
                                     >> 8U)))));
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__112(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__112\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_0_1
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_0_1
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_1[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_1[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_1[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_0_2
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_0_2
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_2[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_2[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_2[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_0_3
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_0_3
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_3[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_3[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_3[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_0_0
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_0_0
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_0_1
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_0_1
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_1[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_1[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_1[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_0_2
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_0_2
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_2[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_2[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_2[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_0_3
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_0_3
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_3[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_3[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_3[2U] 
        = (1U & __Vtemp_28[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_0) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_1622 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_22) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)));
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_22_0);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_22_0 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_9905;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_88[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_88[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_88[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_22_1);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_22_1 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_9944;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_89[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_89[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_89[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_22_2);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_22_2 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_9985;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_90[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_90[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_90[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_22_3);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_22_3 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_10026;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_91[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_91[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_91[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_22_0);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_22_0 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9905;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_88[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_88[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_88[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_22_1);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_22_1 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9944;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_89[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_89[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_89[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_22_2);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_22_2 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_9985;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_90[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_90[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_90[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_22_3);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_22_3 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_10026;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_91[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_91[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_91[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_22_0);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_22_0 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_101382;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_88[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_88[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_88[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_22_1);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_22_1 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_101798;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_89[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_89[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_89[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_22_2);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_22_2 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_102234;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_90[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_90[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_90[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_22_3);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_22_3 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_102670;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_91[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_91[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_91[2U] 
        = (1U & __Vtemp_76[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_22 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_22));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_1950 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_22)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_1403 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_19) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)));
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_19_0);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_19_0 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_8597;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_76[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_76[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_76[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_19_1);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_19_1 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_8636;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_77[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_77[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_77[2U] 
        = (1U & __Vtemp_84[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__113(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__113\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_19_2);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_19_2 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_8677;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_78[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_78[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_78[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_19_3);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_19_3 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_8718;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_79[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_79[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_79[2U] 
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
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_19_1);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_19_1 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_8636;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_77[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_77[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_77[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_19_2);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_19_2 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_8677;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_78[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_78[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_78[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_19_3);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_19_3 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_8718;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_79[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_79[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_79[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_19_0);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_19_0 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_87990;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_76[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_76[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_76[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_19_1);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_19_1 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_88406;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_77[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_77[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_77[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_19_2);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_19_2 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_88842;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_78[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_78[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_78[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_19_3);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_19_3 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_89278;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_79[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_79[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_79[2U] 
        = (1U & __Vtemp_40[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_19 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_19));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_1695 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_19)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_600 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_8) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)));
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_8_0);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_8_0 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_3801;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_32[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_32[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_32[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_8_1);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_8_1 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_3840;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_33[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_33[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_33[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_8_2);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_8_2 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_3881;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_34[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_34[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_34[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_8_3);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_8_3 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_3922;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_35[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_35[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_35[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_8_0);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_8_0 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3801;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_32[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_32[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_32[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_8_1);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_8_1 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3840;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_33[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_33[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_33[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_8_2);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_8_2 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3881;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_34[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_34[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_34[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_8_3);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_8_3 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3922;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_35[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_35[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_35[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_8_0);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_8_0 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_38886;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_32[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_32[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_32[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_8_1);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_8_1 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_39302;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_33[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_33[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_33[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_8_2);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_8_2 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_39738;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_34[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_34[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_34[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_8_3);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_8_3 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_40174;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_35[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_35[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_35[2U] 
        = (1U & __Vtemp_88[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_8 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_8));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_760 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_8)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_454 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_6) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)));
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_6_0);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_6_0 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_2929;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_24[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_24[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_24[2U] 
        = (1U & __Vtemp_92[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__114(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__114\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_6_1);
    __Vtemp_2[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_6_1 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_2968;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_25[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_25[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_25[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_6_2);
    __Vtemp_6[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_6_2 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_3009;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_26[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_26[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_26[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_6_3);
    __Vtemp_10[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_6_3 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_3050;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_27[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_27[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_27[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_6_0);
    __Vtemp_14[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_6_0 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2929;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_24[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_24[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_24[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_6_1);
    __Vtemp_18[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_6_1 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2968;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_25[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_25[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_25[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_6_2);
    __Vtemp_22[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_6_2 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3009;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_26[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_26[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_26[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_6_3);
    __Vtemp_26[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_6_3 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_3050;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_27[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_27[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_27[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_6_0);
    __Vtemp_30[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_6_0 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_29958;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_24[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_24[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_24[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_6_1);
    __Vtemp_34[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_6_1 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_30374;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_25[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_25[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_25[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_6_2);
    __Vtemp_38[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_6_2 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_30810;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_26[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_26[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_26[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_6_3);
    __Vtemp_42[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_6_3 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_31246;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_27[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_27[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_27[2U] 
        = (1U & __Vtemp_44[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_6 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_6));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_590 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_6)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_308 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_4) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)));
    __Vtemp_46[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_4_0);
    __Vtemp_46[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_4_0 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_2057;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_16[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_16[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_16[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_4_1);
    __Vtemp_50[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_4_1 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_2096;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_17[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_17[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_17[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_4_2);
    __Vtemp_54[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_4_2 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_2137;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_18[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_18[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_18[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_4_3);
    __Vtemp_58[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketLoadFirst_4_3 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketLoadFirstDelta_T_2178;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_19[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_19[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__loadFirstNextWide_19[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_4_0);
    __Vtemp_62[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_4_0 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2057;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_16[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_16[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_16[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_4_1);
    __Vtemp_66[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_4_1 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2096;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_17[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_17[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_17[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_4_2);
    __Vtemp_70[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_4_2 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2137;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_18[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_18[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_18[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_4_3);
    __Vtemp_74[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStoreFirst_4_3 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStoreFirstDelta_T_2178;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_19[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_19[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__storeFirstNextWide_19[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_4_0);
    __Vtemp_78[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_4_0 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_21030;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_16[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_16[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_16[2U] 
        = (1U & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_4_1);
    __Vtemp_82[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_4_1 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_21446;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_17[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_17[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_17[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_4_2);
    __Vtemp_86[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_4_2 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_21882;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_18[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_18[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_18[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_4_3);
    __Vtemp_90[1U] = (IData)((vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStrictWriteRead_4_3 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___bucketStrictWriteReadDelta_T_22318;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_19[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_19[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__strictWriteReadNextWide_19[2U] 
        = (1U & __Vtemp_92[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__allocate_4 
        = ((~ (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_4));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___GEN_420 
        = (((IData)(vlSelfRef.tb__DOT__io_processCommit) 
            & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isCurrent_4)) 
           | (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4));
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___T_746 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT____VdfgRegularize_h883887c0_0_2770) 
           & ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__isRetiring_10) 
              & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)));
}
