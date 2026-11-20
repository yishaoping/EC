// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb___024root.h"

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__12(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__12\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_8_2
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_8_2
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_34[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_34[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_34[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_8_3
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_8_3
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_35[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_35[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_35[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_8_0
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_8_0
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_32[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_32[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_32[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_8_1
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_8_1
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_33[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_33[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_33[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_8_2
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_8_2
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_34[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_34[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_34[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_8_3
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_8_3
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_35[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_35[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_35[2U] 
        = (1U & __Vtemp_24[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_8 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_8) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_8));
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_6_0
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_6_0
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_24[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_24[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_24[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_6_1
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_6_1
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_25[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_25[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_25[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_6_2
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_6_2
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_26[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_26[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_26[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_6_3
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_6_3
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_27[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_27[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_27[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_6_0
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_6_0
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_24[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_24[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_24[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_6_1
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_6_1
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_25[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_25[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_25[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_6_2
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_6_2
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_26[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_26[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_26[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_6_3
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_6_3
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_27[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_27[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_27[2U] 
        = (1U & __Vtemp_56[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_6 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_6) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_6));
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_4_0
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_4_0
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_16[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_16[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_16[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_4_1
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_4_1
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_17[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_17[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_17[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_4_2
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_4_2
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_18[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_18[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_18[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_4_3
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_4_3
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_19[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_19[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_19[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_4_0
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_4_0
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_16[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_16[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_16[2U] 
        = (1U & __Vtemp_76[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__13(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__13\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_4_1
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_4_1
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_17[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_17[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_17[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_4_2
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_4_2
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_18[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_18[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_18[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_4_3
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_4_3
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_19[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_19[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_19[2U] 
        = (1U & __Vtemp_12[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_4 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_4) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_4));
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_10_0
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_10_0
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_40[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_40[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_40[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_10_1
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_10_1
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_41[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_41[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_41[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_10_2
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_10_2
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_42[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_42[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_42[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_10_3
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_10_3
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_43[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_43[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_43[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_10_0
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_10_0
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_40[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_40[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_40[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_10_1
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_10_1
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_41[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_41[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_41[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_10_2
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_10_2
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_42[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_42[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_42[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_10_3
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_10_3
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_43[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_43[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_43[2U] 
        = (1U & __Vtemp_44[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_10 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_10) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_10));
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_5_0
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_5_0
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_20[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_20[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_20[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_5_1
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_5_1
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_21[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_21[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_21[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_5_2
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_5_2
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_22[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_22[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_22[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_5_3
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_5_3
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_23[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_23[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_23[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_5_0
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_5_0
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_20[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_20[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_20[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_5_1
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_5_1
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_21[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_21[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_21[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_5_2
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_5_2
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_22[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_22[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_22[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_5_3
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_5_3
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_23[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_23[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_23[2U] 
        = (1U & __Vtemp_76[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__14(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__14\n"); );
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
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_5 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_5) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_5));
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_2_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_2_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_8[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_8[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_8[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_2_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_2_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_9[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_9[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_9[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_2_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_2_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_10[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_10[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_10[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_2_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_2_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_11[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_11[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_11[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_2_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_2_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_8[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_8[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_8[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_2_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_2_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_9[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_9[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_9[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_2_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_2_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_10[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_10[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_10[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_2_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_2_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_11[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_11[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_11[2U] 
        = (1U & __Vtemp_32[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_2 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_2) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_2));
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_11_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_11_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_44[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_44[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_44[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_11_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_11_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_45[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_45[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_45[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_11_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_11_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_46[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_46[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_46[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_11_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_11_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_47[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_47[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_47[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_11_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_11_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_44[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_44[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_44[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_11_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_11_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_45[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_45[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_45[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_11_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_11_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_46[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_46[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_46[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_11_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_11_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_47[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_47[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_47[2U] 
        = (1U & __Vtemp_64[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_11 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_11) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_11));
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_21_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_21_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_84[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_84[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_84[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_21_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_21_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_85[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_85[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_85[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_21_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_21_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_86[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_86[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_86[2U] 
        = (1U & __Vtemp_76[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__15(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__15\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_21_3
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_21_3
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_87[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_87[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_87[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_21_0
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_21_0
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_84[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_84[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_84[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_21_1
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_21_1
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_85[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_85[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_85[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_21_2
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_21_2
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_86[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_86[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_86[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_21_3
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_21_3
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_87[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_87[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_87[2U] 
        = (1U & __Vtemp_20[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_21 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_21) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_21));
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_7_0
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_7_0
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_28[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_28[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_28[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_7_1
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_7_1
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_29[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_29[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_29[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_7_2
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_7_2
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_30[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_30[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_30[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_7_3
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_7_3
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_31[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_31[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_31[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_7_0
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_7_0
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_28[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_28[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_28[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_7_1
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_7_1
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_29[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_29[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_29[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_7_2
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_7_2
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_30[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_30[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_30[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_7_3
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_7_3
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_31[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_31[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_31[2U] 
        = (1U & __Vtemp_52[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_7 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_7) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_7));
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_9_0
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_9_0
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_36[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_36[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_36[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_9_1
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_9_1
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_37[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_37[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_37[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_9_2
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_9_2
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_38[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_38[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_38[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_9_3
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_9_3
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_39[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_39[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_39[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_9_0
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_9_0
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_36[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_36[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_36[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_9_1
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_9_1
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_37[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_37[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_37[2U] 
        = (1U & __Vtemp_76[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__16(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__16\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_9_2
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_9_2
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_38[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_38[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_38[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_9_3
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_9_3
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_39[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_39[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_39[2U] 
        = (1U & __Vtemp_8[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_9 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_9) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_9));
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_12_0
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_12_0
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_48[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_48[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_48[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_12_1
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_12_1
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_49[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_49[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_49[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_12_2
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_12_2
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_50[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_50[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_50[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_12_3
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_12_3
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_51[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_51[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_51[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_12_0
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_12_0
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_48[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_48[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_48[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_12_1
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_12_1
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_49[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_49[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_49[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_12_2
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_12_2
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_50[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_50[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_50[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_12_3
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_12_3
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_51[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_51[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_51[2U] 
        = (1U & __Vtemp_40[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_12 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_12) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_12));
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_14_0
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_14_0
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_56[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_56[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_56[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_14_1
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_14_1
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_57[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_57[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_57[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_14_2
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_14_2
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_58[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_58[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_58[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_14_3
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_14_3
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_59[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_59[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_59[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_14_0
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_14_0
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_56[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_56[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_56[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_14_1
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_14_1
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_57[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_57[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_57[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_14_2
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_14_2
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_58[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_58[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_58[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_14_3
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_14_3
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_59[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_59[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_59[2U] 
        = (1U & __Vtemp_72[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_14 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_14) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_14));
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_16_0
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_16_0
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_64[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_64[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_64[2U] 
        = (1U & __Vtemp_76[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__17(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__17\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_16_1
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_16_1
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_65[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_65[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_65[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_16_2
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_16_2
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_66[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_66[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_66[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_16_3
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_16_3
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_67[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_67[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_67[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_16_0
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_16_0
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_64[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_64[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_64[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_16_1
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_16_1
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_65[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_65[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_65[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_16_2
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_16_2
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_66[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_66[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_66[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_16_3
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_16_3
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_67[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_67[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_67[2U] 
        = (1U & __Vtemp_28[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_16 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_16) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_16));
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_18_0
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_18_0
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_72[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_72[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_72[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_18_1
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_18_1
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_73[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_73[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_73[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_18_2
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_18_2
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_74[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_74[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_74[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_18_3
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_18_3
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_75[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_75[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_75[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_18_0
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_18_0
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_72[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_72[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_72[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_18_1
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_18_1
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_73[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_73[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_73[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_18_2
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_18_2
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_74[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_74[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_74[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_18_3
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_18_3
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_75[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_75[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_75[2U] 
        = (1U & __Vtemp_60[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_18 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_18) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_18));
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_0
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_0
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_120[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_120[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_120[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_1
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_1
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_121[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_121[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_121[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_2
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_2
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_122[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_122[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_122[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_3
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_30_3
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_123[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_123[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_123[2U] 
        = (1U & __Vtemp_76[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__18(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__18\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_30_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_30_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_120[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_120[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_120[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_30_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_30_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_121[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_121[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_121[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_30_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_30_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_122[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_122[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_122[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_30_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_30_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_123[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_123[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_123[2U] 
        = (1U & __Vtemp_16[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_30 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_30) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_30));
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_13_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_13_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_52[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_52[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_52[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_13_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_13_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_53[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_53[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_53[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_13_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_13_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_54[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_54[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_54[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_13_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_13_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_55[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_55[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_55[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_13_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_13_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_52[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_52[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_52[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_13_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_13_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_53[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_53[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_53[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_13_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_13_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_54[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_54[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_54[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_13_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_13_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_55[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_55[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_55[2U] 
        = (1U & __Vtemp_48[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_13 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_13) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_13));
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_17_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_17_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_68[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_68[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_68[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_17_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_17_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_69[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_69[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_69[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_17_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_17_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_70[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_70[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_70[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_17_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_17_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_71[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_71[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_71[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_17_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_17_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_68[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_68[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_68[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_17_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_17_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_69[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_69[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_69[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_17_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_17_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_70[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_70[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_70[2U] 
        = (1U & __Vtemp_76[2U]);
}

VL_INLINE_OPT void Vtb___024root___nba_comb__TOP__19(Vtb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb___024root___nba_comb__TOP__19\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_17_3
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_17_3
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_71[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_71[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_71[2U] 
        = (1U & __Vtemp_4[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_17 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_17) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_17));
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                              ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_20_0
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_20_0
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_80[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_80[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_80[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_20_1
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_20_1
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_81[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_81[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_81[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_20_2
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_20_2
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_82[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_82[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_82[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_20_3
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_20_3
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_83[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_83[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_83[2U] 
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
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_20 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_20) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_20));
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_24_0
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_24_0
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_96[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_96[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_96[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_24_1
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_24_1
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_97[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_97[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_97[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_24_2
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_24_2
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.tb__DOT__io_newStore_words8;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_98[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_98[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_98[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_24_3
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_24_3
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.tb__DOT__io_newStore_lines;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_99[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_99[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_99[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_24_0
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_24_0
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_96[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_96[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_96[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_24_1
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_24_1
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words4;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_97[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_97[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_97[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_24_2
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_24_2
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.tb__DOT__io_newFirstStore_words8;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_98[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_98[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_98[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_24_3
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketFirstStore_24_3
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.tb__DOT__io_newFirstStore_lines;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_99[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_99[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentFirstStoreNextWide_99[2U] 
        = (1U & __Vtemp_68[2U]);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT___io_retiringValid_T_24 
        = ((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__retireSelect_24) 
           & (IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_24));
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_0
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_0
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.tb__DOT__io_newStore_bytes;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_112[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_112[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_112[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                               ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_1
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketValid_28)
                                ? vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__bucketStore_28_1
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.tb__DOT__io_newStore_words4;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_113[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_113[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.tb__DOT__dut__DOT__candidate_0__DOT__currentStoreNextWide_113[2U] 
        = (1U & __Vtemp_76[2U]);
}
