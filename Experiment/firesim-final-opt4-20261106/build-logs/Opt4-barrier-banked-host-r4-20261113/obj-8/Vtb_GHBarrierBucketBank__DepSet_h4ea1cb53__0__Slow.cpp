// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_GHBarrierBucketBank.h"
#include "Vtb__Syms.h"

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__0(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_count_0_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_0);
    vlSelfRef.__PVT___buckets_count_1_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_1);
    vlSelfRef.__PVT___buckets_count_2_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_2);
    vlSelfRef.__PVT___buckets_count_3_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_3);
    vlSelfRef.__PVT___buckets_count_4_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_4);
    vlSelfRef.__PVT___buckets_count_5_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_5);
    vlSelfRef.__PVT___buckets_count_6_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_6);
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
    vlSelfRef.io_observe_7[0U] = (IData)(vlSelfRef.buckets_requestCycleSum_7);
    vlSelfRef.io_observe_7[1U] = (IData)((vlSelfRef.buckets_requestCycleSum_7 
                                          >> 0x20U));
    vlSelfRef.io_observe_7[2U] = (IData)(vlSelfRef.buckets_count_7);
    vlSelfRef.io_observe_7[3U] = (IData)((vlSelfRef.buckets_count_7 
                                          >> 0x20U));
    vlSelfRef.io_observe_7[4U] = vlSelfRef.buckets_seq_7;
    vlSelfRef.io_observe_7[5U] = vlSelfRef.buckets_valid_7;
    vlSelfRef.__PVT__eventNeedsBucket = ((IData)(vlSymsp->TOP.tb__DOT__io_event_valid) 
                                         & (vlSymsp->TOP.tb__DOT__io_event_bits 
                                            > vlSymsp->TOP.tb__DOT__io_safeWatermark));
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_6 = ((6U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((7U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__0(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_count_0_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_0);
    vlSelfRef.__PVT___buckets_count_1_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_1);
    vlSelfRef.__PVT___buckets_count_2_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_2);
    vlSelfRef.__PVT___buckets_count_3_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_3);
    vlSelfRef.__PVT___buckets_count_4_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_4);
    vlSelfRef.__PVT___buckets_count_5_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_5);
    vlSelfRef.__PVT___buckets_count_6_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_6);
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
    vlSelfRef.__PVT__eventNeedsBucket = ((IData)(vlSymsp->TOP.tb__DOT__io_event_valid) 
                                         & (vlSymsp->TOP.tb__DOT__io_event_bits 
                                            > vlSymsp->TOP.tb__DOT__io_safeWatermark));
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((8U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((9U == (0xffU & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xaU == (0xffU 
                                              & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xbU == (0xffU 
                                              & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xcU == (0xffU 
                                              & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xdU == (0xffU 
                                              & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0xeU == (0xffU 
                                              & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0xfU == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_2__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_2__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_3__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_3__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0x18U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x19U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x1aU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x1bU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x1cU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x1dU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0x1eU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x1fU == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_4__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_4__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0x20U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x21U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x22U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x23U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x24U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x25U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0x26U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x27U == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_5__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_5__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0x28U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x29U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x2aU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x2bU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x2cU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x2dU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0x2eU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x2fU == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_6__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_6__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0x30U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x31U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x32U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x33U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x34U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x35U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0x36U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x37U == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_7__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_7__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0x38U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x39U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x3aU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x3bU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x3cU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x3dU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0x3eU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x3fU == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_8__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_8__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0x40U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x41U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x42U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x43U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x44U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x45U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0x46U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x47U == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_9__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_9__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0x48U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x49U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x4aU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x4bU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x4cU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x4dU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0x4eU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x4fU == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_10__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_10__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0x50U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x51U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x52U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x53U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x54U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x55U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0x56U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x57U == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_11__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_11__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0x58U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x59U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x5aU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x5bU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x5cU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x5dU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0x5eU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x5fU == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_12__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_12__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0x60U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x61U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x62U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x63U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x64U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x65U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0x66U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x67U == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_13__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_13__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0x68U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x69U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x6aU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x6bU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x6cU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x6dU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0x6eU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x6fU == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_14__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_14__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0x70U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x71U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x72U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x73U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x74U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x75U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0x76U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x77U == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_15__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_15__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0x78U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x79U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x7aU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x7bU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x7cU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x7dU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0x7eU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x7fU == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_16__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_16__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0x80U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x81U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x82U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x83U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x84U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x85U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0x86U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x87U == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_17__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_17__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0x88U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x89U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x8aU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x8bU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x8cU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x8dU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0x8eU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x8fU == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_18__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_18__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0x90U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x91U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x92U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x93U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x94U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x95U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0x96U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x97U == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_19__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_19__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0x98U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0x99U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0x9aU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0x9bU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0x9cU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0x9dU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0x9eU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0x9fU == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_20__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_20__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0xa0U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xa1U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xa2U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xa3U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xa4U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xa5U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0xa6U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0xa7U == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_21__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_21__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0xa8U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xa9U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xaaU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xabU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xacU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xadU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0xaeU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0xafU == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_22__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_22__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0xb0U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xb1U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xb2U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xb3U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xb4U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xb5U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0xb6U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0xb7U == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_23__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_23__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0xb8U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xb9U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xbaU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xbbU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xbcU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xbdU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0xbeU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0xbfU == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_24__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_24__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0xc0U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xc1U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xc2U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xc3U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xc4U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xc5U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0xc6U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0xc7U == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_25__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_25__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0xc8U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xc9U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xcaU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_3 = ((0xcbU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_10) 
                                       | (vlSelfRef.__PVT__buckets_seq_3 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_4 = ((0xccU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_13) 
                                       | (vlSelfRef.__PVT__buckets_seq_4 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_5 = ((0xcdU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0xceU == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0xcfU == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_26__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_26__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_0 = ((0xd0U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_1) 
                                       | (vlSelfRef.__PVT__buckets_seq_0 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_1 = ((0xd1U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_4) 
                                       | (vlSelfRef.__PVT__buckets_seq_1 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_2 = ((0xd2U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_7) 
                                       | (vlSelfRef.__PVT__buckets_seq_2 
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
    vlSelfRef.__PVT__available_5 = ((0xd5U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_16) 
                                       | (vlSelfRef.__PVT__buckets_seq_5 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_6 = ((0xd6U == (0xffU 
                                               & vlSymsp->TOP.tb__DOT__io_event_bits)) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_19) 
                                       | (vlSelfRef.__PVT__buckets_seq_6 
                                          == vlSymsp->TOP.tb__DOT__io_event_bits)));
    vlSelfRef.__PVT__available_7 = ((0xd7U == (0xffU 
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_27__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_27__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_28__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_28__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_29__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_29__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_30__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_30__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_31__1(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_31__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}
