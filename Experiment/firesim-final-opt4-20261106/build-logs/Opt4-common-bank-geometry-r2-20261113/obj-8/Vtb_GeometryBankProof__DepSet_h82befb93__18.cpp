// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_GeometryBankProof.h"
#include "Vtb__Syms.h"

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__4(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__4\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__io_queryMatch_80_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_80 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_81_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_81 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_82_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_82 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_83_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_83 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_84_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_84 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_85_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_85 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_86_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_86 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__io_queryMatch_87_offset = (0xffU 
                                                & (vlSymsp->TOP.tb__DOT__io_querySeq_87 
                                                   - 
                                                   ((IData)(0x18U) 
                                                    + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__retireSelect_0 = ((0xffU & ((IData)(0x18U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_1 = ((0xffU & ((IData)(0x19U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_2 = ((0xffU & ((IData)(0x1aU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_3 = ((0xffU & ((IData)(0x1bU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_4 = ((0xffU & ((IData)(0x1cU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_5 = ((0xffU & ((IData)(0x1dU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_6 = ((0xffU & ((IData)(0x1eU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_7 = ((0xffU & ((IData)(0x1fU) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__eventNeedsBucket = ((IData)(vlSymsp->TOP.tb__DOT__io_barrierEvent_valid) 
                                         & (vlSymsp->TOP.tb__DOT__io_barrierEvent_bits 
                                            > vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__bucketLoadFirstDelta_ordered = 
        ((IData)(vlSymsp->TOP.tb__DOT__io_loadSources_0_key) 
         <= (IData)(vlSymsp->TOP.tb__DOT__io_loadSources_1_key));
    vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_1 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_loadSources_2_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_loadSources_3_key));
    vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_5 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_loadSources_4_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_loadSources_5_key));
    vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_6 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_loadSources_6_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_loadSources_7_key));
    vlSelfRef.__PVT__bucketStoreFirstDelta_ordered 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_storeSources_0_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_storeSources_1_key));
    vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_1 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_storeSources_2_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_storeSources_3_key));
    vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_5 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_storeSources_4_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_storeSources_5_key));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__36(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__36\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_97) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2647 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2632;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2648 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2633;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2639 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2619;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2644 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2629;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2647 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2622;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2648 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2623;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2639 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2629;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2644 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2619;
    }
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_283 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_719 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1155 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1591 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2027 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2463 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2899 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3335 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_4 
        = ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_46) 
           <= (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_41));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_301 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_737 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1173 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1609 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2045 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2481 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2917 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3353 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_9 
        = ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_183) 
           <= (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_178));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_283 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
         == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_719 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
         == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1155 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1591 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2027 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2463 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2899 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3335 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__37(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__37\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_4 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_46) 
           <= (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_41));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_301 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
         == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_737 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
         == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1173 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1609 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2045 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2481 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2917 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3353 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_9 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_183) 
           <= (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_178));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2749 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7213 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11677 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16141 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20605 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25069 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29533 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_33997 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_4 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_46) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_41));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2767 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7231 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11695 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16159 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20623 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25087 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29551 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34015 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_9 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_183) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_178));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2785 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7249 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__38(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__38\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11713 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16177 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20641 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25105 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29569 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34033 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_14 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_320) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_315));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2803 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7267 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11731 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16195 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20659 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25123 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29587 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34051 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_19 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_457) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_452));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2821 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7285 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11749 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16213 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20677 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25141 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29605 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34069 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_24 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_594) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_589));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2839 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7303 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11767 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16231 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20695 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__39(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__39\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25159 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29623 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34087 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_29 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_731) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_726));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2857 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7321 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11785 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16249 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20713 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25177 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29641 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34105 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_34 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_868) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_863));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2875 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7339 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11803 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16267 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20731 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25195 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29659 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34123 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_39 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1005) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1000));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2893 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7357 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11821 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16285 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20749 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25213 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29677 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34141 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__40(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__40\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_44 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1142) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1137));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2911 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7375 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11839 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16303 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20767 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25231 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29695 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34159 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_49 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1279) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1274));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2929 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7393 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11857 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16321 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20785 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25249 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29713 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34177 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_54 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1416) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1411));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2947 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7411 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11875 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16339 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20803 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25267 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29731 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34195 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_59 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1553) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1548));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2965 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7429 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__41(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__41\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11893 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16357 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20821 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25285 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29749 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34213 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_64 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1690) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1685));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2983 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7447 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11911 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16375 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20839 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25303 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29767 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34231 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_69 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1827) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1822));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3001 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7465 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11929 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16393 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20857 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25321 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29785 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34249 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_74 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1964) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1959));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3019 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7483 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11947 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16411 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20875 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__42(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__42\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25339 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29803 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34267 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_79 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2101) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2096));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3037 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7501 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11965 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16429 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20893 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25357 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29821 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34285 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_84 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2238) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2233));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3055 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7519 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11983 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16447 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20911 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25375 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29839 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34303 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_89 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2375) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2370));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3073 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7537 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12001 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16465 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20929 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25393 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29857 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34321 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__43(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__43\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_94 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2512) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2507));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3091 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7555 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12019 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16483 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20947 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25411 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29875 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34339 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_99 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2649) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2644));
    if (vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_4) {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_92 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_42;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_98 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_43;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_103 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_44;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_108 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_45;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_68 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_47;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_74 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_48;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_80 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_49;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_86 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_50;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_61 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_41;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_56 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_46;
    } else {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_92 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_47;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_98 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_48;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_103 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_49;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_108 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_50;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_68 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_42;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_74 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_43;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_80 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_44;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_86 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_45;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_61 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_46;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_56 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_41;
    }
    if (vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_9) {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_229 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_179;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_235 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_180;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_240 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_181;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_245 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_182;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_205 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_184;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_211 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_185;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_217 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_186;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_223 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_187;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_198 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_178;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_193 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_183;
    } else {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_229 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_184;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_235 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_185;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_240 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_186;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_245 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_187;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_205 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_179;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_211 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_180;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_217 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_181;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_223 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_182;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_198 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_183;
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_193 
            = vlSelfRef.__PVT___bucketLoadFirstDelta_T_178;
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__54(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__54\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_39 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1817) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1837));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_44 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1979) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2031 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1979) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1984 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1954) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1974));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2009 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1974) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1979));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_43 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1974) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1979));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_42 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1954) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1974));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_47 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2116) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2168 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2116) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2121 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2091) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2111));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2146 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2111) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2116));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_46 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2111) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2116));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_45 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2091) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2111));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_50 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2253) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2305 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2253) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2258 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2228) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2248));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2283 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2248) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2253));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_49 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2248) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2253));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_48 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2228) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2248));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_53 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2390) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2442 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2390) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2395 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2365) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2420 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2390));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_52 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2390));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_51 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2365) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2385));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_56 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2579 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2532 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2502) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2557 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_55 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2527));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_54 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2502) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2522));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_59 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2664) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2716 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2664) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2669 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2639) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2659));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2694 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2659) 
           != (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2664));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_58 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2659) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2664));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_57 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2639) 
           == (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2659));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_281 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_717 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__55(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__55\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1153 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1589 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2025 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2461 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2897 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3333 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_275 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_711 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1147 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1583 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2019 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2455 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2891 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3327 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_278 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_714 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1150 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1586 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2022 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2458 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2894 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3330 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_72 = (0x1fU 
                                                   & ((IData)(vlSelfRef.__PVT__bucketLoadFirstDelta_same)
                                                       ? 
                                                      ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37) 
                                                       + (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_68))
                                                       : (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_68)));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__56(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__56\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketLoadFirstDelta_same) {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_84 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_39) 
                     + (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_80)));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_90 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_40) 
                     + (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_86)));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_97 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_38) 
                     + (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_74)));
    } else {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_84 
            = (7U & (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_80));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_90 
            = (3U & (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_86));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_97 
            = (7U & (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_74));
    }
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_299 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_735 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1171 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1607 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2043 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2479 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2915 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3351 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_293 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_729 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1165 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1601 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2037 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2473 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2909 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3345 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_296 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_732 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1168 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__57(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__57\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1604 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2040 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2476 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2912 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3348 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketLoadFirstDelta_same_3) {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_209 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_174) 
                        + (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_205)));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_221 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_176) 
                     + (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_217)));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_227 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_177) 
                     + (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_223)));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_234 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_175) 
                     + (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_211)));
    } else {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_209 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_205));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_221 
            = (7U & (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_217));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_227 
            = (3U & (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_223));
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_234 
            = (7U & (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_211));
    }
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_281 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_717 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1153 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1589 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2025 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2461 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2897 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3333 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_275 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_711 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1147 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1583 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2019 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__58(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__58\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2455 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2891 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3327 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_278 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_714 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1150 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1586 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2022 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2458 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2894 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3330 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStoreFirstDelta_same) {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_72 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_37) 
                        + (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_68)));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_84 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_39) 
                     + (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_80)));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_90 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_40) 
                     + (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_86)));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_97 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_38) 
                     + (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_74)));
    } else {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_72 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_68));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_84 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_80));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_90 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_86));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_97 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_74));
    }
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_299 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_735 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1171 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1607 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2043 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2479 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2915 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__59(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__59\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3351 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_293 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_729 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1165 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1601 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2037 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2473 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2909 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3345 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_296 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_732 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1168 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1604 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2040 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2476 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2912 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3348 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStoreFirstDelta_same_3) {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_209 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_174) 
                        + (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_205)));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_221 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_176) 
                     + (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_217)));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_227 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_177) 
                     + (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_223)));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_234 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_175) 
                     + (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_211)));
    } else {
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_209 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_205));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_221 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_217));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_227 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_223));
        vlSelfRef.__PVT___bucketStoreFirstDelta_T_234 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_211));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2747 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__60(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__60\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7211 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11675 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16139 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20603 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25067 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29531 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_33995 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2741 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7205 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11669 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16133 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20597 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25061 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29525 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_33989 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_36) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2744 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7208 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11672 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16136 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20600 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25064 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29528 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_33992 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__61(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__61\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_72 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_37) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_68)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_84 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_39) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_80)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_90 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_40) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_86)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_97 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_74)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_72 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_68));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_84 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_80));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_90 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_86));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_97 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_74));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2765 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7229 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11693 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16157 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20621 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25085 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29549 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34013 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_198) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2759 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7223 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11687 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16151 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20615 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25079 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29543 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34007 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_173) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2762 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7226 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__62(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__62\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11690 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16154 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20618 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25082 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29546 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34010 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_193) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_3) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_209 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_174) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_205)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_221 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_176) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_217)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_227 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_177) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_223)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_234 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_175) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_211)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_209 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_205));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_221 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_217));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_227 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_223));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_234 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_211));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2783 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7247 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11711 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16175 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20639 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25103 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29567 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34031 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_387) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_335) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2777 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7241 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11705 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16169 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__63(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__63\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20633 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25097 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29561 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34025 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_340) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_310) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2780 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7244 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11708 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16172 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20636 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25100 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29564 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34028 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_365) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_330) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_6) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_346 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_311) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_342)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_358 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_313) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_354)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_364 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_314) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_360)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_371 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_312) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_348)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_346 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_342));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_358 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_354));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_364 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_360));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_371 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_348));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2801 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7265 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11729 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16193 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20657 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25121 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__64(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__64\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29585 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34049 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_524) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_472) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2795 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7259 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11723 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16187 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20651 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25115 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29579 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34043 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_477) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_447) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2798 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7262 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11726 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16190 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20654 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25118 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29582 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34046 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_502) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_467) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_9) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_483 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_448) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_479)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_495 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_450) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_491)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_501 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_451) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_497)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_508 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_449) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_485)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_483 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_479));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_495 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_491));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_501 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_497));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_508 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_485));
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__65(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__65\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2819 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7283 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11747 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16211 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20675 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25139 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29603 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34067 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_661) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_609) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2813 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7277 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11741 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16205 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20669 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25133 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29597 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34061 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_614) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_584) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2816 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7280 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11744 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16208 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20672 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25136 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29600 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__66(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__66\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34064 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_639) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_604) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_12) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_620 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_585) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_616)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_632 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_587) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_628)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_638 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_588) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_634)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_645 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_586) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_622)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_620 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_616));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_632 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_628));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_638 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_634));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_645 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_622));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2837 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7301 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11765 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16229 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20693 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25157 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29621 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34085 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_798) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_746) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2831 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7295 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11759 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16223 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20687 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25151 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29615 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34079 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_751) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_721) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2834 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__67(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__67\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7298 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11762 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16226 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20690 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25154 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29618 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34082 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_776) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_741) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_15) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_757 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_722) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_753)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_769 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_724) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_765)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_775 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_725) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_771)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_782 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_723) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_759)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_757 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_753));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_769 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_765));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_775 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_771));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_782 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_759));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2855 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7319 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11783 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16247 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20711 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25175 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29639 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34103 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_935) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_883) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2849 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7313 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11777 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__68(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__68\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16241 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20705 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25169 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29633 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34097 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_888) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_858) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2852 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7316 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11780 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16244 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20708 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25172 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29636 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34100 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_913) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_878) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_18) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_894 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_859) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_890)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_906 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_861) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_902)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_912 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_862) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_908)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_919 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_860) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_896)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_894 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_890));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_906 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_902));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_912 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_908));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_919 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_896));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2873 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7337 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11801 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16265 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20729 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__69(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__69\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25193 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29657 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34121 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1072) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1020) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2867 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7331 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11795 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16259 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20723 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25187 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29651 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34115 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1025) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_995) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2870 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7334 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11798 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16262 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20726 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25190 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29654 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34118 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1050) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1015) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_21) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1031 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_996) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1027)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1043 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_998) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1039)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1049 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_999) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1045)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1056 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_997) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1033)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1031 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1027));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1043 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1039));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1049 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1045));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1056 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1033));
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__70(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__70\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2891 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7355 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11819 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16283 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20747 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25211 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29675 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34139 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1209) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1157) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2885 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7349 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11813 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16277 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20741 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25205 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29669 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34133 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1162) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1132) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2888 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7352 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11816 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16280 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20744 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25208 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29672 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__71(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__71\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34136 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1187) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1152) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_24) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1168 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1133) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1164)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1180 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1135) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1176)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1186 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1136) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1182)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1193 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1134) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1170)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1168 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1164));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1180 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1176));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1186 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1182));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1193 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1170));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2909 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7373 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11837 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16301 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20765 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25229 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29693 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34157 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1346) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1294) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2903 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7367 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11831 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16295 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20759 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25223 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29687 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34151 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1299) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1269) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2906 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__72(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__72\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7370 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11834 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16298 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20762 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25226 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29690 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34154 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1324) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1289) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_27) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1305 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1270) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1301)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1317 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1272) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1313)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1323 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1273) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1319)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1330 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1271) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1307)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1305 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1301));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1317 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1313));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1323 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1319));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1330 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1307));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2927 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7391 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11855 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16319 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20783 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25247 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29711 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34175 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1483) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1431) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2921 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7385 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11849 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__73(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__73\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16313 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20777 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25241 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29705 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34169 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1436) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1406) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2924 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7388 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11852 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16316 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20780 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25244 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29708 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34172 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1461) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1426) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_30) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1442 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1407) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1438)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1454 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1409) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1450)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1460 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1410) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1456)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1467 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1408) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1444)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1442 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1438));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1454 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1450));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1460 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1456));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1467 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1444));
    }
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2945 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7409 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11873 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16337 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20801 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__74(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__74\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25265 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29729 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34193 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1620) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1568) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2939 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7403 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11867 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16331 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20795 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25259 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29723 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34187 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1573) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1543) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2942 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7406 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11870 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16334 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20798 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25262 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29726 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34190 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1598) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1563) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_same_33) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1579 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1544) 
                        + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1575)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1591 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1546) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1587)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1597 
            = (3U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1547) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1593)));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1604 
            = (7U & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1545) 
                     + (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1581)));
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1579 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1575));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1591 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1587));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1597 
            = (3U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1593));
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1604 
            = (7U & (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1581));
    }
}

VL_INLINE_OPT void Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__75(Vtb_GeometryBankProof* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_GeometryBankProof___nba_sequent__TOP__tb__DOT__dut__DOT__candidate_3__75\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2963 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7427 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11891 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16355 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20819 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25283 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29747 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34211 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1757) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1705) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2957 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7421 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11885 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16349 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20813 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25277 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29741 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34205 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1710) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1680) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2960 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7424 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11888 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16352 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20816 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25280 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29744 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1735) 
           & ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1700) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}
