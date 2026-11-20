// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_GeometryBankProof.h"
#include "Vtb__Syms.h"

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_1__47(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_1__47\n"); );
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
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                              ? vlSelfRef.__PVT__bucketStore_3_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketStore_3_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentStoreNextWide_12[0U] = 
        __Vtemp_4[0U];
    vlSelfRef.__PVT__currentStoreNextWide_12[1U] = 
        __Vtemp_4[1U];
    vlSelfRef.__PVT__currentStoreNextWide_12[2U] = 
        (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                              ? vlSelfRef.__PVT__bucketStore_3_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketStore_3_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentStoreNextWide_13[0U] = 
        __Vtemp_8[0U];
    vlSelfRef.__PVT__currentStoreNextWide_13[1U] = 
        __Vtemp_8[1U];
    vlSelfRef.__PVT__currentStoreNextWide_13[2U] = 
        (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketStore_3_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketStore_3_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentStoreNextWide_14[0U] = 
        __Vtemp_12[0U];
    vlSelfRef.__PVT__currentStoreNextWide_14[1U] = 
        __Vtemp_12[1U];
    vlSelfRef.__PVT__currentStoreNextWide_14[2U] = 
        (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketStore_3_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketStore_3_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentStoreNextWide_15[0U] = 
        __Vtemp_16[0U];
    vlSelfRef.__PVT__currentStoreNextWide_15[1U] = 
        __Vtemp_16[1U];
    vlSelfRef.__PVT__currentStoreNextWide_15[2U] = 
        (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketFirstStore_3_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketFirstStore_3_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentFirstStoreNextWide_12[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_12[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_12[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketFirstStore_3_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketFirstStore_3_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentFirstStoreNextWide_13[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_13[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_13[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketFirstStore_3_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketFirstStore_3_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentFirstStoreNextWide_14[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_14[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_14[2U] 
        = (1U & __Vtemp_28[2U]);
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_1__48(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_1__48\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                              ? vlSelfRef.__PVT__bucketFirstStore_3_3
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketFirstStore_3_3
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentFirstStoreNextWide_15[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_15[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_15[2U] 
        = (1U & __Vtemp_4[2U]);
    vlSelfRef.__PVT___T_16 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                              & ((IData)(vlSelfRef.__PVT__isRetiring) 
                                 & (IData)(vlSelfRef.bucketValid_0)));
    __Vtemp_6[0U] = (IData)(vlSelfRef.bucketLoadFirst_0_0);
    __Vtemp_6[1U] = (IData)((vlSelfRef.bucketLoadFirst_0_0 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_313;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__loadFirstNextWide[0U] = __Vtemp_8[0U];
    vlSelfRef.__PVT__loadFirstNextWide[1U] = __Vtemp_8[1U];
    vlSelfRef.__PVT__loadFirstNextWide[2U] = (1U & 
                                              __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.bucketLoadFirst_0_1);
    __Vtemp_10[1U] = (IData)((vlSelfRef.bucketLoadFirst_0_1 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_352;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__loadFirstNextWide_1[0U] = __Vtemp_12[0U];
    vlSelfRef.__PVT__loadFirstNextWide_1[1U] = __Vtemp_12[1U];
    vlSelfRef.__PVT__loadFirstNextWide_1[2U] = (1U 
                                                & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.bucketLoadFirst_0_2);
    __Vtemp_14[1U] = (IData)((vlSelfRef.bucketLoadFirst_0_2 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_393;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__loadFirstNextWide_2[0U] = __Vtemp_16[0U];
    vlSelfRef.__PVT__loadFirstNextWide_2[1U] = __Vtemp_16[1U];
    vlSelfRef.__PVT__loadFirstNextWide_2[2U] = (1U 
                                                & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.bucketLoadFirst_0_3);
    __Vtemp_18[1U] = (IData)((vlSelfRef.bucketLoadFirst_0_3 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_434;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__loadFirstNextWide_3[0U] = __Vtemp_20[0U];
    vlSelfRef.__PVT__loadFirstNextWide_3[1U] = __Vtemp_20[1U];
    vlSelfRef.__PVT__loadFirstNextWide_3[2U] = (1U 
                                                & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.bucketStoreFirst_0_0);
    __Vtemp_22[1U] = (IData)((vlSelfRef.bucketStoreFirst_0_0 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_313;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__storeFirstNextWide[0U] = __Vtemp_24[0U];
    vlSelfRef.__PVT__storeFirstNextWide[1U] = __Vtemp_24[1U];
    vlSelfRef.__PVT__storeFirstNextWide[2U] = (1U & 
                                               __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.bucketStoreFirst_0_1);
    __Vtemp_26[1U] = (IData)((vlSelfRef.bucketStoreFirst_0_1 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_352;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__storeFirstNextWide_1[0U] = __Vtemp_28[0U];
    vlSelfRef.__PVT__storeFirstNextWide_1[1U] = __Vtemp_28[1U];
    vlSelfRef.__PVT__storeFirstNextWide_1[2U] = (1U 
                                                 & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.bucketStoreFirst_0_2);
    __Vtemp_30[1U] = (IData)((vlSelfRef.bucketStoreFirst_0_2 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_393;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__storeFirstNextWide_2[0U] = __Vtemp_32[0U];
    vlSelfRef.__PVT__storeFirstNextWide_2[1U] = __Vtemp_32[1U];
    vlSelfRef.__PVT__storeFirstNextWide_2[2U] = (1U 
                                                 & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.bucketStoreFirst_0_3);
    __Vtemp_34[1U] = (IData)((vlSelfRef.bucketStoreFirst_0_3 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_434;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__storeFirstNextWide_3[0U] = __Vtemp_36[0U];
    vlSelfRef.__PVT__storeFirstNextWide_3[1U] = __Vtemp_36[1U];
    vlSelfRef.__PVT__storeFirstNextWide_3[2U] = (1U 
                                                 & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_0_0);
    __Vtemp_38[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_0_0 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3174;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__strictWriteReadNextWide[0U] = 
        __Vtemp_40[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide[1U] = 
        __Vtemp_40[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide[2U] = 
        (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_0_1);
    __Vtemp_42[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_0_1 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3590;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__strictWriteReadNextWide_1[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_1[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_1[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_0_2);
    __Vtemp_46[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_0_2 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_4026;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__strictWriteReadNextWide_2[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_2[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_2[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_0_3);
    __Vtemp_50[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_0_3 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_4462;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__strictWriteReadNextWide_3[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_3[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_3[2U] 
        = (1U & __Vtemp_52[2U]);
    vlSelfRef.__PVT__allocate = ((~ (IData)(vlSelfRef.bucketValid_0)) 
                                 & (IData)(vlSelfRef.__PVT__isCurrent));
    vlSelfRef.__PVT___GEN_80 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                 & (IData)(vlSelfRef.__PVT__isCurrent)) 
                                | (IData)(vlSelfRef.bucketValid_0));
    vlSelfRef.__PVT___T_162 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_2) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_2)));
    __Vtemp_54[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_2_0);
    __Vtemp_54[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_2_0 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1185;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__loadFirstNextWide_8[0U] = __Vtemp_56[0U];
    vlSelfRef.__PVT__loadFirstNextWide_8[1U] = __Vtemp_56[1U];
    vlSelfRef.__PVT__loadFirstNextWide_8[2U] = (1U 
                                                & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_2_1);
    __Vtemp_58[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_2_1 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1224;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__loadFirstNextWide_9[0U] = __Vtemp_60[0U];
    vlSelfRef.__PVT__loadFirstNextWide_9[1U] = __Vtemp_60[1U];
    vlSelfRef.__PVT__loadFirstNextWide_9[2U] = (1U 
                                                & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_2_2);
    __Vtemp_62[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_2_2 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1265;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__loadFirstNextWide_10[0U] = __Vtemp_64[0U];
    vlSelfRef.__PVT__loadFirstNextWide_10[1U] = __Vtemp_64[1U];
    vlSelfRef.__PVT__loadFirstNextWide_10[2U] = (1U 
                                                 & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_2_3);
    __Vtemp_66[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_2_3 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1306;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__loadFirstNextWide_11[0U] = __Vtemp_68[0U];
    vlSelfRef.__PVT__loadFirstNextWide_11[1U] = __Vtemp_68[1U];
    vlSelfRef.__PVT__loadFirstNextWide_11[2U] = (1U 
                                                 & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_2_0);
    __Vtemp_70[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_2_0 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1185;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__storeFirstNextWide_8[0U] = __Vtemp_72[0U];
    vlSelfRef.__PVT__storeFirstNextWide_8[1U] = __Vtemp_72[1U];
    vlSelfRef.__PVT__storeFirstNextWide_8[2U] = (1U 
                                                 & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_2_1);
    __Vtemp_74[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_2_1 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1224;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__storeFirstNextWide_9[0U] = __Vtemp_76[0U];
    vlSelfRef.__PVT__storeFirstNextWide_9[1U] = __Vtemp_76[1U];
    vlSelfRef.__PVT__storeFirstNextWide_9[2U] = (1U 
                                                 & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_2_2);
    __Vtemp_78[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_2_2 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1265;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__storeFirstNextWide_10[0U] = __Vtemp_80[0U];
    vlSelfRef.__PVT__storeFirstNextWide_10[1U] = __Vtemp_80[1U];
    vlSelfRef.__PVT__storeFirstNextWide_10[2U] = (1U 
                                                  & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_2_3);
    __Vtemp_82[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_2_3 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1306;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.__PVT__storeFirstNextWide_11[0U] = __Vtemp_84[0U];
    vlSelfRef.__PVT__storeFirstNextWide_11[1U] = __Vtemp_84[1U];
    vlSelfRef.__PVT__storeFirstNextWide_11[2U] = (1U 
                                                  & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_2_0);
    __Vtemp_86[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_2_0 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12102;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.__PVT__strictWriteReadNextWide_8[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_8[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_8[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_2_1);
    __Vtemp_90[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_2_1 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12518;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.__PVT__strictWriteReadNextWide_9[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_9[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_9[2U] 
        = (1U & __Vtemp_92[2U]);
    __Vtemp_94[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_2_2);
    __Vtemp_94[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_2_2 
                              >> 0x20U));
    __Vtemp_94[2U] = 0U;
    __Vtemp_95[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12954;
    __Vtemp_95[1U] = 0U;
    __Vtemp_95[2U] = 0U;
    VL_ADD_W(3, __Vtemp_96, __Vtemp_94, __Vtemp_95);
    vlSelfRef.__PVT__strictWriteReadNextWide_10[0U] 
        = __Vtemp_96[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_10[1U] 
        = __Vtemp_96[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_10[2U] 
        = (1U & __Vtemp_96[2U]);
    __Vtemp_98[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_2_3);
    __Vtemp_98[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_2_3 
                              >> 0x20U));
    __Vtemp_98[2U] = 0U;
    __Vtemp_99[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_13390;
    __Vtemp_99[1U] = 0U;
    __Vtemp_99[2U] = 0U;
    VL_ADD_W(3, __Vtemp_100, __Vtemp_98, __Vtemp_99);
    vlSelfRef.__PVT__strictWriteReadNextWide_11[0U] 
        = __Vtemp_100[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_11[1U] 
        = __Vtemp_100[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_11[2U] 
        = (1U & __Vtemp_100[2U]);
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_1__49(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_1__49\n"); );
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
    vlSelfRef.__PVT__allocate_2 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_2)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_2));
    vlSelfRef.__PVT___GEN_250 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_2)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_2));
    vlSelfRef.__PVT___T_308 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_4) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_4)));
    __Vtemp_2[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_4_0);
    __Vtemp_2[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_4_0 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2057;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__loadFirstNextWide_16[0U] = __Vtemp_4[0U];
    vlSelfRef.__PVT__loadFirstNextWide_16[1U] = __Vtemp_4[1U];
    vlSelfRef.__PVT__loadFirstNextWide_16[2U] = (1U 
                                                 & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_4_1);
    __Vtemp_6[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_4_1 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2096;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__loadFirstNextWide_17[0U] = __Vtemp_8[0U];
    vlSelfRef.__PVT__loadFirstNextWide_17[1U] = __Vtemp_8[1U];
    vlSelfRef.__PVT__loadFirstNextWide_17[2U] = (1U 
                                                 & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_4_2);
    __Vtemp_10[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_4_2 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2137;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__loadFirstNextWide_18[0U] = __Vtemp_12[0U];
    vlSelfRef.__PVT__loadFirstNextWide_18[1U] = __Vtemp_12[1U];
    vlSelfRef.__PVT__loadFirstNextWide_18[2U] = (1U 
                                                 & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_4_3);
    __Vtemp_14[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_4_3 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2178;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__loadFirstNextWide_19[0U] = __Vtemp_16[0U];
    vlSelfRef.__PVT__loadFirstNextWide_19[1U] = __Vtemp_16[1U];
    vlSelfRef.__PVT__loadFirstNextWide_19[2U] = (1U 
                                                 & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_4_0);
    __Vtemp_18[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_4_0 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2057;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__storeFirstNextWide_16[0U] = __Vtemp_20[0U];
    vlSelfRef.__PVT__storeFirstNextWide_16[1U] = __Vtemp_20[1U];
    vlSelfRef.__PVT__storeFirstNextWide_16[2U] = (1U 
                                                  & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_4_1);
    __Vtemp_22[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_4_1 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2096;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__storeFirstNextWide_17[0U] = __Vtemp_24[0U];
    vlSelfRef.__PVT__storeFirstNextWide_17[1U] = __Vtemp_24[1U];
    vlSelfRef.__PVT__storeFirstNextWide_17[2U] = (1U 
                                                  & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_4_2);
    __Vtemp_26[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_4_2 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2137;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__storeFirstNextWide_18[0U] = __Vtemp_28[0U];
    vlSelfRef.__PVT__storeFirstNextWide_18[1U] = __Vtemp_28[1U];
    vlSelfRef.__PVT__storeFirstNextWide_18[2U] = (1U 
                                                  & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_4_3);
    __Vtemp_30[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_4_3 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2178;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__storeFirstNextWide_19[0U] = __Vtemp_32[0U];
    vlSelfRef.__PVT__storeFirstNextWide_19[1U] = __Vtemp_32[1U];
    vlSelfRef.__PVT__storeFirstNextWide_19[2U] = (1U 
                                                  & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_4_0);
    __Vtemp_34[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_4_0 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21030;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__strictWriteReadNextWide_16[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_16[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_16[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_4_1);
    __Vtemp_38[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_4_1 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21446;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__strictWriteReadNextWide_17[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_17[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_17[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_4_2);
    __Vtemp_42[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_4_2 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21882;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__strictWriteReadNextWide_18[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_18[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_18[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_4_3);
    __Vtemp_46[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_4_3 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_22318;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__strictWriteReadNextWide_19[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_19[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_19[2U] 
        = (1U & __Vtemp_48[2U]);
    vlSelfRef.__PVT__allocate_4 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_4)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_4));
    vlSelfRef.__PVT___GEN_420 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_4)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_4));
    vlSelfRef.__PVT___T_381 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_5) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_5)));
    __Vtemp_50[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_5_0);
    __Vtemp_50[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_5_0 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2493;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__loadFirstNextWide_20[0U] = __Vtemp_52[0U];
    vlSelfRef.__PVT__loadFirstNextWide_20[1U] = __Vtemp_52[1U];
    vlSelfRef.__PVT__loadFirstNextWide_20[2U] = (1U 
                                                 & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_5_1);
    __Vtemp_54[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_5_1 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2532;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__loadFirstNextWide_21[0U] = __Vtemp_56[0U];
    vlSelfRef.__PVT__loadFirstNextWide_21[1U] = __Vtemp_56[1U];
    vlSelfRef.__PVT__loadFirstNextWide_21[2U] = (1U 
                                                 & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_5_2);
    __Vtemp_58[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_5_2 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2573;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__loadFirstNextWide_22[0U] = __Vtemp_60[0U];
    vlSelfRef.__PVT__loadFirstNextWide_22[1U] = __Vtemp_60[1U];
    vlSelfRef.__PVT__loadFirstNextWide_22[2U] = (1U 
                                                 & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_5_3);
    __Vtemp_62[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_5_3 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2614;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__loadFirstNextWide_23[0U] = __Vtemp_64[0U];
    vlSelfRef.__PVT__loadFirstNextWide_23[1U] = __Vtemp_64[1U];
    vlSelfRef.__PVT__loadFirstNextWide_23[2U] = (1U 
                                                 & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_5_0);
    __Vtemp_66[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_5_0 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2493;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__storeFirstNextWide_20[0U] = __Vtemp_68[0U];
    vlSelfRef.__PVT__storeFirstNextWide_20[1U] = __Vtemp_68[1U];
    vlSelfRef.__PVT__storeFirstNextWide_20[2U] = (1U 
                                                  & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_5_1);
    __Vtemp_70[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_5_1 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2532;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__storeFirstNextWide_21[0U] = __Vtemp_72[0U];
    vlSelfRef.__PVT__storeFirstNextWide_21[1U] = __Vtemp_72[1U];
    vlSelfRef.__PVT__storeFirstNextWide_21[2U] = (1U 
                                                  & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_5_2);
    __Vtemp_74[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_5_2 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2573;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__storeFirstNextWide_22[0U] = __Vtemp_76[0U];
    vlSelfRef.__PVT__storeFirstNextWide_22[1U] = __Vtemp_76[1U];
    vlSelfRef.__PVT__storeFirstNextWide_22[2U] = (1U 
                                                  & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_5_3);
    __Vtemp_78[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_5_3 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2614;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__storeFirstNextWide_23[0U] = __Vtemp_80[0U];
    vlSelfRef.__PVT__storeFirstNextWide_23[1U] = __Vtemp_80[1U];
    vlSelfRef.__PVT__storeFirstNextWide_23[2U] = (1U 
                                                  & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_5_0);
    __Vtemp_82[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_5_0 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25494;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.__PVT__strictWriteReadNextWide_20[0U] 
        = __Vtemp_84[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_20[1U] 
        = __Vtemp_84[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_20[2U] 
        = (1U & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_5_1);
    __Vtemp_86[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_5_1 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25910;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.__PVT__strictWriteReadNextWide_21[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_21[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_21[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_5_2);
    __Vtemp_90[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_5_2 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_26346;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.__PVT__strictWriteReadNextWide_22[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_22[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_22[2U] 
        = (1U & __Vtemp_92[2U]);
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_1__50(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_1__50\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_5_3);
    __Vtemp_2[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_5_3 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_26782;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__strictWriteReadNextWide_23[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_23[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_23[2U] 
        = (1U & __Vtemp_4[2U]);
    vlSelfRef.__PVT__allocate_5 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_5)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_5));
    vlSelfRef.__PVT___GEN_505 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_5)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_5));
    vlSelfRef.__PVT___T_89 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                              & ((IData)(vlSelfRef.__PVT__isRetiring_1) 
                                 & (IData)(vlSelfRef.__PVT__bucketValid_1)));
    __Vtemp_6[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_1_0);
    __Vtemp_6[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_1_0 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_749;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__loadFirstNextWide_4[0U] = __Vtemp_8[0U];
    vlSelfRef.__PVT__loadFirstNextWide_4[1U] = __Vtemp_8[1U];
    vlSelfRef.__PVT__loadFirstNextWide_4[2U] = (1U 
                                                & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_1_1);
    __Vtemp_10[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_1_1 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_788;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__loadFirstNextWide_5[0U] = __Vtemp_12[0U];
    vlSelfRef.__PVT__loadFirstNextWide_5[1U] = __Vtemp_12[1U];
    vlSelfRef.__PVT__loadFirstNextWide_5[2U] = (1U 
                                                & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_1_2);
    __Vtemp_14[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_1_2 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_829;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__loadFirstNextWide_6[0U] = __Vtemp_16[0U];
    vlSelfRef.__PVT__loadFirstNextWide_6[1U] = __Vtemp_16[1U];
    vlSelfRef.__PVT__loadFirstNextWide_6[2U] = (1U 
                                                & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_1_3);
    __Vtemp_18[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_1_3 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_870;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__loadFirstNextWide_7[0U] = __Vtemp_20[0U];
    vlSelfRef.__PVT__loadFirstNextWide_7[1U] = __Vtemp_20[1U];
    vlSelfRef.__PVT__loadFirstNextWide_7[2U] = (1U 
                                                & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_1_0);
    __Vtemp_22[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_1_0 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_749;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__storeFirstNextWide_4[0U] = __Vtemp_24[0U];
    vlSelfRef.__PVT__storeFirstNextWide_4[1U] = __Vtemp_24[1U];
    vlSelfRef.__PVT__storeFirstNextWide_4[2U] = (1U 
                                                 & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_1_1);
    __Vtemp_26[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_1_1 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_788;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__storeFirstNextWide_5[0U] = __Vtemp_28[0U];
    vlSelfRef.__PVT__storeFirstNextWide_5[1U] = __Vtemp_28[1U];
    vlSelfRef.__PVT__storeFirstNextWide_5[2U] = (1U 
                                                 & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_1_2);
    __Vtemp_30[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_1_2 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_829;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__storeFirstNextWide_6[0U] = __Vtemp_32[0U];
    vlSelfRef.__PVT__storeFirstNextWide_6[1U] = __Vtemp_32[1U];
    vlSelfRef.__PVT__storeFirstNextWide_6[2U] = (1U 
                                                 & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_1_3);
    __Vtemp_34[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_1_3 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_870;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__storeFirstNextWide_7[0U] = __Vtemp_36[0U];
    vlSelfRef.__PVT__storeFirstNextWide_7[1U] = __Vtemp_36[1U];
    vlSelfRef.__PVT__storeFirstNextWide_7[2U] = (1U 
                                                 & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_1_0);
    __Vtemp_38[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_1_0 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7638;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__strictWriteReadNextWide_4[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_4[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_4[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_1_1);
    __Vtemp_42[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_1_1 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8054;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__strictWriteReadNextWide_5[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_5[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_5[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_1_2);
    __Vtemp_46[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_1_2 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8490;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__strictWriteReadNextWide_6[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_6[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_6[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_1_3);
    __Vtemp_50[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_1_3 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_8926;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__strictWriteReadNextWide_7[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_7[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_7[2U] 
        = (1U & __Vtemp_52[2U]);
    vlSelfRef.__PVT__allocate_1 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_1)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_1));
    vlSelfRef.__PVT___GEN_165 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_1)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_1));
    vlSelfRef.__PVT___T_527 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_7) 
                                  & (IData)(vlSelfRef.bucketValid_7)));
    __Vtemp_54[0U] = (IData)(vlSelfRef.bucketLoadFirst_7_0);
    __Vtemp_54[1U] = (IData)((vlSelfRef.bucketLoadFirst_7_0 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3365;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__loadFirstNextWide_28[0U] = __Vtemp_56[0U];
    vlSelfRef.__PVT__loadFirstNextWide_28[1U] = __Vtemp_56[1U];
    vlSelfRef.__PVT__loadFirstNextWide_28[2U] = (1U 
                                                 & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(vlSelfRef.bucketLoadFirst_7_1);
    __Vtemp_58[1U] = (IData)((vlSelfRef.bucketLoadFirst_7_1 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3404;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__loadFirstNextWide_29[0U] = __Vtemp_60[0U];
    vlSelfRef.__PVT__loadFirstNextWide_29[1U] = __Vtemp_60[1U];
    vlSelfRef.__PVT__loadFirstNextWide_29[2U] = (1U 
                                                 & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.bucketLoadFirst_7_2);
    __Vtemp_62[1U] = (IData)((vlSelfRef.bucketLoadFirst_7_2 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3445;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__loadFirstNextWide_30[0U] = __Vtemp_64[0U];
    vlSelfRef.__PVT__loadFirstNextWide_30[1U] = __Vtemp_64[1U];
    vlSelfRef.__PVT__loadFirstNextWide_30[2U] = (1U 
                                                 & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.bucketLoadFirst_7_3);
    __Vtemp_66[1U] = (IData)((vlSelfRef.bucketLoadFirst_7_3 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3486;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__loadFirstNextWide_31[0U] = __Vtemp_68[0U];
    vlSelfRef.__PVT__loadFirstNextWide_31[1U] = __Vtemp_68[1U];
    vlSelfRef.__PVT__loadFirstNextWide_31[2U] = (1U 
                                                 & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.bucketStoreFirst_7_0);
    __Vtemp_70[1U] = (IData)((vlSelfRef.bucketStoreFirst_7_0 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3365;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__storeFirstNextWide_28[0U] = __Vtemp_72[0U];
    vlSelfRef.__PVT__storeFirstNextWide_28[1U] = __Vtemp_72[1U];
    vlSelfRef.__PVT__storeFirstNextWide_28[2U] = (1U 
                                                  & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.bucketStoreFirst_7_1);
    __Vtemp_74[1U] = (IData)((vlSelfRef.bucketStoreFirst_7_1 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3404;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__storeFirstNextWide_29[0U] = __Vtemp_76[0U];
    vlSelfRef.__PVT__storeFirstNextWide_29[1U] = __Vtemp_76[1U];
    vlSelfRef.__PVT__storeFirstNextWide_29[2U] = (1U 
                                                  & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.bucketStoreFirst_7_2);
    __Vtemp_78[1U] = (IData)((vlSelfRef.bucketStoreFirst_7_2 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3445;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__storeFirstNextWide_30[0U] = __Vtemp_80[0U];
    vlSelfRef.__PVT__storeFirstNextWide_30[1U] = __Vtemp_80[1U];
    vlSelfRef.__PVT__storeFirstNextWide_30[2U] = (1U 
                                                  & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.bucketStoreFirst_7_3);
    __Vtemp_82[1U] = (IData)((vlSelfRef.bucketStoreFirst_7_3 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3486;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.__PVT__storeFirstNextWide_31[0U] = __Vtemp_84[0U];
    vlSelfRef.__PVT__storeFirstNextWide_31[1U] = __Vtemp_84[1U];
    vlSelfRef.__PVT__storeFirstNextWide_31[2U] = (1U 
                                                  & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_7_0);
    __Vtemp_86[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_7_0 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34422;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.__PVT__strictWriteReadNextWide_28[0U] 
        = __Vtemp_88[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_28[1U] 
        = __Vtemp_88[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_28[2U] 
        = (1U & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_7_1);
    __Vtemp_90[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_7_1 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34838;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.__PVT__strictWriteReadNextWide_29[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_29[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_29[2U] 
        = (1U & __Vtemp_92[2U]);
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_1__51(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_1__51\n"); );
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
    __Vtemp_2[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_7_2);
    __Vtemp_2[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_7_2 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_35274;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__strictWriteReadNextWide_30[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_30[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_30[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.bucketStrictWriteRead_7_3);
    __Vtemp_6[1U] = (IData)((vlSelfRef.bucketStrictWriteRead_7_3 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_35710;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__strictWriteReadNextWide_31[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_31[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_31[2U] 
        = (1U & __Vtemp_8[2U]);
    vlSelfRef.__PVT__allocate_7 = ((~ (IData)(vlSelfRef.bucketValid_7)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_7));
    vlSelfRef.__PVT___GEN_675 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_7)) 
                                 | (IData)(vlSelfRef.bucketValid_7));
    vlSelfRef.__PVT___T_454 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_6) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_6)));
    __Vtemp_10[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_6_0);
    __Vtemp_10[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_6_0 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2929;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__loadFirstNextWide_24[0U] = __Vtemp_12[0U];
    vlSelfRef.__PVT__loadFirstNextWide_24[1U] = __Vtemp_12[1U];
    vlSelfRef.__PVT__loadFirstNextWide_24[2U] = (1U 
                                                 & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_6_1);
    __Vtemp_14[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_6_1 
                              >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_2968;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__loadFirstNextWide_25[0U] = __Vtemp_16[0U];
    vlSelfRef.__PVT__loadFirstNextWide_25[1U] = __Vtemp_16[1U];
    vlSelfRef.__PVT__loadFirstNextWide_25[2U] = (1U 
                                                 & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_6_2);
    __Vtemp_18[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_6_2 
                              >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3009;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__loadFirstNextWide_26[0U] = __Vtemp_20[0U];
    vlSelfRef.__PVT__loadFirstNextWide_26[1U] = __Vtemp_20[1U];
    vlSelfRef.__PVT__loadFirstNextWide_26[2U] = (1U 
                                                 & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_6_3);
    __Vtemp_22[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_6_3 
                              >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_3050;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__loadFirstNextWide_27[0U] = __Vtemp_24[0U];
    vlSelfRef.__PVT__loadFirstNextWide_27[1U] = __Vtemp_24[1U];
    vlSelfRef.__PVT__loadFirstNextWide_27[2U] = (1U 
                                                 & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_6_0);
    __Vtemp_26[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_6_0 
                              >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2929;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__storeFirstNextWide_24[0U] = __Vtemp_28[0U];
    vlSelfRef.__PVT__storeFirstNextWide_24[1U] = __Vtemp_28[1U];
    vlSelfRef.__PVT__storeFirstNextWide_24[2U] = (1U 
                                                  & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_6_1);
    __Vtemp_30[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_6_1 
                              >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_2968;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__storeFirstNextWide_25[0U] = __Vtemp_32[0U];
    vlSelfRef.__PVT__storeFirstNextWide_25[1U] = __Vtemp_32[1U];
    vlSelfRef.__PVT__storeFirstNextWide_25[2U] = (1U 
                                                  & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_6_2);
    __Vtemp_34[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_6_2 
                              >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3009;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__storeFirstNextWide_26[0U] = __Vtemp_36[0U];
    vlSelfRef.__PVT__storeFirstNextWide_26[1U] = __Vtemp_36[1U];
    vlSelfRef.__PVT__storeFirstNextWide_26[2U] = (1U 
                                                  & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_6_3);
    __Vtemp_38[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_6_3 
                              >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_3050;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__storeFirstNextWide_27[0U] = __Vtemp_40[0U];
    vlSelfRef.__PVT__storeFirstNextWide_27[1U] = __Vtemp_40[1U];
    vlSelfRef.__PVT__storeFirstNextWide_27[2U] = (1U 
                                                  & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_6_0);
    __Vtemp_42[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_6_0 
                              >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29958;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__strictWriteReadNextWide_24[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_24[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_24[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_6_1);
    __Vtemp_46[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_6_1 
                              >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_30374;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__strictWriteReadNextWide_25[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_25[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_25[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_6_2);
    __Vtemp_50[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_6_2 
                              >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_30810;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__strictWriteReadNextWide_26[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_26[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_26[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_6_3);
    __Vtemp_54[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_6_3 
                              >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_31246;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__strictWriteReadNextWide_27[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_27[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_27[2U] 
        = (1U & __Vtemp_56[2U]);
    vlSelfRef.__PVT__allocate_6 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_6)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_6));
    vlSelfRef.__PVT___GEN_590 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_6)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_6));
    vlSelfRef.__PVT___T_235 = ((IData)(vlSelfRef.__VdfgRegularize_h883887c0_0_634) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_3) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_3)));
    __Vtemp_58[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_3_0);
    __Vtemp_58[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_3_0 
                              >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1621;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__loadFirstNextWide_12[0U] = __Vtemp_60[0U];
    vlSelfRef.__PVT__loadFirstNextWide_12[1U] = __Vtemp_60[1U];
    vlSelfRef.__PVT__loadFirstNextWide_12[2U] = (1U 
                                                 & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_3_1);
    __Vtemp_62[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_3_1 
                              >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1660;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__loadFirstNextWide_13[0U] = __Vtemp_64[0U];
    vlSelfRef.__PVT__loadFirstNextWide_13[1U] = __Vtemp_64[1U];
    vlSelfRef.__PVT__loadFirstNextWide_13[2U] = (1U 
                                                 & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_3_2);
    __Vtemp_66[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_3_2 
                              >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1701;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__loadFirstNextWide_14[0U] = __Vtemp_68[0U];
    vlSelfRef.__PVT__loadFirstNextWide_14[1U] = __Vtemp_68[1U];
    vlSelfRef.__PVT__loadFirstNextWide_14[2U] = (1U 
                                                 & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(vlSelfRef.__PVT__bucketLoadFirst_3_3);
    __Vtemp_70[1U] = (IData)((vlSelfRef.__PVT__bucketLoadFirst_3_3 
                              >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSelfRef.__PVT___bucketLoadFirstDelta_T_1742;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__loadFirstNextWide_15[0U] = __Vtemp_72[0U];
    vlSelfRef.__PVT__loadFirstNextWide_15[1U] = __Vtemp_72[1U];
    vlSelfRef.__PVT__loadFirstNextWide_15[2U] = (1U 
                                                 & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_3_0);
    __Vtemp_74[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_3_0 
                              >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1621;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__storeFirstNextWide_12[0U] = __Vtemp_76[0U];
    vlSelfRef.__PVT__storeFirstNextWide_12[1U] = __Vtemp_76[1U];
    vlSelfRef.__PVT__storeFirstNextWide_12[2U] = (1U 
                                                  & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_3_1);
    __Vtemp_78[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_3_1 
                              >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1660;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__storeFirstNextWide_13[0U] = __Vtemp_80[0U];
    vlSelfRef.__PVT__storeFirstNextWide_13[1U] = __Vtemp_80[1U];
    vlSelfRef.__PVT__storeFirstNextWide_13[2U] = (1U 
                                                  & __Vtemp_80[2U]);
    __Vtemp_82[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_3_2);
    __Vtemp_82[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_3_2 
                              >> 0x20U));
    __Vtemp_82[2U] = 0U;
    __Vtemp_83[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1701;
    __Vtemp_83[1U] = 0U;
    __Vtemp_83[2U] = 0U;
    VL_ADD_W(3, __Vtemp_84, __Vtemp_82, __Vtemp_83);
    vlSelfRef.__PVT__storeFirstNextWide_14[0U] = __Vtemp_84[0U];
    vlSelfRef.__PVT__storeFirstNextWide_14[1U] = __Vtemp_84[1U];
    vlSelfRef.__PVT__storeFirstNextWide_14[2U] = (1U 
                                                  & __Vtemp_84[2U]);
    __Vtemp_86[0U] = (IData)(vlSelfRef.__PVT__bucketStoreFirst_3_3);
    __Vtemp_86[1U] = (IData)((vlSelfRef.__PVT__bucketStoreFirst_3_3 
                              >> 0x20U));
    __Vtemp_86[2U] = 0U;
    __Vtemp_87[0U] = vlSelfRef.__PVT___bucketStoreFirstDelta_T_1742;
    __Vtemp_87[1U] = 0U;
    __Vtemp_87[2U] = 0U;
    VL_ADD_W(3, __Vtemp_88, __Vtemp_86, __Vtemp_87);
    vlSelfRef.__PVT__storeFirstNextWide_15[0U] = __Vtemp_88[0U];
    vlSelfRef.__PVT__storeFirstNextWide_15[1U] = __Vtemp_88[1U];
    vlSelfRef.__PVT__storeFirstNextWide_15[2U] = (1U 
                                                  & __Vtemp_88[2U]);
    __Vtemp_90[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_3_0);
    __Vtemp_90[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_3_0 
                              >> 0x20U));
    __Vtemp_90[2U] = 0U;
    __Vtemp_91[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16566;
    __Vtemp_91[1U] = 0U;
    __Vtemp_91[2U] = 0U;
    VL_ADD_W(3, __Vtemp_92, __Vtemp_90, __Vtemp_91);
    vlSelfRef.__PVT__strictWriteReadNextWide_12[0U] 
        = __Vtemp_92[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_12[1U] 
        = __Vtemp_92[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_12[2U] 
        = (1U & __Vtemp_92[2U]);
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_1__52(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_1__52\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_3_1);
    __Vtemp_2[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_3_1 
                             >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16982;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__strictWriteReadNextWide_13[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_13[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_13[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_3_2);
    __Vtemp_6[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_3_2 
                             >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_17418;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__strictWriteReadNextWide_14[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_14[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_14[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(vlSelfRef.__PVT__bucketStrictWriteRead_3_3);
    __Vtemp_10[1U] = (IData)((vlSelfRef.__PVT__bucketStrictWriteRead_3_3 
                              >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_17854;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__strictWriteReadNextWide_15[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.__PVT__strictWriteReadNextWide_15[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.__PVT__strictWriteReadNextWide_15[2U] 
        = (1U & __Vtemp_12[2U]);
    vlSelfRef.__PVT__allocate_3 = ((~ (IData)(vlSelfRef.__PVT__bucketValid_3)) 
                                   & (IData)(vlSelfRef.__PVT__isCurrent_3));
    vlSelfRef.__PVT___GEN_335 = (((IData)(vlSymsp->TOP.tb__DOT__io_processCommit) 
                                  & (IData)(vlSelfRef.__PVT__isCurrent_3)) 
                                 | (IData)(vlSelfRef.__PVT__bucketValid_3));
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
                                                       | ((IData)(vlSelfRef.__PVT__isCurrent_7) 
                                                          & ((IData)(vlSelfRef.bucketValid_7) 
                                                             & ((vlSelfRef.bucketSeq_7 
                                                                 >> 8U) 
                                                                != 
                                                                (vlSymsp->TOP.tb__DOT__io_processSeq 
                                                                 >> 8U)))))))))));
    vlSelfRef.__PVT___GEN_2193 = ((~ (IData)(vlSelfRef.__PVT__resolving_7)) 
                                  & (IData)(vlSelfRef.buckets_valid_7));
    vlSelfRef.__PVT___canAccept_T_22 = (1U & ((~ (IData)(vlSelfRef.buckets_valid_7)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_7)));
    vlSelfRef.__PVT___GEN_2163 = ((~ (IData)(vlSelfRef.__PVT__resolving_5)) 
                                  & (IData)(vlSelfRef.__PVT__buckets_valid_5));
    vlSelfRef.__PVT___canAccept_T_16 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_5)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_5)));
    vlSelfRef.__PVT___GEN_2148 = ((~ (IData)(vlSelfRef.__PVT__resolving_4)) 
                                  & (IData)(vlSelfRef.__PVT__buckets_valid_4));
    vlSelfRef.__PVT___canAccept_T_13 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_4)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_4)));
    vlSelfRef.__PVT___GEN_2178 = ((~ (IData)(vlSelfRef.__PVT__resolving_6)) 
                                  & (IData)(vlSelfRef.__PVT__buckets_valid_6));
    vlSelfRef.__PVT___canAccept_T_19 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_6)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_6)));
    vlSelfRef.__PVT___GEN_2088 = ((~ (IData)(vlSelfRef.__PVT__resolving_0)) 
                                  & (IData)(vlSelfRef.buckets_valid_0));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_1__54(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_comb__TOP__tb__DOT__dut__DOT__candidate_1__54\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_7 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(0xfU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.buckets_seq_7 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_5 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(0xdU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_4 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(0xcU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_6 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(0xeU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_0 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(8U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_2 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(0xaU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_3 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(0xbU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_1 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(9U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__accepted_7 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_7));
    vlSelfRef.__PVT__accepted_5 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_5));
    vlSelfRef.__PVT__accepted_4 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_4));
    vlSelfRef.__PVT__accepted_6 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_6));
    vlSelfRef.__PVT__accepted = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                 & (IData)(vlSelfRef.__PVT__available_0));
    vlSelfRef.__PVT__accepted_2 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_2));
    vlSelfRef.__PVT__accepted_3 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_3));
    vlSelfRef.__PVT__accepted_1 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_1));
    vlSelfRef.__PVT___countOverflow_7_T_2 = ((IData)(vlSelfRef.__PVT__accepted_7) 
                                             & (IData)(vlSelfRef.__PVT___GEN_2193));
    vlSelfRef.__PVT___countOverflow_5_T_2 = ((IData)(vlSelfRef.__PVT__accepted_5) 
                                             & (IData)(vlSelfRef.__PVT___GEN_2163));
    vlSelfRef.__PVT___countOverflow_4_T_2 = ((IData)(vlSelfRef.__PVT__accepted_4) 
                                             & (IData)(vlSelfRef.__PVT___GEN_2148));
    vlSelfRef.__PVT___countOverflow_6_T_2 = ((IData)(vlSelfRef.__PVT__accepted_6) 
                                             & (IData)(vlSelfRef.__PVT___GEN_2178));
    vlSelfRef.__PVT___countOverflow_0_T_2 = ((IData)(vlSelfRef.__PVT__accepted) 
                                             & (IData)(vlSelfRef.__PVT___GEN_2088));
    vlSelfRef.__PVT___countOverflow_2_T_2 = ((IData)(vlSelfRef.__PVT__accepted_2) 
                                             & (IData)(vlSelfRef.__PVT___GEN_2118));
    vlSelfRef.__PVT___countOverflow_3_T_2 = ((IData)(vlSelfRef.__PVT__accepted_3) 
                                             & (IData)(vlSelfRef.__PVT___GEN_2133));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__0(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_requestCycleSum_0_T_1 
        = (vlSelfRef.buckets_requestCycleSum_0 + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_1_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_1 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_2_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_2 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_3_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_3 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_4_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_4 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_5_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_5 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_6_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_6 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_7_T_1 
        = (vlSelfRef.buckets_requestCycleSum_7 + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT__isRetiring = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                   == (0xffU & ((IData)(0x10U) 
                                                + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_1 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0x11U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_2 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0x12U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_3 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0x13U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_4 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0x14U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_5 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0x15U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_6 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0x16U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_7 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0x17U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__VdfgRegularize_h883887c0_0_634 = ((~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError)) 
                                                  & (IData)(vlSymsp->TOP.tb__DOT__io_safeAdvance));
    vlSelfRef.__PVT__io_queryMatch_0_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_0 
                                                  - 
                                                  ((IData)(0x10U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_1_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_1 
                                                  - 
                                                  ((IData)(0x10U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_2_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_2 
                                                  - 
                                                  ((IData)(0x10U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_3_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_3 
                                                  - 
                                                  ((IData)(0x10U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_4_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_4 
                                                  - 
                                                  ((IData)(0x10U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_5_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_5 
                                                  - 
                                                  ((IData)(0x10U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_6_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_6 
                                                  - 
                                                  ((IData)(0x10U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_7_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_7 
                                                  - 
                                                  ((IData)(0x10U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__1(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__io_queryMatch_8_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_8 
                                                  - 
                                                  ((IData)(0x10U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_9_offset = (0xffU 
                                               & (vlSymsp->TOP.tb__DOT__io_querySeq_9 
                                                  - 
                                                  ((IData)(0x10U) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_10_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_10 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_11_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_11 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_12_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_12 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_13_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_13 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_14_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_14 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_15_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_15 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_16_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_16 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_17_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_17 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_18_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_18 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_19_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_19 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_20_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_20 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_21_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_21 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_22_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_22 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_23_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_23 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_24_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_24 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_25_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_25 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_26_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_26 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_27_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_27 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__2(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__io_queryMatch_28_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_28 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_29_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_29 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_30_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_30 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_31_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_31 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_32_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_32 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_33_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_33 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_34_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_34 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_35_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_35 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_36_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_36 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_37_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_37 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_38_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_38 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_39_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_39 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_40_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_40 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_41_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_41 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_42_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_42 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_43_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_43 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_44_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_44 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_45_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_45 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_46_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_46 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_47_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_47 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__3(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__io_queryMatch_48_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_48 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_49_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_49 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_50_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_50 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_51_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_51 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_52_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_52 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_53_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_53 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_54_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_54 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_55_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_55 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_56_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_56 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_57_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_57 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_58_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_58 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_59_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_59 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_60_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_60 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_61_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_61 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_62_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_62 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_63_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_63 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_64_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_64 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_65_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_65 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_66_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_66 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_67_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_67 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__4(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__4\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__io_queryMatch_68_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_68 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_69_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_69 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_70_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_70 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_71_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_71 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_72_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_72 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_73_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_73 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_74_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_74 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_75_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_75 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_76_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_76 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_77_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_77 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_78_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_78 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_79_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_79 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_80_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_80 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_81_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_81 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_82_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_82 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_83_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_83 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_84_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_84 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_85_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_85 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_86_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_86 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_87_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_87 
                                                   - 
                                                   ((IData)(0x10U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__8(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__8\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                              ? vlSelfRef.bucketFirstStore_7_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                              ? vlSelfRef.bucketFirstStore_7_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketFirstStore_7_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.bucketValid_7)
                               ? vlSelfRef.bucketFirstStore_7_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.bucketValid_7)
                                ? vlSelfRef.bucketFirstStore_7_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[2U] 
        = (1U & __Vtemp_16[2U]);
    vlSelfRef.__PVT__retireSelect_0 = ((0xffU & ((IData)(0x10U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_1 = ((0xffU & ((IData)(0x11U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_2 = ((0xffU & ((IData)(0x12U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_3 = ((0xffU & ((IData)(0x13U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_4 = ((0xffU & ((IData)(0x14U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_5 = ((0xffU & ((IData)(0x15U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_6 = ((0xffU & ((IData)(0x16U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_7 = ((0xffU & ((IData)(0x17U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__isCurrent = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                  == (0xffU & ((IData)(0x10U) 
                                               + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_1 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0x11U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_2 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0x12U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_3 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0x13U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_4 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0x14U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_5 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0x15U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_6 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0x16U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_7 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0x17U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__70(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__70\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_95) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2628 
            = vlSymsp->TOP.tb__DOT__io_strictSources_77_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2620 
            = vlSymsp->TOP.tb__DOT__io_strictSources_76_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2621 
            = vlSymsp->TOP.tb__DOT__io_strictSources_76_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2622 
            = vlSymsp->TOP.tb__DOT__io_strictSources_76_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2623 
            = vlSymsp->TOP.tb__DOT__io_strictSources_76_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2624 
            = vlSymsp->TOP.tb__DOT__io_strictSources_77_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2619 
            = vlSymsp->TOP.tb__DOT__io_strictSources_76_key;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2628 
            = vlSymsp->TOP.tb__DOT__io_strictSources_76_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2620 
            = vlSymsp->TOP.tb__DOT__io_strictSources_77_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2621 
            = vlSymsp->TOP.tb__DOT__io_strictSources_77_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2622 
            = vlSymsp->TOP.tb__DOT__io_strictSources_77_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2623 
            = vlSymsp->TOP.tb__DOT__io_strictSources_77_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2624 
            = vlSymsp->TOP.tb__DOT__io_strictSources_76_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2619 
            = vlSymsp->TOP.tb__DOT__io_strictSources_77_key;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_96) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2635 
            = vlSymsp->TOP.tb__DOT__io_strictSources_79_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2636 
            = vlSymsp->TOP.tb__DOT__io_strictSources_79_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2637 
            = vlSymsp->TOP.tb__DOT__io_strictSources_79_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2638 
            = vlSymsp->TOP.tb__DOT__io_strictSources_79_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2630 
            = vlSymsp->TOP.tb__DOT__io_strictSources_78_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2631 
            = vlSymsp->TOP.tb__DOT__io_strictSources_78_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2632 
            = vlSymsp->TOP.tb__DOT__io_strictSources_78_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2633 
            = vlSymsp->TOP.tb__DOT__io_strictSources_78_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2634 
            = vlSymsp->TOP.tb__DOT__io_strictSources_79_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2629 
            = vlSymsp->TOP.tb__DOT__io_strictSources_78_key;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2635 
            = vlSymsp->TOP.tb__DOT__io_strictSources_78_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2636 
            = vlSymsp->TOP.tb__DOT__io_strictSources_78_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2637 
            = vlSymsp->TOP.tb__DOT__io_strictSources_78_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2638 
            = vlSymsp->TOP.tb__DOT__io_strictSources_78_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2630 
            = vlSymsp->TOP.tb__DOT__io_strictSources_79_counts_bytes;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2631 
            = vlSymsp->TOP.tb__DOT__io_strictSources_79_counts_words4;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2632 
            = vlSymsp->TOP.tb__DOT__io_strictSources_79_counts_words8;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2633 
            = vlSymsp->TOP.tb__DOT__io_strictSources_79_counts_lines;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2634 
            = vlSymsp->TOP.tb__DOT__io_strictSources_78_key;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2629 
            = vlSymsp->TOP.tb__DOT__io_strictSources_79_key;
    }
    vlSelfRef.__PVT__available_0 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(0x10U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_1 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(0x11U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_2 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(0x12U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_3 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(0x13U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_4 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(0x14U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_5 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(0x15U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_6 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(0x16U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__71(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__71\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_7 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(0x17U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.buckets_seq_7 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_3 
        = ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_21) 
           <= (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_31));
    vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_2 
        = ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_16) 
           <= (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_26));
    vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_8 
        = ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_158) 
           <= (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_168));
    vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_7 
        = ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_153) 
           <= (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_163));
    vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_3 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_21) 
           <= (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_31));
    vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_2 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_16) 
           <= (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_26));
    vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_8 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_158) 
           <= (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_168));
    vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_7 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_153) 
           <= (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_163));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_3 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_21) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_31));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_2 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_26));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_8 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_158) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_168));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_7 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_153) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_163));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_13 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_295) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_305));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_12 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_290) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_300));
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
}

VL_INLINE_OPT void Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__87(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___act_sequent__TOP__tb__DOT__dut__DOT__candidate_2__87\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_97) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2642 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2622;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2643 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2623;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2645 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2630;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2646 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2631;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2647 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2632;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2648 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2633;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2639 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2619;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2644 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2629;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2642 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2632;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2643 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2633;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2645 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2620;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2646 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2621;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2647 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2622;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2648 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2623;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2639 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2629;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2644 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2619;
    }
    vlSelfRef.__PVT___countOverflow_0_T_2 = ((IData)(vlSelfRef.__PVT__accepted) 
                                             & (IData)(vlSelfRef.__PVT___GEN_2088));
    vlSelfRef.__PVT___countOverflow_1_T_2 = ((IData)(vlSelfRef.__PVT__accepted_1) 
                                             & (IData)(vlSelfRef.__PVT___GEN_2103));
    vlSelfRef.__PVT___countOverflow_2_T_2 = ((IData)(vlSelfRef.__PVT__accepted_2) 
                                             & (IData)(vlSelfRef.__PVT___GEN_2118));
    vlSelfRef.__PVT___countOverflow_3_T_2 = ((IData)(vlSelfRef.__PVT__accepted_3) 
                                             & (IData)(vlSelfRef.__PVT___GEN_2133));
    vlSelfRef.__PVT___countOverflow_4_T_2 = ((IData)(vlSelfRef.__PVT__accepted_4) 
                                             & (IData)(vlSelfRef.__PVT___GEN_2148));
    vlSelfRef.__PVT___countOverflow_5_T_2 = ((IData)(vlSelfRef.__PVT__accepted_5) 
                                             & (IData)(vlSelfRef.__PVT___GEN_2163));
    vlSelfRef.__PVT___countOverflow_6_T_2 = ((IData)(vlSelfRef.__PVT__accepted_6) 
                                             & (IData)(vlSelfRef.__PVT___GEN_2178));
    vlSelfRef.__PVT___countOverflow_7_T_2 = ((IData)(vlSelfRef.__PVT__accepted_7) 
                                             & (IData)(vlSelfRef.__PVT___GEN_2193));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_283 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_719 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1155 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1591 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2027 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2463 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2899 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3335 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_4 
        = ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_46) 
           <= (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_41));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_301 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_737 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1173 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1609 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2045 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2481 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2917 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3353 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}
