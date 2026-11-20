// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_GHBarrierBucketBank.h"

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___stl_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

VL_ATTR_COLD void Vtb_GHBarrierBucketBank___ctor_var_reset(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clock = 0;
    vlSelf->reset = 0;
    VL_ZERO_RESET_W(161, vlSelf->io_observe_0);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_1);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_2);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_3);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_4);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_5);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_6);
    VL_ZERO_RESET_W(161, vlSelf->io_observe_7);
    vlSelf->io_base = 0;
    vlSelf->io_resetStats = 0;
    vlSelf->io_event_valid = 0;
    vlSelf->io_event_bits = 0;
    vlSelf->io_safeWatermark = 0;
    vlSelf->io_currentCycle = 0;
    VL_ZERO_RESET_W(67, vlSelf->io_resolvedCount);
    VL_ZERO_RESET_W(67, vlSelf->io_resolvedRequest);
    vlSelf->io_eventAvailable = 0;
    vlSelf->io_countOverflow = 0;
    vlSelf->io_cycleOverflow = 0;
    vlSelf->__PVT__buckets_valid_0 = 0;
    vlSelf->__PVT__buckets_valid_1 = 0;
    vlSelf->__PVT__buckets_valid_2 = 0;
    vlSelf->__PVT__buckets_valid_3 = 0;
    vlSelf->__PVT__buckets_valid_4 = 0;
    vlSelf->__PVT__buckets_valid_5 = 0;
    vlSelf->__PVT__buckets_valid_6 = 0;
    vlSelf->buckets_valid_7 = 0;
    vlSelf->__PVT__buckets_seq_0 = 0;
    vlSelf->__PVT__buckets_seq_1 = 0;
    vlSelf->__PVT__buckets_seq_2 = 0;
    vlSelf->__PVT__buckets_seq_3 = 0;
    vlSelf->__PVT__buckets_seq_4 = 0;
    vlSelf->__PVT__buckets_seq_5 = 0;
    vlSelf->__PVT__buckets_seq_6 = 0;
    vlSelf->buckets_seq_7 = 0;
    vlSelf->__PVT__buckets_count_0 = 0;
    vlSelf->__PVT__buckets_count_1 = 0;
    vlSelf->__PVT__buckets_count_2 = 0;
    vlSelf->__PVT__buckets_count_3 = 0;
    vlSelf->__PVT__buckets_count_4 = 0;
    vlSelf->__PVT__buckets_count_5 = 0;
    vlSelf->__PVT__buckets_count_6 = 0;
    vlSelf->buckets_count_7 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_0 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_1 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_2 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_3 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_4 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_5 = 0;
    vlSelf->__PVT__buckets_requestCycleSum_6 = 0;
    vlSelf->buckets_requestCycleSum_7 = 0;
    vlSelf->__PVT__eventNeedsBucket = 0;
    vlSelf->__PVT__resolving_0 = 0;
    vlSelf->__PVT___canAccept_T_1 = 0;
    vlSelf->__PVT__accepted = 0;
    vlSelf->__PVT__available_0 = 0;
    vlSelf->__PVT___countOverflow_0_T_2 = 0;
    vlSelf->__PVT___GEN_0 = 0;
    vlSelf->__PVT___buckets_count_0_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_0_T_1 = 0;
    vlSelf->__PVT__resolving_1 = 0;
    vlSelf->__PVT___canAccept_T_4 = 0;
    vlSelf->__PVT__accepted_1 = 0;
    vlSelf->__PVT__available_1 = 0;
    vlSelf->__PVT___countOverflow_1_T_2 = 0;
    vlSelf->__PVT___GEN_15 = 0;
    vlSelf->__PVT___buckets_count_1_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_1_T_1 = 0;
    vlSelf->__PVT__resolving_2 = 0;
    vlSelf->__PVT___canAccept_T_7 = 0;
    vlSelf->__PVT__accepted_2 = 0;
    vlSelf->__PVT__available_2 = 0;
    vlSelf->__PVT___countOverflow_2_T_2 = 0;
    vlSelf->__PVT___GEN_30 = 0;
    vlSelf->__PVT___buckets_count_2_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_2_T_1 = 0;
    vlSelf->__PVT__resolving_3 = 0;
    vlSelf->__PVT___canAccept_T_10 = 0;
    vlSelf->__PVT__accepted_3 = 0;
    vlSelf->__PVT__available_3 = 0;
    vlSelf->__PVT___countOverflow_3_T_2 = 0;
    vlSelf->__PVT___GEN_45 = 0;
    vlSelf->__PVT___buckets_count_3_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_3_T_1 = 0;
    vlSelf->__PVT__resolving_4 = 0;
    vlSelf->__PVT___canAccept_T_13 = 0;
    vlSelf->__PVT__accepted_4 = 0;
    vlSelf->__PVT__available_4 = 0;
    vlSelf->__PVT___countOverflow_4_T_2 = 0;
    vlSelf->__PVT___GEN_60 = 0;
    vlSelf->__PVT___buckets_count_4_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_4_T_1 = 0;
    vlSelf->__PVT__resolving_5 = 0;
    vlSelf->__PVT___canAccept_T_16 = 0;
    vlSelf->__PVT__accepted_5 = 0;
    vlSelf->__PVT__available_5 = 0;
    vlSelf->__PVT___countOverflow_5_T_2 = 0;
    vlSelf->__PVT___GEN_75 = 0;
    vlSelf->__PVT___buckets_count_5_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_5_T_1 = 0;
    vlSelf->__PVT__resolving_6 = 0;
    vlSelf->__PVT___canAccept_T_19 = 0;
    vlSelf->__PVT__accepted_6 = 0;
    vlSelf->__PVT__available_6 = 0;
    vlSelf->__PVT___countOverflow_6_T_2 = 0;
    vlSelf->__PVT___GEN_90 = 0;
    vlSelf->__PVT___buckets_count_6_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_6_T_1 = 0;
    vlSelf->__PVT__resolving_7 = 0;
    vlSelf->__PVT___canAccept_T_22 = 0;
    vlSelf->__PVT__accepted_7 = 0;
    vlSelf->__PVT__available_7 = 0;
    vlSelf->__PVT___countOverflow_7_T_2 = 0;
    vlSelf->__PVT___GEN_105 = 0;
    vlSelf->__PVT___buckets_count_7_T_1 = 0;
    vlSelf->__PVT___buckets_requestCycleSum_7_T_1 = 0;
}
