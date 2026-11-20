// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_GHBarrierBucketBank.h"
#include "Vtb__Syms.h"

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_26__0(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_26__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_requestCycleSum_5_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_5 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_3_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_3 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_6_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_6 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_1_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_1 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_7_T_1 
        = (vlSelfRef.buckets_requestCycleSum_7 + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_2_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_2 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_4_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_4 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_0_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_0 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT__resolving_7 = ((IData)(vlSelfRef.buckets_valid_7) 
                                    & (vlSelfRef.buckets_seq_7 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_6 = ((IData)(vlSelfRef.__PVT__buckets_valid_6) 
                                    & (vlSelfRef.__PVT__buckets_seq_6 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_2 = ((IData)(vlSelfRef.__PVT__buckets_valid_2) 
                                    & (vlSelfRef.__PVT__buckets_seq_2 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_1 = ((IData)(vlSelfRef.__PVT__buckets_valid_1) 
                                    & (vlSelfRef.__PVT__buckets_seq_1 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_3 = ((IData)(vlSelfRef.__PVT__buckets_valid_3) 
                                    & (vlSelfRef.__PVT__buckets_seq_3 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_4 = ((IData)(vlSelfRef.__PVT__buckets_valid_4) 
                                    & (vlSelfRef.__PVT__buckets_seq_4 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_0 = ((IData)(vlSelfRef.__PVT__buckets_valid_0) 
                                    & (vlSelfRef.__PVT__buckets_seq_0 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_5 = ((IData)(vlSelfRef.__PVT__buckets_valid_5) 
                                    & (vlSelfRef.__PVT__buckets_seq_5 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT___GEN_105 = ((~ (IData)(vlSelfRef.__PVT__resolving_7)) 
                                 & (IData)(vlSelfRef.buckets_valid_7));
    vlSelfRef.__PVT___canAccept_T_22 = (1U & ((~ (IData)(vlSelfRef.buckets_valid_7)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_7)));
    vlSelfRef.__PVT___GEN_90 = ((~ (IData)(vlSelfRef.__PVT__resolving_6)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_6));
    vlSelfRef.__PVT___canAccept_T_19 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_6)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_6)));
    vlSelfRef.__PVT___GEN_30 = ((~ (IData)(vlSelfRef.__PVT__resolving_2)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_2));
    vlSelfRef.__PVT___canAccept_T_7 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_2)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_2)));
    vlSelfRef.__PVT___GEN_15 = ((~ (IData)(vlSelfRef.__PVT__resolving_1)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_1));
    vlSelfRef.__PVT___canAccept_T_4 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_1)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_1)));
    vlSelfRef.__PVT___GEN_45 = ((~ (IData)(vlSelfRef.__PVT__resolving_3)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_3));
    vlSelfRef.__PVT___canAccept_T_10 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_3)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_3)));
    vlSelfRef.__PVT___GEN_60 = ((~ (IData)(vlSelfRef.__PVT__resolving_4)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_4));
    vlSelfRef.__PVT___canAccept_T_13 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_4)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_4)));
    vlSelfRef.__PVT___GEN_0 = ((~ (IData)(vlSelfRef.__PVT__resolving_0)) 
                               & (IData)(vlSelfRef.__PVT__buckets_valid_0));
    vlSelfRef.__PVT___canAccept_T_1 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_0)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_0)));
    vlSelfRef.__PVT___GEN_75 = ((~ (IData)(vlSelfRef.__PVT__resolving_5)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_5));
    vlSelfRef.__PVT___canAccept_T_16 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_5)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_5)));
    vlSelfRef.__PVT__available_7 = ((0xd7U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.buckets_seq_7 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_26__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_26__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_6 = ((0xd6U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xd2U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xd1U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xd3U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xd4U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_0 = ((0xd0U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xd5U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__accepted_7 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_7));
    vlSelfRef.__PVT__accepted_6 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_6));
    vlSelfRef.__PVT__accepted_2 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_2));
    vlSelfRef.__PVT__accepted_1 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_1));
    vlSelfRef.__PVT__accepted_3 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_3));
    vlSelfRef.__PVT__accepted_4 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_4));
    vlSelfRef.__PVT__accepted = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                 & (IData)(vlSelfRef.__PVT__available_0));
    vlSelfRef.__PVT__accepted_5 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_5));
    vlSelfRef.__PVT___countOverflow_7_T_2 = ((IData)(vlSelfRef.__PVT__accepted_7) 
                                             & (IData)(vlSelfRef.__PVT___GEN_105));
    vlSelfRef.__PVT___countOverflow_6_T_2 = ((IData)(vlSelfRef.__PVT__accepted_6) 
                                             & (IData)(vlSelfRef.__PVT___GEN_90));
    vlSelfRef.__PVT___countOverflow_2_T_2 = ((IData)(vlSelfRef.__PVT__accepted_2) 
                                             & (IData)(vlSelfRef.__PVT___GEN_30));
    vlSelfRef.__PVT___countOverflow_1_T_2 = ((IData)(vlSelfRef.__PVT__accepted_1) 
                                             & (IData)(vlSelfRef.__PVT___GEN_15));
    vlSelfRef.__PVT___countOverflow_3_T_2 = ((IData)(vlSelfRef.__PVT__accepted_3) 
                                             & (IData)(vlSelfRef.__PVT___GEN_45));
    vlSelfRef.__PVT___countOverflow_4_T_2 = ((IData)(vlSelfRef.__PVT__accepted_4) 
                                             & (IData)(vlSelfRef.__PVT___GEN_60));
    vlSelfRef.__PVT___countOverflow_0_T_2 = ((IData)(vlSelfRef.__PVT__accepted) 
                                             & (IData)(vlSelfRef.__PVT___GEN_0));
    vlSelfRef.__PVT___countOverflow_5_T_2 = ((IData)(vlSelfRef.__PVT__accepted_5) 
                                             & (IData)(vlSelfRef.__PVT___GEN_75));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_27__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_27__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_0 = ((0xd8U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xd9U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xdaU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xdbU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xdcU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xddU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0xdeU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0xdfU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.buckets_seq_7 
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
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_27__0(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_27__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_requestCycleSum_5_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_5 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_3_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_3 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_6_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_6 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_1_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_1 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_7_T_1 
        = (vlSelfRef.buckets_requestCycleSum_7 + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_2_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_2 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_4_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_4 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_0_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_0 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT__resolving_7 = ((IData)(vlSelfRef.buckets_valid_7) 
                                    & (vlSelfRef.buckets_seq_7 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_6 = ((IData)(vlSelfRef.__PVT__buckets_valid_6) 
                                    & (vlSelfRef.__PVT__buckets_seq_6 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_2 = ((IData)(vlSelfRef.__PVT__buckets_valid_2) 
                                    & (vlSelfRef.__PVT__buckets_seq_2 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_1 = ((IData)(vlSelfRef.__PVT__buckets_valid_1) 
                                    & (vlSelfRef.__PVT__buckets_seq_1 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_3 = ((IData)(vlSelfRef.__PVT__buckets_valid_3) 
                                    & (vlSelfRef.__PVT__buckets_seq_3 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_4 = ((IData)(vlSelfRef.__PVT__buckets_valid_4) 
                                    & (vlSelfRef.__PVT__buckets_seq_4 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_0 = ((IData)(vlSelfRef.__PVT__buckets_valid_0) 
                                    & (vlSelfRef.__PVT__buckets_seq_0 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_5 = ((IData)(vlSelfRef.__PVT__buckets_valid_5) 
                                    & (vlSelfRef.__PVT__buckets_seq_5 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT___GEN_105 = ((~ (IData)(vlSelfRef.__PVT__resolving_7)) 
                                 & (IData)(vlSelfRef.buckets_valid_7));
    vlSelfRef.__PVT___canAccept_T_22 = (1U & ((~ (IData)(vlSelfRef.buckets_valid_7)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_7)));
    vlSelfRef.__PVT___GEN_90 = ((~ (IData)(vlSelfRef.__PVT__resolving_6)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_6));
    vlSelfRef.__PVT___canAccept_T_19 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_6)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_6)));
    vlSelfRef.__PVT___GEN_30 = ((~ (IData)(vlSelfRef.__PVT__resolving_2)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_2));
    vlSelfRef.__PVT___canAccept_T_7 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_2)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_2)));
    vlSelfRef.__PVT___GEN_15 = ((~ (IData)(vlSelfRef.__PVT__resolving_1)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_1));
    vlSelfRef.__PVT___canAccept_T_4 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_1)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_1)));
    vlSelfRef.__PVT___GEN_45 = ((~ (IData)(vlSelfRef.__PVT__resolving_3)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_3));
    vlSelfRef.__PVT___canAccept_T_10 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_3)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_3)));
    vlSelfRef.__PVT___GEN_60 = ((~ (IData)(vlSelfRef.__PVT__resolving_4)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_4));
    vlSelfRef.__PVT___canAccept_T_13 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_4)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_4)));
    vlSelfRef.__PVT___GEN_0 = ((~ (IData)(vlSelfRef.__PVT__resolving_0)) 
                               & (IData)(vlSelfRef.__PVT__buckets_valid_0));
    vlSelfRef.__PVT___canAccept_T_1 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_0)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_0)));
    vlSelfRef.__PVT___GEN_75 = ((~ (IData)(vlSelfRef.__PVT__resolving_5)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_5));
    vlSelfRef.__PVT___canAccept_T_16 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_5)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_5)));
    vlSelfRef.__PVT__available_7 = ((0xdfU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.buckets_seq_7 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_27__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_27__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_6 = ((0xdeU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xdaU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xd9U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xdbU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xdcU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_0 = ((0xd8U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xddU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__accepted_7 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_7));
    vlSelfRef.__PVT__accepted_6 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_6));
    vlSelfRef.__PVT__accepted_2 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_2));
    vlSelfRef.__PVT__accepted_1 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_1));
    vlSelfRef.__PVT__accepted_3 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_3));
    vlSelfRef.__PVT__accepted_4 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_4));
    vlSelfRef.__PVT__accepted = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                 & (IData)(vlSelfRef.__PVT__available_0));
    vlSelfRef.__PVT__accepted_5 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_5));
    vlSelfRef.__PVT___countOverflow_7_T_2 = ((IData)(vlSelfRef.__PVT__accepted_7) 
                                             & (IData)(vlSelfRef.__PVT___GEN_105));
    vlSelfRef.__PVT___countOverflow_6_T_2 = ((IData)(vlSelfRef.__PVT__accepted_6) 
                                             & (IData)(vlSelfRef.__PVT___GEN_90));
    vlSelfRef.__PVT___countOverflow_2_T_2 = ((IData)(vlSelfRef.__PVT__accepted_2) 
                                             & (IData)(vlSelfRef.__PVT___GEN_30));
    vlSelfRef.__PVT___countOverflow_1_T_2 = ((IData)(vlSelfRef.__PVT__accepted_1) 
                                             & (IData)(vlSelfRef.__PVT___GEN_15));
    vlSelfRef.__PVT___countOverflow_3_T_2 = ((IData)(vlSelfRef.__PVT__accepted_3) 
                                             & (IData)(vlSelfRef.__PVT___GEN_45));
    vlSelfRef.__PVT___countOverflow_4_T_2 = ((IData)(vlSelfRef.__PVT__accepted_4) 
                                             & (IData)(vlSelfRef.__PVT___GEN_60));
    vlSelfRef.__PVT___countOverflow_0_T_2 = ((IData)(vlSelfRef.__PVT__accepted) 
                                             & (IData)(vlSelfRef.__PVT___GEN_0));
    vlSelfRef.__PVT___countOverflow_5_T_2 = ((IData)(vlSelfRef.__PVT__accepted_5) 
                                             & (IData)(vlSelfRef.__PVT___GEN_75));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_28__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_28__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_0 = ((0xe0U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xe1U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xe2U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xe3U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xe4U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xe5U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0xe6U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0xe7U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.buckets_seq_7 
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
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_28__0(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_28__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_requestCycleSum_5_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_5 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_3_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_3 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_6_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_6 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_1_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_1 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_7_T_1 
        = (vlSelfRef.buckets_requestCycleSum_7 + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_2_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_2 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_4_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_4 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_0_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_0 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT__resolving_7 = ((IData)(vlSelfRef.buckets_valid_7) 
                                    & (vlSelfRef.buckets_seq_7 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_6 = ((IData)(vlSelfRef.__PVT__buckets_valid_6) 
                                    & (vlSelfRef.__PVT__buckets_seq_6 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_2 = ((IData)(vlSelfRef.__PVT__buckets_valid_2) 
                                    & (vlSelfRef.__PVT__buckets_seq_2 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_1 = ((IData)(vlSelfRef.__PVT__buckets_valid_1) 
                                    & (vlSelfRef.__PVT__buckets_seq_1 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_3 = ((IData)(vlSelfRef.__PVT__buckets_valid_3) 
                                    & (vlSelfRef.__PVT__buckets_seq_3 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_4 = ((IData)(vlSelfRef.__PVT__buckets_valid_4) 
                                    & (vlSelfRef.__PVT__buckets_seq_4 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_0 = ((IData)(vlSelfRef.__PVT__buckets_valid_0) 
                                    & (vlSelfRef.__PVT__buckets_seq_0 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_5 = ((IData)(vlSelfRef.__PVT__buckets_valid_5) 
                                    & (vlSelfRef.__PVT__buckets_seq_5 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT___GEN_105 = ((~ (IData)(vlSelfRef.__PVT__resolving_7)) 
                                 & (IData)(vlSelfRef.buckets_valid_7));
    vlSelfRef.__PVT___canAccept_T_22 = (1U & ((~ (IData)(vlSelfRef.buckets_valid_7)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_7)));
    vlSelfRef.__PVT___GEN_90 = ((~ (IData)(vlSelfRef.__PVT__resolving_6)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_6));
    vlSelfRef.__PVT___canAccept_T_19 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_6)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_6)));
    vlSelfRef.__PVT___GEN_30 = ((~ (IData)(vlSelfRef.__PVT__resolving_2)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_2));
    vlSelfRef.__PVT___canAccept_T_7 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_2)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_2)));
    vlSelfRef.__PVT___GEN_15 = ((~ (IData)(vlSelfRef.__PVT__resolving_1)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_1));
    vlSelfRef.__PVT___canAccept_T_4 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_1)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_1)));
    vlSelfRef.__PVT___GEN_45 = ((~ (IData)(vlSelfRef.__PVT__resolving_3)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_3));
    vlSelfRef.__PVT___canAccept_T_10 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_3)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_3)));
    vlSelfRef.__PVT___GEN_60 = ((~ (IData)(vlSelfRef.__PVT__resolving_4)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_4));
    vlSelfRef.__PVT___canAccept_T_13 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_4)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_4)));
    vlSelfRef.__PVT___GEN_0 = ((~ (IData)(vlSelfRef.__PVT__resolving_0)) 
                               & (IData)(vlSelfRef.__PVT__buckets_valid_0));
    vlSelfRef.__PVT___canAccept_T_1 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_0)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_0)));
    vlSelfRef.__PVT___GEN_75 = ((~ (IData)(vlSelfRef.__PVT__resolving_5)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_5));
    vlSelfRef.__PVT___canAccept_T_16 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_5)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_5)));
    vlSelfRef.__PVT__available_7 = ((0xe7U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.buckets_seq_7 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_28__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_28__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_6 = ((0xe6U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xe2U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xe1U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xe3U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xe4U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_0 = ((0xe0U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xe5U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__accepted_7 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_7));
    vlSelfRef.__PVT__accepted_6 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_6));
    vlSelfRef.__PVT__accepted_2 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_2));
    vlSelfRef.__PVT__accepted_1 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_1));
    vlSelfRef.__PVT__accepted_3 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_3));
    vlSelfRef.__PVT__accepted_4 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_4));
    vlSelfRef.__PVT__accepted = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                 & (IData)(vlSelfRef.__PVT__available_0));
    vlSelfRef.__PVT__accepted_5 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_5));
    vlSelfRef.__PVT___countOverflow_7_T_2 = ((IData)(vlSelfRef.__PVT__accepted_7) 
                                             & (IData)(vlSelfRef.__PVT___GEN_105));
    vlSelfRef.__PVT___countOverflow_6_T_2 = ((IData)(vlSelfRef.__PVT__accepted_6) 
                                             & (IData)(vlSelfRef.__PVT___GEN_90));
    vlSelfRef.__PVT___countOverflow_2_T_2 = ((IData)(vlSelfRef.__PVT__accepted_2) 
                                             & (IData)(vlSelfRef.__PVT___GEN_30));
    vlSelfRef.__PVT___countOverflow_1_T_2 = ((IData)(vlSelfRef.__PVT__accepted_1) 
                                             & (IData)(vlSelfRef.__PVT___GEN_15));
    vlSelfRef.__PVT___countOverflow_3_T_2 = ((IData)(vlSelfRef.__PVT__accepted_3) 
                                             & (IData)(vlSelfRef.__PVT___GEN_45));
    vlSelfRef.__PVT___countOverflow_4_T_2 = ((IData)(vlSelfRef.__PVT__accepted_4) 
                                             & (IData)(vlSelfRef.__PVT___GEN_60));
    vlSelfRef.__PVT___countOverflow_0_T_2 = ((IData)(vlSelfRef.__PVT__accepted) 
                                             & (IData)(vlSelfRef.__PVT___GEN_0));
    vlSelfRef.__PVT___countOverflow_5_T_2 = ((IData)(vlSelfRef.__PVT__accepted_5) 
                                             & (IData)(vlSelfRef.__PVT___GEN_75));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_29__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_29__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_0 = ((0xe8U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xe9U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xeaU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xebU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xecU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xedU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0xeeU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0xefU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.buckets_seq_7 
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
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_29__0(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_29__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_requestCycleSum_5_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_5 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_3_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_3 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_6_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_6 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_1_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_1 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_7_T_1 
        = (vlSelfRef.buckets_requestCycleSum_7 + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_2_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_2 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_4_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_4 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_0_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_0 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT__resolving_7 = ((IData)(vlSelfRef.buckets_valid_7) 
                                    & (vlSelfRef.buckets_seq_7 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_6 = ((IData)(vlSelfRef.__PVT__buckets_valid_6) 
                                    & (vlSelfRef.__PVT__buckets_seq_6 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_2 = ((IData)(vlSelfRef.__PVT__buckets_valid_2) 
                                    & (vlSelfRef.__PVT__buckets_seq_2 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_1 = ((IData)(vlSelfRef.__PVT__buckets_valid_1) 
                                    & (vlSelfRef.__PVT__buckets_seq_1 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_3 = ((IData)(vlSelfRef.__PVT__buckets_valid_3) 
                                    & (vlSelfRef.__PVT__buckets_seq_3 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_4 = ((IData)(vlSelfRef.__PVT__buckets_valid_4) 
                                    & (vlSelfRef.__PVT__buckets_seq_4 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_0 = ((IData)(vlSelfRef.__PVT__buckets_valid_0) 
                                    & (vlSelfRef.__PVT__buckets_seq_0 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_5 = ((IData)(vlSelfRef.__PVT__buckets_valid_5) 
                                    & (vlSelfRef.__PVT__buckets_seq_5 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT___GEN_105 = ((~ (IData)(vlSelfRef.__PVT__resolving_7)) 
                                 & (IData)(vlSelfRef.buckets_valid_7));
    vlSelfRef.__PVT___canAccept_T_22 = (1U & ((~ (IData)(vlSelfRef.buckets_valid_7)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_7)));
    vlSelfRef.__PVT___GEN_90 = ((~ (IData)(vlSelfRef.__PVT__resolving_6)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_6));
    vlSelfRef.__PVT___canAccept_T_19 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_6)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_6)));
    vlSelfRef.__PVT___GEN_30 = ((~ (IData)(vlSelfRef.__PVT__resolving_2)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_2));
    vlSelfRef.__PVT___canAccept_T_7 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_2)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_2)));
    vlSelfRef.__PVT___GEN_15 = ((~ (IData)(vlSelfRef.__PVT__resolving_1)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_1));
    vlSelfRef.__PVT___canAccept_T_4 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_1)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_1)));
    vlSelfRef.__PVT___GEN_45 = ((~ (IData)(vlSelfRef.__PVT__resolving_3)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_3));
    vlSelfRef.__PVT___canAccept_T_10 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_3)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_3)));
    vlSelfRef.__PVT___GEN_60 = ((~ (IData)(vlSelfRef.__PVT__resolving_4)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_4));
    vlSelfRef.__PVT___canAccept_T_13 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_4)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_4)));
    vlSelfRef.__PVT___GEN_0 = ((~ (IData)(vlSelfRef.__PVT__resolving_0)) 
                               & (IData)(vlSelfRef.__PVT__buckets_valid_0));
    vlSelfRef.__PVT___canAccept_T_1 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_0)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_0)));
    vlSelfRef.__PVT___GEN_75 = ((~ (IData)(vlSelfRef.__PVT__resolving_5)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_5));
    vlSelfRef.__PVT___canAccept_T_16 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_5)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_5)));
    vlSelfRef.__PVT__available_7 = ((0xefU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.buckets_seq_7 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_29__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_29__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_6 = ((0xeeU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xeaU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xe9U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xebU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xecU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_0 = ((0xe8U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xedU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__accepted_7 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_7));
    vlSelfRef.__PVT__accepted_6 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_6));
    vlSelfRef.__PVT__accepted_2 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_2));
    vlSelfRef.__PVT__accepted_1 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_1));
    vlSelfRef.__PVT__accepted_3 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_3));
    vlSelfRef.__PVT__accepted_4 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_4));
    vlSelfRef.__PVT__accepted = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                 & (IData)(vlSelfRef.__PVT__available_0));
    vlSelfRef.__PVT__accepted_5 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_5));
    vlSelfRef.__PVT___countOverflow_7_T_2 = ((IData)(vlSelfRef.__PVT__accepted_7) 
                                             & (IData)(vlSelfRef.__PVT___GEN_105));
    vlSelfRef.__PVT___countOverflow_6_T_2 = ((IData)(vlSelfRef.__PVT__accepted_6) 
                                             & (IData)(vlSelfRef.__PVT___GEN_90));
    vlSelfRef.__PVT___countOverflow_2_T_2 = ((IData)(vlSelfRef.__PVT__accepted_2) 
                                             & (IData)(vlSelfRef.__PVT___GEN_30));
    vlSelfRef.__PVT___countOverflow_1_T_2 = ((IData)(vlSelfRef.__PVT__accepted_1) 
                                             & (IData)(vlSelfRef.__PVT___GEN_15));
    vlSelfRef.__PVT___countOverflow_3_T_2 = ((IData)(vlSelfRef.__PVT__accepted_3) 
                                             & (IData)(vlSelfRef.__PVT___GEN_45));
    vlSelfRef.__PVT___countOverflow_4_T_2 = ((IData)(vlSelfRef.__PVT__accepted_4) 
                                             & (IData)(vlSelfRef.__PVT___GEN_60));
    vlSelfRef.__PVT___countOverflow_0_T_2 = ((IData)(vlSelfRef.__PVT__accepted) 
                                             & (IData)(vlSelfRef.__PVT___GEN_0));
    vlSelfRef.__PVT___countOverflow_5_T_2 = ((IData)(vlSelfRef.__PVT__accepted_5) 
                                             & (IData)(vlSelfRef.__PVT___GEN_75));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_30__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_30__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_0 = ((0xf0U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xf1U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xf2U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xf3U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xf4U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xf5U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0xf6U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0xf7U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.buckets_seq_7 
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
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_30__0(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_30__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_requestCycleSum_5_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_5 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_3_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_3 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_6_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_6 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_1_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_1 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_7_T_1 
        = (vlSelfRef.buckets_requestCycleSum_7 + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_2_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_2 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_4_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_4 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_0_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_0 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT__resolving_7 = ((IData)(vlSelfRef.buckets_valid_7) 
                                    & (vlSelfRef.buckets_seq_7 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_6 = ((IData)(vlSelfRef.__PVT__buckets_valid_6) 
                                    & (vlSelfRef.__PVT__buckets_seq_6 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_2 = ((IData)(vlSelfRef.__PVT__buckets_valid_2) 
                                    & (vlSelfRef.__PVT__buckets_seq_2 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_1 = ((IData)(vlSelfRef.__PVT__buckets_valid_1) 
                                    & (vlSelfRef.__PVT__buckets_seq_1 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_3 = ((IData)(vlSelfRef.__PVT__buckets_valid_3) 
                                    & (vlSelfRef.__PVT__buckets_seq_3 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_4 = ((IData)(vlSelfRef.__PVT__buckets_valid_4) 
                                    & (vlSelfRef.__PVT__buckets_seq_4 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_0 = ((IData)(vlSelfRef.__PVT__buckets_valid_0) 
                                    & (vlSelfRef.__PVT__buckets_seq_0 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_5 = ((IData)(vlSelfRef.__PVT__buckets_valid_5) 
                                    & (vlSelfRef.__PVT__buckets_seq_5 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT___GEN_105 = ((~ (IData)(vlSelfRef.__PVT__resolving_7)) 
                                 & (IData)(vlSelfRef.buckets_valid_7));
    vlSelfRef.__PVT___canAccept_T_22 = (1U & ((~ (IData)(vlSelfRef.buckets_valid_7)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_7)));
    vlSelfRef.__PVT___GEN_90 = ((~ (IData)(vlSelfRef.__PVT__resolving_6)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_6));
    vlSelfRef.__PVT___canAccept_T_19 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_6)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_6)));
    vlSelfRef.__PVT___GEN_30 = ((~ (IData)(vlSelfRef.__PVT__resolving_2)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_2));
    vlSelfRef.__PVT___canAccept_T_7 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_2)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_2)));
    vlSelfRef.__PVT___GEN_15 = ((~ (IData)(vlSelfRef.__PVT__resolving_1)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_1));
    vlSelfRef.__PVT___canAccept_T_4 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_1)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_1)));
    vlSelfRef.__PVT___GEN_45 = ((~ (IData)(vlSelfRef.__PVT__resolving_3)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_3));
    vlSelfRef.__PVT___canAccept_T_10 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_3)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_3)));
    vlSelfRef.__PVT___GEN_60 = ((~ (IData)(vlSelfRef.__PVT__resolving_4)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_4));
    vlSelfRef.__PVT___canAccept_T_13 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_4)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_4)));
    vlSelfRef.__PVT___GEN_0 = ((~ (IData)(vlSelfRef.__PVT__resolving_0)) 
                               & (IData)(vlSelfRef.__PVT__buckets_valid_0));
    vlSelfRef.__PVT___canAccept_T_1 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_0)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_0)));
    vlSelfRef.__PVT___GEN_75 = ((~ (IData)(vlSelfRef.__PVT__resolving_5)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_5));
    vlSelfRef.__PVT___canAccept_T_16 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_5)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_5)));
    vlSelfRef.__PVT__available_7 = ((0xf7U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.buckets_seq_7 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_30__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_30__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_6 = ((0xf6U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xf2U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xf1U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xf3U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xf4U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_0 = ((0xf0U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xf5U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__accepted_7 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_7));
    vlSelfRef.__PVT__accepted_6 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_6));
    vlSelfRef.__PVT__accepted_2 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_2));
    vlSelfRef.__PVT__accepted_1 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_1));
    vlSelfRef.__PVT__accepted_3 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_3));
    vlSelfRef.__PVT__accepted_4 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_4));
    vlSelfRef.__PVT__accepted = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                 & (IData)(vlSelfRef.__PVT__available_0));
    vlSelfRef.__PVT__accepted_5 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_5));
    vlSelfRef.__PVT___countOverflow_7_T_2 = ((IData)(vlSelfRef.__PVT__accepted_7) 
                                             & (IData)(vlSelfRef.__PVT___GEN_105));
    vlSelfRef.__PVT___countOverflow_6_T_2 = ((IData)(vlSelfRef.__PVT__accepted_6) 
                                             & (IData)(vlSelfRef.__PVT___GEN_90));
    vlSelfRef.__PVT___countOverflow_2_T_2 = ((IData)(vlSelfRef.__PVT__accepted_2) 
                                             & (IData)(vlSelfRef.__PVT___GEN_30));
    vlSelfRef.__PVT___countOverflow_1_T_2 = ((IData)(vlSelfRef.__PVT__accepted_1) 
                                             & (IData)(vlSelfRef.__PVT___GEN_15));
    vlSelfRef.__PVT___countOverflow_3_T_2 = ((IData)(vlSelfRef.__PVT__accepted_3) 
                                             & (IData)(vlSelfRef.__PVT___GEN_45));
    vlSelfRef.__PVT___countOverflow_4_T_2 = ((IData)(vlSelfRef.__PVT__accepted_4) 
                                             & (IData)(vlSelfRef.__PVT___GEN_60));
    vlSelfRef.__PVT___countOverflow_0_T_2 = ((IData)(vlSelfRef.__PVT__accepted) 
                                             & (IData)(vlSelfRef.__PVT___GEN_0));
    vlSelfRef.__PVT___countOverflow_5_T_2 = ((IData)(vlSelfRef.__PVT__accepted_5) 
                                             & (IData)(vlSelfRef.__PVT___GEN_75));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_31__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_31__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_0 = ((0xf8U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xf9U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xfaU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xfbU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xfcU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xfdU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0xfeU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0xffU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.buckets_seq_7 
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
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_31__0(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_31__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_requestCycleSum_5_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_5 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_3_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_3 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_6_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_6 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_1_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_1 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_7_T_1 
        = (vlSelfRef.buckets_requestCycleSum_7 + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_2_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_2 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_4_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_4 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_0_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_0 
           + vlSymsp->TOP.tb__DOT__io_currentCycle);
    vlSelfRef.__PVT__resolving_7 = ((IData)(vlSelfRef.buckets_valid_7) 
                                    & (vlSelfRef.buckets_seq_7 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_6 = ((IData)(vlSelfRef.__PVT__buckets_valid_6) 
                                    & (vlSelfRef.__PVT__buckets_seq_6 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_2 = ((IData)(vlSelfRef.__PVT__buckets_valid_2) 
                                    & (vlSelfRef.__PVT__buckets_seq_2 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_1 = ((IData)(vlSelfRef.__PVT__buckets_valid_1) 
                                    & (vlSelfRef.__PVT__buckets_seq_1 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_3 = ((IData)(vlSelfRef.__PVT__buckets_valid_3) 
                                    & (vlSelfRef.__PVT__buckets_seq_3 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_4 = ((IData)(vlSelfRef.__PVT__buckets_valid_4) 
                                    & (vlSelfRef.__PVT__buckets_seq_4 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_0 = ((IData)(vlSelfRef.__PVT__buckets_valid_0) 
                                    & (vlSelfRef.__PVT__buckets_seq_0 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT__resolving_5 = ((IData)(vlSelfRef.__PVT__buckets_valid_5) 
                                    & (vlSelfRef.__PVT__buckets_seq_5 
                                       <= vlSymsp->TOP.tb__DOT__io_safeWatermark));
    vlSelfRef.__PVT___GEN_105 = ((~ (IData)(vlSelfRef.__PVT__resolving_7)) 
                                 & (IData)(vlSelfRef.buckets_valid_7));
    vlSelfRef.__PVT___canAccept_T_22 = (1U & ((~ (IData)(vlSelfRef.buckets_valid_7)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_7)));
    vlSelfRef.__PVT___GEN_90 = ((~ (IData)(vlSelfRef.__PVT__resolving_6)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_6));
    vlSelfRef.__PVT___canAccept_T_19 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_6)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_6)));
    vlSelfRef.__PVT___GEN_30 = ((~ (IData)(vlSelfRef.__PVT__resolving_2)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_2));
    vlSelfRef.__PVT___canAccept_T_7 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_2)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_2)));
    vlSelfRef.__PVT___GEN_15 = ((~ (IData)(vlSelfRef.__PVT__resolving_1)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_1));
    vlSelfRef.__PVT___canAccept_T_4 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_1)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_1)));
    vlSelfRef.__PVT___GEN_45 = ((~ (IData)(vlSelfRef.__PVT__resolving_3)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_3));
    vlSelfRef.__PVT___canAccept_T_10 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_3)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_3)));
    vlSelfRef.__PVT___GEN_60 = ((~ (IData)(vlSelfRef.__PVT__resolving_4)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_4));
    vlSelfRef.__PVT___canAccept_T_13 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_4)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_4)));
    vlSelfRef.__PVT___GEN_0 = ((~ (IData)(vlSelfRef.__PVT__resolving_0)) 
                               & (IData)(vlSelfRef.__PVT__buckets_valid_0));
    vlSelfRef.__PVT___canAccept_T_1 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_0)) 
                                             | (IData)(vlSelfRef.__PVT__resolving_0)));
    vlSelfRef.__PVT___GEN_75 = ((~ (IData)(vlSelfRef.__PVT__resolving_5)) 
                                & (IData)(vlSelfRef.__PVT__buckets_valid_5));
    vlSelfRef.__PVT___canAccept_T_16 = (1U & ((~ (IData)(vlSelfRef.__PVT__buckets_valid_5)) 
                                              | (IData)(vlSelfRef.__PVT__resolving_5)));
    vlSelfRef.__PVT__available_7 = ((0xffU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.buckets_seq_7 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_31__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_comb__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_31__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_6 = ((0xfeU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xfaU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xf9U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xfbU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xfcU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_0 = ((0xf8U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xfdU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__accepted_7 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_7));
    vlSelfRef.__PVT__accepted_6 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_6));
    vlSelfRef.__PVT__accepted_2 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_2));
    vlSelfRef.__PVT__accepted_1 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_1));
    vlSelfRef.__PVT__accepted_3 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_3));
    vlSelfRef.__PVT__accepted_4 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_4));
    vlSelfRef.__PVT__accepted = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                 & (IData)(vlSelfRef.__PVT__available_0));
    vlSelfRef.__PVT__accepted_5 = ((IData)(vlSelfRef.__PVT__eventNeedsBucket) 
                                   & (IData)(vlSelfRef.__PVT__available_5));
    vlSelfRef.__PVT___countOverflow_7_T_2 = ((IData)(vlSelfRef.__PVT__accepted_7) 
                                             & (IData)(vlSelfRef.__PVT___GEN_105));
    vlSelfRef.__PVT___countOverflow_6_T_2 = ((IData)(vlSelfRef.__PVT__accepted_6) 
                                             & (IData)(vlSelfRef.__PVT___GEN_90));
    vlSelfRef.__PVT___countOverflow_2_T_2 = ((IData)(vlSelfRef.__PVT__accepted_2) 
                                             & (IData)(vlSelfRef.__PVT___GEN_30));
    vlSelfRef.__PVT___countOverflow_1_T_2 = ((IData)(vlSelfRef.__PVT__accepted_1) 
                                             & (IData)(vlSelfRef.__PVT___GEN_15));
    vlSelfRef.__PVT___countOverflow_3_T_2 = ((IData)(vlSelfRef.__PVT__accepted_3) 
                                             & (IData)(vlSelfRef.__PVT___GEN_45));
    vlSelfRef.__PVT___countOverflow_4_T_2 = ((IData)(vlSelfRef.__PVT__accepted_4) 
                                             & (IData)(vlSelfRef.__PVT___GEN_60));
    vlSelfRef.__PVT___countOverflow_0_T_2 = ((IData)(vlSelfRef.__PVT__accepted) 
                                             & (IData)(vlSelfRef.__PVT___GEN_0));
    vlSelfRef.__PVT___countOverflow_5_T_2 = ((IData)(vlSelfRef.__PVT__accepted_5) 
                                             & (IData)(vlSelfRef.__PVT___GEN_75));
}
