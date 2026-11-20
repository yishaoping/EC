// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__11(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__11\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_3
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_25_3
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_103[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_103[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_103[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_0
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_0
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_104[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_104[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_104[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_1
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_1
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_105[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_105[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_105[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_2
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_2
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_106[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_106[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_106[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_3
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_26_3
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_107[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_107[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_107[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_0
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_0
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_108[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_108[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_108[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_1
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_1
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_109[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_109[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_109[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_2
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_2
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_110[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_110[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_110[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_3
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_27_3
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_111[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_111[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_111[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_0
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_0
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_112[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_112[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_112[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_1
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_1
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_113[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_113[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_113[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_2
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_2
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_114[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_114[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_114[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_3
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_3
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_115[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_115[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_115[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_0
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_0
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_116[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_116[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_116[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_1
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_1
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_117[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_117[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_117[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_2
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_2
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_118[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_118[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_118[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_3
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_29)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_29_3
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_119[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_119[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_119[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_0
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_0
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_120[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_120[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_120[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_1
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_1
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_121[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_121[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_121[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_2
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_2
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_122[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_122[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_122[2U] 
        = (1U & __Vtemp_80[2U]);
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__12(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__12\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_3
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_3
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_123[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_123[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_123[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_0
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_0
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_124[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_124[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_124[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_1
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_1
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_125[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_125[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_125[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_2
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_2
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_126[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_126[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_126[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_3
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_31)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_31_3
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_127[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_127[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_127[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_0_0
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_0_0
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_0_1
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_0_1
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_1[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_1[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_1[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_0_2
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_0_2
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_2[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_2[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_2[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_0_3
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_0)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_0_3
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_3[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_3[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_3[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_1_0
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_1_0
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_4[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_4[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_4[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_1_1
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_1_1
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_5[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_5[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_5[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_1_2
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_1_2
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_6[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_6[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_6[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_1_3
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_1)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_1_3
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_7[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_7[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_7[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_2_0
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_2_0
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_8[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_8[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_8[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_2_1
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_2_1
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_9[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_9[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_9[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_2_2
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_2_2
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_10[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_10[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_10[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_2_3
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_2_3
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_11[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_11[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_11[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_3_0
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_3_0
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_12[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_12[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_12[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_3_1
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_3_1
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_13[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_13[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_13[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_3_2
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_3_2
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_14[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_14[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_14[2U] 
        = (1U & __Vtemp_80[2U]);
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__13(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__13\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_3_3
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_3)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_3_3
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_15[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_15[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_15[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_4_0
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_4_0
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_16[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_16[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_16[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_4_1
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_4_1
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_17[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_17[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_17[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_4_2
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_4_2
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_18[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_18[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_18[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_4_3
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_4_3
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_19[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_19[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_19[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_5_0
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_5_0
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_20[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_20[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_20[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_5_1
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_5_1
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_21[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_21[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_21[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_5_2
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_5_2
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_22[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_22[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_22[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_5_3
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_5_3
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_23[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_23[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_23[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_6_0
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_6_0
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_24[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_24[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_24[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_6_1
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_6_1
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_25[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_25[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_25[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_6_2
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_6_2
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_26[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_26[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_26[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_6_3
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_6_3
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_27[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_27[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_27[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_7_0
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_7_0
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_28[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_28[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_28[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_7_1
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_7_1
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_29[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_29[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_29[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_7_2
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_7_2
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_30[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_30[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_30[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_7_3
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_7_3
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_31[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_31[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_31[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_8_0
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_8_0
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_32[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_32[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_32[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_8_1
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_8_1
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_33[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_33[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_33[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_8_2
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_8_2
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_34[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_34[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_34[2U] 
        = (1U & __Vtemp_80[2U]);
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__14(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__14\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_8_3
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_8_3
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_35[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_35[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_35[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_9_0
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_9_0
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_36[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_36[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_36[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_9_1
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_9_1
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_37[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_37[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_37[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_9_2
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_9_2
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_38[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_38[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_38[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_9_3
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_9_3
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_39[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_39[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_39[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_10_0
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_10_0
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_40[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_40[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_40[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_10_1
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_10_1
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_41[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_41[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_41[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_10_2
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_10_2
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_42[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_42[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_42[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_10_3
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_10_3
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_43[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_43[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_43[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_11_0
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_11_0
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_44[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_44[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_44[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_11_1
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_11_1
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_45[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_45[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_45[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_11_2
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_11_2
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_46[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_46[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_46[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_11_3
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_11_3
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_47[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_47[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_47[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_12_0
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_12_0
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_48[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_48[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_48[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_12_1
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_12_1
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_49[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_49[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_49[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_12_2
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_12_2
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_50[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_50[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_50[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_12_3
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_12_3
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_51[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_51[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_51[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_13_0
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_13_0
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_52[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_52[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_52[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_13_1
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_13_1
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_53[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_53[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_53[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_13_2
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_13_2
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_54[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_54[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_54[2U] 
        = (1U & __Vtemp_80[2U]);
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__15(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__15\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_13_3
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_13_3
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_55[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_55[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_55[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_14_0
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_14_0
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_56[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_56[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_56[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_14_1
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_14_1
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_57[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_57[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_57[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_14_2
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_14_2
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_58[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_58[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_58[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_14_3
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_14_3
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_59[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_59[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_59[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_15_0
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_15_0
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_60[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_60[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_60[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_15_1
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_15_1
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_61[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_61[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_61[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_15_2
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_15_2
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_62[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_62[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_62[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_15_3
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_15)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_15_3
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_63[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_63[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_63[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_16_0
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_16_0
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_64[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_64[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_64[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_16_1
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_16_1
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_65[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_65[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_65[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_16_2
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_16_2
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_66[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_66[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_66[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_16_3
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_16_3
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_67[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_67[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_67[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_17_0
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_17_0
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_68[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_68[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_68[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_17_1
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_17_1
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_69[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_69[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_69[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_17_2
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_17_2
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_70[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_70[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_70[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_17_3
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_17_3
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_71[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_71[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_71[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_18_0
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_18_0
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_72[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_72[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_72[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_18_1
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_18_1
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_73[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_73[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_73[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_18_2
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_18_2
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_74[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_74[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_74[2U] 
        = (1U & __Vtemp_80[2U]);
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__16(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__16\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_18_3
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_18_3
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_75[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_75[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_75[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_19_0
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_19_0
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_76[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_76[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_76[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_19_1
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_19_1
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_77[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_77[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_77[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_19_2
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_19_2
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_78[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_78[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_78[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_19_3
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_19)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_19_3
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_79[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_79[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_79[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_20_0
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_20_0
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_80[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_80[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_80[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_20_1
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_20_1
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_81[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_81[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_81[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_20_2
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_20_2
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_82[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_82[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_82[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_20_3
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_20_3
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_83[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_83[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_83[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_21_0
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_21_0
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_84[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_84[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_84[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_21_1
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_21_1
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_85[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_85[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_85[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_21_2
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_21_2
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_86[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_86[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_86[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_21_3
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_21_3
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_87[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_87[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_87[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_22_0
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_22_0
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_88[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_88[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_88[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_22_1
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_22_1
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_89[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_89[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_89[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_22_2
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_22_2
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_90[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_90[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_90[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_22_3
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_22)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_22_3
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_91[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_91[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_91[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_23_0
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_23_0
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_92[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_92[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_92[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_23_1
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_23_1
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_93[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_93[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_93[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_23_2
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_23_2
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_94[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_94[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_94[2U] 
        = (1U & __Vtemp_80[2U]);
}

VL_INLINE_OPT void Vtb___024root___act_sequent__TOP__17(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___act_sequent__TOP__17\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_23_3
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_23)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_23_3
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_95[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_95[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_95[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_24_0
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_24_0
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_96[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_96[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_96[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_24_1
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_24_1
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_97[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_97[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_97[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_24_2
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_24_2
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_98[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_98[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_98[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_24_3
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_24_3
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_99[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_99[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_99[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_25_0
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_25_0
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_100[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_100[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_100[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_25_1
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_25_1
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_101[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_101[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_101[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_25_2
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_25_2
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_102[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_102[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_102[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_25_3
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_25)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_25_3
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_103[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_103[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_103[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_26_0
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_26_0
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_104[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_104[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_104[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_26_1
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_26_1
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_105[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_105[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_105[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_26_2
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_26_2
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_106[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_106[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_106[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_26_3
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_26)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_26_3
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_107[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_107[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_107[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_27_0
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_27_0
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_108[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_108[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_108[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_27_1
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_27_1
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_109[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_109[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_109[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_27_2
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_27_2
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_110[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_110[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_110[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_27_3
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_27)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_27_3
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_111[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_111[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_111[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_28_0
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_28_0
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_112[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_112[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_112[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_28_1
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_28_1
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_113[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_113[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_113[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_28_2
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_28_2
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_114[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_114[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_114[2U] 
        = (1U & __Vtemp_80[2U]);
}
