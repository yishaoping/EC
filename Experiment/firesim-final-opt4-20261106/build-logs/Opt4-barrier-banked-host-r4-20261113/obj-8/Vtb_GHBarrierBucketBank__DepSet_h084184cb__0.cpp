// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_GHBarrierBucketBank.h"

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__2(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___act_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__2\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___countOverflow_7_T_2 = ((IData)(vlSelfRef.__PVT__accepted_7) 
                                             & (IData)(vlSelfRef.__PVT___GEN_105));
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__4(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_0__4\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_count_3_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_3);
    vlSelfRef.__PVT___buckets_count_6_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_6);
    vlSelfRef.__PVT___buckets_count_0_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_0);
    vlSelfRef.__PVT___buckets_count_1_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_1);
    vlSelfRef.__PVT___buckets_count_2_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_2);
    vlSelfRef.__PVT___buckets_count_4_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_4);
    vlSelfRef.__PVT___buckets_count_5_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_5);
}

VL_INLINE_OPT void Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__4(Vtb_GHBarrierBucketBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GHBarrierBucketBank___nba_sequent__TOP__tb__DOT__dutCandidate__DOT__bucketBanks_1__4\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_count_3_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_3);
    vlSelfRef.__PVT___buckets_count_6_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_6);
    vlSelfRef.__PVT___buckets_count_7_T_1 = (1ULL + vlSelfRef.buckets_count_7);
    vlSelfRef.__PVT___buckets_count_0_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_0);
    vlSelfRef.__PVT___buckets_count_1_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_1);
    vlSelfRef.__PVT___buckets_count_2_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_2);
    vlSelfRef.__PVT___buckets_count_4_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_4);
    vlSelfRef.__PVT___buckets_count_5_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_5);
}
