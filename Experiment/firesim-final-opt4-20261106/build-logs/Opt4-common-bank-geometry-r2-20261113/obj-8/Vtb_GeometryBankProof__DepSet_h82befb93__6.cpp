// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_GeometryBankProof.h"
#include "Vtb__Syms.h"

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__1(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__1\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                              ? vlSelfRef.__PVT__bucketStore_4_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketStore_4_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentStoreNextWide_16[0U] = 
        __Vtemp_4[0U];
    vlSelfRef.__PVT__currentStoreNextWide_16[1U] = 
        __Vtemp_4[1U];
    vlSelfRef.__PVT__currentStoreNextWide_16[2U] = 
        (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                              ? vlSelfRef.__PVT__bucketStore_4_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketStore_4_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentStoreNextWide_17[0U] = 
        __Vtemp_8[0U];
    vlSelfRef.__PVT__currentStoreNextWide_17[1U] = 
        __Vtemp_8[1U];
    vlSelfRef.__PVT__currentStoreNextWide_17[2U] = 
        (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketStore_4_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketStore_4_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentStoreNextWide_18[0U] = 
        __Vtemp_12[0U];
    vlSelfRef.__PVT__currentStoreNextWide_18[1U] = 
        __Vtemp_12[1U];
    vlSelfRef.__PVT__currentStoreNextWide_18[2U] = 
        (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketStore_4_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketStore_4_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentStoreNextWide_19[0U] = 
        __Vtemp_16[0U];
    vlSelfRef.__PVT__currentStoreNextWide_19[1U] = 
        __Vtemp_16[1U];
    vlSelfRef.__PVT__currentStoreNextWide_19[2U] = 
        (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketFirstStore_4_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketFirstStore_4_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentFirstStoreNextWide_16[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_16[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_16[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketFirstStore_4_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketFirstStore_4_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentFirstStoreNextWide_17[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_17[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_17[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketFirstStore_4_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketFirstStore_4_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentFirstStoreNextWide_18[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_18[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_18[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketFirstStore_4_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketFirstStore_4_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__currentFirstStoreNextWide_19[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_19[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_19[2U] 
        = (1U & __Vtemp_32[2U]);
    vlSelfRef.__PVT___io_retiringValid_T_5 = ((IData)(vlSelfRef.__PVT__retireSelect_5) 
                                              & (IData)(vlSelfRef.__PVT__bucketValid_5));
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketStore_5_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketStore_5_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__currentStoreNextWide_20[0U] = 
        __Vtemp_36[0U];
    vlSelfRef.__PVT__currentStoreNextWide_20[1U] = 
        __Vtemp_36[1U];
    vlSelfRef.__PVT__currentStoreNextWide_20[2U] = 
        (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketStore_5_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketStore_5_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__currentStoreNextWide_21[0U] = 
        __Vtemp_40[0U];
    vlSelfRef.__PVT__currentStoreNextWide_21[1U] = 
        __Vtemp_40[1U];
    vlSelfRef.__PVT__currentStoreNextWide_21[2U] = 
        (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketStore_5_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketStore_5_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__currentStoreNextWide_22[0U] = 
        __Vtemp_44[0U];
    vlSelfRef.__PVT__currentStoreNextWide_22[1U] = 
        __Vtemp_44[1U];
    vlSelfRef.__PVT__currentStoreNextWide_22[2U] = 
        (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketStore_5_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketStore_5_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__currentStoreNextWide_23[0U] = 
        __Vtemp_48[0U];
    vlSelfRef.__PVT__currentStoreNextWide_23[1U] = 
        __Vtemp_48[1U];
    vlSelfRef.__PVT__currentStoreNextWide_23[2U] = 
        (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketFirstStore_5_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketFirstStore_5_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__currentFirstStoreNextWide_20[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_20[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_20[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketFirstStore_5_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketFirstStore_5_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__currentFirstStoreNextWide_21[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_21[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_21[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketFirstStore_5_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketFirstStore_5_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__currentFirstStoreNextWide_22[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_22[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_22[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketFirstStore_5_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketFirstStore_5_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__currentFirstStoreNextWide_23[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_23[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_23[2U] 
        = (1U & __Vtemp_64[2U]);
    vlSelfRef.__PVT___io_retiringValid_T_1 = ((IData)(vlSelfRef.__PVT__retireSelect_1) 
                                              & (IData)(vlSelfRef.__PVT__bucketValid_1));
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketStore_1_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketStore_1_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__currentStoreNextWide_4[0U] = __Vtemp_68[0U];
    vlSelfRef.__PVT__currentStoreNextWide_4[1U] = __Vtemp_68[1U];
    vlSelfRef.__PVT__currentStoreNextWide_4[2U] = (1U 
                                                   & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketStore_1_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketStore_1_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__currentStoreNextWide_5[0U] = __Vtemp_72[0U];
    vlSelfRef.__PVT__currentStoreNextWide_5[1U] = __Vtemp_72[1U];
    vlSelfRef.__PVT__currentStoreNextWide_5[2U] = (1U 
                                                   & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketStore_1_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketStore_1_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__currentStoreNextWide_6[0U] = __Vtemp_76[0U];
    vlSelfRef.__PVT__currentStoreNextWide_6[1U] = __Vtemp_76[1U];
    vlSelfRef.__PVT__currentStoreNextWide_6[2U] = (1U 
                                                   & __Vtemp_76[2U]);
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__2(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__2\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                              ? vlSelfRef.__PVT__bucketStore_1_3
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketStore_1_3
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentStoreNextWide_7[0U] = __Vtemp_4[0U];
    vlSelfRef.__PVT__currentStoreNextWide_7[1U] = __Vtemp_4[1U];
    vlSelfRef.__PVT__currentStoreNextWide_7[2U] = (1U 
                                                   & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                              ? vlSelfRef.__PVT__bucketFirstStore_1_0
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketFirstStore_1_0
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentFirstStoreNextWide_4[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_4[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_4[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketFirstStore_1_1
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketFirstStore_1_1
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentFirstStoreNextWide_5[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_5[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_5[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketFirstStore_1_2
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketFirstStore_1_2
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentFirstStoreNextWide_6[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_6[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_6[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketFirstStore_1_3
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketFirstStore_1_3
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentFirstStoreNextWide_7[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_7[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_7[2U] 
        = (1U & __Vtemp_20[2U]);
    vlSelfRef.__PVT___io_retiringValid_T_7 = ((IData)(vlSelfRef.__PVT__retireSelect_7) 
                                              & (IData)(vlSelfRef.bucketValid_7));
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketStore_7_0
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketStore_7_0
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentStoreNextWide_28[0U] = 
        __Vtemp_24[0U];
    vlSelfRef.__PVT__currentStoreNextWide_28[1U] = 
        __Vtemp_24[1U];
    vlSelfRef.__PVT__currentStoreNextWide_28[2U] = 
        (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketStore_7_1
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketStore_7_1
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentStoreNextWide_29[0U] = 
        __Vtemp_28[0U];
    vlSelfRef.__PVT__currentStoreNextWide_29[1U] = 
        __Vtemp_28[1U];
    vlSelfRef.__PVT__currentStoreNextWide_29[2U] = 
        (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketStore_7_2
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketStore_7_2
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__currentStoreNextWide_30[0U] = 
        __Vtemp_32[0U];
    vlSelfRef.__PVT__currentStoreNextWide_30[1U] = 
        __Vtemp_32[1U];
    vlSelfRef.__PVT__currentStoreNextWide_30[2U] = 
        (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketStore_7_3
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketStore_7_3
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__currentStoreNextWide_31[0U] = 
        __Vtemp_36[0U];
    vlSelfRef.__PVT__currentStoreNextWide_31[1U] = 
        __Vtemp_36[1U];
    vlSelfRef.__PVT__currentStoreNextWide_31[2U] = 
        (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_0
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketFirstStore_7_0
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_1
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketFirstStore_7_1
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_2
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketFirstStore_7_2
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_3
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketFirstStore_7_3
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[2U] 
        = (1U & __Vtemp_52[2U]);
    vlSelfRef.__PVT___io_retiringValid_T_6 = ((IData)(vlSelfRef.__PVT__retireSelect_6) 
                                              & (IData)(vlSelfRef.__PVT__bucketValid_6));
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketStore_6_0
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketStore_6_0
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__currentStoreNextWide_24[0U] = 
        __Vtemp_56[0U];
    vlSelfRef.__PVT__currentStoreNextWide_24[1U] = 
        __Vtemp_56[1U];
    vlSelfRef.__PVT__currentStoreNextWide_24[2U] = 
        (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketStore_6_1
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketStore_6_1
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__currentStoreNextWide_25[0U] = 
        __Vtemp_60[0U];
    vlSelfRef.__PVT__currentStoreNextWide_25[1U] = 
        __Vtemp_60[1U];
    vlSelfRef.__PVT__currentStoreNextWide_25[2U] = 
        (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketStore_6_2
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketStore_6_2
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__currentStoreNextWide_26[0U] = 
        __Vtemp_64[0U];
    vlSelfRef.__PVT__currentStoreNextWide_26[1U] = 
        __Vtemp_64[1U];
    vlSelfRef.__PVT__currentStoreNextWide_26[2U] = 
        (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketStore_6_3
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketStore_6_3
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__currentStoreNextWide_27[0U] = 
        __Vtemp_68[0U];
    vlSelfRef.__PVT__currentStoreNextWide_27[1U] = 
        __Vtemp_68[1U];
    vlSelfRef.__PVT__currentStoreNextWide_27[2U] = 
        (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_0
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketFirstStore_6_0
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__currentFirstStoreNextWide_24[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_24[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_24[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_1
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketFirstStore_6_1
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__currentFirstStoreNextWide_25[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_25[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_25[2U] 
        = (1U & __Vtemp_76[2U]);
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__3(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__3\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                              ? vlSelfRef.__PVT__bucketFirstStore_6_2
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_2
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentFirstStoreNextWide_26[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_26[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_26[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                              ? vlSelfRef.__PVT__bucketFirstStore_6_3
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_3
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentFirstStoreNextWide_27[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_27[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_27[2U] 
        = (1U & __Vtemp_8[2U]);
    vlSelfRef.__PVT___io_retiringValid_T_3 = ((IData)(vlSelfRef.__PVT__retireSelect_3) 
                                              & (IData)(vlSelfRef.__PVT__bucketValid_3));
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketStore_3_0
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketStore_3_0
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentStoreNextWide_12[0U] = 
        __Vtemp_12[0U];
    vlSelfRef.__PVT__currentStoreNextWide_12[1U] = 
        __Vtemp_12[1U];
    vlSelfRef.__PVT__currentStoreNextWide_12[2U] = 
        (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketStore_3_1
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketStore_3_1
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentStoreNextWide_13[0U] = 
        __Vtemp_16[0U];
    vlSelfRef.__PVT__currentStoreNextWide_13[1U] = 
        __Vtemp_16[1U];
    vlSelfRef.__PVT__currentStoreNextWide_13[2U] = 
        (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketStore_3_2
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketStore_3_2
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentStoreNextWide_14[0U] = 
        __Vtemp_20[0U];
    vlSelfRef.__PVT__currentStoreNextWide_14[1U] = 
        __Vtemp_20[1U];
    vlSelfRef.__PVT__currentStoreNextWide_14[2U] = 
        (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketStore_3_3
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketStore_3_3
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentStoreNextWide_15[0U] = 
        __Vtemp_24[0U];
    vlSelfRef.__PVT__currentStoreNextWide_15[1U] = 
        __Vtemp_24[1U];
    vlSelfRef.__PVT__currentStoreNextWide_15[2U] = 
        (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketFirstStore_3_0
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketFirstStore_3_0
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentFirstStoreNextWide_12[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_12[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_12[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketFirstStore_3_1
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketFirstStore_3_1
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__currentFirstStoreNextWide_13[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_13[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_13[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketFirstStore_3_2
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketFirstStore_3_2
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__currentFirstStoreNextWide_14[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_14[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_14[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketFirstStore_3_3
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketFirstStore_3_3
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__currentFirstStoreNextWide_15[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_15[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_15[2U] 
        = (1U & __Vtemp_40[2U]);
    vlSelfRef.__PVT___io_retiringValid_T = ((IData)(vlSelfRef.__PVT__retireSelect_0) 
                                            & (IData)(vlSelfRef.bucketValid_0));
    vlSelfRef.io_queryMatch_0 = (IData)(((0U == (0xf8U 
                                                 & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset))) 
                                         & (((7U == 
                                              (7U & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                              ? (IData)(vlSelfRef.bucketValid_7)
                                              : ((6U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                  ? (IData)(vlSelfRef.__PVT__bucketValid_6)
                                                  : 
                                                 ((5U 
                                                   == 
                                                   (7U 
                                                    & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                   ? (IData)(vlSelfRef.__PVT__bucketValid_5)
                                                   : 
                                                  ((4U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                    ? (IData)(vlSelfRef.__PVT__bucketValid_4)
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                     ? (IData)(vlSelfRef.__PVT__bucketValid_3)
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                      ? (IData)(vlSelfRef.__PVT__bucketValid_2)
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                       ? (IData)(vlSelfRef.__PVT__bucketValid_1)
                                                       : (IData)(vlSelfRef.bucketValid_0)))))))) 
                                            & ((((7U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                  ? vlSelfRef.bucketSeq_7
                                                  : 
                                                 ((6U 
                                                   == 
                                                   (7U 
                                                    & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                   ? vlSelfRef.__PVT__bucketSeq_6
                                                   : 
                                                  ((5U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                    ? vlSelfRef.__PVT__bucketSeq_5
                                                    : 
                                                   ((4U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                     ? vlSelfRef.__PVT__bucketSeq_4
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                      ? vlSelfRef.__PVT__bucketSeq_3
                                                      : 
                                                     ((2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                       ? vlSelfRef.__PVT__bucketSeq_2
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (7U 
                                                         & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                        ? vlSelfRef.__PVT__bucketSeq_1
                                                        : vlSelfRef.bucketSeq_0))))))) 
                                                >> 8U) 
                                               == (vlSymsp->TOP.tb__DOT__io_querySeq_0 
                                                   >> 8U)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__47(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__47\n"); );
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
    // Body
    vlSelfRef.io_queryMatch_87 = (IData)(((0U == (0xf8U 
                                                  & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset))) 
                                          & (((7U == 
                                               (7U 
                                                & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                               ? (IData)(vlSelfRef.bucketValid_7)
                                               : ((6U 
                                                   == 
                                                   (7U 
                                                    & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                   ? (IData)(vlSelfRef.__PVT__bucketValid_6)
                                                   : 
                                                  ((5U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                    ? (IData)(vlSelfRef.__PVT__bucketValid_5)
                                                    : 
                                                   ((4U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                     ? (IData)(vlSelfRef.__PVT__bucketValid_4)
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                      ? (IData)(vlSelfRef.__PVT__bucketValid_3)
                                                      : 
                                                     ((2U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                       ? (IData)(vlSelfRef.__PVT__bucketValid_2)
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (7U 
                                                         & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                        ? (IData)(vlSelfRef.__PVT__bucketValid_1)
                                                        : (IData)(vlSelfRef.bucketValid_0)))))))) 
                                             & ((((7U 
                                                   == 
                                                   (7U 
                                                    & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                   ? vlSelfRef.bucketSeq_7
                                                   : 
                                                  ((6U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                    ? vlSelfRef.__PVT__bucketSeq_6
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                     ? vlSelfRef.__PVT__bucketSeq_5
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                      ? vlSelfRef.__PVT__bucketSeq_4
                                                      : 
                                                     ((3U 
                                                       == 
                                                       (7U 
                                                        & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                       ? vlSelfRef.__PVT__bucketSeq_3
                                                       : 
                                                      ((2U 
                                                        == 
                                                        (7U 
                                                         & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                        ? vlSelfRef.__PVT__bucketSeq_2
                                                        : 
                                                       ((1U 
                                                         == 
                                                         (7U 
                                                          & (IData)(vlSelfRef.__PVT__io_queryMatch_87_offset)))
                                                         ? vlSelfRef.__PVT__bucketSeq_1
                                                         : vlSelfRef.bucketSeq_0))))))) 
                                                 >> 8U) 
                                                == 
                                                (vlSymsp->TOP.tb__DOT__io_querySeq_87 
                                                 >> 8U)))));
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                              ? vlSelfRef.bucketStore_0_1
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketStore_0_1
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentStoreNextWide_1[0U] = __Vtemp_4[0U];
    vlSelfRef.__PVT__currentStoreNextWide_1[1U] = __Vtemp_4[1U];
    vlSelfRef.__PVT__currentStoreNextWide_1[2U] = (1U 
                                                   & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                              ? vlSelfRef.bucketStore_0_2
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketStore_0_2
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentStoreNextWide_2[0U] = __Vtemp_8[0U];
    vlSelfRef.__PVT__currentStoreNextWide_2[1U] = __Vtemp_8[1U];
    vlSelfRef.__PVT__currentStoreNextWide_2[2U] = (1U 
                                                   & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketStore_0_3
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                                ? vlSelfRef.bucketStore_0_3
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentStoreNextWide_3[0U] = __Vtemp_12[0U];
    vlSelfRef.__PVT__currentStoreNextWide_3[1U] = __Vtemp_12[1U];
    vlSelfRef.__PVT__currentStoreNextWide_3[2U] = (1U 
                                                   & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketFirstStore_0_0
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                                ? vlSelfRef.bucketFirstStore_0_0
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentFirstStoreNextWide[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketFirstStore_0_1
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                                ? vlSelfRef.bucketFirstStore_0_1
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentFirstStoreNextWide_1[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_1[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_1[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketFirstStore_0_2
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                                ? vlSelfRef.bucketFirstStore_0_2
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentFirstStoreNextWide_2[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_2[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_2[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketFirstStore_0_3
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                                ? vlSelfRef.bucketFirstStore_0_3
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentFirstStoreNextWide_3[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_3[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_3[2U] 
        = (1U & __Vtemp_28[2U]);
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__48(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__48\n"); );
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
    vlSelfRef.__PVT___T_162 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_2) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_2)));
    __Vtemp_2[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_2_0);
    __Vtemp_2[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_2_0 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1185;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__loadFirstNextWide_8[0U] = __Vtemp_4[0U];
    vlSelfRef.__PVT__loadFirstNextWide_8[1U] = __Vtemp_4[1U];
    vlSelfRef.__PVT__loadFirstNextWide_8[2U] = (1U 
                                                & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_2_1);
    __Vtemp_6[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_2_1 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1224;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__loadFirstNextWide_9[0U] = __Vtemp_8[0U];
    vlSelfRef.__PVT__loadFirstNextWide_9[1U] = __Vtemp_8[1U];
    vlSelfRef.__PVT__loadFirstNextWide_9[2U] = (1U 
                                                & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_2_2);
    __Vtemp_10[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_2_2 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1265;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__loadFirstNextWide_10[0U] = __Vtemp_12[0U];
    vlSelfRef.__PVT__loadFirstNextWide_10[1U] = __Vtemp_12[1U];
    vlSelfRef.__PVT__loadFirstNextWide_10[2U] = (1U 
                                                 & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_2_3);
    __Vtemp_14[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_2_3 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1306;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__loadFirstNextWide_11[0U] = __Vtemp_16[0U];
    vlSelfRef.__PVT__loadFirstNextWide_11[1U] = __Vtemp_16[1U];
    vlSelfRef.__PVT__loadFirstNextWide_11[2U] = (1U 
                                                 & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_2_0);
    __Vtemp_18[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_2_0 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1185;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__storeFirstNextWide_8[0U] = __Vtemp_20[0U];
    vlSelfRef.__PVT__storeFirstNextWide_8[1U] = __Vtemp_20[1U];
    vlSelfRef.__PVT__storeFirstNextWide_8[2U] = (1U 
                                                 & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_2_1);
    __Vtemp_22[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_2_1 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1224;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__storeFirstNextWide_9[0U] = __Vtemp_24[0U];
    vlSelfRef.__PVT__storeFirstNextWide_9[1U] = __Vtemp_24[1U];
    vlSelfRef.__PVT__storeFirstNextWide_9[2U] = (1U 
                                                 & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_2_2);
    __Vtemp_26[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_2_2 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1265;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__storeFirstNextWide_10[0U] = __Vtemp_28[0U];
    vlSelfRef.__PVT__storeFirstNextWide_10[1U] = __Vtemp_28[1U];
    vlSelfRef.__PVT__storeFirstNextWide_10[2U] = (1U 
                                                  & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_2_3);
    __Vtemp_30[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_2_3 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1306;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__storeFirstNextWide_11[0U] = __Vtemp_32[0U];
    vlSelfRef.__PVT__storeFirstNextWide_11[1U] = __Vtemp_32[1U];
    vlSelfRef.__PVT__storeFirstNextWide_11[2U] = (1U 
                                                  & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_2_0);
    __Vtemp_34[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_2_0 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12102;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__strictWriteReadNextWide_8[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_8[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_8[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_2_1);
    __Vtemp_38[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_2_1 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12518;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__strictWriteReadNextWide_9[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_9[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_9[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_2_2);
    __Vtemp_42[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_2_2 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12954;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__strictWriteReadNextWide_10[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_10[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_10[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_2_3);
    __Vtemp_46[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_2_3 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_13390;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__strictWriteReadNextWide_11[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_11[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_11[2U] 
        = (1U & __Vtemp_48[2U]);
    vlSelfRef.__PVT__allocate_2 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_2)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_2));
    vlSelfRef.__PVT___GEN_250 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_2)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_2));
    vlSelfRef.__PVT___T_308 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_4) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_4)));
    __Vtemp_50[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_4_0);
    __Vtemp_50[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_4_0 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2057;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__loadFirstNextWide_16[0U] = __Vtemp_52[0U];
    vlSelfRef.__PVT__loadFirstNextWide_16[1U] = __Vtemp_52[1U];
    vlSelfRef.__PVT__loadFirstNextWide_16[2U] = (1U 
                                                 & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_4_1);
    __Vtemp_54[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_4_1 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2096;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__loadFirstNextWide_17[0U] = __Vtemp_56[0U];
    vlSelfRef.__PVT__loadFirstNextWide_17[1U] = __Vtemp_56[1U];
    vlSelfRef.__PVT__loadFirstNextWide_17[2U] = (1U 
                                                 & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_4_2);
    __Vtemp_58[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_4_2 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2137;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__loadFirstNextWide_18[0U] = __Vtemp_60[0U];
    vlSelfRef.__PVT__loadFirstNextWide_18[1U] = __Vtemp_60[1U];
    vlSelfRef.__PVT__loadFirstNextWide_18[2U] = (1U 
                                                 & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_4_3);
    __Vtemp_62[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_4_3 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2178;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__loadFirstNextWide_19[0U] = __Vtemp_64[0U];
    vlSelfRef.__PVT__loadFirstNextWide_19[1U] = __Vtemp_64[1U];
    vlSelfRef.__PVT__loadFirstNextWide_19[2U] = (1U 
                                                 & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_4_0);
    __Vtemp_66[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_4_0 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2057;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__storeFirstNextWide_16[0U] = __Vtemp_68[0U];
    vlSelfRef.__PVT__storeFirstNextWide_16[1U] = __Vtemp_68[1U];
    vlSelfRef.__PVT__storeFirstNextWide_16[2U] = (1U 
                                                  & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_4_1);
    __Vtemp_70[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_4_1 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2096;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__storeFirstNextWide_17[0U] = __Vtemp_72[0U];
    vlSelfRef.__PVT__storeFirstNextWide_17[1U] = __Vtemp_72[1U];
    vlSelfRef.__PVT__storeFirstNextWide_17[2U] = (1U 
                                                  & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_4_2);
    __Vtemp_74[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_4_2 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2137;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__storeFirstNextWide_18[0U] = __Vtemp_76[0U];
    vlSelfRef.__PVT__storeFirstNextWide_18[1U] = __Vtemp_76[1U];
    vlSelfRef.__PVT__storeFirstNextWide_18[2U] = (1U 
                                                  & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_4_3);
    __Vtemp_78[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_4_3 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2178;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__storeFirstNextWide_19[0U] = __Vtemp_80[0U];
    vlSelfRef.__PVT__storeFirstNextWide_19[1U] = __Vtemp_80[1U];
    vlSelfRef.__PVT__storeFirstNextWide_19[2U] = (1U 
                                                  & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_4_0);
    __Vtemp_82[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_4_0 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21030;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.__PVT__strictWriteReadNextWide_16[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_16[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_16[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_4_1);
    __Vtemp_86[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_4_1 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21446;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.__PVT__strictWriteReadNextWide_17[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_17[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_17[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_4_2);
    __Vtemp_90[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_4_2 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21882;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.__PVT__strictWriteReadNextWide_18[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_18[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_18[2U] 
        = (1U & __Vtemp_92[2U]);
    __Vtemp_94[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_4_3);
    __Vtemp_94[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_4_3 
                              >> 0x20U));
    __Vtemp_94[2U] = 0U;
    __Vtemp_95[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_22318;
    __Vtemp_95[1U] = 0U;
    __Vtemp_95[2U] = 0U;
    VL_ADD_W(3, __Vtemp_96, __Vtemp_94, __Vtemp_95);
    vlSelfRef.__PVT__strictWriteReadNextWide_19[0U] 
        = __Vtemp_96[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_19[1U] 
        = __Vtemp_96[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_19[2U] 
        = (1U & __Vtemp_96[2U]);
    vlSelfRef.__PVT__allocate_4 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_4)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_4));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__49(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__49\n"); );
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
    vlSelfRef.__PVT___GEN_420 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_4)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_4));
    vlSelfRef.__PVT___T_381 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
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
    vlSelfRef.__PVT___T_89 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                              & ((IData)(vlSelfRef.__PVT__isRetiring_1) 
                                 & (IData)(vlSelfRef.__PVT__bucketValid_1)));
    __Vtemp_50[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_1_0);
    __Vtemp_50[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_1_0 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_749;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__loadFirstNextWide_4[0U] = __Vtemp_52[0U];
    vlSelfRef.__PVT__loadFirstNextWide_4[1U] = __Vtemp_52[1U];
    vlSelfRef.__PVT__loadFirstNextWide_4[2U] = (1U 
                                                & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_1_1);
    __Vtemp_54[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_1_1 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_788;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__loadFirstNextWide_5[0U] = __Vtemp_56[0U];
    vlSelfRef.__PVT__loadFirstNextWide_5[1U] = __Vtemp_56[1U];
    vlSelfRef.__PVT__loadFirstNextWide_5[2U] = (1U 
                                                & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_1_2);
    __Vtemp_58[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_1_2 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_829;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__loadFirstNextWide_6[0U] = __Vtemp_60[0U];
    vlSelfRef.__PVT__loadFirstNextWide_6[1U] = __Vtemp_60[1U];
    vlSelfRef.__PVT__loadFirstNextWide_6[2U] = (1U 
                                                & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_1_3);
    __Vtemp_62[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_1_3 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_870;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__loadFirstNextWide_7[0U] = __Vtemp_64[0U];
    vlSelfRef.__PVT__loadFirstNextWide_7[1U] = __Vtemp_64[1U];
    vlSelfRef.__PVT__loadFirstNextWide_7[2U] = (1U 
                                                & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_1_0);
    __Vtemp_66[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_1_0 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_749;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__storeFirstNextWide_4[0U] = __Vtemp_68[0U];
    vlSelfRef.__PVT__storeFirstNextWide_4[1U] = __Vtemp_68[1U];
    vlSelfRef.__PVT__storeFirstNextWide_4[2U] = (1U 
                                                 & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_1_1);
    __Vtemp_70[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_1_1 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_788;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__storeFirstNextWide_5[0U] = __Vtemp_72[0U];
    vlSelfRef.__PVT__storeFirstNextWide_5[1U] = __Vtemp_72[1U];
    vlSelfRef.__PVT__storeFirstNextWide_5[2U] = (1U 
                                                 & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_1_2);
    __Vtemp_74[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_1_2 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_829;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__storeFirstNextWide_6[0U] = __Vtemp_76[0U];
    vlSelfRef.__PVT__storeFirstNextWide_6[1U] = __Vtemp_76[1U];
    vlSelfRef.__PVT__storeFirstNextWide_6[2U] = (1U 
                                                 & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_1_3);
    __Vtemp_78[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_1_3 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_870;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__storeFirstNextWide_7[0U] = __Vtemp_80[0U];
    vlSelfRef.__PVT__storeFirstNextWide_7[1U] = __Vtemp_80[1U];
    vlSelfRef.__PVT__storeFirstNextWide_7[2U] = (1U 
                                                 & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_1_0);
    __Vtemp_82[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_1_0 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7638;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.__PVT__strictWriteReadNextWide_4[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_4[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_4[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_1_1);
    __Vtemp_86[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_1_1 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8054;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.__PVT__strictWriteReadNextWide_5[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_5[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_5[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_1_2);
    __Vtemp_90[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_1_2 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8490;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.__PVT__strictWriteReadNextWide_6[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_6[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_6[2U] 
        = (1U & __Vtemp_92[2U]);
    __Vtemp_94[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_1_3);
    __Vtemp_94[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_1_3 
                              >> 0x20U));
    __Vtemp_94[2U] = 0U;
    __Vtemp_95[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8926;
    __Vtemp_95[1U] = 0U;
    __Vtemp_95[2U] = 0U;
    VL_ADD_W(3, __Vtemp_96, __Vtemp_94, __Vtemp_95);
    vlSelfRef.__PVT__strictWriteReadNextWide_7[0U] 
        = __Vtemp_96[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_7[1U] 
        = __Vtemp_96[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_7[2U] 
        = (1U & __Vtemp_96[2U]);
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__50(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__50\n"); );
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
    vlSelfRef.__PVT__allocate_1 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_1)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_1));
    vlSelfRef.__PVT___GEN_165 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_1)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_1));
    vlSelfRef.__PVT___T_527 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_7) 
                                  & (IData)(vlSelfRef.bucketValid_7)));
    __Vtemp_2[0U] = (IData)(vlSelfRef.bucketLoadFirst_7_0);
    __Vtemp_2[1U] = (IData)((vlSelfRef.bucketLoadFirst_7_0 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3365;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__loadFirstNextWide_28[0U] = __Vtemp_4[0U];
    vlSelfRef.__PVT__loadFirstNextWide_28[1U] = __Vtemp_4[1U];
    vlSelfRef.__PVT__loadFirstNextWide_28[2U] = (1U 
                                                 & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.bucketLoadFirst_7_1);
    __Vtemp_6[1U] = (IData)((vlSelfRef.bucketLoadFirst_7_1 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3404;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__loadFirstNextWide_29[0U] = __Vtemp_8[0U];
    vlSelfRef.__PVT__loadFirstNextWide_29[1U] = __Vtemp_8[1U];
    vlSelfRef.__PVT__loadFirstNextWide_29[2U] = (1U 
                                                 & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.bucketLoadFirst_7_2);
    __Vtemp_10[1U] = (IData)((vlSelfRef.bucketLoadFirst_7_2 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3445;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__loadFirstNextWide_30[0U] = __Vtemp_12[0U];
    vlSelfRef.__PVT__loadFirstNextWide_30[1U] = __Vtemp_12[1U];
    vlSelfRef.__PVT__loadFirstNextWide_30[2U] = (1U 
                                                 & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.bucketLoadFirst_7_3);
    __Vtemp_14[1U] = (IData)((vlSelfRef.bucketLoadFirst_7_3 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3486;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__loadFirstNextWide_31[0U] = __Vtemp_16[0U];
    vlSelfRef.__PVT__loadFirstNextWide_31[1U] = __Vtemp_16[1U];
    vlSelfRef.__PVT__loadFirstNextWide_31[2U] = (1U 
                                                 & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.bucketStoreFirst_7_0);
    __Vtemp_18[1U] = (IData)((vlSelfRef.bucketStoreFirst_7_0 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3365;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__storeFirstNextWide_28[0U] = __Vtemp_20[0U];
    vlSelfRef.__PVT__storeFirstNextWide_28[1U] = __Vtemp_20[1U];
    vlSelfRef.__PVT__storeFirstNextWide_28[2U] = (1U 
                                                  & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.bucketStoreFirst_7_1);
    __Vtemp_22[1U] = (IData)((vlSelfRef.bucketStoreFirst_7_1 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3404;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__storeFirstNextWide_29[0U] = __Vtemp_24[0U];
    vlSelfRef.__PVT__storeFirstNextWide_29[1U] = __Vtemp_24[1U];
    vlSelfRef.__PVT__storeFirstNextWide_29[2U] = (1U 
                                                  & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.bucketStoreFirst_7_2);
    __Vtemp_26[1U] = (IData)((vlSelfRef.bucketStoreFirst_7_2 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3445;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__storeFirstNextWide_30[0U] = __Vtemp_28[0U];
    vlSelfRef.__PVT__storeFirstNextWide_30[1U] = __Vtemp_28[1U];
    vlSelfRef.__PVT__storeFirstNextWide_30[2U] = (1U 
                                                  & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.bucketStoreFirst_7_3);
    __Vtemp_30[1U] = (IData)((vlSelfRef.bucketStoreFirst_7_3 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3486;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__storeFirstNextWide_31[0U] = __Vtemp_32[0U];
    vlSelfRef.__PVT__storeFirstNextWide_31[1U] = __Vtemp_32[1U];
    vlSelfRef.__PVT__storeFirstNextWide_31[2U] = (1U 
                                                  & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_7_0);
    __Vtemp_34[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_7_0 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34422;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__strictWriteReadNextWide_28[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_28[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_28[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_7_1);
    __Vtemp_38[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_7_1 
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
    __Vtemp_42[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_7_2);
    __Vtemp_42[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_7_2 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_35274;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__strictWriteReadNextWide_30[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_30[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_30[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_7_3);
    __Vtemp_46[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_7_3 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_35710;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__strictWriteReadNextWide_31[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_31[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_31[2U] 
        = (1U & __Vtemp_48[2U]);
    vlSelfRef.__PVT__allocate_7 = ((~ (IData)(vlSelfRef.bucketValid_7)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_7));
    vlSelfRef.__PVT___GEN_675 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_7)) 
                                 | (IData)(vlSelfRef.bucketValid_7));
    vlSelfRef.__PVT___T_454 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_6) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_6)));
    __Vtemp_50[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_6_0);
    __Vtemp_50[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_6_0 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2929;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__loadFirstNextWide_24[0U] = __Vtemp_52[0U];
    vlSelfRef.__PVT__loadFirstNextWide_24[1U] = __Vtemp_52[1U];
    vlSelfRef.__PVT__loadFirstNextWide_24[2U] = (1U 
                                                 & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_6_1);
    __Vtemp_54[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_6_1 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2968;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__loadFirstNextWide_25[0U] = __Vtemp_56[0U];
    vlSelfRef.__PVT__loadFirstNextWide_25[1U] = __Vtemp_56[1U];
    vlSelfRef.__PVT__loadFirstNextWide_25[2U] = (1U 
                                                 & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_6_2);
    __Vtemp_58[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_6_2 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3009;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__loadFirstNextWide_26[0U] = __Vtemp_60[0U];
    vlSelfRef.__PVT__loadFirstNextWide_26[1U] = __Vtemp_60[1U];
    vlSelfRef.__PVT__loadFirstNextWide_26[2U] = (1U 
                                                 & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_6_3);
    __Vtemp_62[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_6_3 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3050;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__loadFirstNextWide_27[0U] = __Vtemp_64[0U];
    vlSelfRef.__PVT__loadFirstNextWide_27[1U] = __Vtemp_64[1U];
    vlSelfRef.__PVT__loadFirstNextWide_27[2U] = (1U 
                                                 & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_6_0);
    __Vtemp_66[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_6_0 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2929;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__storeFirstNextWide_24[0U] = __Vtemp_68[0U];
    vlSelfRef.__PVT__storeFirstNextWide_24[1U] = __Vtemp_68[1U];
    vlSelfRef.__PVT__storeFirstNextWide_24[2U] = (1U 
                                                  & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_6_1);
    __Vtemp_70[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_6_1 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2968;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__storeFirstNextWide_25[0U] = __Vtemp_72[0U];
    vlSelfRef.__PVT__storeFirstNextWide_25[1U] = __Vtemp_72[1U];
    vlSelfRef.__PVT__storeFirstNextWide_25[2U] = (1U 
                                                  & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_6_2);
    __Vtemp_74[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_6_2 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3009;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__storeFirstNextWide_26[0U] = __Vtemp_76[0U];
    vlSelfRef.__PVT__storeFirstNextWide_26[1U] = __Vtemp_76[1U];
    vlSelfRef.__PVT__storeFirstNextWide_26[2U] = (1U 
                                                  & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_6_3);
    __Vtemp_78[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_6_3 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3050;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__storeFirstNextWide_27[0U] = __Vtemp_80[0U];
    vlSelfRef.__PVT__storeFirstNextWide_27[1U] = __Vtemp_80[1U];
    vlSelfRef.__PVT__storeFirstNextWide_27[2U] = (1U 
                                                  & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_6_0);
    __Vtemp_82[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_6_0 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29958;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.__PVT__strictWriteReadNextWide_24[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_24[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_24[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_6_1);
    __Vtemp_86[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_6_1 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_30374;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.__PVT__strictWriteReadNextWide_25[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_25[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_25[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_6_2);
    __Vtemp_90[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_6_2 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_30810;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.__PVT__strictWriteReadNextWide_26[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_26[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_26[2U] 
        = (1U & __Vtemp_92[2U]);
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__51(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_0__51\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_6_3);
    __Vtemp_2[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_6_3 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_31246;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__strictWriteReadNextWide_27[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_27[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_27[2U] 
        = (1U & __Vtemp_4[2U]);
    vlSelfRef.__PVT__allocate_6 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_6)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_6));
    vlSelfRef.__PVT___GEN_590 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_6)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_6));
    vlSelfRef.__PVT___T_235 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_3) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_3)));
    __Vtemp_6[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_3_0);
    __Vtemp_6[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_3_0 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1621;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__loadFirstNextWide_12[0U] = __Vtemp_8[0U];
    vlSelfRef.__PVT__loadFirstNextWide_12[1U] = __Vtemp_8[1U];
    vlSelfRef.__PVT__loadFirstNextWide_12[2U] = (1U 
                                                 & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_3_1);
    __Vtemp_10[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_3_1 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1660;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__loadFirstNextWide_13[0U] = __Vtemp_12[0U];
    vlSelfRef.__PVT__loadFirstNextWide_13[1U] = __Vtemp_12[1U];
    vlSelfRef.__PVT__loadFirstNextWide_13[2U] = (1U 
                                                 & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_3_2);
    __Vtemp_14[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_3_2 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1701;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__loadFirstNextWide_14[0U] = __Vtemp_16[0U];
    vlSelfRef.__PVT__loadFirstNextWide_14[1U] = __Vtemp_16[1U];
    vlSelfRef.__PVT__loadFirstNextWide_14[2U] = (1U 
                                                 & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_3_3);
    __Vtemp_18[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_3_3 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1742;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__loadFirstNextWide_15[0U] = __Vtemp_20[0U];
    vlSelfRef.__PVT__loadFirstNextWide_15[1U] = __Vtemp_20[1U];
    vlSelfRef.__PVT__loadFirstNextWide_15[2U] = (1U 
                                                 & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_3_0);
    __Vtemp_22[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_3_0 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1621;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__storeFirstNextWide_12[0U] = __Vtemp_24[0U];
    vlSelfRef.__PVT__storeFirstNextWide_12[1U] = __Vtemp_24[1U];
    vlSelfRef.__PVT__storeFirstNextWide_12[2U] = (1U 
                                                  & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_3_1);
    __Vtemp_26[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_3_1 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1660;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__storeFirstNextWide_13[0U] = __Vtemp_28[0U];
    vlSelfRef.__PVT__storeFirstNextWide_13[1U] = __Vtemp_28[1U];
    vlSelfRef.__PVT__storeFirstNextWide_13[2U] = (1U 
                                                  & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_3_2);
    __Vtemp_30[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_3_2 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1701;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__storeFirstNextWide_14[0U] = __Vtemp_32[0U];
    vlSelfRef.__PVT__storeFirstNextWide_14[1U] = __Vtemp_32[1U];
    vlSelfRef.__PVT__storeFirstNextWide_14[2U] = (1U 
                                                  & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_3_3);
    __Vtemp_34[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_3_3 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1742;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__storeFirstNextWide_15[0U] = __Vtemp_36[0U];
    vlSelfRef.__PVT__storeFirstNextWide_15[1U] = __Vtemp_36[1U];
    vlSelfRef.__PVT__storeFirstNextWide_15[2U] = (1U 
                                                  & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_3_0);
    __Vtemp_38[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_3_0 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16566;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__strictWriteReadNextWide_12[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_12[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_12[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_3_1);
    __Vtemp_42[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_3_1 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16982;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__strictWriteReadNextWide_13[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_13[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_13[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_3_2);
    __Vtemp_46[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_3_2 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_17418;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__strictWriteReadNextWide_14[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_14[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_14[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_3_3);
    __Vtemp_50[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_3_3 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_17854;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__strictWriteReadNextWide_15[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_15[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_15[2U] 
        = (1U & __Vtemp_52[2U]);
    vlSelfRef.__PVT__allocate_3 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_3)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_3));
    vlSelfRef.__PVT___GEN_335 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_3)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_3));
    vlSelfRef.__PVT___T_16 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                              & ((IData)(vlSelfRef.__PVT__isRetiring) 
                                 & (IData)(vlSelfRef.bucketValid_0)));
    __Vtemp_54[0U] = (IData)(vlSelfRef.bucketLoadFirst_0_0);
    __Vtemp_54[1U] = (IData)((vlSelfRef.bucketLoadFirst_0_0 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_313;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__loadFirstNextWide[0U] = __Vtemp_56[0U];
    vlSelfRef.__PVT__loadFirstNextWide[1U] = __Vtemp_56[1U];
    vlSelfRef.__PVT__loadFirstNextWide[2U] = (1U & 
                                              __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.bucketLoadFirst_0_1);
    __Vtemp_58[1U] = (IData)((vlSelfRef.bucketLoadFirst_0_1 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_352;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__loadFirstNextWide_1[0U] = __Vtemp_60[0U];
    vlSelfRef.__PVT__loadFirstNextWide_1[1U] = __Vtemp_60[1U];
    vlSelfRef.__PVT__loadFirstNextWide_1[2U] = (1U 
                                                & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.bucketLoadFirst_0_2);
    __Vtemp_62[1U] = (IData)((vlSelfRef.bucketLoadFirst_0_2 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_393;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__loadFirstNextWide_2[0U] = __Vtemp_64[0U];
    vlSelfRef.__PVT__loadFirstNextWide_2[1U] = __Vtemp_64[1U];
    vlSelfRef.__PVT__loadFirstNextWide_2[2U] = (1U 
                                                & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.bucketLoadFirst_0_3);
    __Vtemp_66[1U] = (IData)((vlSelfRef.bucketLoadFirst_0_3 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_434;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__loadFirstNextWide_3[0U] = __Vtemp_68[0U];
    vlSelfRef.__PVT__loadFirstNextWide_3[1U] = __Vtemp_68[1U];
    vlSelfRef.__PVT__loadFirstNextWide_3[2U] = (1U 
                                                & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.bucketStoreFirst_0_0);
    __Vtemp_70[1U] = (IData)((vlSelfRef.bucketStoreFirst_0_0 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_313;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__storeFirstNextWide[0U] = __Vtemp_72[0U];
    vlSelfRef.__PVT__storeFirstNextWide[1U] = __Vtemp_72[1U];
    vlSelfRef.__PVT__storeFirstNextWide[2U] = (1U & 
                                               __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.bucketStoreFirst_0_1);
    __Vtemp_74[1U] = (IData)((vlSelfRef.bucketStoreFirst_0_1 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_352;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__storeFirstNextWide_1[0U] = __Vtemp_76[0U];
    vlSelfRef.__PVT__storeFirstNextWide_1[1U] = __Vtemp_76[1U];
    vlSelfRef.__PVT__storeFirstNextWide_1[2U] = (1U 
                                                 & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.bucketStoreFirst_0_2);
    __Vtemp_78[1U] = (IData)((vlSelfRef.bucketStoreFirst_0_2 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_393;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__storeFirstNextWide_2[0U] = __Vtemp_80[0U];
    vlSelfRef.__PVT__storeFirstNextWide_2[1U] = __Vtemp_80[1U];
    vlSelfRef.__PVT__storeFirstNextWide_2[2U] = (1U 
                                                 & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.bucketStoreFirst_0_3);
    __Vtemp_82[1U] = (IData)((vlSelfRef.bucketStoreFirst_0_3 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_434;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.__PVT__storeFirstNextWide_3[0U] = __Vtemp_84[0U];
    vlSelfRef.__PVT__storeFirstNextWide_3[1U] = __Vtemp_84[1U];
    vlSelfRef.__PVT__storeFirstNextWide_3[2U] = (1U 
                                                 & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_0_0);
    __Vtemp_86[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_0_0 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3174;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.__PVT__strictWriteReadNextWide[0U] = 
        __Vtemp_88[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide[1U] = 
        __Vtemp_88[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide[2U] = 
        (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_0_1);
    __Vtemp_90[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_0_1 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3590;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.__PVT__strictWriteReadNextWide_1[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_1[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_1[2U] 
        = (1U & __Vtemp_92[2U]);
}
