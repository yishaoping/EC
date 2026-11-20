// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_GHBarrierBucketBank.h"
#include "Vtb__Syms.h"

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__0(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_count_7_T_1 = (1ULL + vlSelfRef.buckets_count_7);
    vlSelfRef.__PVT___buckets_requestCycleSum_0_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_0 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_1_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_1 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_2_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_2 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_3_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_3 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_4_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_4 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_5_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_5 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_6_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_6 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_7_T_1 
        = (vlSelfRef.buckets_requestCycleSum_7 + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_8_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_8 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_9_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_9 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_10_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_10 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_11_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_11 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_12_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_12 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_13_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_13 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_14_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_14 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_15_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_15 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.io_observe_7[0U] = (IData)(vlSelfRef.buckets_requestCycleSum_7);
    vlSelfRef.io_observe_7[1U] = (IData)((vlSelfRef.buckets_requestCycleSum_7 
                                          >> 0x20U));
    vlSelfRef.io_observe_7[2U] = (IData)(vlSelfRef.buckets_count_7);
    vlSelfRef.io_observe_7[3U] = (IData)((vlSelfRef.buckets_count_7 
                                          >> 0x20U));
    vlSelfRef.io_observe_7[4U] = vlSelfRef.buckets_seq_7;
    vlSelfRef.io_observe_7[5U] = vlSelfRef.buckets_valid_7;
    vlSelfRef.__PVT__resolving_0 = ((IData)(vlSelfRef.__PVT__buckets_valid_0) 
                                    & (vlSelfRef.__PVT__buckets_seq_0 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_1 = ((IData)(vlSelfRef.__PVT__buckets_valid_1) 
                                    & (vlSelfRef.__PVT__buckets_seq_1 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_2 = ((IData)(vlSelfRef.__PVT__buckets_valid_2) 
                                    & (vlSelfRef.__PVT__buckets_seq_2 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_3 = ((IData)(vlSelfRef.__PVT__buckets_valid_3) 
                                    & (vlSelfRef.__PVT__buckets_seq_3 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_4 = ((IData)(vlSelfRef.__PVT__buckets_valid_4) 
                                    & (vlSelfRef.__PVT__buckets_seq_4 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_5 = ((IData)(vlSelfRef.__PVT__buckets_valid_5) 
                                    & (vlSelfRef.__PVT__buckets_seq_5 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_6 = ((IData)(vlSelfRef.__PVT__buckets_valid_6) 
                                    & (vlSelfRef.__PVT__buckets_seq_6 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_7 = ((IData)(vlSelfRef.buckets_valid_7) 
                                    & (vlSelfRef.buckets_seq_7 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_8 = ((IData)(vlSelfRef.__PVT__buckets_valid_8) 
                                    & (vlSelfRef.__PVT__buckets_seq_8 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_9 = ((IData)(vlSelfRef.__PVT__buckets_valid_9) 
                                    & (vlSelfRef.__PVT__buckets_seq_9 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_10 = ((IData)(vlSelfRef.__PVT__buckets_valid_10) 
                                     & (vlSelfRef.__PVT__buckets_seq_10 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_11 = ((IData)(vlSelfRef.__PVT__buckets_valid_11) 
                                     & (vlSelfRef.__PVT__buckets_seq_11 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_12 = ((IData)(vlSelfRef.__PVT__buckets_valid_12) 
                                     & (vlSelfRef.__PVT__buckets_seq_12 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_13 = ((IData)(vlSelfRef.__PVT__buckets_valid_13) 
                                     & (vlSelfRef.__PVT__buckets_seq_13 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_14 = ((IData)(vlSelfRef.__PVT__buckets_valid_14) 
                                     & (vlSelfRef.__PVT__buckets_seq_14 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__1\n"); );
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
    vlSelfRef.__PVT__resolving_15 = ((IData)(vlSelfRef.__PVT__buckets_valid_15) 
                                     & (vlSelfRef.__PVT__buckets_seq_15 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__eventNeedsBucket = ((IData)(vlSymsp->TOP.tb__DOT__io_event_valid) 
                                         & (vlSymsp->TOP.tb__DOT__io_event_bits 
                                            > vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT___GEN_0 = ((~ (IData)(vlSelfRef.__PVT__resolving_0)) 
                               & (IData)(vlSelfRef.__PVT__buckets_valid_0));
    vlSelfRef.__PVT___canAccept_T_1 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_0)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_0)));
    vlSelfRef.__PVT___GEN_15 = ((~ (IData)(vlSelfRef.__PVT__resolving_1)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_1));
    vlSelfRef.__PVT___canAccept_T_4 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_1)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_1)));
    vlSelfRef.__PVT___GEN_30 = ((~ (IData)(vlSelfRef.__PVT__resolving_2)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_2));
    vlSelfRef.__PVT___canAccept_T_7 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_2)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_2)));
    vlSelfRef.__PVT___GEN_45 = ((~ (IData)(vlSelfRef.__PVT__resolving_3)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_3));
    vlSelfRef.__PVT___canAccept_T_10 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_3)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_3)));
    vlSelfRef.__PVT___GEN_60 = ((~ (IData)(vlSelfRef.__PVT__resolving_4)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_4));
    vlSelfRef.__PVT___canAccept_T_13 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_4)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_4)));
    vlSelfRef.__PVT___GEN_75 = ((~ (IData)(vlSelfRef.__PVT__resolving_5)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_5));
    vlSelfRef.__PVT___canAccept_T_16 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_5)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_5)));
    vlSelfRef.__PVT___GEN_90 = ((~ (IData)(vlSelfRef.__PVT__resolving_6)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_6));
    vlSelfRef.__PVT___canAccept_T_19 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_6)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_6)));
    vlSelfRef.__PVT___GEN_105 = ((~ (IData)(vlSelfRef.__PVT__resolving_7)) 
                                 & (IData)(vlSelfRef.buckets_valid_7));
    vlSelfRef.__PVT___canAccept_T_22 = (1U & ((~ (IData)(vlSelfRef.buckets_valid_7)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_7)));
    vlSelfRef.__PVT___GEN_120 = ((~ (IData)(vlSelfRef.__PVT__resolving_8)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_8));
    vlSelfRef.__PVT___canAccept_T_25 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_8)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_8)));
    vlSelfRef.__PVT___GEN_135 = ((~ (IData)(vlSelfRef.__PVT__resolving_9)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_9));
    vlSelfRef.__PVT___canAccept_T_28 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_9)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_9)));
    vlSelfRef.__PVT___GEN_150 = ((~ (IData)(vlSelfRef.__PVT__resolving_10)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_10));
    vlSelfRef.__PVT___canAccept_T_31 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_10)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_10)));
    vlSelfRef.__PVT___GEN_165 = ((~ (IData)(vlSelfRef.__PVT__resolving_11)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_11));
    vlSelfRef.__PVT___canAccept_T_34 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_11)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_11)));
    vlSelfRef.__PVT___GEN_180 = ((~ (IData)(vlSelfRef.__PVT__resolving_12)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_12));
    vlSelfRef.__PVT___canAccept_T_37 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_12)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_12)));
    vlSelfRef.__PVT___GEN_195 = ((~ (IData)(vlSelfRef.__PVT__resolving_13)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_13));
    vlSelfRef.__PVT___canAccept_T_40 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_13)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_13)));
    vlSelfRef.__PVT___GEN_210 = ((~ (IData)(vlSelfRef.__PVT__resolving_14)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_14));
    vlSelfRef.__PVT___canAccept_T_43 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_14)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_14)));
    __Vtemp_5[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                              ? vlSelfRef.__PVT__buckets_requestCycleSum_0
                              : 0ULL));
    __Vtemp_5[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_0
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
                               ? vlSelfRef.buckets_requestCycleSum_7
                               : 0ULL));
    __Vtemp_28[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_requestCycleSum_7
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
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_15
                               : 0ULL));
    __Vtemp_64[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_15
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
    vlSelfRef.io_resolvedRequest[0U] = __Vtemp_74[0U];
    vlSelfRef.io_resolvedRequest[1U] = __Vtemp_74[1U];
    vlSelfRef.io_resolvedRequest[2U] = (0xfU & __Vtemp_74[2U]);
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__2\n"); );
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
    vlSelfRef.__PVT___GEN_225 = ((~ (IData)(vlSelfRef.__PVT__resolving_15)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_15));
    __Vtemp_5[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                              ? vlSelfRef.__PVT__buckets_count_0
                              : 0ULL));
    __Vtemp_5[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_count_0
                               : 0ULL) >> 0x20U));
    __Vtemp_5[2U] = 0U;
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_1)
                              ? vlSelfRef.__PVT__buckets_count_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_1)
                               ? vlSelfRef.__PVT__buckets_count_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    VL_ADD_W(3, __Vtemp_7, __Vtemp_5, __Vtemp_6);
    __Vtemp_9[0U] = __Vtemp_7[0U];
    __Vtemp_9[1U] = __Vtemp_7[1U];
    __Vtemp_9[2U] = (1U & __Vtemp_7[2U]);
    __Vtemp_11[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_2)
                               ? vlSelfRef.__PVT__buckets_count_2
                               : 0ULL));
    __Vtemp_11[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_2)
                                ? vlSelfRef.__PVT__buckets_count_2
                                : 0ULL) >> 0x20U));
    __Vtemp_11[2U] = 0U;
    __Vtemp_12[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_3)
                               ? vlSelfRef.__PVT__buckets_count_3
                               : 0ULL));
    __Vtemp_12[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_3)
                                ? vlSelfRef.__PVT__buckets_count_3
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
                               ? vlSelfRef.__PVT__buckets_count_4
                               : 0ULL));
    __Vtemp_21[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_4)
                                ? vlSelfRef.__PVT__buckets_count_4
                                : 0ULL) >> 0x20U));
    __Vtemp_21[2U] = 0U;
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_5)
                               ? vlSelfRef.__PVT__buckets_count_5
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_5)
                                ? vlSelfRef.__PVT__buckets_count_5
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    VL_ADD_W(3, __Vtemp_23, __Vtemp_21, __Vtemp_22);
    __Vtemp_25[0U] = __Vtemp_23[0U];
    __Vtemp_25[1U] = __Vtemp_23[1U];
    __Vtemp_25[2U] = (1U & __Vtemp_23[2U]);
    __Vtemp_27[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_6)
                               ? vlSelfRef.__PVT__buckets_count_6
                               : 0ULL));
    __Vtemp_27[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_6)
                                ? vlSelfRef.__PVT__buckets_count_6
                                : 0ULL) >> 0x20U));
    __Vtemp_27[2U] = 0U;
    __Vtemp_28[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_7)
                               ? vlSelfRef.buckets_count_7
                               : 0ULL));
    __Vtemp_28[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_count_7
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
                               ? vlSelfRef.__PVT__buckets_count_8
                               : 0ULL));
    __Vtemp_41[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_8)
                                ? vlSelfRef.__PVT__buckets_count_8
                                : 0ULL) >> 0x20U));
    __Vtemp_41[2U] = 0U;
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_9)
                               ? vlSelfRef.__PVT__buckets_count_9
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_9)
                                ? vlSelfRef.__PVT__buckets_count_9
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    VL_ADD_W(3, __Vtemp_43, __Vtemp_41, __Vtemp_42);
    __Vtemp_45[0U] = __Vtemp_43[0U];
    __Vtemp_45[1U] = __Vtemp_43[1U];
    __Vtemp_45[2U] = (1U & __Vtemp_43[2U]);
    __Vtemp_47[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_10)
                               ? vlSelfRef.__PVT__buckets_count_10
                               : 0ULL));
    __Vtemp_47[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_10)
                                ? vlSelfRef.__PVT__buckets_count_10
                                : 0ULL) >> 0x20U));
    __Vtemp_47[2U] = 0U;
    __Vtemp_48[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_11)
                               ? vlSelfRef.__PVT__buckets_count_11
                               : 0ULL));
    __Vtemp_48[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_11)
                                ? vlSelfRef.__PVT__buckets_count_11
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
                               ? vlSelfRef.__PVT__buckets_count_12
                               : 0ULL));
    __Vtemp_57[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_12)
                                ? vlSelfRef.__PVT__buckets_count_12
                                : 0ULL) >> 0x20U));
    __Vtemp_57[2U] = 0U;
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_13)
                               ? vlSelfRef.__PVT__buckets_count_13
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_13)
                                ? vlSelfRef.__PVT__buckets_count_13
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    VL_ADD_W(3, __Vtemp_59, __Vtemp_57, __Vtemp_58);
    __Vtemp_61[0U] = __Vtemp_59[0U];
    __Vtemp_61[1U] = __Vtemp_59[1U];
    __Vtemp_61[2U] = (1U & __Vtemp_59[2U]);
    __Vtemp_63[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_14)
                               ? vlSelfRef.__PVT__buckets_count_14
                               : 0ULL));
    __Vtemp_63[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_14)
                                ? vlSelfRef.__PVT__buckets_count_14
                                : 0ULL) >> 0x20U));
    __Vtemp_63[2U] = 0U;
    __Vtemp_64[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_15)
                               ? vlSelfRef.__PVT__buckets_count_15
                               : 0ULL));
    __Vtemp_64[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_count_15
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
    vlSelfRef.io_resolvedCount[0U] = __Vtemp_74[0U];
    vlSelfRef.io_resolvedCount[1U] = __Vtemp_74[1U];
    vlSelfRef.io_resolvedCount[2U] = (0xfU & __Vtemp_74[2U]);
    vlSelfRef.__PVT___canAccept_T_46 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_15)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_15)));
    vlSelfRef.__PVT__available_0 = ((0U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((1U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((2U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((3U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((4U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((5U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__3(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_6 = ((6U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((7U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.buckets_seq_7 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_8 = ((8U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_25) 
                                       | (vlSelfRef.__PVT__buckets_seq_8 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_9 = ((9U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_28) 
                                       | (vlSelfRef.__PVT__buckets_seq_9 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_10 = ((0xaU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_31) 
                                        | (vlSelfRef.__PVT__buckets_seq_10 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_11 = ((0xbU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_34) 
                                        | (vlSelfRef.__PVT__buckets_seq_11 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_12 = ((0xcU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_37) 
                                        | (vlSelfRef.__PVT__buckets_seq_12 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_13 = ((0xdU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_40) 
                                        | (vlSelfRef.__PVT__buckets_seq_13 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_14 = ((0xeU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_43) 
                                        | (vlSelfRef.__PVT__buckets_seq_14 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_15 = ((0xfU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_46) 
                                        | (vlSelfRef.__PVT__buckets_seq_15 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__accepted = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                 & (IData)(vlSelfRef.__PVT__available_0));
    vlSelfRef.__PVT__accepted_1 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_1));
    vlSelfRef.__PVT__accepted_2 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_2));
    vlSelfRef.__PVT__accepted_3 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_3));
    vlSelfRef.__PVT__accepted_4 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_4));
    vlSelfRef.__PVT__accepted_5 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_5));
    vlSelfRef.__PVT__accepted_6 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_6));
    vlSelfRef.__PVT__accepted_7 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_7));
    vlSelfRef.__PVT__accepted_8 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_8));
    vlSelfRef.__PVT__accepted_9 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_9));
    vlSelfRef.__PVT__accepted_10 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_10));
    vlSelfRef.__PVT__accepted_11 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_11));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__4(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__4\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__accepted_12 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_12));
    vlSelfRef.__PVT__accepted_13 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_13));
    vlSelfRef.__PVT__accepted_14 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_14));
    vlSelfRef.__PVT__accepted_15 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_15));
    vlSelfRef.__PVT___countOverflow_0_T_2 = ((IData)(vlSelfRef.__PVT__accepted) 
                                             & (IData)(vlSelfRef.__PVT___GEN_0));
    vlSelfRef.__PVT___countOverflow_1_T_2 = ((IData)(vlSelfRef.__PVT__accepted_1) 
                                             & (IData)(vlSelfRef.__PVT___GEN_15));
    vlSelfRef.__PVT___countOverflow_2_T_2 = ((IData)(vlSelfRef.__PVT__accepted_2) 
                                             & (IData)(vlSelfRef.__PVT___GEN_30));
    vlSelfRef.__PVT___countOverflow_3_T_2 = ((IData)(vlSelfRef.__PVT__accepted_3) 
                                             & (IData)(vlSelfRef.__PVT___GEN_45));
    vlSelfRef.__PVT___countOverflow_4_T_2 = ((IData)(vlSelfRef.__PVT__accepted_4) 
                                             & (IData)(vlSelfRef.__PVT___GEN_60));
    vlSelfRef.__PVT___countOverflow_5_T_2 = ((IData)(vlSelfRef.__PVT__accepted_5) 
                                             & (IData)(vlSelfRef.__PVT___GEN_75));
    vlSelfRef.__PVT___countOverflow_6_T_2 = ((IData)(vlSelfRef.__PVT__accepted_6) 
                                             & (IData)(vlSelfRef.__PVT___GEN_90));
    vlSelfRef.__PVT___countOverflow_7_T_2 = ((IData)(vlSelfRef.__PVT__accepted_7) 
                                             & (IData)(vlSelfRef.__PVT___GEN_105));
    vlSelfRef.__PVT___countOverflow_8_T_2 = ((IData)(vlSelfRef.__PVT__accepted_8) 
                                             & (IData)(vlSelfRef.__PVT___GEN_120));
    vlSelfRef.__PVT___countOverflow_9_T_2 = ((IData)(vlSelfRef.__PVT__accepted_9) 
                                             & (IData)(vlSelfRef.__PVT___GEN_135));
    vlSelfRef.__PVT___countOverflow_10_T_2 = ((IData)(vlSelfRef.__PVT__accepted_10) 
                                              & (IData)(vlSelfRef.__PVT___GEN_150));
    vlSelfRef.__PVT___countOverflow_11_T_2 = ((IData)(vlSelfRef.__PVT__accepted_11) 
                                              & (IData)(vlSelfRef.__PVT___GEN_165));
    vlSelfRef.__PVT___countOverflow_12_T_2 = ((IData)(vlSelfRef.__PVT__accepted_12) 
                                              & (IData)(vlSelfRef.__PVT___GEN_180));
    vlSelfRef.__PVT___countOverflow_13_T_2 = ((IData)(vlSelfRef.__PVT__accepted_13) 
                                              & (IData)(vlSelfRef.__PVT___GEN_195));
    vlSelfRef.__PVT___countOverflow_14_T_2 = ((IData)(vlSelfRef.__PVT__accepted_14) 
                                              & (IData)(vlSelfRef.__PVT___GEN_210));
    vlSelfRef.__PVT___countOverflow_15_T_2 = ((IData)(vlSelfRef.__PVT__accepted_15) 
                                              & (IData)(vlSelfRef.__PVT___GEN_225));
    vlSelfRef.io_cycleOverflow = (((IData)(vlSelfRef.__PVT___countOverflow_15_T_2) 
                                   & (vlSelfRef.__PVT__buckets_requestCycleSum_15 
                                      > (0xffffffffffffffffULL 
                                         - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                  | (((IData)(vlSelfRef.__PVT___countOverflow_14_T_2) 
                                      & (vlSelfRef.__PVT__buckets_requestCycleSum_14 
                                         > (0xffffffffffffffffULL 
                                            - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                     | (((IData)(vlSelfRef.__PVT___countOverflow_13_T_2) 
                                         & (vlSelfRef.__PVT__buckets_requestCycleSum_13 
                                            > (0xffffffffffffffffULL 
                                               - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                        | (((IData)(vlSelfRef.__PVT___countOverflow_12_T_2) 
                                            & (vlSelfRef.__PVT__buckets_requestCycleSum_12 
                                               > (0xffffffffffffffffULL 
                                                  - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                           | (((IData)(vlSelfRef.__PVT___countOverflow_11_T_2) 
                                               & (vlSelfRef.__PVT__buckets_requestCycleSum_11 
                                                  > 
                                                  (0xffffffffffffffffULL 
                                                   - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                              | (((IData)(vlSelfRef.__PVT___countOverflow_10_T_2) 
                                                  & (vlSelfRef.__PVT__buckets_requestCycleSum_10 
                                                     > 
                                                     (0xffffffffffffffffULL 
                                                      - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                 | (((IData)(vlSelfRef.__PVT___countOverflow_9_T_2) 
                                                     & (vlSelfRef.__PVT__buckets_requestCycleSum_9 
                                                        > 
                                                        (0xffffffffffffffffULL 
                                                         - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                    | (((IData)(vlSelfRef.__PVT___countOverflow_8_T_2) 
                                                        & (vlSelfRef.__PVT__buckets_requestCycleSum_8 
                                                           > 
                                                           (0xffffffffffffffffULL 
                                                            - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                       | (((IData)(vlSelfRef.__PVT___countOverflow_7_T_2) 
                                                           & (vlSelfRef.buckets_requestCycleSum_7 
                                                              > 
                                                              (0xffffffffffffffffULL 
                                                               - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                          | (((IData)(vlSelfRef.__PVT___countOverflow_6_T_2) 
                                                              & (vlSelfRef.__PVT__buckets_requestCycleSum_6 
                                                                 > 
                                                                 (0xffffffffffffffffULL 
                                                                  - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                             | (((IData)(vlSelfRef.__PVT___countOverflow_5_T_2) 
                                                                 & (vlSelfRef.__PVT__buckets_requestCycleSum_5 
                                                                    > 
                                                                    (0xffffffffffffffffULL 
                                                                     - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                                | (((IData)(vlSelfRef.__PVT___countOverflow_4_T_2) 
                                                                    & (vlSelfRef.__PVT__buckets_requestCycleSum_4 
                                                                       > 
                                                                       (0xffffffffffffffffULL 
                                                                        - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                                   | (((IData)(vlSelfRef.__PVT___countOverflow_3_T_2) 
                                                                       & (vlSelfRef.__PVT__buckets_requestCycleSum_3 
                                                                          > 
                                                                          (0xffffffffffffffffULL 
                                                                           - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                                      | (((IData)(vlSelfRef.__PVT___countOverflow_2_T_2) 
                                                                          & (vlSelfRef.__PVT__buckets_requestCycleSum_2 
                                                                             > 
                                                                             (0xffffffffffffffffULL 
                                                                              - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                                         | (((IData)(vlSelfRef.__PVT___countOverflow_1_T_2) 
                                                                             & (vlSelfRef.__PVT__buckets_requestCycleSum_1 
                                                                                > 
                                                                                (0xffffffffffffffffULL 
                                                                                - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                                            | ((IData)(vlSelfRef.__PVT___countOverflow_0_T_2) 
                                                                               & (vlSelfRef.__PVT__buckets_requestCycleSum_0 
                                                                                > 
                                                                                (0xffffffffffffffffULL 
                                                                                - vlSymsp->TOP.tb__DOT__io_currentCycle))))))))))))))))));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__0(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__eventNeedsBucket = ((IData)(vlSymsp->TOP.tb__DOT__io_event_valid) 
                                         & (vlSymsp->TOP.tb__DOT__io_event_bits 
                                            > vlSymsp->TOP.tb__DOT__io_safeWatermark));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.__PVT__buckets_requestCycleSum_15 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__buckets_requestCycleSum_15 = 0ULL;
    } else if (vlSelfRef.__PVT__accepted_15) {
        vlSelfRef.__PVT__buckets_requestCycleSum_15 
            = ((IData)(vlSelfRef.__PVT___canAccept_T_46)
                ? vlSymsp->TOP.tb__DOT__io_currentCycle
                : vlSelfRef.__PVT___buckets_requestCycleSum_15_T_1);
    } else if (vlSelfRef.__PVT__resolving_15) {
        vlSelfRef.__PVT__buckets_requestCycleSum_15 = 0ULL;
    }
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.__PVT__buckets_requestCycleSum_12 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_10 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_8 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_6 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_5 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_4 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_0 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_14 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_3 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__buckets_requestCycleSum_12 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_10 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_8 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_6 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_5 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_4 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_0 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_14 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_3 = 0ULL;
    } else {
        if (vlSelfRef.__PVT__accepted_12) {
            vlSelfRef.__PVT__buckets_requestCycleSum_12 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_37)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_12_T_1);
        } else if (vlSelfRef.__PVT__resolving_12) {
            vlSelfRef.__PVT__buckets_requestCycleSum_12 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_10) {
            vlSelfRef.__PVT__buckets_requestCycleSum_10 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_31)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_10_T_1);
        } else if (vlSelfRef.__PVT__resolving_10) {
            vlSelfRef.__PVT__buckets_requestCycleSum_10 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_8) {
            vlSelfRef.__PVT__buckets_requestCycleSum_8 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_25)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_8_T_1);
        } else if (vlSelfRef.__PVT__resolving_8) {
            vlSelfRef.__PVT__buckets_requestCycleSum_8 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_6) {
            vlSelfRef.__PVT__buckets_requestCycleSum_6 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_19)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_6_T_1);
        } else if (vlSelfRef.__PVT__resolving_6) {
            vlSelfRef.__PVT__buckets_requestCycleSum_6 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_5) {
            vlSelfRef.__PVT__buckets_requestCycleSum_5 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_16)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_5_T_1);
        } else if (vlSelfRef.__PVT__resolving_5) {
            vlSelfRef.__PVT__buckets_requestCycleSum_5 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_4) {
            vlSelfRef.__PVT__buckets_requestCycleSum_4 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_13)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_4_T_1);
        } else if (vlSelfRef.__PVT__resolving_4) {
            vlSelfRef.__PVT__buckets_requestCycleSum_4 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted) {
            vlSelfRef.__PVT__buckets_requestCycleSum_0 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_1)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_0_T_1);
        } else if (vlSelfRef.__PVT__resolving_0) {
            vlSelfRef.__PVT__buckets_requestCycleSum_0 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_14) {
            vlSelfRef.__PVT__buckets_requestCycleSum_14 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_43)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_14_T_1);
        } else if (vlSelfRef.__PVT__resolving_14) {
            vlSelfRef.__PVT__buckets_requestCycleSum_14 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_3) {
            vlSelfRef.__PVT__buckets_requestCycleSum_3 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_10)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_3_T_1);
        } else if (vlSelfRef.__PVT__resolving_3) {
            vlSelfRef.__PVT__buckets_requestCycleSum_3 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__3(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.__PVT__buckets_requestCycleSum_9 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_11 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_13 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_1 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_2 = 0ULL;
        vlSelfRef.buckets_requestCycleSum_7 = 0ULL;
        vlSelfRef.__PVT__buckets_count_13 = 0ULL;
        vlSelfRef.__PVT__buckets_count_10 = 0ULL;
        vlSelfRef.__PVT__buckets_count_9 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__buckets_requestCycleSum_9 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_11 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_13 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_1 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_2 = 0ULL;
        vlSelfRef.buckets_requestCycleSum_7 = 0ULL;
        vlSelfRef.__PVT__buckets_count_13 = 0ULL;
        vlSelfRef.__PVT__buckets_count_10 = 0ULL;
        vlSelfRef.__PVT__buckets_count_9 = 0ULL;
    } else {
        if (vlSelfRef.__PVT__accepted_9) {
            if (vlSelfRef.__PVT___canAccept_T_28) {
                vlSelfRef.__PVT__buckets_requestCycleSum_9 
                    = vlSymsp->TOP.tb__DOT__io_currentCycle;
                vlSelfRef.__PVT__buckets_count_9 = 1ULL;
            } else {
                vlSelfRef.__PVT__buckets_requestCycleSum_9 
                    = vlSelfRef.__PVT___buckets_requestCycleSum_9_T_1;
                vlSelfRef.__PVT__buckets_count_9 = vlSelfRef.__PVT___buckets_count_9_T_1;
            }
        } else if (vlSelfRef.__PVT__resolving_9) {
            vlSelfRef.__PVT__buckets_requestCycleSum_9 = 0ULL;
            vlSelfRef.__PVT__buckets_count_9 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_11) {
            vlSelfRef.__PVT__buckets_requestCycleSum_11 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_34)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_11_T_1);
        } else if (vlSelfRef.__PVT__resolving_11) {
            vlSelfRef.__PVT__buckets_requestCycleSum_11 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_13) {
            if (vlSelfRef.__PVT___canAccept_T_40) {
                vlSelfRef.__PVT__buckets_requestCycleSum_13 
                    = vlSymsp->TOP.tb__DOT__io_currentCycle;
                vlSelfRef.__PVT__buckets_count_13 = 1ULL;
            } else {
                vlSelfRef.__PVT__buckets_requestCycleSum_13 
                    = vlSelfRef.__PVT___buckets_requestCycleSum_13_T_1;
                vlSelfRef.__PVT__buckets_count_13 = vlSelfRef.__PVT___buckets_count_13_T_1;
            }
        } else if (vlSelfRef.__PVT__resolving_13) {
            vlSelfRef.__PVT__buckets_requestCycleSum_13 = 0ULL;
            vlSelfRef.__PVT__buckets_count_13 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_1) {
            vlSelfRef.__PVT__buckets_requestCycleSum_1 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_4)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_1_T_1);
        } else if (vlSelfRef.__PVT__resolving_1) {
            vlSelfRef.__PVT__buckets_requestCycleSum_1 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_2) {
            vlSelfRef.__PVT__buckets_requestCycleSum_2 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_7)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_2_T_1);
        } else if (vlSelfRef.__PVT__resolving_2) {
            vlSelfRef.__PVT__buckets_requestCycleSum_2 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_7) {
            vlSelfRef.buckets_requestCycleSum_7 = ((IData)(vlSelfRef.__PVT___canAccept_T_22)
                                                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                                                    : vlSelfRef.__PVT___buckets_requestCycleSum_7_T_1);
        } else if (vlSelfRef.__PVT__resolving_7) {
            vlSelfRef.buckets_requestCycleSum_7 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_10) {
            vlSelfRef.__PVT__buckets_count_10 = ((IData)(vlSelfRef.__PVT___canAccept_T_31)
                                                  ? 1ULL
                                                  : vlSelfRef.__PVT___buckets_count_10_T_1);
        } else if (vlSelfRef.__PVT__resolving_10) {
            vlSelfRef.__PVT__buckets_count_10 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__4(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__4\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.__PVT__buckets_count_8 = 0ULL;
        vlSelfRef.__PVT__buckets_count_14 = 0ULL;
        vlSelfRef.__PVT__buckets_count_12 = 0ULL;
        vlSelfRef.__PVT__buckets_count_6 = 0ULL;
        vlSelfRef.__PVT__buckets_count_4 = 0ULL;
        vlSelfRef.__PVT__buckets_count_0 = 0ULL;
        vlSelfRef.__PVT__buckets_count_1 = 0ULL;
        vlSelfRef.__PVT__buckets_count_2 = 0ULL;
        vlSelfRef.__PVT__buckets_count_3 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__buckets_count_8 = 0ULL;
        vlSelfRef.__PVT__buckets_count_14 = 0ULL;
        vlSelfRef.__PVT__buckets_count_12 = 0ULL;
        vlSelfRef.__PVT__buckets_count_6 = 0ULL;
        vlSelfRef.__PVT__buckets_count_4 = 0ULL;
        vlSelfRef.__PVT__buckets_count_0 = 0ULL;
        vlSelfRef.__PVT__buckets_count_1 = 0ULL;
        vlSelfRef.__PVT__buckets_count_2 = 0ULL;
        vlSelfRef.__PVT__buckets_count_3 = 0ULL;
    } else {
        if (vlSelfRef.__PVT__accepted_8) {
            vlSelfRef.__PVT__buckets_count_8 = ((IData)(vlSelfRef.__PVT___canAccept_T_25)
                                                 ? 1ULL
                                                 : vlSelfRef.__PVT___buckets_count_8_T_1);
        } else if (vlSelfRef.__PVT__resolving_8) {
            vlSelfRef.__PVT__buckets_count_8 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_14) {
            vlSelfRef.__PVT__buckets_count_14 = ((IData)(vlSelfRef.__PVT___canAccept_T_43)
                                                  ? 1ULL
                                                  : vlSelfRef.__PVT___buckets_count_14_T_1);
        } else if (vlSelfRef.__PVT__resolving_14) {
            vlSelfRef.__PVT__buckets_count_14 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_12) {
            vlSelfRef.__PVT__buckets_count_12 = ((IData)(vlSelfRef.__PVT___canAccept_T_37)
                                                  ? 1ULL
                                                  : vlSelfRef.__PVT___buckets_count_12_T_1);
        } else if (vlSelfRef.__PVT__resolving_12) {
            vlSelfRef.__PVT__buckets_count_12 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_6) {
            vlSelfRef.__PVT__buckets_count_6 = ((IData)(vlSelfRef.__PVT___canAccept_T_19)
                                                 ? 1ULL
                                                 : vlSelfRef.__PVT___buckets_count_6_T_1);
        } else if (vlSelfRef.__PVT__resolving_6) {
            vlSelfRef.__PVT__buckets_count_6 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_4) {
            vlSelfRef.__PVT__buckets_count_4 = ((IData)(vlSelfRef.__PVT___canAccept_T_13)
                                                 ? 1ULL
                                                 : vlSelfRef.__PVT___buckets_count_4_T_1);
        } else if (vlSelfRef.__PVT__resolving_4) {
            vlSelfRef.__PVT__buckets_count_4 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted) {
            vlSelfRef.__PVT__buckets_count_0 = ((IData)(vlSelfRef.__PVT___canAccept_T_1)
                                                 ? 1ULL
                                                 : vlSelfRef.__PVT___buckets_count_0_T_1);
        } else if (vlSelfRef.__PVT__resolving_0) {
            vlSelfRef.__PVT__buckets_count_0 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_1) {
            vlSelfRef.__PVT__buckets_count_1 = ((IData)(vlSelfRef.__PVT___canAccept_T_4)
                                                 ? 1ULL
                                                 : vlSelfRef.__PVT___buckets_count_1_T_1);
        } else if (vlSelfRef.__PVT__resolving_1) {
            vlSelfRef.__PVT__buckets_count_1 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_2) {
            vlSelfRef.__PVT__buckets_count_2 = ((IData)(vlSelfRef.__PVT___canAccept_T_7)
                                                 ? 1ULL
                                                 : vlSelfRef.__PVT___buckets_count_2_T_1);
        } else if (vlSelfRef.__PVT__resolving_2) {
            vlSelfRef.__PVT__buckets_count_2 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_3) {
            vlSelfRef.__PVT__buckets_count_3 = ((IData)(vlSelfRef.__PVT___canAccept_T_10)
                                                 ? 1ULL
                                                 : vlSelfRef.__PVT___buckets_count_3_T_1);
        } else if (vlSelfRef.__PVT__resolving_3) {
            vlSelfRef.__PVT__buckets_count_3 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__5(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__5\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.__PVT__buckets_count_5 = 0ULL;
        vlSelfRef.__PVT__buckets_count_11 = 0ULL;
        vlSelfRef.__PVT__buckets_count_15 = 0ULL;
        vlSelfRef.buckets_count_7 = 0ULL;
        vlSelfRef.__PVT__buckets_seq_3 = 0U;
        vlSelfRef.__PVT__buckets_seq_2 = 0U;
        vlSelfRef.__PVT__buckets_seq_1 = 0U;
        vlSelfRef.__PVT__buckets_seq_9 = 0U;
        vlSelfRef.__PVT__buckets_seq_10 = 0U;
        vlSelfRef.__PVT__buckets_seq_5 = 0U;
        vlSelfRef.__PVT__buckets_seq_8 = 0U;
    } else if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__buckets_count_5 = 0ULL;
        vlSelfRef.__PVT__buckets_count_11 = 0ULL;
        vlSelfRef.__PVT__buckets_count_15 = 0ULL;
        vlSelfRef.buckets_count_7 = 0ULL;
        vlSelfRef.__PVT__buckets_seq_3 = 0U;
        vlSelfRef.__PVT__buckets_seq_2 = 0U;
        vlSelfRef.__PVT__buckets_seq_1 = 0U;
        vlSelfRef.__PVT__buckets_seq_9 = 0U;
        vlSelfRef.__PVT__buckets_seq_10 = 0U;
        vlSelfRef.__PVT__buckets_seq_5 = 0U;
        vlSelfRef.__PVT__buckets_seq_8 = 0U;
    } else {
        if (vlSelfRef.__PVT__accepted_5) {
            if (vlSelfRef.__PVT___canAccept_T_16) {
                vlSelfRef.__PVT__buckets_count_5 = 1ULL;
                vlSelfRef.__PVT__buckets_seq_5 = vlSymsp->TOP.tb__DOT__io_event_bits;
            } else {
                vlSelfRef.__PVT__buckets_count_5 = vlSelfRef.__PVT___buckets_count_5_T_1;
            }
        } else if (vlSelfRef.__PVT__resolving_5) {
            vlSelfRef.__PVT__buckets_count_5 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_11) {
            vlSelfRef.__PVT__buckets_count_11 = ((IData)(vlSelfRef.__PVT___canAccept_T_34)
                                                  ? 1ULL
                                                  : vlSelfRef.__PVT___buckets_count_11_T_1);
        } else if (vlSelfRef.__PVT__resolving_11) {
            vlSelfRef.__PVT__buckets_count_11 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_15) {
            vlSelfRef.__PVT__buckets_count_15 = ((IData)(vlSelfRef.__PVT___canAccept_T_46)
                                                  ? 1ULL
                                                  : vlSelfRef.__PVT___buckets_count_15_T_1);
        } else if (vlSelfRef.__PVT__resolving_15) {
            vlSelfRef.__PVT__buckets_count_15 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_7) {
            vlSelfRef.buckets_count_7 = ((IData)(vlSelfRef.__PVT___canAccept_T_22)
                                          ? 1ULL : vlSelfRef.__PVT___buckets_count_7_T_1);
        } else if (vlSelfRef.__PVT__resolving_7) {
            vlSelfRef.buckets_count_7 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_3) {
            if (vlSelfRef.__PVT___canAccept_T_10) {
                vlSelfRef.__PVT__buckets_seq_3 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_2) {
            if (vlSelfRef.__PVT___canAccept_T_7) {
                vlSelfRef.__PVT__buckets_seq_2 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_1) {
            if (vlSelfRef.__PVT___canAccept_T_4) {
                vlSelfRef.__PVT__buckets_seq_1 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_9) {
            if (vlSelfRef.__PVT___canAccept_T_28) {
                vlSelfRef.__PVT__buckets_seq_9 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_10) {
            if (vlSelfRef.__PVT___canAccept_T_31) {
                vlSelfRef.__PVT__buckets_seq_10 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_8) {
            if (vlSelfRef.__PVT___canAccept_T_25) {
                vlSelfRef.__PVT__buckets_seq_8 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
    }
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__6(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__6\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.__PVT__buckets_seq_0 = 0U;
        vlSelfRef.__PVT__buckets_seq_6 = 0U;
        vlSelfRef.__PVT__buckets_seq_4 = 0U;
        vlSelfRef.__PVT__buckets_seq_11 = 0U;
        vlSelfRef.__PVT__buckets_seq_12 = 0U;
        vlSelfRef.__PVT__buckets_seq_13 = 0U;
        vlSelfRef.__PVT__buckets_seq_14 = 0U;
        vlSelfRef.__PVT__buckets_seq_15 = 0U;
        vlSelfRef.buckets_seq_7 = 0U;
        vlSelfRef.__PVT__buckets_valid_5 = 0U;
        vlSelfRef.__PVT__buckets_valid_4 = 0U;
        vlSelfRef.__PVT__buckets_valid_15 = 0U;
    } else if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__buckets_seq_0 = 0U;
        vlSelfRef.__PVT__buckets_seq_6 = 0U;
        vlSelfRef.__PVT__buckets_seq_4 = 0U;
        vlSelfRef.__PVT__buckets_seq_11 = 0U;
        vlSelfRef.__PVT__buckets_seq_12 = 0U;
        vlSelfRef.__PVT__buckets_seq_13 = 0U;
        vlSelfRef.__PVT__buckets_seq_14 = 0U;
        vlSelfRef.__PVT__buckets_seq_15 = 0U;
        vlSelfRef.buckets_seq_7 = 0U;
        vlSelfRef.__PVT__buckets_valid_5 = 0U;
        vlSelfRef.__PVT__buckets_valid_4 = 0U;
        vlSelfRef.__PVT__buckets_valid_15 = 0U;
    } else {
        if (vlSelfRef.__PVT__accepted) {
            if (vlSelfRef.__PVT___canAccept_T_1) {
                vlSelfRef.__PVT__buckets_seq_0 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_6) {
            if (vlSelfRef.__PVT___canAccept_T_19) {
                vlSelfRef.__PVT__buckets_seq_6 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_4) {
            if (vlSelfRef.__PVT___canAccept_T_13) {
                vlSelfRef.__PVT__buckets_seq_4 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
            vlSelfRef.__PVT__buckets_valid_4 = ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                                | (IData)(vlSelfRef.__PVT___GEN_60));
        } else if (vlSelfRef.__PVT__resolving_4) {
            vlSelfRef.__PVT__buckets_valid_4 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_11) {
            if (vlSelfRef.__PVT___canAccept_T_34) {
                vlSelfRef.__PVT__buckets_seq_11 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_12) {
            if (vlSelfRef.__PVT___canAccept_T_37) {
                vlSelfRef.__PVT__buckets_seq_12 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_13) {
            if (vlSelfRef.__PVT___canAccept_T_40) {
                vlSelfRef.__PVT__buckets_seq_13 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_14) {
            if (vlSelfRef.__PVT___canAccept_T_43) {
                vlSelfRef.__PVT__buckets_seq_14 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_15) {
            if (vlSelfRef.__PVT___canAccept_T_46) {
                vlSelfRef.__PVT__buckets_seq_15 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
            vlSelfRef.__PVT__buckets_valid_15 = ((IData)(vlSelfRef.__PVT___canAccept_T_46) 
                                                 | (IData)(vlSelfRef.__PVT___GEN_225));
        } else if (vlSelfRef.__PVT__resolving_15) {
            vlSelfRef.__PVT__buckets_valid_15 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_7) {
            if (vlSelfRef.__PVT___canAccept_T_22) {
                vlSelfRef.buckets_seq_7 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_5) {
            vlSelfRef.__PVT__buckets_valid_5 = ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                                | (IData)(vlSelfRef.__PVT___GEN_75));
        } else if (vlSelfRef.__PVT__resolving_5) {
            vlSelfRef.__PVT__buckets_valid_5 = 0U;
        }
    }
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__7(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__7\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.__PVT__buckets_valid_3 = 0U;
        vlSelfRef.__PVT__buckets_valid_9 = 0U;
        vlSelfRef.__PVT__buckets_valid_10 = 0U;
        vlSelfRef.__PVT__buckets_valid_13 = 0U;
        vlSelfRef.__PVT__buckets_valid_14 = 0U;
        vlSelfRef.__PVT__buckets_valid_11 = 0U;
        vlSelfRef.__PVT__buckets_valid_12 = 0U;
        vlSelfRef.__PVT__buckets_valid_6 = 0U;
        vlSelfRef.__PVT__buckets_valid_8 = 0U;
        vlSelfRef.__PVT__buckets_valid_0 = 0U;
    } else if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__buckets_valid_3 = 0U;
        vlSelfRef.__PVT__buckets_valid_9 = 0U;
        vlSelfRef.__PVT__buckets_valid_10 = 0U;
        vlSelfRef.__PVT__buckets_valid_13 = 0U;
        vlSelfRef.__PVT__buckets_valid_14 = 0U;
        vlSelfRef.__PVT__buckets_valid_11 = 0U;
        vlSelfRef.__PVT__buckets_valid_12 = 0U;
        vlSelfRef.__PVT__buckets_valid_6 = 0U;
        vlSelfRef.__PVT__buckets_valid_8 = 0U;
        vlSelfRef.__PVT__buckets_valid_0 = 0U;
    } else {
        if (vlSelfRef.__PVT__accepted_3) {
            vlSelfRef.__PVT__buckets_valid_3 = ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                                | (IData)(vlSelfRef.__PVT___GEN_45));
        } else if (vlSelfRef.__PVT__resolving_3) {
            vlSelfRef.__PVT__buckets_valid_3 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_9) {
            vlSelfRef.__PVT__buckets_valid_9 = ((IData)(vlSelfRef.__PVT___canAccept_T_28) 
                                                | (IData)(vlSelfRef.__PVT___GEN_135));
        } else if (vlSelfRef.__PVT__resolving_9) {
            vlSelfRef.__PVT__buckets_valid_9 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_10) {
            vlSelfRef.__PVT__buckets_valid_10 = ((IData)(vlSelfRef.__PVT___canAccept_T_31) 
                                                 | (IData)(vlSelfRef.__PVT___GEN_150));
        } else if (vlSelfRef.__PVT__resolving_10) {
            vlSelfRef.__PVT__buckets_valid_10 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_13) {
            vlSelfRef.__PVT__buckets_valid_13 = ((IData)(vlSelfRef.__PVT___canAccept_T_40) 
                                                 | (IData)(vlSelfRef.__PVT___GEN_195));
        } else if (vlSelfRef.__PVT__resolving_13) {
            vlSelfRef.__PVT__buckets_valid_13 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_14) {
            vlSelfRef.__PVT__buckets_valid_14 = ((IData)(vlSelfRef.__PVT___canAccept_T_43) 
                                                 | (IData)(vlSelfRef.__PVT___GEN_210));
        } else if (vlSelfRef.__PVT__resolving_14) {
            vlSelfRef.__PVT__buckets_valid_14 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_11) {
            vlSelfRef.__PVT__buckets_valid_11 = ((IData)(vlSelfRef.__PVT___canAccept_T_34) 
                                                 | (IData)(vlSelfRef.__PVT___GEN_165));
        } else if (vlSelfRef.__PVT__resolving_11) {
            vlSelfRef.__PVT__buckets_valid_11 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_12) {
            vlSelfRef.__PVT__buckets_valid_12 = ((IData)(vlSelfRef.__PVT___canAccept_T_37) 
                                                 | (IData)(vlSelfRef.__PVT___GEN_180));
        } else if (vlSelfRef.__PVT__resolving_12) {
            vlSelfRef.__PVT__buckets_valid_12 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_6) {
            vlSelfRef.__PVT__buckets_valid_6 = ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                                | (IData)(vlSelfRef.__PVT___GEN_90));
        } else if (vlSelfRef.__PVT__resolving_6) {
            vlSelfRef.__PVT__buckets_valid_6 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_8) {
            vlSelfRef.__PVT__buckets_valid_8 = ((IData)(vlSelfRef.__PVT___canAccept_T_25) 
                                                | (IData)(vlSelfRef.__PVT___GEN_120));
        } else if (vlSelfRef.__PVT__resolving_8) {
            vlSelfRef.__PVT__buckets_valid_8 = 0U;
        }
        if (vlSelfRef.__PVT__accepted) {
            vlSelfRef.__PVT__buckets_valid_0 = ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                                | (IData)(vlSelfRef.__PVT___GEN_0));
        } else if (vlSelfRef.__PVT__resolving_0) {
            vlSelfRef.__PVT__buckets_valid_0 = 0U;
        }
    }
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__8(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__8\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.__PVT__buckets_valid_1 = 0U;
        vlSelfRef.__PVT__buckets_valid_2 = 0U;
        vlSelfRef.buckets_valid_7 = 0U;
    } else if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__buckets_valid_1 = 0U;
        vlSelfRef.__PVT__buckets_valid_2 = 0U;
        vlSelfRef.buckets_valid_7 = 0U;
    } else {
        if (vlSelfRef.__PVT__accepted_1) {
            vlSelfRef.__PVT__buckets_valid_1 = ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                                | (IData)(vlSelfRef.__PVT___GEN_15));
        } else if (vlSelfRef.__PVT__resolving_1) {
            vlSelfRef.__PVT__buckets_valid_1 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_2) {
            vlSelfRef.__PVT__buckets_valid_2 = ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                                | (IData)(vlSelfRef.__PVT___GEN_30));
        } else if (vlSelfRef.__PVT__resolving_2) {
            vlSelfRef.__PVT__buckets_valid_2 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_7) {
            vlSelfRef.buckets_valid_7 = ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                         | (IData)(vlSelfRef.__PVT___GEN_105));
        } else if (vlSelfRef.__PVT__resolving_7) {
            vlSelfRef.buckets_valid_7 = 0U;
        }
    }
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__0(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_requestCycleSum_15_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_15 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_12_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_12 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_10_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_10 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_8_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_8 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_6_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_6 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_5_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_5 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_4_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_4 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_0_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_0 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_14_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_14 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_3_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_3 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_9_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_9 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_11_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_11 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_13_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_13 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_1_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_1 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_2_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_2 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_7_T_1 
        = (vlSelfRef.buckets_requestCycleSum_7 + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_count_7_T_1 = (1ULL + vlSelfRef.buckets_count_7);
    vlSelfRef.__PVT__resolving_5 = ((IData)(vlSelfRef.__PVT__buckets_valid_5) 
                                    & (vlSelfRef.__PVT__buckets_seq_5 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_4 = ((IData)(vlSelfRef.__PVT__buckets_valid_4) 
                                    & (vlSelfRef.__PVT__buckets_seq_4 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_15 = ((IData)(vlSelfRef.__PVT__buckets_valid_15) 
                                     & (vlSelfRef.__PVT__buckets_seq_15 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_3 = ((IData)(vlSelfRef.__PVT__buckets_valid_3) 
                                    & (vlSelfRef.__PVT__buckets_seq_3 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_9 = ((IData)(vlSelfRef.__PVT__buckets_valid_9) 
                                    & (vlSelfRef.__PVT__buckets_seq_9 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_10 = ((IData)(vlSelfRef.__PVT__buckets_valid_10) 
                                     & (vlSelfRef.__PVT__buckets_seq_10 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_13 = ((IData)(vlSelfRef.__PVT__buckets_valid_13) 
                                     & (vlSelfRef.__PVT__buckets_seq_13 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_14 = ((IData)(vlSelfRef.__PVT__buckets_valid_14) 
                                     & (vlSelfRef.__PVT__buckets_seq_14 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_11 = ((IData)(vlSelfRef.__PVT__buckets_valid_11) 
                                     & (vlSelfRef.__PVT__buckets_seq_11 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_12 = ((IData)(vlSelfRef.__PVT__buckets_valid_12) 
                                     & (vlSelfRef.__PVT__buckets_seq_12 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_6 = ((IData)(vlSelfRef.__PVT__buckets_valid_6) 
                                    & (vlSelfRef.__PVT__buckets_seq_6 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_8 = ((IData)(vlSelfRef.__PVT__buckets_valid_8) 
                                    & (vlSelfRef.__PVT__buckets_seq_8 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_0 = ((IData)(vlSelfRef.__PVT__buckets_valid_0) 
                                    & (vlSelfRef.__PVT__buckets_seq_0 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_1 = ((IData)(vlSelfRef.__PVT__buckets_valid_1) 
                                    & (vlSelfRef.__PVT__buckets_seq_1 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_2 = ((IData)(vlSelfRef.__PVT__buckets_valid_2) 
                                    & (vlSelfRef.__PVT__buckets_seq_2 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.io_observe_7[0U] = (IData)(vlSelfRef.buckets_requestCycleSum_7);
    vlSelfRef.io_observe_7[1U] = (IData)((vlSelfRef.buckets_requestCycleSum_7 
                                          >> 0x20U));
    vlSelfRef.io_observe_7[2U] = (IData)(vlSelfRef.buckets_count_7);
    vlSelfRef.io_observe_7[3U] = (IData)((vlSelfRef.buckets_count_7 
                                          >> 0x20U));
    vlSelfRef.io_observe_7[4U] = vlSelfRef.buckets_seq_7;
    vlSelfRef.io_observe_7[5U] = vlSelfRef.buckets_valid_7;
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__1\n"); );
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
    vlSelfRef.__PVT__resolving_7 = ((IData)(vlSelfRef.buckets_valid_7) 
                                    & (vlSelfRef.buckets_seq_7 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT___GEN_75 = ((~ (IData)(vlSelfRef.__PVT__resolving_5)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_5));
    vlSelfRef.__PVT___canAccept_T_16 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_5)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_5)));
    vlSelfRef.__PVT___GEN_60 = ((~ (IData)(vlSelfRef.__PVT__resolving_4)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_4));
    vlSelfRef.__PVT___canAccept_T_13 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_4)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_4)));
    vlSelfRef.__PVT___GEN_225 = ((~ (IData)(vlSelfRef.__PVT__resolving_15)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_15));
    vlSelfRef.__PVT___canAccept_T_46 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_15)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_15)));
    vlSelfRef.__PVT___GEN_45 = ((~ (IData)(vlSelfRef.__PVT__resolving_3)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_3));
    vlSelfRef.__PVT___canAccept_T_10 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_3)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_3)));
    vlSelfRef.__PVT___GEN_135 = ((~ (IData)(vlSelfRef.__PVT__resolving_9)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_9));
    vlSelfRef.__PVT___canAccept_T_28 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_9)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_9)));
    vlSelfRef.__PVT___GEN_150 = ((~ (IData)(vlSelfRef.__PVT__resolving_10)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_10));
    vlSelfRef.__PVT___canAccept_T_31 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_10)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_10)));
    vlSelfRef.__PVT___GEN_195 = ((~ (IData)(vlSelfRef.__PVT__resolving_13)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_13));
    vlSelfRef.__PVT___canAccept_T_40 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_13)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_13)));
    vlSelfRef.__PVT___GEN_210 = ((~ (IData)(vlSelfRef.__PVT__resolving_14)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_14));
    vlSelfRef.__PVT___canAccept_T_43 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_14)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_14)));
    vlSelfRef.__PVT___GEN_165 = ((~ (IData)(vlSelfRef.__PVT__resolving_11)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_11));
    vlSelfRef.__PVT___canAccept_T_34 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_11)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_11)));
    vlSelfRef.__PVT___GEN_180 = ((~ (IData)(vlSelfRef.__PVT__resolving_12)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_12));
    vlSelfRef.__PVT___canAccept_T_37 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_12)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_12)));
    vlSelfRef.__PVT___GEN_90 = ((~ (IData)(vlSelfRef.__PVT__resolving_6)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_6));
    vlSelfRef.__PVT___canAccept_T_19 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_6)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_6)));
    vlSelfRef.__PVT___GEN_120 = ((~ (IData)(vlSelfRef.__PVT__resolving_8)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_8));
    vlSelfRef.__PVT___canAccept_T_25 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_8)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_8)));
    vlSelfRef.__PVT___GEN_0 = ((~ (IData)(vlSelfRef.__PVT__resolving_0)) 
                               & (IData)(vlSelfRef.__PVT__buckets_valid_0));
    vlSelfRef.__PVT___canAccept_T_1 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_0)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_0)));
    vlSelfRef.__PVT___GEN_15 = ((~ (IData)(vlSelfRef.__PVT__resolving_1)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_1));
    vlSelfRef.__PVT___canAccept_T_4 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_1)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_1)));
    vlSelfRef.__PVT___GEN_30 = ((~ (IData)(vlSelfRef.__PVT__resolving_2)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_2));
    vlSelfRef.__PVT___canAccept_T_7 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_2)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_2)));
    __Vtemp_5[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                              ? vlSelfRef.__PVT__buckets_requestCycleSum_0
                              : 0ULL));
    __Vtemp_5[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_0
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
                               ? vlSelfRef.buckets_requestCycleSum_7
                               : 0ULL));
    __Vtemp_28[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_requestCycleSum_7
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
                               ? vlSelfRef.__PVT__buckets_requestCycleSum_15
                               : 0ULL));
    __Vtemp_64[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_requestCycleSum_15
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
    vlSelfRef.io_resolvedRequest[0U] = __Vtemp_74[0U];
    vlSelfRef.io_resolvedRequest[1U] = __Vtemp_74[1U];
    vlSelfRef.io_resolvedRequest[2U] = (0xfU & __Vtemp_74[2U]);
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__2\n"); );
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
    vlSelfRef.__PVT___GEN_105 = ((~ (IData)(vlSelfRef.__PVT__resolving_7)) 
                                 & (IData)(vlSelfRef.buckets_valid_7));
    __Vtemp_5[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                              ? vlSelfRef.__PVT__buckets_count_0
                              : 0ULL));
    __Vtemp_5[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_count_0
                               : 0ULL) >> 0x20U));
    __Vtemp_5[2U] = 0U;
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_1)
                              ? vlSelfRef.__PVT__buckets_count_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_1)
                               ? vlSelfRef.__PVT__buckets_count_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    VL_ADD_W(3, __Vtemp_7, __Vtemp_5, __Vtemp_6);
    __Vtemp_9[0U] = __Vtemp_7[0U];
    __Vtemp_9[1U] = __Vtemp_7[1U];
    __Vtemp_9[2U] = (1U & __Vtemp_7[2U]);
    __Vtemp_11[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_2)
                               ? vlSelfRef.__PVT__buckets_count_2
                               : 0ULL));
    __Vtemp_11[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_2)
                                ? vlSelfRef.__PVT__buckets_count_2
                                : 0ULL) >> 0x20U));
    __Vtemp_11[2U] = 0U;
    __Vtemp_12[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_3)
                               ? vlSelfRef.__PVT__buckets_count_3
                               : 0ULL));
    __Vtemp_12[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_3)
                                ? vlSelfRef.__PVT__buckets_count_3
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
                               ? vlSelfRef.__PVT__buckets_count_4
                               : 0ULL));
    __Vtemp_21[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_4)
                                ? vlSelfRef.__PVT__buckets_count_4
                                : 0ULL) >> 0x20U));
    __Vtemp_21[2U] = 0U;
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_5)
                               ? vlSelfRef.__PVT__buckets_count_5
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_5)
                                ? vlSelfRef.__PVT__buckets_count_5
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    VL_ADD_W(3, __Vtemp_23, __Vtemp_21, __Vtemp_22);
    __Vtemp_25[0U] = __Vtemp_23[0U];
    __Vtemp_25[1U] = __Vtemp_23[1U];
    __Vtemp_25[2U] = (1U & __Vtemp_23[2U]);
    __Vtemp_27[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_6)
                               ? vlSelfRef.__PVT__buckets_count_6
                               : 0ULL));
    __Vtemp_27[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_6)
                                ? vlSelfRef.__PVT__buckets_count_6
                                : 0ULL) >> 0x20U));
    __Vtemp_27[2U] = 0U;
    __Vtemp_28[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_7)
                               ? vlSelfRef.buckets_count_7
                               : 0ULL));
    __Vtemp_28[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_count_7
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
                               ? vlSelfRef.__PVT__buckets_count_8
                               : 0ULL));
    __Vtemp_41[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_8)
                                ? vlSelfRef.__PVT__buckets_count_8
                                : 0ULL) >> 0x20U));
    __Vtemp_41[2U] = 0U;
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_9)
                               ? vlSelfRef.__PVT__buckets_count_9
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_9)
                                ? vlSelfRef.__PVT__buckets_count_9
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    VL_ADD_W(3, __Vtemp_43, __Vtemp_41, __Vtemp_42);
    __Vtemp_45[0U] = __Vtemp_43[0U];
    __Vtemp_45[1U] = __Vtemp_43[1U];
    __Vtemp_45[2U] = (1U & __Vtemp_43[2U]);
    __Vtemp_47[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_10)
                               ? vlSelfRef.__PVT__buckets_count_10
                               : 0ULL));
    __Vtemp_47[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_10)
                                ? vlSelfRef.__PVT__buckets_count_10
                                : 0ULL) >> 0x20U));
    __Vtemp_47[2U] = 0U;
    __Vtemp_48[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_11)
                               ? vlSelfRef.__PVT__buckets_count_11
                               : 0ULL));
    __Vtemp_48[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_11)
                                ? vlSelfRef.__PVT__buckets_count_11
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
                               ? vlSelfRef.__PVT__buckets_count_12
                               : 0ULL));
    __Vtemp_57[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_12)
                                ? vlSelfRef.__PVT__buckets_count_12
                                : 0ULL) >> 0x20U));
    __Vtemp_57[2U] = 0U;
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_13)
                               ? vlSelfRef.__PVT__buckets_count_13
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_13)
                                ? vlSelfRef.__PVT__buckets_count_13
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    VL_ADD_W(3, __Vtemp_59, __Vtemp_57, __Vtemp_58);
    __Vtemp_61[0U] = __Vtemp_59[0U];
    __Vtemp_61[1U] = __Vtemp_59[1U];
    __Vtemp_61[2U] = (1U & __Vtemp_59[2U]);
    __Vtemp_63[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_14)
                               ? vlSelfRef.__PVT__buckets_count_14
                               : 0ULL));
    __Vtemp_63[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_14)
                                ? vlSelfRef.__PVT__buckets_count_14
                                : 0ULL) >> 0x20U));
    __Vtemp_63[2U] = 0U;
    __Vtemp_64[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_15)
                               ? vlSelfRef.__PVT__buckets_count_15
                               : 0ULL));
    __Vtemp_64[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_count_15
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
    vlSelfRef.io_resolvedCount[0U] = __Vtemp_74[0U];
    vlSelfRef.io_resolvedCount[1U] = __Vtemp_74[1U];
    vlSelfRef.io_resolvedCount[2U] = (0xfU & __Vtemp_74[2U]);
    vlSelfRef.__PVT___canAccept_T_22 = (1U & ((~ (IData)(vlSelfRef.buckets_valid_7)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_7)));
    vlSelfRef.__PVT__available_5 = ((5U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((4U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_15 = ((0xfU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_46) 
                                        | (vlSelfRef.__PVT__buckets_seq_15 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((3U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_9 = ((9U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_28) 
                                       | (vlSelfRef.__PVT__buckets_seq_9 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_10 = ((0xaU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_31) 
                                        | (vlSelfRef.__PVT__buckets_seq_10 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__3(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_13 = ((0xdU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_40) 
                                        | (vlSelfRef.__PVT__buckets_seq_13 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_14 = ((0xeU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_43) 
                                        | (vlSelfRef.__PVT__buckets_seq_14 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_11 = ((0xbU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_34) 
                                        | (vlSelfRef.__PVT__buckets_seq_11 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_12 = ((0xcU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_37) 
                                        | (vlSelfRef.__PVT__buckets_seq_12 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((6U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_8 = ((8U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_25) 
                                       | (vlSelfRef.__PVT__buckets_seq_8 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_0 = ((0U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((1U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((2U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((7U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.buckets_seq_7 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__accepted_5 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_5));
    vlSelfRef.__PVT__accepted_4 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_4));
    vlSelfRef.__PVT__accepted_15 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_15));
    vlSelfRef.__PVT__accepted_3 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_3));
    vlSelfRef.__PVT__accepted_9 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_9));
    vlSelfRef.__PVT__accepted_10 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_10));
    vlSelfRef.__PVT__accepted_13 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_13));
    vlSelfRef.__PVT__accepted_14 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_14));
    vlSelfRef.__PVT__accepted_11 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_11));
    vlSelfRef.__PVT__accepted_12 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_12));
    vlSelfRef.__PVT__accepted_6 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_6));
    vlSelfRef.__PVT__accepted_8 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_8));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__4(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__4\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__accepted = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                 & (IData)(vlSelfRef.__PVT__available_0));
    vlSelfRef.__PVT__accepted_1 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_1));
    vlSelfRef.__PVT__accepted_2 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_2));
    vlSelfRef.__PVT__accepted_7 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_7));
    vlSelfRef.__PVT___countOverflow_5_T_2 = ((IData)(vlSelfRef.__PVT__accepted_5) 
                                             & (IData)(vlSelfRef.__PVT___GEN_75));
    vlSelfRef.__PVT___countOverflow_4_T_2 = ((IData)(vlSelfRef.__PVT__accepted_4) 
                                             & (IData)(vlSelfRef.__PVT___GEN_60));
    vlSelfRef.__PVT___countOverflow_15_T_2 = ((IData)(vlSelfRef.__PVT__accepted_15) 
                                              & (IData)(vlSelfRef.__PVT___GEN_225));
    vlSelfRef.__PVT___countOverflow_3_T_2 = ((IData)(vlSelfRef.__PVT__accepted_3) 
                                             & (IData)(vlSelfRef.__PVT___GEN_45));
    vlSelfRef.__PVT___countOverflow_9_T_2 = ((IData)(vlSelfRef.__PVT__accepted_9) 
                                             & (IData)(vlSelfRef.__PVT___GEN_135));
    vlSelfRef.__PVT___countOverflow_10_T_2 = ((IData)(vlSelfRef.__PVT__accepted_10) 
                                              & (IData)(vlSelfRef.__PVT___GEN_150));
    vlSelfRef.__PVT___countOverflow_13_T_2 = ((IData)(vlSelfRef.__PVT__accepted_13) 
                                              & (IData)(vlSelfRef.__PVT___GEN_195));
    vlSelfRef.__PVT___countOverflow_14_T_2 = ((IData)(vlSelfRef.__PVT__accepted_14) 
                                              & (IData)(vlSelfRef.__PVT___GEN_210));
    vlSelfRef.__PVT___countOverflow_11_T_2 = ((IData)(vlSelfRef.__PVT__accepted_11) 
                                              & (IData)(vlSelfRef.__PVT___GEN_165));
    vlSelfRef.__PVT___countOverflow_12_T_2 = ((IData)(vlSelfRef.__PVT__accepted_12) 
                                              & (IData)(vlSelfRef.__PVT___GEN_180));
    vlSelfRef.__PVT___countOverflow_6_T_2 = ((IData)(vlSelfRef.__PVT__accepted_6) 
                                             & (IData)(vlSelfRef.__PVT___GEN_90));
    vlSelfRef.__PVT___countOverflow_8_T_2 = ((IData)(vlSelfRef.__PVT__accepted_8) 
                                             & (IData)(vlSelfRef.__PVT___GEN_120));
    vlSelfRef.__PVT___countOverflow_0_T_2 = ((IData)(vlSelfRef.__PVT__accepted) 
                                             & (IData)(vlSelfRef.__PVT___GEN_0));
    vlSelfRef.__PVT___countOverflow_1_T_2 = ((IData)(vlSelfRef.__PVT__accepted_1) 
                                             & (IData)(vlSelfRef.__PVT___GEN_15));
    vlSelfRef.__PVT___countOverflow_2_T_2 = ((IData)(vlSelfRef.__PVT__accepted_2) 
                                             & (IData)(vlSelfRef.__PVT___GEN_30));
    vlSelfRef.__PVT___countOverflow_7_T_2 = ((IData)(vlSelfRef.__PVT__accepted_7) 
                                             & (IData)(vlSelfRef.__PVT___GEN_105));
    vlSelfRef.io_cycleOverflow = (((IData)(vlSelfRef.__PVT___countOverflow_15_T_2) 
                                   & (vlSelfRef.__PVT__buckets_requestCycleSum_15 
                                      > (0xffffffffffffffffULL 
                                         - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                  | (((IData)(vlSelfRef.__PVT___countOverflow_14_T_2) 
                                      & (vlSelfRef.__PVT__buckets_requestCycleSum_14 
                                         > (0xffffffffffffffffULL 
                                            - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                     | (((IData)(vlSelfRef.__PVT___countOverflow_13_T_2) 
                                         & (vlSelfRef.__PVT__buckets_requestCycleSum_13 
                                            > (0xffffffffffffffffULL 
                                               - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                        | (((IData)(vlSelfRef.__PVT___countOverflow_12_T_2) 
                                            & (vlSelfRef.__PVT__buckets_requestCycleSum_12 
                                               > (0xffffffffffffffffULL 
                                                  - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                           | (((IData)(vlSelfRef.__PVT___countOverflow_11_T_2) 
                                               & (vlSelfRef.__PVT__buckets_requestCycleSum_11 
                                                  > 
                                                  (0xffffffffffffffffULL 
                                                   - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                              | (((IData)(vlSelfRef.__PVT___countOverflow_10_T_2) 
                                                  & (vlSelfRef.__PVT__buckets_requestCycleSum_10 
                                                     > 
                                                     (0xffffffffffffffffULL 
                                                      - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                 | (((IData)(vlSelfRef.__PVT___countOverflow_9_T_2) 
                                                     & (vlSelfRef.__PVT__buckets_requestCycleSum_9 
                                                        > 
                                                        (0xffffffffffffffffULL 
                                                         - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                    | (((IData)(vlSelfRef.__PVT___countOverflow_8_T_2) 
                                                        & (vlSelfRef.__PVT__buckets_requestCycleSum_8 
                                                           > 
                                                           (0xffffffffffffffffULL 
                                                            - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                       | (((IData)(vlSelfRef.__PVT___countOverflow_7_T_2) 
                                                           & (vlSelfRef.buckets_requestCycleSum_7 
                                                              > 
                                                              (0xffffffffffffffffULL 
                                                               - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                          | (((IData)(vlSelfRef.__PVT___countOverflow_6_T_2) 
                                                              & (vlSelfRef.__PVT__buckets_requestCycleSum_6 
                                                                 > 
                                                                 (0xffffffffffffffffULL 
                                                                  - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                             | (((IData)(vlSelfRef.__PVT___countOverflow_5_T_2) 
                                                                 & (vlSelfRef.__PVT__buckets_requestCycleSum_5 
                                                                    > 
                                                                    (0xffffffffffffffffULL 
                                                                     - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                                | (((IData)(vlSelfRef.__PVT___countOverflow_4_T_2) 
                                                                    & (vlSelfRef.__PVT__buckets_requestCycleSum_4 
                                                                       > 
                                                                       (0xffffffffffffffffULL 
                                                                        - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                                   | (((IData)(vlSelfRef.__PVT___countOverflow_3_T_2) 
                                                                       & (vlSelfRef.__PVT__buckets_requestCycleSum_3 
                                                                          > 
                                                                          (0xffffffffffffffffULL 
                                                                           - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                                      | (((IData)(vlSelfRef.__PVT___countOverflow_2_T_2) 
                                                                          & (vlSelfRef.__PVT__buckets_requestCycleSum_2 
                                                                             > 
                                                                             (0xffffffffffffffffULL 
                                                                              - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                                         | (((IData)(vlSelfRef.__PVT___countOverflow_1_T_2) 
                                                                             & (vlSelfRef.__PVT__buckets_requestCycleSum_1 
                                                                                > 
                                                                                (0xffffffffffffffffULL 
                                                                                - vlSymsp->TOP.tb__DOT__io_currentCycle))) 
                                                                            | ((IData)(vlSelfRef.__PVT___countOverflow_0_T_2) 
                                                                               & (vlSelfRef.__PVT__buckets_requestCycleSum_0 
                                                                                > 
                                                                                (0xffffffffffffffffULL 
                                                                                - vlSymsp->TOP.tb__DOT__io_currentCycle))))))))))))))))));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__0(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_requestCycleSum_0_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_0 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_1_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_1 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_2_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_2 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_3_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_3 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_4_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_4 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_5_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_5 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_6_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_6 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_7_T_1 
        = (vlSelfRef.buckets_requestCycleSum_7 + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_8_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_8 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_9_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_9 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_10_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_10 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_11_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_11 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_12_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_12 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_13_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_13 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_14_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_14 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_15_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_15 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT__resolving_0 = ((IData)(vlSelfRef.__PVT__buckets_valid_0) 
                                    & (vlSelfRef.__PVT__buckets_seq_0 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_1 = ((IData)(vlSelfRef.__PVT__buckets_valid_1) 
                                    & (vlSelfRef.__PVT__buckets_seq_1 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_2 = ((IData)(vlSelfRef.__PVT__buckets_valid_2) 
                                    & (vlSelfRef.__PVT__buckets_seq_2 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_3 = ((IData)(vlSelfRef.__PVT__buckets_valid_3) 
                                    & (vlSelfRef.__PVT__buckets_seq_3 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_4 = ((IData)(vlSelfRef.__PVT__buckets_valid_4) 
                                    & (vlSelfRef.__PVT__buckets_seq_4 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_5 = ((IData)(vlSelfRef.__PVT__buckets_valid_5) 
                                    & (vlSelfRef.__PVT__buckets_seq_5 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_6 = ((IData)(vlSelfRef.__PVT__buckets_valid_6) 
                                    & (vlSelfRef.__PVT__buckets_seq_6 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_7 = ((IData)(vlSelfRef.buckets_valid_7) 
                                    & (vlSelfRef.buckets_seq_7 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_8 = ((IData)(vlSelfRef.__PVT__buckets_valid_8) 
                                    & (vlSelfRef.__PVT__buckets_seq_8 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_9 = ((IData)(vlSelfRef.__PVT__buckets_valid_9) 
                                    & (vlSelfRef.__PVT__buckets_seq_9 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_10 = ((IData)(vlSelfRef.__PVT__buckets_valid_10) 
                                     & (vlSelfRef.__PVT__buckets_seq_10 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_11 = ((IData)(vlSelfRef.__PVT__buckets_valid_11) 
                                     & (vlSelfRef.__PVT__buckets_seq_11 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_12 = ((IData)(vlSelfRef.__PVT__buckets_valid_12) 
                                     & (vlSelfRef.__PVT__buckets_seq_12 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_13 = ((IData)(vlSelfRef.__PVT__buckets_valid_13) 
                                     & (vlSelfRef.__PVT__buckets_seq_13 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_14 = ((IData)(vlSelfRef.__PVT__buckets_valid_14) 
                                     & (vlSelfRef.__PVT__buckets_seq_14 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_15 = ((IData)(vlSelfRef.__PVT__buckets_valid_15) 
                                     & (vlSelfRef.__PVT__buckets_seq_15 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__eventNeedsBucket = ((IData)(vlSymsp->TOP.tb__DOT__io_event_valid) 
                                         & (vlSymsp->TOP.tb__DOT__io_event_bits 
                                            > vlSymsp->TOP.tb__DOT__io_safeWatermark));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__2\n"); );
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
    vlSelfRef.__PVT___GEN_225 = ((~ (IData)(vlSelfRef.__PVT__resolving_15)) 
                                 & (IData)(vlSelfRef.__PVT__buckets_valid_15));
    __Vtemp_5[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                              ? vlSelfRef.__PVT__buckets_count_0
                              : 0ULL));
    __Vtemp_5[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_count_0
                               : 0ULL) >> 0x20U));
    __Vtemp_5[2U] = 0U;
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_1)
                              ? vlSelfRef.__PVT__buckets_count_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_1)
                               ? vlSelfRef.__PVT__buckets_count_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    VL_ADD_W(3, __Vtemp_7, __Vtemp_5, __Vtemp_6);
    __Vtemp_9[0U] = __Vtemp_7[0U];
    __Vtemp_9[1U] = __Vtemp_7[1U];
    __Vtemp_9[2U] = (1U & __Vtemp_7[2U]);
    __Vtemp_11[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_2)
                               ? vlSelfRef.__PVT__buckets_count_2
                               : 0ULL));
    __Vtemp_11[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_2)
                                ? vlSelfRef.__PVT__buckets_count_2
                                : 0ULL) >> 0x20U));
    __Vtemp_11[2U] = 0U;
    __Vtemp_12[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_3)
                               ? vlSelfRef.__PVT__buckets_count_3
                               : 0ULL));
    __Vtemp_12[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_3)
                                ? vlSelfRef.__PVT__buckets_count_3
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
                               ? vlSelfRef.__PVT__buckets_count_4
                               : 0ULL));
    __Vtemp_21[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_4)
                                ? vlSelfRef.__PVT__buckets_count_4
                                : 0ULL) >> 0x20U));
    __Vtemp_21[2U] = 0U;
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_5)
                               ? vlSelfRef.__PVT__buckets_count_5
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_5)
                                ? vlSelfRef.__PVT__buckets_count_5
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    VL_ADD_W(3, __Vtemp_23, __Vtemp_21, __Vtemp_22);
    __Vtemp_25[0U] = __Vtemp_23[0U];
    __Vtemp_25[1U] = __Vtemp_23[1U];
    __Vtemp_25[2U] = (1U & __Vtemp_23[2U]);
    __Vtemp_27[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_6)
                               ? vlSelfRef.__PVT__buckets_count_6
                               : 0ULL));
    __Vtemp_27[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_6)
                                ? vlSelfRef.__PVT__buckets_count_6
                                : 0ULL) >> 0x20U));
    __Vtemp_27[2U] = 0U;
    __Vtemp_28[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_7)
                               ? vlSelfRef.buckets_count_7
                               : 0ULL));
    __Vtemp_28[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_count_7
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
                               ? vlSelfRef.__PVT__buckets_count_8
                               : 0ULL));
    __Vtemp_41[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_8)
                                ? vlSelfRef.__PVT__buckets_count_8
                                : 0ULL) >> 0x20U));
    __Vtemp_41[2U] = 0U;
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_9)
                               ? vlSelfRef.__PVT__buckets_count_9
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_9)
                                ? vlSelfRef.__PVT__buckets_count_9
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    VL_ADD_W(3, __Vtemp_43, __Vtemp_41, __Vtemp_42);
    __Vtemp_45[0U] = __Vtemp_43[0U];
    __Vtemp_45[1U] = __Vtemp_43[1U];
    __Vtemp_45[2U] = (1U & __Vtemp_43[2U]);
    __Vtemp_47[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_10)
                               ? vlSelfRef.__PVT__buckets_count_10
                               : 0ULL));
    __Vtemp_47[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_10)
                                ? vlSelfRef.__PVT__buckets_count_10
                                : 0ULL) >> 0x20U));
    __Vtemp_47[2U] = 0U;
    __Vtemp_48[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_11)
                               ? vlSelfRef.__PVT__buckets_count_11
                               : 0ULL));
    __Vtemp_48[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_11)
                                ? vlSelfRef.__PVT__buckets_count_11
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
                               ? vlSelfRef.__PVT__buckets_count_12
                               : 0ULL));
    __Vtemp_57[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_12)
                                ? vlSelfRef.__PVT__buckets_count_12
                                : 0ULL) >> 0x20U));
    __Vtemp_57[2U] = 0U;
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_13)
                               ? vlSelfRef.__PVT__buckets_count_13
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_13)
                                ? vlSelfRef.__PVT__buckets_count_13
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    VL_ADD_W(3, __Vtemp_59, __Vtemp_57, __Vtemp_58);
    __Vtemp_61[0U] = __Vtemp_59[0U];
    __Vtemp_61[1U] = __Vtemp_59[1U];
    __Vtemp_61[2U] = (1U & __Vtemp_59[2U]);
    __Vtemp_63[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_14)
                               ? vlSelfRef.__PVT__buckets_count_14
                               : 0ULL));
    __Vtemp_63[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_14)
                                ? vlSelfRef.__PVT__buckets_count_14
                                : 0ULL) >> 0x20U));
    __Vtemp_63[2U] = 0U;
    __Vtemp_64[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_15)
                               ? vlSelfRef.__PVT__buckets_count_15
                               : 0ULL));
    __Vtemp_64[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_count_15
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
    vlSelfRef.io_resolvedCount[0U] = __Vtemp_74[0U];
    vlSelfRef.io_resolvedCount[1U] = __Vtemp_74[1U];
    vlSelfRef.io_resolvedCount[2U] = (0xfU & __Vtemp_74[2U]);
    vlSelfRef.__PVT___canAccept_T_46 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_15)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_15)));
    vlSelfRef.__PVT__available_0 = ((0x10U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x11U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x12U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x13U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x14U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x15U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__3(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_6 = ((0x16U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x17U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.buckets_seq_7 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_8 = ((0x18U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_25) 
                                       | (vlSelfRef.__PVT__buckets_seq_8 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_9 = ((0x19U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_28) 
                                       | (vlSelfRef.__PVT__buckets_seq_9 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_10 = ((0x1aU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_31) 
                                        | (vlSelfRef.__PVT__buckets_seq_10 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_11 = ((0x1bU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_34) 
                                        | (vlSelfRef.__PVT__buckets_seq_11 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_12 = ((0x1cU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_37) 
                                        | (vlSelfRef.__PVT__buckets_seq_12 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_13 = ((0x1dU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_40) 
                                        | (vlSelfRef.__PVT__buckets_seq_13 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_14 = ((0x1eU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_43) 
                                        | (vlSelfRef.__PVT__buckets_seq_14 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_15 = ((0x1fU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_46) 
                                        | (vlSelfRef.__PVT__buckets_seq_15 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__accepted = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                 & (IData)(vlSelfRef.__PVT__available_0));
    vlSelfRef.__PVT__accepted_1 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_1));
    vlSelfRef.__PVT__accepted_2 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_2));
    vlSelfRef.__PVT__accepted_3 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_3));
    vlSelfRef.__PVT__accepted_4 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_4));
    vlSelfRef.__PVT__accepted_5 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_5));
    vlSelfRef.__PVT__accepted_6 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_6));
    vlSelfRef.__PVT__accepted_7 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_7));
    vlSelfRef.__PVT__accepted_8 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_8));
    vlSelfRef.__PVT__accepted_9 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_9));
    vlSelfRef.__PVT__accepted_10 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_10));
    vlSelfRef.__PVT__accepted_11 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                    & (IData)(vlSelfRef.__PVT__available_11));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.__PVT__buckets_requestCycleSum_12 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_10 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_8 = 0ULL;
        vlSelfRef.buckets_requestCycleSum_7 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_6 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_5 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_4 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_0 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_14 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__buckets_requestCycleSum_12 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_10 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_8 = 0ULL;
        vlSelfRef.buckets_requestCycleSum_7 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_6 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_5 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_4 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_0 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_14 = 0ULL;
    } else {
        if (vlSelfRef.__PVT__accepted_12) {
            vlSelfRef.__PVT__buckets_requestCycleSum_12 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_37)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_12_T_1);
        } else if (vlSelfRef.__PVT__resolving_12) {
            vlSelfRef.__PVT__buckets_requestCycleSum_12 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_10) {
            vlSelfRef.__PVT__buckets_requestCycleSum_10 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_31)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_10_T_1);
        } else if (vlSelfRef.__PVT__resolving_10) {
            vlSelfRef.__PVT__buckets_requestCycleSum_10 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_8) {
            vlSelfRef.__PVT__buckets_requestCycleSum_8 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_25)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_8_T_1);
        } else if (vlSelfRef.__PVT__resolving_8) {
            vlSelfRef.__PVT__buckets_requestCycleSum_8 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_7) {
            vlSelfRef.buckets_requestCycleSum_7 = ((IData)(vlSelfRef.__PVT___canAccept_T_22)
                                                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                                                    : vlSelfRef.__PVT___buckets_requestCycleSum_7_T_1);
        } else if (vlSelfRef.__PVT__resolving_7) {
            vlSelfRef.buckets_requestCycleSum_7 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_6) {
            vlSelfRef.__PVT__buckets_requestCycleSum_6 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_19)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_6_T_1);
        } else if (vlSelfRef.__PVT__resolving_6) {
            vlSelfRef.__PVT__buckets_requestCycleSum_6 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_5) {
            vlSelfRef.__PVT__buckets_requestCycleSum_5 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_16)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_5_T_1);
        } else if (vlSelfRef.__PVT__resolving_5) {
            vlSelfRef.__PVT__buckets_requestCycleSum_5 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_4) {
            vlSelfRef.__PVT__buckets_requestCycleSum_4 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_13)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_4_T_1);
        } else if (vlSelfRef.__PVT__resolving_4) {
            vlSelfRef.__PVT__buckets_requestCycleSum_4 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted) {
            vlSelfRef.__PVT__buckets_requestCycleSum_0 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_1)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_0_T_1);
        } else if (vlSelfRef.__PVT__resolving_0) {
            vlSelfRef.__PVT__buckets_requestCycleSum_0 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_14) {
            vlSelfRef.__PVT__buckets_requestCycleSum_14 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_43)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_14_T_1);
        } else if (vlSelfRef.__PVT__resolving_14) {
            vlSelfRef.__PVT__buckets_requestCycleSum_14 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__3(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__3\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.__PVT__buckets_requestCycleSum_3 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_9 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_11 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_13 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_1 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_2 = 0ULL;
        vlSelfRef.__PVT__buckets_count_13 = 0ULL;
        vlSelfRef.__PVT__buckets_count_10 = 0ULL;
        vlSelfRef.__PVT__buckets_count_9 = 0ULL;
    } else if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__buckets_requestCycleSum_3 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_9 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_11 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_13 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_1 = 0ULL;
        vlSelfRef.__PVT__buckets_requestCycleSum_2 = 0ULL;
        vlSelfRef.__PVT__buckets_count_13 = 0ULL;
        vlSelfRef.__PVT__buckets_count_10 = 0ULL;
        vlSelfRef.__PVT__buckets_count_9 = 0ULL;
    } else {
        if (vlSelfRef.__PVT__accepted_3) {
            vlSelfRef.__PVT__buckets_requestCycleSum_3 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_10)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_3_T_1);
        } else if (vlSelfRef.__PVT__resolving_3) {
            vlSelfRef.__PVT__buckets_requestCycleSum_3 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_9) {
            if (vlSelfRef.__PVT___canAccept_T_28) {
                vlSelfRef.__PVT__buckets_requestCycleSum_9 
                    = vlSymsp->TOP.tb__DOT__io_currentCycle;
                vlSelfRef.__PVT__buckets_count_9 = 1ULL;
            } else {
                vlSelfRef.__PVT__buckets_requestCycleSum_9 
                    = vlSelfRef.__PVT___buckets_requestCycleSum_9_T_1;
                vlSelfRef.__PVT__buckets_count_9 = vlSelfRef.__PVT___buckets_count_9_T_1;
            }
        } else if (vlSelfRef.__PVT__resolving_9) {
            vlSelfRef.__PVT__buckets_requestCycleSum_9 = 0ULL;
            vlSelfRef.__PVT__buckets_count_9 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_11) {
            vlSelfRef.__PVT__buckets_requestCycleSum_11 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_34)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_11_T_1);
        } else if (vlSelfRef.__PVT__resolving_11) {
            vlSelfRef.__PVT__buckets_requestCycleSum_11 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_13) {
            if (vlSelfRef.__PVT___canAccept_T_40) {
                vlSelfRef.__PVT__buckets_requestCycleSum_13 
                    = vlSymsp->TOP.tb__DOT__io_currentCycle;
                vlSelfRef.__PVT__buckets_count_13 = 1ULL;
            } else {
                vlSelfRef.__PVT__buckets_requestCycleSum_13 
                    = vlSelfRef.__PVT___buckets_requestCycleSum_13_T_1;
                vlSelfRef.__PVT__buckets_count_13 = vlSelfRef.__PVT___buckets_count_13_T_1;
            }
        } else if (vlSelfRef.__PVT__resolving_13) {
            vlSelfRef.__PVT__buckets_requestCycleSum_13 = 0ULL;
            vlSelfRef.__PVT__buckets_count_13 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_1) {
            vlSelfRef.__PVT__buckets_requestCycleSum_1 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_4)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_1_T_1);
        } else if (vlSelfRef.__PVT__resolving_1) {
            vlSelfRef.__PVT__buckets_requestCycleSum_1 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_2) {
            vlSelfRef.__PVT__buckets_requestCycleSum_2 
                = ((IData)(vlSelfRef.__PVT___canAccept_T_7)
                    ? vlSymsp->TOP.tb__DOT__io_currentCycle
                    : vlSelfRef.__PVT___buckets_requestCycleSum_2_T_1);
        } else if (vlSelfRef.__PVT__resolving_2) {
            vlSelfRef.__PVT__buckets_requestCycleSum_2 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_10) {
            vlSelfRef.__PVT__buckets_count_10 = ((IData)(vlSelfRef.__PVT___canAccept_T_31)
                                                  ? 1ULL
                                                  : vlSelfRef.__PVT___buckets_count_10_T_1);
        } else if (vlSelfRef.__PVT__resolving_10) {
            vlSelfRef.__PVT__buckets_count_10 = 0ULL;
        }
    }
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__5(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__5\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.__PVT__buckets_count_5 = 0ULL;
        vlSelfRef.buckets_count_7 = 0ULL;
        vlSelfRef.__PVT__buckets_count_11 = 0ULL;
        vlSelfRef.__PVT__buckets_count_15 = 0ULL;
        vlSelfRef.__PVT__buckets_seq_3 = 0U;
        vlSelfRef.__PVT__buckets_seq_2 = 0U;
        vlSelfRef.__PVT__buckets_seq_1 = 0U;
        vlSelfRef.__PVT__buckets_seq_9 = 0U;
        vlSelfRef.__PVT__buckets_seq_10 = 0U;
        vlSelfRef.__PVT__buckets_seq_5 = 0U;
        vlSelfRef.__PVT__buckets_seq_8 = 0U;
    } else if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__buckets_count_5 = 0ULL;
        vlSelfRef.buckets_count_7 = 0ULL;
        vlSelfRef.__PVT__buckets_count_11 = 0ULL;
        vlSelfRef.__PVT__buckets_count_15 = 0ULL;
        vlSelfRef.__PVT__buckets_seq_3 = 0U;
        vlSelfRef.__PVT__buckets_seq_2 = 0U;
        vlSelfRef.__PVT__buckets_seq_1 = 0U;
        vlSelfRef.__PVT__buckets_seq_9 = 0U;
        vlSelfRef.__PVT__buckets_seq_10 = 0U;
        vlSelfRef.__PVT__buckets_seq_5 = 0U;
        vlSelfRef.__PVT__buckets_seq_8 = 0U;
    } else {
        if (vlSelfRef.__PVT__accepted_5) {
            if (vlSelfRef.__PVT___canAccept_T_16) {
                vlSelfRef.__PVT__buckets_count_5 = 1ULL;
                vlSelfRef.__PVT__buckets_seq_5 = vlSymsp->TOP.tb__DOT__io_event_bits;
            } else {
                vlSelfRef.__PVT__buckets_count_5 = vlSelfRef.__PVT___buckets_count_5_T_1;
            }
        } else if (vlSelfRef.__PVT__resolving_5) {
            vlSelfRef.__PVT__buckets_count_5 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_7) {
            vlSelfRef.buckets_count_7 = ((IData)(vlSelfRef.__PVT___canAccept_T_22)
                                          ? 1ULL : vlSelfRef.__PVT___buckets_count_7_T_1);
        } else if (vlSelfRef.__PVT__resolving_7) {
            vlSelfRef.buckets_count_7 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_11) {
            vlSelfRef.__PVT__buckets_count_11 = ((IData)(vlSelfRef.__PVT___canAccept_T_34)
                                                  ? 1ULL
                                                  : vlSelfRef.__PVT___buckets_count_11_T_1);
        } else if (vlSelfRef.__PVT__resolving_11) {
            vlSelfRef.__PVT__buckets_count_11 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_15) {
            vlSelfRef.__PVT__buckets_count_15 = ((IData)(vlSelfRef.__PVT___canAccept_T_46)
                                                  ? 1ULL
                                                  : vlSelfRef.__PVT___buckets_count_15_T_1);
        } else if (vlSelfRef.__PVT__resolving_15) {
            vlSelfRef.__PVT__buckets_count_15 = 0ULL;
        }
        if (vlSelfRef.__PVT__accepted_3) {
            if (vlSelfRef.__PVT___canAccept_T_10) {
                vlSelfRef.__PVT__buckets_seq_3 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_2) {
            if (vlSelfRef.__PVT___canAccept_T_7) {
                vlSelfRef.__PVT__buckets_seq_2 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_1) {
            if (vlSelfRef.__PVT___canAccept_T_4) {
                vlSelfRef.__PVT__buckets_seq_1 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_9) {
            if (vlSelfRef.__PVT___canAccept_T_28) {
                vlSelfRef.__PVT__buckets_seq_9 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_10) {
            if (vlSelfRef.__PVT___canAccept_T_31) {
                vlSelfRef.__PVT__buckets_seq_10 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_8) {
            if (vlSelfRef.__PVT___canAccept_T_25) {
                vlSelfRef.__PVT__buckets_seq_8 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
    }
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__6(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__6\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.buckets_seq_7 = 0U;
        vlSelfRef.__PVT__buckets_seq_0 = 0U;
        vlSelfRef.__PVT__buckets_seq_6 = 0U;
        vlSelfRef.__PVT__buckets_seq_4 = 0U;
        vlSelfRef.__PVT__buckets_seq_11 = 0U;
        vlSelfRef.__PVT__buckets_seq_12 = 0U;
        vlSelfRef.__PVT__buckets_seq_13 = 0U;
        vlSelfRef.__PVT__buckets_seq_14 = 0U;
        vlSelfRef.__PVT__buckets_seq_15 = 0U;
        vlSelfRef.__PVT__buckets_valid_5 = 0U;
        vlSelfRef.__PVT__buckets_valid_4 = 0U;
        vlSelfRef.__PVT__buckets_valid_15 = 0U;
    } else if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.buckets_seq_7 = 0U;
        vlSelfRef.__PVT__buckets_seq_0 = 0U;
        vlSelfRef.__PVT__buckets_seq_6 = 0U;
        vlSelfRef.__PVT__buckets_seq_4 = 0U;
        vlSelfRef.__PVT__buckets_seq_11 = 0U;
        vlSelfRef.__PVT__buckets_seq_12 = 0U;
        vlSelfRef.__PVT__buckets_seq_13 = 0U;
        vlSelfRef.__PVT__buckets_seq_14 = 0U;
        vlSelfRef.__PVT__buckets_seq_15 = 0U;
        vlSelfRef.__PVT__buckets_valid_5 = 0U;
        vlSelfRef.__PVT__buckets_valid_4 = 0U;
        vlSelfRef.__PVT__buckets_valid_15 = 0U;
    } else {
        if (vlSelfRef.__PVT__accepted_7) {
            if (vlSelfRef.__PVT___canAccept_T_22) {
                vlSelfRef.buckets_seq_7 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted) {
            if (vlSelfRef.__PVT___canAccept_T_1) {
                vlSelfRef.__PVT__buckets_seq_0 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_6) {
            if (vlSelfRef.__PVT___canAccept_T_19) {
                vlSelfRef.__PVT__buckets_seq_6 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_4) {
            if (vlSelfRef.__PVT___canAccept_T_13) {
                vlSelfRef.__PVT__buckets_seq_4 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
            vlSelfRef.__PVT__buckets_valid_4 = ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                                | (IData)(vlSelfRef.__PVT___GEN_60));
        } else if (vlSelfRef.__PVT__resolving_4) {
            vlSelfRef.__PVT__buckets_valid_4 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_11) {
            if (vlSelfRef.__PVT___canAccept_T_34) {
                vlSelfRef.__PVT__buckets_seq_11 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_12) {
            if (vlSelfRef.__PVT___canAccept_T_37) {
                vlSelfRef.__PVT__buckets_seq_12 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_13) {
            if (vlSelfRef.__PVT___canAccept_T_40) {
                vlSelfRef.__PVT__buckets_seq_13 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_14) {
            if (vlSelfRef.__PVT___canAccept_T_43) {
                vlSelfRef.__PVT__buckets_seq_14 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
        }
        if (vlSelfRef.__PVT__accepted_15) {
            if (vlSelfRef.__PVT___canAccept_T_46) {
                vlSelfRef.__PVT__buckets_seq_15 = vlSymsp->TOP.tb__DOT__io_event_bits;
            }
            vlSelfRef.__PVT__buckets_valid_15 = ((IData)(vlSelfRef.__PVT___canAccept_T_46) 
                                                 | (IData)(vlSelfRef.__PVT___GEN_225));
        } else if (vlSelfRef.__PVT__resolving_15) {
            vlSelfRef.__PVT__buckets_valid_15 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_5) {
            vlSelfRef.__PVT__buckets_valid_5 = ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                                | (IData)(vlSelfRef.__PVT___GEN_75));
        } else if (vlSelfRef.__PVT__resolving_5) {
            vlSelfRef.__PVT__buckets_valid_5 = 0U;
        }
    }
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__7(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__7\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.__PVT__buckets_valid_3 = 0U;
        vlSelfRef.__PVT__buckets_valid_9 = 0U;
        vlSelfRef.__PVT__buckets_valid_10 = 0U;
        vlSelfRef.__PVT__buckets_valid_13 = 0U;
        vlSelfRef.__PVT__buckets_valid_14 = 0U;
        vlSelfRef.__PVT__buckets_valid_11 = 0U;
        vlSelfRef.__PVT__buckets_valid_12 = 0U;
        vlSelfRef.__PVT__buckets_valid_6 = 0U;
        vlSelfRef.buckets_valid_7 = 0U;
        vlSelfRef.__PVT__buckets_valid_8 = 0U;
    } else if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__buckets_valid_3 = 0U;
        vlSelfRef.__PVT__buckets_valid_9 = 0U;
        vlSelfRef.__PVT__buckets_valid_10 = 0U;
        vlSelfRef.__PVT__buckets_valid_13 = 0U;
        vlSelfRef.__PVT__buckets_valid_14 = 0U;
        vlSelfRef.__PVT__buckets_valid_11 = 0U;
        vlSelfRef.__PVT__buckets_valid_12 = 0U;
        vlSelfRef.__PVT__buckets_valid_6 = 0U;
        vlSelfRef.buckets_valid_7 = 0U;
        vlSelfRef.__PVT__buckets_valid_8 = 0U;
    } else {
        if (vlSelfRef.__PVT__accepted_3) {
            vlSelfRef.__PVT__buckets_valid_3 = ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                                | (IData)(vlSelfRef.__PVT___GEN_45));
        } else if (vlSelfRef.__PVT__resolving_3) {
            vlSelfRef.__PVT__buckets_valid_3 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_9) {
            vlSelfRef.__PVT__buckets_valid_9 = ((IData)(vlSelfRef.__PVT___canAccept_T_28) 
                                                | (IData)(vlSelfRef.__PVT___GEN_135));
        } else if (vlSelfRef.__PVT__resolving_9) {
            vlSelfRef.__PVT__buckets_valid_9 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_10) {
            vlSelfRef.__PVT__buckets_valid_10 = ((IData)(vlSelfRef.__PVT___canAccept_T_31) 
                                                 | (IData)(vlSelfRef.__PVT___GEN_150));
        } else if (vlSelfRef.__PVT__resolving_10) {
            vlSelfRef.__PVT__buckets_valid_10 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_13) {
            vlSelfRef.__PVT__buckets_valid_13 = ((IData)(vlSelfRef.__PVT___canAccept_T_40) 
                                                 | (IData)(vlSelfRef.__PVT___GEN_195));
        } else if (vlSelfRef.__PVT__resolving_13) {
            vlSelfRef.__PVT__buckets_valid_13 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_14) {
            vlSelfRef.__PVT__buckets_valid_14 = ((IData)(vlSelfRef.__PVT___canAccept_T_43) 
                                                 | (IData)(vlSelfRef.__PVT___GEN_210));
        } else if (vlSelfRef.__PVT__resolving_14) {
            vlSelfRef.__PVT__buckets_valid_14 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_11) {
            vlSelfRef.__PVT__buckets_valid_11 = ((IData)(vlSelfRef.__PVT___canAccept_T_34) 
                                                 | (IData)(vlSelfRef.__PVT___GEN_165));
        } else if (vlSelfRef.__PVT__resolving_11) {
            vlSelfRef.__PVT__buckets_valid_11 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_12) {
            vlSelfRef.__PVT__buckets_valid_12 = ((IData)(vlSelfRef.__PVT___canAccept_T_37) 
                                                 | (IData)(vlSelfRef.__PVT___GEN_180));
        } else if (vlSelfRef.__PVT__resolving_12) {
            vlSelfRef.__PVT__buckets_valid_12 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_6) {
            vlSelfRef.__PVT__buckets_valid_6 = ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                                | (IData)(vlSelfRef.__PVT___GEN_90));
        } else if (vlSelfRef.__PVT__resolving_6) {
            vlSelfRef.__PVT__buckets_valid_6 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_7) {
            vlSelfRef.buckets_valid_7 = ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                         | (IData)(vlSelfRef.__PVT___GEN_105));
        } else if (vlSelfRef.__PVT__resolving_7) {
            vlSelfRef.buckets_valid_7 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_8) {
            vlSelfRef.__PVT__buckets_valid_8 = ((IData)(vlSelfRef.__PVT___canAccept_T_25) 
                                                | (IData)(vlSelfRef.__PVT___GEN_120));
        } else if (vlSelfRef.__PVT__resolving_8) {
            vlSelfRef.__PVT__buckets_valid_8 = 0U;
        }
    }
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__8(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__8\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.tb__DOT__reset) {
        vlSelfRef.__PVT__buckets_valid_0 = 0U;
        vlSelfRef.__PVT__buckets_valid_1 = 0U;
        vlSelfRef.__PVT__buckets_valid_2 = 0U;
    } else if (vlSymsp->TOP.tb__DOT__io_resetStats) {
        vlSelfRef.__PVT__buckets_valid_0 = 0U;
        vlSelfRef.__PVT__buckets_valid_1 = 0U;
        vlSelfRef.__PVT__buckets_valid_2 = 0U;
    } else {
        if (vlSelfRef.__PVT__accepted) {
            vlSelfRef.__PVT__buckets_valid_0 = ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                                | (IData)(vlSelfRef.__PVT___GEN_0));
        } else if (vlSelfRef.__PVT__resolving_0) {
            vlSelfRef.__PVT__buckets_valid_0 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_1) {
            vlSelfRef.__PVT__buckets_valid_1 = ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                                | (IData)(vlSelfRef.__PVT___GEN_15));
        } else if (vlSelfRef.__PVT__resolving_1) {
            vlSelfRef.__PVT__buckets_valid_1 = 0U;
        }
        if (vlSelfRef.__PVT__accepted_2) {
            vlSelfRef.__PVT__buckets_valid_2 = ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                                | (IData)(vlSelfRef.__PVT___GEN_30));
        } else if (vlSelfRef.__PVT__resolving_2) {
            vlSelfRef.__PVT__buckets_valid_2 = 0U;
        }
    }
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__0(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_requestCycleSum_15_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_15 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_12_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_12 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_10_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_10 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_8_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_8 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_7_T_1 
        = (vlSelfRef.buckets_requestCycleSum_7 + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_6_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_6 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_5_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_5 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_4_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_4 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_0_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_0 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_14_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_14 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_3_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_3 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_9_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_9 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_11_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_11 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_13_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_13 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_1_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_1 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_2_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_2 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT__resolving_5 = ((IData)(vlSelfRef.__PVT__buckets_valid_5) 
                                    & (vlSelfRef.__PVT__buckets_seq_5 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_4 = ((IData)(vlSelfRef.__PVT__buckets_valid_4) 
                                    & (vlSelfRef.__PVT__buckets_seq_4 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_15 = ((IData)(vlSelfRef.__PVT__buckets_valid_15) 
                                     & (vlSelfRef.__PVT__buckets_seq_15 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_3 = ((IData)(vlSelfRef.__PVT__buckets_valid_3) 
                                    & (vlSelfRef.__PVT__buckets_seq_3 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_9 = ((IData)(vlSelfRef.__PVT__buckets_valid_9) 
                                    & (vlSelfRef.__PVT__buckets_seq_9 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_10 = ((IData)(vlSelfRef.__PVT__buckets_valid_10) 
                                     & (vlSelfRef.__PVT__buckets_seq_10 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_13 = ((IData)(vlSelfRef.__PVT__buckets_valid_13) 
                                     & (vlSelfRef.__PVT__buckets_seq_13 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_14 = ((IData)(vlSelfRef.__PVT__buckets_valid_14) 
                                     & (vlSelfRef.__PVT__buckets_seq_14 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_11 = ((IData)(vlSelfRef.__PVT__buckets_valid_11) 
                                     & (vlSelfRef.__PVT__buckets_seq_11 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_12 = ((IData)(vlSelfRef.__PVT__buckets_valid_12) 
                                     & (vlSelfRef.__PVT__buckets_seq_12 
                                        <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_6 = ((IData)(vlSelfRef.__PVT__buckets_valid_6) 
                                    & (vlSelfRef.__PVT__buckets_seq_6 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_7 = ((IData)(vlSelfRef.buckets_valid_7) 
                                    & (vlSelfRef.buckets_seq_7 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_8 = ((IData)(vlSelfRef.__PVT__buckets_valid_8) 
                                    & (vlSelfRef.__PVT__buckets_seq_8 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_0 = ((IData)(vlSelfRef.__PVT__buckets_valid_0) 
                                    & (vlSelfRef.__PVT__buckets_seq_0 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_1 = ((IData)(vlSelfRef.__PVT__buckets_valid_1) 
                                    & (vlSelfRef.__PVT__buckets_seq_1 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_2 = ((IData)(vlSelfRef.__PVT__buckets_valid_2) 
                                    & (vlSelfRef.__PVT__buckets_seq_2 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT___GEN_75 = ((~ (IData)(vlSelfRef.__PVT__resolving_5)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_5));
    vlSelfRef.__PVT___canAccept_T_16 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_5)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_5)));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__2\n"); );
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
    vlSelfRef.__PVT___GEN_30 = ((~ (IData)(vlSelfRef.__PVT__resolving_2)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_2));
    __Vtemp_5[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_0)
                              ? vlSelfRef.__PVT__buckets_count_0
                              : 0ULL));
    __Vtemp_5[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_0)
                               ? vlSelfRef.__PVT__buckets_count_0
                               : 0ULL) >> 0x20U));
    __Vtemp_5[2U] = 0U;
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_1)
                              ? vlSelfRef.__PVT__buckets_count_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_1)
                               ? vlSelfRef.__PVT__buckets_count_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    VL_ADD_W(3, __Vtemp_7, __Vtemp_5, __Vtemp_6);
    __Vtemp_9[0U] = __Vtemp_7[0U];
    __Vtemp_9[1U] = __Vtemp_7[1U];
    __Vtemp_9[2U] = (1U & __Vtemp_7[2U]);
    __Vtemp_11[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_2)
                               ? vlSelfRef.__PVT__buckets_count_2
                               : 0ULL));
    __Vtemp_11[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_2)
                                ? vlSelfRef.__PVT__buckets_count_2
                                : 0ULL) >> 0x20U));
    __Vtemp_11[2U] = 0U;
    __Vtemp_12[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_3)
                               ? vlSelfRef.__PVT__buckets_count_3
                               : 0ULL));
    __Vtemp_12[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_3)
                                ? vlSelfRef.__PVT__buckets_count_3
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
                               ? vlSelfRef.__PVT__buckets_count_4
                               : 0ULL));
    __Vtemp_21[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_4)
                                ? vlSelfRef.__PVT__buckets_count_4
                                : 0ULL) >> 0x20U));
    __Vtemp_21[2U] = 0U;
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_5)
                               ? vlSelfRef.__PVT__buckets_count_5
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_5)
                                ? vlSelfRef.__PVT__buckets_count_5
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    VL_ADD_W(3, __Vtemp_23, __Vtemp_21, __Vtemp_22);
    __Vtemp_25[0U] = __Vtemp_23[0U];
    __Vtemp_25[1U] = __Vtemp_23[1U];
    __Vtemp_25[2U] = (1U & __Vtemp_23[2U]);
    __Vtemp_27[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_6)
                               ? vlSelfRef.__PVT__buckets_count_6
                               : 0ULL));
    __Vtemp_27[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_6)
                                ? vlSelfRef.__PVT__buckets_count_6
                                : 0ULL) >> 0x20U));
    __Vtemp_27[2U] = 0U;
    __Vtemp_28[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_7)
                               ? vlSelfRef.buckets_count_7
                               : 0ULL));
    __Vtemp_28[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_7)
                                ? vlSelfRef.buckets_count_7
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
                               ? vlSelfRef.__PVT__buckets_count_8
                               : 0ULL));
    __Vtemp_41[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_8)
                                ? vlSelfRef.__PVT__buckets_count_8
                                : 0ULL) >> 0x20U));
    __Vtemp_41[2U] = 0U;
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_9)
                               ? vlSelfRef.__PVT__buckets_count_9
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_9)
                                ? vlSelfRef.__PVT__buckets_count_9
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    VL_ADD_W(3, __Vtemp_43, __Vtemp_41, __Vtemp_42);
    __Vtemp_45[0U] = __Vtemp_43[0U];
    __Vtemp_45[1U] = __Vtemp_43[1U];
    __Vtemp_45[2U] = (1U & __Vtemp_43[2U]);
    __Vtemp_47[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_10)
                               ? vlSelfRef.__PVT__buckets_count_10
                               : 0ULL));
    __Vtemp_47[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_10)
                                ? vlSelfRef.__PVT__buckets_count_10
                                : 0ULL) >> 0x20U));
    __Vtemp_47[2U] = 0U;
    __Vtemp_48[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_11)
                               ? vlSelfRef.__PVT__buckets_count_11
                               : 0ULL));
    __Vtemp_48[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_11)
                                ? vlSelfRef.__PVT__buckets_count_11
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
                               ? vlSelfRef.__PVT__buckets_count_12
                               : 0ULL));
    __Vtemp_57[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_12)
                                ? vlSelfRef.__PVT__buckets_count_12
                                : 0ULL) >> 0x20U));
    __Vtemp_57[2U] = 0U;
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_13)
                               ? vlSelfRef.__PVT__buckets_count_13
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_13)
                                ? vlSelfRef.__PVT__buckets_count_13
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    VL_ADD_W(3, __Vtemp_59, __Vtemp_57, __Vtemp_58);
    __Vtemp_61[0U] = __Vtemp_59[0U];
    __Vtemp_61[1U] = __Vtemp_59[1U];
    __Vtemp_61[2U] = (1U & __Vtemp_59[2U]);
    __Vtemp_63[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_14)
                               ? vlSelfRef.__PVT__buckets_count_14
                               : 0ULL));
    __Vtemp_63[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_14)
                                ? vlSelfRef.__PVT__buckets_count_14
                                : 0ULL) >> 0x20U));
    __Vtemp_63[2U] = 0U;
    __Vtemp_64[0U] = (IData)(((IData)(vlSelfRef.__PVT__resolving_15)
                               ? vlSelfRef.__PVT__buckets_count_15
                               : 0ULL));
    __Vtemp_64[1U] = (IData)((((IData)(vlSelfRef.__PVT__resolving_15)
                                ? vlSelfRef.__PVT__buckets_count_15
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
    vlSelfRef.io_resolvedCount[0U] = __Vtemp_74[0U];
    vlSelfRef.io_resolvedCount[1U] = __Vtemp_74[1U];
    vlSelfRef.io_resolvedCount[2U] = (0xfU & __Vtemp_74[2U]);
    vlSelfRef.__PVT___canAccept_T_7 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_2)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_2)));
    vlSelfRef.__PVT__available_5 = ((0x15U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x14U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_15 = ((0x1fU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_46) 
                                        | (vlSelfRef.__PVT__buckets_seq_15 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x13U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_9 = ((0x19U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_28) 
                                       | (vlSelfRef.__PVT__buckets_seq_9 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_10 = ((0x1aU == (0xffU 
                                                & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_31) 
                                        | (vlSelfRef.__PVT__buckets_seq_10 
                                           == vlSymsp->TOP.tb__DOT__io_event_bits)));
}
