// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb.h for the primary calling header

#include "Vtb__pch.h"
#include "Vtb_ReferenceBank.h"
#include "Vtb__Syms.h"

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_0__12(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_0__12\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__isCurrent_12 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                     == (0xffU & ((IData)(0xcU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_13 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                     == (0xffU & ((IData)(0xdU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_14 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                     == (0xffU & ((IData)(0xeU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isCurrent_15 = ((0xffU & vlSymsp->TOP.tb__DOT__io_processSeq) 
                                     == (0xffU & ((IData)(0xfU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__retireSelect_0 = ((IData)(vlSymsp->TOP.tb__DOT__io_base) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_1 = ((0xffU & ((IData)(1U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_2 = ((0xffU & ((IData)(2U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_3 = ((0xffU & ((IData)(3U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_4 = ((0xffU & ((IData)(4U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_5 = ((0xffU & ((IData)(5U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_6 = ((0xffU & ((IData)(6U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_7 = ((0xffU & ((IData)(7U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_8 = ((0xffU & ((IData)(8U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_9 = ((0xffU & ((IData)(9U) 
                                                 + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                       == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_10 = ((0xffU & ((IData)(0xaU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                        == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_11 = ((0xffU & ((IData)(0xbU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                        == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_12 = ((0xffU & ((IData)(0xcU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                        == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_13 = ((0xffU & ((IData)(0xdU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                        == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_14 = ((0xffU & ((IData)(0xeU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                        == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__retireSelect_15 = ((0xffU & ((IData)(0xfU) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))) 
                                        == (0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq));
    vlSelfRef.__PVT__resolving_0 = ((IData)(vlSelfRef.buckets_valid_0) 
                                    & (vlSelfRef.buckets_seq_0 
                                       <= vlSymsp->TOP.tb__DOT__io_barrierSafeWatermark));
}

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_0__13(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_0__13\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_0__14(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_0__14\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_0__15(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_0__15\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__0(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT___buckets_count_0_T_1 = (1ULL + vlSelfRef.buckets_count_0);
    vlSelfRef.__PVT___buckets_count_1_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_1);
    vlSelfRef.__PVT___buckets_count_2_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_2);
    vlSelfRef.__PVT___buckets_count_3_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_3);
    vlSelfRef.__PVT___buckets_count_4_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_4);
    vlSelfRef.__PVT___buckets_count_5_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_5);
    vlSelfRef.__PVT___buckets_count_6_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_6);
    vlSelfRef.__PVT___buckets_count_7_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_7);
    vlSelfRef.__PVT___buckets_count_8_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_8);
    vlSelfRef.__PVT___buckets_count_9_T_1 = (1ULL + vlSelfRef.__PVT__buckets_count_9);
    vlSelfRef.__PVT___buckets_count_10_T_1 = (1ULL 
                                              + vlSelfRef.__PVT__buckets_count_10);
    vlSelfRef.__PVT___buckets_count_11_T_1 = (1ULL 
                                              + vlSelfRef.__PVT__buckets_count_11);
    vlSelfRef.__PVT___buckets_count_12_T_1 = (1ULL 
                                              + vlSelfRef.__PVT__buckets_count_12);
    vlSelfRef.__PVT___buckets_count_13_T_1 = (1ULL 
                                              + vlSelfRef.__PVT__buckets_count_13);
    vlSelfRef.__PVT___buckets_count_14_T_1 = (1ULL 
                                              + vlSelfRef.__PVT__buckets_count_14);
    vlSelfRef.__PVT___buckets_count_15_T_1 = (1ULL 
                                              + vlSelfRef.buckets_count_15);
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
        = (vlSelfRef.__PVT__buckets_requestCycleSum_7 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_8_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_8 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_9_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_9 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_10_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_10 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_11_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_11 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_12_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_12 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_13_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_13 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_14_T_1 
        = (vlSelfRef.__PVT__buckets_requestCycleSum_14 
           + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
    vlSelfRef.__PVT___buckets_requestCycleSum_15_T_1 
        = (vlSelfRef.buckets_requestCycleSum_15 + vlSymsp->TOP.tb__DOT__io_barrierCurrentCycle);
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
}

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__1(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__1\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.__PVT__isRetiring_8 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0x18U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_9 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                     == (0xffU & ((IData)(0x19U) 
                                                  + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_10 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                      == (0xffU & ((IData)(0x1aU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_11 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                      == (0xffU & ((IData)(0x1bU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_12 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                      == (0xffU & ((IData)(0x1cU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_13 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                      == (0xffU & ((IData)(0x1dU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_14 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                      == (0xffU & ((IData)(0x1eU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__PVT__isRetiring_15 = ((0xffU & vlSymsp->TOP.tb__DOT__io_retiringSeq) 
                                      == (0xffU & ((IData)(0x1fU) 
                                                   + (IData)(vlSymsp->TOP.tb__DOT__io_base))));
    vlSelfRef.__VdfgRegularize_h35be3f4f_0_1346 = (
                                                   (~ (IData)(vlSymsp->TOP.tb__DOT__io_safeError)) 
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

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__2(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__2\n"); );
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

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__3(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__3\n"); );
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

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__4(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__4\n"); );
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

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__5(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__5\n"); );
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

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__6(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__6\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                              ? vlSelfRef.bucketStore_0_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketStore_0_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentStoreNextWide[0U] = __Vtemp_4[0U];
    vlSelfRef.__PVT__currentStoreNextWide[1U] = __Vtemp_4[1U];
    vlSelfRef.__PVT__currentStoreNextWide[2U] = (1U 
                                                 & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                              ? vlSelfRef.bucketStore_0_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketStore_0_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentStoreNextWide_1[0U] = __Vtemp_8[0U];
    vlSelfRef.__PVT__currentStoreNextWide_1[1U] = __Vtemp_8[1U];
    vlSelfRef.__PVT__currentStoreNextWide_1[2U] = (1U 
                                                   & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketStore_0_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                                ? vlSelfRef.bucketStore_0_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentStoreNextWide_2[0U] = __Vtemp_12[0U];
    vlSelfRef.__PVT__currentStoreNextWide_2[1U] = __Vtemp_12[1U];
    vlSelfRef.__PVT__currentStoreNextWide_2[2U] = (1U 
                                                   & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketStore_0_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                                ? vlSelfRef.bucketStore_0_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentStoreNextWide_3[0U] = __Vtemp_16[0U];
    vlSelfRef.__PVT__currentStoreNextWide_3[1U] = __Vtemp_16[1U];
    vlSelfRef.__PVT__currentStoreNextWide_3[2U] = (1U 
                                                   & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketStore_1_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketStore_1_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentStoreNextWide_4[0U] = __Vtemp_20[0U];
    vlSelfRef.__PVT__currentStoreNextWide_4[1U] = __Vtemp_20[1U];
    vlSelfRef.__PVT__currentStoreNextWide_4[2U] = (1U 
                                                   & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketStore_1_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketStore_1_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentStoreNextWide_5[0U] = __Vtemp_24[0U];
    vlSelfRef.__PVT__currentStoreNextWide_5[1U] = __Vtemp_24[1U];
    vlSelfRef.__PVT__currentStoreNextWide_5[2U] = (1U 
                                                   & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketStore_1_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketStore_1_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentStoreNextWide_6[0U] = __Vtemp_28[0U];
    vlSelfRef.__PVT__currentStoreNextWide_6[1U] = __Vtemp_28[1U];
    vlSelfRef.__PVT__currentStoreNextWide_6[2U] = (1U 
                                                   & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketStore_1_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketStore_1_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__currentStoreNextWide_7[0U] = __Vtemp_32[0U];
    vlSelfRef.__PVT__currentStoreNextWide_7[1U] = __Vtemp_32[1U];
    vlSelfRef.__PVT__currentStoreNextWide_7[2U] = (1U 
                                                   & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketStore_2_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                                ? vlSelfRef.__PVT__bucketStore_2_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__currentStoreNextWide_8[0U] = __Vtemp_36[0U];
    vlSelfRef.__PVT__currentStoreNextWide_8[1U] = __Vtemp_36[1U];
    vlSelfRef.__PVT__currentStoreNextWide_8[2U] = (1U 
                                                   & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketStore_2_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                                ? vlSelfRef.__PVT__bucketStore_2_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__currentStoreNextWide_9[0U] = __Vtemp_40[0U];
    vlSelfRef.__PVT__currentStoreNextWide_9[1U] = __Vtemp_40[1U];
    vlSelfRef.__PVT__currentStoreNextWide_9[2U] = (1U 
                                                   & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketStore_2_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                                ? vlSelfRef.__PVT__bucketStore_2_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__currentStoreNextWide_10[0U] = 
        __Vtemp_44[0U];
    vlSelfRef.__PVT__currentStoreNextWide_10[1U] = 
        __Vtemp_44[1U];
    vlSelfRef.__PVT__currentStoreNextWide_10[2U] = 
        (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketStore_2_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                                ? vlSelfRef.__PVT__bucketStore_2_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__currentStoreNextWide_11[0U] = 
        __Vtemp_48[0U];
    vlSelfRef.__PVT__currentStoreNextWide_11[1U] = 
        __Vtemp_48[1U];
    vlSelfRef.__PVT__currentStoreNextWide_11[2U] = 
        (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketStore_3_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketStore_3_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__currentStoreNextWide_12[0U] = 
        __Vtemp_52[0U];
    vlSelfRef.__PVT__currentStoreNextWide_12[1U] = 
        __Vtemp_52[1U];
    vlSelfRef.__PVT__currentStoreNextWide_12[2U] = 
        (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketStore_3_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketStore_3_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__currentStoreNextWide_13[0U] = 
        __Vtemp_56[0U];
    vlSelfRef.__PVT__currentStoreNextWide_13[1U] = 
        __Vtemp_56[1U];
    vlSelfRef.__PVT__currentStoreNextWide_13[2U] = 
        (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketStore_3_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketStore_3_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__currentStoreNextWide_14[0U] = 
        __Vtemp_60[0U];
    vlSelfRef.__PVT__currentStoreNextWide_14[1U] = 
        __Vtemp_60[1U];
    vlSelfRef.__PVT__currentStoreNextWide_14[2U] = 
        (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketStore_3_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketStore_3_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__currentStoreNextWide_15[0U] = 
        __Vtemp_64[0U];
    vlSelfRef.__PVT__currentStoreNextWide_15[1U] = 
        __Vtemp_64[1U];
    vlSelfRef.__PVT__currentStoreNextWide_15[2U] = 
        (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketStore_4_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketStore_4_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__currentStoreNextWide_16[0U] = 
        __Vtemp_68[0U];
    vlSelfRef.__PVT__currentStoreNextWide_16[1U] = 
        __Vtemp_68[1U];
    vlSelfRef.__PVT__currentStoreNextWide_16[2U] = 
        (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketStore_4_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketStore_4_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__currentStoreNextWide_17[0U] = 
        __Vtemp_72[0U];
    vlSelfRef.__PVT__currentStoreNextWide_17[1U] = 
        __Vtemp_72[1U];
    vlSelfRef.__PVT__currentStoreNextWide_17[2U] = 
        (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketStore_4_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketStore_4_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__currentStoreNextWide_18[0U] = 
        __Vtemp_76[0U];
    vlSelfRef.__PVT__currentStoreNextWide_18[1U] = 
        __Vtemp_76[1U];
    vlSelfRef.__PVT__currentStoreNextWide_18[2U] = 
        (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketStore_4_3
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketStore_4_3
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__currentStoreNextWide_19[0U] = 
        __Vtemp_80[0U];
    vlSelfRef.__PVT__currentStoreNextWide_19[1U] = 
        __Vtemp_80[1U];
    vlSelfRef.__PVT__currentStoreNextWide_19[2U] = 
        (1U & __Vtemp_80[2U]);
}

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__7(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__7\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                              ? vlSelfRef.__PVT__bucketStore_5_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketStore_5_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentStoreNextWide_20[0U] = 
        __Vtemp_4[0U];
    vlSelfRef.__PVT__currentStoreNextWide_20[1U] = 
        __Vtemp_4[1U];
    vlSelfRef.__PVT__currentStoreNextWide_20[2U] = 
        (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                              ? vlSelfRef.__PVT__bucketStore_5_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketStore_5_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentStoreNextWide_21[0U] = 
        __Vtemp_8[0U];
    vlSelfRef.__PVT__currentStoreNextWide_21[1U] = 
        __Vtemp_8[1U];
    vlSelfRef.__PVT__currentStoreNextWide_21[2U] = 
        (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketStore_5_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketStore_5_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentStoreNextWide_22[0U] = 
        __Vtemp_12[0U];
    vlSelfRef.__PVT__currentStoreNextWide_22[1U] = 
        __Vtemp_12[1U];
    vlSelfRef.__PVT__currentStoreNextWide_22[2U] = 
        (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketStore_5_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketStore_5_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentStoreNextWide_23[0U] = 
        __Vtemp_16[0U];
    vlSelfRef.__PVT__currentStoreNextWide_23[1U] = 
        __Vtemp_16[1U];
    vlSelfRef.__PVT__currentStoreNextWide_23[2U] = 
        (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketStore_6_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketStore_6_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentStoreNextWide_24[0U] = 
        __Vtemp_20[0U];
    vlSelfRef.__PVT__currentStoreNextWide_24[1U] = 
        __Vtemp_20[1U];
    vlSelfRef.__PVT__currentStoreNextWide_24[2U] = 
        (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketStore_6_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketStore_6_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentStoreNextWide_25[0U] = 
        __Vtemp_24[0U];
    vlSelfRef.__PVT__currentStoreNextWide_25[1U] = 
        __Vtemp_24[1U];
    vlSelfRef.__PVT__currentStoreNextWide_25[2U] = 
        (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketStore_6_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketStore_6_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentStoreNextWide_26[0U] = 
        __Vtemp_28[0U];
    vlSelfRef.__PVT__currentStoreNextWide_26[1U] = 
        __Vtemp_28[1U];
    vlSelfRef.__PVT__currentStoreNextWide_26[2U] = 
        (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketStore_6_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketStore_6_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__currentStoreNextWide_27[0U] = 
        __Vtemp_32[0U];
    vlSelfRef.__PVT__currentStoreNextWide_27[1U] = 
        __Vtemp_32[1U];
    vlSelfRef.__PVT__currentStoreNextWide_27[2U] = 
        (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_7)
                               ? vlSelfRef.__PVT__bucketStore_7_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_7)
                                ? vlSelfRef.__PVT__bucketStore_7_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__currentStoreNextWide_28[0U] = 
        __Vtemp_36[0U];
    vlSelfRef.__PVT__currentStoreNextWide_28[1U] = 
        __Vtemp_36[1U];
    vlSelfRef.__PVT__currentStoreNextWide_28[2U] = 
        (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_7)
                               ? vlSelfRef.__PVT__bucketStore_7_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_7)
                                ? vlSelfRef.__PVT__bucketStore_7_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__currentStoreNextWide_29[0U] = 
        __Vtemp_40[0U];
    vlSelfRef.__PVT__currentStoreNextWide_29[1U] = 
        __Vtemp_40[1U];
    vlSelfRef.__PVT__currentStoreNextWide_29[2U] = 
        (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_7)
                               ? vlSelfRef.__PVT__bucketStore_7_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_7)
                                ? vlSelfRef.__PVT__bucketStore_7_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__currentStoreNextWide_30[0U] = 
        __Vtemp_44[0U];
    vlSelfRef.__PVT__currentStoreNextWide_30[1U] = 
        __Vtemp_44[1U];
    vlSelfRef.__PVT__currentStoreNextWide_30[2U] = 
        (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_7)
                               ? vlSelfRef.__PVT__bucketStore_7_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_7)
                                ? vlSelfRef.__PVT__bucketStore_7_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__currentStoreNextWide_31[0U] = 
        __Vtemp_48[0U];
    vlSelfRef.__PVT__currentStoreNextWide_31[1U] = 
        __Vtemp_48[1U];
    vlSelfRef.__PVT__currentStoreNextWide_31[2U] = 
        (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_8)
                               ? vlSelfRef.__PVT__bucketStore_8_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_8)
                                ? vlSelfRef.__PVT__bucketStore_8_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__currentStoreNextWide_32[0U] = 
        __Vtemp_52[0U];
    vlSelfRef.__PVT__currentStoreNextWide_32[1U] = 
        __Vtemp_52[1U];
    vlSelfRef.__PVT__currentStoreNextWide_32[2U] = 
        (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_8)
                               ? vlSelfRef.__PVT__bucketStore_8_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_8)
                                ? vlSelfRef.__PVT__bucketStore_8_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__currentStoreNextWide_33[0U] = 
        __Vtemp_56[0U];
    vlSelfRef.__PVT__currentStoreNextWide_33[1U] = 
        __Vtemp_56[1U];
    vlSelfRef.__PVT__currentStoreNextWide_33[2U] = 
        (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_8)
                               ? vlSelfRef.__PVT__bucketStore_8_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_8)
                                ? vlSelfRef.__PVT__bucketStore_8_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__currentStoreNextWide_34[0U] = 
        __Vtemp_60[0U];
    vlSelfRef.__PVT__currentStoreNextWide_34[1U] = 
        __Vtemp_60[1U];
    vlSelfRef.__PVT__currentStoreNextWide_34[2U] = 
        (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_8)
                               ? vlSelfRef.__PVT__bucketStore_8_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_8)
                                ? vlSelfRef.__PVT__bucketStore_8_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__currentStoreNextWide_35[0U] = 
        __Vtemp_64[0U];
    vlSelfRef.__PVT__currentStoreNextWide_35[1U] = 
        __Vtemp_64[1U];
    vlSelfRef.__PVT__currentStoreNextWide_35[2U] = 
        (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_9)
                               ? vlSelfRef.__PVT__bucketStore_9_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_9)
                                ? vlSelfRef.__PVT__bucketStore_9_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__currentStoreNextWide_36[0U] = 
        __Vtemp_68[0U];
    vlSelfRef.__PVT__currentStoreNextWide_36[1U] = 
        __Vtemp_68[1U];
    vlSelfRef.__PVT__currentStoreNextWide_36[2U] = 
        (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_9)
                               ? vlSelfRef.__PVT__bucketStore_9_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_9)
                                ? vlSelfRef.__PVT__bucketStore_9_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__currentStoreNextWide_37[0U] = 
        __Vtemp_72[0U];
    vlSelfRef.__PVT__currentStoreNextWide_37[1U] = 
        __Vtemp_72[1U];
    vlSelfRef.__PVT__currentStoreNextWide_37[2U] = 
        (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_9)
                               ? vlSelfRef.__PVT__bucketStore_9_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_9)
                                ? vlSelfRef.__PVT__bucketStore_9_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__currentStoreNextWide_38[0U] = 
        __Vtemp_76[0U];
    vlSelfRef.__PVT__currentStoreNextWide_38[1U] = 
        __Vtemp_76[1U];
    vlSelfRef.__PVT__currentStoreNextWide_38[2U] = 
        (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_9)
                               ? vlSelfRef.__PVT__bucketStore_9_3
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_9)
                                ? vlSelfRef.__PVT__bucketStore_9_3
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__currentStoreNextWide_39[0U] = 
        __Vtemp_80[0U];
    vlSelfRef.__PVT__currentStoreNextWide_39[1U] = 
        __Vtemp_80[1U];
    vlSelfRef.__PVT__currentStoreNextWide_39[2U] = 
        (1U & __Vtemp_80[2U]);
}

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__8(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__8\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_10)
                              ? vlSelfRef.__PVT__bucketStore_10_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_10)
                               ? vlSelfRef.__PVT__bucketStore_10_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentStoreNextWide_40[0U] = 
        __Vtemp_4[0U];
    vlSelfRef.__PVT__currentStoreNextWide_40[1U] = 
        __Vtemp_4[1U];
    vlSelfRef.__PVT__currentStoreNextWide_40[2U] = 
        (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_10)
                              ? vlSelfRef.__PVT__bucketStore_10_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_10)
                               ? vlSelfRef.__PVT__bucketStore_10_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentStoreNextWide_41[0U] = 
        __Vtemp_8[0U];
    vlSelfRef.__PVT__currentStoreNextWide_41[1U] = 
        __Vtemp_8[1U];
    vlSelfRef.__PVT__currentStoreNextWide_41[2U] = 
        (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_10)
                               ? vlSelfRef.__PVT__bucketStore_10_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_10)
                                ? vlSelfRef.__PVT__bucketStore_10_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentStoreNextWide_42[0U] = 
        __Vtemp_12[0U];
    vlSelfRef.__PVT__currentStoreNextWide_42[1U] = 
        __Vtemp_12[1U];
    vlSelfRef.__PVT__currentStoreNextWide_42[2U] = 
        (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_10)
                               ? vlSelfRef.__PVT__bucketStore_10_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_10)
                                ? vlSelfRef.__PVT__bucketStore_10_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentStoreNextWide_43[0U] = 
        __Vtemp_16[0U];
    vlSelfRef.__PVT__currentStoreNextWide_43[1U] = 
        __Vtemp_16[1U];
    vlSelfRef.__PVT__currentStoreNextWide_43[2U] = 
        (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_11)
                               ? vlSelfRef.__PVT__bucketStore_11_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_11)
                                ? vlSelfRef.__PVT__bucketStore_11_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentStoreNextWide_44[0U] = 
        __Vtemp_20[0U];
    vlSelfRef.__PVT__currentStoreNextWide_44[1U] = 
        __Vtemp_20[1U];
    vlSelfRef.__PVT__currentStoreNextWide_44[2U] = 
        (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_11)
                               ? vlSelfRef.__PVT__bucketStore_11_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_11)
                                ? vlSelfRef.__PVT__bucketStore_11_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentStoreNextWide_45[0U] = 
        __Vtemp_24[0U];
    vlSelfRef.__PVT__currentStoreNextWide_45[1U] = 
        __Vtemp_24[1U];
    vlSelfRef.__PVT__currentStoreNextWide_45[2U] = 
        (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_11)
                               ? vlSelfRef.__PVT__bucketStore_11_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_11)
                                ? vlSelfRef.__PVT__bucketStore_11_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentStoreNextWide_46[0U] = 
        __Vtemp_28[0U];
    vlSelfRef.__PVT__currentStoreNextWide_46[1U] = 
        __Vtemp_28[1U];
    vlSelfRef.__PVT__currentStoreNextWide_46[2U] = 
        (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_11)
                               ? vlSelfRef.__PVT__bucketStore_11_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_11)
                                ? vlSelfRef.__PVT__bucketStore_11_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__currentStoreNextWide_47[0U] = 
        __Vtemp_32[0U];
    vlSelfRef.__PVT__currentStoreNextWide_47[1U] = 
        __Vtemp_32[1U];
    vlSelfRef.__PVT__currentStoreNextWide_47[2U] = 
        (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_12)
                               ? vlSelfRef.__PVT__bucketStore_12_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_12)
                                ? vlSelfRef.__PVT__bucketStore_12_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__currentStoreNextWide_48[0U] = 
        __Vtemp_36[0U];
    vlSelfRef.__PVT__currentStoreNextWide_48[1U] = 
        __Vtemp_36[1U];
    vlSelfRef.__PVT__currentStoreNextWide_48[2U] = 
        (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_12)
                               ? vlSelfRef.__PVT__bucketStore_12_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_12)
                                ? vlSelfRef.__PVT__bucketStore_12_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__currentStoreNextWide_49[0U] = 
        __Vtemp_40[0U];
    vlSelfRef.__PVT__currentStoreNextWide_49[1U] = 
        __Vtemp_40[1U];
    vlSelfRef.__PVT__currentStoreNextWide_49[2U] = 
        (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_12)
                               ? vlSelfRef.__PVT__bucketStore_12_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_12)
                                ? vlSelfRef.__PVT__bucketStore_12_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__currentStoreNextWide_50[0U] = 
        __Vtemp_44[0U];
    vlSelfRef.__PVT__currentStoreNextWide_50[1U] = 
        __Vtemp_44[1U];
    vlSelfRef.__PVT__currentStoreNextWide_50[2U] = 
        (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_12)
                               ? vlSelfRef.__PVT__bucketStore_12_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_12)
                                ? vlSelfRef.__PVT__bucketStore_12_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__currentStoreNextWide_51[0U] = 
        __Vtemp_48[0U];
    vlSelfRef.__PVT__currentStoreNextWide_51[1U] = 
        __Vtemp_48[1U];
    vlSelfRef.__PVT__currentStoreNextWide_51[2U] = 
        (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_13)
                               ? vlSelfRef.__PVT__bucketStore_13_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_13)
                                ? vlSelfRef.__PVT__bucketStore_13_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__currentStoreNextWide_52[0U] = 
        __Vtemp_52[0U];
    vlSelfRef.__PVT__currentStoreNextWide_52[1U] = 
        __Vtemp_52[1U];
    vlSelfRef.__PVT__currentStoreNextWide_52[2U] = 
        (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_13)
                               ? vlSelfRef.__PVT__bucketStore_13_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_13)
                                ? vlSelfRef.__PVT__bucketStore_13_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__currentStoreNextWide_53[0U] = 
        __Vtemp_56[0U];
    vlSelfRef.__PVT__currentStoreNextWide_53[1U] = 
        __Vtemp_56[1U];
    vlSelfRef.__PVT__currentStoreNextWide_53[2U] = 
        (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_13)
                               ? vlSelfRef.__PVT__bucketStore_13_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_13)
                                ? vlSelfRef.__PVT__bucketStore_13_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__currentStoreNextWide_54[0U] = 
        __Vtemp_60[0U];
    vlSelfRef.__PVT__currentStoreNextWide_54[1U] = 
        __Vtemp_60[1U];
    vlSelfRef.__PVT__currentStoreNextWide_54[2U] = 
        (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_13)
                               ? vlSelfRef.__PVT__bucketStore_13_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_13)
                                ? vlSelfRef.__PVT__bucketStore_13_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__currentStoreNextWide_55[0U] = 
        __Vtemp_64[0U];
    vlSelfRef.__PVT__currentStoreNextWide_55[1U] = 
        __Vtemp_64[1U];
    vlSelfRef.__PVT__currentStoreNextWide_55[2U] = 
        (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_14)
                               ? vlSelfRef.__PVT__bucketStore_14_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_14)
                                ? vlSelfRef.__PVT__bucketStore_14_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__currentStoreNextWide_56[0U] = 
        __Vtemp_68[0U];
    vlSelfRef.__PVT__currentStoreNextWide_56[1U] = 
        __Vtemp_68[1U];
    vlSelfRef.__PVT__currentStoreNextWide_56[2U] = 
        (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_14)
                               ? vlSelfRef.__PVT__bucketStore_14_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_14)
                                ? vlSelfRef.__PVT__bucketStore_14_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__currentStoreNextWide_57[0U] = 
        __Vtemp_72[0U];
    vlSelfRef.__PVT__currentStoreNextWide_57[1U] = 
        __Vtemp_72[1U];
    vlSelfRef.__PVT__currentStoreNextWide_57[2U] = 
        (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_14)
                               ? vlSelfRef.__PVT__bucketStore_14_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_14)
                                ? vlSelfRef.__PVT__bucketStore_14_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__currentStoreNextWide_58[0U] = 
        __Vtemp_76[0U];
    vlSelfRef.__PVT__currentStoreNextWide_58[1U] = 
        __Vtemp_76[1U];
    vlSelfRef.__PVT__currentStoreNextWide_58[2U] = 
        (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_14)
                               ? vlSelfRef.__PVT__bucketStore_14_3
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_14)
                                ? vlSelfRef.__PVT__bucketStore_14_3
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__currentStoreNextWide_59[0U] = 
        __Vtemp_80[0U];
    vlSelfRef.__PVT__currentStoreNextWide_59[1U] = 
        __Vtemp_80[1U];
    vlSelfRef.__PVT__currentStoreNextWide_59[2U] = 
        (1U & __Vtemp_80[2U]);
}

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__9(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__9\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.bucketValid_15)
                              ? vlSelfRef.bucketStore_15_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.bucketValid_15)
                               ? vlSelfRef.bucketStore_15_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentStoreNextWide_60[0U] = 
        __Vtemp_4[0U];
    vlSelfRef.__PVT__currentStoreNextWide_60[1U] = 
        __Vtemp_4[1U];
    vlSelfRef.__PVT__currentStoreNextWide_60[2U] = 
        (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.bucketValid_15)
                              ? vlSelfRef.bucketStore_15_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.bucketValid_15)
                               ? vlSelfRef.bucketStore_15_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentStoreNextWide_61[0U] = 
        __Vtemp_8[0U];
    vlSelfRef.__PVT__currentStoreNextWide_61[1U] = 
        __Vtemp_8[1U];
    vlSelfRef.__PVT__currentStoreNextWide_61[2U] = 
        (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.bucketValid_15)
                               ? vlSelfRef.bucketStore_15_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.bucketValid_15)
                                ? vlSelfRef.bucketStore_15_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentStoreNextWide_62[0U] = 
        __Vtemp_12[0U];
    vlSelfRef.__PVT__currentStoreNextWide_62[1U] = 
        __Vtemp_12[1U];
    vlSelfRef.__PVT__currentStoreNextWide_62[2U] = 
        (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.bucketValid_15)
                               ? vlSelfRef.bucketStore_15_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.bucketValid_15)
                                ? vlSelfRef.bucketStore_15_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentStoreNextWide_63[0U] = 
        __Vtemp_16[0U];
    vlSelfRef.__PVT__currentStoreNextWide_63[1U] = 
        __Vtemp_16[1U];
    vlSelfRef.__PVT__currentStoreNextWide_63[2U] = 
        (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketFirstStore_0_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                                ? vlSelfRef.bucketFirstStore_0_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentFirstStoreNextWide[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketFirstStore_0_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                                ? vlSelfRef.bucketFirstStore_0_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentFirstStoreNextWide_1[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_1[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_1[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketFirstStore_0_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                                ? vlSelfRef.bucketFirstStore_0_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentFirstStoreNextWide_2[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_2[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_2[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.bucketValid_0)
                               ? vlSelfRef.bucketFirstStore_0_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.bucketValid_0)
                                ? vlSelfRef.bucketFirstStore_0_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__currentFirstStoreNextWide_3[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_3[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_3[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketFirstStore_1_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketFirstStore_1_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__currentFirstStoreNextWide_4[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_4[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_4[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketFirstStore_1_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketFirstStore_1_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__currentFirstStoreNextWide_5[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_5[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_5[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketFirstStore_1_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketFirstStore_1_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__currentFirstStoreNextWide_6[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_6[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_6[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_1)
                               ? vlSelfRef.__PVT__bucketFirstStore_1_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_1)
                                ? vlSelfRef.__PVT__bucketFirstStore_1_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__currentFirstStoreNextWide_7[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_7[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_7[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketFirstStore_2_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                                ? vlSelfRef.__PVT__bucketFirstStore_2_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__currentFirstStoreNextWide_8[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_8[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_8[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketFirstStore_2_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                                ? vlSelfRef.__PVT__bucketFirstStore_2_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__currentFirstStoreNextWide_9[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_9[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_9[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketFirstStore_2_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                                ? vlSelfRef.__PVT__bucketFirstStore_2_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__currentFirstStoreNextWide_10[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_10[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_10[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_2)
                               ? vlSelfRef.__PVT__bucketFirstStore_2_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_2)
                                ? vlSelfRef.__PVT__bucketFirstStore_2_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__currentFirstStoreNextWide_11[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_11[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_11[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketFirstStore_3_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketFirstStore_3_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__currentFirstStoreNextWide_12[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_12[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_12[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketFirstStore_3_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketFirstStore_3_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__currentFirstStoreNextWide_13[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_13[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_13[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketFirstStore_3_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketFirstStore_3_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__currentFirstStoreNextWide_14[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_14[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_14[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_3)
                               ? vlSelfRef.__PVT__bucketFirstStore_3_3
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_3)
                                ? vlSelfRef.__PVT__bucketFirstStore_3_3
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__currentFirstStoreNextWide_15[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_15[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_15[2U] 
        = (1U & __Vtemp_80[2U]);
}

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__10(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__10\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                              ? vlSelfRef.__PVT__bucketFirstStore_4_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketFirstStore_4_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentFirstStoreNextWide_16[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_16[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_16[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                              ? vlSelfRef.__PVT__bucketFirstStore_4_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketFirstStore_4_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentFirstStoreNextWide_17[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_17[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_17[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketFirstStore_4_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketFirstStore_4_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentFirstStoreNextWide_18[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_18[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_18[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_4)
                               ? vlSelfRef.__PVT__bucketFirstStore_4_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_4)
                                ? vlSelfRef.__PVT__bucketFirstStore_4_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentFirstStoreNextWide_19[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_19[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_19[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketFirstStore_5_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketFirstStore_5_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentFirstStoreNextWide_20[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_20[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_20[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketFirstStore_5_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketFirstStore_5_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentFirstStoreNextWide_21[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_21[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_21[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketFirstStore_5_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketFirstStore_5_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentFirstStoreNextWide_22[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_22[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_22[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_5)
                               ? vlSelfRef.__PVT__bucketFirstStore_5_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_5)
                                ? vlSelfRef.__PVT__bucketFirstStore_5_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__currentFirstStoreNextWide_23[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_23[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_23[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketFirstStore_6_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__currentFirstStoreNextWide_24[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_24[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_24[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketFirstStore_6_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__currentFirstStoreNextWide_25[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_25[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_25[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketFirstStore_6_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__currentFirstStoreNextWide_26[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_26[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_26[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_6)
                               ? vlSelfRef.__PVT__bucketFirstStore_6_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_6)
                                ? vlSelfRef.__PVT__bucketFirstStore_6_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__currentFirstStoreNextWide_27[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_27[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_27[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_7)
                               ? vlSelfRef.__PVT__bucketFirstStore_7_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_7)
                                ? vlSelfRef.__PVT__bucketFirstStore_7_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_28[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_7)
                               ? vlSelfRef.__PVT__bucketFirstStore_7_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_7)
                                ? vlSelfRef.__PVT__bucketFirstStore_7_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_29[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_7)
                               ? vlSelfRef.__PVT__bucketFirstStore_7_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_7)
                                ? vlSelfRef.__PVT__bucketFirstStore_7_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_30[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_7)
                               ? vlSelfRef.__PVT__bucketFirstStore_7_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_7)
                                ? vlSelfRef.__PVT__bucketFirstStore_7_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_31[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_8)
                               ? vlSelfRef.__PVT__bucketFirstStore_8_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_8)
                                ? vlSelfRef.__PVT__bucketFirstStore_8_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__currentFirstStoreNextWide_32[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_32[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_32[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_8)
                               ? vlSelfRef.__PVT__bucketFirstStore_8_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_8)
                                ? vlSelfRef.__PVT__bucketFirstStore_8_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__currentFirstStoreNextWide_33[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_33[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_33[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_8)
                               ? vlSelfRef.__PVT__bucketFirstStore_8_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_8)
                                ? vlSelfRef.__PVT__bucketFirstStore_8_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__currentFirstStoreNextWide_34[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_34[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_34[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_8)
                               ? vlSelfRef.__PVT__bucketFirstStore_8_3
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_8)
                                ? vlSelfRef.__PVT__bucketFirstStore_8_3
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__currentFirstStoreNextWide_35[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_35[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_35[2U] 
        = (1U & __Vtemp_80[2U]);
}

VL_ATTR_COLD void Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__11(Vtb_ReferenceBank* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtb_ReferenceBank___stl_sequent__TOP__tb__DOT__dut__DOT__reference_1__11\n"); );
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
    // Body
    __Vtemp_2[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_9)
                              ? vlSelfRef.__PVT__bucketFirstStore_9_0
                              : 0ULL));
    __Vtemp_2[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_9)
                               ? vlSelfRef.__PVT__bucketFirstStore_9_0
                               : 0ULL) >> 0x20U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    vlSelfRef.__PVT__currentFirstStoreNextWide_36[0U] 
        = __Vtemp_4[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_36[1U] 
        = __Vtemp_4[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_36[2U] 
        = (1U & __Vtemp_4[2U]);
    __Vtemp_6[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_9)
                              ? vlSelfRef.__PVT__bucketFirstStore_9_1
                              : 0ULL));
    __Vtemp_6[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_9)
                               ? vlSelfRef.__PVT__bucketFirstStore_9_1
                               : 0ULL) >> 0x20U));
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_7[1U] = 0U;
    __Vtemp_7[2U] = 0U;
    VL_ADD_W(3, __Vtemp_8, __Vtemp_6, __Vtemp_7);
    vlSelfRef.__PVT__currentFirstStoreNextWide_37[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_37[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_37[2U] 
        = (1U & __Vtemp_8[2U]);
    __Vtemp_10[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_9)
                               ? vlSelfRef.__PVT__bucketFirstStore_9_2
                               : 0ULL));
    __Vtemp_10[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_9)
                                ? vlSelfRef.__PVT__bucketFirstStore_9_2
                                : 0ULL) >> 0x20U));
    __Vtemp_10[2U] = 0U;
    __Vtemp_11[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_11[1U] = 0U;
    __Vtemp_11[2U] = 0U;
    VL_ADD_W(3, __Vtemp_12, __Vtemp_10, __Vtemp_11);
    vlSelfRef.__PVT__currentFirstStoreNextWide_38[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_38[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_38[2U] 
        = (1U & __Vtemp_12[2U]);
    __Vtemp_14[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_9)
                               ? vlSelfRef.__PVT__bucketFirstStore_9_3
                               : 0ULL));
    __Vtemp_14[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_9)
                                ? vlSelfRef.__PVT__bucketFirstStore_9_3
                                : 0ULL) >> 0x20U));
    __Vtemp_14[2U] = 0U;
    __Vtemp_15[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_15[1U] = 0U;
    __Vtemp_15[2U] = 0U;
    VL_ADD_W(3, __Vtemp_16, __Vtemp_14, __Vtemp_15);
    vlSelfRef.__PVT__currentFirstStoreNextWide_39[0U] 
        = __Vtemp_16[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_39[1U] 
        = __Vtemp_16[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_39[2U] 
        = (1U & __Vtemp_16[2U]);
    __Vtemp_18[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_10)
                               ? vlSelfRef.__PVT__bucketFirstStore_10_0
                               : 0ULL));
    __Vtemp_18[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_10)
                                ? vlSelfRef.__PVT__bucketFirstStore_10_0
                                : 0ULL) >> 0x20U));
    __Vtemp_18[2U] = 0U;
    __Vtemp_19[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_19[1U] = 0U;
    __Vtemp_19[2U] = 0U;
    VL_ADD_W(3, __Vtemp_20, __Vtemp_18, __Vtemp_19);
    vlSelfRef.__PVT__currentFirstStoreNextWide_40[0U] 
        = __Vtemp_20[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_40[1U] 
        = __Vtemp_20[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_40[2U] 
        = (1U & __Vtemp_20[2U]);
    __Vtemp_22[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_10)
                               ? vlSelfRef.__PVT__bucketFirstStore_10_1
                               : 0ULL));
    __Vtemp_22[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_10)
                                ? vlSelfRef.__PVT__bucketFirstStore_10_1
                                : 0ULL) >> 0x20U));
    __Vtemp_22[2U] = 0U;
    __Vtemp_23[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_23[1U] = 0U;
    __Vtemp_23[2U] = 0U;
    VL_ADD_W(3, __Vtemp_24, __Vtemp_22, __Vtemp_23);
    vlSelfRef.__PVT__currentFirstStoreNextWide_41[0U] 
        = __Vtemp_24[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_41[1U] 
        = __Vtemp_24[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_41[2U] 
        = (1U & __Vtemp_24[2U]);
    __Vtemp_26[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_10)
                               ? vlSelfRef.__PVT__bucketFirstStore_10_2
                               : 0ULL));
    __Vtemp_26[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_10)
                                ? vlSelfRef.__PVT__bucketFirstStore_10_2
                                : 0ULL) >> 0x20U));
    __Vtemp_26[2U] = 0U;
    __Vtemp_27[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    VL_ADD_W(3, __Vtemp_28, __Vtemp_26, __Vtemp_27);
    vlSelfRef.__PVT__currentFirstStoreNextWide_42[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_42[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_42[2U] 
        = (1U & __Vtemp_28[2U]);
    __Vtemp_30[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_10)
                               ? vlSelfRef.__PVT__bucketFirstStore_10_3
                               : 0ULL));
    __Vtemp_30[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_10)
                                ? vlSelfRef.__PVT__bucketFirstStore_10_3
                                : 0ULL) >> 0x20U));
    __Vtemp_30[2U] = 0U;
    __Vtemp_31[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_31[1U] = 0U;
    __Vtemp_31[2U] = 0U;
    VL_ADD_W(3, __Vtemp_32, __Vtemp_30, __Vtemp_31);
    vlSelfRef.__PVT__currentFirstStoreNextWide_43[0U] 
        = __Vtemp_32[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_43[1U] 
        = __Vtemp_32[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_43[2U] 
        = (1U & __Vtemp_32[2U]);
    __Vtemp_34[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_11)
                               ? vlSelfRef.__PVT__bucketFirstStore_11_0
                               : 0ULL));
    __Vtemp_34[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_11)
                                ? vlSelfRef.__PVT__bucketFirstStore_11_0
                                : 0ULL) >> 0x20U));
    __Vtemp_34[2U] = 0U;
    __Vtemp_35[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_35[1U] = 0U;
    __Vtemp_35[2U] = 0U;
    VL_ADD_W(3, __Vtemp_36, __Vtemp_34, __Vtemp_35);
    vlSelfRef.__PVT__currentFirstStoreNextWide_44[0U] 
        = __Vtemp_36[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_44[1U] 
        = __Vtemp_36[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_44[2U] 
        = (1U & __Vtemp_36[2U]);
    __Vtemp_38[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_11)
                               ? vlSelfRef.__PVT__bucketFirstStore_11_1
                               : 0ULL));
    __Vtemp_38[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_11)
                                ? vlSelfRef.__PVT__bucketFirstStore_11_1
                                : 0ULL) >> 0x20U));
    __Vtemp_38[2U] = 0U;
    __Vtemp_39[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_39[1U] = 0U;
    __Vtemp_39[2U] = 0U;
    VL_ADD_W(3, __Vtemp_40, __Vtemp_38, __Vtemp_39);
    vlSelfRef.__PVT__currentFirstStoreNextWide_45[0U] 
        = __Vtemp_40[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_45[1U] 
        = __Vtemp_40[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_45[2U] 
        = (1U & __Vtemp_40[2U]);
    __Vtemp_42[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_11)
                               ? vlSelfRef.__PVT__bucketFirstStore_11_2
                               : 0ULL));
    __Vtemp_42[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_11)
                                ? vlSelfRef.__PVT__bucketFirstStore_11_2
                                : 0ULL) >> 0x20U));
    __Vtemp_42[2U] = 0U;
    __Vtemp_43[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_43[1U] = 0U;
    __Vtemp_43[2U] = 0U;
    VL_ADD_W(3, __Vtemp_44, __Vtemp_42, __Vtemp_43);
    vlSelfRef.__PVT__currentFirstStoreNextWide_46[0U] 
        = __Vtemp_44[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_46[1U] 
        = __Vtemp_44[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_46[2U] 
        = (1U & __Vtemp_44[2U]);
    __Vtemp_46[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_11)
                               ? vlSelfRef.__PVT__bucketFirstStore_11_3
                               : 0ULL));
    __Vtemp_46[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_11)
                                ? vlSelfRef.__PVT__bucketFirstStore_11_3
                                : 0ULL) >> 0x20U));
    __Vtemp_46[2U] = 0U;
    __Vtemp_47[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_47[1U] = 0U;
    __Vtemp_47[2U] = 0U;
    VL_ADD_W(3, __Vtemp_48, __Vtemp_46, __Vtemp_47);
    vlSelfRef.__PVT__currentFirstStoreNextWide_47[0U] 
        = __Vtemp_48[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_47[1U] 
        = __Vtemp_48[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_47[2U] 
        = (1U & __Vtemp_48[2U]);
    __Vtemp_50[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_12)
                               ? vlSelfRef.__PVT__bucketFirstStore_12_0
                               : 0ULL));
    __Vtemp_50[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_12)
                                ? vlSelfRef.__PVT__bucketFirstStore_12_0
                                : 0ULL) >> 0x20U));
    __Vtemp_50[2U] = 0U;
    __Vtemp_51[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    VL_ADD_W(3, __Vtemp_52, __Vtemp_50, __Vtemp_51);
    vlSelfRef.__PVT__currentFirstStoreNextWide_48[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_48[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_48[2U] 
        = (1U & __Vtemp_52[2U]);
    __Vtemp_54[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_12)
                               ? vlSelfRef.__PVT__bucketFirstStore_12_1
                               : 0ULL));
    __Vtemp_54[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_12)
                                ? vlSelfRef.__PVT__bucketFirstStore_12_1
                                : 0ULL) >> 0x20U));
    __Vtemp_54[2U] = 0U;
    __Vtemp_55[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_55[1U] = 0U;
    __Vtemp_55[2U] = 0U;
    VL_ADD_W(3, __Vtemp_56, __Vtemp_54, __Vtemp_55);
    vlSelfRef.__PVT__currentFirstStoreNextWide_49[0U] 
        = __Vtemp_56[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_49[1U] 
        = __Vtemp_56[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_49[2U] 
        = (1U & __Vtemp_56[2U]);
    __Vtemp_58[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_12)
                               ? vlSelfRef.__PVT__bucketFirstStore_12_2
                               : 0ULL));
    __Vtemp_58[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_12)
                                ? vlSelfRef.__PVT__bucketFirstStore_12_2
                                : 0ULL) >> 0x20U));
    __Vtemp_58[2U] = 0U;
    __Vtemp_59[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_59[1U] = 0U;
    __Vtemp_59[2U] = 0U;
    VL_ADD_W(3, __Vtemp_60, __Vtemp_58, __Vtemp_59);
    vlSelfRef.__PVT__currentFirstStoreNextWide_50[0U] 
        = __Vtemp_60[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_50[1U] 
        = __Vtemp_60[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_50[2U] 
        = (1U & __Vtemp_60[2U]);
    __Vtemp_62[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_12)
                               ? vlSelfRef.__PVT__bucketFirstStore_12_3
                               : 0ULL));
    __Vtemp_62[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_12)
                                ? vlSelfRef.__PVT__bucketFirstStore_12_3
                                : 0ULL) >> 0x20U));
    __Vtemp_62[2U] = 0U;
    __Vtemp_63[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_63[1U] = 0U;
    __Vtemp_63[2U] = 0U;
    VL_ADD_W(3, __Vtemp_64, __Vtemp_62, __Vtemp_63);
    vlSelfRef.__PVT__currentFirstStoreNextWide_51[0U] 
        = __Vtemp_64[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_51[1U] 
        = __Vtemp_64[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_51[2U] 
        = (1U & __Vtemp_64[2U]);
    __Vtemp_66[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_13)
                               ? vlSelfRef.__PVT__bucketFirstStore_13_0
                               : 0ULL));
    __Vtemp_66[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_13)
                                ? vlSelfRef.__PVT__bucketFirstStore_13_0
                                : 0ULL) >> 0x20U));
    __Vtemp_66[2U] = 0U;
    __Vtemp_67[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_bytes;
    __Vtemp_67[1U] = 0U;
    __Vtemp_67[2U] = 0U;
    VL_ADD_W(3, __Vtemp_68, __Vtemp_66, __Vtemp_67);
    vlSelfRef.__PVT__currentFirstStoreNextWide_52[0U] 
        = __Vtemp_68[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_52[1U] 
        = __Vtemp_68[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_52[2U] 
        = (1U & __Vtemp_68[2U]);
    __Vtemp_70[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_13)
                               ? vlSelfRef.__PVT__bucketFirstStore_13_1
                               : 0ULL));
    __Vtemp_70[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_13)
                                ? vlSelfRef.__PVT__bucketFirstStore_13_1
                                : 0ULL) >> 0x20U));
    __Vtemp_70[2U] = 0U;
    __Vtemp_71[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words4;
    __Vtemp_71[1U] = 0U;
    __Vtemp_71[2U] = 0U;
    VL_ADD_W(3, __Vtemp_72, __Vtemp_70, __Vtemp_71);
    vlSelfRef.__PVT__currentFirstStoreNextWide_53[0U] 
        = __Vtemp_72[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_53[1U] 
        = __Vtemp_72[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_53[2U] 
        = (1U & __Vtemp_72[2U]);
    __Vtemp_74[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_13)
                               ? vlSelfRef.__PVT__bucketFirstStore_13_2
                               : 0ULL));
    __Vtemp_74[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_13)
                                ? vlSelfRef.__PVT__bucketFirstStore_13_2
                                : 0ULL) >> 0x20U));
    __Vtemp_74[2U] = 0U;
    __Vtemp_75[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_words8;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    VL_ADD_W(3, __Vtemp_76, __Vtemp_74, __Vtemp_75);
    vlSelfRef.__PVT__currentFirstStoreNextWide_54[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_54[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_54[2U] 
        = (1U & __Vtemp_76[2U]);
    __Vtemp_78[0U] = (IData)(((IData)(vlSelfRef.__PVT__bucketValid_13)
                               ? vlSelfRef.__PVT__bucketFirstStore_13_3
                               : 0ULL));
    __Vtemp_78[1U] = (IData)((((IData)(vlSelfRef.__PVT__bucketValid_13)
                                ? vlSelfRef.__PVT__bucketFirstStore_13_3
                                : 0ULL) >> 0x20U));
    __Vtemp_78[2U] = 0U;
    __Vtemp_79[0U] = vlSymsp->TOP.tb__DOT__io_newFirstStore_lines;
    __Vtemp_79[1U] = 0U;
    __Vtemp_79[2U] = 0U;
    VL_ADD_W(3, __Vtemp_80, __Vtemp_78, __Vtemp_79);
    vlSelfRef.__PVT__currentFirstStoreNextWide_55[0U] 
        = __Vtemp_80[0U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_55[1U] 
        = __Vtemp_80[1U];
    vlSelfRef.__PVT__currentFirstStoreNextWide_55[2U] 
        = (1U & __Vtemp_80[2U]);
}
