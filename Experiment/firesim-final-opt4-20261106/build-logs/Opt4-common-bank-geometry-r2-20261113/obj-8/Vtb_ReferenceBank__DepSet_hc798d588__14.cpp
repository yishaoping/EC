// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_ReferenceBank.h"
#include "Vtb__Syms.h"

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__12(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__12\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__isCurrent_8 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0x18U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_9 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                    == (0xffU & ((IData)(0x19U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_10 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                     == (0xffU & ((IData)(0x1aU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_11 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                     == (0xffU & ((IData)(0x1bU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_12 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                     == (0xffU & ((IData)(0x1cU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_13 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                     == (0xffU & ((IData)(0x1dU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_14 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                     == (0xffU & ((IData)(0x1eU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_15 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                     == (0xffU & ((IData)(0x1fU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
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
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__13(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__13\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__retireSelect_8 = ((0xffU & ((IData)(0x18U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_9 = ((0xffU & ((IData)(0x19U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_10 = ((0xffU & ((IData)(0x1aU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                        == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_11 = ((0xffU & ((IData)(0x1bU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                        == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_12 = ((0xffU & ((IData)(0x1cU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                        == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_13 = ((0xffU & ((IData)(0x1dU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                        == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_14 = ((0xffU & ((IData)(0x1eU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                        == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_15 = ((0xffU & ((IData)(0x1fU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                        == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__resolving_0 = ((IData)(vlSelfRef.buckets_valid_0) 
                                    & (vlSelfRef.buckets_seq_0 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_1 = ((IData)(vlSelfRef.__PVT__buckets_valid_1) 
                                    & (vlSelfRef.__PVT__buckets_seq_1 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_2 = ((IData)(vlSelfRef.__PVT__buckets_valid_2) 
                                    & (vlSelfRef.__PVT__buckets_seq_2 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_3 = ((IData)(vlSelfRef.__PVT__buckets_valid_3) 
                                    & (vlSelfRef.__PVT__buckets_seq_3 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_4 = ((IData)(vlSelfRef.__PVT__buckets_valid_4) 
                                    & (vlSelfRef.__PVT__buckets_seq_4 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_5 = ((IData)(vlSelfRef.__PVT__buckets_valid_5) 
                                    & (vlSelfRef.__PVT__buckets_seq_5 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_6 = ((IData)(vlSelfRef.__PVT__buckets_valid_6) 
                                    & (vlSelfRef.__PVT__buckets_seq_6 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_7 = ((IData)(vlSelfRef.__PVT__buckets_valid_7) 
                                    & (vlSelfRef.__PVT__buckets_seq_7 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_8 = ((IData)(vlSelfRef.__PVT__buckets_valid_8) 
                                    & (vlSelfRef.__PVT__buckets_seq_8 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_9 = ((IData)(vlSelfRef.__PVT__buckets_valid_9) 
                                    & (vlSelfRef.__PVT__buckets_seq_9 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_10 = ((IData)(vlSelfRef.__PVT__buckets_valid_10) 
                                     & (vlSelfRef.__PVT__buckets_seq_10 
                                        <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_11 = ((IData)(vlSelfRef.__PVT__buckets_valid_11) 
                                     & (vlSelfRef.__PVT__buckets_seq_11 
                                        <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__14(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__14\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__resolving_12 = ((IData)(vlSelfRef.__PVT__buckets_valid_12) 
                                     & (vlSelfRef.__PVT__buckets_seq_12 
                                        <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_13 = ((IData)(vlSelfRef.__PVT__buckets_valid_13) 
                                     & (vlSelfRef.__PVT__buckets_seq_13 
                                        <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_14 = ((IData)(vlSelfRef.__PVT__buckets_valid_14) 
                                     & (vlSelfRef.__PVT__buckets_seq_14 
                                        <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
    vlSelfRef.__PVT__resolving_15 = ((IData)(vlSelfRef.buckets_valid_15) 
                                     & (vlSelfRef.buckets_seq_15 
                                        <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
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
    vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_6 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_storeSources_6_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_storeSources_7_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_0_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_1_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_1 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_2_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_3_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_5 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_4_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_5_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_6 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_6_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_7_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_10 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_8_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_9_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_11 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_10_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_11_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_15 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_12_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_13_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_16 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_14_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_15_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_20 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_16_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_17_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_21 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_18_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_19_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_25 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_20_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_21_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_26 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_22_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_23_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_30 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_24_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_25_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_31 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_26_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_27_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_35 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_28_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_29_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_36 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_30_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_31_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_40 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_32_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_33_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_41 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_34_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_35_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_45 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_36_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_37_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_46 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_38_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_39_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_50 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_40_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_41_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_51 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_42_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_43_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_55 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_44_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_45_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_56 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_46_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_47_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_60 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_48_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_49_key));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__15(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__15\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_61 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_50_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_51_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_65 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_52_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_53_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_66 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_54_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_55_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_70 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_56_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_57_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_71 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_58_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_59_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_75 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_60_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_61_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_76 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_62_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_63_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_80 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_64_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_65_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_81 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_66_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_67_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_85 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_68_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_69_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_86 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_70_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_71_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_90 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_72_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_73_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_91 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_74_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_75_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_95 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_76_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_77_key));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_96 
        = ((IData)(vlSymsp->TOP.tb__DOT__io_strictSources_78_key) 
           <= (IData)(vlSymsp->TOP.tb__DOT__io_strictSources_79_key));
    vlSelfRef.__PVT___T_16 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                              & ((IData)(vlSelfRef.__PVT__isRetiring) 
                                 & (IData)(vlSelfRef.bucketValid_0)));
    vlSelfRef.__PVT___T_89 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                              & ((IData)(vlSelfRef.__PVT__isRetiring_1) 
                                 & (IData)(vlSelfRef.__PVT__bucketValid_1)));
    vlSelfRef.__PVT___T_162 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_2) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_2)));
    vlSelfRef.__PVT___T_235 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_3) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_3)));
    vlSelfRef.__PVT___T_308 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_4) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_4)));
    vlSelfRef.__PVT___T_381 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_5) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_5)));
    vlSelfRef.__PVT___T_454 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_6) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_6)));
    vlSelfRef.__PVT___T_527 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_7) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_7)));
    vlSelfRef.__PVT___T_600 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_8) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_8)));
    vlSelfRef.__PVT___T_673 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_9) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_9)));
    vlSelfRef.__PVT___T_746 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_10) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_10)));
    vlSelfRef.__PVT___T_819 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_11) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_11)));
    vlSelfRef.__PVT___T_892 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_12) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_12)));
    vlSelfRef.__PVT___T_965 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                               & ((IData)(vlSelfRef.__PVT__isRetiring_13) 
                                  & (IData)(vlSelfRef.__PVT__bucketValid_13)));
    vlSelfRef.__PVT___T_1038 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                                & ((IData)(vlSelfRef.__PVT__isRetiring_14) 
                                   & (IData)(vlSelfRef.__PVT__bucketValid_14)));
    vlSelfRef.__PVT___T_1111 = ((IData)(vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346) 
                                & ((IData)(vlSelfRef.__PVT__isRetiring_15) 
                                   & (IData)(vlSelfRef.bucketValid_15)));
    vlSelfRef.io_queryMatch_0 = (IData)(((0U == (0xf0U 
                                                 & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset))) 
                                         & (((0xfU 
                                              == (0xfU 
                                                  & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                              ? (IData)(vlSelfRef.bucketValid_15)
                                              : ((0xeU 
                                                  == 
                                                  (0xfU 
                                                   & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                  ? (IData)(vlSelfRef.__PVT__bucketValid_14)
                                                  : 
                                                 ((0xdU 
                                                   == 
                                                   (0xfU 
                                                    & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                   ? (IData)(vlSelfRef.__PVT__bucketValid_13)
                                                   : 
                                                  ((0xcU 
                                                    == 
                                                    (0xfU 
                                                     & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                    ? (IData)(vlSelfRef.__PVT__bucketValid_12)
                                                    : 
                                                   ((0xbU 
                                                     == 
                                                     (0xfU 
                                                      & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                     ? (IData)(vlSelfRef.__PVT__bucketValid_11)
                                                     : 
                                                    ((0xaU 
                                                      == 
                                                      (0xfU 
                                                       & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                      ? (IData)(vlSelfRef.__PVT__bucketValid_10)
                                                      : 
                                                     ((9U 
                                                       == 
                                                       (0xfU 
                                                        & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                       ? (IData)(vlSelfRef.__PVT__bucketValid_9)
                                                       : 
                                                      ((8U 
                                                        == 
                                                        (0xfU 
                                                         & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                        ? (IData)(vlSelfRef.__PVT__bucketValid_8)
                                                        : 
                                                       ((7U 
                                                         == 
                                                         (0xfU 
                                                          & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                         ? (IData)(vlSelfRef.__PVT__bucketValid_7)
                                                         : 
                                                        ((6U 
                                                          == 
                                                          (0xfU 
                                                           & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                          ? (IData)(vlSelfRef.__PVT__bucketValid_6)
                                                          : 
                                                         ((5U 
                                                           == 
                                                           (0xfU 
                                                            & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                           ? (IData)(vlSelfRef.__PVT__bucketValid_5)
                                                           : 
                                                          ((4U 
                                                            == 
                                                            (0xfU 
                                                             & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                            ? (IData)(vlSelfRef.__PVT__bucketValid_4)
                                                            : 
                                                           ((3U 
                                                             == 
                                                             (0xfU 
                                                              & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                             ? (IData)(vlSelfRef.__PVT__bucketValid_3)
                                                             : 
                                                            ((2U 
                                                              == 
                                                              (0xfU 
                                                               & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                              ? (IData)(vlSelfRef.__PVT__bucketValid_2)
                                                              : 
                                                             ((1U 
                                                               == 
                                                               (0xfU 
                                                                & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                               ? (IData)(vlSelfRef.__PVT__bucketValid_1)
                                                               : (IData)(vlSelfRef.bucketValid_0)))))))))))))))) 
                                            & ((((0xfU 
                                                  == 
                                                  (0xfU 
                                                   & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                  ? vlSelfRef.bucketSeq_15
                                                  : 
                                                 ((0xeU 
                                                   == 
                                                   (0xfU 
                                                    & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                   ? vlSelfRef.__PVT__bucketSeq_14
                                                   : 
                                                  ((0xdU 
                                                    == 
                                                    (0xfU 
                                                     & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                    ? vlSelfRef.__PVT__bucketSeq_13
                                                    : 
                                                   ((0xcU 
                                                     == 
                                                     (0xfU 
                                                      & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                     ? vlSelfRef.__PVT__bucketSeq_12
                                                     : 
                                                    ((0xbU 
                                                      == 
                                                      (0xfU 
                                                       & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                      ? vlSelfRef.__PVT__bucketSeq_11
                                                      : 
                                                     ((0xaU 
                                                       == 
                                                       (0xfU 
                                                        & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                       ? vlSelfRef.__PVT__bucketSeq_10
                                                       : 
                                                      ((9U 
                                                        == 
                                                        (0xfU 
                                                         & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                        ? vlSelfRef.__PVT__bucketSeq_9
                                                        : 
                                                       ((8U 
                                                         == 
                                                         (0xfU 
                                                          & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                         ? vlSelfRef.__PVT__bucketSeq_8
                                                         : 
                                                        ((7U 
                                                          == 
                                                          (0xfU 
                                                           & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                          ? vlSelfRef.__PVT__bucketSeq_7
                                                          : 
                                                         ((6U 
                                                           == 
                                                           (0xfU 
                                                            & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                           ? vlSelfRef.__PVT__bucketSeq_6
                                                           : 
                                                          ((5U 
                                                            == 
                                                            (0xfU 
                                                             & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                            ? vlSelfRef.__PVT__bucketSeq_5
                                                            : 
                                                           ((4U 
                                                             == 
                                                             (0xfU 
                                                              & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                             ? vlSelfRef.__PVT__bucketSeq_4
                                                             : 
                                                            ((3U 
                                                              == 
                                                              (0xfU 
                                                               & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                              ? vlSelfRef.__PVT__bucketSeq_3
                                                              : 
                                                             ((2U 
                                                               == 
                                                               (0xfU 
                                                                & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                               ? vlSelfRef.__PVT__bucketSeq_2
                                                               : 
                                                              ((1U 
                                                                == 
                                                                (0xfU 
                                                                 & (IData)(vlSelfRef.__PVT__io_queryMatch_0_offset)))
                                                                ? vlSelfRef.__PVT__bucketSeq_1
                                                                : vlSelfRef.bucketSeq_0))))))))))))))) 
                                                >> 8U) 
                                               == (vlSymsp->TOP.tb__DOT__io_querySeq_0 
                                                   >> 8U)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__122(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__122\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__available_7 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(0x17U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_22) 
                                       | (vlSelfRef.__PVT__buckets_seq_7 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_8 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(0x18U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_25) 
                                       | (vlSelfRef.__PVT__buckets_seq_8 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_9 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                     == (0xffU & ((IData)(0x19U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                    & ((IData)(vlSelfRef.__PVT___canAccept_T_28) 
                                       | (vlSelfRef.__PVT__buckets_seq_9 
                                          == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_10 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                      == (0xffU & ((IData)(0x1aU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_31) 
                                        | (vlSelfRef.__PVT__buckets_seq_10 
                                           == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_11 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                      == (0xffU & ((IData)(0x1bU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_34) 
                                        | (vlSelfRef.__PVT__buckets_seq_11 
                                           == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_12 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                      == (0xffU & ((IData)(0x1cU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_37) 
                                        | (vlSelfRef.__PVT__buckets_seq_12 
                                           == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__123(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__123\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__available_13 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                      == (0xffU & ((IData)(0x1dU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_40) 
                                        | (vlSelfRef.__PVT__buckets_seq_13 
                                           == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_14 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                      == (0xffU & ((IData)(0x1eU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_43) 
                                        | (vlSelfRef.__PVT__buckets_seq_14 
                                           == vlSymsp->TOP.tb__DOT__io_barrierEvent_bits)));
    vlSelfRef.__PVT__available_15 = (((0xffU & vlSymsp->TOP.tb__DOT__io_barrierEvent_bits) 
                                      == (0xffU & ((IData)(0x1fU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_barrierBase)))) 
                                     & ((IData)(vlSelfRef.__PVT___canAccept_T_46) 
                                        | (vlSelfRef.buckets_seq_15 
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
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__139(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__139\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_98) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2723 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2636;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2729 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2637;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2735 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2638;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2650 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2625;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2651 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2626;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2652 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2627;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2653 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2628;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2634;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2649 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2624;
    } else {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2723 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2626;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2729 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2627;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2735 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2628;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2650 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2635;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2651 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2636;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2652 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2637;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2653 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2638;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2624;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2649 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2634;
    }
    if (vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_97) {
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2640 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2620;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2641 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2621;
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
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2640 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2630;
        vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2641 
            = vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2631;
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
                                             & (IData)(vlSelfRef.__PVT___GEN_4176));
    vlSelfRef.__PVT___countOverflow_1_T_2 = ((IData)(vlSelfRef.__PVT__accepted_1) 
                                             & (IData)(vlSelfRef.__PVT___GEN_4191));
    vlSelfRef.__PVT___countOverflow_2_T_2 = ((IData)(vlSelfRef.__PVT__accepted_2) 
                                             & (IData)(vlSelfRef.__PVT___GEN_4206));
    vlSelfRef.__PVT___countOverflow_3_T_2 = ((IData)(vlSelfRef.__PVT__accepted_3) 
                                             & (IData)(vlSelfRef.__PVT___GEN_4221));
    vlSelfRef.__PVT___countOverflow_4_T_2 = ((IData)(vlSelfRef.__PVT__accepted_4) 
                                             & (IData)(vlSelfRef.__PVT___GEN_4236));
    vlSelfRef.__PVT___countOverflow_5_T_2 = ((IData)(vlSelfRef.__PVT__accepted_5) 
                                             & (IData)(vlSelfRef.__PVT___GEN_4251));
    vlSelfRef.__PVT___countOverflow_6_T_2 = ((IData)(vlSelfRef.__PVT__accepted_6) 
                                             & (IData)(vlSelfRef.__PVT___GEN_4266));
    vlSelfRef.__PVT___countOverflow_7_T_2 = ((IData)(vlSelfRef.__PVT__accepted_7) 
                                             & (IData)(vlSelfRef.__PVT___GEN_4281));
    vlSelfRef.__PVT___countOverflow_8_T_2 = ((IData)(vlSelfRef.__PVT__accepted_8) 
                                             & (IData)(vlSelfRef.__PVT___GEN_4296));
    vlSelfRef.__PVT___countOverflow_9_T_2 = ((IData)(vlSelfRef.__PVT__accepted_9) 
                                             & (IData)(vlSelfRef.__PVT___GEN_4311));
    vlSelfRef.__PVT___countOverflow_10_T_2 = ((IData)(vlSelfRef.__PVT__accepted_10) 
                                              & (IData)(vlSelfRef.__PVT___GEN_4326));
    vlSelfRef.__PVT___countOverflow_11_T_2 = ((IData)(vlSelfRef.__PVT__accepted_11) 
                                              & (IData)(vlSelfRef.__PVT___GEN_4341));
    vlSelfRef.__PVT___countOverflow_12_T_2 = ((IData)(vlSelfRef.__PVT__accepted_12) 
                                              & (IData)(vlSelfRef.__PVT___GEN_4356));
    vlSelfRef.__PVT___countOverflow_13_T_2 = ((IData)(vlSelfRef.__PVT__accepted_13) 
                                              & (IData)(vlSelfRef.__PVT___GEN_4371));
    vlSelfRef.__PVT___countOverflow_14_T_2 = ((IData)(vlSelfRef.__PVT__accepted_14) 
                                              & (IData)(vlSelfRef.__PVT___GEN_4386));
    vlSelfRef.__PVT___countOverflow_15_T_2 = ((IData)(vlSelfRef.__PVT__accepted_15) 
                                              & (IData)(vlSelfRef.__PVT___GEN_4401));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_283 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__140(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__140\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3771 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4207 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4643 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5079 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5515 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5951 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6387 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6823 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_51) 
         == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
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
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3789 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4225 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4661 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5097 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5533 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__141(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__141\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5969 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6405 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6841 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_188) 
         == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketLoadFirstDelta_ordered_9 
        = ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_183) 
           <= (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_178));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_283 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
         == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_719 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
         == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1155 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1591 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2027 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2463 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2899 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3335 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3771 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4207 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4643 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5079 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5515 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5951 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6387 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6823 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_51) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_4 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_46) 
           <= (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_41));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_301 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
         == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_737 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
         == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1173 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1609 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2045 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2481 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2917 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3353 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__142(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__142\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3789 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4225 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4661 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5097 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5533 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5969 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6405 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6841 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_188) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStoreFirstDelta_ordered_9 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_183) 
           <= (IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_178));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2749 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7213 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11677 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16141 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20605 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25069 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29533 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_33997 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38461 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42925 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47389 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51853 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56317 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60781 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65245 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69709 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_4 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_46) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_41));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2767 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7231 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11695 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__143(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__143\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16159 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20623 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25087 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29551 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34015 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38479 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42943 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47407 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51871 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56335 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60799 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65263 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69727 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_188) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_9 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_183) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_178));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2785 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7249 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11713 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16177 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20641 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25105 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29569 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34033 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38497 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42961 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47425 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51889 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56353 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60817 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65281 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__144(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__144\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69745 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_325) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_14 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_320) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_315));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2803 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7267 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11731 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16195 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20659 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25123 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29587 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34051 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38515 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42979 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47443 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51907 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56371 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60835 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65299 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69763 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_462) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_19 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_457) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_452));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2821 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7285 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11749 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16213 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20677 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25141 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29605 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34069 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38533 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_42997 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__145(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__145\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47461 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51925 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56389 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60853 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65317 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69781 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_599) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_24 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_594) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_589));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2839 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7303 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11767 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16231 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20695 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25159 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29623 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34087 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38551 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43015 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47479 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51943 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56407 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60871 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65335 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69799 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_736) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_29 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_731) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_726));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2857 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7321 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11785 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16249 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20713 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__146(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__146\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25177 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29641 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34105 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38569 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43033 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47497 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51961 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56425 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60889 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65353 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69817 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_873) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_34 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_868) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_863));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2875 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7339 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11803 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16267 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20731 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25195 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29659 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34123 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38587 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43051 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47515 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51979 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56443 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60907 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65371 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69835 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1010) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_39 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1005) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1000));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__147(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__147\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2893 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7357 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11821 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16285 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20749 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25213 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29677 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34141 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38605 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43069 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47533 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_51997 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56461 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60925 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65389 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69853 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1147) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_44 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1142) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1137));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2911 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7375 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11839 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16303 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20767 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25231 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29695 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34159 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38623 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43087 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47551 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52015 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__148(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__148\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56479 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60943 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65407 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69871 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1284) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_49 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1279) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1274));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2929 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7393 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11857 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16321 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20785 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25249 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29713 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34177 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38641 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43105 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47569 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52033 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56497 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60961 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65425 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69889 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1421) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_54 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1416) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1411));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2947 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7411 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11875 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16339 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20803 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25267 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29731 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__149(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__149\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34195 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38659 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43123 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47587 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52051 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56515 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60979 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65443 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69907 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1558) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_59 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1553) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1548));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2965 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7429 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11893 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16357 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20821 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25285 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29749 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34213 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38677 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43141 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47605 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52069 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56533 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_60997 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65461 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69925 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1695) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_64 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1690) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1685));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2983 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7447 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__150(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__150\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11911 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16375 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20839 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25303 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29767 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34231 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38695 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43159 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47623 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52087 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56551 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61015 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65479 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69943 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1832) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_69 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1827) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1822));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3001 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7465 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11929 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16393 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20857 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25321 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29785 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34249 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38713 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43177 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47641 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52105 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56569 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61033 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__151(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__151\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65497 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69961 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1969) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_74 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1964) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_1959));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3019 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7483 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11947 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16411 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20875 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25339 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29803 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34267 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38731 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43195 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47659 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52123 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56587 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61051 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65515 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69979 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2106) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_79 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2101) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2096));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3037 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7501 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11965 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16429 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20893 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25357 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29821 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34285 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38749 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__152(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__152\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43213 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47677 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52141 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56605 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61069 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65533 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_69997 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2243) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_84 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2238) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2233));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3055 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7519 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_11983 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16447 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20911 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25375 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29839 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34303 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38767 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43231 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47695 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52159 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56623 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61087 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65551 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_70015 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2380) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_89 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2375) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2370));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3073 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7537 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12001 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16465 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__153(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__153\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20929 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25393 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29857 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34321 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38785 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43249 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47713 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52177 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56641 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61105 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65569 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_70033 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2517) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_94 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2512) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2507));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_3091 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_7555 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_12019 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_16483 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_20947 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_25411 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_29875 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_34339 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_38803 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_43267 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_47731 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_52195 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_56659 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_61123 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_65587 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_70051 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2654) 
           == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__154(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__154\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__bucketStrictWriteReadDelta_ordered_99 
        = ((IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2649) 
           <= (IData)(vlSelfRef.__PVT___bucketStrictWriteReadDelta_T_2644));
    vlSelfRef.io_barrierCycleOverflow = (((IData)(vlSelfRef.__PVT___countOverflow_15_T_2) 
                                          & (vlSelfRef.buckets_requestCycleSum_15 
                                             > (0xffffffffffffffffULL 
                                                - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                         | (((IData)(vlSelfRef.__PVT___countOverflow_14_T_2) 
                                             & (vlSelfRef.__PVT__buckets_requestCycleSum_14 
                                                > (0xffffffffffffffffULL 
                                                   - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                            | (((IData)(vlSelfRef.__PVT___countOverflow_13_T_2) 
                                                & (vlSelfRef.__PVT__buckets_requestCycleSum_13 
                                                   > 
                                                   (0xffffffffffffffffULL 
                                                    - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                               | (((IData)(vlSelfRef.__PVT___countOverflow_12_T_2) 
                                                   & (vlSelfRef.__PVT__buckets_requestCycleSum_12 
                                                      > 
                                                      (0xffffffffffffffffULL 
                                                       - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                  | (((IData)(vlSelfRef.__PVT___countOverflow_11_T_2) 
                                                      & (vlSelfRef.__PVT__buckets_requestCycleSum_11 
                                                         > 
                                                         (0xffffffffffffffffULL 
                                                          - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                     | (((IData)(vlSelfRef.__PVT___countOverflow_10_T_2) 
                                                         & (vlSelfRef.__PVT__buckets_requestCycleSum_10 
                                                            > 
                                                            (0xffffffffffffffffULL 
                                                             - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                        | (((IData)(vlSelfRef.__PVT___countOverflow_9_T_2) 
                                                            & (vlSelfRef.__PVT__buckets_requestCycleSum_9 
                                                               > 
                                                               (0xffffffffffffffffULL 
                                                                - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                           | (((IData)(vlSelfRef.__PVT___countOverflow_8_T_2) 
                                                               & (vlSelfRef.__PVT__buckets_requestCycleSum_8 
                                                                  > 
                                                                  (0xffffffffffffffffULL 
                                                                   - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                              | (((IData)(vlSelfRef.__PVT___countOverflow_7_T_2) 
                                                                  & (vlSelfRef.__PVT__buckets_requestCycleSum_7 
                                                                     > 
                                                                     (0xffffffffffffffffULL 
                                                                      - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                                 | (((IData)(vlSelfRef.__PVT___countOverflow_6_T_2) 
                                                                     & (vlSelfRef.__PVT__buckets_requestCycleSum_6 
                                                                        > 
                                                                        (0xffffffffffffffffULL 
                                                                         - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                                    | (((IData)(vlSelfRef.__PVT___countOverflow_5_T_2) 
                                                                        & (vlSelfRef.__PVT__buckets_requestCycleSum_5 
                                                                           > 
                                                                           (0xffffffffffffffffULL 
                                                                            - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                                       | (((IData)(vlSelfRef.__PVT___countOverflow_4_T_2) 
                                                                           & (vlSelfRef.__PVT__buckets_requestCycleSum_4 
                                                                              > 
                                                                              (0xffffffffffffffffULL 
                                                                               - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                                          | (((IData)(vlSelfRef.__PVT___countOverflow_3_T_2) 
                                                                              & (vlSelfRef.__PVT__buckets_requestCycleSum_3 
                                                                                > 
                                                                                (0xffffffffffffffffULL 
                                                                                - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                                             | (((IData)(vlSelfRef.__PVT___countOverflow_2_T_2) 
                                                                                & (vlSelfRef.__PVT__buckets_requestCycleSum_2 
                                                                                > 
                                                                                (0xffffffffffffffffULL 
                                                                                - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                                                | (((IData)(vlSelfRef.__PVT___countOverflow_1_T_2) 
                                                                                & (vlSelfRef.__PVT__buckets_requestCycleSum_1 
                                                                                > 
                                                                                (0xffffffffffffffffULL 
                                                                                - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))) 
                                                                                | ((IData)(vlSelfRef.__PVT___countOverflow_0_T_2) 
                                                                                & (vlSelfRef.buckets_requestCycleSum_0 
                                                                                > 
                                                                                (0xffffffffffffffffULL 
                                                                                - vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle))))))))))))))))));
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
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__166(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__166\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
            == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_717 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1153 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1589 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2025 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2461 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2897 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3333 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3769 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4205 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4641 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5077 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5513 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5949 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6385 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6821 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_61) 
            == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__167(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__167\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_275 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_711 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1147 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1583 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2019 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2455 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2891 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3327 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3763 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4199 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4635 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5071 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5507 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5943 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6379 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6815 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_36) 
            == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_278 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_714 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1150 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1586 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2022 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2458 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2894 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__168(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__168\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3330 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3766 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4202 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4638 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5074 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5510 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5946 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6382 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6818 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_56) 
            == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    if (vlSelfRef.__PVT__bucketLoadFirstDelta_same) {
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_72 
            = (0x1fU & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_37) 
                        + (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_68)));
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
        vlSelfRef.__PVT___bucketLoadFirstDelta_T_72 
            = (0x1fU & (IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_68));
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
            == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_735 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1171 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1607 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2043 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2479 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2915 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3351 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3787 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__169(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__169\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4223 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4659 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5095 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5531 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5967 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6403 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6839 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_198) 
            == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_293 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_729 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1165 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1601 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2037 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2473 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2909 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3345 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3781 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4217 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4653 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5089 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5525 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5961 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6397 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6833 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_173) 
            == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__170(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__170\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_296 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_732 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1168 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_1604 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2040 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2476 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_2912 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3348 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_3784 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4220 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_4656 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5092 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5528 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_5964 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6400 = 
        ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketLoadFirstDelta_T_193) 
            == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketLoadFirstDelta_T_6836 = 
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
            == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_717 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
            == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__171(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__171\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1153 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1589 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2025 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2461 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2897 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3333 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3769 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4205 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4641 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5077 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5513 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5949 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6385 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6821 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_113) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_61) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_275 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
            == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_711 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
            == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1147 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1583 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2019 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2455 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2891 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3327 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3763 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__172(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__172\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4199 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4635 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5071 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5507 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5943 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6379 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6815 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_66) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_36) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_278 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
            == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_714 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
            == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1150 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1586 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2022 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2458 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2894 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3330 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3766 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4202 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4638 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5074 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5510 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5946 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6382 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6818 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_91) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_56) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__173(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__173\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
            == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_735 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
            == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1171 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1607 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2043 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2479 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2915 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3351 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3787 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4223 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4659 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5095 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5531 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5967 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6403 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6839 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_250) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_198) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_293 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
            == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_729 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
            == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}

VL_INLINE_OPT void Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__174(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___act_sequent__TOP__tb__DOT__dut__DOT__reference_1__174\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1165 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1601 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2037 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2473 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2909 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3345 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3781 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4217 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x19U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_4653 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x1aU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5089 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x1bU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5525 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x1cU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_5961 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x1dU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6397 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x1eU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_6833 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_203) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_173) 
              == (0xffU & ((IData)(0x1fU) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_296 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
            == (0xffU & ((IData)(0x10U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_732 = 
        ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
         & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
            == (0xffU & ((IData)(0x11U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1168 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x12U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_1604 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x13U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2040 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x14U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2476 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x15U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_2912 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x16U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3348 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x17U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
    vlSelfRef.__PVT___bucketStoreFirstDelta_T_3784 
        = ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_228) 
           & ((IData)(vlSelfRef.__PVT___bucketStoreFirstDelta_T_193) 
              == (0xffU & ((IData)(0x18U) + (IData)(vlSymsp->TOP.tb__DOT__io_base)))));
}
